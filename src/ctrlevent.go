package nox

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME4_1.h"
#include "GAME5_2.h"
#include "client__video__draw_common.h"
#include "client__gui__guicon.h"
#include "client__gui__guisave.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"

extern unsigned int nox_client_renderGUI_80828;
extern unsigned int nox_xxx_xxxRenderGUI_587000_80832;
extern void* nox_gui_itemAmount_dialog_1319228;
extern int nox_players_controlBuffer_2388804[NOX_PLAYERINFO_MAX];
extern nox_player_ctrl_t nox_players_controlBuffer_2388932[NOX_PLAYERINFO_MAX][128];

int nox_ctrlevent_add_ticks_42E630();
void nox_client_orderCreature(int creature, int command);
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

	"nox/v1/client"
	"nox/v1/client/input"
	"nox/v1/common"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/keybind"
	"nox/v1/common/memmap"
	"nox/v1/common/types"
)

var (
	ctrlEvent           = new(CtrlEventHandler)
	allowEmotionsInSolo = true
)

func init() {
	configBoolPtr("game.extensions.solo_allow_emotes", "", true, &allowEmotionsInSolo)
}

const ctrlEventCap = 128

type noxCtrlEvent struct {
	tick   uint32
	code   client.CtrlCode
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
	if noxflags.HasGame(noxflags.GameHost) && noxflags.HasGame(noxflags.GameOnline) {
		c.ticks += nox_ctrlevent_add_ticks_42E630()
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		c.indA = 0
	}
	c.nox_xxx_clientControl_42D6B0_A(a4)
	c.nox_xxx_clientControl_42D6B0_orientation(mpos)
	if memmap.Uint8(0x85B3FC, 12254) != 0 {
		C.nox_xxx_guiSpellTargetClickCheckSend_45DBB0()
	}
	if memmap.Uint8(0x5D4594, 754064)&4 != 0 {
		c.nox_ctrlevent_action_42E670(client.CCSpellPatternEnd, nil)
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
		if v15 := nox_xxx_spriteGetMB_476F80(); v15 != nil {
			y = int(C.sub_4739D0(C.int(v15.Pos().Y)))
		}
		wsz := videoGetWindowSize()
		cx := x - wsz.W/2
		cy := y - wsz.H/2
		rad := math.Atan2(float64(cy), float64(cx))

		// TODO: support gamepad again
		//if inpHandler.Gamepad().InRelative() {
		//	p := inpHandler.Gamepad().StickRel().Posf()
		//	rad = math.Atan2(float64(p.Y), float64(p.X))
		//}

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
	c.nox_ctrlevent_action_42E670(client.CCOrientation, &buf)
}

func (c *CtrlEventHandler) nox_xxx_clientControl_42D6B0_A(a4 *CtrlEventBinding) {
	v2 := *memmap.PtrPtr(0x8531A0, 2576)
	for it := a4; it != nil; it = it.field21 {
		for _, k := range it.events {
			switch k {
			case keybind.EventAction:
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
					c.nox_ctrlevent_action_42E670(client.CCAction, nil) // regular attack?
				}
			case keybind.EventMoveForward:
				v5 := 1
				if memmap.Uint8(0x5D4594, 754064)&0x8 != 0 {
					v5 = 3
				}
				var buf [4]byte
				binary.LittleEndian.PutUint32(buf[:], uint32(v5))
				c.nox_ctrlevent_action_42E670(client.CCMoveForward, &buf)
			case keybind.EventMoveBackward, keybind.EventMoveLeft, keybind.EventMoveRight:
				var code client.CtrlCode
				switch k {
				case keybind.EventMoveBackward:
					code = client.CCMoveBackward
				case keybind.EventMoveLeft:
					code = client.CCMoveLeft
				case keybind.EventMoveRight:
					code = client.CCMoveRight
				}
				v6 := uint32(bool2int(memmap.Uint8(0x5D4594, 754064)&0x1 != 0))
				if memmap.Uint8(0x5D4594, 754064)&0x8 != 0 {
					v6 |= 2
				}
				var buf [4]byte
				binary.LittleEndian.PutUint32(buf[:], v6)
				c.nox_ctrlevent_action_42E670(code, &buf)
			case keybind.EventJump:
				c.nox_ctrlevent_action_42E670(client.CCJump, nil)
			case keybind.EventToggleInventory:
				c.nox_ctrlevent_action_42E670(client.CCInventory, nil)
			case keybind.EventChat:
				c.nox_ctrlevent_action_42E670(client.CCChat, nil)
			case keybind.EventTeamChat:
				if *(*byte)(unsafe.Add(v2, 3680))&0x1 == 0 {
					c.nox_ctrlevent_action_42E670(client.CCTeamChat, nil)
				}
			case keybind.EventToggleBook:
				c.nox_ctrlevent_action_42E670(client.CCReadSpellbook, nil)
			case keybind.EventToggleConsole:
				c.nox_ctrlevent_action_42E670(client.CCToggleConsole, nil)
			case keybind.EventIncreaseWindowSize:
				if !nox_xxx_checkGameFlagPause_413A50() {
					c.nox_ctrlevent_action_42E670(client.CCIncreaseWindowSize, nil)
				}
			case keybind.EventDecreaseWindowSize:
				if !nox_xxx_checkGameFlagPause_413A50() {
					c.nox_ctrlevent_action_42E670(client.CCDecreaseWindowSize, nil)
				}
			case keybind.EventIncreaseGamma:
				c.nox_ctrlevent_action_42E670(client.CCIncreaseGamma, nil)
			case keybind.EventDecreaseGamma:
				c.nox_ctrlevent_action_42E670(client.CCDecreaseGamma, nil)
			case keybind.EventToggleMap:
				c.nox_ctrlevent_action_42E670(client.CCReadMap, nil)
			case keybind.EventCastQueued:
				if !nox_xxx_guiSpellTest_45D9C0() {
					v13 := C.nox_xxx_packetGetMarshall_476F40()
					var b [4]byte
					binary.LittleEndian.PutUint32(b[:], uint32(v13))
					c.nox_ctrlevent_action_42E780(client.CCCastQueuedSpell, &b)
				}
			case keybind.EventPhonemeUN:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(client.CCSpellGestureUp, nil)
				}
			case keybind.EventPhonemeZO:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(client.CCSpellGestureDown, nil)
				}
			case keybind.EventPhonemeET:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(client.CCSpellGestureLeft, nil)
				}
			case keybind.EventPhonemeCHA:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(client.CCSpellGestureRight, nil)
				}
			case keybind.EventPhonemeIN:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(client.CCSpellGestureUpperRight, nil)
				}
			case keybind.EventPhonemeKA:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(client.CCSpellGestureUpperLeft, nil)
				}
			case keybind.EventPhonemeDO:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(client.CCSpellGestureLowerRight, nil)
				}
			case keybind.EventPhonemeRO:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(client.CCSpellGestureLowerLeft, nil)
				}
			case keybind.EventSpellEnd:
				if !nox_xxx_guiSpellTest_45D9C0() {
					c.nox_ctrlevent_action_42E780(client.CCSpellPatternEnd, nil)
				}
			case keybind.EventCastRecent:
				if !nox_xxx_guiSpellTest_45D9C0() {
					v14 := C.nox_xxx_packetGetMarshall_476F40()
					var b [4]byte
					binary.LittleEndian.PutUint32(b[:], uint32(v14))
					c.nox_ctrlevent_action_42E780(client.CCCastMostRecentSpell, &b)
				}
			case keybind.EventInvokeSlot1:
				c.nox_ctrlevent_action_42E780(client.CCCastSpell1, nil)
			case keybind.EventInvokeSlot2:
				c.nox_ctrlevent_action_42E780(client.CCCastSpell2, nil)
			case keybind.EventInvokeSlot3:
				c.nox_ctrlevent_action_42E780(client.CCCastSpell3, nil)
			case keybind.EventInvokeSlot4:
				c.nox_ctrlevent_action_42E780(client.CCCastSpell4, nil)
			case keybind.EventInvokeSlot5:
				c.nox_ctrlevent_action_42E780(client.CCCastSpell5, nil)
			case keybind.EventSpellSet1, keybind.EventSpellSet2, keybind.EventSpellSet3, keybind.EventSpellSet4, keybind.EventSpellSet5:
				C.nox_xxx_clientUpdateButtonRow_45E110(C.int(k - keybind.EventSpellSet1))
			case keybind.EventMapZoomIn:
				c.nox_ctrlevent_action_42E670(client.CCMapZoomIn, nil)
			case keybind.EventMapZoomOut:
				c.nox_ctrlevent_action_42E670(client.CCMapZoomOut, nil)
			case keybind.EventSwapWeapons:
				c.nox_ctrlevent_action_42E780(client.CCNextWeapon, nil)
			case keybind.EventQuickHealth:
				c.nox_ctrlevent_action_42E780(client.CCQuickHealthPotion, nil)
			case keybind.EventQuickMana:
				c.nox_ctrlevent_action_42E780(client.CCQuickManaPotion, nil)
			case keybind.EventQuickCurePoison:
				c.nox_ctrlevent_action_42E780(client.CCQuickCurePoisonPotion, nil)
			case keybind.EventNextSpellSet:
				c.nox_ctrlevent_action_42E780(client.CCNextSpellSet, nil)
			case keybind.EventPreviousSpellSet:
				c.nox_ctrlevent_action_42E780(client.CCPreviousSpellSet, nil)
			case keybind.EventSelectSpellSet:
				c.nox_ctrlevent_action_42E780(client.CCSelectSpellSet, nil)
			case keybind.EventPlaceTrapBomber:
				c.nox_ctrlevent_action_42E780(client.CCBuildTrap, nil)
			case keybind.EventTrapDrop:
				if inputKeyCheckTimeout(k, gameFPS()/4) {
					inputSetKeyTimeout(k)
					gameexDropTrap()
				}
			case keybind.EventTrapBomber1, keybind.EventTrapBomber2, keybind.EventTrapBomber3:
				if inputKeyCheckTimeout(k, gameFPS()/4) {
					inputSetKeyTimeout(k)
					C.nox_client_trapSetSelect_4604B0(C.int(k - keybind.EventTrapBomber1))
					clientPlaySoundSpecial(798, 100)
				}
			case keybind.EventQuit:
				c.nox_ctrlevent_action_42E670(client.CCQuit, nil)
			case keybind.EventToggleQuitMenu:
				c.nox_ctrlevent_action_42E670(client.CCQuitMenu, nil)
			case keybind.EventToggleServerMenu:
				c.nox_ctrlevent_action_42E670(client.CCServerOptions, nil)
			case keybind.EventTaunt:
				if (allowEmotionsInSolo || noxflags.HasGame(noxflags.GameOnline)) && inputKeyCheckTimeoutLegacy(21, gameFPS()) {
					inputSetKeyTimeoutLegacy(21)
					c.nox_ctrlevent_action_42E670(client.CCTaunt, nil)
				}
			case keybind.EventLaugh:
				if (allowEmotionsInSolo || noxflags.HasGame(noxflags.GameOnline)) && inputKeyCheckTimeoutLegacy(20, 2*gameFPS()) {
					inputSetKeyTimeoutLegacy(20)
					c.nox_ctrlevent_action_42E670(client.CCLaugh, nil)
				}
			case keybind.EventPoint:
				if (allowEmotionsInSolo || noxflags.HasGame(noxflags.GameOnline)) && inputKeyCheckTimeoutLegacy(22, gameFPS()) {
					inputSetKeyTimeoutLegacy(22)
					c.nox_ctrlevent_action_42E670(client.CCPoint, nil)
				}
			case keybind.EventInvertSpellTarget:
				c.nox_ctrlevent_action_42E670(client.CCInvertSpellTarget, nil)
			case keybind.EventToggleRank:
				if noxflags.HasGame(noxflags.GameOnline) {
					c.nox_ctrlevent_action_42E670(client.CCToggleRank, nil)
				}
			case keybind.EventToggleNetstat:
				if !nox_xxx_checkGameFlagPause_413A50() {
					c.nox_ctrlevent_action_42E670(client.CCToggleNetstat, nil)
				}
			case keybind.EventToggleGUI:
				c.nox_ctrlevent_action_42E670(client.CCToggleGUI, nil)
			case keybind.EventAutoSave:
				if noxflags.HasGame(noxflags.GameModeCoop) && !nox_xxx_guiCursor_477600() {
					c.nox_ctrlevent_action_42E670(client.CCAutoSave, nil)
				}
			case keybind.EventAutoLoad:
				if noxflags.HasGame(noxflags.GameModeCoop) && !nox_xxx_guiCursor_477600() {
					c.nox_ctrlevent_action_42E670(client.CCAutoLoad, nil)
				}
			case keybind.EventScreenShot:
				c.nox_ctrlevent_action_42E670(client.CCScreenShot, nil)
			case keybind.EventCreaturesBanish:
				if inputKeyCheckTimeout(k, gameFPS()/4) {
					inputSetKeyTimeout(k)
					C.nox_client_orderCreature(0, 0)
				}
			case keybind.EventCreaturesGuard:
				if inputKeyCheckTimeout(k, gameFPS()/4) {
					inputSetKeyTimeout(k)
					C.nox_client_orderCreature(0, 3)
				}
			case keybind.EventCreaturesEscort:
				if inputKeyCheckTimeout(k, gameFPS()/4) {
					inputSetKeyTimeout(k)
					C.nox_client_orderCreature(0, 4)
				}
			case keybind.EventCreaturesHunt:
				if inputKeyCheckTimeout(k, gameFPS()/4) {
					inputSetKeyTimeout(k)
					C.nox_client_orderCreature(0, 5)
				}
			case keybind.EventAcceptItemsBatch:
				if inputKeyCheckTimeout(k, gameFPS()/4) {
					inputSetKeyTimeout(k)
					clientAcceptTradeOrDrop()
				}
			}
		}
	}
}

func clientAcceptTradeOrDrop() {
	dialog := asWindow((*C.nox_window)(C.nox_gui_itemAmount_dialog_1319228))
	if dialog == nil {
		return
	}
	if dialog.Flags().IsHidden() {
		return
	}
	accept := dialog.ChildByID(3606)
	C.sub_4C01C0(0, 16391, (*C.int)(unsafe.Pointer(accept.C())), 0)
}

func clientSetPhonemeFrame(a1 int) {
	*memmap.PtrUint32(0x5D4594, 1096596+4*uintptr(a1)) = gameFrame()
}

func nox_client_increaseViewport_4766E0() {
	nox_draw_setCutSize_476700(0, 2)
}

func nox_client_decreaseViewport_4766F0() {
	nox_draw_setCutSize_476700(0, -2)
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
		case client.CCSpellGestureUp: // un
			if !noxflags.HasGame(noxflags.GameModeChat) {
				clientPlaySoundSpecial(186, 100)
				clientSetPhonemeFrame(1)
			}
		case client.CCSpellGestureDown: // zo
			if !noxflags.HasGame(noxflags.GameModeChat) {
				clientPlaySoundSpecial(190, 100)
				clientSetPhonemeFrame(6)
			}
		case client.CCSpellGestureLeft: // et
			if !noxflags.HasGame(noxflags.GameModeChat) {
				clientPlaySoundSpecial(192, 100)
				clientSetPhonemeFrame(3)
			}
		case client.CCSpellGestureRight: // cha
			if !noxflags.HasGame(noxflags.GameModeChat) {
				clientPlaySoundSpecial(188, 100)
				clientSetPhonemeFrame(4)
			}
		case client.CCSpellGestureUpperRight: // in
			if !noxflags.HasGame(noxflags.GameModeChat) {
				clientPlaySoundSpecial(187, 100)
				clientSetPhonemeFrame(2)
			}
		case client.CCSpellGestureUpperLeft: // ka
			if !noxflags.HasGame(noxflags.GameModeChat) {
				clientPlaySoundSpecial(193, 100)
				clientSetPhonemeFrame(0)
			}
		case client.CCSpellGestureLowerRight: // do
			if !noxflags.HasGame(noxflags.GameModeChat) {
				clientPlaySoundSpecial(189, 100)
				clientSetPhonemeFrame(7)
			}
		case client.CCSpellGestureLowerLeft: // ro
			if !noxflags.HasGame(noxflags.GameModeChat) {
				clientPlaySoundSpecial(191, 100)
				clientSetPhonemeFrame(5)
			}
		case client.CCChat:
			C.nox_client_chatStart_46A430(0)
			ce.active = false
		case client.CCTeamChat:
			C.nox_client_chatStart_46A430(1)
			ce.active = false
		case client.CCReadSpellbook:
			C.nox_client_toggleSpellbook_45AC70()
			ce.active = false
		case client.CCToggleConsole:
			C.nox_client_toggleConsole_451350()
			ce.active = false
		case client.CCIncreaseWindowSize:
			clientPlaySoundSpecial(921, 100)
			nox_client_increaseViewport_4766E0()
			ce.active = false
		case client.CCDecreaseWindowSize:
			clientPlaySoundSpecial(921, 100)
			nox_client_decreaseViewport_4766F0()
			ce.active = false
		case client.CCIncreaseGamma:
			clientPlaySoundSpecial(921, 100)
			v38 := nox_video_getGammaSetting_434B00()
			nox_video_setGammaSetting_434B30(v38 + 1)
			updateGamma(1)
			C.sub_434B60()
			ce.active = false
		case client.CCDecreaseGamma:
			clientPlaySoundSpecial(921, 100)
			v39 := nox_video_getGammaSetting_434B00()
			nox_video_setGammaSetting_434B30(v39 - 1)
			updateGamma(-1)
			C.sub_434B60()
			ce.active = false
		case client.CCQuit:
			C.nox_client_quit_4460C0()
			ce.active = false
		case client.CCQuitMenu:
			if sub_450560() {
				nox_savegame_sub_46D580()
			} else {
				C.sub_42EB90(1)
			}
			ce.active = false
		case client.CCReadMap:
			C.nox_client_toggleMap_473610()
			ce.active = false
		case client.CCInventory:
			C.nox_client_toggleInventory_467C60()
			ce.active = false
		case client.CCCastSpell1, client.CCCastSpell2, client.CCCastSpell3, client.CCCastSpell4, client.CCCastSpell5:
			C.nox_client_invokeSpellSlot_45DA50(C.int(ce.code - client.CCCastSpell1))
			ce.active = false
		case client.CCMapZoomIn:
			C.nox_client_mapZoomIn_4724E0()
			ce.active = false
		case client.CCMapZoomOut:
			C.nox_client_mapZoomOut_472500()
			ce.active = false
		case client.CCNextWeapon:
			C.nox_client_invAlterWeapon_4672C0()
			ce.active = false
		case client.CCQuickHealthPotion:
			C.nox_client_quickHealthPotion_472220()
			ce.active = false
		case client.CCQuickManaPotion:
			C.nox_client_quickManaPotion_472240()
			ce.active = false
		case client.CCQuickCurePoisonPotion:
			C.nox_client_quickCurePoisonPotion_472260()
			ce.active = false
		case client.CCNextSpellSet:
			C.nox_client_spellSetNext_4604F0()
			ce.active = false
		case client.CCPreviousSpellSet:
			C.nox_client_spellSetPrev_460540()
			ce.active = false
		case client.CCSelectSpellSet:
			C.nox_client_spellSetSelect_460590()
			ce.active = false
		case client.CCBuildTrap:
			C.nox_client_buildTrap_45E040()
			ce.active = false
		case client.CCServerOptions:
			if !(noxflags.HasGame(noxflags.GameFlag4) || !noxflags.HasGame(noxflags.GameOnline)) {
				C.nox_xxx_guiServerOptsLoad_457500()
			}
			ce.active = false
		case client.CCLaugh:
			nox_xxx_netClientSendSocial(31, 1, 0, 1)
		case client.CCTaunt:
			nox_xxx_netClientSendSocial(31, 2, 0, 1)
		case client.CCPoint:
			nox_xxx_netClientSendSocial(31, 4, 0, 1)
		case client.CCInvertSpellTarget:
			C.sub_460630()
			ce.active = false
		case client.CCToggleRank:
			clientPlaySoundSpecial(921, 100)
			sub_4703F0()
			ce.active = false
		case client.CCToggleNetstat:
			C.sub_470A60()
			clientPlaySoundSpecial(921, 100)
			ce.active = false
		case client.CCToggleGUI:
			if !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
				C.nox_client_renderGUI_80828 ^= 1
				C.nox_xxx_xxxRenderGUI_587000_80832 = C.nox_client_renderGUI_80828
				clientPlaySoundSpecial(921, 100)
			}
			ce.active = false
		case client.CCAutoSave:
			if noxflags.HasGame(noxflags.GameModeCoop) {
				if C.nox_xxx_game_4DCCB0() != 0 {
					clientPlaySoundSpecial(921, 100)
					sub_4DB130(common.SaveAuto)
					sub_4DB170(1, 0, 0)
				} else {
					clientPlaySoundSpecial(231, 100)
				}
			}
			ce.active = false
		case client.CCAutoLoad:
			if noxflags.HasGame(noxflags.GameModeCoop) {
				if C.nox_xxx_game_4DCCB0() != 0 {
					clientPlaySoundSpecial(921, 100)
					sub_413A00(1)
					v41 := strMan.GetStringInFile("GUIQuit.c:ReallyLoadMessage", "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c")
					v40 := strMan.GetStringInFile("SelChar.c:LoadLabel", "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c")
					NewDialogWindow(nil, v40, v41, 56, C.sub_42E600, C.sub_42E620)
				} else {
					clientPlaySoundSpecial(231, 100)
				}
			}
			ce.active = false
		case client.CCScreenShot:
			makeScreenshot()
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
					if p1.code.CanPauseMode() {
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
					if p1.code.CanPauseMode() {
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

func (c *CtrlEventHandler) nox_ctrlevent_action_42E670(code client.CtrlCode, data *[4]byte) {
	if !noxflags.HasGame(noxflags.GameHost) {
		if c.indA >= cap(c.bufA) {
			return
		}
	} else {
		if c.indA+1 == c.indB {
			return
		}
	}
	if memmap.Uint8(0x85B3FC, 12254) != 0 || !code.IsMagicRelated() {
		j := c.indA
		if noxflags.HasGame(noxflags.GameHost) && code.CanPauseMode() {
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

func (c *CtrlEventHandler) nox_ctrlevent_action_42E780(code client.CtrlCode, data *[4]byte) {
	if p := *memmap.PtrPtr(0x852978, 8); p != nil && *(*byte)(unsafe.Add(p, 120))&2 == 0 {
		if !nox_xxx_checkGameFlagPause_413A50() {
			c.nox_ctrlevent_action_42E670(code, data)
		}
	}
}

func nox_ctrlevent_add_ticks_42E630() uint32 {
	v0 := C.sub_416640()
	switch *(*uint32)(unsafe.Add(v0, 66)) {
	case 1:
		return uint32(C.sub_554290())
	case 2:
		return uint32(C.sub_554300())
	case 3:
		return *(*uint32)(unsafe.Add(v0, 70))
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
			input.Log.Printf("invalid config line: %q", line)
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
			if !first {
				if _, err = io.WriteString(w, "+ "); err != nil {
					return err
				}
			}
			first = false
			_, err = fmt.Fprintf(w, "%s ", k.String())
			if err != nil {
				return err
			}
		}
		if _, err = io.WriteString(w, "= "); err != nil {
			return err
		}
		first = true
		for _, k := range it.events {
			if b := keyBinding.EventByCode(k); b != nil && b.Name != "" {
				if !first {
					if _, err = io.WriteString(w, "+ "); err != nil {
						return err
					}
				}
				first = false
				_, err = fmt.Fprintf(w, "%s ", b.Name)
				if err != nil {
					return err
				}
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
		input.Log.Println("cannot save config: empty file handle")
		return
	}
	if err := writeConfigHotkeys(f.File); err != nil {
		input.Log.Println("cannot save config:", err)
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
			buf[off] = byte(p.code)
			*bufSize = off + 4
			if sz := p.code.DataSize(); sz != 0 {
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
			buf[off] = byte(p.code)
			*bufSize = off + 4
			if sz := p.code.DataSize(); sz != 0 {
				off = *bufSize
				copy(buf[off:], p.data[:sz])
				*bufSize += byte(sz)
			}
		}
	}
}

//export nox_xxx_playerSaveInput_51A960
func nox_xxx_playerSaveInput_51A960(pli C.int, a2 *C.uchar) C.int {
	return C.int(noxServer.nox_xxx_playerSaveInput(int(pli), unsafe.Pointer(a2)))
}

func (s *Server) nox_xxx_playerSaveInput(pli int, a2 unsafe.Pointer) int {
	pl := s.getPlayerByInd(int(pli))
	sz := int(*(*byte)(a2)) + 1
	if pl != nil && *(*byte)(pl.field(3680))&0x10 == 0 {
		return sz
	}
	a2s := unsafe.Slice((*byte)(a2), sz)
	buf := sub_51AAA0(a2s[1:], nil)
	ind := int(C.nox_players_controlBuffer_2388804[pli])
	if ind+len(buf) < 128 {
		dst := C.nox_players_controlBuffer_2388932[pli][ind:]
		n := copy(dst, buf)
		C.nox_players_controlBuffer_2388804[pli] = C.int(ind + n)
	}
	C.sub_51AA20(C.int(pli))
	return sz
}

func (c *CtrlEventHandler) hasDefBinding(ev keybind.Event, key keybind.Key) bool {
	for it := c.bindings; it != nil; it = it.next {
		if it.defEvent() == ev && it.defKey() == key {
			return true
		}
	}
	return false
}

func sub_51AAA0(data []byte, out []C.nox_player_ctrl_t) []C.nox_player_ctrl_t {
	for len(data) > 0 {
		code := client.CtrlCode(data[0])
		data = data[4:]
		v := C.nox_player_ctrl_t{
			field_2: C.uint(code),
			field_4: 1,
		}
		if sz := code.DataSize(); sz != 0 {
			dst := unsafe.Slice((*byte)(unsafe.Pointer(&v.field_3[0])), 4)
			copy(dst, data[:sz])
			data = data[sz:]
		}
		out = append(out, v)
	}
	return out
}
