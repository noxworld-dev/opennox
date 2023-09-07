package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

var dword_5d4594_1599628 uint32 = 0
var dword_5d4594_2386848 int32 = 0
var dword_5d4594_2386852 uint32 = 0

func sub_512E80(a1 int32) int32 {
	var v1 int32
	v1 = int32(dword_5d4594_1599628)
	if dword_5d4594_1599628 >= 1024 {
		return v1 - 1
	}
	*memmap.PtrUint32(0x973F18, uintptr(dword_5d4594_1599628)*4+26664) = uint32(a1)
	dword_5d4594_1599628 = uint32(func() int32 {
		p := &v1
		*p++
		return *p
	}())
	return v1 - 1
}
func nox_xxx_playerCanCarryItem_513B00(a1p *server.Object, a2p *server.Object) {
	var (
		a1 = unsafe.Pointer(a1p)
		a2 = unsafe.Pointer(a2p)
		v2 *uint32
		v3 int32
		v5 int32
		v6 int32
		v7 types.Pointf
	)
	if *memmap.PtrUint32(0x5D4594, 2386856) == 0 {
		*memmap.PtrUint32(0x5D4594, 2386856) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Glyph")))
	}
	if sub_467B00(int32(*(*uint16)(unsafe.Add(a2, 4))), 1)-dword_5d4594_2386848 <= 0 {
		v2 = nil
		v3 = 999999
		v4 := nox_xxx_inventoryGetFirst_4E7980((*server.Object)(a1))
		if v4 != nil {
			for {
				if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 8))) & 0x10) == 0 {
					v5 = int32(v4.ObjFlags)
					if (v5&0x100) == 0 && uint32(v4.TypeInd) != *memmap.PtrUint32(0x5D4594, 2386856) && nox_xxx_ItemIsDroppable_53EBF0(unsafe.Pointer(v4)) == 0 {
						v6 = nox_xxx_shopGetItemCost_50E3D0(1, nil, v4)
						if v6 < v3 {
							v3 = v6
							v2 = (*uint32)(v4)
						}
					}
				}
				v4 = nox_xxx_inventoryGetNext_4E7990(v4)
				if v4 == nil {
					break
				}
			}
			if v2 != nil {
				sub_4ED970(50.0, (*types.Pointf)(unsafe.Add(a1, 56)), &v7)
				nox_xxx_drop_4ED790((*server.Object)(a1), (*server.Object)(unsafe.Pointer(v2)), &v7)
				if dword_5d4594_2386852 == 0 {
					nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(a1), internCStr("pickup.c:CarryingTooMuch"), 0)
					dword_5d4594_2386852 = 1
				}
			}
		}
	}
}
func nox_server_scriptMoveTo_5123C0(a1 int32, a2 int32) *int32 {
	var (
		result *int32
		v3     int32
		v4     *int32
		v5     *int32
		i      *int32
	)
	result = *(**int32)(unsafe.Add(a1, 16))
	if int32(*(*int8)(unsafe.Add(unsafe.Pointer(&result), 1))) < 0 {
		return result
	}
	if int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
		v3 = int32(*(*uint32)(unsafe.Add(a1, 748)))
		nox_xxx_monsterClearActionStack_50A3A0((*server.Object)(a1))
		v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 32))
		if v4 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = 8
		}
		if int32(*(*uint8)(unsafe.Add(a2, 476))) != 0 {
			v5 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 10))
			if v5 != nil {
				*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) = a2
				*((*uint8)(unsafe.Add(unsafe.Pointer(v5), 12))) = *(*uint8)(unsafe.Add(v3, 1332))
			}
		}
		result = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*server.Object)(a1), 8))
		if result != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = int32(*(*uint32)(unsafe.Add(a2, 8)))
			*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*2)) = int32(*(*uint32)(unsafe.Add(a2, 12)))
			*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*3)) = 0
		}
	} else if uint32(*(*uint16)(unsafe.Add(a1, 4))) == dword_5d4594_2386836 {
		result = (*int32)(unsafe.Pointer(uintptr(nox_xxx_moverGoTo_5124C0((*uint32)(a1), (*uint32)(a2)))))
	} else {
		result = nox_server_getFirstObject_4DA790()
		for i = result; result != nil; i = result {
			if uint32(*((*uint16)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(uint16(0))*2)))) == dword_5d4594_2386836 && *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*187)), 32)) == *(*uint32)(unsafe.Add(a1, 40)) {
				nox_xxx_moverGoTo_5124C0((*uint32)(unsafe.Pointer(i)), (*uint32)(a2))
			}
			result = nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(i)))
		}
	}
	return result
}
func nox_xxx_moverGoTo_5124C0(a1 *uint32, a2 *uint32) int32 {
	var v2 int32
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*187)))
	nox_xxx_objectSetOn_4E75B0((*server.Object)(unsafe.Pointer(a1)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*20)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*21)) = 0
	*(*uint8)(v2) = 0
	*(*uint32)(unsafe.Add(v2, 8)) = *a2
	nox_xxx_unitAddToUpdatable_4DA8D0((*server.Object)(unsafe.Pointer(a1)))
	return int32(uintptr(unsafe.Pointer(a1)))
}
func nox_xxx_scriptMonsterRoam_512930(obj *server.Object) {
	var (
		a1 = obj
		v1 int32
		v2 int32
		v3 *int32
		v4 *int32
	)
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2 != 0 {
		v1 = int32(a1.ObjFlags)
		if (v1 & 0x8000) == 0 {
			v2 = int32(a1.UpdateData)
			nox_xxx_monsterClearActionStack_50A3A0(a1)
			v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(a1, 32))
			if v3 != nil {
				*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = 10
			}
			v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(a1, 10))
			if v4 != nil {
				*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = 0
				*((*uint8)(unsafe.Add(unsafe.Pointer(v4), 12))) = *(*uint8)(unsafe.Add(v2, 1332))
			}
		}
	}
}
func nox_server_gotoHome(obj *server.Object) {
	var (
		v2 = obj
		v3 int32
		v4 *uint32
		v5 *int32
		v6 *int32
		v7 *int32
	)
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 8)))&2 != 0 {
		v3 = int32(v2.ObjFlags)
		if (v3 & 0x8000) == 0 {
			v4 = (*uint32)(v2.UpdateData)
			nox_xxx_monsterClearActionStack_50A3A0(v2)
			v5 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(v2, 32))
			if v5 != nil {
				*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) = 37
			}
			v6 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(v2, 25))
			if v6 != nil {
				*((*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*1))) = float32(float64(*memmap.PtrFloat32(0x587000, uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*94))*8+194136)))*10.0 + float64(v2.PosVec.X))
				*((*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*2))) = float32(float64(*memmap.PtrFloat32(0x587000, uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*94))*8+194140)))*10.0 + float64(v2.PosVec.Y))
			}
			v7 = (*int32)(nox_xxx_monsterPushAction_50A260_impl(v2, 37))
			if v7 != nil {
				*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*95)))
				*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*2)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*96)))
				*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*3)) = 0
			}
		}
	}
}
func nox_script_GetHostInfo_513FA0() int32 {
	var (
		v0     int32
		v1     *byte
		result int32
	)
	v0 = nox_script_pop()
	v1 = nox_xxx_getHostInfoPtr_431770()
	switch v0 {
	case 0:
		nox_script_push(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 50))))
		result = 0
	case 1:
		nox_script_push(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 54))))
		result = 0
	case 2:
		nox_script_push(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 58))))
		result = 0
	case 3:
		nox_script_push(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 62))))
		result = 0
	case 4:
		nox_script_push(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v1), 66))))
		result = 0
	case 5:
		nox_script_push(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v1), 67))))
		result = 0
	default:
		nox_script_push(0)
		result = 0
	}
	return result
}
func nox_script_SetQuestInt_514BE0() int32 {
	var (
		v0 int32
		v1 int32
	)
	v0 = nox_script_pop()
	v1 = nox_script_pop()
	nox_xxx_journalQuestSet_500540(nox_script_getString_512E40(v0), v1)
	return 0
}
func nox_script_SetQuestFloat_514C10() int32 {
	var (
		v0 int32
		v1 int32
	)
	v0 = nox_script_pop()
	v1 = nox_script_pop()
	nox_xxx_journalQuestSetBool_5006B0(nox_script_getString_512E40(v0), v1)
	return 0
}
func nox_script_GetQuestInt_514C40() int32 {
	var (
		v0 int32
		v1 int32
	)
	v0 = nox_script_pop()
	v1 = sub_500750(nox_script_getString_512E40(v0))
	nox_script_push(v1)
	return 0
}
func nox_script_GetQuestFloat_514C60() int32 {
	var (
		v0 int32
		v2 int32
	)
	v0 = nox_script_pop()
	v2 = int32(float32(sub_500770(nox_script_getString_512E40(v0))))
	nox_script_push(v2)
	return 0
}
func nox_script_ResetQuestStatus_514C90() int32 {
	var v0 int32
	v0 = nox_script_pop()
	sub_5007E0(nox_script_getString_512E40(v0))
	return 0
}
func nox_script_JournalDelete_515550() int32 {
	var (
		v0 int32
		v1 int32
		v2 int32
	)
	v0 = nox_script_pop()
	v1 = nox_script_pop()
	if v1 != 0 {
		v2 = int32(uintptr(unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v1))))
		if v2 != 0 {
			nox_xxx_comJournalEntryRemove_427630(v2, nox_script_getString_512E40(v0))
			return 0
		}
	} else {
		nox_xxx_comRemoveEntryAll_427680(nox_script_getString_512E40(v0))
	}
	return 0
}
func nox_script_JournalEdit_5155A0() int32 {
	var (
		v0 int16
		v1 int32
		v2 int32
		v3 int32
	)
	v0 = int16(nox_script_pop())
	v1 = nox_script_pop()
	v2 = nox_script_pop()
	if v2 != 0 {
		v3 = int32(uintptr(unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v2))))
		if v3 != 0 {
			nox_xxx_comJournalEntryUpdate_427720(v3, nox_script_getString_512E40(v1), v0)
			return 0
		}
	} else {
		nox_xxx_comUpdateEntryAll_427770(nox_script_getString_512E40(v1), v0)
	}
	return 0
}
func nox_script_HitLocation_5159E0() int32 {
	v4 := nox_script_popf()
	v3 := nox_script_popf()
	v0 := nox_script_pop()
	v1 := unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v0))
	if v1 == nil {
		return 0
	}
	var v5 types.Pointf
	v5.X = v3
	v5.Y = v4
	nox_xxx_monsterActionMelee_515A30(v1, &v5)
	return 0
}
func nox_script_HitLocationGroup_515AE0() int32 {
	var (
		v0 int32
		v3 types.Pointf
		v4 types.Pointf
	)
	*(*uint32)(unsafe.Add(unsafe.Pointer(&v3.Y), 4*0)) = uint32(nox_script_pop())
	*(*uint32)(unsafe.Add(unsafe.Pointer(&v3.X), 4*0)) = uint32(nox_script_pop())
	v0 = nox_script_pop()
	v4 = v3
	v1 := nox_server_scriptGetGroup_57C0A0(v0)
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, func(arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
		nox_xxx_monsterActionMelee_515A30(arg1, (*types.Pointf)(arg2))
	}, unsafe.Pointer(&v4))
	return 0
}
func nox_script_HitFarLocation_515B30() int32 {
	var v3 [2]int32
	v3[1] = nox_script_pop()
	v3[0] = nox_script_pop()
	v0 := nox_script_pop()
	v1 := unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v0))
	if v1 == nil {
		return 0
	}
	var v4 [2]int32
	*(*uint64)(unsafe.Pointer(&v4[0])) = *(*uint64)(unsafe.Pointer(&v3[0]))
	nox_xxx_monsterMissileAttack_515B80(v1, (*uint32)(unsafe.Pointer(&v4[0])))
	return 0
}
func nox_script_HitFarLocationGroup_515BF0() int32 {
	var (
		v0 int32
		v1 *uint8
		v3 [2]int32
		v4 [2]int32
	)
	v3[1] = nox_script_pop()
	v3[0] = nox_script_pop()
	v0 = nox_script_pop()
	*(*uint64)(unsafe.Pointer(&v4[0])) = *(*uint64)(unsafe.Pointer(&v3[0]))
	v1 = (*uint8)(nox_server_scriptGetGroup_57C0A0(v0))
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, func(arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
		nox_xxx_monsterMissileAttack_515B80(arg1, (*uint32)(arg2))
	}, unsafe.Pointer(&v4[0]))
	return 0
}
func nox_script_SetRoamFlag_515C40() int32 {
	v1 := int8(nox_script_pop())
	v2 := nox_script_pop()
	v3 := unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v2))
	if v3 != nil {
		v5 := v1
		sub_515C80(v3, (*uint8)(unsafe.Pointer(&v5)))
	}
	return 0
}
func nox_script_SetRoamFlagGroup_515CB0() int32 {
	var (
		v0 int8
		v1 int32
		v2 *uint8
		v4 int8
	)
	v0 = int8(nox_script_pop())
	v1 = nox_script_pop()
	v4 = v0
	v2 = (*uint8)(nox_server_scriptGetGroup_57C0A0(v1))
	nox_server_scriptExecuteFnForEachGroupObj_502670(v2, 0, func(arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
		sub_515C80(arg1, (*uint8)(arg2))
	}, unsafe.Pointer(&v4))
	return 0
}
func nox_script_GiveExp_516190() int32 {
	v0 := nox_script_pop()
	v1 := nox_script_pop()
	v2 := unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v1))
	if v2 != nil {
		nox_xxx_plyrGiveExp_4EF3A0_exp_level(v2, float32(v0))
	}
	return 0
}
func nox_script_HasSubclass_5162D0() int32 {
	var (
		v0     int32
		result int32
	)
	var v2 *uint8
	var v3 int32
	var v4 *byte
	var i **byte
	var v7 *uint8
	var v8 int32
	var v9 int32
	v8 = nox_script_pop()
	v0 = nox_script_pop()
	v9 = int32(uintptr(unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v0))))
	if v9 == 0 {
		nox_script_push(0)
		return 0
	}
	v2 = (*uint8)(memmap.PtrOff(0x587000, 237304))
	v7 = (*uint8)(memmap.PtrOff(0x587000, 237304))
	for i = (**byte)(memmap.PtrOff(0x587000, 237304)); ; i = (**byte)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof((*byte)(nil))*32)) {
		v3 = 1
		v4 = *i
		if *i != nil {
			for libc.StrCmp(v4, nox_script_getString_512E40(v8)) != 0 {
				v4 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1))))))
				v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 4))
				v3 *= 2
				if v4 == nil {
					goto LABEL_8
				}
			}
			nox_script_push(bool2int32((uint32(v3) & *(*uint32)(unsafe.Add(v9, 12))) != 0))
			return 0
		}
	LABEL_8:
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 128))
		v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 128))
	}
}
func nox_script_StartupScreen_516600_A() {
	var i unsafe.Pointer
	for i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i != nil; i = nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(i)) {
		if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 748)), 276)), 2064))) == 31 {
			break
		}
	}
	sub_4277B0((*server.Object)(i), 0xE)
	v1 := nox_xxx_inventoryGetFirst_4E7980((*server.Object)(i))
	if v1 != nil {
		for {
			v2 := nox_xxx_inventoryGetNext_4E7990(v1)
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 8)))&0x40 != 0 {
				nox_xxx_delayedDeleteObject_4E5CC0(v1)
			}
			v1 = v2
			if v2 == nil {
				break
			}
		}
	}
	*memmap.PtrUint32(0x5D4594, 2386832) = 1
}
func nox_script_IsTalking_5166A0() int32 {
	var (
		v0 *byte
		v1 int32
	)
	v0 = nox_common_playerInfoFromNum_417090(31)
	v1 = 0
	if v0 != nil && *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*514))))), 748)), 284)) != 0 {
		v1 = 1
	}
	nox_script_push(v1)
	return 0
}
func nox_script_PlayerIsTrading_5166E0() int32 {
	var (
		v0 *byte
		v1 int32
	)
	v0 = nox_common_playerInfoFromNum_417090(31)
	v1 = 0
	if v0 != nil && *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*514))))), 748)), 280)) != 0 {
		v1 = 1
	}
	nox_script_push(v1)
	return 0
}
func nox_script_MakeFriendly_516720() int32 {
	var (
		v0 *byte
		v1 int32
		v2 int32
		v3 int32
		v4 int32
	)
	v0 = nox_common_playerInfoFromNum_417090(31)
	v1 = nox_script_pop()
	v2 = int32(uintptr(unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v1))))
	if v2 == 0 {
		return 0
	}
	v3 = int32(*(*uint32)(unsafe.Add(v2, 12)))
	*(*uint8)(unsafe.Add(unsafe.Pointer(&v3), 1)) |= 1
	*(*uint32)(unsafe.Add(v2, 12)) = uint32(v3)
	v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*514))))
	if v4 != 0 {
		nox_xxx_unitSetOwner_4EC290((*server.Object)(v4), (*server.Object)(v2))
	}
	return 0
}
func nox_script_MakeEnemy_516760() int32 {
	var (
		v0 int32
		v1 int32
		v2 int32
	)
	v0 = nox_script_pop()
	v1 = int32(uintptr(unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v0))))
	if v1 == 0 {
		return 0
	}
	v2 = int32(*(*uint32)(unsafe.Add(v1, 12)))
	*(*uint8)(unsafe.Add(unsafe.Pointer(&v2), 1)) &= 0xFE
	*(*uint32)(unsafe.Add(v1, 12)) = uint32(v2)
	nox_xxx_unitClearOwner_4EC300((*server.Object)(v1))
	return 0
}
func nox_script_builtin_516790() int32 {
	var (
		v1 int32
		v2 int32
	)
	v1 = nox_script_pop()
	v2 = int32(uintptr(unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v1))))
	if v2 != 0 {
		nox_script_push(int32((*(*uint32)(unsafe.Add(v2, 12)) >> 8) & 1))
	} else {
		nox_script_push(0)
	}
	return 0
}
func nox_script_BecomePet_5167D0() int32 {
	v0 := nox_common_playerInfoFromNum_417090(31)
	v1 := nox_script_pop()
	v2 := unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v1))
	if v2 == nil {
		return 0
	}
	v3 := v0.PlayerUnit
	if v3 != nil {
		nox_xxx_unitBecomePet_4E7B00(v3, (*server.Object)(v2))
	}
	return 0
}
func nox_script_BecomeEnemy_516810() int32 {
	var (
		v0 *byte
		v1 int32
		v2 *uint32
		v3 int32
	)
	v0 = nox_common_playerInfoFromNum_417090(31)
	v1 = nox_script_pop()
	v2 = (*uint32)(unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v1)))
	if v2 == nil {
		return 0
	}
	v3 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*514))))
	if v3 != 0 {
		nox_xxx_monsterRemoveMonitors_4E7B60((*server.Object)(v3), (*server.Object)(unsafe.Pointer(v2)))
	}
	return 0
}
func nox_script_builtin_516850() int32 {
	var (
		v1 int32
		v2 int32
	)
	v1 = nox_script_pop()
	v2 = int32(uintptr(unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v1))))
	if v2 != 0 {
		nox_script_push(int32((*(*uint32)(unsafe.Add(v2, 12)) & math.MaxUint8) >> 7))
	} else {
		nox_script_push(0)
	}
	return 0
}
func nox_script_OblivionGive_516890() int32 {
	var (
		v0 *uint32
		v1 int32
		v2 int32
		v3 *uint32
		v4 *uint32
	)
	v0 = (*uint32)(unsafe.Pointer(uintptr(nox_common_playerInfoFromNum_417090(31).PlayerUnit)))
	v1 = 0
	v2 = nox_script_pop()
	v3 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v0), 4*126)))
	if v3 != nil {
		for (*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2))&0x1000000) == 0 || (*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3))&0x7800000) == 0 {
			v3 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*124)))
			if v3 == nil {
				goto LABEL_7
			}
		}
		v1 = int32((*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*4)) >> 8) & 1)
		nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(unsafe.Pointer(v3)))
	}
LABEL_7:
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_playerRespawnItem_4EF750((*server.Object)(unsafe.Pointer(v0)), *(**byte)(memmap.PtrOff(0x587000, uintptr(v2*4)+247336)), nil, 1, 1)))
	if v1 != 0 {
		nox_xxx_playerTryEquip_4F2F70((*server.Object)(unsafe.Pointer(v0)), (*server.Object)(unsafe.Pointer(v4)))
	}
	return 0
}
func nox_script_SetShopkeeperGreet_516BE0() int32 {
	var (
		v0 int32
		v1 int32
		v2 int32
	)
	v0 = nox_script_pop()
	v1 = nox_script_pop()
	v2 = int32(uintptr(unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v1))))
	if v2 != 0 {
		sub_548FE0(v2, nox_script_getString_512E40(v0))
	}
	return 0
}
func nox_script_IsSummoned_516C30() int32 {
	var (
		v0 int32
		v1 int32
		v2 int32
	)
	v0 = nox_script_pop()
	v1 = 0
	v2 = int32(uintptr(unsafe.Pointer(nox_server_scriptValToObjectPtr_511B60(v0))))
	if v2 != 0 && int32(*(*uint8)(unsafe.Add(v2, 8)))&2 != 0 {
		v1 = int32((*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 748)), 1440)) >> 7) & 1)
	}
	nox_script_push(v1)
	return 0
}
func nox_script_Fn5E_513F70() int32 {
	var (
		v0 int32
		v1 *wchar2_t
		v2 int32
	)
	v0 = nox_script_pop()
	v1 = nox_strman_loadString_40F1D0(nox_script_getString_512E40(v0), nil, internCStr("C:\\NoxPost\\src\\Server\\System\\CScrFunc.c"), 2901)
	v2 = sub_512E80(int32(uintptr(unsafe.Pointer(v1))))
	nox_script_push(v2)
	return 0
}
