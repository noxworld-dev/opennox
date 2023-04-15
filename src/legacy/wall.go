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

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_wallFlags                  func(ind int) uint32
	Nox_xxx_wallGetBrickObj_410E60     func(ind int, ind2 int) string
	Nox_xxx_getWallSprite_46A3B0       func(ind int, a2 int, a3 int, a4 int) noxrender.ImageHandle
	Nox_xxx_getWallDrawOffset_46A3F0   func(ind int, a2 int, a3 int, a4 int) image.Point
	Nox_xxx_mapWallMaxVariation_410DD0 func(ind int, a2 int, a3 int) byte
	Nox_xxx_map_410E00                 func(ind int) byte
	Nox_xxx_mapWallGetHpByTile_410E20  func(ind int) byte
	Nox_xxx_wallGetBrickTypeMB_410E40  func(ind int) byte
	Nox_xxx_wallField36                func(ind int) uint16
	Nox_xxx_wallSoundByTile_410EA0     func(ind int) string
	Nox_xxx_wallFindOpenSound_410EE0   func(ind int) string
	Nox_xxx_wallFindCloseSound_410F20  func(ind int) string
	Nox_xxx_wallTileByName_410D60      func(name string) int
	Sub_526CA0                         func(a1 string) int
)

var _ = [1]struct{}{}[12332-unsafe.Sizeof(server.WallDef{})]

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

//export nox_xxx_wallFlags
func nox_xxx_wallFlags(ind int) uint32 {
	return Nox_xxx_wallFlags(ind)
}

//export nox_xxx_wallGetBrickObj_410E60
func nox_xxx_wallGetBrickObj_410E60(ind int, ind2 int) *C.char {
	return internCStr(Nox_xxx_wallGetBrickObj_410E60(ind, ind2))
}

//export nox_xxx_getWallSprite_46A3B0
func nox_xxx_getWallSprite_46A3B0(ind int, a2 int, a3 int, a4 int) unsafe.Pointer {
	return unsafe.Pointer(Nox_xxx_getWallSprite_46A3B0(ind, a2, a3, a4))
}

//export nox_xxx_getWallDrawOffset_46A3F0
func nox_xxx_getWallDrawOffset_46A3F0(ind int, a2 int, a3 int, a4 int, px, py *C.int) {
	v := Nox_xxx_getWallDrawOffset_46A3F0(ind, a2, a3, a4)
	*px = C.int(v.X)
	*py = C.int(v.Y)
}

//export nox_xxx_mapWallMaxVariation_410DD0
func nox_xxx_mapWallMaxVariation_410DD0(ind int, a2 int, a3 int) byte {
	return Nox_xxx_mapWallMaxVariation_410DD0(ind, a2, a3)
}

//export nox_xxx_map_410E00
func nox_xxx_map_410E00(ind int) byte {
	return Nox_xxx_map_410E00(ind)
}

//export nox_xxx_mapWallGetHpByTile_410E20
func nox_xxx_mapWallGetHpByTile_410E20(ind int) byte {
	return Nox_xxx_mapWallGetHpByTile_410E20(ind)
}

//export nox_xxx_wallGetBrickTypeMB_410E40
func nox_xxx_wallGetBrickTypeMB_410E40(ind int) byte {
	return Nox_xxx_wallGetBrickTypeMB_410E40(ind)
}

//export nox_xxx_wallField36
func nox_xxx_wallField36(ind int) uint16 {
	return Nox_xxx_wallField36(ind)
}

//export nox_xxx_wallSoundByTile_410EA0
func nox_xxx_wallSoundByTile_410EA0(ind int) *C.char {
	return internCStr(Nox_xxx_wallSoundByTile_410EA0(ind))
}

//export nox_xxx_wallFindOpenSound_410EE0
func nox_xxx_wallFindOpenSound_410EE0(ind int) *C.char {
	return internCStr(Nox_xxx_wallFindOpenSound_410EE0(ind))
}

//export nox_xxx_wallFindCloseSound_410F20
func nox_xxx_wallFindCloseSound_410F20(ind int) *C.char {
	return internCStr(Nox_xxx_wallFindCloseSound_410F20(ind))
}

//export nox_xxx_wallTileByName_410D60
func nox_xxx_wallTileByName_410D60(name *C.char) int {
	return Nox_xxx_wallTileByName_410D60(GoString(name))
}

//export sub_526CA0
func sub_526CA0(a1 *C.char) int {
	return Sub_526CA0(GoString(a1))
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
