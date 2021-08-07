package main

import (
	"nox/v1/client/render"
	"nox/v1/client/seat"
	"nox/v1/common/log"
	"nox/v1/common/types"
)

const (
	noxDefaultWidth  = seat.DefaultWidth
	noxDefaultHeight = seat.DefaultHeight
	noxDefaultDepth  = seat.DefaultDepth
)

var (
	videoLog         = log.New("video")
	noxVideoModeMenu = render.Mode{
		Width:  noxDefaultWidth,
		Height: noxDefaultHeight,
		Depth:  noxDefaultDepth,
	}
	noxVideoMax = types.Size{
		W: noxMaxWidth,
		H: noxMaxHeight,
	}
)

func videoGetMenuMode() render.Mode {
	return noxVideoModeMenu
}

func videoSetMenuMode(mode render.Mode) {
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

func videoResizeView(mode render.Mode) {
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
}

func videoApplyConfigVideoMode(mode render.Mode) {
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
	cfgUpdateFullScreen()
}
