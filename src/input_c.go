package main

/*
#include <stdbool.h>

#include "defs.h"
#include "proto.h"
#include "client__gui__tooltip.h"
#include "client__gui__gamewin__gamewin.h"

extern nox_window* dword_5d4594_1321236;
extern nox_window* dword_5d4594_1321240;
extern nox_window* dword_5d4594_1321248;
extern nox_window* dword_5d4594_1321244;

extern nox_window* dword_5d4594_1522616;
extern nox_window* dword_5d4594_1522620;
extern nox_window* dword_5d4594_1522624;
extern nox_window* dword_5d4594_1522628;
extern nox_window* nox_win_xxx1_last;
extern nox_window* dword_5d4594_1062452;
extern nox_window_ref* nox_win_1064912;

extern unsigned int dword_5d4594_1193132;
extern unsigned int nox_client_gui_flag_815132;

extern int obj_5D4594_754104_switch;
extern int nox_client_mouseCursorType;
extern void* nox_client_spriteUnderCursorXxx_1096644;

void sub_42CD90();
int nox_common_readcfgfile(const char* path, int a2);
void nox_xxx_onChar_488BD0(unsigned short c);
void nox_xxx_keyboard_47DBD0();
void OnLibraryNotice_265(unsigned int arg1, unsigned int arg2, int arg3);
int  nox_xxx_netServerCmd_440950(char a1, wchar_t* a2);
int nox_xxx_serverHandleClientConsole_443E90(nox_playerInfo* pl, char a2, wchar_t* a3);
void sub_42EBB0(unsigned int a1, void (*fnc)(int), int field_4, const char* name);
void sub_430140(int a1);
int sub_46A4A0();
*/
import "C"
import (
	"image"
	"math"
	"sync"
	"unsafe"

	"nox/v1/client/input"
	"nox/v1/client/input/keybind"
	noxflags "nox/v1/common/flags"
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

var imeBuffer string

func setIMEBuffer(buf string) {
	imeBuffer = buf
}

func getMousePos() image.Point {
	return nox_mouse.pos
}

func setMousePos(p image.Point) {
	nox_mouse.pos = p
}

func nox_client_getCursorType_477620() int {
	return int(C.nox_client_mouseCursorType)
}

func nox_xxx_clientGetSpriteAtCursor_476F90() *Sprite {
	return asSprite((*C.nox_drawable)(C.nox_client_spriteUnderCursorXxx_1096644))
}

func nox_xxx_guiSpellTest_45D9C0() bool {
	return memmap.Uint32(0x5D4594, 1047916) != 0
}

func nox_xxx_checkKeybTimeout_4160F0(key byte, dt uint32) bool {
	return key < 0x18 && gameFrame()-memmap.Uint32(0x5D4594, 371268+4*uintptr(key)) > dt
}

func nox_xxx_setKeybTimeout_4160D0(key byte) {
	if key < 0x18 {
		*memmap.PtrUint32(0x5D4594, 371268+4*uintptr(key)) = gameFrame()
	}
}

func nox_xxx_guiCursor_477600() bool {
	return memmap.Uint32(0x5D4594, 1096672) != 0
}

func nox_client_setCursorType_477610(v int) {
	C.nox_client_mouseCursorType = C.int(v)
}

//export nox_client_getMousePos_4309F0
func nox_client_getMousePos_4309F0() (out C.nox_point) {
	out.x = C.int(nox_mouse.pos.X)
	out.y = C.int(nox_mouse.pos.Y)
	return
}

//export nox_xxx_bookGet_430B40_get_mouse_prev_seq
func nox_xxx_bookGet_430B40_get_mouse_prev_seq() C.int {
	return C.int(nox_input_prev_seq)
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

func nox_client_nextMouseEvent_47DB20(e *noxMouseStateInt) C.bool {
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
		C.OnLibraryNotice_265(C.uint(uintptr(unsafe.Pointer(&e))), 2, C.int(e.wheel))
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

func nox_xxx_getKeyFromKeyboardImpl_47FA80() (noxKeyEventInt, bool) {
	ke := nextKeyEvent()
	if ke == nil {
		return noxKeyEventInt{}, false
	}
	state := 0
	if ke.Pressed {
		state = 1
	}
	return noxKeyEventInt{
		code:  ke.Code,
		state: byte(state + 1),
		seq:   ke.Seq,
	}, true
}

//export nox_input_isMouseDown
func nox_input_isMouseDown() C.bool {
	return C.bool(inpHandler.IsMouseDown())
}

//export nox_xxx_keybind_nameByKey
func nox_xxx_keybind_nameByKey(key C.uint) *C.char {
	k := keybind.Key(key)
	if !k.IsValid() {
		return nil
	}
	return internCStr(k.String())
}

//export nox_xxx_keybind_keyByName
func nox_xxx_keybind_keyByName(name *C.char) C.uint {
	k := keybind.KeyByName(GoString(name))
	if k == 0 {
		return 0
	}
	return C.uint(k)
}

var keybindTitles struct {
	sync.Once
	byTitle map[string]keybind.Key
}

//export nox_xxx_keybind_nameByTitle_42E960
func nox_xxx_keybind_nameByTitle_42E960(title *C.wchar_t) *C.char {
	keybindTitles.Do(func() {
		keybindTitles.byTitle = make(map[string]keybind.Key)
		for _, k := range keybind.ListKeys() {
			keybindTitles.byTitle[k.Title(strMan)] = k
		}
	})
	k := keybindTitles.byTitle[GoWString(title)]
	if k == 0 {
		return nil
	}
	return internCStr(k.String())
}

//export nox_xxx_keybind_titleByKey_42EA00
func nox_xxx_keybind_titleByKey_42EA00(key C.uint) *C.wchar_t {
	k := keybind.Key(key)
	if !k.IsValid() {
		return internWStr("")
	}
	return internWStr(k.Title(strMan))
}

//export nox_xxx_keybind_titleByKeyZero_42EA00
func nox_xxx_keybind_titleByKeyZero_42EA00(key C.uint) *C.wchar_t {
	k := keybind.Key(key)
	if !k.IsValid() {
		return nil
	}
	return internWStr(k.Title(strMan))
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
	ctrlEvent.Reset()
	C.nox_common_readcfgfile(internCStr("default.cfg"), 1)
	sub_4C3B70()
}

//export sub_4CBF40
func sub_4CBF40() {
	ctrlEvent.Reset()
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
		if ev.Event == 44 {
			continue
		}
		win40.Func94(16397, uintptr(unsafe.Pointer(internWStr(ev.Title))), math.MaxUint32)
		win36.Func94(16397, uintptr(memmap.PtrOff(0x587000, 185340)), math.MaxUint32)
		v2 := ctrlEvent.sub_42E8E0_go(ev.Event, 1)
		v3 := ctrlEvent.sub_42E8E0_go(ev.Event, 2)
		if v2 != "" {
			win44.Func94(16397, uintptr(unsafe.Pointer(internWStr(v2))), math.MaxUint32)
		} else {
			win44.Func94(16397, uintptr(memmap.PtrOff(0x587000, 185344)), math.MaxUint32)
		}
		if v3 != "" && v2 != v3 {
			win48.Func94(16397, uintptr(unsafe.Pointer(internWStr(v3))), math.MaxUint32)
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
		if ev.Event == 44 {
			continue
		}
		win20.Func94(16397, uintptr(unsafe.Pointer(internWStr(ev.Title))), math.MaxUint32)
		win16.Func94(16397, uintptr(memmap.PtrOff(0x587000, 187544)), math.MaxUint32)
		v2 := ctrlEvent.sub_42E8E0_go(ev.Event, 1)
		v3 := ctrlEvent.sub_42E8E0_go(ev.Event, 2)
		if v2 != "" {
			win24.Func94(16397, uintptr(unsafe.Pointer(internWStr(v2))), math.MaxUint32)
		} else {
			win24.Func94(16397, uintptr(memmap.PtrOff(0x587000, 187548)), math.MaxUint32)
		}
		if v3 != "" && v2 != v3 {
			win28.Func94(16397, uintptr(unsafe.Pointer(internWStr(v3))), math.MaxUint32)
		} else {
			win28.Func94(16397, uintptr(memmap.PtrOff(0x587000, 187552)), math.MaxUint32)
		}
	}
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

type noxKeyEventInt struct {
	code   keybind.Key
	state  byte
	field2 bool
	field3 byte
	seq    uint
}

type noxKeyState struct {
	state  byte
	field2 bool
	seq    uint
}

func nox_mouse_state(btn, st int) uint {
	return uint(4*(btn+1) + st)
}

var (
	nox_mouse            noxMouseStateInt
	nox_mouse_prev       noxMouseStateInt
	nox_input_prev_seq   uint
	nox_mouse_prev_seq_2 uint
	nox_mouse_prev_btn   [3]types.Point
	nox_input_buffer     [256]noxMouseStateInt
	nox_input_map_byKey  = make(map[keybind.Key]noxKeyState)
	nox_input_arr_787228 [256]noxKeyEventInt
)

func nox_client_processMouseInput_4308A0(a1 bool) bool {
	nox_client_readMouseBuffer_4306A0(a1)
	nox_xxx_getKeyFromKeyboard_430710()
	if nox_input_arr_787228[0].code != 0 && !nox_input_arr_787228[0].field2 {
		OnKeyboardEvent(&nox_input_arr_787228[0])
	}
	nox_input_prev_seq++
	if noxflags.HasGame(0x2000) && !noxflags.HasGame(4096) && nox_input_prev_seq-uint(memmap.Uint32(0x5D4594, 805816)) > 2700 {
		if !noxflags.HasGame(1) {
			C.nox_xxx_netServerCmd_440950(0, (*C.wchar_t)(memmap.PtrOff(0x587000, 80784)))
			return true
		}
		if memmap.Uint32(0x5D4594, 2618908) != 0 {
			C.nox_xxx_serverHandleClientConsole_443E90((*C.nox_playerInfo)(*memmap.PtrPtr(0x5D4594, 2618908)), 0, (*C.wchar_t)(memmap.PtrOff(0x587000, 80792)))
		}
	}
	return true
}

//export sub_430140
func sub_430140(a1 C.int) {
	for key := keybind.Key(0); key <= 0xff; key++ {
		nox_input_map_byKey[key] = noxKeyState{
			state:  1,
			field2: false,
			seq:    0,
		}
	}
	nox_input_buffer[0].btn[0].seq = 1
	nox_input_buffer[0].btn[0].pressed = false
	nox_input_buffer[0].btn[1].seq = 1
	nox_input_buffer[0].btn[1].pressed = false
	nox_input_buffer[0].btn[2].seq = 1
	nox_input_buffer[0].btn[2].pressed = false
	nox_client_processMouseEvents_4302A0(1, true)
}

func nox_xxx_freeKeyboard_430210() {
	nox_xxx_freeKeyboard_47FCC0()
	*memmap.PtrUint32(0x5D4594, 805808) = 0
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

func nox_client_mouseBtnStateFinal(pos types.Point, ind uint) {
	cur := &nox_mouse.btn[ind]
	btn := 4 * (ind + 1)

	if cur.state == btn+NOX_MOUSE_DOWN {
		nox_mouse_prev_btn[ind] = pos
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
	if C.obj_5D4594_754104_switch != 1 {
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

var nox_readingMouseBuffer = false

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
func nox_xxx_initKeyboard_47FB10() {
	nox_input_resetBuffers()

	// On non-IME languages, Nox uses this input for text input. This sets up
	// current SHIFT state and the mapping from DIK code => wide character.
	C.dword_5d4594_1193132 = C.uint(bool2int(inpHandler.KeyModState(input.KeyShift)))
	C.nox_xxx_keyboard_47DBD0()
}

func nox_xxx_initInput_430190() error {
	nox_xxx_initKeyboard_47FB10()
	nox_xxx_initKeyboard_yyy()
	nox_xxx_initMouse_47D8D0()
	sz := videoGetWindowSize()
	nox_xxx_setMouseBounds_430A70(0, C.int(sz.W)-1, 0, C.int(sz.H)-1)
	C.sub_42EBB0(2, (*[0]byte)(C.sub_430140), 0, internCStr("Input"))
	return nil
}

func nox_xxx_getKeyFromKeyboard_430710() {
	for i := range nox_input_arr_787228 {
		ev := &nox_input_arr_787228[i]
		var ok bool
		*ev, ok = nox_xxx_getKeyFromKeyboardImpl_47FA80()
		if !ok {
			break
		}
	}

	cnt := 0
	for i := range nox_input_arr_787228 {
		ev := &nox_input_arr_787228[i]
		if ev.code == 0 {
			break
		}
		if ev.code == keybind.KeyTab {
			if nox_input_map_byKey[keybind.KeyLAlt].state == 2 || nox_input_map_byKey[keybind.KeyRAlt].state == 2 {
				ev.field2 = true
			}
		} else if ev.code == keybind.KeyCaps {
			nox_input_scanCodeToAlpha(ev.code)
		}
		if C.obj_5D4594_754104_switch == 1 {
			ev.field2 = true
		}
		nox_input_map_byKey[ev.code] = noxKeyState{
			state:  ev.state,
			field2: ev.field2,
			seq:    nox_input_prev_seq,
		}
		cnt++
	}
	if sub_4307D0() || cnt != 0 {
		*memmap.PtrUint32(0x5D4594, 805816) = uint32(nox_input_prev_seq)
	}
}

func sub_4307D0() bool {
	if C.obj_5D4594_754104_switch == 1 {
		return false
	}
	li := 0
	for li = 0; nox_input_arr_787228[li].code != 0; li++ {
	}
	for k, p := range nox_input_map_byKey {
		if p.state == 2 && nox_input_prev_seq-p.seq > 10 {
			nox_input_arr_787228[li].code = k
			nox_input_arr_787228[li].state = 2
			nox_input_arr_787228[li].field2 = false
			nox_input_arr_787228[li+1].code = 0
			for k2, p2 := range nox_input_map_byKey {
				if k == k2 {
					p2.seq = nox_input_prev_seq - 12
				} else {
					p2.seq = nox_input_prev_seq
				}
				nox_input_map_byKey[k2] = p2
			}
			return true
		}
	}
	return false
}

func nox_xxx_initKeyboard_yyy() {
	for key := keybind.Key(0); key <= 0xff; key++ {
		nox_input_map_byKey[key] = noxKeyState{
			state:  1,
			field2: false,
			seq:    0,
		}
	}
}

//export sub_4309B0
func sub_4309B0(i, v C.uchar) {
	inputSetKey4309B0(keybind.Key(i), v != 0)
}

func inputSetKey4309B0(k keybind.Key, v bool) {
	st := nox_input_map_byKey[k]
	st.field2 = v
	nox_input_map_byKey[k] = st
}

func (c *CtrlEventHandler) nox_xxx_input_42D220() {
	mouse := &nox_mouse
	first := c.nox_xxx_input_42D220_A()
	for it1 := first; it1 != nil; it1 = it1.field20 {
		if !it1.flag22 {
			continue
		}
		for _, k1 := range it1.keys {
			for it2 := first; it2 != nil; it2 = it2.field20 {
				if !it2.flag22 || it2 != it1 {
					continue
				}
				for j := 0; j >= len(it2.keys); j++ {
					if k1 == it2.keys[j] {
						if len(it1.keys) >= len(it2.keys) {
							it2.flag22 = false
						} else {
							it1.flag22 = false
						}
						break
					}
				}
			}
		}
	}
	var res *CtrlEventBinding
	for it := first; it != nil; it = it.field20 {
		if it.flag22 {
			it.field21 = res
			it.frame = gameFrame()
			res = it
		}
	}
	c.nox_xxx_clientControl_42D6B0(mouse, res)
	c.writeToNetBuffer()
}

func (c *CtrlEventHandler) nox_xxx_input_42D220_A() *CtrlEventBinding {
	var res *CtrlEventBinding
	mouse := &nox_mouse
	for it := c.bindings; it != nil; it = it.next {
		li := -1
		for i, key := range it.keys {
			if key.IsKeyboard() {
				if C.nox_xxx_wndGetFocus_46B4F0() != nil || C.sub_46A4A0() != 0 || nox_input_map_byKey[key].state == 1 {
					break
				}
				if nox_input_map_byKey[key].field2 {
					break
				}
			} else if key.IsMouse() && memmap.Uint8(0x5D4594, 747848) != 2 {
				if key == keybind.KeyLeftMouse {
					btn := NOX_MOUSE_LEFT
					state := mouse.btn[btn].state
					if state != nox_mouse_state(btn, NOX_MOUSE_DOWN) && state != nox_mouse_state(btn, NOX_MOUSE_PRESSED) {
						break
					}
					if state == nox_mouse_state(btn, NOX_MOUSE_PRESSED) && it.events[0] == 1 {
						break
					}
				} else if key == keybind.KeyMiddleMouse {
					btn := NOX_MOUSE_MIDDLE
					state := mouse.btn[btn].state
					if state != nox_mouse_state(btn, NOX_MOUSE_DOWN) && state != nox_mouse_state(btn, NOX_MOUSE_PRESSED) {
						break
					}
					if state == nox_mouse_state(btn, NOX_MOUSE_PRESSED) && it.events[0] == 1 {
						break
					}
				} else if key == keybind.KeyRightMouse {
					btn := NOX_MOUSE_RIGHT
					state := mouse.btn[btn].state
					if state != nox_mouse_state(btn, NOX_MOUSE_DOWN) && state != nox_mouse_state(btn, NOX_MOUSE_PRESSED) {
						break
					}
					if state == nox_mouse_state(btn, NOX_MOUSE_PRESSED) && it.events[0] == 1 {
						break
					}
				} else if key == keybind.KeyMouseWheelUp {
					if mouse.wheel != 19 {
						break
					}
				} else if key == keybind.KeyMouseWheelDown {
					if mouse.wheel != 20 {
						break
					}
				}
			} else if key.IsJoystick() && (memmap.Uint8(0x5D4594, 750956) != 0 || (1<<uint32(key))&memmap.Uint32(0x5D4594, 747844) == 0) {
				break
			}
			li = i + 1
		}
		if li == len(it.keys) {
			it.field20 = res
			it.flag22 = true
			res = it
		}
	}
	return res
}

func loadRect(p unsafe.Pointer) types.Rect {
	rp := (*[4]int32)(p)
	return types.Rect{
		Left:   int(rp[0]),
		Top:    int(rp[1]),
		Right:  int(rp[2]),
		Bottom: int(rp[3]),
	}
}

func nox_xxx_cursorUpdate_46B740_sprites(v63 bool, v66 []int) {
	if gameGetPlayState() != 3 {
		return
	}
	if memmap.Uint32(0x5D4594, 1064940) != 0 {
		return
	}
	if C.nox_xxx_playerAnimCheck_4372B0() != 0 {
		return
	}
	if nox_xxx_checkGameFlagPause_413A50() {
		return
	}
	if nox_xxx_guiCursor_477600() {
		return
	}
	if C.nox_xxx_clientIsObserver_4372E0() != 0 {
		return
	}
	m := &nox_mouse
	v42 := int(C.sub_4675B0())
	if v42 == 5 {
		nox_client_setCursorType_477610(6)
		return
	}
	if v42 == 6 {
		nox_client_setCursorType_477610(8)
		return
	}
	sprite := nox_xxx_clientGetSpriteAtCursor_476F90()
	if sprite == nil {
		if C.sub_479590() == 2 {
			nox_client_setCursorType_477610(11)
		} else if C.sub_479590() == 3 {
			nox_client_setCursorType_477610(12)
		}
		return
	}
	var v65 types.Point
	if sprite.Flags28()&0x400006 == 0 || C.nox_xxx_sprite_4C3220(sprite.C()) != 0 || sprite.Flags28()&2 != 0 && sprite.Flags29()&8 != 0 || sprite.Flags28()&2 != 0 && sprite.Flags70()&0x10 != 0 {
		v46 := asWindow(C.dword_5d4594_1062452)
		for v47 := asWindow(C.nox_win_xxx1_last); v47 != nil; v47 = v47.Prev() {
			if v47.Flags().Has(0x10) {
				continue
			}
			if v47.pointIn(m.pos) {
				if v47 == v46 {
					v65 = m.pos
					v50 := loadRect(unsafe.Pointer(C.sub_4676B0()))
					if sub_4281F0(v65, v50) {
						v63 = true
						break
					}
					v52 := loadRect(unsafe.Pointer(C.sub_4676C0()))
					if sub_4281F0(v65, v52) {
						v63 = true
						break
					}
				}
				if v47 != nil && C.nox_xxx_wnd_46C2A0(v47.C()) != 1 {
					return
				}
				break
			}
		}

		v65 = nox_xxx_getSomeCoods_435670()
		sp := sprite.posMB()
		c1 := v65.X - sp.X
		c2 := v65.Y - sp.Y
		v54 := c1*c1 + c2*c2
		if sprite.Flags28()&0x80000000 == 0 || C.nox_xxx_cursorGetDraggedItem_477680() != 0 {
			if v54 < 125*125 {
				if p := *memmap.PtrPtr(0x5D4594, 2618908); p != nil {
					v57 := *(*uintptr)(unsafe.Pointer(uintptr(p) + 3680))
					if v57&0x200 == 0 && C.sub_478030() == 0 {
						if sprite.Flags28()&2 != 0 && sprite.Flags70()&0x10 != 0 {
							nox_client_setCursorType_477610(4)
						} else if sprite.Flags28()&2 != 0 && sprite.Flags29()&8 != 0 {
							nox_client_setCursorType_477610(3)
						}
					}
				}
			}
		} else {
			if v63 {
				v55 := C.nox_xxx_clientAskInfoMb_4BF050(sprite.C())
				C.nox_xxx_cursorSetTooltip_4776B0(v55)
			}
			if v54 >= 75*75 {
				nox_client_setCursorType_477610(15)
			} else {
				if noxflags.HasGame(6144) || C.sub_57B450(sprite.C()) != 0 {
					nox_client_setCursorType_477610(2)
				} else {
					nox_client_setCursorType_477610(16)
				}
				v56 := C.nox_client_mousePriKey_430AF0()
				if v66[v56] == int(C.nox_xxx_cursor_430B00()) {
					C.nox_xxx_clientPickup_46C140(sprite.C())
					v66[v56] = 0
				}
			}
		}
	} else {
		mimic := memmap.Uint32(0x5D4594, 1064944)
		if mimic == 0 {
			mimic = uint32(C.nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Mimic")))
			*memmap.PtrUint32(0x5D4594, 1064944) = mimic
		}
		if sprite.Flags28()&0x400000 != 0 && sprite.Flags29()&0x80 != 0 && sprite.Flags70()&0xC == 0 || uint32(sprite.field_27) == mimic && sprite.field_69 == 0 {
			v65 = nox_xxx_getSomeCoods_435670()
			sp := sprite.posMB()
			c1 := v65.X - sp.X
			c2 := v65.Y - sp.Y
			if c1*c1+c2*c2 < 75*75 && sprite.Flags30()&0x1000000 != 0 && sprite.Flags70()&0xC == 0 {
				nox_client_setCursorType_477610(13)
			}
		}
	}
}

func nox_xxx_cursorUpdate_46B740() {
	var v0 *Window
	var v1 *Window
	var v23 *Window
	var v61 *Window
	v63 := false
	v64 := 0

	m := &nox_mouse

	var v66 [4]int
	v66[0] = int(m.btn[NOX_MOUSE_LEFT].state)
	v66[1] = int(m.btn[NOX_MOUSE_RIGHT].state)
	v66[2] = int(m.btn[NOX_MOUSE_MIDDLE].state)
	v66[3] = m.wheel

	sx := uint16(m.pos.X)
	sy := uint16(m.pos.Y)
	spos := uintptr(uint32(sx) | (uint32(sy) << 16))
	spos2 := spos

	C.nox_xxx_cursorSetTooltip_4776B0(nil)
	if C.nox_client_gui_flag_815132 != 0 || nox_xxx_guiCursor_477600() {
		nox_client_setCursorType_477610(0)
	} else {
		nox_client_setCursorType_477610(14)
	}
	if nox_win_unk3 != nil {
		nox_client_setCursorType_477610(0)
		nox_win_1064916 = nil
		child := nox_win_unk3.ChildByPos(m.pos)
		v1 = child
		for v62, v9 := range v66 {
			if v9 == 0 {
				if v62 == 0 && m.btn[NOX_MOUSE_LEFT].pressed {
					child.Func93(8, spos2, 0)
				}
				continue
			}
			if child == nil {
				if nox_win_unk3.Func93(v9, spos2, 0) != 0 {
					v66[v62] = 0
				}
				continue
			}
			for v10 := child; v10 != nil; v10 = v10.Parent() {
				if v10.Func93(v9, spos2, 0) != 0 {
					v66[v62] = 0
					break
				}
				if v10 == nox_win_unk3 {
					break
				}
			}
		}
	} else if nox_win_1064916 != nil {
		nox_client_setCursorType_477610(0)
		switch v66[0] {
		case 0, 8:
			if nox_win_1064916.Flags().Has(4) && C.sub_45D9B0() == 0 {
				dp := m.dpos
				off := nox_win_1064916.Offs()
				end := nox_win_1064916.End()
				if par := nox_win_1064916.Parent(); par != nil {
					psz := par.Size()
					if off.X+dp.X >= 0 {
						if dp.X+end.X > psz.W {
							dp.X = psz.W - end.X
						}
						v1 = nil
					} else {
						dp.X = -off.X
					}
					if off.Y+dp.Y >= 0 {
						if dp.Y+end.Y > psz.H {
							dp.Y = psz.H - end.Y
						}
					} else {
						dp.Y = -off.Y
					}
				}
				off = off.Add(dp)
				if off.X < 0 {
					off.X = 0
				}
				if off.Y < 0 {
					off.Y = 0
				}
				nox_win_1064916.SetOffs(off)

				vsz := videoGetWindowSize()
				sz := nox_win_1064916.Size()
				end = off.Add(sz.Point())
				if end.X > vsz.W {
					end.X = vsz.W
				}
				if end.Y > vsz.H {
					end.Y = vsz.H
				}
				nox_win_1064916.SetEnd(end)
				nox_win_1064916.SetOffs(end.Sub(sz.Point()))
				spos = spos2
			}
			nox_win_1064916.Func93(8, spos, 0)
			v66[0] = 0
		case 6:
			nox_win_1064916.flags &= 0xFFFFFFFE
			if nox_win_1064916.ChildByPos(m.pos) != nil {
				nox_win_1064916.Func93(6, spos, 0)
			} else if nox_win_1064916.Flags().Has(4) {
				nox_win_1064916.Func93(6, spos, 0)
			}
			v64 = 1
			v66[0] = 0
		case 7:
			nox_win_1064916.Focus()
			nox_win_1064916.Func93(7, spos, 0)
			v64 = 1
			v66[0] = 0
		default:
			v66[0] = 0
		}
	} else {
		if C.nox_win_1064912 != nil {
			v23 = asWindow(C.nox_win_1064912.win).ChildByPos(m.pos)
			goto LABEL_98
		}
		for v24 := asWindow(C.nox_win_xxx1_last); v24 != nil; v24 = v24.Prev() {
			if !v24.Flags().Has(0x20) {
				continue
			}
			if v24.Flags().Has(0x10) {
				continue
			}
			if v24.pointIn(m.pos) {
				v28 := asWindow(C.sub_46B630(v24.C(), C.int(m.pos.X), C.int(m.pos.Y)))
				if v0 == nil && (v28.tooltip_func != nil || v28.DrawData().Tooltip() != "") {
					v0 = v28
				}
				if v24.Flags().Has(8) {
					v61 = v0
					v1 = v24.ChildByPos(m.pos)
					if v1 == nil {
						break
					}
					goto LABEL_99
				}
			}
		}
		for v29 := asWindow(C.nox_win_xxx1_last); v29 != nil; v29 = v29.Prev() {
			if v29.Flags().Has(0x70) {
				continue
			}
			if v29.pointIn(m.pos) {
				v32 := asWindow(C.sub_46B630(v29.C(), C.int(m.pos.X), C.int(m.pos.Y)))
				if v0 == nil && (v32.tooltip_func != nil || v32.DrawData().Tooltip() != "") {
					v0 = v32
				}
				if v29.Flags().Has(8) {
					v61 = v0
					v1 = v29.ChildByPos(m.pos)
					if v1 == nil {
						break
					}
					goto LABEL_99
				}
			}
		}
		for v1 = asWindow(C.nox_win_xxx1_last); v1 != nil; v1 = v1.Prev() {
			if !v1.Flags().Has(0x40) {
				continue
			}
			if v1.Flags().Has(0x10) {
				continue
			}
			if v1.pointIn(m.pos) {
				v36 := asWindow(C.sub_46B630(v1.C(), C.int(m.pos.X), C.int(m.pos.Y)))
				if v0 == nil && (v36.tooltip_func != nil || v36.DrawData().Tooltip() != "") {
					v0 = v36
				}
				if v1.Flags().Has(8) {
					break
				}
			}
		}
		v61 = v0
		v23 = v1.ChildByPos(m.pos)
	LABEL_98:
		v1 = v23
		if v23 == nil {
			goto LABEL_113
		}
	LABEL_99:
		v61 = v1
		if v1.Flags().Has(0x200) {
			v1 = nil
		} else if v1 != nil {
			nox_client_setCursorType_477610(0)
			for i, v39 := range v66 {
				if v39 == 0 {
					continue
				}
				win40 := v1
				// TODO: looks similar to Window.Focus, but doesn't check flags and uses different global
				if win40.Func93(v39, spos2, 0) != 0 {
					if i == 0 && v66[0] == 5 {
						nox_win_1064916 = win40
					}
					v66[i] = 0
				} else {
					for {
						win40 = win40.Parent()
						if win40 == nil {
							break
						}
						if win40.Func93(v39, spos2, 0) != 0 {
							if i == 0 && v66[0] == 5 {
								nox_win_1064916 = win40
							}
							v66[i] = 0
							break
						}
					}
				}
			}
			v0 = v61
		}
	LABEL_113:
		if v0 == nil && C.nox_xxx_wnd_46C2A0(v1.C()) != 0 {
			v0 = v1
		}
		if C.sub_430B30() != 0 {
			if v0 != nil {
				if v0.tooltip_func != nil {
					v0.TooltipFunc(spos2)
				} else if str := v0.DrawData().Tooltip(); str != "" {
					C.nox_xxx_cursorSetTooltip_4776B0(internWStr(str))
				}
			} else {
				v63 = true
			}
		}
	}
	if nox_win_1064916 == nil && v1 != nox_win_1064900 {
		if nox_win_unk3 != nil {
			if nox_win_unk3.IsChild(nox_win_1064900) {
				nox_win_1064900.Func93(18, spos2, 0)
			}
		} else if nox_win_1064900 != nil {
			nox_win_1064900.Func93(18, spos2, 0)
		}
		if v1 != nil {
			v1.Func93(17, spos2, 0)
		}
		nox_win_1064900 = v1
	}
	nox_xxx_cursorUpdate_46B740_sprites(v63, v66[:])
	m.btn[NOX_MOUSE_LEFT].state = uint(v66[0])
	m.btn[NOX_MOUSE_RIGHT].state = uint(v66[1])
	m.btn[NOX_MOUSE_MIDDLE].state = uint(v66[2])
	m.wheel = v66[3]
	if v64 == 1 {
		nox_win_1064916 = nil
	}
	sub_46C200()
}

//export nox_input_scanCodeToAlpha_47F950
func nox_input_scanCodeToAlpha_47F950(r C.ushort) C.ushort {
	return C.ushort(nox_input_scanCodeToAlpha(keybind.Key(r)))
}
func nox_input_scanCodeToAlpha(r keybind.Key) uint16 {
	if r > 0xFF {
		return uint16(r)
	}
	scrollLockStatus := inpHandler.KeyModState(input.KeyAltR) // TODO: why it uses RALT?
	if r == keybind.KeyLShift || r == keybind.KeyRShift {
		*memmap.PtrUint32(0x5D4594, 1193136) = uint32(bool2int(nox_input_map_byKey[r].state == 2))
		return 0
	}
	if r == keybind.KeyCaps {
		if nox_input_map_byKey[r].field2 {
			return 0
		}
		if nox_input_map_byKey[r].state == 2 {
			C.dword_5d4594_1193132 = 1 - C.dword_5d4594_1193132 // TODO: is it correct type-wise?
		}
		inputSetKey4309B0(r, true)
		return 0
	}
	// TODO: extract character tables; once it's done we could properly support UTF-8 input
	if r == keybind.Key(memmap.Uint8(0x5D4594, 1193144)) {
		*memmap.PtrUint32(0x5D4594, 1193140) = uint32(bool2int(nox_input_map_byKey[r].state == 2))
		return 0
	} else if memmap.Uint32(0x5D4594, 1193140) != 0 {
		return memmap.Uint16(0x5D4594, 1191576+6*uintptr(r))
	} else if memmap.Uint32(0x5D4594, 1193136) != 0 || C.dword_5d4594_1193132 != 0 && C.iswalpha(C.uint(memmap.Uint16(0x5D4594, 1191572+6*uintptr(r)))) != 0 {
		if scrollLockStatus {
			return uint16(asc_9800B0[3*int(r)+264])
		}
		return memmap.Uint16(0x5D4594, 1191574+6*uintptr(r))
	}
	if scrollLockStatus {
		return uint16(asc_9800B0[3*int(r)])
	}
	return memmap.Uint16(0x5D4594, 1191572+6*uintptr(r))
}

var asc_9800B0 = []byte{
	0, 0, 0, 0, 0, 0, 49, 33, 0, 50, 64, 0, 51, 35, 0, 52, 36, 0, 53, 37, 0, 54, 94,
	0, 55, 38, 0, 56, 42, 0, 57, 40, 0, 48, 41, 0, 45, 95, 0, 61, 43, 0, 8, 8, 0, 9,
	9, 0, 233, 201, 0, 246, 214, 0, 243, 211, 0, 234, 202, 0, 229, 197, 0, 237, 205, 0, 227, 195, 0,
	248, 216, 0, 249, 217, 0, 231, 199, 0, 245, 213, 0, 250, 218, 0, 10, 10, 0, 0, 0, 0, 244, 212,
	0, 251, 219, 0, 226, 194, 0, 224, 192, 0, 239, 207, 0, 240, 208, 0, 238, 206, 0, 235, 203, 0, 228,
	196, 0, 230, 198, 0, 253, 221, 0, 96, 126, 0, 0, 0, 0, 92, 124, 0, 255, 223, 0, 247, 215, 0,
	241, 209, 0, 236, 204, 0, 232, 200, 0, 242, 210, 0, 252, 220, 0, 225, 193, 0, 254, 222, 0, 47, 63,
	0, 0, 0, 0, 42, 42, 0, 0, 0, 0, 32, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 55, 55, 0, 56, 56, 0, 57, 57, 0, 45, 45, 0, 52, 52, 0, 53, 53,
	0, 54, 54, 0, 43, 43, 0, 49, 49, 0, 50, 50, 0, 51, 51, 0, 48, 48, 0, 46, 46, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49, 33, 0, 50, 64, 0, 51,
	35, 0, 52, 36, 0, 53, 37, 0, 54, 94, 0, 55, 38, 0, 56, 42, 0, 57, 40, 0, 48, 41, 0,
	45, 95, 0, 61, 43, 0, 8, 8, 0, 9, 9, 0, 233, 201, 0, 246, 214, 0, 243, 211, 0, 234, 202,
	0, 229, 197, 0, 237, 205, 0, 227, 195, 0, 248, 216, 0, 249, 217, 0, 231, 199, 0, 245, 213, 0, 250,
	218, 0, 10, 10, 0, 0, 0, 0, 244, 212, 0, 251, 219, 0, 226, 194, 0, 224, 192, 0, 239, 207, 0,
	240, 208, 0, 238, 206, 0, 235, 203, 0, 228, 196, 0, 230, 198, 0, 253, 221, 0, 96, 126, 0, 0, 0,
	0, 92, 124, 0, 255, 223, 0, 247, 215, 0, 241, 209, 0, 236, 204, 0, 232, 200, 0, 242, 210, 0, 252,
	220, 0, 225, 193, 0, 254, 222, 0, 47, 63, 0, 0, 0, 0, 42, 42, 0, 0, 0, 0, 32, 32, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55, 55, 0, 56, 56, 0, 57,
	57, 0, 45, 45, 0, 52, 52, 0, 53, 53, 0, 54, 54, 0, 43, 43, 0, 49, 49, 0, 50, 50, 0,
	51, 51, 0, 48, 48, 0, 46, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
}
