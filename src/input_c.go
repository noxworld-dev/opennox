package main

/*
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "defs.h"

extern int mouse1_state;
extern wchar_t g_ime_buf[512];

void nox_xxx_onChar_488BD0(unsigned short c);
void onLibraryNotice_mouseWheel(nox_mouse_state_t* e);
*/
import "C"
import (
	"nox/common/types"
)

type noxMouseEventType uint

const (
	noxMouseEventMotion = noxMouseEventType(iota)
	noxMouseEventWheel
	noxMouseEventLeft
	noxMouseEventRight
	noxMouseEventMiddle
)

//export nox_xxx_processWinMessages_4453A0_poll_events
func nox_xxx_processWinMessages_4453A0_poll_events() C.int {
	inputPollEvents()
	return 0
}

func inputCleanup() {
	inputCleanupControllers()
}

//export acquireMouse_sub_47D8C0
func acquireMouse_sub_47D8C0() C.int {
	inputAcquireMouse()
	return 0
}

//export unacquireMouse_sub_47D8B0
func unacquireMouse_sub_47D8B0() C.int {
	inputUnacquireMouse()
	return 0
}

//export nox_xxx_initMouse_47D8D0
func nox_xxx_initMouse_47D8D0() C.int {
	inputInitMouse()
	return 1
}

//export nox_xxx_changeWinProcToEdit_5700CA
func nox_xxx_changeWinProcToEdit_5700CA(a1 **C.int, hwnd C.int) C.int {
	inputStartTextInput()
	return 0
}

//export nox_xxx_changeWinProcToNormal_5700F6
func nox_xxx_changeWinProcToNormal_5700F6(a1 **C.int) *C.int {
	inputStopTextInput()
	return nil
}

//export input_set_win_size
func input_set_win_size(w, h C.int) {
	inputSetWinSize(types.Size{W: int(w), H: int(h)})
}

//export input_set_draw_win_size
func input_set_draw_win_size(w, h C.int) {
	inputSetDrawWinSize(types.Size{W: int(w), H: int(h)})
}

func setIMEBuffer(buf []uint16) {
	if len(buf) >= 512 {
		buf = buf[:512-1]
	}
	for i, c := range buf {
		C.g_ime_buf[i] = C.wchar_t(c)
	}
	C.g_ime_buf[len(buf)] = 0
}

func noxInputOnChar(c uint16) {
	C.nox_xxx_onChar_488BD0(C.wchar_t(c))
}

//export nox_client_nextMouseEvent_47DB20
func nox_client_nextMouseEvent_47DB20(e *C.nox_mouse_state_t) C.bool {
	*e = C.nox_mouse_state_t{}
	me := nextMouseEvent()
	if me == nil {
		return false
	}
	e.pos.x = C.int(me.X)
	e.pos.y = C.int(me.Y)
	pressed := 0
	if me.Pressed {
		pressed = 1
	}
	switch me.Type {
	case noxMouseEventMotion:
		e.wheel = C.int(me.Wheel)
	case noxMouseEventWheel:
		e.wheel = C.int(me.Wheel)
		// mix event hanlder is triggered only for wheel events
		C.onLibraryNotice_mouseWheel(e)
	case noxMouseEventLeft:
		e.btn[C.NOX_MOUSE_LEFT].pressed = C.int(pressed)
		e.btn[C.NOX_MOUSE_LEFT].seq = C.uint(me.Seq)
	case noxMouseEventRight:
		e.btn[C.NOX_MOUSE_RIGHT].pressed = C.int(pressed)
		e.btn[C.NOX_MOUSE_RIGHT].seq = C.uint(me.Seq)
	case noxMouseEventMiddle:
		e.btn[C.NOX_MOUSE_MIDDLE].pressed = C.int(pressed)
		e.btn[C.NOX_MOUSE_MIDDLE].seq = C.uint(me.Seq)
	}
	return true
}

//export nox_xxx_getKeyFromKeyboardImpl_47FA80
func nox_xxx_getKeyFromKeyboardImpl_47FA80(e *C.nox_keyboard_btn_t) {
	*e = C.nox_keyboard_btn_t{}
	ke := nextKeyEvent()
	if ke == nil {
		return
	}

	e.code = C.uchar(ke.Code)
	state := 0
	if ke.Pressed {
		state = 1
	}
	e.state = C.uchar(state + 1)
	e.seq = C.uint(ke.Seq)
}

//export send_mouse1_event
func send_mouse1_event() {
	inputMouseButton(mouseButtonRight, C.mouse1_state != 0 /* && !mouse0_state */)
}

//export controller_relative
func controller_relative() C.bool {
	return C.bool(gpad.InRelative())
}

//export controller_relative_pos
func controller_relative_pos() (out C.nox_pointf) {
	if gpad == nil {
		return
	}
	p := gpad.stickRel().Posf()
	out.x = C.float(p.X)
	out.y = C.float(p.Y)
	return
}

//export nox_input_isMouseDown
func nox_input_isMouseDown() C.bool {
	return C.bool(isMouseDown())
}
