package legacy

import (
	"unsafe"
)

func nox_xxx_pickupGold_4F3A60_obj_pickup(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v3     *int32
		v4     *wchar2_t
		result int32
		v6     int32
		v7     int32
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		v3 = *(**int32)(unsafe.Pointer(uintptr(a2 + 692)))
		nox_xxx_playerAddGold_4FA590(a1, *v3)
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
		v7 = *v3
		v4 = nox_strman_loadString_40F1D0(internCStr("GoldPickup"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\pickdrop\\pickup.c"), 709)
		nox_xxx_netSendLineMessage_4D9EB0(a1, v4, v7)
		nox_xxx_aud_501960(307, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		result = 1
	} else {
		v6 = nox_xxx_pickupDefault_4F31E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), a3)
		if v6 != 0 {
			nox_xxx_aud_501960(307, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
		result = v6
	}
	return result
}
