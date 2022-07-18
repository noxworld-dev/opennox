package opennox

import (
	"encoding/json"
	"net/http"

	"github.com/noxworld-dev/opennox-lib/types"
)

type debugWaypoint struct {
	Ind int          `json:"ind"`
	ID  string       `json:"id,omitempty"`
	Pos types.Pointf `json:"pos"`
}

func (w *Waypoint) dump() *debugWaypoint {
	if w == nil {
		return nil
	}
	return &debugWaypoint{
		Ind: w.Ind(),
		ID:  w.ID(),
		Pos: w.Pos(),
	}
}

func (w *Waypoint) MarshalJSON() ([]byte, error) {
	return json.Marshal(w.dump())
}

func init() {
	http.HandleFunc("/debug/nox/waypoints", func(w http.ResponseWriter, r *http.Request) {
		writeJSONResp(w, noxServer.getWaypoints())
	})
}
