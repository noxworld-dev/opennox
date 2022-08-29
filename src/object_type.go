package opennox

/*
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_3.h"
extern uint32_t dword_5d4594_1563664;
extern nox_objectType_t* nox_xxx_objectTypes_head_1563660;
char* nox_xxx_unitDefByAlphabetAdd_4E3080(char* a1);
*/
import "C"
import (
	"fmt"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

//export nox_xxx_unitDefGetCount_4E3AC0
func nox_xxx_unitDefGetCount_4E3AC0() C.int {
	return C.int(memmap.Uint32(0x587000, 201384))
}

type serverObjTypes struct {
	fast struct {
		frog      int
		rat       int
		fishSmall int
		fishBig   int
		plant     int
		polyp     int
		wisp      int
	}
}

func (s *serverObjTypes) readType(thg *MemFile, buf []byte) error {
	typ, _ := alloc.New(ObjectType{})
	id, err := thg.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read object type: %w", err)
	}
	typ.id = CString(id)

	typ.ind = memmap.Uint16(0x587000, 201384)
	*memmap.PtrUint16(0x587000, 201384)++

	typ.field_2 = 0
	typ.menu_icon = -1
	typ.material = 0x4000
	typ.mass = 1.0
	typ.zsize1 = 0
	typ.zsize2 = 30.0
	typ.func_damage = C.nox_xxx_damageDefaultProc_4E0B30
	typ.func_damage_sound = C.nox_xxx_soundDefaultDamageSound_532E20
	typ.func_xfer = C.nox_xxx_XFerDefault_4F49A0
	typ.weight = 255
	if err := nox_thing_read_xxx_4E3220(thg, buf, typ); err != nil {
		return err
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
	switch id {
	case "Boulder", "RollingBoulder", "BoulderIndestructible":
		typ.field_13 = 0.01
		typ.mass = 100.0
	case "Rock7":
		typ.mass = 0.25
	}
	if typ.Class().Has(object.ClassMonster) {
		ud := typ.updateDataMonster()
		ud.field_309 = -1
		ud.field_307 = -1
		ud.field_317 = -1
	} else if typ.Class().Has(object.ClassTrigger) {
		ud := unsafe.Slice((*int32)(typ.data_update), 9)
		ud[6] = -1
		ud[8] = -1
		ud[4] = -1
	} else if typ.Class().Has(object.ClassHole) {
		*(*int32)(unsafe.Add(typ.collide_data, 4)) = -1
	}
	if typ.Class().HasAny(object.ClassWeapon | object.ClassArmor | object.ClassPlayer | object.ClassMonster) {
		if typ.data_34 == nil {
			typ.data_34, _ = alloc.Malloc(20)
		}
	}
	typ.field_4 = 1
	typ.mass *= 10.0
	C.dword_5d4594_1563664 ^= C.nox_xxx_unitDefProtectMB_4E31A0(typ.C())
	typ.next = asObjectType(C.nox_xxx_objectTypes_head_1563660)
	C.nox_xxx_objectTypes_head_1563660 = typ.C()
	C.nox_xxx_unitDefByAlphabetAdd_4E3080(typ.id)
	return nil
}

func (s *Server) getObjectTypeByID(id string) *ObjectType { // nox_xxx_objectTypeByID_4E3830
	cstr := CString(id)
	defer StrFree(cstr)
	p := C.nox_xxx_objectTypeByID_4E3830(cstr)
	if p == nil {
		return nil
	}
	return asObjectType(p)
}

func (s *Server) getObjectTypeID(id string) int { // nox_xxx_getNameId_4E3AA0
	typ := s.getObjectTypeByID(id)
	if typ == nil {
		return 0
	}
	return typ.Ind()
}

func (s *Server) getObjectTypeByInd(ind int) *ObjectType { // nox_xxx_objectTypeByInd_4E3B70
	if ind == math.MaxUint16 {
		return nil
	}
	if ind < 0 || ind >= int(C.nox_xxx_unitDefGetCount_4E3AC0()) {
		return nil
	}
	p := C.nox_xxx_objectTypeByInd_4E3B70(C.int(ind))
	if p == nil {
		return nil
	}
	return asObjectType(p)
}

func (s *Server) getObjectTypes() (out []*ObjectType) {
	for i := 0; i < int(C.nox_xxx_unitDefGetCount_4E3AC0()); i++ {
		typ := s.getObjectTypeByInd(i)
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

var _ = [1]struct{}{}[224-unsafe.Sizeof(ObjectType{})]

type ObjectType struct {
	ind               uint16         // 0, 0
	field_0_1         uint16         // 0, 2
	id                *C.char        // 1, 4
	field_2           uint32         // 2, 8
	menu_icon         int32          // 3, 12
	field_4           uint32         // 4, 16
	field_5_0         uint16         // 5, 20
	field_5_1         uint16         // 5, 22
	obj_class         uint32         // 6, 24
	obj_subclass      uint32         // 7, 28
	obj_flags         uint32         // 8, 32
	field_9           uint32         // 9, 36
	material          uint16         // 10, 40
	field_10_1        uint16         // 10, 42
	experience        float32        // 11, 44
	worth             uint32         // 12, 48
	field_13          float32        // 13, 52
	mass              float32        // 14, 56
	shape             noxShape       // 15, 60
	zsize1            float32        // 28, 112
	zsize2            float32        // 29, 116
	weight            byte           // 30, 120
	field_30_1        byte           // 30, 121
	carry_capacity    uint16         // 30, 122
	speed             float32        // 31, 124
	speed_2           float32        // 32, 128
	float_33          float32        // 33, 132
	data_34           unsafe.Pointer // 34, 136, TODO: data, *[20]byte
	func_collide      unsafe.Pointer // 35, 140
	collide_data      unsafe.Pointer // 36, 144
	collide_data_size int32          // 37, 148
	func_damage       unsafe.Pointer // 38, 152
	func_damage_sound unsafe.Pointer // 39, 156
	func_die          unsafe.Pointer // 40, 160
	die_data          unsafe.Pointer // 41, 164
	func_drop         unsafe.Pointer // 42, 168
	func_init         unsafe.Pointer // 43, 172
	init_data         unsafe.Pointer // 44, 176
	init_data_size    int32          // 45, 180
	func_pickup       unsafe.Pointer // 46, 184
	func_update       unsafe.Pointer // 47, 188
	data_update       unsafe.Pointer // 48, 192
	data_update_size  int32          // 49, 196
	func_use          unsafe.Pointer // 50, 200
	use_data          unsafe.Pointer // 51, 204
	use_data_size     int32          // 52, 208
	func_xfer         unsafe.Pointer // 53, 212
	func_new          unsafe.Pointer // 54, 216
	next              *ObjectType    // 55, 220
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

func (t *ObjectType) newObject() *Object { // nox_xxx_newObjectWithType_4E3470
	cobj := C.nox_xxx_newObjectWithType_4E3470(t.C())
	if cobj == nil {
		return nil
	}
	return asObjectC(cobj)
}

func (t *ObjectType) CreateObject(p types.Pointf) script.Object {
	obj := t.newObject()
	if obj == nil {
		return nil
	}
	nox_xxx_createAt_4DAA50(obj, nil, p)
	if obj.Class().Has(object.MaskUnits) {
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
