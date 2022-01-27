package nox

import (
	"encoding/json"
	"net/http"

	noxflags "nox/v1/common/flags"
)

func init() {
	http.HandleFunc("/debug/nox/flags", func(w http.ResponseWriter, r *http.Request) {
		enc := json.NewEncoder(w)
		enc.SetIndent("", "\t")
		enc.Encode(struct {
			Game   noxflags.GameFlag   `json:"game"`
			Engine noxflags.EngineFlag `json:"engine"`
		}{
			Game:   noxflags.GetGame(),
			Engine: noxflags.GetEngine(),
		})
	})
	http.HandleFunc("/debug/nox/flags/game", func(w http.ResponseWriter, r *http.Request) {
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
	http.HandleFunc("/debug/nox/flags/engine", func(w http.ResponseWriter, r *http.Request) {
		q := r.URL.Query()
		if v := q.Get("set"); v != "" {
			if v, err := noxflags.ParseEngineFlag(v); err == nil {
				noxflags.SetEngine(v)
			}
		}
		if v := q.Get("unset"); v != "" {
			if v, err := noxflags.ParseEngineFlag(v); err == nil {
				noxflags.UnsetEngine(v)
			}
		}
		enc := json.NewEncoder(w)
		enc.SetIndent("", "\t")
		enc.Encode(noxflags.GetEngine())
	})
}
