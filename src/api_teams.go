package opennox

import (
	"encoding/json"
	"net/http"
)

type debugTeamInfo struct {
	Ind    int    `json:"ind"`
	DefInd byte   `json:"def"`
	Ind57  byte   `json:"ind_57"`
	Ind60  int    `json:"ind_60"`
	Name   string `json:"name"`
}

var _ json.Marshaler = &Team{}

func (t *Team) dump() *debugTeamInfo {
	if t == nil {
		return nil
	}
	return &debugTeamInfo{
		Ind:    t.Ind(),
		DefInd: t.DefInd(),
		Ind57:  t.Ind57(),
		Ind60:  t.Ind60(),
		Name:   t.Name(),
	}
}

func (t *Team) MarshalJSON() ([]byte, error) {
	return json.Marshal(t.dump())
}

func init() {
	http.HandleFunc("/debug/nox/teams", func(w http.ResponseWriter, r *http.Request) {
		writeJSONResp(w, noxServer.Teams())
	})
}
