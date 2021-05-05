package main

import (
	"image"
	"log"
	"os"

	"nox/common/memmap"
)

var (
	inputSeq    uint
	mouseBounds = image.Rect(0, 0, noxDefaultWidth, noxDefaultHeight)
	inputLog    = log.New(os.Stderr, "[input]: ", log.LstdFlags|log.Lmsgprefix)
)

func nextInputSeq() uint {
	v := inputSeq
	inputSeq++
	return v
}

func setMouseBounds(r image.Rectangle) {
	inputLog.Printf("mouse bounds: %v", r)
	mouseBounds = r
}

func changeMousePos(p image.Point, isAbs bool) {
	if !isAbs {
		p = p.Add(getMousePos())
	}
	if p.X > mouseBounds.Max.X {
		p.X = mouseBounds.Max.X
	}
	if p.X < mouseBounds.Min.X {
		p.X = mouseBounds.Min.X
	}

	if p.Y > mouseBounds.Max.Y {
		p.Y = mouseBounds.Max.Y
	}
	if p.Y < mouseBounds.Min.Y {
		p.Y = mouseBounds.Min.Y
	}
	setMousePos(p)
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
