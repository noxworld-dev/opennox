package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_49C820() int32 {
	var (
		v1 **byte
		v2 *wchar2_t
	)
	dword_5d4594_1305684 = nox_new_window_from_file(internCStr("conntype.wnd"), sub_49CA60)
	sub_46B120(dword_5d4594_1305684, nil)
	nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1305684)
	sub_46C690(dword_5d4594_1305684)
	nox_xxx_windowFocus_46B500(dword_5d4594_1305684)
	sub_49C910()
	nox_window_setPos_46A9B0(dword_5d4594_1305684, int32(int(nox_win_width/2)-dword_5d4594_1305684.SizeVal.X/2), int32(int(nox_win_height/2)-dword_5d4594_1305684.SizeVal.Y/2))
	nox_xxx_guiServerOptsLoad_457500()
	sub_459D80(1)
	v0 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1305684, 10352)
	v1 = (**byte)(memmap.PtrOff(0x587000, 164928))
	for {
		v2 = nox_strman_loadString_40F1D0(*v1, nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\conntype.c"), 158)
		nox_window_call_field_94_fnc(v0, 16397, uintptr(unsafe.Pointer(v2)), math.MaxUint32)
		v1 = (**byte)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*byte)(nil))*1))
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x587000, 164944))) {
			break
		}
	}
	return int32(nox_window_call_field_94_fnc(v0, 16403, 0, 0))
}
func sub_49C910() {
	var (
		v2  **byte
		v3  int32
		v4  int32
		v5  *uint16
		v6  int32
		v7  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
	)
	v0 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1305684, 10352)
	v1 := v0
	v2 = (**byte)(memmap.PtrOff(0x587000, 164928))
	v3 = (nox_xxx_guiFontHeightMB_43F320(v0.DrawData().FontPtr) + 1) * 5
	v1.EndPos.Y = v1.Off.Y + int(uint32(v3)) + 2
	v1.SizeVal.Y = int(uint32(v3 + 2))
	v4 = 0
	for {
		v5 = nox_strman_loadString_40F1D0(*v2, nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\conntype.c"), 53)
		nox_xxx_drawGetStringSize_43F840(v1.DrawData().FontPtr, v5, &v11, nil, 0)
		if v11 > v4 {
			v4 = v11
		}
		v2 = (**byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((*byte)(nil))*1))
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 164944))) {
			break
		}
	}
	v6 = v4 + 7
	nox_xxx_drawGetStringSize_43F840(v1.DrawData().FontPtr, (*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*54)), &v12, nil, 0)
	if v6 <= v12 {
		v6 = v12
	}
	v7 = int32(v1.Off.X)
	v1.SizeVal.X = int(uint32(v6))
	v1.EndPos.X = int(uint32(v7 + v6))
	dword_5d4594_1305684.Off.X = int(uint32(v7 - 40))
	dword_5d4594_1305684.Off.Y = v1.Off.Y - 40
	dword_5d4594_1305684.EndPos.X = v1.EndPos.X + 40
	dword_5d4594_1305684.EndPos.Y = v1.EndPos.Y + 40
	dword_5d4594_1305684.SizeVal.X = v1.SizeVal.X + 80
	dword_5d4594_1305684.SizeVal.Y = v1.SizeVal.Y + 80
	result := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1305684, 10353)
	result.Off.Y = v1.EndPos.Y + 10
	v9 = int32(result.SizeVal.X)
	v10 = int32(result.Off.Y)
	result.Off.X = v1.EndPos.X - int(uint32(v9))
	result.EndPos.Y = uint32(v10) + result.SizeVal.Y
	result.EndPos.X = uint32(v9) + result.Off.X
}
