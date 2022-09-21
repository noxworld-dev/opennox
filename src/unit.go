package opennox

/*
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_3.h"
#include "GAME5_2.h"
#include "server__script__builtin.h"
void nox_server_gotoHome(nox_object_t* obj);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
)

//export nox_xxx_unitIsUnitTT_4E7C80
func nox_xxx_unitIsUnitTT_4E7C80(a1 *nox_object_t, a2 C.int) C.int {
	return C.int(asUnitC(a1).countSubOfType(int(a2)))
}

func asUnit(p unsafe.Pointer) *Unit {
	if p == nil {
		return nil
	}
	return (*Unit)(p)
}

func asUnitC(p *C.nox_object_t) *Unit {
	if p == nil {
		return nil
	}
	return (*Unit)(unsafe.Pointer(p))
}

type Unit struct {
	Object
}

func (u *Unit) AsObject() *Object {
	if u == nil {
		return nil
	}
	return asObjectC(u.CObj())
}

func (u *Unit) String() string {
	return u.stringAs("Unit")
}

func (u *Unit) move(cp *C.float2) {
	C.nox_xxx_unitMove_4E7010(u.CObj(), cp)
}

func (u *Unit) SetPos(p types.Pointf) {
	cp, free := alloc.New(C.float2{})
	defer free()
	cp.field_0 = C.float(p.X)
	cp.field_4 = C.float(p.Y)
	u.move(cp)
}

func (u *Unit) Push(vec types.Pointf, force float32) {
	p := u.Pos().Sub(vec)
	l := float32(p.Len())
	p.X = force * p.X / l
	p.Y = force * p.Y / l
	u.PushTo(p)
}

func (u *Unit) PushTo(p types.Pointf) {
	u.force_x += C.float(p.X)
	u.force_y += C.float(p.Y)
}

func (u *Unit) Destroy() {
	panic("implement me")
	u.Delete()
}

func (u *Unit) CanSee(obj script.Object) bool {
	panic("implement me")
}

func (u *Unit) updateDataPlayer() *PlayerUpdateData {
	if !u.Class().Has(object.ClassPlayer) {
		panic(u.Class().String())
	}
	// TODO: verify this conversion by checking ObjectType
	p := (*C.nox_object_Player_data_t)(u.updateDataPtr())
	return (*PlayerUpdateData)(unsafe.Pointer(p))
}

func (u *Unit) updateDataMonster() *MonsterUpdateData {
	if !u.Class().Has(object.ClassMonster) {
		panic(u.Class().String())
	}
	// TODO: verify this conversion by checking ObjectType
	p := (*C.nox_object_Monster_data_t)(u.updateDataPtr())
	return (*MonsterUpdateData)(unsafe.Pointer(p))
}

func (u *Unit) ControllingPlayer() *Player {
	if u == nil {
		return nil
	}
	ud := u.updateDataPlayer()
	return asPlayer(ud.player)
}

func (u *Unit) Health() (cur, max int) {
	if u == nil {
		return
	}
	p := u.ptrXxx()
	if p == nil {
		return
	}
	cur = int(*(*uint16)(unsafe.Add(p, 0)))
	max = int(*(*uint16)(unsafe.Add(p, 4)))
	return
}

func (u *Unit) SetHealth(v int) {
	if u == nil {
		return
	}
	if noxflags.HasGame(noxflags.GameSuddenDeath) {
		return
	}
	if v < 0 {
		v = 0
	}
	if _, max := u.Health(); v > max {
		v = max
	}
	// TODO: if 0, trigger death
	C.nox_xxx_unitSetHP_4E4560(u.CObj(), C.ushort(v))
	if u.Class().Has(object.ClassMonster) {
		C.nox_xxx_mobInformOwnerHP_4EE4C0(u.CObj())
	}
}

func (u *Unit) SetMaxHealth(v int) {
	if u == nil {
		return
	}
	if noxflags.HasGame(noxflags.GameSuddenDeath) {
		return
	}
	if v < 0 {
		v = 0
	}
	p := u.ptrXxx()
	if p == nil {
		return
	}
	// TODO: verify it works in MP
	// TODO: if it's the player, we need to adjust GUI health bars
	*(*uint16)(unsafe.Add(p, 4)) = uint16(v)
	u.SetHealth(v)
}

func (u *Unit) Mana() (cur, max int) {
	if u == nil {
		return
	}
	// TODO: check if offsets are the same for monsters
	p := u.updateDataPlayer()
	if p == nil {
		return
	}
	cur = int(p.mana_cur)
	max = int(p.mana_max)
	return
}

func (u *Unit) SetMana(v int) {
	if u == nil {
		return
	}
	if v < 0 {
		v = 0
	}
	p := u.updateDataPlayer()
	if p == nil {
		return
	}
	if _, max := u.Mana(); v > max {
		v = max
	}
	cur := int(p.mana_cur)
	p.mana_prev = C.ushort(cur)
	p.mana_cur = C.ushort(v)
	pt := asPlayer(p.player)
	C.nox_xxx_protectMana_56F9E0(C.int(pt.prot_unit_mana_cur), C.short(v-cur))
}

func (u *Unit) SetMaxMana(v int) {
	if u == nil {
		return
	}
	if v < 0 {
		v = 0
	}
	p := u.updateDataPlayer()
	if p == nil {
		return
	}
	p.mana_max = C.ushort(v)
	u.SetMana(v)
}

func (u *Unit) MoveTo(p types.Pointf) {
	// TODO: originally, this method required Waypoint as an argument
	//       but now we actually have WalkTo and friends which accept both position or a waypoint (in LUA)
	//       so we will call WalkTo here for now, but that Waypoint requirement was probably done for a reason
	u.WalkTo(p)
}

func (u *Unit) WalkTo(p types.Pointf) {
	C.nox_xxx_monsterWalkTo_514110(u.CObj(), C.float(p.X), C.float(p.Y))
}

func (u *Unit) look(v int16) {
	*(*int16)(u.field(124)) = v
	*(*int16)(u.field(126)) = v
}

func (u *Unit) LookAt(p types.Pointf) {
	p = p.Sub(u.Pos())
	v := nox_xxx_math_509ED0(p)
	u.look(int16(v))
}

func (u *Unit) LookAtDir(dir int) {
	C.nox_xxx_monsterLookAt_5125A0(u.CObj(), C.int(dir))
}

func (u *Unit) LookAngle(ang int) {
	v := nox_xxx_math_roundDir(int32(ang))
	u.look(int16(v))
}

func (u *Unit) Freeze(freeze bool) {
	if freeze {
		C.nox_xxx_unitFreeze_4E79C0(u.CObj(), 1)
	} else {
		C.nox_xxx_unitUnFreeze_4E7A60(u.CObj(), 1)
	}
}

func (u *Unit) Wander() {
	C.nox_xxx_scriptMonsterRoam_512930(u.CObj())
}

func (u *Unit) Return() {
	C.nox_server_gotoHome(u.CObj())
}

func (u *Unit) Idle() {
	C.nox_xxx_unitIdle_515820(u.CObj())
}

func (u *Unit) Follow(obj script.Positioner) {
	if v, ok := obj.(script.ObjectWrapper); ok {
		obj = v.GetObject()
	}
	cobj := obj.(noxObject)
	C.nox_xxx_unitSetFollow_5158C0(u.CObj(), cobj.CObj())
}

func (u *Unit) Flee(obj script.Positioner, dur script.Duration) {
	panic("implement me")
}

func (u *Unit) Aggression() float32 {
	panic("implement me")
}

func (u *Unit) SetAggression(v float32) {
	panic("implement me")
}

func (u *Unit) RetreatLevel() float32 {
	panic("implement me")
}

func (u *Unit) SetRetreatLevel(v float32) {
	panic("implement me")
}

func (u *Unit) RegroupLevel() float32 {
	panic("implement me")
}

func (u *Unit) SetRegroupLevel(v float32) {
	panic("implement me")
}

func (u *Unit) Attack(obj script.Positioner) {
	panic("implement me")
}

func (u *Unit) HitMelee(p types.Pointf) {
	panic("implement me")
}

func (u *Unit) HitRanged(p types.Pointf) {
	panic("implement me")
}

func (u *Unit) Guard() {
	panic("implement me")
}

func (u *Unit) Hunt() {
	C.nox_xxx_unitHunt_5157A0(u.CObj())
}

func (u *Unit) Say(text string, dur script.Duration) {
	panic("implement me")
}

func (u *Unit) Mute() {
	panic("implement me")
}

func (u *Unit) AddGold(v int) {
	if v < 0 {
		C.nox_xxx_playerSubGold_4FA5D0(C.int(uintptr(unsafe.Pointer(u.CObj()))), C.uint(v))
	} else {
		C.nox_xxx_playerAddGold_4FA590(C.int(uintptr(unsafe.Pointer(u.CObj()))), C.int(v))
	}
}

func (u *Unit) Cast(sp spell.ID, lvl int, targ script.Positioner) bool {
	if !sp.Valid() || lvl <= 0 {
		return false
	}
	var s *Server = u.getServer()
	sa, freeArg := alloc.New(spellAcceptArg{})
	defer freeArg()
	if targ == nil {
		targ = u
	}
	if o, ok := targ.(noxObject); ok {
		sa.Obj = o.AsObject().CObj()
	}
	sa.Pos = targ.Pos()
	return s.castSpell(sp, lvl, u, sa)
}

func (u *Unit) clearActionStack() { // aka nox_xxx_monsterClearActionStack_50A3A0
	if u.Class().Has(object.ClassMonster) {
		for C.sub_5341F0(u.CObj()) == 0 {
			nox_xxx_monsterPopAction_50A160(u)
		}
	}
}

func (u *Unit) monsterPushAction(act ai.ActionType, args ...any) *aiStack { // aka nox_xxx_monsterPushAction_50A260
	st := (*aiStack)(unsafe.Pointer(C.nox_xxx_monsterPushAction_50A260_impl(u.CObj(), C.int(act), internCStr("go"), 0)))
	if len(args) != 0 {
		st.SetArgs(args...)
	}
	return st
}

func (u *Unit) monsterActionIsScheduled(act ai.ActionType) bool { // nox_xxx_monsterIsActionScheduled_50A090
	stack := u.updateDataMonster().getAIStack()
	for _, v := range stack {
		if v.Type() == act {
			return true
		}
	}
	return false
}

func (u *Unit) makeUnseen() { // nox_xxx_objectMakeUnseenByNoone_4E44E0
	u.field_38 = 0
}

func (u *Unit) needSync() { // nox_xxx_unitNeedSync_4E44F0
	u.field_38 = -1
}

func (u *Unit) countSubOfType(typ int) int { // nox_xxx_unitIsUnitTT_4E7C80
	if u == nil {
		return 0
	}
	cnt := 0
	for it := u.FirstOwned516(); it != nil; it = it.NextOwned512() {
		if it.objTypeInd() == typ && !it.Flags().Has(object.FlagDestroyed) {
			cnt++
		}
	}
	return cnt
}

func nox_xxx_playerSetState_4FA020(u *Unit, a2 int) {
	C.nox_xxx_playerSetState_4FA020(u.CObj(), C.int(a2))
}
