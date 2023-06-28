package legacy

import (
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/server"
)

func asTeamP(p unsafe.Pointer) *server.Team {
	if p == nil {
		return nil
	}
	return (*server.Team)(p)
}

// nox_server_teamByXxx_418AE0
func nox_server_teamByXxx_418AE0(a1 int32) *server.Team {
	return GetServer().S().Teams.ByXxx(int(a1))
}

// nox_xxx_getTeamByID_418AB0
func nox_xxx_getTeamByID_418AB0(a1 int32) *server.Team {
	return GetServer().S().Teams.ByID(server.TeamID(int(a1)))
}

// nox_server_teamFirst_418B10
func nox_server_teamFirst_418B10() *server.Team {
	return GetServer().S().Teams.First()
}

func nox_server_teamNext_418B60(t *server.Team) *server.Team {
	return GetServer().S().Teams.Next(t)
}

// nox_server_teamTitle_418C20
func nox_server_teamTitle_418C20(a1 int32) *wchar2_t {
	return internWStr(GetServer().S().Teams.TeamTitle(server.TeamColor(a1)))
}

// nox_xxx_teamCreate_4186D0
func nox_xxx_teamCreate_4186D0(a1 int8) *server.Team {
	return GetServer().S().Teams.Create(server.TeamID(a1))
}

// nox_xxx_materialGetTeamColor_418D50
func nox_xxx_materialGetTeamColor_418D50(t *server.Team) uint32 {
	c := GetServer().S().Teams.GetTeamColor(t)
	return noxcolor.ToRGBA5551Color(c).Color32()
}

// nox_xxx_getTeamCounter_417DD0
func nox_xxx_getTeamCounter_417DD0() byte {
	return byte(GetServer().S().Teams.Count())
}

// nox_server_teamsResetYyy_417D00
func nox_server_teamsResetYyy_417D00() int {
	return GetServer().TeamsResetYyy()
}

// nox_server_teamsZzz_419030
func nox_server_teamsZzz_419030(a1 int) int {
	return GetServer().TeamsRemoveActive(a1 != 0)
}

// sub_418F20
func sub_418F20(t *server.Team, a2 int) {
	GetServer().TeamRemove(t, a2 != 0)
}
func Sub_459CD0() {
	sub_459CD0()
}
func Sub_456FA0() {
	sub_456FA0()
}
func Sub_418E40(t *server.Team, p *server.ObjectTeam) {
	sub_418E40(t.C(), unsafe.Pointer(p))
}
func Sub_456EA0(name string) {
	sub_456EA0(internWStr(name))
}
