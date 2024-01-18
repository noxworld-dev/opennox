package opennox

import (
	"fmt"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_4FC670(a1 int) {
	noxServer.abilities.curxxx = server.Ability(a1)
}

func nox_xxx_playerExecuteAbil_4FBB70(cu *server.Object, a2 int) {
	noxServer.abilities.Do(cu, server.Ability(a2))
}

func sub_4FC0B0(a1 *server.Object, a2 int) {
	noxServer.abilities.ResetAbility(a1, server.Ability(a2))
}

func nox_xxx_playerCancelAbils_4FC180(cu *server.Object) {
	noxServer.abilities.CancelAbilities(cu)
}

func sub_4FC300(cu *server.Object, a2 int) {
	noxServer.abilities.DisableAbility(cu, server.Ability(a2))
}

func nox_xxx_abilityGetName_0_425260(ca int) string {
	return noxServer.abilities.getName(server.Ability(ca))
}

func nox_xxx_abilityCooldown_4252D0(ca int) int {
	return noxServer.abilities.getDelay(server.Ability(ca))
}

func sub_4252F0(ca int) string {
	return noxServer.abilities.getDesc(server.Ability(ca))
}

func nox_xxx_spellGetAbilityIcon_425310(abil, icon int) noxrender.ImageHandle {
	return noxServer.abilities.getIcon(server.Ability(abil), icon).C()
}

func nox_xxx_bookFirstKnownAbil_425330() int {
	for i := server.AbilityInvalid + 1; i < server.AbilityMax; i++ {
		if noxServer.abilities.defs[i].field24 != 0 {
			return int(i)
		}
	}
	return 0
}

func nox_xxx_bookNextKnownAbil_425350(a1 int) int {
	for i := server.Ability(a1) + 1; i < server.AbilityMax; i++ {
		if noxServer.abilities.defs[i].field24 != 0 {
			return int(i)
		}
	}
	return 0
}

func sub_425450(a1 int) int {
	return noxServer.abilities.defs[a1].field36
}

func nox_xxx_netAbilRepotState_4D8100(a1 *server.Object, a2 server.Ability, a3 byte) {
	noxServer.abilities.netAbilReportState(a1, a2, a3)
}

type AbilityDef struct {
	name     string           // 0, 0
	desc     string           // 1, 4
	icon8    *noxrender.Image // 2, 8
	icon12   *noxrender.Image // 3, 12
	icon16   *noxrender.Image // 4, 16
	field20  uint32           // 5, 20
	field24  uint32           // 6, 24
	delay    int              // 7, 28
	duration int              // 8, 32
	field36  int              // 9, 36
	sound40  sound.ID         // 10, 40
	sound44  sound.ID         // 11, 44
	sound48  sound.ID         // 12, 48
}

type serverAbilities struct {
	s      *Server
	curxxx server.Ability
	byName map[string]server.Ability
	defs   [server.AbilityMax]AbilityDef

	harpoon abilityHarpoon
}

func (a *serverAbilities) Init(s *Server) {
	a.s = s
	a.byName = make(map[string]server.Ability)
	for i := server.AbilityInvalid + 1; i < server.AbilityMax; i++ {
		a.byName[server.AbilityNames[i]] = i
	}
	a.harpoon.Init(s)
}

func (a *serverAbilities) Free() {
	a.harpoon.Free()
}

func (a *serverAbilities) nox_xxx_abilityNameToN_424D80(name string) server.Ability {
	if len(a.byName) == 0 {
		panic("not initialized yet")
	}
	return a.byName[name]
}

func (a *serverAbilities) sub_4FC680() {
	if noxflags.HasGame(noxflags.GameModeCoop) && !noxflags.HasGame(noxflags.GameFlag20) && a.curxxx != 0 {
		if u := a.s.Players.First().PlayerUnit; u != nil {
			a.Do(u, a.curxxx)
			a.curxxx = 0
		}
	}
}

func (a *serverAbilities) Do(u *server.Object, abil server.Ability) {
	if u == nil {
		return
	}
	if !abil.Valid() {
		return
	}
	if u.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
		return
	}
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	ud := u.UpdateDataPlayer()
	pl := ud.Player
	if pl.PlayerClass() != player.Warrior {
		return
	}
	switch abil {
	case server.AbilityBerserk:
		if noxflags.HasGame(noxflags.GameModeCTF) {
			for it := u.FirstItem(); it != nil; it = it.NextItem() {
				if it.Class().Has(object.ClassFlag) {
					a.s.NetInformTextMsg(pl.PlayerIndex(), 2, 5)
					a.s.Audio.EventObj(sound.SoundPermanentFizzle, u, 0, 0)
					return
				}
			}
		}
		if a.s.Abils.IsActiveVal(u, server.AbilityWarcry) || a.s.Abils.IsActive(u, server.AbilityHarpoon) {
			a.s.NetInformTextMsg(pl.PlayerIndex(), 2, 2)
			a.s.Audio.EventObj(sound.SoundPermanentFizzle, u, 0, 0)
			return
		}
	case server.AbilityWarcry:
		if a.s.Abils.IsActive(u, server.AbilityBerserk) || a.s.Abils.IsActive(u, server.AbilityHarpoon) {
			a.s.NetInformTextMsg(pl.PlayerIndex(), 2, 2)
			a.s.Audio.EventObj(sound.SoundPermanentFizzle, u, 0, 0)
			return
		}
	case server.AbilityHarpoon:
		if a.s.Abils.IsActiveVal(u, server.AbilityWarcry) || a.s.Abils.IsActive(u, server.AbilityBerserk) {
			a.s.NetInformTextMsg(pl.PlayerIndex(), 2, 2)
			a.s.Audio.EventObj(sound.SoundPermanentFizzle, u, 0, 0)
			return
		}
	}
	if a.s.Abils.IsActive(u, abil) {
		a.s.NetInformTextMsg(pl.PlayerIndex(), 2, 2)
		a.s.Audio.EventObj(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	if ud.State == server.PlayerState12 || !noxflags.HasGame(noxflags.GameModeCoop) && u.Flags().Has(object.FlagAirborne) {
		a.s.NetInformTextMsg(pl.PlayerIndex(), 2, 6)
		a.s.Audio.EventObj(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	if (!noxflags.HasGame(noxflags.GameOnline) || noxflags.HasGame(noxflags.GameModeQuest)) && pl.SpellLvl[abil] == 0 {
		a.s.NetInformTextMsg(pl.PlayerIndex(), 2, 3)
		a.s.Audio.EventObj(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	if abil == server.AbilityBerserk && pl.Field3656 == 1 {
		a.s.NetInformTextMsg(pl.PlayerIndex(), 2, 7)
		return
	}
	ad := a.s.Abils.GetFor(u)
	cd := &ad.Cooldowns[abil]
	if *cd != 0 {
		a.s.NetInformTextMsg(pl.PlayerIndex(), 2, 2)
		a.s.Audio.EventObj(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	*cd = a.getDelay(abil)
	if a.getDelay(abil) != 0 {
		a.netAbilReportState(u, abil, 0)
	}
	if df := a.getDuration(abil); df > 0 {
		ab := &server.ExecAbilityClass{
			Abil:   abil,
			Frame:  a.s.Frame() + uint32(df),
			Active: 1,
		}
		ab.Next = ad.ExecList
		if ad.ExecList != nil {
			ad.ExecList.Prev = ab
		}
		ad.ExecList = ab
	}
	a.do(u, abil)
	snd := a.getSound(abil, 0)
	a.s.Audio.EventObj(snd, u, 0, 0)
}

func (a *serverAbilities) Update() {
	for obj, ad := range a.s.Abils.ByUnit {
		for i := server.AbilityInvalid; i < server.AbilityMax; i++ {
			ptr := &ad.Cooldowns[i]
			if v := *ptr; v != 0 {
				*ptr = v - 1
				if *ptr == 0 {
					a.netAbilReportState(obj, i, 1)
				}
			}
		}
	}
	for obj, ad := range a.s.Abils.ByUnit {
		var next *server.ExecAbilityClass
		for p := ad.ExecList; p != nil; p = next {
			next = p.Next
			if !obj.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
				if a.s.Frame() <= p.Frame {
					continue
				}
				snd := a.getSound(p.Abil, 2)
				a.s.Audio.EventObj(snd, obj, 0, 0)
				a.netAbilReportActive(obj, p.Abil, false)
				if p.Abil == server.AbilityBerserk {
					nox_xxx_playerSetState_4FA020(obj, server.PlayerState13)
				}
			}
			if next != nil {
				next.Prev = p.Prev
			}
			if prev := p.Prev; prev != nil {
				prev.Next = p.Next
			} else {
				ad.ExecList = p.Next
			}
			*p = server.ExecAbilityClass{}
		}
	}
}

func (a *serverAbilities) ResetAbility(u *server.Object, abil server.Ability) {
	if u == nil {
		return
	}
	ad, ok := a.s.Abils.ByUnit[u]
	if !ok {
		return
	}
	ad.Cooldowns[abil] = 0
	a.netAbilReset(u, abil)
	var next *server.ExecAbilityClass
	for it := ad.ExecList; it != nil; it = next {
		next = it.Next
		if it.Abil == abil {
			a.netAbilReportActive(u, it.Abil, false)
			if next != nil {
				next.Prev = it.Prev
			}
			if prev := it.Prev; prev != nil {
				prev.Next = it.Next
			} else {
				ad.ExecList = it.Next
			}
			*it = server.ExecAbilityClass{}
		}
	}
}

func (a *serverAbilities) CancelAbilities(u *server.Object) {
	if u == nil {
		return
	}
	ad, ok := a.s.Abils.ByUnit[u]
	if !ok {
		return
	}
	for i := server.AbilityInvalid; i < server.AbilityMax; i++ {
		ad.Cooldowns[i] = 0
	}
	a.netAbilReset(u, 6)
	var next *server.ExecAbilityClass
	for it := ad.ExecList; it != nil; it = next {
		next = it.Next
		a.netAbilReportActive(u, it.Abil, false)
		if next != nil {
			next.Prev = it.Prev
		}
		if prev := it.Prev; prev != nil {
			prev.Next = it.Next
		} else {
			ad.ExecList = it.Next
		}
		*it = server.ExecAbilityClass{}
	}
}

func (a *serverAbilities) DisableAbility(u *server.Object, abil server.Ability) {
	if u == nil {
		return
	}
	if !abil.Valid() {
		return
	}
	switch abil {
	case server.AbilityHarpoon:
		a.harpoon.disable(u)
		break
	case server.AbilityTreadLightly:
		asObjectS(u).DisableEnchant(server.ENCHANT_SNEAK)
		break
	case server.AbilityInfravis:
		return
	}
	a.netAbilReportActive(u, abil, false)
	a.s.Abils.DisableAbilityAaa(u, abil)
}

func (a *serverAbilities) do(u *server.Object, abil server.Ability) {
	if u.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
		return
	}
	switch abil {
	case server.AbilityBerserk:
		nox_xxx_warriorBerserker_53FEB0(u)
	case server.AbilityWarcry:
		nox_xxx_warriorWarcry_53FF40(u)
	case server.AbilityHarpoon:
		a.harpoon.Do(u)
	case server.AbilityTreadLightly:
		nox_xxx_warriorTreadLightly_5400B0(u, a.getDuration(abil))
	case server.AbilityInfravis:
		nox_xxx_warriorInfravis_540110(u, a.getDuration(abil))
	}
}

func (a *serverAbilities) netAbilReportActive(u *server.Object, abil server.Ability, active bool) {
	if u.Class().Has(object.ClassPlayer) {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_REPORT_ACTIVE_ABILITIES)
		buf[1] = byte(abil)
		buf[2] = byte(bool2int(active))
		pl := u.ControllingPlayer()
		a.s.NetSendPacketXxx0(pl.Index(), buf[:3], 0, 1)
	}
}

func (a *serverAbilities) netAbilReportState(u *server.Object, abil server.Ability, st byte) {
	if u.Class().Has(object.ClassPlayer) {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_REPORT_ABILITY_STATE)
		buf[1] = byte(abil)
		buf[2] = st
		pl := u.ControllingPlayer()
		a.s.NetSendPacketXxx0(pl.Index(), buf[:3], 0, 1)
	}
}

func (a *serverAbilities) netAbilReset(u *server.Object, abil server.Ability) {
	if u.Class().Has(object.ClassPlayer) {
		pl := u.ControllingPlayer()
		var buf [2]byte
		buf[0] = byte(noxnet.MSG_RESET_ABILITIES)
		buf[1] = byte(abil)
		a.s.NetSendPacketXxx0(pl.Index(), buf[:2], 0, 1)
	}
}

func (a *serverAbilities) thingsReadAll(f *binfile.MemFile) error {
	n := int(f.ReadI32())
	if n <= 0 {
		return nil
	}
	for i := 0; i < n; i++ {
		if err := a.thingsRead(f); err != nil {
			return err
		}
	}
	return nil
}

func readImageRefAbil(f *binfile.MemFile) (*things.ImageRef, error) {
	v := f.ReadI32()
	ref := &things.ImageRef{Ind: int(v)}
	if ref.Ind == -1 {
		ref.Ind2 = int(f.ReadI8())
		var err error
		ref.Name, err = f.ReadString8()
		if err != nil {
			return nil, fmt.Errorf("cannot read image ref: %w", err)
		}
		ref.Ind = -1 // TODO: why?
	}
	return ref, nil
}

func (a *serverAbilities) thingsRead(f *binfile.MemFile) error {
	id, err := f.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read ability: %w", err)
	}
	abil := a.nox_xxx_abilityNameToN_424D80(id)
	if !abil.Valid() {
		return fmt.Errorf("unsupported ability: %q", id)
	}
	def := &a.defs[abil]
	*def = AbilityDef{}
	def.field36 = int(f.ReadI8())
	ref, err := readImageRefAbil(f)
	if err != nil {
		return fmt.Errorf("cannot read ability: %w", err)
	}
	if noxflags.HasGame(noxflags.GameClient) {
		def.icon8 = noxClient.r.Bag.ThingsImageRef(ref)
	}
	ref, err = readImageRefAbil(f)
	if err != nil {
		return fmt.Errorf("cannot read ability: %w", err)
	}
	if noxflags.HasGame(noxflags.GameClient) {
		def.icon12 = noxClient.r.Bag.ThingsImageRef(ref)
	}
	ref, err = readImageRefAbil(f)
	if err != nil {
		return fmt.Errorf("cannot read ability: %w", err)
	}
	if noxflags.HasGame(noxflags.GameClient) {
		def.icon16 = noxClient.r.Bag.ThingsImageRef(ref)
	}
	sid, err := f.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read ability name: %w", err)
	}
	def.name = a.s.Strings().GetStringInFile(strman.ID(sid), "ComAblty.c")
	sid, err = f.ReadString16()
	if err != nil {
		return fmt.Errorf("cannot read ability name: %w", err)
	}
	def.desc = a.s.Strings().GetStringInFile(strman.ID(sid), "ComAblty.c")
	str, err := f.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read ability sound: %w", err)
	}
	def.sound40 = sound.ByName(str)
	str, err = f.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read ability sound: %w", err)
	}
	def.sound44 = sound.ByName(str)
	str, err = f.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read ability sound: %w", err)
	}
	def.sound48 = sound.ByName(str)
	def.field20 = 1
	def.field24 = 1
	return nil
}

func (a *serverAbilities) reloadGamedata() {
	a.defs[server.AbilityBerserk].delay = int(a.s.Balance.Float("BerserkerChargeDelay"))
	a.defs[server.AbilityBerserk].duration = int(a.s.Balance.Float("BerserkerChargeDuration"))
	a.defs[server.AbilityWarcry].delay = int(a.s.Balance.Float("WarcryDelay"))
	a.defs[server.AbilityWarcry].duration = int(a.s.Balance.Float("WarCryDuration"))
	a.defs[server.AbilityHarpoon].delay = int(a.s.Balance.Float("HarpoonDelay"))
	a.defs[server.AbilityHarpoon].duration = int(a.s.Balance.Float("HarpoonDuration"))
	a.defs[server.AbilityTreadLightly].delay = int(a.s.Balance.Float("TreadLightlyDelay"))
	a.defs[server.AbilityTreadLightly].duration = int(a.s.Balance.Float("TreadLightlyDuration"))
	a.defs[server.AbilityInfravis].delay = int(a.s.Balance.Float("EyeOfTheWolfDelay"))
	a.defs[server.AbilityInfravis].duration = int(a.s.Balance.Float("EyeOfTheWolfDuration"))
}

func (a *serverAbilities) getSound(abil server.Ability, snd int) sound.ID {
	p := &a.defs[abil]
	switch snd {
	case 0:
		return p.sound40
	case 1:
		return p.sound44
	case 2:
		return p.sound48
	}
	return 0
}

func (a *serverAbilities) getDuration(abil server.Ability) int {
	return a.defs[abil].duration
}

func (a *serverAbilities) getName(abil server.Ability) string {
	if !abil.Valid() {
		return ""
	}
	if a.defs[abil].field24 == 0 {
		return ""
	}
	return a.defs[abil].name
}

func (a *serverAbilities) getDelay(abil server.Ability) int {
	if !abil.Valid() {
		return 0
	}
	return a.defs[abil].delay
}

func (a *serverAbilities) getDesc(abil server.Ability) string {
	if !abil.Valid() {
		return ""
	}
	return a.defs[abil].desc
}

func (a *serverAbilities) getIcon(abil server.Ability, icon int) *noxrender.Image {
	p := &a.defs[abil]
	switch icon {
	case 0:
		return p.icon8
	case 1:
		return p.icon12
	case 2:
		return p.icon16
	}
	return nil
}
