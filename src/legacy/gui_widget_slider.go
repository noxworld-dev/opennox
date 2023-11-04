package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type nox_slider_data struct {
	field0  int32
	field4  int32
	field8  int32
	field12 int32
}

func nox_gui_newSlider_4B4EE0(par *gui.Window, a2 gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, opts *nox_slider_data) *gui.Window {
	var win *gui.Window
	if draw.Style.IsHorizSlider() {
		win = nox_window_new(par, a2|gui.StatusTabStop, px, py, w, h, sub_4B5010)
		sub_4B51A0(win)
	} else if draw.Style.IsVertSlider() {
		win = nox_window_new(par, a2|gui.StatusTabStop, px, py, w, h, nox_xxx_wndScrollBoxProc_4B5320)
		nox_xxx_wndScrollBoxSetAllFn_4B5500(win, nil)
	}
	if win == nil {
		return nil
	}
	if draw.Window == nil {
		draw.Window = win
	}
	nox_gui_windowCopyDrawData_46AF80(win, draw)
	nox_xxx_wndScrollBoxButtonCreate_4B5640(win, a2|gui.StatusTabStop, draw)
	v11 := int32(*(*uint32)(unsafe.Pointer(opts)))
	if opts.field4 == opts.field0 {
		opts.field4 = v11 + 1
	}
	var v12 float64
	if draw.Style&0x10 != 0 {
		v12 = float64(w-10) / float64(opts.field4-v11)
	} else {
		v12 = float64(h-10) / float64(opts.field4-v11)
	}
	opts.field8 = int32(float32(v12))
	d, _ := alloc.New(nox_slider_data{})
	*d = *opts
	win.WidgetData = unsafe.Pointer(d)
	return win
}
func sub_4B51A0(a1 *gui.Window) {
	if a1 == nil {
		return
	}
	if int32(int8(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))) >= 0 {
		nox_window_set_all_funcs(a1, sub_4B4860, sub_4B51E0, nil)
	} else {
		nox_window_set_all_funcs(a1, sub_4B4860, sub_4B52C0, nil)
	}
}
func nox_xxx_wndScrollBoxButtonCreate_4B5640(a1 *gui.Window, a2 gui.StatusFlags, a3 *gui.WindowData) {
	var (
		v6 [332]byte
	)
	v3 := a3.TextColorVal
	*(*uint32)(unsafe.Pointer(&v6[0])) = 0
	libc.MemSet(unsafe.Pointer(&v6[4]), 0, 0x148)
	v4 := a2
	*(*unsafe.Pointer)(unsafe.Pointer(&v6[16])) = a1.C()
	*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(a2&0xEF | 0xC))
	*(*uint32)(unsafe.Pointer(&v6[8])) = 1
	*(*uint32)(unsafe.Pointer(&v6[68])) = uint32(v3)
	if (v4 & 0x80) == 0 {
		*(*uint32)(unsafe.Pointer(&v6[52])) = a3.SelColorVal
		*(*uint32)(unsafe.Pointer(&v6[28])) = a3.BgColorVal
		*(*uint32)(unsafe.Pointer(&v6[20])) = a3.EnColorVal
	} else {
		*(*uint32)(unsafe.Pointer(&v6[32])) = a3.EnImageHnd
		*(*uint32)(unsafe.Pointer(&v6[48])) = a3.DisImageHnd
		*(*uint32)(unsafe.Pointer(&v6[56])) = a3.SelImageHnd
		*(*uint32)(unsafe.Pointer(&v6[24])) = a3.BgImageHnd
		*(*uint32)(unsafe.Pointer(&v6[40])) = a3.HlImageHnd
	}
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a3), 8)))&0x10 != 0 {
		nox_gui_newButtonOrCheckbox_4A91A0(a1, v4, 0, 0, 10, a1.SizeVal.Y, (*gui.WindowData)(unsafe.Pointer(&v6[0])))
	} else {
		nox_gui_newButtonOrCheckbox_4A91A0(a1, v4, 0, 0, a1.SizeVal.X, 10, (*gui.WindowData)(unsafe.Pointer(&v6[0])))
	}
}
func nox_xxx_wndScrollBoxSetAllFn_4B5500(win *gui.Window, draw *gui.WindowData) {
	if win == nil {
		return
	}
	if int32(int8(*(*uint8)(unsafe.Add(unsafe.Pointer(win), 4)))) >= 0 {
		nox_window_set_all_funcs(win, nox_xxx_wndScrollBoxDraw_4B4BA0, nox_xxx_wndScrollBoxDraw_4B5540, nil)
	} else {
		nox_window_set_all_funcs(win, nox_xxx_wndScrollBoxDraw_4B4BA0, nox_xxx_wndScrollBoxDraw_4B5620, nil)
	}
}

func sub_4B5010(win *gui.Window, a2, a3p, a4p uintptr) uintptr {
	var (
		a1p = win
		v6  int32
		v7  int32
		v8  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int64
		v14 int32
		v15 int32
		v16 int32
		v17 float64
	)
	v4 := a1p
	v5 := a1p.WidgetData
	if a2 > 0x4000 {
		if a2 == 16394 {
			if int32(a3p) >= *(*int32)(v5) && int32(a3p) <= *(*int32)(unsafe.Add(v5, 4)) {
				v17 = float64(a3p)
				*(*uint32)(unsafe.Add(v5, 12)) = uint32(a3p)
				nox_window_setPos_46A9B0(v4.Field100Ptr, int32(int64(v17*float64(*(*float32)(unsafe.Add(v5, 8))))), 0)
			}
		} else if a2 == 16395 {
			v14 = int32(a3p)
			v15 = int32(a4p)
			*(*uint32)(v5) = uint32(a3p)
			*(*uint32)(unsafe.Add(v5, 4)) = uint32(v15)
			v16 = int32(v4.SizeVal.X - 10)
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(v14)
			*(*float32)(unsafe.Add(v5, 8)) = float32(float64(v16) / float64(v15-v14))
			nox_window_setPos_46A9B0(v4.Field100Ptr, 0, 0)
			return 0
		}
		return 0
	}
	if a2 == 0x4000 {
		v10 = int32(uint16(int16(a4p)))
		var a1, a3 int32
		nox_client_wndGetPosition_46AA60(a1p, &a3, &a1)
		if v10 < int32(a3) {
			nox_window_setPos_46A9B0(v4.Field100Ptr, 0, 0)
			v11 = int32(*(*uint32)(v5))
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(v11)
			nox_window_call_field_94_fnc(v4.DrawData().Window, 16393, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 12))))
			return 0
		}
		v12 = int32(v4.SizeVal.X)
		if v10 < v12+int32(a3) {
			v13 = int64(float64(v10-int32(a3)) / float64(*(*float32)(unsafe.Add(v5, 8))))
			v11 = int32(*(*uint32)(unsafe.Add(v5, 4)))
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(int32(v13))
			if int32(v13) > v11 {
				*(*uint32)(unsafe.Add(v5, 12)) = uint32(v11)
				nox_window_call_field_94_fnc(v4.DrawData().Window, 16393, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 12))))
				return 0
			}
		} else {
			nox_window_setPos_46A9B0(v4.Field100Ptr, int32(int(v12)-v4.Field100Ptr.SizeVal.X), 0)
			*(*uint32)(unsafe.Add(v5, 12)) = *(*uint32)(unsafe.Add(v5, 4))
		}
		nox_window_call_field_94_fnc(v4.DrawData().Window, 16393, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 12))))
		return 0
	}
	if a2 == 2 {
		alloc.FreePtr(a1p.WidgetData)
		return 0
	}
	if a2 != 23 {
		return 0
	}
	v6 = int32(a3p)
	v7 = int32(a1p.DrawData().Field0)
	if a3p != 0 {
		*(*uint8)(unsafe.Pointer(&v7)) = uint8(int8(v7 | 2))
	} else {
		*(*uint8)(unsafe.Pointer(&v7)) = uint8(int8(v7 & 0xFD))
	}
	v18 := a1p
	a1p.DrawData().Field0 = uint32(v7)
	v8 = nox_xxx_wndGetID_46B0A0(v18)
	nox_window_call_field_94_fnc(v4.DrawData().Window, 16387, uintptr(v6), uintptr(v8))
	return 1
}
func nox_xxx_wndScrollBoxProc_4B5320(win *gui.Window, a2, a3p, a4p uintptr) uintptr {
	var (
		a1p = win
		v6  int32
		v7  int32
		v8  int64
		v9  int32
		v11 int32
		v12 int32
		v13 int32
		v14 uint32
		v15 int32
		v16 int32
		v17 float64
		v18 int32
		v19 int32
	)
	v4 := a1p
	v5 := a1p.WidgetData
	if a2 > 0x4007 {
		if a2 == 16394 {
			if int32(a3p) >= *(*int32)(v5) {
				v18 = int32(*(*uint32)(unsafe.Add(v5, 4)))
				if int32(a3p) <= v18 {
					v19 = v18 - int32(a3p)
					*(*uint32)(unsafe.Add(v5, 12)) = uint32(a3p)
					nox_window_setPos_46A9B0(v4.Field100Ptr, 0, int32(int64(float64(v19)*float64(*(*float32)(unsafe.Add(v5, 8))))))
				}
			}
		} else if a2 == 16395 {
			v14 = uint32(a4p)
			v15 = int32(a3p)
			*(*uint32)(unsafe.Add(v5, 4)) = uint32(a4p)
			*(*uint32)(v5) = uint32(v15)
			a3b := int32(v14 - uint32(v15))
			v16 = int32(v4.SizeVal.Y)
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(v15)
			v17 = float64(a3b)
			*(*float32)(unsafe.Add(v5, 8)) = float32(float64(v16-10) / v17)
			nox_window_setPos_46A9B0(v4.Field100Ptr, 0, int32(int64(v17*float64(*(*float32)(unsafe.Add(v5, 8))))))
			return 0
		}
		return 0
	}
	switch a2 {
	case 0x4007:
		nox_window_call_field_94_fnc(a1p.DrawData().Window, 16396, uintptr(unsafe.Pointer(a1p)), uintptr(*(*uint32)(unsafe.Add(v5, 12))))
		return 0
	case 2:
		alloc.FreePtr(a1p.WidgetData)
		return 0
	case 0x17:
		v11 = int32(a3p)
		v12 = int32(a1p.DrawData().Field0)
		if a3p != 0 {
			*(*uint8)(unsafe.Pointer(&v12)) = uint8(int8(v12 | 2))
		} else {
			*(*uint8)(unsafe.Pointer(&v12)) = uint8(int8(v12 & 0xFD))
		}
		v20 := a1p
		a1p.DrawData().Field0 = uint32(v12)
		v13 = nox_xxx_wndGetID_46B0A0(v20)
		nox_window_call_field_94_fnc(v4.DrawData().Window, 16387, uintptr(v11), uintptr(v13))
		return 1
	}
	if a2 != 0x4000 {
		return 0
	}
	v6 = int32(a4p >> 16)
	var a1, a3 int32
	nox_client_wndGetPosition_46AA60(a1p, &a1, &a3)
	if v6 >= int32(a3) {
		v7 = int32(v4.SizeVal.Y)
		if v6 < v7+int32(a3) {
			v8 = int64(float64(v6-int32(a3)) / float64(*(*float32)(unsafe.Add(v5, 8))))
			v9 = int32(*(*uint32)(unsafe.Add(v5, 4)))
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(int32(v8))
			if int32(v8) > v9 {
				*(*uint32)(unsafe.Add(v5, 12)) = uint32(v9)
			}
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(v9) - *(*uint32)(unsafe.Add(v5, 12))
		} else {
			nox_window_setPos_46A9B0(v4.Field100Ptr, 0, int32(int(v7)-v4.Field100Ptr.SizeVal.Y))
			*(*uint32)(unsafe.Add(v5, 12)) = *(*uint32)(v5)
		}
	} else {
		nox_window_setPos_46A9B0(v4.Field100Ptr, 0, 0)
		*(*uint32)(unsafe.Add(v5, 12)) = *(*uint32)(unsafe.Add(v5, 4))
	}
	nox_window_call_field_94_fnc(v4.DrawData().Window, 16393, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 12))))
	return 0
}
func sub_4B4860(win *gui.Window, a2, a3p, a4p uintptr) uintptr {
	var (
		a1  = win
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
	)
	v4 := a1.WidgetData
	switch a2 {
	case 5:
		return 1
	case 6, 7:
		v9 = int32(a3p)
		v10 = int32(uint16(int16(a3p)))
		var a3, a4 int32
		nox_client_wndGetPosition_46AA60(a1, &a4, &a3)
		if int(v10) > a1.SizeVal.X+int(int32(uint32(a4)))-10 {
			v10 = int32(a1.SizeVal.X + int(uint32(a4)) - 10)
		}
		nox_window_setPos_46A9B0(a1.Field100Ptr, v10-int32(uint32(a4))-5, 0)
		nox_window_call_field_94_fnc(a1, 0x4000, 0, uintptr(v9))
		return 1
	case 8:
		v8 = int32(a1.DrawData().Style)
		if (v8 & 0x100) == 0 {
			return 1
		}
		nox_window_call_field_94_fnc(a1.DrawData().Window, 0x4000, uintptr(unsafe.Pointer(a1)), 0)
		return 1
	case 17:
		v5 = int32(a1.DrawData().Style)
		if (v5 & 0x100) == 0 {
			return 1
		}
		nox_xxx_wndSetRectColor2MB_46AFE0(a1, int32(a1.DrawData().HlColorVal))
		nox_window_call_field_94_fnc(a1.DrawData().Window, 16389, uintptr(unsafe.Pointer(a1)), 0)
		nox_xxx_windowFocus_46B500(a1)
		return 1
	case 18:
		v7 = int32(a1.DrawData().Style)
		if v7&0x100 != 0 {
			nox_xxx_wndSetRectColor2MB_46AFE0(a1, int32(a1.DrawData().EnColorVal))
			nox_window_call_field_94_fnc(a1.DrawData().Window, 16390, uintptr(unsafe.Pointer(a1)), 0)
		}
		return 1
	case 21:
		switch a3p {
		case 15, 208:
			if a4p != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_46A8A0()
			return 1
		case 200:
			if a4p == 2 {
				nox_xxx_wndRetNULL_0_46A8B0()
			}
			return 1
		case 203:
			if a4p != 2 {
				return 1
			}
			v13 = int32(*(*uint32)(unsafe.Add(v4, 12)))
			if v13 >= *(*int32)(unsafe.Add(v4, 4))-1 {
				return 1
			}
			v14 = v13 + 2
			*(*uint32)(unsafe.Add(v4, 12)) = uint32(v14)
			nox_window_call_field_94_fnc(a1.DrawData().Window, 16393, uintptr(unsafe.Pointer(a1)), uintptr(v14))
			nox_window_setPos_46A9B0(a1.Field100Ptr, int32(int64(float64(int32(*(*uint32)(unsafe.Add(v4, 12))-*(*uint32)(v4)))*float64(*(*float32)(unsafe.Add(v4, 8))))), 0)
			return 1
		case 205:
			if a4p != 2 {
				return 1
			}
			v11 = int32(*(*uint32)(unsafe.Add(v4, 12)))
			if v11 <= *(*int32)(v4)+1 {
				return 1
			}
			v12 = v11 - 2
			*(*uint32)(unsafe.Add(v4, 12)) = uint32(v12)
			nox_window_call_field_94_fnc(a1.DrawData().Window, 16393, uintptr(unsafe.Pointer(a1)), uintptr(v12))
			nox_window_setPos_46A9B0(a1.Field100Ptr, int32(int64(float64(int32(*(*uint32)(unsafe.Add(v4, 12))-*(*uint32)(v4)))*float64(*(*float32)(unsafe.Add(v4, 8))))), 0)
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}
func sub_4B51E0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win
		a2    = draw
		v2    int32
		v3    int32
		v4    int32
		xLeft int32
		yTop  int32
	)
	v2 = int32(a2.EnColorVal)
	v3 = int32(a2.BgColorVal)
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop)
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))&8 != 0 {
		if a2.Field0&2 != 0 && a2.HlColorVal != 0x80000000 {
			nox_client_drawSetColor_434460(int32(a2.HlColorVal))
			nox_client_drawBorderLines_49CC70(xLeft, yTop, int32(a1.SizeVal.X), int32(a1.SizeVal.Y))
		}
	} else {
		v3 = int32(a2.DisColorVal)
	}
	if uint32(v3) != 0x80000000 {
		nox_client_drawSetColor_434460(v3)
		nox_client_drawRectFilledOpaque_49CE30(xLeft+1, yTop+1, int32(a1.SizeVal.X-2), int32(a1.SizeVal.Y-2))
	}
	v4 = int32(int(yTop) + a1.SizeVal.Y/2)
	if uint32(v2) != 0x80000000 {
		nox_client_drawSetColor_434460(v2)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, v4-1, int32(a1.SizeVal.X), 3)
	}
	return 1
}
func sub_4B52C0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1 = win
		a2 = draw
		v4 int32
		v5 int32
	)
	v2 := a2.BgImageHnd
	nox_client_wndGetPosition_46AA60(a1, &v4, &v5)
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4))) & 8) == 0 {
		v2 = a2.DisImageHnd
	}
	if v2 != nil {
		nox_client_drawImageAt_47D2C0(v2, v4, v5)
	}
	return 1
}
func nox_xxx_wndScrollBoxDraw_4B4BA0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		a1  = win
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
	)
	v4 := a1.WidgetData
	switch a2 {
	case 5:
		return 1
	case 6, 7:
		v9 = int32(a3)
		v10 = int32(a3 >> 16)
		var tmp, py int32
		nox_client_wndGetPosition_46AA60(a1, &tmp, &py)
		if int(v10) > a1.SizeVal.Y+int(int32(py))-10 {
			v10 = int32(a1.SizeVal.Y + int(py) - 10)
		}
		nox_window_setPos_46A9B0(a1.Field100Ptr, 0, v10-int32(py)-5)
		nox_window_call_field_94_fnc(a1, 0x4000, 0, uintptr(v9))
		return 1
	case 8:
		v8 = int32(a1.DrawData().Style)
		if (v8 & 0x100) == 0 {
			return 1
		}
		nox_window_call_field_94_fnc(a1.DrawData().Window, 0x4000, uintptr(unsafe.Pointer(a1)), 0)
		return 1
	case 17:
		v5 = int32(a1.DrawData().Style)
		if (v5 & 0x100) == 0 {
			return 1
		}
		nox_xxx_wndSetRectColor2MB_46AFE0(a1, int32(a1.DrawData().HlColorVal))
		nox_window_call_field_94_fnc(a1.DrawData().Window, 16389, uintptr(unsafe.Pointer(a1)), 0)
		nox_xxx_windowFocus_46B500(a1)
		return 1
	case 18:
		v7 = int32(a1.DrawData().Style)
		if v7&0x100 != 0 {
			nox_xxx_wndSetRectColor2MB_46AFE0(a1, int32(a1.DrawData().EnColorVal))
			nox_window_call_field_94_fnc(a1.DrawData().Window, 16390, uintptr(unsafe.Pointer(a1)), 0)
		}
		return 1
	case 21:
		switch a3 {
		case 0xF, 0xCD:
			if a4 != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_46A8A0()
			return 1
		case 0xC8:
			if a4 != 2 {
				return 1
			}
			v11 = int32(*(*uint32)(unsafe.Add(v4, 12)))
			if v11 >= *(*int32)(unsafe.Add(v4, 4))-1 {
				return 1
			}
			v12 = v11 + 2
			*(*uint32)(unsafe.Add(v4, 12)) = uint32(v12)
			nox_window_call_field_94_fnc(a1.DrawData().Window, 16393, uintptr(unsafe.Pointer(a1)), uintptr(v12))
			nox_window_setPos_46A9B0(a1.Field100Ptr, 0, int32(int64(float64(int32(*(*uint32)(unsafe.Add(v4, 4))-*(*uint32)(unsafe.Add(v4, 12))))*float64(*(*float32)(unsafe.Add(v4, 8))))))
			return 1
		case 0xCB:
			if a4 == 2 {
				nox_xxx_wndRetNULL_0_46A8B0()
			}
			return 1
		case 0xD0:
			if a4 != 2 {
				return 1
			}
			v13 = int32(*(*uint32)(unsafe.Add(v4, 12)))
			if v13 <= *(*int32)(v4)+1 {
				return 1
			}
			v14 = v13 - 2
			*(*uint32)(unsafe.Add(v4, 12)) = uint32(v14)
			nox_window_call_field_94_fnc(a1.DrawData().Window, 16393, uintptr(unsafe.Pointer(a1)), uintptr(v14))
			nox_window_setPos_46A9B0(a1.Field100Ptr, 0, int32(int64(float64(int32(*(*uint32)(unsafe.Add(v4, 4))-*(*uint32)(unsafe.Add(v4, 12))))*float64(*(*float32)(unsafe.Add(v4, 8))))))
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}
func nox_xxx_wndScrollBoxDraw_4B5540(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win
		a2    = draw
		v2    int32
		v3    int32
		v4    int32
		xLeft int32
		yTop  int32
	)
	v2 = int32(a2.EnColorVal)
	v3 = int32(a2.BgColorVal)
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop)
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))&8 != 0 {
		if a2.Field0&2 != 0 {
			v2 = int32(a2.SelColorVal)
			if a2.HlColorVal != 0x80000000 {
				nox_client_drawSetColor_434460(int32(a2.HlColorVal))
				nox_client_drawBorderLines_49CC70(xLeft, yTop, int32(a1.SizeVal.X), int32(a1.SizeVal.Y))
			}
		}
	} else {
		v3 = int32(a2.DisColorVal)
	}
	if uint32(v3) != 0x80000000 {
		nox_client_drawSetColor_434460(v3)
		nox_client_drawRectFilledOpaque_49CE30(xLeft+1, yTop+1, int32(a1.SizeVal.X-2), int32(a1.SizeVal.Y-2))
	}
	v4 = int32(int(xLeft) + a1.SizeVal.X/2)
	if uint32(v2) != 0x80000000 {
		nox_client_drawSetColor_434460(v2)
		nox_client_drawRectFilledOpaque_49CE30(v4-1, yTop+4, 3, int32(a1.SizeVal.Y-8))
	}
	return 1
}
func nox_xxx_wndScrollBoxDraw_4B5620(win *gui.Window, draw *gui.WindowData) int {
	var (
		v2 int32
		v3 int32
	)
	nox_client_wndGetPosition_46AA60(win, &v2, &v3)
	return 1
}
