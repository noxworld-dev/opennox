package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

func castFreeze(spellID spell.ID, _, a3, _ *server.Object, args *server.SpellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, server.ENCHANT_FREEZE, lvl, args.Obj, spellBuffConf{
		Dur: 4, DurInSec: true, Orig: a3, Offensive: true,
	})
}
