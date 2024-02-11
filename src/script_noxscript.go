package opennox

import (
	"image/color"
	"os"
	"unsafe"

	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
	"github.com/noxworld-dev/opennox/v1/server/noxscript"
)

func (s *Server) scriptsReset() {
	s.VMsShutdown()
	s.ClearScriptTriggers()
	if legacy.Get_dword_5d4594_2386836() == 0 {
		legacy.Set_dword_5d4594_2386836(s.Types.IndByID("Mover"))
	}
	s.noxScript.Reset()
	s.Activators.CancelAll()
	*memmap.PtrUint32(0x5D4594, 2386844) = 0
	legacy.Set_dword_5d4594_2386848(0)
	legacy.Set_dword_5d4594_2386852(0)
}

func (s *noxScript) Reset() {
	s.NoxScriptVM.Reset()
	legacy.Set_dword_5d4594_1599628(0)
}

var (
	nox_script_objTelekinesisHand  int
	nox_script_objCinemaRemove     []int
	nox_xxx_imagCasterUnit_1569664 *server.Object
)

var _ noxscript.VM = (*noxScript)(nil)

type noxScript struct {
	s *Server
	*server.NoxScriptVM
}

func (s *noxScript) Init(srv *Server) {
	s.s = srv
	s.NoxScriptVM = &srv.Server.NoxScriptVM
	s.NoxScriptVM.CallBuiltinNative = s.callBuiltinNative
}

func (s *noxScript) PopObject() *server.Object {
	return s.ScriptToObject(int(s.PopI32()))
}

func (s *noxScript) nox_xxx_scriptRunFirst_507290() {
	s.RunFirst(nox_xxx_gameIsSwitchToSolo_4DB240())
}

func (s *noxScript) ScriptToObject(val int) *server.Object {
	if val == -1 {
		obj := s.Caller()
		if obj == nil || obj.Flags().Has(object.FlagDestroyed) {
			return nil
		}
		return obj
	}
	if val == -2 {
		obj := s.Trigger()
		if obj == nil || obj.Flags().Has(object.FlagDestroyed) {
			return nil
		}
		return obj
	}
	if obj := legacy.Nox_xxx_script_511C50(val); obj != nil {
		return obj
	}

	for obj := s.s.Objs.List; obj != nil; obj = obj.Next() {
		if !obj.Flags().Has(object.FlagDestroyed) && obj.ScriptIDVal == val {
			legacy.Nox_xxx_scriptPrepareFoundUnit_511D70(obj)
			return obj
		}
		for sub := obj.FirstItem(); sub != nil; sub = sub.NextItem() {
			if !sub.Flags().Has(object.FlagDestroyed) && sub.ScriptIDVal == val {
				legacy.Nox_xxx_scriptPrepareFoundUnit_511D70(sub)
				return sub
			}
		}
	}
	for obj := s.s.Objs.Pending; obj != nil; obj = obj.Next() {
		if !obj.Flags().Has(object.FlagDestroyed) && obj.ScriptIDVal == val {
			legacy.Nox_xxx_scriptPrepareFoundUnit_511D70(obj)
			return obj
		}
	}
	return nil
}

func noxScriptEndGame(v int) {
	dword_587000_311372 = v
	dword_5d4594_2516476 |= 1 << v
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	sub_413960()
	sub_477530(false)
	nox_client_quit_4460C0()
}

func noxScriptStartupScreen(v int) {
	legacy.Nox_script_StartupScreen_516600_A()
	sub5165D0(v)
}

func sub5165D0(which int) {
	*memmap.PtrUint32(0x5D4594, 2386828) = uint32(which - 1)
	sub_413A00(1)
	noxClient.r.FadeInScreen(25, true, func() {
		legacy.Sub_516570()
	})
}

func (s *Server) CinemaPlayers(enable bool) {
	if nox_script_objTelekinesisHand == 0 {
		nox_script_objTelekinesisHand = s.Types.IndByID("TelekinesisHand")
	}
	const (
		perc       = 0.16
		fadeOutDur = 30
		fadeInDur  = 10
	)
	if !enable {
		if noxClient.r.FadeOutCinema(perc, fadeOutDur, color.Black) {
			sub_477530(false)
		}
		for it := s.Objs.First(); it != nil; it = it.Next() {
			if int(it.TypeInd) == nox_script_objTelekinesisHand {
				if f := it.Flags(); f.Has(object.FlagNoCollide) {
					it.ObjFlags = f &^ object.FlagNoCollide
				}
			}
		}
		return
	}
	inFade := noxClient.r.CheckFade(noxrender.FadeInCinemaKey)
	if noxClient.r.FadeInCinema(perc, fadeInDur, color.Black) {
		sub_477530(true)
	}
	if inFade {
		return
	}
	if len(nox_script_objCinemaRemove) == 0 {
		for _, name := range []string{
			"ToxicCloud", "SmallToxicCloud", "Meteor", "SmallFist", "MediumFist", "LargeFist", "Pixie",
		} {
			nox_script_objCinemaRemove = append(nox_script_objCinemaRemove, s.Types.IndByID(name))
		}
	}

	var next *server.Object
	for it := s.Objs.MissileList; it != nil; it = next {
		next = it.Next()
		if int(it.TypeInd) != int(memmap.Uint32(0x5D4594, 2386900)) {
			asObjectS(it).Delete()
		}
	}

	next = nil
	for it := s.Objs.First(); it != nil; it = next {
		next = it.Next()
		if it.Owner() != nil {
			for _, id := range nox_script_objCinemaRemove {
				if int(it.TypeInd) == id {
					asObjectS(it).Delete()
					break
				}
			}
		} else {
			if int(it.TypeInd) == nox_script_objTelekinesisHand {
				if f := it.Flags(); !f.Has(object.FlagNoCollide) {
					it.ObjFlags = f | object.FlagNoCollide
				}
			}
			s.Spells.Dur.CancelFor(spell.SPELL_WALL, it)
			s.Spells.Dur.CancelFor(spell.SPELL_MANA_BOMB, it)
			s.Spells.Dur.CancelFor(spell.SPELL_LIGHTNING, it)
			s.Spells.Dur.CancelFor(spell.SPELL_CHAIN_LIGHTNING, it)
			s.Spells.Dur.CancelFor(spell.SPELL_DRAIN_MANA, it)
			s.Spells.Dur.CancelFor(spell.SPELL_FORCE_OF_NATURE, it)
			s.Spells.Dur.CancelFor(spell.SPELL_GREATER_HEAL, it)
			s.Spells.Dur.CancelFor(spell.SPELL_CHANNEL_LIFE, it)
			s.Spells.Dur.CancelFor(spell.SPELL_CHARM, it)
			s.Spells.Dur.CancelFor(spell.SPELL_BLINK, it)
			s.Spells.Dur.CancelFor(spell.SPELL_SWAP, it)
			s.Spells.Dur.CancelFor(spell.SPELL_TURN_UNDEAD, it)
			s.Spells.Dur.CancelFor(spell.SPELL_PLASMA, it)
			s.Spells.Dur.CancelFor(spell.SPELL_SUMMON_BAT, it)
		}
	}
}

func (s *Server) nox_setImaginaryCaster() int {
	nox_xxx_imagCasterUnit_1569664 = s.NewObjectByTypeID("ImaginaryCaster")
	if nox_xxx_imagCasterUnit_1569664 == nil {
		return 0
	}
	s.CreateObjectAt(nox_xxx_imagCasterUnit_1569664, nil, types.Pointf{X: 128 * common.GridStep, Y: 128 * common.GridStep})
	return 1
}

func nox_script_readWriteZzz_541670(cpath, cpath2, cdst *byte) int {
	if cpath == nil {
		return 0
	}
	if cpath2 == nil {
		return 0
	}
	if cdst == nil {
		return 0
	}
	path, path2, dst := alloc.GoString(cpath), alloc.GoString(cpath2), alloc.GoString(cdst)
	f1, err := ifs.Open(path)
	if err != nil {
		return 0
	}
	defer f1.Close()

	f2, err := ifs.Open(path2)
	if err != nil {
		return 0
	}
	defer f2.Close()

	v6, _ := binfile.FileSize(f1)
	if v6 == 0 {
		ifs.Remove(dst)
		ifs.Rename(path2, dst)
		return 1
	}

	v7, _ := binfile.FileSize(f2)
	if v7 == 0 {
		ifs.Remove(dst)
		ifs.Rename(path, dst)
		return 1
	}

	df, err := ifs.OpenFile(dst, os.O_RDWR)
	if err != nil {
		return 0
	}
	defer df.Close()
	legacy.Nox_script_readWriteWww_5417C0(binfile.NewFile(f1), binfile.NewFile(f2), binfile.NewFile(df))
	return 1
}

func (s *noxScript) ActResolveObjs() {
	s.s.Activators.ResolveObjs(func(id int) *server.Object {
		return s.ScriptToObject(id)
	})
}

func (s *noxScript) NoxScript() ns4.Implementation {
	return s.s.NoxScript()
}

func (s *noxScript) PopWallGroupNS() ns4.WallGroupObj {
	g := s.PopGroup()
	if g == nil || s.s.MapGroups.MapGroupType(g) != server.MapGroupWalls {
		return nil
	}
	return nsWallGroup{s.s, g}
}

func (s *noxScript) PopObjectNS() ns4.Obj {
	obj := s.ScriptToObject(int(s.PopI32()))
	return s.s.noxScriptP().toObj(obj)
}

func (s *noxScript) PopObjGroupNS() ns4.ObjGroup {
	g := s.PopGroup()
	if g == nil || s.s.MapGroups.MapGroupType(g) != server.MapGroupObjects {
		return nil
	}
	return nsObjGroup{s.s, g}
}

func (s *noxScript) ScriptCallback(b *server.ScriptCallback, caller, trigger *server.Object, eventCode server.ScriptEventType) unsafe.Pointer {
	s.scriptCallByEvent(eventCode, caller, trigger)
	out := memmap.PtrUint32(0x5D4594, 1599076)
	out = s.ScriptCallbackRaw(b, caller, trigger, out)
	return unsafe.Pointer(out)
}
