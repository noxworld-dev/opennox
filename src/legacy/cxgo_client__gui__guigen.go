package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_mapGenClientText_4A9D00(a1 *uint8) int16 {
	var (
		v1 *uint8
		v2 int32
		v3 int32
		v4 int32
		v5 *wchar2_t
		v6 int32
		v7 int32
	)
	v1 = a1
	v2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), 1)))
	if uint32(uint16(int16(v2))) == *memmap.PtrUint32(0x5D4594, 1309668) {
		return int16(v2)
	}
	*memmap.PtrUint32(0x5D4594, 1309668) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), 1)))
	nox_xxx_clientPlaySoundSpecial_452D80(897, 50)
	sub_430B50(0, 0, nox_win_width-1, nox_win_height-1)
	nox_client_clearScreen_440900()
	v3 = nox_win_height/2 - 120
	v4 = nox_win_width/2 - 160
	nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, uintptr((*memmap.PtrUint32(0x5D4594, 1309672)%4))*4+1309644)), v4, v3)
	nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 1309672))*4+1309516)), v4, v3)
	switch *v1 {
	case 0x9B:
		v5 = nox_strman_loadString_40F1D0(internCStr("Generating"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guigen.c"), 89)
		*memmap.PtrPtr(0x5D4594, 1309660) = unsafe.Pointer(v5)
	case 0x9C:
		v5 = nox_strman_loadString_40F1D0(internCStr("Assembling"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guigen.c"), 92)
		*memmap.PtrPtr(0x5D4594, 1309660) = unsafe.Pointer(v5)
	case 0x9D:
		v5 = nox_strman_loadString_40F1D0(internCStr("Populating"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guigen.c"), 95)
		*memmap.PtrPtr(0x5D4594, 1309660) = unsafe.Pointer(v5)
	}
	nox_xxx_drawGetStringSize_43F840(nil, *(**uint16)(memmap.PtrOff(0x5D4594, 1309660)), (*int32)(unsafe.Pointer(&a1)), nil, 0)
	v6 = int32(uint32(nox_win_width) - uint32(uintptr(unsafe.Pointer(a1))))
	v7 = nox_win_height/2 - (nox_xxx_guiFontHeightMB_43F320(nil)*2 + 70)
	nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
	nox_xxx_drawSetColor_4343E0(*memmap.PtrInt32(0x852978, 4))
	nox_draw_drawStringHL_43F730(nil, (*wchar2_t)(unsafe.Pointer(*(**int16)(memmap.PtrOff(0x5D4594, 1309660)))), v6/2, v7)
	if func() uint32 {
		p := memmap.PtrUint32(0x5D4594, 1309672)
		*p++
		return *p
	}() >= 32 {
		*memmap.PtrUint32(0x5D4594, 1309672) = 0
	}
	nox_video_callCopyBackBuffer_4AD170()
	return int16(v2)
}
