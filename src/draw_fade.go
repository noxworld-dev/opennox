package opennox

/*
#include "GAME2.h"
#include "GAME2_3.h"
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern uint32_t nox_color_black_2650656;
*/
import "C"
import (
	"image"
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
	noxrend.FadeClearScreen(menu != 0, uint32(nox_color_rgb_4344A0(0, 0, 0)))
}

func getFadeDuration() int {
	if env.IsE2E() {
		return 10
	} else if env.IsDevMode() {
		return 5
	}
	return 25
}

//export clientPacketFade
func clientPacketFade(flag4 C.bool, a2 C.bool) {
	if a2 {
		noxrend.fadeOutScreen(getFadeDuration(), bool(flag4), sub_44E020)
	} else {
		noxrend.fadeInScreen(getFadeDuration(), bool(flag4), fadeDisableGameDraw)
	}
}

//export nox_video_fadeInScreen_44DAB0
func nox_video_fadeInScreen_44DAB0(a1, a2 C.int, fnc unsafe.Pointer) {
	noxrend.fadeInScreen(int(a1), a2 != 0, func() {
		cgoCallVoid2Func(fnc)
	})
}

func (r *NoxRender) fadeInScreen(t int, menu bool, done func()) bool {
	if C.nox_gameDisableMapDraw_5d4594_2650672 == 1 {
		if done != nil {
			done()
		}
		return true
	}
	r.StopFade(noxrender.FadeInScreenKey)
	flags := noxrender.FadeFlags(0)
	if menu {
		flags |= noxrender.FadeMenu
	}
	f := r.NewFade(noxrender.FadeInScreenKey, t, flags)
	if f == nil {
		return false
	}

	f.DoneFunc = done
	var (
		cur = float32(0)
		dv  = float32(0xff) / float32(t)
	)
	f.DrawFunc = func(f *noxrender.Fade) {
		c := int(cur)
		r.Data().setColorInt54(ColorInt{
			R: c, G: c, B: c,
		})
		pix := r.PixBuffer()
		r.drawFadeScreen(pix.Rect)
		cur += dv
	}
	return true
}

func (r *NoxRender) fadeOutScreen(t int, menu bool, done func()) int {
	r.StopFade(noxrender.FadeOutScreenKey)
	flags := noxrender.FadeFlags(0)
	if menu {
		flags |= noxrender.FadeMenu
	}
	f := r.NewFade(noxrender.FadeOutScreenKey, t, flags)
	if f == nil {
		return 0
	}
	f.DoneFunc = done
	var (
		cur = float32(0xff)
		dv  = float32(0xff) / float32(t)
	)
	f.DrawFunc = func(f *noxrender.Fade) {
		c := int(cur)
		r.Data().setColorInt54(ColorInt{
			R: c, G: c, B: c,
		})
		pix := r.PixBuffer()
		r.drawFadeScreen(pix.Rect)
		cur -= dv
	}
	r.StopFade(noxrender.FadeClearScreenKey)
	return 1
}

func (r *NoxRender) drawFadeScreen(rc image.Rectangle) {
	d := r.Data()
	if d.flag_0 != 0 {
		rc = rc.Intersect(d.ClipRect())
		if rc.Empty() {
			return
		}
	}
	C.sub_49DBB0(C.int(rc.Min.X), C.int(rc.Min.Y), C.int(rc.Dx()), C.int(rc.Dy()))
}

//export nox_video_fadeOutScreen_44DB30
func nox_video_fadeOutScreen_44DB30(a1, a2 C.int, fnc unsafe.Pointer) {
	noxrend.fadeOutScreen(int(a1), a2 != 0, func() {
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
