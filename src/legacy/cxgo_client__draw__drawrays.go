package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_netDrawRays_49BDD0(a1 *uint8) int32 {
	var (
		result int32
		v2     *uint8
		v3     *uint8
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    int32
		v15    int32
		v16    int8
		v17    int8
		v18    int8
		v19    [4]uint16
		v20    int32
	)
	result = int32(*memmap.PtrUint32(0x5D4594, 1304308))
	if *memmap.PtrInt32(0x5D4594, 1304308) < 96 {
		if *memmap.PtrUint32(0x5D4594, 1304316) == 0 {
			*memmap.PtrUint32(0x5D4594, 1304316) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DynamicLightning")))
			*memmap.PtrUint32(0x5D4594, 1304320) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DynamicChainLightning")))
			*memmap.PtrUint32(0x5D4594, 1304324) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DynamicEnergyBolt")))
			*memmap.PtrUint32(0x5D4594, 1304348) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GreenZap")))
			dword_5d4594_1304328 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("OrbRay")))
			*memmap.PtrUint32(0x5D4594, 1304332) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("PlasmaRay")))
			*memmap.PtrUint32(0x5D4594, 1304336) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DrainManaOrb")))
			*memmap.PtrUint32(0x5D4594, 1304340) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("HealOrb")))
			*memmap.PtrUint32(0x5D4594, 1304344) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CharmOrb")))
		}
		v2 = a1
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(a1), 1))
		v4 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), 1))) + (int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), 5)))-int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), 1))))/2
		result = int32(*a1) - 125
		v5 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), 3))) + (int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), 7)))-int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), 3))))/2
		switch *a1 {
		case 0x7D:
			v20 = int32(*memmap.PtrUint32(0x5D4594, 1304332))
		case 0x8C:
			v20 = int32(*memmap.PtrUint32(0x5D4594, 1304316))
		case 0x8D:
			v20 = int32(*memmap.PtrUint32(0x5D4594, 1304324))
		case 0x8E:
			v20 = int32(*memmap.PtrUint32(0x5D4594, 1304320))
		case 0x8F:
			v18 = int8(nox_common_randomIntMinMax_415FF0(6, 12, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 137))
			v20 = int32(dword_5d4594_1304328)
			if nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 140) < 50 {
				v15 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 143)
				v10 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 142)
				sub_499490(*memmap.PtrInt32(0x5D4594, 1304336), (*uint16)(unsafe.Pointer(v3)), v10, v15, v18, 0)
			}
		case 0x90:
			v16 = int8(nox_common_randomIntMinMax_415FF0(6, 12, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 101))
			v20 = int32(dword_5d4594_1304328)
			if nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 104) < 50 {
				v12 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 107)
				v6 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 106)
				sub_499490(*memmap.PtrInt32(0x5D4594, 1304344), (*uint16)(unsafe.Pointer(v3)), v6, v12, v16, 0)
			}
			v7 = int32(*(*uint32)(unsafe.Pointer(v3)))
			*(*uint32)(unsafe.Pointer(&v19[0])) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 5))
			*(*uint32)(unsafe.Pointer(&v19[2])) = uint32(v7)
			if nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 112) < 50 {
				v13 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 115)
				v8 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 114)
				sub_499490(*memmap.PtrInt32(0x5D4594, 1304344), &v19[0], v8, v13, v16, 0)
			}
		case 0x91:
			v17 = int8(nox_common_randomIntMinMax_415FF0(6, 12, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 123))
			v20 = int32(dword_5d4594_1304328)
			if nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 126) < 50 {
				v14 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 129)
				v9 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Draw\\drawrays.c"), 128)
				sub_499490(*memmap.PtrInt32(0x5D4594, 1304340), (*uint16)(unsafe.Pointer(v3)), v9, v14, v17, 0)
			}
		default:
			return result
		}
		result = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v20, v4, v5))))
		if result != 0 {
			*(*uint8)(unsafe.Add(result, 432)) = 0
			*(*uint32)(unsafe.Add(result, 437)) = *(*uint32)(unsafe.Pointer(v3))
			*(*uint32)(unsafe.Add(result, 441)) = *((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)))
			v11 = int32(*memmap.PtrUint32(0x5D4594, 1304308))
			*memmap.PtrUint32(0x5D4594, uintptr(memmap.Uint32(0x5D4594, 1304308))*4+1303540) = uint32(result)
			*memmap.PtrUint32(0x5D4594, 1304308) = uint32(v11 + 1)
		}
	}
	return result
}
