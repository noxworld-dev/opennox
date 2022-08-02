package opennox

/*
#include "common__system__team.h"
#include "GAME1_1.h"
#include "GAME2.h"
#include "client__gui__servopts__guiserv.h"
extern unsigned int nox_player_netCode_85319C;
*/
import "C"
import (
	"encoding/binary"
	"image/color"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox-lib/console"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

//export nox_server_teamByXxx_418AE0
func nox_server_teamByXxx_418AE0(a1 C.int) *nox_team_t {
	return noxServer.teamByXxx(int(a1)).C()
}

//export nox_xxx_clientGetTeamColor_418AB0
func nox_xxx_clientGetTeamColor_418AB0(a1 C.int) *nox_team_t {
	return noxServer.teamByYyy(byte(a1)).C()
}

//export nox_server_teamFirst_418B10
func nox_server_teamFirst_418B10() *nox_team_t {
	return noxServer.firstTeam().C()
}

//export nox_server_teamNext_418B60
func nox_server_teamNext_418B60(t *nox_team_t) *nox_team_t {
	return noxServer.nextTeam(asTeam(t)).C()
}

//export nox_server_teamTitle_418C20
func nox_server_teamTitle_418C20(a1 C.int) *C.wchar_t {
	return internWStr(noxServer.teamTitle(TeamColor(a1)))
}

//export nox_xxx_teamCreate_4186D0
func nox_xxx_teamCreate_4186D0(a1 C.char) *nox_team_t {
	return noxServer.teamCreate(byte(a1)).C()
}

//export nox_xxx_materialGetTeamColor_418D50
func nox_xxx_materialGetTeamColor_418D50(t *nox_team_t) C.uint {
	c := noxServer.getTeamColor(asTeam(t))
	return C.uint(noxcolor.ToRGBA5551Color(c).Color32())
}

//export nox_xxx_getTeamCounter_417DD0
func nox_xxx_getTeamCounter_417DD0() C.uchar {
	return C.uchar(noxServer.teamCount())
}

//export nox_server_teamsResetYyy_417D00
func nox_server_teamsResetYyy_417D00() C.int {
	return C.int(noxServer.teamsResetYyy())
}

type objectTeam struct {
	field0 uint32
	field1 byte
}

func nox_xxx_servObjectHasTeam_419130(p *objectTeam) bool {
	if p == nil {
		return false
	}
	return p.field1 != 0
}

func nox_xxx_servCompareTeams_419150(p1, p2 *objectTeam) bool {
	if p1 == nil || p2 == nil {
		return false
	}
	if p1.field1 == 0 || p2.field1 == 0 {
		return false
	}
	return p1.field1 == p2.field1
}

type TeamDef struct {
	Name  strman.ID
	Title string
	Color color.Color
}

type nox_team_t = C.nox_team_t

func asTeam(p *nox_team_t) *Team {
	if p == nil {
		return nil
	}
	return asTeamP(unsafe.Pointer(p))
}

func asTeamP(p unsafe.Pointer) *Team {
	if p == nil {
		return nil
	}
	return (*Team)(p)
}

type TeamColor byte

type Team nox_team_t

func (t *Team) C() *nox_team_t {
	return (*nox_team_t)(unsafe.Pointer(t))
}

func (t *Team) Name() string {
	return GoWString(&t.name[0])
}

func (t *Team) ColorInd() TeamColor {
	return TeamColor(t.def_ind)
}

func (t *Team) Ind57() byte {
	return byte(t.field_57)
}

func (t *Team) Ind() int {
	if t == nil {
		return 0
	}
	return int(t.ind)
}

func (t *Team) Ind60() int {
	if t == nil {
		return 0
	}
	return int(t.field_60)
}

func (t *Team) Active() bool {
	if t == nil {
		return false
	}
	return t.active != 0
}

type serverTeams struct {
	defs map[TeamColor]*TeamDef
	arr  []nox_team_t
}

func (s *Server) allocTeams() {
	s.teams.defs = map[TeamColor]*TeamDef{
		0: {Name: "advserv.wnd:None", Color: nox_color_white_2523948},
		1: {Name: "modifier.db:MaterialTeamRedDesc", Color: nox_color_red_2589776},
		2: {Name: "modifier.db:MaterialTeamBlueDesc", Color: nox_color_blue_2650684},
		3: {Name: "modifier.db:MaterialTeamGreenDesc", Color: nox_color_green_2614268},
		4: {Name: "modifier.db:MaterialTeamCyanDesc", Color: nox_color_cyan_2649820},
		5: {Name: "modifier.db:MaterialTeamYellowDesc", Color: nox_color_yellow_2589772},
		6: {Name: "modifier.db:MaterialTeamVioletDesc", Color: nox_color_violet_2598268},
		7: {Name: "modifier.db:MaterialTeamBlackDesc", Color: nox_color_black_2650656},
		8: {Name: "modifier.db:MaterialTeamWhiteDesc", Color: nox_color_white_2523948},
		9: {Name: "modifier.db:MaterialTeamOrangeDesc", Color: nox_color_orange_2614256},
	}
	s.teamsReloadTitles()
	const teamsMax = 17
	ptr, _ := alloc.Calloc(teamsMax, unsafe.Sizeof(nox_team_t{}))
	s.teams.arr = unsafe.Slice((*nox_team_t)(ptr), teamsMax)
}

func (s *Server) teamsReloadTitles() {
	for _, t := range s.teams.defs {
		t.Title = s.Strings().GetStringInFile(t.Name, "C:\\NoxPost\\src\\common\\System\\team.c")
	}
}

func (s *Server) firstTeam() *Team { // nox_server_teamFirst_418B10
	for i := 1; i < len(s.teams.arr); i++ {
		t := asTeam(&s.teams.arr[i])
		if t.Active() {
			return t
		}
	}
	return nil
}

func (s *Server) nextTeam(t *Team) *Team { // nox_server_teamNext_418B60
	if t == nil {
		return nil
	}
	for i := t.Ind() + 1; i < len(s.teams.arr); i++ {
		t2 := asTeam(&s.teams.arr[i])
		if t2.Active() {
			return t2
		}
	}
	return nil
}

func (s *Server) Teams() []*Team {
	var out []*Team
	for it := s.firstTeam(); it != nil; it = s.nextTeam(it) {
		out = append(out, it)
	}
	return out
}

func (s *Server) teamInactive() int {
	for i := 1; i < len(s.teams.arr); i++ {
		t := asTeam(&s.teams.arr[i])
		if !t.Active() {
			return i
		}
	}
	return 0
}

func (s *Server) teamByXxx(a1 int) *Team { // nox_server_teamByXxx_418AE0
	for it := s.firstTeam(); it != nil; it = s.nextTeam(it) {
		if it.Ind60() == a1 {
			return it
		}
	}
	return nil
}

func (s *Server) teamsReset() {
	for i := 0; i < len(s.teams.arr); i++ {
		s.teams.arr[i] = nox_team_t{}
	}
	for i := 0; i < len(s.teams.arr)-1; i++ { // TODO: why -1 ?
		t := &s.teams.arr[i]
		t.field_57 = 0
		t.field_72 = nil
		t.field_76 = 0
		t.field_60 = 0
	}
	s.teamsReloadTitles()
	nox_xxx_SetGameplayFlag_417D50(2)
	nox_xxx_UnsetGameplayFlags_417D70(1)
	nox_xxx_UnsetGameplayFlags_417D70(4)
}

func (s *Server) teamByYyy(a1 byte) *Team { // nox_xxx_clientGetTeamColor_418AB0
	for t := s.firstTeam(); t != nil; t = s.nextTeam(t) {
		if t.Ind57() == a1 {
			return t
		}
	}
	return nil
}

func (s *Server) teamCount() int {
	return int(memmap.Uint8(0x5D4594, 526280))
}

func (s *Server) nox_xxx_createCoopTeam_417E10() {
	noxflags.SetGame(noxflags.GameModeSolo10)
	t := s.teamByYyy(1)
	if t == nil {
		t = s.teamCreate(1)
	}
	if v1 := C.nox_xxx_objGetTeamByNetCode_418C80(C.int(C.nox_player_netCode_85319C)); v1 != nil {
		C.nox_xxx_createAtImpl_4191D0(t.field_57, unsafe.Pointer(v1), 0, C.int(C.nox_player_netCode_85319C), 0)
	}
	if t != nil {
		text := s.Strings().GetStringInFile("COOP", "C:\\NoxPost\\src\\common\\System\\team.c")
		t.setNameAnd68(text, 0)
	}
	nox_xxx_UnsetGameplayFlags_417D70(1)
}

func (t *Team) setNameAnd68(name string, a3 int) { // sub_418800
	WStrCopy(&t.name[0], 20, name)
	t.name[20] = 0
	t.field_68 = C.uint(a3)
}

func (s *Server) teamCreate(ind byte) *Team {
	if int(memmap.Uint8(0x5D4594, 526280)) >= len(s.teams.arr)-1 {
		text := s.Strings().GetStringInFile("teamexceed", "C:\\NoxPost\\src\\common\\System\\team.c")
		s.Printf(console.ColorRed, text)
		return nil
	}
	ti := s.teamInactive()
	t := asTeam(&s.teams.arr[ti])
	t.name[0] = 0
	t.field_44 = 0
	t.field_48 = 0
	t.lessons = 0
	t.def_ind = C.uchar(ti)
	t.ind = C.uchar(ti)
	t.field_60 = 0
	t.active = 1
	t.field_68 = 0
	ci := ind
	if ind == 0 {
		ci = s.teamFindFreeInd()
	}
	t.field_57 = C.uchar(ci)
	*memmap.PtrUint8(0x5D4594, 526280)++
	C.sub_459CD0() // TODO: GUI callback
	if !noxflags.HasGame(noxflags.GameModeSolo10) {
		text := s.Strings().GetStringInFile("teamcreate", "C:\\NoxPost\\src\\common\\System\\team.c")
		s.Printf(console.ColorRed, text)
	}
	return t
}

func (s *Server) teamFindFreeInd() byte {
	for i := 1; i < len(s.teams.arr); i++ {
		ok := true
		for it := s.firstTeam(); it != nil; it = s.nextTeam(it) {
			if it.Ind57() == byte(i) {
				ok = false
				break
			}
		}
		if ok {
			return byte(i)
		}
	}
	return 0
}

func (s *Server) teamTitle(c TeamColor) string {
	if t, ok := s.teams.defs[c]; ok {
		return t.Title
	}
	return s.Strings().GetStringInFile("NoTeam", "C:\\NoxPost\\src\\common\\System\\team.c")
}

func (s *Server) getTeamColor(t2 *Team) color.Color {
	if t2 == nil {
		return nil
	}
	if t, ok := s.teams.defs[t2.ColorInd()]; ok {
		return t.Color
	}
	return nil
}

func (s *Server) teamsResetYyy() int {
	for i := 1; i < len(s.teams.arr); i++ {
		t := &s.teams.arr[i]
		t.lessons = 0
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		return 0
	}
	return s.sendTeamPacket(0x09)
}

//export nox_server_teamsZzz_419030
func nox_server_teamsZzz_419030(a1 C.int) C.int {
	return C.int(noxServer.teamsZzz(int(a1)))
}

func (s *Server) sendTeamPacket(op byte) int {
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_TEAM_MSG)
	buf[1] = op
	return s.nox_xxx_netSendPacket1_4E5390(159, buf[:], 0, 1)
}

func (s *Server) teamChangeLessons(tm *Team, val int) { // nox_xxx_netChangeTeamID_419090
	if tm == nil {
		return
	}
	tm.lessons = C.int(val)
	if !noxflags.HasGame(noxflags.GameHost) {
		return
	}
	var buf [10]byte
	buf[0] = byte(noxnet.MSG_TEAM_MSG)
	buf[1] = 0x8
	binary.LittleEndian.PutUint32(buf[2:], uint32(tm.field_57))
	binary.LittleEndian.PutUint32(buf[6:], uint32(val))
	s.nox_xxx_netSendPacket1_4E5390(159, buf[:10], 0, 1)
}

func (s *Server) teamsZzz(a1 int) int {
	nox_xxx_UnsetGameplayFlags_417D70(4)
	for i := 1; i < len(s.teams.arr); i++ {
		t := asTeam(&s.teams.arr[i])
		if t.Active() {
			C.sub_418F20(t.C(), 0)
		}
	}
	if a1 == 0 {
		return 0
	}
	C.sub_456FA0() // TODO: GUI callback?
	return s.sendTeamPacket(0x07)
}
