package server

import (
	"image"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"
)

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
	List0     *ObjectIndex
	List4     *ObjectIndex
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

func (s *serverMap) addObjToMap(flag bool, pos image.Point, obj *Object) {
	if pos.X < 0 || pos.Y < 0 || pos.X >= s.indexSize || pos.Y >= s.indexSize { // see #403
		return
	}
	if flag {
		i := int(obj.ObjIndexCur)
		if i >= len(obj.ObjIndex) {
			return
		}
		p := &obj.ObjIndex[i]
		obj.ObjIndexCur++
		*p = ObjectIndex{
			X:     uint16(int16(pos.X)),
			Y:     uint16(int16(pos.Y)),
			Obj12: obj.SObj(),
		}
		p2 := s.bucketByPos[pos.X][pos.Y].List4
		p.Next4 = p2
		if p2 != nil {
			p2.Prev8 = p
		}
		s.bucketByPos[pos.X][pos.Y].List4 = p
	} else {
		p := &obj.ObjIndexBase
		*p = ObjectIndex{
			X:     uint16(int16(pos.X)),
			Y:     uint16(int16(pos.Y)),
			Obj12: obj.SObj(),
		}
		p2 := s.bucketByPos[pos.X][pos.Y].List0
		p.Next4 = p2
		if p2 != nil {
			p2.Prev8 = p
		}
		s.bucketByPos[pos.X][pos.Y].List0 = p
	}
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
	sx := RoundCoord(rect.Left)
	sy := RoundCoord(rect.Top)
	ex := RoundCoord(rect.Right)
	ey := RoundCoord(rect.Bottom)
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
			for it := ptr.List4; it != nil; it = it.Next4 {
				obj := it.Obj12
				tok1 := &obj.Field62[s.eachInRectStackInd]
				tok2 := s.eachInRectStack[s.eachInRectStackInd]
				if *tok1 == tok2 {
					continue
				}
				*tok1 = tok2
				if obj.CollideP1.X < rect.Right && obj.CollideP2.X > rect.Left &&
					obj.CollideP1.Y < rect.Bottom && obj.CollideP2.Y > rect.Top {
					if !fnc(obj) {
						return
					}
				}
			}
		}
	}
}

func (s *serverMap) Sub5178E0(flag bool, p *ObjectIndex) {
	if flag {
		if prev := p.Prev8; prev != nil {
			prev.Next4 = p.Next4
		} else {
			s.bucketByPos[p.X][p.Y].List4 = p.Next4
		}
		if next := p.Next4; next != nil {
			next.Prev8 = p.Prev8
		}
	} else {
		if prev := p.Prev8; prev != nil {
			prev.Next4 = p.Next4
		} else {
			s.bucketByPos[p.X][p.Y].List0 = p.Next4
		}
		if next := p.Next4; next != nil {
			next.Prev8 = p.Prev8
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
	for it := s.bucketByPos[x][y].List4; it != nil; it = it.Next4 {
		fnc(it.Obj12)
	}
}

func (s *serverMap) ValidIndexPos(p types.Pointf) bool {
	pi := RoundPos(p)
	return pi.X >= 0 && pi.X < s.indexSize && pi.Y >= 0 && pi.Y < s.indexSize
}

func (s *serverMap) AddMissileXxx(obj *Object) {
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
	obj.ObjFlags |= uint32(object.FlagPartitioned)
}

func (s *serverMap) eachMissileInRect(rect types.Rectf, fnc func(it *Object) bool) {
	if fnc == nil {
		return
	}
	sx := RoundCoord(rect.Left)
	sy := RoundCoord(rect.Top)
	ex := RoundCoord(rect.Right)
	ey := RoundCoord(rect.Bottom)
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
			for it := s.bucketByPos[x][y].List0; it != nil; it = it.Next4 {
				obj := it.Obj12
				if obj.Class().Has(object.ClassMissile) {
					if !fnc(obj) {
						return
					}
				}
			}
		}
	}
}

func (s *serverMap) EachObjAndMissileInRect(rect types.Rectf, fnc func(it *Object) bool) {
	s.EachObjInRect(rect, fnc)
	s.eachMissileInRect(rect, fnc)
}

func (s *serverMap) EachMissilesInCircle(pos types.Pointf, r float32, fnc func(it *Object) bool) {
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
			for it := s.bucketByPos[x][y].List0; it != nil; it = it.Next4 {
				obj := it.Obj12
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

func (s *serverMap) EachObjInCircle(pos types.Pointf, r float32, fnc func(it *Object) bool) {
	rect := types.Rectf{
		Left:   pos.X - r,
		Top:    pos.Y - r,
		Right:  pos.X + r,
		Bottom: pos.Y + r,
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
