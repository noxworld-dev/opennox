package opennox

import (
	"fmt"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

func asObject(p unsafe.Pointer) *Object {
	return (*Object)(p)
}
func asObjectS(p *server.Object) *Object {
	return (*Object)(unsafe.Pointer(p))
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
	if server.Nox_xxx_servObjectHasTeam_419130(obj.TeamPtr()) {
		legacy.Nox_xxx_netChangeTeamMb_419570(unsafe.Pointer(obj.TeamPtr()), obj.NetCode)
	}
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

func (s *Server) ObjectsNewAdd() {
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
			if it.Update != nil || it.Vel() != (types.Pointf{}) { // TODO: had a weird check: ... && *(*uint8)(&it.obj_class) >= 0
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
		if it.Collide != nil {
			legacy.Sub_5117F0(it.SObj())
		}
		if it.Init != nil {
			ccall.CallVoidPtr2(it.Init, it.SObj().CObj(), nil)
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
	if memmap.Uint32(0x5D4594, 1556864) == 0 {
		*memmap.PtrUint32(0x5D4594, 1556864) = uint32(s.ObjectTypeID("Gold"))
		*memmap.PtrUint32(0x5D4594, 1556868) = uint32(s.ObjectTypeID("QuestGoldPile"))
		*memmap.PtrUint32(0x5D4594, 1556872) = uint32(s.ObjectTypeID("QuestGoldChest"))
	}
	if obj.Flags().HasAny(object.FlagActive | object.FlagDestroyed) {
		return
	}
	obj.ObjFlags &= 0x35E9FEDB
	obj.PrevPos = pos
	obj.PosVec = pos
	obj.NewPos = pos
	obj.Pos39 = pos
	nox_xxx_objectUnkUpdateCoords_4E7290(obj)
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
		(int(obj.TypeInd) == int(memmap.Uint32(0x5D4594, 1556864)) ||
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
	if obj.Field13&0xff != 0 && (!obj.Class().Has(object.ClassFlag) || memmap.Int32(0x973F18, 3800) >= 0) {
		if noxflags.HasGame(noxflags.GameModeCoop) || noxflags.HasGamePlay(4) {
			legacy.Nox_xxx_createAtImpl_4191D0(uint8(obj.Field13), unsafe.Pointer(obj.TeamPtr()), 0, obj.NetCode, 0)
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

var _ = [1]struct{}{}[772-unsafe.Sizeof(Object{})]

type Object server.Object

func (obj *Object) getServer() *Server {
	return noxServer // TODO: attach to object
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

func (obj *Object) Health() (cur, max int) {
	return obj.SObj().Health()
}

func (obj *Object) IsMovable() bool {
	return obj.SObj().IsMovable()
}

func (obj *Object) team() byte {
	return obj.TeamPtr().Field1
}

func (obj *Object) Team() *server.Team {
	if obj == nil {
		return nil
	}
	return obj.getServer().Teams.ByYyy(obj.team())
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
	return asObjectS(obj.Field128)
}

func (obj *Object) FirstOwned516() *Object {
	return asObjectS(obj.Field129)
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

func (obj *Object) AsUnit() *Unit {
	if obj == nil {
		return nil
	}
	// TODO: check somehow
	return asUnit(unsafe.Pointer(obj))
}

func (obj *Object) ObjectTypeC() *server.ObjectType {
	if obj == nil {
		return nil
	}
	return obj.getServer().ObjectTypeByInd(int(obj.TypeInd))
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

func (obj *Object) SetPos(p types.Pointf) {
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = p
	legacy.Nox_xxx_unitMove_4E7010(obj.SObj(), cp)
}

// ApplyForce adds a new force vector to the object. If another force in effect, it will adds up.
func (obj *Object) ApplyForce(p types.Pointf) {
	obj.SObj().ApplyForce(p)
}

func (obj *Object) SetZ(z float32) {
	legacy.Nox_xxx_unitRaise_4E46F0(obj.SObj(), z)
}

func (obj *Object) Push(vec types.Pointf, force float32) {
	panic("implement me")
}

func (obj *Object) PushTo(p types.Pointf) {
	panic("implement me")
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

func (obj *Object) Destroy() {
	panic("implement me")
}

func (obj *Object) CallUpdate() {
	if obj.Update == nil {
		return
	}
	switch obj.Update {
	case unsafe.Pointer(legacy.Get_nox_xxx_updatePlayer_4F8100()):
		nox_xxx_updatePlayer_4F8100(obj.SObj())
	case unsafe.Pointer(legacy.Get_nox_xxx_updatePlayerObserver_4E62F0()):
		nox_xxx_updatePlayerObserver_4E62F0(obj.SObj())
	case unsafe.Pointer(legacy.Get_nox_xxx_updateHarpoon_54F380()):
		nox_xxx_updateHarpoon_54F380(obj.SObj())
	case unsafe.Pointer(legacy.Get_nox_xxx_updatePixie_53CD20()):
		nox_xxx_updatePixie_53CD20(obj.SObj())
	default:
		obj.SObj().CallUpdate()
	}
}

func (obj *Object) CallXfer(a2 unsafe.Pointer) error {
	switch obj.Xfer {
	case unsafe.Pointer(legacy.Get_nox_xxx_XFerDefault_4F49A0()):
		return nox_xxx_XFerDefault4F49A0(cryptfile.Global(), obj.SObj(), a2)
	}
	return obj.SObj().CallXfer(a2)
}

func (obj *Object) CallDamage(who, a3 server.Obj, dmg int, typ object.DamageType) int {
	return obj.SObj().CallDamage(who, a3, dmg, typ)
}

func (obj *Object) CallCollide(a2, a3 int) {
	obj.SObj().CallCollide(a2, a3)
}

func (obj *Object) CallDrop(it server.Obj, pos types.Pointf) int {
	if obj.Drop == nil {
		return 0
	}
	switch obj.Drop {
	case unsafe.Pointer(legacy.Get_nox_objectDropAudEvent_4EE2F0()):
		cpos, free := alloc.New(types.Pointf{})
		defer free()
		*cpos = pos
		return int(nox_objectDropAudEvent_4EE2F0(obj.SObj(), toObjectS(it), cpos))
	default:
		return obj.SObj().CallDrop(it, pos)
	}
}

func (obj *Object) forceDrop(item *Object) int { // nox_xxx_invForceDropItem_4ED930
	s := obj.getServer()
	pos := s.randomReachablePointAround(50.0, obj.Pos())
	return obj.forceDropAt(item, pos)
}

func (obj *Object) forceDropAt(item *Object, pos types.Pointf) int { // nox_xxx_drop_4ED790
	return legacy.Nox_xxx_drop_4ED790(obj.SObj(), item.SObj(), pos)
}

func (s *Server) IsEnemyTo(a1, a2 *server.Object) bool {
	return asObjectS(a1).isEnemyTo(asObjectS(a2))
}

func (obj *Object) isEnemyTo(objp server.Obj) bool { // nox_xxx_unitIsEnemyTo_5330C0
	obj2 := toObject(objp)
	if obj == nil || obj2 == nil {
		return false
	}
	if obj.SObj() == obj2.SObj() {
		return false
	}
	srv := obj.getServer()
	if obj2.Class().HasAny(object.ClassMonster) {
		if ud := obj2.AsUnit().UpdateDataMonster(); ud.Field360&0x40000 != 0 {
			return false
		}
	}
	if obj.Class().HasAny(object.ClassPlayer) && int(obj2.TypeInd) == srv.PolypID() {
		return true
	}
	if obj.Class().HasAny(object.ClassPlayer) && obj2.Class().HasAny(object.ClassMonsterGenerator) {
		return true
	}
	if obj.Class().HasAny(object.ClassMonster) && obj2.Class().HasAny(object.ClassMonsterGenerator) {
		return false
	}
	if obj.Class().HasAny(object.ClassPlayer) && obj2.Class().HasAny(object.ClassMonster) && (obj2.SubClass()&0x20 != 0) {
		return false
	}
	if obj.Class().HasAny(object.ClassMonster) && obj2.Class().HasAny(object.ClassPlayer) && (obj.SubClass()&0x20 != 0) {
		return false
	}
	if obj.isFish() || obj.isFrog() {
		return !obj2.isFish() && !obj2.isFrog()
	}
	if obj.isRat() {
		return !obj2.isRat()
	}
	if obj2.isFish() {
		return false
	}
	if obj2.Class().HasAny(2) && (obj2.SubClass()&0x8 != 0) {
		return false
	}
	if obj.Class().HasAny(2) && (obj.SubClass()&0x8 != 0) {
		return false
	}
	if obj.HasEnchant(server.ENCHANT_CHARMING) || obj2.HasEnchant(server.ENCHANT_CHARMING) {
		return false
	}
	if obj2.Class().HasAny(object.ClassPlayer) {
		if pl := obj2.AsUnit().ControllingPlayer(); pl.Field3680&0x1 != 0 {
			return false
		}
	}
	own1 := obj.FindOwnerChainPlayer()
	own2 := obj2.FindOwnerChainPlayer()
	if own1 == own2 {
		return false
	}
	if server.Nox_xxx_servCompareTeams_419150(own1.TeamPtr(), own2.TeamPtr()) {
		return false
	}
	if own1.Class().HasAny(object.ClassPlayer) && own2.Class().HasAny(object.ClassMonsterGenerator) {
		return true
	}
	if own1.Class().HasAny(object.ClassMonster) && own2.Class().HasAny(object.ClassMonsterGenerator) {
		return false
	}
	if !noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().HasAny(object.ClassMonster) && int(obj2.TypeInd) == srv.WillOWispID() {
		return nox_xxx_checkMobAction_50A0D0(obj2.AsUnit(), ai.ACTION_FIGHT)
	}
	if server.Nox_xxx_servObjectHasTeam_419130(own1.TeamPtr()) || server.Nox_xxx_servObjectHasTeam_419130(own2.TeamPtr()) {
		return true
	}
	if own1.Class().HasAny(object.ClassMonster) && own2.Class().HasAny(object.ClassMonster) {
		return false
	}
	return true
}

func (s *Server) IsFish(obj *server.Object) bool {
	return asObjectS(obj).isFish()
}

func (s *Server) IsRat(obj *server.Object) bool {
	return asObjectS(obj).isRat()
}

func (s *Server) IsFrog(obj *server.Object) bool {
	return asObjectS(obj).isFrog()
}

func (obj *Object) isFish() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	return int(obj.TypeInd) == srv.FishSmallID() || int(obj.TypeInd) == srv.FishBigID()
}

func (obj *Object) isRat() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	return int(obj.TypeInd) == srv.RatID()
}

func (obj *Object) isFrog() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	return int(obj.TypeInd) == srv.GreenFrogID()
}

func (obj *Object) isPlant() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	return int(obj.TypeInd) == srv.CarnivorousPlantID()
}

func (obj *Object) isMimic() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	return int(obj.TypeInd) == srv.MimicID()
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
