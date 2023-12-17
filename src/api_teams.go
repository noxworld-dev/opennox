package opennox

import (
	"encoding/json"
	"net/http"

	"github.com/noxworld-dev/opennox/v1/server"
)

var _ json.Marshaler = &server.Team{}

func init() {
	http.HandleFunc("/debug/nox/teams", func(w http.ResponseWriter, r *http.Request) {
		writeJSONResp(w, noxServer.Teams.Teams())
	})
}
