package sdl

import (
	"image"
	"sync"

	"github.com/veandco/go-sdl2/sdl"

	"nox/v1/common/alloc"
	"nox/v1/common/types"
)

type Surface struct {
	win   *Window
	sz    types.Size
	pitch int
	mu    sync.Mutex
	data  []byte
	tex   *sdl.Texture
}

func (s *Surface) Lock() bool {
	s.mu.Lock()
	return true
}

func (s *Surface) Unlock() {
	s.mu.Unlock()
}

func (s *Surface) Bytes() []byte {
	return s.data
}

func (s *Surface) Pitch() int {
	return s.pitch
}

func (s *Surface) Size() types.Size {
	return s.sz
}

func (s *Surface) Present(vp image.Rectangle) {
	ren := s.win.ren
	rect := &sdl.Rect{W: int32(s.sz.W), H: int32(s.sz.H)}
	s.mu.Lock()
	err := s.tex.Update(rect, s.data, s.pitch)
	s.mu.Unlock()
	if err != nil {
		panic(err)
	}
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
	if s.data != nil {
		alloc.FreeBytes(s.data)
		s.data = nil
	}
	s.win = nil
}
