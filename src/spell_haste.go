package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castHaste(_ things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	dur := int(gamedataFloat("HasteEnchantDuration"))
	asObjectC(args.Obj).ApplyEnchant(ENCHANT_HASTED, dur, lvl)
	return 1
}
