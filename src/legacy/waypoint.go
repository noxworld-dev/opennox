package legacy

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
)

func nox_server_getWaypointById_579C40(a1 int32) *server.Waypoint {
	return Nox_server_getWaypointById_579C40(int(a1))
}

func FirstWaypoint() *server.Waypoint {
	return nox_xxx_waypointsHead_2523752
}

func NewWaypoint(pos types.Pointf) *server.Waypoint {
	return nox_xxx_waypointNew_5798F0(pos.X, pos.Y)
}
