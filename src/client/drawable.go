package client

import (
	"image"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	drawableExts = make(map[unsafe.Pointer]*DrawableExt)
)

type DrawableExt struct {
	Field99 **Drawable
}

func Nox_xxx_sprite_2d_remove(dr *Drawable, ext *DrawableExt) {
	if v := dr.Field_101; v != nil {
		v.Field_100 = dr.Field_100
	} else {
		*ext.Field99 = dr.Field100()
	}
	if v := dr.Field_100; v != nil {
		v.Field_101 = dr.Field_101
	}
	ext.Field99 = nil
}

type Drawable struct {
	Field_0           uint32         // 0, 0
	Field_1           uint32         // 1, 4
	Field_2           unsafe.Pointer // 2, 8
	PosVec            image.Point    // 3, 12
	Field_5           uint32         // 5, 20
	Field_6           uint32         // 6, 24
	Field_7           uint32         // 7, 28
	Field_8           uint32         // 8, 32
	Field_9           uint32         // 9, 36
	Field_10          uint32         // 10, 40
	Shape             server.Shape   // 11, 44
	Field_24          float32        // 24, 96
	Field_25          float32        // 25, 100
	ZVal              uint16         // 26, 104
	Field_26_1        uint16         // 26, 106
	Field_27          uint32         // 27, 108, thing ID? pointer? union?
	Flags28Val        uint32         // 28, 112
	Flags29Val        uint32         // 29, 116
	Flags30Val        uint32         // 30, 120
	Buffs             uint32         // 31, 124
	Field_32          uint32         // 32, 128, npc ID?
	Field_33          uint32         // 33, 132
	LightFlags        uint32         // 34, 136, 0
	LightIntensity    float32        // 35, 140, 1
	LightIntensityRad uint32         // 36, 144, 2
	LightIntensityU16 uint32         // 37, 148, 3
	LightColorR       uint32         // 38, 152, 4
	LightColorG       uint32         // 39, 156, 5
	LightColorB       uint32         // 40, 160, 6
	Field_41_0        uint16         // 41, 164
	Field_41_1        uint16         // 41, 166
	Field_42          uint32         // 42, 168
	Field_43          uint32         // 43, 172
	Field_44          uint32         // 44, 176
	data_45           [5]uint32
	data_50           [10]uint32
	data_60           [5]uint32
	Field_65          uint32         // 65, 260
	Field_66          uint32         // 66, 264
	Field_67          uint32         // 67, 268
	Field_68          uint32         // 68, 272
	Field_69          uint32         // 69, 276
	Flags70Val        uint32         // 70, 280
	Field_71_0        uint8          // 71, 284
	Field_71_1        uint8          // 71, 285
	Field_71_2        uint16         // 71, 286
	Field_72          uint32         // 72, 288
	Field_73_1        uint16         // 73, 292
	Field_73_2        uint16         // 73, 294
	VelZ              int8           // 74, 296
	Field_74_2        byte           // 74, 297
	Field_74_3        byte           // 74, 298
	Field_74_4        byte           // 74, 299
	DrawFuncPtr       unsafe.Pointer // 75, 300, (*DrawFuncPtr)(uint32_t*, nox_drawable*) same as CObjectType->draw_func
	Field_76          unsafe.Pointer // 76, 304
	Field_77          uint32         // 77, 308
	Field_78          uint32         // 78, 312
	Field_79          uint32         // 79, 316
	Field_80          uint32         // 80, 320
	Field_81          uint32         // 81, 324
	Field_82          uint32         // 82, 328
	Field_83          *Drawable      // 83, 332
	Field_84          *Drawable      // 84, 336
	Field_85          uint32         // 85, 340, last draw frame number?
	Field_86          uint32         // 86, 344
	Field_87          *Drawable      // 87, 348
	Field_88          *Drawable      // 88, 352
	Deadline          uint32         // 89, 356
	Field_90          *Drawable      // 90, 360
	Field_91          *Drawable      // 91, 364
	NextPtr           *Drawable      // 92, 368
	Field_93          *Drawable      // 93, 372
	Field_94          *Drawable      // 94, 376
	Field_95          *Drawable      // 95, 380
	Field_96          uint32         // 96, 384
	Field_97          *Drawable      // 97, 388
	Field_98          *Drawable      // 98, 392
	Field_99          **Drawable     // 99, 396
	Field_100         *Drawable      // 100, 400
	Field_101         *Drawable      // 101, 404
	Field_102         *Drawable      // 102, 408
	Field_103         *Drawable      // 103, 412
	Field_104         *Drawable      // 104, 416
	Field_105         *Drawable      // 105, 420
	Field_106         *Drawable      // 106, 424
	Field_107         *Drawable      // 107, 428
	Field_108         uint32         // 108, 432 // TODO: union?
	Field_109         uint32         // 109, 436, SE?
	Field_110         uint32         // 110, 440, SW?
	Field_111         uint32         // 111, 444, SW?
	Field_112_0       int16          // 112, 448
	Field_112_2       int16          // 112, 450
	Field_113         uint32         // 113, 452
	Field_114         *DrawableFX    // 114, 456
	Field_115         uint32         // 115, 460
	Field_116         uint32         // 116, 464
	Field_117         uint32         // 117, 468
	Field_118         uint32         // 118, 472
	Field_119         uint32         // 119, 476
	Field_120         uint32         // 120, 480
	Field_121         uint32         // 121, 484
	Field_122         uint32         // 122, 488
	Field_123         uint32         // 123, 492
	Field_124         unsafe.Pointer // 124, 496
	Field_125         uint32         // 125, 500
	Field_126         uint32         // 126, 504
	Field_127         uint32         // 127, 508
}

func (s *Drawable) C() unsafe.Pointer {
	return unsafe.Pointer(s)
}

func (s *Drawable) Ext() *DrawableExt {
	if s == nil {
		return nil
	}
	p := drawableExts[unsafe.Pointer(s)]
	if p == nil {
		p = new(DrawableExt)
		drawableExts[unsafe.Pointer(s)] = p
	}
	return p
}

func (s *Drawable) Next() *Drawable {
	if s == nil {
		return nil
	}
	return s.NextPtr
}

func (s *Drawable) Pos() image.Point {
	return s.PosVec
}

func (s *Drawable) SetPos(p image.Point) {
	s.PosVec = p
}

func (s *Drawable) Point8() image.Point {
	return image.Point{
		X: int(s.Field_8),
		Y: int(s.Field_9),
	}
}

func (s *Drawable) Field25() float32 {
	return s.Field_25
}

func (s *Drawable) Flags28() uint {
	return uint(s.Flags28Val)
}

func (s *Drawable) Flags29() uint {
	return uint(s.Flags29Val)
}

func (s *Drawable) Flags30() uint {
	return uint(s.Flags30Val)
}

func (s *Drawable) HasEnchant(v server.EnchantID) bool { // nox_client_drawable_testBuff_4356C0
	if s == nil || v >= 32 {
		return false
	}
	return (uint(s.Buffs) & (1 << v)) != 0
}

func (s *Drawable) Flags70() uint {
	return uint(s.Flags70Val)
}

func (s *Drawable) Field27() uint32 {
	return s.Field_27 // TODO: Thing ID?
}

func (s *Drawable) Field32() uint32 {
	return s.Field_32 // TODO: NPC ID?
}

func (s *Drawable) SetLightColor(r, g, b byte) { // nox_xxx_spriteChangeLightColor_484BE0
	if s == nil {
		return
	}
	s.LightFlags = 2
	s.LightColorR = uint32(r)
	s.LightColorG = uint32(g)
	s.LightColorB = uint32(b)
}

func (s *Drawable) Field100() *Drawable {
	return s.Field_100
}

func (s *Drawable) Field104() *Drawable { // sub_45A010
	return s.Field_104
}

func (s *Drawable) TeamPtr() *server.ObjectTeam {
	return (*server.ObjectTeam)(unsafe.Pointer(&s.Field_6))
}

func (s *Drawable) Z() int {
	return int(s.ZVal)
}

const (
	lightMinIntensity = 1.0
)

func (s *Drawable) SetLightIntensity(v float32) { // nox_xxx_spriteChangeIntensity_484D70_light_intensity
	if s == nil {
		return
	}
	const (
		qword_581450_9544 = 0.5
		qword_581450_9552 = 0x10000
	)
	if v > 63.0 {
		v = 63.0
	}
	s.LightIntensity = v
	s.LightIntensityU16 = uint32(v*qword_581450_9552 + qword_581450_9544)
	s.LightIntensityRad = uint32(LightRadius(v))
}

func LightRadius(intens float32) int {
	if intens <= lightMinIntensity {
		return 0
	}
	intens2 := intens
	if intens2 > 31.0 {
		intens2 = 31.0
	}
	// TODO: remove references to memmap
	return int(math.Sqrt(float64(((memmap.Float32(0x587000, 154980)+intens2)/
		(memmap.Float32(0x587000, 154980)+lightMinIntensity) + 1.0) *
		(intens * intens / (memmap.Float32(0x587000, 154976) * memmap.Float32(0x587000, 154972))))))
}

func (s *Drawable) LinkType(i int, typ *ObjectType) {
	*s = Drawable{}
	s.Field_27 = uint32(i)
	*(*uint8)(unsafe.Add(unsafe.Pointer(&s.Field_0), 0)) = typ.HWidth
	*(*uint8)(unsafe.Add(unsafe.Pointer(&s.Field_0), 1)) = typ.HHeight
	s.Field_26_1 = typ.Z // TODO: shouldn't it put this in dr.z?
	s.Flags28Val = typ.ObjClass
	s.Flags29Val = typ.ObjSubClass
	s.Flags30Val = uint32(typ.ObjFlags)
	s.Flags70Val = typ.Field_54
	s.Field_74_3 = typ.Weight
	s.DrawFuncPtr = typ.DrawFunc
	s.Field_76 = typ.Field_5c
	s.Field_77 = typ.Field_60
	s.Field_116 = typ.ClientUpdate
	s.Field_123 = typ.AudioLoop
	s.LightFlags = uint32(typ.Field_f)
	s.Field_42 = typ.Field_10
	s.LightColorR = uint32(typ.LightColorR)
	s.LightColorG = uint32(typ.LightColorG)
	s.LightColorB = uint32(typ.LightColorB)
	s.Field_41_0 = typ.LightDir
	s.Field_41_1 = typ.LightPenumbra

	s.Shape.Kind = server.ShapeKind(typ.ShapeKind)
	s.Shape.Circle.R = typ.ShapeR
	s.Shape.Circle.R2 = typ.ShapeR * typ.ShapeR
	s.Shape.Box.W = typ.ShapeW
	s.Shape.Box.H = typ.ShapeH
	if s.Shape.Kind == server.ShapeKindBox {
		s.Shape.Box.Calc()
	}

	s.Field_24 = typ.ZSizeMin
	s.Field_25 = typ.ZSizeMax
	intens := typ.LightIntensity
	s.Field_43 = 0
	if intens < 0 {
		intens = -intens
		s.Field_43 = 1
	}
	s.LightIntensity = intens
	if intens != 0.0 {
		s.SetLightIntensity(intens)
		if s.LightFlags == 0 {
			s.LightFlags = 1
			s.LightColorR = 255
			s.LightColorG = 255
			s.LightColorB = 255
		}
	}
	if s.Flags28Val&0x13001000 != 0 {
		s.Field_108 = 0
		s.Field_109 = 0
		s.Field_110 = 0
		s.Field_111 = 0
		s.Field_112_0 = -1
		s.Field_112_2 = -1
	}
}
