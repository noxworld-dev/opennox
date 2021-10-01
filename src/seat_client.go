//+build !server

package main

import (
	"image"
	"unicode/utf16"

	"nox/v1/client/input"
	"nox/v1/client/input/keybind"
	"nox/v1/client/render"
	"nox/v1/client/seat"
	"nox/v1/client/seat/sdl"
	"nox/v1/common/env"
	"nox/v1/common/types"
)

var (
	noxRendererS *render.Renderer
	inpHandlerS  *input.Handler
)

func updateFullScreen(mode int) {
	noxRendererS.SetWindowMode(mode)
}

func setScaled(v bool) {
	noxRendererS.SetStretched(v)
}

func getScaled() bool {
	return noxRendererS.GetStretched()
}

func toggleScaled() {
	noxRendererS.SetStretched(!noxRendererS.GetStretched())
}

func getFiltering() bool {
	return noxRendererS.GetFiltering()
}

func toggleFiltering() {
	noxRendererS.SetFiltering(!noxRendererS.GetFiltering())
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

func getMousePos() types.Point {
	return inpHandlerS.GetMousePos()
}

func changeMousePos(pos types.Point, abs bool) {
	inpHandlerS.ChangeMousePos(pos, abs)
}

func setMouseBounds(rect image.Rectangle) {
	inpHandlerS.SetMouseBounds(rect)
}

func keymodShift() bool {
	return inpHandlerS.KeyModShift()
}

func setKeyFlag(key keybind.Key, val bool) {
	inpHandlerS.SetKeyFlag(key, val)
}

func newSeat(sz types.Size) (seat.Seat, error) {
	sst, err := sdl.New("OpenNox "+ClientVersionString(), sz)
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

	inp := input.New(s, input.CheckerFunc(get_obj_5D4594_754104_switch))
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

	return s, nil
}

func mainloopKeysUpdate(inp *input.Handler) {
	for _, key := range inp.KeyboardKeys() {
		//dword_5d4594_2618912 = p
		nox_xxx_windowUpdateKeysMB_46B6B0(inp, key)
	}
}
