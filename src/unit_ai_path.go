package opennox

import (
	"image"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

const aiMapIndexSize = 256
const dword_587000_234176 = 11.5

var (
	aiMapIndex           [aiMapIndexSize][aiMapIndexSize]aiMapIndexNode
	dword_5d4594_2386160 uint32
	dword_5d4594_1599712 int

	dword_5d4594_2386152 *server.Object

	dword_5d4594_2386164 uint32
	dword_5d4594_2386168 uint32

	nox_alloc_visitNode_2386184 alloc.ClassT[aiVisitNode]
	dword_5d4594_2386176        []types.Pointf
	dword_5d4594_2386180        int
	dword_5d4594_2386172        uint32
)

func aiGetMapIndex(x, y int) *aiMapIndexNode {
	if x < 0 || x >= aiMapIndexSize || y < 0 || y >= aiMapIndexSize {
		return nil
	}
	return &aiMapIndex[y][x]
}

type aiVisitNode struct {
	X0      uint16       // 0, 0
	Y2      uint16       // 0, 0
	Field4  *aiVisitNode // 1, 4
	Field8  *aiVisitNode // 2, 8
	Flags12 byte         // 3, 12
	Field13 byte         // 3, 13
	Field14 uint16       // 3, 14
}

func nox_xxx_allocVisitNodesArray_50AB90() int32 {
	nox_alloc_visitNode_2386184 = alloc.NewClassT("VisitNodes", aiVisitNode{}, 1024)
	if nox_alloc_visitNode_2386184.Class == nil {
		return 0
	}
	dword_5d4594_2386176, _ = alloc.Make([]types.Pointf{}, 1024)
	if dword_5d4594_2386176 != nil {
		dword_5d4594_2386172 = 0
		return 1
	} else {
		nox_alloc_visitNode_2386184.Free()
		return 0
	}
}
func (s *Server) Sub_50B500() {
	dword_5d4594_2386168 = 0
}
func (s *Server) Sub_50B510() {
	dword_5d4594_2386168 = 0
	dword_5d4594_2386172 = 0
}
func sub_50ABF0() {
	alloc.FreeSlice(dword_5d4594_2386176)
	nox_alloc_visitNode_2386184.Free()
}

func sub_50B520() {
	s := noxServer
	if (s.Frame() - dword_5d4594_2386172) < 15 {
		return
	}
	dword_5d4594_2386172 = s.Frame()
	dword_5d4594_2386164++
	for it := s.Objs.List; it != nil; it = it.Next() {
		nox_xxx_aiTestUnitDangerous_50B2C0(it)
	}
	dword_5d4594_2386168 = 1
}

func nox_xxx_appendWorkPath_50C990(path []types.Pointf, ind int) int {
	v3 := 0
	if dword_5d4594_2386180 <= 0 {
		return ind
	}
	v4 := ind
	v5 := path[ind:]
	for {
		if v4 == len(path)-1 {
			ai.Log.Printf("appendWorkPath: Path truncated.\n")
			return v4
		}
		v4++
		v6 := dword_5d4594_2386176[v3]
		v3++
		v5[0] = v6
		v5 = v5[1:]
		if v3 >= dword_5d4594_2386180 {
			return v4
		}
	}
}

func (s *Server) sub_50C320(obj *server.Object, node *aiVisitNode, start *types.Pointf) {
	ud := obj.UpdateDataMonster()
	if node == nil {
		dword_5d4594_2386180 = 0
		return
	}
	if start != nil {
		dword_5d4594_2386176[0] = *start
	} else {
		var (
			netCode uint32
			out     types.Pointf
		)
		if node.Flags12&0x2 != 0 && s.sub_50AEA0(node, &out, &netCode) != 0 {
			dword_5d4594_2386176[0] = out
			if int(ud.Field543_0) < len(ud.Field535) {
				ud.Field535[ud.Field543_0] = netCode
				ud.Field543_0++
			}
		} else {
			dword_5d4594_2386176[0].X = float32(float64(node.X0)*23.0 + 11.5)
			dword_5d4594_2386176[0].Y = float32(float64(node.Y2)*23.0 + 11.5)
		}
	}
	ni := 1
	prev := node
	for it := node.Field4; it != nil; it, prev, ni = it.Field4, it, ni+1 {
		dx := int32(it.X0) - int32(prev.X0)
		dy := int32(it.Y2) - int32(prev.Y2)
		if it.Flags12&0x2 != 0 {
			var (
				netCode uint32
				out     types.Pointf
			)
			if s.sub_50AEA0(it, &out, &netCode) != 0 {
				dword_5d4594_2386176[ni] = out
				if int32(ud.Field543_0) < 8 {
					if dx*dx+dy*dy > 4761 {
						ud.Field535[ud.Field543_0] = netCode
						ud.Field543_0++
					} else {
						var ppa, ppb types.Pointf
						ppa.X = float32(int32(it.X0)*23 + 11)
						ppa.Y = float32(int32(it.Y2)*23 + 11)
						ppb.X = float32(int32(prev.X0)*23 + 11)
						ppb.Y = float32(int32(prev.Y2)*23 + 11)
						if !s.MapTraceRayAt(ppa, ppb, nil, nil, 1) {
							ud.Field535[ud.Field543_0] = netCode
							ud.Field543_0++
						}
					}
				}
				continue
			}
		}
		if dx < 0 {
			if dy > 0 {
				dword_5d4594_2386176[ni].X = float32(float64(it.X0)*23.0 + 23.0 - 2.3)
				dword_5d4594_2386176[ni].Y = float32(float64(it.Y2)*23.0 + 2.3)
			} else if dy < 0 {
				dword_5d4594_2386176[ni].X = float32(float64(it.X0)*23.0 + 23.0 - 2.3)
				dword_5d4594_2386176[ni].Y = float32(float64(it.Y2)*23.0 + 23.0 - 2.3)
			} else {
				dword_5d4594_2386176[ni].X = float32(float64(it.X0)*23.0 + 23.0 - 2.3)
				dword_5d4594_2386176[ni].Y = float32(float64(it.Y2)*23.0 + 11.5)
			}
		} else if dx == 0 {
			if dy > 0 {
				dword_5d4594_2386176[ni].X = float32(float64(it.X0)*23.0 + 11.5)
				dword_5d4594_2386176[ni].Y = float32(float64(it.Y2)*23.0 + 2.3)
			} else if dy < 0 {
				dword_5d4594_2386176[ni].X = float32(float64(it.X0)*23.0 + 11.5)
				dword_5d4594_2386176[ni].Y = float32(float64(it.Y2)*23.0 + 23.0 - 2.3)
			}
		} else {
			if dy < 0 {
				dword_5d4594_2386176[ni].X = float32(float64(it.X0)*23.0 + 2.3)
				dword_5d4594_2386176[ni].Y = float32(float64(it.Y2)*23.0 + 23.0 - 2.3)
			} else if dy == 0 {
				dword_5d4594_2386176[ni].X = float32(float64(it.X0)*23.0 + 2.3)
				dword_5d4594_2386176[ni].Y = float32(float64(it.Y2)*23.0 + 11.5)
			} else {
				dword_5d4594_2386176[ni].X = float32(float64(it.X0)*23.0 + 2.3)
				dword_5d4594_2386176[ni].Y = float32(float64(it.Y2)*23.0 + 2.3)
			}
		}
	}
	dword_5d4594_2386180 = ni
	for i := 0; i < dword_5d4594_2386180/2; i++ {
		p1 := &dword_5d4594_2386176[i]
		p2 := &dword_5d4594_2386176[dword_5d4594_2386180-i-1]
		*p1, *p2 = *p2, *p1
	}
}
func (s *Server) Sub_50CB00() int {
	return dword_5d4594_2386180
}
func (s *Server) Sub_50CB10() []types.Pointf {
	return dword_5d4594_2386176
}
func Sub_50CB10() []types.Pointf {
	return dword_5d4594_2386176[:dword_5d4594_2386180]
}

type aiMapIndexFlags uint16

const (
	aiIndexElevator      = aiMapIndexFlags(0x4)
	aiIndexElevatorShaft = aiMapIndexFlags(0x8)
	aiIndexHole          = aiMapIndexFlags(0x10)
	aiIndexTransporter   = aiMapIndexFlags(0x20)
)

type aiMapIndexNode struct {
	Field0  uint32
	Field4  uint32
	Flags8  aiMapIndexFlags
	Field10 uint16
}

func nox_xxx_aiTestUnitDangerous_50B2C0(obj *server.Object) {
	var (
		result int32
		v4     int32
		v5     float64
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v12    int32
		v13    int16
		v14    float32
		v15    float32
		v16    float32
		v17    float32
		v18    int32
		v19    int32
		v20    int32
		a2     types.Pointf
		v24    int32
		v25    [60]byte
		a1a    int32
	)
	v1 := obj
	result = int32(obj.ObjClass)
	if !((result&0xC080) == 0 && (result&0x2000 != 0 || (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(obj), 16)))&0x49) == 0) && (result&0x2008 != 0 || int32(*(*uint8)(unsafe.Add(unsafe.Pointer(obj), 16)))&2 != 0)) {
		return
	}
	if uint32(result)&0x10000 != 0 {
		alloc.Memcpy(unsafe.Pointer(&v25[0]), unsafe.Add(unsafe.Pointer(obj), 172), 60)
		if obj.Shape.Kind == 2 {
			v3 := float64(dword_587000_234176 + obj.Shape.Circle.R)
			obj.Shape.Circle.R = float32(v3)
			obj.Shape.Circle.R2 = float32(v3 * v3)
		} else if obj.Shape.Kind == 3 {
			obj.Shape.Box.W = dword_587000_234176 + dword_587000_234176 + obj.Shape.Box.W
			obj.Shape.Box.H = dword_587000_234176 + dword_587000_234176 + obj.Shape.Box.H
			obj.Shape.Box.Calc()
		}
		nox_xxx_objectUnkUpdateCoords_4E7290(obj)
	}
	v14 = float32(float64(obj.CollideP1.X) / 23)
	v4 = int32(v14)
	v5 = float64(obj.CollideP1.Y) / 23
	v6 = v4
	v24 = v4
	v15 = float32(v5)
	v7 = int32(v15)
	v16 = float32(float64(obj.CollideP2.X) / 23)
	v19 = int32(v16)
	v17 = float32(float64(obj.CollideP2.Y) / 23)
	v8 = int32(v17)
	v9 = v7
	v20 = v8
	for a1a = v7; v9 <= v8; a1a = v9 {
		v18 = v6
		if v6 <= v19 {
			p := aiGetMapIndex(int(v6), int(v9))
			v10 := (*uint8)(unsafe.Pointer(&p.Flags8))
			for {
				for _, v11 := range memmap.PtrT[[9]types.Pointf](0x587000, 234104) {
					v21 := float32(float64(v18) * 23.0)
					a2.X = v21 + v11.X
					v22 := float32(float64(a1a) * 23.0)
					a2.Y = v22 + v11.Y
					if sub_547DB0(v1, &a2) != 0 {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v10), -int(4*1))) = dword_5d4594_2386164
						v12 = int32(v1.ObjClass)
						if v12&8 != 0 || int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 16)))&2 != 0 {
							v13 = int16(int32(*(*uint16)(unsafe.Pointer(v10))) | 0x100)
							*(*uint16)(unsafe.Pointer(v10)) = uint16(v13)
							if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 16))) & 0x10) == 0 {
								*(*uint8)(unsafe.Add(unsafe.Pointer(&v13), unsafe.Sizeof(int16(0))-1)) |= 2
								*(*uint16)(unsafe.Pointer(v10)) = uint16(v13)
							}
						} else if v12&0x2000 != 0 {
							*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 1)) |= 4
						}
						break
					}
				}
				v6++
				v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 3072))
				v18 = v6
				if v6 > v19 {
					break
				}
			}
			v9 = a1a
			v8 = v20
			v6 = v24
		}
		v9++
	}
	if v1.ObjClass&0x10000 != 0 {
		alloc.Memcpy(unsafe.Add(unsafe.Pointer(v1), 172), unsafe.Pointer(&v25[0]), 0x3C)
		nox_xxx_objectUnkUpdateCoords_4E7290(v1)
	}
}

func (s *Server) nox_xxx_pathFind_50BA00(far bool, obj *server.Object, a3 *types.Pointf, a4 *types.Pointf, fnc func(obj *server.Object, x, y int32) int, a6 int32) {
	var (
		v30 *server.Object
		v33 *aiVisitNode
		v36 int32
		v37 int32
		v38 bool
		v39 int32
		v40 int32
		v41 int32
		v42 int32
		v64 int32
		v65 int32
		v67 *aiVisitNode
		v68 [2]uint16
		v77 *aiVisitNode
	)
	v67 = nil
	v64 = 0
	v65 = 0
	var cur int32
	if far {
		cur = 0
	} else {
		cur = 999999
	}
	dword_5d4594_1599712 = 0
	dword_5d4594_2386160++
	if dword_5d4594_2386168 == 0 {
		sub_50B520()
	}
	var a2a Point32
	a2a.X = int32(float32(float64(a3.X) / 23))
	a2a.Y = int32(float32(float64(a3.Y) / 23))
	nox_xxx_pathfind_preCheckWalls_50C8D0(obj, &a2a)
	v63 := bool2int(nox_xxx_pathfind_preCheckWalls2_50B8A0(obj, int(a2a.X), int(a2a.Y)) == 0)
	v61 := false
	if fnc != nil && fnc(obj, a2a.X, a2a.Y) == 0 {
		v61 = true
	}
	x00 := int32(float64(a4.X) / 23)
	y00 := int32(float64(a4.Y) / 23)
	if nox_alloc_visitNode_2386184.Class == nil {
		dword_5d4594_2386180 = 0
		dword_5d4594_1599712 = 2
		return
	}
	nox_alloc_visitNode_2386184.FreeAllObjects()
	vn := nox_alloc_visitNode_2386184.NewObject()
	vn.X0 = uint16(int16(a2a.X))
	vn.Y2 = uint16(int16(a2a.Y))
	x0 := vn.X0
	y0 := vn.Y2
	vn.Field4 = nil
	vn.Field8 = nil
	vn2 := vn

	aiGetMapIndex(int(x0), int(y0)).Field0 = dword_5d4594_2386160
	for v66 := int32(0); ; {
		vn3 := vn2
		vn2 = nil
		v77 = nil
		if vn3 == nil {
			goto LABEL_40
		}
		for {
			x1 := int32(vn3.X0)
			y1 := int32(vn3.Y2)
			dd := (x1-x00)*(x1-x00) + (y1-y00)*(y1-y00)
			if far {
				if dd > cur {
					v67 = vn3
					cur = dd
				}
			} else {
				if dd < cur {
					v67 = vn3
					cur = dd
				}
				if v63 == 0 && !v61 && x1 == x00 && y1 == y00 {
					dword_5d4594_1599712 = 0
					s.sub_50C320(obj, vn3, a4)
					return
				}
			}
			ioff := s.Rand.Logic.IntClamp(0, 7)
			parr := memmap.PtrT[[8]Point32](0x587000, 234216)
			for i := 0; i < 8; i++ {
				ii := (i + ioff) % 8
				pp := parr[ii]
				x2 := pp.X + int32(vn3.X0)
				y2 := pp.Y + int32(vn3.Y2)
				if x2 < 0 || x2 >= aiMapIndexSize || y2 < 0 || y2 >= aiMapIndexSize {
					continue
				}
				ip := aiGetMapIndex(int(x2), int(y2))
				if ip.Field0 == dword_5d4594_2386160 {
					continue
				}
				ip.Field0 = dword_5d4594_2386160
				if x2 == x00 && y2 == y00 {
					var v76a, v76b types.Pointf
					v76a.X = float32(int32(vn3.X0)*23 + 11)
					v76a.Y = float32(int32(vn3.Y2)*23 + 11)
					v76b.X = a4.X
					v76b.Y = a4.Y
					if s.MapTraceObstacles(obj, v76a, v76b) {
						if obj.ObjFlags&0x4000 != 0 {
							if s.MapTraceRayAt(v76a, v76b, nil, nil, 5) {
								v30 = obj
								goto LABEL_32
							}
						} else {
							if s.MapTraceRayAt(v76a, v76b, nil, nil, 1) {
								v30 = obj
								goto LABEL_32
							}
						}
					}
				}
				if ii < 4 {
					v30 = obj
				} else {
					v60 := byte(int8(int32(uint16(int16(^(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(obj), 16)))>>8))))&0xD8 | 0x98))
					s.Doors.SetKeyHolder(obj)
					switch ii {
					case 4:
						v36 = int32(uint8(s.Sub_57B500(image.Pt(int(vn3.X0), int(vn3.Y2)+1), v60)))
						if v36 != 1 && v36 != 6 && v36 != 10 && v36 != 9 && v36 != math.MaxUint8 {
							continue
						}
						*(*uint8)(unsafe.Pointer(&v37)) = uint8(s.Sub_57B500(image.Pt(int(vn3.X0)+1, int(vn3.Y2)), v60))
						v37 = int32(uint8(int8(v37)))
						if int32(uint8(int8(v37))) == 1 || v37 == 4 || v37 == 7 {
							// nop
						} else {
							v38 = v37 == 8
							if !v38 && v37 != math.MaxUint8 {
								continue
							}
						}
					case 5:
						v39 = int32(uint8(s.Sub_57B500(image.Pt(int(vn3.X0)-1, int(vn3.Y2)), v60)))
						if v39 != 1 && v39 != 6 && v39 != 10 && v39 != 9 && v39 != math.MaxUint8 {
							continue
						}
						*(*uint8)(unsafe.Pointer(&v37)) = uint8(s.Sub_57B500(image.Pt(int(vn3.X0), int(vn3.Y2)-1), v60))
						v37 = int32(uint8(int8(v37)))
						if int32(uint8(int8(v37))) == 1 || v37 == 4 || v37 == 7 {
							// nop
						} else {
							v38 = v37 == 8
							if !v38 && v37 != math.MaxUint8 {
								continue
							}
						}
					case 6:
						v40 = int32(uint8(s.Sub_57B500(image.Pt(int(vn3.X0), int(vn3.Y2)+1), v60)))
						if v40 != 0 && v40 != 5 && v40 != 9 && v40 != 8 && v40 != math.MaxUint8 {
							continue
						}
						v37 = int32(uint8(s.Sub_57B500(image.Pt(int(vn3.X0)-1, int(vn3.Y2)), v60)))
						if v37 == 0 || v37 == 3 || v37 == 10 {
							// nop
						} else {
							v38 = v37 == 7
							if !v38 && v37 != math.MaxUint8 {
								continue
							}
						}
					case 7:
						v41 = int32(uint8(s.Sub_57B500(image.Pt(int(vn3.X0)+1, int(vn3.Y2)), v60)))
						if v41 != 0 && v41 != 5 && v41 != 9 && v41 != 8 && v41 != math.MaxUint8 {
							continue
						}
						v42 = int32(uint8(s.Sub_57B500(image.Pt(int(vn3.X0), int(vn3.Y2)-1), v60)))
						if v42 != 0 && v42 != 3 && v42 != 10 && v42 != 7 && v42 != math.MaxUint8 {
							continue
						}
					}
					v30 = obj
					if sub_50B950(obj, int(vn3.X0), int(pp.Y)+int(vn3.Y2)) != 0 || sub_50B950(obj, int(pp.X)+int(vn3.X0), int(vn3.Y2)) != 0 {
						continue
					}
				}
				if sub_50B870(v30, int(x2), int(y2)) != 0 {
					continue
				}
				if x00 != x2 || y00 != y2 {
					if sub_50C830(v30, x2, y2) == 0 {
						continue
					}
				} else if sub_50C830(v30, x2, y2) == 0 {
					continue
				}
				if v63 != 0 {
					v43 := nox_xxx_pathfind_preCheckWalls2_50B8A0(v30, int(x2), int(y2))
					if v43 != 0 {
						v64 = 1
					} else if sub_50B950(v30, int(vn3.X0), int(vn3.Y2)) == 0 && sub_50B950(v30, int(x2), int(y2)) != 0 {
						continue
					}
				} else {
					v43 := nox_xxx_pathfind_preCheckWalls2_50B8A0(v30, int(x2), int(y2))
					if v43 == 0 {
						continue
					}
					if fnc != nil {
						v44 := fnc(v30, x2, y2)
						if v61 {
							if v44 != 0 {
								v65 = 1
							}
						} else if v44 == 0 {
							continue
						}
					}
				}
			LABEL_32:
				v31 := nox_alloc_visitNode_2386184.NewObject()
				if v31 == nil {
					ai.Log.Printf("%d: %s(#%d), buildPath: Exhausted search storage\n", s.Frame(), v30, v30.NetCode)
					dword_5d4594_1599712 = 1
					s.sub_50C320(v30, v67, nil)
					return
				}
				v31.X0 = uint16(int16(x2))
				v31.Y2 = uint16(int16(y2))
				v31.Field4 = vn3
				v31.Field8 = v77
				v77 = v31
			}
			if s.sub_50AC20(vn3, &v68) != 0 {
				vn3.Flags12 |= 2
				v32 := nox_alloc_visitNode_2386184.NewObject()
				if v32 == nil {
					ai.Log.Printf("%d: %s(#%d), buildPath: Exhausted search storage\n", s.Frame(), obj, obj.NetCode)
					dword_5d4594_1599712 = 1
					s.sub_50C320(obj, v67, nil)
					return
				}
				v32.X0 = v68[0]
				v32.Y2 = v68[1]
				v32.Field4 = vn3
				v32.Field8 = v77
				v77 = v32
			}
			vn3 = vn3.Field8
			if vn3 == nil {
				break
			}
		}
		vn2 = v77
	LABEL_40:
		v33 = nil
		if v64 != 0 {
			v34 := vn2
			if vn2 != nil {
				for {
					v35 := v34.Field8
					if nox_xxx_pathfind_preCheckWalls2_50B8A0(obj, int(v34.X0), int(v34.Y2)) != 0 {
						v33 = v34
					} else if v33 != nil {
						v33.Field8 = v34.Field8
					} else {
						vn2 = v34.Field8
					}
					v34 = v35
					if v35 == nil {
						break
					}
				}
				v33 = nil
			}
			v63 = 0
			v64 = 0
		}
		if v65 != 0 {
			v45 := vn2
			if vn2 != nil {
				for {
					v46 := v45.Field8
					if fnc(obj, int32(v45.X0), int32(v45.Y2)) != 0 {
						v33 = v45
					} else if v33 != nil {
						v33.Field8 = v45.Field8
					} else {
						vn2 = v45.Field8
					}
					v45 = v46
					if v46 == nil {
						break
					}
				}
			}
			v61 = false
			v65 = 0
		}
		if vn2 == nil {
			break
		}
		if a6 != 0 && v66 >= a6 {
			ai.Log.Printf("%d: %s(#%d), buildPath: Reached search depth limit\n", s.Frame(), obj, obj.NetCode)
			dword_5d4594_1599712 = 2
			s.sub_50C320(obj, v67, nil)
			return
		}
		v66++
	}
	ai.Log.Printf("%d: %s(#%d), buildPath: Exhausted search space\n", s.Frame(), obj, obj.NetCode)
	dword_5d4594_1599712 = 2
	s.sub_50C320(obj, v67, nil)
}

func sub_50AB50(x, y int) aiMapIndexFlags {
	p := aiGetMapIndex(x, y)
	if p == nil {
		return 0
	}
	return p.Flags8
}

func (s *Server) sub_50AC20(node *aiVisitNode, out *[2]uint16) int32 {
	x := int32(node.X0)
	y := int32(node.Y2)
	p := aiGetMapIndex(int(x), int(y))
	if (p.Flags8 & 0x3C) == 0 {
		return 0
	}
	dword_5d4594_2386152 = nil
	var pos types.Pointf
	pos.X = float32(float64(x) * 23.0)
	pos.Y = float32(float64(y) * 23.0)
	if p.Flags8&aiIndexHole != 0 {
		obj := s.Sub517B70byClass(pos, object.ClassHole)
		if obj == nil {
			return 0
		}
		if int64(uintptr(obj.CollideData)) == -8 {
			return 0
		}
		cd := (*Point32)(unsafe.Add(obj.CollideData, 8))
		if obj.ObjFlags&0x1000000 != 0 {
			out[0] = uint16(cd.X / 23)
			out[1] = uint16(cd.Y / 23)
			return 1
		}
		return 0
	} else if p.Flags8&aiIndexTransporter != 0 {
		obj := s.Sub517B70byClass(pos, object.ClassTransporter)
		if obj == nil {
			return 0
		}
		targ := *(**server.Object)(unsafe.Add(obj.UpdateData, 12))
		if targ != nil && obj.ObjFlags&0x1000000 != 0 {
			out[0] = uint16(int16(float64(targ.PosVec.X) / 23))
			out[1] = uint16(int16(float64(targ.PosVec.Y) / 23))
			return 1
		}
		return 0
	} else if p.Flags8&aiIndexElevator != 0 {
		obj := s.Sub517B70byClass(pos, object.ClassElevator)
		if obj == nil {
			return 0
		}
		targ := *(**server.Object)(unsafe.Add(obj.UpdateData, 4))
		if targ != nil && obj.ObjFlags&0x1000000 != 0 {
			out[0] = uint16(int16(float64(targ.PosVec.X) / 23))
			out[1] = uint16(int16(float64(targ.PosVec.Y) / 23))
			return 1
		}
		return 0
	} else if p.Flags8&aiIndexElevatorShaft != 0 {
		obj := s.Sub517B70byClass(pos, object.ClassElevatorShaft)
		if obj == nil {
			return 0
		}
		targ := *(**server.Object)(unsafe.Add(obj.UpdateData, 4))
		if targ != nil && obj.ObjFlags&0x1000000 != 0 {
			out[0] = uint16(int16(float64(targ.PosVec.X) / 23))
			out[1] = uint16(int16(float64(targ.PosVec.Y) / 23))
			return 1
		}
		return 0
	} else {
		return 0
	}
}

func (s *Server) Sub517B70byClass(pos types.Pointf, filter object.Class) *server.Object {
	dword_5d4594_2386152 = nil
	s.Map.Sub517B70(pos, func(it *server.Object) {
		if it.Class().HasAny(filter) {
			dword_5d4594_2386152 = it
		}
	})
	return dword_5d4594_2386152
}

func (s *Server) sub_50AEA0(node *aiVisitNode, outPos *types.Pointf, outNetCode *uint32) int32 {
	x := int32(node.X0)
	y := int32(node.Y2)
	p := aiGetMapIndex(int(x), int(y))
	if (p.Flags8 & 0x3C) == 0 {
		return 0
	}
	var filter object.Class
	if p.Flags8&aiIndexHole != 0 {
		filter = object.ClassHole
	} else if p.Flags8&aiIndexTransporter != 0 {
		filter = object.ClassTransporter
	} else if p.Flags8&aiIndexElevator != 0 {
		filter = object.ClassElevator
	} else if p.Flags8&aiIndexElevatorShaft != 0 {
		filter = object.ClassElevatorShaft
	}
	var pos types.Pointf
	pos.X = float32(float64(x) * 23.0)
	pos.Y = float32(float64(y) * 23.0)
	obj := s.Sub517B70byClass(pos, filter)
	if obj == nil || !obj.Flags().Has(object.FlagEnabled) {
		return 0
	}
	*outPos = obj.PosVec
	*outNetCode = obj.NetCode
	return 1
}
func sub_50B8E0(obj *server.Object, x, y int) uint32 {
	p := aiGetMapIndex(x, y)
	if p.Field4 != dword_5d4594_2386164 {
		return 0
	}
	if obj.ObjFlags&0x4000 != 0 {
		return uint32((p.Flags8 >> 9) & 1)
	}
	if p.Flags8&0x100 != 0 {
		return 1
	}
	if sub_534020(obj) != 0 || (p.Flags8&0x400) == 0 {
		return 0
	}
	return 1
}
func sub_50B950(obj *server.Object, x, y int) uint32 {
	p := aiGetMapIndex(int(x), int(y))
	if obj.ObjFlags&0x4000 != 0 {
		return uint32(p.Flags8) & 0x10
	} else {
		return uint32(p.Flags8) & 0x1
	}
}

func (s *Server) Sub_50CB20(a1 *server.Object, a2 *types.Pointf) *server.Waypoint {
	dword_5d4594_2386160++
	var a2a Point32
	a2a.X = int32(float64(a2.X) / 23)
	a2a.Y = int32(float64(a2.Y) / 23)
	nox_xxx_pathfind_preCheckWalls_50C8D0(a1, &a2a)
	nox_alloc_visitNode_2386184.FreeAllObjects()
	v4 := nox_alloc_visitNode_2386184.NewObject()
	v4.X0 = uint16(int16(a2a.X))
	v4.Y2 = uint16(int16(a2a.Y))
	v4.Field4 = nil
	v4.Field8 = nil
	aiGetMapIndex(int(v4.X0), int(v4.Y2)).Field0 = dword_5d4594_2386160
	for {
		var v19 *aiVisitNode
		if v4 == nil {
			break
		}
		for v6 := v4; v6 != nil; v6 = v6.Field8 {
			v7 := int32(v6.X0)
			v8 := int32(v6.Y2)
			if int32(aiGetMapIndex(int(v7), int(v8)).Flags8)&0x40 != 0 && sub_50B870(a1, int(v7), int(v8)) == 0 {
				var v18 types.Pointf
				v18.X = float32(float64(v7*23 + 11))
				v18.Y = float32(float64(v8*23 + 11))
				return s.Sub_518460(v18, 0x80, true)
			}
			v9 := memmap.PtrOff(0x587000, 234284)
			for {
				x2 := int32(uint32(v6.X0) + *(*uint32)(unsafe.Add(v9, -int(4*1))))
				y2 := int32(*(*uint32)(unsafe.Pointer(v9)) + uint32(v6.Y2))
				if p := aiGetMapIndex(int(x2), int(y2)); p != nil && p.Field0 != dword_5d4594_2386160 {
					v16 := int32(*(*uint32)(unsafe.Pointer(v9)) + uint32(v6.Y2))
					p.Field0 = dword_5d4594_2386160
					if sub_50B870(a1, int(x2), int(v16)) == 0 {
						if sub_50C830(a1, x2, y2) != 0 {
							v12 := nox_alloc_visitNode_2386184.NewObject()
							if v12 != nil {
								v12.X0 = uint16(int16(x2))
								v12.Y2 = uint16(int16(y2))
								v12.Field4 = v6
								v12.Field8 = v19
								v19 = v12
							}
						}
					}
				}
				v9 = unsafe.Add(v9, 8)
				if uintptr(v9) >= uintptr(memmap.PtrOff(0x587000, 234316)) {
					break
				}
			}
		}
		v4 = v19
		if v19 == nil {
			break
		}
	}
	return nil
}

func sub_50B870(a1 *server.Object, x, y int) int {
	return bool2int(legacy.Sub_57B630(a1, x, y) != -1)
}
func nox_xxx_pathfind_preCheckWalls2_50B8A0(obj *server.Object, x, y int) int {
	if sub_50B950(obj, x, y) != 0 {
		return 0
	}
	return bool2int(sub_50B8E0(obj, x, y) == 0)
}
func nox_xxx_pathfind_preCheckWalls_50C8D0(obj *server.Object, gpos *Point32) {
	if sub_50B870(obj, int(gpos.X), int(gpos.Y)) != 0 {
		dx := float64(obj.PosVec.X) - (float64(gpos.X)*23.0 + 11.5)
		dy := float64(obj.PosVec.Y) - (float64(gpos.Y)*23.0 + 11.5)
		if math.Abs(dy) >= math.Abs(dx) {
			if dy <= 0.0 {
				gpos.Y--
			} else {
				gpos.Y++
			}
		} else {
			if dx <= 0.0 {
				gpos.X--
			} else {
				gpos.X++
			}
		}
	}
}

func sub_50C830(a1 *server.Object, x, y int32) int32 {
	if a1.ObjFlags&0x4000 != 0 || sub_534020(a1) != 0 {
		return 1
	}
	v4 := memmap.PtrFloat32(0x587000, 234188)
	sx := float32(x * 23)
	sy := float32(y * 23)
	for {
		var v6 types.Pointf
		v6.X = sx + *(*float32)(unsafe.Add(unsafe.Pointer(v4), -int(unsafe.Sizeof(float32(0))*1)))
		v6.Y = sy + *v4
		if legacy.Nox_xxx_tileNFromPoint_411160(v6) == 6 {
			break
		}
		v4 = (*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*2))
		if int32(uintptr(unsafe.Pointer(v4))) >= int32(uintptr(memmap.PtrOff(0x587000, 234220))) {
			return 1
		}
	}
	return 0
}

func (s *Server) sub_50AFA0() {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 float64
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v17 *float32
		v21 int32
		v22 int32
		v23 float32
		v24 float32
		v25 float32
		v26 float32
		v27 float32
		v28 float32
		v29 float32
		v30 float32
		v31 float32
		v32 float32
		v33 float32
		v34 float32
		v35 float32
		v36 float32
		v38 int32
		v39 int32
		v40 int32
		v41 float32
		v42 float32
		a2  types.Pointf
		v44 int32
	)
	dword_5d4594_2386160 = 0
	aiMapIndex = [aiMapIndexSize][aiMapIndexSize]aiMapIndexNode{}
	dword_5d4594_2386164 = 0
	for it := s.Objs.List; it != nil; it = it.Next() {
		nox_xxx_aiTestUnitDangerous_50B2C0(it)
		v1 = int32(it.ObjClass)
		if (v1 & 0x80) == 0 {
			if v1&0x800 != 0 {
				v23 = float32(float64(it.PosVec.X) / 23)
				v2 = int32(v23)
				v24 = float32(float64(it.PosVec.Y) / 23)
				v3 = int32(v24)
				aiGetMapIndex(int(v2), int(v3)).Flags8 |= 0x10
			} else if v1&0x400 != 0 {
				v25 = float32(float64(it.PosVec.X) / 23)
				v4 = int32(v25)
				v26 = float32(float64(it.PosVec.Y) / 23)
				v5 = int32(v26)
				aiGetMapIndex(int(v4), int(v5)).Flags8 |= 0x20
			} else if v1&0x4000 != 0 {
				v27 = float32(float64(it.PosVec.X) / 23)
				v6 = int32(v27)
				v28 = float32(float64(it.PosVec.Y) / 23)
				v7 = int32(v28)
				aiGetMapIndex(int(v6), int(v7)).Flags8 |= 0x4
			} else if (v1 & 0x8000) == 0 {
				if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(it), 16))) & 0x49) == 0 {
					if uint32(v1)&0x400000 != 0 {
						v31 = float32(float64(it.CollideP1.X) / 23)
						v10 = int32(v31)
						v11 = float64(it.CollideP1.Y) / 23
						v12 = v10
						v44 = v10
						v32 = float32(v11)
						v13 = int32(v32)
						v33 = float32(float64(it.CollideP2.X) / 23)
						v39 = int32(v33)
						v34 = float32(float64(it.CollideP2.Y) / 23)
						v14 = int32(v34)
						v15 = v13
						v40 = v14
						for j := v13; v15 <= v14; j = v15 {
							v38 = v12
							if v12 <= v39 {
								for {
									v16p := aiGetMapIndex(int(v12), int(v15))
									v17 = memmap.PtrFloat32(0x587000, 234108)
									for {
										v41 = float32(float64(v38) * 23.0)
										a2.X = v41 + *((*float32)(unsafe.Add(unsafe.Pointer(v17), -int(unsafe.Sizeof(float32(0))*1))))
										v42 = float32(float64(j) * 23.0)
										a2.Y = v42 + *v17
										if sub_547DB0(it, &a2) != 0 {
											v16p.Flags8 |= 1
											if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(it), 16))) & 0x10) == 0 {
												v16p.Flags8 |= 2
											}
											break
										}
										v17 = (*float32)(unsafe.Add(unsafe.Pointer(v17), unsafe.Sizeof(float32(0))*2))
										if int32(uintptr(unsafe.Pointer(v17))) >= int32(uintptr(memmap.PtrOff(0x587000, 234180))) {
											break
										}
									}
									v12++
									v38 = v12
									if v12 > v39 {
										break
									}
								}
								v15 = j
								v14 = v40
								v12 = v44
							}
							v15++
						}
					}
				}
			} else {
				v29 = float32(float64(it.PosVec.X) / 23)
				v8 = int32(v29)
				v30 = float32(float64(it.PosVec.Y) / 23)
				v9 = int32(v30)
				aiGetMapIndex(int(v8), int(v9)).Flags8 |= 0x8
			}
		}
	}
	result := legacy.FirstWaypoint()
	for k := result; result != nil; k = result {
		if sub_579EE0(k, 0x80) != 0 {
			v35 = float32(float64(k.PosVec.X) / 23)
			v21 = int32(v35)
			v36 = float32(float64(k.PosVec.Y) / 23)
			v22 = int32(v36)
			aiGetMapIndex(int(v21), int(v22)).Flags8 |= 0x40
		}
		result = k.WpNext
	}
}

func nox_xxx_pathFindStatus_50CAF0() int {
	return dword_5d4594_1599712
}

func (s *Server) nox_xxx_genPathToPoint_50B9A0(path []types.Pointf, u *server.Object, a4 *types.Pointf) int {
	u.UpdateDataMonster().Field543_0 = 0
	s.nox_xxx_pathFind_50BA00(false, u, &u.PosVec, a4, nil, 0)
	if dword_5d4594_2386180 > len(path) && dword_5d4594_1599712 == 0 {
		dword_5d4594_1599712 = 1
	}
	return nox_xxx_appendWorkPath_50C990(path, 0)
}

func (s *Server) Nox_xxx_generateRetreatPath_50CA00(path []types.Pointf, u *server.Object, a4 *types.Pointf) int {
	u.UpdateDataMonster().Field543_0 = 0
	s.nox_xxx_pathFind_50BA00(true, u, &u.PosVec, a4, s.sub_50CA60, 6)
	if dword_5d4594_2386180 > len(path) && dword_5d4594_1599712 == 0 {
		dword_5d4594_1599712 = 1
	}
	return nox_xxx_appendWorkPath_50C990(path, 0)
}

func (s *Server) sub_50CA60(a4 *server.Object, a2 int32, a3 int32) int {
	var a1 types.Pointf
	dword_5d4594_1599708 := 0
	a1.X = float32(float64(a2)*23.0 + 11.5)
	a1.Y = float32(float64(a3)*23.0 + 11.5)
	s.Map.EachObjInCircle(a1, 100.0, func(it *server.Object) bool {
		if dword_5d4594_1599708 != 1 {
			if s.IsEnemyTo(a4, it) {
				dword_5d4594_1599708 = 1
			}
		}
		return true
	})
	return bool2int(dword_5d4594_1599708 == 0)
}

func (s *Server) Nox_xxx_creatureSetDetailedPath_50D220(obj *server.Object, a2 *types.Pointf) {
	ud := obj.UpdateDataMonster()
	ud.Field67 = 0
	if (s.Frame() - ud.Field70) >= 10 {
		ud.Field68 = *a2
		ud.Field2 = uint32(s.nox_xxx_genPathToPoint_50B9A0(ud.Path[:], obj, a2))
		*(*uint8)(unsafe.Add(unsafe.Pointer(ud), 284)) = uint8(int8(nox_xxx_pathFindStatus_50CAF0()))
		ud.Field70 = s.Frame()
	} else {
		ud.Field2 = 0
		*(*uint8)(unsafe.Add(unsafe.Pointer(ud), 284)) = 1
	}
}

func (s *Server) Sub_50B810(obj *server.Object, pos *types.Pointf) int {
	x := int(float64(pos.X) / 23)
	y := int(float64(pos.Y) / 23)
	if sub_50B870(obj, x, y) != 0 {
		return 0
	}
	return nox_xxx_pathfind_preCheckWalls2_50B8A0(obj, x, y)
}
