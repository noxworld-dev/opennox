package opennox

import (
	"errors"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Dword_5d4594_1569672       *server.MagicEntityClass
	dword_5d4594_1303508       *server.PhonemeLeaf
	Nox_alloc_magicEnt_1569668 alloc.ClassT[server.MagicEntityClass]
)

var _ = [1]struct{}{}[60-unsafe.Sizeof(server.MagicEntityClass{})]

type serverSpells struct {
	duration spellsDuration
	missiles spellMissiles
	walls    spellWall
}

func (sp *serverSpells) Init(s *Server) {
	sp.duration.Init(s)
	sp.missiles.Init(s)
	sp.walls.Init(s)
}

func (sp *serverSpells) Free() {
	sp.walls.Free()
	sp.missiles.Free()
	sp.duration.Free()
}

var _ = [1]struct{}{}[40-unsafe.Sizeof(server.PhonemeLeaf{})]

func nox_xxx_spellAwardAll1_4EFD80(p *server.Player) {
	serverSetAllBeastScrolls(p, noxflags.HasEngine(noxflags.EngineAdmin))
}

func nox_xxx_spellAwardAll2_4EFC80(p *server.Player) {
	serverSetAllSpells(p, noxflags.HasEngine(noxflags.EngineAdmin), 0)
}

func nox_xxx_spellAwardAll3_4EFE10(p *server.Player) {
	serverSetAllWarriorAbilities(p, noxflags.HasEngine(noxflags.EngineAdmin), 0)
}

func nox_xxx_spellTitle_424930(ind int) (string, bool) {
	sp := noxServer.Spells.DefByInd(spell.ID(ind))
	if sp == nil || !sp.IsValid() {
		return "", false
	}
	return sp.Title, true
}

func nox_xxx_spellDescription_424A30(ind int) (string, bool) {
	sp := noxServer.Spells.DefByInd(spell.ID(ind))
	if sp == nil {
		return "", false
	}
	return sp.Desc, true
}

func nox_xxx_spellIcon_424A90(ind int) unsafe.Pointer {
	sp := noxServer.Spells.DefByInd(spell.ID(ind))
	if sp == nil {
		return nil
	}
	return unsafe.Pointer(((*noxrender.Image)(sp.Icon)).C())
}

func nox_xxx_spellIconHighlight_424AB0(ind int) unsafe.Pointer {
	sp := noxServer.Spells.DefByInd(spell.ID(ind))
	if sp == nil {
		return nil
	}
	return unsafe.Pointer(((*noxrender.Image)(sp.IconEnabled)).C())
}

func nox_xxx_allocSpellRelatedArrays_4FC9B0() error {
	s := noxServer
	Nox_alloc_magicEnt_1569668 = alloc.NewClassT("magicEntityClass", server.MagicEntityClass{}, 64)
	nox_xxx_imagCasterUnit_1569664 = s.NewObjectByTypeID("ImaginaryCaster")
	if nox_xxx_imagCasterUnit_1569664 == nil {
		return errors.New("cannot find ImaginaryCaster object type")
	}
	s.CreateObjectAt(nox_xxx_imagCasterUnit_1569664, nil, s.Map.Center())
	noxPixieObjID = s.Types.PixieID()
	*memmap.PtrUint32(0x5D4594, 1569676) = uint32(noxPixieObjID)
	*memmap.PtrUint32(0x5D4594, 1569680) = uint32(s.Types.IndByID("MagicMissile"))
	*memmap.PtrUint32(0x5D4594, 1569684) = uint32(s.Types.IndByID("SmallFist"))
	*memmap.PtrUint32(0x5D4594, 1569688) = uint32(s.Types.IndByID("MediumFist"))
	*memmap.PtrUint32(0x5D4594, 1569692) = uint32(s.Types.IndByID("LargeFist"))
	*memmap.PtrUint32(0x5D4594, 1569696) = uint32(s.Types.IndByID("DeathBall"))
	*memmap.PtrUint32(0x5D4594, 1569700) = uint32(s.Types.IndByID("Meteor"))
	return nil
}

func nox_xxx_freeSpellRelated_4FCA80() {
	Nox_alloc_magicEnt_1569668.Free()
	Dword_5d4594_1569672 = nil
	asObjectS(nox_xxx_imagCasterUnit_1569664).Delete()
	nox_xxx_imagCasterUnit_1569664 = nil
}

func sub_49BB80(a1 spell.ID) {
	s := noxServer
	*memmap.PtrUint8(0x5D4594, 1303504) = byte(a1)
	*memmap.PtrUint8(0x5D4594, 1303512) = 0
	*memmap.PtrUint32(0x5D4594, 1303516) = s.Frame()
	dword_5d4594_1303508 = s.Spells.PhonemeTree()
}

func sub_49BBB0() {
	*memmap.PtrUint8(0x5D4594, 1303504) = 0
}

func nox_client_setPhonemeFrame_476E00(a1 int32) {
	s := noxServer
	*memmap.PtrUint32(0x5D4594, uintptr(a1)*4+1096596) = s.Frame()
}

func sub_49BBC0() {
	s := noxServer
	sp := spell.ID(memmap.Uint8(0x5D4594, 1303504))
	if sp == 0 {
		return
	}
	ph := s.Spells.Phoneme(sp, int(memmap.Uint8(0x5D4594, 1303512)))
	if s.Frame() >= uint32(*memmap.PtrInt32(0x5D4594, 1303516)) {
		snd := nox_xxx_spellGetPhoneme_4FE1C0(legacy.ClientPlayerNetCode(), ph)
		legacy.Nox_xxx_clientPlaySoundSpecial_452D80(snd, 100)
		nox_client_setPhonemeFrame_476E00(int32(*memmap.PtrUint32(0x587000, uintptr(ph)*4+163576)))
		*memmap.PtrUint32(0x5D4594, 1303516) = s.Frame() + 3
		dword_5d4594_1303508 = dword_5d4594_1303508.Next(ph)
		*memmap.PtrUint8(0x5D4594, 1303512)++
	}
	if dword_5d4594_1303508.Ind == sp {
		sub_49BBB0()
	}
}

func nox_xxx_Fn_4FCAC0(a1 bool, a2 int32) int32 {
	s := noxServer
	s.Spells.Dur.Sub4FE8A0(a1)
	Nox_alloc_magicEnt_1569668.FreeAllObjects()
	Dword_5d4594_1569672 = nil
	for u := s.Players.FirstUnit(); u != nil; u = s.Players.NextUnit(u) {
		ud := u.UpdateDataPlayer()
		ud.Field47_0 = 0
		ud.SpellCastStart = 0
		for i := range ud.TrapSpells {
			ud.TrapSpells[i] = 0
		}
		ud.TrapSpellsCnt = 0
	}
	if a2 == 0 {
		return 1
	}
	if s.nox_setImaginaryCaster() == 0 {
		return 0
	}
	return 1
}

func nox_xxx_spellCastByBook_4FCB80() {
	s := noxServer
	for it := Dword_5d4594_1569672; it != nil; {
		u := it.Obj4
		if u.Flags().HasAny(object.FlagDead | object.FlagDestroyed) {
			if next := it.Next52; next != nil {
				next.Prev56 = it.Prev56
			}
			if prev := it.Prev56; prev == nil {
				Dword_5d4594_1569672 = it.Next52
			} else {
				prev.Next52 = it.Next52
			}
			next := it.Next52
			Nox_alloc_magicEnt_1569668.FreeObjectFirst(it)
			it = next
			continue
		}
		if s.Frame() < it.Frame40 {
			it = it.Next52
			continue
		}
		var ud *server.PlayerUpdateData
		if u.Class().Has(object.ClassPlayer) {
			ud = u.UpdateDataPlayer()
		}
		if int32(it.Field36) == 0 {
			var buf [2]byte
			buf[0] = byte(noxnet.MSG_REPORT_SPELL_START)
			buf[1] = byte(it.Spells8[it.SpellInd28])
			s.NetList.AddToMsgListCli(ud.Player.PlayerIndex(), 1, buf[:2])
		}
		spi := it.Field32.Ind
		sp := it.Spells8[it.SpellInd28]
		if spi != sp {
			sett := getServerSettings()
			ph := s.Spells.Phoneme(it.Spells8[it.SpellInd28], int(it.Field36))
			if legacy.Get_dword_5d4594_2650652() == 0 || *(*uint32)(unsafe.Pointer(&sett.BroadcastGestures62)) != 0 {
				sub_4FC960(it.Obj4, ph)
			}
			it.Field32 = it.Field32.Next(ph)
			if it.Obj4.Class().Has(object.ClassPlayer) {
				ud.SpellPhonemeLeaf = it.Field32
			}
			it.Field36++
			it.Frame40 = s.Frame() + it.Field44
			it = it.Next52
			continue
		}
		sp1 := it.Spells8[it.SpellInd28+1]
		if it.Field29 == 0 {
			if sp != spell.SPELL_GLYPH && sp1 != 0 {
				it.Field36 = 0
				it.Field32 = s.Spells.PhonemeTree()
				it.Frame40 = s.Frame() + it.Field44
				it.SpellInd28++
				it = it.Next52
				continue
			}
		} else if sp != spell.SPELL_GLYPH {
			if it.Obj4.Class().Has(object.ClassPlayer) {
				check := true
				if ud.TrapSpellsCnt != 0 {
					for i := 0; i < int(ud.TrapSpellsCnt); i++ {
						if ud.TrapSpells[i] == sp {
							s.NetInformTextMsg0(ud.Player.PlayerIndex(), server.SpellDuplicateInGlyph)
							check = false
						}
					}
				}
				if check {
					if sub_4FCF90(it.Obj4, sp, server.SpellCostTrap) < 0 {
						s.NetInformTextMsg0(ud.Player.PlayerIndex(), server.SpellNotEnoughMana)
						s.Audio.EventObj(sound.SoundManaEmpty, it.Obj4, 0, 0)
					} else {
						ud.TrapSpells[ud.TrapSpellsCnt] = sp
						ud.TrapSpellsCnt++
					}
				}
			}
			if sp != spell.SPELL_GLYPH && sp1 != 0 {
				it.Field36 = 0
				it.Field32 = s.Spells.PhonemeTree()
				it.Frame40 = s.Frame() + it.Field44
				it.SpellInd28++
				it = it.Next52
				continue
			}
		}
		if u.Class().Has(object.ClassPlayer) {
			pl := ud.Player
			ud.Field55 = pl.CursorVec.X
			ud.Field56 = pl.CursorVec.Y
			if it.Field48 != 0 {
				pl.Obj3640 = it.Obj4
			} else {
				pl.Obj3640 = ud.CursorObj
			}
			s.PlayerSpell(it.Obj4)
			ud.SpellCastStart = 0
			ud.Field47_0 = 0
			ud.TrapSpellsCnt = 0
		} else {
			s.nox_xxx_castSpellByUser4FDD20(sp, -1, u, nil)
		}
		if next := it.Next52; next != nil {
			next.Prev56 = it.Prev56
		}
		if prev := it.Prev56; prev == nil {
			Dword_5d4594_1569672 = it.Next52
		} else {
			prev.Next52 = it.Next52
		}
		next := it.Next52
		Nox_alloc_magicEnt_1569668.FreeObjectFirst(it)
		it = next
	}
}

func sub_4FC960(obj *server.Object, ph spell.Phoneme) {
	s := noxServer
	for it := s.Players.FirstUnit(); it != nil; it = s.Players.NextUnit(it) {
		if it != obj {
			snd := nox_xxx_spellGetPhoneme_4FE1C0(int(obj.NetCode), ph)
			s.Audio.EventObj(snd, obj, 2, it.NetCode)
		}
	}
}

func nox_xxx_spellGetPhoneme_4FE1C0(id int, ph spell.Phoneme) sound.ID {
	s := noxServer
	c := noxClient
	if noxflags.HasGame(noxflags.GameHost) {
		if !s.getObjectFromNetCode(id).Class().Has(object.ClassPlayer) {
			switch ph {
			case spell.PhonKA:
				return sound.SoundSpellPhonemeUpLeft
			case spell.PhonUN:
				return sound.SoundSpellPhonemeUp
			case spell.PhonIN:
				return sound.SoundSpellPhonemeUpRight
			case spell.PhonET:
				return sound.SoundSpellPhonemeLeft
			case spell.PhonCHA:
				return sound.SoundSpellPhonemeRight
			case spell.PhonRO:
				return sound.SoundSpellPhonemeDownLeft
			case spell.PhonZO:
				return sound.SoundSpellPhonemeDown
			case spell.PhonDO:
				return sound.SoundSpellPhonemeDownRight
			default:
				return 0
			}
		}
	} else {
		if !c.Objs.ByNetCodeDynamic(id).Class().Has(object.ClassPlayer) {
			switch ph {
			case spell.PhonKA:
				return sound.SoundSpellPhonemeUpLeft
			case spell.PhonUN:
				return sound.SoundSpellPhonemeUp
			case spell.PhonIN:
				return sound.SoundSpellPhonemeUpRight
			case spell.PhonET:
				return sound.SoundSpellPhonemeLeft
			case spell.PhonCHA:
				return sound.SoundSpellPhonemeRight
			case spell.PhonRO:
				return sound.SoundSpellPhonemeDownLeft
			case spell.PhonZO:
				return sound.SoundSpellPhonemeDown
			case spell.PhonDO:
				return sound.SoundSpellPhonemeDownRight
			default:
				return 0
			}
		}
	}
	pl := s.Players.ByID(id)
	if pl == nil {
		return 0
	}

	if !pl.Info().IsFemale() {
		switch ph {
		case spell.PhonKA:
			return sound.SoundSpellPhonemeUpLeft
		case spell.PhonUN:
			return sound.SoundSpellPhonemeUp
		case spell.PhonIN:
			return sound.SoundSpellPhonemeUpRight
		case spell.PhonET:
			return sound.SoundSpellPhonemeLeft
		case spell.PhonCHA:
			return sound.SoundSpellPhonemeRight
		case spell.PhonRO:
			return sound.SoundSpellPhonemeDownLeft
		case spell.PhonZO:
			return sound.SoundSpellPhonemeDown
		case spell.PhonDO:
			return sound.SoundSpellPhonemeDownRight
		default:
			return 0
		}
	}
	switch ph {
	case spell.PhonKA:
		return sound.SoundFemaleSpellPhonemeUpLeft
	case spell.PhonUN:
		return sound.SoundFemaleSpellPhonemeUp
	case spell.PhonIN:
		return sound.SoundFemaleSpellPhonemeUpRight
	case spell.PhonET:
		return sound.SoundFemaleSpellPhonemeLeft
	case spell.PhonCHA:
		return sound.SoundFemaleSpellPhonemeRight
	case spell.PhonRO:
		return sound.SoundFemaleSpellPhonemeDownLeft
	case spell.PhonZO:
		return sound.SoundFemaleSpellPhonemeDown
	case spell.PhonDO:
		return sound.SoundFemaleSpellPhonemeDownRight
	default:
		return 0
	}
}

func nox_xxx_spell_4FE680(a1 *server.Object, a2 float32) {
	s := noxServer
	v3 := a1
	for it := Dword_5d4594_1569672; it != nil; {
		v4 := it.Obj4
		if (!v4.Class().Has(object.ClassPlayer) || !v3.TeamPtr().SameAs(v4.TeamPtr())) && (func() bool {
			v5 := it.Obj4
			v6 := float64(v5.PosVec.X - v3.PosVec.X)
			v7 := float64(v5.PosVec.Y - v3.PosVec.Y)
			return math.Sqrt(v7*v7+v6*v6)+0.1 < float64(a2)
		}()) && s.MapTraceVision(v3, it.Obj4) {
			v8 := it.Obj4
			if v8.Class().Has(object.ClassPlayer) {
				v9 := v8.UpdateDataPlayer()
				v9.SpellCastStart = 0
				v9.Field47_0 = 0
				s.NetInformTextMsg0(v9.Player.PlayerIndex(), server.SpellCancelledByWarCry)
				s.Audio.EventObj(231, it.Obj4, 0, 0)
				nox_xxx_playerSetState_4FA020(it.Obj4, 13)
			}
			v10 := it.Next52
			if v10 != nil {
				v10.Prev56 = it.Prev56
			}
			v11 := it.Prev56
			if v11 != nil {
				v11.Next52 = it.Next52
			} else {
				Dword_5d4594_1569672 = it.Next52
			}
			v12 := it.Next52
			Nox_alloc_magicEnt_1569668.FreeObjectFirst(it)
			it = v12
		} else {
			it = it.Next52
		}
		if it == nil {
			break
		}
	}
}

func nox_xxx_spellByBookInsert_4FE340(u *server.Object, spells []spell.ID, a4 int32, a5 int32) int {
	s := noxServer
	if u.ObjFlags&0x8022 != 0 {
		return 0
	}
	for _, sp := range spells {
		if sp < 0 || sp >= 137 {
			return 0
		}
	}
	if !u.Class().Has(object.ClassPlayer) {
		return 0
	}
	ud := u.UpdateDataPlayer()
	if ud.Trade70 != nil {
		return 0
	}
	for _, sp := range spells {
		if sp != 0 && ud.Player.SpellLvl[sp] == 0 {
			return 0
		}
	}
	if ud.SpellCastStart != 0 {
		return 0
	}
	hasGlyph := false
	for i := range spells {
		if spells[i] == spell.SPELL_GLYPH {
			hasGlyph = true
		}
	}
	if hasGlyph {
		if !s.nox_xxx_spellCheckSmth_4FCEF0(u, spells) {
			s.NetInformTextMsg0(ud.Player.PlayerIndex(), server.SpellNotEnoughManaGlyph)
			s.Audio.EventObj(232, u, 0, 0)
			return 0
		}
		if ud.Player.PlayerClass() == player.Conjurer {
			if !nox_xxx_checkSummonedCreaturesLimit_500D70(u, 5) {
				s.NetInformTextMsg0(ud.Player.PlayerIndex(), server.SpellCreatureControlFailed)
				s.Audio.EventObj(231, u, 0, 0)
				return 0
			}
			cnt := u.CountSlaves(object.ClassMonster, object.SubClass(object.MonsterBomber))
			if cnt >= int(s.Balance.Float("MaxBomberCount")) {
				s.NetInformTextMsg0(ud.Player.PlayerIndex(), server.SpellTooManyGlyphs)
				s.Audio.EventObj(231, u, 0, 0)
				return 0
			}
		} else {
			if int(ud.CurTraps) >= int(s.Balance.Float("MaxTrapCount")) {
				s.NetInformTextMsg0(ud.Player.PlayerIndex(), server.SpellTooManyGlyphs)
				s.Audio.EventObj(231, u, 0, 0)
				return 0
			}
		}
		for i := range spells {
			res := s.Spells.Sub_4FD0E0(u, spells[i])
			if res != server.SpellOK {
				s.NetInformTextMsg0(ud.Player.PlayerIndex(), res)
				s.Audio.EventObj(231, u, 0, 0)
				return 0
			}
			res = nox_xxx_checkPlrCantCastSpell_4FD150(u, spells[i], hasGlyph)
			if res != server.SpellOK {
				s.NetInformTextMsg0(ud.Player.PlayerIndex(), res)
				s.Audio.EventObj(231, u, 0, 0)
				return 0
			}
		}
	} else {
		res := s.Spells.Sub_4FD0E0(u, spells[0])
		if res != server.SpellOK {
			s.NetInformTextMsg0(ud.Player.PlayerIndex(), res)
			s.Audio.EventObj(231, u, 0, 0)
			return 0
		}
		res = nox_xxx_checkPlrCantCastSpell_4FD150(u, spells[0], false)
		if res != server.SpellOK {
			s.NetInformTextMsg0(ud.Player.PlayerIndex(), res)
			s.Audio.EventObj(231, u, 0, 0)
			return 0
		}
	}
	nox_xxx_playerSetState_4FA020(u, 2)
	ud.Field47_0 = 1
	ud.SpellCastStart = s.Frame()
	e := Nox_alloc_magicEnt_1569668.NewObject()
	if e == nil {
		return 0
	}
	e.Obj4 = u
	e.Field48 = uint32(a5)
	e.Field36 = 0
	e.Frame40 = s.Frame()
	e.Field44 = uint32(a4)
	e.Field32 = s.Spells.PhonemeTree()
	e.SpellInd28 = 0
	e.Field29 = 0

	for i := range e.Spells8 {
		if i >= len(spells) {
			e.Spells8[i] = 0
		} else {
			e.Spells8[i] = spells[i]
			if spells[i] == spell.SPELL_GLYPH {
				e.Field29 = 1
			}
		}
	}
	e.Prev56 = nil
	e.Next52 = Dword_5d4594_1569672
	if Dword_5d4594_1569672 != nil {
		Dword_5d4594_1569672.Prev56 = e
	}
	Dword_5d4594_1569672 = e
	return 1
}

func (s *Server) nox_xxx_createSpellFly_4FDDA0(u *server.Object, targ *server.Object, sp spell.ID) {
	a2a := float32(float64(u.Shape.Circle.R) + 4.0)
	var v21 types.Pointf
	if targ == nil {
		if u.Class().Has(object.ClassPlayer) {
			ud := u.UpdateDataPlayer()
			v21.X = float32(ud.Player.CursorVec.X)
			v21.Y = float32(ud.Player.CursorVec.Y)
			targ = s.Nox_xxx_spellFlySearchTarget(&v21, u, s.Spells.Flags(sp), 600.0, 0, u)
		} else {
			targ = s.Nox_xxx_spellFlySearchTarget(nil, u, s.Spells.Flags(sp), 600.0, 0, u)
		}
	}
	cos, sin := server.SinCosDir(byte(int(u.Direction1) * 8))
	var v22b types.Pointf
	v22b.X = float32(float64(a2a*cos) + float64(u.PosVec.X) + float64(u.VelVec.X))
	v22b.Y = float32(float64(a2a*sin) + float64(u.PosVec.Y) + float64(u.VelVec.Y))
	if !s.MapTraceRayAt(u.PosVec, v22b, nil, nil, 5) {
		return
	}
	mis := s.NewObjectByTypeID("Magic")
	if mis == nil {
		return
	}
	mud := mis.UpdateDataSpellProjectile()
	s.CreateObjectAt(mis, u, v22b)
	mis.Direction1 = u.Direction1
	mis.Direction2 = u.Direction1
	mud.Field0 = u
	mud.Field4 = targ
	mud.Field8 = u
	mud.Spell12 = uint32(sp)
	mud.Level16 = uint32(nox_xxx_spellGetPower_4FE7B0(sp, u))
	//nox_xxx_xferIndexedDirection_509E20(int32(u.Direction1), &v21)
	cos, sin = server.SinCosDir(byte(int(mis.Direction1) * 8))
	mis.VelVec.X = u.VelVec.X + cos*mis.SpeedCur
	mis.VelVec.Y = u.VelVec.Y + sin*mis.SpeedCur
	if u.HasEnchant(server.ENCHANT_INFRAVISION) {
		elvl := u.EnchantPower(server.ENCHANT_INFRAVISION)
		dur := u.EnchantDur(server.ENCHANT_INFRAVISION)
		asObjectS(mis).ApplyEnchant(server.ENCHANT_INFRAVISION, dur, elvl)
	}
	snd := s.Spells.DefByInd(sp).GetCastSound()
	s.Audio.EventObj(snd, u, 0, 0)
}

func Nox_xxx_playerDoSchedSpell_4FB0E0(u *server.Object, targ *server.Object) int32 {
	s := noxServer
	ud := u.UpdateDataPlayer()
	if ud.TrapSpellsCnt == 0 {
		return 0
	}
	res := nox_xxx_checkPlrCantCastSpell_4FD150(u, ud.TrapSpells[0], false)
	var sa server.SpellAcceptArg
	sa.Obj = targ
	sa.Pos.X = float32(float64(ud.Field55))
	sa.Pos.Y = float32(float64(ud.Field56))
	if res != server.SpellOK {
		s.NetInformTextMsg0(ud.Player.PlayerIndex(), res)
		s.Audio.EventObj(sound.SoundPermanentFizzle, u, 0, 0)
	} else {
		s.nox_xxx_castSpellByUser4FDD20(ud.TrapSpells[0], -1, u, &sa)
	}
	copy(ud.TrapSpells[:], ud.TrapSpells[1:ud.TrapSpellsCnt])
	ud.TrapSpells[ud.TrapSpellsCnt-1] = 0
	ud.TrapSpellsCnt--
	return 1
}

func Nox_xxx_playerDoSchedSpellQueue_4FB1D0(u *server.Object, targ *server.Object) int32 {
	s := noxServer
	ud := u.UpdateDataPlayer()
	if ud.TrapSpellsCnt == 0 {
		return 0
	}
	res := nox_xxx_checkPlrCantCastSpell_4FD150(u, ud.TrapSpells[ud.TrapSpellsCnt-1], false)
	var sa server.SpellAcceptArg
	sa.Obj = targ
	sa.Pos.X = float32(float64(ud.Field55))
	sa.Pos.Y = float32(float64(ud.Field56))
	if res != server.SpellOK {
		s.NetInformTextMsg0(ud.Player.PlayerIndex(), res)
		s.Audio.EventObj(sound.SoundPermanentFizzle, u, 0, 0)
	} else {
		s.nox_xxx_castSpellByUser4FDD20(ud.TrapSpells[ud.TrapSpellsCnt-1], -1, u, &sa)
	}
	ud.TrapSpellsCnt--
	return 1
}

func nox_xxx_checkPlrCantCastSpell_4FD150(u *server.Object, sp spell.ID, hasGlyph bool) server.SpellResult {
	s := noxServer
	if !hasGlyph {
		if noxflags.HasGame(noxflags.GameModeKOTR) {
			if s.Spells.HasFlags(sp, things.SpellCantHoldCrown) {
				for it := u.Field129; it != nil; it = it.Field128 {
					if int(it.TypeInd) == s.Types.CrownID() {
						if u.TeamPtr().Has() {
							return server.SpellRestrictedByCrown
						}
						break
					}
				}
			}
		} else if noxflags.HasGame(noxflags.GameModeFlagBall) {
			if s.Spells.HasFlags(sp, things.SpellCantHoldCrown) {
				for it := u.Field129; it != nil; it = it.Field128 {
					if int(it.TypeInd) == s.Types.GameBallID() {
						return server.SpellRestrictedByBall
					}
				}
			}
		} else if noxflags.HasGame(noxflags.GameModeCTF) {
			if s.Spells.HasFlags(sp, things.SpellCantHoldCrown) {
				for it := u.InvFirstItem; it != nil; it = it.InvNextItem {
					if it.Class().Has(object.ClassFlag) {
						return server.SpellRestrictedByFlag
					}
				}
			}
		}
	}
	if u.HasEnchant(server.ENCHANT_ANTI_MAGIC) {
		return server.SpellNotStartedWarCry
	}
	if !server.CanUseSummonSpell(sp) {
		return server.SpellIllegal
	}
	switch sp {
	case spell.SPELL_FIST:
		if u.CountSubOfType(s.Types.IndByID("LargeFist"), s.Types.IndByID("MediumFist"), s.Types.IndByID("SmallFist")) > 0 {
			return server.SpellTooMany
		}
	case spell.SPELL_FORCE_OF_NATURE:
		if u.CountSubOfType(s.Types.DeathBallID()) > 0 {
			return server.SpellTooMany
		}
	case spell.SPELL_MAGIC_MISSILE:
		if code := s.spells.missiles.CanCast(sp, u); code != server.SpellOK {
			return code
		}
	case spell.SPELL_METEOR:
		if u.CountSubOfType(s.Types.IndByID("Meteor")) > 0 {
			return server.SpellTooMany
		}
	case spell.SPELL_PIXIE_SWARM:
		cnt := u.CountSubOfType(s.Types.PixieID())
		lvl := nox_xxx_spellGetPower_4FE7B0(sp, u)
		if cnt >= int(s.Balance.FloatInd("PixieCount", lvl-1)) {
			return server.SpellTooMany
		}
	}
	return server.SpellOK
}

func nox_xxx_spellGetPower_4FE7B0(sp spell.ID, u *server.Object) int {
	s := noxServer
	if u == nil {
		return 2
	}
	if int(u.TypeInd) == s.Types.IndByID("ImaginaryCaster") {
		return 1
	}
	if noxflags.HasGame(0x570) {
		return 3
	}
	if u.Class().Has(object.ClassPlayer) {
		return int(u.UpdateDataPlayer().Player.SpellLvl[sp])
	}
	if u.Class().Has(object.ClassMonster) {
		return int(u.UpdateDataMonster().SpellLvl510)
	}
	return 3
}

func (s *Server) nox_xxx_spellCheckSmth_4FCEF0(u *server.Object, spells []spell.ID) bool {
	if u == nil {
		return false
	}
	if len(spells) == 0 {
		return true
	}
	if u.Class().Has(object.ClassMonster) {
		return true
	}
	if noxflags.HasEngine(noxflags.EngineGodMode) {
		return true
	}
	mana := u.OldMana()
	for _, sp := range spells {
		var cost int
		if !server.SpellIsSummon(sp) {
			cost = s.Spells.ManaCost(sp, server.SpellCostTrap)
		} else {
			cost = sub_500CA0(sp, u)
		}
		if cost > mana {
			return false
		}
		mana -= cost
	}
	return true
}

func sub_4FCF90(u *server.Object, sp spell.ID, typ server.SpellCostType) int {
	s := noxServer
	if !u.Class().Has(object.ClassPlayer) {
		return -1
	}
	if sp == 0 {
		return -1
	}
	if noxflags.HasEngine(noxflags.EngineGodMode) {
		return 0
	}
	var cost int
	if !server.SpellIsSummon(sp) {
		cost = s.Spells.ManaCost(sp, typ)
	} else {
		cost = sub_500CA0(sp, u)
	}
	ud := u.UpdateDataPlayer()
	if int(ud.ManaCur) < cost {
		ud.Field20_0 = uint16(s.Spells.ManaCost(sp, server.SpellCostRegular))
		ud.Field20_1 = uint16(s.TickRate())
		return -1
	}
	legacy.Nox_xxx_playerManaSub_4EEBF0(u, cost)
	return cost
}

func sub_500CA0(sp spell.ID, u *server.Object) int {
	if u != nil && u.Class().Has(object.ClassPlayer) {
		return int(memmap.Uint32(0x587000, uintptr(sp)*4+217668))
	} else {
		return 0
	}
}

func serverSetAllBeastScrolls(p *Player, enable bool) {
	lvl := 0
	if enable {
		lvl = 1
	}
	legacy.Nox_xxx_playerResetProtectionCRC_56F7D0(p.Prot4640, 0)
	for i := 1; i < len(p.BeastScrollLvl); i++ {
		p.BeastScrollLvl[i] = uint32(lvl)
		legacy.Nox_xxx_playerAwardSpellProtectionCRC_56FCE0(p.Prot4640, i, lvl)
	}
	legacy.Nox_xxx_playerApplyProtectionCRC_56FD50(p.Prot4640, unsafe.Pointer(&p.BeastScrollLvl[0]), len(p.BeastScrollLvl))
}

func serverSetAllSpells(p *Player, enable bool, max int) {
	lvl := 0
	if enable {
		lvl = max
		if max <= 0 {
			lvl = 3
		}
	}
	legacy.Nox_xxx_playerResetProtectionCRC_56F7D0(p.Prot4636, 0)
	// set max level for all possible spells
	// the engine will automatically allow only ones that have WIS_USE, CON_USE or COMMON_USE set
	for i := 1; i < len(p.SpellLvl); i++ {
		p.SpellLvl[i] = uint32(lvl)
		legacy.Nox_xxx_playerAwardSpellProtectionCRC_56FCE0(p.Prot4636, i, lvl)
	}
	if !enable && noxflags.HasGame(noxflags.GameModeQuest) {
		u := p.PlayerUnit
		// grant default spells for Quest when disabling the cheat
		switch p.PlayerClass() {
		case player.Wizard:
			legacy.Nox_xxx_spellGrantToPlayer_4FB550(u, spell.SPELL_FIREBALL, 1, 1, 1)
		case player.Conjurer:
			legacy.Nox_xxx_spellGrantToPlayer_4FB550(u, spell.SPELL_CHARM, 1, 1, 1)
			legacy.Nox_xxx_spellGrantToPlayer_4FB550(u, spell.SPELL_LESSER_HEAL, 1, 1, 1)
		}
	}
	legacy.Nox_xxx_playerApplyProtectionCRC_56FD50(p.Prot4636, unsafe.Pointer(&p.SpellLvl[0]), len(p.SpellLvl))
}

func serverSetSpell(p *Player, sp spell.ID, lvl int) {
	if sp == spell.SPELL_INVALID {
		return
	}
	legacy.Nox_xxx_playerResetProtectionCRC_56F7D0(p.Prot4636, 0)
	for i := 1; i < len(p.SpellLvl); i++ {
		cur := int(p.SpellLvl[i])
		if sp == spell.ID(i) {
			p.SpellLvl[i] = uint32(lvl)
			cur = lvl
		}
		legacy.Nox_xxx_playerAwardSpellProtectionCRC_56FCE0(p.Prot4636, i, cur)
	}
	legacy.Nox_xxx_playerApplyProtectionCRC_56FD50(p.Prot4636, unsafe.Pointer(&p.SpellLvl[0]), len(p.SpellLvl))
}

func serverSetAllWarriorAbilities(p *Player, enable bool, max int) {
	if p.PlayerClass() != player.Warrior {
		return
	}
	lvl := 0
	if enable {
		lvl = max
		if max <= 0 {
			lvl = 5
		}
	}
	for i := 1; i < 6; i++ {
		p.SpellLvl[i] = uint32(lvl)
		legacy.Nox_xxx_playerAwardSpellProtectionCRC_56FCE0(p.Prot4636, i, lvl)
	}
}

func nox_xxx_spellBookReact_4FCB70() {
	nox_xxx_spellCastByBook_4FCB80()
	noxServer.spells.duration.spellCastByPlayer()
}

func (s *Server) Nox_xxx_spellAccept4FD400(spellID spell.ID, a2, obj3, obj4 *server.Object, sa *server.SpellAcceptArg, lvl int) bool {
	if spellID == 0 {
		return false
	}
	if obj3 == nil {
		return false
	}
	if a2 == nil {
		return false
	}
	if sa == nil {
		return false
	}
	obj5 := asObjectS(sa.Obj)
	sp := s.Spells.DefByInd(spellID)
	if sp == nil {
		gameLog.Printf("attempted to cast unsupported spell: %v", spellID)
		return false
	}
	if s.Spells.HasFlags(spellID, things.SpellFlagUnk8) && obj5 != nil && !obj5.Class().HasAny(object.MaskUnits) {
		return false
	}
	if !(obj5 == nil || legacy.Nox_xxx_gameCaptureMagic_4FDC10(spellID, obj5.SObj()) != 0) {
		s.Audio.EventObj(sound.SoundPermanentFizzle, obj5, 0, 0)
		return false
	}
	var fnc func(spellID spell.ID, a2, a3, a4 *server.Object, a5 *server.SpellAcceptArg, lvl int) int
	effectID := sp.Effect
	levelIsSafe := false
	switch effectID {
	case spell.SPELL_ANCHOR:
		fnc = castAnchor
	case spell.SPELL_ARACHNAPHOBIA:
		fnc = legacy.Nox_xxx_spellArachna_52DC80
	case spell.SPELL_BLIND:
		fnc = castBlind
	case spell.SPELL_BLINK:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_spellBlink2_530310(), legacy.Get_nox_xxx_spellBlink1_530380(), nil, 0)
	case spell.SPELL_BURN:
		fnc = legacy.Nox_xxx_castBurn_52C3E0
	case spell.SPELL_CHANNEL_LIFE:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, nil, legacy.Get_sub_52F460(), nil, 0)
	case spell.SPELL_CHARM:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_charmCreature1_5011F0(), legacy.Get_nox_xxx_charmCreatureFinish_5013E0(), legacy.Get_nox_xxx_charmCreature2_501690(), 0)
	case spell.SPELL_CLEANSING_FLAME, spell.SPELL_CLEANSING_MANA_FLAME:
		fnc = legacy.Nox_xxx_spellCastCleansingFlame_52D5C0
	case spell.SPELL_CONFUSE:
		fnc = legacy.Nox_xxx_castConfuse_52C1E0
	case spell.SPELL_COUNTERSPELL:
		fnc = nox_xxx_castCounterSpell_52BBB0
	case spell.SPELL_CURE_POISON:
		fnc = legacy.Nox_xxx_castCurePoison_52CDB0
	case spell.SPELL_DEATH:
		fnc = castDeath
	case spell.SPELL_DEATH_RAY:
		fnc = castDeathRay
	case spell.SPELL_DETECT_MAGIC:
		fnc = castDetectMagic
	case spell.SPELL_DETONATE_GLYPHS:
		fnc = castDetonateGlyphs
	case spell.SPELL_TURN_UNDEAD:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_spellTurnUndeadCreate_531310(), legacy.Get_nox_xxx_spellTurnUndeadUpdate_531410(), legacy.Get_nox_xxx_spellTurnUndeadDelete_531420(), 70)
	case spell.SPELL_DRAIN_MANA:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, nil, legacy.Get_nox_xxx_spellDrainMana_52E210(), nil, 0)
	case spell.SPELL_EARTHQUAKE:
		fnc = legacy.Nox_xxx_castEquake_52DE40
	case spell.SPELL_LIGHTNING:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_spellEnergyBoltStop_52E820(), legacy.Get_nox_xxx_spellEnergyBoltTick_52E850(), legacy.Get_nullsub_29(), 30)
	case spell.SPELL_FEAR:
		fnc = castFear
	case spell.SPELL_FIREBALL:
		fnc = legacy.Nox_xxx_castFireball_52C790
	case spell.SPELL_FIREWALK:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, nil, legacy.Get_nox_xxx_firewalkTick_52ED40(), nil, s.SecToFrames(3))
	case spell.SPELL_FIST:
		fnc = legacy.Nox_xxx_castFist_52D3C0
	case spell.SPELL_FORCE_OF_NATURE:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_sub_52EF30(), legacy.Get_sub_52EFD0(), legacy.Get_sub_52F1D0(), 2*s.TickRate()/3)
	case spell.SPELL_FREEZE:
		fnc = castFreeze
	case spell.SPELL_FUMBLE:
		fnc = legacy.Nox_xxx_castFumble_52C060
	case spell.SPELL_GLYPH:
		fnc = castGlyph
	case spell.SPELL_GREATER_HEAL:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_sub_52F220(), legacy.Get_sub_52F2E0(), nil, 0)
	case spell.SPELL_HASTE:
		fnc = castHaste
	case spell.SPELL_INFRAVISION:
		fnc = castInfravision
	case spell.SPELL_INVERSION:
		fnc = legacy.Sub_52BEB0
	case spell.SPELL_INVISIBILITY:
		fnc = castInvisibility
	case spell.SPELL_INVULNERABILITY:
		fnc = castInvulnerability
	case spell.SPELL_LESSER_HEAL:
		fnc = legacy.Sub_52DD50
	case spell.SPELL_LIGHT:
		fnc = castLight
	case spell.SPELL_CHAIN_LIGHTNING:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_onStartLightning_52F820(), legacy.Get_nox_xxx_onFrameLightning_52F8A0(), legacy.Get_sub_530100(), 30)
	case spell.SPELL_LOCK:
		fnc = legacy.Nox_xxx_castLock_52CE90
	case spell.SPELL_MARK:
		fnc = legacy.Sub_52CA80
	case spell.SPELL_MARK_1, spell.SPELL_MARK_2, spell.SPELL_MARK_3, spell.SPELL_MARK_4:
		fnc = legacy.Sub_52CBD0
	case spell.SPELL_MAGIC_MISSILE:
		fnc = s.spells.missiles.Cast
		levelIsSafe = true
	case spell.SPELL_SHIELD:
		return s.spells.duration.New(spellID, a2, obj5.SObj(), obj4, sa, lvl, legacy.Get_nox_xxx_castShield1_52F5A0(), legacy.Get_sub_52F650(), legacy.Get_sub_52F670(), 0)
	case spell.SPELL_METEOR:
		fnc = legacy.Nox_xxx_castMeteor_52D9D0
	case spell.SPELL_METEOR_SHOWER:
		fnc = legacy.Nox_xxx_castMeteorShower_52D8A0
	case spell.SPELL_MOONGLOW:
		return s.spells.duration.New(spellID, a2, obj5.SObj(), obj4, sa, lvl, legacy.Get_nox_xxx_spellCreateMoonglow_531A00(), nil, legacy.Get_sub_531AF0(), 0)
	case spell.SPELL_NULLIFY:
		fnc = castNullify
	case spell.SPELL_MANA_BOMB:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_manaBomb_530F90(), legacy.Get_nox_xxx_manaBombBoom_5310C0(), legacy.Get_sub_531290(), 0)
	case spell.SPELL_PIXIE_SWARM:
		fnc = legacy.Nox_xxx_castPixies_540440
	case spell.SPELL_PLASMA:
		v8 := s.Balance.Float("PlasmaSearchTime")
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_plasmaSmth_531580(), legacy.Get_nox_xxx_plasmaShot_531600(), legacy.Get_sub_5319E0(), uint32(v8))
	case spell.SPELL_POISON:
		fnc = legacy.Nox_xxx_castPoison_52C720
	case spell.SPELL_PROTECTION_FROM_ELECTRICITY:
		fnc = castProtectElectricity
	case spell.SPELL_PROTECTION_FROM_FIRE:
		fnc = castProtectFire
	case spell.SPELL_PROTECTION_FROM_POISON:
		fnc = castProtectPoison
	case spell.SPELL_PULL:
		fnc = legacy.Nox_xxx_castPull_52BFA0
	case spell.SPELL_PUSH:
		fnc = legacy.Nox_xxx_castPush_52C000
	case spell.SPELL_OVAL_SHIELD:
		return s.spells.duration.New(spellID, a2, obj5.SObj(), obj4, sa, lvl, legacy.Get_sub_531490(), legacy.Get_sub_5314F0(), legacy.Get_sub_531560(), 0)
	case spell.SPELL_RESTORE_HEALTH, spell.SPELL_WINK:
		fnc = legacy.Nox_xxx_castSpellWinkORrestoreHealth_52BF20
	case spell.SPELL_RESTORE_MANA:
		fnc = legacy.Sub_52BF50
	case spell.SPELL_RUN:
		fnc = castRun
	case spell.SPELL_SHOCK:
		fnc = legacy.Nox_xxx_useShock_52C5A0
	case spell.SPELL_SLOW:
		fnc = castSlow
	case spell.SPELL_STUN:
		fnc = legacy.Nox_xxx_castStun_52C2C0
	case spell.SPELL_SUMMON_BAT,
		spell.SPELL_SUMMON_BLACK_BEAR,
		spell.SPELL_SUMMON_BEAR,
		spell.SPELL_SUMMON_BEHOLDER,
		spell.SPELL_SUMMON_CARNIVOROUS_PLANT,
		spell.SPELL_SUMMON_ALBINO_SPIDER,
		spell.SPELL_SUMMON_SMALL_ALBINO_SPIDER,
		spell.SPELL_SUMMON_EVIL_CHERUB,
		spell.SPELL_SUMMON_EMBER_DEMON,
		spell.SPELL_SUMMON_GHOST,
		spell.SPELL_SUMMON_GIANT_LEECH,
		spell.SPELL_SUMMON_IMP,
		spell.SPELL_SUMMON_MECHANICAL_FLYER,
		spell.SPELL_SUMMON_MECHANICAL_GOLEM,
		spell.SPELL_SUMMON_MIMIC,
		spell.SPELL_SUMMON_OGRE,
		spell.SPELL_SUMMON_OGRE_BRUTE,
		spell.SPELL_SUMMON_OGRE_WARLORD,
		spell.SPELL_SUMMON_SCORPION,
		spell.SPELL_SUMMON_SHADE,
		spell.SPELL_SUMMON_SKELETON,
		spell.SPELL_SUMMON_SKELETON_LORD,
		spell.SPELL_SUMMON_SPIDER,
		spell.SPELL_SUMMON_SMALL_SPIDER,
		spell.SPELL_SUMMON_SPITTING_SPIDER,
		spell.SPELL_SUMMON_STONE_GOLEM,
		spell.SPELL_SUMMON_TROLL,
		spell.SPELL_SUMMON_URCHIN,
		spell.SPELL_SUMMON_WASP,
		spell.SPELL_SUMMON_WILLOWISP,
		spell.SPELL_SUMMON_WOLF,
		spell.SPELL_SUMMON_BLACK_WOLF,
		spell.SPELL_SUMMON_WHITE_WOLF,
		spell.SPELL_SUMMON_ZOMBIE,
		spell.SPELL_SUMMON_VILE_ZOMBIE,
		spell.SPELL_SUMMON_DEMON,
		spell.SPELL_SUMMON_LICH,
		spell.SPELL_SUMMON_DRYAD,
		spell.SPELL_SUMMON_URCHIN_SHAMAN:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_summonStart_500DA0(), legacy.Get_nox_xxx_summonFinish_5010D0(), legacy.Get_nox_xxx_summonCancel_5011C0(), 0)
	case spell.SPELL_SWAP:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_sub_530CA0(), legacy.Get_sub_530D30(), nil, 0)
	case spell.SPELL_TAG:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_spellTagCreature_530160(), legacy.Get_sub_530250(), legacy.Get_sub_530270(), 0)
	case spell.SPELL_TELEPORT_OTHER_TO_MARK_1, spell.SPELL_TELEPORT_OTHER_TO_MARK_2, spell.SPELL_TELEPORT_OTHER_TO_MARK_3, spell.SPELL_TELEPORT_OTHER_TO_MARK_4,
		spell.SPELL_TELEPORT_TO_MARK_1, spell.SPELL_TELEPORT_TO_MARK_2, spell.SPELL_TELEPORT_TO_MARK_3, spell.SPELL_TELEPORT_TO_MARK_4:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_sub_5305D0(), legacy.Get_sub_530650(), nil, 0)
	case spell.SPELL_TELEPORT_POP:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_castTele_530820(), legacy.Get_sub_530880(), nil, 0)
	case spell.SPELL_TELEPORT_TO_TARGET:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_sub_530A30_spell_execdur(), legacy.Get_nox_xxx_castTTT_530B70(), nil, 0)
	case spell.SPELL_TELEKINESIS:
		fnc = legacy.Nox_xxx_castTelekinesis_52D330
	case spell.SPELL_TOXIC_CLOUD:
		fnc = legacy.Nox_xxx_castToxicCloud_52DB60
	case spell.SPELL_TRIGGER_GLYPH:
		fnc = legacy.Sub_52CCD0
	case spell.SPELL_VAMPIRISM:
		fnc = castVampirism
	case spell.SPELL_VILLAIN:
		fnc = castVillain
	case spell.SPELL_WALL:
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, legacy.Get_nox_xxx_spellWallCreate_4FFA90(), legacy.Get_nox_xxx_spellWallUpdate_500070(), legacy.Get_nox_xxx_spellWallDestroy_500080(), 0)
	default:
		return true
	}
	// Legacy spells assume spell level 5 is max. Higher level may overflow internal arrays in the blob.
	// For example, Fireball will check which object name the missile must have at this level and will overflow.
	// TODO: remove this when we are ready
	if !levelIsSafe && lvl > 5 {
		lvl = 5
	}
	v9 := fnc(spellID, a2, obj3, obj4, sa, lvl)
	if v9 == 0 {
		s.Audio.EventObj(sound.SoundPermanentFizzle, obj4, 0, 0)
	}
	return v9 != 0
}

func (s *Server) castSpell(spellInd spell.ID, lvl int, u *server.Object, a3 *server.SpellAcceptArg) bool {
	if s.Spells.HasFlags(spellInd, things.SpellOffensive) {
		asObjectS(u).DisableEnchant(server.ENCHANT_INVISIBLE)
		asObjectS(u).DisableEnchant(server.ENCHANT_INVULNERABLE)
		s.Spells.Dur.CancelFor(spell.SPELL_OVAL_SHIELD, u)
	}
	if !s.Spells.HasFlags(spellInd, things.SpellTargeted) || u == a3.Obj {
		return s.Nox_xxx_spellAccept4FD400(spellInd, u, u, u, a3, lvl)
	}
	s.nox_xxx_createSpellFly_4FDDA0(u, a3.Obj, spellInd)
	return true
}

func (s *Server) castSpellBy(spellInd spell.ID, lvl int, caster *server.Object, targ server.Obj, targPos types.Pointf) bool {
	sa, freeArg := alloc.New(server.SpellAcceptArg{})
	defer freeArg()
	sa.Obj = server.ToObject(targ)
	sa.Pos = targPos
	return s.nox_xxx_castSpellByUser4FDD20(spellInd, lvl, caster, sa)
}

func (s *Server) nox_xxx_castSpellByUser4FDD20(spellInd spell.ID, lvl int, u *server.Object, sa *server.SpellAcceptArg) bool {
	if lvl < 0 {
		lvl = nox_xxx_spellGetPower_4FE7B0(spellInd, u)
	}
	return s.castSpell(spellInd, lvl, u, sa)
}
