package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

type spellsDuration struct {
	s *Server
	*server.SpellsDuration
}

func (sp *spellsDuration) Init(s *Server) {
	sp.s = s
	sp.SpellsDuration = &s.Server.Spells.Dur
}

func (sp *spellsDuration) Free() {
}

func (sp *spellsDuration) onNewSpell() {
	var next *server.DurSpell
	for it := sp.List; it != nil; it = next {
		next = it.Next
		if it.Flags88&0x1 != 0 {
			sp.destroyDurSpell(it)
		}
	}
}

func (sp *spellsDuration) destroyDurSpell(spl *server.DurSpell) {
	if spl.Caster16 != nil {
		snd := sp.s.Spells.DefByInd(spell.ID(spl.Spell)).GetOffSound()
		sp.s.Audio.EventObj(snd, spl.Caster16, 0, 0)
	}
	if destroy := spl.Destroy; destroy != nil {
		ccall.CallVoidPtr(destroy, spl.C())
	}
	if u := spl.Caster16; u != nil {
		if u.Class().Has(object.ClassPlayer) {
			ud := u.UpdateDataPlayer()
			if ud.Player.PlayerClass() != player.Warrior || !sp.s.Abils.IsActive(u, server.AbilityBerserk) {
				nox_xxx_playerSetState_4FA020(u, server.PlayerState13)
			}
		} else if u.Class().Has(object.ClassMonster) {
			u.MonsterCancelDurSpell(spell.ID(spl.Spell))
		}
	}
	sp.Unlink(spl)
	sp.FreeRecursive(spl)
}

func (sp *spellsDuration) spellCastByPlayer() {
	var next *server.DurSpell
	for it := sp.List; it != nil; it = next {
		next = it.Next
		if it.Flags88&0x1 != 0 {
			sp.destroyDurSpell(it)
			continue
		}
		if obj16 := it.Caster16; obj16 != nil && obj16.Flags().HasAny(object.FlagDead|object.FlagDestroyed) {
			it.Caster16 = nil
		}

		if obj12 := it.Obj12; obj12 != nil && obj12.Flags().Has(object.FlagDestroyed) {
			it.Obj12 = nil
		}
		if it.Caster16 == nil && it.Flag20 == 0 {
			sp.CancelSpell(it)
			continue
		}
		if obj24 := it.Obj24; obj24 != nil && obj24.Flags().Has(object.FlagDestroyed) {
			it.Obj24 = nil
		}
		if it.Frame68 != it.Frame60 && it.Frame68 <= sp.s.Frame() || it.Update != nil && ccall.CallIntPtr(it.Update, it.C()) != 0 {
			sp.CancelSpell(it)
		}
	}
}

func (sp *spellsDuration) New(spellID spell.ID, u1, u2, u3 *server.Object, sa *server.SpellAcceptArg, lvl int, create, update, destroy unsafe.Pointer, dt uint32) bool {
	glyphID := sp.s.Types.GlyphID()
	if u2 == nil || u2.Flags().HasAny(object.FlagDestroyed|object.FlagDead) && u3 != nil && int(u3.TypeInd) != glyphID {
		return false
	}
	if u2 != nil {
		if (spellID == spell.SPELL_PLASMA || spellID == spell.SPELL_CHAIN_LIGHTNING) && sp.Sub4FEE50(spellID, u2) {
			return true
		}
		sp.CancelFor(spellID, u2)
	}
	sp.onNewSpell()
	p := sp.NewRaw()
	if p == nil {
		return false
	}
	p.Spell = uint32(spellID)
	p.Level = uint32(lvl)
	p.Obj12 = u1
	p.Caster16 = u2
	p.Sub104 = nil
	p.Sub108 = nil
	if u3 != nil && int(u3.TypeInd) == glyphID {
		p.Flag20 = 1
		p.Obj24 = u3
		p.Pos = u3.Pos()
	} else {
		p.Flag20 = 0
		p.Obj24 = nil
		p.Pos = u2.Pos()
	}
	p.Field36 = 0
	p.Target48 = sa.Obj
	p.Pos2 = sa.Pos
	p.Frame60 = sp.s.Frame()
	p.Frame64 = sp.s.Frame()
	p.Frame68 = dt + sp.s.Frame()
	p.Create = create
	p.Update = update
	p.Destroy = destroy
	p.Flags88 = 0
	sp.Add(p)
	def := sp.s.Spells.DefByInd(spellID)
	var aud sound.ID
	if sp.s.Spells.HasFlags(spellID, things.SpellTargeted) {
		aud = def.GetOnSound()
	} else {
		aud = def.GetCastSound()
	}
	sp.s.Audio.EventObj(aud, u2, 0, 0)
	if create == nil || ccall.CallIntPtr(create, p.C()) == 0 {
		return true
	}
	sp.CancelSpell(p)
	return false
}
