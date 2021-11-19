package main

import (
	"errors"
	"flag"
	"fmt"
	"image"
	"io"
	"log"
	"math"
	"net/http"
	_ "net/http/pprof"
	"os"
	"time"

	"nox/v1/client/audio/ail"
	"nox/v1/client/render"
	"nox/v1/client/seat"
	"nox/v1/client/seat/sdl"
	"nox/v1/common/alloc/handles"
	noxcolor "nox/v1/common/color"
	"nox/v1/common/noximage"
	"nox/v1/common/types"
)

func init() {
	go http.ListenAndServe(":6060", nil)
}

var (
	fMovie = flag.String("i", "intro.vqa", "movie file to open")
)

func main() {
	flag.Parse()
	if err := run(*fMovie); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func run(fname string) error {
	// Handles needed for communication with C (currently used by audio backend).
	// TODO: move them to engine instead
	handles.Init()
	defer handles.Release()

	// Initialize SDL window.
	sz := types.Size{
		W: 640,
		H: 480,
	}
	win, err := sdl.New("Nox Movie Player", sz)
	if err != nil {
		return err
	}
	defer win.Close()

	// Initialize audio.
	ail.Startup()
	defer ail.Shutdown()

	drv := ail.WaveOutOpen()
	if e := ail.LastError(); e != "" {
		return errors.New(e)
	}

	// Our new movie player.
	pl, err := NewPlayer(win, drv, fname)
	if err != nil {
		return err
	}
	defer pl.Close()

	const fps = 30
	dt := time.Second / fps
	log.Printf("dt = %v", dt)
	ticker := time.NewTicker(dt)
	defer ticker.Stop()
	stop := make(chan struct{})

	// Set callbacks for the input events.
	win.OnInput(func(ev seat.InputEvent) {
		switch ev := ev.(type) {
		case seat.WindowEvent:
			switch ev {
			case seat.WindowClosed:
				// If user tries to close the window, stop the loop.
				close(stop)
			}
		case *seat.KeyboardEvent, *seat.MouseButtonEvent:
			// Stop the loop on keyboard or mouse key press as well.
			close(stop)
		}
	})
	// Main loop.
loop:
	for {
		select {
		case <-stop:
			break loop
		case <-ticker.C:
		}
		// Process input events.
		win.InputTick()
		// Run until movie player tells us to stop.
		if !pl.Tick() {
			break
		}
		// Run audio callbacks.
		ail.Serve()
	}
	// Return player decoding errors, if any.
	return pl.Close()
}

func NewPlayer(sc seat.Screen, drv ail.Driver, fname string) (*Player, error) {
	// Initialize renderer, it is responsible for preserving aspect ratio, creating SDL surfaces, etc.
	rend, err := render.New(sc)
	if err != nil {
		return nil, err
	}
	// TODO: actually open file and prepare for decoding
	log.Printf("opening file: %q", fname)
	sz := sc.ScreenSize()
	frame := noximage.NewImage16(image.Rect(0, 0, sz.W, sz.H))
	return &Player{
		sz:   sz,
		rend: rend, audio: drv,
		frame: frame,
		black: make([]uint16, len(frame.Pix)), // for quick copy
	}, nil
}

// Player implements Nox movie player.
type Player struct {
	sz    types.Size
	rend  *render.Renderer
	audio ail.Driver
	black []uint16
	frame *noximage.Image16
	cur   int
	file  io.Reader
}

func (p *Player) Close() error {
	if p.audio != 0 {
		p.audio.Close()
		p.audio = 0
	}
	// TODO: cleanup; make sure it can be called safely multiple times (see defer)
	return nil
}

func (p *Player) Tick() bool {
	p.cur++
	copy(p.frame.Pix, p.black)
	// TODO: decode the frame
	for x := 0; x < p.sz.W; x++ {
		y := int(float64(p.sz.H) * (0.5 + 0.5*math.Sin(float64(x+p.cur%p.sz.W)/float64(p.sz.W)*math.Pi*4)))
		if y < 0 || y >= p.sz.H {
			continue
		}
		cl := noxcolor.ToRGBA5551(byte(p.cur%255), 0, 255-byte(p.cur%100), 255)
		p.frame.SetRGBA5551(x, y, cl)
	}
	p.rend.CopyBuffer(p.frame)
	// TODO: no idea how audio works, but package closely follows C
	return true // TODO: return false once video ends
}
