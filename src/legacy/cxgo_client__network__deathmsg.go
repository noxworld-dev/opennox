package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_4952E0(a1 *uint16) {
	var (
		v1  *byte
		v2  *wchar2_t
		v3  *byte
		v4  *wchar2_t
		v5  *byte
		v6  *wchar2_t
		v8  int32
		v9  *wchar2_t
		v10 int32
		v11 [32]wchar2_t
		v12 [32]wchar2_t
		v13 [64]wchar2_t
	)
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*1))) != 0 && (func() *byte {
		v1 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*1))))))
		return v1
	}()) != nil {
		v8 = int32(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 4704)))))
		v2 = nox_strman_loadString_40F1D0(internCStr("die.c:LocalizeAttacker"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\deathmsg.c"), 48)
		nox_swprintf(&v13[0], v2, v8)
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*2))) != 0 {
			v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*2))))))
			if v3 != nil {
				nox_swprintf(&v12[0], (*wchar2_t)(unsafe.Pointer(internCStr(" + %s"))), (*byte)(unsafe.Add(unsafe.Pointer(v3), 4704)))
				nox_wcscat(&v13[0], &v12[0])
			}
		}
	} else {
		v9 = nox_strman_loadString_40F1D0(internCStr("die.c:AttackerNasty"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\deathmsg.c"), 65)
		v4 = nox_strman_loadString_40F1D0(internCStr("die.c:LocalizeAttacker"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\deathmsg.c"), 64)
		nox_swprintf(&v13[0], v4, v9)
	}
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*3))) != 0 {
		v5 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*3))))))
		if v5 != nil {
			v10 = int32(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v5), 4704)))))
			v6 = nox_strman_loadString_40F1D0(internCStr("die.c:LocalizeVictim"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\deathmsg.c"), 72)
			nox_swprintf(&v11[0], v6, v10)
		}
	}
	nox_gui_console_Printf_450C00(uint8(int8(NOX_CONSOLE_WHITE)), (*wchar2_t)(memmap.PtrOff(0x587000, 161668)), &v11[0], &v13[0])
}
