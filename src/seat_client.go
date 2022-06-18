//go:build !server

package opennox

import (
	"image"
	"unicode/utf16"

	"github.com/spf13/viper"

	"github.com/noxworld-dev/opennox-lib/client/seat"
	"github.com/noxworld-dev/opennox-lib/client/seat/sdl"
	"github.com/noxworld-dev/opennox-lib/env"

	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/client/render"
	"github.com/noxworld-dev/opennox/v1/internal/version"
)

var (
	noxRendererS *render.Renderer
	inpHandlerS  *input.Handler
	noxSeat      seat.Seat
)

func init() {
	viper.SetDefault(configVideoFiltering, true)
	viper.SetDefault(configVideoStretch, false)
}

const (
	configVideoFiltering = "video.filtering"
	configVideoStretch   = "video.stretch"
)

func InitSeat(sz image.Point) error {
	s, err := newSeat(sz)
	if err != nil {
		return err
	}
	if s != nil {
		s.SetGamma(getGamma())
	}
	noxSeat = s
	return nil
}

func FreeSeat() {
	if noxSeat != nil {
		noxSeat.Close()
		noxSeat = nil
	}
}

func setScreenSize(sz image.Point) {
	if noxSeat != nil {
		noxSeat.ResizeScreen(sz)
	}
}

func setScreenGamma(v float32) {
	if noxSeat != nil {
		noxSeat.SetGamma(v)
	}
}

func updateFullScreen(mode int) {
	noxRendererS.SetWindowMode(mode)
}

func setStretch(v bool) {
	noxRendererS.SetStretched(v)
	viper.Set(configVideoStretch, v)
}

func setStretchIfNotSet(v bool) {
	if !viper.IsSet(configVideoStretch) {
		setStretch(v)
	}
}

func getStretch() bool {
	return noxRendererS.GetStretched()
}

func toggleStretch() {
	setStretch(!getStretch())
}

func getFiltering() bool {
	return noxRendererS.GetFiltering()
}

func toggleFiltering() {
	val := !noxRendererS.GetFiltering()
	viper.Set(configVideoFiltering, val)
	writeConfigLater()
	noxRendererS.SetFiltering(val)
}

func getWindowMode() int {
	return noxRendererS.WindowMode()
}

func processInput() *input.Handler {
	inp := inpHandlerS
	inp.Tick()
	nox_client_processInput_4308A0(inp)
	nox_xxx_cursorUpdate_46B740(inp)
	mainloopKeysUpdate(inp)
	return inp
}

func resetInput() {
	inpHandlerS.Reset()
}

func getInputSeq() uint {
	return inpHandlerS.CurrentSeq()
}

func getTextEditBuf() string {
	return inpHandlerS.GetTextEditBuf()
}

func setTextInput(enable bool) {
	inpHandlerS.SetTextInput(enable)
}

func getSensitivity() float32 {
	return inpHandlerS.GetSensitivity()
}

func setSensitivity(v float32) {
	inpHandlerS.SetSensitivity(v)
}

func getMousePos() image.Point {
	return inpHandlerS.GetMousePos()
}

func changeMousePos(pos image.Point, abs bool) {
	inpHandlerS.ChangeMousePos(pos, abs)
}

func setMouseBounds(rect image.Rectangle) {
	inpHandlerS.SetMouseBounds(rect)
}

func newSeat(sz image.Point) (seat.Seat, error) {
	sst, err := sdl.New("OpenNox "+version.ClientVersion(), sz)
	if err != nil {
		return nil, err
	}
	var s seat.Seat = sst
	if env.IsE2E() {
		s = e2eWrapSeat(s)
	}
	r, err := render.New(s)
	if err != nil {
		_ = s.Close()
		return nil, err
	}
	noxRendererS = r

	inp := input.New(s, input.CheckerFunc(get_obj_5D4594_754104_switch), strMan.Lang())
	inpHandlerS = inp

	inp.OnQuit(mainloopStop)
	inp.OnToggleFullScreen(r.ToggleWindowMode)
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

	r.OnViewResize(inp.SetWinSize)
	OnPixBufferResize(inp.SetDrawWinSize)

	r.SetFiltering(viper.GetBool(configVideoFiltering))
	r.SetStretched(viper.GetBool(configVideoStretch))

	return s, nil
}

func mainloopKeysUpdate(inp *input.Handler) {
	for _, key := range inp.KeyboardKeys() {
		//dword_5d4594_2618912 = p
		nox_xxx_windowUpdateKeysMB_46B6B0(inp, key)
	}
}
