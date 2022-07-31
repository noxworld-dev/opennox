package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"
)

func castAnchor(spellID spell.ID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_ANCHORED, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "AnchorEnchantDuration", Orig: a3, Offensive: true,
	})
}
