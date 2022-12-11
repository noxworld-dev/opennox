package noxscript

import (
	"image"

	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns"
	"github.com/noxworld-dev/opennox-lib/types"
)

type VM interface {
	NoxScript() ns.Implementation

	DPos() image.Point
	DPosf() types.Pointf
	NameSuff() string

	PushU32(v uint32)
	PushI32(v int32)
	PushF32(v float32)
	PushBool(v bool)
	PushString(str string)
	PushHandleNS(h ns.Handle)

	PopI32() int32
	PopU32() uint32
	PopF32() float32
	PopBool() bool
	PopString() string
	PopPoint() image.Point
	PopPointf() types.Pointf
	PopWallGroupNS() ns.WallGroupObj
	PopWaypointNS() ns.WaypointObj
	PopWpGroupNS() ns.WaypointGroupObj
	PopObjectNS() ns.Obj
	PopObjGroupNS() ns.ObjGroup
}
