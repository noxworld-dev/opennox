package opennox

/*
#include "defs.h"
*/
import "C"

import (
	"image"
	"image/color"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

type RenderData struct {
	useClip      int32           // 0, 0
	clip         image.Rectangle // 1, 4
	clip2        image.Rectangle // 5, 20; is usually set to [0,w-1] as opposed to clip, which is [0,w]
	rect3        image.Rectangle // 9, 36
	useAlpha     uint32          // 13, 52
	multiply14   uint32          // 14, 56
	field_15     uint32          // 15, 60
	flag16       uint32          // 16, 64
	colorize17   uint32          // 17, 68
	field_18     uint32          // 18, 72
	field_19     uint32          // 19, 76
	field_20     uint32          // 20, 80
	field_21     uint32          // 21, 84
	field_22     uint32          // 22, 88
	field_23     uint32          // 23, 92
	colorMult    RGB             // 24, 96
	field_27     uint32          // 27, 108
	field_28     uint32          // 28, 112
	field_29     uint32          // 29, 116
	field_30     uint32          // 30, 120
	field_31     uint32          // 31, 124
	field_32     uint32          // 32, 128
	field_33     uint32          // 33, 132
	field_34     uint32          // 34, 136
	field_35     uint32          // 35, 140
	field_36     uint32          // 36, 144
	field_37     uint32          // 37, 148
	field_38     uint32          // 38, 152
	field_39     uint32          // 39, 156
	field_40     uint32          // 40, 160
	field_41     uint32          // 41, 164
	field_42     uint32          // 42, 168
	field_43     uint32          // 43, 172
	color44      RGB             // 44, 176
	field_47     uint32          // 47, 188
	field_48     uint32          // 48, 192
	field_49     uint32          // 49, 196
	field_50     uint32          // 50, 200
	field_51     uint32          // 51, 204
	field_52     uint32          // 52, 208
	field_53     uint32          // 53, 212
	color54      RGB             // 54, 216
	field_57     uint32          // 57, 228
	selColor     uint32          // 58, 232
	textColor    uint32          // 59, 236
	color1       uint32          // 60, 240
	color2       uint32          // 61, 244
	lightColor   RGB             // 62, 248
	field_65     uint32          // 65, 260
	materials    [16]renderMat   // 66, 264
	field_258_0  uint16          // 258, 1032
	intensity258 uint16          // 258, 1034
	alpha        uint32          // 259, 1036
	field_260    uint32          // 260, 1040
	field_261    uint32          // 261, 1044
	field_262    uint32          // 262, 1048
	field_263    uint32          // 263, 1052
}

var _ = [1]struct{}{}[1056-unsafe.Sizeof(RenderData{})]

func (p *RenderData) C() *C.nox_render_data_t {
	return (*C.nox_render_data_t)(unsafe.Pointer(p))
}

func (p *RenderData) Clip() bool {
	return p.useClip != 0
}

func (p *RenderData) ClipRect() image.Rectangle {
	return p.clip
}

func (p *RenderData) SetClipRect(r image.Rectangle) {
	p.clip = r
}

func (p *RenderData) ClipRect2() image.Rectangle {
	return p.clip2
}

func (p *RenderData) SetClipRect2(r image.Rectangle) {
	p.clip2 = r
}

func (p *RenderData) Rect3() image.Rectangle {
	return p.rect3
}

func (p *RenderData) SetRect3(r image.Rectangle) {
	p.rect3 = r
}

func (p *RenderData) Reset() {
	p.useAlpha = 0
	p.multiply14 = 0
	p.colorize17 = 0
	p.colorMult = RGB{}
	p.color44 = RGB{}
	p.color54 = RGB{}
	p.selColor = 0
	p.textColor = 0
	p.color1 = 0
	p.color2 = 0
	p.SetLightColor(RGB{R: 25, G: 25, B: 25})
	p.alpha = 0xFF
	p.field_260 = 0xFF00FF
	p.field_261 = 0xFF00FF
	p.field_262 = 0
}

func (p *RenderData) IsAlphaEnabled() bool {
	return p.useAlpha != 0
}

func (p *RenderData) SetAlphaEnabled(enabled bool) { // nox_client_drawEnableAlpha_434560
	if enabled != p.IsAlphaEnabled() {
		p.useAlpha = uint32(bool2int(enabled))
	}
}

func (p *RenderData) Multiply14() bool {
	return p.multiply14 != 0
}

func (p *RenderData) Flag16() bool {
	return p.flag16 != 0
}

func (p *RenderData) Colorize17() bool {
	return p.colorize17 != 0
}

func (p *RenderData) setMultiply14(v int) { // sub_4345F0
	p.multiply14 = uint32(v)
}

func (p *RenderData) setColorize17(v int) { // nox_xxx_draw_434600
	p.colorize17 = uint32(v)
}

func (p *RenderData) setColorInt44(c RGB) {
	p.color44 = c
}

func (p *RenderData) setColorInt54(c RGB) { // nox_draw_set54RGB_433F10
	p.color54 = c
}

func (p *RenderData) BgColor() color.Color {
	return noxcolor.RGBA5551(p.selColor)
}

func (p *RenderData) SetSelectColor(a1 uint32) {
	p.selColor = uint32(a1)
}

func (p *RenderData) TextColor() color.Color {
	return noxcolor.RGBA5551(p.textColor)
}

func (p *RenderData) SetTextColor(a1 color.Color) { // nox_xxx_drawSetTextColor_434390
	p.textColor = uint32(noxcolor.ToRGBA5551Color(a1).Color32())
}

func (p *RenderData) Color() color.Color {
	return noxcolor.RGBA5551(p.color1)
}

func (p *RenderData) Color2() color.Color {
	return noxcolor.RGBA5551(p.color2)
}

func (p *RenderData) SetColor(a1 color.Color) { // nox_xxx_drawSetColor_4343E0
	p.color1 = uint32(noxcolor.ToRGBA5551Color(a1).Color32())
}

func (p *RenderData) SetColor2(a1 color.Color) { // nox_client_drawSetColor_434460
	p.color2 = uint32(noxcolor.ToRGBA5551Color(a1).Color32())
}

func (p *RenderData) SetLightColor(c RGB) { // nox_client_drawSetColor_434460
	p.lightColor = c
}

func (p *RenderData) GetLightColor() RGB {
	return p.lightColor
}

var _ = [1]struct{}{}[48-unsafe.Sizeof(renderMat{})]

type renderMat struct {
	field0  uint32 // 0, 0
	field1  uint32 // 1, 4
	field2  uint32 // 2, 8
	field3  uint32 // 3, 12
	field4  uint32 // 4, 16
	field5  uint32 // 5, 20
	Color   RGB    // 6, 24
	field9  uint32 // 9, 36
	Color32 uint32 // 10, 40
	field11 uint32 // 11, 44
}

func (p *RenderData) material(ind int) *renderMat {
	return &p.materials[ind]
}

func (p *RenderData) SetMaterialRGB(ind int, r, g, b int) {
	if ind < 0 || ind >= 16 {
		return
	}
	r = r & 0xFF
	g = g & 0xFF
	b = b & 0xFF
	m := p.material(ind)
	m.Color = RGB{R: r, G: g, B: b}
	m.Color32 = noxcolor.RGB5551Color(byte(r), byte(g), byte(b)).Color32()
}

func (p *RenderData) SetMaterial(ind int, cl color.Color) {
	if ind < 0 || ind >= 16 {
		return
	}
	cl16 := noxcolor.ToRGBA5551Color(cl)
	m := p.material(ind)
	cl32 := cl16.Color32()
	if cl16.Color32() == m.Color32 {
		return
	}
	m.Color32 = cl32
	c := cl16.ColorNRGBA()
	m.Color = RGB{R: int(c.R), G: int(c.G), B: int(c.B)}
}

func (p *RenderData) ColorMultA() noxrender.Color16 {
	return noxrender.Color16{
		R: uint16(p.colorMult.R),
		G: uint16(p.colorMult.G),
		B: uint16(p.colorMult.B),
	}
}

func (p *RenderData) SetColorMultA(c noxrender.Color16) {
	p.colorMult = RGB{R: int(c.R), G: int(c.G), B: int(c.B)}
}

func (p *RenderData) ColorMultOp(op int) noxrender.Color16 {
	m := p.material(op)
	return noxrender.Color16{
		R: uint16(m.Color.R),
		G: uint16(m.Color.G),
		B: uint16(m.Color.B),
	}
}

func (p *RenderData) Alpha() byte {
	return byte(p.alpha)
}

func (p *RenderData) SetAlpha(v byte) { // nox_client_drawSetAlpha_434580
	if p.Alpha() != v {
		p.alpha = uint32(v)
		v2 := uint64(v) | (uint64(v) << 16)
		v2 &= 0xffffffff
		v2 <<= 16
		v2 = (v2 & 0xffffffff00000000) | uint64(v) | (v2 & 0xffffffff)
		v2 <<= 16
		p.field_260 = uint32(uint32(v) | uint32(v2))
		p.field_261 = uint32(v2 >> 32)
	}
}

func (p *RenderData) setField262(a1 int) { // sub_434080
	p.field_262 = uint32(a1)
}
