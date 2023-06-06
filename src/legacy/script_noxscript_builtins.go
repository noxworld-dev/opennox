package legacy

import (
	"github.com/noxworld-dev/noxscript/ns/asm"

	"github.com/noxworld-dev/opennox/v1/server/noxscript"
)

var (
	Nox_script_shouldReadMoreXxx     func(fi asm.Builtin) bool
	Nox_script_shouldReadEvenMoreXxx func(fi asm.Builtin) bool
)

// nox_script_shouldReadMoreXxx
func nox_script_shouldReadMoreXxx(fi int32) bool {
	return Nox_script_shouldReadMoreXxx(asm.Builtin(fi))
}

// nox_script_shouldReadEvenMoreXxx
func nox_script_shouldReadEvenMoreXxx(fi int32) bool {
	return Nox_script_shouldReadEvenMoreXxx(asm.Builtin(fi))
}

func wrapScriptC(fnc func() int32) noxscript.Builtin {
	return func(_ noxscript.VM) int {
		return int(fnc())
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
	nox_script_StartupScreen_516600_A()
}

var noxScriptBuiltins = [asm.BuiltinGetScore + 1]noxscript.Builtin{
	asm.BuiltinUnused5e:            wrapScriptC(nox_script_Fn5E_513F70),
	asm.BuiltinGetCharacterData:    wrapScriptC(nox_script_GetHostInfo_513FA0),
	asm.BuiltinSetQuestStatus:      wrapScriptC(nox_script_SetQuestInt_514BE0),
	asm.BuiltinSetQuestStatusFloat: wrapScriptC(nox_script_SetQuestFloat_514C10),
	asm.BuiltinGetQuestStatus:      wrapScriptC(nox_script_GetQuestInt_514C40),
	asm.BuiltinGetQuestStatusFloat: wrapScriptC(nox_script_GetQuestFloat_514C60),
	asm.BuiltinResetQuestStatus:    wrapScriptC(nox_script_ResetQuestStatus_514C90),
	asm.BuiltinHitLocation:         wrapScriptC(nox_script_HitLocation_5159E0),
	asm.BuiltinGroupHitLocation:    wrapScriptC(nox_script_HitLocationGroup_515AE0),
	asm.BuiltinHitFarLocation:      wrapScriptC(nox_script_HitFarLocation_515B30),
	asm.BuiltinGroupHitFarLocation: wrapScriptC(nox_script_HitFarLocationGroup_515BF0),
	asm.BuiltinSetRoamFlag:         wrapScriptC(nox_script_SetRoamFlag_515C40),
	asm.BuiltinGroupSetRoamFlag:    wrapScriptC(nox_script_SetRoamFlagGroup_515CB0),
	asm.BuiltinJournalDelete:       wrapScriptC(nox_script_JournalDelete_515550),
	asm.BuiltinJournalEdit:         wrapScriptC(nox_script_JournalEdit_5155A0),
	asm.BuiltinGiveXp:              wrapScriptC(nox_script_GiveExp_516190),
	asm.BuiltinHasSubclass:         wrapScriptC(nox_script_HasSubclass_5162D0),
	asm.BuiltinIsTalking:           wrapScriptC(nox_script_IsTalking_5166A0),
	asm.BuiltinMakeFriendly:        wrapScriptC(nox_script_MakeFriendly_516720),
	asm.BuiltinMakeEnemy:           wrapScriptC(nox_script_MakeEnemy_516760),
	asm.BuiltinBecomePet:           wrapScriptC(nox_script_BecomePet_5167D0),
	asm.BuiltinBecomeEnemy:         wrapScriptC(nox_script_BecomeEnemy_516810),
	asm.BuiltinUnknownb8:           wrapScriptC(nox_script_builtin_516790),
	asm.BuiltinUnknownb9:           wrapScriptC(nox_script_builtin_516850),
	asm.BuiltinSetHalberd:          wrapScriptC(nox_script_OblivionGive_516890),
	asm.BuiltinIsTrading:           wrapScriptC(nox_script_PlayerIsTrading_5166E0),
	asm.BuiltinSetShopkeeperText:   wrapScriptC(nox_script_SetShopkeeperGreet_516BE0),
	asm.BuiltinIsSummoned:          wrapScriptC(nox_script_IsSummoned_516C30),
}
