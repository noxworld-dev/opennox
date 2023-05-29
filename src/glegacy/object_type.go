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
	server.RegisterObjectInit("ShopkeeperInit", nox_xxx_unitMonsterInit_4F0040, 1724)
	server.RegisterObjectInit("SkullInit", sub_4F0450, 8)
	server.RegisterObjectInit("DirectionInit", sub_4F0490, 8)
	server.RegisterObjectInit("GoldInit", nox_xxx_unitInitGold_4F04B0, 4)
}

// nox_xxx_unitDefGetCount_4E3AC0
func nox_xxx_unitDefGetCount_4E3AC0() int { return GetServer().S().Types.Count() }

// nox_xxx_newObjectWithTypeInd_4E3450
func nox_xxx_newObjectWithTypeInd_4E3450(ind int) *nox_object_t {
	s := GetServer().S()
	return asObjectC(s.Objs.NewObject(s.Types.ByInd(ind)))
}

// nox_xxx_objectTypeByIndHealthData
func nox_xxx_objectTypeByIndHealthData(ind int) unsafe.Pointer {
	t := GetServer().S().Types.ByInd(ind)
	if t == nil {
		return nil
	}
	return t.Health().C()
}

// sub_4E4C50
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

// sub_4F40A0
func sub_4F40A0(a1 *nox_object_t) char { return char(GetServer().S().Sub_4F40A0(asObjectS(a1))) }

// sub_4E4C90
func sub_4E4C90(a1 *nox_object_t, a2 uint) int { return bool2int(Sub_4E4C90(asObjectS(a1), a2)) }

// nox_xxx_getUnitDefDd10_4E3BA0
func nox_xxx_getUnitDefDd10_4E3BA0(ind int) int {
	return bool2int(GetServer().S().Types.ByInd(ind).Allowed())
}

// nox_xxx_getUnitName_4E39D0
func nox_xxx_getUnitName_4E39D0(cobj *nox_object_t) *char {
	return internCStr(GetServer().S().Types.ByInd(int(asObjectS(cobj).TypeInd)).ID())
}

// sub_4E3B80
func sub_4E3B80(ind int) int { return bool2int(Sub_4E3B80(ind)) }

// nox_xxx_getUnitNameByThingType_4E3A80
func nox_xxx_getUnitNameByThingType_4E3A80(ind int) *char {
	if ind == 0 {
		return nil
	}
	return internCStr(GetServer().S().Types.ByInd(ind).ID())
}

// nox_objectTypeGetXfer
func nox_objectTypeGetXfer(cstr *char) unsafe.Pointer {
	t := GetServer().S().Types.ByID(GoString(cstr))
	if t == nil {
		return nil
	}
	return t.Xfer
}

// nox_objectTypeGetWorth
func nox_objectTypeGetWorth(cstr *char) int {
	t := GetServer().S().Types.ByID(GoString(cstr))
	if t == nil {
		return -1
	}
	return t.Worth
}

// nox_xxx_newObjectByTypeID_4E3810
func nox_xxx_newObjectByTypeID_4E3810(cstr *char) *nox_object_t {
	obj := GetServer().NewObjectByTypeID(GoString(cstr))
	if obj == nil {
		return nil
	}
	return asObjectC(obj)
}

// nox_xxx_getNameId_4E3AA0
func nox_xxx_getNameId_4E3AA0(cstr *char) int {
	return GetServer().S().Types.IndByID(GoString(cstr))
}

// sub_415A30
func sub_415A30(a1 *char) int {
	t := Sub415A30(GoString(a1))
	if t == nil {
		return -1
	}
	return t.Ind()
}

// sub_415EC0
func sub_415EC0(a1 *char) int {
	t := Sub415EC0(GoString(a1))
	if t == nil {
		return -1
	}
	return t.Ind()
}

func Get_nox_xxx_XFerInvLight_4F5AA0() unsafe.Pointer {
	return unsafe.Pointer(nox_xxx_XFerInvLight_4F5AA0)
}
func Nox_call_objectType_new_go(a1 unsafe.Pointer, a2 *server.Object) {
	nox_call_objectType_new_go((*[0]byte)(a1), asObjectC(a2))
}
