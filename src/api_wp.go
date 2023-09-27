package opennox

import (
	"net/http"
)

func init() {
	http.HandleFunc("/debug/nox/waypoints", func(w http.ResponseWriter, r *http.Request) {
		writeJSONResp(w, noxServer.WPs.All())
	})
}
