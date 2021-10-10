package main

/*
#include "defs.h"
#include "client__video__draw_common.h"
#include "GAME1_2.h"
extern unsigned int nox_client_renderGlow_805852;
*/
import "C"
import (
	"encoding/binary"
	"math"
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/alloc/handles"
	"nox/v1/common/types"
)

func (r *NoxRender) initParticles() {
	r.particles.byOpts = make(map[particleOpt]*Particle)
	r.particles.byHandle = make(map[unsafe.Pointer]*Particle)
}

func (r *NoxRender) freeParticles() {
	for _, it := range r.particles.byOpts {
		it.Free()
	}
}

func (r *NoxRender) asParticle(p unsafe.Pointer) *Particle {
	return r.particles.byHandle[p]
}

type particleOpt struct {
	rad    int // 0, 0
	mul1   int // 1, 4
	mul2   int // 2, 8
	colorR int // 12, 48
	colorG int // 13, 52
	colorB int // 14, 56
}

// Particle represents a particle prototype that can be drawn multiple times at different positions.
type Particle struct {
	r    *NoxRender
	hnd  unsafe.Pointer
	img  *Image
	opt  particleOpt
	data []byte // 16, 64
}

func (p *Particle) C() unsafe.Pointer {
	if p.hnd == nil {
		p.hnd = handles.NewPtr()
		p.r.particles.byHandle[p.hnd] = p
	}
	return p.hnd
}

func (p *Particle) Free() {
	alloc.FreeBytes(p.data)
	p.data = nil
	delete(p.r.particles.byOpts, p.opt)
	delete(p.r.particles.byHandle, p.hnd)
	p.r = nil
	p.hnd = nil
	if p.img != nil && p.img.cfree != nil {
		p.img.cfree()
	}
}

//export sub_4B0680
func sub_4B0680(a1, a2 C.uchar) unsafe.Pointer {
	return noxrend.newParticle(int(a1), int(a2)).C()
}

//export nox_particle_rad
func nox_particle_rad(p unsafe.Pointer) C.int {
	return C.int(noxrend.asParticle(p).opt.rad)
}

func (r *NoxRender) newParticle(mul1, mul2 int) *Particle {
	rad := int(r.p.field_262)
	opt := particleOpt{
		rad:    rad,
		mul1:   mul1,
		mul2:   mul2,
		colorR: int(r.p.field_54),
		colorG: int(r.p.field_55),
		colorB: int(r.p.field_56),
	}
	if p := r.particles.byOpts[opt]; p != nil {
		return p
	}
	p := &Particle{r: r, opt: opt}
	r.particles.byOpts[opt] = p
	p.genImage()
	p.img = NewRawImage(8, p.data)
	return p
}

func (p *Particle) genImage() {
	rr := p.opt.rad
	size := 2*(22*rr*(rr+1)/7+6*rr) + 17
	p.data, _ = alloc.Bytes(uintptr(size))
	data := p.data
	mul1 := p.opt.mul1
	mul2 := p.opt.mul2

	binary.LittleEndian.PutUint32(data[:4], 2*uint32(rr))
	data = data[4:]
	binary.LittleEndian.PutUint32(data[:4], 2*uint32(rr))
	data = data[4:]
	binary.LittleEndian.PutUint32(data[:4], uint32(-rr))
	data = data[4:]
	binary.LittleEndian.PutUint32(data[:4], uint32(-rr))
	data = data[4:]
	data = data[1:] // skip

	c1R := uint32((mul1*p.opt.colorR)&0xffff) >> 8
	c1G := uint32((mul1*p.opt.colorG)&0xffff) >> 8
	c1B := uint32((mul1*p.opt.colorB)&0xffff) >> 8
	c3R := c1R << 16
	c4R := c1R << 16
	c2R := int(((((uint32)(mul2*p.opt.colorR)>>8)&0xFF)-c1R)<<16) / rr
	c3G := c1G << 16
	c4G := c1G << 16
	c2G := int(((((uint32)(mul2*p.opt.colorG)>>8)&0xFF)-c1G)<<16) / rr
	c3B := c1B << 16
	c4B := c1B << 16
	c2B := int(((((uint32)(mul2*p.opt.colorB)>>8)&0xFF)-c1B)<<16) / rr
	if rr == 0 {
		return
	}

	for i := 0; i < 2*rr; i++ {
		v7 := -rr + i
		d := int(math.Sqrt(float64(rr*rr - v7*v7)))
		if d < rr {
			data[0] = 1
			data[1] = byte(rr - d)
			data = data[2:]
		}
		if d != 0 {
			data[0] = 7
			data[1] = byte(2 * d)
			data = data[2:]

			dR := c4R / uint32(d)
			dG := c4G / uint32(d)
			dB := c4B / uint32(d)

			vR := c3R
			vG := c3G
			vB := c3B
			for j := 0; j < 2*d; j++ {
				col := uint16((vB>>19)&0x1F | (8 * ((vG>>16)&0xFC | (32 * ((vR >> 16) & 0xFFF8)))))
				binary.LittleEndian.PutUint16(data[:2], col)
				data = data[2:]
				if v14 := -d + j; v14 >= 0 {
					vR -= dR
					vG -= dG
					vB -= dB
				} else {
					vR += dR
					vG += dG
					vB += dB
				}
			}
		}
		if d < rr {
			data[0] = 1
			data[1] = byte(rr - d)
			data = data[2:]
		}
		if v7 >= 0 {
			c4G -= uint32(c2G)
			c4R -= uint32(c2R)
			c4B -= uint32(c2B)
		} else {
			c4G += uint32(c2G)
			c4R += uint32(c2R)
			c4B += uint32(c2B)
		}
	}
}

func (p *Particle) DrawAt(pos types.Point) {
	p.r.DrawImageAt(p.img, pos)
}

//export sub_4B6720
func sub_4B6720(a1 *C.int2, a2, a3 C.int, a4 C.char) {
	if C.nox_client_renderGlow_805852 != 0 {
		C.sub_434040(a2)
		C.sub_434080(a3 + 4)
		pos := types.Point{X: int(a1.field_0), Y: int(a1.field_4)}
		p := noxrend.newParticle(0, int(32*byte(a4)))
		p.DrawAt(pos)
	}
}
