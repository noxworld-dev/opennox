package main

import (
	"image"

	"nox/v1/common/memmap"
	"nox/v1/common/types"
)

const (
	NOX_MOUSE_LEFT   = 0
	NOX_MOUSE_RIGHT  = 1
	NOX_MOUSE_MIDDLE = 2
)

const (
	NOX_MOUSE_DOWN     = 1
	NOX_MOUSE_DRAG_END = 2
	NOX_MOUSE_UP       = 3
	NOX_MOUSE_PRESSED  = 4
)

type noxMouseEventType uint

const (
	noxMouseEventMotion = noxMouseEventType(iota)
	noxMouseEventWheel
	noxMouseEventLeft
	noxMouseEventRight
	noxMouseEventMiddle
)

var (
	nox_mouse              noxMouseStateInt
	nox_mouse_prev         noxMouseStateInt
	nox_mouse_prev_seq_2   uint
	nox_readingMouseBuffer = false
	mouseBounds            = image.Rect(0, 0, noxDefaultWidth, noxDefaultHeight)
	nox_mouse_prev_btn     [3]types.Point
	nox_input_buffer       [256]noxMouseStateInt
)

var noxMouseSelectOpt = []string{
	"Left",
	"Right",
	"Middle",
	"Wheel",
}

type noxMouseBtnInt struct {
	pressed bool
	state   uint
	seq     uint
}

type noxMouseStateInt struct {
	pos   types.Point
	wheel int
	dpos  types.Point
	btn   [3]noxMouseBtnInt
}

type noxMouseEvent struct {
	Type    noxMouseEventType
	X, Y    int
	Wheel   int
	Pressed bool
	Seq     uint
}

const mouseEventBuf = 256

var (
	mouseEventQueue = make(chan noxMouseEvent, mouseEventBuf)
)

func inputInitMouse() {
	inpHandler.AcquireMouse()

	// indicates that mouse is present so cursor should be drawn
	*memmap.PtrUint32(0x5D4594, 1193108) = 1

	sz := videoGetWindowSize()
	setMouseBounds(image.Rect(0, 0, sz.W-1, sz.H-1))
}

func pushMouseEvent(e noxMouseEvent) {
	e.Seq = nextInputSeq()
	select {
	case mouseEventQueue <- e:
	default:
		inputLog.Println("cannot keep up, mouse event dropped")
	}
}

func nox_mouse_state(btn, st int) uint {
	return uint(4*(btn+1) + st)
}

func setMouseBounds(r image.Rectangle) {
	inputLog.Printf("mouse bounds: %v", r)
	mouseBounds = r
}

func getMousePos() image.Point {
	return nox_mouse.pos
}

func setMousePos(p image.Point) {
	nox_mouse.pos = p
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

func nox_client_mouseBtnStateFinal(pos types.Point, ind uint) {
	cur := &nox_mouse.btn[ind]
	btn := 4 * (ind + 1)

	if cur.state == btn+NOX_MOUSE_DOWN {
		nox_mouse_prev_btn[ind] = pos
	}
}

func noxResetMouseBuffer() {
	nox_input_buffer[0].btn[0].seq = 1
	nox_input_buffer[0].btn[0].pressed = false
	nox_input_buffer[0].btn[1].seq = 1
	nox_input_buffer[0].btn[1].pressed = false
	nox_input_buffer[0].btn[2].seq = 1
	nox_input_buffer[0].btn[2].pressed = false
	nox_client_processMouseEvents_4302A0(1, true)
}

func nox_client_mouseBtnStateReset(ind uint) {
	cur := &nox_mouse.btn[ind]
	prev := &nox_mouse_prev.btn[ind]
	btn := 4 * (ind + 1)

	if cur.pressed && (prev.state == btn+NOX_MOUSE_DOWN || prev.state == btn+NOX_MOUSE_PRESSED) {
		cur.state = btn + NOX_MOUSE_PRESSED
	}
}

func nox_client_mouseBtnState_430230() {
	nox_client_mouseBtnStateReset(NOX_MOUSE_LEFT)
	nox_client_mouseBtnStateReset(NOX_MOUSE_RIGHT)
	nox_client_mouseBtnStateReset(NOX_MOUSE_MIDDLE)
}

func nox_client_readMouseBuffer_4306A0(a1 bool) {
	if nox_readingMouseBuffer {
		return
	}
	nox_readingMouseBuffer = true
	n := 0
	for i := range nox_input_buffer {
		e := &nox_input_buffer[i]
		if !nox_client_nextMouseEvent_47DB20(e) {
			break
		}
		n++
	}
	nox_client_processMouseEvents_4302A0(n, a1)
	nox_readingMouseBuffer = false
	if n > 0 {
		*memmap.PtrUint32(0x5D4594, 805816) = uint32(nox_input_prev_seq)
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

func nox_client_nextMouseEvent_47DB20(e *noxMouseStateInt) bool {
	*e = noxMouseStateInt{}
	me := nextMouseEvent()
	if me == nil {
		return false
	}
	e.pos.X = me.X
	e.pos.Y = me.Y
	switch me.Type {
	case noxMouseEventMotion:
		e.wheel = me.Wheel
	case noxMouseEventWheel:
		e.wheel = me.Wheel
		// mix event hanlder is triggered only for wheel events
		call_OnLibraryNotice_265(e)
	case noxMouseEventLeft:
		e.btn[NOX_MOUSE_LEFT].pressed = me.Pressed
		e.btn[NOX_MOUSE_LEFT].seq = me.Seq
	case noxMouseEventRight:
		e.btn[NOX_MOUSE_RIGHT].pressed = me.Pressed
		e.btn[NOX_MOUSE_RIGHT].seq = me.Seq
	case noxMouseEventMiddle:
		e.btn[NOX_MOUSE_MIDDLE].pressed = me.Pressed
		e.btn[NOX_MOUSE_MIDDLE].seq = me.Seq
	}
	return true
}

func nox_client_mouseBtnStateApply(evt *noxMouseStateInt, pos types.Point, ind uint) {
	ev := &evt.btn[ind]
	cur := &nox_mouse.btn[ind]
	prevPos := nox_mouse_prev_btn[ind]
	btn := 4 * (ind + 1)

	if ev.seq == 0 {
		nox_client_mouseBtnStateReset(ind)
		return
	}
	if cur.pressed == ev.pressed {
		return
	}
	dx := pos.X - prevPos.X
	dy := pos.Y - prevPos.Y
	if ev.pressed {
		if cur.state != btn+NOX_MOUSE_UP {
			cur.state = btn + NOX_MOUSE_DOWN
			cur.pressed = true
			cur.seq = nox_input_prev_seq
		}
	} else {
		if int(nox_input_prev_seq)-int(cur.seq) >= 15 || dx*dx+dy*dy >= 100 {
			cur.state = btn + NOX_MOUSE_DRAG_END
		} else {
			cur.state = btn + NOX_MOUSE_UP
		}
		cur.pressed = false
		cur.seq = nox_input_prev_seq
	}
}

func nox_client_processMouseEvents_4302A0(evNum int, a2 bool) {
	if nox_mouse_prev_seq_2 != nox_input_prev_seq {
		nox_mouse.btn[NOX_MOUSE_LEFT].state = 0
		nox_mouse.btn[NOX_MOUSE_RIGHT].state = 0
		nox_mouse.btn[NOX_MOUSE_MIDDLE].state = 0
		nox_mouse.wheel = 0
		nox_mouse_prev_seq_2 = nox_input_prev_seq
	}
	num := 0
	if !get_obj_5D4594_754104_switch() {
		num = evNum
		if num == 0 {
			nox_client_mouseBtnState_430230()
		}
	}
	pos := nox_mouse.pos
	for i := 0; i < num; i++ {
		ev := &nox_input_buffer[i]
		// apply absolute mouse pos
		changeMousePos(ev.pos, true)
		nox_mouse.wheel += ev.wheel

		// variable needs to be updated as well
		pos = nox_mouse.pos

		// apply button states
		nox_client_mouseBtnStateApply(ev, pos, NOX_MOUSE_LEFT)
		nox_client_mouseBtnStateApply(ev, pos, NOX_MOUSE_RIGHT)
		nox_client_mouseBtnStateApply(ev, pos, NOX_MOUSE_MIDDLE)
	}
	// update button prev pos, if necessary
	nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_LEFT)
	nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_RIGHT)
	nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_MIDDLE)

	nox_mouse.dpos.X = pos.X - nox_mouse_prev.pos.X
	nox_mouse.dpos.Y = pos.Y - nox_mouse_prev.pos.Y
	if nox_mouse.dpos.X*nox_mouse.dpos.X+nox_mouse.dpos.Y*nox_mouse.dpos.Y >= 4 {
		*memmap.PtrUint32(0x5D4594, 805824) = 0
		*memmap.PtrUint32(0x5D4594, 805804) = 0
	} else {
		*memmap.PtrUint32(0x5D4594, 805824)++
		if *memmap.PtrUint32(0x5D4594, 805824) >= 10 {
			*memmap.PtrUint32(0x5D4594, 805804) = 1
		}
	}
	if a2 { // TODO: this is weird
		if nox_mouse.wheel <= 0 {
			if nox_mouse.wheel >= 0 {
				nox_mouse.wheel = 0
			} else {
				nox_mouse.wheel = 20
			}
		} else {
			nox_mouse.wheel = 19
		}
		nox_mouse_prev = nox_mouse
	}
}
