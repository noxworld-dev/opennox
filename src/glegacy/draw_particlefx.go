package legacy

import (
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
)

// sub_4B6720
func sub_4B6720(a1 *int2, a2, a3 int32, a4 int8) {
	GetClient().R2().DrawGlow(AsPoint(unsafe.Pointer(a1)), noxcolor.RGBA5551(a2), int(a3), int(a4))
}
