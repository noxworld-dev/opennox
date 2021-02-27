package input

import (
	"github.com/veandco/go-sdl2/sdl"
	"nox/common/types"
)

type mouse struct {
	pos      types.Point // last mouse coordinates (in window space)
	grab     bool
	acquired bool
}

func (h *Handler) SetMouseGrab(grab bool) {
	h.mouse.grab = grab
}

func (h *Handler) AcquireMouse() {
	if h.mouse.acquired {
		return
	}
	if h.mouse.grab {
		h.iface.WindowEvent(WindowAcquireMouse)
		sdl.SetRelativeMouseMode(true)
	}
	h.mouse.acquired = true
}

func (h *Handler) UnacquireMouse() {
	if h.mouse.grab {
		sdl.SetRelativeMouseMode(false)
		h.iface.WindowEvent(WindowUnacquireMouse)
	}
	h.mouse.acquired = false
}

func (h *Handler) GlobalMousePos() types.Point {
	mouseX, mouseY, _ := sdl.GetGlobalMouseState()
	return types.Point{
		X: int(mouseX),
		Y: int(mouseY),
	}
}

func (h *Handler) IsMouseDown() bool {
	return sdl.GetEventState(sdl.MOUSEBUTTONDOWN) != 0
}

func (h *Handler) processMouseEvent(ev *sdl.MouseButtonEvent) {
	pressed := ev.State == sdl.PRESSED
	if pressed {
		h.iface.WindowEvent(WindowFocus)
	}

	var button MouseButton
	switch ev.Button {
	case sdl.BUTTON_LEFT:
		button = MouseButtonLeft
	case sdl.BUTTON_RIGHT:
		button = MouseButtonRight
	case sdl.BUTTON_MIDDLE:
		button = MouseButtonMiddle
	default:
		return
	}
	h.MouseButtonAt(types.Point{
		X: int(ev.X), Y: int(ev.Y),
	}, button, pressed)
}

// MouseButtonAt sets mouse pos to a given position and sets a specified mouse button state.
func (h *Handler) MouseButtonAt(p types.Point, button MouseButton, pressed bool) {
	h.mouse.pos = p
	p = h.win.toDrawSpace(p)
	h.iface.MouseButtonAt(p, button, pressed)
}

// MouseSet sets mouse to a specific position in the window space.
func (h *Handler) MouseSet(p types.Point) {
	h.mouse.pos = p
	p = h.win.toDrawSpace(p)
	h.iface.MouseMotion(p)
}

// MouseWheel moves mouse wheel by a specific amount.
func (h *Handler) MouseWheel(dv int) {
	p := h.mouse.pos
	p = h.win.toDrawSpace(p)
	h.iface.MouseWheel(p, dv)
}

// MouseMove moves mouse by a specific amount in the window space.
func (h *Handler) MouseMove(dp types.Pointf) {
	h.mouse.pos.X += int(dp.X)
	h.mouse.pos.Y += int(dp.Y)
	// TODO: native support for relative events
	h.MouseSet(h.mouse.pos)
}

// MouseButton sets a specified mouse button state.
func (h *Handler) MouseButton(button MouseButton, pressed bool) {
	h.MouseButtonAt(h.mouse.pos, button, pressed)
}

func (h *Handler) MouseDownAt(p types.Point, button MouseButton) {
	h.MouseButtonAt(p, button, true)
}

func (h *Handler) MouseUpAt(p types.Point, button MouseButton) {
	h.MouseButtonAt(p, button, false)
}

func (h *Handler) MouseDown(button MouseButton) {
	h.MouseButton(button, true)
}

func (h *Handler) MouseUp(button MouseButton) {
	h.MouseButton(button, false)
}

func (h *Handler) processMotionEvent(ev *sdl.MouseMotionEvent) {
	h.MouseSet(types.Point{X: int(ev.X), Y: int(ev.Y)})
}

func (h *Handler) processWheelEvent(ev *sdl.MouseWheelEvent) {
	h.MouseWheel(int(ev.Y))
}
