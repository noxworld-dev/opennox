package server

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type DurSpell struct {
	ID       uint16         // 0, 0
	_        uint16         // 0, 2
	Spell    uint32         // 1, 4
	Level    uint32         // 2, 8
	Obj12    *Object        // 3, 12
	Caster16 *Object        // 4, 16
	Flag20   uint32         // 5, 20
	Obj24    *Object        // 6, 24
	Pos      types.Pointf   // 7, 28
	Field36  uint32         // 9, 36
	Field40  uint32         // 10, 40
	Field44  uint32         // 11, 44
	Target48 *Object        // 12, 48
	Pos2     types.Pointf   // 13, 52
	Frame60  uint32         // 15, 60
	Frame64  uint32         // 16, 64
	Frame68  uint32         // 17, 68
	Field72  int32          // 18, 72
	Field76  uintptr        // 19, 76
	Field80  uint32         // 20, 80
	Field84  uint32         // 21, 84
	Flags88  uint32         // 22, 88
	Create   unsafe.Pointer // 23, 92
	Update   unsafe.Pointer // 24, 96
	Destroy  unsafe.Pointer // 25, 100
	Sub104   *DurSpell      // 26, 104
	Sub108   *DurSpell      // 27, 108
	Prev     *DurSpell      // 28, 112
	Next     *DurSpell      // 29, 116
}

func (sp *DurSpell) C() unsafe.Pointer {
	return unsafe.Pointer(sp)
}

type SpellsDuration struct {
	s      *Server
	alloc  alloc.ClassT[DurSpell]
	List   *DurSpell
	lastID uint16
}

func (sp *SpellsDuration) init(s *Server) {
	sp.s = s
}

func (sp *SpellsDuration) Init() {
	sp.alloc = alloc.NewClassT("spellDuration", DurSpell{}, 512)
}

func (sp *SpellsDuration) Free() {
	sp.alloc.Free()
}

func (sp *SpellsDuration) NewRaw() *DurSpell {
	p := sp.alloc.NewObject()
	if p != nil {
		sp.lastID++
		p.ID = sp.lastID
	}
	return p
}

func (sp *SpellsDuration) NewLightningSub(src *DurSpell, from, to *Object) {
	p := sp.NewRaw()
	if p == nil {
		return
	}
	p.Target48 = to
	p.Caster16 = from
	p.Spell = uint32(spell.SPELL_CHAIN_LIGHTNING_BOLT)
	p.Sub108 = nil
	p.Sub104 = nil
	p.Prev = nil
	p.Next = src.Sub108
	if sub := src.Sub108; sub != nil {
		sub.Prev = p
	}
	src.Sub108 = p
}

func (sp *SpellsDuration) Sub4FE8A0(a1 bool) {
	if !a1 {
		sp.alloc.FreeAllObjects()
		sp.List = nil
		return
	}
	var next *DurSpell
	for it := sp.List; it != nil; it = next {
		u := it.Target48
		next = it.Next
		if u == nil || !u.Class().Has(object.ClassPlayer) {
			sp.Unlink(it)
			sp.FreeRecursive(it)
		}
	}
}

func (sp *SpellsDuration) FreeRecursive(p *DurSpell) {
	var next1 *DurSpell
	for it := p.Sub108; it != nil; it = next1 {
		next1 = it.Next
		sp.FreeRecursive(it)
	}
	var next2 *DurSpell
	for it := p.Sub104; it != nil; it = next2 {
		next2 = it.Next
		sp.FreeRecursive(it)
	}
	sp.alloc.FreeObjectFirst(p)
}

func (sp *SpellsDuration) Add(p *DurSpell) {
	if sp.List != nil {
		sp.List.Prev = p
	}
	p.Prev = nil
	p.Next = sp.List
	sp.List = p
}

func (sp *SpellsDuration) Unlink(p *DurSpell) {
	if prev := p.Prev; prev != nil {
		prev.Next = p.Next
	} else {
		sp.List = p.Next
	}
	if next := p.Next; next != nil {
		next.Prev = p.Prev
	}
}

func (sp *SpellsDuration) Sub4FEE50(a1 spell.ID, a2 *Object) bool {
	for it := sp.List; it != nil; it = it.Next {
		if it.Flag20 == 0 && spell.ID(it.Spell) == a1 && it.Caster16 == a2 && it.Flags88&0x1 == 0 {
			return true
		}
	}
	return false
}

func (sp *SpellsDuration) CancelOffensiveFor(u *Object) {
	var next *DurSpell
	for it := sp.List; it != nil; it = next {
		next = it.Next
		if it.Caster16 == u && sp.s.Spells.Flags(spell.ID(it.Spell)).Has(things.SpellOffensive) {
			sp.CancelSpell(it)
		}
	}
}

func (sp *SpellsDuration) CancelFor(sid spell.ID, obj Obj) {
	var next *DurSpell
	for it := sp.List; it != nil; it = next {
		sid2 := spell.ID(it.Spell)
		next = it.Next
		if sid2 == sid && it.Caster16 == ToObject(obj) || SpellIsSummon(sid) && SpellIsSummon(sid2) && it.Caster16 == ToObject(obj) {
			sp.CancelSpell(it)
		}
	}
}

func (sp *SpellsDuration) CancelSpell(sd *DurSpell) {
	obj := sd.Caster16
	spl := spell.ID(sd.Spell)
	if obj != nil && obj.Class().Has(object.ClassPlayer) {
		ud := obj.UpdateDataPlayer()
		if spl == spell.SPELL_CHAIN_LIGHTNING {
			sp.s.NetReportSpellStat(int(ud.Player.PlayerInd), spl, 0)
		} else {
			sp.s.NetReportSpellStat(int(ud.Player.PlayerInd), spl, 15)
		}
	}
	if spl == spell.SPELL_CHAIN_LIGHTNING {
		for i := sd.Sub108; i != nil; i = i.Next {
			if i.Target48 != nil {
				sp.s.NetStopRaySpell(i, i.Target48)
			}
		}
	} else if sd.Target48 != nil {
		sp.s.NetStopRaySpell(sd, sd.Target48)
	}
	sd.Flags88 |= 1
}
