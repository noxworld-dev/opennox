package main

/*
#include "defs.h"
#include "client__video__draw_common.h"
#include "GAME1_2.h"
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
	noxrend.DrawGlow(asPoint(unsafe.Pointer(a1)), uint32(a2), int(a3), byte(a4))
}

func (r *NoxRender) DrawGlow(pos types.Point, cl uint32, a3 int, a4 byte) { // sub_4B6720
	if !r.shouldDrawGlow() {
		return
	}
	C.sub_434040(C.int(cl))
	r.sub434080(a3 + 4)
	p := r.newParticle(0, int(32*byte(a4)))
	p.DrawAt(pos)
}

//export nox_client_drawXxxProtect_474BE0
func nox_client_drawXxxProtect_474BE0(vp *C.nox_draw_viewport_t, pos *C.nox_point, dr *C.nox_drawable, phase, eff C.int, cl1, cl2 C.int, back C.bool) {
	noxrend.drawProtectEffectDefault(asViewport(vp), asPoint(unsafe.Pointer(pos)), asDrawable(dr), int(phase), int(eff), uint32(cl1), uint32(cl2), bool(back))
}

func (r *NoxRender) drawProtectEffectDefault(vp *Viewport, pos types.Point, dr *Drawable, phase, eff int, cl1, cl2 uint32, back bool) { // nox_client_drawXxxProtect_474BE0
	opts := ProtectEffect{
		Cnt:       2,
		Height:    20,
		Speed:     10,
		Phase:     phase,
		Radius:    1.0,
		TailLeng:  6,
		GlowColor: cl1,
		TailColor: cl2,
	}
	switch eff {
	case 1:
		opts.Radius = 0.70709997
		opts.Angle = +35
	case 2:
		opts.Radius = 0.70709997
		opts.Angle = -35
	}
	r.drawProtectEffect(vp, pos, dr, opts, back)
}

type ProtectEffect struct {
	Cnt       int
	Height    int
	Speed     int
	Radius    float32
	Angle     int
	Phase     int
	TailLeng  int
	GlowColor uint32
	TailColor uint32
}

func intAngle(val, min, max int) int {
	sz := max - min
	for val < min {
		val += sz
	}
	for val >= max {
		val -= sz
	}
	return val
}

func (r *NoxRender) drawProtectEffect(vp *Viewport, pos types.Point, dr *Drawable, opts ProtectEffect, back bool) { // nox_client_drawXxxProtect
	frame := r.Frame()
	phi := opts.Phase + opts.Speed*int(byte(frame)+*(*byte)(dr.field(128)))
	for i := 0; i < opts.Cnt; i++ {
		// Calculate positions of two points on a (possibly inclined) orbit.
		// These two points are used to draw a tiny vector, where the head is the particle, and the line is a tail.
		ph1 := phi + (256/opts.Cnt)*i
		ph2 := ph1 - opts.TailLeng

		ph1 = intAngle(ph1, 0, 256)
		ph2 = intAngle(ph2, 0, 256)

		rad := opts.Radius
		part := types.Point{
			X: int(2 * rad * float32(sincosTable16[ph1].X)),
			Y: int(2 * rad * float32(sincosTable16[ph1].Y)),
		}

		draw := false
		if back {
			draw = part.Y < pos.Y
		} else {
			draw = part.Y >= pos.Y
		}
		if !draw {
			continue
		}
		tail := types.Point{
			X: int(2 * rad * float32(sincosTable16[ph2].X)),
			Y: int(2 * rad * float32(sincosTable16[ph2].Y)),
		}
		part = part.Add(pos)
		tail = tail.Add(pos)

		dy := opts.Angle * (pos.X - part.X) / (2 * sincosTable16[0].X)
		dy -= opts.Height + int(*(*int16)(dr.field(104)))
		part.Y += dy
		tail.Y += dy
		r.drawProtectParticle(vp, part, tail, opts.GlowColor, opts.TailColor)
	}
}

func (r *NoxRender) drawProtectParticle(vp *Viewport, part, tail types.Point, partCl, tailCl uint32) { // nox_client_drawXxxProtectParticle_474DD0
	part = vp.toScreenPos(part)
	tail = vp.toScreenPos(tail)

	r.DrawGlow(part, partCl, 10, 12)
	r.SetColor2(tailCl)
	r.DrawPoint(part, 3)

	r.SetColor2(tailCl)
	r.DrawLineFromPoints(part, tail)
}

// sincosTable16 assumes circle radius of 16, and expects an angle in range [0,256).
var sincosTable16 = []types.Point{
	{16, 0}, {16, 0}, {16, 1}, {16, 1}, {16, 2}, {16, 2}, {16, 2}, {16, 3},
	{16, 3}, {16, 4}, {16, 4}, {15, 4}, {15, 5}, {15, 5}, {15, 5}, {15, 6},
	{15, 6}, {15, 6}, {14, 7}, {14, 7}, {14, 8}, {14, 8}, {14, 8}, {14, 9},
	{13, 9}, {13, 9}, {13, 10}, {13, 10}, {12, 10}, {12, 10}, {12, 11}, {12, 11},
	{11, 11}, {11, 12}, {11, 12}, {10, 12}, {10, 12}, {10, 13}, {10, 13}, {9, 13},
	{9, 13}, {9, 14}, {8, 14}, {8, 14}, {8, 14}, {7, 14}, {7, 14}, {6, 15},
	{6, 15}, {6, 15}, {5, 15}, {5, 15}, {5, 15}, {4, 15}, {4, 16}, {4, 16},
	{3, 16}, {3, 16}, {2, 16}, {2, 16}, {2, 16}, {1, 16}, {1, 16}, {0, 16},
	{0, 16}, {0, 16}, {0, 16}, {0, 16}, {-1, 16}, {-1, 16}, {-1, 16}, {-2, 16},
	{-2, 16}, {-3, 16}, {-3, 16}, {-3, 15}, {-4, 15}, {-4, 15}, {-4, 15}, {-5, 15},
	{-5, 15}, {-5, 15}, {-6, 14}, {-6, 14}, {-7, 14}, {-7, 14}, {-7, 14}, {-8, 14},
	{-8, 13}, {-8, 13}, {-9, 13}, {-9, 13}, {-9, 12}, {-9, 12}, {-10, 12}, {-10, 12},
	{-10, 11}, {-11, 11}, {-11, 11}, {-11, 10}, {-11, 10}, {-12, 10}, {-12, 10}, {-12, 9},
	{-12, 9}, {-13, 9}, {-13, 8}, {-13, 8}, {-13, 8}, {-13, 7}, {-13, 7}, {-14, 6},
	{-14, 6}, {-14, 6}, {-14, 5}, {-14, 5}, {-14, 5}, {-14, 4}, {-15, 4}, {-15, 4},
	{-15, 3}, {-15, 3}, {-15, 2}, {-15, 2}, {-15, 2}, {-15, 1}, {-15, 1}, {-15, 0},
	{-15, 0}, {-15, 0}, {-15, 0}, {-15, 0}, {-15, -1}, {-15, -1}, {-15, -1}, {-15, -2},
	{-15, -2}, {-15, -3}, {-15, -3}, {-14, -3}, {-14, -4}, {-14, -4}, {-14, -4}, {-14, -5},
	{-14, -5}, {-14, -5}, {-13, -6}, {-13, -6}, {-13, -7}, {-13, -7}, {-13, -7}, {-13, -8},
	{-12, -8}, {-12, -8}, {-12, -9}, {-12, -9}, {-11, -9}, {-11, -9}, {-11, -10}, {-11, -10},
	{-10, -10}, {-10, -11}, {-10, -11}, {-9, -11}, {-9, -11}, {-9, -12}, {-9, -12}, {-8, -12},
	{-8, -12}, {-8, -13}, {-7, -13}, {-7, -13}, {-7, -13}, {-6, -13}, {-6, -13}, {-5, -14},
	{-5, -14}, {-5, -14}, {-4, -14}, {-4, -14}, {-4, -14}, {-3, -14}, {-3, -15}, {-3, -15},
	{-2, -15}, {-2, -15}, {-1, -15}, {-1, -15}, {-1, -15}, {0, -15}, {0, -15}, {0, -15},
	{0, -15}, {0, -15}, {1, -15}, {1, -15}, {2, -15}, {2, -15}, {2, -15}, {3, -15},
	{3, -15}, {4, -15}, {4, -15}, {4, -14}, {5, -14}, {5, -14}, {5, -14}, {6, -14},
	{6, -14}, {6, -14}, {7, -13}, {7, -13}, {8, -13}, {8, -13}, {8, -13}, {9, -13},
	{9, -12}, {9, -12}, {10, -12}, {10, -12}, {10, -11}, {10, -11}, {11, -11}, {11, -11},
	{11, -10}, {12, -10}, {12, -10}, {12, -9}, {12, -9}, {13, -9}, {13, -9}, {13, -8},
	{13, -8}, {14, -8}, {14, -7}, {14, -7}, {14, -7}, {14, -6}, {14, -6}, {15, -5},
	{15, -5}, {15, -5}, {15, -4}, {15, -4}, {15, -4}, {15, -3}, {16, -3}, {16, -3},
	{16, -2}, {16, -2}, {16, -1}, {16, -1}, {16, -1}, {16, 0}, {16, 0}, {16, 0},
}
