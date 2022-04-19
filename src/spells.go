package opennox

/*
#include "defs.h"
#include "server__magic__plyrspel.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5_2.h"
#include "server__magic__spell__execdur.h"
void nox_xxx_spellCastByBook_4FCB80();
void nox_xxx_spellCastByPlayer_4FEEF0();

static int nox_spells_call_intint6_go(int (*f)(int, void*, nox_object_t*, nox_object_t*, void*, int), int a1, nox_object_t* a2, nox_object_t* a3, nox_object_t* a4, void* a5, int a6) { return f(a1, a2, a3, a4, a5, a6); }
*/
import "C"
import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	spellPhonemeTree   *phonemeLeaf
	noxSpellMissileTyp = make(map[things.SpellID]int) // map[spellID]typeID, 0x5D4594, 2489136
)

type serverSpells struct {
	byID     map[things.SpellID]*SpellDef
	allowAll bool // a cheat to allow all spells
}

var _ = [1]struct{}{}[40-unsafe.Sizeof(phonemeLeaf{})]

type phonemeLeaf struct {
	Ind int32
	Pho [things.PhonMax]*phonemeLeaf
}

//export nox_xxx_spellGetDefArrayPtr_424820
func nox_xxx_spellGetDefArrayPtr_424820() unsafe.Pointer {
	return unsafe.Pointer(getPhonemeTree())
}

func getPhonemeTree() *phonemeLeaf {
	if spellPhonemeTree == nil {
		spellPhonemeTree, _ = alloc.New(phonemeLeaf{})
	}
	return spellPhonemeTree
}

const noxSpellsMax = int(C.NOX_SPELLS_MAX)

//export nox_xxx_spellNameByN_424870
func nox_xxx_spellNameByN_424870(ind C.int) *C.char {
	s := things.SpellID(ind).String()
	if s == "" {
		return nil
	}
	return internCStr(s)
}

//export nox_xxx_spellNameToN_4243F0
func nox_xxx_spellNameToN_4243F0(cid *C.char) C.int {
	id := GoString(cid)
	ind := things.ParseSpellID(id)
	if ind <= 0 {
		return 0
	}
	return C.int(ind)
}

//export nox_xxx_spellAwardAll1_4EFD80
func nox_xxx_spellAwardAll1_4EFD80(p *C.nox_playerInfo) {
	serverSetAllBeastScrolls(asPlayer(p), noxflags.HasEngine(noxflags.EngineAdmin))
}

//export nox_xxx_spellAwardAll2_4EFC80
func nox_xxx_spellAwardAll2_4EFC80(p *C.nox_playerInfo) {
	serverSetAllSpells(asPlayer(p), noxflags.HasEngine(noxflags.EngineAdmin), 0)
}

//export nox_xxx_spellAwardAll3_4EFE10
func nox_xxx_spellAwardAll3_4EFE10(p *C.nox_playerInfo) {
	serverSetAllWarriorAbilities(asPlayer(p), noxflags.HasEngine(noxflags.EngineAdmin), 0)
}

//export nox_xxx_spellFlySearchTarget_540610
func nox_xxx_spellFlySearchTarget_540610(cpos *C.float2, msl *nox_object_t, sflags C.int, dist C.float, a5 C.int, self *nox_object_t) *nox_object_t {
	var pos *types.Pointf
	if cpos != nil {
		pos = &types.Pointf{X: float32(cpos.field_0), Y: float32(cpos.field_4)}
	}
	return nox_xxx_spellFlySearchTarget(pos, asObjectC(msl), things.SpellFlags(sflags), float32(dist), int(a5), asUnitC(self)).CObj()
}

//export nox_xxx_spellGetAud44_424800
func nox_xxx_spellGetAud44_424800(ind, a2 C.int) C.int {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return 0
	}
	return C.int(sp.GetAudio(int(a2)))
}

//export nox_xxx_spellTitle_424930
func nox_xxx_spellTitle_424930(ind C.int) *wchar_t {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil || !sp.IsValid() {
		return nil
	}
	return internWStr(sp.Title)
}

//export nox_xxx_spellDescription_424A30
func nox_xxx_spellDescription_424A30(ind C.int) *wchar_t {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return nil
	}
	return internWStr(sp.Desc)
}

//export nox_xxx_spellByTitle_424960
func nox_xxx_spellByTitle_424960(ctitle *wchar_t) C.int {
	title := GoWString(ctitle)
	for i := 1; i < noxSpellsMax; i++ {
		if noxServer.SpellDefByInd(things.SpellID(i)).Title == title {
			return C.int(i)
		}
	}
	return 0
}

//export nox_xxx_spellManaCost_4249A0
func nox_xxx_spellManaCost_4249A0(ind, a2 C.int) C.int {
	id := things.SpellID(ind)
	if !id.Valid() {
		return 0
	}
	if a2 == 2 {
		switch ind {
		case 24:
			return C.int(gamedataFloat("EnergyBoltTrapCost"))
		case 43:
			return C.int(gamedataFloat("LightningTrapCost"))
		case 56:
			return C.int(gamedataFloat("ManaBombTrapCost"))
		}
	}
	sp := noxServer.SpellDefByInd(id)
	return C.int(sp.Def.ManaCost)
}

//export nox_xxx_spellPhonemes_424A20
func nox_xxx_spellPhonemes_424A20(ind, ind2 C.int) C.char {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return 0
	}
	list := sp.Def.Phonemes
	if ind2 < 0 || int(ind2) >= len(list) {
		return 0
	}
	return C.char(list[ind2])
}

//export nox_xxx_spellHasFlags_424A50
func nox_xxx_spellHasFlags_424A50(ind, flags C.int) C.bool {
	return C.bool(noxServer.spellHasFlags(things.SpellID(ind), things.SpellFlags(flags)))
}

//export nox_xxx_spellFlags_424A70
func nox_xxx_spellFlags_424A70(ind C.int) C.uint {
	return C.uint(noxServer.spellFlags(things.SpellID(ind)))
}

//export nox_xxx_spellIcon_424A90
func nox_xxx_spellIcon_424A90(ind C.int) unsafe.Pointer {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return nil
	}
	return unsafe.Pointer(sp.Icon.C())
}

//export nox_xxx_spellIconHighlight_424AB0
func nox_xxx_spellIconHighlight_424AB0(ind C.int) unsafe.Pointer {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return nil
	}
	return unsafe.Pointer(sp.IconEnabled.C())
}

//export nox_xxx_spellFirstValid_424AD0
func nox_xxx_spellFirstValid_424AD0() C.int {
	for i := 1; i < noxSpellsMax; i++ {
		sp := noxServer.SpellDefByInd(things.SpellID(i))
		if sp.IsValid() {
			return C.int(i)
		}
	}
	return 0
}

//export nox_xxx_spellNextValid_424AF0
func nox_xxx_spellNextValid_424AF0(ind C.int) C.int {
	ind++
	if ind <= 0 || int(ind) >= noxSpellsMax {
		return 0
	}
	for i := int(ind); i < noxSpellsMax; i++ {
		sp := noxServer.SpellDefByInd(things.SpellID(i))
		if sp.IsValid() {
			return C.int(i)
		}
	}
	return 0
}

//export nox_xxx_spellIsValid_424B50
func nox_xxx_spellIsValid_424B50(ind C.int) C.bool {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return false
	}
	return C.bool(sp.Valid)
}

//export nox_xxx_spellIsEnabled_424B70
func nox_xxx_spellIsEnabled_424B70(ind C.int) C.bool {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return false
	}
	return C.bool(sp.Enabled)
}

//export nox_xxx_spellEnable_424B90
func nox_xxx_spellEnable_424B90(ind C.int) C.bool {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return false
	}
	sp.Enabled = true
	return true
}

//export nox_xxx_spellDisable_424BB0
func nox_xxx_spellDisable_424BB0(ind C.int) C.bool {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return false
	}
	sp.Enabled = false
	return true
}

//export nox_xxx_spellCanUseInTrap_424BF0
func nox_xxx_spellCanUseInTrap_424BF0(ind C.int) C.bool {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return false
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && ind == 4 {
		return false
	}
	return C.bool(!sp.Def.Flags.Has(things.SpellNoTrap))
}

//export nox_xxx_spellPrice_424C40
func nox_xxx_spellPrice_424C40(ind C.int) C.int {
	sp := noxServer.SpellDefByInd(things.SpellID(ind))
	if sp == nil {
		return 0
	}
	price := float64(sp.Def.Price)
	if noxflags.HasGame(noxflags.GameModeQuest) {
		price *= gamedataFloat("QuestSpellWorthMultiplier")
	}
	return C.int(price)
}

//export nox_xxx_spellEnableAll_424BD0
func nox_xxx_spellEnableAll_424BD0() {
	noxServer.spellEnableAll()
}

func (s *Server) spellEnableAll() {
	for _, sp := range s.spells.byID {
		sp.Enabled = true
	}
}

func (s *Server) nox_thing_read_SPEL_4156B0(f *MemFile, isClient bool) error {
	const yamlFile = "spells.yml"
	spells, err := things.ReadSpellsYAML(datapath.Data(yamlFile))
	if os.IsNotExist(err) {
		// no new file - read bag instead
		br := bufio.NewReader(f)
		spells, err = things.ReadSpellsSection(br)
		if n := br.Buffered(); n != 0 {
			f.Seek(-int64(n), io.SeekCurrent)
		}
		if err != nil {
			return err
		}
	} else if err == nil {
		// ok, need to skip bag section
		br := bufio.NewReader(f)
		err = things.SkipSpellsSection(br)
		if n := br.Buffered(); n != 0 {
			f.Seek(-int64(n), io.SeekCurrent)
		}
		if err != nil {
			return err
		}
	} else {
		return err
	}
	if os.Getenv("NOX_DUMP_SPELLS") == "true" {
		// generate default configs for OpenNox spell extensions
		for i := range spells {
			sp := &spells[i]
			switch sp.ID {
			case "SPELL_MAGIC_MISSILE":
				if sp.Missiles == nil {
					sp.Missiles = new(things.MissilesSpellConf)
					sp.Missiles.SetDefaults()
				}
			}
		}
		if err := things.WriteSpellsYAML(yamlFile, spells); err != nil {
			return err
		}
	}
	for _, sp := range spells {
		if err := s.createSpellFrom(&sp, isClient); err != nil {
			return err
		}
	}
	return nil
}

func (s *Server) createSpellFrom(def *things.Spell, isClient bool) error {
	ind := things.ParseSpellID(def.ID)
	if ind <= 0 {
		return fmt.Errorf("unsupported spell: %q", def.ID)
	}
	const strFile = "speltree.c"
	sp := &SpellDef{
		Def:       *def,
		ID:        ind,
		Effect:    ind,
		Enabled:   true,
		Valid:     true,
		Title:     s.Strings().GetStringInFile(def.Title, strFile),
		Desc:      s.Strings().GetStringInFile(def.Desc, strFile),
		CastSound: nox_xxx_utilFindSound_40AF50(def.CastSound),
		OnSound:   nox_xxx_utilFindSound_40AF50(def.OnSound),
		OffSound:  nox_xxx_utilFindSound_40AF50(def.OffSound),
	}
	if def.Effect != "" {
		if eff := things.ParseSpellID(def.Effect); eff > 0 {
			sp.Effect = eff
		}
	}
	if s.spells.byID == nil {
		s.spells.byID = make(map[things.SpellID]*SpellDef)
	}
	s.spells.byID[ind] = sp
	if len(sp.Def.Phonemes) != 0 {
		leaf := getPhonemeTree()
		for _, ph := range sp.Def.Phonemes {
			next := leaf.Pho[ph]
			if next == nil {
				next, _ = alloc.New(phonemeLeaf{})
				leaf.Pho[ph] = next
			}
			leaf = next
		}
		leaf.Ind = int32(ind)
		sp.Def.Phonemes = append(sp.Def.Phonemes, things.PhonEnd)
	}
	if isClient {
		sp.Icon = thingsImageRef(sp.Def.Icon)
		sp.IconEnabled = thingsImageRef(sp.Def.IconEnabled)
	}
	return nil
}

func (s *Server) spellHasFlags(ind things.SpellID, flag things.SpellFlags) bool {
	return s.spellFlags(ind).Has(flag)
}

func (s *Server) spellFlags(ind things.SpellID) things.SpellFlags {
	sp := s.SpellDefByInd(ind)
	if sp == nil {
		return 0
	}
	flags := sp.Def.Flags
	if s.spells.allowAll {
		flags |= things.SpellClassAny
	}
	return flags
}

func serverSetAllBeastScrolls(p *Player, enable bool) {
	lvl := 0
	if enable {
		lvl = 1
	}
	C.nox_xxx_playerResetProtectionCRC_56F7D0(C.int(*(*uintptr)(p.field(4640))), 0)
	for i := 1; i < len(p.beast_scroll_lvl); i++ {
		p.beast_scroll_lvl[i] = C.uint(lvl)
		C.nox_xxx_playerAwardSpellProtectionCRC_56FCE0(C.int(*(*uintptr)(p.field(4640))), C.int(i), C.int(lvl))
	}
	C.nox_xxx_playerApplyProtectionCRC_56FD50(C.int(*(*uintptr)(p.field(4640))), unsafe.Pointer(&p.beast_scroll_lvl[0]), C.int(len(p.beast_scroll_lvl)))
}

func serverSetAllSpells(p *Player, enable bool, max int) {
	lvl := 0
	if enable {
		lvl = max
		if max <= 0 {
			lvl = 3
		}
	}
	C.nox_xxx_playerResetProtectionCRC_56F7D0(C.int(*(*uintptr)(p.field(4636))), 0)
	// set max level for all possible spells
	// the engine will automatically allow only ones that have WIS_USE, CON_USE or COMMON_USE set
	for i := 1; i < len(p.spell_lvl); i++ {
		p.spell_lvl[i] = C.uint(lvl)
		C.nox_xxx_playerAwardSpellProtectionCRC_56FCE0(C.int(*(*uintptr)(p.field(4636))), C.int(i), C.int(lvl))
	}
	if !enable && noxflags.HasGame(noxflags.GameModeQuest) {
		u := p.UnitC()
		// grant default spells for Quest when disabling the cheat
		switch p.PlayerClass() {
		case player.Wizard:
			C.nox_xxx_spellGrantToPlayer_4FB550(u.CObj(), C.int(things.SPELL_FIREBALL), 1, 1, 1)
		case player.Conjurer:
			C.nox_xxx_spellGrantToPlayer_4FB550(u.CObj(), C.int(things.SPELL_CHARM), 1, 1, 1)
			C.nox_xxx_spellGrantToPlayer_4FB550(u.CObj(), C.int(things.SPELL_LESSER_HEAL), 1, 1, 1)
		}
	}
	C.nox_xxx_playerApplyProtectionCRC_56FD50(C.int(*(*uintptr)(p.field(4636))), unsafe.Pointer(&p.spell_lvl[0]), C.int(len(p.spell_lvl)))
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
		p.spell_lvl[i] = C.uint(lvl)
		C.nox_xxx_playerAwardSpellProtectionCRC_56FCE0(C.int(*(*uintptr)(p.field(4636))), C.int(i), C.int(lvl))
	}
}

func nox_xxx_spellBookReact_4FCB70() {
	C.nox_xxx_spellCastByBook_4FCB80()
	C.nox_xxx_spellCastByPlayer_4FEEF0()
}

func (s *Server) SpellDefs() []*SpellDef {
	out := make([]*SpellDef, 0, noxSpellsMax)
	for _, sp := range s.spells.byID {
		if sp != nil {
			out = append(out, sp)
		}
	}
	sort.Slice(out, func(i, j int) bool {
		return out[i].ID < out[j].ID
	})
	return out
}

func (s *Server) SpellDefByInd(i things.SpellID) *SpellDef {
	if i <= 0 {
		return nil
	}
	return s.spells.byID[i]
}

func SpellIDs() []string {
	out := make([]string, 0, noxSpellsMax)
	for i := 1; i < noxSpellsMax; i++ {
		out = append(out, things.SpellID(i).String())
	}
	return out
}

type SpellDef struct {
	Def         things.Spell
	ID          things.SpellID // the ID of the spell itself, used to index it
	Effect      things.SpellID // the ID of the spell effect function
	Enabled     bool
	Valid       bool
	Title       string
	Desc        string
	Icon        *Image
	IconEnabled *Image
	CastSound   int
	OnSound     int
	OffSound    int
}

func (s *SpellDef) IsValid() bool {
	return s != nil && s.Valid
}

func (s *SpellDef) GetAudio(snd int) int { // nox_xxx_spellGetAud44_424800
	if s == nil {
		return 0
	}
	switch snd {
	case 0:
		return s.CastSound
	case 1:
		return s.OnSound
	case 2:
		return s.OffSound
	}
	return 0
}

type spellAcceptArg struct {
	Obj  *nox_object_t
	Arg1 float32
	Arg2 float32
}

//export nox_xxx_spellAccept_4FD400
func nox_xxx_spellAccept_4FD400(ispellID C.int, a2, a3p, a4p, a5p unsafe.Pointer, lvli C.int) C.int {
	if nox_xxx_spellAccept4FD400(things.SpellID(ispellID), asUnit(a2), asUnit(a3p), asUnit(a4p), (*spellAcceptArg)(a5p), int(lvli)) {
		return 1
	}
	return 0
}

func nox_xxx_spellAccept4FD400(spellID things.SpellID, a2, obj3, obj4 *Unit, arg5 *spellAcceptArg, lvl int) bool {
	if spellID == 0 {
		return false
	}
	if obj3 == nil {
		return false
	}
	if a2 == nil {
		return false
	}
	if arg5 == nil {
		return false
	}
	obj5 := asUnitC(arg5.Obj)
	sp := noxServer.SpellDefByInd(spellID)
	if noxServer.spellHasFlags(spellID, things.SpellFlagUnk8) && obj5 != nil && !obj5.Class().Has(object.MaskUnits) {
		return false
	}
	if !(obj5 == nil || C.nox_xxx_gameCaptureMagic_4FDC10(C.int(spellID), obj5.CObj()) != 0) {
		nox_xxx_aud_501960(231, obj5, 0, 0)
		return false
	}
	var (
		fnc  func(spellID things.SpellID, a2, a3, a4 *Unit, a5 *spellAcceptArg, lvl int) int
		cfnc unsafe.Pointer
	)
	effectID := sp.Effect
	switch effectID {
	case things.SPELL_ANCHOR:
		cfnc = C.nox_xxx_castAnchor_52C390
	case things.SPELL_ARACHNAPHOBIA:
		cfnc = C.nox_xxx_spellArachna_52DC80
	case things.SPELL_BLIND:
		cfnc = C.sub_52C750
	case things.SPELL_BLINK:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_spellBlink2_530310, C.nox_xxx_spellBlink1_530380, nil, 0)
	case things.SPELL_BURN:
		cfnc = C.nox_xxx_castBurn_52C3E0
	case things.SPELL_CHANNEL_LIFE:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, nil, C.sub_52F460, nil, 0)
	case things.SPELL_CHARM:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_charmCreature1_5011F0, C.nox_xxx_charmCreatureFinish_5013E0, C.nox_xxx_charmCreature2_501690, 0)
	case things.SPELL_CLEANSING_FLAME, things.SPELL_CLEANSING_MANA_FLAME:
		cfnc = C.nox_xxx_spellCastCleansingFlame_52D5C0
	case things.SPELL_CONFUSE:
		cfnc = C.nox_xxx_castConfuse_52C1E0
	case things.SPELL_COUNTERSPELL:
		cfnc = C.nox_xxx_castCounterSpell_52BBB0
	case things.SPELL_CURE_POISON:
		cfnc = C.nox_xxx_castCurePoison_52CDB0
	case things.SPELL_DEATH:
		cfnc = C.nox_xxx_castDeath_52C920
	case things.SPELL_DEATH_RAY:
		cfnc = C.nox_xxx_castDeathRay_52D1E0
	case things.SPELL_DETECT_MAGIC:
		cfnc = C.sub_52C8D0
	case things.SPELL_DETONATE_GLYPHS:
		cfnc = C.sub_537E60
	case things.SPELL_TURN_UNDEAD:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_spellTurnUndeadCreate_531310, C.nox_xxx_spellTurnUndeadUpdate_531410, C.nox_xxx_spellTurnUndeadDelete_531420, 70)
	case things.SPELL_DRAIN_MANA:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, nil, C.nox_xxx_spellDrainMana_52E210, nil, 0)
	case things.SPELL_EARTHQUAKE:
		cfnc = C.nox_xxx_castEquake_52DE40
	case things.SPELL_LIGHTNING:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_spellEnergyBoltStop_52E820, C.nox_xxx_spellEnergyBoltTick_52E850, C.nullsub_29, 30)
	case things.SPELL_FEAR:
		cfnc = C.nox_xxx_castFear_52DF40
	case things.SPELL_FIREBALL:
		cfnc = C.nox_xxx_castFireball_52C790
	case things.SPELL_FIREWALK:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, nil, C.nox_xxx_firewalkTick_52ED40, nil, 3*gameFPS())
	case things.SPELL_FIST:
		cfnc = C.nox_xxx_castFist_52D3C0
	case things.SPELL_FORCE_OF_NATURE:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.sub_52EF30, C.sub_52EFD0, C.sub_52F1D0, 2*gameFPS()/3)
	case things.SPELL_FREEZE:
		cfnc = C.nox_xxx_castFreeze_52C350
	case things.SPELL_FUMBLE:
		cfnc = C.nox_xxx_castFumble_52C060
	case things.SPELL_GLYPH:
		cfnc = C.nox_xxx_castGlyph_537FA0
	case things.SPELL_GREATER_HEAL:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.sub_52F220, C.sub_52F2E0, nil, 0)
	case things.SPELL_HASTE:
		cfnc = C.nox_xxx_castHaste_52C640
	case things.SPELL_INFRAVISION:
		cfnc = C.nox_xxx_castInfra_52CA30
	case things.SPELL_INVERSION:
		cfnc = C.sub_52BEB0
	case things.SPELL_INVISIBILITY:
		cfnc = C.nox_xxx_castInvis_52C980
	case things.SPELL_INVULNERABILITY:
		cfnc = C.nox_xxx_castInvul_52C9E0
	case things.SPELL_LESSER_HEAL:
		cfnc = C.sub_52DD50
	case things.SPELL_LIGHT:
		cfnc = C.nox_xxx_castLight_52C6D0
	case things.SPELL_CHAIN_LIGHTNING:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_onStartLightning_52F820, C.nox_xxx_onFrameLightning_52F8A0, C.sub_530100, 30)
	case things.SPELL_LOCK:
		cfnc = C.nox_xxx_castLock_52CE90
	case things.SPELL_MARK:
		cfnc = C.sub_52CA80
	case things.SPELL_MARK_1, things.SPELL_MARK_2, things.SPELL_MARK_3, things.SPELL_MARK_4:
		cfnc = C.sub_52CBD0
	case things.SPELL_MAGIC_MISSILE:
		fnc = nox_xxx_castMissilesOM_540160
	case things.SPELL_SHIELD:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj5, obj4, arg5, lvl, C.nox_xxx_castShield1_52F5A0, C.sub_52F650, C.sub_52F670, 0)
	case things.SPELL_METEOR:
		cfnc = C.nox_xxx_castMeteor_52D9D0
	case things.SPELL_METEOR_SHOWER:
		cfnc = C.nox_xxx_castMeteorShower_52D8A0
	case things.SPELL_MOONGLOW:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj5, obj4, arg5, lvl, C.nox_xxx_spellCreateMoonglow_531A00, nil, C.sub_531AF0, 0)
	case things.SPELL_NULLIFY:
		cfnc = C.sub_52C230
	case things.SPELL_MANA_BOMB:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_manaBomb_530F90, C.nox_xxx_manaBombBoom_5310C0, C.sub_531290, 0)
	case things.SPELL_PIXIE_SWARM:
		cfnc = C.nox_xxx_castPixies_540440
	case things.SPELL_PLASMA:
		v8 := gamedataFloat("PlasmaSearchTime")
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_plasmaSmth_531580, C.nox_xxx_plasmaShot_531600, C.sub_5319E0, uint32(v8))
	case things.SPELL_POISON:
		cfnc = C.nox_xxx_castPoison_52C720
	case things.SPELL_PROTECTION_FROM_ELECTRICITY:
		cfnc = C.nox_xxx_castProtectElect_52D150
	case things.SPELL_PROTECTION_FROM_FIRE:
		cfnc = C.nox_xxx_castProtectFire_52D110
	case things.SPELL_PROTECTION_FROM_POISON:
		cfnc = C.nox_xxx_castProtectPosion_52D1A0
	case things.SPELL_PULL:
		cfnc = C.nox_xxx_castPull_52BFA0
	case things.SPELL_PUSH:
		cfnc = C.nox_xxx_castPush_52C000
	case things.SPELL_OVAL_SHIELD:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj5, obj4, arg5, lvl, C.sub_531490, C.sub_5314F0, C.sub_531560, 0)
	case things.SPELL_RESTORE_HEALTH, things.SPELL_WINK:
		cfnc = C.nox_xxx_castSpellWinkORrestoreHealth_52BF20
	case things.SPELL_RESTORE_MANA:
		cfnc = C.sub_52BF50
	case things.SPELL_RUN:
		cfnc = C.nox_xxx_castRun_52C680
	case things.SPELL_SHOCK:
		cfnc = C.nox_xxx_useShock_52C5A0
	case things.SPELL_SLOW:
		cfnc = C.nox_xxx_castSlow_52C190
	case things.SPELL_STUN:
		cfnc = C.nox_xxx_castStun_52C2C0
	case things.SPELL_SUMMON_BAT,
		things.SPELL_SUMMON_BLACK_BEAR,
		things.SPELL_SUMMON_BEAR,
		things.SPELL_SUMMON_BEHOLDER,
		things.SPELL_SUMMON_CARNIVOROUS_PLANT,
		things.SPELL_SUMMON_ALBINO_SPIDER,
		things.SPELL_SUMMON_SMALL_ALBINO_SPIDER,
		things.SPELL_SUMMON_EVIL_CHERUB,
		things.SPELL_SUMMON_EMBER_DEMON,
		things.SPELL_SUMMON_GHOST,
		things.SPELL_SUMMON_GIANT_LEECH,
		things.SPELL_SUMMON_IMP,
		things.SPELL_SUMMON_MECHANICAL_FLYER,
		things.SPELL_SUMMON_MECHANICAL_GOLEM,
		things.SPELL_SUMMON_MIMIC,
		things.SPELL_SUMMON_OGRE,
		things.SPELL_SUMMON_OGRE_BRUTE,
		things.SPELL_SUMMON_OGRE_WARLORD,
		things.SPELL_SUMMON_SCORPION,
		things.SPELL_SUMMON_SHADE,
		things.SPELL_SUMMON_SKELETON,
		things.SPELL_SUMMON_SKELETON_LORD,
		things.SPELL_SUMMON_SPIDER,
		things.SPELL_SUMMON_SMALL_SPIDER,
		things.SPELL_SUMMON_SPITTING_SPIDER,
		things.SPELL_SUMMON_STONE_GOLEM,
		things.SPELL_SUMMON_TROLL,
		things.SPELL_SUMMON_URCHIN,
		things.SPELL_SUMMON_WASP,
		things.SPELL_SUMMON_WILLOWISP,
		things.SPELL_SUMMON_WOLF,
		things.SPELL_SUMMON_BLACK_WOLF,
		things.SPELL_SUMMON_WHITE_WOLF,
		things.SPELL_SUMMON_ZOMBIE,
		things.SPELL_SUMMON_VILE_ZOMBIE,
		things.SPELL_SUMMON_DEMON,
		things.SPELL_SUMMON_LICH,
		things.SPELL_SUMMON_DRYAD,
		things.SPELL_SUMMON_URCHIN_SHAMAN:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_summonStart_500DA0, C.nox_xxx_summonFinish_5010D0, C.nox_xxx_summonCancel_5011C0, 0)
	case things.SPELL_SWAP:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.sub_530CA0, C.sub_530D30, nil, 0)
	case things.SPELL_TAG:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_spellTagCreature_530160, C.sub_530250, C.sub_530270, 0)
	case things.SPELL_TELEPORT_OTHER_TO_MARK_1, things.SPELL_TELEPORT_OTHER_TO_MARK_2, things.SPELL_TELEPORT_OTHER_TO_MARK_3, things.SPELL_TELEPORT_OTHER_TO_MARK_4,
		things.SPELL_TELEPORT_TO_MARK_1, things.SPELL_TELEPORT_TO_MARK_2, things.SPELL_TELEPORT_TO_MARK_3, things.SPELL_TELEPORT_TO_MARK_4:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.sub_5305D0, C.sub_530650, nil, 0)
	case things.SPELL_TELEPORT_POP:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_castTele_530820, C.sub_530880, nil, 0)
	case things.SPELL_TELEPORT_TO_TARGET:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.sub_530A30_spell_execdur, C.nox_xxx_castTTT_530B70, nil, 0)
	case things.SPELL_TELEKINESIS:
		cfnc = C.nox_xxx_castTelekinesis_52D330
	case things.SPELL_TOXIC_CLOUD:
		cfnc = C.nox_xxx_castToxicCloud_52DB60
	case things.SPELL_TRIGGER_GLYPH:
		cfnc = C.sub_52CCD0
	case things.SPELL_VAMPIRISM:
		cfnc = C.nox_xxx_castVamp_52C530
	case things.SPELL_VILLAIN:
		cfnc = C.sub_52C270
	case things.SPELL_WALL:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_spellWallCreate_4FFA90, C.nox_xxx_spellWallUpdate_500070, C.nox_xxx_spellWallDestroy_500080, 0)
	default:
		return true
	}
	if cfnc != nil {
		fnc = func(spellID things.SpellID, a2, a3, a4 *Unit, a5 *spellAcceptArg, lvl int) int {
			return int(C.nox_spells_call_intint6_go((*[0]byte)(cfnc), C.int(spellID), a2.CObj(), a3.CObj(), a4.CObj(), unsafe.Pointer(arg5), C.int(lvl)))
		}
	}
	v9 := fnc(spellID, a2, obj3, obj4, arg5, lvl)
	if v9 == 0 {
		nox_xxx_aud_501960(231, obj4, 0, 0)
	}
	return v9 != 0
}

func nox_xxx_spellDurationBased_4FEBA0(spellID things.SpellID, a2, a3, a4 *Unit, a5 *spellAcceptArg, a6 int, a7, a8, a9 unsafe.Pointer, a10 uint32) bool {
	return C.nox_xxx_spellDurationBased_4FEBA0(C.int(spellID), a2.CObj(), a3.CObj(), a4.CObj(), unsafe.Pointer(a5), C.int(a6), a7, a8, a9, C.int(a10)) != 0
}

func (s *Server) castSpellMissilesCustom(spellID things.SpellID, owner, caster *Unit, opts things.MissilesSpell) {
	cpos := caster.Pos()
	cvel := caster.Vel()
	rdist := float32(caster.shape.circle_r) + opts.Offset
	for i := 0; i < opts.Count; i++ {
		doff := int16(opts.Spread * uint16((i+1)/2))
		if i%2 == 1 {
			doff = -doff
		}
		dir := nox_xxx_math_roundDirI16(int16(caster.field_31_0) + doff)
		dirX := memmap.Float32(0x587000, 194136+8*uintptr(dir))
		dirY := memmap.Float32(0x587000, 194140+8*uintptr(dir))
		p2 := types.Pointf{
			X: cpos.X + cvel.X + rdist*dirX,
			Y: cpos.Y + cvel.Y + rdist*dirY,
		}
		tpos, ok := nox_xxx_mapTraceRay_535250_00(cpos, p2, 5)
		if !ok {
			continue
		}
		msl := noxServer.newObjectByTypeID(opts.Projectile)
		mud := msl.updateDataMissile()
		nox_xxx_createAt_4DAA50(msl, owner, tpos)
		mspeed := float32(noxRndCounter1.FloatClamp(opts.SpeedRndMin, opts.SpeedRndMax) * float64(msl.curSpeed()))
		msl.speed_cur = C.float(mspeed)
		msl.setDir(dir)
		msl.setVel(types.Pointf{
			X: cvel.X + mspeed*dirX*opts.VelMult,
			Y: cvel.Y + mspeed*dirY*opts.VelMult,
		})
		var ppos *types.Pointf
		if caster.Class().Has(object.ClassPlayer) {
			pl := caster.ControllingPlayer()
			ppos = &types.Pointf{
				X: float32(pl.field_2284),
				Y: float32(pl.field_2288),
			}
		}
		targ := nox_xxx_spellFlySearchTarget(ppos, msl, 0x20, opts.SearchDist, 0, owner)
		mud.owner = owner.CObj()
		mud.target = targ.CObj()
		mud.spellID = C.int(spellID)
	}
	aud := s.SpellDefByInd(spellID).GetAudio(0)
	nox_xxx_aud_501960(aud, caster, 0, 0)
}

func nox_xxx_castMissilesOM_540160(spellID things.SpellID, a2, owner, caster *Unit, a5 *spellAcceptArg, lvl int) int {
	sp := noxServer.SpellDefByInd(spellID)
	opts := sp.Def.Missiles.Level(lvl)
	typ, ok := noxSpellMissileTyp[spellID]
	if !ok {
		typ = noxServer.getObjectTypeID(opts.Projectile)
		noxSpellMissileTyp[spellID] = typ
	}
	curCnt := owner.countSubOfType(typ)
	var cnt, maxCnt int
	if opts.Count <= 0 {
		// it's intentionally loading this variable twice
		// looks previously there were two separate config values for it
		cnt = int(gamedataFloatInd("MagicMissileCount", lvl-1))
		maxCnt = int(gamedataFloatInd("MagicMissileCount", lvl-1))
	} else {
		cnt, maxCnt = opts.Count, opts.Count
	}
	if curCnt+cnt > maxCnt {
		cnt = maxCnt - curCnt
	}
	if cnt <= 0 {
		C.nox_xxx_netPriMsgToPlayer_4DA2C0(owner.CObj(), internCStr("mmissile.c:TooManyMissiles"), 0)
		return 0
	}
	opts.Count = cnt
	noxServer.castSpellMissilesCustom(spellID, owner, caster, opts)
	return 1
}

func nox_xxx_spellFlySearchTarget(pos *types.Pointf, msl *Object, sflags things.SpellFlags, dist float32, a5 int, self *Unit) *Object {
	if self != nil && self.Class().Has(object.ClassPlayer) && sflags.Has(things.SpellOffensive) {
		if curTarg := self.updateDataPlayer().CursorObj(); curTarg != nil {
			if self.isEnemyTo(curTarg) && ((a5 == 1) || (a5 == 0) && msl != curTarg) {
				return curTarg
			}
		}
	}
	var center types.Pointf
	if pos == nil {
		if msl == nil {
			return nil
		}
		center = msl.Pos()
	} else if msl != nil {
		if _, ok := nox_xxx_mapTraceRay_535250_00(msl.Pos(), *pos, 5); ok {
			center = *pos // TODO: it ignores tay tracing result; intentional?
		} else {
			center = msl.Pos()
		}
	} else {
		center = *pos
	}
	dist2 := dist * dist
	owner := msl.findOwnerChainPlayer()
	rect := types.Rectf{
		Left:   center.X - dist,
		Top:    center.Y - dist,
		Right:  center.X + dist,
		Bottom: center.Y + dist,
	}
	var (
		minDist float32 = 1e+08
		found   *Object
	)
	getUnitsInRect(rect, func(it *Object) {
		if !(a5 != 0 || msl != it) {
			return
		}
		if !it.Class().HasAny(object.MaskTargets) {
			return
		}
		if it.Class().Has(object.ClassMonster) && (it.SubClass()&0x8000 != 0) {
			return
		}
		if it.Class().Has(object.ClassPlayer) && it.AsUnit().ControllingPlayer().field_3680&0x1 != 0 {
			return
		}
		if it.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			return
		}
		if it.Class().Has(object.ClassMonster) && (it.SubClass()&0x4000 != 0) {
			return
		}
		it.findOwnerChainPlayer() // FIXME: result unused!
		if sflags.Has(things.SpellOffensive) && !msl.isEnemyTo(it) {
			return
		}
		opos := it.Pos()
		dx := center.X - opos.X
		dy := center.Y - opos.Y
		odist := dy*dy + dx*dx
		if odist > dist2 {
			return
		}
		if msl != nil && !nox_xxx_unitCanInteractWith_5370E0(msl, it, 0) {
			return
		}
		if owner != nil && !nox_xxx_unitCanInteractWith_5370E0(owner, it, 0) {
			return
		}
		if odist < minDist {
			found = it
			minDist = odist
		}
	})
	return found
}

//export nox_xxx_castSpellByUser_4FDD20
func nox_xxx_castSpellByUser_4FDD20(a1 C.int, a2 *nox_object_t, a3 unsafe.Pointer) C.int {
	if nox_xxx_castSpellByUser4FDD20(things.SpellID(a1), asUnitC(a2), (*spellAcceptArg)(a3)) {
		return 1
	}
	return 0
}

func nox_xxx_castSpellByUser4FDD20(spellInd things.SpellID, u *Unit, a3 *spellAcceptArg) bool {
	lvl := int(C.nox_xxx_spellGetPower_4FE7B0(C.int(spellInd), u.CObj()))
	if noxServer.spellHasFlags(spellInd, things.SpellOffensive) {
		C.nox_xxx_spellBuffOff_4FF5B0(u.CObj(), 0)
		C.nox_xxx_spellBuffOff_4FF5B0(u.CObj(), 23)
		C.nox_xxx_spellCancelDurSpell_4FEB10(67, u.CObj())
	}
	if !noxServer.spellHasFlags(spellInd, things.SpellTargeted) || u.CObj() == a3.Obj {
		return nox_xxx_spellAccept4FD400(spellInd, u, u, u, a3, lvl)
	}
	C.nox_xxx_createSpellFly_4FDDA0(u.CObj(), a3.Obj, C.int(spellInd))
	return true
}
