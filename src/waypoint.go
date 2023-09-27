package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func asWaypoint(p unsafe.Pointer) *Waypoint {
	return (*Waypoint)(p)
}

func asWaypointS(p *server.Waypoint) *Waypoint {
	return asWaypoint(unsafe.Pointer(p))
}

func (s *Server) newWaypoint(pos types.Pointf) *Waypoint {
	return asWaypointS(s.NewWaypoint(pos))
}

func (s *Server) firstWaypoint() *Waypoint {
	return asWaypointS(s.WPs.First())
}

func (s *Server) getWaypointByID(id string) *Waypoint {
	for w := s.firstWaypoint(); w != nil; w = w.Next() {
		if w.EqualID(id) {
			return w
		}
	}
	return nil
}

func (s *Server) getWaypointByInd(ind int) *Waypoint {
	for w := s.firstWaypoint(); w != nil; w = w.Next() {
		if w.Ind() == ind {
			return w
		}
	}
	return nil
}

func nox_server_getWaypointById_579C40(a1 int) *server.Waypoint {
	return noxServer.getWaypointByInd(a1).S()
}

func (s *Server) getWaypointGroupByID(id string) *script.WaypointGroup {
	g := s.GroupByID(id, server.MapGroupWaypoints)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Waypoint
	for it := g.First(); it != nil; it = it.Next() {
		if wl := s.getWaypointByInd(it.Data1()); wl != nil {
			list = append(list, wl)
		}
	}
	return script.NewWaypointGroup(id, list...)
}

func (s *Server) getWaypoints() []*Waypoint {
	var out []*Waypoint
	for w := s.firstWaypoint(); w != nil; w = w.Next() {
		out = append(out, w)
	}
	return out
}

type Waypoint server.Waypoint

func (w *Waypoint) S() *server.Waypoint {
	return (*server.Waypoint)(unsafe.Pointer(w))
}

func (w *Waypoint) Next() *Waypoint {
	return asWaypointS(w.WpNext)
}

func (w *Waypoint) Ind() int {
	return int(w.Index)
}

func (w *Waypoint) ScriptID() int {
	return int(w.Index)
}

func (w *Waypoint) WaypointScriptID() int {
	return int(w.Index)
}

func (w *Waypoint) ID() string {
	return w.S().ID()
}

func (w *Waypoint) SetID(id string) {
	w.S().SetID(id)
}

func (w *Waypoint) Name() string {
	return w.S().ID()
}

func (w *Waypoint) SetName(name string) {
	w.S().SetID(name)
}

func (w *Waypoint) EqualID(id2 string) bool {
	return w.S().EqualID(id2)
}

func (w *Waypoint) String() string {
	return w.S().String()
}

func (w *Waypoint) IsEnabled() bool {
	return w.S().IsEnabled()
}

func (w *Waypoint) Enable(enable bool) {
	w.S().Enable(enable)
}

func (w *Waypoint) Toggle() bool {
	return w.S().Toggle()
}

func (w *Waypoint) Pos() types.Pointf {
	return w.S().Pos()
}

func (w *Waypoint) SetPos(p types.Pointf) {
	w.S().SetPos(p)
}

func sub_579EE0(a1 *server.Waypoint, a2 uint8) int {
	return bool2int((int32(a2) & int32(a1.Flags2)) != 0)
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

func sub_5798A0(a1 *server.Waypoint) *server.Waypoint {
	if a1 != nil {
		return a1.WpNext
	} else {
		return nil
	}
}
func (s *Server) sub_579CA0() int32 {
	for it1 := s.WPs.Pending; it1 != nil; it1 = it1.WpNext {
		it1.Field1 = it1.Index
	}
	for it := s.WPs.Pending; it != nil; it = it.WpNext {
		if int32(it.PointsCnt) != 0 {
			for i := 0; i < int(it.PointsCnt); i++ {
				pt := &it.Points[i]
				pt.Waypoint = s.PendingWaypointByInd579C60(it.Field348[i])
				if pt.Waypoint == nil {
					return 0
				}
			}
		}
	}
	return 1
}
func (s *Server) Sub_579D20() {
	v0 := s.WPs.Nox_xxx_waypoint_5798C0()
	for it := s.WPs.Pending; it != nil; it = it.WpNext {
		it.Field1 = it.Index
		it.Index = v0
		v0++
	}
	for it := s.WPs.Pending; it != nil; it = it.WpNext {
		j := 0
		for i := 0; i < int(it.PointsCnt); i++ {
			v5 := &it.Points[j]
			v5.Waypoint = s.PendingWaypointByInd579C60(it.Field348[i])
			if v5.Waypoint != nil {
				j++
			}
		}
		it.PointsCnt = uint8(j)
	}
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
		if sub_579EE0(wp, 0x80) != 0 && wp.Flags&1 != 0 {
			s.WPs.CntXxx++
		}
	}
	if s.WPs.CntXxx == 0 {
		return 0
	}
	cnt := s.Rand.Logic.IntClamp(0, s.WPs.CntXxx-1)
	for wp := s.WPs.First(); wp != nil; wp = wp.WpNext {
		if sub_579EE0(wp, 0x80) == 0 {
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
