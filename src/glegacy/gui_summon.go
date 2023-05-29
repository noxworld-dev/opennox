package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	Sub_4C26F0 func(a1 *gui.Window) int
)

// sub_4C26F0
func sub_4C26F0(a1 unsafe.Pointer) int { return Sub_4C26F0(AsWindowP(a1)) }
