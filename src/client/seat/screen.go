package seat

import (
	"image"

	"nox/v1/common/noximage"
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
	ScreenSize() noximage.Size
	// ScreenMaxSize returns max size of the screen.
	ScreenMaxSize() noximage.Size
	// ResizeScreen changes the size of the screen.
	ResizeScreen(sz noximage.Size)
	// SetScreenMode changes the screen mode. Fullscreen will maximize the screen to max, while Windowed will return
	// is back to the previous state.
	SetScreenMode(mode ScreenMode)
	// SetGamma sets screen gamma parameter.
	SetGamma(v float32)
	// OnScreenResize adds a handler function that will be called on screen resize.
	OnScreenResize(fnc func(sz noximage.Size))
	// NewSurface creates a new screen surface.
	NewSurface(sz noximage.Size, filter bool) Surface
	// Clear the screen.
	Clear()
	// Present the current buffer to the screen.
	Present()
}

type Surface interface {
	// Size of the surface.
	Size() noximage.Size
	// Update the surface with 16 bit data.
	Update(data *noximage.Image16)
	// Draw the surface in a given viewport rectangle.
	Draw(vp image.Rectangle)
	// Destroy the surface.
	Destroy()
}
