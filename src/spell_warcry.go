package opennox

import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_warriorWarcry_53FF40(u *Unit) {
	if u == nil {
		return
	}
	const dist = 300.0
	s := noxServer
	if u.Class().Has(object.ClassPlayer) {
		if ud := u.UpdateDataPlayer(); ud != nil {
			ud.Field59_0 = 0
		}
	}
	nox_xxx_playerSetState_4FA020(u, 1)
	legacy.Nox_xxx_spell_4FE680(u.SObj(), dist)
	s.Map.EachObjInCircle(u.Pos(), dist, func(it *server.Object) {
		if !it.Class().HasAny(object.MaskUnits) {
			return
		}
		if it.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			return
		}
		u2 := asUnitS(it)
		if u2.Class().Has(object.ClassPlayer) {
			pl := u2.ControllingPlayer()
			if pl == nil {
				return
			}
			if pl.PlayerClass() == player.Warrior {
				return
			}
			if pl.Field3680&0x1 != 0 {
				return
			}
		} else if u2.Class().Has(object.ClassMonster) {
			ud := u2.UpdateDataMonster()
			if ud.Field360&0x20 == 0 {
				return
			}
		}
		if !server.Nox_xxx_servCompareTeams_419150(u.TeamPtr(), u2.TeamPtr()) {
			if legacy.Nox_xxx_mapCheck_537110(u2.SObj(), u.SObj()) != 0 {
				pos := u2.Pos()
				sa, free := alloc.New(server.SpellAcceptArg{})
				defer free()
				*sa = server.SpellAcceptArg{
					Obj: u2.SObj(),
					Pos: pos,
				}
				s.Nox_xxx_spellAccept4FD400(spell.SPELL_NULLIFY, u.SObj(), u.SObj(), u.SObj(), sa, 5)
			}
		}
	})
	u.DisableEnchant(server.ENCHANT_INVISIBLE)
	u.DisableEnchant(server.ENCHANT_INVULNERABLE)
	s.spells.duration.CancelFor(spell.SPELL_OVAL_SHIELD, u)
	s.abilities.netAbilReportActive(u, server.AbilityWarcry, true)
}
