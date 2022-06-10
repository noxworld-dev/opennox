package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castRun(spellID things.SpellID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_RUN, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "RunEnchantDuration", Orig: a3, Offensive: true,
	})
}
