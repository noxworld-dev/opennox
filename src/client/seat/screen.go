package seat

import (
	"image"

	"nox/v1/common/types"
)

const (
	DefaultWidth  = 640
	DefaultHeight = 480
	DefaultDepth  = 16
)

const (
	Windowed = ScreenMode(iota + 1)
	Fullscreen
	Borderless
)

type ScreenMode int

type Screen interface {
	// ScreenSize returns current size of the screen.
	ScreenSize() types.Size
	// ScreenMaxSize returns max size of the screen.
	ScreenMaxSize() types.Size
	// ResizeScreen changes the size of the screen.
	ResizeScreen(sz types.Size)
	// SetScreenMode changes the screen mode. Fullscreen will maximize the screen to max, while Windowed will return
	// is back to the previous state.
	SetScreenMode(mode ScreenMode)
	// SetGamma sets screen gamma parameter.
	SetGamma(v float32)
	// OnScreenResize adds a handler function that will be called on screen resize.
	OnScreenResize(fnc func(sz types.Size))
	// NewSurface creates a new screen surface.
	NewSurface(sz types.Size) Surface
}

type Surface interface {
	// Size of the surface.
	Size() types.Size
	// Lock the surface.
	Lock() bool
	// Unlock the surface.
	Unlock()
	// Present the surface in a given viewport rectangle.
	Present(vp image.Rectangle)
	// Bytes exposes underlying data of the surface.
	Bytes() []byte
	// Pitch returns the index shift for each surface row (in bytes).
	Pitch() int
	// Destroy the surface.
	Destroy()
}
