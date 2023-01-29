package opennox

/*
#include <stdbool.h>
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
*/
import "C"
import (
	"image/color"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/env"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/internal/ccall"
)

func fadeDisableGameDraw() {
	if !noxClient.r.CheckFade(noxrender.FadeOutScreenKey) {
		C.nox_gameDisableMapDraw_5d4594_2650672 = 1
	}
}

func sub_44E020() {
	if !noxClient.r.CheckFade(noxrender.FadeInScreenKey) {
		sub_413A00(0)
	}
}

//export nox_video_stopAllFades_44E040
func nox_video_stopAllFades_44E040() {
	noxClient.nox_video_stopAllFades44E040()
}
func (c *Client) nox_video_stopAllFades44E040() {
	stopFadeOutScreen()
	stopFadeInScreen()
	noxClient.r.StopFade(noxrender.FadeClearScreenKey)
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	sub_413A00(0)
}

func stopFadeOutScreen() {
	noxClient.r.StopFade(noxrender.FadeOutScreenKey)
}

func stopFadeInScreen() {
	noxClient.r.StopFade(noxrender.FadeInScreenKey)
}

func nox_xxx_cliPlayMapIntro_44E0B0(menu int) {
	stopFadeOutScreen()
	stopFadeInScreen()
	C.nox_gameDisableMapDraw_5d4594_2650672 = 1
	noxClient.r.FadeClearScreen(menu != 0, color.Black)
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
		noxClient.r.FadeOutScreen(getFadeDuration(), bool(flag4), sub_44E020)
	} else {
		noxClient.r.FadeInScreen(getFadeDuration(), bool(flag4), fadeDisableGameDraw)
	}
}

//export nox_video_fadeInScreen_44DAB0
func nox_video_fadeInScreen_44DAB0(a1, a2 C.int, fnc unsafe.Pointer) {
	noxClient.r.FadeInScreen(int(a1), a2 != 0, func() {
		ccall.CallVoidVoid(fnc)
	})
}

//export nox_video_fadeOutScreen_44DB30
func nox_video_fadeOutScreen_44DB30(a1, a2 C.int, fnc unsafe.Pointer) {
	noxClient.r.FadeOutScreen(int(a1), a2 != 0, func() {
		ccall.CallVoidVoid(fnc)
	})
}

//export nox_video_inFadeTransition_44E0D0
func nox_video_inFadeTransition_44E0D0() int {
	if noxClient.r.CheckFade(noxrender.FadeOutScreenKey) {
		return 1
	}
	if noxClient.r.CheckFade(noxrender.FadeInScreenKey) {
		return 1
	}
	return bool2int(C.nox_gameDisableMapDraw_5d4594_2650672 != 0)
}
