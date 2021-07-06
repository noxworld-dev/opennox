package sdl

import (
	"image"

	"github.com/veandco/go-sdl2/sdl"

	noxcolor "nox/v1/common/color"
	"nox/v1/common/types"
)

type Surface struct {
	win *Window
	p   *sdl.Surface
}

func (s *Surface) Lock() bool {
	return s.p.Lock() == nil
}

func (s *Surface) Unlock() {
	s.p.Unlock()
}

func (s *Surface) Bytes() []byte {
	return s.p.Pixels()
}

func (s *Surface) Pitch() int {
	return int(s.p.Pitch)
}

func (s *Surface) Size() types.Size {
	return types.Size{W: int(s.p.W), H: int(s.p.H)}
}

func (s *Surface) SetTransparency(cl noxcolor.Color16) {
	if s == nil || s.p == nil {
		return
	}
	v := noxcolor.ExtendColor16(cl)
	key := uint32(uint16(v))
	s.p.SetColorKey(true, key)
}

func (s *Surface) Present(vp image.Rectangle) {
	ren := s.win.ren
	// TODO: maybe find a way to get the underlying buffer
	tex, err := ren.CreateTextureFromSurface(s.p)
	if err != nil {
		panic(err)
	}
	// TODO: reuse the texture
	defer tex.Destroy()
	if err := ren.Clear(); err != nil {
		panic(err)
	}
	var srect sdl.Rect
	s.p.GetClipRect(&srect)
	svp := sdl.Rect{
		X: int32(vp.Min.X), Y: int32(vp.Min.Y),
		W: int32(vp.Dx()), H: int32(vp.Dy()),
	}
	if err := ren.Copy(tex, &srect, &svp); err != nil {
		panic(err)
	}
	ren.Present()
}

func (s *Surface) Destroy() {
	if s.p != nil {
		s.p.Free()
		s.p = nil
	}
	s.win = nil
}
