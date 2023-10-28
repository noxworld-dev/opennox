//go:build !server

package opennox

import (
	"image"
	"image/color"
	"math"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
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
)

func sub_4CAE60() {
	var v1 *SightStructXxx
	dword_5d4594_1522584 = nil
	for it := dword_5d4594_1522592; it != nil; it = it.Field8 {
		it.Field16 = v1
		v1 = it
		dword_5d4594_1522584 = it
	}
}

func (c *Client) nox_xxx_drawBlack_496150(vp *noxrender.Viewport) {
	sub_4CAE60()
	dword_5d4594_1217464_size = 0
	sightStructArrSize = 0
	v1 := int32(vp.World.Min.X)
	v2 := int32(vp.World.Min.Y)
	v3 := int32(vp.Size.X)
	v79 := v1 / 23
	v80 := v2 / 23
	v74 := (v3+v1)/23 - v1/23
	v4 := int32((vp.Size.Y+int(v2))/23 - int(v2/23))
	dword_5d4594_1217444_vec.X = v1 + v3/2
	dword_5d4594_1217444_vec.Y = int32(uint32(vp.World.Min.Y + vp.Jiggle12 + vp.Size.Y/2))
	sub_498030(vp)
	c.sub_497260(vp)
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
				wl := c.srv.Walls.GetWallAtGrid(image.Pt(int(gx), int(gy)))
				if wl == nil {
					continue
				}
				v10 := uint8(c.srv.Sub_57B500(image.Pt(int(gx), int(gy)), 64))
				if int32(v10) == math.MaxUint8 {
					continue
				}
				def := c.srv.Walls.DefByInd(int(wl.Tile1))
				if def.Flags32&1 == 0 {
					wl.Flags4 |= 1
					if int32(wl.Y6)*23 <= dword_5d4594_1217444_vec.Y {
						wl.Flags4 &^= 2
					} else {
						wl.Flags4 |= 2
					}
					if def.Flags32&4 != 0 {
						nox_xxx_drawList1096512_Append_4754C0(wl)
					}
				} else {
					if wl.Flags4&0x40 != 0 {
						if (dword_5d4594_1217444_vec.X-v69-11)*(dword_5d4594_1217444_vec.X-v69-11)+(dword_5d4594_1217444_vec.Y-v70-11)*(dword_5d4594_1217444_vec.Y-v70-11) < 3600 {
							wl.Flags4 |= 1
							continue
						}
					}
					if v10 == 0 {
						nox_xxx_drawBlackofWall_497C40(gx, gy, 9)
					} else if v10 == 1 {
						nox_xxx_drawBlackofWall_497C40(gx, gy, 6)
					} else {
						v16 := memmap.Uint8(0x587000, uintptr(v10)+161764)
						if int32(v16)&2 != 0 {
							nox_xxx_drawBlackofWall_497C40(gx, gy, 2)
						}
						if int32(v16)&1 != 0 {
							nox_xxx_drawBlackofWall_497C40(gx, gy, 1)
						}
						if int32(v16)&8 != 0 {
							nox_xxx_drawBlackofWall_497C40(gx, gy, 8)
						}
						if int32(v16)&4 != 0 {
							nox_xxx_drawBlackofWall_497C40(gx, gy, 4)
						}
					}
				}
			}
		}
	}
	sub_498110()
	var brect types.Rectf
	brect.Min.X = float32(dword_5d4594_1217444_vec.X)
	brect.Min.Y = float32(dword_5d4594_1217444_vec.Y)
	v51 := dword_5d4594_1217464_size
	if sightStructArrSize > 0 {
		for i := 0; i < sightStructArrSize; i++ {
			v18 := int32(0)
			ss := sightStructArr[i]
			var pp1, pp2 types.Pointf
			switch ss.Field56 {
			case 0:
				v20 := (ss.Field40 * 25736) / 75000
				v21 := (ss.Field44 * 25736) / 75000

				brect.Max.X = float32(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v20))
				brect.Max.Y = float32(dword_5d4594_1217444_vec.Y + sub_414BD0(v20))
				pp1 = sub_4CA960(ss.GridPos24, int8(ss.Field36), brect)

				brect.Max.X = float32(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v21))
				brect.Max.Y = float32(dword_5d4594_1217444_vec.Y + sub_414BD0(v21))
				pp2 = sub_4CA960(ss.GridPos24, int8(ss.Field36), brect)

				wl := c.srv.Walls.GetWallAtGrid(image.Pt(int(ss.GridPos24.X), int(ss.GridPos24.Y)))
				wl.Field12 = 1
				wl.Flags4 |= 1
				if pp2.X < pp1.X {
					wl.Flags4 |= 2
				}
				wl.Field3 |= ss.Field36
				v18 = ss.GridPos24.X + (ss.GridPos24.Y << 8)
			case 1:
				pp1.X = float32(dword_5d4594_1217444_vec.X + sub_414C50((ss.Field40*25736)/75000-19302)*int32(vp.Size.Y/2)/4096)
				pp1.Y = float32(vp.World.Min.Y)
				pp2.X = float32(dword_5d4594_1217444_vec.X + sub_414C50((ss.Field44*25736)/75000-19302)*int32(vp.Size.Y/2)/4096)
				pp2.Y = float32(vp.World.Min.Y)
				v18 = 0
			case 2:
				pp1.X = float32(dword_5d4594_1217444_vec.X - sub_414C50((ss.Field40*25736)/75000-6434)*(int32(vp.Size.Y)/2)/4096)
				pp1.Y = float32(vp.World.Min.Y + vp.Size.Y - 1)
				v29 := sub_414C50((ss.Field44*25736)/75000 - 6434)
				pp2.X = float32(dword_5d4594_1217444_vec.X - v29*(int32(vp.Size.Y)/2)/4096)
				pp2.Y = float32(vp.World.Min.Y + vp.Size.Y - 1)
				v18 = 0
			case 3:
				pp1.X = float32(vp.World.Min.X)
				pp1.Y = float32(dword_5d4594_1217444_vec.Y - sub_414C50((ss.Field40*25736)/75000-12868)*int32(vp.Size.X/2)/4096)
				pp2.X = float32(vp.World.Min.X)
				pp2.Y = float32(dword_5d4594_1217444_vec.Y - sub_414C50((ss.Field44*25736)/75000-12868)*int32(vp.Size.X/2)/4096)
				v18 = 0
			case 4:
				pp1.X = float32(float64(vp.Size.X + vp.World.Min.X - 1))
				pp1.Y = float32(float64(int32(dword_5d4594_1217444_vec.Y + int32(sub_414C50((ss.Field40*25736)/75000)*(int32(vp.Size.X)/2)/4096))))
				pp2.X = float32(float64(vp.World.Min.X + vp.Size.X - 1))
				pp2.Y = float32(float64(int32(dword_5d4594_1217444_vec.Y + int32(sub_414C50((ss.Field44*25736)/75000)*int32(vp.Size.X/2)/4096))))
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
				brect.Max.X = float32(float64(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v36)))
				brect.Max.Y = float32(float64(dword_5d4594_1217444_vec.Y + sub_414BD0(v36)))
				var ok bool
				pp1, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp1 = rect.Min
				}
				v37 := (ss.Field44 * 25736) / 75000
				brect.Max.X = float32(float64(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v37)))
				brect.Max.Y = float32(float64(dword_5d4594_1217444_vec.Y + sub_414BD0(v37)))
				pp2, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp2 = rect.Max
				}
				v18 = int32(v34.Field_32)
			case 7:
				ss.Obj20.Field_33 = 1
				v38 := ss.Obj20
				v39 := dword_5d4594_1217444_vec.X - int32(v38.PosVec.X)
				v40 := int32(v38.PosVec.Y - int(dword_5d4594_1217444_vec.Y))
				var rect types.Rectf
				rect.Min.X = float32(float64(v40 + int32(ss.Obj20.PosVec.X)))
				rect.Min.Y = float32(float64(v39 + int32(ss.Obj20.PosVec.Y)))
				rect.Max.X = float32(float64(ss.Obj20.PosVec.X - int(v40)))
				rect.Max.Y = float32(float64(ss.Obj20.PosVec.Y - int(v39)))
				v41 := (ss.Field40 * 25736) / 75000
				brect.Max.X = float32(float64(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v41)))
				brect.Max.Y = float32(float64(dword_5d4594_1217444_vec.Y + sub_414BD0(v41)))
				var ok bool
				pp1, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp1 = types.Ptf(rect.Min.X, rect.Min.Y)
				}
				v42 := (ss.Field44 * 25736) / 75000
				brect.Max.X = float32(float64(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v42)))
				brect.Max.Y = float32(float64(dword_5d4594_1217444_vec.Y + sub_414BD0(v42)))
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
				brect.Max.X = float32(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v45))
				brect.Max.Y = float32(dword_5d4594_1217444_vec.Y + sub_414BD0(v45))
				var ok bool
				pp1, ok = server.LineTracePointXxx(brect, rect)
				if !ok {
					pp1 = rect.Min
				}
				v46 := (ss.Field44 * 25736) / 75000
				brect.Max.X = float32(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v46))
				brect.Max.Y = float32(dword_5d4594_1217444_vec.Y + sub_414BD0(v46))
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
				v47 := dword_5d4594_1217464_size
				arr_5d4594_1203876[dword_5d4594_1217464_size].X = int32(a1a.X)
				arr_5d4594_1203876[dword_5d4594_1217464_size].Y = int32(a1a.Y)
				arr_5d4594_1213348[v47] = uint32(v18)
				arr_5d4594_1212324[v47] = ss.Field56
				v47++
				dword_5d4594_1217464_size = v47
				arr_5d4594_1203876[v47].X = int32(a2.X)
				arr_5d4594_1203876[v47].Y = int32(a2.Y)
				arr_5d4594_1213348[v47] = uint32(v18)
				arr_5d4594_1212324[v47] = ss.Field56
				v51 = v47 + 1
				dword_5d4594_1217464_size = v51
			} else {
				v51 = dword_5d4594_1217464_size
			}
		}
	}
	dword_5d4594_1217464_size = v51 - 1
	pi := dword_5d4594_1217464_size - 1
	for i := 0; i < dword_5d4594_1217464_size; pi, i = i, i+1 {
		v55 := arr_5d4594_1212324[pi]
		var adx, ady int32
		if v55 != 0 {
			v56 := arr_5d4594_1212324[i]
			if v56 == 0 {
				if v55 == 6 || arr_5d4594_1212324[i] == 6 {
					v63 := arr_5d4594_1203876[pi].X
					var v64 int32
					if arr_5d4594_1203876[i].X-v63 >= 0 {
						v64 = arr_5d4594_1203876[i].X - v63
					} else {
						v64 = v63 - arr_5d4594_1203876[i].X
					}
					v65 := arr_5d4594_1203876[pi].Y
					var v66 int32
					if arr_5d4594_1203876[i].Y-v65 >= 0 {
						v66 = arr_5d4594_1203876[i].Y - v65
					} else {
						v66 = v65 - arr_5d4594_1203876[i].Y
					}
					if v64 <= 4 && v66 <= 4 {
						continue
					}
				}
				arr_5d4594_1212324[pi] = 12
				continue
			}
			if v56 != v55 {
				arr_5d4594_1212324[pi] = 12
				continue
			}
			if arr_5d4594_1213348[i] == arr_5d4594_1213348[pi] {
				continue
			}
			v57 := arr_5d4594_1203876[pi].X
			v58 := arr_5d4594_1203876[i].X - v57
			if v58 < 0 {
				adx = v57 - arr_5d4594_1203876[i].X
			} else {
				adx = v58
			}
		} else {
			if arr_5d4594_1212324[i] != 0 {
				if v55 == 6 || arr_5d4594_1212324[i] == 6 {
					v63 := arr_5d4594_1203876[pi].X
					var v64 int32
					if arr_5d4594_1203876[i].X-v63 >= 0 {
						v64 = arr_5d4594_1203876[i].X - v63
					} else {
						v64 = v63 - arr_5d4594_1203876[i].X
					}
					v65 := arr_5d4594_1203876[pi].Y
					var v66 int32
					if arr_5d4594_1203876[i].Y-v65 >= 0 {
						v66 = arr_5d4594_1203876[i].Y - v65
					} else {
						v66 = v65 - arr_5d4594_1203876[i].Y
					}
					if v64 <= 4 && v66 <= 4 {
						continue
					}
				}
				arr_5d4594_1212324[pi] = 12
				continue
			}
			if arr_5d4594_1213348[pi] == arr_5d4594_1213348[i] {
				continue
			}
			if xx1, xx2 := arr_5d4594_1203876[i].X, arr_5d4594_1203876[pi].X; xx1-xx2 < 0 {
				adx = xx2 - xx1
			} else {
				adx = xx1 - xx2
			}
		}
		if yy1, yy2 := arr_5d4594_1203876[i].Y, arr_5d4594_1203876[pi].Y; yy1-yy2 < 0 {
			ady = yy2 - yy1
		} else {
			ady = yy1 - yy2
		}
		if adx > 4 || ady > 4 {
			arr_5d4594_1212324[pi] = 12
		}
	}
}

func (c *Client) Nox_xxx_client_4984B0_drawable(dr *client.Drawable) int {
	if dr.DrawFuncPtr == nil {
		return 0
	}
	if dr == c.ClientPlayerUnit() {
		return 1
	}
	var v42, v43, v6 int32
	if int8(byte(dr.Flags28())) >= 0 {
		v42 = int32(dr.PosVec.X)
		v43 = int32(dr.PosVec.Y)
		v6 = int32(dr.PosVec.X)
	} else {
		if (dr.Flags29() & 4) == 0 {
			return int(int32(dr.Field_33))
		}
		v3 := int32(dr.PosVec.X)
		v4 := int32(dr.Field_74_4) * 8
		v5 := *memmap.PtrInt32(0x587000, uintptr(v4)+196184)
		v6 = v3 + v5/2
		v42 = v3 + v5/2
		v43 = int32(dr.PosVec.Y + int(uint32(*memmap.PtrInt32(0x587000, uintptr(v4)+196188)/2)))
	}
	if dr.Flags30Val&0x10000 != 0 {
		return int(int32(dr.Field_33))
	}
	vp := c.Viewport()
	v7 := int32(vp.World.Min.X - vp.Screen.Min.X)
	v8 := int32(vp.World.Min.Y - vp.Screen.Min.Y)
	v44 := v7
	v45 := v8
	v37 := v6 - v7
	var a1a image.Rectangle
	a1a.Min.X = vp.Screen.Min.X + vp.Size.X/2
	a1a.Min.Y = vp.Screen.Min.Y + vp.Jiggle12 + vp.Size.Y/2
	a1a.Max.X = int(v6 - v7)
	a1a.Max.Y = int(v43 - v8)
	if dword_5d4594_1217464_size <= 0 {
		return 1
	}
	v9 := arr_5d4594_1203876[dword_5d4594_1217464_size-1]
	ok := false
	for v31 := 0; v31 < dword_5d4594_1217464_size; v31++ {
		p := arr_5d4594_1203876[v31]
		var a2 image.Rectangle
		a2.Min.X = int(v9.X)
		a2.Min.Y = int(v9.Y)
		a2.Max.X = int(p.X)
		a2.Max.Y = int(p.Y)
		if sub_427C80(a1a, a2) {
			ok = true
			break
		}
		v9 = p
	}
	if !ok {
		return 1
	}
	var v13, v14, v15, v16 int32
	if dr.Shape.Kind == 2 {
		v12 := int32(dr.Shape.Circle.R)
		if int32(*(*uint16)(unsafe.Add(dr.C(), 2))) != 0 {
			v35 := int32(*(*uint16)(unsafe.Add(dr.C(), 6)))
			v13 = v6 - (int32(*(*uint16)(unsafe.Add(dr.C(), 4))) >> 1) - v7
			v14 = v43 + v12 + int32(dr.ZVal) - v35 - v8 - int32(dr.Field_24)
			v15 = v13 + int32(*(*uint16)(unsafe.Add(dr.C(), 4)))
			v16 = v14 + v35
		} else {
			v13 = v6 - v12 - v7
			v14 = v43 - v12 - v8 - int32(dr.Field_25)
			v15 = v42 + v12 - v44
			v16 = v43 + v12 + int32(dr.ZVal) - v45 - int32(dr.Field_24)
		}
	} else if int32(*(*uint16)(unsafe.Add(dr.C(), 2))) != 0 {
		v13 = v6 - (int32(*(*uint16)(unsafe.Add(dr.C(), 4))) >> 1) - v7
		v16 = int32(dr.Shape.Box.RightTop2) + v43 + int32(dr.ZVal) - v8
		v14 = v16 - int32(*(*uint16)(unsafe.Add(dr.C(), 6)))
		v15 = v13 + int32(*(*uint16)(unsafe.Add(dr.C(), 4)))
	} else {
		v13 = v37 + int32(dr.Shape.Box.LeftBottom2)
		v17 := v43 - v8 - int32(dr.Field_25)
		v14 = int32(dr.Shape.Box.LeftBottom) + v17
		v15 = v37 + int32(dr.Shape.Box.RightTop)
		v16 = int32(dr.Shape.Box.RightTop2) + v43 + int32(dr.ZVal) - v45
	}
	v32 := 0
	v51 := 0
	v41 := v13
	v38 := v14
	v40 := v15
	v36 := v16
	if int(v13) < vp.Screen.Min.X || int(v13) > vp.Screen.Max.X {
		v32 = 1
	} else {
		v51 = 1
	}
	if int(v14) < vp.Screen.Min.Y || int(v14) > vp.Screen.Max.Y {
		v32++
	} else {
		v51++
	}
	if int(v15) < vp.Screen.Min.X || int(v15) > vp.Screen.Max.X {
		v32++
	} else {
		v51++
	}
	if int(v16) < vp.Screen.Min.Y || int(v16) > vp.Screen.Max.Y {
		v32++
	} else {
		v51++
	}
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(dr), 2))) != 0 {
		if v15-v13 > 6 {
			v13 += 3
			v15 -= 3
		}
		if v16-v14 >= 22 {
			v14 += 11
			v16 -= 11
		}
	}
	if v51 == 0 || v32 == 0 {
		return 0
	}
	var v48 image.Rectangle
	v48.Min.X = a1a.Min.X
	v48.Min.Y = a1a.Min.Y
	if int(v41) < vp.Screen.Min.X {
		v48.Max.X = int(v15)
		a1a.Max.X = int(v15)
		a1a.Max.Y = int(v14)
		v48.Max.Y = int(v16)
	} else if int(v40) > vp.Screen.Max.X {
		v48.Max.X = int(v13)
		a1a.Max.X = int(v13)
		a1a.Max.Y = int(v14)
		v48.Max.Y = int(v16)
	}
	if int(v38) < vp.Screen.Min.Y {
		a1a.Max.X = int(v13)
		v48.Max.Y = int(v16)
		a1a.Max.Y = int(v16)
		v48.Max.X = int(v15)
	} else if int(v36) > vp.Screen.Max.Y {
		a1a.Max.X = int(v13)
		v48.Max.Y = int(v14)
		a1a.Max.Y = int(v14)
		v48.Max.X = int(v15)
	}
	v18 := dword_5d4594_1217464_size
	v20 := arr_5d4594_1203876[dword_5d4594_1217464_size-1]
	if dword_5d4594_1217464_size > 0 {
		for v19 := 0; v19 < dword_5d4594_1217464_size; v19++ {
			p := arr_5d4594_1203876[v19]
			var a2 image.Rectangle
			a2.Min.X = int(v20.X)
			a2.Min.Y = int(v20.Y)
			a2.Max.X = int(p.X)
			a2.Max.Y = int(p.Y)
			if sub_427C80(a1a, a2) {
				return 0
			}
			v18 = dword_5d4594_1217464_size
			v20 = p
		}
	}
	if v18 <= 0 {
		return 1
	}
	v25 := arr_5d4594_1203876[v18-1]
	for i := 0; i < dword_5d4594_1217464_size; i++ {
		p := arr_5d4594_1203876[i]
		var a2 image.Rectangle
		a2.Min.X = int(v25.X)
		a2.Min.Y = int(v25.Y)
		a2.Max.X = int(p.X)
		a2.Max.Y = int(p.Y)
		if sub_427C80(v48, a2) {
			return 0
		}
		v25 = p
	}
	return 1
}

func (c *Client) sub_498AE0() {
	c.r.Data().SetAlphaEnabled(true)
	defer c.r.Data().SetAlphaEnabled(false)
	cl := noxcolor.RGB5551Color(0, 0, 0)
	c.r.Data().SetColor2(cl)
	v0 := dword_5d4594_1217464_size
	v1 := 0
	for i := dword_5d4594_1217464_size - 1; v1 < v0; v1++ {
		if arr_5d4594_1212324[i] == 12 {
			c.sub_498B50(cl, arr_5d4594_1203876[i], arr_5d4594_1203876[v1])
			v0 = dword_5d4594_1217464_size
		}
		i = v1
	}
}

func (c *Client) Sub_498C20(a1 *ntype.Point32, a2 *ntype.Point32, a3 int32) int32 {
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
	dword_5d4594_1217452 = 0
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
	v7 := dword_5d4594_1217464_size
	if dword_5d4594_1217464_size > 0 {
		for v32 := 0; ; {
			a2a := arr_5d4594_1203876[v32]
			var a3a ntype.Point32
			if v32 == v7-1 {
				a3a = arr_5d4594_1203876[0]
			} else {
				a3a = arr_5d4594_1203876[v32+1]
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
									sub_499130(a1a)
								}
								goto LABEL_65
							}
							a1a.Y = v3.X
							a1a.X = a2a.X
							if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
								sub_499130(a1a)
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
										sub_499130(a1a)
									}
								} else {
									a1a.X = v3.X
									v22 = float32(float64(a1a.X) * float64(v28))
									a1a.Y = v16 + int32(v22)
									if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
										sub_499130(a1a)
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
									sub_499130(a1a)
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
									sub_499130(a1a)
									goto LABEL_65
								}
							}
						}
					}
				}
			}
		LABEL_65:
			v7 = dword_5d4594_1217464_size
			v32++
			if v32 >= dword_5d4594_1217464_size {
				break
			}
			v6 = v37
			v4 = a2
		}
	}
	sub_4991E0(v3)
	return int32(dword_5d4594_1217452)
}

func (c *Client) Sub_4992B0(a1 int, a2 int) int {
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
	if dword_5d4594_1217464_size <= 0 {
		return 0
	}
	v3 := dword_5d4594_1217464_size*8 - 8
	for v8 < dword_5d4594_1217464_size {
		v4 = arr_5d4594_1203876[v3/8].X
		v5 = arr_5d4594_1203876[v3/8].Y
		v6 = arr_5d4594_1203876[v8].Y
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
		if int32(a1) >= arr_5d4594_1203876[v8].X+(int32(a2)-v6)*(v4-arr_5d4594_1203876[v8].X)/(v5-v6) {
			result = v7
		} else {
			result = int32(bool2int(v7 == 0))
			v7 = int32(bool2int(v7 == 0))
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

func sub_498130(a1 *SightStructXxx) {
	for i := sub_498290(a1); i < sightStructArrSize; i++ {
		v2 := sightStructArr[i]
		if v2.Field40 > a1.Field44 {
			break
		}
		sub_498380(a1, sightStructArr[i])
		if int32(a1.Field48) == 0 || a1.Field44-a1.Field40 < 0 {
			sub_4CAE40(a1)
			return
		}
		if int32(v2.Field48) == 0 || v2.Field44-v2.Field40 < 0 {
			if sub_4982E0(v2) <= i {
				i--
			}
			sub_4CAE40(v2)
		}
	}
	sub_4981D0(a1)
}
func sub_4981D0(a1 *SightStructXxx) {
	v1 := sightStructArrSize - 1
	v2 := 0
	for v2 <= v1 {
		ind := (v1 + v2) / 2
		if sightStructArr[ind].Field40 >= a1.Field40 {
			v1 = ind - 1
		} else {
			v2 = ind + 1
		}
	}
	sub_498220(a1, v2)
}
func sub_498220(a1 *SightStructXxx, a2 int) {
	if a2 < sightStructArrSize {
		copy(sightStructArr[a2+1:], sightStructArr[a2:sightStructArrSize])
	}
	sightStructArr[a2] = a1
	sightStructArrSize++
}
func sub_498290(a1 *SightStructXxx) int {
	v1 := 0
	v2 := sightStructArrSize - 1
	if sightStructArrSize-1 < 0 {
		return 0
	}
	for {
		ind := (v2 + v1) / 2
		if sightStructArr[ind].Field44 >= a1.Field40 {
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
func sub_4982E0(p *SightStructXxx) int {
	ind := sub_498330(p)
	copy(sightStructArr[ind:], sightStructArr[ind+1:sightStructArrSize])
	sightStructArrSize--
	return ind
}
func sub_498330(a1 *SightStructXxx) int {
	v1 := a1.Field40
	v2 := 0
	v3 := sightStructArrSize - 1
	for {
		ind := (v3 + v2) / 2
		v5 := sightStructArr[ind].Field40
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
func sub_498110() {
	for it := sub_4CAEB0(); it != nil; it = sub_4CAEB0() {
		sub_498130(it)
	}
}
func sub_4CAEB0() *SightStructXxx {
	res := dword_5d4594_1522596
	if dword_5d4594_1522596 != nil {
		dword_5d4594_1522596 = dword_5d4594_1522596.Field12
	}
	return res
}
func sub_4CAE90(a1 *SightStructXxx) {
	a1.Field12 = dword_5d4594_1522596
	dword_5d4594_1522596 = a1
}
func sub_496120_free() int32 {
	if sightStructArr != nil {
		alloc.FreeSlice(sightStructArr)
		sightStructArr = nil
	}
	return 1
}
func sub_4960B0() int32 {
	sightStructArr, _ = alloc.Make([]*SightStructXxx{}, uintptr(nox_win_width*4/23*(nox_win_height/23)/2))
	if sightStructArr == nil {
		return 0
	}
	sub_4CA860()
	return 1
}
func sub_4CA860() {
	ca := *memmap.PtrFloat64(0x581450, 9960)
	cb := *memmap.PtrFloat64(0x581450, 9952)
	for i := range arr_5d4594_1322584 {
		v1 := int64(math.Atan2(float64(i)*ca, 1.0)*cb + 0.5)
		arr_5d4594_1322584[i] = int16(v1)
	}
}
func sub_4CAED0(a1 *SightStructXxx) *SightStructXxx {
	p := sub_4CADD0()
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
	Field0    uint32           // 0, 0
	Field4    uint32           // 1, 4
	Field8    *SightStructXxx  // 2, 8
	Field12   *SightStructXxx  // 3, 12
	Field16   *SightStructXxx  // 4, 16
	Obj20     *client.Drawable // 5, 20
	GridPos24 ntype.Point32    // 6, 24
	Field32   int32            // 8, 32
	Field36   byte             // 9, 36
	Field37   byte             // 9, 37
	Field38   uint16           // 9, 38
	Field40   int32            // 10, 40
	Field44   int32            // 11, 44
	Field48   byte             // 12, 48
	Field49   byte             // 12, 49
	Field50   uint16           // 12, 50
	Field52   uint32           // 13, 52
	Field56   byte             // 14, 56
	Field57   byte             // 14, 57
	Field58   uint16           // 14, 58
}

func sub_4CADD0() *SightStructXxx {
	result := dword_5d4594_1522584
	if dword_5d4594_1522584 == nil {
		for i := 0; i < 10; i++ {
			p, _ := alloc.New(SightStructXxx{})
			p.Field16 = dword_5d4594_1522584
			dword_5d4594_1522584 = p
			p.Field8 = dword_5d4594_1522592
			dword_5d4594_1522592 = p
		}
		dword_5d4594_1522588 += 10
		result = dword_5d4594_1522584
	}
	dword_5d4594_1522584 = result.Field16
	return result
}
func nox_xxx_drawBlackofWall_497C40(a1 int32, a2 int32, a3 int8) {
	v21 := a1 * 23
	v22 := a2 * 23
	v3 := a1*23 + 11
	v4 := a2*23 + 11
	v5 := sub_4CADD0()
	v5.GridPos24.X = a1
	v5.GridPos24.Y = a2
	v5.Field36 = uint8(a3)
	v5.Field48 = 1
	v5.Field56 = 0
	var v6, v7, v8, v9, v23 int32
	var v24 int32 // FIXME: uninitialized!
	switch a3 {
	case 1:
		v6 = int32(v3) - dword_5d4594_1217444_vec.X + 5
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y - 5
		v8 = v3
		v9 = a2 * 23
		v23 = v21 + 23
	case 2:
		v6 = int32(v3) - dword_5d4594_1217444_vec.X - 5
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y - 5
		v8 = v3
		v9 = a2 * 23
		v23 = a1 * 23
	case 4:
		v6 = int32(v3) - dword_5d4594_1217444_vec.X + 5
		v10 := 5
		v8 = v3
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y + int32(v10)
		v23 = v21 + 23
		v9 = v22 + 23
	case 6:
		v8 = a1 * 23
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y
		v4 = a2 * 23
		v6 = int32(v3) - dword_5d4594_1217444_vec.X
		v23 = v21 + 23
		v9 = v22 + 23
	case 8:
		v6 = int32(v3) - dword_5d4594_1217444_vec.X - 5
		v23 = a1 * 23
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y + 5
		v8 = v3
		v9 = v22 + 23
	case 9:
		v6 = int32(v3) - dword_5d4594_1217444_vec.X
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y
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
	v11 := sub_4CA8B0(int32(v4)-dword_5d4594_1217444_vec.Y, int32(v8)-dword_5d4594_1217444_vec.X)
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
	v14 := sub_4CA8B0(int32(v9)-dword_5d4594_1217444_vec.Y, int32(v23)-dword_5d4594_1217444_vec.X)
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
		sub_4CAE90(v5)
		return
	}
	v19 := sub_4CAED0(v5)
	v19.Field40 = 0
	v19.Field44 = v5.Field40
	v5.Field40 = v5.Field44
	v5.Field44 = 74999
	sub_4CAE90(v19)
	sub_4CAE90(v5)
}
func sub_4974B0(a1 *client.Drawable) {
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
	if (a1.Flags29() & 4) == 0 {
		v2 := sub_4CADD0()
		v2.Field48 = 1
		v2.Field56 = 6
		v2.Obj20 = a1
		v3 = int32(a1.Field_74_4) * 8
		v4 = float64(int32(dword_5d4594_1217444_vec.X - int32(*memmap.PtrInt32(0x587000, uintptr(v3)+196184)/2) - int32(a1.PosVec.X)))
		v15 = dword_5d4594_1217444_vec.Y - int32(*memmap.PtrInt32(0x587000, uintptr(v3)+196188)/2) - int32(a1.PosVec.Y)
		v14 = float32(float64(v15)*float64(v15) + v4*v4)
		v2.Field32 = int32(v14)
		v5 = sub_4CA8B0(int32(v1.PosVec.Y-int(dword_5d4594_1217444_vec.Y)), int32(v1.PosVec.X-int(dword_5d4594_1217444_vec.X)))
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
		v8 = sub_4CA8B0(int32(v1.PosVec.Y+int(int32(*memmap.PtrInt32(0x587000, uintptr(int32(v1.Field_74_4)*8)+196188)))-int(dword_5d4594_1217444_vec.Y)), int32(v1.PosVec.X+int(int32(*memmap.PtrInt32(0x587000, uintptr(int32(v1.Field_74_4)*8)+196184)))-int(dword_5d4594_1217444_vec.X)))
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
			v13 := sub_4CAED0(v2)
			v13.Field40 = 0
			v13.Field44 = v2.Field40
			v2.Field40 = v2.Field44
			v2.Field44 = 74999
			sub_4CAE90(v13)
		}
		sub_4CAE90(v2)
	}
}
func sub_497650(a1 *client.Drawable) {
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
	v1 := sub_4CADD0()
	v2 := a1
	v3 := v1
	v1.Field48 = 1
	v1.Field56 = 7
	v1.Obj20 = a1
	v4 = int32(a1.PosVec.Y)
	v24 = float32(float64(int32(a1.PosVec.X - int(dword_5d4594_1217444_vec.X))))
	v5 = float64(int32(int32(v4) - dword_5d4594_1217444_vec.Y))
	v23 = float32(v5)
	v21 = float32(v5*float64(v23) + float64(v24*v24))
	v6 = int32(v21)
	v3.Field32 = v6
	v7 = int32(int64(math.Sqrt(float64(v6))))
	v22 = int32(v24)
	v8 = int32(v23)
	v9 = sub_4CA8B0(v8, v22)
	v10 = int32(v2.Shape.Circle.R)
	v11 = sub_4CA8B0(v10, v7)
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
		sub_4CAE90(v3)
		return
	}
	v19 := sub_4CAED0(v3)
	v19.Field40 = 0
	v19.Field44 = v3.Field40
	v3.Field40 = v3.Field44
	v3.Field44 = 74999
	sub_4CAE90(v19)
	sub_4CAE90(v3)
}
func sub_4977C0(a1 *client.Drawable) {
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
	v30 = int32(int32(v38[0])) - dword_5d4594_1217444_vec.X
	v4 = int32(v38[1])
	v5 = sub_4CA8B0(int32(v4)-dword_5d4594_1217444_vec.Y, v30)
	v31 = int32(int32(v38[2])) - dword_5d4594_1217444_vec.X
	v6 = int32(v38[3])
	v7 = sub_4CA8B0(int32(v6)-dword_5d4594_1217444_vec.Y, v31)
	v32 = int32(int32(v38[4])) - dword_5d4594_1217444_vec.X
	v8 = int32(v38[5])
	v9 = sub_4CA8B0(int32(v8)-dword_5d4594_1217444_vec.Y, v32)
	v33 = int32(int32(v38[6])) - dword_5d4594_1217444_vec.X
	v10 = int32(v38[7])
	v40 = sub_4CA8B0(int32(v10)-dword_5d4594_1217444_vec.Y, v33)
	result = int32(uint8(sub_497B80(&v38, &dword_5d4594_1217444_vec))) - 1
	switch result {
	case 0:
		v35 = float32(float64(v38[5]+v38[1]) * 0.5)
		v14 = float64(v38[4]+v38[0])*0.5 - float64(dword_5d4594_1217444_vec.X)
		v25 = float32((float64(v35)-float64(dword_5d4594_1217444_vec.Y))*(float64(v35)-float64(dword_5d4594_1217444_vec.Y)) + v14*v14)
		v15 = int32(v25)
		sub_497F60(v5, v9, 9, v15, v1)
	case 1:
		v37 = float32(float64(v38[7]+v38[3]) * 0.5)
		v18 = float64(v38[6]+v38[2])*0.5 - float64(dword_5d4594_1217444_vec.X)
		v27 = float32((float64(v37)-float64(dword_5d4594_1217444_vec.Y))*(float64(v37)-float64(dword_5d4594_1217444_vec.Y)) + v18*v18)
		v19 = int32(v27)
		sub_497F60(v40, v7, 10, v19, v1)
	case 3:
		v34 = float32(float64(v38[3]+v38[1]) * 0.5)
		v12 = float64(v38[2]+v38[0])*0.5 - float64(dword_5d4594_1217444_vec.X)
		v24 = float32((float64(v34)-float64(dword_5d4594_1217444_vec.Y))*(float64(v34)-float64(dword_5d4594_1217444_vec.Y)) + v12*v12)
		v13 = int32(v24)
		sub_497F60(v5, v7, 8, v13, v1)
	case 4, 9:
		v22 = float64(int32(v1.PosVec.X - int(dword_5d4594_1217444_vec.X)))
		v29 = float32(float64(int32(v1.PosVec.Y-int(dword_5d4594_1217444_vec.Y)))*float64(int32(v1.PosVec.Y-int(dword_5d4594_1217444_vec.Y))) + v22*v22)
		v23 = int32(v29)
		sub_497F60(v7, v9, 14, v23, v1)
	case 5, 8:
		v20 = float64(int32(v1.PosVec.X - int(dword_5d4594_1217444_vec.X)))
		v28 = float32(float64(int32(v1.PosVec.Y-int(dword_5d4594_1217444_vec.Y)))*float64(int32(v1.PosVec.Y-int(dword_5d4594_1217444_vec.Y))) + v20*v20)
		v21 = int32(v28)
		sub_497F60(v5, v40, 13, v21, v1)
	case 7:
		v36 = float32(float64(v38[7]+v38[5]) * 0.5)
		v16 = float64(v38[6]+v38[4])*0.5 - float64(dword_5d4594_1217444_vec.X)
		v26 = float32((float64(v36)-float64(dword_5d4594_1217444_vec.Y))*(float64(v36)-float64(dword_5d4594_1217444_vec.Y)) + v16*v16)
		v17 = int32(v26)
		sub_497F60(v40, v9, 11, v17, v1)
	}
}
func sub_498030(a1 *noxrender.Viewport) {
	v1 := int32(a1.World.Min.X)
	v2 := int32(a1.World.Min.Y)
	v3 := int32(a1.Size.X + int(uint32(v1)))
	v4 := int32(a1.Size.Y + int(uint32(v2)))
	v9 := sub_4CA8B0(int32(v2)-dword_5d4594_1217444_vec.Y, int32(v1)-dword_5d4594_1217444_vec.X)
	v5 := sub_4CA8B0(int32(v2)-dword_5d4594_1217444_vec.Y, int32(v3)-dword_5d4594_1217444_vec.X)
	v6 := sub_4CA8B0(int32(v4)-dword_5d4594_1217444_vec.Y, int32(v3)-dword_5d4594_1217444_vec.X)
	v7 := sub_4CA8B0(int32(v4)-dword_5d4594_1217444_vec.Y, int32(v1)-dword_5d4594_1217444_vec.X)
	sub_497F60(v9, v5, 1, math.MaxInt32, nil)
	sub_497F60(v5, v6, 4, math.MaxInt32, nil)
	sub_497F60(v6, v7, 2, math.MaxInt32, nil)
	sub_497F60(v7, v9, 3, math.MaxInt32, nil)
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

func sub_4CA8B0(a1 int32, a2 int32) int32 {
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
	if ind >= len(arr_5d4594_1322584) {
		ind = len(arr_5d4594_1322584) - 1
	}
	res := int32(arr_5d4594_1322584[ind])
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

func (c *Client) sub_497260(vp *noxrender.Viewport) {
	for dr := c.Objs.FirstList2(); dr != nil; dr = dr.Field_90 {
		dr.Field_33 = 0
		if dr.HasEnchant(server.ENCHANT_INVISIBLE) {
			continue
		}
		pos := types.Point2f(dr.Pos())
		if int8(byte(dr.Flags28())) >= 0 {
			switch dr.Shape.Kind {
			case server.ShapeKindCircle:
				if (pos.X-dr.Shape.Circle.R) < float32(vp.World.Min.X+vp.Size.X) && (pos.X+dr.Shape.Circle.R) > float32(vp.World.Min.X) {
					if (pos.Y-dr.Shape.Circle.R) < float32(vp.World.Min.Y+vp.Size.Y) && (pos.Y+dr.Shape.Circle.R) > float32(vp.World.Min.Y) {
						sub_497650(dr)
					}
				}
			case server.ShapeKindBox:
				if (pos.X+dr.Shape.Box.LeftBottom2) < float32(vp.World.Min.X+vp.Size.X) && (pos.X+dr.Shape.Box.RightTop) > float32(vp.World.Min.X) {
					if (pos.Y+dr.Shape.Box.LeftBottom) < float32(vp.World.Min.Y+vp.Size.Y) && (pos.Y+dr.Shape.Box.RightTop2) > float32(vp.World.Min.Y) {
						sub_4977C0(dr)
					}
				}
			}
		} else {
			if (pos.X-32) < float32(vp.World.Min.X+vp.Size.X) && (pos.X+32) > float32(vp.World.Min.X) {
				if (pos.Y-32) < float32(vp.World.Min.Y+vp.Size.Y) && (pos.Y+32) > float32(vp.World.Min.Y) {
					sub_4974B0(dr)
				}
			}
		}
	}
}

func (c *Client) sub_498B50(cl color.Color, p1, p2 ntype.Point32) {
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
		v11 := uint32(bool2int(v9 < 0) - 1)
		v11 &= 0xFFFFFFFE
		sy = int32(v11 + 1)
	}
	alpha := byte(208)
	cp := p1
	vx := p2.X - p1.X
	vy := p2.Y - p1.Y
	for i := 0; i < 10; i++ {
		c.r.Data().SetAlpha(alpha)
		alpha -= 20
		c.r.DrawVector(image.Pt(int(cp.X), int(cp.Y)), image.Pt(int(vx), int(vy)), cl)
		cp.X += sx
		cp.Y += sy
	}
}
func sub_499130(a1 ntype.Point32) {
	if dword_5d4594_1217452 >= len(arr_5d4594_1212068) {
		return
	}
	arr_5d4594_1212068[dword_5d4594_1217452] = a1
	dword_5d4594_1217452++
}
func (c *Client) Sub_499290(a1 int) ntype.Point32 {
	return arr_5d4594_1212068[a1]
}
func sub_4991E0(a1 *ntype.Point32) {
	v1 := dword_5d4594_1217452
	if dword_5d4594_1217452 > 0 {
		v2 := a1
		v3 := 1
		v12 := 1
		for {
			v4 := &arr_5d4594_1212068[v3-1]
			v5 := v4.Y - v2.Y
			v6 := (v4.X-v2.X)*(v4.X-v2.X) + int32(v5*v5)
			if v3 < v1 {
				for i := 0; i < v1-v3; i++ {
					v7 := &arr_5d4594_1212068[v3+i]
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
				v1 = dword_5d4594_1217452
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
func sub_497F60(a1 int32, a2 int32, a3 int8, a4 int32, a5 *client.Drawable) {
	v5 := sub_4CADD0()
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
		sub_4CAE90(v5)
		return
	}
	v10 := sub_4CAED0(v5)
	v10.Field40 = 0
	v10.Field44 = v5.Field40
	v5.Field40 = v5.Field44
	v5.Field44 = 74999
	sub_4CAE90(v10)
	sub_4CAE90(v5)
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
		return int32(bool2int(v1 <= 0) + math.MaxInt32)
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
func sub_498380(a1 *SightStructXxx, a2 *SightStructXxx) {
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
			v7 := sub_4CAED0(a2)
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
			sub_4CAE90(v7)
			return
		}
		a1.Field48 = 0
		return
	}
	v12 = v3 <= v5
	v13 = a1.Field32
	if v12 {
		if v13 >= a2.Field32 {
			v14 := sub_4CAED0(a1)
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
			sub_4CAE90(v14)
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
func sub_4CAE40(a1 *SightStructXxx) {
	a1.Field16 = dword_5d4594_1522584
	dword_5d4594_1522584 = a1
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

func (c *Client) nox_xxx_drawBlack_496150_B() {
	sub_4989A0()
	arr := arr_5d4594_1203876[:dword_5d4594_1217464_size]
	if len(arr) == 0 {
		return
	}
	c.sub_4C52E0(arr)
}

func sub_4989A0() {
	arr := arr_5d4594_1203876[:dword_5d4594_1217464_size]
	if len(arr) < 3 {
		return
	}

	barr := arr_5d4594_1212324[:]
	iarr := arr_5d4594_1213348[:]

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
	dword_5d4594_1217464_size = j + 1
}
