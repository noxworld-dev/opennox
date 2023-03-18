package opennox

import (
	"image/color"
	"unsafe"

	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/noxscript/ns/v4/class"
	"github.com/noxworld-dev/noxscript/ns/v4/damage"
	"github.com/noxworld-dev/noxscript/ns/v4/enchant"
	"github.com/noxworld-dev/noxscript/ns/v4/subclass"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) ObjectType(name string) ns4.ObjType {
	typ := s.s.ObjectTypeByID(name)
	if typ == nil {
		return nil
	}
	return nsObjType{s.s, typ}
}

func (s noxScriptNS) ObjectTypeByInd(ind int) ns4.ObjType {
	typ := s.s.ObjectTypeByInd(ind)
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
		scriptLog.Printf("noxscript: cannot find object: %q", name)
		return nil
	}
	return nsObj{s.s, obj}
}

func (s noxScriptNS) ObjectGroupByHandle(h ns4.ObjGroupHandle) ns4.ObjGroup {
	if h == nil {
		return nil
	}
	g := s.s.MapGroups.GroupByInd(h.ObjGroupScriptID())
	if g == nil || mapGroupType(g) != server.MapGroupObjects {
		return nil
	}
	return nsObjGroup{s.s, g}
}

func (s noxScriptNS) ObjectGroup(name string) ns4.ObjGroup {
	g := s.s.GroupByID(name, server.MapGroupObjects)
	if g == nil {
		scriptLog.Printf("noxscript: cannot find object group: %q", name)
		return nil
	}
	return nsObjGroup{s.s, g}
}

func (s noxScriptNS) FindObjects(iter func(obj ns4.Obj) bool, conditions ...ns4.ObjCond) int {
	// This generic iteration function will act as a fallback that scans everything.
	search := func(fnc func(obj *server.Object) bool) {
		for it := s.s.FirstServerObject(); it != nil; it = it.Next() {
			if !fnc(it) {
				break
			}
		}
	}
	// Attempt to find a more specific iterator ad optimize it.
	for i, c := range conditions {
		found := false
		switch c := c.(type) {
		case ns4.InRectf:
			search = func(fnc func(obj *server.Object) bool) {
				s.s.Map.EachObjInRect(types.RectFromPointsf(c.Min, c.Max), fnc)
			}
			found = true
		case ns4.InCirclef:
			search = func(fnc func(obj *server.Object) bool) {
				s.s.Map.EachObjInCircle(c.Center.Pos(), float32(c.R), fnc)
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
	cnt := 0
	search(func(obj *server.Object) bool {
		nobj := nsObj{s.s, asObjectS(obj)}
		for _, c := range conditions {
			if !c.Matches(nobj) {
				return true // find next match
			}
		}
		// Found, pass to user-defined handler func.
		cnt++
		return iter(nobj)
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

func (s noxScriptNS) IsTrigger(obj ns4.Obj) bool {
	v := s.s.noxScript.Trigger()
	if v == nil || obj == nil {
		return false
	}
	return v.ScriptIDVal == obj.ScriptID()
}

func (s noxScriptNS) IsCaller(obj ns4.Obj) bool {
	v := s.s.noxScript.Caller()
	if v == nil || obj == nil {
		return false
	}
	return v.ScriptIDVal == obj.ScriptID()
}

func (s noxScriptNS) IsGameBall(obj ns4.Obj) bool {
	if obj == nil {
		return false
	}
	return s.s.GameBallID() == obj.Type().Index()
}

func (s noxScriptNS) IsCrown(obj ns4.Obj) bool {
	if obj == nil {
		return false
	}
	return s.s.CrownID() == obj.Type().Index()
}

func (s noxScriptNS) IsSummoned(obj ns4.Obj) bool {
	//TODO implement me
	panic("implement me")
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
	obj := typ.s.NewObject(typ.t)
	if obj == nil {
		return nil
	}
	typ.s.CreateObjectAt(obj, nil, p.Pos())
	return nsObj{typ.s, obj}
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

func (obj nsObj) IsLocked() bool {
	return obj.Class().Has(object.ClassDoor) && (*(*uint8)(unsafe.Add(obj.UpdateData, 1))) != 0
}

func (obj nsObj) Lock(lock bool) {
	if !obj.Class().Has(object.ClassDoor) {
		return
	}
	s := obj.getServer()
	flag, snd := byte(0), sound.SoundUnlock
	if lock {
		flag, snd = 5, sound.SoundLock
	}
	*(*uint8)(unsafe.Add(obj.UpdateData, 1)) = flag
	s.AudioEventObj(snd, obj, 0, 0)
}

func (obj nsObj) HasClass(class class.Class) bool {
	cls, err := object.ParseClass(string(class))
	if err != nil {
		return false
	}
	return obj.Class().Has(cls)
}

func (obj nsObj) HasSubclass(subclass subclass.SubClass) bool {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) HasEnchant(enc enchant.Enchant) bool {
	e, ok := server.ParseEnchant(string(enc))
	if !ok {
		return false
	}
	return obj.Object.HasEnchant(e)
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

func (obj nsObj) RestoreHealth(amount int) {
	if amount <= 0 {
		return
	}
	legacy.Nox_xxx_unitAdjustHP_4EE460(obj.SObj(), amount)
}

func (obj nsObj) CurrentMana() int {
	v, _ := obj.Mana()
	return v
}

func (obj nsObj) MaxMana() int {
	_, v := obj.Mana()
	return v
}

func (obj nsObj) GetGold() int {
	if obj.Object == nil {
		return 0
	}
	return legacy.Nox_object_getGold_4FA6D0(obj.SObj())
}

func (obj nsObj) ChangeGold(delta int) {
	if obj.Object == nil {
		return
	}
	legacy.Nox_object_setGold_4FA620(obj.SObj(), delta)
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
	if tm := s.Teams.ByYyy(u.team()); tm != nil {
		s.teamChangeLessons(tm, val+tm.Lessons)
	}
	nox_xxx_netReportLesson_4D8EF0(u)
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

func (obj nsObj) Freeze(freeze bool) {
	obj.Object.Freeze(freeze)
}

func (obj nsObj) Pause(dt ns4.Duration) {
	sub_516090(obj.SObj(), obj.s.AsFrames(dt))
}

func (obj nsObj) Move(w ns4.WaypointObj) {
	if w == nil {
		return
	}
	if obj.Flags().Has(object.FlagDead) {
		return
	}
	wp := w.(*Waypoint)
	legacy.Nox_server_scriptMoveTo_5123C0(obj.SObj(), wp.S())
}

func (obj nsObj) WalkTo(p types.Pointf) {
	obj.Object.WalkTo(p)
}

func (obj nsObj) LookAtDirection(dir ns4.Direction) {
	if obj.Class().Has(object.ClassMonster) && !obj.Flags().Has(object.FlagDead) {
		obj.LookAtDir(int(dir))
	}
}

func (obj nsObj) LookWithAngle(angle int) {
	dir := server.Dir16(nox_xxx_math_roundDir(int32(angle)))
	obj.setAllDirs(dir)
}

func (obj nsObj) LookAtObject(targ ns4.Positioner) {
	if targ == nil {
		return
	}
	dir := server.DirFromVec(targ.Pos().Sub(obj.Pos()))
	obj.setAllDirs(dir)
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

func (obj nsObj) Damage(source ns4.Obj, amount int, typ damage.Type) {
	if amount <= 0 {
		return
	}
	var src *Object
	if source != nil {
		src = source.(nsObj).Object
	}
	owner := src.FindOwnerChainPlayer()
	obj.CallDamage(owner, src, amount, object.DamageType(typ))
}

func (obj nsObj) DeleteAfter(dt ns4.Duration) {
	s := obj.s
	s.DeleteAfter(obj.Object.SObj(), uint32(s.AsFrames(dt)))
}

func (obj nsObj) Idle() {
	obj.Object.Idle()
}

func (obj nsObj) Wander() {
	obj.Object.Wander()
}

func (obj nsObj) Hunt() {
	obj.Object.Hunt()
}

func (obj nsObj) Return() {
	obj.Object.Return()
}

func (obj nsObj) Follow(targ ns4.Positioner) {
	if targ == nil {
		return
	}
	obj.Object.Follow(targ)
}

func (obj nsObj) Guard(p1, p2 types.Pointf, distance float32) {
	nox_xxx_monsterGoPatrol_515680(obj.SObj(), p1, p2, distance)
}

func (obj nsObj) Attack(targ ns4.Positioner) {
	if wr, ok := targ.(script.ObjectWrapper); ok {
		targ = wr.GetObject()
	}
	var tobj *server.Object
	switch targ := targ.(type) {
	case nil:
		tobj = nil
	case nsObj:
		tobj = targ.SObj()
	case server.Obj:
		tobj = targ.SObj()
	default:
		// Fallback to hitting position (ground).
		// TODO: pick melee/ranged automatically
		obj.HitMelee(targ.Pos())
		return
	}
	nox_xxx_mobSetFightTarg_515D30(obj.SObj(), tobj)
}

func (obj nsObj) IsAttackedBy(obj2 ns4.Obj) bool {
	if obj2 == nil {
		return false
	}
	return obj.isEnemyTo(obj2.(server.Obj))
}

func (obj nsObj) HitMelee(p types.Pointf) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) HitRanged(p types.Pointf) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) Flee(target ns4.Positioner, dt ns4.Duration) {
	var targ *server.Object
	nox_server_scriptFleeFrom_515F70(obj.SObj(), targ, obj.s.AsFrames(dt))
}

func (obj nsObj) HasItem(item ns4.Obj) bool {
	if item == nil {
		return false
	}
	return obj.Object.HasItem(toObject(item.(server.Obj)))
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

func (obj nsObj) Items() []ns4.Obj {
	var out []ns4.Obj
	for it := obj.FirstItem(); it != nil; it = it.NextItem() {
		out = append(out, nsObj{obj.s, it})
	}
	return out
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
	s := obj.getServer()
	it := toObject(item.(server.Obj))
	gold := s.ObjectTypeID("Gold")
	goldPile := s.ObjectTypeID("QuestGoldPile")
	goldChest := s.ObjectTypeID("QuestGoldChest")
	isPlayerInCoop := noxflags.HasGame(noxflags.GameModeCoop) && obj.Class().Has(object.ClassPlayer)
	if isPlayerInCoop {
		if f := s.Frame(); *memmap.PtrUint32(0x5D4594, 2386844) != f {
			*memmap.PtrUint32(0x5D4594, 2386844) = f
			legacy.Set_dword_5d4594_2386848(0)
			legacy.Set_dword_5d4594_2386852(0)
		}
		if typ := int(it.TypeInd); typ != gold && typ != goldPile && typ != goldChest {
			legacy.Nox_xxx_playerCanCarryItem_513B00(obj.SObj(), it.SObj())
		}
	}
	if legacy.Nox_xxx_inventoryServPlace_4F36F0(obj.SObj(), it.SObj(), 1, 1) == 0 {
		return false
	}
	if isPlayerInCoop && int(it.TypeInd) != gold {
		legacy.Inc_dword_5d4594_2386848()
	}
	return true
}

func (obj nsObj) Drop(item ns4.Obj) bool {
	if item == nil {
		return false
	}
	return obj.forceDrop(toObject(item.(server.Obj))) != 0
}

func (obj nsObj) Equip(item ns4.Obj) bool {
	if item == nil {
		return false
	}
	if !obj.HasItem(item) {
		if !obj.Pickup(item) {
			return false
		}
	}
	return legacy.Nox_xxx_playerTryEquip_4F2F70(obj.SObj(), item.(nsObj).SObj())
}

func (obj nsObj) SetColor(ind int, cl color.Color) {
	if obj.Class().Has(object.ClassMonster) {
		ud := obj.UpdateDataMonster()
		if ind >= 0 && ind < len(ud.Color) {
			ccl := server.AsColor3(cl)
			nox_xxx_setNPCColor_4E4A90(obj.SObj(), byte(ind), &ccl)
		}
	} else if obj.Class().Has(object.ClassPlayer) {
		panic("not implemented")
	}
}

func (obj nsObj) ZombieStayDown() {
	if obj.Class().Has(object.ClassMonster) {
		obj.UpdateDataMonster().Flags360 |= 0x100000
	}
}

func (obj nsObj) RaiseZombie() {
	legacy.Sub_516D00(obj.SObj())
}

func (obj nsObj) Chat(message ns4.StringID) {
	obj.ChatTimer(message, ns4.Frames(0))
}

func (obj nsObj) ChatTimer(message ns4.StringID, dt ns4.Duration) {
	s := obj.getServer()
	v, _ := s.Strings().GetVariantInFile(strman.ID(message), "CScrFunc.c")
	legacy.Nox_xxx_netSendChat_528AC0(obj.SObj(), v.Str, uint16(s.AsFrames(dt)))
	if noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Nox_xxx_playDialogFile_44D900(v.Str2, 100)
	}
}

func (obj nsObj) ChatStr(message string) {
	obj.ChatStrTimer(message, ns4.Frames(0))
}

func (obj nsObj) ChatStrTimer(message string, dt ns4.Duration) {
	s := obj.getServer()
	legacy.Nox_xxx_netSendChat_528AC0(obj.SObj(), message, uint16(s.AsFrames(dt)))
}

func (obj nsObj) DestroyChat() {
	nox_xxx_netKillChat_528D00(obj.Object)
}

func (obj nsObj) CreateMover(wp ns4.WaypointObj, speed float32) ns4.Obj {
	s := obj.getServer()
	mv := asObjectS(s.NewObjectByTypeID("Mover"))
	if mv == nil {
		return nil
	}
	s.CreateObjectAt(mv, nil, obj.Pos())
	mv.VelVec = types.Pointf{}

	ud := mv.updateDataMover()
	ud.Field_7 = obj.SObj()
	ud.Field_2 = int32(wp.ScriptID())
	ud.Field_1 = speed
	ud.Field_0 = 0

	mv.Enable(true)
	s.Objs.AddToUpdatable(mv.SObj())
	return nsObj{obj.s, mv}
}

func (obj nsObj) GetElevatorStatus() int {
	if !obj.Class().Has(object.ClassElevator) {
		return -1
	}
	return int(obj.updateDataElevator().Field_3)
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

func (obj nsObj) OnEvent(event ns4.ObjectEvent, fnc ns4.Func) {
	//TODO implement me
	panic("implement me")
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
	eachObjectRecursiveNS(g.s, g.g, func(obj ns4.Obj) bool {
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
	eachObjectRecursiveNS(g.s, g.g, func(obj ns4.Obj) bool {
		obj.Guard(p1, p2, distance)
		return true
	})
}

func (g nsObjGroup) Flee(target ns4.Positioner, dt ns4.Duration) {
	eachObjectRecursiveNS(g.s, g.g, func(obj ns4.Obj) bool {
		obj.Flee(target, dt)
		return true
	})
}

func (g nsObjGroup) HitMelee(p types.Pointf) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) HitRanged(p types.Pointf) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) Attack(targ ns4.Positioner) {
	eachObjectRecursiveNS(g.s, g.g, func(obj ns4.Obj) bool {
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
		eachObjectRecursiveNS(g.s, g.g, fnc)
	} else {
		eachObjectNS(g.s, g.g, fnc)
	}
}
