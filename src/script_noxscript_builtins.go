package opennox

/*
#include "defs.h"
int nox_script_getWall_511EB0();
int nox_script_toggleObject_5127F0();
int nox_script_deleteObjectGroup_5128D0();
int nox_script_canInteract_513E80();
int nox_script_Fn5E_513F70();
int nox_script_GetHostInfo_513FA0();
int nox_script_SetQuestInt_514BE0();
int nox_script_SetQuestFloat_514C10();
int nox_script_GetQuestInt_514C40();
int nox_script_GetQuestFloat_514C60();
int nox_script_ResetQuestStatus_514C90();
int nox_script_IsTrigger_514CB0();
int nox_script_IsCaller_514CF0();
int nox_script_SetDialog_514D90();
int nox_script_CancelDialog_514DF0();
int nox_script_DialogPortrait_514E30();
int nox_script_TellStory_514E90();
int nox_script_StartDialog_514ED0();
int nox_script_Guard_515600();
int nox_script_GuardGroup_515700();
int nox_script_HuntGroup_5157D0();
int nox_script_AgressionLevel_515950();
int nox_script_AggressionLevelGroup_5159B0();
int nox_script_HitLocation_5159E0();
int nox_script_HitLocationGroup_515AE0();
int nox_script_HitFarLocation_515B30();
int nox_script_HitFarLocationGroup_515BF0();
int nox_script_SetRoamFlag_515C40();
int nox_script_SetRoamFlagGroup_515CB0();
int nox_script_Attack_515CF0();
int nox_script_AttackGroup_515DB0();
int nox_script_JournalDelete_515550();
int nox_script_JournalEdit_5155A0();
int nox_script_RetreatLevel_515DF0();
int nox_script_RetreatLevelGroup_515E50();
int nox_script_SetResumeLevel_515E80();
int nox_script_SetResumeLevelGroup_515EE0();
int nox_script_RunAway_515F10();
int nox_script_RunAwayGroup_516000();
int nox_script_PauseObject_516060();
int nox_script_PauseObjectGroup_5160F0();
int nox_script_GetGold_516120();
int nox_script_ChangeGold_516160();
int nox_script_DialogResult_5163C0();
int nox_script_GiveExp_516190();
int nox_script_HasSubclass_5162D0();
int nox_script_StartupScreen_516600();
int nox_script_IsTalking_5166A0();
int nox_script_GetTrigger_514D30();
int nox_script_GetCaller_514D60();
int nox_script_MakeFriendly_516720();
int nox_script_MakeEnemy_516760();
int nox_script_BecomePet_5167D0();
int nox_script_BecomeEnemy_516810();
int nox_script_builtin_516790();
int nox_script_builtin_516850();
int nox_script_OblivionGive_516890();
int nox_script_DeleteObjectTimer_516A50();
int nox_script_TrapSpells_516B40();
int nox_script_PlayerIsTrading_5166E0();
int nox_script_SetShopkeeperGreet_516BE0();
int nox_script_IsSummoned_516C30();
int nox_script_ObjIsGameball_516D70();
int nox_script_ObjIsCrown_516DC0();

extern unsigned int nox_xxx_wallSounds_2386840;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern int dword_5d4594_2386848;
extern unsigned int dword_5d4594_2386852;

nox_object_t* nox_xxx_getObjectByScrName_4DA4F0(char* a1);
void* nox_server_scriptGetMapGroupByName_57C280(const char* a1, int a2);
int nox_xxx_destroyEveryChatMB_528D60();
const char* nox_xxx_waypointByName_579E30(const char* a1);
void sub_43D9B0(int a1, int a2);
int sub_43DA80();
void sub_43DAD0();
int* nox_server_scriptMoveTo_5123C0(int a1, int a2);
void nox_xxx_comJournalEntryAdd_427500(nox_object_t* a1, char* a2, short a3);
int nox_xxx_comAddEntryAll_427550(char* a1, short a2);
int nox_script_addString_512E40(char* a1);
int nox_xxx_netSendChat_528AC0(nox_object_t* a1, wchar_t* a2, wchar_t a3);
int nox_xxx_playDialogFile_44D900(char* a1, int a2);
int nox_xxx_spellGrantToPlayer_4FB550(nox_object_t* a1, int a2, int a3, int a4, int a5);
int nox_xxx_inventoryServPlace_4F36F0(nox_object_t* a1p, nox_object_t* a2p, int a3, int a4);
void nox_xxx_playerCanCarryItem_513B00(nox_object_t* a1p, nox_object_t* a2p);
unsigned int sub_516D00(nox_object_t* a1);
void nox_xxx_unitAdjustHP_4EE460(nox_object_t* unit, int dv);
void nox_xxx_unitSetOwner_4EC290(nox_object_t* obj1, nox_object_t* obj2);
*/
import "C"
import (
	"image"
	"math"
	"strconv"
	"strings"
	"unsafe"

	asm "github.com/noxworld-dev/opennox-lib/script/noxscript/noxasm"

	"github.com/noxworld-dev/opennox/v1/server"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func wrapScriptC(fnc unsafe.Pointer) noxScriptBuiltin {
	return func(_ *noxScript) int {
		return cgoCallIntVoidFunc(fnc)
	}
}

//export nox_script_callBuiltin_508B70
func nox_script_callBuiltin_508B70(i, fi C.int) C.int {
	return C.int(noxServer.noxScript.callBuiltin(int(i), asm.Builtin(fi)))
}

func (s *noxScript) callBuiltin(i int, fi asm.Builtin) int {
	if fi < 0 || fi > asm.BuiltinGetScore {
		if !s.panicCompilerCheck(fi) {
			scriptLog.Printf("noxscript: invalid builtin index: %d (%x)", fi, fi)
			return 0
		}
		return 0
	}
	if s.builtinNeedsField36(fi) {
		s.nameSuff = s.scriptNameSuff(i)
	}
	if s.builtinNeedsFields4044(fi) {
		s.dpos.X = s.scriptField40(i)
		s.dpos.Y = s.scriptField44(i)
	}
	res := s.callBuiltinNative(fi)
	s.resetBuiltin()
	return res
}

//export nox_script_shouldReadMoreXxx
func nox_script_shouldReadMoreXxx(fi C.int) C.bool {
	return C.bool(fi == 9 || fi == 10 ||
		fi == 46 || fi == 47 ||
		fi == 190 || fi == 126)
}

//export nox_script_shouldReadEvenMoreXxx
func nox_script_shouldReadEvenMoreXxx(fi C.int) C.bool {
	return C.bool(fi == 126)
}

func (s *noxScript) callBuiltinNative(fi asm.Builtin) int {
	if res, ok := s.panicScriptCall(fi); ok {
		return res
	}
	return noxScriptBuiltins[fi](s)
}

func (s *noxScript) builtinNeedsFields4044(fi asm.Builtin) bool {
	// TODO: 7 items in the array, but the count is set to 5; why?
	var check = []asm.Builtin{
		0,
		67, 68,
		72,
		97, 98,
		100,
	}
	for _, ind := range check[:5] {
		if fi == ind {
			return true
		}
	}
	return false
}

func (s *noxScript) builtinNeedsField36(fi asm.Builtin) bool {
	switch fi {
	case 60, 110, 111, 112, 113:
		return true
	}
	return false
}

type noxScriptBuiltin func(s *noxScript) int

var noxScriptBuiltins = [asm.BuiltinGetScore + 1]noxScriptBuiltin{
	asm.BuiltinWall:                      noxScriptCompare("nox_script_getWall_511EB0", wrapScriptC(C.nox_script_getWall_511EB0), nox_script_getWall_511EB0),
	asm.BuiltinWallOpen:                  nox_script_openSecretWall_511F50,
	asm.BuiltinWallGroupOpen:             nox_script_openWallGroup_512010,
	asm.BuiltinWallClose:                 nox_script_closeWall_512040,
	asm.BuiltinWallGroupClose:            nox_script_closeWallGroup_512100,
	asm.BuiltinWallToggle:                nox_script_toggleWall_512130,
	asm.BuiltinWallGroupToggle:           nox_script_toggleWallGroup_512260,
	asm.BuiltinWallBreak:                 nox_script_wallBreak_512290,
	asm.BuiltinWallGroupBreak:            nox_script_wallGroupBreak_5122F0,
	asm.BuiltinSecondTimer:               nox_script_secondTimer_512320,
	asm.BuiltinFrameTimer:                nox_script_frameTimer_512350,
	asm.BuiltinMove:                      nox_script_moverOrMonsterGo_512370,
	asm.BuiltinGroupMove:                 nox_script_groupGoTo_512500,
	asm.BuiltinLookAtDirection:           nox_script_lookAtDirection_512560,
	asm.BuiltinGroupLookAtDirection:      nox_script_groupLookAtDirection_512610,
	asm.BuiltinObjectOn:                  nox_script_objectOn_512670,
	asm.BuiltinObjectGroupOn:             nox_script_objGroupOn_512690,
	asm.BuiltinWaypointOn:                nox_script_waypointOn_5126D0,
	asm.BuiltinWaypointGroupOn:           nox_script_waypointGroupOn_5126F0,
	asm.BuiltinObjectOff:                 nox_script_objectOff_512730,
	asm.BuiltinObjectGroupOff:            nox_script_objGroupOff_512750,
	asm.BuiltinWaypointOff:               nox_script_waypointOff_512790,
	asm.BuiltinWaypointGroupOff:          nox_script_waypointGroupOff_5127B0,
	asm.BuiltinObjectToggle:              nox_script_toggleObject_5127F0,
	asm.BuiltinObjectGroupToggle:         nox_script_toggleObjectGroup_512810,
	asm.BuiltinWaypointToggle:            nox_script_toggleWaypoint_512850,
	asm.BuiltinWaypointGroupToggle:       nox_script_toggleWaypointGroup_512870,
	asm.BuiltinDelete:                    nox_script_deleteObject_5128B0,
	asm.BuiltinGroupDelete:               nox_script_deleteObjectGroup_5128D0,
	asm.BuiltinWander:                    nox_script_followNearestWaypoint_512910,
	asm.BuiltinGroupWander:               nox_script_groupRoam_512990,
	asm.BuiltinUnused1f:                  nox_script_getObject2_5129C0,
	asm.BuiltinUnused20:                  nox_script_getObject3_5129E0,
	asm.BuiltinGoBackHome:                nox_script_gotoHome_512A00,
	asm.BuiltinAudioEvent:                nox_script_audioEven_512AC0,
	asm.BuiltinPrint:                     nox_script_printToCaller_512B10,
	asm.BuiltinPrintToAll:                nox_script_printToAll_512B60,
	asm.BuiltinChat:                      nox_script_sayChat_512B90,
	asm.BuiltinStopScript:                nox_script_returnOne_512C10,
	asm.BuiltinUnlockDoor:                nox_script_unlockDoor_512C20,
	asm.BuiltinLockDoor:                  nox_script_lockDoor_512C60,
	asm.BuiltinIsObjectOn:                nox_script_isOn_512CA0,
	asm.BuiltinIsWaypointOn:              nox_script_wpIsEnabled_512CE0,
	asm.BuiltinIsLocked:                  nox_script_doorIsLocked_512D20,
	asm.BuiltinRandomFloat:               nox_script_randomFloat_512D70,
	asm.BuiltinRandom:                    nox_script_randomInt_512DB0,
	asm.BuiltinSecondTimerWithArg:        nox_script_timerSecSpecial_512DE0,
	asm.BuiltinFrameTimerWithArg:         nox_script_specialTimer_512E10,
	asm.BuiltinIntToString:               nox_script_intToString_512EA0,
	asm.BuiltinFloatToString:             nox_script_floatToString_512ED0,
	asm.BuiltinCreateObject:              nox_script_create_512F10,
	asm.BuiltinDamage:                    nox_script_damage_512F80,
	asm.BuiltinGroupDamage:               nox_script_groupDamage_513010,
	asm.BuiltinCreateMover:               nox_script_Wander_513070,
	asm.BuiltinGroupCreateMover:          nox_script_WanderGroup_513160,
	asm.BuiltinAwardSpell:                nox_script_awardSpell_5131C0,
	asm.BuiltinGroupAwardSpell:           nox_script_awardSpellGroup_513230,
	asm.BuiltinEnchant:                   nox_script_enchant_5132E0,
	asm.BuiltinGroupEnchant:              nox_script_groupEnchant_5133B0,
	asm.BuiltinGetHost:                   nox_script_getHost_513460,
	asm.BuiltinObject:                    nox_script_objectGet_513490,
	asm.BuiltinGetObjectX:                nox_script_getObjectX_513530,
	asm.BuiltinGetWaypointX:              nox_script_getWaypointX_513570,
	asm.BuiltinGetObjectY:                nox_script_getObjectY_5135B0,
	asm.BuiltinGetWaypointY:              nox_script_getWaypointY_5135F0,
	asm.BuiltinGetObjectZ:                nox_script_unitHeight_513630,
	asm.BuiltinGetDirection:              nox_script_getUnitLook_513670,
	asm.BuiltinMoveObject:                nox_script_moveObject_5136A0,
	asm.BuiltinMoveWaypoint:              nox_script_moveWaypoint_513700,
	asm.BuiltinRaise:                     nox_script_raise_513750,
	asm.BuiltinLookWithAngle:             nox_script_faceAngle_513780,
	asm.BuiltinPushObjectTo:              nox_script_pushObject_5137D0,
	asm.BuiltinPushObject:                nox_script_pushObjectTo_513820,
	asm.BuiltinGetLastItem:               nox_script_getFirstInvItem_5138B0,
	asm.BuiltinGetPreviousItem:           nox_script_getNextInvItem_5138E0,
	asm.BuiltinHasItem:                   nox_script_hasItem_513910,
	asm.BuiltinGetHolder:                 nox_script_getInvHolder_513960,
	asm.BuiltinPickup:                    nox_script_pickup_5139A0,
	asm.BuiltinDrop:                      nox_script_drop_513C10,
	asm.BuiltinHasClass:                  nox_script_HasClass_516210,
	asm.BuiltinUnused50:                  nox_script_builtin_513C60,
	asm.BuiltinHasEnchant:                nox_script_TestBuffs_513C70,
	asm.BuiltinEnchantOff:                nox_script_cancelBuff_513D00,
	asm.BuiltinCurrentHealth:             nox_script_getCurrentHP_513D70,
	asm.BuiltinMaxHealth:                 nox_script_getMaxHP_513DB0,
	asm.BuiltinRestoreHealth:             nox_script_restoreHP_513DF0,
	asm.BuiltinDistance:                  nox_script_getDistance_513E20,
	asm.BuiltinIsVisibleTo:               noxScriptCompare("nox_script_canInteract_513E80", wrapScriptC(C.nox_script_canInteract_513E80), nox_script_canInteract_513E80),
	asm.BuiltinUnused58:                  nox_script_fn58_513F10,
	asm.BuiltinUnused59:                  nox_script_fn59_513F20,
	asm.BuiltinUnused5a:                  nox_script_fn5A_513F30,
	asm.BuiltinUnused5b:                  nox_script_fn5B_513F40,
	asm.BuiltinUnused5c:                  nox_script_Fn5C_513F50,
	asm.BuiltinUnused5d:                  nox_script_Fn5D_513F60,
	asm.BuiltinUnused5e:                  wrapScriptC(C.nox_script_Fn5E_513F70),
	asm.BuiltinGetCharacterData:          wrapScriptC(C.nox_script_GetHostInfo_513FA0),
	asm.BuiltinLookAtObject:              nox_script_FaceObject_514050,
	asm.BuiltinWalk:                      nox_script_Walk_5140B0,
	asm.BuiltinGroupWalk:                 nox_script_GroupWalk_514170,
	asm.BuiltinCancelTimer:               nox_script_CancelTimer_5141F0,
	asm.BuiltinEffect:                    nox_script_Effect_514210,
	asm.BuiltinSetOwner:                  nox_script_SetOwner_514490,
	asm.BuiltinGroupSetOwner:             nox_script_SetOwnerGroup_5144C0,
	asm.BuiltinSetOwners:                 nox_script_SetOwners_514510,
	asm.BuiltinGroupSetOwners:            nox_script_SetOwnersGroup_514570,
	asm.BuiltinIsOwnedBy:                 nox_script_IsOwnedBy_5145F0,
	asm.BuiltinGroupIsOwnedBy:            nox_script_IsOwnedByGroup_514630,
	asm.BuiltinIsOwnedByAny:              nox_script_IsOwnedByAny_5146B0,
	asm.BuiltinGroupIsOwnedByAny:         nox_script_IsOwnedByAnyGroup_514730,
	asm.BuiltinClearOwner:                nox_script_ClearOwner_5147E0,
	asm.BuiltinWaypoint:                  nox_script_Waypoint_514800,
	asm.BuiltinWaypointGroup:             nox_script_GetWaypointGroup_5148A0,
	asm.BuiltinObjectGroup:               nox_script_GetObjectGroup_514940,
	asm.BuiltinWallGroup:                 nox_script_GetWallGroup_5149E0,
	asm.BuiltinChatTimerSeconds:          nox_script_ChatTimerSeconds_514A80,
	asm.BuiltinChatTimer:                 nox_script_ChatTimerFrames_514B10,
	asm.BuiltinUnused74:                  nox_script_Pop2_74_514BA0,
	asm.BuiltinDestroyChat:               nox_script_RemoveChat_514BB0,
	asm.BuiltinDestroyEveryChat:          nox_script_NoChatAll_514BD0,
	asm.BuiltinSetQuestStatus:            wrapScriptC(C.nox_script_SetQuestInt_514BE0),
	asm.BuiltinSetQuestStatusFloat:       wrapScriptC(C.nox_script_SetQuestFloat_514C10),
	asm.BuiltinGetQuestStatus:            wrapScriptC(C.nox_script_GetQuestInt_514C40),
	asm.BuiltinGetQuestStatusFloat:       wrapScriptC(C.nox_script_GetQuestFloat_514C60),
	asm.BuiltinResetQuestStatus:          wrapScriptC(C.nox_script_ResetQuestStatus_514C90),
	asm.BuiltinIsTrigger:                 wrapScriptC(C.nox_script_IsTrigger_514CB0),
	asm.BuiltinIsCaller:                  wrapScriptC(C.nox_script_IsCaller_514CF0),
	asm.BuiltinSetDialog:                 wrapScriptC(C.nox_script_SetDialog_514D90),
	asm.BuiltinCancelDialog:              wrapScriptC(C.nox_script_CancelDialog_514DF0),
	asm.BuiltinStoryPic:                  wrapScriptC(C.nox_script_DialogPortrait_514E30),
	asm.BuiltinTellStory:                 wrapScriptC(C.nox_script_TellStory_514E90),
	asm.BuiltinStartDialog:               wrapScriptC(C.nox_script_StartDialog_514ED0),
	asm.BuiltinCastSpellObjectObject:     nox_script_CastObject2_514F10,
	asm.BuiltinCastSpellObjectLocation:   nox_script_CastObjectLocation_514FC0,
	asm.BuiltinCastSpellLocationObject:   nox_script_CastLocationObject_515060,
	asm.BuiltinCastSpellLocationLocation: nox_script_CastLocation2_515130,
	asm.BuiltinUnBlind:                   nox_script_UnBlind_515200,
	asm.BuiltinBlind:                     nox_script_Blind_515220,
	asm.BuiltinWideScreen:                nox_script_WideScreen_515240,
	asm.BuiltinGetElevatorStatus:         nox_script_GetElevatorStat_5154A0,
	asm.BuiltinCreatureGuard:             wrapScriptC(C.nox_script_Guard_515600),
	asm.BuiltinCreatureGroupGuard:        wrapScriptC(C.nox_script_GuardGroup_515700),
	asm.BuiltinCreatureHunt:              nox_script_Hunt_515780,
	asm.BuiltinCreatureGroupHunt:         wrapScriptC(C.nox_script_HuntGroup_5157D0),
	asm.BuiltinCreatureIdle:              nox_script_Idle_515800,
	asm.BuiltinCreatureGroupIdle:         nox_script_GroupIdle_515850,
	asm.BuiltinCreatureFollow:            nox_script_Follow_515880,
	asm.BuiltinCreatureGroupFollow:       nox_script_FollowGroup_515910,
	asm.BuiltinAggressionLevel:           wrapScriptC(C.nox_script_AgressionLevel_515950),
	asm.BuiltinGroupAggressionLevel:      wrapScriptC(C.nox_script_AggressionLevelGroup_5159B0),
	asm.BuiltinHitLocation:               wrapScriptC(C.nox_script_HitLocation_5159E0),
	asm.BuiltinGroupHitLocation:          wrapScriptC(C.nox_script_HitLocationGroup_515AE0),
	asm.BuiltinHitFarLocation:            wrapScriptC(C.nox_script_HitFarLocation_515B30),
	asm.BuiltinGroupHitFarLocation:       wrapScriptC(C.nox_script_HitFarLocationGroup_515BF0),
	asm.BuiltinSetRoamFlag:               wrapScriptC(C.nox_script_SetRoamFlag_515C40),
	asm.BuiltinGroupSetRoamFlag:          wrapScriptC(C.nox_script_SetRoamFlagGroup_515CB0),
	asm.BuiltinAttack:                    wrapScriptC(C.nox_script_Attack_515CF0),
	asm.BuiltinGroupAttack:               wrapScriptC(C.nox_script_AttackGroup_515DB0),
	asm.BuiltinJournalEntry:              nox_script_JournalEntry_5154E0,
	asm.BuiltinJournalDelete:             wrapScriptC(C.nox_script_JournalDelete_515550),
	asm.BuiltinJournalEdit:               wrapScriptC(C.nox_script_JournalEdit_5155A0),
	asm.BuiltinRetreatLevel:              wrapScriptC(C.nox_script_RetreatLevel_515DF0),
	asm.BuiltinGroupRetreatLevel:         wrapScriptC(C.nox_script_RetreatLevelGroup_515E50),
	asm.BuiltinResumeLevel:               wrapScriptC(C.nox_script_SetResumeLevel_515E80),
	asm.BuiltinGroupResumeLevel:          wrapScriptC(C.nox_script_SetResumeLevelGroup_515EE0),
	asm.BuiltinRunAway:                   wrapScriptC(C.nox_script_RunAway_515F10),
	asm.BuiltinGroupRunAway:              wrapScriptC(C.nox_script_RunAwayGroup_516000),
	asm.BuiltinPauseObject:               wrapScriptC(C.nox_script_PauseObject_516060),
	asm.BuiltinGroupPauseObject:          wrapScriptC(C.nox_script_PauseObjectGroup_5160F0),
	asm.BuiltinIsAttackedBy:              nox_script_IsAttackedBy_5161C0,
	asm.BuiltinGetGold:                   wrapScriptC(C.nox_script_GetGold_516120),
	asm.BuiltinChangeGold:                wrapScriptC(C.nox_script_ChangeGold_516160),
	asm.BuiltinGetAnswer:                 wrapScriptC(C.nox_script_DialogResult_5163C0),
	asm.BuiltinGiveXp:                    wrapScriptC(C.nox_script_GiveExp_516190),
	asm.BuiltinHasSubclass:               wrapScriptC(C.nox_script_HasSubclass_5162D0),
	asm.BuiltinAutoSave:                  nox_script_ForceAutosave_516400,
	asm.BuiltinMusic:                     nox_script_Music_516430,
	asm.BuiltinStartupScreen:             wrapScriptC(C.nox_script_StartupScreen_516600),
	asm.BuiltinIsTalking:                 wrapScriptC(C.nox_script_IsTalking_5166A0),
	asm.BuiltinGetTrigger:                wrapScriptC(C.nox_script_GetTrigger_514D30),
	asm.BuiltinGetCaller:                 wrapScriptC(C.nox_script_GetCaller_514D60),
	asm.BuiltinMakeFriendly:              wrapScriptC(C.nox_script_MakeFriendly_516720),
	asm.BuiltinMakeEnemy:                 wrapScriptC(C.nox_script_MakeEnemy_516760),
	asm.BuiltinBecomePet:                 wrapScriptC(C.nox_script_BecomePet_5167D0),
	asm.BuiltinBecomeEnemy:               wrapScriptC(C.nox_script_BecomeEnemy_516810),
	asm.BuiltinUnknownb8:                 wrapScriptC(C.nox_script_builtin_516790),
	asm.BuiltinUnknownb9:                 wrapScriptC(C.nox_script_builtin_516850),
	asm.BuiltinSetHalberd:                wrapScriptC(C.nox_script_OblivionGive_516890),
	asm.BuiltinDeathScreen:               nox_script_DeathScreen_516680,
	asm.BuiltinFrozen:                    nox_script_Frozen_516920,
	asm.BuiltinNoWallSound:               nox_script_NoWallSound_516960,
	asm.BuiltinSetCallback:               nox_script_SetCallback_516970,
	asm.BuiltinDeleteObjectTimer:         wrapScriptC(C.nox_script_DeleteObjectTimer_516A50),
	asm.BuiltinTrapSpells:                wrapScriptC(C.nox_script_TrapSpells_516B40),
	asm.BuiltinIsTrading:                 wrapScriptC(C.nox_script_PlayerIsTrading_5166E0),
	asm.BuiltinClearMessages:             nox_script_ClearMessages_516BC0,
	asm.BuiltinSetShopkeeperText:         wrapScriptC(C.nox_script_SetShopkeeperGreet_516BE0),
	asm.BuiltinUnknownc4:                 nox_script_StopAllFades_516C10,
	asm.BuiltinIsSummoned:                wrapScriptC(C.nox_script_IsSummoned_516C30),
	asm.BuiltinZombieStayDown:            nox_script_ZombieStayDown_516C70,
	asm.BuiltinZombieGroupStayDown:       nox_script_ZombieStayDownGroup_516CB0,
	asm.BuiltinRaiseZombie:               nox_script_RaiseZombie_516CE0,
	asm.BuiltinRaiseZombieGroup:          nox_script_RaiseZombieGroup_516D40,
	asm.BuiltinMusicPushEvent:            nox_script_MusicPushEvent_5164A0,
	asm.BuiltinMusicPopEvent:             nox_script_MusicPopEvent_5164E0,
	asm.BuiltinMusicEvent:                nox_script_ClearMusic_516520,
	asm.BuiltinIsGameBall:                wrapScriptC(C.nox_script_ObjIsGameball_516D70),
	asm.BuiltinIsCrown:                   wrapScriptC(C.nox_script_ObjIsCrown_516DC0),
	asm.BuiltinEndGame:                   nox_script_EndGame_516E10,
	asm.BuiltinImmediateBlind:            nox_script_StartGame_516C20,
	asm.BuiltinChangeScore:               nox_script_ChangeScore_516E30,
	asm.BuiltinGetScore:                  nox_script_GetScore_516EA0,
}

func nox_script_secondTimer_512320(s *noxScript) int {
	fnc := int(s.PopU32())
	dt := s.PopU32()
	s.PushU32(s.newScriptTimer(int(dt*s.s.TickRate()), fnc, 0))
	return 0
}

func nox_script_frameTimer_512350(s *noxScript) int {
	fnc := int(s.PopU32())
	df := int(s.PopU32())
	s.PushU32(s.newScriptTimer(df, fnc, 0))
	return 0
}

func nox_script_deleteObject_5128B0(s *noxScript) int {
	if obj := s.PopObject(); obj != nil {
		obj.Delete()
	}
	return 0
}

func nox_script_deleteObjectGroup_5128D0(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) {
		obj.Delete()
	})
	return 0
}

func nox_script_getObject2_5129C0(s *noxScript) int {
	_ = s.PopObject()
	return 0
}

func nox_script_getObject3_5129E0(s *noxScript) int {
	_ = s.PopObject()
	return 0
}

func nox_script_printToCaller_512B10(s *noxScript) int {
	strID := s.PopString()
	if c := s.Caller().AsUnit(); c != nil && c.Class().Has(object.ClassPlayer) {
		str := s.s.Strings().GetStringInFile(strman.ID(strID), "CScrFunc.c")
		nox_xxx_netSendLineMessage_4D9EB0(c, str)
	}
	return 0
}

func nox_script_printToAll_512B60(s *noxScript) int {
	strID := s.PopString()
	str := s.s.Strings().GetStringInFile(strman.ID(strID), "CScrFunc.c")
	PrintToPlayers(str)
	return 0
}

func nox_script_returnOne_512C10(_ *noxScript) int { return 1 }

func nox_script_randomFloat_512D70(s *noxScript) int {
	max := float64(s.PopF32())
	min := float64(s.PopF32())
	val := noxRndCounter1.FloatClamp(min, max)
	s.PushF32(float32(val))
	return 0
}

func nox_script_randomInt_512DB0(s *noxScript) int {
	max := int(s.PopU32())
	min := int(s.PopU32())
	val := noxRndCounter1.IntClamp(min, max)
	s.PushI32(int32(val))
	return 0
}

func nox_script_timerSecSpecial_512DE0(s *noxScript) int {
	fnc := int(s.PopU32())
	arg := s.PopU32()
	dt := s.PopU32()
	s.PushU32(s.newScriptTimer(int(dt*s.s.TickRate()), fnc, arg))
	return 0
}

func nox_script_specialTimer_512E10(s *noxScript) int {
	fnc := int(s.PopU32())
	arg := s.PopU32()
	df := int(s.PopU32())
	s.PushU32(s.newScriptTimer(df, fnc, arg))
	return 0
}

func nox_script_objectGet_513490(s *noxScript) int {
	str := s.PopString()
	str += s.nameSuff
	cstr := CString(str)
	defer StrFree(cstr)
	obj := asObjectC(C.nox_xxx_getObjectByScrName_4DA4F0(cstr))
	if obj != nil {
		s.PushU32(uint32(obj.ScriptID))
	} else {
		scriptLog.Printf("noxscript: cannot find object: %q", str)
		s.PushU32(0)
	}
	return 0
}

func nox_script_getObjectX_513530(s *noxScript) int {
	obj := s.PopObject()
	s.PushF32(obj.Pos().X)
	return 0
}

func nox_script_getObjectY_5135B0(s *noxScript) int {
	obj := s.PopObject()
	s.PushF32(obj.Pos().Y)
	return 0
}

func nox_script_builtin_513C60(s *noxScript) int { return 0 }

func nox_script_fn58_513F10(s *noxScript) int {
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_fn59_513F20(s *noxScript) int {
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_fn5A_513F30(s *noxScript) int {
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_fn5B_513F40(s *noxScript) int {
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_Fn5C_513F50(s *noxScript) int {
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_Fn5D_513F60(s *noxScript) int {
	s.PopU32()
	s.PopU32()
	return 0
}

// TODO: migrate all usage of `nox_server_scriptExecuteFnForEachGroupObj_502670` to use these funcs below.
func scriptExecuteFnForObjectGroup(s *Server, g *mapGroup, fn func(*Object)) {
	if g == nil {
		return
	}
	switch g.GroupType() {
	case mapGroupObjects:
		for item := g.First(); item != nil; item = item.Next() {
			ind := item.Ind()
			obj := s.GetObjectByInd(ind)
			if obj != nil {
				fn(obj)
			}
		}
	case mapGroupGroups:
		for item := g.First(); item != nil; item = item.Next() {
			childMapGroup := s.mapGroupByInd(item.Ind())
			scriptExecuteFnForObjectGroup(s, childMapGroup, fn)
		}
	}
}

func scriptExecuteFnForWaypointGroup(s *Server, g *mapGroup, fn func(*Waypoint)) {
	if g == nil {
		return
	}
	switch g.GroupType() {
	case mapGroupWaypoints:
		for item := g.First(); item != nil; item = item.Next() {
			ind := item.Ind()
			wp := s.getWaypointByInd(ind)
			if wp != nil {
				fn(wp)
			}
		}
	case mapGroupGroups:
		for item := g.First(); item != nil; item = item.Next() {
			childMapGroup := s.mapGroupByInd(item.Ind())
			scriptExecuteFnForWaypointGroup(s, childMapGroup, fn)
		}
	}
}

func scriptExecuteFnForWallGroup(s *Server, g *mapGroup, fn func(*Wall)) {
	if g == nil {
		return
	}
	switch g.GroupType() {
	case mapGroupWalls:
		for item := g.First(); item != nil; item = item.Next() {
			wall := s.getWallAtGrid(image.Pt(item.Ind(), item.Ind2()))
			if wall != nil {
				fn(wall)
			}
		}
	case mapGroupGroups:
		for item := g.First(); item != nil; item = item.Next() {
			childMapGroup := s.mapGroupByInd(item.Ind())
			scriptExecuteFnForWallGroup(s, childMapGroup, fn)
		}
	}
}

func nox_script_CancelTimer_5141F0(s *noxScript) int {
	act := s.PopU32()
	ok := s.actCancel(act)
	s.PushBool(ok)
	return 0
}

func nox_script_Effect_514210(s *noxScript) int {
	pos2 := s.PopPointf()
	pos := s.PopPointf()
	name := "MSG_FX_" + strings.ToUpper(s.PopString())
	dpos := s.DPos()
	pos = pos.Add(types.Point2f(dpos))

	switch fx := s.fxNames[name]; fx {
	case noxnet.MSG_FX_BLUE_SPARKS,
		noxnet.MSG_FX_YELLOW_SPARKS,
		noxnet.MSG_FX_CYAN_SPARKS,
		noxnet.MSG_FX_VIOLET_SPARKS,
		noxnet.MSG_FX_EXPLOSION,
		noxnet.MSG_FX_LESSER_EXPLOSION,
		noxnet.MSG_FX_COUNTERSPELL_EXPLOSION,
		noxnet.MSG_FX_THIN_EXPLOSION,
		noxnet.MSG_FX_TELEPORT,
		noxnet.MSG_FX_SMOKE_BLAST,
		noxnet.MSG_FX_DAMAGE_POOF,
		noxnet.MSG_FX_RICOCHET,
		noxnet.MSG_FX_WHITE_FLASH,
		noxnet.MSG_FX_TURN_UNDEAD,
		noxnet.MSG_FX_MANA_BOMB_CANCEL:
		nox_xxx_netSendPointFx_522FF0(fx, pos)
	case noxnet.MSG_FX_LIGHTNING,
		noxnet.MSG_FX_ENERGY_BOLT,
		noxnet.MSG_FX_PLASMA,
		noxnet.MSG_FX_DRAIN_MANA,
		noxnet.MSG_FX_CHARM,
		noxnet.MSG_FX_GREATER_HEAL,
		noxnet.MSG_FX_DEATH_RAY,
		noxnet.MSG_FX_SENTRY_RAY:
		nox_xxx_netSendRayFx_5232F0(fx, dpos.Add(pos.Point()), dpos.Add(pos2.Point()))
	case noxnet.MSG_FX_SPARK_EXPLOSION:
		nox_xxx_netSparkExplosionFx_5231B0(pos, byte(pos2.X))
	case noxnet.MSG_FX_JIGGLE:
		nox_xxx_earthquakeSend_4D9110(pos, int(pos2.X))
	case noxnet.MSG_FX_GREEN_BOLT:
		nox_xxx_netSendFxGreenBolt_523790(dpos.Add(pos.Point()), dpos.Add(pos2.Point()), 30)
	case noxnet.MSG_FX_VAMPIRISM:
		nox_xxx_netSendVampFx_523270(fx, dpos.Add(pos.Point()), dpos.Add(pos2.Point()), 100)
	}
	return 0
}

func nox_script_Waypoint_514800(s *noxScript) int {
	str := s.PopString()
	str += s.nameSuff
	cstr := CString(str)
	defer StrFree(cstr)
	ptr := unsafe.Pointer(C.nox_xxx_waypointByName_579E30(cstr))
	if ptr != nil {
		s.PushU32(*(*uint32)(unsafe.Add(ptr, 0)))
	} else {
		scriptLog.Printf("noxscript: cannot find waypoint: %q", str)
		s.PushU32(0)
	}
	return 0
}

func nox_script_GetWaypointGroup_5148A0(s *noxScript) int {
	str := s.PopString()
	str += s.nameSuff
	cstr := CString(str)
	defer StrFree(cstr)
	ptr := unsafe.Pointer(C.nox_server_scriptGetMapGroupByName_57C280(cstr, 1))
	if ptr != nil {
		s.PushU32(*(*uint32)(unsafe.Add(ptr, 4)))
	} else {
		scriptLog.Printf("noxscript: cannot find waypoint group: %q", str)
		s.PushU32(0)
	}
	return 0
}

func nox_script_GetObjectGroup_514940(s *noxScript) int {
	str := s.PopString()
	str += s.nameSuff
	cstr := CString(str)
	defer StrFree(cstr)
	ptr := unsafe.Pointer(C.nox_server_scriptGetMapGroupByName_57C280(cstr, 0))
	if ptr != nil {
		s.PushU32(*(*uint32)(unsafe.Add(ptr, 4)))
	} else {
		scriptLog.Printf("noxscript: cannot find object group: %q", str)
		s.PushU32(0)
	}
	return 0
}

func nox_script_GetWallGroup_5149E0(s *noxScript) int {
	str := s.PopString()
	str += s.nameSuff
	cstr := CString(str)
	defer StrFree(cstr)
	ptr := unsafe.Pointer(C.nox_server_scriptGetMapGroupByName_57C280(cstr, 2))
	if ptr != nil {
		s.PushU32(*(*uint32)(unsafe.Add(ptr, 4)))
	} else {
		scriptLog.Printf("noxscript: cannot find wall group: %q", str)
		s.PushU32(0)
	}
	return 0
}

func nox_script_Pop2_74_514BA0(s *noxScript) int {
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_RemoveChat_514BB0(s *noxScript) int {
	if u := s.PopObject().AsUnit(); u != nil {
		nox_xxx_netKillChat_528D00(u)
	}
	return 0
}

func nox_script_NoChatAll_514BD0(s *noxScript) int {
	C.nox_xxx_destroyEveryChatMB_528D60()
	return 0
}

func nox_script_CastObject2_514F10(s *noxScript) int {
	targ := s.PopObject()
	caster := s.PopObject().AsUnit()
	sp := spell.ParseID(s.PopString())
	if !sp.Valid() {
		return 0
	}
	if caster == nil {
		return 0
	}
	if caster.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
		return 0
	}
	if targ == nil {
		return 0
	}
	caster.Direction1 = server.DirFromVec(targ.Pos().Sub(caster.Pos()))
	s.s.castSpellBy(sp, caster, targ, targ.Pos())
	return 0
}

func nox_script_CastObjectLocation_514FC0(s *noxScript) int {
	targPos := s.PopPointf()
	caster := s.PopObject().AsUnit()
	sp := spell.ParseID(s.PopString())
	if !sp.Valid() {
		return 0
	}
	if caster == nil {
		return 0
	}
	caster.Direction1 = server.DirFromVec(targPos.Sub(caster.Pos()))
	s.s.castSpellBy(sp, caster, nil, targPos)
	return 0
}

func nox_script_CastLocationObject_515060(s *noxScript) int {
	targ := s.PopObject()
	srcPos := s.PopPointf()
	sp := spell.ParseID(s.PopString())
	if !sp.Valid() {
		return 0
	}
	if targ == nil {
		return 0
	}
	nox_xxx_imagCasterUnit_1569664.SetPos(srcPos)
	nox_xxx_imagCasterUnit_1569664.Direction1 = server.DirFromVec(targ.Pos().Sub(srcPos))
	s.s.castSpellBy(sp, nox_xxx_imagCasterUnit_1569664, targ, targ.Pos())
	return 0
}

func nox_script_CastLocation2_515130(s *noxScript) int {
	targPos := s.PopPointf()
	srcPos := s.PopPointf()
	sp := spell.ParseID(s.PopString())
	if !sp.Valid() {
		return 0
	}
	nox_xxx_imagCasterUnit_1569664.SetPos(srcPos)
	nox_xxx_imagCasterUnit_1569664.Direction1 = server.DirFromVec(targPos.Sub(srcPos))
	s.s.castSpellBy(sp, nox_xxx_imagCasterUnit_1569664, nil, targPos)
	return 0
}

func nox_script_UnBlind_515200(s *noxScript) int {
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	noxClient.r.FadeOutScreen(25, false, nil)
	return 0
}

func nox_script_Blind_515220(s *noxScript) int {
	noxClient.r.FadeInScreen(25, false, fadeDisableGameDraw)
	return 0
}

func nox_script_WideScreen_515240(s *noxScript) int {
	s.s.CinemaPlayers(s.PopI32() == 1)
	return 0
}

func nox_script_IsAttackedBy_5161C0(s *noxScript) int {
	obj2 := s.PopObject()
	obj1 := s.PopObject()
	val := obj1 != nil && obj2 != nil && obj1.isEnemyTo(obj2)
	s.PushBool(val)
	return 0
}

func nox_script_ForceAutosave_516400(s *noxScript) int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		sub_4DB130("AUTOSAVE")
		sub_4DB170(1, nil, 0)
	}
	return 0
}

func nox_script_Music_516430(s *noxScript) int {
	v0 := s.PopU32()
	v3 := s.PopU32()
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43D9B0(C.int(v3), C.int(v0))
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
		buf[1] = byte(v3)
		buf[2] = byte(v0)
		s.s.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

func nox_script_DeathScreen_516680(s *noxScript) int {
	*memmap.PtrUint32(0x5D4594, 2386832) = 0
	sub_5165D0()
	return 0
}

func nox_script_Frozen_516920(s *noxScript) int {
	val := s.PopBool()
	if u := s.PopObject().AsUnit(); u != nil {
		u.Freeze(val)
	}
	return 0
}

func nox_script_NoWallSound_516960(s *noxScript) int {
	C.nox_xxx_wallSounds_2386840 = C.uint(s.PopU32())
	return 0
}

func nox_script_SetCallback_516970(s *noxScript) int {
	fnc := int32(s.PopU32())
	ev := s.PopU32()
	u := s.PopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassMonster) {
		return 0
	}
	ud := u.UpdateDataMonster()
	switch ev {
	case 3: // Enemy sighted
		ud.ScriptEnemySightedCB = fnc
	case 4: // Looking for enemy
		ud.ScriptLookingForEnemyCB = fnc
	case 5: // Death
		ud.ScriptDeathCB = fnc
	case 6: // Change focus
		ud.ScriptChangeFocusCB = fnc
	case 7: // Is hit
		ud.ScriptIsHitCB = fnc
	case 8: // Retreat
		ud.ScriptRetreatCB = fnc
	case 9: // Collision
		ud.ScriptCollisionCB = fnc
	case 10: // Enemy heard
		ud.ScriptHearEnemyCB = fnc
	case 11: // End of waypoint
		ud.ScriptEndOfWaypointCB = fnc
	case 13: // Lost sight of enemy
		ud.ScriptLostEnemyCB = fnc
	}
	return 0
}

func nox_script_ClearMessages_516BC0(s *noxScript) int {
	if u := s.PopObject().AsUnit(); u != nil {
		nox_xxx_netScriptMessageKill_4D9760(u)
	}
	return 0
}

func nox_script_StopAllFades_516C10(s *noxScript) int {
	nox_video_stopAllFades_44E040()
	return 0
}

func nox_script_MusicPushEvent_5164A0(s *noxScript) int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43DA80()
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_PUSH_EVENT)
		s.s.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

func nox_script_MusicPopEvent_5164E0(s *noxScript) int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43DAD0()
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_POP_EVENT)
		s.s.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

func nox_script_ClearMusic_516520(s *noxScript) int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43D9B0(0, 0)
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
		s.s.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

func nox_script_EndGame_516E10(s *noxScript) int {
	v := int(s.PopI32())
	s.noxScriptEndGame(v)
	return 0
}

func nox_script_StartGame_516C20(s *noxScript) int {
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	return 0
}

func nox_script_ChangeScore_516E30(s *noxScript) int {
	val := int(s.PopU32())
	u := s.PopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassPlayer) {
		return 0
	}
	if val <= 0 {
		nox_xxx_playerSubLessons_4D8EC0(u, -val)
	} else {
		nox_xxx_changeScore_4D8E90(u, val)
	}

	if tm := s.s.teamByYyy(u.team()); tm != nil {
		s.s.teamChangeLessons(tm, val+int(tm.lessons))
	}
	nox_xxx_netReportLesson_4D8EF0(u)
	return 0
}

func nox_script_GetScore_516EA0(s *noxScript) int {
	u := s.PopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassPlayer) {
		s.PushU32(0)
		return 0
	}
	pl := u.ControllingPlayer()
	s.PushI32(int32(pl.lessons))
	return 0
}

func sliceEqual(a, b []uint32) bool {
	if len(a) != len(b) {
		return false
	}
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}

func noxScriptCompare(name string, orig, updated noxScriptBuiltin) noxScriptBuiltin {
	return func(s *noxScript) int {
		origStack := append([]uint32{}, s.vm.stack...)
		dryrunRet := updated(s)
		dryrunStack := append([]uint32{}, s.vm.stack...)
		s.vm.stack = origStack
		ret := orig(s)

		scriptLog.Printf("%s: test %v:%d vs %v:%d\n", name, dryrunStack, dryrunRet, s.vm.stack, ret)
		if dryrunRet != ret || !sliceEqual(s.vm.stack, dryrunStack) {
			scriptLog.Printf("%s: unexpected execution result: dry run %v:%d, not matching with %v:%d\n", name, dryrunStack, dryrunRet, s.vm.stack, ret)
		}

		return ret
	}
}

func nox_script_getWall_511EB0(s *noxScript) int {
	y := s.PopI32()
	x := s.PopI32()

	if dpos := s.DPos(); dpos != (image.Point{}) {
		x = (int32(dpos.X) + common.GridStep*x) / common.GridStep
		y = (int32(dpos.Y) + common.GridStep*y) / common.GridStep
	}

	if nox_server_getWallAtGrid_410580(C.int(x), C.int(y)) != nil {
		s.PushI32((x << 16) | y)
	} else {
		s.PushI32(0)
	}

	return 0
}

func nox_script_canInteract_513E80(s *noxScript) int {
	v3 := s.PopObject()
	v2 := s.PopObject()

	v4 := 0
	if v2 != nil && v3 != nil {
		p2 := v2.Pos()
		p3 := v3.Pos()
		if abs(p2.X-p3.X) <= 512.0 && abs(p2.Y-p3.Y) <= 512.0 {
			if nox_xxx_unitCanInteractWith_5370E0(v2, v3, 0) {
				v4 = 1
			}
		}
	}
	s.PushI32(int32(v4))

	return 0
}

func pointUnpack(packed int32) image.Point {
	return image.Pt(int(packed>>16), int(uint16(packed))) // Or, packed & 0xffff
}

func nox_script_openSecretWall_511F50(s *noxScript) int {
	grid := pointUnpack(s.PopI32())
	wall := s.s.getWallAtGrid(grid)
	if wall != nil {
		wall.Enable(false)
	}
	return 0
}

func nox_script_closeWall_512040(s *noxScript) int {
	grid := pointUnpack(s.PopI32())
	wall := s.s.getWallAtGrid(grid)
	if wall != nil {
		wall.Enable(false)
	}
	return 0
}

func nox_script_toggleWall_512130(s *noxScript) int {
	grid := pointUnpack(s.PopI32())
	wall := s.s.getWallAtGrid(grid)
	if wall != nil {
		wall.Toggle()
	}
	return 0
}

func nox_script_toggleWallGroup_512260(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))

	scriptExecuteFnForWallGroup(s.s, mapGroup, func(wall *Wall) {
		wall.Toggle()
	})
	return 0
}

func nox_script_wallBreak_512290(s *noxScript) int {
	grid := pointUnpack(s.PopI32())
	wall := s.s.getWallAtGrid(grid)
	if wall != nil {
		wall.Destroy()
	}
	return 0
}

func nox_script_wallGroupBreak_5122F0(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))

	scriptExecuteFnForWallGroup(s.s, mapGroup, func(wall *Wall) {
		wall.Destroy()
	})
	return 0
}

func nox_script_moverOrMonsterGo_512370(s *noxScript) int {
	waypointId := int(s.PopI32())
	obj := s.PopObject()
	if obj != nil {
		if !obj.Flags().Has(object.FlagDead) {
			waypoint := s.s.getWaypointByInd(waypointId)
			if waypoint != nil {
				C.nox_server_scriptMoveTo_5123C0(C.int(uintptr(unsafe.Pointer(obj))), C.int(uintptr(unsafe.Pointer(waypoint))))
			}
		}
	}
	return 0
}

func nox_script_groupGoTo_512500(s *noxScript) int {
	waypointId := int(s.PopI32())
	v1 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v1))
	waypoint := s.s.getWaypointByInd(waypointId)

	if mapGroup != nil && waypoint != nil {
		for it := mapGroup.First(); it != nil; it = it.Next() {
			item := s.s.GetObjectByInd(it.Ind())
			if item != nil {
				C.nox_server_scriptMoveTo_5123C0(C.int(uintptr(unsafe.Pointer(item))), C.int(uintptr(unsafe.Pointer(waypoint))))
			}
		}
	}
	return 0
}

func nox_script_lookAtDirection_512560(s *noxScript) int {
	direction := s.PopI32()
	monster := s.PopObject()
	if monster != nil {
		if monster.Class().Has(object.ClassMonster) && !monster.Flags().Has(object.FlagDead) {
			monster.AsUnit().LookAtDir(int(direction))
		}
	}
	return 0
}

func nox_script_groupLookAtDirection_512610(s *noxScript) int {
	direction := int(s.PopI32())
	v1 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v1))
	if mapGroup != nil {
		for it := mapGroup.First(); it != nil; it = it.Next() {
			monster := s.s.GetObjectByInd(it.Ind())
			if monster != nil && monster.Class().Has(object.ClassMonster) && !monster.Flags().Has(object.FlagDead) {
				monster.AsUnit().LookAtDir(direction)
			}
		}
	}
	return 0
}

func nox_script_objectOn_512670(s *noxScript) int {
	obj := s.PopObject()
	if obj != nil {
		obj.Enable(true)
	}
	return 0
}

func nox_script_objGroupOn_512690(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) {
		obj.Enable(true)
	})
	return 0
}

func nox_script_waypointOn_5126D0(s *noxScript) int {
	waypoint := s.s.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		*(*uint32)(unsafe.Add(unsafe.Pointer(waypoint), 120*4)) |= 1
	}
	return 0
}

func nox_script_objectOff_512730(s *noxScript) int {
	obj := s.PopObject()
	if obj != nil {
		obj.Enable(false)
	}
	return 0
}

func nox_script_objGroupOff_512750(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) {
		obj.Enable(false)
	})
	return 0
}

func nox_script_waypointOff_512790(s *noxScript) int {
	waypoint := s.s.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		*(*uint32)(unsafe.Add(unsafe.Pointer(waypoint), 120*4)) &= 0xFFFFFFFE
	}
	return 0
}

func nox_script_waypointGroupOff_5127B0(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForWaypointGroup(s.s, mapGroup, func(wp *Waypoint) {
		wp.Enable(false)
	})
	return 0
}

func nox_script_toggleObject_5127F0(s *noxScript) int {
	obj := s.PopObject()
	if obj != nil {
		obj.Toggle()
	}
	return 0
}

func nox_script_toggleWaypoint_512850(s *noxScript) int {
	waypoint := s.s.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		waypoint.Toggle()
	}
	return 0
}

func nox_script_toggleWaypointGroup_512870(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForWaypointGroup(s.s, mapGroup, func(wp *Waypoint) {
		wp.Toggle()
	})
	return 0
}

func nox_script_Hunt_515780(s *noxScript) int {
	v1 := s.PopObject()
	if v1 != nil {
		v1.AsUnit().Hunt()
	}
	return 0
}

func nox_script_unlockDoor_512C20(s *noxScript) int {
	obj := s.PopObject()
	if obj != nil && obj.Class().Has(object.ClassDoor) {
		*(*uint8)(unsafe.Add(obj.UpdateData, 1)) = 0
		s.s.AudioEventObj(sound.SoundUnlock, obj.AsUnit(), 0, 0)
	}
	return 0
}

func nox_script_lockDoor_512C60(s *noxScript) int {
	obj := s.PopObject()
	if obj != nil && obj.Class().Has(object.ClassDoor) {
		*(*uint8)(unsafe.Add(obj.UpdateData, 1)) = 5
		s.s.AudioEventObj(sound.SoundLock, obj.AsUnit(), 0, 0)
	}
	return 0
}

func nox_script_isOn_512CA0(s *noxScript) int {
	v1 := s.PopObject()
	if v1 != nil && v1.Flags().Has(object.FlagEnabled) {
		s.PushI32(1)
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_wpIsEnabled_512CE0(s *noxScript) int {
	waypoint := s.s.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil && (*(*uint32)(unsafe.Add(unsafe.Pointer(waypoint), 120*4)))&1 != 0 {
		s.PushI32(1)
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_doorIsLocked_512D20(s *noxScript) int {
	obj := s.PopObject()
	if obj != nil && obj.Class().Has(object.ClassDoor) && (*(*uint8)(unsafe.Add(obj.UpdateData, 1))) != 0 {
		s.PushI32(1)
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_JournalEntry_5154E0(s *noxScript) int {
	v0 := s.PopI32()
	v1 := s.PopString()
	v2 := s.PopI32()
	if v2 != 0 {
		v3 := s.scriptToObject(int(v2))
		if v3 != nil {
			C.nox_xxx_comJournalEntryAdd_427500(v3.CObj(), CString(v1), C.short(v0))
			if (v0 & 0xB) != 0 {
				s.s.AudioEventObj(sound.SoundJournalEntryAdd, v3.AsUnit(), 0, 0)
			}
		}
	} else {
		C.nox_xxx_comAddEntryAll_427550(CString(v1), C.short(v0))
	}
	return 0
}

func nox_script_intToString_512EA0(s *noxScript) int {
	v0 := s.PopI32()
	str := strconv.FormatInt(int64(v0), 10)
	s.PushString(str)
	return 0
}

func nox_script_floatToString_512ED0(s *noxScript) int {
	v0 := s.PopF32()
	str := strconv.FormatFloat(float64(v0), 'f', -1, 32)
	s.PushString(str)
	return 0
}

// create_sub_512FE0 creates anonymous function to call damage function with params
// TODO: Deprecate sub_512FE0 after remove all the usages
func create_sub_512FE0(a20 *Object, dmg, unknown int) func(*Object) {
	return func(obj *Object) {
		if dmg > 0 {
			owner := a20.FindOwnerChainPlayer()
			obj.callDamage(owner, a20, dmg, unknown)
		}
	}
}

// Before: [Target Object] [Damage Source] [Damage] [Damage Type]
// Cause damage from src to target
func nox_script_damage_512F80(s *noxScript) int {
	param1 := s.PopI32()
	param0 := s.PopI32()
	src := s.PopObject()
	dest := s.PopObject()
	if dest != nil {
		create_sub_512FE0(src, int(param0), int(param1))(dest)
	}
	return 0
}

// Before: [Target Group] [Damage Source] [Damage] [Damage Type]
// Cause damage from src to all objects in group
func nox_script_groupDamage_513010(s *noxScript) int {
	param1 := s.PopI32()
	param0 := s.PopI32()
	src := s.PopObject()
	destGroupInd := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(destGroupInd))
	scriptExecuteFnForObjectGroup(s.s, mapGroup, create_sub_512FE0(src, int(param0), int(param1)))
	return 0
}

// TODO: Rename to Roam
func nox_script_followNearestWaypoint_512910(s *noxScript) int {
	obj := s.PopObject()
	if obj != nil {
		obj.AsUnit().Wander()
	}
	return 0
}

func nox_script_groupRoam_512990(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) {
		obj.AsUnit().Wander()
	})
	return 0
}

func nox_script_gotoHome_512A00(s *noxScript) int {
	obj := s.PopObject()
	if obj != nil {
		obj.AsUnit().Return()
	}
	return 0
}

func nox_script_audioEven_512AC0(s *noxScript) int {
	waypoint := s.s.getWaypointByInd(int(s.PopI32()))
	soundName := s.PopString()
	if waypoint != nil {
		soundId := sound.ByName(soundName)
		s.s.AudioEventPos(soundId, waypoint.Pos(), 0, 0)
	}
	return 0
}

func nox_script_sayChat_512B90(s *noxScript) int {
	messageId := s.PopString()
	obj := s.PopObject()
	if obj != nil {
		v, _ := s.s.Strings().GetVariantInFile(strman.ID(messageId), "CScrFunc.c")
		C.nox_xxx_netSendChat_528AC0(obj.CObj(), internWStr(v.Str), 0)
		if noxflags.HasGame(noxflags.GameModeCoop) {
			C.nox_xxx_playDialogFile_44D900(internCStr(v.Str2), 100)
		}
	}
	return 0
}

func nox_script_Wander_513070(s *noxScript) int {
	v4 := s.PopF32()
	v0 := s.PopI32()
	obj := s.PopObject()
	if obj != nil {
		s.PushI32(int32(create_sub_5130E0(v4, v0)(s.s, obj)))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_WanderGroup_513160(s *noxScript) int {
	v4 := s.PopF32()
	v0 := s.PopI32()
	v1 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v1))
	fn := create_sub_5130E0(v4, v0)
	scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) { fn(s.s, obj) })
	return 0
}

func create_sub_5130E0(v5_0 float32, v5_1 int32) func(*Server, *Object) int {
	return func(s *Server, obj *Object) int {
		v2 := s.newObjectByTypeID("Mover")
		if v2 == nil {
			return 0
		}
		s.createObjectAt(v2, nil, obj.Pos())
		v5 := v2.updateDataMover()

		v5.field_7 = obj.CObj()
		v5.field_2 = C.int32_t(v5_1)
		v5.field_1 = C.float(v5_0)
		v5.field_0 = 0
		v2.VelVec = types.Pointf{0, 0}

		v2.Enable(true)
		s.Objs.AddToUpdatable(v2.SObj())
		return v2.ScriptID
	}
}

func nox_script_awardSpell_5131C0(s *noxScript) int {
	spellName := s.PopString()
	v4 := s.PopObject()

	spl := spell.ParseID(spellName)
	if spl != spell.SPELL_INVALID {
		if v4 != nil {
			v5 := C.nox_xxx_spellGrantToPlayer_4FB550(v4.CObj(), C.int(spl), 1, 0, 0)
			s.PushI32(int32(v5))
		} else {
			s.PushI32(0)
		}
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_awardSpellGroup_513230(s *noxScript) int {
	spellName := s.PopString()
	v1 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v1))
	spl := spell.ParseID(spellName)
	if spl == spell.SPELL_INVALID {
		return 0
	}
	scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) {
		var v2 int
		if noxflags.HasGame(noxflags.GameModeCoop) && obj.Class().Has(object.ClassPlayer) && asPlayerS(obj.SObj().UpdateDataPlayer().Player).spell_lvl[spl] == 0 {
			v2 = 1
		} else {
			v2 = 0
		}
		C.nox_xxx_spellGrantToPlayer_4FB550(obj.CObj(), C.int(spl), 1, C.int(v2), 0)
	})
	return 0
}

func nox_script_enchant_5132E0(s *noxScript) int {
	v5 := s.PopF32()
	v8 := s.PopString()
	v3 := s.PopObject()
	id, ok := server.ParseEnchant(v8)
	if ok {
		if v3 != nil {
			dur := int(float32(s.s.TickRate()) * v5)
			v3.ApplyEnchant(id, dur, 5)
		}
	}
	return 0
}

func nox_script_groupEnchant_5133B0(s *noxScript) int {
	durationSecs := s.PopF32()
	enchantName := s.PopString()
	groupInd := s.PopI32()

	id, ok := server.ParseEnchant(enchantName)
	mapGroup := s.s.mapGroupByInd(int(groupInd))
	if ok {
		dur := int(float32(s.s.TickRate()) * durationSecs)
		scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) {
			obj.ApplyEnchant(id, dur, 5)
		})
	}
	return 0
}

func nox_script_getHost_513460(s *noxScript) int {
	// Note: original C code got the player from `s.s.getPlayerByInd(MaxPlayers - 1)`
	v0 := HostPlayerUnit()
	if v0 != nil {
		s.PushI32(int32(v0.ScriptID))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_getWaypointX_513570(s *noxScript) int {
	waypoint := s.s.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		s.PushF32(waypoint.Pos().X)
	} else {
		s.PushI32(0) // f32 0 == i32 0
	}
	return 0
}

func nox_script_getWaypointY_5135F0(s *noxScript) int {
	waypoint := s.s.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		s.PushF32(waypoint.Pos().Y)
	} else {
		s.PushI32(0) // f32 0 == i32 0
	}
	return 0
}

func nox_script_getUnitLook_513670(s *noxScript) int {
	v1 := s.PopObject()
	if v1 != nil {
		s.PushI32(int32(v1.Dir1()))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_unitHeight_513630(s *noxScript) int {
	v1 := s.PopObject()
	if v1 != nil {
		s.PushF32(v1.Z())
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_moveObject_5136A0(s *noxScript) int {
	dy := s.PopF32()
	dx := s.PopF32()
	obj := s.PopObject()
	if obj != nil {
		pos := s.DPosf().Add(types.Pointf{X: dx, Y: dy})
		obj.SetPos(pos)
	}
	return 0
}

func nox_script_moveWaypoint_513700(s *noxScript) int {
	dy := s.PopF32()
	dx := s.PopF32()
	waypoint := s.s.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		pos := s.DPosf().Add(types.Pointf{X: dx, Y: dy})
		waypoint.SetPos(pos)
	}
	return 0
}

func nox_script_openWallGroup_512010(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))

	scriptExecuteFnForWallGroup(s.s, mapGroup, func(wall *Wall) {
		wall.Enable(false)
	})
	return 0
}

func nox_script_closeWallGroup_512100(s *noxScript) int {
	groupInd := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(groupInd))

	scriptExecuteFnForWallGroup(s.s, mapGroup, func(wall *Wall) {
		wall.Enable(true)
	})
	return 0
}

func nox_script_waypointGroupOn_5126F0(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForWaypointGroup(s.s, mapGroup, func(wp *Waypoint) {
		wp.Enable(true)
	})
	return 0
}

func nox_script_toggleObjectGroup_512810(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) {
		obj.Toggle()
	})
	return 0
}

func nox_script_create_512F10(s *noxScript) int {
	waypointInd := s.PopI32()
	wp := s.s.getWaypointByInd(int(waypointInd))
	objectTypeId := s.PopString()

	if wp != nil {
		obj := s.s.newObjectByTypeID(objectTypeId)
		if obj == nil {
			s.PushI32(0)
			return 0
		}
		s.s.createObjectAt(obj, nil, wp.Pos())
		s.PushI32(int32(obj.ScriptID))
	} else {
		scriptLog.Printf("noxscript: cannot find waypoint from idx: %v", waypointInd)
		s.PushI32(0)
	}
	return 0
}

func nox_script_raise_513750(s *noxScript) int {
	zValue := s.PopF32()
	obj := s.PopObject()
	if obj != nil {
		obj.SetZ(zValue)
	}
	return 0
}

func nox_script_faceAngle_513780(s *noxScript) int {
	dir := s.PopI32()
	obj := s.PopObject()
	if obj != nil {
		v3 := server.Dir16(nox_xxx_math_roundDir(dir))
		obj.setAllDirs(v3)
	}
	return 0
}

func nox_script_pushObject_5137D0(s *noxScript) int {
	dy := s.PopF32()
	dx := s.PopF32()
	obj := s.PopObject()
	if obj != nil {
		force := obj.Force()
		force.X += dx
		force.Y += dy
		obj.ForceVec = force
	}
	return 0
}

func nox_script_pushObjectTo_513820(s *noxScript) int {
	yPos := s.PopF32()
	xPos := s.PopF32()
	force := s.PopF32()
	obj := s.PopObject()
	if obj != nil {
		dpos := s.DPosf()
		xDir := obj.Pos().X - xPos + dpos.X
		yDir := obj.Pos().Y - yPos + dpos.Y
		dirLength := float32(math.Hypot(float64(xDir), float64(yDir)))
		obj.ApplyForce(types.Pointf{X: force * xDir / dirLength, Y: force * yDir / dirLength})
	}
	return 0
}

func nox_script_getFirstInvItem_5138B0(s *noxScript) int {
	v2 := s.PopObject()
	if v2 != nil {
		v3 := v2.FirstItem()
		if v3 != nil {
			s.PushI32(int32(v3.ScriptID))
			return 0
		}
	}
	s.PushI32(0)
	return 0
}

func nox_script_getNextInvItem_5138E0(s *noxScript) int {
	v2 := s.PopObject()
	if v2 != nil {
		v3 := v2.NextItem()
		if v3 != nil {
			s.PushI32(int32(v3.ScriptID))
			return 0
		}
	}
	s.PushI32(0)
	return 0
}

func zombieSetStayDead(obj *Object) {
	if obj != nil {
		if obj.Class().Has(object.ClassMonster) {
			obj.AsUnit().UpdateDataMonster().Field360 |= 0x100000
		}
	}
}

func nox_script_ZombieStayDown_516C70(s *noxScript) int {
	v1 := s.PopObject()
	if v1 != nil {
		zombieSetStayDead(v1)
	}
	return 0
}

func nox_script_ZombieStayDownGroup_516CB0(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(s.s, mapGroup, zombieSetStayDead)

	return 0
}

func nox_script_hasItem_513910(s *noxScript) int {
	item := s.PopObject()
	holder := s.PopObject()
	if holder != nil && item != nil && holder.HasItem(item) {
		s.PushI32(1)
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_getInvHolder_513960(s *noxScript) int {
	obj := s.PopObject()
	if obj == nil {
		s.PushI32(0)
		return 0
	}
	holder := obj.InventoryHolder()
	if holder != nil {
		s.PushI32(int32(holder.ScriptID))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_pickup_5139A0(s *noxScript) int {
	objGold := s.s.ObjectTypeID("Gold")
	objQuestGoldPile := s.s.ObjectTypeID("QuestGoldPile")
	objQuestGoldChest := s.s.ObjectTypeID("QuestGoldChest")

	item := s.PopObject()
	picker := s.PopObject()
	if picker == nil || item == nil {
		s.PushI32(0)
		return 0
	}
	if noxflags.HasGame(noxflags.GameModeCoop) && picker.Class().Has(object.ClassPlayer) &&
		*memmap.PtrUint32(0x5D4594, 2386844) != s.s.Frame() {
		*memmap.PtrUint32(0x5D4594, 2386844) = s.s.Frame()
		C.dword_5d4594_2386848 = 0
		C.dword_5d4594_2386852 = 0
	}

	if noxflags.HasGame(noxflags.GameModeCoop) && picker.Class().Has(object.ClassPlayer) {
		v5 := int(picker.TypeInd)
		if v5 != objGold && v5 != objQuestGoldPile && v5 != objQuestGoldChest {
			C.nox_xxx_playerCanCarryItem_513B00(picker.CObj(), item.CObj())
		}
	}

	v6 := int32(C.nox_xxx_inventoryServPlace_4F36F0(picker.CObj(), item.CObj(), 1, 1))
	if v6 == 1 && picker.Class().Has(object.ClassPlayer) && noxflags.HasGame(noxflags.GameModeCoop) && int(item.TypeInd) != objGold {
		C.dword_5d4594_2386848 += 1
		s.PushI32(1)
		return 0
	}
	s.PushI32(v6)
	return 0
}

func nox_script_Idle_515800(s *noxScript) int {
	unit := s.PopObject()
	if unit != nil {
		unit.AsUnit().Idle()
	}
	return 0
}

func nox_script_GroupIdle_515850(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) {
		obj.AsUnit().Idle()
	})
	return 0
}

func nox_script_Follow_515880(s *noxScript) int {
	v3 := s.PopObject()
	v2 := s.PopObject()
	if v2 != nil && v3 != nil {
		v2.AsUnit().Follow(v3)
	}
	return 0
}

func nox_script_FollowGroup_515910(s *noxScript) int {
	v2 := s.PopObject()
	v1 := s.PopI32()
	if v2 != nil {
		mapGroup := s.s.mapGroupByInd(int(v1))
		scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) {
			obj.AsUnit().Follow(v2)
		})
	}
	return 0
}

func nox_script_RaiseZombie_516CE0(s *noxScript) int {
	v1 := s.PopObject()
	if v1 != nil {
		C.sub_516D00(v1.CObj())
	}
	return 0
}

func nox_script_RaiseZombieGroup_516D40(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(s.s, mapGroup, func(obj *Object) {
		C.sub_516D00(obj.CObj())
	})
	return 0
}

func nox_script_drop_513C10(s *noxScript) int {
	item := s.PopObject()
	holder := s.PopObject()
	if holder != nil && item != nil {
		v4 := int32(holder.forceDrop(item))
		s.PushI32(v4)
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_TestBuffs_513C70(s *noxScript) int {
	enchantName := s.PopString()
	obj := s.PopObject()
	enchantId, ok := server.ParseEnchant(enchantName)
	if obj != nil && ok {
		hasEnchant := obj.HasEnchant(enchantId)
		s.PushI32(int32(bool2int(hasEnchant)))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_HasClass_516210(s *noxScript) int {
	v5 := s.PopString()
	v7 := s.PopObject()
	if v7 != nil {
		cls, err := object.ParseClass(v5)
		if err != nil {
			panic(err)
		}
		s.PushI32(int32(bool2int(v7.Class().Has(cls))))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_cancelBuff_513D00(s *noxScript) int {
	enchantName := s.PopString()
	obj := s.PopObject()
	enchantId, ok := server.ParseEnchant(enchantName)
	if ok && obj != nil {
		obj.DisableEnchant(enchantId)
	}
	return 0
}

func nox_script_getCurrentHP_513D70(s *noxScript) int {
	v1 := s.PopObject()
	if v1 != nil {
		cur, _ := v1.Health()
		s.PushI32(int32(cur))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_getMaxHP_513DB0(s *noxScript) int {
	v1 := s.PopObject()
	if v1 != nil {
		_, max := v1.Health()
		s.PushI32(int32(max))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_restoreHP_513DF0(s *noxScript) int {
	delta := s.PopI32()
	obj := s.PopObject()
	if obj != nil && delta > 0 {
		C.nox_xxx_unitAdjustHP_4EE460(obj.CObj(), C.int(delta))
	}
	return 0
}

func nox_script_getDistance_513E20(s *noxScript) int {
	y2 := s.PopF32()
	x2 := s.PopF32()
	y1 := s.PopF32()
	x1 := s.PopF32()

	v5 := float32(math.Hypot(float64(y1-y2), float64(x1-x2)))
	s.PushF32(v5)
	return 0
}

func nox_script_FaceObject_514050(s *noxScript) int {
	tgt := s.PopObject()
	obj := s.PopObject()

	if obj != nil && tgt != nil {
		vec := tgt.Pos()
		dir := server.DirFromVec(vec.Sub(obj.Pos()))
		obj.setAllDirs(dir)
	}
	return 0
}

func nox_script_Walk_5140B0(s *noxScript) int {
	dy := s.PopF32()
	dx := s.PopF32()
	obj := s.PopObject()
	if obj != nil {
		dpos := s.DPosf()
		posy := dpos.X + dy
		posx := dpos.Y + dx
		obj.AsUnit().WalkTo(types.Pointf{X: posx, Y: posy})
	}
	return 0
}

func nox_script_GroupWalk_514170(s *noxScript) int {
	dy := s.PopF32()
	dx := s.PopF32()
	groupInd := s.PopI32()
	dpos := s.DPosf()

	posy := dpos.X + dy
	posx := dpos.Y + dx
	dstPoint := types.Pointf{X: posx, Y: posy}
	mapGroup := s.s.mapGroupByInd(int(groupInd))
	if mapGroup != nil {
		// Unlike scriptExecuteFnForObjectGroup, it does not nest into child groups.
		for item := mapGroup.First(); item != nil; item = item.Next() {
			obj := s.s.GetObjectByInd(item.Ind())
			if obj != nil {
				obj.AsUnit().WalkTo(dstPoint)
			}
		}
	}
	return 0
}

func nox_script_SetOwner_514490(s *noxScript) int {
	obj := s.PopObject()
	owner := s.PopObject()

	obj.SetOwner(owner)
	return 0
}

func nox_script_SetOwnerGroup_5144C0(s *noxScript) int {
	v0 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v0))
	v2 := s.PopObject()

	if mapGroup != nil {
		for item := mapGroup.First(); item != nil; item = item.Next() {
			obj := s.s.GetObjectByInd(item.Ind())
			if obj != nil {
				C.nox_xxx_unitSetOwner_4EC290(v2.CObj(), obj.CObj())
			}
		}
	}
	return 0
}

func nox_script_SetOwners_514510(s *noxScript) int {
	v3 := s.PopObject()
	v1 := s.PopI32()
	mapGroup := s.s.mapGroupByInd(int(v1))

	if mapGroup != nil {
		for item := mapGroup.First(); item != nil; item = item.Next() {
			obj := s.s.GetObjectByInd(item.Ind())
			if obj != nil {
				C.nox_xxx_unitSetOwner_4EC290(obj.CObj(), v3.CObj())
			}
		}
	}
	return 0
}

func nox_script_SetOwnersGroup_514570(s *noxScript) int {
	v0 := s.PopI32()
	v1 := s.PopI32()
	v2 := s.s.mapGroupByInd(int(v1))
	v3 := s.s.mapGroupByInd(int(v0))

	if v2 != nil && v3 != nil {
		for i := v2.First(); i != nil; i = i.Next() {
			v6 := s.s.GetObjectByInd(i.Ind())
			if v6 != nil {
				for j := v3.First(); j != nil; j = j.Next() {
					v8 := s.s.GetObjectByInd(j.Ind())
					if v8 != nil {
						C.nox_xxx_unitSetOwner_4EC290(v6.CObj(), v8.CObj())
					}
				}
			}
		}
	}
	return 0
}

func nox_script_IsOwnedBy_5145F0(s *noxScript) int {
	owner := s.PopObject()
	obj := s.PopObject()
	s.PushBool(obj.HasOwner(owner))
	return 0
}

// From (object, object group), push 1 if all object group is parent of input obj, otherwise push 0
func nox_script_IsOwnedByGroup_514630(s *noxScript) int {
	groupInd := s.PopI32()
	obj := s.PopObject()
	mapGroup := s.s.mapGroupByInd(int(groupInd))
	if mapGroup != nil {
		for it := mapGroup.First(); it != nil; it = it.Next() {
			item := s.s.GetObjectByInd(it.Ind())
			if !obj.HasOwner(item) {
				s.PushI32(0)
				return 0
			}
		}
	}
	s.PushI32(1)
	return 0
}

// From (object, object group), push 1 if obj is parent of all object group, otherwise push 0
func nox_script_IsOwnedByAny_5146B0(s *noxScript) int {
	groupInd := s.PopI32()
	obj := s.PopObject()
	mapGroup := s.s.mapGroupByInd(int(groupInd))
	if mapGroup != nil {
		for it := mapGroup.First(); it != nil; it = it.Next() {
			item := s.s.GetObjectByInd(it.Ind())
			if !item.HasOwner(obj) {
				s.PushI32(0)
				return 0
			}
		}
	}
	s.PushI32(1)
	return 0
}

// From (object group A, object group B), push 1 if all in A is owned by all in B, otherwise push 0
func nox_script_IsOwnedByAnyGroup_514730(s *noxScript) int {
	groupIndB := s.PopI32()
	groupIndA := s.PopI32()
	groupB := s.s.mapGroupByInd(int(groupIndB))
	groupA := s.s.mapGroupByInd(int(groupIndA))
	if groupB == nil || groupA == nil {
		s.PushI32(1)
		return 0
	}
	for iterB := groupB.First(); iterB != nil; iterB = iterB.Next() {
		itemB := s.s.GetObjectByInd(iterB.Ind())
		if itemB != nil {
			for iterA := groupA.First(); iterA != nil; iterA = iterA.Next() {
				itemA := s.s.GetObjectByInd(iterA.Ind())
				if itemA != nil {
					if !itemA.HasOwner(itemB) {
						s.PushI32(0)
						return 0
					}
				}
			}
		}
	}
	s.PushI32(1)
	return 0
}

func nox_script_ClearOwner_5147E0(s *noxScript) int {
	v1 := s.PopObject()
	v1.SetOwner(nil)
	return 0
}

func chatTimerFrames(mgr *strman.StringManager, msgId string, obj *Object, durationTicks uint16) {
	v, _ := mgr.GetVariantInFile(strman.ID(msgId), "CScrFunc.c")

	C.nox_xxx_netSendChat_528AC0(obj.CObj(), internWStr(v.Str), C.ushort(durationTicks))
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.nox_xxx_playDialogFile_44D900(internCStr(v.Str2), 100)
	}
}

func nox_script_ChatTimerSeconds_514A80(s *noxScript) int {
	durationSecs := s.PopU32()
	msgId := s.PopString()
	obj := s.PopObject()
	if obj != nil {
		durationFrames := uint16(durationSecs * s.s.TickRate())
		chatTimerFrames(s.s.Strings(), msgId, obj, durationFrames)
	}
	return 0
}

func nox_script_ChatTimerFrames_514B10(s *noxScript) int {
	durationFrames := s.PopU32()
	msgId := s.PopString()
	obj := s.PopObject()
	if obj != nil {
		chatTimerFrames(s.s.Strings(), msgId, obj, uint16(durationFrames))
	}
	return 0
}

func nox_script_GetElevatorStat_5154A0(s *noxScript) int {
	v2 := s.PopObject()
	if v2 != nil {
		if v2.Class().Has(object.ClassElevator) {
			s.PushI32(int32(v2.updateDataElevator().field_3))
			return 0
		}
	}
	s.PushI32(-1)
	return 0
}
