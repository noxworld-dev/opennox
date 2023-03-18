package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func asWaypoint(p unsafe.Pointer) *Waypoint {
	return (*Waypoint)(p)
}

func asWaypointS(p *server.Waypoint) *Waypoint {
	return asWaypoint(unsafe.Pointer(p))
}

func (s *Server) newWaypoint(pos types.Pointf) *Waypoint {
	return asWaypointS(legacy.NewWaypoint(pos))
}

func (s *Server) firstWaypoint() *Waypoint {
	return asWaypointS(legacy.FirstWaypoint())
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
