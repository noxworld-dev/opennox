package opennox

import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s *Server) getWaypointGroupByID(id string) *script.WaypointGroup {
	g := s.GroupByID(id, server.MapGroupWaypoints)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Waypoint
	for it := g.First(); it != nil; it = it.Next() {
		if wl := s.WPs.ByInd(it.Data1()); wl != nil {
			list = append(list, wl)
		}
	}
	return script.NewWaypointGroup(id, list...)
}

func (s *Server) Nox_xxx_waypoint_5799C0() {
	var next *server.Waypoint
	for it := s.WPs.Pending; it != nil; it = next {
		next = it.WpNext
		it.WpNext = s.WPs.List
		if s.WPs.List != nil {
			s.WPs.List.WpPrev = it
		}
		s.WPs.List = it
		if noxflags.HasGame(1) {
			s.Map.Nox_xxx_waypointMapRegister_5179B0(it)
		}
	}
	s.WPs.Pending = nil
	s.WPs.Sub_579A30()
}

func (s *Server) nox_xxx_waypointDeleteAll_579DD0() {
	var next *server.Waypoint
	for it := s.WPs.First(); it != nil; it = next {
		next = it.WpNext
		if noxflags.HasGame(1) {
			s.Map.Sub517A70(it)
		}
		alloc.Free(it)
	}
	s.WPs.List = nil
	s.WPs.Pending = nil
	s.WPs.CntXxx = 0
}

func (s *Server) NewWaypoint(pos types.Pointf) *server.Waypoint { // nox_xxx_waypointNew_5798F0
	wp, _ := alloc.New(server.Waypoint{})
	v3 := s.WPs.Nox_xxx_waypoint_5798C0()
	v4 := int32(wp.Flags)
	wp.Index = v3
	wp.PosVec = pos
	wp.Flags = uint32(v4 | 1)
	wp.WpNext = s.WPs.List
	if s.WPs.List != nil {
		s.WPs.List.WpPrev = wp
	}
	s.WPs.List = wp
	if noxflags.HasGame(1) {
		s.Map.Nox_xxx_waypointMapRegister_5179B0(wp)
	}
	return wp
}

func (s *Server) Sub_579E90(wp *server.Waypoint) {
	wp.Flags |= 0x1000000
	wp.WpNext = s.WPs.Pending
	if s.WPs.Pending != nil {
		s.WPs.Pending.WpPrev = wp
	}
	s.WPs.Pending = wp
	if noxflags.HasGame(1) {
		s.Map.Nox_xxx_waypointMapRegister_5179B0(wp)
	}
}

func (s *Server) Nox_xxx_waypoint_579F00(out *types.Pointf, obj *server.Object) int {
	var flag *server.Object
	if noxflags.HasGame(noxflags.GameModeCTF) && obj != nil {
		for it := s.Objs.First(); it != nil; it = it.Next() {
			if it.Class().Has(object.ClassFlag) && !obj.TeamPtr().SameAs(it.TeamPtr()) {
				flag = it
				break
			}
		}
	}
	s.WPs.CntXxx = 0
	for wp := s.WPs.First(); wp != nil; wp = wp.WpNext {
		if wp.HasFlag2Mask(0x80) && wp.Flags&1 != 0 {
			s.WPs.CntXxx++
		}
	}
	if s.WPs.CntXxx == 0 {
		return 0
	}
	cnt := s.Rand.Logic.IntClamp(0, s.WPs.CntXxx-1)
	for wp := s.WPs.First(); wp != nil; wp = wp.WpNext {
		if !wp.HasFlag2Mask(0x80) {
			continue
		}
		if (wp.Flags & 1) == 0 {
			continue
		}
		if noxflags.HasGame(noxflags.GameModeCTF) && flag != nil && obj != nil {
			v7 := (*types.Pointf)(flag.UpdateData)
			if s.MapTraceRayAt(*v7, wp.PosVec, nil, nil, 9) {
				continue
			}
		}
		if cnt == 0 {
			*out = wp.PosVec
			return 1
		}
		cnt--
	}
	return 0
}
