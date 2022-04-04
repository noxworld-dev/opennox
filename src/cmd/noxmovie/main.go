package main

import (
	"errors"
	"flag"
	"fmt"
	"os"

	"nox/v1/client/audio/ail"
	"nox/v1/client/noxmovie"
	"nox/v1/client/seat/sdl"
	"nox/v1/common/alloc/handles"
	"nox/v1/common/types"
)

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

	drv := ail.WaveOutOpen()
	if e := ail.LastError(); e != "" {
		return errors.New(e)
	}

	plr, err := noxmovie.NewPlayer(fname, win, drv)
	if err != nil {
		return err
	}

	defer plr.Close()

	plr.Start()
	plr.Play()

	plr2, err := noxmovie.NewPlayer(fname, win, drv)
	if err != nil {
		return err
	}

	defer plr2.Close()

	plr2.Start()
	plr2.Play()

	ail.Shutdown()
	return nil
}
