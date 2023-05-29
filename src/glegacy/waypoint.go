package legacy

/*
#include "defs.h"
extern nox_waypoint_t* nox_xxx_waypointsHead_2523752;
nox_waypoint_t* nox_xxx_waypointNew_5798F0(float a1, float a2);
*/

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_server_getWaypointById_579C40 func(a1 int) *server.Waypoint
)

var (
	_ = [1]struct{}{}[516-unsafe.Sizeof(server.Waypoint{})]
	_ = [1]struct{}{}[516-unsafe.Sizeof(nox_waypoint_t{})]
)

type nox_waypoint_t = nox_waypoint_t

func asWaypointS(p *nox_waypoint_t) *server.Waypoint {
	return (*server.Waypoint)(unsafe.Pointer(p))
}

func asWaypointC(p *server.Waypoint) *nox_waypoint_t {
	return (*nox_waypoint_t)(p.C())
}

// nox_server_getWaypointById_579C40
func nox_server_getWaypointById_579C40(a1 int) *nox_waypoint_t {
	return asWaypointC(Nox_server_getWaypointById_579C40(a1))
}

func FirstWaypoint() *server.Waypoint {
	return asWaypointS(nox_xxx_waypointsHead_2523752)
}

func NewWaypoint(pos types.Pointf) *server.Waypoint {
	return asWaypointS(nox_xxx_waypointNew_5798F0(float32(pos.X), float32(pos.Y)))
}
