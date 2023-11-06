package legacy

/*
#include "defs.h"
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	_ = [1]struct{}{}[516-unsafe.Sizeof(server.Waypoint{})]
	_ = [1]struct{}{}[516-unsafe.Sizeof(nox_waypoint_t{})]
)

type nox_waypoint_t = C.nox_waypoint_t

func asWaypointS(p *nox_waypoint_t) *server.Waypoint {
	return (*server.Waypoint)(unsafe.Pointer(p))
}

func asWaypointC(p *server.Waypoint) *nox_waypoint_t {
	return (*nox_waypoint_t)(p.C())
}

//export nox_server_getWaypointById_579C40
func nox_server_getWaypointById_579C40(a1 int) *nox_waypoint_t {
	return asWaypointC(GetServer().S().WPs.ByInd(a1))
}

//export nox_xxx_waypointGetList_579860
func nox_xxx_waypointGetList_579860() *nox_waypoint_t {
	return asWaypointC(GetServer().S().WPs.First())
}

//export sub_579890
func sub_579890() *nox_waypoint_t {
	return asWaypointC(GetServer().S().WPs.Sub_579890())
}

//export nox_xxx_waypoint_579F00
func nox_xxx_waypoint_579F00(out *C.float2, obj *nox_object_t) int {
	return GetServer().S().Nox_xxx_waypoint_579F00((*types.Pointf)(unsafe.Pointer(out)), asObjectS(obj))
}

//export sub_579C80
func sub_579C80(a1 uint32) *nox_waypoint_t {
	return asWaypointC(GetServer().S().WPs.PendingByInd(int(a1)))
}

//export nox_xxx_waypointNew_5798F0
func nox_xxx_waypointNew_5798F0(x, y float32) *nox_waypoint_t {
	return asWaypointC(GetServer().S().NewWaypoint(types.Ptf(x, y)))
}

//export sub_579AD0
func sub_579AD0(x, y float32) *nox_waypoint_t {
	return asWaypointC(GetServer().S().WPs.Sub_579AD0(types.Ptf(x, y)))
}

//export nox_xxx_waypointNewNotMap_579970
func nox_xxx_waypointNewNotMap_579970(ind int, x, y float32) *nox_waypoint_t {
	return asWaypointC(GetServer().S().WPs.Nox_xxx_waypointNewNotMap_579970(ind, types.Ptf(x, y)))
}

//export sub_579D20
func sub_579D20() {
	GetServer().S().WPs.Sub_579D20()
}

//export nox_xxx_waypoint_5799C0
func nox_xxx_waypoint_5799C0() {
	GetServer().S().Nox_xxx_waypoint_5799C0()
}

//export sub_579E90
func sub_579E90(wp *nox_waypoint_t) {
	GetServer().S().Sub_579E90(asWaypointS(wp))
}
