package server

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const aiMapIndexSize = 256
const dword_587000_234176 = 11.5

type AIVisitNode struct {
	X0      uint16       // 0, 0
	Y2      uint16       // 0, 0
	Field4  *AIVisitNode // 1, 4
	Field8  *AIVisitNode // 2, 8
	Flags12 byte         // 3, 12
	Field13 byte         // 3, 13
	Field14 uint16       // 3, 14
}

type AIMapIndexFlags uint16

const (
	AIIndexElevator      = AIMapIndexFlags(0x4)
	AIIndexElevatorShaft = AIMapIndexFlags(0x8)
	AIIndexHole          = AIMapIndexFlags(0x10)
	AIIndexTransporter   = AIMapIndexFlags(0x20)
)

type AIMapIndexNode struct {
	Index0    uint32
	IndexGen4 uint32
	Flags8    AIMapIndexFlags
	Field10   uint16
}

type serverAIPaths struct {
	s            *Server
	mapIndex     [aiMapIndexSize][aiMapIndexSize]AIMapIndexNode
	MapIndexLast uint32
	mapIndexGen  uint32

	allocVisit alloc.ClassT[AIVisitNode]
	points     []types.Pointf
	pointsCnt  int
	PathStatus int
	lastFrame  uint32
	calculated bool
}

func (s *serverAIPaths) Valid() bool {
	return s.allocVisit.Class != nil
}

func (s *serverAIPaths) ResetVisitNodes() {
	s.allocVisit.FreeAllObjects()
}

func (s *serverAIPaths) NewVisitNode() *AIVisitNode {
	return s.allocVisit.NewObject()
}

func (s *serverAIPaths) ResetIndex() {
	s.MapIndexLast = 0
	s.mapIndexGen = 0
	s.mapIndex = [aiMapIndexSize][aiMapIndexSize]AIMapIndexNode{}
}

func (s *serverAIPaths) PathFindStatus() int {
	return s.PathStatus
}

func (s *serverAIPaths) MapIndex(x, y int) *AIMapIndexNode {
	if x < 0 || x >= aiMapIndexSize || y < 0 || y >= aiMapIndexSize {
		return nil
	}
	return &s.mapIndex[y][x]
}

func (s *serverAIPaths) MapIndexFlags(x, y int) AIMapIndexFlags {
	p := s.MapIndex(x, y)
	if p == nil {
		return 0
	}
	return p.Flags8
}

func (s *serverAIPaths) CheckIndexFlags(obj *Object, x, y int) bool {
	p := s.MapIndex(x, y)
	if obj.Flags().Has(object.FlagAirborne) {
		return p.Flags8&0x10 != 0
	} else {
		return p.Flags8&0x1 != 0
	}
}

func (s *serverAIPaths) ResetPoints() {
	s.pointsCnt = 0
}

func (s *serverAIPaths) appendPoint(p types.Pointf) bool {
	if s.pointsCnt >= len(s.points) {
		return false
	}
	s.points[s.pointsCnt] = p
	s.pointsCnt++
	return true
}

func (s *serverAIPaths) swapPoints() {
	for i := 0; i < s.pointsCnt/2; i++ {
		p1 := &s.points[i]
		p2 := &s.points[s.pointsCnt-i-1]
		*p1, *p2 = *p2, *p1
	}
}

func (s *serverAIPaths) Points() []types.Pointf {
	return s.points[:s.pointsCnt]
}

func (s *serverAIPaths) MaybeAppendWorkPath(path []types.Pointf) int {
	if s.pointsCnt > len(path) && s.PathStatus == 0 {
		s.PathStatus = 1
	}
	return s.appendWorkPath(path, 0)
}

func (s *serverAIPaths) appendWorkPath(path []types.Pointf, ind int) int {
	v3 := 0
	if s.pointsCnt <= 0 {
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
		v6 := s.points[v3]
		v3++
		v5[0] = v6
		v5 = v5[1:]
		if v3 >= s.pointsCnt {
			return v4
		}
	}
}

func (s *serverAIPaths) Init(srv *Server) {
	s.s = srv
	s.allocVisit = alloc.NewClassT("VisitNodes", AIVisitNode{}, 1024)
	s.points, _ = alloc.Make([]types.Pointf{}, 1024)
	s.lastFrame = 0
}
func (s *serverAIPaths) Sub_50B500() {
	s.calculated = false
}
func (s *serverAIPaths) Sub_50B510() {
	s.calculated = false
	s.lastFrame = 0
}
func (s *serverAIPaths) Free() {
	alloc.FreeSlice(s.points)
	s.points = nil
	s.allocVisit.Free()
}

func (s *serverAIPaths) sub50B8E0(obj *Object, x, y int) uint32 {
	p := s.MapIndex(x, y)
	if p.IndexGen4 != s.mapIndexGen {
		return 0
	}
	if obj.ObjFlags&0x4000 != 0 {
		return uint32((p.Flags8 >> 9) & 1)
	}
	if p.Flags8&0x100 != 0 {
		return 1
	}
	if (obj.ObjSubClass>>10)&1 != 0 || (p.Flags8&0x400) == 0 {
		return 0
	}
	return 1
}

func (s *serverAIPaths) Nox_xxx_pathfind_preCheckWalls2_50B8A0(obj *Object, x, y int) bool {
	if s.CheckIndexFlags(obj, x, y) {
		return false
	}
	return s.sub50B8E0(obj, x, y) == 0
}

func (s *serverAIPaths) MaybeIndexObjects() {
	if s.calculated {
		return
	}
	s.IndexObjects()
}

func (s *serverAIPaths) IndexObjects() {
	if (s.s.Frame() - s.lastFrame) < 15 {
		return
	}
	s.lastFrame = s.s.Frame()
	s.mapIndexGen++
	for it := s.s.Objs.List; it != nil; it = it.Next() {
		s.IndexObject(it)
	}
	s.calculated = true
}

func (s *serverAIPaths) IndexObject(obj *Object) {
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
		obj.Nox_xxx_objectUnkUpdateCoords_4E7290()
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
			p := s.MapIndex(int(v6), int(v9))
			v10 := (*uint8)(unsafe.Pointer(&p.Flags8))
			for {
				for _, v11 := range memmap.PtrT[[9]types.Pointf](0x587000, 234104) {
					v21 := float32(float64(v18) * 23.0)
					a2.X = v21 + v11.X
					v22 := float32(float64(a1a) * 23.0)
					a2.Y = v22 + v11.Y
					if v1.Sub547DB0(&a2) {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v10), -int(4*1))) = s.mapIndexGen
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
		v1.Nox_xxx_objectUnkUpdateCoords_4E7290()
	}
}

func (s *serverAIPaths) sub50AEA0(node *AIVisitNode, outPos *types.Pointf, outNetCode *uint32) bool {
	x := int32(node.X0)
	y := int32(node.Y2)
	p := s.MapIndex(int(x), int(y))
	if (p.Flags8 & 0x3C) == 0 {
		return false
	}
	var filter object.Class
	if p.Flags8&AIIndexHole != 0 {
		filter = object.ClassHole
	} else if p.Flags8&AIIndexTransporter != 0 {
		filter = object.ClassTransporter
	} else if p.Flags8&AIIndexElevator != 0 {
		filter = object.ClassElevator
	} else if p.Flags8&AIIndexElevatorShaft != 0 {
		filter = object.ClassElevatorShaft
	}
	var pos types.Pointf
	pos.X = float32(float64(x) * 23.0)
	pos.Y = float32(float64(y) * 23.0)
	obj := s.s.Map.Sub517B70byClass(pos, filter)
	if obj == nil || !obj.Flags().Has(object.FlagEnabled) {
		return false
	}
	*outPos = obj.PosVec
	*outNetCode = obj.NetCode
	return true
}

func (s *serverAIPaths) Sub_50C320(obj *Object, node *AIVisitNode, start *types.Pointf) {
	ud := obj.UpdateDataMonster()
	s.ResetPoints()
	if node == nil {
		return
	}
	if start != nil {
		s.appendPoint(*start)
	} else {
		var (
			netCode uint32
			out     types.Pointf
		)
		if node.Flags12&0x2 != 0 && s.sub50AEA0(node, &out, &netCode) {
			s.appendPoint(out)
			if int(ud.Field543_0) < len(ud.Field535) {
				ud.Field535[ud.Field543_0] = netCode
				ud.Field543_0++
			}
		} else {
			s.appendPoint(types.Pointf{
				X: float32(float64(node.X0)*23.0 + 11.5),
				Y: float32(float64(node.Y2)*23.0 + 11.5),
			})
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
			if s.sub50AEA0(it, &out, &netCode) {
				s.appendPoint(out)
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
						if !s.s.MapTraceRayAt(ppa, ppb, nil, nil, 1) {
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
				s.appendPoint(types.Pointf{
					X: float32(float64(it.X0)*23.0 + 23.0 - 2.3),
					Y: float32(float64(it.Y2)*23.0 + 2.3),
				})
			} else if dy < 0 {
				s.appendPoint(types.Pointf{
					X: float32(float64(it.X0)*23.0 + 23.0 - 2.3),
					Y: float32(float64(it.Y2)*23.0 + 23.0 - 2.3),
				})
			} else {
				s.appendPoint(types.Pointf{
					X: float32(float64(it.X0)*23.0 + 23.0 - 2.3),
					Y: float32(float64(it.Y2)*23.0 + 11.5),
				})
			}
		} else if dx == 0 {
			if dy > 0 {
				s.appendPoint(types.Pointf{
					X: float32(float64(it.X0)*23.0 + 11.5),
					Y: float32(float64(it.Y2)*23.0 + 2.3),
				})
			} else if dy < 0 {
				s.appendPoint(types.Pointf{
					X: float32(float64(it.X0)*23.0 + 11.5),
					Y: float32(float64(it.Y2)*23.0 + 23.0 - 2.3),
				})
			}
		} else {
			if dy < 0 {
				s.appendPoint(types.Pointf{
					X: float32(float64(it.X0)*23.0 + 2.3),
					Y: float32(float64(it.Y2)*23.0 + 23.0 - 2.3),
				})
			} else if dy == 0 {
				s.appendPoint(types.Pointf{
					X: float32(float64(it.X0)*23.0 + 2.3),
					Y: float32(float64(it.Y2)*23.0 + 11.5),
				})
			} else {
				s.appendPoint(types.Pointf{
					X: float32(float64(it.X0)*23.0 + 2.3),
					Y: float32(float64(it.Y2)*23.0 + 2.3),
				})
			}
		}
	}
	s.swapPoints()
}

func (s *serverAIPaths) HasNoEnemiesAround(obj *Object, x, y int) bool {
	found := false
	var pos types.Pointf
	pos.X = float32(float64(x)*23.0 + 11.5)
	pos.Y = float32(float64(y)*23.0 + 11.5)
	s.s.Map.EachObjInCircle(pos, 100.0, func(it *Object) bool {
		if !found && s.s.IsEnemyTo(obj, it) {
			found = true
		}
		return true
	})
	return !found
}
