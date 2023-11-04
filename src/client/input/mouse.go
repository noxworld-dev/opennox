package input

import (
	"fmt"
	"image"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	"github.com/noxworld-dev/opennox-lib/client/seat"
	"github.com/noxworld-dev/opennox-lib/types"
)

const (
	mouseEventBufChan = 256
	mouseEventBuf     = 256
)

type MouseButton int8

func (btn MouseButton) String() string {
	switch btn {
	case -1:
		return "None"
	case NOX_MOUSE_LEFT:
		return "Left"
	case NOX_MOUSE_RIGHT:
		return "Right"
	case NOX_MOUSE_MIDDLE:
		return "Middle"
	default:
		return fmt.Sprintf("MouseButton(%d)", int(btn))
	}
}

const (
	NOX_MOUSE_LEFT   = MouseButton(0)
	NOX_MOUSE_RIGHT  = MouseButton(1)
	NOX_MOUSE_MIDDLE = MouseButton(2)
)

type MouseState int8

func (s MouseState) String() string {
	switch s {
	case NOX_MOUSE_DOWN:
		return "Down"
	case NOX_MOUSE_DRAG_END:
		return "DragEnd"
	case NOX_MOUSE_UP:
		return "Up"
	case NOX_MOUSE_PRESSED:
		return "Pressed"
	default:
		return fmt.Sprintf("MouseState(%d)", int(s))
	}
}

const (
	NOX_MOUSE_DOWN     = MouseState(1)
	NOX_MOUSE_DRAG_END = MouseState(2)
	NOX_MOUSE_UP       = MouseState(3)
	NOX_MOUSE_PRESSED  = MouseState(4)
)

const (
	NOX_MOUSE_LEFT_DOWN       = MouseStateCode(4*(int(NOX_MOUSE_LEFT)+1) + int(NOX_MOUSE_DOWN))       // 5
	NOX_MOUSE_LEFT_DRAG_END   = MouseStateCode(4*(int(NOX_MOUSE_LEFT)+1) + int(NOX_MOUSE_DRAG_END))   // 6
	NOX_MOUSE_LEFT_UP         = MouseStateCode(4*(int(NOX_MOUSE_LEFT)+1) + int(NOX_MOUSE_UP))         // 7
	NOX_MOUSE_LEFT_PRESSED    = MouseStateCode(4*(int(NOX_MOUSE_LEFT)+1) + int(NOX_MOUSE_PRESSED))    // 8
	NOX_MOUSE_RIGHT_DOWN      = MouseStateCode(4*(int(NOX_MOUSE_RIGHT)+1) + int(NOX_MOUSE_DOWN))      // 9
	NOX_MOUSE_RIGHT_DRAG_END  = MouseStateCode(4*(int(NOX_MOUSE_RIGHT)+1) + int(NOX_MOUSE_DRAG_END))  // 10
	NOX_MOUSE_RIGHT_UP        = MouseStateCode(4*(int(NOX_MOUSE_RIGHT)+1) + int(NOX_MOUSE_UP))        // 11
	NOX_MOUSE_RIGHT_PRESSED   = MouseStateCode(4*(int(NOX_MOUSE_RIGHT)+1) + int(NOX_MOUSE_PRESSED))   // 12
	NOX_MOUSE_MIDDLE_DOWN     = MouseStateCode(4*(int(NOX_MOUSE_MIDDLE)+1) + int(NOX_MOUSE_DOWN))     // 13
	NOX_MOUSE_MIDDLE_DRAG_END = MouseStateCode(4*(int(NOX_MOUSE_MIDDLE)+1) + int(NOX_MOUSE_DRAG_END)) // 14
	NOX_MOUSE_MIDDLE_UP       = MouseStateCode(4*(int(NOX_MOUSE_MIDDLE)+1) + int(NOX_MOUSE_UP))       // 15
	NOX_MOUSE_MIDDLE_PRESSED  = MouseStateCode(4*(int(NOX_MOUSE_MIDDLE)+1) + int(NOX_MOUSE_PRESSED))  // 16
)

type MouseStateCode uint

func (st MouseStateCode) Split() (MouseButton, MouseState) {
	sti := int((st - 1) / 4)
	return MouseButton(sti - 1), MouseState(int(st-1)%4 + 1)
}

func ToMouseState(btn MouseButton, st MouseState) MouseStateCode {
	return MouseStateCode(4*(int(btn)+1) + int(st))
}

type noxMouseEventType uint

const (
	noxMouseEventMotion = noxMouseEventType(iota)
	noxMouseEventWheel
	noxMouseEventLeft
	noxMouseEventRight
	noxMouseEventMiddle
)

type noxMouseBtnInt struct {
	pressed bool
	state   MouseStateCode
	seq     uint
}

type noxMouseStateInt struct {
	pos   image.Point
	wheel int
	dpos  image.Point
	btn   [3]noxMouseBtnInt
}

type noxMouseEvent struct {
	Type    noxMouseEventType
	Pos     image.Point
	Wheel   int
	Pressed bool
	Seq     uint
}

func newMouseHandler(s Sequencer, chk bool) *mouseHandler {
	def := image.Point{X: seat.DefaultWidth, Y: seat.DefaultHeight}
	h := &mouseHandler{
		seq:   s,
		chk:   chk,
		sens:  1.0,
		queue: make(chan noxMouseEvent, mouseEventBufChan),
	}
	h.win.init(def)
	return h
}

type mouseHandler struct {
	seq    Sequencer
	chk    bool
	bounds image.Rectangle
	win    window
	pos    types.Pointf // float to make it cumulative for relative events

	sens float32

	distSlow bool // TODO: check what this does
	distCnt  int

	cur     noxMouseStateInt
	prev    noxMouseStateInt
	prevSeq uint
	prevBtn [3]image.Point

	buffer  [mouseEventBuf]noxMouseStateInt
	reading bool

	queue chan noxMouseEvent

	onMouseWheel []func(dv int)
}

func (h *mouseHandler) OnMouseWheel(fnc func(dv int)) {
	h.onMouseWheel = append(h.onMouseWheel, fnc)
}

func (h *mouseHandler) MouseMove(ev *seat.MouseMoveEvent) {
	if ev.Relative {
		dp := ev.Rel.Mul(h.sens)
		h.pos = h.pos.Add(dp)
		h.pos = clampf(h.win.view, h.pos)
	} else {
		h.pos = types.Point2f(ev.Pos)
	}
	h.pushEvent(noxMouseEvent{
		Type:  noxMouseEventMotion,
		Pos:   h.win.toDrawSpace(h.pos.Point()),
		Wheel: 0,
	})
}

func toMouseBtn(v seat.MouseButton) MouseButton {
	switch v {
	case seat.MouseButtonLeft:
		return NOX_MOUSE_LEFT
	case seat.MouseButtonRight:
		return NOX_MOUSE_RIGHT
	case seat.MouseButtonMiddle:
		return NOX_MOUSE_MIDDLE
	}
	return MouseButton(-1)
}

func (h *mouseHandler) MouseButton(ev *seat.MouseButtonEvent) {
	var typ noxMouseEventType
	switch ev.Button {
	case seat.MouseButtonLeft:
		typ = noxMouseEventLeft
	case seat.MouseButtonRight:
		typ = noxMouseEventRight
	case seat.MouseButtonMiddle:
		typ = noxMouseEventMiddle
	default:
		panic(ev.Button)
	}
	h.pushEvent(noxMouseEvent{
		Type:    typ,
		Pos:     h.win.toDrawSpace(h.pos.Point()),
		Pressed: ev.Pressed,
	})
}

func (h *mouseHandler) MouseWheel(ev *seat.MouseWheelEvent) {
	h.pushEvent(noxMouseEvent{
		Type:  noxMouseEventWheel,
		Pos:   h.win.toDrawSpace(h.pos.Point()),
		Wheel: ev.Wheel,
	})
}

func (h *mouseHandler) GetSensitivity() float32 {
	return h.sens
}

func (h *mouseHandler) SetSensitivity(v float32) {
	if v <= 0 {
		v = 1
	}
	h.sens = v
}

func (h *mouseHandler) IsMousePressed(btn seat.MouseButton) bool {
	return h.cur.btn[toMouseBtn(btn)].pressed
}

func (h *mouseHandler) GetMouseState(btn seat.MouseButton) MouseStateCode {
	return h.cur.btn[toMouseBtn(btn)].state
}

func (h *mouseHandler) SetMouseState(btn seat.MouseButton, st MouseStateCode) {
	h.cur.btn[toMouseBtn(btn)].state = st
}

func (h *mouseHandler) SetWinSize(rect image.Rectangle) {
	h.win.SetWinSize(rect)
}

func (h *mouseHandler) SetDrawWinSize(sz image.Point) {
	h.win.SetDrawWinSize(sz)
	h.setMouseBounds(image.Rect(0, 0, sz.X-1, sz.Y-1))
}

func (h *mouseHandler) pushEvent(e noxMouseEvent) bool {
	e.Seq = h.seq.NextEventSeq()
	select {
	case h.queue <- e:
		return true
	default:
		Log.Println("cannot keep up, mouse event dropped")
		return false
	}
}

func (h *mouseHandler) SetMouseBounds(r image.Rectangle) {
	h.setMouseBounds(r)
}

func (h *mouseHandler) setMouseBounds(r image.Rectangle) {
	Log.Printf("mouse bounds: %v", r)
	h.bounds = r
}

func (h *mouseHandler) getMousePos() image.Point {
	return h.cur.pos
}

func (h *mouseHandler) getMouseRel() image.Point {
	return h.cur.dpos
}

func (h *mouseHandler) setMousePos(p image.Point) {
	h.cur.pos = p
}

func (h *mouseHandler) GetMousePos() image.Point {
	return h.getMousePos()
}

func (h *mouseHandler) GetMouseRel() image.Point {
	return h.getMouseRel()
}

func (h *mouseHandler) GetMouseWheel() int {
	return h.cur.wheel
}

func (h *mouseHandler) SetMouseWheel(v int) {
	h.cur.wheel = v
}

func (h *mouseHandler) ChangeMousePos(p image.Point, isAbs bool) {
	h.changeMousePos(p, isAbs)
}

func (h *mouseHandler) changeMousePos(p image.Point, isAbs bool) {
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

func (h *mouseHandler) nox_client_mouseBtnStateFinal(pos image.Point, btn MouseButton) {
	cur := &h.cur.btn[btn]
	if cur.state == ToMouseState(btn, NOX_MOUSE_DOWN) {
		h.prevBtn[btn] = pos
	}
}

func (h *mouseHandler) noxResetMouseBuffer(cseq uint) {
	h.buffer[0].btn[0].seq = 1
	h.buffer[0].btn[0].pressed = false
	h.buffer[0].btn[1].seq = 1
	h.buffer[0].btn[1].pressed = false
	h.buffer[0].btn[2].seq = 1
	h.buffer[0].btn[2].pressed = false
	h.nox_client_processMouseEvents_4302A0(cseq, 1, true)
}

func (h *mouseHandler) nox_client_mouseBtnStateReset(btn MouseButton) {
	cur := &h.cur.btn[btn]
	prev := &h.prev.btn[btn]
	if cur.pressed && (prev.state == ToMouseState(btn, NOX_MOUSE_DOWN) || prev.state == ToMouseState(btn, NOX_MOUSE_PRESSED)) {
		cur.state = ToMouseState(btn, NOX_MOUSE_PRESSED)
	}
}

func (h *mouseHandler) nox_client_mouseBtnState_430230() {
	h.nox_client_mouseBtnStateReset(NOX_MOUSE_LEFT)
	h.nox_client_mouseBtnStateReset(NOX_MOUSE_RIGHT)
	h.nox_client_mouseBtnStateReset(NOX_MOUSE_MIDDLE)
}

func (h *mouseHandler) nextMouseEvent() *noxMouseEvent {
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

func (h *mouseHandler) nox_client_nextMouseEvent_47DB20(e *noxMouseStateInt) bool {
	*e = noxMouseStateInt{}
	me := h.nextMouseEvent()
	if me == nil {
		return false
	}
	e.pos = me.Pos
	switch me.Type {
	case noxMouseEventMotion:
		e.wheel = me.Wheel
	case noxMouseEventWheel:
		e.wheel = me.Wheel
		for _, fnc := range h.onMouseWheel {
			fnc(e.wheel)
		}
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

func (h *mouseHandler) nox_client_mouseBtnStateApply(cseq uint, evt *noxMouseStateInt, pos image.Point, btn MouseButton) {
	ev := &evt.btn[btn]
	cur := &h.cur.btn[btn]
	prevPos := h.prevBtn[btn]

	if ev.seq == 0 {
		h.nox_client_mouseBtnStateReset(btn)
		return
	}
	if cur.pressed == ev.pressed {
		return
	}
	dx := pos.X - prevPos.X
	dy := pos.Y - prevPos.Y
	if ev.pressed {
		if cur.state != ToMouseState(btn, NOX_MOUSE_UP) {
			cur.state = ToMouseState(btn, NOX_MOUSE_DOWN)
			cur.pressed = true
			cur.seq = cseq
		}
	} else {
		if int(cseq)-int(cur.seq) >= 15 || dx*dx+dy*dy >= 100 {
			cur.state = ToMouseState(btn, NOX_MOUSE_DRAG_END)
		} else {
			cur.state = ToMouseState(btn, NOX_MOUSE_UP)
		}
		cur.pressed = false
		cur.seq = cseq
	}
}

func (h *mouseHandler) MouseAction(key keybind.Key, ev keybind.Event) bool {
	if key == keybind.KeyLeftMouse {
		btn := NOX_MOUSE_LEFT
		state := h.GetMouseState(seat.MouseButtonLeft)
		if state != ToMouseState(btn, NOX_MOUSE_DOWN) && state != ToMouseState(btn, NOX_MOUSE_PRESSED) {
			return true
		}
		if state == ToMouseState(btn, NOX_MOUSE_PRESSED) && ev == 1 {
			return true
		}
	} else if key == keybind.KeyMiddleMouse {
		btn := NOX_MOUSE_MIDDLE
		state := h.GetMouseState(seat.MouseButtonMiddle)
		if state != ToMouseState(btn, NOX_MOUSE_DOWN) && state != ToMouseState(btn, NOX_MOUSE_PRESSED) {
			return true
		}
		if state == ToMouseState(btn, NOX_MOUSE_PRESSED) && ev == 1 {
			return true
		}
	} else if key == keybind.KeyRightMouse {
		btn := NOX_MOUSE_RIGHT
		state := h.GetMouseState(seat.MouseButtonRight)
		if state != ToMouseState(btn, NOX_MOUSE_DOWN) && state != ToMouseState(btn, NOX_MOUSE_PRESSED) {
			return true
		}
		if state == ToMouseState(btn, NOX_MOUSE_PRESSED) && ev == 1 {
			return true
		}
	} else if key == keybind.KeyMouseWheelUp {
		if h.GetMouseWheel() != 19 {
			return true
		}
	} else if key == keybind.KeyMouseWheelDown {
		if h.GetMouseWheel() != 20 {
			return true
		}
	}
	return false
}

func (h *mouseHandler) GetDistSlow() bool {
	return h.distSlow
}

func (h *mouseHandler) nox_client_processMouseEvents_4302A0(cseq uint, evNum int, a2 bool) {
	if h.prevSeq != cseq {
		h.cur.btn[NOX_MOUSE_LEFT].state = 0
		h.cur.btn[NOX_MOUSE_RIGHT].state = 0
		h.cur.btn[NOX_MOUSE_MIDDLE].state = 0
		h.cur.wheel = 0
		h.prevSeq = cseq
	}
	num := 0
	if !h.chk {
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
		h.nox_client_mouseBtnStateApply(cseq, ev, pos, NOX_MOUSE_LEFT)
		h.nox_client_mouseBtnStateApply(cseq, ev, pos, NOX_MOUSE_RIGHT)
		h.nox_client_mouseBtnStateApply(cseq, ev, pos, NOX_MOUSE_MIDDLE)
	}
	// update button prev pos, if necessary
	h.nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_LEFT)
	h.nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_RIGHT)
	h.nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_MIDDLE)

	h.cur.dpos.X = pos.X - h.prev.pos.X
	h.cur.dpos.Y = pos.Y - h.prev.pos.Y
	if h.cur.dpos.X*h.cur.dpos.X+h.cur.dpos.Y*h.cur.dpos.Y >= 4 {
		h.distCnt = 0
		h.distSlow = false
	} else {
		h.distCnt++
		if h.distCnt >= 10 {
			h.distSlow = true
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

func (h *mouseHandler) nox_client_readMouseBuffer_4306A0(cseq uint, a1 bool) bool {
	if h.reading {
		return false
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
	h.nox_client_processMouseEvents_4302A0(cseq, n, a1)
	h.reading = false
	return n > 0
}
