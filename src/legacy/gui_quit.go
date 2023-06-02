package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	Sub_446380 func()
	Sub_445B40 func() int
)

// nox_xxx____setargv_4_44B000
func nox_xxx____setargv_4_44B000() {
	dword_5d4594_830272 = 1
}

// sub_446380
func sub_446380() { Sub_446380() }

// sub_445B40
func sub_445B40() int { return Sub_445B40() }

func Sub_4D70B0() {
	sub_4D70B0()
}

func Sub_509CB0() {
	sub_509CB0()
}

func Sub_41F4B0() {
	sub_41F4B0()
}

func Sub_41EC30() {
	sub_41EC30()
}

func Sub_446490(v int) {
	sub_446490(int32(v))
}

func Nox_xxx_guiServerOptionsHide_4597E0(v int) {
	nox_xxx_guiServerOptionsHide_4597E0(int32(v))
}

func Sub_445C40() {
	sub_445C40()
}

func Set_nox_wnd_quitMenu_825760(win *gui.Window) {
	nox_wnd_quitMenu_825760 = (*gui.Window)(win.C())
}

func Nox_xxx____setargv_4_44B000() {
	nox_xxx____setargv_4_44B000()
}

func Get_dword_5d4594_2650652() int {
	return int(dword_5d4594_2650652)
}

func Set_dword_5d4594_2650652(v int) {
	dword_5d4594_2650652 = uint32(v)
}

func Sub_41CEE0(p unsafe.Pointer, a2 int) {
	sub_41CEE0(p, int32(a2))
}
