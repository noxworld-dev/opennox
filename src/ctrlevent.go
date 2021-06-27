package main

/*
#include "proto.h"
#include "client__system__ctrlevnt.h"
#include "client__gui__guicon.h"
#include "client__gui__guisave.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"

extern unsigned int nox_client_renderGUI_80828;
extern unsigned int nox_xxx_xxxRenderGUI_587000_80832;

int nox_ctrlevent_add_ticks_42E630();
*/
import "C"
import (
	"bufio"
	"encoding/binary"
	"fmt"
	"io"
	"math"
	"strings"
	"unsafe"

	"nox/v1/client/input/keybind"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/memmap"
	"nox/v1/common/types"
)

var ctrlEvent = new(CtrlEventHandler)

const ctrlEventCap = 128

type noxCtrlEvent struct {
	tick   uint32
	code   byte
	data   [4]byte
	active bool
}

type CtrlEventBinding struct {
	keys    []keybind.Key
	events  []keybind.Event
	prev    *CtrlEventBinding
	next    *CtrlEventBinding
	field20 *CtrlEventBinding
	field21 *CtrlEventBinding
	flag22  bool
	frame   uint32
}

func (c *CtrlEventBinding) defKey() keybind.Key {
	if len(c.keys) == 0 {
		return 0
	}
	return c.keys[0]
}

func (c *CtrlEventBinding) defEvent() keybind.Event {
	if len(c.events) == 0 {
		return 0
	}
	return c.events[0]
}

type CtrlEventHandler struct {
	ticks     uint32
	playerDir uint32
	bufA      [ctrlEventCap]noxCtrlEvent
	bufB      [ctrlEventCap]noxCtrlEvent // TODO: size a guess
	bindings  *CtrlEventBinding
	indA      int
	indB      int
	indC      int
	indD      int
}

func (c *CtrlEventHandler) Reset() {
	c.bindings = nil
	*memmap.PtrUint8(0x5D4594, 747848) = 0
	*memmap.PtrUint8(0x5D4594, 750956) = 0
	c.indA = 0
	c.indB = 0
	c.indC = 0
	c.indD = 0
	*memmap.PtrUint32(0x5D4594, 747856) = 100
	*memmap.PtrUint32(0x5D4594, 747868) = 4
}

func (c *CtrlEventHandler) nox_xxx_clientControl_42D6B0(mpos types.Point, a4 *CtrlEventBinding) {
	c.ticks = uint32(platformTicks())
	if noxflags.HasGame(noxflags.GameHost) && noxflags.HasGame(0x2000) {
		c.ticks += nox_ctrlevent_add_ticks_42E630()
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		c.indA = 0
	}
	c.nox_xxx_clientControl_42D6B0_A(a4)
	c.nox_xxx_clientControl_42D6B0_orientation(mpos)
	if memmap.Uint8(0x5D4594, 2661958) != 0 {
		C.nox_xxx_guiSpellTargetClickCheckSend_45DBB0()
	}
	if memmap.Uint8(0x5D4594, 754064)&4 != 0 {
		c.nox_ctrlevent_action_42E670(CC_CastMostRecentSpell, nil)
	}
	c.nox_xxx_clientControl_42D6B0_C()
	*memmap.PtrUint32(0x5D4594, 754064) = 0
	c.nox_xxx_clientControl_42D6B0_B()
}

func (c *CtrlEventHandler) nox_xxx_clientControl_42D6B0_orientation(mpos types.Point) {
	if memmap.Uint8(0x5D4594, 747848) != 2 && memmap.Uint32(0x5D4594, 747868) == 4 {
		// calculates player orientation
		x := mpos.X
		y := mpos.Y
		if v15 := C.nox_xxx_spriteGetMB_476F80(); v15 != nil {
			y = int(C.sub_4739D0(*(*C.int)(unsafe.Pointer(uintptr(v15) + 16))))
		}
		wsz := videoGetWindowSize()
		cx := x - wsz.W/2
		cy := y - wsz.H/2
		rad := math.Atan2(float64(cy), float64(cx))
		if inpHandler.Gamepad().InRelative() {
			p := inpHandler.Gamepad().StickRel().Posf()
			rad = math.Atan2(float64(p.Y), float64(p.X))
		}
		// represent as integer
		ang := int((rad+2*math.Pi)*128.0/math.Pi + 0.5)
		if ang < 0 {
			ang += int((uint(255-ang) >> 8) << 8)
		}
		if ang >= 256 {
			ang -= int((uint(ang) >> 8) << 8)
		}
		c.playerDir = uint32(ang)
	}
	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:], c.playerDir)
	c.nox_ctrlevent_action_42E670(CC_Orientation, &buf)
}

func (c *CtrlEventHandler) nox_xxx_clientControl_42D6B0_A(a4 *CtrlEventBinding) {
	v2 := *memmap.PtrPtr(0x5D4594, 2618908)
	for it := a4; it != nil; it = it.field21 {
		for _, k := range it.events {
			switch k {
			case 1:
				switch nox_client_getCursorType_477620() {
				case 3:
					v10 := nox_xxx_clientGetSpriteAtCursor_476F90()
					C.nox_xxx_clientTrade_42E850(v10.C())
				case 4:
					v11 := nox_xxx_clientGetSpriteAtCursor_476F90()
					if v11.Flags70()&0x10 != 0 {
						C.nox_xxx_clientTalk_42E7B0(v11.C())
					}
				case 13:
					v12 := nox_xxx_clientGetSpriteAtCursor_476F90()
					C.nox_xxx_clientCollideOrUse_42E810(v12.C())
				default:
					c.nox_ctrlevent_action_42E670(CC_Action, nil)
				}
			case 2:
				if inpHandler.IsMouseDown() {
					v5 := 1
					if memmap.Uint8(0x5D4594, 754064)&0x8 != 0 {
						v5 = 3
					}
					var buf [4]byte
					binary.LittleEndian.PutUint32(buf[:], uint32(v5))
					c.nox_ctrlevent_action_42E670(CC_MoveForward, &buf)
				}
			case 3, 4, 5:
				var code byte
				switch k {
				case 3:
					code = CC_MoveBackward
				case 4:
					code = CC_MoveLeft
				case 5:
					code = CC_MoveRight
				}
				v6 := uint32(bool2int(memmap.Uint8(0x5D4594, 754064)&0x1 != 0))
				if memmap.Uint8(0x5D4594, 754064)&0x8 != 0 {
					v6 |= 2
				}
				var buf [4]byte
				binary.LittleEndian.PutUint32(buf[:], v6)
				c.nox_ctrlevent_action_42E670(code, &buf)
			case 6:
				c.nox_ctrlevent_action_42E670(CC_Jump, nil)
			case 7:
				c.nox_ctrlevent_action_42E670(CC_SpellGestureDown, nil)
			case 8:
				c.nox_ctrlevent_action_42E670(CC_Chat, nil)
			case 9:
				if *(*byte)(unsafe.Pointer(uintptr(v2) + 3680))&0x1 == 0 {
					c.nox_ctrlevent_action_42E670(CC_TeamChat, nil)
				}
			case 0xA:
				c.nox_ctrlevent_action_42E670(CC_ReadSpellbook, nil)
			case 0xB:
				c.nox_ctrlevent_action_42E670(CC_ToggleConsole, nil)
			case 0xC:
				if !nox_xxx_checkGameFlagPause_413A50() {
					c.nox_ctrlevent_action_42E670(CC_IncreaseWindowSize, nil)
				}
			case 0xD:
				if !nox_xxx_checkGameFlagPause_413A50() {
					c.nox_ctrlevent_action_42E670(CC_DecreaseWindowSize, nil)
				}
			case 0xE:
				c.nox_ctrlevent_action_42E670(CC_Quit, nil)
			case 0xF:
				c.nox_ctrlevent_action_42E670(CC_QuitMenu, nil)
			case 0x10:
				c.nox_ctrlevent_action_42E670(CC_SpellGestureUp, nil)
			case 0x11:
				if !nox_xxx_guiSpellTest_45D9C0() {
					v13 := C.nox_xxx_packetGetMarshall_476F40()
					var b [4]byte
					binary.LittleEndian.PutUint32(b[:], uint32(v13))
					c.nox_ctrlevent_action_42E780(CC_CastSpell1, &b)
				}
			case 0x12:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(CC_SpellGestureLeft, nil)
				}
			case 0x13:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(CC_SpellGestureRight, nil)
				}
			case 0x14:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(CC_SpellGestureUpperRight, nil)
				}
			case 0x15:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(CC_SpellGestureUpperLeft, nil)
				}
			case 0x16:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(CC_SpellGestureLowerRight, nil)
				}
			case 0x17:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(CC_SpellGestureLowerLeft, nil)
				}
			case 0x18:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(CC_SpellPatternEnd, nil)
				}
			case 0x19:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(CC_CastQueuedSpell, nil)
				}
			case 0x1A:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(CC_CastMostRecentSpell, nil)
				}
			case 0x1B:
				if !nox_xxx_guiSpellTest_45D9C0() {
					v14 := C.nox_xxx_packetGetMarshall_476F40()
					var b [4]byte
					binary.LittleEndian.PutUint32(b[:], uint32(v14))
					c.nox_ctrlevent_action_42E780(CC_CastSpell2, &b)
				}
			case 0x1C:
				c.nox_ctrlevent_action_42E780(CC_CastSpell3, nil)
			case 0x1D:
				c.nox_ctrlevent_action_42E780(CC_CastSpell4, nil)
			case 0x1E:
				c.nox_ctrlevent_action_42E780(CC_CastSpell5, nil)
			case 0x1F:
				c.nox_ctrlevent_action_42E780(CC_MapZoomIn, nil)
			case 0x20:
				c.nox_ctrlevent_action_42E780(CC_MapZoomOut, nil)
			case 0x21:
				c.nox_ctrlevent_action_42E670(CC_NextWeapon, nil)
			case 0x22:
				c.nox_ctrlevent_action_42E670(CC_QuickHealthPotion, nil)
			case 0x23:
				c.nox_ctrlevent_action_42E780(CC_QuickManaPotion, nil)
			case 0x24:
				c.nox_ctrlevent_action_42E780(CC_QuickCurePoisonPotion, nil)
			case 0x25:
				c.nox_ctrlevent_action_42E780(CC_NextSpellSet, nil)
			case 0x26:
				c.nox_ctrlevent_action_42E780(CC_PreviousSpellSet, nil)
			case 0x27:
				c.nox_ctrlevent_action_42E780(CC_SelectSpellSet, nil)
			case 0x28:
				c.nox_ctrlevent_action_42E780(CC_BuildTrap, nil)
			case 0x29:
				c.nox_ctrlevent_action_42E780(CC_ServerOptions, nil)
			case 0x2A:
				c.nox_ctrlevent_action_42E780(CC_Taunt, nil)
			case 0x2B:
				c.nox_ctrlevent_action_42E670(CC_ReadMap, nil)
			case 0x2C:
				c.nox_ctrlevent_action_42E670(CC_Inventory, nil)
			case 0x2D:
				c.nox_ctrlevent_action_42E670(CC_Laugh, nil)
			case 0x2E:
				if noxflags.HasGame(0x2000) && nox_xxx_checkKeybTimeout_4160F0(0x15, gameFPS()) {
					nox_xxx_setKeybTimeout_4160D0(21)
					c.nox_ctrlevent_action_42E670(CC_Point, nil)
				}
			case 0x2F:
				if noxflags.HasGame(0x2000) && nox_xxx_checkKeybTimeout_4160F0(0x14, 2*gameFPS()) {
					nox_xxx_setKeybTimeout_4160D0(20)
					c.nox_ctrlevent_action_42E670(CC_InvertSpellTarget, nil)
				}
			case 0x30:
				if noxflags.HasGame(0x2000) && nox_xxx_checkKeybTimeout_4160F0(0x16, gameFPS()) {
					nox_xxx_setKeybTimeout_4160D0(22)
					c.nox_ctrlevent_action_42E670(CC_ToggleRank, nil)
				}
			case 0x31:
				c.nox_ctrlevent_action_42E670(CC_ToggleNetstat, nil)
			case 0x32:
				if noxflags.HasGame(0x2000) {
					c.nox_ctrlevent_action_42E670(CC_ToggleGUI, nil)
				}
			case 0x33:
				if !nox_xxx_checkGameFlagPause_413A50() {
					c.nox_ctrlevent_action_42E670(CC_AutoSave, nil)
				}
			case 0x34:
				c.nox_ctrlevent_action_42E670(CC_AutoLoad, nil)
			case 0x35:
				if noxflags.HasGame(2048) && !nox_xxx_guiCursor_477600() {
					c.nox_ctrlevent_action_42E670(CC_ScreenShot, nil)
				}
			case 0x36:
				if noxflags.HasGame(2048) && !nox_xxx_guiCursor_477600() {
					c.nox_ctrlevent_action_42E670(CC_Unknown55, nil)
				}
			case 0x37:
				c.nox_ctrlevent_action_42E670(CC_Unknown56, nil)
			}
		}
	}
}

func sub_476E00(a1 int) {
	*memmap.PtrUint32(0x5D4594, 1096596+4*uintptr(a1)) = gameFrame()
}

func (c *CtrlEventHandler) nox_xxx_clientControl_42D6B0_B() {
	indStart := 0
	indEnd := 0
	if noxflags.HasGame(noxflags.GameHost) {
		indStart = c.indB
		indEnd = c.indA
		if c.indA < c.indB {
			indEnd = c.indA + cap(c.bufA)
		}
	} else {
		indEnd = c.indA
	}
	for i := indStart; i < indEnd; i++ {
		ce := &c.bufA[i%cap(c.bufA)]
		if !ce.active {
			continue
		}
		switch ce.code {
		case 0x14:
			if !noxflags.HasGame(128) {
				clientPlaySoundSpecial(186, 100)
				sub_476E00(1)
			}
		case 0x15:
			if !noxflags.HasGame(128) {
				clientPlaySoundSpecial(190, 100)
				sub_476E00(6)
			}
		case 0x16:
			if !noxflags.HasGame(128) {
				clientPlaySoundSpecial(192, 100)
				sub_476E00(3)
			}
		case 0x17:
			if !noxflags.HasGame(128) {
				clientPlaySoundSpecial(188, 100)
				sub_476E00(4)
			}
		case 0x18:
			if !noxflags.HasGame(128) {
				clientPlaySoundSpecial(187, 100)
				sub_476E00(2)
			}
		case 0x19:
			if !noxflags.HasGame(128) {
				clientPlaySoundSpecial(193, 100)
				sub_476E00(0)
			}
		case 0x1A:
			if !noxflags.HasGame(128) {
				clientPlaySoundSpecial(189, 100)
				sub_476E00(7)
			}
		case 0x1B:
			if !noxflags.HasGame(128) {
				clientPlaySoundSpecial(191, 100)
				sub_476E00(5)
			}
		}
		v37 := ce.code
		switch v37 {
		case 8:
			C.sub_46A430(0)
			ce.active = false
		case 9:
			C.sub_46A430(1)
			ce.active = false
		case 10:
			C.sub_45AC70()
			ce.active = false
		case 11:
			C.nox_gui_console_F1_451350()
			ce.active = false
		case 12:
			clientPlaySoundSpecial(921, 100)
			C.sub_4766E0()
			ce.active = false
		case 13:
			clientPlaySoundSpecial(921, 100)
			C.sub_4766F0()
			ce.active = false
		case 14:
			clientPlaySoundSpecial(921, 100)
			v38 := C.nox_video_getGammaSetting_434B00()
			C.nox_video_setGammaSetting_434B30(v38 + 1)
			C.updateGamma(1)
			C.sub_434B60()
			ce.active = false
		case 15:
			clientPlaySoundSpecial(921, 100)
			v39 := C.nox_video_getGammaSetting_434B00()
			C.nox_video_setGammaSetting_434B30(v39 - 1)
			C.updateGamma(-1)
			C.sub_434B60()
			ce.active = false
		case 16:
			C.nox_xxx_quit_4460C0()
			ce.active = false
		case 17:
			if C.sub_450560() != 0 {
				C.nox_savegame_sub_46D580()
			} else {
				C.sub_42EB90(1)
			}
			ce.active = false
		case 18:
			C.sub_473610()
			ce.active = false
		case 19:
			C.sub_467C60()
			ce.active = false
		case 31, 32, 33, 34, 35:
			C.nox_xxx_clientUseQWEButton_45DA50(C.int(v37) - 31)
			ce.active = false
		case 36:
			C.sub_4724E0()
			ce.active = false
		case 37:
			C.sub_472500()
			ce.active = false
		case 38:
			C.nox_client_invAlterWeapon_4672C0()
			ce.active = false
		case 39:
			C.sub_472220()
			ce.active = false
		case 40:
			C.sub_472240()
			ce.active = false
		case 41:
			C.sub_472260()
			ce.active = false
		case 42:
			C.nox_xxx_spellNext_4604F0()
			ce.active = false
		case 43:
			C.nox_xxx_spellPrev_460540()
			ce.active = false
		case 44:
			C.nox_xxx_spellReset_460590()
			ce.active = false
		case 45:
			C.nox_xxx_clientUseTrap_45E040()
			ce.active = false
		case 46:
			if !(noxflags.HasGame(8) || !noxflags.HasGame(0x2000)) {
				C.nox_xxx_guiServerOptsLoad_457500()
			}
			ce.active = false
		case 47:
			var buf [2]byte
			binary.LittleEndian.PutUint16(buf[:], 739)
			nox_xxx_netClientSend2_4E53C0(31, buf[:], 0, 1)
		case 48:
			var buf [2]byte
			binary.LittleEndian.PutUint16(buf[:], 483)
			nox_xxx_netClientSend2_4E53C0(31, buf[:], 0, 1)
		case 49:
			var buf [2]byte
			buf[0] = 0xE3
			buf[1] = 4
			nox_xxx_netClientSend2_4E53C0(31, buf[:], 0, 1)
		case 50:
			C.sub_460630()
			ce.active = false
		case 51:
			clientPlaySoundSpecial(921, 100)
			C.sub_4703F0()
			ce.active = false
		case 52:
			C.sub_470A60()
			clientPlaySoundSpecial(921, 100)
			ce.active = false
		case 53:
			if !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
				C.nox_client_renderGUI_80828 ^= 1
				C.nox_xxx_xxxRenderGUI_587000_80832 = C.nox_client_renderGUI_80828
				clientPlaySoundSpecial(921, 100)
			}
			ce.active = false
		case 54:
			if noxflags.HasGame(2048) {
				if C.nox_xxx_game_4DCCB0() != 0 {
					clientPlaySoundSpecial(921, 100)
					C.sub_4DB130(internCStr("AUTOSAVE"))
					C.sub_4DB170(1, 0, 0)
				} else {
					clientPlaySoundSpecial(231, 100)
				}
			}
			ce.active = false
		case 55:
			if noxflags.HasGame(2048) {
				if C.nox_xxx_game_4DCCB0() != 0 {
					clientPlaySoundSpecial(921, 100)
					C.sub_413A00(1)
					v41 := strMan.GetStringInFile("GUIQuit.c:ReallyLoadMessage", "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c")
					v40 := strMan.GetStringInFile("SelChar.c:LoadLabel", "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c")
					NewDialogWindow(nil, v40, v41, 56, C.sub_42E600, C.sub_42E620)
				} else {
					clientPlaySoundSpecial(231, 100)
				}
			}
			ce.active = false
		case 56:
			C.nox_xxx_saveScreenshot_46DB00()
			ce.active = false
		}
	}
}

func (c *CtrlEventHandler) nox_xxx_clientControl_42D6B0_C() {
	if noxflags.HasGame(noxflags.GameHost) {
		v20 := c.indB
		cnt := 0
		for i := c.indD; i != v20; i = (i + 1) % cap(c.bufA) {
			c.bufB[cnt] = c.bufA[i]
			cnt++
		}
		if cnt > 0 {
			c.indD = v20
			c.indC = cnt
		}
		v23 := c.indC
		for i := v20; i != c.indA; i = (i + 1) % cap(c.bufA) {
			if v23 <= 0 {
				continue
			}
			p1 := &c.bufA[i]
			for j := 0; j < v23; j++ {
				p2 := &c.bufB[j]
				if p1.code == p2.code {
					if nox_xxx_keyCanPauseMode_42D4B0(p1.code) {
						p1.active = false
					}
					v23 = c.indC
					break
				}
			}
		}
	} else {
		for i := 0; i < c.indA; i++ {
			p1 := &c.bufA[i]
			p1.active = true
			if c.indC <= 0 {
				continue
			}
			for j := 0; j < c.indC; j++ {
				p2 := &c.bufB[j]
				if p1.code == p2.code {
					if nox_xxx_keyCanPauseMode_42D4B0(p1.code) {
						p1.active = false
					}
					break
				}
			}
		}
		n := c.indA
		copy(c.bufB[:n], c.bufA[:n])
		c.indC = c.indA
	}
}

func (c *CtrlEventHandler) nox_ctrlevent_action_42E670(code byte, data *[4]byte) {
	if !noxflags.HasGame(noxflags.GameHost) {
		if c.indA >= cap(c.bufA) {
			return
		}
	} else {
		if c.indA+1 == c.indB {
			return
		}
	}
	if memmap.Uint8(0x5D4594, 2661958) != 0 || !nox_xxx_keyCheckWarrorKeys_42D460(code) {
		j := c.indA
		if noxflags.HasGame(noxflags.GameHost) && nox_xxx_keyCanPauseMode_42D4B0(code) {
			for i := c.indB; i != c.indA; i = (i + 1) % cap(c.bufA) {
				if c.bufA[i].code == code {
					return
				}
			}
		}
		p := &c.bufA[j]
		p.tick = c.ticks
		p.code = code
		if data != nil {
			p.data = *data
		} else {
			p.data = [4]byte{}
		}
		p.active = true
		c.indA = j + 1
		if noxflags.HasGame(noxflags.GameHost) {
			c.indA %= cap(c.bufA)
		}
	}
}

func (c *CtrlEventHandler) nox_ctrlevent_action_42E780(code byte, data *[4]byte) {
	if p := *memmap.PtrPtr(0x5D4594, 2614252); p != nil && *(*byte)(unsafe.Pointer(uintptr(p) + 120))&2 == 0 {
		if !nox_xxx_checkGameFlagPause_413A50() {
			c.nox_ctrlevent_action_42E670(code, data)
		}
	}
}

func nox_ctrlevent_add_ticks_42E630() uint32 {
	v0 := C.sub_416640()
	switch *(*uint32)(unsafe.Pointer(uintptr(v0) + 66)) {
	case 1:
		return uint32(C.sub_554290())
	case 2:
		return uint32(C.sub_554300())
	case 3:
		return *(*uint32)(unsafe.Pointer(uintptr(v0) + 70))
	}
	return 0
}

//export sub_42E8E0
func sub_42E8E0(key, a2 C.int) *C.wchar_t {
	s := ctrlEvent.sub_42E8E0_go(keybind.Event(key), int(a2))
	return internWStr(s)
}

func (c *CtrlEventHandler) sub_42E8E0_go(ev keybind.Event, ind int) string {
	for v2 := c.bindings; v2 != nil; v2 = v2.next {
		for _, e := range v2.events {
			if e != ev {
				continue
			}
			ind--
			if ind <= 0 {
				if key := v2.defKey(); key.IsValid() {
					return key.Title(strMan)
				}
			}
		}
	}
	return ""
}

func (c *CtrlEventHandler) addBinding(ce *CtrlEventBinding) {
	ce.prev = nil
	ce.next = c.bindings
	if c.bindings != nil {
		c.bindings.prev = ce
	}
	c.bindings = ce
}

func (c *CtrlEventHandler) listBindings() []*CtrlEventBinding {
	var tail *CtrlEventBinding
	for it := c.bindings; it != nil; it = it.next {
		tail = it
	}
	if tail == nil {
		return nil
	}
	var out []*CtrlEventBinding
	for it := tail; it != nil; it = it.prev {
		out = append(out, it)
	}
	return out
}

//export nox_client_parseConfigHotkeysLine_42CF50
func nox_client_parseConfigHotkeysLine_42CF50(a1 *C.char) C.int {
	*memmap.PtrUint32(0x5D4594, 747868) = 4
	*memmap.PtrUint8(0x5D4594, 747848) = 0
	r := strings.NewReader(GoString(a1))
	sc := bufio.NewScanner(r)
	for sc.Scan() {
		line := strings.TrimSpace(sc.Text())
		if len(line) == 0 || line[0] == '-' || line[0] == '#' {
			continue
		}
		i := strings.IndexByte(line, '=')
		if i < 0 {
			inputLog.Printf("invalid config line: %q", line)
			continue
		}
		key, val := strings.TrimSpace(line[:i]), strings.TrimSpace(line[i+1:])
		switch key {
		case "MousePickup":
			val = strings.ToLower(val)
			for i, s := range noxMouseSelectOpt {
				if val == strings.ToLower(s) {
					C.sub_430AA0(C.int(i))
					return 1
				}
			}
			C.sub_430AA0(0)
			return 1
		}
		ce := new(CtrlEventBinding)
		for _, s := range strings.Split(key, "+") {
			s = strings.TrimSpace(s)
			if k := keybind.KeyByName(s); k != 0 {
				ce.keys = append(ce.keys, k)
			}
		}
		for _, s := range strings.Split(val, "+") {
			s = strings.TrimSpace(s)
			if b := keyBinding.EventByName(s); b != nil && b.Event != 0 {
				ce.events = append(ce.events, b.Event)
			}
		}
		ctrlEvent.addBinding(ce)
		return 1
	}
	return 0
}

func writeConfigHotkeys(w io.Writer) error {
	v1 := int(C.nox_client_mousePriKey_430AF0())
	_, err := fmt.Fprintf(w, "MousePickup = %s\r\n", noxMouseSelectOpt[v1])
	if err != nil {
		return err
	}
	for _, it := range ctrlEvent.listBindings() {
		first := true
		for _, k := range it.keys {
			if !k.IsValid() {
				continue
			}
			_, err = fmt.Fprintf(w, "%s ", k.String())
			if err != nil {
				return err
			}
			if !first {
				if _, err = io.WriteString(w, "+ "); err != nil {
					return err
				}
			}
			first = false
		}
		if _, err = io.WriteString(w, "= "); err != nil {
			return err
		}
		first = true
		for _, k := range it.events {
			if b := keyBinding.EventByCode(k); b != nil && b.Name != "" {
				_, err = fmt.Fprintf(w, "%s ", b.Name)
				if err != nil {
					return err
				}
				if !first {
					if _, err = io.WriteString(w, "+ "); err != nil {
						return err
					}
				}
				first = false
			}
		}
		if _, err = io.WriteString(w, "\n"); err != nil {
			return err
		}
	}
	return nil
}

//export nox_client_writeConfigHotkeys_42CDF0
func nox_client_writeConfigHotkeys_42CDF0(h *C.FILE) {
	f := fileByHandle(h)
	if f == nil {
		inputLog.Println("cannot save config: empty file handle")
		return
	}
	if err := writeConfigHotkeys(f.File); err != nil {
		inputLog.Println("cannot save config:", err)
		return
	}
}

//export sub_42CD90
func sub_42CD90() {
	ctrlEvent.Reset()
}

var (
	noxCtrlEventNetbufSize byte
	noxCtrlEventNetbuf     [256]byte // TODO: size is a guess
)

func (c *CtrlEventHandler) writeToNetBuffer() { // nox_xxx_netBuf_42D510
	bufSize := &noxCtrlEventNetbufSize
	buf := noxCtrlEventNetbuf[:]
	ticks := uint32(platformTicks())
	*bufSize = 0
	if noxflags.HasGame(noxflags.GameHost) {
		for i := c.indB; i != c.indA; i = (i + 1) % cap(c.bufA) {
			p := &c.bufA[i]
			if p.tick > ticks+50 {
				break
			}
			if !p.active {
				continue
			}
			off := *bufSize
			buf[off] = p.code & 0xff
			*bufSize = off + 4
			if p.HasData() {
				sz := p.DataSize()
				off = *bufSize
				copy(buf[off:], p.data[:sz])
				*bufSize += byte(sz)
			}
		}
		c.indB = c.indA
	} else {
		for i := 0; i < c.indA; i++ {
			p := &c.bufA[i]
			if !p.active {
				continue
			}
			off := *bufSize
			buf[off] = p.code & 0xff
			*bufSize = off + 4
			if p.HasData() {
				sz := p.DataSize()
				off = *bufSize
				copy(buf[off:], p.data[:sz])
				*bufSize += byte(sz)
			}
		}
	}
}

//export nox_xxx_playerSaveInput_51A960
func nox_xxx_playerSaveInput_51A960(a1 C.int, a2 *C.uchar) C.int {
	pl := getPlayerByInd(int(a1))
	v3 := *a2 // TODO: size of the rest of a2?
	if pl != nil && *(*byte)(pl.field(3680))&0x10 == 0 {
		return C.int(v3) + 1
	}
	a2s := asByteSlice(unsafe.Pointer(a2), int(v3)+1)
	var buf [3072]byte
	v5 := uint32(sub_51AAA0(a2s[1:], buf[:]))
	v6 := memmap.Uint32(0x5D4594, 2388804+4*uintptr(a1))
	if v6+v5 < 128 {
		*memmap.PtrUint32(0x5D4594, 2388804+4*uintptr(a1)) = v6 + v5
		tsz := int(24 * v5)
		copy(asByteSlice(memmap.PtrOff(0x5D4594, 2388932+24*(uintptr(v6)+(uintptr(a1)<<7))), tsz), buf[:tsz])
	}
	C.sub_51AA20(a1)
	return C.int(v3) + 1
}

func (c *CtrlEventHandler) hasDefBinding(ev keybind.Event, key keybind.Key) bool {
	for it := c.bindings; it != nil; it = it.next {
		if it.defEvent() == ev && it.defKey() == key {
			return true
		}
	}
	return false
}

func sub_51AAA0(a1 []byte, a3 []byte) int {
	cnt := 0
	v5 := a3[8:]
	for off := 0; off < len(a1); {
		code := a1[off]
		off += 4
		binary.LittleEndian.PutUint32(v5[0:], uint32(code))
		binary.LittleEndian.PutUint32(v5[4:], 0)
		if nox_ctrlevent_has_data_42D440(code) {
			v7 := nox_ctrlevent_data_size_42D450(code)
			copy(v5[4:4+v7], a1[off:])
			off += v7
		}
		binary.LittleEndian.PutUint32(v5[8:], 1)
		cnt++
		v5 = v5[24:]
	}
	return cnt
}
