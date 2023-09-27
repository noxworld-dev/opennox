package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
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

func NewWaypoint(pos types.Pointf) *server.Waypoint {
	return nox_xxx_waypointNew_5798F0(pos.X, pos.Y)
}

func FirstWaypoint() *server.Waypoint {
	return nox_xxx_waypointsHead_2523752
}
func nox_xxx_waypointGetList_579860() *server.Waypoint {
	return nox_xxx_waypointsHead_2523752
}

var nox_xxx_waypointsHead_2523752 *server.Waypoint
var dword_5d4594_2523756 *server.Waypoint
var dword_5d4594_2523760 uint32

func nox_xxx_waypoint_5798C0() uint32 {
	nextInd := uint32(1)
	for it := nox_xxx_waypointsHead_2523752; it != nil; it = it.WpNext {
		if nextInd <= it.Index {
			nextInd = it.Index + 1
		}
	}
	return nextInd
}

func nox_xxx_waypoint_5799C0() {
	var next *server.Waypoint
	for it := dword_5d4594_2523756; it != nil; it = next {
		next = it.WpNext
		it.WpNext = nox_xxx_waypointsHead_2523752
		if nox_xxx_waypointsHead_2523752 != nil {
			nox_xxx_waypointsHead_2523752.WpPrev = it
		}
		nox_xxx_waypointsHead_2523752 = it
		if noxflags.HasGame(1) {
			nox_xxx_waypointMapRegister_5179B0(it)
		}
	}
	dword_5d4594_2523756 = nil
	sub_579A30()
}

func sub_579A30() {
	for wp := nox_xxx_waypointGetList_579860(); wp != nil; wp = nox_xxx_waypointNext_579870(wp) {
		wp.Flags2 = 0
		for i := 0; i < int(wp.PointsCnt); i++ {
			pt := &wp.Points[i]
			wp.Flags2 |= pt.Ind
		}
		for wp2 := nox_xxx_waypointGetList_579860(); wp2 != nil; wp2 = nox_xxx_waypointNext_579870(wp2) {
			for i := 0; i < int(wp2.PointsCnt); i++ {
				pt := &wp2.Points[i]
				if pt.Waypoint == wp {
					wp.Flags2 |= pt.Ind
				}
			}
		}
	}
}

func nox_xxx_waypointDeleteAll_579DD0() {
	var next *server.Waypoint
	for it := nox_xxx_waypointsHead_2523752; it != nil; it = next {
		next = it.WpNext
		if noxflags.HasGame(1) {
			sub_517A70(it)
		}
		alloc.Free(it)
	}
	nox_xxx_waypointsHead_2523752 = nil
	dword_5d4594_2523756 = nil
	dword_5d4594_2523760 = 0
}

func nox_xxx_waypointNew_5798F0(a1 float32, a2 float32) *server.Waypoint {
	wp, _ := alloc.New(server.Waypoint{})
	v3 := nox_xxx_waypoint_5798C0()
	v4 := int32(wp.Flags)
	wp.Index = v3
	wp.PosVec.X = a1
	wp.PosVec.Y = a2
	wp.Flags = uint32(v4 | 1)
	wp.WpNext = nox_xxx_waypointsHead_2523752
	if nox_xxx_waypointsHead_2523752 != nil {
		nox_xxx_waypointsHead_2523752.WpPrev = wp
	}
	nox_xxx_waypointsHead_2523752 = wp
	if noxflags.HasGame(1) {
		nox_xxx_waypointMapRegister_5179B0(wp)
	}
	return wp
}
func sub_579AD0(x float32, y float32) *server.Waypoint {
	var out *server.Waypoint
	min := float32(100.0)
	for it := nox_xxx_waypointsHead_2523752; it != nil; it = it.WpNext {
		dx := float64(it.PosVec.X - x)
		dy := float64(it.PosVec.Y - y)
		dd := dy*dy + dx*dx
		if dd < float64(min) {
			min = float32(dd)
			out = it
		}
	}
	return out
}

func nox_xxx_waypointNewNotMap_579970(a1 int32, a2 float32, a3 float32) *server.Waypoint {
	wp, _ := alloc.New(server.Waypoint{})
	wp.Index = uint32(a1)
	wp.PosVec.X = a2
	wp.PosVec.Y = a3
	wp.Flags |= 0x1
	wp.WpNext = dword_5d4594_2523756
	dword_5d4594_2523756 = wp
	return wp
}
func sub_579890() *server.Waypoint {
	return dword_5d4594_2523756
}
func sub_5798A0(a1 *server.Waypoint) *server.Waypoint {
	if a1 != nil {
		return a1.WpNext
	} else {
		return nil
	}
}
func sub_579C80(a1 int32) *server.Waypoint {
	for it := dword_5d4594_2523756; it != nil; it = it.WpNext {
		if it.Index == uint32(a1) {
			return it
		}
	}
	return nil
}
func sub_579CA0() int32 {
	for it1 := dword_5d4594_2523756; it1 != nil; it1 = it1.WpNext {
		it1.Field1 = it1.Index
	}
	for it := dword_5d4594_2523756; it != nil; it = it.WpNext {
		if int32(it.PointsCnt) != 0 {
			for i := 0; i < int(it.PointsCnt); i++ {
				pt := &it.Points[i]
				pt.Waypoint = sub_579C60(it.Field348[i])
				if pt.Waypoint == nil {
					return 0
				}
			}
		}
	}
	return 1
}
func sub_579D20() int32 {
	v0 := nox_xxx_waypoint_5798C0()
	for it := dword_5d4594_2523756; it != nil; it = it.WpNext {
		it.Field1 = it.Index
		it.Index = v0
		v0++
	}
	for it := dword_5d4594_2523756; it != nil; it = it.WpNext {
		j := 0
		for i := 0; i < int(it.PointsCnt); i++ {
			v5 := &it.Points[j]
			v5.Waypoint = sub_579C60(it.Field348[i])
			if v5.Waypoint != nil {
				j++
			}
		}
		it.PointsCnt = uint8(j)
	}
	return 1
}
func sub_579E90(wp *server.Waypoint) {
	wp.Flags |= 0x1000000
	wp.WpNext = dword_5d4594_2523756
	if dword_5d4594_2523756 != nil {
		dword_5d4594_2523756.WpPrev = wp
	}
	dword_5d4594_2523756 = wp
	if noxflags.HasGame(1) {
		nox_xxx_waypointMapRegister_5179B0(wp)
	}
}

func nox_xxx_waypoint_579F00(out *types.Pointf, obj *server.Object) int32 {
	var found *server.Object
	if noxflags.HasGame(32) && obj != nil {
		for it := nox_server_getFirstObject_4DA790(); it != nil; it = nox_server_getNextObject_4DA7A0(it) {
			if (it.ObjClass&0x10000000) != 0 && nox_xxx_servCompareTeams_419150(obj.TeamPtr(), it.TeamPtr()) == 0 {
				found = it
				break
			}
		}
	}
	dword_5d4594_2523760 = 0
	for wp := nox_xxx_waypointGetList_579860(); wp != nil; wp = nox_xxx_waypointNext_579870(wp) {
		if sub_579EE0(wp, 0x80) != 0 && wp.Flags&1 != 0 {
			dword_5d4594_2523760++
		}
	}
	if dword_5d4594_2523760 == 0 {
		return 0
	}
	cnt := nox_common_randomInt_415FA0(0, int32(dword_5d4594_2523760-1))
	for wp := nox_xxx_waypointGetList_579860(); wp != nil; wp = nox_xxx_waypointNext_579870(wp) {
		if sub_579EE0(wp, 0x80) == 0 {
			continue
		}
		if (wp.Flags & 1) == 0 {
			continue
		}
		if noxflags.HasGame(32) && found != nil && obj != nil {
			v7 := (*types.Pointf)(found.UpdateData)
			var v12 float4
			v12.field_0 = v7.X
			v12.field_4 = v7.Y
			v12.field_8 = wp.PosVec.X
			v12.field_C = wp.PosVec.Y
			if nox_xxx_mapTraceRay_535250(&v12, nil, nil, 9) == 1 {
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
