package server

import (
	"encoding/json"
	"image/color"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/strman"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type TeamDef struct {
	Name  strman.ID
	Title string
	Color color.Color
}

type serverTeams struct {
	sm        *strman.StringManager
	pr        console.Printer
	defs      map[TeamColor]*TeamDef
	Arr       []Team
	ActiveCnt int

	onCreateOrRemove []func()
}

const (
	TeamNone   = TeamColor(0)
	TeamRed    = TeamColor(1)
	TeamBlue   = TeamColor(2)
	TeamGreen  = TeamColor(3)
	TeamCyan   = TeamColor(4)
	TeamYellow = TeamColor(5)
	TeamViolet = TeamColor(6)
	TeamBlack  = TeamColor(7)
	TeamWhite  = TeamColor(8)
	TeamOrange = TeamColor(9)
)

func (s *serverTeams) init(sm *strman.StringManager, pr console.Printer) {
	s.sm = sm
	s.pr = pr
	s.defs = map[TeamColor]*TeamDef{
		TeamNone:   {Name: "advserv.wnd:None", Color: nox_color_white_2523948},
		TeamRed:    {Name: "modifier.db:MaterialTeamRedDesc", Color: nox_color_red_2589776},
		TeamBlue:   {Name: "modifier.db:MaterialTeamBlueDesc", Color: nox_color_blue_2650684},
		TeamGreen:  {Name: "modifier.db:MaterialTeamGreenDesc", Color: nox_color_green_2614268},
		TeamCyan:   {Name: "modifier.db:MaterialTeamCyanDesc", Color: nox_color_cyan_2649820},
		TeamYellow: {Name: "modifier.db:MaterialTeamYellowDesc", Color: nox_color_yellow_2589772},
		TeamViolet: {Name: "modifier.db:MaterialTeamVioletDesc", Color: nox_color_violet_2598268},
		TeamBlack:  {Name: "modifier.db:MaterialTeamBlackDesc", Color: nox_color_black_2650656},
		TeamWhite:  {Name: "modifier.db:MaterialTeamWhiteDesc", Color: nox_color_white_2523948},
		TeamOrange: {Name: "modifier.db:MaterialTeamOrangeDesc", Color: nox_color_orange_2614256},
	}
	s.teamsReloadTitles()
	const teamsMax = 17
	s.Arr, _ = alloc.Make([]Team{}, teamsMax)
}

func (s *serverTeams) teamsReloadTitles() {
	for _, t := range s.defs {
		t.Title = s.sm.GetStringInFile(t.Name, "team.c")
	}
}

func (s *serverTeams) OnCreateOrRemove(fnc func()) {
	s.onCreateOrRemove = append(s.onCreateOrRemove, fnc)
}

func (s *serverTeams) HookCreateOrRemove() {
	for _, fnc := range s.onCreateOrRemove {
		fnc()
	}
}

func (s *serverTeams) First() *Team { // nox_server_teamFirst_418B10
	for i := 1; i < len(s.Arr); i++ {
		t := &s.Arr[i]
		if t.Active() {
			return t
		}
	}
	return nil
}

func (s *serverTeams) Next(t *Team) *Team { // nox_server_teamNext_418B60
	if t == nil {
		return nil
	}
	for i := int(t.ind) + 1; i < len(s.Arr); i++ {
		t2 := &s.Arr[i]
		if t2.Active() {
			return t2
		}
	}
	return nil
}

func (s *serverTeams) Teams() []*Team {
	var out []*Team
	for it := s.First(); it != nil; it = s.Next(it) {
		out = append(out, it)
	}
	return out
}

func (s *serverTeams) ByXxx(a1 int) *Team { // nox_server_teamByXxx_418AE0
	for it := s.First(); it != nil; it = s.Next(it) {
		if it.Ind60() == a1 {
			return it
		}
	}
	return nil
}

func (s *serverTeams) ByID(id TeamID) *Team { // nox_xxx_getTeamByID_418AB0
	for t := s.First(); t != nil; t = s.Next(t) {
		if t.ID() == id {
			return t
		}
	}
	return nil
}

func (s *serverTeams) Reset() {
	for i := 0; i < len(s.Arr); i++ {
		s.Arr[i] = Team{}
	}
	for i := 0; i < len(s.Arr)-1; i++ { // TODO: why -1 ?
		t := &s.Arr[i]
		t.id = 0
		t.Field_72 = nil
		t.field_76 = 0
		t.field_60 = 0
	}
	s.teamsReloadTitles()
}

func (s *serverTeams) GetTeamColor(t *Team) color.Color {
	if t == nil {
		return nil
	}
	if d, ok := s.defs[t.ColorInd]; ok {
		return d.Color
	}
	return nil
}

func (s *serverTeams) TeamTitle(c TeamColor) string {
	if t, ok := s.defs[c]; ok {
		return t.Title
	}
	return s.sm.GetStringInFile("NoTeam", "team.c")
}

func (s *serverTeams) Count() int {
	return s.ActiveCnt
}

func (s *serverTeams) Max() int {
	return len(s.Arr) - 1
}

func (s *serverTeams) getInactive() (*Team, int) {
	for i := 1; i < len(s.Arr); i++ {
		t := &s.Arr[i]
		if !t.Active() {
			return t, i
		}
	}
	return nil, -1
}

func (s *serverTeams) getFreeID() TeamID {
	for i := 1; i < len(s.Arr); i++ {
		ok := true
		for it := s.First(); it != nil; it = s.Next(it) {
			if it.ID() == TeamID(i) {
				ok = false
				break
			}
		}
		if ok {
			return TeamID(i)
		}
	}
	return 0
}

func (s *serverTeams) create(id TeamID) *Team {
	t, ind := s.getInactive()
	t.name[0] = 0
	t.Lessons = 0
	t.ColorInd = TeamColor(ind)
	t.ind = byte(ind)
	t.active = 1
	t.field_44 = 0
	t.field_48 = 0
	t.field_60 = 0
	t.field_68 = 0
	if id == 0 {
		id = s.getFreeID()
	}
	t.id = id
	return t
}

func (s *serverTeams) GetOrCreate(id TeamID) *Team {
	if t := s.ByID(id); t != nil {
		return t
	}
	return s.Create(id)
}

func (s *serverTeams) Create(id TeamID) *Team {
	if s.Count() >= s.Max() {
		text := s.sm.GetStringInFile("teamexceed", "team.c")
		s.pr.Printf(console.ColorRed, text)
		return nil
	}
	t := s.create(id)
	s.ActiveCnt++
	s.HookCreateOrRemove()
	if !noxflags.HasGame(noxflags.GameModeCoopTeam) {
		text := s.sm.GetStringInFile("teamcreate", "team.c")
		s.pr.Printf(console.ColorRed, text)
	}
	return t
}

func (s *serverTeams) ResetYyy() {
	for i := 1; i < len(s.Arr); i++ {
		t := &s.Arr[i]
		t.Lessons = 0
	}
}

func (s *Server) TeamsReset() {
	s.Teams.Reset()
	noxflags.SetGamePlay(2)
	noxflags.UnsetGamePlay(1)
	noxflags.UnsetGamePlay(4)
}

func (s *Server) TeamChangeLessons(tm *Team, val int) { // nox_xxx_netChangeTeamID_419090
	if tm == nil {
		return
	}
	tm.Lessons = val
	if !noxflags.HasGame(noxflags.GameHost) {
		return
	}
	s.NetTeamChangeLessons(tm, val)
}

func (s *Server) TeamsResetYyy() int {
	s.Teams.ResetYyy()
	if !noxflags.HasGame(noxflags.GameHost) {
		return 0
	}
	return s.SendTeamPacket(0x09)
}

type ObjectTeam struct {
	Field0 uint32
	ID     TeamID
	_      [3]byte
}

func (t *ObjectTeam) Has() bool { // nox_xxx_servObjectHasTeam_419130
	return t != nil && t.ID != 0
}

func (t *ObjectTeam) C() unsafe.Pointer {
	return unsafe.Pointer(t)
}

func (t *ObjectTeam) SameAs(t2 *ObjectTeam) bool { // nox_xxx_servCompareTeams_419150
	if t == nil || t2 == nil {
		return false
	}
	if t.ID == 0 || t2.ID == 0 {
		return false
	}
	return t.ID == t2.ID
}

type TeamID byte

type TeamColor byte

type Team struct {
	name     [22]uint16     // 0, 0
	field_44 uint32         // 11, 44
	field_48 uint32         // 12, 48
	Lessons  int            // 13, 52
	ColorInd TeamColor      // 14, 56
	id       TeamID         // 14, 57 TODO: team def code?
	ind      byte           // 14, 58
	_        byte           // 14, 59
	field_60 uint32         // 15, 60 TODO: id? net code?
	active   uint32         // 16, 64
	field_68 uint32         // 17, 68
	Field_72 unsafe.Pointer // 18, 72 TODO: team flag? team spawn?
	field_76 uint32         // 19, 76
}

func (t *Team) Reset() {
	t.name[0] = 0
	t.field_44 = 0
	t.field_48 = 0
	t.active = 0
	t.field_60 = 0
	t.field_68 = 0
	t.Field_72 = nil
	t.field_76 = 0
	t.id = 0
}

func (t *Team) C() unsafe.Pointer {
	return unsafe.Pointer(t)
}

func (t *Team) Name() string {
	return alloc.GoString16S(t.name[:])
}

func (t *Team) ID() TeamID {
	return t.id
}

// Ind returns a server team array index.
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

func (t *Team) SetNameAnd68(name string, a3 int) { // sub_418800
	alloc.StrCopy16(t.name[:20], name)
	t.name[20] = 0
	t.field_68 = uint32(a3)
}

type debugTeamInfo struct {
	Ind   int       `json:"ind"`
	Color TeamColor `json:"color"`
	ID    TeamID    `json:"id"`
	Ind60 int       `json:"ind_60"`
	Name  string    `json:"name"`
}

func (t *Team) dump() *debugTeamInfo {
	if t == nil {
		return nil
	}
	return &debugTeamInfo{
		Ind:   t.Ind(),
		Color: t.ColorInd,
		ID:    t.ID(),
		Ind60: t.Ind60(),
		Name:  t.Name(),
	}
}

func (t *Team) MarshalJSON() ([]byte, error) {
	return json.Marshal(t.dump())
}
