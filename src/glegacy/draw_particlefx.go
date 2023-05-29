package legacy

/*
#include "defs.h"
#include "GAME2.h"
#include "GAME2_3.h"
#include "GAME3.h"
*/

import (
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
)

// sub_4B6720
func sub_4B6720(a1 *int2, a2, a3 int, a4 char) {
	GetClient().R2().DrawGlow(AsPoint(unsafe.Pointer(a1)), noxcolor.RGBA5551(a2), int(a3), int(a4))
}
