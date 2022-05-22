package opennox

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
	"image"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox-lib/console"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/version"
)

var (
	guiCon = &guiConsole{c: noxConsole, translucent: true}
)

func init() {
	consoleMux.Add(guiCon)
	guiCon.c.Register(&console.Command{
		Token: "clear", HelpID: "clearhelp",
		Flags: console.ClientServer,
		Func:  guiCon.cmdClear,
	})
	guiCon.c.Register(&console.Command{
		Token: "lock", HelpID: "lockhelp",
		Flags: console.ClientServer,
		Func:  guiCon.cmdLock,
	})
	guiCon.c.Register(&console.Command{
		Token: "unlock", HelpID: "unlockhelp",
		Flags: console.ClientServer,
		Func:  guiCon.cmdUnlock,
	})
}

//export nox_gui_console_flagXxx_451410
func nox_gui_console_flagXxx_451410() C.int {
	return C.int((^(guiCon.root.Flags() >> 4)) & 1)
}

//export nox_gui_console_Clear_450B70
func nox_gui_console_Clear_450B70() {
	guiCon.Clear()
}

//export nox_gui_console_Print_450B90
func nox_gui_console_Print_450B90(cl C.uchar, cstr *C.wchar_t) C.int {
	// since legacy code still calls it, we redirect into global printer instead of GUI printer
	noxConsole.Print(console.Color(cl), GoWString(cstr))
	return 1
}

//export nox_gui_console_PrintOrError_450C30
func nox_gui_console_PrintOrError_450C30(cl C.uchar, cstr *C.wchar_t) {
	noxConsole.PrintOrError(console.Color(cl), GoWString(cstr))
}

//export nox_gui_console_Hide_4512B0
func nox_gui_console_Hide_4512B0() C.int {
	return C.int(bool2int(guiCon.Hide()))
}

type guiConsole struct {
	c           *console.Console
	password    string
	root        *Window
	scrollbox   *Window
	input       *Window
	translucent bool
	wantsPass   bool
	enabled     bool
}

func (c *guiConsole) Enable(v bool) {
	c.enabled = v
}

func (c *guiConsole) Print(cl console.Color, str string) {
	if c.enabled && c.scrollbox != nil {
		c.scrollbox.Func94(&WindowEvent0x400d{Str: str, Val: int(cl)})
	}
}

func (c *guiConsole) Printf(cl console.Color, format string, args ...interface{}) {
	str := fmt.Sprintf(format, args...)
	c.Print(cl, str)
}

func (c *guiConsole) PrintOrError(cl console.Color, str string) {
	if str != "" {
		c.Print(cl, str)
		return
	}
	str = c.c.Strings().GetStringInFile("InternalError", "guicon.c")
	if str != "" {
		c.Print(cl, str)
	}
}

func (c *guiConsole) Clear() {
	c.scrollbox.Func94(asWindowEvent(0x400F, 0, 0))
}

func (c *guiConsole) Init(sz image.Point) *Window {
	v0 := noxcolor.RGBA5551(memmap.Uint32(0x85B3FC, 956))
	*memmap.PtrInt32(0x5D4594, 833704) = int32(sz.X) - 1
	*memmap.PtrInt32(0x5D4594, 833708) = int32(sz.Y) / 2
	c.root = newWindowRaw(nil, 0x38, 0, 0, sz.X-1, sz.Y/2, nil)
	c.root.SetAllFuncs(func(win *Window, ev WindowEvent) WindowEventResp {
		return nil
	}, func(win *Window, a2 *WindowData) int {
		r := noxrend
		pos := win.GlobalPos()
		if win.Flags().Has(gui.StatusImage) {
			r.DrawImageAt(a2.BackgroundImage(), pos)
			return 1
		}
		wsz := win.Size()
		if a2.BackgroundColor() != gui.ColorTransparent {
			if c.translucent {
				r.DrawRectFilledAlpha(pos.X, pos.Y, wsz.X, wsz.Y)
				return 1
			}
			r.Data().SetColor2(noxcolor.ExtendColor16(a2.BackgroundColor()))
			r.DrawRectFilledOpaque(pos.X, pos.Y, wsz.X, wsz.Y)
		}
		return 1
	}, nil)
	c.root.DrawData().SetBackgroundColor(noxcolor.RGBA5551(C.nox_color_black_2650656))

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

	scrollData, freeScr := alloc.New(scrollListBoxData{})
	defer freeScr()
	scrollData.count = 128
	scrollData.line_height = 10
	scrollData.field_1 = 1
	scrollData.field_2 = 1
	scrollData.field_3 = 1
	scrollData.field_4 = 0
	c.scrollbox = nox_gui_newScrollListBox_4A4310(c.root, 1152, 0, 0, int(memmap.Int32(0x5D4594, 833704)), int(memmap.Int32(0x5D4594, 833708))-20, drawData, scrollData)
	drawData.SetDisabledColor(v0)
	drawData.SetEnabledColor(v0)
	drawData.SetHighlightColor(v0)
	drawData.SetSelectedColor(v0)
	drawData.SetTextColor(v0)

	inpData, freeInp := alloc.New(entryFieldData{})
	defer freeInp()
	inpData.text[0] = 0
	inpData.field_1024 = 0
	inpData.field_1028 = 0
	inpData.field_1032 = 0
	inpData.field_1036 = 0
	inpData.field_1040 = 128
	inpData.field_1042 = C.short(*memmap.PtrInt16(0x5D4594, 833704))

	drawData.SetText("")
	drawData.SetStyleFlags(gui.StyleEntryField)
	c.input = nox_gui_newEntryField_488500(c.root, 16393, 0, int(memmap.Int32(0x5D4594, 833708))-20, int(memmap.Int32(0x5D4594, 833704)), 20, drawData, inpData)
	c.input.setFunc93(c.inputProc)
	c.wantsPass = false
	c.password = ""
	return c.root
}

func (c *guiConsole) Hide() bool {
	if c.root.Flags().IsHidden() {
		return false
	}
	if nox_xxx_wndGetFocus_46B4F0() == c.input.C() {
		guiFocus(nil)
	}
	c.root.Hide()
	c.root.flags &= 0xFFFFFFF7
	c.input.flags &= 0xFFFFFFF7
	c.scrollbox.flags &= 0xFFFFFFF7
	c.input.DrawData().field_0 &= 0xFFFFFFFB
	c.input.DrawData().field_0 &= 0xFFFFFFFD
	C.dword_5d4594_3799524 = 1
	return true
}

func (c *guiConsole) ReloadColors() {
	color := noxcolor.RGBA5551(memmap.Uint32(0x85B3FC, 956))
	black := noxcolor.RGBA5551(C.nox_color_black_2650656)
	white := noxcolor.RGBA5551(C.nox_color_white_2523948)
	if c.root != nil {
		c.root.DrawData().SetBackgroundColor(black)
	}
	if c.scrollbox != nil {
		dd := c.scrollbox.DrawData()
		dd.SetBackgroundColor(gui.ColorTransparent)
		dd.SetDisabledColor(gui.ColorTransparent)
		dd.SetEnabledColor(color)
		dd.SetHighlightColor(color)
		dd.SetSelectedColor(gui.ColorTransparent)
		dd.SetTextColor(color)

		scr := (*scrollListBoxData)(c.scrollbox.widget_data)
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
	if c.input != nil {
		dd := c.input.DrawData()
		dd.SetBackgroundColor(black)
		dd.SetDisabledColor(color)
		dd.SetEnabledColor(color)
		dd.SetHighlightColor(color)
		dd.SetSelectedColor(color)
		dd.SetTextColor(color)
	}
}

func (c *guiConsole) SetPass(pass string) {
	if pass != "" {
		c.password = pass
	}
}

func (c *guiConsole) ResetPass() {
	c.password = ""
	c.wantsPass = false
}

func (c *guiConsole) Toggle() {
	if !c.root.Flags().Has(gui.StatusHidden) {
		c.Hide()
		return
	}
	if C.nox_gui_xxx_check_446360() == 0 {
		nox_xxx_wndShowModalMB(c.root)
		c.root.flags |= 8
		c.scrollbox.flags |= 8
		c.input.flags |= 8
		c.input.flags |= 1
		guiFocus(c.input)
		if c.password != "" {
			c.Clear()
			s := c.c.Strings().GetStringInFile("ENTERPASSWORD", "C:\\NoxPost\\src\\Client\\Gui\\guicon.c")
			c.c.Print(console.ColorWhite, s)
			c.wantsPass = true
		}
	}
}

func (c *guiConsole) inputProc(win *Window, ev WindowEvent) WindowEventResp {
	switch ev := ev.(type) {
	case WindowKeyPress:
		if ctrlEvent.hasDefBinding(keybind.EventToggleConsole, ev.Key) {
			if ev.Pressed {
				c.Toggle()
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
				c.nox_gui_console_Enter_450FD0()
			}
			return RawEventResp(1)
		}
	}
	return nox_xxx_wndEditProc_487D70(win, ev)
}

func (c *guiConsole) nox_gui_console_Enter_450FD0() {
	wd := (*entryFieldData)(c.input.widget_data)
	if wd.field_1044 != 0 {
		return
	}
	cmd := eventRespStr(c.input.Func94(asWindowEvent(0x401d, 0, 0)))
	if c.wantsPass && c.password != "" {
		if cmd != c.password {
			s := strMan.GetStringInFile("INVALIDPASSWORD", "C:\\NoxPost\\src\\Client\\Gui\\guicon.c")
			c.PrintOrError(console.ColorWhite, s)
		} else {
			c.wantsPass = false
			s := strMan.GetStringInFile("ConsoleUnlocked", "C:\\NoxPost\\src\\Client\\Gui\\guicon.c")
			c.PrintOrError(console.ColorRed, s)
		}
		c.input.Func94(asWindowEvent(0x401e, uintptr(memmap.PtrOff(0x5D4594, 833744)), 0))
		return
	}
	c.Print(console.ColorWhite, "> "+cmd)
	if cmd != "" {
		if noxflags.HasEngine(noxflags.EngineReplayWrite) {
			nox_xxx_replaySaveConsole(cmd)
		}
		execConsoleCmd(context.Background(), cmd)
	}
	c.input.Func94(asWindowEvent(0x401e, uintptr(memmap.PtrOff(0x5D4594, 833748)), 0))
}

func (c *guiConsole) cmdClear(ctx context.Context, _ *console.Console, tokens []string) bool {
	if len(tokens) != 0 {
		return false
	}
	c.Clear()
	return true
}

func (c *guiConsole) cmdLock(ctx context.Context, _ *console.Console, tokens []string) bool {
	if len(tokens) != 1 {
		return false
	}
	c.SetPass(tokens[0])
	c.Clear()
	s := c.c.Strings().GetStringInFile("consolelocked", "C:\\NoxPost\\src\\Client\\System\\parsecmd.c")
	c.Print(console.ColorWhite, s)
	return true
}

func (c *guiConsole) cmdUnlock(ctx context.Context, _ *console.Console, tokens []string) bool {
	if len(tokens) != 0 {
		return false
	}
	c.ResetPass()
	s := c.c.Strings().GetStringInFile("consoleunlocked", "C:\\NoxPost\\src\\Client\\System\\parsecmd.c")
	c.Print(console.ColorWhite, s)
	return true
}
