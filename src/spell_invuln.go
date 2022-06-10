package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castInvulnerability(_ things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	dur := int(gamedataFloat("InvulnerabilityEnchantDuration"))
	sub_4FF310(asObjectC(args.Obj))
	asObjectC(args.Obj).ApplyEnchant(ENCHANT_INVULNERABLE, dur, lvl)
	return 1
}
