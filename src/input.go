package main

import (
	"fmt"
	"math"

	"github.com/veandco/go-sdl2/sdl"

	"nox/common/types"
)

const (
	gpadStickMax        = math.MaxInt16
	gpadTrigMax         = math.MaxInt16
	gpadMouseSpeed      = 50.0
	gpadDeadZone        = 1500
	gpadStickRelAutoRun = 0.3
)

var (
	inputSeq uint
	// size of the actual window
	inputWindow = types.Size{W: noxDefaultWidth, H: noxDefaultHeight}
	// size of the image that Nox draws
	inputDrawWindow = types.Size{W: noxDefaultWidth, H: noxDefaultHeight}
	// scale factors calculated from sizes above
	inputScale = types.Sizef{W: 1, H: 1}
)

func nextInputSeq() uint {
	v := inputSeq
	inputSeq++
	return v
}

func inputUpdateScale() {
	inputScale.W = float32(inputDrawWindow.W) / float32(inputWindow.W)
	inputScale.H = float32(inputDrawWindow.H) / float32(inputWindow.H)
}

func inputSetWinSize(sz types.Size) {
	if sz.W == 0 || sz.H == 0 {
		return
	}
	inputWindow = sz
	inputUpdateScale()
}

func inputSetDrawWinSize(sz types.Size) {
	if sz.W == 0 || sz.H == 0 {
		return
	}
	inputDrawWindow = sz
	inputUpdateScale()
}

// inputToDrawSpace remaps window position to position on the video buffer
func inputToDrawSpace(p types.Point) types.Point {
	p.X = int(float32(p.X) * inputScale.W)
	p.Y = int(float32(p.Y) * inputScale.H)
	return p
}

// inputClamp clamps window coords according to the current screen size.
func inputClamp(p types.Point) types.Point {
	if p.X < 0 {
		p.X = 0
	}
	if p.Y < 0 {
		p.Y = 0
	}
	if inputWindow.W > 0 && p.X > inputWindow.W {
		p.X = inputWindow.W
	}
	if inputWindow.H > 0 && p.Y > inputWindow.H {
		p.Y = inputWindow.H
	}
	return p
}

// inputClampf clamps window coords according to the current screen size.
func inputClampf(p types.Pointf) types.Pointf {
	if p.X < 0 {
		p.X = 0
	}
	if p.Y < 0 {
		p.Y = 0
	}
	if inputWindow.W > 0 && p.X > float32(inputWindow.W) {
		p.X = float32(inputWindow.W)
	}
	if inputWindow.H > 0 && p.Y > float32(inputWindow.H) {
		p.Y = float32(inputWindow.H)
	}
	return p
}

func inputPollEvents() {
	inputEventsTick()
	for {
		switch ev := sdl.PollEvent().(type) {
		case nil:
			// no more events
			return
		case *sdl.TextEditingEvent:
			processTextEditingEvent(ev)
		case *sdl.TextInputEvent:
			processTextInputEvent(ev)
		case *sdl.KeyboardEvent:
			if inTextInput {
				processTextInputKeyboardEvent(ev)
			} else {
				processKeyboardEvent(ev)
			}
		case *sdl.MouseButtonEvent:
			processMouseEvent(ev)
		case *sdl.MouseMotionEvent:
			processMotionEvent(ev)
		case *sdl.MouseWheelEvent:
			processWheelEvent(ev)
		case *sdl.ControllerAxisEvent:
			fmt.Printf("SDL event: SDL_CONTROLLERAXISMOTION (%x): joy=%d, axis=%d, val=%d\n",
				ev.GetType(), ev.Which, ev.Axis, ev.Value)
			processGamepadAxisEvent(ev)
		case *sdl.ControllerButtonEvent:
			fmt.Printf("SDL event: SDL_CONTROLLERBUTTON (%x): joy=%d, btn=%d, state=%d\n",
				ev.GetType(), ev.Which, ev.Button, ev.State)
			processGamepadButtonEvent(ev)
		case *sdl.ControllerDeviceEvent:
			switch ev.GetType() {
			case sdl.CONTROLLERDEVICEADDED:
				fmt.Printf("SDL event: SDL_CONTROLLERDEVICEADDED (%x): joy=%d\n", ev.GetType(), ev.Which)
				processGamepadDeviceEvent(ev)
			case sdl.CONTROLLERDEVICEREMOVED:
				fmt.Printf("SDL event: SDL_CONTROLLERDEVICEREMOVED (%x): joy=%d\n", ev.GetType(), ev.Which)
				processGamepadDeviceEvent(ev)
			case sdl.CONTROLLERDEVICEREMAPPED:
				fmt.Printf("SDL event: SDL_CONTROLLERDEVICEREMAPPED (%x)\n", ev.GetType())
			}
		case *sdl.WindowEvent:
			processWindowEvent(ev)
		}
		// TODO: touch events for WASM
	}
}

func processWindowEvent(ev *sdl.WindowEvent) {
	switch ev.GetType() {
	case sdl.WINDOWEVENT_FOCUS_LOST:
		unacquireMouse_sub_47D8B0()
	case sdl.WINDOWEVENT_FOCUS_GAINED:
		if isMouseInside(noxWindow) {
			acquireMouse_sub_47D8C0()
		}
	}
}

func inputEventsTick() {
	inputControllerTick()
}

func abs(v int) int {
	if v < 0 {
		return -v
	}
	return v
}
