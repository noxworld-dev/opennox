package opennox

/*
#include "defs.h"
extern nox_waypoint_t* nox_xxx_waypointsHead_2523752;
*/
import "C"
import (
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"
)

func asWaypoint(p unsafe.Pointer) *Waypoint {
	return (*Waypoint)(p)
}

func asWaypointC(p *C.nox_waypoint_t) *Waypoint {
	return asWaypoint(unsafe.Pointer(p))
}

func (s *Server) firstWaypoint() *Waypoint {
	return asWaypointC(C.nox_xxx_waypointsHead_2523752)
}

func (s *Server) getWaypointByID(id string) *Waypoint {
	for w := s.firstWaypoint(); w != nil; w = w.Next() {
		if w.equalID(id) {
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
func nox_server_getWaypointById_579C40(a1 C.int) *C.uint32_t {
	return (*C.uint32_t)(unsafe.Pointer(noxServer.getWaypointByInd(int(a1))))
}

func (s *Server) getWaypointGroupByID(id string) *script.WaypointGroup {
	g := getMapGroupByID(id, 1)
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
type Waypoint nox_waypoint_t

func (w *Waypoint) C() unsafe.Pointer {
	return unsafe.Pointer(w)
}

func (w *Waypoint) Next() *Waypoint {
	return asWaypointC(w.next)
}

func (w *Waypoint) Ind() int {
	return int(w.ind)
}

func (w *Waypoint) ID() string {
	return GoString(&w.name[0])
}

func (w *Waypoint) equalID(id2 string) bool {
	id := w.ID()
	if id == "" {
		return false
	}
	return id == id2 || strings.HasSuffix(id, ":"+id2)
}

func (w *Waypoint) String() string {
	return "Waypoint(" + w.ID() + ")"
}

func (w *Waypoint) IsEnabled() bool {
	return w != nil && w.flags&0x1 != 0
}

func (w *Waypoint) Enable(enable bool) {
	if enable {
		w.flags |= 0x1
	} else {
		w.flags &^= 0x1
	}
}

func (w *Waypoint) PosC() *C.float2 {
	return &w.pos
}

func (w *Waypoint) Pos() types.Pointf {
	return types.Pointf{
		X: float32(w.pos.field_0),
		Y: float32(w.pos.field_4),
	}
}

func (w *Waypoint) SetPos(p types.Pointf) {
	w.pos.field_0 = C.float(p.X)
	w.pos.field_4 = C.float(p.Y)
}
