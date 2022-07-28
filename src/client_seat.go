//go:build !server

package opennox

import (
	"image"
	"unicode/utf16"

	"github.com/spf13/viper"

	"github.com/noxworld-dev/opennox-lib/client/seat/sdl"
	"github.com/noxworld-dev/opennox-lib/env"

	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/client/render"
	"github.com/noxworld-dev/opennox/v1/internal/version"
)

func init() {
	viper.SetDefault(configVideoFiltering, true)
	viper.SetDefault(configVideoStretch, false)
}

func (c *Client) initSeat(sz image.Point) error {
	sst, err := sdl.New("OpenNox "+version.ClientVersion(), sz)
	if err != nil {
		return err
	}
	c.seat = sst
	if env.IsE2E() {
		c.seat = e2eWrapSeat(c.seat)
	}
	c.win, err = render.New(c.seat)
	if err != nil {
		_ = c.seat.Close()
		return err
	}

	inp := input.New(c.seat, input.CheckerFunc(get_obj_5D4594_754104_switch), c.Strings().Lang())
	c.inp = inp

	inp.OnQuit(mainloopStop)
	inp.OnToggleFullScreen(c.win.ToggleWindowMode)
	inp.OnKeyPress(gameexOnKeyboardPress)
	inp.OnMouseWheel(func(dv int) {
		// mix event handler is triggered only for wheel events
		call_OnLibraryNotice_265(dv)
	})
	inp.OnInputString(func(str string) {
		for _, c := range utf16.Encode([]rune(str)) {
			noxInputOnChar(c)
		}
	})

	c.win.OnViewResize(inp.SetWinSize)
	OnPixBufferResize(inp.SetDrawWinSize)

	c.win.SetFiltering(viper.GetBool(configVideoFiltering))
	c.win.SetStretched(viper.GetBool(configVideoStretch))
	if err != nil {
		return err
	}
	sst.SetGamma(getGamma())
	return nil
}

func (c *Client) freeSeat() {
	if c.seat != nil {
		c.seat.Close()
		c.seat = nil
	}
}
