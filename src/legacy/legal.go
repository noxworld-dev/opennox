package legacy

/*
#include "GAME1_3.h"
#include "GAME2_1.h"
#include "client__gui__window.h"
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

func Sub_46AF00(a1 *gui.Window) string {
	return GoWString(C.sub_46AF00(a1.C()))
}
func Sub_46AF40(a1 *gui.Window) unsafe.Pointer {
	return C.sub_46AF40(a1.C())
}
