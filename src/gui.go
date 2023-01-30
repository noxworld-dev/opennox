package opennox

import (
	"context"
	"image"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

var (
	guiLog                            = log.New("gui")
	nox_xxx_xxxRenderGUI_587000_80832 = true
	nox_client_renderGUI_80828        = true
	nox_client_gui_flag_815132        int
)

func init() {
	noxCmdShow.Register(&console.Command{
		Token: "gui", HelpID: "showguihelp",
		Flags: console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			v0 := !nox_client_renderGUI_80828
			nox_client_renderGUI_80828 = v0
			nox_xxx_xxxRenderGUI_587000_80832 = v0
			return true
		},
	})
}

func enableGUIDrawing(enable bool) {
	nox_client_renderGUI_80828 = enable
	nox_xxx_xxxRenderGUI_587000_80832 = enable
}

func nox_client_gui_set_flag_815132(v int) {
	nox_client_gui_flag_815132 = v
}

func nox_client_onClientStatusA(v int) {
	if v&1 != 0 {
		nox_client_renderGUI_80828 = false
	} else if nox_xxx_xxxRenderGUI_587000_80832 {
		nox_client_renderGUI_80828 = true
	}
}

func nox_client_setRenderGUI(v int) {
	nox_client_renderGUI_80828 = v != 0
}

func nox_client_getRenderGUI() int {
	return bool2int(nox_client_renderGUI_80828)
}

func nox_color_rgb_4344A0(r, g, b int) uint32 {
	return noxcolor.RGB5551Color(byte(r), byte(g), byte(b)).Color32()
}

func (c *Client) keyBindingsCheckActive() int {
	if legacy.Sub_46A4A0() != 0 {
		return 1
	}
	for _, key := range c.Inp.KeyboardKeys() {
		if !c.Inp.GetKeyFlag(key) && !c.Inp.IsPressed(key) && nox_xxx_guiCursor_477600() == 0 {
			if noxConsole.ExecMacros(context.Background(), key) {
				c.Inp.SetKeyFlag(key, true)
			}
		}
	}
	return 1
}

func nox_xxx_pointInRect_4281F0(p image.Point, r image.Rectangle) bool {
	return p.In(r)
}

func sub_46AEE0(a1 *gui.Window, a2 string) {
	a1.Func94(&gui.StaticTextSetText{Str: a2})
}
