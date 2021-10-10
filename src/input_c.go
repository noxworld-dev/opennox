package main

/*
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3_1.h"
#include "GAME5_2.h"
#include "client__io__win95__focus.h"
#include "common__config.h"
#include "client__system__parsecmd.h"
#include "input_common.h"
#include "win.h"
#include "MixPatch.h"
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
extern void* dword_5d4594_1096640;
extern void* nox_client_spriteUnderCursorXxx_1096644;

static bool iswalpha_go(wchar_t r) { return iswalpha(r); }
*/
import "C"
import (
	"image"
	"math"
	"sync"
	"unsafe"

	"nox/v1/client/input"
	"nox/v1/client/input/keybind"
	"nox/v1/client/seat"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/memmap"
	"nox/v1/common/types"
)

func nox_client_getCursorType_477620() int {
	return int(C.nox_client_mouseCursorType)
}

func nox_xxx_spriteGetMB_476F80() *Drawable {
	return asDrawable((*C.nox_drawable)(C.dword_5d4594_1096640))
}

func nox_xxx_clientGetSpriteAtCursor_476F90() *Drawable {
	return asDrawable((*C.nox_drawable)(C.nox_client_spriteUnderCursorXxx_1096644))
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
	mpos := getMousePos()
	out.x = C.int(mpos.X)
	out.y = C.int(mpos.Y)
	return
}

//export nox_xxx_bookGet_430B40_get_mouse_prev_seq
func nox_xxx_bookGet_430B40_get_mouse_prev_seq() C.int {
	return C.int(getInputSeq())
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
	// TODO
	//inpHandler.Tick()
	return 0
}

//export nox_input_pollEventsMovie
func nox_input_pollEventsMovie() C.int {
	panic("TODO")
}

//export nox_input_getSensitivity
func nox_input_getSensitivity() C.float {
	return C.float(getSensitivity())
}

//export nox_input_setSensitivity
func nox_input_setSensitivity(v C.float) {
	setSensitivity(float32(v))
}

//export acquireMouse_sub_47D8C0
func acquireMouse_sub_47D8C0() C.int {
	// TODO
	//inpHandler.AcquireMouse()
	return 0
}

//export unacquireMouse_sub_47D8B0
func unacquireMouse_sub_47D8B0() C.int {
	// TODO
	//inpHandler.UnacquireMouse()
	return 0
}

//export nox_input_enableTextEdit_5700CA
func nox_input_enableTextEdit_5700CA() {
	setTextInput(true)
}

//export nox_input_disableTextEdit_5700F6
func nox_input_disableTextEdit_5700F6() {
	setTextInput(false)
}

//export nox_input_getStringBuffer_57011C
func nox_input_getStringBuffer_57011C() *C.wchar_t {
	return CWString(getTextEditBuf())
}

//export nox_input_freeStringBuffer_57011C
func nox_input_freeStringBuffer_57011C(p *C.wchar_t) {
	WStrFree(p)
}

func noxInputOnChar(c uint16) {
	C.nox_xxx_onChar_488BD0(C.wchar_t(c))
}

func call_OnLibraryNotice_265(dv int) {
	C.OnLibraryNotice_265(0, 2, C.int(dv))
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
		if ev.Event == keybind.EventToggleQuitMenu {
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
		if ev.Event == keybind.EventToggleQuitMenu {
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

func nox_client_processInput_4308A0(h *input.Handler) {
	if noxflags.HasGame(noxflags.GameOnline) && !noxflags.HasGame(4096) && h.SeqDelay() > 2700 {
		if !noxflags.HasGame(1) {
			C.nox_xxx_netServerCmd_440950(0, (*C.wchar_t)(memmap.PtrOff(0x587000, 80784)))
			return
		}
		if memmap.Uint32(0x8531A0, 2576) != 0 {
			C.nox_xxx_serverHandleClientConsole_443E90((*C.nox_playerInfo)(*memmap.PtrPtr(0x8531A0, 2576)), 0, (*C.wchar_t)(memmap.PtrOff(0x587000, 80792)))
		}
	}
}

//export nox_input_reset_430140
func nox_input_reset_430140(a1 C.int) {
	resetInput()
}

func nox_xxx_freeKeyboard_430210() {
	*memmap.PtrUint32(0x5D4594, 805808) = 0
}

func get_obj_5D4594_754104_switch() bool {
	return C.obj_5D4594_754104_switch != 0
}

func nox_xxx_initKeyboard_47FB10() {
	// On non-IME languages, Nox uses this input for text input. This sets up
	// current SHIFT state and the mapping from DIK code => wide character.
	C.dword_5d4594_1193132 = C.uint(bool2int(keymodShift()))
	nox_xxx_keyboard_47DBD0()
}

func nox_xxx_initInput_430190() error {
	nox_xxx_initKeyboard_47FB10()
	inputInitMouse()
	C.sub_42EBB0(2, (*[0]byte)(C.nox_input_reset_430140), 0, internCStr("Input"))
	return nil
}

//export sub_4309B0
func sub_4309B0(i, v C.uchar) {
	setKeyFlag(keybind.Key(i), v != 0)
}

func (c *CtrlEventHandler) nox_xxx_input_42D220(inp *input.Handler) {
	first := c.nox_xxx_input_42D220_A(inp)
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
	c.nox_xxx_clientControl_42D6B0(inp.GetMousePos(), res)
	c.writeToNetBuffer()
}

func (c *CtrlEventHandler) nox_xxx_input_42D220_A(inp *input.Handler) *CtrlEventBinding {
	var res *CtrlEventBinding
	for it := c.bindings; it != nil; it = it.next {
		li := -1
		for i, key := range it.keys {
			if key.IsKeyboard() {
				if C.nox_xxx_wndGetFocus_46B4F0() != nil || C.sub_46A4A0() != 0 {
					break
				}
				if inp.IsReleased(key) {
					break
				}
			} else if key.IsMouse() && memmap.Uint8(0x5D4594, 747848) != 2 {
				if inp.MouseAction(key, it.events[0]) {
					break
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

func nox_xxx_cursorUpdate_46B740_sprites(inp *input.Handler, v63 bool, v66 []int) {
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
		for v47 := nox_win_xxx1_last; v47 != nil; v47 = v47.Prev() {
			if v47.Flags().Has(0x10) {
				continue
			}
			mpos := inp.GetMousePos()
			if v47.pointIn(mpos) {
				if v47 == v46 {
					v65 = mpos
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
		sp := sprite.Pos()
		c1 := v65.X - sp.X
		c2 := v65.Y - sp.Y
		v54 := c1*c1 + c2*c2
		if sprite.Flags28()&0x80000000 == 0 || C.nox_xxx_cursorGetDraggedItem_477680() != nil {
			if v54 < 125*125 {
				if p := *memmap.PtrPtr(0x8531A0, 2576); p != nil {
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
			sp := sprite.Pos()
			c1 := v65.X - sp.X
			c2 := v65.Y - sp.Y
			if c1*c1+c2*c2 < 75*75 && sprite.Flags30()&0x1000000 != 0 && sprite.Flags70()&0xC == 0 {
				nox_client_setCursorType_477610(13)
			}
		}
	}
}

func nox_xxx_cursorUpdate_46B740(inp *input.Handler) {
	var v0 *Window
	var v1 *Window
	var v23 *Window
	var v61 *Window
	v63 := false
	v64 := 0

	var v66 [4]int
	v66[0] = int(inp.GetMouseState(seat.MouseButtonLeft))
	v66[1] = int(inp.GetMouseState(seat.MouseButtonRight))
	v66[2] = int(inp.GetMouseState(seat.MouseButtonMiddle))
	v66[3] = inp.GetMouseWheel()

	mpos := inp.GetMousePos()
	sx := uint16(mpos.X)
	sy := uint16(mpos.Y)
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
		child := nox_win_unk3.ChildByPos(mpos)
		v1 = child
		for v62, v9 := range v66 {
			if v9 == 0 {
				if v62 == 0 && inp.IsMousePressed(seat.MouseButtonLeft) {
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
				dp := inp.GetMouseRel()
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
			if nox_win_1064916.ChildByPos(mpos) != nil {
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
			v23 = asWindow(C.nox_win_1064912.win).ChildByPos(mpos)
			goto LABEL_98
		}
		for v24 := nox_win_xxx1_last; v24 != nil; v24 = v24.Prev() {
			if !v24.Flags().Has(0x20) {
				continue
			}
			if v24.Flags().Has(0x10) {
				continue
			}
			if v24.pointIn(mpos) {
				v28 := asWindow(C.sub_46B630(v24.C(), C.int(mpos.X), C.int(mpos.Y)))
				if v0 == nil && (v28.tooltip_func != nil || v28.DrawData().Tooltip() != "") {
					v0 = v28
				}
				if v24.Flags().Has(8) {
					v61 = v0
					v1 = v24.ChildByPos(mpos)
					if v1 == nil {
						break
					}
					goto LABEL_99
				}
			}
		}
		for v29 := nox_win_xxx1_last; v29 != nil; v29 = v29.Prev() {
			if v29.Flags().Has(0x70) {
				continue
			}
			if v29.pointIn(mpos) {
				v32 := asWindow(C.sub_46B630(v29.C(), C.int(mpos.X), C.int(mpos.Y)))
				if v0 == nil && (v32.tooltip_func != nil || v32.DrawData().Tooltip() != "") {
					v0 = v32
				}
				if v29.Flags().Has(8) {
					v61 = v0
					v1 = v29.ChildByPos(mpos)
					if v1 == nil {
						break
					}
					goto LABEL_99
				}
			}
		}
		for v1 = nox_win_xxx1_last; v1 != nil; v1 = v1.Prev() {
			if !v1.Flags().Has(0x40) {
				continue
			}
			if v1.Flags().Has(0x10) {
				continue
			}
			if v1.pointIn(mpos) {
				v36 := asWindow(C.sub_46B630(v1.C(), C.int(mpos.X), C.int(mpos.Y)))
				if v0 == nil && (v36.tooltip_func != nil || v36.DrawData().Tooltip() != "") {
					v0 = v36
				}
				if v1.Flags().Has(8) {
					break
				}
			}
		}
		v61 = v0
		v23 = v1.ChildByPos(mpos)
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
		if inp.GetDistSlow() {
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
	if nox_win_1064916 == nil && v1 != nox_win_activeWindow_1064900 {
		if nox_win_unk3 != nil {
			if nox_win_unk3.IsChild(nox_win_activeWindow_1064900) {
				nox_win_activeWindow_1064900.Func93(18, spos2, 0)
			}
		} else if nox_win_activeWindow_1064900 != nil {
			nox_win_activeWindow_1064900.Func93(18, spos2, 0)
		}
		if v1 != nil {
			v1.Func93(17, spos2, 0)
		}
		nox_win_activeWindow_1064900 = v1
	}
	nox_xxx_cursorUpdate_46B740_sprites(inp, v63, v66[:])
	inp.SetMouseState(seat.MouseButtonLeft, uint(v66[0]))
	inp.SetMouseState(seat.MouseButtonRight, uint(v66[1]))
	inp.SetMouseState(seat.MouseButtonMiddle, uint(v66[2]))
	inp.SetMouseWheel(v66[3])
	if v64 == 1 {
		nox_win_1064916 = nil
	}
	sub_46C200()
}

//export nox_input_scanCodeToAlpha_47F950
func nox_input_scanCodeToAlpha_47F950(r C.ushort) C.ushort {
	return C.ushort(nox_input_scanCodeToAlpha(inpHandlerS, keybind.Key(r)))
}

type inputCharMap struct {
	lower string
	upper string
	ext   string
}

var (
	dword_5d4594_1193136 bool
	dword_5d4594_1193140 bool
	noxInputMap          map[keybind.Key]inputCharMap
)

func str2u16(s string) uint16 {
	if s == "" {
		return 0
	}
	b := []byte(s)
	if len(b) == 1 {
		return uint16(b[0])
	}
	return uint16(b[0]) | uint16(b[1])<<8
}

func nox_input_scanCodeToAlpha(inp *input.Handler, r keybind.Key) uint16 {
	if r > 0xFF {
		return uint16(r)
	}
	scrollLockStatus := inp.KeyModAlt() // TODO: why it uses RALT?
	if r == keybind.KeyLShift || r == keybind.KeyRShift {
		dword_5d4594_1193136 = inp.IsPressed(r)
		return 0
	}
	if r == keybind.KeyCaps {
		if !inp.GetKeyFlag(r) {
			if inp.IsPressed(r) {
				C.dword_5d4594_1193132 = 1 - C.dword_5d4594_1193132 // TODO: is it correct type-wise?
			}
			inp.SetKeyFlag(r, true)
		}
		return 0
	}
	// TODO: extract character tables; once it's done we could properly support UTF-8 input
	if r == keybind.Key(memmap.Uint8(0x5D4594, 1193144)) {
		dword_5d4594_1193140 = inp.IsPressed(r)
		return 0
	}
	if dword_5d4594_1193140 {
		return str2u16(noxInputMap[r].ext)
	}
	if dword_5d4594_1193136 || C.dword_5d4594_1193132 != 0 && C.iswalpha_go(C.wchar_t(str2u16(noxInputMap[r].lower))) {
		if scrollLockStatus {
			return uint16(asc_9800B0[3*int(r)+264])
		}
		return str2u16(noxInputMap[r].upper)
	}
	if scrollLockStatus {
		return uint16(asc_9800B0[3*int(r)])
	}
	return str2u16(noxInputMap[r].lower)
}

func nox_xxx_keyboard_47DBD0() {
	noxInputMap = make(map[keybind.Key]inputCharMap, 256)
	for k, v := range noxInputMapGeneric {
		noxInputMap[k] = v
	}
	*memmap.PtrUint8(0x5D4594, 1193144) = 0
	var m map[keybind.Key]inputCharMap
	switch strMan.Lang() {
	case 0, 4, 6, 7, 8, 9:
		m = noxInputMapLang0
	case 1:
		m = noxInputMapLang1
		*memmap.PtrInt8(0x5D4594, 1193144) = -72
	case 2:
		m = noxInputMapLang2
		*memmap.PtrInt8(0x5D4594, 1193144) = -72
	case 3:
		m = noxInputMapLang3
		*memmap.PtrInt8(0x5D4594, 1193144) = -72
	case 5:
		m = noxInputMapLang5
		*memmap.PtrInt8(0x5D4594, 1193144) = -72
	}
	for k, v := range m {
		noxInputMap[k] = v
	}
}

var (
	noxInputMapGeneric = map[keybind.Key]inputCharMap{
		0xe:  {lower: "\b", upper: "\b"},
		0xf:  {lower: "\t", upper: "\t"},
		0x1c: {lower: "\n", upper: "\n"},
		0x39: {lower: " ", upper: " "},
		0x52: {lower: "0", upper: "0"},
		0x4f: {lower: "1", upper: "1"},
		0x50: {lower: "2", upper: "2"},
		0x51: {lower: "3", upper: "3"},
		0x4b: {lower: "4", upper: "4"},
		0x4c: {lower: "5", upper: "5"},
		0x4d: {lower: "6", upper: "6"},
		0x47: {lower: "7", upper: "7"},
		0x48: {lower: "8", upper: "8"},
		0x49: {lower: "9", upper: "9"},
		0xd3: {lower: "\b", upper: "\b"},
	}
	noxInputMapLang0 = map[keybind.Key]inputCharMap{
		0x2:  {lower: "1", upper: "!"},
		0x3:  {lower: "2", upper: "@"},
		0x4:  {lower: "3", upper: "#"},
		0x5:  {lower: "4", upper: "$"},
		0x6:  {lower: "5", upper: "%"},
		0x7:  {lower: "6", upper: "^"},
		0x8:  {lower: "7", upper: "&"},
		0x9:  {lower: "8", upper: "*"},
		0xa:  {lower: "9", upper: "("},
		0xb:  {lower: "0", upper: ")"},
		0xc:  {lower: "-", upper: "_"},
		0xd:  {lower: "=", upper: "+"},
		0x10: {lower: "q", upper: "Q"},
		0x11: {lower: "w", upper: "W"},
		0x12: {lower: "e", upper: "E"},
		0x13: {lower: "r", upper: "R"},
		0x14: {lower: "t", upper: "T"},
		0x15: {lower: "y", upper: "Y"},
		0x16: {lower: "u", upper: "U"},
		0x17: {lower: "i", upper: "I"},
		0x18: {lower: "o", upper: "O"},
		0x19: {lower: "p", upper: "P"},
		0x1a: {lower: "[", upper: "{"},
		0x1b: {lower: "]", upper: "}"},
		0x1e: {lower: "a", upper: "A"},
		0x1f: {lower: "s", upper: "S"},
		0x20: {lower: "d", upper: "D"},
		0x21: {lower: "f", upper: "F"},
		0x22: {lower: "g", upper: "G"},
		0x23: {lower: "h", upper: "H"},
		0x24: {lower: "j", upper: "J"},
		0x25: {lower: "k", upper: "K"},
		0x26: {lower: "l", upper: "L"},
		0x27: {lower: ";", upper: ":"},
		0x28: {lower: "'", upper: "\""},
		0x29: {lower: "`", upper: "~"},
		0x2b: {lower: "\\", upper: "|"},
		0x2c: {lower: "z", upper: "Z"},
		0x2d: {lower: "x", upper: "X"},
		0x2e: {lower: "c", upper: "C"},
		0x2f: {lower: "v", upper: "V"},
		0x30: {lower: "b", upper: "B"},
		0x31: {lower: "n", upper: "N"},
		0x32: {lower: "m", upper: "M"},
		0x33: {lower: ",", upper: "<"},
		0x34: {lower: ".", upper: ">"},
		0x35: {lower: "/", upper: "?"},
		0x37: {lower: "*", upper: "*"},
		0x4a: {lower: "-", upper: "-"},
		0x4e: {lower: "+", upper: "+"},
		0x53: {lower: ".", upper: "."},
		0x9c: {lower: "\n", upper: "\n"},
		0xb5: {lower: "/", upper: "/"},
	}
	noxInputMapLang1 = map[keybind.Key]inputCharMap{
		0x2:  {lower: "1", upper: "!"},
		0x3:  {lower: "2", upper: "\""},
		0x4:  {lower: "3", upper: "\xa3"},
		0x5:  {lower: "4", upper: "$", ext: "\xac "},
		0x6:  {lower: "5", upper: "%"},
		0x7:  {lower: "6", upper: "^"},
		0x8:  {lower: "7", upper: "&"},
		0x9:  {lower: "8", upper: "*"},
		0xa:  {lower: "9", upper: "("},
		0xb:  {lower: "0", upper: ")"},
		0xc:  {lower: "-", upper: "_"},
		0xd:  {lower: "=", upper: "+"},
		0x10: {lower: "q", upper: "Q"},
		0x11: {lower: "w", upper: "W"},
		0x12: {lower: "e", upper: "E"},
		0x13: {lower: "r", upper: "R"},
		0x14: {lower: "t", upper: "T"},
		0x15: {lower: "y", upper: "Y"},
		0x16: {lower: "u", upper: "U"},
		0x17: {lower: "i", upper: "I"},
		0x18: {lower: "o", upper: "O"},
		0x19: {lower: "p", upper: "P"},
		0x1a: {lower: "[", upper: "{"},
		0x1b: {lower: "]", upper: "}"},
		0x1e: {lower: "a", upper: "A"},
		0x1f: {lower: "s", upper: "S"},
		0x20: {lower: "d", upper: "D"},
		0x21: {lower: "f", upper: "F"},
		0x22: {lower: "g", upper: "G"},
		0x23: {lower: "h", upper: "H"},
		0x24: {lower: "j", upper: "J"},
		0x25: {lower: "k", upper: "K"},
		0x26: {lower: "l", upper: "L"},
		0x27: {lower: ";", upper: ":"},
		0x28: {lower: "'", upper: "@"},
		0x29: {lower: "`", upper: "\xac", ext: "\xa6"},
		0x2b: {lower: "#", upper: "~"},
		0x2c: {lower: "z", upper: "Z"},
		0x2d: {lower: "x", upper: "X"},
		0x2e: {lower: "c", upper: "C"},
		0x2f: {lower: "v", upper: "V"},
		0x30: {lower: "b", upper: "B"},
		0x31: {lower: "n", upper: "N"},
		0x32: {lower: "m", upper: "M"},
		0x33: {lower: ",", upper: "<"},
		0x34: {lower: ".", upper: ">"},
		0x35: {lower: "/", upper: "?"},
		0x37: {lower: "*", upper: "*"},
		0x4a: {lower: "-", upper: "-"},
		0x4e: {lower: "+", upper: "+"},
		0x53: {lower: ".", upper: "."},
		0x56: {lower: "\\", upper: "|"},
		0x9c: {lower: "\n", upper: "\n"},
		0xb5: {lower: "/", upper: "/"},
	}
	noxInputMapLang2 = map[keybind.Key]inputCharMap{
		0x2:  {lower: "1", upper: "!"},
		0x3:  {lower: "2", upper: "\"", ext: "\xb2"},
		0x4:  {lower: "3", upper: "\xa7", ext: "\xb3"},
		0x5:  {lower: "4", upper: "$"},
		0x6:  {lower: "5", upper: "%"},
		0x7:  {lower: "6", upper: "&"},
		0x8:  {lower: "7", upper: "/", ext: "{"},
		0x9:  {lower: "8", upper: "(", ext: "["},
		0xa:  {lower: "9", upper: ")", ext: "]"},
		0xb:  {lower: "0", upper: "=", ext: "}"},
		0xc:  {lower: "\xdf", upper: "?", ext: "\\"},
		0xd:  {lower: "\xb4", upper: "`"},
		0x10: {lower: "q", upper: "Q", ext: "@"},
		0x11: {lower: "w", upper: "W"},
		0x12: {lower: "e", upper: "E"},
		0x13: {lower: "r", upper: "R"},
		0x14: {lower: "t", upper: "T"},
		0x15: {lower: "z", upper: "Z"},
		0x16: {lower: "u", upper: "U"},
		0x17: {lower: "i", upper: "I"},
		0x18: {lower: "o", upper: "O"},
		0x19: {lower: "p", upper: "P"},
		0x1a: {lower: "\xfc", upper: "\xdc"},
		0x1b: {lower: "+", upper: "*", ext: "~"},
		0x1e: {lower: "a", upper: "A"},
		0x1f: {lower: "s", upper: "S"},
		0x20: {lower: "d", upper: "D"},
		0x21: {lower: "f", upper: "F"},
		0x22: {lower: "g", upper: "G"},
		0x23: {lower: "h", upper: "H"},
		0x24: {lower: "j", upper: "J"},
		0x25: {lower: "k", upper: "K"},
		0x26: {lower: "l", upper: "L"},
		0x27: {lower: "\xf6", upper: "\xd6"},
		0x28: {lower: "\xe4", upper: "\xc4"},
		0x29: {lower: "^", upper: "\xb0"},
		0x2b: {lower: "#", upper: "'"},
		0x2c: {lower: "y", upper: "Y"},
		0x2d: {lower: "x", upper: "X"},
		0x2e: {lower: "c", upper: "C"},
		0x2f: {lower: "v", upper: "V"},
		0x30: {lower: "b", upper: "B"},
		0x31: {lower: "n", upper: "N"},
		0x32: {lower: "m", upper: "M", ext: "\xb5"},
		0x33: {lower: ",", upper: ";"},
		0x34: {lower: ".", upper: ":"},
		0x35: {lower: "-", upper: "_"},
		0x37: {lower: "*", upper: "*"},
		0x4a: {lower: "-", upper: "-"},
		0x4e: {lower: "+", upper: "+"},
		0x53: {lower: ",", upper: ","},
		0x56: {lower: "<", upper: ">", ext: "|"},
		0x9c: {lower: "\n", upper: "\n"},
		0xb5: {lower: "/", upper: "/"},
	}
	noxInputMapLang3 = map[keybind.Key]inputCharMap{
		0x2:  {lower: "&", upper: "1"},
		0x3:  {lower: "\xe9", upper: "2", ext: "~"},
		0x4:  {lower: "\"", upper: "3", ext: "#"},
		0x5:  {lower: "'", upper: "4", ext: "{"},
		0x6:  {lower: "(", upper: "5", ext: "["},
		0x7:  {lower: "-", upper: "6", ext: "|"},
		0x8:  {lower: "\xe8", upper: "7", ext: "`"},
		0x9:  {lower: "_", upper: "8", ext: "\\"},
		0xa:  {lower: "\xe7", upper: "9"},
		0xb:  {lower: "\xe0", upper: "0", ext: "@"},
		0xc:  {lower: ")", upper: "\xb0", ext: "]"},
		0xd:  {lower: "=", upper: "+", ext: "}"},
		0x10: {lower: "a", upper: "A"},
		0x11: {lower: "z", upper: "Z"},
		0x12: {lower: "e", upper: "E"},
		0x13: {lower: "r", upper: "R"},
		0x14: {lower: "t", upper: "T"},
		0x15: {lower: "y", upper: "Y"},
		0x16: {lower: "u", upper: "U"},
		0x17: {lower: "i", upper: "I"},
		0x18: {lower: "o", upper: "O"},
		0x19: {lower: "p", upper: "P"},
		0x1a: {lower: "^", upper: "\xa8"},
		0x1b: {lower: "$", upper: "\xa3", ext: "\xa4"},
		0x1e: {lower: "q", upper: "Q"},
		0x1f: {lower: "s", upper: "S"},
		0x20: {lower: "d", upper: "D"},
		0x21: {lower: "f", upper: "F"},
		0x22: {lower: "g", upper: "G"},
		0x23: {lower: "h", upper: "H"},
		0x24: {lower: "j", upper: "J"},
		0x25: {lower: "k", upper: "K"},
		0x26: {lower: "l", upper: "L"},
		0x27: {lower: "m", upper: "M"},
		0x28: {lower: "\xf9", upper: "%"},
		0x29: {lower: "\xb2", upper: ""},
		0x2b: {lower: "*", upper: "\xb5"},
		0x2c: {lower: "w", upper: "W"},
		0x2d: {lower: "x", upper: "X"},
		0x2e: {lower: "c", upper: "C"},
		0x2f: {lower: "v", upper: "V"},
		0x30: {lower: "b", upper: "B"},
		0x31: {lower: "n", upper: "N"},
		0x32: {lower: ",", upper: "?"},
		0x33: {lower: ";", upper: "."},
		0x34: {lower: ":", upper: "/"},
		0x35: {lower: "!", upper: "\xa7"},
		0x37: {lower: "*", upper: "*"},
		0x4a: {lower: "-", upper: "-"},
		0x4e: {lower: "+", upper: "+"},
		0x53: {lower: ".", upper: "."},
		0x56: {lower: "<", upper: ">"},
		0x9c: {lower: "\n", upper: "\n"},
		0xb5: {lower: "/", upper: "/"},
	}
	noxInputMapLang5 = map[keybind.Key]inputCharMap{
		0x2:  {lower: "1", upper: "!"},
		0x3:  {lower: "2", upper: "\""},
		0x4:  {lower: "3", upper: "\xa3"},
		0x5:  {lower: "4", upper: "$"},
		0x6:  {lower: "5", upper: "%"},
		0x7:  {lower: "6", upper: "&"},
		0x8:  {lower: "7", upper: "/"},
		0x9:  {lower: "8", upper: "("},
		0xa:  {lower: "9", upper: ")"},
		0xb:  {lower: "0", upper: "="},
		0xc:  {lower: "'", upper: "?"},
		0xd:  {lower: "\xec", upper: "^"},
		0x10: {lower: "q", upper: "Q"},
		0x11: {lower: "w", upper: "W"},
		0x12: {lower: "e", upper: "E"},
		0x13: {lower: "r", upper: "R"},
		0x14: {lower: "t", upper: "T"},
		0x15: {lower: "y", upper: "Y"},
		0x16: {lower: "u", upper: "U"},
		0x17: {lower: "i", upper: "I"},
		0x18: {lower: "o", upper: "O"},
		0x19: {lower: "p", upper: "P"},
		0x1a: {lower: "\xe8", upper: "\xe9", ext: "["},
		0x1b: {lower: "+", upper: "*", ext: "]"},
		0x1e: {lower: "a", upper: "A"},
		0x1f: {lower: "s", upper: "S"},
		0x20: {lower: "d", upper: "D"},
		0x21: {lower: "f", upper: "F"},
		0x22: {lower: "g", upper: "G"},
		0x23: {lower: "h", upper: "H"},
		0x24: {lower: "j", upper: "J"},
		0x25: {lower: "k", upper: "K"},
		0x26: {lower: "l", upper: "L"},
		0x27: {lower: "\xf2", upper: "\xe7", ext: "@"},
		0x28: {lower: "\xe0", upper: "\xb0", ext: "#"},
		0x29: {lower: "\\", upper: "|"},
		0x2b: {lower: "\xf9", upper: "\xa7"},
		0x2c: {lower: "z", upper: "Z"},
		0x2d: {lower: "x", upper: "X"},
		0x2e: {lower: "c", upper: "C"},
		0x2f: {lower: "v", upper: "V"},
		0x30: {lower: "b", upper: "B"},
		0x31: {lower: "n", upper: "N"},
		0x32: {lower: "m", upper: "M"},
		0x33: {lower: ",", upper: ";"},
		0x34: {lower: ".", upper: ":"},
		0x35: {lower: "-", upper: "_"},
		0x37: {lower: "*", upper: "*"},
		0x4a: {lower: "-", upper: "-"},
		0x4e: {lower: "+", upper: "+"},
		0x53: {lower: ".", upper: "."},
		0x56: {lower: "<", upper: ">"},
		0x9c: {lower: "\n", upper: "\n"},
		0xb5: {lower: "/", upper: "/"},
	}
)

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
