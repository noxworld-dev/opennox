package legacy

/*
#include "defs.h"
int nox_script_Fn5E_513F70();
int nox_script_GetHostInfo_513FA0();
int nox_script_SetQuestInt_514BE0();
int nox_script_SetQuestFloat_514C10();
int nox_script_GetQuestInt_514C40();
int nox_script_GetQuestFloat_514C60();
int nox_script_ResetQuestStatus_514C90();
int nox_script_CancelDialog_514DF0();
int nox_script_DialogPortrait_514E30();
int nox_script_TellStory_514E90();
int nox_script_StartDialog_514ED0();
int nox_script_Guard_515600();
int nox_script_GuardGroup_515700();
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
int nox_script_DialogResult_5163C0();
int nox_script_GiveExp_516190();
int nox_script_HasSubclass_5162D0();
int nox_script_IsTalking_5166A0();
int nox_script_MakeFriendly_516720();
int nox_script_MakeEnemy_516760();
int nox_script_BecomePet_5167D0();
int nox_script_BecomeEnemy_516810();
int nox_script_builtin_516790();
int nox_script_builtin_516850();
int nox_script_OblivionGive_516890();
int nox_script_TrapSpells_516B40();
int nox_script_PlayerIsTrading_5166E0();
int nox_script_SetShopkeeperGreet_516BE0();
int nox_script_IsSummoned_516C30();
void nox_script_StartupScreen_516600_A();
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/noxscript/ns/asm"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server/noxscript"
)

var (
	Nox_script_shouldReadMoreXxx     func(fi asm.Builtin) bool
	Nox_script_shouldReadEvenMoreXxx func(fi asm.Builtin) bool
)

//export nox_script_shouldReadMoreXxx
func nox_script_shouldReadMoreXxx(fi int) C.bool {
	return C.bool(Nox_script_shouldReadMoreXxx(asm.Builtin(fi)))
}

//export nox_script_shouldReadEvenMoreXxx
func nox_script_shouldReadEvenMoreXxx(fi int) C.bool {
	return C.bool(Nox_script_shouldReadEvenMoreXxx(asm.Builtin(fi)))
}

func wrapScriptC(fnc unsafe.Pointer) noxscript.Builtin {
	return func(_ noxscript.VM) int {
		return ccall.CallIntVoid(fnc)
	}
}

func CallScriptBuiltin(fi asm.Builtin) (int, bool) {
	if fi < 0 || int(fi) >= len(noxScriptBuiltins) {
		return 0, false
	}
	fnc := noxScriptBuiltins[fi]
	if fnc == nil {
		return 0, false
	}
	res := fnc(GetServer().NoxScriptC())
	return res, true
}

func Nox_script_StartupScreen_516600_A() {
	C.nox_script_StartupScreen_516600_A()
}

var noxScriptBuiltins = [asm.BuiltinGetScore + 1]noxscript.Builtin{
	asm.BuiltinUnused5e:            wrapScriptC(C.nox_script_Fn5E_513F70),
	asm.BuiltinGetCharacterData:    wrapScriptC(C.nox_script_GetHostInfo_513FA0),
	asm.BuiltinSetQuestStatus:      wrapScriptC(C.nox_script_SetQuestInt_514BE0),
	asm.BuiltinSetQuestStatusFloat: wrapScriptC(C.nox_script_SetQuestFloat_514C10),
	asm.BuiltinGetQuestStatus:      wrapScriptC(C.nox_script_GetQuestInt_514C40),
	asm.BuiltinGetQuestStatusFloat: wrapScriptC(C.nox_script_GetQuestFloat_514C60),
	asm.BuiltinResetQuestStatus:    wrapScriptC(C.nox_script_ResetQuestStatus_514C90),
	asm.BuiltinCancelDialog:        wrapScriptC(C.nox_script_CancelDialog_514DF0),
	asm.BuiltinStoryPic:            wrapScriptC(C.nox_script_DialogPortrait_514E30),
	asm.BuiltinTellStory:           wrapScriptC(C.nox_script_TellStory_514E90),
	asm.BuiltinStartDialog:         wrapScriptC(C.nox_script_StartDialog_514ED0),
	asm.BuiltinCreatureGuard:       wrapScriptC(C.nox_script_Guard_515600),
	asm.BuiltinCreatureGroupGuard:  wrapScriptC(C.nox_script_GuardGroup_515700),
	asm.BuiltinHitLocation:         wrapScriptC(C.nox_script_HitLocation_5159E0),
	asm.BuiltinGroupHitLocation:    wrapScriptC(C.nox_script_HitLocationGroup_515AE0),
	asm.BuiltinHitFarLocation:      wrapScriptC(C.nox_script_HitFarLocation_515B30),
	asm.BuiltinGroupHitFarLocation: wrapScriptC(C.nox_script_HitFarLocationGroup_515BF0),
	asm.BuiltinSetRoamFlag:         wrapScriptC(C.nox_script_SetRoamFlag_515C40),
	asm.BuiltinGroupSetRoamFlag:    wrapScriptC(C.nox_script_SetRoamFlagGroup_515CB0),
	asm.BuiltinAttack:              wrapScriptC(C.nox_script_Attack_515CF0),
	asm.BuiltinGroupAttack:         wrapScriptC(C.nox_script_AttackGroup_515DB0),
	asm.BuiltinJournalDelete:       wrapScriptC(C.nox_script_JournalDelete_515550),
	asm.BuiltinJournalEdit:         wrapScriptC(C.nox_script_JournalEdit_5155A0),
	asm.BuiltinRunAway:             wrapScriptC(C.nox_script_RunAway_515F10),
	asm.BuiltinGroupRunAway:        wrapScriptC(C.nox_script_RunAwayGroup_516000),
	asm.BuiltinPauseObject:         wrapScriptC(C.nox_script_PauseObject_516060),
	asm.BuiltinGroupPauseObject:    wrapScriptC(C.nox_script_PauseObjectGroup_5160F0),
	asm.BuiltinGetAnswer:           wrapScriptC(C.nox_script_DialogResult_5163C0),
	asm.BuiltinGiveXp:              wrapScriptC(C.nox_script_GiveExp_516190),
	asm.BuiltinHasSubclass:         wrapScriptC(C.nox_script_HasSubclass_5162D0),
	asm.BuiltinIsTalking:           wrapScriptC(C.nox_script_IsTalking_5166A0),
	asm.BuiltinMakeFriendly:        wrapScriptC(C.nox_script_MakeFriendly_516720),
	asm.BuiltinMakeEnemy:           wrapScriptC(C.nox_script_MakeEnemy_516760),
	asm.BuiltinBecomePet:           wrapScriptC(C.nox_script_BecomePet_5167D0),
	asm.BuiltinBecomeEnemy:         wrapScriptC(C.nox_script_BecomeEnemy_516810),
	asm.BuiltinUnknownb8:           wrapScriptC(C.nox_script_builtin_516790),
	asm.BuiltinUnknownb9:           wrapScriptC(C.nox_script_builtin_516850),
	asm.BuiltinSetHalberd:          wrapScriptC(C.nox_script_OblivionGive_516890),
	asm.BuiltinTrapSpells:          wrapScriptC(C.nox_script_TrapSpells_516B40),
	asm.BuiltinIsTrading:           wrapScriptC(C.nox_script_PlayerIsTrading_5166E0),
	asm.BuiltinSetShopkeeperText:   wrapScriptC(C.nox_script_SetShopkeeperGreet_516BE0),
	asm.BuiltinIsSummoned:          wrapScriptC(C.nox_script_IsSummoned_516C30),
}
