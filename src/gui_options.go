package nox

/*
#include "client__gui__window.h"
extern void* dword_5d4594_1307292;
*/
import "C"
import (
	"fmt"
	"image"
	"math"
	"strings"
	"unsafe"

	"github.com/spf13/viper"

	"nox/v1/client/noxfont"
	"nox/v1/common/strman"
	"nox/v1/common/types"
)

const (
	guiIDMenuExt = 380

	configVideoWidth  = "video.size.width"
	configVideoHeight = "video.size.height"
)

func init() {
	viper.SetDefault(configVideoWidth, 1024)
	viper.SetDefault(configVideoHeight, 768)
}

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
			root.ChildByID(id).Func94(asWindowEvent(0x4008, 1, 0))
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
		viper.Set(configVideoWidth, guiOptionsRes.W)
		viper.Set(configVideoHeight, guiOptionsRes.H)
		writeConfigLater()
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
	small := guiFontPtrByName(noxfont.SmallName)
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
		Func94(asWindowEvent(0x400A, uintptr((float32(nox_video_getGamma())-0.5)*50), 0))
	NewStaticText(root, 317, 112, 258, 140, 16, true, false, "Sensitivity")
	NewHorizontalSlider(root, 318, 120, 274, 120, 16, 1, 100).
		Func94(asWindowEvent(0x400A, uintptr((math.Log10(float64(nox_input_getSensitivity()))+1.0)*50), 0))
}

//export sub_4A19F0
func sub_4A19F0(name *C.char) {
	sub4A19F0(strman.ID(GoString(name)))
}

func sub4A19F0(name strman.ID) {
	win := asWindowP(C.dword_5d4594_1307292)
	v1 := win.ChildByID(152)
	v2 := strMan.GetStringInFile(name, "C:\\NoxPost\\src\\client\\shell\\OptsBack.c")
	v1.Func94(asWindowEvent(guiEventStaticTextSetText, uintptr(unsafe.Pointer(internWStr(v2))), math.MaxUint32))
}
