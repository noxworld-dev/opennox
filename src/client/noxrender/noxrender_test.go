package noxrender

import (
	"image"

	"golang.org/x/image/font"
)

var _ RenderData = &testRenderData{}

func newRenderData(w, h int) *testRenderData {
	return &testRenderData{
		clipRect:      image.Rect(0, 0, w, h),
		colorMult:     Color16{0xff, 0xff, 0xff},
		colorMultOp:   make(map[int]Color16),
		colorMultMiss: make(map[int]int),
	}
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
	colorMult     Color16
	colorMultOp   map[int]Color16
	colorMultMiss map[int]int
	color         Color
	color2        Color
	bgcolor       Color
	textcolor     Color
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

func (d *testRenderData) ColorMultA() Color16 {
	return d.colorMult
}

func (d *testRenderData) ColorMultOp(op int) Color16 {
	c, ok := d.colorMultOp[op]
	if !ok {
		n := d.colorMultMiss[op]
		n++
		d.colorMultMiss[op] = n
	}
	return c
}

func (d *testRenderData) IsAlphaEnabled() bool {
	return d.alphaEnabled
}

func (d *testRenderData) Alpha() byte {
	return d.alpha
}

func (d *testRenderData) Color() Color {
	return d.color
}

func (d *testRenderData) Color2() Color {
	return d.color2
}

func (d *testRenderData) BgColor() Color {
	return d.bgcolor
}

func (d *testRenderData) ShouldDrawText() bool {
	return !d.notext
}

func (d *testRenderData) TextColor() Color {
	return d.textcolor
}

func (d *testRenderData) SetTextColor(a1 Color) {
	d.textcolor = a1
}

func (d *testRenderData) DefaultFont() font.Face {
	return d.defaultFont
}
