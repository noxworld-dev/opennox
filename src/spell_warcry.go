package opennox

/*
#include "GAME4.h"
#include "GAME4_3.h"
*/
import "C"
import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

func nox_xxx_warriorWarcry_53FF40(u *Unit) {
	if u == nil {
		return
	}
	const dist = 300.0
	s := noxServer
	if u.Class().Has(object.ClassPlayer) {
		if ud := u.updateDataPlayer(); ud != nil {
			ud.field_59_0 = 0
		}
	}
	nox_xxx_playerSetState_4FA020(u, 1)
	C.nox_xxx_spell_4FE680(u.CObj(), dist)
	getUnitsInCircle(u.Pos(), dist, func(it *Object) {
		if !it.Class().HasAny(object.MaskUnits) {
			return
		}
		if it.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			return
		}
		u2 := it.AsUnit()
		if u2.Class().Has(object.ClassPlayer) {
			pl := u2.ControllingPlayer()
			if pl == nil {
				return
			}
			if pl.PlayerClass() == player.Warrior {
				return
			}
			if pl.field_3680&0x1 != 0 {
				return
			}
		} else if u2.Class().Has(object.ClassMonster) {
			ud := u2.updateDataMonster()
			if ud.field_360&0x20 == 0 {
				return
			}
		}
		if !nox_xxx_servCompareTeams_419150(u.teamPtr(), u2.teamPtr()) {
			if C.nox_xxx_mapCheck_537110(u2.CObj(), u.CObj()) != 0 {
				pos := u2.Pos()
				sa, free := alloc.New(spellAcceptArg{})
				defer free()
				*sa = spellAcceptArg{
					Obj:  u2.CObj(),
					Arg1: pos.X,
					Arg2: pos.Y,
				}
				s.nox_xxx_spellAccept4FD400(spell.SPELL_NULLIFY, u, u, u, sa, 5)
			}
		}
	})
	u.DisableEnchant(ENCHANT_INVISIBLE)
	u.DisableEnchant(ENCHANT_INVULNERABLE)
	nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_OVAL_SHIELD, u)
	s.abilities.netAbilReportActive(u, AbilityWarcry, true)
}
