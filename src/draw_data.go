package opennox

/*
#include "defs.h"
*/
import "C"

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"
)

var byte_5D4594_3804364 [40]uint32

var byte_581450_9176 = [40]uint32{
	0x7c00, 0x3e0, 0x1f, // masks: R, G, B
	0x7, 0x2, 0x3, // shifts: R, G, B
	0xfbdefbde, 0x0, 0x7c007c00,
	0x7c007c00, 0x3e003e0, 0x3e003e0,
	0x1f001f, 0x1f001f, 0xf800f800,
	0xf800f800, 0xf800f800, 0xf800f800,
	0xf800f800, 0xf800f800, 0x7,
	0x0, 0x2, 0x0,
	0x3, 0x0, 0x1,
	0x0, 0x6, 0x0,
	0xb, 0x0, 0x1,
	0x0, 0x6, 0x0,
	0xb, 0x0, 0xfbdefbde,
	0xfbdefbde,
}

func asRenderData(p *C.nox_render_data_t) *RenderData {
	return (*RenderData)(unsafe.Pointer(p))
}

type RenderData C.nox_render_data_t

func (p *RenderData) C() *C.nox_render_data_t {
	return (*C.nox_render_data_t)(unsafe.Pointer(p))
}

func (p *RenderData) ClipRect() types.Rect {
	return types.Rect{
		Left:   int(p.clip.left),
		Top:    int(p.clip.top),
		Right:  int(p.clip.right),
		Bottom: int(p.clip.bottom),
	}
}

func (p *RenderData) SetClipRect(r types.Rect) {
	p.clip.left = C.int(r.Left)
	p.clip.top = C.int(r.Top)
	p.clip.right = C.int(r.Right)
	p.clip.bottom = C.int(r.Bottom)
}

func (p *RenderData) Rect2() types.Rect {
	return types.Rect{
		Left:   int(p.rect2.left),
		Top:    int(p.rect2.top),
		Right:  int(p.rect2.right),
		Bottom: int(p.rect2.bottom),
	}
}

func (p *RenderData) SetRect2(r types.Rect) {
	p.rect2.left = C.int(r.Left)
	p.rect2.top = C.int(r.Top)
	p.rect2.right = C.int(r.Right)
	p.rect2.bottom = C.int(r.Bottom)
}

func (p *RenderData) Rect3() types.Rect {
	return types.Rect{
		Left:   int(p.rect3.left),
		Top:    int(p.rect3.top),
		Right:  int(p.rect3.right),
		Bottom: int(p.rect3.bottom),
	}
}

func (p *RenderData) SetRect3(r types.Rect) {
	p.rect3.left = C.int(r.Left)
	p.rect3.top = C.int(r.Top)
	p.rect3.right = C.int(r.Right)
	p.rect3.bottom = C.int(r.Bottom)
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

func (p *RenderData) setField14(v int) { // sub_4345F0
	p.field_14 = C.uint(v)
}

func (p *RenderData) setField17(v int) { // nox_xxx_draw_434600
	p.field_17 = C.uint(v)
}

func (p *RenderData) setColorInt44(c ColorInt) { // sub_433E80
	p.field_44 = C.uint(c.R)
	p.field_45 = C.uint(c.G)
	p.field_46 = C.uint(c.B)
}

func (p *RenderData) setColorInt54(c ColorInt) { // nox_xxx_drawMakeRGB_433F10
	p.field_54 = C.uint(c.R)
	p.field_55 = C.uint(c.G)
	p.field_56 = C.uint(c.B)
}

func (p *RenderData) SetSelectColor(a1 uint32) { // nox_xxx_drawSelectColor_434350
	p.field_58 = C.uint(a1)
}

func (p *RenderData) SetTextColor(a1 uint32) { // nox_xxx_drawSetTextColor_434390
	p.field_59 = C.uint(a1)
}

func (p *RenderData) SetColor(a1 uint32) { // nox_xxx_drawSetColor_4343E0
	p.field_60 = C.uint(a1)
}

func (p *RenderData) SetColor2(a1 uint32) { // nox_client_drawSetColor_434460
	p.field_61 = C.uint(a1)
}

func (p *RenderData) SetLightColor(c ColorInt) { // nox_client_drawSetColor_434460
	p.field_62 = C.uint(c.R)
	p.field_63 = C.uint(c.G)
	p.field_64 = C.uint(c.B)
}

func (p *RenderData) GetLightColor() ColorInt { // sub_434A10
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
