package opennox

/*
#include "common/alloc/classes/alloc_class.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_3.h"
extern nox_alloc_class* nox_alloc_gameObject_1563344;

static void nox_call_objectType_new_go(void (*fnc)(nox_object_t*), nox_object_t* arg1) { fnc(arg1); }
*/
import "C"
import (
	"fmt"
	"math"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

//export nox_xxx_unitDefGetCount_4E3AC0
func nox_xxx_unitDefGetCount_4E3AC0() C.int {
	return C.int(len(noxServer.types.byInd))
}

//export nox_xxx_newObjectWithTypeInd_4E3450
func nox_xxx_newObjectWithTypeInd_4E3450(ind C.int) *nox_object_t {
	return noxServer.getObjectTypeByInd(int(ind)).newObject().CObj()
}

//export nox_xxx_objectTypeByIndHealthData
func nox_xxx_objectTypeByIndHealthData(ind C.int) unsafe.Pointer {
	t := noxServer.getObjectTypeByInd(int(ind))
	if t == nil {
		return nil
	}
	return unsafe.Pointer(t.health_data)
}

//export sub_4E4C50
func sub_4E4C50(cobj *nox_object_t) int {
	item := asObjectC(cobj)
	if item == nil {
		return 0
	}
	typ := noxServer.getObjectTypeByInd(item.objTypeInd())
	if typ == nil {
		return 0
	}
	return int(typ.init_data_size)
}

//export sub_4F40A0
func sub_4F40A0(a1 *nox_object_t) C.char {
	obj := asObjectC(a1)
	if obj == nil {
		return 0
	}
	if obj.ID() != "" {
		return -1
	}
	if obj.inv_first_item != nil {
		return -1
	}
	if obj.field_129 != nil {
		return -1
	}
	if byte(obj.field_13) != 0 {
		return -1
	}
	typ := noxServer.getObjectTypeByInd(obj.objTypeInd())
	if (uint32(obj.obj_flags)^typ.obj_flags)&0x11408162 != 0 {
		return -1
	}
	if (byte(obj.field_5)^byte(typ.field_9))&0x5E != 0 {
		return -1
	}
	if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
		v3 := GoString((*C.char)(obj.field_189))
		if v3 != "" {
			return -1
		}
	} else if noxflags.HasGame(noxflags.GameHost) && obj.field_192 != -1 {
		return -1
	}
	return 0
}

//export sub_4E4C90
func sub_4E4C90(a1 *nox_object_t, a2 uint) int {
	obj := asObjectC(a1)
	typ := noxServer.getObjectTypeByInd(obj.objTypeInd())
	switch a2 {
	case 0x1:
		return bool2int(obj.field_33 != 0)
	case 0x2:
		health := obj.healthData()
		if health == nil {
			return 0
		}
		if typ == nil || typ.health_data == nil {
			return 0
		}
		return bool2int(typ.health_data.cur != health.cur)
	case 0x4:
		return bool2int((uint32(obj.obj_flags)^typ.obj_flags>>24)&1 != 0)
	case 0x8:
		return bool2int(typ.field_9 != uint32(obj.field_5))
	case 0x40:
		return bool2int(obj.Z() != 0.0)
	case 0x80:
		return bool2int(obj.buffs != 0)
	case 0x200:
		return bool2int(obj.obj_class&0x13001000 != 0)
	case 0x400:
		return bool2int(obj.obj_class&2 != 0 && obj.obj_subclass&0x30 != 0)
	default:
		return 0
	}
}

//export nox_xxx_getUnitDefDd10_4E3BA0
func nox_xxx_getUnitDefDd10_4E3BA0(ind C.int) C.int {
	return C.int(noxServer.getObjectTypeByInd(int(ind)).allowed)
}

//export nox_xxx_getUnitName_4E39D0
func nox_xxx_getUnitName_4E39D0(cobj *nox_object_t) *C.char {
	return asObjectC(cobj).ObjectTypeC().id
}

//export sub_4E3B80
func sub_4E3B80(ind C.int) C.int {
	return C.int(bool2int(noxServer.getObjectTypeByInd(int(ind)).menu_icon != -1))
}

//export nox_xxx_getUnitNameByThingType_4E3A80
func nox_xxx_getUnitNameByThingType_4E3A80(ind C.int) *C.char {
	if ind == 0 {
		return nil
	}
	return noxServer.getObjectTypeByInd(int(ind)).id
}

//export nox_objectTypeGetXfer
func nox_objectTypeGetXfer(cstr *C.char) unsafe.Pointer {
	t := noxServer.getObjectTypeByID(GoString(cstr))
	if t == nil {
		return nil
	}
	return t.func_xfer
}

//export nox_objectTypeGetWorth
func nox_objectTypeGetWorth(cstr *C.char) C.int {
	t := noxServer.getObjectTypeByID(GoString(cstr))
	if t == nil {
		return -1
	}
	return C.int(t.worth)
}

//export nox_xxx_newObjectByTypeID_4E3810
func nox_xxx_newObjectByTypeID_4E3810(cstr *C.char) *nox_object_t {
	obj := noxServer.newObjectByTypeID(GoString(cstr))
	if obj == nil {
		return nil
	}
	return obj.CObj()
}

//export nox_xxx_getNameId_4E3AA0
func nox_xxx_getNameId_4E3AA0(cstr *C.char) C.int {
	return C.int(noxServer.getObjectTypeID(GoString(cstr)))
}

//export sub_415A30
func sub_415A30(a1 *C.char) C.int {
	t := sub415A30(GoString(a1))
	if t == nil {
		return -1
	}
	return C.int(t.ind)
}

//export sub_415EC0
func sub_415EC0(a1 *C.char) C.int {
	t := sub415EC0(GoString(a1))
	if t == nil {
		return -1
	}
	return C.int(t.ind)
}

func (s *Server) disableObject(typ *ObjectType) {
	s.types.crc ^= typ.allowed
	typ.allowed = 0
}

func (s *Server) enableObject(typ *ObjectType) {
	s.types.crc ^= typ.allowed
	typ.allowed = 1
	s.types.crc ^= 1
}

type serverObjTypes struct {
	first *ObjectType
	byInd []*ObjectType
	byID  map[string]*ObjectType
	crc   uint32
	fast  struct {
		frog      int
		rat       int
		fishSmall int
		fishBig   int
		plant     int
		polyp     int
		wisp      int
	}
}

func (s *serverObjTypes) nox_xxx_freeObjectTypes_4E2A20() {
	if s.first == nil && s.byID != nil {
		return
	}
	var next *ObjectType
	for typ := s.first; typ != nil; typ = next {
		next = typ.next
		if typ.id != nil {
			StrFree(typ.id)
			typ.id = nil
		}
		if typ.health_data != nil {
			alloc.Free(unsafe.Pointer(typ.health_data))
			typ.health_data = nil
		}
		if typ.collide_data != nil {
			C.free(unsafe.Pointer(typ.collide_data))
			typ.collide_data = nil
		}
		if typ.die_data != nil {
			C.free(unsafe.Pointer(typ.die_data))
			typ.die_data = nil
		}
		if typ.init_data != nil {
			C.free(unsafe.Pointer(typ.init_data))
			typ.init_data = nil
		}
		if typ.data_update != nil {
			if typ.Class().Has(object.ClassMonster) {
				ud := typ.updateDataMonster()
				if ud.field_119 != nil {
					C.free(unsafe.Pointer(ud.field_119))
				}
			}
			C.free(unsafe.Pointer(typ.data_update))
			typ.data_update = nil
		}
		if typ.use_data != nil {
			C.free(unsafe.Pointer(typ.use_data))
			typ.use_data = nil
		}
		alloc.Free(unsafe.Pointer(typ))
	}
	s.first = nil
	s.byInd = []*ObjectType{nil}
	s.byID = make(map[string]*ObjectType)
	s.crc = 0
	nox_xxx_free_42BF80()
}

func (s *serverObjTypes) Clear() {
	s.nox_xxx_freeObjectTypes_4E2A20()
}

func (s *serverObjTypes) readType(thg *things.Thing) error {
	typ, _ := alloc.New(ObjectType{})
	typ.id = CString(thg.Name)

	typ.ind = uint16(len(s.byInd))
	s.byInd = append(s.byInd, typ)

	typ.field_2 = 0
	typ.menu_icon = -1
	typ.obj_class = 0
	typ.obj_subclass = 0
	typ.obj_flags = 0
	typ.material = 0x4000
	typ.mass = 1.0
	typ.zsize1 = 0
	typ.zsize2 = 30.0
	typ.func_damage = C.nox_xxx_damageDefaultProc_4E0B30
	typ.func_damage_sound = C.nox_xxx_soundDefaultDamageSound_532E20
	typ.func_xfer = C.nox_xxx_XFerDefault_4F49A0
	typ.weight = 255
	typ.carry_capacity = uint16(thg.CarryCap)
	typ.shape = noxShape{}
	if thg.Mass != 0 {
		typ.mass = float32(thg.Mass)
	}
	if thg.Weight != 0 {
		typ.weight = byte(thg.Weight)
	}
	if thg.Price != nil {
		typ.worth = uint32(*thg.Price)
	}
	if thg.Experience != 0 {
		typ.experience = float32(thg.Experience)
	}
	if thg.ZSize != nil {
		v1, v2 := thg.ZSize.Bottom, thg.ZSize.Top
		if v2 < v1 {
			v2 = v1
		}
		typ.zsize1 = float32(v1)
		typ.zsize2 = float32(v2)
	}
	if thg.Speed != nil {
		fv := float32(float64(*thg.Speed) / 32)
		typ.float_33 = 0
		typ.speed = fv
		typ.speed_2 = fv
	}
	for _, s := range thg.Class {
		v, err := object.ParseClass(string(s))
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Ind(), err)
		}
		typ.obj_class |= uint32(v)
	}
	for _, s := range thg.SubClass {
		v, err := object.ParseSubClass(string(s))
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Ind(), err)
		}
		typ.obj_subclass |= uint32(v)
	}
	for _, s := range thg.Flags {
		v, err := object.ParseFlag(string(s))
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Ind(), err)
		}
		typ.obj_flags |= uint32(v)
	}
	if len(thg.Material) != 0 {
		for _, s := range thg.Material {
			v, err := object.ParseMaterial(string(s))
			if err != nil {
				thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Ind(), err)
			}
			typ.material |= uint16(v)
		}
	}
	if thg.Health != nil {
		if typ.health_data != nil {
			alloc.Free(unsafe.Pointer(typ.health_data))
		}
		data, _ := alloc.New(objectHealthData{})
		typ.health_data = data
		data.cur = uint16(*thg.Health)
		data.max = uint16(*thg.Health)
	}
	if thg.Menu != nil {
		typ.menu_icon = int32(thg.Menu.Ind)
	}
	switch v := thg.Extent.(type) {
	case nil:
		typ.shape.kind = shapeKindNone
	case things.Center:
		typ.shape.kind = shapeKindCenter
	case things.Circle:
		typ.shape.kind = shapeKindCircle
		typ.shape.circle.R = v.R
		typ.shape.circle.R2 = v.R * v.R
	case things.Box:
		typ.shape.kind = shapeKindBox
		typ.shape.box.W = v.W
		typ.shape.box.H = v.H
		typ.shape.box.Calc()
	default:
		return fmt.Errorf("unsupported shape type: %T", v)
	}
	if d := thg.OnCreate; d != nil {
		if err := nox_xxx_parseCreateProc_536830(typ, d); err != nil {
			return err
		}
	}
	if d := thg.OnInit; d != nil {
		if err := nox_xxx_parseInitProc_536930(typ, d); err != nil {
			return err
		}
	}
	if d := thg.OnUpdate; d != nil {
		if err := nox_xxx_parseUpdate_536620(typ, d); err != nil {
			return err
		}
	}
	if d := thg.OnCollide; d != nil {
		if err := nox_xxx_parseCollide_536EC0(typ, d); err != nil {
			return err
		}
	}
	if d := thg.OnUse; d != nil {
		if err := nox_xxx_parseUseFn_5363F0(typ, d); err != nil {
			return err
		}
	}
	if d := thg.OnDamage; d != nil {
		if err := nox_xxx_parseDamageFn_536C60(typ, d); err != nil {
			return err
		}
	}
	if d := thg.DamageSound; d != "" {
		if err := nox_xxx_parseDamageSound_536CF0(typ, d); err != nil {
			return err
		}
	}
	if d := thg.OnDie; d != nil {
		if err := nox_xxx_parseDieProc_536B80(typ, d); err != nil {
			return err
		}
	}
	if d := thg.OnDrop; d != nil {
		if err := nox_xxx_parseDrop_536A20(typ, d); err != nil {
			return err
		}
	}
	if d := thg.OnPickup; d != nil {
		if err := nox_xxx_parsePickup_536710(typ, d); err != nil {
			return err
		}
	}
	if d := thg.OnXfer; d != nil {
		if err := nox_xxx_parseXFer_5360A0(typ, d); err != nil {
			return err
		}
	}
	if d := thg.Draw; d != nil {
		if err := nox_xxx_parseDraw_535CD0(typ, d); err != nil {
			return err
		}
	}
	if typ.func_collide == nil {
		typ.obj_flags |= uint32(object.FlagNoCollide)
	}
	typ.field_5_0 = typ.ind
	typ.obj_flags |= uint32(object.FlagEnabled)
	if typ.Class().Has(object.ClassImmobile) {
		typ.mass = 1e10
	}
	if typ.Class().Has(object.ClassMissile) {
		typ.field_13 = 1.0
		typ.speed *= 2
		typ.speed_2 *= 2
	} else {
		typ.field_13 = 0.5
	}
	switch thg.Name {
	case "Boulder", "RollingBoulder", "BoulderIndestructible":
		typ.field_13 = 0.01
		typ.mass = 100.0
	case "Rock7":
		typ.mass = 0.25
	}
	if typ.Class().Has(object.ClassMonster) {
		ud := typ.updateDataMonster()
		ud.script_enemy_sighted_cb = -1
		ud.script_looking_for_enemy_cb = -1
		ud.script_death_cb = -1
	} else if typ.Class().Has(object.ClassTrigger) {
		ud := unsafe.Slice((*int32)(typ.data_update), 9)
		ud[6] = -1
		ud[8] = -1
		ud[4] = -1
	} else if typ.Class().Has(object.ClassHole) {
		*(*int32)(unsafe.Add(typ.collide_data, 4)) = -1
	}
	if typ.Class().HasAny(object.ClassWeapon | object.ClassArmor | object.ClassPlayer | object.ClassMonster) {
		if typ.health_data == nil {
			typ.health_data, _ = alloc.New(objectHealthData{})
		}
	}
	typ.allowed = 1
	typ.mass *= 10.0
	s.crc ^= s.nox_xxx_unitDefProtectMB_4E31A0(typ)
	typ.next = s.first
	s.first = typ
	s.byID[strings.ToLower(thg.Name)] = typ
	return nil
}

func (s *serverObjTypes) checkTypes() error {
	if err := s.checkObjSizes(); err != nil {
		return err
	}
	s.nox_xxx_protectUnitDefUpdateMB_4E3C20()
	return nil
}

func (s *serverObjTypes) checkObjSizes() error {
	const maxSize = 85
	for typ := s.first; typ != nil; typ = typ.next {
		if typ.Flags().Has(object.FlagNoCollide) {
			continue
		}
		shape := &typ.shape
		if shape.kind == shapeKindCircle {
			if sz := 2 * shape.circle.R; sz >= maxSize {
				return fmt.Errorf("object %q is too large: %v >= %v", typ.ID(), sz, maxSize)
			}
		} else if shape.kind == shapeKindBox {
			shape.box.Calc()
			if sz := shape.box.RightTop - shape.box.LeftBottom2; sz >= 85.0 {
				return fmt.Errorf("object %q is too large: %v >= %v", typ.ID(), sz, maxSize)
			} else if sz = shape.box.RightTop2 - shape.box.LeftBottom; sz >= 85.0 {
				return fmt.Errorf("object %q is too large: %v >= %v", typ.ID(), sz, maxSize)
			}
		}
	}
	return nil
}

func (s *serverObjTypes) sub_4E31E0(typ *ObjectType) uint32 {
	//unsigned short* v1;

	val := uint32(typ.field_5_0) ^ typ.obj_flags ^ typ.field_9 ^ math.Float32bits(typ.mass)
	if h := typ.health_data; h != nil {
		val ^= uint32(h.cur ^ h.max)
	}
	return val
}

func (s *serverObjTypes) nox_xxx_unitDefProtectMB_4E31A0(typ *ObjectType) uint32 {
	if typ == nil {
		return 0
	}
	val := uint32(typ.ind)
	val ^= typ.allowed
	val ^= s.sub_4E31E0(typ)
	val ^= protectBytes([]byte(typ.ID()))
	return val
}

func (s *serverObjTypes) nox_xxx_protectUnitDefUpdateMB_4E3C20() {
	val := uint32(0)
	for typ := s.first; typ != nil; typ = typ.next {
		val ^= s.nox_xxx_unitDefProtectMB_4E31A0(typ)
	}
	if val != s.crc {
		// TODO: there was a nop function here; what was it for?
	}
}

func (s *Server) getObjectTypeByID(id string) *ObjectType {
	id = strings.ToLower(id)
	return s.types.byID[id]
}

func (s *Server) getObjectTypeID(id string) int { // nox_xxx_getNameId_4E3AA0
	typ := s.getObjectTypeByID(id)
	if typ == nil {
		return 0
	}
	return typ.Ind()
}

func (s *Server) getObjectTypeByInd(ind int) *ObjectType {
	if ind == math.MaxUint16 {
		return nil
	}
	if ind < 0 || ind >= len(s.types.byInd) {
		return nil
	}
	return s.types.byInd[ind]
}

func (s *Server) getObjectTypes() (out []*ObjectType) {
	for _, typ := range s.types.byInd {
		if typ == nil {
			continue
		}
		out = append(out, typ)
	}
	return
}

func (s *Server) newObjectByTypeInd(ind int) *Object { // nox_xxx_newObjectWithTypeInd_4E3450
	typ := s.getObjectTypeByInd(ind)
	if typ == nil {
		return nil
	}
	return typ.newObject()
}

func (s *Server) newObjectByTypeID(id string) *Object { // nox_xxx_newObjectByTypeID_4E3810
	typ := s.getObjectTypeByID(id)
	if typ == nil {
		return nil
	}
	return typ.newObject()
}

var _ = [1]struct{}{}[20-unsafe.Sizeof(objectHealthData{})]

type objectHealthData struct {
	cur     uint16
	field2  uint16
	max     uint16
	field6  uint16
	field8  uint32
	field12 uint32
	field16 uint32
}

var _ = [1]struct{}{}[224-unsafe.Sizeof(ObjectType{})]

type ObjectType struct {
	ind               uint16            // 0, 0
	field_0_1         uint16            // 0, 2
	id                *C.char           // 1, 4
	field_2           uint32            // 2, 8
	menu_icon         int32             // 3, 12
	allowed           uint32            // 4, 16
	field_5_0         uint16            // 5, 20
	field_5_1         uint16            // 5, 22
	obj_class         uint32            // 6, 24
	obj_subclass      uint32            // 7, 28
	obj_flags         uint32            // 8, 32
	field_9           uint32            // 9, 36
	material          uint16            // 10, 40
	field_10_1        uint16            // 10, 42
	experience        float32           // 11, 44
	worth             uint32            // 12, 48
	field_13          float32           // 13, 52
	mass              float32           // 14, 56
	shape             noxShape          // 15, 60
	zsize1            float32           // 28, 112
	zsize2            float32           // 29, 116
	weight            byte              // 30, 120
	field_30_1        byte              // 30, 121
	carry_capacity    uint16            // 30, 122
	speed             float32           // 31, 124
	speed_2           float32           // 32, 128
	float_33          float32           // 33, 132
	health_data       *objectHealthData // 34, 136
	func_collide      unsafe.Pointer    // 35, 140
	collide_data      unsafe.Pointer    // 36, 144
	collide_data_size int32             // 37, 148
	func_damage       unsafe.Pointer    // 38, 152
	func_damage_sound unsafe.Pointer    // 39, 156
	func_die          unsafe.Pointer    // 40, 160
	die_data          unsafe.Pointer    // 41, 164
	func_drop         unsafe.Pointer    // 42, 168
	func_init         unsafe.Pointer    // 43, 172
	init_data         unsafe.Pointer    // 44, 176
	init_data_size    int32             // 45, 180
	func_pickup       unsafe.Pointer    // 46, 184
	func_update       unsafe.Pointer    // 47, 188
	data_update       unsafe.Pointer    // 48, 192
	data_update_size  int32             // 49, 196
	func_use          unsafe.Pointer    // 50, 200
	use_data          unsafe.Pointer    // 51, 204
	use_data_size     int32             // 52, 208
	func_xfer         unsafe.Pointer    // 53, 212
	func_new          unsafe.Pointer    // 54, 216
	next              *ObjectType       // 55, 220
}

func asObjectType(p *C.nox_objectType_t) *ObjectType {
	return asObjectTypeP(unsafe.Pointer(p))
}

func asObjectTypeP(p unsafe.Pointer) *ObjectType {
	return (*ObjectType)(p)
}

func (t *ObjectType) C() *C.nox_objectType_t {
	return (*C.nox_objectType_t)(unsafe.Pointer(t))
}

func (t *ObjectType) ID() string {
	return GoString(t.id)
}

func (t *ObjectType) Ind() int {
	if t == nil {
		return 0
	}
	return int(t.ind)
}

func (t *ObjectType) Class() object.Class {
	return object.Class(t.obj_class)
}

func (t *ObjectType) ArmorClass() object.ArmorClass {
	if !t.Class().Has(object.ClassArmor) {
		return 0
	}
	return object.ArmorClass(t.obj_subclass)
}

func (t *ObjectType) Flags() object.Flags {
	return object.Flags(t.obj_flags)
}

func (t *ObjectType) String() string {
	return fmt.Sprintf("ObjectType(%d,%q)", t.Ind(), t.ID())
}

func (t *ObjectType) newObject() *Object {
	s := noxServer
	cobj := alloc.AsClassT[nox_object_t](unsafe.Pointer(C.nox_alloc_gameObject_1563344)).NewObject()
	*cobj = nox_object_t{
		net_code:     cobj.net_code,         // it is persisted by the allocator; so we basically reuse ID of the older object
		typ_ind:      C.ushort(t.field_5_0), // TODO: why is it setting it and then overwriting again?
		obj_class:    C.uint(t.obj_class),
		obj_subclass: C.uint(t.obj_subclass),
		obj_flags:    C.uint(t.obj_flags),
		field_5:      C.uint(t.field_9),
		material:     C.ushort(t.material),
		experience:   C.float(t.experience),
		worth:        C.uint(t.worth),
		float_28:     C.float(t.field_13),
		mass:         C.float(t.mass),
		zsize1:       C.float(t.zsize1),
		zsize2:       C.float(t.zsize2),
	}
	obj := asObjectC(cobj)
	*obj.getShape() = t.shape
	if !obj.Flags().Has(object.FlagNoCollide) {
		C.nox_xxx_objectUnkUpdateCoords_4E7290(obj.CObj())
	}
	obj.weight = C.uchar(t.weight)
	obj.carry_capacity = C.ushort(t.carry_capacity)
	obj.speed_cur = C.float(t.speed)
	obj.speed_2 = C.float(t.speed_2)
	obj.float_138 = C.float(t.float_33)
	obj.health_data = nil
	obj.field_38 = -1
	obj.typ_ind = C.ushort(t.ind)
	if t.health_data != nil {
		data, _ := alloc.New(objectHealthData{})
		obj.health_data = unsafe.Pointer(data)
		*data = *t.health_data
	}
	obj.func_init = t.func_init
	if t.init_data_size != 0 {
		data, _ := alloc.Make([]byte{}, t.init_data_size)
		obj.init_data = unsafe.Pointer(&data[0])
		copy(data, unsafe.Slice((*byte)(t.init_data), t.init_data_size))
	}
	obj.func_collide = t.func_collide
	if t.collide_data_size != 0 {
		data, _ := alloc.Make([]byte{}, t.collide_data_size)
		obj.collide_data = unsafe.Pointer(&data[0])
		copy(data, unsafe.Slice((*byte)(t.collide_data), t.collide_data_size))
	}
	obj.func_xfer = (*[0]byte)(t.func_xfer)
	obj.func_use = t.func_use
	if t.use_data_size != 0 {
		data, _ := alloc.Make([]byte{}, t.use_data_size)
		obj.use_data = unsafe.Pointer(&data[0])
		copy(data, unsafe.Slice((*byte)(t.use_data), t.use_data_size))
	}
	obj.func_update = (*[0]byte)(t.func_update)
	if t.data_update_size != 0 {
		data, _ := alloc.Make([]byte{}, t.data_update_size)
		obj.data_update = unsafe.Pointer(&data[0])
		copy(data, unsafe.Slice((*byte)(t.data_update), t.data_update_size))
	}
	obj.func_pickup = t.func_pickup
	obj.func_drop = t.func_drop
	obj.func_damage = (*[0]byte)(t.func_damage)
	obj.func_damage_sound = t.func_damage_sound
	obj.func_die = t.func_die
	obj.field_190 = 0
	obj.die_data = t.die_data
	obj.field_192 = -1
	if noxflags.HasGame(noxflags.GameFlag22|noxflags.GameFlag23) && (obj.Class().HasAny(0x20A02) || unsafe.Pointer(obj.func_xfer) == unsafe.Pointer(C.nox_xxx_XFerInvLight_4F5AA0) || obj.weight != 0xff) {
		obj.field_189, _ = alloc.Malloc(2572)
	}
	if t.func_new != nil {
		C.nox_call_objectType_new_go((*[0]byte)(t.func_new), obj.CObj())
	}
	if !noxflags.HasGame(noxflags.GameFlag22) {
		obj.script_id = C.int(s.NextObjectScriptID())
	}
	if obj.Class().Has(object.ClassSimple) {
		*memmap.PtrUint32(0x5D4594, 1563888)++
	} else if obj.Class().Has(object.ClassImmobile) {
		*memmap.PtrUint32(0x5D4594, 1563892)++
	}
	v8 := *memmap.PtrUint32(0x5D4594, 1563900) + 1
	*memmap.PtrUint32(0x5D4594, 1563884)++
	*memmap.PtrUint32(0x5D4594, 1563900)++
	if *memmap.PtrInt32(0x5D4594, 1563900) > *memmap.PtrInt32(0x5D4594, 1563896) {
		*memmap.PtrUint32(0x5D4594, 1563896) = v8
	}
	return obj
}

func (t *ObjectType) CreateObject(p types.Pointf) script.Object {
	obj := t.newObject()
	if obj == nil {
		return nil
	}
	noxServer.createObjectAt(obj, nil, p)
	if obj.Class().HasAny(object.MaskUnits) {
		return obj.AsUnit()
	}
	return obj
}

func (t *ObjectType) updateDataPtr() unsafe.Pointer {
	return t.data_update
}

func (t *ObjectType) updateDataRaw() []byte {
	return unsafe.Slice((*byte)(t.data_update), int(t.data_update_size))
}

func (t *ObjectType) updateDataMonster() *MonsterUpdateData {
	if !t.Class().Has(object.ClassMonster) {
		panic(t.Class().String())
	}
	p := (*C.nox_object_Monster_data_t)(t.updateDataPtr())
	return (*MonsterUpdateData)(unsafe.Pointer(p))
}
