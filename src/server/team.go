package server

import (
	"image/color"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type TeamDef struct {
	Name  strman.ID
	Title string
	Color color.Color
}

type serverTeams struct {
	sm   *strman.StringManager
	defs map[TeamColor]*TeamDef
	Arr  []Team
}

func (s *serverTeams) init(sm *strman.StringManager) {
	s.sm = sm
	s.defs = map[TeamColor]*TeamDef{
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
	s.Arr, _ = alloc.Make([]Team{}, teamsMax)
}

func (s *serverTeams) teamsReloadTitles() {
	for _, t := range s.defs {
		t.Title = s.sm.GetStringInFile(t.Name, "team.c")
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
	for i := t.Ind() + 1; i < len(s.Arr); i++ {
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

func (s *serverTeams) Inactive() int {
	for i := 1; i < len(s.Arr); i++ {
		t := &s.Arr[i]
		if !t.Active() {
			return i
		}
	}
	return 0
}

func (s *serverTeams) ByXxx(a1 int) *Team { // nox_server_teamByXxx_418AE0
	for it := s.First(); it != nil; it = s.Next(it) {
		if it.Ind60() == a1 {
			return it
		}
	}
	return nil
}

func (s *serverTeams) ByYyy(a1 byte) *Team { // nox_xxx_clientGetTeamColor_418AB0
	for t := s.First(); t != nil; t = s.Next(t) {
		if t.Ind57() == a1 {
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
		t.Field_57 = 0
		t.Field_72 = nil
		t.field_76 = 0
		t.field_60 = 0
	}
	s.teamsReloadTitles()
}

func (s *serverTeams) teamFindFreeInd() byte {
	for i := 1; i < len(s.Arr); i++ {
		ok := true
		for it := s.First(); it != nil; it = s.Next(it) {
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

func (s *serverTeams) GetTeamColor(t2 *Team) color.Color {
	if t2 == nil {
		return nil
	}
	if t, ok := s.defs[t2.ColorInd()]; ok {
		return t.Color
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
	return len(s.Arr)
}

func (s *serverTeams) New(ind byte) *Team {
	ti := s.Inactive()
	t := &s.Arr[ti]
	t.name[0] = 0
	t.field_44 = 0
	t.field_48 = 0
	t.Lessons = 0
	t.Def_ind = byte(ti)
	t.ind = byte(ti)
	t.field_60 = 0
	t.active = 1
	t.field_68 = 0
	ci := ind
	if ind == 0 {
		ci = s.teamFindFreeInd()
	}
	t.Field_57 = ci
	return t
}

func (s *serverTeams) ResetYyy() {
	for i := 1; i < len(s.Arr); i++ {
		t := &s.Arr[i]
		t.Lessons = 0
	}
}

type ObjectTeam struct {
	Field0 uint32
	Field1 byte
}

func Nox_xxx_servObjectHasTeam_419130(p *ObjectTeam) bool {
	if p == nil {
		return false
	}
	return p.Field1 != 0
}

func Nox_xxx_servCompareTeams_419150(p1, p2 *ObjectTeam) bool {
	if p1 == nil || p2 == nil {
		return false
	}
	if p1.Field1 == 0 || p2.Field1 == 0 {
		return false
	}
	return p1.Field1 == p2.Field1
}

type TeamColor byte

type Team struct {
	name     [21]uint16     // 0, 0
	field_42 uint16         // 10, 42
	field_44 uint32         // 11, 44
	field_48 uint32         // 12, 48
	Lessons  int            // 13, 52
	Def_ind  uint8          // 14, 56
	Field_57 byte           // 14, 57 TODO: team def code?
	ind      uint8          // 14, 58
	field_59 uint8          // 14, 59
	field_60 uint32         // 15, 60 TODO: id? net code?
	active   uint32         // 16, 64
	field_68 uint32         // 17, 68
	Field_72 unsafe.Pointer // 18, 72 TODO: team flag? team spawn?
	field_76 uint32         // 19, 76
}

func (t *Team) C() unsafe.Pointer {
	return unsafe.Pointer(t)
}

func (t *Team) Name() string {
	return alloc.GoString16S(t.name[:])
}

func (t *Team) ColorInd() TeamColor {
	return TeamColor(t.Def_ind)
}

func (t *Team) Ind57() byte {
	return t.Field_57
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

func (t *Team) SetNameAnd68(name string, a3 int) { // sub_418800
	alloc.StrCopy16(t.name[:20], name)
	t.name[20] = 0
	t.field_68 = uint32(a3)
}
