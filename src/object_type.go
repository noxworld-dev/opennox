package opennox

/*
#include "GAME3_2.h"
#include "GAME3_3.h"
*/
import "C"
import (
	"fmt"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"
)

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

func (t *ObjectType) updateDataRaw() []byte {
	return unsafe.Slice((*byte)(t.data_update), int(t.data_update_size))
}
