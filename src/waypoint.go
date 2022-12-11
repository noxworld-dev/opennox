package opennox

/*
#include "defs.h"
extern nox_waypoint_t* nox_xxx_waypointsHead_2523752;
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

func asWaypoint(p unsafe.Pointer) *Waypoint {
	return (*Waypoint)(p)
}

func asWaypointC(p *nox_waypoint_t) *Waypoint {
	return asWaypoint(unsafe.Pointer(p))
}

var _ = [1]struct{}{}[516-unsafe.Sizeof(server.Waypoint{})]

func asWaypointS(p *server.Waypoint) *Waypoint {
	return asWaypoint(unsafe.Pointer(p))
}

func (s *Server) firstWaypoint() *Waypoint {
	return asWaypointC(C.nox_xxx_waypointsHead_2523752)
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

//export nox_server_getWaypointById_579C40
func nox_server_getWaypointById_579C40(a1 C.int) *nox_waypoint_t {
	return noxServer.getWaypointByInd(int(a1)).C()
}

func (s *Server) getWaypointGroupByID(id string) *script.WaypointGroup {
	g := s.getMapGroupByID(id, 1)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Waypoint
	for wp := g.FirstItem(); wp != nil; wp = wp.Next() {
		ind := int(*(*int32)(wp.Payload()))
		if wl := s.getWaypointByInd(ind); wl != nil {
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

type nox_waypoint_t = C.nox_waypoint_t
type Waypoint server.Waypoint

func (w *Waypoint) C() *nox_waypoint_t {
	return (*nox_waypoint_t)(unsafe.Pointer(w))
}

func (w *Waypoint) S() *server.Waypoint {
	return (*server.Waypoint)(unsafe.Pointer(w))
}

func (w *Waypoint) Next() *Waypoint {
	return asWaypointS(w.WpNext)
}

func (w *Waypoint) Ind() int {
	return int(w.Index)
}

func (w *Waypoint) ID() string {
	return w.S().ID()
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

func (w *Waypoint) Toggle() {
	w.S().Toggle()
}

func (w *Waypoint) Pos() types.Pointf {
	return w.S().Pos()
}

func (w *Waypoint) SetPos(p types.Pointf) {
	w.S().SetPos(p)
}
