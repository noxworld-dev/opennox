package opennox

import (
	"net/http"

	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	http.HandleFunc("/debug/nox/spells", func(w http.ResponseWriter, r *http.Request) {
		var out []*server.DebugSpellDef
		spells := noxServer.Spells.Defs()
		ids := server.SpellIDs()
		for i, s := range spells {
			d := s.Dump()
			d.ID = ids[i]
			out = append(out, d)
		}
		writeJSONResp(w, out)
	})
}
