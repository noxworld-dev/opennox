package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castFear(_ things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	dur := int(gamedataFloat("FearEnchantDuration"))
	asObjectC(args.Obj).ApplyEnchant(ENCHANT_AFRAID, dur, lvl)
	return 1
}
