package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

func castSlow(spellID spell.ID, _, a3, _ *server.Object, args *server.SpellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, server.ENCHANT_SLOWED, lvl, args.Obj, spellBuffConf{
		DurOpt: "SlowEnchantDuration", Orig: a3, Offensive: true,
	})
}
