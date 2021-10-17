package nox

import (
	"nox/v1/client/seat"
	"nox/v1/common/env"
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
	noxVideoModeMenu = types.Size{
		W: noxDefaultWidth,
		H: noxDefaultHeight,
	}
	noxVideoMax = types.Size{
		W: noxMaxWidth,
		H: noxMaxHeight,
	}
)

func videoGetMenuMode() types.Size {
	return noxVideoModeMenu
}

func videoSetMenuMode(mode types.Size) {
	noxVideoModeMenu = mode
}

func videoSetMaxSize(sz types.Size) {
	noxVideoMax = sz
}

func videoGetMaxSize() types.Size {
	return noxVideoMax
}

func videoResizeView(mode types.Size) {
	max := videoGetMaxSize()
	if mode.W > max.W {
		mode.W = max.W
	}
	if mode.H > max.H {
		mode.H = max.H
	}
	videoSetWindowSize(mode)
}

func videoApplyConfigVideoMode(mode types.Size) {
	if env.IsE2E() {
		videoSetGameMode(types.Size{W: 1024, H: 768})
		changeWindowedOrFullscreen()
		return
	}
	if !getEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE) {
		videoSetGameMode(mode)

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
