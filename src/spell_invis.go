package opennox

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/things"
)

func castInvisibility(spellID things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_INVISIBLE, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "InvisibilityEnchantDuration", Defensive: true, PointFX: noxnet.MSG_FX_SMOKE_BLAST,
	})
}
