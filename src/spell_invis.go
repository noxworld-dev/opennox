package opennox

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

func castInvisibility(spellID spell.ID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, server.ENCHANT_INVISIBLE, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "InvisibilityEnchantDuration", Defensive: true, PointFX: noxnet.MSG_FX_SMOKE_BLAST,
	})
}
