package opennox

import (
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func castNullify(_ things.SpellID, _, a3, _ *Unit, a5 *spellAcceptArg, lvl int) int {
	if a5.Obj == nil {
		return 0
	}
	dur := memmap.Uint32(0x5D4594, 599164+52*2)
	asObjectC(a5.Obj).ApplyEnchant(ENCHANT_ANTI_MAGIC, int(dur), lvl)
	sub_4E7540(a3, asObjectC(a5.Obj))
	return 1
}
