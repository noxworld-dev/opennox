package opennox

/*
#include "defs.h"
int nox_script_getWall_511EB0();
int nox_script_closeWallGroup_512100();
int nox_script_toggleWallGroup_512260();
int nox_script_wallGroupBreak_5122F0();
int nox_script_groupGoTo_512500();
int nox_script_groupLookAtDirection_512610();
int nox_script_objGroupOn_512690();
int nox_script_objGroupOff_512750();
int nox_script_waypointGroupOff_5127B0();
int nox_script_toggleObject_5127F0();
int nox_script_toggleWaypointGroup_512870();
int nox_script_deleteObjectGroup_5128D0();
int nox_script_groupRoam_512990();
int nox_script_groupDamage_513010();
int nox_script_WanderGroup_513160();
int nox_script_awardSpellGroup_513230();
int nox_script_groupEnchant_5133B0();
int nox_script_canInteract_513E80();
int nox_script_Fn5E_513F70();
int nox_script_GetHostInfo_513FA0();
int nox_script_SetOwner_514490();
int nox_script_SetOwnerGroup_5144C0();
int nox_script_SetOwners_514510();
int nox_script_SetOwnersGroup_514570();
int nox_script_IsOwnedBy_5145F0();
int nox_script_IsOwnedByGroup_514630();
int nox_script_IsOwnedByAny_5146B0();
int nox_script_IsOwnedByAnyGroup_514730();
int nox_script_ClearOwner_5147E0();
int nox_script_ChatTimerSeconds_514A80();
int nox_script_ChatTimerFrames_514B10();
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
int nox_script_GetElevatorStat_5154A0();
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
void nox_xxx_comJournalEntryAdd_427500(int a1, char* a2, short a3);
int nox_xxx_comAddEntryAll_427550(char* a1, short a2);
int nox_script_addString_512E40(char* a1);
void nox_xxx_audCreate_501A30(int a1, float2* a2, int a3, int a4);
int nox_xxx_netSendChat_528AC0(nox_object_t* a1, wchar_t* a2, wchar_t a3);
int nox_xxx_playDialogFile_44D900(int a1, int a2);
uint32_t* sub_5130E0(int a1, uint32_t* a2);
int nox_xxx_spellGrantToPlayer_4FB550(nox_object_t* a1, int a2, int a3, int a4, int a5);
int nox_xxx_inventoryServPlace_4F36F0(nox_object_t* a1p, nox_object_t* a2p, int a3, int a4);
void nox_xxx_playerCanCarryItem_513B00(nox_object_t* a1p, nox_object_t* a2p);
unsigned int sub_516D00(nox_object_t* a1);
void nox_xxx_unitAdjustHP_4EE460(nox_object_t* unit, int dv);
*/
import "C"
import (
	"image"
	"math"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc"

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

func wrapScriptC(fnc unsafe.Pointer) func() int {
	return func() int {
		return cgoCallIntVoidFunc(fnc)
	}
}

//export nox_script_callBuiltin_508B70
func nox_script_callBuiltin_508B70(i, fi C.int) C.int {
	return C.int(noxServer.noxScript.callBuiltin(int(i), int(fi)))
}

func (s *noxScript) callBuiltin(i, fi int) int {
	if fi < 0 || fi >= len(noxScriptBuiltins) {
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
		s.f40 = s.scriptField40(i)
		s.f44 = s.scriptField44(i)
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

func (s *noxScript) callBuiltinNative(fi int) int {
	if res, ok := s.panicScriptCall(fi); ok {
		return res
	}
	return noxScriptBuiltins[fi]()
}

func (s *noxScript) builtinNeedsFields4044(fi int) bool {
	// TODO: 7 items in the array, but the count is set to 5; why?
	var check = []int{
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

func (s *noxScript) builtinNeedsField36(fi int) bool {
	switch fi {
	case 60, 110, 111, 112, 113:
		return true
	}
	return false
}

var noxScriptBuiltins = []func() int{
	0:   noxScriptCompare("nox_script_getWall_511EB0", wrapScriptC(C.nox_script_getWall_511EB0), nox_script_getWall_511EB0),
	1:   nox_script_openSecretWall_511F50,
	2:   nox_script_openWallGroup_512010,
	3:   nox_script_closeWall_512040,
	4:   wrapScriptC(C.nox_script_closeWallGroup_512100),
	5:   nox_script_toggleWall_512130,
	6:   wrapScriptC(C.nox_script_toggleWallGroup_512260),
	7:   nox_script_wallBreak_512290,
	8:   wrapScriptC(C.nox_script_wallGroupBreak_5122F0),
	9:   nox_script_secondTimer_512320,
	10:  nox_script_frameTimer_512350,
	11:  nox_script_moverOrMonsterGo_512370,
	12:  wrapScriptC(C.nox_script_groupGoTo_512500),
	13:  nox_script_lookAtDirection_512560,
	14:  wrapScriptC(C.nox_script_groupLookAtDirection_512610),
	15:  nox_script_objectOn_512670,
	16:  wrapScriptC(C.nox_script_objGroupOn_512690),
	17:  nox_script_waypointOn_5126D0,
	18:  nox_script_waypointGroupOn_5126F0,
	19:  nox_script_objectOff_512730,
	20:  wrapScriptC(C.nox_script_objGroupOff_512750),
	21:  nox_script_waypointOff_512790,
	22:  wrapScriptC(C.nox_script_waypointGroupOff_5127B0),
	23:  nox_script_toggleObject_5127F0,
	24:  nox_script_toggleObjectGroup_512810,
	25:  nox_script_toggleWaypoint_512850,
	26:  wrapScriptC(C.nox_script_toggleWaypointGroup_512870),
	27:  nox_script_deleteObject_5128B0,
	28:  wrapScriptC(C.nox_script_deleteObjectGroup_5128D0),
	29:  nox_script_followNearestWaypoint_512910,
	30:  wrapScriptC(C.nox_script_groupRoam_512990),
	31:  nox_script_getObject2_5129C0,
	32:  nox_script_getObject3_5129E0,
	33:  nox_script_gotoHome_512A00,
	34:  nox_script_audioEven_512AC0,
	35:  nox_script_printToCaller_512B10,
	36:  nox_script_printToAll_512B60,
	37:  nox_script_sayChat_512B90,
	38:  nox_script_returnOne_512C10,
	39:  nox_script_unlockDoor_512C20,
	40:  nox_script_lockDoor_512C60,
	41:  nox_script_isOn_512CA0,
	42:  nox_script_wpIsEnabled_512CE0,
	43:  nox_script_doorIsLocked_512D20,
	44:  nox_script_randomFloat_512D70,
	45:  nox_script_randomInt_512DB0,
	46:  nox_script_timerSecSpecial_512DE0,
	47:  nox_script_specialTimer_512E10,
	48:  nox_script_intToString_512EA0,
	49:  nox_script_floatToString_512ED0,
	50:  nox_script_create_512F10,
	51:  nox_script_damage_512F80,
	52:  wrapScriptC(C.nox_script_groupDamage_513010),
	53:  nox_script_Wander_513070,
	54:  wrapScriptC(C.nox_script_WanderGroup_513160),
	55:  nox_script_awardSpell_5131C0,
	56:  wrapScriptC(C.nox_script_awardSpellGroup_513230),
	57:  nox_script_enchant_5132E0,
	58:  wrapScriptC(C.nox_script_groupEnchant_5133B0),
	59:  nox_script_getHost_513460,
	60:  nox_script_objectGet_513490,
	61:  nox_script_getObjectX_513530,
	62:  nox_script_getWaypointX_513570,
	63:  nox_script_getObjectY_5135B0,
	64:  nox_script_getWaypointY_5135F0,
	65:  nox_script_unitHeight_513630,
	66:  nox_script_getUnitLook_513670,
	67:  nox_script_moveObject_5136A0,
	68:  nox_script_moveWaypoint_513700,
	69:  nox_script_raise_513750,
	70:  nox_script_faceAngle_513780,
	71:  nox_script_pushObject_5137D0,
	72:  nox_script_pushObjectTo_513820,
	73:  nox_script_getFirstInvItem_5138B0,
	74:  nox_script_getNextInvItem_5138E0,
	75:  nox_script_hasItem_513910,
	76:  nox_script_getInvHolder_513960,
	77:  nox_script_pickup_5139A0,
	78:  nox_script_drop_513C10,
	79:  nox_script_HasClass_516210,
	80:  nox_script_builtin_513C60,
	81:  nox_script_TestBuffs_513C70,
	82:  nox_script_cancelBuff_513D00,
	83:  nox_script_getCurrentHP_513D70,
	84:  nox_script_getMaxHP_513DB0,
	85:  nox_script_restoreHP_513DF0,
	86:  nox_script_getDistance_513E20,
	87:  noxScriptCompare("nox_script_canInteract_513E80", wrapScriptC(C.nox_script_canInteract_513E80), nox_script_canInteract_513E80),
	88:  nox_script_fn58_513F10,
	89:  nox_script_fn59_513F20,
	90:  nox_script_fn5A_513F30,
	91:  nox_script_fn5B_513F40,
	92:  nox_script_Fn5C_513F50,
	93:  nox_script_Fn5D_513F60,
	94:  wrapScriptC(C.nox_script_Fn5E_513F70),
	95:  wrapScriptC(C.nox_script_GetHostInfo_513FA0),
	96:  nox_script_FaceObject_514050,
	97:  nox_script_Walk_5140B0,
	98:  nox_script_GroupWalk_514170,
	99:  nox_script_CancelTimer_5141F0,
	100: nox_script_Effect_514210,
	101: wrapScriptC(C.nox_script_SetOwner_514490),
	102: wrapScriptC(C.nox_script_SetOwnerGroup_5144C0),
	103: wrapScriptC(C.nox_script_SetOwners_514510),
	104: wrapScriptC(C.nox_script_SetOwnersGroup_514570),
	105: wrapScriptC(C.nox_script_IsOwnedBy_5145F0),
	106: wrapScriptC(C.nox_script_IsOwnedByGroup_514630),
	107: wrapScriptC(C.nox_script_IsOwnedByAny_5146B0),
	108: wrapScriptC(C.nox_script_IsOwnedByAnyGroup_514730),
	109: wrapScriptC(C.nox_script_ClearOwner_5147E0),
	110: nox_script_Waypoint_514800,
	111: nox_script_GetWaypointGroup_5148A0,
	112: nox_script_GetObjectGroup_514940,
	113: nox_script_GetWallGroup_5149E0,
	114: wrapScriptC(C.nox_script_ChatTimerSeconds_514A80),
	115: wrapScriptC(C.nox_script_ChatTimerFrames_514B10),
	116: nox_script_Pop2_74_514BA0,
	117: nox_script_RemoveChat_514BB0,
	118: nox_script_NoChatAll_514BD0,
	119: wrapScriptC(C.nox_script_SetQuestInt_514BE0),
	120: wrapScriptC(C.nox_script_SetQuestFloat_514C10),
	121: wrapScriptC(C.nox_script_GetQuestInt_514C40),
	122: wrapScriptC(C.nox_script_GetQuestFloat_514C60),
	123: wrapScriptC(C.nox_script_ResetQuestStatus_514C90),
	124: wrapScriptC(C.nox_script_IsTrigger_514CB0),
	125: wrapScriptC(C.nox_script_IsCaller_514CF0),
	126: wrapScriptC(C.nox_script_SetDialog_514D90),
	127: wrapScriptC(C.nox_script_CancelDialog_514DF0),
	128: wrapScriptC(C.nox_script_DialogPortrait_514E30),
	129: wrapScriptC(C.nox_script_TellStory_514E90),
	130: wrapScriptC(C.nox_script_StartDialog_514ED0),
	131: nox_script_CastObject2_514F10,
	132: nox_script_CastObjectLocation_514FC0,
	133: nox_script_CastLocationObject_515060,
	134: nox_script_CastLocation2_515130,
	135: nox_script_UnBlind_515200,
	136: nox_script_Blind_515220,
	137: nox_script_WideScreen_515240,
	138: wrapScriptC(C.nox_script_GetElevatorStat_5154A0),
	139: wrapScriptC(C.nox_script_Guard_515600),
	140: wrapScriptC(C.nox_script_GuardGroup_515700),
	141: nox_script_Hunt_515780,
	142: wrapScriptC(C.nox_script_HuntGroup_5157D0),
	143: nox_script_Idle_515800,
	144: nox_script_GroupIdle_515850,
	145: nox_script_Follow_515880,
	146: nox_script_FollowGroup_515910,
	147: wrapScriptC(C.nox_script_AgressionLevel_515950),
	148: wrapScriptC(C.nox_script_AggressionLevelGroup_5159B0),
	149: wrapScriptC(C.nox_script_HitLocation_5159E0),
	150: wrapScriptC(C.nox_script_HitLocationGroup_515AE0),
	151: wrapScriptC(C.nox_script_HitFarLocation_515B30),
	152: wrapScriptC(C.nox_script_HitFarLocationGroup_515BF0),
	153: wrapScriptC(C.nox_script_SetRoamFlag_515C40),
	154: wrapScriptC(C.nox_script_SetRoamFlagGroup_515CB0),
	155: wrapScriptC(C.nox_script_Attack_515CF0),
	156: wrapScriptC(C.nox_script_AttackGroup_515DB0),
	157: nox_script_JournalEntry_5154E0,
	158: wrapScriptC(C.nox_script_JournalDelete_515550),
	159: wrapScriptC(C.nox_script_JournalEdit_5155A0),
	160: wrapScriptC(C.nox_script_RetreatLevel_515DF0),
	161: wrapScriptC(C.nox_script_RetreatLevelGroup_515E50),
	162: wrapScriptC(C.nox_script_SetResumeLevel_515E80),
	163: wrapScriptC(C.nox_script_SetResumeLevelGroup_515EE0),
	164: wrapScriptC(C.nox_script_RunAway_515F10),
	165: wrapScriptC(C.nox_script_RunAwayGroup_516000),
	166: wrapScriptC(C.nox_script_PauseObject_516060),
	167: wrapScriptC(C.nox_script_PauseObjectGroup_5160F0),
	168: nox_script_IsAttackedBy_5161C0,
	169: wrapScriptC(C.nox_script_GetGold_516120),
	170: wrapScriptC(C.nox_script_ChangeGold_516160),
	171: wrapScriptC(C.nox_script_DialogResult_5163C0),
	172: wrapScriptC(C.nox_script_GiveExp_516190),
	173: wrapScriptC(C.nox_script_HasSubclass_5162D0),
	174: nox_script_ForceAutosave_516400,
	175: nox_script_Music_516430,
	176: wrapScriptC(C.nox_script_StartupScreen_516600),
	177: wrapScriptC(C.nox_script_IsTalking_5166A0),
	178: wrapScriptC(C.nox_script_GetTrigger_514D30),
	179: wrapScriptC(C.nox_script_GetCaller_514D60),
	180: wrapScriptC(C.nox_script_MakeFriendly_516720),
	181: wrapScriptC(C.nox_script_MakeEnemy_516760),
	182: wrapScriptC(C.nox_script_BecomePet_5167D0),
	183: wrapScriptC(C.nox_script_BecomeEnemy_516810),
	184: wrapScriptC(C.nox_script_builtin_516790),
	185: wrapScriptC(C.nox_script_builtin_516850),
	186: wrapScriptC(C.nox_script_OblivionGive_516890),
	187: nox_script_DeathScreen_516680,
	188: nox_script_Frozen_516920,
	189: nox_script_NoWallSound_516960,
	190: nox_script_SetCallback_516970,
	191: wrapScriptC(C.nox_script_DeleteObjectTimer_516A50),
	192: wrapScriptC(C.nox_script_TrapSpells_516B40),
	193: wrapScriptC(C.nox_script_PlayerIsTrading_5166E0),
	194: nox_script_ClearMessages_516BC0,
	195: wrapScriptC(C.nox_script_SetShopkeeperGreet_516BE0),
	196: nox_script_StopAllFades_516C10,
	197: wrapScriptC(C.nox_script_IsSummoned_516C30),
	198: nox_script_ZombieStayDown_516C70,
	199: nox_script_ZombieStayDownGroup_516CB0,
	200: nox_script_RaiseZombie_516CE0,
	201: nox_script_RaiseZombieGroup_516D40,
	202: nox_script_MusicPushEvent_5164A0,
	203: nox_script_MusicPopEvent_5164E0,
	204: nox_script_ClearMusic_516520,
	205: wrapScriptC(C.nox_script_ObjIsGameball_516D70),
	206: wrapScriptC(C.nox_script_ObjIsCrown_516DC0),
	207: nox_script_EndGame_516E10,
	208: nox_script_StartGame_516C20,
	209: nox_script_ChangeScore_516E30,
	210: nox_script_GetScore_516EA0,
}

func nox_script_secondTimer_512320() int {
	s := &noxServer.noxScript
	fnc := int(s.PopU32())
	dt := s.PopU32()
	s.PushU32(s.newScriptTimer(int(dt*s.s.TickRate()), fnc, 0))
	return 0
}

func nox_script_frameTimer_512350() int {
	s := &noxServer.noxScript
	fnc := int(s.PopU32())
	df := int(s.PopU32())
	s.PushU32(s.newScriptTimer(df, fnc, 0))
	return 0
}

func nox_script_deleteObject_5128B0() int {
	s := &noxServer.noxScript
	if obj := s.PopObject(); obj != nil {
		obj.Delete()
	}
	return 0
}

func nox_script_getObject2_5129C0() int {
	s := &noxServer.noxScript
	_ = s.PopObject()
	return 0
}

func nox_script_getObject3_5129E0() int {
	s := &noxServer.noxScript
	_ = s.PopObject()
	return 0
}

func nox_script_printToCaller_512B10() int {
	s := &noxServer.noxScript
	strID := s.PopString()
	if c := s.Caller().AsUnit(); c != nil && c.Class().Has(object.ClassPlayer) {
		str := s.s.Strings().GetStringInFile(strman.ID(strID), "CScrFunc.c")
		nox_xxx_netSendLineMessage_4D9EB0(c, str)
	}
	return 0
}

func nox_script_printToAll_512B60() int {
	s := &noxServer.noxScript
	strID := s.PopString()
	str := s.s.Strings().GetStringInFile(strman.ID(strID), "CScrFunc.c")
	PrintToPlayers(str)
	return 0
}

func nox_script_returnOne_512C10() int { return 1 }

func nox_script_randomFloat_512D70() int {
	s := &noxServer.noxScript
	max := float64(s.PopF32())
	min := float64(s.PopF32())
	val := noxRndCounter1.FloatClamp(min, max)
	s.PushF32(float32(val))
	return 0
}

func nox_script_randomInt_512DB0() int {
	s := &noxServer.noxScript
	max := int(s.PopU32())
	min := int(s.PopU32())
	val := noxRndCounter1.IntClamp(min, max)
	s.PushI32(int32(val))
	return 0
}

func nox_script_timerSecSpecial_512DE0() int {
	s := &noxServer.noxScript
	fnc := int(s.PopU32())
	arg := s.PopU32()
	dt := s.PopU32()
	s.PushU32(s.newScriptTimer(int(dt*s.s.TickRate()), fnc, arg))
	return 0
}

func nox_script_specialTimer_512E10() int {
	s := &noxServer.noxScript
	fnc := int(s.PopU32())
	arg := s.PopU32()
	df := int(s.PopU32())
	s.PushU32(s.newScriptTimer(df, fnc, arg))
	return 0
}

func nox_script_objectGet_513490() int {
	s := &noxServer.noxScript
	str := s.PopString()
	str += s.nameSuff
	cstr := CString(str)
	defer StrFree(cstr)
	obj := asObjectC(C.nox_xxx_getObjectByScrName_4DA4F0(cstr))
	if obj != nil {
		s.PushU32(uint32(obj.script_id))
	} else {
		scriptLog.Printf("noxscript: cannot find object: %q", str)
		s.PushU32(0)
	}
	return 0
}

func nox_script_getObjectX_513530() int {
	s := &noxServer.noxScript
	obj := s.PopObject()
	s.PushF32(obj.Pos().X)
	return 0
}

func nox_script_getObjectY_5135B0() int {
	s := &noxServer.noxScript
	obj := s.PopObject()
	s.PushF32(obj.Pos().Y)
	return 0
}

func nox_script_builtin_513C60() int { return 0 }

func nox_script_fn58_513F10() int {
	s := &noxServer.noxScript
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_fn59_513F20() int {
	s := &noxServer.noxScript
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_fn5A_513F30() int {
	s := &noxServer.noxScript
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_fn5B_513F40() int {
	s := &noxServer.noxScript
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_Fn5C_513F50() int {
	s := &noxServer.noxScript
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_Fn5D_513F60() int {
	s := &noxServer.noxScript
	s.PopU32()
	s.PopU32()
	return 0
}

// TODO: migrate all usage of `nox_server_scriptExecuteFnForEachGroupObj_502670` to use these funcs below.
func scriptExecuteFnForObjectGroup(group *mapGroup, fn func(*Object)) {
	if group == nil {
		return
	}
	groupType := group.GroupType()
	switch groupType {
	case 0:
		for item := group.FirstItem(); item != nil; item = item.Next() {
			ind := item.Ind()
			obj := noxServer.getObjectByInd(ind)
			if obj != nil {
				fn(obj)
			}
		}
	case 3:
		for item := group.FirstItem(); item != nil; item = item.Next() {
			childMapGroup := getMapGroupByInd(item.Ind())
			scriptExecuteFnForObjectGroup(childMapGroup, fn)
		}
	}
}

func scriptExecuteFnForWaypointGroup(group *mapGroup, fn func(*Waypoint)) {
	if group == nil {
		return
	}
	groupType := group.GroupType()
	switch groupType {
	case 1:
		for item := group.FirstItem(); item != nil; item = item.Next() {
			ind := item.Ind()
			wp := noxServer.getWaypointByInd(ind)
			if wp != nil {
				fn(wp)
			}
		}
	case 3:
		for item := group.FirstItem(); item != nil; item = item.Next() {
			childMapGroup := getMapGroupByInd(item.Ind())
			scriptExecuteFnForWaypointGroup(childMapGroup, fn)
		}
	}
}

func scriptExecuteFnForWallGroup(group *mapGroup, fn func(*Wall)) {
	if group == nil {
		return
	}
	groupType := group.GroupType()
	switch groupType {
	case 2:
		for item := group.FirstItem(); item != nil; item = item.Next() {
			wall := noxServer.getWallAtGrid(image.Pt(item.Ind(), item.Ind2()))
			if wall != nil {
				fn(wall)
			}
		}
	case 3:
		for item := group.FirstItem(); item != nil; item = item.Next() {
			childMapGroup := getMapGroupByInd(item.Ind())
			scriptExecuteFnForWallGroup(childMapGroup, fn)
		}
	}
}

func nox_script_CancelTimer_5141F0() int {
	s := &noxServer.noxScript
	act := s.PopU32()
	ok := s.actCancel(act)
	s.PushBool(ok)
	return 0
}

func nox_script_Effect_514210() int {
	s := &noxServer.noxScript
	pos2 := s.PopPointf()
	pos := s.PopPointf()
	name := "MSG_FX_" + strings.ToUpper(s.PopString())
	dpos := image.Point{
		X: s.builtinGetF40(),
		Y: s.builtinGetF44(),
	}
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

func nox_script_Waypoint_514800() int {
	s := &noxServer.noxScript
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

func nox_script_GetWaypointGroup_5148A0() int {
	s := &noxServer.noxScript
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

func nox_script_GetObjectGroup_514940() int {
	s := &noxServer.noxScript
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

func nox_script_GetWallGroup_5149E0() int {
	s := &noxServer.noxScript
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

func nox_script_Pop2_74_514BA0() int {
	s := &noxServer.noxScript
	s.PopU32()
	s.PopU32()
	return 0
}

func nox_script_RemoveChat_514BB0() int {
	s := &noxServer.noxScript
	if u := s.PopObject().AsUnit(); u != nil {
		nox_xxx_netKillChat_528D00(u)
	}
	return 0
}

func nox_script_NoChatAll_514BD0() int {
	C.nox_xxx_destroyEveryChatMB_528D60()
	return 0
}

func nox_script_CastObject2_514F10() int {
	s := &noxServer.noxScript
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
	caster.direction1 = C.ushort(nox_xxx_math_509ED0(targ.Pos().Sub(caster.Pos())))
	s.s.castSpellBy(sp, caster, targ, targ.Pos())
	return 0
}

func nox_script_CastObjectLocation_514FC0() int {
	s := &noxServer.noxScript
	targPos := s.PopPointf()
	caster := s.PopObject().AsUnit()
	sp := spell.ParseID(s.PopString())
	if !sp.Valid() {
		return 0
	}
	if caster == nil {
		return 0
	}
	caster.direction1 = C.ushort(nox_xxx_math_509ED0(targPos.Sub(caster.Pos())))
	s.s.castSpellBy(sp, caster, nil, targPos)
	return 0
}

func nox_script_CastLocationObject_515060() int {
	s := &noxServer.noxScript
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
	nox_xxx_imagCasterUnit_1569664.direction1 = C.ushort(nox_xxx_math_509ED0(targ.Pos().Sub(srcPos)))
	s.s.castSpellBy(sp, nox_xxx_imagCasterUnit_1569664, targ, targ.Pos())
	return 0
}

func nox_script_CastLocation2_515130() int {
	s := &noxServer.noxScript
	targPos := s.PopPointf()
	srcPos := s.PopPointf()
	sp := spell.ParseID(s.PopString())
	if !sp.Valid() {
		return 0
	}
	nox_xxx_imagCasterUnit_1569664.SetPos(srcPos)
	nox_xxx_imagCasterUnit_1569664.direction1 = C.ushort(nox_xxx_math_509ED0(targPos.Sub(srcPos)))
	s.s.castSpellBy(sp, nox_xxx_imagCasterUnit_1569664, nil, targPos)
	return 0
}

func nox_script_UnBlind_515200() int {
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	noxClient.r.FadeOutScreen(25, false, nil)
	return 0
}

func nox_script_Blind_515220() int {
	noxClient.r.FadeInScreen(25, false, fadeDisableGameDraw)
	return 0
}

func nox_script_WideScreen_515240() int {
	s := &noxServer.noxScript
	s.s.CinemaPlayers(s.PopI32() == 1)
	return 0
}

func nox_script_IsAttackedBy_5161C0() int {
	s := &noxServer.noxScript
	obj2 := s.PopObject()
	obj1 := s.PopObject()
	val := obj1 != nil && obj2 != nil && obj1.isEnemyTo(obj2)
	s.PushBool(val)
	return 0
}

func nox_script_ForceAutosave_516400() int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		sub_4DB130("AUTOSAVE")
		sub_4DB170(1, nil, 0)
	}
	return 0
}

func nox_script_Music_516430() int {
	s := &noxServer.noxScript
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

func nox_script_DeathScreen_516680() int {
	*memmap.PtrUint32(0x5D4594, 2386832) = 0
	sub_5165D0()
	return 0
}

func nox_script_Frozen_516920() int {
	s := &noxServer.noxScript
	val := s.PopBool()
	if u := s.PopObject().AsUnit(); u != nil {
		u.Freeze(val)
	}
	return 0
}

func nox_script_NoWallSound_516960() int {
	s := &noxServer.noxScript
	C.nox_xxx_wallSounds_2386840 = C.uint(s.PopU32())
	return 0
}

func nox_script_SetCallback_516970() int {
	s := &noxServer.noxScript
	fnc := C.int(s.PopU32())
	ev := s.PopU32()
	u := s.PopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassMonster) {
		return 0
	}
	ud := u.updateDataMonster()
	switch ev {
	case 3: // Enemy sighted
		ud.script_enemy_sighted_cb = fnc
	case 4: // Looking for enemy
		ud.script_looking_for_enemy_cb = fnc
	case 5: // Death
		ud.script_death_cb = fnc
	case 6: // Change focus
		ud.script_change_focus_cb = fnc
	case 7: // Is hit
		ud.script_is_hit_cb = fnc
	case 8: // Retreat
		ud.script_retreat_cb = fnc
	case 9: // Collision
		ud.script_collision_cb = fnc
	case 10: // Enemy heard
		ud.script_hear_enemy_cb = fnc
	case 11: // End of waypoint
		ud.script_end_of_waypoint_cb = fnc
	case 13: // Lost sight of enemy
		ud.script_lost_enemy_cb = fnc
	}
	return 0
}

func nox_script_ClearMessages_516BC0() int {
	s := &noxServer.noxScript
	if u := s.PopObject().AsUnit(); u != nil {
		nox_xxx_netScriptMessageKill_4D9760(u)
	}
	return 0
}

func nox_script_StopAllFades_516C10() int {
	nox_video_stopAllFades_44E040()
	return 0
}

func nox_script_MusicPushEvent_5164A0() int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43DA80()
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_PUSH_EVENT)
		noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

func nox_script_MusicPopEvent_5164E0() int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43DAD0()
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_POP_EVENT)
		noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

func nox_script_ClearMusic_516520() int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43D9B0(0, 0)
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
		noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

func nox_script_EndGame_516E10() int {
	s := &noxServer.noxScript
	v := int(s.PopI32())
	s.noxScriptEndGame(v)
	return 0
}

func nox_script_StartGame_516C20() int {
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	return 0
}

func nox_script_ChangeScore_516E30() int {
	s := &noxServer.noxScript
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

func nox_script_GetScore_516EA0() int {
	s := &noxServer.noxScript
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

func noxScriptCompare(name string, orig func() int, updated func() int) func() int {
	return func() int {
		s := &noxServer.noxScript
		origStack := append([]uint32{}, s.vm.stack...)
		dryrunRet := updated()
		dryrunStack := append([]uint32{}, s.vm.stack...)
		s.vm.stack = origStack
		ret := orig()

		scriptLog.Printf("%s: test %v:%d vs %v:%d\n", name, dryrunStack, dryrunRet, s.vm.stack, ret)
		if dryrunRet != ret || !sliceEqual(s.vm.stack, dryrunStack) {
			scriptLog.Printf("%s: unexpected execution result: dry run %v:%d, not matching with %v:%d\n", name, dryrunStack, dryrunRet, s.vm.stack, ret)
		}

		return ret
	}
}

func nox_script_getWall_511EB0() int {
	s := &noxServer.noxScript

	y := s.PopI32()
	x := s.PopI32()

	if s.f40 != 0 || s.f44 != 0 {
		x = (int32(s.f40) + common.GridStep*x) / common.GridStep
		y = (int32(s.f44) + common.GridStep*y) / common.GridStep
	}

	if nox_server_getWallAtGrid_410580(C.int(x), C.int(y)) != nil {
		s.PushI32((x << 16) | y)
	} else {
		s.PushI32(0)
	}

	return 0
}

func nox_script_canInteract_513E80() int {
	s := &noxServer.noxScript

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

func nox_script_openSecretWall_511F50() int {
	s := &noxServer.noxScript

	grid := pointUnpack(s.PopI32())
	wall := noxServer.getWallAtGrid(grid)
	if wall != nil {
		wall.Enable(false)
	}
	return 0
}

func nox_script_closeWall_512040() int {
	s := &noxServer.noxScript

	grid := pointUnpack(s.PopI32())
	wall := noxServer.getWallAtGrid(grid)
	if wall != nil {
		wall.Enable(false)
	}
	return 0
}

func nox_script_toggleWall_512130() int {
	s := &noxServer.noxScript

	grid := pointUnpack(s.PopI32())
	wall := noxServer.getWallAtGrid(grid)
	if wall != nil {
		wall.Toggle()
	}
	return 0
}

func nox_script_wallBreak_512290() int {
	s := &noxServer.noxScript

	grid := pointUnpack(s.PopI32())
	wall := noxServer.getWallAtGrid(grid)
	if wall != nil {
		wall.Destroy()
	}
	return 0
}

func nox_script_moverOrMonsterGo_512370() int {
	s := &noxServer.noxScript

	waypointId := int(s.PopI32())
	obj := s.PopObject()
	if obj != nil {
		if !obj.Flags().Has(object.FlagDead) {
			waypoint := noxServer.getWaypointByInd(waypointId)
			if waypoint != nil {
				C.nox_server_scriptMoveTo_5123C0(C.int(uintptr(unsafe.Pointer(obj))), C.int(uintptr(unsafe.Pointer(waypoint))))
			}
		}
	}
	return 0
}

func nox_script_lookAtDirection_512560() int {
	s := &noxServer.noxScript

	direction := s.PopI32()
	monster := s.PopObject()
	if monster != nil {
		if monster.Class().Has(object.ClassMonster) && !monster.Flags().Has(object.FlagDead) {
			monster.AsUnit().LookAtDir(int(direction))
		}
	}
	return 0
}

func nox_script_objectOn_512670() int {
	s := &noxServer.noxScript

	obj := s.PopObject()
	if obj != nil {
		obj.Enable(true)
	}
	return 0
}

func nox_script_waypointOn_5126D0() int {
	s := &noxServer.noxScript

	waypoint := noxServer.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		*(*uint32)(unsafe.Add(unsafe.Pointer(waypoint), 120*4)) |= 1
	}
	return 0
}

func nox_script_objectOff_512730() int {
	s := &noxServer.noxScript

	obj := s.PopObject()
	if obj != nil {
		obj.Enable(false)
	}
	return 0
}

func nox_script_waypointOff_512790() int {
	s := &noxServer.noxScript

	waypoint := noxServer.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		*(*uint32)(unsafe.Add(unsafe.Pointer(waypoint), 120*4)) &= 0xFFFFFFFE
	}
	return 0
}

func nox_script_toggleObject_5127F0() int {
	s := &noxServer.noxScript

	obj := s.PopObject()
	if obj != nil {
		obj.Toggle()
	}
	return 0
}

func nox_script_toggleWaypoint_512850() int {
	s := &noxServer.noxScript

	waypoint := noxServer.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		*(*uint32)(unsafe.Add(unsafe.Pointer(waypoint), 120*4)) ^= 1
	}
	return 0
}

func nox_script_Hunt_515780() int {
	s := &noxServer.noxScript

	v1 := s.PopObject()
	if v1 != nil {
		v1.AsUnit().Hunt()
	}
	return 0
}

func nox_script_unlockDoor_512C20() int {
	s := &noxServer.noxScript

	obj := s.PopObject()
	if obj != nil && obj.Class().Has(object.ClassDoor) {
		(*(*uint8)(unsafe.Add(obj.updateDataPtr(), 1))) = 0
		nox_xxx_aud_501960(sound.SoundUnlock, obj.AsUnit(), 0, 0)
	}
	return 0
}

func nox_script_lockDoor_512C60() int {
	s := &noxServer.noxScript

	obj := s.PopObject()
	if obj != nil && obj.Class().Has(object.ClassDoor) {
		(*(*uint8)(unsafe.Add(obj.updateDataPtr(), 1))) = 5
		nox_xxx_aud_501960(sound.SoundLock, obj.AsUnit(), 0, 0)
	}
	return 0
}

func nox_script_isOn_512CA0() int {
	s := &noxServer.noxScript

	v1 := s.PopObject()
	if v1 != nil && v1.Flags().Has(object.FlagEnabled) {
		s.PushI32(1)
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_wpIsEnabled_512CE0() int {
	s := &noxServer.noxScript

	waypoint := noxServer.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil && (*(*uint32)(unsafe.Add(unsafe.Pointer(waypoint), 120*4)))&1 != 0 {
		s.PushI32(1)
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_doorIsLocked_512D20() int {
	s := &noxServer.noxScript

	obj := s.PopObject()
	if obj != nil && obj.Class().Has(object.ClassDoor) && (*(*uint8)(unsafe.Add(obj.updateDataPtr(), 1))) != 0 {
		s.PushI32(1)
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_JournalEntry_5154E0() int {
	s := &noxServer.noxScript

	v0 := s.PopI32()
	v1 := s.PopString()
	v2 := s.PopI32()
	if v2 != 0 {
		v3 := s.scriptToObject(int(v2))
		if v3 != nil {
			C.nox_xxx_comJournalEntryAdd_427500(C.int(uintptr(unsafe.Pointer(v3.CObj()))), CString(v1), C.short(v0))
			if (v0 & 0xB) != 0 {
				nox_xxx_aud_501960(sound.SoundJournalEntryAdd, v3.AsUnit(), 0, 0)
			}
		}
	} else {
		C.nox_xxx_comAddEntryAll_427550(CString(v1), C.short(v0))
	}
	return 0
}

func nox_script_intToString_512EA0() int {
	s := &noxServer.noxScript

	v0 := s.PopI32()
	str := strconv.FormatInt(int64(v0), 10)
	s.PushString(str)
	return 0
}

func nox_script_floatToString_512ED0() int {
	s := &noxServer.noxScript

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
			owner := a20.findOwnerChainPlayer()
			obj.callDamage(owner, a20, dmg, unknown)
		}
	}
}

// Cause damage from src to dest
func nox_script_damage_512F80() int {
	s := &noxServer.noxScript

	param1 := s.PopI32()
	param0 := s.PopI32()
	src := s.PopObject()
	dest := s.PopObject()
	if dest != nil {
		create_sub_512FE0(src, int(param0), int(param1))(dest)
	}
	return 0
}

func nox_script_followNearestWaypoint_512910() int {
	s := &noxServer.noxScript

	obj := s.PopObject()
	if obj != nil {
		obj.AsUnit().Wander()
	}
	return 0
}

func nox_script_gotoHome_512A00() int {
	s := &noxServer.noxScript

	obj := s.PopObject()
	if obj != nil {
		obj.AsUnit().Return()
	}
	return 0
}

func nox_script_audioEven_512AC0() int {
	s := &noxServer.noxScript

	waypoint := noxServer.getWaypointByInd(int(s.PopI32()))
	soundName := s.PopString()
	if waypoint != nil {
		pos := waypoint.PosC()
		soundId := C.int(sound.ByName(soundName))
		C.nox_xxx_audCreate_501A30(soundId, pos, 0, 0)
	}
	return 0
}

func nox_script_sayChat_512B90() int {
	s := &noxServer.noxScript

	messageId := s.PopString()
	obj := s.PopObject()
	if obj != nil {
		v, _ := s.s.Strings().GetVariantInFile(strman.ID(messageId), "CScrFunc.c")
		C.nox_xxx_netSendChat_528AC0(obj.CObj(), internWStr(v.Str), 0)
		if noxflags.HasGame(noxflags.GameModeCoop) {
			C.nox_xxx_playDialogFile_44D900(C.int(uintptr(unsafe.Pointer(internCStr(v.Str2)))), 100)
		}
	}
	return 0
}

func nox_script_Wander_513070() int {
	s := &noxServer.noxScript

	v4 := s.PopF32()
	v0 := s.PopI32()
	obj := s.PopObject()
	if obj != nil {
		v5, free5 := alloc.Make([]C.int{}, 3)
		defer free5()
		v5[0] = C.int(int64(v4))
		v5[1] = C.int(v0)
		v5[2] = 0
		C.sub_5130E0(C.int(uintptr(unsafe.Pointer(obj.CObj()))), (*C.uint32_t)(unsafe.Pointer(&v5[0])))
		s.PushI32(int32(v5[2]))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_awardSpell_5131C0() int {
	s := &noxServer.noxScript

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

func nox_script_enchant_5132E0() int {
	s := &noxServer.noxScript

	v5 := s.PopF32()
	v8 := s.PopString()
	v3 := s.PopObject()
	id, ok := enchantByName[v8]
	if ok {
		if v3 != nil {
			dur := int(float32(s.s.TickRate()) * v5)
			v3.ApplyEnchant(id, dur, 5)
		}
	}
	return 0
}

func nox_script_getHost_513460() int {
	s := &noxServer.noxScript

	// Note: original C code got the player from `noxServer.getPlayerByInd(MaxPlayers - 1)`
	v0 := HostPlayerUnit()
	if v0 != nil {
		s.PushI32(int32(v0.ScriptID()))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_getWaypointX_513570() int {
	s := &noxServer.noxScript

	waypoint := noxServer.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		s.PushF32(waypoint.Pos().X)
	} else {
		s.PushI32(0) // f32 0 == i32 0
	}
	return 0
}

func nox_script_getWaypointY_5135F0() int {
	s := &noxServer.noxScript

	waypoint := noxServer.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		s.PushF32(waypoint.Pos().Y)
	} else {
		s.PushI32(0) // f32 0 == i32 0
	}
	return 0
}

func nox_script_getUnitLook_513670() int {
	s := &noxServer.noxScript

	v1 := s.PopObject()
	if v1 != nil {
		s.PushI32(int32(v1.Dir1()))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_unitHeight_513630() int {
	s := &noxServer.noxScript

	v1 := s.PopObject()
	if v1 != nil {
		s.PushU32(v1.RawZ())
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_moveObject_5136A0() int {
	s := &noxServer.noxScript

	dy := s.PopF32()
	dx := s.PopF32()
	obj := s.PopObject()
	if obj != nil {
		pos := types.Pointf{X: float32(s.builtinGetF40()) + dx, Y: float32(s.builtinGetF44()) + dy}
		obj.SetPos(pos)
	}
	return 0
}

func nox_script_moveWaypoint_513700() int {
	s := &noxServer.noxScript

	dy := s.PopF32()
	dx := s.PopF32()
	waypoint := noxServer.getWaypointByInd(int(s.PopI32()))
	if waypoint != nil {
		pos := types.Pointf{X: float32(s.builtinGetF40()) + dx, Y: float32(s.builtinGetF44()) + dy}
		waypoint.SetPos(pos)
	}
	return 0
}

func nox_script_openWallGroup_512010() int {
	s := &noxServer.noxScript

	v0 := s.PopI32()
	mapGroup := getMapGroupByInd(int(v0))

	scriptExecuteFnForWallGroup(mapGroup, func(wall *Wall) {
		wall.Enable(false)
	})
	return 0
}

func nox_script_waypointGroupOn_5126F0() int {
	s := &noxServer.noxScript

	v0 := s.PopI32()
	mapGroup := getMapGroupByInd(int(v0))
	scriptExecuteFnForWaypointGroup(mapGroup, func(wp *Waypoint) {
		wp.Enable(true)
	})
	return 0
}

func nox_script_toggleObjectGroup_512810() int {
	s := &noxServer.noxScript

	v0 := s.PopI32()
	mapGroup := getMapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(mapGroup, func(obj *Object) {
		obj.Toggle()
	})
	return 0
}

func nox_script_create_512F10() int {
	s := &noxServer.noxScript

	waypointInd := s.PopI32()
	wp := noxServer.getWaypointByInd(int(waypointInd))
	objectTypeId := s.PopString()

	if wp != nil {
		obj := noxServer.newObjectByTypeID(objectTypeId)
		if obj == nil {
			s.PushI32(0)
			return 0
		}
		noxServer.createObjectAt(obj, nil, wp.Pos())
		s.PushI32(int32(obj.ScriptID()))
	} else {
		scriptLog.Printf("noxscript: cannot find waypoint from idx: %v", waypointInd)
		s.PushI32(0)
	}
	return 0
}

func nox_script_raise_513750() int {
	s := &noxServer.noxScript

	zValue := s.PopF32()
	obj := s.PopObject()
	if obj != nil {
		obj.SetZ(zValue)
	}
	return 0
}

func nox_script_faceAngle_513780() int {
	s := &noxServer.noxScript

	dir := s.PopI32()
	obj := s.PopObject()
	if obj != nil {
		v3 := uint16(nox_xxx_math_roundDir(dir))
		obj.setAllDirs(v3)
	}
	return 0
}

func nox_script_pushObject_5137D0() int {
	s := &noxServer.noxScript

	dy := s.PopF32()
	dx := s.PopF32()
	obj := s.PopObject()
	if obj != nil {
		force := obj.Force()
		force.X += dx
		force.Y += dy
		obj.setForce(force)
	}
	return 0
}

func nox_script_pushObjectTo_513820() int {
	s := &noxServer.noxScript

	yPos := s.PopF32()
	xPos := s.PopF32()
	force := s.PopF32()
	obj := s.PopObject()
	if obj != nil {
		xDir := obj.Pos().X - xPos + float32(s.builtinGetF40())
		yDir := obj.Pos().Y - yPos + float32(s.builtinGetF44())
		dirLength := float32(math.Hypot(float64(xDir), float64(yDir)))
		obj.ApplyForce(types.Pointf{X: force * xDir / dirLength, Y: force * yDir / dirLength})
	}
	return 0
}

func nox_script_getFirstInvItem_5138B0() int {
	s := &noxServer.noxScript

	v2 := s.PopObject()
	if v2 != nil {
		v3 := v2.FirstItem()
		if v3 != nil {
			s.PushI32(int32(v3.ScriptID()))
			return 0
		}
	}
	s.PushI32(0)
	return 0
}

func nox_script_getNextInvItem_5138E0() int {
	s := &noxServer.noxScript

	v2 := s.PopObject()
	if v2 != nil {
		v3 := v2.NextItem()
		if v3 != nil {
			s.PushI32(int32(v3.ScriptID()))
			return 0
		}
	}
	s.PushI32(0)
	return 0
}

func zombieSetStayDead(obj *Object) {
	if obj != nil {
		if obj.Class().Has(object.ClassMonster) {
			obj.AsUnit().updateDataMonster().field_360 |= 0x100000
		}
	}
}

func nox_script_ZombieStayDown_516C70() int {
	s := &noxServer.noxScript

	v1 := s.PopObject()
	if v1 != nil {
		zombieSetStayDead(v1)
	}
	return 0
}

func nox_script_ZombieStayDownGroup_516CB0() int {
	s := &noxServer.noxScript

	v0 := s.PopI32()
	mapGroup := getMapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(mapGroup, zombieSetStayDead)

	return 0
}

func nox_script_hasItem_513910() int {
	s := &noxServer.noxScript

	item := s.PopObject()
	holder := s.PopObject()
	if holder != nil && item != nil && holder.HasItem(item) {
		s.PushI32(1)
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_getInvHolder_513960() int {
	s := &noxServer.noxScript

	obj := s.PopObject()
	if obj != nil {
		s.PushI32(int32(obj.InventoryHolder().ScriptID()))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_pickup_5139A0() int {
	s := &noxServer.noxScript

	objGold := noxServer.getObjectTypeID("Gold")
	objQuestGoldPile := noxServer.getObjectTypeID("QuestGoldPile")
	objQuestGoldChest := noxServer.getObjectTypeID("QuestGoldChest")

	item := s.PopObject()
	picker := s.PopObject()
	if picker == nil || item == nil {
		s.PushI32(0)
		return 0
	}
	if noxflags.HasGame(noxflags.GameModeCoop) && picker.Class().Has(object.ClassPlayer) &&
		*memmap.PtrUint32(0x5D4594, 2386844) != noxServer.Frame() {
		*memmap.PtrUint32(0x5D4594, 2386844) = noxServer.Frame()
		C.dword_5d4594_2386848 = 0
		C.dword_5d4594_2386852 = 0
	}

	if noxflags.HasGame(noxflags.GameModeCoop) && picker.Class().Has(object.ClassPlayer) {
		v5 := picker.objTypeInd()
		if v5 != objGold && v5 != objQuestGoldPile && v5 != objQuestGoldChest {
			C.nox_xxx_playerCanCarryItem_513B00(picker.CObj(), item.CObj())
		}
	}

	v6 := int32(C.nox_xxx_inventoryServPlace_4F36F0(picker.CObj(), item.CObj(), 1, 1))
	if v6 == 1 && picker.Class().Has(object.ClassPlayer) && noxflags.HasGame(noxflags.GameModeCoop) && item.objTypeInd() != objGold {
		C.dword_5d4594_2386848 += 1
		s.PushI32(1)
		return 0
	}
	s.PushI32(v6)
	return 0
}

func nox_script_Idle_515800() int {
	s := &noxServer.noxScript

	unit := s.PopObject()
	if unit != nil {
		unit.AsUnit().Idle()
	}
	return 0
}

func nox_script_GroupIdle_515850() int {
	s := &noxServer.noxScript

	v0 := s.PopI32()
	mapGroup := getMapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(mapGroup, func(obj *Object) {
		obj.AsUnit().Idle()
	})
	return 0
}

func nox_script_Follow_515880() int {
	s := &noxServer.noxScript

	v3 := s.PopObject()
	v2 := s.PopObject()
	if v2 != nil && v3 != nil {
		v2.AsUnit().Follow(v3)
	}
	return 0
}

func nox_script_FollowGroup_515910() int {
	s := &noxServer.noxScript

	v2 := s.PopObject()
	v1 := s.PopI32()
	if v2 != nil {
		mapGroup := getMapGroupByInd(int(v1))
		scriptExecuteFnForObjectGroup(mapGroup, func(obj *Object) {
			obj.AsUnit().Follow(v2)
		})
	}
	return 0
}

func nox_script_RaiseZombie_516CE0() int {
	s := &noxServer.noxScript

	v1 := s.PopObject()
	if v1 != nil {
		C.sub_516D00(v1.CObj())
	}
	return 0
}

func nox_script_RaiseZombieGroup_516D40() int {
	s := &noxServer.noxScript

	v0 := s.PopI32()
	mapGroup := getMapGroupByInd(int(v0))
	scriptExecuteFnForObjectGroup(mapGroup, func(obj *Object) {
		C.sub_516D00(obj.CObj())
	})
	return 0
}

func nox_script_drop_513C10() int {
	s := &noxServer.noxScript

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

func nox_script_TestBuffs_513C70() int {
	s := &noxServer.noxScript

	enchantName := s.PopString()
	obj := s.PopObject()
	enchantId, ok := enchantByName[enchantName]
	if obj != nil && ok {
		hasEnchant := obj.HasEnchant(enchantId)
		s.PushI32(int32(bool2int(hasEnchant)))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_HasClass_516210() int {
	s := &noxServer.noxScript

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

func nox_script_cancelBuff_513D00() int {
	s := &noxServer.noxScript

	enchantName := s.PopString()
	obj := s.PopObject()
	enchantId, ok := enchantByName[enchantName]
	if ok && obj != nil {
		obj.DisableEnchant(enchantId)
	}
	return 0
}

func nox_script_getCurrentHP_513D70() int {
	s := &noxServer.noxScript

	v1 := s.PopObject()
	if v1 != nil {
		cur, _ := v1.Health()
		s.PushI32(int32(cur))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_getMaxHP_513DB0() int {
	s := &noxServer.noxScript

	v1 := s.PopObject()
	if v1 != nil {
		_, max := v1.Health()
		s.PushI32(int32(max))
	} else {
		s.PushI32(0)
	}
	return 0
}

func nox_script_restoreHP_513DF0() int {
	s := &noxServer.noxScript

	delta := s.PopI32()
	obj := s.PopObject()
	if obj != nil && delta > 0 {
		C.nox_xxx_unitAdjustHP_4EE460(obj.CObj(), C.int(delta))
	}
	return 0
}

func nox_script_getDistance_513E20() int {
	s := &noxServer.noxScript

	y2 := s.PopF32()
	x2 := s.PopF32()
	y1 := s.PopF32()
	x1 := s.PopF32()

	v5 := float32(math.Hypot(float64(y1-y2), float64(x1-x2)))
	s.PushF32(v5)
	return 0
}

func nox_script_FaceObject_514050() int {
	s := &noxServer.noxScript

	tgt := s.PopObject()
	obj := s.PopObject()

	if obj != nil && tgt != nil {
		vec := tgt.Pos()
		dir := nox_xxx_math_509ED0(vec.Sub(obj.Pos()))
		obj.setAllDirs(uint16(dir))
	}
	return 0
}

func nox_script_Walk_5140B0() int {
	s := &noxServer.noxScript

	dy := s.PopF32()
	dx := s.PopF32()
	obj := s.PopObject()
	if obj != nil {
		posy := float32(s.builtinGetF44()) + dy
		posx := float32(s.builtinGetF40()) + dx
		obj.AsUnit().WalkTo(types.Pointf{X: posx, Y: posy})
	}
	return 0
}

func nox_script_GroupWalk_514170() int {
	s := &noxServer.noxScript

	dy := s.PopF32()
	dx := s.PopF32()
	groupInd := s.PopI32()

	posy := float32(s.builtinGetF44()) + dy
	posx := float32(s.builtinGetF40()) + dx
	dstPoint := types.Pointf{X: posx, Y: posy}
	mapGroup := getMapGroupByInd(int(groupInd))
	if mapGroup != nil {
		// Unlike scriptExecuteFnForObjectGroup, it does not nest into child groups.
		for item := mapGroup.FirstItem(); item != nil; item = item.Next() {
			obj := noxServer.getObjectByInd(item.Ind())
			if obj != nil {
				obj.AsUnit().WalkTo(dstPoint)
			}
		}
	}
	return 0
}
