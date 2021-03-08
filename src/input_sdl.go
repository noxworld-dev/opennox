//+build !server

package main

import (
	"fmt"
	"image"
	"unicode/utf16"

	"nox/client/input"
	"nox/common/types"

	"github.com/veandco/go-sdl2/sdl"
)

var inpHandler *input.Handler

var _ input.Interface = noxInput{}

func inputInit() (func(), error) {
	inp, err := input.NewHandler(noxInput{})
	if err != nil {
		return nil, fmt.Errorf("input initialization failed: %w", err)
	}
	inpHandler = inp
	return func() {
		inp.Close()
	}, nil
}

type noxInput struct{}

func (noxInput) MouseButtonAt(p image.Point, button input.MouseButton, pressed bool) {
	var typ noxMouseEventType
	switch button {
	case input.MouseButtonLeft:
		typ = noxMouseEventLeft
	case input.MouseButtonRight:
		typ = noxMouseEventRight
	case input.MouseButtonMiddle:
		typ = noxMouseEventMiddle
	default:
		panic(button)
	}
	pushMouseEvent(noxMouseEvent{
		Type:    typ,
		X:       p.X,
		Y:       p.Y,
		Pressed: pressed,
	})
}

func (noxInput) MouseMotion(p image.Point) {
	pushMouseEvent(noxMouseEvent{
		Type:  noxMouseEventMotion,
		X:     p.X,
		Y:     p.Y,
		Wheel: 0,
	})
}

func (noxInput) MouseWheel(p image.Point, dv int) {
	pushMouseEvent(noxMouseEvent{
		Type:  noxMouseEventWheel,
		X:     p.X,
		Y:     p.Y,
		Wheel: dv,
	})
}

func (noxInput) InputKeyboard(code input.Scancode, pressed bool) {
	pushKeyEvent(noxKeyEvent{
		Code:    scanCodeToKeyNum[code],
		Pressed: pressed,
	})
}

func (noxInput) WindowDefault() types.Size {
	return types.Size{W: noxDefaultWidth, H: noxDefaultHeight}
}

func (noxInput) WindowEvent(ev input.WindowEvent) {
	switch ev {
	case input.WindowUnfocus:
		unacquireMouse_sub_47D8B0()
	case input.WindowFocus:
		if isMouseInside(noxWindow) {
			acquireMouse_sub_47D8C0()
		}
	case input.WindowAcquireMouse:
		noxWindow.SetGrab(true)
	case input.WindowUnacquireMouse:
		noxWindow.SetGrab(false)
	}
}

func (noxInput) TextEdit(text string) {
	setIMEBuffer(text)
}

func (noxInput) TextInput(text string) {
	setIMEBuffer("")
	for _, c := range utf16.Encode([]rune(text)) {
		noxInputOnChar(c)
	}
}

func isMouseInside(win *sdl.Window) bool {
	mouse := inpHandler.GlobalMousePos()
	wndPosX, wndPosY := win.GetPosition()
	wndSizeW, wndSizeH := win.GetSize()
	return mouse.X >= int(wndPosX) &&
		mouse.X <= int(wndPosX+wndSizeW) &&
		mouse.Y >= int(wndPosY) &&
		mouse.Y <= int(wndPosY+wndSizeH)
}
