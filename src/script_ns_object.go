package opennox

import (
	"fmt"

	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/noxscript/ns/v4/class"
	"github.com/noxworld-dev/noxscript/ns/v4/damage"
	"github.com/noxworld-dev/noxscript/ns/v4/enchant"
	"github.com/noxworld-dev/noxscript/ns/v4/subclass"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) ObjectType(name string) ns4.ObjType {
	typ := s.s.Types.ByID(name)
	if typ == nil {
		return nil
	}
	return nsObjType{s.s, typ}
}

func (s noxScriptNS) ObjectTypeByInd(ind int) ns4.ObjType {
	typ := s.s.Types.ByInd(ind)
	if typ == nil {
		return nil
	}
	return nsObjType{s.s, typ}
}

func (s noxScriptNS) ObjectByHandle(h ns4.ObjHandle) ns4.Obj {
	if h == nil {
		return nil
	}
	obj := s.s.noxScript.ScriptToObject(h.ObjScriptID())
	if obj == nil {
		return nil
	}
	return nsObj{s.s, asObjectS(obj)}
}

func (s noxScriptNS) CreateObject(typ string, p ns4.Positioner) ns4.Obj {
	if p == nil {
		return nil
	}
	obj := s.s.NewObjectByTypeID(typ)
	if obj == nil {
		return nil
	}
	s.s.CreateObjectAt(obj, nil, p.Pos())
	return nsObj{s.s, asObjectS(obj)}
}

func (s noxScriptNS) Object(name string) ns4.Obj {
	obj := asObjectS(legacy.Nox_xxx_getObjectByScrName_4DA4F0(name))
	if obj == nil {
		ScriptLog.Printf("noxscript: cannot find object: %q", name)
		return nil
	}
	return nsObj{s.s, obj}
}

func (s noxScriptNS) ObjectGroupByHandle(h ns4.ObjGroupHandle) ns4.ObjGroup {
	if h == nil {
		return nil
	}
	g := s.s.MapGroups.GroupByInd(h.ObjGroupScriptID())
	if g == nil || s.s.MapGroups.MapGroupType(g) != server.MapGroupObjects {
		return nil
	}
	return nsObjGroup{s.s, g}
}

func (s noxScriptNS) ObjectGroup(name string) ns4.ObjGroup {
	g := s.s.MapGroups.GroupByID(name, server.MapGroupObjects)
	if g == nil {
		ScriptLog.Printf("noxscript: cannot find object group: %q", name)
		return nil
	}
	return nsObjGroup{s.s, g}
}

func (s noxScriptNS) FindObjects(iter func(obj ns4.Obj) bool, conditions ...ns4.ObjCond) int {
	// This generic iteration function will act as a fallback that scans everything.
	search := func(fnc func(obj *server.Object) bool) {
		for it := s.s.Objs.First(); it != nil; it = it.Next() {
			if !fnc(it) {
				return
			}
		}
		for it := s.s.Objs.MissileList; it != nil; it = it.Next() {
			if !fnc(it) {
				return
			}
		}
	}
	// Attempt to find a more specific iterator ad optimize it.
	for i, c := range conditions {
		found := false
		switch c := c.(type) {
		case ns4.InRectf:
			search = func(fnc func(obj *server.Object) bool) {
				s.s.Map.EachObjAndMissileInRect(types.RectFromPointsf(c.Min, c.Max), fnc)
			}
			found = true
		case ns4.InCirclef:
			search = func(fnc func(obj *server.Object) bool) {
				s.s.Map.EachObjAndMissileInCircle(c.Center.Pos(), float32(c.R), fnc)
			}
			found = true
		}
		// We only need one optimized iterator. Once found - remove it from conditions.
		if found {
			conditions = append(conditions[:i], conditions[i+1:]...)
			break
		}
	}
	// Finally start the actual iteration.
	filter := ns4.AND(conditions)
	cnt := 0
	search(func(obj *server.Object) bool {
		nobj := nsObj{s.s, asObjectS(obj)}
		if !filter.Matches(nobj) {
			return true // find next match
		}
		// Found, pass to user-defined handler func.
		cnt++
		if iter != nil && !iter(nobj) {
			return false
		}
		return true
	})
	return cnt
}

func (s noxScriptNS) GetTrigger() ns4.Obj {
	obj := asObjectS(s.s.noxScript.Trigger())
	if obj == nil {
		return nil
	}
	return nsObj{s.s, obj}
}

func (s noxScriptNS) GetCaller() ns4.Obj {
	obj := asObjectS(s.s.noxScript.Caller())
	if obj == nil {
		return nil
	}
	return nsObj{s.s, obj}
}

func (s noxScriptNS) DestroyEveryChat() {
	legacy.Nox_xxx_destroyEveryChatMB_528D60()
}

func (s noxScriptNS) MakeFriendly(obj ns4.Obj) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) MakeEnemy(obj ns4.Obj) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) BecomePet(obj ns4.Obj) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) BecomeEnemy(obj ns4.Obj) {
	//TODO implement me
	panic("implement me")
}

type nsObjType struct {
	s *Server
	t *server.ObjectType
}

func (typ nsObjType) Name() string {
	return typ.t.ID()
}

func (typ nsObjType) Index() int {
	return typ.t.Ind()
}

func (typ nsObjType) Create(p ns4.Positioner) ns4.Obj {
	if p == nil {
		return nil
	}
	obj := typ.s.Objs.NewObject(typ.t)
	if obj == nil {
		return nil
	}
	typ.s.CreateObjectAt(obj, nil, p.Pos())
	return nsObj{typ.s, asObjectS(obj)}
}

func (typ nsObjType) Class() object.Class {
	return typ.t.Class()
}

func (typ nsObjType) HasClass(class class.Class) bool {
	cls, err := object.ParseClass(string(class))
	if err != nil {
		return false
	}
	return typ.t.Class().Has(cls)
}

func (typ nsObjType) HasSubclass(subclass subclass.SubClass) bool {
	//TODO implement me
	panic("implement me")
}

func (typ nsObjType) Flags() object.Flags {
	return typ.t.Flags()
}

var _ server.Obj = nsObj{}

type nsObj struct {
	s *Server
	*Object
}

func (obj nsObj) ScriptID() int {
	return obj.Object.ScriptIDVal
}

func (obj nsObj) ObjScriptID() int {
	return obj.Object.ScriptIDVal
}

func (obj nsObj) Type() ns4.ObjType {
	return nsObjType{obj.s, obj.Object.ObjectTypeC()}
}

func (obj nsObj) Mass() float32 {
	return obj.Object.Mass
}

func (obj nsObj) SetMass(v float32) {
	obj.Object.Mass = v
	obj.Object.NeedSync()
}

func (obj nsObj) Team() ns4.Team {
	t := obj.Object.Team()
	if t == nil {
		return nil
	}
	return nsTeam{obj.s, t}
}

func (obj nsObj) HasTeam(t ns4.Team) bool {
	if t == nil {
		return !obj.Object.HasTeam()
	}
	tm, ok := t.(nsTeam)
	if !ok {
		return false
	}
	return obj.TeamEqual(tm.t)
}

func (obj nsObj) SetTeam(t ns4.Team) {
	if t == nil {
		return // TODO: support clearing the team
	}
	tm, ok := t.(nsTeam)
	if !ok {
		return
	}
	obj.Object.SetTeam(tm.t)
}

func (obj nsObj) HasClass(class class.Class) bool {
	cls, err := object.ParseClass(string(class))
	if err != nil {
		return false
	}
	return obj.Class().Has(cls)
}

func (obj nsObj) HasSubclass(subclass subclass.SubClass) bool {
	cls, err := object.ParseSubClass(string(subclass))
	if err != nil {
		return false
	}
	return obj.SubClass().Has(cls)
}

func (obj nsObj) HasEnchant(enc enchant.Enchant) bool {
	e, ok := server.ParseEnchant(string(enc))
	if !ok {
		return false
	}
	return obj.Object.HasEnchant(e)
}

func (obj nsObj) MonsterStatus() object.MonsterStatus {
	if !obj.Class().Has(object.ClassMonster) {
		return 0
	}
	return obj.UpdateDataMonster().StatusFlags
}

func (obj nsObj) Direction() ns4.Direction {
	return ns4.Direction(obj.Dir1())
}

func (obj nsObj) CurrentHealth() int {
	v, _ := obj.Health()
	return v
}

func (obj nsObj) MaxHealth() int {
	_, v := obj.Health()
	return v
}

func (obj nsObj) CurrentMana() int {
	v, _ := obj.Mana()
	return v
}

func (obj nsObj) MaxMana() int {
	_, v := obj.Mana()
	return v
}

func (obj nsObj) GiveXp(xp float32) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) Player() ns4.Player {
	if !obj.Class().Has(object.ClassPlayer) {
		return nil
	}
	pl := obj.ControllingPlayer()
	if pl == nil {
		return nil
	}
	return nsPlayer{obj.s, pl}
}

func (obj nsObj) GetScore() int {
	pl := obj.Player()
	if pl == nil {
		return 0
	}
	return pl.GetScore()
}

func (obj nsObj) GetClass() player.Class {
	if !obj.Class().Has(object.ClassPlayer) {
		return 0
	}
	return obj.ControllingPlayer().PlayerClass()
}

func (obj nsObj) GetLevel() int {
	if !obj.Class().Has(object.ClassPlayer) {
		return 0
	}
	return int(obj.ControllingPlayer().Level)
}

func (obj nsObj) ChangeScore(val int) {
	if !obj.Class().Has(object.ClassPlayer) {
		return
	}
	u := obj.Object
	if val <= 0 {
		nox_xxx_playerSubLessons_4D8EC0(u, -val)
	} else {
		nox_xxx_changeScore_4D8E90(u, val)
	}
	s := obj.getServer()
	if tm := u.Team(); tm != nil {
		s.TeamChangeLessons(tm, val+tm.Lessons)
	}
	s.Nox_xxx_netReportLesson_4D8EF0(u.SObj())
}

func (obj nsObj) HasOwner(owner ns4.Obj) bool {
	own, _ := owner.(server.Obj)
	return obj.Object.HasOwner(toObject(own))
}

func (obj nsObj) HasOwnerIn(owners ns4.ObjGroup) bool {
	if owners == nil {
		return false
	}
	ok := false
	owners.EachObject(false, func(own ns4.Obj) bool {
		ok = obj.HasOwner(own)
		return !ok // stop if has any owner
	})
	return ok
}

func (obj nsObj) SetOwner(owner ns4.Obj) {
	if owner == nil {
		obj.Object.SetOwner(nil)
		return
	}
	v := toObject(owner.(server.Obj))
	obj.Object.SetOwner(v)
}

func (obj nsObj) SetOwners(owners ns4.ObjGroup) {
	if owners == nil {
		obj.Object.SetOwner(nil)
		return
	}
	owners.EachObject(false, func(it ns4.Obj) bool {
		obj.SetOwner(it)
		return true
	})
}

func (obj nsObj) CanSee(obj2 ns4.Obj) bool {
	if obj.Object == nil || obj2 == nil {
		return false
	}
	return obj.Object.CanSee(obj2.(nsObj).Object)
}

func (obj nsObj) PushTo(p ns4.Positioner, force float32) {
	if p != nil {
		obj.Push(p.Pos(), force)
	}
}

func (obj nsObj) Damage(source ns4.Obj, amount int, typ damage.Type) bool {
	var src *server.Object
	if source != nil {
		src = source.(nsObj).Object.SObj()
	}
	return obj.Object.DoDamage(src, amount, object.DamageType(typ))
}

func (obj nsObj) DeleteAfter(dt ns4.Duration) {
	s := obj.s
	s.DeleteAfter(obj.Object.SObj(), uint32(s.AsFrames(dt)))
}

func (obj nsObj) IsAttackedBy(obj2 ns4.Obj) bool {
	if obj2 == nil {
		return false
	}
	return obj.Object.IsAttackedBy(obj2.(server.Obj).SObj())
}

func (obj nsObj) HasItem(item ns4.Obj) bool {
	if item == nil {
		return false
	}
	return obj.Object.HasItem(toObject(item.(server.Obj)))
}

func (obj nsObj) HasEquipment(item ns4.Obj) bool {
	if !obj.HasItem(item) {
		return false
	}
	return item.Flags().Has(object.FlagEquipped)
}

func (obj nsObj) GetLastItem() ns4.Obj {
	it := obj.FirstItem()
	if it == nil {
		return nil
	}
	return nsObj{obj.s, it}
}

func (obj nsObj) GetPreviousItem() ns4.Obj {
	it := obj.NextItem()
	if it == nil {
		return nil
	}
	return nsObj{obj.s, it}
}

func (obj nsObj) Items(conditions ...ns4.ObjCond) []ns4.Obj {
	filter := ns4.AND(conditions)
	var out []ns4.Obj
	for it := obj.FirstItem(); it != nil; it = it.NextItem() {
		v := nsObj{obj.s, it}
		if filter.Matches(v) {
			out = append(out, v)
		}
	}
	return out
}

func (obj nsObj) Equipment(conditions ...ns4.ObjCond) []ns4.Obj {
	conditions = append(conditions, ns4.HasObjFlags(object.FlagEquipped))
	return obj.Items(conditions...)
}

type nsObjInItems struct {
	obj     nsObj
	filters []ns4.ObjCond
}

func (s nsObjInItems) FindObjects(fnc func(it ns4.Obj) bool, conditions ...ns4.ObjCond) int {
	filter := ns4.AND(conditions)
	filter = append(filter, s.filters...)
	cnt := 0
	for it := s.obj.FirstItem(); it != nil; it = it.NextItem() {
		v := nsObj{s.obj.s, it}
		if !filter.Matches(v) {
			continue
		}
		cnt++
		if fnc != nil && !fnc(v) {
			break
		}
	}
	return cnt
}

func (obj nsObj) InItems() ns4.ObjSearcher {
	return nsObjInItems{obj: obj}
}

func (obj nsObj) InEquipment() ns4.ObjSearcher {
	return nsObjInItems{obj: obj, filters: []ns4.ObjCond{
		ns4.HasObjFlags(object.FlagEquipped),
	}}
}

func (obj nsObj) FindItems(fnc func(it ns4.Obj) bool, conditions ...ns4.ObjCond) int {
	return obj.InItems().FindObjects(fnc, conditions...)
}

func (obj nsObj) GetHolder() ns4.Obj {
	obj2 := obj.InventoryHolder()
	if obj2 == nil {
		return nil
	}
	return nsObj{obj.s, obj2}
}

func (obj nsObj) Pickup(item ns4.Obj) bool {
	if item == nil {
		return false
	}
	return obj.Object.DoPickup(toObject(item.(server.Obj)))
}

func (obj nsObj) Drop(item ns4.Obj) bool {
	if item == nil {
		return false
	}
	return obj.DoDrop(toObject(item.(server.Obj)))
}

func (obj nsObj) Equip(item ns4.Obj) bool {
	if item == nil {
		return false
	}
	return obj.Object.Equip(toObject(item.(server.Obj)))
}

func (obj nsObj) Unequip(item ns4.Obj) bool {
	if item == nil {
		return false
	}
	return obj.Object.Unequip(toObject(item.(server.Obj)))
}

func (obj nsObj) CreateMover(wp ns4.WaypointObj, speed float32) ns4.Obj {
	mv := obj.Object.CreateMover(wp, speed)
	return nsObj{obj.s, mv}
}

func (obj nsObj) GetElevatorStatus() int {
	if !obj.Class().Has(object.ClassElevator) {
		return -1
	}
	return int(obj.UpdateDataElevator().Field_3)
}

func (obj nsObj) AggressionLevel(level float32) {
	obj.Object.SetAggression(level)
}

func (obj nsObj) SetRoamFlag(flags int) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) RetreatLevel(percent float32) {
	obj.Object.SetRetreatLevel(percent)
}

func (obj nsObj) ResumeLevel(percent float32) {
	obj.Object.SetRegroupLevel(percent)
}

func (obj nsObj) OnEvent(ev ns4.ObjectEvent, fnc ns4.Func) {
	if !obj.Class().Has(object.ClassMonster) {
		return
	}
	ind := int32(obj.s.noxScript.AsFuncIndex(fmt.Sprintf("OnEvent_%d", int(ev)), fnc))
	ud := obj.UpdateDataMonster()
	switch ev {
	case ns4.EventEnemySighted: // Enemy sighted
		ud.ScriptEnemySighted.Func = ind
	case ns4.EventLookingForEnemy: // Looking for enemy
		ud.ScriptLookingForEnemy.Func = ind
	case ns4.EventDeath: // Death
		ud.ScriptDeath.Func = ind
	case ns4.EventChangeFocus: // Change focus
		ud.ScriptChangeFocus.Func = ind
	case ns4.EventIsHit: // Is hit
		ud.ScriptIsHit.Func = ind
	case ns4.EventRetreat: // Retreat
		ud.ScriptRetreat.Func = ind
	case ns4.EventCollision: // Collision
		ud.ScriptCollision.Func = ind
	case ns4.EventEnemyHeard: // Enemy heard
		ud.ScriptHearEnemy.Func = ind
	case ns4.EventEndOfWaypoint: // End of waypoint
		ud.ScriptEndOfWaypoint.Func = ind
	case ns4.EventLostEnemy: // Lost sight of enemy
		ud.ScriptLostEnemy.Func = ind
	}
}

type nsObjGroup struct {
	s *Server
	g *server.MapGroup
}

func (g nsObjGroup) ScriptID() int {
	return int(g.g.Index())
}

func (g nsObjGroup) ObjGroupScriptID() int {
	return int(g.g.Index())
}

func (g nsObjGroup) Name() string {
	return g.g.ID()
}

func (g nsObjGroup) Enable(enable bool) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Enable(enable)
		return true
	})
}

func (g nsObjGroup) Toggle() bool {
	one := false
	g.EachObject(true, func(obj ns4.Obj) bool {
		if obj.Toggle() {
			one = true
		}
		return true
	})
	return one
}

func (g nsObjGroup) HasOwner(owner ns4.Obj) bool {
	ok := true
	g.EachObject(false, func(obj ns4.Obj) bool {
		ok = obj.HasOwner(owner)
		return ok
	})
	return ok
}

func (g nsObjGroup) HasOwnerIn(owners ns4.ObjGroup) bool {
	// TODO: not exactly sure if the logic was like this
	ok := true
	g.EachObject(false, func(obj ns4.Obj) bool {
		ok = obj.HasOwnerIn(owners)
		return ok
	})
	return ok
}

func (g nsObjGroup) SetOwner(owner ns4.Obj) {
	g.EachObject(false, func(obj ns4.Obj) bool {
		obj.SetOwner(owner)
		return true
	})
}

func (g nsObjGroup) SetOwners(owners ns4.ObjGroup) {
	g.EachObject(false, func(obj ns4.Obj) bool {
		obj.SetOwners(owners)
		return true
	})
}

func (g nsObjGroup) Pause(dt ns4.Duration) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Pause(dt)
		return true
	})
}

func (g nsObjGroup) Move(wp ns4.WaypointObj) {
	if wp == nil {
		return
	}
	g.EachObject(false, func(obj ns4.Obj) bool {
		obj.Move(wp)
		return true
	})
}

func (g nsObjGroup) WalkTo(p types.Pointf) {
	g.EachObject(false, func(obj ns4.Obj) bool {
		obj.WalkTo(p)
		return true
	})
}

func (g nsObjGroup) LookAtDirection(dir ns4.Direction) {
	g.EachObject(false, func(obj ns4.Obj) bool {
		obj.LookAtDirection(dir)
		return true
	})
}

func (g nsObjGroup) Damage(source ns4.Obj, amount int, typ damage.Type) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Damage(source, amount, typ)
		return true
	})
}

func (g nsObjGroup) Delete() {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) Idle() {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Idle()
		return true
	})
}

func (g nsObjGroup) Wander() {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) Hunt() {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Hunt()
		return true
	})
}

func (g nsObjGroup) Follow(targ ns4.Positioner) {
	if targ == nil {
		return
	}
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Follow(targ)
		return true
	})
}

func (g nsObjGroup) Guard(p1, p2 types.Pointf, distance float32) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Guard(p1, p2, distance)
		return true
	})
}

func (g nsObjGroup) Flee(target ns4.Positioner, dt ns4.Duration) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Flee(target, dt)
		return true
	})
}

func (g nsObjGroup) HitMelee(pos types.Pointf) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.HitMelee(pos)
		return true
	})
}

func (g nsObjGroup) HitRanged(pos types.Pointf) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.HitRanged(pos)
		return true
	})
}

func (g nsObjGroup) Attack(targ ns4.Positioner) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Attack(targ)
		return true
	})
}

func (g nsObjGroup) ZombieStayDown() {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.ZombieStayDown()
		return true
	})
}

func (g nsObjGroup) RaiseZombie() {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.RaiseZombie()
		return true
	})
}

func (g nsObjGroup) CreateMover(wp ns4.WaypointObj, speed float32) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.CreateMover(wp, speed)
		return true
	})
}

func (g nsObjGroup) AggressionLevel(level float32) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.AggressionLevel(level)
		return true
	})
}

func (g nsObjGroup) SetRoamFlag(flags int) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) RetreatLevel(percent float32) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.RetreatLevel(percent)
		return true
	})
}

func (g nsObjGroup) ResumeLevel(percent float32) {
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.ResumeLevel(percent)
		return true
	})
}

func (g nsObjGroup) Enchant(enchant enchant.Enchant, dt ns4.Duration) {
	if _, ok := server.ParseEnchant(string(enchant)); !ok {
		return
	}
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Enchant(enchant, dt)
		return true
	})
}

func (g nsObjGroup) EachObject(recursive bool, fnc func(obj ns4.Obj) bool) {
	if recursive {
		server.EachObjectRecursive(g.s.Server, g.g, func(obj *server.Object) bool {
			return fnc(nsObj{g.s, asObjectS(obj)})
		})
	} else {
		server.EachObject(g.s.Server, g.g, func(obj *server.Object) bool {
			return fnc(nsObj{g.s, asObjectS(obj)})
		})
	}
}

func (g nsObjGroup) AllObjects() ns4.Objects {
	var out ns4.Objects
	g.EachObject(true, func(obj ns4.Obj) bool {
		out = append(out, obj)
		return true
	})
	return out
}

func (g nsObjGroup) FindObjects(fnc func(it ns4.Obj) bool, conditions ...ns4.ObjCond) int {
	filter := ns4.AND(conditions)
	cnt := 0
	g.EachObject(true, func(obj ns4.Obj) bool {
		if !filter.Matches(obj) {
			return true // continue
		}
		cnt++
		if fnc != nil && !fnc(obj) {
			return false // break
		}
		return true
	})
	return cnt
}
