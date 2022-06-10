package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castFreeze(spellID things.SpellID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_FREEZE, lvl, asUnitC(args.Obj), spellBuffConf{
		Dur: 4, DurFPSMul: true, Orig: a3, Offensive: true,
	})
}
