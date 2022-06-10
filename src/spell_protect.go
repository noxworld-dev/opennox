package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castProtectElectricity(spellID things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_PROTECT_FROM_ELECTRICITY, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "ProtectElectricityEnchantDuration",
	})
}

func castProtectPoison(spellID things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_PROTECT_FROM_POISON, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "ProtectPoisonEnchantDuration",
	})
}

func castProtectFire(spellID things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_PROTECT_FROM_FIRE, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "ProtectFireEnchantDuration",
	})
}
