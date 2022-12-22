package opennox

/*
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2_2.h"
*/
import "C"
import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	"github.com/noxworld-dev/opennox-lib/noxfont"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/ccall"
)

const (
	guiDialogID           = 4000
	guiDialogOKID         = 4001
	guiDialogCancelID     = 4002
	guiDialogTextEntry1ID = 4003
	guiDialogTextEntry2ID = 4008
	guiDialogTextID       = 4004
	guiDialogTitleID      = 4005
	guiDialogNoID         = 4006
	guiDialogYesID        = 4007
	guiDialogDisconnectID = 4009
	guiDialogHelpID       = 4010
)

var (
	nox_gui_curDialog_830224 *Window
	dword_5d4594_830228      *Window
	dword_5d4594_830232      *Window
	dword_5d4594_830236      *Window
	func_5D4594_830220       func()
	func_5d4594_830216       func()
)

//export sub_44A4A0
func sub_44A4A0() C.int {
	return C.int(bool2int(nox_gui_curDialog_830224 != nil))
}

func sub44A4A0() bool {
	return nox_gui_curDialog_830224 != nil
}

//export nox_xxx_dialogMsgBoxCreate_449A10
func nox_xxx_dialogMsgBoxCreate_449A10(win *C.nox_window, title, text *C.wchar_t, a4 C.int, a5, a6 unsafe.Pointer) unsafe.Pointer {
	var fnc5, fnc6 func()
	if a5 != nil {
		fnc5 = func() {
			ccall.CallVoid(a5)
		}
	}
	if a6 != nil {
		fnc6 = func() {
			ccall.CallVoid(a6)
		}
	}
	NewDialogWindow(asWindow(win), GoWString(title), GoWString(text), gui.DialogFlags(a4), fnc5, fnc6)
	return nil
}

func (win *Window) NewDialogID(id strman.ID, file string) {
	str := strMan.GetStringInFile(id, file)
	NewDialogWindow(win, "", str, 0, nil, nil)
}

func NewDialogWindow(a1 *Window, title string, text string, flags gui.DialogFlags, a5, a6 func()) {
	if nox_gui_curDialog_830224 != nil && func_5d4594_830216 != nil {
		func_5d4594_830216()
	}
	dword_5d4594_830228 = a1
	dword_5d4594_830232 = nil
	func_5D4594_830220 = a5
	func_5d4594_830216 = a6
	if nox_gui_curDialog_830224 != nil {
		sub449EA0(flags)
		if title != "" {
			sub449E00(title)
		}
		if text != "" {
			sub449E30(text)
		}
		return
	}
	*memmap.PtrUint32(0x5D4594, 830240) = 0
	lang := strMan.Lang()
	if noxClient.r.FontHeight(nil) > 10 {
		lang = 2
	}
	wfile := "dlg.wnd"
	_ = lang
	// TODO: check array at 0x587000, 112976 + 4 * lang
	//if lang == xxx {
	//	wfile = "ldlg.wnd"
	//}
	dia := newWindowFromFile(wfile, nox_xxx_windowDlgProc_449CA0)
	nox_gui_curDialog_830224 = dia
	if dia == nil {
		return
	}
	dia.setFunc93(sub_449BE0)
	dia.ChildByID(guiDialogTextEntry1ID).setFunc93(sub_449C30)
	dia.ChildByID(guiDialogTextEntry2ID).setFunc93(sub_449C30)
	if title != "" {
		dia.ChildByID(guiDialogTitleID).Func94(&WindowEvent0x4001{Str: title, Val: -1})
	}
	if text != "" {
		dia.ChildByID(guiDialogTextID).Func94(&WindowEvent0x4001{Str: text, Val: -1})
	}
	sub46B120(dia, nil)
	nox_xxx_wndShowModalMB(dia)
	sub46C690(dia)
	vsz := videoGetWindowSize()
	sz := dia.Size()
	dia.SetPos(image.Pt((vsz.X-sz.X)/2, (vsz.Y-sz.Y)/2))
	sub449EA0(flags)
	prev := nox_xxx_wndGetCaptureMain()
	dword_5d4594_830236 = prev
	if prev != nil {
		nox_xxx_wndClearCaptureMain(prev)
	}
}

//export sub_449E00
func sub_449E00(a1 *wchar_t) C.int {
	return C.int(sub449E00(GoWString(a1)))
}

func sub449E00(a1 string) int {
	v1 := nox_gui_curDialog_830224.ChildByID(4005)
	return eventRespInt(v1.Func94(&WindowEvent0x4001{Str: a1, Val: -1}))
}

//export sub_449E30
func sub_449E30(a1 *wchar_t) C.int {
	return C.int(sub449E30(GoWString(a1)))
}

func sub449E30(a1 string) int {
	v1 := nox_gui_curDialog_830224.ChildByID(4004)
	return eventRespInt(v1.Func94(&WindowEvent0x4001{Str: a1, Val: -1}))
}

//export sub_449E60
func sub_449E60(a1 C.char) C.int {
	return C.int(eventRespInt(sub449E60(int8(a1))))
}

func sub449E60(a1 int8) WindowEventResp {
	var v1 *Window
	if a1 >= 0 {
		v1 = nox_gui_curDialog_830224.ChildByID(guiDialogTextEntry1ID)
	} else {
		v1 = nox_gui_curDialog_830224.ChildByID(guiDialogTextEntry2ID)
	}
	return v1.Func94(asWindowEvent(0x401d, 0, 0))
}

//export sub_449EA0
func sub_449EA0(a1 C.int) {
	sub449EA0(gui.DialogFlags(a1))
}

func sub449EA0(flags gui.DialogFlags) {
	dflags := flags ^ gui.DialogFlags(*memmap.PtrUint16(0x5D4594, 830240))
	if dflags.Has(gui.DialogOKButton) {
		nox_gui_curDialog_830224.ChildByID(guiDialogOKID).ToggleHidden()
	}
	if dflags.Has(gui.DialogCancelButton) {
		nox_gui_curDialog_830224.ChildByID(guiDialogCancelID).ToggleHidden()
	}
	if dflags.Has(gui.DialogDisconnectButton) {
		nox_gui_curDialog_830224.ChildByID(guiDialogDisconnectID).ToggleHidden()
	}
	if dflags.Has(gui.DialogHelpButton) {
		nox_gui_curDialog_830224.ChildByID(guiDialogHelpID).ToggleHidden()
	}
	if dflags.Has(gui.DialogYesButton) {
		nox_gui_curDialog_830224.ChildByID(guiDialogYesID).ToggleHidden()
	}
	if dflags.Has(gui.DialogNoButton) {
		nox_gui_curDialog_830224.ChildByID(guiDialogNoID).ToggleHidden()
	}
	if dflags.Has(gui.DialogTextEntry1) {
		nox_gui_curDialog_830224.ChildByID(guiDialogTextEntry1ID).ToggleHidden()
	}
	if dflags.Has(gui.DialogTextEntry2) {
		nox_gui_curDialog_830224.ChildByID(guiDialogTextEntry2ID).ToggleHidden()
	}
	if flags.Has(gui.DialogLockMouse) {
		off := nox_gui_curDialog_830224.Offs()
		end := nox_gui_curDialog_830224.End()
		noxClient.SetMouseBounds(image.Rect(off.X, off.Y, end.X, end.Y))
	} else {
		sz := videoGetWindowSize()
		noxClient.SetMouseBounds(image.Rect(0, 0, sz.X-1, sz.Y-1))
	}
	*memmap.PtrUint32(0x5D4594, 830240) = uint32(flags)
}

func nox_gui_dialogUnsetFlags_830224(a1 gui.DialogFlags) {
	if a1.Has(gui.DialogOKButton) {
		nox_gui_curDialog_830224.ChildByID(4001).Hide()
	}
	if a1.Has(gui.DialogCancelButton) {
		nox_gui_curDialog_830224.ChildByID(4002).Hide()
	}
	if a1.Has(gui.DialogDisconnectButton) {
		nox_gui_curDialog_830224.ChildByID(4009).Hide()
	}
	if a1.Has(gui.DialogHelpButton) {
		nox_gui_curDialog_830224.ChildByID(4010).Hide()
	}
	if a1.Has(gui.DialogYesButton) {
		nox_gui_curDialog_830224.ChildByID(4007).Hide()
	}
	if a1.Has(gui.DialogNoButton) {
		nox_gui_curDialog_830224.ChildByID(4006).Hide()
	}
	if a1.Has(gui.DialogTextEntry1) {
		nox_gui_curDialog_830224.ChildByID(4003).Hide()
	}
	if a1.Has(gui.DialogTextEntry2) {
		nox_gui_curDialog_830224.ChildByID(4008).Hide()
	}
	if a1.Has(gui.DialogLockMouse) {
		noxClient.SetMouseBounds(image.Rect(0, 0, nox_win_width-1, nox_win_height-1))
	}
	*memmap.PtrUint32(0x5D4594, 830240) &^= uint32(a1)
}

func sub_449BE0(win *Window, ev WindowEvent) WindowEventResp {
	switch ev := ev.(type) {
	default:
		return nil
	case WindowKeyPress:
		switch ev.Key {
		case keybind.KeyEsc:
			return RawEventResp(1)
		case keybind.KeySpace:
			mpos := noxClient.GetMousePos()
			win.Func93(&WindowMouseState{State: input.NOX_MOUSE_LEFT_DOWN, Pos: mpos})
		}
		return nil
	}
}

func sub_449C30(a1 *Window, ev WindowEvent) WindowEventResp {
	switch ev := ev.(type) {
	case WindowKeyPress:
		if ev.Key == keybind.KeyEnter {
			dia := nox_gui_curDialog_830224
			bok := dia.ChildByID(guiDialogOKID)
			if bok.Flags().IsEnabled() && !bok.Flags().IsHidden() {
				dia.Func94(&WindowEvent0x4007{Win: bok})
			}
		}
	}
	return nox_xxx_wndEditProc_487D70(a1, ev)
}

func nox_xxx_windowDlgProc_449CA0(a1 *Window, ev WindowEvent) WindowEventResp {
	switch ev := ev.(type) {
	default:
		return nil
	case WindowFocus:
		return RawEventResp(1)
	case *WindowEvent0x4007:
		switch ev.Win.ID() {
		case guiDialogOKID, guiDialogYesID: // OK or Yes
			if memmap.Uint8(0x5D4594, 830240)&0x20 != 0 {
				nox_xxx_wnd46C6E0(nox_gui_curDialog_830224)
			}
			dword_5d4594_830228.Func94(ev)
			if func_5D4594_830220 != nil {
				func_5D4594_830220()
			}
			if memmap.Uint8(0x5D4594, 830240)&0x20 == 0 {
				return nil
			}
			sub_44A400()
		case guiDialogCancelID, guiDialogNoID: // Cancel or No
			if memmap.Uint8(0x5D4594, 830240)&0x20 != 0 {
				nox_xxx_wnd46C6E0(nox_gui_curDialog_830224)
			}
			dword_5d4594_830228.Func94(ev)
			if func_5d4594_830216 != nil {
				func_5d4594_830216()
			}
			if memmap.Uint8(0x5D4594, 830240)&0x20 == 0 {
				return nil
			}
			sub_44A400()
		case guiDialogDisconnectID: // Disconnect
			sub_41E300(9)
			v5 := sub_41E2F0()
			C.sub_41DA70(C.int(v5), 8)
			nox_gui_dialogUnsetFlags_830224(gui.DialogDisconnectButton)
			sub_44A400()
		case guiDialogHelpID: // Help
			dword_5d4594_830228.Func94(ev)
		}
		return nil
	}
}

//export sub_44A4E0
func sub_44A4E0() C.int {
	if !sub44A4A0() {
		return 0
	}
	v0 := nox_gui_curDialog_830224.ChildByID(4002)
	nox_gui_curDialog_830224.Func94(&WindowEvent0x4007{Win: v0})
	return 1
}

//export sub_44A4B0
func sub_44A4B0() {
	if nox_gui_curDialog_830224 != nil {
		nox_xxx_wndShowModalMB(nox_gui_curDialog_830224)
	}
}

//export sub_44A360
func sub_44A360(a1 C.int) {
	name := noxfont.DefaultName
	if a1 == 1 {
		name = noxfont.LargeName
	}
	fnt := noxClient.r.Fonts.FontPtrByName(name)
	nox_gui_curDialog_830224.ChildByID(guiDialogTitleID).DrawData().SetFont(fnt)
	nox_gui_curDialog_830224.ChildByID(guiDialogTextID).DrawData().SetFont(fnt)
}
