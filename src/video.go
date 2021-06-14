package main

import (
	"image"

	"nox/v1/common/log"
	"nox/v1/common/types"
)

const (
	noxDefaultWidth  = 640
	noxDefaultHeight = 480
	noxDefaultDepth  = 16
	noxMaxWidth      = 1024
	noxMaxHeight     = 768
)

var (
	noxFullScreen    int = -4 // unset
	noxBorderless        = false
	noxPresentTicks  uint
	videoLog         = log.New("video")
	noxVideoModeMenu = renderMode{
		Width:  noxDefaultWidth,
		Height: noxDefaultHeight,
		Depth:  noxDefaultDepth,
	}
	noxVideoMax = types.Size{
		W: noxMaxWidth,
		H: noxMaxHeight,
	}
)

type renderMode struct {
	Width  int
	Height int
	Depth  int
}

func (m renderMode) Size() types.Size {
	return types.Size{
		W: m.Width,
		H: m.Height,
	}
}

func videoGetMenuMode() renderMode {
	return noxVideoModeMenu
}

func videoSetMenuMode(mode renderMode) {
	noxVideoModeMenu = mode
}

func videoSetMaxSize(sz types.Size) {
	noxVideoMax = sz
}

func videoGetMaxSize() types.Size {
	return noxVideoMax
}

func videoSyncMenuDepth() bool {
	depth := videoGetGameMode().Depth
	if depth == noxVideoModeMenu.Depth {
		return true
	}
	noxVideoModeMenu.Depth = depth
	return false
}

func callPresent() {
	presentFrame()
	noxPresentTicks++
}

func videoResizeView(mode renderMode) {
	mode.Depth = 16 // 8 bit not supported
	max := videoGetMaxSize()
	if mode.Width > max.W {
		mode.Width = max.W
	}
	if mode.Height > max.H {
		mode.Height = max.H
	}
	videoSetWindowSize(mode.Size())
	videoSet16Bit(mode.Depth != 8)
	inpHandler.SetDrawWinSize(mode.Size())
}

func videoApplyConfigVideoMode(mode renderMode) {
	mode.Depth = 16 // 8 bit not supported
	if !getEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE) {
		videoSetGameMode(mode)
		videoSyncMenuDepth()

		// FIXME: this will cause the game to change its window size to whatever set in nox.cfg right at the
		// start! this is different from original game where window is only resized after joining the game
		changeWindowedOrFullscreen()
	}
}

func nox_xxx_utilRect_49F930(a2, a3 types.Rect) (out types.Rect, _ bool) {
	left := a3.Left
	if a2.Left >= a3.Left {
		left = a2.Left
	}
	right := a3.Right
	if a2.Right <= right {
		right = a2.Right
	}
	if left >= right {
		return out, false
	}
	top := a3.Top
	if a2.Top >= top {
		top = a2.Top
	}
	bottom := a3.Bottom
	if a2.Bottom <= bottom {
		bottom = a2.Bottom
	}
	if top >= bottom {
		return out, false
	}
	out.Left = left
	out.Top = top
	out.Right = right
	out.Bottom = bottom
	return out, true
}

func changeWindowedOrFullscreen() {
	winSize := videoGetGameMode().Size()
	dispSize := getDisplayDim()
	centeredPos := image.Point{
		X: dispSize[2] + (dispSize[0]-winSize.W)/2,
		Y: dispSize[3] + (dispSize[1]-winSize.H)/2,
	}

	// Init all sizes

	// Windowed
	windowedSize := winSize
	windowedPos := centeredPos

	// Fullscreen
	fullscreenSize := types.Size{W: dispSize[0], H: dispSize[1]}
	fullscreenPos := image.Point{X: dispSize[2], Y: dispSize[3]}

	switch noxFullScreen {
	case -1, 1:
		// Normal fullscreen
		setFullScreenMode(fullscreenSize, fullscreenPos)
	case -2, 2:
		// Borderless fullscreen
		setFullScreenBorderlessMode(fullscreenSize, fullscreenPos)
	default:
		// Windowed
		setWindowedMode(windowedSize, windowedPos)
	}
	cfgUpdateFullScreen()
}

func toggleFullsreen() {
	switch noxFullScreen {
	case -1, 1:
		// Normal fullscreen -> Windowed
		noxBorderless = false
		noxFullScreen = -3
	case -2, 2:
		// Borderless fullscreen -> Windowed
		noxBorderless = true
		noxFullScreen = -3
	default:
		// Windowed -> last fullscreen
		if noxBorderless {
			noxFullScreen = -2
		} else {
			noxFullScreen = -1
		}
	}
	changeWindowedOrFullscreen()
}
