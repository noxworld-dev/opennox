package client

import (
	"image"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

const (
	Nox_drawable_2d_index_cap = 47
	Nox_drawable_2d_div       = 128
)

var (
	drawableExts = make(map[unsafe.Pointer]*DrawableExt)
)

type DrawableExt struct {
	Field99 **Drawable
}

func (c *Client) DrawableLinkThing(dr *Drawable, i int) int {
	typ := c.Things.TypeByInd(i)
	if typ == nil {
		return 0
	}
	dr.LinkType(i, typ)
	if typ.Lifetime != 0 {
		c.Objs.TransparentDecay(dr, int(typ.Lifetime))
	}
	return 1
}

type clientDrawables struct {
	c *Client

	Alloc        alloc.ClassT[Drawable]
	Count        int
	List1        *Drawable
	List2        *Drawable
	list3        *Drawable
	List4        *Drawable
	clientUpdate *Drawable
	playerList   *Drawable
	minimapList  *Drawable
	List6        *Drawable
	DeadlineList *Drawable
	List8        *Drawable
	Index2D      [][]*Drawable
	Index2DSize  int
}

func (c *clientDrawables) init(cli *Client) {
	c.c = cli
}

func (c *clientDrawables) Init(cnt int) {
	c.Alloc = alloc.NewClassT("drawableClass", Drawable{}, cnt)
	c.initIndex2D()
}

func (c *clientDrawables) Free() {
	c.freeIndex2D()
	c.Alloc.Free()
	c.List1 = nil
	c.List2 = nil
	c.list3 = nil
	c.List4 = nil
	c.Count = 0
}

func (c *clientDrawables) initIndex2D() {
	c.Index2DSize = Nox_drawable_2d_index_cap
	c.Index2D = make([][]*Drawable, c.Index2DSize)
	for i := 0; i < c.Index2DSize; i++ {
		c.Index2D[i] = make([]*Drawable, c.Index2DSize)
	}
}

func (c *clientDrawables) freeIndex2D() {
	c.Index2D = nil
	c.Index2DSize = 0
}

func (c *clientDrawables) FirstList1() *Drawable {
	return c.List1
}

func (c *clientDrawables) FirstList2() *Drawable {
	return c.List2
}

func (c *clientDrawables) FirstList5() *Drawable {
	return c.clientUpdate
}

func (c *clientDrawables) FirstList8() *Drawable {
	return c.List8
}

func (c *clientDrawables) FirstMinimapList() *Drawable {
	return c.minimapList
}

func (c *clientDrawables) FirstPlayerList() *Drawable {
	return c.playerList
}

func (c *clientDrawables) List34Add(dr *Drawable) {
	dr.Field_98 = nil
	dr.Field_97 = c.list3
	if c.list3 != nil {
		c.list3.Field_98 = dr
	} else {
		c.List4 = dr
	}
	c.list3 = dr
	dr.Flags30Val |= 0x400000
}

func (c *clientDrawables) List34Delete(dr *Drawable) {
	if (dr.Flags30() & 0x400000) == 0 {
		return
	}
	if dr2 := dr.Field_98; dr2 != nil {
		dr2.Field_97 = dr.Field_97
	} else {
		c.list3 = dr.Field_97
	}
	if dr2 := dr.Field_97; dr2 != nil {
		dr2.Field_98 = dr.Field_98
	} else {
		c.List4 = dr.Field_98
	}
	dr.Flags30Val &= 0xFFBFFFFF
}

func (c *clientDrawables) ClientUpdateAdd(dr *Drawable) {
	if dr.InClientUpdateList != 0 {
		return
	}
	dr.Field_95 = nil
	dr.Field_94 = c.clientUpdate
	if c.clientUpdate != nil {
		c.clientUpdate.Field_95 = dr
	}
	c.clientUpdate = dr
	dr.InClientUpdateList = 1
}

func (c *clientDrawables) ClientUpdateDelete(dr *Drawable) {
	if dr.InClientUpdateList == 0 {
		return
	}
	if v2 := dr.Field_95; v2 != nil {
		v2.Field_94 = dr.Field_94
		if v3 := dr.Field_94; v3 != nil {
			v3.Field_95 = dr.Field_95
			dr.InClientUpdateList = 0
			return
		}
	} else {
		c.clientUpdate = dr.Field_94
		if v4 := dr.Field_94; v4 != nil {
			v4.Field_95 = nil
		}
	}
	dr.InClientUpdateList = 0
}

func (c *clientDrawables) List6Add(dr *Drawable) {
	dr.Field_84 = nil
	dr.Field_83 = c.List6
	if c.List6 != nil {
		c.List6.Field_84 = dr
	}
	c.List6 = dr
	dr.Flags30Val |= 0x200000
}

func (c *clientDrawables) List6Delete(dr *Drawable) {
	if dr.Flags30()&0x200000 == 0 {
		return
	}
	if v2 := dr.Field_84; v2 != nil {
		v2.Field_83 = dr.Field_83
	} else {
		c.List6 = dr.Field_83
	}
	if v3 := dr.Field_83; v3 != nil {
		v3.Field_84 = dr.Field_84
	}
	dr.Flags30Val &= 0xFFDFFFFF
}

func (c *clientDrawables) List8Add(dr *Drawable) {
	dr.Field_106 = c.List8
	dr.Field_107 = nil
	if c.List8 != nil {
		c.List8.Field_107 = dr
	}
	c.List8 = dr
}

func (c *clientDrawables) RemoveHealthBar(dr *Drawable, a2 uint8) {
	if dr.Flags30()&0x80000000 == 0 {
		return
	}
	set := (^a2 & dr.Field_71_0) == 0
	dr.Field_71_0 &= ^a2
	if !set {
		return
	}
	if v4 := dr.Field_102; v4 != nil {
		v4.Field_103 = dr.Field_103
	}
	if v5 := dr.Field_103; v5 != nil {
		v5.Field_102 = dr.Field_102
	} else {
		c.minimapList = dr.Field_102
	}
	dr.Flags30Val &^= 0x80000000
}

func (c *clientDrawables) MinimapAdd(dr *Drawable, a2 uint8) {
	if dr == nil {
		return
	}
	dr.Field_71_0 |= a2
	if dr.Flags30()&0x80000000 != 0 {
		return
	}
	for it := c.FirstMinimapList(); it != nil; it = it.Nox_xxx_cliNextMinimapObj_459EC0(it) {
		// TODO: this happens when hosting a Solo map in Arena game mode and leads to an infinite loop, so we prevent it
		if dr == it {
			return
		}
	}
	v4 := c.minimapList
	dr.Field_103 = nil
	dr.Field_102 = v4
	if c.minimapList != nil {
		c.minimapList.Field_103 = dr
	}
	c.minimapList = dr
	dr.Flags30Val |= 0x80000000
}

func (c *clientDrawables) DeadlineRemove(dr *Drawable) {
	if dr.Deadline == 0 {
		return
	}
	if v2 := dr.Field_88; v2 != nil {
		v2.Field_87 = dr.Field_87
	} else {
		c.DeadlineList = dr.Field_87
	}
	if v3 := dr.Field_87; v3 != nil {
		v3.Field_88 = dr.Field_88
	}
	dr.Deadline = 0
}

func (c *clientDrawables) TransparentDecay(dr *Drawable, lifetime int) {
	if dr.Deadline != 0 {
		c.DeadlineRemove(dr)
	}
	v2 := c.c.srv.Frame() + uint32(lifetime)
	dr.Deadline = v2
	if c.DeadlineList == nil {
		dr.Field_87 = nil
		dr.Field_88 = nil
		c.DeadlineList = dr
		return
	}

	var last *Drawable
	for it := c.DeadlineList; it != nil; it = it.Field_87 {
		if it.Deadline >= v2 {
			dr.Field_87 = it
			dr.Field_88 = it.Field_88
			if v5 := it.Field_88; v5 != nil {
				v5.Field_87 = dr
			} else {
				c.DeadlineList = dr
			}
			it.Field_88 = dr
			return
		}
		last = it
	}
	last.Field_87 = dr
	dr.Field_87 = nil
	dr.Field_88 = last
}

func (c *clientDrawables) ByNetCodeStatic(id int) *Drawable {
	for dr := c.List1; dr != nil; dr = dr.NextPtr {
		if dr.Flags28()&0x20400000 != 0 && dr.Field_32 == uint32(id) {
			return dr
		}
	}
	return nil
}

func (c *clientDrawables) ByNetCodeDynamic(id int) *Drawable {
	for dr := c.List1; dr != nil; dr = dr.NextPtr {
		if dr.Flags28()&0x20400000 == 0 && dr.Field_32 == uint32(id) {
			return dr
		}
	}
	return nil
}

func (c *clientDrawables) IsPlayer(dr *Drawable) bool {
	for pl := c.c.srv.Players.First(); pl != nil; pl = c.c.srv.Players.Next(pl) {
		if dr.Field_32 == pl.NetCodeVal {
			return true
		}
	}
	return false
}

func (c *clientDrawables) PlayerListAdd(dr *Drawable) {
	dr.Field_104 = c.playerList
	dr.Field_105 = nil
	if c.playerList != nil {
		c.playerList.Field_105 = dr
	}
	c.playerList = dr
}

func (c *clientDrawables) PlayerListDelete(dr *Drawable) {
	if v2 := dr.Field_104; v2 != nil {
		v2.Field_105 = dr.Field_105
	}
	if v3 := dr.Field_105; v3 != nil {
		v3.Field_104 = dr.Field_104
	} else {
		c.playerList = dr.Field_104
	}
}

func (c *clientDrawables) Index2DRemove(dr *Drawable, ext *DrawableExt) {
	if v := dr.Field_101; v != nil {
		v.Field_100 = dr.Field_100
	} else if ext.Field99 != nil {
		*ext.Field99 = dr.Field100()
	}
	if v := dr.Field_100; v != nil {
		v.Field_101 = dr.Field_101
	}
	ext.Field99 = nil
}

func (c *clientDrawables) AddIndex2D(dr *Drawable) {
	pos := dr.Pos()
	xi := pos.X / Nox_drawable_2d_div
	yi := pos.Y / Nox_drawable_2d_div

	ext := dr.Ext()
	if ext.Field99 != nil {
		c.Index2DRemove(dr, ext)
	}

	dr.Field_101 = nil

	if xi < 0 || xi >= len(c.Index2D) {
		return
	}
	index := c.Index2D[xi]
	if yi < 0 || yi >= len(index) {
		return
	}
	v4 := index[yi]
	dr.Field_100 = v4
	if v4 != nil {
		v4.Field_101 = dr
	}
	c.Index2D[xi][yi] = dr

	ext.Field99 = &c.Index2D[xi][yi]
}

func (c *clientDrawables) EachInRect(rect image.Rectangle, fnc func(dr *Drawable)) {
	if fnc == nil {
		return
	}
	xs := rect.Min.X / Nox_drawable_2d_div
	if xs < 0 {
		xs = 0
	}
	ys := rect.Min.Y / Nox_drawable_2d_div
	if ys < 0 {
		ys = 0
	}
	xe := rect.Max.X / Nox_drawable_2d_div
	if xe >= c.Index2DSize {
		xe = c.Index2DSize - 1
	}
	ye := rect.Max.Y / Nox_drawable_2d_div
	if ye >= c.Index2DSize {
		ye = c.Index2DSize - 1
	}
	for y := ys; y <= ye; y++ {
		for x := xs; x <= xe; x++ {
			for cur := c.Index2D[x][y]; cur != nil; cur = cur.Field100() {
				fnc(cur)
			}
		}
	}
}

type Drawable struct {
	Field_0            uint32            // 0, 0
	Field_1            uint32            // 1, 4
	Field_2            unsafe.Pointer    // 2, 8
	PosVec             image.Point       // 3, 12
	Field_5            uint32            // 5, 20
	TeamVal            server.ObjectTeam // 6, 24
	Field_8            uint32            // 8, 32
	Field_9            uint32            // 9, 36
	Field_10           uint32            // 10, 40
	Shape              server.Shape      // 11, 44
	Field_24           float32           // 24, 96
	Field_25           float32           // 25, 100
	ZVal               uint16            // 26, 104
	Field_26_1         uint16            // 26, 106
	Field_27           uint32            // 27, 108, thing ID? pointer? union?
	Flags28Val         uint32            // 28, 112
	Flags29Val         uint32            // 29, 116
	Flags30Val         uint32            // 30, 120
	Buffs              uint32            // 31, 124
	Field_32           uint32            // 32, 128, npc ID?
	Field_33           uint32            // 33, 132
	LightFlags         uint32            // 34, 136, 0
	LightIntensity     float32           // 35, 140, 1
	LightIntensityRad  uint32            // 36, 144, 2
	LightIntensityU16  uint32            // 37, 148, 3
	LightColorR        uint32            // 38, 152, 4
	LightColorG        uint32            // 39, 156, 5
	LightColorB        uint32            // 40, 160, 6
	Field_41_0         uint16            // 41, 164
	Field_41_1         uint16            // 41, 166
	Field_42           uint32            // 42, 168
	Field_43           uint32            // 43, 172
	Field_44           uint32            // 44, 176
	data_45            [5]uint32
	data_50            [10]uint32
	data_60            [5]uint32
	Field_65           uint32                                               // 65, 260
	Field_66           uint32                                               // 66, 264
	Field_67           uint32                                               // 67, 268
	Field_68           uint32                                               // 68, 272
	Field_69           uint32                                               // 69, 276
	Flags70Val         uint32                                               // 70, 280
	Field_71_0         uint8                                                // 71, 284
	Field_71_1         uint8                                                // 71, 285
	Field_71_2         uint16                                               // 71, 286
	Field_72           uint32                                               // 72, 288
	Field_73_1         uint16                                               // 73, 292
	Field_73_2         uint16                                               // 73, 294
	VelZ               int8                                                 // 74, 296
	Field_74_2         byte                                                 // 74, 297
	Field_74_3         byte                                                 // 74, 298
	Field_74_4         byte                                                 // 74, 299
	DrawFunc           ccall.Func[ObjectDrawFunc]                           // 75, 300
	Field_76           unsafe.Pointer                                       // 76, 304
	Field_77           uint32                                               // 77, 308
	Field_78           uint32                                               // 78, 312
	Field_79           uint32                                               // 79, 316
	Field_80           uint32                                               // 80, 320
	Field_81           uint32                                               // 81, 324
	Field_82           uint32                                               // 82, 328
	Field_83           *Drawable                                            // 83, 332
	Field_84           *Drawable                                            // 84, 336
	Field_85           uint32                                               // 85, 340, last draw frame number?
	Field_86           uint32                                               // 86, 344
	Field_87           *Drawable                                            // 87, 348
	Field_88           *Drawable                                            // 88, 352
	Deadline           uint32                                               // 89, 356
	Field_90           *Drawable                                            // 90, 360
	Field_91           *Drawable                                            // 91, 364
	NextPtr            *Drawable                                            // 92, 368
	Field_93           *Drawable                                            // 93, 372
	Field_94           *Drawable                                            // 94, 376
	Field_95           *Drawable                                            // 95, 380
	InClientUpdateList uint32                                               // 96, 384
	Field_97           *Drawable                                            // 97, 388
	Field_98           *Drawable                                            // 98, 392
	Field_99           **Drawable                                           // 99, 396
	Field_100          *Drawable                                            // 100, 400
	Field_101          *Drawable                                            // 101, 404
	Field_102          *Drawable                                            // 102, 408
	Field_103          *Drawable                                            // 103, 412
	Field_104          *Drawable                                            // 104, 416
	Field_105          *Drawable                                            // 105, 420
	Field_106          *Drawable                                            // 106, 424
	Field_107          *Drawable                                            // 107, 428
	Field_108_0        uint8                                                // 108, 432 // TODO: union? size = 20?
	Field_108_1        uint8                                                // 108, 433 // TODO: union?
	Field_108_2        uint16                                               // 108, 434 // TODO: union?
	Field_109          uintptr                                              // 109, 436, // TODO: union? SE?
	Field_110          uintptr                                              // 110, 440, // TODO: union? SW?
	Field_111          uintptr                                              // 111, 444, // TODO: union? SW?
	Field_112          uintptr                                              // 112, 448 // TODO: union?
	Field_113          uint32                                               // 113, 452
	Field_114          *DrawableFX                                          // 114, 456
	Field_115          ccall.Func[func(*noxrender.Viewport, *Drawable) int] // 115, 460
	ClientUpdateFunc   ccall.Func[ObjectUpdateFunc]                         // 116, 464
	Field_117          uint32                                               // 117, 468
	Field_118          uint32                                               // 118, 472
	Field_119          uint32                                               // 119, 476
	Field_120          uint32                                               // 120, 480
	Field_121          uint32                                               // 121, 484
	Field_122          uint32                                               // 122, 488
	Field_123          uint32                                               // 123, 492
	Field_124          unsafe.Pointer                                       // 124, 496
	Field_125          uint32                                               // 125, 500
	Field_126          uint32                                               // 126, 504
	Field_127          uint32                                               // 127, 508
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

func (s *Drawable) Nox_xxx_cliNextMinimapObj_459EC0(dr *Drawable) *Drawable {
	next := dr.Field_102
	if dr != nil && dr == next {
		panic("infinite loop!")
	}
	return next
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
	if s == nil {
		return nil
	}
	return &s.TeamVal
}

func (s *Drawable) HasTeam() bool {
	if s == nil {
		return false
	}
	return s.TeamVal.Has()
}

func (s *Drawable) Z() int {
	return int(s.ZVal)
}

func (s *Drawable) SetActive() { // Nox_xxx_spriteSetActiveMB_45A990_drawable
	s.Flags30Val |= 0x4
}

func (s *Drawable) HasFX(id int) bool {
	for fx := s.Field_114; fx != nil; fx = fx.Next {
		if fx.Field0 == uint32(id) {
			return true
		}
	}
	return false
}

func (s *Drawable) SetFrameMB(a2 int) { // Nox_xxx_spriteSetFrameMB_45AB80
	if s.Flags28()&0x2 == 0 || s.Flags29()&0x40000 == 0 || s.Field_69 != 8 {
		s.Field_78 = s.Field_77
		s.Field_77 = uint32(a2)
	}
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

func (s *Drawable) CallDraw(vp *noxrender.Viewport) int {
	return s.DrawFunc.Get()(vp, s)
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
	s.DrawFunc = typ.DrawFunc
	s.Field_76 = typ.Field_5c
	s.Field_77 = typ.Field_60
	s.ClientUpdateFunc = typ.ClientUpdate
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
		s.Field_108_0 = 0
		s.Field_108_1 = 0
		s.Field_108_2 = 0
		s.Field_109 = 0
		s.Field_110 = 0
		s.Field_111 = 0
		s.Field_112 = math.MaxUint32
	}
}
