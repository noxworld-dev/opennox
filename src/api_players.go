package opennox

import (
	"encoding/json"
	"net/http"

	"github.com/noxworld-dev/opennox/v1/server"
)

var _ json.Marshaler = &server.Player{}

func init() {
	http.HandleFunc("/debug/nox/players", func(w http.ResponseWriter, r *http.Request) {
		all := r.URL.Query().Get("all") != ""
		var arr []*Player
		if all {
			arr = noxServer.Players.ListSlots()
		} else {
			arr = noxServer.Players.List()
		}
		writeJSONResp(w, arr)
	})
}
