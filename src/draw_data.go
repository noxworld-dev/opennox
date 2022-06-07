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

func asRenderData(p *C.nox_render_data_t) *RenderData {
	return (*RenderData)(unsafe.Pointer(p))
}

type RenderData C.nox_render_data_t

func (p *RenderData) C() *C.nox_render_data_t {
	return (*C.nox_render_data_t)(unsafe.Pointer(p))
}

func (p *RenderData) Clip() bool {
	return p.flag_0 != 0
}

func (p *RenderData) ClipRect() image.Rectangle {
	return toRect(&p.clip)
}

func (p *RenderData) SetClipRect(r image.Rectangle) {
	setRect(&p.clip, r)
}

func (p *RenderData) ClipRect2() image.Rectangle {
	return toRect(&p.rect2)
}

func (p *RenderData) SetClipRect2(r image.Rectangle) {
	setRect(&p.rect2, r)
}

func (p *RenderData) Rect3() image.Rectangle {
	return toRect(&p.rect3)
}

func (p *RenderData) SetRect3(r image.Rectangle) {
	setRect(&p.rect3, r)
}

func (p *RenderData) Reset() {
	p.field_13 = 0
	p.field_14 = 0
	p.field_17 = 0
	p.field_24 = 0
	p.field_25 = 0
	p.field_26 = 0
	p.field_44 = 0
	p.field_45 = 0
	p.field_46 = 0
	p.field_54 = 0
	p.field_55 = 0
	p.field_56 = 0
	p.field_58 = 0
	p.field_59 = 0
	p.field_60 = 0
	p.field_61 = 0
	p.SetLightColor(ColorInt{R: 25, G: 25, B: 25})
	p.field_259 = 0xFF
	p.field_260 = 0xFF00FF
	p.field_261 = 0xFF00FF
	p.field_262 = 0
}

func (p *RenderData) IsAlphaEnabled() bool {
	return p.field_13 != 0
}

func (p *RenderData) SetAlphaEnabled(enabled bool) { // nox_client_drawEnableAlpha_434560
	if enabled != p.IsAlphaEnabled() {
		p.field_13 = C.uint(bool2int(enabled))
	}
}

func (p *RenderData) Multiply14() bool {
	return p.field_14 != 0
}

func (p *RenderData) Flag16() bool {
	return p.field_16 != 0
}

func (p *RenderData) Colorize17() bool {
	return p.field_17 != 0
}

func (p *RenderData) setMultiply14(v int) { // sub_4345F0
	p.field_14 = C.uint(v)
}

func (p *RenderData) setColorize17(v int) { // nox_xxx_draw_434600
	p.field_17 = C.uint(v)
}

func (p *RenderData) setColorInt44(c ColorInt) {
	p.field_44 = C.uint(c.R)
	p.field_45 = C.uint(c.G)
	p.field_46 = C.uint(c.B)
}

func (p *RenderData) setColorInt54(c ColorInt) { // nox_draw_set54RGB_433F10
	p.field_54 = C.uint(c.R)
	p.field_55 = C.uint(c.G)
	p.field_56 = C.uint(c.B)
}

func (p *RenderData) BgColor() color.Color {
	return noxcolor.RGBA5551(p.field_58)
}

func (p *RenderData) SetSelectColor(a1 uint32) {
	p.field_58 = C.uint(a1)
}

func (p *RenderData) TextColor() color.Color {
	return noxcolor.RGBA5551(p.field_59)
}

func (p *RenderData) SetTextColor(a1 color.Color) { // nox_xxx_drawSetTextColor_434390
	p.field_59 = C.uint(noxcolor.ToRGBA5551Color(a1).Color32())
}

func (p *RenderData) Color() color.Color {
	return noxcolor.RGBA5551(p.field_60)
}

func (p *RenderData) Color2() color.Color {
	return noxcolor.RGBA5551(p.field_61)
}

func (p *RenderData) SetColor(a1 color.Color) { // nox_xxx_drawSetColor_4343E0
	p.field_60 = C.uint(noxcolor.ToRGBA5551Color(a1).Color32())
}

func (p *RenderData) SetColor2(a1 color.Color) { // nox_client_drawSetColor_434460
	p.field_61 = C.uint(noxcolor.ToRGBA5551Color(a1).Color32())
}

func (p *RenderData) SetLightColor(c ColorInt) { // nox_client_drawSetColor_434460
	p.field_62 = C.uint(c.R)
	p.field_63 = C.uint(c.G)
	p.field_64 = C.uint(c.B)
}

func (p *RenderData) GetLightColor() ColorInt {
	return ColorInt{
		R: int(p.field_62),
		G: int(p.field_63),
		B: int(p.field_64),
	}
}

var _ = [1]struct{}{}[48-unsafe.Sizeof(renderMat{})]

type renderMat struct {
	field0  uint32 // 0, 0
	field1  uint32 // 1, 4
	field2  uint32 // 2, 8
	field3  uint32 // 3, 12
	field4  uint32 // 4, 16
	field5  uint32 // 5, 20
	R       uint32 // 6, 24
	G       uint32 // 7, 28
	B       uint32 // 8, 32
	field9  uint32 // 9, 36
	Color32 uint32 // 10, 40
	field11 uint32 // 11, 44
}

func (p *RenderData) material(ind int) *renderMat {
	return (*renderMat)(unsafe.Pointer(&p.materials[ind]))
}

func (p *RenderData) SetMaterialRGB(ind int, r, g, b int) {
	if ind < 0 || ind >= 16 {
		return
	}
	r = r & 0xFF
	g = g & 0xFF
	b = b & 0xFF
	m := p.material(ind)
	m.R = uint32(r)
	m.G = uint32(g)
	m.B = uint32(b)
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
	m.R = uint32(c.R)
	m.G = uint32(c.G)
	m.B = uint32(c.B)
}

func (p *RenderData) ColorMultA() noxrender.Color16 {
	return noxrender.Color16{
		R: uint16(p.field_24),
		G: uint16(p.field_25),
		B: uint16(p.field_26),
	}
}

func (p *RenderData) SetColorMultA(c noxrender.Color16) {
	p.field_24 = C.uint(c.R)
	p.field_25 = C.uint(c.G)
	p.field_26 = C.uint(c.B)
}

func (p *RenderData) ColorMultOp(op int) noxrender.Color16 {
	m := p.material(op)
	return noxrender.Color16{
		R: uint16(m.R),
		G: uint16(m.G),
		B: uint16(m.B),
	}
}

func (p *RenderData) Alpha() byte {
	return byte(p.field_259)
}

func (p *RenderData) SetAlpha(v byte) { // nox_client_drawSetAlpha_434580
	if p.Alpha() != v {
		p.field_259 = C.uint(v)
		v2 := uint64(v) | (uint64(v) << 16)
		v2 &= 0xffffffff
		v2 <<= 16
		v2 = (v2 & 0xffffffff00000000) | uint64(v) | (v2 & 0xffffffff)
		v2 <<= 16
		p.field_260 = C.uint(uint32(v) | uint32(v2))
		p.field_261 = C.uint(v2 >> 32)
	}
}

func (p *RenderData) setField262(a1 int) { // sub_434080
	p.field_262 = C.uint(a1)
}
