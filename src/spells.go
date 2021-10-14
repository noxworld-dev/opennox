package main

/*
#include "defs.h"
#include "GAME3_3.h"
extern nox_spell_t nox_spells_arr_588124[NOX_SPELLS_MAX+1];
void nox_xxx_spellCastByBook_4FCB80();
void nox_xxx_spellCastByPlayer_4FEEF0();
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/things"
)

const noxSpellsMax = int(C.NOX_SPELLS_MAX)

func nox_xxx_spellAwardAll1_4EFD80(p *Player) {
	C.nox_xxx_spellAwardAll1_4EFD80(p.C())
}

func nox_xxx_spellAwardAll2_4EFC80(p *Player) {
	C.nox_xxx_spellAwardAll2_4EFC80(p.C())
}

func nox_xxx_spellAwardAll3_4EFE10(p *Player) {
	C.nox_xxx_spellAwardAll3_4EFE10(p.C())
}

func nox_xxx_spellBookReact_4FCB70() {
	C.nox_xxx_spellCastByBook_4FCB80()
	C.nox_xxx_spellCastByPlayer_4FEEF0()
}

func SpellDefs() []*SpellDef {
	out := make([]*SpellDef, 0, noxSpellsMax)
	for i := 1; i < noxSpellsMax; i++ {
		out = append(out, (*SpellDef)(unsafe.Pointer(&C.nox_spells_arr_588124[i])))
	}
	return out
}

type SpellDef C.nox_spell_t

func (s *SpellDef) Title() string {
	return GoWString(s.title)
}

func (s *SpellDef) Description() string {
	return GoWString(s.desc)
}

func (s *SpellDef) Flags() things.SpellFlags {
	return things.SpellFlags(s.flags)
}

func (s *SpellDef) Allowed() bool {
	return s.enabled == 1
}

func (s *SpellDef) Valid() bool {
	return s.valid == 1
}

func (s *SpellDef) ManaCost() int {
	return int(s.mana_cost)
}

func (s *SpellDef) BasePrice() int {
	return int(s.price)
}
