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
	"github.com/noxworld-dev/opennox/v1/server"
)

//export nox_xxx_unitIsUnitTT_4E7C80
func nox_xxx_unitIsUnitTT_4E7C80(a1 *nox_object_t, a2 int) int {
	return asUnitC(a1).countSubOfType(a2)
}

func asUnit(p unsafe.Pointer) *Unit {
	if p == nil {
		return nil
	}
	return (*Unit)(p)
}

func asUnitS(p *server.Object) *Unit {
	if p == nil {
		return nil
	}
	return (*Unit)(unsafe.Pointer(p))
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

func (u *Unit) SObj() *server.Object {
	if u == nil {
		return nil
	}
	return u.Object.SObj()
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

func (u *Unit) Destroy() {
	panic("implement me")
	u.Delete()
}

func (u *Unit) CanSee(obj script.Object) bool {
	panic("implement me")
}

func (u *Unit) UpdateDataPlayer() *server.PlayerUpdateData {
	return u.SObj().UpdateDataPlayer()
}

func (u *Unit) UpdateDataMonster() *server.MonsterUpdateData {
	return u.SObj().UpdateDataMonster()
}

func (u *Unit) ControllingPlayer() *Player {
	if u == nil {
		return nil
	}
	ud := u.UpdateDataPlayer()
	return asPlayerS(ud.Player)
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
	h := u.HealthData
	if h == nil {
		return
	}
	// TODO: verify it works in MP
	// TODO: if it's the player, we need to adjust GUI health bars
	h.Max = uint16(v)
	u.SetHealth(v)
}

func (u *Unit) Mana() (cur, max int) {
	return u.SObj().Mana()
}

func (u *Unit) SetMana(v int) {
	if u == nil {
		return
	}
	if v < 0 {
		v = 0
	}
	p := u.UpdateDataPlayer()
	if p == nil {
		return
	}
	if _, max := u.Mana(); v > max {
		v = max
	}
	cur := int(p.ManaCur)
	p.ManaPrev = uint16(cur)
	p.ManaCur = uint16(v)
	pt := asPlayerS(p.Player)
	C.nox_xxx_protectMana_56F9E0(C.int(pt.ProtUnitManaCur), C.short(v-cur))
}

func (u *Unit) SetMaxMana(v int) {
	if u == nil {
		return
	}
	if v < 0 {
		v = 0
	}
	p := u.UpdateDataPlayer()
	if p == nil {
		return
	}
	p.ManaMax = uint16(v)
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

func (u *Unit) SetDir(v server.Dir16) {
	u.SObj().SetDir(v)
}

func (u *Unit) LookAt(p types.Pointf) {
	u.SObj().LookAt(p)
}

func (u *Unit) LookAtDir(dir int) {
	C.nox_xxx_monsterLookAt_5125A0(u.CObj(), C.int(dir))
}

func (u *Unit) LookAngle(ang int) {
	v := nox_xxx_math_roundDir(int32(ang))
	u.SetDir(server.Dir16(v))
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
			u.monsterPopAction()
		}
	}
}

func (u *Unit) monsterPushAction(act ai.ActionType, args ...any) *server.AIStackItem { // aka nox_xxx_monsterPushAction_50A260
	st := u.monsterPushActionImpl(act, "go", 0)
	if len(args) != 0 {
		aiStackSetArgs(st, args...)
	}
	return st
}

func (u *Unit) monsterActionIsScheduled(act ai.ActionType) bool { // nox_xxx_monsterIsActionScheduled_50A090
	stack := u.UpdateDataMonster().GetAIStack()
	for _, v := range stack {
		if v.Type() == act {
			return true
		}
	}
	return false
}

func (u *Unit) countSubOfType(typ int) int { // nox_xxx_unitIsUnitTT_4E7C80
	if u == nil {
		return 0
	}
	cnt := 0
	for it := u.FirstOwned516(); it != nil; it = it.NextOwned512() {
		if int(it.TypeInd) == typ && !it.Flags().Has(object.FlagDestroyed) {
			cnt++
		}
	}
	return cnt
}

func nox_xxx_playerSetState_4FA020(u *Unit, a2 int) {
	C.nox_xxx_playerSetState_4FA020(u.CObj(), C.int(a2))
}
