package render

import (
	"image"
	"unsafe"

	"nox/v1/client/seat"
	"nox/v1/common/log"
	"nox/v1/common/types"
)

const (
	DefaultWidth  = 640
	DefaultHeight = 480
	DefaultDepth  = 16
	MaxWidth      = 1024
	MaxHeight     = 768
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
	r := &Renderer{
		sc:         sc,
		fullscreen: -4, // unset
	}
	if err := r.Init(sc.ScreenSize()); err != nil {
		return nil, err
	}
	sc.OnScreenResize(func(sz types.Size) {
		r.present(sz)
	})
	return r, nil
}

type Renderer struct {
	sc         seat.Screen
	backbuf    seat.Surface
	view       image.Rectangle
	fullscreen int
	borderless bool // only used for toggle
	rotate     bool
	rotated    bool
	ticks      uint
	onResize   []func(view image.Rectangle)
	onReset    []func(sz types.Size)
}

// Ticks returns the number of present ticks since the last Reset or Init.
func (r *Renderer) Ticks() uint {
	return r.ticks
}

// Init the renderer.
func (r *Renderer) Init(sz types.Size) error {
	if r.backbuf != nil {
		return nil
	}
	r.reset(sz)
	return nil
}

// Reset the renderer.
func (r *Renderer) Reset(sz types.Size) error {
	if r.sc != nil && sz == r.BufferSize() {
		Log.Printf("reusing surface: %dx%d", sz.W, sz.H)
		r.ticks = 0
		return nil
	}
	r.reset(sz)
	return nil
}

// reset the renderer. This function always resets the surface and won't check anything.
func (r *Renderer) reset(sz types.Size) {
	Log.Printf("creating surface: %dx%d", sz.W, sz.H)
	r.Stop()
	r.backbuf = r.newSurface(sz)
	for _, fnc := range r.onReset {
		fnc(sz)
	}
}

// Stop the renderer temporarily.
func (r *Renderer) Stop() {
	if r.backbuf != nil {
		r.backbuf.Destroy()
		r.backbuf = nil
	}
	r.ticks = 0
}

// OnViewResize registers a function that will be called when the render or the underlying window resizes.
func (r *Renderer) OnViewResize(fnc func(view image.Rectangle)) {
	r.onResize = append(r.onResize, fnc)
	fnc(r.view)
}

// OnBufferResize registers a function that will be called when the render buffer resizes.
func (r *Renderer) OnBufferResize(fnc func(sz types.Size)) {
	r.onReset = append(r.onReset, fnc)
	fnc(r.BufferSize())
}

// newSurface creates a new surface of a given size.
func (r *Renderer) newSurface(sz types.Size) seat.Surface {
	return r.sc.NewSurface(sz)
}

// BufferSize returns the size of the back buffer.
func (r *Renderer) BufferSize() types.Size {
	return r.backbuf.Size()
}

// BufferData returns C pointer to the back buffer data.
func (r *Renderer) BufferData() unsafe.Pointer {
	b := r.backbuf.Bytes()
	return unsafe.Pointer(&b[0])
}

// BufferPitch returns for the back buffer data.
func (r *Renderer) BufferPitch() int {
	return r.backbuf.Pitch()
}

// CopyBufferRows copies given image rows into the buffer and presents it.
func (r *Renderer) CopyBufferRows(rows [][]byte) {
	if !r.backbuf.Lock() {
		return
	}
	defer func() {
		r.backbuf.Unlock()
		r.present(r.sc.ScreenSize())
	}()
	height := r.backbuf.Size().H

	dpix := r.backbuf.Bytes()
	pitch := r.backbuf.Pitch()
	for y := 0; y < height; y++ {
		row := rows[y]
		drow := dpix[y*pitch : (y+1)*pitch]
		copy(drow, row[:pitch])
	}
}

func (r *Renderer) present(wsz types.Size) {
	bsz := r.BufferSize()
	view := r.setViewport(bsz.W, bsz.H, wsz.W, wsz.H)
	r.backbuf.Present(view)
	if r.view != view {
		r.view = view
		for _, fnc := range r.onResize {
			fnc(view)
		}
	}
	r.ticks++
}

func (r *Renderer) setViewport(srcw, srch, tw, th int) image.Rectangle {
	var (
		ratio    = float32(srcw) / float32(srch)
		offx     = 0
		offy     = 0
		vpw, vph int
		vpx, vpy int
	)

	vpw, vph = tw, th

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

// RenderMode returns the current rendering mode.
func (r *Renderer) RenderMode() Mode {
	sz := r.backbuf.Size()
	return Mode{
		Width:  sz.W,
		Height: sz.H,
		Depth:  DefaultDepth, // only one mode is supported
	}
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
