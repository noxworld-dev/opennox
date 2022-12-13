package opennox

/*
#include "defs.h"
extern int dword_5d4594_2386848;
extern unsigned int dword_5d4594_2386852;

unsigned int sub_516D00(nox_object_t* a1);
int* nox_server_scriptMoveTo_5123C0(int a1, int a2);
int nox_xxx_destroyEveryChatMB_528D60();
nox_object_t* nox_xxx_getObjectByScrName_4DA4F0(char* a1);
int nox_xxx_playDialogFile_44D900(char* a1, int a2);
int nox_xxx_netSendChat_528AC0(nox_object_t* a1, wchar_t* a2, wchar_t a3);
int nox_xxx_inventoryServPlace_4F36F0(nox_object_t* a1p, nox_object_t* a2p, int a3, int a4);
void nox_xxx_playerCanCarryItem_513B00(nox_object_t* a1p, nox_object_t* a2p);
void nox_xxx_unitAdjustHP_4EE460(nox_object_t* unit, int dv);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns/class"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns/damage"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns/enchant"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns/subclass"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) CreateObject(typ string, p script.Positioner) ns.Obj {
	if p == nil {
		return nil
	}
	obj := s.s.newObjectByTypeID(typ)
	if obj == nil {
		return nil
	}
	s.s.createObjectAt(obj, nil, p.Pos())
	return nsObj{obj}
}

func (s noxScriptNS) Object(name string) ns.Obj {
	cstr := CString(name)
	defer StrFree(cstr)
	obj := asObjectC(C.nox_xxx_getObjectByScrName_4DA4F0(cstr))
	if obj == nil {
		scriptLog.Printf("noxscript: cannot find object: %q", name)
		return nil
	}
	return nsObj{obj}
}

func (s noxScriptNS) ObjectGroup(name string) ns.ObjGroup {
	g := s.s.mapGroups.GroupByID(name, mapGroupObjects)
	if g == nil {
		scriptLog.Printf("noxscript: cannot find object group: %q", name)
		return nil
	}
	return nsObjGroup{s.s, g}
}

func (s noxScriptNS) GetTrigger() ns.Obj {
	obj := s.s.noxScript.Trigger()
	if obj == nil {
		return nil
	}
	return nsObj{obj}
}

func (s noxScriptNS) GetCaller() ns.Obj {
	obj := s.s.noxScript.Caller()
	if obj == nil {
		return nil
	}
	return nsObj{obj}
}

func (s noxScriptNS) IsTrigger(obj ns.Obj) bool {
	v := s.s.noxScript.Trigger()
	if v == nil || obj == nil {
		return false
	}
	return v.ScriptID == obj.ScriptID()
}

func (s noxScriptNS) IsCaller(obj ns.Obj) bool {
	v := s.s.noxScript.Caller()
	if v == nil || obj == nil {
		return false
	}
	return v.ScriptID == obj.ScriptID()
}

func (s noxScriptNS) IsGameBall(obj ns.Obj) bool {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) IsCrown(obj ns.Obj) bool {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) IsSummoned(obj ns.Obj) bool {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) DestroyEveryChat() {
	C.nox_xxx_destroyEveryChatMB_528D60()
}

func (s noxScriptNS) MakeFriendly(obj ns.Obj) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) MakeEnemy(obj ns.Obj) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) BecomePet(obj ns.Obj) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) BecomeEnemy(obj ns.Obj) {
	//TODO implement me
	panic("implement me")
}

var _ noxObject = nsObj{}

type nsObj struct {
	*Object
}

func (obj nsObj) ScriptID() int {
	return obj.Object.ScriptID
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
	s.AudioEventObj(snd, obj.AsUnit(), 0, 0)
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

func (obj nsObj) Direction() ns.Direction {
	return ns.Direction(obj.Dir1())
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
	C.nox_xxx_unitAdjustHP_4EE460(obj.CObj(), C.int(amount))
}

func (obj nsObj) GetGold() int {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) ChangeGold(delta int) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) GiveXp(xp float32) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) GetScore() int {
	if !obj.Class().Has(object.ClassPlayer) {
		return 0
	}
	pl := obj.AsUnit().ControllingPlayer()
	return int(pl.lessons)
}

func (obj nsObj) ChangeScore(val int) {
	if !obj.Class().Has(object.ClassPlayer) {
		return
	}
	u := obj.AsUnit()
	if val <= 0 {
		nox_xxx_playerSubLessons_4D8EC0(u, -val)
	} else {
		nox_xxx_changeScore_4D8E90(u, val)
	}
	s := obj.getServer()
	if tm := s.teamByYyy(u.team()); tm != nil {
		s.teamChangeLessons(tm, val+int(tm.lessons))
	}
	nox_xxx_netReportLesson_4D8EF0(u)
}

func (obj nsObj) HasOwner(owner ns.Obj) bool {
	own, _ := owner.(noxObject)
	return obj.Object.HasOwner(toObject(own))
}

func (obj nsObj) HasOwnerIn(owners ns.ObjGroup) bool {
	if owners == nil {
		return false
	}
	ok := false
	owners.EachObject(false, func(own ns.Obj) bool {
		ok = obj.HasOwner(own)
		return !ok // stop if has any owner
	})
	return ok
}

func (obj nsObj) SetOwner(owner ns.Obj) {
	if owner == nil {
		obj.Object.SetOwner(nil)
		return
	}
	v := owner.(noxObject)
	obj.Object.SetOwner(v.AsObject())
}

func (obj nsObj) SetOwners(owners ns.ObjGroup) {
	if owners == nil {
		obj.Object.SetOwner(nil)
		return
	}
	owners.EachObject(false, func(it ns.Obj) bool {
		obj.SetOwner(it)
		return true
	})
}

func (obj nsObj) Freeze(freeze bool) {
	obj.Object.AsUnit().Freeze(freeze)
}

func (obj nsObj) Pause(dt script.Duration) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) Move(w ns.WaypointObj) {
	if w == nil {
		return
	}
	if obj.Flags().Has(object.FlagDead) {
		return
	}
	wp := w.(*Waypoint)
	C.nox_server_scriptMoveTo_5123C0(C.int(uintptr(unsafe.Pointer(obj.CObj()))), C.int(uintptr(unsafe.Pointer(wp.C()))))
}

func (obj nsObj) WalkTo(p types.Pointf) {
	obj.AsUnit().WalkTo(p)
}

func (obj nsObj) LookAtDirection(dir ns.Direction) {
	if obj.Class().Has(object.ClassMonster) && !obj.Flags().Has(object.FlagDead) {
		obj.AsUnit().LookAtDir(int(dir))
	}
}

func (obj nsObj) LookWithAngle(angle int) {
	dir := server.Dir16(nox_xxx_math_roundDir(int32(angle)))
	obj.setAllDirs(dir)
}

func (obj nsObj) LookAtObject(targ script.Positioner) {
	if targ == nil {
		return
	}
	dir := server.DirFromVec(targ.Pos().Sub(obj.Pos()))
	obj.setAllDirs(dir)
}

func (obj nsObj) CanSee(obj2 ns.Obj) bool {
	if obj.Object == nil || obj2 == nil {
		return false
	}
	p1 := obj.Pos()
	p2 := obj2.Pos()
	if abs(p1.X-p2.X) > 512.0 || abs(p1.Y-p2.Y) > 512.0 {
		return false
	}
	return nox_xxx_unitCanInteractWith_5370E0(obj, obj2.(noxObject), 0)
}

func (obj nsObj) PushTo(p script.Positioner, force float32) {
	if p == nil {
		return
	}
	vec := obj.Pos().Sub(p.Pos()).Normalize()
	obj.ApplyForce(vec.Mul(force))
}

func (obj nsObj) Damage(source ns.Obj, amount int, typ damage.Type) {
	if amount <= 0 {
		return
	}
	var src *Object
	if source != nil {
		src = source.(nsObj).Object
	}
	owner := src.FindOwnerChainPlayer()
	obj.callDamage(owner, src, amount, int(typ))
}

func (obj nsObj) DeleteAfter(dt script.Duration) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) Idle() {
	obj.AsUnit().Idle()
}

func (obj nsObj) Wander() {
	obj.AsUnit().Wander()
}

func (obj nsObj) Hunt() {
	obj.AsUnit().Hunt()
}

func (obj nsObj) Return() {
	obj.AsUnit().Return()
}

func (obj nsObj) Follow(targ script.Positioner) {
	if targ == nil {
		return
	}
	obj.AsUnit().Follow(targ)
}

func (obj nsObj) Guard(p1, p2 types.Pointf, distance float32) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) Attack(target script.Positioner) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) IsAttackedBy(obj2 ns.Obj) bool {
	if obj2 == nil {
		return false
	}
	return obj.isEnemyTo(obj2.(noxObject))
}

func (obj nsObj) HitMelee(p types.Pointf) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) HitRanged(p types.Pointf) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) Flee(target script.Positioner, dt script.Duration) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) HasItem(item ns.Obj) bool {
	if item == nil {
		return false
	}
	return obj.Object.HasItem(item.(noxObject).AsObject())
}

func (obj nsObj) GetLastItem() ns.Obj {
	it := obj.FirstItem()
	if it == nil {
		return nil
	}
	return nsObj{it}
}

func (obj nsObj) GetPreviousItem() ns.Obj {
	it := obj.NextItem()
	if it == nil {
		return nil
	}
	return nsObj{it}
}

func (obj nsObj) GetHolder() ns.Obj {
	obj2 := obj.InventoryHolder()
	if obj2 == nil {
		return nil
	}
	return nsObj{obj2}
}

func (obj nsObj) Pickup(item ns.Obj) bool {
	if item == nil {
		return false
	}
	s := obj.getServer()
	it := item.(noxObject).AsObject()
	gold := s.ObjectTypeID("Gold")
	goldPile := s.ObjectTypeID("QuestGoldPile")
	goldChest := s.ObjectTypeID("QuestGoldChest")
	isPlayerInCoop := noxflags.HasGame(noxflags.GameModeCoop) && obj.Class().Has(object.ClassPlayer)
	if isPlayerInCoop {
		if f := s.Frame(); *memmap.PtrUint32(0x5D4594, 2386844) != f {
			*memmap.PtrUint32(0x5D4594, 2386844) = f
			C.dword_5d4594_2386848 = 0
			C.dword_5d4594_2386852 = 0
		}
		if typ := int(it.TypeInd); typ != gold && typ != goldPile && typ != goldChest {
			C.nox_xxx_playerCanCarryItem_513B00(obj.CObj(), it.CObj())
		}
	}
	if C.nox_xxx_inventoryServPlace_4F36F0(obj.CObj(), it.CObj(), 1, 1) == 0 {
		return false
	}
	if isPlayerInCoop && int(it.TypeInd) != gold {
		C.dword_5d4594_2386848 += 1
	}
	return true
}

func (obj nsObj) Drop(item ns.Obj) bool {
	if item == nil {
		return false
	}
	return obj.forceDrop(item.(noxObject).AsObject()) != 0
}

func (obj nsObj) ZombieStayDown() {
	if obj.Class().Has(object.ClassMonster) {
		obj.AsUnit().UpdateDataMonster().Field360 |= 0x100000
	}
}

func (obj nsObj) RaiseZombie() {
	C.sub_516D00(obj.CObj())
}

func (obj nsObj) Chat(message ns.StringID) {
	obj.ChatTimer(message, script.Frames(0))
}

func (obj nsObj) ChatTimer(message ns.StringID, dt script.Duration) {
	s := obj.getServer()
	v, _ := s.Strings().GetVariantInFile(strman.ID(message), "CScrFunc.c")
	C.nox_xxx_netSendChat_528AC0(obj.CObj(), internWStr(v.Str), C.ushort(s.AsFrames(dt)))
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.nox_xxx_playDialogFile_44D900(internCStr(v.Str2), 100)
	}
}

func (obj nsObj) DestroyChat() {
	nox_xxx_netKillChat_528D00(obj.AsUnit())
}

func (obj nsObj) CreateMover(wp ns.WaypointObj, speed float32) ns.Obj {
	s := obj.getServer()
	mv := s.newObjectByTypeID("Mover")
	if mv == nil {
		return nil
	}
	s.createObjectAt(mv, nil, obj.Pos())
	mv.VelVec = types.Pointf{}

	ud := mv.updateDataMover()
	ud.field_7 = obj.CObj()
	ud.field_2 = C.int32_t(wp.ScriptID())
	ud.field_1 = C.float(speed)
	ud.field_0 = 0

	mv.Enable(true)
	s.Objs.AddToUpdatable(mv.SObj())
	return nsObj{mv}
}

func (obj nsObj) GetElevatorStatus() int {
	if !obj.Class().Has(object.ClassElevator) {
		return -1
	}
	return int(obj.updateDataElevator().field_3)
}

func (obj nsObj) AggressionLevel(level float32) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) SetRoamFlag(flags int) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) RetreatLevel(percent float32) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) ResumeLevel(percent float32) {
	//TODO implement me
	panic("implement me")
}

func (obj nsObj) OnEvent(event ns.ObjectEvent, fnc ns.Func) {
	//TODO implement me
	panic("implement me")
}

type nsObjGroup struct {
	s *Server
	g *mapGroup
}

func (g nsObjGroup) ScriptID() int {
	return int(g.g.Ind())
}

func (g nsObjGroup) Enable(enable bool) {
	g.EachObject(true, func(obj ns.Obj) bool {
		obj.Enable(enable)
		return true
	})
}

func (g nsObjGroup) Toggle() bool {
	one := false
	g.EachObject(true, func(obj ns.Obj) bool {
		if obj.Toggle() {
			one = true
		}
		return true
	})
	return one
}

func (g nsObjGroup) HasOwner(owner ns.Obj) bool {
	ok := true
	g.EachObject(false, func(obj ns.Obj) bool {
		ok = obj.HasOwner(owner)
		return ok
	})
	return ok
}

func (g nsObjGroup) HasOwnerIn(owners ns.ObjGroup) bool {
	// TODO: not exactly sure if the logic was like this
	ok := true
	g.EachObject(false, func(obj ns.Obj) bool {
		ok = obj.HasOwnerIn(owners)
		return ok
	})
	return ok
}

func (g nsObjGroup) SetOwner(owner ns.Obj) {
	g.EachObject(false, func(obj ns.Obj) bool {
		obj.SetOwner(owner)
		return true
	})
}

func (g nsObjGroup) SetOwners(owners ns.ObjGroup) {
	g.EachObject(false, func(obj ns.Obj) bool {
		obj.SetOwners(owners)
		return true
	})
}

func (g nsObjGroup) Pause(dt script.Duration) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) Move(wp ns.WaypointObj) {
	if wp == nil {
		return
	}
	g.EachObject(false, func(obj ns.Obj) bool {
		obj.Move(wp)
		return true
	})
}

func (g nsObjGroup) WalkTo(p types.Pointf) {
	g.EachObject(false, func(obj ns.Obj) bool {
		obj.WalkTo(p)
		return true
	})
}

func (g nsObjGroup) LookAtDirection(dir ns.Direction) {
	g.EachObject(false, func(obj ns.Obj) bool {
		obj.LookAtDirection(dir)
		return true
	})
}

func (g nsObjGroup) Damage(source ns.Obj, amount int, typ damage.Type) {
	g.EachObject(true, func(obj ns.Obj) bool {
		obj.Damage(source, amount, typ)
		return true
	})
}

func (g nsObjGroup) Delete() {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) Idle() {
	g.EachObject(true, func(obj ns.Obj) bool {
		obj.Idle()
		return true
	})
}

func (g nsObjGroup) Wander() {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) Hunt() {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) Follow(targ script.Positioner) {
	if targ == nil {
		return
	}
	g.EachObject(true, func(obj ns.Obj) bool {
		obj.Follow(targ)
		return true
	})
}

func (g nsObjGroup) Guard(p1, p2 types.Pointf, distance float32) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) Flee(target script.Positioner, dt script.Duration) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) HitMelee(p types.Pointf) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) HitRanged(p types.Pointf) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) Attack(target script.Positioner) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) ZombieStayDown() {
	g.EachObject(true, func(obj ns.Obj) bool {
		obj.ZombieStayDown()
		return true
	})
}

func (g nsObjGroup) RaiseZombie() {
	g.EachObject(true, func(obj ns.Obj) bool {
		obj.RaiseZombie()
		return true
	})
}

func (g nsObjGroup) CreateMover(wp ns.WaypointObj, speed float32) {
	g.EachObject(true, func(obj ns.Obj) bool {
		obj.CreateMover(wp, speed)
		return true
	})
}

func (g nsObjGroup) AggressionLevel(group ns.ObjGroup, level float32) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) SetRoamFlag(flags int) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) RetreatLevel(percent float32) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) ResumeLevel(percent float32) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) Enchant(enchant enchant.Enchant, dt script.Duration) {
	if _, ok := server.ParseEnchant(string(enchant)); !ok {
		return
	}
	g.EachObject(true, func(obj ns.Obj) bool {
		obj.Enchant(enchant, dt)
		return true
	})
}

func (g nsObjGroup) EachObject(recursive bool, fnc func(obj ns.Obj) bool) {
	if recursive {
		g.g.eachObjectRecursiveNS(g.s, fnc)
	} else {
		g.g.eachObjectNS(g.s, fnc)
	}
}
