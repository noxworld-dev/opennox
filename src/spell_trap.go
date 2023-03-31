package opennox

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

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
		SpellArg: server.SpellAcceptArg{
			Pos: sa.Pos,
		},
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

func setBomberSpells(u *server.Object, spells ...spell.ID) {
	s := noxServer
	if u == nil {
		return
	}
	if !u.Class().Has(object.ClassMonster) {
		return
	}
	if !u.SubClass().AsMonster().Has(object.MonsterBomber) {
		return
	}
	for it := u.FirstItem(); it != nil; it = it.NextItem() {
		if int(it.TypeInd) != s.GlyphID() {
			s.DelayedDelete(it)
			break
		}
	}
	trap := s.NewObjectByTypeID("Glyph")
	if trap == nil {
		return
	}
	idata := trap.InitDataGlyph()
	*idata = server.GlyphInitData{
		SpellsCnt: 0,
		SpellArg: server.SpellAcceptArg{
			Pos: u.Pos(),
		},
	}
	for _, sp := range spells {
		if !sp.Valid() {
			continue
		}
		idata.Spells[idata.SpellsCnt] = uint32(sp)
		idata.SpellsCnt++
	}
	legacy.Nox_xxx_inventoryPutImpl_4F3070(u, trap, 1)
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

func nox_xxx___mkgmtime_538280(obj *server.Object) {
	triggerTrap(obj, nil)
}

func nox_xxx_dieGlyph_54DF30(obj *server.Object) {
	triggerTrap(obj, nil)
}

func nox_xxx_collideGlyph_4E9A00(a1, a2 *server.Object) {
	if !legacy.Sub_4E9A30(a1, a2) {
		return
	}
	triggerTrap(a1, a2)
}

func castDetonateGlyphs(sp spell.ID, a2, a3, caster *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	s := noxServer
	pos := caster.Pos()
	const dist = 300
	rect := types.RectFromPointsf(pos.Sub(types.Ptf(dist, dist)), pos.Add(types.Ptf(dist, dist)))
	snd := s.SpellDefByInd(sp).GetAudio(0)
	s.AudioEventObj(snd, a3, 0, 0)
	for {
		var found *server.Object
		s.Map.EachObjInRect(rect, func(it *server.Object) bool {
			if int(it.TypeInd) != s.GlyphID() || it.Flags().Has(object.FlagDestroyed) {
				return true
			}
			owner := caster.FindOwnerChainPlayer()
			if it.HasOwner(owner) || it.ObjOwner == nil && !owner.Class().Has(object.ClassPlayer) {
				if s.MapTraceRayAt(caster.Pos(), it.Pos(), nil, nil, 5) {
					found = it
					return false
				}
			}
			return true
		})
		if found == nil {
			break
		}
		triggerTrap(found, nil)
	}
	return 1
}

func triggerTrap(trap, a2 *server.Object) {
	s := noxServer
	idata := trap.InitDataGlyph()
	if trap.Flags().Has(object.FlagDestroyed) {
		return
	}
	owner := trap.FindOwnerChainPlayer()
	s.DelayedDelete(trap)
	if owner != nil && owner.Class().Has(object.ClassPlayer) {
		ud := owner.UpdateDataPlayer()
		if ud.Player.PlayerClass() == player.Wizard {
			if ud.CurTraps != 0 {
				ud.CurTraps--
			}
		}
	}
	sa := &idata.SpellArg
	if a2 != nil {
		idata.SpellArg.Obj = a2
	} else {
		v10 := float32(gamedataFloat("GlyphRange"))
		idata.SpellArg.Obj = sub_4E6EA0(trap, v10, &trapSearchArg{
			Field0:             15,
			Field4:             1,
			Field8:             0,
			ClassAllow12:       object.MaskUnits,
			ClassDisallow16:    0,
			SubClassAllow20:    math.MaxUint32,
			SubClassDisallow24: 0,
			FlagsAllow28:       math.MaxUint32,
			FlagsDisallow32:    object.FlagDead,
		})
	}

	for i := 0; i < int(idata.SpellsCnt); i++ {
		sp := spell.ID(idata.Spells[i])
		if (!s.SpellHasFlags(sp, things.SpellFlagUnk1) || a2 != nil) && legacy.Sub_4FD0E0(owner, sp) == 0 {
			if owner.Class().Has(object.ClassPlayer) {
				lvl := legacy.Nox_xxx_spellGetPower_4FE7B0(sp, owner)
				s.Nox_xxx_spellAccept4FD400(sp, owner, owner, trap, sa, lvl)
			} else {
				s.Nox_xxx_spellAccept4FD400(sp, owner, owner, trap, sa, 2)
			}
		}
	}
	pos := trap.Pos()
	nox_xxx_netSendPointFx_522FF0(noxnet.MSG_FX_BLUE_SPARKS, pos)
	s.AudioEventPos(sound.SoundGlyphDetonate, pos, 0, 0)
	const dist = 100
	rect := types.RectFromPointsf(pos.Sub(types.Ptf(dist, dist)), pos.Add(types.Ptf(dist, dist)))
	s.Map.EachObjInRect(rect, func(it *server.Object) bool {
		if it != trap && (int32(uint8(*(*float32)(unsafe.Add(unsafe.Pointer(it), unsafe.Sizeof(float32(0))*4))))&0x20) == 0 {
			if int(it.TypeInd) == s.GlyphID() {
				if s.MapTraceRayAt(trap.Pos(), it.Pos(), nil, nil, 5) {
					_ = nox_xxx___mkgmtime_538280
					it.Update = legacy.Get_nox_xxx___mkgmtime_538280()
					s.Objs.AddToUpdatable(it)
				}
			}
		}
		return true
	})
}

type trapSearchArg struct {
	Field0             uint32          // 0, 0
	Field4             uint32          // 1, 4
	Field8             uint32          // 2, 8
	ClassAllow12       object.Class    // 3, 12
	ClassDisallow16    object.Class    // 4, 16
	SubClassAllow20    object.SubClass // 5, 20
	SubClassDisallow24 object.SubClass // 6, 24
	FlagsAllow28       object.Flags    // 7, 28
	FlagsDisallow32    object.Flags    // 8, 32
	Field36            *server.Object  // 9, 36
}

func sub_4E6EA0(a1 *server.Object, r float32, ta *trapSearchArg) *server.Object {
	s := noxServer
	if ta == nil {
		return nil
	}
	var (
		found *server.Object
		min   = float64(r * r)
	)
	ta.Field36 = a1
	s.Map.EachObjInCircle(a1.Pos(), r, func(it *server.Object) bool {
		if it.Flags().Has(object.FlagDestroyed) {
			return true
		}
		a1 := ta.Field36
		if !(!legacy.Nox_xxx_unitsHaveSameTeam_4EC520(it, a1) && (!it.Class().Has(object.ClassPlayer) || (int32(it.ControllingPlayer().Field3680&1) == 0) && (ta.Field8 == 0 || s.IsEnemyTo(a1, it)))) {
			return true
		}
		if uint32(legacy.Nox_server_testTwoPointsAndDirection_4E6E50(a1.Pos(), int16(a1.Direction1), it.Pos()))&ta.Field0 == 0 {
			return true
		}
		if it == a1 || (ta.Field4 != 0 && !nox_xxx_unitCanInteractWith_5370E0(a1, it, 0)) {
			return true
		}
		if !it.Class().HasAny(ta.ClassAllow12) || it.Class().HasAny(ta.ClassDisallow16) {
			return true
		}
		if !it.Flags().HasAny(ta.FlagsAllow28) || it.Flags().HasAny(ta.FlagsDisallow32) {
			return true
		}
		if !(it.SubClass() == 0 || it.SubClass().HasAny(ta.SubClassAllow20) && !it.SubClass().HasAny(ta.SubClassDisallow24)) {
			return true
		}
		dp := it.Pos().Sub(a1.Pos())
		dx, dy := float64(dp.X), float64(dp.Y)
		if d2 := dx*dx + dy*dy; d2 < min {
			min = d2
			found = it
		}
		return true
	})
	return found
}

func sub_4E71F0(obj *server.Object) {
	s := noxServer
	ud := obj.UpdateDataSpellProjectile()
	v2 := sub_4E6EA0(obj, 50.0, &trapSearchArg{
		Field0:             15,
		Field4:             1,
		Field8:             0,
		ClassAllow12:       object.MaskUnits,
		ClassDisallow16:    0,
		SubClassAllow20:    math.MaxUint32,
		SubClassDisallow24: 0,
		FlagsAllow28:       math.MaxUint32,
		FlagsDisallow32:    object.FlagDead | object.FlagDestroyed,
	})
	if v2 != nil {
		var sa server.SpellAcceptArg
		sa.Obj = v2
		s.Nox_xxx_spellAccept4FD400(spell.ID(ud.Spell12), ud.Field8, ud.Field0, ud.Field0, &sa, int(ud.Level16))
	}
	s.DelayedDelete(obj)
}

func nox_bomberDead_54A150(u *server.Object) int {
	s := noxServer
	ud := u.UpdateDataMonster()
	nox_xxx_netSendPointFx_522FF0(noxnet.MSG_FX_EXPLOSION, u.Pos())
	s.AudioEventObj(sound.SoundBomberDie, u, 0, 0)

	if it := u.FirstItem(); it != nil {
		// TODO: this assumes inventory of exactly 1 item, which is a trap
		//       instead, should scan for all traps, check the type of it, etc
		idata := it.InitDataGlyph()
		owner := it.ObjOwner
		legacy.Sub_4ED0C0(u, it)
		legacy.Nox_xxx_unitSetOwner_4EC290(owner, it)
		idata.SpellArg.Obj = nil
		idata.SpellArg.Pos = u.Pos()
		it.PosVec = u.PosVec
		it.NewPos = u.NewPos
		it.Direction1 = u.Direction1
		it.Direction2 = u.Direction1
		triggerTrap(it, ud.Field544)
	} else {
		s.Nox_xxx_mapDamageUnitsAround(u.Pos(), 50.0, 30.0, 10, object.DamageExplosion, u, nil, doDamageWalls)
		legacy.Nox_xxx_mapPushUnitsAround_52E040(u.Pos(), 50.0, 30.0, 30.0, u, 0, 0)
	}
	return 1
}
