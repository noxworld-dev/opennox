package noxrender

import (
	"image"

	"golang.org/x/image/font"

	"nox/v1/common/types"
)

var _ RenderData = &testRenderData{}

func newRenderData(w, h int) *testRenderData {
	return &testRenderData{
		clip:          image.Rect(0, 0, w, h),
		colorMult:     colorU32{0xff, 0xff, 0xff},
		colorMultOp:   make(map[int]colorU32),
		colorMultMiss: make(map[int]int),
	}
}

type colorU32 struct {
	R, G, B uint32
}

type blendConf struct {
	flag0        bool
	multiply14   bool
	flag16       bool
	colorize17   bool
	alphaEnabled bool
	alpha        byte
}

type testRenderData struct {
	frame uint32
	clip  image.Rectangle
	blendConf
	colorMult     colorU32
	colorMultOp   map[int]colorU32
	colorMultMiss map[int]int
	color         uint32
	bgcolor       uint32
	textcolor     uint32
	notext        bool
	defaultFont   font.Face
}

func (d *testRenderData) Frame() uint32 {
	return d.frame
}

func (d *testRenderData) ClipRect() image.Rectangle {
	return d.clip
}

func (d *testRenderData) ClipRectNox() types.Rect {
	return types.Rect{
		Left:   d.clip.Min.X,
		Top:    d.clip.Min.Y,
		Right:  d.clip.Max.X,
		Bottom: d.clip.Max.Y,
	}
}

func (d *testRenderData) Flag0() bool {
	return d.flag0
}

func (d *testRenderData) Multiply14() bool {
	return d.multiply14
}

func (d *testRenderData) Flag16() bool {
	return d.flag16
}

func (d *testRenderData) Colorize17() bool {
	return d.colorize17
}

func (d *testRenderData) ColorMultA() (r, g, b uint32) {
	return d.colorMult.R, d.colorMult.G, d.colorMult.B
}

func (d *testRenderData) ColorMultOp(op int) (r, g, b uint32) {
	c, ok := d.colorMultOp[op]
	if !ok {
		n := d.colorMultMiss[op]
		n++
		d.colorMultMiss[op] = n
	}
	return c.R, c.G, c.B
}

func (d *testRenderData) IsAlphaEnabled() bool {
	return d.alphaEnabled
}

func (d *testRenderData) Alpha() byte {
	return d.alpha
}

func (d *testRenderData) Color() uint32 {
	return d.color
}

func (d *testRenderData) BgColor() uint32 {
	return d.bgcolor
}

func (d *testRenderData) ShouldDrawText() bool {
	return !d.notext
}

func (d *testRenderData) TextColor() uint32 {
	return d.textcolor
}

func (d *testRenderData) SetTextColor(a1 uint32) {
	d.textcolor = a1
}

func (d *testRenderData) DefaultFont() font.Face {
	return d.defaultFont
}
