package opennox

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	"github.com/noxworld-dev/opennox-lib/noxfont"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
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
	nox_gui_curDialog_830224 *gui.Window
	dword_5d4594_830228      *gui.Window
	dword_5d4594_830232      *gui.Window
	dword_5d4594_830236      *gui.Window
	func_5D4594_830220       func()
	func_5d4594_830216       func()
)

func sub_44A4A0() int {
	return bool2int(nox_gui_curDialog_830224 != nil)
}

func sub44A4A0() bool {
	return nox_gui_curDialog_830224 != nil
}

func winNewDialogID(win *gui.Window, id strman.ID, file string) {
	str := strMan.GetStringInFile(id, file)
	NewDialogWindow(win, "", str, 0, nil, nil)
}

func NewDialogWindow(a1 *gui.Window, title string, text string, flags gui.DialogFlags, a5, a6 func()) {
	g := a1.GUI()
	if g == nil {
		g = noxClient.GUI
	}
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
	if g.Render().FontHeight(nil) > 10 {
		lang = 2
	}
	wfile := "dlg.wnd"
	_ = lang
	// TODO: check array at 0x587000, 112976 + 4 * lang
	//if lang == xxx {
	//	wfile = "ldlg.wnd"
	//}
	dia := newWindowFromFile(g, wfile, nox_xxx_windowDlgProc_449CA0)
	nox_gui_curDialog_830224 = dia
	if dia == nil {
		return
	}
	dia.SetFunc93(sub_449BE0)
	dia.ChildByID(guiDialogTextEntry1ID).SetFunc93(sub_449C30)
	dia.ChildByID(guiDialogTextEntry2ID).SetFunc93(sub_449C30)
	if title != "" {
		dia.ChildByID(guiDialogTitleID).Func94(&gui.StaticTextSetText{Str: title, Val: -1})
	}
	if text != "" {
		dia.ChildByID(guiDialogTextID).Func94(&gui.StaticTextSetText{Str: text, Val: -1})
	}
	dia.SetParent(nil)
	dia.ShowModal()
	dia.StackPush()
	vsz := videoGetWindowSize()
	sz := dia.Size()
	dia.SetPos(image.Pt((vsz.X-sz.X)/2, (vsz.Y-sz.Y)/2))
	sub449EA0(flags)
	prev := g.Captured()
	dword_5d4594_830236 = prev
	if prev != nil {
		prev.Capture(false)
	}
}

func sub449E00(a1 string) int {
	v1 := nox_gui_curDialog_830224.ChildByID(4005)
	return gui.EventRespInt(v1.Func94(&gui.StaticTextSetText{Str: a1, Val: -1}))
}

func sub449E30(a1 string) int {
	v1 := nox_gui_curDialog_830224.ChildByID(4004)
	return gui.EventRespInt(v1.Func94(&gui.StaticTextSetText{Str: a1, Val: -1}))
}

func sub_449E60(a1 int8) int {
	return gui.EventRespInt(sub449E60(a1))
}

func sub449E60(a1 int8) gui.WindowEventResp {
	var v1 *gui.Window
	if a1 >= 0 {
		v1 = nox_gui_curDialog_830224.ChildByID(guiDialogTextEntry1ID)
	} else {
		v1 = nox_gui_curDialog_830224.ChildByID(guiDialogTextEntry2ID)
	}
	return v1.Func94(gui.AsWindowEvent(0x401d, 0, 0))
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

func sub_449BE0(win *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	switch ev := ev.(type) {
	default:
		return nil
	case gui.WindowKeyPress:
		switch ev.Key {
		case keybind.KeyEsc:
			return gui.RawEventResp(1)
		case keybind.KeySpace:
			mpos := noxClient.GetMousePos()
			win.Func93(&gui.WindowMouseState{State: input.NOX_MOUSE_LEFT_DOWN, Pos: mpos})
		}
		return nil
	}
}

func sub_449C30(a1 *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	switch ev := ev.(type) {
	case gui.WindowKeyPress:
		if ev.Key == keybind.KeyEnter {
			dia := nox_gui_curDialog_830224
			bok := dia.ChildByID(guiDialogOKID)
			if bok.GetFlags().IsEnabled() && !bok.GetFlags().IsHidden() {
				dia.Func94(&WindowEvent0x4007{Win: bok})
			}
		}
	}
	return legacy.Nox_xxx_wndEditProc_487D70(a1, ev)
}

func nox_xxx_windowDlgProc_449CA0(a1 *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	switch ev := ev.(type) {
	default:
		return nil
	case gui.WindowFocus:
		return gui.RawEventResp(1)
	case *WindowEvent0x4007:
		switch ev.Win.ID() {
		case guiDialogOKID, guiDialogYesID: // OK or Yes
			if memmap.Uint8(0x5D4594, 830240)&0x20 != 0 {
				nox_gui_curDialog_830224.StackPop()
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
				nox_gui_curDialog_830224.StackPop()
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
			v5 := legacy.Sub_41E2F0()
			legacy.Sub_41DA70(v5, 8)
			nox_gui_dialogUnsetFlags_830224(gui.DialogDisconnectButton)
			sub_44A400()
		case guiDialogHelpID: // Help
			dword_5d4594_830228.Func94(ev)
		}
		return nil
	}
}

func sub_44A4E0() int {
	if !sub44A4A0() {
		return 0
	}
	v0 := nox_gui_curDialog_830224.ChildByID(4002)
	nox_gui_curDialog_830224.Func94(&WindowEvent0x4007{Win: v0})
	return 1
}

func sub_44A4B0() {
	if nox_gui_curDialog_830224 != nil {
		nox_gui_curDialog_830224.ShowModal()
	}
}

func sub_44A360(a1 int) {
	name := noxfont.DefaultName
	if a1 == 1 {
		name = noxfont.LargeName
	}
	fnt := noxClient.r.Fonts.FontPtrByName(name)
	nox_gui_curDialog_830224.ChildByID(guiDialogTitleID).DrawData().SetFont(fnt)
	nox_gui_curDialog_830224.ChildByID(guiDialogTextID).DrawData().SetFont(fnt)
}

func guiCloseNPCDialog() {
	root := legacy.Get_dword_5d4594_1123524()
	sub := root.ChildByID(3901)
	sub.Func94(gui.AsWindowEvent(0x400F, 0, 0))
	legacy.Nox_xxx_wnd_46ABB0(root, 0)
	root.SetHidden(true)
	sub_44D8F0()
	legacy.Set_dword_5d4594_1123520(0)
	if !nox_client_renderGUI_80828 && memmap.Uint32(0x587000, 153436) == 1 {
		nox_client_renderGUI_80828 = true
	}
}

func guiOpenNPCDialog(title string, snd sound.ID, str strman.ID, pic string, flags server.DialogFlags) {
	c := noxClient
	root := legacy.Get_dword_5d4594_1123524()
	v5 := root.ChildByID(3901)
	v6 := root.ChildByID(3910)
	legacy.Sub_445C20()
	v5.Func94(gui.AsWindowEvent(0x400F, 0, 0))
	root.SetPos(videoGetWindowSize().Sub(root.Size()))
	legacy.Sub_47A020(str)
	v17 := nox_xxx_gLoadImg(pic)
	v7 := root.ChildByID(3905)
	v7.DrawData().SetBackgroundImage(v17)
	v6.Func94(&gui.StaticTextSetText{Str: title})
	v8 := root.ChildByID(3908)
	if flags&0x1 != 0 {
		legacy.Nox_xxx_wnd_46ABB0(v8, 1)
		v8.SetHidden(false)
		v8.Off.Y = 5

		v9 := root.ChildByID(3909)
		legacy.Nox_xxx_wnd_46ABB0(v9, 1)
		v9.SetHidden(false)
		v9.Off.Y = 35
	} else {
		legacy.Nox_xxx_wnd_46ABB0(v8, 0)
		v8.SetHidden(true)

		v12 := root.ChildByID(3909)
		legacy.Nox_xxx_wnd_46ABB0(v12, 0)
		v12.SetHidden(true)
	}
	v10 := root.ChildByID(3906)
	v11 := c.Strings().GetStringInFile("Dialog.wnd:Done", "GUIDlg.c")
	sub_46AEE0(v10, v11)
	legacy.Nox_xxx_wnd_46ABB0(v10, 1)
	v10.SetHidden(false)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*5)) = 95
	v13 := root.ChildByID(3907)
	legacy.Nox_xxx_wnd_46ABB0(v13, 1)
	v13.SetHidden(false)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*5)) = 65
	if flags&0x2 != 0 {
		v14 := root.ChildByID(3906)
		v15 := c.Strings().GetStringInFile("Dialog.wnd:Next", "GUIDlg.c")
		sub_46AEE0(v14, v15)
	}
	legacy.Sub_467C10()
	legacy.Nox_xxx_bookHideMB_45ACA0(0)
	*memmap.PtrUint32(0x587000, 153436) = uint32(nox_client_getRenderGUI())
	nox_client_renderGUI_80828 = false
	legacy.Nox_xxx_wnd_46ABB0(root, 1)
	root.ShowModal()
	*memmap.PtrUint32(0x5D4594, 1123528) = uint32(snd)
	legacy.Nox_xxx_playDialogFile_44D900(alloc.GoString((*byte)(*memmap.PtrPtr(0x5D4594, 1115312))), 100)
	legacy.Set_dword_5d4594_1123520(1)
}
