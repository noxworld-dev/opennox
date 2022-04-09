package opennox

import (
	"encoding/json"
	"net/http"

	"github.com/noxworld-dev/opennox-lib/things"
)

type debugSpellDef struct {
	ID        string            `json:"id,omitempty"`
	Title     string            `json:"title,omitempty"`
	Desc      string            `json:"desc,omitempty"`
	Flags     things.SpellFlags `json:"flags,omitempty"`
	Enabled   bool              `json:"enabled"`
	Valid     bool              `json:"valid"`
	ManaCost  int               `json:"mana_cost,omitempty"`
	BasePrice int               `json:"base_price,omitempty"`
	Phonemes  []things.Phoneme  `json:"phonemes,omitempty"`
}

var _ json.Marshaler = &SpellDef{}

func (s *SpellDef) dump() *debugSpellDef {
	if s == nil {
		return nil
	}
	return &debugSpellDef{
		Title:     s.Title,
		Desc:      s.Desc,
		Flags:     s.Def.Flags,
		Enabled:   s.Enabled,
		Valid:     s.Valid,
		ManaCost:  s.Def.ManaCost,
		BasePrice: s.Def.Price,
		Phonemes:  s.Def.Phonemes,
	}
}

func (s *SpellDef) MarshalJSON() ([]byte, error) {
	return json.Marshal(s.dump())
}

func init() {
	http.HandleFunc("/debug/nox/spells", func(w http.ResponseWriter, r *http.Request) {
		var out []*debugSpellDef
		spells := noxServer.SpellDefs()
		ids := SpellIDs()
		for i, s := range spells {
			d := s.dump()
			d.ID = ids[i]
			out = append(out, d)
		}
		writeJSONResp(w, out)
	})
}
