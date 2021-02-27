package main

import (
	"log"
	"unicode/utf16"

	"nox/client/input"
	"nox/common/memmap"
	"nox/common/types"

	"github.com/veandco/go-sdl2/sdl"
)

var inpHandler *input.Handler

var _ input.Interface = noxInput{}

type noxInput struct{}

func (noxInput) MouseButtonAt(p types.Point, button input.MouseButton, pressed bool) {
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

func (noxInput) MouseMotion(p types.Point) {
	pushMouseEvent(noxMouseEvent{
		Type:  noxMouseEventMotion,
		X:     p.X,
		Y:     p.Y,
		Wheel: 0,
	})
}

func (noxInput) MouseWheel(p types.Point, dv int) {
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

var (
	inputSeq uint
)

func nextInputSeq() uint {
	v := inputSeq
	inputSeq++
	return v
}

const keyboardEventBuf = 256

var (
	keyboardEventQueue = make(chan noxKeyEvent, keyboardEventBuf)
)

type noxKeyEvent struct {
	Code    byte
	Pressed bool
	Seq     uint
}

func pushKeyEvent(e noxKeyEvent) {
	e.Seq = nextInputSeq()
	select {
	case keyboardEventQueue <- e:
	default:
		log.Println("cannot keep up, keyboard event dropped")
	}
}

func nextKeyEvent() *noxKeyEvent {
	select {
	case e, ok := <-keyboardEventQueue:
		if !ok {
			return nil
		}
		return &e
	default:
		return nil
	}
}

const mouseEventBuf = 256

var (
	mouseEventQueue = make(chan noxMouseEvent, mouseEventBuf)
)

func inputInitMouse() {
	inpHandler.AcquireMouse()

	// indicates that mouse is present so cursor should be drawn
	*memmap.PtrUint32(0x5D4594, 1193108) = 1
}

func pushMouseEvent(e noxMouseEvent) {
	e.Seq = nextInputSeq()
	select {
	case mouseEventQueue <- e:
	default:
		log.Println("cannot keep up, mouse event dropped")
	}
}

func nextMouseEvent() *noxMouseEvent {
	select {
	case e, ok := <-mouseEventQueue:
		if !ok {
			return nil
		}
		return &e
	default:
		return nil
	}
}

type noxMouseEvent struct {
	Type    noxMouseEventType
	X, Y    int
	Wheel   int
	Pressed bool
	Seq     uint
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
