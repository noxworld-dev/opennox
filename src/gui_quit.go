package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_xxx_wndLoadQuitMenu_445790() int {
	win := newWindowFromFile(noxClient.GUI, "QuitMenu.wnd", gui.WrapFuncC(legacy.Get_nox_xxx_menuGameOnButton_445840()))
	if win == nil {
		return 0
	}
	legacy.Set_nox_wnd_quitMenu_825760(win)
	win.SetAllFuncs(func(win *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
		return gui.RawEventResp(1)
	}, func(win *gui.Window, draw *gui.WindowData) int {
		pos := win.GlobalPos()
		sz := win.Size()
		noxClient.r.DrawRectFilledAlpha(pos.X, pos.Y, sz.X, sz.Y)
		return 1
	}, nil)
	sz := win.Size()
	win.DrawData().SetBackgroundColor(nox_color_black_2650656)
	win.Off.X = int(nox_win_width-sz.X) / 2
	win.EndPos.X = win.Off.X + sz.X
	if nox_win_height > 768 {
		win.Off.Y = (nox_win_height - sz.Y - nox_win_height/3) / 2
		win.EndPos.Y = win.Off.Y + sz.Y
	}
	legacy.Sub_445C40()
	dword_5d4594_825752 = 0
	dword_5d4594_825768 = 0
	str := strMan.GetStringInFile("Vote", "guiquit.c")
	alloc.StrCopyZero(unsafe.Slice((*byte)(memmap.PtrOff(0x5D4594, 825772)), 256), str)
	return 1
}

func sub_467440(a1 int) {
	*memmap.PtrUint32(0x5D4594, 1062544) = uint32(a1)
}

func sub_446190() {
	nox_xxx_serverIsClosing_825764 = false
	if noxflags.HasGame(noxflags.GameHost) {
		str := strMan.GetStringInFile("ServerManualShutdown", "guiquit.c")
		netstr.Log.Println(str)
	}
	if noxflags.HasGame(noxflags.GameFlag26) {
		sub_41E300(9)
		legacy.Nox_xxx____setargv_4_44B000()
	} else if noxServer.nox_xxx_isQuest_4D6F50() {
		if sub4D6F30() {
			noxClient.nox_game_checkStateMenu_43C2F0()
		}
		legacy.Sub_4D70B0()
		sub4D6F40(false)
		sub_4D6F90(0)
	}
	if dword_5d4594_825768 == 0 {
		dword_5d4594_825752 = 0
		dword_5d4594_825768 = noxServer.Frame()
		if noxflags.HasGame(noxflags.GameHost) {
			if false && noxflags.HasGame(noxflags.GameFlag15|noxflags.GameFlag16) {
				sub_416150(15, 0)
			}
			legacy.Sub_509CB0()
		}
		if noxflags.HasGame(noxflags.GameHost) {
			dword_5d4594_825752 = noxServer.Players.Count() - 1
			sub_467440(0)
			if dword_5d4594_825752 > 0 {
				netSendServerQuit()
				v3 := strMan.GetStringInFile("ShuttingDown", "C:\\NoxPost\\src\\client\\Gui\\guiquit.c")
				v2 := strMan.GetStringInFile("Wolchat.c:PleaseWait", "C:\\NoxPost\\src\\client\\Gui\\guiquit.c")
				NewDialogWindow(nil, v2, v3, 0, nil, nil)
				sub_44A360(1)
				goto LABEL_20
			}
		} else if !noxflags.HasGame(noxflags.GameOnline) {
			goto LABEL_20
		}
		sub_446380()
	}
LABEL_20:
	if legacy.Get_dword_5d4594_2650652() != 0 {
		if legacy.Sub_41E2F0() == 9 {
			legacy.Sub_41F4B0()
			legacy.Sub_41EC30()
			legacy.Sub_446490(0)
			legacy.Nox_xxx____setargv_4_44B000()
		}
	}
}

func sub_446380() {
	sub_44A400()
	if noxflags.HasGame(noxflags.GameOnline) && !noxflags.HasGame(noxflags.GameModeQuest) && !sub4D6F30() {
		legacy.Sub_41CEE0(memmap.PtrOff(0x85B3FC, 10980), 1)
	}
	legacy.Nox_xxx_guiServerOptionsHide_4597E0(1)
	nox_game_exit_xxx2()
	sub_446060()
}

func clientLoadCoopAuto445B40() int {
	sub_413A00(0)
	if clientLoadCoopGame(common.SaveAuto) {
		return 1
	}
	str := strMan.GetStringInFile("GUISave.c:SaveErrorTitle", "guiquit.c")
	NewDialogWindow(nil, str, str, gui.DialogOKButton|gui.DialogFlag6, nil, nil)
	return 1
}
