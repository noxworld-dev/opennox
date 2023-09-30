package opennox

import (
	"math"

	"github.com/noxworld-dev/opennox-lib/object"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_updateSprings_5113A0() {
	noxServer.springs.Update()
}

type serverSprings struct {
	head *Spring
}

type Spring struct {
	obj1    *server.Object
	obj2    *server.Object
	force   float32
	length  float32
	maxDist float32
	curLen  float32
	prevLen float32
	flags   uint32
	next    *Spring
	prev    *Spring
}

func (s *serverSprings) Reset() {
	s.head = nil
}

func (s *serverSprings) listRemove(p *Spring) {
	if prev := p.prev; prev != nil {
		prev.next = p.next
	} else {
		s.head = p.next
	}
	if next := p.next; next != nil {
		next.prev = p.prev
	}
	*p = Spring{}
}

func (s *serverSprings) listAdd(p *Spring) {
	p.next = s.head
	p.prev = nil
	if s.head != nil {
		s.head.prev = p
	}
	s.head = p
}

func (s *serverSprings) Add(obj1, obj2 *server.Object) {
	if obj1 == nil || obj2 == nil {
		return
	}
	if obj1.Flags().Has(object.FlagDestroyed) || obj2.Flags().Has(object.FlagDestroyed) {
		return
	}
	p1, p2 := obj1.Pos(), obj2.Pos()
	dp := p2.Sub(p1)
	dx := float64(dp.X)
	dy := float64(dp.Y)
	dist := float32(math.Sqrt(dx*dx + dy*dy))
	s.listAdd(&Spring{
		obj1:    obj1,
		obj2:    obj2,
		force:   60,
		maxDist: 256,
		flags:   0x1,
		length:  dist,
		curLen:  dist,
		prevLen: dist,
	})
}

func (s *serverSprings) Update() {
	var next *Spring
	for it := s.head; it != nil; it = next {
		next = it.next

		obj1 := it.obj1
		obj2 := it.obj2
		if obj1 == nil || obj2 == nil {
			s.listRemove(it)
			continue
		}
		if obj1.Flags().Has(object.FlagDestroyed) || obj2.Flags().Has(object.FlagDestroyed) {
			s.listRemove(it)
			continue
		}
		p1, p2 := obj1.Pos(), obj2.Pos()
		dp := p2.Sub(p1)
		dx := float64(dp.X)
		dy := float64(dp.Y)
		dist := float32(math.Sqrt(dy*dy + dx*dx))
		it.curLen = dist
		if dist > it.maxDist {
			s.listRemove(it)
			continue
		}
		dl := dist - it.length
		if it.flags&0x1 != 0 || dl >= 0.0 {
			if dl > it.length {
				dl = it.length
			}
			dv := dp.Div(dist).Mul(dl * it.force)
			obj1.SObj().Sub548600(dv.Mul(+1))
			legacy.Nox_xxx_unitHasCollideOrUpdateFn_537610(obj1.SObj())
			obj2.SObj().Sub548600(dv.Mul(-1))
			legacy.Nox_xxx_unitHasCollideOrUpdateFn_537610(obj2.SObj())
			it.prevLen = dist
		}
	}
}
