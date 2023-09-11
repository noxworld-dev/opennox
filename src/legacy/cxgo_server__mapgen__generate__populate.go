package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
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
		a2a Point32
		a1a types.Pointf
		v13 float32 = 0
		v14 float32 = 0
		v15 types.Pointf
	)
	v2 = int32(*(*uint32)(unsafe.Add(a2, 60)))
	if int32(*((*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(a1), v2), 216)))) != 0 {
		return nil
	}
	switch v2 {
	case 0:
		a1a.X = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*7)))*0.5 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) + 1.0)
		v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) + 10.0
		a1a.Y = float32(v4)
	case 1:
		a1a.X = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*7)))*0.5 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) + 1.0)
		v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*12))) - 10.0
		a1a.Y = float32(v4)
	case 2:
		v5 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*11))) - 10.0
		a1a.X = float32(v5)
		v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*8)))*0.5 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) + 1.0
		a1a.Y = float32(v4)
	case 3:
		v5 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) + 10.0
		a1a.X = float32(v5)
		v4 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*8)))*0.5 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) + 1.0
		a1a.Y = float32(v4)
	default:
	}
	nox_xxx_mapGenGetObjID_527940((*byte)(a2))
	v6 = nox_xxx_mapGenPlaceObj_5279B0(&a1a)
	if v6 == nil {
		return v6
	}
	nox_xxx_mapGenRoundFloatToPtr_520DF0(&a1a, (*uint32)(unsafe.Pointer(&a2a)))
	switch *(*uint32)(unsafe.Add(a2, 60)) {
	case 0:
		v13 = 3.0
		v7 = 2.0
		a2a.X--
	case 1:
		v7 = 2.0
		a2a.X--
		a2a.Y -= 2
		v13 = 3.0
	case 2:
		a2a.X -= 2
		v13 = 2.0
		v7 = 3.0
		a2a.Y--
	case 3:
		v13 = 2.0
		v7 = 3.0
		a2a.Y--
	default:
		v7 = float64(v14)
	}
	v15.X = float32(float64(a2a.X) * 32.526913)
	v15.Y = float32(float64(a2a.Y) * 32.526913)
	a4 = float32(v7 * 32.526913)
	a3 = float32(float64(v13) * 32.526913)
	sub_521BC0(int32(uintptr(unsafe.Pointer(a1))), &v15, a3, a4)
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
	v3 = nox_xxx_getUnitName_4E39D0((*server.Object)(a1))
	if nox_objectTypeGetXfer(v3) != ccall.FuncAddr(nox_xxx_XFerExit_4F4B90) {
		return 0
	}
	libc.StrNCpy(*(**byte)(unsafe.Add(a1, 700)), a2, 0x50)
	return 1
}
func nox_xxx_mapGenMakeExit_522A40(a1 int32) int32 {
	if *(*uint32)(unsafe.Add(a1, 472)) == 0 {
		return 1
	}
	for v2 := sub_5259E0(); v2 != 0; v2 = int32(*(*uint32)(unsafe.Add(v2, 68))) {
		if *(*uint32)(v2) != 1 {
			continue
		}
		var v3 int32 = 0
		var v4 int32 = a1 + 216
		for v3 < *(*int32)(unsafe.Add(a1, 472)) {
			var v5 *float32 = nox_xxx_mapgen_522AD0((*float32)(v2), v4)
			if v5 != nil {
				sub_527D50(int32(uintptr(unsafe.Pointer(v5))), (*byte)(unsafe.Add(a1, 476)))
				return 1
			}
			v3++
			v4 += 64
		}
	}
	return 0
}
func sub_5259D0() float64 {
	return float64(dword_5d4594_2487580)
}
func sub_526A90() {
	alloc.FreePtr(dword_5d4594_2487672)
}
func nox_xxx_mapGenFinishPopulate_5228B0_mapgen_populate(a1 unsafe.Pointer) {
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
	for i = sub_4D42C0(); i != 0; i = int32(*(*uint32)(unsafe.Add(i, 64))) {
		nox_xxx_mapGenSetFlags_5235F0(-99)
		if *(*uint32)(unsafe.Add(i, 372)) != 0 && (int32(*(*uint8)(unsafe.Add(i, 52)))&2) == 0 {
			nox_xxx_mapgen_522340(a1, i)
		}
		if *(*uint32)(unsafe.Add(a1, 60)) != 0 {
			for j = int32(*(*uint32)(unsafe.Add(i, 368))); j != 0; j = int32(*(*uint32)(unsafe.Add(j, 24))) {
				if *(*uint32)(j) != 0 {
					nox_xxx_tileGetDefByName_51D4D0(internCStr("CrystalBlue"))
				} else {
					nox_xxx_tileGetDefByName_51D4D0(internCStr("CrystalRed"))
				}
				sub_5245A0(a1, (*float32)(unsafe.Add(j, 4)), int32(int64((float64(*(*float32)(unsafe.Add(j, 12))-*(*float32)(unsafe.Add(j, 4)))+0.5)*0.030743772)), int32(int64((float64(*(*float32)(unsafe.Add(j, 16))-*(*float32)(unsafe.Add(j, 8)))+0.5)*0.030743772)))
			}
		}
	}
	v6 = (*float32)(unsafe.Pointer(uintptr(sub_4D42C0())))
	v8 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*11))+*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*9))) * 0.5)
	v9 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*12))+*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*10))) * 0.5)
	nox_xxx_mapGenGetObjID_527940(internCStr("PlayerStart"))
	nox_xxx_mapGenPlaceObj_5279B0((*types.Pointf)(unsafe.Pointer(&v8)))
	sub_469B90(*(*[3]uint32)(unsafe.Add(a1, 536)))
	sub_526A90()
}
