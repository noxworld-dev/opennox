package legacy

/*
#include "memfile.h"
#include "defs.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME4.h"
extern uint32_t nox_tile_def_cnt;
extern uint32_t dword_5d4594_251572;
int nox_free_tile_defs();
int sub_485F30();
int sub_4F0640();
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
)

var (
	Sub_42BFB0             func()
	Nox_xxx_objectTOCgetTT func(a1 uint16) int
	Sub_42C310             func(a1 int, a2 uint16)
	Sub_42C2E0             func(a1 int) uint16
	Sub_42C300             func() uint16
	Sub_42BFE0             func()
	Sub_4E3AD0             func(ind int) int
)

//export sub_42BFB0
func sub_42BFB0() { Sub_42BFB0() }

//export nox_xxx_objectTOCgetTT_42C2B0
func nox_xxx_objectTOCgetTT_42C2B0(a1 C.ushort) int { return Nox_xxx_objectTOCgetTT(uint16(a1)) }

//export sub_42C310
func sub_42C310(a1 C.int, a2 C.ushort) { Sub_42C310(int(a1), uint16(a2)) }

//export sub_42C2E0
func sub_42C2E0(a1 int) C.ushort { return C.ushort(Sub_42C2E0(a1)) }

//export sub_42C300
func sub_42C300() C.ushort { return C.ushort(Sub_42C300()) }

//export sub_42BFE0
func sub_42BFE0() { Sub_42BFE0() }

//export sub_4E3AD0
func sub_4E3AD0(ind int) int { return Sub_4E3AD0(ind) }
func Sub_4F0640() {
	C.sub_4F0640()
}
func Sub_485CF0() {
	C.nox_free_tile_defs()
}
func Sub_485F30() {
	C.sub_485F30()
}

func Nox_thing_skip_spells_415100(f *binfile.MemFile) {
	C.nox_thing_skip_spells_415100((*nox_memfile)(f.C()))
}

func Nox_thing_read_ability_415320(f *binfile.MemFile) {
	C.nox_thing_read_ability_415320((*nox_memfile)(f.C()))
}

func Nox_thing_skip_AUD_414D40(f *binfile.MemFile) {
	C.nox_thing_skip_AUD_414D40((*nox_memfile)(f.C()))
}

func Nox_thing_skip_AVNT_452B00(f *binfile.MemFile) {
	C.nox_thing_skip_AVNT_452B00((*nox_memfile)(f.C()))
}

func Nox_thing_read_image_415240(f *binfile.MemFile) {
	C.nox_thing_read_image_415240((*nox_memfile)(f.C()))
}

func Nox_thing_read_floor_485B30(f *binfile.MemFile, buf []byte) int {
	if cap(buf) < 256*1024 {
		panic(cap(buf))
	}
	return int(C.nox_thing_read_floor_485B30((*nox_memfile)(f.C()), (*C.char)(unsafe.Pointer(&buf[0]))))
}

func Nox_thing_read_edge_485D40(f *binfile.MemFile, buf []byte) int {
	if cap(buf) < 256*1024 {
		panic(cap(buf))
	}
	return int(C.nox_thing_read_edge_485D40((*nox_memfile)(f.C()), (*C.char)(unsafe.Pointer(&buf[0]))))
}

func Nox_thing_read_WALL_414F60(f *binfile.MemFile, buf []byte) int {
	if cap(buf) < 256*1024 {
		panic(cap(buf))
	}
	return int(C.nox_thing_read_WALL_414F60((*nox_memfile)(f.C()), unsafe.Pointer(&buf[0])))
}

func Nox_thing_read_FLOR_414DB0(f *binfile.MemFile) int {
	return int(C.nox_thing_read_FLOR_414DB0((*nox_memfile)(f.C())))
}

func Nox_thing_read_EDGE_414E70(f *binfile.MemFile, buf []byte) int {
	if cap(buf) < 256*1024 {
		panic(cap(buf))
	}
	return int(C.nox_thing_read_EDGE_414E70((*nox_memfile)(f.C()), unsafe.Pointer(&buf[0])))
}

func Nox_thing_read_audio_415660(f *binfile.MemFile, buf []byte) int {
	if cap(buf) < 256*1024 {
		panic(cap(buf))
	}
	return int(C.nox_thing_read_audio_415660((*nox_memfile)(f.C()), (*C.char)(unsafe.Pointer(&buf[0]))))
}

func Nox_thing_read_AVNT_452890(f *binfile.MemFile, buf []byte) int {
	if cap(buf) < 256*1024 {
		panic(cap(buf))
	}
	return int(C.nox_thing_read_AVNT_452890((*nox_memfile)(f.C()), unsafe.Pointer(&buf[0])))
}

func Nox_thing_read_FLOR_411540(f *binfile.MemFile, buf []byte) int {
	if cap(buf) < 256*1024 {
		panic(cap(buf))
	}
	return int(C.nox_thing_read_FLOR_411540((*nox_memfile)(f.C()), (*C.uchar)(unsafe.Pointer(&buf[0]))))
}

func Nox_thing_read_EDGE_411850(f *binfile.MemFile, buf []byte) int {
	if cap(buf) < 256*1024 {
		panic(cap(buf))
	}
	return int(C.nox_thing_read_EDGE_411850((*nox_memfile)(f.C()), (*C.uchar)(unsafe.Pointer(&buf[0]))))
}

func LoadAllBinFileSectionsResetCounters() {
	C.nox_tile_def_cnt = 0
	C.dword_5d4594_251572 = 0
}
