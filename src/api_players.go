package main

import (
	"encoding/json"
	"net/http"

	"nox/v1/common/types"
)

func init() {
	http.HandleFunc("/debug/nox/players", func(w http.ResponseWriter, r *http.Request) {
		type unit struct {
			Ind       int          `json:"ind"`
			ID        string       `json:"id,omitempty"`
			Enabled   bool         `json:"enabled"`
			Pos       types.Pointf `json:"pos"`
			Health    int          `json:"health"`
			MaxHealth int          `json:"health_max"`
		}
		type playerInfo struct {
			Index    int    `json:"index"`
			NetCode  int    `json:"net_code"`
			Name     string `json:"name"`
			OrigName string `json:"orig_name"`
			Active   bool   `json:"active"`
			Unit     *unit  `json:"unit"`
		}
		var arr []playerInfo
		for _, p := range getAllPlayerStructs() {
			var uni *unit
			if u := p.UnitC(); u != nil {
				hp, hpmax := u.Health()
				uni = &unit{
					Ind:       u.Ind(),
					ID:        u.ID(),
					Enabled:   u.IsEnabled(),
					Pos:       u.Pos(),
					Health:    hp,
					MaxHealth: hpmax,
				}
			}
			arr = append(arr, playerInfo{
				Index:    p.Index(),
				NetCode:  p.NetCode(),
				Name:     p.Name(),
				OrigName: p.OrigName(),
				Active:   p.IsActive(),
				Unit:     uni,
			})
		}
		enc := json.NewEncoder(w)
		enc.SetIndent("", "\t")
		enc.Encode(arr)
	})
}
