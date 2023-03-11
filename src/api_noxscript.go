package opennox

import (
	"image"
	"net/http"
)

func init() {
	type debugNoxScript struct {
		Ind  int         `json:"ind"`
		Name string      `json:"name"`
		Suff string      `json:"suff,omitempty"`
		DPos image.Point `json:"dpos,omitempty"`
	}
	http.HandleFunc("/debug/nox/script/legacy", func(w http.ResponseWriter, r *http.Request) {
		var out []debugNoxScript
		funcs := noxServer.noxScript.Funcs()
		for i, f := range funcs {
			out = append(out, debugNoxScript{
				Ind:  i,
				Name: f.Name(),
				Suff: f.NamePref,
				DPos: f.PosOff,
			})
		}
		writeJSONResp(w, out)
	})
}
