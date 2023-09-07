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
	server.DefaultDamage = nox_xxx_damageDefaultProc_4E0B30
	server.DefaultDamageSound = nox_xxx_soundDefaultDamageSound_532E20
	server.DefaultXfer = nox_xxx_XFerDefault_4F49A0

	server.RegisterObjectCreate("MonsterCreate", nox_xxx_monsterCreateFn_54C480)
	server.RegisterObjectCreate("ArmorCreate", sub_54C950)
	server.RegisterObjectCreate("WeaponCreate", nox_xxx_createWeapon_54C710)
	server.RegisterObjectCreate("ObeliskCreate", nox_xxx_createFnObelisk_54CA10)
	server.RegisterObjectCreate("AnimCreate", nox_xxx_createFnAnim_54CA50)
	server.RegisterObjectCreate("TriggerCreate", nox_xxx_createTrigger_54CA60)
	server.RegisterObjectCreate("MonsterGeneratorCreate", nox_xxx_createMonsterGen_54CA90)
	server.RegisterObjectCreate("RewardMarkerCreate", nox_xxx_createRewardMarker_54CAC0)

	server.RegisterObjectInit("MonsterInit", nox_xxx_unitMonsterInit_4F0040, 0)
	server.RegisterObjectInit("PlayerInit", nox_xxx_unitInitPlayer_4EFE80, 0)
	server.RegisterObjectInit("SparkInit", nox_xxx_unitSparkInit_4F0390, 0)
	server.RegisterObjectInit("FrogInit", nox_xxx_initFrog_4F03B0, 0)
	server.RegisterObjectInit("ChestInit", nox_xxx_initChest_4F0400, 0)
	server.RegisterObjectInit("BoulderInit", nox_xxx_unitBoulderInit_4F0420, 0)
	server.RegisterObjectInit("BreakInit", nox_xxx_breakInit_4F0570, 0)
	server.RegisterObjectInit("MonsterGeneratorInit", nox_xxx_unitInitGenerator_4F0590, 0)
	server.RegisterObjectInit("ShopkeeperInit", nox_xxx_unitMonsterInit_4F0040, unsafe.Sizeof(server.ShopkeeperInitData{}))
	server.RegisterObjectInit("SkullInit", sub_4F0450, unsafe.Sizeof(server.SkullInitData{}))
	server.RegisterObjectInit("DirectionInit", sub_4F0490, unsafe.Sizeof(server.DirectionInitData{}))
	server.RegisterObjectInit("GoldInit", nox_xxx_unitInitGold_4F04B0, unsafe.Sizeof(server.GoldInitData{}))
}

// nox_xxx_unitDefGetCount_4E3AC0
func nox_xxx_unitDefGetCount_4E3AC0() int { return GetServer().S().Types.Count() }

// nox_xxx_newObjectWithTypeInd_4E3450
func nox_xxx_newObjectWithTypeInd_4E3450(ind int32) *server.Object {
	s := GetServer().S()
	return asObjectC(s.Objs.NewObject(s.Types.ByInd(int(ind))))
}

// nox_xxx_objectTypeByIndHealthData
func nox_xxx_objectTypeByIndHealthData(ind int32) *server.HealthData {
	t := GetServer().S().Types.ByInd(int(ind))
	if t == nil {
		return nil
	}
	return t.Health()
}

// sub_4E4C50
func sub_4E4C50(cobj *server.Object) int32 {
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
func sub_4F40A0(a1 *server.Object) int8 { return GetServer().S().Sub_4F40A0(asObjectS(a1)) }

// sub_4E4C90
func sub_4E4C90(a1 *server.Object, a2 uint32) int32 {
	return bool2int32(Sub_4E4C90(asObjectS(a1), uint(a2)))
}

// nox_xxx_getUnitDefDd10_4E3BA0
func nox_xxx_getUnitDefDd10_4E3BA0(ind int32) int32 {
	return bool2int32(GetServer().S().Types.ByInd(int(ind)).Allowed())
}

// nox_xxx_getUnitName_4E39D0
func nox_xxx_getUnitName_4E39D0(cobj *server.Object) *byte {
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

func nox_objectTypeGetXfer(cstr *byte) unsafe.Pointer {
	t := GetServer().S().Types.ByID(GoString(cstr))
	if t == nil {
		return nil
	}
	return t.Xfer.Ptr()
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
func nox_xxx_newObjectByTypeID_4E3810(cstr *byte) *server.Object {
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
