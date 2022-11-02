package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

func castNullify(spellID spell.ID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, server.ENCHANT_ANTI_MAGIC, lvl, asUnitC(args.Obj), spellBuffConf{
		Dur: noxServer.abilities.defs[AbilityWarcry].duration, Orig: a3, Offensive: true,
	})
}
