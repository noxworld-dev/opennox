package server

import (
	"encoding/json"

	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
)

type DebugSpellDef struct {
	ID        string            `json:"id,omitempty"`
	Title     string            `json:"title,omitempty"`
	Desc      string            `json:"desc,omitempty"`
	Flags     things.SpellFlags `json:"flags,omitempty"`
	Enabled   bool              `json:"enabled"`
	Valid     bool              `json:"valid"`
	ManaCost  int               `json:"mana_cost,omitempty"`
	BasePrice int               `json:"base_price,omitempty"`
	Phonemes  []spell.Phoneme   `json:"phonemes,omitempty"`
}

var _ json.Marshaler = &SpellDef{}

func (s *SpellDef) Dump() *DebugSpellDef {
	if s == nil {
		return nil
	}
	return &DebugSpellDef{
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
	return json.Marshal(s.Dump())
}
