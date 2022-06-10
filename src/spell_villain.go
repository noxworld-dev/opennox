package opennox

import "github.com/noxworld-dev/opennox-lib/things"

func castVillain(spellID things.SpellID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_VILLAIN, lvl, asUnitC(args.Obj), spellBuffConf{
		Dur: 12, DurFPSMul: true, DurLevelMul: true, Orig: a3, Offensive: true,
	})
}
