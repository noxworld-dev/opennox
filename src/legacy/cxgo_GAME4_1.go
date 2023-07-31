package legacy

import (
	"math"
	"unicode"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_xxx_wallSounds_2386840 uint32 = 0
var dword_5d4594_2386176 unsafe.Pointer = nil
var nox_monsterBin_head_2386924 *server.MonsterDef

func sub_5098A0() {
	var (
		v0  int32
		v1  int32
		v2  int32
		i   *byte
		v4  int32
		v6  int32
		v7  int32
		v8  int32
		v10 *byte
		v11 unsafe.Pointer
	)
	v0 = 0
	v11 = nil
	v10 = nil
	v1 = 0
	v2 = math.MinInt32
	for i = nox_server_teamFirst_418B10(); i != nil; i = (*byte)(unsafe.Pointer(nox_server_teamNext_418B60((*server.Team)(unsafe.Pointer(i))))) {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*13)))
		if v4 >= v2 {
			v1 = bool2int32(v4 == v2 && v0 != 0)
			v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*13)))
			v10 = i
			v0 = int32(uintptr(unsafe.Pointer(i)))
		}
	}
	v5 := nox_xxx_getFirstPlayerUnit_4DA7C0()
	if v5 != nil {
		for {
			v6 = int32(v5.UpdateData)
			if nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(v5), 48))) == 0 {
				v7 = int32(*(*uint32)(unsafe.Add(v6, 276)))
				if (int32(*(*uint8)(unsafe.Add(v7, 3680))) & 1) == 0 {
					v8 = int32(*(*uint32)(unsafe.Add(v7, 2136)))
					if v8 >= v2 {
						v1 = bool2int32(v8 == v2 && v11 != nil)
						v2 = v8
						v11 = unsafe.Pointer(v5)
					}
				}
			}
			v5 = nox_xxx_getNextPlayerUnit_4DA7F0(v5)
			if v5 == nil {
				break
			}
		}
		v0 = int32(uintptr(unsafe.Pointer(v10)))
	}
	nox_xxx_setGameFlags_40A4D0(8)
	if v1 != 0 {
		nox_xxx_netSendDMTeamWinner_4D8BF0(nil, 1)
		return
	}
	if v11 != nil {
		nox_xxx_netSendDMWinner_4D8B90((*server.Object)(v11), 1)
		return
	}
	if v0 != 0 {
		nox_xxx_netSendDMTeamWinner_4D8BF0(v0, 1)
	}
}
func sub_5099B0() {
	var (
		v0 *server.Team
		v1 int32
		v2 int32
		v4 int32
	)
	v2 = -1
	for i := nox_server_teamFirst_418B10(); i != nil; i = nox_server_teamNext_418B60(i) {
		v4 = int32(i.Lessons)
		if v4 >= v2 {
			v1 = bool2int32(v4 == v2 && v0 != nil)
			v2 = int32(i.Lessons)
			v0 = i
		}
	}
	nox_xxx_setGameFlags_40A4D0(8)
	if v0 == nil || v1 != 0 {
		if noxflags.HasGame(64) {
			nox_xxx_netFlagballWinner_4D8C40(nil)
		} else {
			nox_xxx_netFlagWinner_4D8C40_4D8C80(nil, 1)
		}
	} else if noxflags.HasGame(64) {
		nox_xxx_netFlagballWinner_4D8C40(v0)
	} else {
		nox_xxx_netFlagWinner_4D8C40_4D8C80(v0, 1)
	}
}
func nox_server_checkVictory_509A60() {
	if noxflags.HasGame(1024) {
		var (
			v6 *byte  = nil
			v7 int16  = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
			v0 uint16 = uint16(nox_xxx_servGamedataGet_40A020(v7))
			v8        = int32(v0)
		)
		if v8 < 1 {
			return
		}
		var v9 unsafe.Pointer = nil
		for i := nox_xxx_getFirstPlayerUnit_4DA7C0(); i != nil; i = nox_xxx_getNextPlayerUnit_4DA7F0(i) {
			var v11 int32 = int32(*(*uint32)(unsafe.Add(i.UpdateData, 276)))
			if (int32(*(*uint8)(unsafe.Add(v11, 3680)))&1) == 0 && *(*uint32)(unsafe.Add(v11, 2140)) < uint32(v8) {
				if nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(i), 48))) != 0 {
					var v0 *byte = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(i.TeamVal.ID))))
					if v6 != nil {
						if v6 != v0 {
							return
						}
					} else {
						v6 = v0
					}
				} else {
					if v9 != nil || v6 != nil {
						return
					}
					v9 = unsafe.Pointer(i)
				}
			}
		}
		if nox_xxx_gamePlayIsAnyPlayers_40A8A0() == 0 {
			return
		}
		nox_xxx_setGameFlags_40A4D0(8)
		if v6 != nil {
			nox_xxx_netSendDMTeamWinner_4D8BF0(int32(uintptr(unsafe.Pointer(v6))), 0)
		} else if v9 != nil {
			nox_xxx_netSendDMWinner_4D8B90((*server.Object)(v9), 0)
		} else {
			nox_xxx_netSendDMWinner_4D8B90(nil, 0)
		}
		return
	}
	if noxflags.HasGame(512) {
		return
	}
	var v1 int16 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
	var v0a uint16 = uint16(nox_xxx_servGamedataGet_40A020(v1))
	var v2 int32 = int32(v0a)
	if int32(v0a) == 0 {
		return
	}
	for v3 := nox_server_teamFirst_418B10(); v3 != nil; v3 = nox_server_teamNext_418B60(v3) {
		if v3.Lessons >= int(v2) {
			nox_xxx_setGameFlags_40A4D0(8)
			nox_xxx_netSendDMTeamWinner_4D8BF0(v3, 0)
			return
		}
	}
	for v4 := nox_xxx_getFirstPlayerUnit_4DA7C0(); v4 != nil; v4 = nox_xxx_getNextPlayerUnit_4DA7F0(v4) {
		var v5 int32 = int32(*(*uint32)(unsafe.Add(v4.UpdateData, 276)))
		if (int32(*(*uint8)(unsafe.Add(v5, 3680)))&1) == 0 && *(*int32)(unsafe.Add(v5, 2136)) >= v2 {
			nox_xxx_setGameFlags_40A4D0(8)
			nox_xxx_netSendDMWinner_4D8B90(v4, 0)
			break
		}
	}
}
func sub_509C30(pl *server.Player) {
	var (
		a1 = pl
		v1 *byte
	)
	if dword_5d4594_1599688 == 0 {
		nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 1599676)))
		dword_5d4594_1599688 = 1
	}
	v1 = (*byte)(alloc.Calloc1(1, 0x20))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*6)) = a1.Field2068
	libc.StrCpy((*byte)(unsafe.Add(unsafe.Pointer(v1), 12)), (*byte)(unsafe.Add(unsafe.Pointer(a1), 2096)))
	*(*byte)(unsafe.Add(unsafe.Pointer(v1), 28)) = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 2251))
	sub_4257F0(mem_getI32Ptr(0x5D4594, 1599676), (*uint32)(unsafe.Pointer(v1)))
}
func sub_509CB0() *int32 {
	var (
		result *int32
		v1     *int32
		v2     *int32
	)
	result = dword_5d4594_1599688
	if dword_5d4594_1599688 == 0 {
		return result
	}
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1599676))))))
	v1 = result
	if result == nil {
		return result
	}
	for {
		v2 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v1)))))
		nox_common_list_remove_425920(unsafe.Pointer(v1))
		alloc.Free(v1)
		v1 = v2
		if v2 == nil {
			break
		}
	}
	return result
}
func sub_509CF0(a1 *byte, a2 int8, a3 int32) int32 {
	var v3 *int32
	v3 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1599676))))))
	if v3 == nil {
		return 1
	}
	for libc.StrCmp((*byte)(unsafe.Add(unsafe.Pointer(v3), 12)), a1) != 0 || int32(a2) == int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 28))) && a3 == *(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*6)) {
		v3 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v3)))))
		if v3 == nil {
			return 1
		}
	}
	return 0
}
func sub_509D80(a1 *server.Player) int32 {
	var v1 *int32
	v1 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1599676))))))
	if v1 == nil {
		return 0
	}
	for libc.StrCmp((*byte)(unsafe.Add(unsafe.Pointer(v1), 12)), &a1.Field2096Buf[0]) != 0 {
		v1 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v1)))))
		if v1 == nil {
			return 0
		}
	}
	return 1
}
func nox_xxx_xferDirectionToAngle_509E00(a1 *uint32) int32 {
	return int32(*memmap.PtrUint32(0x587000, uintptr((*a1+*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1))*3))*4+230072))
}
func nox_xxx_xferIndexedDirection_509E20(a1 int32, a2 *Point32) int32 {
	var (
		v2     int32
		v3     int32
		result int32
	)
	v2 = *memmap.PtrInt32(0x587000, uintptr(a1*8)+192088)
	if v2 <= dword_587000_230092 {
		a2.X = bool2int32(v2 >= -dword_587000_230092) - 1
	} else {
		a2.X = 1
	}
	v3 = *memmap.PtrInt32(0x587000, uintptr(a1*8)+192092)
	result = int32(dword_587000_230092)
	if v3 <= dword_587000_230092 {
		result = int32(-dword_587000_230092)
		if v3 >= -dword_587000_230092 {
			a2.Y = 0
		} else {
			a2.Y = -1
		}
	} else {
		a2.Y = 1
	}
	return result
}
func nox_xxx_mathDirection4ToAngle_509E90(a1 int32) int32 {
	return int32(*memmap.PtrUint32(0x587000, uintptr(a1*4)+230056))
}
func nox_xxx_math_509EA0(a1 int32) int32 {
	var a2 Point32
	nox_xxx_xferIndexedDirection_509E20(a1, &a2)
	return a2.Y + a2.X + a2.Y*2 + 4
}
func nox_xxx_math_509ED0(a1 *types.Pointf) int32 {
	var (
		result int32
		v2     float32
	)
	v2 = float32((math.Atan2(float64(a1.Y), float64(a1.X))+6.2831855)*40.743664 + 0.5)
	result = int32(v2)
	if result < 0 {
		result += int32(uint32(math.MaxUint8-result) >> 8 << 8)
	}
	if result >= 256 {
		result += int32((uint32(result) >> 8) * 4294967040)
	}
	return result
}
func nox_xxx_utilNormalizeVector_509F20(a1 *types.Pointf) {
	var v1 float64
	v1 = float64(float32(math.Sqrt(float64(a1.X*a1.X + a1.Y*a1.Y))))
	a1.X = float32(float64(a1.X) / v1)
	a1.Y = float32(float64(a1.Y) / v1)
}
func sub_509FF0(a1 unsafe.Pointer) {
	if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(a1), 16)))&0x20 != 0 {
		*(*uint32)(a1) = 0
	}
}
func nox_xxx_monsterActionIsCondition_50A010(a1 int32) int32 {
	var result int32
	result = bool2int32(a1 < 39)
	*(*uint8)(unsafe.Pointer(&result)) = uint8(int8(bool2int32(a1 > 39)))
	return result
}
func nox_xxx_mobActionGet_50A020(obj *server.Object) int32 {
	ud := obj.UpdateDataMonster()
	return int32(ud.AIStackHead().Action)
}
func sub_50A040(a1 *server.Object) int32 {
	ud := a1.UpdateDataMonster()
	for i := ud.AIStackInd; i >= 0; i-- {
		act := &ud.AIStack[i]
		if nox_xxx_monsterActionIsCondition_50A010(int32(act.Action)) == 0 {
			return int32(act.Action)
		}
	}
	return 38
}
func nox_xxx_monsterIsActionScheduled_50A090(a1 *server.Object, act ai.ActionType) int32 {
	ud := a1.UpdateDataMonster()
	for i := ud.AIStackInd - 1; i >= 0; i-- {
		if ud.AIStack[i].Action == act {
			return 1
		}
	}
	return 0
}
func nox_xxx_checkMobAction_50A0D0(obj *server.Object, act ai.ActionType) int32 {
	ud := obj.UpdateDataMonster()
	for i := ud.AIStackInd; i >= 0; i-- {
		if ud.AIStack[i].Action == act {
			return 1
		}
	}
	return 0
}
func nox_xxx_monsterAction_50A360(obj *server.Object, typ ai.ActionType) {
	if !obj.Class().Has(object.ClassMonster) {
		return
	}
	ud := obj.UpdateDataMonster()
	if ud.AIStackHead().Type() != typ {
		Nox_xxx_monsterPushAction_50A260_impl(obj, typ, 1)
	}
}
func nox_xxx_monsterCallDieFn_50A3D0(a1 *server.Object) {
	var (
		v5  int32
		v9  int32
		v10 int32
	)
	v1 := a1.UpdateData
	if noxflags.HasGame(4096) {
		sub_50E1E0(unsafe.Pointer(a1))
	}
	for i := nox_xxx_getFirstPlayerUnit_4DA7C0(); i != nil; i = nox_xxx_getNextPlayerUnit_4DA7F0(i) {
		if (*uint32)(unsafe.Pointer(nox_xxx_playerGetPossess_4DDF30(i))) == a1 {
			nox_xxx_playerObserveClear_4DDEF0(i)
		}
	}
	nox_xxx_monsterClearActionStack_50A3A0(a1)
	nox_xxx_monsterPushAction_50A260_impl(a1, 31)
	nox_xxx_monsterPushAction_50A260_impl(a1, 30)
	if nox_xxx_unitIsZombie_534A40(a1) != 0 {
		return
	}
	v4 := int32(a1.ObjFlags)
	*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 & math.MaxInt8))
	a1.ObjFlags = uint32(v4)
	nox_xxx_action_4DA9F0(a1)
	nox_xxx_unitClearBuffs_4FF580(a1)
	if int32(int8(*(*uint8)(unsafe.Add(v1, 1440)))) >= 0 {
		if !noxflags.HasGame(4096) {
			goto LABEL_13
		}
		v5 = nox_common_randomInt_415FA0(5, 8)
	} else {
		v5 = nox_common_randomInt_415FA0(10, 20)
	}
	nox_xxx_unitSetDecayTime_511660(a1, int32(gameFPS()*uint32(v5)))
LABEL_13:
	v6 := a1.ObjOwner
	if v6 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 8)))&4 != 0 {
		v7 := int32(a1.ObjSubClass)
		v8 := v6.UpdateData
		*(*uint8)(unsafe.Pointer(&v7)) = uint8(int8(v7 & math.MaxInt8))
		a1.ObjSubClass = uint32(v7)
		nox_xxx_netFxShield_0_4D9200(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v8, 276)), 2064))), a1)
		nox_xxx_netUnmarkMinimapObj_417300(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v8, 276)), 2064))), a1, 1)
	}
	v9 = int32(a1.ObjSubClass)
	*(*uint8)(unsafe.Add(unsafe.Pointer(&v9), 1)) &= 0xFE
	a1.ObjSubClass = uint32(v9)
	nox_xxx_unitTransferSlaves_4EC4B0(a1)
	nox_xxx_unitClearOwner_4EC300(a1)
	v10 = int32(a1.ObjSubClass)
	if (v10 & 0x2000) == 0 {
		nox_xxx_dropAllItems_4EDA40(a1)
	}
	if !noxflags.HasGame(2048) && *(*uint32)(unsafe.Add(v1, 2188)) == 2 && *(*uint32)(unsafe.Add(v1, 2184)) == 2 {
		if a1.Obj130 != nil {
			v11 := nox_xxx_findParentChainPlayer_4EC580(a1.Obj130)
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v11), 8)))&4 != 0 {
				sub_4FC0B0(v11, 1)
			}
		}
	}
	if noxflags.HasGame(4096) {
		v12 := a1.Obj130
		if v12 != nil {
			result := nox_xxx_findParentChainPlayer_4EC580(v12)
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(result), 8)))&4 != 0 {
				sub_4D6170(result)
			}
		}
	}
}
func nox_xxx_updateNPCAnimData_50A850(a1p *server.Object) int8 {
	var (
		a1 = unsafe.Pointer(a1p)
		v1 *uint8
		v2 *uint8
		v3 uint8
		v4 uint8
		v5 uint8
		v6 uint8
	)
	v1 = *(**uint8)(unsafe.Add(a1, 748))
	if int32(*(*uint8)(unsafe.Add(a1, 12)))&0x10 != 0 {
		v2 = *(**uint8)(unsafe.Add(unsafe.Pointer(v1), int32(int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 544))))*24+552))
		if uintptr(unsafe.Pointer(v2)) == uintptr(16) || uintptr(unsafe.Pointer(v2)) == uintptr(17) {
			*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 483)) = 0
			return int8(uintptr(unsafe.Pointer(v2)))
		}
	}
	*(*uint8)(unsafe.Pointer(&v2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v1), 483))
	if int32(uint8(uintptr(unsafe.Pointer(v2)))) != 0 {
		return int8(uintptr(unsafe.Pointer(v2)))
	}
	v2 = nox_xxx_unitNPCActionToAnim_533D00(a1)
	if v2 == nil {
		return int8(uintptr(unsafe.Pointer(v2)))
	}
	*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 480)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v2), 9))
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 9))) == 0 {
		*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 483)) = 1
		return int8(uintptr(unsafe.Pointer(v2)))
	}
	v3 = uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 482))) + 1))
	*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 482)) = v3
	if int32(v3) < int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 10)))+1 {
		return int8(uintptr(unsafe.Pointer(v2)))
	}
	v4 = *(*uint8)(unsafe.Add(unsafe.Pointer(v1), 481))
	*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 482)) = 0
	*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 481)) = func() uint8 {
		p := &v4
		*p++
		return *p
	}()
	v5 = v4
	v6 = *(*uint8)(unsafe.Add(unsafe.Pointer(v2), 9))
	if int32(v5) >= int32(v6) {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) != 0 {
			*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 481)) = 0
			return int8(uintptr(unsafe.Pointer(v2)))
		}
		*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 481)) = uint8(int8(int32(v6) - 1))
		*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 483)) = 1
		return int8(uintptr(unsafe.Pointer(v2)))
	}
	return int8(uintptr(unsafe.Pointer(v2)))
}

var aiActionsTable = []struct {
	Act  ai.ActionType
	Args []uint32
}{
	{Act: ai.ACTION_IDLE, Args: []uint32{5}},
	{Act: ai.ACTION_WAIT, Args: []uint32{5}},
	{Act: ai.ACTION_WAIT_RELATIVE, Args: []uint32{3}},
	{Act: ai.ACTION_ESCORT, Args: []uint32{0, 1}},
	{Act: ai.ACTION_GUARD, Args: []uint32{0, 3}},
	{Act: ai.ACTION_HUNT},
	{Act: ai.ACTION_RETREAT},
	{Act: ai.ACTION_MOVE_TO, Args: []uint32{0, 1}},
	{Act: ai.ACTION_FAR_MOVE_TO, Args: []uint32{0, 1}},
	{Act: ai.ACTION_DODGE, Args: []uint32{0}},
	{Act: ai.ACTION_ROAM, Args: []uint32{2, 7}},
	{Act: ai.ACTION_PICKUP_OBJECT},
	{Act: ai.ACTION_DROP_OBJECT},
	{Act: ai.ACTION_FIND_OBJECT},
	{Act: ai.ACTION_RETREAT_TO_MASTER},
	{Act: ai.ACTION_FIGHT, Args: []uint32{0, 5}},
	{Act: ai.ACTION_MELEE_ATTACK},
	{Act: ai.ACTION_MISSILE_ATTACK, Args: []uint32{0, 1}},
	{Act: ai.ACTION_CAST_SPELL_ON_OBJECT, Args: []uint32{3, 1}},
	{Act: ai.ACTION_CAST_SPELL_ON_LOCATION, Args: []uint32{3, 0}},
	{Act: ai.ACTION_CAST_DURATION_SPELL, Args: []uint32{3, 1}},
	{Act: ai.ACTION_BLOCK_ATTACK, Args: []uint32{5}},
	{Act: ai.ACTION_BLOCK_FINISH},
	{Act: ai.ACTION_WEAPON_BLOCK},
	{Act: ai.ACTION_FLEE, Args: []uint32{0, 1}},
	{Act: ai.ACTION_FACE_LOCATION, Args: []uint32{0}},
	{Act: ai.ACTION_FACE_OBJECT, Args: []uint32{1}},
	{Act: ai.ACTION_FACE_ANGLE, Args: []uint32{3}},
	{Act: ai.ACTION_SET_ANGLE, Args: []uint32{3}},
	{Act: ai.ACTION_RANDOM_WALK},
	{Act: ai.ACTION_DYING},
	{Act: ai.ACTION_DEAD},
	{Act: ai.ACTION_REPORT, Args: []uint32{3}},
	{Act: ai.ACTION_MORPH_INTO_CHEST},
	{Act: ai.ACTION_MORPH_BACK_TO_SELF},
	{Act: ai.ACTION_GET_UP},
	{Act: ai.ACTION_CONFUSED},
	{Act: ai.ACTION_MOVE_TO_HOME, Args: []uint32{0, 1}},
	{Act: ai.ACTION_INVALID},
	{Act: 0x27},
	{Act: ai.DEPENDENCY_OR},
	{Act: ai.DEPENDENCY_TIME, Args: []uint32{5}},
	{Act: ai.DEPENDENCY_ALIVE, Args: []uint32{1}},
	{Act: ai.DEPENDENCY_UNDER_ATTACK, Args: []uint32{5}},
	{Act: ai.DEPENDENCY_NOT_UNDER_ATTACK},
	{Act: ai.DEPENDENCY_CAN_SEE, Args: []uint32{1}},
	{Act: ai.DEPENDENCY_CANNOT_SEE, Args: []uint32{1}},
	{Act: ai.DEPENDENCY_BLOCKED_LINE_OF_FIRE, Args: []uint32{1}},
	{Act: ai.DEPENDENCY_OBJECT_AT_VISIBLE_LOCATION, Args: []uint32{0, 1}},
	{Act: ai.DEPENDENCY_OBJECT_FARTHER_THAN, Args: []uint32{4, 1}},
	{Act: ai.DEPENDENCY_OBJECT_CLOSER_THAN, Args: []uint32{4, 1}},
	{Act: ai.DEPENDENCY_LOCATION_FARTHER_THAN, Args: []uint32{4, 0}},
	{Act: ai.DEPENDENCY_LOCATION_CLOSER_THAN, Args: []uint32{4, 0}},
	{Act: ai.DEPENDENCY_VISIBLE_ENEMY},
	{Act: ai.DEPENDENCY_VISIBLE_FRIEND},
	{Act: ai.DEPENDENCY_VISIBLE_FOOD},
	{Act: ai.DEPENDENCY_NO_VISIBLE_ENEMY},
	{Act: ai.DEPENDENCY_NO_VISIBLE_FRIEND},
	{Act: ai.DEPENDENCY_NO_VISIBLE_FOOD},
	{Act: ai.DEPENDENCY_NO_INTERESTING_SOUND},
	{Act: ai.DEPENDENCY_NO_NEW_ENEMY, Args: []uint32{1}},
	{Act: ai.DEPENDENCY_UNINTERRUPTABLE},
	{Act: ai.DEPENDENCY_IS_ENCHANTED, Args: []uint32{3}},
	{Act: ai.DEPENDENCY_ENEMY_CLOSER_THAN, Args: []uint32{4}},
	{Act: ai.DEPENDENCY_NOT_HEALTHY},
	{Act: ai.DEPENDENCY_WAIT_FOR_STAMINA},
	{Act: ai.DEPENDENCY_ENEMY_FARTHER_THAN, Args: []uint32{4}},
	{Act: ai.DEPENDENCY_UNDER_CURSOR},
	{Act: ai.DEPENDENCY_NOT_CORNERED},
	{Act: ai.DEPENDENCY_LOCATION_IS_SAFE, Args: []uint32{0}},
	{Act: ai.DEPENDENCY_NOT_FRUSTRATED},
	{Act: ai.DEPENDENCY_NOT_MOVED},
}

func nox_xxx_mobAction_50A910(a1p *server.Object) int32 {
	ud := a1p.UpdateDataMonster()
	v1 := unsafe.Pointer(ud)
	v12 := v1
	if p := ud.Field304; p != nil && p.Flags().HasAny(0x8020) {
		ud.Field304 = nil
	}
	result := int32(ud.AIStackInd)
	if result < 0 {
		return -1
	}
	v4 := unsafe.Pointer(ud.AIStackHead())
	v13 := result + 1
	for {
		act := (*server.AIStackItem)(v4)
		tbl := &aiActionsTable[act.Action]
		for i, t := range tbl.Args {
			v6 := (*uint32)(unsafe.Pointer(&act.Args[2*i]))
			if t == 1 && *v6 != 0 {
				sub_509FF0(unsafe.Pointer(v6))
			}
		}
		v1 = v12
		switch act.Action {
		case ai.ACTION_ESCORT:
			if v7 := *(*unsafe.Pointer)(unsafe.Add(v4, 4*3)); v7 != nil {
				v11 := int32(*(*uint32)(unsafe.Add(v7, 56)))
				*(*uint32)(unsafe.Add(v4, 4*1)) = uint32(v11)
				*(*uint32)(unsafe.Add(v4, 4*2)) = *(*uint32)(unsafe.Add(v7, 60))
			}
		case ai.ACTION_MOVE_TO, ai.ACTION_FAR_MOVE_TO:
			if v10 := *(*unsafe.Pointer)(unsafe.Add(v4, 4*3)); v10 != nil {
				if nox_xxx_unitCanInteractWith_5370E0(a1p, (*server.Object)(v10), 0) != 0 || nox_xxx_checkMobAction_50A0D0(a1p, 3) != 0 {
					v7 := int32(*(*uint32)(unsafe.Add(v4, 4*3)))
					v11 := int32(*(*uint32)(unsafe.Add(v7, 56)))
					*(*uint32)(unsafe.Add(v4, 4*1)) = uint32(v11)
					*(*uint32)(unsafe.Add(v4, 4*2)) = *(*uint32)(unsafe.Add(v7, 60))
				} else {
					*(*uint32)(unsafe.Add(v4, 4*3)) = 0
				}
			}
		case ai.ACTION_FIGHT:
			if v7 := *(*unsafe.Pointer)(unsafe.Add(v1, 1196)); v7 != nil {
				v11 := int32(*(*uint32)(unsafe.Add(v7, 56)))
				*(*uint32)(unsafe.Add(v4, 4*1)) = uint32(v11)
				*(*uint32)(unsafe.Add(v4, 4*2)) = *(*uint32)(unsafe.Add(v7, 60))
			}
		case ai.ACTION_MISSILE_ATTACK:
			if v8 := *(*unsafe.Pointer)(unsafe.Add(v4, 4*3)); v8 != nil && nox_xxx_unitCanInteractWith_5370E0(a1p, (*server.Object)(v8), 0) != 0 {
				v9 := int32(*(*uint32)(unsafe.Add(v4, 4*3)))
				*(*uint32)(unsafe.Add(v4, 4*1)) = *(*uint32)(unsafe.Add(v9, 56))
				*(*uint32)(unsafe.Add(v4, 4*2)) = *(*uint32)(unsafe.Add(v9, 60))
			}
		}
		v4 = unsafe.Add(v4, -int(unsafe.Sizeof(server.AIStackItem{})))
		v13--
		result = v13
		if v13 == 0 {
			return result
		}
		v1 = v12
	}
}
func nox_xxx_minimapFirstMonster_50AAE0() int32 {
	var v0 int32
	v0 = nox_server_getFirstObject_4DA790()
	dword_5d4594_1599696 = uint32(v0)
	if v0 == 0 {
		return 0
	}
	for (int32(*(*uint8)(unsafe.Add(v0, 8))) & 2) == 0 {
		v0 = nox_server_getNextObject_4DA7A0((*server.Object)(v0))
		dword_5d4594_1599696 = uint32(v0)
		if v0 == 0 {
			return 0
		}
	}
	return v0 + 56
}
func nox_xxx_minimapNextMonster_50AB10() int32 {
	var v0 int32
	v0 = nox_server_getNextObject_4DA7A0((*server.Object)(dword_5d4594_1599696))
	dword_5d4594_1599696 = uint32(v0)
	if v0 == 0 {
		return 0
	}
	for (int32(*(*uint8)(unsafe.Add(v0, 8))) & 2) == 0 {
		v0 = nox_server_getNextObject_4DA7A0((*server.Object)(v0))
		dword_5d4594_1599696 = uint32(v0)
		if v0 == 0 {
			return 0
		}
	}
	return v0 + 56
}
func sub_50AB50(a1 int32, a2 int32) int16 {
	if a1 < 0 || a1 >= 256 || a2 < 0 || a2 >= 256 {
		return 0
	}
	return int16(nox_server_xxx_1599716[a2+(a1<<8)].field_8)
}
func nox_xxx_allocVisitNodesArray_50AB90() int32 {
	var result int32
	result = int32(uintptr(unsafe.Pointer(nox_new_alloc_class(internCStr("VisitNodes"), 16, 1024))))
	nox_alloc_visitNode_2386184 = result
	if result == 0 {
		return result
	}
	dword_5d4594_2386176 = alloc.Calloc1(1, 0x2000)
	if dword_5d4594_2386176 != nil {
		dword_5d4594_2386172 = 0
		result = 1
	} else {
		nox_free_alloc_class((*nox_alloc_class)(nox_alloc_visitNode_2386184))
		result = 0
	}
	return result
}
func sub_50ABF0() {
	alloc.FreePtr(dword_5d4594_2386176)
	nox_free_alloc_class((*nox_alloc_class)(nox_alloc_visitNode_2386184))
	nox_alloc_visitNode_2386184 = nil
}
func sub_50AC20(a3 int32, a2 *uint16) int32 {
	var (
		v2     *uint16
		v3     uint16
		v4     uint16
		v5     uint16
		v6     int16
		v7     *uint32
		v8     *uint16
		result int32
		v10    int32
		v11    int32
		v12    int32
		v13    int16
		v14    *uint16
		v15    int16
		v16    *uint16
		v17    float32
		v18    float32
		v19    float32
		v20    float32
		v21    int32
		a1     types.Pointf
	)
	v2 = (*uint16)(a3)
	v3 = *(*uint16)(unsafe.Add(a3, 2))
	a3 = int32(*(*uint16)(a3))
	v21 = int32(v3)
	if (int32(nox_server_xxx_1599716[int32(v3)+(a3<<8)].field_8) & 0x3C) == 0 {
		return 0
	}
	dword_5d4594_2386152 = 0
	v4 = *v2
	v5 = *(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*1))
	a1.X = float32(float64(a3) * 23.0)
	v6 = int16(nox_server_xxx_1599716[int32(v5)+(int32(v4)<<8)].field_8)
	a1.Y = float32(float64(v21) * 23.0)
	if int32(v6)&0x10 != 0 {
		a3 = 2048
		sub_517B70(&a1, sub_50AE80, unsafe.Pointer(&a3))
		if dword_5d4594_2386152 == 0 {
			return 0
		}
		v7 = (*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_2386152, 700)), 8))
		if *(*int32)(unsafe.Add(dword_5d4594_2386152, 700)) == -8 {
			return 0
		}
		if *(*uint32)(unsafe.Add(dword_5d4594_2386152, 16))&0x1000000 != 0 {
			v8 = a2
			*a2 = uint16(int16(int32(int16(*(*int32)(unsafe.Pointer(v7)))) / 23))
			result = 1
			*(*uint16)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1))) / 23))
			return result
		}
		return 0
	}
	if int32(v6)&0x20 != 0 {
		a3 = 1024
		sub_517B70(&a1, sub_50AE80, unsafe.Pointer(&a3))
		v10 = int32(dword_5d4594_2386152)
		if dword_5d4594_2386152 == 0 {
			return 0
		}
		v11 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_2386152, 748)), 12)))
		goto LABEL_18
	}
	if int32(v6)&4 != 0 {
		a3 = 0x4000
		sub_517B70(&a1, sub_50AE80, unsafe.Pointer(&a3))
		if dword_5d4594_2386152 == 0 {
			return 0
		}
		v12 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_2386152, 748)), 4)))
		if v12 == 0 {
			return 0
		}
		if *(*uint32)(unsafe.Add(dword_5d4594_2386152, 16))&0x1000000 != 0 {
			v17 = float32(float64(*(*float32)(unsafe.Add(v12, 56))) * 0.043478262)
			v13 = int16(int32(v17))
			v14 = a2
			*a2 = uint16(v13)
			v18 = float32(float64(*(*float32)(unsafe.Add(v12, 60))) * 0.043478262)
			*(*uint16)(unsafe.Add(unsafe.Pointer(v14), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(int32(v18)))
			return 1
		}
		return 0
	}
	if (int32(v6) & 8) == 0 {
		return 0
	}
	a3 = 0x8000
	sub_517B70(&a1, sub_50AE80, unsafe.Pointer(&a3))
	v10 = int32(dword_5d4594_2386152)
	if dword_5d4594_2386152 == 0 {
		return 0
	}
	v11 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_2386152, 748)), 4)))
LABEL_18:
	if v11 != 0 && *(*uint32)(unsafe.Add(v10, 16))&0x1000000 != 0 {
		v19 = float32(float64(*(*float32)(unsafe.Add(v11, 56))) * 0.043478262)
		v15 = int16(int32(v19))
		v16 = a2
		*a2 = uint16(v15)
		v20 = float32(float64(*(*float32)(unsafe.Add(v11, 60))) * 0.043478262)
		*(*uint16)(unsafe.Add(unsafe.Pointer(v16), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(int32(v20)))
		return 1
	}
	return 0
}
func sub_50AE80(it *server.Object, data unsafe.Pointer) {
	a1 := it
	a2 := int32(uintptr(data))
	if a1.ObjClass&*(*uint32)(a2) != 0 {
		dword_5d4594_2386152 = uint32(a1)
	}
}
func sub_50AEA0(a1 int32, a2 *types.Pointf, a3 *uint32) int32 {
	var (
		v3  *uint16
		v4  uint16
		v5  uint16
		v6  uint16
		v7  int16
		v9  int32
		a1a types.Pointf
	)
	v3 = (*uint16)(a1)
	v4 = *(*uint16)(unsafe.Add(a1, 2))
	a1 = int32(*(*uint16)(a1))
	v9 = int32(v4)
	if (int32(nox_server_xxx_1599716[int32(v4)+(a1<<8)].field_8) & 0x3C) == 0 {
		return 0
	}
	dword_5d4594_2386152 = 0
	v5 = *v3
	v6 = *(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*1))
	a1a.X = float32(float64(a1) * 23.0)
	v7 = int16(nox_server_xxx_1599716[int32(v6)+(int32(v5)<<8)].field_8)
	a1a.Y = float32(float64(v9) * 23.0)
	if int32(v7)&0x10 != 0 {
		a1 = 2048
	} else if int32(v7)&0x20 != 0 {
		a1 = 1024
	} else if int32(v7)&4 != 0 {
		a1 = 0x4000
	} else if int32(v7)&8 != 0 {
		a1 = 0x8000
	}
	sub_517B70(&a1a, sub_50AE80, unsafe.Pointer(&a1))
	if dword_5d4594_2386152 == 0 || (*(*uint32)(unsafe.Add(dword_5d4594_2386152, 16))&0x1000000) == 0 {
		return 0
	}
	*a2 = *(*types.Pointf)(unsafe.Add(dword_5d4594_2386152, 56))
	*a3 = *(*uint32)(unsafe.Add(dword_5d4594_2386152, 36))
	return 1
}
func nox_xxx_aiTestUnitDangerous_50B2C0(a1 int32) {
	var (
		v1     int32
		result int32
		v3     float64
		v4     int32
		v5     float64
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    *uint8
		v11    *float32
		v12    int32
		v13    int16
		v14    float32
		v15    float32
		v16    float32
		v17    float32
		v18    int32
		v19    int32
		v20    int32
		v21    float32
		v22    float32
		a2     types.Pointf
		v24    int32
		v25    [60]byte
		a1a    int32
	)
	v1 = a1
	result = int32(*(*uint32)(unsafe.Add(a1, 8)))
	if !((result&0xC080) == 0 && (result&0x2000 != 0 || (int32(*(*uint8)(unsafe.Add(a1, 16)))&0x49) == 0) && (result&0x2008 != 0 || int32(*(*uint8)(unsafe.Add(a1, 16)))&2 != 0)) {
		return result
	}
	if uint32(result)&0x10000 != 0 {
		alloc.Memcpy(unsafe.Pointer(&v25[0]), unsafe.Add(a1, 172), 60)
		if *(*uint32)(unsafe.Add(a1, 172)) == 2 {
			v3 = float64(dword_587000_234176 + *(*float32)(unsafe.Add(a1, 176)))
			*(*float32)(unsafe.Add(a1, 176)) = float32(v3)
			*(*float32)(unsafe.Add(a1, 180)) = float32(v3 * v3)
		} else if *(*uint32)(unsafe.Add(a1, 172)) == 3 {
			*(*float32)(unsafe.Add(a1, 184)) = dword_587000_234176 + dword_587000_234176 + *(*float32)(unsafe.Add(a1, 184))
			*(*float32)(unsafe.Add(a1, 188)) = dword_587000_234176 + dword_587000_234176 + *(*float32)(unsafe.Add(a1, 188))
			nox_shape_box_calc((*server.Shape)(unsafe.Add(a1, 172)))
		}
		nox_xxx_objectUnkUpdateCoords_4E7290((*server.Object)(a1))
	}
	v14 = float32(float64(*(*float32)(unsafe.Add(a1, 232))) * 0.043478262)
	v4 = int32(v14)
	v5 = float64(*(*float32)(unsafe.Add(a1, 236))) * 0.043478262
	v6 = v4
	v24 = v4
	v15 = float32(v5)
	v7 = int32(v15)
	v16 = float32(float64(*(*float32)(unsafe.Add(a1, 240))) * 0.043478262)
	v19 = int32(v16)
	v17 = float32(float64(*(*float32)(unsafe.Add(a1, 244))) * 0.043478262)
	v8 = int32(v17)
	v9 = v7
	v20 = v8
	for a1a = v7; v9 <= v8; a1a = v9 {
		v18 = v6
		if v6 <= v19 {
			v10 = (*uint8)(unsafe.Pointer(&nox_server_xxx_1599716[v9+(v6<<8)].field_8))
			for {
				v11 = mem_getFloatPtr(0x587000, 234108)
				for {
					v21 = float32(float64(v18) * 23.0)
					a2.X = v21 + *(*float32)(unsafe.Add(unsafe.Pointer(v11), -int(unsafe.Sizeof(float32(0))*1)))
					v22 = float32(float64(a1a) * 23.0)
					a2.Y = v22 + *v11
					if sub_547DB0(v1, &a2) != 0 {
						break
					}
					v11 = (*float32)(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(float32(0))*2))
					if int32(uintptr(unsafe.Pointer(v11))) >= int32(uintptr(memmap.PtrOff(0x587000, 234180))) {
						goto LABEL_25
					}
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v10), -int(4*1))) = dword_5d4594_2386164
				v12 = int32(*(*uint32)(unsafe.Add(v1, 8)))
				if v12&8 != 0 || int32(*(*uint8)(unsafe.Add(v1, 16)))&2 != 0 {
					v13 = int16(int32(*(*uint16)(unsafe.Pointer(v10))) | 0x100)
					*(*uint16)(unsafe.Pointer(v10)) = uint16(v13)
					if (int32(*(*uint8)(unsafe.Add(v1, 16))) & 0x10) == 0 {
						*(*uint8)(unsafe.Add(unsafe.Pointer(&v13), unsafe.Sizeof(int16(0))-1)) |= 2
						*(*uint16)(unsafe.Pointer(v10)) = uint16(v13)
					}
				} else if v12&0x2000 != 0 {
					*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 1)) |= 4
				}
			LABEL_25:
				v6++
				v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 3072))
				v18 = v6
				if v6 > v19 {
					break
				}
			}
			v9 = a1a
			v8 = v20
			v6 = v24
		}
		v9++
	}
	result = int32(*(*uint32)(unsafe.Add(v1, 8)))
	if uint32(result)&0x10000 != 0 {
		alloc.Memcpy(unsafe.Add(v1, 172), unsafe.Pointer(&v25[0]), 0x3C)
		nox_xxx_objectUnkUpdateCoords_4E7290((*server.Object)(v1))
	}
}
func sub_50B500() {
	dword_5d4594_2386168 = 0
}
func sub_50B510() {
	dword_5d4594_2386168 = 0
	dword_5d4594_2386172 = 0
}
func sub_50B520() {
	if (gameFrame() - dword_5d4594_2386172) < 0xF {
		return
	}
	dword_5d4594_2386172 = gameFrame()
	dword_5d4594_2386164++
	result := nox_server_getFirstObject_4DA790()
	for i := result; result != nil; i = result {
		nox_xxx_aiTestUnitDangerous_50B2C0(i)
		result = nox_server_getNextObject_4DA7A0(i)
	}
	dword_5d4594_2386168 = 1
}
func sub_50B810(a1 unsafe.Pointer, a2 *float32) int32 {
	var (
		v2     int32
		v3     int32
		result int32
		v5     float32
		v6     float32
	)
	v5 = float32(float64(*a2) * 0.043478262)
	v2 = int32(v5)
	v6 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) * 0.043478262)
	v3 = int32(v6)
	if sub_50B870(a1, v2, v3) != 0 {
		result = 0
	} else {
		result = nox_xxx_pathfind_preCheckWalls2_50B8A0(a1, v2, v3)
	}
	return result
}
func sub_50B870(a1 unsafe.Pointer, a2 int32, a3 int32) int32 {
	return bool2int32(int32(sub_57B630(a1, a2, a3)) != -1)
}
func nox_xxx_pathfind_preCheckWalls2_50B8A0(a1 unsafe.Pointer, a2 int32, a3 int32) int32 {
	var result int32
	if sub_50B950(a1, a2, a3) != 0 {
		result = 0
	} else {
		result = bool2int32(sub_50B8E0(a1, a2, a3) == 0)
	}
	return result
}
func sub_50B8E0(a1 unsafe.Pointer, a2 int32, a3 int32) uint32 {
	var (
		v4  uint32
		v5  int32
		ind int32 = (a3 + (a2 << 8))
	)
	if nox_server_xxx_1599716[ind].field_4 != dword_5d4594_2386164 {
		return 0
	}
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v4), unsafe.Sizeof(uint16(0))*1)) = *(*uint16)(unsafe.Add(unsafe.Pointer(&a1), unsafe.Sizeof(uint16(0))*1))
	v5 = int32(*(*uint32)(unsafe.Add(a1, 16)))
	if v5&0x4000 != 0 {
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v4), unsafe.Sizeof(uint16(0))*0)) = nox_server_xxx_1599716[ind].field_8
		return (v4 >> 9) & 1
	}
	if int32(nox_server_xxx_1599716[ind].field_8)&0x100 != 0 {
		return 1
	}
	if sub_534020(a1) != 0 || (int32(nox_server_xxx_1599716[ind].field_8)&0x400) == 0 {
		return 0
	}
	return 1
}
func sub_50B950(a1 unsafe.Pointer, a2 int32, a3 int32) int32 {
	var (
		v3     int32
		result int32
	)
	v3 = int32(*(*uint32)(unsafe.Add(a1, 16)))
	if v3&0x4000 != 0 {
		result = (int32(nox_server_xxx_1599716[a3+(a2<<8)].field_8) >> 1) & 0x1
	} else {
		result = int32(nox_server_xxx_1599716[a3+(a2<<8)].field_8) & 0x1
	}
	return result
}
func nox_xxx_genPathToPoint_50B9A0(a1 unsafe.Pointer, a2 int32, a3 unsafe.Pointer, a4 *float32) int32 {
	*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a3, 748)), 2172)) = 0
	nox_xxx_pathFind_50BA00(0, a3, (*float32)(unsafe.Add(a3, 56)), a4, nil, 0)
	if dword_5d4594_2386180 > uint32(a2) && dword_5d4594_1599712 == 0 {
		dword_5d4594_1599712 = 1
	}
	return nox_xxx_appendWorkPath_50C990(a1, 0, a2)
}
func nox_xxx_pathFind_50BA00(a1 int32, a2 unsafe.Pointer, a3 *float32, a4 *float32, a5 func(unsafe.Pointer, int32, int32) int32, a6 int32) {
	var (
		v6  int32
		v7  float64
		v8  int32
		v9  float64
		v11 *uint16
		v12 uint16
		v13 uint16
		v14 *uint16
		v15 *uint16
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 uint16
		v23 int32
		v24 int32
		v25 uint16
		v26 int32
		v27 float32
		v28 float32
		v29 int32
		v30 unsafe.Pointer
		v31 *uint16
		v32 *uint16
		v33 *uint16
		v34 *uint16
		v35 *uint16
		v36 int32
		v37 int32
		v38 bool
		v39 int32
		v40 int32
		v41 int32
		v42 int32
		v43 int32
		v44 int32
		v45 *uint16
		v46 *uint16
		v47 int32
		v48 int32
		v49 int32
		v50 int32
		v51 float32
		v52 float32
		v53 float32
		v54 float32
		v55 int32
		v56 int32
		v57 int32
		v58 int32
		v59 int32
		v60 int8
		v61 int32
		i   int32
		v63 int32
		v64 int32
		v65 int32
		v66 int32
		v67 int32
		v68 [2]int16
		v69 int32
		v70 int32
		v71 *uint8
		v72 *uint8
		v73 int32
		v74 int32
		a2a Point32
		v76 float4
		v77 *uint16
	)
	v67 = 0
	v64 = 0
	v65 = 0
	if a1 != 0 {
		v59 = 0
	} else {
		v59 = 999999
	}
	dword_5d4594_1599712 = 0
	dword_5d4594_2386160++
	if dword_5d4594_2386168 == 0 {
		sub_50B520()
	}
	v51 = float32(float64(*a3) * 0.043478262)
	v6 = int32(v51)
	v7 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))) * 0.043478262
	a2a.X = v6
	v52 = float32(v7)
	a2a.Y = int32(v52)
	nox_xxx_pathfind_preCheckWalls_50C8D0(a2, &a2a)
	v61 = 0
	v63 = bool2int32(nox_xxx_pathfind_preCheckWalls2_50B8A0(a2, a2a.X, a2a.Y) == 0)
	if a5 != nil && a5(a2, a2a.X, a2a.Y) == 0 {
		v61 = 1
	}
	v53 = float32(float64(*a4) * 0.043478262)
	v8 = int32(v53)
	v9 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a4), unsafe.Sizeof(float32(0))*1))) * 0.043478262
	v73 = v8
	v54 = float32(v9)
	v74 = int32(v54)
	if nox_alloc_visitNode_2386184 == nil {
		dword_5d4594_2386180 = 0
		dword_5d4594_1599712 = 2
		return
	}
	nox_alloc_class_free_all((*nox_alloc_class)(nox_alloc_visitNode_2386184))
	v11 = (*uint16)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_visitNode_2386184)))
	*v11 = uint16(int16(a2a.X))
	*(*uint16)(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(a2a.Y))
	v12 = *v11
	v13 = *(*uint16)(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(uint16(0))*1))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*1)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*2)) = 0
	v14 = v11
	v66 = 0
	nox_server_xxx_1599716[int32(v13)+(int32(v12)<<8)].field_0 = dword_5d4594_2386160
	for {
		v15 = v14
		v14 = nil
		v77 = nil
		if v15 == nil {
			goto LABEL_40
		}
		for {
			v16 = int32(*v15)
			v17 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1)))
			v18 = (int32(uint16(int16(v16)))-v73)*(int32(uint16(int16(v16)))-v73) + (int32(uint16(int16(v17)))-v74)*(int32(uint16(int16(v17)))-v74)
			if a1 != 0 {
				if v18 > v59 {
					v67 = int32(uintptr(unsafe.Pointer(v15)))
					v59 = (int32(uint16(int16(v16)))-v73)*(int32(uint16(int16(v16)))-v73) + (int32(uint16(int16(v17)))-v74)*(int32(uint16(int16(v17)))-v74)
				}
			} else {
				if v18 < v59 {
					v67 = int32(uintptr(unsafe.Pointer(v15)))
					v59 = (int32(uint16(int16(v16)))-v73)*(int32(uint16(int16(v16)))-v73) + (int32(uint16(int16(v17)))-v74)*(int32(uint16(int16(v17)))-v74)
				}
				if v63 == 0 && v61 == 0 && v16 == v73 && v17 == v74 {
					dword_5d4594_1599712 = 0
					sub_50C320(a2, int32(uintptr(unsafe.Pointer(v15))), (*uint32)(unsafe.Pointer(a4)))
					return
				}
			}
			v69 = nox_common_randomInt_415FA0(0, 7)
			for i = 0; i < 8; i++ {
				v19 = (i + v69) % 8
				v20 = int32(*memmap.PtrUint32(0x587000, uintptr(v19*8)+234216))
				v21 = int32(*memmap.PtrUint32(0x587000, uintptr(v19*8)+234220))
				v22 = *v15
				v72 = (*uint8)(memmap.PtrOff(0x587000, uintptr(v19*8)+234216))
				v23 = v20 + int32(v22)
				v24 = v21 + int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1)))
				v71 = (*uint8)(memmap.PtrOff(0x587000, uintptr(v19*8)+234220))
				if v23 < 0 || v23 >= 256 || v24 < 0 || v24 >= 256 || nox_server_xxx_1599716[v24+(v23<<8)].field_0 == dword_5d4594_2386160 {
					continue
				}
				nox_server_xxx_1599716[v24+(v23<<8)].field_0 = dword_5d4594_2386160
				if v23 == v73 && v24 == v74 {
					v25 = *(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1))
					v70 = int32(*v15)*23 + 11
					v76.field_0 = float32(float64(v70))
					v26 = int32(v25) * 23
					v27 = *a4
					v28 = *(*float32)(unsafe.Add(unsafe.Pointer(a4), unsafe.Sizeof(float32(0))*1))
					v70 = v26 + 11
					v76.field_8 = v27
					v76.field_4 = float32(float64(v26 + 11))
					v76.field_C = v28
					if nox_xxx_mapTraceObstacles_50B580((*server.Object)(a2), &v76) != 0 {
						v29 = int32(*(*uint32)(unsafe.Add(a2, 16)))
						if v29&0x4000 != 0 {
							if nox_xxx_mapTraceRay_535250(&v76, nil, nil, 5) != 0 {
								v30 = a2
								goto LABEL_32
							}
						} else if nox_xxx_mapTraceRay_535250(&v76, nil, nil, 1) != 0 {
							v30 = a2
							goto LABEL_32
						}
					}
				}
				if v19 < 4 {
					v30 = a2
				} else {
					v60 = int8(int32(uint16(int16(^(int32(*(*uint16)(unsafe.Add(a2, 16)))>>8))))&0xD8 | 0x98)
					sub_57B4D0((*server.Object)(a2))
					switch v19 {
					case 4:
						v36 = int32(uint8(sub_57B500(int32(*v15), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1)))+1, v60)))
						if v36 != 1 && v36 != 6 && v36 != 10 && v36 != 9 && v36 != math.MaxUint8 {
							continue
						}
						*(*uint8)(unsafe.Pointer(&v37)) = uint8(sub_57B500(int32(*v15)+1, int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1))), v60))
						v37 = int32(uint8(int8(v37)))
						if int32(uint8(int8(v37))) == 1 || v37 == 4 || v37 == 7 {
							goto LABEL_86
						}
						v38 = v37 == 8
					case 5:
						v39 = int32(uint8(sub_57B500(int32(*v15)-1, int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1))), v60)))
						if v39 != 1 && v39 != 6 && v39 != 10 && v39 != 9 && v39 != math.MaxUint8 {
							continue
						}
						*(*uint8)(unsafe.Pointer(&v37)) = uint8(sub_57B500(int32(*v15), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1)))-1, v60))
						v37 = int32(uint8(int8(v37)))
						if int32(uint8(int8(v37))) == 1 || v37 == 4 || v37 == 7 {
							goto LABEL_86
						}
						v38 = v37 == 8
					case 6:
						v40 = int32(uint8(sub_57B500(int32(*v15), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1)))+1, v60)))
						if v40 != 0 && v40 != 5 && v40 != 9 && v40 != 8 && v40 != math.MaxUint8 {
							continue
						}
						v37 = int32(uint8(sub_57B500(int32(*v15)-1, int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1))), v60)))
						if v37 == 0 || v37 == 3 || v37 == 10 {
							goto LABEL_86
						}
						v38 = v37 == 7
					case 7:
						v41 = int32(uint8(sub_57B500(int32(*v15)+1, int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1))), v60)))
						if v41 != 0 && v41 != 5 && v41 != 9 && v41 != 8 && v41 != math.MaxUint8 {
							continue
						}
						v42 = int32(uint8(sub_57B500(int32(*v15), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1)))-1, v60)))
						if v42 != 0 {
							if v42 != 3 && v42 != 10 && v42 != 7 && v42 != math.MaxUint8 {
								continue
							}
						}
						goto LABEL_86
					default:
						goto LABEL_86
					}
					if !v38 && v37 != math.MaxUint8 {
						continue
					}
				LABEL_86:
					v30 = a2
					if sub_50B950(a2, int32(*v15), int32(*(*uint32)(unsafe.Pointer(v71))+uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1))))) != 0 || sub_50B950(a2, int32(*(*uint32)(unsafe.Pointer(v72))+uint32(*v15)), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1)))) != 0 {
						continue
					}
				}
				if sub_50B870(v30, v23, v24) != 0 {
					continue
				}
				if v73 != v23 || v74 != v24 {
					if sub_50C830(v30, v23, v24) == 0 {
						continue
					}
				} else if sub_50C830(v30, v23, v24) == 0 {
					continue
				}
				v43 = nox_xxx_pathfind_preCheckWalls2_50B8A0(v30, v23, v24)
				if v63 != 0 {
					if v43 != 0 {
						v64 = 1
					} else if sub_50B950(v30, int32(*v15), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*1)))) == 0 && sub_50B950(v30, v23, v24) != 0 {
						continue
					}
				} else {
					if v43 == 0 {
						continue
					}
					if a5 != nil {
						v44 = a5(v30, v23, v24)
						if v61 != 0 {
							if v44 != 0 {
								v65 = 1
							}
						} else if v44 == 0 {
							continue
						}
					}
				}
			LABEL_32:
				v31 = (*uint16)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_visitNode_2386184)))
				if v31 == nil {
					v55 = int32(*(*uint32)(unsafe.Add(v30, 36)))
					v47 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*server.Object)(v30)))))
					nox_ai_debug_printf_5341A0(internCStr("%d: %s(#%d), buildPath: Exhausted search storage\n"), gameFrame(), v47, v55)
					dword_5d4594_1599712 = 1
					sub_50C320(v30, v67, nil)
					return
				}
				*v31 = uint16(int16(v23))
				*(*uint16)(unsafe.Add(unsafe.Pointer(v31), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(v24))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v31), 4*1)) = uint32(uintptr(unsafe.Pointer(v15)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v31), 4*2)) = uint32(uintptr(unsafe.Pointer(v77)))
				v77 = v31
			}
			if sub_50AC20(int32(uintptr(unsafe.Pointer(v15))), (*uint16)(unsafe.Pointer(&v68[0]))) != 0 {
				*(*uint8)(unsafe.Add(unsafe.Pointer(v15), 12)) |= 2
				v32 = (*uint16)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_visitNode_2386184)))
				if v32 == nil {
					v30 = a2
					v56 = int32(*(*uint32)(unsafe.Add(a2, 36)))
					v48 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*server.Object)(a2)))))
					nox_ai_debug_printf_5341A0(internCStr("%d: %s(#%d), buildPath: Exhausted search storage\n"), gameFrame(), v48, v56)
					dword_5d4594_1599712 = 1
					sub_50C320(v30, v67, nil)
					return
				}
				*(*uint32)(unsafe.Pointer(v32)) = *(*uint32)(unsafe.Pointer(&v68[0]))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*1)) = uint32(uintptr(unsafe.Pointer(v15)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*2)) = uint32(uintptr(unsafe.Pointer(v77)))
				v77 = v32
			}
			v15 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*2)))))
			if v15 != nil {
				continue
			}
			break
		}
		v14 = v77
	LABEL_40:
		v33 = nil
		if v64 != 0 {
			v34 = v14
			if v14 != nil {
				for {
					v35 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v34), 4*2)))))
					if nox_xxx_pathfind_preCheckWalls2_50B8A0(a2, int32(*v34), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v34), unsafe.Sizeof(uint16(0))*1)))) != 0 {
						v33 = v34
					} else if v33 != nil {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v33), 4*2)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v34), 4*2))
					} else {
						v14 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v34), 4*2)))))
					}
					v34 = v35
					if v35 == nil {
						break
					}
				}
				v33 = nil
			}
			v63 = 0
			v64 = 0
		}
		if v65 != 0 {
			v45 = v14
			if v14 != nil {
				for {
					v46 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v45), 4*2)))))
					if a5(a2, int32(*v45), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v45), unsafe.Sizeof(uint16(0))*1)))) != 0 {
						v33 = v45
					} else if v33 != nil {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v33), 4*2)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v45), 4*2))
					} else {
						v14 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v45), 4*2)))))
					}
					v45 = v46
					if v46 == nil {
						break
					}
				}
			}
			v61 = 0
			v65 = 0
		}
		if v14 != nil {
			if a6 != 0 && v66 >= a6 {
				v58 = int32(*(*uint32)(unsafe.Add(a2, 36)))
				v50 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*server.Object)(a2)))))
				nox_ai_debug_printf_5341A0(internCStr("%d: %s(#%d), buildPath: Reached search depth limit\n"), gameFrame(), v50, v58)
				v30 = a2
				dword_5d4594_1599712 = 2
				sub_50C320(v30, v67, nil)
				return
			}
			v66++
			continue
		}
		break
	}
	v57 = int32(*(*uint32)(unsafe.Add(a2, 36)))
	v49 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*server.Object)(a2)))))
	nox_ai_debug_printf_5341A0(internCStr("%d: %s(#%d), buildPath: Exhausted search space\n"), gameFrame(), v49, v57)
	v30b := a2
	dword_5d4594_1599712 = 2
	sub_50C320(v30b, v67, nil)
}
func sub_50C320(a1 unsafe.Pointer, a2 int32, a3 *uint32) {
	var (
		v4  *uint16
		v5  int32
		v6  *uint32
		v7  *uint16
		v8  int32
		v9  int32
		v10 int8
		v11 int32
		v12 int32
		v13 uint16
		v14 int32
		v15 uint16
		v16 int32
		v17 uint16
		v18 float64
		v19 float64
		v20 float64
		v21 int32
		v22 *uint32
		v23 *uint32
		v24 int32
		v25 int32
		v26 types.Pointf
		v27 float4
	)
	v4 = (*uint16)(a2)
	v5 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v25 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	if a2 == 0 {
		dword_5d4594_2386180 = 0
		return
	}
	v6 = a3
	if a3 != nil {
		*(*uint32)(unsafe.Add(dword_5d4594_2386176, 0)) = *a3
		*(*uint32)(unsafe.Add(dword_5d4594_2386176, 4)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
	} else if int32(*(*uint8)(unsafe.Add(a2, 12)))&2 != 0 && sub_50AEA0(a2, &v26, (*uint32)(unsafe.Pointer(&a1))) != 0 {
		*(*float32)(unsafe.Add(dword_5d4594_2386176, 0)) = v26.X
		*(*float32)(unsafe.Add(dword_5d4594_2386176, 4)) = v26.Y
		if int32(*(*uint8)(unsafe.Add(v5, 2172))) < 8 {
			*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(v5+int32(func() uint8 {
				p := (*uint8)(unsafe.Add(v5, 2172))
				x := *p
				*p++
				return x
			}())*4)), 2140)) = a1
		}
	} else {
		a2 = int32(*v4)
		*(*float32)(unsafe.Add(dword_5d4594_2386176, 0)) = float32(float64(a2)*23.0 + 11.5)
		a2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*1)))
		*(*float32)(unsafe.Add(dword_5d4594_2386176, 4)) = float32(float64(a2)*23.0 + 11.5)
	}
	v7 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))))
	v8 = 1
	if v7 != nil {
		for {
			v9 = int32(*v7) - int32(*v4)
			v10 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 12)))
			v11 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1))) - int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*1)))
			a2 = int32(*v7) - int32(*v4)
			if (int32(v10) & 2) != 0 {
				if sub_50AEA0(int32(uintptr(unsafe.Pointer(v7))), &v26, (*uint32)(unsafe.Pointer(&a1))) == 0 {
					v9 = a2
				} else {
					v12 = v25
					*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v8*8))) = v26.X
					*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176))+v8*8)), 4)) = v26.Y
					if int32(*(*uint8)(unsafe.Add(v25, 2172))) < 8 {
						a2 = a2*a2 + v11*v11
						if float64(a2) > 4761.0 {
							*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(v12+int32(func() uint8 {
								p := (*uint8)(unsafe.Add(v12, 2172))
								x := *p
								*p++
								return x
							}())*4)), 2140)) = a1
							goto LABEL_38
						}
						v13 = *(*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1))
						a2 = int32(*v7)*23 + 11
						v14 = int32(v13) * 23
						v15 = *v4
						v27.field_0 = float32(float64(a2))
						a2 = v14 + 11
						v16 = int32(v15) * 23
						v17 = *(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*1))
						v27.field_4 = float32(float64(v14 + 11))
						v27.field_8 = float32(float64(v16 + 11))
						a2 = int32(v17)*23 + 11
						v27.field_C = float32(float64(a2))
						if nox_xxx_mapTraceRay_535250(&v27, nil, nil, 1) == 0 {
							v12 = v25
							*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(v12+int32(func() uint8 {
								p := (*uint8)(unsafe.Add(v12, 2172))
								x := *p
								*p++
								return x
							}())*4)), 2140)) = a1
							goto LABEL_38
						}
					}
					goto LABEL_38
				}
			}
			if v9 <= 0 {
				if v9 < 0 {
					if v11 > 0 {
						a2 = int32(*v7)
						*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v8*8))) = float32(float64(a2)*23.0 + 23.0 - 2.3)
						a2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1)))
						v20 = float64(a2)
						*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176))+v8*8)), 4)) = float32(v20*23.0 + 2.3)
						goto LABEL_38
					}
					if v11 < 0 {
						a2 = int32(*v7)
						*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v8*8))) = float32(float64(a2)*23.0 + 23.0 - 2.3)
						a2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1)))
						v18 = float64(a2)
						*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176))+v8*8)), 4)) = float32(v18*23.0 + 23.0 - 2.3)
						goto LABEL_38
					}
					a2 = int32(*v7)
					*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v8*8))) = float32(float64(a2)*23.0 + 23.0 - 2.3)
					a2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1)))
					v19 = float64(a2)
					*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176))+v8*8)), 4)) = float32(v19*23.0 + 11.5)
					goto LABEL_38
				}
				if v11 > 0 {
					a2 = int32(*v7)
					*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v8*8))) = float32(float64(a2)*23.0 + 11.5)
					a2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1)))
					v20 = float64(a2)
					*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176))+v8*8)), 4)) = float32(v20*23.0 + 2.3)
					goto LABEL_38
				}
				if v11 < 0 {
					a2 = int32(*v7)
					*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v8*8))) = float32(float64(a2)*23.0 + 11.5)
					a2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1)))
					v18 = float64(a2)
					*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176))+v8*8)), 4)) = float32(v18*23.0 + 23.0 - 2.3)
					goto LABEL_38
				}
			} else {
				if v11 <= 0 {
					if v11 < 0 {
						a2 = int32(*v7)
						*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v8*8))) = float32(float64(a2)*23.0 + 2.3)
						a2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1)))
						v18 = float64(a2)
						*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176))+v8*8)), 4)) = float32(v18*23.0 + 23.0 - 2.3)
						goto LABEL_38
					}
					a2 = int32(*v7)
					*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v8*8))) = float32(float64(a2)*23.0 + 2.3)
					a2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1)))
					v19 = float64(a2)
					*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176))+v8*8)), 4)) = float32(v19*23.0 + 11.5)
					goto LABEL_38
				}
				a2 = int32(*v7)
				*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v8*8))) = float32(float64(a2)*23.0 + 2.3)
				a2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1)))
				*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176))+v8*8)), 4)) = float32(float64(a2)*23.0 + 2.3)
			}
		LABEL_38:
			v4 = v7
			v7 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1)))))
			v8++
			if v7 == nil {
				goto LABEL_39
			}
		}
	}
LABEL_39:
	v21 = 0
	dword_5d4594_2386180 = uint32(v8)
	for v21 < dword_5d4594_2386180/2 {
		v22 = (*uint32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v21*8)))
		v23 = (*uint32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + (v8-v21)*8 - 8)))
		v26 = *(*types.Pointf)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v21*8)))
		*v22 = *v23
		*(*uint32)(unsafe.Add(unsafe.Pointer(v22), 4*1)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v23), 4*1))
		v24 = int32(dword_5d4594_2386180 - uint32(func() int32 {
			p := &v21
			x := *p
			*p++
			return x
		}()))
		*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v24*8 - 8))) = v26.X
		*(*float32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + v24*8 - 4))) = v26.Y
		v8 = int32(dword_5d4594_2386180)
	}
}
func sub_50C830(a1 unsafe.Pointer, a2 int32, a3 int32) int32 {
	var (
		v3 int32
		v4 *float32
		v6 types.Pointf
		v7 float32
		v8 float32
	)
	v3 = int32(*(*uint32)(unsafe.Add(a1, 16)))
	if v3&0x4000 != 0 || sub_534020(a1) != 0 {
		return 1
	}
	v4 = mem_getFloatPtr(0x587000, 234188)
	v8 = float32(float64(a2 * 23))
	for {
		v6.X = v8 + *(*float32)(unsafe.Add(unsafe.Pointer(v4), -int(unsafe.Sizeof(float32(0))*1)))
		v7 = float32(float64(a3 * 23))
		v6.Y = v7 + *v4
		if nox_xxx_tileNFromPoint_411160(&v6) == 6 {
			break
		}
		v4 = (*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*2))
		if int32(uintptr(unsafe.Pointer(v4))) >= int32(uintptr(memmap.PtrOff(0x587000, 234220))) {
			return 1
		}
	}
	return 0
}
func nox_xxx_pathfind_preCheckWalls_50C8D0(a1 unsafe.Pointer, a2 *Point32) {
	var (
		v2 int32
		v3 int32
		v4 float64
		v5 float32
		v6 float32
	)
	if sub_50B870(a1, a2.X, a2.Y) != 0 {
		v2 = a2.X
		v3 = a2.Y
		v5 = float32(float64(v3)*23.0 + 11.5)
		v4 = float64(*(*float32)(unsafe.Add(a1, 56))) - (float64(a2.X)*23.0 + 11.5)
		v6 = *(*float32)(unsafe.Add(a1, 60)) - v5
		if math.Abs(float64(v6)) >= math.Abs(v4) {
			if float64(v6) <= 0.0 {
				a2.Y = v3 - 1
			} else {
				a2.Y = v3 + 1
			}
		} else if v4 <= 0.0 {
			a2.X = v2 - 1
		} else {
			a2.X = v2 + 1
		}
	}
}
func nox_xxx_appendWorkPath_50C990(a1 unsafe.Pointer, ind int32, sz int32) int32 {
	var (
		v3 int32
		v4 int32
		v6 *uint32
	)
	v3 = 0
	if dword_5d4594_2386180 <= 0 {
		return ind
	}
	v4 = ind
	v5 := unsafe.Add(a1, ind*8)
	for {
		if v4 == sz-1 {
			nox_ai_debug_printf_5341A0(internCStr("appendWorkPath: Path truncated.\n"))
			return v4
		}
		v4++
		v5 = unsafe.Add(v5, 8)
		v6 = (*uint32)(unsafe.Pointer(uintptr(int32(uintptr(dword_5d4594_2386176)) + func() int32 {
			p := &v3
			x := *p
			*p++
			return x
		}()*8)))
		*(*uint32)(unsafe.Add(v5, -8)) = *v6
		*(*uint32)(unsafe.Add(v5, -4)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
		if v3 >= dword_5d4594_2386180 {
			return v4
		}
	}
}
func nox_xxx_generateRetreatPath_50CA00(a1 unsafe.Pointer, a2 int32, a3 unsafe.Pointer, a4 *float32) int32 {
	*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a3, 748)), 2172)) = 0
	nox_xxx_pathFind_50BA00(1, a3, (*float32)(unsafe.Add(a3, 56)), a4, sub_50CA60, 6)
	if dword_5d4594_2386180 > uint32(a2) && dword_5d4594_1599712 == 0 {
		dword_5d4594_1599712 = 1
	}
	return nox_xxx_appendWorkPath_50C990(a1, 0, a2)
}
func sub_50CA60(a4 unsafe.Pointer, a2 int32, a3 int32) int32 {
	var a1 types.Pointf
	dword_5d4594_1599708 = 0
	a1.X = float32(float64(a2)*23.0 + 11.5)
	a1.Y = float32(float64(a3)*23.0 + 11.5)
	nox_xxx_unitsGetInCircle_517F90(&a1, 100.0, sub_50CAC0, a4)
	return bool2int32(dword_5d4594_1599708 == 0)
}
func sub_50CAC0(it *server.Object, data unsafe.Pointer) {
	a1 := it
	a2 := int32(uintptr(data))
	if dword_5d4594_1599708 != 1 {
		if nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(a2), a1) != 0 {
			dword_5d4594_1599708 = 1
		}
	}
}
func nox_xxx_pathFindStatus_50CAF0() int32 {
	return int32(dword_5d4594_1599712)
}
func sub_50CB00() int32 {
	return int32(dword_5d4594_2386180)
}
func sub_50CB10() unsafe.Pointer {
	return dword_5d4594_2386176
}
func sub_50CB20(a1 unsafe.Pointer, a2 *float32) unsafe.Pointer {
	var (
		v2  int32
		v3  float64
		v4  *uint16
		v5  int32
		v6  *uint16
		v7  int32
		v8  int32
		v9  *uint8
		v10 int32
		v11 int32
		v12 *uint16
		v14 float32
		v15 float32
		v16 int32
		a2a Point32
		v18 types.Pointf
		v19 *uint16
	)
	dword_5d4594_2386160++
	v14 = float32(float64(*a2) * 0.043478262)
	v2 = int32(v14)
	v3 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) * 0.043478262
	a2a.X = v2
	v15 = float32(v3)
	a2a.Y = int32(v15)
	nox_xxx_pathfind_preCheckWalls_50C8D0(a1, &a2a)
	nox_alloc_class_free_all((*nox_alloc_class)(nox_alloc_visitNode_2386184))
	v4 = (*uint16)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_visitNode_2386184)))
	*v4 = uint16(int16(a2a.X))
	*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(a2a.Y))
	v5 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*1))) + (int32(*v4) << 8)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) = 0
	nox_server_xxx_1599716[v5].field_0 = dword_5d4594_2386160
	for {
		v6 = v4
		v19 = nil
		if v4 == nil {
			break
		}
		for {
			v7 = int32(*v6)
			v8 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(uint16(0))*1)))
			if int32(nox_server_xxx_1599716[int32(uint16(int16(v8)))+(v7<<8)].field_8)&0x40 != 0 && sub_50B870(a1, v7, v8) == 0 {
				v18.X = float32(float64(v7*23 + 11))
				v18.Y = float32(float64(v8*23 + 11))
				return unsafe.Pointer(sub_518740(&v18, 0x80))
			}
			v9 = (*uint8)(memmap.PtrOff(0x587000, 234284))
			for {
				v10 = int32(uint32(*v6) + *(*uint32)(unsafe.Add(unsafe.Pointer(v9), -int(4*1))))
				v11 = int32(*(*uint32)(unsafe.Pointer(v9)) + uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(uint16(0))*1))))
				if v10 >= 0 && v10 < 256 && v11 >= 0 && v11 < 256 && nox_server_xxx_1599716[v11+(v10<<8)].field_0 != dword_5d4594_2386160 {
					v16 = int32(*(*uint32)(unsafe.Pointer(v9)) + uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(uint16(0))*1))))
					nox_server_xxx_1599716[v11+(v10<<8)].field_0 = dword_5d4594_2386160
					if sub_50B870(a1, v10, v16) == 0 {
						if sub_50C830(a1, v10, v11) != 0 {
							v12 = (*uint16)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_visitNode_2386184)))
							if v12 != nil {
								*v12 = uint16(int16(v10))
								*(*uint16)(unsafe.Add(unsafe.Pointer(v12), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(v11))
								*(*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*1)) = uint32(uintptr(unsafe.Pointer(v6)))
								*(*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*2)) = uint32(uintptr(unsafe.Pointer(v19)))
								v19 = v12
							}
						}
					}
				}
				v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 8))
				if int32(uintptr(unsafe.Pointer(v9))) >= int32(uintptr(memmap.PtrOff(0x587000, 234316))) {
					break
				}
			}
			v6 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*2)))))
			if v6 == nil {
				break
			}
		}
		v4 = v19
		if v19 == nil {
			break
		}
	}
	return nil
}
func nox_xxx_creatureSetDetailedPath_50D220(a1 unsafe.Pointer, a2 int32) int32 {
	obj := a1
	var result int32
	ud := obj.UpdateDataMonster()
	v3 := unsafe.Pointer(ud)
	v4 := int32(ud.Field70)
	ud.Field67 = 0
	if (gameFrame() - uint32(v4)) >= 0xA {
		ud.Field68 = *(*uint32)(a2)
		ud.Field69 = *(*uint32)(unsafe.Add(a2, 4))
		ud.Field2 = uint32(nox_xxx_genPathToPoint_50B9A0(unsafe.Pointer(&ud.Path), 32, a1, (*float32)(a2)))
		result = nox_xxx_pathFindStatus_50CAF0()
		*(*uint8)(unsafe.Add(v3, 284)) = uint8(int8(result))
		ud.Field70 = gameFrame()
	} else {
		ud.Field2 = 0
		*(*uint8)(unsafe.Add(v3, 284)) = 1
	}
	return result
}
func sub_50D2A0(a1 unsafe.Pointer, a2 int32) int32 {
	var (
		v2     *uint32
		result int32
	)
	v2 = *(**uint32)(unsafe.Add(a1, 748))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*92)) = *(*uint32)(a2)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*93)) = *(*uint32)(unsafe.Add(a2, 4))
	result = sub_547F20(a1, (*float32)(a2))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*74)) = uint32(result)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*91)) = 0
	return result
}
func sub_50D2E0(a1 unsafe.Pointer) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 int32
		v5 float64
		v6 float64
		v8 *uint32
		v9 int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v2 = int32(*(*uint32)(unsafe.Add(v1, 296)))
	if !(v2 != 0 && *(*uint32)(unsafe.Add(v1, 8)) == 0) {
		return bool2int32(nox_xxx_creatureActuallyMove_50D3B0((*float32)(a1)) != 0 && int32(*(*uint8)(unsafe.Add(v1, 284))) == 2)
	}
	v3 = int32(*(*uint32)(unsafe.Add(v1, 364)))
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1+v3*4)), 300)))
	v5 = float64(*(*float32)(unsafe.Add(v4, 8)) - *(*float32)(unsafe.Add(a1, 56)))
	v6 = float64(*(*float32)(unsafe.Add(v4, 12)) - *(*float32)(unsafe.Add(a1, 60)))
	if v6*v6+v5*v5 < 64.0 {
		if v3 == v2-1 {
			*(*uint32)(unsafe.Add(v1, 296)) = 0
			return 1
		}
		*(*uint32)(unsafe.Add(v1, 364)) = uint32(v3 + 1)
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1+(v3+1)*4)), 300)))
	}
	v8 = (*uint32)(unsafe.Add(v4, 8))
	nox_xxx_creatureSetDetailedPath_50D220(a1, v4+8)
	if int32(*(*uint8)(unsafe.Add(v1, 284))) != 0 {
		return bool2int32(nox_xxx_creatureActuallyMove_50D3B0((*float32)(a1)) != 0 && int32(*(*uint8)(unsafe.Add(v1, 284))) == 2)
	}
	v9 = int32(*(*uint32)(unsafe.Add(v1, 8)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1+v9*8)), 4)) = *v8
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1+v9*8)), 8)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
	return bool2int32(nox_xxx_creatureActuallyMove_50D3B0((*float32)(a1)) != 0 && int32(*(*uint8)(unsafe.Add(v1, 284))) == 2)
}
func nox_xxx_creatureActuallyMove_50D3B0(a1 *float32) int32 {
	var (
		v1  int32
		v2  int32
		v3  float32
		v4  int32
		v5  *float32
		v6  float64
		v7  float64
		v8  float64
		v10 *float32
		v11 float64
		v12 float64
		v13 int16
		v14 int32
		v15 float64
		v16 *float32
		v17 float32
		v18 *float32
		v19 int32
		v20 float32
		v21 float32
		v22 types.Pointf
		v23 float4
		v24 float32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*187)))
	v2 = 0
	if *(*uint32)(unsafe.Add(v1, 8)) == 0 {
		return 0
	}
	v3 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*15))
	v23.field_0 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*14))
	v23.field_4 = v3
	v4 = int32(*(*uint32)(unsafe.Add(v1, 268)))
	v16 = nil
	v18 = nil
	v19 = 0
	v17 = 1e+07
	if v4 >= *(*int32)(unsafe.Add(v1, 8)) {
		*(*uint32)(unsafe.Add(v1, 8)) = 0
		return 0
	}
	v5 = (*float32)(unsafe.Add(unsafe.Pointer(uintptr(v1+v4*8)), 12))
	for {
		v23.field_8 = *v5
		v23.field_C = *(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*1))
		if nox_xxx_mapTraceRay_535250(&v23, nil, nil, -124) != 0 {
			v6 = float64(v23.field_8 - *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*14)))
			v7 = float64(v23.field_C - *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*15)))
			v8 = v7*v7 + v6*v6
			if v8 > 64.0 {
				if v16 == nil || float64(v17) > v8 {
					v17 = float32(v8)
					v16 = v5
					v2 = v4
				}
			} else {
				if uint32(v4) == *(*uint32)(unsafe.Add(v1, 8))-1 {
					*(*uint32)(unsafe.Add(v1, 8)) = 0
					return 1
				}
				v18 = v5
				v19 = v4
			}
		}
		v4++
		v5 = (*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*2))
		if v4 >= *(*int32)(unsafe.Add(v1, 8)) {
			break
		}
	}
	if v16 == nil {
		if v18 == nil {
			*(*uint32)(unsafe.Add(v1, 8)) = 0
			return 0
		}
		v2 = v19
	}
	v10 = a1
	*memmap.PtrUint32(0x5D4594, 2386204) = uint32(v2)
	*(*uint32)(unsafe.Add(v1, 268)) = uint32(v2)
	v20 = *(*float32)(unsafe.Add(unsafe.Pointer(uintptr(v1+v2*8)), 12)) - *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*14))
	v11 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(v1+v2*8)), 16)) - *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*15)))
	v21 = float32(v11)
	v24 = float32(math.Sqrt(v11*float64(v21)+float64(v20*v20)) + *mem_getDoublePtr(0x581450, 10288))
	if v2 <= 0 {
		v22.X = *(*float32)(unsafe.Add(v1, 20)) - *(*float32)(unsafe.Add(v1, 12))
		v12 = float64(*(*float32)(unsafe.Add(v1, 24)) - *(*float32)(unsafe.Add(v1, 16)))
	} else {
		v22.X = *(*float32)(unsafe.Add(unsafe.Pointer(uintptr(v1+v2*8)), 12)) - *(*float32)(unsafe.Add(unsafe.Pointer(uintptr(v1+v2*8)), 4))
		v12 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(v1+v2*8)), 16)) - *(*float32)(unsafe.Add(unsafe.Pointer(uintptr(v1+v2*8)), 8)))
	}
	v22.Y = float32(v12)
	v13 = int16(nox_xxx_math_509ED0(&v22))
	*(*uint16)(unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(uint16(0))*62)) = uint16(v13)
	*(*uint16)(unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(uint16(0))*63)) = uint16(v13)
	v14 = int32(*(*uint32)(unsafe.Add(v1, 1440)))
	if v14&0x4000 != 0 {
		v15 = float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 484)), 96)) * *(*float32)(unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(float32(0))*136)))
	} else {
		v15 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(float32(0))*136)))
	}
	*(*float32)(unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(float32(0))*22)) = float32(v15 * float64(v20) / float64(v24))
	*(*float32)(unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(float32(0))*23)) = float32(v15 * float64(v21) / float64(v24))
	return 0
}
func nox_xxx_creatureSetMovePath_50D5A0(a1 unsafe.Pointer) int32 {
	var (
		v1  int32
		v2  float64
		v3  *float32
		v4  float64
		v6  float32
		v7  int8
		v8  bool
		v9  int32
		v10 float64
		v11 float64
		v12 float64
		v13 float64
		v14 float4
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v2 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(v1+int32(*(*byte)(unsafe.Add(v1, 544))*24))), 556)) - *(*float32)(unsafe.Add(a1, 56)))
	v3 = (*float32)(unsafe.Add(unsafe.Pointer(uintptr(v1+int32(*(*byte)(unsafe.Add(v1, 544))*24))), 556))
	v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(v1+int32(*(*byte)(unsafe.Add(v1, 544))*24))), 560)) - *(*float32)(unsafe.Add(a1, 60)))
	if math.Sqrt(v4*v4+v2*v2)+*mem_getDoublePtr(0x581450, 10288) <= 8.0 {
		return 1
	}
	v6 = *(*float32)(unsafe.Add(a1, 60))
	v14.field_0 = *(*float32)(unsafe.Add(a1, 56))
	v14.field_4 = v6
	v14.field_8 = *v3
	v7 = int8(uint8((*(*uint32)(unsafe.Add(a1, 16)) >> 12) & 4))
	v14.field_C = *(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*1))
	v8 = nox_xxx_mapTraceRay_535250(&v14, nil, nil, v7) == 0
	v9 = int32(*(*uint32)(unsafe.Add(v1, 8)))
	if v8 {
		if v9 == 0 {
			if *(*uint32)(unsafe.Add(v1, 296)) == 0 || (gameFrame()-*(*uint32)(unsafe.Add(v1, 280))) > 0xA && (func() bool {
				v12 = float64(*(*float32)(unsafe.Add(v1, 368)) - *v3)
				v13 = float64(*(*float32)(unsafe.Add(v1, 372)) - *(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*1)))
				return v13*v13+v12*v12 > 10000.0
			}()) {
				sub_50D2A0(a1, int32(uintptr(unsafe.Pointer(v3))))
			}
			if *(*uint32)(unsafe.Add(v1, 296)) != 0 {
				if sub_50D2E0(a1) != 0 {
					*(*uint32)(unsafe.Add(v1, 8)) = 0
					*(*uint32)(unsafe.Add(v1, 296)) = 0
					return 1
				}
				return 0
			}
			nox_ai_debug_printf_5341A0(internCStr(" ** Waypoint path failed, doing detailed path\n"))
			nox_xxx_creatureSetDetailedPath_50D220(a1, int32(uintptr(unsafe.Pointer(v3))))
		}
	} else if v9 == 0 || (gameFrame()-*(*uint32)(unsafe.Add(v1, 280))) > 0xA && (func() bool {
		v10 = float64(*(*float32)(unsafe.Add(v1, 272)) - *v3)
		v11 = float64(*(*float32)(unsafe.Add(v1, 276)) - *(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*1)))
		return v11*v11+v10*v10 > 2500.0
	}()) {
		nox_xxx_creatureSetDetailedPath_50D220(a1, int32(uintptr(unsafe.Pointer(v3))))
	}
	if *(*uint32)(unsafe.Add(v1, 296)) != 0 {
		if sub_50D2E0(a1) != 0 {
			*(*uint32)(unsafe.Add(v1, 8)) = 0
			*(*uint32)(unsafe.Add(v1, 296)) = 0
			return 1
		}
		return 0
	}
	if *(*uint32)(unsafe.Add(v1, 8)) != 0 && nox_xxx_creatureActuallyMove_50D3B0((*float32)(a1)) != 0 {
		*(*uint32)(unsafe.Add(v1, 8)) = 0
		return 1
	}
	return 0
}
func nox_xxx_allocMonsterRelatedArrays_50D780() int32 {
	var result int32
	result = int32(uintptr(unsafe.Pointer(nox_new_alloc_class(internCStr("SpawnClass"), 12, 96))))
	nox_alloc_spawn_2386216 = result
	if result == 0 {
		return result
	}
	dword_5d4594_2386212 = 0
	result = int32(uintptr(unsafe.Pointer(nox_new_alloc_class(internCStr("MonsterListClass"), 148, 96))))
	nox_alloc_monsterList_2386220 = result
	if result == 0 {
		return result
	}
	dword_5d4594_2386224 = 0
	dword_5d4594_2386228 = 0
	result = 1
	return result
}
func sub_50D7E0() {
	nox_alloc_class_free_all((*nox_alloc_class)(nox_alloc_spawn_2386216))
	dword_5d4594_2386212 = 0
	nox_alloc_class_free_all((*nox_alloc_class)(nox_alloc_monsterList_2386220))
	dword_5d4594_2386224 = 0
	dword_5d4594_2386228 = 0
}
func sub_50D820() {
	nox_free_alloc_class((*nox_alloc_class)(nox_alloc_spawn_2386216))
	nox_alloc_spawn_2386216 = nil
	dword_5d4594_2386212 = 0
	nox_free_alloc_class((*nox_alloc_class)(nox_alloc_monsterList_2386220))
	nox_alloc_monsterList_2386220 = nil
	dword_5d4594_2386224 = 0
	dword_5d4594_2386228 = 0
}
func sub_50D8D0() {
	var (
		v0 *int32
		v1 *int32
		v2 int32
		v3 int32
		v4 int32
	)
	v0 = dword_5d4594_2386212
	if dword_5d4594_2386212 != 0 {
		for {
			v1 = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v0), 4*1)))
			v2 = 1
			v3 = nox_xxx_getFirstPlayerUnit_4DA7C0()
			for v3 != 0 {
				v4 = int32(*(*uint32)(unsafe.Add(v3, 748)))
				if *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 4792)) == 1 && *(*uint32)(unsafe.Add(v4, 312)) == 0 && nox_xxx_calcDistance_4E6C00((*server.Object)(v3), (*server.Object)(unsafe.Pointer(uintptr(*v0)))) < 700.0 {
					v2 = 0
				}
				v3 = nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(v3))
			}
			if v2 == 1 {
				nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(unsafe.Pointer(uintptr(*v0))))
			}
			v0 = v1
			if v1 == nil {
				break
			}
		}
	}
}
func sub_50D960() int32 {
	var (
		v0  int32
		v1  int32
		v2  int32
		v3  *int32
		v4  int32
		v5  *uint32
		v6  *uint32
		v7  int32
		i   int32
		v9  float64
		v10 int32
		v11 *float32
		v12 int32
		j   int32
		k   int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
		v23 int32
		v24 int32
		v25 *uint8
		v26 *int32
		v27 *int32
		v28 int8
		v29 *uint8
		v30 int32
		v31 int32
		v32 int32
		v34 float32
		v35 int32
		v36 int32
		v37 int32
		a2  float4
		v39 float4
	)
	v34 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MaxOnscreenMonsterCount")))
	v35 = int32(v34)
	v36 = 0
	libc.MemSet(memmap.PtrOff(0x5D4594, 2386232), 0, 0x80)
	v0 = nox_xxx_getFirstPlayerUnit_4DA7C0()
	if v0 == 0 {
		return sub_50DE10()
	}
	for {
		v1 = int32(*(*uint32)(unsafe.Add(v0, 748)))
		*memmap.PtrUint32(0x5D4594, uintptr(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 2064)))*4)+2386232) = 0
		v2 = int32(*(*uint32)(unsafe.Add(v1, 276)))
		if *(*uint32)(unsafe.Add(v2, 4792)) != 0 {
			v3 = dword_5d4594_2386212
			a2.field_0 = float32(float64(*(*float32)(unsafe.Add(v0, 56))) - float64(*(*uint16)(unsafe.Add(v2, 10))) - 100.0)
			a2.field_4 = float32(float64(*(*float32)(unsafe.Add(v0, 60))) - float64(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 12))) - 100.0)
			a2.field_8 = float32(float64(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 10))) + float64(*(*float32)(unsafe.Add(v0, 56))) + 100.0)
			a2.field_C = float32(float64(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 12))) + float64(*(*float32)(unsafe.Add(v0, 60))) + 100.0)
			if dword_5d4594_2386212 != 0 {
				for {
					if sub_428220((*types.Pointf)(unsafe.Add(unsafe.Pointer(uintptr(*v3)), 56)), &a2) != 0 {
						v39.field_0 = *(*float32)(unsafe.Add(v0, 56))
						v39.field_4 = *(*float32)(unsafe.Add(v0, 60))
						v4 = *v3
						v39.field_8 = *(*float32)(unsafe.Add(unsafe.Pointer(uintptr(*v3)), 56))
						v39.field_C = *(*float32)(unsafe.Add(v4, 60))
						if nox_xxx_mapTraceRay_535250(&v39, nil, nil, 69) != 0 {
							v5 = sub_50DE60(*v3)
							if v5 == nil {
								v6 = (*uint32)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_monsterList_2386220)))
								v5 = v6
								if v6 == nil {
									break
								}
								*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*35)) = dword_5d4594_2386224
								if dword_5d4594_2386224 != 0 {
									*(*uint32)(unsafe.Add(dword_5d4594_2386224, 144)) = uint32(uintptr(unsafe.Pointer(v6)))
								}
								dword_5d4594_2386224 = uint32(uintptr(unsafe.Pointer(v6)))
								dword_5d4594_2386228++
								*v6 = uint32(*v3)
							}
							*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2)) |= uint32(1 << int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 2064))))
							v7 = int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 2064)))
							*memmap.PtrUint32(0x5D4594, uintptr(v7*4)+2386232)++
							if *memmap.PtrUint32(0x5D4594, uintptr(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 2064)))*4)+2386232) > uint32(v35) {
								v36 = 1
							}
							*(*float32)(unsafe.Add(unsafe.Pointer(v5), 4*uintptr(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 2064)))+3))) = float32(nox_xxx_calcDistance_4E6C00((*server.Object)(unsafe.Pointer(uintptr(*v3))), (*server.Object)(v0)))
						}
					}
					v3 = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*1)))
					if v3 == nil {
						break
					}
				}
			}
		}
		v0 = nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(v0))
		if v0 == 0 {
			break
		}
	}
	if v36 == 0 {
		return sub_50DE10()
	}
	for i = int32(dword_5d4594_2386224); i != 0; i = int32(*(*uint32)(unsafe.Add(i, 140))) {
		v9 = 0.0
		v10 = 0
		v11 = (*float32)(unsafe.Add(i, 12))
		v12 = 32
		for {
			if float64(*v11) != 0.0 {
				v9 = v9 + float64(*v11)
				v10++
			}
			v11 = (*float32)(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(float32(0))*1))
			v12--
			if v12 == 0 {
				break
			}
		}
		*(*float32)(unsafe.Add(i, 4)) = float32(v9 / float64(v10))
	}
	for j = int32(dword_5d4594_2386224); j != 0; j = int32(*(*uint32)(unsafe.Add(j, 140))) {
		for k = int32(*(*uint32)(unsafe.Add(j, 140))); k != 0; k = int32(*(*uint32)(unsafe.Add(k, 140))) {
			if float64(*(*float32)(unsafe.Add(k, 4))) > float64(*(*float32)(unsafe.Add(j, 4))) {
				v15 = int32(*(*uint32)(unsafe.Add(j, 140)))
				if v15 == k {
					v16 = int32(*(*uint32)(unsafe.Add(j, 144)))
					*(*uint32)(unsafe.Add(k, 144)) = uint32(v16)
					if v16 != 0 {
						*(*uint32)(unsafe.Add(v16, 140)) = uint32(k)
					}
					v17 = int32(*(*uint32)(unsafe.Add(k, 140)))
					*(*uint32)(unsafe.Add(j, 140)) = uint32(v17)
					if v17 != 0 {
						*(*uint32)(unsafe.Add(v17, 144)) = uint32(j)
					}
					*(*uint32)(unsafe.Add(j, 144)) = uint32(k)
					*(*uint32)(unsafe.Add(k, 140)) = uint32(j)
				} else {
					v18 = int32(*(*uint32)(unsafe.Add(j, 144)))
					v19 = int32(*(*uint32)(unsafe.Add(k, 140)))
					v20 = int32(*(*uint32)(unsafe.Add(k, 144)))
					if v18 != 0 {
						*(*uint32)(unsafe.Add(v18, 140)) = uint32(k)
					}
					if v20 != 0 {
						*(*uint32)(unsafe.Add(v20, 140)) = uint32(j)
					}
					if v15 != 0 {
						*(*uint32)(unsafe.Add(v15, 144)) = uint32(k)
					}
					if v19 != 0 {
						*(*uint32)(unsafe.Add(v19, 144)) = uint32(j)
					}
					*(*uint32)(unsafe.Add(j, 144)) = uint32(v20)
					*(*uint32)(unsafe.Add(j, 140)) = uint32(v19)
					*(*uint32)(unsafe.Add(k, 144)) = uint32(v18)
					*(*uint32)(unsafe.Add(k, 140)) = uint32(v15)
				}
				if uint32(j) == dword_5d4594_2386224 {
					dword_5d4594_2386224 = uint32(k)
				}
				v21 = k
				k = j
				j = v21
			}
		}
	}
	for {
		v22 = 0
		v23 = 0
		v24 = 0
		v25 = (*uint8)(memmap.PtrOff(0x5D4594, 2386232))
		for {
			if *(*uint32)(unsafe.Pointer(v25)) > uint32(v22) {
				v22 = int32(*(*uint32)(unsafe.Pointer(v25)))
				v23 = v24
			}
			v25 = (*uint8)(unsafe.Add(unsafe.Pointer(v25), 4))
			v24++
			if int32(uintptr(unsafe.Pointer(v25))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 2386360))) {
				break
			}
		}
		if v22 <= v35 {
			break
		}
		v26 = dword_5d4594_2386224
		v37 = 1
		if dword_5d4594_2386224 != 0 {
			for {
				if v37 != 1 {
					break
				}
				v27 = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v26), 4*35)))
				if *(*int32)(unsafe.Add(unsafe.Pointer(v26), 4*2))&(1<<v23) != 0 {
					nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(unsafe.Pointer(uintptr(*v26))))
					v28 = 0
					v29 = (*uint8)(memmap.PtrOff(0x5D4594, 2386232))
					for {
						if (1<<int32(v28))&*(*int32)(unsafe.Add(unsafe.Pointer(v26), 4*2)) != 0 {
							*(*uint32)(unsafe.Pointer(v29))--
						}
						v29 = (*uint8)(unsafe.Add(unsafe.Pointer(v29), 4))
						v28++
						if int32(uintptr(unsafe.Pointer(v29))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 2386360))) {
							break
						}
					}
					v30 = *(*int32)(unsafe.Add(unsafe.Pointer(v26), 4*35))
					if v30 != 0 {
						*(*uint32)(unsafe.Add(v30, 144)) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v26), 4*36)))
					}
					v31 = *(*int32)(unsafe.Add(unsafe.Pointer(v26), 4*36))
					if v31 != 0 {
						*(*uint32)(unsafe.Add(v31, 140)) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v26), 4*35)))
					} else {
						dword_5d4594_2386224 = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v26), 4*35)))
					}
					nox_alloc_class_free_obj_first((*nox_alloc_class)(nox_alloc_monsterList_2386220), unsafe.Pointer(v26))
					v32 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v23*4)+2386232))
					dword_5d4594_2386228--
					if v32 <= v35 {
						v37 = 0
					}
				}
				v26 = v27
				if v27 == nil {
					break
				}
			}
		}
	}
	return sub_50DE10()
}
func sub_50DE10() int32 {
	var (
		result int32
		v1     int32
	)
	result = int32(dword_5d4594_2386224)
	if dword_5d4594_2386224 != 0 {
		for {
			v1 = int32(*(*uint32)(unsafe.Add(result, 140)))
			nox_alloc_class_free_obj_first((*nox_alloc_class)(nox_alloc_monsterList_2386220), result)
			result = v1
			dword_5d4594_2386228--
			if v1 == 0 {
				break
			}
		}
		dword_5d4594_2386224 = 0
	} else {
		dword_5d4594_2386224 = 0
	}
	return result
}
func sub_50DE60(a1 int32) *uint32 {
	var result *uint32
	result = dword_5d4594_2386224
	if dword_5d4594_2386224 == 0 {
		return nil
	}
	for *result != uint32(a1) {
		result = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(result), 4*35)))
		if result == nil {
			return nil
		}
	}
	return result
}
func sub_50DE80(a1 int32, a2 *float32) int32 {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v7  float32
		a2a float4
	)
	v7 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MaxOnscreenMonsterCount")))
	v2 = int32(v7)
	v3 = nox_xxx_getFirstPlayerUnit_4DA7C0()
	if v3 == 0 {
		return 1
	}
	for {
		v4 = int32(*(*uint32)(unsafe.Add(v3, 748)))
		v5 = int32(*(*uint32)(unsafe.Add(v4, 276)))
		if *(*uint32)(unsafe.Add(v5, 4792)) != 0 {
			a2a.field_0 = float32(float64(*(*float32)(unsafe.Add(v3, 56))) - float64(*(*uint16)(unsafe.Add(v5, 10))) - 100.0)
			a2a.field_4 = float32(float64(*(*float32)(unsafe.Add(v3, 60))) - float64(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 12))) - 100.0)
			a2a.field_8 = float32(float64(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 10))) + float64(*(*float32)(unsafe.Add(v3, 56))) + 100.0)
			a2a.field_C = float32(float64(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 12))) + float64(*(*float32)(unsafe.Add(v3, 60))) + 100.0)
			if sub_428220((*types.Pointf)(unsafe.Pointer(a2)), &a2a) != 0 {
				*memmap.PtrUint32(0x5D4594, 2386208) = 0
				nox_xxx_getUnitsInRect_517C10(&a2a, sub_50DFB0, v3)
				if *memmap.PtrUint32(0x5D4594, 2386208) >= uint32(v2) {
					break
				}
			}
		}
		v3 = nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(v3))
		if v3 == 0 {
			return 1
		}
	}
	return 0
}
func sub_50DFB0(it *server.Object, data unsafe.Pointer) {
	a1 := (*float32)(it.CObj())
	a2 := int32(uintptr(data))
	var (
		v2 float32
		v3 float32
		v4 float32
		v5 float4
	)
	if int32(uint8(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*2))))&2 != 0 && (uint32(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*4)))&0x20) == 0 && ((uint32(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*4)))&0x8000) != 0x8000 || nox_xxx_unitIsZombie_534A40((*server.Object)(unsafe.Pointer(a1))) != 0) {
		v2 = *(*float32)(unsafe.Add(a2, 56))
		v3 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*14))
		v5.field_4 = *(*float32)(unsafe.Add(a2, 60))
		v5.field_0 = v2
		v4 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*15))
		v5.field_8 = v3
		v5.field_C = v4
		if nox_xxx_mapTraceRay_535250(&v5, nil, nil, 69) == 1 {
			*memmap.PtrUint32(0x5D4594, 2386208)++
		}
	}
}
func sub_50E030(a1 int32, a2 *uint32) int32 {
	var (
		v2     int32
		v3     *uint32
		result int32
		v5     *uint32
		v6     int32
		v7     *uint32
		v8     int32
		v9     *int32
		v10    *uint32
		v11    int32
		v12    int32
		v13    *uint32
		v14    int32
	)
	v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v3 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*187)))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*549)) != 0 {
		return 1
	}
	result = int32(uintptr(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_spawn_2386216))))
	v5 = (*uint32)(result)
	if result == 0 {
		return result
	}
	sub_50E110(result)
	*v5 = uint32(uintptr(unsafe.Pointer(a2)))
	*(*uint8)(unsafe.Add(v2, 86))++
	*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*549)) = uint32(uintptr(unsafe.Pointer(v5)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*548)) = uint32(a1)
	v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)))
	if v6&0x2000 == 0 {
		return 1
	}
	v7 = nox_xxx_newObjectByTypeID_4E3810(internCStr("Glyph"))
	if v7 != nil {
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*173)))
		v9 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*511))
		v10 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v7), 4*173)))
		v11 = 3
		for {
			v12 = *v9
			v9 = (*int32)(unsafe.Add(unsafe.Pointer(v9), 4*1))
			*v10 = uint32(v12)
			v10 = (*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*1))
			v11--
			if v11 == 0 {
				break
			}
		}
		*(*uint32)(unsafe.Add(v8, 24)) = 0
		*(*uint32)(unsafe.Add(v8, 28)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*14))
		*(*uint32)(unsafe.Add(v8, 32)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*15))
		*(*uint8)(unsafe.Add(v8, 20)) = 0
		v13 = (*uint32)(v8)
		v14 = 3
		for {
			if *v13 != 0 {
				*(*uint8)(unsafe.Add(v8, 20))++
			}
			v13 = (*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*1))
			v14--
			if v14 == 0 {
				break
			}
		}
	}
	nox_xxx_inventoryPutImpl_4F3070((*server.Object)(unsafe.Pointer(a2)), (*server.Object)(unsafe.Pointer(v7)), 1)
	return 1
}
func sub_50E110(a1 int32) int32 {
	var result int32
	result = a1
	*(*uint32)(unsafe.Add(a1, 8)) = 0
	*(*uint32)(unsafe.Add(a1, 4)) = dword_5d4594_2386212
	if dword_5d4594_2386212 != 0 {
		*(*uint32)(unsafe.Add(dword_5d4594_2386212, 8)) = uint32(a1)
	}
	dword_5d4594_2386212 = uint32(a1)
	return result
}
func sub_50E140(a1 unsafe.Pointer) {
	var (
		v1 int32
		v2 int32
	)
	if a1 != nil {
		v1 = int32(*(*uint32)(unsafe.Add(a1, 748)))
		v2 = int32(*(*uint32)(unsafe.Add(v1, 2192)))
		if v2 != 0 {
			*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 748)), 86))--
			*(*uint32)(unsafe.Add(v1, 2192)) = 0
		}
		if *(*uint32)(unsafe.Add(v1, 2196)) != 0 {
			sub_50E1B0(int32(*(*uint32)(unsafe.Add(v1, 2196))))
			nox_alloc_class_free_obj_first((*nox_alloc_class)(nox_alloc_spawn_2386216), unsafe.Pointer(*(**uint64)(unsafe.Add(v1, 2196))))
			*(*uint32)(unsafe.Add(v1, 2196)) = 0
		}
	}
}
func sub_50E1B0(a1 int32) int32 {
	var (
		result int32
		v2     int32
		v3     int32
	)
	result = a1
	v2 = int32(*(*uint32)(unsafe.Add(a1, 4)))
	if v2 != 0 {
		*(*uint32)(unsafe.Add(v2, 8)) = *(*uint32)(unsafe.Add(a1, 8))
	}
	v3 = int32(*(*uint32)(unsafe.Add(a1, 8)))
	if v3 != 0 {
		result = int32(*(*uint32)(unsafe.Add(a1, 4)))
		*(*uint32)(unsafe.Add(v3, 4)) = uint32(result)
	} else {
		dword_5d4594_2386212 = *(*uint32)(unsafe.Add(a1, 4))
	}
	return result
}
func sub_50E1E0(obj unsafe.Pointer) {
	if obj != nil {
		if nox_xxx_unitIsZombie_534A40((*server.Object)(obj)) == 0 {
			sub_50E140(obj)
		}
	}
}
func sub_50E210(a1p *server.Object) {
	var (
		a1 = unsafe.Pointer(a1p)
		v1 int32
		v2 int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	if *memmap.PtrUint32(0x5D4594, 2386360) == 0 {
		*memmap.PtrUint32(0x5D4594, 2386360) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Glyph")))
	}
	if int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
		v2 = int32(*(*uint32)(unsafe.Add(a1, 12)))
		if v2&0x2000 != 0 {
			if *(*uint32)(unsafe.Add(v1, 2196)) != 0 {
				v3 := nox_xxx_inventoryGetFirst_4E7980((*server.Object)(a1))
				if v3 != nil {
					for {
						v4 := nox_xxx_inventoryGetNext_4E7990(v3)
						if uint32(v3.TypeInd) == *memmap.PtrUint32(0x5D4594, 2386360) {
							nox_xxx_delayedDeleteObject_4E5CC0(v3)
						}
						v3 = v4
						if v4 == nil {
							break
						}
					}
				}
			}
		}
	}
	sub_50E140(a1)
}
func nox_xxx_registerShopClasses_50E2A0() int32 {
	var result int32
	result = int32(uintptr(unsafe.Pointer(nox_new_alloc_class(internCStr("TradeSessions"), 64, 64))))
	nox_alloc_tradeSession_2386492 = result
	if result == 0 {
		return result
	}
	nox_alloc_tradeItems_2386496 = unsafe.Pointer(nox_new_alloc_class(internCStr("TradeItems"), 16, 500))
	if nox_alloc_tradeItems_2386496 != nil {
		libc.MemSet(memmap.PtrOff(0x5D4594, 2386364), 0, 0x80)
		dword_5d4594_2386500 = 0
		result = 1
	} else {
		nox_xxx_deleteShopInventories_50E300()
		result = 0
	}
	return result
}
func nox_xxx_deleteShopInventories_50E300() int32 {
	var result int32
	if nox_alloc_tradeSession_2386492 != nil {
		nox_free_alloc_class((*nox_alloc_class)(nox_alloc_tradeSession_2386492))
	}
	nox_alloc_tradeSession_2386492 = nil
	if nox_alloc_tradeItems_2386496 != nil {
		nox_free_alloc_class((*nox_alloc_class)(nox_alloc_tradeItems_2386496))
	}
	result = 0
	libc.MemSet(memmap.PtrOff(0x5D4594, 2386364), 0, 0x80)
	nox_alloc_tradeItems_2386496 = nil
	dword_5d4594_2386500 = 0
	return result
}
func sub_50E360() int32 {
	var (
		v0     *uint32
		i      *int32
		result int32
	)
	v0 = dword_5d4594_2386500
	if dword_5d4594_2386500 != 0 {
		for {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*4)) != 0 {
				for i = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v0), 4*5))); i != nil; i = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*2))) {
					nox_xxx_objectFreeMem_4E38A0((*server.Object)(unsafe.Pointer(uintptr(*i))))
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*5)) = 0
			}
			v0 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v0), 4*14)))
			if v0 == nil {
				break
			}
		}
	}
	nox_alloc_class_free_all((*nox_alloc_class)(nox_alloc_tradeSession_2386492))
	nox_alloc_class_free_all((*nox_alloc_class)(nox_alloc_tradeItems_2386496))
	result = 0
	libc.MemSet(memmap.PtrOff(0x5D4594, 2386364), 0, 0x80)
	dword_5d4594_2386500 = 0
	return result
}
func nox_xxx_shopGetItemCost_50E3D0(a1 int32, a2 unsafe.Pointer, a3 float32) int32 {
	var (
		v3  float32
		v4  int32
		v6  int32
		v7  int32
		v8  int32
		v9  float64
		v11 int32
		v12 int32
		v13 float64
		v14 int32
		v15 *uint8
		v16 float64
		v17 int32
		v18 float64
		v19 int32
		v20 int32
		v21 *uint16
		v22 float64
		v23 int32
		v24 float64
		v26 float32
		v27 int32
		v28 float32
		v29 int32
		v30 float32
		v31 float32
	)
	v3 = a3
	v4 = 0
	v27 = 0
	v31 = float32(float64(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a3), 4*0))))), 32))))
	if *memmap.PtrUint32(0x5D4594, 2386504) == 0 {
		*memmap.PtrUint32(0x5D4594, 2386504) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Diamond")))
		*memmap.PtrUint32(0x5D4594, 2386508) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Ruby")))
		*memmap.PtrUint32(0x5D4594, 2386512) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Emerald")))
	}
	v5 := a2
	if a2 != nil && *(*uint32)(unsafe.Add(a2, 16)) != 0 {
		v6 = int32(*(*uint32)(unsafe.Add(a2, 8)))
		if int32(*(*uint8)(unsafe.Add(v6, 8)))&4 != 0 {
			v6 = int32(*(*uint32)(unsafe.Add(a2, 12)))
		}
		v27 = int32(*(*uint32)(unsafe.Add(v6, 692)))
		v4 = int32(*(*uint32)(unsafe.Add(v6, 692)))
	}
	v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 8)))
	if v7&0x100 != 0 {
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 12)))
		if v8&1 != 0 {
			v9 = float64(uint16(int16(nox_xxx_spellPrice_424C40(int32(**(**uint8)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 736)))))))
			v31 = float32(v9)
			goto LABEL_17
		}
		if v8&2 != 0 {
			var worth int32 = nox_objectTypeGetWorth(*(**byte)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 736)))
			if worth >= 0 {
				v31 = float32(float64(worth))
			}
			if noxflags.HasGame(4096) {
				v9 = nox_xxx_gamedataGetFloat_419D40(internCStr("QuestGuideWorthMultiplier")) * float64(v31)
				v31 = float32(v9)
				goto LABEL_17
			}
		}
	}
LABEL_17:
	if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 8))&0x13001000 != 0 {
		v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 692)))
		v12 = 4
		for {
			if *(*uint32)(v11) != 0 {
				v29 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(v11), 20))))
				if noxflags.HasGame(4096) {
					v13 = nox_xxx_gamedataGetFloat_419D40(internCStr("QuestModifierWorthMultiplier")) * float64(v29)
				} else {
					v13 = float64(v29)
				}
				v31 = float32(v13 + float64(v31))
			}
			v11 += 4
			v12--
			if v12 == 0 {
				break
			}
		}
		v4 = v27
	}
	v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 8)))
	v30 = v31
	if uint32(v14)&0x1000000 != 0 && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 12)))&0x82 != 0 {
		v15 = *(**uint8)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 736))
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v15), 2))) == 0 && int32(*v15) != 0 {
			if noxflags.HasGame(4096) {
				v16 = nox_xxx_gamedataGetFloat_419D40(internCStr("DefaultAmmoAmountQuest"))
			} else {
				v16 = nox_xxx_gamedataGetFloat_419D40(internCStr("DefaultAmmoAmount"))
			}
			v26 = float32(v16)
			v17 = int32(v26)
			v18 = float64(v17)
			v19 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v15), 1)))
			if v19 > v17 {
				v28 = float32(float64(v31) / v18)
				v31 = float32(float64(v19-v17)*float64(v28) + float64(v31))
			} else {
				v31 = float32(float64(*(*uint8)(unsafe.Add(unsafe.Pointer(v15), 1))) / v18 * float64(v31))
			}
		}
	} else if v14&0x1000 != 0 {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 12))&0x47F0000 != 0 {
			v20 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 736)))
			if int32(*(*uint8)(unsafe.Add(v20, 109))) != 0 {
				v4 = v27
				v31 = float32(float64(*(*uint8)(unsafe.Add(v20, 108))) / float64(*(*uint8)(unsafe.Add(v20, 109))) * float64(v31))
			}
		}
	}
	if v4 != 0 && v5 != nil && *(*uint32)(unsafe.Add(v5, 16)) != 0 && a1 != 0 {
		v31 = v31 * *(*float32)(unsafe.Add(v4, 1716))
		v30 = v30 * *(*float32)(unsafe.Add(v4, 1716))
	}
	v21 = *(**uint16)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 556))
	if v21 != nil && int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v21), unsafe.Sizeof(uint16(0))*2))) != 0 {
		v31 = float32(float64(*v21) / float64(*(*uint16)(unsafe.Add(unsafe.Pointer(v21), unsafe.Sizeof(uint16(0))*2))) * float64(v31))
	}
	if v4 != 0 && a1 == 0 {
		if noxflags.HasGame(4096) {
			v22 = nox_xxx_gamedataGetFloat_419D40(internCStr("QuestSellMultiplier"))
		} else {
			v22 = float64(*(*float32)(unsafe.Add(v4, 1720)))
		}
		v23 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 4)))
		if uint32(uint16(int16(v23))) != *memmap.PtrUint32(0x5D4594, 2386504) && uint32(v23) != *memmap.PtrUint32(0x5D4594, 2386512) && uint32(v23) != *memmap.PtrUint32(0x5D4594, 2386508) {
			v31 = float32(v22 * float64(v31))
			v30 = float32(v22 * float64(v30))
		}
	}
	if noxflags.HasGame(4096) && a1 == 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 8))&0x3001000 != 0 && int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0))))), 748)), 4)))&1 != 0 {
		v30 = 0.0
	} else if float64(v31) >= 1.0 {
		goto LABEL_64
	}
	v31 = 1.0
LABEL_64:
	if float64(v30) < 1.0 {
		v30 = 1.0
	}
	if a1 != 2 {
		return int32(v31)
	}
	v24 = nox_xxx_gamedataGetFloat_419D40(internCStr("RepairCoefficient")) * float64(v30-v31)
	v31 = float32(v24)
	if v24 < 1.0 {
		v31 = 1.0
	}
	return int32(v31)
}
func sub_50E820(a1 int32, a2 int32) int32 {
	var (
		v3 int32
		v5 int32
	)
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*1)) = *(*uint16)(unsafe.Add(a2, 36))
	v3 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*0)) = 2505
	return nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 2064))), unsafe.Pointer(&v5), 4, nil, 1)
}
func nox_xxx_createShopStruct_50E870() *uint32 {
	var (
		v0 *uint32
		v1 *uint32
	)
	v0 = (*uint32)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_tradeSession_2386492)))
	v1 = v0
	if v0 == nil {
		return nil
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*2)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*3)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*6)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*7)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*8)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*9)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*10)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*11)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*5)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*12)) = nox_xxx_newObjectByTypeID_4E3810(internCStr("Gold"))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*13)) = nox_xxx_newObjectByTypeID_4E3810(internCStr("Gold"))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*15)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*14)) = dword_5d4594_2386500
	if dword_5d4594_2386500 != 0 {
		*(*uint32)(unsafe.Add(dword_5d4594_2386500, 60)) = uint32(uintptr(unsafe.Pointer(v1)))
	}
	dword_5d4594_2386500 = uint32(uintptr(unsafe.Pointer(v1)))
	return v1
}
func nox_xxx_loadShopItems_50E970(a1 unsafe.Pointer) {
	var (
		v2  int32
		v3  int32
		v4  uint32
		v5  *uint32
		v6  **byte
		v7  *uint8
		v8  *uint32
		v9  int32
		v10 *uint32
		v12 *uint32
	)
	var v13 int32
	var v14 uint32
	var v15 *uint32
	var v16 *uint32
	var v17 *uint32
	var v18 *uint32
	var v19 *uint32
	var v20 *uint32
	var v21 *uint32
	var v22 *uint32
	var v23 *uint32
	var v24 *uint32
	var v25 *uint32
	var v26 *uint32
	var v27 *uint32
	var v28 *uint32
	var v29 *uint32
	var v30 *uint32
	var v31 *uint32
	var v32 *uint32
	var v33 *uint8
	var v34 *uint8
	var v35 *uint32
	var v36 int32
	var v37 int32
	var v38 int32
	var v39 int32
	var v40 float32
	var v41 int32
	var v42 int32
	var v43 *uint8
	var v44 [20]uint8
	v1 := a1
	v2 = int32(*(*uint32)(unsafe.Add(a1, 8)))
	if v2 != 0 && int32(*(*uint8)(unsafe.Add(v2, 8)))&2 != 0 && int32(*(*uint8)(unsafe.Add(v2, 12)))&8 != 0 || (func() int32 {
		v2 = int32(*(*uint32)(unsafe.Add(a1, 12)))
		return v2
	}()) != 0 && int32(*(*uint8)(unsafe.Add(v2, 8)))&2 != 0 && int32(*(*uint8)(unsafe.Add(v2, 12)))&8 != 0 {
		v3 = v2
		if noxflags.HasGame(4096) {
			v40 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ShopAnkhCutoffStage")))
			v4 = uint32(int32(v40))
			if uint32(nox_game_getQuestStage_4E3CC0()) < v4 {
				v5 = nox_xxx_newObjectByTypeID_4E3810(internCStr("AnkhTradable"))
				if v5 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v5)
				}
			}
			if *memmap.PtrUint32(0x587000, 234816) != 0 {
				v6 = (**byte)(memmap.PtrOff(0x587000, 234816))
				v7 = (*uint8)(memmap.PtrOff(0x587000, 234816))
				for {
					v8 = nox_xxx_newObjectByTypeID_4E3810(*v6)
					if v8 != nil {
						nox_xxx_addItemToShopSession_50EE00(a1, v8)
					}
					v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1)))
					v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 4))
					v6 = (**byte)(unsafe.Pointer(v7))
					if v9 == 0 {
						break
					}
				}
			}
			v10 = nox_xxx_newObjectByTypeID_4E3810(internCStr("RewardMarker"))
			v11 := unsafe.Pointer(v10)
			if v10 != nil {
				v12 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*173)))
				v13 = nox_game_getQuestStage_4E3CC0()
				*v12 = 8
				v14 = uint32(v13 + 2)
				v15 = nox_server_rewardgen_activateMarker_4F0720(v11, uint32(v13+2))
				if v15 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v15)
				}
				*v12 = 8
				v16 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v16 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v16)
				}
				*v12 = 8
				v17 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v17 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v17)
				}
				*v12 = 8
				v18 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v18 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v18)
				}
				*v12 = 16
				v19 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v19 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v19)
				}
				*v12 = 16
				v20 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v20 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v20)
				}
				*v12 = 16
				v21 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v21 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v21)
				}
				*v12 = 16
				v22 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v22 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v22)
				}
				*v12 = 1
				v23 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v23 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v23)
				}
				*v12 = 1
				v24 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v24 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v24)
				}
				*v12 = 1
				v25 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v25 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v25)
				}
				*v12 = 1
				v26 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v26 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v26)
				}
				*v12 = 1
				v27 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v27 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v27)
				}
				*v12 = 1
				v28 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v28 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v28)
				}
				*v12 = 4
				v29 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v29 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v29)
				}
				*v12 = 4
				v30 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v30 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v30)
				}
				*v12 = 4
				v31 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
				if v31 != nil {
					nox_xxx_addItemToShopSession_50EE00(a1, v31)
				}
				if nox_common_randomInt_415FA0(0, 100) > 90 {
					*v12 = 2
					v32 = nox_server_rewardgen_activateMarker_4F0720(v11, v14)
					if v32 != nil {
						nox_xxx_addItemToShopSession_50EE00(a1, v32)
					}
				}
				nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v11))
			}
		} else {
			v33 = *(**uint8)(unsafe.Add(v3, 692))
			v43 = v33
			if v33 != nil {
				if int32(*v33) != 0 {
					v42 = 0
					if int32(*v33) != 0 {
						v34 = (*uint8)(unsafe.Add(unsafe.Pointer(v33), 8))
						for {
							v41 = 0
							if int32(*v34) != 0 {
								for {
									{
										var v34p uint32 = *(*uint32)(unsafe.Add(unsafe.Pointer(v34), -int(4*1)))
										v35 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(int32(v34p))))
										v36 = int32(uintptr(unsafe.Pointer(v35)))
										if v35 != nil {
											if *(*uint32)(unsafe.Add(unsafe.Pointer(v35), 4*2))&0x13001000 != 0 {
												v37 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v34), 4*2)))
												v38 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v34), 4*4)))
												*(*uint32)(unsafe.Pointer(&v44[4])) = *(*uint32)(unsafe.Add(unsafe.Pointer(v34), 4*3))
												*(*uint32)(unsafe.Pointer(&v44[0])) = uint32(v37)
												v39 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v34), 4*5)))
												*(*uint32)(unsafe.Pointer(&v44[8])) = uint32(v38)
												*(*uint32)(unsafe.Pointer(&v44[12])) = uint32(v39)
												nox_xxx_modifSetItemAttrs_4E4990((*server.Object)(v36), (*int32)(unsafe.Pointer(&v44[0])))
											}
											if *(*unsafe.Pointer)(unsafe.Add(v36, 704)) == ccall.FuncAddr(nox_xxx_XFerSpellReward_4F5F30) {
												**(**uint8)(unsafe.Add(v36, 736)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v34), 4))
											}
											if *(*unsafe.Pointer)(unsafe.Add(v36, 704)) == ccall.FuncAddr(Nox_xxx_XFerAbilityReward_4F6240) {
												**(**uint8)(unsafe.Add(v36, 736)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v34), 4))
											}
											if *(*unsafe.Pointer)(unsafe.Add(v36, 704)) == ccall.FuncAddr(Nox_xxx_XFerFieldGuide_4F6390) {
												libc.StrCpy(*(**byte)(unsafe.Add(v36, 736)), nox_xxx_getUnitNameByThingType_4E3A80(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v34), 4*1)))))
												v1 = a1
												v33 = v43
											}
											nox_xxx_addItemToShopSession_50EE00(v1, float32(v36))
										}
										v41++
									}
									if v41 >= int32(*v34) {
										break
									}
								}
							}
							v34 = (*uint8)(unsafe.Add(unsafe.Pointer(v34), 28))
							v42++
							if v42 >= int32(*v33) {
								break
							}
						}
					}
				}
			}
		}
	}
}
func nox_xxx_addItemToShopSession_50EE00(a1 unsafe.Pointer, a2 float32) *float32 {
	var (
		result *float32
		v3     *float32
		v4     uint32
		v5     int32
		i      *uint32
		v7     int32
	)
	result = (*float32)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_tradeItems_2386496)))
	v3 = result
	if result == nil {
		return result
	}
	*result = a2
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = uint32(nox_xxx_shopGetItemCost_50E3D0(1, a1, a2))
	v4 = uint32(sub_50EEC0((*uint32)(unsafe.Pointer(v3))))
	if *(*uint32)(unsafe.Add(a1, 20)) != 0 {
		if v4 <= uint32(sub_50EEC0(*(**uint32)(unsafe.Add(a1, 20)))) {
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*3)) = 0.0
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*2)) = *(*float32)(unsafe.Add(a1, 20))
			*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 20)), 12)) = uint32(uintptr(unsafe.Pointer(v3)))
			*(*uint32)(unsafe.Add(a1, 20)) = uint32(uintptr(unsafe.Pointer(v3)))
			result = v3
		} else {
			v5 = int32(*(*uint32)(unsafe.Add(a1, 20)))
			for i = *(**uint32)(unsafe.Add(v5, 8)); i != nil; i = *(**uint32)(unsafe.Add(v5, 8)) {
				if v4 <= uint32(sub_50EEC0(i)) {
					break
				}
				v5 = int32(*(*uint32)(unsafe.Add(v5, 8)))
			}
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*2)) = *(*float32)(unsafe.Add(v5, 8))
			v7 = int32(*(*uint32)(unsafe.Add(v5, 8)))
			if v7 != 0 {
				*(*uint32)(unsafe.Add(v7, 12)) = uint32(uintptr(unsafe.Pointer(v3)))
			}
			*(*uint32)(unsafe.Add(v5, 8)) = uint32(uintptr(unsafe.Pointer(v3)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)) = uint32(v5)
			result = v3
		}
	} else {
		*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*2)) = 0.0
		*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*3)) = 0.0
		*(*uint32)(unsafe.Add(a1, 20)) = uint32(uintptr(unsafe.Pointer(v3)))
		result = v3
	}
	return result
}
func sub_50EEC0(a1 *uint32) int32 {
	var (
		v1 int32
		v2 int32
		v3 *uint8
	)
	v1 = 16781312
	v2 = math.MaxUint8
	v3 = (*uint8)(memmap.PtrOff(0x581450, 10308))
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*a1)), 8))&uint32(v1) != 0 && (*(*uint32)(unsafe.Pointer(v3)) == 0 || *(*uint32)(unsafe.Pointer(v3))&*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*a1)), 12)) != 0) {
			break
		}
		v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 8))
		v2--
		if v1 == 0 {
			break
		}
	}
	return int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) | uint32(v2<<24))
}
func sub_50F2B0(a1 int32, a2 *uint32) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 *uint16
		i  int32
		v9 [18]byte
	)
	v2 = int32(*a2)
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))
	v4 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*a2)), 692)))
	v9[0] = 201
	v9[1] = 8
	*(*uint16)(unsafe.Pointer(&v9[4])) = *(*uint16)(unsafe.Add(v2, 36))
	*(*uint16)(unsafe.Pointer(&v9[2])) = *(*uint16)(unsafe.Add(v2, 4))
	*(*uint32)(unsafe.Pointer(&v9[6])) = uint32(v3)
	v6 = *(**uint16)(unsafe.Add(v2, 556))
	if v6 != nil {
		*(*uint32)(unsafe.Pointer(&v9[10])) = uint32(*v6)
	} else {
		*(*uint32)(unsafe.Pointer(&v9[10])) = 0
	}
	if *(*uint32)(unsafe.Add(v2, 8))&0x13001000 != 0 {
		for i = 0; i < 4; i++ {
			if *(*uint32)(v5) != 0 {
				v9[i+14] = *(*uint8)(unsafe.Add(*(*unsafe.Pointer)(v5), 4))
			} else {
				v9[i+14] = math.MaxUint8
			}
			v5 += 4
		}
	} else {
		*(*uint32)(unsafe.Pointer(&v9[14])) = math.MaxUint32
	}
	return nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 2064))), unsafe.Pointer(&v9[0]), 18, nil, 1)
}
func sub_50F3A0(a1 *uint32) {
	var (
		i *int32
		j *int32
	)
	for i = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*8))); i != nil; i = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*2))) {
		nox_xxx_inventoryPutImpl_4F3070((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*2))), (*server.Object)(unsafe.Pointer(uintptr(*i))), 1)
	}
	nox_xxx_playerAddGold_4FA590(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*2)), int32(**(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*12)), 692))))
	sub_50F450(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))))
	for j = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*9))); j != nil; j = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(j), 4*2))) {
		nox_xxx_inventoryPutImpl_4F3070((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*3))), (*server.Object)(unsafe.Pointer(uintptr(*j))), 1)
	}
	nox_xxx_playerAddGold_4FA590(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*3)), int32(**(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*13)), 692))))
	sub_50F450(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3))))
	sub_50F490(a1, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))))
	sub_50F490(a1, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3))))
	sub_510000(int32(uintptr(unsafe.Pointer(a1))))
}
func sub_50F450(a1 int32) int32 {
	var (
		v2 int32
		v4 [2]byte
	)
	v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	*(*uint16)(unsafe.Pointer(&v4[0])) = 457
	return nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 2064))), unsafe.Pointer(&v4[0]), 2, nil, 1)
}
func sub_50F490(a1 *uint32, a2 int32) int32 {
	var result int32
	result = a2
	*a1 = 0
	if int32(*(*uint8)(unsafe.Add(a2, 8)))&4 == 0 {
		return result
	}
	result = int32(*(*uint32)(unsafe.Add(a2, 748)))
	if *(**uint32)(unsafe.Add(result, 280)) == a1 {
		*(*uint32)(unsafe.Add(result, 280)) = 0
	}
	return result
}
func nox_xxx_shopExit_50F4C0(a1 *uint32) {
	var (
		v1 int32
		v2 int32
		v3 int32
	)
	sub_50F490(a1, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))))
	sub_50F490(a1, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3))))
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
	if int32(*(*uint8)(unsafe.Add(v1, 8)))&4 != 0 {
		nox_xxx_unitUnFreeze_4E7A60((*server.Object)(v1), 0)
	} else {
		nox_xxx_unitUnFreeze_4E7A60((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*3))), 0)
	}
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
	if int32(*(*uint8)(unsafe.Add(v2, 8)))&4 != 0 {
		nox_xxx_sendEndTradeMsg_50F560(v2)
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
	} else {
		nox_xxx_sendEndTradeMsg_50F560(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3))))
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
	}
	if noxflags.HasGame(4096) {
		*memmap.PtrPtr(0x5D4594, uintptr(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 748)), 276)), 2064)))*4)+2386364) = unsafe.Pointer(a1)
	} else {
		sub_510000(int32(uintptr(unsafe.Pointer(a1))))
	}
}
func nox_xxx_sendEndTradeMsg_50F560(a1 int32) int32 {
	var (
		v2 int32
		v4 int16
	)
	v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v4 = 713
	return nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 2064))), unsafe.Pointer(&v4), 2, nil, 1)
}
func nox_xxx_tradeAccept_50F5A0(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	var (
		v4 int32
		v5 int32
		v6 int32
	)
	v2 := *(*unsafe.Pointer)(unsafe.Add(a1, 8))
	if v2 == a2 {
		*(*uint32)(unsafe.Add(a1, 24)) = 1
	} else if *(*unsafe.Pointer)(unsafe.Add(a1, 12)) == a2 {
		*(*uint32)(unsafe.Add(a1, 28)) = 1
	}
	if int32(*(*uint8)(unsafe.Add(v2, 8)))&4 != 0 {
		sub_50F720(v2, (*uint32)(a1))
	}
	v3 := *(*unsafe.Pointer)(unsafe.Add(a1, 12))
	if int32(*(*uint8)(unsafe.Add(v3, 8)))&4 != 0 {
		sub_50F720(v3, (*uint32)(a1))
	}
	if *(*uint32)(unsafe.Add(a1, 24)) == 1 && *(*uint32)(unsafe.Add(a1, 28)) == 1 {
		sub_50F790(a1, int32(*(*uint32)(unsafe.Add(a1, 12))), *(**int32)(unsafe.Add(a1, 32)))
		sub_50F790(a1, int32(*(*uint32)(unsafe.Add(a1, 8))), *(**int32)(unsafe.Add(a1, 36)))
		sub_50F7F0(*(*unsafe.Pointer)(unsafe.Add(a1, 12)), int32(*(*uint32)(unsafe.Add(a1, 48))))
		sub_50F7F0(*(*unsafe.Pointer)(unsafe.Add(a1, 8)), int32(*(*uint32)(unsafe.Add(a1, 52))))
		sub_50F6B0(*(*unsafe.Pointer)(unsafe.Add(a1, 32)))
		v7 := *(*unsafe.Pointer)(unsafe.Add(a1, 36))
		*(*uint32)(unsafe.Add(a1, 32)) = 0
		sub_50F6B0(v7)
		v4 = int32(*(*uint32)(unsafe.Add(a1, 48)))
		*(*uint32)(unsafe.Add(a1, 36)) = 0
		**(**uint32)(unsafe.Add(v4, 692)) = 0
		**(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 52)), 692)) = 0
		v5 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		*(*uint32)(unsafe.Add(a1, 40)) = 0
		*(*uint32)(unsafe.Add(a1, 44)) = 0
		if v5 == 1 {
			v6 = int32(*(*uint32)(unsafe.Add(a1, 8)))
			if int32(*(*uint8)(unsafe.Add(v6, 8)))&4 != 0 {
				sub_50F6E0(v6)
			} else {
				sub_50F6E0(int32(*(*uint32)(unsafe.Add(a1, 12))))
			}
		} else {
			sub_50F3A0((*uint32)(a1))
		}
	}
}
func sub_50F6B0(a1 unsafe.Pointer) {
	result := a1
	if a1 != nil {
		for {
			v2 := *(*unsafe.Pointer)(unsafe.Add(result, 8))
			nox_alloc_class_free_obj_first((*nox_alloc_class)(nox_alloc_tradeItems_2386496), result)
			result = v2
			if v2 == nil {
				break
			}
		}
	}
}
func sub_50F6E0(a1 int32) int32 {
	var (
		v2 int32
		v4 int16
	)
	v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v4 = 1993
	return nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 2064))), unsafe.Pointer(&v4), 2, nil, 1)
}
func sub_50F720(a1 unsafe.Pointer, a2 *uint32) int32 {
	var (
		v3 int32
		v4 int32
		v5 int8
		v6 int8
	)
	v2 := a1
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*6)))
	v4 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v5 = 0
	*(*uint16)(unsafe.Add(unsafe.Pointer(&a1), unsafe.Sizeof(uint16(0))*0)) = 969
	*(*uint8)(unsafe.Add(unsafe.Pointer(&a1), 2)) = 0
	if v3 != 0 {
		v5 = int8(bool2int32(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*2)) != v2) + 1)
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a1), 2)) = uint8(int8(bool2int32(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*2)) != v2) + 1))
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*7)) == 0 {
		return nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 2064))), unsafe.Pointer(&a1), 3, nil, 1)
	}
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*3)) == v2 {
		v6 = int8(int32(v5) | 1)
	} else {
		v6 = int8(int32(v5) | 2)
	}
	*(*uint8)(unsafe.Add(unsafe.Pointer(&a1), 2)) = uint8(v6)
	return nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 2064))), unsafe.Pointer(&a1), 3, nil, 1)
}
func sub_50F790(a1 unsafe.Pointer, a2 int32, a3 *int32) {
	var (
		i  *int32
		v4 *float32
		v5 int32
	)
	for i = a3; i != nil; i = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*2))) {
		if int32(*(*uint8)(unsafe.Add(a2, 8)))&4 != 0 {
			nox_xxx_inventoryPutImpl_4F3070((*server.Object)(a2), (*server.Object)(unsafe.Pointer(uintptr(*i))), 1)
		} else {
			v4 = nox_xxx_addItemToShopSession_50EE00(a1, *(*float32)(unsafe.Pointer(i)))
			if v4 != nil {
				v5 = int32(*(*uint32)(unsafe.Add(a1, 8)))
				if int32(*(*uint8)(unsafe.Add(v5, 8)))&4 != 0 {
					sub_50F2B0(v5, (*uint32)(unsafe.Pointer(v4)))
				} else {
					sub_50F2B0(int32(*(*uint32)(unsafe.Add(a1, 12))), (*uint32)(unsafe.Pointer(v4)))
				}
			}
		}
	}
}
func sub_50F7F0(a1 unsafe.Pointer, a2 int32) {
	if int32(*(*uint8)(unsafe.Add(a1, 8)))&4 != 0 {
		nox_xxx_playerAddGold_4FA590(a1, int32(**(**uint32)(unsafe.Add(a2, 692))))
	}
}
func nox_xxx_tradeP2PUpdStuff_50FA00(a1 int32, a2 *uint32) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v7 [14]byte
	)
	v7[0] = 201
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*2)))
	v3 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v7[1] = 6
	if v2 == a1 {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)))
		*(*uint32)(unsafe.Pointer(&v7[2])) = **(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*12)), 692))
		if int32(*(*uint8)(unsafe.Add(v4, 8)))&4 != 0 {
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*13)))
			*(*uint32)(unsafe.Pointer(&v7[6])) = 0
		} else {
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*13)))
			*(*uint32)(unsafe.Pointer(&v7[6])) = *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*11)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*10))
		}
		*(*uint32)(unsafe.Pointer(&v7[10])) = **(**uint32)(unsafe.Add(v5, 692))
	} else if *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)) == uint32(a1) {
		*(*uint32)(unsafe.Pointer(&v7[2])) = **(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*13)), 692))
		if int32(*(*uint8)(unsafe.Add(v2, 8)))&4 != 0 {
			*(*uint32)(unsafe.Pointer(&v7[6])) = 0
		} else {
			*(*uint32)(unsafe.Pointer(&v7[6])) = *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*10)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*11))
		}
		*(*uint32)(unsafe.Pointer(&v7[10])) = **(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*12)), 692))
	}
	return nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 2064))), unsafe.Pointer(&v7[0]), 14, nil, 1)
}
func sub_50FB90(a1 *uint32) *uint32 {
	var (
		result *uint32
		v3     *int32
		v5     *int32
		v6     int32
		v7     int32
		v8     uint32
		v9     uint32
		v10    uint32
		v11    int32
		v12    uint32
		v13    uint32
		v14    int32
	)
	v1 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*2))
	result = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v1, 8)) & 4)))
	if !(uintptr(unsafe.Pointer(result)) != uintptr(4) || (int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*3)), 8)))&4) != 4) {
		return result
	}
	v3 = *(**int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*12)), 692))
	if result != nil {
		nox_xxx_playerAddGold_4FA590(v1, *v3)
	}
	*v3 = 0
	v4 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*3))
	v5 = *(**int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*13)), 692))
	if int32(*(*uint8)(unsafe.Add(v4, 8)))&4 != 0 {
		nox_xxx_playerAddGold_4FA590(v4, *v5)
	}
	*v5 = 0
	v6 = sub_50FD20(a1, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))))
	v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*10)) = uint32(v6)
	result = (*uint32)(unsafe.Pointer(uintptr(sub_50FD20(a1, v7))))
	v8 = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*10))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*11)) = uint32(uintptr(unsafe.Pointer(result)))
	if uint32(uintptr(unsafe.Pointer(result))) <= v8 {
		if uint32(uintptr(unsafe.Pointer(result))) < v8 {
			v12 = v8 - uint32(uintptr(unsafe.Pointer(result)))
			if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*3)), 8)))&4 != 0 {
				v13 = uint32(nox_xxx_playerGetGold_4FA6B0(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*3))))
				if v13 < v12 {
					*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*11)) += v13
					**(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*13)), 692)) += v13
					result = nox_xxx_playerSubGold_4FA5D0(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*3)), v13)
				} else {
					v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*13)))
					*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*11)) += v12
					**(**uint32)(unsafe.Add(v14, 692)) += v12
					result = nox_xxx_playerSubGold_4FA5D0(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*3)), v12)
				}
			} else {
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*11)) = v8
				result = *(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*13)), 692))
				*result += v12
			}
		}
	} else {
		v9 = uint32(uintptr(unsafe.Pointer(result))) - v8
		if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*2)), 8)))&4 != 0 {
			v10 = uint32(nox_xxx_playerGetGold_4FA6B0(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*2))))
			if v10 < v9 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*10)) += v10
				**(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*12)), 692)) += v10
				result = nox_xxx_playerSubGold_4FA5D0(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*2)), v10)
			} else {
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*10)) += v9
				**(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*12)), 692)) += v9
				result = nox_xxx_playerSubGold_4FA5D0(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*2)), v9)
			}
		} else {
			v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*12)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*10)) = v9 + v8
			result = *(**uint32)(unsafe.Add(v11, 692))
			*result += v9
		}
	}
	return result
}
func sub_50FD20(a1 *uint32, a2 int32) int32 {
	var (
		v2     int32
		v3     int32
		result int32
		v5     int32
	)
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) == uint32(a2) {
		v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*12)))
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))
	} else {
		v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*13)))
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
	}
	for result = int32(**(**uint32)(unsafe.Add(v2, 692))); v3 != 0; result += v5 {
		v5 = int32(*(*uint32)(unsafe.Add(v3, 4)))
		v3 = int32(*(*uint32)(unsafe.Add(v3, 8)))
	}
	return result
}
func nox_xxx_tradeP2PAddOfferMB_50FE20(a1 unsafe.Pointer, a2 int32) int32 {
	var (
		v2     *int32
		v3     int32
		result int32
		v5     *float32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
	)
	v2 = (*int32)(unsafe.Pointer(sub_50FFE0(*(**uint32)(unsafe.Add(a1, 32)), a2)))
	if v2 != nil {
		v3 = int32(*(*uint32)(unsafe.Add(a1, 8)))
	} else {
		result = int32(uintptr(unsafe.Pointer(sub_50FFE0(*(**uint32)(unsafe.Add(a1, 36)), a2))))
		v2 = (*int32)(result)
		if result == 0 {
			return result
		}
		v3 = int32(*(*uint32)(unsafe.Add(a1, 12)))
	}
	if int32(*(*uint8)(unsafe.Add(v3, 8)))&4 != 0 {
		nox_xxx_inventoryPutImpl_4F3070((*server.Object)(v3), (*server.Object)(unsafe.Pointer(uintptr(*v2))), 1)
	} else {
		v5 = nox_xxx_addItemToShopSession_50EE00(a1, *(*float32)(unsafe.Pointer(v2)))
		if v5 != nil {
			v6 = int32(*(*uint32)(unsafe.Add(a1, 8)))
			if (int32(*(*uint8)(unsafe.Add(v6, 8))) & 4) == 0 {
				v6 = int32(*(*uint32)(unsafe.Add(a1, 12)))
			}
			sub_50F2B0(v6, (*uint32)(unsafe.Pointer(v5)))
		}
	}
	v7 = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*2))
	if v7 != 0 {
		*(*uint32)(unsafe.Add(v7, 12)) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*3)))
	}
	v8 = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*3))
	if v8 != 0 {
		*(*uint32)(unsafe.Add(v8, 8)) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
	}
	if *(*uint32)(unsafe.Add(a1, 8)) == uint32(v3) {
		if *(**int32)(unsafe.Add(a1, 32)) == v2 {
			*(*uint32)(unsafe.Add(a1, 32)) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
		}
	} else if *(**int32)(unsafe.Add(a1, 36)) == v2 {
		*(*uint32)(unsafe.Add(a1, 36)) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
	}
	sub_50FB90((*uint32)(a1))
	*(*uint32)(unsafe.Add(a1, 24)) = 0
	*(*uint32)(unsafe.Add(a1, 28)) = 0
	v9 = int32(*(*uint32)(unsafe.Add(a1, 8)))
	if int32(*(*uint8)(unsafe.Add(v9, 8)))&4 != 0 {
		if (int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 12)), 8)))&4) == 0 && *(*uint32)(unsafe.Add(a1, 44)) <= uint32(*(*int32)(unsafe.Add(a1, 40))) {
			*(*uint32)(unsafe.Add(a1, 28)) = 1
		}
	} else if *(*uint32)(unsafe.Add(a1, 40)) <= uint32(*(*int32)(unsafe.Add(a1, 44))) {
		*(*uint32)(unsafe.Add(a1, 24)) = 1
	}
	if int32(*(*uint8)(unsafe.Add(v9, 8)))&4 != 0 {
		nox_xxx_tradeP2PUpdStuff_50FA00(v9, (*uint32)(a1))
		sub_50FF90(int32(*(*uint32)(unsafe.Add(a1, 8))), a1, *v2)
		sub_50F720(*(*unsafe.Pointer)(unsafe.Add(a1, 8)), (*uint32)(a1))
	}
	v10 = int32(*(*uint32)(unsafe.Add(a1, 12)))
	if int32(*(*uint8)(unsafe.Add(v10, 8)))&4 != 0 {
		nox_xxx_tradeP2PUpdStuff_50FA00(v10, (*uint32)(a1))
		sub_50FF90(int32(*(*uint32)(unsafe.Add(a1, 12))), a1, *v2)
		sub_50F720(*(*unsafe.Pointer)(unsafe.Add(a1, 12)), (*uint32)(a1))
	}
	nox_alloc_class_free_obj_first((*nox_alloc_class)(nox_alloc_tradeItems_2386496), unsafe.Pointer(v2))
	return 1
}
func sub_50FF90(a1 int32, a2 unsafe.Pointer, a3 int32) int32 {
	var (
		v4 int32
		v6 int32
	)
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v6), unsafe.Sizeof(uint16(0))*1)) = *(*uint16)(unsafe.Add(a3, 36))
	v4 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v6), unsafe.Sizeof(uint16(0))*0)) = 1481
	return nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 2064))), unsafe.Pointer(&v6), 4, nil, 1)
}
func sub_50FFE0(a1 *uint32, a2 int32) *uint32 {
	var result *uint32
	result = a1
	if a1 == nil {
		return nil
	}
	for *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*result)), 36)) != uint32(a2) {
		result = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(result), 4*2)))
		if result == nil {
			return nil
		}
	}
	return result
}
func sub_510000(a1 int32) {
	var (
		v1 *int32
		v2 *int32
		v3 int32
		v4 int32
	)
	v1 = *(**int32)(unsafe.Add(a1, 20))
	if v1 != nil {
		for {
			v2 = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*2)))
			nox_xxx_objectFreeMem_4E38A0((*server.Object)(unsafe.Pointer(uintptr(*v1))))
			nox_alloc_class_free_obj_first((*nox_alloc_class)(nox_alloc_tradeItems_2386496), unsafe.Pointer(v1))
			v1 = v2
			if v2 == nil {
				break
			}
		}
	}
	nox_xxx_objectFreeMem_4E38A0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(a1, 48))))
	nox_xxx_objectFreeMem_4E38A0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))))
	sub_50F6B0(*(*unsafe.Pointer)(unsafe.Add(a1, 32)))
	sub_50F6B0(*(*unsafe.Pointer)(unsafe.Add(a1, 36)))
	v3 = int32(*(*uint32)(unsafe.Add(a1, 56)))
	if v3 != 0 {
		*(*uint32)(unsafe.Add(v3, 60)) = *(*uint32)(unsafe.Add(a1, 60))
	}
	v4 = int32(*(*uint32)(unsafe.Add(a1, 60)))
	if v4 != 0 {
		*(*uint32)(unsafe.Add(v4, 56)) = *(*uint32)(unsafe.Add(a1, 56))
	}
	if uint32(a1) == dword_5d4594_2386500 {
		dword_5d4594_2386500 = *(*uint32)(unsafe.Add(a1, 56))
	}
	nox_alloc_class_free_obj_first((*nox_alloc_class)(nox_alloc_tradeSession_2386492), a1)
}
func nox_xxx_getSomeShopData_5103A0(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		v3 *uint8
		v4 int32
		i  int32
	)
	v2 = int32(*(*uint32)(unsafe.Add(a1, 8)))
	if int32(*(*uint8)(unsafe.Add(v2, 8)))&4 != 0 {
		v2 = int32(*(*uint32)(unsafe.Add(a1, 12)))
	}
	v3 = *(**uint8)(unsafe.Add(v2, 692))
	v4 = 0
	if int32(*v3) == 0 {
		return -1
	}
	for i = int32(uintptr(unsafe.Add(unsafe.Pointer(v3), 4))); sub_5103F0(a2, i) == 0; i += 28 {
		if func() int32 {
			p := &v4
			*p++
			return *p
		}() >= int32(*v3) {
			return -1
		}
	}
	return v4
}
func sub_5103F0(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		v3 int32
		v4 *uint32
		v5 int32
	)
	v2 = 0
	if a1 == 0 || a2 == 0 {
		return 0
	}
	if uint32(*(*uint16)(unsafe.Add(a1, 4))) != *(*uint32)(a2) {
		return v2
	}
	v3 = int32(*(*uint32)(unsafe.Add(a1, 8)))
	v2 = 1
	if uint32(v3)&0x13001000 != 0 {
		v4 = *(**uint32)(unsafe.Add(a1, 692))
		if *(*uint32)(unsafe.Add(a2, 12)) != *v4 {
			v2 = 0
		}
		if *(*uint32)(unsafe.Add(a2, 16)) != *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) {
			v2 = 0
		}
		if *(*uint32)(unsafe.Add(a2, 20)) != *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) {
			v2 = 0
		}
		if *(*uint32)(unsafe.Add(a2, 24)) != *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) {
			v2 = 0
		}
	}
	if v3&0x100 == 0 {
		return v2
	}
	v5 = int32(*(*uint32)(unsafe.Add(a1, 12)))
	if v5&1 != 0 || v5&4 != 0 {
		if uint32(**(**uint8)(unsafe.Add(a1, 736))) != *(*uint32)(unsafe.Add(a2, 8)) {
			return 0
		}
	} else if libc.StrCmp(*(**byte)(unsafe.Add(a1, 736)), nox_xxx_getUnitNameByThingType_4E3A80(int32(*(*uint32)(unsafe.Add(a2, 8))))) != 0 {
		v2 = 0
	}
	return v2
}
func sub_5108D0(a1 unsafe.Pointer, a2 unsafe.Pointer, a3 int32) *uint32 {
	var (
		v3     int32
		result *uint32
		v5     int32
		v6     int32
		v7     int32
		v8     uint8
		v9     *uint16
		v10    int16
		v11    [8]byte
	)
	v3 = 0
	result = *(**uint32)(unsafe.Add(a1, 504))
	v5 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v11[0] = 201
	v11[1] = 31
	*(*uint16)(unsafe.Pointer(&v11[2])) = uint16(int16(a3))
	if result == nil {
		return result
	}
	for *(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*9)) != uint32(a3) {
		result = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(result), 4*124)))
		if result == nil {
			return result
		}
	}
	v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*2)))
	if v6&0x1000 != 0 {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3))&0x47F0000 != 0 {
			v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*184)))
			v8 = *(*uint8)(unsafe.Add(v7, 109))
			if int32(*(*uint8)(unsafe.Add(v7, 108))) < int32(v8) {
				if int32(v8) != 0 {
					v3 = 1
				}
			}
		}
	}
	v9 = (*uint16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(result), 4*139)))
	if v9 != nil && (func() bool {
		v10 = int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*2)))
		return int32(*v9) != int32(v10)
	}()) && int32(v10) != 0 || v3 != 0 {
		*(*uint32)(unsafe.Pointer(&v11[4])) = uint32(nox_xxx_shopGetItemCost_50E3D0(2, a2, result))
		result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 2064))), unsafe.Pointer(&v11[0]), 8, nil, 1))))
	} else {
		nox_xxx_aud_501960(925, (*server.Object)(a1), 0, 0)
	}
	return result
}
func sub_510AE0(a1 *int32, a2 unsafe.Pointer, a3 *uint32) *uint32 {
	var (
		result *uint32
		v4     int32
		v5     int32
		v6     uint32
		v7     int32
		v8     int32
	)
	result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_playerGetGold_4FA6B0(unsafe.Pointer(a1)))))
	v4 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*126))
	v5 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*187))
	if v4 == 0 {
		return result
	}
	result = a3
	for *(**uint32)(unsafe.Add(v4, 36)) != a3 {
		v4 = int32(*(*uint32)(unsafe.Add(v4, 496)))
		if v4 == 0 {
			return result
		}
	}
	v6 = uint32(nox_xxx_shopGetItemCost_50E3D0(2, a2, float32(v4)))
	nox_xxx_playerSubGold_4FA5D0(unsafe.Pointer(a1), v6)
	nox_xxx_unitSetHP_4E4560((*server.Object)(v4), *(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 556)), 4)))
	nox_xxx_itemReportHealth_4D87A0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 2064))), (*server.Object)(v4))
	v7 = int32(*(*uint32)(unsafe.Add(v4, 8)))
	if v7&0x1000 != 0 && *(*uint32)(unsafe.Add(v4, 12))&0x47F0000 != 0 {
		v8 = int32(*(*uint32)(unsafe.Add(v4, 736)))
		if nox_xxx_rechargeItem_53C520(v4, 100) != 0 {
			nox_xxx_netReportCharges_4D82B0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 2064))), (*server.Object)(v4), int8(*(*uint8)(unsafe.Add(v8, 108))), int8(*(*uint8)(unsafe.Add(v8, 109))))
		}
	}
	sub_4D8870(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 2064))), (*server.Object)(unsafe.Pointer(a1)))
	nox_xxx_aud_501960(803, (*server.Object)(unsafe.Pointer(a1)), 2, *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
	return result
}
func sub_510D10(a1 *int32, a2 unsafe.Pointer, a3 int32, a4 uint32) {
	var (
		result uint16
		v5     int32
		v6     int32
		v7     int32
		v8     int32
	)
	nox_xxx_playerGetGold_4FA6B0(unsafe.Pointer(a1))
	result = uint16(a4)
	v5 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*187))
	v6 = 0
	if a4 != 0 {
		for {
			v7 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*126))
			if v7 == 0 {
				break
			}
			for {
				result = *(*uint16)(unsafe.Add(v7, 4))
				if int32(result) == a3 {
					break
				}
				v7 = int32(*(*uint32)(unsafe.Add(v7, 496)))
				if v7 == 0 {
					return
				}
			}
			sub_4ED0C0((*server.Object)(unsafe.Pointer(a1)), (*server.Object)(v7))
			nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v7))
			v8 = nox_xxx_shopGetItemCost_50E3D0(0, a2, float32(v7))
			nox_xxx_playerAddGold_4FA590(unsafe.Pointer(a1), v8)
			sub_4D8870(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 2064))), (*server.Object)(unsafe.Pointer(a1)))
			result = uint16(a4)
			if uint32(func() int32 {
				p := &v6
				*p++
				return *p
			}()) >= a4 {
				nox_xxx_aud_501960(307, (*server.Object)(unsafe.Pointer(a1)), 2, *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
				return
			}
		}
	}
}
func nox_xxx_shopCancelSession_510DC0(a1 *uint32) {
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) != 0 {
		nox_xxx_shopExit_50F4C0(a1)
	} else {
		sub_50F3A0(a1)
	}
}
func sub_510DE0(a1 unsafe.Pointer, a2 int32) unsafe.Pointer {
	var (
		v2 int32
		v3 *uint32
	)
	v2 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 280)))
	if v2 == 0 {
		return nil
	}
	v3 = *(**uint32)(unsafe.Add(v2, 20))
	if v3 == nil {
		return nil
	}
	for *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*v3)), 36)) != uint32(a2) {
		v3 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*2)))
		if v3 == nil {
			return nil
		}
	}
	return *(*unsafe.Pointer)(unsafe.Pointer(v3))
}
func sub_510E20(a1 int32) {
	if *memmap.PtrUint32(0x5D4594, uintptr(a1*4)+2386364) != 0 {
		sub_510000(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+2386364)))
	}
	*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+2386364) = 0
}
func sub_510E50() {
	dword_5d4594_2386564 = 0
}
func nox_xxx_updateSentryGlobe_510E60(obj *server.Object) {
	a1 := obj
	var (
		result int32
		v2     int32
		v3     float32
		v4     float32
		v5     float32
		v6     float32
		a2     types.Pointf
		v8     [2]int32
		a1a    float4
		v10    float4
	)
	result = int32(a1.ObjFlags)
	v2 = int32(a1.UpdateData)
	if result >= 0 {
		a1.Field125 = nil
		a1.InvNextItem = dword_5d4594_2386564
		if dword_5d4594_2386564 != 0 {
			*(*uint32)(unsafe.Add(dword_5d4594_2386564, 500)) = uint32(a1)
		}
		dword_5d4594_2386564 = uint32(a1)
		result = int32(a1.ObjFlags | 0x80000000)
		a1.ObjFlags = uint32(result)
	}
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 16)))&0x20 != 0 {
		result = int32(uintptr(unsafe.Pointer(nox_xxx_sentryUpdateList_510FD0((*uint32)(a1)))))
	}
	if a1.ObjFlags&0x1000000 != 0 {
		v3 = a1.PosVec.Y
		a1a.field_0 = a1.PosVec.X
		a1a.field_4 = v3
		a1a.field_8 = float32(math.Cos(float64(*(*float32)(v2)))*600.0 + float64(a1.PosVec.X))
		a1a.field_C = float32(math.Sin(float64(*(*float32)(v2)))*600.0 + float64(a1.PosVec.Y))
		if nox_xxx_mapTraceRay_535250(&a1a, &a2, nil, 5) != 0 {
			v4 = a1a.field_C
			a1.Pos39.X = a1a.field_8
			a1.Pos39.Y = v4
		} else {
			v5 = a2.X
			v6 = a2.Y
			a1.Pos39.X = a2.X
			a1.Pos39.Y = v6
			a1a.field_8 = v5
			a1a.field_C = v6
		}
		*(*float32)(v2) = *(*float32)(unsafe.Add(v2, 8)) + *(*float32)(v2)
		if float64(a1a.field_0) >= float64(a1a.field_8) {
			v10.field_8 = a1a.field_0
			v10.field_0 = a1a.field_8
		} else {
			v10.field_0 = a1a.field_0
			v10.field_8 = a1a.field_8
		}
		if float64(a1a.field_4) >= float64(a1a.field_C) {
			v10.field_C = a1a.field_4
			v10.field_4 = a1a.field_C
		} else {
			v10.field_4 = a1a.field_4
			v10.field_C = a1a.field_C
		}
		v8[0] = a1
		*(*unsafe.Pointer)(unsafe.Pointer(&v8[1])) = unsafe.Pointer(&a1a)
		nox_xxx_getUnitsInRect_517C10(&v10, nox_xxx_sentry_511020, unsafe.Pointer(&v8[0]))
	} else {
		*(*uint32)(v2) = *(*uint32)(unsafe.Add(v2, 4))
	}
}
func nox_xxx_sentryUpdateList_510FD0(a1 *uint32) *uint32 {
	var (
		result *uint32
		v2     int32
		v3     int32
	)
	result = a1
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) < 0 {
		v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*125)))
		if v2 != 0 {
			*(*uint32)(unsafe.Add(v2, 496)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*124))
		} else {
			dword_5d4594_2386564 = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*124))
		}
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*124)))
		if v3 != 0 {
			*(*uint32)(unsafe.Add(v3, 500)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*125))
		}
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) &= math.MaxInt32
	return result
}
func nox_xxx_sentry_511020(it *server.Object, data unsafe.Pointer) {
	a1 := it
	a2 := int32(uintptr(data))
	var (
		v2 int32
		v3 float64
		v6 int32
		v7 int32
		a3 types.Pointf
	)
	v2 = int32(a1.ObjFlags)
	if (v2&0x41) == 0 && ((v2&0x10) == 0 || noxflags.HasGame(4096) && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2 != 0 && (a1.ObjFlags&0x8000) != 0x8000) && a1.HealthData != nil && nox_xxx_mathPointOnTheLine_57C8A0(*(**float4)(unsafe.Add(a2, 4)), (*types.Pointf)(unsafe.Add(unsafe.Pointer(a1), 56)), &a3) != 0 {
		v3 = float64(a1.PosVec.Y - a3.Y)
		if float64(a1.Shape.Circle*a1.Shape.Circle) > v3*v3+float64((a1.PosVec.X-a3.X)*(a1.PosVec.X-a3.X)) {
			v7 = int32(*(*uint32)(a2))
			v6 = nox_xxx_findParentChainPlayer_4EC580((*server.Object)(*(*unsafe.Pointer)(a2)))
			ccall.AsFunc[func(int32, int32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 716)))(a1, v6, v7, 500, 16)
			nox_xxx_aud_501960(298, a1, 0, 0)
		}
	}
}
func sub_511100(a1 int32) {
	var (
		v1  int32
		v2  *byte
		v3  int32
		v4  float64
		v5  float64
		v6  float32
		v7  float32
		v8  float32
		v9  float32
		v10 float32
		v11 float32
		i   float32
		v13 float32
	)
	v1 = a1
	v2 = nox_common_playerInfoFromNum_417090(a1)
	v3 = int32(dword_5d4594_2386564)
	v4 = float64(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*5)))
	v9 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*908))) - v4)
	v13 = float32(float64(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*6))))
	v10 = *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*909)) - v13
	v11 = float32(v4 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*908))))
	for i = v13 + *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*909)); v3 != 0; v3 = int32(*(*uint32)(unsafe.Add(v3, 496))) {
		if *(*uint32)(unsafe.Add(v3, 16))&0x1000000 != 0 {
			if float64(*(*float32)(unsafe.Add(v3, 56))) >= float64(*(*float32)(unsafe.Add(v3, 156))) {
				v5 = float64(*(*float32)(unsafe.Add(v3, 56)))
				v6 = *(*float32)(unsafe.Add(v3, 156))
			} else {
				v5 = float64(*(*float32)(unsafe.Add(v3, 156)))
				v6 = *(*float32)(unsafe.Add(v3, 56))
			}
			if float64(*(*float32)(unsafe.Add(v3, 60))) >= float64(*(*float32)(unsafe.Add(v3, 160))) {
				v8 = *(*float32)(unsafe.Add(v3, 60))
				v7 = *(*float32)(unsafe.Add(v3, 160))
			} else {
				v7 = *(*float32)(unsafe.Add(v3, 60))
				v8 = *(*float32)(unsafe.Add(v3, 160))
			}
			if float64(v9) < v5 && float64(v11) > float64(v6) && float64(v10) < float64(v8) && float64(i) > float64(v7) {
				sub_511250(v1, (*float32)(v3))
			}
		} else {
			**(**uint32)(unsafe.Add(v3, 748)) = *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 748)), 4))
		}
	}
}
func sub_511250(a1 int32, a2 *float32) int32 {
	var (
		v2 int16
		v3 float32
		v4 int16
		v5 float32
		v7 [9]byte
	)
	v7[0] = 149
	v2 = int16(uint16(sub_419A30(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*14)))))
	v3 = *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*15))
	*(*uint16)(unsafe.Pointer(&v7[1])) = uint16(v2)
	v4 = int16(uint16(sub_419A30(v3)))
	v5 = *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*39))
	*(*uint16)(unsafe.Pointer(&v7[3])) = uint16(v4)
	*(*uint16)(unsafe.Pointer(&v7[5])) = uint16(sub_419A30(v5))
	*(*uint16)(unsafe.Pointer(&v7[7])) = uint16(sub_419A30(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*40))))
	return nox_netlist_addToMsgListCli_40EBC0(a1, 1, &v7[0], 9)
}
func nox_xxx_unitSetDecayTime_511660(a1p *server.Object, a2 int32) int32 {
	var (
		a1     = a1p
		result int32
		v3     uint32
		v4     int32
		v5     int32
		v6     int32
	)
	result = int32(a1.ObjFlags)
	if (uint32(result) & 0x10000) != 0 {
		return result
	}
	if uint32(result)&0x400000 != 0 {
		nox_xxx_decay_5116F0(a1)
	}
	v3 = gameFrame() + uint32(a2)
	v4 = 0
	a1.Field34 = gameFrame() + uint32(a2)
	v5 = int32(dword_5d4594_2386576)
	if dword_5d4594_2386576 != nil {
		for {
			if v3 < uint32(*(*int32)(unsafe.Add(v5, 136))) {
				break
			}
			v4 = v5
			v5 = int32(*(*uint32)(unsafe.Add(v5, 468)))
			if v5 == 0 {
				break
			}
		}
	}
	if v4 != 0 {
		*(*uint32)(unsafe.Add(v4, 468)) = uint32(uintptr(unsafe.Pointer(a1)))
		if v5 == 0 {
			v6 = int32(a1.ObjFlags)
			a1.Field117 = nil
			result = int32(uint32(v6) | 0x400000)
			a1.ObjFlags = uint32(result)
			return result
		}
	} else {
		dword_5d4594_2386576 = a1
	}
	a1.Field117 = uint32(v5)
	result = int32(a1.ObjFlags | 0x400000)
	a1.ObjFlags = uint32(result)
	return result
}
func nox_xxx_decay_5116F0(item *server.Object) {
	r1 := int32(item.ObjFlags)
	if uint32(r1)&0x400000 == 0 {
		return
	}
	item.ObjFlags = uint32(r1) & 0xFFBFFFFF
	r2 := dword_5d4594_2386576
	if dword_5d4594_2386576 == nil {
		return
	}
	var v2 *server.Object
	for r2 != item {
		v2 = r2
		r2 = r2.Field117
		if r2 == nil {
			return
		}
	}
	if r2 == nil {
		return
	}
	if v2 != nil {
		v2.Field117 = item.Field117
	} else {
		dword_5d4594_2386576 = item.Field117
	}
}
func nox_xxx_decay_511750() {
	var (
		v0 *uint32
		v1 *uint32
		v2 int32
	)
	v0 = dword_5d4594_2386576
	if dword_5d4594_2386576 != nil {
		for {
			v1 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v0), 4*117)))
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*123)) != 0 {
				nox_xxx_decay_5116F0((*server.Object)(unsafe.Pointer(v0)))
			} else {
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*34)) > gameFrame() {
					return
				}
				nox_xxx_decay_5116F0((*server.Object)(unsafe.Pointer(v0)))
				v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*5)))
				*(*uint8)(unsafe.Pointer(&v2)) = uint8(int8(v2 | 0x80))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*5)) = uint32(v2)
				nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(unsafe.Pointer(v0)))
			}
			v0 = v1
			if v1 == nil {
				break
			}
		}
	}
}
func nox_xxx_decayDestroy_5117B0() int32 {
	var (
		result int32
		v1     int32
	)
	result = int32(dword_5d4594_2386576)
	if dword_5d4594_2386576 != nil {
		for {
			v1 = int32(*(*uint32)(unsafe.Add(result, 468)))
			nox_xxx_decay_5116F0((*server.Object)(result))
			result = v1
			if v1 == 0 {
				break
			}
		}
		dword_5d4594_2386576 = nil
	} else {
		dword_5d4594_2386576 = nil
	}
	return result
}
func sub_5117F0(a1 *server.Object) int8 {
	var result int8
	result = int8(uintptr(unsafe.Pointer(a1)))
	if (int32(a1.ObjClass) & 1) == 0 {
		result = nox_xxx_unitHasCollideOrUpdateFn_537610(a1)
	}
	return result
}
func nox_xxx_unit_511810(a1 *server.Object) {
	if (int32(a1.ObjClass) & 1) == 0 {
		if sub_537580(unsafe.Pointer(a1)) != 0 {
			sub_5375A0(unsafe.Pointer(a1))
		}
	}
}
func nox_xxx_updateObjectsVelocity_5118A0(step float32) {
	var (
		v4  float64
		v5  float32
		v6  *float32
		v7  *uint8
		v8  int8
		v9  int32
		v10 float64
		v11 float64
		v12 float32
		v13 float32
		v15 types.Pointf
		v16 float4
	)
	if *memmap.PtrUint32(0x5D4594, 2386580) == 0 {
		*memmap.PtrUint32(0x5D4594, 2386580) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2386584) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2386588) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("MediumFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2386592) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("FlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2386596) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("LargeFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2386600) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallBlueFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2386604) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallBlueFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2386608) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("MediumBlueFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2386612) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("BlueFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2386616) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("LargeBlueFlameCleanse")))
	}
	for i := sub_537740(); i != nil; i = sub_537750(i) {
		sub_5481C0(i)
	}
	nox_xxx_updateSprings_5113A0()
	result := sub_537740()
	for j := result; result != nil; j = result {
		if int32(*(*uint8)(unsafe.Add(j, 16)))&2 != 0 || int32(*(*uint8)(unsafe.Add(j, 8)))&2 != 0 && nox_xxx_checkMobAction_50A0D0((*server.Object)(j), 67) != 0 {
			*(*uint32)(unsafe.Add(j, 100)) = 0
			*(*uint32)(unsafe.Add(j, 96)) = 0
			*(*uint32)(unsafe.Add(j, 84)) = 0
			*(*uint32)(unsafe.Add(j, 80)) = 0
		} else {
			if nox_xxx_testUnitBuffs_4FF350((*server.Object)(j), 5) != 0 || nox_xxx_testUnitBuffs_4FF350((*server.Object)(j), 25) != 0 || nox_xxx_testUnitBuffs_4FF350((*server.Object)(j), 28) != 0 {
				v4 = float64(*(*float32)(unsafe.Add(j, 96)))
				v13 = *(*float32)(unsafe.Add(j, 100))
			} else {
				v4 = float64(*(*float32)(unsafe.Add(j, 96)) + *(*float32)(unsafe.Add(j, 88)))
				v13 = *(*float32)(unsafe.Add(j, 100)) + *(*float32)(unsafe.Add(j, 92))
			}
			v5 = *(*float32)(unsafe.Add(j, 64))
			v6 = (*float32)(unsafe.Add(j, 64))
			*(*float32)(unsafe.Add(j, 80)) += float32((v4 - float64(*(*float32)(unsafe.Add(j, 80))**(*float32)(unsafe.Add(j, 112)))) * float64(step))
			*(*float32)(unsafe.Add(j, 84)) += (v13 - *(*float32)(unsafe.Add(j, 84))**(*float32)(unsafe.Add(j, 112))) * step
			v16.field_0 = v5
			v16.field_4 = *(*float32)(unsafe.Add(j, 68))
			v7 = (*uint8)(memmap.PtrOff(0x5D4594, 2386580))
			v16.field_8 = step**(*float32)(unsafe.Add(j, 80)) + *(*float32)(unsafe.Add(j, 64))
			v16.field_C = step**(*float32)(unsafe.Add(j, 84)) + *(*float32)(unsafe.Add(j, 68))
			v8 = int8(uint8((*(*uint32)(unsafe.Add(j, 16))>>12)&4 | 1))
			for uint32(*(*uint16)(unsafe.Add(j, 4))) != *(*uint32)(unsafe.Pointer(v7)) {
				v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 4))
				if int32(uintptr(unsafe.Pointer(v7))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 2386620))) {
					goto LABEL_20
				}
			}
			v8 = int8(uint8((*(*uint32)(unsafe.Add(j, 16))>>12)&4 | 0x41))
		LABEL_20:
			if nox_xxx_mapTraceRay_535250(&v16, nil, nil, v8) != 0 {
				*(*float32)(unsafe.Add(j, 64)) = v16.field_8
				*(*float32)(unsafe.Add(j, 68)) = v16.field_C
			}
			v9 = int32(*(*uint32)(unsafe.Add(j, 16)))
			if (v9&0x4000) == 0 && *(*uint32)(unsafe.Add(j, 556)) != 0 && nox_xxx_tileNFromPoint_411160((*types.Pointf)(unsafe.Add(j, 64))) == 6 {
				v15.X = 0.0
				v15.Y = 0.0
				nox_xxx_collSysAddCollision_548630(j, unsafe.Pointer(uintptr(6)), &v15)
			}
			v10 = float64(*v6 - *(*float32)(unsafe.Add(j, 56)))
			if v10 < 0.0 {
				v10 = -v10
			}
			v11 = float64(*(*float32)(unsafe.Add(j, 68)) - *(*float32)(unsafe.Add(j, 60)))
			if v11 < 0.0 {
				v11 = -v11
			}
			if v10 > 0.0099999998 || (func() bool {
				v12 = float32(v11)
				return float64(v12) > 0.0099999998
			}()) {
				nox_xxx_unitNeedSync_4E44F0((*server.Object)(j))
				nox_xxx_objectUnkUpdateCoords_4E7290((*server.Object)(j))
				nox_xxx_moveUpdateSpecial_517970((*server.Object)(j))
			}
		}
		result = sub_537750(j)
	}
}
func nox_xxx_script_511C50(a1 int32) *server.Object {
	var v1 *uint32
	if dword_587000_237036 != 0 {
		sub_511D20()
	}
	v1 = *(**uint32)(memmap.PtrOff(0x5D4594, 2386820))
	if *memmap.PtrUint32(0x5D4594, 2386820) == 0 {
		return nil
	}
	for int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*v1)), 16)))&0x20 != 0 || *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*v1)), 44)) != uint32(a1) {
		v1 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*2)))
		if v1 == nil {
			return nil
		}
	}
	sub_511CE0((*uint32)(memmap.PtrOff(0x5D4594, 2386820)), int32(uintptr(unsafe.Pointer(v1))))
	sub_511CB0((*uint32)(memmap.PtrOff(0x5D4594, 2386820)), int32(uintptr(unsafe.Pointer(v1))))
	return (*server.Object)(unsafe.Pointer(uintptr(*v1)))
}
func sub_511CB0(a1 *uint32, a2 int32) int32 {
	var result int32
	result = a2
	*(*uint32)(unsafe.Add(a2, 4)) = 0
	*(*uint32)(unsafe.Add(a2, 8)) = *a1
	if *a1 != 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*a1)), 4)) = uint32(a2)
	} else {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = uint32(a2)
	}
	*a1 = uint32(a2)
	return result
}
func sub_511CE0(a1 *uint32, a2 int32) int32 {
	var (
		result int32
		v3     int32
		v4     int32
	)
	result = a2
	v3 = int32(*(*uint32)(unsafe.Add(a2, 8)))
	if v3 != 0 {
		*(*uint32)(unsafe.Add(v3, 4)) = *(*uint32)(unsafe.Add(a2, 4))
	} else {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = *(*uint32)(unsafe.Add(a2, 4))
	}
	v4 = int32(*(*uint32)(unsafe.Add(a2, 4)))
	if v4 != 0 {
		*(*uint32)(unsafe.Add(v4, 8)) = *(*uint32)(unsafe.Add(a2, 8))
	} else {
		result = int32(*(*uint32)(unsafe.Add(a2, 8)))
		*a1 = uint32(result)
	}
	return result
}
func sub_511D20() int32 {
	var (
		v0     *uint8
		result int32
	)
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 2386628))
	*memmap.PtrUint32(0x5D4594, 2386820) = 0
	*memmap.PtrUint32(0x5D4594, 2386824) = 0
	*memmap.PtrUint32(0x5D4594, 2386620) = 0
	*memmap.PtrUint32(0x5D4594, 2386624) = 0
	for {
		result = sub_511CB0((*uint32)(memmap.PtrOff(0x5D4594, 2386620)), int32(uintptr(unsafe.Pointer(v0))))
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 12))
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 2386820))) {
			break
		}
	}
	dword_587000_237036 = 0
	return result
}
func nox_xxx_scriptPrepareFoundUnit_511D70(obj *server.Object) int32 {
	var (
		a1     = obj
		v1     *int32
		v2     int32
		result int32
		v4     int32
	)
	v1 = (*int32)(unsafe.Pointer(uintptr(sub_511DC0())))
	if v1 != nil {
		*v1 = a1
		result = sub_511CB0((*uint32)(memmap.PtrOff(0x5D4594, 2386820)), int32(uintptr(unsafe.Pointer(v1))))
	} else {
		v2 = int32(*memmap.PtrUint32(0x5D4594, 2386824))
		v4 = int32(*memmap.PtrUint32(0x5D4594, 2386824))
		**(**uint32)(memmap.PtrOff(0x5D4594, 2386824)) = uint32(a1)
		sub_511CE0((*uint32)(memmap.PtrOff(0x5D4594, 2386820)), v4)
		result = sub_511CB0((*uint32)(memmap.PtrOff(0x5D4594, 2386820)), v2)
	}
	return result
}
func sub_511DC0() int32 {
	var result int32
	result = int32(*memmap.PtrUint32(0x5D4594, 2386620))
	if *memmap.PtrUint32(0x5D4594, 2386620) == 0 {
		return 0
	}
	*memmap.PtrUint32(0x5D4594, 2386620) = *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 2386620), 8))
	return result
}
func sub_511DE0(a1 *server.Object) int32 {
	var (
		result int32
		v2     *uint32
	)
	result = int32(dword_587000_237036)
	if dword_587000_237036 != 0 {
		return result
	}
	v2 = *(**uint32)(memmap.PtrOff(0x5D4594, 2386820))
	if *memmap.PtrUint32(0x5D4594, 2386820) == 0 {
		return result
	}
	result = int32(uintptr(unsafe.Pointer(a1)))
	for unsafe.Pointer(uintptr(*v2)) != unsafe.Pointer(a1) {
		v2 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
		if v2 == nil {
			return result
		}
	}
	sub_511CE0((*uint32)(memmap.PtrOff(0x5D4594, 2386820)), int32(uintptr(unsafe.Pointer(v2))))
	result = sub_511CB0((*uint32)(memmap.PtrOff(0x5D4594, 2386620)), int32(uintptr(unsafe.Pointer(v2))))
	return result
}
func sub_511E20() int32 {
	var (
		result int32
		v1     int32
		v2     int32
	)
	result = int32(dword_587000_237036)
	if dword_587000_237036 != 0 {
		return result
	}
	v1 = int32(*memmap.PtrUint32(0x5D4594, 2386820))
	if *memmap.PtrUint32(0x5D4594, 2386820) == 0 {
		return result
	}
	for {
		v2 = int32(*(*uint32)(unsafe.Add(v1, 8)))
		sub_511CE0((*uint32)(memmap.PtrOff(0x5D4594, 2386820)), v1)
		result = sub_511CB0((*uint32)(memmap.PtrOff(0x5D4594, 2386620)), v1)
		v1 = v2
		if v2 == 0 {
			break
		}
	}
	return result
}
func nox_xxx_wallOpen_511F80(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 int8
		v4 int32
		v5 *byte
		v6 int32
		v7 types.Pointf
		v8 int32
	)
	v1 = a1
	if int32(*(*uint8)(unsafe.Add(a1, 4)))&4 != 0 {
		v2 = int32(*(*uint32)(unsafe.Add(a1, 28)))
		v3 = int8(*(*uint8)(unsafe.Add(v2, 21)))
		if int32(v3) != 3 && int32(v3) != 4 {
			v4 = int32(*(*uint32)(unsafe.Add(v2, 4)))
			*(*uint8)(unsafe.Add(v2, 21)) = 4
			v8 = int32(*(*uint32)(unsafe.Add(v2, 8)) * 23)
			v7.X = float32(float64(v4*23) + 11.5)
			v7.Y = float32(float64(v8) + 11.5)
			if nox_xxx_wallSounds_2386840 == 0 {
				v5 = nox_xxx_wallFindOpenSound_410EE0(int32(*(*uint8)(unsafe.Add(v1, 1))))
				v6 = nox_xxx_utilFindSound_40AF50(v5)
				nox_xxx_audCreate_501A30(v6, &v7, 0, 0)
			}
		}
	}
}
func nox_xxx_wallClose_512070(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 int8
		v4 int32
		v5 *byte
		v6 int32
		v7 types.Pointf
		v8 int32
	)
	v1 = a1
	if int32(*(*uint8)(unsafe.Add(a1, 4)))&4 != 0 {
		v2 = int32(*(*uint32)(unsafe.Add(a1, 28)))
		v3 = int8(*(*uint8)(unsafe.Add(v2, 21)))
		if int32(v3) != 1 && int32(v3) != 2 {
			v4 = int32(*(*uint32)(unsafe.Add(v2, 4)))
			*(*uint8)(unsafe.Add(v2, 21)) = 2
			v8 = int32(*(*uint32)(unsafe.Add(v2, 8)) * 23)
			v7.X = float32(float64(v4*23) + 11.5)
			v7.Y = float32(float64(v8) + 11.5)
			if nox_xxx_wallSounds_2386840 == 0 {
				v5 = nox_xxx_wallFindCloseSound_410F20(int32(*(*uint8)(unsafe.Add(v1, 1))))
				v6 = nox_xxx_utilFindSound_40AF50(v5)
				nox_xxx_audCreate_501A30(v6, &v7, 0, 0)
			}
		}
	}
}
func nox_xxx_wallToggle_512160(a1 int32) {
	var (
		v1 int32
		v2 int8
		v3 int32
		v4 *byte
		v5 int32
		v6 int32
		v7 types.Pointf
	)
	if int32(*(*uint8)(unsafe.Add(a1, 4)))&4 != 0 {
		v1 = int32(*(*uint32)(unsafe.Add(a1, 28)))
		v2 = int8(*(*uint8)(unsafe.Add(v1, 21)))
		if int32(v2) == 1 || int32(v2) == 2 {
			v5 = int32(*(*uint32)(unsafe.Add(v1, 4)))
			*(*uint8)(unsafe.Add(v1, 21)) = 4
			v7.X = float32(float64(v5*23) + 11.5)
			v7.Y = float32(float64(int32(*(*uint32)(unsafe.Add(v1, 8))*23)) + 11.5)
			if nox_xxx_wallSounds_2386840 != 0 {
				return
			}
			v4 = nox_xxx_wallFindOpenSound_410EE0(int32(*(*uint8)(unsafe.Add(a1, 1))))
		} else {
			v3 = int32(*(*uint32)(unsafe.Add(v1, 4)))
			*(*uint8)(unsafe.Add(v1, 21)) = 2
			v7.X = float32(float64(v3*23) + 11.5)
			v7.Y = float32(float64(int32(*(*uint32)(unsafe.Add(v1, 8))*23)) + 11.5)
			if nox_xxx_wallSounds_2386840 != 0 {
				return
			}
			v4 = nox_xxx_wallFindCloseSound_410F20(int32(*(*uint8)(unsafe.Add(a1, 1))))
		}
		v6 = nox_xxx_utilFindSound_40AF50(v4)
		nox_xxx_audCreate_501A30(v6, &v7, 0, 0)
	}
}
func nox_xxx_wallPreDestroyByPtr_5122C0(a1 int32) int32 {
	var (
		v1 int32
		v3 Point32
	)
	v1 = int32(*(*uint8)(unsafe.Add(a1, 6)))
	v3.X = int32(*(*uint8)(unsafe.Add(a1, 5)))
	v3.Y = v1
	return nox_xxx_wallPreDestroy_534DA0(&v3.X)
}
func nox_xxx_monsterLookAt_5125A0(obj *server.Object, a2 int32) *float32 {
	var (
		a1     = obj
		result *float32
		v3     int32
		v4     float32
		v5     float32
	)
	result = (*float32)(unsafe.Pointer(uintptr(nox_xxx_mathDirection4ToAngle_509E90(a2))))
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2 == 0 {
		return result
	}
	v3 = int32(a1.ObjFlags)
	if (v3 & 0x8000) != 0 {
		return result
	}
	v4 = float32(float64(*mem_getFloatPtr(0x587000, uint32(uintptr(unsafe.Pointer(result)))*8+194136))*10.0 + float64(a1.PosVec.X))
	v5 = float32(float64(*mem_getFloatPtr(0x587000, uint32(uintptr(unsafe.Pointer(result)))*8+194140))*10.0 + float64(a1.PosVec.Y))
	result = (*float32)(nox_xxx_monsterPushAction_50A260_impl(a1, 25))
	if result != nil {
		*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*1)) = v4
		*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*2)) = v5
	}
	return result
}
func nox_xxx_monsterWalkTo_514110(obj *server.Object, x float32, y float32) {
	var (
		a1     = obj
		result *int32
		v4     *int32
	)
	result = a1.ObjFlags
	if int32(*(*int8)(unsafe.Add(unsafe.Pointer(&result), 1))) >= 0 && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2 != 0 {
		nox_xxx_monsterClearActionStack_50A3A0(a1)
		v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(a1, 32))
		if v4 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = 8
		}
		result = (*int32)(nox_xxx_monsterPushAction_50A260_impl(a1, 8))
		if result != nil {
			*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*1)) = x
			*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*2)) = y
			*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*3)) = 0
		}
	}
}
func nox_xxx_monsterGoPatrol_515680(a1p *server.Object, a2p unsafe.Pointer) {
	var (
		a1       = a1p
		a2 int32 = int32(uintptr(a2p))
		v2 int32
		v3 int32
		v4 *int32
		v5 types.Pointf
	)
	v2 = int32(a1.UpdateData)
	if a1 != nil {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2 != 0 {
			v3 = int32(a1.ObjFlags)
			if (v3 & 0x8000) == 0 {
				v5.X = *(*float32)(unsafe.Add(a2, 8)) - *(*float32)(a2)
				v5.Y = *(*float32)(unsafe.Add(a2, 12)) - *(*float32)(unsafe.Add(a2, 4))
				nox_xxx_monsterClearActionStack_50A3A0(a1)
				v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(a1, 4))
				if v4 != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = int32(*(*uint32)(a2))
					*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) = int32(*(*uint32)(unsafe.Add(a2, 4)))
					*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) = nox_xxx_math_509ED0(&v5)
				}
				*(*uint32)(unsafe.Add(v2, 1312)) = *(*uint32)(unsafe.Add(a2, 16))
			}
		}
	}
}
func nox_xxx_unitHunt_5157A0(obj *server.Object) {
	var (
		a1     = obj
		result int32
	)
	if a1 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2 != 0 {
		result = int32(a1.ObjFlags)
		if int32(*(*int8)(unsafe.Add(unsafe.Pointer(&result), 1))) >= 0 {
			nox_xxx_monsterClearActionStack_50A3A0(a1)
			nox_xxx_monsterPushAction_50A260_impl(a1, 5)
		}
	}
}
func nox_xxx_unitIdle_515820(obj *server.Object) {
	var (
		a1     = obj
		result int32
	)
	if a1 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2 != 0 {
		result = int32(a1.ObjFlags)
		if int32(*(*int8)(unsafe.Add(unsafe.Pointer(&result), 1))) >= 0 {
			nox_xxx_monsterClearActionStack_50A3A0(a1)
			nox_xxx_monsterPushAction_50A260_impl(a1, 0)
		}
	}
}
func nox_xxx_unitSetFollow_5158C0(obj1 *server.Object, obj2 *server.Object) {
	var (
		a1 = obj1
		a2 = obj2
		v2 int32
		v3 *int32
	)
	if a1 != nil {
		if a2 != nil {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2 != 0 {
				if a1 != a2 {
					v2 = int32(a1.ObjFlags)
					if (v2 & 0x8000) == 0 {
						nox_xxx_monsterClearActionStack_50A3A0(a1)
						v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(a1, 3))
						if v3 != nil {
							*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = int32(a2.PosVec.X)
							*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*2)) = int32(a2.PosVec.Y)
							*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*3)) = a2
						}
					}
				}
			}
		}
	}
}
func nox_xxx_monsterActionMelee_515A30(a1 unsafe.Pointer, a2 *types.Pointf) {
	var (
		v2 int32
		v3 *int32
		v4 *float32
		v5 *float32
	)
	if a1 != nil {
		if int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
			v2 = int32(*(*uint32)(unsafe.Add(a1, 16)))
			if (v2 & 0x8000) == 0 {
				if nox_xxx_monsterCanMelee_534220(a1) != 0 {
					nox_xxx_monsterClearActionStack_50A3A0((*server.Object)(a1))
					v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 32))
					if v3 != nil {
						*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = 16
					}
					nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 16)
					v4 = (*float32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 51))
					if v4 != nil {
						*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*1)) = float32(sub_534470(a1) + float64(*(*float32)(unsafe.Add(a1, 176))))
						*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*3)) = a2.X
						*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*4)) = a2.Y
					}
					v5 = (*float32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 7))
					if v5 != nil {
						*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*1)) = a2.X
						*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*2)) = a2.Y
						*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*3)) = 0
					}
				}
			}
		}
	}
}
func nox_xxx_monsterMissileAttack_515B80(a1 unsafe.Pointer, a2 *uint32) {
	var (
		v2 int32
		v3 *int32
		v4 *int32
	)
	if a1 != nil {
		if a2 != nil {
			if int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
				v2 = int32(*(*uint32)(unsafe.Add(a1, 16)))
				if (v2 & 0x8000) == 0 {
					if nox_xxx_monsterCanShoot_534280(a1) != 0 {
						nox_xxx_monsterClearActionStack_50A3A0((*server.Object)(a1))
						v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 32))
						if v3 != nil {
							*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = 17
						}
						v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 17))
						if v4 != nil {
							*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = int32(*a2)
							*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))
							*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) = 0
						}
					}
				}
			}
		}
	}
}
func sub_515C80(a1 unsafe.Pointer, a2 *uint8) {
	if a1 != nil {
		if int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
			result := int32(*(*uint32)(unsafe.Add(a1, 748)))
			*(*uint8)(unsafe.Add(result, 1332)) = *a2
		}
	}
}
func nox_xxx_mobSetFightTarg_515D30(a1p *server.Object, a2p *server.Object) {
	var (
		a1 = a1p
		a2 = a2p
		v2 int32
		v3 int32
		v4 *int32
		v5 *int32
	)
	v2 = int32(a1.UpdateData)
	if a1 != nil {
		if a2 != nil {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2 != 0 {
				if a1 != a2 {
					v3 = int32(a1.ObjFlags)
					if (v3 & 0x8000) == 0 {
						nox_xxx_monsterClearActionStack_50A3A0(a1)
						*(*uint32)(unsafe.Add(v2, 1216)) = uint32(a2)
						nox_xxx_frameCounterSetCopyToNextFrame_5281D0()
						v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(a1, 32))
						if v4 != nil {
							*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = 15
						}
						v5 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(a1, 15))
						if v5 != nil {
							*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) = int32(a2.PosVec.X)
							*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*2)) = int32(a2.PosVec.Y)
							*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*3)) = int32(gameFrame())
						}
					}
				}
			}
		}
	}
}
func nox_server_scriptFleeFrom_515F70(a1p *server.Object, a2p unsafe.Pointer) {
	var (
		a1 int32   = int32(uintptr(unsafe.Pointer(a1p)))
		a2 *uint32 = (*uint32)(a2p)
		v2 int32
		v3 *int32
		v4 *int32
		v5 *int32
		v6 int32
		v7 int32
	)
	if a1 != 0 {
		if int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
			v2 = int32(*(*uint32)(unsafe.Add(a1, 16)))
			if (v2&0x8000) == 0 && nox_xxx_checkMobAction_50A0D0((*server.Object)(a1), 24) == 0 {
				v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 32))
				if v3 != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = 24
				}
				v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 41))
				if v4 != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = int32(gameFrame() + *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))
				}
				v5 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 24))
				if v5 != nil {
					v6 = int32(*a2)
					*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*a2)), 56)))
					v7 = int32(*(*uint32)(unsafe.Add(v6, 60)))
					*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*3)) = 0
					*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*2)) = v7
				}
			}
		}
	}
}
func sub_516090(a1p *server.Object, a2 uint32) {
	var (
		a1 = a1p
		v2 int32
		v3 *int32
		v4 *int32
	)
	if a1 != nil {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2 != 0 {
			v2 = int32(a1.ObjFlags)
			if (v2 & 0x8000) == 0 {
				v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(a1, 32))
				if v3 != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = 1
				}
				v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(a1, 1))
				if v4 != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = int32(gameFrame() + a2)
				}
			}
		}
	}
}
func sub_516570() int32 {
	var (
		v2 *uint8 = nil
		v1 int32  = int32(nox_xxx_getFirstPlayerUnit_4DA7C0())
	)
	if v1 != 0 {
		for {
			v2 = *(**uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 748)), 276))
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 2064))) == 31 {
				break
			}
			v1 = nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(v1))
			if v1 == 0 {
				break
			}
		}
	}
	nox_gameDisableMapDraw_5d4594_2650672 = 1
	if v2 == nil {
		return 0
	}
	return nox_xxx_netSendChapterEnd_4D9560(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 2064))), int8(*memmap.PtrUint8(0x5D4594, 2386828)), *memmap.PtrInt32(0x5D4594, 2386832))
}
func sub_516D00(a1p *server.Object) {
	var (
		a1 = unsafe.Pointer(a1p)
		v2 int32
	)
	if a1 != nil && int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
		v2 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		if (v2 & 0x8000) != 0 {
			*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 1440)) &= 0xFFEFFFFF
			nox_xxx_mobRaiseZombie_534AB0((*server.Object)(a1))
		}
	}
}
func nox_xxx_allocPendingOwnsArray_516EE0() int32 {
	dword_5d4594_2386920 = 0
	nox_alloc_pendingOwn_2386916 = unsafe.Pointer(nox_new_alloc_class(internCStr("PendingOwn"), 12, 512))
	return bool2int32(nox_alloc_pendingOwn_2386916 != nil)
}
func sub_516F10() int32 {
	var result int32
	nox_free_alloc_class((*nox_alloc_class)(nox_alloc_pendingOwn_2386916))
	result = 0
	nox_alloc_pendingOwn_2386916 = nil
	dword_5d4594_2386920 = 0
	return result
}
func sub_516F30() {
	nox_alloc_class_free_all((*nox_alloc_class)(nox_alloc_pendingOwn_2386916))
	dword_5d4594_2386920 = 0
}
func sub_516F90(a1 int32, a2 int32) *uint32 {
	var result *uint32
	result = (*uint32)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_pendingOwn_2386916)))
	if result == nil {
		return result
	}
	*result = uint32(a1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = uint32(a2)
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*2)) = dword_5d4594_2386920
	dword_5d4594_2386920 = uint32(uintptr(unsafe.Pointer(result)))
	return result
}
func sub_516FC0() {
	var (
		v0 *int32
		v1 int32
		v2 int32
	)
	v0 = dword_5d4594_2386920
	if dword_5d4594_2386920 != 0 {
		for {
			v1 = sub_4ECF10(*v0)
			v2 = sub_4ECF10(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*1)))
			if v1 != 0 && v2 != 0 {
				nox_xxx_unitSetOwner_4EC290((*server.Object)(v1), (*server.Object)(v2))
			}
			v0 = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v0), 4*2)))
			if v0 == nil {
				break
			}
		}
	}
	sub_516F30()
}
func nox_xxx_loadMonsterBin_517010() int32 {
	var buf [256]byte
	nox_monsterBin_head_2386924 = nil
	f := nox_binfile_open_408CC0(internCStr("monster.bin"), 0)
	if f == nil {
		return 0
	}
	defer nox_binfile_close_408D90(f)
	if nox_binfile_cryptSet_408D40(f, 23) == 0 {
		return 0
	}
	for {
		if nox_xxx_readStr_517090(f, &buf[0]) == 0 {
			return 1
		}
		if nox_xxx_servParseMonsterDef_517170(f, &buf[0]) == 0 {
			return 0
		}
	}
}
func nox_xxx_readStr_517090(a1 *FILE, a2 *uint8) int32 {
	var (
		v2       *uint8
		v3       int32
		v4       int32
		v5       int32
		v6       int32
		CharType [2]uint16
	)
	v2 = a2
	v3 = 0
	*(*uint32)(unsafe.Pointer(&CharType[0])) = 0
	v4 = 1
	for {
		for {
			v5 = v3
			nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&CharType[0])), 1, 1, a1)
			if nox_binfile_lastErr_409370(a1) == -1 {
				return 0
			}
			v3 = int32(*(*uint32)(unsafe.Pointer(&CharType[0])))
			v6 = bool2int32(unicode.IsSpace(rune(CharType[0])))
			if v6 != 0 {
				break
			}
			v4 = 0
			if v3 != 47 || v5 != 47 {
				*func() *uint8 {
					p := &v2
					x := *p
					*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
					return x
				}() = uint8(int8(v3))
			} else {
				sub_517140(a1)
				v2 = a2
				v3 = int32(*(*uint32)(unsafe.Pointer(&CharType[0])))
				v4 = 1
			}
		}
		if v4 == 0 {
			break
		}
	}
	*v2 = 0
	return 1
}
func sub_517140(a1 *FILE) int32 {
	var (
		v1     *FILE
		result int32
	)
	v1 = a1
	for {
		*(*uint8)(unsafe.Pointer(&a1)) = 0
		nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&a1)), 1, 1, v1)
		result = nox_binfile_lastErr_409370(v1)
		if result == -1 || int32(uint8(uintptr(unsafe.Pointer(a1)))) == 10 {
			break
		}
	}
	return result
}
func nox_xxx_servParseMonsterDef_517170(f *FILE, a2 *byte) int32 {
	var buf [256]byte
	def, _ := alloc.New(server.MonsterDef{})
	if def == nil {
		return 0
	}
	libc.StrCpy(&def.Name0[0], a2)
	for {
		if nox_xxx_readStr_517090(f, &buf[0]) == 0 || nox_strcmpi(internCStr("END"), &buf[0]) == 0 {
			def.Next244 = nox_monsterBin_head_2386924
			nox_monsterBin_head_2386924 = def
			return 1
		}
		if noxflags.HasGame(noxflags.GameModeCoop) || noxflags.HasGame(noxflags.GameFlag22) {
			if nox_strcmpi(internCStr("ARENA"), &buf[0]) == 0 {
				sub_517140(f)
				continue
			} else if nox_strcmpi(internCStr("SOLO"), &buf[0]) == 0 {
				continue
			}
		} else if noxflags.HasGame(noxflags.GameOnline) {
			if nox_strcmpi(internCStr("SOLO"), &buf[0]) == 0 {
				sub_517140(f)
				continue
			} else if nox_strcmpi(internCStr("ARENA"), &buf[0]) == 0 {
				continue
			}
		}
		v4 := (*uint8)(memmap.PtrOff(0x587000, 248192))
		if *memmap.PtrUint32(0x587000, 248192) != 0 {
			for {
				if nox_strcmpi(*(**byte)(unsafe.Pointer(v4)), &buf[0]) == 0 {
					break
				}
				v5 := int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*3)))
				v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 12))
				if v5 == 0 {
					break
				}
			}
		}
		if *(*uint32)(unsafe.Pointer(v4)) == 0 {
			alloc.Free(def)
			return 0
		}
		fptr := unsafe.Add(unsafe.Pointer(def), *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2)))
		switch *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) {
		case 0:
			nox_xxx_readStr_517090(f, &buf[0])
			*(*uint32)(fptr) = uint32(libc.Atoi(libc.GoString(&buf[0])))
		case 1:
			nox_xxx_readStr_517090(f, &buf[0])
			*(*float32)(fptr) = float32(libc.Atof(libc.GoString(&buf[0])))
		case 2:
			nox_xxx_readStr_517090(f, &buf[0])
			*(*uint32)(fptr) = uint32(nox_xxx_utilFindSound_40AF50(&buf[0]))
		case 3:
			nox_xxx_readStr_517090(f, &buf[0])
			if !nox_xxx_monsterLoadStrikeFn_549040(def, GoString(&buf[0])) {
				return 0
			}
		case 4:
			nox_xxx_readStr_517090(f, &buf[0])
			if nox_xxx_monsterLoadDieFn_5490E0(int32(uintptr(unsafe.Pointer(def))), &buf[0]) == 0 {
				return 0
			}
		case 5:
			nox_xxx_readStr_517090(f, &buf[0])
			if nox_xxx_monsterLoadDeadFn_549180(int32(uintptr(unsafe.Pointer(def))), &buf[0]) == 0 {
				return 0
			}
		case 6:
			v9 := uint32(0)
			nox_xxx_readStr_517090(f, &buf[0])
			set_bitmask_flags_from_plus_separated_names_423930(&buf[0], &v9, (**byte)(memmap.PtrOff(0x587000, 247536)))
			*(*uint16)(fptr) = uint16(int16(v9))
		case 7:
			nox_xxx_readStr_517090(f, (*byte)(fptr))
			if libc.StrCmp(internCStr("NULL"), (*byte)(fptr)) == 0 {
				*(*byte)(fptr) = 0
			}
		case 8:
			nox_xxx_readStr_517090(f, &buf[0])
			def.MeleeAttackDamageType124 = 18
			v7 := 0
			v8 := (*uint8)(memmap.PtrOff(0x587000, 247464))
			for {
				if nox_strcmpi(&buf[0], (*byte)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v8)), 7))) == 0 {
					def.MeleeAttackDamageType124 = uint32(v7)
					break
				}
				v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 4))
				v7++
				if int32(uintptr(unsafe.Pointer(v8))) >= int32(uintptr(memmap.PtrOff(0x587000, 247536))) {
					break
				}
			}
			if def.MeleeAttackDamageType124 == 18 {
				return 0
			}
		}
	}
}
func nox_xxx_monsterListFree_5174F0() {
	var next *server.MonsterDef
	for it := nox_monsterBin_head_2386924; it != nil; it = next {
		next = it.Next244
		alloc.Free(it)
	}
	nox_monsterBin_head_2386924 = nil
}
func nox_xxx_monsterList_517520() int32 {
	for it := nox_monsterBin_head_2386924; it != nil; it = it.Next244 {
		typ := nox_xxx_getNameId_4E3AA0(&it.Name0[0])
		it.TypeInd240 = uint32(typ)
		if typ == 0 {
			nox_xxx_monsterListFree_5174F0()
			return 0
		}
	}
	return 1
}
func Nox_xxx_monsterDefByTT_517560(typ int) *server.MonsterDef {
	for it := nox_monsterBin_head_2386924; it != nil; it = it.Next244 {
		if it.TypeInd240 == uint32(typ) {
			return it
		}
	}
	return nil
}
func sub_517870(a1p *server.Object) int16 {
	var (
		a1 = a1p
		v1 int32
		v2 int32
		v3 *uint16
	)
	v1 = int32(a1.ObjFlags)
	if v1&0x200 == 0 {
		return int16(v1)
	}
	sub_5178E0(0, unsafe.Add(unsafe.Pointer(a1), 256))
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8))) & 1) == 0 {
		v2 = 0
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 336))) != 0 {
			v3 = (*uint16)(unsafe.Add(unsafe.Pointer(a1), 272))
			for {
				sub_5178E0(1, unsafe.Pointer(v3))
				v2++
				v3 = (*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*8))
				if v2 >= int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 336))) {
					break
				}
			}
		}
		*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 336)) = 0
	}
	v1 = int32(a1.ObjFlags)
	*(*uint8)(unsafe.Add(unsafe.Pointer(&v1), 1)) &= 0xFD
	a1.ObjFlags = uint32(v1)
	return int16(v1)
}
func eachInRect518040(posp *types.Pointf, sz float32, fnc func(it *server.Object, data unsafe.Pointer), data unsafe.Pointer) {
	if posp == nil {
		return
	}
	pos := *posp
	p1 := pos.Sub(types.Ptf(sz, sz))
	p2 := pos.Add(types.Ptf(sz, sz))
	GetServer().S().Map.EachObjInRect(types.RectFromPointsf(p1, p2), func(it *server.Object) bool {
		if it == nil {
			return true
		}
		itc := it.CObj()
		var dist float64
		switch it.Shape.Kind {
		case server.ShapeKindCircle:
			dp := pos.Sub(it.PosVec)
			dist = float64(sz) - dp.Len() - float64(it.Shape.Circle.R)
		case server.ShapeKindBox:
			var v8 types.Pointf
			dist = sub_54A990(posp, sz, itc, &v8)
		default:
			dp := pos.Sub(it.PosVec)
			dist = float64(sz) - dp.Len()
		}
		if dist > 0.0 {
			fnc(it, data)
		}
		return true
	})
}
func sub_518770() int32 {
	var result int32
	result = nox_xxx_getNameId_4E3AA0(internCStr("TeleportPentagram"))
	*memmap.PtrUint32(0x5D4594, 2386972) = uint32(result)
	if result == 0 {
		return 0
	}
	result = nox_xxx_getNameId_4E3AA0(internCStr("PressurePlate"))
	*memmap.PtrUint32(0x5D4594, 2386976) = uint32(result)
	if result == 0 {
		return 0
	}
	result = nox_xxx_getNameId_4E3AA0(internCStr("Spike"))
	*memmap.PtrUint32(0x5D4594, 2386980) = uint32(result)
	if result == 0 {
		return 0
	}
	result = nox_xxx_getNameId_4E3AA0(internCStr("PeriodicSpike"))
	*memmap.PtrUint32(0x5D4594, 2386984) = uint32(result)
	if result == 0 {
		return 0
	}
	return 1
}
func nox_xxx_netSendPhantomPlrMb_5187E0(a1 int32, a2 int32) int32 {
	var (
		v2  int16
		v3  float32
		v4  int16
		v5  float32
		v6  int32
		v7  int8
		a2a Point32
		v10 [11]byte
	)
	v10[0] = 48
	*(*uint16)(unsafe.Pointer(&v10[3])) = *(*uint16)(unsafe.Add(a2, 4))
	v2 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(a2))))
	v3 = *(*float32)(unsafe.Add(a2, 56))
	*(*uint16)(unsafe.Pointer(&v10[1])) = uint16(v2)
	v4 = int16(int32(v3))
	v5 = *(*float32)(unsafe.Add(a2, 60))
	*(*uint16)(unsafe.Pointer(&v10[5])) = uint16(v4)
	v6 = int32(v5)
	*(*uint16)(unsafe.Pointer(&v10[7])) = uint16(int16(v6))
	if int32(*(*uint8)(unsafe.Add(a2, 8)))&1 != 0 && int32(*(*uint8)(unsafe.Add(a2, 12)))&0x30 != 0 {
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v6), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(a2, 124))
		v10[10] = byte(int8(v6 >> 3))
	} else {
		v10[10] = math.MaxUint8
	}
	nox_xxx_xferIndexedDirection_509E20(int32(*(*int16)(unsafe.Add(a2, 124))), &a2a)
	if int32(uint8(int8(int32(*(*uint8)(unsafe.Pointer(&a2a.X)))+int32(*(*uint8)(unsafe.Pointer(&a2a.Y)))*3+4))) <= 3 {
		v7 = int8(int32(*(*uint8)(unsafe.Pointer(&a2a.X))) + int32(*(*uint8)(unsafe.Pointer(&a2a.Y)))*3 + 4)
	} else {
		v7 = int8(int32(*(*uint8)(unsafe.Pointer(&a2a.X))) + int32(*(*uint8)(unsafe.Pointer(&a2a.Y)))*3 + 3)
	}
	v10[9] = byte(int8(int32(v7) * 16))
	return bool2int32(nox_netlist_addToMsgListSrv_40EF40(a1, &v10[0], 11))
}
func nox_xxx_netSendSimpleObj_5188A0(a1 int32, a2 int32) int32 {
	var (
		v2  *int16
		v3  int32
		v4  int16
		v5  int16
		v6  int16
		v7  int16
		v8  float32
		v10 [9]byte
	)
	if *(*uint32)(unsafe.Add(a2, 8))&0x20000 != 0 {
		v2 = *(**int16)(unsafe.Add(a2, 556))
		if v2 != nil {
			v3 = int32(*(*uint32)(unsafe.Add(a2, 748)))
			if (gameFrame() - *(*uint32)(unsafe.Add(a2, 536))) > 2 {
				v4 = *v2
				v5 = int16(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v3+a1*2)), 96)))
				if int32(v4) != int32(v5) {
					nox_xxx_netReportHealthDelta_4D8760(a1, int16(uint16(*(*uint32)(unsafe.Add(a2, 36)))), int16(int32(v4)-int32(v5)))
					*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v3+a1*2)), 96)) = **(**uint16)(unsafe.Add(a2, 556))
				}
			}
		}
	}
	v6 = int16(*(*uint16)(unsafe.Add(a2, 4)))
	v10[0] = 47
	*(*uint16)(unsafe.Pointer(&v10[3])) = uint16(v6)
	*(*uint16)(unsafe.Pointer(&v10[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(a2)))
	v7 = int16(int32(*(*float32)(unsafe.Add(a2, 56))))
	v8 = *(*float32)(unsafe.Add(a2, 60))
	*(*uint16)(unsafe.Pointer(&v10[5])) = uint16(v7)
	*(*uint16)(unsafe.Pointer(&v10[7])) = uint16(int16(int32(v8)))
	return bool2int32(nox_netlist_addToMsgListSrv_40EF40(a1, &v10[0], 9))
}
func nox_xxx_netSendComplexObject_518960(a1 int32, a2 *uint32, a3 int32) int32 {
	var (
		v3  int32
		v4  *uint32
		v5  *int16
		v6  int32
		v7  int16
		v8  int16
		v9  int16
		v10 int16
		v11 float32
		v12 int16
		v13 int32
		v14 int8
		v15 int8
		a2a Point32
		v18 [11]byte
	)
	v3 = a1
	v4 = a2
	if a3 != 0 {
		v5 = (*int16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*139)))
		if v5 != nil {
			v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*187)))
			if (gameFrame() - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*134))) > 2 {
				v7 = *v5
				v8 = int16(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v6+a1*2)), 412)))
				if int32(v7) != int32(v8) {
					nox_xxx_netReportHealthDelta_4D8760(a1, int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*9)))), int16(int32(v7)-int32(v8)))
					*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v6+v3*2)), 412)) = *(*uint16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*139)))
				}
			}
		}
	}
	v9 = int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*2)))
	v18[0] = 48
	*(*uint16)(unsafe.Pointer(&v18[3])) = uint16(v9)
	*(*uint16)(unsafe.Pointer(&v18[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(v4))))
	v10 = int16(int32(*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*14))))
	v11 = *(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*15))
	*(*uint16)(unsafe.Pointer(&v18[5])) = uint16(v10)
	v12 = int16(int32(v11))
	v13 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*187)))
	*(*uint16)(unsafe.Pointer(&v18[7])) = uint16(v12)
	v18[9] = byte(int8(nox_xxx_mobActionToAnimation_533790(AsObjectP(unsafe.Pointer(v4)))))
	v14 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 12)))
	v18[10] = *(*uint8)(unsafe.Add(v13, 481))
	if int32(v14)&0x10 != 0 && int32(*(*uint8)(unsafe.Add(v13, 2094))) != 0 && nox_common_randomInt_415FA0(0, 10) >= 8 {
		v18[9] = 14
		nox_xxx_animPlayerGetFrameRange_4F9F90(50, &a3, &a1)
		v18[10] = byte(int8(nox_common_randomInt_415FA0(0, a3)))
	}
	nox_xxx_xferIndexedDirection_509E20(int32(*(*int16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(int16(0))*62))), &a2a)
	*(*uint8)(unsafe.Pointer(&a3)) = uint8(int8(int32(*(*uint8)(unsafe.Pointer(&a2a.X))) + int32(*(*uint8)(unsafe.Pointer(&a2a.Y)))*3 + 4))
	if int32(uint8(int8(a3))) <= 3 {
		v15 = int8(a3)
	} else {
		v15 = int8(a3 - 1)
	}
	v18[9] |= byte(int8(int32(v15) * 16))
	return bool2int32(nox_netlist_addToMsgListSrv_40EF40(v3, &v18[0], 11))
}
func nox_xxx_netSpriteUpdate_518AE0(a1 int32, a2 int32, a3 *uint32) int32 {
	var (
		v3  *uint32
		v4  int16
		v5  int32
		v7  int32
		v8  int8
		v9  int32
		v10 int8
		v11 uint8
		v12 int32
		v13 int32
		v14 uint8
		v15 int8
	)
	v3 = a3
	v4 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a3)))))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2)))
	*(*uint16)(unsafe.Add(unsafe.Pointer(&a3), 1)) = uint16(v4)
	if uint32(v5)&0x400000 != 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3))&0x18 != 0 {
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a3), unsafe.Sizeof((*uint32)(nil))-1)) = *(*uint8)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*187)))
		*(*uint8)(unsafe.Pointer(&a3)) = 179
		return nox_xxx_netSendPacket1_4E5390(a2, unsafe.Pointer(&a3), 4, nil, 1)
	}
	v7 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*2)))
	if uint32(uint16(int16(v7))) == *memmap.PtrUint32(0x5D4594, 2386972) {
		v8 = int8(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*187)), 20)))
		*(*uint8)(unsafe.Pointer(&a3)) = 57
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a3), unsafe.Sizeof((*uint32)(nil))-1)) = uint8(v8)
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, (*uint8)(unsafe.Pointer(&a3)), 4)
	}
	if uint32(v7) == *memmap.PtrUint32(0x5D4594, 2386980) {
		v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*4)))
		*(*uint8)(unsafe.Pointer(&a3)) = 57
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a3), unsafe.Sizeof((*uint32)(nil))-1)) = uint8(int8(int32(^(*(*uint8)(unsafe.Add(unsafe.Pointer(&v9), 4-1)))) & 1))
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, (*uint8)(unsafe.Pointer(&a3)), 4)
	}
	if uint32(v7) == *memmap.PtrUint32(0x5D4594, 2386976) {
		v10 = int8(*(*uint8)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*187))))
		*(*uint8)(unsafe.Pointer(&a3)) = 180
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a3), unsafe.Sizeof((*uint32)(nil))-1)) = uint8(int8(int32(v10) & 1))
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, (*uint8)(unsafe.Pointer(&a3)), 4)
	}
	if v5&0x4000 != 0 {
		v11 = *(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*187)), 16))
		*(*uint8)(unsafe.Pointer(&a3)) = 57
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a3), unsafe.Sizeof((*uint32)(nil))-1)) = uint8(int8(int32(v11) >> 2))
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, (*uint8)(unsafe.Pointer(&a3)), 4)
	}
	if (v5 & 0x8000) != 0 {
		v12 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*187)))
		if v12 != 0 && (func() int32 {
			v13 = int32(*(*uint32)(unsafe.Add(v12, 4)))
			return v13
		}()) != 0 {
			v14 = *(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v13, 748)), 16))
			*(*uint8)(unsafe.Pointer(&a3)) = 57
			*(*uint8)(unsafe.Add(unsafe.Pointer(&a3), unsafe.Sizeof((*uint32)(nil))-1)) = uint8(int8(int32(v14) >> 2))
		} else {
			*(*uint8)(unsafe.Add(unsafe.Pointer(&a3), unsafe.Sizeof((*uint32)(nil))-1)) = 0
			*(*uint8)(unsafe.Pointer(&a3)) = 57
		}
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, (*uint8)(unsafe.Pointer(&a3)), 4)
	}
	if (v5 & 0x80) != 0 {
		v15 = int8(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*187)), 12)))
		*(*uint8)(unsafe.Pointer(&a3)) = 178
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a3), unsafe.Sizeof((*uint32)(nil))-1)) = uint8(v15)
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, (*uint8)(unsafe.Pointer(&a3)), 4)
	}
	nox_xxx_netUpdateObjectSpecial_527E50((*server.Object)(a1), (*server.Object)(unsafe.Pointer(v3)))
	return 0
}
func nox_xxx_netPlayerObjSend_518C30(a1p *server.Object, a2p *server.Object, a3 int32, a4 int32) int32 {
	var (
		a1     = a1p
		a2     = a2p
		v5     *uint32
		v6     int32
		v7     int32
		v8     *int16
		v9     int16
		v10    int16
		v11    int16
		v12    int16
		v13    float32
		v14    int16
		v15    float32
		v16    int8
		v17    int8
		v18    int32
		v19    int8
		result int32
		a2a    Point32
		v22    [12]byte
		v23    int32
	)
	v4 := a1
	v5 = a2
	v23 = int32(a1.UpdateData)
	v6 = int32(a2.UpdateData)
	v7 = int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v23, 276)), 2064)))
	if a4 != 0 {
		v8 = (*int16)(a2.HealthData)
		if v8 != nil {
			if (gameFrame() - a2.Frame134) > 2 {
				v9 = *v8
				v10 = int16(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v6+v7*2)), 12)))
				if int32(v9) != int32(v10) {
					nox_xxx_netReportHealthDelta_4D8760(v7, int16(uint16(a2.NetCode)), int16(int32(v9)-int32(v10)))
					*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v6+v7*2)), 12)) = *(*uint16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v5), 4*139)))
				}
			}
		}
	}
	if (*uint32)(v4) == v5 {
		nox_xxx_playerReportAnything_4D9900(v4)
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v23, 276))+uint32(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v6, 276)), 2064)))*4))), 4452)) = gameFrame()
	v11 = int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*2)))
	v22[0] = 195
	*(*uint16)(unsafe.Pointer(&v22[3])) = uint16(v11)
	v12 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(v5)))))
	v13 = *(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*14))
	*(*uint16)(unsafe.Pointer(&v22[1])) = uint16(v12)
	v14 = int16(int32(v13))
	v15 = *(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*15))
	*(*uint16)(unsafe.Pointer(&v22[5])) = uint16(v14)
	*(*uint16)(unsafe.Pointer(&v22[7])) = uint16(int16(int32(v15)))
	v22[9] = 0
	v22[11] = byte(int8(nox_common_mapPlrActionToStateId_4FA2B0((*server.Object)(unsafe.Pointer(v5)))))
	v16 = int8(*(*uint8)(unsafe.Add(v6, 88)))
	if int32(v16) == 1 || int32(v16) == 10 || int32(v16) == 2 || int32(v16) == 15 || int32(v16) == 16 || int32(v16) == 17 || int32(v16) == 14 || int32(v16) == 20 || int32(v16) == 18 || int32(v16) == 19 || int32(v16) == 21 || int32(v16) == 22 || int32(v16) == 24 || int32(v16) == 25 || int32(v16) == 27 || int32(v16) == 28 || int32(v16) == 29 || int32(v16) == 26 || int32(v16) == 30 || int32(v16) == 32 {
		v22[10] = *(*uint8)(unsafe.Add(v6, 236))
	} else {
		v22[10] = math.MaxUint8
	}
	if int32(*(*uint16)(unsafe.Add(v6, 160))) != 0 && nox_common_randomInt_415FA0(0, 10) >= 8 {
		v22[11] = 50
		v22[10] = math.MaxUint8
	}
	v17 = int8(*(*uint8)(unsafe.Add(v6, 88)))
	if (int32(v17) == 3 || int32(v17) == 4) && *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*131)) == 16 {
		v22[11] = 51
		v22[10] = math.MaxUint8
	}
	if int32(*(*uint8)(unsafe.Add(v6, 88))) != 30 && *(*uint32)(unsafe.Add(v6, 164)) != 0 {
		nox_xxx_animPlayerGetFrameRange_4F9F90(52, &a4, (*int32)(unsafe.Pointer(&a2)))
		v18 = int32((gameFrame() - *(*uint32)(unsafe.Add(v6, 164))) / (uint32(uintptr(unsafe.Pointer(a2))) + 1))
		if v18 >= a4 || (gameFrame()-*(*uint32)(unsafe.Add(v6, 164))) >= 4 {
			*(*uint32)(unsafe.Add(v6, 164)) = 0
		} else {
			v22[11] = 52
			v22[10] = byte(int8(v18))
		}
	}
	nox_xxx_xferIndexedDirection_509E20(int32(*(*int16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(int16(0))*62))), &a2a)
	*(*uint8)(unsafe.Pointer(&a2)) = uint8(int8(int32(*(*uint8)(unsafe.Pointer(&a2a.X))) + int32(*(*uint8)(unsafe.Pointer(&a2a.Y)))*3 + 4))
	if int32(uint8(uintptr(unsafe.Pointer(a2)))) <= 3 {
		v19 = int8(uintptr(unsafe.Pointer(a2)))
	} else {
		v19 = int8(int32(uint8(uintptr(unsafe.Pointer(a2)))) - 1)
	}
	v22[9] |= byte(int8(int32(v19) * 16))
	if a3 != 0 {
		result = bool2int32(nox_netlist_addToMsgListSrv_40EF40(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v23, 276)), 2064))), &v22[0], 12))
	} else {
		result = nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v23, 276)), 2064))), 1, &v22[0], 12)
	}
	return result
}
func nox_xxx_netSendObjects2Plr_519410(a1p *server.Object, a2p *server.Object) int8 {
	var (
		a1  = a1p
		a2  = a2p
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  float32
		v10 float32
		v11 int32
		v13 int32
		v14 float4
	)
	v4 = int32(a1.UpdateData)
	v13 = v4
	v2 = 0
	v3 = int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 2064)))
	*(*uint8)(unsafe.Pointer(&v4)) = *(*uint8)(unsafe.Add(unsafe.Pointer(a2), 16))
	v5 = v3
	if !((v4&0x20) == 0 && (a2.ObjClass&0x40000000) == 0) {
		return int8(v4)
	}
	v6 = 1 << v3
	if a2 != a1 && uint32(v6)&a2.Field35 != 0 {
		nox_xxx_netFriendAddRemove_4D97A0(v3, a2, bool2int32((uint32(v6)&a2.Field36) != 0))
		*(*uint8)(unsafe.Pointer(&v4)) = ^uint8(int8(v6))
		a2.Field35 &= uint32(^v6)
	}
	if !(uint32(v6)&a2.Field38 != 0 || int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 8)))&1 != 0) {
		return int8(v4)
	}
	v7 = int32(a2.ObjFlags)
	if !((v7&0x800) == 0 || nox_xxx_unitHasThatParent_4EC4F0(a2, a1) != 0 || (func() int32 {
		v4 = bool2int32(noxflags.HasGame(512))
		return v4
	}()) != 0) {
		return int8(v4)
	}
	v8 = int32(*(*uint32)(unsafe.Add(v13, 276)))
	v14.field_0 = *(*float32)(unsafe.Add(v8, 3632))
	v9 = a2.PosVec.Y
	v10 = *(*float32)(unsafe.Add(v8, 3636))
	v14.field_8 = a2.PosVec.X
	v4 = int32(a2.ObjClass)
	v14.field_4 = v10
	v14.field_C = v9
	if uint32(v4)&0x20400000 != 0 || (func() int32 {
		v4 = nox_xxx_playerMapTracksObj_4173D0(v5, a2)
		return v4
	}()) != 0 || (func() int32 {
		v4 = nox_xxx_mapTraceRay_535250(&v14, nil, nil, 69)
		return v4
	}()) != 0 {
		if uint32(v6)&a2.Field37 != 0 {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 20)))&0x20 != 0 {
				return int8(v4)
			}
		} else if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2+v5*4)), 560))&0xFFF != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2+v5*4)), 560)) |= (*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2+v5*4)), 560)) & 0xFFF) << 16
		}
		v11 = int32(a2.ObjClass)
		if uint32(v11)&0x400000 != 0 {
			v2 = nox_xxx_netSpriteUpdate_518AE0(a1, v5, (*uint32)(a2))
		} else if uint32(v11)&0x200000 != 0 {
			if v11&2 != 0 {
				v2 = nox_xxx_netSendComplexObject_518960(v5, (*uint32)(a2), 1)
			} else if v11&4 != 0 {
				v2 = nox_xxx_netPlayerObjSend_518C30(a1, a2, 1, 1)
			} else {
				v2 = nox_xxx_netSendPhantomPlrMb_5187E0(v5, a2)
			}
		} else if uint32(v11)&0x100000 != 0 {
			v2 = nox_xxx_netSendSimpleObj_5188A0(v5, a2)
		} else {
			a2.Field38 = 0
		}
		*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(nox_xxx_netUpdateObjectSpecial_527E50(a1, a2)))
		if v2 != 0 {
			v4 = int32(uint32(v6) | a2.Field37)
			a2.Field38 &= uint32(^v6)
			a2.Field37 = uint32(v4)
		}
	} else if uint32(v6)&a2.Field37 != 0 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 8)))&6 != 0 {
			nox_xxx_netObjectOutOfSight_528A60(v5, (*uint32)(a2))
		} else {
			nox_xxx_netObjectInShadows_528A90(v5, (*uint32)(a2))
		}
		v4 = int32(uint32(^v6) & a2.Field37)
		a2.Field38 |= uint32(v6)
		a2.Field37 = uint32(v4)
	}
	return int8(v4)
}
func sub_519710(a1 unsafe.Pointer) int32 {
	var result int32
	result = sub_417270(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 276)), 2064))))
	if result != 0 {
		result = bool2int32(result > 60 || gameFrame()-*(*uint32)(unsafe.Add(a1, 268)) > uint32(60/result))
	}
	return result
}
func sub_51A500(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		i  *uint8
		v4 int32
	)
	if *memmap.PtrUint32(0x5D4594, 2388664) == 0 {
		sub_51A550()
	}
	if a1 == 0 {
		return 0
	}
	v1 = 0
	if *memmap.PtrUint32(0x587000, 249904) == 0 {
		return 0
	}
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v2), unsafe.Sizeof(uint16(0))*1)) = 0
	for i = (*uint8)(memmap.PtrOff(0x587000, 249904)); ; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 16)) {
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v2), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(a1, 4))
		if *(*uint32)(unsafe.Add(unsafe.Pointer(i), -int(4*1))) == uint32(v2) {
			break
		}
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*4)))
		v1++
		if v4 == 0 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*16)+249908))
}
func sub_51A550() *byte {
	var (
		result *byte
		v1     *uint8
	)
	result = *(**byte)(memmap.PtrOff(0x587000, 249904))
	if *memmap.PtrUint32(0x587000, 249904) != 0 {
		v1 = (*uint8)(memmap.PtrOff(0x587000, 249896))
		for {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3)) = uint32(nox_xxx_getNameId_4E3AA0(result))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*1)) = uint32(nox_xxx_getNameId_4E3AA0(*(**byte)(unsafe.Pointer(v1))))
			result = (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*6)))))
			v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 16))
			if result == nil {
				break
			}
		}
		*memmap.PtrUint32(0x5D4594, 2388664) = 1
	} else {
		*memmap.PtrUint32(0x5D4594, 2388664) = 1
	}
	return result
}
func nox_xxx_spawnHecubahQuest_51A5A0(a1 *int32) {
	var (
		v1  *uint32
		v2  *uint32
		v3  int32
		v4  int32
		v5  float64
		v6  int32
		v7  *uint32
		v8  int32
		v9  *uint32
		v10 int32
		v11 *uint32
		v12 int32
		v13 *uint32
		v14 int32
		v15 *uint32
		v16 float32
		v17 float32
	)
	v1 = nox_xxx_newObjectByTypeID_4E3810(internCStr("Hecubah"))
	v16 = float32(sub_4E40F0())
	if v1 != nil {
		v2 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*187)))
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*121)))
		if v3 != 0 {
			v4 = int32(*(*uint32)(unsafe.Add(v3, 72)))
		} else {
			v4 = int32(*(*uint16)(unsafe.Add(nox_xxx_objectTypeByIndHealthData(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2)))), 4)))
		}
		if float64(v16) < 1.0 {
			v16 = 1.0
		}
		v5 = float64(v4) * float64(v16)
		v17 = float32(v5)
		nox_xxx_unitSetHP_4E4560((*server.Object)(unsafe.Pointer(v1)), uint16(int16(int64(v5))))
		*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*139)), 4)) = uint16(int16(int32(v17)))
		if int32(*(*uint16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*139)))) == 0 {
			nox_xxx_unitSetHP_4E4560((*server.Object)(unsafe.Pointer(v1)), 1)
		}
		v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*139)))
		if int32(*(*uint16)(unsafe.Add(v6, 4))) == 0 {
			*(*uint16)(unsafe.Add(v6, 4)) = 1
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*411)) = 0x10000000
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*423)) = 0x10000000
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*340)) = 4
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*326)) = 1062501089
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*510)) = 3
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*410)) = 0x8000000
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*444)) = 0x20000000
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*388)) = 0x40000000
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*415)) = 0x40000000
		nox_xxx_gamedataGetFloat_419D40(internCStr("HecubahQuestSkill"))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*330)) = 1062836634
		nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v1)), nil, *(*float32)(unsafe.Pointer(a1)), *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1)))
		v7 = nox_xxx_newObjectByTypeID_4E3810(internCStr("RewardMarker"))
		if v7 != nil {
			v8 = nox_game_getQuestStage_4E3CC0()
			v9 = nox_server_rewardgen_activateMarker_4F0720(unsafe.Pointer(v7), uint32(v8+2))
			if v9 != nil {
				nox_xxx_inventoryPutImpl_4F3070((*server.Object)(unsafe.Pointer(v1)), (*server.Object)(unsafe.Pointer(v9)), 0)
			}
			v10 = nox_game_getQuestStage_4E3CC0()
			v11 = nox_server_rewardgen_activateMarker_4F0720(unsafe.Pointer(v7), uint32(v10+2))
			if v11 != nil {
				nox_xxx_inventoryPutImpl_4F3070((*server.Object)(unsafe.Pointer(v1)), (*server.Object)(unsafe.Pointer(v11)), 0)
			}
			v12 = nox_game_getQuestStage_4E3CC0()
			v13 = nox_server_rewardgen_activateMarker_4F0720(unsafe.Pointer(v7), uint32(v12+2))
			if v13 != nil {
				nox_xxx_inventoryPutImpl_4F3070((*server.Object)(unsafe.Pointer(v1)), (*server.Object)(unsafe.Pointer(v13)), 0)
			}
			v14 = nox_game_getQuestStage_4E3CC0()
			v15 = nox_server_rewardgen_activateMarker_4F0720(unsafe.Pointer(v7), uint32(v14+2))
			if v15 != nil {
				nox_xxx_inventoryPutImpl_4F3070((*server.Object)(unsafe.Pointer(v1)), (*server.Object)(unsafe.Pointer(v15)), 0)
			}
			nox_xxx_objectFreeMem_4E38A0((*server.Object)(unsafe.Pointer(v7)))
		}
	}
}
func nox_xxx_spawnNecroQuest_51A7A0(a1 *int32) {
	var (
		v1  *uint32
		v2  *uint32
		v3  int32
		v4  int32
		v5  float64
		v6  int32
		v7  *uint32
		v8  int32
		v9  *uint32
		v10 float32
		v11 float32
	)
	v1 = nox_xxx_newObjectByTypeID_4E3810(internCStr("Necromancer"))
	v10 = float32(sub_4E40F0())
	if v1 != nil {
		v2 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*187)))
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*121)))
		if v3 != 0 {
			v4 = int32(*(*uint32)(unsafe.Add(v3, 72)))
		} else {
			v4 = int32(*(*uint16)(unsafe.Add(nox_xxx_objectTypeByIndHealthData(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2)))), 4)))
		}
		if float64(v10) < 1.0 {
			v10 = 1.0
		}
		v5 = float64(v4) * float64(v10)
		v11 = float32(v5)
		nox_xxx_unitSetHP_4E4560((*server.Object)(unsafe.Pointer(v1)), uint16(int16(int64(v5))))
		*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*139)), 4)) = uint16(int16(int32(v11)))
		if int32(*(*uint16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*139)))) == 0 {
			nox_xxx_unitSetHP_4E4560((*server.Object)(unsafe.Pointer(v1)), 1)
		}
		v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*139)))
		if int32(*(*uint16)(unsafe.Add(v6, 4))) == 0 {
			*(*uint16)(unsafe.Add(v6, 4)) = 1
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*340)) = 4
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*411)) = 0x10000000
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*423)) = 0x10000000
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*326)) = 1062501089
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*510)) = 1
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*410)) = 0x8000000
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*444)) = 0x20000000
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*415)) = 0x40000000
		nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v1)), nil, *(*float32)(unsafe.Pointer(a1)), *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1)))
		v7 = nox_xxx_newObjectByTypeID_4E3810(internCStr("RewardMarker"))
		if v7 != nil {
			v8 = nox_game_getQuestStage_4E3CC0()
			v9 = nox_server_rewardgen_activateMarker_4F0720(unsafe.Pointer(v7), uint32(v8+2))
			if v9 != nil {
				nox_xxx_inventoryPutImpl_4F3070((*server.Object)(unsafe.Pointer(v1)), (*server.Object)(unsafe.Pointer(v9)), 0)
			}
			nox_xxx_objectFreeMem_4E38A0((*server.Object)(unsafe.Pointer(v7)))
		}
	}
}
func nox_xxx_getQuestStage_51A930() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 2388660))
}
func sub_51A940(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 2388656) = uint32(a1)
	return result
}
func sub_51A950() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 2388656))
}
func sub_51B810(a1p *server.Object) {
	var (
		a1 = a1p
		v1 *float32
		v2 float64
		v3 int32
		v4 float64
		v6 int32
		v7 float32
	)
	v1 = (*float32)(a1)
	v6 = a1
	v2 = float64(a1.ForceVec.X + a1.VelVec.X)
	v3 = int32(a1.NewPos.Y)
	a1.PosVec.X = a1.NewPos.X
	a1.PosVec.Y = float32(uint32(v3))
	v4 = v2 * float64(a1.Float28)
	a1.VelVec.X = float32(v4)
	v7 = (*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*23)) + *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*21))) * *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*28))
	*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*21)) = v7
	*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*16)) = float32(v4 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*16))))
	*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*17)) = v7 + *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*17))
	nox_xxx_objectUnkUpdateCoords_4E7290((*server.Object)(v6))
}
func sub_51B860(it *server.Object, _ unsafe.Pointer) {
	nox_xxx_unitHasCollideOrUpdateFn_537610(it)
}
func nox_xxx_updateFallLogic_51B870(a1p *server.Object) {
	var (
		a1  = a1p
		v1  int32
		v2  int32
		v3  float64
		v4  float64
		v5  float64
		v6  float64
		v7  float64
		v8  float64
		v9  float64
		v10 float32
		v11 float32
		v12 float32
		v13 float32
		v14 int32
	)
	v1 = a1
	v2 = int32(a1.ObjFlags)
	v3 = float64(a1.ZVal)
	if uint32(v2)&0x40000 != 0 {
		v10 = float32(v3 + float64(a1.Field27))
		nox_xxx_unitRaise_4E46F0(a1, v10)
		v4 = float64(a1.Field27) - 1.0
		a1.ForceVec.X = 0
		a1.ForceVec.Y = 0
		a1.VelVec.X = 0
		a1.VelVec.Y = 0
		a1.Field27 = float32(v4)
		v5 = float64(a1.PosVec.X - a1.Pos39.X)
		v6 = float64(a1.PosVec.Y - a1.Pos39.Y)
		v13 = float32(v6)
		v7 = math.Sqrt(v6*float64(v13) + v5*v5)
		v14 = int32(float32(v7))
		if v7 > 0.0 {
			*(*float32)(unsafe.Add(v1, 88)) = float32(v5 * (-3.0) / float64(v14))
			*(*float32)(unsafe.Add(v1, 92)) = float32(float64(v13) * (-3.0) / float64(v14))
		}
		if float64(*(*float32)(unsafe.Add(v1, 104))) < -50.0 {
			nox_xxx_unitRaise_4E46F0((*server.Object)(v1), 90.0)
			*(*uint32)(unsafe.Add(v1, 16)) &= 0xFFFBFFFF
			nox_xxx_unitMove_4E7010((*server.Object)(v1), (*types.Pointf)(unsafe.Add(v1, 164)))
		}
	} else if v3 != 0.0 || float64(a1.Field27) != 0.0 {
		if uint32(v2)&0x800000 != 0 {
			v11 = a1.ZVal + a1.Field27
			nox_xxx_unitRaise_4E46F0(a1, v11)
			if float64(a1.ZVal) >= 0.0 {
				a1.Field27 = float32(float64(a1.Field27) - 0.5)
			} else {
				nox_xxx_unitRaise_4E46F0(a1, 0.0)
				v8 = float64(-a1.Field27*a1.Field29) * 0.1
				a1.Field27 = float32(v8)
				if v8 < 2.0 {
					nox_xxx_unitRaise_4E46F0(a1, 0.0)
					a1.Field27 = 0
				}
			}
		} else if (uint32(v2) & 0x100000) == 0 {
			if float64(a1.ZVal) > 0.0 {
				if float64(a1.Field27) <= 0.0 {
					a1.ObjFlags = uint32(v2) | 0x20000
				}
				v12 = a1.ZVal + a1.Field27
				nox_xxx_unitRaise_4E46F0(a1, v12)
				a1.Field27 = float32(float64(a1.Field27) - 1.0)
			}
			if float64(a1.ZVal) <= 0.0 {
				v9 = float64(a1.Field27)
				a1.ObjFlags &= 0xFFFDFFFF
				if v9 < 0.0 && (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&1) == 0 {
					nox_xxx_unitHasCollideOrUpdateFn_537610(a1)
					if float64(a1.Field27) < -10.0 {
						if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 {
							nox_xxx_aud_501960(280, a1, 0, 0)
						}
					}
				}
				nox_xxx_unitRaise_4E46F0(a1, 0.0)
				a1.Field27 = 0
			}
		}
	}
}
func sub_51D0E0() {
	dword_5d4594_2487244 = nil
}
func sub_51D0F0(a1 int8) int32 {
	*memmap.PtrUint8(0x973F18, 35972) = uint8(a1)
	return 1
}
func sub_51D100(a1 int32) int32 {
	if a1 != 1 && a1 != 0 {
		return 0
	}
	*memmap.PtrUint32(0x973F18, 35976) = uint32(a1)
	return 1
}
func sub_51D120(a1 *types.Pointf) {
	var (
		v3 types.Pointf
	)
	if nox_xxx_mapGenFixCoords_4D3D90(a1, &v3) == 0 {
		return
	}
	r2 := nox_xxx_waypointNew_5798F0(v3.X, v3.Y)
	v2 := r2
	if r2 == nil {
		return
	}
	if dword_5d4594_2487244 != nil {
		if *memmap.PtrUint32(0x973F18, 35976) == 1 {
			sub_51D300(dword_5d4594_2487244, r2, int8(*memmap.PtrUint8(0x973F18, 35972)))
			sub_51D300(v2, dword_5d4594_2487244, int8(*memmap.PtrUint8(0x973F18, 35972)))
		}
	}
	dword_5d4594_2487244 = v2
}
func sub_51D1A0(a1 *types.Pointf) *float32 {
	var a2 types.Pointf
	if nox_xxx_mapGenFixCoords_4D3D90(a1, &a2) == 0 {
		return nil
	}
	return sub_579AD0(a2.X, a2.Y)
}
func sub_51D2C0(a1 *server.Waypoint, a2 *server.Waypoint) int32 {
	return sub_51D300(a1, a2, int8(*memmap.PtrUint8(0x973F18, 35972)))
}
func sub_51D300(a1 *server.Waypoint, a2 *server.Waypoint, a3 int8) int32 {
	var (
		v3 uint8
		v4 int32
		v5 int32
		v6 *uint8
	)
	v3 = a1.PointsCnt
	if int32(v3) >= 0x1F || a1 == a2 {
		return 0
	}
	v4 = 0
	v5 = int32(v3)
	if int32(v3) > 0 {
		v6 = (*uint8)(unsafe.Add(unsafe.Pointer(a1), 96))
		for {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v6), -int(4*1))) == uint32(a2) && int32(*v6) == int32(a3) {
				break
			}
			v4++
			v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 8))
			if v4 >= v5 {
				break
			}
		}
	}
	if v4 != v5 {
		return 0
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1+v5*8)), 92)) = uint32(a2)
	*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1+int32(func() uint8 {
		p := (*uint8)(unsafe.Add(unsafe.Pointer(a1), 476))
		x := *p
		*p++
		return x
	}())*8)), 96)) = uint8(a3)
	return 1
}
func sub_51D3F0(a1 *types.Pointf, a2 *types.Pointf) {
	if a1 != nil {
		if a2 != nil {
			result := unsafe.Pointer(sub_51D1A0(a1))
			v3 := result
			if result != nil {
				result = unsafe.Pointer(sub_51D1A0(a2))
				if result != nil {
					sub_51D2C0(int32(uintptr(v3)), int32(uintptr(result)))
				}
			}
		}
	}
}
func nox_xxx_tileGetDefByName_51D4D0(a1 *byte) int32 {
	var v1 int32 = 0
	for i := int32(0); i < 176; i++ {
		p := &nox_tile_defs_arr[i]
		if nox_strcmpi(&p.name[0], a1) == 0 {
			v1 = 1
			*memmap.PtrUint32(0x973F18, 35912) = uint32(i)
		}
	}
	if nox_strcmpi(a1, internCStr("NONE")) == 0 {
		*memmap.PtrUint32(0x973F18, 35912) = math.MaxUint8
		return 1
	}
	if v1 != 0 {
		return 1
	}
	*memmap.PtrUint32(0x973F18, 35912) = 0
	return 0
}
func nox_xxx_tileCheckImage_51D540(a1 int32) int32 {
	var result int32
	if a1 < 0 || a1 >= 176 {
		*memmap.PtrUint32(0x973F18, 35912) = 0
		result = 0
	} else {
		*memmap.PtrUint32(0x973F18, 35912) = uint32(a1)
		result = 1
	}
	return result
}
func nox_xxx_tileCheckImageVari_51D570(a1 int32) int32 {
	var (
		result int32
		ind    int32          = int32(*memmap.PtrUint32(0x973F18, 35912))
		p      *nox_tileDef_t = &nox_tile_defs_arr[ind]
	)
	if a1 <= int32(p.field_52)*int32(p.field_53)-1 {
		dword_5d4594_3835348 = uint32(a1)
		result = 1
	} else {
		dword_5d4594_3835348 = 0
		result = 0
	}
	return result
}
func nox_xxx_tile_51D5C0(a1 int32) int32 {
	if a1 != 1 && a1 != 0 {
		return 0
	}
	*memmap.PtrUint32(0x973F18, 35916) = uint32(a1)
	return 1
}
func sub_51D5E0(a1 *float32) *float32 {
	var (
		result *float32
		v2     types.Pointf
	)
	result = a1
	if a1 == nil {
		return result
	}
	if *memmap.PtrUint32(0x973F18, 35912) == math.MaxUint8 || (func() bool {
		nox_xxx_mapGenFixCoords_4D3D90((*types.Pointf)(unsafe.Pointer(a1)), &v2)
		return (func() *float32 {
			result = (*float32)(unsafe.Pointer(uintptr(sub_51D8F0(&v2))))
			return result
		}()) != nil
	}()) && (dword_5d4594_3835364 != 1 || (func() *float32 {
		result = (*float32)(unsafe.Pointer(uintptr(sub_527380(&v2.X))))
		return result
	}()) != nil) {
		result = (*float32)(unsafe.Pointer(uintptr(1)))
	}
	return result
}
func sub_51D8F0(a1 *types.Pointf) int32 {
	var (
		v1     float64
		v2     float64
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		result int32
		v8     int32
		v9     int32
	)
	var v10 int32
	var v11 int32
	var v12 int32
	var v13 int8
	var v14 int32
	var v15 int32
	var v16 float32
	v9 = int32(dword_5d4594_3835348)
	v1 = float64(a1.X) + 11.5
	v8 = int32(*memmap.PtrUint32(0x973F18, 35912))
	v10 = 0
	v13 = 0
	v11 = -1
	v12 = -1
	v14 = math.MaxUint8
	v15 = 0
	v2 = float64(a1.Y) + 11.5
	v3 = int32(int64(v1 * 0.021739131))
	v16 = float32(v2)
	v4 = int32(int64(v2 * 0.021739131))
	v5 = int32(int64(v1)) % 46
	v6 = int32(int64(v16) % 46)
	if *memmap.PtrUint32(0x973F18, 35912) == math.MaxUint8 {
		result = sub_51D9C0(v3, v4, v5, v6, nil)
	} else {
		result = sub_51D9C0(v3, v4, v5, v6, unsafe.Pointer(&v8))
	}
	return result
}
func sub_51D9C0(a1 int32, a2 int32, a3 int32, a4 int32, a5 unsafe.Pointer) int32 {
	var result int32
	if a1-1 <= 0 || a1 >= math.MaxInt8 || a2-1 <= 0 || a2 >= math.MaxInt8 {
		return 0
	}
	if a3 <= a4 {
		if 46-a3 <= a4 {
			result = sub_51DA70(a1, a2, a5, 2, 0)
		} else {
			result = sub_51DA70(a1-1, a2, a5, 1, 0)
		}
	} else if 46-a3 <= a4 {
		result = sub_51DA70(a1, a2, a5, 1, 0)
	} else {
		result = sub_51DA70(a1, a2-1, a5, 2, 0)
	}
	return result
}
