package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_clientDrawAll_436100_draw_A() {
	if sub_436550() == 0 {
		nox_common_resetEngineFlag(NOX_ENGINE_FLAG_9)
	} else {
		nox_common_setEngineFlag(NOX_ENGINE_FLAG_9)
	}
	if *memmap.PtrUint32(0x5D4594, 814540) == 0 {
		*memmap.PtrUint32(0x5D4594, 814540) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("MenuSystemBG")))))
	}
	if nox_common_getEngineFlag(NOX_ENGINE_FLAG_9) {
		var v10 unsafe.Pointer = nox_xxx_guiFontPtrByName_43F360(internCStr("large"))
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 814540)))), 0, 0)
		var v11 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("InProgress"), nil, internCStr("C:\\NoxPost\\src\\client\\System\\client.c"), 1550)
		var v22 int32 = 0
		nox_xxx_drawGetStringSize_43F840(v10, v11, &v22, nil, 0)
		nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
		var v21 int32 = nox_win_height / 2
		var v20 int32 = (nox_win_width - v22) / 2
		var v12 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("InProgress"), nil, internCStr("C:\\NoxPost\\src\\client\\System\\client.c"), 1553)
		nox_xxx_drawString_43F6E0(v10, v12, v20, v21)
	}
}
func nox_xxx_clientDrawAll_436100_draw_B() {
	var v25 [128]wchar2_t
	nox_wcscpy(&v25[0], (*wchar2_t)(memmap.PtrOff(0x5D4594, 811376)))
	var v14 int32 = (nox_win_width - 310) / 2
	var v16 int32 = (nox_win_height - 200) / 2
	var v15 *int32 = mem_getI32Ptr(0x5D4594, *memmap.PtrUint32(0x5D4594, 811060)*4+811888)
	if *v15 == 0 {
		*v15 = int32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(*(**byte)(memmap.PtrOff(0x587000, uintptr(*memmap.PtrUint32(0x5D4594, 811060))*4+85712))))))
	}
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*v15))), v14, v16)
	var v22 int32 = 0
	var v23 int32 = 0
	nox_xxx_drawGetStringSize_43F840(nil, &v25[0], &v22, &v23, 220)
	var v17 int32 = v14 + 45
	var v18 int32 = v16 + (49-v23)/2 + 143
	nox_client_drawSetColor_434460(int32(nox_color_white_2523948))
	for tok := nox_wcstok(&v25[0], internWStr("\n\r")); tok != nil; tok = nox_wcstok(nil, internWStr("\n\r")) {
		nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
		nox_xxx_drawGetStringSize_43F840(nil, tok, &v22, nil, 0)
		nox_xxx_drawStringWrap_43FAF0(nil, tok, v17+(220-v22)/2, v18, 220, 0)
		v18 += nox_xxx_guiFontHeightMB_43F320(nil)
	}
}
func sub_436F50() int32 {
	var (
		v0     int32
		v2     int32
		v3     int32
		v4     *byte
		result int32
		v6     int32
		v7     *wchar2_t
		v8     int32
		v9     *wchar2_t
	)
	v0 = nox_xxx_guiFontHeightMB_43F320(nil)
	var rdr = nox_draw_getViewport_437250()
	v2 = int32(rdr.Screen.Min.X + 10)
	v3 = int32(rdr.Screen.Min.Y + 90)
	nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
	v4 = nox_server_currentMapGetFilename_409B30()
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 811120)), internWStr("%S"), v4)
	nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer(mem_getI16Ptr(0x5D4594, 811120))), v2, v3)
	result = int32(*memmap.PtrUint32(0x852978, 8))
	v6 = v0 + v3
	if *memmap.PtrUint32(0x852978, 8) != 0 {
		if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 811120)), internWStr("X:%d\tY:%d"), *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 12)), *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 16)))
			nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer(mem_getI16Ptr(0x5D4594, 811120))), v2, v6)
			v9 = nox_strman_loadString_40F1D0(*(**byte)(memmap.PtrOff(0x587000, uintptr(int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251)))*4+29456))), nil, internCStr("C:\\NoxPost\\src\\client\\System\\client.c"), 1357)
			v8 = int32(*(*byte)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 3684)))
			v7 = nox_strman_loadString_40F1D0(internCStr("PlayerInfo"), nil, internCStr("C:\\NoxPost\\src\\client\\System\\client.c"), 1355)
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 811120)), v7, v8, v9)
			result = nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer(mem_getI16Ptr(0x5D4594, 811120))), v2, v0+v6)
		}
	}
	return result
}
func nox_xxx_getRandomName_4358A0() *byte {
	var (
		v0 int32
		v1 **byte
		v2 *byte
		v4 [34]*byte
	)
	v0 = int32(*memmap.PtrUint32(0x5D4594, 814516))
	v4[0] = internCStr("Dweezle")
	v4[1] = internCStr("Glork")
	v4[2] = internCStr("Floogle")
	v4[3] = internCStr("Goombah")
	v4[4] = internCStr("Kraun")
	v4[5] = internCStr("Kloog")
	v4[6] = internCStr("Zurg")
	v4[7] = internCStr("Darg")
	v4[8] = internCStr("Arfingle")
	v4[9] = internCStr("Buurl")
	v4[10] = internCStr("Gurgin")
	v4[11] = internCStr("Grok")
	v4[12] = internCStr("Hurlong")
	v4[13] = internCStr("Luric")
	v4[14] = internCStr("Lupis")
	v4[15] = internCStr("Mallik")
	v4[16] = internCStr("Thrall")
	v4[17] = internCStr("Norwood")
	v4[18] = internCStr("Nulik")
	v4[19] = internCStr("Orin")
	v4[20] = internCStr("Olaf")
	v4[21] = internCStr("Orguk")
	v4[22] = internCStr("Pervis")
	v4[23] = internCStr("Paavik")
	v4[24] = internCStr("Qix")
	v4[25] = internCStr("Xevin")
	v4[26] = internCStr("Xurcon")
	v4[27] = internCStr("Markoan")
	v4[28] = internCStr("Yuric")
	v4[29] = internCStr("Yoovis")
	v4[30] = internCStr("Yalek")
	v4[31] = internCStr("Zug")
	v4[32] = internCStr("Zivik")
	v4[33] = nil
	if *memmap.PtrUint32(0x5D4594, 814516) == 0 {
		v1 = &v4[0]
		for {
			v2 = *(**byte)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*byte)(nil))*1))
			v1 = (**byte)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*byte)(nil))*1))
			v0++
			if v2 == nil {
				break
			}
		}
		*memmap.PtrUint32(0x5D4594, 814516) = uint32(v0)
	}
	return v4[nox_common_randomIntMinMax_415FF0(0, v0-1, internCStr("C:\\NoxPost\\src\\client\\System\\client.c"), 559)]
}
