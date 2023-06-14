package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

var (
	Nox_thing_debug_draw client.ObjectDrawFunc
)

// nox_thing_debug_draw
func nox_thing_debug_draw(cvp *noxrender.Viewport, cdr *client.Drawable) int {
	return Nox_thing_debug_draw(cvp, cdr)
}

func Sub_50CB00() int {
	return int(dword_5d4594_2386180)
}

func Sub_50CB10() []types.Pointf {
	sz := Sub_50CB00()
	return unsafe.Slice((*types.Pointf)(dword_5d4594_2386176), sz)
}

func Sub_50AB50(x, y int) int {
	return int(sub_50AB50(int32(x), int32(y)))
}
