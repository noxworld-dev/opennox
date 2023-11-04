package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_gui_newScrollListBox_4A4310(par *gui.Window, a2 nox_window_flags, a3, a4, a5, a6 int, draw *gui.WindowData, opts *nox_scrollListBox_data) *gui.Window {
	var (
		a8  = opts
		v19 int32
		v21 int32
		v22 int32
		v23 int32
		v24 [4]int32
		v25 [332]byte
	)
	v21 = 0
	if int32(opts.line_height) < nox_xxx_guiFontHeightMB_43F320(draw.FontPtr) {
		opts.line_height = uint16(int16(nox_xxx_guiFontHeightMB_43F320(draw.FontPtr)))
	}
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(draw), 72))) != 0 {
		v21 = 1
	}
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(draw), 8))) & 0x20) == 0 {
		return nil
	}
	win := nox_window_new(par, a2, a3, a4, a5, a6, nox_xxx_wndListboxProcPre_4A30D0)
	nox_xxx_wndListboxInit_4A3C00(win, opts)
	if win == nil {
		return nil
	}
	if draw.Window == nil {
		draw.Window = win
	}
	nox_gui_windowCopyDrawData_46AF80(win, draw)
	items, _ := alloc.Make([]nox_scrollListBox_item{}, int(opts.count))
	a8.items = &items[0]
	v10 := a6
	a8.field_13_0 = uint16(int16(a6))
	if v21 != 0 {
		a8.field_13_0 -= uint16(int16(nox_xxx_guiFontHeightMB_43F320(draw.FontPtr)))
	}
	a8.field_13_1 = 0
	a8.field_12 = (*uint32)(unsafe.Pointer(uintptr(0xffffffff)))
	a8.field_11_1 = 0
	a8.field_11_0 = 0
	a8.field_10 = 0
	if a8.field_4 != 0 {
		v12, _ := alloc.Make([]uint32{}, int(opts.count))
		a8.field_12 = &v12[0]
		if v12 == nil {
			alloc.FreeSlice(items)
			return nil
		}
		for i := range v12 {
			v12[i] = math.MaxUint32
		}
	}
	if a8.field_3 != 0 {
		v24[0] = 0
		v14 := draw.FontPtr
		v24[1] = 0
		v24[2] = 0
		v24[3] = 0
		v26 := a2 & 0xFFFFEFEF
		v15 := nox_xxx_guiFontHeightMB_43F320(v14)
		if v21 != 0 {
			v22 = v15 + 1
			v10 = v10 - int(v15) - 1
		} else {
			v22 = 0
		}
		*(*[332]byte)(unsafe.Pointer(&v25[0])) = [332]byte{}
		if int32(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(win), 4))))) >= 0 {
			*(*uint32)(unsafe.Pointer(&v25[20])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[44])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[28])) = nox_color_orange_2614256
			*(*uint32)(unsafe.Pointer(&v25[36])) = nox_color_white_2523948
			*(*uint32)(unsafe.Pointer(&v25[52])) = nox_color_yellow_2589772
			*(*uint32)(unsafe.Pointer(&v25[68])) = nox_color_orange_2614256
			v16 := nox_strman_loadString_40F1D0(internCStr("WindowDir:Up"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\Gadgets\\listbox.c"), 1483)
			nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v25[72])), v16)
			v23 = 10
		} else {
			*(*uint32)(unsafe.Pointer(&v25[24])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButton"))
			*(*uint32)(unsafe.Pointer(&v25[40])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButtonLit"))
			*(*uint32)(unsafe.Pointer(&v25[48])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButtonDis"))
			*(*uint32)(unsafe.Pointer(&v25[56])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButtonLit"))
			*(*uint32)(unsafe.Pointer(&v25[32])) = 0
			v23 = 13
		}
		v17 := v26 | 9
		*(*uint32)(unsafe.Pointer(&v25[16])) = uint32(uintptr(unsafe.Pointer(win)))
		*(*uint32)(unsafe.Pointer(&v25[8])) = 1
		a8.field_7 = nox_gui_newButtonOrCheckbox_4A91A0(win, v17, a5-10, int(v22), 10, int(v23), (*gui.WindowData)(unsafe.Pointer(&v25[0])))
		*(*[332]byte)(unsafe.Pointer(&v25[0])) = [332]byte{}
		if int32(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(win), 4))))) >= 0 {
			*(*uint32)(unsafe.Pointer(&v25[20])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[44])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[28])) = nox_color_orange_2614256
			*(*uint32)(unsafe.Pointer(&v25[36])) = nox_color_white_2523948
			*(*uint32)(unsafe.Pointer(&v25[52])) = nox_color_yellow_2589772
			*(*uint32)(unsafe.Pointer(&v25[68])) = nox_color_orange_2614256
			v18 := nox_strman_loadString_40F1D0(internCStr("WindowDir:Down"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\Gadgets\\listbox.c"), 1519)
			nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v25[72])), v18)
		} else {
			*(*uint32)(unsafe.Pointer(&v25[24])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButton"))
			*(*uint32)(unsafe.Pointer(&v25[40])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButtonLit"))
			*(*uint32)(unsafe.Pointer(&v25[48])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButtonDis"))
			*(*uint32)(unsafe.Pointer(&v25[56])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButtonLit"))
			*(*uint32)(unsafe.Pointer(&v25[32])) = 0
		}
		*(*uint32)(unsafe.Pointer(&v25[8])) = 1
		*(*uint32)(unsafe.Pointer(&v25[16])) = uint32(uintptr(unsafe.Pointer(win)))
		a8.field_8 = nox_gui_newButtonOrCheckbox_4A91A0(win, v17, a5-10, int(v22+v10-v23), 10, int(v23), (*gui.WindowData)(unsafe.Pointer(&v25[0])))
		*(*[332]byte)(unsafe.Pointer(&v25[0])) = [332]byte{}
		if int32(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(win), 4))))) >= 0 {
			*(*uint32)(unsafe.Pointer(&v25[20])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[44])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[36])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[28])) = nox_color_orange_2614256
			*(*uint32)(unsafe.Pointer(&v25[52])) = nox_color_orange_2614256
			v19 = 10
		} else {
			*(*uint32)(unsafe.Pointer(&v25[24])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumb"))
			*(*uint32)(unsafe.Pointer(&v25[40])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumbLit"))
			*(*uint32)(unsafe.Pointer(&v25[48])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumbDis"))
			*(*uint32)(unsafe.Pointer(&v25[56])) = nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumbLit"))
			*(*uint32)(unsafe.Pointer(&v25[32])) = 0
			v19 = 9
		}
		v24[0] = 0
		v24[1] = 0
		v24[2] = 0
		*(*uint32)(unsafe.Pointer(&v25[8])) = 8
		v24[3] = 0
		*(*uint32)(unsafe.Pointer(&v25[16])) = uint32(uintptr(unsafe.Pointer(win)))
		a8.field_9 = nox_gui_newSlider_4B4EE0(win, v17, a5-int(v19), int(v22+v23), int(v19), v10-int(v23*2), (*uint32)(unsafe.Pointer(&v25[0])), (*float32)(unsafe.Pointer(&v24[0])))
	}
	d, _ := alloc.New(nox_scrollListBox_data{})
	*d = *opts
	win.WidgetData = unsafe.Pointer(d)
	return win
}
func nox_xxx_wndListboxInit_4A3C00(a1 *gui.Window, a2 *nox_scrollListBox_data) {
	if a1 != nil {
		if int32(int8(a1.Flags)) >= 0 {
			nox_xxx_wndSetDrawFn_46B340(a1, nox_xxx_wndListboxDrawNoImage_4A3C50)
		} else {
			nox_xxx_wndSetDrawFn_46B340(a1, nox_xxx_wndListboxDrawWithImage_4A3FC0)
		}
		if a2.field_4 != 0 {
			nox_xxx_wndSetWindowProc_46B300(a1, nox_xxx_wndListboxProcWithData10_4A2DE0)
		} else {
			nox_xxx_wndSetWindowProc_46B300(a1, nox_xxx_wndListboxProcWithoutData10_4A28E0)
		}
	}
}
func nox_xxx_wndListboxProcPre_4A30D0(win *gui.Window, ev, a3, a4 uintptr) uintptr {
	var (
		v12  int32
		v13  int16
		v14  *uint32
		v15  int32
		v18  int16
		v19  int16
		v20  int32
		v21  int32
		v23  int32
		v24  int32
		v26  *uint32
		v27  int32
		v28  int32
		v29  int16
		v30  int16
		v31  int32
		v32  int16
		v34  int32
		v38  int32
		v39  int16
		v40  int32
		v41  *uint32
		v42  int32
		v43  int32
		v44  int32
		v45  int16
		v46  int32
		v4             = win
		ind  int32     = 0
		wstr *wchar2_t = nil
	)
	sdata := (*nox_scrollListBox_data)(win.WidgetData)
	if ev > 16402 {
		switch ev {
		case 0x4013:
			ind := int(a3)
			if ind < 0 || ind >= int(sdata.count) {
				if sdata.field_4 != 0 {
					libc.MemSet(unsafe.Pointer(sdata.field_12), math.MaxUint8, int(int32(sdata.count)*4))
					return 0
				}
				sdata.field_12 = (*uint32)(unsafe.Pointer(uintptr(math.MaxUint32)))
				return 0
			}
			items := sdata.Items()
			it := &items[ind]
			if it.text[0] == 0 {
				return 0
			}
			if sdata.field_4 != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(sdata.field_12), 4*0)) = uint32(ind)
				*(*uint32)(unsafe.Add(unsafe.Pointer(sdata.field_12), 4*1)) = math.MaxUint32
				return 0
			}
			v38 = int32(sdata.field_13_1)
			sdata.field_12 = (*uint32)(unsafe.Pointer(uintptr(ind)))
			if it.field_0 < uint32(v38) {
				nox_window_call_field_94_fnc(win, 16412, uintptr(ind), 0)
				return 0
			}
			v39 = int16(sdata.field_13_0)
			if it.field_0 > uint32(v38+int32(v39)) {
				if ind <= 0 {
					sdata.field_13_1 = 0
				} else {
					v37 := it
					sdata.field_13_1 = uint16(int16(int32(*(*uint16)(unsafe.Pointer(v37))) - int32(v39)))
				}
				nox_xxx_wndListBox_4A2D10(win, 0, 1)
			}
			return 0
		case 0x4014:
			return uintptr(unsafe.Pointer(sdata.field_12))
		case 0x4015:
			ind := int(a3)
			if ind < 0 || ind >= int(sdata.count) {
				if sdata.field_4 == 0 {
					return 0
				}
				libc.MemSet(unsafe.Pointer(sdata.field_12), math.MaxUint8, int(int32(sdata.count)*4))
				return 0
			}
			items := sdata.Items()
			it := &items[ind]
			if it.text[0] == 0 || sdata.field_4 == 0 {
				return 0
			}
			v33 := sdata.field_12
			v34 = 0
			v35 := *v33
			if int32(*v33) < 0 {
				*(*int32)(unsafe.Add(unsafe.Pointer(v33), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(v34))) = int32(ind)
				*(*uint32)(unsafe.Add(unsafe.Pointer(sdata.field_12), 4*uintptr(v34+1))) = math.MaxUint32
				return 0
			}
			v36 := unsafe.Pointer(sdata.field_12)
			for int(v35) != ind {
				v35 = *(*uint32)(unsafe.Add(v36, 4))
				v36 = unsafe.Add(v36, 4)
				v34++
				if int32(v35) < 0 {
					*(*int32)(unsafe.Add(unsafe.Pointer(v33), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(v34))) = int32(ind)
					*(*uint32)(unsafe.Add(unsafe.Pointer(sdata.field_12), 4*uintptr(v34+1))) = math.MaxUint32
					return 0
				}
			}
			sub_4A3090(sdata, int(v34))
			return 0
		case 0x4016:
			ind = int32(a3)
			if ind < 0 || ind >= int32(sdata.count) {
				return 0
			}
			return uintptr(unsafe.Pointer(&((*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(ind)))).text[0]))
		case 0x4017:
			ind = int32(a4)
			wstr = (*wchar2_t)(unsafe.Pointer(a3))
			if ind < 0 || ind >= int32(sdata.count) {
				return 0
			}
			nox_wcsncpy(&((*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(ind)))).text[0], wstr, math.MaxUint8)
			((*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(ind)))).text[nox_wcslen(wstr)] = 0
			return 0
		case 0x4018:
			sdata.field_7 = (*gui.Window)(unsafe.Pointer(a3))
			return 0
		case 0x4019:
			sdata.field_8 = (*gui.Window)(unsafe.Pointer(a3))
			return 0
		case 0x401A:
			sdata.field_9 = (*gui.Window)(unsafe.Pointer(a3))
			return 0
		case 0x401B:
			ind = int32(a3)
			v40 = int32(sdata.field_11_0)
			if v40 < ind {
				return 0
			}
			libc.MemMove(unsafe.Pointer(sdata.items), unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(ind)), int(uint32(v40-ind)*uint32(unsafe.Sizeof(nox_scrollListBox_item{}))))
			sdata.field_11_0 -= uint16(int16(ind))
			sdata.field_11_1 = sdata.field_11_0
			if sdata.field_4 != 0 {
				v41 = sdata.field_12
				v42 = 0
				if int32(*v41) >= 0 {
					for {
						v43 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v41), 4*uintptr(v42))))
						if ind < v43 {
							sub_4A3090(sdata, func() int {
								p := &v42
								x := *p
								*p--
								return int(x)
							}())
						} else {
							*(*uint32)(unsafe.Add(unsafe.Pointer(v41), 4*uintptr(v42))) = uint32(v43 - ind)
						}
						v41 = sdata.field_12
						v42++
						if int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v41), 4*uintptr(v42)))) < 0 {
							break
						}
					}
				}
			} else {
				v44 = int32(uintptr(unsafe.Pointer(sdata.field_12)))
				if v44 > 0 {
					sdata.field_12 = (*uint32)(unsafe.Pointer(uintptr(v44 - ind)))
				}
			}
			if int32(sdata.field_13_1) > 0 {
				nox_xxx_wndListBox_4A2D10(win, -ind, 1)
			}
			nox_xxx_wndListBox_4A3A70(win)
			return 1
		case 0x401C:
			ind = int32(a3)
			if ind-1 >= 0 && ind-1 < int32(sdata.count) {
				sdata.field_13_1 = uint16(((*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(ind-1)))).field_0 + 1)
			} else {
				sdata.field_13_1 = 0
			}
			v45 = int16(sdata.field_13_0)
			v46 = int32(sdata.field_10)
			if int32(sdata.field_13_1)+int32(v45) >= v46 {
				sdata.field_13_1 = uint16(int16(v46 - int32(v45)))
			}
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
			return 0
		}
		return 0
	}
	if ev == 16402 {
		if int32(a3) >= 0 {
			v32 = int16(sdata.field_11_0)
			if int32(a3) <= int32(v32) {
				sdata.field_11_1 = uint16(a3)
			} else {
				sdata.field_11_1 = uint16(v32)
			}
		} else {
			sdata.field_11_1 = 0
		}
		return 0
	}
	if ev > 0x4007 {
		switch ev {
		case 0x4009:
			v29 = int16(sdata.field_13_0)
			v30 = int16(int32(*(*uint16)(unsafe.Add(sdata.field_9.WidgetData, 4))) - int32(a4))
			v31 = int32(sdata.field_10 - uint32(v29) + 1)
			sdata.field_13_1 = uint16(v30)
			if int32(v30) > v31 {
				sdata.field_13_1 = uint16(int16(int32(sdata.field_10) - int32(v29) + 1))
			}
			if int32(sdata.field_13_1) < 0 {
				sdata.field_13_1 = 0
			}
			nox_xxx_wndListBox_4A2D10(win, 0, 0)
			return 0
		case 16397:
			v18 = int16(sdata.field_11_1)
			v19 = int16(sdata.field_11_0)
			if int32(v18) != int32(v19) {
				if int32(v19) < int32(sdata.count) {
					v20 = int32(v19) - 1
					if v20 >= int32(v18) {
						v21 = v20 * 524
						for {
							v20--
							v22 := unsafe.Add(unsafe.Pointer(&sdata.items.field_0), 4*uintptr(v21))
							v21 -= 524
							alloc.Memcpy(unsafe.Add(v22, 524), v22, 0x20C)
							if v20 < int32(sdata.field_11_1) {
								break
							}
						}
						v4 = win
					}
					nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), v4)
				} else {
					if sdata.field_2 == 0 {
						return 0
					}
					nox_window_call_field_94_fnc(win, 16411, 1, 0)
					v23 = int32(sdata.field_11_0) - 1
					if v23 >= int32(sdata.field_11_1) {
						v24 = v23 * 524
						for {
							v23--
							v25 := unsafe.Add(unsafe.Pointer(sdata.items), v24)
							v24 -= 524
							alloc.Memcpy(unsafe.Add(v25, 524), v25, 0x20C)
							if v23 < int32(sdata.field_11_1) {
								break
							}
						}
						v4 = win
					}
					nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), v4)
				}
			} else if int32(v18) >= int32(sdata.count) {
				if sdata.field_2 == 0 {
					return 0
				}
				nox_window_call_field_94_fnc(win, 16411, 1, 0)
				nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), win)
			} else {
				nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), win)
			}
			if sdata.field_1 != 0 {
				for ((*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(int32(sdata.field_11_1)-1)))).field_0 >= uint32(int32(sdata.field_13_1)+int32(sdata.field_13_0)) {
					nox_xxx_wndListBox_4A2D10(win, 1, 1)
				}
			}
			v26 = sdata.field_12
			if sdata.field_4 != 0 {
				if int32(*v26) >= 0 {
					v27 = 0
					for {
						v28 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v26), 4*uintptr(v27))))
						if int32(sdata.field_11_1) < v28 {
							*(*uint32)(unsafe.Add(unsafe.Pointer(v26), 4*uintptr(v27))) = uint32(v28 + 1)
						}
						v26 = sdata.field_12
						v27++
						if int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v26), 4*uintptr(v27)))) < 0 {
							break
						}
					}
					return 1
				}
			} else if int32(sdata.field_11_1) < int32(uintptr(unsafe.Pointer(v26))) {
				sdata.field_12 = (*uint32)(unsafe.Add(unsafe.Pointer(v26), 1))
			}
			return 1
		case 0x400E:
			ind = int32(a3)
			v12 = int32(sdata.field_11_0)
			if ind < 0 || ind >= v12 {
				return 0
			}
			for i := ind; i < v12-1; i++ {
				alloc.Memcpy(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(i)), unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(i+1)), unsafe.Sizeof(nox_scrollListBox_item{}))
			}
			v13 = int16(func() uint16 {
				p := &sdata.field_11_0
				*p--
				return *p
			}())
			*(*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(v13))) = nox_scrollListBox_item{}
			sdata.field_11_1 = uint16(v13)
			(*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(v13))).text[0] = 0
			if sdata.field_4 != 0 {
				v14 = sdata.field_12
				v15 = 0
				if int32(*v14) >= 0 {
					for {
						v16 := *(*int32)(unsafe.Add(unsafe.Pointer(v14), 4*uintptr(v15)))
						if ind >= int32(v16) {
							if ind == int32(v16) {
								sub_4A3090(sdata, func() int {
									p := &v15
									x := *p
									*p--
									return int(x)
								}())
							}
						} else {
							*(*int32)(unsafe.Add(unsafe.Pointer(v14), 4*uintptr(v15))) = v16 - 1
						}
						v14 = sdata.field_12
						v15++
						if int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*uintptr(v15)))) < 0 {
							break
						}
					}
					nox_xxx_wndListBox_4A3A70(win)
					return 0
				}
			} else {
				v17 := int32(uint32(uintptr(unsafe.Pointer(sdata.field_12))))
				if ind < int32(v17) {
					sdata.field_12 = (*uint32)(unsafe.Pointer(uintptr(uint32(v17 - 1))))
					nox_xxx_wndListBox_4A3A70(win)
					return 0
				}
				if ind == v17 {
					sdata.field_12 = (*uint32)(unsafe.Pointer(uintptr(math.MaxUint32)))
				}
			}
			nox_xxx_wndListBox_4A3A70(win)
			return 0
		case 0x400F:
			items := sdata.Items()
			for i := range items {
				items[i] = nox_scrollListBox_item{}
			}
			if a3 != 1 {
				sdata.field_13_1 = 0
			}
			if sdata.field_4 != 0 {
				libc.MemSet(unsafe.Pointer(sdata.field_12), math.MaxUint8, int(int32(sdata.count)*4))
			} else {
				sdata.field_12 = (*uint32)(unsafe.Pointer(uintptr(math.MaxUint32)))
			}
			sdata.field_11_1 = 0
			sdata.field_11_0 = 0
			sdata.field_10 = 0
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
			return 0
		default:
			return 0
		}
	}
	if ev == 16391 {
		if unsafe.Pointer(a3) == sdata.field_7.C() {
			if int32(sdata.field_13_1) > 0 {
				nox_xxx_wndListBox_4A2D10(win, -1, 1)
				return 0
			}
		} else if unsafe.Pointer(a3) == sdata.field_8.C() && uint32(int32(sdata.field_13_0)+int32(sdata.field_13_1)) <= sdata.field_10 {
			nox_xxx_wndListBox_4A2D10(win, 1, 1)
			return 0
		}
		return 0
	}
	if ev == 16385 {
		wstr = (*wchar2_t)(unsafe.Pointer(a3))
		nox_wcsncpy(&win.DrawData().TextBuf()[0], wstr, 63)
		win.DrawData().TextBuf()[nox_wcslen(wstr)] = 0
		return 0
	}
	if ev == 16388 {
		v9 := sdata.field_7
		if v9 != nil {
			nox_window_setPos_46A9B0(v9, int32(int(a3)-v9.SizeVal.X), 0)
		}
		v10 := sdata.field_8
		if v10 != nil {
			nox_window_setPos_46A9B0(v10, int32(int(a3)-v10.SizeVal.X), int32(int(a4)-v10.SizeVal.Y))
		}
		v11 := sdata.field_9
		if v11 != nil {
			nox_window_setPos_46A9B0(v11, int32(int(a3)-v11.SizeVal.X), int32(sdata.field_7.SizeVal.Y))
			sub_46AB20(sdata.field_9, int32(sdata.field_9.SizeVal.X), int32(int(a4)-sdata.field_9.Field100Ptr.SizeVal.Y*2))
		}
		sdata.field_13_0 = uint16(int16(a4))
		if win.DrawData().TextBuf()[0] != 0 {
			sdata.field_13_0 -= uint16(int16(nox_xxx_guiFontHeightMB_43F320(win.DrawData().FontC())))
		}
		return 0
	}
	if ev > 0x4000 {
		return 0
	}
	if ev == 0x4000 {
		if unsafe.Pointer(a3) == sdata.field_7.C() {
			if int32(sdata.field_13_1) > 0 {
				nox_xxx_wndListBox_4A2D10(win, -1, 1)
				return 0
			}
		} else if unsafe.Pointer(a3) == sdata.field_8.C() && uint32(int32(sdata.field_13_0)+int32(sdata.field_13_1)) <= sdata.field_10 {
			nox_xxx_wndListBox_4A2D10(win, 1, 1)
			return 0
		}
		return 0
	}
	if ev == 2 {
		if sdata != nil {
			alloc.Free(sdata.items)
			if sdata.field_4 != 0 {
				alloc.Free(sdata.field_12)
			}
			alloc.Free(sdata)
		}
		win.WidgetData = nil
		return 0
	}
	if ev == 23 {
		if a3 != 0 {
			win.DrawData().Field0 |= 2
		} else {
			win.DrawData().Field0 &= 0xFFFFFFFD
		}
		v7 := nox_xxx_wndGetID_46B0A0(win)
		nox_window_call_field_94_fnc(win.DrawData().Window, 16387, a3, uintptr(v7))
		return 1
	}
	return 0
}
func sub_4A3090(d *nox_scrollListBox_data, i int) {
	field12 := unsafe.Slice(d.field_12, d.count)
	copy(field12[i:], field12[i+1:])
	field12[d.count-1] = math.MaxUint32
}
func nox_xxx_wndListBoxAddLine_4A3AC0(a1 *wchar2_t, a2 int32, a3 *gui.Window) {
	v3 := a3
	v4 := a3.WidgetData
	v5 := int32(a3.SizeVal.X - 7)
	if *(*uint32)(unsafe.Add(v4, 12)) != 0 {
		v5 = int32(a3.SizeVal.X - 17)
	}
	if a2 >= 17 || a2 < 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 24))+uint32(int32(*(*int16)(unsafe.Add(v4, 46)))*524))), 516)) = a3.DrawData().TextColorVal
	} else {
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 24))+uint32(int32(*(*int16)(unsafe.Add(v4, 46)))*524))), 516)) = **(**uint32)(memmap.PtrOff(0x85B3FC, uintptr(a2*4+132)))
	}
	v6 := (*wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 24))+uint32(int32(*(*int16)(unsafe.Add(v4, 46)))*524))), 4))
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
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 24))+uint32(int32(*(*int16)(unsafe.Add(v4, 46)))*524))), 520)) = uint8(int8(nox_xxx_guiFontHeightMB_43F320(v3.DrawData().FontPtr)))
	} else {
		nox_xxx_drawGetStringSize_43F840(v3.DrawData().FontPtr, v6, nil, (*int32)(unsafe.Pointer(&a3)), v5)
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 24))+uint32(int32(*(*int16)(unsafe.Add(v4, 46)))*524))), 520)) = uint8(uintptr(unsafe.Pointer(a3)))
	}
	*(*uint16)(unsafe.Add(v4, 46))++
	*(*uint16)(unsafe.Add(v4, 44))++
	nox_xxx_wndListBox_4A3A70(v3)
}
func nox_xxx_wndListBox_4A3A70(win *gui.Window) {
	var (
		v1 int32
		v2 int32
	)
	v3 := win.WidgetData
	if int32(*(*uint16)(unsafe.Add(v3, 44))) > 0 {
		v4 := 0
		for {
			v5 := unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 24)), v4)
			v1++
			v4 += 524
			v2 += int32(*(*uint8)(unsafe.Add(v5, 520))) + 1
			*(*uint32)(v5) = uint32(v2)
			if v1 >= int32(*(*int16)(unsafe.Add(v3, 44))) {
				break
			}
		}
	}
	*(*uint32)(unsafe.Add(v3, 40)) = uint32(v2)
	nox_xxx_wndListBox_4A2D10(win, 0, 1)
}
func nox_xxx_wndListBox_4A2D10(win *gui.Window, a2 int32, a3 int32) {
	a1 := win
	var (
		v4 int32
		v5 int32
		v7 int32
	)
	v3 := a1.WidgetData
	v4 = a2 + sub_4A4800(win.WidgetData)
	if v4 >= 0 {
		v5 = int32(*(*int16)(unsafe.Add(v3, 44)))
		if v4 >= v5 {
			v4 = v5 - 1
		}
	} else {
		v4 = 0
	}
	if a3 != 0 {
		if v4 <= 0 {
			*(*uint16)(unsafe.Add(v3, 54)) = 0
		} else {
			*(*uint16)(unsafe.Add(v3, 54)) = uint16(int16(int32(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v3, 24)) + uint32(v4*524) - 524)))) + 1))
		}
	}
	r2 := *(*unsafe.Pointer)(unsafe.Add(v3, 36))
	if r2 == nil {
		return
	}
	r3 := *(*unsafe.Pointer)(unsafe.Add(r2, 32))
	v7 = int32(*(*uint32)(unsafe.Add(v3, 40)) - uint32(*(*int16)(unsafe.Add(v3, 52))) + 3)
	*(*uint32)(unsafe.Add(r3, 4)) = uint32(v7)
	if v7 < 0 {
		*(*uint32)(unsafe.Add(r3, 4)) = 0
	}
	*(*float32)(unsafe.Add(r3, 8)) = float32(float64(int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 36)), 12))-*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 36)), 400)), 12)))) / float64(*(*int32)(unsafe.Add(r3, 4))))
	if a3 != 0 {
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v3, 36))), 16394, uintptr(*(*uint32)(unsafe.Add(r3, 4))-uint32(*(*int16)(unsafe.Add(v3, 54)))), 0)
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
		v13   *int32
		v14   int32
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
	v2 := a1.WidgetData
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
	if *(*uint32)(unsafe.Add(v2, 12)) != 0 {
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
	v7 = int32(*(*int16)(unsafe.Add(v2, 54)))
	v8 = yTop - v7
	v21 = yTop - v7
	if a2.TextColorVal != 0x80000000 {
		v9 = 0
		v24 = 0
		for i = 0; ; i = v9 {
			if v9 > 0 && *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v2, 24)) + uint32(v9) - 524))) > uint32(int32(*(*int16)(unsafe.Add(v2, 54)))+int32(*(*int16)(unsafe.Add(v2, 52)))) || v24 == int32(*(*int16)(unsafe.Add(v2, 44))) {
				break
			}
			v10 := unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 24)), uint32(v9))
			if *(*uint32)(v10) < uint32(*(*int16)(unsafe.Add(v2, 54))) {
				v21 = v8 + int32(*(*uint8)(unsafe.Add(v10, 520))) + 1
				goto LABEL_38
			}
			v11 = int32(*(*uint8)(unsafe.Add(v10, 520)))
			v19 = int32(*(*uint32)(unsafe.Add(v10, 516)))
			v12 = v11 + 1
			v27 = v11 + 1
			nox_xxx_drawSetTextColor_434390(v19)
			if *(*uint32)(unsafe.Add(v2, 16)) != 0 {
				v13 = *(**int32)(unsafe.Add(v2, 48))
				v14 = *v13
				if *v13 >= 0 {
					for v24 != v14 {
						v14 = *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1))
						v13 = (*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1))
						if v14 < 0 {
							goto LABEL_32
						}
					}
					if a2.SelColorVal != 0x80000000 {
						nox_client_drawSetColor_434460(int32(a2.SelColorVal))
						nox_client_drawRectFilledOpaque_49CE30(xLeft, v21, v22, v12)
					}
				}
			} else if uint32(v24) == *(*uint32)(unsafe.Add(v2, 48)) {
				if a2.SelColorVal != 0x80000000 {
					nox_client_drawSetColor_434460(int32(a2.SelColorVal))
					nox_client_drawRectFilledOpaque_49CE30(xLeft, v21, v22, v12)
				}
			}
		LABEL_32:
			nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v2, 24))+uint32(v9))), 516))))
			if (a1.Flags & 0x4000) == 0x4000 {
				nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v30[0])), (*wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v2, 24))+uint32(v9))), 4)))
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
				nox_xxx_drawStringWrap_43FAF0(a2.FontPtr, (*wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v2, 24))+uint32(v9))), 4)), xLeft+5, v21+2, v22-7, v12)
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
		v14   *int32
		v15   int32
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
	v3 := a1.WidgetData
	v28 = int32(a2.EnColorVal)
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop)
	v4 = int32(a1.SizeVal.Y)
	v22 = int32(a1.SizeVal.X)
	if (a1.Flags & 0x2000) == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	nox_xxx_wndDraw_49F7F0()
	if *(*uint32)(unsafe.Add(v3, 12)) != 0 {
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
	v7 = int32(*(*int16)(unsafe.Add(v3, 54)))
	v8 = int32(a2.TextColorVal)
	v9 = yTop - v7
	v25 = yTop - v7
	if uint32(v8) != 0x80000000 {
		v10 = 0
		v26 = 0
		for i := int32(0); ; i = v10 {
			if v10 > 0 && *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v3, 24)) + uint32(v10) - 524))) > uint32(int32(*(*int16)(unsafe.Add(v3, 54)))+int32(*(*int16)(unsafe.Add(v3, 52)))) || v26 == int32(*(*int16)(unsafe.Add(v3, 44))) {
				break
			}
			v11 := unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 24)), uint32(v10))
			if *(*uint32)(v11) < uint32(*(*int16)(unsafe.Add(v3, 54))) {
				v25 = v9 + int32(*(*uint8)(unsafe.Add(v11, 520))) + 1
				goto LABEL_35
			}
			v12 = int32(*(*uint8)(unsafe.Add(v11, 520)))
			v21 = int32(*(*uint32)(unsafe.Add(v11, 516)))
			v13 = v12 + 1
			v28 = v12 + 1
			nox_xxx_drawSetTextColor_434390(v21)
			if *(*uint32)(unsafe.Add(v3, 16)) != 0 {
				v14 = *(**int32)(unsafe.Add(v3, 48))
				v15 = *v14
				if *v14 >= 0 {
					for v26 != v15 {
						v15 = *(*int32)(unsafe.Add(unsafe.Pointer(v14), 4*1))
						v14 = (*int32)(unsafe.Add(unsafe.Pointer(v14), 4*1))
						if v15 < 0 {
							goto LABEL_29
						}
					}
					if a2.SelColorVal != 0x80000000 {
						nox_client_drawSetColor_434460(int32(a2.SelColorVal))
						nox_client_drawRectFilledOpaque_49CE30(xLeft, v25, v22, v13)
					}
				}
			} else if uint32(v26) == *(*uint32)(unsafe.Add(v3, 48)) {
				if a2.SelColorVal != 0x80000000 {
					nox_client_drawSetColor_434460(int32(a2.SelColorVal))
					nox_client_drawRectFilledOpaque_49CE30(xLeft, v25, v22, v13)
				}
			}
		LABEL_29:
			nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 24)), uint32(v10)+516))))
			if (a1.Flags & 0x4000) == 0x4000 {
				nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v30[0])), (*wchar2_t)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 24)), uint32(v10)+4)))
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
				nox_xxx_drawStringWrap_43FAF0(a2.FontPtr, (*wchar2_t)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 24)), uint32(v10)+4)), xLeft+5, v25+2, v22-7, v13)
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
	var v11 int32
	var v12 *int32
	var v13 int32
	var v14 int32
	var v16 uint32
	var v17 int32
	var v18 uint32
	var v19 int32
	var v20 int32
	var v21 int32
	v4 := win

	sdata := (*nox_scrollListBox_data)(win.WidgetData)
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
		v11 = 0
		for {
			if v11 > 0 {
				if *(*int32)(unsafe.Add(unsafe.Pointer(v5.items), uint32(v11)-524)) > int32(int32(v5.field_13_0)+int32(v5.field_13_1)) {
					v10 = -1
					v4 = a1
					break
				}
				v4 = a1
			}
			if v10 == int32(v5.field_11_0) {
				v10 = -1
				break
			} else if *(*int32)(unsafe.Add(unsafe.Pointer(v5.items), uint32(v11))) <= int32(v7+uint32(v5.field_13_1)-v9) {
				v4 = a1
				v10++
				v11 += 524
			} else {
				v4 = a1
				break
			}
		}
		v12 = (*int32)(unsafe.Pointer(v5.field_12))
		v13 = 0
		v14 = *v12
		if *v12 >= 0 {
			v15 := unsafe.Pointer(v5.field_12)
			for {
				if v14 == v10 {
					sub_4A3090(sdata, int(v13))
					nox_window_call_field_94_fnc(v4.DrawData().Window, 16400, uintptr(unsafe.Pointer(v4)), uintptr(v10))
					return 1
				}
				v14 = int32(*(*uint32)(unsafe.Add(v15, 4)))
				v15 = unsafe.Add(v15, 4)
				v13++
				if v14 < 0 {
					break
				}
			}
		}
		*(*int32)(unsafe.Add(unsafe.Pointer(v12), 4*uintptr(v13))) = v10
		*(*uint32)(unsafe.Add(unsafe.Pointer(v5.field_12), uint32(v13)*4+4)) = math.MaxUint32
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
		v20 = 0
		for {
			if v20 > 0 {
				if *(*int32)(unsafe.Add(unsafe.Pointer(v5.items), uint32(v20)-524)) > int32(int32(v5.field_13_0)+int32(v5.field_13_1)) {
					v19 = -1
					nox_window_call_field_94_fnc(a1.DrawData().Window, 16401, uintptr(unsafe.Pointer(a1)), uintptr(v19))
					return 1
				}
				v4 = a1
			}
			if v19 != int32(v5.field_11_0) {
				if *(*int32)(unsafe.Add(unsafe.Pointer(v5.items), uint32(v20))) <= int32(v16+uint32(v5.field_13_1)-v18) {
					v4 = a1
					v19++
					v20 += 524
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
		if v5.field_7 == nil || int32(v5.field_13_1) <= 0 {
			return 1
		}
		nox_xxx_wndListBox_4A2D10(win, -1, 1)
		return 1
	case 20:
		if v5.field_8 == nil || int32(v5.field_13_0)+int32(v5.field_13_1) > int32(v5.field_10) {
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
	var v7 int32
	var v8 int32
	var v9 int32
	var v10 int32
	var v11 int32
	var v12 uint32
	var v13 uint32
	var v14 int32
	var v15 int32
	var v16 int32
	var v17 uint32
	var v18 uint32
	var v19 int32
	var v20 int32
	var v21 int32
	var v22 int32
	v4 := win
	v5 := win.WidgetData
	switch a2 {
	case 5, 17, 18:
		return 1
	case 6, 7:
		v12 = uint32(p3)
		a3 := *(*uint32)(unsafe.Add(v5, 48))
		v13 = v12 >> 16
		var a1, a4 int32
		nox_client_wndGetPosition_46AA60(win, &a1, &a4)
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*54))) != 0 {
			v14 = nox_xxx_guiFontHeightMB_43F320(v4.DrawData().FontPtr)
			a4 += v14 + 1
		}
		v15 = 0
		*(*uint32)(unsafe.Add(v5, 48)) = 4294967294
		v16 = 0
		for {
			if v16 > 0 && *(*int32)(unsafe.Pointer(uintptr(uint32(v16) + *(*uint32)(unsafe.Add(v5, 24)) - 524))) > int32(*(*int16)(unsafe.Add(v5, 52)))+int32(*(*int16)(unsafe.Add(v5, 54))) || v15 == int32(*(*int16)(unsafe.Add(v5, 44))) {
				*(*uint32)(unsafe.Add(v5, 48)) = math.MaxUint32
			} else if *(*int32)(unsafe.Pointer(uintptr(uint32(v16) + *(*uint32)(unsafe.Add(v5, 24))))) <= int32(v13+uint32(*(*int16)(unsafe.Add(v5, 54)))-uint32(a4)) {
				v15++
				v16 += 524
				continue
			}
			break
		}
		v17 = a3
		if uint32(v15) == a3 && *(*uint32)(unsafe.Add(v5, 20)) == 0 {
			*(*uint32)(unsafe.Add(v5, 48)) = math.MaxUint32
		}
		if *(*int32)(unsafe.Add(v5, 48)) == -2 && v15 < int32(*(*int16)(unsafe.Add(v5, 44))) {
			*(*uint32)(unsafe.Add(v5, 48)) = uint32(v15)
		}
		if *(*int32)(unsafe.Add(v5, 48)) < 0 {
			if *(*uint32)(unsafe.Add(v5, 20)) != 0 {
				*(*uint32)(unsafe.Add(v5, 48)) = v17
			}
		}
		nox_window_call_field_94_fnc(v4.DrawData().Window, 16400, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
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
		for (v21 <= 0 || *(*uint32)(unsafe.Pointer(uintptr(uint32(v21) + *(*uint32)(unsafe.Add(v5, 24)) - 524))) <= uint32(int32(*(*int16)(unsafe.Add(v5, 52)))+int32(*(*int16)(unsafe.Add(v5, 54))))) && v20 != int32(*(*int16)(unsafe.Add(v5, 44))) {
			if *(*uint32)(unsafe.Pointer(uintptr(uint32(v21) + *(*uint32)(unsafe.Add(v5, 24))))) > v18+uint32(*(*int16)(unsafe.Add(v5, 54)))-uint32(a4) {
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
		v8 = int32(*(*uint32)(unsafe.Add(v5, 48)))
		if v8 == -1 {
			*(*uint32)(unsafe.Add(v5, 48)) = 0
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
		} else if v8 > 0 {
			v11 = v8 - 1
			*(*uint32)(unsafe.Add(v5, 48)) = uint32(v11)
			if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v5, 24)) + uint32(v11*524)))) < uint32(*(*int16)(unsafe.Add(v5, 54))) {
				nox_xxx_wndListBox_4A2D10(win, -1, 1)
			}
		}
		nox_window_call_field_94_fnc(v4.DrawData().Window, 16400, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
		return 1
	case 20:
		v7 = int32(*(*uint32)(unsafe.Add(v5, 48)))
		if v7 == -1 {
			*(*uint32)(unsafe.Add(v5, 48)) = 0
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
		} else if v7 < int32(*(*int16)(unsafe.Add(v5, 44)))-1 {
			v9 = v7 + 1
			v10 = int32(*(*int16)(unsafe.Add(v5, 52))) + int32(*(*int16)(unsafe.Add(v5, 54)))
			*(*uint32)(unsafe.Add(v5, 48)) = uint32(v9)
			if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v5, 24)) + uint32(v9*524)))) > uint32(v10) {
				nox_xxx_wndListBox_4A2D10(win, 1, 1)
			}
		}
		nox_window_call_field_94_fnc(v4.DrawData().Window, 16400, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
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
			nox_window_call_field_94_fnc(win.DrawData().Window, 16400, uintptr(unsafe.Pointer(win)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
			return 1
		case 0xC8:
			if p4 != 2 {
				return 1
			}
			v8 = int32(*(*uint32)(unsafe.Add(v5, 48)))
			if v8 == -1 {
				*(*uint32)(unsafe.Add(v5, 48)) = 0
				nox_xxx_wndListBox_4A2D10(win, 0, 1)
			} else if v8 > 0 {
				v11 = v8 - 1
				*(*uint32)(unsafe.Add(v5, 48)) = uint32(v11)
				if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v5, 24)) + uint32(v11*524)))) < uint32(*(*int16)(unsafe.Add(v5, 54))) {
					nox_xxx_wndListBox_4A2D10(win, -1, 1)
				}
			}
			nox_window_call_field_94_fnc(v4.DrawData().Window, 16400, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
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
			v7 = int32(*(*uint32)(unsafe.Add(v5, 48)))
			if v7 == -1 {
				*(*uint32)(unsafe.Add(v5, 48)) = 0
				nox_xxx_wndListBox_4A2D10(win, 0, 1)
			} else if v7 < int32(*(*int16)(unsafe.Add(v5, 44)))-1 {
				v9 = v7 + 1
				v10 = int32(*(*int16)(unsafe.Add(v5, 52))) + int32(*(*int16)(unsafe.Add(v5, 54)))
				*(*uint32)(unsafe.Add(v5, 48)) = uint32(v9)
				if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v5, 24)) + uint32(v9*524)))) > uint32(v10) {
					nox_xxx_wndListBox_4A2D10(win, 1, 1)
				}
			}
			nox_window_call_field_94_fnc(v4.DrawData().Window, 16400, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}
