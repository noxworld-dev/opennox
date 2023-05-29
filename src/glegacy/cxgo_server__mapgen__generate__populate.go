package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"unsafe"
)

func sub_4D42C0() int32 {
	return int32(dword_5d4594_1550916)
}
func nox_xxx_mapgen_522AD0(a1 *float32, a2 int32) *float32 {
	var (
		v2  int32
		v4  float64
		v5  float64
		v6  *float32
		v7  float64
		a3  float32
		a4  float32
		a2a int2
		a1a float2
		v13 float32 = 0
		v14 float32 = 0
		v15 float2
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 60))))
	if int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(a1))), v2))), 216)))) != 0 {
		return nil
	}
	switch v2 {
	case 0:
		a1a.field_0 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*7)))*0.5 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) + 1.0)
		v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) + 10.0
		a1a.field_4 = float32(v4)
	case 1:
		a1a.field_0 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*7)))*0.5 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) + 1.0)
		v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*12))) - 10.0
		a1a.field_4 = float32(v4)
	case 2:
		v5 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*11))) - 10.0
		a1a.field_0 = float32(v5)
		v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*8)))*0.5 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) + 1.0
		a1a.field_4 = float32(v4)
	case 3:
		v5 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) + 10.0
		a1a.field_0 = float32(v5)
		v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*8)))*0.5 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) + 1.0
		a1a.field_4 = float32(v4)
	default:
	}
	nox_xxx_mapGenGetObjID_527940((*byte)(unsafe.Pointer(uintptr(a2))))
	v6 = nox_xxx_mapGenPlaceObj_5279B0(&a1a)
	if v6 != nil {
		nox_xxx_mapGenRoundFloatToPtr_520DF0(&a1a, (*uint32)(unsafe.Pointer(&a2a)))
		switch *(*uint32)(unsafe.Pointer(uintptr(a2 + 60))) {
		case 0:
			v13 = 3.0
			v7 = 2.0
			a2a.field_0--
		case 1:
			v7 = 2.0
			a2a.field_0--
			a2a.field_4 -= 2
			v13 = 3.0
		case 2:
			a2a.field_0 -= 2
			v13 = 2.0
			v7 = 3.0
			a2a.field_4--
		case 3:
			v13 = 2.0
			v7 = 3.0
			a2a.field_4--
		default:
			v7 = float64(v14)
		}
		v15.field_0 = float32(float64(a2a.field_0) * 32.526913)
		v15.field_4 = float32(float64(a2a.field_4) * 32.526913)
		a4 = float32(v7 * 32.526913)
		a3 = float32(float64(v13) * 32.526913)
		sub_521BC0(int32(uintptr(unsafe.Pointer(a1))), &v15, a3, a4)
	}
	return v6
}
func sub_5259E0() int32 {
	return int32(dword_5d4594_2487576)
}
func sub_527D50(a1 int32, a2 *byte) int32 {
	var v3 *byte
	if a1 == 0 {
		return 0
	}
	if a2 == nil {
		return 0
	}
	v3 = nox_xxx_getUnitName_4E39D0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	if funAddr(asFunc(nox_objectTypeGetXfer(v3), (*func(a1 int32) int32)(nil)).(func(a1 int32) int32)) != funAddr(nox_xxx_XFerExit_4F4B90) {
		return 0
	}
	libc.StrNCpy(*(**byte)(unsafe.Pointer(uintptr(a1 + 700))), a2, 0x50)
	return 1
}
func nox_xxx_mapGenMakeExit_522A40(a1 int32) int32 {
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 472))) == 0 {
		return 1
	}
	for v2 := int32(sub_5259E0()); v2 != 0; v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 68)))) {
		if *(*uint32)(unsafe.Pointer(uintptr(v2))) != 1 {
			continue
		}
		var v3 int32 = 0
		var v4 int32 = a1 + 216
		for v3 < *(*int32)(unsafe.Pointer(uintptr(a1 + 472))) {
			var v5 *float32 = nox_xxx_mapgen_522AD0((*float32)(unsafe.Pointer(uintptr(v2))), v4)
			if v5 != nil {
				sub_527D50(int32(uintptr(unsafe.Pointer(v5))), (*byte)(unsafe.Pointer(uintptr(a1+476))))
				return 1
			}
			v3++
			v4 += 64
		}
	}
	return 0
}
func sub_5259D0() float64 {
	return float64(*(*float32)(unsafe.Pointer(&dword_5d4594_2487580)))
}
func sub_526A90() {
	alloc.Free(*(*unsafe.Pointer)(unsafe.Pointer(&dword_5d4594_2487672)))
}
func nox_xxx_mapGenFinishPopulate_5228B0_mapgen_populate(a1 int32) {
	var (
		v1 *wchar2_t
		v2 *wchar2_t
		v3 *wchar2_t
		i  int32
		j  int32
		v6 *float32
		v8 float32
		v9 float32
	)
	_ = v9
	nox_xxx_mapGenSetFlags_5235F0(-99)
	if nox_xxx_mapGenMakeExit_522A40(a1) == 0 {
		v1 = nox_strman_loadString_40F1D0(internCStr("NoExit"), nil, internCStr("C:\\NoxPost\\src\\Server\\MapGen\\Generate\\populate.c"), 848)
		nox_xxx_printToAll_4D9FD0(0, v1)
		v2 = nox_strman_loadString_40F1D0(internCStr("NoExit"), nil, internCStr("C:\\NoxPost\\src\\Server\\MapGen\\Generate\\populate.c"), 849)
		nox_xxx_printToAll_4D9FD0(0, v2)
		v3 = nox_strman_loadString_40F1D0(internCStr("NoExit"), nil, internCStr("C:\\NoxPost\\src\\Server\\MapGen\\Generate\\populate.c"), 850)
		nox_xxx_printToAll_4D9FD0(0, v3)
	}
	sub_5259D0()
	for i = sub_4D42C0(); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 64)))) {
		nox_xxx_mapGenSetFlags_5235F0(-99)
		if *(*uint32)(unsafe.Pointer(uintptr(i + 372))) != 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(i + 52))))&2) == 0 {
			nox_xxx_mapgen_522340(a1, i)
		}
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 60))) != 0 {
			for j = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 368)))); j != 0; j = int32(*(*uint32)(unsafe.Pointer(uintptr(j + 24)))) {
				if *(*uint32)(unsafe.Pointer(uintptr(j))) != 0 {
					nox_xxx_tileGetDefByName_51D4D0(internCStr("CrystalBlue"))
				} else {
					nox_xxx_tileGetDefByName_51D4D0(internCStr("CrystalRed"))
				}
				sub_5245A0(a1, (*float32)(unsafe.Pointer(uintptr(j+4))), int32(int64((float64(*(*float32)(unsafe.Pointer(uintptr(j + 12)))-*(*float32)(unsafe.Pointer(uintptr(j + 4))))+0.5)*0.030743772)), int32(int64((float64(*(*float32)(unsafe.Pointer(uintptr(j + 16)))-*(*float32)(unsafe.Pointer(uintptr(j + 8))))+0.5)*0.030743772)))
			}
		}
	}
	v6 = (*float32)(unsafe.Pointer(uintptr(sub_4D42C0())))
	v8 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*11))+*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*9))) * 0.5)
	v9 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*12))+*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*10))) * 0.5)
	nox_xxx_mapGenGetObjID_527940(internCStr("PlayerStart"))
	nox_xxx_mapGenPlaceObj_5279B0((*float2)(unsafe.Pointer(&v8)))
	sub_469B90((*int32)(unsafe.Pointer(uintptr(a1 + 536))))
	sub_526A90()
}
