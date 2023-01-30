package legacy

/*
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME3_3.h"
#include "GAME4_2.h"
extern uint32_t dword_5d4594_1049844;
extern uint32_t dword_5d4594_1563096;
void nox_xxx_monstersAllBelongToHost_4DB6A0();
void nox_xxx_unitsNewAddToList_4DAC00();
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_savegame_rm                        func(name string, rmDir bool) error
	Nox_client_countPlayerFiles04_4DC7D0   func() int
	Nox_xxx_gameGet_4DB1B0                 func() int
	Sub_4DCC90                             func() int
	Sub_4DB1C0                             func() unsafe.Pointer
	Sub_4DCBF0                             func(a1 int)
	Sub_4460A0                             func(a1 int)
	Sub_40BBC0                             func(a1, a2 int)
	Sub_40B850                             func(a1, act int)
	Sub_40B810                             func(act int, cbuf unsafe.Pointer, sz int)
	Nox_xxx_serverIsClosing_446180         func() int
	Sub_419EB0                             func(i, val int)
	Sub_4DCC10                             func(a1p *server.Object) int
	Nox_xxx_soloGameEscMenuCallback_40AF90 func(ind, a2 int, act int, a4 unsafe.Pointer, cbuf unsafe.Pointer, sz int)
	Sub_4DCFB0                             func(a1p *server.Object)
	Sub_4DD0B0                             func(a1p *server.Object)
)

//export nox_savegame_rm_4DBE10
func nox_savegame_rm_4DBE10(cname *C.char, rmDir int) {
	if cname == nil {
		return
	}
	saveName := GoString(cname)
	Nox_savegame_rm(saveName, rmDir != 0)
}

//export nox_client_countPlayerFiles04_4DC7D0
func nox_client_countPlayerFiles04_4DC7D0() int { return Nox_client_countPlayerFiles04_4DC7D0() }

//export nox_xxx_gameGet_4DB1B0
func nox_xxx_gameGet_4DB1B0() int { return Nox_xxx_gameGet_4DB1B0() }

//export sub_4DCC90
func sub_4DCC90() int { return Sub_4DCC90() }

//export sub_4DB1C0
func sub_4DB1C0() unsafe.Pointer { return Sub_4DB1C0() }

//export sub_4DCBF0
func sub_4DCBF0(a1 int) { Sub_4DCBF0(a1) }

//export sub_4460A0
func sub_4460A0(a1 int) { Sub_4460A0(a1) }

//export sub_40BBC0
func sub_40BBC0(a1, a2 int) { Sub_40BBC0(a1, a2) }

//export sub_40B850
func sub_40B850(a1, act int) { Sub_40B850(a1, act) }

//export sub_40B810
func sub_40B810(act int, cbuf unsafe.Pointer, sz int) { Sub_40B810(act, cbuf, sz) }

//export nox_xxx_serverIsClosing_446180
func nox_xxx_serverIsClosing_446180() int { return Nox_xxx_serverIsClosing_446180() }

//export sub_419EB0
func sub_419EB0(i, val int) { Sub_419EB0(i, val) }

//export sub_4DCC10
func sub_4DCC10(a1p *nox_object_t) int { return Sub_4DCC10(asObjectS(a1p)) }

//export nox_xxx_soloGameEscMenuCallback_40AF90
func nox_xxx_soloGameEscMenuCallback_40AF90(ind, a2 int, act int, a4 unsafe.Pointer, cbuf unsafe.Pointer, sz int) {
	Nox_xxx_soloGameEscMenuCallback_40AF90(ind, a2, act, a4, cbuf, sz)
}

//export sub_4DCFB0
func sub_4DCFB0(a1p *nox_object_t) { Sub_4DCFB0(asObjectS(a1p)) }

//export sub_4DD0B0
func sub_4DD0B0(a1p *nox_object_t) { Sub_4DD0B0(asObjectS(a1p)) }
func Nox_xxx_destroyEveryChatMB_528D60() {
	C.nox_xxx_destroyEveryChatMB_528D60()
}
func Nox_xxx_quickBarClose_4606B0() {
	C.nox_xxx_quickBarClose_4606B0()
}
func Nox_xxx_monstersAllBelongToHost_4DB6A0() {
	C.nox_xxx_monstersAllBelongToHost_4DB6A0()
}
func Nox_xxx_playerSaveToFile_41A140(a1 string, a2 int) int {
	return int(C.nox_xxx_playerSaveToFile_41A140(internCStr(a1), C.int(a2)))
}
func Nox_xxx_mapSavePlayerDataMB_41A230(a1 string) int {
	return int(C.nox_xxx_mapSavePlayerDataMB_41A230(internCStr(a1)))
}
func Sub_446520(a1 int, a2 unsafe.Pointer, a3 int) {
	C.sub_446520(C.int(a1), a2, C.int(a3))
}
func Nox_xxx_computeServerPlayerDataBufferSize_41CC50(a1 string) int {
	return int(C.nox_xxx_computeServerPlayerDataBufferSize_41CC50(internCStr(a1)))
}
func Sub_40BC60(a1 int, a2 int, a3 string, a4 unsafe.Pointer, a5 int, a6 int) {
	C.sub_40BC60(C.int(a1), C.int(a2), internCStr(a3), a4, C.int(a5), C.int(a6))
}
func Nox_xxx_mapSaveMap_51E010(a1 string, a2 int) int {
	return int(C.nox_xxx_mapSaveMap_51E010(internCStr(a1), C.int(a2)))
}
