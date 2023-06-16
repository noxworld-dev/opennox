package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_gui_newScrollListBox_4A4310(a1p *gui.Window, a2 nox_window_flags, a3, a4, a5, a6 int, a7 unsafe.Pointer, opts *nox_scrollListBox_data) *gui.Window {
	var (
		a1  int32  = int32(uintptr(unsafe.Pointer(a1p)))
		a8  *int16 = (*int16)(unsafe.Pointer(opts))
		v8  *uint32
		v9  unsafe.Pointer
		v10 int32
		v11 int32
		v12 unsafe.Pointer
		v14 int32
		v15 int32
		v16 *wchar2_t
		v18 *wchar2_t
		v19 int32
		v20 *int16
		v21 int32
		v22 int32
		v23 int32
		v24 [4]int32
		v25 [332]byte
	)
	v21 = 0
	if int32(opts.line_height) < nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(a7, 200))) {
		opts.line_height = uint16(int16(nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(a7, 200)))))
	}
	if int32(*(*uint16)(unsafe.Add(a7, 72))) != 0 {
		v21 = 1
	}
	if (int32(*(*uint8)(unsafe.Add(a7, 8))) & 0x20) == 0 {
		return nil
	}
	v8 = (*uint32)(unsafe.Pointer(nox_window_new((*gui.Window)(a1), a2, a3, a4, a5, a6, nox_xxx_wndListboxProcPre_4A30D0)))
	nox_xxx_wndListboxInit_4A3C00((*gui.Window)(unsafe.Pointer(v8)), int32(uintptr(unsafe.Pointer(opts))))
	if v8 == nil {
		return nil
	}
	if *(*uint32)(unsafe.Add(a7, 16)) == 0 {
		*(*uint32)(unsafe.Add(a7, 16)) = uint32(uintptr(unsafe.Pointer(v8)))
	}
	nox_gui_windowCopyDrawData_46AF80((*gui.Window)(unsafe.Pointer(v8)), a7)
	arr, _ := alloc.Make([]nox_scrollListBox_item{}, int(opts.count))
	v9 = unsafe.Pointer(&arr[0])
	*((*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*6))) = uint32(uintptr(v9))
	if v9 == nil {
		return nil
	}
	libc.MemSet(v9, 0, int(int32(opts.count)*524))
	v10 = int32(a6)
	*(*int16)(unsafe.Add(unsafe.Pointer(a8), unsafe.Sizeof(int16(0))*26)) = int16(a6)
	if v21 != 0 {
		*(*int16)(unsafe.Add(unsafe.Pointer(a8), unsafe.Sizeof(int16(0))*26)) -= int16(nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(a7, 200))))
	}
	v11 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*4))))
	*(*int16)(unsafe.Add(unsafe.Pointer(a8), unsafe.Sizeof(int16(0))*27)) = 0
	*((*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*12))) = math.MaxUint32
	*(*int16)(unsafe.Add(unsafe.Pointer(a8), unsafe.Sizeof(int16(0))*23)) = 0
	*(*int16)(unsafe.Add(unsafe.Pointer(a8), unsafe.Sizeof(int16(0))*22)) = 0
	*((*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*10))) = 0
	if v11 != 0 {
		v12 = alloc.Calloc1(int(opts.count), 4)
		*((*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*12))) = uint32(uintptr(v12))
		if v12 == nil {
			alloc.FreePtr(*((*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a8), unsafe.Sizeof(unsafe.Pointer(nil))*6))))
			return nil
		}
		libc.MemSet(v12, math.MaxUint8, int(int32(opts.count)*4))
		v10 = int32(a6)
	}
	if *((*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*3))) != 0 {
		v24[0] = 0
		v14 = int32(*(*uint32)(unsafe.Add(a7, 200)))
		v24[1] = 0
		v24[2] = 0
		v24[3] = 0
		v26 := a2 & 0xFFFFEFEF
		v15 = nox_xxx_guiFontHeightMB_43F320(v14)
		if v21 != 0 {
			v22 = v15 + 1
			v10 = v10 - v15 - 1
		} else {
			v22 = 0
		}
		*(*[332]byte)(unsafe.Pointer(&v25[0])) = [332]byte{}
		if int32(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(v8), 4))))) >= 0 {
			*(*uint32)(unsafe.Pointer(&v25[20])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[44])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[28])) = nox_color_orange_2614256
			*(*uint32)(unsafe.Pointer(&v25[36])) = nox_color_white_2523948
			*(*uint32)(unsafe.Pointer(&v25[52])) = nox_color_yellow_2589772
			*(*uint32)(unsafe.Pointer(&v25[68])) = nox_color_orange_2614256
			v16 = nox_strman_loadString_40F1D0(internCStr("WindowDir:Up"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\Gadgets\\listbox.c"), 1483)
			nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v25[72])), v16)
			v23 = 10
		} else {
			*(*uint32)(unsafe.Pointer(&v25[24])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButton")))))
			*(*uint32)(unsafe.Pointer(&v25[40])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButtonLit")))))
			*(*uint32)(unsafe.Pointer(&v25[48])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButtonDis")))))
			*(*uint32)(unsafe.Pointer(&v25[56])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultLBUpButtonLit")))))
			*(*uint32)(unsafe.Pointer(&v25[32])) = 0
			v23 = 13
		}
		v17 := v26 | 9
		*(*uint32)(unsafe.Pointer(&v25[16])) = uint32(uintptr(unsafe.Pointer(v8)))
		*(*uint32)(unsafe.Pointer(&v25[8])) = 1
		*((*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*7))) = uint32(uintptr(unsafe.Pointer(nox_gui_newButtonOrCheckbox_4A91A0((*gui.Window)(unsafe.Pointer(v8)), v26|9, a5-10, int(v22), 10, int(v23), (*gui.WindowData)(unsafe.Pointer(&v25[0]))))))
		*(*[332]byte)(unsafe.Pointer(&v25[0])) = [332]byte{}
		if int32(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(v8), 4))))) >= 0 {
			*(*uint32)(unsafe.Pointer(&v25[20])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[44])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[28])) = nox_color_orange_2614256
			*(*uint32)(unsafe.Pointer(&v25[36])) = nox_color_white_2523948
			*(*uint32)(unsafe.Pointer(&v25[52])) = nox_color_yellow_2589772
			*(*uint32)(unsafe.Pointer(&v25[68])) = nox_color_orange_2614256
			v18 = nox_strman_loadString_40F1D0(internCStr("WindowDir:Down"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\Gadgets\\listbox.c"), 1519)
			nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v25[72])), v18)
		} else {
			*(*uint32)(unsafe.Pointer(&v25[24])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButton")))))
			*(*uint32)(unsafe.Pointer(&v25[40])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButtonLit")))))
			*(*uint32)(unsafe.Pointer(&v25[48])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButtonDis")))))
			*(*uint32)(unsafe.Pointer(&v25[56])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultLBDownButtonLit")))))
			*(*uint32)(unsafe.Pointer(&v25[32])) = 0
		}
		*(*uint32)(unsafe.Pointer(&v25[8])) = 1
		*(*uint32)(unsafe.Pointer(&v25[16])) = uint32(uintptr(unsafe.Pointer(v8)))
		*((*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*8))) = uint32(uintptr(unsafe.Pointer(nox_gui_newButtonOrCheckbox_4A91A0((*gui.Window)(unsafe.Pointer(v8)), v17, a5-10, int(v22+v10-v23), 10, int(v23), (*gui.WindowData)(unsafe.Pointer(&v25[0]))))))
		*(*[332]byte)(unsafe.Pointer(&v25[0])) = [332]byte{}
		if int32(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(v8), 4))))) >= 0 {
			*(*uint32)(unsafe.Pointer(&v25[20])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[44])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[36])) = nox_color_black_2650656
			*(*uint32)(unsafe.Pointer(&v25[28])) = nox_color_orange_2614256
			*(*uint32)(unsafe.Pointer(&v25[52])) = nox_color_orange_2614256
			v19 = 10
		} else {
			*(*uint32)(unsafe.Pointer(&v25[24])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumb")))))
			*(*uint32)(unsafe.Pointer(&v25[40])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumbLit")))))
			*(*uint32)(unsafe.Pointer(&v25[48])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumbDis")))))
			*(*uint32)(unsafe.Pointer(&v25[56])) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DefaultSliderThumbLit")))))
			*(*uint32)(unsafe.Pointer(&v25[32])) = 0
			v19 = 9
		}
		v24[0] = 0
		v24[1] = 0
		v24[2] = 0
		*(*uint32)(unsafe.Pointer(&v25[8])) = 8
		v24[3] = 0
		*(*uint32)(unsafe.Pointer(&v25[16])) = uint32(uintptr(unsafe.Pointer(v8)))
		*((*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*9))) = uint32(uintptr(unsafe.Pointer(nox_gui_newSlider_4B4EE0(int32(uintptr(unsafe.Pointer(v8))), v17, a5-int(v19), int(v22+v23), int(v19), int(v10-v23*2), (*uint32)(unsafe.Pointer(&v25[0])), (*float32)(unsafe.Pointer(&v24[0]))))))
	}
	d, _ := alloc.New(nox_scrollListBox_data{})
	v20 = (*int16)(unsafe.Pointer(d))
	alloc.Memcpy(unsafe.Pointer(v20), unsafe.Pointer(opts), unsafe.Sizeof(nox_scrollListBox_data{}))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*8)) = uint32(uintptr(unsafe.Pointer(v20)))
	return (*gui.Window)(unsafe.Pointer(v8))
}
