package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

func castVampirism(spellID spell.ID, _, _, _ *server.Object, args *server.SpellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, server.ENCHANT_VAMPIRISM, lvl, args.Obj, spellBuffConf{
		DurOpt: "VampirismEnchantDuration", DurOptMulQuest: "QuestVampDurMultiplier",
	})
}
