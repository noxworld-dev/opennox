package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castProtectSpell(enc EnchantID, durKey string, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	dur := int(gamedataFloat(durKey))
	asObjectC(args.Obj).ApplyEnchant(enc, dur, lvl)
	return 1
}

func castProtectElectricity(_ things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castProtectSpell(ENCHANT_PROTECT_FROM_ELECTRICITY, "ProtectElectricityEnchantDuration", args, lvl)
}

func castProtectPoison(_ things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castProtectSpell(ENCHANT_PROTECT_FROM_POISON, "ProtectPoisonEnchantDuration", args, lvl)
}

func castProtectFire(_ things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castProtectSpell(ENCHANT_PROTECT_FROM_FIRE, "ProtectFireEnchantDuration", args, lvl)
}
