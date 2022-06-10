package opennox

import (
	"github.com/noxworld-dev/opennox-lib/things"
)

func castVampirism(spellID things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_VAMPIRISM, lvl, asUnitC(args.Obj), spellBuffConf{
		DurOpt: "VampirismEnchantDuration", DurOptMulQuest: "QuestVampDurMultiplier",
	})
}
