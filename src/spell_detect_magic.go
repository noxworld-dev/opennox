package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castDetectMagic(_ things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	asObjectC(args.Obj).ApplyEnchant(ENCHANT_DETECTING, 60*int(gameFPS()), lvl)
	return 1
}
