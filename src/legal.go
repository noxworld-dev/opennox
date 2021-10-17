package nox

/*
#include "client__gui__window.h"
*/
import "C"
import (
	noxcolor "nox/v1/common/color"
)

//export nox_client_onShowLegal
func nox_client_onShowLegal(p *C.nox_window) {
	win := asWindow(p)
	vers := win.ChildByID(9999)
	draw := vers.DrawData()
	// original version text color is grey, we change it to yellow
	// if it's a dev build, make it red
	if IsDevVersion() {
		draw.SetTextColor(noxcolor.RGBColor(255, 0, 0))
	} else {
		draw.SetTextColor(noxcolor.RGBColor(242, 218, 0))
	}
}
