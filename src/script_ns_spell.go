package opennox

import (
	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/noxscript/ns/v4/enchant"
	nsp "github.com/noxworld-dev/noxscript/ns/v4/spell"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) CastSpellLvl(name nsp.Spell, lvl int, source, target ns4.Positioner) {
	sp := spell.ParseID(string(name))
	if !sp.Valid() {
		return
	}
	if source == nil || target == nil {
		return
	}
	srcH, _ := source.(server.Obj)
	targH, _ := target.(server.Obj)
	src := server.ToObject(srcH)
	if src != nil && src.Flags().HasAny(object.FlagDestroyed|object.FlagDead) {
		return
	}
	targPos := target.Pos()
	if src == nil {
		asObjectS(nox_xxx_imagCasterUnit_1569664).SetPos(source.Pos())
		src = nox_xxx_imagCasterUnit_1569664
	}
	src.Direction1 = server.DirFromVec(targPos.Sub(src.Pos()))
	// TODO: pass spell level
	s.s.castSpellBy(sp, lvl, src, targH, targPos)
}

func (s noxScriptNS) CastSpell(name nsp.Spell, source, target ns4.Positioner) {
	s.CastSpellLvl(name, -1, source, target)
}

func (s noxScriptNS) NewTrap(pos ns4.Positioner, spells []ns4.TrapSpell) ns4.Obj {
	if pos == nil {
		return nil
	}
	trap := s.s.NewObjectByTypeID("Glyph")
	if trap == nil {
		return nil
	}
	p := pos.Pos()
	s.s.CreateObjectAt(trap, nil, p)

	idata := trap.InitDataGlyph()
	*idata = server.GlyphInitData{
		SpellsCnt: 0,
		SpellArg: server.SpellAcceptArg{
			Pos: p,
		},
	}
	for _, sp := range spells {
		spl := spell.ParseID(string(sp.Spell))
		if !spl.Valid() {
			continue
		}
		idata.Spells[idata.SpellsCnt] = uint32(spl)
		idata.SpellsCnt++
	}
	return nsObj{s.s, asObjectS(trap)}
}

func (obj nsObj) AwardSpell(name nsp.Spell) bool {
	sp := spell.ParseID(string(name))
	if !sp.Valid() {
		return false
	}
	return legacy.Nox_xxx_spellGrantToPlayer_4FB550(obj.SObj(), sp, 1, 0, 0) != 0
}

func (obj nsObj) Enchant(enc enchant.Enchant, dt ns4.Duration) {
	id, ok := server.ParseEnchant(string(enc))
	if !ok {
		return
	}
	s := obj.Server()
	obj.ApplyEnchant(id, s.AsFrames(dt), 5)
}

func (obj nsObj) EnchantOff(enc enchant.Enchant) {
	e, ok := server.ParseEnchant(string(enc))
	if !ok {
		return
	}
	obj.DisableEnchant(e)
}

func (obj nsObj) TrapSpells(spells ...nsp.Spell) {
	out := make([]spell.ID, 0, len(spells))
	for _, name := range spells {
		sp := spell.ParseID(string(name))
		if !sp.Valid() {
			continue
		}
		out = append(out, sp)
	}
	obj.Object.SetTrapSpells(out...)
}

func (obj nsObj) TrapSpellsAdv(spells []ns4.TrapSpell) {
	out := make([]spell.ID, 0, len(spells))
	for _, s := range spells {
		sp := spell.ParseID(string(s.Spell))
		if !sp.Valid() {
			continue
		}
		out = append(out, sp)
	}
	obj.Object.SetTrapSpells(out...)
}

func (g nsObjGroup) AwardSpell(sp nsp.Spell) {
	spl := spell.ParseID(string(sp))
	if !spl.Valid() {
		return
	}
	g.EachObject(true, func(it ns4.Obj) bool {
		// TODO: why it.AwardSpell is different?
		val := 0
		obj := server.ToObject(it.(server.Obj))
		if noxflags.HasGame(noxflags.GameModeCoop) && it.Class().Has(object.ClassPlayer) && asPlayerS(obj.UpdateDataPlayer().Player).SpellLvl[spl] == 0 {
			val = 1
		}
		legacy.Nox_xxx_spellGrantToPlayer_4FB550(obj, spl, 1, val, 0)
		return true
	})
}
