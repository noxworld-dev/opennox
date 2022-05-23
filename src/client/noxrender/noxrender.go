package noxrender

import (
	"image"
	"image/draw"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/noximage"
)

type RenderData interface {
	Frame() uint32
	ClipRect() image.Rectangle
	ClipRect2() image.Rectangle

	Clip() bool
	Multiply14() bool
	Flag16() bool
	Colorize17() bool

	ColorMultA() (r, g, b uint32)
	ColorMultOp(op int) (r, g, b uint32)

	IsAlphaEnabled() bool
	Alpha() byte

	Color() uint32
	Color2() uint32
	BgColor() uint32

	RenderDataText
}

func NewRender() *NoxRender {
	r := &NoxRender{}
	r.SetColorMode(noxcolor.ModeRGBA5551)
	r.initText()
	r.initColorTablesRev()
	return r
}

type NoxRender struct {
	p   RenderData
	pix *noximage.Image16

	colors struct {
		mode     noxcolor.Mode
		R        [256]uint16
		G        [256]uint16
		B        [256]uint16
		revTable []byte // map[Color16]byte
	}
	points []image.Point
	text   noxRenderText
	fade   noxRenderFade

	dword_5d4594_3799476 int
	dword_5d4594_3799484 uint32
	dword_5d4594_3799508 byte
	dword_5d4594_3799552 uint32

	HookImageDrawXxx func(pos image.Point, sz image.Point)
}

func (r *NoxRender) ColorIntensity(cr, cg, cb byte) byte {
	v := ((cb & 0xF8) >> 3) | ((cg & 0xF8) << 2) | ((cr & 0xF8) << 7)
	return r.colors.revTable[v]
}

func (r *NoxRender) PixBuffer() *noximage.Image16 {
	return r.pix
}

func (r *NoxRender) SetPixBuffer(pix *noximage.Image16) {
	r.pix = pix
}

func (r *NoxRender) Data() RenderData {
	return r.p
}

func (r *NoxRender) SetData(p RenderData) {
	r.p = p
}

func (r *NoxRender) Frame() uint32 {
	return r.p.Frame()
}

func (r *NoxRender) SetColorMode(mode noxcolor.Mode) {
	if r.colors.mode == mode {
		return
	}
	for i := 0; i < 256; i++ {
		r.colors.R[i] = mode.RGB(byte(i), 0, 0).Color16()
		r.colors.G[i] = mode.RGB(0, byte(i), 0).Color16()
		r.colors.B[i] = mode.RGB(0, 0, byte(i)).Color16()
	}
	r.colors.mode = mode
}

func (r *NoxRender) initColorTablesRev() {
	const max = 0x7FFF
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)
	r.colors.revTable = make([]byte, max+3)
	for i := 0; i <= max; i++ {
		cr := uint32((i & rmask) >> rshift)
		cg := uint32((i & gmask) >> gshift)
		cb := uint32((i & bmask) << bshift)
		r.colors.revTable[i] = byte((28*(cb|7) + 150*(cg|7) + 76*(cr|7)) >> 8)
	}
}

func (r *NoxRender) CopyPixBuffer() *image.NRGBA {
	img := image.NewNRGBA(r.pix.Rect)
	draw.Draw(img, img.Rect, r.pix, r.pix.Rect.Min, draw.Src)
	return img
}

func (r *NoxRender) ClearScreen() {
	r.ClearScreenWith(r.p.BgColor())
}

func (r *NoxRender) ClearScreenWith(cl uint32) {
	for i := range r.pix.Pix {
		r.pix.Pix[i] = uint16(cl)
	}
}

func (r *NoxRender) Set_dword_5d4594_3799484(v int) { // sub_47D370
	if v < 0 {
		v = 0
	}
	r.dword_5d4594_3799484 = uint32(v)
}

func (r *NoxRender) Set_dword_5d4594_37995xx(v uint32, a2 byte) { // sub_47D400
	if v < 0 {
		v = 0
	}
	r.dword_5d4594_3799552 = v
	r.dword_5d4594_3799508 = a2 & 0x1
}

func (r *NoxRender) Reset_dword_5d4594_3799476() {
	r.dword_5d4594_3799476 = 0
}

func (r *NoxRender) Get_dword_5d4594_3799476() int {
	return r.dword_5d4594_3799476
}
