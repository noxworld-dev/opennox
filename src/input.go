package main

import (
	"log"

	"nox/common/memmap"
)

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
