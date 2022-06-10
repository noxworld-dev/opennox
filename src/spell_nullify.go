package opennox

import (
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func castNullify(spellID things.SpellID, _, a3, _ *Unit, args *spellAcceptArg, lvl int) int {
	return castBuffSpell(spellID, ENCHANT_ANTI_MAGIC, lvl, asUnitC(args.Obj), spellBuffConf{
		Dur: int(memmap.Uint32(0x5D4594, 599164+52*2)), Orig: a3, Offensive: true,
	})
}
