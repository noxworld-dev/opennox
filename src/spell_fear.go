package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"
)

func castFear(spellID spell.ID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_AFRAID, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "FearEnchantDuration",
	})
}
