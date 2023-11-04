package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

type nox_window_flags = gui.StatusFlags

const (
	NOX_WIN_HIDDEN      nox_window_flags = 0x10
	NOX_WIN_LAYER_FRONT nox_window_flags = 0x20
	NOX_WIN_LAYER_BACK  nox_window_flags = 0x40
)

type nox_window_ref struct {
	win  *gui.Window
	next *nox_window_ref
}

func sub_46ACE0(win *gui.Window, a2 int32, a3 int32, a4 int32) {
	for i := a2; i <= a3; i++ {
		v5 := nox_xxx_wndGetChildByID_46B0C0(win, i)
		nox_window_set_hidden(v5, a4)
	}
}
func sub_46AD20(win *gui.Window, a2 int32, a3 int32, a4 int32) {
	for i := a2; i <= a3; i++ {
		v5 := nox_xxx_wndGetChildByID_46B0C0(win, i)
		nox_xxx_wnd_46ABB0(v5, a4)
	}
}
func nox_gui_getWindowOffs_46AA20(win *gui.Window, px *uint32, py *uint32) int32 {
	if win == nil {
		*px = 0
		*py = 0
		return -2
	}
	*px = uint32(win.Off.X)
	*py = uint32(win.Off.Y)
	return 0
}
func nox_client_wndGetPosition_46AA60(win *gui.Window, px *int32, py *int32) int32 {
	if win == nil {
		return -2
	}
	*px = int32(win.Off.X)
	*py = int32(win.Off.Y)
	for i := win.Parent(); i != nil; i = i.Parent() {
		*px += int32(i.Off.X)
		*py += int32(i.Off.Y)
	}
	return 0
}
func nox_xxx_wndPointInWnd_46AAB0(a1 *gui.Window, a2 int32, a3 int32) bool {
	var (
		v3 *uint32
		v5 int32
		v6 int32 = 0
		v7 int32 = 0
	)
	v3 = a1
	nox_client_wndGetPosition_46AA60(a1, (*uint32)(unsafe.Pointer(&a1)), &v6)
	nox_window_get_size((*gui.Window)(unsafe.Pointer(v3)), &v5, &v7)
	return a2 >= int32(uintptr(unsafe.Pointer(a1))) && a2 <= int32(uintptr(unsafe.Pointer(a1)))+v5 && a3 >= v6 && a3 <= v6+v7
}
func sub_46AB20(a1 *gui.Window, a2 int32, a3 int32) int32 {
	var v4 int32
	if a1 == nil {
		return -2
	}
	a1.EndPos.X = int(uint32(a2)) + a1.Off.X
	v4 = int32(int(uint32(a3)) + a1.Off.Y)
	a1.SizeVal.X = int(uint32(a2))
	a1.SizeVal.Y = int(uint32(a3))
	a1.EndPos.Y = int(uint32(v4))
	nox_window_call_field_94_fnc(a1, 16388, uintptr(a2), uintptr(a3))
	return 0
}
func nox_window_get_size(win *gui.Window, outW *int32, outH *int32) int32 {
	if win == nil {
		*outW = 0
		*outH = 0
		return -2
	}
	*outW = int32(win.Size().X)
	*outH = int32(win.Size().Y)
	return 0
}
func nox_xxx_wnd_46ABB0(win *gui.Window, a2 int32) int32 {
	var (
		a1 = unsafe.Pointer(win)
		v4 uint32
	)
	if a1 == nil {
		return -2
	}
	v3 := int32(*(*uint32)(unsafe.Add(a1, 4)))
	if a2 != 0 {
		v4 = uint32(v3 | 8)
	} else {
		v4 = uint32(v3) & 0xFFFFFFF7
	}
	v5 := *(*unsafe.Pointer)(unsafe.Add(a1, 400))
	for *(*uint32)(unsafe.Add(a1, 4)) = v4; v5 != nil; v5 = *(*unsafe.Pointer)(unsafe.Add(v5, 388)) {
		nox_xxx_wnd_46ABB0((*gui.Window)(v5), a2)
	}
	return 0
}
func nox_xxx_wnd_46AD60(a1 *gui.Window, a2 int32) int32 {
	if a1 == nil {
		return -2
	}
	result := int32(a1.Flags)
	a1.Flags |= gui.StatusFlags(a2)
	return result
}
func nox_xxx_wndClearFlag_46AD80(a1 *gui.Window, a2 int32) int32 {
	if a1 == nil {
		return -2
	}
	result := int32(a1.Flags)
	a1.Flags &^= gui.StatusFlags(a2)
	return result
}
func nox_xxx_wndGetFlags_46ADA0(a1 *gui.Window) int32 {
	if a1 != nil {
		return int32(a1.Flags)
	} else {
		return -2
	}
}
func nox_window_is_child(a1 *gui.Window, a2 *gui.Window) int32 {
	if a1 == nil {
		return 0
	}
	if a2 == nil {
		return 0
	}
	var cur *gui.Window = a2
	for {
		cur = cur.Parent()
		if a1 == cur {
			break
		}
		if cur == nil {
			return 0
		}
	}
	return 1
}
func nox_xxx_wnd_46B280(a1 *gui.Window, a2 *gui.Window) int32 {
	if a1 == nil {
		return -2
	}
	if a2 != nil {
		a1.DrawData().Window = a2
	} else {
		a1.DrawData().Window = a1
	}
	return 0
}
