package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_4FE8A0(a1 int) {
	noxServer.spells.duration.sub4FE8A0(a1)
}

func nox_xxx_spellCancelDurSpell_4FEB10(a1 int, a2 *server.Object) {
	noxServer.spells.duration.CancelFor(spell.ID(a1), a2)
}

type spellsDuration struct {
	s      *Server
	alloc  alloc.ClassT[server.DurSpell]
	list   *server.DurSpell
	lastID uint16
}

func (sp *spellsDuration) Init(s *Server) {
	sp.s = s
	sp.alloc = alloc.NewClassT("spellDuration", server.DurSpell{}, 512)
}

func (sp *spellsDuration) Free() {
	sp.alloc.Free()
}

func (sp *spellsDuration) newDur() *server.DurSpell {
	p := sp.alloc.NewObject()
	if p != nil {
		sp.lastID++
		p.ID = sp.lastID
	}
	return p
}

func (sp *spellsDuration) sub4FE8A0(a1 int) {
	if a1 == 0 {
		sp.alloc.FreeAllObjects()
		sp.list = nil
		return
	}
	var next *server.DurSpell
	for it := sp.list; it != nil; it = next {
		u := it.Target48
		next = it.Next
		if u == nil || !u.Class().Has(object.ClassPlayer) {
			sp.unlink(it)
			sp.freeRecursive(it)
		}
	}
}

func (sp *spellsDuration) freeRecursive(p *server.DurSpell) {
	var next1 *server.DurSpell
	for it := p.Sub108; it != nil; it = next1 {
		next1 = it.Next
		sp.freeRecursive(it)
	}
	var next2 *server.DurSpell
	for it := p.Sub104; it != nil; it = next2 {
		next2 = it.Next
		sp.freeRecursive(it)
	}
	sp.alloc.FreeObjectFirst(p)
}

func (sp *spellsDuration) unlink(p *server.DurSpell) {
	if prev := p.Prev; prev != nil {
		prev.Next = p.Next
	} else {
		sp.list = p.Next
	}
	if next := p.Next; next != nil {
		next.Prev = p.Prev
	}
}

func (sp *spellsDuration) newHook() {
	var next *server.DurSpell
	for it := sp.list; it != nil; it = next {
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
				nox_xxx_playerSetState_4FA020(asObjectS(u), 13)
			}
		} else if u.Class().Has(object.ClassMonster) {
			monsterCancelDurSpell(u, spell.ID(spl.Spell))
		}
	}
	sp.unlink(spl)
	sp.freeRecursive(spl)
}

func (sp *spellsDuration) add(p *server.DurSpell) {
	if sp.list != nil {
		sp.list.Prev = p
	}
	p.Prev = nil
	p.Next = sp.list
	sp.list = p
}

func spellIsSummon(sp spell.ID) bool {
	return sp >= spell.SPELL_SUMMON_BAT && sp <= spell.SPELL_SUMMON_URCHIN_SHAMAN
}

func (sp *spellsDuration) CancelFor(sid spell.ID, obj server.Obj) {
	var next *server.DurSpell
	for it := sp.list; it != nil; it = next {
		sid2 := spell.ID(it.Spell)
		next = it.Next
		if sid2 == sid && it.Caster16 == toObjectS(obj) || spellIsSummon(sid) && spellIsSummon(sid2) && it.Caster16 == toObjectS(obj) {
			nox_xxx_spellCancelSpellDo_4FE9D0(it)
		}
	}
}

func (sp *spellsDuration) sub4FEE50(a1 spell.ID, a2 *server.Object) bool {
	for it := sp.list; it != nil; it = it.Next {
		if it.Flag20 == 0 && spell.ID(it.Spell) == a1 && it.Caster16 == a2.SObj() && it.Flags88&0x1 == 0 {
			return true
		}
	}
	return false
}

func (sp *spellsDuration) nox_spell_cancelOffensiveFor_4FF310(u *server.Object) {
	var next *server.DurSpell
	for it := sp.list; it != nil; it = next {
		next = it.Next
		if it.Caster16 == u.SObj() && sp.s.Spells.Flags(spell.ID(it.Spell)).Has(things.SpellOffensive) {
			nox_xxx_spellCancelSpellDo_4FE9D0(it)
		}
	}
}

func (sp *spellsDuration) spellCastByPlayer() {
	var next *server.DurSpell
	for it := sp.list; it != nil; it = next {
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
			nox_xxx_spellCancelSpellDo_4FE9D0(it)
			continue
		}
		if obj24 := it.Obj24; obj24 != nil && obj24.Flags().Has(object.FlagDestroyed) {
			it.Obj24 = nil
		}
		if it.Frame68 != it.Frame60 && it.Frame68 <= noxServer.Frame() || it.Update != nil && ccall.CallIntPtr(it.Update, it.C()) != 0 {
			nox_xxx_spellCancelSpellDo_4FE9D0(it)
		}
	}
}

func (sp *spellsDuration) New(spellID spell.ID, u1, u2, u3 *server.Object, sa *server.SpellAcceptArg, lvl int, create, update, destroy unsafe.Pointer, dt uint32) bool {
	glyphID := sp.s.Types.GlyphID()
	if u2 == nil || u2.Flags().HasAny(object.FlagDestroyed|object.FlagDead) && u3 != nil && int(u3.TypeInd) != glyphID {
		return false
	}
	if u2 != nil {
		if (spellID == spell.SPELL_PLASMA || spellID == spell.SPELL_CHAIN_LIGHTNING) && sp.sub4FEE50(spellID, u2) {
			return true
		}
		sp.CancelFor(spellID, u2)
	}
	sp.newHook()
	p := sp.newDur()
	if p == nil {
		return false
	}
	p.Spell = uint32(spellID)
	p.Level = uint32(lvl)
	p.Obj12 = u1.SObj()
	p.Caster16 = u2.SObj()
	p.Sub104 = nil
	p.Sub108 = nil
	if u3 != nil && int(u3.TypeInd) == glyphID {
		p.Flag20 = 1
		p.Obj24 = u3.SObj()
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
	sp.add(p)
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
	nox_xxx_spellCancelSpellDo_4FE9D0(p)
	return false
}
