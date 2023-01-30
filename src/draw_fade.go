package opennox

import (
	"image/color"

	"github.com/noxworld-dev/opennox-lib/env"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

func fadeDisableGameDraw() {
	if !noxClient.r.CheckFade(noxrender.FadeOutScreenKey) {
		legacy.Set_nox_gameDisableMapDraw_5d4594_2650672(1)
	}
}

func sub_44E020() {
	if !noxClient.r.CheckFade(noxrender.FadeInScreenKey) {
		sub_413A00(0)
	}
}

func (c *Client) Nox_video_stopAllFades44E040() {
	stopFadeOutScreen()
	stopFadeInScreen()
	noxClient.r.StopFade(noxrender.FadeClearScreenKey)
	legacy.Set_nox_gameDisableMapDraw_5d4594_2650672(0)
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
	legacy.Set_nox_gameDisableMapDraw_5d4594_2650672(1)
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
	if legacy.Get_nox_gameDisableMapDraw_5d4594_2650672() == 1 {
		if done != nil {
			done()
		}
		return true
	}
	return r.NoxRender.FadeInScreen(t, menu, done)
}

func clientPacketFade(flag4 bool, a2 bool) {
	if a2 {
		noxClient.r.FadeOutScreen(getFadeDuration(), flag4, sub_44E020)
	} else {
		noxClient.r.FadeInScreen(getFadeDuration(), flag4, fadeDisableGameDraw)
	}
}

func nox_video_inFadeTransition_44E0D0() int {
	if noxClient.r.CheckFade(noxrender.FadeOutScreenKey) {
		return 1
	}
	if noxClient.r.CheckFade(noxrender.FadeInScreenKey) {
		return 1
	}
	return bool2int(legacy.Get_nox_gameDisableMapDraw_5d4594_2650672() != 0)
}
