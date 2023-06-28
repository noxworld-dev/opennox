package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	guiSelClassInfoPtr unsafe.Pointer
	guiSelClassWin     *gui.Window
	guiSelClassAnim    *gui.Anim
	guiSelClassAccept  *gui.Window
	guiSelClassCurID   uint
)

func Nox_game_showSelClass_4A4840() int {
	sub_5007E0(internCStr("*:*"))
	sub_4A1BE0(1)
	guiSelClassInfoPtr = unsafe.Pointer(nox_xxx_getHostInfoPtr_431770())
	nox_game_addStateCode_43BDD0(600)
	win := nox_new_window_from_file(internCStr("SelClass.wnd"), guiSelClassProc1)
	guiSelClassWin = win
	if win == nil {
		return 0
	}
	win.SetFunc93(gui.WrapFunc(guiSelProc2))
	ani := nox_gui_makeAnimation_43C5B0(win, 0, 0, 0, -460, 0, 20, 0, -40)
	guiSelClassAnim = ani
	if ani == nil {
		return 0
	}
	ani.StateID = 600
	ani.Func12Ptr.Set(sub_4A4970)
	ani.FncDoneOutPtr.Set(func() int {
		fnc := ani.Func13Ptr.Get()
		nox_gui_freeAnimation_43C570(ani)
		win.Destroy()
		fnc()
		return 1
	})

	win.ChildByID(601).SetDraw(guiSelClassShadeDraw)
	win.ChildByID(602).SetDraw(guiSelClassShadeDraw)
	win.ChildByID(603).SetDraw(guiSelClassShadeDraw)

	guiSelClassAccept = win.ChildByID(610)
	nox_xxx_wndRetNULL_46A8A0()
	guiSelClassCurID = 0
	sub_4A19F0(internCStr("OptsBack.wnd:Back"))
	sub_4602F0()
	return 1
}

func sub_4A4970() int {
	guiSelClassAnim.SetState(NOX_GUI_ANIM_OUT)
	sub_43BE40(2)
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100)
	return 1
}

func guiSelClassShadeDraw(win *gui.Window, draw *gui.WindowData) int {
	if guiSelClassCurID == win.ID() {
		return 1
	}
	var x, y uint32
	nox_client_wndGetPosition_46AA60(win, &x, &y)
	nox_client_drawRectFilledAlpha_49CF10(int32(x), int32(y), int32(win.EndPos.X-win.Off.X), int32(win.EndPos.Y-win.Off.Y))
	return 1
}

func guiSelClassProc1(_ *gui.Window, ev, a3, a4 uintptr) uintptr {
	switch ev {
	case 0x4005:
		targ := AsWindowP(unsafe.Pointer(a3))
		if id := targ.ID(); id >= 601 && id <= 603 {
			nox_xxx_wnd_46ABB0(guiSelClassAccept, 1)
			descWin := guiSelClassWin.ChildByID(605)
			cl := player.Class(byte(int8(id - 89))) // TODO: how this conversion works?
			*(*byte)(unsafe.Add(guiSelClassInfoPtr, 66)) = byte(cl)
			names := []strman.ID{
				"Warrior",
				"Wizard",
				"Conjurer",
			}
			desc := internWStr(GetClient().Strings().GetStringInFile(names[cl], "SelClass.c"))
			descWin.Func94(gui.AsWindowEvent(0x4001, uintptr(unsafe.Pointer(desc)), 0))
			guiSelClassCurID = id
		}
		nox_xxx_clientPlaySoundSpecial_452D80(920, 100)
		return 1
	case 0x4007:
		targ := AsWindowP(unsafe.Pointer(a3))
		if id := targ.ID(); id >= 601 {
			if id <= 603 {
				return 1
			}
			if id == 610 {
				if noxflags.HasGame(0x2000) && !noxflags.HasGame(4096) {
					var v5 int32
					if nox_xxx_isQuest_4D6F50() != 0 || (func() int32 {
						v5 = sub_4D6F70()
						return v5
					}()) != 0 {
						v5 = 1
					}
					sub_4A4B70(v5)
				}
				sub_4A4970()
				guiSelClassAnim.Func13Ptr.Set(nox_game_showSelColor_4A5D00)
			}
		}
		nox_xxx_clientPlaySoundSpecial_452D80(921, 100)
		return 1
	default:
		return 0
	}
}

func sub_4A4B70(a1 int32) {
	var (
		v1     uint8
		result unsafe.Pointer
		v3     *uint8
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     bool
		v9     uint8
		v10    int32
		v11    int32
	)
	v1 = 0
	result = *(*unsafe.Pointer)(unsafe.Add(guiSelClassInfoPtr, 66))
	v3 = *(**uint8)(memmap.PtrOff(0x587000, uintptr(result)*4+170156))
	if int32(*v3) == 0 {
		return
	}
	for {
		result = unsafe.Pointer(uintptr(func() uint8 {
			p := &v1
			*p++
			return *p
		}()))
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), int32(v1)*4+int32(v1)))) == 0 {
			break
		}
	}
	if int32(v1) == 0 {
		return
	}
	v4 = 0
	v9 = uint8(int8(nox_common_randomIntMinMax_415FF0(0, int32(v1)-1, internCStr("C:\\NoxPost\\src\\client\\shell\\SelClass.c"), 195)))
	if int32(*(*uint8)(unsafe.Add(guiSelClassInfoPtr, 66))) != 0 {
		v10 = 0
		v11 = 5
		for {
			nox_xxx_clientUpdateButtonRow_45E110(v10)
			v6 = 0
			v7 = 5
			for {
				if a1 == 1 {
					nox_xxx_book_45DBE0(2, 0, v6)
				} else {
					nox_xxx_book_45DBE0(2, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), int32(v9)*4+v6+int32(v9)))), v6)
				}
				v6++
				v7--
				if v7 == 0 {
					break
				}
			}
			v8 = v11 == 1
			v10++
			v11--
			if v8 {
				break
			}
		}
		nox_xxx_clientUpdateButtonRow_45E110(0)
	} else {
		nox_xxx_clientUpdateButtonRow_45E110(0)
		v5 = 5
		for {
			if a1 == 1 {
				nox_xxx_book_45DBE0(3, 0, v4)
			} else {
				nox_xxx_book_45DBE0(3, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), int32(v9)*4+v4+int32(v9)))), v4)
			}
			v4++
			v5--
			if v5 == 0 {
				break
			}
		}
	}
}

func guiSelProc2(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	return GuiSelProc2(a1, a2, a3, a4)
}
