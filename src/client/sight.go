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

type WallChecker interface {
	GetWallAtGrid(pos image.Point) *server.Wall
	DefByInd(i int) *server.WallDef
}

func (c *Client) Nox_xxx_drawBlack_496150(vp *noxrender.Viewport) {
	c.Sight.Nox_xxx_drawBlack_496150_A(vp)
	c.Sight.Sub_498030(vp)
	c.sub_497260(vp)
	c.Sight.Nox_xxx_drawBlack_496150_E(vp, &c.Server.Walls, c.Server.Sub_57B500, c.DrawListAppendWallYyy)
	c.Sight.Sub_498110()
	c.Sight.Nox_xxx_drawBlack_496150_F(vp, &c.Server.Walls)
}

func (c *Client) Sub_498AE0() {
	r := c.Render()
	r.Data().SetAlphaEnabled(true)
	defer r.Data().SetAlphaEnabled(false)
	cl := noxcolor.RGB5551Color(0, 0, 0)
	r.Data().SetColor2(cl)
	c.Sight.Sub_498AE0_B(func(p1, p2 ntype.Point32) {
		c.sub_498B50(cl, p1, p2)
	})
}

func (c *Client) sub_498B50(cl color.Color, p1, p2 ntype.Point32) {
	r := c.Render()
	v7 := p1.Y - p2.Y
	v8 := p1.X - p2.X
	v9 := p1.X - p2.X
	v10 := p2.Y - p1.Y
	if p1.X-p2.X < 0 {
		v8 = p2.X - p1.X
	}
	if v7 < 0 {
		v7 = p2.Y - p1.Y
	}
	var sy, sx int32
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
		sy = int32(v11 + 1)
	}
	alpha := byte(208)
	cp := p1
	vx := p2.X - p1.X
	vy := p2.Y - p1.Y
	for i := 0; i < 10; i++ {
		r.Data().SetAlpha(alpha)
		alpha -= 20
		r.DrawVector(image.Pt(int(cp.X), int(cp.Y)), image.Pt(int(vx), int(vy)), cl)
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
						c.Sight.Sub_497650(dr)
					}
				}
			case server.ShapeKindBox:
				if (pos.X+dr.Shape.Box.LeftBottom2) < float32(vp.World.Min.X+vp.Size.X) && (pos.X+dr.Shape.Box.RightTop) > float32(vp.World.Min.X) {
					if (pos.Y+dr.Shape.Box.LeftBottom) < float32(vp.World.Min.Y+vp.Size.Y) && (pos.Y+dr.Shape.Box.RightTop2) > float32(vp.World.Min.Y) {
						c.Sight.Sub_4977C0(dr)
					}
				}
			}
		} else {
			if (pos.X-32) < float32(vp.World.Min.X+vp.Size.X) && (pos.X+32) > float32(vp.World.Min.X) {
				if (pos.Y-32) < float32(vp.World.Min.Y+vp.Size.Y) && (pos.Y+32) > float32(vp.World.Min.Y) {
					c.Sight.Sub_4974B0(dr)
				}
			}
		}
	}
}

type clientSight struct {
	dword_5d4594_1217444_vec ntype.Point32
	dword_5d4594_1217452     int
	sightStructArr           []*SightStructXxx
	sightStructArrSize       int

	dword_5d4594_1522584 *SightStructXxx
	dword_5d4594_1522588 uint32
	dword_5d4594_1522592 *SightStructXxx
	dword_5d4594_1522596 *SightStructXxx

	arr_5d4594_1322584 [100000]int16

	dword_5d4594_1217464_size int
	arr_5d4594_1203876        [1024]ntype.Point32
	arr_5d4594_1213348        [1024]uint32
	arr_5d4594_1212324        [1024]byte

	arr_5d4594_1212068 [32]ntype.Point32
}

func (c *clientSight) sub_4CAE60() {
	var v1 *SightStructXxx
	c.dword_5d4594_1522584 = nil
	for it := c.dword_5d4594_1522592; it != nil; it = it.Field8 {
		it.Field16 = v1
		v1 = it
		c.dword_5d4594_1522584 = it
	}
}

func (c *clientSight) Nox_xxx_drawBlack_496150_A(vp *noxrender.Viewport) {
	c.sub_4CAE60()
	c.dword_5d4594_1217464_size = 0
	c.sightStructArrSize = 0
	c.dword_5d4594_1217444_vec.X = int32(vp.World.Min.X) + int32(vp.Size.X)/2
	c.dword_5d4594_1217444_vec.Y = int32(uint32(vp.World.Min.Y + vp.Jiggle12 + vp.Size.Y/2))
}

func (c *clientSight) Nox_xxx_drawBlack_496150_E(vp *noxrender.Viewport, walls WallChecker, checkDoor func(pos image.Point, flags byte) int8, addWall func(w *server.Wall)) {
	v1 := int32(vp.World.Min.X)
	v2 := int32(vp.World.Min.Y)
	v3 := int32(vp.Size.X)
	v79 := v1 / 23
	v80 := v2 / 23
	v74 := (v3+v1)/23 - v1/23
	v4 := int32((vp.Size.Y+int(v2))/23 - int(v2/23))
	if v4 >= 0 {
		for yi := 0; yi < int(v4+1); yi++ {
			gy := v80 + int32(yi)
			v70 := 23 * gy
			v7 := (int32(uint8(int8(gy))) + int32(uint8(int8(v79)))) & 1
			if v7 > v74 {
				continue
			}
			for xi := 0; xi < int(v74-v7+2)/2; xi++ {
				gx := v7 + v79 + 2*int32(xi)
				v69 := 23 * gx
				wl := walls.GetWallAtGrid(image.Pt(int(gx), int(gy)))
				if wl == nil {
					continue
				}
				v10 := uint8(checkDoor(image.Pt(int(gx), int(gy)), 64))
				if int32(v10) == math.MaxUint8 {
					continue
				}
				def := walls.DefByInd(int(wl.Tile1))
				if def.Flags32&1 == 0 {
					wl.Flags4 |= 1
					if int32(wl.Y6)*23 <= c.dword_5d4594_1217444_vec.Y {
						wl.Flags4 &^= 2
					} else {
						wl.Flags4 |= 2
					}
					if def.Flags32&4 != 0 {
						addWall(wl)
					}
				} else {
					if wl.Flags4&0x40 != 0 {
						if (c.dword_5d4594_1217444_vec.X-v69-11)*(c.dword_5d4594_1217444_vec.X-v69-11)+(c.dword_5d4594_1217444_vec.Y-v70-11)*(c.dword_5d4594_1217444_vec.Y-v70-11) < 3600 {
							wl.Flags4 |= 1
							continue
						}
					}
					if v10 == 0 {
						c.nox_xxx_drawBlackofWall_497C40(gx, gy, 9)
					} else if v10 == 1 {
						c.nox_xxx_drawBlackofWall_497C40(gx, gy, 6)
					} else {
						v16 := memmap.Uint8(0x587000, uintptr(v10)+161764)
						if int32(v16)&2 != 0 {
							c.nox_xxx_drawBlackofWall_497C40(gx, gy, 2)
						}
						if int32(v16)&1 != 0 {
							c.nox_xxx_drawBlackofWall_497C40(gx, gy, 1)
						}
						if int32(v16)&8 != 0 {
							c.nox_xxx_drawBlackofWall_497C40(gx, gy, 8)
						}
						if int32(v16)&4 != 0 {
							c.nox_xxx_drawBlackofWall_497C40(gx, gy, 4)
						}
					}
				}
			}
		}
	}
}

func (c *clientSight) Nox_xxx_drawBlack_496150_F(vp *noxrender.Viewport, walls WallChecker) {
	var brect types.Rectf
	brect.Min.X = float32(c.dword_5d4594_1217444_vec.X)
	brect.Min.Y = float32(c.dword_5d4594_1217444_vec.Y)
	v51 := c.dword_5d4594_1217464_size
	if c.sightStructArrSize > 0 {
		for i := 0; i < c.sightStructArrSize; i++ {
			v18 := int32(0)
			ss := c.sightStructArr[i]
			var pp1, pp2 types.Pointf
			switch ss.Field56 {
			case 0:
				v20 := (ss.Field40 * 25736) / 75000
				v21 := (ss.Field44 * 25736) / 75000

				brect.Max.X = float32(c.dword_5d4594_1217444_vec.X + sub_414BD0(6434-v20))
				brect.Max.Y = float32(c.dword_5d4594_1217444_vec.Y + sub_414BD0(v20))
				pp1 = sub_4CA960(ss.GridPos24, int8(ss.Field36), brect)

				brect.Max.X = float32(c.dword_5d4594_1217444_vec.X + sub_414BD0(6434-v21))
				brect.Max.Y = float32(c.dword_5d4594_1217444_vec.Y + sub_414BD0(v21))
				pp2 = sub_4CA960(ss.GridPos24, int8(ss.Field36), brect)

				wl := walls.GetWallAtGrid(image.Pt(int(ss.GridPos24.X), int(ss.GridPos24.Y)))
				wl.Field12 = 1
				wl.Flags4 |= 1
				if pp2.X < pp1.X {
					wl.Flags4 |= 2
				}
				wl.Field3 |= ss.Field36
				v18 = ss.GridPos24.X + (ss.GridPos24.Y << 8)
			case 1:
				pp1.X = float32(c.dword_5d4594_1217444_vec.X + sub_414C50((ss.Field40*25736)/75000-19302)*int32(vp.Size.Y/2)/4096)
				pp1.Y = float32(vp.World.Min.Y)
				pp2.X = float32(c.dword_5d4594_1217444_vec.X + sub_414C50((ss.Field44*25736)/75000-19302)*int32(vp.Size.Y/2)/4096)
				pp2.Y = float32(vp.World.Min.Y)
				v18 = 0
			case 2:
				pp1.X = float32(c.dword_5d4594_1217444_vec.X - sub_414C50((ss.Field40*25736)/75000-6434)*(int32(vp.Size.Y)/2)/4096)
				pp1.Y = float32(vp.World.Min.Y + vp.Size.Y - 1)
				v29 := sub_414C50((ss.Field44*25736)/75000 - 6434)
				pp2.X = float32(c.dword_5d4594_1217444_vec.X - v29*(int32(vp.Size.Y)/2)/4096)
				pp2.Y = float32(vp.World.Min.Y + vp.Size.Y - 1)
				v18 = 0
			case 3:
				pp1.X = float32(vp.World.Min.X)
				pp1.Y = float32(c.dword_5d4594_1217444_vec.Y - sub_414C50((ss.Field40*25736)/75000-12868)*int32(vp.Size.X/2)/4096)
				pp2.X = float32(vp.World.Min.X)
				pp2.Y = float32(c.dword_5d4594_1217444_vec.Y - sub_414C50((ss.Field44*25736)/75000-12868)*int32(vp.Size.X/2)/4096)
				v18 = 0
			case 4:
				pp1.X = float32(float64(vp.Size.X + vp.World.Min.X - 1))
				pp1.Y = float32(float64(int32(c.dword_5d4594_1217444_vec.Y + int32(sub_414C50((ss.Field40*25736)/75000)*(int32(vp.Size.X)/2)/4096))))
				pp2.X = float32(float64(vp.World.Min.X + vp.Size.X - 1))
				pp2.Y = float32(float64(int32(c.dword_5d4594_1217444_vec.Y + int32(sub_414C50((ss.Field44*25736)/75000)*int32(vp.Size.X/2)/4096))))
				v18 = 0
			case 6:
				v34 := ss.Obj20
				v35 := float64(v34.PosVec.X)
				v34.Field_33 = 1
				var rect types.Rectf
				rect.Min.X = float32(v35)
				rect.Min.Y = float32(float64(v34.PosVec.Y))
				rect.Max.X = float32(float64(v34.PosVec.X + int(*memmap.PtrInt32(0x587000, uintptr(int32(v34.Field_74_4)*8)+196184))))
				rect.Max.Y = float32(float64(v34.PosVec.Y + int(*memmap.PtrInt32(0x587000, uintptr(int32(v34.Field_74_4)*8)+196188))))
				v36 := (ss.Field40 * 25736) / 75000
				brect.Max.X = float32(float64(c.dword_5d4594_1217444_vec.X + sub_414BD0(6434-v36)))
				brect.Max.Y = float32(float64(c.dword_5d4594_1217444_vec.Y + sub_414BD0(v36)))
				var ok bool
				pp1, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp1 = rect.Min
				}
				v37 := (ss.Field44 * 25736) / 75000
				brect.Max.X = float32(float64(c.dword_5d4594_1217444_vec.X + sub_414BD0(6434-v37)))
				brect.Max.Y = float32(float64(c.dword_5d4594_1217444_vec.Y + sub_414BD0(v37)))
				pp2, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp2 = rect.Max
				}
				v18 = int32(v34.Field_32)
			case 7:
				ss.Obj20.Field_33 = 1
				v38 := ss.Obj20
				v39 := c.dword_5d4594_1217444_vec.X - int32(v38.PosVec.X)
				v40 := int32(v38.PosVec.Y - int(c.dword_5d4594_1217444_vec.Y))
				var rect types.Rectf
				rect.Min.X = float32(float64(v40 + int32(ss.Obj20.PosVec.X)))
				rect.Min.Y = float32(float64(v39 + int32(ss.Obj20.PosVec.Y)))
				rect.Max.X = float32(float64(ss.Obj20.PosVec.X - int(v40)))
				rect.Max.Y = float32(float64(ss.Obj20.PosVec.Y - int(v39)))
				v41 := (ss.Field40 * 25736) / 75000
				brect.Max.X = float32(float64(c.dword_5d4594_1217444_vec.X + sub_414BD0(6434-v41)))
				brect.Max.Y = float32(float64(c.dword_5d4594_1217444_vec.Y + sub_414BD0(v41)))
				var ok bool
				pp1, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp1 = types.Ptf(rect.Min.X, rect.Min.Y)
				}
				v42 := (ss.Field44 * 25736) / 75000
				brect.Max.X = float32(float64(c.dword_5d4594_1217444_vec.X + sub_414BD0(6434-v42)))
				brect.Max.Y = float32(float64(c.dword_5d4594_1217444_vec.Y + sub_414BD0(v42)))
				pp2, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp2 = rect.Max
				}
				v18 = int32(ss.Obj20.Field_32)
			case 8, 9, 0xA, 0xB, 0xD, 0xE:
				ss.Obj20.Field_33 = 1
				var rect types.Rectf
				switch ss.Field56 {
				case 8:
					rect.Min.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.LeftTop
					rect.Min.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.LeftBottom
					rect.Max.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.LeftBottom2
					rect.Max.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.LeftTop2
				case 9:
					rect.Min.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.LeftTop
					rect.Min.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.LeftBottom
					rect.Max.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.RightTop
					rect.Max.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.RightBottom
				case 0xA:
					rect.Min.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.RightBottom2
					rect.Min.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.RightTop2
					rect.Max.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.LeftBottom2
					rect.Max.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.LeftTop2
				case 0xB:
					rect.Min.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.RightBottom2
					rect.Min.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.RightTop2
					rect.Max.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.RightTop
					rect.Max.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.RightBottom
				case 0xD:
					rect.Min.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.LeftTop
					rect.Min.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.LeftBottom
					rect.Max.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.RightBottom2
					rect.Max.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.RightTop2
				case 0xE:
					rect.Min.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.LeftBottom2
					rect.Min.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.LeftTop2
					rect.Max.X = float32(ss.Obj20.PosVec.X) + ss.Obj20.Shape.Box.RightTop
					rect.Max.Y = float32(ss.Obj20.PosVec.Y) + ss.Obj20.Shape.Box.RightBottom
				}
				v45 := (ss.Field40 * 25736) / 75000
				brect.Max.X = float32(c.dword_5d4594_1217444_vec.X + sub_414BD0(6434-v45))
				brect.Max.Y = float32(c.dword_5d4594_1217444_vec.Y + sub_414BD0(v45))
				var ok bool
				pp1, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp1 = rect.Min
				}
				v46 := (ss.Field44 * 25736) / 75000
				brect.Max.X = float32(c.dword_5d4594_1217444_vec.X + sub_414BD0(6434-v46))
				brect.Max.Y = float32(c.dword_5d4594_1217444_vec.Y + sub_414BD0(v46))
				pp2, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp2 = rect.Max
				}
				v18 = int32(ss.Obj20.Field_32)
			}
			var a1a, a2 image.Point
			a1a.X = vp.Screen.Min.X - vp.World.Min.X + int(pp1.X)
			a1a.Y = vp.Screen.Min.Y - vp.World.Min.Y + int(pp1.Y)
			a2.X = vp.Screen.Min.X - vp.World.Min.X + int(pp2.X)
			a2.Y = vp.Screen.Min.Y - vp.World.Min.Y + int(pp2.Y)
			if sub_57BA30(&a1a, &a2, &vp.Screen) != 0 {
				v47 := c.dword_5d4594_1217464_size
				c.arr_5d4594_1203876[c.dword_5d4594_1217464_size].X = int32(a1a.X)
				c.arr_5d4594_1203876[c.dword_5d4594_1217464_size].Y = int32(a1a.Y)
				c.arr_5d4594_1213348[v47] = uint32(v18)
				c.arr_5d4594_1212324[v47] = ss.Field56
				v47++
				c.dword_5d4594_1217464_size = v47
				c.arr_5d4594_1203876[v47].X = int32(a2.X)
				c.arr_5d4594_1203876[v47].Y = int32(a2.Y)
				c.arr_5d4594_1213348[v47] = uint32(v18)
				c.arr_5d4594_1212324[v47] = ss.Field56
				v51 = v47 + 1
				c.dword_5d4594_1217464_size = v51
			} else {
				v51 = c.dword_5d4594_1217464_size
			}
		}
	}
	c.dword_5d4594_1217464_size = v51 - 1
	pi := c.dword_5d4594_1217464_size - 1
	for i := 0; i < c.dword_5d4594_1217464_size; pi, i = i, i+1 {
		v55 := c.arr_5d4594_1212324[pi]
		var adx, ady int32
		if v55 != 0 {
			v56 := c.arr_5d4594_1212324[i]
			if v56 == 0 {
				if v55 == 6 || c.arr_5d4594_1212324[i] == 6 {
					v63 := c.arr_5d4594_1203876[pi].X
					var v64 int32
					if c.arr_5d4594_1203876[i].X-v63 >= 0 {
						v64 = c.arr_5d4594_1203876[i].X - v63
					} else {
						v64 = v63 - c.arr_5d4594_1203876[i].X
					}
					v65 := c.arr_5d4594_1203876[pi].Y
					var v66 int32
					if c.arr_5d4594_1203876[i].Y-v65 >= 0 {
						v66 = c.arr_5d4594_1203876[i].Y - v65
					} else {
						v66 = v65 - c.arr_5d4594_1203876[i].Y
					}
					if v64 <= 4 && v66 <= 4 {
						continue
					}
				}
				c.arr_5d4594_1212324[pi] = 12
				continue
			}
			if v56 != v55 {
				c.arr_5d4594_1212324[pi] = 12
				continue
			}
			if c.arr_5d4594_1213348[i] == c.arr_5d4594_1213348[pi] {
				continue
			}
			v57 := c.arr_5d4594_1203876[pi].X
			v58 := c.arr_5d4594_1203876[i].X - v57
			if v58 < 0 {
				adx = v57 - c.arr_5d4594_1203876[i].X
			} else {
				adx = v58
			}
		} else {
			if c.arr_5d4594_1212324[i] != 0 {
				if v55 == 6 || c.arr_5d4594_1212324[i] == 6 {
					v63 := c.arr_5d4594_1203876[pi].X
					var v64 int32
					if c.arr_5d4594_1203876[i].X-v63 >= 0 {
						v64 = c.arr_5d4594_1203876[i].X - v63
					} else {
						v64 = v63 - c.arr_5d4594_1203876[i].X
					}
					v65 := c.arr_5d4594_1203876[pi].Y
					var v66 int32
					if c.arr_5d4594_1203876[i].Y-v65 >= 0 {
						v66 = c.arr_5d4594_1203876[i].Y - v65
					} else {
						v66 = v65 - c.arr_5d4594_1203876[i].Y
					}
					if v64 <= 4 && v66 <= 4 {
						continue
					}
				}
				c.arr_5d4594_1212324[pi] = 12
				continue
			}
			if c.arr_5d4594_1213348[pi] == c.arr_5d4594_1213348[i] {
				continue
			}
			if xx1, xx2 := c.arr_5d4594_1203876[i].X, c.arr_5d4594_1203876[pi].X; xx1-xx2 < 0 {
				adx = xx2 - xx1
			} else {
				adx = xx1 - xx2
			}
		}
		if yy1, yy2 := c.arr_5d4594_1203876[i].Y, c.arr_5d4594_1203876[pi].Y; yy1-yy2 < 0 {
			ady = yy2 - yy1
		} else {
			ady = yy1 - yy2
		}
		if adx > 4 || ady > 4 {
			c.arr_5d4594_1212324[pi] = 12
		}
	}
}

func (c *clientSight) checkXxx(r image.Rectangle) bool {
	prev := c.arr_5d4594_1203876[c.dword_5d4594_1217464_size-1]
	for i := 0; i < c.dword_5d4594_1217464_size; i++ {
		p := c.arr_5d4594_1203876[i]
		var r2 image.Rectangle
		r2.Min.X = int(prev.X)
		r2.Min.Y = int(prev.Y)
		r2.Max.X = int(p.X)
		r2.Max.Y = int(p.Y)
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
	if c.dword_5d4594_1217464_size <= 0 {
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
	} else if *(*uint16)(unsafe.Add(dr.C(), 2)) != 0 {
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

func (c *clientSight) Sub_498AE0_B(draw func(p1, p2 ntype.Point32)) {
	v0 := c.dword_5d4594_1217464_size
	v1 := 0
	for i := c.dword_5d4594_1217464_size - 1; v1 < v0; v1++ {
		if c.arr_5d4594_1212324[i] == 12 {
			draw(c.arr_5d4594_1203876[i], c.arr_5d4594_1203876[v1])
			v0 = c.dword_5d4594_1217464_size
		}
		i = v1
	}
}

func (c *clientSight) Sub_498C20(a1 *ntype.Point32, a2 *ntype.Point32, a3 int32) int32 {
	var (
		v3  *ntype.Point32
		v4  *ntype.Point32
		v5  int8
		v6  int8
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v21 float32
		v22 float32
		v23 float32
		v24 float32
		v25 float32
		v26 float32
		v27 float32
		v28 float32
		v29 float32 = 0
		v30 float32
		v31 int32 = 0
		a1a ntype.Point32
		v37 int8
		v38 int8
		v39 float32
	)
	v3 = a1
	if a1 == nil {
		return 0
	}
	v4 = a2
	if a2 == nil {
		return 0
	}
	if a3 == 0 {
		return 0
	}
	c.dword_5d4594_1217452 = 0
	v5 = sub_4990D0(a1, a2)
	v6 = v5
	v37 = v5
	if int32(v5) == 0 {
		return 0
	}
	if int32(v5) != 4 && int32(v5) != 8 {
		v29 = float32(float64(a2.Y-v3.Y) / float64(a2.X-v3.X))
		v27 = float32(float64(v3.X) * float64(v29))
		v31 = v3.Y - int32(v27)
	}
	v7 := c.dword_5d4594_1217464_size
	if c.dword_5d4594_1217464_size > 0 {
		for v32 := 0; ; {
			a2a := c.arr_5d4594_1203876[v32]
			var a3a ntype.Point32
			if v32 == v7-1 {
				a3a = c.arr_5d4594_1203876[0]
			} else {
				a3a = c.arr_5d4594_1203876[v32+1]
			}
			v38 = sub_4990D0(&a2a, &a3a)
			if int32(v38) != 0 && ((int32(v6)&1) == 0 || a2a.X <= v3.X || a2a.X <= v4.X || a3a.X <= v3.X || a3a.X <= v4.X) && ((int32(v37)&2) == 0 || a2a.X >= v3.X || a2a.X >= v4.X || a3a.X >= v3.X) {
				if (int32(v37)&4) == 0 || (func() bool {
					v11 = v3.Y
					return a2a.Y <= v11
				}()) || (func() bool {
					v12 = a2.Y
					return a2a.Y <= v12
				}()) || a3a.Y <= v11 || a3a.Y <= v12 {
					if (int32(v37)&8) == 0 || (func() bool {
						v13 = v3.Y
						return a2a.Y >= v13
					}()) || (func() bool {
						v14 = a2.Y
						return a2a.Y >= v14
					}()) || a3a.Y >= v13 || a3a.Y >= v14 {
						if a2a.X == a3a.X {
							if int32(v37) == 4 || int32(v37) == 8 {
								goto LABEL_65
							}
							if int32(v37) != 1 && int32(v37) != 2 {
								a1a.X = a2a.X
								v26 = float32(float64(a2a.X) * float64(v29))
								a1a.Y = v31 + int32(v26)
								if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
									c.sub_499130(a1a)
								}
								goto LABEL_65
							}
							a1a.Y = v3.X
							a1a.X = a2a.X
							if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
								c.sub_499130(a1a)
								goto LABEL_65
							}
						} else {
							v28 = float32(float64(a3a.Y-a2a.Y) / float64(a3a.X-a2a.X))
							v21 = float32(float64(a2a.X) * float64(v28))
							v15 = int32(v21)
							v16 = a2a.Y - v15
							if int32(v37) == 4 || int32(v37) == 8 {
								if int32(v38) == 1 || int32(v38) == 2 {
									a1a.X = v3.X
									a1a.Y = a2a.X
									if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
										c.sub_499130(a1a)
									}
								} else {
									a1a.X = v3.X
									v22 = float32(float64(a1a.X) * float64(v28))
									a1a.Y = v16 + int32(v22)
									if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
										c.sub_499130(a1a)
									}
								}
							}
							if int32(v37) == 1 || int32(v37) == 2 {
								if int32(v38) == 1 || int32(v38) == 2 {
									goto LABEL_65
								}
								v25 = float32(float64(v31-v16) / float64(v28))
								v17 = int32(v25)
								v18 = v3.Y
								a1a.X = v17
								a1a.Y = v18
								if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
									c.sub_499130(a1a)
								}
								goto LABEL_65
							}
							if v29 != v28 {
								v39 = float32(float64(v31 - v16))
								v30 = v28 - v29
								v23 = v39 / v30
								a1a.X = int32(v23)
								v24 = v39 * v28 / v30
								a1a.Y = v16 + int32(v24)
								if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
									c.sub_499130(a1a)
									goto LABEL_65
								}
							}
						}
					}
				}
			}
		LABEL_65:
			v7 = c.dword_5d4594_1217464_size
			v32++
			if v32 >= c.dword_5d4594_1217464_size {
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
	var (
		result int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
	)
	result = 0
	v7 = 0
	v8 := 0
	if c.dword_5d4594_1217464_size <= 0 {
		return 0
	}
	v3 := c.dword_5d4594_1217464_size*8 - 8
	for v8 < c.dword_5d4594_1217464_size {
		v4 = c.arr_5d4594_1203876[v3/8].X
		v5 = c.arr_5d4594_1203876[v3/8].Y
		v6 = c.arr_5d4594_1203876[v8].Y
		if v6 > int32(a2) {
			if v5 > int32(a2) {
				v3 = func() int {
					p := &v8
					x := *p
					*p++
					return x
				}() * 8
				continue
			}
		} else if int32(a2) < v5 {
			goto LABEL_8
		}
		if int32(a2) >= v6 {
			v3 = func() int {
				p := &v8
				x := *p
				*p++
				return x
			}() * 8
			continue
		}
	LABEL_8:
		if int32(a1) >= c.arr_5d4594_1203876[v8].X+(int32(a2)-v6)*(v4-c.arr_5d4594_1203876[v8].X)/(v5-v6) {
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
	return int(result)
}

func (c *clientSight) sub_498130(a1 *SightStructXxx) {
	for i := c.sub_498290(a1); i < c.sightStructArrSize; i++ {
		v2 := c.sightStructArr[i]
		if v2.Field40 > a1.Field44 {
			break
		}
		c.sub_498380(a1, c.sightStructArr[i])
		if int32(a1.Field48) == 0 || a1.Field44-a1.Field40 < 0 {
			c.sub_4CAE40(a1)
			return
		}
		if int32(v2.Field48) == 0 || v2.Field44-v2.Field40 < 0 {
			if c.sub_4982E0(v2) <= i {
				i--
			}
			c.sub_4CAE40(v2)
		}
	}
	c.sub_4981D0(a1)
}
func (c *clientSight) sub_4981D0(a1 *SightStructXxx) {
	v1 := c.sightStructArrSize - 1
	v2 := 0
	for v2 <= v1 {
		ind := (v1 + v2) / 2
		if c.sightStructArr[ind].Field40 >= a1.Field40 {
			v1 = ind - 1
		} else {
			v2 = ind + 1
		}
	}
	c.sub_498220(a1, v2)
}
func (c *clientSight) sub_498220(a1 *SightStructXxx, a2 int) {
	if a2 < c.sightStructArrSize {
		copy(c.sightStructArr[a2+1:], c.sightStructArr[a2:c.sightStructArrSize])
	}
	c.sightStructArr[a2] = a1
	c.sightStructArrSize++
}
func (c *clientSight) sub_498290(a1 *SightStructXxx) int {
	v1 := 0
	v2 := c.sightStructArrSize - 1
	if c.sightStructArrSize-1 < 0 {
		return 0
	}
	for {
		ind := (v2 + v1) / 2
		if c.sightStructArr[ind].Field44 >= a1.Field40 {
			v2 = ind - 1
		} else {
			v1 = ind + 1
		}
		if v1 > v2 {
			if v2 >= 0 {
				return v2
			} else {
				return 0
			}
		}
	}
}
func (c *clientSight) sub_4982E0(p *SightStructXxx) int {
	ind := c.sub_498330(p)
	copy(c.sightStructArr[ind:], c.sightStructArr[ind+1:c.sightStructArrSize])
	c.sightStructArrSize--
	return ind
}
func (c *clientSight) sub_498330(a1 *SightStructXxx) int {
	v1 := a1.Field40
	v2 := 0
	v3 := c.sightStructArrSize - 1
	for {
		ind := (v3 + v2) / 2
		v5 := c.sightStructArr[ind].Field40
		if v5 == v1 {
			return ind
		}
		if v5 >= v1 {
			v3 = (v3 + v2) / 2
		} else {
			v2 = ind + 1
		}
		if v2 > v3 {
			panic(-1)
		}
	}
}
func (c *clientSight) Sub_498110() {
	for it := c.sub_4CAEB0(); it != nil; it = c.sub_4CAEB0() {
		c.sub_498130(it)
	}
}
func (c *clientSight) sub_4CAEB0() *SightStructXxx {
	res := c.dword_5d4594_1522596
	if c.dword_5d4594_1522596 != nil {
		c.dword_5d4594_1522596 = c.dword_5d4594_1522596.Field12
	}
	return res
}
func (c *clientSight) sub_4CAE90(a1 *SightStructXxx) {
	a1.Field12 = c.dword_5d4594_1522596
	c.dword_5d4594_1522596 = a1
}
func (c *clientSight) Free() int32 {
	if c.sightStructArr != nil {
		alloc.FreeSlice(c.sightStructArr)
		c.sightStructArr = nil
	}
	return 1
}
func (c *clientSight) Init(w, h int) int32 {
	c.sightStructArr, _ = alloc.Make([]*SightStructXxx{}, uintptr(w*4/23*(h/23)/2))
	if c.sightStructArr == nil {
		return 0
	}
	c.sub_4CA860()
	return 1
}
func (c *clientSight) sub_4CA860() {
	ca := *memmap.PtrFloat64(0x581450, 9960)
	cb := *memmap.PtrFloat64(0x581450, 9952)
	for i := range c.arr_5d4594_1322584 {
		v1 := int64(math.Atan2(float64(i)*ca, 1.0)*cb + 0.5)
		c.arr_5d4594_1322584[i] = int16(v1)
	}
}
func (c *clientSight) sub_4CAED0(a1 *SightStructXxx) *SightStructXxx {
	p := c.sub_4CADD0()
	p.GridPos24 = a1.GridPos24
	p.Field32 = a1.Field32
	p.Field36 = a1.Field36
	p.Field40 = a1.Field40
	p.Field44 = a1.Field44
	p.Field48 = a1.Field48
	p.Field56 = a1.Field56
	p.Obj20 = a1.Obj20
	return p
}

type SightStructXxx struct {
	Field0    uint32          // 0, 0
	Field4    uint32          // 1, 4
	Field8    *SightStructXxx // 2, 8
	Field12   *SightStructXxx // 3, 12
	Field16   *SightStructXxx // 4, 16
	Obj20     *Drawable       // 5, 20
	GridPos24 ntype.Point32   // 6, 24
	Field32   int32           // 8, 32
	Field36   byte            // 9, 36
	Field37   byte            // 9, 37
	Field38   uint16          // 9, 38
	Field40   int32           // 10, 40
	Field44   int32           // 11, 44
	Field48   byte            // 12, 48
	Field49   byte            // 12, 49
	Field50   uint16          // 12, 50
	Field52   uint32          // 13, 52
	Field56   byte            // 14, 56
	Field57   byte            // 14, 57
	Field58   uint16          // 14, 58
}

func (c *clientSight) sub_4CADD0() *SightStructXxx {
	result := c.dword_5d4594_1522584
	if c.dword_5d4594_1522584 == nil {
		for i := 0; i < 10; i++ {
			p, _ := alloc.New(SightStructXxx{})
			p.Field16 = c.dword_5d4594_1522584
			c.dword_5d4594_1522584 = p
			p.Field8 = c.dword_5d4594_1522592
			c.dword_5d4594_1522592 = p
		}
		c.dword_5d4594_1522588 += 10
		result = c.dword_5d4594_1522584
	}
	c.dword_5d4594_1522584 = result.Field16
	return result
}
func (c *clientSight) nox_xxx_drawBlackofWall_497C40(a1 int32, a2 int32, a3 int8) {
	v21 := a1 * 23
	v22 := a2 * 23
	v3 := a1*23 + 11
	v4 := a2*23 + 11
	v5 := c.sub_4CADD0()
	v5.GridPos24.X = a1
	v5.GridPos24.Y = a2
	v5.Field36 = uint8(a3)
	v5.Field48 = 1
	v5.Field56 = 0
	var v6, v7, v8, v9, v23 int32
	var v24 int32 // FIXME: uninitialized!
	switch a3 {
	case 1:
		v6 = int32(v3) - c.dword_5d4594_1217444_vec.X + 5
		v7 = int32(v4) - c.dword_5d4594_1217444_vec.Y - 5
		v8 = v3
		v9 = a2 * 23
		v23 = v21 + 23
	case 2:
		v6 = int32(v3) - c.dword_5d4594_1217444_vec.X - 5
		v7 = int32(v4) - c.dword_5d4594_1217444_vec.Y - 5
		v8 = v3
		v9 = a2 * 23
		v23 = a1 * 23
	case 4:
		v6 = int32(v3) - c.dword_5d4594_1217444_vec.X + 5
		v10 := 5
		v8 = v3
		v7 = int32(v4) - c.dword_5d4594_1217444_vec.Y + int32(v10)
		v23 = v21 + 23
		v9 = v22 + 23
	case 6:
		v8 = a1 * 23
		v7 = int32(v4) - c.dword_5d4594_1217444_vec.Y
		v4 = a2 * 23
		v6 = int32(v3) - c.dword_5d4594_1217444_vec.X
		v23 = v21 + 23
		v9 = v22 + 23
	case 8:
		v6 = int32(v3) - c.dword_5d4594_1217444_vec.X - 5
		v23 = a1 * 23
		v7 = int32(v4) - c.dword_5d4594_1217444_vec.Y + 5
		v8 = v3
		v9 = v22 + 23
	case 9:
		v6 = int32(v3) - c.dword_5d4594_1217444_vec.X
		v7 = int32(v4) - c.dword_5d4594_1217444_vec.Y
		v4 = a2 * 23
		v8 = v21 + 23
		v23 = a1 * 23
		v9 = v22 + 23
	default:
		v6 = a1
		v7 = a1
		v4 = v24
		v8 = v23
		v9 = v24
	}
	v5.Field32 = v6*v6 + v7*v7
	v11 := c.sub_4CA8B0(int32(v4)-c.dword_5d4594_1217444_vec.Y, int32(v8)-c.dword_5d4594_1217444_vec.X)
	v5.Field40 = v11
	if v11 < 0 {
		for {
			v12 := v5.Field40
			v5.Field40 = v12 + 75000
			if v5.Field40 >= 0 {
				break
			}
		}
	}
	if v5.Field40 >= 75000 {
		for {
			v13 := v5.Field40 - 75000
			v5.Field40 = v13
			if v13 < 75000 {
				break
			}
		}
	}
	v14 := c.sub_4CA8B0(int32(v9)-c.dword_5d4594_1217444_vec.Y, int32(v23)-c.dword_5d4594_1217444_vec.X)
	v5.Field44 = v14
	if v14 < 0 {
		for {
			v15 := v5.Field44
			v5.Field44 = v15 + 75000
			if v15+75000 >= 0 {
				break
			}
		}
	}
	if v5.Field44 >= 75000 {
		for {
			v16 := v5.Field44 - 75000
			v5.Field44 = v16
			if v16 < 75000 {
				break
			}
		}
	}
	v17 := v5.Field44
	v18 := v5.Field40
	if v17 < v18 {
		v5.Field40 = v17
		v5.Field44 = v18
	}
	if v5.Field44-v5.Field40 < 37500 {
		c.sub_4CAE90(v5)
		return
	}
	v19 := c.sub_4CAED0(v5)
	v19.Field40 = 0
	v19.Field44 = v5.Field40
	v5.Field40 = v5.Field44
	v5.Field44 = 74999
	c.sub_4CAE90(v19)
	c.sub_4CAE90(v5)
}
func (c *clientSight) Sub_4974B0(a1 *Drawable) {
	var (
		v3  int32
		v4  float64
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v14 float32
		v15 int32
	)
	v1 := a1
	if (a1.SubClass() & 4) == 0 {
		v2 := c.sub_4CADD0()
		v2.Field48 = 1
		v2.Field56 = 6
		v2.Obj20 = a1
		v3 = int32(a1.Field_74_4) * 8
		v4 = float64(int32(c.dword_5d4594_1217444_vec.X - int32(*memmap.PtrInt32(0x587000, uintptr(v3)+196184)/2) - int32(a1.PosVec.X)))
		v15 = c.dword_5d4594_1217444_vec.Y - int32(*memmap.PtrInt32(0x587000, uintptr(v3)+196188)/2) - int32(a1.PosVec.Y)
		v14 = float32(float64(v15)*float64(v15) + v4*v4)
		v2.Field32 = int32(v14)
		v5 = c.sub_4CA8B0(int32(v1.PosVec.Y-int(c.dword_5d4594_1217444_vec.Y)), int32(v1.PosVec.X-int(c.dword_5d4594_1217444_vec.X)))
		v2.Field40 = v5
		if v5 < 0 {
			for {
				v6 = v2.Field40
				v2.Field40 = v6 + 75000
				if v6+75000 >= 0 {
					break
				}
			}
		}
		if v2.Field40 >= 75000 {
			for {
				v7 = v2.Field40 - 75000
				v2.Field40 = v7
				if v7 < 75000 {
					break
				}
			}
		}
		v8 = c.sub_4CA8B0(int32(v1.PosVec.Y+int(int32(*memmap.PtrInt32(0x587000, uintptr(int32(v1.Field_74_4)*8)+196188)))-int(c.dword_5d4594_1217444_vec.Y)), int32(v1.PosVec.X+int(int32(*memmap.PtrInt32(0x587000, uintptr(int32(v1.Field_74_4)*8)+196184)))-int(c.dword_5d4594_1217444_vec.X)))
		v2.Field44 = v8
		if v8 < 0 {
			for {
				v9 = v2.Field44
				v2.Field44 = v9 + 75000
				if v9+75000 >= 0 {
					break
				}
			}
		}
		if v2.Field44 >= 75000 {
			for {
				v10 = v2.Field44 - 75000
				v2.Field44 = v10
				if v10 < 75000 {
					break
				}
			}
		}
		v11 = v2.Field44
		v12 = v2.Field40
		if v11 < v12 {
			v2.Field40 = v11
			v2.Field44 = v12
		}
		if float64(int32(v2.Field44-v2.Field40)) >= 37500.0 {
			v13 := c.sub_4CAED0(v2)
			v13.Field40 = 0
			v13.Field44 = v2.Field40
			v2.Field40 = v2.Field44
			v2.Field44 = 74999
			c.sub_4CAE90(v13)
		}
		c.sub_4CAE90(v2)
	}
}
func (c *clientSight) Sub_497650(a1 *Drawable) {
	var (
		v4  int32
		v5  float64
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v21 float32
		v22 int32
		v23 float32
		v24 float32
	)
	v1 := c.sub_4CADD0()
	v2 := a1
	v3 := v1
	v1.Field48 = 1
	v1.Field56 = 7
	v1.Obj20 = a1
	v4 = int32(a1.PosVec.Y)
	v24 = float32(float64(int32(a1.PosVec.X - int(c.dword_5d4594_1217444_vec.X))))
	v5 = float64(int32(int32(v4) - c.dword_5d4594_1217444_vec.Y))
	v23 = float32(v5)
	v21 = float32(v5*float64(v23) + float64(v24*v24))
	v6 = int32(v21)
	v3.Field32 = v6
	v7 = int32(int64(math.Sqrt(float64(v6))))
	v22 = int32(v24)
	v8 = int32(v23)
	v9 = c.sub_4CA8B0(v8, v22)
	v10 = int32(v2.Shape.Circle.R)
	v11 = c.sub_4CA8B0(v10, v7)
	v3.Field40 = v11 + v9
	if v11+v9 < 0 {
		for {
			v12 = v3.Field40
			v3.Field40 = v12 + 75000
			if v12+75000 >= 0 {
				break
			}
		}
	}
	if v3.Field40 >= 75000 {
		for {
			v13 = v3.Field40 - 75000
			v3.Field40 = v13
			if v13 < 75000 {
				break
			}
		}
	}
	v14 = v9 - v11
	v3.Field44 = v14
	if v14 < 0 {
		for {
			v15 = v3.Field44
			v3.Field44 = v15 + 75000
			if v15+75000 >= 0 {
				break
			}
		}
	}
	if v3.Field44 >= 75000 {
		for {
			v16 = v3.Field44 - 75000
			v3.Field44 = v16
			if v16 < 75000 {
				break
			}
		}
	}
	v17 = v3.Field44
	v18 = v3.Field40
	if v17 < v18 {
		v3.Field40 = v17
		v3.Field44 = v18
	}
	if float64(v3.Field44-v3.Field40) < 37500.0 {
		c.sub_4CAE90(v3)
		return
	}
	v19 := c.sub_4CAED0(v3)
	v19.Field40 = 0
	v19.Field44 = v3.Field40
	v3.Field40 = v3.Field44
	v3.Field44 = 74999
	c.sub_4CAE90(v19)
	c.sub_4CAE90(v3)
}
func (c *clientSight) Sub_4977C0(a1 *Drawable) {
	var (
		v2     float64
		v3     float64
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		result int32
		v12    float64
		v13    int32
		v14    float64
		v15    int32
		v16    float64
		v17    int32
		v18    float64
		v19    int32
		v20    float64
		v21    int32
		v22    float64
		v23    int32
		v24    float32
		v25    float32
		v26    float32
		v27    float32
		v28    float32
		v29    float32
		v30    int32
		v31    int32
		v32    int32
		v33    int32
		v34    float32
		v35    float32
		v36    float32
		v37    float32
		v38    [8]float32
		v39    float32
		v40    int32
	)
	v1 := a1
	v2 = float64(a1.PosVec.X)
	v38[0] = float32(v2 + float64(a1.Shape.Box.LeftTop))
	v3 = float64(a1.PosVec.Y)
	v39 = float32(v3)
	v38[1] = float32(v3 + float64(v1.Shape.Box.LeftBottom))
	v38[2] = float32(v2 + float64(v1.Shape.Box.LeftBottom2))
	v38[3] = v39 + v1.Shape.Box.LeftTop2
	v38[4] = float32(v2 + float64(v1.Shape.Box.RightTop))
	v38[5] = v39 + v1.Shape.Box.RightBottom
	v38[6] = float32(v2 + float64(v1.Shape.Box.RightBottom2))
	v38[7] = v39 + v1.Shape.Box.RightTop2
	v30 = int32(int32(v38[0])) - c.dword_5d4594_1217444_vec.X
	v4 = int32(v38[1])
	v5 = c.sub_4CA8B0(int32(v4)-c.dword_5d4594_1217444_vec.Y, v30)
	v31 = int32(int32(v38[2])) - c.dword_5d4594_1217444_vec.X
	v6 = int32(v38[3])
	v7 = c.sub_4CA8B0(int32(v6)-c.dword_5d4594_1217444_vec.Y, v31)
	v32 = int32(int32(v38[4])) - c.dword_5d4594_1217444_vec.X
	v8 = int32(v38[5])
	v9 = c.sub_4CA8B0(int32(v8)-c.dword_5d4594_1217444_vec.Y, v32)
	v33 = int32(int32(v38[6])) - c.dword_5d4594_1217444_vec.X
	v10 = int32(v38[7])
	v40 = c.sub_4CA8B0(int32(v10)-c.dword_5d4594_1217444_vec.Y, v33)
	result = int32(uint8(sub_497B80(&v38, &c.dword_5d4594_1217444_vec))) - 1
	switch result {
	case 0:
		v35 = float32(float64(v38[5]+v38[1]) * 0.5)
		v14 = float64(v38[4]+v38[0])*0.5 - float64(c.dword_5d4594_1217444_vec.X)
		v25 = float32((float64(v35)-float64(c.dword_5d4594_1217444_vec.Y))*(float64(v35)-float64(c.dword_5d4594_1217444_vec.Y)) + v14*v14)
		v15 = int32(v25)
		c.sub_497F60(v5, v9, 9, v15, v1)
	case 1:
		v37 = float32(float64(v38[7]+v38[3]) * 0.5)
		v18 = float64(v38[6]+v38[2])*0.5 - float64(c.dword_5d4594_1217444_vec.X)
		v27 = float32((float64(v37)-float64(c.dword_5d4594_1217444_vec.Y))*(float64(v37)-float64(c.dword_5d4594_1217444_vec.Y)) + v18*v18)
		v19 = int32(v27)
		c.sub_497F60(v40, v7, 10, v19, v1)
	case 3:
		v34 = float32(float64(v38[3]+v38[1]) * 0.5)
		v12 = float64(v38[2]+v38[0])*0.5 - float64(c.dword_5d4594_1217444_vec.X)
		v24 = float32((float64(v34)-float64(c.dword_5d4594_1217444_vec.Y))*(float64(v34)-float64(c.dword_5d4594_1217444_vec.Y)) + v12*v12)
		v13 = int32(v24)
		c.sub_497F60(v5, v7, 8, v13, v1)
	case 4, 9:
		v22 = float64(int32(v1.PosVec.X - int(c.dword_5d4594_1217444_vec.X)))
		v29 = float32(float64(int32(v1.PosVec.Y-int(c.dword_5d4594_1217444_vec.Y)))*float64(int32(v1.PosVec.Y-int(c.dword_5d4594_1217444_vec.Y))) + v22*v22)
		v23 = int32(v29)
		c.sub_497F60(v7, v9, 14, v23, v1)
	case 5, 8:
		v20 = float64(int32(v1.PosVec.X - int(c.dword_5d4594_1217444_vec.X)))
		v28 = float32(float64(int32(v1.PosVec.Y-int(c.dword_5d4594_1217444_vec.Y)))*float64(int32(v1.PosVec.Y-int(c.dword_5d4594_1217444_vec.Y))) + v20*v20)
		v21 = int32(v28)
		c.sub_497F60(v5, v40, 13, v21, v1)
	case 7:
		v36 = float32(float64(v38[7]+v38[5]) * 0.5)
		v16 = float64(v38[6]+v38[4])*0.5 - float64(c.dword_5d4594_1217444_vec.X)
		v26 = float32((float64(v36)-float64(c.dword_5d4594_1217444_vec.Y))*(float64(v36)-float64(c.dword_5d4594_1217444_vec.Y)) + v16*v16)
		v17 = int32(v26)
		c.sub_497F60(v40, v9, 11, v17, v1)
	}
}
func (c *clientSight) Sub_498030(a1 *noxrender.Viewport) {
	v1 := int32(a1.World.Min.X)
	v2 := int32(a1.World.Min.Y)
	v3 := int32(a1.Size.X + int(uint32(v1)))
	v4 := int32(a1.Size.Y + int(uint32(v2)))
	v9 := c.sub_4CA8B0(int32(v2)-c.dword_5d4594_1217444_vec.Y, int32(v1)-c.dword_5d4594_1217444_vec.X)
	v5 := c.sub_4CA8B0(int32(v2)-c.dword_5d4594_1217444_vec.Y, int32(v3)-c.dword_5d4594_1217444_vec.X)
	v6 := c.sub_4CA8B0(int32(v4)-c.dword_5d4594_1217444_vec.Y, int32(v3)-c.dword_5d4594_1217444_vec.X)
	v7 := c.sub_4CA8B0(int32(v4)-c.dword_5d4594_1217444_vec.Y, int32(v1)-c.dword_5d4594_1217444_vec.X)
	c.sub_497F60(v9, v5, 1, math.MaxInt32, nil)
	c.sub_497F60(v5, v6, 4, math.MaxInt32, nil)
	c.sub_497F60(v6, v7, 2, math.MaxInt32, nil)
	c.sub_497F60(v7, v9, 3, math.MaxInt32, nil)
}

func sub_497B80(a1 *[8]float32, a2 *ntype.Point32) int8 {
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

func (c *clientSight) sub_4CA8B0(a1 int32, a2 int32) int32 {
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
	if ind >= len(c.arr_5d4594_1322584) {
		ind = len(c.arr_5d4594_1322584) - 1
	}
	res := int32(c.arr_5d4594_1322584[ind])
	switch v6 {
	case 2:
		return 37500 - res
	case 3:
		return res + 37500
	case 4:
		return 75000 - res
	}
	return res
}
func sub_4CA960(gpos ntype.Point32, a2 int8, a3 types.Rectf) types.Pointf {
	pos := ntype.Point32{
		X: gpos.X * common.GridStep,
		Y: gpos.Y * common.GridStep,
	}
	switch a2 {
	case 1:
		return sub_4CAA90(pos, a3, common.GridStep/2, common.GridStep)
	case 2:
		return sub_4CAC30(pos, a3, 0, common.GridStep/2)
	case 4:
		return sub_4CAC30(pos, a3, common.GridStep/2, common.GridStep)
	case 6:
		return sub_4CAC30(pos, a3, 0, common.GridStep)
	case 8:
		return sub_4CAA90(pos, a3, 0, common.GridStep/2)
	case 9:
		return sub_4CAA90(pos, a3, 0, common.GridStep)
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
		if float64(v19) < *memmap.PtrFloat64(0x581450, 9968) {
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
func (c *clientSight) sub_499130(a1 ntype.Point32) {
	if c.dword_5d4594_1217452 >= len(c.arr_5d4594_1212068) {
		return
	}
	c.arr_5d4594_1212068[c.dword_5d4594_1217452] = a1
	c.dword_5d4594_1217452++
}
func (c *clientSight) Sub_499290(a1 int) ntype.Point32 {
	return c.arr_5d4594_1212068[a1]
}
func (c *clientSight) sub_4991E0(a1 *ntype.Point32) {
	v1 := c.dword_5d4594_1217452
	if c.dword_5d4594_1217452 > 0 {
		v2 := a1
		v3 := 1
		v12 := 1
		for {
			v4 := &c.arr_5d4594_1212068[v3-1]
			v5 := v4.Y - v2.Y
			v6 := (v4.X-v2.X)*(v4.X-v2.X) + int32(v5*v5)
			if v3 < v1 {
				for i := 0; i < v1-v3; i++ {
					v7 := &c.arr_5d4594_1212068[v3+i]
					v8 := v7.Y - v2.Y
					v9 := (v7.X-v2.X)*(v7.X-v2.X) + int32(v8*v8)
					if v9 < v6 {
						v10 := int32(v4.Y)
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
}
func sub_4990D0(a1 *ntype.Point32, a2 *ntype.Point32) int8 {
	if a1.X <= a2.X {
		if a1.X >= a2.X {
			v7 := int32(a1.Y)
			v8 := int32(a2.Y)
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
			v5 := int32(a1.Y)
			v6 := int32(a2.Y)
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
		v2 := int32(a1.Y)
		v3 := int32(a2.Y)
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
func sub_499160(a1 *ntype.Point32, a2 *ntype.Point32, a3 *ntype.Point32) int32 {
	var (
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		result int32
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
	result = 0
	if !(a1.X >= v6 && a1.X <= v3) {
		return result
	}
	v7 = a1.Y
	if v7 >= v4 && v7 <= v5 {
		result = 1
	}
	return result
}
func (c *clientSight) sub_497F60(a1 int32, a2 int32, a3 int8, a4 int32, a5 *Drawable) {
	v5 := c.sub_4CADD0()
	v5.Field56 = uint8(a3)
	v5.Field32 = a4
	v5.Field48 = 1
	v5.Obj20 = a5
	if a2 >= a1 {
		v5.Field40 = a1
		v5.Field44 = a2
	} else {
		v5.Field40 = a2
		v5.Field44 = a1
	}
	if v5.Field40 < 0 {
		for {
			v6 := int32(v5.Field40)
			v5.Field40 = v6 + 75000
			if v6+75000 >= 0 {
				break
			}
		}
	}
	if v5.Field40 >= 75000 {
		for {
			v7 := int32(v5.Field40 - 75000)
			v5.Field40 = v7
			if v7 < 75000 {
				break
			}
		}
	}
	if v5.Field44 < 0 {
		for {
			v8 := int32(v5.Field44)
			v5.Field44 = v8 + 75000
			if v8+75000 >= 0 {
				break
			}
		}
	}
	if v5.Field44 >= 75000 {
		for {
			v9 := int32(v5.Field44 - 75000)
			v5.Field44 = v9
			if v9 < 75000 {
				break
			}
		}
	}
	if v5.Field44-v5.Field40 < 37500 {
		c.sub_4CAE90(v5)
		return
	}
	v10 := c.sub_4CAED0(v5)
	v10.Field40 = 0
	v10.Field44 = v5.Field40
	v5.Field40 = v5.Field44
	v5.Field44 = 74999
	c.sub_4CAE90(v10)
	c.sub_4CAE90(v5)
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
		if float64(v14) < *memmap.PtrFloat64(0x581450, 9968) {
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
func sub_414C50(a1 int32) int32 {
	v1 := sub_414BD0(a1)
	v2 := sub_414BD0(6434 - a1)
	if v2 != 0 {
		return (v1 << 12) / v2
	} else {
		v3 := 0
		if v1 <= 0 {
			v3 = 1
		}
		return int32(v3) + math.MaxInt32
	}
}
func sub_414BD0(a1 int32) int32 {
	v1 := a1
	if a1 < 0 {
		v1 = a1 + ((25735-a1)/25736)*25736
	}
	if v1 >= 25736 {
		v1 %= 25736
	}
	return memmap.Int32(0x85B3FC, uintptr(((v1<<12)/25736)*4+12260))
}
func sub_57BA30(p1, p2 *image.Point, a3 *image.Rectangle) int {
	swap := false
	for {
		var fx byte
		if p1.X < a3.Min.X {
			fx |= 8
		} else if p1.X > a3.Max.X {
			fx |= 4
		}
		if p1.Y < a3.Min.Y {
			fx |= 2
		} else if p1.Y > a3.Max.Y {
			fx |= 1
		}
		var fy byte
		if p2.X < a3.Min.X {
			fy |= 8
		} else if p2.X > a3.Max.X {
			fy |= 4
		}
		if p2.Y < a3.Min.Y {
			fy |= 2
		} else if p2.Y > a3.Max.Y {
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
			p1.X += (a3.Max.Y - p1.Y) * (p2.X - p1.X) / (p2.Y - p1.Y)
			p1.Y = a3.Max.Y
		} else if fx&2 != 0 {
			p1.X += (a3.Min.Y - p1.Y) * (p2.X - p1.X) / (p2.Y - p1.Y)
			p1.Y = a3.Min.Y
		} else if fx&4 != 0 {
			p1.Y += (a3.Max.X - p1.X) * (p2.Y - p1.Y) / (p2.X - p1.X)
			p1.X = a3.Max.X
		} else if fx&8 != 0 {
			p1.Y += (a3.Min.X - p1.X) * (p2.Y - p1.Y) / (p2.X - p1.X)
			p1.X = a3.Min.X
		}
	}
}
func (c *clientSight) sub_498380(a1 *SightStructXxx, a2 *SightStructXxx) {
	var (
		v6  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 bool
		v13 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
	)
	v2 := int32(a1.Field40)
	v3 := int32(a2.Field44)
	if v3 < v2 {
		return
	}
	v4 := int32(a2.Field40)
	v5 := int32(a1.Field44)
	if v4 > v5 {
		return
	}
	if v4 < v2 {
		if v3 <= v5 {
			if a1.Field32 >= a2.Field32 {
				v6 = a1.Field44
				a1.Field40 = v3 + 1
				if v3+1 > v6 {
					a1.Field48 = 0
				}
			} else {
				a2.Field44 = v2 - 1
			}
			return
		}
		if a1.Field32 < a2.Field32 {
			v7 := c.sub_4CAED0(a2)
			v8 = v7.Field44
			v9 = a1.Field44 + 1
			v7.Field40 = v9
			if v9 > v8 {
				v7.Field48 = 0
			}
			v10 = a1.Field40 - 1
			v11 = a2.Field40
			a2.Field44 = v10
			if v11 > v10 {
				a2.Field48 = 0
			}
			c.sub_4CAE90(v7)
			return
		}
		a1.Field48 = 0
		return
	}
	v12 = v3 <= v5
	v13 = a1.Field32
	if v12 {
		if v13 >= a2.Field32 {
			v14 := c.sub_4CAED0(a1)
			v15 = v14.Field44
			v16 = a2.Field44 + 1
			v14.Field40 = v16
			if v16 > v15 {
				v14.Field48 = 0
			}
			v17 = a2.Field40 - 1
			v18 = a1.Field40
			a1.Field44 = v17
			if v18 > v17 {
				a1.Field48 = 0
			}
			c.sub_4CAE90(v14)
		} else {
			a2.Field48 = 0
		}
	} else {
		if v13 >= a2.Field32 {
			v21 = v4 - 1
			v22 = a1.Field40
			a1.Field44 = v21
			if v22 <= v21 {
				return
			}
			a1.Field48 = 0
			return
		}
		v19 = a2.Field44
		v20 = v5 + 1
		a2.Field40 = v20
		if v20 > v19 {
			a2.Field48 = 0
		}
	}
}
func (c *clientSight) sub_4CAE40(a1 *SightStructXxx) {
	a1.Field16 = c.dword_5d4594_1522584
	c.dword_5d4594_1522584 = a1
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

func (c *clientSight) Nox_xxx_drawBlack_496150_C() []ntype.Point32 {
	c.sub_4989A0()
	return c.arr_5d4594_1203876[:c.dword_5d4594_1217464_size]
}
func (c *clientSight) sub_4989A0() {
	arr := c.arr_5d4594_1203876[:c.dword_5d4594_1217464_size]
	if len(arr) < 3 {
		return
	}

	barr := c.arr_5d4594_1212324[:]
	iarr := c.arr_5d4594_1213348[:]

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
	c.dword_5d4594_1217464_size = j + 1
}
