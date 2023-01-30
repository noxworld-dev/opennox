package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

func castAnchor(spellID spell.ID, _, a3, _ *server.Object, args *server.SpellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, server.ENCHANT_ANCHORED, lvl, args.Obj, spellBuffConf{
		DurOpt: "AnchorEnchantDuration", Orig: a3, Offensive: true,
	})
}
