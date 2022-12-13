package opennox

/*
#include "defs.h"
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
*/
import "C"
import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	asm "github.com/noxworld-dev/opennox-lib/script/noxscript/noxasm"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns"

	"github.com/noxworld-dev/opennox/v1/server/noxscript"
)

func wrapScriptC(fnc unsafe.Pointer) noxscript.Builtin {
	return func(_ noxscript.VM) int {
		return cgoCallIntVoidFunc(fnc)
	}
}

//export nox_script_callBuiltin_508B70
func nox_script_callBuiltin_508B70(i, fi C.int) C.int {
	return C.int(noxServer.noxScript.callBuiltin(int(i), asm.Builtin(fi)))
}

func (s *noxScript) callBuiltin(i int, fi asm.Builtin) int {
	if fi < 0 || fi > asm.BuiltinGetScore {
		if s.panicCompilerCheck(fi) {
			return 0
		}
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
	if res, ok := noxscript.CallBuiltin(s, fi); ok {
		return res
	}
	if res, ok := s.panicScriptCall(fi); ok {
		return res
	}
	if fi < 0 || int(fi) >= len(noxScriptBuiltins) {
		scriptLog.Printf("noxscript: invalid builtin index: %d (%x)", fi, fi)
		return 0
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

var noxScriptBuiltins = [asm.BuiltinGetScore + 1]noxscript.Builtin{
	asm.BuiltinSecondTimer:          nsSecondTimer,
	asm.BuiltinFrameTimer:           nsFrameTimer,
	asm.BuiltinSecondTimerWithArg:   nsSecondTimerArg,
	asm.BuiltinFrameTimerWithArg:    nsFrameTimerArg,
	asm.BuiltinUnused5e:             wrapScriptC(C.nox_script_Fn5E_513F70),
	asm.BuiltinGetCharacterData:     wrapScriptC(C.nox_script_GetHostInfo_513FA0),
	asm.BuiltinCancelTimer:          nsCancelTimer,
	asm.BuiltinSetQuestStatus:       wrapScriptC(C.nox_script_SetQuestInt_514BE0),
	asm.BuiltinSetQuestStatusFloat:  wrapScriptC(C.nox_script_SetQuestFloat_514C10),
	asm.BuiltinGetQuestStatus:       wrapScriptC(C.nox_script_GetQuestInt_514C40),
	asm.BuiltinGetQuestStatusFloat:  wrapScriptC(C.nox_script_GetQuestFloat_514C60),
	asm.BuiltinResetQuestStatus:     wrapScriptC(C.nox_script_ResetQuestStatus_514C90),
	asm.BuiltinIsTrigger:            wrapScriptC(C.nox_script_IsTrigger_514CB0),
	asm.BuiltinIsCaller:             wrapScriptC(C.nox_script_IsCaller_514CF0),
	asm.BuiltinSetDialog:            wrapScriptC(C.nox_script_SetDialog_514D90),
	asm.BuiltinCancelDialog:         wrapScriptC(C.nox_script_CancelDialog_514DF0),
	asm.BuiltinStoryPic:             wrapScriptC(C.nox_script_DialogPortrait_514E30),
	asm.BuiltinTellStory:            wrapScriptC(C.nox_script_TellStory_514E90),
	asm.BuiltinStartDialog:          wrapScriptC(C.nox_script_StartDialog_514ED0),
	asm.BuiltinCreatureGuard:        wrapScriptC(C.nox_script_Guard_515600),
	asm.BuiltinCreatureGroupGuard:   wrapScriptC(C.nox_script_GuardGroup_515700),
	asm.BuiltinCreatureGroupHunt:    wrapScriptC(C.nox_script_HuntGroup_5157D0),
	asm.BuiltinAggressionLevel:      wrapScriptC(C.nox_script_AgressionLevel_515950),
	asm.BuiltinGroupAggressionLevel: wrapScriptC(C.nox_script_AggressionLevelGroup_5159B0),
	asm.BuiltinHitLocation:          wrapScriptC(C.nox_script_HitLocation_5159E0),
	asm.BuiltinGroupHitLocation:     wrapScriptC(C.nox_script_HitLocationGroup_515AE0),
	asm.BuiltinHitFarLocation:       wrapScriptC(C.nox_script_HitFarLocation_515B30),
	asm.BuiltinGroupHitFarLocation:  wrapScriptC(C.nox_script_HitFarLocationGroup_515BF0),
	asm.BuiltinSetRoamFlag:          wrapScriptC(C.nox_script_SetRoamFlag_515C40),
	asm.BuiltinGroupSetRoamFlag:     wrapScriptC(C.nox_script_SetRoamFlagGroup_515CB0),
	asm.BuiltinAttack:               wrapScriptC(C.nox_script_Attack_515CF0),
	asm.BuiltinGroupAttack:          wrapScriptC(C.nox_script_AttackGroup_515DB0),
	asm.BuiltinJournalDelete:        wrapScriptC(C.nox_script_JournalDelete_515550),
	asm.BuiltinJournalEdit:          wrapScriptC(C.nox_script_JournalEdit_5155A0),
	asm.BuiltinRetreatLevel:         wrapScriptC(C.nox_script_RetreatLevel_515DF0),
	asm.BuiltinGroupRetreatLevel:    wrapScriptC(C.nox_script_RetreatLevelGroup_515E50),
	asm.BuiltinResumeLevel:          wrapScriptC(C.nox_script_SetResumeLevel_515E80),
	asm.BuiltinGroupResumeLevel:     wrapScriptC(C.nox_script_SetResumeLevelGroup_515EE0),
	asm.BuiltinRunAway:              wrapScriptC(C.nox_script_RunAway_515F10),
	asm.BuiltinGroupRunAway:         wrapScriptC(C.nox_script_RunAwayGroup_516000),
	asm.BuiltinPauseObject:          wrapScriptC(C.nox_script_PauseObject_516060),
	asm.BuiltinGroupPauseObject:     wrapScriptC(C.nox_script_PauseObjectGroup_5160F0),
	asm.BuiltinGetGold:              wrapScriptC(C.nox_script_GetGold_516120),
	asm.BuiltinChangeGold:           wrapScriptC(C.nox_script_ChangeGold_516160),
	asm.BuiltinGetAnswer:            wrapScriptC(C.nox_script_DialogResult_5163C0),
	asm.BuiltinGiveXp:               wrapScriptC(C.nox_script_GiveExp_516190),
	asm.BuiltinHasSubclass:          wrapScriptC(C.nox_script_HasSubclass_5162D0),
	asm.BuiltinStartupScreen:        wrapScriptC(C.nox_script_StartupScreen_516600),
	asm.BuiltinIsTalking:            wrapScriptC(C.nox_script_IsTalking_5166A0),
	asm.BuiltinGetTrigger:           wrapScriptC(C.nox_script_GetTrigger_514D30),
	asm.BuiltinGetCaller:            wrapScriptC(C.nox_script_GetCaller_514D60),
	asm.BuiltinMakeFriendly:         wrapScriptC(C.nox_script_MakeFriendly_516720),
	asm.BuiltinMakeEnemy:            wrapScriptC(C.nox_script_MakeEnemy_516760),
	asm.BuiltinBecomePet:            wrapScriptC(C.nox_script_BecomePet_5167D0),
	asm.BuiltinBecomeEnemy:          wrapScriptC(C.nox_script_BecomeEnemy_516810),
	asm.BuiltinUnknownb8:            wrapScriptC(C.nox_script_builtin_516790),
	asm.BuiltinUnknownb9:            wrapScriptC(C.nox_script_builtin_516850),
	asm.BuiltinSetHalberd:           wrapScriptC(C.nox_script_OblivionGive_516890),
	asm.BuiltinSetCallback:          nsSetCallback,
	asm.BuiltinDeleteObjectTimer:    wrapScriptC(C.nox_script_DeleteObjectTimer_516A50),
	asm.BuiltinTrapSpells:           wrapScriptC(C.nox_script_TrapSpells_516B40),
	asm.BuiltinIsTrading:            wrapScriptC(C.nox_script_PlayerIsTrading_5166E0),
	asm.BuiltinSetShopkeeperText:    wrapScriptC(C.nox_script_SetShopkeeperGreet_516BE0),
	asm.BuiltinIsSummoned:           wrapScriptC(C.nox_script_IsSummoned_516C30),
	asm.BuiltinIsGameBall:           wrapScriptC(C.nox_script_ObjIsGameball_516D70),
	asm.BuiltinIsCrown:              wrapScriptC(C.nox_script_ObjIsCrown_516DC0),
}

func nsSecondTimer(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int(s.PopU32())
	dt := s.PopU32()
	s.PushU32(s.s.NewTimer(int(dt*s.s.TickRate()), fnc, 0))
	return 0
}

func nsFrameTimer(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int(s.PopU32())
	df := int(s.PopU32())
	s.PushU32(s.s.NewTimer(df, fnc, 0))
	return 0
}

func nsSecondTimerArg(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int(s.PopU32())
	arg := s.PopU32()
	dt := s.PopU32()
	s.PushU32(s.s.NewTimer(int(dt*s.s.TickRate()), fnc, arg))
	return 0
}

func nsFrameTimerArg(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int(s.PopU32())
	arg := s.PopU32()
	df := int(s.PopU32())
	s.PushU32(s.s.NewTimer(df, fnc, arg))
	return 0
}

// TODO: migrate all usage of `nox_server_scriptExecuteFnForEachGroupObj_502670` to use these funcs below.

func (g *mapGroup) eachObjectNS(s *Server, fnc func(obj ns.Obj) bool) {
	if g == nil {
		return
	}
	switch g.GroupType() {
	case mapGroupObjects:
		for it := g.First(); it != nil; it = it.Next() {
			if obj := s.GetObjectByInd(it.Data1()); obj != nil {
				if !fnc(nsObj{obj}) {
					return
				}
			}
		}
	}
}

func (g *mapGroup) eachObjectRecursiveNS(s *Server, fnc func(obj ns.Obj) bool) bool {
	if g == nil {
		return true // just skip this group
	}
	switch g.GroupType() {
	case mapGroupObjects:
		for it := g.First(); it != nil; it = it.Next() {
			if obj := s.GetObjectByInd(it.Data1()); obj != nil {
				if !fnc(nsObj{obj}) {
					return false
				}
			}
		}
	case mapGroupGroups:
		for it := g.First(); it != nil; it = it.Next() {
			if !s.mapGroupByInd(it.Data1()).eachObjectRecursiveNS(s, fnc) {
				return false
			}
		}
	}
	return true
}

func (g *mapGroup) eachWaypointRecursive(s *Server, fnc func(wp ns.WaypointObj) bool) bool {
	if g == nil {
		return true
	}
	switch g.GroupType() {
	case mapGroupWaypoints:
		for it := g.First(); it != nil; it = it.Next() {
			if wp := s.getWaypointByInd(it.Data1()); wp != nil {
				if !fnc(wp) {
					return false
				}
			}
		}
	case mapGroupGroups:
		for it := g.First(); it != nil; it = it.Next() {
			if !s.mapGroupByInd(it.Data1()).eachWaypointRecursive(s, fnc) {
				return false
			}
		}
	}
	return true
}

func (g *mapGroup) eachWallRecursive(s *Server, fnc func(w ns.WallObj) bool) bool {
	if g == nil {
		return true
	}
	switch g.GroupType() {
	case mapGroupWalls:
		for it := g.First(); it != nil; it = it.Next() {
			if w := s.getWallAtGrid(image.Pt(it.Data1(), it.Data2())); w != nil {
				if !fnc(w) {
					return false
				}
			}
		}
	case mapGroupGroups:
		for it := g.First(); it != nil; it = it.Next() {
			if !s.mapGroupByInd(it.Data1()).eachWallRecursive(s, fnc) {
				return false
			}
		}
	}
	return true
}

func nsCancelTimer(vm noxscript.VM) int {
	s := vm.(*noxScript)
	act := s.PopU32()
	ok := s.s.Activators.Cancel(act)
	s.PushBool(ok)
	return 0
}

func nsSetCallback(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int32(s.PopU32())
	ev := ns.ObjectEvent(s.PopU32())
	u := s.PopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassMonster) {
		return 0
	}
	ud := u.UpdateDataMonster()
	switch ev {
	case ns.EventEnemySighted: // Enemy sighted
		ud.ScriptEnemySightedCB = fnc
	case ns.EventLookingForEnemy: // Looking for enemy
		ud.ScriptLookingForEnemyCB = fnc
	case ns.EventDeath: // Death
		ud.ScriptDeathCB = fnc
	case ns.EventChangeFocus: // Change focus
		ud.ScriptChangeFocusCB = fnc
	case ns.EventIsHit: // Is hit
		ud.ScriptIsHitCB = fnc
	case ns.EventRetreat: // Retreat
		ud.ScriptRetreatCB = fnc
	case ns.EventCollision: // Collision
		ud.ScriptCollisionCB = fnc
	case ns.EventEnemyHeard: // Enemy heard
		ud.ScriptHearEnemyCB = fnc
	case ns.EventEndOfWaypoint: // End of waypoint
		ud.ScriptEndOfWaypointCB = fnc
	case ns.EventLostEnemy: // Lost sight of enemy
		ud.ScriptLostEnemyCB = fnc
	}
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
