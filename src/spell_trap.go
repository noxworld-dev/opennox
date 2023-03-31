package opennox

import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_castGlyph_537FA0(sp spell.ID, a2, caster, targ *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	s := noxServer
	if !caster.Class().Has(object.ClassPlayer) {
		return 1
	}
	ud := caster.UpdateDataPlayer()
	pl := ud.Player
	if int(ud.CurTraps) >= int(gamedataFloat("MaxTrapCount")) {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 0, 5)
		return 0
	}
	if ud.TrapSpellsCnt == 0 {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 0, 7)
		return 0
	}
	trap := s.NewObjectByTypeID("Glyph")
	if trap == nil {
		return 0
	}
	if pl.PlayerClass() != player.Conjurer {
		s.CreateObjectAt(trap, caster, targ.Pos())
		snd := s.SpellDefByInd(sp).GetAudio(0)
		s.AudioEventObj(snd, targ, 0, 0)
	} else {
		if countBombers(caster) >= int(gamedataFloat("MaxBomberCount")) {
			nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 0, 5)
			s.DelayedDelete(trap)
			return 0
		}
		if !nox_xxx_checkSummonedCreaturesLimit_500D70(caster, 5) {
			s.DelayedDelete(trap)
			return 0
		}
		pos := s.randomReachablePointAround(50.0, targ.Pos())
		var bomb *server.Object
		if caster != nil {
			bomb = nox_xxx_unitDoSummonAt_5016C0(s.BomberID(), pos, caster, caster.Direction1)
		} else {
			bomb = nox_xxx_unitDoSummonAt_5016C0(s.BomberID(), pos, nil, 0)
		}
		if bomb != nil {
			legacy.Nox_xxx_inventoryPutImpl_4F3070(bomb, trap, 1)
		}
		s.AudioEventObj(sound.SoundBomberSummon, targ, 0, 0)
	}
	idata := trap.InitDataGlyph()
	*idata = server.GlyphInitData{
		SpellsCnt: 0,
		Field24:   0,
		Targ:      sa.Pos,
	}
	for i := 0; i < int(ud.TrapSpellsCnt); i++ {
		sp := spell.ID(ud.TrapSpells[i])
		if spl := s.SpellDefByInd(sp); spl != nil && spl.Enabled {
			idata.Spells[idata.SpellsCnt] = uint32(sp)
			idata.SpellsCnt++
		}
	}
	ud.TrapSpellsCnt = 0
	trap.Direction1 = targ.Direction1
	trap.Direction2 = targ.Direction1
	if pl.PlayerClass() == player.Wizard {
		ud.CurTraps++
	}
	return 1
}

func countBombers(u *server.Object) int {
	cnt := 0
	for it := u.FirstOwned516(); it != nil; it = it.NextOwned512() {
		if it.Class().Has(object.ClassMonster) && it.SubClass().AsMonster().Has(object.MonsterBomber) {
			cnt++
		}
	}
	return cnt
}
