package opennox

import (
	"github.com/noxworld-dev/noxscript/ns/v4"

	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) Teams() []ns.Team {
	arr := s.s.Teams.Teams()
	out := make([]ns.Team, 0, len(arr))
	for _, t := range arr {
		out = append(out, nsTeam{s.s, t})
	}
	return out
}

type nsTeam struct {
	s *Server
	t *server.Team
}

func (t nsTeam) Name() string {
	return t.t.Name()
}

func (t nsTeam) Players() []ns.Player {
	var out []ns.Player
	for _, p := range t.s.NoxScript().Players() {
		if p.HasTeam(t) {
			out = append(out, p)
		}
	}
	return out
}

func (t nsTeam) GetScore() int {
	return t.t.Lessons
}

func (t nsTeam) ChangeScore(score int) {
	t.s.teamChangeLessons(t.t, score+t.t.Lessons)
}
