package client

import (
	"image"
	"image/color"
	"math"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

// TODO: remove references to memmap

const (
	sightAngSz       = 75000
	sightAngMax      = sightAngSz - 1
	sightAngHalfSize = sightAngSz / 2

	sightAngVal1 = 6434
	sightAngVal2 = 2 * sightAngVal1
	sightAngVal3 = 3 * sightAngVal1
	sightAngVal4 = 4 * sightAngVal1

	sightPointsMax   = 1024
	sightAngTableMax = 100000
)

func sightAngleFromRad(rad float64) sightAngle {
	return sightAngle(rad*sightAngHalfSize/math.Pi + 0.5)
}

type sightAngle int32

func (v sightAngle) ConvA() int32 {
	return int32((v * sightAngVal4) / sightAngSz)
}

func (v sightAngle) Rad() float64 {
	return float64(v) * math.Pi / sightAngHalfSize
}

func (v sightAngle) Angle() float64 {
	return float64(v) * 180 / sightAngHalfSize
}

func (v sightAngle) Normalize() sightAngle {
	for v < 0 {
		v += sightAngSz
	}
	for v >= sightAngSz {
		v -= sightAngSz
	}
	return v
}

type WallChecker interface {
	GetWallAtGrid(pos image.Point) *server.Wall
	DefByInd(i int) *server.WallDef
}

func (c *Client) Nox_xxx_drawBlack_496150(vp *noxrender.Viewport) {
	c.Sight.sightReset(vp)
	c.Sight.newFromViewport(vp)
	c.sub_497260(vp)
	c.Sight.Nox_xxx_drawBlack_496150_E(vp, &c.Server.Walls, c.Server.Sub_57B500, c.DrawListAppendWallYyy)
	c.Sight.procListZzz()
	c.Sight.Nox_xxx_drawBlack_496150_F(vp, &c.Server.Walls, func() {
		if c.Debug.ShowSight {
			c.DebugSightAdd()
		}
	})
}

func (c *Client) Sub_498AE0() {
	r := c.Render()
	r.Data().SetAlphaEnabled(true)
	defer r.Data().SetAlphaEnabled(false)
	cl := noxcolor.RGB5551Color(0, 0, 0)
	r.Data().SetColor2(cl)
	c.Sight.Sub_498AE0_B(func(p1, p2 image.Point) {
		c.sub_498B50(cl, p1, p2)
	})
}

func (c *Client) sub_498B50(cl color.Color, p1, p2 image.Point) {
	r := c.Render()
	v7 := p1.Y - p2.Y
	v8 := p1.X - p2.X
	v9 := v8
	v10 := -v7
	if v8 < 0 {
		v8 = -v8
	}
	if v7 < 0 {
		v7 = -v7
	}
	var sy, sx int
	if v8 <= v7 {
		if v10 < 0 {
			sx = 1
		} else {
			sx = -1
		}
	} else {
		v11a := 0
		if v9 < 0 {
			v11a = 1
		}
		v11 := uint32(v11a - 1)
		v11 &= 0xFFFFFFFE
		sy = int(v11 + 1)
	}
	alpha := byte(208)
	cp := p1
	vpt := p2.Sub(p1)
	for i := 0; i < 10; i++ {
		r.Data().SetAlpha(alpha)
		alpha -= 20
		r.DrawVector(cp, vpt, cl)
		cp.X += sx
		cp.Y += sy
	}
}

func (c *Client) sub_497260(vp *noxrender.Viewport) {
	for dr := c.Objs.FirstList2(); dr != nil; dr = dr.Field_90 {
		dr.Field_33 = 0
		if dr.HasEnchant(server.ENCHANT_INVISIBLE) {
			continue
		}
		pos := types.Point2f(dr.Pos())
		if int8(byte(dr.Class())) >= 0 {
			switch dr.Shape.Kind {
			case server.ShapeKindCircle:
				if (pos.X-dr.Shape.Circle.R) < float32(vp.World.Min.X+vp.Size.X) && (pos.X+dr.Shape.Circle.R) > float32(vp.World.Min.X) {
					if (pos.Y-dr.Shape.Circle.R) < float32(vp.World.Min.Y+vp.Size.Y) && (pos.Y+dr.Shape.Circle.R) > float32(vp.World.Min.Y) {
						c.Sight.newFromDrawableCircle(dr)
					}
				}
			case server.ShapeKindBox:
				if (pos.X+dr.Shape.Box.LeftBottom2) < float32(vp.World.Min.X+vp.Size.X) && (pos.X+dr.Shape.Box.RightTop) > float32(vp.World.Min.X) {
					if (pos.Y+dr.Shape.Box.LeftBottom) < float32(vp.World.Min.Y+vp.Size.Y) && (pos.Y+dr.Shape.Box.RightTop2) > float32(vp.World.Min.Y) {
						c.Sight.newFromDrawableBox(dr)
					}
				}
			}
		} else {
			if (pos.X-32) < float32(vp.World.Min.X+vp.Size.X) && (pos.X+32) > float32(vp.World.Min.X) {
				if (pos.Y-32) < float32(vp.World.Min.Y+vp.Size.Y) && (pos.Y+32) > float32(vp.World.Min.Y) {
					c.Sight.newFromDrawableDoor(dr)
				}
			}
		}
	}
}

type sightObjKind byte

const (
	sightKindWall     = sightObjKind(0)
	sightKindView1    = sightObjKind(1)
	sightKindView2    = sightObjKind(2)
	sightKindView3    = sightObjKind(3)
	sightKindView4    = sightObjKind(4)
	sightKindDrDoor   = sightObjKind(6)
	sightKindDrCircle = sightObjKind(7)
	sightKindDrBox1   = sightObjKind(8)
	sightKindDrBox2   = sightObjKind(9)
	sightKindDrBox3   = sightObjKind(10)
	sightKindDrBox4   = sightObjKind(11)
	sightKindOK       = sightObjKind(12)
	sightKindDrBox5   = sightObjKind(13)
	sightKindDrBox6   = sightObjKind(14)
)

type SightObject struct {
	Field0    uint32        // 0, 0
	Field4    uint32        // 1, 4
	NextYyy8  *SightObject  // 2, 8
	NextZzz12 *SightObject  // 3, 12
	NextXxx16 *SightObject  // 4, 16
	Drawable  *Drawable     // 5, 20
	WallPos   ntype.Point32 // 6, 24
	DistSq32  int32         // 8, 32
	Field36   byte          // 9, 36
	Field37   byte          // 9, 37
	Field38   uint16        // 9, 38
	Ang40     sightAngle    // 10, 40
	Ang44     sightAngle    // 11, 44
	Field48   byte          // 12, 48
	Field49   byte          // 12, 49
	Field50   uint16        // 12, 50
	Field52   uint32        // 13, 52
	Kind56    sightObjKind  // 14, 56
	Field57   byte          // 14, 57
	Field58   uint16        // 14, 58
}

type clientSight struct {
	sightViewCenter    image.Point
	sightStructArr     []*SightObject
	sightStructArrSize int

	sightListCnt uint32
	sightListXxx *SightObject
	sightListYyy *SightObject
	sightListZzz *SightObject

	angleTable [sightAngTableMax]sightAngle

	sightPointsCnt  int
	sightPointsArr  [sightPointsMax]image.Point
	sightPointsSrc  [sightPointsMax]uint32
	sightPointsKind [sightPointsMax]sightObjKind

	arr_5d4594_1212068   [32]image.Point
	dword_5d4594_1217452 int
}

func (c *clientSight) addSightPoint(p image.Point, id uint32, kind sightObjKind) {
	ind := c.sightPointsCnt
	c.sightPointsArr[ind] = p
	c.sightPointsSrc[ind] = id
	c.sightPointsKind[ind] = kind
	c.sightPointsCnt++
}

func (c *clientSight) addSightLine(p1, p2 image.Point, id uint32, kind sightObjKind) {
	c.addSightPoint(p1, id, kind)
	c.addSightPoint(p2, id, kind)
}

func (c *clientSight) GetSightPoints() []image.Point {
	return c.sightPointsArr[:c.sightPointsCnt]
}

func (c *clientSight) Init(w, h int) {
	c.sightStructArr, _ = alloc.Make([]*SightObject{}, uintptr(w*4/common.GridStep*(h/common.GridStep)/2))
	c.initAngles()
}
func (c *clientSight) initAngles() {
	const dy = 1.0 / 1000
	for i := range c.angleTable {
		c.angleTable[i] = sightAngleFromRad(math.Atan2(float64(i)*dy, 1.0))
	}
}
func (c *clientSight) Free() {
	if c.sightStructArr != nil {
		alloc.FreeSlice(c.sightStructArr)
		c.sightStructArr = nil
	}
}

func (c *clientSight) nextListZzz() *SightObject {
	res := c.sightListZzz
	if c.sightListZzz != nil {
		c.sightListZzz = c.sightListZzz.NextZzz12
	}
	return res
}
func (c *clientSight) addListZzz(ss *SightObject) {
	ss.NextZzz12 = c.sightListZzz
	c.sightListZzz = ss
}

func (c *clientSight) sightListReset() {
	var prev *SightObject
	c.sightListXxx = nil
	for it := c.sightListYyy; it != nil; it = it.NextYyy8 {
		it.NextXxx16 = prev
		prev = it
		c.sightListXxx = it
	}
}

func (c *clientSight) listPutXxx(ss *SightObject) {
	ss.NextXxx16 = c.sightListXxx
	c.sightListXxx = ss
}

func (c *clientSight) sightReset(vp *noxrender.Viewport) {
	c.sightListReset()
	c.sightPointsCnt = 0
	c.sightStructArrSize = 0
	c.sightViewCenter.X = vp.World.Min.X + vp.Size.X/2
	c.sightViewCenter.Y = vp.World.Min.Y + vp.Size.Y/2 + vp.Jiggle12
}

func (c *clientSight) Nox_xxx_drawBlack_496150_E(vp *noxrender.Viewport, walls WallChecker, checkDoor func(pos image.Point, flags byte) int8, addWall func(w *server.Wall)) {
	v1 := int32(vp.World.Min.X)
	v2 := int32(vp.World.Min.Y)
	v3 := int32(vp.Size.X)
	v79 := v1 / common.GridStep
	v80 := v2 / common.GridStep
	v74 := (v3+v1)/common.GridStep - v1/common.GridStep
	v4 := (vp.Size.Y+int(v2))/common.GridStep - int(v2/common.GridStep)
	if v4 < 0 {
		return
	}
	for yi := 0; yi < v4+1; yi++ {
		gy := int(v80) + yi
		v70 := int32(common.GridStep * gy)
		v7 := (int32(uint8(int8(gy))) + int32(uint8(int8(v79)))) & 1
		if v7 > v74 {
			continue
		}
		for xi := 0; xi < int(v74-v7+2)/2; xi++ {
			gx := int(v7 + v79 + 2*int32(xi))
			v69 := int32(common.GridStep * gx)
			wl := walls.GetWallAtGrid(image.Pt(gx, gy))
			if wl == nil {
				continue
			}
			v10 := checkDoor(image.Pt(gx, gy), 64)
			if v10 == -1 {
				continue
			}
			def := walls.DefByInd(int(wl.Tile1))
			if def.Flags32&1 == 0 {
				wl.Flags4 |= 1
				if int(wl.Y6)*common.GridStep <= c.sightViewCenter.Y {
					wl.Flags4 &^= 2
				} else {
					wl.Flags4 |= 2
				}
				if def.Flags32&4 != 0 {
					addWall(wl)
				}
			} else {
				if wl.Flags4&0x40 != 0 {
					if (int32(c.sightViewCenter.X)-v69-11)*(int32(c.sightViewCenter.X)-v69-11)+(int32(c.sightViewCenter.Y)-v70-11)*(int32(c.sightViewCenter.Y)-v70-11) < 3600 {
						wl.Flags4 |= 1
						continue
					}
				}
				if v10 == 0 {
					c.newFromWall(gx, gy, 9)
				} else if v10 == 1 {
					c.newFromWall(gx, gy, 6)
				} else {
					v16 := memmap.Uint8(0x587000, uintptr(v10)+161764)
					if v16&2 != 0 {
						c.newFromWall(gx, gy, 2)
					}
					if v16&1 != 0 {
						c.newFromWall(gx, gy, 1)
					}
					if v16&8 != 0 {
						c.newFromWall(gx, gy, 8)
					}
					if v16&4 != 0 {
						c.newFromWall(gx, gy, 4)
					}
				}
			}
		}
	}
}

func (c *clientSight) Nox_xxx_drawBlack_496150_F(vp *noxrender.Viewport, walls WallChecker, debug func()) {
	var brect types.Rectf
	brect.Min.X = float32(c.sightViewCenter.X)
	brect.Min.Y = float32(c.sightViewCenter.Y)
	if c.sightStructArrSize > 0 {
		for i := 0; i < c.sightStructArrSize; i++ {
			id := uint32(0)
			ss := c.sightStructArr[i]
			var pp1, pp2 types.Pointf
			switch ss.Kind56 {
			case sightKindWall:
				v20 := ss.Ang40.ConvA()
				v21 := ss.Ang44.ConvA()

				brect.Max.X = float32(c.sightViewCenter.X + sub_414BD0(sightAngVal1-v20))
				brect.Max.Y = float32(c.sightViewCenter.Y + sub_414BD0(v20))
				pp1 = sub_4CA960(ss.WallPos, ss.Field36, brect)

				brect.Max.X = float32(c.sightViewCenter.X + sub_414BD0(sightAngVal1-v21))
				brect.Max.Y = float32(c.sightViewCenter.Y + sub_414BD0(v21))
				pp2 = sub_4CA960(ss.WallPos, ss.Field36, brect)

				wl := walls.GetWallAtGrid(image.Pt(int(ss.WallPos.X), int(ss.WallPos.Y)))
				wl.Field12 = 1
				wl.Flags4 |= 1
				if pp2.X < pp1.X {
					wl.Flags4 |= 2
				}
				wl.Field3 |= ss.Field36
				id = uint32(ss.WallPos.X)&0xffff + ((uint32(ss.WallPos.Y) & 0xffff) << 8)
			case sightKindView1:
				pp1.X = float32(c.sightViewCenter.X + sub_414C50(ss.Ang40.ConvA()-sightAngVal3)*(vp.Size.Y/2)/4096)
				pp1.Y = float32(vp.World.Min.Y)
				pp2.X = float32(c.sightViewCenter.X + sub_414C50(ss.Ang44.ConvA()-sightAngVal3)*(vp.Size.Y/2)/4096)
				pp2.Y = float32(vp.World.Min.Y)
				id = 0
			case sightKindView2:
				pp1.X = float32(c.sightViewCenter.X - sub_414C50(ss.Ang40.ConvA()-sightAngVal1)*(vp.Size.Y/2)/4096)
				pp1.Y = float32(vp.World.Min.Y + vp.Size.Y - 1)
				pp2.X = float32(c.sightViewCenter.X - sub_414C50(ss.Ang44.ConvA()-sightAngVal1)*(vp.Size.Y/2)/4096)
				pp2.Y = float32(vp.World.Min.Y + vp.Size.Y - 1)
				id = 0
			case sightKindView3:
				pp1.X = float32(vp.World.Min.X)
				pp1.Y = float32(c.sightViewCenter.Y - sub_414C50(ss.Ang40.ConvA()-sightAngVal2)*(vp.Size.X/2)/4096)
				pp2.X = float32(vp.World.Min.X)
				pp2.Y = float32(c.sightViewCenter.Y - sub_414C50(ss.Ang44.ConvA()-sightAngVal2)*(vp.Size.X/2)/4096)
				id = 0
			case sightKindView4:
				pp1.X = float32(vp.Size.X + vp.World.Min.X - 1)
				pp1.Y = float32(c.sightViewCenter.Y + sub_414C50(ss.Ang40.ConvA()-0)*(vp.Size.X/2)/4096)
				pp2.X = float32(vp.World.Min.X + vp.Size.X - 1)
				pp2.Y = float32(c.sightViewCenter.Y + sub_414C50(ss.Ang44.ConvA()-0)*(vp.Size.X/2)/4096)
				id = 0
			case sightKindDrDoor:
				dr := ss.Drawable
				dr.Field_33 = 1
				var rect types.Rectf
				rect.Min.X = float32(float64(dr.PosVec.X))
				rect.Min.Y = float32(float64(dr.PosVec.Y))
				rect.Max.X = float32(float64(dr.PosVec.X + int(memmap.Int32(0x587000, uintptr(int32(dr.Field_74_4)*8)+196184))))
				rect.Max.Y = float32(float64(dr.PosVec.Y + int(memmap.Int32(0x587000, uintptr(int32(dr.Field_74_4)*8)+196188))))
				v36 := ss.Ang40.ConvA()
				brect.Max.X = float32(c.sightViewCenter.X + sub_414BD0(sightAngVal1-v36))
				brect.Max.Y = float32(c.sightViewCenter.Y + sub_414BD0(v36))
				var ok bool
				pp1, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp1 = rect.Min
				}
				v37 := ss.Ang44.ConvA()
				brect.Max.X = float32(c.sightViewCenter.X + sub_414BD0(sightAngVal1-v37))
				brect.Max.Y = float32(c.sightViewCenter.Y + sub_414BD0(v37))
				pp2, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp2 = rect.Max
				}
				id = dr.Field_32
			case sightKindDrCircle:
				dr := ss.Drawable
				dr.Field_33 = 1
				v39 := c.sightViewCenter.X - dr.PosVec.X
				v40 := -(c.sightViewCenter.Y - dr.PosVec.Y)
				var rect types.Rectf
				rect.Min.X = float32(v40 + dr.PosVec.X)
				rect.Min.Y = float32(v39 + dr.PosVec.Y)
				rect.Max.X = float32(dr.PosVec.X - v40)
				rect.Max.Y = float32(dr.PosVec.Y - v39)
				v41 := ss.Ang40.ConvA()
				brect.Max.X = float32(c.sightViewCenter.X + sub_414BD0(sightAngVal1-v41))
				brect.Max.Y = float32(c.sightViewCenter.Y + sub_414BD0(v41))
				var ok bool
				pp1, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp1 = types.Ptf(rect.Min.X, rect.Min.Y)
				}
				v42 := ss.Ang44.ConvA()
				brect.Max.X = float32(c.sightViewCenter.X + sub_414BD0(sightAngVal1-v42))
				brect.Max.Y = float32(c.sightViewCenter.Y + sub_414BD0(v42))
				pp2, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp2 = rect.Max
				}
				id = dr.Field_32
			case sightKindDrBox1, sightKindDrBox2, sightKindDrBox3, sightKindDrBox4, sightKindDrBox5, sightKindDrBox6:
				dr := ss.Drawable
				dr.Field_33 = 1
				var rect types.Rectf
				switch ss.Kind56 {
				case sightKindDrBox1:
					rect.Min.X = float32(dr.PosVec.X) + dr.Shape.Box.LeftTop
					rect.Min.Y = float32(dr.PosVec.Y) + dr.Shape.Box.LeftBottom
					rect.Max.X = float32(dr.PosVec.X) + dr.Shape.Box.LeftBottom2
					rect.Max.Y = float32(dr.PosVec.Y) + dr.Shape.Box.LeftTop2
				case sightKindDrBox2:
					rect.Min.X = float32(dr.PosVec.X) + dr.Shape.Box.LeftTop
					rect.Min.Y = float32(dr.PosVec.Y) + dr.Shape.Box.LeftBottom
					rect.Max.X = float32(dr.PosVec.X) + dr.Shape.Box.RightTop
					rect.Max.Y = float32(dr.PosVec.Y) + dr.Shape.Box.RightBottom
				case sightKindDrBox3:
					rect.Min.X = float32(dr.PosVec.X) + dr.Shape.Box.RightBottom2
					rect.Min.Y = float32(dr.PosVec.Y) + dr.Shape.Box.RightTop2
					rect.Max.X = float32(dr.PosVec.X) + dr.Shape.Box.LeftBottom2
					rect.Max.Y = float32(dr.PosVec.Y) + dr.Shape.Box.LeftTop2
				case sightKindDrBox4:
					rect.Min.X = float32(dr.PosVec.X) + dr.Shape.Box.RightBottom2
					rect.Min.Y = float32(dr.PosVec.Y) + dr.Shape.Box.RightTop2
					rect.Max.X = float32(dr.PosVec.X) + dr.Shape.Box.RightTop
					rect.Max.Y = float32(dr.PosVec.Y) + dr.Shape.Box.RightBottom
				case sightKindDrBox5:
					rect.Min.X = float32(dr.PosVec.X) + dr.Shape.Box.LeftTop
					rect.Min.Y = float32(dr.PosVec.Y) + dr.Shape.Box.LeftBottom
					rect.Max.X = float32(dr.PosVec.X) + dr.Shape.Box.RightBottom2
					rect.Max.Y = float32(dr.PosVec.Y) + dr.Shape.Box.RightTop2
				case sightKindDrBox6:
					rect.Min.X = float32(dr.PosVec.X) + dr.Shape.Box.LeftBottom2
					rect.Min.Y = float32(dr.PosVec.Y) + dr.Shape.Box.LeftTop2
					rect.Max.X = float32(dr.PosVec.X) + dr.Shape.Box.RightTop
					rect.Max.Y = float32(dr.PosVec.Y) + dr.Shape.Box.RightBottom
				}
				v45 := ss.Ang40.ConvA()
				brect.Max.X = float32(c.sightViewCenter.X + sub_414BD0(sightAngVal1-v45))
				brect.Max.Y = float32(c.sightViewCenter.Y + sub_414BD0(v45))
				var ok bool
				pp1, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp1 = rect.Min
				}
				v46 := ss.Ang44.ConvA()
				brect.Max.X = float32(c.sightViewCenter.X + sub_414BD0(sightAngVal1-v46))
				brect.Max.Y = float32(c.sightViewCenter.Y + sub_414BD0(v46))
				pp2, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp2 = rect.Max
				}
				id = dr.Field_32
			}
			sp1 := vp.Screen.Min.Add(pp1.Point().Sub(vp.World.Min))
			sp2 := vp.Screen.Min.Add(pp2.Point().Sub(vp.World.Min))
			if sub_57BA30(&sp1, &sp2, vp.Screen) != 0 {
				c.addSightLine(sp1, sp2, id, ss.Kind56)
			}
		}
	}
	debug()
	c.sightPointsCnt--
	pi := c.sightPointsCnt - 1
	for i := 0; i < c.sightPointsCnt; pi, i = i, i+1 {
		kind1 := c.sightPointsKind[pi]
		var adx, ady int
		if kind1 != sightKindWall {
			kind2 := c.sightPointsKind[i]
			if kind2 == sightKindWall {
				if kind1 == sightKindDrDoor || c.sightPointsKind[i] == sightKindDrDoor {
					v63 := c.sightPointsArr[pi].X
					var v64 int
					if c.sightPointsArr[i].X-v63 >= 0 {
						v64 = c.sightPointsArr[i].X - v63
					} else {
						v64 = v63 - c.sightPointsArr[i].X
					}
					v65 := c.sightPointsArr[pi].Y
					var v66 int
					if c.sightPointsArr[i].Y-v65 >= 0 {
						v66 = c.sightPointsArr[i].Y - v65
					} else {
						v66 = v65 - c.sightPointsArr[i].Y
					}
					if v64 <= 4 && v66 <= 4 {
						continue
					}
				}
				c.sightPointsKind[pi] = sightKindOK
				continue
			}
			if kind2 != kind1 {
				c.sightPointsKind[pi] = sightKindOK
				continue
			}
			if c.sightPointsSrc[i] == c.sightPointsSrc[pi] {
				continue
			}
			v57 := c.sightPointsArr[pi].X
			v58 := c.sightPointsArr[i].X - v57
			if v58 < 0 {
				adx = v57 - c.sightPointsArr[i].X
			} else {
				adx = v58
			}
		} else {
			if c.sightPointsKind[i] != sightKindWall {
				if kind1 == sightKindDrDoor || c.sightPointsKind[i] == sightKindDrDoor {
					v63 := c.sightPointsArr[pi].X
					var v64 int
					if c.sightPointsArr[i].X-v63 >= 0 {
						v64 = c.sightPointsArr[i].X - v63
					} else {
						v64 = v63 - c.sightPointsArr[i].X
					}
					v65 := c.sightPointsArr[pi].Y
					var v66 int
					if c.sightPointsArr[i].Y-v65 >= 0 {
						v66 = c.sightPointsArr[i].Y - v65
					} else {
						v66 = v65 - c.sightPointsArr[i].Y
					}
					if v64 <= 4 && v66 <= 4 {
						continue
					}
				}
				c.sightPointsKind[pi] = sightKindOK
				continue
			}
			if c.sightPointsSrc[pi] == c.sightPointsSrc[i] {
				continue
			}
			if xx1, xx2 := c.sightPointsArr[i].X, c.sightPointsArr[pi].X; xx1-xx2 < 0 {
				adx = xx2 - xx1
			} else {
				adx = xx1 - xx2
			}
		}
		if yy1, yy2 := c.sightPointsArr[i].Y, c.sightPointsArr[pi].Y; yy1-yy2 < 0 {
			ady = yy2 - yy1
		} else {
			ady = yy1 - yy2
		}
		if adx > 4 || ady > 4 {
			c.sightPointsKind[pi] = sightKindOK
		}
	}
}

func (c *clientSight) checkXxx(r image.Rectangle) bool {
	prev := c.sightPointsArr[c.sightPointsCnt-1]
	for i := 0; i < c.sightPointsCnt; i++ {
		p := c.sightPointsArr[i]
		var r2 image.Rectangle
		r2.Min = prev
		r2.Max = p
		if sub_427C80(r, r2) {
			return true
		}
		prev = p
	}
	return false
}

func (c *clientSight) Nox_xxx_client_4984B0_drawable_A(vp *noxrender.Viewport, dr *Drawable) bool {
	if dr.DrawFuncPtr == nil {
		return false
	}
	var pos image.Point
	if int8(byte(dr.Class())) >= 0 {
		pos = dr.PosVec
	} else {
		if (dr.SubClass() & 4) == 0 {
			return dr.Field_33 != 0
		}
		ind := int32(dr.Field_74_4)
		pos = dr.PosVec.Add(image.Point{
			X: int(memmap.Int32(0x587000, 8*uintptr(ind)+196184) / 2),
			Y: int(memmap.Int32(0x587000, 8*uintptr(ind)+196188) / 2),
		})
	}
	if dr.Flags().Has(object.FlagShadow) {
		return dr.Field_33 != 0
	}
	opos := vp.World.Min.Sub(vp.Screen.Min)
	opos2 := opos
	dx := pos.X - opos.X
	var r1 image.Rectangle
	r1.Min.X = vp.Screen.Min.X + vp.Size.X/2
	r1.Min.Y = vp.Screen.Min.Y + vp.Jiggle12 + vp.Size.Y/2
	r1.Max.X = pos.X - opos.X
	r1.Max.Y = pos.Y - opos.Y
	if c.sightPointsCnt <= 0 {
		return true
	}
	if !c.checkXxx(r1) {
		return true
	}
	var vec1, vec2 image.Point
	if dr.Shape.Kind == 2 {
		v12 := int(dr.Shape.Circle.R)
		if *(*uint16)(unsafe.Add(dr.C(), 2)) != 0 {
			v35 := int(*(*uint16)(unsafe.Add(dr.C(), 6)))
			vec1.X = pos.X - (int(*(*uint16)(unsafe.Add(dr.C(), 4))) >> 1) - opos.X
			vec1.Y = pos.Y + v12 + int(dr.ZVal) - v35 - opos.Y - int(dr.ZSizeMin)
			vec2.X = vec1.X + int(*(*uint16)(unsafe.Add(dr.C(), 4)))
			vec2.Y = vec1.Y + v35
		} else {
			vec1.X = pos.X - v12 - opos.X
			vec1.Y = pos.Y - v12 - opos.Y - int(dr.ZSizeMax)
			vec2.X = pos.X + v12 - opos2.X
			vec2.Y = pos.Y + v12 + int(dr.ZVal) - opos2.Y - int(dr.ZSizeMin)
		}
	} else {
		if *(*uint16)(unsafe.Add(dr.C(), 2)) != 0 {
			vec1.X = pos.X - (int(*(*uint16)(unsafe.Add(dr.C(), 4))) >> 1) - opos.X
			vec2.Y = int(dr.Shape.Box.RightTop2) + pos.Y + int(dr.ZVal) - opos.Y
			vec1.Y = vec2.Y - int(*(*uint16)(unsafe.Add(dr.C(), 6)))
			vec2.X = vec1.X + int(*(*uint16)(unsafe.Add(dr.C(), 4)))
		} else {
			vec1.X = dx + int(dr.Shape.Box.LeftBottom2)
			v17 := pos.Y - opos.Y - int(dr.ZSizeMax)
			vec1.Y = int(dr.Shape.Box.LeftBottom) + v17
			vec2.X = dx + int(dr.Shape.Box.RightTop)
			vec2.Y = int(dr.Shape.Box.RightTop2) + pos.Y + int(dr.ZVal) - opos2.Y
		}
	}
	scrOut := 0
	scrIn := 0
	vec3 := vec1
	vec4 := vec2
	if vec1.X < vp.Screen.Min.X || vec1.X > vp.Screen.Max.X {
		scrOut = 1
	} else {
		scrIn = 1
	}
	if vec1.Y < vp.Screen.Min.Y || vec1.Y > vp.Screen.Max.Y {
		scrOut++
	} else {
		scrIn++
	}
	if vec2.X < vp.Screen.Min.X || vec2.X > vp.Screen.Max.X {
		scrOut++
	} else {
		scrIn++
	}
	if vec2.Y < vp.Screen.Min.Y || vec2.Y > vp.Screen.Max.Y {
		scrOut++
	} else {
		scrIn++
	}
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(dr), 2))) != 0 {
		if vec2.X-vec1.X > 6 {
			vec1.X += 3
			vec2.X -= 3
		}
		if vec2.Y-vec1.Y >= 22 {
			vec1.Y += 11
			vec2.Y -= 11
		}
	}
	if scrIn == 0 || scrOut == 0 {
		return false
	}
	var r2 image.Rectangle
	r2.Min = r1.Min
	if vec3.X < vp.Screen.Min.X {
		r1.Max.X = vec2.X
		r1.Max.Y = vec1.Y
		r2.Max.X = vec2.X
		r2.Max.Y = vec2.Y
	} else if vec4.X > vp.Screen.Max.X {
		r1.Max.X = vec1.X
		r1.Max.Y = vec1.Y
		r2.Max.X = vec1.X
		r2.Max.Y = vec2.Y
	}
	if vec3.Y < vp.Screen.Min.Y {
		r1.Max.X = vec1.X
		r1.Max.Y = vec2.Y
		r2.Max.X = vec2.X
		r2.Max.Y = vec2.Y
	} else if vec4.Y > vp.Screen.Max.Y {
		r1.Max.X = vec1.X
		r1.Max.Y = vec1.Y
		r2.Max.X = vec2.X
		r2.Max.Y = vec1.Y
	}
	if c.checkXxx(r1) || c.checkXxx(r2) {
		return false
	}
	return true
}

func (c *clientSight) Sub_498AE0_B(draw func(p1, p2 image.Point)) {
	v1 := 0
	v0 := c.sightPointsCnt
	for i := c.sightPointsCnt - 1; v1 < v0; v1++ {
		if c.sightPointsKind[i] == sightKindOK {
			draw(c.sightPointsArr[i], c.sightPointsArr[v1])
			v0 = c.sightPointsCnt
		}
		i = v1
	}
}

func (c *clientSight) Sub_498C20(a1p *image.Point, a2p *image.Point, a3 int32) int32 {
	if a1p == nil || a2p == nil {
		return 0
	}
	if a3 == 0 {
		return 0
	}
	var (
		v27 float32
		v29 float32
		v31 int
		a1a image.Point
	)
	a1 := *a1p
	v3 := a1
	a2 := *a2p
	v4 := a2
	c.dword_5d4594_1217452 = 0
	v5 := sub_4990D0(a1, a2)
	v6 := v5
	v37 := v5
	if v5 == 0 {
		return 0
	}
	if v5 != 4 && v5 != 8 {
		v29 = float32(float64(a2.Y-v3.Y) / float64(a2.X-v3.X))
		v27 = float32(float64(v3.X) * float64(v29))
		v31 = v3.Y - int(v27)
	}
	v7 := c.sightPointsCnt
	if c.sightPointsCnt > 0 {
		for v32 := 0; ; {
			a2a := c.sightPointsArr[v32]
			var a3a image.Point
			if v32 == v7-1 {
				a3a = c.sightPointsArr[0]
			} else {
				a3a = c.sightPointsArr[v32+1]
			}
			v38 := sub_4990D0(a2a, a3a)
			if v38 != 0 && (v6&1 == 0 || a2a.X <= v3.X || a2a.X <= v4.X || a3a.X <= v3.X || a3a.X <= v4.X) && (v37&2 == 0 || a2a.X >= v3.X || a2a.X >= v4.X || a3a.X >= v3.X) {
				if v37&4 == 0 || a2a.Y <= v3.Y || a2a.Y <= a2.Y || a3a.Y <= v3.Y || a3a.Y <= a2.Y {
					if v37&8 == 0 || a2a.Y >= v3.Y || a2a.Y >= a2.Y || a3a.Y >= v3.Y || a3a.Y >= a2.Y {
						if a2a.X == a3a.X {
							if v37 == 4 || v37 == 8 {
								goto LABEL_65
							}
							if v37 != 1 && v37 != 2 {
								a1a.X = a2a.X
								v26 := float32(float64(a2a.X) * float64(v29))
								a1a.Y = v31 + int(v26)
								if sub_499160(a1a, a2a, a3a) && sub_499160(a1a, v3, a2) {
									c.sub_499130(a1a)
								}
								goto LABEL_65
							}
							a1a.Y = v3.X
							a1a.X = a2a.X
							if sub_499160(a1a, a2a, a3a) && sub_499160(a1a, v3, a2) {
								c.sub_499130(a1a)
								goto LABEL_65
							}
						} else {
							v28 := float32(float64(a3a.Y-a2a.Y) / float64(a3a.X-a2a.X))
							v21 := float32(float64(a2a.X) * float64(v28))
							v15 := int(v21)
							v16 := a2a.Y - v15
							if v37 == 4 || v37 == 8 {
								if v38 == 1 || v38 == 2 {
									a1a.X = v3.X
									a1a.Y = a2a.X
									if sub_499160(a1a, a2a, a3a) && sub_499160(a1a, v3, a2) {
										c.sub_499130(a1a)
									}
								} else {
									a1a.X = v3.X
									v22 := float32(float64(a1a.X) * float64(v28))
									a1a.Y = v16 + int(v22)
									if sub_499160(a1a, a2a, a3a) && sub_499160(a1a, v3, a2) {
										c.sub_499130(a1a)
									}
								}
							}
							if v37 == 1 || v37 == 2 {
								if v38 == 1 || v38 == 2 {
									goto LABEL_65
								}
								v25 := float32(float64(v31-v16) / float64(v28))
								v17 := int(v25)
								v18 := v3.Y
								a1a.X = v17
								a1a.Y = v18
								if sub_499160(a1a, a2a, a3a) && sub_499160(a1a, v3, a2) {
									c.sub_499130(a1a)
								}
								goto LABEL_65
							}
							if v29 != v28 {
								v39 := float32(float64(v31 - v16))
								v30 := v28 - v29
								v23 := v39 / v30
								a1a.X = int(v23)
								v24 := v39 * v28 / v30
								a1a.Y = v16 + int(v24)
								if sub_499160(a1a, a2a, a3a) && sub_499160(a1a, v3, a2) {
									c.sub_499130(a1a)
									goto LABEL_65
								}
							}
						}
					}
				}
			}
		LABEL_65:
			v7 = c.sightPointsCnt
			v32++
			if v32 >= c.sightPointsCnt {
				break
			}
			v6 = v37
			v4 = a2
		}
	}
	c.sub_4991E0(v3)
	return int32(c.dword_5d4594_1217452)
}

func (c *clientSight) Sub_4992B0(a1 int, a2 int) int {
	result := 0
	v7 := 0
	v8 := 0
	if c.sightPointsCnt <= 0 {
		return 0
	}
	v3 := (c.sightPointsCnt - 1) * 8
	for v8 < c.sightPointsCnt {
		v4 := c.sightPointsArr[v3/8].X
		v5 := c.sightPointsArr[v3/8].Y
		v6 := c.sightPointsArr[v8].Y
		if v6 > a2 {
			if v5 > a2 {
				v3 = func() int {
					p := &v8
					x := *p
					*p++
					return x
				}() * 8
				continue
			}
		} else if a2 < v5 {
			goto LABEL_8
		}
		if a2 >= v6 {
			v3 = func() int {
				p := &v8
				x := *p
				*p++
				return x
			}() * 8
			continue
		}
	LABEL_8:
		if a1 >= c.sightPointsArr[v8].X+(a2-v6)*(v4-c.sightPointsArr[v8].X)/(v5-v6) {
			result = v7
		} else {
			if v7 == 0 {
				v7 = 1
			} else {
				v7 = 0
			}
			result = v7
		}
		v3 = func() int {
			p := &v8
			x := *p
			*p++
			return x
		}() * 8
	}
	return result
}

func (c *clientSight) sightArrInsertAt(ss *SightObject, i int) {
	if i < c.sightStructArrSize {
		copy(c.sightStructArr[i+1:], c.sightStructArr[i:c.sightStructArrSize])
	}
	c.sightStructArr[i] = ss
	c.sightStructArrSize++
}
func (c *clientSight) sightArrRemoveAt(i int) {
	copy(c.sightStructArr[i:], c.sightStructArr[i+1:c.sightStructArrSize])
	c.sightStructArrSize--
}
func (c *clientSight) sightArrFind(ss *SightObject) int {
	i := 0
	j := c.sightStructArrSize - 1
	for {
		ind := (j + i) / 2
		ss2 := c.sightStructArr[ind]
		if ss2.Ang40 == ss.Ang40 {
			return ind
		}
		if ss2.Ang40 >= ss.Ang40 {
			j = (j + i) / 2
		} else {
			i = ind + 1
		}
		if i > j {
			panic(-1)
		}
	}
}
func (c *clientSight) sightArrFindFirst(ss *SightObject) int {
	i := 0
	j := c.sightStructArrSize - 1
	if c.sightStructArrSize-1 < 0 {
		return 0
	}
	for {
		ind := (j + i) / 2
		ss2 := c.sightStructArr[ind]
		if ss2.Ang44 >= ss.Ang40 {
			j = ind - 1
		} else {
			i = ind + 1
		}
		if i > j {
			if j >= 0 {
				return j
			} else {
				return 0
			}
		}
	}
}
func (c *clientSight) sightArrFindInsert(ss *SightObject) int {
	i := 0
	j := c.sightStructArrSize - 1
	for i <= j {
		ind := (j + i) / 2
		ss2 := c.sightStructArr[ind]
		if ss2.Ang40 >= ss.Ang40 {
			j = ind - 1
		} else {
			i = ind + 1
		}
	}
	return i
}
func (c *clientSight) sightArrInsert(ss *SightObject) {
	i := c.sightArrFindInsert(ss)
	c.sightArrInsertAt(ss, i)
}
func (c *clientSight) sightArrRemove(ss *SightObject) int {
	i := c.sightArrFind(ss)
	c.sightArrRemoveAt(i)
	return i
}

func (c *clientSight) procListZzz() {
	for it := c.nextListZzz(); it != nil; it = c.nextListZzz() {
		c.procZzz(it)
	}
}
func (c *clientSight) procZzz(ss *SightObject) {
	for i := c.sightArrFindFirst(ss); i < c.sightStructArrSize; i++ {
		ss2 := c.sightStructArr[i]
		if ss2.Ang40 > ss.Ang44 {
			break
		}
		c.sub_498380(ss, c.sightStructArr[i])
		if ss.Field48 == 0 || ss.Ang44-ss.Ang40 < 0 {
			c.listPutXxx(ss)
			return
		}
		if ss2.Field48 == 0 || ss2.Ang44-ss2.Ang40 < 0 {
			if c.sightArrRemove(ss2) <= i {
				i--
			}
			c.listPutXxx(ss2)
		}
	}
	c.sightArrInsert(ss)
}

func (c *clientSight) newStruct() *SightObject {
	ss := c.sightListXxx
	if c.sightListXxx == nil {
		const batch = 10
		for i := 0; i < batch; i++ {
			p, _ := alloc.New(SightObject{})
			p.NextXxx16 = c.sightListXxx
			c.sightListXxx = p
			p.NextYyy8 = c.sightListYyy
			c.sightListYyy = p
		}
		c.sightListCnt += batch
		ss = c.sightListXxx
	}
	c.sightListXxx = ss.NextXxx16
	return ss
}

func (c *clientSight) copyStruct(ss *SightObject) *SightObject {
	ss2 := c.newStruct()
	ss2.WallPos = ss.WallPos
	ss2.DistSq32 = ss.DistSq32
	ss2.Field36 = ss.Field36
	ss2.Ang40 = ss.Ang40
	ss2.Ang44 = ss.Ang44
	ss2.Field48 = ss.Field48
	ss2.Kind56 = ss.Kind56
	ss2.Drawable = ss.Drawable
	return ss2
}

func (c *clientSight) newFromWall(gx, gy int, typ byte) {
	x := gx * common.GridStep
	y := gy * common.GridStep
	cx := x + 11
	cy := y + 11
	ss := c.newStruct()
	ss.WallPos.X = int32(gx)
	ss.WallPos.Y = int32(gy)
	ss.Field36 = typ
	ss.Field48 = 1
	ss.Kind56 = sightKindWall
	var dx, dy, v8, v9, v23 int
	switch typ {
	case 1:
		dx = cx - c.sightViewCenter.X + 5
		dy = cy - c.sightViewCenter.Y - 5
		v8 = cx
		v9 = gy * common.GridStep
		v23 = x + common.GridStep
	case 2:
		dx = cx - c.sightViewCenter.X - 5
		dy = cy - c.sightViewCenter.Y - 5
		v8 = cx
		v9 = gy * common.GridStep
		v23 = gx * common.GridStep
	case 4:
		dx = cx - c.sightViewCenter.X + 5
		v8 = cx
		dy = cy - c.sightViewCenter.Y + 5
		v23 = x + common.GridStep
		v9 = y + common.GridStep
	case 6:
		v8 = gx * common.GridStep
		dy = cy - c.sightViewCenter.Y
		cy = gy * common.GridStep
		dx = cx - c.sightViewCenter.X
		v23 = x + common.GridStep
		v9 = y + common.GridStep
	case 8:
		dx = cx - c.sightViewCenter.X - 5
		v23 = gx * common.GridStep
		dy = cy - c.sightViewCenter.Y + 5
		v8 = cx
		v9 = y + common.GridStep
	case 9:
		dx = cx - c.sightViewCenter.X
		dy = cy - c.sightViewCenter.Y
		cy = gy * common.GridStep
		v8 = x + common.GridStep
		v23 = gx * common.GridStep
		v9 = y + common.GridStep
	}
	ss.DistSq32 = int32(dx*dx + dy*dy)
	ss.Ang40 = c.sub_4CA8B0(int32(cy)-int32(c.sightViewCenter.Y), int32(v8)-int32(c.sightViewCenter.X))
	ss.Ang40 = ss.Ang40.Normalize()
	ss.Ang44 = c.sub_4CA8B0(int32(v9)-int32(c.sightViewCenter.Y), int32(v23)-int32(c.sightViewCenter.X))
	ss.Ang44 = ss.Ang44.Normalize()
	v17 := ss.Ang44
	v18 := ss.Ang40
	if v17 < v18 {
		ss.Ang40 = v17
		ss.Ang44 = v18
	}
	if ss.Ang44-ss.Ang40 < sightAngHalfSize {
		c.addListZzz(ss)
		return
	}
	ss2 := c.copyStruct(ss)
	ss2.Ang40 = 0
	ss2.Ang44 = ss.Ang40
	ss.Ang40 = ss.Ang44
	ss.Ang44 = sightAngMax
	c.addListZzz(ss2)
	c.addListZzz(ss)
}
func (c *clientSight) newFromDrawableDoor(dr *Drawable) {
	if dr.SubClass()&4 != 0 {
		return
	}
	ss := c.newStruct()
	ss.Field48 = 1
	ss.Kind56 = sightKindDrDoor
	ss.Drawable = dr
	v3 := int32(dr.Field_74_4) * 8
	v4 := float64(int32(c.sightViewCenter.X) - memmap.Int32(0x587000, uintptr(v3)+196184)/2 - int32(dr.PosVec.X))
	v15 := int32(c.sightViewCenter.Y) - memmap.Int32(0x587000, uintptr(v3)+196188)/2 - int32(dr.PosVec.Y)
	v14 := float32(float64(v15)*float64(v15) + v4*v4)
	ss.DistSq32 = int32(v14)
	ss.Ang40 = c.sub_4CA8B0(int32(dr.PosVec.Y-c.sightViewCenter.Y), int32(dr.PosVec.X-c.sightViewCenter.X))
	ss.Ang40 = ss.Ang40.Normalize()
	ss.Ang44 = c.sub_4CA8B0(int32(dr.PosVec.Y+int(memmap.Int32(0x587000, uintptr(int32(dr.Field_74_4)*8)+196188))-c.sightViewCenter.Y), int32(dr.PosVec.X+int(memmap.Int32(0x587000, uintptr(int32(dr.Field_74_4)*8)+196184))-c.sightViewCenter.X))
	ss.Ang44 = ss.Ang44.Normalize()
	v11 := ss.Ang44
	v12 := ss.Ang40
	if v11 < v12 {
		ss.Ang40 = v11
		ss.Ang44 = v12
	}
	if ss.Ang44-ss.Ang40 >= sightAngHalfSize {
		ss2 := c.copyStruct(ss)
		ss2.Ang40 = 0
		ss2.Ang44 = ss.Ang40
		ss.Ang40 = ss.Ang44
		ss.Ang44 = sightAngMax
		c.addListZzz(ss2)
	}
	c.addListZzz(ss)
}
func (c *clientSight) newFromDrawableCircle(dr *Drawable) {
	ss := c.newStruct()
	v2 := dr
	ss.Field48 = 1
	ss.Kind56 = sightKindDrCircle
	ss.Drawable = dr
	v4 := int32(dr.PosVec.Y)
	v24 := float32(float64(int32(dr.PosVec.X - c.sightViewCenter.X)))
	v5 := float64(int32(int(v4) - c.sightViewCenter.Y))
	v23 := float32(v5)
	v21 := float32(v5*float64(v23) + float64(v24*v24))
	v6 := int32(v21)
	ss.DistSq32 = v6
	v7 := int32(int64(math.Sqrt(float64(v6))))
	v22 := int32(v24)
	v8 := int32(v23)
	v9 := c.sub_4CA8B0(v8, v22)
	v10 := int32(v2.Shape.Circle.R)
	v11 := c.sub_4CA8B0(v10, v7)
	ss.Ang40 = (v11 + v9).Normalize()
	ss.Ang44 = (v9 - v11).Normalize()
	v17 := ss.Ang44
	v18 := ss.Ang40
	if v17 < v18 {
		ss.Ang40 = v17
		ss.Ang44 = v18
	}
	if ss.Ang44-ss.Ang40 < sightAngHalfSize {
		c.addListZzz(ss)
		return
	}
	ss2 := c.copyStruct(ss)
	ss2.Ang40 = 0
	ss2.Ang44 = ss.Ang40
	ss.Ang40 = ss.Ang44
	ss.Ang44 = sightAngMax
	c.addListZzz(ss2)
	c.addListZzz(ss)
}
func (c *clientSight) newFromDrawableBox(a1 *Drawable) {
	var (
		v38 [8]float32
		v39 float32
	)
	v1 := a1
	v2 := float64(a1.PosVec.X)
	v38[0] = float32(v2 + float64(a1.Shape.Box.LeftTop))
	v3 := float64(a1.PosVec.Y)
	v39 = float32(v3)
	v38[1] = float32(v3 + float64(v1.Shape.Box.LeftBottom))
	v38[2] = float32(v2 + float64(v1.Shape.Box.LeftBottom2))
	v38[3] = v39 + v1.Shape.Box.LeftTop2
	v38[4] = float32(v2 + float64(v1.Shape.Box.RightTop))
	v38[5] = v39 + v1.Shape.Box.RightBottom
	v38[6] = float32(v2 + float64(v1.Shape.Box.RightBottom2))
	v38[7] = v39 + v1.Shape.Box.RightTop2
	v30 := int32(v38[0]) - int32(c.sightViewCenter.X)
	v4 := int32(v38[1])
	v5 := c.sub_4CA8B0(v4-int32(c.sightViewCenter.Y), v30)
	v31 := int32(v38[2]) - int32(c.sightViewCenter.X)
	v6 := int32(v38[3])
	v7 := c.sub_4CA8B0(v6-int32(c.sightViewCenter.Y), v31)
	v32 := int32(v38[4]) - int32(c.sightViewCenter.X)
	v8 := int32(v38[5])
	v9 := c.sub_4CA8B0(v8-int32(c.sightViewCenter.Y), v32)
	v33 := int32(v38[6]) - int32(c.sightViewCenter.X)
	v10 := int32(v38[7])
	v40 := c.sub_4CA8B0(v10-int32(c.sightViewCenter.Y), v33)
	result := sub_497B80(&v38, c.sightViewCenter) - 1
	switch result {
	case 0:
		v35 := float32(float64(v38[5]+v38[1]) * 0.5)
		v14 := float64(v38[4]+v38[0])*0.5 - float64(c.sightViewCenter.X)
		v25 := float32((float64(v35)-float64(c.sightViewCenter.Y))*(float64(v35)-float64(c.sightViewCenter.Y)) + v14*v14)
		v15 := int32(v25)
		c.newFromDrawableBoxSub(v5, v9, sightKindDrBox2, v15, v1)
	case 1:
		v37 := float32(float64(v38[7]+v38[3]) * 0.5)
		v18 := float64(v38[6]+v38[2])*0.5 - float64(c.sightViewCenter.X)
		v27 := float32((float64(v37)-float64(c.sightViewCenter.Y))*(float64(v37)-float64(c.sightViewCenter.Y)) + v18*v18)
		v19 := int32(v27)
		c.newFromDrawableBoxSub(v40, v7, sightKindDrBox3, v19, v1)
	case 3:
		v34 := float32(float64(v38[3]+v38[1]) * 0.5)
		v12 := float64(v38[2]+v38[0])*0.5 - float64(c.sightViewCenter.X)
		v24 := float32((float64(v34)-float64(c.sightViewCenter.Y))*(float64(v34)-float64(c.sightViewCenter.Y)) + v12*v12)
		v13 := int32(v24)
		c.newFromDrawableBoxSub(v5, v7, sightKindDrBox1, v13, v1)
	case 4, 9:
		v22 := float64(int32(v1.PosVec.X - int(c.sightViewCenter.X)))
		v29 := float32(float64(int32(v1.PosVec.Y-int(c.sightViewCenter.Y)))*float64(int32(v1.PosVec.Y-c.sightViewCenter.Y)) + v22*v22)
		v23 := int32(v29)
		c.newFromDrawableBoxSub(v7, v9, sightKindDrBox6, v23, v1)
	case 5, 8:
		v20 := float64(int32(v1.PosVec.X - int(c.sightViewCenter.X)))
		v28 := float32(float64(int32(v1.PosVec.Y-int(c.sightViewCenter.Y)))*float64(int32(v1.PosVec.Y-c.sightViewCenter.Y)) + v20*v20)
		v21 := int32(v28)
		c.newFromDrawableBoxSub(v5, v40, sightKindDrBox5, v21, v1)
	case 7:
		v36 := float32(float64(v38[7]+v38[5]) * 0.5)
		v16 := float64(v38[6]+v38[4])*0.5 - float64(c.sightViewCenter.X)
		v26 := float32((float64(v36)-float64(c.sightViewCenter.Y))*(float64(v36)-float64(c.sightViewCenter.Y)) + v16*v16)
		v17 := int32(v26)
		c.newFromDrawableBoxSub(v40, v9, sightKindDrBox4, v17, v1)
	}
}
func (c *clientSight) newFromViewport(vp *noxrender.Viewport) {
	v1 := int32(vp.World.Min.X)
	v2 := int32(vp.World.Min.Y)
	v3 := int32(vp.Size.X + int(uint32(v1)))
	v4 := int32(vp.Size.Y + int(uint32(v2)))
	v9 := c.sub_4CA8B0(v2-int32(c.sightViewCenter.Y), v1-int32(c.sightViewCenter.X))
	v5 := c.sub_4CA8B0(v2-int32(c.sightViewCenter.Y), v3-int32(c.sightViewCenter.X))
	v6 := c.sub_4CA8B0(v4-int32(c.sightViewCenter.Y), v3-int32(c.sightViewCenter.X))
	v7 := c.sub_4CA8B0(v4-int32(c.sightViewCenter.Y), v1-int32(c.sightViewCenter.X))
	c.newFromDrawableBoxSub(v9, v5, sightKindView1, math.MaxInt32, nil)
	c.newFromDrawableBoxSub(v5, v6, sightKindView4, math.MaxInt32, nil)
	c.newFromDrawableBoxSub(v6, v7, sightKindView2, math.MaxInt32, nil)
	c.newFromDrawableBoxSub(v7, v9, sightKindView3, math.MaxInt32, nil)
}

func sub_497B80(a1 *[8]float32, a2 image.Point) int8 {
	v2 := a2
	v4 := int8(0)
	v9 := float32(float64(a2.X))
	v7 := float32(float64(v2.Y))
	v5 := float64(a1[5]+a1[4]-v9-v7) * 0.70709997
	v8 := float32(float64(a1[1]+a1[0]-v9-v7) * 0.70709997)
	if float64(a1[1]-a1[0]+v9-v7)*0.70709997 <= 0.0 {
		if float64(a1[3]-a1[2]+v9-v7)*0.70709997 < 0.0 {
			v4 = 2
		}
	} else {
		v4 = 1
	}
	if v5 < 0.0 {
		return int8(int32(v4) | 8)
	}
	if float64(v8) > 0.0 {
		v4 |= 4
	}
	return v4
}

func (c *clientSight) sub_4CA8B0(a1 int32, a2 int32) sightAngle {
	v2 := a2
	if a2 == 0 {
		if a1 <= 0 {
			return 56250
		}
		return 18750
	}
	v4 := a1
	var v6 int
	if a2 >= 0 {
		if a1 >= 0 {
			v6 = 1
		} else {
			v6 = 4
			v4 = -v4
		}
	} else {
		if a1 >= 0 {
			v6 = 2
		} else {
			v4 = -a1
			v6 = 3
		}
		v2 = -a2
	}
	ind := int(v4 * 1000 / v2)
	if ind >= len(c.angleTable) {
		ind = len(c.angleTable) - 1
	}
	res := c.angleTable[ind]
	switch v6 {
	case 2:
		return sightAngHalfSize - res
	case 3:
		return res + sightAngHalfSize
	case 4:
		return sightAngSz - res
	}
	return res
}
func sub_4CA960(gpos ntype.Point32, typ byte, r types.Rectf) types.Pointf {
	pos := ntype.Point32{
		X: gpos.X * common.GridStep,
		Y: gpos.Y * common.GridStep,
	}
	switch typ {
	case 1:
		return sub_4CAA90(pos, r, common.GridStep/2, common.GridStep)
	case 2:
		return sub_4CAC30(pos, r, 0, common.GridStep/2)
	case 4:
		return sub_4CAC30(pos, r, common.GridStep/2, common.GridStep)
	case 6:
		return sub_4CAC30(pos, r, 0, common.GridStep)
	case 8:
		return sub_4CAA90(pos, r, 0, common.GridStep/2)
	case 9:
		return sub_4CAA90(pos, r, 0, common.GridStep)
	default:
		return types.Pointf{}
	}
}
func sub_4CAA90(pos ntype.Point32, rect types.Rectf, dpx, dpy int32) (out types.Pointf) {
	v5 := dpy + pos.X
	v6 := pos.Y - dpy + 22
	v22 := float32(pos.X + dpx)
	v7 := float64(v5)
	v23 := float32(v7)
	v18 := float32(v7 + float64(v6))
	v8 := int32(v18)
	if rect.Max.X == rect.Min.X {
		out.X = rect.Max.X
		out.Y = float32(v8) - rect.Max.X
		return out
	}
	if rect.Max.Y == rect.Min.Y {
		out.X = float32(v8) - rect.Max.Y
		out.Y = rect.Max.Y
		return out
	}
	v11 := float64(rect.Max.Y)
	v13 := (v11 - float64(rect.Min.Y)) / float64(rect.Max.X-rect.Min.X)
	if v13 == -1.0 {
		v13 = -0.99000001
	}
	v14 := float64(v8)
	v20 := float32(v14)
	v15 := float64(float32((v14 - (float64(rect.Min.Y) - v13*float64(rect.Min.X))) / (v13 + 1.0)))
	v21, v16 := math.Modf(v15)
	v19 := float32(v16)
	v17 := float64(float32(v21))
	out.X = float32(v17)
	if float64(v19) <= 0.5 {
		if float64(v19) < memmap.Float64(0x581450, 9968) {
			out.X = float32(v17 - 1.0)
		}
	} else {
		out.X = float32(v17 + 1.0)
	}
	if float64(out.X) >= float64(v22) {
		if float64(out.X) > float64(v23) {
			out.X = v23
		}
		out.Y = v20 - out.X
	} else {
		out.X = v22
		out.Y = v20 - out.X
	}
	return out
}
func (c *clientSight) sub_499130(a1 image.Point) {
	if c.dword_5d4594_1217452 >= len(c.arr_5d4594_1212068) {
		return
	}
	c.arr_5d4594_1212068[c.dword_5d4594_1217452] = a1
	c.dword_5d4594_1217452++
}
func (c *clientSight) Sub_499290(a1 int) image.Point {
	return c.arr_5d4594_1212068[a1]
}
func (c *clientSight) sub_4991E0(a1 image.Point) {
	v1 := c.dword_5d4594_1217452
	if c.dword_5d4594_1217452 <= 0 {
		return
	}
	v2 := a1
	v3 := 1
	v12 := 1
	for {
		v4 := &c.arr_5d4594_1212068[v3-1]
		v5 := v4.Y - v2.Y
		v6 := (v4.X-v2.X)*(v4.X-v2.X) + v5*v5
		if v3 < v1 {
			for i := 0; i < v1-v3; i++ {
				v7 := &c.arr_5d4594_1212068[v3+i]
				v8 := v7.Y - v2.Y
				v9 := (v7.X-v2.X)*(v7.X-v2.X) + v8*v8
				if v9 < v6 {
					v10 := v4.Y
					v6 = v9
					v11 := v4.X
					v4.X = v7.X
					v4.Y = v7.Y
					v7.X = v11
					v7.Y = v10
				}
			}
			v1 = c.dword_5d4594_1217452
			v3 = v12
		}
		v3++
		v12 = v3
		if v3-1 >= v1 {
			break
		}
	}
}
func sub_4990D0(a1, a2 image.Point) int8 {
	if a1.X <= a2.X {
		if a1.X >= a2.X {
			v7 := a1.Y
			v8 := a2.Y
			if v7 <= v8 {
				if v7 >= v8 {
					return 0
				} else {
					return 8
				}
			} else {
				return 4
			}
		} else {
			v5 := a1.Y
			v6 := a2.Y
			if v5 <= v6 {
				if v5 < v6 {
					return 10
				}
			} else {
				return 6
			}
			return 2
		}
	} else {
		v2 := a1.Y
		v3 := a2.Y
		if v2 <= v3 {
			if v2 < v3 {
				return 9
			}
		} else {
			return 5
		}
		return 1
	}
}
func sub_499160(a1, a2, a3 image.Point) bool {
	var (
		v3 int
		v4 int
		v5 int
		v6 int
		v7 int
	)
	v3 = a3.X
	if a3.X > a2.X {
		v4 = a3.Y
		if v4 > a2.Y {
			v3 = a3.X
			v6 = a2.X
			v4 = a2.Y
			v5 = a3.Y
		} else {
			v6 = a2.X
			v5 = a2.Y
		}
	} else {
		v4 = a2.Y
		if a3.Y > v4 {
			v6 = a3.X
			v3 = a2.X
			v5 = a3.Y
		} else {
			v5 = a2.Y
			v6 = a3.X
			v4 = a3.Y
			v3 = a2.X
		}
	}
	if !(a1.X >= v6 && a1.X <= v3) {
		return false
	}
	v7 = a1.Y
	if v7 >= v4 && v7 <= v5 {
		return true
	}
	return false
}
func (c *clientSight) newFromDrawableBoxSub(a1, a2 sightAngle, kind sightObjKind, a4 int32, dr *Drawable) {
	ss := c.newStruct()
	ss.Kind56 = kind
	ss.DistSq32 = a4
	ss.Field48 = 1
	ss.Drawable = dr
	if a2 >= a1 {
		ss.Ang40 = a1
		ss.Ang44 = a2
	} else {
		ss.Ang40 = a2
		ss.Ang44 = a1
	}
	ss.Ang40 = ss.Ang40.Normalize()
	ss.Ang44 = ss.Ang44.Normalize()
	if ss.Ang44-ss.Ang40 < sightAngHalfSize {
		c.addListZzz(ss)
		return
	}
	ss2 := c.copyStruct(ss)
	ss2.Ang40 = 0
	ss2.Ang44 = ss.Ang40
	ss.Ang40 = ss.Ang44
	ss.Ang44 = sightAngMax
	c.addListZzz(ss2)
	c.addListZzz(ss)
}

func sub_4CAC30(pos ntype.Point32, rect types.Rectf, dpx, dpy int32) (out types.Pointf) {
	v5 := dpx + pos.Y
	v6 := dpy + pos.X
	v17 := float32(float64(pos.X + dpx))
	v18 := float32(float64(v6))
	v13 := float32(float64(v5) - float64(v17))
	v7 := int32(v13)
	if rect.Max.X == rect.Min.X {
		out.X = rect.Max.X
		out.Y = float32(float64(v7) + float64(rect.Max.X))
		return out
	} else if rect.Max.Y == rect.Min.Y {
		out.X = float32(float64(rect.Max.Y) - float64(v7))
		out.Y = rect.Max.Y
		return out
	}
	v8 := float64((rect.Max.Y - rect.Min.Y) / (rect.Max.X - rect.Min.X))
	if v8 == 1.0 {
		v8 = 0.99000001
	}
	v9 := float64(v7)
	v15 := float32(v9)
	v10 := float64(float32((v9 - (float64(rect.Min.Y) - v8*float64(rect.Min.X))) / (v8 - 1.0)))
	v16, v11 := math.Modf(v10)
	v14 := float32(v11)
	v12 := float64(float32(v16))
	out.X = float32(v12)
	if float64(v14) <= 0.5 {
		if float64(v14) < memmap.Float64(0x581450, 9968) {
			out.X = float32(v12 - 1.0)
		}
	} else {
		out.X = float32(v12 + 1.0)
	}
	if float64(out.X) >= float64(v17) {
		if float64(out.X) > float64(v18) {
			out.X = v18
		}
		out.Y = v15 + out.X
	} else {
		out.X = v17
		out.Y = v15 + out.X
	}
	return out
}
func sub_414C50(a1 int32) int {
	v1 := sub_414BD0(a1)
	v2 := sub_414BD0(sightAngVal1 - a1)
	if v2 != 0 {
		return (v1 << 12) / v2
	} else {
		v3 := 0
		if v1 <= 0 {
			v3 = 1
		}
		return v3 + math.MaxInt32
	}
}
func sub_414BD0(a1 int32) int {
	v1 := a1
	if a1 < 0 {
		v1 = a1 + ((sightAngVal4-a1-1)/sightAngVal4)*sightAngVal4
	}
	if v1 >= sightAngVal4 {
		v1 %= sightAngVal4
	}
	return int(memmap.Int32(0x85B3FC, uintptr(((v1<<12)/sightAngVal4)*4+12260)))
}
func sub_57BA30(p1, p2 *image.Point, r image.Rectangle) int {
	swap := false
	for {
		var fx byte
		if p1.X < r.Min.X {
			fx |= 8
		} else if p1.X > r.Max.X {
			fx |= 4
		}
		if p1.Y < r.Min.Y {
			fx |= 2
		} else if p1.Y > r.Max.Y {
			fx |= 1
		}
		var fy byte
		if p2.X < r.Min.X {
			fy |= 8
		} else if p2.X > r.Max.X {
			fy |= 4
		}
		if p2.Y < r.Min.Y {
			fy |= 2
		} else if p2.Y > r.Max.Y {
			fy |= 1
		}
		if fy&fx != 0 {
			if swap {
				*p1, *p2 = *p2, *p1
			}
			return 0
		}
		if fx == 0 {
			if fy == 0 {
				if swap {
					*p1, *p2 = *p2, *p1
				}
				return 1
			}
			*p1, *p2 = *p2, *p1
			fx = fy
			swap = !swap
		}
		if fx&1 != 0 {
			p1.X += (r.Max.Y - p1.Y) * (p2.X - p1.X) / (p2.Y - p1.Y)
			p1.Y = r.Max.Y
		} else if fx&2 != 0 {
			p1.X += (r.Min.Y - p1.Y) * (p2.X - p1.X) / (p2.Y - p1.Y)
			p1.Y = r.Min.Y
		} else if fx&4 != 0 {
			p1.Y += (r.Max.X - p1.X) * (p2.Y - p1.Y) / (p2.X - p1.X)
			p1.X = r.Max.X
		} else if fx&8 != 0 {
			p1.Y += (r.Min.X - p1.X) * (p2.Y - p1.Y) / (p2.X - p1.X)
			p1.X = r.Min.X
		}
	}
}
func (c *clientSight) sub_498380(ss1 *SightObject, ss2 *SightObject) {
	v2 := ss1.Ang40
	v3 := ss2.Ang44
	if v3 < v2 {
		return
	}
	v4 := ss2.Ang40
	v5 := ss1.Ang44
	if v4 > v5 {
		return
	}
	if v4 < v2 {
		if v3 <= v5 {
			if ss1.DistSq32 >= ss2.DistSq32 {
				v6 := ss1.Ang44
				ss1.Ang40 = v3 + 1
				if v3+1 > v6 {
					ss1.Field48 = 0
				}
			} else {
				ss2.Ang44 = v2 - 1
			}
			return
		}
		if ss1.DistSq32 < ss2.DistSq32 {
			v7 := c.copyStruct(ss2)
			v8 := v7.Ang44
			v9 := ss1.Ang44 + 1
			v7.Ang40 = v9
			if v9 > v8 {
				v7.Field48 = 0
			}
			v10 := ss1.Ang40 - 1
			v11 := ss2.Ang40
			ss2.Ang44 = v10
			if v11 > v10 {
				ss2.Field48 = 0
			}
			c.addListZzz(v7)
			return
		}
		ss1.Field48 = 0
		return
	}
	v12 := v3 <= v5
	v13 := ss1.DistSq32
	if v12 {
		if v13 >= ss2.DistSq32 {
			v14 := c.copyStruct(ss1)
			v15 := v14.Ang44
			v16 := ss2.Ang44 + 1
			v14.Ang40 = v16
			if v16 > v15 {
				v14.Field48 = 0
			}
			v17 := ss2.Ang40 - 1
			v18 := ss1.Ang40
			ss1.Ang44 = v17
			if v18 > v17 {
				ss1.Field48 = 0
			}
			c.addListZzz(v14)
		} else {
			ss2.Field48 = 0
		}
	} else {
		if v13 >= ss2.DistSq32 {
			v21 := v4 - 1
			v22 := ss1.Ang40
			ss1.Ang44 = v21
			if v22 <= v21 {
				return
			}
			ss1.Field48 = 0
			return
		}
		v19 := ss2.Ang44
		v20 := v5 + 1
		ss2.Ang40 = v20
		if v20 > v19 {
			ss2.Field48 = 0
		}
	}
}
func sub_427C80(r1, r2 image.Rectangle) bool {
	v2 := r1.Min.X
	v3 := r1.Min.Y
	v4 := r1.Max.X
	v19 := r1.Max.Y
	v5 := r2.Min.X
	v21 := r2.Min.Y
	v17 := r2.Max.Y
	v6 := r2.Max.X
	v7 := v4 - v2
	v8 := r2.Min.X - v6
	v20 := r2.Min.X
	var v22 int
	if v4-v2 >= 0 {
		v6 = r2.Max.X
		v22 = v2
	} else {
		v22 = v4
		v4 = v2
	}
	if v8 <= 0 {
		if v4 < v5 || v6 < v22 {
			return false
		}
	} else if v4 < v6 || v5 < v22 {
		return false
	}
	v10 := v19
	v11 := v21 - v17
	v18 := v19 - v3
	var v23 int
	if v19-v3 >= 0 {
		v23 = v3
	} else {
		v23 = v19
		v10 = v3
	}
	if v11 <= 0 {
		if v10 < v21 || v17 < v23 {
			return false
		}
	} else {
		if v10 < v17 {
			return false
		}
		if v21 < v23 {
			return false
		}
	}
	v12 := v2 - v20
	v13 := v3 - v21
	v14 := v11*(v2-v20) - v8*(v3-v21)
	v15 := v8*v18 - v7*v11
	if v15 <= 0 {
		if v14 > 0 || v14 < v15 {
			return false
		}
	} else {
		if v14 < 0 {
			return false
		}
		if v14 > v15 {
			return false
		}
	}
	v16 := v7*v13 - v18*v12
	if v15 <= 0 {
		if v16 <= 0 && v16 >= v15 {
			return true
		}
		return false
	}
	if v16 < 0 {
		return false
	}
	if v16 > v15 {
		return false
	}
	return true
}

func (c *clientSight) Nox_xxx_drawBlack_496150_C() []image.Point {
	c.sub_4989A0()
	return c.GetSightPoints()
}
func (c *clientSight) sub_4989A0() {
	arr := c.GetSightPoints()
	if len(arr) < 3 {
		return
	}

	barr := c.sightPointsKind[:]
	iarr := c.sightPointsSrc[:]

	p0 := arr[0]
	p1 := arr[1]

	j := 1
	for i := 2; i < len(arr); i++ {
		p := arr[i]
		bv := barr[i]
		if ((p0.X-p1.X)*(p.Y-p1.Y) != (p0.Y-p1.Y)*(p.X-p1.X)) || bv != barr[j] {
			j++
			p0 = p1
		}
		arr[j] = p
		barr[j] = bv
		iarr[j] = iarr[i]
		p1 = p
	}
	c.sightPointsCnt = j + 1
}
