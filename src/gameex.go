package main

/*
#include "defs.h"
#include "client__gui__window.h"
extern unsigned int dword_587000_87404;
extern unsigned int dword_5d4594_1064868;
extern unsigned int dword_5d4594_1316972;
extern nox_window* nox_win_unk3;
extern unsigned int gameex_flags;
int sub_4BDFD0();
int  gameex_sendPacket(char* buf, int len, int smth);
char  mix_MouseKeyboardWeaponRoll(int playerObj, char a2);
int getFlagValueFromFlagIndex(signed int a1);
int  modifyWndInputHandler(int a1, int a2, int a3, int a4);
int  nox_xxx_clientUpdateButtonRow_45E110(int a1);
unsigned int*  nox_xxx_objGetTeamByNetCode_418C80(int a1);
void  nox_xxx_printCentered_445490(wchar_t* a1);
char  playerDropATrap(int playerObj);
*/
import "C"
import (
	"bufio"
	"encoding/binary"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	"unsafe"

	"nox/v1/client/input/keybind"
	"nox/v1/common/alloc"
	"nox/v1/common/datapath"
	"nox/v1/common/fs"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
)

var modifyWndPntr *Window
var gameex = struct {
	Log        *log.Logger
	keysByCode map[keybind.Key]string
	keysByName map[string]keybind.Key
	keys       struct {
		panels [5]keybind.Key
		trap   keybind.Key
	}
	configPath string
}{
	Log: log.New("gameex"),
	keysByCode: map[keybind.Key]string{
		183: "print scren",
		210: "insert",
		211: "delete",
		199: "home",
		207: "end",
		197: "pause break",
		41:  "~",
		2:   "1",
		3:   "2",
		4:   "3",
		5:   "4",
		6:   "5",
		7:   "6",
		8:   "7",
		9:   "8",
		10:  "9",
		11:  "0",
		12:  "-",
		13:  "=",
		14:  "backspace",
		181: "num /",
		55:  "num *",
		74:  "num -",
		71:  "num 7",
		72:  "num 8",
		73:  "num 9",
		75:  "num 4",
		76:  "num 5",
		77:  "num 6",
		79:  "num 1",
		80:  "num 2",
		81:  "num 3",
		78:  "num +",
		82:  "num 0",
		83:  "del",
		156: "enter2",
		15:  "tab",
		16:  "q",
		17:  "w",
		18:  "e",
		19:  "r",
		20:  "t",
		21:  "y",
		22:  "u",
		23:  "i",
		24:  "o",
		25:  "p",
		26:  "[",
		27:  "]",
		28:  "enter",
		30:  "a",
		31:  "s",
		32:  "d",
		33:  "f",
		34:  "g",
		35:  "h",
		36:  "j",
		37:  "k",
		38:  "l",
		39:  ";",
		40:  "'",
		43:  "\\",
		42:  "left shift",
		86:  "|",
		44:  "z",
		45:  "x",
		46:  "c",
		47:  "v",
		48:  "b",
		49:  "n",
		50:  "m",
		51:  ",",
		52:  ".",
		53:  "/",
		54:  "right shift",
		29:  "left ctrl",
		56:  "left alt",
		57:  "spacebar",
		184: "right alt",
		201: "page up",
		209: "page down",
		157: "right ctrl",
		200: "up",
		203: "left",
		208: "down",
		205: "right",
	},
}

func init() {
	gameex.keys.panels = [5]keybind.Key{2, 3, 4, 5, 6} // '1', '2', '3', '4', '5'
	gameex.keys.trap = 156                             // 'Num Enter'
	gameex.keysByName = make(map[string]keybind.Key)
	for k, s := range gameex.keysByCode {
		gameex.keysByName[s] = k
	}
}

func gameexReadConfig(path string) error {
	path = datapath.Path(path)
	gameex.configPath = path
	gameex.Log.Println("reading config", path)
	f, err := fs.Open(path)
	if os.IsNotExist(err) {
		gameex.Log.Println("no config file")
		return nil
	} else if err != nil {
		return err
	}
	defer f.Close()

	sc := bufio.NewScanner(f)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if len(line) == 0 || line[0] == '-' || line[0] == '#' {
			continue
		}
		sub := strings.SplitN(line, "=", 2)
		if len(sub) < 2 {
			gameex.Log.Printf("malformed option: %q", line)
			continue
		}
		key := strings.TrimSpace(sub[0])
		val := strings.TrimSpace(sub[1])
		switch key {
		case "AUTO_SHIELD":
			v, err := strconv.ParseBool(val)
			if err != nil {
				return err
			}
			if v {
				C.gameex_flags |= 0x2
			} else {
				C.gameex_flags &^= 0x2
			}
		case "GREAT_SWORD_BLOKING_WALK", "GREAT_SWORD_BLOCKING_WALK":
			v, err := strconv.ParseBool(val)
			if err != nil {
				return err
			}
			if v {
				C.gameex_flags |= 0x4
			} else {
				C.gameex_flags &^= 0x4
			}
		case "MOUSE_KEYBOARD_ROLL":
			v, err := strconv.ParseBool(val)
			if err != nil {
				return err
			}
			if v {
				C.gameex_flags |= 0x8
			} else {
				C.gameex_flags &^= 0x8
			}
		case "BERSERKER_SHIED_BLOCK", "BERSERKER_SHIELD_BLOCK":
			v, err := strconv.ParseBool(val)
			if err != nil {
				return err
			}
			if v {
				C.gameex_flags |= 0x10
			} else {
				C.gameex_flags &^= 0x10
			}
		case "EXTENSION_MESSAGES":
			v, err := strconv.ParseBool(val)
			if err != nil {
				return err
			}
			if v {
				C.gameex_flags |= 0x20
			} else {
				C.gameex_flags &^= 0x20
			}
		case "PANEL1":
			k, err := gameexKeyCode(val)
			if err != nil {
				return err
			}
			gameex.keys.panels[0] = k
		case "PANEL2":
			k, err := gameexKeyCode(val)
			if err != nil {
				return err
			}
			gameex.keys.panels[1] = k
		case "PANEL3":
			k, err := gameexKeyCode(val)
			if err != nil {
				return err
			}
			gameex.keys.panels[2] = k
		case "PANEL4":
			k, err := gameexKeyCode(val)
			if err != nil {
				return err
			}
			gameex.keys.panels[3] = k
		case "PANEL5":
			k, err := gameexKeyCode(val)
			if err != nil {
				return err
			}
			gameex.keys.panels[4] = k
		case "TRAPKEY":
			k, err := gameexKeyCode(val)
			if err != nil {
				return err
			}
			gameex.keys.trap = k
		default:
			gameex.Log.Printf("unrecognized option: %q", key)
		}
	}
	return sc.Err()
}

func gameexKeyCode(s string) (keybind.Key, error) {
	if s == "" {
		return 0, nil
	}
	key, ok := gameex.keysByName[s]
	if ok {
		return key, nil
	}
	b := keyBinding.KeyByName(s)
	if b == nil {
		return 0, fmt.Errorf("invalid key: %q", s)
	}
	return b.Key, nil
}

func gameexKeyName(k keybind.Key) (string, error) {
	if k == 0 {
		return "", nil
	}
	s, ok := gameex.keysByCode[k]
	if ok {
		return s, nil
	}
	b := keyBinding.KeyByCode(k)
	if b == nil {
		return "", fmt.Errorf("invalid key: %v", k)
	}
	return b.Name, nil
}

func gameex_makeExtensionPacket(buf []byte, opcode uint16, needsPlayer bool) {
	binary.LittleEndian.PutUint16(buf[0:], 0xF13A) // extension packet code
	binary.LittleEndian.PutUint16(buf[2:], opcode)
	if needsPlayer {
		binary.LittleEndian.PutUint32(buf[4:], memmap.Uint32(0x5D4594, 2616328)) // playerNetCode
	}
}

var wndEntryNames = [5][35]uint16{
	{119, 97, 114, 114, 105, 111, 114, 115, 32, 108, 105, 107, 101, 32, 115, 104, 105, 101, 108, 100, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{119, 97, 108, 107, 105, 110, 103, 32, 119, 105, 116, 104, 32, 115, 119, 111, 114, 100, 32, 98, 108, 111, 99, 107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{119, 101, 97, 112, 111, 110, 32, 114, 111, 108, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{115, 104, 105, 101, 108, 100, 32, 38, 32, 98, 101, 114, 115, 101, 114, 107, 101, 114, 32, 98, 108, 111, 99, 107, 105, 110, 103, 0, 0, 0, 0, 0, 0, 0, 0},
	{101, 120, 116, 101, 110, 115, 105, 111, 110, 32, 109, 101, 115, 115, 97, 103, 101, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
}

//export OnKeyboardEvent
func OnKeyboardEvent(ev *C.nox_keyboard_btn_t) {
	if ev.state != 2 {
		return
	}
	if ((C.gameex_flags>>3)&1 != 0) && (ev.code == 26 || ev.code == 27) { // '[' and ']'
		v8 := byte(bool2int(ev.code == 26))
		// checks some gameFlags that are yet undiscovered
		if nox_common_gameFlags_check_40A5C0(0x204) {
			if C.dword_5d4594_1064868 != 0 || C.nox_win_unk3 != nil {
				return
			}
			if nox_common_gameFlags_check_40A5C0(1) { // isServer
				if u := HostPlayerUnit(); u != nil && C.mix_MouseKeyboardWeaponRoll(C.int(uintptr(unsafe.Pointer(u.CObj()))), C.char(v8)) != 0 {
					clientPlaySoundSpecial(895, 100)
				}
			} else {
				buf := alloc.Bytes(10)
				gameex_makeExtensionPacket(buf, 0, true)
				buf[8] = v8 | 0x10 // TODO: should it be just v8?
				C.gameex_sendPacket((*C.char)(unsafe.Pointer(&buf[0])), 9, 0)
				alloc.FreeBytes(buf)
			}
		}
	}
	if keybind.Key(ev.code) == gameex.keys.trap {
		if (C.gameex_flags>>3)&1 != 0 {
			if nox_common_gameFlags_check_40A5C0(516) {
				if C.dword_5d4594_1064868 != 0 || C.nox_win_unk3 != nil {
					return
				}
				if nox_common_gameFlags_check_40A5C0(1) { // checkGameFlags isServer
					v9 := C.nox_xxx_objGetTeamByNetCode_418C80(C.int(memmap.Uint32(0x5D4594, 2616328)))
					C.playerDropATrap(C.int(uintptr(unsafe.Pointer(v9)) - 12*4)) // TODO: this doesn't look right
				} else {
					buf := alloc.Bytes(10)
					gameex_makeExtensionPacket(buf, 9, true)
					C.gameex_sendPacket((*C.char)(unsafe.Pointer(&buf[0])), 8, 0)
					alloc.FreeBytes(buf)
				}
			}
		}
	}
	if ev.code == 66 { // F8
		if !nox_common_gameFlags_check_40A5C0(1) {
			C.nox_xxx_printCentered_445490(internWStr("only server can change these options"))
			clientPlaySoundSpecial(231, 100)
			return
		}
		if !nox_common_gameFlags_check_40A5C0(516) {
			return
		}
		clientPlaySoundSpecial(921, 100)
		if modifyWndPntr != nil {
			if err := gameexSaveConfig(); err != nil {
				gameex.Log.Println(err)
			}
			DestroyNoxWindow()
			modifyWndPntr = nil
		} else {
			modifyWndPntr = newWindowFromString(gameexModifWnd, unsafe.Pointer(C.modifyWndInputHandler))
			if modifyWndPntr == nil {
				return
			}
			if nox_common_gameFlags_check_40A5C0(512) {
				modifyWndPntr.ChildByID(1938).Hide()
				v11 := modifyWndPntr.ChildByID(1524)
				C.nox_xxx_wnd_46ABB0(C.int(uintptr(unsafe.Pointer(v11.C()))), 0)
			}
			C.sub_46B120(modifyWndPntr.C(), 0)
			a2b := modifyWndPntr.ChildByID(1981)
			for i := 0; i < 5; i++ {
				wstr := GoWStringSlice(wndEntryNames[i][:])
				id := uint(1520 + i)
				a2b.Func94(16397, uintptr(unsafe.Pointer(internWStr(wstr))), math.MaxUint32)
				if uint32(C.getFlagValueFromFlagIndex(C.int(id)-1519))&uint32(C.gameex_flags) != 0 {
					v14 := modifyWndPntr.ChildByID(id)
					v14.DrawData().field_0 |= 0x4
				} else {
					v15 := modifyWndPntr.ChildByID(id)
					v15.DrawData().field_0 &= 0xFFFFFFFB
				}
			}
		}
	}
	for i, k := range gameex.keys.panels {
		if keybind.Key(ev.code) == k {
			C.nox_xxx_clientUpdateButtonRow_45E110(C.int(i))
			break
		}
	}
}

func DestroyNoxWindow() {
	C.nox_xxx_wnd_46C6E0(C.int(uintptr(unsafe.Pointer(modifyWndPntr.C()))))
	C.nox_xxx_windowDestroyMB_46C4E0((*C.uint)(unsafe.Pointer(modifyWndPntr.C())))
	modifyWndPntr = nil
}

func gameexSaveConfig() error {
	path := gameex.configPath
	if path == "" {
		path = datapath.Path("game_ex.cfg")
	}
	gameex.Log.Println("saving config", path)
	f, err := fs.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()

	_, err = fmt.Fprintf(f, "AUTO_SHIELD = %d\r\n", bool2int((C.gameex_flags>>1)&1 != 0))
	if err != nil {
		return err
	}
	_, err = fmt.Fprintf(f, "GREAT_SWORD_BLOKING_WALK = %d\r\n", bool2int((C.gameex_flags>>2)&1 != 0))
	if err != nil {
		return err
	}
	_, err = fmt.Fprintf(f, "MOUSE_KEYBOARD_ROLL = %d\r\n", bool2int((C.gameex_flags>>3)&1 != 0))
	if err != nil {
		return err
	}
	_, err = fmt.Fprintf(f, "BERSERKER_SHIED_BLOCK = %d\r\n", bool2int((C.gameex_flags>>4)&1 != 0))
	if err != nil {
		return err
	}
	_, err = fmt.Fprintf(f, "EXTENSION_MESSAGES = %d\r\n", bool2int((C.gameex_flags>>5)&1 != 0))
	if err != nil {
		return err
	}
	for i, k := range gameex.keys.panels {
		s, err := gameexKeyName(k)
		if err != nil {
			return err
		}
		_, err = fmt.Fprintf(f, "PANEL%d = %s\r\n", i+1, s)
		if err != nil {
			return err
		}
	}
	s, err := gameexKeyName(gameex.keys.trap)
	if err != nil {
		return err
	}
	_, err = fmt.Fprintf(f, "TRAPKEY = %s\r\n", s)
	if err != nil {
		return err
	}
	_, err = f.WriteString("----------\r\n")
	if err != nil {
		return err
	}
	return f.Close()
}

//export modifyWndInputHandler
func modifyWndInputHandler(a1, a2, a3, a4 C.int) C.int {
	if a2 != 16391 {
		return 0
	}
	clientPlaySoundSpecial(766, 100)
	a3p := asWindow((*C.nox_window)(unsafe.Pointer(uintptr(a3))))
	switch a3p.ID() {
	case 1937:
		if err := gameexSaveConfig(); err != nil {
			gameex.Log.Println(err)
		}
		DestroyNoxWindow()
	case 1938:
		if !nox_common_gameFlags_check_40A5C0(512) {
			C.sub_4BDFD0()
			C.nox_wnd_nox_xxx_wndDraw_46A9B0((*C.nox_window)(unsafe.Pointer(uintptr(C.dword_5d4594_1316972))), 200, 100)
		}
	case 1520:
		if (C.gameex_flags>>1)&1 != 0 {
			C.gameex_flags &= 0xFFFFFFFD
		} else {
			C.gameex_flags |= 0x2
		}
	case 1521:
		if (C.gameex_flags>>2)&1 != 0 {
			C.gameex_flags &= 0xFFFFFFFB
		} else {
			C.gameex_flags |= 0x4
		}
	case 1522:
		if (C.gameex_flags>>3)&1 != 0 {
			C.gameex_flags &= 0xFFFFFFF7
		} else {
			C.gameex_flags |= 0x8
		}
	case 1523:
		if (C.gameex_flags>>4)&1 != 0 {
			C.gameex_flags &= 0xFFFFFFEF
		} else {
			C.gameex_flags |= 0x10
		}
	case 1524:
		if (C.gameex_flags>>5)&1 != 0 {
			C.gameex_flags &= 0xFFFFFFDF
		} else {
			C.gameex_flags |= 0x20
		}
	}
	return 0
}

const gameexModifWnd = `
ENABLEDCOLOR = TRANSPARENT;
HILITECOLOR = 255 192 192;
DISABLEDCOLOR = 128 128 128;
SELECTEDCOLOR = 255 128 128;
TEXTCOLOR = 255 255 255;
BACKGROUNDCOLOR = 0 0 0;

WINDOW
  1930 50 55 200 150 USER;
  STATUS = ENABLED+ABOVE+BORDER;

  CHILD
	WINDOW
	  1520 8 22 15 10 CHECKBOX (Object allowed);
      STATUS = ENABLED+IMAGE;
	  STYLE = MOUSETRACK;
	  SELECTEDIMAGE = UICheckBoxLit;
	  HILITEIMAGE = NULL;
	  BACKGROUNDIMAGE = UICheckBox;
	  ENABLEDIMAGE = NULL;
	  DISABLEDIMAGE = UICheckBoxDis;
	  TOOLTIP = objlst.wnd:ToggleTT;
	END

	WINDOW
	  1521 8 32 15 10 CHECKBOX (Object allowed);
      STATUS = ENABLED+IMAGE;
	  SELECTEDIMAGE = UICheckBoxLit;
	  HILITEIMAGE = NULL;
	  BACKGROUNDIMAGE = UICheckBox;
	  ENABLEDIMAGE = NULL;
	  DISABLEDIMAGE = UICheckBoxDis;
	  STYLE = MOUSETRACK;
	  TOOLTIP = objlst.wnd:ToggleTT;
	END

	WINDOW
	  1522 8 42 15 10 CHECKBOX (Object allowed);
      STATUS = ENABLED+IMAGE;
	  SELECTEDIMAGE = UICheckBoxLit;
	  HILITEIMAGE = NULL;
	  BACKGROUNDIMAGE = UICheckBox;
	  ENABLEDIMAGE = NULL;
	  DISABLEDIMAGE = UICheckBoxDis;
	  STYLE = MOUSETRACK;
	  TOOLTIP = objlst.wnd:ToggleTT;
	END

	WINDOW
	  1523 8 52 15 10 CHECKBOX (Object allowed);
      STATUS = ENABLED+IMAGE;
	  SELECTEDIMAGE = UICheckBoxLit;
	  HILITEIMAGE = NULL;
	  BACKGROUNDIMAGE = UICheckBox;
	  ENABLEDIMAGE = NULL;
	  DISABLEDIMAGE = UICheckBoxDis;
	  STYLE = MOUSETRACK;
	  TOOLTIP = objlst.wnd:ToggleTT;
	END

	WINDOW
	  1524 8 62 15 10 CHECKBOX (Object allowed);
      STATUS = ENABLED+IMAGE;
	  SELECTEDIMAGE = UICheckBoxLit;
	  HILITEIMAGE = NULL;
	  BACKGROUNDIMAGE = UICheckBox;
	  ENABLEDIMAGE = NULL;
	  DISABLEDIMAGE = UICheckBoxDis;
	  STYLE = MOUSETRACK;
	  TOOLTIP = objlst.wnd:ToggleTT;
	END

        WINDOW
          1937 65 120 70 20 PUSHBUTTON;
          STATUS = ENABLED+IMAGE;
          STYLE = MOUSETRACK+TABSTOP;
	  SELECTEDIMAGE = UIButtonLgLit;
	  HILITEIMAGE = UIButtonLgLit;
	  BACKGROUNDIMAGE = UIButtonLg;
	  ENABLEDIMAGE = NULL;
	  DISABLEDIMAGE = UIButtonLgDis;
          TEXT = WolFind.wnd:Done;
       END

        WINDOW
          1938 115 80 70 20 PUSHBUTTON;
          STATUS = ENABLED+IMAGE;
          STYLE = MOUSETRACK+TABSTOP;
	  SELECTEDIMAGE = UIButtonLgLit;
	  HILITEIMAGE = UIButtonLgLit;
	  BACKGROUNDIMAGE = UIButtonLg;
	  ENABLEDIMAGE = NULL;
	  DISABLEDIMAGE = UIButtonLgDis;
          TEXT = servopts.wnd:Advanced;
       END

        WINDOW
          1981 22 21 150 60 SCROLLLISTBOX
          STATUS = ONE_LINE;
          DISABLEDCOLOR = TRANSPARENT;
          DATA = 26 10 0 1 0 0 1;
          FONT = default;
       END
END
`
