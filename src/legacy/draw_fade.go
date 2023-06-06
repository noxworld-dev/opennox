package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

var (
	ClientPacketFade                  func(flag4 bool, a2 bool)
	Nox_video_inFadeTransition_44E0D0 func() int
)

// nox_video_stopAllFades_44E040
func nox_video_stopAllFades_44E040() {
	GetClient().Nox_video_stopAllFades44E040()
}

// clientPacketFade
func clientPacketFade(flag4 bool, a2 bool) {
	ClientPacketFade(flag4, a2)
}

// nox_video_inFadeTransition_44E0D0
func nox_video_inFadeTransition_44E0D0() int32 {
	return int32(Nox_video_inFadeTransition_44E0D0())
}

// nox_video_fadeInScreen_44DAB0
func nox_video_fadeInScreen_44DAB0(a1, a2 int32, fnc unsafe.Pointer) {
	GetClient().R2().FadeInScreen(int(a1), a2 != 0, func() {
		ccall.AsFunc[func()](fnc)()
	})
}

// nox_video_fadeOutScreen_44DB30
func nox_video_fadeOutScreen_44DB30(a1, a2 int32, fnc unsafe.Pointer) {
	GetClient().R2().FadeOutScreen(int(a1), a2 != 0, func() {
		ccall.AsFunc[func()](fnc)()
	})
}
