package opennox

import (
	"encoding/binary"
	"fmt"
	"math"
	"unsafe"

	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func asObject(p unsafe.Pointer) *Object {
	return (*Object)(p)
}
func asObjectS(p *server.Object) *Object {
	return (*Object)(unsafe.Pointer(p))
}

func nox_xxx_monsterClearActionStack_50A3A0(u *server.Object) {
	asObjectS(u).clearActionStack()
}

func (s *Server) GetObjects() []*Object {
	var out []*Object
	for p := s.FirstServerObject(); p != nil; p = p.Next() {
		out = append(out, asObjectS(p))
	}
	return out
}

func (s *Server) GetObjectsUpdatable2() []*Object {
	var out []*Object
	for p := asObjectS(s.Objs.UpdatableList2); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func (s *Server) GetObjectByID(id string) *Object {
	return asObjectS(s.Server.GetObjectByID(id))
}

func (s *Server) GetObjectByInd(ind int) *Object { // aka nox_xxx_netGetUnitByExtent_4ED020
	return asObjectS(s.Server.GetObjectByInd(ind))
}

func (s *Server) getObjectGroupByID(id string) *script.ObjectGroup {
	g := s.GroupByID(id, server.MapGroupObjects)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Object
	for it := g.First(); it != nil; it = it.Next() {
		if wl := s.GetObjectByInd(it.Data1()); wl != nil {
			list = append(list, wl)
		}
	}
	return script.NewObjectGroup(id, list...)
}

func (s *Server) getObjectFromNetCode(code int) *Object { // nox_server_getObjectFromNetCode_4ECCB0
	return asObjectS(legacy.Nox_server_getObjectFromNetCode_4ECCB0(code))
}

func (s *Server) DelayedDelete(obj *server.Object) {
	if obj == nil || obj.Flags().Has(object.FlagDestroyed) {
		return
	}
	if owner := asObjectS(obj).OwnerC(); owner != nil && owner.Class().Has(object.ClassPlayer) {
		if obj.Class().Has(object.ClassMonster) && legacy.Nox_xxx_creatureIsMonitored_500CC0(owner.SObj(), obj.SObj()) == 0 && (obj.SubClass()&0x80 != 0) {
			legacy.Nox_xxx_monsterRemoveMonitors_4E7B60(owner.SObj(), obj)
		}
	}

	if v := asObjectS(obj).InventoryHolder(); v != nil {
		legacy.Sub_4ED0C0(v.SObj(), obj.SObj())
	}
	legacy.Nox_xxx_playerCancelSpells_4FEAE0(obj)
	if noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().Has(object.ClassMonster) {
		legacy.Sub_50E210(obj)
	}
	if obj.Class().Has(object.ClassPlayer) {
		legacy.Sub_506740(obj)
	}
	obj.ObjFlags |= uint32(object.FlagDestroyed)
	obj.DeletedNext = s.Objs.DeletedList.SObj()
	s.Objs.DeletedList = obj.SObj()
	obj.DeletedAt = s.Frame()
	if obj.HasTeam() {
		legacy.Nox_xxx_netChangeTeamMb_419570(obj.TeamPtr(), obj.NetCode)
	}
}

func (s *Server) DeleteAfter(obj *server.Object, frames uint32) {
	legacy.Nox_xxx_unitSetDecayTime_511660(obj, int(frames))
}

func (s *Server) FinalizeDeletingObjects() {
	var next *Object
	for it := asObjectS(s.Objs.DeletedList); it != nil; it = next {
		next = asObjectS(it.DeletedNext)
		s.objectDeleteFinish(it)
	}
	s.Objs.DeletedList = nil
}

func (s *Server) objectDeleteFinish(obj *Object) {
	legacy.Nox_xxx_unitTransferSlaves_4EC4B0(obj.SObj())
	obj.SetOwner(nil)
	s.Activators.ClearOnObject(obj.SObj())
	legacy.Nox_xxx_decay_5116F0(obj.SObj())
	obj.dropAllItems()
	s.ObjectDeleteLast(obj.SObj())
	s.Objs.FreeObject(obj.SObj())
}

func (s *Server) ObjectDeleteLast(obj *server.Object) {
	if !obj.Flags().Has(object.FlagActive) {
		return
	}
	obj.ObjFlags &^= uint32(object.FlagActive)
	s.nox_xxx_playerLeaveObsByObserved_4E60A0(obj)
	if !noxflags.HasGame(noxflags.GameFlag20) {
		legacy.Nox_xxx_netReportDestroyObject_5289D0(obj)
	}
	legacy.Nox_xxx_unit_511810(obj)
	asObjectS(obj).SetOwner(nil)
	legacy.Nox_xxx_unitRemoveChild_4EC470(obj)
	legacy.Sub_517870(obj)
	s.sub_4DAE50(obj)
	legacy.Sub_4ECFA0(obj)
	legacy.Sub_511DE0(obj)
	if obj.Class().HasAny(object.MaskUnits) {
		legacy.Sub_528990(obj)
	}
}

func (s *Server) deletedObjectsUpdate() {
	var (
		list *Object
		next *Object
	)
	for it := asObjectS(s.Objs.DeletedList); it != nil; it = next {
		next = asObjectS(it.DeletedNext)
		if it.DeletedAt == s.Frame() {
			it.DeletedNext = list.SObj()
			list = it
			s.Objs.RemoveFromUpdatable(it.SObj())
		} else {
			s.objectDeleteFinish(it)
		}
	}
	s.Objs.DeletedList = list.SObj()
}

func (s *Server) ObjectsAddPending() {
	var next *Object
	for it := asObjectS(s.Objs.Pending); it != nil; it = next {
		next = it.Next()
		for it2 := it.OwnerC(); it2 != nil; it2 = it.OwnerC() {
			if !it.Flags().Has(object.FlagDestroyed) {
				break
			}
			it.SetOwner(it2.Owner())
		}
		if it.Class().Has(object.ClassMissile) {
			it.ObjNext = s.Objs.UpdatableList2.SObj()
			it.ObjPrev = nil
			if s.Objs.UpdatableList2 != nil {
				s.Objs.UpdatableList2.ObjPrev = it.SObj()
			}
			s.Objs.UpdatableList2 = it.SObj()
		} else {
			if it.Flags().Has(object.FlagShadow) {
				it.ObjFlags &^= uint32(object.FlagShadow)
				legacy.Nox_xxx_unitNewAddShadow_4DA9A0(it.SObj())
			}
			if it.Flags().Has(object.FlagRespawn) && !noxflags.HasGame(noxflags.GameModeQuest) {
				legacy.Nox_xxx_respawnAdd_4EC5E0(it.SObj())
			}
			if it.Update.Get() != nil || it.Vel() != (types.Pointf{}) { // TODO: had a weird check: ... && *(*uint8)(&it.obj_class) >= 0
				s.Objs.AddToUpdatable(it.SObj())
			}
			it.ObjNext = s.Objs.List.SObj()
			it.ObjPrev = nil
			if s.Objs.List != nil {
				s.Objs.List.ObjPrev = it.SObj()
			}
			s.Objs.List = it.SObj()
		}
		s.Map.AddMissileXxx(it.SObj())
		if it.Collide.Get() != nil {
			legacy.Sub_5117F0(it.SObj())
		}
		if fnc := it.Init.Get(); fnc != nil {
			fnc(it.SObj())
		}
		var v6 bool
		if it.Class().Has(object.ClassImmobile) {
			if it.SubClass()&0x18 != 0 {
				v6 = false
			} else {
				v6 = (^it.SubClass() >> 7) != 0
			}
		} else {
			v6 = ((uint32(it.Class()) >> 29) & 1) != 0
		}
		if it.Class().Has(object.ClassVisibleEnable) || !v6 {
			it.NeedSync()
			if !it.Class().HasAny(object.ClassClientPersist | object.ClassImmobile) {
				it.Field37 = 0
			}
		} else {
			it.makeUnseen()
			legacy.Sub_527E00(it.SObj())
			it.Field37 = math.MaxUint32
		}
		it.ObjFlags &^= uint32(object.FlagPending)
	}
	s.Objs.Pending = nil
	for _, fnc := range s.Objs.PendingActions {
		fnc()
	}
	s.Objs.PendingActions = nil
}

func (s *Server) sub_4DAE50(obj *server.Object) {
	legacy.Nox_xxx_action_4DA9F0(obj.SObj())
	if obj.Class().Has(object.ClassMissile) {
		prev := asObjectS(obj.ObjPrev)
		if prev != nil {
			prev.ObjNext = obj.ObjNext
		} else {
			s.Objs.UpdatableList2 = obj.ObjNext
		}
		if next := obj.ObjNext; next != nil {
			next.ObjPrev = prev.SObj()
		}
	} else {
		s.Objs.RemoveFromUpdatable(obj.SObj())
		prev := asObjectS(obj.ObjPrev)
		if prev != nil {
			prev.ObjNext = obj.ObjNext
		} else {
			s.Objs.List = obj.ObjNext
		}
		if next := obj.ObjNext; next != nil {
			next.ObjPrev = prev.SObj()
		}
	}
}

func (s *Server) attachPending() {
	for it := asObjectS(s.Objs.Pending); it != nil; it = it.Next() {
		if it.Class().Has(object.ClassElevator) {
			ud := it.UpdateData
			// find elevator shaft and attach them to each other
			for it2 := asObjectS(s.Objs.Pending); it2 != nil; it2 = it2.Next() {
				if it2.Class().Has(object.ClassElevatorShaft) {
					ud2 := it2.UpdateData
					if *(*uint32)(unsafe.Add(ud, 8)) == it2.Extent {
						*(**server.Object)(unsafe.Add(ud, 4)) = it2.SObj()
						*(**server.Object)(unsafe.Add(ud2, 4)) = it.SObj()
						break
					}
				}
			}
		}
		if it.Class().Has(object.ClassTransporter) {
			ud := it.UpdateData
			*(**server.Object)(unsafe.Add(ud, 12)) = nil
			// if transporter target is set - attach to it
			if ext := *(*uint32)(unsafe.Add(ud, 16)); ext != 0 {
				for it2 := asObjectS(s.Objs.Pending); it2 != nil; it2 = it2.Next() {
					if it2.Class().Has(object.ClassTransporter) && ext == it2.Extent {
						*(**server.Object)(unsafe.Add(ud, 12)) = it2.SObj()
						break
					}
				}
			}
		}
	}
}

func (s *Server) CreateObjectAt(a11 server.Obj, owner server.Obj, pos types.Pointf) {
	obj := toObject(a11)
	if obj.Flags().HasAny(object.FlagActive | object.FlagDestroyed) {
		return
	}
	obj.ObjFlags &= 0x35E9FEDB
	obj.PrevPos = pos
	obj.PosVec = pos
	obj.NewPos = pos
	obj.Pos39 = pos
	obj.SObj().Nox_xxx_objectUnkUpdateCoords_4E7290()
	if obj.Class().HasAny(object.MaskUnits) {
		legacy.Nox_xxx_unitPostCreateNotify_4E7F10(obj.SObj())
	}
	if owner != nil {
		obj.SetOwner(toObject(owner))
	}
	obj.VelVec = types.Pointf{}
	obj.ForceVec = types.Pointf{}
	obj.ObjFlags |= uint32(object.FlagActive)
	obj.Field32 = s.Frame()
	obj.Field34 = s.Frame()
	if noxflags.HasGame(noxflags.GameOnline) && !noxflags.HasGame(noxflags.GameModeQuest) && !obj.Class().Has(object.ClassMissile) &&
		(int(obj.TypeInd) == s.Types.GoldID() ||
			obj.Class().HasAny(object.ClassFood|object.ClassInfoBook|object.ClassWand|object.ClassWeapon|object.ClassArmor)) {
		obj.ObjFlags |= uint32(object.FlagNoCollide)
	}
	obj.ObjNext = s.Objs.Pending.SObj()
	obj.ObjPrev = nil
	if s.Objs.Pending != nil {
		s.Objs.Pending.ObjPrev = obj.SObj()
	}
	s.Objs.Pending = obj.SObj()
	obj.ObjFlags |= uint32(object.FlagPending)
	if obj.TeamVal.ID != 0 && (!obj.Class().Has(object.ClassFlag) || memmap.Int32(0x973F18, 3800) >= 0) {
		if noxflags.HasGame(noxflags.GameModeCoop) || noxflags.HasGamePlay(4) {
			legacy.Nox_xxx_createAtImpl_4191D0(obj.TeamVal.ID, obj.TeamPtr(), 0, obj.NetCode, 0)
		}
	}
}

func (s *Server) deleteAllObjectsOfType(t *server.ObjectType) {
	var next *server.Object
	for it := s.FirstServerObject(); it != nil; it = next {
		next = it.Next()
		var next2 *server.Object
		for it2 := it.FirstItem(); it2 != nil; it2 = next2 {
			next2 = it2.NextItem()
			if int(it2.TypeInd) == t.Ind() {
				asObjectS(it2).Delete()
			}
		}
		if int(it.TypeInd) == t.Ind() {
			asObjectS(it).Delete()
		}
	}
}

func toObjectS(obj server.Obj) *server.Object {
	if obj == nil {
		return nil
	}
	return obj.SObj()
}

func toObject(obj server.Obj) *Object {
	if obj == nil {
		return nil
	}
	return asObjectS(obj.SObj())
}

var _ = [1]struct{}{}[776-unsafe.Sizeof(Object{})]

type Object server.Object

func (obj *Object) getServer() *Server {
	return noxServer // TODO: attach to object
}

func (obj *Object) Server() *server.Server {
	return obj.SObj().Server()
}

func (obj *Object) UniqueKey() uintptr {
	return uintptr(unsafe.Pointer(obj))
}

func (obj *Object) SObj() *server.Object {
	return (*server.Object)(obj)
}

func (obj *Object) field(dp uintptr) unsafe.Pointer {
	return unsafe.Add(unsafe.Pointer(obj), dp)
}

func (obj *Object) ID() string {
	return alloc.GoString((*byte)(obj.IDPtr))
}

func (obj *Object) Ind() int { // aka "extent"
	return int(obj.Extent)
}

func (obj *Object) ScriptID() int {
	return obj.SObj().ScriptID()
}

func (obj *Object) ObjScriptID() int {
	return obj.SObj().ObjScriptID()
}

func (obj *Object) stringAs(typ string) string {
	if obj == nil {
		return fmt.Sprintf("%s(<nil>)", typ)
	}
	var oid string
	if id := obj.ID(); id != "" {
		oid = fmt.Sprintf("%q", id)
	} else if ind := obj.Ind(); ind != 0 {
		oid = fmt.Sprintf("#%d", ind)
	}
	if obj.Class().Has(object.ClassPlayer) {
		// TODO: better way
		for _, p := range obj.getServer().GetPlayers() {
			if u := p.UnitC(); u != nil && u.SObj() == obj.SObj() {
				oid += fmt.Sprintf(",P:%q", p.Name())
			}
		}
	}
	if t := obj.ObjectTypeC(); t != nil {
		return fmt.Sprintf("%s(%s,T:%q)", typ, oid, t.ID())
	}
	return fmt.Sprintf("%s(%s)", typ, oid)
}

func (obj *Object) String() string {
	return obj.stringAs("Object")
}

func (obj *Object) GetObject() script.Object {
	if obj == nil {
		return nil
	}
	return obj
}

func (obj *Object) Class() object.Class {
	return obj.SObj().Class()
}

func (obj *Object) SubClass() object.SubClass {
	return obj.SObj().SubClass()
}

func (obj *Object) ArmorClass() object.ArmorClass {
	return obj.SObj().ArmorClass()
}

func (obj *Object) Flags() object.Flags {
	return obj.SObj().Flags()
}

func (obj *Object) SetFlags(v object.Flags) {
	obj.SObj().SetFlags(v)
}

func (obj *Object) FlagsEnable(v object.Flags) {
	obj.SObj().FlagsEnable(v)
}

func (obj *Object) FlagsDisable(v object.Flags) {
	obj.SObj().FlagsDisable(v)
}

func (obj *Object) Health() (cur, max int) {
	return obj.SObj().Health()
}

func (obj *Object) SetHealth(v int) {
	if obj == nil {
		return
	}
	if noxflags.HasGame(noxflags.GameSuddenDeath) {
		return
	}
	if v < 0 {
		v = 0
	}
	if _, max := obj.Health(); v > max {
		v = max
	}
	// TODO: if 0, trigger death
	legacy.Nox_xxx_unitSetHP_4E4560(obj.SObj(), uint16(v))
	if obj.Class().Has(object.ClassMonster) {
		legacy.Nox_xxx_mobInformOwnerHP_4EE4C0(obj.SObj())
	}
}

func (obj *Object) SetMaxHealth(v int) {
	if obj == nil {
		return
	}
	if noxflags.HasGame(noxflags.GameSuddenDeath) {
		return
	}
	if v < 0 {
		v = 0
	}
	h := obj.HealthData
	if h == nil {
		return
	}
	// TODO: verify it works in MP
	// TODO: if it's the player, we need to adjust GUI health bars
	h.Max = uint16(v)
	obj.SetHealth(v)
}

func (obj *Object) Mana() (cur, max int) {
	return obj.SObj().Mana()
}

func (obj *Object) SetMana(v int) {
	if obj == nil {
		return
	}
	if v < 0 {
		v = 0
	}
	p := obj.UpdateDataPlayer()
	if p == nil {
		return
	}
	if _, max := obj.Mana(); v > max {
		v = max
	}
	cur := int(p.ManaCur)
	p.ManaPrev = uint16(cur)
	p.ManaCur = uint16(v)
	pt := asPlayerS(p.Player)
	legacy.Nox_xxx_protectMana_56F9E0(int(pt.ProtUnitManaCur), int16(v-cur))
}

func (obj *Object) SetMaxMana(v int) {
	if obj == nil {
		return
	}
	if v < 0 {
		v = 0
	}
	p := obj.UpdateDataPlayer()
	if p == nil {
		return
	}
	p.ManaMax = uint16(v)
	obj.SetMana(v)
}

func (obj *Object) CurrentSpeed() float32 {
	return obj.SObj().CurrentSpeed()
}

func (obj *Object) BaseSpeed() float32 {
	return obj.SObj().BaseSpeed()
}

func (obj *Object) SetBaseSpeed(v float32) {
	obj.SObj().SetBaseSpeed(v)
}

func (obj *Object) Strength() int {
	return obj.SObj().Strength()
}

func (obj *Object) SetStrength(v int) {
	obj.SObj().SetStrength(v)
}

func (obj *Object) IsMovable() bool {
	return obj.SObj().IsMovable()
}

func (obj *Object) FindByID(id string) *Object {
	return asObjectS(obj.SObj().FindByID(id))
}

func (obj *Object) NeedSync() { // nox_xxx_unitNeedSync_4E44F0
	obj.SObj().NeedSync()
}

func (obj *Object) makeUnseen() { // nox_xxx_objectMakeUnseenByNoone_4E44E0
	obj.Field38 = 0
}

func (obj *Object) Next() *Object { // nox_server_getNextObject_4DA7A0, nox_xxx_getNextUpdatable2Object_4DA850, nox_server_getNextObjectUninited_4DA880
	if obj == nil {
		return nil
	}
	return asObjectS(obj.SObj().Next())
}

func (obj *Object) FirstItem() *Object { // nox_xxx_inventoryGetFirst_4E7980
	return asObjectS(obj.InvFirstItem.SObj())
}

func (obj *Object) NextItem() *Object {
	return asObjectS(obj.InvNextItem.SObj())
}

func (obj *Object) InventoryHolder() *Object {
	return asObjectS(obj.InvHolder.SObj())
}

func (obj *Object) HasItem(item *Object) bool {
	return obj.SObj().HasItem(item.SObj())
}

func (obj *Object) updateDataMissile() *legacy.Nox_object_Missile_data_t {
	return (*legacy.Nox_object_Missile_data_t)(obj.UpdateData)
}

func (obj *Object) updateDataElevator() *legacy.Nox_object_Elevator_data_t {
	return (*legacy.Nox_object_Elevator_data_t)(obj.UpdateData)
}

func (obj *Object) updateDataMover() *legacy.Nox_object_Mover_data_t {
	return (*legacy.Nox_object_Mover_data_t)(obj.UpdateData)
}

func (obj *Object) Inventory() []*Object {
	var out []*Object
	for p := obj.FirstItem(); p != nil; p = p.NextItem() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) NextOwned512() *Object {
	return asObjectS(obj.SObj().NextOwned512())
}

func (obj *Object) FirstOwned516() *Object {
	return asObjectS(obj.SObj().FirstOwned516())
}

func (obj *Object) GetOwned516() []*Object {
	var out []*Object
	for p := obj.FirstOwned516(); p != nil; p = p.NextOwned512() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) HasEnchant(v server.EnchantID) bool { // nox_xxx_testUnitBuffs_4FF350
	return obj.SObj().HasEnchant(v)
}

func (obj *Object) EnchantDur(v server.EnchantID) int { // nox_xxx_unitGetBuffTimer_4FF550
	return obj.SObj().EnchantDur(v)
}

func (obj *Object) EnchantPower(v server.EnchantID) int { // nox_xxx_buffGetPower_4FF570
	return obj.SObj().EnchantPower(v)
}

func (obj *Object) ApplyEnchant(v server.EnchantID, dur, power int) { // nox_xxx_buffApplyTo_4FF380
	if obj == nil || v >= 32 {
		return
	}
	legacy.Nox_xxx_buffApplyTo_4FF380(obj.SObj(), v, dur, power)
}

func (obj *Object) DisableEnchant(v server.EnchantID) { // nox_xxx_spellBuffOff_4FF5B0
	if obj == nil || v >= 32 {
		return
	}
	legacy.Nox_xxx_spellBuffOff_4FF5B0(obj.SObj(), v)
}

func (obj *Object) ObjectTypeC() *server.ObjectType {
	if obj == nil {
		return nil
	}
	return obj.getServer().Types.ByInd(int(obj.TypeInd))
}

func (obj *Object) ObjectType() script.ObjectType {
	t := obj.ObjectTypeC()
	if t == nil {
		return nil
	}
	return noxScriptObjType{t}
}

func (obj *Object) TeamPtr() *server.ObjectTeam {
	if obj == nil {
		return nil
	}
	return obj.SObj().TeamPtr()
}

func (obj *Object) HasTeam() bool {
	if obj == nil {
		return false
	}
	return obj.SObj().HasTeam()
}

func (obj *Object) Team() *server.Team {
	if obj == nil {
		return nil
	}
	return obj.SObj().Team()
}

func (obj *Object) OwnerC() *Object {
	if obj == nil {
		return nil
	}
	return asObjectS(obj.ObjOwner)
}

func (obj *Object) Owner() script.Object {
	if obj == nil {
		return nil
	}
	p := obj.OwnerC()
	if p == nil {
		return nil
	}
	return p
}

func (obj *Object) SetOwner(owner script.ObjectWrapper) {
	if owner == nil {
		legacy.Nox_xxx_unitClearOwner_4EC300(obj.SObj())
		return
	}
	own := owner.GetObject().(server.Obj)
	legacy.Nox_xxx_unitSetOwner_4EC290(own.SObj(), obj.SObj())
}

func (obj *Object) Pos() types.Pointf {
	return obj.SObj().Pos()
}

func (obj *Object) Vel() types.Pointf {
	return obj.SObj().Vel()
}

func (obj *Object) Force() types.Pointf {
	return obj.SObj().Force()
}

func (obj *Object) Dir1() server.Dir16 {
	return obj.SObj().Dir1()
}

func (obj *Object) Dir2() server.Dir16 {
	return obj.SObj().Dir2()
}

func (obj *Object) Z() float32 {
	return obj.ZVal
}

func (obj *Object) curSpeed() float32 {
	if obj == nil {
		return 0
	}
	return obj.SpeedCur
}

func (obj *Object) setAllDirs(dir server.Dir16) {
	obj.Direction1 = dir
	obj.Direction2 = dir
}

func (obj *Object) move(cp *types.Pointf) {
	legacy.Nox_xxx_unitMove_4E7010(obj.SObj(), cp)
}

func (obj *Object) SetPos(p types.Pointf) {
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = p
	obj.move(cp)
}

// ApplyForce adds a new force vector to the object. If another force in effect, it will adds up.
func (obj *Object) ApplyForce(p types.Pointf) {
	obj.SObj().ApplyForce(p)
}

func (obj *Object) SetZ(z float32) {
	legacy.Nox_xxx_unitRaise_4E46F0(obj.SObj(), z)
}

func (obj *Object) Push(vec types.Pointf, force float32) {
	obj.SObj().Push(vec, force)
}

func (obj *Object) PushTo(p types.Pointf) {
	obj.SObj().PushTo(p)
}

func (obj *Object) IsEnabled() bool {
	return obj.SObj().IsEnabled()
}

// Toggle the object's enable state.
// The returning boolean represents the enabled state of the object before toggled.
func (obj *Object) Toggle() bool {
	if obj.IsEnabled() {
		legacy.Nox_xxx_objectSetOff_4E7600(obj.SObj())
		return true
	} else {
		legacy.Nox_xxx_objectSetOn_4E75B0(obj.SObj())
		return false
	}
}

func (obj *Object) Enable(enable bool) {
	if obj == nil {
		return
	}
	if enable {
		legacy.Nox_xxx_objectSetOn_4E75B0(obj.SObj())
	} else {
		legacy.Nox_xxx_objectSetOff_4E7600(obj.SObj())
	}
}

func (obj *Object) Delete() {
	obj.getServer().DelayedDelete(obj.SObj())
}

func (obj *Object) DeleteAfter(frames uint32) {
	obj.getServer().DeleteAfter(obj.SObj(), frames)
}

func (obj *Object) Destroy() {
	panic("implement me")
	obj.Delete()
}

func (obj *Object) UpdateDataPlayer() *server.PlayerUpdateData {
	return obj.SObj().UpdateDataPlayer()
}

func (obj *Object) UpdateDataMonster() *server.MonsterUpdateData {
	return obj.SObj().UpdateDataMonster()
}

func (obj *Object) ControllingPlayer() *Player {
	return asPlayerS(obj.SObj().ControllingPlayer())
}

func (obj *Object) CallUpdate() {
	obj.SObj().CallUpdate()
}

func (obj *Object) CallXfer(a2 unsafe.Pointer) error {
	return obj.SObj().CallXfer(a2)
}

func (obj *Object) CallDamage(who, a3 server.Obj, dmg int, typ object.DamageType) int {
	return obj.SObj().CallDamage(who, a3, dmg, typ)
}

func (obj *Object) CallCollide(obj2 *server.Object, pos *types.Pointf) {
	obj.SObj().CallCollide(obj2, pos)
}

func (obj *Object) CallDrop(it server.Obj, pos types.Pointf) int {
	return obj.SObj().CallDrop(it, pos)
}

func (obj *Object) forceDrop(item *Object) int { // nox_xxx_invForceDropItem_4ED930
	s := obj.getServer()
	pos := s.RandomReachablePointAround(50.0, obj.Pos())
	return obj.forceDropAt(item, pos)
}

func (obj *Object) forceDropAt(item *Object, pos types.Pointf) int { // nox_xxx_drop_4ED790
	return legacy.Nox_xxx_drop_4ED790(obj.SObj(), item.SObj(), pos)
}

func (obj *Object) CanSee(obj2 script.Object) bool {
	if obj == nil || obj2 == nil {
		return false
	}
	return obj.CanSeeS(toObject(obj2.(server.Obj)))
}

func (obj *Object) CanSeeS(obj2 *Object) bool {
	if obj == nil || obj2 == nil {
		return false
	}
	p1 := obj.Pos()
	p2 := obj2.Pos()
	if abs(p1.X-p2.X) > 512.0 || abs(p1.Y-p2.Y) > 512.0 {
		return false
	}
	return obj.getServer().CanInteract(obj.SObj(), obj2.SObj(), 0)
}

func (obj *Object) FindOwnerChainPlayer() *Object { // nox_xxx_findParentChainPlayer_4EC580
	return asObjectS(obj.SObj().FindOwnerChainPlayer())
}

func (obj *Object) HasOwner(owner *Object) bool {
	return obj.SObj().HasOwner(owner.SObj())
}

func (obj *Object) dropAllItems() {
	legacy.Nox_xxx_dropAllItems_4EDA40(obj.SObj())
}

func (obj *Object) MoveTo(p types.Pointf) {
	// TODO: originally, this method required Waypoint as an argument
	//       but now we actually have WalkTo and friends which accept both position or a waypoint (in LUA)
	//       so we will call WalkTo here for now, but that Waypoint requirement was probably done for a reason
	obj.WalkTo(p)
}

func (obj *Object) WalkTo(p types.Pointf) {
	legacy.Nox_xxx_monsterWalkTo_514110(obj.SObj(), p.X, p.Y)
}

func (obj *Object) SetDir(v server.Dir16) {
	obj.SObj().SetDir(v)
}

func (obj *Object) LookAt(p types.Pointf) {
	obj.SObj().LookAt(p)
}

func (obj *Object) LookAtDir(dir int) {
	legacy.Nox_xxx_monsterLookAt_5125A0(obj.SObj(), dir)
}

func (obj *Object) LookAngle(ang int) {
	v := nox_xxx_math_roundDir(int32(ang))
	obj.SetDir(server.Dir16(v))
}

func (obj *Object) Freeze(freeze bool) {
	if freeze {
		legacy.Nox_xxx_unitFreeze_4E79C0(obj.SObj(), 1)
	} else {
		legacy.Nox_xxx_unitUnFreeze_4E7A60(obj.SObj(), 1)
	}
}

func (obj *Object) Wander() {
	legacy.Nox_xxx_scriptMonsterRoam_512930(obj.SObj())
}

func (obj *Object) Return() {
	legacy.Nox_server_gotoHome(obj.SObj())
}

func (obj *Object) Idle() {
	legacy.Nox_xxx_unitIdle_515820(obj.SObj())
}

func (obj *Object) Follow(obj2 script.Positioner) {
	if v, ok := obj2.(script.ObjectWrapper); ok {
		obj2 = v.GetObject()
	}
	cobj := obj2.(server.Obj)
	legacy.Nox_xxx_unitSetFollow_5158C0(obj.SObj(), cobj.SObj())
}

func (obj *Object) Flee(obj2 script.Positioner, dur ns4.Duration) {
	panic("implement me")
}

func (obj *Object) Aggression() float32 {
	return obj.SObj().Aggression()
}

func (obj *Object) SetAggression(v float32) {
	obj.SObj().SetAggression(v)
}

func (obj *Object) RetreatLevel() float32 {
	return obj.SObj().RetreatLevel()
}

func (obj *Object) SetRetreatLevel(v float32) {
	obj.SObj().SetRetreatLevel(v)
}

func (obj *Object) RegroupLevel() float32 {
	return obj.SObj().RegroupLevel()
}

func (obj *Object) SetRegroupLevel(v float32) {
	obj.SObj().SetRegroupLevel(v)
}

func (obj *Object) Attack(obj2 script.Positioner) {
	panic("implement me")
}

func (obj *Object) HitMelee(p types.Pointf) {
	panic("implement me")
}

func (obj *Object) HitRanged(p types.Pointf) {
	panic("implement me")
}

func (obj *Object) Guard() {
	panic("implement me")
}

func (obj *Object) Hunt() {
	legacy.Nox_xxx_unitHunt_5157A0(obj.SObj())
}

func (obj *Object) Say(text string, dur ns4.Duration) {
	panic("implement me")
}

func (obj *Object) Mute() {
	panic("implement me")
}

func (obj *Object) AddGold(v int) {
	if v < 0 {
		legacy.Nox_xxx_playerSubGold_4FA5D0(obj.SObj(), v)
	} else {
		legacy.Nox_xxx_playerAddGold_4FA590(obj.SObj(), v)
	}
}

func (obj *Object) Cast(sp spell.ID, lvl int, targ script.Positioner) bool {
	if !sp.Valid() || lvl <= 0 {
		return false
	}
	var s *Server = obj.getServer()
	sa, freeArg := alloc.New(server.SpellAcceptArg{})
	defer freeArg()
	if targ == nil {
		targ = obj
	}
	if o, ok := targ.(server.Obj); ok {
		sa.Obj = toObjectS(o)
	}
	sa.Pos = targ.Pos()
	return s.castSpell(sp, lvl, obj.SObj(), sa)
}

func (obj *Object) clearActionStack() { // aka nox_xxx_monsterClearActionStack_50A3A0
	if obj.Class().Has(object.ClassMonster) {
		for !aiStackEmptyAndIdle(obj.SObj()) {
			obj.monsterPopAction()
		}
	}
}

func (obj *Object) monsterPushAction(act ai.ActionType, args ...any) *server.AIStackItem { // aka nox_xxx_monsterPushAction_50A260
	st := obj.monsterPushActionImpl(act, 1)
	st.SetArgs(args...)
	return st
}

func (obj *Object) monsterActionIsScheduled(act ai.ActionType) bool { // nox_xxx_monsterIsActionScheduled_50A090
	stack := obj.UpdateDataMonster().GetAIStack()
	for _, v := range stack {
		if v.Type() == act {
			return true
		}
	}
	return false
}

func (obj *Object) countSubOfType(typ int) int { // nox_xxx_unitIsUnitTT_4E7C80
	if obj == nil {
		return 0
	}
	cnt := 0
	for it := obj.FirstOwned516(); it != nil; it = it.NextOwned512() {
		if int(it.TypeInd) == typ && !it.Flags().Has(object.FlagDestroyed) {
			cnt++
		}
	}
	return cnt
}

func (obj *Object) SetTrapSpells(spells ...spell.ID) {
	setBomberSpells(obj.SObj(), spells...)
}

func nox_xxx_playerSetState_4FA020(u *Object, a2 int) {
	legacy.Nox_xxx_playerSetState_4FA020(u.SObj(), a2)
}

func nox_xxx_unitIsUnitTT_4E7C80(a1 *server.Object, a2 int) int {
	return asObjectS(a1).countSubOfType(a2)
}

func nox_xxx_scriptSetDialog_548C80(obj *server.Object, flags server.DialogFlags, start, end int) {
	if obj == nil {
		return
	}
	if !obj.Class().Has(object.ClassMonster) {
		return
	}
	ud := obj.UpdateDataMonster()
	if start == -1 || end == -1 {
		return
	}
	ud.DialogStartFunc = int32(start)
	ud.DialogEndFunc = int32(end)
	ud.DialogFlags = byte(flags)
	legacy.Nox_xxx_unitSetXStatus_4E4800(obj, 0x10)
}

func scriptCancelDialog(obj *server.Object) {
	if obj == nil {
		return
	}
	if !obj.Class().Has(object.ClassMonster) {
		return
	}
	ud := obj.UpdateDataMonster()
	ud.DialogStartFunc = -1
	ud.DialogEndFunc = -1
	legacy.Nox_xxx_unitUnsetXStatus_4E4780(obj, 0x10)
}

func nox_xxx_script_forcedialog_548CD0(obj, obj2 *server.Object) {
	legacy.Nox_xxx_script_forcedialog_548CD0(obj, obj2)
}

func sub_548F40(obj *server.Object) int {
	if obj == nil {
		return 0
	}
	if !obj.Class().Has(object.ClassMonster) {
		return 0
	}
	ud := obj.UpdateDataMonster()
	return int(ud.DialogResult)
}

func nox_xxx_startShopDialog_548DE0(player, npc *server.Object, snd sound.ID, str strman.ID) {
	if str == "" {
		return
	}
	if player == nil || !player.Class().Has(object.ClassPlayer) {
		return
	}
	if npc == nil || !npc.Class().Has(object.ClassMonster) {
		return
	}
	s := noxServer
	tud := npc.UpdateDataMonster()
	pud := player.UpdateDataPlayer()
	pud.DialogWith = npc

	buf, free := alloc.Make([]byte{}, 135)
	defer free()
	buf[0] = byte(noxnet.MSG_DIALOG)
	buf[1] = 3
	copy(buf[2:34], str)
	v7 := legacy.Sub_4E39F0_obj_db(npc)
	alloc.StrCopy16B(buf[34:96], v7)
	buf[96] = 0
	buf[97] = 0
	binary.LittleEndian.PutUint32(buf[98:], uint32(snd))
	if pname := tud.DialogPortrait(); pname != "" {
		copy(buf[102:134], pname)
	} else {
		copy(buf[102:134], "ShopKeeperPic")
	}
	buf[134] = tud.DialogFlags
	pl := player.ControllingPlayer()
	s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:135], 1)
	legacy.Nox_xxx_unitFreeze_4E79C0(player, 0)
}

func nox_xxx_mobSetFightTarg_515D30(obj, targ *server.Object) {
	legacy.Nox_xxx_mobSetFightTarg_515D30(obj, targ)
}

func nox_server_scriptFleeFrom_515F70(obj, targ *server.Object, df int) {
	legacy.Nox_server_scriptFleeFrom_515F70(obj, targ, df)
}

func nox_xxx_monsterGoPatrol_515680(obj *server.Object, p1, p2 types.Pointf, dist float32) {
	legacy.Nox_xxx_monsterGoPatrol_515680(obj, p1, p2, dist)
}

func sub_516090(obj *server.Object, df int) {
	legacy.Sub_516090(obj, df)
}

func sub_4E4500(obj *server.Object, val1 uint32, val2 uint32, set bool) {
	for i := 0; i < 32; i++ {
		if set {
			obj.Field140[i] |= val2
		} else {
			obj.Field140[i] &^= val2
		}
		if obj.Field37&uint32(1<<i) != 0 {
			obj.Field140[i] |= val1
		} else if obj.Field140[i]&val2 == 0 {
			obj.Field140[i] &^= val1
		}
	}
}
