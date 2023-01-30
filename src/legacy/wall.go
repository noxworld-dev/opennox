package legacy

/*
#include "GAME1.h"
#include "GAME4_1.h"
extern void* dword_5d4594_251560;
*/
import "C"
import "unsafe"

var (
	Nox_server_getWallAtGrid_410580 func(x, y int) unsafe.Pointer
	Nox_xxx_wall_4105E0             func(x, y int) unsafe.Pointer
)

//export nox_server_getWallAtGrid_410580
func nox_server_getWallAtGrid_410580(x, y int) unsafe.Pointer {
	return Nox_server_getWallAtGrid_410580(x, y)
}

//export nox_xxx_wall_4105E0
func nox_xxx_wall_4105E0(x, y int) unsafe.Pointer { return Nox_xxx_wall_4105E0(x, y) }
func Nox_xxx_wallTileByName_410D60(name string) byte {
	str := CString(name)
	defer StrFree(str)
	return byte(C.nox_xxx_wallTileByName_410D60(str))
}
func Nox_xxx_wallClose_512070(a1 unsafe.Pointer) {
	C.nox_xxx_wallClose_512070(C.int(uintptr(a1)))
}
func Nox_xxx_wallOpen_511F80(a1 unsafe.Pointer) {
	C.nox_xxx_wallOpen_511F80(C.int(uintptr(a1)))
}
func Nox_xxx_wallToggle_512160(a1 unsafe.Pointer) {
	C.nox_xxx_wallToggle_512160(C.int(uintptr(a1)))
}
func Nox_xxx_wallPreDestroyByPtr_5122C0(a1 unsafe.Pointer) {
	C.nox_xxx_wallPreDestroyByPtr_5122C0(C.int(uintptr(a1)))
}
