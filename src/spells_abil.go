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
)

var (
	execAbilHead         *execAbilityClass
	dword_5d4594_1569660 int
	abilityCooldowns     [NOX_PLAYERINFO_MAX][abilityMax]int
	abilityByName        = make(map[string]Ability)
	abilityDefs          [abilityMax]AbilityDef
)

type AbilityDef struct {
	name     string // 0, 0
	desc     string // 1, 4
	icon8    *Image // 2, 8
	icon12   *Image // 3, 12
	icon16   *Image // 4, 16
	field20  uint32 // 5, 20
	field24  uint32 // 6, 24
	delay    int    // 7, 28
	duration int    // 8, 32
	field36  int    // 9, 36
	sound40  int    // 10, 40
	sound44  int    // 11, 44
	sound48  int    // 12, 48
}

func init() {
	for i := abilityInvalid + 1; i < abilityMax; i++ {
		abilityByName[abilityNames[i]] = i
	}
}

func nox_xxx_abilityNameToN_424D80(name string) Ability {
	return abilityByName[name]
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

var _ = [1]struct{}{}[24-unsafe.Sizeof(execAbilityClass{})]

type execAbilityClass struct {
	abil   Ability           // 0, 0
	unit   *Unit             // 1, 4
	frame  uint32            // 2, 8
	active uint32            // 3, 12
	next   *execAbilityClass // 4, 16
	prev   *execAbilityClass // 5, 20
}

func (s *Server) resetAbilities() {
	abilityCooldowns = [NOX_PLAYERINFO_MAX][abilityMax]int{}
}

//export sub_4FC670
func sub_4FC670(a1 C.int) {
	dword_5d4594_1569660 = int(a1)
}

func sub_4FC680() {
	if noxflags.HasGame(noxflags.GameModeCoop) && !noxflags.HasGame(noxflags.GameFlag20) && dword_5d4594_1569660 != 0 {
		if u := noxServer.playerFirst().UnitC(); u != nil {
			nox_xxx_playerExecuteAbil_4FBB70(u.CObj(), C.int(dword_5d4594_1569660))
			dword_5d4594_1569660 = 0
		}
	}
}

//export nox_xxx_playerExecuteAbil_4FBB70
func nox_xxx_playerExecuteAbil_4FBB70(cu *nox_object_t, a2 C.int) {
	s := noxServer
	if cu == nil {
		return
	}
	abil := Ability(a2)
	if !abil.Valid() {
		return
	}
	u := asUnitC(cu)
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
					nox_xxx_aud_501960(231, u, 0, 0)
					return
				}
			}
		}
		if isAbilityActiveVal(u, AbilityWarcry) || isAbilityActive(u, AbilityHarpoon) {
			nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 2)
			nox_xxx_aud_501960(231, u, 0, 0)
			return
		}
	case AbilityWarcry:
		if isAbilityActive(u, AbilityWarcry) || isAbilityActive(u, AbilityHarpoon) {
			nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 2)
			nox_xxx_aud_501960(231, u, 0, 0)
			return
		}
	case AbilityHarpoon:
		if isAbilityActiveVal(u, AbilityWarcry) || isAbilityActive(u, AbilityBerserk) {
			nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 2)
			nox_xxx_aud_501960(231, u, 0, 0)
			return
		}
	}
	if isAbilityActive(u, abil) {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 2)
		nox_xxx_aud_501960(231, u, 0, 0)
		return
	}
	if ud.field_22_0 == 12 || !noxflags.HasGame(noxflags.GameModeCoop) && u.Flags().Has(object.FlagAirborne) {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 6)
		nox_xxx_aud_501960(231, u, 0, 0)
		return
	}
	if (!noxflags.HasGame(noxflags.GameOnline) || noxflags.HasGame(noxflags.GameModeQuest)) && pl.spell_lvl[abil] == 0 {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 3)
		nox_xxx_aud_501960(231, u, 0, 0)
		return
	}
	if abil == AbilityBerserk && pl.field_3656 == 1 {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 7)
		return
	}
	cd := &abilityCooldowns[pl.Index()][abil]
	if *cd != 0 {
		nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 2, 2)
		nox_xxx_aud_501960(231, u, 0, 0)
		return
	}
	*cd = abilityCooldown(abil)
	if abilityCooldown(abil) != 0 {
		s.netAbilReportState(u, abil, 0)
	}
	if df := getAbilityDur(abil); df > 0 {
		ab := &execAbilityClass{
			abil:   abil,
			unit:   u,
			frame:  gameFrame() + uint32(df),
			active: 1,
		}
		ab.next = execAbilHead
		if execAbilHead != nil {
			execAbilHead.prev = ab
		}
		execAbilHead = ab
	}
	nox_xxx_playerInvokeAbility_4FBAF0(u, abil)
	snd := getAbilitySound(abil, 0)
	nox_xxx_aud_501960(snd, u, 0, 0)
}

func (s *Server) updateAbilities() {
	for _, p := range s.getPlayers() {
		if p.UnitC() != nil && p.PlayerClass() == player.Warrior {
			for i := abilityInvalid; i < abilityMax; i++ {
				ptr := &abilityCooldowns[p.Index()][i]
				if v := *ptr; v != 0 {
					*ptr = v - 1
					if *ptr == 0 {
						s.netAbilReportState(p.UnitC(), i, 1)
					}
				}
			}
		}
	}
	var next *execAbilityClass
	for p := execAbilHead; p != nil; p = next {
		next = p.next
		if !p.unit.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			if gameFrame() <= p.frame {
				continue
			}
			snd := getAbilitySound(p.abil, 2)
			nox_xxx_aud_501960(snd, p.unit, 0, 0)
			s.netAbilReportActive(p.unit, p.abil, false)
			if p.abil == AbilityBerserk {
				nox_xxx_playerSetState_4FA020(p.unit, 13)
			}
		}
		if next != nil {
			next.prev = p.prev
		}
		if prev := p.prev; prev != nil {
			prev.next = p.next
		} else {
			execAbilHead = p.next
		}
		*p = execAbilityClass{}
	}
}

//export sub_4FC0B0
func sub_4FC0B0(a1 *nox_object_t, a2 C.int) {
	abil := Ability(a2)
	u := asUnitC(a1)
	if u == nil {
		return
	}
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	s := noxServer
	pl := u.ControllingPlayer()
	if pl.PlayerClass() != player.Warrior {
		return
	}
	abilityCooldowns[pl.Index()][abil] = 0
	s.netAbilReset(u, abil)
	var next *execAbilityClass
	for it := execAbilHead; it != nil; it = next {
		next = it.next
		if it.unit == u && it.abil == abil {
			s.netAbilReportActive(it.unit, it.abil, false)
			if next != nil {
				next.prev = it.prev
			}
			if prev := it.prev; prev != nil {
				prev.next = it.next
			} else {
				execAbilHead = it.next
			}
			*it = execAbilityClass{}
		}
	}
}

//export nox_xxx_playerCancelAbils_4FC180
func nox_xxx_playerCancelAbils_4FC180(cu *nox_object_t) {
	s := noxServer
	if cu == nil {
		return
	}
	u := asUnitC(cu)
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	ud := u.updateDataPlayer()
	pl := ud.Player()
	if pl.PlayerClass() != player.Warrior {
		return
	}
	for i := abilityInvalid; i < abilityMax; i++ {
		abilityCooldowns[pl.Index()][i] = 0
	}
	s.netAbilReset(u, 6)
	var next *execAbilityClass
	for it := execAbilHead; it != nil; it = next {
		next = it.next
		if it.unit == u {
			s.netAbilReportActive(it.unit, it.abil, false)
			if next != nil {
				next.prev = it.prev
			}
			if prev := it.prev; prev != nil {
				prev.next = it.next
			} else {
				execAbilHead = it.next
			}
			*it = execAbilityClass{}
		}
	}
}

//export sub_4FC300
func sub_4FC300(cu *nox_object_t, a2 int) {
	s := noxServer
	if cu == nil {
		return
	}
	abil := Ability(a2)
	if !abil.Valid() {
		return
	}
	u := asUnitC(cu)
	switch abil {
	case AbilityHarpoon:
		ud := u.updateDataPlayer()
		s.nox_xxx_netHarpoonBreak_4D98A0(u, asUnitC(ud.harpoon_bolt))
		break
	case AbilityTreadLightly:
		u.DisableEnchant(ENCHANT_SNEAK)
		break
	case AbilityInfravis:
		return
	}
	s.netAbilReportActive(u, abil, false)
	var next *execAbilityClass
	for it := execAbilHead; it != nil; it = next {
		next = it.next
		if it.unit == u && it.abil == abil {
			if next != nil {
				next.prev = it.prev
			}
			if prev := it.prev; prev != nil {
				prev.next = it.next
			} else {
				execAbilHead = it.next
			}
			*it = execAbilityClass{}
		}
	}
}

func nox_xxx_playerInvokeAbility_4FBAF0(u *Unit, abil Ability) {
	if u.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
		return
	}
	switch abil {
	case AbilityBerserk:
		nox_xxx_warriorBerserker_53FEB0(u)
	case AbilityWarcry:
		nox_xxx_warriorWarcry_53FF40(u)
	case AbilityHarpoon:
		nox_xxx_warriorHarpoon_540070(u)
	case AbilityTreadLightly:
		nox_xxx_warriorTreadLightly_5400B0(u, getAbilityDur(abil))
	case AbilityInfravis:
		nox_xxx_warriorInfravis_540110(u, getAbilityDur(abil))
	}
}

//export sub_4FC030
func sub_4FC030(a1 *nox_object_t, a2 C.int) C.int {
	u := asUnitC(a1)
	abil := Ability(a2)
	for it := execAbilHead; it != nil; it = it.next {
		if it.unit == u && it.abil == abil {
			return C.int(it.frame - gameFrame())
		}
	}
	return -1
}

//export sub_4FC070
func sub_4FC070(a1 *nox_object_t, a2, dt C.int) {
	u := asUnitC(a1)
	abil := Ability(a2)
	for it := execAbilHead; it != nil; it = it.next {
		if it.unit == u && it.abil == abil {
			it.frame = gameFrame() + uint32(dt)
			break
		}
	}
}

//export nox_common_playerIsAbilityActive_4FC250
func nox_common_playerIsAbilityActive_4FC250(a1 *nox_object_t, a2 C.int) C.int {
	return C.int(bool2int(isAbilityActive(asUnitC(a1), Ability(a2))))
}

//export nox_xxx_probablyWarcryCheck_4FC3E0
func nox_xxx_probablyWarcryCheck_4FC3E0(a1 *nox_object_t, a2 C.int) C.int {
	return C.int(bool2int(isAbilityActiveVal(asUnitC(a1), Ability(a2))))
}

func isAbilityActive(u *Unit, abil Ability) bool {
	if !u.Class().Has(object.ClassPlayer) {
		return false
	}
	if pl := u.ControllingPlayer(); pl != nil {
		if pl.PlayerClass() != player.Warrior {
			return false
		}
	}
	for it := execAbilHead; it != nil; it = it.next {
		if it.unit == u && it.abil == abil {
			return true
		}
	}
	return false
}

func isAbilityActiveVal(u *Unit, abil Ability) bool {
	if !u.Class().Has(object.ClassPlayer) {
		return false
	}
	if pl := u.ControllingPlayer(); pl != nil {
		if pl.PlayerClass() != player.Warrior {
			return false
		}
	}
	for it := execAbilHead; it != nil; it = it.next {
		if it.unit == u && it.abil == abil {
			return it.active != 0
		}
	}
	return false
}

//export nox_xxx_playerIsExecutingAbility_4FC2B0
func nox_xxx_playerIsExecutingAbility_4FC2B0(a1 *nox_object_t) C.int {
	u := asUnitC(a1)
	if !u.Class().Has(object.ClassPlayer) {
		return 0
	}
	if pl := u.ControllingPlayer(); pl != nil {
		if pl.PlayerClass() != player.Warrior {
			return 0
		}
	}
	for it := execAbilHead; it != nil; it = it.next {
		if it.unit == u {
			return 1
		}
	}
	return 0
}

//export nox_xxx_netAbilRepotState_4D8100
func nox_xxx_netAbilRepotState_4D8100(a1 *nox_object_t, a2, a3 C.char) {
	noxServer.netAbilReportState(asUnitC(a1), Ability(a2), byte(a3))
}

func (s *Server) netAbilReportActive(u *Unit, abil Ability, active bool) {
	if u.Class().Has(object.ClassPlayer) {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_REPORT_ACTIVE_ABILITIES)
		buf[1] = byte(abil)
		buf[2] = byte(bool2int(active))
		pl := u.ControllingPlayer()
		s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:3], 0, 1)
	}
}

func (s *Server) netAbilReportState(u *Unit, abil Ability, st byte) {
	if u.Class().Has(object.ClassPlayer) {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_REPORT_ABILITY_STATE)
		buf[1] = byte(abil)
		buf[2] = st
		pl := u.ControllingPlayer()
		s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:3], 0, 1)
	}
}

func (s *Server) netAbilReset(u *Unit, abil Ability) {
	if u.Class().Has(object.ClassPlayer) {
		pl := u.ControllingPlayer()
		var buf [2]byte
		buf[0] = byte(noxnet.MSG_RESET_ABILITIES)
		buf[1] = byte(abil)
		s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:2], 0, 1)
	}
}

//export sub_4FC440
func sub_4FC440(a1 *nox_object_t, a2 C.int) {
	u := asUnitC(a1)
	abil := Ability(a2)
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	if pl := u.ControllingPlayer(); pl != nil {
		if pl.PlayerClass() != player.Warrior {
			return
		}
	}
	for it := execAbilHead; it != nil; it = it.next {
		if it.unit == u && it.abil == abil {
			it.active = 0
			break
		}
	}
}

//export nox_xxx_abilityGetName_425250
func nox_xxx_abilityGetName_425250(a1 C.int) *C.char {
	return internCStr(Ability(a1).String())
}

//export sub_4FBE60
func sub_4FBE60(a1 unsafe.Pointer, abil C.int) C.int {
	pl := noxServer.getPlayerByID(int(*(*int32)(unsafe.Add(a1, 36))))
	if pl == nil {
		return 0
	}
	return C.int(abilityCooldowns[pl.Index()][abil])
}

//export sub_4FBEA0
func sub_4FBEA0(a1 unsafe.Pointer, abil, cd C.int) {
	pl := noxServer.getPlayerByID(int(*(*int32)(unsafe.Add(a1, 36))))
	if pl == nil {
		return
	}
	abilityCooldowns[pl.Index()][abil] = int(cd)
}

func nox_thing_read_ABIL_415750(f *MemFile) error {
	n := int(f.ReadI32())
	if n <= 0 {
		return nil
	}
	for i := 0; i < n; i++ {
		if err := nox_thing_read_ABIL_rec_424F00(f); err != nil {
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

func nox_thing_read_ABIL_rec_424F00(f *MemFile) error {
	s := noxServer
	id, err := f.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read ability: %w", err)
	}
	abil := nox_xxx_abilityNameToN_424D80(id)
	if !abil.Valid() {
		return fmt.Errorf("unsupported ability: %q", id)
	}
	def := &abilityDefs[abil]
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
	def.name = s.Strings().GetStringInFile(strman.ID(sid), "ComAblty.c")
	sid, err = f.ReadString16()
	if err != nil {
		return fmt.Errorf("cannot read ability name: %w", err)
	}
	def.desc = s.Strings().GetStringInFile(strman.ID(sid), "ComAblty.c")
	str, err := f.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read ability sound: %w", err)
	}
	def.sound40 = nox_xxx_utilFindSound_40AF50(str)
	str, err = f.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read ability sound: %w", err)
	}
	def.sound44 = nox_xxx_utilFindSound_40AF50(str)
	str, err = f.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read ability sound: %w", err)
	}
	def.sound48 = nox_xxx_utilFindSound_40AF50(str)
	def.field20 = 1
	def.field24 = 1
	return nil
}

//export nox_xxx_loadWariorParams_424DF0
func nox_xxx_loadWariorParams_424DF0() {
	abilityDefs[AbilityBerserk].delay = int(gamedataFloat("BerserkerChargeDelay"))
	abilityDefs[AbilityBerserk].duration = int(gamedataFloat("BerserkerChargeDuration"))
	abilityDefs[AbilityWarcry].delay = int(gamedataFloat("WarcryDelay"))
	abilityDefs[AbilityWarcry].duration = int(gamedataFloat("WarCryDuration"))
	abilityDefs[AbilityHarpoon].delay = int(gamedataFloat("HarpoonDelay"))
	abilityDefs[AbilityHarpoon].duration = int(gamedataFloat("HarpoonDuration"))
	abilityDefs[AbilityTreadLightly].delay = int(gamedataFloat("TreadLightlyDelay"))
	abilityDefs[AbilityTreadLightly].duration = int(gamedataFloat("TreadLightlyDuration"))
	abilityDefs[AbilityInfravis].delay = int(gamedataFloat("EyeOfTheWolfDelay"))
	abilityDefs[AbilityInfravis].duration = int(gamedataFloat("EyeOfTheWolfDuration"))
}

func getAbilitySound(abil Ability, snd int) int {
	p := &abilityDefs[abil]
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

func getAbilityDur(abil Ability) int {
	return abilityDefs[abil].duration
}

//export nox_xxx_abilityGetName_0_425260
func nox_xxx_abilityGetName_0_425260(ca C.int) *wchar_t {
	abil := Ability(ca)
	if !abil.Valid() {
		return nil
	}
	if abilityDefs[abil].field24 == 0 {
		return nil
	}
	return internWStr(abilityDefs[abil].name)
}

//export nox_xxx_abilityCooldown_4252D0
func nox_xxx_abilityCooldown_4252D0(ca C.int) C.int {
	return C.int(abilityCooldown(Ability(ca)))
}

func abilityCooldown(abil Ability) int {
	if !abil.Valid() {
		return 0
	}
	return abilityDefs[abil].delay
}

//export sub_4252F0
func sub_4252F0(ca C.int) *wchar_t {
	abil := Ability(ca)
	if !abil.Valid() {
		return nil
	}
	return internWStr(abilityDefs[abil].desc)
}

//export nox_xxx_spellGetAbilityIcon_425310
func nox_xxx_spellGetAbilityIcon_425310(abil, icon C.int) *nox_video_bag_image_t {
	p := &abilityDefs[abil]
	switch icon {
	case 0:
		return p.icon8.C()
	case 1:
		return p.icon12.C()
	case 2:
		return p.icon16.C()
	}
	return nil
}

//export nox_xxx_bookFirstKnownAbil_425330
func nox_xxx_bookFirstKnownAbil_425330() C.int {
	for i := abilityInvalid + 1; i < abilityMax; i++ {
		if abilityDefs[i].field24 != 0 {
			return C.int(i)
		}
	}
	return 0
}

//export nox_xxx_bookNextKnownAbil_425350
func nox_xxx_bookNextKnownAbil_425350(a1 C.int) C.int {
	for i := Ability(a1) + 1; i < abilityMax; i++ {
		if abilityDefs[i].field24 != 0 {
			return C.int(i)
		}
	}
	return 0
}

//export sub_425450
func sub_425450(a1 C.int) C.int {
	return C.int(abilityDefs[a1].field36)
}
