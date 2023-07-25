package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_netSendChat_528AC0(a1p *server.Object, a2 *wchar2_t, a3 wchar2_t) int32 {
	var (
		a1     = a1p
		v3     int8
		v4     int16
		v5     float64
		v6     int64
		v7     float64
		v8     int32
		result int32
		i      int32
		v11    [520]byte
	)
	v11[0] = 168
	v11[3] = 0
	if nox_xxx_cliCanTalkMB_4100F0((*int16)(unsafe.Pointer(a2))) != 0 {
		v3 = int8(v11[3] | 2)
	} else {
		v3 = int8(v11[3] | 4)
	}
	v11[3] = byte(v3)
	v4 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0(a1)))
	v5 = float64(a1.PosVec.X)
	*(*uint16)(unsafe.Pointer(&v11[1])) = uint16(v4)
	v6 = int64(v5)
	v7 = float64(a1.PosVec.Y)
	*(*uint16)(unsafe.Pointer(&v11[4])) = uint16(int16(v6))
	*(*uint16)(unsafe.Pointer(&v11[6])) = uint16(int16(int64(v7)))
	*(*uint16)(unsafe.Pointer(&v11[9])) = a3
	v11[8] = byte(nox_wcslen(a2) + 1)
	if v11[3]&4 != 0 {
		nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v11[11])), a2)
		v8 = 2
	} else {
		nox_sprintf(&v11[11], internCStr("%S"), a2)
		v8 = 1
	}
	result = nox_xxx_getFirstPlayerUnit_4DA7C0()
	for i = result; result != 0; i = result {
		nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 748)), 276)), 2064))), 1, &v11[0], v8*int32(v11[8])+11)
		result = nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(i))
	}
	return result
}
