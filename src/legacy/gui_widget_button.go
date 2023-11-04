package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func nox_xxx_wndButtonProcPre_4A9250(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	var (
		a1 = win
		a3 = (*wchar2_t)(unsafe.Pointer(p3))
		v4 int32
	)
	if a2 == 23 {
		if a3 == nil {
			v4 = int32(a1.DrawData().Field0)
			*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 & 0xFD))
			a1.DrawData().Field0 = uint32(v4)
		}
		v5 := nox_xxx_wndGetID_46B0A0(a1)
		nox_window_call_field_94_fnc(a1.DrawData().Window, 16387, uintptr(unsafe.Pointer(a3)), uintptr(v5))
		return 1
	} else {
		if a2 == 16385 {
			nox_wcsncpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(a1), 108)), a3, 0x3F)
			*(*uint16)(unsafe.Add(unsafe.Pointer(a1), 234)) = 0
		}
		return 0
	}
}

func Nox_xxx_wndButtonInit_4A8340(a1 *gui.Window) {
	if int8(byte(a1.Flags)) >= 0 {
		nox_window_set_all_funcs(a1, nox_xxx_wndButtonProc_4A7F50, nox_xxx_wndButtonDrawNoImg_4A81D0, nil)
	} else {
		nox_window_set_all_funcs(a1, nox_xxx_wndButtonProc_4A7F50, nox_xxx_wndButtonDraw_4A8380, nil)
	}
}

func nox_xxx_wndButtonProc_4A7F50(win *gui.Window, ev, a3, a4 uintptr) uintptr {
	switch ev {
	case 5:
		win.DrawData().Field0 |= 4
		return 1
	case 6, 7:
		if (win.DrawData().Field0 & 4) == 0 {
			return 0
		}
		nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000|7, uintptr(unsafe.Pointer(win)), a3)
		win.DrawData().Field0 &= 0xFFFFFFFB
		return 1
	case 8:
		nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000, uintptr(unsafe.Pointer(win)), a3)
		return 1
	case 17:
		if win.DrawData().Style&0x100 != 0 {
			win.DrawData().Field0 |= 2
			nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000|5, uintptr(unsafe.Pointer(win)), a3)
			nox_xxx_windowFocus_46B500(win)
		}
		return 1
	case 18:
		if win.DrawData().Style&0x100 != 0 {
			win.DrawData().Field0 &= 0xFFFFFFFD
			nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000|6, uintptr(unsafe.Pointer(win)), a3)
		}
		if win.DrawData().Field0&4 != 0 {
			win.DrawData().Field0 &= 0xFFFFFFFB
		}
		return 1
	case 21:
		switch a3 {
		case 15, 205, 208:
			if a4 == 2 {
				nox_xxx_wndRetNULL_46A8A0()
			}
			return 1
		case 28, 57:
			if a4 != 1 {
				win.DrawData().Field0 |= 4
				return 1
			}
			if win.DrawData().Field0&4 != 0 {
				nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000|7, uintptr(unsafe.Pointer(win)), 0)
				win.DrawData().Field0 &= 0xFFFFFFFB
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

func nox_xxx_wndButtonDrawNoImg_4A81D0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		v9    int32
		xLeft int32
		yTop  int32
	)
	v2 := draw
	v3 = int32(draw.EnColorVal)
	v4 = int32(draw.BgColorVal)
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop)
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))&8 != 0 {
		if v2.Field0&4 != 0 {
			v4 = int32(v2.SelColorVal)
		} else if v2.Field0&2 != 0 {
			v3 = int32(v2.HlColorVal)
		}
	} else {
		v4 = int32(v2.DisColorVal)
	}
	if uint32(v3) != 0x80000000 {
		nox_client_drawSetColor_434460(v3)
		nox_client_drawBorderLines_49CC70(xLeft, yTop, int32(a1.SizeVal.X), int32(a1.SizeVal.Y))
	}
	if uint32(v4) != 0x80000000 {
		nox_client_drawSetColor_434460(v4)
		nox_client_drawRectFilledOpaque_49CE30(xLeft+1, yTop+1, int32(a1.SizeVal.X-2), int32(a1.SizeVal.Y-2))
	}
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), 72))) == 0 {
		return 1
	}
	v5 = int32(int(xLeft) + a1.SizeVal.X/2)
	v6 = int32(int(yTop) + a1.SizeVal.Y/2)
	if (a1.Flags & 0x2000) == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	var a2 int32
	nox_xxx_drawGetStringSize_43F840(v2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), 72)), &a2, nil, 0)
	if v2.TextColorVal != 0x80000000 {
		nox_xxx_drawSetTextColor_434390(int32(v2.TextColorVal))
		v9 = int32(a1.SizeVal.X)
		v7 = nox_xxx_guiFontHeightMB_43F320(v2.FontPtr)
		nox_xxx_drawStringWrap_43FAF0(v2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), 72)), v5-a2/2, v6-v7/2, v9, 0)
	}
	nox_draw_enableTextSmoothing_43F670(0)
	return 1
}

func nox_xxx_wndButtonDraw_4A8380(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1p = win
		a2p = draw
		v4  noxrender.ImageHandle
		v5  noxrender.ImageHandle
		v7  int32
		v8  int32
		v10 int32
		v11 int32
	)
	v2 := a2p
	v3 := a1p
	v4 = a2p.EnImageHnd
	v5 = a2p.BgImageHnd
	var a1, a2 int32
	nox_client_wndGetPosition_46AA60(a1p, &a1, &a2)
	if v3.Flags&8 != 0 {
		if v2.Field0&4 != 0 {
			v4 = v2.SelImageHnd
		} else if v2.Field0&2 != 0 {
			v4 = v2.HlImageHnd
		}
	} else {
		v5 = v2.DisImageHnd
	}
	if v5 != nil {
		nox_client_drawImageAt_47D2C0(v5, a1+int32(v3.DrawData().ImgPtVal.X), a2+int32(v3.DrawData().ImgPtVal.Y))
	}
	if v4 != nil {
		nox_client_drawImageAt_47D2C0(v4, a1+int32(v3.DrawData().ImgPtVal.X), a2+int32(v3.DrawData().ImgPtVal.Y))
	}
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), 72))) == 0 {
		return 1
	}
	v7 = int32(v3.Flags & 0x2000)
	a1 += int32(v3.SizeVal.X / 2)
	a2 += int32(v3.SizeVal.Y / 2)
	if v7 == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	nox_xxx_drawGetStringSize_43F840(v2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), 72)), &v11, nil, 0)
	if v2.TextColorVal != 0x80000000 {
		nox_xxx_drawSetTextColor_434390(int32(v2.TextColorVal))
		v10 = int32(v3.SizeVal.X)
		v8 = nox_xxx_guiFontHeightMB_43F320(v2.FontPtr)
		nox_xxx_drawStringWrap_43FAF0(v2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), 72)), int32(a1)-v11/2, int32(a2)-v8/2, v10, 0)
	}
	nox_draw_enableTextSmoothing_43F670(0)
	return 1
}
