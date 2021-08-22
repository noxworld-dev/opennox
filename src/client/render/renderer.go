package render

import (
	"image"
	"sync"
	"sync/atomic"

	"nox/v1/client/seat"
	"nox/v1/common/log"
	"nox/v1/common/types"
)

var (
	Log = log.New("render")
)

type Mode struct {
	Width  int
	Height int
	Depth  int
}

func (m Mode) Size() types.Size {
	return types.Size{
		W: m.Width,
		H: m.Height,
	}
}

func New(sc seat.Screen) (*Renderer, error) {
	sz := sc.ScreenSize()
	r := &Renderer{
		updates:    make(chan update, 1),
		sc:         sc,
		fullscreen: -4, // unset
	}
	if err := r.Init(sz); err != nil {
		return nil, err
	}
	sc.OnScreenResize(func(sz types.Size) {
		r.present(types.Size{}, nil)
	})
	return r, nil
}

type Renderer struct {
	ticks      uint32 // atomic
	updates    chan update
	sc         seat.Screen
	backbuf    seat.Surface
	view       image.Rectangle
	fullscreen int
	borderless bool // only used for toggle
	stretch    bool
	rotate     bool
	rotated    bool
	onResize   []func(view image.Rectangle)

	bufMu sync.Mutex
	buf   []byte
}

// Ticks returns the number of present ticks since the last Reset or Init.
func (r *Renderer) Ticks() uint {
	return uint(atomic.LoadUint32(&r.ticks))
}

// Init the renderer.
func (r *Renderer) Init(sz types.Size) error {
	if r.backbuf != nil {
		return nil
	}
	Log.Printf("creating surface: %dx%d", sz.W, sz.H)
	r.backbuf = r.sc.NewSurface(sz)
	return nil
}

// Reset the renderer.
func (r *Renderer) Reset(sz types.Size) error {
	return nil
}

// OnViewResize registers a function that will be called when the render or the underlying window resizes.
func (r *Renderer) OnViewResize(fnc func(view image.Rectangle)) {
	r.onResize = append(r.onResize, fnc)
	fnc(r.view)
}

// CopyBuffer copies given 16 bit image into the buffer and presents it.
func (r *Renderer) CopyBuffer(sz types.Size, src []byte) {
	r.present(sz, src)
}

func (r *Renderer) present(sz types.Size, src []byte) {
	view := r.setViewport(float32(sz.W) / float32(sz.H))
	if r.view != view {
		r.view = view
		for _, fnc := range r.onResize {
			fnc(view)
		}
	}
	upd := update{view: view, size: sz}
	if src != nil {
		r.bufMu.Lock()
		defer r.bufMu.Unlock()
		if len(r.buf) != len(src) {
			r.buf = make([]byte, len(src))
		}
		copy(r.buf, src)
		upd.copy = true
	}
	r.triggerUpdate(upd)
}

type update struct {
	view image.Rectangle
	size types.Size
	copy bool
}

func (r *Renderer) triggerUpdate(u update) {
	for {
		select {
		case r.updates <- u:
			return
		case <-r.updates:
			// continue
		}
	}
}

func (r *Renderer) Loop() {
	var (
		prev []byte
		bsz  = r.backbuf.Size()
	)
	for u := range r.updates {
		func() {
			if u.copy {
				if u.size != bsz {
					old := r.backbuf.Size()
					Log.Printf("recreating surface: %dx%d -> %dx%d", old.W, old.H, u.size.W, u.size.H)
					if r.backbuf != nil {
						r.backbuf.Destroy()
						r.backbuf = nil
					}
					r.backbuf = r.sc.NewSurface(u.size)
					bsz = u.size
				}
				r.bufMu.Lock()
				prev, r.buf = r.buf, prev
				r.bufMu.Unlock()
				r.backbuf.Update(prev)
			}
			r.sc.Clear()
			r.backbuf.Draw(u.view)
			r.sc.Present()
			atomic.AddUint32(&r.ticks, 1)
		}()
	}
}

func (r *Renderer) SetStretch(stretch bool) {
	r.stretch = stretch
}

func (r *Renderer) setViewport(ratio float32) image.Rectangle {
	wsz := r.sc.ScreenSize()
	if r.stretch {
		return image.Rect(0, 0, wsz.W, wsz.H)
	}
	var (
		offx     = 0
		offy     = 0
		vpw, vph int
		vpx, vpy int
	)

	vpw, vph = wsz.W, wsz.H

	// Maintain source aspect ratio
	if r.rotate && float32(vph)-ratio*float32(vpw) > float32(vpw)-ratio*float32(vph) {
		r.rotated = true
	} else {
		r.rotated = false
	}
	if r.rotated {
		ratio = 1.0 / ratio
	}

	if ratio*float32(vph) <= float32(vpw) {
		offx = int(float32(vpw)-float32(vph)*ratio) / 2
		vpw = int(float32(vph) * ratio)
	} else {
		offy = int(float32(vph)-float32(vpw)/ratio) / 2
		vph = int(float32(vpw) / ratio)
	}
	vpx = offx
	vpy = offy
	return image.Rect(vpx, vpy, vpx+vpw, vpy+vph)
}

// IsFullScreen checks if the renderer's window is set to fullscreen mode.
func (r *Renderer) IsFullScreen() bool {
	switch r.fullscreen {
	case -1, 1, -2, 2:
		return true
	}
	return false
}

// WindowMode returns the current window/fullscreen mode for the renderer's screen.
func (r *Renderer) WindowMode() int {
	return r.fullscreen
}

// SetWindowMode updates the window/fullscreen mode for the renderer's screen.
func (r *Renderer) SetWindowMode(mode int) {
	// TODO: previously it set the size of the window
	switch mode {
	case -1, 1:
		// Normal fullscreen
		r.sc.SetScreenMode(seat.Fullscreen)
	case -2, 2:
		// Borderless fullscreen
		r.sc.SetScreenMode(seat.Borderless)
	default:
		// Windowed
		r.sc.SetScreenMode(seat.Windowed)
	}
	r.fullscreen = mode
}

// ToggleWindowMode switches window/fullscreen mode for the renderer's screen.
func (r *Renderer) ToggleWindowMode() {
	switch r.fullscreen {
	case -1, 1:
		// Normal fullscreen -> Windowed
		r.borderless = false
		r.SetWindowMode(-3)
	case -2, 2:
		// Borderless fullscreen -> Windowed
		r.borderless = true
		r.SetWindowMode(-3)
	default:
		// Windowed -> last fullscreen
		if r.borderless {
			r.SetWindowMode(-2)
		} else {
			r.SetWindowMode(-1)
		}
	}
}
