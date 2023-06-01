package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_guiObjlistLoad_4530C0(a1 int32, a2 int32) int32 {
	var (
		v2  int32
		v3  *wchar2_t
		v4  int32
		v5  int32
		v6  int32
		v7  *wchar2_t
		v8  int32
		v9  int32
		v10 int32
		v11 *uint32
		v12 *uint32
		v14 [66]wchar2_t
	)
	v2 = 0
	dword_5d4594_1045468 = uint32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("objlst.wnd"), funAddrP(sub_4533D0)))))
	nox_xxx_wndSetDrawFn_46B340(*(*int32)(unsafe.Pointer(&dword_5d4594_1045468)), funAddrP(sub_453350))
	sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045468)))), (*nox_window)(unsafe.Pointer(uintptr(a1))))
	nox_xxx_wnd_46B280(*(*int32)(unsafe.Pointer(&dword_5d4594_1045468)), a1)
	dword_5d4594_1045464 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045468)))), 1510))))
	sub_4532E0()
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045464))))), 16399, 0, 0)
	if uint32(a2) == 0x1000000 {
		dword_5d4594_1045460 = 0
		v7 = nox_strman_loadString_40F1D0(internCStr("Weapons"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\objlst.c"), 321)
		nox_wcscpy(&v14[0], v7)
		v8 = 4
		v9 = 25
		for {
			v10 = sub_4159F0(v8)
			if v10 != 0 {
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045464))))), 16397, v10, -1)
				v2++
			}
			v8 *= 2
			v9--
			if v9 == 0 {
				break
			}
		}
	} else if uint32(a2) == 0x2000000 {
		dword_5d4594_1045460 = 1
		v3 = nox_strman_loadString_40F1D0(internCStr("servopts.wnd:Armor"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\objlst.c"), 308)
		nox_wcscpy(&v14[0], v3)
		v4 = 1
		v5 = 26
		for {
			v6 = sub_415E80(v4)
			if v6 != 0 {
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045464))))), 16397, v6, -1)
				v2++
			}
			v4 *= 2
			v5--
			if v5 == 0 {
				break
			}
		}
	}
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045464))))), 16385, int32(uintptr(unsafe.Pointer(&v14[0]))), 0)
	v11 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045468)))), 1513)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045464))))), 16408, int32(uintptr(unsafe.Pointer(v11))), 0)
	v12 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045468)))), 1514)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045464))))), 16409, int32(uintptr(unsafe.Pointer(v12))), 0)
	*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1045460)*4+1045472) = uint32(v2)
	sub_453750()
	if !nox_common_gameFlags_check_40A5C0(1) || nox_common_gameFlags_check_40A5C0(49152) {
		sub_46AD20(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045468)), 1515, 1533, 0)
	}
	return int32(dword_5d4594_1045468)
}
