package server

import (
	"github.com/noxworld-dev/opennox-lib/spell"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

func CanUseSummonSpell(sp spell.ID) bool {
	if noxflags.HasGame(noxflags.GameModeQuest) {
		return true
	}
	switch sp {
	case spell.SPELL_SUMMON_DEMON,
		spell.SPELL_SUMMON_LICH,
		spell.SPELL_SUMMON_DRYAD,
		spell.SPELL_SUMMON_URCHIN_SHAMAN:
		return false
	}
	return true
}
