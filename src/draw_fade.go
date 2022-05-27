package opennox

/*
#include <stdbool.h>
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/env"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func fadeDisableGameDraw() {
	if !noxrend.CheckFade(noxrender.FadeOutScreenKey) {
		C.nox_gameDisableMapDraw_5d4594_2650672 = 1
	}
}

func sub_44E020() {
	if !noxrend.CheckFade(noxrender.FadeInScreenKey) {
		sub_413A00(0)
	}
}

//export nox_video_stopAllFades_44E040
func nox_video_stopAllFades_44E040() {
	stopFadeOutScreen()
	stopFadeInScreen()
	noxrend.StopFade(noxrender.FadeClearScreenKey)
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	sub_413A00(0)
}

func stopFadeOutScreen() {
	noxrend.StopFade(noxrender.FadeOutScreenKey)
}

func stopFadeInScreen() {
	noxrend.StopFade(noxrender.FadeInScreenKey)
}

//export nox_xxx_cliPlayMapIntro_44E0B0
func nox_xxx_cliPlayMapIntro_44E0B0(menu C.int) {
	stopFadeOutScreen()
	stopFadeInScreen()
	C.nox_gameDisableMapDraw_5d4594_2650672 = 1
	noxrend.FadeClearScreen(menu != 0, noxrender.ColorRGB(0, 0, 0))
}

func getFadeDuration() int {
	if env.IsE2E() {
		return 10
	} else if env.IsDevMode() {
		return 5
	}
	return 25
}

func (r *NoxRender) FadeInScreen(t int, menu bool, done func()) bool {
	if C.nox_gameDisableMapDraw_5d4594_2650672 == 1 {
		if done != nil {
			done()
		}
		return true
	}
	return r.NoxRender.FadeInScreen(t, menu, done)
}

//export clientPacketFade
func clientPacketFade(flag4 C.bool, a2 C.bool) {
	if a2 {
		noxrend.FadeOutScreen(getFadeDuration(), bool(flag4), sub_44E020)
	} else {
		noxrend.FadeInScreen(getFadeDuration(), bool(flag4), fadeDisableGameDraw)
	}
}

//export nox_video_fadeInScreen_44DAB0
func nox_video_fadeInScreen_44DAB0(a1, a2 C.int, fnc unsafe.Pointer) {
	noxrend.FadeInScreen(int(a1), a2 != 0, func() {
		cgoCallVoid2Func(fnc)
	})
}

//export nox_video_fadeOutScreen_44DB30
func nox_video_fadeOutScreen_44DB30(a1, a2 C.int, fnc unsafe.Pointer) {
	noxrend.FadeOutScreen(int(a1), a2 != 0, func() {
		cgoCallVoid2Func(fnc)
	})
}

//export nox_video_inFadeTransition_44E0D0
func nox_video_inFadeTransition_44E0D0() C.int {
	if noxrend.CheckFade(noxrender.FadeOutScreenKey) {
		return 1
	}
	if noxrend.CheckFade(noxrender.FadeInScreenKey) {
		return 1
	}
	return C.int(bool2int(C.nox_gameDisableMapDraw_5d4594_2650672 != 0))
}
