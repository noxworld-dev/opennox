package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

func castVampirism(spellID spell.ID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, server.ENCHANT_VAMPIRISM, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "VampirismEnchantDuration", DurOptMulQuest: "QuestVampDurMultiplier",
	})
}
