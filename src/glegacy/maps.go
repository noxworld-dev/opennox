package legacy

/*
#include "defs.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME5_2.h"
#include "server__script__script.h"
#include "client__gui__guicon.h"
*/

import (
	"fmt"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/legacy/cnxz"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	gameLog                           = log.New("game")
	mapLog                            = log.New("map")
	Nox_common_checkMapFile           func(name string) error
	Nox_xxx_mapWriteSectionsMB_426E20 func(a1 unsafe.Pointer) int
	Sub_51A100                        func()
)

// nox_common_checkMapFile_4CFE10
func nox_common_checkMapFile_4CFE10(name *char) int {
	if err := Nox_common_checkMapFile(GoString(name)); err != nil {
		gameLog.Println("check map file:", err)
		return 0
	}
	return 1
}

// nox_xxx_mapReadSection_426EA0
func nox_xxx_mapReadSection_426EA0(a1 unsafe.Pointer, cname *char, cerr *uint) int {
	panic("TODO")
}

// nox_xxx_mapWriteSectionsMB_426E20
func nox_xxx_mapWriteSectionsMB_426E20(a1 unsafe.Pointer) int {
	return Nox_xxx_mapWriteSectionsMB_426E20(a1)
}

// nox_xxx_nxzCompressFile_57BDD0
func nox_xxx_nxzCompressFile_57BDD0(a1, a2 *char) int {
	if err := cnxz.CompressFile(GoString(a1), GoString(a2)); err != nil {
		mapLog.Println(err)
		return 0
	}
	return 1
}

// nox_xxx_mapReset_5028E0
func nox_xxx_mapReset_5028E0() {
	GetServer().Nox_xxx_mapReset5028E0()
}

// nox_xxx_free_503F40
func nox_xxx_free_503F40() {
	GetServer().Nox_xxx_free503F40()
}

// sub_51A100
func sub_51A100() {
	Sub_51A100()
}

func Nox_server_mapRWMapInfo_42A6E0(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWMapInfo_42A6E0, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWWallMap_429B20(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWWallMap_429B20, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWFloorMap_422230(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWFloorMap_422230, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWSecretWalls_4297C0(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWSecretWalls_4297C0, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWDestructableWalls_429530(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWDestructableWalls_429530, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWWaypoints_506260(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWWaypoints_506260, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWWindowWalls_4292C0(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWWindowWalls_4292C0, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWGroupData_505C30(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWGroupData_505C30, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWAmbientData_429200(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWAmbientData_429200, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWPolygons_428CD0(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWPolygons_428CD0, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWMapIntro_505080(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWMapIntro_505080, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func Nox_server_mapRWObjectTOC_428B30(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(nox_server_mapRWObjectTOC_428B30, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}

func Sub_579CA0() int {
	return int(sub_579CA0())
}

func Nox_xxx_waypoint_5799C0() {
	nox_xxx_waypoint_5799C0()
}

func Nox_xxx_servMapLoadPlaceObj_4F3F50(obj *server.Object, a2 int, a3 unsafe.Pointer) int {
	return int(nox_xxx_servMapLoadPlaceObj_4F3F50(asObjectC(obj), int(a2), a3))
}

func Nox_xxx_prepareLightningEffects_4BAB30() {
	nox_xxx_prepareLightningEffects_4BAB30()
}

func Sub_4B64C0() {
	sub_4B64C0()
}

func Nox_xxx_bookSetColor_45AC40() {
	nox_xxx_bookSetColor_45AC40()
}

func Nox_xxx_colorInit_4C4FD0() {
	nox_xxx_colorInit_4C4FD0()
}

func Sub_445FF0() {
	sub_445FF0()
}

func Sub_470680() {
	sub_470680()
}

func Sub_461520() {
	sub_461520()
}

func Nox_xxx_tile_486060() {
	nox_xxx_tile_486060()
}

func Sub_461400() {
	sub_461400()
}

func Sub_461450() int {
	return int(sub_461450())
}

func Nox_xxx_cliShowHideTubes_470AA0(v int) {
	nox_xxx_cliShowHideTubes_470AA0(int(v))
}

func Sub_51DED0() int {
	return int(sub_51DED0())
}

func Sub_428170(a1, a2 unsafe.Pointer) {
	sub_428170(a1, (*int4)(a2))
}

func Nox_xxx_tileNFromPoint_411160(p types.Pointf) int {
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = p
	return int(nox_xxx_tileNFromPoint_411160((*float2)(unsafe.Pointer(cp))))
}

func Nox_xxx_unitSetDecayTime_511660(obj *server.Object, a2 int) {
	nox_xxx_unitSetDecayTime_511660(asObjectC(obj), int(a2))
}

func Nox_xxx_tileFreeTileOne_4221E0(p unsafe.Pointer) {
	nox_xxx_tileFreeTileOne_4221E0(p)
}

func Get_nox_client_mapSpecialRWObjectData_4AC610() unsafe.Pointer {
	return nox_client_mapSpecialRWObjectData_4AC610
}

func Sub_4DE410(pli ntype.PlayerInd) {
	sub_4DE410(int(pli))
}
