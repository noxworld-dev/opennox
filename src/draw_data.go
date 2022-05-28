package opennox

/*
#include "defs.h"
*/
import "C"

import (
	"image"
	"unsafe"

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

func (p *RenderData) setColorInt54(c ColorInt) { // nox_xxx_drawMakeRGB_433F10
	p.field_54 = C.uint(c.R)
	p.field_55 = C.uint(c.G)
	p.field_56 = C.uint(c.B)
}

func (p *RenderData) BgColor() noxrender.Color {
	return noxrender.Color(p.field_58)
}

func (p *RenderData) SetSelectColor(a1 uint32) {
	p.field_58 = C.uint(a1)
}

func (p *RenderData) TextColor() noxrender.Color {
	return noxrender.Color(p.field_59)
}

func (p *RenderData) SetTextColor(a1 noxrender.Color) { // nox_xxx_drawSetTextColor_434390
	p.field_59 = C.uint(a1)
}

func (p *RenderData) Color() noxrender.Color {
	return noxrender.Color(p.field_60)
}

func (p *RenderData) Color2() noxrender.Color {
	return noxrender.Color(p.field_61)
}

func (p *RenderData) SetColor(a1 noxrender.Color) { // nox_xxx_drawSetColor_4343E0
	p.field_60 = C.uint(a1)
}

func (p *RenderData) SetColor2(a1 noxrender.Color) { // nox_client_drawSetColor_434460
	p.field_61 = C.uint(a1)
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

func (p *RenderData) field66(ind int) []uint32 {
	const (
		size = 12
		max  = 16
	)
	type item [size]uint32
	arr := unsafe.Slice((*item)(unsafe.Pointer(&p.field_66)), max)
	v := arr[ind][:]
	return v
}

func (p *RenderData) ColorMultA() noxrender.Color16 {
	return noxrender.Color16{
		R: uint16(p.field_24),
		G: uint16(p.field_25),
		B: uint16(p.field_26),
	}
}

func (p *RenderData) ColorMultOp(op int) noxrender.Color16 {
	arr := p.field66(op)
	return noxrender.Color16{
		R: uint16(arr[6]),
		G: uint16(arr[7]),
		B: uint16(arr[8]),
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
