package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

func Sub_46AF00(a1 *gui.Window) string {
	return GoWString(sub_46AF00(a1.C()))
}
func Sub_46AF40(a1 *gui.Window) unsafe.Pointer {
	return sub_46AF40(a1.C())
}
