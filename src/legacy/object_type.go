package legacy

/*
#include "common/alloc/classes/alloc_class.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_3.h"
#include "GAME5.h"

static void nox_call_objectType_new_go(void (*fnc)(nox_object_t*), nox_object_t* arg1) { fnc(arg1); }
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Sub_4E3B80 func(ind int) bool
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
func nox_xxx_unitDefGetCount_4E3AC0() int { return GetServer().S().Types.Count() }

//export nox_xxx_newObjectWithTypeInd_4E3450
func nox_xxx_newObjectWithTypeInd_4E3450(ind int) *nox_object_t {
	s := GetServer().S()
	return asObjectC(s.Objs.NewObject(s.Types.ByInd(ind)))
}

//export nox_xxx_objectTypeByIndHealthData
func nox_xxx_objectTypeByIndHealthData(ind int) unsafe.Pointer {
	t := GetServer().S().Types.ByInd(ind)
	if t == nil {
		return nil
	}
	return t.Health().C()
}

//export sub_4E4C50
func sub_4E4C50(cobj *nox_object_t) int {
	item := asObjectS(cobj)
	if item == nil {
		return 0
	}
	typ := GetServer().S().Types.ByInd(int(item.TypeInd))
	if typ == nil {
		return 0
	}
	return int(typ.InitDataSize)
}

//export sub_4F40A0
func sub_4F40A0(a1 *nox_object_t) C.char { return C.char(GetServer().S().Sub_4F40A0(asObjectS(a1))) }

//export sub_4E4C90
func sub_4E4C90(a1 *nox_object_t, a2 uint) int { return bool2int(asObjectS(a1).Sub_4E4C90(a2)) }

//export nox_xxx_getUnitDefDd10_4E3BA0
func nox_xxx_getUnitDefDd10_4E3BA0(ind int) int {
	return bool2int(GetServer().S().Types.ByInd(ind).Allowed())
}

//export nox_xxx_getUnitName_4E39D0
func nox_xxx_getUnitName_4E39D0(cobj *nox_object_t) *C.char {
	return internCStr(GetServer().S().Types.ByInd(int(asObjectS(cobj).TypeInd)).ID())
}

//export sub_4E3B80
func sub_4E3B80(ind int) int { return bool2int(Sub_4E3B80(ind)) }

//export nox_xxx_getUnitNameByThingType_4E3A80
func nox_xxx_getUnitNameByThingType_4E3A80(ind int) *C.char {
	if ind == 0 {
		return nil
	}
	return internCStr(GetServer().S().Types.ByInd(ind).ID())
}

//export nox_objectTypeGetXfer
func nox_objectTypeGetXfer(cstr *C.char) unsafe.Pointer {
	t := GetServer().S().Types.ByID(GoString(cstr))
	if t == nil {
		return nil
	}
	return t.Xfer
}

//export nox_objectTypeGetWorth
func nox_objectTypeGetWorth(cstr *C.char) int {
	t := GetServer().S().Types.ByID(GoString(cstr))
	if t == nil {
		return -1
	}
	return t.Worth
}

//export nox_xxx_newObjectByTypeID_4E3810
func nox_xxx_newObjectByTypeID_4E3810(cstr *C.char) *nox_object_t {
	obj := GetServer().S().NewObjectByTypeID(GoString(cstr))
	if obj == nil {
		return nil
	}
	return asObjectC(obj)
}

//export nox_xxx_getNameId_4E3AA0
func nox_xxx_getNameId_4E3AA0(cstr *C.char) int {
	return GetServer().S().Types.IndByID(GoString(cstr))
}

//export sub_415A30
func sub_415A30(a1 *C.char) int {
	t := GetServer().S().Sub415A30(GoString(a1))
	if t == nil {
		return -1
	}
	return t.Ind()
}

//export sub_415EC0
func sub_415EC0(a1 *C.char) int {
	t := GetServer().S().Sub415EC0(GoString(a1))
	if t == nil {
		return -1
	}
	return t.Ind()
}

func Get_nox_xxx_XFerInvLight_4F5AA0() unsafe.Pointer {
	return unsafe.Pointer(C.nox_xxx_XFerInvLight_4F5AA0)
}
func Nox_call_objectType_new_go(a1 unsafe.Pointer, a2 *server.Object) {
	C.nox_call_objectType_new_go((*[0]byte)(a1), asObjectC(a2))
}
