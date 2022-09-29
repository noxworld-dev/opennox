package opennox

import "C"
import (
	"fmt"
	"strconv"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/things"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

//export sub_4FC670
func sub_4FC670(a1 C.int) {
	noxServer.abilities.curxxx = Ability(a1)
}

//export nox_xxx_playerExecuteAbil_4FBB70
func nox_xxx_playerExecuteAbil_4FBB70(cu *nox_object_t, a2 C.int) {
	noxServer.abilities.Do(asUnitC(cu), Ability(a2))
}

//export sub_4FC0B0
func sub_4FC0B0(a1 *nox_object_t, a2 C.int) {
	noxServer.abilities.ResetAbility(asUnitC(a1), Ability(a2))
}

//export nox_xxx_playerCancelAbils_4FC180
func nox_xxx_playerCancelAbils_4FC180(cu *nox_object_t) {
	noxServer.abilities.CancelAbilities(asUnitC(cu))
}

//export sub_4FC300
func sub_4FC300(cu *nox_object_t, a2 C.int) {
	noxServer.abilities.DisableAbility(asUnitC(cu), Ability(a2))
}

//export sub_4FC070
func sub_4FC070(a1 *nox_object_t, a2, dt C.int) {
	noxServer.abilities.sub4FC070(asUnitC(a1), Ability(a2), int(dt))
}

//export sub_4FC030
func sub_4FC030(a1 *nox_object_t, a2 C.int) C.int {
	return C.int(noxServer.abilities.sub4FC030(asUnitC(a1), Ability(a2)))
}

//export sub_4FC440
func sub_4FC440(a1 *nox_object_t, a2 C.int) {
	noxServer.abilities.sub4FC440(asUnitC(a1), Ability(a2))
}

//export nox_xxx_abilityGetName_425250
func nox_xxx_abilityGetName_425250(a1 C.int) *C.char {
	return internCStr(Ability(a1).String())
}

//export sub_4FBE60
func sub_4FBE60(a1 unsafe.Pointer, abil C.int) C.int {
	return C.int(noxServer.abilities.getCooldown(a1, Ability(abil)))
}

//export sub_4FBEA0
func sub_4FBEA0(a1 unsafe.Pointer, abil, cd C.int) {
	noxServer.abilities.setCooldown(a1, Ability(abil), int(cd))
}

//export nox_xxx_abilityGetName_0_425260
func nox_xxx_abilityGetName_0_425260(ca C.int) *wchar_t {
	return internWStr(noxServer.abilities.getName(Ability(ca)))
}

//export nox_common_playerIsAbilityActive_4FC250
func nox_common_playerIsAbilityActive_4FC250(a1 *nox_object_t, a2 C.int) C.int {
	return C.int(bool2int(noxServer.abilities.IsActive(asUnitC(a1), Ability(a2))))
}

//export nox_xxx_probablyWarcryCheck_4FC3E0
func nox_xxx_probablyWarcryCheck_4FC3E0(a1 *nox_object_t, a2 C.int) C.int {
	return C.int(bool2int(noxServer.abilities.IsActiveVal(asUnitC(a1), Ability(a2))))
}

//export nox_xxx_abilityCooldown_4252D0
func nox_xxx_abilityCooldown_4252D0(ca C.int) C.int {
	return C.int(noxServer.abilities.getDelay(Ability(ca)))
}

//export sub_4252F0
func sub_4252F0(ca C.int) *wchar_t {
	return internWStr(noxServer.abilities.getDesc(Ability(ca)))
}

//export nox_xxx_spellGetAbilityIcon_425310
func nox_xxx_spellGetAbilityIcon_425310(abil, icon C.int) *nox_video_bag_image_t {
	return noxServer.abilities.getIcon(Ability(abil), int(icon)).C()
}

//export nox_xxx_bookFirstKnownAbil_425330
func nox_xxx_bookFirstKnownAbil_425330() C.int {
	for i := abilityInvalid + 1; i < abilityMax; i++ {
		if noxServer.abilities.defs[i].field24 != 0 {
			return C.int(i)
		}
	}
	return 0
}

//export nox_xxx_bookNextKnownAbil_425350
func nox_xxx_bookNextKnownAbil_425350(a1 C.int) C.int {
	for i := Ability(a1) + 1; i < abilityMax; i++ {
		if noxServer.abilities.defs[i].field24 != 0 {
			return C.int(i)
		}
	}
	return 0
}

//export sub_425450
func sub_425450(a1 C.int) C.int {
	return C.int(noxServer.abilities.defs[a1].field36)
}

//export nox_xxx_netAbilRepotState_4D8100
func nox_xxx_netAbilRepotState_4D8100(a1 *nox_object_t, a2, a3 C.char) {
	noxServer.abilities.netAbilReportState(asUnitC(a1), Ability(a2), byte(a3))
}

type AbilityDef struct {
	name     string   // 0, 0
	desc     string   // 1, 4
	icon8    *Image   // 2, 8
	icon12   *Image   // 3, 12
	icon16   *Image   // 4, 16
	field20  uint32   // 5, 20
	field24  uint32   // 6, 24
	delay    int      // 7, 28
	duration int      // 8, 32
	field36  int      // 9, 36
	sound40  sound.ID // 10, 40
	sound44  sound.ID // 11, 44
	sound48  sound.ID // 12, 48
}

type unitAbilities struct {
	cooldowns [abilityMax]int
	execList  *execAbilityClass
}

type serverAbilities struct {
	s      *Server
	curxxx Ability
	byUnit map[*nox_object_t]*unitAbilities
	byName map[string]Ability
	defs   [abilityMax]AbilityDef

	harpoon abilityHarpoon
}

func (a *serverAbilities) Init(s *Server) {
	a.s = s
	a.byName = make(map[string]Ability)
	for i := abilityInvalid + 1; i < abilityMax; i++ {
		a.byName[abilityNames[i]] = i
	}
	a.harpoon.Init(s)
}

func (a *serverAbilities) Reset() {
	a.byUnit = make(map[*nox_object_t]*unitAbilities)
}

func (a *serverAbilities) Free() {
	a.harpoon.Free()
}

func (a *serverAbilities) nox_xxx_abilityNameToN_424D80(name string) Ability {
	if len(a.byName) == 0 {
		panic("not initialized yet")
	}
	return a.byName[name]
}

type Ability int32

func (a Ability) String() string {
	if a >= 0 && int(a) < len(abilityNames) {
		return abilityNames[a]
	}
	return "Ability(" + strconv.Itoa(int(a)) + ")"
}

func (a Ability) Valid() bool {
	return a > abilityInvalid && a < abilityMax
}

const (
	abilityInvalid = Ability(iota)
	AbilityBerserk
	AbilityWarcry
	AbilityHarpoon
	AbilityTreadLightly
	AbilityInfravis
	abilityMax
)

var abilityNames = []string{
	"ABILITY_INVALID", "ABILITY_BERSERKER_CHARGE", "ABILITY_WARCRY",
	"ABILITY_HARPOON", "ABILITY_TREAD_LIGHTLY", "ABILITY_EYE_OF_THE_WOLF",
}

type execAbilityClass struct {
	abil   Ability           // 0, 0
	frame  uint32            // 2, 8
	active uint32            // 3, 12
	next   *execAbilityClass // 4, 16
	prev   *execAbilityClass // 5, 20
}

func (a *serverAbilities) sub_4FC680() {
	if noxflags.HasGame(noxflags.GameModeCoop) && !noxflags.HasGame(noxflags.GameFlag20) && a.curxxx != 0 {
		if u := a.s.playerFirst().UnitC(); u != nil {
			a.Do(u, a.curxxx)
			a.curxxx = 0
		}
	}
}

func (a *serverAbilities) getAbilitiesFor(u noxObject) *unitAbilities {
	if u == nil {
		return nil
	}
	d := a.byUnit[u.CObj()]
	if d != nil {
		return d
	}
	d = new(unitAbilities)
	a.byUnit[u.CObj()] = d
	return d
}

func (a *serverAbilities) Do(u *Unit, abil Ability) {
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
	ud := u.updateDataPlayer()
	pl := ud.Player()
	if pl.PlayerClass() != player.Warrior {
		return
	}
	switch abil {
	case AbilityBerserk:
		if noxflags.HasGame(noxflags.GameModeCTF) {
			for it := u.FirstItem(); it != nil; it = it.NextItem() {
				if it.Class().Has(object.ClassFlag) {
					nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 5)
					nox_xxx_aud_501960(sound.SoundPermanentFizzle, u, 0, 0)
					return
				}
			}
		}
		if a.IsActiveVal(u, AbilityWarcry) || a.IsActive(u, AbilityHarpoon) {
			nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 2)
			nox_xxx_aud_501960(sound.SoundPermanentFizzle, u, 0, 0)
			return
		}
	case AbilityWarcry:
		if a.IsActive(u, AbilityBerserk) || a.IsActive(u, AbilityHarpoon) {
			nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 2)
			nox_xxx_aud_501960(sound.SoundPermanentFizzle, u, 0, 0)
			return
		}
	case AbilityHarpoon:
		if a.IsActiveVal(u, AbilityWarcry) || a.IsActive(u, AbilityBerserk) {
			nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 2)
			nox_xxx_aud_501960(sound.SoundPermanentFizzle, u, 0, 0)
			return
		}
	}
	if a.IsActive(u, abil) {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 2)
		nox_xxx_aud_501960(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	if ud.field_22_0 == 12 || !noxflags.HasGame(noxflags.GameModeCoop) && u.Flags().Has(object.FlagAirborne) {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 6)
		nox_xxx_aud_501960(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	if (!noxflags.HasGame(noxflags.GameOnline) || noxflags.HasGame(noxflags.GameModeQuest)) && pl.spell_lvl[abil] == 0 {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 3)
		nox_xxx_aud_501960(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	if abil == AbilityBerserk && pl.field_3656 == 1 {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 7)
		return
	}
	ad := a.getAbilitiesFor(u)
	cd := &ad.cooldowns[abil]
	if *cd != 0 {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 2)
		nox_xxx_aud_501960(sound.SoundPermanentFizzle, u, 0, 0)
		return
	}
	*cd = a.getDelay(abil)
	if a.getDelay(abil) != 0 {
		a.netAbilReportState(u, abil, 0)
	}
	if df := a.getDuration(abil); df > 0 {
		ab := &execAbilityClass{
			abil:   abil,
			frame:  gameFrame() + uint32(df),
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
	nox_xxx_aud_501960(snd, u, 0, 0)
}

func (a *serverAbilities) Update() {
	for obj, ad := range a.byUnit {
		u := asUnitC(obj)
		for i := abilityInvalid; i < abilityMax; i++ {
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
		u := asUnitC(obj)
		var next *execAbilityClass
		for p := ad.execList; p != nil; p = next {
			next = p.next
			if !u.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
				if gameFrame() <= p.frame {
					continue
				}
				snd := a.getSound(p.abil, 2)
				nox_xxx_aud_501960(snd, u, 0, 0)
				a.netAbilReportActive(u, p.abil, false)
				if p.abil == AbilityBerserk {
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

func (a *serverAbilities) ResetAbility(u *Unit, abil Ability) {
	if u == nil {
		return
	}
	ad, ok := a.byUnit[u.CObj()]
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

func (a *serverAbilities) CancelAbilities(u *Unit) {
	if u == nil {
		return
	}
	ad, ok := a.byUnit[u.CObj()]
	if !ok {
		return
	}
	for i := abilityInvalid; i < abilityMax; i++ {
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

func (a *serverAbilities) DisableAbility(u *Unit, abil Ability) {
	if u == nil {
		return
	}
	if !abil.Valid() {
		return
	}
	switch abil {
	case AbilityHarpoon:
		a.harpoon.disable(u)
		break
	case AbilityTreadLightly:
		u.DisableEnchant(ENCHANT_SNEAK)
		break
	case AbilityInfravis:
		return
	}
	a.netAbilReportActive(u, abil, false)
	ad, ok := a.byUnit[u.CObj()]
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

func (a *serverAbilities) do(u *Unit, abil Ability) {
	if u.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
		return
	}
	switch abil {
	case AbilityBerserk:
		nox_xxx_warriorBerserker_53FEB0(u)
	case AbilityWarcry:
		nox_xxx_warriorWarcry_53FF40(u)
	case AbilityHarpoon:
		a.harpoon.Do(u)
	case AbilityTreadLightly:
		nox_xxx_warriorTreadLightly_5400B0(u, a.getDuration(abil))
	case AbilityInfravis:
		nox_xxx_warriorInfravis_540110(u, a.getDuration(abil))
	}
}

func (a *serverAbilities) sub4FC030(u *Unit, abil Ability) int {
	ad, ok := a.byUnit[u.CObj()]
	if !ok {
		return -1
	}
	for it := ad.execList; it != nil; it = it.next {
		if it.abil == abil {
			return int(it.frame - gameFrame())
		}
	}
	return -1
}

func (a *serverAbilities) sub4FC070(u *Unit, abil Ability, dt int) {
	ad, ok := a.byUnit[u.CObj()]
	if !ok {
		return
	}
	for it := ad.execList; it != nil; it = it.next {
		if it.abil == abil {
			it.frame = gameFrame() + uint32(dt)
			break
		}
	}
}

func (a *serverAbilities) IsActive(u *Unit, abil Ability) bool {
	ad, ok := a.byUnit[u.CObj()]
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

func (a *serverAbilities) IsActiveVal(u *Unit, abil Ability) bool {
	ad, ok := a.byUnit[u.CObj()]
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

func (a *serverAbilities) IsAnyActive(u *Unit) bool {
	ad, ok := a.byUnit[u.CObj()]
	if !ok {
		return false
	}
	return ad.execList != nil
}

func (a *serverAbilities) netAbilReportActive(u *Unit, abil Ability, active bool) {
	if u.Class().Has(object.ClassPlayer) {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_REPORT_ACTIVE_ABILITIES)
		buf[1] = byte(abil)
		buf[2] = byte(bool2int(active))
		pl := u.ControllingPlayer()
		a.s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:3], 0, 1)
	}
}

func (a *serverAbilities) netAbilReportState(u *Unit, abil Ability, st byte) {
	if u.Class().Has(object.ClassPlayer) {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_REPORT_ABILITY_STATE)
		buf[1] = byte(abil)
		buf[2] = st
		pl := u.ControllingPlayer()
		a.s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:3], 0, 1)
	}
}

func (a *serverAbilities) netAbilReset(u *Unit, abil Ability) {
	if u.Class().Has(object.ClassPlayer) {
		pl := u.ControllingPlayer()
		var buf [2]byte
		buf[0] = byte(noxnet.MSG_RESET_ABILITIES)
		buf[1] = byte(abil)
		a.s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:2], 0, 1)
	}
}

func (a *serverAbilities) sub4FC440(u *Unit, abil Ability) {
	ad, ok := a.byUnit[u.CObj()]
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

func (a *serverAbilities) getCooldown(a1 unsafe.Pointer, abil Ability) int {
	pl := a.s.getPlayerByID(int(*(*int32)(unsafe.Add(a1, 36))))
	if pl == nil {
		return 0
	}
	ad, ok := a.byUnit[pl.UnitC().CObj()]
	if !ok {
		return 0
	}
	return ad.cooldowns[abil]
}

func (a *serverAbilities) setCooldown(a1 unsafe.Pointer, abil Ability, cd int) {
	pl := a.s.getPlayerByID(int(*(*int32)(unsafe.Add(a1, 36))))
	if pl == nil {
		return
	}
	ad, ok := a.byUnit[pl.UnitC().CObj()]
	if !ok {
		return
	}
	ad.cooldowns[abil] = cd
}

func (a *serverAbilities) thingsReadAll(f *MemFile) error {
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

func readImageRefAbil(f *MemFile) (*things.ImageRef, error) {
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

func (a *serverAbilities) thingsRead(f *MemFile) error {
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
		def.icon8 = thingsImageRef(ref)
	}
	ref, err = readImageRefAbil(f)
	if err != nil {
		return fmt.Errorf("cannot read ability: %w", err)
	}
	if noxflags.HasGame(noxflags.GameClient) {
		def.icon12 = thingsImageRef(ref)
	}
	ref, err = readImageRefAbil(f)
	if err != nil {
		return fmt.Errorf("cannot read ability: %w", err)
	}
	if noxflags.HasGame(noxflags.GameClient) {
		def.icon16 = thingsImageRef(ref)
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
	a.defs[AbilityBerserk].delay = int(gamedataFloat("BerserkerChargeDelay"))
	a.defs[AbilityBerserk].duration = int(gamedataFloat("BerserkerChargeDuration"))
	a.defs[AbilityWarcry].delay = int(gamedataFloat("WarcryDelay"))
	a.defs[AbilityWarcry].duration = int(gamedataFloat("WarCryDuration"))
	a.defs[AbilityHarpoon].delay = int(gamedataFloat("HarpoonDelay"))
	a.defs[AbilityHarpoon].duration = int(gamedataFloat("HarpoonDuration"))
	a.defs[AbilityTreadLightly].delay = int(gamedataFloat("TreadLightlyDelay"))
	a.defs[AbilityTreadLightly].duration = int(gamedataFloat("TreadLightlyDuration"))
	a.defs[AbilityInfravis].delay = int(gamedataFloat("EyeOfTheWolfDelay"))
	a.defs[AbilityInfravis].duration = int(gamedataFloat("EyeOfTheWolfDuration"))
}

func (a *serverAbilities) getSound(abil Ability, snd int) sound.ID {
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

func (a *serverAbilities) getDuration(abil Ability) int {
	return a.defs[abil].duration
}

func (a *serverAbilities) getName(abil Ability) string {
	if !abil.Valid() {
		return ""
	}
	if a.defs[abil].field24 == 0 {
		return ""
	}
	return a.defs[abil].name
}

func (a *serverAbilities) getDelay(abil Ability) int {
	if !abil.Valid() {
		return 0
	}
	return a.defs[abil].delay
}

func (a *serverAbilities) getDesc(abil Ability) string {
	if !abil.Valid() {
		return ""
	}
	return a.defs[abil].desc
}

func (a *serverAbilities) getIcon(abil Ability, icon int) *Image {
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
