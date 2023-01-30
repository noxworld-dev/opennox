package opennox

import (
	"net/http"

	"github.com/noxworld-dev/opennox/v1/server"
)

type debugTeamInfo struct {
	Ind   int              `json:"ind"`
	Color server.TeamColor `json:"color"`
	Ind57 byte             `json:"ind_57"`
	Ind60 int              `json:"ind_60"`
	Name  string           `json:"name"`
}

func dumpTeam(t *server.Team) *debugTeamInfo {
	if t == nil {
		return nil
	}
	return &debugTeamInfo{
		Ind:   t.Ind(),
		Color: t.ColorInd(),
		Ind57: t.Ind57(),
		Ind60: t.Ind60(),
		Name:  t.Name(),
	}
}

func dumpTeams(arr []*server.Team) []*debugTeamInfo {
	if len(arr) == 0 {
		return nil
	}
	out := make([]*debugTeamInfo, 0, len(arr))
	for _, v := range arr {
		out = append(out, dumpTeam(v))
	}
	return out
}

func init() {
	http.HandleFunc("/debug/nox/teams", func(w http.ResponseWriter, r *http.Request) {
		writeJSONResp(w, dumpTeams(noxServer.Teams.Teams()))
	})
}
