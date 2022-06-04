package opennox

/*
#include "defs.h"
#include "GAME3.h"
int nox_xxx_partFx_4AF600(void*);
int sub_4AF650(nox_particlefx_t*);
*/
import "C"
import (
	"image"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
)

//export sub_4AF650
func sub_4AF650(p *C.nox_particlefx_t) C.int {
	r := noxrend
	d := r.Data()
	d.SetAlphaEnabled(true)
	d.SetAlpha(byte(255 * p.field_48 / p.field_52))
	nox_xxx_drawParticlefx_4AFEB0(p)
	d.SetAlphaEnabled(false)
	return 1
}

//export nox_xxx_particleFxNew_4AF990
func nox_xxx_particleFxNew_4AF990(a1, a2, a3, a4 C.int) *C.nox_particlefx_t {
	p := C.nox_xxx_partfxAllocSmth_4B01B0()
	if p == nil {
		return nil
	}
	p.field_0 = nil
	p.field_4 = nil
	p.drawable = nil
	p.drawable_vp = nil
	p.field_20 = 0
	p.color_24 = noxrend.Data().field_61
	p.field_28 = a1
	p.field_32 = a2
	p.field_36 = a3
	p.field_40 = 0
	p.field_44 = 0
	p.field_48 = a4
	p.field_52 = a4
	p.field_56 = 0
	p.field_64 = 0
	p.field_80 = C.uint(a1) << 16
	p.field_84 = C.uint(a2) << 16
	p.field_88 = C.uint(a3) << 16
	p.field_92 = 0
	p.field_96 = 0
	p.field_100 = 0
	p.field_104 = 0
	p.field_108 = 0
	p.field_112 = 0
	p.field_116 = 0
	p.field_120 = 0
	_ = nox_xxx_drawParticlefx_4AFEB0
	p.field_124 = (*[0]byte)(C.nox_xxx_drawParticlefx_4AFEB0)
	p.field_128 = (*[0]byte)(C.sub_4B0020)
	p.field_132 = C.sub_4B01A0
	return p
}

//export nox_xxx_drawParticlefx_4AFEB0
func nox_xxx_drawParticlefx_4AFEB0(p *C.nox_particlefx_t) {
	pos1 := image.Pt(int(p.field_80>>16), int((p.field_84>>16)-(p.field_88>>16)))
	pos2 := sub_4739A0(pos1)

	r := noxrend
	if img := asImage(p.field_0); img != nil {
		r.DrawImageAt(img, pos2)
	}
	if pr := r.asParticle(p.field_4); pr != nil {
		pr.DrawAt(pos2)
	}
	if dr := asDrawable(p.drawable); dr != nil && p.drawable_vp != nil {
		prev := dr.Pos()
		dr.SetPos(pos1)
		dr.DrawFunc(asViewportP(p.drawable_vp))
		dr.SetPos(prev)
	}
	if p.field_64 != 0 {
		cl := noxcolor.RGBA5551(p.color_24)
		switch p.field_64 {
		case 1:
			r.DrawPixel(pos2, cl)
		case 2:
			r.DrawPixel(pos2.Add(image.Pt(0, 0)), cl)
			r.DrawPixel(pos2.Add(image.Pt(1, 0)), cl)
			r.DrawPixel(pos2.Add(image.Pt(0, 1)), cl)
			r.DrawPixel(pos2.Add(image.Pt(1, 1)), cl)
		case 3:
			r.DrawPixel(pos2.Add(image.Pt(1, 0)), cl)
			r.DrawPixel(pos2.Add(image.Pt(0, 1)), cl)
			r.DrawPixel(pos2.Add(image.Pt(1, 1)), cl)
			r.DrawPixel(pos2.Add(image.Pt(2, 1)), cl)
			r.DrawPixel(pos2.Add(image.Pt(1, 2)), cl)
		default:
			r.DrawPointRad(pos2, int(p.field_64)/2, cl)
		}
	}
}

//export nox_xxx_partFx_4AF600
func nox_xxx_partFx_4AF600(a1 unsafe.Pointer) C.int {
	p := nox_xxx_particleFxNew_4AF990(0, 0, 0, 5)
	if p == nil {
		return 0
	}
	p20 := *(*unsafe.Pointer)(unsafe.Add(a1, 20))
	p.drawable_vp = *(*unsafe.Pointer)(unsafe.Add(p20, 16))
	C.sub_4AFB10(p, C.int(*(*uint32)(unsafe.Add(p20, 12))))
	_ = sub_4AF650
	p.field_124 = (*[0]byte)(C.sub_4AF650)
	return 1
}

//export nox_xxx_ParticleFxT6_4AF5A0
func nox_xxx_ParticleFxT6_4AF5A0(a1 unsafe.Pointer) C.int {
	p := nox_xxx_particleFxNew_4AF990(0, 0, 0, 0x7FFFFFFF)
	if p == nil {
		return 0
	}
	p.drawable_vp = *(*unsafe.Pointer)(unsafe.Add(a1, 8))
	C.sub_4AFB10(p, C.int(*(*uint32)(unsafe.Add(a1, 0))))
	p.field_124 = nil
	p.field_128 = nil
	_ = nox_xxx_partFx_4AF600
	return C.nox_xxx_registerParticleFx_4AFCF0(C.nox_xxx_partFx_4AF600, p, 1, 500)
}
