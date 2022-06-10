package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castFear(spellID things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_AFRAID, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "FearEnchantDuration",
	})
}
