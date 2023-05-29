package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"math"
	"unsafe"
)

type struct313272 struct {
	f0  uint32
	f4  float32
	f8  float32
	f12 uint32
	f16 float32
	f20 float32
}

var table_313272 [11]struct313272 = [11]struct313272{{f0: 0x0, f4: 0, f8: 0, f12: 0x1, f16: 0, f20: 23}, {f0: 0x1, f4: 0, f8: 23, f12: 0x0, f16: 0, f20: 0}, {f0: 0x1, f4: 0, f8: 23, f12: 0x1, f16: 0, f20: 23}, {f0: 0x1, f4: 0, f8: 11.5, f12: 0x1, f16: 0, f20: 23}, {f0: 0x1, f4: 0, f8: 23, f12: 0x1, f16: 11.5, f20: 23}, {f0: 0x1, f4: 11.5, f8: 23, f12: 0x1, f16: 0, f20: 23}, {f0: 0x1, f4: 0, f8: 23, f12: 0x1, f16: 0, f20: 11.5}, {f0: 0x1, f4: 0, f8: 11.5, f12: 0x1, f16: 11.5, f20: 23}, {f0: 0x1, f4: 11.5, f8: 23, f12: 0x1, f16: 11.5, f20: 23}, {f0: 0x1, f4: 11.5, f8: 23, f12: 0x1, f16: 0, f20: 11.5}, {f0: 0x1, f4: 0, f8: 11.5, f12: 0x1, f16: 0, f20: 11.5}}

func nox_xxx_mobActionRandomWalk_545020(a1 int32) int8 {
	var (
		v1 int32
		v2 int16
		v3 int32
		v4 float64
		v5 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v2 = int16(sub_545090(a1))
	*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))) = uint16(v2)
	*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = uint16(v2)
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 1440))))
	if v3&0x4000 != 0 {
		v4 = float64(*(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 484))) + 96))) * *(*float32)(unsafe.Pointer(uintptr(a1 + 544))))
	} else {
		v4 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 544))))
	}
	v5 = int32(v2) * 8
	*(*float32)(unsafe.Pointer(uintptr(a1 + 88))) = float32(v4 * float64(*mem_getFloatPtr(0x587000, uint32(v5)+194136)))
	*(*float32)(unsafe.Pointer(uintptr(a1 + 92))) = float32(v4 * float64(*mem_getFloatPtr(0x587000, uint32(v5)+194140)))
	return nox_xxx_monsterMoveAudio_534030(a1)
}
func sub_545090(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		v4 float2
	)
	v1 = int32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124)))) + nox_common_randomInt_415FA0(-20, 20)
	if v1 < 0 {
		v1 += int32(uint32(math.MaxUint8-v1) >> 8 << 8)
	}
	if v1 >= 256 {
		v1 += int32((uint32(v1) >> 8) * 4294967040)
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
	if (v2 & 0x400) == 0 {
		v4.field_0 = float32(float64(*mem_getFloatPtr(0x587000, uint32(v1*8)+194136))*30.0 + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))))
		v4.field_4 = float32(float64(*mem_getFloatPtr(0x587000, uint32(v1*8)+194140))*30.0 + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))))
		if nox_xxx_tileNFromPoint_411160(&v4) == 6 {
			v1 += 64
		}
		if v1 >= 256 {
			v1 += int32((uint32(v1) >> 8) * 4294967040)
		}
	}
	return v1
}
func nox_xxx_mobActionConfuse_545140(a1 int32) int8 {
	var (
		v1 *int32
		v2 float64
	)
	if nox_common_randomInt_415FA0(0, 100) >= 15 {
		*((*uint8)(unsafe.Pointer(&v1))) = uint8(nox_xxx_mobActionRandomWalk_545020(a1))
		return int8(uintptr(unsafe.Pointer(v1)))
	}
	if nox_xxx_monsterCanMelee_534220(a1) != 0 {
		if nox_xxx_monsterCanShoot_534280(a1) == 0 || nox_common_randomInt_415FA0(0, 100) < 50 {
			*((*uint8)(unsafe.Pointer(&v1))) = uint8(uint32(uintptr(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 16, internCStr(__FILE__), __LINE__))))
			return int8(uintptr(unsafe.Pointer(v1)))
		}
	} else {
		v1 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_monsterCanShoot_534280(a1))))
		if v1 == nil {
			return int8(uintptr(unsafe.Pointer(v1)))
		}
	}
	v1 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 17, internCStr(__FILE__), __LINE__))
	if v1 != nil {
		*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v1))), unsafe.Sizeof(float32(0))*1))) = float32(float64(*mem_getFloatPtr(0x587000, uint32(int32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124))))*8)+194136))*10.0 + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))))
		v2 = float64(*mem_getFloatPtr(0x587000, uint32(int32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124))))*8)+194140))*10.0 + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
		*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*3)) = 0
		*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v1))), unsafe.Sizeof(float32(0))*2))) = float32(v2)
	}
	return int8(uintptr(unsafe.Pointer(v1)))
}
func sub_545210(a1 int32) int8 {
	return sub_545240(a1, (*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748)))+uint32(*(*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 544)))*24)+556))))
}
func sub_545240(a1 int32, a2 *float32) int8 {
	var (
		v2  int32
		v3  float64
		v4  float64
		v5  int32
		v6  float64
		v7  int32
		v9  float2
		v11 float32
	)
	v2 = a1
	v3 = float64(*a2 - *(*float32)(unsafe.Pointer(uintptr(a1 + 56))))
	v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) - *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
	v5 = int32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124))))
	v9.field_4 = float32(v4)
	v11 = float32(math.Sqrt(v4*float64(v9.field_4)+v3*v3) + 0.001)
	v9.field_0 = float32(v3 / float64(v11))
	v6 = float64(v9.field_4 / v11)
	v9.field_4 = float32(v6)
	if v6*float64(*mem_getFloatPtr(0x587000, uint32(v5*8)+194136))-float64(v9.field_0**mem_getFloatPtr(0x587000, uint32(v5*8)+194140)) >= 0.0 {
		*(*uint16)(unsafe.Pointer(uintptr(v2 + 126))) += 8
	} else {
		*(*uint16)(unsafe.Pointer(uintptr(v2 + 126))) -= 8
	}
	for ; int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 126)))) < 0; *(*uint16)(unsafe.Pointer(uintptr(v2 + 126))) += 256 {
	}
	for ; int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 126)))) >= 256; *(*uint16)(unsafe.Pointer(uintptr(v2 + 126))) -= 256 {
	}
	v7 = sub_534120(v2, &v9)
	if v7 != 0 {
		*((*uint8)(unsafe.Pointer(&v7))) = uint8(int8(nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(v2))))))
	}
	return int8(v7)
}
func sub_545300(a1 int32) int8 {
	var (
		v1     int32
		result int8
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + uint32((*(*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 544)))+23)*24) + 4))))
	if v1 != 0 {
		result = sub_545240(a1, (*float32)(unsafe.Pointer(uintptr(v1+56))))
	} else {
		result = int8(nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))
	}
	return result
}
func sub_545340(a1 int32) int8 {
	var (
		v1 *float32
		v2 int32
		v3 *float2
		v4 int32
	)
	v1 = mem_getFloatPtr(0x587000, uint32(int32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124))))*8)+194136)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + uint32(*(*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 544)))*24) + 556))))
	v3 = (*float2)(memmap.PtrOff(0x587000, uint32(v2*8)+194136))
	if float64(*mem_getFloatPtr(0x587000, uint32(v2*8)+194140)**v1-*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*1))*v3.field_0) >= 0.0 {
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) += 8
	} else {
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) -= 8
	}
	for ; int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 126)))) < 0; *(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) += 256 {
	}
	for ; int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 126)))) >= 256; *(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) -= 256 {
	}
	v4 = sub_534120(a1, v3)
	if v4 != 0 {
		*((*uint8)(unsafe.Pointer(&v4))) = uint8(int8(nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(a1))))))
	}
	return int8(v4)
}
func sub_5453E0(a1 int32) int8 {
	var v1 int16
	v1 = int16(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + uint32(*(*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 544)))*24) + 556))))
	for *(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = uint16(v1); int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 126)))) < 0; *(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) += 256 {
	}
	for ; int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 126)))) >= 256; *(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) -= 256 {
	}
	*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 126)))
	return int8(nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))
}
func nox_xxx_mobActionRetreat_545440(a1 int32) int8 {
	var (
		v1 int32
		v2 *int32
		v3 *int32
		v4 int32
		v5 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if sub_545580(a1) != 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(v1 + 1196))) != 0 {
			if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 29) != 0 || (func() *int32 {
				v2 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_mobCastRelated_541050(a1))))
				return v2
			}()) == nil {
				v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 41, internCStr(__FILE__), __LINE__))
				if v3 != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = int32(gameFrame() + uint32(nox_common_randomInt_415FA0(int32(gameFPS()*4), int32(gameFPS()*6))))
				}
				v2 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 24, internCStr(__FILE__), __LINE__))
				if v2 != nil {
					v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 1196))))
					*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 56))))
					v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 60))))
					*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) = 0
					*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = v5
				}
			}
		} else {
			v2 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_monsterCanResumeAttack_545520(a1))))
			if v2 == nil {
				*((*uint8)(unsafe.Pointer(&v2))) = uint8(uint32(uintptr(unsafe.Pointer(nox_xxx_mobRetreatCheckEdibles_5455E0(a1)))))
			}
		}
	} else {
		*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(a1))))))
	}
	return int8(uintptr(unsafe.Pointer(v2)))
}
func nox_xxx_monsterCanResumeAttack_545520(a1 int32) int32 {
	var (
		v1 *uint16
		v2 float64
	)
	v1 = *(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2))) != 0 {
		v2 = float64(*v1) / float64(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2)))
	} else {
		v2 = 1.0
	}
	return bool2int32(v2 >= float64(*(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 1344)))))
}
func sub_545580(a1 int32) int32 {
	var result int32
	if nox_xxx_monsterCanResumeAttack_545520(a1) == 0 || (func() int32 {
		result = nox_xxx_monsterCanCast2_5455B0(a1)
		return result
	}()) != 0 {
		result = 1
	}
	return result
}
func nox_xxx_monsterCanCast2_5455B0(a1 int32) int32 {
	return bool2int32(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 1440))))&0x20 != 0 && nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 29) != 0)
}
func nox_xxx_mobRetreatCheckEdibles_5455E0(a1 int32) *int32 {
	var (
		v1     int32
		v2     *int32
		v3     *int32
		result *int32
		v5     int32
		v6     int32
	)
	if nox_common_gameFlags_check_40A5C0(4096) {
		v6 = 1142947840
	} else {
		v6 = 1132068864
	}
	v1 = nox_xxx_mobSearchEdible_544A00((*nox_object_t)(unsafe.Pointer(uintptr(a1))), *(*float32)(unsafe.Pointer(&v6)))
	if v1 != 0 {
		nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 64, internCStr(__FILE__), __LINE__)
		nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 56, internCStr(__FILE__), __LINE__)
		v2 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 48, internCStr(__FILE__), __LINE__))
		if v2 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 56))))
			*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 60))))
			*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) = v1
		}
		v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 11, internCStr(__FILE__), __LINE__))
		if v3 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = v1
		}
		result = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 7, internCStr(__FILE__), __LINE__))
		if result != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 56))))
			v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 60))))
			*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*3)) = v1
			*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*2)) = v5
		}
	} else {
		nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 64, internCStr(__FILE__), __LINE__)
		nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 56, internCStr(__FILE__), __LINE__)
		nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 58, internCStr(__FILE__), __LINE__)
		result = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 10, internCStr(__FILE__), __LINE__))
		if result != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = 0
			*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(result))), 12))) = 128
		}
	}
	return result
}
func sub_5456B0(a1 int32) int32 {
	return sub_534750(a1)
}
func sub_5456C0(a1 int32) int32 {
	return sub_534780(a1)
}
func sub_5456D0(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 float64
		v4 float64
		v5 *int32
		v6 *int32
		v7 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 508))) != 0 && sub_545580(a1) != 0 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
		v3 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56))) - *(*float32)(unsafe.Pointer(uintptr(v2 + 56))))
		v4 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60))) - *(*float32)(unsafe.Pointer(uintptr(v2 + 60))))
		if (float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 1316))))+30.0)*(float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 1316))))+30.0) < v4*v4+v3*v3 {
			v5 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 49, internCStr(__FILE__), __LINE__))
			if v5 != nil {
				*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 1316))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*3)) = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
			}
			v6 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 7, internCStr(__FILE__), __LINE__))
			if v6 != nil {
				v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 56))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v6), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 60))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v6), 4*3)) = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
			}
		}
	} else {
		nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
}
func sub_545790(a1 int32) int64 {
	var (
		v1     int32
		result int64
	)
	v1 = 16
	result = int64(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	for {
		v1--
		if v1 == 0 {
			break
		}
	}
	*(*uint32)(unsafe.Pointer(uintptr(result + 300))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(result + 364))) = 0
	return result
}
func sub_5457C0(a1 int32) int32 {
	var result int32
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	*(*uint32)(unsafe.Pointer(uintptr(result + int32(*(*byte)(unsafe.Pointer(uintptr(result + 544)))*24) + 556))) = 0
	return result
}
func nox_xxx_mobActionRoam_5457E0(a1 *int32) int8 {
	var (
		v1  *int32
		v2  int32
		v3  *int32
		v4  *int32
		v5  *int32
		v6  *int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 *int32
		v12 int32
		v13 float64
		v14 float64
		v15 int32
		v16 int32
		v17 int32
		v19 int32
		v20 int32
		v21 int32
		v22 uint8
	)
	v1 = a1
	v2 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*187))
	if sub_5343C0(int32(uintptr(unsafe.Pointer(a1)))) != 0 || nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))) != 0 {
		v3 = (*int32)(unsafe.Pointer(uintptr(sub_545E60((*nox_object_t)(unsafe.Pointer(a1))))))
		if v3 != nil {
			return int8(uintptr(unsafe.Pointer(v3)))
		}
	}
	if *(*uint32)(unsafe.Pointer(uintptr(v2 + 1440)))&0x20000 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v2 + 1196))) == 0 && nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 0) != 0 && (int32(uint8(gameFrame()))&0x1F) == 0 && nox_common_randomInt_415FA0(0, 100) < 10 {
		v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 66, internCStr(__FILE__), __LINE__))
		if v4 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = 1125515264
		}
		v5 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 62, internCStr(__FILE__), __LINE__))
		if v5 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) = 0
		}
		v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 1, internCStr(__FILE__), __LINE__))
		v6 = v3
		if v3 != nil {
			v3 = (*int32)(unsafe.Pointer(uintptr(gameFrame() + gameFPS()*uint32(nox_common_randomInt_415FA0(3, 10)))))
			*(*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1)) = int32(uintptr(unsafe.Pointer(v3)))
		}
		return int8(uintptr(unsafe.Pointer(v3)))
	}
	if nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))) != 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(v2 + 1196))) != 0 {
			v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 15, internCStr(__FILE__), __LINE__))
			if v3 != nil {
				v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 1196))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 56))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 60))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*3)) = int32(gameFrame())
			}
			return int8(uintptr(unsafe.Pointer(v3)))
		}
		v3 = (*int32)(unsafe.Pointer(uintptr(sub_5466F0((*nox_object_t)(unsafe.Pointer(a1))))))
		if v3 != nil {
			return int8(uintptr(unsafe.Pointer(v3)))
		}
	}
	v8 = v2 + int32((*(*byte)(unsafe.Pointer(uintptr(v2 + 544)))+23)*24)
	v22 = *(*uint8)(unsafe.Pointer(uintptr(v2 + int32((*(*byte)(unsafe.Pointer(uintptr(v2 + 544)))+23)*24) + 12)))
	if sub_547EE0(int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + 4)))), v22) == 0 {
		*(*uint32)(unsafe.Pointer(uintptr(v8 + 4))) = 0
	}
	if *(*uint32)(unsafe.Pointer(uintptr(v8 + 4))) == 0 {
		v9 = int32(uintptr(unsafe.Pointer(sub_518740((*float2)(unsafe.Add(unsafe.Pointer((*float2)(unsafe.Pointer(v1))), unsafe.Sizeof(float2{})*7)), v22))))
		*(*uint32)(unsafe.Pointer(uintptr(v8 + 4))) = uint32(v9)
		if v9 == 0 && *(*byte)(unsafe.Pointer(uintptr(v8 + 12))) == 128 {
			*(*uint32)(unsafe.Pointer(uintptr(v8 + 4))) = uint32(sub_50CB20(int32(uintptr(unsafe.Pointer(v1))), (*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v1))), unsafe.Sizeof(float32(0))*14))))
		}
		if *(*uint32)(unsafe.Pointer(uintptr(v8 + 4))) == 0 {
			v19 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*9))
			v10 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1))))))))))
			nox_ai_debug_printf_5341A0(internCStr("%d: %s(#%d) Cannot find any waypoints\n"), gameFrame(), v10, v19)
			nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))))
			v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), 1, internCStr(__FILE__), __LINE__))
			v11 = v3
			if v3 != nil {
				v3 = (*int32)(unsafe.Pointer(uintptr(gameFrame() + uint32(nox_common_randomInt_415FA0(int32(gameFPS()), int32(gameFPS()*2))))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*1)) = int32(uintptr(unsafe.Pointer(v3)))
			}
			return int8(uintptr(unsafe.Pointer(v3)))
		}
		sub_545B00(v2, int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + 4)))))
	}
	v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + 4))))
	v13 = float64(*(*float32)(unsafe.Pointer(uintptr(v12 + 8))) - *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v1))), unsafe.Sizeof(float32(0))*14))))
	v14 = float64(*(*float32)(unsafe.Pointer(uintptr(v12 + 12))) - *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v1))), unsafe.Sizeof(float32(0))*15))))
	if v14*v14+v13*v13 <= 64.0 {
		v3 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_monsterRoamDeadEnd_545BB0(int32(uintptr(unsafe.Pointer(v1))), int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + 4))))))))
		if v3 == nil {
			return int8(uintptr(unsafe.Pointer(v3)))
		}
		*(*uint32)(unsafe.Pointer(uintptr(v2 + 280))) = 0
	}
	if *(*uint32)(unsafe.Pointer(uintptr(v2 + 8))) == 0 {
		nox_xxx_creatureSetDetailedPath_50D220(int32(uintptr(unsafe.Pointer(v1))), int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + 4)))+8))
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 284)))) == 2 {
		v20 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*9))
		v15 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1))))))))))
		nox_ai_debug_printf_5341A0(internCStr("%d: %s(#%d) Cannot compute path to waypoint, choosing other\n"), gameFrame(), v15, v20)
		v16 = sub_545B60(v2, v22)
		if v16 == 0 {
			v21 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*9))
			v17 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1))))))))))
			nox_ai_debug_printf_5341A0(internCStr("%d: %s(#%d) No previous waypoint, giving up.\n"), gameFrame(), v17, v21)
			*((*uint8)(unsafe.Pointer(&v3))) = uint8(int8(nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))))))
			return int8(uintptr(unsafe.Pointer(v3)))
		}
		v3 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_monsterRoamDeadEnd_545BB0(int32(uintptr(unsafe.Pointer(v1))), v16))))
		if v3 == nil {
			return int8(uintptr(unsafe.Pointer(v3)))
		}
	}
	if nox_xxx_creatureActuallyMove_50D3B0((*float32)(unsafe.Pointer(v1))) != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(v2 + 8))) = 0
	}
	*((*uint8)(unsafe.Pointer(&v3))) = uint8(nox_xxx_monsterMoveAudio_534030(int32(uintptr(unsafe.Pointer(v1)))))
	return int8(uintptr(unsafe.Pointer(v3)))
}
func sub_545B00(a1 int32, a2 int32) {
	var (
		v3 int32
		v4 *uint32
		i  int32
	)
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 364))) + 1)
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 364))) = uint32(v3)
	if v3 >= 16 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 364))) = 0
	}
	v4 = (*uint32)(unsafe.Pointer(uintptr(a1 + 300)))
	*(*uint32)(unsafe.Pointer(uintptr(uint32(a1) + *(*uint32)(unsafe.Pointer(uintptr(a1 + 364)))*4 + 300))) = uint32(a2)
	for i = 0; i < 16; i++ {
		if *v4 == uint32(a2) && uint32(i) != *(*uint32)(unsafe.Pointer(uintptr(a1 + 364))) {
			*v4 = 0
		}
		v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
	}
}
func sub_545B60(a1 int32, a2 uint8) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
	)
	v2 = 1
	for {
		v3 = *(*int32)(unsafe.Pointer(uintptr(a1 + 364))) - v2 + (func() int32 {
			if *(*int32)(unsafe.Pointer(uintptr(a1 + 364)))-v2 < 0 {
				return 0x10
			}
			return 0
		}())
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + v3*4 + 300))))
		if v4 != 0 {
			if sub_547EE0(v4, a2) != 0 {
				break
			}
		}
		if func() int32 {
			p := &v2
			*p++
			return *p
		}() >= 16 {
			return 0
		}
	}
	return int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + v3*4 + 300))))
}
func nox_xxx_monsterRoamDeadEnd_545BB0(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		v3     uint8
		v4     int32
		v5     int32
		result int32
		v7     int32
		v8     int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v3 = *(*uint8)(unsafe.Pointer(uintptr(v2 + int32((*(*byte)(unsafe.Pointer(uintptr(v2 + 544)))+23)*24) + 12)))
	v4 = v2 + int32((*(*byte)(unsafe.Pointer(uintptr(v2 + 544)))+23)*24)
	*(*uint32)(unsafe.Pointer(uintptr(v2 + 8))) = 0
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 476)))) != 0 && int32(func() uint8 {
		*(*uint32)(unsafe.Pointer(uintptr(v4 + 4))) = uint32(sub_545C60(v2, a2, v3))
		return *(*uint8)(unsafe.Pointer(uintptr(a2 + 476)))
	}()) != 0 && (func() int32 {
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 4))))
		return v5
	}()) != 0 {
		sub_545B00(v2, v5)
		result = 1
	} else {
		v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 36))))
		v7 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		nox_ai_debug_printf_5341A0(internCStr("%d: %s(#%d) Reached dead end, giving up.\n"), gameFrame(), v7, v8)
		nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		result = 0
	}
	return result
}
func sub_545C60(a1 int32, a2 int32, a3 uint8) int32 {
	var (
		v3  int32
		v4  *int32
		v5  *int32
		v6  int32
		v7  int32
		v8  *uint32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 *uint32
		v17 int32
		v18 [32]int32
	)
	v3 = 0
	v17 = 0
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 476)))) == 0 {
		goto LABEL_27
	}
	v4 = &v18[0]
	v5 = (*int32)(unsafe.Pointer(uintptr(a2 + 92)))
	for {
		v6 = *v5
		if sub_547EE0(*v5, a3) != 0 {
			v7 = 0
			v8 = (*uint32)(unsafe.Pointer(uintptr(a1 + 300)))
			for {
				if uint32(v6) == *v8 {
					break
				}
				v7++
				v8 = (*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
				if v7 >= 16 {
					break
				}
			}
			if v7 == 16 {
				*v4 = v6
				v4 = (*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
				v17++
			}
		}
		v3++
		v5 = (*int32)(unsafe.Add(unsafe.Pointer(v5), 4*2))
		if v3 >= int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 476)))) {
			break
		}
	}
	if v17 != 0 {
		return v18[nox_common_randomInt_415FA0(0, v17-1)]
	}
LABEL_27:
	v9 = 0
	for {
		v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 364))))
		v11 = v10 + v9 + 1
		if v11 >= 16 {
			v11 = v10 + v9 - 15
		}
		v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + v11*4 + 300))))
		if v12 != 0 {
			v13 = 0
			v14 = int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 476))))
			if v14 > 0 {
				v15 = (*uint32)(unsafe.Pointer(uintptr(a2 + 92)))
				for {
					if uint32(v12) == *v15 {
						break
					}
					v13++
					v15 = (*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*2))
					if v13 >= v14 {
						break
					}
				}
			}
			if v13 != v14 && sub_547EE0(v12, a3) != 0 {
				break
			}
		}
		if func() int32 {
			p := &v9
			*p++
			return *p
		}() >= 16 {
			return 0
		}
	}
	return int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + v11*4 + 300))))
}
func sub_545DA0(a1 int32) int32 {
	var (
		v1 *uint32
		v2 *int32
		v3 *int32
	)
	v1 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 748)))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*97)) == 0 || gameFrame()-*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*101)) >= (gameFPS()*3) {
		return 0
	}
	nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 59, internCStr(__FILE__), __LINE__)
	nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 56, internCStr(__FILE__), __LINE__)
	v2 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 1, internCStr(__FILE__), __LINE__))
	if v2 != nil {
		*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = int32(gameFrame() + uint32(nox_common_randomInt_415FA0(int32(gameFPS()), int32(gameFPS()*2))))
	}
	v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 25, internCStr(__FILE__), __LINE__))
	if v3 != nil {
		*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*99)))
		*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*2)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*100)))
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*97)) = 0
	return 1
}
func nox_xxx_mobActionGuard_546010(a1 int32) *int32 {
	var (
		v1     int32
		v2     int32
		result *int32
		v4     int32
		v5     int32
		v6     float64
		v7     float64
		v8     *int32
		v9     *int32
		v10    *int32
		v11    *int32
		v12    int32
		v13    float64
		v14    float64
		v15    int32
		v16    int32
		v17    *int32
		v18    int32
		v19    int32
		v20    int32
		v21    float64
		v22    float64
		a2     float2
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v2 = v1 + int32((*(*byte)(unsafe.Pointer(uintptr(v1 + 544)))+23)*24)
	if sub_534440(a1) != 0 || (func() *int32 {
		result = (*int32)(unsafe.Pointer(uintptr(sub_545E60((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		return result
	}()) == nil {
		if *(*uint32)(unsafe.Pointer(uintptr(v1 + 1196))) != 0 {
			if nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(a1)))) != 0 {
				result = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 15, internCStr(__FILE__), __LINE__))
				if result != nil {
					v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 1196))))
					*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 56))))
					*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 60))))
					*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*3)) = int32(gameFrame())
				}
				return result
			}
			if sub_5343C0(a1) != 0 {
				v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 1196))))
				v6 = float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 4))) - *(*float32)(unsafe.Pointer(uintptr(v5 + 56))))
				v7 = float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 8))) - *(*float32)(unsafe.Pointer(uintptr(v5 + 60))))
				if float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 1312)))**(*float32)(unsafe.Pointer(uintptr(v1 + 1312)))) > v7*v7+v6*v6 {
					if nox_xxx_unitIsPlant_534A10(a1) != 0 {
						v8 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 63, internCStr(__FILE__), __LINE__))
						if v8 != nil {
							*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v8))), unsafe.Sizeof(float32(0))*1))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 1312)))) * 1.05)
						}
					} else {
						v9 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 43, internCStr(__FILE__), __LINE__))
						if v9 != nil {
							*(*int32)(unsafe.Add(unsafe.Pointer(v9), 4*1)) = 0
						}
						v10 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 52, internCStr(__FILE__), __LINE__))
						if v10 != nil {
							*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v10))), unsafe.Sizeof(float32(0))*1))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 1312)))) * 1.5)
							*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*3)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 4))))
							*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*4)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 8))))
						}
						nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 40, internCStr(__FILE__), __LINE__)
					}
					v11 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 15, internCStr(__FILE__), __LINE__))
					if v11 != nil {
						v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 1196))))
						*(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v12 + 56))))
						*(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v12 + 60))))
						*(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*3)) = int32(gameFrame())
					}
				}
			}
		}
		if nox_xxx_unitIsMimic_534840(a1) != 0 || (func() *int32 {
			result = (*int32)(unsafe.Pointer(uintptr(nox_xxx_monsterLookAtDamager_5466B0(a1))))
			return result
		}()) == nil {
			if nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(a1)))) != 0 {
				result = (*int32)(unsafe.Pointer(uintptr(sub_5466F0((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
				if result != nil {
					return result
				}
			} else if nox_xxx_unitIsMimic_534840(a1) == 0 {
				result = (*int32)(unsafe.Pointer(uintptr(sub_545DA0(a1))))
				if result != nil {
					return result
				}
			}
			if (int32(uint8(gameFrame()))+int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 36)))))&0xF != 0 {
				goto LABEL_49
			}
			v13 = float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 4))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 56))))
			v14 = float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 8))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
			if v14*v14+v13*v13 > 64.0 {
				if nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(a1)))) != 0 {
					nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 56, internCStr(__FILE__), __LINE__)
					nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 59, internCStr(__FILE__), __LINE__)
				}
				nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 44, internCStr(__FILE__), __LINE__)
				result = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 7, internCStr(__FILE__), __LINE__))
				if result != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 4))))
					v15 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 8))))
					*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*3)) = 0
					*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*2)) = v15
				}
				return result
			}
			if nox_xxx_unitIsMimic_534840(a1) != 0 {
				v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))))
				if sub_534120(a1, (*float2)(memmap.PtrOff(0x587000, uint32(v16*8)+194136))) == 0 {
					v17 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 27, internCStr(__FILE__), __LINE__))
					if v17 != nil {
						*(*int32)(unsafe.Add(unsafe.Pointer(v17), 4*1)) = v16
						goto LABEL_49
					}
				}
			} else {
				if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 1129)))) > 0 {
					v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 1196))))
					if v16 == 0 {
						v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 1132))))
						v18 = v1 + 1132
						v19 = 0
						v20 = int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 1129))))
						if v20 > 0 {
							for (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v18))) + 8)))) & 4) == 0 {
								v19++
								v18 += 4
								if v19 >= v20 {
									goto LABEL_43
								}
							}
							v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + v19*4 + 1132))))
						}
					}
				LABEL_43:
					a2.field_0 = *(*float32)(unsafe.Pointer(uintptr(v16 + 56))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
					v21 = float64(*(*float32)(unsafe.Pointer(uintptr(v16 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
					v22 = math.Sqrt(v21*v21+float64(a2.field_0*a2.field_0)) + 0.001
					a2.field_0 = float32(float64(a2.field_0) / v22)
					a2.field_4 = float32(v21 / v22)
					if sub_534120(a1, &a2) != 0 {
						goto LABEL_49
					}
					v17 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 26, internCStr(__FILE__), __LINE__))
					if v17 == nil {
						goto LABEL_49
					}
					*(*int32)(unsafe.Add(unsafe.Pointer(v17), 4*1)) = v16
					goto LABEL_49
				}
				v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))))
				if sub_534120(a1, (*float2)(memmap.PtrOff(0x587000, uint32(v16*8)+194136))) == 0 {
					nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 56, internCStr(__FILE__), __LINE__)
					v17 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 27, internCStr(__FILE__), __LINE__))
					if v17 != nil {
						*(*int32)(unsafe.Add(unsafe.Pointer(v17), 4*1)) = v16
						goto LABEL_49
					}
				}
			}
		LABEL_49:
			if nox_xxx_unitIsMimic_534840(a1) != 0 || (gameFrame()-*(*uint32)(unsafe.Pointer(uintptr(v1 + 548)))) <= gameFPS()>>1 || *(*float32)(unsafe.Pointer(uintptr(a1 + 56))) == *(*float32)(unsafe.Pointer(uintptr(a1 + 72))) && *(*float32)(unsafe.Pointer(uintptr(a1 + 60))) == *(*float32)(unsafe.Pointer(uintptr(a1 + 76))) {
				result = (*int32)(unsafe.Pointer(uintptr(nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 29))))
				if result == nil {
					result = (*int32)(unsafe.Pointer(uintptr(nox_xxx_mobHealSomeone_5411A0((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
				}
			} else {
				result = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 25, internCStr(__FILE__), __LINE__))
				if result != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 72))))
					*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 76))))
				}
			}
			return result
		}
	}
	return result
}
func sub_546410(a1 int32) int32 {
	return sub_534780(a1)
}
func sub_546420(a1 int32) int32 {
	return sub_534780(a1)
}
func nox_xxx_mobActionEscort_546430(a1 *int32) int8 {
	var (
		v1  int32
		v2  *uint32
		v3  int32
		v4  *int32
		v5  int32
		v6  int32
		v7  float64
		v8  float64
		v9  *int32
		v10 int32
	)
	v1 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*187))
	v2 = (*uint32)(unsafe.Pointer(uintptr(v1 + int32((*(*byte)(unsafe.Pointer(uintptr(v1 + 544)))+23)*24))))
	if *(*uint32)(unsafe.Pointer(uintptr(v1 + int32((*(*byte)(unsafe.Pointer(uintptr(v1 + 544)))+23)*24) + 12))) == 0 {
		v3 = nox_xxx_monsterGetObjEscortName_546600(int32(uintptr(unsafe.Pointer(a1))))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) = uint32(v3)
		if v3 == 0 {
			*((*uint8)(unsafe.Pointer(&v4))) = uint8(int8(nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))))))
			return int8(uintptr(unsafe.Pointer(v4)))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = *(*uint32)(unsafe.Pointer(uintptr(v3 + 56)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = *(*uint32)(unsafe.Pointer(uintptr(v3 + 60)))
	}
	if nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))) != 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(v1 + 1196))) != 0 {
			v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 15, internCStr(__FILE__), __LINE__))
			if v4 != nil {
				v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 1196))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 56))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 60))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) = int32(gameFrame())
			}
			return int8(uintptr(unsafe.Pointer(v4)))
		}
		v4 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_monsterLookAtDamager_5466B0(int32(uintptr(unsafe.Pointer(a1)))))))
		if v4 != nil {
			return int8(uintptr(unsafe.Pointer(v4)))
		}
	} else if sub_5343C0(int32(uintptr(unsafe.Pointer(a1)))) != 0 {
		v4 = (*int32)(unsafe.Pointer(uintptr(sub_545E60((*nox_object_t)(unsafe.Pointer(a1))))))
		if v4 != nil {
			return int8(uintptr(unsafe.Pointer(v4)))
		}
		v4 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_monsterLookAtDamager_5466B0(int32(uintptr(unsafe.Pointer(a1)))))))
		if v4 != nil {
			return int8(uintptr(unsafe.Pointer(v4)))
		}
	}
	v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)))
	v7 = float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*14))) - *(*float32)(unsafe.Pointer(uintptr(v6 + 56))))
	v8 = float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*15))) - *(*float32)(unsafe.Pointer(uintptr(v6 + 60))))
	if (float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 1316))))+30.0)*(float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 1316))))+30.0) >= v8*v8+v7*v7 {
		if nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))) == 0 || (func() *int32 {
			v4 = (*int32)(unsafe.Pointer(uintptr(sub_5466F0((*nox_object_t)(unsafe.Pointer(a1))))))
			return v4
		}()) == nil {
			v4 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 29))))
			if v4 == nil {
				*((*uint8)(unsafe.Pointer(&v4))) = uint8(int8(nox_xxx_mobHealSomeone_5411A0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))))))
			}
		}
	} else {
		if sub_5343C0(int32(uintptr(unsafe.Pointer(a1)))) != 0 || nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))) != 0 {
			nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 44, internCStr(__FILE__), __LINE__)
		}
		if nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))) != 0 {
			nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 56, internCStr(__FILE__), __LINE__)
		}
		v9 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 49, internCStr(__FILE__), __LINE__))
		if v9 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v9), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 1316))))
			*(*int32)(unsafe.Add(unsafe.Pointer(v9), 4*3)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)))
		}
		v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 7, internCStr(__FILE__), __LINE__))
		if v4 != nil {
			v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)))
			*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v10 + 56))))
			*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v10 + 60))))
			*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)))
		}
	}
	return int8(uintptr(unsafe.Pointer(v4)))
}
func nox_xxx_monsterGetObjEscortName_546600(a1 int32) int32 {
	var (
		v1     *byte
		v2     int32
		i      int32
		v4     int32
		result int32
		v6     int32
	)
	v1 = (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 1364)))
	if libc.StrCmp(v1, internCStr("**PLAYER**")) == 0 {
		v2 = 0
		for i = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(i))))))) {
			v2++
		}
		v4 = nox_common_randomInt_415FA0(0, v2-1)
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
		if result != 0 {
			for {
				v6 = func() int32 {
					p := &v4
					x := *p
					*p--
					return x
				}()
				if v6 == 0 {
					break
				}
				result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(result)))))))
				if result == 0 {
					*v1 = 0
					return result
				}
			}
		}
	} else {
		if libc.StrCmp((*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748)))+1364))), internCStr("**OWNER**")) == 0 {
			result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
			*v1 = 0
			return result
		}
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getObjectByScrName_4DA4F0((*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 1364)))))))
	}
	*v1 = 0
	return result
}
func nox_xxx_monsterLookAtDamager_5466B0(a1 int32) int32 {
	var v1 *int32
	if sub_5347A0((*nox_object_t)(unsafe.Pointer(uintptr(a1)))) == 0 {
		return 0
	}
	v1 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 25, internCStr(__FILE__), __LINE__))
	if v1 != nil {
		*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 528))))
		*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 532))))
	}
	return 1
}
func sub_5466F0(a1p *nox_object_t) int32 {
	var (
		a1 *uint32 = (*uint32)(unsafe.Pointer(a1p))
		v1 int32
		v2 *float32
		v3 float32
		v4 float32
		v5 float32
		v6 *int32
		v7 *int32
		v9 float4
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*187)))
	if *(*uint32)(unsafe.Pointer(uintptr(v1 + 388))) == 0 || gameFrame()-*(*uint32)(unsafe.Pointer(uintptr(v1 + 404))) >= (gameFPS()*3) {
		return 0
	}
	if sub_534020(int32(uintptr(unsafe.Pointer(a1)))) != 0 || nox_xxx_tileNFromPoint_411160((*float2)(unsafe.Pointer(uintptr(v1+396)))) != 6 {
		v2 = (*float32)(unsafe.Pointer(uintptr(v1 + 396)))
		if sub_50B810(int32(uintptr(unsafe.Pointer(a1))), (*float32)(unsafe.Pointer(uintptr(v1+396)))) != 0 {
			v3 = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*14)))
			v4 = *v2
			v9.field_4 = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*15)))
			v9.field_0 = v3
			v5 = *(*float32)(unsafe.Pointer(uintptr(v1 + 400)))
			v9.field_8 = v4
			v9.field_C = v5
			if nox_xxx_mapTraceRay_535250(&v9, nil, nil, 9) != 0 {
				sub_545DA0(int32(uintptr(unsafe.Pointer(a1))))
			} else {
				nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 59, internCStr(__FILE__), __LINE__)
				nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 56, internCStr(__FILE__), __LINE__)
				nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 70, internCStr(__FILE__), __LINE__)
				v6 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 69, internCStr(__FILE__), __LINE__))
				if v6 != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1)) = int32(*(*uint32)(unsafe.Pointer(v2)))
					*(*int32)(unsafe.Add(unsafe.Pointer(v6), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 400))))
				}
				v7 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 7, internCStr(__FILE__), __LINE__))
				if v7 != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1)) = int32(*(*uint32)(unsafe.Pointer(v2)))
					*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 400))))
					*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*3)) = 0
				}
			}
		}
	}
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 388))) = 0
	return 1
}
func nox_xxx_mobAction_5469B0(a1p *nox_object_t) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 int32
		v2 int32
		v3 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&2 != 0 {
		if nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(a1)))) == 0 && *(*uint32)(unsafe.Pointer(uintptr(v1 + 1196))) == 0 && float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 524)))) <= 300.0 {
			v2 = nox_xxx_mobActionGet_50A020(a1)
			if (v2 == 0 || v2 == 4) && gameFrame() >= uint32(*(*int32)(unsafe.Pointer(uintptr(v1 + 528)))) {
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 528))) = gameFrame() + uint32(nox_common_randomInt_415FA0(int32(gameFPS()*20), int32(gameFPS()*60)))
				v3 = int32(uintptr(nox_xxx_monsterGetSoundSet_424300((*nox_object_t)(unsafe.Pointer(uintptr(a1))))))
				if v3 != 0 {
					nox_xxx_aud_501960(int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 16)))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
				}
			}
		}
	}
}
func nox_xxx_unitIsDangerous_547120(a1p *nox_object_t, a2p *nox_object_t) int16 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v2 int32
		v3 int32
	)
	if *memmap.PtrUint32(0x5D4594, 2489468) == 0 {
		*memmap.PtrUint32(0x5D4594, 2489468) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ToxicCloud")))
		*memmap.PtrUint32(0x5D4594, 2489472) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallToxicCloud")))
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	if v2&0x2000 != 0 {
		v3 = sub_534020(a2)
		if v3 == 0 {
			dword_5d4594_2489460 = 0
		}
	} else {
		v3 = int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))
		if uint32(uint16(int16(v3))) == *memmap.PtrUint32(0x5D4594, 2489468) || uint32(v3) == *memmap.PtrUint32(0x5D4594, 2489472) {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 12))))
			if (v3 & 0x200) == 0 {
				dword_5d4594_2489460 = 0
			}
		} else if uint32(v2)&0x10000 != 0 {
			dword_5d4594_2489460 = 0
		}
	}
	return int16(v3)
}
func nox_xxx_monsterPopAttackActions_5471B0(a1 int32) {
	var v1 int32
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	for {
		switch *(*uint32)(unsafe.Pointer(uintptr(v1 + int32((*(*byte)(unsafe.Pointer(uintptr(v1 + 544)))+23)*24)))) {
		case 0x10:
			fallthrough
		case 0x11:
			fallthrough
		case 0x12:
			fallthrough
		case 0x13:
			fallthrough
		case 0x14:
			fallthrough
		case 0x19:
			fallthrough
		case 0x1A:
			fallthrough
		case 0x1B:
			fallthrough
		case 0x1C:
			nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		default:
			return
		}
	}
}
func nox_xxx_monsterMainAIFn_547210(a1p *nox_object_t) {
	var (
		a1  int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1  int32
		v2  int32
		v3  *int32
		v4  **int32
		v5  *int32
		v6  *uint32
		v7  *uint32
		v8  int32
		v9  float64
		v10 float64
		v11 int32
		v12 *int32
		v13 *int32
		v14 *int32
		v15 *int32
		v16 *int32
		v17 int32
		v18 int32
		v19 int32
		v20 float64
		v21 int32
		v22 int32
		v23 *int32
		v24 *int32
		v25 *int32
		v26 int32
		v27 int32
		v28 int32
		v29 int32
		v30 **int32
		v31 *int32
		v32 float64
		v33 float64
		v34 int32
		v35 *int32
		v36 int32
		v37 int32
		v39 int32
		v40 **int32
		v41 float32
		v42 float32
		v43 [3]int32
		v44 *int32
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v3 = (*int32)(unsafe.Pointer(uintptr(*(*byte)(unsafe.Pointer(uintptr(v2 + 544))))))
	v4 = (**int32)(unsafe.Pointer(uintptr(uint32(v2) + (uint32(uintptr(unsafe.Pointer(v3)))*3+69)*8)))
	v40 = v4
	v5 = *v4
	if (v5 == nil || uintptr(unsafe.Pointer(v5)) == uintptr(4)) && (int32(uint8(gameFrame()))+int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 36))))-int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 548)))))&0xF != 0 {
		return
	}
	v3 = (*int32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v3))), -1))))
	if int32(uintptr(unsafe.Pointer(v3))) >= 0 {
		v6 = (*uint32)(unsafe.Pointer(uintptr(uint32(v2) + (uint32(uintptr(unsafe.Pointer(v3)))*3+69)*8)))
		for *v6 != 61 {
			v3 = (*int32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v3))), -1))))
			v6 = (*uint32)(unsafe.Add(unsafe.Pointer(v6), -int(4*6)))
			if int32(uintptr(unsafe.Pointer(v3))) < 0 {
				goto LABEL_8
			}
		}
		return
	}
LABEL_8:
	v3 = *(**int32)(unsafe.Pointer(uintptr(a1 + 16)))
	if int32(*(*int8)(unsafe.Add(unsafe.Pointer((*int8)(unsafe.Pointer(&v3))), 1))) < 0 {
		return
	}
	v44 = (*int32)(nox_xxx_monsterGetSoundSet_424300((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))
	if nox_common_gameFlags_check_40A5C0(2048) {
		if nox_xxx_guiCursor_477600() == 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 20))))&0x10 != 0 {
				if nox_getHostPlayerUnit() != nil {
					if (int32(*(*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(nox_getHostPlayerUnit()))) + 16))))&2) == 0 && nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 2) == 0 {
						v7 = *(**uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(nox_getHostPlayerUnit()))) + 748)))
						v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*69)))
						v9 = float64(*(*int32)(unsafe.Pointer(uintptr(v8 + 2284)))) - float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 56))))
						v10 = float64(*(*int32)(unsafe.Pointer(uintptr(v8 + 2288)))) - float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 60))))
						if v10*v10+v9*v9 < 100.0 && unsafe.Pointer(nox_xxx_findObjectAtCursor_54AF40(nox_getHostPlayerUnit())) == unsafe.Pointer(uintptr(v1)) {
							v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 60))))
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 72))) = *(*uint32)(unsafe.Pointer(uintptr(v1 + 56)))
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 92))) = 0
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 88))) = 0
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 100))) = 0
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 96))) = 0
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 84))) = 0
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 80))) = 0
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 76))) = uint32(v11)
							nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 71, internCStr(__FILE__), __LINE__)
							v12 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 2, internCStr(__FILE__), __LINE__))
							if v12 != nil {
								*(*int32)(unsafe.Add(unsafe.Pointer(v12), 4*1)) = int32(gameFPS())
							}
							nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 67, internCStr(__FILE__), __LINE__)
							v13 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 2, internCStr(__FILE__), __LINE__))
							if v13 != nil {
								*(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1)) = 999999
							}
							v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 26, internCStr(__FILE__), __LINE__))
							if v3 != nil {
								*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = int32(uintptr(unsafe.Pointer(nox_getHostPlayerUnit())))
							}
							if *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*71)) == 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*70)) == 0 {
								*((*uint8)(unsafe.Pointer(&v3))) = uint8(uintptr(unsafe.Pointer(v44)))
								if v44 != nil {
									nox_xxx_aud_501960(*(*int32)(unsafe.Add(unsafe.Pointer(v44), 4*1)), (*nox_object_t)(unsafe.Pointer(uintptr(v1))), 0, 0)
								}
							}
							return
						}
					}
				}
			}
		}
	}
	if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 3) != 0 && nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 36) == 0 {
		v14 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 62, internCStr(__FILE__), __LINE__))
		v40 = (**int32)(unsafe.Pointer(v14))
		if v14 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v14), 4*1)) = 3
		}
		nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 36, internCStr(__FILE__), __LINE__)
	}
	if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 29) != 0 || (func() *int32 {
		v3 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_mobCastInversion_5408D0(v1))))
		return v3
	}()) == nil {
		if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 11) != 0 && nox_xxx_monsterIsMoveing_534320(v1) != 0 && nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 24) == 0 {
			v15 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 62, internCStr(__FILE__), __LINE__))
			if v15 != nil {
				*(*int32)(unsafe.Add(unsafe.Pointer(v15), 4*1)) = 11
			}
			v16 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 24, internCStr(__FILE__), __LINE__))
			if v16 != nil {
				*(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 56))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 60))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*3)) = 0
			}
			*((*uint8)(unsafe.Pointer(&v3))) = uint8(uintptr(unsafe.Pointer(v44)))
			if v44 != nil {
				nox_xxx_aud_501960(*(*int32)(unsafe.Add(unsafe.Pointer(v44), 4*12)), (*nox_object_t)(unsafe.Pointer(uintptr(v1))), 0, 0)
			}
			return
		}
		if (int32(uint8(gameFrame()))&0xF) == 0 && (sub_5343C0(v1) != 0 || nox_xxx_monsterCanAttackAtWill_534390((*nox_object_t)(unsafe.Pointer(uintptr(v1)))) != 0) {
			if nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 4) != 0 {
				if nox_xxx_mobActionGet_50A020(v1) != 4 && nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 15) == 0 {
					v17 = int32(uintptr(unsafe.Pointer(nox_xxx_enemyAggro_5335D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 100.0))))
					if v17 != 0 {
						if int32(*(*uint8)(unsafe.Pointer(uintptr(v17 + 8))))&6 != 0 {
							v18 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 1440))))
							v19 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 1196))))
							*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v18))), 1)) |= 2
							*(*uint32)(unsafe.Pointer(uintptr(v2 + 1440))) = uint32(v18)
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 520))) = uint32(v19)
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 524))) = 11
							*(*uint32)(unsafe.Pointer(uintptr(v1 + 536))) = gameFrame()
						}
					}
				}
			}
		}
		if sub_534440(v1) == 0 {
			if nox_xxx_monsterIsMoveing_534320(v1) != 0 {
				if sub_5408A0(v1) == 0 && nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 3) == 0 && nox_xxx_mobGetMoveAttemptTime_534810((*nox_object_t)(unsafe.Pointer(uintptr(v1)))) == 0 {
					if *(*uint32)(unsafe.Pointer(uintptr(v2 + 1196))) != 0 {
						v20 = nox_xxx_calcDistance_4E6C00((*nox_object_t)(unsafe.Pointer(uintptr(v1))), (*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 1196)))))))
						if v20 < float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 1356)))) {
							if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 1440))))&0x20 != 0 {
								if *(*uint32)(unsafe.Pointer(uintptr(v2 + 1504))) != 0 {
									if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 29) == 0 && gameFrame() >= uint32(*(*int32)(unsafe.Pointer(uintptr(v2 + 1484)))) {
										v41 = float32(v20)
										if float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 1356))))*0.5 > float64(v41) {
											v21 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 56))))
											v22 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 60))))
											v43[0] = v1
											v43[1] = v21
											v43[2] = v22
											nox_xxx_mobCast_541300(4, (*uint32)(unsafe.Pointer(uintptr(v1))), int32(uintptr(unsafe.Pointer(&v43[0]))))
											v3 = (*int32)(unsafe.Pointer(uintptr(gameFrame() + uint32(nox_common_randomInt_415FA0(int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 1480)))), int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 1482)))))))))
											*(*uint32)(unsafe.Pointer(uintptr(v2 + 1484))) = uint32(uintptr(unsafe.Pointer(v3)))
											return
										}
									}
								}
							}
							if nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 24) == 0 && float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 1356)))) != 0.0 {
								v23 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 28, internCStr(__FILE__), __LINE__))
								if v23 != nil {
									*(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*1)) = int32(*(*int16)(unsafe.Pointer(uintptr(v1 + 124)))) + 128
								}
								nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 68, internCStr(__FILE__), __LINE__)
								v24 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 63, internCStr(__FILE__), __LINE__))
								if v24 != nil {
									*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v24))), unsafe.Sizeof(float32(0))*1))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 1356)))) + 30.0)
								}
								v25 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 24, internCStr(__FILE__), __LINE__))
								if v25 != nil {
									v26 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 1196))))
									*(*int32)(unsafe.Add(unsafe.Pointer(v25), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v26 + 56))))
									v27 = int32(*(*uint32)(unsafe.Pointer(uintptr(v26 + 60))))
									*(*int32)(unsafe.Add(unsafe.Pointer(v25), 4*3)) = 0
									*(*int32)(unsafe.Add(unsafe.Pointer(v25), 4*2)) = v27
								}
								v3 = (*int32)(unsafe.Pointer(uintptr(nox_common_randomInt_415FA0(0, 1))))
								if v3 != nil {
									*((*uint8)(unsafe.Pointer(&v3))) = uint8(uintptr(unsafe.Pointer(v44)))
									if v44 != nil {
										nox_xxx_aud_501960(*(*int32)(unsafe.Add(unsafe.Pointer(v44), 4*12)), (*nox_object_t)(unsafe.Pointer(uintptr(v1))), 0, 0)
									}
								}
								return
							}
						}
					}
				}
			}
		}
		if int32(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 556))) + 4)))) != 0 && nox_xxx_monsterIsMoveing_534320(v1) != 0 && nox_xxx_mobGetMoveAttemptTime_534810((*nox_object_t)(unsafe.Pointer(uintptr(v1)))) == 0 && nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 24) == 0 && nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 6) == 0 && nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 14) == 0 {
			v42 = float32(float64(**(**uint16)(unsafe.Pointer(uintptr(v1 + 556)))) / float64(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 556))) + 4)))))
			v28 = bool2int32(int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 1440))))&0x20 != 0 && nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 29) != 0)
			if float64(v42) <= float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 1336)))) || v28 != 0 {
				nox_xxx_monsterPopAttackActions_5471B0(v1)
				nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 68, internCStr(__FILE__), __LINE__)
				if ((int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 1440))))&0x80) != 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 12))))&0x80 != 0) && nox_common_gameFlags_check_40A5C0(2048) {
					nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 14, internCStr(__FILE__), __LINE__)
				} else {
					nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 6, internCStr(__FILE__), __LINE__)
				}
				if v44 != nil {
					nox_xxx_aud_501960(*(*int32)(unsafe.Add(unsafe.Pointer(v44), 4*13)), (*nox_object_t)(unsafe.Pointer(uintptr(v1))), 0, 0)
				}
				nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(uintptr(v2+1256)), nil, unsafe.Pointer(uintptr(v1)), 4)
				return
			}
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 12))))&0x10 != 0 && (func() int32 {
			v29 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 2056))))
			return int32(*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v29))), 1))) & 4
		}()) != 0 {
			v30 = v40
			if uintptr(unsafe.Pointer(*v40)) != uintptr(16) && uintptr(unsafe.Pointer(*v40)) != uintptr(17) && nox_xxx_monsterTestBlockShield_533E70((*nox_object_t)(unsafe.Pointer(uintptr(v1)))) != 0 {
				v3 = *v40
				if uintptr(unsafe.Pointer(*v40)) != uintptr(1) && uintptr(unsafe.Pointer(v3)) != uintptr(23) {
					nox_xxx_monsterPopAttackActions_5471B0(v1)
					v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 1, internCStr(__FILE__), __LINE__))
					if v3 != nil {
						*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = int32(gameFrame() + gameFPS())
					}
				}
				return
			}
		} else {
			v30 = v40
		}
		if nox_xxx_monsterHasShield_5342C0(v1) != 0 && uintptr(unsafe.Pointer(*v30)) != uintptr(16) && uintptr(unsafe.Pointer(*v30)) != uintptr(17) && nox_xxx_monsterTestBlockShield_533E70((*nox_object_t)(unsafe.Pointer(uintptr(v1)))) != 0 {
			v3 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 21))))
			if v3 == nil {
				nox_xxx_monsterPopAttackActions_5471B0(v1)
				v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 21, internCStr(__FILE__), __LINE__))
				if v3 != nil {
					*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = int32(gameFrame() + (gameFPS() >> 1))
				}
			}
			return
		}
		if nox_common_gameFlags_check_40A5C0(2048) {
			if sub_534440(v1) == 0 && nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 3) == 0 {
				if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 92))))&8 != 0 {
					if nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 9) == 0 {
						if nox_xxx_monsterTestBlockShield_533E70((*nox_object_t)(unsafe.Pointer(uintptr(v1)))) != 0 {
							v3 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_monsterCheckDodgeables_547C50(v1))))
							if v3 != nil {
								return
							}
						}
					}
				}
			}
		}
		v31 = *v30
		if uintptr(unsafe.Pointer(*v30)) == uintptr(7) || uintptr(unsafe.Pointer(v31)) == uintptr(37) || uintptr(unsafe.Pointer(v31)) == uintptr(8) || uintptr(unsafe.Pointer(v31)) == uintptr(10) || uintptr(unsafe.Pointer(v31)) == uintptr(24) {
			v32 = float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 500))) - *(*float32)(unsafe.Pointer(uintptr(v1 + 56))))
			v33 = float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 504))) - *(*float32)(unsafe.Pointer(uintptr(v1 + 60))))
			if v33*v33+v32*v32 > 225.0 {
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 496))) = gameFrame()
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 500))) = *(*uint32)(unsafe.Pointer(uintptr(v1 + 56)))
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 504))) = *(*uint32)(unsafe.Pointer(uintptr(v1 + 60)))
			} else if (gameFrame() - *(*uint32)(unsafe.Pointer(uintptr(v2 + 496)))) > uint32(int32(gameFPS())>>1) {
				v39 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 36))))
				v34 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*nox_object_t)(unsafe.Pointer(uintptr(v1)))))))
				nox_ai_debug_printf_5341A0(internCStr("%d: %s(#%d) FRUSTRATED\n"), gameFrame(), v34, v39)
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 1440))) |= 0x200000
				if nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 6) != 0 || nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 14) != 0 || nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 24) != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v2 + 508))) = gameFrame()
				}
				if nox_xxx_checkMobAction_50A0D0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 15) != 0 {
					nox_xxx_monsterCheckDodgeables_547C50(v1)
				} else if nox_common_randomInt_415FA0(0, 100) >= 33 || nox_xxx_monsterCheckDodgeables_547C50(v1) == 0 {
					v35 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 1, internCStr(__FILE__), __LINE__))
					if v35 != nil {
						*(*int32)(unsafe.Add(unsafe.Pointer(v35), 4*1)) = int32(gameFrame() + uint32(nox_common_randomInt_415FA0(int32(gameFPS()>>1), int32(gameFPS()*2))))
					}
				}
				*((*uint8)(unsafe.Pointer(&v3))) = uint8(gameFrame())
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 496))) = gameFrame()
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 500))) = *(*uint32)(unsafe.Pointer(uintptr(v1 + 56)))
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 504))) = *(*uint32)(unsafe.Pointer(uintptr(v1 + 60)))
				return
			}
		}
		v3 = (*int32)(unsafe.Pointer(uintptr(sub_534440(v1))))
		if v3 == nil {
			v3 = (*int32)(unsafe.Pointer(uintptr(sub_5347C0(v1))))
			if v3 != nil {
				if (int32(uint8(gameFrame())) & 0xF) == 0 {
					v3 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_mobSearchEdible_544A00((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 75.0))))
					v36 = int32(uintptr(unsafe.Pointer(v3)))
					if v3 != nil {
						nox_xxx_inventoryServPlace_4F36F0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), 1, 1)
						*((*uint8)(unsafe.Pointer(&v3))) = *(*uint8)(unsafe.Pointer(uintptr(v36 + 12)))
						if int32(uint8(uintptr(unsafe.Pointer(v3))))&0x90 != 0 {
							*((*uint8)(unsafe.Pointer(&v3))) = uint8(int8(nox_xxx_useByNetCode_53F8E0(v1, v36)))
						}
					}
				}
			}
		}
		if *(*uint32)(unsafe.Pointer(uintptr(v2 + 1440)))&0x20000 != 0 {
			v3 = *(**int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 2180))) + 276)))
			if int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v3))), 2251)))) == 0 && *(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) == 0 && (int32(uint8(gameFrame()))&0xF) == 0 {
				v3 = (*int32)(unsafe.Pointer(uintptr(sub_544AE0(v1, 75.0))))
				v37 = int32(uintptr(unsafe.Pointer(v3)))
				if v3 != nil {
					nox_xxx_mobMorphToPlayer_4FAAF0((*uint32)(unsafe.Pointer(uintptr(v1))))
					nox_xxx_inventoryServPlace_4F36F0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), (*nox_object_t)(unsafe.Pointer(uintptr(v37))), 1, 1)
					*((*uint8)(unsafe.Pointer(&v3))) = uint8(nox_xxx_mobMorphFromPlayer_4FAAC0((*uint32)(unsafe.Pointer(uintptr(v1)))))
				}
			}
		}
	}
}
func nox_xxx_monsterCheckDodgeables_547C50(a1 int32) int32 {
	var (
		v1  *float32
		v2  int32
		v3  int32
		v4  float64
		v5  float32
		v6  float64
		v7  float64
		v9  *int32
		v10 *int32
		v11 float32
		v12 float32
		v13 float4
		v14 float32
	)
	v1 = (*float32)(unsafe.Pointer(uintptr(a1)))
	v2 = 0
	v3 = int32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124))))
	v4 = float64(*mem_getFloatPtr(0x587000, uint32(v3*8)+194140))
	v12 = *mem_getFloatPtr(0x587000, uint32(v3*8)+194136)
	v5 = *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
	v13.field_0 = *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
	v11 = float32(-v4)
	v13.field_4 = v5
	for {
		v6 = nox_common_randomFloat_416030(2.0, 3.0) * float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*44)))
		v14 = float32(v6)
		if v6 > 15.0 {
			v14 = 15.0
		}
		v7 = float64(v14)
		if nox_common_randomInt_415FA0(0, 100) < 50 {
			v7 = -v7
		}
		v13.field_8 = float32(v7*float64(v11) + float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*14))))
		v13.field_C = float32(v7*float64(v12) + float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*15))))
		if nox_xxx_mapTraceRay_535250(&v13, nil, nil, 1) != 0 {
			if nox_xxx_mapTraceObstacles_50B580((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), &v13) != 0 && nox_xxx_tileNFromPoint_411160((*float2)(unsafe.Pointer(&v13.field_8))) != 6 {
				break
			}
		}
		if func() int32 {
			p := &v2
			*p++
			return *p
		}() >= 5 {
			return 0
		}
	}
	nox_xxx_monsterPopAttackActions_5471B0(int32(uintptr(unsafe.Pointer(v1))))
	v9 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), 41, internCStr(__FILE__), __LINE__))
	if v9 != nil {
		*(*int32)(unsafe.Add(unsafe.Pointer(v9), 4*1)) = int32(gameFrame() + gameFPS())
	}
	v10 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), 9, internCStr(__FILE__), __LINE__))
	if v10 != nil {
		*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*1)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&v13.field_8))), 4*0)))
		*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*2)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&v13.field_C))), 4*0)))
		*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*3)) = 0
	}
	return 1
}
func sub_547DB0(a1 int32, a2 *float2) int32 {
	var (
		v3 float64
		v4 float64
		v5 float32
		v6 float32
		v7 float32
		v8 float32
	)
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 172))) == 1 {
		return 0
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 172))) != 2 {
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 172))) == 3 {
			v5 = *(*float32)(unsafe.Pointer(uintptr(a1 + 192))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 64)))
			v6 = *(*float32)(unsafe.Pointer(uintptr(a1 + 196))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 68)))
			if float64(v6-v5+a2.field_0-a2.field_4)*0.70709997 < 0.0 && float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 204)))+*(*float32)(unsafe.Pointer(uintptr(a1 + 68)))-(*(*float32)(unsafe.Pointer(uintptr(a1 + 200)))+*(*float32)(unsafe.Pointer(uintptr(a1 + 64))))+a2.field_0-a2.field_4)*0.70709997 > 0.0 {
				v7 = *(*float32)(unsafe.Pointer(uintptr(a1 + 208))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 64)))
				v8 = *(*float32)(unsafe.Pointer(uintptr(a1 + 212))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 68)))
				if float64(v8+v7-a2.field_0-a2.field_4)*0.70709997 > 0.0 && float64(v6+v5-a2.field_0-a2.field_4)*0.70709997 < 0.0 {
					return 1
				}
			}
		}
		return 0
	}
	v3 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 64))) - a2.field_0)
	v4 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 68))) - a2.field_4)
	if v4*v4+v3*v3 > float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 180)))) {
		return 0
	}
	return 1
}
func sub_547EE0(a1 int32, a2 uint8) int32 {
	return bool2int32(a1 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 480))))&1 != 0 && sub_579EE0((*nox_waypoint_t)(unsafe.Pointer(uintptr(a1))), a2) != 0)
}
func sub_547F10() int32 {
	var result int32
	result = int32(*memmap.PtrUint32(0x5D4594, 2490500))
	*memmap.PtrUint32(0x5D4594, 2490500) = 0
	return result
}
func sub_547F20(a1 int32, a2 *float32) int32 {
	var (
		v2     int32
		v3     *uint32
		v4     int32
		result int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v3 = (*uint32)(unsafe.Pointer(uintptr(sub_50CB20(a1, (*float32)(unsafe.Pointer(uintptr(a1+56)))))))
	v4 = sub_50CB20(a1, a2)
	if v3 != nil && v4 != 0 && v3 != (*uint32)(unsafe.Pointer(uintptr(v4))) {
		result = nox_xxx_BuildWaypointPath_547F70(v3, v4, (*uint32)(unsafe.Pointer(uintptr(v2+300))), 16)
	} else {
		result = 0
	}
	return result
}
func nox_xxx_BuildWaypointPath_547F70(a1 *uint32, a2 int32, a3 *uint32, a4 int32) int32 {
	var (
		v4  *uint32
		v5  int32
		v6  int32
		v7  *uint32
		v8  int32
		v9  *uint8
		v10 int32
		v11 *uint32
		v12 *uint8
		v14 *uint32
	)
	v4 = a1
	if sub_547EE0(int32(uintptr(unsafe.Pointer(a1))), 0x80) != 0 && sub_547EE0(a2, 0x80) != 0 {
		dword_5d4594_2490504++
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*math.MaxInt8)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*128)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*126)) = dword_5d4594_2490504
		for {
			v14 = nil
			if v4 == nil {
				break
			}
			for {
				if v4 == (*uint32)(unsafe.Pointer(uintptr(a2))) {
					v8 = 0
					*memmap.PtrUint32(0x5D4594, 2490500) = 0
					v9 = (*uint8)(memmap.PtrOff(0x5D4594, 2489476))
					for {
						*(*uint32)(unsafe.Pointer(v9)) = uint32(uintptr(unsafe.Pointer(v4)))
						v4 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*math.MaxInt8)))))
						v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 4))
						v8++
						if unsafe.Pointer(v9) == memmap.PtrOff(0x5D4594, 2490500) {
							break
						}
						if v4 == nil {
							goto LABEL_20
						}
					}
					nox_ai_debug_printf_5341A0(internCStr("BuildWaypointPath: Node list exceeded internal buffer.\n"))
				LABEL_20:
					v10 = 0
					if v8 > 0 {
						v11 = a3
						v12 = (*uint8)(memmap.PtrOff(0x5D4594, uint32(v8*4)+2489472))
						for {
							*v11 = *(*uint32)(unsafe.Pointer(v12))
							if v10 == a4 {
								break
							}
							v10++
							v12 = (*uint8)(unsafe.Add(unsafe.Pointer(v12), -4))
							v11 = (*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
							if v10 >= v8 {
								break
							}
						}
					}
					if v10 != v8 {
						nox_ai_debug_printf_5341A0(internCStr("BuildWaypointPath: Node list too long.\n"))
						*memmap.PtrUint32(0x5D4594, 2490500) = 1
					}
					return v10
				}
				v5 = 0
				if int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v4))), 476)))) != 0 {
					v6 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*23)))))
					for {
						v7 = *(**uint32)(unsafe.Pointer(uintptr(v6)))
						if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v6))) + 504))) != dword_5d4594_2490504 {
							if sub_547EE0(int32(uintptr(unsafe.Pointer(v7))), 0x80) != 0 {
								*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*math.MaxInt8)) = uint32(uintptr(unsafe.Pointer(v4)))
								*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*128)) = uint32(uintptr(unsafe.Pointer(v14)))
								v14 = v7
								*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*126)) = dword_5d4594_2490504
							}
						}
						v5++
						v6 += 8
						if v5 >= int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v4))), 476)))) {
							break
						}
					}
				}
				v4 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*128)))))
				if v4 == nil {
					break
				}
			}
			v4 = v14
			if v14 == nil {
				break
			}
		}
	}
	*memmap.PtrUint32(0x5D4594, 2490500) = 2
	return 0
}
func sub_548100(a1 *int2, a2 int32) {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  *byte
		v8  int32
		v9  float2
		v10 int32
	)
	v2 = int32(uintptr(nox_server_getWallAtGrid_410580(a1.field_0, a1.field_4)))
	if v2 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 4))))&4 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&6 != 0 {
				v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 28))))
				if int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 21)))) == 1 {
					if int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 20))))&2 != 0 {
						*(*uint8)(unsafe.Pointer(uintptr(v3 + 21))) = 4
						v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 4))))
						*(*uint8)(unsafe.Pointer(uintptr(v3 + 22))) = 0
						v5 = v4 * 23
						v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 8))) * 23)
						v6 = int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 1))))
						v9.field_0 = float32(float64(v5) + 11.5)
						v9.field_4 = float32(float64(v10) + 11.5)
						v7 = nox_xxx_wallFindOpenSound_410EE0(v6)
						v8 = nox_xxx_utilFindSound_40AF50(v7)
						nox_xxx_audCreate_501A30(v8, &v9, 0, 0)
					}
				}
			}
		}
	}
}
func sub_5481C0(a1 int32) {
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 96))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 100))) = 0
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16)))) & 0x60) == 0 {
		nox_xxx_getUnitsInRect_517C10((*float4)(unsafe.Pointer(uintptr(a1+232))), unsafe.Pointer(funAddr(sub_548220)), unsafe.Pointer(uintptr(a1)))
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16)))) & 8) == 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(a1 + 172))) == 2 {
				sub_54FEF0(a1)
			} else if *(*uint32)(unsafe.Pointer(uintptr(a1 + 172))) == 3 {
				sub_5504B0(a1)
			}
		}
	}
}
func sub_548220(a1 *int32, a2 *float32) {
	var (
		v2 int32
		v3 int32
		v4 int32
	)
	if sub_548360(int32(uintptr(unsafe.Pointer(a2))), int32(uintptr(unsafe.Pointer(a1)))) != 0 {
		v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*2))))
		if v2&0x4000 != 0 {
			sub_551AE0(int32(uintptr(unsafe.Pointer(a2))), int32(uintptr(unsafe.Pointer(a1))), 0)
		} else {
			v3 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2))
			if v3&0x4000 != 0 {
				sub_551AE0(int32(uintptr(unsafe.Pointer(a1))), int32(uintptr(unsafe.Pointer(a2))), 1)
			} else if (v2 & 0x8000) == 0 {
				if (v3 & 0x8000) == 0 {
					if (v2 & 0x80) == 0 {
						if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*43))) == 2 {
							if (v3 & 0x80) == 0 {
								if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*43)) == 2 {
									nox_xxx_collisionCheckCircleCircle_550D00(int32(uintptr(unsafe.Pointer(a2))), int32(uintptr(unsafe.Pointer(a1))))
								} else if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*43)) == 3 {
									sub_54AD50(int32(uintptr(unsafe.Pointer(a2))), int32(uintptr(unsafe.Pointer(a1))), 0)
								}
							} else {
								sub_5488B0(a1, a2, 1)
							}
						} else if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*43))) == 3 {
							if (v3 & 0x80) == 0 {
								if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*43)) == 2 {
									sub_54AD50(int32(uintptr(unsafe.Pointer(a1))), int32(uintptr(unsafe.Pointer(a2))), 1)
								} else if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*43)) == 3 {
									sub_550F80(a2, int32(uintptr(unsafe.Pointer(a1))))
								}
							} else {
								sub_551250(uint32(uintptr(unsafe.Pointer(a1))), a2, 1)
							}
						}
					} else {
						v4 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*43))
						if v4 == 2 {
							sub_5488B0((*int32)(unsafe.Pointer(a2)), (*float32)(unsafe.Pointer(a1)), 0)
						} else if v4 == 3 {
							sub_551250(uint32(uintptr(unsafe.Pointer(a2))), (*float32)(unsafe.Pointer(a1)), 0)
						}
					}
				} else {
					sub_551C40(int32(uintptr(unsafe.Pointer(a1))), int32(uintptr(unsafe.Pointer(a2))))
				}
			} else {
				sub_551C40(int32(uintptr(unsafe.Pointer(a2))), int32(uintptr(unsafe.Pointer(a1))))
			}
		}
	}
}
func sub_548360(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		v3     int32
		v4     func(int32) int32
		v5     func(int32) int32
		v6     int32
		v7     int32
		v8     int32
		v9     int16
		result int32
	)
	_ = result
	var v11 int32
	var v12 int32
	var v13 int32
	var v14 int32
	if dword_5d4594_2490508 != 0 {
		v2 = int32(*memmap.PtrUint32(0x5D4594, 2490516))
	} else {
		dword_5d4594_2490508 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Trigger")))
		*memmap.PtrUint32(0x5D4594, 2490512) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("BlackPowder")))
		v2 = nox_xxx_getNameId_4E3AA0(internCStr("TelekinesisHand"))
		*memmap.PtrUint32(0x5D4594, 2490516) = uint32(v2)
	}
	v3 = a2
	v4 = *(*func(int32) int32)(unsafe.Pointer(uintptr(a1 + 696)))
	if funAddr(v4) == funAddr(nox_xxx_collidePentagram_4EAB20) && int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))) == v2 {
		return 0
	}
	v5 = *(*func(int32) int32)(unsafe.Pointer(uintptr(a2 + 696)))
	if funAddr(v5) == funAddr(nox_xxx_collidePentagram_4EAB20) && int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) == v2 {
		return 0
	}
	v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))) & 0x80)
	if v12 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 16))))&9 != 0 {
			return 0
		}
	}
	v14 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))))
	if v14&0x80 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16))))&9 != 0 {
			return 0
		}
	}
	v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	v13 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	if v7&0x60 != 0 {
		return 0
	}
	v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 16))))
	if v8&0x60 != 0 || a1 == v3 || v4 == nil || v5 == nil {
		return 0
	}
	if v6&2 != 0 && v7&0x4000 != 0 {
		v9 = int16(v14)
		if v14&0xCC00 != 0 {
			return sub_5485B0(a1, v3)
		}
	} else {
		v9 = int16(v14)
	}
	if int32(v9)&2 != 0 && v8&0x4000 != 0 && v6&0xCC00 != 0 {
		return sub_5485B0(v3, a1)
	}
	if v6&0x2000 != 0 && uint32(*(*uint16)(unsafe.Pointer(uintptr(v3 + 4)))) == *memmap.PtrUint32(0x5D4594, 2490512) {
		return 1
	}
	if int32(v9)&0x2000 != 0 && uint32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) == *memmap.PtrUint32(0x5D4594, 2490512) {
		return 1
	}
	if (func() int32 {
		v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
		return v13 & 8
	}()) != 0 && v8&8 != 0 || v12 != 0 && v8&8 != 0 || v14&0x80 != 0 && v13&8 != 0 || uint32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) != dword_5d4594_2490508 && uint32(*(*uint16)(unsafe.Pointer(uintptr(v3 + 4)))) != dword_5d4594_2490508 && (v13&0x11 != 0 && uint32(v8)&0x24000 != 0 || v8&0x11 != 0 && uint32(v11)&0x24000 != 0) || v12 != 0 && v14&0x80 != 0 || v6&0x4000 != 0 && v14&0x4000 != 0 || (v6&0x8000) != 0 && (v14&0x8000) != 0 || v11&0x400 != 0 && nox_xxx_unitsHaveSameTeam_4EC520((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(v3)))) != 0 {
		return 0
	} else {
		return 1
	}
}
func sub_5485B0(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		i  *uint32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v3 = 0
	v4 = int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 2172))))
	if v4 <= 0 {
		return 0
	}
	for i = (*uint32)(unsafe.Pointer(uintptr(v2 + 2140))); *i != *(*uint32)(unsafe.Pointer(uintptr(a2 + 36))); i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
		if func() int32 {
			p := &v3
			*p++
			return *p
		}() >= v4 {
			return 0
		}
	}
	return 1
}
func nox_xxx_collSysAddCollision_548630(a1 int32, a2 uint32, a3 *float2) {
	var (
		v3 int32
		v4 int32
		v5 *uint32
		v6 int32
		v7 *int32
		v8 int32
	)
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 36))))
	if a2 > 6 {
		v3 += int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 36))))
	}
	v4 = v3 % 256
	v5 = *(**uint32)(memmap.PtrOff(0x5D4594, uint32(v4*4)+2490520))
	if v5 != nil {
		for {
			v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2)))
			if v6 == a1 && *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*3)) == a2 {
				break
			}
			if uint32(v6) == a2 && *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*3)) == uint32(a1) {
				break
			}
			v5 = (*uint32)(unsafe.Pointer(uintptr(*v5)))
			if v5 == nil {
				goto LABEL_9
			}
		}
		return
	}
LABEL_9:
	v7 = (*int32)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&nox_alloc_hit_2491548))))))
	if v7 != nil {
		*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*2)) = a1
		*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*3)) = int32(a2)
		*((*float2)(unsafe.Add(unsafe.Pointer((*float2)(unsafe.Pointer(v7))), unsafe.Sizeof(float2{})*2))) = *a3
		*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*6)) = v4
		*v7 = int32(*memmap.PtrUint32(0x5D4594, uint32(v4*4)+2490520))
		v8 = int32(dword_5d4594_2491544)
		*memmap.PtrUint32(0x5D4594, uint32(v4*4)+2490520) = uint32(uintptr(unsafe.Pointer(v7)))
		*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1)) = v8
		dword_5d4594_2491544 = uint32(uintptr(unsafe.Pointer(v7)))
	}
}
func nox_xxx_allocHitArray_5486D0() {
	var (
		v0 *byte
		i  int32
	)
	v0 = *(**byte)(unsafe.Pointer(&nox_alloc_hit_2491548))
	if nox_alloc_hit_2491548 == nil {
		v0 = (*byte)(unsafe.Pointer(nox_new_alloc_class(internCStr("Hit"), 28, 1024)))
		nox_alloc_hit_2491548 = unsafe.Pointer(v0)
		libc.MemSet(memmap.PtrOff(0x5D4594, 2490520), 0, 0x400)
	}
	for i = int32(dword_5d4594_2491544); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 4)))) {
		*memmap.PtrUint32(0x5D4594, *(*uint32)(unsafe.Pointer(uintptr(i + 24)))*4+2490520) = 0
	}
	nox_alloc_class_free_all((*nox_alloc_class)(unsafe.Pointer(v0)))
	dword_5d4594_2491544 = 0
}
func nox_xxx_collide_548740() {
	var (
		i  int32
		v1 uint32
		v2 int32
		v3 float2
	)
	for i = int32(dword_5d4594_2491544); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 4)))) {
		v1 = *(*uint32)(unsafe.Pointer(uintptr(i + 12)))
		if v1 > 6 || v1 == 0 {
			(*(*func(uint32, uint32, int32))(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 8))) + 696))))(*(*uint32)(unsafe.Pointer(uintptr(i + 8))), v1, i+16)
			if *(*uint32)(unsafe.Pointer(uintptr(i + 12))) != 0 {
				nox_xxx_collide_4FDF90(int32(*(*uint32)(unsafe.Pointer(uintptr(i + 8)))), int32(*(*uint32)(unsafe.Pointer(uintptr(i + 12)))))
			}
		}
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 12))))
		if v2 == 6 {
			(*(*func(uint32, uint32, uint32, int32, int32))(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 8))) + 716))))(*(*uint32)(unsafe.Pointer(uintptr(i + 8))), 0, 0, 2, 12)
			nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 8)))))))
		} else if v2 != 0 {
			v3.field_0 = -*(*float32)(unsafe.Pointer(uintptr(i + 16)))
			v3.field_4 = -*(*float32)(unsafe.Pointer(uintptr(i + 20)))
			(*(*func(uint32, uint32, *float2))(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 12))) + 696))))(*(*uint32)(unsafe.Pointer(uintptr(i + 12))), *(*uint32)(unsafe.Pointer(uintptr(i + 8))), &v3)
			nox_xxx_collide_4FDF90(int32(*(*uint32)(unsafe.Pointer(uintptr(i + 12)))), int32(*(*uint32)(unsafe.Pointer(uintptr(i + 8)))))
			if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 8))) + 16))))&8 != 0 {
				nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 12)))))))
			} else if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 12))) + 16))))&8 != 0 {
				nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 8)))))))
			}
		}
		nullsub_30(*(*uint32)(unsafe.Pointer(uintptr(i + 8))))
	}
}
func sub_548830(a1 int32) {
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 28))) == 0 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 36))) = dword_5d4594_2491552
		dword_5d4594_2491552 = uint32(a1)
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 28))) = 1
	}
}
func sub_548860(a1 int32, a2 int16) {
	var v2 int32
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	for *(*uint16)(unsafe.Pointer(uintptr(v2 + 40))) += uint16(a2); int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 40)))) < 0; *(*uint16)(unsafe.Pointer(uintptr(v2 + 40))) += 256 {
	}
	for ; int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 40)))) >= 256; *(*uint16)(unsafe.Pointer(uintptr(v2 + 40))) -= 256 {
	}
	sub_548830(v2)
}
func sub_5488B0(a1 *int32, a2 *float32, a3 int32) {
	var (
		v3  *int32
		v4  int32
		v5  float32
		v6  int32
		v7  *float32
		v8  *float32
		v9  float64
		v10 float64
		v11 float64
		v12 float64
		v13 float32
		v14 float64
		v15 float32
		v16 float64
		v17 int32
		v18 *float32
		v19 float64
		v20 float64
		v21 float32
		v22 float32
		v23 int32
		v24 float32
		v25 *int32
		v26 *uint8
		v27 float2
		a3a float2
		a1a float4
		v30 int32
		v31 float32
		v32 float32
		v33 float32
	)
	v3 = a1
	v4 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*187))
	v5 = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*17)))
	*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1a.field_0))), 4*0)) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*16)))
	a1a.field_4 = v5
	v6 = int32(*(*int16)(unsafe.Pointer(uintptr(v4 + 40)))) + 160
	if v6 >= 256 {
		v6 = int32(*(*int16)(unsafe.Pointer(uintptr(v4 + 40)))) - 96
	}
	v26 = (*uint8)(memmap.PtrOff(0x587000, uint32(v6*8)+192092))
	v7 = a2
	v25 = mem_getI32Ptr(0x587000, uint32(v6*8)+192088)
	v30 = *(*int32)(unsafe.Pointer(v26)) * 2
	v8 = (*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*16))
	a1a.field_8 = float32(float64(*memmap.PtrInt32(0x587000, uint32(v6*8)+192088)*2) + float64(a1a.field_0))
	a1a.field_C = float32(float64(v30) + float64(a1a.field_4))
	sub_57C790(&a1a, (*float2)(unsafe.Add(unsafe.Pointer((*float2)(unsafe.Pointer(a2))), unsafe.Sizeof(float2{})*8)), &a3a, 32.0)
	v9 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*16)) - a3a.field_0)
	v10 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*17)) - a3a.field_4)
	v27.field_4 = float32(v10)
	v11 = math.Sqrt(v10*float64(v27.field_4) + v9*v9)
	v31 = float32(v11)
	if v11 == 0.0 {
		v31 = 0.1
	}
	if float64(v31) < float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*44))) {
		v27.field_0 = float32(v9 / float64(v31))
		v27.field_4 = v27.field_4 / v31
		nox_xxx_collSysAddCollision_548630(int32(uintptr(unsafe.Pointer(a2))), uint32(uintptr(unsafe.Pointer(v3))), &v27)
		*(*uint32)(unsafe.Pointer(uintptr(v4 + 44))) = gameFrame()
		if a3 == 1 {
			v32 = *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*44)) - v31
			v24 = -(v27.field_4 * *(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*21))) - v27.field_0**(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*20))
			v12 = nox_xxx_objectGetMass_4E4A70(int32(uintptr(unsafe.Pointer(v7))))
			v13 = *(*float32)(unsafe.Pointer(&dword_587000_292492))
			v14 = math.Sqrt(v12 * float64(v13) * 4.0)
			v15 = *(*float32)(unsafe.Pointer(&dword_587000_292492))
			v16 = v14*float64(v24)*0.25 + float64(v15*v32)
			v22 = float32(v16 * float64(v27.field_4))
			v21 = float32(v16 * float64(v27.field_0))
			sub_548600((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v7)))))), v21, v22)
		}
		v17 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v7))), 4*4))))
		if uint32(v17)&0x8000000 != 0 {
			if (v17 & 8) == 0 {
				nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v7)))))))
			}
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v7))), 4*4))) &= 0xF7FFFFFF
		}
		nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))))
		if nox_xxx_servObjectHasTeam_419130(int32(uintptr(unsafe.Pointer((*int32)(unsafe.Add(unsafe.Pointer(v3), 4*12)))))) == 0 || *(*uint32)(unsafe.Pointer(uintptr(v4 + 12))) != *(*uint32)(unsafe.Pointer(uintptr(v4 + 4))) || nox_xxx_servCompareTeams_419150(int32(uintptr(unsafe.Pointer((*int32)(unsafe.Add(unsafe.Pointer(v3), 4*12))))), int32(uintptr(unsafe.Pointer((*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*12)))))) != 0 {
			if a3 == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 1)))) == 0 {
				v18 = (*float32)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*math.MaxInt8)))))
				if v18 == nil || v18 == v7 {
					v33 = *(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*44)) - v31
					v19 = float64(v33 * *(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*30)))
					if float64(*v25)*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*17))-*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v3))), unsafe.Sizeof(float32(0))*17))))-float64(*(*int32)(unsafe.Pointer(v26)))*float64(*v8-*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v3))), unsafe.Sizeof(float32(0))*16)))) <= 0.0 {
						v20 = v19 + float64(*(*float32)(unsafe.Pointer(uintptr(v4 + 32))))
					} else {
						v20 = float64(*(*float32)(unsafe.Pointer(uintptr(v4 + 32)))) - v19
					}
					*(*float32)(unsafe.Pointer(uintptr(v4 + 32))) = float32(v20)
					sub_548830(v4)
					nox_xxx_unitAddToUpdatable_4DA8D0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))))
				}
			}
		} else if gameFrame() > uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*34))) {
			v23 = int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v3))), 52))))
			*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*34)) = int32(gameFrame() + gameFPS())
			nox_xxx_getTeamByID_418AB0(v23)
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v7)))))), internCStr("objcoll.c:GateLockedMechanism"), 0)
		}
	}
}
func sub_548B60() {
	var (
		v0 int32
		v1 int32
		v2 int32
		v3 int16
		v4 int16
		v5 int16
		v6 int32
		v7 int32
		v8 int32
		v9 float32
	)
	v0 = int32(dword_5d4594_2491552)
	if dword_5d4594_2491552 != 0 {
		for {
			v9 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(v0 + 32)))+*(*float32)(unsafe.Pointer(uintptr(v0 + 32)))) + 0.5)
			v1 = nox_float2int(v9)
			v2 = v1
			if v1 < 0 {
				v2 = -v1
			}
			if v2 > 4 {
				*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = 4
			}
			if float64(*(*float32)(unsafe.Pointer(uintptr(v0 + 32)))) >= -0.0099999998 {
				if float64(*(*float32)(unsafe.Pointer(uintptr(v0 + 32)))) <= 0.0099999998 {
					goto LABEL_15
				}
				if *(*uint32)(unsafe.Pointer(uintptr(v0 + 12))) == (*(*uint32)(unsafe.Pointer(uintptr(v0 + 4)))+12)%32 {
					goto LABEL_15
				}
				*(*uint16)(unsafe.Pointer(uintptr(v0 + 40))) += uint16(int16(v2))
				v5 = int16(*(*uint16)(unsafe.Pointer(uintptr(v0 + 40))))
				if int32(v5) < 256 {
					goto LABEL_15
				}
				v4 = int16(int32(v5) - 256)
			} else {
				if *(*int32)(unsafe.Pointer(uintptr(v0 + 12))) == *(*int32)(unsafe.Pointer(uintptr(v0 + 4)))-12+(func() int32 {
					if *(*int32)(unsafe.Pointer(uintptr(v0 + 4)))-12 < 0 {
						return 0x20
					}
					return 0
				}()) {
					goto LABEL_15
				}
				*(*uint16)(unsafe.Pointer(uintptr(v0 + 40))) -= uint16(int16(v2))
				v3 = int16(*(*uint16)(unsafe.Pointer(uintptr(v0 + 40))))
				if int32(v3) >= 0 {
					goto LABEL_15
				}
				v4 = int16(int32(v3) + 256)
			}
			*(*uint16)(unsafe.Pointer(uintptr(v0 + 40))) = uint16(v4)
		LABEL_15:
			v6 = int32(*(*int16)(unsafe.Pointer(uintptr(v0 + 40)))) * 32 / 256
			*(*uint32)(unsafe.Pointer(uintptr(v0 + 12))) = uint32(v6)
			if v6 < 0 {
				for {
					v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v0 + 12))))
					*(*uint32)(unsafe.Pointer(uintptr(v0 + 12))) = uint32(v7 + 32)
					if v7+32 >= 0 {
						break
					}
				}
			}
			if *(*uint32)(unsafe.Pointer(uintptr(v0 + 12))) >= 32 {
				for {
					v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v0 + 12))) - 32)
					*(*uint32)(unsafe.Pointer(uintptr(v0 + 12))) = uint32(v8)
					if v8 < 32 {
						break
					}
				}
			}
			*(*uint32)(unsafe.Pointer(uintptr(v0 + 28))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(v0 + 32))) = 0
			v0 = int32(*(*uint32)(unsafe.Pointer(uintptr(v0 + 36))))
			if v0 == 0 {
				dword_5d4594_2491552 = 0
				return
			}
		}
	}
	dword_5d4594_2491552 = 0
}
func nox_xxx_script_forcedialog_548CD0(a1p *nox_object_t, a2p *nox_object_t) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v2 int32
		v3 int32
	)
	if a1 != 0 {
		if a2 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
				if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&2 != 0 {
					if (*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) & 0x8020) == 0 {
						v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
						if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 20))))&0x10 != 0 {
							v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 2096))))
							if v3 != -1 && *(*int32)(unsafe.Pointer(uintptr(v2 + 2100))) != -1 {
								nox_script_callByIndex_507310(v3, unsafe.Pointer(uintptr(a1)), unsafe.Pointer(uintptr(a2)))
							}
						}
					}
				}
			}
		}
	}
}
func nox_xxx_scriptDialog_548D30(a1p *nox_object_t, a2 int8) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v2 int32
		v3 int32
		v5 int32
		v6 int32
	)
	v2 = a1
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	nox_xxx_unitUnFreeze_4E7A60((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0)
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 284))))
	if v5 != 0 {
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 748))))
		if *(*int32)(unsafe.Pointer(uintptr(v6 + 2096))) != -1 && *(*int32)(unsafe.Pointer(uintptr(v6 + 2100))) != -1 {
			*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*0)) = 1232
			nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2064)))), unsafe.Pointer(&a1), 2, 0, 1)
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 284))) = 0
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v6 + 2104)))) == 1 {
				*(*uint8)(unsafe.Pointer(uintptr(v6 + 2105))) = uint8(a2)
			} else {
				*(*uint8)(unsafe.Pointer(uintptr(v6 + 2105))) = 0
			}
			nox_script_callByIndex_507310(int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 2100)))), unsafe.Pointer(uintptr(v2)), unsafe.Pointer(uintptr(v5)))
		}
	}
}
func sub_548FE0(a1 int32, a2 *byte) {
	if a1 != 0 && a2 != nil && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&8 != 0 && libc.StrLen(a2) < 0x20 {
		libc.StrCpy((*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692)))+1684))), a2)
	}
}
func nox_xxx_monsterLoadStrikeFn_549040(a1 int32, a2 *byte) int32 {
	var (
		v3 *byte
		v4 int32
		v5 *uint8
	)
	if nox_strcmpi(internCStr("NULL"), a2) != 0 {
		v3 = *(**byte)(memmap.PtrOff(0x587000, 287096))
		v4 = 0
		if *memmap.PtrUint32(0x587000, 287096) != 0 {
			v5 = (*uint8)(memmap.PtrOff(0x587000, 287096))
			for libc.StrCmp(a2, v3) != 0 {
				v3 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*2))))))
				v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 8))
				v4++
				if v3 == nil {
					return 0
				}
			}
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 236))) = *memmap.PtrUint32(0x587000, uint32(v4*8)+287100)
			return 1
		} else {
			return 0
		}
	} else {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 236))) = 0
		return 1
	}
}
func nox_xxx_monsterLoadDieFn_5490E0(a1 int32, a2 *byte) int32 {
	var (
		v3 *byte
		v4 int32
		v5 *uint8
	)
	if nox_strcmpi(internCStr("NULL"), a2) != 0 {
		v3 = *(**byte)(memmap.PtrOff(0x587000, 287280))
		v4 = 0
		if *memmap.PtrUint32(0x587000, 287280) != 0 {
			v5 = (*uint8)(memmap.PtrOff(0x587000, 287280))
			for libc.StrCmp(a2, v3) != 0 {
				v3 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*2))))))
				v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 8))
				v4++
				if v3 == nil {
					return 0
				}
			}
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 228))) = *memmap.PtrUint32(0x587000, uint32(v4*8)+287284)
			return 1
		} else {
			return 0
		}
	} else {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 228))) = 0
		return 1
	}
}
func nox_xxx_monsterLoadDeadFn_549180(a1 int32, a2 *byte) int32 {
	var (
		v3 *byte
		v4 int32
		v5 *uint8
	)
	if nox_strcmpi(internCStr("NULL"), a2) != 0 {
		v3 = *(**byte)(memmap.PtrOff(0x587000, 287192))
		v4 = 0
		if *memmap.PtrUint32(0x587000, 287192) != 0 {
			v5 = (*uint8)(memmap.PtrOff(0x587000, 287192))
			for libc.StrCmp(a2, v3) != 0 {
				v3 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*2))))))
				v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 8))
				v4++
				if v3 == nil {
					return 0
				}
			}
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 232))) = *memmap.PtrUint32(0x587000, uint32(v4*8)+287196)
			return 1
		} else {
			return 0
		}
	} else {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 232))) = 0
		return 1
	}
}
func nox_xxx_strikeOgre_549220(a1 float32) int32 {
	var (
		v1 *float2
		v2 float64
		v4 int32
		v5 float32
	)
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)))
	v1 = (*float2)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 56)))
	v2 = float64(*(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 748))) + 484))) + 112))) + *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 176))))
	*memmap.PtrUint32(0x5D4594, 2491556) = 0
	v5 = float32(v2 + float64(*mem_getFloatPtr(0x587000, 287328)))
	nox_xxx_unitsGetInCircle_517F90(v1, v5, unsafe.Pointer(uintptr(int32(funAddr(sub_549270)))), unsafe.Pointer(uintptr(v4)))
	return int32(*memmap.PtrUint32(0x5D4594, 2491556))
}
func sub_549270(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  int32
		v4  float64
		v5  float64
		v6  *float32
		v7  int32
		v8  *float32
		v9  float32
		v10 float32
		v11 float32
		v12 float4
		v13 float32
	)
	v2 = a2
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	if a2 != a1 {
		v4 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56))) - *(*float32)(unsafe.Pointer(uintptr(a2 + 56))))
		v5 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a2 + 60))))
		v6 = (*float32)(unsafe.Pointer(uintptr(a2 + 56)))
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 484))))
		v12.field_4 = float32(v5)
		v13 = float32(math.Sqrt(v5*float64(v12.field_4)+v4*v4) + 0.0099999998)
		if v13-(*(*float32)(unsafe.Pointer(uintptr(a1 + 176)))+*(*float32)(unsafe.Pointer(uintptr(v2 + 176)))) <= *(*float32)(unsafe.Pointer(uintptr(v7 + 112))) {
			v8 = mem_getFloatPtr(0x587000, uint32(int32(*(*int16)(unsafe.Pointer(uintptr(v2 + 124))))*8)+194136)
			if float64(v12.field_4/v13**(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*1)))+v4/float64(v13)*float64(*v8) > 0.40000001 {
				v9 = *v6
				v10 = *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
				v12.field_4 = *(*float32)(unsafe.Pointer(uintptr(v2 + 60)))
				v12.field_0 = v9
				v11 = *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
				v12.field_8 = v10
				v12.field_C = v11
				if nox_xxx_mapTraceRay_535250(&v12, nil, nil, 5) != 0 {
					(*(*func(int32, int32, int32, uint32, uint32))(unsafe.Pointer(uintptr(a1 + 716))))(a1, v2, v2, *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 484))) + 116))), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 484))) + 124))))
					nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(v2+56))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 484))) + 120))))
					*memmap.PtrUint32(0x5D4594, 2491556) = 1
				}
			}
		}
	}
}
func nox_xxx_strikeMonsterDefault_549380(a1 float32) int32 {
	var (
		v1     float32
		v2     int32
		v3     int32
		v4     float32
		v5     float32
		v6     float32
		result int32
		v8     float4
		v9     float32
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 748))))
	v3 = nox_xxx_monsterPickMeleeTarget_549440(*(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&a1))), 4*0)), 0)
	if v3 != 0 {
		v4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 56)))
		v5 = *(*float32)(unsafe.Pointer(uintptr(v3 + 56)))
		v8.field_4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 60)))
		v8.field_0 = v4
		v6 = *(*float32)(unsafe.Pointer(uintptr(v3 + 60)))
		v8.field_8 = v5
		v8.field_C = v6
		result = nox_xxx_mapTraceRay_535250(&v8, nil, nil, 5)
		if result == 0 {
			return result
		}
		(*(*func(int32, uint32, uint32, uint32, uint32))(unsafe.Pointer(uintptr(v3 + 716))))(v3, *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 116))), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 124))))
		v9 = *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 120)))
		if float64(v9) > 0.0 {
			nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&v1))), 4*0)))+56))), (*nox_object_t)(unsafe.Pointer(uintptr(v3))), v9)
		}
	}
	return 1
}
func nox_xxx_monsterPickMeleeTarget_549440(a3 int32, a2 int32) int32 {
	var (
		v2 int32
		v3 float64
		v4 float64
		v5 int32
		a1 float4
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a3 + 748))))
	v3 = float64(*(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 112))) + *(*float32)(unsafe.Pointer(uintptr(a3 + 176))) + *mem_getFloatPtr(0x587000, 287328))
	a1.field_0 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a3 + 56)))) - v3)
	a1.field_4 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a3 + 60)))) - v3)
	a1.field_8 = float32(v3 + float64(*(*float32)(unsafe.Pointer(uintptr(a3 + 56)))))
	v4 = v3 + float64(*(*float32)(unsafe.Pointer(uintptr(a3 + 60))))
	*memmap.PtrUint32(0x5D4594, 2491568) = uint32(a2)
	a1.field_C = float32(v4)
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 112))))
	*memmap.PtrUint32(0x5D4594, 2491564) = 0
	*memmap.PtrUint32(0x5D4594, 2491572) = uint32(v5)
	nox_xxx_getUnitsInRect_517C10(&a1, unsafe.Pointer(funAddr(sub_5494C0)), unsafe.Pointer(uintptr(a3)))
	return int32(*memmap.PtrUint32(0x5D4594, 2491564))
}
func sub_5494C0(a1 *float32, a2 int32) {
	var (
		v2 int32
		v3 int32
		v4 float64
		v5 *float32
		v6 float64
		v7 float32
		v8 int32
	)
	v2 = a2
	if (*float32)(unsafe.Pointer(uintptr(a2))) != a1 && ((int32(uint8(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*4))))&0x11) == 0 || int32(uint8(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*2))))&6 != 0) {
		if int32(uint8(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*2))))&6 != 0 || (func() int32 {
			v3 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*139))))
			return v3
		}()) != 0 && int32(*(*uint16)(unsafe.Pointer(uintptr(v3 + 4)))) != 0 {
			if nox_xxx_unitIsEnemyTo_5330C0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))) != 0 || *memmap.PtrUint32(0x5D4594, 2491568) != 0 {
				v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*14)) - *(*float32)(unsafe.Pointer(uintptr(a2 + 56))))
				v7 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*15)) - *(*float32)(unsafe.Pointer(uintptr(a2 + 60)))
				v5 = mem_getFloatPtr(0x587000, uint32(int32(*(*int16)(unsafe.Pointer(uintptr(a2 + 124))))*8)+194136)
				*(*float32)(unsafe.Pointer(&v8)) = float32(math.Sqrt(float64(v7*v7)+v4*v4) + 0.001)
				if float64(v7 / *(*float32)(unsafe.Pointer(&v8)) * *(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*1)))+v4/float64(*(*float32)(unsafe.Pointer(&v8)))*float64(*v5) > 0.5 {
					v6 = float64(*(*float32)(unsafe.Pointer(&v8)) - (*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*44)) + *(*float32)(unsafe.Pointer(uintptr(v2 + 176)))))
					if v6 < float64(*mem_getFloatPtr(0x5D4594, 2491572)) {
						*mem_getFloatPtr(0x5D4594, 2491572) = float32(v6)
						*memmap.PtrUint32(0x5D4594, 2491564) = uint32(uintptr(unsafe.Pointer(a1)))
					}
				}
			}
		}
	}
}
func nox_xxx_strikeScorpion_5495B0(a1 float32) int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		v4     float32
		v5     float32
		v6     float32
		result int32
		v8     float4
		v9     float32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 748))))
	v3 = nox_xxx_monsterPickMeleeTarget_549440(*(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&a1))), 4*0)), 0)
	if v3 != 0 {
		v4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 56)))
		v5 = *(*float32)(unsafe.Pointer(uintptr(v3 + 56)))
		v8.field_4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 60)))
		v8.field_0 = v4
		v6 = *(*float32)(unsafe.Pointer(uintptr(v3 + 60)))
		v8.field_8 = v5
		v8.field_C = v6
		result = nox_xxx_mapTraceRay_535250(&v8, nil, nil, 5)
		if result == 0 {
			return result
		}
		(*(*func(int32, uint32, uint32, uint32, uint32))(unsafe.Pointer(uintptr(v3 + 716))))(v3, *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 116))), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 124))))
		v9 = *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 120)))
		if float64(v9) > 0.0 {
			nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(v1+56))), (*nox_object_t)(unsafe.Pointer(uintptr(v3))), v9)
		}
		if sub_549690(v1, v3) != 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("aifunc.c:PoisonedByScorpion"), 0)
		}
	}
	return 1
}
func sub_549690(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		v3     int32
		result int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 484))))
	result = 0
	if *(*uint32)(unsafe.Pointer(uintptr(v2 + 136))) != 0 {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 484))))
		if nox_common_randomInt_415FA0(1, 100) <= *(*int32)(unsafe.Pointer(uintptr(v2 + 136))) {
			if nox_xxx_activatePoison_4EE7E0(a2, int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 140)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 144))))) != 0 {
				result = 1
			}
		}
	}
	return result
}
func nox_xxx_strikeVileZombie_549700(a1 float32) int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		v4     float32
		v5     float32
		v6     float32
		result int32
		v8     float4
		v9     float32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 748))))
	v3 = nox_xxx_monsterPickMeleeTarget_549440(*(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&a1))), 4*0)), 0)
	if v3 != 0 {
		v4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 56)))
		v5 = *(*float32)(unsafe.Pointer(uintptr(v3 + 56)))
		v8.field_4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 60)))
		v8.field_0 = v4
		v6 = *(*float32)(unsafe.Pointer(uintptr(v3 + 60)))
		v8.field_8 = v5
		v8.field_C = v6
		result = nox_xxx_mapTraceRay_535250(&v8, nil, nil, 5)
		if result == 0 {
			return result
		}
		(*(*func(int32, uint32, uint32, uint32, uint32))(unsafe.Pointer(uintptr(v3 + 716))))(v3, *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 116))), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 124))))
		v9 = *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 120)))
		if float64(v9) > 0.0 {
			nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(v1+56))), (*nox_object_t)(unsafe.Pointer(uintptr(v3))), v9)
		}
		if sub_549690(v1, v3) != 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("aifunc.c:PoisonedByZombie"), 0)
		}
	}
	return 1
}
func nox_xxx_strikeStoneGolem_5497E0(a1 float32) int32 {
	*memmap.PtrUint32(0x5D4594, 2491560) = 0
	return nox_xxx_sendEquakeAfterGolem_549800(a1)
}
func nox_xxx_sendEquakeAfterGolem_549800(a1 float32) int32 {
	var (
		v1 *float2
		v2 float64
		v4 int32
		v5 float32
	)
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)))
	v1 = (*float2)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 56)))
	v2 = float64(*(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 748))) + 484))) + 112))) + *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 176))))
	*memmap.PtrUint32(0x5D4594, 2491576) = 0
	v5 = float32(v2 + float64(*mem_getFloatPtr(0x587000, 287328)))
	nox_xxx_unitsGetInCircle_517F90(v1, v5, unsafe.Pointer(uintptr(int32(funAddr(nox_xxx_monsterAttackAreaDamage_549860)))), unsafe.Pointer(uintptr(v4)))
	nox_xxx_earthquakeSend_4D9110(&v1.field_0, 30)
	return int32(*memmap.PtrUint32(0x5D4594, 2491576))
}
func nox_xxx_monsterAttackAreaDamage_549860(a1 int32, a2 float32) {
	var (
		v2 int32
		v3 bool
		v4 float32
		v5 float32
		v6 float32
		v7 float4
		v8 int32
		v9 float32
	)
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a2))), 4*0)))
	v3 = (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a2))), 4*0))) == uint32(a1)
	v8 = int32(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a2))), 4*0))) + 748))))
	if !v3 {
		if nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(v2+56))), int32(*(*int16)(unsafe.Pointer(uintptr(v2 + 124)))), (*float2)(unsafe.Pointer(uintptr(a1+56))))&1 != 0 {
			if nox_xxx_calcDistance_4E6C00((*nox_object_t)(unsafe.Pointer(uintptr(v2))), (*nox_object_t)(unsafe.Pointer(uintptr(a1)))) <= float64(*(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v8 + 484))) + 112)))) {
				v4 = *(*float32)(unsafe.Pointer(uintptr(v2 + 56)))
				v5 = *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
				v7.field_4 = *(*float32)(unsafe.Pointer(uintptr(v2 + 60)))
				v7.field_0 = v4
				v6 = *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
				v7.field_8 = v5
				v7.field_C = v6
				if nox_xxx_mapTraceRay_535250(&v7, nil, nil, 5) != 0 {
					(*(*func(int32, int32, int32, uint32, uint32))(unsafe.Pointer(uintptr(a1 + 716))))(a1, v2, v2, *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v8 + 484))) + 116))), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v8 + 484))) + 124))))
					if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&6 != 0 {
						*memmap.PtrUint32(0x5D4594, 2491576) = 1
					}
					v9 = *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v8 + 484))) + 120)))
					if float64(v9) > 0.0 {
						nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(v2+56))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), v9)
					}
				}
			}
		}
	}
}
func nox_xxx_strikeMechGolem_549960(a1 float32) int32 {
	*memmap.PtrUint32(0x5D4594, 2491560) = 1
	return nox_xxx_sendEquakeAfterGolem_549800(a1)
}
func nox_xxx_strikeWasp_549980(a1 float32) int32 {
	var (
		v1 float32
		v2 int32
		v3 int32
		v4 float32
		v5 float32
		v6 float32
		v8 float4
		v9 float32
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 748))))
	v3 = nox_xxx_monsterPickMeleeTarget_549440(*(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&a1))), 4*0)), 0)
	if v3 == 0 {
		return 0
	}
	v4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 56)))
	v5 = *(*float32)(unsafe.Pointer(uintptr(v3 + 56)))
	v8.field_4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 60)))
	v8.field_0 = v4
	v6 = *(*float32)(unsafe.Pointer(uintptr(v3 + 60)))
	v8.field_8 = v5
	v8.field_C = v6
	if nox_xxx_mapTraceRay_535250(&v8, nil, nil, 5) == 0 {
		return 0
	}
	(*(*func(int32, uint32, uint32, uint32, uint32))(unsafe.Pointer(uintptr(v3 + 716))))(v3, *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 116))), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 124))))
	if sub_549690(*(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&a1))), 4*0)), v3) != 0 {
		nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("aifunc.c:PoisonedByWasp"), 0)
	}
	v9 = *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 120)))
	if float64(v9) > 0.0 {
		nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&v1))), 4*0)))+56))), (*nox_object_t)(unsafe.Pointer(uintptr(v3))), v9)
	}
	return 1
}
func nox_xxx_strikeGhost_549A60(a1 float32) int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		v4     float32
		v5     float32
		v6     float32
		result int32
		v8     *int32
		v9     *int32
		v10    *int32
		v11    float4
		v12    float32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 748))))
	v3 = nox_xxx_monsterPickMeleeTarget_549440(*(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&a1))), 4*0)), 0)
	if v3 != 0 {
		v4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 56)))
		v5 = *(*float32)(unsafe.Pointer(uintptr(v3 + 56)))
		v11.field_4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 60)))
		v11.field_0 = v4
		v6 = *(*float32)(unsafe.Pointer(uintptr(v3 + 60)))
		v11.field_8 = v5
		v11.field_C = v6
		result = nox_xxx_mapTraceRay_535250(&v11, nil, nil, 5)
		if result == 0 {
			return result
		}
		(*(*func(int32, uint32, uint32, uint32, uint32))(unsafe.Pointer(uintptr(v3 + 716))))(v3, *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 116))), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 124))))
		v12 = *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 120)))
		if float64(v12) > 0.0 {
			nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(v1+56))), (*nox_object_t)(unsafe.Pointer(uintptr(v3))), v12)
		}
		nox_xxx_buffApplyTo_4FF380((*nox_object_t)(unsafe.Pointer(uintptr(v3))), 5, int16(int32(uint16(gameFPS()))*2), 3)
		v8 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 25, internCStr(__FILE__), __LINE__))
		if v8 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v8), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 56))))
			*(*int32)(unsafe.Add(unsafe.Pointer(v8), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 60))))
		}
		v9 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 41, internCStr(__FILE__), __LINE__))
		if v9 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v9), 4*1)) = int32(gameFrame() + uint32(nox_common_randomInt_415FA0(int32(gameFPS()*2), int32(gameFPS()*4))))
		}
		v10 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 24, internCStr(__FILE__), __LINE__))
		if v10 != nil {
			*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 56))))
			*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 60))))
			*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*3)) = 0
		}
	}
	return 1
}
func nox_xxx_strikeBomber_549BB0() int32 {
	return 1
}
func nox_xxx_strikeSpider_549BC0(a1 float32) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 float32
		v5 float32
		v6 float32
		v8 float4
		v9 float32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 748))))
	v3 = nox_xxx_monsterPickMeleeTarget_549440(*(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&a1))), 4*0)), 0)
	if v3 == 0 {
		return 0
	}
	v4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 56)))
	v5 = *(*float32)(unsafe.Pointer(uintptr(v3 + 56)))
	v8.field_4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 60)))
	v8.field_0 = v4
	v6 = *(*float32)(unsafe.Pointer(uintptr(v3 + 60)))
	v8.field_8 = v5
	v8.field_C = v6
	if nox_xxx_mapTraceRay_535250(&v8, nil, nil, 5) == 0 {
		return 0
	}
	(*(*func(int32, uint32, uint32, uint32, uint32))(unsafe.Pointer(uintptr(v3 + 716))))(v3, *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 116))), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 124))))
	v9 = *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 120)))
	if float64(v9) > 0.0 {
		nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(v1+56))), (*nox_object_t)(unsafe.Pointer(uintptr(v3))), v9)
	}
	if sub_549690(v1, v3) != 0 {
		nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("aifunc.c:Poisoned"), 0)
	}
	return 1
}
func nox_xxx_strikeSpittingSpider_549CA0(a1 float32) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 float32
		v5 float32
		v6 float32
		v8 float4
		v9 float32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 748))))
	v3 = nox_xxx_monsterPickMeleeTarget_549440(*(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&a1))), 4*0)), 0)
	if v3 == 0 {
		return 0
	}
	v4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 56)))
	v5 = *(*float32)(unsafe.Pointer(uintptr(v3 + 56)))
	v8.field_4 = *(*float32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 60)))
	v8.field_0 = v4
	v6 = *(*float32)(unsafe.Pointer(uintptr(v3 + 60)))
	v8.field_8 = v5
	v8.field_C = v6
	if nox_xxx_mapTraceRay_535250(&v8, nil, nil, 5) == 0 {
		return 0
	}
	(*(*func(int32, uint32, uint32, uint32, uint32))(unsafe.Pointer(uintptr(v3 + 716))))(v3, *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 116))), *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 124))))
	v9 = *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 484))) + 120)))
	if float64(v9) > 0.0 {
		nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(v1+56))), (*nox_object_t)(unsafe.Pointer(uintptr(v3))), v9)
	}
	if sub_549690(v1, v3) != 0 {
		nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("aifunc.c:Poisoned"), 0)
	}
	return 1
}
func sub_549D80(a1 int32) int32 {
	var v1 int32
	if nox_common_gameFlags_check_40A5C0(2048) {
		v1 = 30
	} else {
		v1 = 96
	}
	nox_xxx_mapPushUnitsAround_52E040(unsafe.Pointer(uintptr(a1+56)), 96.0, 10.0, 100.0, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	nox_xxx_mapDamageUnitsAround_4E25B0((*float32)(unsafe.Pointer(uintptr(a1+56))), 96.0, 10.0, v1, 7, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), nil)
	nox_xxx_netSparkExplosionFx_5231B0((*float32)(unsafe.Pointer(uintptr(a1+56))), math.MinInt8)
	nox_xxx_aud_501960(42, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	return 1
}
func sub_549E00(a1 int32) int32 {
	nox_xxx_mapPushUnitsAround_52E040(unsafe.Pointer(uintptr(a1+56)), 150.0, 10.0, 150.0, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	nox_xxx_mapDamageUnitsAround_4E25B0((*float32)(unsafe.Pointer(uintptr(a1+56))), 150.0, 10.0, 148, 7, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), nil)
	nox_xxx_netSparkExplosionFx_5231B0((*float32)(unsafe.Pointer(uintptr(a1+56))), -1)
	nox_xxx_aud_501960(42, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	return 1
}
func sub_549E70(a1 int32) int32 {
	nox_xxx_netSendPointFx_522FF0(-127, (*float2)(unsafe.Pointer(uintptr(a1+56))))
	return 1
}
func sub_549E90(a1 int32) int32 {
	var (
		v1 **byte
		v2 *uint8
		v3 *float32
		v4 float64
		v5 int32
		v6 int32
		v7 int32
		v9 float32
		a3 float2
	)
	nox_xxx_aud_501960(494, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	nox_xxx_netSendPointFx_522FF0(-118, (*float2)(unsafe.Pointer(uintptr(a1+56))))
	if *memmap.PtrUint32(0x587000, 287976) != 0 {
		v1 = (**byte)(memmap.PtrOff(0x587000, 287976))
		v2 = (*uint8)(memmap.PtrOff(0x587000, 287976))
		for {
			v3 = (*float32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(*v1)))
			if v3 == nil {
				break
			}
			sub_4ED970(30.0, (*float2)(unsafe.Pointer(uintptr(a1+56))), &a3)
			nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), nil, a3.field_0, a3.field_4)
			v9 = float32(nox_common_randomFloat_416030(10.0, 70.0))
			nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), v9)
			v4 = nox_common_randomFloat_416030(-2.0, 0.0)
			v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*4))))
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*27)) = float32(v4)
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*29)) = 2.0
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*4))) = uint32(v5) | 0x800000
			v6 = nox_common_randomInt_415FA0(10, 20)
			nox_xxx_unitSetDecayTime_511660((*nox_object_t)(unsafe.Pointer(v3)), int32(gameFPS()*uint32(v6)))
			v7 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*1))))
			v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 4))
			v1 = (**byte)(unsafe.Pointer(v2))
			if v7 == 0 {
				break
			}
		}
	}
	return 1
}
func sub_549FA0(a1 int32) int32 {
	var (
		v1  *float2
		v2  int32
		v3  int32
		v4  *float32
		v5  float64
		v6  int32
		v8  float32
		v9  float32
		a3  float2
		v11 int32
	)
	nox_xxx_aud_501960(487, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	v1 = (*float2)(unsafe.Pointer(uintptr(a1 + 56)))
	nox_xxx_netSendPointFx_522FF0(-118, (*float2)(unsafe.Pointer(uintptr(a1+56))))
	if nox_common_gameFlags_check_40A5C0(2048) {
		v11 = nox_common_randomInt_415FA0(20, 30)
	} else {
		v11 = 6
	}
	v2 = 0
	if v11 > 0 {
		v3 = int32(dword_5d4594_2491580)
		for {
			v4 = (*float32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(*(**byte)(memmap.PtrOff(0x587000, uint32(v3*4)+288240)))))
			if v4 == nil {
				break
			}
			sub_4ED970(30.0, v1, &a3)
			nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), nil, a3.field_0, a3.field_4)
			v8 = float32(nox_common_randomFloat_416030(10.0, 70.0))
			nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), v8)
			*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*27)) = float32(nox_common_randomFloat_416030(-2.0, 0.0))
			v5 = float64(*memmap.PtrUint8(0x587000, dword_5d4594_2491580+287332))
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*4))) |= 0x800000
			*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*29)) = float32(v5)
			v9 = float32(nox_common_randomFloat_416030(5.0, 20.0))
			nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), v9)
			if nox_common_gameFlags_check_40A5C0(2048) {
				v6 = nox_common_randomInt_415FA0(10, 20)
			} else {
				v6 = nox_common_randomInt_415FA0(5, 10)
			}
			nox_xxx_unitSetDecayTime_511660((*nox_object_t)(unsafe.Pointer(v4)), int32(gameFPS()*uint32(v6)))
			v3 = int32((dword_5d4594_2491580 + 1) % *memmap.PtrUint32(0x587000, 287344))
			v2++
			dword_5d4594_2491580 = (dword_5d4594_2491580 + 1) % *memmap.PtrUint32(0x587000, 287344)
			if v2 >= v11 {
				break
			}
		}
	}
	return 1
}
func sub_54A250(a1 int32) int32 {
	nox_xxx_netSendPointFx_522FF0(-127, (*float2)(unsafe.Pointer(uintptr(a1+56))))
	return 1
}
func nox_xxx_monsterDeadTroll_54A270(a1 int32) int32 {
	var (
		v1 int32
		v2 *uint32
		v3 *uint32
	)
	_ = v3
	var v5 float32
	v1 = int32(*memmap.PtrUint32(0x5D4594, 2491584))
	if *memmap.PtrUint32(0x5D4594, 2491584) == 0 {
		v1 = nox_xxx_getNameId_4E3AA0(internCStr("SmallToxicCloud"))
		*memmap.PtrUint32(0x5D4594, 2491584) = uint32(v1)
	}
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(v1)))
	if v2 != nil {
		v3 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*187)))))
		nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), *(*float32)(unsafe.Pointer(uintptr(a1 + 56))), *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
		nox_xxx_aud_501960(644, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		v5 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("SmallToxicCloudLifetime")) * float64(int32(gameFPS())))
		*v3 = uint32(nox_float2int(v5))
	}
	return 1
}
func sub_54A310(a1 int32) int32 {
	var v1 int32
	v1 = nox_common_randomInt_415FA0(0, 100)
	sub_54A4C0(a1)
	if v1 > 20 {
		if v1 <= 50 {
			sub_54A390(a1, internCStr("Sword"), internCStr("WeaponPower1"), internCStr("Material2"), nil, nil, 0)
			return 1
		}
		sub_54A390(a1, internCStr("WoodenShield"), nil, internCStr("Material2"), nil, nil, 0)
	}
	return 1
}
func sub_54A390(a1 int32, a2 *byte, a3 *byte, a4 *byte, a5 *byte, a6 *byte, a7 int32) {
	var (
		result int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		a3a    float2
		v14    [20]uint8
	)
	if nox_common_gameFlags_check_40A5C0(2048) {
		result = int32(uintptr(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(a2))))
		v8 = result
		if result != 0 {
			sub_4ED970(50.0, (*float2)(unsafe.Pointer(uintptr(a1+56))), &a3a)
			nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(v8))), nil, a3a.field_0, a3a.field_4)
			if *(*uint32)(unsafe.Pointer(uintptr(v8 + 8)))&0x13001000 != 0 && (a3 != nil || a4 != nil || a5 != nil || a6 != nil) {
				v9 = nox_xxx_modifGetIdByName_413290(a3)
				*(*uint32)(unsafe.Pointer(&v14[0])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v9)))
				v10 = nox_xxx_modifGetIdByName_413290(a4)
				*(*uint32)(unsafe.Pointer(&v14[4])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v10)))
				v11 = nox_xxx_modifGetIdByName_413290(a5)
				*(*uint32)(unsafe.Pointer(&v14[8])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v11)))
				v12 = nox_xxx_modifGetIdByName_413290(a6)
				*(*uint32)(unsafe.Pointer(&v14[12])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v12)))
				nox_xxx_modifSetItemAttrs_4E4990((*nox_object_t)(unsafe.Pointer(uintptr(v8))), (*int32)(unsafe.Pointer(&v14[0])))
			}
			if a7 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v8 + 8)))&0x1000000 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v8 + 12))))&0x82 != 0 {
				*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v8 + 736))) + 1))) = uint8(int8(a7))
			}
			result = int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + 8))))
			if uint32(result)&0x2000000 != 0 {
				sub_53EAE0(v8)
			} else if uint32(result)&0x1001000 != 0 {
				sub_53AAB0(v8)
			}
		}
	}
}
func sub_54A4C0(a1 int32) {
	var (
		v1  *float2
		v2  *float32
		v3  float64
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  *float32
		v10 float64
		v11 int32
		v12 int32
		v13 bool
		v15 float32
		v16 float32
		v17 float32
		v18 int32
		a3  float2
		v20 int32
	)
	nox_xxx_aud_501960(356, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	v1 = (*float2)(unsafe.Pointer(uintptr(a1 + 56)))
	nox_xxx_netSendPointFx_522FF0(-118, (*float2)(unsafe.Pointer(uintptr(a1+56))))
	v2 = (*float32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("Skull"))))
	if v2 != nil {
		sub_4ED970(20.0, v1, &a3)
		nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), nil, a3.field_0, a3.field_4)
		nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), 40.0)
		v3 = nox_common_randomFloat_416030(-2.0, 0.0)
		v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*4))))
		*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*27)) = float32(v3)
		*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*29)) = 4.0
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*4))) = uint32(v4) | 0x800000
		v15 = float32(nox_common_randomFloat_416030(5.0, 25.0))
		nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), v15)
		if nox_common_gameFlags_check_40A5C0(2048) {
			v5 = nox_common_randomInt_415FA0(10, 20)
			nox_xxx_unitSetDecayTime_511660((*nox_object_t)(unsafe.Pointer(v2)), int32(gameFPS()*uint32(v5)))
			v6 = nox_common_randomInt_415FA0(10, 20)
		} else {
			v7 = nox_common_randomInt_415FA0(2, 5)
			nox_xxx_unitSetDecayTime_511660((*nox_object_t)(unsafe.Pointer(v2)), int32(gameFPS()*uint32(v7)))
			v6 = nox_common_randomInt_415FA0(5, 10)
		}
		v20 = v6
		v18 = 0
		if v6 > 0 {
			v8 = int32(dword_5d4594_2491588)
			for {
				v9 = (*float32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(*(**byte)(memmap.PtrOff(0x587000, uint32(v8*4)+288868)))))
				if v9 == nil {
					break
				}
				sub_4ED970(20.0, v1, &a3)
				nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v9)))))), nil, a3.field_0, a3.field_4)
				v16 = float32(nox_common_randomFloat_416030(10.0, 35.0))
				nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v9)))))), v16)
				v10 = nox_common_randomFloat_416030(-2.0, 0.0)
				v11 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v9))), 4*4))))
				*(*float32)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(float32(0))*27)) = float32(v10)
				*(*float32)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(float32(0))*29)) = 4.0
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v9))), 4*4))) = uint32(v11) | 0x800000
				v17 = float32(nox_common_randomFloat_416030(5.0, 25.0))
				nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v9)))))), v17)
				if nox_common_gameFlags_check_40A5C0(2048) {
					v12 = nox_common_randomInt_415FA0(10, 20)
				} else {
					v12 = nox_common_randomInt_415FA0(2, 5)
				}
				nox_xxx_unitSetDecayTime_511660((*nox_object_t)(unsafe.Pointer(v9)), int32(gameFPS()*uint32(v12)))
				v8 = int32((dword_5d4594_2491588 + 1) % *memmap.PtrUint32(0x587000, 287348))
				v13 = func() int32 {
					p := &v18
					*p++
					return *p
				}() < v20
				dword_5d4594_2491588 = (dword_5d4594_2491588 + 1) % *memmap.PtrUint32(0x587000, 287348)
				if !v13 {
					break
				}
			}
		}
	}
}
func sub_54A750(a1 int32) int32 {
	var v1 int32
	v1 = nox_common_randomInt_415FA0(0, 100)
	sub_54A4C0(a1)
	if v1 > 20 {
		if v1 <= 50 {
			sub_54A390(a1, internCStr("Sword"), internCStr("WeaponPower1"), internCStr("Material2"), nil, nil, 0)
			return 1
		}
		sub_54A390(a1, internCStr("SteelShield"), nil, internCStr("Material2"), nil, nil, 0)
	}
	return 1
}
func sub_54A7D0(a1 int32) int32 {
	var v1 int32
	v1 = nox_common_randomInt_415FA0(0, 100)
	if v1 > 20 {
		if v1 <= 50 {
			sub_54A390(a1, internCStr("Sword"), internCStr("WeaponPower1"), internCStr("Material1"), nil, nil, 0)
			return 1
		}
		sub_54A390(a1, internCStr("WoodenShield"), nil, internCStr("Material1"), nil, nil, 0)
	}
	return 1
}
func sub_54A850(a1 int32) int32 {
	if nox_common_randomInt_415FA0(0, 100) > 25 {
		sub_54A390(a1, internCStr("StaffWooden"), internCStr("WeaponPower1"), nil, nil, nil, 0)
	}
	return 1
}
func sub_54A890(a1 int32) int32 {
	var v1 int32
	v1 = nox_common_randomInt_415FA0(0, 100)
	if v1 > 20 {
		if v1 <= 50 {
			sub_54A390(a1, internCStr("Bow"), nil, nil, nil, nil, 0)
			return 1
		}
		sub_54A390(a1, internCStr("Quiver"), nil, nil, nil, nil, 0)
	}
	return 1
}
func sub_54A900(a1 int32) int32 {
	if nox_common_randomInt_415FA0(0, 100) > 25 {
		sub_54A390(a1, internCStr("OgreAxe"), internCStr("WeaponPower1"), internCStr("Material2"), nil, nil, 0)
	}
	return 1
}
func sub_54A950(a1 int32) int32 {
	if nox_common_randomInt_415FA0(0, 100) > 25 {
		sub_54A390(a1, internCStr("FanChakram"), nil, nil, nil, nil, 5)
	}
	return 1
}
func sub_54A990(a1 *float2, a2 float32, a3 int32, a4 *float2) float64 {
	var (
		v4     int32
		v5     *float2
		result float64
		v7     int8
		v8     int32
		v9     float64
		v10    float64
		v11    float64
		v12    float64
		v13    float64
		v14    float64
		v15    int8
		v16    float32
		v17    float32
		v18    float32
		v19    float32
		v20    float32
		v21    float32
		v22    float32
		v23    float32
		v24    float32
		v25    float32
		v26    float32
		v27    float32
		v28    float32
		v29    float32
		v30    float32
		v31    float32
		v32    float32
	)
	v4 = a3
	v5 = a1
	result = -1.0
	v15 = 0
	v21 = *(*float32)(unsafe.Pointer(uintptr(a3 + 192))) + *(*float32)(unsafe.Pointer(uintptr(a3 + 64)))
	v22 = *(*float32)(unsafe.Pointer(uintptr(a3 + 196))) + *(*float32)(unsafe.Pointer(uintptr(a3 + 68)))
	v25 = *(*float32)(unsafe.Pointer(uintptr(a3 + 200))) + *(*float32)(unsafe.Pointer(uintptr(a3 + 64)))
	v26 = *(*float32)(unsafe.Pointer(uintptr(a3 + 204))) + *(*float32)(unsafe.Pointer(uintptr(a3 + 68)))
	v23 = *(*float32)(unsafe.Pointer(uintptr(a3 + 208))) + *(*float32)(unsafe.Pointer(uintptr(a3 + 64)))
	v24 = *(*float32)(unsafe.Pointer(uintptr(a3 + 212))) + *(*float32)(unsafe.Pointer(uintptr(a3 + 68)))
	v27 = *(*float32)(unsafe.Pointer(uintptr(a3 + 216))) + *(*float32)(unsafe.Pointer(uintptr(a3 + 64)))
	v28 = *(*float32)(unsafe.Pointer(uintptr(a3 + 220))) + *(*float32)(unsafe.Pointer(uintptr(a3 + 68)))
	v31 = float32(float64(v22-v21+a1.field_0-a1.field_4) * 0.70709997)
	v29 = float32(float64(v26-v25+a1.field_0-a1.field_4) * 0.70709997)
	v17 = float32(float64(v24+v23-v5.field_0-v5.field_4) * 0.70709997)
	v18 = float32(float64(v22+v21-v5.field_0-v5.field_4) * 0.70709997)
	if float64(v31) <= 0.0 {
		if float64(v29) < 0.0 {
			v15 = 2
		}
	} else {
		v15 = 1
	}
	if float64(v17) >= 0.0 {
		if float64(v18) <= 0.0 {
			goto LABEL_10
		}
		v7 = int8(int32(v15) | 4)
	} else {
		v7 = int8(int32(v15) | 8)
	}
	v15 = v7
LABEL_10:
	switch v15 {
	case 0:
		v19 = v5.field_0 - *(*float32)(unsafe.Pointer(uintptr(v4 + 64)))
		v20 = v5.field_4 - *(*float32)(unsafe.Pointer(uintptr(v4 + 68)))
		if float64(v19) == 0.0 && float64(v20) == 0.0 {
			v8 = nox_common_randomInt_415FA0(0, 3)
			v19 = *mem_getFloatPtr(0x587000, uint32(v8*8)+289928)
			v20 = *mem_getFloatPtr(0x587000, uint32(v8*8)+289932)
		}
		result = math.Sqrt(float64(v20*v20 + v19*v19))
		if result == 0.0 {
			result = 0.1
		}
		a4.field_0 = float32(float64(v19) / result)
		a4.field_4 = float32(float64(v20) / result)
		return result
	case 1:
		result = float64(a2 - v31)
		a4.field_0 = 0.70709997
		a4.field_4 = -0.70709997
		return result
	case 2:
		result = float64(a2 - (-v29))
		a4.field_0 = -0.70709997
		a4.field_4 = 0.70709997
		return result
	case 4:
		result = float64(a2 - v18)
		a4.field_0 = -0.70709997
		a4.field_4 = -0.70709997
		return result
	case 5:
		v30 = v5.field_0 - v21
		v9 = float64(v5.field_4 - v22)
		v16 = float32(v9)
		v10 = math.Sqrt(v9*float64(v16) + float64(v30*v30))
		v32 = float32(v10)
		if v10 == 0.0 {
			v32 = 0.1
		}
		result = float64(a2 - v32)
		if result >= 0.0 {
			a4.field_0 = v30 / v32
			a4.field_4 = v16 / v32
		}
		return result
	case 6:
		v30 = v5.field_0 - v25
		v13 = float64(v5.field_4 - v26)
		v16 = float32(v13)
		v14 = math.Sqrt(v13*float64(v16) + float64(v30*v30))
		v32 = float32(v14)
		if v14 == 0.0 {
			v32 = 0.1
		}
		result = float64(a2 - v32)
		if result >= 0.0 {
			a4.field_0 = v30 / v32
			a4.field_4 = v16 / v32
		}
		return result
	case 8:
		result = float64(a2 - (-v17))
		a4.field_0 = 0.70709997
		a4.field_4 = 0.70709997
		return result
	case 9:
		v30 = v5.field_0 - v23
		v9 = float64(v5.field_4 - v24)
		v16 = float32(v9)
		v10 = math.Sqrt(v9*float64(v16) + float64(v30*v30))
		v32 = float32(v10)
		if v10 == 0.0 {
			v32 = 0.1
		}
		result = float64(a2 - v32)
		if result >= 0.0 {
			a4.field_0 = v30 / v32
			a4.field_4 = v16 / v32
		}
		return result
	case 0xA:
		v30 = v5.field_0 - v27
		v11 = float64(v5.field_4 - v28)
		v16 = float32(v11)
		v12 = math.Sqrt(v11*float64(v16) + float64(v30*v30))
		v32 = float32(v12)
		if v12 == 0.0 {
			v32 = 0.1
		}
		result = float64(a2 - v32)
		if result >= 0.0 {
			a4.field_0 = v30 / v32
			a4.field_4 = v16 / v32
		}
		return result
	default:
		return result
	}
}
func sub_54AD50(a1 int32, a2 int32, a3 int32) {
	var (
		v3  int32
		v4  int32
		v5  int32
		v6  float64
		v7  float32
		v8  float32
		v9  float32
		v10 int32
		v11 int32
		v12 float64
		v13 float64
		v14 float64
		v15 float64
		v16 float64
		v17 float32
		v18 float32
		v19 float32
		a4  float2
		a1a float4
		v22 int32
		v23 int32
		a3c float32
		a3a int32
		a3b int32
		v27 float32
	)
	v3 = a1
	v4 = a2
	v5 = 1
	v6 = sub_54A990((*float2)(unsafe.Pointer(uintptr(a1+64))), *(*float32)(unsafe.Pointer(uintptr(a1 + 176))), a2, &a4)
	if v6 >= 0.0 {
		if (*(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x2204) == 0 || (*(*uint32)(unsafe.Pointer(uintptr(a2 + 8)))&0x2204) == 0 || (func() int32 {
			v7 = *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
			v8 = *(*float32)(unsafe.Pointer(uintptr(a2 + 56)))
			a1a.field_4 = *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
			a1a.field_0 = v7
			v9 = *(*float32)(unsafe.Pointer(uintptr(a2 + 60)))
			a1a.field_8 = v8
			a1a.field_C = v9
			return nox_xxx_mapTraceRay_535250(&a1a, nil, nil, 0)
		}()) != 0 {
			nox_xxx_collSysAddCollision_548630(a1, uint32(a2), &a4)
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16))))&8) == 8 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 16))))&8) == 8 {
				v5 = 0
			}
			v10 = a3
			if a3 != 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&6) == 0 || (func() bool {
				v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
				return (v11 & 0x2000) == 0
			}()) {
				if v5 != 0 {
					a3c = float32(v6)
					v12 = float64(*(*float32)(unsafe.Pointer(&dword_587000_292488)) * a3c)
					a1a.field_4 = a4.field_0
					*(*float32)(unsafe.Pointer(&v22)) = float32(float64(a4.field_0) * v12)
					*(*float32)(unsafe.Pointer(&a3a)) = float32(float64(a4.field_4) * v12)
					v13 = float64(*(*float32)(unsafe.Pointer(uintptr(v3 + 80))) - *(*float32)(unsafe.Pointer(uintptr(v4 + 80))))
					v14 = float64(*(*float32)(unsafe.Pointer(uintptr(v3 + 84))) - *(*float32)(unsafe.Pointer(uintptr(v4 + 84))))
					a1a.field_0 = -a4.field_4
					v19 = float32(float64(a1a.field_0)*v13 + v14*float64(a4.field_0))
					v27 = float32(nox_xxx_objectGetMass_4E4A70(v3))
					if nox_xxx_objectGetMass_4E4A70(v4) <= float64(v27) {
						v15 = nox_xxx_objectGetMass_4E4A70(v4)
					} else {
						v15 = nox_xxx_objectGetMass_4E4A70(v3)
					}
					v16 = v15 * float64(v19)
					*(*float32)(unsafe.Pointer(&v23)) = float32(float64(*(*float32)(unsafe.Pointer(&v22))) - v16*float64(a1a.field_0)*0.69999999)
					*(*float32)(unsafe.Pointer(&a3b)) = float32(float64(*(*float32)(unsafe.Pointer(&a3a))) - v16*float64(a1a.field_4)*0.69999999)
					if v10 != 0 {
						v18 = -*(*float32)(unsafe.Pointer(&a3b))
						v17 = -*(*float32)(unsafe.Pointer(&v23))
						sub_548600((*nox_object_t)(unsafe.Pointer(uintptr(v4))), v17, v18)
					} else {
						sub_548600((*nox_object_t)(unsafe.Pointer(uintptr(v3))), *(*float32)(unsafe.Pointer(&v23)), *(*float32)(unsafe.Pointer(&a3b)))
					}
				}
			}
			if *(*uint32)(unsafe.Pointer(uintptr(v3 + 16)))&0x8000000 != 0 {
				nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
				*(*uint32)(unsafe.Pointer(uintptr(v3 + 16))) &= 0xF7FFFFFF
			}
			if *(*uint32)(unsafe.Pointer(uintptr(v4 + 16)))&0x8000000 != 0 {
				nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(v4))))
				*(*uint32)(unsafe.Pointer(uintptr(v4 + 16))) &= 0xF7FFFFFF
			}
		}
	}
}
func nox_xxx_findObjectAtCursor_54AF40(a1p *nox_object_t) *nox_object_t {
	var (
		a1  int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1  int32
		v2  float64
		a1a float2
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))))
	a1a.field_0 = float32(float64(*(*int32)(unsafe.Pointer(uintptr(v1 + 2284)))))
	v2 = float64(*(*int32)(unsafe.Pointer(uintptr(v1 + 2288))))
	dword_5d4594_2491592 = uint32(a1)
	a1a.field_4 = float32(v2)
	*memmap.PtrUint32(0x5D4594, 2491596) = 0
	*memmap.PtrUint32(0x5D4594, 2491600) = 0
	nox_xxx_unitsGetInCircle_517F90(&a1a, 100.0, unsafe.Pointer(uintptr(int32(funAddr(nox_xxx_playerCursorScanFn_54AFB0)))), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(&a1a))))))
	return (*nox_object_t)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, 2491596))))
}
func nox_xxx_playerCursorScanFn_54AFB0(a1 int32, a2 *float32) {
	var (
		v2  *float32
		v3  *byte
		v4  int32
		v5  float64
		v6  float32
		v7  int32
		v8  float64
		v9  float64
		v10 float64
		v11 float64
		v12 float64
		v13 float32
		v14 float32
		a3  float2
		a1a float2
		v17 float32
	)
	if *memmap.PtrUint32(0x5D4594, 2491604) == 0 {
		*memmap.PtrUint32(0x5D4594, 2491604) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Polyp")))
	}
	v2 = (*float32)(unsafe.Pointer(uintptr(a1)))
	if uint32(a1) != dword_5d4594_2491592 && (*(*uint32)(unsafe.Pointer(uintptr(a1 + 16)))&0x8020) == 0 && (nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0) == 0 || nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_2491592))))), 21) != 0) && (*(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x80000206 != 0 || uint32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) == *memmap.PtrUint32(0x5D4594, 2491604)) {
		if nox_xxx_mapCheck_537110((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_2491592)))))) != 0 {
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4) == 0 || (*(*uint32)(unsafe.Pointer(uintptr(a1 + 36))) != nox_player_netCode_85319C || !nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING))) && (func() *byte {
				v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 36)))))))
				return v3
			}()) != nil && (*(*byte)(unsafe.Add(unsafe.Pointer(v3), 3680))&1) == 0 {
				if (*(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x200) != 512 || (func() int32 {
					v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
					return int32(*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v4))), 1))) & 0x40
				}()) != 0 {
					v5 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 104))))
					v14 = float32(v5)
					v17 = float32(v5)
					if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*43))) == 2 {
						v13 = *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*44)) * *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*44))
						v7 = nox_float2int(v13)
						a3.field_0 = *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*14)) - *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*44))
						a1a.field_0 = *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*44)) + *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*14))
						if float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) > float64(v17) {
							v8 = float64(*a2 - *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*14)))
							v9 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) - v17)
							if float64(v7) <= v9*v9+v8*v8 {
								return
							}
							v12 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*26)) + *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*15)))
							if v12 > float64(*mem_getFloatPtr(0x5D4594, 2491600)) {
								*mem_getFloatPtr(0x5D4594, 2491600) = float32(v12)
								*memmap.PtrUint32(0x5D4594, 2491596) = uint32(uintptr(unsafe.Pointer(v2)))
							}
							return
						}
						v10 = float64(*a2)
						if float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) < float64(v14) {
							v11 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) - v14)
							if float64(v7) <= v11*v11+(v10-float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*14))))*(v10-float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*14)))) {
								return
							}
							v12 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*26)) + *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*15)))
							if v12 > float64(*mem_getFloatPtr(0x5D4594, 2491600)) {
								*mem_getFloatPtr(0x5D4594, 2491600) = float32(v12)
								*memmap.PtrUint32(0x5D4594, 2491596) = uint32(uintptr(unsafe.Pointer(v2)))
							}
							return
						}
						if v10 > float64(a3.field_0) && float64(*a2) < float64(a1a.field_0) {
							v12 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*26)) + *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*15)))
							if v12 > float64(*mem_getFloatPtr(0x5D4594, 2491600)) {
								*mem_getFloatPtr(0x5D4594, 2491600) = float32(v12)
								*memmap.PtrUint32(0x5D4594, 2491596) = uint32(uintptr(unsafe.Pointer(v2)))
							}
							return
						}
					} else if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*43))) == 3 {
						v6 = *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*14))
						a1a.field_4 = float32(v5)
						a3.field_0 = *a2
						a1a.field_0 = v6
						a3.field_4 = *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))
						if nox_xxx_map_57B850(&a1a, (*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*43)), &a3) != 0 {
							v12 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*26)) + *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*15)))
							if v12 > float64(*mem_getFloatPtr(0x5D4594, 2491600)) {
								*mem_getFloatPtr(0x5D4594, 2491600) = float32(v12)
								*memmap.PtrUint32(0x5D4594, 2491596) = uint32(uintptr(unsafe.Pointer(v2)))
							}
							return
						}
						a1a.field_4 = float32(v5)
						if nox_xxx_map_57B850(&a1a, (*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*43)), &a3) != 0 || *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*50))+*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*14)) < *a2 && float64(*a2) < float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*14))) && v14+*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*51)) < *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) && v17+*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*51)) > *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) {
							v12 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*26)) + *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*15)))
							if v12 > float64(*mem_getFloatPtr(0x5D4594, 2491600)) {
								*mem_getFloatPtr(0x5D4594, 2491600) = float32(v12)
								*memmap.PtrUint32(0x5D4594, 2491596) = uint32(uintptr(unsafe.Pointer(v2)))
							}
							return
						}
						if float64(*a2) >= float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*14))) && *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*52))+*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*14)) > *a2 && v14+*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*53)) < *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) && v17+*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*53)) > *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) {
							v12 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*26)) + *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*15)))
							if v12 > float64(*mem_getFloatPtr(0x5D4594, 2491600)) {
								*mem_getFloatPtr(0x5D4594, 2491600) = float32(v12)
								*memmap.PtrUint32(0x5D4594, 2491596) = uint32(uintptr(unsafe.Pointer(v2)))
							}
							return
						}
					}
				}
			}
		}
	}
}
func sub_54B2D0(a1 *int32, a2 int32, a3 *uint32) int32 {
	var (
		v3  int32
		v4  *int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  *int32
		v11 *int32
		v12 int32
		v13 int32
		v14 int32
		v15 *int32
		v16 *int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 *int32
		v22 int32
		v23 *int32
		v24 int32
		v25 int32
		v26 int32
		v27 int32
		v28 int32
		v29 int32
		v30 *int32
		v31 int32
		v32 int32
		v33 int32
		a4  int2
		v35 int32
		v36 int32
		v37 int32
		v38 int32
		a2a int32
		a2b int32
		a2c int32
		a2d int32
		a2e int32
		a2f int32
		a2g int32
		a2h int32
	)
	v3 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*uintptr(a2*4+22)))
	switch a2 {
	case 0:
		v4 = (*int32)(unsafe.Pointer(a3))
		a2a = 0
		v5 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*4))
		v6 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) - v3
		a4.field_0 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) + *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3))/2
		a4.field_4 = v5 + *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) - 1
		if v6 >= 0 {
			for {
				if sub_54B810(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), int32(uintptr(unsafe.Pointer(v4))), (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*20)), &a4, *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*22))) != 0 {
					return 1
				}
				v7 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
				if func() int32 {
					p := &a4.field_0
					*p++
					return *p
				}() > v7+v6 {
					a4.field_0 = v7
				}
				a2a++
				if a2a > v6 {
					break
				}
			}
		}
		a2b = 0
		v8 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*4))
		v35 = v8 - v3
		a4.field_4 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) + v8/2
		if v8-v3 < 0 {
			return 0
		}
		v9 = (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*22))
		for {
			a4.field_0 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
			if sub_54BD90(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), int32(uintptr(unsafe.Pointer(v4))), (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*20)), &a4.field_0, *v9) != 0 {
				return 1
			}
			v32 = *v9
			a4.field_0 = a4.field_0 + *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) - 1
			if sub_54BD90(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), int32(uintptr(unsafe.Pointer(v4))), (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*20)), &a4.field_0, v32) != 0 {
				return 1
			}
			if func() int32 {
				p := &a4.field_4
				*p++
				return *p
			}() > *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2))+v35 {
				a4.field_4 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2))
			}
			a2b++
			if a2b > v35 {
				break
			}
		}
		return 0
	case 1:
		v11 = (*int32)(unsafe.Pointer(a3))
		a2c = 0
		v12 = *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*3)) - v3
		a4.field_0 = *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*1)) + *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*3))/2
		a4.field_4 = *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*2))
		if v12 < 0 {
			goto LABEL_20
		}
		for {
			if sub_54B810(int32(uintptr(unsafe.Pointer(v11))), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), &a4.field_0, (*int2)(unsafe.Add(unsafe.Pointer((*int2)(unsafe.Pointer(a1))), unsafe.Sizeof(int2{})*12)), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*26))) != 0 {
				return 1
			}
			v13 = *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
			if func() int32 {
				p := &a4.field_0
				*p++
				return *p
			}() > v13+v12 {
				a4.field_0 = v13
			}
			if func() int32 {
				p := &a2c
				*p++
				return *p
			}() > v12 {
				break
			}
		}
	LABEL_20:
		a2d = 0
		v14 = *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*4))
		v36 = v14 - v3
		a4.field_4 = *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*2)) + v14/2
		if v14-v3 < 0 {
			return 0
		}
		v15 = (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*26))
		for {
			a4.field_0 = *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
			if sub_54BF20(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), int32(uintptr(unsafe.Pointer(v11))), (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*24)), &a4.field_0, *v15) != 0 {
				break
			}
			v33 = *v15
			a4.field_0 = a4.field_0 + *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*3)) - 1
			if sub_54BF20(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), int32(uintptr(unsafe.Pointer(v11))), (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*24)), &a4.field_0, v33) != 0 {
				break
			}
			if func() int32 {
				p := &a4.field_4
				*p++
				return *p
			}() > *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*2))+v36 {
				a4.field_4 = *(*int32)(unsafe.Add(unsafe.Pointer(v11), 4*2))
			}
			if func() int32 {
				p := &a2d
				*p++
				return *p
			}() > v36 {
				return 0
			}
		}
		return 1
	case 2:
		v16 = (*int32)(unsafe.Pointer(a3))
		a2e = 0
		v17 = *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*3))
		a4.field_0 = *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1))
		v18 = v17 - v3
		a4.field_4 = *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*2)) + *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*4))/2
		if v18 < 0 {
			goto LABEL_33
		}
		for {
			if sub_54BB20(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), int32(uintptr(unsafe.Pointer(v16))), (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*28)), (*uint32)(unsafe.Pointer(&a4)), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*30))) != 0 {
				return 1
			}
			v19 = *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*2))
			if func() int32 {
				p := &a4.field_4
				*p++
				return *p
			}() > v19+v18 {
				a4.field_4 = v19
			}
			if func() int32 {
				p := &a2e
				*p++
				return *p
			}() > v18 {
				break
			}
		}
	LABEL_33:
		a2f = 0
		v20 = *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*3))
		v37 = v20 - v3
		a4.field_0 = *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1)) + v20/2
		if v20-v3 < 0 {
			return 0
		}
		v21 = (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*30))
		for {
			a4.field_4 = *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*2))
			if sub_54BD90(int32(uintptr(unsafe.Pointer(v16))), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), &a4.field_0, (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*28)), *v21) != 0 {
				break
			}
			v22 = *v21
			a4.field_4 = a4.field_4 + *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*4)) - 1
			if sub_54BF20(int32(uintptr(unsafe.Pointer(v16))), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), &a4.field_0, (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*28)), v22) != 0 {
				break
			}
			if func() int32 {
				p := &a4.field_0
				*p++
				return *p
			}() > *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1))+v37 {
				a4.field_0 = *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1))
			}
			if func() int32 {
				p := &a2f
				*p++
				return *p
			}() > v37 {
				return 0
			}
		}
		return 1
	case 3:
		v23 = (*int32)(unsafe.Pointer(a3))
		a2g = 0
		v24 = *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*3))
		v25 = *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*4))
		v26 = *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*2))
		a4.field_0 = *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*1)) + v24 - 1
		v27 = v24 - v3
		a4.field_4 = v26 + v25/2
		if v27 < 0 {
			goto LABEL_46
		}
	default:
		return 0
	}
	for {
		if sub_54BB20(int32(uintptr(unsafe.Pointer(v23))), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), &a4.field_0, (*uint32)(unsafe.Pointer((*int32)(unsafe.Add(unsafe.Pointer(a1), 4*32)))), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*34))) != 0 {
			return 1
		}
		v28 = *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*2))
		if func() int32 {
			p := &a4.field_4
			*p++
			return *p
		}() > v28+v27 {
			a4.field_4 = v28
		}
		if func() int32 {
			p := &a2g
			*p++
			return *p
		}() > v27 {
			break
		}
	}
LABEL_46:
	a2h = 0
	v29 = *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*3))
	v38 = v29 - v3
	a4.field_0 = *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*1)) + v29/2
	if v29-v3 < 0 {
		return 0
	}
	v30 = (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*34))
	for {
		a4.field_4 = *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*2))
		if sub_54BD90(int32(uintptr(unsafe.Pointer(v23))), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), &a4.field_0, (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*32)), *v30) != 0 {
			break
		}
		v31 = *v30
		a4.field_4 = a4.field_4 + *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*4)) - 1
		if sub_54BF20(int32(uintptr(unsafe.Pointer(v23))), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*37)), &a4.field_0, (*int32)(unsafe.Add(unsafe.Pointer(a1), 4*32)), v31) != 0 {
			break
		}
		if func() int32 {
			p := &a4.field_0
			*p++
			return *p
		}() > *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*1))+v38 {
			a4.field_0 = *(*int32)(unsafe.Add(unsafe.Pointer(v23), 4*1))
		}
		if func() int32 {
			p := &a2h
			*p++
			return *p
		}() > v38 {
			return 0
		}
	}
	return 1
}
func sub_54B810(a1 int32, a2 int32, a3 *int32, a4 *int2, a5 int32) int32 {
	var (
		v5  *int32
		v6  *int2
		v7  int32
		v8  *float32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 *float32
		v16 float64
		v17 *float32
		v18 *float32
		a2a float2
		v20 int32
		v21 *int2
		v22 *int2
		v23 int32
		v24 int32
	)
	v5 = a3
	v6 = a4
	v7 = a4.field_0 - *a3
	v20 = a4.field_0 - *a3
	if v20 < 0 {
		v7 = -v7
	}
	*memmap.PtrUint32(0x5D4594, 2491608) = 0
	if v7 != 0 {
		if v7 < 3 {
			return 0
		}
		v10 = *(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
		v11 = a4.field_4
		v12 = *(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
		*memmap.PtrUint32(0x5D4594, 2491608) = 0
		v13 = v10 - (v12-v11)/2
		v14 = v13 - 1
		v21 = (*int2)(unsafe.Pointer(uintptr(v13 - 1)))
		v15 = sub_523E30(2, a5, *(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))-(v13-1))
		*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(v15)))
		a2a.field_0 = float32(float64(*v5) * 32.526913)
		v16 = float64(int32(uintptr(unsafe.Pointer(v21)))) * 32.526913
		a2a.field_4 = float32(v16)
		nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v15)), &a2a)
		*memmap.PtrUint32(0x5D4594, 2491608)++
		if v20 <= 0 {
			v17 = sub_523E30(5, a5, *v5-v6.field_0)
			a2a.field_4 = float32(v16)
			*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(v17)))
			a2a.field_0 = float32(float64(v6.field_0) * 32.526913)
			sub_521A70(*memmap.PtrInt32(0x5D4594, 2491612), *(*int32)(unsafe.Pointer(&dword_5d4594_2491616)), 3)
		} else {
			*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(sub_523E30(4, a5, v6.field_0-*v5))))
			v22 = (*int2)(unsafe.Pointer(uintptr(a5 + *v5)))
			a2a.field_4 = float32(v16)
			a2a.field_0 = float32(float64(int32(uintptr(unsafe.Pointer(v22)))) * 32.526913)
			sub_521A70(*memmap.PtrInt32(0x5D4594, 2491612), *(*int32)(unsafe.Pointer(&dword_5d4594_2491616)), 2)
		}
		nox_xxx_mapGenSetRoomPos_521880(*(**uint32)(memmap.PtrOff(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612)), &a2a)
		*memmap.PtrUint32(0x5D4594, 2491608)++
		v18 = sub_523E30(2, a5, v14-v6.field_4-1)
		*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(v18)))
		v24 = v6.field_4 + 1
		a2a.field_0 = float32(float64(v6.field_0) * 32.526913)
		a2a.field_4 = float32(float64(v24) * 32.526913)
		nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v18)), &a2a)
		sub_521A70(*(*int32)(unsafe.Pointer(&dword_5d4594_2491616)), *memmap.PtrInt32(0x5D4594, 2491620), 0)
	} else {
		v8 = sub_523E30(2, a5, *(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))-a4.field_4-1)
		*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(v8)))
		v23 = a4.field_4 + 1
		a2a.field_0 = float32(float64(a4.field_0) * 32.526913)
		a2a.field_4 = float32(float64(v23) * 32.526913)
		nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v8)), &a2a)
	}
	*memmap.PtrUint32(0x5D4594, 2491608)++
	return sub_54BA60(a1, a2, 0, 1)
}
func sub_54BA60(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4     int32
		v5     int32
		v6     *int32
		v7     int32
		v8     *uint8
		result int32
	)
	_ = result
	var v10 int32
	var v11 *unsafe.Pointer
	v4 = int32(*memmap.PtrUint32(0x5D4594, 2491608))
	v5 = 0
	if *memmap.PtrInt32(0x5D4594, 2491608) > 0 {
		v6 = mem_getI32Ptr(0x5D4594, 2491612)
		for sub_521200(*v6) == 0 {
			v4 = int32(*memmap.PtrUint32(0x5D4594, 2491608))
			v5++
			v6 = (*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
			if v5 >= *memmap.PtrInt32(0x5D4594, 2491608) {
				goto LABEL_5
			}
		}
		v10 = 0
		if *memmap.PtrUint32(0x5D4594, 2491608) > 0 {
			v11 = (*unsafe.Pointer)(memmap.PtrOff(0x5D4594, 2491612))
			for {
				sub_521A10(*v11)
				v10++
				v11 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(unsafe.Pointer(nil))*1))
				if v10 >= *memmap.PtrInt32(0x5D4594, 2491608) {
					break
				}
			}
		}
		return 0
	}
LABEL_5:
	v7 = 0
	if v4 > 0 {
		v8 = (*uint8)(memmap.PtrOff(0x5D4594, 2491612))
		for {
			nox_xxx_mapGenAddNewRoom_521730(*(**uint32)(unsafe.Pointer(v8)))
			v7++
			v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 4))
			if v7 >= *memmap.PtrInt32(0x5D4594, 2491608) {
				break
			}
		}
	}
	sub_521A70(a1, *memmap.PtrInt32(0x5D4594, 2491612), a3)
	sub_521A70(a2, int32(*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491608)), a4)
	return 1
}
func sub_54BB20(a1 int32, a2 int32, a3 *int32, a4 *uint32, a5 int32) int32 {
	var (
		v5  *uint32
		v6  int32
		v7  *float32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 *float32
		v14 *float32
		a2a float2
		v16 int32
		v17 int32
	)
	v5 = a4
	v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a4), 4*1)) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1))))
	v16 = v6
	if v6 < 0 {
		v6 = -v6
	}
	*memmap.PtrUint32(0x5D4594, 2491608) = 0
	if v6 != 0 {
		if v6 < 3 {
			return 0
		}
		v9 = *a3
		v10 = int32(*v5 - uint32(*a3))
		*memmap.PtrUint32(0x5D4594, 2491608) = 0
		v11 = v9 + v10/2
		v12 = a5
		v13 = sub_523E30(4, a5, v11-*a3+a5-1)
		*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(v13)))
		a2a.field_0 = float32(float64(*a3+1) * 32.526913)
		a2a.field_4 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1))) * 32.526913)
		nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v13)), &a2a)
		*memmap.PtrUint32(0x5D4594, 2491608)++
		if v16 <= 0 {
			*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(sub_523E30(2, a5, int32(uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1)))-*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1)))))))
			a2a.field_0 = float32(float64(v11) * 32.526913)
			a2a.field_4 = float32(float64(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1)))) * 32.526913)
			sub_521A70(*memmap.PtrInt32(0x5D4594, 2491612), *(*int32)(unsafe.Pointer(&dword_5d4594_2491616)), 0)
		} else {
			*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(sub_523E30(3, a5, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1))-uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1))))))))
			v17 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) + a5
			a2a.field_0 = float32(float64(v11) * 32.526913)
			a2a.field_4 = float32(float64(v17) * 32.526913)
			sub_521A70(*memmap.PtrInt32(0x5D4594, 2491612), *(*int32)(unsafe.Pointer(&dword_5d4594_2491616)), 1)
		}
		nox_xxx_mapGenSetRoomPos_521880(*(**uint32)(memmap.PtrOff(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612)), &a2a)
		*memmap.PtrUint32(0x5D4594, 2491608)++
		v14 = sub_523E30(4, v12, int32(*v5-uint32(v11)-uint32(v12)))
		*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(v14)))
		a2a.field_0 = float32(float64(v12+v11) * 32.526913)
		a2a.field_4 = float32(float64(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1)))) * 32.526913)
		nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v14)), &a2a)
		sub_521A70(*(*int32)(unsafe.Pointer(&dword_5d4594_2491616)), *memmap.PtrInt32(0x5D4594, 2491620), 2)
	} else {
		v7 = sub_523E30(4, a5, int32(*v5-uint32(*a3)-1))
		*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(v7)))
		a2a.field_0 = float32(float64(*a3+1) * 32.526913)
		a2a.field_4 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1))) * 32.526913)
		nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v7)), &a2a)
	}
	*memmap.PtrUint32(0x5D4594, 2491608)++
	return sub_54BA60(a1, a2, 2, 3)
}
func sub_54BD90(a1 int32, a2 int32, a3 *int32, a4 *int32, a5 int32) int32 {
	var (
		v6  int32
		v7  int32
		v8  int32
		v9  *float32
		v10 int32
		a2a float2
	)
	if *(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1)) > *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1))-a5 {
		return 0
	}
	v6 = *a3
	v7 = *a4
	*memmap.PtrUint32(0x5D4594, 2491608) = 0
	v8 = v7 - v6
	v9 = sub_523E30(2, a5, *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1))-*(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1)))
	*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(v9)))
	a2a.field_0 = float32(float64(*a3) * 32.526913)
	a2a.field_4 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1))) * 32.526913)
	nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v9)), &a2a)
	*memmap.PtrUint32(0x5D4594, 2491608)++
	if v8 <= 0 {
		*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(sub_523E30(5, a5, *a3-*a4-1))))
		a2a.field_0 = float32(float64(*a4+1) * 32.526913)
		a2a.field_4 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1))) * 32.526913)
		sub_521A70(*memmap.PtrInt32(0x5D4594, 2491612), *(*int32)(unsafe.Pointer(&dword_5d4594_2491616)), 3)
		v10 = 2
	} else {
		*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(sub_523E30(4, a5, *a4-*a3-a5))))
		a2a.field_0 = float32(float64(a5+*a3) * 32.526913)
		a2a.field_4 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1))) * 32.526913)
		sub_521A70(*memmap.PtrInt32(0x5D4594, 2491612), *(*int32)(unsafe.Pointer(&dword_5d4594_2491616)), 2)
		v10 = 3
	}
	nox_xxx_mapGenSetRoomPos_521880(*(**uint32)(memmap.PtrOff(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612)), &a2a)
	*memmap.PtrUint32(0x5D4594, 2491608)++
	return sub_54BA60(a1, a2, 0, v10)
}
func sub_54BF20(a1 int32, a2 int32, a3 *int32, a4 *int32, a5 int32) int32 {
	var (
		v5  *int32
		v7  int32
		v8  int32
		v9  *float32
		v10 int32
		a2a float2
		v12 int32
	)
	v5 = a3
	if *(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1)) <= *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) {
		return 0
	}
	v7 = *a3
	v8 = *a4
	*memmap.PtrUint32(0x5D4594, 2491608) = 0
	v9 = sub_523E30(3, a5, *(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1))-*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1))+a5-1)
	*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(v9)))
	v12 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) + 1
	a2a.field_0 = float32(float64(*v5) * 32.526913)
	a2a.field_4 = float32(float64(v12) * 32.526913)
	nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v9)), &a2a)
	*memmap.PtrUint32(0x5D4594, 2491608)++
	if v8-v7 <= 0 {
		*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(sub_523E30(5, a5, *v5-*a4-1))))
		a2a.field_0 = float32(float64(*a4+1) * 32.526913)
		a2a.field_4 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1))) * 32.526913)
		sub_521A70(*memmap.PtrInt32(0x5D4594, 2491612), *(*int32)(unsafe.Pointer(&dword_5d4594_2491616)), 3)
		v10 = 2
	} else {
		*memmap.PtrUint32(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612) = uint32(uintptr(unsafe.Pointer(sub_523E30(4, a5, *a4-*v5-a5))))
		a2a.field_0 = float32(float64(a5+*v5) * 32.526913)
		a2a.field_4 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1))) * 32.526913)
		sub_521A70(*memmap.PtrInt32(0x5D4594, 2491612), *(*int32)(unsafe.Pointer(&dword_5d4594_2491616)), 2)
		v10 = 3
	}
	nox_xxx_mapGenSetRoomPos_521880(*(**uint32)(memmap.PtrOff(0x5D4594, *memmap.PtrUint32(0x5D4594, 2491608)*4+2491612)), &a2a)
	*memmap.PtrUint32(0x5D4594, 2491608)++
	return sub_54BA60(a1, a2, 1, v10)
}
func nox_xxx_monsterAutoSpells_54C0C0(a1p *nox_object_t) int16 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 int32
		v2 int32
		v3 int16
		v4 int16
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if *memmap.PtrUint32(0x5D4594, 2491640) == 0 {
		*memmap.PtrUint32(0x5D4594, 2491624) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("UrchinShaman")))
		*memmap.PtrUint32(0x5D4594, 2491628) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Wizard")))
		*memmap.PtrUint32(0x5D4594, 2491632) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("WizardWhite")))
		*memmap.PtrUint32(0x5D4594, 2491636) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Beholder")))
		*memmap.PtrUint32(0x5D4594, 2491640) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Lich")))
		*memmap.PtrUint32(0x5D4594, 2491644) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("LichLord")))
		*memmap.PtrUint32(0x5D4594, 2491648) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Demon")))
		*memmap.PtrUint32(0x5D4594, 2491652) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("WizardGreen")))
		*memmap.PtrUint32(0x5D4594, 2491656) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("WillOWisp")))
	}
	v2 = int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))
	if uint32(uint16(int16(v2))) != *memmap.PtrUint32(0x5D4594, 2491624) {
		if uint32(v2) == *memmap.PtrUint32(0x5D4594, 2491628) || uint32(v2) == *memmap.PtrUint32(0x5D4594, 2491632) {
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 2040))) = 3
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 1540))) = 0x8000000
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 1640))) = 0x8000000
			*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = 0
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 1644))) = 0x10000000
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 1776))) = 0x20000000
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 1596))) = 0x40000000
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 1688))) = 0x40000000
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 1660))) = 0x40000000
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 1584))) = 0x40000000
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 1504))) = 2147483648
		} else if uint32(v2) == *memmap.PtrUint32(0x5D4594, 2491636) {
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 2040))) = 3
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 1584))) = 0x40000000
			v2 = bool2int32(nox_common_gameFlags_check_40A5C0(4096))
			if v2 == 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1504))) = 2147483648
				*(*uint8)(unsafe.Pointer(uintptr(v1 + 2036))) = 1
				return int16(v2)
			}
		} else {
			if uint32(v2) == *memmap.PtrUint32(0x5D4594, 2491640) {
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 2040))) = 3
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1540))) = 0x8000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1640))) = 0x8000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1772))) = 0x10000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1776))) = 0x20000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1620))) = 0x20000000
				*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = 0
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1644))) = 2147483648
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1596))) = 0x40000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1660))) = 0x40000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1584))) = 0x40000000
				*(*uint8)(unsafe.Pointer(uintptr(v1 + 2036))) = 1
				return int16(v2)
			}
			if uint32(v2) == *memmap.PtrUint32(0x5D4594, 2491644) {
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 2040))) = 3
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1540))) = 0x8000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1640))) = 0x8000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1772))) = 0x10000000
				*(*uint16)(unsafe.Pointer(uintptr(v1 + 1472))) = uint16(int16(int32(uint16(gameFPS())) * 3))
				*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = uint16(gameFPS())
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1612))) = 0x40000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1644))) = 2147483648
				*(*uint8)(unsafe.Pointer(uintptr(v1 + 2036))) = 1
				*(*uint16)(unsafe.Pointer(uintptr(v1 + 1474))) = uint16(int16(v2 * 5))
				return int16(v2)
			}
			if uint32(v2) == *memmap.PtrUint32(0x5D4594, 2491648) {
				*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = 0
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 2040))) = 3
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1540))) = 0x8000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1784))) = 0x20000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1596))) = 0x40000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1528))) = 0x40000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1644))) = 2147483648
				*(*uint8)(unsafe.Pointer(uintptr(v1 + 2036))) = 1
				return int16(v2)
			}
			if uint32(v2) == *memmap.PtrUint32(0x5D4594, 2491652) {
				*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = 0
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 2040))) = 3
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1640))) = 0x8000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1536))) = 0x20000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1720))) = 0x40000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1728))) = 0x40000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1688))) = 0x40000000
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1504))) = 2147483648
				*(*uint8)(unsafe.Pointer(uintptr(v1 + 2036))) = 1
				return int16(v2)
			}
			if uint32(v2) == *memmap.PtrUint32(0x5D4594, 2491656) {
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 2040))) = 3
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 1660))) = 0x40000000
				*(*uint8)(unsafe.Pointer(uintptr(v1 + 2036))) = 1
				return int16(v2)
			}
		}
		*(*uint8)(unsafe.Pointer(uintptr(v1 + 2036))) = 1
		return int16(v2)
	}
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 2040))) = 2
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 1640))) = 0x8000000
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 1448))) = 0
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 1450))) = uint16(gameFPS() >> 1)
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 1536))) = 0x20000000
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 1464))) = uint16(int16(int32(uint16(gameFPS())) * 3))
	v3 = int16(uint16(gameFPS()))
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 1472))) = 0
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 1466))) = uint16(int16(int32(v3) * 5))
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 1720))) = 0x40000000
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 1696))) = 0x40000000
	v4 = int16(uint16(gameFPS()))
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 1752))) = 2147483648
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 1474))) = uint16(int16(int32(v4) * 3))
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 1480))) = uint16(gameFPS())
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = uint16(gameFPS())
	*(*uint8)(unsafe.Pointer(uintptr(v1 + 2036))) = 1
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 1482))) = uint16(int16(v2 * 3))
	return int16(v2)
}
func nox_xxx_createWeapon_54C710(a1 int32) int32 {
	var (
		v1  int32
		v2  int32
		v3  *uint32
		v4  *uint16
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 *uint8
	)
	_ = v10
	var v11 float64
	var v12 int8
	var result int32
	var v14 int32
	var v15 float32
	var v16 float32
	var v17 float32
	var v18 float32
	var v19 float32
	var v20 float32
	var v21 float32
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))))
	v3 = (*uint32)(nox_xxx_getProjectileClassById_413250(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))))
	if *memmap.PtrUint32(0x5D4594, 2491660) == 0 {
		*memmap.PtrUint32(0x5D4594, 2491660) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("OblivionHeart")))
		*memmap.PtrUint32(0x5D4594, 2491664) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("OblivionWierdling")))
		*memmap.PtrUint32(0x5D4594, 2491668) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("OblivionOrb")))
	}
	if v3 != nil {
		v4 = *(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
		if v4 != nil {
			*v4 = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*26)))
			*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))) + 4))) = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*26)))
			if nox_common_gameFlags_check_40A5C0(4096) {
				v20 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("QuestDurabilityMultiplier")))
				v15 = float32(float64(**(**uint16)(unsafe.Pointer(uintptr(v1 + 556)))) * float64(v20))
				**(**uint16)(unsafe.Pointer(uintptr(v1 + 556))) = uint16(int16(nox_float2int(v15)))
				v16 = float32(float64(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 556))) + 4)))) * float64(v20))
				*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 556))) + 4))) = uint16(int16(nox_float2int(v16)))
			}
		}
	}
	v5 = int32(*(*uint16)(unsafe.Pointer(uintptr(v1 + 4))))
	if uint32(uint16(int16(v5))) == *memmap.PtrUint32(0x5D4594, 2491660) {
		v6 = nox_xxx_modifGetIdByName_413290(internCStr("Lightning4"))
		*(*uint32)(unsafe.Pointer(uintptr(v2 + 8))) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v6)))
	} else if uint32(v5) == *memmap.PtrUint32(0x5D4594, 2491664) {
		v7 = nox_xxx_modifGetIdByName_413290(internCStr("Vampirism2"))
		*(*uint32)(unsafe.Pointer(uintptr(v2 + 8))) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v7)))
		v8 = nox_xxx_modifGetIdByName_413290(internCStr("Lightning3"))
		*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v8)))
	}
	if *(*uint32)(unsafe.Pointer(uintptr(v1 + 8)))&0x1000000 != 0 {
		v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 12))))
		if v9&0x82 != 0 {
			v10 = *(**uint8)(unsafe.Pointer(uintptr(v1 + 736)))
			if nox_common_gameFlags_check_40A5C0(4096) {
				v11 = nox_xxx_gamedataGetFloat_419D40(internCStr("DefaultAmmoAmountQuest"))
			} else {
				v11 = nox_xxx_gamedataGetFloat_419D40(internCStr("DefaultAmmoAmount"))
			}
			v17 = float32(v11)
			v12 = int8(nox_float2int(v17))
			*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 1)) = uint8(v12)
			*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 2)) = 0
			*v10 = uint8(v12)
		} else if v9&0xC != 0 {
			**(**uint8)(unsafe.Pointer(uintptr(v1 + 736))) = 0
		}
	}
	result = bool2int32(nox_common_gameFlags_check_40A5C0(4096))
	if result != 0 {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 8))))
		if result&0x1000 != 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(v1 + 12)))&0x47F0000 != 0 {
				v14 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 736))))
				v21 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("QuestStaffChargeMultiplier")))
				if *(*uint32)(unsafe.Pointer(uintptr(v1 + 12)))&0x40000 != 0 {
					v21 = v21 + v21
				}
				v18 = float32(float64(*(*uint8)(unsafe.Pointer(uintptr(v14 + 109)))) * float64(v21))
				*(*uint8)(unsafe.Pointer(uintptr(v14 + 109))) = uint8(int8(nox_float2int(v18)))
				v19 = float32(float64(*(*uint8)(unsafe.Pointer(uintptr(v14 + 108)))) * float64(v21))
				result = nox_float2int(v19)
				*(*uint8)(unsafe.Pointer(uintptr(v14 + 108))) = uint8(int8(result))
			}
		}
	}
	return result
}
func sub_54C950(a1 int32) *uint32 {
	var (
		v1     int32
		result *uint32
		v3     *uint16
		v4     float32
		v5     float32
		v6     float32
	)
	v1 = a1
	result = (*uint32)(nox_xxx_equipClothFindDefByTT_413270(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))))
	if result != nil {
		v3 = *(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
		if v3 != nil {
			*v3 = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*26)))
			*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))) + 4))) = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*26)))
			result = (*uint32)(unsafe.Pointer(uintptr(bool2int32(nox_common_gameFlags_check_40A5C0(4096)))))
			if result != nil {
				v6 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("QuestDurabilityMultiplier")))
				v4 = float32(float64(**(**uint16)(unsafe.Pointer(uintptr(v1 + 556)))) * float64(v6))
				**(**uint16)(unsafe.Pointer(uintptr(v1 + 556))) = uint16(int16(nox_float2int(v4)))
				v5 = float32(float64(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 556))) + 4)))) * float64(v6))
				result = (*uint32)(unsafe.Pointer(uintptr(nox_float2int(v5))))
				*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 556))) + 4))) = uint16(uintptr(unsafe.Pointer(result)))
			}
		}
	}
	return result
}
func nox_xxx_createFnObelisk_54CA10(a1 int32) int32 {
	**(**uint32)(unsafe.Pointer(uintptr(a1 + 748))) = 50
	nullsub_35(uint32(a1), 1117782016)
	nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	return 0
}
func nox_xxx_createFnAnim_54CA50(a1 int32) *int32 {
	return (*int32)(unsafe.Pointer(uintptr(nox_xxx_unitSetXStatus_4E4800((*nox_object_t)(unsafe.Pointer(uintptr(a1))), int32(uintptr(unsafe.Pointer((*int32)(unsafe.Pointer(uintptr(2))))))))))
}
func nox_xxx_createTrigger_54CA60(a1 int32) *uint8 {
	var result *uint8
	result = *(**uint8)(unsafe.Pointer(uintptr(a1 + 748)))
	*(*uint8)(unsafe.Add(unsafe.Pointer(result), 54)) = 90
	*(*uint8)(unsafe.Add(unsafe.Pointer(result), 55)) = 90
	*(*uint8)(unsafe.Add(unsafe.Pointer(result), 56)) = 90
	*(*uint8)(unsafe.Add(unsafe.Pointer(result), 57)) = 10
	*(*uint8)(unsafe.Add(unsafe.Pointer(result), 58)) = 10
	*(*uint8)(unsafe.Add(unsafe.Pointer(result), 59)) = 10
	return result
}
func nox_xxx_createMonsterGen_54CA90(a1 int32) *uint32 {
	var result *uint32
	result = *(**uint32)(unsafe.Pointer(uintptr(a1 + 748)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*23)) = 2
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*13)) = math.MaxUint32
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*15)) = math.MaxUint32
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*19)) = math.MaxUint32
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*17)) = math.MaxUint32
	return result
}
func nox_xxx_createRewardMarker_54CAC0(a1 int32) *uint32 {
	var result *uint32
	result = *(**uint32)(unsafe.Pointer(uintptr(a1 + 692)))
	*result = math.MaxUint8
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*53)) = 0
	return result
}
func nox_xxx_dieImpEgg_54CAE0(a1 int32) int32 {
	var result int32
	nox_xxx_aud_501960(764, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	*((*uint8)(unsafe.Pointer(&result))) = uint8(int8(result | 0x40))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) = uint32(result)
	return result
}
func nox_xxx_diePolyp_54CB10(a1 int32) {
	var (
		v1 int32
		v2 *uint32
		v3 *uint32
	)
	_ = v3
	var v4 float32
	v1 = int32(*memmap.PtrUint32(0x5D4594, 2491672))
	if *memmap.PtrUint32(0x5D4594, 2491672) == 0 {
		v1 = nox_xxx_getNameId_4E3AA0(internCStr("ToxicCloud"))
		*memmap.PtrUint32(0x5D4594, 2491672) = uint32(v1)
	}
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(v1)))
	if v2 != nil {
		v3 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*187)))))
		nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), nil, *(*float32)(unsafe.Pointer(uintptr(a1 + 56))), *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
		v4 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ToxicCloudLifetime")) * float64(int32(gameFPS())))
		*v3 = uint32(nox_float2int(v4))
	}
	nox_xxx_aud_501960(284, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
}
func nox_xxx_diePotion_54CBB0(a1 int32) {
	nox_xxx_aud_501960(753, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
}
func sub_54CBD0(a1 int32) {
	var (
		v1 int32
		v2 uint32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v2 = uint32(nox_xxx_playerGetGold_4FA6B0(a1))
	nox_xxx_playerSubGold_4FA5D0(a1, v2>>1)
	sub_54D080(a1)
	sub_54CC40(a1)
	sub_54CD30(a1)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 2251)))) == 0 {
		sub_54CD30(a1)
	}
	sub_54CE00(a1)
	sub_54CE00(a1)
	sub_54CEE0(a1)
	sub_54CEE0(a1)
	sub_54CFB0(a1)
}
func sub_54CC40(a1 int32) {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  *uint32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v2 = nox_xxx_inventoryGetFirst_4E7980(a1)
	if v2 != 0 {
		for {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))))
			if v3&0x100 != 0 {
				if *(*uint32)(unsafe.Pointer(uintptr(v2 + 8)))&0x1001000 != 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 12))))&2) == 0 {
					break
				}
			}
			v2 = nox_xxx_inventoryGetNext_4E7990(v2)
			if v2 == 0 {
				return
			}
		}
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))))
		if (uint32(v4) & 0x10000) == 0 {
			v6 = 0
			if (v4 & 0x104) != 0 {
				v5 = *(**uint32)(unsafe.Pointer(uintptr(v2 + 692)))
				v6 = 1
				v7 = 4
				for {
					if *v5 != 0 {
						v6 = 0
					}
					v5 = (*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
					v7--
					if v7 == 0 {
						break
					}
				}
			}
			if v6 != 1 {
				v8 = 0
				v9 = nox_xxx_inventoryGetFirst_4E7980(a1)
				if v9 != 0 {
					for {
						if *(*uint32)(unsafe.Pointer(uintptr(v9 + 8)))&0x1001000 != 0 {
							v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(v9 + 16))))
							if (v10&0x100) == 0 && nox_xxx_playerClassCanUseItem_57B3D0((*nox_object_t)(unsafe.Pointer(uintptr(v9))), int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 2251))))) != 0 {
								v8 = 1
							}
						}
						v9 = nox_xxx_inventoryGetNext_4E7990(v9)
						if v9 == 0 {
							break
						}
					}
					if v8 != 0 {
						nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
					}
				}
			}
		}
	}
}
func sub_54CD30(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		i  int32
		v7 int32
	)
	v1 = 0
	v2 = nox_xxx_inventoryGetFirst_4E7980(a1)
	if v2 != 0 {
		for {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))))
			if v3&0x100 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v2 + 8)))&0x2000000 != 0 && (sub_415D10(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(*(*uint16)(unsafe.Pointer(uintptr(v2 + 4))))))))))&0x405) == 0 {
				v1++
			}
			v2 = nox_xxx_inventoryGetNext_4E7990(v2)
			if v2 == 0 {
				break
			}
		}
		if v1 != 0 {
			v4 = nox_common_randomInt_415FA0(0, v1-1)
			v5 = 0
			for i = nox_xxx_inventoryGetFirst_4E7980(a1); i != 0; i = nox_xxx_inventoryGetNext_4E7990(i) {
				v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 16))))
				if v7&0x100 != 0 && *(*uint32)(unsafe.Pointer(uintptr(i + 8)))&0x2000000 != 0 && (sub_415D10(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(*(*uint16)(unsafe.Pointer(uintptr(i + 4))))))))))&0x405) == 0 {
					if v5 == v4 {
						nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(i))))
						return
					}
					v5++
				}
			}
		}
	}
}
func sub_54CE00(a1 int32) {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  *uint32
		v6  *uint32
		v7  int32
		v8  int32
		i   int32
		v10 int32
		v12 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))))
	a1 = v1
	*((*uint8)(unsafe.Pointer(&v2))) = *(*uint8)(unsafe.Pointer(uintptr(v1 + 2251)))
	if int32(uint8(int8(v2))) == 2 || int32(uint8(int8(v2))) == 1 {
		v3 = 0
		v4 = 0
		v5 = (*uint32)(unsafe.Pointer(uintptr(v1 + 3696)))
		v6 = v5
		for {
			if *v6 != 0 && sub_4F24E0(v4) != 0 {
				v3++
			}
			v4++
			v6 = (*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
			if v4 >= 137 {
				break
			}
		}
		v2 = nox_common_randomInt_415FA0(0, v3-1)
		v7 = 0
		v8 = v2
		for i = 0; i < 137; i++ {
			if *v5 != 0 {
				v2 = sub_4F24E0(i)
				if v2 != 0 {
					if v7 == v8 {
						v10 = a1
						*(*uint32)(unsafe.Pointer(uintptr(a1 + i*4 + 3696))) = 0
						v12 = int32(*(*uint8)(unsafe.Pointer(uintptr(v10 + 2064))))
						*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*0)) = 4592
						*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(i))
						*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(nox_xxx_netSendPacket0_4E5420(v12, unsafe.Pointer(&a1), 4, 0, 1)))
						return
					}
					v7++
				}
			}
			v5 = (*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
		}
	}
}
func sub_54CEE0(a1 int32) {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  *uint32
		v6  *uint32
		v7  int32
		v8  int32
		i   int32
		v10 int32
		v11 int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))))
	a1 = v2
	if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 2251)))) == 2 {
		v3 = 0
		v4 = 0
		v5 = (*uint32)(unsafe.Pointer(uintptr(v2 + 4244)))
		v6 = v5
		for {
			if *v6 == 1 && sub_4F2530(v4) != 0 {
				v3++
			}
			v4++
			v6 = (*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
			if v4 >= 41 {
				break
			}
		}
		v8 = nox_common_randomInt_415FA0(0, v3-1)
		v7 = 0
		for i = 0; i < 41; i++ {
			if *v5 == 1 {
				if sub_4F2530(i) != 0 {
					if v7 == v8 {
						v10 = a1
						*(*uint32)(unsafe.Pointer(uintptr(a1 + i*4 + 4244))) = 0
						v11 = int32(*(*uint8)(unsafe.Pointer(uintptr(v10 + 2064))))
						*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*0)) = 5104
						*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(i))
						nox_xxx_netSendPacket0_4E5420(v11, unsafe.Pointer(&a1), 4, 0, 1)
						return
					}
					v7++
				}
			}
			v5 = (*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
		}
	}
}
func sub_54CFB0(a1 int32) int8 {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  *uint32
		v6  int32
		v7  int32
		v8  *uint32
		v10 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))))
	*((*uint8)(unsafe.Pointer(&v2))) = *(*uint8)(unsafe.Pointer(uintptr(v1 + 2251)))
	if int32(uint8(int8(v2))) == 0 {
		v3 = 0
		v4 = 0
		v5 = (*uint32)(unsafe.Pointer(uintptr(v1 + 3696)))
		for {
			if *v5 != 0 && sub_4F2570(v4) != 0 {
				v3++
			}
			v4++
			v5 = (*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
			if v4 >= 6 {
				break
			}
		}
		v2 = nox_common_randomInt_415FA0(1, v3)
		v6 = 1
		a1 = v2
		v7 = 1
		v8 = (*uint32)(unsafe.Pointer(uintptr(v1 + 3700)))
		for {
			if *v8 != 0 {
				v2 = sub_4F2570(v7)
				if v2 != 0 {
					if v6 == a1 {
						*(*uint32)(unsafe.Pointer(uintptr(v1 + v7*4 + 3696))) = 0
						v10 = int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 2064))))
						*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*0)) = 4848
						*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(v7))
						*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(nox_xxx_netSendPacket0_4E5420(v10, unsafe.Pointer(&a1), 4, 0, 1)))
						return int8(v2)
					}
					v6++
				}
			}
			v7++
			v8 = (*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
			if v7 >= 6 {
				break
			}
		}
	}
	return int8(v2)
}
func sub_54D080(a1 int32) {
	var (
		v1  int8
		v2  int32
		i   int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
	)
	v1 = 0
	v17 = 0
	v13 = 0
	v15 = 0
	if dword_5d4594_2491676 == 0 {
		dword_5d4594_2491676 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Diamond")))
		*memmap.PtrUint32(0x5D4594, 2491680) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Emerald")))
		*memmap.PtrUint32(0x5D4594, 2491684) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Ruby")))
	}
	v2 = a1
	for i = nox_xxx_inventoryGetFirst_4E7980(a1); i != 0; i = nox_xxx_inventoryGetNext_4E7990(i) {
		v4 = int32(*(*uint16)(unsafe.Pointer(uintptr(i + 4))))
		if uint32(uint16(int16(v4))) == dword_5d4594_2491676 {
			v17++
		} else if uint32(v4) == *memmap.PtrUint32(0x5D4594, 2491680) {
			v13++
		} else if uint32(v4) == *memmap.PtrUint32(0x5D4594, 2491684) {
			v15++
		}
	}
	v5 = v17
	if v17&1 != 0 {
		v5 = v17 - 1
		v1 = 1
	}
	if v13&1 != 0 {
		v1 |= 2
		v13--
	}
	v6 = v15
	if v15&1 != 0 {
		v6 = v15 - 1
		v1 |= 4
	}
	v14 = v13 / 2
	v7 = v5 / 2
	v18 = v5 / 2
	v16 = v6 / 2
	v8 = nox_xxx_inventoryGetFirst_4E7980(a1)
	if v8 != 0 {
		for {
			v19 = nox_xxx_inventoryGetNext_4E7990(v8)
			v9 = int32(*(*uint16)(unsafe.Pointer(uintptr(v8 + 4))))
			if uint32(uint16(int16(v9))) == dword_5d4594_2491676 {
				if int32(v1)&1 != 0 {
					v10 = nox_xxx_shopGetItemCost_50E3D0(1, 0, *(*float32)(unsafe.Pointer(&v8)))
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v8))))
					nox_xxx_playerAddGold_4FA590(v2, v10/2)
					v1 &= -0x2
				} else if v7 > 0 {
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v8))))
					v18 = v7 - 1
				}
			} else if uint32(v9) == *memmap.PtrUint32(0x5D4594, 2491680) {
				if int32(v1)&2 != 0 {
					v11 = nox_xxx_shopGetItemCost_50E3D0(1, 0, *(*float32)(unsafe.Pointer(&v8)))
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v8))))
					nox_xxx_playerAddGold_4FA590(v2, v11/2)
					v1 &= -0x3
				} else if v14 > 0 {
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v8))))
					v14--
				}
			} else if uint32(v9) == *memmap.PtrUint32(0x5D4594, 2491684) {
				if int32(v1)&4 != 0 {
					v12 = nox_xxx_shopGetItemCost_50E3D0(1, 0, *(*float32)(unsafe.Pointer(&v8)))
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v8))))
					nox_xxx_playerAddGold_4FA590(v2, v12/2)
					v1 &= -0x5
				} else if v16 > 0 {
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v8))))
					v16--
				}
			}
			v8 = v19
			if v19 == 0 {
				break
			}
			v7 = v18
		}
	}
}
func nox_xxx_diePlayer_54D2B0(a1 int32) int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		v4     *uint32
		v5     *byte
		v6     int32
		v7     int8
		v8     int32
		v9     int32
		v10    int16
		v11    int16
		v12    int32
		v13    int32
		v14    int16
		v15    int32
		v16    int32
		v17    int32
		result int32
		v19    int32
		v20    int32
		v21    float32
		v22    *byte
		v23    [14]uint8
		v24    int32
	)
	v1 = a1
	v2 = 0
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if *memmap.PtrUint32(0x5D4594, 2491688) == 0 {
		*memmap.PtrUint32(0x5D4594, 2491688) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("AnkhTradable")))
	}
	if nox_common_gameFlags_check_40A5C0(2048) {
		sub_4DB170(0, nil, 0)
	}
	v24 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 520))))
	if v24 != 0 {
		v24 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(v24)))))))
	}
	v4 = *(**uint32)(unsafe.Pointer(uintptr(v3 + 276)))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*900)) != 0 && gameFrame()-*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*902)) < (gameFPS()*10) {
		v5 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*901))))))
		v6 = int32(uintptr(unsafe.Pointer(v5)))
		v22 = v5
		if v5 != nil {
			if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*523))) != 0 && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*514))) != 0 {
				v2 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*515))))))))
			} else {
				v22 = nil
				v2 = 0
				v6 = 0
			}
			if v24 == v2 {
				v2 = 0
			}
			if v1 == v2 {
				v2 = 0
			}
		}
	} else {
		v22 = nil
		v6 = 0
	}
	if !nox_common_gameFlags_check_40A5C0(0x2000) {
		goto LABEL_38
	}
	v7 = 0
	v23[10] = 0
	*(*uint32)(unsafe.Pointer(&v23[0])) = 0
	*(*uint32)(unsafe.Pointer(&v23[4])) = 0
	*(*uint16)(unsafe.Pointer(&v23[8])) = 0
	if v24 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v24 + 8))))&4 != 0 {
		*(*uint16)(unsafe.Pointer(&v23[2])) = *(*uint16)(unsafe.Pointer(uintptr(v24 + 36)))
	}
	v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 520))))
	if v8 != 0 {
		v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + 8))))
		if v9&2 != 0 {
			v23[10] = 1
			v10 = int16(*(*uint16)(unsafe.Pointer(uintptr(v8 + 4))))
			*(*uint16)(unsafe.Pointer(&v23[8])) = uint16(v10)
			goto LABEL_31
		}
		if v9&4 != 0 {
			v7 = int8(*(*uint8)(unsafe.Pointer(uintptr(v3 + 304))))
			v11 = int16(*(*uint16)(unsafe.Pointer(uintptr(v3 + 300))))
			v23[10] = *(*uint8)(unsafe.Pointer(uintptr(v3 + 304)))
			*(*uint16)(unsafe.Pointer(&v23[8])) = uint16(v11)
		} else {
			v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + 508))))
			if v12 != 0 {
				v13 = int32(*(*uint32)(unsafe.Pointer(uintptr(v12 + 8))))
				if v13&4 != 0 {
					v7 = int8(*(*uint8)(unsafe.Pointer(uintptr(v3 + 304))))
					v14 = int16(*(*uint16)(unsafe.Pointer(uintptr(v3 + 300))))
					v23[10] = *(*uint8)(unsafe.Pointer(uintptr(v3 + 304)))
					*(*uint16)(unsafe.Pointer(&v23[8])) = uint16(v14)
				} else if v13&2 != 0 {
					v23[10] = 1
					*(*uint16)(unsafe.Pointer(&v23[8])) = *(*uint16)(unsafe.Pointer(uintptr(v12 + 4)))
					goto LABEL_31
				}
			}
		}
	}
	if int32(v7) == 0 {
		v10 = int16(*(*uint16)(unsafe.Pointer(uintptr(v3 + 300))))
		v23[10] = *(*uint8)(unsafe.Pointer(uintptr(v3 + 304)))
		*(*uint16)(unsafe.Pointer(&v23[8])) = uint16(v10)
	}
LABEL_31:
	if v2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 8))))&4 != 0 {
		*(*uint16)(unsafe.Pointer(&v23[4])) = *(*uint16)(unsafe.Pointer(uintptr(v2 + 36)))
	}
	*(*uint16)(unsafe.Pointer(&v23[6])) = *(*uint16)(unsafe.Pointer(uintptr(v1 + 36)))
	nox_xxx_netInformTextMsg2_4DA180(14, &v23[0])
	if int32(v23[10]) == 2 && int32(*(*uint16)(unsafe.Pointer(&v23[8]))) == 2 {
		sub_4FC0B0((*nox_object_t)(unsafe.Pointer(uintptr(v24))), 1)
	}
	v6 = int32(uintptr(unsafe.Pointer(v22)))
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 304))) = 0
LABEL_38:
	if *(*uint32)(unsafe.Pointer(uintptr(v1 + 524))) == 16 {
		nox_xxx_aud_501960(299, (*nox_object_t)(unsafe.Pointer(uintptr(v1))), 0, 0)
	} else if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2252)))) != 0 {
		nox_xxx_aud_501960(331, (*nox_object_t)(unsafe.Pointer(uintptr(v1))), 0, 0)
	} else {
		nox_xxx_aud_501960(321, (*nox_object_t)(unsafe.Pointer(uintptr(v1))), 0, 0)
	}
	v15 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 16))))
	*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v15))), 1)) |= 0x80
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 16))) = uint32(v15)
	nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 3)
	*(*uint8)(unsafe.Pointer(uintptr(v3 + 188))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 216))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 192))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 196))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 200))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 204))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 208))) = 0
	*(*uint8)(unsafe.Pointer(uintptr(v3 + 212))) = 0
	v16 = nox_xxx_gamePlayIsAnyPlayers_40A8A0()
	if v16 != 0 {
		if nox_common_gameFlags_check_40A5C0(256) {
			nox_xxx_playerUpdateScore_54D980(v1, v24, v2, v6)
		} else if nox_common_gameFlags_check_40A5C0(16) {
			nox_xxx_playerHandleKotrDeath_54DC40(v1, v24)
		} else if nox_common_gameFlags_check_40A5C0(1024) {
			nox_xxx_playerHandleElimDeath_54D7A0(v1, v24)
		}
	}
	if nox_common_gameFlags_check_40A5C0(1024) && int32(nox_xxx_servGamedataGet_40A020(1024)) != 0 && *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2140))) >= uint32(int32(uint16(nox_xxx_servGamedataGet_40A020(1024)))) {
		nox_xxx_playerRemoveSpawnedStuff_4E5AD0((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
	}
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 16))) |= 0x10
	nox_xxx_action_4DA9F0((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
	if !nox_common_gameFlags_check_40A5C0(4096) {
		nox_xxx_dropAllItems_4EDA40((*uint32)(unsafe.Pointer(uintptr(v1))))
	}
	nox_xxx_netNotifyPlayerDied_54DF00(v1)
	v17 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))))
	*(*uint16)(unsafe.Pointer(uintptr(v3 + 4))) = 0
	nox_xxx_protectMana_56F9E0(int32(*(*uint32)(unsafe.Pointer(uintptr(v17 + 4596)))), 0)
	nox_xxx_setUnitBuffFlags_4E48F0(v1, 0)
	nox_xxx_playerCancelAbils_4FC180((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
	*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 3600))) = 0
	nox_xxx_playerCancelSpells_4FEAE0((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
	nox_xxx_unitClearBuffs_4FF580((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
	if *(*uint32)(unsafe.Pointer(uintptr(v3 + 280))) != 0 {
		nox_xxx_shopCancelSession_510DC0(*(**uint32)(unsafe.Pointer(uintptr(v3 + 280))))
	}
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 280))) = 0
	result = bool2int32(nox_common_gameFlags_check_40A5C0(4096))
	if result != 0 {
		v19 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 320))))
		if v19 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 320))) = uint32(v19 - 1)
			result = sub_4D6130(v1)
		} else {
			v20 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))))
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 548))) = gameFrame()
			v23[0] = 240
			v23[1] = 2
			*(*uint16)(unsafe.Pointer(&v23[8])) = *(*uint16)(unsafe.Pointer(uintptr(v20 + 4688)))
			*(*uint16)(unsafe.Pointer(&v23[2])) = *(*uint16)(unsafe.Pointer(uintptr(v20 + 4668)))
			*(*uint16)(unsafe.Pointer(&v23[6])) = *(*uint16)(unsafe.Pointer(uintptr(v20 + 4664)))
			*(*uint16)(unsafe.Pointer(&v23[4])) = *(*uint16)(unsafe.Pointer(uintptr(v20 + 4672)))
			*(*uint32)(unsafe.Pointer(&v23[10])) = 0
			nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(v20 + 2064)))), unsafe.Pointer(&v23[0]), 14, 0, 1)
			sub_4D6000((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
			sub_54CBD0(v1)
			v21 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("QuestGameStartingExtraLives")))
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 320))) = uint32(nox_float2int(v21))
			result = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))))
			*(*uint8)(unsafe.Pointer(uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(result + 2064)))) + v3 + 452))) = *(*uint8)(unsafe.Pointer(uintptr(v3 + 320)))
		}
	}
	return result
}
func nox_xxx_playerHandleElimDeath_54D7A0(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 int32
		v4 *byte
		v5 int32
		v6 int32
		v7 int32
		v8 *byte
		v9 int32
	)
	v2 = a1
	v3 = 0
	v4 = nil
	v8 = nil
	v6 = a1 + 48
	v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if nox_xxx_servObjectHasTeam_419130(v6) != 0 {
		v8 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 52)))))))
	}
	if a2 != 0 {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
		if nox_xxx_servObjectHasTeam_419130(a2+48) != 0 {
			v4 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 52)))))))
		}
	}
	if a2 == v2 {
		nox_xxx_playerSubLessons_4D8EC0(v2, 1)
		nox_xxx_playerIncrementElimDeath_4D8D40(v2)
		nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
		if v8 != nil {
			nox_xxx_netChangeTeamID_419090(int32(uintptr(unsafe.Pointer(v8))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*13)))+1))
		}
		if dword_5d4594_2650652 != 0 {
			if v3 != 0 {
				sub_425CA0(int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276)))))
			}
		}
		return
	}
	if a2 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
			if v4 != nil {
				if v4 == v8 {
					nox_xxx_playerSubLessons_4D8EC0(a2, 1)
					nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
					if dword_5d4594_2650652 != 0 && v3 != 0 {
						sub_425CA0(int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276)))))
					}
					goto LABEL_32
				}
			} else if v8 == nil {
				nox_xxx_changeScore_4D8E90(a2, 1)
				nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
				if dword_5d4594_2650652 != 0 && v3 != 0 && v9 != 0 {
					sub_425CA0(int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v9 + 276)))))
				}
				goto LABEL_32
			}
			nox_xxx_changeScore_4D8E90(a2, 1)
			nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
			if dword_5d4594_2650652 != 0 {
				if v3 != 0 && v9 != 0 {
					v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))))
					v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v9 + 276))))
					sub_425CA0(v5, v7)
					goto LABEL_32
				}
			}
		}
	} else if dword_5d4594_2650652 != 0 && v9 != 0 {
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v9 + 276))))
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v9 + 276))))
		sub_425CA0(v5, v7)
	}
LABEL_32:
	nox_xxx_playerIncrementElimDeath_4D8D40(v2)
	nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
	if v8 != nil {
		nox_xxx_netChangeTeamID_419090(int32(uintptr(unsafe.Pointer(v8))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*13)))+1))
	}
}
func nox_xxx_playerUpdateScore_54D980(a1 int32, a2 int32, a3 int32, a4 int32) {
	var (
		v4     int32
		v5     *byte
		v6     int32
		v7     int32
		result *byte
		v9     *byte
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    *byte
		v15    *byte
		v16    *byte
		v17    int32
	)
	v4 = a1
	v5 = nil
	v12 = a1 + 48
	v14 = nil
	v15 = nil
	v17 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v6 = 0
	v16 = nil
	if nox_xxx_servObjectHasTeam_419130(v12) != 0 {
		v14 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 52)))))))
	}
	if a2 != 0 {
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
		if nox_xxx_servObjectHasTeam_419130(a2+48) != 0 {
			v5 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 52)))))))
		}
	}
	if a4 != 0 {
		if a3 != 0 {
			v16 = *(**byte)(unsafe.Pointer(uintptr(a3 + 748)))
			if nox_xxx_servObjectHasTeam_419130(a3+48) != 0 {
				v15 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(a3 + 52)))))))
			}
		}
	}
	if a2 == v4 {
		goto LABEL_31
	}
	if a2 != 0 {
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8)))) & 4) == 0 {
			nox_xxx_playerIncrementElimDeath_4D8D40(v4)
			result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v4)))))))
			v9 = v14
			goto LABEL_36
		}
		if v5 != nil {
			if v5 == v14 {
				nox_xxx_playerSubLessons_4D8EC0(a2, 1)
				nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
				nox_xxx_netChangeTeamID_419090(int32(uintptr(unsafe.Pointer(v5))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*13)))-1))
				if dword_5d4594_2650652 == 0 || v6 == 0 {
					nox_xxx_playerIncrementElimDeath_4D8D40(v4)
					result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v4)))))))
					v9 = v14
					goto LABEL_36
				}
				v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 276))))
				v13 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 276))))
				sub_425CA0(v7, v13)
				nox_xxx_playerIncrementElimDeath_4D8D40(v4)
				result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v4)))))))
				v9 = v14
				goto LABEL_36
			}
		} else if v14 == nil {
			nox_xxx_changeScore_4D8E90(a2, 1)
			nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
			if dword_5d4594_2650652 == 0 || v6 == 0 || v17 == 0 {
				nox_xxx_playerIncrementElimDeath_4D8D40(v4)
				result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v4)))))))
				v9 = v14
				goto LABEL_36
			}
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 276))))
			v13 = int32(*(*uint32)(unsafe.Pointer(uintptr(v17 + 276))))
			sub_425CA0(v7, v13)
			nox_xxx_playerIncrementElimDeath_4D8D40(v4)
			result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v4)))))))
			v9 = v14
			goto LABEL_36
		}
		nox_xxx_changeScore_4D8E90(a2, 1)
		nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
		nox_xxx_netChangeTeamID_419090(int32(uintptr(unsafe.Pointer(v5))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*13)))+1))
		if dword_5d4594_2650652 != 0 && v6 != 0 && v17 != 0 {
			sub_425CA0(int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 276)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v17 + 276)))))
		}
		nox_xxx_playerIncrementElimDeath_4D8D40(v4)
		result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v4)))))))
		v9 = v14
		goto LABEL_36
	}
	if a3 != 0 {
		nox_xxx_playerIncrementElimDeath_4D8D40(v4)
		result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v4)))))))
		v9 = v14
		goto LABEL_36
	}
LABEL_31:
	nox_xxx_playerSubLessons_4D8EC0(v4, 1)
	nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v4))))
	v9 = v14
	if v14 != nil {
		nox_xxx_netChangeTeamID_419090(int32(uintptr(unsafe.Pointer(v14))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v14))), 4*13)))-1))
	}
	result = *(**byte)(unsafe.Pointer(&dword_5d4594_2650652))
	if dword_5d4594_2650652 != 0 && v6 != 0 {
		result = sub_425CA0(int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 276)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 276)))))
	}
LABEL_36:
	if a3 == 0 {
		return
	}
	if v5 != nil {
		result = v15
		if v5 == v15 {
			return
		}
		v10 = int32(uintptr(unsafe.Pointer(v15)))
	} else {
		v10 = int32(uintptr(unsafe.Pointer(v15)))
		if v15 == nil {
			goto LABEL_44
		}
	}
	if v9 != nil {
		if v9 == (*byte)(unsafe.Pointer(uintptr(v10))) {
			return
		}
	}
	if v10 != 0 {
		nox_xxx_changeScore_4D8E90(a3, 1)
		nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a3))))
		if v10 != 0 {
			nox_xxx_netChangeTeamID_419090(v10, int32(*(*uint32)(unsafe.Pointer(uintptr(v10 + 52)))+1))
		}
		result = *(**byte)(unsafe.Pointer(&dword_5d4594_2650652))
		if dword_5d4594_2650652 != 0 {
			result = v16
			if v16 != nil {
				v11 = v17
				if v17 != 0 {
					sub_425CA0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(result))), 4*69)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v11 + 276)))))
					return
				}
			}
		}
		return
	}
LABEL_44:
	nox_xxx_changeScore_4D8E90(a3, 1)
	nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a3))))
	if dword_5d4594_2650652 != 0 {
		result = v16
		if v16 != nil {
			v11 = v17
			if v17 != 0 {
				sub_425CA0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(result))), 4*69)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v11 + 276)))))
				return
			}
		}
	}
}
func nox_xxx_playerHandleKotrDeath_54DC40(a1 int32, a2 int32) {
	var (
		v2     *byte
		v3     *byte
		result *byte
		v5     int32
		v6     float64
		v7     int32
		v8     int32
		v9     int32
		v10    float64
		v11    int32
		v12    float32
		v13    float32
		v14    int32
		v15    float32
		v16    int32
	)
	v2 = nil
	v3 = nil
	v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_servObjectHasTeam_419130(a1 + 48))))
	if result != nil {
		result = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 52)))))))
		v3 = result
	}
	if a2 != 0 {
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
		result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_servObjectHasTeam_419130(a2 + 48))))
		if result != nil {
			result = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 52)))))))
			v2 = result
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
			if a2 == a1 || v3 == v2 && v3 != nil {
				if nox_xxx_unitIsCrown_4E7BE0(a2) == 0 {
					nox_xxx_playerIncrementElimDeath_4D8D40(a1)
					nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
					return
				}
				nox_xxx_playerSubLessons_4D8EC0(a2, 1)
				nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
				if v2 != nil {
					nox_xxx_netChangeTeamID_419090(int32(uintptr(unsafe.Pointer(v2))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*13)))-1))
				}
				if dword_5d4594_2650652 == 0 || v5 == 0 {
					nox_xxx_playerIncrementElimDeath_4D8D40(a1)
					nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
					return
				}
				v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))))
				v14 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))))
			} else {
				if v2 == nil || v2 == v3 {
					if nox_xxx_unitIsCrown_4E7BE0(a2) != 0 || nox_xxx_unitIsCrown_4E7BE0(a1) != 0 {
						if nox_xxx_unitIsCrown_4E7BE0(a2) != 0 {
							v10 = nox_xxx_gamedataGetFloat_419D40(internCStr("KotRKingKillsPawnPoints"))
						} else {
							v10 = nox_xxx_gamedataGetFloat_419D40(internCStr("KotRPawnKillsKingPoints"))
						}
						v15 = float32(v10)
						v11 = nox_float2int(v15)
						nox_xxx_changeScore_4D8E90(a2, v11)
						nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
						if dword_5d4594_2650652 != 0 && v5 != 0 && v16 != 0 {
							sub_425CA0(int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v16 + 276)))))
						}
						if !nox_xxx_CheckGameplayFlags_417DA0(4) && nox_xxx_unitIsCrown_4E7BE0(a1) != 0 {
							sub_4ED050(a1, a2)
						}
					}
					nox_xxx_playerIncrementElimDeath_4D8D40(a1)
					nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
					return
				}
				if nox_xxx_unitIsCrown_4E7BE0(a2) != 0 {
					if nox_xxx_unitIsCrown_4E7BE0(a1) != 0 {
						v6 = nox_xxx_gamedataGetFloat_419D40(internCStr("KotRKingKillsKingPoints"))
					} else {
						v6 = nox_xxx_gamedataGetFloat_419D40(internCStr("KotRKingKillsPawnPoints"))
					}
					v12 = float32(v6)
					v7 = nox_float2int(v12)
					nox_xxx_changeScore_4D8E90(a2, v7)
					nox_xxx_netChangeTeamID_419090(int32(uintptr(unsafe.Pointer(v2))), int32(uint32(v7)+*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*13)))))
					nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
					if dword_5d4594_2650652 != 0 && v5 != 0 {
						if v16 != 0 {
							sub_425CA0(int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v16 + 276)))))
						}
					}
					nox_xxx_playerIncrementElimDeath_4D8D40(a1)
					nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
					return
				}
				if nox_xxx_unitIsCrown_4E7BE0(a1) == 0 || (func() bool {
					v13 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("KotRPawnKillsKingPoints")))
					v8 = nox_float2int(v13)
					nox_xxx_changeScore_4D8E90(a2, v8)
					nox_xxx_netChangeTeamID_419090(int32(uintptr(unsafe.Pointer(v2))), int32(uint32(v8)+*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*13)))))
					nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
					return dword_5d4594_2650652 == 0
				}()) || v5 == 0 || v16 == 0 {
					nox_xxx_playerIncrementElimDeath_4D8D40(a1)
					nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
					return
				}
				v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))))
				v14 = int32(*(*uint32)(unsafe.Pointer(uintptr(v16 + 276))))
			}
			sub_425CA0(v9, v14)
			nox_xxx_playerIncrementElimDeath_4D8D40(a1)
			nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			return
		}
	}
}
func nox_xxx_netNotifyPlayerDied_54DF00(a1 int32) {
	var (
		v1 int32 = 0
		v2 int16
		v4 int32
	)
	v4 = v1
	v2 = int16(*(*uint16)(unsafe.Pointer(uintptr(a1 + 36))))
	*((*uint8)(unsafe.Pointer(&v4))) = 232
	*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v4))), 1)))) = uint16(v2)
	nox_xxx_netSendPacket1_4E5390(math.MaxUint8, int32(uintptr(unsafe.Pointer(&v4))), 3, 0, 0)
}
func nox_xxx_dieBarrel_54DFA0(a1 int32) {
	var (
		v1 int32
		v2 *uint32
	)
	v1 = int32(*memmap.PtrUint32(0x5D4594, 2491696))
	if *memmap.PtrUint32(0x5D4594, 2491696) == 0 {
		v1 = nox_xxx_getNameId_4E3AA0(internCStr("BarrelBreaking"))
		*memmap.PtrUint32(0x5D4594, 2491696) = uint32(v1)
	}
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(v1)))
	if v2 != nil {
		nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), nil, *(*float32)(unsafe.Pointer(uintptr(a1 + 56))), *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
	}
	nox_xxx_aud_501960(286, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	nox_xxx_spawnSomeBarrel_4E7470(a1, a1+56)
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
}
func nox_xxx_dieCreateObject_54E010(a1 int32) {
	var (
		v1 int32
		v2 *uint32
		v3 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 728))))
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(*(**byte)(unsafe.Pointer(uintptr(a1 + 728))))))
	if v2 != nil {
		nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), nil, *(*float32)(unsafe.Pointer(uintptr(a1 + 56))), *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
	}
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 128))))
	if v3 != 0 {
		nox_xxx_aud_501960(v3, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	}
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
}
func nox_xxx_dieSpawnObject_54E070(a1 int32) int16 {
	var (
		v1 int32
		v2 *uint32
		v3 int32
		v4 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 728))))
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(*(**byte)(unsafe.Pointer(uintptr(a1 + 728))))))
	if v2 != nil {
		nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), nil, *(*float32)(unsafe.Pointer(uintptr(a1 + 56))), *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
	}
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 128))))
	if v3 != 0 {
		nox_xxx_aud_501960(v3, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	}
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v4))), 1)) |= 0x80
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) = uint32(v4)
	return int16(v4)
}
func nox_xxx_dieMarker_54E460(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 *uint32
	)
	v1 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
	if v1 != 0 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 748))))
		v3 = 0
		v4 = (*uint32)(unsafe.Pointer(uintptr(v2 + 116)))
		for *v4 != uint32(a1) {
			v3++
			v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
			if v3 >= 4 {
				goto LABEL_7
			}
		}
		*(*uint32)(unsafe.Pointer(uintptr(v2 + v3*4 + 116))) = 0
	}
LABEL_7:
	nox_xxx_netSendPointFx_522FF0(-118, (*float2)(unsafe.Pointer(uintptr(a1+56))))
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
}
func nox_xxx_dieBoulder_54E4B0(a1 int32) {
	var (
		v1  int32
		v2  *float2
		v3  int32
		v4  int32
		v5  int32
		v6  *float32
		v7  float64
		v8  int32
		v9  float32
		v10 float32
		a3  float2
	)
	v1 = a1
	nox_xxx_aud_501960(757, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	v2 = (*float2)(unsafe.Pointer(uintptr(a1 + 56)))
	nox_xxx_netSendPointFx_522FF0(-118, (*float2)(unsafe.Pointer(uintptr(a1+56))))
	v3 = nox_common_randomInt_415FA0(20, 30)
	v4 = 0
	if v3 <= 0 {
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
		return
	}
	v5 = int32(dword_5d4594_2491704)
	for {
		v6 = (*float32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(*(**byte)(memmap.PtrOff(0x587000, uint32(v5*4)+291512)))))
		if v6 == nil {
			break
		}
		sub_4ED970(30.0, v2, &a3)
		nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v6)))))), nil, a3.field_0, a3.field_4)
		v9 = float32(nox_common_randomFloat_416030(10.0, 70.0))
		nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v6)))))), v9)
		*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*27)) = float32(nox_common_randomFloat_416030(-2.0, 0.0))
		v7 = float64(*memmap.PtrUint8(0x587000, dword_5d4594_2491704+290328))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*4))) |= 0x800000
		*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*29)) = float32(v7)
		v10 = float32(nox_common_randomFloat_416030(5.0, 20.0))
		nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v6)))))), v10)
		v8 = nox_common_randomInt_415FA0(45, 75)
		nox_xxx_unitSetDecayTime_511660((*nox_object_t)(unsafe.Pointer(v6)), int32(gameFPS()*uint32(v8)))
		v5 = int32((dword_5d4594_2491704 + 1) % *memmap.PtrUint32(0x587000, 290340))
		v4++
		dword_5d4594_2491704 = (dword_5d4594_2491704 + 1) % *memmap.PtrUint32(0x587000, 290340)
		if v4 >= v3 {
			v1 = a1
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
			return
		}
	}
}
func nox_xxx_dieGameBall_54E620(a1 int32) int32 {
	return sub_417F50(a1)
}
func nox_xxx_dieMonsterGen_54E630(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 *uint32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	sub_4D71E0(int32(gameFrame()))
	sub_4D7520(0)
	nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(uintptr(v1+56)), unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 520))))), unsafe.Pointer(uintptr(a1)), 3)
	nox_xxx_aud_501960(1000, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	nox_xxx_sendGeneratorBreakFX_523200((*float32)(unsafe.Pointer(uintptr(a1+56))), -56)
	if nox_common_gameFlags_check_40A5C0(4096) {
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 520))) != 0 {
			v2 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 520))))))))))
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 8))))&4 != 0 {
				sub_4D61B0(v2)
			}
		}
	}
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("DestroyedGenerator"))))
	if v3 != nil {
		nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), nil, *(*float32)(unsafe.Pointer(uintptr(a1 + 56))), *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
	}
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
}
func sub_54E6F0(a1 int32, a2 int32) int32 {
	var result int32
	result = sub_54E730(a2, a1)
	if result != 0 {
		result = bool2int32(nox_xxx_unitsHaveSameTeam_4EC520((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) == 0 || nox_xxx_GetGameplayFlags_417D90()&1 != 0)
	}
	return result
}
func sub_54E730(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		v3     int32
		result int32
	)
	_ = result
	var v5 int32
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&1 != 0 {
		return 0
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	if v2&0x20 != 0 {
		return 0
	}
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
	if v3&0x20 != 0 || *(*uint32)(unsafe.Pointer(uintptr(a1 + 696))) == 0 || *(*uint32)(unsafe.Pointer(uintptr(a2 + 696))) == 0 || v3&0x40 != 0 {
		return 0
	}
	if (v3 & 0x80) != 0 {
		return 1
	}
	if v2&0x11 != 0 && v3&0x4000 != 0 || v3&0x11 != 0 && v2&0x4000 != 0 || (v2&0x400 != 0 || v3&0x400 != 0) && nox_xxx_unitsHaveSameTeam_4EC520((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*nox_object_t)(unsafe.Pointer(uintptr(a1)))) != 0 || (func() int32 {
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
		return v5
	}()) != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&1 != 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&2) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))&2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&2 != 0 && (nox_xxx_unitIsEnemyTo_5330C0((*nox_object_t)(unsafe.Pointer(uintptr(v5))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) == 0 || nox_xxx_unitsHaveSameTeam_4EC520((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))))) != 0) {
		return 0
	} else {
		return 1
	}
}
func sub_54E810(a1 int32, a2 *float2, a3 int32) int32 {
	var a3a [4]int32
	a3a[0] = a1
	a3a[1] = 0
	a3a[2] = a3
	a3a[3] = int32(uintptr(unsafe.Pointer(a2)))
	sub_517B70(a2, unsafe.Pointer(funAddr(sub_54E850)), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(&a3a[0]))))))
	return a3a[1]
}
func sub_54E850(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  *float2
		v4  *float2
		v5  float32
		v6  *uint32
		v7  *uint32
		a2a float4
		a1a float4
	)
	if int32(int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))) >= 0 {
		if sub_54E730(int32(*(*uint32)(unsafe.Pointer(uintptr(a2)))), a1) != 0 && sub_547DB0(a1, *(**float2)(unsafe.Pointer(uintptr(a2 + 12)))) != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(a2 + 4))) = uint32(a1)
		}
	} else {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12)))) & 4) == 0 {
			v3 = *(**float2)(unsafe.Pointer(uintptr(a2 + 8)))
			a1a.field_0 = v3.field_0
			v4 = *(**float2)(unsafe.Pointer(uintptr(a2 + 12)))
			a1a.field_4 = v3.field_4
			a1a.field_8 = v4.field_0
			v5 = v4.field_4
			a2a.field_0 = *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
			a1a.field_C = v5
			a2a.field_4 = *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
			a2a.field_8 = float32(float64(*memmap.PtrInt32(0x587000, *(*uint32)(unsafe.Pointer(uintptr(v2 + 12)))*8+196184)) + float64(a2a.field_0))
			a2a.field_C = float32(float64(*memmap.PtrInt32(0x587000, *(*uint32)(unsafe.Pointer(uintptr(v2 + 12)))*8+196188)) + float64(a2a.field_4))
			if sub_427980(&a1a, &a2a) != 0 {
				v6 = *(**uint32)(unsafe.Pointer(uintptr(a2 + 8)))
				v7 = *(**uint32)(unsafe.Pointer(uintptr(a2 + 12)))
				*v7 = *v6
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
				*(*uint32)(unsafe.Pointer(uintptr(a2 + 4))) = uint32(a1)
			}
		}
	}
}
func nox_xxx_updateMonsterGenerator_54E930(a1 *uint32) int8 {
	var (
		v1  uint32
		v2  int32
		v3  int32
		v4  uint32
		v5  uint32
		v6  uint32
		v7  int32
		v8  float64
		v9  int32
		v10 *uint32
		v11 int32
		v12 int32
		v14 float32
		v15 float32
		v16 float32
		v17 float32
		v18 float32
		v19 float32
		v20 float32
		v21 float32
		v22 int64
		a2  float2
	)
	v1 = uint32(nox_game_getQuestStage_4E3CC0())
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*187)))
	v3 = nox_xxx_getQuestStage_51A930()
	if dword_5d4594_2491716 == 0 {
		v14 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("QuestHardcoreStage")))
		dword_5d4594_2491716 = uint32(nox_float2int(v14))
		v15 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("QuestHardcoreSpawnRateIncrease")))
		*memmap.PtrUint32(0x5D4594, 2491720) = uint32(nox_float2int(v15))
		*mem_getFloatPtr(0x5D4594, 2491744) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("QuestHardcoreSpawnCap")))
		v16 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("SpawnRateHighValue")))
		*memmap.PtrUint32(0x5D4594, 2491724) = uint32(nox_float2int(v16))
		v17 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("SpawnRateNormalValue")))
		*memmap.PtrUint32(0x5D4594, 2491728) = uint32(nox_float2int(v17))
		v18 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("SpawnRateLowValue")))
		*memmap.PtrUint32(0x5D4594, 2491732) = uint32(nox_float2int(v18))
		v19 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("SpawnRateVeryLowValue")))
		*memmap.PtrUint32(0x5D4594, 2491736) = uint32(nox_float2int(v19))
		v20 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("SpawnRateVeryVeryLowValue")))
		*memmap.PtrUint32(0x5D4594, 2491740) = uint32(nox_float2int(v20))
	}
	v4 = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
	if (v4 & 0x800) == 0 {
		v4 = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
		if v4&0x1000000 != 0 {
			if (v4 & 0x8020) == 0 {
				nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))))
				v5 = gameFrame() - *(*uint32)(unsafe.Pointer(uintptr(v2 + 88)))
				switch *(*uint8)(unsafe.Pointer(uintptr(v2 + v3 + 80))) {
				case 0:
					v4 = *memmap.PtrUint32(0x5D4594, 2491724)
				case 1:
					v4 = *memmap.PtrUint32(0x5D4594, 2491728)
				case 2:
					v4 = *memmap.PtrUint32(0x5D4594, 2491732)
				case 3:
					v4 = *memmap.PtrUint32(0x5D4594, 2491736)
				case 4:
					v4 = *memmap.PtrUint32(0x5D4594, 2491740)
				default:
					v4 = uint32(uintptr(unsafe.Pointer(a1)))
				}
				if v1 >= uint32(*(*int32)(unsafe.Pointer(&dword_5d4594_2491716))) {
					v6 = *memmap.PtrUint32(0x5D4594, 2491720) * (v1 - dword_5d4594_2491716 + 1)
					if v6 > v4 {
						v7 = 0
					} else {
						v7 = int32(v4 - v6)
					}
					v22 = int64(v4)
					v8 = float64(v4)
					*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&v22))), 4*0)) = uint32(v7)
					if float64(v22)/v8 < float64(*mem_getFloatPtr(0x5D4594, 2491744)) {
						v21 = float32(v8 * float64(*mem_getFloatPtr(0x5D4594, 2491744)))
						v7 = nox_float2int(v21)
					}
					v4 = uint32(v7)
				}
				if v5 > v4 {
					*((*uint8)(unsafe.Pointer(&v4))) = *(*uint8)(unsafe.Pointer(uintptr(v2 + 86)))
					if int32(uint8(v4)) < int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 87)))) {
						if int32(uint8(gameFrame()))&8 != 0 {
							v9 = 0
							v10 = (*uint32)(unsafe.Pointer(uintptr(v2 + v3*16)))
							v11 = 4
							for {
								if *v10 != 0 {
									v9++
								}
								v10 = (*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*1))
								v11--
								if v11 == 0 {
									break
								}
							}
							v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + (nox_common_randomInt_415FA0(0, v9-1)+v3*4)*4))))
							v4 = uint32(nox_xxx_mobGeneratorPick_54EBA0(a1, &a2, v12))
							if v4 == 1 {
								*((*uint8)(unsafe.Pointer(&v4))) = uint8(uint32(uintptr(unsafe.Pointer(nox_xxx_mobGeneratorSpawn_54F070(int32(uintptr(unsafe.Pointer(a1))), int32(uintptr(unsafe.Pointer(&a2))), v12)))))
								*(*uint32)(unsafe.Pointer(uintptr(v2 + 88))) = gameFrame()
							}
						}
					}
				}
			}
		}
	}
	return int8(uint8(v4))
}
func nox_xxx_mobGeneratorPick_54EBA0(a1 *uint32, a2 *float2, a4 int32) int32 {
	var (
		v3  *float32
		v4  int32
		v5  int32
		v6  int32
		v7  float32
		v8  float32
		v9  float32
		v10 int32
		v11 *byte
		v13 int32
		v14 float32
		v15 *int32
		v16 int32
		a1a float4
		v18 [32]int32
	)
	v13 = 0
	v16 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*187)))
	v3 = (*float32)(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))
	if v3 == nil {
		return 0
	}
	v15 = &v18[0]
	for {
		v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*187))))
		if (uint32(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*4))) & 0x8020) == 0 {
			v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))))
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 3680)))) & 1) == 0 {
				v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v16 + 92))))
				if v6&1 != 0 {
					if nox_xxx_calcDistance_4E6C00((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3))))))) <= 300.0 {
						return nox_xxx_mgenSetCreaturePos_54ED50(int32(uintptr(unsafe.Pointer(a1))), a2, 0, a4)
					}
				} else {
					if (v6 & 2) == 0 {
						return 0
					}
					v14 = nox_double2float(math.Sqrt(float64(int32(*(*uint16)(unsafe.Pointer(uintptr(v5 + 12))))*int32(*(*uint16)(unsafe.Pointer(uintptr(v5 + 12)))) + int32(*(*uint16)(unsafe.Pointer(uintptr(v5 + 10))))*int32(*(*uint16)(unsafe.Pointer(uintptr(v5 + 10)))))))
					if nox_xxx_calcDistance_4E6C00((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3))))))) <= float64(v14) {
						v7 = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*14)))
						v8 = *(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*14))
						a1a.field_4 = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*15)))
						a1a.field_0 = v7
						v9 = *(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*15))
						a1a.field_8 = v8
						a1a.field_C = v9
						if nox_xxx_mapTraceRay_535250(&a1a, nil, nil, 69) != 0 {
							*v15 = int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2064))))
							v13++
							v15 = (*int32)(unsafe.Add(unsafe.Pointer(v15), 4*1))
						}
					}
				}
			}
		}
		v3 = (*float32)(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))))))
		if v3 == nil {
			break
		}
	}
	if v13 == 0 {
		return 0
	}
	v10 = nox_common_randomInt_415FA0(0, v13-1)
	v11 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(v18[v10])))
	return nox_xxx_mgenSetCreaturePos_54ED50(int32(uintptr(unsafe.Pointer(a1))), a2, int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v11))), 4*514)))), a4)
}
func nox_xxx_mgenSetCreaturePos_54ED50(a1 int32, a2 *float2, a3 int32, a4 int32) int32 {
	var (
		v4  int32
		v5  int8
		v6  float32
		v7  int16
		a1a float2
		v10 float4
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 92))))&2 != 0 && a3 != 0 {
		a1a.field_0 = *(*float32)(unsafe.Pointer(uintptr(a3 + 56))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
		a1a.field_4 = *(*float32)(unsafe.Pointer(uintptr(a3 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
		if float64(a1a.field_0) == 0.0 {
			a1a.field_0 = float32(float64(a1a.field_0) + 1.0)
		}
		if float64(a1a.field_4) == 0.0 {
			a1a.field_4 = float32(float64(a1a.field_4) + 1.0)
		}
		nox_xxx_utilNormalizeVector_509F20(&a1a)
		a1a.field_0 = float32(float64(a1a.field_0)*45.0 + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))))
		a1a.field_4 = float32(float64(a1a.field_4)*45.0 + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))))
		if sub_54EF00(&a1a.field_0) == 0 {
			v10.field_8 = a1a.field_0
			v10.field_0 = *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
			v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a4 + 16))))
			v10.field_C = a1a.field_4
			v5 = 1
			v10.field_4 = *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
			if v4&0x4000 != 0 {
				v5 = 5
			}
			if nox_xxx_mapTraceRay_535250(&v10, nil, nil, v5) != 0 && nox_xxx_mapTileAllowTeleport_411A90(&a1a) == 0 {
				v6 = a1a.field_4
				a2.field_0 = a1a.field_0
				a2.field_4 = v6
				a1a.field_0 = *(*float32)(unsafe.Pointer(uintptr(a3 + 56))) - a1a.field_0
				a1a.field_4 = *(*float32)(unsafe.Pointer(uintptr(a3 + 60))) - a1a.field_4
				v7 = int16(nox_xxx_math_509ED0(&a1a))
				*(*uint16)(unsafe.Pointer(uintptr(a4 + 124))) = uint16(v7)
				*(*uint16)(unsafe.Pointer(uintptr(a4 + 126))) = uint16(v7)
				return 1
			}
		}
	}
	if sub_54EF90(45.0, a1+56, int32(uintptr(unsafe.Pointer(a2))), a4) == 1 {
		if a3 == 0 {
			return 1
		}
		v10.field_0 = *(*float32)(unsafe.Pointer(uintptr(a3 + 56))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
		v10.field_4 = *(*float32)(unsafe.Pointer(uintptr(a3 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
		v7 = int16(nox_xxx_math_509ED0((*float2)(unsafe.Pointer(&v10))))
		*(*uint16)(unsafe.Pointer(uintptr(a4 + 124))) = uint16(v7)
		*(*uint16)(unsafe.Pointer(uintptr(a4 + 126))) = uint16(v7)
		return 1
	}
	return 0
}
func sub_54EF00(a3 *float32) int32 {
	var a1 float4
	*memmap.PtrUint32(0x5D4594, 2491708) = 0
	a1.field_0 = float32(float64(*a3) - 15.0)
	a1.field_4 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))) - 15.0)
	a1.field_8 = float32(float64(*a3) + 15.0)
	a1.field_C = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))) + 15.0)
	nox_xxx_getUnitsInRect_517C10(&a1, unsafe.Pointer(funAddr(sub_54EF60)), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a3))))))
	return int32(*memmap.PtrUint32(0x5D4594, 2491708))
}
func sub_54EF60(a1 *float32, a2 int32) {
	var v2 int32
	if (uint32(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*2))) & 0x20000) == 0 {
		v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*5))))
		if (v2&0x800) == 0 && sub_547DB0(int32(uintptr(unsafe.Pointer(a1))), (*float2)(unsafe.Pointer(uintptr(a2)))) == 1 {
			*memmap.PtrUint32(0x5D4594, 2491708) = 1
		}
	}
}
func sub_54EF90(a1 float32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4  *float32
		v5  float32
		v6  int8
		v7  int32
		v8  int32
		v9  float64
		v11 float32
		v12 float4
		v13 int32
	)
	v4 = (*float32)(unsafe.Pointer(uintptr(a2)))
	v5 = *(*float32)(unsafe.Pointer(uintptr(a2 + 4)))
	v6 = 1
	v12.field_0 = *(*float32)(unsafe.Pointer(uintptr(a2)))
	v12.field_4 = v5
	*(*float32)(unsafe.Pointer(&v13)) = float32(nox_common_randomFloat_416030(-3.1415927, 3.1415927))
	v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a4 + 16))))
	if v7&0x4000 != 0 {
		v6 = 5
	}
	v8 = 0
	for {
		v9 = float64(*(*float32)(unsafe.Pointer(&v13))) + 1.8849558
		*(*float32)(unsafe.Pointer(&v13)) = float32(v9)
		v12.field_8 = float32(math.Cos(v9)*float64(a1) + float64(*v4))
		v12.field_C = float32(math.Sin(float64(*(*float32)(unsafe.Pointer(&v13))))*float64(a1) + float64(*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*1))))
		if nox_xxx_mapTraceRay_535250(&v12, nil, nil, v6) != 0 {
			if sub_54EF00(&v12.field_8) == 0 && nox_xxx_mapTileAllowTeleport_411A90((*float2)(unsafe.Pointer(&v12.field_8))) == 0 {
				break
			}
		}
		if func() int32 {
			p := &v8
			*p++
			return *p
		}() >= 32 {
			return 0
		}
	}
	v11 = v12.field_C
	*(*float32)(unsafe.Pointer(uintptr(a3))) = v12.field_8
	*(*float32)(unsafe.Pointer(uintptr(a3 + 4))) = v11
	return 1
}
func nox_xxx_mobGeneratorSpawn_54F070(a1 int32, a2 int32, a3 int32) *uint32 {
	var (
		v3     int32
		result *uint32
		v5     *uint32
		v6     int32
		v7     int32
		v8     int32
		v9     *uint16
		v10    int32
		v11    int32
		v12    float32
		v13    int32
		v14    float64
		v15    float32
		v16    float32
		v17    float32
		v18    float32
		v19    float32
		v20    int32
		a1a    float2
		v22    int4
		v23    int32
	)
	v3 = a1
	v20 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	nox_xxx_getQuestStage_51A930()
	if *memmap.PtrUint32(0x5D4594, 2491712) == 0 {
		*memmap.PtrUint32(0x5D4594, 2491712) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Beholder")))
	}
	result = (*uint32)(unsafe.Pointer(uintptr(sub_50DE80(a1, (*float32)(unsafe.Pointer(uintptr(a2)))))))
	if result != nil {
		result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(int32(*(*uint16)(unsafe.Pointer(uintptr(a3 + 4)))))))
		v5 = result
		if result != nil {
			v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*187)))
			v23 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*187)))
			nox_xxx_unitCreatureCopyUC_54F2B0(a3, int32(uintptr(unsafe.Pointer(result))))
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 484))))
			if v7 != 0 {
				v15 = float32(sub_4E40F0() * float64(*(*int32)(unsafe.Pointer(uintptr(v7 + 72)))))
				*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*139))))) = uint16(int16(nox_float2int(v15)))
				v16 = float32(sub_4E40F0() * float64(*(*int32)(unsafe.Pointer(uintptr(v7 + 72)))))
			} else {
				v8 = int32(uintptr(nox_xxx_objectTypeByIndHealthData(int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v5))), unsafe.Sizeof(uint16(0))*2)))))))
				v17 = float32(sub_4E40F0() * float64(*(*uint16)(unsafe.Pointer(uintptr(v8)))))
				*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*139))))) = uint16(int16(nox_float2int(v17)))
				v16 = float32(sub_4E40F0() * float64(*(*uint16)(unsafe.Pointer(uintptr(v8 + 4)))))
			}
			*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*139)) + 4))) = uint16(int16(nox_float2int(v16)))
			v9 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*139)))))
			if int32(*v9) == 0 {
				*v9 = 1
			}
			v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*139)))
			if int32(*(*uint16)(unsafe.Pointer(uintptr(v10 + 4)))) == 0 {
				*(*uint16)(unsafe.Pointer(uintptr(v10 + 4))) = 1
			}
			if uint32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v5))), unsafe.Sizeof(uint16(0))*2)))) == *memmap.PtrUint32(0x5D4594, 2491712) {
				*(*uint32)(unsafe.Pointer(uintptr(v23 + 1504))) = 0
			}
			if sub_50E030(v3, v5) != 0 {
				nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5)))))), nil, *(*float32)(unsafe.Pointer(uintptr(a2))), *(*float32)(unsafe.Pointer(uintptr(a2 + 4))))
				nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(uintptr(v20+64)), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5))))), unsafe.Pointer(uintptr(v3)), 2)
				v11 = nox_float2int(*(*float32)(unsafe.Pointer(uintptr(v3 + 56))))
				v12 = *(*float32)(unsafe.Pointer(uintptr(v3 + 60)))
				v22.field_0 = v11
				v13 = nox_float2int(v12)
				v14 = float64(*(*float32)(unsafe.Pointer(uintptr(a2))) - *(*float32)(unsafe.Pointer(uintptr(v3 + 56))))
				v22.field_4 = v13 - 50
				a1a.field_0 = float32(v14)
				a1a.field_4 = *(*float32)(unsafe.Pointer(uintptr(a2 + 4))) - *(*float32)(unsafe.Pointer(uintptr(v3 + 60)))
				nox_xxx_utilNormalizeVector_509F20(&a1a)
				v18 = float32(float64(a1a.field_0)*30.0 + float64(*(*float32)(unsafe.Pointer(uintptr(a2)))))
				v22.field_8 = nox_float2int(v18)
				v19 = float32(float64(a1a.field_4)*30.0 + float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 4)))))
				v22.field_C = nox_float2int(v19)
				nox_xxx_sendGeneratorSpawnFX_523830(&v22, 10)
				nox_xxx_aud_501960(1002, (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5)))))), 0, 0)
			} else {
				result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_objectFreeMem_4E38A0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5))))))))))
			}
		}
	}
	return result
}
func nox_xxx_unitCreatureCopyUC_54F2B0(a1 int32, a2 int32) {
	var (
		v2     int32
		v3     int32
		v4     *uint32
		v5     *uint32
		v6     int32
		result int16
	)
	v2 = a1
	alloc.Memcpy(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(a2 + 748))), *(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 748))), 0x898)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x10 != 0 {
		v3 = nox_xxx_inventoryGetFirst_4E7980(a1)
		if v3 != 0 {
			for {
				v4 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(int32(*(*uint16)(unsafe.Pointer(uintptr(v3 + 4)))))))
				v5 = v4
				if v4 != nil {
					if *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2))&0x13001000 != 0 {
						nox_xxx_modifSetItemAttrs_4E4990((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), *(**int32)(unsafe.Pointer(uintptr(v3 + 692))))
					}
					nox_xxx_inventoryPutImpl_4F3070((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5)))))), 0)
					if *(*uint32)(unsafe.Pointer(uintptr(v3 + 16)))&0x100 != 0 {
						v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2)))
						if uint32(v6)&0x1001000 != 0 {
							nox_xxx_NPCEquipWeapon_53A2C0(a2, (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5)))))))
						} else if uint32(v6)&0x2000000 != 0 {
							nox_xxx_NPCEquipArmor_53E520(a2, v5)
						}
					}
				}
				v3 = nox_xxx_inventoryGetNext_4E7990(v3)
				if v3 == 0 {
					break
				}
			}
			v2 = a1
		}
	}
	result = int16(*(*uint16)(unsafe.Pointer(uintptr(v2 + 124))))
	*(*uint16)(unsafe.Pointer(uintptr(a2 + 124))) = uint16(result)
	*(*uint16)(unsafe.Pointer(uintptr(a2 + 126))) = uint16(result)
}
func nox_xxx_unitUpdateMover_54F740(a1 int32) {
	var (
		v1  *float32
		v2  *uint8
		v3  int32
		v4  int32
		v5  int32
		v6  *uint32
		v7  float64
		v8  float64
		v9  int32
		v10 int8
		v11 int32
		v12 int32
		v13 float64
		v14 float64
		v15 float32
		v16 float32
	)
	v1 = (*float32)(unsafe.Pointer(uintptr(a1)))
	v2 = *(**uint8)(unsafe.Pointer(uintptr(a1 + 748)))
	if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*8))) == 0 {
		nox_xxx_unitRemoveFromUpdatable_4DA920((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		return
	}
	if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*7))) == 0 {
		v3 = nox_xxx_netGetUnitByExtent_4ED020(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*8)))))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*7))) = uint32(v3)
		if v3 == 0 {
			nox_xxx_unitRemoveFromUpdatable_4DA920((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			return
		}
	}
	if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*4))) != 0 && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*3))) == 0 {
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*3))) = uint32(uintptr(unsafe.Pointer(nox_server_getWaypointById_579C40(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*4))))))))
	}
	if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*6))) != 0 && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*5))) == 0 {
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*5))) = uint32(uintptr(unsafe.Pointer(nox_server_getWaypointById_579C40(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*6))))))))
	}
	v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*7))))
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 16))))
	if (v5&4) == 0 || v5&0x20 != 0 {
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*7))) = 0
		nox_xxx_unitRemoveFromUpdatable_4DA920((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		return
	}
	switch *v2 {
	case 0:
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 16)))&0x1000000 != 0 {
			v6 = &nox_server_getWaypointById_579C40(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*2))))).ind
			if v6 != nil {
				nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*float2)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*7)))+56))))
				v7 = float64(*((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v2))), 4*1))))
				*v2 = 1
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*3))) = uint32(uintptr(unsafe.Pointer(v6)))
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*5))) = 0
				v8 = v7 * 0.25
				*(*float32)(unsafe.Pointer(uintptr(a1 + 548))) = float32(v8)
				*(*float32)(unsafe.Pointer(uintptr(a1 + 544))) = float32(v8)
			} else {
				*v2 = 3
			}
		}
	case 1:
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 16)))&0x1000000 != 0 {
			if float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) != 0.0 && float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 84)))) != 0.0 {
				v9 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*3))))
				if float64((*(*float32)(unsafe.Pointer(uintptr(v9 + 12)))-*(*float32)(unsafe.Pointer(uintptr(a1 + 60))))**(*float32)(unsafe.Pointer(uintptr(a1 + 84)))+(*(*float32)(unsafe.Pointer(uintptr(v9 + 8)))-*(*float32)(unsafe.Pointer(uintptr(a1 + 56))))**(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) <= 0.0 {
					v10 = int8(*(*uint8)(unsafe.Pointer(uintptr(v9 + 476))))
					if int32(v10) != 0 {
						if int32(v10) == 1 {
							*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*5))) = uint32(v9)
							*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*3))) = *(*uint32)(unsafe.Pointer(uintptr(v9 + 92)))
						} else {
							for {
								v11 = nox_common_randomInt_415FA0(0, int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 476))))-1)
								v9 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*3))))
								if *(*uint32)(unsafe.Pointer(uintptr(v9 + v11*8 + 92))) != *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*5))) {
									break
								}
							}
							*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*5))) = uint32(v9)
							*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*3))) = *(*uint32)(unsafe.Pointer(uintptr(v9 + v11*8 + 92)))
						}
					} else {
						*v2 = 3
						nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(v4))), (*float2)(unsafe.Pointer(uintptr(v9+8))))
					}
				}
			}
			if int32(*v2) == 1 {
				nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*7)))))), (*float2)(unsafe.Pointer(uintptr(a1+56))))
				v12 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*3))))
				v13 = float64(*(*float32)(unsafe.Pointer(uintptr(v12 + 8))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 56))))
				v14 = float64(*(*float32)(unsafe.Pointer(uintptr(v12 + 12))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
				v15 = float32(v14)
				v16 = float32(math.Sqrt(v14*float64(v15)+v13*v13) + 0.1)
				*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*20)) = float32(v13 * float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*136))) / float64(v16))
				if float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*20))) == 0.0 {
					*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*20)) = float32(FLT_MIN)
				}
				*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*21)) = float32(float64(v15) * float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*136))) / float64(v16))
				if float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*21))) == 0.0 {
					*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*21)) = float32(FLT_MIN)
				}
			}
		} else {
			*v2 = 2
		}
	case 2:
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 16)))&0x1000000 != 0 {
			nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*float2)(unsafe.Pointer(uintptr(v4+56))))
			*v2 = 1
		}
	case 3:
		nox_xxx_unitRemoveFromUpdatable_4DA920((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		return
	default:
		return
	}
}
func nox_xxx_updateShootingTrap_54F9A0(a1 int32) int32 {
	var (
		result int32
		v2     *int32
		v3     int32
		v4     int32
	)
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	v2 = *(**int32)(unsafe.Pointer(uintptr(a1 + 748)))
	if uint32(result)&0x1000000 != 0 {
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 48)))) == 0 {
			*v2 = 0
			*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = 0
		}
		v3 = *v2
		*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 48))) = 1
		if v3 == 0 {
			sub_54FBB0(a1)
			*v2 = int32(gameFPS())
		}
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 8)))) == 1 && *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) == 0 {
			if *memmap.PtrUint32(0x5D4594, 2491780) == 0 {
				*memmap.PtrUint32(0x5D4594, 2491780) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ArrowTrap1")))
				*memmap.PtrUint32(0x5D4594, 2491784) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ArrowTrap2")))
			}
			nox_xxx_createArrowTrapProjectile_54FA80(a1, *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*3)))
			v4 = int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))
			if uint32(uint16(int16(v4))) == *memmap.PtrUint32(0x5D4594, 2491780) {
				nox_xxx_sendArrowTrapFX_5238A0((*float32)(unsafe.Pointer(uintptr(a1+56))), 1)
			} else if uint32(v4) == *memmap.PtrUint32(0x5D4594, 2491784) {
				nox_xxx_sendArrowTrapFX_5238A0((*float32)(unsafe.Pointer(uintptr(a1+56))), 2)
			}
			*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = 30
		}
		if *v2 != 0 {
			*v2--
		}
		result = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1))
		if result != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = func() int32 {
				p := &result
				*p--
				return *p
			}()
		}
	} else {
		*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 48))) = 0
	}
	return result
}
func nox_xxx_createArrowTrapProjectile_54FA80(a1 int32, a2 int32) {
	var (
		v2  float64
		v3  int32
		v4  int32
		v5  int32
		v6  int16
		v7  *int32
		v9  float32
		v10 float32
		v11 float32
	)
	v2 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 176)))) + 4.0
	v3 = int32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124)))) * 8
	v10 = float32(v2*float64(*mem_getFloatPtr(0x587000, uint32(v3)+194136)) + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))))
	v11 = float32(v2*float64(*mem_getFloatPtr(0x587000, uint32(v3)+194140)) + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))))
	v4 = int32(uintptr(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(a2))))
	v5 = v4
	if v4 != 0 {
		nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(v4))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), v10, v11)
		v6 = int16(*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))))
		*(*uint16)(unsafe.Pointer(uintptr(v5 + 124))) = uint16(v6)
		*(*uint16)(unsafe.Pointer(uintptr(v5 + 126))) = uint16(v6)
		*(*float32)(unsafe.Pointer(uintptr(v5 + 80))) = *mem_getFloatPtr(0x587000, uint32(int32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124))))*8)+194136) * *(*float32)(unsafe.Pointer(uintptr(v5 + 544)))
		*(*float32)(unsafe.Pointer(uintptr(v5 + 84))) = *mem_getFloatPtr(0x587000, uint32(int32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124))))*8)+194140) * *(*float32)(unsafe.Pointer(uintptr(v5 + 544)))
		if *memmap.PtrUint32(0x5D4594, 2491768) == 0 {
			*memmap.PtrUint32(0x5D4594, 2491768) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("MercArcherArrow")))
			*memmap.PtrUint32(0x5D4594, 2491772) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ArrowTrap1")))
			*memmap.PtrUint32(0x5D4594, 2491776) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ArrowTrap2")))
		}
		v4 = int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))
		if uint32(uint16(int16(v4))) == *memmap.PtrUint32(0x5D4594, 2491772) || uint32(v4) == *memmap.PtrUint32(0x5D4594, 2491776) {
			v7 = *(**int32)(unsafe.Pointer(uintptr(v5 + 700)))
			v9 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ArrowTrapDamage")))
			v4 = nox_float2int(v9)
			*v7 = v4
			*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1)) = v4
		}
		if uint32(a2) == *memmap.PtrUint32(0x5D4594, 2491768) {
			nox_xxx_aud_501960(889, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
	}
}
func sub_54FBB0(a1 int32) {
	var v1 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if sub_54FBF0(a1) != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 8)))) != 1 {
			*(*uint8)(unsafe.Pointer(uintptr(v1 + 8))) = 1
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 4))) = 0
		}
	} else {
		*(*uint8)(unsafe.Pointer(uintptr(v1 + 8))) = 0
	}
}
func sub_54FBF0(a3 int32) int32 {
	var (
		v1 float64
		a1 float4
	)
	a1.field_0 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a3 + 56)))) - 350.0)
	a1.field_4 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a3 + 60)))) - 350.0)
	a1.field_8 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a3 + 56)))) + 350.0)
	v1 = float64(*(*float32)(unsafe.Pointer(uintptr(a3 + 60)))) + 350.0
	*memmap.PtrUint32(0x5D4594, 2491764) = 0
	a1.field_C = float32(v1)
	nox_xxx_getUnitsInRect_517C10(&a1, unsafe.Pointer(funAddr(nox_xxx_unitIsAttackReachable_54FC50)), unsafe.Pointer(uintptr(a3)))
	return int32(*memmap.PtrUint32(0x5D4594, 2491764))
}
func nox_xxx_unitIsAttackReachable_54FC50(a1 int32, a2 int32) {
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&6 != 0 && (*(*uint32)(unsafe.Pointer(uintptr(a1 + 16)))&0x8020) == 0 && nox_xxx_unitIsEnemyTo_5330C0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*nox_object_t)(unsafe.Pointer(uintptr(a1)))) != 0 && nox_xxx_mapCheck_537110((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) != 0 {
		if nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(a2+56))), int32(*(*int16)(unsafe.Pointer(uintptr(a2 + 124)))), (*float2)(unsafe.Add(unsafe.Pointer((*float2)(unsafe.Pointer(uintptr(a1)))), unsafe.Sizeof(float2{})*7)))&1 != 0 {
			*memmap.PtrUint32(0x5D4594, 2491764) = 1
		}
	}
}
func nox_xxx_collideTrigger_54FCD0(a1 int32, a2 int32) {
	var (
		v2 *int32
		v3 int32
		v4 int32
		v5 int32
		v6 int8
		v7 int8
		v8 int32
	)
	v2 = *(**int32)(unsafe.Pointer(uintptr(a1 + 748)))
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 16)))&0x1000000 != 0 {
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 8)))) != 5 {
			if a2 != 0 {
				if nox_xxx_objectGetMass_4E4A70(a2) > 0.0 {
					v4 = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*11))
					if v4 == 0 || uint32(v4)&*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))) != 0 {
						v5 = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*12))
						if v5 == 0 || (uint32(v5)&*(*uint32)(unsafe.Pointer(uintptr(a2 + 8)))) == 0 {
							v6 = int8(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 52))))
							if int32(v6) == 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 52)))) == int32(v6) {
								v7 = int8(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 53))))
								if (int32(v7) == 0 || *(*byte)(unsafe.Pointer(uintptr(a2 + 52))) != byte(v7)) && (*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*4)) == -1 || *(*uint32)(nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer((*int32)(unsafe.Add(unsafe.Pointer(v2), 4*3))), unsafe.Pointer(uintptr(a2)), unsafe.Pointer(uintptr(a1)), 1)) != 0) {
									v8 = *v2
									*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = a2
									*((*uint8)(unsafe.Pointer(&v8))) = uint8(int8(v8 | 1))
									*v2 = v8
								}
							}
						}
					}
				}
			}
		}
	} else {
		v3 = *v2
		*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = 0
		*((*uint8)(unsafe.Pointer(&v3))) = uint8(int8(v3 & 0xFE))
		*v2 = v3
	}
}
func nox_xxx_createSpark_54FD80(a1 float32, a2 float32, a3 int32, a4 int32, a5 float32, a6 float32, a7 float32, a8 int32) *float32 {
	var (
		v8 *float32
		v9 *uint32
	)
	_ = v9
	var v10 *int32
	var v11 int32
	var v12 int32
	var v13 uint32
	var result *float32
	v8 = (*float32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("Spark"))))
	if v8 == nil {
		return nil
	}
	v9 = (*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*175))))))
	v10 = (*int32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*187))))))
	nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))), (*nox_object_t)(unsafe.Pointer(uintptr(a8))), a1, a2)
	*(*uint32)(unsafe.Pointer((*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*34)))) = gameFrame()
	*v10 = a4
	*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*1)) = a4
	*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*3)) = a3
	v11 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*2))))
	*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v11))), 1)) &= 0xDF
	v12 = int32(uint32(v11) | 0x80000)
	v13 = uint32(*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*4))) & 0xFF7FFFBF
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*2))) = uint32(v12)
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*4))) = v13
	switch a3 {
	case 0:
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*4))) = v13 | 0x40
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*2))) = uint32(v12) & 0xFFF7FFFF
	case 1:
		*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v12))), 1)) |= 0x20
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*2))) = uint32(v12)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*4))) = v13 | 0x800000
		*v9 = 3
		nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))), 28.0)
		*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*27)) = a7
		*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*29)) = 7.0
		*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*20)) = a5
		*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*21)) = a6
		return v8
	case 2:
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*4))) = v13 | 0x800040
		*v9 = 0
		nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))), 28.0)
		*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*27)) = a7
		*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*29)) = 7.0
		*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*20)) = a5
		*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*21)) = a6
		return v8
	case 4:
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*2))) = uint32(v12) & 0xFFF7FFFF
	default:
	}
	*v9 = 0
	nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))), 28.0)
	*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*27)) = a7
	*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*29)) = 0.0
	*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*20)) = a5
	*(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*21)) = a6
	result = v8
	return result
}
func sub_54FEF0(a2 int32) {
	var (
		v1  *float32
		v2  int32
		v3  int32
		v4  int32
		i   int32
		v6  int32
		v7  float32
		v8  float32
		v9  float32
		v10 float32
		v11 int32
		a1  int2
		a2a int32
	)
	v1 = (*float32)(unsafe.Pointer(uintptr(a2)))
	if (*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))) & 0x400000) == 0 {
		v7 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 232)))) * 0.043478262)
		a2a = nox_float2int(v7)
		v8 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*59))) * 0.043478262)
		v2 = nox_float2int(v8)
		v9 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*60))) * 0.043478262)
		v3 = nox_float2int(v9)
		v10 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*61))) * 0.043478262)
		v4 = nox_float2int(v10)
		v11 = v4
		for i = v2; i <= v4; i++ {
			v6 = a2a
			a1.field_4 = i
			if a2a <= v3 {
				for {
					a1.field_0 = v6
					if sub_54FFC0(&a1, int32(uintptr(unsafe.Pointer(v1)))) != 0 {
						sub_548100(&a1, int32(uintptr(unsafe.Pointer(v1))))
					}
					v6++
					if v6 > v3 {
						break
					}
				}
				v4 = v11
			}
		}
	}
}
func sub_54FFC0(a1 *int2, a2 int32) int32 {
	var (
		v2  int32
		v3  int32
		v4  int32
		v6  int32
		v7  int32
		v8  uint8
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int8
		a5  int32
		a4  int32
		v16 int32
		a1a float2
		a7  float2
	)
	v2 = a2
	a4 = 0
	a5 = 0
	v16 = 0
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
	if (v3&0x4000) == 0 || *(*uint32)(unsafe.Pointer(uintptr(a2 + 172))) != 2 || (func() bool {
		v13 = 0
		return float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 176)))) > 9.0
	}()) {
		v13 = 64
	}
	v4 = int32(uint8(sub_57B500(a1.field_0, a1.field_4, v13)))
	if v4 == math.MaxUint8 {
		return 0
	}
	v6 = a1.field_0
	v7 = a1.field_4
	a1a.field_0 = float32(float64(a1.field_0 * 23))
	v8 = uint8(table_313272[v4].f0)
	a1a.field_4 = float32(float64(v7 * 23))
	if int32(v8) != 0 {
		if int32(*memmap.PtrUint8(0x587000, uint32(v4)+292496))&2 != 0 && int32(sub_57B500(v6-1, v7-1, v13)) == -1 {
			a4 = 1
		}
		if int32(*memmap.PtrUint8(0x587000, uint32(v4)+292496))&4 != 0 && int32(sub_57B500(a1.field_0+1, a1.field_4+1, v13)) == -1 {
			a5 = 1
		}
		if v4 == 7 || v4 == 10 {
			a5 = 1
		} else if v4 == 8 || v4 == 9 {
			a4 = 1
			v9 = sub_550280(int32(uintptr(unsafe.Pointer(&a1a))), table_313272[v4].f4, table_313272[v4].f8, 1, a5, a2+64, int32(uintptr(unsafe.Pointer(&a7))))
			goto LABEL_21
		}
		v9 = sub_550280(int32(uintptr(unsafe.Pointer(&a1a))), table_313272[v4].f4, table_313272[v4].f8, a4, a5, a2+64, int32(uintptr(unsafe.Pointer(&a7))))
	LABEL_21:
		if v9 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
				v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
				if v10 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v10 + 296))) = uint32(uintptr(nox_server_getWallAtGrid_410580(a1.field_0, a1.field_4)))
				}
				v2 = a2
			}
			if sub_550380(v4, v2, &a7) != 0 {
				v16 = 1
			}
		}
	}
	if table_313272[v4].f12 != 0 {
		if int32(*memmap.PtrUint8(0x587000, uint32(v4)+292496))&8 != 0 && int32(sub_57B500(a1.field_0-1, a1.field_4+1, v13)) == -1 {
			a4 = 1
		}
		if int32(*memmap.PtrUint8(0x587000, uint32(v4)+292496))&1 != 0 && int32(sub_57B500(a1.field_0+1, a1.field_4-1, v13)) == -1 {
			a5 = 1
		}
		if v4 == 7 || v4 == 8 {
			a4 = 1
		} else if v4 == 9 || v4 == 10 {
			v11 = sub_5502F0(&a1a, table_313272[v4].f16, table_313272[v4].f20, a4, 1, (*float2)(unsafe.Pointer(uintptr(v2+64))), &a7)
			goto LABEL_42
		}
		v11 = sub_5502F0(&a1a, table_313272[v4].f16, table_313272[v4].f20, a4, a5, (*float2)(unsafe.Pointer(uintptr(v2+64))), &a7)
	LABEL_42:
		if v11 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 8))))&4 != 0 {
				v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 748))))
				if v12 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v12 + 296))) = uint32(uintptr(nox_server_getWallAtGrid_410580(a1.field_0, a1.field_4)))
				}
			}
			if sub_550380(v4, v2, &a7) != 0 {
				v16 = 1
			}
		}
	}
	return v16
}
func sub_550280(a1 int32, a2 float32, a3 float32, a4 int32, a5 int32, a6 int32, a7 int32) int32 {
	var v7 float64
	v7 = float64(*(*float32)(unsafe.Pointer(uintptr(a6)))-*(*float32)(unsafe.Pointer(uintptr(a1)))+*(*float32)(unsafe.Pointer(uintptr(a6 + 4)))-*(*float32)(unsafe.Pointer(uintptr(a1 + 4)))) * 0.70709997 * 0.70709997
	if v7 < float64(a2) {
		if a4 == 0 {
			return 0
		}
		v7 = float64(a2)
	}
	if v7 > float64(a3) {
		if a5 == 0 {
			return 0
		}
		v7 = float64(a3)
	}
	*(*float32)(unsafe.Pointer(uintptr(a7))) = float32(v7 + float64(*(*float32)(unsafe.Pointer(uintptr(a1)))))
	*(*float32)(unsafe.Pointer(uintptr(a7 + 4))) = float32(v7 + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 4)))))
	return 1
}
func sub_5502F0(a1 *float2, a2 float32, a3 float32, a4 int32, a5 int32, a6 *float2, a7 *float2) int32 {
	var v7 float64
	v7 = 23.0 - (float64(a6.field_4-a1.field_4)*0.70709997-(float64(a6.field_0)-(float64(a1.field_0)+23.0))*0.70709997)*0.70709997
	if v7 < float64(a2) {
		if a4 == 0 {
			return 0
		}
		v7 = float64(a2)
	}
	if v7 > float64(a3) {
		if a5 == 0 {
			return 0
		}
		v7 = float64(a3)
	}
	a7.field_0 = float32(v7 + float64(a1.field_0))
	a7.field_4 = float32(23.0 - v7 + float64(a1.field_4))
	return 1
}
func sub_550380(a1 int32, a2 int32, a3 *float2) int32 {
	var (
		v3  *float32
		v4  float64
		v5  float64
		v6  float64
		v7  float64
		v8  float64
		v9  float64
		v11 float32
		v12 float32
		v13 float2
		v14 float32
		v15 float32
		v16 float32
	)
	v3 = (*float32)(unsafe.Pointer(uintptr(a2)))
	v4 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 64))) - a3.field_0)
	v5 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 68))) - a3.field_4)
	v15 = float32(v5)
	v6 = math.Sqrt(v5*float64(v15) + v4*v4)
	v14 = float32(v6)
	if v6 == 0.0 {
		v14 = 0.0099999998
	}
	if float64(v14) >= float64(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*44))) {
		return 0
	}
	v13.field_0 = float32(v4 / float64(v14))
	v7 = float64(v15 / v14)
	v13.field_4 = float32(v7)
	v8 = -v7*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*21))) + float64(-v13.field_0**(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*20)))
	v16 = float32(v8)
	if v8 > 0.0 && sub_550480(int32(uintptr(unsafe.Pointer(v3)))) == 0 {
		*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*20)) = v16*v13.field_0 + *(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*20))
		*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*21)) = v16*v13.field_4 + *(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*21))
	}
	v9 = float64((*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*44)) - v14) * *(*float32)(unsafe.Pointer(&dword_587000_292492)))
	v12 = float32(v9 * float64(v13.field_4))
	v11 = float32(v9 * float64(v13.field_0))
	sub_548600((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), v11, v12)
	nox_xxx_collSysAddCollision_548630(int32(uintptr(unsafe.Pointer(v3))), 0, &v13)
	return 1
}
func sub_550480(a1 int32) int32 {
	var v1 int32
	v1 = int32(*memmap.PtrUint32(0x5D4594, 2491788))
	if *memmap.PtrUint32(0x5D4594, 2491788) == 0 {
		v1 = nox_xxx_getNameId_4E3AA0(internCStr("GameBall"))
		*memmap.PtrUint32(0x5D4594, 2491788) = uint32(v1)
	}
	return bool2int32(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) == v1)
}
func sub_5504B0(a2 int32) {
	var (
		v1  *float32
		v2  int32
		v3  int32
		v4  int32
		i   int32
		v6  int32
		v7  float32
		v8  float32
		v9  float32
		v10 float32
		v11 int32
		a1  int2
		a2a int32
	)
	v1 = (*float32)(unsafe.Pointer(uintptr(a2)))
	if (*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))) & 0x400000) == 0 {
		v7 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 232)))) * 0.043478262)
		a2a = nox_float2int(v7)
		v8 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*59))) * 0.043478262)
		v2 = nox_float2int(v8)
		v9 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*60))) * 0.043478262)
		v3 = nox_float2int(v9)
		v10 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*61))) * 0.043478262)
		v4 = nox_float2int(v10)
		v11 = v4
		for i = v2; i <= v4; i++ {
			v6 = a2a
			a1.field_4 = i
			if a2a <= v3 {
				for {
					a1.field_0 = v6
					if sub_550580(&a1, v1) != 0 {
						sub_548100(&a1, int32(uintptr(unsafe.Pointer(v1))))
					}
					v6++
					if v6 > v3 {
						break
					}
				}
				v4 = v11
			}
		}
	}
}
func sub_550580(a1 *int2, a2 *float32) int32 {
	var (
		v2  int32
		v3  int32
		v5  float64
		v6  float64
		v7  *uint8
		v8  float64
		v9  int8
		v10 float64
		a5  float2
		a1a float2
		a2a float2
		a3  float2
		a4  float4
		v16 float32
	)
	v2 = 0
	v3 = int32(uint8(sub_57B500(a1.field_0, a1.field_4, 64)))
	if v3 == math.MaxUint8 {
		return 0
	}
	v5 = float64(a1.field_0 * 23)
	v6 = float64(a1.field_4 * 23)
	v7 = (*uint8)(memmap.PtrOff(0x587000, uint32(v3*24)+292520))
	a1a.field_0 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*17))+*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*16))) * 0.70710677)
	a1a.field_4 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*17))-*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*16))) * 0.70710677)
	a3.field_0 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*19))+*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*18))) * 0.70710677)
	a3.field_4 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*19))-*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*18))) * 0.70710677)
	v8 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*46))) * 0.5
	a4.field_0 = float32(float64(a1a.field_0) - v8)
	v16 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*47))) * 0.5)
	a4.field_4 = a1a.field_4 - v16
	a4.field_8 = float32(v8 + float64(a1a.field_0))
	a4.field_C = v16 + a1a.field_4
	a2a.field_0 = float32((v6 + v5) * 0.70710677)
	a2a.field_4 = float32((v6 - v5) * 0.70710677)
	v9 = sub_550CB0(&a1a, &a2a)
	if int32(*v7) != 0 {
		if (int32(uint8(v9)) & int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 1)))) == 0 {
			a5.field_0 = float32(float64(a2a.field_0) + 16.263456)
			v10 = float64(a2a.field_4) - 16.263456
			a5.field_4 = float32(v10)
			a5.field_4 = float32(v10 + float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v7))), unsafe.Sizeof(float32(0))*1)))))
			if sub_550A10(int32(uintptr(unsafe.Pointer(a2))), &a1a, &a3, &a4, &a5, *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v7))), unsafe.Sizeof(float32(0))*2)))) != 0 {
				v2 = 1
			}
		}
	}
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 12))) != 0 && (int32(uint8(v9))&int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 13)))) == 0 {
		a5 = a2a
		a5.field_0 = a2a.field_0 + *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v7))), unsafe.Sizeof(float32(0))*4)))
		if sub_550760(int32(uintptr(unsafe.Pointer(a2))), &a1a, &a3, &a4, &a5, *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v7))), unsafe.Sizeof(float32(0))*5)))) != 0 {
			v2 = 1
		}
	}
	return v2
}
func sub_550760(a1 int32, a2 *float2, a3 *float2, a4 *float4, a5 *float2, a6 float32) int32 {
	var (
		v6  *float2
		v7  *float4
		v8  float64
		v9  float64
		v10 float64
		v11 float64
		v12 float64
		v13 float32
		v14 float64
		v15 float32
		v16 float64
		v17 float32
		v18 float64
		v19 float64
		v20 float64
		v21 float64
		v23 float2
		v24 float2
		v25 float2
		v26 float32
		v27 float32
		v28 float32
		v29 float32
		v30 float32
		v31 float32
		v32 float32
		v33 float32
	)
	v6 = a5
	v7 = a4
	if float64(a4.field_0) <= float64(a5.field_0) {
		v30 = a5.field_0
	} else {
		v30 = a4.field_0
	}
	v8 = float64(a6 + v6.field_0)
	if float64(a4.field_8) >= v8 {
		v27 = float32(v8)
	} else {
		v27 = a4.field_8
	}
	if float64(v30) > v8 || float64(v27) < float64(v6.field_0) {
		return 0
	}
	v9 = float64(a2.field_4 - v6.field_4)
	v10 = float64(a3.field_4 - v6.field_4)
	if v10*v9 < 0.0 {
		v11 = float64(v6.field_4)
		v32 = float32(v10)
		if float64(v32) >= 0.0 {
			v12 = v11 + 2.0
		} else {
			v12 = v11 - 2.0
		}
		a2.field_4 = float32(v12)
		*(*float32)(unsafe.Pointer(uintptr(a1 + 64))) = float32(float64(a2.field_0-a2.field_4) * 0.70710677)
		*(*float32)(unsafe.Pointer(uintptr(a1 + 68))) = float32(float64(a2.field_0+a2.field_4) * 0.70710677)
		v7.field_4 = float32(float64(a2.field_4) - float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 188))))*0.5)
		v7.field_C = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 188))))*0.5 + float64(a2.field_4))
		v9 = float64(a2.field_4 - v6.field_4)
	}
	if float64(v7.field_4) > float64(v6.field_4) || float64(v7.field_C) < float64(v6.field_4) {
		return 0
	}
	v26 = (v27 - v30) / (v7.field_8 - v7.field_0)
	v31 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 84)))-*(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) * 0.70710677)
	if v9 >= 0.0 {
		v28 = v6.field_4 - v7.field_4
		v15 = *(*float32)(unsafe.Pointer(&dword_587000_292492))
		v14 = float64(v15 * v28)
	} else {
		v28 = v7.field_C - v6.field_4
		v13 = *(*float32)(unsafe.Pointer(&dword_587000_292492))
		v14 = float64(-(v13 * v28))
	}
	v33 = float32(v14)
	v16 = nox_xxx_objectGetMass_4E4A70(a1)
	v17 = *(*float32)(unsafe.Pointer(&dword_587000_292492))
	v18 = (math.Sqrt(v16*float64(v17)*4.0)*float64(-v31)*0.5 + float64(v33)) * float64(v26)
	v23.field_0 = float32(v18 * (-0.70710677))
	v23.field_4 = float32(v18 * 0.70710677)
	if float64(v28) >= 0.0 {
		v19 = 0.70710677
		v24.field_0 = -0.70710677
	} else {
		v19 = -0.70710677
		v24.field_0 = 0.70710677
	}
	v20 = float64(v24.field_0**(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) + v19*float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 84))))
	if v20 < 0.0 {
		*(*float32)(unsafe.Pointer(uintptr(a1 + 80))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) - v20*float64(v24.field_0))
		*(*float32)(unsafe.Pointer(uintptr(a1 + 84))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 84)))) - v20*v19)
	}
	v21 = -v19
	v25.field_0 = float32(v21)
	v29 = float32(v21*float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) + float64(v24.field_0**(*float32)(unsafe.Pointer(uintptr(a1 + 84)))))
	v23.field_0 = float32(float64(v23.field_0) - nox_xxx_objectGetMass_4E4A70(a1)*float64(v29)*float64(v25.field_0)*0.69999999)
	v23.field_4 = float32(float64(v23.field_4) - nox_xxx_objectGetMass_4E4A70(a1)*float64(v29)*float64(v24.field_0)*0.69999999)
	sub_548600((*nox_object_t)(unsafe.Pointer(uintptr(a1))), v23.field_0, v23.field_4)
	nox_xxx_collSysAddCollision_548630(a1, 0, &v23)
	return 1
}
func sub_550A10(a1 int32, a2 *float2, a3 *float2, a4 *float4, a5 *float2, a6 float32) int32 {
	var (
		v6  *float2
		v7  *float4
		v8  float64
		v9  float64
		v10 float64
		v11 float64
		v12 float64
		v13 float64
		v14 float32
		v15 float64
		v16 float32
		v17 float64
		v18 float32
		v19 float64
		v20 float64
		v21 float64
		v22 float64
		v24 float2
		v25 float2
		v26 float2
		v27 float32
		v28 float32
		v29 float32
		v30 float32
		v31 float32
		v32 float32
		v33 float32
		v34 float32
	)
	v6 = a5
	v7 = a4
	if float64(a5.field_4) >= float64(a4.field_4) {
		v8 = float64(a5.field_4)
	} else {
		v8 = float64(a4.field_4)
	}
	v31 = float32(v8)
	v9 = float64(a6 + v6.field_4)
	if float64(a4.field_C) >= v9 {
		v28 = float32(v9)
	} else {
		v28 = a4.field_C
	}
	if float64(v31) > v9 || float64(v28) < float64(v6.field_4) {
		return 0
	}
	v10 = float64(a2.field_0 - v6.field_0)
	v11 = float64(a3.field_0 - v6.field_0)
	if v11*v10 < 0.0 {
		v12 = float64(v6.field_0)
		v33 = float32(v11)
		if float64(v33) >= 0.0 {
			v13 = v12 + 2.0
		} else {
			v13 = v12 - 2.0
		}
		a2.field_0 = float32(v13)
		*(*float32)(unsafe.Pointer(uintptr(a1 + 64))) = float32(float64(a2.field_0-a2.field_4) * 0.70710677)
		*(*float32)(unsafe.Pointer(uintptr(a1 + 68))) = float32(float64(a2.field_4+a2.field_0) * 0.70710677)
		v7.field_0 = float32(float64(a2.field_0) - float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 184))))*0.5)
		v7.field_8 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 184))))*0.5 + float64(a2.field_0))
		v10 = float64(a2.field_0 - v6.field_0)
	}
	if float64(v7.field_0) > float64(v6.field_0) || float64(v7.field_8) < float64(v6.field_0) {
		return 0
	}
	v27 = (v28 - v31) / (v7.field_C - v7.field_4)
	v32 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80)))+*(*float32)(unsafe.Pointer(uintptr(a1 + 84)))) * 0.70710677)
	if v10 >= 0.0 {
		v29 = v6.field_0 - v7.field_0
		v16 = *(*float32)(unsafe.Pointer(&dword_587000_292492))
		v15 = float64(v16 * v29)
	} else {
		v29 = v7.field_8 - v6.field_0
		v14 = *(*float32)(unsafe.Pointer(&dword_587000_292492))
		v15 = float64(-(v14 * v29))
	}
	v34 = float32(v15)
	v17 = nox_xxx_objectGetMass_4E4A70(a1)
	v18 = *(*float32)(unsafe.Pointer(&dword_587000_292492))
	v19 = (math.Sqrt(v17*float64(v18)*4.0)*float64(-v32)*0.5 + float64(v34)) * float64(v27) * 0.70710677
	v24.field_0 = float32(v19)
	v24.field_4 = float32(v19)
	if float64(v29) >= 0.0 {
		v20 = 0.70710677
		v25.field_0 = 0.70710677
	} else {
		v20 = -0.70710677
		v25.field_0 = -0.70710677
	}
	v21 = float64(v25.field_0**(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) + v20*float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 84))))
	if v21 < 0.0 {
		*(*float32)(unsafe.Pointer(uintptr(a1 + 80))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) - v21*float64(v25.field_0))
		*(*float32)(unsafe.Pointer(uintptr(a1 + 84))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 84)))) - v21*v20)
	}
	v22 = -v20
	v26.field_0 = float32(v22)
	v30 = float32(v22*float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) + float64(v25.field_0**(*float32)(unsafe.Pointer(uintptr(a1 + 84)))))
	v24.field_0 = float32(float64(v24.field_0) - nox_xxx_objectGetMass_4E4A70(a1)*float64(v30)*float64(v26.field_0)*0.69999999)
	v24.field_4 = float32(float64(v24.field_4) - nox_xxx_objectGetMass_4E4A70(a1)*float64(v30)*float64(v25.field_0)*0.69999999)
	sub_548600((*nox_object_t)(unsafe.Pointer(uintptr(a1))), v24.field_0, v24.field_4)
	nox_xxx_collSysAddCollision_548630(a1, 0, &v24)
	return 1
}
func sub_550CB0(a1 *float2, a2 *float2) int8 {
	var (
		v2 float64
		v3 int8 = 0
		v4 bool
	)
	_ = v4
	var v5 int8
	_ = v5
	var v6 bool
	_ = v6
	var v7 int8
	var v8 bool
	var v9 bool
	var result int8
	var v11 float32
	v11 = a1.field_0 - a2.field_0
	v2 = float64(a1.field_4 - a2.field_4)
	v4 = float64(v11) < 16.263456
	v5 = 0
	v6 = float64(v11) == 16.263456
	v7 = v3
	v8 = v2 < 0.0
	v9 = v2 == 0.0
	if int32(v7)&0x41 != 0 {
		result = 8
		if v8 || v9 {
			result = 1
		}
	} else if v8 || v9 {
		result = 2
	} else {
		result = 4
	}
	return result
}
func nox_xxx_collisionCheckCircleCircle_550D00(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  float64
		v6  float64
		v7  int32
		v8  float32
		v9  float32
		v10 float32
		v11 float64
		v12 float64
		v13 float64
		v14 float64
		v15 float32
		v16 float32
		v17 float32
		v18 float2
		a1a float4
		v20 float32
		v21 float32
		v22 float32
		v23 float32
		v24 float32
	)
	v2 = a1
	v3 = a2
	v18.field_0 = *(*float32)(unsafe.Pointer(uintptr(a2 + 64))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 64)))
	v18.field_4 = *(*float32)(unsafe.Pointer(uintptr(a2 + 68))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 68)))
	if float64(v18.field_0) == 0.0 && float64(v18.field_4) == 0.0 {
		v4 = nox_common_randomInt_415FA0(0, 3)
		v18.field_0 = *mem_getFloatPtr(0x587000, uint32(v4*8)+292784)
		v18.field_4 = *mem_getFloatPtr(0x587000, uint32(v4*8)+292788)
	}
	v5 = math.Sqrt(float64(v18.field_4*v18.field_4 + v18.field_0*v18.field_0))
	v22 = float32(v5)
	if v5 == 0.0 {
		v22 = 0.0099999998
	}
	v6 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 176))) + *(*float32)(unsafe.Pointer(uintptr(v3 + 176))) - v22)
	v20 = float32(v6)
	if v6 > 0.0 {
		v7 = 1
		if (*(*uint32)(unsafe.Pointer(uintptr(v2 + 8)))&0x2204) == 0 || (*(*uint32)(unsafe.Pointer(uintptr(v3 + 8)))&0x2204) == 0 || (func() int32 {
			v8 = *(*float32)(unsafe.Pointer(uintptr(v2 + 56)))
			v9 = *(*float32)(unsafe.Pointer(uintptr(v3 + 56)))
			a1a.field_4 = *(*float32)(unsafe.Pointer(uintptr(v2 + 60)))
			a1a.field_0 = v8
			v10 = *(*float32)(unsafe.Pointer(uintptr(v3 + 60)))
			a1a.field_8 = v9
			a1a.field_C = v10
			return nox_xxx_mapTraceRay_535250(&a1a, nil, nil, 0)
		}()) != 0 {
			nox_xxx_collSysAddCollision_548630(v3, uint32(v2), &v18)
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 16))))&8) == 8 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 16))))&8) == 8 {
				v7 = 0
			}
			if ((int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 8))))&6) == 0 || (*(*uint32)(unsafe.Pointer(uintptr(v3 + 16)))&0x2000) != 0x2000) && v7 != 0 {
				a1a.field_0 = v18.field_0 / v22
				a1a.field_4 = v18.field_4 / v22
				v15 = *(*float32)(unsafe.Pointer(uintptr(v2 + 80))) - *(*float32)(unsafe.Pointer(uintptr(v3 + 80)))
				v17 = *(*float32)(unsafe.Pointer(uintptr(v2 + 84))) - *(*float32)(unsafe.Pointer(uintptr(v3 + 84)))
				v23 = float32(nox_xxx_objectGetMass_4E4A70(v2))
				if nox_xxx_objectGetMass_4E4A70(v3) <= float64(v23) {
					v11 = nox_xxx_objectGetMass_4E4A70(v3)
				} else {
					v11 = nox_xxx_objectGetMass_4E4A70(v2)
				}
				v12 = float64(*(*float32)(unsafe.Pointer(&dword_587000_292488)) * v20)
				v21 = float32(-(v12 * float64(a1a.field_0)))
				v24 = float32(-(v12 * float64(a1a.field_4)))
				if (int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 8))))&6) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 8))))&6) == 0 {
					v13 = float64(-a1a.field_4)
					v14 = v13*float64(v15) + float64(v17*a1a.field_0)
					v16 = float32(v14)
					v21 = float32(float64(v21) - v14*v13*v11*0.69999999)
					v24 = float32(float64(v24) - float64(v16)*v11*float64(a1a.field_0)*0.69999999)
				}
				sub_548600((*nox_object_t)(unsafe.Pointer(uintptr(v2))), v21, v24)
			}
			if *(*uint32)(unsafe.Pointer(uintptr(v2 + 16)))&0x8000000 != 0 {
				nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))) &= 0xF7FFFFFF
			}
			if *(*uint32)(unsafe.Pointer(uintptr(v3 + 16)))&0x8000000 != 0 {
				nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
				*(*uint32)(unsafe.Pointer(uintptr(v3 + 16))) &= 0xF7FFFFFF
			}
		}
	}
}
func sub_550F80(a1 *float32, a2 int32) {
	var (
		v2  *float32
		v3  int32
		v4  float64
		v5  float64
		v6  int32
		v7  float64
		v8  float64
		v9  float64
		v10 float64
		v11 float64
		v12 float32
		v13 float64
		v14 float32
		v15 float64
		v16 float2
		v17 float32
		v18 float32
		v19 float32
		v20 float32
		v21 float32
		v22 float32
		v23 float32
		v24 float32
		v25 float32
		v26 float32
		v27 float32
		v28 float32
		v29 float32
		v30 float32
	)
	v2 = a1
	v3 = 1
	v17 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*16))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*17))) * 0.70710677)
	v18 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*17))-*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*16))) * 0.70710677)
	v19 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 64)))+*(*float32)(unsafe.Pointer(uintptr(a2 + 68)))) * 0.70710677)
	v20 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 68)))-*(*float32)(unsafe.Pointer(uintptr(a2 + 64)))) * 0.70710677)
	v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*46))) * 0.5
	v21 = float32(float64(v17) - v4)
	v29 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*47))) * 0.5)
	v22 = v18 - v29
	v23 = float32(v4 + float64(v17))
	v24 = v29 + v18
	v5 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 184)))) * 0.5
	v25 = float32(float64(v19) - v5)
	v30 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 188)))) * 0.5)
	v26 = v20 - v30
	v27 = float32(v5 + float64(v19))
	v28 = v30 + v20
	if float64(v21) <= float64(v27) && float64(v22) <= float64(v28) && float64(v23) >= float64(v25) && float64(v24) >= float64(v26) {
		v16.field_0 = *(*float32)(unsafe.Pointer(uintptr(a2 + 64))) - *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*16))
		v16.field_4 = *(*float32)(unsafe.Pointer(uintptr(a2 + 68))) - *(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*17))
		nox_xxx_collSysAddCollision_548630(a2, uint32(uintptr(unsafe.Pointer(v2))), &v16)
		if (int32(uint8(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*4))))&8) == 8 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 16))))&8) == 8 {
			v3 = 0
		}
		if (int32(uint8(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*2))))&6) == 0 || (func() bool {
			v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
			return (v6 & 0x2000) == 0
		}()) {
			if v3 != 0 {
				if float64(v21) <= float64(v25) {
					v7 = float64(v25)
				} else {
					v7 = float64(v21)
				}
				if float64(v23) >= float64(v27) {
					v8 = float64(v27)
				} else {
					v8 = float64(v23)
				}
				if float64(v22) <= float64(v26) {
					v9 = float64(v26)
				} else {
					v9 = float64(v22)
				}
				if float64(v24) >= float64(v28) {
					v10 = float64(v28)
				} else {
					v10 = float64(v24)
				}
				v16.field_0 = float32(v8 - v7)
				v16.field_4 = float32(v10 - v9)
				if float64(v16.field_0) >= float64(v16.field_4) {
					if float64(v18) >= float64(v20) {
						v20 = v16.field_4
					} else {
						v20 = -v16.field_4
					}
					v11 = 0.0
				} else {
					v11 = float64(v16.field_0)
					if float64(v17) < float64(v19) {
						v11 = -v11
					}
					v20 = 0.0
				}
				v12 = *(*float32)(unsafe.Pointer(&dword_587000_292488))
				v13 = v11 * float64(v12)
				v14 = *(*float32)(unsafe.Pointer(&dword_587000_292488))
				v15 = float64(v20 * v14)
				v19 = float32((v13 - v15) * 0.70710677)
				v20 = float32((v15 + v13) * 0.70710677)
				sub_548600((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), v19, v20)
			}
		}
		if uint32(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*4)))&0x8000000 != 0 {
			nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))))
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*4))) &= 0xF7FFFFFF
		}
		if *(*uint32)(unsafe.Pointer(uintptr(a2 + 16)))&0x8000000 != 0 {
			nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
			*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) &= 0xF7FFFFFF
		}
	}
}
func sub_551250(a1 uint32, a2 *float32, a3 int32) {
	var (
		v3  uint32
		v4  *float32
		v5  int32
		v6  float64
		v7  float64
		v8  float64
		v9  int32
		v10 float64
		v11 float64
		v12 float64
		v13 float64
		v14 float64
		v15 float64
		v16 float64
		v17 float32
		v18 float64
		v19 float32
		v20 float64
		v21 int32
		v22 int32
		v23 *float32
		v24 int32
		v25 float64
		v26 float64
		v27 float32
		v28 float32
		v29 float2
		v30 float32
		v31 float32
		a4  float2
		v33 float2
		a2a float4
		a3a float4
		a1a float4
		v37 float4
		v38 float32
		v39 float32
		v40 float32
		v41 float32
	)
	v3 = a1
	v4 = a2
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v6 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 68)))+*(*float32)(unsafe.Pointer(uintptr(a1 + 64)))) * 0.70710677
	v29.field_4 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 68)))-*(*float32)(unsafe.Pointer(uintptr(a1 + 64)))) * 0.70710677)
	v7 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*17)) + *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*16)))
	a1a.field_4 = v29.field_4
	v30 = float32(v7 * 0.70710677)
	v31 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*17))-*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*16))) * 0.70710677)
	v8 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*46))) * 0.5
	a3a.field_0 = float32(float64(v30) - v8)
	v38 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*47))) * 0.5)
	a3a.field_4 = v31 - v38
	a3a.field_8 = float32(v8 + float64(v30))
	a3a.field_C = v38 + v31
	a1a.field_0 = float32(v6)
	v9 = int32(*(*int16)(unsafe.Pointer(uintptr(v5 + 40)))) + 128
	if v9 >= 256 {
		v9 = int32(*(*int16)(unsafe.Pointer(uintptr(v5 + 40)))) - 128
	}
	a1a.field_8 = float32(float64(*mem_getFloatPtr(0x587000, uint32(v9*8)+194136))*32.0 + v6)
	a1a.field_C = float32(float64(*mem_getFloatPtr(0x587000, uint32(v9*8)+194140))*32.0 + float64(v29.field_4))
	if v6 >= float64(a1a.field_8) {
		a2a.field_8 = float32(v6)
		a2a.field_0 = a1a.field_8
	} else {
		a2a.field_0 = float32(v6)
		a2a.field_8 = a1a.field_8
	}
	if float64(v29.field_4) >= float64(a1a.field_C) {
		a2a.field_4 = a1a.field_C
		a2a.field_C = v29.field_4
	} else {
		a2a.field_C = a1a.field_C
		a2a.field_4 = v29.field_4
	}
	if float64(a2a.field_0) <= float64(a3a.field_8) && float64(a2a.field_4) <= float64(a3a.field_C) && float64(a2a.field_8) >= float64(a3a.field_0) && float64(a2a.field_C) >= float64(a3a.field_4) {
		if sub_551960(&a1a, &a2a, &a3a, &a4) != 0 {
			v10 = float64(v30 - a4.field_0)
			v11 = float64(v31 - a4.field_4)
			v29.field_4 = float32(v11)
			v12 = math.Sqrt(v11*float64(v29.field_4) + v10*v10)
			v39 = float32(v12)
			if v12 != 0.0 {
				v37.field_0 = v30
				v37.field_4 = v31
				*(*float2)(unsafe.Pointer(&v37.field_8)) = a4
				v29.field_0 = float32(v10 / float64(v39))
				v29.field_4 = v29.field_4 / v39
				if sub_5516A0(&v37, &a3a, &v33, 1, 1) == 1 {
					v13 = math.Sqrt(float64((v33.field_4-v31)*(v33.field_4-v31) + (v33.field_0-v30)*(v33.field_0-v30)))
					if v13 != 0.0 {
						v14 = float64(v29.field_0-v29.field_4) * 0.70710677
						v29.field_4 = float32(float64(v29.field_4+v29.field_0) * 0.70710677)
						v29.field_0 = float32(v14)
						v15 = v13 - float64(v39)
						v40 = float32(v15)
						if v15 > 0.0 {
							nox_xxx_collSysAddCollision_548630(int32(uintptr(unsafe.Pointer(a2))), v3, &v29)
							*(*uint32)(unsafe.Pointer(uintptr(v5 + 44))) = gameFrame()
							if a3 == 1 {
								v41 = -(v29.field_4 * *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*21))) - v29.field_0**(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*20))
								v16 = nox_xxx_objectGetMass_4E4A70(int32(uintptr(unsafe.Pointer(v4))))
								v17 = *(*float32)(unsafe.Pointer(&dword_587000_292492))
								v18 = math.Sqrt(v16 * float64(v17) * 4.0)
								v19 = *(*float32)(unsafe.Pointer(&dword_587000_292492))
								v20 = v18*float64(v41)*0.25 + float64(v40*v19)
								v28 = float32(v20 * float64(v29.field_4))
								v27 = float32(v20 * float64(v29.field_0))
								sub_548600((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), v27, v28)
							}
							v21 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*4))))
							if uint32(v21)&0x8000000 != 0 {
								if (v21 & 8) == 0 {
									nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))))
								}
								*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*4))) &= 0xF7FFFFFF
							}
							nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
							if nox_xxx_servObjectHasTeam_419130(int32(v3+48)) == 0 || *(*uint32)(unsafe.Pointer(uintptr(v5 + 12))) != *(*uint32)(unsafe.Pointer(uintptr(v5 + 4))) || nox_xxx_servCompareTeams_419150(int32(v3+48), int32(uintptr(unsafe.Pointer((*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*12)))))) != 0 {
								if a3 == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 1)))) == 0 {
									v23 = *(**float32)(unsafe.Pointer(uintptr(v3 + 508)))
									if v23 == nil || v23 == v4 {
										v24 = v9 + 32
										if v24 >= 256 {
											v24 -= 256
										}
										v25 = float64(v40 * *(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*30)))
										if float64(*memmap.PtrInt32(0x587000, uint32(v24*8)+192088))*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*17))-*(*float32)(unsafe.Pointer(uintptr(v3 + 68))))-float64(*memmap.PtrInt32(0x587000, uint32(v24*8)+192092))*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*16))-*(*float32)(unsafe.Pointer(uintptr(v3 + 64)))) <= 0.0 {
											v26 = v25 + float64(*(*float32)(unsafe.Pointer(uintptr(v5 + 32))))
										} else {
											v26 = float64(*(*float32)(unsafe.Pointer(uintptr(v5 + 32)))) - v25
										}
										*(*float32)(unsafe.Pointer(uintptr(v5 + 32))) = float32(v26)
										sub_548830(v5)
										nox_xxx_unitAddToUpdatable_4DA8D0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
									}
								}
							} else if gameFrame() > *(*uint32)(unsafe.Pointer(uintptr(v3 + 136))) {
								v22 = int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 52))))
								*(*uint32)(unsafe.Pointer(uintptr(v3 + 136))) = gameFrame() + gameFPS()
								nox_xxx_getTeamByID_418AB0(v22)
								nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), internCStr("objcoll.c:GateLockedMechanism"), 0)
							}
						}
					}
				}
			}
		}
	}
}
func sub_5516A0(a1 *float4, a2 *float4, a3 *float2, a4 int32, a6 int32) int32 {
	var (
		v5  int32
		v6  int32
		v7  *float2
		v9  int32
		v10 int32
	)
	v5 = 0
	v6 = 0
	v9 = 0
	v10 = 0
	if a4 > 0 {
		v7 = a3
		for {
			if v10 >= 4 {
				break
			}
			switch v10 {
			case 0:
				v6 = sub_551780(a1, a2.field_0, a2.field_8, a2.field_4, v7, a6)
			case 1:
				v6 = sub_551870(a1, a2.field_8, a2.field_4, a2.field_C, v7, a6)
			case 2:
				v6 = sub_551780(a1, a2.field_0, a2.field_8, a2.field_C, v7, a6)
			case 3:
				v6 = sub_551870(a1, a2.field_0, a2.field_4, a2.field_C, v7, a6)
			default:
			}
			v5 = v9
			if v6 != 0 {
				v5 = v9 + 1
				v7 = (*float2)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float2{})*1))
				v9++
			}
			v10++
			if v5 >= a4 {
				break
			}
		}
	}
	return v5
}
func sub_551780(a1 *float4, a2 float32, a3 float32, a4 float32, a5 *float2, a6 int32) int32 {
	var (
		v6  *float4
		v7  float64
		v8  float64
		v10 float32
		v11 float32
	)
	v6 = a1
	v7 = float64(a1.field_4 - a1.field_C)
	if v7 == 0.0 {
		return 0
	}
	v10 = float32(float64(a4-a1.field_C) / v7)
	if float64(v10) < 0.0 && a6 == 0 {
		return 0
	}
	if float64(v10) > 1.0 {
		return 0
	}
	v8 = float64(a2 - a3)
	if v8 == 0.0 {
		return 0
	}
	v11 = float32(((1.0-float64(v10))*float64(v6.field_8) + float64(v10*v6.field_0) - float64(a3)) / v8)
	if float64(v11) < 0.0 || float64(v11) > 1.0 {
		return 0
	}
	a5.field_4 = a4
	a5.field_0 = float32((1.0-float64(v11))*float64(a3) + float64(v11*a2))
	return 1
}
func sub_551870(a1 *float4, a2 float32, a3 float32, a4 float32, a5 *float2, a6 int32) int32 {
	var (
		v6  *float4
		v7  float64
		v8  float64
		v10 float32
		v11 float32
	)
	v6 = a1
	v7 = float64(a1.field_0 - a1.field_8)
	if v7 == 0.0 {
		return 0
	}
	v10 = float32(float64(a2-a1.field_8) / v7)
	if float64(v10) < 0.0 && a6 == 0 {
		return 0
	}
	if float64(v10) > 1.0 {
		return 0
	}
	v8 = float64(a3 - a4)
	if v8 == 0.0 {
		return 0
	}
	v11 = float32(((1.0-float64(v10))*float64(v6.field_C) + float64(v10*v6.field_4) - float64(a4)) / v8)
	if float64(v11) < 0.0 || float64(v11) > 1.0 {
		return 0
	}
	a5.field_0 = a2
	a5.field_4 = float32((1.0-float64(v11))*float64(a4) + float64(v11*a3))
	return 1
}
func sub_551960(a1 *float4, a2 *float4, a3 *float4, a4 *float2) int32 {
	var (
		result int32
		v5     int32
		v6     int32
		v7     float64
		v8     *float2
		v9     float64
		a3a    [2]float2
	)
	if float64(a2.field_0) < float64(a3.field_0) || float64(a2.field_8) > float64(a3.field_8) || float64(a2.field_4) < float64(a3.field_4) || float64(a2.field_C) > float64(a3.field_C) {
		v5 = sub_5516A0(a1, a3, &a3a[0], 2, 0) - 1
		if v5 != 0 {
			if v5 == 1 {
				a4.field_0 = float32(float64(a3a[1].field_0+a3a[0].field_0) * 0.5)
				a4.field_4 = float32(float64(a3a[1].field_4+a3a[0].field_4) * 0.5)
				result = 1
			} else {
				result = 0
			}
		} else {
			v6 = sub_551A90((*float2)(unsafe.Pointer(a1)), a3)
			v7 = float64(a3a[0].field_0)
			if v6 != 0 {
				v8 = a4
				a4.field_0 = float32((v7 + float64(a1.field_0)) * 0.5)
				v9 = float64(a3a[0].field_4 + a1.field_4)
			} else {
				v8 = a4
				a4.field_0 = float32((v7 + float64(a1.field_8)) * 0.5)
				v9 = float64(a3a[0].field_4 + a1.field_C)
			}
			v8.field_4 = float32(v9 * 0.5)
			result = 1
		}
	} else {
		a4.field_0 = float32(float64(a1.field_8+a1.field_0) * 0.5)
		result = 1
		a4.field_4 = float32(float64(a1.field_C+a1.field_4) * 0.5)
	}
	return result
}
func sub_551A90(a1 *float2, a2 *float4) int32 {
	return bool2int32(float64(a1.field_0) >= float64(a2.field_0) && float64(a1.field_0) <= float64(a2.field_8) && float64(a1.field_4) >= float64(a2.field_4) && float64(a1.field_4) <= float64(a2.field_C))
}
func sub_551AE0(a1 int32, a2 int32, a3 int32) {
	var (
		v3 int32
		v4 int32
		v5 float32
		v6 float32
	)
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if *memmap.PtrUint32(0x5D4594, 2491808) == 0 {
		sub_551BF0()
	}
	if a3 != 0 {
		v4 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4))))
		if uint32(uint16(int16(v4))) != *memmap.PtrUint32(0x5D4594, 2491792) && uint32(v4) != *memmap.PtrUint32(0x5D4594, 2491796) && uint32(v4) != *memmap.PtrUint32(0x5D4594, 2491800) && uint32(v4) != *memmap.PtrUint32(0x5D4594, 2491804) {
			v5 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 104)))) - float64(*(*int32)(unsafe.Pointer(uintptr(v3 + 16)))))
			if sub_419A10(v5) > 10.0 {
				if float64(*(*int32)(unsafe.Pointer(uintptr(v3 + 16)))) > float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 104)))) {
					if *(*uint32)(unsafe.Pointer(uintptr(a2 + 172))) == 2 {
						sub_54AD50(a2, a1, 0)
					} else if *(*uint32)(unsafe.Pointer(uintptr(a2 + 172))) == 3 {
						sub_550F80((*float32)(unsafe.Pointer(uintptr(a2))), a1)
					}
				}
			} else if nox_xxx_map_57B850((*float2)(unsafe.Pointer(uintptr(a1+64))), (*float32)(unsafe.Pointer(uintptr(a1+172))), (*float2)(unsafe.Pointer(uintptr(a2+64)))) != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) = *(*uint32)(unsafe.Pointer(uintptr(a2 + 16)))&0xFFFBFFFF | 0x100000
				v6 = float32(float64(*(*int32)(unsafe.Pointer(uintptr(v3 + 16)))) + 4.0)
				nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), v6)
				*(*uint32)(unsafe.Pointer(uintptr(a2 + 108))) = 0
			}
		}
	}
}
func sub_551BF0() {
	*memmap.PtrUint32(0x5D4594, 2491792) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallFist")))
	*memmap.PtrUint32(0x5D4594, 2491796) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("MediumFist")))
	*memmap.PtrUint32(0x5D4594, 2491800) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("LargeFist")))
	*memmap.PtrUint32(0x5D4594, 2491804) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Meteor")))
	*memmap.PtrUint32(0x5D4594, 2491808) = 1
}
func sub_551C40(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  float64
		v7  *uint32
		v8  float32
		v9  float32
		v10 float32
	)
	v2 = a1
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if *memmap.PtrUint32(0x5D4594, 2491808) == 0 {
		sub_551BF0()
	}
	if *(*uint32)(unsafe.Pointer(uintptr(v3 + 4))) != 0 {
		v4 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4))))
		if uint32(uint16(int16(v4))) != *memmap.PtrUint32(0x5D4594, 2491792) && uint32(v4) != *memmap.PtrUint32(0x5D4594, 2491796) && uint32(v4) != *memmap.PtrUint32(0x5D4594, 2491800) && uint32(v4) != *memmap.PtrUint32(0x5D4594, 2491804) {
			v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 172))))
			if v5 == 3 {
				if float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 184)))) < float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 184)))) || float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 188)))) < float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 188)))) {
					return
				}
			} else if v5 == 2 {
				v6 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 176))) + *(*float32)(unsafe.Pointer(uintptr(a2 + 176))))
				if v6 > float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 184)))) || v6 > float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 188)))) {
					return
				}
			}
			v7 = (*uint32)(unsafe.Pointer(uintptr(a1 + 64)))
			if nox_xxx_map_57B850((*float2)(unsafe.Pointer(uintptr(a1+64))), (*float32)(unsafe.Pointer(uintptr(a1+172))), (*float2)(unsafe.Pointer(uintptr(a2+64)))) != 0 {
				v10 = float32(float64(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 4))) + 748))) + 16))) - 64)))
				v8 = *(*float32)(unsafe.Pointer(uintptr(a2 + 104))) - v10
				if sub_419A10(v8) > 10.0 {
					if float64(v10) <= -10.0 {
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) |= 0x40000
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 156))) = *v7
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 160))) = *(*uint32)(unsafe.Pointer(uintptr(v2 + 68)))
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 164))) = *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 4))) + 64)))
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 168))) = *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 4))) + 68)))
					}
				} else {
					v9 = float32(float64(v10) + 4.0)
					*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) = *(*uint32)(unsafe.Pointer(uintptr(a2 + 16)))&0xFFFBFFFF | 0x100000
					nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), v9)
					*(*uint32)(unsafe.Pointer(uintptr(a2 + 108))) = 0
				}
			}
		}
	}
}
