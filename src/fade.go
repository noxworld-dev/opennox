package opennox

/*
#include "GAME2.h"
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
*/
import "C"
import "unsafe"

func nox_client_setScreenFade_44DF90(fnc unsafe.Pointer) {
	C.nox_client_setScreenFade_44DF90(fnc)
}

func nox_client_checkFade_44DFD0(fnc unsafe.Pointer) bool {
	return C.nox_client_checkFade_44DFD0(fnc) != 0
}

//export sub_44E000
func sub_44E000() {
	if !nox_client_checkFade_44DFD0(C.nox_client_drawFadingScreen_44DD70) {
		C.nox_gameDisableMapDraw_5d4594_2650672 = 1
	}
}

//export sub_44E020
func sub_44E020() {
	if !nox_client_checkFade_44DFD0(C.nox_xxx_screenFadeEffect_44DD20) {
		sub_413A00(0)
	}
}

//export sub_44E040
func sub_44E040() {
	sub_44E070()
	sub_44E090()
	nox_client_setScreenFade_44DF90(C.nox_xxx_cliClearScreen_44DDC0)
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	sub_413A00(0)
}

func sub_44E070() {
	nox_client_setScreenFade_44DF90(C.nox_client_drawFadingScreen_44DD70)
	nox_client_setScreenFade_44DF90(C.sub_44DE30)
}

func sub_44E090() {
	nox_client_setScreenFade_44DF90(C.nox_xxx_screenFadeEffect_44DD20)
	nox_client_setScreenFade_44DF90(C.sub_44DDF0)
}

//export nox_xxx_cliPlayMapIntro_44E0B0
func nox_xxx_cliPlayMapIntro_44E0B0(a1 C.int) {
	sub_44E070()
	sub_44E090()
	C.nox_gameDisableMapDraw_5d4594_2650672 = 1
	C.nox_client_fadeXxx_44DA60(a1)
}

//export sub_44E0D0
func sub_44E0D0() C.int {
	if nox_client_checkFade_44DFD0(C.nox_client_drawFadingScreen_44DD70) {
		return 1
	}
	if nox_client_checkFade_44DFD0(C.nox_xxx_screenFadeEffect_44DD20) {
		return 1
	}
	return C.int(bool2int(C.nox_gameDisableMapDraw_5d4594_2650672 != 0))
}
