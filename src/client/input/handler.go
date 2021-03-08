//+build !server

package input

import (
	"fmt"

	"github.com/veandco/go-sdl2/sdl"
)

type Handler struct {
	iface Interface
	gpad  *Gamepad
	win   window
	mouse mouse
	sens  float32
}

func NewHandler(iface Interface) (*Handler, error) {
	h := &Handler{
		iface: iface,
		sens:  1.0,
	}
	h.initWindow()
	return h, nil
}

func (h *Handler) Close() error {
	h.cleanupControllers()
	h.iface = nil
	return nil
}

func (h *Handler) GetSensitivity() float32 {
	return h.sens
}

func (h *Handler) SetSensitivity(v float32) {
	h.sens = v
}

func (h *Handler) tick() {
	h.controllerTick()
}

func (h *Handler) Tick() {
	h.tick()
	for {
		switch ev := sdl.PollEvent().(type) {
		case nil:
			// no more events
			return
		case *sdl.TextEditingEvent:
			h.processTextEditingEvent(ev)
		case *sdl.TextInputEvent:
			h.processTextInputEvent(ev)
		case *sdl.KeyboardEvent:
			h.processKeyboardEvent(ev)
		case *sdl.MouseButtonEvent:
			h.processMouseEvent(ev)
		case *sdl.MouseMotionEvent:
			h.processMotionEvent(ev)
		case *sdl.MouseWheelEvent:
			h.processWheelEvent(ev)
		case *sdl.ControllerAxisEvent:
			fmt.Printf("SDL event: SDL_CONTROLLERAXISMOTION (%x): joy=%d, axis=%d, val=%d\n",
				ev.GetType(), ev.Which, ev.Axis, ev.Value)
			h.processGamepadAxisEvent(ev)
		case *sdl.ControllerButtonEvent:
			fmt.Printf("SDL event: SDL_CONTROLLERBUTTON (%x): joy=%d, btn=%d, state=%d\n",
				ev.GetType(), ev.Which, ev.Button, ev.State)
			h.processGamepadButtonEvent(ev)
		case *sdl.ControllerDeviceEvent:
			switch ev.GetType() {
			case sdl.CONTROLLERDEVICEADDED:
				fmt.Printf("SDL event: SDL_CONTROLLERDEVICEADDED (%x): joy=%d\n", ev.GetType(), ev.Which)
				h.processGamepadDeviceEvent(ev)
			case sdl.CONTROLLERDEVICEREMOVED:
				fmt.Printf("SDL event: SDL_CONTROLLERDEVICEREMOVED (%x): joy=%d\n", ev.GetType(), ev.Which)
				h.processGamepadDeviceEvent(ev)
			case sdl.CONTROLLERDEVICEREMAPPED:
				fmt.Printf("SDL event: SDL_CONTROLLERDEVICEREMAPPED (%x)\n", ev.GetType())
			}
		case *sdl.WindowEvent:
			h.processWindowEvent(ev)
		}
		// TODO: touch events for WASM
	}
}

func (h *Handler) WaitClick() bool {
	h.tick()
	res := false
	for {
		switch sdl.PollEvent().(type) {
		case nil:
			// no more events
			return res
		case *sdl.KeyboardEvent,
			*sdl.MouseButtonEvent,
			*sdl.ControllerButtonEvent:
			res = true
		}
	}
}
