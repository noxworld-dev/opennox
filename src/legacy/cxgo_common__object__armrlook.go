package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_415B60(a1 *server.Object) string {
	for i := range table_34848 {
		it := &table_34848[i]
		if it.TypeInd == uint32(a1.TypeInd) {
			return nox_strman_loadString_40F1D0(it.NameStr, nil, internCStr("C:\\NoxPost\\src\\common\\Object\\ArmrLook.c"), 261)
		}
	}
	return nox_strman_loadString_40F1D0(internCStr("result:ERROR"), nil, internCStr("C:\\NoxPost\\src\\common\\Object\\ArmrLook.c"), 263)
}
func nox_xxx_loadLook_415D50() **byte {
	var (
		result **byte
		v1     *uint8
		v2     int32
	)
	result = *(***byte)(memmap.PtrOff(0x5D4594, 371256))
	if *memmap.PtrUint32(0x5D4594, 371256) != 0 {
		return result
	}
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
	return result
}
