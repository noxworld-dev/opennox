package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"
)

func castInvulnerability(spellID spell.ID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_INVULNERABLE, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "InvulnerabilityEnchantDuration", Defensive: true,
	})
}
