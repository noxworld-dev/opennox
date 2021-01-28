package main

import (
	"log"

	"github.com/veandco/go-sdl2/sdl"
)

func sdlSetWindowRect(size, pos [2]int) {
	input_set_win_size(size)
	noxWindow.SetSize(int32(size[0]), int32(size[1]))
	noxWindow.SetPosition(int32(pos[0]), int32(pos[1]))
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
	centeredPosX := dispSize[2] + (dispSize[0]-winSize[0])/2
	centeredPosY := dispSize[3] + (dispSize[1]-winSize[1])/2

	// Init all sizes

	// Windowed
	windowedSize := winSize
	windowedPos := [2]int{centeredPosX, centeredPosY}

	// Fullscreen
	fullscreenSize := [2]int{dispSize[0], dispSize[1]}
	fullscreenPos := [2]int{dispSize[2], dispSize[3]}

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
