package main

import (
	"github.com/veandco/go-sdl2/sdl"

	"nox/common/types"
)

type mouseButton int

const (
	mouseButtonLeft = mouseButton(iota)
	mouseButtonRight
	mouseButtonMiddle
)

var (
	inputGrabMouse = false
	mouseAcquired  = false

	// inputMousePos is a last mouse coordinates (in window space)
	inputMousePos types.Point
)

func isMouseInside(win *sdl.Window) bool {
	mouseX, mouseY, _ := sdl.GetGlobalMouseState()
	wndPosX, wndPosY := win.GetPosition()
	wndSizeW, wndSizeH := win.GetSize()
	return mouseX >= wndPosX &&
		mouseX <= wndPosX+wndSizeW &&
		mouseY >= wndPosY &&
		mouseY <= wndPosY+wndSizeH
}

func inputAcquireMouse() {
	if mouseAcquired {
		return
	}
	if inputGrabMouse {
		noxWindow.SetGrab(true)
		sdl.SetRelativeMouseMode(true)
	}
	mouseAcquired = true
}

func inputUnacquireMouse() {
	if inputGrabMouse {
		sdl.SetRelativeMouseMode(false)
		noxWindow.SetGrab(false)
	}
	mouseAcquired = false
}

// inputMouseMove moves mouse by a specific amount in the window space.
func inputMouseMove(dp types.Pointf) {
	inputMousePos.X += int(dp.X)
	inputMousePos.Y += int(dp.Y)
	// TODO: native support for relative events
	inputMouseSet(inputMousePos)
}

// inputMouseButton sets a specified mouse button state.
func inputMouseButton(button mouseButton, pressed bool) {
	inputMouseButtonAt(inputMousePos, button, pressed)
}

func inputMouseDownAt(p types.Point, button mouseButton) {
	inputMouseButtonAt(p, button, true)
}

func inputMouseUpAt(p types.Point, button mouseButton) {
	inputMouseButtonAt(p, button, false)
}

func inputMouseDown(button mouseButton) {
	inputMouseButton(button, true)
}

func inputMouseUp(button mouseButton) {
	inputMouseButton(button, false)
}

func processMouseEvent(ev *sdl.MouseButtonEvent) {
	pressed := ev.State == sdl.PRESSED
	if pressed {
		var wndEvt sdl.WindowEvent
		wndEvt.Type = sdl.WINDOWEVENT_FOCUS_GAINED
		processWindowEvent(&wndEvt)
	}

	var button mouseButton
	switch ev.Button {
	case sdl.BUTTON_LEFT:
		button = mouseButtonLeft
	case sdl.BUTTON_RIGHT:
		button = mouseButtonRight
	case sdl.BUTTON_MIDDLE:
		button = mouseButtonMiddle
	default:
		return
	}
	inputMouseButtonAt(types.Point{
		X: int(ev.X), Y: int(ev.Y),
	}, button, pressed)
}

func processMotionEvent(ev *sdl.MouseMotionEvent) {
	inputMouseSet(types.Point{X: int(ev.X), Y: int(ev.Y)})
}

func processWheelEvent(ev *sdl.MouseWheelEvent) {
	inputMouseWheel(int(ev.Y))
}
