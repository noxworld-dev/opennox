package legacy

/*
#include "client__gui__guiquit.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME3_2.h"
#include "GAME4_1.h"
extern nox_window* nox_wnd_quitMenu_825760;
extern unsigned int dword_5d4594_2650652;
extern uint32_t dword_5d4594_830272;
int* nox_xxx_guiServerOptionsHide_4597E0(int a1);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	Sub_446380 func()
	Sub_445B40 func() int
)

//export nox_xxx____setargv_4_44B000
func nox_xxx____setargv_4_44B000() {
	C.dword_5d4594_830272 = 1
}

//export sub_446380
func sub_446380() { Sub_446380() }

//export sub_445B40
func sub_445B40() int { return Sub_445B40() }

func Sub_4D70B0() {
	C.sub_4D70B0()
}

func Sub_509CB0() {
	C.sub_509CB0()
}

func Sub_41F4B0() {
	C.sub_41F4B0()
}

func Sub_41EC30() {
	C.sub_41EC30()
}

func Sub_446490(v int) {
	C.sub_446490(C.int(v))
}

func Nox_xxx_guiServerOptionsHide_4597E0(v int) {
	C.nox_xxx_guiServerOptionsHide_4597E0(C.int(v))
}

func Sub_445C40() {
	C.sub_445C40()
}

func Set_nox_wnd_quitMenu_825760(win *gui.Window) {
	C.nox_wnd_quitMenu_825760 = (*nox_window)(win.C())
}

func Nox_xxx____setargv_4_44B000() {
	nox_xxx____setargv_4_44B000()
}

func Get_dword_5d4594_2650652() int {
	return int(C.dword_5d4594_2650652)
}

func Set_dword_5d4594_2650652(v int) {
	C.dword_5d4594_2650652 = C.uint(v)
}

func Sub_41CEE0(p unsafe.Pointer, a2 int) {
	C.sub_41CEE0(p, C.int(a2))
}

func Get_nox_xxx_menuGameOnButton_445840() unsafe.Pointer {
	return C.nox_xxx_menuGameOnButton_445840
}
