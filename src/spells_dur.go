package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var (
	nox_alloc_spellDur_1569724 alloc.ClassT[noxDurSpell]
)

func nox_xxx_spellCastedFirst_4FE930() unsafe.Pointer {
	return noxServer.spells.duration.list.C()
}

func nox_xxx_spellCastedNext_4FE940(a1 unsafe.Pointer) unsafe.Pointer {
	return (*noxDurSpell)(a1).next.C()
}

func sub_4FE8A0(a1 int) {
	noxServer.spells.duration.sub4FE8A0(a1)
}

func sub_4FE900(a1 unsafe.Pointer) {
	noxServer.spells.duration.unlink((*noxDurSpell)(a1))
}

func nox_xxx_spellCastByPlayer_4FEEF0() {
	noxServer.spells.duration.spellCastByPlayer()
}

func nox_xxx_spellCancelDurSpell_4FEB10(a1 int, a2 *server.Object) {
	noxServer.spells.duration.CancelFor(spell.ID(a1), a2)
}

func sub_4FE980(a1 unsafe.Pointer) {
	noxServer.spells.duration.freeRecursive((*noxDurSpell)(a1))
}

func sub_4FF310(a1 *server.Object) {
	noxServer.spells.duration.nox_spell_cancelOffensiveFor_4FF310(a1)
}

type noxDurSpell struct {
	id      uint16         // 0, 0
	_       uint16         // 0, 2
	spell   uint32         // 1, 4
	level   uint32         // 2, 8
	obj12   *server.Object // 3, 12
	obj16   *server.Object // 4, 16
	flag20  uint32         // 5, 20
	obj24   *server.Object // 6, 24
	pos     types.Pointf   // 7, 28
	field36 uint32         // 9, 36
	field40 uint32         // 10, 40
	field44 uint32         // 11, 44
	obj48   *server.Object // 12, 48
	pos2    types.Pointf   // 13, 52
	frame60 uint32         // 15, 60
	frame64 uint32         // 16, 64
	frame68 uint32         // 17, 68
	field72 int32          // 18, 72
	field76 uint32         // 19, 76
	field80 uint32         // 20, 80
	field84 uint32         // 21, 84
	flags88 uint32         // 22, 88
	create  unsafe.Pointer // 23, 92
	update  unsafe.Pointer // 24, 96
	destroy unsafe.Pointer // 25, 100
	sub104  *noxDurSpell   // 26, 104
	sub108  *noxDurSpell   // 27, 108
	prev    *noxDurSpell   // 28, 112
	next    *noxDurSpell   // 29, 116
}

func (sp *noxDurSpell) C() unsafe.Pointer {
	return unsafe.Pointer(sp)
}

type spellsDuration struct {
	s       *Server
	lastID  uint16
	list    *noxDurSpell
	objects struct {
		Glyph int
	}
}

func (sp *spellsDuration) Init(s *Server) {
	sp.s = s
}

func (sp *spellsDuration) Free() {
	sp.objects.Glyph = 0
}

func (sp *spellsDuration) newDur() *noxDurSpell {
	p := nox_alloc_spellDur_1569724.NewObject()
	if p != nil {
		sp.lastID++
		p.id = sp.lastID
	}
	return p
}

func (sp *spellsDuration) sub4FE8A0(a1 int) {
	if a1 == 0 {
		nox_alloc_spellDur_1569724.FreeAllObjects()
		sp.list = nil
		return
	}
	var next *noxDurSpell
	for it := sp.list; it != nil; it = next {
		u := it.obj48
		next = it.next
		if u == nil || !u.Class().Has(object.ClassPlayer) {
			sub_4FE900(it.C())
			sub_4FE980(it.C())
		}
	}
}

func (sp *spellsDuration) freeRecursive(p *noxDurSpell) {
	var next1 *noxDurSpell
	for it := p.sub108; it != nil; it = next1 {
		next1 = it.next
		sp.freeRecursive(it)
	}
	var next2 *noxDurSpell
	for it := p.sub104; it != nil; it = next2 {
		next2 = it.next
		sp.freeRecursive(it)
	}
	nox_alloc_spellDur_1569724.FreeObjectFirst(p)
}

func (sp *spellsDuration) unlink(p *noxDurSpell) {
	if prev := p.prev; prev != nil {
		prev.next = p.next
	} else {
		sp.list = p.next
	}
	if next := p.next; next != nil {
		next.prev = p.prev
	}
}

func (sp *spellsDuration) newHook() {
	var next *noxDurSpell
	for it := sp.list; it != nil; it = next {
		next = it.next
		if it.flags88&0x1 != 0 {
			legacy.Nox_xxx_plrCastSmth_4FEDA0(it.C())
		}
	}
}

func (sp *spellsDuration) add(p *noxDurSpell) {
	if sp.list != nil {
		sp.list.prev = p
	}
	p.prev = nil
	p.next = sp.list
	sp.list = p
}

func spellIsSummon(sp spell.ID) bool {
	return sp >= spell.SPELL_SUMMON_BAT && sp <= spell.SPELL_SUMMON_URCHIN_SHAMAN
}

func (sp *spellsDuration) CancelFor(sid spell.ID, obj server.Obj) {
	var next *noxDurSpell
	for it := sp.list; it != nil; it = next {
		sid2 := spell.ID(it.spell)
		next = it.next
		if sid2 == sid && it.obj16 == toObjectS(obj) || spellIsSummon(sid) && spellIsSummon(sid2) && it.obj16 == toObjectS(obj) {
			legacy.Nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
		}
	}
}

func (sp *spellsDuration) sub4FEE50(a1 spell.ID, a2 *server.Object) bool {
	for it := sp.list; it != nil; it = it.next {
		if it.flag20 == 0 && spell.ID(it.spell) == a1 && it.obj16 == a2.SObj() && it.flags88&0x1 == 0 {
			return true
		}
	}
	return false
}

func (sp *spellsDuration) nox_spell_cancelOffensiveFor_4FF310(u *server.Object) {
	var next *noxDurSpell
	for it := sp.list; it != nil; it = next {
		next = it.next
		if it.obj16 == u.SObj() && sp.s.SpellFlags(spell.ID(it.spell)).Has(things.SpellOffensive) {
			legacy.Nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
		}
	}
}

func (sp *spellsDuration) spellCastByPlayer() {
	var next *noxDurSpell
	for it := sp.list; it != nil; it = next {
		next = it.next
		if it.flags88&0x1 != 0 {
			legacy.Nox_xxx_plrCastSmth_4FEDA0(it.C())
			continue
		}
		if obj16 := it.obj16; obj16 != nil && obj16.Flags().HasAny(object.FlagDead|object.FlagDestroyed) {
			it.obj16 = nil
		}

		if obj12 := it.obj12; obj12 != nil && obj12.Flags().Has(object.FlagDestroyed) {
			it.obj12 = nil
		}
		if it.obj16 == nil && it.flag20 == 0 {
			legacy.Nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
			continue
		}
		if obj24 := it.obj24; obj24 != nil && obj24.Flags().Has(object.FlagDestroyed) {
			it.obj24 = nil
		}
		if it.frame68 != it.frame60 && it.frame68 <= noxServer.Frame() || it.update != nil && ccall.CallIntPtr(it.update, it.C()) != 0 {
			legacy.Nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
		}
	}
}

func (sp *spellsDuration) New(spellID spell.ID, u1, u2, u3 *server.Object, sa *server.SpellAcceptArg, lvl int, create, update, destroy unsafe.Pointer, dt uint32) bool {
	if sp.objects.Glyph == 0 {
		sp.objects.Glyph = sp.s.ObjectTypeID("Glyph")
	}
	if u2 == nil || u2.Flags().HasAny(object.FlagDestroyed|object.FlagDead) && u3 != nil && int(u3.TypeInd) != sp.objects.Glyph {
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
	p.spell = uint32(spellID)
	p.level = uint32(lvl)
	p.obj12 = u1.SObj()
	p.obj16 = u2.SObj()
	p.sub104 = nil
	p.sub108 = nil
	if u3 != nil && int(u3.TypeInd) == sp.objects.Glyph {
		p.flag20 = 1
		p.obj24 = u3.SObj()
		p.pos = u3.Pos()
	} else {
		p.flag20 = 0
		p.obj24 = nil
		p.pos = u2.Pos()
	}
	p.field36 = 0
	p.obj48 = sa.Obj
	p.pos2 = sa.Pos
	p.frame60 = sp.s.Frame()
	p.frame64 = sp.s.Frame()
	p.frame68 = dt + sp.s.Frame()
	p.create = create
	p.update = update
	p.destroy = destroy
	p.flags88 = 0
	sp.add(p)
	sid := 0
	if sp.s.SpellHasFlags(spellID, things.SpellTargeted) {
		sid = 1
	}
	aud := sp.s.SpellDefByInd(spellID).GetAudio(sid)
	sp.s.AudioEventObj(aud, u2, 0, 0)
	if create == nil || ccall.CallIntPtr(create, p.C()) == 0 {
		return true
	}
	legacy.Nox_xxx_spellCancelSpellDo_4FE9D0(p.C())
	return false
}
