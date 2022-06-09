package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castLight(_ things.SpellID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	dur := int(gamedataFloat("LightEnchantDuration"))
	asObjectC(args.Obj).ApplyEnchant(ENCHANT_LIGHT, dur, lvl)
	sub_4E7540(a3, asObjectC(args.Obj))
	return 1
}
