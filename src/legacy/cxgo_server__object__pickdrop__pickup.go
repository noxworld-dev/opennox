package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_pickupGold_4F3A60_obj_pickup(obj *server.Object, obj2 *server.Object, a3 int, a4 int) int {
	a1 := obj.CObj()
	a2 := obj2.CObj()
	var (
		v3     *int32
		v4     *wchar2_t
		result int32
		v6     int32
		v7     int32
	)
	if int32(*(*uint8)(unsafe.Add(a1, 8)))&4 != 0 {
		v3 = *(**int32)(unsafe.Add(a2, 692))
		nox_xxx_playerAddGold_4FA590(a1, *v3)
		nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(a2))
		v7 = *v3
		v4 = nox_strman_loadString_40F1D0(internCStr("GoldPickup"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\pickdrop\\pickup.c"), 709)
		nox_xxx_netSendLineMessage_4D9EB0((*server.Object)(a1), v4, v7)
		nox_xxx_aud_501960(307, (*server.Object)(a1), 0, 0)
		result = 1
	} else {
		v6 = int32(Nox_xxx_pickupDefault_4F31E0(obj, obj2, a3, a4))
		if v6 != 0 {
			nox_xxx_aud_501960(307, (*server.Object)(a1), 0, 0)
		}
		result = v6
	}
	return int(result)
}
