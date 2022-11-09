package opennox

/*
#include <stdint.h>
void nox_xxx_plrCastSmth_4FEDA0(void* a1);
char nox_xxx_spellCancelSpellDo_4FE9D0(void* a1);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

var (
	nox_alloc_spellDur_1569724 alloc.ClassT[noxDurSpell]
)

//export nox_xxx_spellCastedFirst_4FE930
func nox_xxx_spellCastedFirst_4FE930() unsafe.Pointer {
	return noxServer.spells.duration.list.C()
}

//export nox_xxx_spellCastedNext_4FE940
func nox_xxx_spellCastedNext_4FE940(a1 unsafe.Pointer) unsafe.Pointer {
	return (*noxDurSpell)(a1).next.C()
}

//export sub_4FE8A0
func sub_4FE8A0(a1 int) {
	noxServer.spells.duration.sub4FE8A0(a1)
}

//export sub_4FE900
func sub_4FE900(a1 unsafe.Pointer) {
	noxServer.spells.duration.unlink((*noxDurSpell)(a1))
}

//export sub_4FEE50
func sub_4FEE50(a1 uint32, a2 *nox_object_t) int {
	return noxServer.spells.duration.sub4FEE50(spell.ID(a1), asUnitC(a2))
}

//export nox_xxx_spellCastByPlayer_4FEEF0
func nox_xxx_spellCastByPlayer_4FEEF0() {
	noxServer.spells.duration.spellCastByPlayer()
}

//export nox_xxx_spellCancelDurSpell_4FEB10
func nox_xxx_spellCancelDurSpell_4FEB10(a1 int, a2 *nox_object_t) {
	noxServer.spells.duration.CancelFor(spell.ID(a1), asUnitC(a2))
}

//export sub_4FE980
func sub_4FE980(a1 unsafe.Pointer) {
	noxServer.spells.duration.freeRecursive((*noxDurSpell)(a1))
}

//export sub_4FED70
func sub_4FED70() {
	noxServer.spells.duration.newHook()
}

//export sub_4FF310
func sub_4FF310(a1 *nox_object_t) {
	noxServer.spells.duration.nox_spell_cancelOffensiveFor_4FF310(asUnitC(a1))
}

//export sub_4FED40
func sub_4FED40(a1 unsafe.Pointer) {
	noxServer.spells.duration.add((*noxDurSpell)(a1))
}

//export nox_xxx_newSpellDuration_4FE950
func nox_xxx_newSpellDuration_4FE950() unsafe.Pointer {
	return noxServer.spells.duration.newDur().C()
}

type noxDurSpell struct {
	id      uint16         // 0, 0
	_       uint16         // 0, 2
	spell   uint32         // 1, 4
	level   uint32         // 2, 8
	obj12   *nox_object_t  // 3, 12
	obj16   *nox_object_t  // 4, 16
	flag20  uint32         // 5, 20
	obj24   *nox_object_t  // 6, 24
	pos     types.Pointf   // 7, 28
	field36 uint32         // 9, 36
	field40 uint32         // 10, 40
	field44 uint32         // 11, 44
	obj48   *nox_object_t  // 12, 48
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
	s      *Server
	lastID uint16
	list   *noxDurSpell
}

func (sp *spellsDuration) Init(s *Server) {
	sp.s = s
}

func (sp *spellsDuration) Free() {
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
		u := asUnitC(it.obj48)
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
			C.nox_xxx_plrCastSmth_4FEDA0(it.C())
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

func (sp *spellsDuration) CancelFor(sid spell.ID, obj noxObject) {
	var next *noxDurSpell
	for it := sp.list; it != nil; it = next {
		sid2 := spell.ID(it.spell)
		next = it.next
		if sid2 == sid && it.obj16 == toCObj(obj) || spellIsSummon(sid) && spellIsSummon(sid2) && it.obj16 == toCObj(obj) {
			C.nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
		}
	}
}

func (sp *spellsDuration) sub4FEE50(a1 spell.ID, a2 *Unit) int {
	for it := sp.list; it != nil; it = it.next {
		if it.flag20 == 0 && spell.ID(it.spell) == a1 && it.obj16 == a2.CObj() && it.flags88&0x1 == 0 {
			return 1
		}
	}
	return 0
}

func (sp *spellsDuration) nox_spell_cancelOffensiveFor_4FF310(u *Unit) {
	var next *noxDurSpell
	for it := sp.list; it != nil; it = next {
		next = it.next
		if it.obj16 == u.CObj() && sp.s.spellFlags(spell.ID(it.spell)).Has(things.SpellOffensive) {
			C.nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
		}
	}
}

func (sp *spellsDuration) spellCastByPlayer() {
	var next *noxDurSpell
	for it := sp.list; it != nil; it = next {
		next = it.next
		if it.flags88&0x1 != 0 {
			C.nox_xxx_plrCastSmth_4FEDA0(it.C())
			continue
		}
		if obj16 := asObjectC(it.obj16); obj16 != nil && obj16.Flags().HasAny(object.FlagDead|object.FlagDestroyed) {
			it.obj16 = nil
		}

		if obj12 := asObjectC(it.obj12); obj12 != nil && obj12.Flags().Has(object.FlagDestroyed) {
			it.obj12 = nil
		}
		if it.obj16 == nil && it.flag20 == 0 {
			C.nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
			continue
		}
		if obj24 := asObjectC(it.obj24); obj24 != nil && obj24.Flags().Has(object.FlagDestroyed) {
			it.obj24 = nil
		}
		if it.frame68 != it.frame60 && it.frame68 <= noxServer.Frame() ||
			it.update != nil && cgoCallIntVoidPtrFunc(it.update, it.C()) != 0 {
			C.nox_xxx_spellCancelSpellDo_4FE9D0(it.C())
		}
	}
}
