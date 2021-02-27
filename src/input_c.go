package main

/*
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "defs.h"

void nox_xxx_onChar_488BD0(unsigned short c);
void OnLibraryNotice_265(unsigned int arg1, unsigned int arg2, unsigned int arg3);
*/
import "C"
import (
	"nox/client/input"
	"nox/common/types"
	"unsafe"
)

type noxMouseEventType uint

const (
	noxMouseEventMotion = noxMouseEventType(iota)
	noxMouseEventWheel
	noxMouseEventLeft
	noxMouseEventRight
	noxMouseEventMiddle
)

var imeBuffer string

func setIMEBuffer(buf string) {
	imeBuffer = buf
}

//export nox_input_pollEvents_4453A0
func nox_input_pollEvents_4453A0() C.int {
	inpHandler.Tick()
	return 0
}

//export nox_input_pollEventsMovie
func nox_input_pollEventsMovie() C.int {
	return C.int(bool2int(inpHandler.WaitClick()))
}

//export nox_xxx_freeKeyboard_47FCC0
func nox_xxx_freeKeyboard_47FCC0() C.int {
	return 0
}

//export nox_input_getSensitivity
func nox_input_getSensitivity() C.float {
	return C.float(inpHandler.GetSensitivity())
}

//export nox_input_setSensitivity
func nox_input_setSensitivity(v C.float) {
	inpHandler.SetSensitivity(float32(v))
}

//export acquireMouse_sub_47D8C0
func acquireMouse_sub_47D8C0() C.int {
	inpHandler.AcquireMouse()
	return 0
}

//export unacquireMouse_sub_47D8B0
func unacquireMouse_sub_47D8B0() C.int {
	inpHandler.UnacquireMouse()
	return 0
}

//export nox_xxx_initMouse_47D8D0
func nox_xxx_initMouse_47D8D0() C.int {
	inputInitMouse()
	return 1
}

//export nox_input_enableTextEdit_5700CA
func nox_input_enableTextEdit_5700CA() {
	inpHandler.StartTextInput()
}

//export nox_input_disableTextEdit_5700F6
func nox_input_disableTextEdit_5700F6() {
	inpHandler.StopTextInput()
}

//export nox_input_shiftState
func nox_input_shiftState() C.bool {
	return C.bool(inpHandler.KeyModState(input.KeyShift))
}

//export nox_input_scrollLockState
func nox_input_scrollLockState() C.bool {
	// TODO: why it uses RALT?
	return C.bool(inpHandler.KeyModState(input.KeyAltR))
}

//export input_set_win_size
func input_set_win_size(w, h C.int) {
	inpHandler.SetWinSize(types.Size{W: int(w), H: int(h)})
}

//export input_set_draw_win_size
func input_set_draw_win_size(w, h C.int) {
	inpHandler.SetDrawWinSize(types.Size{W: int(w), H: int(h)})
}

//export nox_input_getStringBuffer_57011C
func nox_input_getStringBuffer_57011C() *C.wchar_t {
	return CWString(imeBuffer)
}

//export nox_input_freeStringBuffer_57011C
func nox_input_freeStringBuffer_57011C(p *C.wchar_t) {
	WStrFree(p)
}

//export nox_input_resetBuffers
func nox_input_resetBuffers() {}

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
		C.OnLibraryNotice_265(C.uint(uintptr(unsafe.Pointer(&e))), 2, C.uint(e.wheel))
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

//export controller_relative
func controller_relative() C.bool {
	return C.bool(inpHandler.Gamepad().InRelative())
}

//export controller_relative_pos
func controller_relative_pos() (out C.nox_pointf) {
	if inpHandler.Gamepad() == nil {
		return
	}
	p := inpHandler.Gamepad().StickRel().Posf()
	out.x = C.float(p.X)
	out.y = C.float(p.Y)
	return
}

//export nox_input_isMouseDown
func nox_input_isMouseDown() C.bool {
	return C.bool(inpHandler.IsMouseDown())
}
