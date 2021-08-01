package sdl

import (
	"image"

	"github.com/veandco/go-sdl2/sdl"

	"nox/v1/common/types"
)

type Surface struct {
	win *Window
	sz  types.Size
	tex *sdl.Texture
}

func (s *Surface) rect() *sdl.Rect {
	return &sdl.Rect{W: int32(s.sz.W), H: int32(s.sz.H)}
}

func (s *Surface) Lock() ([]byte, int, bool) {
	data, pitch, err := s.tex.Lock(s.rect())
	if err != nil {
		Log.Printf("cannot lock surface: %v", err)
		return nil, 0, false
	}
	return data, pitch, true
}

func (s *Surface) Unlock() {
	s.tex.Unlock()
}

func (s *Surface) Size() types.Size {
	return s.sz
}

func (s *Surface) Present(vp image.Rectangle) {
	ren := s.win.ren
	rect := s.rect()
	if err := ren.Clear(); err != nil {
		panic(err)
	}
	svp := sdl.Rect{
		X: int32(vp.Min.X), Y: int32(vp.Min.Y),
		W: int32(vp.Dx()), H: int32(vp.Dy()),
	}
	if err := ren.Copy(s.tex, rect, &svp); err != nil {
		panic(err)
	}
	ren.Present()
}

func (s *Surface) Destroy() {
	if s.tex != nil {
		_ = s.tex.Destroy()
		s.tex = nil
	}
	s.win = nil
}
