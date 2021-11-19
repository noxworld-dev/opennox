package seat

import (
	"image"

	"nox/v1/client/input/keybind"
	"nox/v1/common/types"
)

type Input interface {
	// InputTick runs input event processing, triggering all relevant callback functions.
	InputTick()
	// OnInput adds a handler function that will be called on each input event.
	OnInput(fnc func(ev InputEvent))
	// SetTextInput enables or disables text input mode.
	SetTextInput(enable bool)
}

type InputEvent interface {
	isInputEvent()
}

type MouseButton int

const (
	MouseButtonLeft = MouseButton(iota)
	MouseButtonRight
	MouseButtonMiddle
)

var _ InputEvent = &MouseMoveEvent{}

type MouseMoveEvent struct {
	Relative bool
	Pos      image.Point
	Rel      types.Pointf
}

func (e *MouseMoveEvent) isInputEvent() {}

var _ InputEvent = &MouseButtonEvent{}

type MouseButtonEvent struct {
	Button  MouseButton
	Pressed bool
}

func (e *MouseButtonEvent) isInputEvent() {}

var _ InputEvent = &MouseWheelEvent{}

type MouseWheelEvent struct {
	Wheel int
}

func (e *MouseWheelEvent) isInputEvent() {}

const (
	WindowClosed = WindowEvent(iota)
	WindowFocused
	WindowUnfocused
)

var _ InputEvent = WindowEvent(0)

type WindowEvent int

func (e WindowEvent) isInputEvent() {}

var _ InputEvent = &TextEditEvent{}

type TextEditEvent struct {
	Text string
}

func (e *TextEditEvent) isInputEvent() {}

var _ InputEvent = &TextInputEvent{}

type TextInputEvent struct {
	Text string
}

func (e *TextInputEvent) isInputEvent() {}

var _ InputEvent = &KeyboardEvent{}

type KeyboardEvent struct {
	Key     keybind.Key
	Pressed bool
}

func (e *KeyboardEvent) isInputEvent() {}
