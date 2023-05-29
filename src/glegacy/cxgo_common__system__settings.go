package legacy

import "github.com/gotranspile/cxgo/runtime/libc"

func sub_409FB0_settings(a1 int16, a2 uint16) {
	var (
		v2 int32
		v3 uint16
		v4 *wchar2_t
	)
	v2 = sub_409A70(a1)
	v3 = a2
	if int32(*memmap.PtrUint16(0x5D4594, uint32(v2*2+3488))) != int32(a2) {
		if int32(a2) > 0x3E7 {
			v3 = 999
		}
		*memmap.PtrUint16(0x5D4594, uint32(v2*2+3488)) = v3
		nox_server_gameSettingsUpdated = 1
		if nox_client_isConnected_43C700() != 0 {
			v4 = nox_strman_loadString_40F1D0(internCStr("parsecmd.c:lessonsset"), nil, internCStr("C:\\NoxPost\\src\\Common\\System\\settings.c"), 389)
			sub_440A20(v4, v3)
		}
	}
}
