package legacy

/*
#include "defs.h"
#include "GAME2.h"
#include "GAME2_3.h"
#include "GAME3.h"
*/
import "C"
import (
	"image"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client"
)

//export sub_4B6720
func sub_4B6720(a1 *C.int2, a2, a3 C.int, a4 C.char) {
	GetClient().R2().DrawGlow(AsPoint(unsafe.Pointer(a1)), noxcolor.RGBA5551(a2), int(a3), int(a4))
}
func Nox_xxx_spriteLoadAdd_45A360_drawable(a1 int, a2 image.Point) *client.Drawable {
	return asDrawable(C.nox_xxx_spriteLoadAdd_45A360_drawable(C.int(a1), C.int(a2.X), C.int(a2.Y)))
}
