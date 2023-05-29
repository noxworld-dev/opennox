package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_57AF30(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 *uint32
		v4 *wchar2_t
		v5 int32
	)
	if dword_5d4594_2523804 == 1 || nox_xxx_checkGameFlagPause_413A50() != 0 {
		return
	}
	v2 = a1
	if a1 != 0 {
		dword_5d4594_2523780 = uint32(a1)
	} else {
		v2 = int32(dword_5d4594_2523780)
	}
	if a2 != 0 {
		if a2 != 1 {
			v3 = *(**uint32)(unsafe.Pointer(&dword_5d4594_2523776))
		} else {
			v3 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("OblivionUp"))))
			v2 = int32(dword_5d4594_2523780)
			dword_5d4594_2523776 = uint32(uintptr(unsafe.Pointer(v3)))
		}
	} else {
		v3 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("LevelUp"))))
		v2 = int32(dword_5d4594_2523780)
		dword_5d4594_2523776 = uint32(uintptr(unsafe.Pointer(v3)))
	}
	if v3 != nil {
		if v2 != 0 {
			nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), nil, *(*float32)(unsafe.Pointer(uintptr(v2 + 56))), *(*float32)(unsafe.Pointer(uintptr(v2 + 60))))
		} else {
			nox_xxx_objectFreeMem_4E38A0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))))
			dword_5d4594_2523776 = 0
		}
		v2 = int32(dword_5d4594_2523780)
	}
	if (a2 == 0 || a2 == 1) && v2 != 0 {
		nox_xxx_netSendPointFx_522FF0(-102, (*float2)(unsafe.Pointer(uintptr(v2+56))))
		v2 = int32(dword_5d4594_2523780)
	}
	if a2 == 0 {
		if v2 == 0 {
			goto LABEL_29
		}
		nox_xxx_aud_501960(902, (*nox_object_t)(unsafe.Pointer(uintptr(v2))), 2, int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 36)))))
		v4 = nox_strman_loadString_40F1D0(internCStr("expLevel.c:LevelUP"), nil, internCStr("C:\\NoxPost\\src\\common\\GameMech\\PauseFX.c"), 109)
		nox_xxx_netSendLineMessage_4D9EB0(*(*int32)(unsafe.Pointer(&dword_5d4594_2523780)), v4)
		v2 = int32(dword_5d4594_2523780)
	}
	if v2 != 0 {
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 748))))
		if nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(v2))), 30) == 1 {
			*(*uint8)(unsafe.Pointer(uintptr(v5 + 236))) = 4
		}
	}
	if a2 != 0 {
		*memmap.PtrUint32(0x5D4594, 2523796) = 0
		if a2 != 1 {
			goto LABEL_30
		}
	}
LABEL_29:
	*memmap.PtrUint32(0x5D4594, 2523796) = 5000
LABEL_30:
	*memmap.PtrUint32(0x5D4594, 2523800) = 0
	*memmap.PtrUint32(0x5D4594, 2523772) = uint32(a2)
	dword_5d4594_2523804 = 1
	sub_413A00(1)
	*memmap.PtrUint64(0x5D4594, 2523788) = uint64(nox_platform_get_ticks())
}
