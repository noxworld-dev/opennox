package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var (
	nox_alloc_spellDur_1569724 alloc.ClassT[server.DurSpell]
)

func nox_xxx_spellCastedFirst_4FE930() unsafe.Pointer {
	return noxServer.spells.duration.list.C()
}

func nox_xxx_spellCastedNext_4FE940(a1 unsafe.Pointer) unsafe.Pointer {
	return (*server.DurSpell)(a1).Next.C()
}

func sub_4FE8A0(a1 int) {
	noxServer.spells.duration.sub4FE8A0(a1)
}

func sub_4FE900(a1 unsafe.Pointer) {
	noxServer.spells.duration.unlink((*server.DurSpell)(a1))
}

func nox_xxx_spellCastByPlayer_4FEEF0() {
	noxServer.spells.duration.spellCastByPlayer()
}

func nox_xxx_spellCancelDurSpell_4FEB10(a1 int, a2 *server.Object) {
	noxServer.spells.duration.CancelFor(spell.ID(a1), a2)
}

func sub_4FE980(a1 unsafe.Pointer) {
	noxServer.spells.duration.freeRecursive((*server.DurSpell)(a1))
}

func sub_4FF310(a1 *server.Object) {
	noxServer.spells.duration.nox_spell_cancelOffensiveFor_4FF310(a1)
}

type spellsDuration struct {
	s      *Server
	lastID uint16
	list   *server.DurSpell
}

func (sp *spellsDuration) Init(s *Server) {
	sp.s = s
}

func (sp *spellsDuration) Free() {
}

func (sp *spellsDuration) newDur() *server.DurSpell {
	p := nox_alloc_spellDur_1569724.NewObject()
	if p != nil {
		sp.lastID++
		p.ID = sp.lastID
	}
	return p
}

func (sp *spellsDuration) sub4FE8A0(a1 int) {
	if a1 == 0 {
		nox_alloc_spellDur_1569724.FreeAllObjects()
		sp.list = nil
		return
	}
	var next *server.DurSpell
	for it := sp.list; it != nil; it = next {
		u := it.Obj48
		next = it.Next
		if u == nil || !u.Class().Has(object.ClassPlayer) {
			sub_4FE900(it.C())
			sub_4FE980(it.C())
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
	nox_alloc_spellDur_1569724.FreeObjectFirst(p)
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
			legacy.Nox_xxx_plrCastSmth_4FEDA0(it.C())
		}
	}
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
		if sid2 == sid && it.Obj16 == toObjectS(obj) || spellIsSummon(sid) && spellIsSummon(sid2) && it.Obj16 == toObjectS(obj) {
			legacy.Nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
		}
	}
}

func (sp *spellsDuration) sub4FEE50(a1 spell.ID, a2 *server.Object) bool {
	for it := sp.list; it != nil; it = it.Next {
		if it.Flag20 == 0 && spell.ID(it.Spell) == a1 && it.Obj16 == a2.SObj() && it.Flags88&0x1 == 0 {
			return true
		}
	}
	return false
}

func (sp *spellsDuration) nox_spell_cancelOffensiveFor_4FF310(u *server.Object) {
	var next *server.DurSpell
	for it := sp.list; it != nil; it = next {
		next = it.Next
		if it.Obj16 == u.SObj() && sp.s.SpellFlags(spell.ID(it.Spell)).Has(things.SpellOffensive) {
			legacy.Nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
		}
	}
}

func (sp *spellsDuration) spellCastByPlayer() {
	var next *server.DurSpell
	for it := sp.list; it != nil; it = next {
		next = it.Next
		if it.Flags88&0x1 != 0 {
			legacy.Nox_xxx_plrCastSmth_4FEDA0(it.C())
			continue
		}
		if obj16 := it.Obj16; obj16 != nil && obj16.Flags().HasAny(object.FlagDead|object.FlagDestroyed) {
			it.Obj16 = nil
		}

		if obj12 := it.Obj12; obj12 != nil && obj12.Flags().Has(object.FlagDestroyed) {
			it.Obj12 = nil
		}
		if it.Obj16 == nil && it.Flag20 == 0 {
			legacy.Nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
			continue
		}
		if obj24 := it.Obj24; obj24 != nil && obj24.Flags().Has(object.FlagDestroyed) {
			it.Obj24 = nil
		}
		if it.Frame68 != it.Frame60 && it.Frame68 <= noxServer.Frame() || it.Update.Get() != nil && it.Update.Get()(it) != 0 {
			legacy.Nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
		}
	}
}

func (sp *spellsDuration) New(spellID spell.ID, u1, u2, u3 *server.Object, sa *server.SpellAcceptArg, lvl int, create server.DurSpellCreateFunc, update server.DurSpellUpdateFunc, destroy server.DurSpellDestroyFunc, dt uint32) bool {
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
	p.Obj16 = u2.SObj()
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
	p.Obj48 = sa.Obj
	p.Pos2 = sa.Pos
	p.Frame60 = sp.s.Frame()
	p.Frame64 = sp.s.Frame()
	p.Frame68 = dt + sp.s.Frame()
	p.Create = ccall.FuncPtr(create)
	p.Update = ccall.FuncPtr(update)
	p.Destroy = ccall.FuncPtr(destroy)
	p.Flags88 = 0
	sp.add(p)
	sid := 0
	if sp.s.SpellHasFlags(spellID, things.SpellTargeted) {
		sid = 1
	}
	aud := sp.s.SpellDefByInd(spellID).GetAudio(sid)
	sp.s.AudioEventObj(aud, u2, 0, 0)
	if create == nil || create(p) == 0 {
		return true
	}
	legacy.Nox_xxx_spellCancelSpellDo_4FE9D0(p.C())
	return false
}
