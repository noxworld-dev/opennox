package noxrender

import (
	"image"
)

func newRenderData(w, h int) *RenderData {
	p := new(RenderData)
	p.Reset()
	p.SetClipRect(image.Rect(0, 0, w, h))
	p.colorMult = RGB{0xff, 0xff, 0xff}
	return p
}

type blendConf struct {
	useClip      bool
	multiply14   bool
	flag16       bool
	colorize17   bool
	alphaEnabled bool
	alpha        byte
}

func (c *blendConf) SetTo(p *RenderData) {
	p.SetClip(c.useClip)
	if c.multiply14 {
		p.SetMultiply14(1)
	} else {
		p.SetMultiply14(0)
	}
	p.SetFlag16(c.flag16)
	if c.colorize17 {
		p.SetColorize17(1)
	} else {
		p.SetColorize17(0)
	}
	p.SetAlphaEnabled(c.alphaEnabled)
	p.SetAlpha(c.alpha)
}
