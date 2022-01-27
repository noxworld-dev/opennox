package nox

/*
#include "defs.h"
#include "server__magic__plyrspel.h"
#include "GAME3_3.h"
#include "GAME5_2.h"
extern nox_spell_t nox_spells_arr_588124[NOX_SPELLS_MAX+1];
void nox_xxx_spellCastByBook_4FCB80();
void nox_xxx_spellCastByPlayer_4FEEF0();
*/
import "C"
import (
	"unsafe"

	noxflags "nox/v1/common/flags"
	"nox/v1/common/player"
	"nox/v1/common/things"
)

const noxSpellsMax = int(C.NOX_SPELLS_MAX)

//export nox_xxx_spellAwardAll1_4EFD80
func nox_xxx_spellAwardAll1_4EFD80(p *C.nox_playerInfo) {
	serverSetAllBeastScrolls(asPlayer(p), noxflags.HasEngine(noxflags.EngineAdmin))
}

//export nox_xxx_spellAwardAll2_4EFC80
func nox_xxx_spellAwardAll2_4EFC80(p *C.nox_playerInfo) {
	serverSetAllSpells(asPlayer(p), noxflags.HasEngine(noxflags.EngineAdmin))
}

//export nox_xxx_spellAwardAll3_4EFE10
func nox_xxx_spellAwardAll3_4EFE10(p *C.nox_playerInfo) {
	serverSetAllWarriorAbilities(asPlayer(p), noxflags.HasEngine(noxflags.EngineAdmin))
}

func serverSetAllBeastScrolls(p *Player, enable bool) {
	lvl := 0
	if enable {
		lvl = 1
	}
	C.nox_xxx_playerUpdateNetBuffs_56F7D0(C.int(*(*uintptr)(p.field(4640))), 0)
	for i := 1; i < len(p.beast_scroll_lvl); i++ {
		p.beast_scroll_lvl[i] = C.uint(lvl)
		C.nox_xxx_playerAwardSpellProtection_56FCE0(C.int(*(*uintptr)(p.field(4640))), C.int(i), C.int(lvl))
	}
	C.sub_56FD50(C.int(*(*uintptr)(p.field(4640))), unsafe.Pointer(&p.beast_scroll_lvl[0]), C.int(len(p.beast_scroll_lvl)))
}

func serverSetAllSpells(p *Player, enable bool) {
	lvl := 0
	if enable {
		lvl = 3
	}
	C.nox_xxx_playerUpdateNetBuffs_56F7D0(C.int(*(*uintptr)(p.field(4636))), 0)
	for i := 1; i < len(p.spell_lvl); i++ {
		p.spell_lvl[i] = C.uint(lvl)
		C.nox_xxx_playerAwardSpellProtection_56FCE0(C.int(*(*uintptr)(p.field(4636))), C.int(i), C.int(lvl))
	}
	if !enable && noxflags.HasGame(noxflags.GameModeQuest) {
		u := p.UnitC()
		switch p.PlayerClass() {
		case player.Wizard:
			C.nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(u.CObj(), 27, 1, 1, 1)
		case player.Conjurer:
			C.nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(u.CObj(), 9, 1, 1, 1)
			C.nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(u.CObj(), 41, 1, 1, 1) // spawn spells?
		}
	}
	C.sub_56FD50(C.int(*(*uintptr)(p.field(4636))), unsafe.Pointer(&p.spell_lvl[0]), C.int(len(p.spell_lvl)))
}

func serverSetAllWarriorAbilities(p *Player, enable bool) {
	if p.PlayerClass() != player.Warrior {
		return
	}
	lvl := 0
	if enable {
		lvl = 5
	}
	for i := 1; i < 6; i++ {
		p.spell_lvl[i] = C.uint(lvl)
		C.nox_xxx_playerAwardSpellProtection_56FCE0(C.int(*(*uintptr)(p.field(4636))), C.int(i), C.int(lvl))
	}
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

func SpellDefByInd(i int) *SpellDef {
	if i <= 0 || i >= noxSpellsMax {
		return nil
	}
	return (*SpellDef)(unsafe.Pointer(&C.nox_spells_arr_588124[i]))
}

func SpellIDs() []string {
	out := make([]string, 0, noxSpellsMax)
	for i := 1; i < noxSpellsMax; i++ {
		out = append(out, things.SpellIDByIndex(i))
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

func (s *SpellDef) Phonemes() (out []things.Phoneme) {
	for i := 0; i < int(s.phonemes_cnt); i++ {
		out = append(out, things.Phoneme(i))
	}
	return out
}
