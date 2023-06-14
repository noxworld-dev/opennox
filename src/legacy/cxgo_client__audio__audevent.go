package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func sub_451CF0(a1 *uint32) int32 {
	var (
		v1     int32
		result int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     *uint32
		v9     int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
	result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108)))
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 4)))
	if result != 0 {
		if v3&2 != 0 {
			v5 = nox_common_randomIntMinMax_415FF0(0, result-1, internCStr("C:\\NoxPost\\src\\client\\Audio\\AudEvent.c"), 376)
			v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108)) - 1)
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*43)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*uintptr(v5+76)))
			v7 = v5
			if v5 < v6 {
				v8 = (*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*uintptr(v5+76)))
				for {
					v7++
					*v8 = *(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
					v8 = (*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
					if uint32(v7) >= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108))-1 {
						break
					}
				}
			}
		} else {
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*43))++
		}
		v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*43)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108))--
		result = sub_4BD710(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*uintptr(v9+10)))))
	} else if v3&1 != 0 {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 60)) != 0 && (func() bool {
			v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*109)) + 1)
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*109)) = uint32(v4)
			return v4 >= *(*int32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 60))
		}()) {
			result = 0
		} else {
			result = sub_451CA0(a1)
		}
	}
	return result
}
func sub_451DC0(a1 int32) int32 {
	var (
		v1     *uint32
		result int32
		v3     int32
		i      int32
		v5     int32
		v6     int32
	)
	v1 = *(**uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 36))
	result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 168)))
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*1)))
	if result != 0 {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*17)) < 0x21 {
			return result
		}
		sub_451F90(a1)
	}
	if v3&4 != 0 {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*17)) >= 0x21 {
			v5 = sub_451E80(a1)
			result = sub_451F30(a1, v5)
		} else {
			result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*48)))
			for i = 0; i < result; i++ {
				sub_451F30(a1, i)
				result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*48)))
			}
		}
	} else if v3&2 != 0 {
		v6 = nox_common_randomIntMinMax_415FF0(0, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*48))-1), internCStr("C:\\NoxPost\\src\\client\\Audio\\AudEvent.c"), 536)
		result = sub_451F30(a1, v6)
	} else {
		result = sub_451F30(a1, 0)
	}
	return result
}
func sub_451E80(a1 int32) int32 {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 *uint32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 36)))
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 4)))
	if *(*int32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 568)) <= 0 {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 192)))
		v4 = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 568)) = uint32(v3)
		if v3 > 0 {
			v5 = a1 + 440
			for {
				v5 += 4
				v6 = v3 - func() int32 {
					p := &v4
					x := *p
					*p++
					return x
				}() - 1
				*(*uint32)(unsafe.Pointer(uintptr(v5 - 4))) = uint32(v6)
				v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 568)))
				if v4 >= v3 {
					break
				}
			}
		}
	}
	v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 568)) - 1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 568)) = uint32(v7)
	if (v2 & 2) == 0 {
		return int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1+v7*4)), 440)))
	}
	v8 = nox_common_randomIntMinMax_415FF0(0, v7, internCStr("C:\\NoxPost\\src\\client\\Audio\\AudEvent.c"), 431)
	v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1+v8*4)), 440)))
	v10 = v8
	if v8 < *(*int32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 568)) {
		v11 = (*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1+v8*4)), 440))
		for {
			v10++
			*v11 = *(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
			v11 = (*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
			if v10 >= *(*int32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 568)) {
				break
			}
		}
	}
	return v9
}
func sub_452580(a1 *uint32) int32 {
	var (
		v1     int32
		result int32
		v3     int32
		v4     int32
		v5     int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 192)) == 0 {
		return 0
	}
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*75)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*109)) = 0
	result = int32(uintptr(unsafe.Pointer(sub_452810(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 48))+uint32(v3)), 0))))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*44)) = uint32(result)
	if result != 0 {
		v4 = nox_common_randomIntMinMax_415FF0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 76))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 80))), internCStr("C:\\NoxPost\\src\\client\\Audio\\AudEvent.c"), 1482)
		sub_486320((*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*44)), 48)), v4+100)
		sub_4BDB20(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*44))))
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*44)), 152)) = uint32(uintptr(unsafe.Pointer(a1)))
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*44)), 140)) = uint32(uintptr(ccall.FuncAddr(sub_452770)))
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*44)), 144)) = uint32(uintptr(ccall.FuncAddr(sub_4526F0)))
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*44)), 148)) = uint32(uintptr(ccall.FuncAddr(sub_4526D0)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) = 1
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*44)), 112)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(a1), 4*46)))
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 4)))&8 != 0 {
			v5 = nox_common_randomIntMinMax_415FF0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 68))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v1)), 72))), internCStr("C:\\NoxPost\\src\\client\\Audio\\AudEvent.c"), 1497)
			if v5 > 33 {
				sub_452690(int32(uintptr(unsafe.Pointer(a1))), int64(v5), 1)
			}
		}
		result = 1
	}
	return result
}
func sub_452770(a1p unsafe.Pointer) {
	a1 := (*uint32)(a1p)
	var (
		v1 *uint32
		v2 *uint32
		v4 int32
		v5 uint32
	)
	v1 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*38)))
	v2 = (*uint32)(unsafe.Pointer(uintptr(sub_451CF0((*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*38)))))))
	if *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*9)), 72)) < 0x21 {
		sub_4BDB90(a1, v2)
		return
	}
	sub_4BDB90(a1, nil)
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*9)))
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v4)), 4)))&8) == 0 || v2 != nil || *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*142)) != 0 {
		v5 = uint32(nox_common_randomIntMinMax_415FF0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v4)), 68))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v4)), 72))), internCStr("C:\\NoxPost\\src\\client\\Audio\\AudEvent.c"), 706))
		if v5 < 0x21 {
			sub_4BDB90(a1, v2)
			return
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*71)) = v5
		*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*74)) = uint32(uintptr(unsafe.Pointer(v2)))
	}
}
