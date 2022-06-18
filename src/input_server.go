//go:build server

package opennox

import (
	"image"

	"github.com/noxworld-dev/opennox/v1/client/input"
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

func setStretch(v bool) {
}

func setStretchIfNotSet(v bool) {
}

func getStretch() bool {
	return false
}

func toggleStretch() {
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

func getMousePos() image.Point { return image.Point{} }

func changeMousePos(pos image.Point, abs bool) {}

func getInputSeq() uint { return 1 }

func resetInput() {}

func setMouseBounds(rect image.Rectangle) {}

func map_download_start() {}

func mapDownloadLoop(first bool) (bool, error) {
	return true, nil
}
