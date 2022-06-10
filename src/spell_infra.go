package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castInfravision(spellID things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_INFRAVISION, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "InfravisionEnchantDuration",
	})
}
