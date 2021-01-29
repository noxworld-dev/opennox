package main

import (
	"log"
	"nox/common/types"

	"github.com/veandco/go-sdl2/sdl"
)

func sdlSetWindowRect(size types.Size, pos types.Point) {
	inputSetWinSize(size)
	noxWindow.SetSize(int32(size.W), int32(size.H))
	noxWindow.SetPosition(int32(pos.X), int32(pos.Y))
}

func sdlGetDisplayDim() (r [4]int) {
	r = [4]int{-1, -1, 0, 0}
	disp, err := noxWindow.GetDisplayIndex()
	if err != nil {
		log.Println("can't get display index: ", err)
		return
	}
	rect, err := sdl.GetDisplayBounds(disp)
	if err != nil {
		log.Println("can't get display bounds: ", err)
		return
	}
	return [4]int{
		int(rect.W),
		int(rect.H),
		int(rect.X),
		int(rect.Y),
	}
}

func changeWindowedOrFullscreen() {
	winSize := noxGetWinSize1()
	dispSize := sdlGetDisplayDim()
	centeredPos := types.Point{
		X: dispSize[2] + (dispSize[0]-winSize.W)/2,
		Y: dispSize[3] + (dispSize[1]-winSize.H)/2,
	}

	// Init all sizes

	// Windowed
	windowedSize := winSize
	windowedPos := centeredPos

	// Fullscreen
	fullscreenSize := types.Size{W: dispSize[0], H: dispSize[1]}
	fullscreenPos := types.Point{X: dispSize[2], Y: dispSize[3]}

	switch noxGetScreenMode() {
	case -1, 1:
		// Normal fullscreen
		noxWindow.SetResizable(false)
		noxWindow.SetBordered(false)
		sdlSetWindowRect(fullscreenSize, fullscreenPos)
		noxWindow.SetFullscreen(sdl.WINDOW_FULLSCREEN_DESKTOP)
	case -2, 2:
		// Borderless fullscreen
		noxWindow.SetFullscreen(0)
		noxWindow.SetResizable(false)
		noxWindow.SetBordered(true)
		sdlSetWindowRect(fullscreenSize, fullscreenPos)
	default:
		// Windowed
		noxWindow.SetFullscreen(0)
		noxWindow.SetResizable(true)
		noxWindow.SetBordered(true)
		sdlSetWindowRect(windowedSize, windowedPos)
	}
}
