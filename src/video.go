package opennox

import (
	"image"

	"github.com/noxworld-dev/opennox-lib/client/seat"
	"github.com/noxworld-dev/opennox-lib/log"
)

const (
	noxDefaultWidth  = seat.DefaultWidth
	noxDefaultHeight = seat.DefaultHeight
	noxDefaultDepth  = seat.DefaultDepth
)

var (
	videoLog         = log.New("video")
	noxVideoModeMenu = image.Point{
		X: noxDefaultWidth,
		Y: noxDefaultHeight,
	}
	noxVideoMax = image.Point{
		X: noxMaxWidth,
		Y: noxMaxHeight,
	}
	noxVideoModes = []image.Point{
		{640, 480},
		{800, 600},
		{1024, 768},
		{1280, 720},
		{1920, 1080},
		{2560, 1440},
		{3840, 2160},
	}
	nox_video_cutSize = 100
	nox_video_gamma   = 1

	g_scaled_cfg     = 0
	g_fullscreen_cfg = 0
)

func videoModeID() int {
	mode := videoGetGameMode()
	for i, res := range noxVideoModes {
		if mode == res {
			return i
		}
	}
	for i, res := range noxVideoModes {
		if mode.X == res.X {
			return i
		}
	}
	for i, res := range noxVideoModes {
		if mode.Y == res.Y {
			return i
		}
	}
	area := mode.X * mode.Y
	min := 0
	ind := -1
	for i, res := range noxVideoModes {
		area2 := res.X * res.Y
		if ind == -1 || abs(area-area2) < min {
			ind = i
			min = abs(area - area2)
		}
	}
	return ind
}

func videoModeByID(code byte) (image.Point, bool) {
	if int(code) >= len(noxVideoModes) {
		return image.Point{}, false
	}
	return noxVideoModes[code], true
}

func videoGetMenuMode() image.Point {
	return noxVideoModeMenu
}

func videoSetMenuMode(mode image.Point) {
	noxVideoModeMenu = mode
}

func videoSetMaxSize(sz image.Point) {
	noxVideoMax = sz
}

func videoGetMaxSize() image.Point {
	return noxVideoMax
}

func videoResizeView(mode image.Point) {
	max := videoGetMaxSize()
	if mode.X > max.X {
		mode.X = max.X
	}
	if mode.Y > max.Y {
		mode.Y = max.Y
	}
	videoSetWindowSize(mode)
}

func changeWindowedOrFullscreen() {
	cfgUpdateFullScreen()
}

func nox_video_setCutSize(v int) {
	if v < 65 {
		v = 65
	}
	if v > 100 {
		v = 100
	}
	nox_video_cutSize = v
}

func nox_video_getCutSize() int {
	return nox_video_cutSize
}
