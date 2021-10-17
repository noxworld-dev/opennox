package nox

import (
	"encoding/json"
	"net/http"

	"nox/v1/common/player"
)

type debugPlayerInfo struct {
	Ind      int          `json:"ind"`
	NetCode  int          `json:"net_code"`
	Name     string       `json:"name"`
	OrigName string       `json:"orig_name"`
	Active   bool         `json:"active"`
	Class    player.Class `json:"class"`
	Unit     *debugObject `json:"unit"`
}

var _ json.Marshaler = &Player{}

func (p *Player) dump() *debugPlayerInfo {
	if p == nil {
		return nil
	}
	return &debugPlayerInfo{
		Ind:      p.Index(),
		NetCode:  p.NetCode(),
		Name:     p.Name(),
		OrigName: p.OrigName(),
		Active:   p.IsActive(),
		Class:    p.PlayerClass(),
		Unit:     p.UnitC().AsObject().dump(),
	}
}

func (p *Player) MarshalJSON() ([]byte, error) {
	return json.Marshal(p.dump())
}

func init() {
	http.HandleFunc("/debug/nox/players", func(w http.ResponseWriter, r *http.Request) {
		all := r.URL.Query().Get("all") != ""
		var arr []*Player
		if all {
			arr = getAllPlayerStructs()
		} else {
			arr = getPlayers()
		}
		writeJSONResp(w, arr)
	})
}
