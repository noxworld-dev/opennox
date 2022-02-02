package nox

/*
#include "defs.h"
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
#include "GAME5_2.h"
#include "server__script__script.h"
#include "client__gui__guicon.h"
extern unsigned int nox_player_netCode_85319C;
static int nox_call_object_xfer(int (*fnc)(nox_object_t*, int), nox_object_t* a1, int a2) { return fnc(a1, a2); }
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"unsafe"

	"nox/v1/common"
	"nox/v1/common/crypt"
	"nox/v1/common/datapath"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/fs"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
)

var (
	mapLog = log.New("map")
)

type mapSection struct {
	Name string
	Fnc  unsafe.Pointer
}

var (
	noxMapSections = []mapSection{
		{Name: "MapInfo", Fnc: C.nox_server_mapRWMapInfo_42A6E0},
		{Name: "WallMap", Fnc: C.nox_server_mapRWWallMap_429B20},
		{Name: "FloorMap", Fnc: C.nox_server_mapRWFloorMap_422230},
		{Name: "SecretWalls", Fnc: C.nox_server_mapRWSecretWalls_4297C0},
		{Name: "DestructableWalls", Fnc: C.nox_server_mapRWDestructableWalls_429530},
		{Name: "WayPoints", Fnc: C.nox_server_mapRWWaypoints_506260},
		{Name: "DebugData", Fnc: C.nox_server_mapRWDebugData_5060D0},
		{Name: "WindowWalls", Fnc: C.nox_server_mapRWWindowWalls_4292C0},
		{Name: "GroupData", Fnc: C.nox_server_mapRWGroupData_505C30},
		{Name: "ScriptObject", Fnc: C.nox_server_mapRWScriptObject_505A40},
		{Name: "AmbientData", Fnc: C.nox_server_mapRWAmbientData_429200},
		{Name: "Polygons", Fnc: C.nox_server_mapRWPolygons_428CD0},
		{Name: "MapIntro", Fnc: C.nox_server_mapRWMapIntro_505080},
		{Name: "ScriptData", Fnc: C.nox_server_mapRWScriptData_504F90},
		{Name: "ObjectTOC", Fnc: C.nox_server_mapRWObjectTOC_428B30},
		{Name: "ObjectData", Fnc: C.nox_server_mapRWObjectData_504CF0},
	}
	noxMapSectByName = make(map[string]*mapSection)
)

func init() {
	for i := range noxMapSections {
		sect := &noxMapSections[i]
		noxMapSectByName[sect.Name] = sect
	}
}

func nox_xxx_mapWall_426A80(a1, a2 uint32) {
	*memmap.PtrUint32(0x5D4594, 739980) = a1
	*memmap.PtrUint32(0x5D4594, 739984) = a2
}

//export nox_common_checkMapFile_4CFE10
func nox_common_checkMapFile_4CFE10(name *C.char) C.int {
	if err := nox_common_checkMapFile(GoString(name)); err != nil {
		gameLog.Println(err)
		return 0
	}
	return 1
}

func mapReadCryptHeader() (uint32, error) {
	magic, err := cryptFileReadU32()
	if err != nil {
		return 0, err
	}
	if magic == 0xFADEBEEF {
		return 0, nil
	}
	if magic != 0xFADEFACE {
		return 0, fmt.Errorf("unexpected magic: 0x%X", magic)
	}
	var buf [4]byte
	cryptFileReadMaybeAlign(buf[:4])
	return binary.LittleEndian.Uint32(buf[:4]), nil
}

func nox_common_checkMapFile(name string) error {
	path := datapath.Maps(name, name+".map")
	if err := cryptFileOpen(path, 1, crypt.MapKey); err != nil {
		return err
	}
	defer cryptFileClose()
	if _, err := mapReadCryptHeader(); err != nil {
		return err
	}
	var pbuf [32]byte
	cryptFileReadWrite(pbuf[:32])
	if C.nox_server_mapRWMapInfo_42A6E0() == 0 {
		return fmt.Errorf("cannot read map info: %q", name)
	}
	return nil
}

func (s *Server) nox_xxx_serverParseEntireMap_4CFCE0() error {
	mapLog.Printf("server reading map sections")
	v5a, _ := cryptFileReadU32()
	v5b, _ := cryptFileReadU32()
	nox_xxx_mapWall_426A80(v5a, v5b)
	for {
		sect, err := cryptFileReadString8()
		if err != nil {
			return fmt.Errorf("cannot read next section: %w", err)
		}
		mapLog.Printf("section: %q", sect)
		if sect == "" {
			break
		}
		_, _ = cryptFileReadAlignedU32() // skip size
		if ok, err := nox_xxx_mapReadSection(nil, sect); !ok {
			if err != nil {
				return err
			}
			obj := s.newObjectByTypeID(sect)
			if obj == nil || C.nox_call_object_xfer(obj.func_xfer, obj.CObj(), 0) == 0 {
				return fmt.Errorf("cannot decode map object: %q", sect)
			}
			C.nox_xxx_servMapLoadPlaceObj_4F3F50(obj.CObj(), 0, nil)
		}
	}
	if C.sub_579CA0() == 0 {
		return errors.New("sub_579CA0 failed")
	}
	C.sub_4DAF10()
	if noxflags.HasGame(noxflags.GameHost) {
		C.nox_xxx_waypoint_5799C0()
		C.nox_xxx_unitsNewAddToList_4DAC00()
	}
	return nil
}

//export nox_xxx_mapReadSection_426EA0
func nox_xxx_mapReadSection_426EA0(a1 unsafe.Pointer, cname *C.char, cerr *C.uint) C.int {
	panic("TODO")
	//*cerr = 0
	//name := GoString(cname)
	//ok, err := nox_xxx_mapReadSection(a1, name)
	//if err != nil {
	//	gameLog.Printf("cannot parse map section %q: %v", name, err)
	//	*cerr = 1
	//}
	//return C.int(bool2int(ok))
}

func nox_xxx_mapReadSection(a1 unsafe.Pointer, name string) (bool, error) {
	sect, ok := noxMapSectByName[name]
	if !ok {
		mapLog.Printf("unsupported map section: %q", name)
		return false, nil
	}
	if cgoCallIntVoidPtrFunc(sect.Fnc, a1) == 0 {
		return false, fmt.Errorf("cannot parse map section: %q", name)
	}
	return true, nil
}

//export nox_xxx_mapWriteSectionsMB_426E20
func nox_xxx_mapWriteSectionsMB_426E20(a1 unsafe.Pointer) C.int {
	for _, sect := range noxMapSections {
		buf := make([]byte, 1+len(sect.Name)+1)
		buf[0] = byte(len(sect.Name)) + 1
		copy(buf[1:], sect.Name)
		cryptFileWrite(buf)
		nox_xxx_crypt_426C90()
		if cgoCallIntVoidPtrFunc(sect.Fnc, a1) == 0 {
			gameLog.Println("failed to write section: ", sect.Name)
			return 0
		}
		nox_xxx_crypt_426D40()
	}
	return 1
}

func nox_xxx_mapReadSectionSpecial_426F40(a1 unsafe.Pointer, name string, fnc unsafe.Pointer) error {
	if fnc == nil {
		return errors.New("empty map section function")
	}
	_, ok := noxMapSectByName[name]
	if !ok {
		mapLog.Printf("unsupported map section: %q", name)
		return nil // TODO: why is returns true here?
	}
	if cgoCallIntVoidPtrFunc(fnc, a1) == 0 {
		return fmt.Errorf("cannot parse map section: %q", name)
	}
	return nil
}

func nox_xxx_mapCliReadAllA(path string) error {
	mapLog.Printf("client reading map: %q", path)
	if err := cryptFileOpen(path, 1, crypt.MapKey); err != nil {
		return err
	}
	defer cryptFileClose()
	if _, err := mapReadCryptHeader(); err != nil {
		return err
	}
	v9a, _ := cryptFileReadU32()
	v9b, _ := cryptFileReadU32()
	nox_xxx_mapWall_426A80(v9a, v9b)
	for {
		sect, err := cryptFileReadString8()
		if err != nil {
			return fmt.Errorf("cannot read next section: %w", err)
		}
		mapLog.Printf("section: %q", sect)
		if sect == "" {
			break
		}
		sz, _ := cryptFileReadAlignedU32()
		var berr error
		if sect == "ObjectData" {
			berr = nox_xxx_mapReadSectionSpecial_426F40(nil, "ObjectData", C.nox_client_mapSpecialRWObjectData_4AC610)
		} else if noxflags.HasGame(noxflags.GameHost) {
			nox_xxx_cryptSeekCur(int64(sz)) // skip section
		} else {
			_, berr = nox_xxx_mapReadSection(nil, sect)
		}
		if berr != nil {
			return berr
		}
	}
	return nil
}

func nox_xxx_mapCliReadAll_4AC2B0(path string) error {
	if path == "" {
		return errors.New("empty map name")
	}
	path = fs.Normalize(path)
	dir := filepath.Dir(path)
	fname := filepath.Base(path)
	name := strings.TrimSuffix(fname, filepath.Ext(fname))
	if !strings.HasSuffix(strings.TrimRight(dir, "/\\"), name) {
		dir = filepath.Join(common.MapsDir, name)
	}
	fpath := filepath.Join(dir, fname)
	_, err := fs.Stat(fpath)
	if os.IsNotExist(err) {
		err1 := err
		v15 := filepath.Join(dir, name+".nxz")
		if _, err := fs.Stat(v15); os.IsNotExist(err) {
			return err1
		} else if err != nil {
			return err
		}
		if C.nox_xxx_mapNxzDecompress_57BC50(internCStr(v15), internCStr(fpath)) == 0 {
			return errors.New("cannot decompress map")
		}
	} else if err != nil {
		return err
	}
	if err := nox_xxx_mapCliReadAllA(fpath); err != nil {
		return err
	}
	C.nox_xxx_prepareLightningEffects_4BAB30()
	C.sub_4B64C0()
	C.nox_xxx_bookSetColor_45AC40()
	C.nox_xxx_colorInit_4C4FD0()
	C.nox_gui_console_reloadColors_451100()
	C.sub_445FF0()
	C.sub_470680()
	C.sub_461520()
	C.nox_xxx_tile_486060()
	v2 := noxServer.getPlayerByID(int(C.nox_player_netCode_85319C))
	sub_422140(v2)
	C.nox_xxx_gameSetNoMPFlag_4DB230(0)
	if *memmap.PtrInt32(0x973F18, 3800) < 0 {
		if C.sub_461450() == 1 {
			C.sub_461400()
			C.sub_461440(0)
		}
		C.nox_xxx_cliShowHideTubes_470AA0(0)
	}
	return nil
}
