package nox

/*
#include "GAME3_3.h"
#include "defs.h"
extern nox_object_t* nox_server_objects_1556844;
extern nox_object_t* nox_server_objects_uninited_1556860;
extern nox_object_t* nox_server_objects_updatable2_1556848;
static void nox_call_obj_update_go(void (*fnc)(nox_object_t*), nox_object_t* obj) { fnc(obj); }
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/object"
	"nox/v1/common/types"
	"nox/v1/server/script"
)

func asPointf(p unsafe.Pointer) types.Pointf {
	cp := (*C.float2)(p)
	return types.Pointf{
		X: float32(cp.field_0),
		Y: float32(cp.field_4),
	}
}
func asPoint(p unsafe.Pointer) types.Point {
	cp := (*C.nox_point)(p)
	return types.Point{
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

func firstServerObject() *Object { // nox_server_getFirstObject_4DA790
	return asObjectC(C.nox_server_objects_1556844)
}

func firstServerObjectUpdatable2() *Object { // nox_xxx_getFirstUpdatable2Object_4DA840
	return asObjectC(C.nox_server_objects_updatable2_1556848)
}

func firstServerObjectUninited() *Object { // nox_server_getFirstObjectUninited_4DA870
	return asObjectC(C.nox_server_objects_uninited_1556860)
}

func getObjects() []*Object {
	var out []*Object
	for p := firstServerObject(); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func getObjectsUpdatable2() []*Object {
	var out []*Object
	for p := firstServerObjectUpdatable2(); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func getObjectsUninited() []*Object {
	var out []*Object
	for p := firstServerObjectUninited(); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func getObjectByID(id string) *Object {
	for obj := firstServerObject(); obj != nil; obj = obj.Next() {
		if p := obj.findByID(id); p != nil {
			return p
		}
	}
	for obj := firstServerObjectUninited(); obj != nil; obj = obj.Next() {
		if p := obj.findByID(id); p != nil {
			return p
		}
	}
	return nil
}

func getObjectByInd(ind int) *Object { // aka nox_xxx_netGetUnitByExtent_4ED020
	for p := firstServerObject(); p != nil; p = p.Next() {
		if p.Flags16()&0x20 == 0 && p.Ind() == ind {
			return p
		}
	}
	return nil
}

func getObjectGroupByID(id string) *script.ObjectGroup {
	g := getMapGroupByID(id, 0)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Object
	for wp := g.FirstItem(); wp != nil; wp = wp.Next() {
		ind := int(*(*int32)(wp.Payload()))
		if wl := getObjectByInd(ind); wl != nil {
			list = append(list, wl)
		}
	}
	return script.NewObjectGroup(id, list...)
}

type nox_object_t = C.nox_object_t

type noxObject interface {
	CObj() *nox_object_t
}

type Object nox_object_t

func (obj *Object) UniqueKey() uintptr {
	return uintptr(unsafe.Pointer(obj))
}

func (obj *Object) CObj() *nox_object_t {
	return (*nox_object_t)(unsafe.Pointer(obj))
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
		for _, p := range getPlayers() {
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

func (obj *Object) ArmorClass() object.ArmorClass {
	if !obj.Class().Has(object.ClassArmor) {
		return 0
	}
	return object.ArmorClass(obj.field_3)
}

func (obj *Object) Flags16() uint32 {
	return uint32(obj.field_4)
}

func (obj *Object) SetFlags16(v uint32) {
	obj.field_4 = C.uint(v)
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

func (obj *Object) Next() *Object {
	return asObject(unsafe.Pointer(obj.field_111))
}

func (obj *Object) FirstItem() *Object {
	return asObject(unsafe.Pointer(obj.field_126))
}

func (obj *Object) NextItem() *Object {
	return asObject(unsafe.Pointer(obj.field_124))
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

func (obj *Object) AsUnit() *Unit {
	// TODO: check somehow
	return asUnit(unsafe.Pointer(obj))
}

func (obj *Object) ObjectTypeC() *ObjectType {
	if obj == nil {
		return nil
	}
	ind := obj.objTypeInd()
	return getObjectTypeByInd(ind)
}

func (obj *Object) ObjectType() script.ObjectType {
	t := obj.ObjectTypeC()
	if t == nil {
		return nil
	}
	return t
}

func (obj *Object) OwnerC() *Object {
	p := *(*unsafe.Pointer)(obj.field(508))
	return asObject(p)
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

func (obj *Object) newPos() types.Pointf {
	return types.Pointf{
		X: float32(obj.new_x),
		Y: float32(obj.new_y),
	}
}

func (obj *Object) SetPos(p types.Pointf) {
	pp, free := alloc.Malloc(unsafe.Sizeof(C.float2{}))
	defer free()
	cp := (*C.float2)(pp)
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
	C.nox_xxx_delayedDeleteObject_4E5CC0(obj.CObj())
}

func (obj *Object) Destroy() {
	panic("implement me")
}

func (obj *Object) callUpdate() {
	if obj.func_update != nil {
		C.nox_call_obj_update_go((*[0]byte)(obj.func_update), obj.CObj())
	}
}
