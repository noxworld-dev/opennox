package legacy

import (
	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	Sub_4C26F0 func(a1 *gui.Window) int
)

// sub_4C26F0
func sub_4C26F0(win *gui.Window, draw *gui.WindowData) int {
	return int(Sub_4C26F0(win))
}
