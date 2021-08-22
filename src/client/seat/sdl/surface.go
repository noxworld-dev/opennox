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

func (s *Surface) Update(data []byte) {
	err := s.tex.Update(s.rect(), data, 2*s.sz.W)
	if err != nil {
		Log.Printf("cannot update surface: %v", err)
	}
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

func (s *Surface) Draw(vp image.Rectangle) {
	svp := sdl.Rect{
		X: int32(vp.Min.X), Y: int32(vp.Min.Y),
		W: int32(vp.Dx()), H: int32(vp.Dy()),
	}
	if err := s.win.ren.Copy(s.tex, s.rect(), &svp); err != nil {
		panic(err)
	}
}

func (s *Surface) Destroy() {
	if s.tex != nil {
		_ = s.tex.Destroy()
		s.tex = nil
	}
	s.win = nil
}
