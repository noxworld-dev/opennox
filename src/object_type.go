package opennox

/*
#include "common/alloc/classes/alloc_class.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_3.h"
#include "GAME5.h"
extern nox_alloc_class* nox_alloc_gameObject_1563344;

static void nox_call_objectType_new_go(void (*fnc)(nox_object_t*), nox_object_t* arg1) { fnc(arg1); }
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.DefaultDamage = C.nox_xxx_damageDefaultProc_4E0B30
	server.DefaultDamageSound = C.nox_xxx_soundDefaultDamageSound_532E20
	server.DefaultXfer = C.nox_xxx_XFerDefault_4F49A0

	server.RegisterObjectCreate("MonsterCreate", C.nox_xxx_monsterCreateFn_54C480)
	server.RegisterObjectCreate("ArmorCreate", C.sub_54C950)
	server.RegisterObjectCreate("WeaponCreate", C.nox_xxx_createWeapon_54C710)
	server.RegisterObjectCreate("ObeliskCreate", C.nox_xxx_createFnObelisk_54CA10)
	server.RegisterObjectCreate("AnimCreate", C.nox_xxx_createFnAnim_54CA50)
	server.RegisterObjectCreate("TriggerCreate", C.nox_xxx_createTrigger_54CA60)
	server.RegisterObjectCreate("MonsterGeneratorCreate", C.nox_xxx_createMonsterGen_54CA90)
	server.RegisterObjectCreate("RewardMarkerCreate", C.nox_xxx_createRewardMarker_54CAC0)

	server.RegisterObjectInit("MonsterInit", C.nox_xxx_unitMonsterInit_4F0040, 0)
	server.RegisterObjectInit("PlayerInit", C.nox_xxx_unitInitPlayer_4EFE80, 0)
	server.RegisterObjectInit("SparkInit", C.nox_xxx_unitSparkInit_4F0390, 0)
	server.RegisterObjectInit("FrogInit", C.nox_xxx_initFrog_4F03B0, 0)
	server.RegisterObjectInit("ChestInit", C.nox_xxx_initChest_4F0400, 0)
	server.RegisterObjectInit("BoulderInit", C.nox_xxx_unitBoulderInit_4F0420, 0)
	server.RegisterObjectInit("BreakInit", C.nox_xxx_breakInit_4F0570, 0)
	server.RegisterObjectInit("MonsterGeneratorInit", C.nox_xxx_unitInitGenerator_4F0590, 0)
	server.RegisterObjectInit("ShopkeeperInit", C.nox_xxx_unitMonsterInit_4F0040, 1724)
	server.RegisterObjectInit("SkullInit", C.sub_4F0450, 8)
	server.RegisterObjectInit("DirectionInit", C.sub_4F0490, 8)
	server.RegisterObjectInit("GoldInit", C.nox_xxx_unitInitGold_4F04B0, 4)
}

//export nox_xxx_unitDefGetCount_4E3AC0
func nox_xxx_unitDefGetCount_4E3AC0() C.int {
	return C.int(noxServer.ObjectTypesCount())
}

//export nox_xxx_newObjectWithTypeInd_4E3450
func nox_xxx_newObjectWithTypeInd_4E3450(ind C.int) *nox_object_t {
	s := noxServer
	return s.newObject(s.ObjectTypeByInd(int(ind))).CObj()
}

//export nox_xxx_objectTypeByIndHealthData
func nox_xxx_objectTypeByIndHealthData(ind C.int) unsafe.Pointer {
	t := noxServer.ObjectTypeByInd(int(ind))
	if t == nil {
		return nil
	}
	return t.Health().C()
}

//export sub_4E4C50
func sub_4E4C50(cobj *nox_object_t) int {
	item := asObjectC(cobj)
	if item == nil {
		return 0
	}
	typ := noxServer.ObjectTypeByInd(item.objTypeInd())
	if typ == nil {
		return 0
	}
	return int(typ.InitDataSize)
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
	typ := noxServer.ObjectTypeByInd(obj.objTypeInd())
	if (obj.Flags()^typ.Flags())&0x11408162 != 0 {
		return -1
	}
	if (byte(obj.field_5)^byte(typ.Field9))&0x5E != 0 {
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
	typ := noxServer.ObjectTypeByInd(obj.objTypeInd())
	switch a2 {
	case 0x1:
		return bool2int(obj.field_33 != 0)
	case 0x2:
		health := obj.healthData()
		if health == nil {
			return 0
		}
		if typ == nil || typ.Health() == nil {
			return 0
		}
		return bool2int(typ.Health().Cur != health.Cur)
	case 0x4:
		return bool2int((uint32(obj.obj_flags)^uint32(typ.Flags())>>24)&1 != 0)
	case 0x8:
		return bool2int(typ.Field9 != uint32(obj.field_5))
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
	return C.int(bool2int(noxServer.ObjectTypeByInd(int(ind)).Allowed()))
}

//export nox_xxx_getUnitName_4E39D0
func nox_xxx_getUnitName_4E39D0(cobj *nox_object_t) *C.char {
	return internCStr(asObjectC(cobj).ObjectTypeC().ID())
}

//export sub_4E3B80
func sub_4E3B80(ind C.int) C.int {
	return C.int(bool2int(noxServer.ObjectTypeByInd(int(ind)).Icon != -1))
}

//export nox_xxx_getUnitNameByThingType_4E3A80
func nox_xxx_getUnitNameByThingType_4E3A80(ind C.int) *C.char {
	if ind == 0 {
		return nil
	}
	return internCStr(noxServer.ObjectTypeByInd(int(ind)).ID())
}

//export nox_objectTypeGetXfer
func nox_objectTypeGetXfer(cstr *C.char) unsafe.Pointer {
	t := noxServer.ObjectTypeByID(GoString(cstr))
	if t == nil {
		return nil
	}
	return t.Xfer
}

//export nox_objectTypeGetWorth
func nox_objectTypeGetWorth(cstr *C.char) C.int {
	t := noxServer.ObjectTypeByID(GoString(cstr))
	if t == nil {
		return -1
	}
	return C.int(t.Worth)
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
	return C.int(noxServer.ObjectTypeID(GoString(cstr)))
}

//export sub_415A30
func sub_415A30(a1 *C.char) C.int {
	t := sub415A30(GoString(a1))
	if t == nil {
		return -1
	}
	return C.int(t.Ind())
}

//export sub_415EC0
func sub_415EC0(a1 *C.char) C.int {
	t := sub415EC0(GoString(a1))
	if t == nil {
		return -1
	}
	return C.int(t.Ind())
}

func (s *Server) FreeObjectTypes() {
	s.Server.FreeObjectTypes()
	nox_xxx_free_42BF80()
}

func (s *Server) newObjectByTypeInd(ind int) *Object { // nox_xxx_newObjectWithTypeInd_4E3450
	typ := s.ObjectTypeByInd(ind)
	if typ == nil {
		return nil
	}
	return s.newObject(typ)
}

func (s *Server) newObjectByTypeID(id string) *Object { // nox_xxx_newObjectByTypeID_4E3810
	typ := s.ObjectTypeByID(id)
	if typ == nil {
		return nil
	}
	return s.newObject(typ)
}

var _ = [1]struct{}{}[20-unsafe.Sizeof(server.HealthData{})]

func (s *Server) newObject(t *server.ObjectType) *Object {
	cobj := alloc.AsClassT[nox_object_t](unsafe.Pointer(C.nox_alloc_gameObject_1563344)).NewObject()
	*cobj = nox_object_t{
		net_code:     cobj.net_code,      // it is persisted by the allocator; so we basically reuse ID of the older object
		typ_ind:      C.ushort(t.Ind2()), // TODO: why is it setting it and then overwriting again?
		obj_class:    C.uint(t.Class()),
		obj_subclass: C.uint(t.SubClass()),
		obj_flags:    C.uint(t.Flags()),
		field_5:      C.uint(t.Field9),
		material:     C.ushort(t.Material()),
		experience:   C.float(t.Experience),
		worth:        C.uint(t.Worth),
		float_28:     C.float(t.Field13),
		mass:         C.float(t.Mass),
		zsize1:       C.float(t.ZSize1),
		zsize2:       C.float(t.ZSize2),
	}
	obj := asObjectC(cobj)
	*obj.getShape() = t.Shape
	if !obj.Flags().Has(object.FlagNoCollide) {
		C.nox_xxx_objectUnkUpdateCoords_4E7290(obj.CObj())
	}
	obj.weight = t.Weight
	obj.carry_capacity = uint16(t.CarryCap)
	obj.speed_cur = t.Speed
	obj.speed_2 = t.Speed2
	obj.float_138 = t.Float33
	obj.health_data = nil
	obj.field_38 = -1
	obj.typ_ind = uint16(t.Ind())
	if t.Health() != nil {
		data, _ := alloc.New(server.HealthData{})
		obj.health_data = data
		*data = *t.Health()
	}
	obj.func_init = t.Init
	if t.InitDataSize != 0 {
		data, _ := alloc.Make([]byte{}, t.InitDataSize)
		obj.init_data = unsafe.Pointer(&data[0])
		copy(data, unsafe.Slice((*byte)(t.InitData), t.InitDataSize))
	}
	obj.func_collide = t.Collide
	if t.CollideDataSize != 0 {
		data, _ := alloc.Make([]byte{}, t.CollideDataSize)
		obj.collide_data = unsafe.Pointer(&data[0])
		copy(data, unsafe.Slice((*byte)(t.CollideData), t.CollideDataSize))
	}
	obj.func_xfer = t.Xfer
	obj.func_use = t.Use
	if t.UseDataSize != 0 {
		data, _ := alloc.Make([]byte{}, t.UseDataSize)
		obj.use_data = unsafe.Pointer(&data[0])
		copy(data, unsafe.Slice((*byte)(t.UseData), t.UseDataSize))
	}
	obj.func_update = t.Update
	if t.UpdateDataSize != 0 {
		data, _ := alloc.Make([]byte{}, t.UpdateDataSize)
		obj.data_update = unsafe.Pointer(&data[0])
		copy(data, unsafe.Slice((*byte)(t.UpdateData), t.UpdateDataSize))
	}
	obj.func_pickup = t.Pickup
	obj.func_drop = t.Drop
	obj.func_damage = t.Damage
	obj.func_damage_sound = t.DamageSound
	obj.func_die = t.Death
	obj.field_190 = 0
	obj.die_data = t.DeathData
	obj.field_192 = -1
	if noxflags.HasGame(noxflags.GameFlag22|noxflags.GameFlag23) && (obj.Class().HasAny(0x20A02) || unsafe.Pointer(obj.func_xfer) == unsafe.Pointer(C.nox_xxx_XFerInvLight_4F5AA0) || obj.weight != 0xff) {
		obj.field_189, _ = alloc.Malloc(2572)
	}
	if t.Create != nil {
		C.nox_call_objectType_new_go((*[0]byte)(t.Create), obj.CObj())
	}
	if !noxflags.HasGame(noxflags.GameFlag22) {
		obj.script_id = int(s.NextObjectScriptID())
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

func (s *Server) createObject(t *server.ObjectType, p types.Pointf) script.Object {
	obj := s.newObject(t)
	if obj == nil {
		return nil
	}
	s.createObjectAt(obj, nil, p)
	if obj.Class().HasAny(object.MaskUnits) {
		return obj.AsUnit()
	}
	return obj
}
