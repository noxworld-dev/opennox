package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_spriteNPCInfo_49A4B0(dr *client.Drawable, a2 int32, a3 int32) int {
	ptr := (*uint32)(unsafe.Add(unsafe.Pointer(&dr.Union), 0))
	res := int(*ptr)
	*ptr = 0
	switch dr.AnimInd - 1 {
	case 0, 1, 2, 3:
		if (uint32(a2) & 0xFFFFFFFC) == 0 {
			if res == 0 || dr.AnimFrameSlave == 0 {
				res = int(nox_common_randomIntMinMax_415FF0(23, 24, internCStr("C:\\NoxPost\\src\\client\\System\\NPCInfo.c"), 286))
			}
			*ptr = uint32(res)
			return res
		}
		return sub_4FA280(int32(uint32(a2) & 0xFFFFFFFC))
	case 4, 5:
		if a2&0x400 != 0 {
			if res != 0 && dr.AnimFrameSlave != 0 {
				*ptr = uint32(res)
			} else {
				res = int(nox_common_randomIntMinMax_415FF0(47, 49, internCStr("C:\\NoxPost\\src\\client\\System\\NPCInfo.c"), 314))
				*ptr = uint32(res)
			}
			return res
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
func sub_4FA280(a1 int32) int32 {
	var v1 int32
	v1 = 2
	for ((1 << v1) & a1) == 0 {
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= 27 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*4)+215824))
}
