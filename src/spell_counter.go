package opennox

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_cspellRemoveSpell_52BC90(obj *server.Object) {
	sobj := asObjectS(obj)
	s := obj.Server()
	if !obj.SubClass().AsMissile().Has(object.MissileMissileCounterSpell) {
		return
	}
	if obj.Flags().Has(object.FlagDestroyed) {
		return
	}
	s.Nox_xxx_netSendPointFx_522FF0(noxnet.MSG_FX_COUNTERSPELL_EXPLOSION, obj.PosVec)
	switch int(obj.TypeInd) {
	case s.Types.MagicID():
		sobj.Delete()
	case s.Types.DeathBallID():
		nox_xxx_deathBallCreateFragments_52BD30(obj)
		sobj.Delete()
	default:
		obj.CallCollide(0, 0)
		if !obj.Flags().Has(object.FlagDestroyed) {
			sobj.Delete()
		}
	}
}

func nox_xxx_castCounterSpell_52BBB0(cspl spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	s := noxServer
	r := s.Balance.Float("CounterspellRange")
	def := s.Spells.DefByInd(cspl)
	s.Map.EachMissileInCircle(a4.PosVec, float32(r), func(it *server.Object) bool {
		nox_xxx_cspellRemoveSpell_52BC90(it)
		return true
	})
	for sp := s.Spells.Dur.List; sp != nil; sp = sp.Next {
		spl := spell.ID(sp.Spell)
		if s.Spells.HasFlags(spl, things.SpellCanCounter) && (sp.Flags88&0x2 == 0 || spl == spell.SPELL_CHAIN_LIGHTNING) {
			dx := float64(sp.Pos.X - a4.PosVec.X)
			dy := float64(sp.Pos.Y - a4.PosVec.Y)
			if dy*dy+dx*dx <= r*r {
				s.Spells.Dur.CancelSpell(sp)
			}
		}
	}
	s.Map.EachObjInCircle(a4.PosVec, float32(r), func(it *server.Object) bool {
		found := false
		if it != a4 && (it.ObjFlags&0x8020) == 0 {
			for enc := server.EnchantID(0); enc < 32; enc++ {
				if !it.HasEnchant(enc) {
					continue
				}
				if it.EnchantDur(enc) == 0 {
					continue
				}
				esp := enc.Spell()
				if esp == 0 || !s.Spells.HasFlags(esp, things.SpellCanCounter) {
					continue
				}
				if !found {
					s.Nox_xxx_netSendPointFx_522FF0(noxnet.MSG_FX_COUNTERSPELL_EXPLOSION, it.PosVec)
					found = true
				}
				asObjectS(it).DisableEnchant(enc)
			}
		}
		return true
	})
	s.Audio.EventObj(def.GetCastSound(), a4, 0, 0)
	return 1
}

func nox_xxx_changeOwner_52BE40(mis, own *server.Object) {
	if !mis.Class().Has(object.ClassMissile) || !mis.SubClass().AsMissile().Has(object.MissileMagic) {
		return
	}
	s := mis.Server()
	ud := mis.UpdateDataMissile()
	if spell.ID(ud.SpellID) == spell.SPELL_SWAP {
		nox_xxx_cspellRemoveSpell_52BC90(mis)
	} else if ud.Target == own {
		ud.Target = ud.Owner
		ud.Owner = own
		mis.SetOwner(nil)
		mis.SetOwner(own)
		mis.Field32 = s.Frame()
		s.Audio.EventObj(sound.SoundInversionCast, own, 0, 0)
	}
}
