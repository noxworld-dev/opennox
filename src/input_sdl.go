//+build !server

package main

import (
	"fmt"
	"image"
	"unicode/utf16"

	"nox/v1/client/input"
	"nox/v1/common/types"

	"github.com/veandco/go-sdl2/sdl"
)

var (
	inpHandler *input.Handler
	noxInp     *Input
)

var _ input.Interface = &Input{}

func inputInit() (func(), error) {
	noxInp = NewInput()
	inp, err := input.NewHandler(noxInp)
	if err != nil {
		return nil, fmt.Errorf("input initialization failed: %w", err)
	}
	inpHandler = inp
	return func() {
		inp.Close()
	}, nil
}

func NewInput() *Input {
	return &Input{
		m: NewMouseHandler(),
	}
}

type Input struct {
	m *MouseHandler
}

func (inp *Input) GetMousePos() types.Point {
	return inp.m.getMousePos()
}

func (inp *Input) GetMouseRel() types.Point {
	return inp.m.getMouseRel()
}

func (inp *Input) IsMousePressed(btn int) bool {
	return inp.m.cur.btn[btn].pressed
}

func (inp *Input) GetMouseState(btn int) uint {
	return inp.m.cur.btn[btn].state
}

func (inp *Input) SetMouseState(btn int, st uint) {
	inp.m.cur.btn[btn].state = st
}

func (inp *Input) GetMouseWheel() int {
	return inp.m.cur.wheel
}

func (inp *Input) SetMouseWheel(v int) {
	inp.m.cur.wheel = v
}

func (inp *Input) MouseButtonAt(p types.Point, button input.MouseButton, pressed bool) {
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
	inp.m.pushEvent(noxMouseEvent{
		Type:    typ,
		X:       p.X,
		Y:       p.Y,
		Pressed: pressed,
	})
}

func (inp *Input) MouseMotion(p image.Point) {
	inp.m.pushEvent(noxMouseEvent{
		Type:  noxMouseEventMotion,
		X:     p.X,
		Y:     p.Y,
		Wheel: 0,
	})
}

func (inp *Input) MouseWheel(p image.Point, dv int) {
	inp.m.pushEvent(noxMouseEvent{
		Type:  noxMouseEventWheel,
		X:     p.X,
		Y:     p.Y,
		Wheel: dv,
	})
}

func (inp *Input) InputKeyboard(code input.Scancode, pressed bool) {
	pushKeyEvent(noxKeyEvent{
		Code:    scanCodeToKeyNum[code],
		Pressed: pressed,
	})
}

func (inp *Input) WindowDefault() types.Size {
	return types.Size{W: noxDefaultWidth, H: noxDefaultHeight}
}

func (inp *Input) WindowEvent(ev input.WindowEvent) {
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
	case input.WindowToggleFullscreen:
		toggleFullsreen()
	case input.WindowQuit:
		mainloopStop()
	}
}

func (inp *Input) TextEdit(text string) {
	setIMEBuffer(text)
}

func (inp *Input) TextInput(text string) {
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
