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
)

//export nox_server_getFirstObject_4DA790
func nox_server_getFirstObject_4DA790() *nox_object_t {
	return noxServer.firstServerObject().CObj()
}

//export nox_server_getFirstObjectUninited_4DA870
func nox_server_getFirstObjectUninited_4DA870() *nox_object_t {
	return noxServer.objs.pending.CObj()
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
	l := noxServer.objs.list
	noxServer.objs.list = nil
	return l.CObj()
}

//export nox_set_server_objects_4DA3E0
func nox_set_server_objects_4DA3E0(list *nox_object_t) {
	noxServer.objs.list = asObjectC(list)
}

//export nox_xxx_findParentChainPlayer_4EC580
func nox_xxx_findParentChainPlayer_4EC580(obj *nox_object_t) *nox_object_t {
	return asObjectC(obj).findOwnerChainPlayer().CObj()
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
	return noxServer.objs.updatableList.CObj()
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
	noxServer.objs.addToUpdatable(asObjectC(cobj))
}

//export nox_xxx_unitRemoveFromUpdatable_4DA920
func nox_xxx_unitRemoveFromUpdatable_4DA920(cobj *nox_object_t) {
	noxServer.objs.removeFromUpdatable(asObjectC(cobj))
}

//export nox_xxx_servFinalizeDelObject_4DADE0
func nox_xxx_servFinalizeDelObject_4DADE0(cobj *nox_object_t) {
	noxServer.objectDeleteLast(asObjectC(cobj))
}

//export nox_xxx_getFirstUpdatable2Object_4DA840
func nox_xxx_getFirstUpdatable2Object_4DA840() *nox_object_t {
	return noxServer.objs.updatableList2.CObj()
}

//export nox_xxx_unitsNewAddToList_4DAC00
func nox_xxx_unitsNewAddToList_4DAC00() {
	noxServer.objectsNewAdd()
}

//export nox_xxx_unitClearPendingMB_4DB030
func nox_xxx_unitClearPendingMB_4DB030() {
	noxServer.objectsClearPending()
}

//export nox_xxx_createAt_4DAA50
func nox_xxx_createAt_4DAA50(cobj *nox_object_t, cowner *nox_object_t, x C.float, y C.float) {
	var owner noxObject
	if cowner != nil {
		owner = asObjectC(cowner)
	}
	noxServer.createObjectAt(asObjectC(cobj), owner, types.Pointf{X: float32(x), Y: float32(y)})
}

type shapeKind uint32

const (
	shapeKindNone   = shapeKind(0)
	shapeKindCenter = shapeKind(1)
	shapeKindCircle = shapeKind(2)
	shapeKindBox    = shapeKind(3)
)

var _ = ([1]struct{}{})[52-unsafe.Sizeof(noxShape{})]

type noxShape struct {
	kind   shapeKind // 0, 0x0, (43)
	circle struct {
		R  float32 // 1, 0x4, (44)
		R2 float32 // 2, 0x8, (45)
	}
	box noxShapeBox
}

type noxShapeBox struct {
	W            float32 // 3, 0xC, (46)
	H            float32 // 4, 0x10, (47)
	LeftTop      float32 // 5, 0x14, (48)
	LeftBottom   float32 // 6, 0x18, (49)
	LeftBottom2  float32 // 7, 0x1C, (50)
	LeftTop2     float32 // 8, 0x20, (51)
	RightTop     float32 // 9, 0x24, (52)
	RightBottom  float32 // 10, 0x28, (53)
	RightBottom2 float32 // 11, 0x2C, (54)
	RightTop2    float32 // 12, 0x30, (55)
}

func (s *noxShapeBox) Calc() {
	const mul = 0.35354999 // cos(Pi/4) / 2
	px := s.W * mul
	py := s.H * mul

	v := float32(0.0)

	v = -px + py
	s.LeftTop = v
	s.LeftTop2 = v

	v = -px - py
	s.LeftBottom = v
	s.LeftBottom2 = v

	v = +px + py
	s.RightTop = v
	s.RightTop2 = v

	v = +px - py
	s.RightBottom = v
	s.RightBottom2 = v
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

func (s *Server) firstServerObject() *Object { // nox_server_getFirstObject_4DA790
	return s.objs.list
}

func (s *Server) getObjects() []*Object {
	var out []*Object
	for p := s.firstServerObject(); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func (s *Server) getObjectsUpdatable2() []*Object {
	var out []*Object
	for p := s.objs.updatableList2; p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

type serverObjects struct {
	list           *Object
	pending        *Object
	updatableList  *Object
	updatableList2 *Object
	deletedList    *Object
}

func (s *serverObjects) addToUpdatable(obj *Object) {
	if obj.is_updatable == 0 && !obj.Class().Has(object.ClassMissile) {
		obj.updatable_prev = nil
		obj.updatable_next = s.updatableList.CObj()
		if s.updatableList != nil {
			s.updatableList.updatable_prev = obj.CObj()
		}
		s.updatableList = obj
		obj.is_updatable = 1
		obj.obj_130 = nil
	}
}

func (s *serverObjects) removeFromUpdatable(obj *Object) {
	if obj.is_updatable == 0 {
		return
	}
	prev := asObjectC(obj.updatable_prev)
	if prev != nil {
		prev.updatable_next = obj.updatable_next
	} else {
		s.updatableList = asObjectC(obj.updatable_next)
	}
	if next := obj.updatable_next; next != nil {
		next.updatable_prev = prev.CObj()
	}
	obj.is_updatable = 0
	obj.obj_130 = nil
}

func (s *Server) getObjectsUninited() []*Object {
	var out []*Object
	for p := s.objs.pending; p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func (s *Server) getObjectByID(id string) *Object {
	for obj := s.objs.list; obj != nil; obj = obj.Next() {
		if p := obj.findByID(id); p != nil {
			return p
		}
	}
	for obj := s.objs.pending; obj != nil; obj = obj.Next() {
		if p := obj.findByID(id); p != nil {
			return p
		}
	}
	return nil
}

func (s *Server) getObjectByInd(ind int) *Object { // aka nox_xxx_netGetUnitByExtent_4ED020
	for p := s.firstServerObject(); p != nil; p = p.Next() {
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
		if wl := s.getObjectByInd(ind); wl != nil {
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

	if v := obj.field_123; v != 0 {
		C.sub_4ED0C0(C.int(v), obj.CObj())
	}
	C.nox_xxx_playerCancelSpells_4FEAE0(obj.CObj())
	if noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().Has(object.ClassMonster) {
		C.sub_50E210(obj.CObj())
	}
	if obj.Class().Has(object.ClassPlayer) {
		C.sub_506740(obj.CObj())
	}
	obj.SetFlags(obj.Flags() | object.FlagDestroyed)
	obj.deleted_next = s.objs.deletedList.CObj()
	s.objs.deletedList = obj
	obj.deleted_at = C.uint(gameFrame())
	if nox_xxx_servObjectHasTeam_419130(obj.teamPtr()) {
		C.nox_xxx_netChangeTeamMb_419570(unsafe.Pointer(obj.teamPtr()), C.int(obj.net_code))
	}
}

func (s *Server) finalizeDeletingObjects() {
	var next *Object
	for it := s.objs.deletedList; it != nil; it = next {
		next = asObjectC(it.deleted_next)
		s.objectDeleteFinish(it)
	}
	s.objs.deletedList = nil
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
	obj.obj_flags &^= C.uint(object.FlagActive)
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
	for it := s.objs.deletedList; it != nil; it = next {
		next = asObjectC(it.deleted_next)
		if uint32(it.deleted_at) == gameFrame() {
			it.deleted_next = list.CObj()
			list = it
			s.objs.removeFromUpdatable(it)
		} else {
			s.objectDeleteFinish(it)
		}
	}
	s.objs.deletedList = list
}

func (s *Server) objectsNewAdd() {
	var next *Object
	for it := s.objs.pending; it != nil; it = next {
		next = it.Next()
		for it2 := it.OwnerC(); it2 != nil; it2 = it.OwnerC() {
			if !it.Flags().Has(object.FlagDestroyed) {
				break
			}
			it.SetOwner(it2.Owner())
		}
		if it.Class().Has(object.ClassMissile) {
			it.object_next = s.objs.updatableList2.CObj()
			it.object_prev = nil
			if s.objs.updatableList2 != nil {
				s.objs.updatableList2.object_prev = it.CObj()
			}
			s.objs.updatableList2 = it
		} else {
			if it.Flags().Has(object.FlagShadow) {
				it.obj_flags &^= C.uint(object.FlagShadow)
				C.nox_xxx_unitNewAddShadow_4DA9A0(it.CObj())
			}
			if it.Flags().Has(object.FlagRespawn) && !noxflags.HasGame(noxflags.GameModeQuest) {
				C.nox_xxx_respawnAdd_4EC5E0(it.CObj())
			}
			if it.func_update != nil || it.vel_x != 0.0 || it.vel_y != 0.0 { // TODO: had a weird check: ... && *(*uint8)(&it.obj_class) >= 0
				s.objs.addToUpdatable(it)
			}
			it.object_next = s.objs.list.CObj()
			it.object_prev = nil
			if s.objs.list != nil {
				s.objs.list.object_prev = it.CObj()
			}
			s.objs.list = it
		}
		C.nox_xxx_unitCreateMissileSmth_517640(it.CObj())
		if it.func_collide != nil {
			C.sub_5117F0(it.CObj())
		}
		if it.func_init != nil {
			C.nox_call_object_init((*[0]byte)(it.func_init), it.CObj(), nil)
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
				it.field_37 = 0
			}
		} else {
			it.makeUnseen()
			C.sub_527E00(it.CObj())
			it.field_37 = -1
		}
		it.obj_flags &^= C.uint(object.FlagPending)
	}
	s.objs.pending = nil
}

func (s *Server) sub_4DAE50(obj *Object) {
	C.nox_xxx_action_4DA9F0(obj.CObj())
	if obj.Class().Has(object.ClassMissile) {
		prev := asObjectC(obj.object_prev)
		if prev != nil {
			prev.object_next = obj.object_next
		} else {
			s.objs.updatableList2 = asObjectC(obj.object_next)
		}
		if next := obj.object_next; next != nil {
			next.object_prev = prev.CObj()
		}
	} else {
		s.objs.removeFromUpdatable(obj)
		prev := asObjectC(obj.object_prev)
		if prev != nil {
			prev.object_next = obj.object_next
		} else {
			s.objs.list = asObjectC(obj.object_next)
		}
		if next := obj.object_next; next != nil {
			next.object_prev = prev.CObj()
		}
	}
}

func (s *Server) objectsClearPending() {
	var next *Object
	for it := s.objs.pending; it != nil; it = next {
		next = it.Next()
		it.obj_flags &^= C.uint(object.FlagPending)
		if s.objs.list != nil {
			s.objs.list.object_prev = it.CObj()
		}
		it.object_next = s.objs.list.CObj()
		it.object_prev = nil
		s.objs.list = it
	}
	s.objs.pending = nil
}

func (s *Server) attachPending() {
	for it := s.objs.pending; it != nil; it = it.Next() {
		if it.Class().Has(object.ClassElevator) {
			ud := it.updateDataPtr()
			// find elevator shaft and attach them to each other
			for it2 := s.objs.pending; it2 != nil; it2 = it2.Next() {
				if it2.Class().Has(object.ClassElevatorShaft) {
					ud2 := it2.updateDataPtr()
					if *(*uint32)(unsafe.Add(ud, 8)) == uint32(it2.extent) {
						*(**nox_object_t)(unsafe.Add(ud, 4)) = it2.CObj()
						*(**nox_object_t)(unsafe.Add(ud2, 4)) = it.CObj()
						break
					}
				}
			}
		}
		if it.Class().Has(object.ClassTransporter) {
			ud := it.updateDataPtr()
			*(**nox_object_t)(unsafe.Add(ud, 12)) = nil
			// if transporter target is set - attach to it
			if ext := *(*uint32)(unsafe.Add(ud, 16)); ext != 0 {
				for it2 := s.objs.pending; it2 != nil; it2 = it2.Next() {
					if it2.Class().Has(object.ClassTransporter) && ext == uint32(it2.extent) {
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
		*memmap.PtrUint32(0x5D4594, 1556864) = uint32(s.getObjectTypeID("Gold"))
		*memmap.PtrUint32(0x5D4594, 1556868) = uint32(s.getObjectTypeID("QuestGoldPile"))
		*memmap.PtrUint32(0x5D4594, 1556872) = uint32(s.getObjectTypeID("QuestGoldChest"))
	}
	if obj.Flags().HasAny(object.FlagActive | object.FlagDestroyed) {
		return
	}
	obj.SetFlags(obj.Flags() & 0x35E9FEDB)
	obj.setPrevPos(pos)
	obj.setPos(pos)
	obj.setNewPos(pos)
	obj.float_39 = C.float(pos.X)
	obj.float_40 = C.float(pos.Y)
	C.nox_xxx_objectUnkUpdateCoords_4E7290(obj.CObj())
	if obj.Class().HasAny(object.MaskUnits) {
		C.nox_xxx_unitPostCreateNotify_4E7F10(obj.CObj())
	}
	if owner != nil {
		obj.SetOwner(owner.AsObject())
	}
	obj.setVel(types.Pointf{})
	obj.setForce(types.Pointf{})
	obj.obj_flags |= C.uint(object.FlagActive)
	obj.field_32 = C.uint(gameFrame())
	obj.field_34 = C.uint(gameFrame())
	if noxflags.HasGame(noxflags.GameOnline) && !noxflags.HasGame(noxflags.GameModeQuest) && !obj.Class().Has(object.ClassMissile) &&
		(obj.objTypeInd() == int(memmap.Uint32(0x5D4594, 1556864)) ||
			obj.Class().HasAny(object.ClassFood|object.ClassInfoBook|object.ClassWand|object.ClassWeapon|object.ClassArmor)) {
		obj.obj_flags |= C.uint(object.FlagNoCollide)
	}
	obj.object_next = s.objs.pending.CObj()
	obj.object_prev = nil
	if s.objs.pending != nil {
		s.objs.pending.object_prev = obj.CObj()
	}
	s.objs.pending = obj
	obj.obj_flags |= C.uint(object.FlagPending)
	if obj.field_13&0xff != 0 && (!obj.Class().Has(object.ClassFlag) || memmap.Int32(0x973F18, 3800) >= 0) {
		if noxflags.HasGame(noxflags.GameModeCoop) || checkGameplayFlags(4) {
			C.nox_xxx_createAtImpl_4191D0(C.uchar(obj.field_13), unsafe.Pointer(obj.teamPtr()), 0, C.int(obj.net_code), 0)
		}
	}
}

func (s *Server) deleteAllObjectsOfType(t *ObjectType) {
	var next *Object
	for it := s.firstServerObject(); it != nil; it = next {
		next = it.Next()
		var next2 *Object
		for it2 := it.FirstItem(); it2 != nil; it2 = next2 {
			next2 = it2.NextItem()
			if it2.objTypeInd() == t.Ind() {
				it2.Delete()
			}
		}
		if it.objTypeInd() == t.Ind() {
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
	AsObject() *Object
}

type Object nox_object_t

func (obj *Object) getServer() *Server {
	return noxServer // TODO: attach to object
}

func (obj *Object) UniqueKey() uintptr {
	return uintptr(unsafe.Pointer(obj))
}

func (obj *Object) CObj() *nox_object_t {
	return (*nox_object_t)(unsafe.Pointer(obj))
}

func (obj *Object) AsObject() *Object {
	return obj
}

func (obj *Object) field(dp uintptr) unsafe.Pointer {
	return unsafe.Add(unsafe.Pointer(obj), dp)
}

func (obj *Object) ID() string {
	return GoString(obj.id)
}

func (obj *Object) Ind() int { // aka "extent"
	return int(obj.extent)
}

func (obj *Object) ScriptID() int {
	return int(obj.script_id)
}

func (obj *Object) objTypeInd() int {
	return int(obj.typ_ind)
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
	return object.Class(obj.obj_class)
}

func (obj *Object) SubClass() uint32 {
	return uint32(obj.obj_subclass)
}

func (obj *Object) ArmorClass() object.ArmorClass {
	if !obj.Class().Has(object.ClassArmor) {
		return 0
	}
	return object.ArmorClass(obj.SubClass())
}

func (obj *Object) Flags() object.Flags {
	return object.Flags(obj.obj_flags)
}

func (obj *Object) SetFlags(v object.Flags) {
	obj.obj_flags = C.uint(v)
}

func (obj *Object) Mass() float32 { // nox_xxx_objectGetMass_4E4A70
	return float32(obj.mass)
}

func (obj *Object) getShape() *noxShape {
	return (*noxShape)(unsafe.Pointer(&obj.shape))
}

func (obj *Object) healthData() *objectHealthData {
	return (*objectHealthData)(unsafe.Pointer(obj.health_data))
}

func (obj *Object) Health() (cur, max int) {
	if obj == nil {
		return
	}
	h := obj.healthData()
	if h == nil {
		return
	}
	cur = int(h.cur)
	max = int(h.max)
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
	obj.field_38 = -1
}

func (obj *Object) makeUnseen() { // nox_xxx_objectMakeUnseenByNoone_4E44E0
	obj.field_38 = 0
}

func (obj *Object) Next() *Object { // nox_server_getNextObject_4DA7A0, nox_xxx_getNextUpdatable2Object_4DA850, nox_server_getNextObjectUninited_4DA880
	return asObject(unsafe.Pointer(obj.object_next))
}

func (obj *Object) FirstItem() *Object { // nox_xxx_inventoryGetFirst_4E7980
	return asObject(unsafe.Pointer(obj.field_126))
}

func (obj *Object) NextItem() *Object {
	return asObject(unsafe.Pointer(obj.field_124))
}

func (obj *Object) updateDataPtr() unsafe.Pointer {
	return unsafe.Pointer(obj.data_update)
}

func (obj *Object) updateDataMissile() *C.nox_object_Missile_data_t {
	return (*C.nox_object_Missile_data_t)(unsafe.Pointer(obj.data_update))
}

func (obj *Object) Inventory() []*Object {
	var out []*Object
	for p := obj.FirstItem(); p != nil; p = p.NextItem() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) NextOwned512() *Object {
	return asObject(unsafe.Pointer(obj.field_128))
}

func (obj *Object) FirstOwned516() *Object {
	return asObject(unsafe.Pointer(obj.field_129))
}

func (obj *Object) GetOwned516() []*Object {
	var out []*Object
	for p := obj.FirstOwned516(); p != nil; p = p.NextOwned512() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) HasEnchant(v EnchantID) bool { // nox_xxx_testUnitBuffs_4FF350
	if obj == nil || v >= 32 {
		return false
	}
	return uint32(obj.buffs)&(uint32(1)<<v) != 0
}

func (obj *Object) EnchantDur(v EnchantID) int { // nox_xxx_unitGetBuffTimer_4FF550
	if obj == nil || v >= 32 {
		return 0
	}
	return int(obj.buffs_dur[v])
}

func (obj *Object) EnchantPower(v EnchantID) int { // nox_xxx_buffGetPower_4FF570
	if obj == nil || v >= 32 {
		return 0
	}
	return int(obj.buffs_dur[v])
}

func (obj *Object) ApplyEnchant(v EnchantID, dur, power int) { // nox_xxx_buffApplyTo_4FF380
	if obj == nil || v >= 32 {
		return
	}
	C.nox_xxx_buffApplyTo_4FF380(obj.CObj(), C.int(v), C.short(dur), C.char(power))
}

func (obj *Object) DisableEnchant(v EnchantID) { // nox_xxx_spellBuffOff_4FF5B0
	if obj == nil || v >= 32 {
		return
	}
	C.nox_xxx_spellBuffOff_4FF5B0(obj.CObj(), C.int(v))
}

func (obj *Object) AsUnit() *Unit {
	// TODO: check somehow
	return asUnit(unsafe.Pointer(obj))
}

func (obj *Object) ObjectTypeC() *ObjectType {
	if obj == nil {
		return nil
	}
	ind := obj.objTypeInd()
	return obj.getServer().getObjectTypeByInd(ind)
}

func (obj *Object) ObjectType() script.ObjectType {
	t := obj.ObjectTypeC()
	if t == nil {
		return nil
	}
	return t
}

func (obj *Object) teamPtr() *objectTeam {
	if obj == nil {
		return nil
	}
	return (*objectTeam)(unsafe.Pointer(&obj.field_12))
}

func (obj *Object) OwnerC() *Object {
	return asObjectC(obj.owner)
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
	return types.Pointf{
		X: float32(obj.x),
		Y: float32(obj.y),
	}
}

func (obj *Object) Vel() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return types.Pointf{
		X: float32(obj.vel_x),
		Y: float32(obj.vel_y),
	}
}

func (obj *Object) Force() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return types.Pointf{
		X: float32(obj.force_x),
		Y: float32(obj.force_y),
	}
}

func (obj *Object) Dir() uint16 {
	if obj == nil {
		return 0
	}
	return uint16(obj.direction2)
}

func (obj *Object) curSpeed() float32 {
	if obj == nil {
		return 0
	}
	return float32(obj.speed_cur)
}

func (obj *Object) setAllDirs(dir uint16) {
	obj.direction1 = C.uint16_t(dir)
	obj.direction2 = C.uint16_t(dir)
}

func (obj *Object) prevPos() types.Pointf {
	return types.Pointf{
		X: float32(obj.prev_x),
		Y: float32(obj.prev_y),
	}
}

func (obj *Object) newPos() types.Pointf {
	return types.Pointf{
		X: float32(obj.new_x),
		Y: float32(obj.new_y),
	}
}

func (obj *Object) SetPos(p types.Pointf) {
	cp, free := alloc.New(C.float2{})
	defer free()
	cp.field_0 = C.float(p.X)
	cp.field_4 = C.float(p.Y)
	C.nox_xxx_unitMove_4E7010(obj.CObj(), cp)
}

func (obj *Object) setPos(p types.Pointf) {
	obj.x = C.float(p.X)
	obj.y = C.float(p.Y)
}

func (obj *Object) setPrevPos(p types.Pointf) {
	obj.prev_x = C.float(p.X)
	obj.prev_y = C.float(p.Y)
}

func (obj *Object) setNewPos(p types.Pointf) {
	obj.new_x = C.float(p.X)
	obj.new_y = C.float(p.Y)
}

func (obj *Object) setVel(p types.Pointf) {
	obj.vel_x = C.float(p.X)
	obj.vel_y = C.float(p.Y)
}

func (obj *Object) setForce(p types.Pointf) {
	obj.force_x = C.float(p.X)
	obj.force_y = C.float(p.Y)
}

func (obj *Object) Z() float32 {
	return float32(*(*C.int)(obj.field(104)))
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
	return *(*uint32)(obj.field(16))&0x1000000 != 0
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
	if obj.func_update == nil {
		return
	}
	switch unsafe.Pointer(obj.func_update) {
	case unsafe.Pointer(C.nox_xxx_updatePlayer_4F8100):
		nox_xxx_updatePlayer_4F8100(obj.CObj())
	case unsafe.Pointer(C.nox_xxx_updatePlayerObserver_4E62F0):
		nox_xxx_updatePlayerObserver_4E62F0(obj.CObj())
	case unsafe.Pointer(C.nox_xxx_updateHarpoon_54F380):
		nox_xxx_updateHarpoon_54F380(obj.CObj())
	case unsafe.Pointer(C.nox_xxx_updatePixie_53CD20):
		nox_xxx_updatePixie_53CD20(obj.CObj())
	default:
		C.nox_call_obj_update_go((*[0]byte)(obj.func_update), obj.CObj())
	}
}

func (obj *Object) callXfer(a2 unsafe.Pointer) error {
	switch unsafe.Pointer(obj.func_xfer) {
	case unsafe.Pointer(C.nox_xxx_XFerDefault_4F49A0):
		return nox_xxx_XFerDefault4F49A0(obj, a2)
	}
	if C.nox_call_object_xfer((*[0]byte)(obj.func_xfer), obj.CObj(), a2) == 0 {
		return fmt.Errorf("xfer for %s failed", obj.String())
	}
	return nil
}

func (obj *Object) callDamage(who noxObject, a3 noxObject, dmg, a5 int) int {
	if obj.func_damage != nil {
		return int(C.nox_call_object_damage((*[0]byte)(obj.func_damage), obj.CObj(), toCObj(who), toCObj(a3), C.int(dmg), C.int(a5)))
	}
	return 0
}

func (obj *Object) callDrop(it noxObject, pos types.Pointf) int {
	if obj.func_drop == nil {
		return 0
	}
	cpos, free := alloc.New(types.Pointf{})
	defer free()
	*cpos = pos
	ptr := (*C.float2)(unsafe.Pointer(cpos))

	switch unsafe.Pointer(obj.func_drop) {
	case unsafe.Pointer(C.nox_objectDropAudEvent_4EE2F0):
		return int(nox_objectDropAudEvent_4EE2F0(obj.CObj(), toCObj(it), ptr))
	default:
		return int(C.nox_call_object_drop((*[0]byte)(obj.func_drop), obj.CObj(), toCObj(it), ptr))
	}
}

func (obj *Object) forceDrop(item *Object) { // nox_xxx_invForceDropItem_4ED930
	pos := randomReachablePointAround(50.0, obj.Pos())
	obj.forceDropAt(item, pos)
}

func (obj *Object) forceDropAt(item *Object, pos types.Pointf) { // nox_xxx_drop_4ED790
	cpos, free := alloc.New(types.Pointf{})
	defer free()
	*cpos = pos
	C.nox_xxx_drop_4ED790(obj.CObj(), item.CObj(), (*C.float2)(unsafe.Pointer(cpos)))
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
	if srv.types.fast.plant == 0 {
		srv.types.fast.plant = srv.getObjectTypeID("CarnivorousPlant")
	}
	if srv.types.fast.polyp == 0 {
		srv.types.fast.polyp = srv.getObjectTypeID("Polyp")
	}
	if srv.types.fast.wisp == 0 {
		srv.types.fast.wisp = srv.getObjectTypeID("WillOWisp")
	}
	if obj2.Class().HasAny(object.ClassMonster) {
		if ud := obj2.AsUnit().updateDataMonster(); ud.field_360&0x40000 != 0 {
			return false
		}
	}
	if obj.Class().HasAny(object.ClassPlayer) && obj2.objTypeInd() == srv.types.fast.polyp {
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
	if obj.HasEnchant(ENCHANT_CHARMING) || obj2.HasEnchant(ENCHANT_CHARMING) {
		return false
	}
	if obj2.Class().HasAny(object.ClassPlayer) {
		if pl := obj2.AsUnit().ControllingPlayer(); pl.field_3680&0x1 != 0 {
			return false
		}
	}
	own1 := obj.findOwnerChainPlayer()
	own2 := obj2.findOwnerChainPlayer()
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
	if !noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().HasAny(object.ClassMonster) && obj2.objTypeInd() == srv.types.fast.wisp {
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
	if srv.types.fast.fishSmall == 0 {
		srv.types.fast.fishSmall = srv.getObjectTypeID("FishSmall")
		srv.types.fast.fishBig = srv.getObjectTypeID("FishBig")
	}
	return obj.objTypeInd() == srv.types.fast.fishSmall || obj.objTypeInd() == srv.types.fast.fishBig
}

func (obj *Object) isRat() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	if srv.types.fast.rat == 0 {
		srv.types.fast.rat = srv.getObjectTypeID("Rat")
	}
	return obj.objTypeInd() == srv.types.fast.rat
}

func (obj *Object) isFrog() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	if srv.types.fast.frog == 0 {
		srv.types.fast.frog = srv.getObjectTypeID("GreenFrog")
	}
	return obj.objTypeInd() == srv.types.fast.frog
}

func (obj *Object) isPlant() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	if srv.types.fast.plant == 0 {
		srv.types.fast.plant = srv.getObjectTypeID("CarnivorousPlant")
	}
	return obj.objTypeInd() == srv.types.fast.plant
}

func (obj *Object) findOwnerChainPlayer() *Object { // nox_xxx_findParentChainPlayer_4EC580
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

func (obj *Object) dropAllItems() {
	C.nox_xxx_dropAllItems_4EDA40((*C.uint)(unsafe.Pointer(obj.CObj())))
}

func (obj *Object) sub548600(dp types.Pointf) {
	mass := obj.Mass()
	obj.float_24 += C.float(dp.X / mass)
	obj.float_25 += C.float(dp.Y / mass)
}
