package opennox

/*
#include "defs.h"
extern int nox_drawable_count;
int  nox_xxx_client_4984B0_drawable(nox_drawable* dr);
nox_drawable* nox_xxx_spriteLoadAdd_45A360_drawable(int thingInd, int a2, int a3);
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

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	drawableExts = make(map[unsafe.Pointer]*drawableExt)
)

func drawableCount() int {
	return int(C.nox_drawable_count)
}

type drawableExt struct {
	Field99 **Drawable
}

func asDrawable(p *nox_drawable) *Drawable {
	return (*Drawable)(unsafe.Pointer(p))
}

type nox_drawable = C.nox_drawable

type Drawable struct {
	field_0             uint32         // 0, 0
	field_1             uint32         // 1, 4
	field_2             unsafe.Pointer // 2, 8
	pos                 image.Point    // 3, 12
	field_5             uint32         // 5, 20
	field_6             uint32         // 6, 24
	field_7             uint32         // 7, 28
	field_8             uint32         // 8, 32
	field_9             uint32         // 9, 36
	field_10            uint32         // 10, 40
	shape               server.Shape   // 11, 44
	field_24            float32        // 24, 96
	field_25            float32        // 25, 100
	z                   uint16         // 26, 104
	field_26_1          uint16         // 26, 106
	field_27            uint32         // 27, 108, thing ID? pointer? union?
	flags28             uint32         // 28, 112
	flags29             uint32         // 29, 116
	flags30             uint32         // 30, 120
	buffs               uint32         // 31, 124
	field_32            uint32         // 32, 128, npc ID?
	field_33            uint32         // 33, 132
	light_flags         uint32         // 34, 136, 0
	light_intensity     float32        // 35, 140, 1
	light_intensity_rad uint32         // 36, 144, 2
	light_intensity_u16 uint32         // 37, 148, 3
	light_color_r       uint32         // 38, 152, 4
	light_color_g       uint32         // 39, 156, 5
	light_color_b       uint32         // 40, 160, 6
	field_41_0          uint16         // 41, 164
	field_41_1          uint16         // 41, 166
	field_42            uint32         // 42, 168
	field_43            uint32         // 43, 172
	field_44            uint32         // 44, 176
	data_45             [5]uint32
	data_50             [10]uint32
	data_60             [5]uint32
	field_65            uint32         // 65, 260
	field_66            uint32         // 66, 264
	field_67            uint32         // 67, 268
	field_68            uint32         // 68, 272
	field_69            uint32         // 69, 276
	flags70             uint32         // 70, 280
	field_71            uint32         // 71, 284
	field_72            uint32         // 72, 288
	field_73_1          uint16         // 73, 292
	field_73_2          uint16         // 73, 294
	vel_z               int8           // 74, 296
	field_74_2          byte           // 74, 297
	field_74_3          byte           // 74, 298
	field_74_4          byte           // 74, 299
	draw_func           unsafe.Pointer // 75, 300, (*draw_func)(uint32_t*, nox_drawable*) same as CObjectType->draw_func
	field_76            unsafe.Pointer // 76, 304
	field_77            uint32         // 77, 308
	field_78            uint32         // 78, 312
	field_79            uint32         // 79, 316
	field_80            uint32         // 80, 320
	field_81            uint32         // 81, 324
	field_82            uint32         // 82, 328
	field_83            uint32         // 83, 332
	field_84            uint32         // 84, 336
	field_85            uint32         // 85, 340, last draw frame number?
	field_86            uint32         // 86, 344
	field_87            uint32         // 87, 348
	field_88            uint32         // 88, 352
	field_89            uint32         // 89, 356
	field_90            *Drawable      // 90, 360
	field_91            *Drawable      // 91, 364
	field_92            *Drawable      // 92, 368
	field_93            *Drawable      // 93, 372
	field_94            uint32         // 94, 376
	field_95            uint32         // 95, 380
	field_96            uint32         // 96, 384
	field_97            *Drawable      // 97, 388
	field_98            *Drawable      // 98, 392
	field_99            **Drawable     // 99, 396
	field_100           *Drawable      // 100, 400
	field_101           *Drawable      // 101, 404
	field_102           uint32         // 102, 408
	field_103           uint32         // 103, 412
	field_104           *Drawable      // 104, 416
	field_105           *Drawable      // 105, 420
	field_106           uint32         // 106, 424
	field_107           uint32         // 107, 428
	field_108_1         byte           // 108, 432 // TODO: union?
	field_108_2         byte           // 108, 433
	field_108_3         uint16         // 108, 434
	field_109           uint32         // 109, 436, SE?
	field_110           uint32         // 110, 440, SW?
	field_111           uint32         // 111, 444, SW?
	field_112           uint32         // 112, 448, SE?
	field_113           uint32         // 113, 452
	field_114           uint32         // 114, 456
	field_115           uint32         // 115, 460
	field_116           uint32         // 116, 464
	field_117           uint32         // 117, 468
	field_118           uint32         // 118, 472
	field_119           uint32         // 119, 476
	field_120           uint32         // 120, 480
	field_121           uint32         // 121, 484
	field_122           uint32         // 122, 488
	field_123           uint32         // 123, 492
	field_124           uint32         // 124, 496
	field_125           uint32         // 125, 500
	field_126           uint32         // 126, 504
	field_127           uint32         // 127, 508
}

func (s *Drawable) C() *nox_drawable {
	return (*nox_drawable)(unsafe.Pointer(s))
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
	return s.pos
}

func (s *Drawable) Point8() image.Point {
	return image.Point{
		X: int(s.field_8),
		Y: int(s.field_9),
	}
}

func (s *Drawable) SetPos(p image.Point) {
	s.pos = p
}

func (s *Drawable) Field25() float32 {
	return s.field_25
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

func (s *Drawable) HasEnchant(v server.EnchantID) bool { // nox_client_drawable_testBuff_4356C0
	if s == nil || v >= 32 {
		return false
	}
	return (uint(s.buffs) & (1 << v)) != 0
}

func (s *Drawable) Flags70() uint {
	return uint(s.flags70)
}

func (s *Drawable) Field27() uint32 {
	return s.field_27 // TODO: Thing ID?
}

func (s *Drawable) Field32() uint32 {
	return s.field_32 // TODO: NPC ID?
}

func (s *Drawable) SetLightColor(r, g, b byte) { // nox_xxx_spriteChangeLightColor_484BE0
	if s == nil {
		return
	}
	s.light_flags = 2
	s.light_color_r = uint32(r)
	s.light_color_g = uint32(g)
	s.light_color_b = uint32(b)
}

func (s *Drawable) SetLightIntensity(v float32) { // nox_xxx_spriteChangeIntensity_484D70_light_intensity
	if s == nil {
		return
	}
	if v > 63.0 {
		v = 63.0
	}
	s.light_intensity = v
	s.light_intensity_u16 = uint32(v*qword_581450_9552 + qword_581450_9544)
	s.light_intensity_rad = uint32(lightRadius(v))
}

func (s *Drawable) Field100() *Drawable {
	return s.field_100
}

func (s *Drawable) Field104() *Drawable { // sub_45A010
	return s.field_104
}

func (s *Drawable) getShape() *server.Shape {
	return &s.shape
}

func (s *Drawable) DrawFunc(vp *noxrender.Viewport) int {
	return int(C.go_nox_drawable_call_draw_func((*nox_draw_viewport_t)(vp.C()), s.C()))
}

func (s *Drawable) Z() int {
	return int(s.z)
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

func nox_xxx_spriteLoadAdd_45A360_drawable(thingInd int, pos image.Point) *Drawable {
	return asDrawable(C.nox_xxx_spriteLoadAdd_45A360_drawable(C.int(thingInd), C.int(pos.X), C.int(pos.Y)))
}

//export nox_xxx_sprite_49AA00_drawable
func nox_xxx_sprite_49AA00_drawable(d *nox_drawable) {
	dr := asDrawable(d)
	pos := dr.Pos()
	xi := pos.X / nox_drawable_2d_div
	yi := pos.Y / nox_drawable_2d_div

	ext := dr.Ext()
	if ext.Field99 != nil {
		nox_xxx_sprite_2d_remove(dr, ext)
	}

	dr.field_101 = nil

	if xi < 0 || xi >= len(nox_drawable_2d_index) {
		return
	}
	index := nox_drawable_2d_index[xi]
	if yi < 0 || yi >= len(index) {
		return
	}
	v4 := index[yi]
	dr.field_100 = v4
	if v4 != nil {
		v4.field_101 = dr
	}
	nox_drawable_2d_index[xi][yi] = dr

	ext.Field99 = &nox_drawable_2d_index[xi][yi]
}

//export nox_xxx_sprite_49A9B0_drawable
func nox_xxx_sprite_49A9B0_drawable(d *nox_drawable) C.int {
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
func nox_drawable_find_49ABF0(pt *C.nox_point, r C.int) *nox_drawable {
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
