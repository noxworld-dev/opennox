package main

/*
#include "client__gui__window.h"
*/
import "C"
import (
	"image/color"
)

//export nox_client_onShowLegal
func nox_client_onShowLegal(p *C.nox_window) {
	win := asWindow(p)
	vers := win.ChildByID(9999)
	draw := vers.DrawData()
	// original version text color is grey, we change it to yellow
	// if it's a dev build, make it red
	if IsDevVersion() {
		draw.SetTextColor(color.RGBA{R: 255, A: 255})
	} else {
		draw.SetTextColor(color.RGBA{R: 242, G: 218, A: 255})
	}
}
