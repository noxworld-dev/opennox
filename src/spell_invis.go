package opennox

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/things"
)

func castInvisibility(_ things.SpellID, _, _, _ *Unit, args *spellAcceptArg, lvl int) int {
	if args.Obj == nil {
		return 0
	}
	dur := int(gamedataFloat("InvisibilityEnchantDuration"))
	obj := asObjectC(args.Obj)
	sub_4FF310(obj)
	obj.ApplyEnchant(ENCHANT_INVISIBLE, dur, lvl)
	nox_xxx_netSendPointFx_522FF0(noxnet.MSG_FX_SMOKE_BLAST, obj.Pos())
	return 1
}
