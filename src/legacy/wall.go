package legacy

/*
#include "GAME1.h"
#include "GAME4_1.h"
extern void* dword_5d4594_251560;
*/
import "C"
import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

func asWallP(p unsafe.Pointer) *server.Wall {
	return (*server.Wall)(p)
}

//export nox_server_getWallAtGrid_410580
func nox_server_getWallAtGrid_410580(x, y int) unsafe.Pointer {
	return GetServer().S().Walls.GetWallAtGrid(image.Pt(x, y)).C()
}

//export nox_xxx_wall_4105E0
func nox_xxx_wall_4105E0(x, y int) unsafe.Pointer {
	return GetServer().S().Walls.GetWallAtGrid2(image.Pt(x, y)).C()
}

//export nox_xxx_wallCreateAt_410250
func nox_xxx_wallCreateAt_410250(x, y int) unsafe.Pointer {
	return GetServer().S().Walls.CreateAtGrid(image.Pt(x, y)).C()
}

//export nox_xxx_mapDelWallAtPt_410430
func nox_xxx_mapDelWallAtPt_410430(x, y int) {
	GetServer().S().Walls.DeleteAtGrid(image.Pt(x, y))
}

//export sub_4106A0
func sub_4106A0(y int) unsafe.Pointer {
	return GetServer().S().Walls.IndexByY(y).C()
}

//export nox_xxx_wallForeachFn_410640
func nox_xxx_wallForeachFn_410640(cfnc unsafe.Pointer, data unsafe.Pointer) {
	GetServer().S().Walls.EachWallXxx(func(it *server.Wall) {
		ccall.CallVoidPtr2(cfnc, it.C(), data)
	})
}

//export sub_57B500
func sub_57B500(x, y int, flags C.char) C.char {
	return C.char(GetServer().S().Sub_57B500(image.Pt(x, y), byte(int8(flags))))
}

//export sub_4D72C0
func sub_4D72C0() C.int {
	return C.int(bool2int(GetServer().S().Doors.Sub_4D72C0()))
}

//export sub_4D72B0
func sub_4D72B0(v C.int) {
	GetServer().S().Doors.Sub_4D72B0(v != 0)
}

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
