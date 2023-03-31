package legacy

/*
#include "common__system__team.h"
#include "GAME1_1.h"
#include "GAME2.h"
#include "client__gui__servopts__guiserv.h"
extern unsigned int nox_player_netCode_85319C;
*/
import "C"
import (
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/server"
)

type nox_team_t = C.nox_team_t

func asTeam(p *nox_team_t) *server.Team {
	if p == nil {
		return nil
	}
	return asTeamP(unsafe.Pointer(p))
}

func asTeamP(p unsafe.Pointer) *server.Team {
	if p == nil {
		return nil
	}
	return (*server.Team)(p)
}

//export nox_server_teamByXxx_418AE0
func nox_server_teamByXxx_418AE0(a1 int) *nox_team_t {
	return (*nox_team_t)(GetServer().S().Teams.ByXxx(a1).C())
}

//export nox_xxx_clientGetTeamColor_418AB0
func nox_xxx_clientGetTeamColor_418AB0(a1 int) *nox_team_t {
	return (*nox_team_t)(GetServer().S().Teams.ByYyy(byte(a1)).C())
}

//export nox_server_teamFirst_418B10
func nox_server_teamFirst_418B10() *nox_team_t {
	return (*nox_team_t)(GetServer().S().Teams.First().C())
}

//export nox_server_teamNext_418B60
func nox_server_teamNext_418B60(t *nox_team_t) *nox_team_t {
	return (*nox_team_t)(GetServer().S().Teams.Next(asTeam(t)).C())
}

//export nox_server_teamTitle_418C20
func nox_server_teamTitle_418C20(a1 int) *wchar2_t {
	return internWStr(GetServer().S().Teams.TeamTitle(server.TeamColor(a1)))
}

//export nox_xxx_teamCreate_4186D0
func nox_xxx_teamCreate_4186D0(a1 C.char) *nox_team_t {
	return (*nox_team_t)(GetServer().TeamCreate(byte(a1)).C())
}

//export nox_xxx_materialGetTeamColor_418D50
func nox_xxx_materialGetTeamColor_418D50(t *nox_team_t) C.uint {
	c := GetServer().S().Teams.GetTeamColor(asTeam(t))
	return C.uint(noxcolor.ToRGBA5551Color(c).Color32())
}

//export nox_xxx_getTeamCounter_417DD0
func nox_xxx_getTeamCounter_417DD0() C.uchar {
	return C.uchar(GetServer().TeamCount())
}

//export nox_server_teamsResetYyy_417D00
func nox_server_teamsResetYyy_417D00() int {
	return GetServer().TeamsResetYyy()
}

//export nox_server_teamsZzz_419030
func nox_server_teamsZzz_419030(a1 int) int {
	return GetServer().TeamsZzz(a1)
}
func Sub_459CD0() {
	C.sub_459CD0()
}
func Sub_456FA0() {
	C.sub_456FA0()
}
func Sub_418F20(a1 unsafe.Pointer, a2 int) {
	C.sub_418F20((*nox_team_t)(a1), C.int(a2))
}
