package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castHaste(spellID things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_HASTED, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "HasteEnchantDuration",
	})
}
