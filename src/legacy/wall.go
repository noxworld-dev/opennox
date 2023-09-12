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

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Sub_526CA0                                func(a1 string) int
	Nox_xxx_mapSetWallInGlobalDir0pr1_5004D0  func()
	Nox_xxx_map_5004F0                        func()
	Sub_4FF990                                func(a1 uint32)
	Nox_xxx_wallDestroyMagicwallSysuse_4FF840 func(a1 *server.Wall)
	Sub_5000B0                                func(a1 *server.Object) int
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
	return GetServer().S().Walls.DefByInd(ind).Flags32
}

//export nox_xxx_wallGetBrickObj_410E60
func nox_xxx_wallGetBrickObj_410E60(ind int, ind2 int) *C.char {
	return internCStr(GetServer().S().Walls.DefByInd(ind).BrickObject(ind2))
}

//export nox_xxx_getWallSprite_46A3B0
func nox_xxx_getWallSprite_46A3B0(ind int, a2 int, a3 int, a4 int) unsafe.Pointer {
	return GetServer().S().Walls.DefByInd(ind).Sprite(a2, a3, a4)
}

//export nox_xxx_getWallDrawOffset_46A3F0
func nox_xxx_getWallDrawOffset_46A3F0(ind int, a2 int, a3 int, a4 int, px, py *C.int) {
	v := GetServer().S().Walls.DefByInd(ind).DrawOffset(a2, a3, a4)
	*px = C.int(v.X)
	*py = C.int(v.Y)
}

//export nox_xxx_mapWallMaxVariation_410DD0
func nox_xxx_mapWallMaxVariation_410DD0(ind int, a2 int, a3 int) byte {
	return GetServer().S().Walls.DefByInd(ind).Variations(a2, a3)
}

//export nox_xxx_map_410E00
func nox_xxx_map_410E00(ind int) byte {
	return GetServer().S().Walls.DefByInd(ind).Field749
}

//export nox_xxx_mapWallGetHpByTile_410E20
func nox_xxx_mapWallGetHpByTile_410E20(ind int) byte {
	return GetServer().S().Walls.DefByInd(ind).Health41
}

//export nox_xxx_wallGetBrickTypeMB_410E40
func nox_xxx_wallGetBrickTypeMB_410E40(ind int) byte {
	return GetServer().S().Walls.DefByInd(ind).BrickType42
}

//export nox_xxx_wallField36
func nox_xxx_wallField36(ind int) uint16 {
	return GetServer().S().Walls.DefByInd(ind).Field36
}

//export nox_xxx_wallSoundByTile_410EA0
func nox_xxx_wallSoundByTile_410EA0(ind int) *C.char {
	return internCStr(GetServer().S().Walls.DefByInd(ind).BreakSound())
}

//export nox_xxx_wallFindOpenSound_410EE0
func nox_xxx_wallFindOpenSound_410EE0(ind int) *C.char {
	return internCStr(GetServer().S().Walls.DefByInd(ind).OpenSound())
}

//export nox_xxx_wallFindCloseSound_410F20
func nox_xxx_wallFindCloseSound_410F20(ind int) *C.char {
	return internCStr(GetServer().S().Walls.DefByInd(ind).CloseSound())
}

//export nox_xxx_wallTileByName_410D60
func nox_xxx_wallTileByName_410D60(name *C.char) int {
	return GetServer().S().Walls.DefIndByName(GoString(name))
}

//export sub_526CA0
func sub_526CA0(a1 *C.char) int {
	return Sub_526CA0(GoString(a1))
}

//export nox_xxx_mapSetWallInGlobalDir0pr1_5004D0
func nox_xxx_mapSetWallInGlobalDir0pr1_5004D0() {
	Nox_xxx_mapSetWallInGlobalDir0pr1_5004D0()
}

//export nox_xxx_map_5004F0
func nox_xxx_map_5004F0() {
	Nox_xxx_map_5004F0()
}

//export sub_4FF990
func sub_4FF990(a1 C.uint) {
	Sub_4FF990(uint32(a1))
}

//export nox_xxx_wallDestroyMagicwallSysuse_4FF840
func nox_xxx_wallDestroyMagicwallSysuse_4FF840(a1 unsafe.Pointer) {
	Nox_xxx_wallDestroyMagicwallSysuse_4FF840((*server.Wall)(a1))
}

//export sub_5000B0
func sub_5000B0(a1 *nox_object_t) int {
	return Sub_5000B0(asObjectS(a1))
}

func Nox_xxx_wallPreDestroyByPtr_5122C0(a1 unsafe.Pointer) {
	C.nox_xxx_wallPreDestroyByPtr_5122C0(C.int(uintptr(a1)))
}

func Nox_xxx_math_509ED0(pos types.Pointf) int {
	cpos, free := alloc.New(types.Pointf{})
	defer free()
	*cpos = pos
	return int(C.nox_xxx_math_509ED0((*C.float2)(unsafe.Pointer(cpos))))
}

func Nox_xxx_math_509EA0(a1 int) int {
	return int(C.nox_xxx_math_509EA0(C.int(a1)))
}
