//go:build server
// +build server

package nox

import (
	"image"

	"nox/v1/client/input"
	"nox/v1/client/input/keybind"
	"nox/v1/common/types"
)

var (
	inpHandlerS *input.Handler
	srvSens     float32
	winMode     = -4
)

func getSensitivity() float32 {
	return srvSens
}

func setSensitivity(v float32) {
	srvSens = v
}

func updateFullScreen(mode int) {
	winMode = mode
}

func setScaled(v bool) {
}

func getScaled() bool {
	return false
}

func toggleScaled() {
}

func getFiltering() bool {
	return true
}

func toggleFiltering() {
}

func getWindowMode() int {
	return winMode
}

func gameResetVideoMode(inMenu, force bool) error {
	return nil
}

func setTextInput(enable bool) {}

func getTextEditBuf() string { return "" }

func keymodShift() bool { return false }

func processInput() {}

func clientDraw() bool { return true }

func drawAndPresent() {}

func getMousePos() types.Point { return types.Point{} }

func changeMousePos(pos types.Point, abs bool) {}

func getInputSeq() uint { return 1 }

func resetInput() {}

func setMouseBounds(rect image.Rectangle) {}

func setKeyFlag(key keybind.Key, val bool) {}

func map_download_start() {}

func mapDownloadLoop(first bool) (bool, error) {
	return true, nil
}
