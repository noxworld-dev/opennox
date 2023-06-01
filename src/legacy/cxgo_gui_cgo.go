package legacy

import (
	"unsafe"
)

func nox_window_set_all_funcs(win *nox_window, a2 unsafe.Pointer, draw unsafe.Pointer, a4 unsafe.Pointer) int32 {
	return nox_window_set_all_funcs_go(win, a2, draw, a4)
}
func nox_window_new(a1 *nox_window, flags nox_window_flags, a3 int32, a4 int32, w int32, h int32, fnc unsafe.Pointer) *nox_window {
	return nox_window_new_go(a1, int(flags), int(a3), int(a4), int(w), int(h), fnc)
}
func nox_xxx_wndSetProc_46B2C0(a1 int32, a2 unsafe.Pointer) int32 {
	return nox_xxx_wndSetProc_46B2C0_go((*nox_window)(unsafe.Pointer(uintptr(a1))), a2)
}
func nox_xxx_wndSetWindowProc_46B300(a1 int32, a2 unsafe.Pointer) int32 {
	return nox_xxx_wndSetWindowProc_46B300_go((*nox_window)(unsafe.Pointer(uintptr(a1))), a2)
}
func nox_xxx_wndSetDrawFn_46B340(a1 int32, a2 unsafe.Pointer) int32 {
	return nox_xxx_wndSetDrawFn_46B340_go((*nox_window)(unsafe.Pointer(uintptr(a1))), a2)
}
