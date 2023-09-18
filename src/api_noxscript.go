package opennox

import (
	"net/http"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func init() {
	type debugNoxScript struct {
		Ind  int    `json:"ind"`
		Name string `json:"name"`
		Suff string `json:"suff"`
	}
	http.HandleFunc("/debug/nox/script/legacy", func(w http.ResponseWriter, r *http.Request) {
		var out []debugNoxScript
		scripts := noxServer.noxScript.scripts()
		for i := range scripts {
			s := &scripts[i]
			out = append(out, debugNoxScript{Ind: i, Name: alloc.GoString(s.name), Suff: alloc.GoString(s.suff)})
		}
		writeJSONResp(w, out)
	})
}
