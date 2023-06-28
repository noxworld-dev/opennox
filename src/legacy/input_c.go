package legacy

import (
	"image"

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

// nox_xxx_setKeybTimeout_4160D0
func nox_xxx_setKeybTimeout_4160D0(key int32) int32 {
	InputSetKeyTimeoutLegacy(byte(key))
	return key
}

// nox_xxx_checkKeybTimeout_4160F0
func nox_xxx_checkKeybTimeout_4160F0(key byte, dt uint32) bool {
	return InputKeyCheckTimeoutLegacy(key, dt)
}

// sub_416120
func sub_416120(key byte) bool { return Sub_416120(key) }

// sub_416170
func sub_416170(key int) int { return Sub_416170(key) }

// sub_416150
func sub_416150(key, ts int) int { return Sub_416150(key, ts) }

// nox_client_getMousePos_4309F0
func nox_client_getMousePos_4309F0() (out nox_point) {
	mpos := GetClient().GetMousePos()
	out.x = int32(mpos.X)
	out.y = int32(mpos.Y)
	return
}

// nox_xxx_bookGet_430B40_get_mouse_prev_seq
func nox_xxx_bookGet_430B40_get_mouse_prev_seq() int32 {
	return int32(GetClient().GetInputSeq())
}

// nox_client_changeMousePos_430A00
func nox_client_changeMousePos_430A00(x, y int32, isAbs bool) {
	GetClient().ChangeMousePos(image.Pt(int(x), int(y)), isAbs)
}

// nox_xxx_setMouseBounds_430A70
func nox_xxx_setMouseBounds_430A70(xmin, xmax, ymin, ymax int32) {
	GetClient().SetMouseBounds(image.Rect(int(xmin), int(ymin), int(xmax), int(ymax)))
}

// nox_input_pollEvents_4453A0
func nox_input_pollEvents_4453A0() int {
	// TODO
	//inpHandler.Tick()
	return 0
}

// nox_input_setSensitivity
func nox_input_setSensitivity(v float32) {
	GetClient().SetSensitivity(v)
}

// nox_input_enableTextEdit_5700CA
func nox_input_enableTextEdit_5700CA() {
	GetClient().SetTextInput(true)
}

// nox_input_disableTextEdit_5700F6
func nox_input_disableTextEdit_5700F6() {
	GetClient().SetTextInput(false)
}

// nox_input_getStringBuffer_57011C
func nox_input_getStringBuffer_57011C() *wchar2_t {
	p, _ := CWString(GetClient().GetTextEditBuf())
	return p
}

// nox_input_freeStringBuffer_57011C
func nox_input_freeStringBuffer_57011C(p *wchar2_t) {
	StrFree(p)
}

// nox_xxx_keybind_nameByTitle_42E960
func nox_xxx_keybind_nameByTitle_42E960(title *wchar2_t) *byte {
	k := Nox_xxx_keybind_nameByTitle_42E960(GoWString(title))
	if k == 0 {
		return nil
	}
	return internCStr(k.String())
}

// nox_xxx_keybind_titleByKey_42EA00
func nox_xxx_keybind_titleByKey_42EA00(key uint32) *wchar2_t {
	k := keybind.Key(key)
	if !k.IsValid() {
		return internWStr("")
	}
	return internWStr(k.Title(GetClient().Strings()))
}

// nox_xxx_keybind_titleByKeyZero_42EA00
func nox_xxx_keybind_titleByKeyZero_42EA00(key uint32) *wchar2_t {
	k := keybind.Key(key)
	if !k.IsValid() {
		return nil
	}
	return internWStr(k.Title(GetClient().Strings()))
}

// nox_xxx_bindevent_bindNameByTitle_42EA40
func nox_xxx_bindevent_bindNameByTitle_42EA40(title *wchar2_t) *byte {
	b := Nox_xxx_bindevent_bindNameByTitle_42EA40(GoWString(title))
	if b == nil {
		return nil
	}
	return internCStr(b.Name)
}

// sub_4C3B70
func sub_4C3B70() { Sub_4C3B70() }

// sub_4CBBF0
func sub_4CBBF0() { Sub_4CBBF0() }

// nox_input_scanCodeToAlpha_47F950
func nox_input_scanCodeToAlpha_47F950(r uint16) uint16 {
	return GetClient().Cli().Inp.KeyToWChar(keybind.Key(r))
}

func NoxInputOnChar(c uint16) {
	nox_xxx_onChar_488BD0(c)
}
func Nox_xxx_clientIsObserver_4372E0() int {
	return int(nox_xxx_clientIsObserver_4372E0())
}
func Sub_4675B0() int {
	return int(sub_4675B0())
}
func Sub_479590() int {
	return int(sub_479590())
}
func Sub_478030() int {
	return int(sub_478030())
}
func Nox_xxx_cursor_430B00() int {
	return int(nox_xxx_cursor_430B00())
}
func Sub_45D9B0() int {
	return int(sub_45D9B0())
}
func Nox_xxx_sprite_4C3220(a1 *client.Drawable) int {
	return int(nox_xxx_sprite_4C3220(a1))
}
func Nox_xxx_wnd_46C2A0(a1 *gui.Window) int {
	return int(nox_xxx_wnd_46C2A0(a1))
}
func Nox_xxx_clientAskInfoMb_4BF050(a1 *client.Drawable) string {
	return GoWString(nox_xxx_clientAskInfoMb_4BF050(a1))
}
func Nox_xxx_cursorSetTooltip_4776B0(a1 string) {
	if a1 == "" {
		nox_xxx_cursorSetTooltip_4776B0(nil)
		return
	}
	wstr, free := CWString(a1)
	defer free()
	nox_xxx_cursorSetTooltip_4776B0(wstr)
}
func Sub_57B450(a1 *client.Drawable) int {
	return int(sub_57B450(a1))
}
func Nox_xxx_clientPickup_46C140(a1 *client.Drawable) {
	nox_xxx_clientPickup_46C140(a1)
}
func Sub_46B630(a1 *gui.Window, a2 int, a3 int) *gui.Window {
	return sub_46B630(a1, int32(a2), int32(a3))
}
