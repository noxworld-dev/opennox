package input

import (
	"image"

	"nox/common/types"
)

type Scancode uint32

type Keymod uint

type WindowEvent int

const (
	WindowFocus = WindowEvent(iota + 1)
	WindowUnfocus
	WindowAcquireMouse
	WindowUnacquireMouse
)

type MouseButton int

const (
	MouseButtonLeft = MouseButton(iota)
	MouseButtonRight
	MouseButtonMiddle
)

type Interface interface {
	MouseButtonAt(p image.Point, button MouseButton, pressed bool)
	MouseMotion(p image.Point)
	MouseWheel(p image.Point, dv int)
	InputKeyboard(code Scancode, pressed bool)
	TextEdit(text string)
	TextInput(text string)
	WindowDefault() types.Size
	WindowEvent(ev WindowEvent)
}
