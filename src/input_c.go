package main

/*
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "defs.h"
#include "blobs/memmap.h"

extern int mouse1_state;
extern unsigned int mouse_event_ridx;
extern unsigned int mouse_event_widx;
extern wchar_t g_ime_buf[512];

struct keyboard_event {
	unsigned char code;
	unsigned char state;
	unsigned int seq;
};

struct mouse_event {
	unsigned int type;
	int x, y, wheel;
	int pressed;
	unsigned int seq;
};

void nox_xxx_onChar_488BD0(unsigned short c);
struct keyboard_event* nox_newKeyboardEvent();
struct mouse_event* nox_newMouseEvent();
*/
import "C"
import (
	"nox/blobs"
	"nox/common/types"

	"github.com/veandco/go-sdl2/sdl"
)

const ( // must be in sync with C
	noxMouseMotion       = 0
	noxMouseWheel        = 1
	noxMouseButtonLeft   = 2
	noxMouseButtonRight  = 3
	noxMouseButtonMiddle = 4
)

//export nox_xxx_processWinMessages_4453A0_poll_events
func nox_xxx_processWinMessages_4453A0_poll_events() C.int {
	inputPollEvents()
	return 0
}

//export input_cleanup
func input_cleanup() {
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

//export initMouse_sub_47D8D0
func initMouse_sub_47D8D0() C.int {
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

func inputInitMouse() {
	inputAcquireMouse()

	C.mouse_event_ridx = 0
	C.mouse_event_widx = 0

	// indicates that mouse is present so cursor should be drawn
	*blobs.PtrUint32(0x5D4594, 1193108) = 1
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

// inputMouseSet sets mouse to a specific position in the window space.
func inputMouseSet(p types.Point) {
	inputMousePos = p
	p = inputToDrawSpace(p)

	me := C.nox_newMouseEvent()
	me._type = noxMouseMotion
	me.x = C.int(p.X)
	me.y = C.int(p.Y)
	me.wheel = 0
}

// inputMouseWheel moves mouse wheel by a specific amount.
func inputMouseWheel(dv int) {
	p := inputMousePos
	p = inputToDrawSpace(p)

	me := C.nox_newMouseEvent()
	me._type = noxMouseWheel
	me.x = C.int(p.X)
	me.y = C.int(p.Y)
	me.wheel = C.int(dv)
}

// inputMouseButtonAt sets mouse pos to a given position and sets a specified mouse button state.
func inputMouseButtonAt(p types.Point, button mouseButton, pressed bool) {
	var typ int
	switch button {
	case mouseButtonLeft:
		typ = noxMouseButtonLeft
	case mouseButtonRight:
		typ = noxMouseButtonRight
	case mouseButtonMiddle:
		typ = noxMouseButtonMiddle
	default:
		panic(button)
	}
	inputMousePos = p
	p = inputToDrawSpace(p)

	me := C.nox_newMouseEvent()
	me._type = C.uint(typ)
	me.x = C.int(p.X)
	me.y = C.int(p.Y)
	if pressed {
		me.pressed = 1
	} else {
		me.pressed = 0
	}
}

func inputKeyboard(code sdl.Scancode, pressed bool) {
	ke := C.nox_newKeyboardEvent()
	ke.code = C.uchar(scanCodeToKeyNum[code])
	if pressed {
		ke.state = 1
	} else {
		ke.state = 0
	}
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
