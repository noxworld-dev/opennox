package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func nox_gui_newButtonOrCheckbox_4A91A0(parent *gui.Window, a2 nox_window_flags, a3, a4, a5, a6 int, draw *gui.WindowData) *gui.Window {
	if draw.Style&1 != 0 {
		btn := nox_window_new(parent, a2, a3, a4, a5, a6, nox_xxx_wndButtonProcPre_4A9250)
		if btn == nil {
			return nil
		}
		Nox_xxx_wndButtonInit_4A8340(btn)
		if draw.Window == nil {
			draw.Window = btn
		}
		nox_gui_windowCopyDrawData_46AF80(btn, draw)
		return btn
	}
	if draw.Style&4 != 0 {
		btn := nox_window_new(parent, a2, a3, a4, a5, a6, nox_xxx_wndCheckboxProcMB_4A92C0)
		if btn == nil {
			return nil
		}
		Nox_xxx_wndCheckBoxInit_4A8E60(btn)
		if draw.Window == nil {
			draw.Window = btn
		}
		nox_gui_windowCopyDrawData_46AF80(btn, draw)
		return btn
	}
	return nil
}

func Nox_xxx_wndCheckBoxInit_4A8E60(a1 *gui.Window) {
	if int32(int8(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))) >= 0 {
		nox_window_set_all_funcs(a1, nox_xxx_wndCheckBoxProc_4A8C00, nox_xxx_wndDrawCheckBoxNoImg_4A8EA0, nil)
	} else {
		nox_window_set_all_funcs(a1, nox_xxx_wndCheckBoxProc_4A8C00, nox_xxx_wndDrawCheckBox_4A9050, nil)
	}
}

func nox_xxx_wndCheckBoxProc_4A8C00(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		a1 = win
	)
	switch a2 {
	case 5:
		return 1
	case 6, 7:
		v8 := a1
		if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 36))) & 2) == 0 {
			return 0
		}
		nox_window_call_field_94_fnc(a1.DrawData().Window, 16391, uintptr(unsafe.Pointer(a1)), a3)
		v8.DrawData().Field0 ^= 4
		return 1
	case 8:
		nox_window_call_field_94_fnc(a1.DrawData().Window, 0x4000, uintptr(unsafe.Pointer(a1)), a3)
		return 1
	case 17:
		v4 := int32(a1.DrawData().Style)
		if v4&0x100 != 0 {
			v5 := a1.DrawData().Window
			a1.DrawData().Field0 |= 2
			nox_window_call_field_94_fnc(v5, 16389, uintptr(unsafe.Pointer(a1)), a3)
			nox_xxx_windowFocus_46B500(a1)
		}
		return 1
	case 18:
		v7 := int32(a1.DrawData().Style)
		if v7&0x100 != 0 {
			v9 := a1.DrawData().Window
			a1.DrawData().Field0 &= 0xFFFFFFFD
			nox_window_call_field_94_fnc(v9, 16390, uintptr(unsafe.Pointer(a1)), a3)
		}
		return 1
	case 21:
		switch a3 {
		case 15, 205, 208:
			if a4 != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_46A8A0()
			return 1
		case 28, 57:
			if a4 == 2 {
				v8 := a1
				nox_window_call_field_94_fnc(v8.DrawData().Window, 16391, uintptr(unsafe.Pointer(v8)), 0)
				v8.DrawData().Field0 ^= 4
			}
			return 1
		case 200, 203:
			if a4 == 2 {
				nox_xxx_wndRetNULL_0_46A8B0()
			}
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}

func nox_xxx_wndDrawCheckBoxNoImg_4A8EA0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win
		a2    = draw
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		v9    int32
		xLeft int32
		yTop  int32
		v12   int32
	)
	v2 := a2
	v3 = int32(a2.EnColorVal)
	v12 = int32(a2.BgColorVal)
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop)
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))&8 != 0 {
		if v2.Field0&2 != 0 {
			v3 = int32(v2.HlColorVal)
		}
	} else {
		v12 = int32(v2.DisColorVal)
	}
	v4 = int32(int(yTop) + a1.SizeVal.Y/2 - 5)
	v5 = xLeft + 4
	if uint32(v12) != 0x80000000 {
		nox_client_drawSetColor_434460(v12)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, int32(a1.SizeVal.X), int32(a1.SizeVal.Y))
	}
	if uint32(v3) != 0x80000000 {
		nox_client_drawSetColor_434460(v3)
		nox_client_drawBorderLines_49CC70(v5, v4, 10, 10)
	}
	if v2.Field0&4 != 0 {
		if v2.SelColorVal != 0x80000000 {
			nox_client_drawSetColor_434460(int32(v2.SelColorVal))
			nox_client_drawRectFilledOpaque_49CE30(v5+1, v4+1, 8, 8)
			if uint32(v3) != 0x80000000 {
				nox_client_drawSetColor_434460(v3)
				nox_client_drawAddPoint_49F500(v5, v4)
				nox_xxx_rasterPointRel_49F570(9, 9)
				nox_client_drawLineFromPoints_49E4B0()
				nox_client_drawAddPoint_49F500(v5, v4+9)
				nox_xxx_rasterPointRel_49F570(9, -9)
				nox_client_drawLineFromPoints_49E4B0()
			}
		}
	}
	v6 = 5 - nox_xxx_guiFontHeightMB_43F320(v2.FontPtr)/2 + v4
	v7 = v5 + 14
	nox_xxx_drawGetStringSize_43F840(v2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), 72)), &v9, nil, 0)
	if v2.TextColorVal == 0x80000000 {
		return 1
	}
	if (a1.Flags & 0x2000) == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	nox_xxx_drawSetTextColor_434390(int32(v2.TextColorVal))
	nox_xxx_drawStringWrap_43FAF0(v2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), 72)), v7, v6, int32(a1.SizeVal.X), 0)
	nox_draw_enableTextSmoothing_43F670(0)
	return 1
}

func nox_xxx_wndDrawCheckBox_4A9050(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1  = win
		v4  int32
		v5  int32
		v6  int32
		v7  noxrender.ImageHandle
		v8  int32
		v9  int32
		v12 int32
		v13 int32
	)
	v2 := draw
	v3 := a1
	v11 := draw.EnImageHnd
	a2 := draw.BgImageHnd
	nox_client_wndGetPosition_46AA60(a1, &v12, &v13)
	v4 = int32(int(v13) + v3.SizeVal.Y/2)
	if v3.Flags&8 != 0 {
		if v2.Field0&2 != 0 {
			v11 = v2.HlImageHnd
		}
	} else {
		a2 = v2.DisImageHnd
	}
	v5 = v4 - 5
	v6 = v12 + 4
	if a2 != nil {
		nox_client_drawImageAt_47D2C0(a2, int32(int(v6)+v3.DrawData().ImgPtVal.X), int32(int(v5)+v3.DrawData().ImgPtVal.Y))
	}
	if v2.Field0&4 != 0 {
		v7 = v2.SelImageHnd
		if v7 == nil {
			goto LABEL_12
		}
	} else {
		v7 = v11
		if v11 == nil {
			goto LABEL_12
		}
	}
	nox_client_drawImageAt_47D2C0(v7, int32(int(v6)+v3.DrawData().ImgPtVal.X), int32(int(v5)+v3.DrawData().ImgPtVal.Y))
LABEL_12:
	v8 = 5 - nox_xxx_guiFontHeightMB_43F320(v2.FontPtr)/2 + v5
	v9 = v6 + 16
	nox_xxx_drawGetStringSize_43F840(v2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), 72)), (*int32)(unsafe.Pointer(&a1)), nil, 0)
	if v2.TextColorVal == 0x80000000 {
		return 1
	}
	if (v3.Flags & 0x2000) == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	nox_xxx_drawSetTextColor_434390(int32(v2.TextColorVal))
	nox_xxx_drawStringWrap_43FAF0(v2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), 72)), v9, v8, int32(v3.SizeVal.X), 0)
	nox_draw_enableTextSmoothing_43F670(0)
	return 1
}
