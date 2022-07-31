package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"
)

func castFreeze(spellID spell.ID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_FREEZE, lvl, asUnitC(args.Obj), spellBuffConf{
		Dur: 4, DurFPSMul: true, Orig: a3, Offensive: true,
	})
}
