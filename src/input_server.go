//+build server

package main

import (
	"nox/client/input"
	"nox/common/types"
)

func inputInit() (func(), error) {
	return func() {}, nil
}

var inpHandler fakeInput

type fakeInput struct {
	sens float32
}

func (fakeInput) Tick()           {}
func (fakeInput) AcquireMouse()   {}
func (fakeInput) UnacquireMouse() {}
func (fakeInput) StartTextInput() {}
func (fakeInput) StopTextInput()  {}

func (h *fakeInput) GetSensitivity() float32 {
	return h.sens
}

func (h *fakeInput) SetSensitivity(v float32) {
	h.sens = v
}

func (fakeInput) WaitClick() bool {
	return true
}

func (fakeInput) IsMouseDown() bool {
	return false
}
func (fakeInput) KeyModState(mod input.Keymod) bool {
	return false
}

func (fakeInput) SetWinSize(sz types.Size)     {}
func (fakeInput) SetDrawWinSize(sz types.Size) {}

type fakeGamepad struct{}
type fakeGamepadStick struct{}

func (fakeGamepadStick) Posf() types.Pointf {
	return types.Pointf{}
}
func (*fakeGamepad) StickRel() fakeGamepadStick {
	return fakeGamepadStick{}
}
func (*fakeGamepad) InRelative() bool {
	return false
}
func (fakeInput) Gamepad() *fakeGamepad {
	return nil
}
