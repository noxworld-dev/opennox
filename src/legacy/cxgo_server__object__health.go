package legacy

import (
	"unsafe"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_unitGiveXP_4EF270(a1 unsafe.Pointer, a2 float32) float64 {
	var (
		v3 int32
		v4 float64
		v5 float32
	)
	if float64(*(*float32)(unsafe.Add(a1, 28))) >= float64(a2) {
		return 0.0
	}
	v3 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v4 = float64((a2-*(*float32)(unsafe.Add(a1, 28)))**mem_getFloatPtr(0x587000, 206148)) + 1.0
	v5 = float32(v4)
	*(*float32)(unsafe.Add(a1, 28)) = float32(v4 + float64(*(*float32)(unsafe.Add(a1, 28))))
	sub_56FA40(int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 4604))), v5)
	sub_4D81A0(a1)
	sub_4EF2E0_exp_level(a1)
	return float64(v5)
}
func nox_xxx_soloMonsterKillReward_4EE500_obj_health(a1 *server.Object) {
	var (
		v3 int32
		v5 int32
		v6 float64
		v7 *wchar2_t
	)
	v1 := a1
	if a1 == nil {
		return
	}
	if !noxflags.HasGame(2048) {
		return
	}
	v2 := a1.Obj130
	if v2 == nil {
		return
	}
	v3 = 1
	v4 := unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580(a1.Obj130))
	if (int32(*(*uint8)(unsafe.Add(v4, 8))) & 4) == 0 {
		return
	}
	v5 = 0
	if v2 != v4 {
		for v2 != v4 {
			if v5 != 0 {
				break
			}
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 8)))&2 != 0 {
				v3 = nox_xxx_creatureIsMonitored_500CC0((*server.Object)(v4), v2)
				v5 = 1
			}
			v2 = v2.ObjOwner
		}
		if v3 == 0 {
			return
		}
		v1 = a1
	}
	v6 = nox_xxx_unitGiveXP_4EF270(v4, v1.Experience)
	if v6 > 0.0 {
		v7 = nox_strman_loadString_40F1D0(internCStr("gainpoints"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\health.c"), 172)
		nox_xxx_netSendLineMessage_4D9EB0((*server.Object)(v4), v7, uint32(int32(int64(v6))))
	}
	return
}
