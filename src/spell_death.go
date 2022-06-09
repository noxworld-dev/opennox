package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castDeath(_ things.SpellID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	obj := asObjectC(args.Obj)
	if obj.HasEnchant(ENCHANT_DEATH) {
		return 0
	}
	obj.ApplyEnchant(ENCHANT_DEATH, 450, lvl)
	if a3 != nil {
		sub_4E7540(a3, obj)
	}
	return 1
}
