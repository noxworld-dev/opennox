package noxrender

import (
	"encoding/binary"
	"image"
	"image/color"
	"math"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

type renderParticles struct {
	RenderGlow bool
	byOpts     map[particleOpt]*Particle
}

func (r *renderParticles) initParticles() {
	r.RenderGlow = true
	r.byOpts = make(map[particleOpt]*Particle)
}

func (r *renderParticles) Free() {
	for _, it := range r.byOpts {
		it.Free()
	}
}

type particleOpt struct {
	rad   int // 0, 0
	mul1  int // 1, 4
	mul2  int // 2, 8
	color RGB // 12, 48
}

// Particle represents a particle prototype that can be drawn multiple times at different positions.
type Particle struct {
	r    *NoxRender
	img  *Image
	opt  particleOpt
	data []byte // 16, 64
}

func (p *Particle) Free() {
	alloc.FreeSlice(p.data)
	p.data = nil
	delete(p.r.Part.byOpts, p.opt)
	p.r = nil
	p.img.Free()
}

func (r *NoxRender) NewParticle(mul1, mul2 int) *Particle {
	rad := int(r.Data().Field262())
	opt := particleOpt{
		rad:   rad,
		mul1:  mul1,
		mul2:  mul2,
		color: r.Data().ColorInt54(),
	}
	if p := r.Part.byOpts[opt]; p != nil {
		return p
	}
	p := &Particle{r: r, opt: opt}
	r.Part.byOpts[opt] = p
	p.genImage()
	p.img = r.Bag.NewRawImage(8, p.data)
	return p
}

func (p *Particle) genImage() {
	rr := p.opt.rad
	size := 2*(22*rr*(rr+1)/7+6*rr) + 17
	p.data, _ = alloc.Make([]byte{}, size)
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

	c1R := uint32((mul1*p.opt.color.R)&0xffff) >> 8
	c1G := uint32((mul1*p.opt.color.G)&0xffff) >> 8
	c1B := uint32((mul1*p.opt.color.B)&0xffff) >> 8
	c3R := c1R << 16
	c4R := c1R << 16
	c2R := int((((uint32(mul2*p.opt.color.R)>>8)&0xFF)-c1R)<<16) / rr
	c3G := c1G << 16
	c4G := c1G << 16
	c2G := int((((uint32(mul2*p.opt.color.G)>>8)&0xFF)-c1G)<<16) / rr
	c3B := c1B << 16
	c4B := c1B << 16
	c2B := int((((uint32(mul2*p.opt.color.B)>>8)&0xFF)-c1B)<<16) / rr
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

func (p *Particle) DrawAt(pos image.Point) {
	p.r.DrawImage16(p.img, pos)
}

func (r *NoxRender) DrawGlow(pos image.Point, cl color.Color, a3 int, a4 int) { // sub_4B6720
	if !r.Part.RenderGlow {
		return
	}
	c := SplitColor(noxcolor.ToRGBA5551Color(cl))
	r.Data().SetColorInt54(RGB{R: int(c.R), G: int(c.G), B: int(c.B)})
	r.Data().SetField262(a3 + 4)
	p := r.NewParticle(0, int(32*byte(a4)))
	p.DrawAt(pos)
}

func (r *NoxRender) DrawParticles49ED80(mul2 int) bool {
	d := r.Data()
	pos2, ok := r.LastPoint(false)
	if !ok {
		return false
	}
	pos1, ok := r.LastPoint(false)
	if !ok {
		return false
	}
	if d.IsAlphaEnabled() {
		r.DrawLineAlpha(pos1, pos2, r.Data().Color2())
		return true
	}
	if d.Clip() && !r.clipToRect2(&pos1, &pos2) {
		return true
	}
	dx := pos2.X - pos1.X
	dy := pos2.Y - pos1.Y

	sx := 0
	if dx > 0 {
		sx = +1
	} else if dx < 0 {
		sx = -1
		dx = -dx
	}

	sy := 0
	if dy > 0 {
		sy = +1
	} else if dy < 0 {
		sy = -1
		dy = -dy
	}

	p := r.NewParticle(0, mul2)
	each := p.opt.rad / 4
	if dx <= dy {
		v := 2*dx - dy
		p.DrawAt(pos1)
		step := 0
		for i := dy; i > 0; i-- {
			pos1.Y += sy
			if v >= 0 {
				v += 2 * (dx - dy)
				pos1.X += sx
			} else {
				v += 2 * dx
			}
			step++
			if step >= each {
				p.DrawAt(pos1)
				step = 0
			}
		}
	} else {
		v := 2*dy - dx
		p.DrawAt(pos1)
		step := 0
		for i := dx; i > 0; i-- {
			pos1.X += sx
			if v >= 0 {
				v += 2 * (dy - dx)
				pos1.Y += sy
			} else {
				v += 2 * dy
			}
			step++
			if step >= each {
				p.DrawAt(pos1)
				step = 0
			}
		}
	}
	return true
}
