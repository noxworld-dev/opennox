package noxrender

import (
	"image"

	"golang.org/x/image/font"
)

var _ RenderData = &testRenderData{}

func newRenderData(w, h int) *testRenderData {
	return &testRenderData{
		clipRect:      image.Rect(0, 0, w, h),
		colorMult:     colorU32{0xff, 0xff, 0xff},
		colorMultOp:   make(map[int]colorU32),
		colorMultMiss: make(map[int]int),
	}
}

type colorU32 struct {
	R, G, B uint32
}

type blendConf struct {
	clip         bool
	multiply14   bool
	flag16       bool
	colorize17   bool
	alphaEnabled bool
	alpha        byte
}

type testRenderData struct {
	frame     uint32
	clipRect  image.Rectangle
	clipRect2 image.Rectangle
	blendConf
	colorMult     colorU32
	colorMultOp   map[int]colorU32
	colorMultMiss map[int]int
	color         uint32
	color2        uint32
	bgcolor       uint32
	textcolor     uint32
	notext        bool
	defaultFont   font.Face
}

func (d *testRenderData) Frame() uint32 {
	return d.frame
}

func (d *testRenderData) ClipRect() image.Rectangle {
	return d.clipRect
}

func (d *testRenderData) ClipRect2() image.Rectangle {
	return d.clipRect2
}

func (d *testRenderData) Clip() bool {
	return d.clip
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

func (d *testRenderData) Color2() uint32 {
	return d.color2
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
