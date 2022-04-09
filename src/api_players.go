package opennox

import (
	"encoding/json"
	"net/http"

	"github.com/noxworld-dev/opennox-lib/player"
)

type debugPlayerInfo struct {
	Ind      int            `json:"ind"`
	NetCode  int            `json:"net_code"`
	Name     string         `json:"name"`
	OrigName string         `json:"orig_name"`
	Serial   string         `json:"serial"`
	Active   bool           `json:"active"`
	Class    player.Class   `json:"class"`
	Team     *debugTeamInfo `json:"team"`
	Unit     *debugObject   `json:"unit"`
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
		Serial:   p.Serial(),
		Active:   p.IsActive(),
		Class:    p.PlayerClass(),
		Unit:     p.UnitC().AsObject().dump(),
		Team:     p.UnitC().Team().dump(),
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
			arr = noxServer.getAllPlayerStructs()
		} else {
			arr = noxServer.getPlayers()
		}
		writeJSONResp(w, arr)
	})
}
