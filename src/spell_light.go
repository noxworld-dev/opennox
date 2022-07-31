package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"
)

func castLight(spellID spell.ID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_LIGHT, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "LightEnchantDuration", Orig: a3, Offensive: true,
	})
}
