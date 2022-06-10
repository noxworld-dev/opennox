package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castSlow(spellID things.SpellID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_SLOWED, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "SlowEnchantDuration", Orig: a3, Offensive: true,
	})
}
