package nox

import (
	"nox/v1/client/seat"
	"nox/v1/common/types"
)

func e2eWrapSeat(s seat.Seat) seat.Seat {
	e2e.real = s
	s.OnInput(e2eRealInput)
	return &e2eSeat{s: s}
}

type e2eSeat struct {
	s seat.Seat
}

func (e *e2eSeat) ReplaceInputs(cfg seat.InputConfig) seat.InputConfig {
	return e.s.ReplaceInputs(cfg)
}

func (e *e2eSeat) ScreenSize() types.Size {
	return e.s.ScreenSize()
}

func (e *e2eSeat) ScreenMaxSize() types.Size {
	return types.Size{W: 1024, H: 768}
}

func (e *e2eSeat) ResizeScreen(sz types.Size) {
	e.s.ResizeScreen(sz)
}

func (e *e2eSeat) SetScreenMode(mode seat.ScreenMode) {
	e.s.SetScreenMode(mode)
}

func (e *e2eSeat) SetGamma(v float32) {
	e.s.SetGamma(v)
}

func (e *e2eSeat) OnScreenResize(fnc func(sz types.Size)) {
	e.s.OnScreenResize(fnc)
}

func (e *e2eSeat) NewSurface(sz types.Size, filter bool) seat.Surface {
	return e.s.NewSurface(sz, filter)
}

func (e *e2eSeat) Clear() {
	e.s.Clear()
}

func (e *e2eSeat) Present() {
	e.s.Present()
}

func (e *e2eSeat) InputTick() {
	e.s.InputTick()
	e2eInputTick()
}

func (e *e2eSeat) OnInput(fnc func(ev seat.InputEvent)) {
	e2e.onInput = append(e2e.onInput, fnc)
}

func (e *e2eSeat) SetTextInput(enable bool) {
	if e2e.realEnable {
		e.s.SetTextInput(enable)
	}
}

func (e *e2eSeat) Close() error {
	return e.s.Close()
}
