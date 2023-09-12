package legacy

/*
#include "defs.h"
#include "GAME1_1.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "server__script__script.h"
extern unsigned int dword_5d4594_2489460;
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Sub_545E60                           func(a1c *server.Object) int
	Nox_xxx_gameSetAudioFadeoutMb_501AC0 func(v int)
	Nox_xxx_unitUpdateMonster_50A5C0     func(a1 *server.Object)
)

type Nox_player_polygon_check_data struct {
	Field_0 [35]uint32
}

func init() {
	for typ, a := range map[ai.ActionType]struct {
		Start, Update, End, Cancel unsafe.Pointer
	}{
		ai.ACTION_ESCORT:            {Update: C.nox_xxx_mobActionEscort_546430, End: C.sub_546410, Cancel: C.sub_546420},
		ai.ACTION_GUARD:             {Update: C.nox_xxx_mobActionGuard_546010},
		ai.ACTION_HUNT:              {Update: C.nox_xxx_mobActionHunt_5449D0},
		ai.ACTION_RETREAT:           {Update: C.nox_xxx_mobActionRetreat_545440},
		ai.ACTION_MOVE_TO:           {Update: C.nox_xxx_mobActionMoveTo_5443F0},
		ai.ACTION_FAR_MOVE_TO:       {Update: C.nox_xxx_mobActionMoveToFar_5445C0},
		ai.ACTION_DODGE:             {Update: C.nox_xxx_mobActionDodge_544640},
		ai.ACTION_ROAM:              {Start: C.sub_545790, Update: C.nox_xxx_mobActionRoam_5457E0, Cancel: C.sub_5457C0},
		ai.ACTION_PICKUP_OBJECT:     {Update: C.nox_xxx_mobActionPickupObject_544B90},
		ai.ACTION_RETREAT_TO_MASTER: {Start: C.sub_5456B0, Update: C.sub_5456D0, End: C.sub_5456C0},
		ai.ACTION_FIGHT:             {Start: C.nox_xxx_mobActionFightStart_531E20, Update: C.nox_xxx_mobActionFight_531EC0, End: C.sub_531E90},
		ai.ACTION_MELEE_ATTACK:      {Start: C.nox_xxx_mobActionMelee1_532130, Update: C.nox_xxx_mobActionMeleeAtt_532440, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_MISSILE_ATTACK:    {Start: C.sub_532540, Update: C.nox_xxx_mobActionMissileAtt_532610, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_BLOCK_ATTACK:      {Update: C.nox_xxx_monsterShieldBlockStart_532070, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_BLOCK_FINISH:      {Update: C.nox_xxx_monsterShieldBlockStop_5320E0, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_WEAPON_BLOCK:      {Update: C.sub_532110, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_FLEE:              {Start: C.sub_544740, Update: C.nox_xxx_mobActionFlee_544760, End: C.sub_544750},
		ai.ACTION_FACE_LOCATION:     {Update: C.sub_545210, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_FACE_OBJECT:       {Update: C.sub_545300, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_FACE_ANGLE:        {Update: C.sub_545340, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_SET_ANGLE:         {Update: C.sub_5453E0, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_RANDOM_WALK:       {Update: C.nox_xxx_mobActionRandomWalk_545020},
		ai.ACTION_DYING:             {Start: C.nox_xxx_mobGenericDeath_544C40, Update: C.sub_544D60, End: C.nox_xxx_zombieBurnDeleteCheck_544CA0},
		ai.ACTION_DEAD:              {Start: C.nox_xxx_mobActionDead1_544D80, Update: C.nox_xxx_mobActionDead2_544EC0},
		ai.ACTION_GET_UP:            {Update: C.nox_xxx_mobActionGetUp_534A90},
		ai.ACTION_CONFUSED:          {Update: C.nox_xxx_mobActionConfuse_545140},
		ai.ACTION_MOVE_TO_HOME:      {Start: C.nox_xxx_mobActionReturnToHome_544920, Update: C.sub_544950, End: C.sub_544930, Cancel: C.sub_544940},
	} {
		server.RegisterAIAction(cgoAIAction{typ: typ, start: a.Start, update: a.Update, end: a.End, cancel: a.Cancel})
	}
}

type cgoAIAction struct {
	typ                        ai.ActionType
	start, update, end, cancel unsafe.Pointer
}

func (a cgoAIAction) Type() ai.ActionType {
	return a.typ
}

func (a cgoAIAction) Start(u *server.Object) {
	if a.start != nil {
		ccall.CallVoidPtr(a.start, u.CObj())
	}
}

func (a cgoAIAction) Update(u *server.Object) {
	if a.update != nil {
		ccall.CallVoidPtr(a.update, u.CObj())
	}
}

func (a cgoAIAction) End(u *server.Object) {
	if a.end != nil {
		ccall.CallVoidPtr(a.end, u.CObj())
	}
}

func (a cgoAIAction) Cancel(u *server.Object) {
	if a.cancel != nil {
		ccall.CallVoidPtr(a.cancel, u.CObj())
	}
}

//export nox_ai_debug_print
func nox_ai_debug_print(str *C.char) { ai.Log.Printf("%s", GoString(str)) }

//export sub_545E60
func sub_545E60(a1c *nox_object_t) int { return Sub_545E60(asObjectS(a1c)) }

//export nox_xxx_gameSetAudioFadeoutMb_501AC0
func nox_xxx_gameSetAudioFadeoutMb_501AC0(v int) { Nox_xxx_gameSetAudioFadeoutMb_501AC0(v) }

//export nox_xxx_monsterPopAction_50A160
func nox_xxx_monsterPopAction_50A160(a1 *nox_object_t) int {
	return asObjectS(a1).MonsterPopAction()
}

//export nox_xxx_monsterPushAction_50A260_impl
func nox_xxx_monsterPushAction_50A260_impl(u *nox_object_t, act int, file *C.char, line int) unsafe.Pointer {
	return asObjectS(u).MonsterPushActionImpl(ai.ActionType(act), GoString(file), line).C()
}

//export nox_xxx_unitUpdateMonster_50A5C0
func nox_xxx_unitUpdateMonster_50A5C0(a1 *nox_object_t) {
	Nox_xxx_unitUpdateMonster_50A5C0(asObjectS(a1))
}

//export nox_xxx_monsterClearActionStack_50A3A0
func nox_xxx_monsterClearActionStack_50A3A0(a1 *nox_object_t) {
	asObjectS(a1).ClearActionStack()
}

//export nox_xxx_checkMobAction_50A0D0
func nox_xxx_checkMobAction_50A0D0(a1 *nox_object_t, a2 int) int {
	return bool2int(asObjectS(a1).UpdateDataMonster().HasAction(ai.ActionType(a2)))
}
func Nox_xxx_mobSearchEdible_544A00(a1 *server.Object, a2 float32) int {
	return int(C.nox_xxx_mobSearchEdible_544A00(asObjectC(a1), C.float(a2)))
}
func Nox_xxx_weaponGetStaminaByType_4F7E80(a1 int) int {
	return int(C.nox_xxx_weaponGetStaminaByType_4F7E80(C.int(a1)))
}
func Nox_xxx_mobGetMoveAttemptTime_534810(a1 *server.Object) int {
	return int(C.nox_xxx_mobGetMoveAttemptTime_534810(asObjectC(a1)))
}
func Nox_xxx_unitIsDangerous_547120(a1 *server.Object, a2 *server.Object) {
	C.nox_xxx_unitIsDangerous_547120(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_checkIsKillable_528190(a1 *server.Object) int {
	return int(C.nox_xxx_checkIsKillable_528190(asObjectC(a1)))
}
func Nox_xxx_polygonIsPlayerInPolygon_4217B0(a1 unsafe.Pointer, a2 int) *Nox_player_polygon_check_data {
	return (*Nox_player_polygon_check_data)(unsafe.Pointer(C.nox_xxx_polygonIsPlayerInPolygon_4217B0((*C.int2)(a1), C.int(a2))))
}
func Nox_xxx_mobAction_50A910(a1 *server.Object) {
	C.nox_xxx_mobAction_50A910(asObjectC(a1))
}
func Nox_xxx_monsterGetSoundSet_424300(a1 *server.Object) unsafe.Pointer {
	return unsafe.Pointer(C.nox_xxx_monsterGetSoundSet_424300(asObjectC(a1)))
}
func Nox_xxx_monsterPlayHurtSound_532800(a1 *server.Object) {
	C.nox_xxx_monsterPlayHurtSound_532800(asObjectC(a1))
}
func Nox_xxx_mobAction_5469B0(a1 *server.Object) {
	C.nox_xxx_mobAction_5469B0(asObjectC(a1))
}
func Nox_xxx_unitUpdateSightMB_5281F0(a1 *server.Object) {
	C.nox_xxx_unitUpdateSightMB_5281F0(asObjectC(a1))
}
func Nox_xxx_monsterMainAIFn_547210(a1 *server.Object) {
	C.nox_xxx_monsterMainAIFn_547210(asObjectC(a1))
}
func Nox_xxx_updateNPCAnimData_50A850(a1 *server.Object) {
	C.nox_xxx_updateNPCAnimData_50A850(asObjectC(a1))
}
func Nox_xxx_monsterPolygonEnter_421FF0(a1 *server.Object) {
	C.nox_xxx_monsterPolygonEnter_421FF0(asObjectC(a1))
}
func Nox_xxx_monsterMimicCheckMorph_534950(a1 *server.Object) {
	C.nox_xxx_monsterMimicCheckMorph_534950(asObjectC(a1))
}
func Sub_5466F0(a1 *server.Object) int {
	return int(C.sub_5466F0(asObjectC(a1)))
}
func Nox_xxx_mobHealSomeone_5411A0(a1 *server.Object) {
	C.nox_xxx_mobHealSomeone_5411A0(asObjectC(a1))
}
func Nox_xxx_mobActionCast_5413B0(a1 *server.Object, a2 int) {
	C.nox_xxx_mobActionCast_5413B0(asObjectC(a1), C.int(a2))
}
func Nox_xxx_monsterMarkUpdate_4E8020(a1 *server.Object) {
	C.nox_xxx_monsterMarkUpdate_4E8020(asObjectC(a1))
}
