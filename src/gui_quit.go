package opennox

/*
#include "GAME1_1.h"
int* nox_xxx_guiServerOptionsHide_4597E0(int a1);
*/
import "C"
import (
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

//export sub_446380
func sub_446380() {
	sub_44A400()
	if noxflags.HasGame(noxflags.GameOnline) && !noxflags.HasGame(noxflags.GameModeQuest) && !sub4D6F30() {
		C.sub_41CEE0(memmap.PtrOff(0x85B3FC, 10980), 1)
	}
	C.nox_xxx_guiServerOptionsHide_4597E0(1)
	nox_game_exit_xxx2()
	sub_446060()
}

//export sub_445B40
func sub_445B40() C.int {
	sub_413A00(0)
	if sub4DB790("AUTOSAVE") {
		return 1
	}
	v2 := strMan.GetStringInFile("GUISave.c:SaveErrorTitle", "guiquit.c")
	v1 := strMan.GetStringInFile("GUISave.c:SaveErrorTitle", "guiquit.c")
	NewDialogWindow(nil, v1, v2, 33, nil, nil)
	return 1
}
