package opennox

import (
	"github.com/noxworld-dev/opennox-lib/things"
)

func castNullify(spellID things.SpellID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_ANTI_MAGIC, lvl, asUnitC(args.Obj), spellBuffConf{
		Dur: noxServer.abilities.defs[AbilityWarcry].duration, Orig: a3, Offensive: true,
	})
}
