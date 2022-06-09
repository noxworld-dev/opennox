package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castVillain(_ things.SpellID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	asObjectC(args.Obj).ApplyEnchant(ENCHANT_VILLAIN, 12*lvl*int(gameFPS()), lvl)
	sub_4E7540(a3, asObjectC(args.Obj))
	return 1
}
