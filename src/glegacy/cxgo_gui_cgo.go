package legacy

import (
	"unsafe"
)

func nox_window_set_all_funcs(win *nox_window, a2 func(int32, int32, int32, int32) int32, draw func(*nox_window, unsafe.Pointer) int32, a4 unsafe.Pointer) int32 {
	return nox_window_set_all_funcs_go(win, unsafe.Pointer(funAddr(a2)), unsafe.Pointer(funAddr(draw)), a4)
}
func nox_window_new(a1 *nox_window, flags int32, a3 int32, a4 int32, w int32, h int32, fnc func(int32, int32, int32, int32) int32) *nox_window {
	return nox_window_new_go(a1, flags, a3, a4, w, h, unsafe.Pointer(funAddr(fnc)))
}
func nox_xxx_wndSetProc_46B2C0(a1 int32, a2 func(int32, int32, int32, int32) int32) int32 {
	return nox_xxx_wndSetProc_46B2C0_go((*nox_window)(unsafe.Pointer(uintptr(a1))), unsafe.Pointer(funAddr(a2)))
}
func nox_xxx_wndSetWindowProc_46B300(a1 int32, a2 func(int32, int32, int32, int32) int32) int32 {
	return nox_xxx_wndSetWindowProc_46B300_go((*nox_window)(unsafe.Pointer(uintptr(a1))), unsafe.Pointer(funAddr(a2)))
}
func nox_xxx_wndSetDrawFn_46B340(a1 int32, a2 func(int32, int32) int32) int32 {
	return nox_xxx_wndSetDrawFn_46B340_go((*nox_window)(unsafe.Pointer(uintptr(a1))), unsafe.Pointer(funAddr(a2)))
}
