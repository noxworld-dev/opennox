package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_itemGetName_4E77E0_obj_util(a1 int32) *wchar2_t {
	var (
		v1  int32
		v2  *uint32
		v3  *uint32
		v4  *uint32
		v5  *wchar2_t
		v7  int32
		v8  *wchar2_t
		v9  int32
		v10 int32
		v11 *wchar2_t
		v12 int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 8)))
	if uint32(v1)&0x13001000 != 0 {
		v2 = *(**uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 692))
		if uint32(v1)&0x11001000 != 0 {
			v3 = (*uint32)(nox_xxx_getProjectileClassById_413250(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 4)))))
		} else {
			v3 = (*uint32)(nox_xxx_equipClothFindDefByTT_413270(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 4)))))
		}
		v4 = v3
		if v3 == nil {
			v12 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*server.Object)(unsafe.Pointer(uintptr(a1)))))))
			v5 = nox_strman_loadString_40F1D0(internCStr("NoInfo"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\objutil.c"), 983)
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), v5, v12)
			return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660))
		}
		nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1567732)))
		if *v2 != 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*v2)), 8)) != 0 {
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), *(**wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(*v2)), 8)))
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), internWStr(" "))
		}
		v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)))
		if v7 != 0 {
			v8 = *(**wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 8))
			if v8 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), v8)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), internWStr(" "))
			}
		}
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) != 0 {
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), (*wchar2_t)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*2))))
		}
		v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
		if v9 != 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v9)), 8)) != 0 {
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), internWStr(" "))
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), *(**wchar2_t)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*2)), 8)))
		}
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)))
		if v10 != 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v10)), 12)) != 0 {
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), internWStr(" "))
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), *(**wchar2_t)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*3)), 12)))
			return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660))
		}
	} else {
		v11 = nox_strman_loadString_40F1D0(internCStr("NoDescription"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\objutil.c"), 1032)
		nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660)), v11)
	}
	return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1565660))
}
