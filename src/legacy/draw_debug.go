package legacy

/*
#include "defs.h"
#include "GAME4_1.h"
#include "GAME5_2.h"
extern void* dword_5d4594_2386176;
extern uint32_t dword_5d4594_2386180;
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

var (
	Nox_thing_debug_draw func(vp *noxrender.Viewport, dr *client.Drawable) int
)

//export nox_thing_debug_draw
func nox_thing_debug_draw(cvp *nox_draw_viewport_t, cdr *nox_drawable) int {
	return Nox_thing_debug_draw(asViewport(cvp), asDrawable(cdr))
}

func Sub_50CB00() int {
	return int(C.dword_5d4594_2386180)
}

func Sub_50CB10() []types.Pointf {
	sz := Sub_50CB00()
	return unsafe.Slice((*types.Pointf)(C.dword_5d4594_2386176), sz)
}

func Sub_50AB50(x, y int) int {
	return int(C.sub_50AB50(C.int(x), C.int(y)))
}
