package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

func castDetectMagic(spellID spell.ID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, server.ENCHANT_DETECTING, lvl, asUnitC(args.Obj), spellBuffConf{
		Dur: 60, DurFPSMul: true,
	})
}
