package main

import (
	"log"

	"github.com/veandco/go-sdl2/sdl"
)

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

func inputKeyboard(code sdl.Scancode, pressed bool) {
	pushKeyEvent(noxKeyEvent{
		Code:    scanCodeToKeyNum[code],
		Pressed: pressed,
	})
}

func processKeyboardEvent(ev *sdl.KeyboardEvent) {
	inputKeyboard(ev.Keysym.Scancode, ev.State == sdl.PRESSED)
}
