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
	NewSurface(sz types.Size, filter bool) Surface
	// Clear the screen.
	Clear()
	// Present the current buffer to the screen.
	Present()
}

type Surface interface {
	// Size of the surface.
	Size() types.Size
	// Update the surface with 16 bit data.
	Update(data []uint16)
	// Draw the surface in a given viewport rectangle.
	Draw(vp image.Rectangle)
	// Destroy the surface.
	Destroy()
}
