package server

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"
)

const MapSize = WallGridSize * common.GridStep

type MapTraceFlags byte

func (f MapTraceFlags) Has(f2 MapTraceFlags) bool {
	return f&f2 != 0
}

const (
	MapTraceFlag1 = MapTraceFlags(0x1)
	MapTraceFlag2 = MapTraceFlags(0x2)
	MapTraceFlag3 = MapTraceFlags(0x4)
	MapTraceFlag4 = MapTraceFlags(0x8)
	MapTraceFlag5 = MapTraceFlags(0x10)
	MapTraceFlag6 = MapTraceFlags(0x20)
	MapTraceFlag7 = MapTraceFlags(0x40)
	MapTraceFlag8 = MapTraceFlags(0x80)
)

type mapIndexBucket struct {
	List      *ObjectIndex
	PartsList *ObjectIndex
	Waypoints *Waypoint
	Tok12     uint32
}

const getInRectStackSize = 2 // FIXME: size is a guess

type serverMap struct {
	Debug serverMapDebug

	indexSize   int
	bucketByPos [][]mapIndexBucket

	eachInRectStackInd int
	eachInRectStack    [getInRectStackSize]uint32
}

func (s *serverMap) Init() {
	s.eachInRectStackInd = -1
	s.indexSize = 70
	s.bucketByPos = make([][]mapIndexBucket, s.indexSize)
	for i := range s.bucketByPos {
		s.bucketByPos[i] = make([]mapIndexBucket, s.indexSize)
	}
}

func (s *serverMap) Free() {
	s.bucketByPos = nil
}

func (s *serverMap) Center() types.Pointf {
	return types.Pointf{X: MapSize / 2, Y: MapSize / 2}
}

func (s *serverMap) addObjToMap(large bool, pos image.Point, obj *Object) {
	if pos.X < 0 || pos.Y < 0 || pos.X >= s.indexSize || pos.Y >= s.indexSize { // see #403
		return
	}
	if large {
		i := int(obj.ObjIndexCur)
		if i >= len(obj.ObjIndex) {
			return
		}
		p := &obj.ObjIndex[i]
		obj.ObjIndexCur++
		*p = ObjectIndex{
			X:      uint16(int16(pos.X)),
			Y:      uint16(int16(pos.Y)),
			Object: obj,
		}
		p2 := s.bucketByPos[pos.X][pos.Y].PartsList
		p.Next = p2
		if p2 != nil {
			p2.Prev = p
		}
		s.bucketByPos[pos.X][pos.Y].PartsList = p
	} else {
		p := &obj.ObjIndexBase
		*p = ObjectIndex{
			X:      uint16(int16(pos.X)),
			Y:      uint16(int16(pos.Y)),
			Object: obj,
		}
		p2 := s.bucketByPos[pos.X][pos.Y].List
		p.Next = p2
		if p2 != nil {
			p2.Prev = p
		}
		s.bucketByPos[pos.X][pos.Y].List = p
	}
}

type DebugObjectIndex struct {
	Pos image.Point
	Obj *Object
}

type DebugMapIndex struct {
	List  []DebugObjectIndex
	Parts []DebugObjectIndex
}

func (s *serverMap) DebugIndex() map[image.Point]DebugMapIndex {
	m := make(map[image.Point]DebugMapIndex)
	for x := 0; x < len(s.bucketByPos); x++ {
		for y := 0; y < len(s.bucketByPos[x]); y++ {
			b := s.bucketByPos[x][y]
			if b.List == nil && b.PartsList == nil {
				continue
			}
			var d DebugMapIndex
			for it := b.List; it != nil; it = it.Next {
				d.List = append(d.List, DebugObjectIndex{
					Pos: image.Point{X: int(it.X), Y: int(it.Y)},
					Obj: it.Object,
				})
			}
			for it := b.PartsList; it != nil; it = it.Next {
				d.Parts = append(d.Parts, DebugObjectIndex{
					Pos: image.Point{X: int(it.X), Y: int(it.Y)},
					Obj: it.Object,
				})
			}
			m[image.Point{X: x, Y: y}] = d
		}
	}
	return m
}

func (s *serverMap) Sub5178E0(flag bool, p *ObjectIndex) {
	if flag {
		if prev := p.Prev; prev != nil {
			prev.Next = p.Next
		} else {
			s.bucketByPos[p.X][p.Y].PartsList = p.Next
		}
		if next := p.Next; next != nil {
			next.Prev = p.Prev
		}
	} else {
		if prev := p.Prev; prev != nil {
			prev.Next = p.Next
		} else {
			s.bucketByPos[p.X][p.Y].List = p.Next
		}
		if next := p.Next; next != nil {
			next.Prev = p.Prev
		}
	}
}

func (s *serverMap) Nox_xxx_waypointMapRegister_5179B0(wp *Waypoint) {
	if wp.Flags&0x2 != 0 {
		return
	}
	pos := wp.Pos()
	x := RoundCoord(pos.X)
	y := RoundCoord(pos.Y)
	wp.KeyX = uint16(int16(x))
	wp.KeyY = uint16(int16(y))
	wp.Flags |= 0x2
	wp.Field13 = nil
	wp2 := s.bucketByPos[x][y].Waypoints
	if wp2 != nil {
		wp2.Field13 = wp
	}
	wp.Field12 = s.bucketByPos[x][y].Waypoints
	s.bucketByPos[x][y].Waypoints = wp
}

func (s *serverMap) Sub517A70(wp *Waypoint) {
	if wp.Flags&0x2 == 0 {
		return
	}
	if wp2 := wp.Field13; wp2 != nil {
		wp2.Field12 = wp.Field12
	} else {
		s.bucketByPos[wp.KeyX][wp.KeyY].Waypoints = wp.Field12
	}
	if wp2 := wp.Field12; wp2 != nil {
		wp2.Field13 = wp.Field13
	}
	wp.Flags &= 0xFFFFFFFD
}

func (s *serverMap) Sub517B70(pos types.Pointf, fnc func(it *Object)) {
	if fnc == nil {
		return
	}
	x := RoundCoord(pos.X)
	y := RoundCoord(pos.Y)
	if x < 0 {
		x = 0
	} else if x >= s.indexSize {
		x = s.indexSize - 1
	}
	if y < 0 {
		y = 0
	} else if y >= s.indexSize {
		y = s.indexSize - 1
	}
	for it := s.bucketByPos[x][y].PartsList; it != nil; it = it.Next {
		fnc(it.Object)
	}
}

func (s *serverMap) Sub517B70byClass(pos types.Pointf, filter object.Class) *Object {
	var found *Object
	s.Sub517B70(pos, func(it *Object) {
		if it.Class().HasAny(filter) {
			found = it
		}
	})
	return found
}

func (s *serverMap) ValidIndexPos(p types.Pointf) bool {
	pi := RoundPos(p)
	return pi.X >= 0 && pi.X < s.indexSize && pi.Y >= 0 && pi.Y < s.indexSize
}

func (s *serverMap) AddObjectToIndex(obj *Object) {
	if f := obj.Flags(); f.Has(object.FlagDestroyed) || f.Has(object.FlagPartitioned) || !f.Has(object.FlagActive) {
		return
	}
	if !obj.Class().Has(object.ClassMissile) {
		obj.UpdateCollider(obj.NewPos)
		sp := RoundPos(obj.CollideP1)
		ep := RoundPos(obj.CollideP2)
		if sp.X < 0 {
			sp.X = 0
		}
		if sp.Y < 0 {
			sp.Y = 0
		}
		if ep.X >= s.indexSize {
			ep.X = s.indexSize - 1
		}
		if ep.Y >= s.indexSize {
			ep.Y = s.indexSize - 1
		}
		obj.ObjIndexCur = 0
		for y := sp.Y; y <= ep.Y; y++ {
			for x := sp.X; x <= ep.X; x++ {
				s.addObjToMap(true, image.Pt(x, y), obj)
			}
		}
	}
	pi := RoundPos(obj.NewPos)
	s.addObjToMap(false, pi, obj)
	obj.ObjFlags |= object.FlagPartitioned
}

func (s *serverMap) EachObjInRect(rect types.Rectf, fnc func(it *Object) bool) {
	if s.eachInRectStackInd >= 1 {
		return
	}
	if fnc == nil {
		return
	}
	s.eachInRectStackInd++
	s.eachInRectStack[s.eachInRectStackInd]++
	defer func() {
		s.eachInRectStackInd--
	}()
	sx := RoundCoord(rect.Min.X)
	sy := RoundCoord(rect.Min.Y)
	ex := RoundCoord(rect.Max.X)
	ey := RoundCoord(rect.Max.Y)
	if sx < 0 {
		sx = 0
	}
	if ex >= s.indexSize {
		ex = s.indexSize - 1
	}
	if sy < 0 {
		sy = 0
	}
	if ey >= s.indexSize {
		ey = s.indexSize - 1
	}
	for y := sy; y <= ey; y++ {
		for x := sx; x <= ex; x++ {
			ptr := &s.bucketByPos[x][y]
			for it := ptr.PartsList; it != nil; it = it.Next {
				obj := it.Object
				tok1 := &obj.Field62[s.eachInRectStackInd]
				tok2 := s.eachInRectStack[s.eachInRectStackInd]
				if *tok1 == tok2 {
					continue
				}
				*tok1 = tok2
				if obj.CollideP1.X < rect.Max.X && obj.CollideP2.X > rect.Min.X &&
					obj.CollideP1.Y < rect.Max.Y && obj.CollideP2.Y > rect.Min.Y {
					if !fnc(obj) {
						return
					}
				}
			}
		}
	}
}

func (s *serverMap) EachObjInCircle(pos types.Pointf, r float32, fnc func(it *Object) bool) {
	rect := types.Rectf{
		Min: pos.Sub(types.Ptf(r, r)),
		Max: pos.Add(types.Ptf(r, r)),
	}
	r2 := r * r
	s.EachObjInRect(rect, func(obj *Object) bool {
		vec := obj.Pos().Sub(pos)
		if vec.X*vec.X+vec.Y*vec.Y > r2 {
			return true
		}
		return fnc(obj)
	})
}

func (s *serverMap) EachMissileInRect(rect types.Rectf, fnc func(it *Object) bool) {
	if fnc == nil {
		return
	}
	sx := RoundCoord(rect.Min.X)
	sy := RoundCoord(rect.Min.Y)
	ex := RoundCoord(rect.Max.X)
	ey := RoundCoord(rect.Max.Y)
	if sx < 0 {
		sx = 0
	}
	if ex >= s.indexSize {
		ex = s.indexSize - 1
	}
	if sy < 0 {
		sy = 0
	}
	if ey >= s.indexSize {
		ey = s.indexSize - 1
	}
	for y := sy; y <= ey; y++ {
		for x := sx; x <= ex; x++ {
			for it := s.bucketByPos[x][y].List; it != nil; it = it.Next {
				obj := it.Object
				if obj.Class().Has(object.ClassMissile) {
					if !fnc(obj) {
						return
					}
				}
			}
		}
	}
}

func (s *serverMap) EachMissileInCircle(pos types.Pointf, r float32, fnc func(it *Object) bool) {
	if fnc == nil {
		return
	}
	sx := RoundCoord(pos.X - r)
	sy := RoundCoord(pos.Y - r)
	ex := RoundCoord(pos.X + r)
	ey := RoundCoord(pos.Y + r)
	if sx < 0 {
		sx = 0
	}
	if ex >= s.indexSize {
		ex = s.indexSize - 1
	}
	if sy < 0 {
		sy = 0
	}
	if ey >= s.indexSize {
		ey = s.indexSize - 1
	}
	r2 := r * r
	for y := sy; y <= ey; y++ {
		for x := sx; x <= ex; x++ {
			for it := s.bucketByPos[x][y].List; it != nil; it = it.Next {
				obj := it.Object
				if obj.Class().Has(object.ClassMissile) {
					dp := pos.Sub(obj.Pos())
					if dp.X*dp.X+dp.Y*dp.Y <= r2 {
						if !fnc(obj) {
							return
						}
					}
				}
			}
		}
	}
}

func (s *serverMap) EachObjAndMissileInRect(rect types.Rectf, fnc func(it *Object) bool) {
	s.EachObjInRect(rect, fnc)
	s.EachMissileInRect(rect, fnc)
}

func (s *serverMap) EachObjAndMissileInCircle(pos types.Pointf, r float32, fnc func(it *Object) bool) {
	s.EachObjInCircle(pos, r, fnc)
	s.EachMissileInCircle(pos, r, fnc)
}

func (s *serverMap) Sub518550Base(rect image.Rectangle, mask byte, scanSub bool, tok *uint32, fnc func(it *Waypoint)) {
	if rect.Min.X < 0 {
		rect.Min.X = 0
	}
	if rect.Max.X >= s.indexSize {
		rect.Max.X = s.indexSize - 1
	}
	if rect.Min.Y < 0 {
		rect.Min.Y = 0
	}
	if rect.Max.Y >= s.indexSize {
		rect.Max.Y = s.indexSize - 1
	}
	for y := rect.Min.Y; y <= rect.Max.Y; y++ {
		for x := rect.Min.X; x <= rect.Max.X; x++ {
			p := &s.bucketByPos[x][y]
			if p.Tok12 != *tok {
				for it := p.Waypoints; it != nil; it = it.Field12 {
					if it.IsEnabled() && it.HasFlag2Mask(mask) {
						cnt := 0
						if scanSub {
							for i := 0; i < int(it.PointsCnt); i++ {
								pt := &it.Points[i]
								wp2 := pt.Waypoint
								if wp2.IsEnabled() && wp2.HasFlag2Mask(mask) {
									cnt++
								}
							}
						}
						if cnt != 0 {
							fnc(it)
						}
					}
				}
				s.bucketByPos[x][y].Tok12 = *tok
			}
		}
	}
}

func (s *Server) MapTraceObstacles(from *Object, p1, p2 types.Pointf) bool {
	rect := types.RectFromPointsf(p1, p2)

	searching := true
	s.Map.EachObjInRect(rect, func(it *Object) bool {
		if !searching {
			return false
		}
		if from == it {
			return true
		}
		if it.Class().HasAny(object.MaskUnits) {
			u2 := it
			if s.IsEnemyTo(from, u2) {
				return true
			}
		} else if !it.Class().HasAny(object.ClassImmobile | object.ClassObstacle) {
			return true
		}
		if it.Flags().HasAny(object.FlagNoCollide|object.FlagAllowOverlap) || it.Class().Has(object.ClassDoor) {
			return true
		}
		pos := it.Pos()
		sh := &it.Shape
		switch sh.Kind {
		case ShapeKindCircle:
			if a3p, ok := PointOnTheLine(p1, p2, it.PosVec); ok {
				dx := a3p.X - pos.X
				dy := a3p.Y - pos.Y
				if dy*dy+dx*dx <= sh.Circle.R2 {
					searching = false
					return false
				}
			}
		case ShapeKindBox:
			if LineTraceXxx(rect, types.RectFromPointsf(
				pos.Add(types.Ptf(sh.Box.LeftTop, sh.Box.LeftBottom)),
				pos.Add(types.Ptf(sh.Box.LeftBottom2, sh.Box.LeftTop2)),
			)) {
				searching = false
				return false
			}
			if LineTraceXxx(rect, types.RectFromPointsf(
				pos.Add(types.Ptf(sh.Box.LeftTop, sh.Box.LeftBottom)),
				pos.Add(types.Ptf(sh.Box.RightTop, sh.Box.RightBottom)),
			)) {
				searching = false
				return false
			}
			if LineTraceXxx(rect, types.RectFromPointsf(
				pos.Add(types.Ptf(sh.Box.RightBottom2, sh.Box.RightTop2)),
				pos.Add(types.Ptf(sh.Box.RightTop, sh.Box.RightBottom)),
			)) {
				searching = false
				return false
			}
			if LineTraceXxx(rect, types.RectFromPointsf(
				pos.Add(types.Ptf(sh.Box.RightBottom2, sh.Box.RightTop2)),
				pos.Add(types.Ptf(sh.Box.LeftBottom2, sh.Box.LeftTop2)),
			)) {
				searching = false
				return false
			}
		}
		return true
	})
	return searching
}

func (s *Server) MapTraceVision(obj1, obj2 *Object) bool {
	pos := obj1.Pos()
	pos2 := obj2.Pos()
	if int8(obj2.Class()) < 0 && obj2.SubClass().Has(0x4) { // TODO: door?
		ud := obj2.UpdateData
		val := *(*uint32)(unsafe.Add(ud, 12))
		sz := DoorSize(byte(val))
		pos2.X = float32(float64(sz.X/2) + float64(pos2.X))
		pos2.Y = float32(float64(sz.Y/2) + float64(pos2.Y))
	}
	rect := types.RectFromPointsf(pos, pos2)
	searching := true
	line := types.RectFromPointsf(pos, pos2)
	s.Map.EachObjInRect(rect, func(it *Object) bool {
		if it == obj1 || it == obj2 {
			return true
		}
		if !it.Flags().Has(object.FlagShadow) {
			return true
		}
		if int8(it.Class()) < 0 { // TODO: door?
			ud := it.UpdateData
			if !it.SubClass().Has(4) {
				val := *(*uint32)(unsafe.Add(ud, 12))
				sz := DoorSize(byte(val))
				p := it.Pos()
				p2 := p.Sub(types.Ptf(float32(sz.X)*0.125, float32(sz.Y)*0.125))
				p3 := p2.Add(types.Ptf(float32(sz.X)*1.125, float32(sz.Y)*1.125))
				if LineTraceXxx(line, types.RectFromPointsf(p2, p3)) {
					searching = false
					return false
				}
			}
			return true
		}
		switch it.Shape.Kind {
		case ShapeKindCircle:
			if a3, ok := PointOnTheLine(pos, pos2, it.Pos()); ok {
				dp := a3.Sub(it.Pos())
				dx, dy := float64(dp.X), float64(dp.Y)
				if dy*dy+dx*dx <= float64(it.Shape.Circle.R2) {
					searching = false
					return false
				}
			}
		case ShapeKindBox:
			p := it.Pos()
			if LineTraceXxx(line, types.RectFromPointsf(
				p.Add(types.Ptf(it.Shape.Box.LeftTop, it.Shape.Box.LeftBottom)),
				p.Add(types.Ptf(it.Shape.Box.LeftBottom2, it.Shape.Box.LeftTop2)),
			)) {
				searching = false
				return false
			}
			if LineTraceXxx(line, types.RectFromPointsf(
				p.Add(types.Ptf(it.Shape.Box.LeftTop, it.Shape.Box.LeftBottom)),
				p.Add(types.Ptf(it.Shape.Box.RightTop, it.Shape.Box.RightBottom)),
			)) {
				searching = false
				return false
			}
			if LineTraceXxx(line, types.RectFromPointsf(
				p.Add(types.Ptf(it.Shape.Box.RightBottom2, it.Shape.Box.RightTop2)),
				p.Add(types.Ptf(it.Shape.Box.RightTop, it.Shape.Box.RightBottom)),
			)) {
				searching = false
				return false
			}
			if LineTraceXxx(line, types.RectFromPointsf(
				p.Add(types.Ptf(it.Shape.Box.RightBottom2, it.Shape.Box.RightTop2)),
				p.Add(types.Ptf(it.Shape.Box.LeftBottom2, it.Shape.Box.LeftTop2)),
			)) {
				searching = false
				return false
			}
		}
		return true
	})
	if !searching {
		return false
	}
	return s.MapTraceRayAt(pos, pos2, nil, nil, 9)
}

func LineTraceXxx(r1, r2 types.Rectf) bool {
	r1 = r1.Canon()
	r2 = r2.Canon()
	if r1.Max.X < r2.Min.X || r1.Min.X > r2.Max.X || r1.Max.Y < r2.Min.Y || r1.Min.Y > r2.Max.Y {
		return false
	}
	if r1.Min.Y == r1.Max.Y && r2.Min.Y == r2.Max.Y {
		return true
	}
	a1w := r1.Max.X - r1.Min.X
	a1h := r1.Max.Y - r1.Min.Y
	a2w := r2.Max.X - r2.Min.X
	a2h := r2.Max.Y - r2.Min.Y
	dx := r2.Min.X - r1.Min.X
	dy := r2.Min.Y - r1.Min.Y
	dd1 := dy*a1w - dx*a1h
	dd2 := a2w*a1h - a2h*a1w
	dd3 := dy*a2w - dx*a2h
	if dd1 == 0.0 || dd2 == 0.0 || dd1 < 0.0 && dd2 > 0.0 {
		return false
	}
	if float64(dd1) > 0.0 && float64(dd2) < 0.0 || fabs(dd2) < fabs(dd1) ||
		dd3 < 0.0 && float64(dd2) > 0.0 || dd3 > 0.0 && float64(dd2) < 0.0 || fabs(dd2) < fabs(dd3) {
		return false
	}
	return true
}

func IntersectLines(v1, v2 types.Rectf) (out types.Pointf, _ bool) {
	v1c := v1.Canon()
	v2c := v2.Canon()
	if v1c.Max.X < v2c.Min.X || v1c.Min.X > v2c.Max.X || v1c.Max.Y < v2c.Min.Y || v1c.Min.Y > v2c.Max.Y {
		return out, false
	}
	dx1 := v1.Max.X - v1.Min.X
	dy1 := v1.Max.Y - v1.Min.Y
	dx2 := v2.Max.X - v2.Min.X
	dy2 := v2.Max.Y - v2.Min.Y
	dx := v2.Min.X - v1.Min.X
	dy := v2.Min.Y - v1.Min.Y
	dd := dx2*dy1 - dy2*dx1
	dd2 := dy*dx1 - dx*dy1
	if dd == 0.0 {
		return out, false
	}
	out.X = dd2*dx2/dd + v2.Min.X
	out.Y = dd2*dy2/dd + v2.Min.Y
	return out, true
}
