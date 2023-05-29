package legacy

/*
#include "client__gui__window.h"
#include "GAME1_2.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "client__shell__inputcfg__inputcfg.h"
extern void* dword_5d4594_1307292;
extern void* dword_5d4594_1309720;
extern nox_gui_animation* nox_wnd_xxx_1309740;
void sub_42CD90();
*/

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	Nox_video_setMenuOptions func(win *gui.Window)
	Nox_gui_menu_proc_ext    func(id int) int
	Sub_4A19F0               func(name strman.ID)
	Sub_4AAA10               func() int
	Sub_4C3A90               func(a1, a2 int, a3 unsafe.Pointer, a4 int) int
	Sub_4CBE70               func(a1, a2 int, a3 unsafe.Pointer, a4 int) int
)

// nox_video_setMenuOptions
func nox_video_setMenuOptions(cwin *nox_window) { Nox_video_setMenuOptions(asWindow(cwin)) }

// nox_gui_menu_proc_ext
func nox_gui_menu_proc_ext(id int) int { return Nox_gui_menu_proc_ext(id) }

// sub_4A19F0
func sub_4A19F0(name *char) { Sub_4A19F0(strman.ID(GoString(name))) }

// sub_4AAA10
func sub_4AAA10() int { return Sub_4AAA10() }

// sub_4C3A90
func sub_4C3A90(a1, a2 int, a3 *int, a4 int) int { return Sub_4C3A90(a1, a2, unsafe.Pointer(a3), a4) }

// sub_4CBE70
func sub_4CBE70(a1, a2 int, a3 *int, a4 int) int { return Sub_4CBE70(a1, a2, unsafe.Pointer(a3), a4) }

func Sub_42CD90() {
	sub_42CD90()
}

func Sub_4CBD30() {
	sub_4CBD30()
}

func Get_dword_5d4594_1307292() *gui.Window {
	return AsWindowP(dword_5d4594_1307292)
}

func Sub_430AA0(v int) {
	sub_430AA0(int(v))
}

func Sub_4C35B0(v int) {
	sub_4C35B0(int(v))
}

func Sub_4A1A40(v int) {
	sub_4A1A40(int(v))
}

func Get_nox_wnd_xxx_1309740() *gui.Anim {
	return asGUIAnim(nox_wnd_xxx_1309740)
}

func Get_dword_5d4594_1309720() *gui.Window {
	return AsWindowP(dword_5d4594_1309720)
}
