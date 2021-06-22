package main

/*
#include <stdbool.h>

#include "defs.h"

extern nox_mouse_state_t nox_mouse;

extern nox_window* dword_5d4594_1321236;
extern nox_window* dword_5d4594_1321240;
extern nox_window* dword_5d4594_1321248;
extern nox_window* dword_5d4594_1321244;

extern nox_window* dword_5d4594_1522616;
extern nox_window* dword_5d4594_1522620;
extern nox_window* dword_5d4594_1522624;
extern nox_window* dword_5d4594_1522628;

void sub_42CD90();
wchar_t* sub_42E8E0(int a1, int a2);
int nox_common_readcfgfile(const char* path, int a2);
void nox_xxx_onChar_488BD0(unsigned short c);
void OnLibraryNotice_265(unsigned int arg1, unsigned int arg2, int arg3);
*/
import "C"
import (
	"image"
	"math"
	"unsafe"

	"nox/v1/client/input"
	"nox/v1/client/input/keybind"
	"nox/v1/common/memmap"
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

func getMousePos() image.Point {
	return image.Point{
		X: int(C.nox_mouse.pos.x),
		Y: int(C.nox_mouse.pos.y),
	}
}

func setMousePos(p image.Point) {
	C.nox_mouse.pos.x = C.int(p.X)
	C.nox_mouse.pos.y = C.int(p.Y)
}

//export nox_client_changeMousePos_430A00
func nox_client_changeMousePos_430A00(x, y C.int, isAbs C.bool) {
	changeMousePos(image.Pt(int(x), int(y)), bool(isAbs))
}

//export nox_xxx_setMouseBounds_430A70
func nox_xxx_setMouseBounds_430A70(xmin, xmax, ymin, ymax C.int) {
	setMouseBounds(image.Rect(int(xmin), int(ymin), int(xmax), int(ymax)))
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
		C.OnLibraryNotice_265(C.uint(uintptr(unsafe.Pointer(&e))), 2, C.int(e.wheel))
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

//export nox_xxx_keybind_nameByKey
func nox_xxx_keybind_nameByKey(key C.uint) *C.char {
	b := keyBinding.KeyByCode(keybind.Key(key))
	if b == nil {
		return nil
	}
	return internCStr(b.Name)
}

//export nox_xxx_keybind_keyByName
func nox_xxx_keybind_keyByName(name *C.char) C.uint {
	b := keyBinding.KeyByName(GoString(name))
	if b == nil {
		return 0
	}
	return C.uint(b.Key)
}

//export nox_xxx_keybind_nameByTitle_42E960
func nox_xxx_keybind_nameByTitle_42E960(title *C.wchar_t) *C.char {
	b := keyBinding.KeyByTitle(GoWString(title))
	if b == nil {
		return nil
	}
	return internCStr(b.Name)
}

//export nox_xxx_keybind_titleByKey_42EA00
func nox_xxx_keybind_titleByKey_42EA00(key C.uint) *C.wchar_t {
	b := keyBinding.KeyByCode(keybind.Key(key))
	if b == nil {
		return internWStr("")
	}
	return internWStr(b.Title)
}

//export nox_xxx_keybind_titleByKeyZero_42EA00
func nox_xxx_keybind_titleByKeyZero_42EA00(key C.uint) *C.wchar_t {
	b := keyBinding.KeyByCode(keybind.Key(key))
	if b == nil {
		return nil
	}
	return internWStr(b.Title)
}

//export nox_xxx_bindevent_bindNameByKey
func nox_xxx_bindevent_bindNameByKey(key C.uint) *C.char {
	b := keyBinding.EventByCode(keybind.Key(key))
	if b == nil {
		return nil
	}
	return internCStr(b.Name)
}

//export nox_xxx_bindevent_bindKeyByName
func nox_xxx_bindevent_bindKeyByName(name *C.char) C.uint {
	b := keyBinding.EventByName(GoString(name))
	if b == nil {
		return 0
	}
	return C.uint(b.Key)
}

//export nox_xxx_bindevent_bindNameByTitle_42EA40
func nox_xxx_bindevent_bindNameByTitle_42EA40(title *C.wchar_t) *C.char {
	b := keyBinding.EventByTitle(GoWString(title))
	if b == nil {
		return nil
	}
	return internCStr(b.Name)
}

//export sub_4C3CB0
func sub_4C3CB0() {
	C.sub_42CD90()
	C.nox_common_readcfgfile(internCStr("default.cfg"), 1)
	sub_4C3B70()
}

//export sub_4CBF40
func sub_4CBF40() {
	C.sub_42CD90()
	C.nox_common_readcfgfile(internCStr("default.cfg"), 1)
	sub_4CBBF0()
}

//export sub_4C3B70
func sub_4C3B70() {
	win36 := asWindow(C.dword_5d4594_1321236)
	win40 := asWindow(C.dword_5d4594_1321240)
	win44 := asWindow(C.dword_5d4594_1321244)
	win48 := asWindow(C.dword_5d4594_1321248)
	win36.Func94(16399, 0, 0)
	win40.Func94(16399, 0, 0)
	win44.Func94(16399, 0, 0)
	win48.Func94(16399, 0, 0)
	for _, ev := range keyBinding.Events() {
		if ev.Key == 44 {
			continue
		}
		win40.Func94(16397, uintptr(unsafe.Pointer(internWStr(ev.Title))), math.MaxUint32)
		win36.Func94(16397, uintptr(memmap.PtrOff(0x587000, 185340)), math.MaxUint32)
		v2p := C.sub_42E8E0(C.int(ev.Key), 1)
		v3p := C.sub_42E8E0(C.int(ev.Key), 2)
		v2 := GoWString(v2p)
		v3 := GoWString(v3p)
		if v2 != "" {
			win44.Func94(16397, uintptr(unsafe.Pointer(v2p)), math.MaxUint32)
		} else {
			win44.Func94(16397, uintptr(memmap.PtrOff(0x587000, 185344)), math.MaxUint32)
		}
		if v3 != "" && v2 != v3 {
			win48.Func94(16397, uintptr(unsafe.Pointer(v3p)), math.MaxUint32)
		} else {
			win48.Func94(16397, uintptr(memmap.PtrOff(0x587000, 185348)), math.MaxUint32)
		}
	}
}

//export sub_4CBBF0
func sub_4CBBF0() {
	win16 := asWindow(C.dword_5d4594_1522616)
	win20 := asWindow(C.dword_5d4594_1522620)
	win24 := asWindow(C.dword_5d4594_1522624)
	win28 := asWindow(C.dword_5d4594_1522628)
	win16.Func94(16399, 0, 0)
	win20.Func94(16399, 0, 0)
	win24.Func94(16399, 0, 0)
	win28.Func94(16399, 0, 0)
	for _, ev := range keyBinding.Events() {
		if ev.Key == 44 {
			continue
		}
		win20.Func94(16397, uintptr(unsafe.Pointer(internWStr(ev.Title))), math.MaxUint32)
		win16.Func94(16397, uintptr(memmap.PtrOff(0x587000, 187544)), math.MaxUint32)
		v2p := C.sub_42E8E0(C.int(ev.Key), 1)
		v3p := C.sub_42E8E0(C.int(ev.Key), 2)
		v2 := GoWString(v2p)
		v3 := GoWString(v3p)
		if v2 != "" {
			win24.Func94(16397, uintptr(unsafe.Pointer(v2p)), math.MaxUint32)
		} else {
			win24.Func94(16397, uintptr(memmap.PtrOff(0x587000, 187548)), math.MaxUint32)
		}
		if v3 != "" && v2 != v3 {
			win28.Func94(16397, uintptr(unsafe.Pointer(v3p)), math.MaxUint32)
		} else {
			win28.Func94(16397, uintptr(memmap.PtrOff(0x587000, 187552)), math.MaxUint32)
		}
	}
}
