package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"unsafe"
)

type nox_window_flags int32

const (
	NOX_WIN_HIDDEN      nox_window_flags = 0x10
	NOX_WIN_LAYER_FRONT nox_window_flags = 0x20
	NOX_WIN_LAYER_BACK  nox_window_flags = 0x40
)

type nox_window struct {
	id           int32
	flags        nox_window_flags
	width        int32
	height       int32
	off_x        int32
	off_y        int32
	end_x        int32
	end_y        int32
	widget_data  unsafe.Pointer
	draw_data    nox_window_data
	field_92     uint32
	field_93     func(*nox_window, int32, int32, int32) int32
	field_94     func(*nox_window, int32, int32, int32) int32
	draw_func    func(*nox_window, *nox_window_data) int32
	tooltip_func func(*nox_window, *nox_window_data, int32) int32
	prev         *nox_window
	next         *nox_window
	parent       *nox_window
	field_100    *nox_window
}
type nox_window_data struct {
	field_0    uint32
	group      int32
	style      int32
	status     int32
	win        *nox_window
	bg_color   uint32
	bg_image   unsafe.Pointer
	en_color   uint32
	en_image   unsafe.Pointer
	hl_color   uint32
	hl_image   unsafe.Pointer
	dis_color  uint32
	dis_image  unsafe.Pointer
	sel_color  uint32
	sel_image  unsafe.Pointer
	img_px     int32
	img_py     int32
	text_color uint32
	text       [64]wchar2_t
	font       unsafe.Pointer
	tooltip    [64]wchar2_t
}
type nox_window_ref struct {
	win  *nox_window
	next *nox_window_ref
}

func sub_46ACE0(a1 *uint32, a2 int32, a3 int32, a4 int32) {
	for i := int32(a2); i <= a3; i++ {
		var v5 *uint32 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(a1)), i)))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5)))))), a4)
	}
}
func sub_46AD20(a1 *uint32, a2 int32, a3 int32, a4 int32) {
	var (
		i  int32
		v5 *uint32
	)
	for i = a2; i <= a3; i++ {
		v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(a1)), i)))
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5)))))), a4)
	}
}
func nox_gui_getWindowOffs_46AA20(win *nox_window, px *uint32, py *uint32) int32 {
	if win == nil {
		*px = 0
		*py = 0
		return -2
	}
	*px = uint32(win.off_x)
	*py = uint32(win.off_y)
	return 0
}
func nox_client_wndGetPosition_46AA60(win *nox_window, px *uint32, py *uint32) int32 {
	if win == nil {
		return -2
	}
	*px = uint32(win.off_x)
	*py = uint32(win.off_y)
	for i := (*nox_window)(win.parent); i != nil; i = i.parent {
		*px += uint32(i.off_x)
		*py += uint32(i.off_y)
	}
	return 0
}
func nox_xxx_wndPointInWnd_46AAB0(a1 *uint32, a2 int32, a3 int32) bool {
	var (
		v3 *uint32
		v5 int32
		v6 int32 = 0
		v7 int32 = 0
	)
	v3 = a1
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(a1)), (*uint32)(unsafe.Pointer(&a1)), (*uint32)(unsafe.Pointer(&v6)))
	nox_window_get_size((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), &v5, &v7)
	return a2 >= int32(uintptr(unsafe.Pointer(a1))) && a2 <= int32(uintptr(unsafe.Pointer(a1)))+v5 && a3 >= v6 && a3 <= v6+v7
}
func sub_46AB20(a1 *uint32, a2 int32, a3 int32) int32 {
	var v4 int32
	if a1 == nil {
		return -2
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*6)) = uint32(a2) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
	v4 = int32(uint32(a3) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) = uint32(a2)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) = uint32(a3)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) = uint32(v4)
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 16388, a2, a3, internCStr(__FILE__), __LINE__)
	return 0
}
func nox_window_get_size(win *nox_window, outW *int32, outH *int32) int32 {
	if win == nil {
		*outW = 0
		*outH = 0
		return -2
	}
	*outW = win.width
	*outH = win.height
	return 0
}
func nox_xxx_wnd_46ABB0(win *nox_window, a2 int32) int32 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(win)))
		v3 int32
		v4 uint32
		v5 int32
	)
	if a1 == 0 {
		return -2
	}
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))))
	if a2 != 0 {
		v4 = uint32(v3 | 8)
	} else {
		v4 = uint32(v3) & 0xFFFFFFF7
	}
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 400))))
	for *(*uint32)(unsafe.Pointer(uintptr(a1 + 4))) = v4; v5 != 0; v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 388)))) {
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(v5))), a2)
	}
	return 0
}
func nox_xxx_wnd_46AD60(a1 int32, a2 int32) int32 {
	var result int32
	if a1 == 0 {
		return -2
	}
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))) = uint32(a2 | result)
	return result
}
func nox_xxx_wndClearFlag_46AD80(a1 int32, a2 int32) int32 {
	var result int32
	if a1 == 0 {
		return -2
	}
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))) = uint32(result & ^a2)
	return result
}
func nox_xxx_wndGetFlags_46ADA0(a1 int32) int32 {
	var result int32
	if a1 != 0 {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))))
	} else {
		result = -2
	}
	return result
}
func nox_window_is_child(a1 *nox_window, a2 *nox_window) int32 {
	if a1 == nil {
		return 0
	}
	if a2 == nil {
		return 0
	}
	var cur *nox_window = a2
	for {
		cur = cur.parent
		if a1 == cur {
			break
		}
		if cur == nil {
			return 0
		}
	}
	return 1
}
func nox_xxx_wnd_46B280(a1 int32, a2 int32) int32 {
	if a1 == 0 {
		return -2
	}
	if a2 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 52))) = uint32(a2)
	} else {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 52))) = uint32(a1)
	}
	return 0
}
