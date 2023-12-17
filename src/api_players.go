package opennox

import (
	"encoding/json"
	"net/http"
)

var _ json.Marshaler = &Player{}

func (p *Player) MarshalJSON() ([]byte, error) {
	return p.S().MarshalJSON()
}

func init() {
	http.HandleFunc("/debug/nox/players", func(w http.ResponseWriter, r *http.Request) {
		all := r.URL.Query().Get("all") != ""
		var arr []*Player
		if all {
			arr = noxServer.GetAllPlayerStructs()
		} else {
			arr = noxServer.GetPlayers()
		}
		writeJSONResp(w, arr)
	})
}
