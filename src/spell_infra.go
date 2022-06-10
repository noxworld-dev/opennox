package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castInfravision(_ things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	dur := int(gamedataFloat("InfravisionEnchantDuration"))
	asObjectC(args.Obj).ApplyEnchant(ENCHANT_INFRAVISION, dur, lvl)
	return 1
}
