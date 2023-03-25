package opennox

import (
	"fmt"
	"unsafe"

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
	noxServer.abilities.Do(asObjectS(cu), server.Ability(a2))
}

func sub_4FC0B0(a1 *server.Object, a2 int) {
	noxServer.abilities.ResetAbility(asObjectS(a1), server.Ability(a2))
}

func nox_xxx_playerCancelAbils_4FC180(cu *server.Object) {
	noxServer.abilities.CancelAbilities(asObjectS(cu))
}

func sub_4FC300(cu *server.Object, a2 int) {
	noxServer.abilities.DisableAbility(asObjectS(cu), server.Ability(a2))
}

func sub_4FC070(a1 *server.Object, a2, dt int) {
	noxServer.abilities.sub4FC070(asObjectS(a1), server.Ability(a2), dt)
}

func sub_4FC030(a1 *server.Object, a2 int) int {
	return noxServer.abilities.sub4FC030(asObjectS(a1), server.Ability(a2))
}

func sub_4FC440(a1 *server.Object, a2 int) {
	noxServer.abilities.sub4FC440(asObjectS(a1), server.Ability(a2))
}

func sub_4FBE60(a1 unsafe.Pointer, abil int) int {
	return noxServer.abilities.getCooldown(a1, server.Ability(abil))
}

func sub_4FBEA0(a1 unsafe.Pointer, abil, cd int) {
	noxServer.abilities.setCooldown(a1, server.Ability(abil), cd)
}

func nox_xxx_abilityGetName_0_425260(ca int) string {
	return noxServer.abilities.getName(server.Ability(ca))
}

func nox_common_playerIsAbilityActive_4FC250(a1 *server.Object, a2 int) int {
	return bool2int(noxServer.abilities.IsActive(asObjectS(a1), server.Ability(a2)))
}

func nox_xxx_probablyWarcryCheck_4FC3E0(a1 *server.Object, a2 int) int {
	return bool2int(noxServer.abilities.IsActiveVal(asObjectS(a1), server.Ability(a2)))
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
	noxServer.abilities.netAbilReportState(asObjectS(a1), a2, a3)
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

type unitAbilities struct {
	cooldowns [server.AbilityMax]int
	execList  *execAbilityClass
}

type serverAbilities struct {
	s      *Server
	curxxx server.Ability
	byUnit map[*server.Object]*unitAbilities
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

func (a *serverAbilities) Reset() {
	a.byUnit = make(map[*server.Object]*unitAbilities)
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

type execAbilityClass struct {
	abil   server.Ability    // 0, 0
	frame  uint32            // 2, 8
	active uint32            // 3, 12
	next   *execAbilityClass // 4, 16
	prev   *execAbilityClass // 5, 20
}

func (a *serverAbilities) sub_4FC680() {
	if noxflags.HasGame(noxflags.GameModeCoop) && !noxflags.HasGame(noxflags.GameFlag20) && a.curxxx != 0 {
		if u := a.s.PlayerFirst().UnitC(); u != nil {
			a.Do(u, a.curxxx)
			a.curxxx = 0
		}
	}
}

func (a *serverAbilities) getAbilitiesFor(u server.Obj) *unitAbilities {
	if u == nil {
		return nil
	}
	d := a.byUnit[u.SObj()]
	if d != nil {
		return d
	}
	d = new(unitAbilities)
	a.byUnit[u.SObj()] = d
	return d
}

func (a *serverAbilities) Do(u *Object, abil server.Ability) {
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
	pl := asPlayerS(ud.Player)
	if pl.PlayerClass() != player.Warrior {
		return
	}
	switch abil {
	case server.AbilityBerserk:
		if noxflags.HasGame(noxflags.GameModeCTF) {
			for it := u.FirstItem(); it != nil; it = it.NextItem() {
				if it.Class().Has(object.ClassFlag) {
					nox_xxx_netInformTextMsg_4DA0F0(pl.PlayerIndex(), 2, 5)
					a.s.AudioEventObj(sound.SoundPermanentFizzle, u, 0, 0)
					return
				}
			}
		}
		if a.IsActiveVal(u, server.AbilityWarcry) || a.IsActive(u, server.AbilityHarpoon) {
			nox_xxx_netInformTextMsg_4DA0F0(pl.PlayerIndex(), 2, 2)
			a.s.AudioEventObj(sound.SoundPermanentFizzle, u, 0, 0)
			return
		}
	case server.AbilityWarcry:
		if a.IsActive(u, server.AbilityBerserk) || a.IsActive(u, server.AbilityHarpoon) {
			nox_xxx_netInformTextMsg_4DA0F0(pl.PlayerIndex(), 2, 2)
			a.s.AudioEventObj(sound.SoundPermanentFizzle, u, 0, 0)
			return
		}
	case server.AbilityHarpoon:
		if a.IsActiveVal(u, server.AbilityWarcry) || a.IsActive(u, server.AbilityBerserk) {
			nox_xxx_netInformTextMsg_4DA0F0(pl.PlayerIndex(), 2, 2)
			a.s.AudioEventObj(sound.SoundPermanentFizzle, u, 0, 0)
			return
		}
	}
	if a.IsActive(u, abil) {
		nox_xxx_netInformTextMsg_4DA0F0(pl.PlayerIndex(), 2, 2)
		a.s.AudioEventObj(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	if ud.Field22_0 == 12 || !noxflags.HasGame(noxflags.GameModeCoop) && u.Flags().Has(object.FlagAirborne) {
		nox_xxx_netInformTextMsg_4DA0F0(pl.PlayerIndex(), 2, 6)
		a.s.AudioEventObj(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	if (!noxflags.HasGame(noxflags.GameOnline) || noxflags.HasGame(noxflags.GameModeQuest)) && pl.SpellLvl[abil] == 0 {
		nox_xxx_netInformTextMsg_4DA0F0(pl.PlayerIndex(), 2, 3)
		a.s.AudioEventObj(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	if abil == server.AbilityBerserk && pl.Field3656 == 1 {
		nox_xxx_netInformTextMsg_4DA0F0(pl.PlayerIndex(), 2, 7)
		return
	}
	ad := a.getAbilitiesFor(u)
	cd := &ad.cooldowns[abil]
	if *cd != 0 {
		nox_xxx_netInformTextMsg_4DA0F0(pl.PlayerIndex(), 2, 2)
		a.s.AudioEventObj(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	*cd = a.getDelay(abil)
	if a.getDelay(abil) != 0 {
		a.netAbilReportState(u, abil, 0)
	}
	if df := a.getDuration(abil); df > 0 {
		ab := &execAbilityClass{
			abil:   abil,
			frame:  a.s.Frame() + uint32(df),
			active: 1,
		}
		ab.next = ad.execList
		if ad.execList != nil {
			ad.execList.prev = ab
		}
		ad.execList = ab
	}
	a.do(u, abil)
	snd := a.getSound(abil, 0)
	a.s.AudioEventObj(snd, u, 0, 0)
}

func (a *serverAbilities) Update() {
	for obj, ad := range a.byUnit {
		u := asObjectS(obj)
		for i := server.AbilityInvalid; i < server.AbilityMax; i++ {
			ptr := &ad.cooldowns[i]
			if v := *ptr; v != 0 {
				*ptr = v - 1
				if *ptr == 0 {
					a.netAbilReportState(u, i, 1)
				}
			}
		}
	}
	for obj, ad := range a.byUnit {
		u := asObjectS(obj)
		var next *execAbilityClass
		for p := ad.execList; p != nil; p = next {
			next = p.next
			if !u.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
				if a.s.Frame() <= p.frame {
					continue
				}
				snd := a.getSound(p.abil, 2)
				a.s.AudioEventObj(snd, u, 0, 0)
				a.netAbilReportActive(u, p.abil, false)
				if p.abil == server.AbilityBerserk {
					nox_xxx_playerSetState_4FA020(u, 13)
				}
			}
			if next != nil {
				next.prev = p.prev
			}
			if prev := p.prev; prev != nil {
				prev.next = p.next
			} else {
				ad.execList = p.next
			}
			*p = execAbilityClass{}
		}
	}
}

func (a *serverAbilities) ResetAbility(u *Object, abil server.Ability) {
	if u == nil {
		return
	}
	ad, ok := a.byUnit[u.SObj()]
	if !ok {
		return
	}
	ad.cooldowns[abil] = 0
	a.netAbilReset(u, abil)
	var next *execAbilityClass
	for it := ad.execList; it != nil; it = next {
		next = it.next
		if it.abil == abil {
			a.netAbilReportActive(u, it.abil, false)
			if next != nil {
				next.prev = it.prev
			}
			if prev := it.prev; prev != nil {
				prev.next = it.next
			} else {
				ad.execList = it.next
			}
			*it = execAbilityClass{}
		}
	}
}

func (a *serverAbilities) CancelAbilities(u *Object) {
	if u == nil {
		return
	}
	ad, ok := a.byUnit[u.SObj()]
	if !ok {
		return
	}
	for i := server.AbilityInvalid; i < server.AbilityMax; i++ {
		ad.cooldowns[i] = 0
	}
	a.netAbilReset(u, 6)
	var next *execAbilityClass
	for it := ad.execList; it != nil; it = next {
		next = it.next
		a.netAbilReportActive(u, it.abil, false)
		if next != nil {
			next.prev = it.prev
		}
		if prev := it.prev; prev != nil {
			prev.next = it.next
		} else {
			ad.execList = it.next
		}
		*it = execAbilityClass{}
	}
}

func (a *serverAbilities) DisableAbility(u *Object, abil server.Ability) {
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
		u.DisableEnchant(server.ENCHANT_SNEAK)
		break
	case server.AbilityInfravis:
		return
	}
	a.netAbilReportActive(u, abil, false)
	ad, ok := a.byUnit[u.SObj()]
	if !ok {
		return
	}
	var next *execAbilityClass
	for it := ad.execList; it != nil; it = next {
		next = it.next
		if it.abil == abil {
			if next != nil {
				next.prev = it.prev
			}
			if prev := it.prev; prev != nil {
				prev.next = it.next
			} else {
				ad.execList = it.next
			}
			*it = execAbilityClass{}
		}
	}
}

func (a *serverAbilities) do(u *Object, abil server.Ability) {
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

func (a *serverAbilities) sub4FC030(u *Object, abil server.Ability) int {
	ad, ok := a.byUnit[u.SObj()]
	if !ok {
		return -1
	}
	for it := ad.execList; it != nil; it = it.next {
		if it.abil == abil {
			return int(it.frame - a.s.Frame())
		}
	}
	return -1
}

func (a *serverAbilities) sub4FC070(u *Object, abil server.Ability, dt int) {
	ad, ok := a.byUnit[u.SObj()]
	if !ok {
		return
	}
	for it := ad.execList; it != nil; it = it.next {
		if it.abil == abil {
			it.frame = a.s.Frame() + uint32(dt)
			break
		}
	}
}

func (a *serverAbilities) IsActive(u *Object, abil server.Ability) bool {
	ad, ok := a.byUnit[u.SObj()]
	if !ok {
		return false
	}
	for it := ad.execList; it != nil; it = it.next {
		if it.abil == abil {
			return true
		}
	}
	return false
}

func (a *serverAbilities) IsActiveVal(u *Object, abil server.Ability) bool {
	ad, ok := a.byUnit[u.SObj()]
	if !ok {
		return false
	}
	for it := ad.execList; it != nil; it = it.next {
		if it.abil == abil {
			return it.active != 0
		}
	}
	return false
}

func (a *serverAbilities) IsAnyActive(u *Object) bool {
	ad, ok := a.byUnit[u.SObj()]
	if !ok {
		return false
	}
	return ad.execList != nil
}

func (a *serverAbilities) netAbilReportActive(u *Object, abil server.Ability, active bool) {
	if u.Class().Has(object.ClassPlayer) {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_REPORT_ACTIVE_ABILITIES)
		buf[1] = byte(abil)
		buf[2] = byte(bool2int(active))
		pl := u.ControllingPlayer()
		a.s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:3], 0, 1)
	}
}

func (a *serverAbilities) netAbilReportState(u *Object, abil server.Ability, st byte) {
	if u.Class().Has(object.ClassPlayer) {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_REPORT_ABILITY_STATE)
		buf[1] = byte(abil)
		buf[2] = st
		pl := u.ControllingPlayer()
		a.s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:3], 0, 1)
	}
}

func (a *serverAbilities) netAbilReset(u *Object, abil server.Ability) {
	if u.Class().Has(object.ClassPlayer) {
		pl := u.ControllingPlayer()
		var buf [2]byte
		buf[0] = byte(noxnet.MSG_RESET_ABILITIES)
		buf[1] = byte(abil)
		a.s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:2], 0, 1)
	}
}

func (a *serverAbilities) sub4FC440(u *Object, abil server.Ability) {
	ad, ok := a.byUnit[u.SObj()]
	if !ok {
		return
	}
	for it := ad.execList; it != nil; it = it.next {
		if it.abil == abil {
			it.active = 0
			break
		}
	}
}

func (a *serverAbilities) getCooldown(a1 unsafe.Pointer, abil server.Ability) int {
	pl := a.s.GetPlayerByID(int(*(*int32)(unsafe.Add(a1, 36))))
	if pl == nil {
		return 0
	}
	ad, ok := a.byUnit[pl.UnitC().SObj()]
	if !ok {
		return 0
	}
	return ad.cooldowns[abil]
}

func (a *serverAbilities) setCooldown(a1 unsafe.Pointer, abil server.Ability, cd int) {
	pl := a.s.GetPlayerByID(int(*(*int32)(unsafe.Add(a1, 36))))
	if pl == nil {
		return
	}
	ad, ok := a.byUnit[pl.UnitC().SObj()]
	if !ok {
		return
	}
	ad.cooldowns[abil] = cd
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
	a.defs[server.AbilityBerserk].delay = int(gamedataFloat("BerserkerChargeDelay"))
	a.defs[server.AbilityBerserk].duration = int(gamedataFloat("BerserkerChargeDuration"))
	a.defs[server.AbilityWarcry].delay = int(gamedataFloat("WarcryDelay"))
	a.defs[server.AbilityWarcry].duration = int(gamedataFloat("WarCryDuration"))
	a.defs[server.AbilityHarpoon].delay = int(gamedataFloat("HarpoonDelay"))
	a.defs[server.AbilityHarpoon].duration = int(gamedataFloat("HarpoonDuration"))
	a.defs[server.AbilityTreadLightly].delay = int(gamedataFloat("TreadLightlyDelay"))
	a.defs[server.AbilityTreadLightly].duration = int(gamedataFloat("TreadLightlyDuration"))
	a.defs[server.AbilityInfravis].delay = int(gamedataFloat("EyeOfTheWolfDelay"))
	a.defs[server.AbilityInfravis].duration = int(gamedataFloat("EyeOfTheWolfDuration"))
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
