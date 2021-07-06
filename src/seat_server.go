//+build server

package main

import (
	"image"

	"nox/v1/client/seat"
	"nox/v1/common/alloc"
	"nox/v1/common/color"
	"nox/v1/common/types"
)

func newSeat(sz types.Size) (seat.Seat, error) {
	return &nullSeat{sz: sz}, nil
}

type nullSeat struct {
	sz types.Size
}

func (s *nullSeat) ScreenSize() types.Size {
	return s.sz
}

func (s *nullSeat) ScreenMaxSize() types.Size {
	return s.sz
}

func (s *nullSeat) ResizeScreen(sz types.Size) {
	s.sz = sz
}

func (s *nullSeat) SetScreenMode(mode seat.ScreenMode) {
}

func (s *nullSeat) OnScreenResize(fnc func(sz types.Size)) {
}

func (s *nullSeat) OnInput(fnc func(ev seat.InputEvent)) {
}

func (s *nullSeat) SetMouseGrab(enable bool) {
}

func (s *nullSeat) SetMouseRelative(enable bool) {
}

func (s *nullSeat) SetTextInput(enable bool) {
}

func (s *nullSeat) Tick() {
}

func (s *nullSeat) Close() error {
}

func (s *nullSeat) NewSurface(sz types.Size) seat.Surface {
	data := alloc.Bytes(uintptr(sz.W) * uintptr(sz.H) * 2)
	return &nullSurface{sz: sz, data: data}
}

type nullSurface struct {
	sz   types.Size
	data []byte
}

func (s *nullSurface) Bytes() []byte {
	return s.data
}

func (s *nullSurface) Pitch() int {
	return s.sz.W * 2
}

func (s *nullSurface) SetTransparency(cl noxcolor.Color16) {
}

func (s *nullSurface) Present(vp image.Rectangle) {
}

func (s *nullSurface) Destroy() {
	if s.data != nil {
		alloc.FreeBytes(s.data)
		s.data = nil
	}
}
