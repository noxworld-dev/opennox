package main

/*
#include "defs.h"
extern nox_render_data_t* ptr_5D4594_3799572;
*/
import "C"
import (
	"encoding/binary"
	"math"
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/alloc/handles"
)

var (
	particlesHead *Particle
	particles     = make(map[unsafe.Pointer]*Particle)
)

type Particle struct {
	rad    int       // 0, 0
	mul1   int       // 1, 4
	mul2   int       // 2, 8
	cnt    int       // 4, 16
	colorR int       // 12, 48
	colorG int       // 13, 52
	colorB int       // 14, 56
	data   []byte    // 16, 64
	prev   *Particle // 17, 68
	next   *Particle // 18, 72
	hnd    unsafe.Pointer
}

func sub_4B0650() {
	particlesHead = nil
}

func sub_4B0660() {
	for it := particlesHead; it != nil; it = particlesHead {
		sub_4B07D0(it)
	}
}

func sub_4B07D0(p *Particle) {
	p.cnt--
	if p.cnt < 0 {
		if v2 := p.prev; v2 != nil {
			v2.next = p.next
		}
		if v3 := p.next; v3 != nil {
			v3.prev = p.prev
		}
		if p == particlesHead {
			particlesHead = p.next
		}
		alloc.FreeBytes(p.data)
		delete(particles, p.hnd)
		p.hnd = nil
	}
}

//export sub_4B0680
func sub_4B0680(a1, a2 C.uchar) unsafe.Pointer {
	p := sub4B0680(int(a1), int(a2))
	if p.hnd == nil {
		p.hnd = handles.NewPtr()
		particles[p.hnd] = p
	}
	return p.hnd
}

func sub4B0680(mul1, mul2 int) *Particle {
	rad := int(C.ptr_5D4594_3799572.field_262)
	var p *Particle
	if particlesHead != nil {
		var last *Particle
		for it := particlesHead; it != nil; it = it.next {
			last = it
			if it.rad == rad && it.mul1 == mul1 && it.mul2 == mul2 && it.colorR == int(C.ptr_5D4594_3799572.field_54) &&
				it.colorG == int(C.ptr_5D4594_3799572.field_55) && it.colorB == int(C.ptr_5D4594_3799572.field_56) {
				it.cnt++
				return it
			}
		}
		p = new(Particle)
		last.next = p
		p.prev = last
	} else {
		particlesHead = new(Particle)
		p = particlesHead
		particlesHead.prev = nil
	}
	p.rad = rad
	p.mul1 = mul1
	p.mul2 = mul2
	p.cnt = 0
	p.colorR = int(C.ptr_5D4594_3799572.field_54)
	p.colorG = int(C.ptr_5D4594_3799572.field_55)
	p.colorB = int(C.ptr_5D4594_3799572.field_56)
	p.next = nil
	p.genImage()
	return p
}

func (p *Particle) genImage() {
	rr := p.rad
	size := 2*(22*rr*(rr+1)/7+6*rr) + 17
	p.data, _ = alloc.Bytes(uintptr(size))
	data := p.data
	mul1 := p.mul1
	mul2 := p.mul2

	binary.LittleEndian.PutUint32(data[:4], 2*uint32(rr))
	data = data[4:]
	binary.LittleEndian.PutUint32(data[:4], 2*uint32(rr))
	data = data[4:]
	binary.LittleEndian.PutUint32(data[:4], uint32(-rr))
	data = data[4:]
	binary.LittleEndian.PutUint32(data[:4], uint32(-rr))
	data = data[4:]
	data = data[1:] // skip

	c1R := uint32((mul1*p.colorR)&0xffff) >> 8
	c1G := uint32((mul1*p.colorG)&0xffff) >> 8
	c1B := uint32((mul1*p.colorB)&0xffff) >> 8
	c3R := c1R << 16
	c4R := c1R << 16
	c2R := int(((((uint32)(mul2*p.colorR)>>8)&0xFF)-c1R)<<16) / rr
	c3G := c1G << 16
	c4G := c1G << 16
	c2G := int(((((uint32)(mul2*p.colorG)>>8)&0xFF)-c1G)<<16) / rr
	c3B := c1B << 16
	c4B := c1B << 16
	c2B := int(((((uint32)(mul2*p.colorB)>>8)&0xFF)-c1B)<<16) / rr
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
