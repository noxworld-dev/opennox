package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_unitIsUnitTT_4E7C80(a1 *server.Object, a2 int) int {
	return asUnitS(a1).countSubOfType(a2)
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

type Unit struct {
	Object
}

func (u *Unit) SObj() *server.Object {
	if u == nil {
		return nil
	}
	return u.Object.SObj()
}

func (u *Unit) ScriptID() int {
	return u.SObj().ScriptID()
}

func (u *Unit) ObjScriptID() int {
	return u.SObj().ObjScriptID()
}

func (u *Unit) String() string {
	return u.stringAs("Unit")
}

func (u *Unit) move(cp *types.Pointf) {
	legacy.Nox_xxx_unitMove_4E7010(u.SObj(), cp)
}

func (u *Unit) SetPos(p types.Pointf) {
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = p
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
	return asPlayerS(u.SObj().ControllingPlayer())
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
	legacy.Nox_xxx_unitSetHP_4E4560(u.SObj(), uint16(v))
	if u.Class().Has(object.ClassMonster) {
		legacy.Nox_xxx_mobInformOwnerHP_4EE4C0(u.SObj())
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
	legacy.Nox_xxx_protectMana_56F9E0(int(pt.ProtUnitManaCur), int16(v-cur))
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
	legacy.Nox_xxx_monsterWalkTo_514110(u.SObj(), p.X, p.Y)
}

func (u *Unit) SetDir(v server.Dir16) {
	u.SObj().SetDir(v)
}

func (u *Unit) LookAt(p types.Pointf) {
	u.SObj().LookAt(p)
}

func (u *Unit) LookAtDir(dir int) {
	legacy.Nox_xxx_monsterLookAt_5125A0(u.SObj(), dir)
}

func (u *Unit) LookAngle(ang int) {
	v := nox_xxx_math_roundDir(int32(ang))
	u.SetDir(server.Dir16(v))
}

func (u *Unit) Freeze(freeze bool) {
	if freeze {
		legacy.Nox_xxx_unitFreeze_4E79C0(u.SObj(), 1)
	} else {
		legacy.Nox_xxx_unitUnFreeze_4E7A60(u.SObj(), 1)
	}
}

func (u *Unit) Wander() {
	legacy.Nox_xxx_scriptMonsterRoam_512930(u.SObj())
}

func (u *Unit) Return() {
	legacy.Nox_server_gotoHome(u.SObj())
}

func (u *Unit) Idle() {
	legacy.Nox_xxx_unitIdle_515820(u.SObj())
}

func (u *Unit) Follow(obj script.Positioner) {
	if v, ok := obj.(script.ObjectWrapper); ok {
		obj = v.GetObject()
	}
	cobj := obj.(server.Obj)
	legacy.Nox_xxx_unitSetFollow_5158C0(u.SObj(), cobj.SObj())
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
	legacy.Nox_xxx_unitHunt_5157A0(u.SObj())
}

func (u *Unit) Say(text string, dur script.Duration) {
	panic("implement me")
}

func (u *Unit) Mute() {
	panic("implement me")
}

func (u *Unit) AddGold(v int) {
	if v < 0 {
		legacy.Nox_xxx_playerSubGold_4FA5D0(u.SObj(), v)
	} else {
		legacy.Nox_xxx_playerAddGold_4FA590(u.SObj(), v)
	}
}

func (u *Unit) Cast(sp spell.ID, lvl int, targ script.Positioner) bool {
	if !sp.Valid() || lvl <= 0 {
		return false
	}
	var s *Server = u.getServer()
	sa, freeArg := alloc.New(server.SpellAcceptArg{})
	defer freeArg()
	if targ == nil {
		targ = u
	}
	if o, ok := targ.(server.Obj); ok {
		sa.Obj = toObjectS(o)
	}
	sa.Pos = targ.Pos()
	return s.castSpell(sp, lvl, u.SObj(), sa)
}

func (u *Unit) clearActionStack() { // aka nox_xxx_monsterClearActionStack_50A3A0
	if u.Class().Has(object.ClassMonster) {
		for legacy.Sub_5341F0(u.SObj()) == 0 {
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
	legacy.Nox_xxx_playerSetState_4FA020(u.SObj(), a2)
}
