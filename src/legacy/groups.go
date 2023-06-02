package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

// nox_server_getFirstMapGroup_57C080
func nox_server_getFirstMapGroup_57C080() unsafe.Pointer {
	return GetServer().S().MapGroups.GetFirstMapGroup().C()
}

// nox_server_scriptGetGroup_57C0A0
func nox_server_scriptGetGroup_57C0A0(a1 int32) unsafe.Pointer {
	return GetServer().S().MapGroups.GroupByInd(int(a1)).C()
}

// sub_504600
func sub_504600(name *byte, ind uint32, typ uint8) {
	GetServer().S().MapGroups.Sub504600(GoString(name), ind, typ)
}

// sub_57C130
func sub_57C130(d *uint32, ind int32) int32 {
	var arg []uint32
	if d != nil {
		arg = unsafe.Slice(d, 2)
	}
	return GetServer().S().MapGroups.Sub57C130(arg, uint32(ind))
}

// sub_5046A0
func sub_5046A0(d *uint32, ind uint32) int {
	var arg []uint32
	if d != nil {
		arg = unsafe.Slice(d, 2)
	}
	return GetServer().S().MapGroups.Sub5046A0(arg, ind)
}

// sub_4CFFE0
func sub_4CFFE0(sid int32) *server.Object {
	return asObjectC(GetServer().PendingObjByScriptID4CFFE0(int(sid)))
}

// sub_579C60
func sub_579C60(id uint32) *nox_waypoint_t {
	return asWaypointC(GetServer().PendingWaypointByInd579C60(id))
}

// nox_server_mapLoadAddGroup_57C0C0
func nox_server_mapLoadAddGroup_57C0C0(name *byte, ind uint32, typ byte) int32 {
	return GetServer().S().MapGroups.MapLoadAddGroup57C0C0(GoString(name), ind, typ)
}

// sub_504720
func sub_504720(a1, a2 uint32) int32 {
	return GetServer().Sub504720(a1, a2)
}

func Nox_server_scriptGetGroupId_57C2D0(g unsafe.Pointer) server.MapGroupKind {
	return server.MapGroupKind(nox_server_scriptGetGroupId_57C2D0((**int32)(g)))
}

func Get_dword_5d4594_2523756() *server.Waypoint {
	return asWaypointS((*nox_waypoint_t)(dword_5d4594_2523756))
}

func Get_dword_5d4594_3835312() int {
	return int(dword_5d4594_3835312)
}
