package server

import (
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"
)

type SpellAcceptArg struct {
	Obj *Object
	Pos types.Pointf
}

type PhonemeLeaf struct {
	Ind int32
	Pho [spell.PhonMax]*PhonemeLeaf
}

func (p *PhonemeLeaf) Next(ph spell.Phoneme) *PhonemeLeaf { // nox_xxx_updateSpellRelated_424830
	if p == nil || !ph.Valid() {
		return nil
	}
	return p.Pho[ph]
}
