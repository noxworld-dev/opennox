package legacy

/*
#include <stdbool.h>
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

var (
	ClientPacketFade                  func(flag4 bool, a2 bool)
	Nox_video_inFadeTransition_44E0D0 func() int
)

//export nox_video_stopAllFades_44E040
func nox_video_stopAllFades_44E040() {
	GetClient().Nox_video_stopAllFades44E040()
}

//export clientPacketFade
func clientPacketFade(flag4 C.bool, a2 C.bool) {
	ClientPacketFade(bool(flag4), bool(a2))
}

//export nox_video_inFadeTransition_44E0D0
func nox_video_inFadeTransition_44E0D0() int {
	return Nox_video_inFadeTransition_44E0D0()
}

//export nox_video_fadeInScreen_44DAB0
func nox_video_fadeInScreen_44DAB0(a1, a2 C.int, fnc unsafe.Pointer) {
	GetClient().R2().FadeInScreen(int(a1), a2 != 0, func() {
		ccall.CallVoidVoid(fnc)
	})
}

//export nox_video_fadeOutScreen_44DB30
func nox_video_fadeOutScreen_44DB30(a1, a2 C.int, fnc unsafe.Pointer) {
	GetClient().R2().FadeOutScreen(int(a1), a2 != 0, func() {
		ccall.CallVoidVoid(fnc)
	})
}
