package nox

/*
#include "client__gui__window.h"
#include "client__gui__guicon.h"
extern uint32_t nox_color_black_2650656;
extern uint32_t nox_color_white_2523948;
extern int dword_5d4594_3799524;
void nox_xxx_consoleEsc_49B7A0();
unsigned int nox_gui_xxx_check_446360();
*/
import "C"
import (
	"context"
	"fmt"
	"unsafe"

	"nox/v1/client/gui"
	"nox/v1/common/alloc"
	noxcolor "nox/v1/common/color"
	"nox/v1/common/console"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/keybind"
	"nox/v1/common/memmap"
	"nox/v1/common/types"
	"nox/v1/internal/version"
)

var (
	guiCon                      = new(guiConsolePrinter)
	nox_gui_console_win         *Window
	nox_gui_console_scrollbox   *Window
	nox_gui_console_input       *Window
	nox_gui_console_translucent = true
	nox_gui_console_password    string
	nox_gui_console_locked      bool
	nox_gui_console_wantsPass   bool
)

func init() {
	consoleMux.Add(guiCon)
	noxConsole.Register(&console.Command{
		Token: "clear", HelpID: "clearhelp",
		Flags: console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			nox_gui_console_Clear_450B70()
			return true
		},
	})
	noxConsole.Register(&console.Command{
		Token: "lock", HelpID: "lockhelp",
		Flags: console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if len(tokens) != 1 {
				return false
			}
			nox_gui_console_Lock_450B20(tokens[0])
			nox_gui_console_Clear_450B70()
			s := c.Strings().GetStringInFile("consolelocked", "C:\\NoxPost\\src\\Client\\System\\parsecmd.c")
			c.Print(console.ColorWhite, s)
			return true
		},
	})
	noxConsole.Register(&console.Command{
		Token: "unlock", HelpID: "unlockhelp",
		Flags: console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if len(tokens) != 0 {
				return false
			}
			nox_gui_console_Unlock_450B50()
			s := c.Strings().GetStringInFile("consoleunlocked", "C:\\NoxPost\\src\\Client\\System\\parsecmd.c")
			c.Print(console.ColorWhite, s)
			return true
		},
	})
}

type guiConsolePrinter struct {
	enabled bool
}

func (p guiConsolePrinter) Print(cl console.Color, str string) {
	if p.enabled && nox_gui_console_scrollbox != nil {
		nox_gui_console_scrollbox.Func94(&WindowEvent0x400d{Str: str, Val: int(cl)})
	}
}

func (p guiConsolePrinter) Printf(cl console.Color, format string, args ...interface{}) {
	str := fmt.Sprintf(format, args...)
	p.Print(cl, str)
}

//export nox_gui_console_translucent_get
func nox_gui_console_translucent_get() C.int {
	if nox_gui_console_translucent {
		return 1
	}
	return 0
}

//export nox_gui_console_translucent_set
func nox_gui_console_translucent_set(v C.int) {
	nox_gui_console_translucent = v != 0
}

//export nox_gui_console_Enable_450BE0
func nox_gui_console_Enable_450BE0() {
	guiCon.enabled = true
}

//export nox_gui_console_Disable_450BF0
func nox_gui_console_Disable_450BF0() {
	guiCon.enabled = false
}

//export nox_gui_console_flagXxx_451410
func nox_gui_console_flagXxx_451410() C.int {
	return C.int((^(nox_gui_console_win.Flags() >> 4)) & 1)
}

//export nox_gui_console_Clear_450B70
func nox_gui_console_Clear_450B70() {
	nox_gui_console_scrollbox.Func94(asWindowEvent(0x400F, 0, 0))
}

//export nox_gui_console_Print_450B90
func nox_gui_console_Print_450B90(cl C.uchar, cstr *C.wchar_t) C.int {
	// since legacy code still calls it, we redirect into global printer instead of GUI printer
	noxConsole.Print(console.Color(cl), GoWString(cstr))
	return 1
}

//export nox_gui_console_PrintOrError_450C30
func nox_gui_console_PrintOrError_450C30(cl C.uchar, cstr *C.wchar_t) {
	nox_gui_console_PrintOrError(console.Color(cl), GoWString(cstr))
}

func nox_gui_console_PrintOrError(cl console.Color, str string) {
	if str != "" {
		noxConsole.Print(cl, str)
		return
	}
	str = noxConsole.Strings().GetStringInFile("InternalError", "C:\\NoxPost\\src\\Client\\Gui\\guicon.c")
	if str != "" {
		noxConsole.Print(cl, str)
	}
}

func nox_gui_console_Create_450C70(sz types.Size) *Window {
	v0 := noxcolor.RGBA5551(memmap.Uint32(0x85B3FC, 956))
	*memmap.PtrInt32(0x5D4594, 833704) = int32(sz.W) - 1
	*memmap.PtrInt32(0x5D4594, 833708) = int32(sz.H) / 2
	nox_gui_console_win = newWindowRaw(nil, 0x38, 0, 0, sz.W-1, sz.H/2, nil)
	nox_gui_console_win.SetAllFuncs(func(win *Window, ev WindowEvent) WindowEventResp {
		return nil
	}, func(win *Window, a2 *WindowData) int {
		pos := win.GlobalPos()
		if win.Flags().Has(gui.StatusImage) {
			noxrend.DrawImageAt(a2.BackgroundImage(), pos)
			return 1
		}
		wsz := win.Size()
		if a2.BackgroundColor() != gui.ColorTransparent {
			if nox_gui_console_translucent {
				noxrend.DrawRectFilledAlpha(pos.X, pos.Y, wsz.W, wsz.H)
				return 1
			}
			noxrend.Data().SetColor2(noxcolor.ExtendColor16(a2.BackgroundColor()))
			noxrend.DrawRectFilledOpaque(pos.X, pos.Y, wsz.W, wsz.H)
		}
		return 1
	}, nil)
	nox_gui_console_win.DrawData().SetBackgroundColor(noxcolor.RGBA5551(C.nox_color_black_2650656))

	drawData, freeDraw := newWindowData()
	defer freeDraw()

	drawData.SetHighlightColor(gui.ColorTransparent)
	drawData.SetSelectedColor(gui.ColorTransparent)
	drawData.SetBackgroundImage(nil)
	drawData.SetDisabledImage(nil)
	drawData.SetEnabledColor(v0)
	drawData.SetTextColor(v0)
	drawData.SetText(version.ClientVersion())

	drawData.SetStyleFlags(gui.StyleScrollListBox)

	scrp, freeScr := alloc.Malloc(unsafe.Sizeof(scrollListBoxData{}))
	defer freeScr()
	scrollData := (*scrollListBoxData)(scrp)
	scrollData.count = 128
	scrollData.line_height = 10
	scrollData.field_1 = 1
	scrollData.field_2 = 1
	scrollData.field_3 = 1
	scrollData.field_4 = 0
	nox_gui_console_scrollbox = nox_gui_newScrollListBox_4A4310(nox_gui_console_win, 1152, 0, 0, int(memmap.Int32(0x5D4594, 833704)), int(memmap.Int32(0x5D4594, 833708))-20, drawData, scrollData)
	drawData.SetDisabledColor(v0)
	drawData.SetEnabledColor(v0)
	drawData.SetHighlightColor(v0)
	drawData.SetSelectedColor(v0)
	drawData.SetTextColor(v0)

	inpp, freeInp := alloc.Malloc(unsafe.Sizeof(entryFieldData{}))
	defer freeInp()
	inpData := (*entryFieldData)(inpp)
	inpData.text[0] = 0
	inpData.field_1024 = 0
	inpData.field_1028 = 0
	inpData.field_1032 = 0
	inpData.field_1036 = 0
	inpData.field_1040 = 128
	inpData.field_1042 = C.short(*memmap.PtrInt16(0x5D4594, 833704))

	drawData.SetText("")
	drawData.SetStyleFlags(gui.StyleEntryField)
	nox_gui_console_input = nox_gui_newEntryField_488500(nox_gui_console_win, 16393, 0, int(memmap.Int32(0x5D4594, 833708))-20, int(memmap.Int32(0x5D4594, 833704)), 20, drawData, inpData)
	nox_gui_console_input.setFunc93(nox_xxx_consoleEditProc_450F40)
	nox_gui_console_locked = false
	nox_gui_console_wantsPass = false
	nox_gui_console_password = ""
	return nox_gui_console_win
}

func nox_xxx_consoleEditProc_450F40(win *Window, ev WindowEvent) WindowEventResp {
	switch ev := ev.(type) {
	case WindowKeyPress:
		if ctrlEvent.hasDefBinding(keybind.EventToggleConsole, ev.Key) {
			if ev.Pressed {
				nox_client_toggleConsole_451350()
			}
			return RawEventResp(1)
		}
		switch ev.Key {
		case keybind.KeyEsc:
			if ev.Pressed {
				C.nox_xxx_consoleEsc_49B7A0()
			}
			return RawEventResp(1)
		case keybind.KeyEnter:
			if ev.Pressed {
				nox_gui_console_Enter_450FD0()
			}
			return RawEventResp(1)
		}
	}
	return nox_xxx_wndEditProc_487D70(win, ev)
}

//export nox_gui_console_Hide_4512B0
func nox_gui_console_Hide_4512B0() C.int {
	if nox_gui_console_win.Flags().IsHidden() {
		return 0
	}
	if nox_xxx_wndGetFocus_46B4F0() == nox_gui_console_input.C() {
		guiFocus(nil)
	}
	nox_gui_console_win.Hide()
	nox_gui_console_win.flags &= 0xFFFFFFF7
	nox_gui_console_input.flags &= 0xFFFFFFF7
	nox_gui_console_scrollbox.flags &= 0xFFFFFFF7
	nox_gui_console_input.DrawData().field_0 &= 0xFFFFFFFB
	nox_gui_console_input.DrawData().field_0 &= 0xFFFFFFFD
	C.dword_5d4594_3799524 = 1
	return 1
}

func nox_gui_console_reloadColors_451100() {
	color := noxcolor.RGBA5551(memmap.Uint32(0x85B3FC, 956))
	black := noxcolor.RGBA5551(C.nox_color_black_2650656)
	white := noxcolor.RGBA5551(C.nox_color_white_2523948)
	if nox_gui_console_win != nil {
		nox_gui_console_win.DrawData().SetBackgroundColor(black)
	}
	if nox_gui_console_scrollbox != nil {
		dd := nox_gui_console_scrollbox.DrawData()
		dd.SetBackgroundColor(gui.ColorTransparent)
		dd.SetDisabledColor(gui.ColorTransparent)
		dd.SetEnabledColor(color)
		dd.SetHighlightColor(color)
		dd.SetSelectedColor(gui.ColorTransparent)
		dd.SetTextColor(color)

		scr := (*scrollListBoxData)(nox_gui_console_scrollbox.widget_data)
		if v2 := asWindowP(scr.field_9); v2 != nil {
			dd2 := v2.DrawData()
			dd2.SetBackgroundColor(black)
			dd2.SetDisabledColor(black)
			dd2.SetEnabledColor(color)
			dd2.SetHighlightColor(black)
			dd2.SetSelectedColor(color)
			if v3 := v2.Field100(); v3 != nil {
				dd3 := v3.DrawData()
				dd3.SetBackgroundColor(black)
				dd3.SetDisabledColor(black)
				dd3.SetEnabledColor(color)
				dd3.SetHighlightColor(black)
				dd3.SetSelectedColor(black)
			}
		}
		if v4 := asWindowP(scr.field_7); v4 != nil {
			dd4 := v4.DrawData()
			dd4.SetBackgroundColor(black)
			dd4.SetDisabledColor(black)
			dd4.SetEnabledColor(color)
			dd4.SetHighlightColor(white)
			dd4.SetSelectedColor(color)
			dd4.SetTextColor(color)
		}
		if v5 := asWindowP(scr.field_8); v5 != nil {
			dd5 := v5.DrawData()
			dd5.SetBackgroundColor(black)
			dd5.SetDisabledColor(black)
			dd5.SetEnabledColor(color)
			dd5.SetHighlightColor(white)
			dd5.SetSelectedColor(color)
			dd5.SetTextColor(color)
		}
	}
	if nox_gui_console_input != nil {
		dd := nox_gui_console_input.DrawData()
		dd.SetBackgroundColor(black)
		dd.SetDisabledColor(color)
		dd.SetEnabledColor(color)
		dd.SetHighlightColor(color)
		dd.SetSelectedColor(color)
		dd.SetTextColor(color)
	}
}

func nox_gui_console_Lock_450B20(pass string) {
	if pass != "" {
		nox_gui_console_password = pass
		nox_gui_console_locked = true
	}
}

func nox_gui_console_Unlock_450B50() {
	nox_gui_console_password = ""
	nox_gui_console_locked = false
	nox_gui_console_wantsPass = false
}

func nox_client_toggleConsole_451350() {
	if !nox_gui_console_win.Flags().Has(gui.StatusHidden) {
		nox_gui_console_Hide_4512B0()
		return
	}
	if C.nox_gui_xxx_check_446360() == 0 {
		nox_xxx_wndShowModalMB(nox_gui_console_win)
		nox_gui_console_win.flags |= 8
		nox_gui_console_scrollbox.flags |= 8
		nox_gui_console_input.flags |= 8
		nox_gui_console_input.flags |= 1
		guiFocus(nox_gui_console_input)
		if nox_gui_console_locked {
			nox_gui_console_Clear_450B70()
			s := noxConsole.Strings().GetStringInFile("ENTERPASSWORD", "C:\\NoxPost\\src\\Client\\Gui\\guicon.c")
			noxConsole.Print(console.ColorWhite, s)
			nox_gui_console_wantsPass = true
		}
	}
}

func nox_gui_console_Enter_450FD0() int {
	wd := (*entryFieldData)(nox_gui_console_input.widget_data)
	if wd.field_1044 != 0 {
		return 1
	}
	line := eventRespStr(nox_gui_console_input.Func94(asWindowEvent(0x401d, 0, 0)))
	if nox_gui_console_wantsPass && nox_gui_console_password != "" {
		if line != nox_gui_console_password {
			v4 := strMan.GetStringInFile("INVALIDPASSWORD", "C:\\NoxPost\\src\\Client\\Gui\\guicon.c")
			nox_gui_console_PrintOrError(console.ColorWhite, v4)
		} else {
			nox_gui_console_wantsPass = false
			v3 := strMan.GetStringInFile("ConsoleUnlocked", "C:\\NoxPost\\src\\Client\\Gui\\guicon.c")
			nox_gui_console_PrintOrError(console.ColorRed, v3)
		}
		nox_gui_console_input.Func94(asWindowEvent(0x401e, uintptr(memmap.PtrOff(0x5D4594, 833744)), 0))
		return 1
	}
	noxConsole.Print(console.ColorWhite, "> "+line)
	if line != "" {
		if noxflags.HasEngine(noxflags.EngineReplayWrite) {
			nox_xxx_replaySaveConsole(line)
		}
		execConsoleCmd(context.Background(), line)
	}
	nox_gui_console_input.Func94(asWindowEvent(0x401e, uintptr(memmap.PtrOff(0x5D4594, 833748)), 0))
	return 1
}
