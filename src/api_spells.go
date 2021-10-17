package nox

import (
	"encoding/json"
	"net/http"

	"nox/v1/common/things"
)

type debugSpellDef struct {
	ID        string            `json:"id,omitempty"`
	Title     string            `json:"title,omitempty"`
	Desc      string            `json:"desc,omitempty"`
	Flags     things.SpellFlags `json:"flags,omitempty"`
	Allowed   bool              `json:"allowed"`
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
		Title:     s.Title(),
		Desc:      s.Description(),
		Flags:     s.Flags(),
		Allowed:   s.Allowed(),
		Valid:     s.Valid(),
		ManaCost:  s.ManaCost(),
		BasePrice: s.BasePrice(),
		Phonemes:  s.Phonemes(),
	}
}

func (s *SpellDef) MarshalJSON() ([]byte, error) {
	return json.Marshal(s.dump())
}

func init() {
	http.HandleFunc("/debug/nox/spells", func(w http.ResponseWriter, r *http.Request) {
		var out []*debugSpellDef
		spells := SpellDefs()
		ids := SpellIDs()
		for i, s := range spells {
			d := s.dump()
			d.ID = ids[i]
			out = append(out, d)
		}
		writeJSONResp(w, out)
	})
}
