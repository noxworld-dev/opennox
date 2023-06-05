package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_415B60(a1 int32) *wchar2_t {
	var (
		v1 int32
		v2 int32
		i  *uint8
		v4 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 34848) == 0 {
		return nox_strman_loadString_40F1D0(internCStr("result:ERROR"), nil, internCStr("C:\\NoxPost\\src\\common\\Object\\ArmrLook.c"), 263)
	}
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v2), unsafe.Sizeof(uint16(0))*1)) = 0
	for i = (*uint8)(memmap.PtrOff(0x587000, 34848)); ; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 24)) {
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v2), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))
		if uint32(v2) == *((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*2))) {
			break
		}
		v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*6))))
		v1++
		if v4 == 0 {
			return nox_strman_loadString_40F1D0(internCStr("result:ERROR"), nil, internCStr("C:\\NoxPost\\src\\common\\Object\\ArmrLook.c"), 263)
		}
	}
	return nox_strman_loadString_40F1D0(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1*24+34852))), nil, internCStr("C:\\NoxPost\\src\\common\\Object\\ArmrLook.c"), 261)
}
func nox_xxx_loadLook_415D50() **byte {
	var (
		result **byte
		v1     *uint8
		v2     int32
	)
	result = *(***byte)(memmap.PtrOff(0x5D4594, 371256))
	if *memmap.PtrUint32(0x5D4594, 371256) == 0 {
		result = *(***byte)(memmap.PtrOff(0x587000, 35500))
		if *memmap.PtrUint32(0x587000, 35500) != 0 {
			result = (**byte)(memmap.PtrOff(0x587000, 35500))
			v1 = (*uint8)(memmap.PtrOff(0x587000, 35500))
			for {
				*((*uint32)(unsafe.Add(unsafe.Pointer(v1), -int(4*1)))) = uint32(uintptr(unsafe.Pointer(nox_strman_loadString_40F1D0(*result, nil, internCStr("C:\\NoxPost\\src\\common\\Object\\ArmrLook.c"), 380))))
				v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3))))
				v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 12))
				result = (**byte)(unsafe.Pointer(v1))
				if v2 == 0 {
					break
				}
			}
		}
		*memmap.PtrUint32(0x5D4594, 371256) = 1
	}
	return result
}
