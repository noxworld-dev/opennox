package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_common_maplist nox_list_item_t = nox_list_item_t{}

func nox_xxx_updDrawDBall_4CDF80(a1 int32, a2 int32) int32 {
	nox_xxx_updDrawAddRndSpark_4CDFA0(a2, (*uint32)(unsafe.Pointer(uintptr(3))))
	return 1
}
func sub_4CE0A0(a1 int32, a2 int32) int32 {
	nox_xxx_updDrawAddRndSpark_4CDFA0(a2, (*uint32)(unsafe.Pointer(uintptr(1))))
	return 1
}
func nox_xxx_updDrawCloud_4CE1D0(a1 int32, a2 int32) int32 {
	if int32(uint8(gameFrame()))&1 != 0 {
		sub_4CE200(a1, a2, 1, 75)
	}
	return 1
}
func sub_4CE340(a1 int32, a2 int32) int32 {
	*(*uint16)(unsafe.Pointer(uintptr(a2 + 104))) += uint16(*(*uint8)(unsafe.Pointer(uintptr(a2 + 432))))
	return 1
}
func sub_4CE360(a1 int32, a2 int32) int32 {
	if int32(uint8(gameFrame()))&1 != 0 {
		sub_4CE200(a1, a2, 1, 35)
	}
	return 1
}
func nox_xxx_updDrawColorlight_4CE390(a1 *uint32, a2 int32) int32 {
	var (
		result int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 432)))) != 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 433)))) != 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 434)))) != 0 {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 12))))
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		if v3 >= v4-100 && uint32(v3) <= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8))+uint32(v4)+100 {
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
			v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
			if v6 >= v5-100 && uint32(v6) <= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9))+uint32(v5)+100 && !noxflags.HasGame(0x200000) {
				nox_xxx_colorLightAlterB0ArrayColor_4CE440(a2)
				nox_xxx_colorLightAlterIntensity_4CE610(a2)
				nox_xxx_colorLightAlterRadius_4CE760(a2)
				sub_4CE960(a2)
				sub_4CE8C0(a2)
			}
		}
		result = 1
	} else {
		sub_49BCD0((*nox_drawable)(unsafe.Pointer(uintptr(a2))))
		result = 1
	}
	return result
}
func nox_xxx_colorLightAlterB0ArrayColor_4CE440(a1 int32) {
	var (
		v1  int32
		v2  int8
		v3  float64
		v4  int64
		v5  float64
		v6  float64
		v7  int8
		v8  int8
		v9  int32
		v10 float64
		v11 int32
		v12 int8
		v13 float32
		v14 int32
		v15 int8
	)
	v1 = a1
	v2 = int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 432))))
	v12 = int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 432))))
	if int32(v2) > 1 && int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 258)))) != 0 {
		v3 = float64(gameFrame()) / float64(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 258))))*int32(v2))
		v4 = int64(v3)
		v5 = v3 - float64(int32(int64(v3)))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 176))))&1 != 0 {
			v6 = v5 * float64(v2)
			v15 = int8(int64(v6))
			v7 = int8(int32(v15) + 1)
			if int32(int8(int32(v15)+1)) >= int32(v12) {
				v7 = 0
			}
		} else {
			v6 = v5 * float64(v2)
			if v4&1 != 0 {
				v8 = int8(uint8(uint64(v2) - uint64(int64(v6)) - 1))
				v15 = v8
				v7 = int8(int32(v8) - 1)
				if int32(v7) < 0 {
					v7 = 0
				}
			} else {
				v15 = int8(int64(v6))
				v7 = int8(int32(v15) + 1)
				if int32(int8(int32(v15)+1)) >= int32(v12) {
					v7 = int8(int32(v12) - 1)
				}
			}
		}
		v13 = float32(float64(*(*uint16)(unsafe.Pointer(uintptr(v1 + 258)))))
		v9 = int32(v7)
		v10 = float64(uint8(int8(int64((v6 - float64(int32(int64(v6)))) * float64(v13)))))
		v11 = v1 + int32(v15)*2 + int32(v15)
		v14 = int32(*(*uint8)(unsafe.Pointer(uintptr(int32(v15) + v1 + int32(v15)*2 + 120 + 60))))
		nox_xxx_spriteChangeLightColor_484BE0((*uint32)(unsafe.Pointer(uintptr(v1+136))), int32(int64(float64(int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + v1 + v9*2 + 178))))-int32(*(*uint8)(unsafe.Pointer(uintptr(v11 + 178)))))/float64(v13)*v10+float64(*(*uint8)(unsafe.Pointer(uintptr(v11 + 178)))))), int32(int64(float64(int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + v1 + v9*2 + 179))))-int32(*(*uint8)(unsafe.Pointer(uintptr(v11 + 179)))))/float64(v13)*v10+float64(*(*uint8)(unsafe.Pointer(uintptr(v11 + 179)))))), int32(int64(float64(int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + v1 + v9*2 + 120 + 60))))-v14)/float64(v13)*v10+float64(v14))))
	}
}
func nox_xxx_colorLightAlterIntensity_4CE610(a1 int32) {
	var (
		v1  int32
		v2  float64
		v3  int64
		v4  float64
		v5  float64
		v6  int64
		v7  int8
		v8  float32
		v9  int8
		v10 float32
	)
	v1 = a1
	v9 = int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 433))))
	if int32(v9) > 1 && int32(*(*uint16)(unsafe.Pointer(uintptr(v1 + 260)))) != 0 {
		v2 = float64(gameFrame()) / float64(int32(*(*uint16)(unsafe.Pointer(uintptr(v1 + 260))))*int32(v9))
		v3 = int64(v2)
		v4 = v2 - float64(int32(int64(v2)))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 176))))&4 != 0 {
			v5 = v4 * float64(v9)
			v6 = int64(v5)
			v7 = int8(uint8(uint64(int64(v5)) + 1))
			if int32(v7) >= int32(v9) {
				v7 = 0
			}
		} else {
			v5 = v4 * float64(v9)
			if v3&1 != 0 {
				*((*uint8)(unsafe.Pointer(&v6))) = uint8(uint64(v9) - uint64(int64(v5)) - 1)
				v7 = int8(uint8(uint64(v9) - uint64(int64(v5)) - 2))
				if int32(v7) < 0 {
					v7 = 0
				}
			} else {
				v6 = int64(v5)
				v7 = int8(uint8(uint64(int64(v5)) + 1))
				if int32(v7) >= int32(v9) {
					v7 = int8(int32(v9) - 1)
				}
			}
		}
		v10 = float32(float64(*(*uint16)(unsafe.Pointer(uintptr(v1 + 260)))))
		v8 = float32(float64(uint8(int8(int64((v5-float64(int32(int64(v5))))*float64(v10)))))*(float64(int32(*(*uint8)(unsafe.Pointer(uintptr(int32(v7) + v1 + 226))))-int32(*(*uint8)(unsafe.Pointer(uintptr(int32(int8(v6)) + v1 + 226)))))/float64(v10)) + float64(*(*uint8)(unsafe.Pointer(uintptr(int32(int8(v6)) + v1 + 226)))))
		nox_xxx_spriteChangeIntensity_484D70_light_intensity(v1+136, v8)
	}
}
func nox_xxx_colorLightAlterRadius_4CE760(a1 int32) int32 {
	var (
		v1     int32
		result int32
		v3     int8
		v4     float64
		v5     int64
		v6     float64
		v7     float64
		v8     int64
		v9     int8
		v10    int8
		v11    int8
		v12    float32
	)
	v1 = a1
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 168))))
	v3 = int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 434))))
	v11 = int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 434))))
	if result == 0 && int32(*(*uint16)(unsafe.Pointer(uintptr(v1 + 262)))) > 0 && int32(v3) > 1 {
		v4 = float64(gameFrame()) / float64(int32(*(*uint16)(unsafe.Pointer(uintptr(v1 + 262))))*int32(v3))
		v5 = int64(v4)
		v6 = v4 - float64(int32(int64(v4)))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 176))))&0x10 != 0 {
			v7 = v6 * float64(v3)
			v8 = int64(v7)
			v9 = int8(uint8(uint64(int64(v7)) + 1))
			if int32(v9) >= int32(v11) {
				v9 = 0
			}
		} else {
			v7 = v6 * float64(v3)
			if v5&1 != 0 {
				v10 = int8(uint8(uint64(v3) - uint64(int64(v7)) - 1))
				*((*uint8)(unsafe.Pointer(&v8))) = uint8(v10)
				v9 = int8(int32(v10) - 1)
				if int32(v9) < 0 {
					v9 = 0
				}
			} else {
				v8 = int64(v7)
				v9 = int8(uint8(uint64(int64(v7)) + 1))
				if int32(v9) >= int32(v11) {
					v9 = int8(int32(v11) - 1)
				}
			}
		}
		v12 = float32(float64(*(*uint16)(unsafe.Pointer(uintptr(v1 + 262)))))
		result = int32(nox_xxx_spriteChangeLightSize_484C30(v1+136, int32(int64(float64(uint8(int8(int64((v7-float64(int32(int64(v7))))*float64(v12)))))*(float64(int32(*(*uint8)(unsafe.Pointer(uintptr(int32(v9) + v1 + 242))))-int32(*(*uint8)(unsafe.Pointer(uintptr(int32(int8(v8)) + v1 + 242)))))/float64(v12))+float64(*(*uint8)(unsafe.Pointer(uintptr(int32(int8(v8)) + v1 + 242))))))))
	}
	return result
}
func sub_4CE8C0(a1 int32) {
	var (
		v1 *uint32
		v2 int32
		v3 float64
		v4 int32
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 176))))&0x40 != 0 {
		v1 = &nox_xxx_netSpriteByCodeStatic_45A720(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 264))))).Field_0
		if v1 != nil {
			v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*4)) - *(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
			v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3)) - *(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
			v3 = float64(float32(math.Acos(float64(v4)/math.Sqrt(float64(v4*v4+v2*v2))))) * 57.295776
			if v2 < 0 {
				v3 = 360.0 - v3
			}
			sub_484C00(a1+136, int32(int64(v3)))
		}
	}
}
func sub_4CE960(a1 int32) {
	var (
		v2 int16
		v3 float64
		v4 float64
		v5 float64
	)
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 168))) == 0 {
		return
	}
	v2 = int16(*(*uint16)(unsafe.Pointer(uintptr(a1 + 176))))
	if (int32(v2) & 0x80) == 0 {
		return
	}
	var v1 int16 = int16(*(*uint16)(unsafe.Pointer(uintptr(a1 + 270))))
	if int32(v1) == 0 {
		return
	}
	if (int32(v2) & 0x100) == 256 {
		v5 = float64(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 272)))) - int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 268)))))
	} else {
		v5 = 360.0
	}
	v4 = float64(gameFPS())
	v3 = float64(v1)
	var v6 int32 = int32((float64(gameFrame())/(v5/v3*v4)-float64(int32(int64(float64(gameFrame())/(v5/v3*v4)))))*(v5/v3*v4)*(v3/v4) + float64(*(*uint16)(unsafe.Pointer(uintptr(a1 + 268)))))
	if v6 >= 0 {
		if v6 >= 360 {
			v6 -= 360
		}
	} else {
		v6 += 360
	}
	sub_484C00(a1+136, v6)
}
func sub_4CEBA0(a1 int32, a2 *byte) int32 {
	var (
		v2 *uint32
		v3 *uint32
		v4 *byte
		v5 *uint32
		v6 *uint32
		v8 *uint32
		v9 *byte
	)
	dword_5d4594_1523024 = uint32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("rulelist.wnd"), sub_4CF060))))
	dword_5d4594_1523028 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), 10170))))
	dword_5d4594_1523032 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), 10171))))
	dword_5d4594_1523036 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), 10172))))
	dword_5d4594_1523040 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), 10173))))
	dword_5d4594_1523044 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), 10174))))
	dword_5d4594_1523048 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), 10175))))
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), 10176)))
	nox_xxx_wndSetDrawFn_46B340((*gui.Window)(unsafe.Pointer(v2)), sub_4CEED0)
	sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), (*gui.Window)(unsafe.Pointer(uintptr(a1))))
	v3 = *(**uint32)(unsafe.Pointer(uintptr(dword_5d4594_1523028 + 32)))
	v9 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UISlider"))))
	v4 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UISliderLit"))))
	v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), 10179)))
	v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), 10177)))
	v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), 10178)))
	*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*100)) + 8))) = 16
	*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*100)) + 12))) = 10
	sub_4B5700(int32(uintptr(unsafe.Pointer(v5))), 0, 0, int32(uintptr(unsafe.Pointer(v9))), int32(uintptr(unsafe.Pointer(v4))), int32(uintptr(unsafe.Pointer(v4))))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v5))), *(*int32)(unsafe.Pointer(&dword_5d4594_1523028)))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v6))), *(*int32)(unsafe.Pointer(&dword_5d4594_1523028)))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v8))), *(*int32)(unsafe.Pointer(&dword_5d4594_1523028)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*9)) = uint32(uintptr(unsafe.Pointer(v5)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*7)) = uint32(uintptr(unsafe.Pointer(v6)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*8)) = uint32(uintptr(unsafe.Pointer(v8)))
	sub_4CED40(a2)
	return int32(dword_5d4594_1523024)
}
func sub_4CED40(a1 *byte) {
	var (
		result       HANDLE
		v2           HANDLE
		FindFileData WIN32_FIND_DATAA
		FileName     [64]byte
		v5           [100]wchar2_t
	)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16399, 0, 0)
	nox_sprintf(&FileName[0], internCStr("maps\\%s\\*.rul"), a1)
	result = compatFindFirstFileA(&FileName[0], &FindFileData)
	v2 = result
	if uintptr(result) != uintptr(math.MaxUint32) {
		FindFileData.cFileName[libc.StrLen(&FindFileData.cAlternateFileName[0])+256] = 0
		if nox_strcmpi(a1, &FindFileData.cAlternateFileName[0]) != 0 && nox_strcmpi(internCStr("user"), &FindFileData.cAlternateFileName[0]) != 0 {
			nox_swprintf(&v5[0], (*wchar2_t)(unsafe.Pointer(internCStr("%S"))), &FindFileData.cAlternateFileName[0])
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16397, uintptr(unsafe.Pointer(&v5[0])), math.MaxUint32)
		}
		for compatFindNextFileA(v2, &FindFileData) != 0 {
			FindFileData.cFileName[libc.StrLen(&FindFileData.cAlternateFileName[0])+256] = 0
			if nox_strcmpi(a1, &FindFileData.cAlternateFileName[0]) != 0 {
				if nox_strcmpi(internCStr("user"), &FindFileData.cAlternateFileName[0]) != 0 {
					nox_swprintf(&v5[0], (*wchar2_t)(unsafe.Pointer(internCStr("%S"))), &FindFileData.cAlternateFileName[0])
					nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16397, uintptr(unsafe.Pointer(&v5[0])), math.MaxUint32)
				}
			}
		}
		compatFindClose(v2)
	}
}
func sub_4CEED0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = int32(uintptr(win.C()))
		a2    = int32(uintptr(draw.C()))
		v2    int32
		v3    int8
		v4    *uint16
		v5    *uint32
		xLeft int32
		yTop  int32
	)
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(uintptr(a1))), (*uint32)(unsafe.Pointer(&xLeft)), (*uint32)(unsafe.Pointer(&yTop)))
	if int32(int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 4))))) >= 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(a2 + 20))) != 0x80000000 {
			nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))), int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12)))))
		}
	} else {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a2 + 24)))))), xLeft, yTop)
	}
	v2 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16404, 0, 0))
	v3 = int8(*(*uint8)(unsafe.Pointer(uintptr(dword_5d4594_1523040 + 4))))
	if v2 < 0 {
		if int32(v3)&8 != 0 {
			nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523040))))), 0)
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(dword_5d4594_1523044 + 4))))&8 != 0 {
			nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523044))))), 0)
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(dword_5d4594_1523048 + 4))))&8 != 0 {
			nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523048))))), 0)
		}
	} else {
		if (int32(v3) & 8) == 0 {
			nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523040))))), 1)
		}
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(dword_5d4594_1523044 + 4))))&8) == 0 && !noxflags.HasGame(49152) {
			nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523044))))), 1)
		}
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(dword_5d4594_1523048 + 4)))) & 8) == 0 {
			nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523048))))), 1)
		}
	}
	v4 = (*uint16)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523032))))), 16413, 0, 0))))
	v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetFocus_46B4F0()))
	if v5 != nil && *v5 == 10171 {
		if v4 != nil && int32(*v4) != 0 {
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(dword_5d4594_1523036 + 4)))) & 8) == 0 {
				nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523036))))), 1)
				return 1
			}
		} else if int32(*(*uint8)(unsafe.Pointer(uintptr(dword_5d4594_1523036 + 4))))&8 != 0 {
			nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523036))))), 0)
		}
	}
	return 1
}
func sub_4CF060(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v4  *uint32
		v6  *byte
		v7  *byte
		v8  *byte
		v9  int32
		v10 int32
		v11 int32
		v12 *byte
		v13 *byte
		v14 *byte
		v15 int32
		v16 int32
		v17 *byte
		v18 *byte
		v19 int32
		v20 int32
		v21 int32
		v22 *wchar2_t
		v23 *byte
		v24 *byte
		v25 int32
		v26 int32
		v27 *wchar2_t
		v28 [16]byte
	)
	if a2 > 0x4007 {
		if a2 == 16400 {
			nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
		}
		return 1
	}
	if a2 != 16391 {
		if a2 != 23 && a2 == 16387 {
			v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1523024)))), int32(a4))))
			if v4 == nil {
				return 0
			}
			if int32(uint16(uintptr(unsafe.Pointer(a3)))) == 1 {
				return 0
			}
			v6 = (*byte)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), 16413, 0, 0))))
			v7 = v6
			if v6 != nil {
				if *v6 != 0 {
					libc.Atoi(libc.GoString(v6))
					if a4 == 10171 {
						v8 = sub_4165B0()
						if nox_strcmpi(v7, v8) == 0 || nox_strcmpi(v7, internCStr("user")) == 0 {
							nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523036))))), 0)
							return 1
						}
					}
				}
			}
		}
		return 1
	}
	v9 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	switch v9 {
	case 10172:
		sub_416580()
		v22 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523032))))), 16413, 0, 0))))
		nox_sprintf(&v28[0], internCStr("%S%s"), v22, memmap.PtrOff(0x587000, 191640))
		v23 = sub_4165B0()
		sub_459AA0(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v23))))))
		v24 = sub_4165B0()
		sub_57AAA0(&v28[0], v24, nil)
		v25 = 0
		v26 = int32(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1523028 + 32))))
		if int32(*(*int16)(unsafe.Pointer(uintptr(v26 + 44)))) <= 0 {
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16397, uintptr(unsafe.Pointer(v22)), math.MaxUint32)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523032))))), 16414, uintptr(memmap.PtrOff(0x5D4594, 1523056)), 0)
			nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523036))))), 0)
			return 1
		}
	case 10173:
		sub_416580()
		v10 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16404, 0, 0))
		v11 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16406, uintptr(v10), 0))
		nox_sprintf(&v28[0], internCStr("%S%s"), v11, memmap.PtrOff(0x587000, 191592))
		v12 = sub_4165B0()
		sub_459AA0(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v12))))))
		v13 = sub_4165B0()
		sub_57AAA0(&v28[0], v13, nil)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16403, math.MaxUint32, 0)
		return 1
	case 10174:
		sub_416580()
		v14 = sub_4165B0()
		v15 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16404, 0, 0))
		v16 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16406, uintptr(v15), 0))
		nox_sprintf(&v28[0], internCStr("%S%s"), v16, memmap.PtrOff(0x587000, 191608))
		sub_57A1E0((*int32)(unsafe.Pointer(v14)), &v28[0], nil, 7, int16(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v14))), unsafe.Sizeof(uint16(0))*26)))))
		sub_453F70(unsafe.Add(unsafe.Pointer(v14), 24))
		sub_4535E0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v14))), 4*11)))
		sub_4535F0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v14))), 4*12)))))
		v17 = sub_4165B0()
		sub_459880(int32(uintptr(unsafe.Pointer(v17))))
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16403, math.MaxUint32, 0)
		sub_459D50(1)
		return 1
	case 10175:
		v18 = sub_4165B0()
		v19 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16404, 0, 0))
		v20 = v19
		v21 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16406, uintptr(v19), 0))
		nox_sprintf(&v28[0], internCStr("%S%s"), v21, memmap.PtrOff(0x587000, 191624))
		sub_57A9F0(v18, &v28[0])
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16398, uintptr(v20), 0)
		return 1
	default:
		return 1
	}
	for {
		v27 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16406, uintptr(v25), 0))))
		if _nox_wcsicmp(v22, v27) == 0 {
			break
		}
		if func() int32 {
			p := &v25
			*p++
			return *p
		}() >= int32(*(*int16)(unsafe.Pointer(uintptr(v26 + 44)))) {
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523028))))), 16397, uintptr(unsafe.Pointer(v22)), math.MaxUint32)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523032))))), 16414, uintptr(memmap.PtrOff(0x5D4594, 1523056)), 0)
			nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523036))))), 0)
			return 1
		}
	}
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1523032))))), 16414, uintptr(memmap.PtrOff(0x5D4594, 1523052)), 0)
	return 1
}
func nox_xxx_mapValidateMB_4CF470(a1 *byte, a2 int32) int32 {
	var (
		v2       int32
		v4       int32
		v5       int32
		FileName [1024]byte
	)
	v2 = 0
	if a2 == 0 {
		return 6
	}
	if a1 != nil {
		if libc.StrChr(a1, '\\') != nil {
			libc.StrCpy(&FileName[0], a1)
		} else {
			libc.StrCpy(&FileName[0], internCStr("maps\\"))
			libc.StrNCat(&FileName[0], a1, 1024-6)
			FileName[libc.StrLen(&FileName[0])-4] = 0
			*(*uint16)(unsafe.Pointer(&FileName[libc.StrLen(&FileName[0])])) = *memmap.PtrUint16(0x587000, 191672)
			libc.StrCat(&FileName[0], a1)
		}
		if nox_fs_access(&FileName[0], 0) != -1 {
			v4 = 0
			if nox_fs_access(&FileName[0], 2) == -1 {
				v2 = 1
			}
			if nox_xxx_cryptOpen_426910(&FileName[0], 1, 19) != 0 {
				v2 |= 2
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 4)
				if v5 != -86065425 && v5 == -86050098 {
					nox_xxx_fileCryptReadCrcMB_426C20((*uint8)(unsafe.Pointer(&v4)), 4)
					if v4 == a2 {
						v2 |= 4
					}
				}
				nox_xxx_cryptClose_4269F0()
			}
		}
	}
	return v2
}
func nox_xxx_mapFindCrown_4CFC30() {
	var (
		v0 int32
		v1 int32
	)
	if *memmap.PtrUint32(0x5D4594, 1523076) == 0 {
		*memmap.PtrUint32(0x5D4594, 1523076) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Crown")))
	}
	v0 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if v0 != 0 {
		for {
			v1 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(v0)))))))
			if uint32(*(*uint16)(unsafe.Pointer(uintptr(v0 + 4)))) == *memmap.PtrUint32(0x5D4594, 1523076) {
				nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(unsafe.Pointer(uintptr(v0))))
				sub_4EC6A0(v0)
			}
			v0 = v1
			if v1 == 0 {
				break
			}
		}
	}
}
func sub_4CFDF0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1523072) = uint32(a1)
	return result
}
func sub_4CFE00() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1523072))
}
func nox_xxx_mapGetTypeMB_4CFFA0(a1 unsafe.Pointer) int32 {
	return nox_mapToGameFlags_4CFF50(int32(*(*uint32)(unsafe.Pointer(uintptr(int32(uintptr(a1)) + 1392)))))
}
func sub_4CFFC0(a1 int32) int32 {
	return nox_mapToGameFlags_4CFF50(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 28)))))
}
func nox_xxx_interesting_xfer_4D0010(a1 *uint32, a2 int32) int32 {
	var (
		i   int32
		v3  *uint32
		v4  *byte
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 *byte
		v16 int32
		v17 int32
		v18 *byte
		v19 int32
		v20 *uint32
		v21 int32
		v22 int32
		v23 *byte
	)
	for i = int32(uintptr(unsafe.Pointer(nox_server_getFirstObjectUninited_4DA870()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_server_getNextObjectUninited_4DA880((*server.Object)(unsafe.Pointer(uintptr(i))))))) {
		*(*uint32)(unsafe.Pointer(uintptr(i + 44))) = *(*uint32)(unsafe.Pointer(uintptr(i + 40)))
		*(*uint32)(unsafe.Pointer(uintptr(i + 40))) = uint32(func() int32 {
			p := &a2
			x := *p
			*p++
			return x
		}())
	}
	v3 = (*uint32)(unsafe.Pointer(nox_server_getFirstObjectUninited_4DA870()))
	if v3 == nil {
		return a2
	}
	for {
		v4 = nox_xxx_getUnitName_4E39D0((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))))
		v5 := nox_objectTypeGetXfer(v4)
		if v5 == ccall.FuncAddr(nox_xxx_XFerElevator_4F53D0) {
			v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*187)))
			v7 = int32(uintptr(unsafe.Pointer(sub_4CFFE0(int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 8))))))))
			if v7 == 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v6 + 8))) = 0
				*(*uint32)(unsafe.Pointer(uintptr(v6 + 4))) = 0
			} else {
				v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 40))))
				*(*uint32)(unsafe.Pointer(uintptr(v6 + 4))) = uint32(v7)
				*(*uint32)(unsafe.Pointer(uintptr(v6 + 8))) = uint32(v8)
			}
		} else if v5 == ccall.FuncAddr(nox_xxx_XFerElevatorShaft_4F54A0) {
			v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*187)))
			v9 = int32(uintptr(unsafe.Pointer(sub_4CFFE0(int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 8))))))))
			if v9 != 0 {
				v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(v9 + 40))))
				*(*uint32)(unsafe.Pointer(uintptr(v6 + 4))) = uint32(v9)
				*(*uint32)(unsafe.Pointer(uintptr(v6 + 8))) = uint32(v10)
			} else {
				*(*uint32)(unsafe.Pointer(uintptr(v6 + 8))) = 0
				*(*uint32)(unsafe.Pointer(uintptr(v6 + 4))) = 0
			}
		} else if v5 == ccall.FuncAddr(nox_xxx_XFerTransporter_4F5300) {
			v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*187)))
			v12 = int32(uintptr(unsafe.Pointer(sub_4CFFE0(int32(*(*uint32)(unsafe.Pointer(uintptr(v11 + 16))))))))
			if v12 != 0 {
				v13 = int32(*(*uint32)(unsafe.Pointer(uintptr(v12 + 40))))
				*(*uint32)(unsafe.Pointer(uintptr(v11 + 12))) = uint32(v12)
				*(*uint32)(unsafe.Pointer(uintptr(v11 + 16))) = uint32(v13)
			} else {
				*(*uint32)(unsafe.Pointer(uintptr(v11 + 16))) = 0
				*(*uint32)(unsafe.Pointer(uintptr(v11 + 12))) = 0
			}
		} else if v5 == ccall.FuncAddr(nox_xxx_XFerHole_4F51D0) {
			v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*175)))
			v15 = nox_xxx_mapGetWallSize_426A70()
			v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(v14 + 12))))
			*(*uint32)(unsafe.Pointer(uintptr(v14 + 8))) += *a1 - *(*uint32)(unsafe.Pointer(v15))*23
			*(*uint32)(unsafe.Pointer(uintptr(v14 + 12))) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v15))), 4*1)))*23 + uint32(v16)
		} else if v5 == ccall.FuncAddr(nox_xxx_XFerExit_4F4B90) {
			v17 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*175)))
			v18 = nox_xxx_mapGetWallSize_426A70()
			*(*float32)(unsafe.Pointer(uintptr(v17 + 80))) = float32(float64(int32(*a1-*(*uint32)(unsafe.Pointer(v18))*23)) + float64(*(*float32)(unsafe.Pointer(uintptr(v17 + 80)))))
			*(*float32)(unsafe.Pointer(uintptr(v17 + 84))) = float32(float64(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1))-*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v18))), 4*1)))*23)) + float64(*(*float32)(unsafe.Pointer(uintptr(v17 + 84)))))
		} else if v5 == ccall.FuncAddr(nox_xxx_XFerMover_4F5730) {
			v19 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*187)))
			v20 = (*uint32)(unsafe.Pointer(sub_579C60(*(*uint32)(unsafe.Pointer(uintptr(v19 + 8))))))
			if v20 != nil {
				*(*uint32)(unsafe.Pointer(uintptr(v19 + 8))) = *v20
			} else {
				*(*uint32)(unsafe.Pointer(uintptr(v19 + 8))) = 0
			}
			v21 = int32(uintptr(unsafe.Pointer(sub_4CFFE0(int32(*(*uint32)(unsafe.Pointer(uintptr(v19 + 32))))))))
			if v21 != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v19 + 32))) = *(*uint32)(unsafe.Pointer(uintptr(v21 + 40)))
			} else {
				*(*uint32)(unsafe.Pointer(uintptr(v19 + 32))) = 0
			}
		} else if v5 == ccall.FuncAddr(nox_xxx_XFerGlyph_4F5890) {
			v22 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*173)))
			v23 = nox_xxx_mapGetWallSize_426A70()
			*(*float32)(unsafe.Pointer(uintptr(v22 + 28))) = float32(float64(int32(*a1-*(*uint32)(unsafe.Pointer(v23))*23)) + float64(*(*float32)(unsafe.Pointer(uintptr(v22 + 28)))))
			*(*float32)(unsafe.Pointer(uintptr(v22 + 32))) = float32(float64(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1))-*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v23))), 4*1)))*23)) + float64(*(*float32)(unsafe.Pointer(uintptr(v22 + 32)))))
		}
		v3 = (*uint32)(unsafe.Pointer(nox_server_getNextObjectUninited_4DA880((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))))))
		if v3 == nil {
			return a2
		}
	}
}
func sub_4D0550(a1 *byte) int32 {
	var (
		result int32
		v2     uint32
		v3     int8
		v4     int32
		v5     uint8
		v6     *byte
		v7     *byte
		v8     uint8
		v9     uint8
		v10    [256]byte
	)
	result = 0
	if a1 != nil {
		v10[0] = 0
		libc.StrNCat(&v10[0], a1, 256-1)
		v10[libc.StrLen(&v10[0])-4] = 0
		v2 = uint32(libc.StrLen(&v10[0]) + 1)
		v3 = int8(uint8(v2 - 1))
		v9 = uint8(v2 - 1)
		if int32(uint8(v2)) != 1 {
			for v10[v9] != 92 {
				v9 = uint8(func() int8 {
					p := &v3
					*p--
					return *p
				}())
				if int32(v3) == 0 {
					goto LABEL_7
				}
			}
			v10[int32(v9)+1] = 0
		}
	LABEL_7:
		v4 = int32(*memmap.PtrUint32(0x587000, 191752))
		v5 = *memmap.PtrUint8(0x587000, 191756)
		v6 = &v10[libc.StrLen(&v10[0])]
		*(*uint32)(unsafe.Pointer(v6)) = *memmap.PtrUint32(0x587000, 191748)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*1))) = uint32(v4)
		*(*byte)(unsafe.Add(unsafe.Pointer(v6), 8)) = byte(v5)
		if sub_4D0670(&v10[0]) == 0 {
			v10[0] = 0
			libc.StrNCat(&v10[0], a1, 256-1)
			v10[libc.StrLen(&v10[0])-4] = 0
			v7 = &v10[libc.StrLen(&v10[0])+1]
			v8 = *memmap.PtrUint8(0x587000, 191764)
			*(*uint32)(unsafe.Pointer(func() *byte {
				p := &v7
				*p = (*byte)(unsafe.Add(unsafe.Pointer(*p), -1))
				return *p
			}())) = *memmap.PtrUint32(0x587000, 191760)
			*(*byte)(unsafe.Add(unsafe.Pointer(v7), 4)) = byte(v8)
			sub_4D0670(&v10[0])
		}
		if false {
			sub_4D0670((*byte)(memmap.PtrOff(0x587000, 191768)))
		}
		result = 1
	}
	return result
}
func sub_4D0670(a1 *byte) int32 {
	var (
		v1 int32
		v2 *FILE
		v3 *FILE
		v4 *byte
		v5 int32
		v7 [255]byte
		v8 [256]wchar2_t
	)
	v1 = 6128
	v2 = nox_fs_open_text(a1)
	v3 = v2
	if v2 == nil {
		return 0
	}
	if !nox_fs_feof(v3) {
		for {
			libc.MemSet(unsafe.Pointer(&v7[0]), 0, 0xFC)
			*(*uint16)(unsafe.Pointer(&v7[252])) = 0
			v7[254] = 0
			nox_fs_fgets(v3, &v7[0], math.MaxUint8)
			v4 = libc.StrChr(&v7[0], 10)
			if v4 != nil {
				*v4 = 0
			}
			if v7[0] != 0 {
				nox_swprintf(&v8[0], (*wchar2_t)(unsafe.Pointer(internCStr("%S"))), &v7[0])
				v5 = sub_57AE30(&v7[0])
				if v5 != 0 {
					v1 = v5
				} else if noxflags.HasGame(noxflags.GameFlag(v1)) {
					nox_server_parseCmdText_443C80(&v8[0], 1)
				}
			}
			if nox_fs_feof(v3) {
				break
			}
		}
	}
	nox_fs_close(v3)
	return 1
}
func nox_common_maplist_add_4D0760(map_ *Nox_map_list_item) {
	var it *Nox_map_list_item = (*Nox_map_list_item)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_common_maplist)))
	if it == nil {
		nox_common_list_append_4258E0(&nox_common_maplist, &map_.list)
		return
	}
	for libc.StrCmp(&map_.Name[0], &it.Name[0]) > 0 {
		it = (*Nox_map_list_item)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0(&it.list)))
		if it == nil {
			nox_common_list_append_4258E0(&nox_common_maplist, &map_.list)
			return
		}
	}
	nox_common_list_append_4258E0(&it.list, &map_.list)
}
func nox_common_maplist_free_4D0970() {
	var (
		result *int32
		v1     *int32
		v2     *int32
	)
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_common_maplist)))
	v1 = result
	if result != nil {
		for {
			v2 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v1)))))
			nox_common_list_remove_425920(unsafe.Pointer((**uint32)(unsafe.Pointer(v1))))
			alloc.Free(v1)
			v1 = v2
			if v2 == nil {
				break
			}
		}
	}
}
func nox_common_maplist_first_4D09B0() *Nox_map_list_item {
	return (*Nox_map_list_item)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_common_maplist)))
}
func nox_common_maplist_next_4D09C0(list *Nox_map_list_item) *Nox_map_list_item {
	return (*Nox_map_list_item)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0(&list.list)))
}
func nox_xxx_loadMapCycle_4D0A30() *FILE {
	var (
		v0     int32
		result *FILE
		v7     *FILE
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    *byte
		v13    int32
		v14    int32
		v15    *FILE
		v16    [128]byte
		v17    [128]byte
	)
	v0 = 1
	libc.MemSet(memmap.PtrOff(0x5D4594, 1548428), 0, 0x18)
	libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, 1524108)), nox_fs_root())
	libc.StrCat((*byte)(memmap.PtrOff(0x5D4594, 1524108)), internCStr("\\mapcycle.txt"))
	result = nox_fs_open_text((*byte)(memmap.PtrOff(0x5D4594, 1524108)))
	v7 = result
	v15 = result
	if result != nil {
		if nox_fs_fgets(result, &v16[0], math.MaxInt8) {
			sub_4D0CC0(&v16[0])
			v8 = sub_4D0C80(&v16[0])
			if v8 < 0 {
				v9 = int32(*memmap.PtrUint32(0x5D4594, 1548432))
				libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 1548432))*128+1532428)), &v16[0])
				*memmap.PtrUint32(0x5D4594, 1548432) = uint32(v9 + 1)
			} else {
				v0 = v8
			}
		}
		for !nox_fs_feof(v7) {
			if nox_fs_fgets(v7, &v16[0], math.MaxInt8) {
				sub_4D0CC0(&v16[0])
				v10 = sub_4D0C80(&v16[0])
				if v10 < 0 {
					if *memmap.PtrInt32(0x5D4594, uintptr(v0*4)+1548428) < 25 && v16[0] != 0 {
						v11 = sub_4D0C70(v0)
						libc.StrCpy(&v17[0], &v16[0])
						v12 = libc.StrTok(&v17[0], internCStr(".\n"))
						if nox_common_checkMapFile_4CFE10(v12) != 0 {
							v13 = nox_xxx_mapGetTypeMB_4CFFA0(unsafe.Pointer(uintptr(int32(uintptr(memmap.PtrOff(0x973F18, 2408))))))
							if v13&v11 != 0 {
								v14 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v0*4)+1548428))
								libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, uintptr((v14+v0*20+v0*5)*128)+1529228)), &v16[0])
								*memmap.PtrUint32(0x5D4594, uintptr(v0*4)+1548428) = uint32(v14 + 1)
							}
						}
						v7 = v15
					}
				} else {
					v0 = v10
				}
			}
		}
		nox_fs_close(v7)
		result = nil
	} else {
		*memmap.PtrUint32(0x5D4594, 1548484) = 0
	}
	return result
}
func sub_4D0C70(a1 int32) int32 {
	return int32(*memmap.PtrUint32(0x587000, uintptr(a1*8)+191836))
}
func sub_4D0C80(a1 *byte) int32 {
	var (
		v1 int32
		v2 **byte
	)
	v1 = 0
	v2 = (**byte)(memmap.PtrOff(0x587000, 191832))
	for nox_strcmpi(*v2, a1) != 0 {
		v2 = (**byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((*byte)(nil))*2))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 191880))) {
			return -1
		}
	}
	return v1
}
func sub_4D0CC0(a1 *byte) {
	var (
		v1 *byte
		v2 *byte
	)
	if a1 != nil {
		v1 = libc.StrChr(a1, 13)
		if v1 != nil {
			*v1 = 0
		}
		v2 = libc.StrChr(a1, 10)
		if v2 != nil {
			*v2 = 0
		}
	}
}
func sub_4D0D50(a1 int32) int32 {
	var (
		result int32
		v2     *uint8
	)
	result = 0
	v2 = (*uint8)(memmap.PtrOff(0x587000, 191836))
	for (uint32(a1) & *(*uint32)(unsafe.Pointer(v2))) == 0 {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 8))
		result++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 191884))) {
			return 0
		}
	}
	return result
}
func sub_4D0D70() int32 {
	return bool2int32(*memmap.PtrUint32(0x5D4594, 1548484) != 0 || nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)))
}
func sub_4D0D90(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1548484) = uint32(a1)
	return result
}
func sub_4D0DA0() {
	libc.MemSet(memmap.PtrOff(0x5D4594, 1548452), 0, 0x18)
	libc.MemSet(memmap.PtrOff(0x5D4594, 1548428), 0, 0x18)
}
func sub_4D0DC0(a1 int32, a2 int32) int32 {
	var result int32
	result = sub_4D0D50(a1)
	*memmap.PtrUint32(0x5D4594, uintptr(result*4)+1548452) = uint32(a2)
	return result
}
func sub_4D0DE0(a1 int32) int32 {
	return int32(*memmap.PtrUint32(0x5D4594, uintptr(sub_4D0D50(a1)*4)+1548452))
}
func nox_xxx_mapSelectFirst_4D0E00() int32 {
	var (
		i  *int32
		v3 int32
		v4 uint8
		v5 *uint8
	)
	_ = v5
	var v6 int32
	var result int32
	var v8 int32
	var v9 int32
	var v10 *uint8
	var v11 int32
	var v12 int32
	var v13 int32
	dword_5d4594_1548476 = 0
	for i = (*int32)(unsafe.Pointer(nox_common_maplist_first_4D09B0())); i != nil; i = (*int32)(unsafe.Pointer(nox_common_maplist_next_4D09C0((*Nox_map_list_item)(unsafe.Pointer(i))))) {
		if *(*int32)(unsafe.Add(unsafe.Pointer(i), 4*6)) != 0 {
			if sub_4CFFC0(int32(uintptr(unsafe.Pointer(i))))&0x1000 != 0 {
				if *(*int32)(unsafe.Pointer(&dword_5d4594_1548476)) < 128 {
					v3 = int32(dword_5d4594_1548476 * 32)
					libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, uintptr(dword_5d4594_1548476)*32+1525136)), (*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(i))), 12)))
					v4 = *memmap.PtrUint8(0x587000, 192004)
					v5 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v3)+1525136+uintptr(libc.StrLen((*byte)(memmap.PtrOff(0x5D4594, uintptr(v3)+1525136))))))
					*(*uint32)(unsafe.Pointer(v5)) = *memmap.PtrUint32(0x587000, 192000)
					*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 4)) = v4
					v6 = int32(dword_5d4594_1548476 + 1)
					*memmap.PtrUint32(0x5D4594, uintptr(v3)+1525132) = 0
					dword_5d4594_1548476 = uint32(v6)
				}
			}
		}
	}
	result = int32(dword_5d4594_1548476)
	v8 = 1
	if dword_5d4594_1548476 > 0 {
		v9 = 1
		v10 = (*uint8)(memmap.PtrOff(0x5D4594, 1525132))
		for {
			if *(*uint32)(unsafe.Pointer(v10)) == 0 {
				*(*uint32)(unsafe.Pointer(v10)) = uint32(func() int32 {
					p := &v8
					x := *p
					*p++
					return x
				}())
				v13 = v8
				v11 = v9
				if v9 < result {
					v12 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v10), 32)))))
					for {
						if nox_strnicmp((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v10))), 4)), (*byte)(unsafe.Pointer(uintptr(v12+4))), 6) == 0 {
							*(*uint32)(unsafe.Pointer(uintptr(v12))) = *(*uint32)(unsafe.Pointer(v10))
						}
						result = int32(dword_5d4594_1548476)
						v11++
						v12 += 32
						if v11 >= *(*int32)(unsafe.Pointer(&dword_5d4594_1548476)) {
							break
						}
					}
					v8 = v13
				}
			}
			v9++
			v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 32))
			if v9-1 >= result {
				break
			}
		}
	}
	return result
}
func sub_4D0F30() {
	var (
		v0 int32
		v1 *uint8
	)
	v0 = int32(dword_5d4594_1548476)
	dword_5d4594_1548480 = 1000
	if dword_5d4594_1548476 > 0 {
		v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1525160))
		for {
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), -int(4*1)))) = 0
			*(*uint32)(unsafe.Pointer(v1)) = 0
			v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 32))
			v0--
			if v0 == 0 {
				break
			}
		}
	}
}
func nox_xxx_getQuestMapFile_4D0F60() *byte {
	var (
		v1  int32
		v2  *uint8
		v3  int32
		v4  int32
		v5  *uint8
		v6  int32
		v7  *uint8
		v8  int32
		v9  int32
		v10 int32
		v11 *uint8
		v12 int32
		v13 int32
		v14 int32
		i   *uint8
		v16 int32
	)
	if dword_5d4594_1548476 == 0 {
		return nil
	}
	if dword_5d4594_1548476 == 1 {
		return (*byte)(memmap.PtrOff(0x5D4594, 1525136))
	}
	v1 = 0
	v16 = 0
	if *(*int32)(unsafe.Pointer(&dword_5d4594_1548476)) <= 0 {
		return (*byte)(memmap.PtrOff(0x5D4594, uintptr(nox_common_randomInt_415FA0(0, int32(dword_5d4594_1548476-1))*32)+1525136))
	}
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1525156))
	v3 = int32(dword_5d4594_1548476)
	for {
		if *(*uint32)(unsafe.Pointer(v2)) > uint32(v1) {
			v16 = int32(*(*uint32)(unsafe.Pointer(v2)))
			v1 = int32(*(*uint32)(unsafe.Pointer(v2)))
		}
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 32))
		v3--
		if v3 == 0 {
			break
		}
	}
	if v1 == 0 {
		return (*byte)(memmap.PtrOff(0x5D4594, uintptr(nox_common_randomInt_415FA0(0, int32(dword_5d4594_1548476-1))*32)+1525136))
	}
	v4 = 1
	v5 = (*uint8)(memmap.PtrOff(0x5D4594, 1525156))
	v6 = int32(dword_5d4594_1548476)
	for {
		if dword_5d4594_1548476 > 1 {
			v7 = (*uint8)(memmap.PtrOff(0x5D4594, 1525188))
			v8 = int32(dword_5d4594_1548476 - 1)
			for {
				if *(*uint32)(unsafe.Pointer(v5)) != *(*uint32)(unsafe.Pointer(v7)) {
					v4 = 0
				}
				v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 32))
				v8--
				if v8 == 0 {
					break
				}
			}
		}
		v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 32))
		v6--
		if v6 == 0 {
			break
		}
	}
	if v4 == 1 {
		v16++
	}
	v9 = 0
	v10 = 0
	v11 = (*uint8)(memmap.PtrOff(0x5D4594, 1525132))
	for {
		if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v11))), 4*6))) < uint32(v16) && uint32(v10) != *memmap.PtrUint32(0x587000, 191880) && *(*uint32)(unsafe.Pointer(v11)) != *memmap.PtrUint32(0x5D4594, uintptr(*memmap.PtrUint32(0x587000, 191880))*32+1525132) && dword_5d4594_1548480-*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v11))), 4*7))) > 4 {
			v9++
		}
		v10++
		v11 = (*uint8)(unsafe.Add(unsafe.Pointer(v11), 32))
		if v10 >= *(*int32)(unsafe.Pointer(&dword_5d4594_1548476)) {
			break
		}
	}
	v12 = nox_common_randomInt_415FA0(0, v9-1)
	v13 = 0
	v14 = 0
	if *(*int32)(unsafe.Pointer(&dword_5d4594_1548476)) <= 0 {
		return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v12*32)+1525136))
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 1525132)); ; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 32)) {
		if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*6))) >= uint32(v16) || uint32(v14) == *memmap.PtrUint32(0x587000, 191880) || *(*uint32)(unsafe.Pointer(i)) == *memmap.PtrUint32(0x5D4594, uintptr(*memmap.PtrUint32(0x587000, 191880))*32+1525132) || dword_5d4594_1548480-*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*7))) <= 4 {
			goto LABEL_36
		}
		if v13 == v12 {
			break
		}
		v13++
	LABEL_36:
		if func() int32 {
			p := &v14
			*p++
			return *p
		}() >= *(*int32)(unsafe.Pointer(&dword_5d4594_1548476)) {
			return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v12*32)+1525136))
		}
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v14*32)+1525136))
}
func sub_4D11A0() {
	if *memmap.PtrUint32(0x5D4594, 1548504) == 0 {
		nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 1548492)))
		*memmap.PtrUint32(0x5D4594, 1548504) = 1
	}
}
func sub_4D11D0() {
	var (
		result *int32
		v1     *int32
		v2     *int32
	)
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1548492))))))
	v1 = result
	if result != nil {
		for {
			v2 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v1)))))
			nox_common_list_remove_425920(unsafe.Pointer((**uint32)(unsafe.Pointer(v1))))
			alloc.Free(v1)
			v1 = v2
			if v2 == nil {
				break
			}
		}
	}
}
func sub_4D1210(a1 int32) {
	var (
		result unsafe.Pointer
		v2     unsafe.Pointer
		v3     *uint32
	)
	result = unsafe.Pointer(uintptr(sub_4D12A0(a1)))
	if result == nil {
		result = unsafe.Pointer(nox_common_playerInfoFromNum_417090(a1))
		v2 = result
		if result != nil {
			v3 = (*uint32)(alloc.Calloc1(1, 0x10))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)) = uint32(uintptr(v2))
			nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(uintptr(int32(uintptr(memmap.PtrOff(0x5D4594, 1548492)))))), (*nox_list_item_t)(unsafe.Pointer(v3)))
		}
	}
}
func sub_4D1250(a1 int32) *int32 {
	var (
		result *int32
		v2     *int32
	)
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1548492))))))
	v2 = result
	if result != nil {
		for int32(*(*uint8)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) + 2064)))) != a1 {
			result = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v2)))))
			v2 = result
			if result == nil {
				return result
			}
		}
		nox_common_list_remove_425920(unsafe.Pointer((**uint32)(unsafe.Pointer(v2))))
		alloc.Free(v2)
	}
	return result
}
func sub_4D12A0(a1 int32) int32 {
	var v1 *int32
	v1 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1548492))))))
	if v1 == nil {
		return 0
	}
	for int32(*(*uint8)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*3)) + 2064)))) != a1 {
		v1 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v1)))))
		if v1 == nil {
			return 0
		}
	}
	return 1
}
func nox_xxx_mapSwitchLevel_4D12E0(a1 int32) {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  *uint32
		v5  int32
		v6  *uint32
		v11 [3]int32
	)
	v11[0] = 25
	v11[1] = 25
	v11[2] = 25
	nox_xxx_setGameFlags_40A4D0(0x80000)
	sub_516F30()
	sub_421B10()
	sub_469B90(&v11[0])
	if noxflags.HasGame(2) {
		sub_4349C0((*uint32)(unsafe.Pointer(&v11[0])))
	}
	sub_511E60()
	if noxflags.HasGame(2048) {
		v1 = a1
		sub_4FCEB0(a1)
	} else {
		sub_4FCEB0(0)
		v1 = a1
	}
	nox_xxx_mapWall_4FF790()
	v2 = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	if v2 != 0 {
		for {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 748))))
			sub_4F7950(v2)
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 296))) = 0
			nox_xxx_unitUnFreeze_4E7A60((*server.Object)(unsafe.Pointer(uintptr(v2))), 1)
			v4 = *(**uint32)(unsafe.Pointer(uintptr(v3 + 280)))
			*(*uint16)(unsafe.Pointer(uintptr(v3 + 160))) = 0
			if v4 != nil {
				nox_xxx_shopCancelSession_510DC0(v4)
			}
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 280))) = 0
			if *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v2 + 744))) == ccall.FuncAddr(Nox_xxx_updatePlayerMonsterBot_4FAB20) {
				nox_xxx_playerBotCreate_4FA700(v2)
			}
			v2 = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(v2)))))))
			if v2 == 0 {
				break
			}
		}
		v1 = a1
	}
	for {
		nox_xxx_unitsNewAddToList_4DAC00()
		sub_4E5BF0(v1)
		nox_xxx_spellCastByPlayer_4FEEF0()
		nox_xxx_finalizeDeletingUnits_4E5EC0()
		if nox_server_getFirstObjectUninited_4DA870() == nil {
			break
		}
	}
	v5 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if v5 != 0 {
		for {
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 520))) = 0
			if nox_xxx_isUnit_4E5B50((*server.Object)(unsafe.Pointer(uintptr(v5)))) != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))&2 != 0 {
				v6 = *(**uint32)(unsafe.Pointer(uintptr(v5 + 748)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*309)) = math.MaxUint32
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*307)) = math.MaxUint32
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*317)) = math.MaxUint32
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*311)) = math.MaxUint32
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*313)) = math.MaxUint32
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*315)) = math.MaxUint32
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*319)) = math.MaxUint32
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*321)) = math.MaxUint32
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*323)) = math.MaxUint32
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*325)) = math.MaxUint32
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*98)) = 0
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*101)) = 0
			}
			v5 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(v5)))))))
			if v5 == 0 {
				break
			}
		}
		v1 = a1
	}
	sub_50D1C0()
	for obj := (*server.Object)(nox_xxx_getFirstUpdatable2Object_4DA840()); obj != nil; obj = nox_xxx_getNextUpdatable2Object_4DA850(obj) {
		if sub_4E5B80(obj) != 0 {
			sub_4E81D0(obj)
		}
	}
	sub_4ECFE0()
	sub_511E20()
	nox_xxx_wall_410160()
	if v1 != 0 {
		nox_xxx_Fn_4FCAC0(v1, 1)
	} else {
		nox_xxx_Fn_4FCAC0(0, 0)
	}
	for j := int32(0); j < ptr_5D4594_2650668_cap*44; j += 44 {
		for k := int32(0); k < ptr_5D4594_2650668_cap; k++ {
			*(*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(k)))))) + uint32(j)))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(k)))))) + uint32(j) + 4))) = math.MaxUint8
			*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(k)))))) + uint32(j) + 24))) = math.MaxUint8
			nox_xxx_tileFreeTile_422200(int32(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(k)))))) + uint32(j) + 4))
			nox_xxx_tileFreeTile_422200(int32(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(k)))))) + uint32(j) + 24))
		}
	}
	nox_xxx_mapSwitchLevel_4D12E0_end()
}
func sub_4D15C0() {
	*memmap.PtrUint32(0x5D4594, 1548508) = 0
}
func nox_xxx_scavengerTreasureMax_4D1600() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1548528))
}
func sub_4D1610() {
	*memmap.PtrUint32(0x5D4594, 1548528) = 0
}
func nox_xxx_servResetPlayers_4D23C0() int32 {
	var (
		i  *byte
		v2 int32
	)
	for i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); i != nil; i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(i))))))))) {
		if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*514))) != 0 {
			dword_5d4594_2649712 &= uint32(int32(^(1 << *(*byte)(unsafe.Add(unsafe.Pointer(i), 2064)))))
			v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*514))))
			*(*byte)(unsafe.Add(unsafe.Pointer(i), 3676)) = 2
			nox_xxx_playerMakeDefItems_4EF7D0(v2, 1, 0)
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*535))) = 0
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*534))) = 0
		}
	}
	sub_51A100()
	nox_common_gameFlags_unset_40A540(0x20000)
	nox_xxx_netGameSettings_4DEF00()
	nox_server_gameUnsetMapLoad_40A690()
	return 1
}
func nox_xxx_netReportAllLatency_4D3050() *byte {
	var (
		result *byte
		v1     bool
		i      int32
		v3     [5]byte
	)
	v3[0] = 215
	if dword_5d4594_1548700 == 0 || (func() bool {
		result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1548700))))))))
		return (func() uint32 {
			dword_5d4594_1548700 = uint32(uintptr(unsafe.Pointer(result)))
			return dword_5d4594_1548700
		}()) == 0
	}()) {
		result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
		dword_5d4594_1548700 = uint32(uintptr(unsafe.Pointer(result)))
	}
	if result != nil {
		for k := int32(0); *(*byte)(unsafe.Add(unsafe.Pointer(result), 2064)) != 31 && k < 32; k++ {
			v1 = sub_554240(int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(result), 2064))))) == 0
			result = *(**byte)(unsafe.Pointer(&dword_5d4594_1548700))
			if !v1 {
				break
			}
			result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1548700))))))))
			dword_5d4594_1548700 = uint32(uintptr(unsafe.Pointer(result)))
			if result == nil {
				result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
				dword_5d4594_1548700 = uint32(uintptr(unsafe.Pointer(result)))
			}
		}
		if result != nil {
			*(*uint16)(unsafe.Pointer(&v3[1])) = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*1030)))
			*(*uint16)(unsafe.Pointer(&v3[3])) = uint16(int16(sub_554240(int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(result), 2064)))))))
			result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
			for i = int32(uintptr(unsafe.Pointer(result))); result != nil; i = int32(uintptr(unsafe.Pointer(result))) {
				nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Pointer(uintptr(i + 2064)))), 1, (*uint8)(unsafe.Pointer(&v3[0])), 5)
				result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(uintptr(i))))))
			}
		}
	}
	return result
}
func sub_4D39F0(a3 *byte) int32 {
	var (
		v1     uint32
		v2     int8
		v3     *uint8
		v4     *byte
		v5     int32
		v6     int32
		v7     *uint8
		v8     uint32
		v9     *uint8
		v10    *byte
		v11    *uint8
		v12    int32
		v13    int32
		v14    int32
		v15    *byte
		v16    uint8
		result int32
		v18    [2048]byte
	)
	*memmap.PtrUint64(0x5D4594, 1549772) = uint64(nox_platform_get_ticks())
	libc.MemSet(memmap.PtrOff(0x973F18, 35912), 0, 0x48)
	*memmap.PtrUint32(0x973F18, 35912) = 0
	*memmap.PtrUint32(0x973F18, 35916) = 0
	dword_5d4594_3835348 = 0
	dword_5d4594_3835356 = math.MaxUint8
	dword_5d4594_3835352 = 0
	dword_5d4594_3835360 = 0
	dword_5d4594_3835364 = 1
	dword_5d4594_3835368 = 1
	dword_5d4594_3835372 = 1
	*memmap.PtrUint32(0x973F18, 35948) = 0
	*memmap.PtrUint32(0x973F18, 35952) = 0
	*memmap.PtrUint32(0x973F18, 35956) = 0
	dword_5d4594_3835388 = 0
	dword_5d4594_3835392 = 1
	dword_5d4594_3835396 = math.MaxUint32
	*memmap.PtrUint8(0x973F18, 35972) = 2
	*memmap.PtrUint32(0x973F18, 35976) = 0
	*memmap.PtrUint32(0x973F18, 35980) = 0
	sub_51D0E0()
	if a3 != nil {
		v1 = uint32(libc.StrLen(a3) + 1)
		v2 = int8(uint8(v1))
		v1 >>= 2
		alloc.Memcpy(memmap.PtrOff(0x973F18, 42152), unsafe.Pointer(a3), uintptr(v1*4))
		v4 = (*byte)(unsafe.Add(unsafe.Pointer(a3), v1*4))
		v3 = (*uint8)(memmap.PtrOff(0x973F18, uintptr(v1)*4+42152))
		*((*uint8)(unsafe.Pointer(&v1))) = uint8(v2)
		v5 = int32(*memmap.PtrUint32(0x587000, 197560))
		alloc.Memcpy(unsafe.Pointer(v3), unsafe.Pointer(v4), uintptr(v1&3))
		libc.StrCpy((*byte)(memmap.PtrOff(0x973F18, 36008)), a3)
		v6 = int32(*memmap.PtrUint32(0x587000, 197564))
		v7 = (*uint8)(memmap.PtrOff(0x973F18, uintptr(libc.StrLen((*byte)(memmap.PtrOff(0x973F18, 36008)))+36008)))
		*(*uint32)(unsafe.Pointer(v7)) = *memmap.PtrUint32(0x587000, 197556)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v7))), 4*1))) = uint32(v5)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v7))), 4*2))) = uint32(v6)
		v8 = uint32(libc.StrLen(a3) + 1)
		*((*uint8)(unsafe.Pointer(&v5))) = uint8(v8)
		v8 >>= 2
		alloc.Memcpy(memmap.PtrOff(0x973F18, 38056), unsafe.Pointer(a3), uintptr(v8*4))
		v10 = (*byte)(unsafe.Add(unsafe.Pointer(a3), v8*4))
		v9 = (*uint8)(memmap.PtrOff(0x973F18, uintptr(v8)*4+38056))
		*((*uint8)(unsafe.Pointer(&v8))) = uint8(int8(v5))
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v5))), unsafe.Sizeof(uint16(0))*0)) = *memmap.PtrUint16(0x587000, 197576)
		alloc.Memcpy(unsafe.Pointer(v9), unsafe.Pointer(v10), uintptr(v8&3))
		v11 = (*uint8)(memmap.PtrOff(0x973F18, uintptr(libc.StrLen((*byte)(memmap.PtrOff(0x973F18, 38056)))+38057)))
		v12 = int32(*memmap.PtrUint32(0x587000, 197572))
		*(*uint32)(unsafe.Pointer(func() *uint8 {
			p := &v11
			*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), -1))
			return *p
		}())) = *memmap.PtrUint32(0x587000, 197568)
		*((*uint8)(unsafe.Pointer(&v6))) = *memmap.PtrUint8(0x587000, 197578)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v11))), 4*1))) = uint32(v12)
		*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v11))), unsafe.Sizeof(uint16(0))*4))) = uint16(int16(v5))
		*(*uint8)(unsafe.Add(unsafe.Pointer(v11), 10)) = uint8(int8(v6))
		nox_fs_remove((*byte)(memmap.PtrOff(0x973F18, 36008)))
		nox_fs_remove((*byte)(memmap.PtrOff(0x973F18, 38056)))
	} else {
		*memmap.PtrUint8(0x973F18, 42152) = *memmap.PtrUint8(0x5D4594, 1549780)
		*memmap.PtrUint8(0x973F18, 40104) = *memmap.PtrUint8(0x5D4594, 1549784)
		*memmap.PtrUint8(0x973F18, 36008) = *memmap.PtrUint8(0x5D4594, 1549788)
		*memmap.PtrUint8(0x973F18, 38056) = *memmap.PtrUint8(0x5D4594, 1549792)
	}
	nox_xxx_mapReset_5028E0()
	v13 = int32(*memmap.PtrUint32(0x587000, 197584))
	libc.StrCpy(&v18[0], a3)
	v14 = int32(*memmap.PtrUint32(0x587000, 197588))
	v15 = &v18[libc.StrLen(&v18[0])]
	*(*uint32)(unsafe.Pointer(v15)) = *memmap.PtrUint32(0x587000, 197580)
	v16 = *memmap.PtrUint8(0x587000, 197592)
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v15))), 4*1))) = uint32(v13)
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v15))), 4*2))) = uint32(v14)
	*(*byte)(unsafe.Add(unsafe.Pointer(v15), 12)) = byte(v16)
	sub_502A50(&v18[0])
	sub_502AB0(&v18[0])
	result = sub_502B10()
	dword_5d4594_3835312 = 0
	*memmap.PtrUint32(0x973F18, 35880) = 0
	*memmap.PtrUint32(0x5D4594, 1599580) = 0
	return result
}
func nox_xxx_tileInitdataClear_4D3C50(a1 unsafe.Pointer) {
	alloc.Memcpy(memmap.PtrOff(0x973F18, 35912), a1, 0x48)
}
func sub_4D3C70() *uint8 {
	return (*uint8)(memmap.PtrOff(0x973F18, 35912))
}
func sub_4D3C80(a1 *uint32) *uint32 {
	var (
		result *uint32
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
	)
	result = a1
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
	v10 = int32(*a1)
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	if v2 < v3 {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
		v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) < uint32(v3) {
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
		v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) < uint32(v3) {
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*6)))
		v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)))
	}
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
	v12 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
	if *a1 < uint32(v4) {
		v4 = int32(*a1)
		v12 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) < uint32(v4) {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v12 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	}
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*6)))
	if v5 < v4 {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*6)))
		v12 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)))
	}
	v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	if *a1 > uint32(v6) {
		v6 = int32(*a1)
		v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) > uint32(v6) {
		v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
		v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
	}
	if v5 > v6 {
		v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*6)))
		v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)))
	}
	v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)))
	v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*6)))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) > uint32(v8) {
		v9 = int32(*a1)
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	}
	if v2 > v8 {
		v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) > uint32(v8) {
		v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*6)) = uint32(v9)
	*a1 = uint32(v10)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) = uint32(v4)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) = uint32(v8)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = uint32(v11)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) = uint32(v6)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) = uint32(v7)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) = uint32(v12)
	return result
}
func nox_xxx_mapGenFixCoords_4D3D90(a1 *float2, a2 *float2) int32 {
	if a1 == nil || a2 == nil {
		return 0
	}
	a2.field_0 = float32(float64(a1.field_4+a1.field_0)*0.70710677 + 2957.0)
	a2.field_4 = float32(float64(a1.field_4-a1.field_0)*0.70710677 + 2956.0)
	if float64(a2.field_0) <= 80.5 {
		a2.field_0 = 82.5
	}
	if float64(a2.field_4) <= 80.5 {
		a2.field_4 = 81.5
	}
	if float64(a2.field_0) >= 5853.5 {
		a2.field_0 = 5851.5
	}
	if float64(a2.field_4) >= 5853.5 {
		a2.field_4 = 5852.5
	}
	return 1
}
func sub_4D3E30(a1 *float2, a2 *float2) int32 {
	var result int32
	if a1 == nil || a2 == nil {
		return 0
	}
	if float64(a1.field_0) <= 80.5 {
		a1.field_0 = 82.5
	}
	if float64(a1.field_4) <= 80.5 {
		a1.field_4 = 81.5
	}
	if float64(a1.field_0) >= 5853.5 {
		a1.field_0 = 5851.5
	}
	if float64(a1.field_4) >= 5853.5 {
		a1.field_4 = 5852.5
	}
	result = 1
	a2.field_0 = float32((float64(a1.field_0) - 1.0 - float64(a1.field_4)) * 0.70710677)
	a2.field_4 = float32((float64(a1.field_4+a1.field_0) - 5912.0) * 0.70710677)
	return result
}
func sub_4D3FF0(a1 int32) int32 {
	var result int32
	switch a1 {
	case 0:
		result = 3
	case 1:
		result = 0
	case 2:
		result = 1
	case 3:
		result = 6
	case 5:
		result = 2
	case 6:
		result = 7
	case 7:
		result = 8
	case 8:
		result = 5
	default:
		result = -1
	}
	return result
}
func sub_4D42E0(a1 *byte) uint32 {
	var result uint32
	result = uint32(libc.StrLen(a1) + 1)
	alloc.Memcpy(memmap.PtrOff(0x587000, 197860), unsafe.Pointer(a1), uintptr(result))
	return result
}
func nox_xxx_getRandMapName_4D4310() *byte {
	return (*byte)(memmap.PtrOff(0x587000, 197860))
}
func nox_xxx_mapGenStart_4D4320() int32 {
	var (
		v0               int32
		v1               int32
		v2               *byte
		v3               *byte
		result           int32
		i                int32
		v6               *byte
		v7               *byte
		v8               *byte
		v9               *byte
		v10              *byte
		PathName         [1024]byte
		FileName         [1024]byte
		ExistingFileName [1024]byte
	)
	v0 = 100
	nox_xxx_mapSwitchLevel_4D12E0(1)
	nox_xxx_setGameFlags_40A4D0(0x400000)
	*memmap.PtrUint32(0x5D4594, 1550924) = uint32(uintptr(unsafe.Pointer(nox_get_and_zero_server_objects_4DA3C0())))
	libc.MemSet(memmap.PtrOff(0x973F18, 2408), 0, 0x5B8)
	for {
		v1 = nox_xxx_mapGenStep_4D44E0()
		if v1 == 1 {
			break
		}
		if v1 != 0 {
			if func() int32 {
				p := &v0
				*p--
				return *p
			}() != 0 {
				continue
			}
		}
		return 0
	}
	v2 = nox_fs_root()
	nox_sprintf(&FileName[0], internCStr("%s\\nc.obj"), v2)
	v3 = nox_fs_root()
	nox_sprintf(&ExistingFileName[0], internCStr("%s\\blend.obj"), v3)
	if nox_fs_access(&FileName[0], 0) == -1 || (func() int32 {
		result = bool2int32(nox_fs_remove(&FileName[0]))
		return result
	}()) != 0 {
		if nox_fs_access(&ExistingFileName[0], 0) == -1 || (func() int32 {
			result = bool2int32(nox_fs_move(&ExistingFileName[0], &FileName[0]))
			return result
		}()) != 0 {
			for i = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(i))))))) {
				*(*uint32)(unsafe.Pointer(uintptr(i + 44))) = 0
			}
			nox_xxx_mapGenMakeInfo_4D5DB0(unsafe.Pointer(uintptr(int32(uintptr(memmap.PtrOff(0x973F18, 2408))))))
			v9 = nox_xxx_getRandMapName_4D4310()
			v6 = nox_fs_root()
			nox_sprintf(&PathName[0], internCStr("%s\\Maps\\$%s"), v6, v9)
			nox_fs_mkdir(&PathName[0])
			v10 = nox_xxx_getRandMapName_4D4310()
			v8 = nox_xxx_getRandMapName_4D4310()
			v7 = nox_fs_root()
			nox_sprintf(&PathName[0], internCStr("%s\\Maps\\$%s\\$%s.map"), v7, v8, v10)
			if nox_xxx_mapSaveMap_51E010(&PathName[0], 1) == 0 {
				return 0
			}
			nox_xxx_mapSwitchLevel_4D12E0(1)
			nox_set_server_objects_4DA3E0((*server.Object)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1550924)))))
			*memmap.PtrUint32(0x5D4594, 1550924) = 0
			nox_common_gameFlags_unset_40A540(0x400000)
			result = 1
		}
	}
	return result
}
func nox_xxx_mapGenStep_4D44E0() int32 {
	var (
		result int32
		v2     int32
		v3     int32
		v4     *float32
		v5     float64
		i      *byte
		j      *int32
		k      *int32
		a2     float2
	)
	dword_5d4594_1550916 = 0
	sub_57C490_2(internCStr("theme"))
	sub_526C40(0)
	sub_51D100(0)
	result = nox_xxx_mapGenReadTheme_51E260(mem_getI32Ptr(0x5D4594, 1549796), int32(uintptr(memmap.PtrOff(0x587000, 197860))))
	if result == 0 {
		return 0
	}
	*memmap.PtrUint32(0x5D4594, 1549864) = uint32(int32(int64(float64(*mem_getFloatPtr(0x5D4594, 1549860)) * 0.030743772)))
	nox_xxx_mapGenSetRngSeed_526AB0(*memmap.PtrUint32(0x5D4594, 1549872))
	sub_526950()
	result = nox_xxx_mapgenAllocBuffer_5213E0()
	if result == 0 {
		return 0
	}
	result = sub_520EA0(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))))
	if result == 0 {
		return 0
	}
	nox_xxx_mapGenMkSmallRoom_4D4F40((*uint32)(memmap.PtrOff(0x5D4594, 1549796)))
	if nox_xxx_mapGen_InPrefab1_525D20(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796)))) != 0 {
		sub_4D52F0()
		if nox_xxx_mapGen_InPrefab2_5266F0(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796)))) != 0 {
			if nox_xxx_mapGenPlacePrefabs_526830(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796)))) == 0 {
				v2 = 0
				goto LABEL_25
			}
			sub_5259F0(*(*int32)(unsafe.Pointer(&dword_5d4594_1550916)), 0, 0.0)
			sub_525AF0(*(*int32)(unsafe.Pointer(&dword_5d4594_1550916)))
			if *memmap.PtrUint32(0x5D4594, 1549980) != 0 {
				v3 = int32(int64(float64(*mem_getFloatPtr(0x5D4594, 1549860)) * 0.030743772))
				v4 = nox_xxx_mapGenMakeRoomStruct_521940(v3*2+1, v3*2+1)
				v5 = float64(-v3) * 32.526913
				a2.field_0 = float32(v5)
				a2.field_4 = float32(v5)
				nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v4)), &a2)
				for i = (*byte)(nox_xxx_mapGenGetTopRoom_521710()); i != nil; i = (*byte)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(i))))))) {
					sub_521BC0(int32(uintptr(unsafe.Pointer(v4))), (*float2)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(i), 20)))), *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(i))), unsafe.Sizeof(float32(0))*7))), *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(i))), unsafe.Sizeof(float32(0))*8))))
				}
				sub_524070(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(uintptr(unsafe.Pointer(v4))))
				nox_xxx_gen_524E00(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(uintptr(unsafe.Pointer(v4))))
				nox_xxx_mapgen_522340(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(uintptr(unsafe.Pointer(v4))))
				sub_521A10(unsafe.Pointer(v4))
			}
			if nox_xxx_mapGenMakeRooms_524310(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796)))) != 0 {
				for j = (*int32)(nox_xxx_mapGenGetTopRoom_521710()); j != nil; j = (*int32)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(j))))))) {
					if nox_xxx_mapGenCheckRoomType_5238F0(j) != 0 {
						nox_xxx_mapGenSetFlags_5235F0(-100)
						nox_xxx_gen_524E00(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(uintptr(unsafe.Pointer(j))))
					}
				}
				for k = (*int32)(nox_xxx_mapGenGetTopRoom_521710()); k != nil; k = (*int32)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(k))))))) {
					if nox_xxx_mapGenCheckRoomType_5238F0(k) == 0 {
						nox_xxx_mapGenSetFlags_5235F0(-100)
						nox_xxx_gen_524E00(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(uintptr(unsafe.Pointer(k))))
					}
				}
				sub_522D30(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))))
				nox_xxx_mapgen_Doors_4D4790()
				nox_xxx_mapGenTryNextRoom_522F40((*uint32)(memmap.PtrOff(0x5D4594, 1549796)))
				nox_xxx_mapGenGetTopRoom_521710()
				nox_xxx_mapGenFinishPopulate_5228B0_mapgen_populate(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))))
				v2 = 1
				goto LABEL_25
			}
		}
	}
	v2 = 2
LABEL_25:
	nox_xxx_mapGenFreeTopRoom_521A40()
	nox_xxx_mapgenFreeBuffer_521400()
	sub_520F80()
	sub_520D50((*uint32)(memmap.PtrOff(0x5D4594, 1549796)))
	return v2
}
func nox_xxx_mapgen_Doors_4D4790() *float32 {
	var (
		result *float32
		v1     *float32
		v2     *int32
		v3     int32
		v4     int32
		v5     int32
		v6     *int32
		v7     int32
		v8     *float32
		v9     float64
		v10    float64
		v11    *float32
		v12    float64
		v13    float64
		v14    float64
		v15    float64
		v16    int32
		v17    int32
		v18    *int32
		v19    int32
		v20    *float32
		v21    float64
		v22    float64
		v23    float64
		v24    *float32
		v25    float64
		v26    float64
		v27    float64
		v28    int32
		v29    int32 = 0
		v30    int32
		v31    int32
		v32    int32
		v33    int32 = 0
		v34    float2
		a2     float2
		v36    float32
		v37    float32
		v38    float2
		v39    float2
		a1     int2
	)
	result = (*float32)(nox_xxx_mapGenGetTopRoom_521710())
	v1 = result
	v2 = nil
	if result == nil {
		return result
	}
	v3 = v33
	for {
		if *(*uint32)(unsafe.Pointer(v1)) != 1 {
			goto LABEL_117
		}
		nox_xxx_mapGenSetFlags_5235F0(-100)
		v4 = 0
		v32 = 0
		for {
			if int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v1))), v4))), 216)))) == 0 && nox_xxx_mapGenRandFunc_526AC0(1, 100) <= *memmap.PtrInt32(0x5D4594, 1549848) {
				switch v4 {
				case 0, 1:
					a1.field_0 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*1)))
					if v4 == 1 {
						a1.field_4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*2))) + *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*4))))
					} else {
						a1.field_4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*2))) - 1)
					}
					v31 = 0
					if *((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v1))), 4*3))) <= 0 {
						goto LABEL_115
					}
					for {
						v17 = sub_521290(&a1)
						v18 = (*int32)(unsafe.Pointer(uintptr(v17)))
						if v17 != 0 {
							if (*int32)(unsafe.Pointer(uintptr(v17))) == v2 {
								if int32(*(*uint8)(unsafe.Pointer(uintptr(v17 + 52))))&2 != 0 {
									v29++
								}
							}
						}
						if (*int32)(unsafe.Pointer(uintptr(v17))) != v2 || (func() bool {
							v19 = v31
							return uint32(v31) == *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*3)))-1
						}()) {
							if v2 != nil && v29 >= 3 {
								v34.field_0 = float32(float64((v3+v31)/2)*32.526913 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*9))))
								if v32 == 1 {
									v34.field_4 = *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*12))
								} else {
									v34.field_4 = *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*10))
								}
								sub_527030(&v34)
								v34.field_0 = float32(float64(v34.field_0) - 16.263456)
								if v29 < 4 {
									nox_xxx_mapGenGetObjID_527940(internCStr("ArchedDoor"))
								} else {
									nox_xxx_mapGenGetObjID_527940(internCStr("ArchedHalfDoor"))
								}
								v20 = nox_xxx_mapGenPlaceObj_5279B0((*float2)(unsafe.Pointer(&v34.field_0)))
								if v20 != nil {
									nox_xxx_mapGenOrientObj_527C60(int32(uintptr(unsafe.Pointer(v20))), 5)
								}
								a2.field_0 = v34.field_0
								if v32 == 1 {
									a2.field_4 = float32(float64(v34.field_4) - 32.526913)
								} else {
									a2.field_4 = v34.field_4
								}
								sub_521BC0(int32(uintptr(unsafe.Pointer(v1))), &a2, 32.526913, 32.526913)
								if nox_xxx_mapGenCheckRoomType_5238F0(v2) != 0 {
									v21 = float64(a2.field_4)
									if v32 == 1 {
										v22 = v21 + 32.526913
									} else {
										v22 = v21 - 32.526913
									}
									a2.field_4 = float32(v22)
									sub_521BC0(int32(uintptr(unsafe.Pointer(v2))), &a2, 32.526913, 32.526913)
								}
								v23 = float64(v34.field_0) + 16.263456
								if v29 < 4 {
									v37 = v34.field_4
								} else {
									v34.field_0 = float32(v23 + 32.526913)
									sub_527030(&v34)
									v34.field_0 = float32(float64(v34.field_0) + 16.263456)
									nox_xxx_mapGenGetObjID_527940(internCStr("ArchedHalfDoor"))
									v24 = nox_xxx_mapGenPlaceObj_5279B0((*float2)(unsafe.Pointer(&v34.field_0)))
									if v24 != nil {
										nox_xxx_mapGenOrientObj_527C60(int32(uintptr(unsafe.Pointer(v24))), 3)
									}
									v25 = float64(v34.field_0) - 32.526913
									v37 = v34.field_4
									v36 = float32(v25)
									a2.field_0 = float32(v25)
									if v32 == 1 {
										a2.field_4 = float32(float64(v34.field_4) - 32.526913)
									} else {
										a2.field_4 = v34.field_4
									}
									sub_521BC0(int32(uintptr(unsafe.Pointer(v1))), &a2, 32.526913, 32.526913)
									if nox_xxx_mapGenCheckRoomType_5238F0(v2) != 0 {
										v26 = float64(a2.field_4)
										if v32 == 1 {
											v27 = v26 + 32.526913
										} else {
											v27 = v26 - 32.526913
										}
										a2.field_4 = float32(v27)
										sub_521BC0(int32(uintptr(unsafe.Pointer(v2))), &a2, 32.526913, 32.526913)
									}
									v23 = float64(v36)
								}
								v39.field_0 = float32(v23)
								v39.field_4 = float32(float64(v37) - 32.526913)
								v38.field_0 = float32(v23)
								v38.field_4 = float32(float64(v37) + 32.526913)
								sub_522C80(&v39.field_0)
								sub_522C80(&v38.field_0)
								sub_51D3F0(&v39, &v38)
								sub_51D3F0(&v38, &v39)
								if v32 == 1 {
									sub_522CA0(int32(uintptr(unsafe.Pointer(v1))), &v39.field_0)
									if *v2 == 1 {
										sub_522CA0(int32(uintptr(unsafe.Pointer(v2))), &v38.field_0)
									}
								} else {
									sub_522CA0(int32(uintptr(unsafe.Pointer(v1))), &v38.field_0)
									if *v2 == 1 {
										sub_522CA0(int32(uintptr(unsafe.Pointer(v2))), &v39.field_0)
									}
								}
								sub_521900(int32(uintptr(unsafe.Pointer(v1))), int32(uintptr(unsafe.Pointer(v2))), v32)
								v28 = sub_523960(v32)
								sub_521900(int32(uintptr(unsafe.Pointer(v2))), int32(uintptr(unsafe.Pointer(v1))), v28)
							}
							v19 = v31
							v3 = v31
							v29 = 1
							v2 = v18
							if v18 != nil && *v18 == 1 && v32 == 1 {
								v2 = nil
							}
						}
						a1.field_0++
						v31 = v19 + 1
						if uint32(v19+1) >= *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*3))) {
							v4 = v32
							goto LABEL_115
						}
					}
					fallthrough
				case 2, 3:
					if v4 == 2 {
						a1.field_0 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*1))) + *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*3))))
					} else {
						a1.field_0 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*1))) - 1)
					}
					v30 = 0
					a1.field_4 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*2)))
					if *((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v1))), 4*4))) <= 0 {
						goto LABEL_115
					}
					for {
						v5 = sub_521290(&a1)
						v6 = (*int32)(unsafe.Pointer(uintptr(v5)))
						if v5 != 0 {
							if (*int32)(unsafe.Pointer(uintptr(v5))) == v2 {
								if int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 52))))&2 != 0 {
									v29++
								}
							}
						}
						if (*int32)(unsafe.Pointer(uintptr(v5))) != v2 || (func() bool {
							v7 = v30
							return uint32(v30) == *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*4)))-1
						}()) {
							if v2 != nil && v29 >= 3 {
								if v32 == 2 {
									v34.field_0 = *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*11))
								} else {
									v34.field_0 = *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*9))
								}
								v34.field_4 = float32(float64((v3+v30)/2)*32.526913 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*10))))
								sub_527030(&v34)
								v34.field_4 = float32(float64(v34.field_4) - 16.263456)
								if v29 < 4 {
									nox_xxx_mapGenGetObjID_527940(internCStr("ArchedDoor"))
								} else {
									nox_xxx_mapGenGetObjID_527940(internCStr("ArchedHalfDoor"))
								}
								v8 = nox_xxx_mapGenPlaceObj_5279B0((*float2)(unsafe.Pointer(&v34.field_0)))
								if v8 != nil {
									nox_xxx_mapGenOrientObj_527C60(int32(uintptr(unsafe.Pointer(v8))), 7)
								}
								if v32 == 2 {
									a2.field_0 = float32(float64(v34.field_0) - 32.526913)
								} else {
									a2.field_0 = v34.field_0
								}
								a2.field_4 = v34.field_4
								sub_521BC0(int32(uintptr(unsafe.Pointer(v1))), &a2, 32.526913, 32.526913)
								if nox_xxx_mapGenCheckRoomType_5238F0(v2) != 0 {
									v9 = float64(a2.field_0)
									if v32 == 2 {
										v10 = v9 + 32.526913
									} else {
										v10 = v9 - 32.526913
									}
									a2.field_0 = float32(v10)
									sub_521BC0(int32(uintptr(unsafe.Pointer(v2))), &a2, 32.526913, 32.526913)
								}
								if v29 < 4 {
									v15 = float64(v34.field_4) + 16.263456
									v36 = v34.field_0
								} else {
									v34.field_4 = float32(float64(v34.field_4) + 16.263456 + 32.526913)
									sub_527030(&v34)
									v34.field_4 = float32(float64(v34.field_4) + 16.263456)
									nox_xxx_mapGenGetObjID_527940(internCStr("ArchedHalfDoor"))
									v11 = nox_xxx_mapGenPlaceObj_5279B0((*float2)(unsafe.Pointer(&v34.field_0)))
									if v11 != nil {
										nox_xxx_mapGenOrientObj_527C60(int32(uintptr(unsafe.Pointer(v11))), 1)
									}
									v12 = float64(v34.field_4) - 32.526913
									v36 = v34.field_0
									v37 = float32(v12)
									if v32 == 2 {
										a2.field_0 = float32(float64(v34.field_0) - 32.526913)
									} else {
										a2.field_0 = v34.field_0
									}
									a2.field_4 = float32(v12)
									sub_521BC0(int32(uintptr(unsafe.Pointer(v1))), &a2, 32.526913, 32.526913)
									if nox_xxx_mapGenCheckRoomType_5238F0(v2) != 0 {
										v13 = float64(a2.field_0)
										if v32 == 2 {
											v14 = v13 + 32.526913
										} else {
											v14 = v13 - 32.526913
										}
										a2.field_0 = float32(v14)
										sub_521BC0(int32(uintptr(unsafe.Pointer(v2))), &a2, 32.526913, 32.526913)
									}
									v15 = float64(v37)
								}
								v39.field_0 = float32(float64(v36) - 32.526913)
								v39.field_4 = float32(v15)
								v38.field_0 = float32(float64(v36) + 32.526913)
								v38.field_4 = float32(v15)
								sub_522C80(&v39.field_0)
								sub_522C80(&v38.field_0)
								sub_51D3F0(&v39, &v38)
								sub_51D3F0(&v38, &v39)
								if v32 == 2 {
									sub_522CA0(int32(uintptr(unsafe.Pointer(v1))), &v39.field_0)
									if *v2 == 1 {
										sub_522CA0(int32(uintptr(unsafe.Pointer(v2))), &v38.field_0)
									}
								} else {
									sub_522CA0(int32(uintptr(unsafe.Pointer(v1))), &v38.field_0)
									if *v2 == 1 {
										sub_522CA0(int32(uintptr(unsafe.Pointer(v2))), &v39.field_0)
									}
								}
								sub_521900(int32(uintptr(unsafe.Pointer(v1))), int32(uintptr(unsafe.Pointer(v2))), v32)
								v16 = sub_523960(v32)
								sub_521900(int32(uintptr(unsafe.Pointer(v2))), int32(uintptr(unsafe.Pointer(v1))), v16)
							}
							v7 = v30
							v29 = 1
							v3 = v30
							v2 = v6
							if v6 != nil && *v6 == 1 && v32 == 3 {
								v2 = nil
							}
						}
						a1.field_4++
						v30 = v7 + 1
						if uint32(v7+1) >= *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*4))) {
							v4 = v32
							break
						}
					}
				default:
					goto LABEL_115
				}
			}
		LABEL_115:
			v32 = func() int32 {
				p := &v4
				*p++
				return *p
			}()
			if v4 >= 4 {
				break
			}
			v2 = nil
		}
		v2 = nil
	LABEL_117:
		result = (*float32)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(v1)))))))
		v1 = result
		if result == nil {
			break
		}
	}
	return result
}
func nox_xxx_mapGenMkSmallRoom_4D4F40(a1 *uint32) *float32 {
	var (
		v1     *float32
		result *float32
		v3     float64
		v4     int32
		v5     *int32
		v6     *float32
		v7     int32
		v8     float64
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		v13    *int32
		v14    int32
		v15    int32
		v16    *float32
		v17    int32
		v18    int32
		v19    int32
		v20    int32
		v21    int32
		v22    float2
		v24    int32
		v25    *int32
		v26    *float32
		v27    int32
		v28    float2
		v30    [128]int32
	)
	v1 = nil
	dword_5d4594_1550912 = 0
	if *a1 == 1 {
		v26 = nil
		v24 = 0
		v22.field_0 = 0.0
		v22.field_4 = 0.0
		v25 = mem_getI32Ptr(0x587000, 197924)
	LABEL_5:
		v4 = 0
		v5 = &v30[v24]
		v27 = *v25
		for {
			result = (*float32)(alloc.Calloc1(1, 0x178))
			v6 = result
			*v5 = int32(uintptr(unsafe.Pointer(result)))
			if result == nil {
				break
			}
			v7 = v27
			*(*uint32)(unsafe.Pointer(v6)) = uint32(v27)
			switch v7 {
			case 2:
				v22.field_4 = float32(float64(v22.field_4) - 162.63457)
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*3))) = 4
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*4))) = 5
				sub_521900(int32(uintptr(unsafe.Pointer(v6))), int32(uintptr(unsafe.Pointer(v1))), 1)
				sub_521900(int32(uintptr(unsafe.Pointer(v1))), int32(uintptr(unsafe.Pointer(v6))), 0)
			case 3:
				if *(*uint32)(unsafe.Pointer(v1)) == 4 {
					v22.field_0 = float32(float64(v22.field_0) + 32.526913)
					v8 = float64(v22.field_4) + 130.10765
				} else {
					v8 = float64(v22.field_4) + 162.63457
				}
				v22.field_4 = float32(v8)
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*3))) = 4
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*4))) = 5
				sub_521900(int32(uintptr(unsafe.Pointer(v6))), int32(uintptr(unsafe.Pointer(v1))), 0)
				sub_521900(int32(uintptr(unsafe.Pointer(v1))), int32(uintptr(unsafe.Pointer(v6))), 1)
			case 4:
				if v1 != nil {
					v22.field_0 = float32(float64(v22.field_0) + 162.63457)
					sub_521900(int32(uintptr(unsafe.Pointer(v6))), int32(uintptr(unsafe.Pointer(v1))), 3)
					sub_521900(int32(uintptr(unsafe.Pointer(v1))), int32(uintptr(unsafe.Pointer(v6))), 2)
				}
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*3))) = 5
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*4))) = 4
			case 5:
				if *(*uint32)(unsafe.Pointer(v1)) == 3 {
					v22.field_4 = float32(float64(v22.field_4) + 32.526913)
				}
				v22.field_0 = float32(float64(v22.field_0) - 162.63457)
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*3))) = 5
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*4))) = 4
				sub_521900(int32(uintptr(unsafe.Pointer(v6))), int32(uintptr(unsafe.Pointer(v1))), 2)
				sub_521900(int32(uintptr(unsafe.Pointer(v1))), int32(uintptr(unsafe.Pointer(v6))), 3)
				if v4 == 5 {
					v26 = v6
				}
			default:
			}
			v28.field_0 = float32(float64(v22.field_0) - 878.22662)
			v28.field_4 = float32(float64(v22.field_4) - 878.22662)
			*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*7)) = float32(float64(*((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v6))), 4*3)))) * 32.526913)
			*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*8)) = float32(float64(*((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v6))), 4*4)))) * 32.526913)
			nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v6)), &v28)
			nox_xxx_mapGenAddNewRoom_521730((*uint32)(unsafe.Pointer(v6)))
			v1 = v6
			v9 = v24 + 1
			v5 = (*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
			v4++
			v24++
			if v4 >= 10 {
				v25 = (*int32)(unsafe.Add(unsafe.Pointer(v25), 4*1))
				if int32(uintptr(unsafe.Pointer(v25))) < int32(uintptr(memmap.PtrOff(0x587000, 197940))) {
					goto LABEL_5
				}
				v10 = v30[0]
				v11 = v9
				v12 = v30[v9-1]
				v13 = &v30[v11]
				sub_521900(v12, v30[0], 2)
				sub_521900(v10, v12, 3)
				v14 = int32(uintptr(unsafe.Pointer(v26)))
				v15 = 0
				v22.field_0 = *(*float32)(unsafe.Add(unsafe.Pointer(v26), unsafe.Sizeof(float32(0))*5))
				v22.field_4 = *(*float32)(unsafe.Add(unsafe.Pointer(v26), unsafe.Sizeof(float32(0))*8)) + *(*float32)(unsafe.Add(unsafe.Pointer(v26), unsafe.Sizeof(float32(0))*6))
				for {
					result = (*float32)(alloc.Calloc1(1, 0x178))
					v16 = result
					*v13 = int32(uintptr(unsafe.Pointer(result)))
					if result == nil {
						break
					}
					*(*uint32)(unsafe.Pointer(result)) = 3
					*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(result))), 4*3))) = 4
					*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(result))), 4*4))) = 5
					sub_521900(int32(uintptr(unsafe.Pointer(result))), v14, 0)
					sub_521900(v14, int32(uintptr(unsafe.Pointer(v16))), 1)
					*(*float32)(unsafe.Add(unsafe.Pointer(v16), unsafe.Sizeof(float32(0))*7)) = float32(float64(*((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v16))), 4*3)))) * 32.526913)
					*(*float32)(unsafe.Add(unsafe.Pointer(v16), unsafe.Sizeof(float32(0))*8)) = float32(float64(*((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v16))), 4*4)))) * 32.526913)
					nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v16)), &v22)
					nox_xxx_mapGenAddNewRoom_521730((*uint32)(unsafe.Pointer(v16)))
					v14 = int32(uintptr(unsafe.Pointer(v16)))
					v17 = v24 + 1
					v13 = (*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1))
					v15++
					v22.field_4 = float32(float64(v22.field_4) + 162.63457)
					v24++
					if v15 >= 8 {
						v18 = v17
						v19 = v17 / 5
						if v17/5 < 1 {
							v19 = 1
						}
						v20 = nox_xxx_mapGenRandFunc_526AC0(0, v19)
						for {
							v21 = v30[v20]
							*(*uint32)(unsafe.Pointer(uintptr(v21 + 84))) = dword_5d4594_1550912
							dword_5d4594_1550912 = uint32(v21)
							v20 += nox_xxx_mapGenRandFunc_526AC0(1, v19)
							if v20 >= v18 {
								break
							}
						}
						result = (*float32)(unsafe.Pointer(uintptr(v30[v18-1])))
						dword_5d4594_1550916 = uint32(v30[v18-1])
						return result
					}
				}
				return result
			}
		}
	} else {
		result = nox_xxx_mapGenPrepareRoom_521990(int32(uintptr(unsafe.Pointer(a1))))
		dword_5d4594_1550916 = uint32(uintptr(unsafe.Pointer(result)))
		if result != nil {
			v3 = float64(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*17))))
			v22.field_0 = 0.0
			v22.field_4 = float32(v3*32.526913 - float64(*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*8))) + 97.580734)
			nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(result)), &v22)
			nox_xxx_mapGenAddNewRoom_521730(*(**uint32)(unsafe.Pointer(&dword_5d4594_1550916)))
			result = *(**float32)(unsafe.Pointer(&dword_5d4594_1550916))
			*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1550916 + 84))) = dword_5d4594_1550912
			dword_5d4594_1550912 = dword_5d4594_1550916
		}
	}
	return result
}
func sub_4D52F0() {
	var v0 *uint32
	v0 = *(**uint32)(unsafe.Pointer(&dword_5d4594_1550912))
	if dword_5d4594_1550912 != 0 {
		for {
			switch *v0 {
			case 1:
				sub_4D5350(v0, 0, 0, 0, 0)
			case 2, 3:
				sub_4D5350(v0, 0, 0, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*3))), 0)
			case 4, 5:
				sub_4D5350(v0, 0, 0, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*4))), 0)
			default:
			}
			v0 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*21)))))
			if v0 == nil {
				break
			}
		}
	}
}
func sub_4D5350(a1 *uint32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		v5     int32
		result int32
	)
	v5 = a2 + 1
	if a2+1 >= *memmap.PtrInt32(0x5D4594, 1549868) {
		return 0
	}
	nox_xxx_mapGenSetFlags_5235F0(-101)
	if *a1 == 1 {
		result = nox_xxx_mapGenFillRoom_4D53B0(int32(uintptr(unsafe.Pointer(a1))), v5, a3, a4, a5)
	} else {
		result = sub_4D5630(int32(uintptr(unsafe.Pointer(a1))), v5, a3, a4, a5)
	}
	return result
}
func nox_xxx_mapGenFillRoom_4D53B0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		v5  *float32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 *float32
		v19 float64
		v20 float64
		v21 int32
		v22 int32
		v23 *int32
		v24 int32
		v25 int32
		v26 int32
		v28 int32
		a2a float2
		v30 int32
		v31 int32
	)
	_ = v31
	var v32 int32
	_ = v32
	var v33 int32
	_ = v33
	var v34 int32
	v5 = (*float32)(unsafe.Pointer(uintptr(a1)))
	v6 = sub_5218B0(a1, 0)
	if v6 != 0 {
		v7 = 0
	} else {
		v7 = 2
	}
	if v6 != 0 {
		v30 = 0
	} else {
		v30 = 2
	}
	v8 = sub_5218B0(a1, 1)
	if v8 != 0 {
		v9 = 0
	} else {
		v9 = 3
	}
	if v8 != 0 {
		v31 = 0
	} else {
		v31 = 3
	}
	v10 = sub_5218B0(a1, 2)
	if v10 != 0 {
		v11 = 0
	} else {
		v11 = 4
	}
	if v10 != 0 {
		v32 = 0
	} else {
		v32 = 4
	}
	v12 = -bool2int32(sub_5218B0(a1, 3) != 0)
	*((*uint8)(unsafe.Pointer(&v12))) = uint8(int8(v12 & 0xFB))
	v13 = v12 + 5
	v33 = v13
	if v7 != 0 || v9 != 0 || v11 != 0 || v13 != 0 {
		v14 = nox_xxx_mapGenRandFunc_526AC0(0, 3)
		v34 = 0
		for {
			v15 = (v14 + 1) % 4
			v16 = *((*int32)(unsafe.Add(unsafe.Pointer(&v30), 4*uintptr(v15))))
			v28 = v15
			if v16 == 0 {
				v14 = v28
				continue
			}
			v17 = nox_xxx_mapGenRandFunc_526AC0(int32(*memmap.PtrUint32(0x5D4594, 1549808)-*memmap.PtrUint32(0x5D4594, 1549812)), int32(*memmap.PtrUint32(0x5D4594, 1549812)+*memmap.PtrUint32(0x5D4594, 1549808)))
			v18 = nox_xxx_mapGenMakeHall_523EC0(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), v16, v17)
			if v18 == nil {
				return 0
			}
			switch *(*uint32)(unsafe.Pointer(v18)) {
			case 2:
				a2a.field_0 = float32(sub_521B00(int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(unsafe.Pointer(v18)))))
				v19 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*6)) - *(*float32)(unsafe.Add(unsafe.Pointer(v18), unsafe.Sizeof(float32(0))*8)))
				a2a.field_4 = float32(v19)
			case 3:
				a2a.field_0 = float32(sub_521B00(int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(unsafe.Pointer(v18)))))
				v19 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*8)) + *(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*6)))
				a2a.field_4 = float32(v19)
			case 4:
				v20 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*7)) + *(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*5)))
				a2a.field_0 = float32(v20)
				v19 = sub_521B30(int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(unsafe.Pointer(v18))))
				a2a.field_4 = float32(v19)
			case 5:
				v20 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*5)) - *(*float32)(unsafe.Add(unsafe.Pointer(v18), unsafe.Sizeof(float32(0))*7)))
				a2a.field_0 = float32(v20)
				v19 = sub_521B30(int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(unsafe.Pointer(v18))))
				a2a.field_4 = float32(v19)
			default:
			}
			nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v18)), &a2a)
			if sub_5217A0(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(uintptr(unsafe.Pointer(v18)))) == 0 {
				sub_521A10(unsafe.Pointer(v18))
				goto LABEL_26
			}
			v21 = sub_523920(int32(*(*uint32)(unsafe.Pointer(v18))))
			v22 = sub_523960(v21)
			sub_521900(int32(uintptr(unsafe.Pointer(v18))), int32(uintptr(unsafe.Pointer(v5))), v22)
			v23 = (*int32)(unsafe.Pointer(uintptr(sub_521200(int32(uintptr(unsafe.Pointer(v18)))))))
			v24 = int32(uintptr(unsafe.Pointer(v23)))
			if v23 != nil {
				if nox_xxx_mapGenCheckRoomType_5238F0(v23) != 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(v24 + 52))))&2 != 0 || v24 == a5 || nox_xxx_mapGenRandFunc_526AC0(1, 100) > *(*int32)(unsafe.Pointer(&dword_5d4594_1549844)) || sub_523A10(int32(uintptr(unsafe.Pointer(v18))), (*float32)(unsafe.Pointer(uintptr(v24)))) == 0 {
					sub_521A10(unsafe.Pointer(v18))
				} else {
					nox_xxx_mapGenAddNewRoom_521730((*uint32)(unsafe.Pointer(v18)))
					v25 = sub_523920(int32(*(*uint32)(unsafe.Pointer(v18))))
					sub_521A70(int32(uintptr(unsafe.Pointer(v18))), v24, v25)
					v26 = sub_523920(int32(*(*uint32)(unsafe.Pointer(v18))))
					sub_521900(int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(unsafe.Pointer(v18))), v26)
				}
				goto LABEL_26
			}
			nox_xxx_mapGenAddNewRoom_521730((*uint32)(unsafe.Pointer(v18)))
			if sub_4D5350((*uint32)(unsafe.Pointer(v18)), a2, 1, v17, int32(uintptr(unsafe.Pointer(v5)))) != 0 {
				v26 = sub_523920(int32(*(*uint32)(unsafe.Pointer(v18))))
				sub_521900(int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(unsafe.Pointer(v18))), v26)
				goto LABEL_26
			}
			sub_521760(int32(uintptr(unsafe.Pointer(v18))))
			sub_521A10(unsafe.Pointer(v18))
		LABEL_26:
			if func() int32 {
				p := &v34
				*p++
				return *p
			}() >= 8 {
				return 1
			}
			v14 = v28
		}
	}
	return 1
}
func sub_4D5630(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		v5  int32
		v6  int32
		v7  int32
		v8  *float32
		v9  float64
		v10 float64
		v11 int32
		v13 *float32
		v14 *float32
		v15 float64
		v16 float64
		v17 int32
		v18 *float32
		v19 int32
		v20 int32
		v21 int32
		v22 *float32
		v23 float64
		v24 float64
		v25 float64
		v26 int32
		v27 *float32
		v28 int32
		v29 int32
		v30 int32
		v31 *float32
		v32 *int32
		v33 float64
		v34 float64
		v35 float64
		v36 float64
		v37 int32
		v38 int32
		v39 *float32
		v40 int32
		v41 int32
		v42 int32
		v43 int32
		v44 int32
		v45 int32
		a2a float2
		v47 int32
		v48 int32
		v49 int32
	)
	v5 = a1
	v43 = 0
	v44 = 0
	if a3 >= *memmap.PtrInt32(0x5D4594, 1549816) || (func() bool {
		v6 = sub_4D5D20((*uint32)(unsafe.Pointer(uintptr(a1))))
		v45 = v6
		return v6 == 1
	}()) {
		v7 = 0
		for {
			v8 = nox_xxx_mapGenPrepareRoom_521990(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))))
			if v8 == nil {
				return 0
			}
			switch *(*uint32)(unsafe.Pointer(uintptr(a1))) {
			case 2:
				a2a.field_0 = float32(sub_521B60(int32(uintptr(unsafe.Pointer(v8))), a1))
				v9 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 24))) - *(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*8)))
				a2a.field_4 = float32(v9)
			case 3:
				a2a.field_0 = float32(sub_521B60(int32(uintptr(unsafe.Pointer(v8))), a1))
				v9 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 32))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 24))))
				a2a.field_4 = float32(v9)
			case 4:
				v10 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 28))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 20))))
				a2a.field_0 = float32(v10)
				v9 = sub_521B90(int32(uintptr(unsafe.Pointer(v8))), a1)
				a2a.field_4 = float32(v9)
			case 5:
				v10 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 20))) - *(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*7)))
				a2a.field_0 = float32(v10)
				v9 = sub_521B90(int32(uintptr(unsafe.Pointer(v8))), a1)
				a2a.field_4 = float32(v9)
			default:
			}
			nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v8)), &a2a)
			if sub_521820(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(uintptr(unsafe.Pointer(v8)))) == 0 {
				sub_521A10(unsafe.Pointer(v8))
				if func() int32 {
					p := &v7
					*p++
					return *p
				}() < 10 {
					continue
				}
			}
			if v7 == 10 {
				return 0
			}
			nox_xxx_mapGenAddNewRoom_521730((*uint32)(unsafe.Pointer(v8)))
			v11 = sub_523920(int32(*(*uint32)(unsafe.Pointer(uintptr(a1)))))
			sub_521A70(a1, int32(uintptr(unsafe.Pointer(v8))), v11)
			sub_4D5350((*uint32)(unsafe.Pointer(v8)), a2, 0, 0, int32(uintptr(unsafe.Pointer(v8))))
			return 1
		}
	}
	if v6 != 2 && v6 != 8 && v6 != 32 && v6 != 64 {
		goto LABEL_43
	}
	v13 = nox_xxx_mapGenMakeHall_523EC0(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(*memmap.PtrUint32(0x587000, uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1))))*4+197812)), a4)
	v14 = v13
	if v13 == nil {
		return 0
	}
	switch *(*uint32)(unsafe.Pointer(uintptr(a1))) {
	case 2:
		v15 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 20))) - *(*float32)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(float32(0))*7)))
		a2a.field_4 = *(*float32)(unsafe.Pointer(uintptr(a1 + 24)))
		a2a.field_0 = float32(v15)
	case 3:
		a2a.field_0 = *(*float32)(unsafe.Pointer(uintptr(a1 + 28))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 20)))
		v16 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 32))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 24))) - *(*float32)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(float32(0))*8)))
		a2a.field_4 = float32(v16)
	case 4:
		a2a.field_0 = *(*float32)(unsafe.Pointer(uintptr(a1 + 28))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 20))) - *(*float32)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(float32(0))*7))
		v16 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 24))) - *(*float32)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(float32(0))*8)))
		a2a.field_4 = float32(v16)
	case 5:
		v16 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 32))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 24))))
		a2a.field_0 = *(*float32)(unsafe.Pointer(uintptr(a1 + 20)))
		a2a.field_4 = float32(v16)
	default:
	}
	nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v13)), &a2a)
	v47 = sub_5239B0(int32(*(*uint32)(unsafe.Pointer(uintptr(a1)))))
	sub_521900(int32(uintptr(unsafe.Pointer(v14))), v5, v47)
	if sub_5217A0(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(uintptr(unsafe.Pointer(v14)))) == 0 {
		v43 = 0
		sub_521A10(unsafe.Pointer(v14))
		if v45 == 2 || v45 == 8 {
			return 0
		}
		goto LABEL_43
	}
	v17 = sub_521200(int32(uintptr(unsafe.Pointer(v14))))
	v18 = (*float32)(unsafe.Pointer(uintptr(v17)))
	if v17 == 0 {
		v43 = 1
		v19 = 0
		goto LABEL_34
	}
	if *(*uint32)(unsafe.Pointer(uintptr(v17))) != 1 || int32(*(*uint8)(unsafe.Pointer(uintptr(v17 + 52))))&2 != 0 || v17 == a5 || nox_xxx_mapGenRandFunc_526AC0(1, 100) > *(*int32)(unsafe.Pointer(&dword_5d4594_1549844)) {
		v43 = 0
		sub_521A10(unsafe.Pointer(v14))
		if v45 == 2 || v45 == 8 {
			return 0
		}
		goto LABEL_43
	}
	v43 = sub_523A10(int32(uintptr(unsafe.Pointer(v14))), v18)
	v19 = 1
	if v43 == 0 {
		sub_521A10(unsafe.Pointer(v14))
		if v45 == 2 || v45 == 8 {
			return 0
		}
		goto LABEL_43
	}
LABEL_34:
	nox_xxx_mapGenAddNewRoom_521730((*uint32)(unsafe.Pointer(v14)))
	if v19 == 0 {
		if sub_4D5350((*uint32)(unsafe.Pointer(v14)), a2, a3+1, a4, a5) != 0 {
			goto LABEL_39
		}
		sub_521760(int32(uintptr(unsafe.Pointer(v14))))
		v43 = 0
		sub_521A10(unsafe.Pointer(v14))
		if v45 == 2 || v45 == 8 {
			return 0
		}
		goto LABEL_43
	}
	v20 = sub_523920(int32(*(*uint32)(unsafe.Pointer(v14))))
	sub_521A70(int32(uintptr(unsafe.Pointer(v14))), int32(uintptr(unsafe.Pointer(v18))), v20)
LABEL_39:
	v21 = sub_523960(v47)
	sub_521900(v5, int32(uintptr(unsafe.Pointer(v14))), v21)
LABEL_43:
	if v45 != 4 && v45 != 16 && v45 != 32 && v45 != 64 {
		goto LABEL_71
	}
	v22 = nox_xxx_mapGenMakeHall_523EC0(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(*memmap.PtrUint32(0x587000, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5))))*4+197836)), a4)
	if v22 == nil {
		return 0
	}
	switch *(*uint32)(unsafe.Pointer(uintptr(v5))) {
	case 2:
		v23 = float64(*(*float32)(unsafe.Pointer(uintptr(v5 + 28))) + *(*float32)(unsafe.Pointer(uintptr(v5 + 20))))
		a2a.field_4 = *(*float32)(unsafe.Pointer(uintptr(v5 + 24)))
		a2a.field_0 = float32(v23)
	case 3:
		a2a.field_0 = *(*float32)(unsafe.Pointer(uintptr(v5 + 20))) - *(*float32)(unsafe.Add(unsafe.Pointer(v22), unsafe.Sizeof(float32(0))*7))
		v24 = float64(*(*float32)(unsafe.Pointer(uintptr(v5 + 32))) + *(*float32)(unsafe.Pointer(uintptr(v5 + 24))))
		v25 = v24 - float64(*(*float32)(unsafe.Add(unsafe.Pointer(v22), unsafe.Sizeof(float32(0))*8)))
		a2a.field_4 = float32(v25)
	case 4:
		a2a.field_0 = *(*float32)(unsafe.Pointer(uintptr(v5 + 28))) + *(*float32)(unsafe.Pointer(uintptr(v5 + 20))) - *(*float32)(unsafe.Add(unsafe.Pointer(v22), unsafe.Sizeof(float32(0))*7))
		v25 = float64(*(*float32)(unsafe.Pointer(uintptr(v5 + 32))) + *(*float32)(unsafe.Pointer(uintptr(v5 + 24))))
		a2a.field_4 = float32(v25)
	case 5:
		v24 = float64(*(*float32)(unsafe.Pointer(uintptr(v5 + 24))))
		a2a.field_0 = *(*float32)(unsafe.Pointer(uintptr(v5 + 20)))
		v25 = v24 - float64(*(*float32)(unsafe.Add(unsafe.Pointer(v22), unsafe.Sizeof(float32(0))*8)))
		a2a.field_4 = float32(v25)
	default:
	}
	nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v22)), &a2a)
	v48 = sub_523970(int32(*(*uint32)(unsafe.Pointer(uintptr(v5)))))
	sub_521900(int32(uintptr(unsafe.Pointer(v22))), v5, v48)
	if sub_5217A0(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(uintptr(unsafe.Pointer(v22)))) == 0 {
		v44 = 0
		sub_521A10(unsafe.Pointer(v22))
		if v45 == 4 || v45 == 16 {
			return 0
		}
		goto LABEL_71
	}
	v26 = sub_521200(int32(uintptr(unsafe.Pointer(v22))))
	v27 = (*float32)(unsafe.Pointer(uintptr(v26)))
	if v26 == 0 {
		v44 = 1
		v28 = 0
	} else {
		if *(*uint32)(unsafe.Pointer(uintptr(v26))) != 1 || int32(*(*uint8)(unsafe.Pointer(uintptr(v26 + 52))))&2 != 0 || v26 == a5 || nox_xxx_mapGenRandFunc_526AC0(1, 100) > *(*int32)(unsafe.Pointer(&dword_5d4594_1549844)) {
			v44 = 0
			sub_521A10(unsafe.Pointer(v22))
			if v45 == 4 || v45 == 16 {
				return 0
			}
			goto LABEL_71
		}
		v44 = sub_523A10(int32(uintptr(unsafe.Pointer(v22))), v27)
		v28 = 1
		if v44 == 0 {
			sub_521A10(unsafe.Pointer(v22))
			if v45 == 4 || v45 == 16 {
				return 0
			}
			goto LABEL_71
		}
	}
	nox_xxx_mapGenAddNewRoom_521730((*uint32)(unsafe.Pointer(v22)))
	if v28 == 0 {
		if sub_4D5350((*uint32)(unsafe.Pointer(v22)), a2, a3+1, a4, a5) != 0 {
			goto LABEL_67
		}
		sub_521760(int32(uintptr(unsafe.Pointer(v22))))
		v44 = 0
		sub_521A10(unsafe.Pointer(v22))
		if v45 == 4 || v45 == 16 {
			return 0
		}
		goto LABEL_71
	}
	v29 = sub_523920(int32(*(*uint32)(unsafe.Pointer(v22))))
	sub_521A70(int32(uintptr(unsafe.Pointer(v22))), int32(uintptr(unsafe.Pointer(v27))), v29)
LABEL_67:
	v30 = sub_523960(v48)
	sub_521900(v5, int32(uintptr(unsafe.Pointer(v22))), v30)
LABEL_71:
	if v43 != 0 || v44 != 0 {
		if v45 != 32 && v45 != 8 && v45 != 16 {
			return 1
		}
		v31 = nox_xxx_mapGenMakeHall_523EC0(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(*(*uint32)(unsafe.Pointer(uintptr(v5)))), a4)
		v32 = (*int32)(unsafe.Pointer(v31))
		if v31 != nil {
			switch *(*uint32)(unsafe.Pointer(uintptr(v5))) {
			case 2:
				v33 = float64(*(*float32)(unsafe.Pointer(uintptr(v5 + 24))))
				a2a.field_0 = *(*float32)(unsafe.Pointer(uintptr(v5 + 20)))
				a2a.field_4 = float32(v33 - float64(*(*float32)(unsafe.Add(unsafe.Pointer(v31), unsafe.Sizeof(float32(0))*8))))
			case 3:
				v34 = float64(*(*float32)(unsafe.Pointer(uintptr(v5 + 32))) + *(*float32)(unsafe.Pointer(uintptr(v5 + 24))))
				a2a.field_0 = *(*float32)(unsafe.Pointer(uintptr(v5 + 20)))
				a2a.field_4 = float32(v34)
			case 4:
				v35 = float64(*(*float32)(unsafe.Pointer(uintptr(v5 + 28))) + *(*float32)(unsafe.Pointer(uintptr(v5 + 20))))
				a2a.field_4 = *(*float32)(unsafe.Pointer(uintptr(v5 + 24)))
				a2a.field_0 = float32(v35)
			case 5:
				v36 = float64(*(*float32)(unsafe.Pointer(uintptr(v5 + 20))) - *(*float32)(unsafe.Add(unsafe.Pointer(v31), unsafe.Sizeof(float32(0))*7)))
				a2a.field_4 = *(*float32)(unsafe.Pointer(uintptr(v5 + 24)))
				a2a.field_0 = float32(v36)
			default:
			}
			nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v31)), &a2a)
			v37 = sub_523920(int32(*(*uint32)(unsafe.Pointer(uintptr(v5)))))
			v49 = sub_523960(v37)
			sub_521900(int32(uintptr(unsafe.Pointer(v32))), v5, v49)
			if sub_5217A0(int32(uintptr(memmap.PtrOff(0x5D4594, 1549796))), int32(uintptr(unsafe.Pointer(v32)))) == 0 {
				sub_521A10(unsafe.Pointer(v32))
				return 1
			}
			v38 = sub_521200(int32(uintptr(unsafe.Pointer(v32))))
			v39 = (*float32)(unsafe.Pointer(uintptr(v38)))
			if v38 == 0 {
				v40 = 0
			} else {
				if *(*uint32)(unsafe.Pointer(uintptr(v38))) == 1 && (int32(*(*uint8)(unsafe.Pointer(uintptr(v38 + 52))))&2) == 0 && v38 != a5 && nox_xxx_mapGenRandFunc_526AC0(1, 100) <= *(*int32)(unsafe.Pointer(&dword_5d4594_1549844)) {
					v40 = 1
					if sub_523A10(int32(uintptr(unsafe.Pointer(v32))), v39) != 0 {
						goto LABEL_89
					}
				}
				sub_521A10(unsafe.Pointer(v32))
				return 1
			}
		LABEL_89:
			nox_xxx_mapGenAddNewRoom_521730((*uint32)(unsafe.Pointer(v32)))
			if v40 != 0 {
				v41 = sub_523920(*v32)
				sub_521A70(int32(uintptr(unsafe.Pointer(v32))), int32(uintptr(unsafe.Pointer(v39))), v41)
				v42 = sub_523960(v49)
				sub_521900(v5, int32(uintptr(unsafe.Pointer(v32))), v42)
				return 1
			}
			if sub_4D5350((*uint32)(unsafe.Pointer(v32)), a2, a3+1, a4, a5) != 0 {
				v42 = sub_523960(v49)
				sub_521900(v5, int32(uintptr(unsafe.Pointer(v32))), v42)
				return 1
			}
			sub_521760(int32(uintptr(unsafe.Pointer(v32))))
			sub_521A10(unsafe.Pointer(v32))
			return 1
		}
	}
	return 0
}
func sub_4D5D20(a1 *uint32) int32 {
	var result int32
	if *a1 == 2 || *a1 == 3 {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) >= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) {
			return 1
		}
	} else if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) >= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) {
		return 1
	}
	if nox_xxx_mapGenRandFunc_526AC0(1, 100) > *memmap.PtrInt32(0x5D4594, 1549820) {
		if nox_xxx_mapGenRandFunc_526AC0(1, 100) > *memmap.PtrInt32(0x5D4594, 1549824) {
			if nox_xxx_mapGenRandFunc_526AC0(1, 100) >= 50 {
				result = 4
			} else {
				result = 2
			}
		} else {
			result = 1
		}
	} else {
		nox_xxx_mapGenRandFunc_526AC0(1, 100)
		result = 32
	}
	return result
}
func nox_xxx_mapGenStartAlt_4D5F30() int32 {
	var (
		v0               int32
		v1               int32
		v2               *byte
		v3               *byte
		result           int32
		FileName         [1024]byte
		ExistingFileName [1024]byte
	)
	v0 = 100
	nox_xxx_setGameFlags_40A4D0(0x400000)
	libc.MemSet(memmap.PtrOff(0x973F18, 2408), 0, 0x5B8)
	for {
		v1 = nox_xxx_mapGenStep_4D44E0()
		if v1 == 1 {
			break
		}
		if v1 != 0 {
			if func() int32 {
				p := &v0
				*p--
				return *p
			}() != 0 {
				continue
			}
		}
		return 0
	}
	v2 = nox_fs_root()
	nox_sprintf(&FileName[0], internCStr("%s\\nc.obj"), v2)
	v3 = nox_fs_root()
	nox_sprintf(&ExistingFileName[0], internCStr("%s\\blend.obj"), v3)
	result = bool2int32(nox_fs_remove(&FileName[0]))
	if result == 0 {
		return result
	}
	if !nox_fs_move(&ExistingFileName[0], &FileName[0]) {
		return 0
	}
	nox_xxx_mapGenMakeInfo_4D5DB0(unsafe.Pointer(uintptr(int32(uintptr(memmap.PtrOff(0x973F18, 2408))))))
	nox_common_gameFlags_unset_40A540(0x400000)
	return 1
}
func sub_4D6000(a1p *server.Object) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result int32
		v2     int32
	)
	result = 0
	if a1 != 0 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4652))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4656))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4660))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4664))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4668))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4672))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4676))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4680))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4684))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4688))) = uint32(nox_game_getQuestStage_4E3CC0())
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))))
		*(*uint32)(unsafe.Pointer(uintptr(result + 4692))) = 63
	}
	return result
}
func sub_4D60B0() int32 {
	var (
		result int32
		i      int32
	)
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		sub_4D6000((*server.Object)(unsafe.Pointer(uintptr(i))))
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func sub_4D60E0(a1 int32) *uint32 {
	var (
		result *uint32
		v2     int32
	)
	result = (*uint32)(unsafe.Pointer(uintptr(a1)))
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16)))) & 0x20) != 32 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		result = *(**uint32)(unsafe.Pointer(uintptr(v2 + 276)))
		if *(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1198)) == 1 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1163))++
			result = *(**uint32)(unsafe.Pointer(uintptr(v2 + 276)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1173)) |= 1
		}
	}
	return result
}
func sub_4D6130(a1 int32) int32 {
	var (
		result int32
		v2     int32
	)
	result = a1
	if a1 != 0 {
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16)))) & 0x20) != 32 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4660)))++
			result = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))))
			*(*uint32)(unsafe.Pointer(uintptr(result + 4692))) |= 2
		}
	}
	return result
}
func sub_4D6170(a1 int32) int32 {
	var (
		result int32
		v2     int32
	)
	result = a1
	if a1 != 0 {
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16)))) & 0x20) != 32 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4664)))++
			result = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))))
			*(*uint32)(unsafe.Pointer(uintptr(result + 4692))) |= 4
		}
	}
	return result
}
func sub_4D61B0(a1 int32) {
	var v2 int32
	if a1 != 0 {
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16)))) & 0x20) != 32 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4668)))++
			var result int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))))
			*(*uint32)(unsafe.Pointer(uintptr(result + 4692))) |= 8
		}
	}
}
func sub_4D61F0(a1 int32) int32 {
	var (
		result int32
		v2     int32
	)
	result = a1
	if a1 != 0 {
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16)))) & 0x20) != 32 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4672)))++
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4676)))++
			result = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))))
			*(*uint32)(unsafe.Pointer(uintptr(result + 4692))) |= 0x10
		}
	}
	return result
}
func sub_4D6540(a1 int32) uint32 {
	var (
		v1     int32
		v2     *uint32
		v3     *uint32
		result uint32
		v5     uint32
		i      int32
		v7     *uint32
		v8     uint32
		v9     int32
		v10    float32
		v11    uint32
		v12    uint32
		v13    float32
		v14    uint32
	)
	v1 = nox_xxx_player_4E3CE0()
	v2 = (*uint32)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(a1)))
	v3 = v2
	if v2 == nil || *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1198)) == 0 {
		return 0
	}
	if v1 == 1 {
		result = uint32(sub_4D66E0(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1167)), *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1168)), *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1166)), *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1172))))
	} else {
		v5 = 0
		v11 = 0
		v14 = 0
		v12 = 1
		v13 = 1.0
		for i = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i))))))) {
			v7 = *(**uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 276)))
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1198)) != 0 {
				v8 = uint32(sub_4D66E0(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1167)), *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1168)), 0, *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1172))))
				if v8 > v5 {
					v5 = v8
				}
				v11 += *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1167))
				v12 = *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1172))
				v14 += *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1168))
			}
		}
		v9 = sub_4D66E0(v11, v14, 0, v12)
		if v5 > 0 {
			v13 = float32(float64(uint32(v9)) / float64(v5))
		}
		v10 = float32(float64(uint32(sub_4D66E0(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1167)), *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1168)), *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1166)), *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1172))))) * float64(v13))
		result = uint32(int32(v10))
	}
	if result > 0x3B9AC9FF {
		result = 999999999
	}
	return result
}
func sub_4D66E0(a1 uint32, a2 uint32, a3 uint32, a4 uint32) int32 {
	var v5 float32
	v5 = float32(float64(float32(math.Pow(float64(a4), *(*float64)(memmap.PtrOff(0x581450, 10088))))) * (float64(a1)*10.0 + float64(a2)*35.0 + float64(a3)*0.1))
	return int32(v5)
}
func sub_4D6770(a1 int32) int32 {
	var (
		v1 *byte
		v2 int32
		v3 int32
		v4 *byte
		v5 int32
		v7 [90]byte
	)
	v1 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(a1)))
	libc.MemSet(unsafe.Pointer(&v7[0]), 0, 0x58)
	*(*uint16)(unsafe.Pointer(&v7[88])) = 0
	v7[0] = 240
	v7[1] = 12
	*(*uint16)(unsafe.Pointer(&v7[2])) = uint16(int16(sub_4D7300()))
	v2 = 0
	v3 = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	if v3 != 0 {
		v4 = &v7[8]
		for {
			v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 748))))
			if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 4792))) == 1 && v2 < 6 {
				*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), -int(unsafe.Sizeof(uint16(0))*1)))) = *(*uint16)(unsafe.Pointer(uintptr(v3 + 36)))
				*(*uint16)(unsafe.Pointer(v4)) = *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 4668)))
				*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), unsafe.Sizeof(uint16(0))*3))) = *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 4664)))
				*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), unsafe.Sizeof(uint16(0))*1))) = *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 4672)))
				*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), unsafe.Sizeof(uint16(0))*2))) = *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 4680)))
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*2))) = sub_4D6540(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 2064)))))
				v2++
				v4 = (*byte)(unsafe.Add(unsafe.Pointer(v4), 14))
				*(*uint16)(unsafe.Pointer(&v7[4])) = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v1))), unsafe.Sizeof(uint16(0))*2344)))
			}
			v3 = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(v3)))))))
			if v3 == 0 {
				break
			}
		}
	}
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v7[0]))), 90, 0, 1)
}
func sub_4D6880(a1 int32, a2 int32) int32 {
	var v3 [69]byte
	libc.MemSet(unsafe.Pointer(&v3[0]), 0, 0x44)
	v3[68] = 0
	v3[0] = 240
	v3[1] = 13
	if a2 != 0 {
		v3[4] |= 1
	}
	if sub_51A950() != 0 {
		v3[4] |= 2
	}
	*(*uint16)(unsafe.Pointer(&v3[2])) = uint16(int16(nox_game_getQuestStage_4E3CC0()))
	nox_server_currentMapGetFilename_409B30()
	libc.StrCpy(&v3[5], sub_4D6940())
	nox_server_currentMapGetFilename_409B30()
	libc.StrCpy(&v3[37], sub_4D6950())
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v3[0]))), 69, 0, 1)
}
func sub_4D6940() *byte {
	return (*byte)(memmap.PtrOff(0x973F18, 3838))
}
func sub_4D6950() *byte {
	return (*byte)(memmap.PtrOff(0x973F18, 3806))
}
func nox_game_sendQuestStage_4D6960(a1 int32) int32 {
	var v2 [69]byte = [69]byte{}
	v2[0] = 240
	v2[1] = 14
	v2[4] = 0
	if sub_51A950() != 0 {
		v2[4] |= 2
	}
	*(*uint16)(unsafe.Pointer(&v2[2])) = uint16(int16(nox_game_getQuestStage_4E3CC0()))
	nox_server_currentMapGetFilename_409B30()
	libc.StrCpy(&v2[5], sub_4D6940())
	nox_server_currentMapGetFilename_409B30()
	libc.StrCpy(&v2[37], sub_4D6950())
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v2[0]))), 69, 0, 1)
}
func sub_4D6A20(a1 int32, a2 int32) int32 {
	var (
		v3 int16
		v5 int32
	)
	v3 = int16(*(*uint16)(unsafe.Pointer(uintptr(a2 + 40))))
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v5))), unsafe.Sizeof(uint16(0))*0)) = 4080
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v5))), unsafe.Sizeof(uint16(0))*1)) = uint16(v3)
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v5), 4, 0, 1)
}
func nox_xxx_isQuest_4D6F50() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1556160))
}
func nox_xxx_setQuest_4D6F60(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1556160) = uint32(a1)
	return result
}
func sub_4D6F70() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1556164))
}
func sub_4D6F80(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1556164) = uint32(a1)
	return result
}
func sub_4D6FA0() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1556104))
}
func sub_4D70B0() *byte {
	var result *byte
	result = *(**byte)(memmap.PtrOff(0x5D4594, 1556152))
	if *memmap.PtrUint32(0x5D4594, 1556152) == 0 {
		result = sub_4169F0()
	}
	return result
}
func nox_xxx_bookCreatureTest_4D70C0(a1 int32) int32 {
	return bool2int32(noxflags.HasGame(4096) || a1 != 37 && a1 != 38 && a1 != 40 && a1 != 39)
}
func sub_4D7100(a1 int32) int32 {
	return bool2int32(noxflags.HasGame(4096) || a1 != 111 && a1 != 112 && a1 != 114 && a1 != 113)
}
func sub_4D7150() int32 {
	var (
		result int32
		i      int32
		v2     *int32
		v3     int32
	)
	result = int32(dword_5d4594_1556144)
	if dword_5d4594_1556144 != 0 {
		if gameFrame() > uint32(*(*int32)(unsafe.Pointer(&dword_5d4594_1556144))) {
			result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
			for i = result; result != 0; i = result {
				v2 = *(**int32)(unsafe.Pointer(uintptr(i + 748)))
				v3 = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*69))
				if (int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 3680))))&1) == 1 && *(*uint32)(unsafe.Pointer(uintptr(v3 + 4792))) == 1 && *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*78)) == 0 && *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*79)) == 0 && (*(*uint32)(unsafe.Pointer(uintptr(v3 + 3680)))&0x10) == 16 {
					sub_4DF3C0((*server.Player)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*69))))))
					nox_xxx_playerLeaveObserver_0_4E6AA0((*server.Player)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*69))))))
					nox_xxx_playerCameraUnlock_4E6040((*server.Object)(unsafe.Pointer(uintptr(i))))
				}
				result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
			}
		}
	}
	return result
}
func sub_4D71E0(a1 int32) int32 {
	var result int32
	result = a1
	dword_5d4594_1556136 = uint32(a1)
	return result
}
func sub_4D71F0() uint32 {
	var (
		result uint32
		v1     int32
		v2     int8
	)
	result = dword_5d4594_1556136
	if dword_5d4594_1556136 != 0 {
		if (gameFrame() - dword_5d4594_1556136) >= 0x2328 {
			v1 = 0
			result = uint32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
			if result != 0 {
				for {
					if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(result + 748))) + 308))) != 0 {
						v1 = 1
					}
					result = uint32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(result)))))))
					if result == 0 {
						break
					}
				}
				if v1 != 0 {
					result = uint32(nox_xxx_player_4E3CE0())
					if result > 1 {
						sub_4D71E0(0)
						result = uint32(sub_4D72C0())
						if result == 0 {
							sub_4D72B0(1)
							v2 = int8(sub_4D72C0())
							result = uint32(sub_4D7280(math.MaxUint8, v2))
						}
					}
				}
			}
		}
	}
	return result
}
func sub_4D7280(a1 int32, a2 int8) int32 {
	var v4 [3]byte
	v4[0] = 240
	v4[1] = 24
	v4[2] = byte(a2)
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v4[0]))), 3, 0, 1)
}
func sub_4D72D0(a1 int32) int32 {
	var result int32
	result = int32(dword_5d4594_1556128)
	*memmap.PtrUint32(0x5D4594, 1556132) = dword_5d4594_1556128
	dword_5d4594_1556128 = uint32(a1)
	return result
}
func sub_4D7300() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1556132))
}
func sub_4D7430() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1556116))
}
func sub_4D7440(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1556116) = uint32(a1)
	return result
}
func sub_4D7450(a1 int32, a2 int16) int32 {
	var v3 [4]byte
	v3[0] = 240
	v3[1] = 29
	*(*uint16)(unsafe.Pointer(&v3[2])) = uint16(a2)
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v3[0]), 4, 0, 1)
}
func sub_4D7480(a1p *server.Object) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 int32
		v2 int32
		v3 *float2
	)
	if a1 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 316))))
		if v2 != 0 {
			v3 = *(**float2)(unsafe.Pointer(uintptr(v2 + 700)))
			nox_xxx_playerLeaveObserver_0_4E6AA0((*server.Player)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276)))))))
			nox_xxx_playerCameraUnlock_4E6040((*server.Object)(unsafe.Pointer(uintptr(a1))))
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 316))) = 0
			nox_xxx_unitMove_4E7010((*server.Object)(unsafe.Pointer(uintptr(a1))), (*float2)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float2{})*10)))
			nox_xxx_aud_501960(312, (*server.Object)(unsafe.Pointer(uintptr(a1))), 2, int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 36)))))
			nox_xxx_netSendPointFx_522FF0(-127, (*float2)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float2{})*10)))
		}
	}
}
func sub_4D7520(a1 int32) int8 {
	var (
		v1 int32
		i  int32
		v3 int32
		v4 int32
		v5 int32
	)
	*((*uint8)(unsafe.Pointer(&v1))) = *memmap.PtrUint8(0x5D4594, 1556120)
	if *memmap.PtrUint32(0x5D4594, 1556120) != 1 {
		*memmap.PtrUint32(0x5D4594, 1556120) = uint32(a1)
		return int8(v1)
	}
	if a1 != 0 {
		*memmap.PtrUint32(0x5D4594, 1556120) = uint32(a1)
		return int8(v1)
	}
	for i = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i))))))) {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 748))))
		if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 4792))) != 0 && *(*uint32)(unsafe.Pointer(uintptr(v3 + 316))) != 0 {
			sub_4D7480((*server.Object)(unsafe.Pointer(uintptr(i))))
		}
	}
	v1 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	v4 = v1
	if v1 == 0 {
		*memmap.PtrUint32(0x5D4594, 1556120) = uint32(a1)
		return int8(v1)
	}
	for {
		v5 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(v4)))))))
		*((*uint8)(unsafe.Pointer(&v1))) = *(*uint8)(unsafe.Pointer(uintptr(v4 + 8)))
		if v1&0x20 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 12))))&2 != 0 {
			*((*uint8)(unsafe.Pointer(&v1))) = uint8(int8(nox_xxx_objectSetOff_4E7600((*server.Object)(unsafe.Pointer(uintptr(v4))))))
		}
		v4 = v5
		if v5 == 0 {
			break
		}
	}
	*memmap.PtrUint32(0x5D4594, 1556120) = 0
	return int8(v1)
}
func sub_4D75E0() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1556120))
}
func sub_4D75F0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1556108) = uint32(a1)
	return result
}
func nox_server_checkWarpGate_4D7600() {
	var exp int32 = nox_xxx_player_4E3CE0()
	if exp == 0 {
		return
	}
	if (gameFrame() - *memmap.PtrUint32(0x5D4594, 1556108)) < 30 {
		return
	}
	var inGate int32 = 0
	for unit := unsafe.Pointer(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())); unit != nil; unit = unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unit))) {
		var v3 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(int32(uintptr(unit)) + 748))))
		if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 4792))) != 0 && *(*uint32)(unsafe.Pointer(uintptr(v3 + 316))) != 0 {
			inGate++
		}
	}
	if exp != inGate {
		return
	}
	if !nox_server_questMaybeWarp_4E8F60() {
		for unit := unsafe.Pointer(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())); unit != nil; unit = unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unit))) {
			var v5 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(int32(uintptr(unit)) + 748))))
			if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 4792))) != 0 && *(*uint32)(unsafe.Pointer(uintptr(v5 + 316))) != 0 {
				sub_4D7480((*server.Object)(unit))
				if exp <= 1 {
					nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(unit), internCStr("Gauntlet.c:WarpRestrictedSolo"), 0)
				} else {
					nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(unit), internCStr("Gauntlet.c:WarpRestrictedMulti"), 0)
				}
			}
		}
	}
}
func sub_4D76E0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1556124) = uint32(a1)
	return result
}
func sub_4D76F0() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1556124))
}
func sub_4D79A0(a1 int8) int32 {
	var result int32
	result = ^(1 << int32(a1))
	*memmap.PtrUint32(0x5D4594, 1556300) &= uint32(result)
	return result
}
func sub_4D79C0(a1p *server.Object) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1     int32
		result int32
		v3     int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	sub_4D9D20(math.MaxUint8, (*server.Object)(unsafe.Pointer(uintptr(a1))))
	sub_4D6000((*server.Object)(unsafe.Pointer(uintptr(a1))))
	for result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); result != 0; result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(result))))))) {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(result + 748))))
		*(*uint8)(unsafe.Pointer(uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 2064)))) + v3 + 452))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(v3 + int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 2064))))*4 + 324))) = 0
		*(*uint8)(unsafe.Pointer(uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 2064)))) + v3 + 484))) = 0
		*(*uint8)(unsafe.Pointer(uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 2064)))) + v3 + 516))) = 0
	}
	return result
}
func sub_4D7A60(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1556172) = gameFrame()
	return result
}
func sub_4D7A80() int32 {
	var (
		v0     *uint8
		v1     int32
		v2     int32
		v3     *byte
		v4     int32
		v5     int32
		v6     int32
		result int32
	)
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 1556172))
	v1 = int32(324 - uint32(uintptr(memmap.PtrOff(0x5D4594, 1556172))))
	v2 = 484
	for {
		v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(v2 - 484)))
		if v3 != nil && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*523))) != 0 && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*514))) != 0 && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1198))) == 1 {
			*(*uint32)(unsafe.Pointer(v0)) = 0
		} else if *(*uint32)(unsafe.Pointer(v0)) != 0 && gameFrame()-*(*uint32)(unsafe.Pointer(v0)) > (gameFPS()*30) {
			v4 = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
			if v4 != 0 {
				v5 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v0), v1)))))
				for {
					v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 748))))
					*(*uint8)(unsafe.Pointer(uintptr(v2 + v6 - 32))) = 0
					*(*uint32)(unsafe.Pointer(uintptr(v5 + v6))) = 0
					*(*uint8)(unsafe.Pointer(uintptr(v2 + v6))) = 0
					*(*uint8)(unsafe.Pointer(uintptr(v2 + v6 + 32))) = 0
					v4 = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(v4)))))))
					if v4 == 0 {
						break
					}
				}
				v1 = int32(324 - uint32(uintptr(memmap.PtrOff(0x5D4594, 1556172))))
			}
			*(*uint32)(unsafe.Pointer(v0)) = 0
		}
		v2++
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 4))
		result = v2 - 484
		if v2-484 >= 32 {
			break
		}
	}
	return result
}
func sub_4D7B40() int32 {
	var result int32
	result = 0
	libc.MemSet(memmap.PtrOff(0x5D4594, 1556172), 0, 0x80)
	return result
}
func sub_4D7B60(a1 int32) int32 {
	var (
		result int32
		i      int32
		v3     [7]byte
	)
	v3[0] = 210
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a1)))))
	*(*uint16)(unsafe.Pointer(&v3[3])) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))
	v3[5] = 1
	v3[6] = 2
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 276))) + 2064)))), unsafe.Pointer(&v3[0]), 7, 0, 1)
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func nox_xxx_netSendInterestingId_4D7BE0(a1 int32) int32 {
	var (
		result int32
		i      int32
		v3     [7]byte
	)
	v3[0] = 210
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a1)))))
	*(*uint16)(unsafe.Pointer(&v3[3])) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))
	v3[5] = 2
	v3[6] = 2
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 276))) + 2064)))), unsafe.Pointer(&v3[0]), 7, 0, 1)
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func sub_4D7C60() int32 {
	var (
		result int32
		v1     float32
		v2     float32
	)
	dword_5d4594_1556316 = 0
	*mem_getFloatPtr(0x5D4594, 1556308) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("CamperRadiusSq")))
	v1 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("CamperStartTime")))
	*memmap.PtrUint32(0x5D4594, 1556312) = uint32(int32(v1))
	v2 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("CamperFadeTime")))
	result = int32(v2)
	*memmap.PtrUint32(0x5D4594, 1556304) = uint32(result)
	return result
}
func sub_4D7CC0() int32 {
	var (
		result int32
		i      int32
		v2     int32
		v3     float64
		v4     float64
		j      int32
		v6     *uint32
		v7     int32
	)
	nox_platform_get_ticks()
	result = sub_409F40(0x2000)
	if result != 0 {
		if (gameFrame() - dword_5d4594_1556316) > uint32(*memmap.PtrInt32(0x5D4594, 1556312)) {
			for i = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i))))))) {
				if (*(*uint32)(unsafe.Pointer(uintptr(i + 16))) & 0x8020) == 0 {
					v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 748))))
					if (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 3680)))) & 1) == 0 {
						v3 = float64(*(*float32)(unsafe.Pointer(uintptr(i + 60))) - *(*float32)(unsafe.Pointer(uintptr(v2 + 252))))
						v4 = float64(*(*float32)(unsafe.Pointer(uintptr(i + 56))) - *(*float32)(unsafe.Pointer(uintptr(v2 + 248))))
						if v4*v4+v3*v3 < float64(*mem_getFloatPtr(0x5D4594, 1556308)) {
							*(*uint32)(unsafe.Pointer(uintptr(v2 + 256))) = gameFrame()
						}
						*(*uint32)(unsafe.Pointer(uintptr(v2 + 248))) = *(*uint32)(unsafe.Pointer(uintptr(i + 56)))
						*(*uint32)(unsafe.Pointer(uintptr(v2 + 252))) = *(*uint32)(unsafe.Pointer(uintptr(i + 60)))
					}
				}
			}
			dword_5d4594_1556316 = gameFrame()
		}
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
		for j = result; result != 0; j = result {
			if (*(*uint32)(unsafe.Pointer(uintptr(j + 16))) & 0x8020) == 0 {
				v6 = *(**uint32)(unsafe.Pointer(uintptr(j + 748)))
				if (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*69)) + 3680)))) & 1) == 0 {
					v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*65)))
					if (dword_5d4594_1556316 - *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*64))) > uint32(*memmap.PtrInt32(0x5D4594, 1556304)) {
						if v7 != 0 {
							nox_xxx_netSendInterestingId_4D7BE0(j)
							*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*65)) = 0
						}
					} else if v7 == 0 {
						if !noxflags.HasGame(32) || int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*69)) + 4))))&1 != 0 {
							nox_xxx_aud_501960(774, (*server.Object)(unsafe.Pointer(uintptr(j))), 0, 0)
						}
						sub_4D7B60(j)
						*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*65)) = 1
					}
				}
			}
			result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(j)))))))
		}
	}
	return result
}
func sub_4D7E50(a1p *server.Object) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result int32
		v2     *uint32
	)
	result = a1
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		v2 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 748)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*62)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*63)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*64)) = gameFrame()
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*65)) != 0 {
			result = nox_xxx_netSendInterestingId_4D7BE0(a1)
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*65)) = 0
	}
	return result
}
func sub_4D7EA0() int32 {
	var (
		result int32
		i      int32
	)
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		sub_4D7E50((*server.Object)(unsafe.Pointer(uintptr(i))))
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func nox_xxx_netCreatureCmd_4D7EE0(player int32, orderType int8) int32 {
	var buf [2]byte
	buf[0] = 237
	buf[1] = byte(orderType)
	return nox_xxx_netSendPacket1_4E5390(player, int32(uintptr(unsafe.Pointer(&buf[0]))), 2, 0, 1)
}
func nox_xxx_netNotifyRate_4D7F10(a1 int32) int32 {
	var v2 [2]byte
	v2[0] = 236
	v2[1] = byte(int8(nox_xxx_rateGet_40A6C0()))
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v2[0]))), 2, 0, 1)
}
func nox_xxx_netReportObjectPoison_4D7F40(a1 int32, a2 *uint32, a3 int8) int32 {
	var v3 int32
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	*((*uint8)(unsafe.Pointer(&a1))) = 218
	*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a1))), 1)))) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&a1))), 4-1)) = uint8(a3)
	return nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2064)))), unsafe.Pointer(&a1), 4, 0, 1)
}
func sub_4D81A0(a1 int32) {
	var (
		v1 float64
		v2 int32
		v3 [5]byte
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		v1 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 28))))
		v3[0] = 110
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		*(*uint32)(unsafe.Pointer(&v3[1])) = uint32(int32(int64(v1)))
		nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))), unsafe.Pointer(&v3[0]), 5, 0, 1)
	}
}
func nox_xxx_netReportAnimFrame_4D81F0(a1 int32, a2 *uint32) int32 {
	var v3 [7]byte
	v3[0] = 107
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	*(*uint32)(unsafe.Pointer(&v3[3])) = *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*33))
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v3[0]), 7, 0, 1)
}
func nox_xxx_netReportXStatus_4D8230(a1 int32, a2 *uint32) int32 {
	var v3 [7]byte
	v3[0] = 101
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	*(*uint32)(unsafe.Pointer(&v3[3])) = *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*5))
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v3[0]), 7, 0, 1)
}
func nox_xxx_netReportPlrStatus_4D8270(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		v4 [5]byte
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v4[0] = 102
	*(*uint32)(unsafe.Pointer(&v4[1])) = uint32(v1)
	return nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))), unsafe.Pointer(&v4[0]), 5, 0, 1)
}
func nox_xxx_netReportCharges_4D82B0(a1 int32, item *server.Object, a3 int8, a4 int8) int32 {
	var v5 [5]byte
	v5[0] = 100
	*(*uint16)(unsafe.Pointer(&v5[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(item))
	v5[3] = byte(a3)
	v5[4] = byte(a4)
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v5[0]))), 5, 0, 0)
}
func sub_4D82F0(a1 int32, a2 *uint32) *uint32 {
	var (
		result *uint32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     *uint32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    *uint32
		v15    int32
		v16    int32
		v17    int32
		v18    int32
		v19    [11]byte
	)
	result = a2
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*2)))
	v4 = 0
	if uint32(v3)&0x11001000 != 0 {
		v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*173)))
		v6 = 4
		v7 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*173)))))
		for {
			if *v7 != 0 {
				v4 = 1
			}
			v7 = (*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
			v6--
			if v6 == 0 {
				break
			}
		}
		if v4 != 0 {
			v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*123)))
			v19[0] = 81
			*(*uint16)(unsafe.Pointer(&v19[1])) = *(*uint16)(unsafe.Pointer(uintptr(v8 + 36)))
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v8 + 8))))&4 != 0 {
				v19[2] |= 0x80
			}
			*(*uint32)(unsafe.Pointer(&v19[3])) = uint32(nox_xxx_weaponInventoryEquipFlags_415820((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2))))))))
			v9 = 0
			v10 = v5
			for {
				if *(*uint32)(unsafe.Pointer(uintptr(v10))) != 0 {
					v19[v9+7] = byte(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v10))) + 4))))
				} else {
					v19[v9+7] = math.MaxUint8
				}
				v9++
				v10 += 4
				if v9 >= 4 {
					break
				}
			}
			result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v19[0]))), 11, 0, 0))))
		} else {
			v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*123)))
			v19[0] = 80
			*(*uint16)(unsafe.Pointer(&v19[1])) = *(*uint16)(unsafe.Pointer(uintptr(v11 + 36)))
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v11 + 8))))&4 != 0 {
				v19[2] |= 0x80
			}
			*(*uint32)(unsafe.Pointer(&v19[3])) = uint32(nox_xxx_weaponInventoryEquipFlags_415820((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2))))))))
			result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v19[0]))), 7, 0, 0))))
		}
	} else if uint32(v3)&0x2000000 != 0 {
		v12 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*173)))
		v13 = 4
		v14 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*173)))))
		for {
			if *v14 != 0 {
				v4 = 1
			}
			v14 = (*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*1))
			v13--
			if v13 == 0 {
				break
			}
		}
		if v4 != 0 {
			v15 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*123)))
			v19[0] = 82
			*(*uint16)(unsafe.Pointer(&v19[1])) = *(*uint16)(unsafe.Pointer(uintptr(v15 + 36)))
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v15 + 8))))&4 != 0 {
				v19[2] |= 0x80
			}
			*(*uint32)(unsafe.Pointer(&v19[3])) = uint32(nox_xxx_unitArmorInventoryEquipFlags_415C70((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2))))))))
			v16 = 0
			v17 = v12
			for {
				if *(*uint32)(unsafe.Pointer(uintptr(v17))) != 0 {
					v19[v16+7] = byte(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v17))) + 4))))
				} else {
					v19[v16+7] = math.MaxUint8
				}
				v16++
				v17 += 4
				if v16 >= 4 {
					break
				}
			}
			result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v19[0]))), 11, 0, 0))))
		} else {
			v18 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*123)))
			v19[0] = 79
			*(*uint16)(unsafe.Pointer(&v19[1])) = *(*uint16)(unsafe.Pointer(uintptr(v18 + 36)))
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v18 + 8))))&4 != 0 {
				v19[2] |= 0x80
			}
			*(*uint32)(unsafe.Pointer(&v19[3])) = uint32(nox_xxx_unitArmorInventoryEquipFlags_415C70((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2))))))))
			result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v19[0]))), 7, 0, 0))))
		}
	}
	return result
}
func nox_xxx_netReportDequip_4D84C0(a1 int32, object *server.Object) int32 {
	var (
		result int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     [7]byte
	)
	result = int32(uintptr(unsafe.Pointer(object)))
	v3 = int32(object.ObjClass)
	if uint32(v3)&0x11001000 != 0 {
		v4 = int32(uintptr(unsafe.Pointer(object.InvHolder)))
		v7[0] = 84
		*(*uint16)(unsafe.Pointer(&v7[1])) = *(*uint16)(unsafe.Pointer(uintptr(v4 + 36)))
		v5 = nox_xxx_weaponInventoryEquipFlags_415820(object)
	} else {
		if (uint32(v3) & 0x2000000) == 0 {
			return result
		}
		v6 = int32(uintptr(unsafe.Pointer(object.InvHolder)))
		v7[0] = 83
		*(*uint16)(unsafe.Pointer(&v7[1])) = *(*uint16)(unsafe.Pointer(uintptr(v6 + 36)))
		v5 = nox_xxx_unitArmorInventoryEquipFlags_415C70(object)
	}
	*(*uint32)(unsafe.Pointer(&v7[3])) = uint32(v5)
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v7[0]))), 7, 0, 0)
}
func nox_xxx_netReportEquip_4D8540(a1 int32, a2 *uint32, a3 int32) *uint32 {
	var (
		result *uint32
		v4     [3]byte
	)
	v4[0] = 96
	*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v4[0]))), 3, 0, 0)
	result = (*uint32)(unsafe.Pointer(uintptr(a3)))
	if a3 != 0 {
		result = sub_4D82F0(math.MaxUint8, a2)
	}
	return result
}
func nox_xxx_netReportDequip_4D8590(a1 int32, object *server.Object) int32 {
	var (
		a2 *uint32 = (*uint32)(unsafe.Pointer(object))
		v4 [3]byte
	)
	v4[0] = 97
	*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v4[0]))), 3, 0, 0)
}
func nox_xxx_netReportTotalHealth_4D85C0(a1 int32, a2 *uint32) int32 {
	var (
		result int32
		v3     *uint16
		v4     [7]byte
	)
	result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*139)))
	if result != 0 {
		v4[0] = 221
		*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
		v3 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*139)))))
		*(*uint16)(unsafe.Pointer(&v4[3])) = *v3
		*(*uint16)(unsafe.Pointer(&v4[5])) = *(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*2))
		result = nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v4[0]))), 7, 0, 1)
	}
	return result
}
func nox_xxx_netReportUnitCurrentHP_4D8620(a1 int32, a2 *uint32) int32 {
	var (
		v2     *uint32
		result int32
		v4     uint32
		v5     *uint32
	)
	v2 = a2
	result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*139)))
	if result != 0 {
		v5 = a2
		*((*uint8)(unsafe.Pointer(&a2))) = 65
		*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a2))), 1)))) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(v5))))
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v4))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*139)))))
		*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&a2))), unsafe.Sizeof((*uint32)(nil))-1)) = uint8(v4 >> 1)
		result = nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&a2))), 4, 0, 1)
	}
	return result
}
func nox_xxx_netSendTeam_4D8670(a1 int32, a2 *uint32) int32 {
	var (
		result int32
		v3     int16
		v4     *uint16
		v5     [5]byte
	)
	result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*139)))
	if result != 0 {
		v5[0] = 196
		v5[1] = 12
		v3 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2)))))
		v4 = (*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*139)))))
		*(*uint16)(unsafe.Pointer(&v5[2])) = uint16(v3)
		v5[4] = byte(int8(int32(*v4) * 100 / int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*2)))))
		result = nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v5[0]))), 5, 0, 1)
	}
	return result
}
func nox_xxx_netSendPlrHealthToTeam_4D86E0(a1 int32) *byte {
	var (
		v1     int32
		result *byte
		v3     *byte
	)
	v1 = a1
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(a1)))
	v3 = result
	if result != nil {
		result = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(result))), 4*514))))))
		if result != nil {
			if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(result))), 4*139))) != 0 {
				*((*uint8)(unsafe.Pointer(&a1))) = 67
				*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a1))), 1)))) = **(**uint16)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*514))) + 556)))
				nox_xxx_netSendPacket1_4E5390(v1, int32(uintptr(unsafe.Pointer(&a1))), 3, 0, 1)
				result = (*byte)(unsafe.Pointer(uintptr(bool2int32(noxflags.HasGame(4096)))))
				if result != nil {
					result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_netSendTeam_4D8670(v1|0x80, *((**uint32)(unsafe.Add(unsafe.Pointer((**uint32)(unsafe.Pointer(v3))), unsafe.Sizeof((*uint32)(nil))*514)))))))
				}
			}
		}
	}
	return result
}
func nox_xxx_netReportHealthDelta_4D8760(a1 int32, a2 int16, a3 int16) int16 {
	var (
		result int16
		v4     [5]byte
	)
	result = a3
	if int32(a3) < 0 {
		*(*uint16)(unsafe.Pointer(&v4[3])) = uint16(a3)
		v4[0] = 66
		*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(a2)
		result = int16(nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v4[0]), 5, 0, 1))
	}
	return result
}
func nox_xxx_itemReportHealth_4D87A0(a1 int32, item *server.Object) int32 {
	var (
		result int32
		v3     *uint16
		v4     [7]byte
	)
	result = int32(uintptr(unsafe.Pointer(item.HealthData)))
	if result != 0 {
		if int32(*(*uint16)(unsafe.Pointer(uintptr(result + 4)))) != 0 {
			v4[0] = 68
			*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(item))
			v3 = (*uint16)(unsafe.Pointer(item.HealthData))
			*(*uint16)(unsafe.Pointer(&v4[3])) = *(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*0))
			*(*uint16)(unsafe.Pointer(&v4[5])) = *(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*2))
			result = nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v4[0]))), 7, 0, 0)
		}
	}
	return result
}
func nox_xxx_netReportStamina_4D8800(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     int32
	)
	result = a2
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
		*((*uint8)(unsafe.Pointer(&a2))) = 71
		*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&a2))), 1)) = *(*uint8)(unsafe.Pointer(uintptr(v3 + 91)))
		result = nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&a2))), 2, 0, 1)
	}
	return result
}
func sub_4D8840(a1 int32, a2 int32) int32 {
	var (
		v3 int8
		v5 int16
	)
	v3 = int8(*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))))
	*((*uint8)(unsafe.Pointer(&v5))) = 91
	*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v5))), unsafe.Sizeof(int16(0))-1)) = uint8(v3)
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v5), 2, 0, 1)
}
func sub_4D8870(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     int32
		v4     [5]byte
	)
	result = a2
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
		v4[0] = 74
		*(*uint32)(unsafe.Pointer(&v4[1])) = *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2164)))
		result = nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v4[0]), 5, 0, 1)
	}
	return result
}
func nox_xxx_netReportTotalMana_4D88C0(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     int32
		v4     [7]byte
	)
	result = a2
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 && (v3 == 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2251)))) != 0) {
		v4[0] = 222
		*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a2)))))
		*(*uint16)(unsafe.Pointer(&v4[3])) = *(*uint16)(unsafe.Pointer(uintptr(v3 + 4)))
		*(*uint16)(unsafe.Pointer(&v4[5])) = *(*uint16)(unsafe.Pointer(uintptr(v3 + 8)))
		result = sub_4E5450(a1, &v4[0], 7, 0, 1)
	}
	return result
}
func nox_xxx_netReportMana_4D8930(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     int32
		v4     [5]byte
	)
	result = a2
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 && (v3 == 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2251)))) != 0) {
		v4[0] = 69
		*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a2)))))
		*(*uint16)(unsafe.Pointer(&v4[3])) = *(*uint16)(unsafe.Pointer(uintptr(v3 + 4)))
		result = sub_4E5450(a1, &v4[0], 5, 0, 1)
	}
	return result
}
func nox_xxx_servSendStats_4D8990(a1 int32, a2 int32, a3 int8) int8 {
	var (
		result int8
		v4     int32
		v5     int16
		v6     int32
		v7     int16
		v8     [14]byte
	)
	result = int8(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	if int32(result)&4 != 0 {
		v8[0] = 72
		v5 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a2))))))
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 556))))
		*(*uint16)(unsafe.Pointer(&v8[1])) = uint16(v5)
		*(*uint16)(unsafe.Pointer(&v8[5])) = *(*uint16)(unsafe.Pointer(uintptr(v4 + 8)))
		v7 = int16(*(*uint16)(unsafe.Pointer(uintptr(a2 + 490))))
		*(*uint16)(unsafe.Pointer(&v8[3])) = *(*uint16)(unsafe.Pointer(uintptr(v6 + 4)))
		*(*uint16)(unsafe.Pointer(&v8[7])) = uint16(v7)
		*(*uint16)(unsafe.Pointer(&v8[9])) = *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2235)))
		*(*uint16)(unsafe.Pointer(&v8[11])) = *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2239)))
		v8[13] = byte(a3)
		result = int8(nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v8[0]), 14, 0, 1))
	}
	return result
}
func nox_xxx_netReportArmorVal_4D8A30(a1 int32, a2 int32) int32 {
	var v3 [5]byte
	v3[0] = 73
	*(*uint32)(unsafe.Pointer(&v3[1])) = uint32(a2)
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v3[0]), 5, 0, 1)
}
func nox_xxx_netReportPickup_4D8A60(a1 int32, item *server.Object) int32 {
	var (
		v3 int16
		v4 int16
		v5 [5]byte
	)
	if item.ObjClass&0x13001000 != 0 {
		return nox_xxx_netReportModifiablePickup_4D8AD0(a1, item)
	}
	v5[0] = 75
	v3 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0(item)))
	v4 = int16(item.TypeInd)
	*(*uint16)(unsafe.Pointer(&v5[1])) = uint16(v3)
	*(*uint16)(unsafe.Pointer(&v5[3])) = uint16(v4)
	nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v5[0]))), 5, 0, 0)
	return nox_xxx_itemReportHealth_4D87A0(a1, item)
}
func nox_xxx_netReportModifiablePickup_4D8AD0(a1 int32, item *server.Object) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		v6 [9]byte
	)
	v6[0] = 76
	v2 = int32(uintptr(item.InitData))
	*(*uint16)(unsafe.Pointer(&v6[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(item))
	*(*uint16)(unsafe.Pointer(&v6[3])) = item.TypeInd
	v3 = 0
	v4 = v2
	for {
		if *(*uint32)(unsafe.Pointer(uintptr(v4))) != 0 {
			v6[v3+5] = byte(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4))) + 4))))
		} else {
			v6[v3+5] = math.MaxUint8
		}
		v3++
		v4 += 4
		if v3 >= 4 {
			break
		}
	}
	nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v6[0]))), 9, 0, 0)
	return nox_xxx_itemReportHealth_4D87A0(a1, item)
}
func nox_xxx_netReportDrop_4D8B50(a1 int32, object *server.Object) int32 {
	var (
		a2 int32 = int32(uintptr(unsafe.Pointer(object)))
		v3 [5]byte
	)
	v3[0] = 77
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a2)))))
	*(*uint16)(unsafe.Pointer(&v3[3])) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v3[0]))), 5, 0, 0)
}
func nox_xxx_netSendDMWinner_4D8B90(a1 int32, a2 int8) int32 {
	var (
		result int32
		v3     [8]byte
	)
	result = a1
	if a1 != 0 {
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8)))) & 4) == 0 {
			return result
		}
		v3[0] = 88
		*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a1)))))
	} else {
		v3[0] = 88
		*(*uint16)(unsafe.Pointer(&v3[1])) = 0
	}
	v3[3] = byte(a2)
	*(*uint32)(unsafe.Pointer(&v3[4])) = gameFrame()
	return nox_xxx_netSendPacket1_4E5390(math.MaxUint8, int32(uintptr(unsafe.Pointer(&v3[0]))), 8, 0, 1)
}
func nox_xxx_netSendDMTeamWinner_4D8BF0(a1 int32, a2 int8) int32 {
	var v3 [8]byte
	v3[0] = 89
	if a1 != 0 {
		*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(*(*uint8)(unsafe.Pointer(uintptr(a1 + 57))))
	} else {
		*(*uint16)(unsafe.Pointer(&v3[1])) = 0
	}
	v3[3] = byte(a2)
	*(*uint32)(unsafe.Pointer(&v3[4])) = gameFrame()
	return nox_xxx_netSendPacket1_4E5390(math.MaxUint8, int32(uintptr(unsafe.Pointer(&v3[0]))), 8, 0, 1)
}
func nox_xxx_netFlagballWinner_4D8C40(a1 int32) int32 {
	var (
		v1 int16
		v3 [8]byte
	)
	v1 = int16(*(*uint8)(unsafe.Pointer(uintptr(a1 + 57))))
	v3[0] = 86
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(v1)
	v3[3] = 0
	*(*uint32)(unsafe.Pointer(&v3[4])) = gameFrame()
	return nox_xxx_netSendPacket1_4E5390(math.MaxUint8, int32(uintptr(unsafe.Pointer(&v3[0]))), 8, 0, 1)
}
func nox_xxx_netFlagWinner_4D8C40_4D8C80(a1 int32, a2 int8) int32 {
	var v3 [8]byte
	v3[0] = 87
	if a1 != 0 {
		*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(*(*uint8)(unsafe.Pointer(uintptr(a1 + 57))))
	} else {
		*(*uint16)(unsafe.Pointer(&v3[1])) = math.MaxUint16
	}
	v3[3] = byte(a2)
	*(*uint32)(unsafe.Pointer(&v3[4])) = gameFrame()
	return nox_xxx_netSendPacket1_4E5390(math.MaxUint8, int32(uintptr(unsafe.Pointer(&v3[0]))), 8, 0, 1)
}
func nox_xxx_scavengerHuntReport_4D8CD0(a1 int32) int32 {
	var (
		result int32
		v2     int32
		v3     [7]byte
	)
	result = a1
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		v3[0] = 85
		*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a1)))))
		*(*uint16)(unsafe.Pointer(&v3[3])) = *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2152)))
		*(*uint16)(unsafe.Pointer(&v3[5])) = *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2156)))
		result = nox_xxx_netSendPacket0_4E5420(math.MaxUint8, unsafe.Pointer(&v3[0]), 7, 0, 1)
	}
	return result
}
func nox_xxx_playerIncrementElimDeath_4D8D40(a1 int32) {
	var (
		result *byte
		i      *byte
		v3     *byte
		v4     float64
		v5     int32
		v6     int32
		v7     float32
		v8     *uint8
		v9     int32
	)
	result = (*byte)(unsafe.Pointer(uintptr(a1)))
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))) + 2140)))++
		result = (*byte)(unsafe.Pointer(uintptr(bool2int32(noxflags.HasGame(1024)))))
		if result != nil {
			if sub_40AA00() != 0 && sub_40AA20() == 0 {
				for i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); i != nil; i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(i))))))))) {
					if *(*byte)(unsafe.Add(unsafe.Pointer(i), 3680))&1 != 0 {
						nox_xxx_netNeedTimestampStatus_4174F0((*server.Player)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(i)))))), 256)
					}
				}
				sub_40AA30(1)
			}
			result = (*byte)(unsafe.Pointer(uintptr(bool2int32(noxflags.HasGame(0x4000000)))))
			if result == nil {
				result = (*byte)(unsafe.Pointer(uintptr(sub_40A300())))
				if result == nil {
					result = (*byte)(unsafe.Pointer(uintptr(sub_40AA00())))
					if result != nil {
						if !nox_xxx_CheckGameplayFlags_417DA0(4) {
							v5 = sub_40A770()
							result = (*byte)(unsafe.Pointer(uintptr(sub_40AA40())))
							if v5 >= int32(uintptr(unsafe.Pointer(result))) {
								return
							}
							v8 = (*uint8)(memmap.PtrOff(0x587000, 198928))
							v4 = nox_xxx_gamedataGetFloat_419D40(internCStr("SuddenDeathCountdown"))
							v7 = float32(v4)
							v6 = int32(v7)
							nox_xxx_servStartCountdown_40A2A0(v6, (*byte)(unsafe.Pointer(v8)))
							return
						}
						v9 = int32(nox_xxx_getTeamCounter_417DD0())
						result = (*byte)(unsafe.Pointer(uintptr(sub_40AA40())))
						if v9 < int32(uintptr(unsafe.Pointer(result))) {
							result = (*byte)(unsafe.Pointer(nox_server_teamFirst_418B10()))
							v3 = result
							if result != nil {
								for nox_xxx_countNonEliminatedPlayersInTeam_40A830((*nox_team_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3))))))) != 1 {
									result = (*byte)(unsafe.Pointer(nox_server_teamNext_418B60((*nox_team_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))))))
									v3 = result
									if result == nil {
										return
									}
								}
								v8 = (*uint8)(memmap.PtrOff(0x587000, 198872))
								v4 = nox_xxx_gamedataGetFloat_419D40(internCStr("SuddenDeathCountdown"))
								v7 = float32(v4)
								v6 = int32(v7)
								nox_xxx_servStartCountdown_40A2A0(v6, (*byte)(unsafe.Pointer(v8)))
								return
							}
						}
					}
				}
			}
		}
	}
}
func nox_xxx_changeScore_4D8E90(a1 int32, a2 int32) int32 {
	var result int32
	result = a1
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))))
		*(*uint32)(unsafe.Pointer(uintptr(result + 2136))) += uint32(a2)
	}
	return result
}
func nox_xxx_playerSubLessons_4D8EC0(a1 int32, a2 int32) int32 {
	var result int32
	result = a1
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))))
		*(*uint32)(unsafe.Pointer(uintptr(result + 2136))) -= uint32(a2)
	}
	return result
}
func nox_xxx_netReportLesson_4D8EF0(a1p *server.Object) int32 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 int32
		v3 [11]byte
	)
	v3[0] = 78
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	*(*uint16)(unsafe.Pointer(&v3[1])) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 36)))
	*(*uint32)(unsafe.Pointer(&v3[3])) = *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 2136)))
	*(*uint32)(unsafe.Pointer(&v3[7])) = *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 2140)))
	return nox_xxx_netSendPacket1_4E5390(math.MaxUint8, int32(uintptr(unsafe.Pointer(&v3[0]))), 11, 0, 1)
}
func nox_xxx_netTimerStatus_4D8F50(a1 int32, a2 int32) int32 {
	var v3 [13]byte
	v3[0] = 211
	*(*uint32)(unsafe.Pointer(&v3[1])) = uint32(a2)
	*(*uint32)(unsafe.Pointer(&v3[5])) = uint32(sub_40A230())
	*(*uint32)(unsafe.Pointer(&v3[9])) = gameFrame()
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v3[0]))), 13, 0, 1)
}
func nox_xxx_netReportEnchant_4D8F90(a1 int32, a2 *uint32) int32 {
	var v3 [7]byte
	v3[0] = 90
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	*(*uint32)(unsafe.Pointer(&v3[3])) = *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*85))
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v3[0]))), 7, 0, 1)
}
func nox_xxx_netReportObjHidden_4D8FD0(a1 int32, a2 *uint32) {
	var v2 *uint32
	v2 = a2
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*2))&0x800000 != 0 {
		*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a2))), 1)))) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
		*((*uint8)(unsafe.Pointer(&a2))) = uint8(int8(56 - bool2int32((*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4))&0x1000000) != 0)))
		nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&a2), 3, 0, 1)
	}
}
func nox_xxx_netReportUnitHeight_4D9020(a1 int32, a2p *server.Object) int32 {
	var (
		a2     int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v2     int32
		v3     int16
		v4     float64
		v5     int64
		v6     float64
		v7     int64
		v8     float64
		result int32
		v10    int16
		v11    float64
		v12    int16
		v13    float64
		v14    *uint32
		v15    [6]byte
	)
	v2 = a2
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 20))))&0x20 != 0 {
		v3 = int16(*(*uint16)(unsafe.Pointer(uintptr(a2 + 36))))
		v15[0] = 159
		v4 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 104))))
		*(*uint16)(unsafe.Pointer(&v15[1])) = uint16(v3)
		v5 = int64(v4)
		v6 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 108))))
		v15[3] = byte(int8(v5))
		v7 = int64(v6)
		v8 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 116))))
		v15[4] = byte(int8(v7))
		v15[5] = byte(int8(int64(v8)))
		result = nox_netlist_addToMsgListCli_40EBC0(a1, 1, (*uint8)(unsafe.Pointer(&v15[0])), 6)
	} else {
		v14 = (*uint32)(unsafe.Pointer(uintptr(a2)))
		if float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 104)))) < 0.0 {
			*((*uint8)(unsafe.Pointer(&a2))) = 95
			v12 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(v14)))))
			v13 = float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 104))))
			*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a2))), 1)))) = uint16(v12)
			v11 = -v13
		} else {
			*((*uint8)(unsafe.Pointer(&a2))) = 94
			v10 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(v14)))))
			v11 = float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 104))))
			*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a2))), 1)))) = uint16(v10)
		}
		*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&a2))), 4-1)) = uint8(int8(int64(v11)))
		result = nox_netlist_addToMsgListCli_40EBC0(a1, 1, (*uint8)(unsafe.Pointer(&a2)), 4)
	}
	return result
}
func sub_4D90E0(a1 int32, a2 int8) int32 {
	var v3 [2]byte
	v3[0] = 151
	v3[1] = byte(a2)
	return nox_netlist_addToMsgListCli_40EBC0(a1, 1, (*uint8)(unsafe.Pointer(&v3[0])), 2)
}
func nox_xxx_earthquakeSend_4D9110(a1 *float32, a2 int32) int32 {
	var (
		result int32
		i      int32
		v4     int32
		v5     float64
		v6     float64
		v7     float64
	)
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 276))))
		v5 = float64(*a1 - *(*float32)(unsafe.Pointer(uintptr(v4 + 3632))))
		v6 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1)) - *(*float32)(unsafe.Pointer(uintptr(v4 + 3636))))
		v7 = v6*v6 + v5*v5
		if v7 < 90000.0 {
			sub_4D90E0(int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 2064)))), int8(int64((1.0-v7*1.1111111e-05)*float64(a2))))
		}
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func nox_xxx_netReportAcquireCreature_4D91A0(a1 int32, a2p *server.Object) int32 {
	var (
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v3 [5]byte
	)
	v3[0] = 108
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a2)))))
	*(*uint16)(unsafe.Pointer(&v3[3])) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))
	if noxflags.HasGame(0x8000000) {
		v3[4] |= 0x80
	}
	nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v3[0]))), 5, 0, 1)
	return nox_xxx_netReportTotalHealth_4D85C0(a1, (*uint32)(unsafe.Pointer(uintptr(a2))))
}
func nox_xxx_netFxShield_0_4D9200(a1 int32, a2 int32) int32 {
	var v4 int32
	*((*uint8)(unsafe.Pointer(&v4))) = 109
	*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v4))), 1)))) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 36)))
	if noxflags.HasGame(0x8000000) {
		*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v4))), 2)) |= 0x80
	}
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v4))), 3, 0, 1)
}
func nox_xxx_netMonitorCreature_4D9250(a1 int32, a2 int32) int32 {
	var v3 [5]byte
	v3[0] = 219
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a2)))))
	*(*uint16)(unsafe.Pointer(&v3[3])) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))
	nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v3[0]))), 5, 0, 1)
	return nox_xxx_netReportTotalHealth_4D85C0(a1, (*uint32)(unsafe.Pointer(uintptr(a2))))
}
func nox_xxx_netSendUnMonitorCrea_4D92A0(a1 int32, a2 *uint32) int32 {
	var v4 [3]byte
	v4[0] = 220
	*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v4[0]))), 3, 0, 1)
}
func nox_xxx_netReportTeamBase_4D92D0(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     int32
		v4     int32
		v5     int32
		v6     [7]byte
	)
	result = int32(*memmap.PtrUint32(0x5D4594, 1556320))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 692))))
	if *memmap.PtrUint32(0x5D4594, 1556320) == 0 {
		result = nox_xxx_getNameId_4E3AA0(internCStr("TeamBase"))
		*memmap.PtrUint32(0x5D4594, 1556320) = uint32(result)
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a2 + 8)))&0x13001000 != 0 || int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))) == result {
		v6[0] = 103
		*(*uint16)(unsafe.Pointer(&v6[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a2)))))
		v4 = 0
		v5 = v3
		for {
			if *(*uint32)(unsafe.Pointer(uintptr(v5))) != 0 {
				v6[v4+3] = byte(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5))) + 4))))
			} else {
				v6[v4+3] = math.MaxUint8
			}
			v4++
			v5 += 4
			if v4 >= 4 {
				break
			}
		}
		result = nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v6[0]), 7, 0, 1)
	}
	return result
}
func nox_xxx_netReportStatsSpeed_4D9360(a1 int32, a2 *uint32, a3 int8, a4 int32) int32 {
	var v5 [8]byte
	v5[0] = 104
	*(*uint16)(unsafe.Pointer(&v5[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	v5[7] = byte(a3)
	*(*uint32)(unsafe.Pointer(&v5[3])) = uint32(a4)
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v5[0]), 8, 0, 1)
}
func nox_xxx_netSendReportNPC_4D93A0(a1 int32, a2 int32) *uint32 {
	var (
		v2 int32
		v3 *byte
		v4 int32
		v5 int32
		v6 int32
		v7 *byte
	)
	_ = v7
	var result *uint32
	var i *uint32
	var v10 [21]byte
	v10[0] = 105
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	*(*uint16)(unsafe.Pointer(&v10[1])) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 36)))
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 540)))) != 0 {
		v10[2] |= 0x80
	}
	v3 = &v10[3]
	v4 = v2 + 2076
	v5 = 6
	for {
		v6 = v4
		v7 = v3
		v4 += 3
		v3 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 3))
		v5--
		*(*uint16)(unsafe.Pointer(v7)) = *(*uint16)(unsafe.Pointer(uintptr(v6)))
		*(*byte)(unsafe.Add(unsafe.Pointer(v7), 2)) = byte(*(*uint8)(unsafe.Pointer(uintptr(v6 + 2))))
		if v5 == 0 {
			break
		}
	}
	result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v10[0]))), 21, 0, 1))))
	for i = *(**uint32)(unsafe.Pointer(uintptr(a2 + 504))); i != nil; i = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*124))))) {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*4))&0x100 != 0 {
			result = sub_4D82F0(a1, i)
		}
	}
	return result
}
func nox_xxx_netSendJournalAdd_4D9440(a1 int32, a2p *nox_playerInfo_journal) int32 {
	var (
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v3 [68]byte
	)
	v3[0] = 213
	v3[1] = 1
	libc.StrCpy(&v3[2], (*byte)(unsafe.Pointer(uintptr(a2))))
	*(*uint16)(unsafe.Pointer(&v3[66])) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 72)))
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v3[0]), 68, 0, 1)
}
func nox_xxx_netSendJournalRemove_4D94A0(a1 int32, a2 *byte) int32 {
	var v3 [68]byte
	v3[0] = 213
	v3[1] = 2
	libc.StrCpy(&v3[2], a2)
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v3[0]), 68, 0, 1)
}
func nox_xxx_netSendJournalUpdate_4D9500(a1 int32, a2 int32) int32 {
	var v3 [68]byte
	v3[0] = 213
	v3[1] = 3
	libc.StrCpy(&v3[2], (*byte)(unsafe.Pointer(uintptr(a2))))
	*(*uint16)(unsafe.Pointer(&v3[66])) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 72)))
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v3[0]), 68, 0, 1)
}
func nox_xxx_netSendChapterEnd_4D9560(a1 int32, a2 int8, a3 int32) int32 {
	var v5 [3]byte
	v5[1] = byte(a2)
	v5[0] = 214
	v5[2] = byte(int8(bool2int32(a3 == 1)))
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v5[0]), 3, 0, 1)
}
func nox_xxx_netSendFlagStatus_4D95A0(a1 int32, a2 int8, a3 int8, a4 int8, a5 int16) int32 {
	var v6 [6]byte
	v6[1] = byte(a3)
	v6[3] = byte(a4)
	v6[2] = byte(a2)
	v6[0] = 216
	*(*uint16)(unsafe.Pointer(&v6[4])) = uint16(a5)
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v6[0]))), 6, 0, 1)
}
func nox_xxx_netSendBallStatus_4D95F0(a1 int32, a2 int8, a3 int16) int32 {
	var v4 [4]byte
	v4[1] = byte(a2)
	v4[0] = 217
	*(*uint16)(unsafe.Pointer(&v4[2])) = uint16(a3)
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v4[0]))), 4, 0, 1)
}
func nox_xxx_netReportSpellStat_4D9630(a1 int32, a2 int32, a3 int8) int32 {
	var v4 [6]byte
	*(*uint32)(unsafe.Pointer(&v4[1])) = uint32(a2)
	v4[0] = 223
	v4[5] = byte(a3)
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v4[0]), 6, 0, 1)
}
func nox_xxx_netSendSecondaryWeapon_4D9670(a1 int32, a2 *uint32, a3 int8) int32 {
	var v4 [4]byte
	v4[0] = 224
	*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	v4[3] = byte(a3)
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v4[0]))), 4, 0, 0)
}
func nox_xxx_netMsgLastQuiver_4D96B0(a1 int32, a2 *uint32) int32 {
	var v4 [3]byte
	v4[0] = 225
	*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v4[0]))), 3, 0, 0)
}
func nox_xxx_netMsgInventoryLoaded_4D96E0(a1 int32) int32 {
	var v2 [1]byte
	v2[0] = 113
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v2[0]))), 1, 0, 0)
}
func nox_xxx_netFriendAddRemove_4D97A0(a1 int32, a2 *uint32, a3 int32) int32 {
	*((*uint8)(unsafe.Pointer(&a3))) = uint8(int8(bool2int32(a3 != 1) + 52))
	*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a3))), 1)))) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&a3))), 3, 0, 1)
}
func sub_4D97E0(a1 int32) int32 {
	var v2 [1]byte
	v2[0] = 54
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v2[0]))), 1, 0, 1)
}
func nox_xxx_netMsgFadeBeginPlayer(pl int32, a1 int32, a2 int32) int32 {
	var v4 [3]byte
	v4[0] = 0xE4
	v4[1] = byte(int8(bool2int32(a1 != 0)))
	v4[2] = byte(int8(bool2int32(a2 != 0)))
	return nox_xxx_netSendPacket1_4E5390(pl, int32(uintptr(unsafe.Pointer(&v4[0]))), 3, 0, 1)
}
func nox_xxx_playerReportAnything_4D9900(a1 int32) {
	var (
		v1  int32
		v2  int32
		v3  *uint16
		v4  int32
		v5  int32
		i   int32
		v7  *byte
		j   int32
		v9  int32
		v10 int32
		k   int32
		v12 int32
		v13 int32
		v14 int32
		v15 *uint16
		v16 int32
	)
	v1 = a1
	if a1 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		v3 = *(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
		v15 = *(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
		v16 = *(*int32)(unsafe.Pointer(uintptr(v2 + 228)))
		if *(*float32)(unsafe.Pointer(uintptr(v2 + 232))) != *(*float32)(unsafe.Pointer(&v16)) {
			nox_xxx_netReportArmorVal_4D8A30(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))), v16)
			*(*uint32)(unsafe.Pointer(uintptr(v2 + 232))) = *(*uint32)(unsafe.Pointer(uintptr(v2 + 228)))
		}
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))))
		if *(*uint32)(unsafe.Pointer(uintptr(v4 + 2168))) != *(*uint32)(unsafe.Pointer(uintptr(v4 + 2164))) {
			sub_4D8870(int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 2064)))), v1)
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2168))) = *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2164)))
		}
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 2172)))) != int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 440)))) {
			sub_4D8840(int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 2064)))), v1)
			*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2172))) = *(*uint8)(unsafe.Pointer(uintptr(v1 + 440)))
		}
		if noxflags.HasGame(4096) {
			for i = 0; i < 32; i++ {
				v7 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(i)))
				if v7 != nil && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v7))), 4*514))) != 0 && *(*uint32)(unsafe.Pointer(uintptr(v2 + 320))) != uint32(*(*uint8)(unsafe.Pointer(uintptr(i + v2 + 452)))) {
					sub_4D9D60(i, v1)
					*(*uint8)(unsafe.Pointer(uintptr(i + v2 + 452))) = *(*uint8)(unsafe.Pointer(uintptr(v2 + 320)))
				}
			}
			for j = 0; j < 32; j++ {
				v9 = 0
				if *memmap.PtrUint32(0x5D4594, 1556324) == 0 {
					*memmap.PtrUint32(0x5D4594, 1556324) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SilverKey")))
				}
				if nox_common_playerInfoFromNum_417090(j) != nil {
					v10 = nox_xxx_inventoryGetFirst_4E7980(v1)
					if v10 != 0 {
						for uint32(*(*uint16)(unsafe.Pointer(uintptr(v10 + 4)))) != *memmap.PtrUint32(0x5D4594, 1556324) {
							v10 = nox_xxx_inventoryGetNext_4E7990(v10)
							if v10 == 0 {
								goto LABEL_25
							}
						}
						v9 = 1
					}
				LABEL_25:
					if v9 != int32(*(*uint8)(unsafe.Pointer(uintptr(j + v2 + 484)))) {
						sub_4D9DF0(j, v1, int8(v9))
						*(*uint8)(unsafe.Pointer(uintptr(j + v2 + 484))) = uint8(int8(v9))
					}
				}
			}
			for k = 0; k < 32; k++ {
				v12 = 0
				if *memmap.PtrUint32(0x5D4594, 1556328) == 0 {
					*memmap.PtrUint32(0x5D4594, 1556328) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("GoldKey")))
				}
				if nox_common_playerInfoFromNum_417090(k) != nil {
					v13 = nox_xxx_inventoryGetFirst_4E7980(v1)
					if v13 != 0 {
						for uint32(*(*uint16)(unsafe.Pointer(uintptr(v13 + 4)))) != *memmap.PtrUint32(0x5D4594, 1556328) {
							v13 = nox_xxx_inventoryGetNext_4E7990(v13)
							if v13 == 0 {
								goto LABEL_37
							}
						}
						v12 = 1
					}
				LABEL_37:
					if v12 != int32(*(*uint8)(unsafe.Pointer(uintptr(k + v2 + 516)))) {
						sub_4D9E30(k, v1, int8(v12))
						*(*uint8)(unsafe.Pointer(uintptr(k + v2 + 516))) = uint8(int8(v12))
					}
				}
			}
			v3 = v15
		}
		v14 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v14 + 2184)))) != 0 {
			nox_xxx_netReportTotalHealth_4D85C0(int32(*(*uint8)(unsafe.Pointer(uintptr(v14 + 2064)))), (*uint32)(unsafe.Pointer(uintptr(v1))))
			nox_xxx_netReportTotalMana_4D88C0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))), v1)
			nox_xxx_servSendStats_4D8990(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))), v1, int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 3684)))))
			*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2184))) = 0
		}
		if false {
			sub_528030(v1)
		} else {
			if v3 != nil && int32(*v3) != int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 10)))) {
				nox_xxx_netSendPlrHealthToTeam_4D86E0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))))
				*(*uint16)(unsafe.Pointer(uintptr(v2 + 10))) = *v3
			}
			if int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 4)))) != int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 6)))) {
				nox_xxx_netReportMana_4D8930(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))), v1)
				*(*uint16)(unsafe.Pointer(uintptr(v2 + 6))) = *(*uint16)(unsafe.Pointer(uintptr(v2 + 4)))
			}
		}
	}
}
func sub_4D9CF0(a1 int32) int32 {
	var v2 [2]byte
	v2[0] = 240
	v2[1] = 0
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v2[0]))), 2, 0, 1)
}
func sub_4D9D20(a1 int32, a2p *server.Object) int32 {
	var (
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v3 int16
		v5 [4]byte
	)
	v3 = int16(*(*uint16)(unsafe.Pointer(uintptr(a2 + 36))))
	*(*uint16)(unsafe.Pointer(&v5[0])) = 496
	*(*uint16)(unsafe.Pointer(&v5[2])) = uint16(v3)
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v5[0]))), 4, 0, 1)
}
func sub_4D9D60(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		v4 [5]byte
	)
	v4[0] = 240
	v4[1] = 4
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	*(*uint16)(unsafe.Pointer(&v4[3])) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 36)))
	v4[2] = byte(*(*uint8)(unsafe.Pointer(uintptr(v2 + 320))))
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v4[0]), 5, 0, 1)
}
func sub_4D9DF0(a1 int32, a2 int32, a3 int8) int32 {
	var v4 [5]byte
	*(*uint16)(unsafe.Pointer(&v4[3])) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 36)))
	v4[0] = 240
	v4[1] = 22
	v4[2] = byte(a3)
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v4[0]), 5, 0, 1)
}
func sub_4D9E30(a1 int32, a2 int32, a3 int8) int32 {
	var v4 [5]byte
	*(*uint16)(unsafe.Pointer(&v4[3])) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 36)))
	v4[0] = 240
	v4[1] = 23
	v4[2] = byte(a3)
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v4[0]), 5, 0, 1)
}
func nox_xxx_netGauntlet_4D9E70(a1 int32) int32 {
	var v2 [2]byte
	v2[0] = 240
	v2[1] = 20
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v2[0]), 2, 0, 1)
}
func nox_xxx_netSendLineMessage_4D9EB0(a1p *server.Object, a2 *wchar2_t, _rest ...interface{}) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result int32
		v3     int32
		v4     int8
		v5     int32
		v6     [516]wchar2_t
		va     libc.ArgList
	)
	va.Start(a2, _rest)
	result = a1
	if a1 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		nox_vswprintf(&v6[260], a2, va)
		*((*uint8)(unsafe.Pointer(&v6[0]))) = 168
		*(*wchar2_t)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v6[0]))), 1)))) = 0
		*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v6[1]))), unsafe.Sizeof(wchar2_t(0))-1)) = 0
		if nox_xxx_cliCanTalkMB_4100F0((*int16)(unsafe.Pointer(&v6[260]))) != 0 {
			v4 = int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v6[1]))), unsafe.Sizeof(wchar2_t(0))-1))) | 2)
		} else {
			v4 = int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v6[1]))), unsafe.Sizeof(wchar2_t(0))-1))) | 4)
		}
		*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v6[1]))), unsafe.Sizeof(wchar2_t(0))-1)) = uint8(v4)
		v6[2] = 0
		v6[3] = 0
		*((*uint8)(unsafe.Pointer(&v6[5]))) = 0
		v6[4] = wchar2_t(uint8(nox_wcslen(&v6[260]) + 1))
		if v6[1]&0x400 != 0 {
			nox_wcscpy((*wchar2_t)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v6[5]))), 1)))), &v6[260])
			v5 = 2
		} else {
			nox_sprintf((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v6[5]))), 1)), internCStr("%S"), &v6[260])
			v5 = 1
		}
		result = nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2064)))), 1, (*uint8)(unsafe.Pointer(&v6[0])), v5*int32(*((*uint8)(unsafe.Pointer(&v6[4]))))+11)
	}
	return result
}
func nox_xxx_printToAll_4D9FD0(a1 int8, a2 *wchar2_t, _rest ...interface{}) int32 {
	var (
		v2     int8
		v3     int32
		result int32
		i      int32
		v6     [516]wchar2_t
		va     libc.ArgList
	)
	va.Start(a2, _rest)
	nox_vswprintf(&v6[260], a2, va)
	*((*uint8)(unsafe.Pointer(&v6[0]))) = 168
	*(*wchar2_t)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v6[0]))), 1)))) = 0
	*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v6[1]))), unsafe.Sizeof(wchar2_t(0))-1)) = uint8(a1)
	if nox_xxx_cliCanTalkMB_4100F0((*int16)(unsafe.Pointer(&v6[260]))) != 0 {
		v2 = int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v6[1]))), unsafe.Sizeof(wchar2_t(0))-1))) | 2)
	} else {
		v2 = int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v6[1]))), unsafe.Sizeof(wchar2_t(0))-1))) | 4)
	}
	*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v6[1]))), unsafe.Sizeof(wchar2_t(0))-1)) = uint8(v2)
	v6[2] = 0
	v6[3] = 0
	*((*uint8)(unsafe.Pointer(&v6[5]))) = 0
	v6[4] = wchar2_t(uint8(nox_wcslen(&v6[260]) + 1))
	if v6[1]&0x400 != 0 {
		nox_wcscpy((*wchar2_t)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v6[5]))), 1)))), &v6[260])
		v3 = 2
	} else {
		nox_sprintf((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v6[5]))), 1)), internCStr("%S"), &v6[260])
		v3 = 1
	}
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 276))) + 2064)))), 1, (*uint8)(unsafe.Pointer(&v6[0])), v3*int32(*((*uint8)(unsafe.Pointer(&v6[4]))))+11)
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func nox_xxx_netInformTextMsg_4DA0F0(a1 int32, a2 int32, a3 *int32) int32 {
	var (
		result int32
		v4     int32
		v5     [6]byte
	)
	result = a2
	switch a2 {
	case 0, 1, 2, 12, 13, 16, 20, 21:
		v5[1] = byte(int8(a2))
		v4 = *a3
		v5[0] = 169
		*(*uint32)(unsafe.Pointer(&v5[2])) = uint32(v4)
		result = nox_netlist_addToMsgListCli_40EBC0(a1, 1, (*uint8)(unsafe.Pointer(&v5[0])), 6)
	case 17:
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a2))), unsafe.Sizeof(uint16(0))*0)) = 4521
		result = nox_netlist_addToMsgListCli_40EBC0(a1, 1, (*uint8)(unsafe.Pointer(&a2)), 2)
	default:
		return result
	}
	return result
}
func nox_xxx_netInformTextMsg2_4DA180(a1 int32, a2 *uint8) int32 {
	var (
		result int32
		i      int32
		j      int32
		k      int32
		v6     [6]byte
	)
	result = a1
	switch a1 {
	case 3, 4, 8, 18, 19, 21:
		v6[1] = byte(int8(a1))
		v6[0] = 169
		*(*uint32)(unsafe.Pointer(&v6[2])) = *(*uint32)(unsafe.Pointer(a2))
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
		for i = result; result != 0; i = result {
			nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 276))) + 2064)))), 1, (*uint8)(unsafe.Pointer(&v6[0])), 6)
			result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
		}
	case 5, 6, 7, 9, 10, 11:
		*a2 = 169
		*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 1)) = uint8(int8(a1))
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
		for j = result; result != 0; j = result {
			nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(j + 748))) + 276))) + 2064)))), 1, a2, 10)
			result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(j)))))))
		}
	case 14:
		*a2 = 169
		*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 1)) = uint8(int8(a1))
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
		for k = result; result != 0; k = result {
			nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(k + 748))) + 276))) + 2064)))), 1, a2, 11)
			result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(k)))))))
		}
	default:
		return result
	}
	return result
}
func nox_xxx_netPriMsgToPlayer_4DA2C0(a1p *server.Object, a2 *byte, a3 int8) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v3 int32
		v4 [52]byte
	)
	if a1 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 && a2 != nil && sub_419E60((*server.Object)(unsafe.Pointer(uintptr(a1)))) == 0 && libc.StrLen(a2) != 0 && libc.StrLen(a2) <= 0x30 {
		v4[2] = byte(a3)
		v4[0] = 169
		v4[1] = 15
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		libc.StrCpy(&v4[3], a2)
		nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2064)))), 1, (*uint8)(unsafe.Pointer(&v4[0])), int32(libc.StrLen(a2)+4))
	}
}
func nox_xxx_netPrintLineToAll_4DA390(a1 *byte) int32 {
	var (
		result int32
		i      int32
	)
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(unsafe.Pointer(uintptr(i))), a1, 0)
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func nox_xxx_getObjectByScrName_4DA4F0(a1 *byte) *server.Object {
	var (
		i      int32
		result int32
		v3     int32
		v4     int32
		v5     int32
	)
	if libc.StrChr(a1, ':') != nil {
		for i = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(i))))))) {
			result = sub_4DA5C0(i, a1)
			if result != 0 {
				return (*server.Object)(unsafe.Pointer(uintptr(result)))
			}
		}
		v3 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObjectUninited_4DA870())))
		if v3 != 0 {
			for {
				result = sub_4DA5C0(v3, a1)
				if result != 0 {
					break
				}
				result = int32(uintptr(unsafe.Pointer(nox_server_getNextObjectUninited_4DA880((*server.Object)(unsafe.Pointer(uintptr(v3)))))))
				v3 = result
				if result == 0 {
					break
				}
			}
			return (*server.Object)(unsafe.Pointer(uintptr(result)))
		}
		return nil
	}
	v4 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if v4 != 0 {
		for {
			result = sub_4DA660(v4, a1)
			if result != 0 {
				break
			}
			v4 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(v4)))))))
			if v4 == 0 {
				goto LABEL_12
			}
		}
		return (*server.Object)(unsafe.Pointer(uintptr(result)))
	}
LABEL_12:
	v5 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObjectUninited_4DA870())))
	if v5 == 0 {
		return nil
	}
	for {
		result = sub_4DA660(v5, a1)
		if result != 0 {
			break
		}
		v5 = int32(uintptr(unsafe.Pointer(nox_server_getNextObjectUninited_4DA880((*server.Object)(unsafe.Pointer(uintptr(v5)))))))
		if v5 == 0 {
			return nil
		}
	}
	return (*server.Object)(unsafe.Pointer(uintptr(result)))
}
func sub_4DA5C0(a1 int32, a2 *byte) int32 {
	var v2 int32
	v2 = a1
	if *(*uint32)(unsafe.Pointer(uintptr(a1))) != 0 && libc.StrCmp(*(**byte)(unsafe.Pointer(uintptr(a1))), a2) == 0 {
		return v2
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))))
	if v2 != 0 {
		for *(*uint32)(unsafe.Pointer(uintptr(v2))) == 0 || libc.StrCmp(*(**byte)(unsafe.Pointer(uintptr(v2))), a2) != 0 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 496))))
			if v2 == 0 {
				return 0
			}
		}
		return v2
	}
	return 0
}
func sub_4DA660(a1 int32, a2 *byte) int32 {
	var (
		i   int32
		v3  *byte
		v4  *byte
		v5  *byte
		v6  bool
		v7  uint8
		v8  uint8
		v9  int32
		v10 *byte
		v11 uint8
		v12 uint8
		v14 *byte
	)
	i = a1
	if *(*uint32)(unsafe.Pointer(uintptr(a1))) != 0 {
		v3 = libc.StrChr(*(**byte)(unsafe.Pointer(uintptr(a1))), 58)
		v4 = a2
		if v3 != nil {
			v5 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1))
			for {
				v6 = uint32(*v5) < uint32(*v4)
				if *v5 != *v4 {
					break
				}
				if *v5 != 0 {
					v7 = uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v5), 1)))
					v8 = uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v4), 1)))
					v6 = int32(v7) < int32(v8)
					if int32(v7) != int32(v8) {
						break
					}
					v5 = (*byte)(unsafe.Add(unsafe.Pointer(v5), 2))
					v4 = (*byte)(unsafe.Add(unsafe.Pointer(v4), 2))
					if int32(v7) != 0 {
						continue
					}
				}
				v9 = 0
				goto LABEL_16
			}
		} else {
			v10 = *(**byte)(unsafe.Pointer(uintptr(a1)))
			for {
				v6 = uint32(*v10) < uint32(*v4)
				if *v10 != *v4 {
					break
				}
				if *v10 != 0 {
					v11 = uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v10), 1)))
					v12 = uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v4), 1)))
					v6 = int32(v11) < int32(v12)
					if int32(v11) != int32(v12) {
						break
					}
					v10 = (*byte)(unsafe.Add(unsafe.Pointer(v10), 2))
					v4 = (*byte)(unsafe.Add(unsafe.Pointer(v4), 2))
					if int32(v11) != 0 {
						continue
					}
				}
				v9 = 0
				goto LABEL_16
			}
		}
		v9 = -bool2int32(v6) - (bool2int32(v6) - 1)
	LABEL_16:
		if v9 == 0 {
			return i
		}
	}
	for i = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504)))); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 496)))) {
		if *(*uint32)(unsafe.Pointer(uintptr(i))) != 0 {
			v14 = libc.StrChr(*(**byte)(unsafe.Pointer(uintptr(i))), 58)
			if v14 != nil {
				if libc.StrCmp((*byte)(unsafe.Add(unsafe.Pointer(v14), 1)), a2) == 0 {
					return i
				}
			} else if libc.StrCmp(*(**byte)(unsafe.Pointer(uintptr(i))), a2) == 0 {
				return i
			}
		}
	}
	return 0
}
func nox_xxx_getFirstPlayerUnit_4DA7C0() *server.Object {
	for p := (*server.Player)(nox_common_playerInfoGetFirst_416EA0()); p != nil; p = nox_common_playerInfoGetNext_416EE0(p) {
		if p.PlayerUnit != nil {
			return p.PlayerUnit
		}
	}
	return nil
}
func nox_xxx_getNextPlayerUnit_4DA7F0(obj *server.Object) *server.Object {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(obj)))
		v1 *byte
	)
	if a1 == 0 {
		return nil
	}
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8)))) & 4) == 0 {
		return nil
	}
	v1 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276)))))))))
	if v1 == nil {
		return nil
	}
	for *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*514))) == 0 {
		v1 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))))))
		if v1 == nil {
			return nil
		}
	}
	return (*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*514))))))
}
func nox_xxx_unitNewAddShadow_4DA9A0(a1p *server.Object) *uint32 {
	var (
		a1     *uint32 = (*uint32)(unsafe.Pointer(a1p))
		result *uint32
		v2     int32
	)
	result = a1
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	if (uint32(v2) & 0x410000) == 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*118)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) = uint32(v2) | 0x10000
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*117)) = dword_5d4594_1556856
		if dword_5d4594_1556856 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1556856 + 472))) = uint32(uintptr(unsafe.Pointer(a1)))
		}
		dword_5d4594_1556856 = uint32(uintptr(unsafe.Pointer(a1)))
	}
	return result
}
func nox_xxx_action_4DA9F0(a1p *server.Object) *uint32 {
	var (
		a1     *uint32 = (*uint32)(unsafe.Pointer(a1p))
		result *uint32
		v2     int32
		v3     int32
		v4     int32
	)
	result = a1
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	if uint32(v2)&0x10000 != 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) = uint32(v2) & 0xFFFEFFFF
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*118)))
		if v3 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 468))) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*117))
		} else {
			dword_5d4594_1556856 = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*117))
		}
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*117)))
		if v4 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v4 + 472))) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*118))
		}
	}
	return result
}
func nox_client_countSaveFiles_4DC550() int32 {
	var (
		v0       int32
		v1       *byte
		v5       *byte
		v6       int32
		v7       *byte
		PathName [1024]byte
	)
	v0 = 0
	v1 = nox_fs_root()
	libc.StrCpy(&PathName[0], v1)
	libc.StrCat(&PathName[0], internCStr("\\Save\\"))
	nox_fs_mkdir(&PathName[0])
	v5 = nox_fs_root()
	nox_sprintf(&PathName[0], internCStr("%s\\Save\\AUTOSAVE\\Player.plr"), v5)
	if nox_fs_access(&PathName[0], 0) != -1 {
		v0 = 1
	}
	v6 = 13
	for {
		v7 = nox_fs_root()
		nox_sprintf(&PathName[0], internCStr("%s\\Save\\SAVE%04d\\Player.plr"), v7, v0)
		if nox_fs_access(&PathName[0], 0) != -1 {
			v0++
		}
		v6--
		if v6 == 0 {
			break
		}
	}
	return v0
}
func nox_client_countPlayerFiles02_4DC630() int32 {
	var (
		v0           int32
		v1           *byte
		v5           HANDLE
		v6           *byte
		FindFileData WIN32_FIND_DATAA
		PathName     [1024]byte
		v10          [1280]byte
		v11          [1024]byte
	)
	v0 = 0
	v1 = nox_fs_root()
	libc.StrCpy(&PathName[0], v1)
	libc.StrCat(&PathName[0], internCStr("\\Save\\"))
	libc.StrCpy(&v11[0], &PathName[0])
	nox_fs_mkdir(&PathName[0])
	nox_fs_set_workdir(&PathName[0])
	v5 = compatFindFirstFileA(internCStr("*.plr"), &FindFileData)
	if uintptr(v5) != uintptr(math.MaxUint32) {
		if (FindFileData.FileAttributes & 0x10) == 0 {
			nox_sprintf(&PathName[0], internCStr("%s%s"), &v11[0], &FindFileData.cFileName[0])
			sub_41A000(&PathName[0], (*Nox_savegame_xxx)(unsafe.Pointer(&v10[0])))
			if v10[0]&2 != 0 {
				v0 = 1
			}
		}
		for compatFindNextFileA(v5, &FindFileData) != 0 {
			if (FindFileData.FileAttributes & 0x10) == 0 {
				nox_sprintf(&PathName[0], internCStr("%s%s"), &v11[0], &FindFileData.cFileName[0])
				sub_41A000(&PathName[0], (*Nox_savegame_xxx)(unsafe.Pointer(&v10[0])))
				if v10[0]&2 != 0 {
					v0++
				}
			}
		}
		compatFindClose(v5)
	}
	v6 = nox_fs_root()
	nox_fs_set_workdir(v6)
	return v0
}
func nox_xxx_mapLoadOrSaveMB_4DCC70(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1563072) = uint32(a1)
	return result
}
func nox_xxx_game_4DCCB0() int32 {
	var (
		result int32
		v1     *byte
		v2     int32
		v3     int32
	)
	if !noxflags.HasGame(2048) {
		return 1
	}
	v1 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(31)))
	if v1 == nil || (func() int32 {
		v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*514))))
		return v2
	}()) == 0 || sub_4DCC90() != 0 || sub_4139B0() != 0 || (gameFrame()-*memmap.PtrUint32(0x5D4594, 1563068)) < 0x1E || nox_xxx_guiCursor_477600() != 0 || (func() int32 {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))))
		return int32(*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v3))), 1))) & 0x40
	}()) != 0 {
		result = 0
	} else {
		result = bool2int32(sub_4DCC10((*server.Object)(unsafe.Pointer(uintptr(v2)))) != 0)
	}
	return result
}
func nox_xxx_gameServerReadyMB_4DD180(a1 int32) *byte {
	var (
		result *byte
		v2     *byte
		v3     int32
		i      int32
		v5     int32
	)
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(a1)))
	v2 = result
	if result != nil {
		nox_xxx_netNeedTimestampStatus_4174F0((*server.Player)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(result)))))), 16)
		if noxflags.HasGame(0x2000) && !noxflags.HasGame(128) {
			v3 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514))))
			if v3 != 0 {
				nox_xxx_spellBuffOff_4FF5B0((*server.Object)(unsafe.Pointer(uintptr(v3))), 23)
				nox_xxx_buffApplyTo_4FF380((*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514)))))), 23, int16(int32(uint16(gameFPS()))*5), 5)
			}
			for i = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(i))))))) {
				if *(*uint32)(unsafe.Pointer(uintptr(i + 8)))&0x10000000 != 0 {
					nox_xxx_netMarkMinimapObject_417190(a1, (*server.Object)(unsafe.Pointer(uintptr(i))), 1)
				}
			}
		}
		if (*(*byte)(unsafe.Add(unsafe.Pointer(v2), 3680)) & 1) == 1 {
			v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514))))
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*908))) = *(*uint32)(unsafe.Pointer(uintptr(v5 + 56)))
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*909))) = *(*uint32)(unsafe.Pointer(uintptr(v5 + 60)))
			if noxflags.HasGame(512) {
				nox_xxx_playerLeaveObserver_0_4E6AA0((*server.Player)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))))
			}
		}
		nox_xxx_wall_4DF1E0(a1)
		if noxflags.HasGame(4096) && sub_40A300() == 1 {
			nox_xxx_netGauntlet_4D9E70(a1)
		}
		if a1 == 31 && noxflags.HasGame(128) {
			if nox_server_connectionType_3596 == 0 && false {
				sub_49C820()
				return (*byte)(unsafe.Pointer(uintptr(nox_xxx_netStatsMultiplier_4D9C20((*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514))))))))))
			}
			if nox_server_sanctuaryHelp_54276 == 1 {
				nox_xxx_cliShowHelpGui_49C560()
				return (*byte)(unsafe.Pointer(uintptr(nox_xxx_netStatsMultiplier_4D9C20((*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514))))))))))
			}
			nox_xxx_guiServerOptsLoad_457500()
		}
		result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_netStatsMultiplier_4D9C20((*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514))))))))))
	}
	return result
}
func nox_xxx_netGuiGameSettings_4DD9B0(a1 int8, a2 unsafe.Pointer, a3 int32) int32 {
	var v4 [60]byte
	v4[0] = 177
	v4[1] = byte(a1)
	alloc.Memcpy(unsafe.Pointer(&v4[2]), a2, 0x3A)
	return nox_xxx_netSendPacket1_4E5390(a3, int32(uintptr(unsafe.Pointer(&v4[0]))), 60, 0, 0)
}
func nox_xxx_netNewPlayerMakePacket_4DDA90(buf *uint8, pl *server.Player) {
	*buf = 45
	*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(buf), 1)))) = uint16(pl.NetCodeVal)
	*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(buf), 100)))) = uint16(int16(pl.Lessons))
	*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(buf), 102)))) = uint16(pl.Field2140)
	*(*uint32)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(buf), 104)))) = pl.Field0
	*(*uint32)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(buf), 108)))) = pl.Field4
	*(*uint8)(unsafe.Add(unsafe.Pointer(buf), 116)) = uint8(pl.Field2152)
	*(*uint8)(unsafe.Add(unsafe.Pointer(buf), 117)) = uint8(pl.Field2156)
	*(*uint8)(unsafe.Add(unsafe.Pointer(buf), 118)) = uint8(int8(bool2int32(int32(pl.Field3676) == 3)))
	*(*uint32)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(buf), 112)))) = pl.Field3680 & 0x423
	alloc.Memcpy(unsafe.Add(unsafe.Pointer(buf), 119), unsafe.Pointer(&pl.Field2096Buf[0]), uintptr(libc.StrLen(&pl.Field2096Buf[0])+1))
	alloc.Memcpy(unsafe.Add(unsafe.Pointer(buf), 3), unsafe.Pointer(pl.Info()), 97)
}
func sub_4DDE10(a1 int32, a2p *server.Player) {
	var (
		a2     int32 = int32(uintptr(unsafe.Pointer(a2p)))
		result *uint32
		i      int32
		v4     int32
	)
	result = *(**uint32)(unsafe.Pointer(uintptr(a2 + 2056)))
	if result != nil {
		if dword_5d4594_1563276 == 0 {
			dword_5d4594_1563276 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Flag")))
		}
		result = *(**uint32)(unsafe.Pointer(uintptr(a2 + 2056)))
		for i = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*126))); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 496)))) {
			v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 16))))
			if (v4 & 0x100) == 0 {
				result = *(**uint32)(unsafe.Pointer(&dword_5d4594_1563276))
				if uint32(*(*uint16)(unsafe.Pointer(uintptr(i + 4)))) != dword_5d4594_1563276 {
					continue
				}
			}
			sub_4D82F0(a1, (*uint32)(unsafe.Pointer(uintptr(i))))
		}
	}
}
func nox_xxx_netPlayerIncomingServ_4DDF60(a1 int32) int32 {
	var (
		v1  int32
		v2  *byte
		v3  int32
		v4  int32
		v5  int32
		i   *byte
		v7  int32
		v8  *byte
		j   *byte
		v10 *uint8
		k   int32
		v13 int32
	)
	v1 = a1
	v2 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(a1)))
	if v2 == nil {
		panic("abort")
	}
	if noxflags.HasGame(4096) {
		if a1 != 31 {
			if v2 != nil {
				v3 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514))))
				if v3 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 748))) + 552))) = 1
				}
			}
		}
		sub_4D9CF0(a1)
		if v2 != nil && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514))) != 0 {
			sub_4D6000((*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514)))))))
		}
	}
	sub_57B920(unsafe.Add(unsafe.Pointer(v2), 16))
	v13 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514))))
	dword_5d4594_2649712 |= uint32(1 << v1)
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v13 + 56))))
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v13 + 60))))
	nox_xxx_newPlayerSendAllPlayers_4DE300(v1)
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*1175))) = 0
	v13p := AsObjectP(unsafe.Pointer(uintptr(v13)))
	v13p.Init.Get()(v13p)
	*(*byte)(unsafe.Add(unsafe.Pointer(v2), 3676)) = 3
	if !noxflags.HasGame(512) {
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*908))) = uint32(v4)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*909))) = uint32(v5)
	}
	if nox_server_sendMotd_108752 != 0 && noxflags.HasGame(0x2000) && !noxflags.HasGame(4096) {
		nox_xxx_playerSendMOTD_4DD140(v1)
	}
	for i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); i != nil; i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(i))))))))) {
		v7 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*514))))
		if v7 != 0 {
			if i != v2 {
				nox_xxx_netMarkMinimapObject_417190(v1, (*server.Object)(unsafe.Pointer(uintptr(v7))), 1)
				nox_xxx_netMarkMinimapObject_417190(int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(i), 2064)))), (*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514)))))), 1)
				nox_xxx_netSendSimpleObject2_4DF360(int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(i), 2064)))), (*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*514)))))))
				if noxflags.HasGame(4096) {
					nox_xxx_netSendTeam_4D8670(int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(i), 2064)))), *((**uint32)(unsafe.Add(unsafe.Pointer((**uint32)(unsafe.Pointer(v2))), unsafe.Sizeof((*uint32)(nil))*514))))
					nox_xxx_netSendTeam_4D8670(v1, *((**uint32)(unsafe.Add(unsafe.Pointer((**uint32)(unsafe.Pointer(i))), unsafe.Sizeof((*uint32)(nil))*514))))
				}
			}
		}
	}
	nox_xxx_servMinimapRevealFlag_4DE380(v1)
	sub_4DF2E0(v1)
	if noxflags.HasGame(1024) && sub_40AA70((*server.Player)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2))))))) == 0 {
		nox_xxx_netNeedTimestampStatus_4174F0((*server.Player)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), 256)
	}
	if false {
		sub_4161E0()
		sub_416690()
	}
	sub_4E8110(v1)
	if noxflags.HasGame(64) {
		v8 = sub_4E8310()
		nox_xxx_netSendBallStatus_4D95F0(v1, int8(*v8), int16(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v8))), unsafe.Sizeof(uint16(0))*1)))))
	} else if noxflags.HasGame(32) {
		for j = (*byte)(unsafe.Pointer(nox_server_teamFirst_418B10())); j != nil; j = (*byte)(unsafe.Pointer(nox_server_teamNext_418B60((*nox_team_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(j))))))))) {
			v10 = sub_4E8320(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(j), 57))))
			nox_xxx_netSendFlagStatus_4D95A0(v1, int8(*v10), int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 2))), int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 1))), int16(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v10))), unsafe.Sizeof(uint16(0))*2)))))
		}
	}
	nox_xxx_sendAllClientStatus_4175C0(int32(uintptr(unsafe.Pointer(v2))))
	if sub_409F40(0x2000) != 0 {
		nox_xxx_sendAllPlayerIDs_4DE270(int32(uintptr(unsafe.Pointer(v2))))
	}
	if noxflags.HasGame(4096) {
		for k = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); k != 0; k = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(k))))))) {
			if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(k + 748))) + 276))) + 4792))) == 1 {
				sub_4D9D20(v1, (*server.Object)(unsafe.Pointer(uintptr(k))))
			}
		}
	}
	if noxflags.HasGame(4096) {
		sub_4D7A60(v1)
	}
	return int32(*(*uint32)(unsafe.Pointer(uintptr(v13 + 36))))
}
func nox_xxx_sendAllPlayerIDs_4DE270(a1 int32) int32 {
	var (
		result int32
		i      int32
		v3     int32
		v4     [7]byte
	)
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		if *(*uint32)(unsafe.Pointer(uintptr(i + 36))) != *(*uint32)(unsafe.Pointer(uintptr(a1 + 2060))) {
			if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 260))) != 0 {
				v4[0] = 210
				*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(i)))))
				v3 = int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 2064))))
				*(*uint16)(unsafe.Pointer(&v4[3])) = *(*uint16)(unsafe.Pointer(uintptr(i + 4)))
				v4[5] = 1
				v4[6] = 2
				nox_xxx_netSendPacket0_4E5420(v3, unsafe.Pointer(&v4[0]), 7, 0, 1)
			}
		}
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func nox_xxx_newPlayerSendAllPlayers_4DE300(a1 int32) *byte {
	var (
		result *byte
		i      int32
		v3     [132]byte
	)
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
	for i = int32(uintptr(unsafe.Pointer(result))); result != nil; i = int32(uintptr(unsafe.Pointer(result))) {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(i + 2064)))) != a1 && (int32(*(*uint8)(unsafe.Pointer(uintptr(i + 2064)))) != 31 || !nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING))) {
			nox_xxx_netNewPlayerMakePacket_4DDA90((*uint8)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(&v3[0])))))), (*server.Player)(unsafe.Pointer(uintptr(i))))
			nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v3[0]))), 129, 0, 0)
			sub_4DDE10(a1, (*server.Player)(unsafe.Pointer(uintptr(i))))
		}
		result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(uintptr(i))))))
	}
	return result
}
func nox_xxx_servMinimapRevealFlag_4DE380(a1 int32) int32 {
	var (
		result int32
		i      int32
		v3     int32
	)
	if *memmap.PtrUint32(0x5D4594, 1563284) == 0 {
		*memmap.PtrUint32(0x5D4594, 1563284) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("GameBall")))
	}
	if *memmap.PtrUint32(0x5D4594, 1563272) == 0 {
		*memmap.PtrUint32(0x5D4594, 1563272) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Crown")))
	}
	result = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	for i = result; result != 0; i = result {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(i + 16))))&4 != 0 {
			v3 = int32(*(*uint16)(unsafe.Pointer(uintptr(i + 4))))
			if uint32(uint16(int16(v3))) == *memmap.PtrUint32(0x5D4594, 1563284) || uint32(v3) == *memmap.PtrUint32(0x5D4594, 1563272) {
				nox_xxx_netMarkMinimapObject_417190(a1, (*server.Object)(unsafe.Pointer(uintptr(i))), 1)
			}
		}
		result = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func sub_4DE410(a1 int32) {
	var (
		v1     int32
		v2     int32
		result *uint32
		i      *uint32
		v5     int32
		v6     int32
		v7     uint32
		v8     int32
	)
	v1 = a1
	v2 = 1 << a1
	v8 = 1 << a1
	result = (*uint32)(unsafe.Pointer(nox_server_getFirstObject_4DA790()))
	for i = result; result != nil; i = result {
		v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*2)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*38)) |= uint32(v2)
		if (uint32(v5) & 0x20400000) == 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*37)) &= uint32(^v2)
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*uintptr(v1+140))) &= 0xFFF
		if *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*2))&0x20400000 != 0 {
			v6 = 0x10000
			v7 = 1
			for {
				if sub_4E4C90((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(i)))))), v7) != 0 {
					*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*uintptr(v1+140))) |= uint32(v6)
				}
				v7 *= 2
				v6 *= 2
				if v7 >= 0x10000 {
					break
				}
			}
			v2 = v8
		}
		result = (*uint32)(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(i)))))))))
	}
}
func sub_4DE4D0(a1 int8) int32 {
	var (
		v1     int32
		result int32
		v3     int8
	)
	v1 = 1 << int32(a1)
	for result = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); result != 0; result = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(result))))))) {
		v3 = int8(*(*uint8)(unsafe.Pointer(uintptr(result + 16))))
		*(*uint32)(unsafe.Pointer(uintptr(result + 152))) |= uint32(v1)
		if (int32(v3)&0x20) == 0 && (*(*uint32)(unsafe.Pointer(uintptr(result + 8)))&0x20400006) == 0 {
			*(*uint32)(unsafe.Pointer(uintptr(result + 148))) &= uint32(^v1)
		}
	}
	return result
}
func nox_xxx_playerForceDisconnect_4DE7C0(ind int32) {
	var plr *server.Player = nox_common_playerInfoFromNum_417090(ind)
	nox_script_event_playerLeave(plr)
	if sub_4D12A0(ind) != 0 {
		sub_4D1250(ind)
	}
	if plr.Field2068 != 0 {
		var v3 *int32 = sub_425A70(int32(plr.Field2068))
		if v3 != nil {
			sub_425B60(unsafe.Pointer(v3), ind)
		}
	}
	var v4 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(plr.PlayerUnit))) + 748))))
	if *(*uint32)(unsafe.Pointer(uintptr(v4 + 280))) != 0 {
		nox_xxx_shopCancelSession_510DC0(*(**uint32)(unsafe.Pointer(uintptr(v4 + 280))))
	}
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 280))) = 0
	sub_510E20(int32(plr.PlayerInd))
	sub_4FF990(1 << int32(plr.PlayerInd))
	if !noxflags.HasGame(2) {
		plr.Active = 0
	}
	var pl *byte = (*byte)(unsafe.Pointer(plr))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1146)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1148)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1149)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1150)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1151)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1152)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1153)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1154)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1155)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1156)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1157)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1158)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1159)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1147)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1160)))
	sub_56F4F0((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(pl))), 4*1161)))
	var buf [3]byte
	buf[0] = 46
	*(*uint16)(unsafe.Pointer(&buf[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(plr.PlayerUnit))
	nox_xxx_netSendPacket0_4E5420(ind|0x80, unsafe.Pointer(&buf[0]), 3, 0, 0)
	nox_xxx_delayedDeleteObject_4E5CC0(plr.PlayerUnit)
	plr.PlayerUnit = nil
	for i := int32(int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i))))))) {
		var v7 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 748))))
		*(*uint8)(unsafe.Pointer(uintptr(ind + v7 + 452))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(v7 + ind*4 + 324))) = 0
		*(*uint8)(unsafe.Pointer(uintptr(ind + v7 + 484))) = 0
		*(*uint8)(unsafe.Pointer(uintptr(ind + v7 + 516))) = 0
	}
	if nox_xxx_gamePlayIsAnyPlayers_40A8A0() != 0 {
		if noxflags.HasGame(1024) && nox_xxx_serverIsClosing_446180() == 0 && sub_40A770() == 1 {
			sub_5095E0()
		}
	} else {
		sub_40A1F0(0)
		nox_xxx_playerForceSendLessons_416E50(1)
		nox_server_teamsResetYyy_417D00()
		sub_40A970()
	}
	sub_4E55F0(uint8(int8(ind)))
	nox_xxx_playerResetImportantCtr_4E4F40(ind)
	sub_4E4F30(ind)
	if false {
		sub_4161E0()
		sub_416690()
	}
	if !noxflags.HasGame(4096) {
		return
	}
	if sub_4E9010() == 1 {
		nox_xxx_mapLoad_4D2450((*byte)(unsafe.Pointer(sub_4E8E50())))
	} else if nox_server_questMaybeWarp_4E8F60() {
		sub_4D60B0()
		sub_4D76E0(1)
		var v12 int32 = nox_game_getQuestStage_4E3CC0()
		var v13 int32 = nox_server_questNextStageThreshold_4D74F0(v12)
		nox_game_setQuestStage_4E3CD0(v13 - 1)
		nox_xxx_mapLoad_4D2450((*byte)(unsafe.Pointer(sub_4E8E50())))
	} else {
		var result *byte = (*byte)(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))
		if result != nil {
			for *(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(result))), 4*187))) + 312))) == 0 {
				result = (*byte)(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(result)))))))))
				if result == nil {
					return
				}
			}
			result = (*byte)(unsafe.Pointer(uintptr(sub_4E8E60())))
		}
	}
}
func nox_xxx_netGameSettings_4DEF00() int32 {
	var (
		v0 *byte
		v2 [20]byte
		v3 [49]byte
	)
	v0 = nox_xxx_cliGamedataGet_416590(0)
	v2[0] = 175
	*(*uint32)(unsafe.Pointer(&v2[1])) = gameFrame()
	*(*uint32)(unsafe.Pointer(&v2[9])) = nox_common_gameFlags_getVal_40A5B0() & 0x7FFF0
	*(*uint32)(unsafe.Pointer(&v2[13])) = uint32(nox_xxx_getServerSubFlags_409E60())
	*(*uint32)(unsafe.Pointer(&v2[5])) = NOX_CLIENT_VERS_CODE
	v2[17] = byte(int8(nox_xxx_servGetPlrLimit_409FA0()))
	v2[18] = byte(int8(nox_xxx_servGamedataGet_40A020(int16(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v0))), unsafe.Sizeof(uint16(0))*26)))))))
	v2[19] = byte(sub_40A180(int16(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v0))), unsafe.Sizeof(uint16(0))*26))))))
	v3[0] = 176
	libc.StrCpy(&v3[1], nox_xxx_serverOptionsGetServername_40A4C0())
	alloc.Memcpy(unsafe.Pointer(&v3[17]), unsafe.Add(unsafe.Pointer(v0), 24), 0x1C)
	if sub_40A220() != 0 && (sub_40A300() != 0 || int32(sub_40A180(int16(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v0))), unsafe.Sizeof(uint16(0))*26)))))) != 0) {
		*(*uint32)(unsafe.Pointer(&v3[45])) = uint32(sub_40A230())
	} else {
		*(*uint32)(unsafe.Pointer(&v3[45])) = 0
	}
	nox_xxx_netSendPacket1_4E5390(159, int32(uintptr(unsafe.Pointer(&v2[0]))), 20, 0, 0)
	return nox_xxx_netSendPacket1_4E5390(159, int32(uintptr(unsafe.Pointer(&v3[0]))), 49, 0, 0)
}
func sub_4DF020() *byte {
	var (
		result *byte
		v1     int32
		v2     *uint8
		v3     *byte
		v4     bool
		i      *byte
		v6     [60]byte
	)
	result = sub_459AA0(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(&v6[0]))))))
	v1 = 29
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1563214))
	v3 = &v6[0]
	v4 = true
	for {
		if v1 == 0 {
			break
		}
		v4 = int32(*(*uint16)(unsafe.Pointer(v3))) == int32(*(*uint16)(unsafe.Pointer(v2)))
		v3 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 2))
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 2))
		v1--
		if !v4 {
			break
		}
	}
	if !v4 {
		result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
		for i = result; result != nil; i = result {
			if *(*byte)(unsafe.Add(unsafe.Pointer(i), 2064)) != 31 {
				nox_xxx_netGuiGameSettings_4DD9B0(1, unsafe.Pointer(&v6[0]), int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(i), 2064)))))
			}
			result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(i)))))))))
		}
		alloc.Memcpy(memmap.PtrOff(0x5D4594, 1563214), unsafe.Pointer(&v6[0]), 0x38)
		*memmap.PtrUint16(0x5D4594, 1563270) = *(*uint16)(unsafe.Pointer(&v6[56]))
	}
	return result
}
func nox_xxx_wallSendDestroyed_4DF0A0(a1 int32, a2 int32) int32 {
	var (
		result int32
		i      int32
		v4     [3]byte
	)
	v4[0] = 58
	*(*uint16)(unsafe.Pointer(&v4[1])) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 10)))
	if a2 != 32 {
		return nox_xxx_netSendPacket0_4E5420(a2, unsafe.Pointer(&v4[0]), 3, 0, 1)
	}
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 276))) + 2064)))), unsafe.Pointer(&v4[0]), 3, 0, 1)
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func sub_4DF120(a1 unsafe.Pointer) int32 {
	var (
		result int32
		i      int32
		v3     [3]byte
	)
	v3[0] = 59
	*(*uint16)(unsafe.Pointer(&v3[1])) = *(*uint16)(unsafe.Pointer(uintptr(uint32(uintptr(a1)) + 10)))
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 276))) + 2064)))), unsafe.Pointer(&v3[0]), 3, 0, 1)
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func sub_4DF180(a1 unsafe.Pointer) int32 {
	var (
		result int32
		i      int32
		v3     [3]byte
	)
	v3[0] = 60
	*(*uint16)(unsafe.Pointer(&v3[1])) = *(*uint16)(unsafe.Pointer(uintptr(uint32(uintptr(a1)) + 10)))
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 276))) + 2064)))), unsafe.Pointer(&v3[0]), 3, 0, 1)
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func nox_xxx_wall_4DF1E0(a1 int32) int32 {
	var (
		i      *int32
		v2     int32
		result int32
		j      int32
		v5     int8
	)
	for i = (*int32)(nox_xxx_wallGetFirstBreakableCli_410870()); i != nil; i = (*int32)(unsafe.Pointer(uintptr(nox_xxx_wallGetNextBreakableCli_410880(i)))) {
		v2 = *(*int32)(unsafe.Add(unsafe.Pointer(i), 4*1))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 4))))&0x20 != 0 {
			nox_xxx_wallSendDestroyed_4DF0A0(v2, a1)
		}
	}
	sub_4DF2A0(int8(a1))
	if sub_5071C0() != 0 {
		sub_507190(a1, 1)
	}
	result = bool2int32(noxflags.HasGame(4096))
	if result != 0 {
		for j = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); j != 0; j = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(j))))))) {
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(j + 8))))&0x80) != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(j + 748))) + 48)))) != 0 {
				sub_4D6A20(a1, j)
			}
		}
		result = sub_4D72C0()
		if result == 1 {
			v5 = int8(sub_4D72C0())
			result = sub_4D7280(a1, v5)
		}
	}
	return result
}
func sub_4DF2A0(a1 int8) *int32 {
	var (
		v1     int32
		result *int32
	)
	v1 = 1 << int32(a1)
	for result = (*int32)(nox_xxx_wallSecretGetFirstWall_410780()); result != nil; result = (*int32)(unsafe.Pointer(uintptr(nox_xxx_wallSecretNext_410790(result)))) {
		if *(*int32)(unsafe.Add(unsafe.Pointer(result), 4*5))&8 != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*7)) |= v1
		} else {
			*(*int32)(unsafe.Add(unsafe.Pointer(result), 4*7)) &= ^v1
		}
	}
	return result
}
func sub_4DF2E0(a1 int32) {
	var (
		i *byte
		j int32
	)
	if a1 != 31 {
		for i = (*byte)(unsafe.Pointer(nox_server_teamFirst_418B10())); i != nil; i = (*byte)(unsafe.Pointer(nox_server_teamNext_418B60((*nox_team_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(i))))))))) {
			sub_4197C0((*wchar2_t)(unsafe.Pointer(i)), a1)
			for j = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); j != 0; j = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(j))))))) {
				if nox_xxx_teamCompare2_419180(unsafe.Pointer(uintptr(j+48)), uint8(*(*byte)(unsafe.Add(unsafe.Pointer(i), 57)))) != 0 {
					sub_4198A0(j+48, a1, int32(*(*uint32)(unsafe.Pointer(uintptr(j + 36)))))
				}
			}
		}
	}
}
func nox_xxx_netSendSimpleObject2_4DF360(a1 int32, a2p *server.Object) int32 {
	var (
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v2 int16
		v3 float32
		v4 int16
		v5 float32
		v7 [9]byte
	)
	v7[0] = 47
	*(*uint16)(unsafe.Pointer(&v7[3])) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))
	v2 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(uintptr(a2))))))
	v3 = *(*float32)(unsafe.Pointer(uintptr(a2 + 56)))
	*(*uint16)(unsafe.Pointer(&v7[1])) = uint16(v2)
	v4 = int16(int32(v3))
	v5 = *(*float32)(unsafe.Pointer(uintptr(a2 + 60)))
	*(*uint16)(unsafe.Pointer(&v7[5])) = uint16(v4)
	*(*uint16)(unsafe.Pointer(&v7[7])) = uint16(int16(int32(v5)))
	return nox_xxx_netSendPacket1_4E5390(a1, int32(uintptr(unsafe.Pointer(&v7[0]))), 9, 0, 1)
}
func sub_4DF3C0(pl *server.Player) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(pl)))
		v1 int32
		v2 *byte
		v3 *byte
		v4 *byte
		v5 *byte
		v6 int32
		v7 int32
		v8 int32
		v9 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 2056))))
	v2 = (*byte)(sub_416640())
	v3 = v2
	if v1 == 0 {
		return
	}
	if sub_40A740() == 0 && !noxflags.HasGame(0x8000) {
		var v2b uint8 = nox_xxx_getTeamCounter_417DD0()
		if int32(v2b) != 0 {
			v2 = sub_4189D0()
			v4 = v2
			if v2 != nil {
				v2 = (*byte)(unsafe.Pointer(uintptr(nox_xxx_servObjectHasTeam_419130(v1 + 48))))
				if v2 == nil {
					nox_xxx_createAtImpl_4191D0(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v4), 57))), unsafe.Pointer(uintptr(v1+48)), 1, int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 36)))), 1)
				}
			}
		}
		return
	}
	v2 = *(**byte)(unsafe.Pointer(uintptr(a1 + 2068)))
	if v2 == nil {
		return
	}
	v5 = (*byte)(unsafe.Pointer(nox_server_teamByXxx_418AE0(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 2068)))))))
	if v5 != nil {
		v6 = v1 + 48
		v7 = nox_xxx_servObjectHasTeam_419130(v1 + 48)
	} else {
		v8 = int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v3), 52))))
		if (noxflags.HasGame(96) || noxflags.HasGame(16) && nox_xxx_CheckGameplayFlags_417DA0(4)) && v8 > 2 {
			v8 = 2
		}
		v2 = (*byte)(unsafe.Pointer(uintptr(uint8(sub_417DE0()))))
		if int32(uintptr(unsafe.Pointer(v2))) >= v8 {
			return
		}
		if !noxflags.HasGame(96) || (func() bool {
			v9 = int32(uint8(sub_417DE0()))
			v2 = (*byte)(unsafe.Pointer(uintptr(sub_417DC0())))
			return v9 < int32(uintptr(unsafe.Pointer(v2)))
		}()) {
			v2 = sub_418A10()
			v5 = v2
			if v2 == nil {
				return
			}
			sub_418800((*wchar2_t)(unsafe.Pointer(v2)), (*wchar2_t)(unsafe.Pointer(uintptr(a1+2072))), 0)
			sub_418830(int32(uintptr(unsafe.Pointer(v5))), int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 2068)))))
			sub_4184D0((*nox_team_t)(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(v5)))))
			v6 = v1 + 48
			v7 = nox_xxx_servObjectHasTeam_419130(v1 + 48)
		} else {
			return
		}
	}
	if v7 != 0 {
		sub_4196D0(unsafe.Pointer(uintptr(v6)), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5))))), int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 36)))), 0)
	} else {
		nox_xxx_createAtImpl_4191D0(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v5), 57))), unsafe.Pointer(uintptr(v6)), 1, int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 36)))), 0)
	}
	return
}
func sub_4DFB50(a1 int32, a2 int32) {
	*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) |= 8
	nox_xxx_aud_501960(75, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
}
func sub_4DFB80(a1 int32, a2 int32) {
	if nox_xxx_enchantItemTestInventory_4DFBB0(a2, 8) == 0 {
		*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) &= 0xF7
	}
	nox_xxx_aud_501960(76, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
}
func nox_xxx_enchantItemTestInventory_4DFBB0(a1 int32, a2 int8) int32 {
	var (
		v2 *uint32
		v3 int32
		v4 int32
		v5 int32
		v6 *uint8
	)
	if a1 == 0 {
		return 0
	}
	if int32(a2) == 0 {
		return 0
	}
	v2 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 504)))
	if v2 == nil {
		return 0
	}
	for {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4)))
		if v3&0x100 != 0 {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2))&0x13001000 != 0 {
				v4 = 0
				v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*173)))
				for {
					if *(*uint32)(unsafe.Pointer(uintptr(v5))) != 0 {
						v6 = (*uint8)(memmap.PtrOff(0x587000, 200164))
						for *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5))) + 112))) != *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), -int(4*1)))) || int32(a2) != int32(*v6) {
							v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 20))
							if int32(uintptr(unsafe.Pointer(v6))) >= int32(uintptr(memmap.PtrOff(0x587000, 200284))) {
								goto LABEL_12
							}
						}
						return 1
					}
				LABEL_12:
					v4++
					v5 += 4
					if v4 >= 4 {
						goto LABEL_13
					}
				}
			}
		}
	LABEL_13:
		v2 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*124)))))
		if v2 == nil {
			return 0
		}
	}
}
func nox_xxx_effectSpeedEngage_4DFC30(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 int32
		v5 int32
	)
	v2 = a2
	if a2 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
			*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) |= 0x10
			*(*float32)(unsafe.Pointer(&v5)) = *(*float32)(unsafe.Pointer(uintptr(a1 + 120))) + *(*float32)(unsafe.Pointer(uintptr(a2 + 552)))
			*(*float32)(unsafe.Pointer(uintptr(v2 + 552))) = *(*float32)(unsafe.Pointer(&v5))
			nox_xxx_netReportStatsSpeed_4D9360(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2064)))), (*uint32)(unsafe.Pointer(uintptr(v2))), 0, v5)
			nox_xxx_aud_501960(59, (*server.Object)(unsafe.Pointer(uintptr(v2))), 0, 0)
		}
	}
}
func nox_xxx_effectSpeedDisengage_4DFCA0(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 int32
		v4 int32
	)
	v2 = a2
	if a2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
		if nox_xxx_enchantItemTestInventory_4DFBB0(a2, 16) == 0 {
			*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) &= 0xEF
		}
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
		*(*float32)(unsafe.Pointer(&v4)) = *(*float32)(unsafe.Pointer(uintptr(a2 + 552))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 120)))
		*(*float32)(unsafe.Pointer(uintptr(v2 + 552))) = *(*float32)(unsafe.Pointer(&v4))
		nox_xxx_netReportStatsSpeed_4D9360(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2064)))), (*uint32)(unsafe.Pointer(uintptr(v2))), 0, v4)
		nox_xxx_aud_501960(60, (*server.Object)(unsafe.Pointer(uintptr(v2))), 0, 0)
	}
}
func sub_4DFD10(a1 int32, a2 int32) {
	*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) |= 1
	nox_xxx_aud_501960(102, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
}
func nox_xxx_modifFireProtection_4DFD40(a1 int32, a2 int32, a3 int32) {
	if a2 != 0 && a3 != 0 {
		if nox_xxx_enchantItemTestInventory_4DFBB0(a2, 1) == 0 {
			*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) &= 0xFE
		}
		nox_xxx_aud_501960(103, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
	}
}
func nox_xxx_buff_4DFD80(a1 int32, a2 int32) {
	*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) |= 4
	nox_xxx_aud_501960(106, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
}
func sub_4DFDB0(a1 int32, a2 int32) {
	if nox_xxx_enchantItemTestInventory_4DFBB0(a2, 4) == 0 {
		*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) &= 0xFB
	}
	nox_xxx_aud_501960(107, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
}
func nox_xxx_checkPoisonProtectEnch_4DFDE0(a1 int32, a2 int32) {
	*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) |= 2
	nox_xxx_aud_501960(110, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
}
func sub_4DFE10(a1 int32, a2 int32) {
	if nox_xxx_enchantItemTestInventory_4DFBB0(a2, 2) == 0 {
		*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) &= 0xFD
	}
	nox_xxx_aud_501960(111, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
}
func nox_xxx_checkFireProtect_4DFE40(a1 *uint32) float64 {
	var (
		v1     float64
		result float64
		v3     *uint32
		v4     int32
		v5     *int32
		v6     int32
		v7     int32
		v8     *int32
		v9     int32
		v10    int32
		v11    uint8
		v12    float32
	)
	v1 = 0.0
	v12 = 0.0
	if a1 == nil {
		return 0.0
	}
	v3 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*126)))))
	if v3 != nil {
		for {
			v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*4)))
			if v4&0x100 != 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2))&0x13001000 != 0 {
				v5 = (*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*173)))))
				v6 = 4
				for {
					v7 = *v5
					if *v5 != 0 && *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v7 + 112))) == ccall.FuncAddr(sub_4DFD10) {
						v1 = v1 + float64(*(*float32)(unsafe.Pointer(uintptr(v7 + 120))))
					}
					v5 = (*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
					v6--
					if v6 == 0 {
						break
					}
				}
			}
			v3 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*124)))))
			if v3 == nil {
				break
			}
		}
		v12 = float32(v1)
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))&0x13001000 != 0 {
		v8 = (*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*173)))))
		v9 = 4
		for {
			v10 = *v8
			if *v8 != 0 && *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v10 + 112))) == ccall.FuncAddr(sub_4DFD10) {
				v1 = v1 + float64(*(*float32)(unsafe.Pointer(uintptr(v10 + 120))))
			}
			v8 = (*int32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
			v9--
			if v9 == 0 {
				break
			}
		}
		v12 = float32(v1)
	}
	if v1 > 0.5 {
		v12 = 0.5
	}
	if nox_xxx_testUnitBuffs_4FF350((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 17) != 0 {
		v11 = uint8(nox_xxx_buffGetPower_4FF570((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 17))
		result = nox_xxx_gamedataGetFloatTable_419D70(internCStr("FireSpellProtection"), int32(uint32(v11)-1)) + float64(v12)
	} else {
		result = float64(v12)
	}
	if result > 0.60000002 {
		result = 0.60000002
	}
	return result
}
func nox_xxx_checkElectrProtect_4DFF40(a1 *uint32) float64 {
	var (
		v1     float64
		result float64
		v3     *uint32
		v4     int32
		v5     *int32
		v6     int32
		v7     int32
		v8     *int32
		v9     int32
		v10    int32
		v11    uint8
		v12    float32
	)
	v1 = 0.0
	v12 = 0.0
	if a1 == nil {
		return 0.0
	}
	v3 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*126)))))
	if v3 != nil {
		for {
			v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*4)))
			if v4&0x100 != 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2))&0x13001000 != 0 {
				v5 = (*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*173)))))
				v6 = 4
				for {
					v7 = *v5
					if *v5 != 0 && *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v7 + 112))) == ccall.FuncAddr(nox_xxx_buff_4DFD80) {
						v1 = v1 + float64(*(*float32)(unsafe.Pointer(uintptr(v7 + 120))))
					}
					v5 = (*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
					v6--
					if v6 == 0 {
						break
					}
				}
			}
			v3 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*124)))))
			if v3 == nil {
				break
			}
		}
		v12 = float32(v1)
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))&0x13001000 != 0 {
		v8 = (*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*173)))))
		v9 = 4
		for {
			v10 = *v8
			if *v8 != 0 && *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v10 + 112))) == ccall.FuncAddr(nox_xxx_buff_4DFD80) {
				v1 = v1 + float64(*(*float32)(unsafe.Pointer(uintptr(v10 + 120))))
			}
			v8 = (*int32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
			v9--
			if v9 == 0 {
				break
			}
		}
		v12 = float32(v1)
	}
	if v1 >= 0.5 {
		v12 = 0.5
	}
	if nox_xxx_testUnitBuffs_4FF350((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 20) != 0 {
		v11 = uint8(nox_xxx_buffGetPower_4FF570((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 20))
		result = nox_xxx_gamedataGetFloatTable_419D70(internCStr("ElectricitySpellProtection"), int32(uint32(v11)-1)) + float64(v12)
	} else {
		result = float64(v12)
	}
	if result > 0.60000002 {
		result = 0.60000002
	}
	return result
}
func nox_xxx_getPoisonDmg_4E0040(a1 *uint32) float64 {
	var (
		v1     float64
		result float64
		v3     *uint32
		v4     int32
		v5     *int32
		v6     int32
		v7     int32
		v8     *int32
		v9     int32
		v10    int32
		v11    uint8
		v12    float32
	)
	v1 = 0.0
	v12 = 0.0
	if a1 == nil {
		return 0.0
	}
	v3 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*126)))))
	if v3 != nil {
		for {
			v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*4)))
			if v4&0x100 != 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2))&0x13001000 != 0 {
				v5 = (*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*173)))))
				v6 = 4
				for {
					v7 = *v5
					if *v5 != 0 && *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v7 + 112))) == ccall.FuncAddr(nox_xxx_checkPoisonProtectEnch_4DFDE0) {
						v1 = v1 + float64(*(*float32)(unsafe.Pointer(uintptr(v7 + 120))))
					}
					v5 = (*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
					v6--
					if v6 == 0 {
						break
					}
				}
			}
			v3 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*124)))))
			if v3 == nil {
				break
			}
		}
		v12 = float32(v1)
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))&0x13001000 != 0 {
		v8 = (*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*173)))))
		v9 = 4
		for {
			v10 = *v8
			if *v8 != 0 && *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v10 + 112))) == ccall.FuncAddr(nox_xxx_checkPoisonProtectEnch_4DFDE0) {
				v1 = v1 + float64(*(*float32)(unsafe.Pointer(uintptr(v10 + 120))))
			}
			v8 = (*int32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
			v9--
			if v9 == 0 {
				break
			}
		}
		v12 = float32(v1)
	}
	if v1 > 0.69999999 {
		v12 = 0.69999999
	}
	if nox_xxx_testUnitBuffs_4FF350((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 18) != 0 {
		v11 = uint8(nox_xxx_buffGetPower_4FF570((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 18))
		result = nox_xxx_gamedataGetFloatTable_419D70(internCStr("PoisonSpellProtection"), int32(uint32(v11)-1)) + float64(v12)
	} else {
		result = float64(v12)
	}
	if result > 0.89999998 {
		result = 0.89999998
	}
	return result
}
func sub_4E0140(a1 int32, a2 int32) {
	*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) |= 0x20
	nox_xxx_aud_501960(123, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
}
func sub_4E0170(a1 int32, a2 int32) {
	if a2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
		if nox_xxx_enchantItemTestInventory_4DFBB0(a2, 32) == 0 {
			*(*uint8)(unsafe.Pointer(uintptr(a2 + 440))) &= 0xDF
		}
		nox_xxx_aud_501960(124, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
	}
}
func nox_xxx_effectRegeneration_4E01D0(a1 int32, a2 int32) {
	var (
		v2 *uint32
		v3 uint16
		v4 uint32
		v5 int32
	)
	if a2 != 0 {
		v2 = *(**uint32)(unsafe.Pointer(uintptr(a2 + 492)))
		if v2 != nil {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*139)) != 0 {
				if (gameFrame()-*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*134))) >= uint32(int32(gameFPS())) && (*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4))&0x8020) == 0 {
					v3 = uint16(nox_xxx_unitGetMaxHP_4EE7A0(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 492))))))
					if int32(uint16(nox_xxx_unitGetHP_4EE780((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2))))))))) < int32(v3) {
						v4 = *(*uint32)(unsafe.Pointer(uintptr(a1 + 108)))
						if *(*uint32)(unsafe.Pointer(uintptr(a2 + 8)))&0x2000000 != 0 {
							v5 = nox_xxx_unitArmorInventoryEquipFlags_415C70((*server.Object)(unsafe.Pointer(uintptr(a2))))
							if v5&0x4000 != 0 {
								v4 /= 3
							}
						}
						if (gameFrame() % (v4 * gameFPS() / uint32(uint16(nox_xxx_unitGetMaxHP_4EE7A0(int32(uintptr(unsafe.Pointer(v2)))))))) == 0 {
							nox_xxx_unitAdjustHP_4EE460((*server.Object)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), 1)
						}
					}
				}
			}
		}
	}
}
func nox_xxx_attribContinualReplen_4E02C0(a1 int32, a2 *uint32) {
	var (
		v2 int32
		v3 int32
		v4 uint8
		v5 uint8
		v6 int32
		v7 int32
		v8 int32
	)
	if a2 != nil {
		if (gameFrame() % *(*uint32)(unsafe.Pointer(uintptr(a1 + 108)))) == 0 {
			v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*2)))
			v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*184)))
			if v2&0x1000 != 0 {
				v4 = *(*uint8)(unsafe.Pointer(uintptr(v3 + 108)))
				v5 = *(*uint8)(unsafe.Pointer(uintptr(v3 + 109)))
				v6 = int32(func() uint8 {
					p := &v4
					x := *p
					*p++
					return x
				}())
				*(*uint8)(unsafe.Pointer(uintptr(v3 + 108))) = v4
				if int32(v4) > int32(v5) {
					*(*uint8)(unsafe.Pointer(uintptr(v3 + 108))) = v5
				}
				v7 = int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 108))))
				if v6 != v7 {
					v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*123)))
					if v8 != 0 {
						if int32(*(*uint8)(unsafe.Pointer(uintptr(v8 + 8))))&4 != 0 {
							nox_xxx_netReportCharges_4D82B0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v8 + 748))) + 276))) + 2064)))), (*server.Object)(unsafe.Pointer(a2)), int8(v7), int8(v5))
						}
					}
				}
			}
		}
	}
}
func sub_4E0370(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 *float32) *float32 {
	var result *float32
	result = a6
	*a6 = *(*float32)(unsafe.Pointer(uintptr(a1 + 80))) * *a6
	return result
}
func sub_4E0380(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 *float32) *float32 {
	var result *float32
	result = a6
	*a6 = float32((1.0 - float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) + 1.0) * float64(*a6))
	return result
}
func nox_xxx_inversionEffect_4E03D0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 *int32) int32 {
	var result int32
	result = bool2int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 96))) >= 1)
	*a6 = result
	return result
}
func nox_xxx_unusedCheckGripEffect_4E03F0(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4  int32
		v5  int32
		v6  *uint32
		v7  int32
		v8  func(int32, int32, int32, int32, int32, *int32) int32
		v9  bool
		i   *uint32
		v12 int32
	)
	v4 = a3
	if a3 == 0 || (*(*uint32)(unsafe.Pointer(uintptr(a3 + 8)))&0x3001000) == 0 {
		return 0
	}
	v5 = a4
	v6 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a3 + 692))) + 8)))
	v12 = 2
	for i = v6; ; i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
		v7 = int32(*v6)
		if v7 != 0 {
			v8 = ccall.AsFunc[func(int32, int32, int32, int32, int32, *int32) int32](unsafe.Pointer(uintptr(v7 + 88)))
			if ccall.FuncAddr(v8) == ccall.FuncAddr(nox_xxx_gripEffect_4E0480) {
				v8(v7, v4, a2, v5, a1, &a4)
				if a4 == 0 {
					break
				}
			}
		}
		v6 = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1))
		v9 = func() int32 {
			p := &v12
			*p++
			return *p
		}() < 4
		if !v9 {
			return 0
		}
	}
	return 1
}
func nox_xxx_gripEffect_4E0480(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 *int32) int32 {
	var result int32
	result = bool2int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 96))) < 1)
	*a6 = result
	return result
}
func nox_xxx_effectDamageMultiplier_4E04C0(a1 int32, a2 int32, a3 int32, a4 int32, a5 *float32) *float32 {
	var result *float32
	result = a5
	*a5 = *(*float32)(unsafe.Pointer(uintptr(a1 + 44))) * *a5
	return result
}
func nox_xxx_stunEffect_4E04D0(a1 int32, a2 int32, a3 int32, a4 int32) {
	var (
		v4 int32
		v5 int32
		v6 int32
		v8 int32
		v9 [3]int32
	)
	v4 = a4
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a4 + 8))))&6 != 0 {
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a4 + 60))))
		v9[1] = int32(*(*uint32)(unsafe.Pointer(uintptr(a4 + 56))))
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 60))))
		v9[2] = v5
		v9[0] = a4
		nox_xxx_castStun_52C2C0(74, a3, a3, a3, &v9[0], int8(v6))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 8))))&4 != 0 {
			v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 748))))
			a4 = 0
			nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v8 + 276))) + 2064)))), 13, &a4)
		}
	}
}
func nox_xxx_recoilEffect_4E0640(a1 int32, a2 int32, a3 int32, a4 int32) {
	if a2 != 0 {
		if a4 != 0 {
			nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(a2+56))), (*server.Object)(unsafe.Pointer(uintptr(a4))), *(*float32)(unsafe.Pointer(uintptr(a1 + 56))))
		}
	}
}
func nox_xxx_confuseEffect_4E0670(a1 int32, a2 int32, a3 int32, a4 int32) {
	var (
		v4 int32
		v5 int32
		v6 int32
		v8 int32
		v9 [3]int32
	)
	v4 = a4
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a4 + 8))))&6 != 0 {
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a4 + 60))))
		v9[1] = int32(*(*uint32)(unsafe.Pointer(uintptr(a4 + 56))))
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 60))))
		v9[2] = v5
		v9[0] = a4
		nox_xxx_castConfuse_52C1E0(12, a3, a3, a3, &v9[0], int8(v6))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 8))))&4 != 0 {
			v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 748))))
			a4 = 1
			nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v8 + 276))) + 2064)))), 13, &a4)
		}
	}
}
func nox_xxx_lightngEffect_4E06F0(a1 int32, a2 int32, a3 int32, a4 int32) {
	if a4 != 0 {
		ccall.AsFunc[func(int32, int32, int32, uint32, int32)](unsafe.Pointer(uintptr(a4+716)))(a4, a3, a2, uint32(int32(int64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))))), 9)
		nox_xxx_netSendPointFx_522FF0(-127, (*float2)(unsafe.Pointer(uintptr(a4+56))))
		nox_xxx_aud_501960(225, (*server.Object)(unsafe.Pointer(uintptr(a4))), 0, 0)
	}
}
func nox_xxx_drainMEffect_4E0740(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32) {
	var (
		v5 int32
		v6 uint16
		v7 int16
	)
	if a3 != 0 && a4 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a4 + 8))))&6 != 0 {
		v5 = int32(int64(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 68)))) * float64(*a5)))
		if v5 == 0 {
			v5 = 1
		}
		v6 = uint16(nox_xxx_unitGetOldMana_4EEC80(a4))
		v7 = int16(v6)
		if int32(v6) < v5 {
			nox_xxx_playerManaSub_4EEBF0(a4, int32(v6))
			nox_xxx_playerManaAdd_4EEB80((*server.Object)(unsafe.Pointer(uintptr(a3))), v7)
		} else {
			nox_xxx_playerManaSub_4EEBF0(a4, v5)
			nox_xxx_playerManaAdd_4EEB80((*server.Object)(unsafe.Pointer(uintptr(a3))), int16(v5))
		}
	}
}
func nox_xxx_vampirismEffect_4E07C0(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32) {
	var (
		v5 int32
		v6 int32
		v7 int32
	)
	if a3 != 0 {
		if a4 != 0 {
			v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a4 + 8))))
			if v5&6 != 0 {
				if (v5&2) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a4 + 12))))&0x40) == 0 {
					v6 = int32(int64(float64(*a5) * float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 68))))))
					if v6 == 0 {
						v6 = 1
					}
					v7 = int32(uint16(nox_xxx_unitGetHP_4EE780((*server.Object)(unsafe.Pointer(uintptr(a4))))))
					if v7 < v6 {
						nox_xxx_unitAdjustHP_4EE460((*server.Object)(unsafe.Pointer(uintptr(a3))), v7)
					} else {
						nox_xxx_unitAdjustHP_4EE460((*server.Object)(unsafe.Pointer(uintptr(a3))), v6)
					}
				}
			}
		}
	}
}
func nox_xxx_poisonEffect_4E0850(a1 int32, a2 int32, a3 int32, a4 int32) {
	var (
		v4 int32
		v5 int32
	)
	v4 = a4
	if ((int32(*(*uint8)(unsafe.Pointer(uintptr(a4 + 8))))&4) == 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a4 + 748))) + 88)))) != 16 || (nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(a4+56))), int32(*(*int16)(unsafe.Pointer(uintptr(a4 + 124)))), (*float2)(unsafe.Pointer(uintptr(a3+56))))&1) == 0) && int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 8))))&6 != 0 && nox_xxx_activatePoison_4EE7E0(v4, 1, int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 72))))) != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 8))))&4 != 0 {
			v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 748))))
			a4 = 2
			nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 2064)))), 13, &a4)
		}
	}
}
func nox_xxx_sympathyEffect_4E08E0(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32) {
	var (
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 float32
	)
	v5 = a3
	if a3 != 0 && a4 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a4 + 8))))&6 != 0 {
		v8 = a4
		v10 = *(*float32)(unsafe.Pointer(uintptr(a1 + 68)))
		v6 = *a5
		v9 = *a5
		v7 = int32(uint16(nox_xxx_unitGetHP_4EE780((*server.Object)(unsafe.Pointer(uintptr(v8))))))
		if v7 < v6 {
			v9 = v7
		}
		nox_xxx_unitDamageClear_4EE5E0((*server.Object)(unsafe.Pointer(uintptr(v5))), int32(int64(float64(v9)*float64(v10))))
	}
}
func nox_xxx_itemCheckReadinessEffect_4E0960(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		i  int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))))
	if a1 == 0 || (*(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x13001000) == 0 {
		return 0
	}
	v2 = 2
	for i = v1 + 8; *(*uint32)(unsafe.Pointer(uintptr(i))) == 0 || unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i)))+40)) != ccall.FuncAddr(nullsub_22); i += 4 {
		if func() int32 {
			p := &v2
			*p++
			return *p
		}() >= 4 {
			return 0
		}
	}
	return int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + v2*4))) + 48))))
}
func nox_xxx_effectProjectileSpeed_4E09B0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var result int32
	result = a5
	*(*float32)(unsafe.Pointer(uintptr(a5 + 544))) = *(*float32)(unsafe.Pointer(uintptr(a1 + 44))) * *(*float32)(unsafe.Pointer(uintptr(a5 + 544)))
	return result
}
func nox_xxx_parseDamageTypeByName_4E0A00(a1 *byte) int32 {
	var (
		v1 int32
		v2 **byte
	)
	v1 = 0
	v2 = (**byte)(memmap.PtrOff(0x587000, 200728))
	for {
		if libc.StrCmp(a1, *v2) == 0 {
			break
		}
		v2 = (**byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((*byte)(nil))*1))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 200800))) {
			break
		}
	}
	return v1
}
func nox_xxx_projectileReflect_4E0A70(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     float64
		v4     float64
		v5     int16
		v6     float64
		v7     float64
		v8     int32
		v9     float32
		v10    float32
		v11    float32
		v12    float32
		v13    float32
	)
	result = a1
	v3 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56))) - *(*float32)(unsafe.Pointer(uintptr(a2 + 56))))
	v4 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a2 + 60))))
	*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))) += 128
	v5 = int16(*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))))
	v11 = float32(-v4)
	v13 = float32(math.Sqrt(v4*v4+v3*v3) + 0.1)
	v6 = (v4*float64(*(*float32)(unsafe.Pointer(uintptr(result + 84)))) + v3*float64(*(*float32)(unsafe.Pointer(uintptr(result + 80))))) / float64(v13)
	v9 = float32(v6 * v3 / float64(v13))
	v10 = float32(v6 * v4 / float64(v13))
	v7 = (float64(v11**(*float32)(unsafe.Pointer(uintptr(result + 80)))) + v3*float64(*(*float32)(unsafe.Pointer(uintptr(result + 84))))) / float64(v13)
	v12 = float32(v7 * float64(v11) / float64(v13))
	*(*float32)(unsafe.Pointer(uintptr(result + 80))) = v12 - v9
	*(*float32)(unsafe.Pointer(uintptr(result + 84))) = float32(v3*v7/float64(v13) - float64(v10))
	if int32(v5) >= 256 {
		*(*uint16)(unsafe.Pointer(uintptr(result + 124))) = uint16(int16(int32(v5) - 256))
	}
	v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(result + 76))))
	*(*uint32)(unsafe.Pointer(uintptr(result + 64))) = *(*uint32)(unsafe.Pointer(uintptr(result + 72)))
	*(*uint32)(unsafe.Pointer(uintptr(result + 68))) = uint32(v8)
	return result
}
func nox_xxx_damageDefaultProc_4E0B30(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 float64
		v17 float64
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
		v23 int8
		v24 *uint32
		v25 int32
		v26 int32
		v27 int32
		v28 int32
		v29 func(int32, int32)
		v30 uint8
		v31 float64
		v32 uint16
		v33 int32
		v34 float32
		v35 int32
		v36 float32
		v37 int8
		v38 int32
		v39 int32
		v40 int32
		v41 float32
		v42 float32
		v43 float32
		v44 float32
		v45 [4]int32
		v46 float32
		v47 float32
	)
	if a1 == 0 {
		return 1
	}
	if nox_xxx_testUnitBuffs_4FF350((*server.Object)(unsafe.Pointer(uintptr(a1))), 23) != 0 {
		if (int32(uint8(gameFrame())) & 3) == 0 {
			nox_xxx_aud_501960(71, (*server.Object)(unsafe.Pointer(uintptr(a1))), 0, 0)
			return 1
		}
		return 1
	}
	v6 = a5
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&2 != 0 {
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		*(*uint32)(unsafe.Pointer(uintptr(v7 + 2188))) = 0
		if v6 == 1 || v6 == 12 || v6 == 7 || v6 == 14 || v6 == 6 {
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 1440))) |= 0x80000
		}
	}
	v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	if (v8 & 0x8000) != 0 {
		if nox_xxx_unitIsZombie_534A40(a1) == 0 {
			return 1
		}
		v9 = a3
		if a3 == 0 {
			v9 = a2
		}
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 520))) = uint32(v9)
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 524))) = uint32(v6)
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 536))) = gameFrame()
		return 1
	}
	v10 = a2
	if !nox_xxx_CheckGameplayFlags_417DA0(1) {
		v11 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*server.Object)(unsafe.Pointer(uintptr(a2)))))))
		v12 = v11
		if v11 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v11 + 8))))&6 != 0 && nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(unsafe.Pointer(uintptr(a1))), (*server.Object)(unsafe.Pointer(uintptr(v11)))) == 0 && (a1 != v12 || noxflags.HasGame(4096)) {
				return 1
			}
		}
	}
	if a2 != 0 && a3 != 0 && nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(unsafe.Pointer(uintptr(a1))), (*server.Object)(unsafe.Pointer(uintptr(a2)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&6 != 0 && sub_4E1400(a2, (*uint32)(unsafe.Pointer(uintptr(a3)))) != 0 && sub_4E1470(a3) == 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16))))&2 != 0 {
		return 1
	}
	if a2 != 0 {
		if nox_xxx_testUnitBuffs_4FF350((*server.Object)(unsafe.Pointer(uintptr(a1))), 22) != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&6 != 0 {
				if a3 != 0 {
					if sub_4E1400(a2, (*uint32)(unsafe.Pointer(uintptr(a3)))) != 0 {
						nox_xxx_aud_501960(135, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
						nox_xxx_spellBuffOff_4FF5B0((*server.Object)(unsafe.Pointer(uintptr(a1))), 22)
						v41 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("ShockDamage"), 4))
						v13 = int32(v41)
						ccall.AsFunc[func(int32, int32, uint32, int32, int32)](unsafe.Pointer(uintptr(a2+716)))(a2, a1, 0, v13, 9)
						if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
							nox_xxx_playerSetState_4FA020((*server.Object)(unsafe.Pointer(uintptr(a2))), 23)
						}
					}
				}
			}
		}
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&2 != 0 {
		v14 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
		v15 = a5
		if v14&0x200 != 0 && a5 == 5 {
			return 1
		}
		if v14&0x400 != 0 {
			if a5 == 1 || a5 == 12 {
				return 1
			}
			if a5 == 7 {
				a4 /= 2
				goto LABEL_53
			}
		} else if v14&0x800 != 0 {
			if a5 == 9 {
				return 1
			}
			if a5 == 17 {
				return 1
			}
		}
	} else {
		v15 = a5
	}
	if v15 != 1 && v15 != 12 && v15 != 7 {
		goto LABEL_58
	}
LABEL_53:
	v16 = nox_xxx_checkFireProtect_4DFE40((*uint32)(unsafe.Pointer(uintptr(a1))))
	if v16 != 0.0 && (int32(uint8(gameFrame()))&3) == 0 {
		nox_xxx_aud_501960(104, (*server.Object)(unsafe.Pointer(uintptr(a1))), 0, 0)
	}
	v46 = float32(v16)
	v42 = float32((1.0 - float64(v46)) * float64(a4))
	a4 = int32(v42)
	if a4 == 0 {
		a4 = 1
	}
LABEL_58:
	if v15 == 9 || v15 == 17 {
		v17 = nox_xxx_checkElectrProtect_4DFF40((*uint32)(unsafe.Pointer(uintptr(a1))))
		if v17 != 0.0 && (int32(uint8(gameFrame()))&3) == 0 {
			nox_xxx_aud_501960(108, (*server.Object)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
		v47 = float32(v17)
		v43 = float32((1.0 - float64(v47)) * float64(a4))
		a4 = int32(v43)
		if a4 == 0 {
			a4 = 1
		}
		v18 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
		if v18&4 != 0 {
			*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 160))) = 2
		} else if v18&2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x10 != 0 {
			*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 2094))) = 2
		}
	}
	if v10 == 0 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 528))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 532))) = 0
		if v15 == 12 {
			nox_xxx_spellBuffOff_4FF5B0((*server.Object)(unsafe.Pointer(uintptr(a1))), 0)
		}
		v19 = a3
		goto LABEL_87
	}
	v19 = a3
	if a3 != 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(a3 + 8)))&0x1001000 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 528))) = *(*uint32)(unsafe.Pointer(uintptr(v10 + 72)))
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 532))) = *(*uint32)(unsafe.Pointer(uintptr(v10 + 76)))
		} else {
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 528))) = *(*uint32)(unsafe.Pointer(uintptr(a3 + 72)))
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 532))) = *(*uint32)(unsafe.Pointer(uintptr(a3 + 76)))
		}
		if a3 == v10 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&2) == 0 {
			goto LABEL_83
		}
		v20 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v21))), unsafe.Sizeof(uint16(0))*1)) = 0
		*(*uint32)(unsafe.Pointer(uintptr(v20 + 2188))) = 1
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v21))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(a3 + 4)))
	} else {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 528))) = *(*uint32)(unsafe.Pointer(uintptr(v10 + 72)))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 532))) = *(*uint32)(unsafe.Pointer(uintptr(v10 + 76)))
		if v15 != 10 && v15 != 2 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&2) == 0 {
			goto LABEL_83
		}
		v20 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v21))), unsafe.Sizeof(uint16(0))*1)) = 0
		*(*uint32)(unsafe.Pointer(uintptr(v20 + 2188))) = 1
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v21))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(v10 + 4)))
	}
	*(*uint32)(unsafe.Pointer(uintptr(v20 + 2184))) = uint32(v21)
LABEL_83:
	nox_xxx_spellBuffOff_4FF5B0((*server.Object)(unsafe.Pointer(uintptr(a1))), 0)
LABEL_87:
	v22 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	if v22&4 != 0 || v22&2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x10 != 0 {
		nox_xxx_itemApplyDefendEffect2_4E1320(a1, v10, v19, &a4, v15)
	}
	if v19 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 520))) = uint32(v19)
	} else {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 520))) = uint32(v10)
	}
	v23 = int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 524))) = uint32(v15)
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 536))) = gameFrame()
	if int32(v23)&2 != 0 {
		v24 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 748)))
		v25 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v24), 4*360)))
		v26 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v24), 4*547)))
		*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v25))), 1)) |= 2
		*(*uint32)(unsafe.Add(unsafe.Pointer(v24), 4*360)) = uint32(v25)
		if v26 == 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v24), 4*547)) = 2
			*(*uint32)(unsafe.Add(unsafe.Pointer(v24), 4*546)) = uint32(v15)
		}
	}
	if v19 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v19 + 8)))&0x1001000 != 0 {
		nox_xxx_itemApplyPreDamageEffect_4E13B0(a1, v10, v19, int32(uintptr(unsafe.Pointer(&a4))))
	}
	if a1 != v19 || (*(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1001000) == 0 {
		if v10 == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v10 + 8))))&2) == 0 || *(*uint32)(unsafe.Pointer(uintptr(v10 + 748))) == 0 || (func() int32 {
			v27 = int32(uintptr(nox_xxx_monsterGetSoundSet_424300((*server.Object)(unsafe.Pointer(uintptr(v10))))))
			return v27
		}()) == 0 || (func() int32 {
			v28 = int32(*(*uint32)(unsafe.Pointer(uintptr(v27 + 32))))
			return v28
		}()) == 0 || nox_xxx_getSevenDwords3_501940(v28) <= 0 {
			v29 = ccall.AsFunc[func(int32, int32)](unsafe.Pointer(uintptr(a1 + 720)))
			if v29 != nil {
				if v19 != 0 {
					v29(a1, v19)
				} else {
					v29(a1, v10)
				}
			} else if v19 != 0 {
				nox_xxx_soundDefaultDamageSound_532E20((*server.Object)(unsafe.Pointer(uintptr(a1))), (*server.Object)(unsafe.Pointer(uintptr(v19))))
			} else {
				nox_xxx_soundDefaultDamageSound_532E20((*server.Object)(unsafe.Pointer(uintptr(a1))), (*server.Object)(unsafe.Pointer(uintptr(v10))))
			}
		}
	}
	if v10 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&6 != 0 && nox_xxx_testUnitBuffs_4FF350((*server.Object)(unsafe.Pointer(uintptr(v10))), 13) != 0 {
		nox_xxx_aud_501960(163, (*server.Object)(unsafe.Pointer(uintptr(a3))), 0, 0)
		v30 = uint8(nox_xxx_buffGetPower_4FF570((*server.Object)(unsafe.Pointer(uintptr(v10))), 13))
		v31 = nox_xxx_gamedataGetFloatTable_419D70(internCStr("VampirismCoeff"), int32(uint32(v30)-1))
		v44 = float32(v31 * float64(a4))
		v32 = uint16(int16(int32(v44)))
		if int32(v32) < 1 {
			v32 = 1
		}
		nox_xxx_unitAdjustHP_4EE460((*server.Object)(unsafe.Pointer(uintptr(v10))), int32(v32))
		v45[0] = int32(*(*float32)(unsafe.Pointer(uintptr(v10 + 56))))
		v33 = int32(*(*float32)(unsafe.Pointer(uintptr(v10 + 60))))
		v34 = *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
		v45[1] = v33
		v35 = int32(v34)
		v36 = *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
		v45[2] = v35
		v45[3] = int32(v36)
		nox_xxx_netSendVampFx_523270(-94, (*int16)(unsafe.Pointer(&v45[0])), int16(v32))
	}
	nox_xxx_gameballOnPlayerDamage_4E1230(v10, a1, a4)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		if a4 >= 20 {
			v37 = int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 88))))
			if int32(v37) != 1 && int32(v37) != 15 {
				nox_xxx_playerSetState_4FA020((*server.Object)(unsafe.Pointer(uintptr(a1))), 30)
			}
		}
	}
	if noxflags.HasGame(6144) {
		sub_4FB050(v10, a1, &a4)
	}
	if v10 == 0 {
		goto LABEL_137
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(v10 + 8))))&2 != 0 {
		v38 = v10
	} else {
		v39 = int32(*(*uint32)(unsafe.Pointer(uintptr(v10 + 508))))
		if v39 == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v39 + 8))))&2) == 0 {
			goto LABEL_137
		}
		v38 = int32(*(*uint32)(unsafe.Pointer(uintptr(v10 + 508))))
	}
	if v38 != 0 && nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(unsafe.Pointer(uintptr(a1))), (*server.Object)(unsafe.Pointer(uintptr(v38)))) != 0 {
		sub_532880(v38)
	}
LABEL_137:
	if nox_xxx_testUnitBuffs_4FF350((*server.Object)(unsafe.Pointer(uintptr(a1))), 26) != 0 && a5 != 5 {
		v40 = a3
		if a3 == 0 {
			v40 = v10
		}
		if a5 != 15 || v10 != a1 {
			nox_xxx_unitShieldReduceDamage_52F710(a1, &a4, a5, v40)
		}
		if a4 == 0 {
			return 0
		}
	}
	nox_xxx_unitDamageClear_4EE5E0((*server.Object)(unsafe.Pointer(uintptr(a1))), a4)
	return 1
}
func nox_xxx_gameballOnPlayerDamage_4E1230(a1 int32, a2 int32, a3 int32) {
	var (
		v3 int32
		v4 int32
		v5 *byte
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 && a3 >= 30 {
		v3 = int32(*memmap.PtrUint32(0x5D4594, 1563316))
		if *memmap.PtrUint32(0x5D4594, 1563316) == 0 {
			v3 = nox_xxx_getNameId_4E3AA0(internCStr("GameBall"))
			*memmap.PtrUint32(0x5D4594, 1563316) = uint32(v3)
		}
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 516))))
		if v4 != 0 {
			for int32(*(*uint16)(unsafe.Pointer(uintptr(v4 + 4)))) != v3 {
				v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 512))))
				if v4 == 0 {
					return
				}
			}
			*(*uint32)(unsafe.Pointer(uintptr(v4 + 16))) &= 0xFFFFFFBF
			nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Pointer(uintptr(a2+56))), (*server.Object)(unsafe.Pointer(uintptr(v4))), 30.0)
			nox_xxx_unitClearOwner_4EC300((*server.Object)(unsafe.Pointer(uintptr(v4))))
			sub_4EB9B0(v4, a2)
			if nox_xxx_servObjectHasTeam_419130(v4+48) != 0 {
				v5 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 52)))))))
				if v5 != nil {
					sub_4196D0(unsafe.Pointer(uintptr(v4+48)), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5))))), int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 36)))), 0)
				}
			} else {
				nox_xxx_createAtImpl_4191D0(*(*uint8)(unsafe.Pointer(uintptr(a1 + 52))), unsafe.Pointer(uintptr(v4+48)), 1, int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 36)))), 0)
			}
			nox_xxx_aud_501960(926, (*server.Object)(unsafe.Pointer(uintptr(a2))), 0, 0)
		}
	}
}
func nox_xxx_itemApplyDefendEffect2_4E1320(a1 int32, a2 int32, a3 int32, a4 *int32, a5 int32) int32 {
	var (
		result int32
		v6     *uint32
		v7     int32
		v8     *int32
		v9     int32
		v10    int2
		v11    int32
	)
	result = a1
	v6 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 504)))
	if v6 != nil {
		v7 = a5
		for {
			result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*4)))
			if result&0x100 != 0 {
				v11 = 2
				v8 = (*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*173)) + 8)))
				for {
					v9 = *v8
					if *v8 != 0 {
						if *(*uint32)(unsafe.Pointer(uintptr(v9 + 76))) != 0 {
							v10.field_0 = *a4
							v10.field_4 = v7
							ccall.AsFunc[func(int32, *uint32, int32, int32, int32, *int2)](unsafe.Pointer(uintptr(v9+76)))(v9, v6, a1, a3, a2, &v10)
							*a4 = v10.field_0
						}
					}
					v8 = (*int32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
					result = func() int32 {
						p := &v11
						*p--
						return *p
					}()
					if v11 == 0 {
						break
					}
				}
			}
			v6 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*124)))))
			if v6 == nil {
				break
			}
		}
	}
	return result
}
func nox_xxx_itemApplyPreDamageEffect_4E13B0(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4     int32
		v5     *int32
		v6     int32
		v7     func(int32, int32, int32, int32, int32)
		result int32
		v9     int32
	)
	v4 = a3
	v9 = 4
	v5 = *(**int32)(unsafe.Pointer(uintptr(v4 + 692)))
	for {
		v6 = *v5
		if *v5 != 0 {
			v7 = ccall.AsFunc[func(int32, int32, int32, int32, int32)](unsafe.Pointer(uintptr(v6 + 64)))
			if v7 != nil {
				v7(v6, v4, a2, a1, a4)
			}
		}
		v5 = (*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
		result = func() int32 {
			p := &v9
			*p--
			return *p
		}()
		if v9 == 0 {
			break
		}
	}
	return result
}
func sub_4E1400(a1 int32, a2 *uint32) int32 {
	var (
		v2     int32
		result int32
		v4     int32
	)
	if a2 != nil {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*2)))
		if v4&0x1000 != 0 {
			if (*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)) & 0x47F0000) == 0 {
				return 1
			}
			if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*184)) + 96))))&2 != 0 {
				return 1
			}
		} else if uint32(v4)&0x1000000 != 0 && (*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3))&0x47F00FE) == 0 {
			return 1
		}
		result = (int32(uint8(int8(v4))) >> 1) & 1
	} else {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
		if v2&4 != 0 {
			return 1
		}
		result = bool2int32(v2&2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x10 != 0)
	}
	return result
}
func sub_4E1470(a1 int32) int32 {
	var (
		v1     int32
		result int32
	)
	result = 0
	if a1 != 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1000000 != 0 {
			v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
			if v1&0x4000 != 0 {
				result = 1
			}
		}
	}
	return result
}
func sub_4E14A0() int32 {
	return 0
}
func sub_4E14B0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var result int32
	if a1 != 0 && *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1001000 != 0 && (*(*uint32)(unsafe.Pointer(uintptr(a1 + 492))) != 0 || a5 == 12) {
		result = nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, a4, a5)
	} else {
		result = 0
	}
	return result
}
func nox_xxx_damageArmor_4E1500(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		v5     int32
		result int32
	)
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x2000000 != 0 && (*(*uint32)(unsafe.Pointer(uintptr(a1 + 492))) != 0 || a5 == 12) && (func() int32 {
		if a5 != 2 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 24))))&0x10) == 0 {
			v5 = a4
		} else {
			v5 = a4 * 2
		}
		return v5
	}()) != 0 {
		result = nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, v5, a5)
	} else {
		result = 0
	}
	return result
}
func nox_xxx_playerDamageWeapon_4E1560(a1 int32, a2 int32, a3 int32, a4 int32, a5 float32, a6 int32) {
	var (
		v6  *float32
		v7  int32
		v8  func(int32, int32, int32, int32, int32, *float32)
		v9  int32
		v10 uint16
		v11 uint16
	)
	if a1 != 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 556))) != 0 {
			v6 = *(**float32)(unsafe.Pointer(uintptr(a1 + 748)))
			if (*(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1000000) == 0 || (*(*uint32)(unsafe.Pointer(uintptr(a1 + 12)))&0x7800000) == 0 {
				v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))) + 4))))
				if v7 != 0 {
					v8 = ccall.AsFunc[func(int32, int32, int32, int32, int32, *float32)](unsafe.Pointer(uintptr(v7 + 76)))
					if v8 != nil {
						v8(v7, a1, a2, a4, a3, &a5)
					}
				}
				a5 = a5 + *v6
				v9 = int32(a5)
				*v6 = float32(float64(a5) - float64(v9))
				if v9 > 0 {
					v10 = **(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
					ccall.AsFunc[func(int32, int32, int32, int32, int32)](unsafe.Pointer(uintptr(a1+716)))(a1, a3, a4, v9, a6)
					if a2 != 0 {
						if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
							v11 = **(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
							if int32(v10) != int32(v11) {
								nox_xxx_itemDestroyed_4E1650(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))) + 276))) + 2064)))), (*uint32)(unsafe.Pointer(uintptr(a1))), v10, v11)
							}
						}
					}
				}
			}
		}
	}
}
func nox_xxx_itemDestroyed_4E1650(a1 int32, a2 *uint32, a3 uint16, a4 uint16) int32 {
	var (
		result int32
		v5     int32
	)
	result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*139)))
	if result != 0 {
		if noxflags.HasGame(2048) {
			result = nox_xxx_itemReportHealth_4D87A0(a1, (*server.Object)(unsafe.Pointer(a2)))
		} else {
			v5 = sub_57B190(a3, *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*139)) + 4))))
			result = sub_57B190(a4, *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*139)) + 4))))
			if v5 != result {
				result = nox_xxx_itemReportHealth_4D87A0(a1, (*server.Object)(unsafe.Pointer(a2)))
			}
		}
	}
	return result
}
func nox_xxx_equipDamage_4E16D0(a1 int32, a2 int32, a3 int32, a4 int32, a5 float32, a6 int32) {
	var (
		v6  *float32
		v7  int32
		v8  func(int32, int32, int32, int32, int32, *float32)
		v9  int32
		v10 uint16
		v11 uint16
	)
	if a1 != 0 && *(*uint32)(unsafe.Pointer(uintptr(a1 + 556))) != 0 {
		v6 = *(**float32)(unsafe.Pointer(uintptr(a1 + 748)))
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))) + 4))))
		if v7 != 0 {
			v8 = ccall.AsFunc[func(int32, int32, int32, int32, int32, *float32)](unsafe.Pointer(uintptr(v7 + 76)))
			if v8 != nil {
				v8(v7, a1, a2, a4, a3, &a5)
			}
		}
		a5 = a5 + *v6
		v9 = int32(a5)
		*v6 = float32(float64(a5) - float64(v9))
		if v9 > 0 {
			v10 = **(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
			ccall.AsFunc[func(int32, int32, int32, int32, int32)](unsafe.Pointer(uintptr(a1+716)))(a1, a3, a4, v9, a6)
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
				v11 = **(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
				if int32(v10) != int32(v11) {
					nox_xxx_itemDestroyed_4E1650(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))) + 276))) + 2064)))), (*uint32)(unsafe.Pointer(uintptr(a1))), v10, v11)
				}
			}
		}
	}
}
