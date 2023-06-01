package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_thing_flag_draw(a1 *int32, dr *nox_drawable) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 *uint16
		a2 int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v2 = a2
	nox_thing_weapon_animate_draw(a1, dr)
	if nox_common_gameFlags_check_40A5C0(128) {
		if *(*uint32)(unsafe.Pointer(uintptr(v2 + 120)))&0x1000000 != 0 {
			v3 = int32(uint32(*a1) + *(*uint32)(unsafe.Pointer(uintptr(v2 + 12))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))))
			v4 = int32(uint32(uint64(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16)))+uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))-uint32(*(*int16)(unsafe.Pointer(uintptr(v2 + 104))))) - uint64(int64(*(*float32)(unsafe.Pointer(uintptr(v2 + 100))))) - uint64(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))))
			v5 = sub_4B94E0(dr)
			v6 = (*uint16)(unsafe.Pointer(sub_418A80(v5)))
			if v6 != nil {
				nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x8531A0, 2572))
				nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(v6)), &a2, nil, 0)
				nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer((*int16)(unsafe.Pointer(v6)))), a2/(-2)+v3, v4)
			}
		}
	}
	return 1
}
