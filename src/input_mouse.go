package main

import (
	"image"

	"nox/v1/common/memmap"
	"nox/v1/common/types"
)

const (
	mouseEventBufChan = 256
	mouseEventBuf     = 256
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

func nox_mouse_state(btn, st int) uint {
	return uint(4*(btn+1) + st)
}

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

func NewMouseHandler() *MouseHandler {
	h := &MouseHandler{
		queue: make(chan noxMouseEvent, mouseEventBufChan),
	}
	return h
}

type MouseHandler struct {
	bounds image.Rectangle

	cur     noxMouseStateInt
	prev    noxMouseStateInt
	prevSeq uint
	prevBtn [3]types.Point

	buffer  [mouseEventBuf]noxMouseStateInt
	reading bool

	queue chan noxMouseEvent
}

func inputInitMouse() {
	inpHandler.AcquireMouse()

	// indicates that mouse is present so cursor should be drawn
	*memmap.PtrUint32(0x5D4594, 1193108) = 1

	noxInp.m.updateScreen(videoGetWindowSize())
}

func (h *MouseHandler) updateScreen(sz types.Size) {
	h.setMouseBounds(image.Rect(0, 0, sz.W-1, sz.H-1))
}

func (h *MouseHandler) pushEvent(e noxMouseEvent) bool {
	e.Seq = nextInputSeq()
	select {
	case h.queue <- e:
		return true
	default:
		inputLog.Println("cannot keep up, mouse event dropped")
		return false
	}
}

func (h *MouseHandler) setMouseBounds(r image.Rectangle) {
	inputLog.Printf("mouse bounds: %v", r)
	h.bounds = r
}

func (h *MouseHandler) getMousePos() image.Point {
	return h.cur.pos
}

func (h *MouseHandler) getMouseRel() image.Point {
	return h.cur.dpos
}

func (h *MouseHandler) setMousePos(p image.Point) {
	h.cur.pos = p
}

func (h *MouseHandler) changeMousePos(p image.Point, isAbs bool) {
	if !isAbs {
		p = p.Add(h.getMousePos())
	}
	if p.X > h.bounds.Max.X {
		p.X = h.bounds.Max.X
	}
	if p.X < h.bounds.Min.X {
		p.X = h.bounds.Min.X
	}

	if p.Y > h.bounds.Max.Y {
		p.Y = h.bounds.Max.Y
	}
	if p.Y < h.bounds.Min.Y {
		p.Y = h.bounds.Min.Y
	}
	h.setMousePos(p)
}

func (h *MouseHandler) nox_client_mouseBtnStateFinal(pos types.Point, ind uint) {
	cur := &h.cur.btn[ind]
	btn := 4 * (ind + 1)

	if cur.state == btn+NOX_MOUSE_DOWN {
		h.prevBtn[ind] = pos
	}
}

func (h *MouseHandler) noxResetMouseBuffer() {
	h.buffer[0].btn[0].seq = 1
	h.buffer[0].btn[0].pressed = false
	h.buffer[0].btn[1].seq = 1
	h.buffer[0].btn[1].pressed = false
	h.buffer[0].btn[2].seq = 1
	h.buffer[0].btn[2].pressed = false
	h.nox_client_processMouseEvents_4302A0(1, true)
}

func (h *MouseHandler) nox_client_mouseBtnStateReset(ind uint) {
	cur := &h.cur.btn[ind]
	prev := &h.prev.btn[ind]
	btn := 4 * (ind + 1)
	if cur.pressed && (prev.state == btn+NOX_MOUSE_DOWN || prev.state == btn+NOX_MOUSE_PRESSED) {
		cur.state = btn + NOX_MOUSE_PRESSED
	}
}

func (h *MouseHandler) nox_client_mouseBtnState_430230() {
	h.nox_client_mouseBtnStateReset(NOX_MOUSE_LEFT)
	h.nox_client_mouseBtnStateReset(NOX_MOUSE_RIGHT)
	h.nox_client_mouseBtnStateReset(NOX_MOUSE_MIDDLE)
}

func (h *MouseHandler) nox_client_readMouseBuffer_4306A0(a1 bool) {
	if h.reading {
		return
	}
	h.reading = true
	n := 0
	for i := range h.buffer {
		e := &h.buffer[i]
		if !h.nox_client_nextMouseEvent_47DB20(e) {
			break
		}
		n++
	}
	h.nox_client_processMouseEvents_4302A0(n, a1)
	h.reading = false
	if n > 0 {
		*memmap.PtrUint32(0x5D4594, 805816) = uint32(nox_input_prev_seq)
	}
}

func (h *MouseHandler) nextMouseEvent() *noxMouseEvent {
	select {
	case e, ok := <-h.queue:
		if !ok {
			return nil
		}
		return &e
	default:
		return nil
	}
}

func (h *MouseHandler) nox_client_nextMouseEvent_47DB20(e *noxMouseStateInt) bool {
	*e = noxMouseStateInt{}
	me := h.nextMouseEvent()
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

func (h *MouseHandler) nox_client_mouseBtnStateApply(evt *noxMouseStateInt, pos types.Point, ind uint) {
	ev := &evt.btn[ind]
	cur := &h.cur.btn[ind]
	prevPos := h.prevBtn[ind]
	btn := 4 * (ind + 1)

	if ev.seq == 0 {
		h.nox_client_mouseBtnStateReset(ind)
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

func (h *MouseHandler) nox_client_processMouseEvents_4302A0(evNum int, a2 bool) {
	if h.prevSeq != nox_input_prev_seq {
		h.cur.btn[NOX_MOUSE_LEFT].state = 0
		h.cur.btn[NOX_MOUSE_RIGHT].state = 0
		h.cur.btn[NOX_MOUSE_MIDDLE].state = 0
		h.cur.wheel = 0
		h.prevSeq = nox_input_prev_seq
	}
	num := 0
	if !get_obj_5D4594_754104_switch() {
		num = evNum
		if num == 0 {
			h.nox_client_mouseBtnState_430230()
		}
	}
	pos := h.cur.pos
	for i := 0; i < num; i++ {
		ev := &h.buffer[i]
		// apply absolute mouse pos
		h.changeMousePos(ev.pos, true)
		h.cur.wheel += ev.wheel

		// variable needs to be updated as well
		pos = h.cur.pos

		// apply button states
		h.nox_client_mouseBtnStateApply(ev, pos, NOX_MOUSE_LEFT)
		h.nox_client_mouseBtnStateApply(ev, pos, NOX_MOUSE_RIGHT)
		h.nox_client_mouseBtnStateApply(ev, pos, NOX_MOUSE_MIDDLE)
	}
	// update button prev pos, if necessary
	h.nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_LEFT)
	h.nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_RIGHT)
	h.nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_MIDDLE)

	h.cur.dpos.X = pos.X - h.prev.pos.X
	h.cur.dpos.Y = pos.Y - h.prev.pos.Y
	if h.cur.dpos.X*h.cur.dpos.X+h.cur.dpos.Y*h.cur.dpos.Y >= 4 {
		*memmap.PtrUint32(0x5D4594, 805824) = 0
		*memmap.PtrUint32(0x5D4594, 805804) = 0
	} else {
		*memmap.PtrUint32(0x5D4594, 805824)++
		if *memmap.PtrUint32(0x5D4594, 805824) >= 10 {
			*memmap.PtrUint32(0x5D4594, 805804) = 1
		}
	}
	if a2 { // TODO: this is weird
		if h.cur.wheel <= 0 {
			if h.cur.wheel >= 0 {
				h.cur.wheel = 0
			} else {
				h.cur.wheel = 20
			}
		} else {
			h.cur.wheel = 19
		}
		h.prev = h.cur
	}
}
