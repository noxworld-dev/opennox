package nox

/*
#include "client__gui__window.h"
*/
import "C"
import (
	"fmt"
	"image"
	"math"
	"strings"

	"nox/v1/common/types"
)

const (
	guiIDMenuExt = 380
)

var (
	guiOptionsRes = types.Size{
		W: noxDefaultWidth,
		H: noxDefaultHeight,
	}
)

func getResolutionOptions() []types.Size {
	if noxHighRes {
		return []types.Size{
			{640, 480},
			{800, 600},
			{1024, 768},
			{1280, 720},
			{1600, 900},
			{1920, 1080},
			{2144, 1206},
			{2560, 1440},
			{3200, 1800},
			{3840, 2160},
		}
	}
	return []types.Size{
		{640, 480},
		{720, 540},
		{800, 600},
		{928, 696},
		{1024, 768},

		{},
		{},
		{864, 486},
		{928, 522},
		{1024, 576},
	}
}

//export nox_video_setMenuOptions
func nox_video_setMenuOptions(cwin *C.nox_window) {
	root := asWindow(cwin)
	mode := videoGetGameMode()
	for i, res := range getResolutionOptions() {
		if res == (types.Size{}) {
			continue
		}
		id := uint(guiIDMenuExt + i)
		if res == mode {
			root.ChildByID(id).Func94(16392, 1, 0)
			return
		}
	}
}

//export nox_gui_menu_proc_ext
func nox_gui_menu_proc_ext(cid C.int) C.int {
	id := int(cid)
	opts := getResolutionOptions()
	if id >= guiIDMenuExt && id < guiIDMenuExt+len(opts) {
		guiOptionsRes = opts[id-guiIDMenuExt]
	}
	clientPlaySoundSpecial(921, 100)
	return 1
}

func guiParseHook(name string, win *Window) {
	name = strings.ToLower(name)
	switch name {
	case "options.wnd":
		guiEnhanceOptions(win)
	case "inputcfg.wnd":
		guiEnhanceInputCfg(win)
	}
}

func guiEnhanceInputCfg(root *Window) {
	// "Back" is confusing, we rename it to "Apply"
	if w := root.ChildByID(932); w != nil {
		w.DrawData().SetText("Apply")
	}
}

func guiEnhanceOptions(root *Window) {
	small := nox_xxx_guiFontPtrByName_43F360("SMALL")
	// change resolution options to a new ones
	// if you decide to change these, check carefully in other places, especially in C
	resOpts := getResolutionOptions()
	// exactly 3 options in the menu (321-323)
	for i := 0; i < 3; i++ {
		if w := root.ChildByID(uint(321 + i)); w != nil {
			w.Hide()
		}
	}
	// add new resolution options
	const (
		resRows   = 5
		resHeight = 12
		resWidth  = 70
	)
	for i, res := range resOpts {
		if res == (types.Size{}) {
			continue
		}
		xi := i / resRows
		yi := i % resRows
		text := fmt.Sprintf("%4dx%d", res.W, res.H)
		b := NewRadioButton(root, uint(guiIDMenuExt+i), 112+resWidth*xi, 135+resHeight*yi, resWidth, resHeight, 1, text)
		draw := b.DrawData()
		draw.SetFont(small)
		draw.SetImagePoint(image.Point{Y: -2})
	}

	// replace 8bit/16bit switch with window/fullscreen
	if w := root.ChildByID(331); w != nil { // 8bit
		w.DrawData().SetText("\tWindowed")
		w.Show() // keep enabled even in-game
	}
	if w := root.ChildByID(332); w != nil { // 16bit
		w.DrawData().SetText("\tFullscreen")
		w.Show() // keep enabled even in-game
	}

	// hide window size selection
	for i := uint(0); i < 5; i++ { // 310-314
		root.ChildByID(310 + i).Hide()
	}
	// add gamma and sensitivity sliders instead
	NewStaticText(root, 315, 112, 220, 140, 16, true, false, "Gamma")
	NewHorizontalSlider(root, 316, 120, 236, 120, 16, 1, 100).
		Func94(16394, uintptr((float32(nox_video_getGamma())-0.5)*50), 0)
	NewStaticText(root, 317, 112, 258, 140, 16, true, false, "Sensitivity")
	NewHorizontalSlider(root, 318, 120, 274, 120, 16, 1, 100).
		Func94(16394, uintptr((math.Log10(float64(nox_input_getSensitivity()))+1.0)*50), 0)
}
