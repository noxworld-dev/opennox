package opennox

import (
	"image"
	"net/http"
)

func init() {
	type debugNoxScript struct {
		Ind     int          `json:"ind"`
		Name    string       `json:"name"`
		Args    []uint32     `json:"args,omitempty"`
		Locals  []uint32     `json:"locals,omitempty"`
		Returns int          `json:"returns,omitempty"`
		Suff    string       `json:"suff,omitempty"`
		DPos    *image.Point `json:"dpos,omitempty"`
	}
	http.HandleFunc("/debug/nox/script/legacy", func(w http.ResponseWriter, r *http.Request) {
		var out []debugNoxScript
		funcs := noxServer.noxScript.Funcs()
		for i, f := range funcs {
			var dpos *image.Point
			if f.PosOff != (image.Point{}) {
				dpos = &f.PosOff
			}
			out = append(out, debugNoxScript{
				Ind:     i,
				Name:    f.Name(),
				Args:    f.Args(),
				Locals:  f.Locals(),
				Returns: f.Return,
				Suff:    f.NamePref,
				DPos:    dpos,
			})
		}
		writeJSONResp(w, out)
	})
}
