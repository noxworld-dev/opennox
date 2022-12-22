package opennox

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
extern unsigned int nox_player_netCode_85319C;
extern unsigned int dword_5d4594_1599644;
extern uint32_t dword_5d4594_1599480;
extern uint32_t dword_5d4594_1599476;
extern void* dword_5d4594_1599540;
extern void* dword_5d4594_1599532;
extern void* dword_5d4594_1599556;
extern void* dword_5d4594_1599548;
extern void* dword_5d4594_1599588;
extern void* dword_5d4594_1599592;
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"fmt"
	"image"
	"io"
	"math"
	"os"
	"path/filepath"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/noxcrypt"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script/noxscript"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/internal/ccall"
	"github.com/noxworld-dev/opennox/v1/internal/cnxz"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
)

var (
	mapLog = log.New("map")
)

type mapSection struct {
	Name string
	Fnc  mapSectionFunc
}

type mapSectionFunc func(cf *cryptfile.CryptFile, a1 unsafe.Pointer) error

var (
	noxMapSections = []mapSection{
		{Name: "MapInfo", Fnc: nox_server_mapRWMapInfo_42A6E0},
		{Name: "WallMap", Fnc: nox_server_mapRWWallMap_429B20},
		{Name: "FloorMap", Fnc: nox_server_mapRWFloorMap_422230},
		{Name: "SecretWalls", Fnc: nox_server_mapRWSecretWalls_4297C0},
		{Name: "DestructableWalls", Fnc: nox_server_mapRWDestructableWalls_429530},
		{Name: "WayPoints", Fnc: nox_server_mapRWWaypoints_506260},
		{Name: "DebugData", Fnc: nox_server_mapRWDebugData_5060D0},
		{Name: "WindowWalls", Fnc: nox_server_mapRWWindowWalls_4292C0},
		{Name: "GroupData", Fnc: nox_server_mapRWGroupData_505C30},
		{Name: "ScriptObject", Fnc: nox_server_mapRWScriptObject_505A40},
		{Name: "AmbientData", Fnc: nox_server_mapRWAmbientData_429200},
		{Name: "Polygons", Fnc: nox_server_mapRWPolygons_428CD0},
		{Name: "MapIntro", Fnc: nox_server_mapRWMapIntro_505080},
		{Name: "ScriptData", Fnc: nox_server_mapRWScriptData_504F90},
		{Name: "ObjectTOC", Fnc: nox_server_mapRWObjectTOC_428B30},
		{Name: "ObjectData", Fnc: nox_server_mapRWObjectData_504CF0},
	}
	noxMapSectByName = make(map[string]*mapSection)
)

func nox_server_mapRWMapInfo_42A6E0(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWMapInfo_42A6E0, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWWallMap_429B20(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWWallMap_429B20, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWFloorMap_422230(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWFloorMap_422230, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWSecretWalls_4297C0(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWSecretWalls_4297C0, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWDestructableWalls_429530(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWDestructableWalls_429530, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWWaypoints_506260(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWWaypoints_506260, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWWindowWalls_4292C0(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWWindowWalls_4292C0, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWGroupData_505C30(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWGroupData_505C30, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}

func nox_xxx_mapCrcGetMB_409B00() uint32 {
	return memmap.Uint32(0x5D4594, 3604)
}

//export nox_xxx_mapSetCrcMB_409B10
func nox_xxx_mapSetCrcMB_409B10(crc uint32) {
	if memmap.Uint32(0x5D4594, 3604) != crc {
		*memmap.PtrUint32(0x5D4594, 3604) = crc
	}
}

func nox_server_mapRWScriptObject_505A40(cf *cryptfile.CryptFile, a1 unsafe.Pointer) (gout error) {
	defer func() {
		if gout != nil {
			log.Printf("nox_server_mapRWScriptObject_505A40: %w (%s)", gout, caller(1))
		}
	}()
	fname := datapath.Data(noxscript.NCobjName)
	C.dword_5d4594_1599644 = 0
	if cf.File.Mode() != binfile.ReadOnly {
		cf.WriteU16(1)
		f, err := ifs.Open(fname)
		if os.IsNotExist(err) {
			cf.WriteU32(0)
			return nil
		} else if err != nil {
			mapLog.Println(err)
			return err
		}
		defer f.Close()
		fi, _ := f.Stat()
		sz := fi.Size()
		cf.WriteU32(uint32(sz))
		if sz == 0 {
			return nil
		}
		_, err = io.CopyN(cf, f, sz)
		if err != nil {
			mapLog.Println(err)
			return err
		}
		return nil
	}
	v10, _ := cf.ReadU16()
	if int16(v10) < 1 {
		return fmt.Errorf("unsupported version: %d", v10)
	}
	if !cf.ReadOnly() {
		return fmt.Errorf("unexpected crypt file state")
	}
	f, err := ifs.Create(fname)
	if err != nil {
		mapLog.Println(err)
		return err
	}
	defer f.Close()
	sz, err := cf.ReadU32()
	if err != nil {
		mapLog.Println(err)
		return err
	}
	C.dword_5d4594_1599644 = C.uint(sz)
	if sz > 0 {
		_, err = io.CopyN(f, cf, int64(sz))
		if err != nil {
			mapLog.Println(err)
			return err
		}
	}
	_ = f.Close()
	if sz <= 0 || noxflags.HasGame(noxflags.GameFlag22|noxflags.GameFlag23) {
		return nil
	}
	if C.nox_script_ncobj_parse_505360() == 0 {
		return fmt.Errorf("nox_script_ncobj_parse_505360 failed")
	}
	return nil
}

func nox_server_mapRWAmbientData_429200(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWAmbientData_429200, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWPolygons_428CD0(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWPolygons_428CD0, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWMapIntro_505080(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWMapIntro_505080, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWScriptData_504F90(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWScriptData_504F90, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}
func nox_server_mapRWObjectTOC_428B30(_ *cryptfile.CryptFile, a1 unsafe.Pointer) error {
	if ccall.CallIntPtr(C.nox_server_mapRWObjectTOC_428B30, a1) == 0 {
		return fmt.Errorf("%s failed", caller(0))
	}
	return nil
}

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
		gameLog.Println("check map file:", err)
		return 0
	}
	return 1
}

func mapReadCryptHeader(cf *cryptfile.CryptFile) (uint32, error) {
	magic, err := cf.ReadU32()
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
	cf.ReadMaybeAlign(buf[:4])
	return binary.LittleEndian.Uint32(buf[:4]), nil
}

func nox_common_checkMapFile(name string) error {
	path := datapath.Maps(name, name+".map")
	if err := cryptfile.OpenGlobal(path, cryptfile.ReadOnly, crypt.MapKey); err != nil {
		return err
	}
	defer cryptfile.Close()
	cf := cryptfile.Global()
	if _, err := mapReadCryptHeader(cf); err != nil {
		return err
	}
	var pbuf [32]byte
	cf.ReadWrite(pbuf[:32])
	if err := nox_server_mapRWMapInfo_42A6E0(cf, nil); err != nil {
		return fmt.Errorf("cannot read map info: %q: %w", name, err)
	}
	return nil
}

func (s *Server) nox_xxx_serverParseEntireMap_4CFCE0(cf *cryptfile.CryptFile) error {
	mapLog.Printf("server reading map sections")
	v5a, _ := cf.ReadU32()
	v5b, _ := cf.ReadU32()
	nox_xxx_mapWall_426A80(v5a, v5b)
	for {
		sect, err := cf.ReadString8()
		if err != nil {
			return fmt.Errorf("cannot read next section: %w", err)
		}
		mapLog.Printf("section: %q", sect)
		if sect == "" {
			break
		}
		_, _ = cf.ReadAlignedU32() // skip size
		if ok, err := nox_xxx_mapReadSection(cf, nil, sect); !ok {
			if err != nil {
				return err
			}
			obj := s.newObjectByTypeID(sect)
			if obj == nil {
				return fmt.Errorf("cannot decode map object: invalid type: %q", sect)
			}
			if err := obj.callXfer(nil); err != nil {
				return fmt.Errorf("cannot decode map object: %q: %w", sect, err)
			}
			C.nox_xxx_servMapLoadPlaceObj_4F3F50(obj.CObj(), 0, nil)
		}
	}
	if C.sub_579CA0() == 0 {
		return errors.New("sub_579CA0 failed")
	}
	s.attachPending()
	if noxflags.HasGame(noxflags.GameHost) {
		C.nox_xxx_waypoint_5799C0()
		s.objectsNewAdd()
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

func nox_xxx_mapReadSection(cf *cryptfile.CryptFile, a1 unsafe.Pointer, name string) (bool, error) {
	sect, ok := noxMapSectByName[name]
	if !ok {
		mapLog.Printf("unsupported map section: %q", name)
		return false, nil
	}
	if err := sect.Fnc(cf, a1); err != nil {
		return false, fmt.Errorf("cannot parse map section: %q: %w", name, err)
	}
	return true, nil
}

//export nox_xxx_mapWriteSectionsMB_426E20
func nox_xxx_mapWriteSectionsMB_426E20(a1 unsafe.Pointer) C.int {
	cf := cryptfile.Global()
	for _, sect := range noxMapSections {
		buf := make([]byte, 1+len(sect.Name)+1)
		buf[0] = byte(len(sect.Name)) + 1
		copy(buf[1:], sect.Name)
		cf.Write(buf)
		cf.SectionStart()
		if err := sect.Fnc(cf, a1); err != nil {
			gameLog.Printf("failed to write section: %q: %v", sect.Name, err)
			return 0
		}
		cf.SectionEnd()
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
	if ccall.CallIntPtr(fnc, a1) == 0 {
		return fmt.Errorf("cannot parse map section: %q", name)
	}
	return nil
}

func nox_xxx_mapCliReadAllA(path string) error {
	mapLog.Printf("client reading map: %q", path)
	if err := cryptfile.OpenGlobal(path, cryptfile.ReadOnly, crypt.MapKey); err != nil {
		return err
	}
	defer cryptfile.Close()
	cf := cryptfile.Global()
	if _, err := mapReadCryptHeader(cf); err != nil {
		return err
	}
	v9a, _ := cf.ReadU32()
	v9b, _ := cf.ReadU32()
	nox_xxx_mapWall_426A80(v9a, v9b)
	for {
		sect, err := cf.ReadString8()
		if err != nil {
			return fmt.Errorf("cannot read next section: %w", err)
		}
		mapLog.Printf("section: %q", sect)
		if sect == "" {
			break
		}
		sz, _ := cf.ReadAlignedU32()
		var berr error
		if sect == "ObjectData" {
			berr = nox_xxx_mapReadSectionSpecial_426F40(nil, "ObjectData", C.nox_client_mapSpecialRWObjectData_4AC610)
		} else if noxflags.HasGame(noxflags.GameHost) {
			cf.Seek(int64(sz), io.SeekCurrent) // skip section
		} else {
			_, berr = nox_xxx_mapReadSection(cf, nil, sect)
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
	path = ifs.Normalize(path)
	dir := filepath.Dir(path)
	fname := filepath.Base(path)
	name := strings.TrimSuffix(fname, filepath.Ext(fname))
	if !strings.HasSuffix(strings.TrimRight(dir, "/\\"), name) {
		dir = filepath.Join(common.MapsDir, name)
	}
	fpath := filepath.Join(dir, fname)
	_, err := ifs.Stat(fpath)
	if os.IsNotExist(err) {
		err1 := err
		zname := filepath.Join(dir, name+".nxz")
		if _, err := ifs.Stat(zname); os.IsNotExist(err) {
			return err1
		} else if err != nil {
			return err
		}
		if err := cnxz.DecompressFile(zname, fpath); err != nil {
			return fmt.Errorf("cannot decompress map %q: %w", zname, err)
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
	guiCon.ReloadColors()
	C.sub_445FF0()
	C.sub_470680()
	C.sub_461520()
	C.nox_xxx_tile_486060()
	v2 := noxServer.getPlayerByID(int(C.nox_player_netCode_85319C))
	sub_422140(v2)
	nox_xxx_gameSetNoMPFlag_4DB230(0)
	if *memmap.PtrInt32(0x973F18, 3800) < 0 {
		if C.sub_461450() == 1 {
			C.sub_461400()
			C.sub_461440(0)
		}
		C.nox_xxx_cliShowHideTubes_470AA0(0)
	}
	return nil
}

func nox_server_mapRWObjectData_504CF0_Read(cf *cryptfile.CryptFile, a2 unsafe.Pointer, v16 unsafe.Pointer) error {
	s := noxServer
	v12, _ := cf.ReadU16()
	if v12 == 0 {
		return nil
	}
	for {
		_, _ = cf.ReadAlignedU32()
		typInd := nox_xxx_objectTOCgetTT(v12)
		typ := s.ObjectTypeByInd(typInd)
		if typ == nil {
			cf.Close()
			return fmt.Errorf("cannot find object with type: %d", typInd)
		}
		obj := s.NewObject(typ)
		var v9a2 unsafe.Pointer
		if a2 != nil {
			v9a2 = v16
		}
		if err := obj.callXfer(v9a2); err != nil {
			cf.Close()
			return fmt.Errorf("xfer decode failed for %s: %w", typ.String(), err)
		}
		var (
			v11 bool
			v7  int
		)
		if obj.Flags().Has(object.FlagTransient) {
			v7 = int(obj.Field32)
			v11 = true
		}
		var v16a2 unsafe.Pointer
		if a2 != nil {
			v16a2 = v16
		}
		if C.nox_xxx_servMapLoadPlaceObj_4F3F50(obj.CObj(), 0, v16a2) == 1 && v11 {
			C.nox_xxx_unitSetDecayTime_511660(obj.CObj(), C.int(v7))
		}
		v12, _ = cf.ReadU16()
		if v12 == 0 {
			return nil
		}
	}
}

func nox_server_mapRWObjectData_504CF0_Write(cf *cryptfile.CryptFile, a2 unsafe.Pointer) error {
	s := noxServer
	for it := s.FirstServerObject(); it != nil; it = it.Next() {
		pos := it.Pos()
		if a2 == nil || sub_4280E0(image.Point{X: int(pos.X), Y: int(pos.Y)}, a2) {
			if sub_4E3B80(C.int(it.TypeInd)) != 0 && nox_xxx_xfer_saveObj51DF90(cf, it) == 0 {
				return fmt.Errorf("cannot write object %s", it.String())
			}
		}
	}
	for obj := asObjectS(s.Objs.UpdatableList2); obj != nil; obj = obj.Next() {
		if a2 != nil {
			pos := obj.Pos()
			if !sub_4280E0(image.Point{X: int(pos.X), Y: int(pos.Y)}, a2) {
				continue
			}
		}
		if obj.Class().Has(object.ClassWeapon) && obj.SubClass()&0x40 != 0 {
			pos := obj.Pos()
			v6 := obj.FirstItem()
			v6.PosVec = pos
			nox_xxx_xfer_saveObj51DF90(cf, v6)
		} else if sub_4E3B80(C.int(obj.TypeInd)) != 0 && nox_xxx_xfer_saveObj51DF90(cf, obj) == 0 {
			return fmt.Errorf("cannot write upd object %s", obj.String())
		}
	}
	if noxflags.HasGame(noxflags.GameFlag22) || !noxflags.HasGame(noxflags.GameHost) || noxflags.HasGame(noxflags.GameFlag23) || C.sub_51DED0() != 0 {
		cf.WriteU16(0)
		return nil
	}
	return fmt.Errorf("object write failed")
}

func sub_4280E0(pt image.Point, a2p unsafe.Pointer) bool {
	a2 := unsafe.Slice((*int32)(a2p), 8)
	if pt.X < int(a2[2]) || pt.X > int(a2[4]) {
		return false
	}
	if pt.Y < int(a2[1]) || pt.Y > int(a2[7]) {
		return false
	}
	if pt.Y > int(a2[3]) {
		if pt.X < int(a2[2])+pt.Y-int(a2[3]) {
			return false
		}
	} else if pt.X < int(a2[0])+int(a2[1])-pt.Y {
		return false
	}
	if pt.Y > int(a2[5]) {
		if pt.X > int(a2[4])+int(a2[5])-pt.Y {
			return false
		}
	} else if pt.X > int(a2[0])+pt.Y-int(a2[1]) {
		return false
	}
	return true
}

func nox_server_mapRWObjectData_504CF0(cf *cryptfile.CryptFile, ptr unsafe.Pointer) error {
	if vers, _ := cf.ReadWriteU16(1); vers > 1 {
		return fmt.Errorf("wrong section version: %d", int(vers))
	}
	v16p, free := alloc.Malloc(16)
	defer free()
	if ptr != nil {
		C.sub_428170(ptr, (*C.int4)(v16p))
	}
	if cf.ReadOnly() {
		return nox_server_mapRWObjectData_504CF0_Read(cf, ptr, v16p)
	}
	return nox_server_mapRWObjectData_504CF0_Write(cf, ptr)
}

func nox_xxx_tileNFromPoint_411160(p types.Pointf) int {
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = p
	return int(C.nox_xxx_tileNFromPoint_411160((*C.float2)(unsafe.Pointer(cp))))
}

//export nox_xxx_nxzCompressFile_57BDD0
func nox_xxx_nxzCompressFile_57BDD0(a1, a2 *C.char) int {
	if err := cnxz.CompressFile(GoString(a1), GoString(a2)); err != nil {
		mapLog.Println(err)
		return 0
	}
	return 1
}

//export nox_xxx_mapReset_5028E0
func nox_xxx_mapReset_5028E0() {
	noxServer.nox_xxx_mapReset5028E0()
}
func (s *Server) nox_xxx_mapReset5028E0() {
	C.dword_5d4594_1599480 = math.MaxUint32
	*memmap.PtrUint32(0x5D4594, 1599572) = math.MaxUint32
	C.dword_5d4594_1599476 = 0
	C.dword_5d4594_1599540 = nil
	*memmap.PtrUint32(0x5D4594, 1599544) = 0
	C.dword_5d4594_1599532 = nil
	*memmap.PtrUint32(0x5D4594, 1599536) = 0
	C.dword_5d4594_1599556 = nil
	*memmap.PtrUint32(0x5D4594, 1599560) = 0
	C.dword_5d4594_1599548 = nil
	*memmap.PtrUint32(0x5D4594, 1599552) = 0
	s.mapGroups.refs = nil
	*memmap.PtrUint32(0x5D4594, 1599568) = 0
	*memmap.PtrUint32(0x5D4594, 1599484) = 0
	*memmap.PtrUint32(0x5D4594, 1599488) = 0
	*memmap.PtrUint32(0x5D4594, 1599492) = 0
	*memmap.PtrUint32(0x5D4594, 1599496) = 0
	alloc.Memset(memmap.PtrOff(0x5D4594, 1599500), 0, 32)
	if C.dword_5d4594_1599588 == nil {
		C.dword_5d4594_1599588, _ = alloc.Malloc(2048)
	}
	if C.dword_5d4594_1599592 == nil {
		C.dword_5d4594_1599592, _ = alloc.Malloc(2048)
	}
}

//export nox_xxx_free_503F40
func nox_xxx_free_503F40() {
	noxServer.nox_xxx_free503F40()
}
func (s *Server) nox_xxx_free503F40() {
	{
		var next unsafe.Pointer
		for v0 := unsafe.Pointer(C.dword_5d4594_1599540); v0 != nil; v0 = next {
			next = *(*unsafe.Pointer)(unsafe.Add(v0, 4))
			if C.dword_5d4594_1599476 == 0 {
				s.Objs.FreeObject(asObject(*(*unsafe.Pointer)(unsafe.Add(v0, 0))).SObj())
			}
			alloc.Free(v0)
		}
	}

	{
		var next unsafe.Pointer
		for it := unsafe.Pointer(C.dword_5d4594_1599548); it != nil; it = next {
			next = *(*unsafe.Pointer)(unsafe.Add(it, 4))
			if C.dword_5d4594_1599476 == 0 {
				*(*unsafe.Pointer)(unsafe.Add(it, 0)) = nil
			}
			alloc.Free(it)
		}
	}

	{
		var next unsafe.Pointer
		for it := unsafe.Pointer(C.dword_5d4594_1599556); it != nil; it = next {
			next = *(*unsafe.Pointer)(unsafe.Add(it, 16))

			var next2 unsafe.Pointer
			for it2 := *(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(it, 0)), 16)); it2 != nil; it2 = next2 {
				next2 = *(*unsafe.Pointer)(unsafe.Add(it2, 16))
				C.nox_xxx_tileFreeTileOne_4221E0(it2)
			}
			*(*unsafe.Pointer)(unsafe.Add(it, 0)) = nil
			alloc.Free(it)
		}
	}

	{
		var next unsafe.Pointer
		for it := unsafe.Pointer(C.dword_5d4594_1599532); it != nil; it = next {
			next = *(*unsafe.Pointer)(unsafe.Add(it, 4))
			if C.dword_5d4594_1599476 == 0 && *(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(it, 0)), 4))&0x4 != 0 {
				*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(it, 0)), 4*7)) = nil
			}
			*(*unsafe.Pointer)(unsafe.Add(it, 0)) = nil
			alloc.Free(it)
		}
	}

	{
		var next *mapGroupRef
		for it := s.mapGroups.refs; it != nil; it = next {
			next = it.next4
			if C.dword_5d4594_1599476 == 0 {
				var next2 *mapGroupItem
				for it2 := it.field0.list; it2 != nil; it2 = next2 {
					next2 = it2.next8
					s.mapGroups.allocItem.FreeObjectFirst(it2)
				}
				s.mapGroups.allocGroup.FreeObjectFirst(it.field0)
			}
			alloc.Free(unsafe.Pointer(it))
		}
	}
	*memmap.PtrUint32(0x5D4594, 1599568) = 0
	s.mapGroups.refs = nil
	s.nox_xxx_mapReset5028E0()
}
