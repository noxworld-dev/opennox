package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_ai_debug_print                     func(str string)
	Sub_545E60                             func(a1c *server.Object) int
	Sub_50D1C0                             func()
	Nox_xxx_gameSetAudioFadeoutMb_501AC0   func(v int)
	Nox_xxx_monsterPopAction_50A160        func(a1 *server.Object) int
	Nox_xxx_monsterPushAction_50A260_impl  func(u *server.Object, act ai.ActionType, skip int) unsafe.Pointer
	Nox_xxx_unitUpdateMonster_50A5C0       func(a1 *server.Object)
	Nox_xxx_monsterClearActionStack_50A3A0 func(a1 *server.Object)
)

type Nox_player_polygon_check_data struct {
	Field_0 [35]uint32
}

func init() {
	for typ, a := range map[ai.ActionType]struct {
		Start, Update, End, Cancel func(*server.Object)
	}{
		ai.ACTION_ESCORT:            {Update: nox_xxx_mobActionEscort_546430, End: sub_546410, Cancel: sub_546420},
		ai.ACTION_GUARD:             {Update: nox_xxx_mobActionGuard_546010},
		ai.ACTION_HUNT:              {Update: nox_xxx_mobActionHunt_5449D0},
		ai.ACTION_RETREAT:           {Update: nox_xxx_mobActionRetreat_545440},
		ai.ACTION_MOVE_TO:           {Update: nox_xxx_mobActionMoveTo_5443F0},
		ai.ACTION_FAR_MOVE_TO:       {Update: nox_xxx_mobActionMoveToFar_5445C0},
		ai.ACTION_DODGE:             {Update: nox_xxx_mobActionDodge_544640},
		ai.ACTION_ROAM:              {Start: sub_545790, Update: nox_xxx_mobActionRoam_5457E0, Cancel: sub_5457C0},
		ai.ACTION_PICKUP_OBJECT:     {Update: nox_xxx_mobActionPickupObject_544B90},
		ai.ACTION_RETREAT_TO_MASTER: {Start: sub_5456B0, Update: sub_5456D0, End: sub_5456C0},
		ai.ACTION_FIGHT:             {Start: nox_xxx_mobActionFightStart_531E20, Update: nox_xxx_mobActionFight_531EC0, End: sub_531E90},
		ai.ACTION_MELEE_ATTACK:      {Start: nox_xxx_mobActionMelee1_532130, Update: nox_xxx_mobActionMeleeAtt_532440, Cancel: nox_ai_action_pop_532100},
		ai.ACTION_MISSILE_ATTACK:    {Start: sub_532540, Update: nox_xxx_mobActionMissileAtt_532610, Cancel: nox_ai_action_pop_532100},
		ai.ACTION_BLOCK_ATTACK:      {Update: nox_xxx_monsterShieldBlockStart_532070, Cancel: nox_ai_action_pop_532100},
		ai.ACTION_BLOCK_FINISH:      {Update: nox_xxx_monsterShieldBlockStop_5320E0, Cancel: nox_ai_action_pop_532100},
		ai.ACTION_WEAPON_BLOCK:      {Update: sub_532110, Cancel: nox_ai_action_pop_532100},
		ai.ACTION_FLEE:              {Start: sub_544740, Update: nox_xxx_mobActionFlee_544760, End: sub_544750},
		ai.ACTION_FACE_LOCATION:     {Update: sub_545210, Cancel: nox_ai_action_pop_532100},
		ai.ACTION_FACE_OBJECT:       {Update: sub_545300, Cancel: nox_ai_action_pop_532100},
		ai.ACTION_FACE_ANGLE:        {Update: sub_545340, Cancel: nox_ai_action_pop_532100},
		ai.ACTION_SET_ANGLE:         {Update: sub_5453E0, Cancel: nox_ai_action_pop_532100},
		ai.ACTION_RANDOM_WALK:       {Update: nox_xxx_mobActionRandomWalk_545020},
		ai.ACTION_DYING:             {Start: nox_xxx_mobGenericDeath_544C40, Update: sub_544D60, End: nox_xxx_zombieBurnDeleteCheck_544CA0},
		ai.ACTION_DEAD:              {Start: nox_xxx_mobActionDead1_544D80, Update: nox_xxx_mobActionDead2_544EC0},
		ai.ACTION_GET_UP:            {Update: nox_xxx_mobActionGetUp_534A90},
		ai.ACTION_CONFUSED:          {Update: nox_xxx_mobActionConfuse_545140},
		ai.ACTION_MOVE_TO_HOME:      {Start: nox_xxx_mobActionReturnToHome_544920, Update: sub_544950, End: sub_544930, Cancel: sub_544940},
	} {
		server.RegisterAIAction(cgoAIAction{typ: typ, start: a.Start, update: a.Update, end: a.End, cancel: a.Cancel})
	}
}

type cgoAIAction struct {
	typ                        ai.ActionType
	start, update, end, cancel func(*server.Object)
}

func (a cgoAIAction) Type() ai.ActionType {
	return a.typ
}

func (a cgoAIAction) Start(u *server.Object) {
	if a.start != nil {
		a.start(u)
	}
}

func (a cgoAIAction) Update(u *server.Object) {
	if a.update != nil {
		a.update(u)
	}
}

func (a cgoAIAction) End(u *server.Object) {
	if a.end != nil {
		a.end(u)
	}
}

func (a cgoAIAction) Cancel(u *server.Object) {
	if a.cancel != nil {
		a.cancel(u)
	}
}

// nox_ai_debug_print
func nox_ai_debug_print(str *byte) { Nox_ai_debug_print(GoString(str)) }

// sub_545E60
func sub_545E60(a1c *server.Object) int32 { return int32(Sub_545E60(asObjectS(a1c))) }

// sub_50D1C0
func sub_50D1C0() { Sub_50D1C0() }

// nox_xxx_gameSetAudioFadeoutMb_501AC0
func nox_xxx_gameSetAudioFadeoutMb_501AC0(v int32) { Nox_xxx_gameSetAudioFadeoutMb_501AC0(int(v)) }

func nox_xxx_monsterPopAction_50A160(a1 *server.Object) {
	Nox_xxx_monsterPopAction_50A160(asObjectS(a1))
}

func nox_xxx_monsterPushAction_50A260_impl(u *server.Object, act ai.ActionType) unsafe.Pointer {
	return Nox_xxx_monsterPushAction_50A260_impl(asObjectS(u), act, 1)
}

// nox_xxx_unitUpdateMonster_50A5C0
func nox_xxx_unitUpdateMonster_50A5C0(a1 *server.Object) {
	Nox_xxx_unitUpdateMonster_50A5C0(asObjectS(a1))
}

// nox_xxx_monsterClearActionStack_50A3A0
func nox_xxx_monsterClearActionStack_50A3A0(a1 *server.Object) {
	Nox_xxx_monsterClearActionStack_50A3A0(asObjectS(a1))
}
func Nox_xxx_mobSearchEdible_544A00(a1 *server.Object, a2 float32) int {
	return int(nox_xxx_mobSearchEdible_544A00(asObjectC(a1), a2))
}
func Nox_xxx_weaponGetStaminaByType_4F7E80(a1 int) int {
	return int(nox_xxx_weaponGetStaminaByType_4F7E80(int32(a1)))
}
func Nox_xxx_mobGetMoveAttemptTime_534810(a1 *server.Object) int {
	return int(nox_xxx_mobGetMoveAttemptTime_534810(asObjectC(a1)))
}
func Nox_xxx_unitIsDangerous_547120(a1 *server.Object, a2 *server.Object) {
	nox_xxx_unitIsDangerous_547120(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_checkIsKillable_528190(a1 *server.Object) int {
	return int(nox_xxx_checkIsKillable_528190(asObjectC(a1)))
}
func Nox_xxx_polygonIsPlayerInPolygon_4217B0(a1 unsafe.Pointer, a2 int) *Nox_player_polygon_check_data {
	return (*Nox_player_polygon_check_data)(unsafe.Pointer(nox_xxx_polygonIsPlayerInPolygon_4217B0((*Point32)(a1), int32(a2))))
}
func Nox_xxx_mobAction_50A910(a1 *server.Object) {
	nox_xxx_mobAction_50A910(asObjectC(a1))
}
func Nox_xxx_monsterGetSoundSet_424300(a1 *server.Object) unsafe.Pointer {
	return nox_xxx_monsterGetSoundSet_424300(asObjectC(a1))
}
func Nox_xxx_monsterPlayHurtSound_532800(a1 *server.Object) {
	nox_xxx_monsterPlayHurtSound_532800(asObjectC(a1))
}
func Nox_xxx_mobAction_5469B0(a1 *server.Object) {
	nox_xxx_mobAction_5469B0(asObjectC(a1))
}
func Nox_xxx_unitUpdateSightMB_5281F0(a1 *server.Object) {
	nox_xxx_unitUpdateSightMB_5281F0(asObjectC(a1))
}
func Nox_xxx_monsterMainAIFn_547210(a1 *server.Object) {
	nox_xxx_monsterMainAIFn_547210(asObjectC(a1))
}
func Nox_xxx_updateNPCAnimData_50A850(a1 *server.Object) {
	nox_xxx_updateNPCAnimData_50A850(asObjectC(a1))
}
func Nox_xxx_monsterPolygonEnter_421FF0(a1 *server.Object) {
	nox_xxx_monsterPolygonEnter_421FF0(asObjectC(a1))
}
func Nox_xxx_monsterMimicCheckMorph_534950(a1 *server.Object) {
	nox_xxx_monsterMimicCheckMorph_534950(asObjectC(a1))
}
func Sub_5466F0(a1 *server.Object) int {
	return int(sub_5466F0(asObjectC(a1)))
}
func Nox_xxx_mobHealSomeone_5411A0(a1 *server.Object) {
	nox_xxx_mobHealSomeone_5411A0(asObjectC(a1))
}
func Nox_xxx_mobActionCast_5413B0(a1 *server.Object, a2 int) {
	nox_xxx_mobActionCast_5413B0(asObjectC(a1), int32(a2))
}
func Nox_xxx_monsterMarkUpdate_4E8020(a1 *server.Object) {
	nox_xxx_monsterMarkUpdate_4E8020(asObjectC(a1))
}
