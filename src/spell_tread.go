package opennox

import (
	"github.com/noxworld-dev/opennox-lib/object"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_warriorTreadLightly_5400B0(u *Unit, dur int) {
	if u == nil {
		return
	}
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	s := noxServer
	if ud := u.UpdateDataPlayer(); ud != nil {
		if ud.Field22_0 == 5 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		u.ApplyEnchant(server.ENCHANT_SNEAK, dur, int(asPlayerS(ud.Player).SpellLvl[server.AbilityTreadLightly]))
		s.abilities.netAbilReportActive(u, server.AbilityTreadLightly, true)
		legacy.Nox_xxx_frameCounterSetCopyToNextFrame_5281D0()
	}
}
