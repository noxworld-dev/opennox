package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Sub_4E4C90 func(a1 *server.Object, a2 uint) bool
	Sub_4E3B80 func(ind int) bool
	Sub415A30  func(a1 string) *server.ObjectType
	Sub415EC0  func(id string) *server.ObjectType
)

func init() {
	server.DefaultDamage = funAddrP(nox_xxx_damageDefaultProc_4E0B30)
	server.DefaultDamageSound = funAddrP(nox_xxx_soundDefaultDamageSound_532E20)
	server.DefaultXfer = funAddrP(nox_xxx_XFerDefault_4F49A0)

	server.RegisterObjectCreate("MonsterCreate", funAddrP(nox_xxx_monsterCreateFn_54C480))
	server.RegisterObjectCreate("ArmorCreate", funAddrP(sub_54C950))
	server.RegisterObjectCreate("WeaponCreate", funAddrP(nox_xxx_createWeapon_54C710))
	server.RegisterObjectCreate("ObeliskCreate", funAddrP(nox_xxx_createFnObelisk_54CA10))
	server.RegisterObjectCreate("AnimCreate", funAddrP(nox_xxx_createFnAnim_54CA50))
	server.RegisterObjectCreate("TriggerCreate", funAddrP(nox_xxx_createTrigger_54CA60))
	server.RegisterObjectCreate("MonsterGeneratorCreate", funAddrP(nox_xxx_createMonsterGen_54CA90))
	server.RegisterObjectCreate("RewardMarkerCreate", funAddrP(nox_xxx_createRewardMarker_54CAC0))

	server.RegisterObjectInit("MonsterInit", funAddrP(nox_xxx_unitMonsterInit_4F0040), 0)
	server.RegisterObjectInit("PlayerInit", funAddrP(nox_xxx_unitInitPlayer_4EFE80), 0)
	server.RegisterObjectInit("SparkInit", funAddrP(nox_xxx_unitSparkInit_4F0390), 0)
	server.RegisterObjectInit("FrogInit", funAddrP(nox_xxx_initFrog_4F03B0), 0)
	server.RegisterObjectInit("ChestInit", funAddrP(nox_xxx_initChest_4F0400), 0)
	server.RegisterObjectInit("BoulderInit", funAddrP(nox_xxx_unitBoulderInit_4F0420), 0)
	server.RegisterObjectInit("BreakInit", funAddrP(nox_xxx_breakInit_4F0570), 0)
	server.RegisterObjectInit("MonsterGeneratorInit", funAddrP(nox_xxx_unitInitGenerator_4F0590), 0)
	server.RegisterObjectInit("ShopkeeperInit", funAddrP(nox_xxx_unitMonsterInit_4F0040), 1724)
	server.RegisterObjectInit("SkullInit", funAddrP(sub_4F0450), 8)
	server.RegisterObjectInit("DirectionInit", funAddrP(sub_4F0490), 8)
	server.RegisterObjectInit("GoldInit", funAddrP(nox_xxx_unitInitGold_4F04B0), 4)
}

// nox_xxx_unitDefGetCount_4E3AC0
func nox_xxx_unitDefGetCount_4E3AC0() int { return GetServer().S().Types.Count() }

// nox_xxx_newObjectWithTypeInd_4E3450
func nox_xxx_newObjectWithTypeInd_4E3450(ind int32) *nox_object_t {
	s := GetServer().S()
	return asObjectC(s.Objs.NewObject(s.Types.ByInd(int(ind))))
}

// nox_xxx_objectTypeByIndHealthData
func nox_xxx_objectTypeByIndHealthData(ind int32) unsafe.Pointer {
	t := GetServer().S().Types.ByInd(int(ind))
	if t == nil {
		return nil
	}
	return t.Health().C()
}

// sub_4E4C50
func sub_4E4C50(cobj *nox_object_t) int32 {
	item := asObjectS(cobj)
	if item == nil {
		return 0
	}
	typ := GetServer().S().Types.ByInd(int(item.TypeInd))
	if typ == nil {
		return 0
	}
	return int32(typ.InitDataSize)
}

// sub_4F40A0
func sub_4F40A0(a1 *nox_object_t) int8 { return int8(GetServer().S().Sub_4F40A0(asObjectS(a1))) }

// sub_4E4C90
func sub_4E4C90(a1 *nox_object_t, a2 uint32) int32 {
	return bool2int32(Sub_4E4C90(asObjectS(a1), uint(a2)))
}

// nox_xxx_getUnitDefDd10_4E3BA0
func nox_xxx_getUnitDefDd10_4E3BA0(ind int32) int32 {
	return bool2int32(GetServer().S().Types.ByInd(int(ind)).Allowed())
}

// nox_xxx_getUnitName_4E39D0
func nox_xxx_getUnitName_4E39D0(cobj *nox_object_t) *byte {
	return internCStr(GetServer().S().Types.ByInd(int(asObjectS(cobj).TypeInd)).ID())
}

// sub_4E3B80
func sub_4E3B80(ind int32) int32 { return bool2int32(Sub_4E3B80(int(ind))) }

// nox_xxx_getUnitNameByThingType_4E3A80
func nox_xxx_getUnitNameByThingType_4E3A80(ind int32) *byte {
	if ind == 0 {
		return nil
	}
	return internCStr(GetServer().S().Types.ByInd(int(ind)).ID())
}

// nox_objectTypeGetXfer
func nox_objectTypeGetXfer(cstr *byte) unsafe.Pointer {
	t := GetServer().S().Types.ByID(GoString(cstr))
	if t == nil {
		return nil
	}
	return t.Xfer
}

// nox_objectTypeGetWorth
func nox_objectTypeGetWorth(cstr *byte) int32 {
	t := GetServer().S().Types.ByID(GoString(cstr))
	if t == nil {
		return -1
	}
	return int32(t.Worth)
}

// nox_xxx_newObjectByTypeID_4E3810
func nox_xxx_newObjectByTypeID_4E3810(cstr *byte) *nox_object_t {
	obj := GetServer().NewObjectByTypeID(GoString(cstr))
	if obj == nil {
		return nil
	}
	return asObjectC(obj)
}

// nox_xxx_getNameId_4E3AA0
func nox_xxx_getNameId_4E3AA0(cstr *byte) int32 {
	return int32(GetServer().S().Types.IndByID(GoString(cstr)))
}

// sub_415A30
func sub_415A30(a1 *byte) int32 {
	t := Sub415A30(GoString(a1))
	if t == nil {
		return -1
	}
	return int32(t.Ind())
}

// sub_415EC0
func sub_415EC0(a1 *byte) int32 {
	t := Sub415EC0(GoString(a1))
	if t == nil {
		return -1
	}
	return int32(t.Ind())
}

func Get_nox_xxx_XFerInvLight_4F5AA0() unsafe.Pointer {
	return funAddrP(nox_xxx_XFerInvLight_4F5AA0)
}
func Nox_call_objectType_new_go(a1 unsafe.Pointer, a2 *server.Object) {
	asFuncT[func(*nox_object_t)](uintptr(a1))(asObjectC(a2))
}
