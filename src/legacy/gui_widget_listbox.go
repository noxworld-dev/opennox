package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func Nox_gui_newScrollListBox_4A4310(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, sdata *gui.ScrollListBoxData) *gui.Window {
	v21 := false
	if int32(sdata.LineHeight) < nox_xxx_guiFontHeightMB_43F320(draw.FontPtr) {
		sdata.LineHeight = uint16(int16(nox_xxx_guiFontHeightMB_43F320(draw.FontPtr)))
	}
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(draw), 72))) != 0 {
		v21 = true
	}
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(draw), 8))) & 0x20) == 0 {
		return nil
	}
	win := nox_window_new(par, status, px, py, w, h, nox_xxx_wndListboxProcPre_4A30D0)
	nox_xxx_wndListboxInit_4A3C00(win, sdata)
	if win == nil {
		return nil
	}
	if draw.Window == nil {
		draw.Window = win
	}
	nox_gui_windowCopyDrawData_46AF80(win, draw)
	items, _ := alloc.Make([]gui.ScrollListBoxItem{}, int(sdata.Count))
	sdata.ItemsPtr = &items[0]
	v10 := h
	sdata.Field_13_0 = uint16(int16(h))
	if v21 {
		sdata.Field_13_0 -= uint16(int16(nox_xxx_guiFontHeightMB_43F320(draw.FontPtr)))
	}
	sdata.Field_13_1 = 0
	sdata.SetField12(-1)
	sdata.Field_11_1 = 0
	sdata.Field_11_0 = 0
	sdata.Field_10 = 0
	if sdata.HasData != 0 {
		arr, _ := alloc.Make([]int32{}, int(sdata.Count))
		sdata.SetField12Slice(arr)
		for i := range arr {
			arr[i] = -1
		}
	}
	if sdata.HasScroll != 0 {
		v15 := nox_xxx_guiFontHeightMB_43F320(draw.FontPtr)
		var v22 int32
		if v21 {
			v22 = v15 + 1
			v10 = v10 - int(v15) - 1
		}
		btnFlags := (status & 0xFFFFEFEF) | 9

		var v23 int32
		var v25 gui.WindowData
		if int32(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(win), 4))))) >= 0 {
			v25.BgColorVal = nox_color_black_2650656
			v25.DisColorVal = nox_color_black_2650656
			v25.EnColorVal = nox_color_orange_2614256
			v25.HlColorVal = nox_color_white_2523948
			v25.SelColorVal = nox_color_yellow_2589772
			v25.TextColorVal = nox_color_orange_2614256
			v16 := nox_strman_loadString_40F1D0(internCStr("WindowDir:Up"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\Gadgets\\listbox.c"), 1483)
			nox_wcscpy(&v25.TextBuf[0], v16)
			v23 = 10
		} else {
			v25.BgImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButton"))
			v25.HlImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButtonLit"))
			v25.DisImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButtonDis"))
			v25.SelImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButtonLit"))
			v25.EnImageHnd = nil
			v23 = 13
		}
		v25.Window = win
		v25.Style = gui.StylePushButton
		sdata.UpButton = nox_gui_newButtonOrCheckbox_4A91A0(win, btnFlags, w-10, int(v22), 10, int(v23), &v25)

		var v25c gui.WindowData
		if int32(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(win), 4))))) >= 0 {
			v25c.BgColorVal = nox_color_black_2650656
			v25c.DisColorVal = nox_color_black_2650656
			v25c.EnColorVal = nox_color_orange_2614256
			v25c.HlColorVal = nox_color_white_2523948
			v25c.SelColorVal = nox_color_yellow_2589772
			v25c.TextColorVal = nox_color_orange_2614256
			v18 := nox_strman_loadString_40F1D0(internCStr("WindowDir:Down"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\Gadgets\\listbox.c"), 1519)
			nox_wcscpy(&v25c.TextBuf[0], v18)
		} else {
			v25c.BgImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButton"))
			v25c.HlImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButtonLit"))
			v25c.DisImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButtonDis"))
			v25c.SelImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButtonLit"))
			v25c.EnImageHnd = nil
		}
		v25c.Style = gui.StylePushButton
		v25c.Window = win
		sdata.DownButton = nox_gui_newButtonOrCheckbox_4A91A0(win, btnFlags, w-10, int(v22)+v10-int(v23), 10, int(v23), &v25c)

		var v25d gui.WindowData
		var v19 int32
		if int32(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(win), 4))))) >= 0 {
			v25d.BgColorVal = nox_color_black_2650656
			v25d.DisColorVal = nox_color_black_2650656
			v25d.HlColorVal = nox_color_black_2650656
			v25d.EnColorVal = nox_color_orange_2614256
			v25d.SelColorVal = nox_color_orange_2614256
			v19 = 10
		} else {
			v25d.BgImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumb"))
			v25d.HlImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumbLit"))
			v25d.DisImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumbDis"))
			v25d.SelImageHnd = nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumbLit"))
			v25d.EnImageHnd = nil
			v19 = 9
		}
		v25d.Style = 8
		v25d.Window = win
		var v24 nox_slider_data
		sdata.Slider = nox_gui_newSlider_4B4EE0(win, btnFlags, w-int(v19), int(v22+v23), int(v19), v10-int(v23*2), &v25d, &v24)
	}
	d, _ := alloc.New(gui.ScrollListBoxData{})
	*d = *sdata
	win.WidgetData = unsafe.Pointer(d)
	return win
}
func nox_xxx_wndListboxInit_4A3C00(a1 *gui.Window, a2 *gui.ScrollListBoxData) {
	if a1 != nil {
		if int32(int8(a1.Flags)) >= 0 {
			nox_xxx_wndSetDrawFn_46B340(a1, nox_xxx_wndListboxDrawNoImage_4A3C50)
		} else {
			nox_xxx_wndSetDrawFn_46B340(a1, nox_xxx_wndListboxDrawWithImage_4A3FC0)
		}
		if a2.HasData != 0 {
			nox_xxx_wndSetWindowProc_46B300(a1, nox_xxx_wndListboxProcWithData10_4A2DE0)
		} else {
			nox_xxx_wndSetWindowProc_46B300(a1, nox_xxx_wndListboxProcWithoutData10_4A28E0)
		}
	}
}
func nox_xxx_wndListboxProcPre_4A30D0(win *gui.Window, ev, a3, a4 uintptr) uintptr {
	sdata := (*gui.ScrollListBoxData)(win.WidgetData)
	switch ev {
	case 2:
		if sdata != nil {
			alloc.Free(sdata.ItemsPtr)
			if sdata.HasData != 0 {
				alloc.Free(sdata.Field12Ptr())
			}
			alloc.Free(sdata)
		}
		win.WidgetData = nil
		return 0
	case 23:
		if a3 != 0 {
			win.DrawData().Field0 |= 2
		} else {
			win.DrawData().Field0 &= 0xFFFFFFFD
		}
		id := nox_xxx_wndGetID_46B0A0(win)
		nox_window_call_field_94_fnc(win.DrawData().Window, 0x4003, a3, uintptr(id))
		return 1
	case 0x4013:
		ind := int(a3)
		if ind < 0 || ind >= int(sdata.Count) {
			if sdata.HasData != 0 {
				arr := sdata.Field12Slice()
				for i := range arr {
					arr[i] = -1
				}
				return 0
			}
			sdata.SetField12(-1)
			return 0
		}
		items := sdata.Items()
		it := &items[ind]
		if it.TextBuf[0] == 0 {
			return 0
		}
		if sdata.HasData != 0 {
			arr := sdata.Field12Slice()
			arr[0] = int32(ind)
			arr[1] = -1
			return 0
		}
		v38 := int32(sdata.Field_13_1)
		sdata.SetField12(int32(ind))
		if it.Field_0 < uint32(v38) {
			nox_window_call_field_94_fnc(win, 0x401C, uintptr(ind), 0)
			return 0
		}
		v39 := int16(sdata.Field_13_0)
		if it.Field_0 > uint32(v38+int32(v39)) {
			if ind <= 0 {
				sdata.Field_13_1 = 0
			} else {
				v37 := it
				sdata.Field_13_1 = uint16(int16(int32(*(*uint16)(unsafe.Pointer(v37))) - int32(v39)))
			}
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
		}
		return 0
	case 0x4014:
		return uintptr(sdata.Field12()) // TODO: not sure if it's a ptr or int here
	case 0x4015:
		ind := int(a3)
		if ind < 0 || ind >= int(sdata.Count) {
			if sdata.HasData == 0 {
				return 0
			}
			arr := sdata.Field12Slice()
			for i := range arr {
				arr[i] = -1
			}
			return 0
		}
		items := sdata.Items()
		it := &items[ind]
		if it.TextBuf[0] == 0 || sdata.HasData == 0 {
			return 0
		}
		arr := sdata.Field12Slice()
		for i := range arr {
			v := int(arr[i])
			if v < 0 {
				arr[i] = int32(ind)
				arr[i+1] = -1
				return 0
			} else if v == ind {
				sub_4A3090(sdata, i)
				return 0
			}
		}
		return 0
	case 0x4016: // get item text
		ind := int(a3)
		arr := sdata.Items()
		if ind < 0 || ind >= len(arr) {
			return 0
		}
		return uintptr(unsafe.Pointer(&arr[ind].TextBuf[0]))
	case 0x4017: // set item text
		str := alloc.GoString16((*uint16)(unsafe.Pointer(a3)))
		ind := int(a4)
		arr := sdata.Items()
		if ind < 0 || ind >= len(arr) {
			return 0
		}
		arr[ind].SetText(str)
		return 0
	case 0x4018: // set up button
		sdata.UpButton = (*gui.Window)(unsafe.Pointer(a3))
		return 0
	case 0x4019: // set down button
		sdata.DownButton = (*gui.Window)(unsafe.Pointer(a3))
		return 0
	case 0x401A: // set slider
		sdata.Slider = (*gui.Window)(unsafe.Pointer(a3))
		return 0
	case 0x401B:
		ind := int32(a3)
		v40 := int32(sdata.Field_11_0)
		if v40 < ind {
			return 0
		}
		arr := sdata.Items()
		copy(arr[:v40-ind], arr[ind:v40])
		sdata.Field_11_0 -= uint16(int16(ind))
		sdata.Field_11_1 = sdata.Field_11_0
		if sdata.HasData != 0 {
			v41 := sdata.Field12Slice()
			v42 := 0
			if v41[0] >= 0 {
				for {
					v43 := v41[v42]
					if ind < v43 {
						sub_4A3090(sdata, v42)
						v42--
					} else {
						v41[v42] = v43 - ind
					}
					v42++
					if v41[v42] < 0 {
						break
					}
				}
			}
		} else {
			if v44 := sdata.Field12(); v44 > 0 {
				sdata.SetField12(v44 - ind)
			}
		}
		if int32(sdata.Field_13_1) > 0 {
			nox_xxx_wndListBox_4A2D10(win, -ind, 1)
		}
		nox_xxx_wndListBox_4A3A70(win)
		return 1
	case 0x401C:
		ind := int32(a3)
		if ind-1 >= 0 && ind-1 < int32(sdata.Count) {
			arr := sdata.Items()
			sdata.Field_13_1 = uint16(arr[ind-1].Field_0 + 1)
		} else {
			sdata.Field_13_1 = 0
		}
		v45 := int16(sdata.Field_13_0)
		v46 := int32(sdata.Field_10)
		if int32(sdata.Field_13_1)+int32(v45) >= v46 {
			sdata.Field_13_1 = uint16(int16(v46 - int32(v45)))
		}
		nox_xxx_wndListBox_4A2D10(win, 0, 1)
		return 0
	case 0x4012:
		if int32(a3) >= 0 {
			v32 := int16(sdata.Field_11_0)
			if int32(a3) <= int32(v32) {
				sdata.Field_11_1 = uint16(a3)
			} else {
				sdata.Field_11_1 = uint16(v32)
			}
		} else {
			sdata.Field_11_1 = 0
		}
		return 0
	case 0x4009:
		v29 := int16(sdata.Field_13_0)
		v30 := int16(int32(*(*uint16)(unsafe.Add(sdata.Slider.WidgetData, 4))) - int32(a4))
		v31 := int32(sdata.Field_10 - uint32(v29) + 1)
		sdata.Field_13_1 = uint16(v30)
		if int32(v30) > v31 {
			sdata.Field_13_1 = uint16(int16(int32(sdata.Field_10) - int32(v29) + 1))
		}
		if int32(sdata.Field_13_1) < 0 {
			sdata.Field_13_1 = 0
		}
		nox_xxx_wndListBox_4A2D10(win, 0, 0)
		return 0
	case 0x400D:
		v18 := int16(sdata.Field_11_1)
		v19 := int16(sdata.Field_11_0)
		if int32(v18) != int32(v19) {
			if int32(v19) < int32(sdata.Count) {
				v20 := int32(v19) - 1
				if v20 >= int32(v18) {
					arr := sdata.Items()
					for {
						arr[v20] = gui.ScrollListBoxItem{}
						v20--
						if v20 < int32(sdata.Field_11_1) {
							break
						}
					}
				}
				nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), win)
			} else {
				if sdata.Field_2 == 0 {
					return 0
				}
				nox_window_call_field_94_fnc(win, 16411, 1, 0)
				v23 := int32(sdata.Field_11_0) - 1
				arr := sdata.Items()
				if v23 >= int32(sdata.Field_11_1) {
					for {
						arr[v23] = gui.ScrollListBoxItem{}
						v23--
						if v23 < int32(sdata.Field_11_1) {
							break
						}
					}
				}
				nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), win)
			}
		} else if int32(v18) >= int32(sdata.Count) {
			if sdata.Field_2 == 0 {
				return 0
			}
			nox_window_call_field_94_fnc(win, 16411, 1, 0)
			nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), win)
		} else {
			nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), win)
		}
		if sdata.Field_1 != 0 {
			arr := sdata.Items()
			for arr[int32(sdata.Field_11_1)-1].Field_0 >= uint32(int32(sdata.Field_13_1)+int32(sdata.Field_13_0)) {
				nox_xxx_wndListBox_4A2D10(win, 1, 1)
			}
		}
		if sdata.HasData != 0 {
			v26 := sdata.Field12Slice()
			if v26[0] >= 0 {
				v27 := 0
				for {
					v28 := v26[v27]
					if int32(sdata.Field_11_1) < v28 {
						v26[v27] = v28 + 1
					}
					v27++
					if v26[v27] < 0 {
						break
					}
				}
				return 1
			}
		} else if v26 := sdata.Field12(); int32(sdata.Field_11_1) < int32(v26) {
			sdata.SetField12(v26 + 1)
		}
		return 1
	case 0x400E:
		ind := int(a3)
		if ind < 0 || ind >= int(sdata.Field_11_0) {
			return 0
		}
		items := sdata.Items()
		for i := ind; i < int(sdata.Field_11_0)-1; i++ {
			items[i] = items[i+1]
		}
		sdata.Field_11_0--
		items[sdata.Field_11_0] = gui.ScrollListBoxItem{}
		sdata.Field_11_1 = sdata.Field_11_0
		if sdata.HasData != 0 {
			arr := sdata.Field12Slice()
			for i := 0; i < len(arr) && arr[i] >= 0; i++ {
				ind2 := int(arr[i])
				if ind < ind2 {
					arr[i]--
				} else if ind == ind2 {
					sub_4A3090(sdata, i)
					i--
				}
			}
		} else {
			ind2 := sdata.Field12()
			if ind < ind2 {
				sdata.SetField12(ind2 - 1)
			} else if ind == ind2 {
				sdata.SetField12(-1)
			}
		}
		nox_xxx_wndListBox_4A3A70(win)
		return 0
	case 0x400F: // clear?
		items := sdata.Items()
		for i := range items {
			items[i] = gui.ScrollListBoxItem{}
		}
		if a3 != 1 {
			sdata.Field_13_1 = 0
		}
		if sdata.HasData != 0 {
			arr := sdata.Field12Slice()
			for i := range arr {
				arr[i] = -1
			}
		} else {
			sdata.SetField12(-1)
		}
		sdata.Field_11_1 = 0
		sdata.Field_11_0 = 0
		sdata.Field_10 = 0
		nox_xxx_wndListBox_4A2D10(win, 0, 1)
		return 0
	case 0x4000, 0x4007: // click on up/down?
		btn := (*gui.Window)(unsafe.Pointer(a3))
		switch btn {
		case sdata.UpButton:
			if int32(sdata.Field_13_1) > 0 {
				nox_xxx_wndListBox_4A2D10(win, -1, 1)
			}
		case sdata.DownButton:
			if int(sdata.Field_13_0)+int(sdata.Field_13_1) <= int(sdata.Field_10) {
				nox_xxx_wndListBox_4A2D10(win, 1, 1)
			}
		}
		return 0
	case 0x4001: // set text
		str := alloc.GoString16((*uint16)(unsafe.Pointer(a3)))
		win.DrawData().SetText(str)
		return 0
	case 0x4004: // resize?
		if btn := sdata.UpButton; btn != nil {
			nox_window_setPos_46A9B0(btn, int32(int(a3)-btn.SizeVal.X), 0)
		}
		if btn := sdata.DownButton; btn != nil {
			nox_window_setPos_46A9B0(btn, int32(int(a3)-btn.SizeVal.X), int32(int(a4)-btn.SizeVal.Y))
		}
		if sl := sdata.Slider; sl != nil {
			nox_window_setPos_46A9B0(sl, int32(int(a3)-sl.SizeVal.X), int32(sdata.UpButton.SizeVal.Y))
			sub_46AB20(sdata.Slider, int32(sdata.Slider.SizeVal.X), int32(int(a4)-sdata.Slider.Field100Ptr.SizeVal.Y*2))
		}
		sdata.Field_13_0 = uint16(int16(a4))
		if win.DrawData().Text() != "" {
			sdata.Field_13_0 -= uint16(nox_xxx_guiFontHeightMB_43F320(win.DrawData().FontC()))
		}
		return 0
	default:
		return 0
	}
}
func sub_4A3090(d *gui.ScrollListBoxData, i int) {
	field12 := d.Field12Slice()
	copy(field12[i:], field12[i+1:])
	field12[d.Count-1] = -1
}
func nox_xxx_wndListBoxAddLine_4A3AC0(a1 *wchar2_t, a2 int32, win *gui.Window) {
	v3 := win
	v4 := (*gui.ScrollListBoxData)(win.WidgetData)
	v5 := int32(win.SizeVal.X - 7)
	if v4.HasScroll != 0 {
		v5 = int32(win.SizeVal.X - 17)
	}
	if a2 >= 17 || a2 < 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(v4.ItemsPtr), uintptr(uint32(int32(v4.Field_11_1)*524))+516)) = win.DrawData().TextColorVal
	} else {
		*(*uint32)(unsafe.Add(unsafe.Pointer(v4.ItemsPtr), uintptr(uint32(int32(v4.Field_11_1)*524))+516)) = **(**uint32)(memmap.PtrOff(0x85B3FC, uintptr(a2*4+132)))
	}
	v6 := (*wchar2_t)(unsafe.Add(unsafe.Pointer(v4.ItemsPtr), uintptr(uint32(int32(v4.Field_11_1)*524))+4))
	if a1 != nil {
		nox_wcsncpy(v6, a1, math.MaxUint8)
		*(*wchar2_t)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(wchar2_t(0))*math.MaxUint8)) = 0
		v7 := (*wchar2_t)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(wchar2_t(0))*uintptr(nox_wcslen(v6)-1)))
		if *v7 == 10 {
			*v7 = 0
		}
	} else {
		*v6 = 32
		*(*wchar2_t)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(wchar2_t(0))*1)) = 0
	}
	if (v3.Flags & 0x4000) == 0x4000 {
		*(*uint8)(unsafe.Add(unsafe.Pointer(v4.ItemsPtr), uintptr(uint32(int32(v4.Field_11_1)*524))+520)) = uint8(int8(nox_xxx_guiFontHeightMB_43F320(v3.DrawData().FontPtr)))
	} else {
		nox_xxx_drawGetStringSize_43F840(v3.DrawData().FontPtr, v6, nil, (*int32)(unsafe.Pointer(&win)), v5)
		*(*uint8)(unsafe.Add(unsafe.Pointer(v4.ItemsPtr), uintptr(uint32(int32(v4.Field_11_1)*524))+520)) = uint8(uintptr(unsafe.Pointer(win)))
	}
	v4.Field_11_1++
	v4.Field_11_0++
	nox_xxx_wndListBox_4A3A70(v3)
}
func nox_xxx_wndListBox_4A3A70(win *gui.Window) {
	sdata := (*gui.ScrollListBoxData)(win.WidgetData)
	if int32(sdata.Field_11_0) > 0 {
		v4 := 0
		v1 := 0
		v2 := 0
		for {
			v5 := unsafe.Add(unsafe.Pointer(sdata.ItemsPtr), v4)
			v1++
			v4 += 524
			v2 += int(*(*uint8)(unsafe.Add(v5, 520))) + 1
			*(*uint32)(v5) = uint32(v2)
			if v1 >= int(sdata.Field_11_0) {
				break
			}
		}
	}
	sdata.Field_10 = uint32(v2)
	nox_xxx_wndListBox_4A2D10(win, 0, 1)
}
func nox_xxx_wndListBox_4A2D10(win *gui.Window, a2 int32, a3 int32) {
	a1 := win
	var (
		v4 int32
		v5 int32
		v7 int32
	)
	v3 := (*gui.ScrollListBoxData)(a1.WidgetData)
	v4 = a2 + sub_4A4800(v3)
	if v4 >= 0 {
		v5 = int32(v3.Field_11_0)
		if v4 >= v5 {
			v4 = v5 - 1
		}
	} else {
		v4 = 0
	}
	if a3 != 0 {
		if v4 <= 0 {
			v3.Field_13_1 = 0
		} else {
			v3.Field_13_1 = uint16(int16(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v3.ItemsPtr), uintptr(uint32(v4*524)-524)))) + 1))
		}
	}
	r2 := v3.Slider
	if r2 == nil {
		return
	}
	r3 := r2.WidgetData
	v7 = int32(v3.Field_10 - uint32(v3.Field_13_0) + 3)
	*(*uint32)(unsafe.Add(r3, 4)) = uint32(v7)
	if v7 < 0 {
		*(*uint32)(unsafe.Add(r3, 4)) = 0
	}
	*(*float32)(unsafe.Add(r3, 8)) = float32(float64(int32(v3.Slider.SizeVal.Y-v3.Slider.Field100Ptr.SizeVal.Y)) / float64(*(*int32)(unsafe.Add(r3, 4))))
	if a3 != 0 {
		nox_window_call_field_94_fnc(v3.Slider, 16394, uintptr(*(*uint32)(unsafe.Add(r3, 4))-uint32(v3.Field_13_1)), 0)
	}
}
func nox_xxx_wndListboxDrawNoImage_4A3C50(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win
		a2    = draw
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		v8    int32
		v9    int32
		v11   int32
		v12   int32
		v15   *int16
		v16   int32
		v19   int32
		v20   int32
		v21   int32
		v22   int32
		v23   int32
		v24   int32
		yTop  int32
		xLeft int32
		v27   int32
		i     int32
		v29   int32
		v30   [256]int16
	)
	v2 := (*gui.ScrollListBoxData)(a1.WidgetData)
	v20 = int32(a2.EnColorVal)
	v23 = int32(a2.BgColorVal)
	nox_client_wndGetPosition_46AA60(win, &xLeft, &yTop)
	v3 := nox_xxx_guiFontHeightMB_43F320(a2.FontPtr)
	v4 = int32(a1.SizeVal.Y)
	v22 = int32(a1.SizeVal.X)
	if (a1.Flags & 0x2000) == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	nox_xxx_wndDraw_49F7F0()
	if v2.HasScroll != 0 {
		v22 -= 10
	}
	if int32(*(*uint16)(unsafe.Add(a2.C(), 72))) != 0 {
		nox_xxx_drawSetTextColor_434390(int32(a2.TextColorVal))
		nox_xxx_drawStringWrap_43FAF0(a2.FontPtr, (*wchar2_t)(unsafe.Add(a2.C(), 72)), xLeft+1, yTop, v22, v3)
		v4 += -1 - v3
		yTop += v3 + 1
	}
	if a1.Flags&8 == 0 {
		v5 = int32(a2.DisColorVal)
		v6 = v20
	} else if int32(*(*uint8)(a2.C()))&2 != 0 {
		v6 = int32(a2.HlColorVal)
		v5 = v23
	} else {
		v5 = v23
		v6 = v20
	}
	if uint32(v5) != 0x80000000 {
		nox_client_drawSetColor_434460(v5)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, v22, v4)
	}
	if uint32(v6) != 0x80000000 {
		nox_client_drawSetColor_434460(v6)
		nox_client_drawBorderLines_49CC70(xLeft, yTop, v22, v4)
	}
	nox_client_copyRect_49F6F0(xLeft, yTop, v22, v4)
	v7 = int32(v2.Field_13_1)
	v8 = yTop - v7
	v21 = yTop - v7
	if a2.TextColorVal != 0x80000000 {
		v9 = 0
		v24 = 0
		for i = 0; ; i = v9 {
			if v9 > 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(v2.ItemsPtr), uintptr(uint32(v9)-524))) > uint32(int32(v2.Field_13_1)+int32(v2.Field_13_0)) || v24 == int32(v2.Field_11_0) {
				break
			}
			v10 := unsafe.Add(unsafe.Pointer(v2.ItemsPtr), uint32(v9))
			if *(*uint32)(v10) < uint32(v2.Field_13_1) {
				v21 = v8 + int32(*(*uint8)(unsafe.Add(v10, 520))) + 1
				goto LABEL_38
			}
			v11 = int32(*(*uint8)(unsafe.Add(v10, 520)))
			v19 = int32(*(*uint32)(unsafe.Add(v10, 516)))
			v12 = v11 + 1
			v27 = v11 + 1
			nox_xxx_drawSetTextColor_434390(v19)
			if v2.HasData != 0 {
				v13 := v2.Field12Slice()
				v14 := v13[0]
				if v13[0] >= 0 {
					for v24 != v14 {
						v13 = v13[1:]
						v14 = v13[0]
						if v14 < 0 {
							goto LABEL_32
						}
					}
					if a2.SelColorVal != 0x80000000 {
						nox_client_drawSetColor_434460(int32(a2.SelColorVal))
						nox_client_drawRectFilledOpaque_49CE30(xLeft, v21, v22, v12)
					}
				}
			} else if v24 == v2.Field12() {
				if a2.SelColorVal != 0x80000000 {
					nox_client_drawSetColor_434460(int32(a2.SelColorVal))
					nox_client_drawRectFilledOpaque_49CE30(xLeft, v21, v22, v12)
				}
			}
		LABEL_32:
			nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2.ItemsPtr), uintptr(uint32(v9))+516))))
			if (a1.Flags & 0x4000) == 0x4000 {
				nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v30[0])), (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2.ItemsPtr), uintptr(uint32(v9))+4)))
				v15 = &v30[nox_wcslen((*wchar2_t)(unsafe.Pointer(&v30[0])))]
				v16 = v22 - 7
				for {
					v17 := a2.FontPtr
					*v15 = 0
					v15 = (*int16)(unsafe.Add(unsafe.Pointer(v15), -int(unsafe.Sizeof(int16(0))*1)))
					nox_xxx_drawGetStringSize_43F840(v17, (*wchar2_t)(unsafe.Pointer(&v30[0])), &v29, nil, 0)
					if v29 <= v16 {
						break
					}
				}
				nox_xxx_drawStringWrap_43FAF0(a2.FontPtr, (*wchar2_t)(unsafe.Pointer(&v30[0])), xLeft+5, v21+2, v16, v27)
				v9 = i
				v12 = v27
			} else {
				nox_xxx_drawStringWrap_43FAF0(a2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2.ItemsPtr), uintptr(uint32(v9))+4)), xLeft+5, v21+2, v22-7, v12)
			}
			v21 += v12
		LABEL_38:
			v8 = v21
			v9 += 524
			v24++
		}
	}
	sub_49F860()
	nox_draw_enableTextSmoothing_43F670(0)
	return 1
}
func nox_xxx_wndListboxDrawWithImage_4A3FC0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win
		a2    = draw
		v4    int32
		v5    noxrender.ImageHandle
		v6    int32
		v7    int32
		v8    int32
		v9    int32
		v10   int32
		v12   int32
		v13   int32
		v16   *int16
		v17   int32
		v21   int32
		v22   int32
		yTop  int32
		xLeft int32
		v25   int32
		v26   int32
		v28   int32
		v29   int32
		v30   [256]int16
	)
	v2 := a2.BgImageHnd
	v3 := (*gui.ScrollListBoxData)(a1.WidgetData)
	v28 = int32(a2.EnColorVal)
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop)
	v4 = int32(a1.SizeVal.Y)
	v22 = int32(a1.SizeVal.X)
	if (a1.Flags & 0x2000) == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	nox_xxx_wndDraw_49F7F0()
	if v3.HasScroll != 0 {
		v22 -= 10
	}
	if a1.Flags&8 != 0 {
		v5 = v2
	} else {
		v5 = a2.DisImageHnd
	}
	if v5 != nil {
		nox_client_drawImageAt_47D2C0(v5, xLeft, yTop)
	}
	if int32(*(*uint16)(unsafe.Add(a2.C(), 72))) != 0 {
		nox_xxx_drawSetTextColor_434390(int32(a2.TextColorVal))
		nox_xxx_drawStringWrap_43FAF0(a2.FontPtr, (*wchar2_t)(unsafe.Add(a2.C(), 72)), xLeft+1, yTop, v22, 0)
		v6 = nox_xxx_guiFontHeightMB_43F320(a2.FontPtr)
		v20 := a2.FontPtr
		yTop += v6 + 1
		v4 += -1 - nox_xxx_guiFontHeightMB_43F320(v20)
	}
	if uint32(v28) != 0x80000000 {
		nox_client_drawSetColor_434460(v28)
		nox_client_drawBorderLines_49CC70(xLeft, yTop, v22, v4)
	}
	nox_client_copyRect_49F6F0(xLeft, yTop, v22, v4)
	v7 = int32(v3.Field_13_1)
	v8 = int32(a2.TextColorVal)
	v9 = yTop - v7
	v25 = yTop - v7
	if uint32(v8) != 0x80000000 {
		v10 = 0
		v26 = 0
		for i := int32(0); ; i = v10 {
			if v10 > 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(v3.ItemsPtr), uintptr(uint32(v10)-524))) > uint32(int32(v3.Field_13_1)+int32(v3.Field_13_0)) || v26 == int32(v3.Field_11_0) {
				break
			}
			v11 := unsafe.Add(unsafe.Pointer(v3.ItemsPtr), uint32(v10))
			if *(*uint32)(v11) < uint32(v3.Field_13_1) {
				v25 = v9 + int32(*(*uint8)(unsafe.Add(v11, 520))) + 1
				goto LABEL_35
			}
			v12 = int32(*(*uint8)(unsafe.Add(v11, 520)))
			v21 = int32(*(*uint32)(unsafe.Add(v11, 516)))
			v13 = v12 + 1
			v28 = v12 + 1
			nox_xxx_drawSetTextColor_434390(v21)
			if v3.HasData != 0 {
				v14 := v3.Field12Slice()
				v15 := v14[0]
				if v14[0] >= 0 {
					for v26 != v15 {
						v14 = v14[1:]
						v15 = v14[0]
						if v15 < 0 {
							goto LABEL_29
						}
					}
					if a2.SelColorVal != 0x80000000 {
						nox_client_drawSetColor_434460(int32(a2.SelColorVal))
						nox_client_drawRectFilledOpaque_49CE30(xLeft, v25, v22, v13)
					}
				}
			} else if v26 == v3.Field12() {
				if a2.SelColorVal != 0x80000000 {
					nox_client_drawSetColor_434460(int32(a2.SelColorVal))
					nox_client_drawRectFilledOpaque_49CE30(xLeft, v25, v22, v13)
				}
			}
		LABEL_29:
			nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3.ItemsPtr), uint32(v10)+516))))
			if (a1.Flags & 0x4000) == 0x4000 {
				nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v30[0])), (*wchar2_t)(unsafe.Add(unsafe.Pointer(v3.ItemsPtr), uint32(v10)+4)))
				v16 = &v30[nox_wcslen((*wchar2_t)(unsafe.Pointer(&v30[0])))]
				v17 = v22 - 7
				for {
					v18 := a2.FontPtr
					*v16 = 0
					v16 = (*int16)(unsafe.Add(unsafe.Pointer(v16), -int(unsafe.Sizeof(int16(0))*1)))
					nox_xxx_drawGetStringSize_43F840(v18, (*wchar2_t)(unsafe.Pointer(&v30[0])), &v29, nil, 0)
					if v29 <= v17 {
						break
					}
				}
				nox_xxx_drawStringWrap_43FAF0(a2.FontPtr, (*wchar2_t)(unsafe.Pointer(&v30[0])), xLeft+5, v25+2, v17, v28)
				v10 = i
				v13 = v28
			} else {
				nox_xxx_drawStringWrap_43FAF0(a2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v3.ItemsPtr), uint32(v10)+4)), xLeft+5, v25+2, v22-7, v13)
			}
			v25 += v13
		LABEL_35:
			v9 = v25
			v10 += 524
			v26++
		}
	}
	sub_49F860()
	nox_draw_enableTextSmoothing_43F670(0)
	return 1
}
func nox_xxx_wndListboxProcWithData10_4A2DE0(win *gui.Window, p2, p3, a4 uintptr) uintptr {
	var (
		a1 = win
	)
	var v7 uint32
	var v8 int32
	var v9 uint32
	var v10 int32
	var v16 uint32
	var v17 int32
	var v18 uint32
	var v19 int32
	var v21 int32
	v4 := win

	sdata := (*gui.ScrollListBoxData)(win.WidgetData)
	v5 := sdata
	switch p2 {
	case 5, 17, 18:
		return 1
	case 6, 7:
		v7 = uint32(p3 >> 16)
		var a2, a3 int32
		nox_client_wndGetPosition_46AA60(a1, &a2, &a3)
		if int32(*(*uint16)(unsafe.Add(a1.C(), 108))) != 0 {
			v8 = nox_xxx_guiFontHeightMB_43F320(a1.DrawData().FontPtr)
			v9 = uint32(a3 + int32(v8) + 1)
			a3 += v8 + 1
		} else {
			v9 = uint32(a3)
		}
		v10 = 0
		v11i := 0
		items := v5.Items()
		for {
			if v11i > 0 {
				if int32(items[v11i-1].field_0) > int32(int32(v5.Field_13_0)+int32(v5.Field_13_1)) {
					v10 = -1
					v4 = a1
					break
				}
				v4 = a1
			}
			if v10 == int32(v5.Field_11_0) {
				v10 = -1
				break
			} else if int32(items[v11i].field_0) <= int32(v7+uint32(v5.Field_13_1)-v9) {
				v4 = a1
				v10++
				v11i++
			} else {
				v4 = a1
				break
			}
		}
		v12 := v5.Field12Slice()
		v13 := 0
		v14 := v12[0]
		if v12[0] >= 0 {
			v15 := v5.Field12Slice()
			for {
				if v14 == v10 {
					sub_4A3090(sdata, v13)
					nox_window_call_field_94_fnc(v4.DrawData().Window, 16400, uintptr(unsafe.Pointer(v4)), uintptr(v10))
					return 1
				}
				v14 = v15[0]
				v15 = v15[1:]
				v13++
				if v14 < 0 {
					break
				}
			}
		}
		v12[v13] = v10
		v12[v13+1] = -1
		nox_window_call_field_94_fnc(v4.DrawData().Window, 16400, uintptr(unsafe.Pointer(v4)), uintptr(v10))
		return 1
	case 8:
		v21 = int32(a1.DrawData().Style)
		if v21&0x100 != 0 {
			nox_window_call_field_94_fnc(a1.DrawData().Window, 0x4000, uintptr(unsafe.Pointer(a1)), 0)
		}
		return 1
	case 10, 11:
		v16 = uint32(p3 >> 16)
		var a2, a3 int32
		nox_client_wndGetPosition_46AA60(a1, &a2, &a3)
		if int32(*(*uint16)(unsafe.Add(a1.C(), 108))) != 0 {
			v17 = nox_xxx_guiFontHeightMB_43F320(a1.DrawData().FontPtr)
			v18 = uint32(a3 + int32(v17) + 1)
			a3 += v17 + 1
		} else {
			v18 = uint32(a3)
		}
		v19 = 0
		v20i := 0
		items := v5.Items()
		for {
			if v20i > 0 {
				if int32(items[v20i-1].field_0) > int32(int32(v5.Field_13_0)+int32(v5.Field_13_1)) {
					v19 = -1
					nox_window_call_field_94_fnc(a1.DrawData().Window, 16401, uintptr(unsafe.Pointer(a1)), uintptr(v19))
					return 1
				}
				v4 = a1
			}
			if v19 != int32(v5.Field_11_0) {
				if int32(items[v20i].field_0) <= int32(v16+uint32(v5.Field_13_1)-v18) {
					v4 = a1
					v19++
					v20i++
					continue
				}
				nox_window_call_field_94_fnc(a1.DrawData().Window, 16401, uintptr(unsafe.Pointer(a1)), uintptr(v19))
				return 1
			}
			break
		}
		nox_window_call_field_94_fnc(v4.DrawData().Window, 16401, uintptr(unsafe.Pointer(v4)), math.MaxUint32)
		return 1
	case 19:
		if v5.UpButton == nil || int32(v5.Field_13_1) <= 0 {
			return 1
		}
		nox_xxx_wndListBox_4A2D10(win, -1, 1)
		return 1
	case 20:
		if v5.DownButton == nil || int32(v5.Field_13_0)+int32(v5.Field_13_1) > int32(v5.Field_10) {
			return 1
		}
		nox_xxx_wndListBox_4A2D10(win, 1, 1)
		return 1
	case 21:
		if p3 != 15 {
			return 0
		}
		if a4 != 2 {
			return 1
		}
		nox_xxx_wndRetNULL_46A8A0()
		return 1
	default:
		return 0
	}
}
func nox_xxx_wndListboxProcWithoutData10_4A28E0(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	var v9 int32
	var v10 int32
	var v11 int32
	var v12 uint32
	var v13 uint32
	var v14 int32
	var v15 int32
	var v16 int32
	var v18 uint32
	var v19 int32
	var v20 int32
	var v21 int32
	var v22 int32
	v4 := win
	v5 := (*gui.ScrollListBoxData)(win.WidgetData)
	switch a2 {
	case 5, 17, 18:
		return 1
	case 6, 7:
		v12 = uint32(p3)
		a3 := v5.Field12()
		v13 = v12 >> 16
		var a1, a4 int32
		nox_client_wndGetPosition_46AA60(win, &a1, &a4)
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*54))) != 0 {
			v14 = nox_xxx_guiFontHeightMB_43F320(v4.DrawData().FontPtr)
			a4 += v14 + 1
		}
		v15 = 0
		v5.SetField12(-2)
		v16 = 0
		for {
			if v16 > 0 && *(*int32)(unsafe.Add(unsafe.Pointer(v5.ItemsPtr), uintptr(uint32(v16)-524))) > int32(v5.Field_13_0)+int32(v5.Field_13_1) || v15 == int32(v5.Field_11_0) {
				v5.SetField12(-1)
			} else if *(*int32)(unsafe.Add(unsafe.Pointer(v5.ItemsPtr), uintptr(uint32(v16)))) <= int32(v13+uint32(v5.Field_13_1)-uint32(a4)) {
				v15++
				v16 += 524
				continue
			}
			break
		}
		v17 := a3
		if uint32(v15) == uint32(a3) && v5.Field_5 == 0 {
			v5.SetField12(-1)
		}
		if v5.Field12() == -2 && v15 < int32(v5.Field_11_0) {
			v5.SetField12(v15)
		}
		if v5.Field12() < 0 && v5.Field_5 != 0 {
			v5.SetField12(v17)
		}
		nox_window_call_field_94_fnc(v4.DrawData().Window, 0x4010, uintptr(unsafe.Pointer(v4)), v5.Field_12)
		return 1
	case 8:
		v22 = int32(win.DrawData().Style)
		if v22&0x100 != 0 {
			nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000, uintptr(unsafe.Pointer(win)), 0)
		}
		return 1
	case 10, 11:
		v18 = uint32(p3) >> 16
		var a3, a4 int32
		nox_client_wndGetPosition_46AA60(win, &a3, &a4)
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*54))) != 0 {
			v19 = nox_xxx_guiFontHeightMB_43F320(v4.DrawData().FontPtr)
			a4 += v19 + 1
		}
		v20 = 0
		v21 = 0
		for (v21 <= 0 || *(*uint32)(unsafe.Add(unsafe.Pointer(v5.ItemsPtr), uintptr(uint32(v21)-524))) <= uint32(int32(v5.Field_13_0)+int32(v5.Field_13_1))) && v20 != int32(v5.Field_11_0) {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v5.ItemsPtr), uintptr(uint32(v21)))) > v18+uint32(v5.Field_13_1)-uint32(a4) {
				nox_window_call_field_94_fnc(v4.DrawData().Window, 16401, uintptr(unsafe.Pointer(v4)), uintptr(v20))
				return 1
			}
			v20++
			v21 += 524
		}
		v20 = -1
		nox_window_call_field_94_fnc(v4.DrawData().Window, 16401, uintptr(unsafe.Pointer(v4)), uintptr(v20))
		return 1
	case 19:
		v8 := v5.Field12()
		if v8 == -1 {
			v5.SetField12(0)
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
		} else if v8 > 0 {
			v11 = v8 - 1
			v5.SetField12(v11)
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v5.ItemsPtr), uintptr(uint32(v11*524)))) < uint32(v5.Field_13_1) {
				nox_xxx_wndListBox_4A2D10(win, -1, 1)
			}
		}
		nox_window_call_field_94_fnc(v4.DrawData().Window, 0x4010, uintptr(unsafe.Pointer(v4)), v5.Field_12)
		return 1
	case 20:
		v7 := v5.Field12()
		if v7 == -1 {
			v5.SetField12(0)
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
		} else if v7 < int32(v5.Field_11_0)-1 {
			v9 = v7 + 1
			v10 = int32(v5.Field_13_0) + int32(v5.Field_13_1)
			v5.SetField12(v9)
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v5.ItemsPtr), uintptr(uint32(v9*524)))) > uint32(v10) {
				nox_xxx_wndListBox_4A2D10(win, 1, 1)
			}
		}
		nox_window_call_field_94_fnc(v4.DrawData().Window, 0x4010, uintptr(unsafe.Pointer(v4)), v5.Field_12)
		return 1
	case 21:
		switch p3 {
		case 0xF, 0xCD:
			if p4 != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_46A8A0()
			return 1
		case 0x1C, 0x39:
			if p4 != 1 {
				return 1
			}
			nox_window_call_field_94_fnc(win.DrawData().Window, 0x4010, uintptr(unsafe.Pointer(win)), v5.Field_12)
			return 1
		case 0xC8:
			if p4 != 2 {
				return 1
			}
			v8 := v5.Field12()
			if v8 == -1 {
				v5.SetField12(0)
				nox_xxx_wndListBox_4A2D10(win, 0, 1)
			} else if v8 > 0 {
				v11 = v8 - 1
				v5.SetField12(v11)
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v5.ItemsPtr), uintptr(uint32(v11*524)))) < uint32(v5.Field_13_1) {
					nox_xxx_wndListBox_4A2D10(win, -1, 1)
				}
			}
			nox_window_call_field_94_fnc(v4.DrawData().Window, 0x4010, uintptr(unsafe.Pointer(v4)), v5.Field_12)
			return 1
		case 0xCB:
			if p4 != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_0_46A8B0()
			return 1
		case 0xD0:
			if p4 != 2 {
				return 1
			}
			v7 := v5.Field12()
			if v7 == -1 {
				v5.SetField12(0)
				nox_xxx_wndListBox_4A2D10(win, 0, 1)
			} else if v7 < int32(v5.Field_11_0)-1 {
				v9 = v7 + 1
				v10 = int32(v5.Field_13_0) + int32(v5.Field_13_1)
				v5.SetField12(v9)
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v5.ItemsPtr), uintptr(uint32(v9*524)))) > uint32(v10) {
					nox_xxx_wndListBox_4A2D10(win, 1, 1)
				}
			}
			nox_window_call_field_94_fnc(v4.DrawData().Window, 0x4010, uintptr(unsafe.Pointer(v4)), v5.Field_12)
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}
