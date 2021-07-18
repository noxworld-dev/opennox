package main

import (
	"math"
	"strings"
)

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
	// change resolution options to a new ones
	if w := root.ChildByID(321); w != nil { // 640x480
		w.DrawData().SetText(" 848 X 480 (w)")
	}
	if w := root.ChildByID(322); w != nil { // 800x600
		w.DrawData().SetText("1024 X 576 (w)")
	}
	if w := root.ChildByID(323); w != nil { // 1024x768
		w.DrawData().SetText("1024 X 768")
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
