package legacy

import (
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_server_scriptGetGroupId_57C2D0(a1 *server.MapGroup) int32 {
	if a1.GroupType() == server.MapGroupObjects {
		return int32(a1.GroupType())
	}
	it := a1
	for it.GroupType() != server.MapGroupWaypoints && it.GroupType() != server.MapGroupWalls {
		if it.GroupType() != server.MapGroupGroups || it == nil {
			str := nox_strman_loadString_40F1D0(internCStr("Undefined"), nil, internCStr("C:\\NoxPost\\src\\Common\\System\\Group.c"), 358)
			nox_gui_console_PrintOrError_450C30(NOX_CONSOLE_RED, str)
			return 0
		}
		it = nox_server_scriptGetGroup_57C0A0(int32(it.List.Raw0))
		if it.GroupType() == server.MapGroupObjects {
			return int32(it.GroupType())
		}
	}
	return int32(it.GroupType())
}
