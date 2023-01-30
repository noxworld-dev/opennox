package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

func castVillain(spellID spell.ID, _, a3, _ *server.Object, args *server.SpellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, server.ENCHANT_VILLAIN, lvl, args.Obj, spellBuffConf{
		Dur: 12, DurFPSMul: true, DurLevelMul: true, Orig: a3, Offensive: true,
	})
}
