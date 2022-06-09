package opennox

import (
	"github.com/noxworld-dev/opennox-lib/things"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

func castVampirism(_ things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	dur := gamedataFloat("VampirismEnchantDuration")
	if noxflags.HasGame(noxflags.GameModeQuest) {
		dur *= gamedataFloat("QuestVampDurMultiplier")
	}
	asObjectC(args.Obj).ApplyEnchant(ENCHANT_VAMPIRISM, int(dur), lvl)
	return 1
}
