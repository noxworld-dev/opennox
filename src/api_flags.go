package nox

import (
	"encoding/json"
	"net/http"

	noxflags "nox/v1/common/flags"
)

func init() {
	http.HandleFunc("/debug/nox/flags", func(w http.ResponseWriter, r *http.Request) {
		q := r.URL.Query()
		if v := q.Get("set"); v != "" {
			if v, err := noxflags.ParseGameFlag(v); err == nil {
				noxflags.SetGame(v)
			}
		}
		if v := q.Get("unset"); v != "" {
			if v, err := noxflags.ParseGameFlag(v); err == nil {
				noxflags.UnsetGame(v)
			}
		}
		enc := json.NewEncoder(w)
		enc.SetIndent("", "\t")
		enc.Encode(noxflags.GetGame())
	})
}
