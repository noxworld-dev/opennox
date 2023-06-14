package legacy

import (
	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	Nox_new_window_from_file func(name string, fnc gui.WindowFunc) *gui.Window
)

// nox_new_window_from_file
func nox_new_window_from_file(cname *byte, fnc gui.WindowFuncLegacy) *gui.Window {
	return Nox_new_window_from_file(GoString(cname), gui.WrapFunc(fnc))
}
