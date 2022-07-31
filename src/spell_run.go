package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"
)

func castRun(spellID spell.ID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_RUN, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "RunEnchantDuration", Orig: a3, Offensive: true,
	})
}
