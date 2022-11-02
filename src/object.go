package opennox

/*
#include "defs.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
void nox_xxx_updateHarpoon_54F380(nox_object_t* a1);
int nox_objectDropAudEvent_4EE2F0(nox_object_t* a1, nox_object_t* a2, float2* a3);
static void nox_call_obj_update_go(void (*fnc)(nox_object_t*), nox_object_t* obj) { fnc(obj); }
static void nox_call_object_init(void (*fnc)(nox_object_t*, void*), nox_object_t* a1, void* a2) { fnc(a1, a2); }
static int nox_call_object_xfer(int (*fnc)(nox_object_t*, void*), nox_object_t* a1, void* a2) { return fnc(a1, a2); }
static int nox_call_object_drop(int (*fnc)(nox_object_t*, nox_object_t*, float2*), nox_object_t* a1, nox_object_t* a2, float2* a3) { return fnc(a1, a2, a3); }
static int nox_call_object_damage(int (*fnc)(nox_object_t*, nox_object_t*, nox_object_t*, int, int), nox_object_t* a1, nox_object_t* a2, nox_object_t* a3, int a4, int a5) { return fnc(a1, a2, a3, a4, a5); }
*/
import "C"
import (
	"fmt"
	"image"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/server"
)

//export nox_server_getFirstObject_4DA790
func nox_server_getFirstObject_4DA790() *nox_object_t {
	return noxServer.FirstServerObject().CObj()
}

//export nox_server_getFirstObjectUninited_4DA870
func nox_server_getFirstObjectUninited_4DA870() *nox_object_t {
	return noxServer.Objs.Pending.CObj()
}

//export nox_server_getNextObject_4DA7A0
func nox_server_getNextObject_4DA7A0(cobj *nox_object_t) *nox_object_t {
	return asObjectC(cobj).Next().CObj()
}

//export nox_server_getNextObjectUninited_4DA880
func nox_server_getNextObjectUninited_4DA880(cobj *nox_object_t) *nox_object_t {
	return asObjectC(cobj).Next().CObj()
}

//export nox_xxx_getNextUpdatable2Object_4DA850
func nox_xxx_getNextUpdatable2Object_4DA850(cobj *nox_object_t) *nox_object_t {
	return asObjectC(cobj).Next().CObj()
}

//export nox_get_and_zero_server_objects_4DA3C0
func nox_get_and_zero_server_objects_4DA3C0() *nox_object_t {
	l := noxServer.Objs.List
	noxServer.Objs.List = nil
	return l.CObj()
}

//export nox_set_server_objects_4DA3E0
func nox_set_server_objects_4DA3E0(list *nox_object_t) {
	noxServer.Objs.List = asObjectC(list)
}

//export nox_xxx_findParentChainPlayer_4EC580
func nox_xxx_findParentChainPlayer_4EC580(obj *nox_object_t) *nox_object_t {
	return asObjectC(obj).FindOwnerChainPlayer().CObj()
}

//export nox_xxx_unitHasThatParent_4EC4F0
func nox_xxx_unitHasThatParent_4EC4F0(obj, owner *nox_object_t) C.int {
	return C.int(bool2int(asObjectC(obj).HasOwner(asObjectC(owner))))
}

//export nox_xxx_unitIsEnemyTo_5330C0
func nox_xxx_unitIsEnemyTo_5330C0(a, b *nox_object_t) C.int {
	if asObjectC(a).isEnemyTo(asObjectC(b)) {
		return 1
	}
	return 0
}

//export nox_xxx_unitIsAFish_534B10
func nox_xxx_unitIsAFish_534B10(obj *nox_object_t) C.int {
	if asObjectC(obj).isFish() {
		return 1
	}
	return 0
}

//export nox_xxx_unitIsARat_534B60
func nox_xxx_unitIsARat_534B60(obj *nox_object_t) C.int {
	if asObjectC(obj).isRat() {
		return 1
	}
	return 0
}

//export nox_xxx_unitIsAFrog_534B90
func nox_xxx_unitIsAFrog_534B90(obj *nox_object_t) C.int {
	if asObjectC(obj).isFrog() {
		return 1
	}
	return 0
}

//export sub_548600
func sub_548600(a1 *nox_object_t, a2, a3 C.float) {
	asObjectC(a1).sub548600(types.Pointf{X: float32(a2), Y: float32(a3)})
}

//export nox_xxx_delayedDeleteObject_4E5CC0
func nox_xxx_delayedDeleteObject_4E5CC0(obj *nox_object_t) {
	asObjectC(obj).Delete()
}

//export nox_xxx_finalizeDeletingUnits_4E5EC0
func nox_xxx_finalizeDeletingUnits_4E5EC0() {
	noxServer.finalizeDeletingObjects()
}

//export nox_xxx_getFirstUpdatableObject_4DA8A0
func nox_xxx_getFirstUpdatableObject_4DA8A0() *nox_object_t {
	return noxServer.Objs.UpdatableList.CObj()
}

//export nox_xxx_getNextUpdatableObject_4DA8B0
func nox_xxx_getNextUpdatableObject_4DA8B0(obj *nox_object_t) *nox_object_t {
	if obj == nil {
		return nil
	}
	return obj.updatable_next
}

//export nox_xxx_unitAddToUpdatable_4DA8D0
func nox_xxx_unitAddToUpdatable_4DA8D0(cobj *nox_object_t) {
	noxServer.Objs.AddToUpdatable(asObjectC(cobj))
}

//export nox_xxx_unitRemoveFromUpdatable_4DA920
func nox_xxx_unitRemoveFromUpdatable_4DA920(cobj *nox_object_t) {
	noxServer.Objs.RemoveFromUpdatable(asObjectC(cobj))
}

//export nox_xxx_servFinalizeDelObject_4DADE0
func nox_xxx_servFinalizeDelObject_4DADE0(cobj *nox_object_t) {
	noxServer.objectDeleteLast(asObjectC(cobj))
}

//export nox_xxx_getFirstUpdatable2Object_4DA840
func nox_xxx_getFirstUpdatable2Object_4DA840() *nox_object_t {
	return noxServer.Objs.UpdatableList2.CObj()
}

//export nox_xxx_unitsNewAddToList_4DAC00
func nox_xxx_unitsNewAddToList_4DAC00() {
	noxServer.objectsNewAdd()
}

//export nox_xxx_unitClearPendingMB_4DB030
func nox_xxx_unitClearPendingMB_4DB030() {
	noxServer.ObjectsClearPending()
}

//export nox_xxx_createAt_4DAA50
func nox_xxx_createAt_4DAA50(cobj *nox_object_t, cowner *nox_object_t, x C.float, y C.float) {
	var owner noxObject
	if cowner != nil {
		owner = asObjectC(cowner)
	}
	noxServer.createObjectAt(asObjectC(cobj), owner, types.Pointf{X: float32(x), Y: float32(y)})
}

func asPointf(p unsafe.Pointer) types.Pointf {
	cp := (*C.float2)(p)
	return types.Pointf{
		X: float32(cp.field_0),
		Y: float32(cp.field_4),
	}
}
func asPoint(p unsafe.Pointer) image.Point {
	cp := (*C.nox_point)(p)
	return image.Point{
		X: int(cp.x),
		Y: int(cp.y),
	}
}
func asObject(p unsafe.Pointer) *Object {
	return (*Object)(p)
}
func asObjectC(p *C.nox_object_t) *Object {
	return asObject(unsafe.Pointer(p))
}
func asObjectS(p *server.Object) *Object {
	return (*Object)(unsafe.Pointer(p))
}

func (s *Server) FirstServerObject() *Object { // nox_server_getFirstObject_4DA790
	return s.Objs.List
}

func (s *Server) GetObjects() []*Object {
	var out []*Object
	for p := s.FirstServerObject(); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func (s *Server) GetObjectsUpdatable2() []*Object {
	var out []*Object
	for p := s.Objs.UpdatableList2; p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

type serverObjects struct {
	List           *Object
	Pending        *Object
	UpdatableList  *Object
	UpdatableList2 *Object
	DeletedList    *Object
}

func (s *serverObjects) AddToUpdatable(obj *Object) {
	if obj.IsUpdatable == 0 && !obj.Class().Has(object.ClassMissile) {
		obj.UpdatablePrev = nil
		obj.UpdatableNext = s.UpdatableList
		if s.UpdatableList != nil {
			s.UpdatableList.UpdatablePrev = obj
		}
		s.UpdatableList = obj
		obj.IsUpdatable = 1
		obj.Obj130 = nil
	}
}

func (s *serverObjects) RemoveFromUpdatable(obj *Object) {
	if obj.IsUpdatable == 0 {
		return
	}
	prev := obj.UpdatablePrev
	if prev != nil {
		prev.UpdatableNext = obj.UpdatableNext
	} else {
		s.UpdatableList = obj.UpdatableNext
	}
	if next := obj.UpdatableNext; next != nil {
		next.UpdatablePrev = prev
	}
	obj.IsUpdatable = 0
	obj.Obj130 = nil
}

func (s *Server) getObjectsUninited() []*Object {
	var out []*Object
	for p := s.Objs.Pending; p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func (s *Server) GetObjectByID(id string) *Object {
	for obj := s.Objs.List; obj != nil; obj = obj.Next() {
		if p := obj.findByID(id); p != nil {
			return p
		}
	}
	for obj := s.Objs.Pending; obj != nil; obj = obj.Next() {
		if p := obj.findByID(id); p != nil {
			return p
		}
	}
	return nil
}

func (s *Server) GetObjectByInd(ind int) *Object { // aka nox_xxx_netGetUnitByExtent_4ED020
	for p := s.FirstServerObject(); p != nil; p = p.Next() {
		if !p.Flags().Has(object.FlagDestroyed) && p.Ind() == ind {
			return p
		}
	}
	return nil
}

func (s *Server) getObjectGroupByID(id string) *script.ObjectGroup {
	g := getMapGroupByID(id, 0)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Object
	for wp := g.FirstItem(); wp != nil; wp = wp.Next() {
		ind := int(*(*int32)(wp.Payload()))
		if wl := s.GetObjectByInd(ind); wl != nil {
			list = append(list, wl)
		}
	}
	return script.NewObjectGroup(id, list...)
}

func (s *Server) getObjectFromNetCode(code int) *Object { // nox_server_getObjectFromNetCode_4ECCB0
	return asObjectC(C.nox_server_getObjectFromNetCode_4ECCB0(C.int(code)))
}

func (s *Server) delayedDelete(obj *Object) {
	if obj == nil || obj.Flags().Has(object.FlagDestroyed) {
		return
	}
	if owner := obj.OwnerC(); owner != nil && owner.Class().Has(object.ClassPlayer) {
		if obj.Class().Has(object.ClassMonster) && C.nox_xxx_creatureIsMonitored_500CC0(owner.CObj(), obj.CObj()) == 0 && (obj.SubClass()&0x80 != 0) {
			C.nox_xxx_monsterRemoveMonitors_4E7B60(owner.CObj(), obj.CObj())
		}
	}

	if v := obj.InventoryHolder(); v != nil {
		C.sub_4ED0C0(v.CObj(), obj.CObj())
	}
	C.nox_xxx_playerCancelSpells_4FEAE0(obj.CObj())
	if noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().Has(object.ClassMonster) {
		C.sub_50E210(obj.CObj())
	}
	if obj.Class().Has(object.ClassPlayer) {
		C.sub_506740(obj.CObj())
	}
	obj.SetFlags(obj.Flags() | object.FlagDestroyed)
	obj.DeletedNext = s.Objs.DeletedList
	s.Objs.DeletedList = obj
	obj.DeletedAt = s.Frame()
	if nox_xxx_servObjectHasTeam_419130(obj.teamPtr()) {
		C.nox_xxx_netChangeTeamMb_419570(unsafe.Pointer(obj.teamPtr()), C.int(obj.NetCode))
	}
}

func (s *Server) finalizeDeletingObjects() {
	var next *Object
	for it := s.Objs.DeletedList; it != nil; it = next {
		next = it.DeletedNext
		s.objectDeleteFinish(it)
	}
	s.Objs.DeletedList = nil
}

func (s *Server) objectDeleteFinish(obj *Object) {
	C.nox_xxx_unitTransferSlaves_4EC4B0(obj.CObj())
	obj.SetOwner(nil)
	s.noxScript.actClearObj(obj)
	C.nox_xxx_decay_5116F0(obj.CObj())
	obj.dropAllItems()
	s.objectDeleteLast(obj)
	C.nox_xxx_objectFreeMem_4E38A0(obj.CObj())
}

func (s *Server) objectDeleteLast(obj *Object) {
	if !obj.Flags().Has(object.FlagActive) {
		return
	}
	obj.ObjFlags &^= uint32(object.FlagActive)
	s.nox_xxx_playerLeaveObsByObserved_4E60A0(obj)
	if !noxflags.HasGame(noxflags.GameFlag20) {
		C.nox_xxx_netReportDestroyObject_5289D0(obj.CObj())
	}
	C.nox_xxx_unit_511810(obj.CObj())
	obj.SetOwner(nil)
	C.nox_xxx_unitRemoveChild_4EC470(obj.CObj())
	C.sub_517870(obj.CObj())
	s.sub_4DAE50(obj)
	C.sub_4ECFA0(obj.CObj())
	C.sub_511DE0(obj.CObj())
	if obj.Class().HasAny(object.MaskUnits) {
		C.sub_528990(obj.CObj())
	}
}

func (s *Server) deletedObjectsUpdate() {
	var (
		list *Object
		next *Object
	)
	for it := s.Objs.DeletedList; it != nil; it = next {
		next = it.DeletedNext
		if it.DeletedAt == s.Frame() {
			it.DeletedNext = list
			list = it
			s.Objs.RemoveFromUpdatable(it)
		} else {
			s.objectDeleteFinish(it)
		}
	}
	s.Objs.DeletedList = list
}

func (s *Server) objectsNewAdd() {
	var next *Object
	for it := s.Objs.Pending; it != nil; it = next {
		next = it.Next()
		for it2 := it.OwnerC(); it2 != nil; it2 = it.OwnerC() {
			if !it.Flags().Has(object.FlagDestroyed) {
				break
			}
			it.SetOwner(it2.Owner())
		}
		if it.Class().Has(object.ClassMissile) {
			it.ObjNext = s.Objs.UpdatableList2
			it.ObjPrev = nil
			if s.Objs.UpdatableList2 != nil {
				s.Objs.UpdatableList2.ObjPrev = it
			}
			s.Objs.UpdatableList2 = it
		} else {
			if it.Flags().Has(object.FlagShadow) {
				it.ObjFlags &^= uint32(object.FlagShadow)
				C.nox_xxx_unitNewAddShadow_4DA9A0(it.CObj())
			}
			if it.Flags().Has(object.FlagRespawn) && !noxflags.HasGame(noxflags.GameModeQuest) {
				C.nox_xxx_respawnAdd_4EC5E0(it.CObj())
			}
			if it.Update != nil || it.Vel() != (types.Pointf{}) { // TODO: had a weird check: ... && *(*uint8)(&it.obj_class) >= 0
				s.Objs.AddToUpdatable(it)
			}
			it.ObjNext = s.Objs.List
			it.ObjPrev = nil
			if s.Objs.List != nil {
				s.Objs.List.ObjPrev = it
			}
			s.Objs.List = it
		}
		C.nox_xxx_unitCreateMissileSmth_517640(it.CObj())
		if it.Collide != nil {
			C.sub_5117F0(it.CObj())
		}
		if it.Init != nil {
			C.nox_call_object_init((*[0]byte)(it.Init), it.CObj(), nil)
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
			it.needSync()
			if !it.Class().HasAny(object.ClassClientPersist | object.ClassImmobile) {
				it.Field37 = 0
			}
		} else {
			it.makeUnseen()
			C.sub_527E00(it.CObj())
			it.Field37 = -1
		}
		it.ObjFlags &^= uint32(object.FlagPending)
	}
	s.Objs.Pending = nil
}

func (s *Server) sub_4DAE50(obj *Object) {
	C.nox_xxx_action_4DA9F0(obj.CObj())
	if obj.Class().Has(object.ClassMissile) {
		prev := obj.ObjPrev
		if prev != nil {
			prev.ObjNext = obj.ObjNext
		} else {
			s.Objs.UpdatableList2 = obj.ObjNext
		}
		if next := obj.ObjNext; next != nil {
			next.ObjPrev = prev
		}
	} else {
		s.Objs.RemoveFromUpdatable(obj)
		prev := obj.ObjPrev
		if prev != nil {
			prev.ObjNext = obj.ObjNext
		} else {
			s.Objs.List = obj.ObjNext
		}
		if next := obj.ObjNext; next != nil {
			next.ObjPrev = prev
		}
	}
}

func (s *Server) ObjectsClearPending() {
	var next *Object
	for it := s.Objs.Pending; it != nil; it = next {
		next = it.Next()
		it.ObjFlags &^= uint32(object.FlagPending)
		if s.Objs.List != nil {
			s.Objs.List.ObjPrev = it
		}
		it.ObjNext = s.Objs.List
		it.ObjPrev = nil
		s.Objs.List = it
	}
	s.Objs.Pending = nil
}

func (s *Server) attachPending() {
	for it := s.Objs.Pending; it != nil; it = it.Next() {
		if it.Class().Has(object.ClassElevator) {
			ud := it.UpdateData
			// find elevator shaft and attach them to each other
			for it2 := s.Objs.Pending; it2 != nil; it2 = it2.Next() {
				if it2.Class().Has(object.ClassElevatorShaft) {
					ud2 := it2.UpdateData
					if *(*uint32)(unsafe.Add(ud, 8)) == it2.Extent {
						*(**nox_object_t)(unsafe.Add(ud, 4)) = it2.CObj()
						*(**nox_object_t)(unsafe.Add(ud2, 4)) = it.CObj()
						break
					}
				}
			}
		}
		if it.Class().Has(object.ClassTransporter) {
			ud := it.UpdateData
			*(**nox_object_t)(unsafe.Add(ud, 12)) = nil
			// if transporter target is set - attach to it
			if ext := *(*uint32)(unsafe.Add(ud, 16)); ext != 0 {
				for it2 := s.Objs.Pending; it2 != nil; it2 = it2.Next() {
					if it2.Class().Has(object.ClassTransporter) && ext == it2.Extent {
						*(**nox_object_t)(unsafe.Add(ud, 12)) = it2.CObj()
						break
					}
				}
			}
		}
	}
}

func (s *Server) createObjectAt(a11 noxObject, owner noxObject, pos types.Pointf) {
	obj := a11.AsObject()
	if memmap.Uint32(0x5D4594, 1556864) == 0 {
		*memmap.PtrUint32(0x5D4594, 1556864) = uint32(s.ObjectTypeID("Gold"))
		*memmap.PtrUint32(0x5D4594, 1556868) = uint32(s.ObjectTypeID("QuestGoldPile"))
		*memmap.PtrUint32(0x5D4594, 1556872) = uint32(s.ObjectTypeID("QuestGoldChest"))
	}
	if obj.Flags().HasAny(object.FlagActive | object.FlagDestroyed) {
		return
	}
	obj.SetFlags(obj.Flags() & 0x35E9FEDB)
	obj.PrevPos = pos
	obj.PosVec = pos
	obj.NewPos = pos
	obj.Pos39 = pos
	C.nox_xxx_objectUnkUpdateCoords_4E7290(obj.CObj())
	if obj.Class().HasAny(object.MaskUnits) {
		C.nox_xxx_unitPostCreateNotify_4E7F10(obj.CObj())
	}
	if owner != nil {
		obj.SetOwner(owner.AsObject())
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
	obj.ObjNext = s.Objs.Pending
	obj.ObjPrev = nil
	if s.Objs.Pending != nil {
		s.Objs.Pending.ObjPrev = obj
	}
	s.Objs.Pending = obj
	obj.ObjFlags |= uint32(object.FlagPending)
	if obj.Field13&0xff != 0 && (!obj.Class().Has(object.ClassFlag) || memmap.Int32(0x973F18, 3800) >= 0) {
		if noxflags.HasGame(noxflags.GameModeCoop) || checkGameplayFlags(4) {
			C.nox_xxx_createAtImpl_4191D0(C.uchar(obj.Field13), unsafe.Pointer(obj.teamPtr()), 0, C.int(obj.NetCode), 0)
		}
	}
}

func (s *Server) deleteAllObjectsOfType(t *server.ObjectType) {
	var next *Object
	for it := s.FirstServerObject(); it != nil; it = next {
		next = it.Next()
		var next2 *Object
		for it2 := it.FirstItem(); it2 != nil; it2 = next2 {
			next2 = it2.NextItem()
			if int(it2.TypeInd) == t.Ind() {
				it2.Delete()
			}
		}
		if int(it.TypeInd) == t.Ind() {
			it.Delete()
		}
	}
}

type nox_object_t = C.nox_object_t

func toCObj(obj noxObject) *nox_object_t {
	if obj == nil {
		return nil
	}
	return obj.CObj()
}

func toObject(obj noxObject) *Object {
	if obj == nil {
		return nil
	}
	return obj.AsObject()
}

type noxObject interface {
	CObj() *nox_object_t
	server.Obj
	AsObject() *Object
}

var _ = [1]struct{}{}[772-unsafe.Sizeof(Object{})]

type Object struct {
	IDPtr         unsafe.Pointer     // 0, 0
	TypeInd       uint16             // 1, 4
	Field1_2      uint16             // 1, 6
	ObjClass      uint32             // 2, 8
	ObjSubClass   uint32             // 3, 12
	ObjFlags      uint32             // 4, 16
	Field5        uint32             // 5, 20
	Material      uint16             // 6, 24
	Field6_2      uint16             // 6, 26
	Experience    float32            // 7, 28
	Worth         uint32             // 8, 32
	NetCode       uint32             // 9, 36
	Extent        uint32             // 10, 40
	ScriptID      int                // 11, 44
	Field12       uint32             // 12, 48
	Field13       uint32             // 13, 52, // TODO: first byte is team?
	PosVec        types.Pointf       // 14, 56
	NewPos        types.Pointf       // 16, 64
	PrevPos       types.Pointf       // 18, 72
	VelVec        types.Pointf       // 20, 80
	ForceVec      types.Pointf       // 22, 88
	Pos24         types.Pointf       // 24, 96, // TODO: something related to acceleration/direction
	ZVal          float32            // 26, 104
	Field27       uint32             // 27, 108
	Float28       float32            // 28, 112, // TODO: damping/drag?
	Field29       uint32             // 29, 116
	MassVal       float32            // 30, 120
	Direction1    uint16             // 31, 124
	Direction2    uint16             // 31, 126
	Field32       uint32             // 32, 128, TODO: some frame/timestamp
	Field33       uint32             // 33, 132
	Field34       uint32             // 34, 136, TODO: some frame/timestamp
	Field35       uint32             // 35, 140
	Field36       uint32             // 36, 144
	Field37       int                // 37, 148
	Field38       int                // 38, 152
	Pos39         types.Pointf       // 39, 156
	Field41       uint32             // 41, 164
	Field42       uint32             // 42, 168
	Shape         server.Shape       // 43, 172
	ZSize1        float32            // 56, 224
	ZSize2        float32            // 57, 228
	CollideP1     types.Pointf       // 58, 232
	CollideP2     types.Pointf       // 60, 240
	Field62       uint32             // 62, 248
	Field63       uint32             // 63, 252
	Field64       uint32             // 64, 256
	Field65       uint32             // 65, 260
	Field66       uint32             // 66, 264
	Field67       uint32             // 67, 268
	Field68       uint32             // 68, 272
	Field69       uint32             // 69, 276
	Field70       uint32             // 70, 280
	Field71       uint32             // 71, 284
	Field72       uint32             // 72, 288
	Field73       uint32             // 73, 292
	Field74       uint32             // 74, 296
	Field75       uint32             // 75, 300
	Field76       uint32             // 76, 304
	Field77       uint32             // 77, 308
	Field78       uint32             // 78, 312
	Field79       uint32             // 79, 316
	Field80       uint32             // 80, 320
	Field81       uint32             // 81, 324
	Field82       uint32             // 82, 328
	Field83       uint32             // 83, 332
	Field84       uint32             // 84, 336
	Buffs         uint32             // 85, 340
	BuffsDur      [32]uint16         // 86, 344
	BuffsPower    [32]uint8          // 102, 408
	Field110      uint32             // 110, 440
	ObjNext       *Object            // 111, 444
	ObjPrev       *Object            // 112, 448
	DeletedNext   *Object            // 113, 452
	DeletedAt     uint32             // 114, 456
	Field115      uint32             // 115, 460
	Field116      uint32             // 116, 464
	Field117      uint32             // 117, 468
	Field118      uint32             // 118, 472
	UpdatableNext *Object            // 119, 476
	UpdatablePrev *Object            // 120, 480
	IsUpdatable   uint32             // 121, 484
	Weight        uint8              // 122, 488
	Field122_1    uint8              // 122, 489
	CarryCapacity uint16             // 122, 490
	InvHolder     *Object            // 123, 492 // Also health data, possibly same as 556, see 4E4560
	InvNextItem   *Object            // 124, 496, TODO: next item
	Field125      *Object            // 125, 500, TODO: a nox_object_t*? see 4ED0C0
	InvFirstItem  *Object            // 126, 504, TODO: first item
	OwnerPtr      *Object            // 127, 508
	Field128      *Object            // 128, 512
	Field129      *Object            // 129, 516
	Obj130        *Object            // 130, 520
	Field131      uint32             // 131, 524
	Field132      uint32             // 132, 528
	Field133      uint32             // 133, 532
	Field134      uint32             // 134, 536, TODO: some timestamp
	Field135      uint32             // 135, 540, TODO: 541 accessed as byte
	SpeedCur      float32            // 136, 544
	Speed2        float32            // 137, 548
	Float138      float32            // 138, 552
	HealthData    *server.HealthData // 139, 556
	Field140      uint32             // 140, 560
	Field141      uint32             // 141, 564
	Field142      uint32             // 142, 568
	Field143      uint32             // 143, 572
	Field144      uint32             // 144, 576
	Field145      uint32             // 145, 580
	Field146      uint32             // 146, 584
	Field147      uint32             // 147, 588
	Field148      uint32             // 148, 592
	Field149      uint32             // 149, 596
	Field150      uint32             // 150, 600
	Field151      uint32             // 151, 604
	Field152      uint32             // 152, 608
	Field153      uint32             // 153, 612
	Field154      uint32             // 154, 616
	Field155      uint32             // 155, 620
	Field156      uint32             // 156, 624
	Field157      uint32             // 157, 628
	Field158      uint32             // 158, 632
	Field159      uint32             // 159, 636
	Field160      uint32             // 160, 640
	Field161      uint32             // 161, 644
	Field162      uint32             // 162, 648
	Field163      uint32             // 163, 652
	Field164      uint32             // 164, 656
	Field165      uint32             // 165, 660
	Field166      uint32             // 166, 664
	Field167      uint32             // 167, 668
	Field168      uint32             // 168, 672
	Field169      uint32             // 169, 676
	Field170      uint32             // 170, 680
	Field171      uint32             // 171, 684
	Init          unsafe.Pointer     // 172, 688
	InitData      unsafe.Pointer     // 173, 692, // TODO: struct pointer; struct at least 8 bytes wide. see 4F3030.
	Collide       unsafe.Pointer     // 174, 696
	CollideData   unsafe.Pointer     // 175, 700
	Xfer          unsafe.Pointer     // 176, 704; func(*Object, int) int
	Pickup        unsafe.Pointer     // 177, 708
	Drop          unsafe.Pointer     // 178, 712
	Damage        unsafe.Pointer     // 179, 716; func(*Object, *Object, int, int, int) int
	DamageSound   unsafe.Pointer     // 180, 720
	Death         unsafe.Pointer     // 181, 724
	DeathData     unsafe.Pointer     // 182, 728
	Use           unsafe.Pointer     // 183, 732
	UseData       unsafe.Pointer     // 184, 736
	Field185      uint32             // 185, 740
	Update        unsafe.Pointer     // 186, 744; func(*Object)
	UpdateData    unsafe.Pointer     // 187, 748
	Field188      uint32             // 188, 752
	Field189      unsafe.Pointer     // 189, 756
	Field190      uint32             // 190, 760
	Field191      uint32             // 191, 764
	Field192      int                // 192, 768
}

func (obj *Object) getServer() *Server {
	return noxServer // TODO: attach to object
}

func (obj *Object) UniqueKey() uintptr {
	return uintptr(unsafe.Pointer(obj))
}

func (obj *Object) CObj() *nox_object_t {
	return (*nox_object_t)(unsafe.Pointer(obj))
}

func (obj *Object) SObj() *server.Object {
	return (*server.Object)(unsafe.Pointer(obj))
}

func (obj *Object) AsObject() *Object {
	return obj
}

func (obj *Object) field(dp uintptr) unsafe.Pointer {
	return unsafe.Add(unsafe.Pointer(obj), dp)
}

func (obj *Object) ID() string {
	return GoString((*C.char)(obj.IDPtr))
}

func (obj *Object) Ind() int { // aka "extent"
	return int(obj.Extent)
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
		for _, p := range obj.getServer().getPlayers() {
			if u := p.UnitC(); u != nil && u.CObj() == obj.CObj() {
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
	return object.Class(obj.ObjClass)
}

func (obj *Object) SubClass() uint32 {
	return uint32(obj.ObjSubClass)
}

func (obj *Object) ArmorClass() object.ArmorClass {
	if !obj.Class().Has(object.ClassArmor) {
		return 0
	}
	return object.ArmorClass(obj.SubClass())
}

func (obj *Object) Flags() object.Flags {
	return object.Flags(obj.ObjFlags)
}

func (obj *Object) SetFlags(v object.Flags) {
	obj.ObjFlags = uint32(v)
}

func (obj *Object) Mass() float32 { // nox_xxx_objectGetMass_4E4A70
	return obj.MassVal
}

func (obj *Object) Health() (cur, max int) {
	if obj == nil {
		return
	}
	h := obj.HealthData
	if h == nil {
		return
	}
	cur = int(h.Cur)
	max = int(h.Max)
	return
}

func (obj *Object) IsMovable() bool {
	if obj.Flags().HasAny(object.FlagNotMovableMask) {
		return false
	}
	return !obj.Class().Has(object.ClassImmobile)
}

func (obj *Object) team() byte {
	return obj.teamPtr().field1
}

func (obj *Object) Team() *Team {
	if obj == nil {
		return nil
	}
	return obj.getServer().teamByYyy(obj.team())
}

func (obj *Object) findByID(id string) *Object {
	if obj.equalID(id) {
		return obj
	}
	for p := obj.FirstItem(); p != nil; p = p.NextItem() {
		if p.equalID(id) {
			return p
		}
	}
	return nil
}

func (obj *Object) equalID(id2 string) bool {
	id := obj.ID()
	if id == "" {
		return false
	}
	return id == id2 || strings.HasSuffix(id, ":"+id2)
}

func (obj *Object) needSync() { // nox_xxx_unitNeedSync_4E44F0
	obj.Field38 = -1
}

func (obj *Object) makeUnseen() { // nox_xxx_objectMakeUnseenByNoone_4E44E0
	obj.Field38 = 0
}

func (obj *Object) Next() *Object { // nox_server_getNextObject_4DA7A0, nox_xxx_getNextUpdatable2Object_4DA850, nox_server_getNextObjectUninited_4DA880
	return asObject(unsafe.Pointer(obj.ObjNext))
}

func (obj *Object) FirstItem() *Object { // nox_xxx_inventoryGetFirst_4E7980
	return asObject(unsafe.Pointer(obj.InvFirstItem))
}

func (obj *Object) NextItem() *Object {
	return asObject(unsafe.Pointer(obj.InvNextItem))
}

func (obj *Object) InventoryHolder() *Object {
	return asObject(unsafe.Pointer(obj.InvHolder))
}

func (obj *Object) HasItem(item *Object) bool {
	if item == nil || item.InventoryHolder() != obj {
		return false
	}
	for p := obj.FirstItem(); p != nil; p = p.NextItem() {
		if p == item {
			return true
		}
	}
	return false
}

func (obj *Object) updateDataMissile() *C.nox_object_Missile_data_t {
	return (*C.nox_object_Missile_data_t)(obj.UpdateData)
}

func (obj *Object) updateDataElevator() *C.nox_object_Elevator_data_t {
	return (*C.nox_object_Elevator_data_t)(obj.UpdateData)
}

func (obj *Object) Inventory() []*Object {
	var out []*Object
	for p := obj.FirstItem(); p != nil; p = p.NextItem() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) NextOwned512() *Object {
	return asObject(unsafe.Pointer(obj.Field128))
}

func (obj *Object) FirstOwned516() *Object {
	return asObject(unsafe.Pointer(obj.Field129))
}

func (obj *Object) GetOwned516() []*Object {
	var out []*Object
	for p := obj.FirstOwned516(); p != nil; p = p.NextOwned512() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) HasEnchant(v server.EnchantID) bool { // nox_xxx_testUnitBuffs_4FF350
	if obj == nil || v >= 32 {
		return false
	}
	return obj.Buffs&(uint32(1)<<v) != 0
}

func (obj *Object) EnchantDur(v server.EnchantID) int { // nox_xxx_unitGetBuffTimer_4FF550
	if obj == nil || v >= 32 {
		return 0
	}
	return int(obj.BuffsDur[v])
}

func (obj *Object) EnchantPower(v server.EnchantID) int { // nox_xxx_buffGetPower_4FF570
	if obj == nil || v >= 32 {
		return 0
	}
	return int(obj.BuffsDur[v])
}

func (obj *Object) ApplyEnchant(v server.EnchantID, dur, power int) { // nox_xxx_buffApplyTo_4FF380
	if obj == nil || v >= 32 {
		return
	}
	C.nox_xxx_buffApplyTo_4FF380(obj.CObj(), C.int(v), C.short(dur), C.char(power))
}

func (obj *Object) DisableEnchant(v server.EnchantID) { // nox_xxx_spellBuffOff_4FF5B0
	if obj == nil || v >= 32 {
		return
	}
	C.nox_xxx_spellBuffOff_4FF5B0(obj.CObj(), C.int(v))
}

func (obj *Object) AsUnit() *Unit {
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

func (obj *Object) teamPtr() *objectTeam {
	if obj == nil {
		return nil
	}
	return (*objectTeam)(unsafe.Pointer(&obj.Field12))
}

func (obj *Object) OwnerC() *Object {
	return obj.OwnerPtr
}

func (obj *Object) Owner() script.Object {
	p := obj.OwnerC()
	if p == nil {
		return nil
	}
	return p
}

func (obj *Object) SetOwner(owner script.ObjectWrapper) {
	if owner == nil {
		C.nox_xxx_unitClearOwner_4EC300(obj.CObj())
		return
	}
	own := owner.GetObject().(noxObject)
	C.nox_xxx_unitSetOwner_4EC290(own.CObj(), obj.CObj())
}

func (obj *Object) Pos() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return obj.PosVec
}

func (obj *Object) Vel() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return obj.VelVec
}

func (obj *Object) Force() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return obj.ForceVec
}

func (obj *Object) Dir1() uint16 {
	if obj == nil {
		return 0
	}
	return obj.Direction1
}

func (obj *Object) Dir2() uint16 {
	if obj == nil {
		return 0
	}
	return obj.Direction2
}

func (obj *Object) curSpeed() float32 {
	if obj == nil {
		return 0
	}
	return obj.SpeedCur
}

func (obj *Object) setAllDirs(dir uint16) {
	obj.Direction1 = dir
	obj.Direction2 = dir
}

func (obj *Object) SetPos(p types.Pointf) {
	cp, free := alloc.New(C.float2{})
	defer free()
	cp.field_0 = C.float(p.X)
	cp.field_4 = C.float(p.Y)
	C.nox_xxx_unitMove_4E7010(obj.CObj(), cp)
}

// ApplyForce adds a new force vector to the object. If another force in effect, it will adds up.
func (obj *Object) ApplyForce(p types.Pointf) {
	obj.ForceVec = obj.ForceVec.Add(p)
}

func (obj *Object) Z() float32 {
	return obj.ZVal
}

func (obj *Object) SetZ(z float32) {
	C.nox_xxx_unitRaise_4E46F0(obj.CObj(), C.float(z))
}

func (obj *Object) Push(vec types.Pointf, force float32) {
	panic("implement me")
}

func (obj *Object) PushTo(p types.Pointf) {
	panic("implement me")
}

func (obj *Object) IsEnabled() bool {
	if obj == nil {
		return false
	}
	return obj.Flags().Has(object.FlagEnabled)
}

// Toggle the object's enable state.
// The returning boolean represents the enabled state of the object before toggled.
func (obj *Object) Toggle() bool {
	if obj.IsEnabled() {
		C.nox_xxx_objectSetOff_4E7600(obj.CObj())
		return true
	} else {
		C.nox_xxx_objectSetOn_4E75B0(obj.CObj())
		return false
	}
}

func (obj *Object) Enable(enable bool) {
	if obj == nil {
		return
	}
	if enable {
		C.nox_xxx_objectSetOn_4E75B0(obj.CObj())
	} else {
		C.nox_xxx_objectSetOff_4E7600(obj.CObj())
	}
}

func (obj *Object) Delete() {
	obj.getServer().delayedDelete(obj)
}

func (obj *Object) Destroy() {
	panic("implement me")
}

func (obj *Object) callUpdate() {
	if obj.Update == nil {
		return
	}
	switch obj.Update {
	case unsafe.Pointer(C.nox_xxx_updatePlayer_4F8100):
		nox_xxx_updatePlayer_4F8100(obj.CObj())
	case unsafe.Pointer(C.nox_xxx_updatePlayerObserver_4E62F0):
		nox_xxx_updatePlayerObserver_4E62F0(obj.CObj())
	case unsafe.Pointer(C.nox_xxx_updateHarpoon_54F380):
		nox_xxx_updateHarpoon_54F380(obj.CObj())
	case unsafe.Pointer(C.nox_xxx_updatePixie_53CD20):
		nox_xxx_updatePixie_53CD20(obj.CObj())
	default:
		C.nox_call_obj_update_go((*[0]byte)(obj.Update), obj.CObj())
	}
}

func (obj *Object) callXfer(a2 unsafe.Pointer) error {
	switch obj.Xfer {
	case unsafe.Pointer(C.nox_xxx_XFerDefault_4F49A0):
		return nox_xxx_XFerDefault4F49A0(obj, a2)
	}
	if C.nox_call_object_xfer((*[0]byte)(obj.Xfer), obj.CObj(), a2) == 0 {
		return fmt.Errorf("xfer for %s failed", obj.String())
	}
	return nil
}

func (obj *Object) callDamage(who noxObject, a3 noxObject, dmg, a5 int) int {
	if obj.Damage != nil {
		return int(C.nox_call_object_damage((*[0]byte)(obj.Damage), obj.CObj(), toCObj(who), toCObj(a3), C.int(dmg), C.int(a5)))
	}
	return 0
}

func (obj *Object) callDrop(it noxObject, pos types.Pointf) int {
	if obj.Drop == nil {
		return 0
	}
	cpos, free := alloc.New(types.Pointf{})
	defer free()
	*cpos = pos
	ptr := (*C.float2)(unsafe.Pointer(cpos))

	switch obj.Drop {
	case unsafe.Pointer(C.nox_objectDropAudEvent_4EE2F0):
		return int(nox_objectDropAudEvent_4EE2F0(obj.CObj(), toCObj(it), ptr))
	default:
		return int(C.nox_call_object_drop((*[0]byte)(obj.Drop), obj.CObj(), toCObj(it), ptr))
	}
}

func (obj *Object) forceDrop(item *Object) int { // nox_xxx_invForceDropItem_4ED930
	pos := randomReachablePointAround(50.0, obj.Pos())
	return obj.forceDropAt(item, pos)
}

func (obj *Object) forceDropAt(item *Object, pos types.Pointf) int { // nox_xxx_drop_4ED790
	cpos, free := alloc.New(types.Pointf{})
	defer free()
	*cpos = pos
	return int(C.nox_xxx_drop_4ED790(obj.CObj(), item.CObj(), (*C.float2)(unsafe.Pointer(cpos))))
}

func (obj *Object) isEnemyTo(objp noxObject) bool { // nox_xxx_unitIsEnemyTo_5330C0
	obj2 := toObject(objp)
	if obj == nil || obj2 == nil {
		return false
	}
	if obj.CObj() == obj2.CObj() {
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
		if pl := obj2.AsUnit().ControllingPlayer(); pl.field_3680&0x1 != 0 {
			return false
		}
	}
	own1 := obj.FindOwnerChainPlayer()
	own2 := obj2.FindOwnerChainPlayer()
	if own1 == own2 {
		return false
	}
	if nox_xxx_servCompareTeams_419150(own1.teamPtr(), own2.teamPtr()) {
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
	if nox_xxx_servObjectHasTeam_419130(own1.teamPtr()) || nox_xxx_servObjectHasTeam_419130(own2.teamPtr()) {
		return true
	}
	if own1.Class().HasAny(object.ClassMonster) && own2.Class().HasAny(object.ClassMonster) {
		return false
	}
	return true
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

func (obj *Object) FindOwnerChainPlayer() *Object { // nox_xxx_findParentChainPlayer_4EC580
	if obj == nil {
		return nil
	}
	res := obj
	for it := obj.OwnerC(); it != nil; it = it.OwnerC() {
		if it.Class().Has(object.ClassPlayer) {
			res = it
			break
		}
		res = it
	}
	return res
}

func (obj *Object) HasOwner(owner *Object) bool {
	for it := owner; it != nil; it = it.OwnerC() {
		if it == owner {
			return true
		}
	}
	return false
}

func (obj *Object) dropAllItems() {
	C.nox_xxx_dropAllItems_4EDA40((*C.uint)(unsafe.Pointer(obj.CObj())))
}

func (obj *Object) sub548600(dp types.Pointf) {
	mass := obj.Mass()
	obj.Pos24.X += dp.X / mass
	obj.Pos24.Y += dp.Y / mass
}
