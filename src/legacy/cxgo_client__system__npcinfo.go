package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
)

func nox_xxx_spriteNPCInfo_49A4B0(a1 *client.Drawable, a2 int32, a3 int32) int32 {
	var (
		result int32
		v4     int32
	)
	result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108)))
	v4 = int32(a1.Field_69 - 1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108)) = 0
	switch v4 {
	case 0, 1, 2, 3:
		if (uint32(a2) & 0xFFFFFFFC) == 0 {
			if result == 0 || a1.Field_77 == 0 {
				result = nox_common_randomIntMinMax_415FF0(23, 24, internCStr("C:\\NoxPost\\src\\client\\System\\NPCInfo.c"), 286)
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108)) = uint32(result)
			return result
		}
		return sub_4FA280(int32(uint32(a2) & 0xFFFFFFFC))
	case 4, 5:
		if a2&0x400 != 0 {
			if result != 0 && a1.Field_77 != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108)) = uint32(result)
			} else {
				result = nox_common_randomIntMinMax_415FF0(47, 49, internCStr("C:\\NoxPost\\src\\client\\System\\NPCInfo.c"), 314)
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108)) = uint32(result)
			}
			return result
		} else if uint32(a2)&0x7FF8000 != 0 {
			return 30
		} else if (uint32(a3) & 0x3000000) == 0 {
			if (a2 & 0x400) != 0 {
				return 0x26
			}
			return 0
		}
		return 40
	case 6:
		return 21
	case 7:
		if (a2 & 0x400) != 0 {
			return 0x26
		}
		return 0
	case 8:
		return 1
	case 9:
		return 2
	case 11:
		return 4
	case 12:
		return 6
	case 13:
		return 50
	default:
		return 0
	}
}
