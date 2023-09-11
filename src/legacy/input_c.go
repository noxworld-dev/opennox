package legacy

/*
#include "nox_wchar.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3_1.h"
#include "GAME5_2.h"
#include "client__io__win95__focus.h"
#include "client__system__parsecmd.h"
#include "input_common.h"
#include "MixPatch.h"
#include "client__gui__tooltip.h"
#include "client__gui__gamewin__gamewin.h"

static bool iswalpha_go(wchar2_t r) { return iswalpha(r); }
*/
import "C"
import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	InputSetKeyTimeoutLegacy                 func(key byte)
	InputKeyCheckTimeoutLegacy               func(key byte, dt uint32) bool
	Sub_416120                               func(key byte) bool
	Sub_416170                               func(key int) int
	Sub_416150                               func(key, ts int) int
	Nox_xxx_keybind_nameByTitle_42E960       func(title string) keybind.Key
	Nox_xxx_bindevent_bindNameByTitle_42EA40 func(title string) *keybind.BindEvent
	Sub_4C3B70                               func()
	Sub_4CBBF0                               func()
	Nox_input_reset_430140                   func(a1 int)
)

//export nox_xxx_setKeybTimeout_4160D0
func nox_xxx_setKeybTimeout_4160D0(key int) int {
	InputSetKeyTimeoutLegacy(byte(key))
	return key
}

//export nox_xxx_checkKeybTimeout_4160F0
func nox_xxx_checkKeybTimeout_4160F0(key C.uchar, dt C.uint) C.bool {
	return C.bool(InputKeyCheckTimeoutLegacy(byte(key), uint32(dt)))
}

//export sub_416120
func sub_416120(key C.uchar) C.bool { return C.bool(Sub_416120(byte(key))) }

//export sub_416170
func sub_416170(key int) int { return Sub_416170(key) }

//export sub_416150
func sub_416150(key, ts int) int { return Sub_416150(key, ts) }

//export nox_client_getMousePos_4309F0
func nox_client_getMousePos_4309F0() (out C.nox_point) {
	mpos := GetClient().GetMousePos()
	out.x = C.int(mpos.X)
	out.y = C.int(mpos.Y)
	return
}

//export nox_xxx_bookGet_430B40_get_mouse_prev_seq
func nox_xxx_bookGet_430B40_get_mouse_prev_seq() int {
	return int(GetClient().GetInputSeq())
}

//export nox_client_changeMousePos_430A00
func nox_client_changeMousePos_430A00(x, y int, isAbs C.bool) {
	GetClient().ChangeMousePos(image.Pt(x, y), bool(isAbs))
}

//export nox_xxx_setMouseBounds_430A70
func nox_xxx_setMouseBounds_430A70(xmin, xmax, ymin, ymax int) {
	GetClient().SetMouseBounds(image.Rect(xmin, ymin, xmax, ymax))
}

//export nox_input_pollEvents_4453A0
func nox_input_pollEvents_4453A0() int {
	// TODO
	//inpHandler.Tick()
	return 0
}

//export nox_input_setSensitivity
func nox_input_setSensitivity(v C.float) {
	GetClient().SetSensitivity(float32(v))
}

//export nox_input_enableTextEdit_5700CA
func nox_input_enableTextEdit_5700CA() {
	GetClient().SetTextInput(true)
}

//export nox_input_disableTextEdit_5700F6
func nox_input_disableTextEdit_5700F6() {
	GetClient().SetTextInput(false)
}

//export nox_input_getStringBuffer_57011C
func nox_input_getStringBuffer_57011C() *wchar2_t {
	p, _ := CWString(GetClient().GetTextEditBuf())
	return p
}

//export nox_input_freeStringBuffer_57011C
func nox_input_freeStringBuffer_57011C(p *wchar2_t) {
	StrFree(p)
}

//export nox_xxx_keybind_nameByTitle_42E960
func nox_xxx_keybind_nameByTitle_42E960(title *wchar2_t) *C.char {
	k := Nox_xxx_keybind_nameByTitle_42E960(GoWString(title))
	if k == 0 {
		return nil
	}
	return internCStr(k.String())
}

//export nox_xxx_keybind_titleByKey_42EA00
func nox_xxx_keybind_titleByKey_42EA00(key C.uint) *wchar2_t {
	k := keybind.Key(key)
	if !k.IsValid() {
		return internWStr("")
	}
	return internWStr(k.Title(GetClient().Strings()))
}

//export nox_xxx_keybind_titleByKeyZero_42EA00
func nox_xxx_keybind_titleByKeyZero_42EA00(key C.uint) *wchar2_t {
	k := keybind.Key(key)
	if !k.IsValid() {
		return nil
	}
	return internWStr(k.Title(GetClient().Strings()))
}

//export nox_xxx_bindevent_bindNameByTitle_42EA40
func nox_xxx_bindevent_bindNameByTitle_42EA40(title *wchar2_t) *C.char {
	b := Nox_xxx_bindevent_bindNameByTitle_42EA40(GoWString(title))
	if b == nil {
		return nil
	}
	return internCStr(b.Name)
}

//export sub_4C3B70
func sub_4C3B70() { Sub_4C3B70() }

//export sub_4CBBF0
func sub_4CBBF0() { Sub_4CBBF0() }

//export nox_input_reset_430140
func nox_input_reset_430140(a1 int) { Nox_input_reset_430140(a1) }

//export nox_input_scanCodeToAlpha_47F950
func nox_input_scanCodeToAlpha_47F950(r C.ushort) C.ushort {
	return C.ushort(GetClient().Cli().Inp.KeyToWChar(keybind.Key(r)))
}

func NoxInputOnChar(c uint16) {
	C.nox_xxx_onChar_488BD0(C.wchar2_t(c))
}
func Nox_xxx_clientIsObserver_4372E0() int {
	return int(C.nox_xxx_clientIsObserver_4372E0())
}
func Sub_4675B0() int {
	return int(C.sub_4675B0())
}
func Sub_479590() int {
	return int(C.sub_479590())
}
func Sub_478030() int {
	return int(C.sub_478030())
}
func Sub_47A260() int {
	return int(C.sub_47A260())
}
func Nox_xxx_cursor_430B00() int {
	return int(C.nox_xxx_cursor_430B00())
}
func Sub_45D9B0() int {
	return int(C.sub_45D9B0())
}
func Nox_xxx_sprite_4C3220(a1 *client.Drawable) int {
	return int(C.nox_xxx_sprite_4C3220((*nox_drawable)(a1.C())))
}
func Nox_xxx_wnd_46C2A0(a1 *gui.Window) int {
	return int(C.nox_xxx_wnd_46C2A0((*nox_window)(a1.C())))
}
func Nox_xxx_clientAskInfoMb_4BF050(a1 *client.Drawable) string {
	return GoWString(C.nox_xxx_clientAskInfoMb_4BF050((*nox_drawable)(a1.C())))
}
func Nox_xxx_cursorSetTooltip_4776B0(a1 string) {
	if a1 == "" {
		C.nox_xxx_cursorSetTooltip_4776B0(nil)
		return
	}
	wstr, free := CWString(a1)
	defer free()
	C.nox_xxx_cursorSetTooltip_4776B0(wstr)
}
func Sub_57B450(a1 *client.Drawable) int {
	return int(C.sub_57B450((*nox_drawable)(a1.C())))
}
func Nox_xxx_clientPickup_46C140(a1 *client.Drawable) {
	C.nox_xxx_clientPickup_46C140((*nox_drawable)(a1.C()))
}
func Sub_46B630(a1 *gui.Window, a2 int, a3 int) *gui.Window {
	return asWindow(C.sub_46B630((*nox_window)(a1.C()), C.int(a2), C.int(a3)))
}

func Get_nox_input_reset_430140() unsafe.Pointer {
	return C.nox_input_reset_430140
}
