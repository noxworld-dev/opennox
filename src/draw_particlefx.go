package opennox

/*
#include "defs.h"
#include "GAME2.h"
#include "GAME2_3.h"
#include "GAME3.h"
*/
import "C"
import (
	"image"
	"image/color"
	"math"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/alloc/handles"
	"github.com/noxworld-dev/opennox/v1/common/gsync"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

const (
	particlefxObjName = "Particle"
)

//export nox_client_onParticleFx
func nox_client_onParticleFx(code C.int, a1 *nox_drawable, a2, a3, a4 C.int) {
	noxClient.r.partfx.onParticleFx(byte(code), asDrawable(a1), int(a2), a3 != 0, int(a4))
}

type partFXes struct {
	r        *NoxRender
	types    [32]particlefxType
	pool     gsync.Pool[particleFx]
	byHandle map[unsafe.Pointer]*particleFx

	rand struct {
		u16 uint16
		u32 uint32
	}
}

func (pfx *partFXes) asParticlefx(p unsafe.Pointer) *particleFx {
	if p == nil {
		return nil
	}
	v := pfx.byHandle[p]
	if v == nil {
		panic("invalid particlefx handle")
	}
	return v
}

type particleFx struct {
	pfx        *partFXes
	chnd       unsafe.Pointer
	image      *Image          // 0, 0
	rendPart   *Particle       // 1, 4
	drawable8  *Drawable       // 2, 8
	drawable12 *Drawable       // 3, 12
	drawableVp *Viewport       // 4, 16
	partfxTyp  *particlefxType // 5, 20
	color      color.Color     // 6, 24
	pos        image.Point     // 7, 28
	z          int             // 9, 36
	cnt40      int             // 10, 40
	remains44  int             // 11, 44
	ticksLeft  int             // 12, 48
	ticksTotal int             // 13, 52
	flags      uint32          // 14, 56
	//bufferInd  int                     // 15, 60
	pointSize  int                    // 16, 64
	field_68   int                    // 17, 68
	field_72   int                    // 18, 72
	field_76   int                    // 19, 76
	x16        int                    // 20, 80
	y16        int                    // 21, 84
	z16        int                    // 22, 88
	xrel16     int                    // 23, 92
	yrel16     int                    // 24, 96
	zrel16     int                    // 25, 100
	xrel16md   int                    // 26, 104
	yrel16md   int                    // 27, 108
	zrel16md   int                    // 28, 112
	zrel16off  int                    // 29, 116
	muldiv     int                    // 30, 120
	drawFunc   func(*particleFx)      // 31, 124
	updateFunc func(*particleFx) bool // 32, 128
	//dieFunc    func(*particleFx) // 33, 132
}

func (p *particleFx) C() unsafe.Pointer {
	if p == nil {
		return nil
	}
	if p.chnd == nil {
		p.chnd = handles.NewPtr()
		p.pfx.byHandle[p.chnd] = p
	}
	return p.chnd
}

func (p *particleFx) free() {
	if p == nil {
		return
	}
	if p.partfxTyp != nil {
		p.partfxTyp.fnc = nil
	}
	if p.chnd != nil {
		delete(p.pfx.byHandle, p.chnd)
	}
	p.pfx.pool.Put(p)
}

type particlefxType struct {
	fnc    func(t *particlefxType) bool
	field1 int
	field2 int
	field3 int
	field4 int
	field5 *particleFx
}

func (pfx *partFXes) Init(r *NoxRender) {
	pfx.r = r
	pfx.rand.u16 = 0x1352
	pfx.rand.u32 = 0x13527438
	for i := range pfx.types {
		it := &pfx.types[i]
		it.fnc = nil
		it.field1 = 0
		it.field2 = 0
		it.field3 = 0
	}
}

func (pfx *partFXes) registerParticleFx(fnc func(t *particlefxType) bool, p *particleFx, a3, a4 int) int {
	for i := range pfx.types {
		it := &pfx.types[i]
		if it.fnc == nil {
			p.partfxTyp = it
			*it = particlefxType{
				fnc:    fnc,
				field1: a3,
				field2: a3,
				field3: 0,
				field4: a4,
				field5: p,
			}
			return 1
		}
	}
	return 0
}

func (pfx *partFXes) Draw() {
	for _, p := range pfx.byHandle { // TODO: this gives random order
		if p.flags&8 == 0 {
			if p.drawFunc != nil {
				p.drawFunc(p)
			}
		}
		if p.updateFunc != nil {
			if !p.updateFunc(p) {
				p.free()
			}
		}
	}
	for i := range pfx.types {
		it := &pfx.types[i]
		if it.fnc == nil {
			continue
		}
		if it.field1 == 1 {
			v := it.field3 + 1
			it.field3 = v
			if v <= it.field4 && it.fnc(it) {
				it.field1 = it.field2
			} else {
				it.fnc = nil
				it.field5.free()
				it.field5 = nil // TODO: check
			}
		}
	}
}

func (pfx *partFXes) Free() {
	pfx.byHandle = make(map[unsafe.Pointer]*particleFx)
}

func (pfx *partFXes) newParticlefx() *particleFx {
	p := pfx.pool.Get()
	p.pfx = pfx
	if p.chnd != nil {
		pfx.byHandle[p.chnd] = p
	}
	return p
}

func (p *particleFx) setDrawable8(dr *Drawable) {
	if dr != nil {
		p.flags |= 4
		p.drawable8 = dr
	} else {
		p.flags &= 0xFFFFFFFB
		p.drawable8 = nil
	}
}

func (pfx *partFXes) nox_xxx_particleFxNew_4AF990(pos image.Point, z, dur int, cl color.Color) *particleFx {
	p := pfx.newParticlefx()
	if p == nil {
		return nil
	}
	p.image = nil
	p.rendPart = nil
	p.drawable12 = nil
	p.drawableVp = nil
	p.partfxTyp = nil
	p.color = cl
	p.pos = pos
	p.z = z
	p.cnt40 = 0
	p.remains44 = 0
	p.ticksLeft = dur
	p.ticksTotal = dur
	p.flags = 0
	p.pointSize = 0
	p.x16 = pos.X << 16
	p.y16 = pos.Y << 16
	p.z16 = z << 16
	p.xrel16 = 0
	p.yrel16 = 0
	p.zrel16 = 0
	p.xrel16md = 0
	p.yrel16md = 0
	p.zrel16md = 0
	p.zrel16off = 0
	p.muldiv = 0
	p.drawFunc = partfxDraw
	p.updateFunc = partfxUpdateDef
	return p
}

func partfxDraw(p *particleFx) {
	pos1 := image.Pt(p.x16>>16, (p.y16>>16)-(p.z16>>16))
	pos2 := partOffsetPos(pos1)

	r := p.pfx.r
	if p.image != nil {
		r.DrawImageAt(p.image, pos2)
	}
	if p.rendPart != nil {
		p.rendPart.DrawAt(pos2)
	}
	if dr := p.drawable12; dr != nil && p.drawableVp != nil {
		prev := dr.Pos()
		dr.SetPos(pos1)
		dr.DrawFunc(p.drawableVp)
		dr.SetPos(prev)
	}
	if p.pointSize != 0 {
		cl := p.color
		switch p.pointSize {
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
			r.DrawPointRad(pos2, p.pointSize/2, cl)
		}
	}
}

func muldiv(a, b, c int) int {
	panic("TODO")
}

func cfshl(x, y int) int {
	panic("TODO")
}

func partfxUpdateDef(p *particleFx) bool {
	if p.ticksLeft < 0 {
		return false
	}
	p.cnt40++
	xx := p.x16
	yy := p.y16
	zz := p.z16
	if p.flags&4 != 0 {
		if dr := p.drawable8; dr != nil {
			pos := dr.Pos()
			pt8 := dr.Point8()
			xx += (pos.X - pt8.X) << 16
			yy += (pos.Y - pt8.Y) << 16
		}
	}
	if p.remains44 != 0 {
		p.remains44--
		return true
	}
	xrel16 := p.xrel16
	yrel16 := p.yrel16
	zrel16 := p.zrel16
	x16 := xrel16 + xx
	y16 := yrel16 + yy
	z16 := zrel16 + zz
	const md = 0x10000
	if z16 < 0 {
		if p.flags&2 != 0 {
			z16 -= zrel16
			zrel16 = -zrel16
			if p.muldiv != 0 {
				xrel16 = muldiv(xrel16, p.muldiv, md)
				yrel16 = muldiv(yrel16, p.muldiv, md)
				zrel16 = muldiv(zrel16, p.muldiv, md)
			}
		} else {
			z16 = 0
			zrel16 = 0
		}
	}

	if p.xrel16md != 0 {
		xrel16 = muldiv(xrel16, p.xrel16md, md)
	}
	if p.yrel16md != 0 {
		yrel16 = muldiv(yrel16, p.yrel16md, md)
	}
	if p.zrel16md != 0 {
		zrel16 = muldiv(zrel16, p.zrel16md, md)
	}
	p.ticksLeft--
	if p.ticksLeft < 0 {
		return false
	}
	p.x16 = x16
	p.y16 = y16
	p.z16 = z16
	p.xrel16 = xrel16
	p.yrel16 = yrel16
	p.zrel16 = p.zrel16off + zrel16
	return true
}

func (p *particleFx) setMulDiv(v int, flag bool) {
	if flag {
		p.flags |= 2
	} else {
		p.flags &= 0xFFFFFFFD
	}
	p.muldiv = v
}

func (pfx *partFXes) sub_4AF4C0(t *particlefxType) bool {
	dr := t.field5.drawable8
	pos := dr.Pos()
	y := pfx.randI32(pos.Y-2, pos.Y+2)
	x := pfx.randI32(pos.X-2, pos.X+2)
	p := pfx.nox_xxx_particleFxNew_4AF990(image.Pt(x, y), 2, 10, nox_color_yellow_2589772)
	if p == nil {
		return false
	}
	p.loadParticle(particlefxObjName)
	p.rendPart = t.field5.rendPart
	p.pointSize = 1
	p.zrel16off = math.MinInt16
	p.setMulDiv(45875, true)
	p.xrel16 = int(pfx.randU16())
	p.yrel16 = int(pfx.randU16())
	p.zrel16 = int(pfx.randU16())
	return true
}

func (p *particleFx) loadParticle(typ string) {
	id := nox_things.IndByID(typ)
	dr := nox_xxx_spriteLoadAdd_45A360_drawable(id, image.Pt(p.x16>>16, p.y16>>16))
	if dr != nil {
		p.drawable12 = dr
		dr.field_27 = C.uint(uintptr(p.C())) // TODO: unused?
		C.nox_xxx_spriteTransparentDecay_49B950(dr.C(), C.int(p.ticksTotal))
		C.nox_xxx_sprite_45A110_drawable(dr.C())
	}
	p.flags |= 8
}

func (pfx *partFXes) nox_xxx_partFx_4AF600(t *particlefxType) bool {
	p := pfx.nox_xxx_particleFxNew_4AF990(image.Pt(0, 0), 0, 5, pfx.r.Data().Color2())
	if p == nil {
		return false
	}
	p.drawableVp = t.field5.drawableVp
	p.setDrawable8(t.field5.drawable12)
	p.drawFunc = func(p *particleFx) {
		d := pfx.r.Data()
		d.SetAlphaEnabled(true)
		d.SetAlpha(byte(0xff * p.ticksLeft / p.ticksTotal))
		partfxDraw(p)
		d.SetAlphaEnabled(false)
	}
	return true
}

func nox_xxx_partfxSwitch_4AF690(fx *packetParticleFx, fnc func(pt image.Point)) {
	pix := fx.img.Pixdata()
	if len(pix) < 5 {
		return
	}
	w := int(pix[0])
	h := int(pix[1])
	xx := fx.pos.X + int(pix[2])
	yy := fx.pos.Y + int(pix[3])
	pix = pix[5:]
	if h == 0 {
		return
	}

	cnt2 := 0
	buf := pix
	for j := 0; j < h; j++ {
		var n int
		for i := 0; i < w; i += n {
			n = int(buf[1])
			op := buf[0] & 0xF
			buf = buf[2:]
			switch op {
			case 1:
				// nop
			case 2, 5, 6:
				cnt2 += n
				buf = buf[2*n:]
			case 4:
				cnt2 += n
				buf = buf[n:]
			default:
				n = 0
			}
		}
	}
	cnt3 := fx.cnt

	buf = pix
	for j := 0; j < h; j++ {
		var n int
		for i := 0; i < w; i += n {
			n = int(buf[1])
			op := buf[0] & 0xF
			buf = buf[2:]
			switch op {
			case 1:
				// nop
			case 2, 5, 6:
				for k := 0; k < n; k++ {
					cnt3 += fx.cnt
					if cnt3 >= cnt2 {
						cnt3 -= cnt2
						fnc(image.Pt(xx+i+k, yy+j))
					}
				}
				buf = buf[2*n:]
			case 4:
				for k := 0; k < n; k++ {
					cnt3 += fx.cnt
					if cnt3 >= cnt2 {
						cnt3 -= cnt2
						fnc(image.Pt(xx+i+k, yy+j))
					}
				}
				buf = buf[n:]
			default:
				n = 0
			}
		}
	}
}

type packetParticleFx struct {
	dr   *Drawable   // 0
	img  *Image      // 1
	vp   *Viewport   // 2
	pos  image.Point // 3
	cnt  int         // 5
	flag bool        // 6
	max  int         // 7
}

func (pfx *partFXes) onParticleFx(code byte, dr *Drawable, cnt int, flag bool, max int) {
	fx := &packetParticleFx{
		dr:   dr,
		cnt:  cnt,
		flag: flag,
		max:  max,
	}
	switch code {
	case 0:
		pfx.newPartfxT0(fx)
	case 1:
		pfx.newPartfxT1(fx)
	case 2:
		pfx.newPartfxT2(fx)
	case 3:
		pfx.newPartfxT3(fx)
	case 4:
		pfx.newPartfxT4(fx)
	case 5:
		pfx.newPartfxT5(fx)
	case 6:
		pfx.newPartfxT6(fx)
	}
}

func (fx *packetParticleFx) setImage() {
	fx.img = asImageP(fx.dr.field_2) // TODO: +8 or +32?
}

func (fx *packetParticleFx) updatePos() {
	dr := fx.dr
	fx.pos = dr.Pos().Sub(image.Pt(
		int(dr.field_0),
		int(dr.field_1)+int(dr.field_26_1)+int(dr.z),
	))
}

func (pfx *partFXes) randU16() uint16 {
	v0 := pfx.rand.u16
	for i := 0; i < 16; i++ {
		v2 := cfshl(int(v0), 1)
		v0 = rotl16(v0, 1)
		if v2 != 0 {
			v0 ^= 0xA
		}
	}
	pfx.rand.u16 = v0
	return v0
}

func (pfx *partFXes) randI32(a1, a2 int) int {
	v2 := pfx.rand.u32
	for v3 := 32; v3 != 0; v3-- {
		v4 := cfshl(int(v2), 1)
		v2 = rotl(v2, 1)
		if v4 != 0 {
			v2 ^= 0xA0A
		}
	}
	pfx.rand.u32 = v2
	return a1 + int((uint64(a2-a1)*uint64(v2))>>32)
}

func (pfx *partFXes) newPartfxT0(fx *packetParticleFx) {
	r := pfx.r
	fx.setImage()
	if fx.img == nil {
		return
	}
	fx.updatePos()
	nox_xxx_partfxSwitch_4AF690(fx, func(pt image.Point) {
		r.Data().setColorInt54(RGB{
			R: 0xFF, G: 0x80, B: 0x20,
		})
		r.Data().setField262(pfx.randI32(2, 3))
		rp := r.newParticle(0, 0xFF)
		z := pfx.randI32(0, 40)
		dur := pfx.randI32(0, fx.max)
		p := pfx.nox_xxx_particleFxNew_4AF990(image.Pt(pt.X, pt.Y+z), z, dur, r.Data().Color2())
		if p == nil {
			return
		}
		p.rendPart = rp
		p.setDrawable8(fx.dr)
		p.remains44 = 50
		p.xrel16 = int(pfx.randU16())
		p.zrel16off = math.MinInt16
		p.setMulDiv(45875, true)
	})
}

func sub_4AEDA0(ind, mul int) (pt image.Point) {
	if ind < 0 {
		ind = 0
	} else if ind > 256 {
		ind = 256
	}
	pt.X = (mul * int(memmap.Int32(0x5D4594, 1310096+4*uintptr(ind)))) >> 16
	pt.Y = (mul * int(memmap.Int32(0x5D4594, 1309840+4*uintptr(ind)))) >> 16
	return
}

func (pfx *partFXes) randPoint(min, max, mul int, pt4 image.Point) image.Point {
	return sub_4AEDA0(pfx.randI32(min, max), mul).Add(pt4)
}

func (pfx *partFXes) newPartfxT1(fx *packetParticleFx) {
	dr := fx.dr
	pos := dr.Pos()
	cl := color.White
	for i := 0; i < fx.cnt; i++ {
		p := pfx.nox_xxx_particleFxNew_4AF990(pos, 0, 128, cl)
		if p == nil {
			continue
		}
		p.field_68 = pfx.randI32(-256, 256)
		p.field_72 = 0
		p.field_76 = 0
		p.setDrawable8(dr)
		p.remains44 = pfx.randI32(0, 128)
		p.pointSize = 2
		p.yrel16 = math.MinInt16/2 - int(pfx.randU16()>>2)
		p.updateFunc = func(fx *particleFx) bool {
			if fx.ticksLeft < 0 {
				return false
			}
			fx.cnt40++
			if fx.remains44 != 0 {
				fx.remains44--
				return true
			}
			if fx.field_68 >= 0 {
				fx.field_72 -= 4
			} else {
				fx.field_72 += 4
			}
			fx.field_68 += fx.field_72
			v10 := (fx.field_68 * fx.field_76) >> 2
			fx.field_76 += 256
			fx.ticksLeft--
			if fx.ticksLeft < 0 {
				return false
			}
			fx.x16 = (fx.pos.X << 16) + v10
			fx.y16 += fx.yrel16
			return true
		}
	}
}

func (pfx *partFXes) newPartfxT2(fx *packetParticleFx) {
	fx.setImage()
	if fx.img == nil {
		return
	}
	fx.updatePos()
	off, sz, _ := fx.img.Meta()
	pos := fx.pos.Add(off)
	for v7 := fx.cnt - 1; v7 >= 0; v7-- {
		var cl color.Color
		if v7%2 != 0 {
			cl = nox_color_white_2523948
		} else {
			cl = nox_color_yellow_2589772
		}
		y := pos.Y + pfx.randI32(-8, -2)
		x := pfx.randI32(pos.X+sz.X/2, pos.X+sz.X)
		p := pfx.nox_xxx_particleFxNew_4AF990(image.Pt(x, y), 0, fx.max, cl)
		if p == nil {
			continue
		}
		p.pointSize = 2
		p.setDrawable8(fx.dr)
		p.field_68 = pfx.randI32(-sz.X/2, sz.X/2)
		p.field_72 = 0
		p.updateFunc = func(fx *particleFx) bool {
			if fx.ticksLeft < 0 {
				return false
			}
			fx.cnt40++
			if fx.remains44 != 0 {
				fx.remains44--
				return true
			}
			if fx.flags&4 != 0 {
				if dr := fx.drawable8; dr != nil {
					p1, p2 := dr.Pos(), dr.Point8()
					fx.pos = fx.pos.Sub(p2).Add(p1)
				}
			}
			if fx.field_68 >= 0 {
				fx.field_72 -= 1
			} else {
				fx.field_72 += 1
			}
			fx.field_68 += fx.field_72
			fx.ticksLeft--
			if fx.ticksLeft < 0 {
				return false
			}
			fx.x16 = (fx.field_68 + fx.pos.X) << 16
			fx.y16 = fx.pos.Y << 16
			return true
		}
	}
}

func (p *particleFx) updateRelPos(pt image.Point) {
	if p.ticksTotal != 0 {
		p.xrel16 = ((pt.X - p.pos.X) << 16) / p.ticksTotal
		p.yrel16 = ((pt.Y - p.pos.Y) << 16) / p.ticksTotal
	}
}

func (pfx *partFXes) newPartfxT3(fx *packetParticleFx) {
	fx.setImage()
	if fx.img == nil {
		return
	}
	fx.updatePos()
	r := pfx.r
	cl1 := noxcolor.RGB5551Color(64, 200, 64)
	cl2 := noxcolor.RGB5551Color(64, 64, 255)
	nox_xxx_partfxSwitch_4AF690(fx, func(pt image.Point) {
		cl := cl1
		if fx.flag {
			cl = cl2
		}
		c := noxrender.SplitColor(cl)
		r.Data().setColorInt54(RGB{
			R: int(c.R), G: int(c.G), B: int(c.B),
		})
		r.Data().setField262(pfx.randI32(2, 5))
		rp := r.newParticle(0, 0xFF)
		pt2 := pfx.randPoint(0, 256, 120, pt)
		p := pfx.nox_xxx_particleFxNew_4AF990(pt2, 0, pfx.randI32(1, fx.max), r.Data().Color2())
		if p == nil {
			return
		}
		p.loadParticle(particlefxObjName)
		p.setDrawable8(fx.dr)
		p.rendPart = rp
		p.updateRelPos(pt)
	})
}

func (pfx *partFXes) newPartfxT4(fx *packetParticleFx) {
	nox_xxx_partfxSwitch_4AF690(fx, func(pt image.Point) {
		p := pfx.nox_xxx_particleFxNew_4AF990(pt, 0, pfx.randI32(0, 100), color.White)
		p.pointSize = 1
		p.remains44 = pfx.randI32(0, 64)
		p.yrel16 = int(pfx.randU16()) - 6553
	})
}

func (pfx *partFXes) newPartfxT5(fx *packetParticleFx) {
	r := pfx.r
	r.Data().setColorInt54(RGB{
		R: 0x32, G: 0x32, B: 0x32,
	})
	r.Data().setField262(10)
	rp := r.newParticle(0, 0xFF)
	p := pfx.nox_xxx_particleFxNew_4AF990(image.Pt(0, 0), 0, math.MaxInt32, r.Data().Color2())
	if p == nil {
		return
	}
	p.setDrawable8(fx.dr)
	p.rendPart = rp
	pfx.registerParticleFx(pfx.sub_4AF4C0, p, 1, fx.max)
}

func (pfx *partFXes) newPartfxT6(fx *packetParticleFx) {
	p := pfx.nox_xxx_particleFxNew_4AF990(image.Pt(0, 0), 0, math.MaxInt32, pfx.r.Data().Color2())
	if p == nil {
		return
	}
	p.drawableVp = fx.vp
	p.setDrawable8(fx.dr)
	p.drawFunc = nil
	p.updateFunc = nil
	pfx.registerParticleFx(pfx.nox_xxx_partFx_4AF600, p, 1, 500)
}
