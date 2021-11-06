package nox

/*
#include "GAME1_1.h"
#include "server__xfer__savegame__savegame.h"
*/
import "C"
import (
	noxflags "nox/v1/common/flags"
	"nox/v1/common/memmap"
)

func nox_xxx_playerSaveToFile_41A140(path string, ind int) bool {
	return C.nox_xxx_playerSaveToFile_41A140(internCStr(path), C.int(ind)) != 0
}

//export sub_4DB790
func sub_4DB790(a1 *C.char) C.int {
	nox_xxx_mapLoadOrSaveMB_4DCC70(1)
	noxflags.SetGame(0x8000000)
	sub_43F140(500)
	v1 := C.nox_xxx_soloLoadGame_4DB7E0_savegame(a1)
	sub_43F1A0()
	noxflags.UnsetGame(0x8000000)
	*memmap.PtrUint32(0x5D4594, 1563068) = gameFrame()
	return v1
}
