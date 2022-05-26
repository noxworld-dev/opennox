package opennox

/*
#include "defs.h"
int nox_xxx_getTTByNameSpriteMB_44CFC0(char* a1);
int  nox_xxx_client_4984B0_drawable(nox_drawable* dr);
static int go_nox_drawable_call_draw_func(nox_draw_viewport_t* vp, nox_drawable* dr) {
	return dr->draw_func(vp, dr);
}
static void go_nox_drawable_call_sprite_func(void(* fnc)(nox_drawable*, int), nox_drawable* dr, int arg) {
	fnc(dr, arg);
}
*/
import "C"
import (
	"image"
	"unsafe"
)

var (
	drawableExts = make(map[unsafe.Pointer]*drawableExt)
)

func nox_xxx_getTTByNameSpriteMB_44CFC0(name string) uint32 {
	return uint32(C.nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr(name)))
}

type drawableExt struct {
	Field99 **Drawable
}

func asDrawable(p *C.nox_drawable) *Drawable {
	return (*Drawable)(unsafe.Pointer(p))
}

type Drawable C.nox_drawable

func (s *Drawable) C() *C.nox_drawable {
	return (*C.nox_drawable)(unsafe.Pointer(s))
}

func (s *Drawable) field(dp uintptr) unsafe.Pointer {
	return unsafe.Add(unsafe.Pointer(s), dp)
}

func (s *Drawable) Ext() *drawableExt {
	if s == nil {
		return nil
	}
	p := drawableExts[unsafe.Pointer(s)]
	if p == nil {
		p = new(drawableExt)
		drawableExts[unsafe.Pointer(s)] = p
	}
	return p
}

func (s *Drawable) Pos() image.Point {
	return image.Point{
		X: int(s.pos.x),
		Y: int(s.pos.y),
	}
}

func (s *Drawable) Point8() image.Point {
	return image.Point{
		X: int(s.field_8),
		Y: int(s.field_9),
	}
}

func (s *Drawable) SetPos(p image.Point) {
	s.pos.x = C.int(p.X)
	s.pos.y = C.int(p.Y)
}

func (s *Drawable) Field25() float32 {
	return float32(s.field_25)
}

func (s *Drawable) Flags28() uint {
	return uint(s.flags28)
}

func (s *Drawable) Flags29() uint {
	return uint(s.flags29)
}

func (s *Drawable) Flags30() uint {
	return uint(s.flags30)
}

func (s *Drawable) Flags31() uint {
	return uint(s.flags31)
}

func (s *Drawable) CheckFlag31(i byte) bool { // nox_xxx_spriteCheckFlag31_4356C0
	if s == nil {
		return false
	}
	return (s.Flags31() & (1 << i)) != 0
}

func (s *Drawable) Flags70() uint {
	return uint(s.flags70)
}

func (s *Drawable) Field27() uint32 {
	return uint32(s.field_27) // TODO: Thing ID?
}

func (s *Drawable) Field32() uint32 {
	return uint32(s.field_32) // TODO: NPC ID?
}

func (s *Drawable) SetLightColor(r, g, b byte) { // nox_xxx_spriteChangeLightColor_484BE0
	if s == nil {
		return
	}
	s.light_flags = 2
	s.light_color_r = C.uint(r)
	s.light_color_g = C.uint(g)
	s.light_color_b = C.uint(b)
}

func (s *Drawable) SetLightIntensity(v float32) { // nox_xxx_spriteChangeIntensity_484D70_light_intensity
	if s == nil {
		return
	}
	if v > 63.0 {
		v = 63.0
	}
	s.light_intensity = C.float(v)
	s.light_intensity_u16 = C.uint(v*qword_581450_9552 + qword_581450_9544)
	s.light_intensity_rad = C.uint(lightRadius(v))
}

func (s *Drawable) Field100() *Drawable {
	return asDrawable(s.field_100)
}

func (s *Drawable) Field104() *Drawable { // sub_45A010
	return asDrawable(s.field_104)
}

func (s *Drawable) getShape() *noxShape {
	return (*noxShape)(unsafe.Pointer(&s.shape))
}

func (s *Drawable) DrawFunc(vp *Viewport) int {
	return int(C.go_nox_drawable_call_draw_func(vp.C(), s.C()))
}

const (
	nox_drawable_2d_index_cap = 47
	nox_drawable_2d_div       = 128
)

var (
	nox_drawable_2d_index      [][]*Drawable
	nox_drawable_2d_index_size int
)

func sub_49A8E0_init() {
	nox_drawable_2d_index_size = nox_drawable_2d_index_cap
	nox_drawable_2d_index = make([][]*Drawable, nox_drawable_2d_index_size)
	for i := 0; i < nox_drawable_2d_index_size; i++ {
		nox_drawable_2d_index[i] = make([]*Drawable, nox_drawable_2d_index_size)
	}
}

func sub_49A950_free() {
	nox_drawable_2d_index = nil
	nox_drawable_2d_index_size = 0
}

//export nox_xxx_sprite_49AA00_drawable
func nox_xxx_sprite_49AA00_drawable(d *C.nox_drawable) {
	dr := asDrawable(d)
	pos := dr.Pos()
	xi := pos.X / nox_drawable_2d_div
	yi := pos.Y / nox_drawable_2d_div

	ext := dr.Ext()
	if ext.Field99 != nil {
		nox_xxx_sprite_2d_remove(dr, ext)
	}

	dr.field_101 = nil

	v4 := nox_drawable_2d_index[xi][yi]
	dr.field_100 = v4.C()
	if v4 != nil {
		v4.field_101 = dr.C()
	}
	nox_drawable_2d_index[xi][yi] = dr

	ext.Field99 = &nox_drawable_2d_index[xi][yi]
}

//export nox_xxx_sprite_49A9B0_drawable
func nox_xxx_sprite_49A9B0_drawable(d *C.nox_drawable) C.int {
	dr := asDrawable(d)
	nox_xxx_sprite_2d_remove(dr, dr.Ext())
	return 0
}

func nox_xxx_sprite_2d_remove(dr *Drawable, ext *drawableExt) {
	if v := dr.field_101; v != nil {
		v.field_100 = dr.field_100
	} else {
		*ext.Field99 = dr.Field100()
	}
	if v := dr.field_100; v != nil {
		v.field_101 = dr.field_101
	}
	ext.Field99 = nil
}

//export nox_xxx_forEachSprite_49AB00
func nox_xxx_forEachSprite_49AB00(a1 *C.int4, cfnc unsafe.Pointer, data C.int) {
	if cfnc == nil {
		return
	}
	rect := image.Rect(int(a1.field_0), int(a1.field_4), int(a1.field_8), int(a1.field_C))
	nox_xxx_forEachSprite(rect, func(dr *Drawable) {
		C.go_nox_drawable_call_sprite_func((*[0]byte)(cfnc), dr.C(), data)
	})
}

func nox_xxx_forEachSprite(rect image.Rectangle, fnc func(dr *Drawable)) {
	if fnc == nil {
		return
	}
	xs := rect.Min.X / nox_drawable_2d_div
	if xs < 0 {
		xs = 0
	}
	ys := rect.Min.Y / nox_drawable_2d_div
	if ys < 0 {
		ys = 0
	}
	xe := rect.Max.X / nox_drawable_2d_div
	if xe >= nox_drawable_2d_index_size {
		xe = nox_drawable_2d_index_size - 1
	}
	ye := rect.Max.Y / nox_drawable_2d_div
	if ye >= nox_drawable_2d_index_size {
		ye = nox_drawable_2d_index_size - 1
	}
	for y := ys; y <= ye; y++ {
		for x := xs; x <= xe; x++ {
			for cur := nox_drawable_2d_index[x][y]; cur != nil; cur = cur.Field100() {
				fnc(cur)
			}
		}
	}
}

//export nox_drawable_find_49ABF0
func nox_drawable_find_49ABF0(pt *C.nox_point, r C.int) *C.nox_drawable {
	return nox_drawable_find(image.Point{X: int(pt.x), Y: int(pt.y)}, int(r)).C()
}

func nox_drawable_find(pt image.Point, r int) *Drawable {
	xs := (pt.X - r) / nox_drawable_2d_div
	if xs < 0 {
		xs = 0
	}
	ys := (pt.Y - r) / nox_drawable_2d_div
	if ys < 0 {
		ys = 0
	}
	xe := (pt.X + r) / nox_drawable_2d_div
	if xe >= nox_drawable_2d_index_size {
		xe = nox_drawable_2d_index_size - 1
	}
	ye := (pt.Y + r) / nox_drawable_2d_div
	if ye >= nox_drawable_2d_index_size {
		ye = nox_drawable_2d_index_size - 1
	}
	var (
		out *Drawable
		min = -1
		r2  = r * r
	)
	for y := ys; y <= ye; y++ {
		for x := xs; x <= xe; x++ {
			for dr := nox_drawable_2d_index[x][y]; dr != nil; dr = dr.Field100() {
				if C.nox_xxx_client_4984B0_drawable(dr.C()) == 0 {
					continue
				}
				dp := pt.Sub(dr.Pos())
				d2 := dp.X*dp.X + dp.Y*dp.Y
				if d2 >= r2 {
					continue
				}
				if min < 0 || d2 < min {
					min = d2
					out = dr
				}
			}
		}
	}
	return out
}
