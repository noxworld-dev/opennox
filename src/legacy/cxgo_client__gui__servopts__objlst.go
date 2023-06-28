package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_xxx_guiObjlistLoad_4530C0(a1 unsafe.Pointer, a2 int32) unsafe.Pointer {
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
	)
	v14, free14 := alloc.Make([]wchar2_t{}, 66)
	defer free14()
	v2 = 0
	dword_5d4594_1045468 = nox_new_window_from_file(internCStr("objlst.wnd"), sub_4533D0)
	nox_xxx_wndSetDrawFn_46B340(dword_5d4594_1045468, sub_453350)
	sub_46B120(dword_5d4594_1045468, (*gui.Window)(a1))
	nox_xxx_wnd_46B280(dword_5d4594_1045468, (*gui.Window)(a1))
	dword_5d4594_1045464 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045468, 1510)
	sub_4532E0()
	nox_window_call_field_94_fnc(dword_5d4594_1045464, 16399, 0, 0)
	if uint32(a2) == 0x1000000 {
		dword_5d4594_1045460 = 0
		v7 = nox_strman_loadString_40F1D0(internCStr("Weapons"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\objlst.c"), 321)
		nox_wcscpy(&v14[0], v7)
		v8 = 4
		v9 = 25
		for {
			v10 = sub_4159F0(v8)
			if v10 != 0 {
				nox_window_call_field_94_fnc(dword_5d4594_1045464, 16397, uintptr(v10), math.MaxUint32)
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
				nox_window_call_field_94_fnc(dword_5d4594_1045464, 16397, uintptr(v6), math.MaxUint32)
				v2++
			}
			v4 *= 2
			v5--
			if v5 == 0 {
				break
			}
		}
	}
	nox_window_call_field_94_fnc(dword_5d4594_1045464, 16385, uintptr(unsafe.Pointer(&v14[0])), 0)
	v11 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045468, 1513)))
	nox_window_call_field_94_fnc(dword_5d4594_1045464, 16408, uintptr(unsafe.Pointer(v11)), 0)
	v12 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045468, 1514)))
	nox_window_call_field_94_fnc(dword_5d4594_1045464, 16409, uintptr(unsafe.Pointer(v12)), 0)
	*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1045460)*4+1045472) = uint32(v2)
	sub_453750()
	if !noxflags.HasGame(1) || noxflags.HasGame(49152) {
		sub_46AD20(dword_5d4594_1045468, 1515, 1533, 0)
	}
	return int32(dword_5d4594_1045468)
}
