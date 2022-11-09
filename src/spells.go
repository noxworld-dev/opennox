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

extern void* nox_alloc_magicEnt_1569668;
extern uint32_t dword_5d4594_1569672;

static int nox_spells_call_intint6_go(int (*f)(int, void*, nox_object_t*, nox_object_t*, void*, int), int a1, nox_object_t* a2, nox_object_t* a3, nox_object_t* a4, void* a5, int a6) { return f(a1, a2, a3, a4, a5, a6); }
*/
import "C"
import (
	"errors"
	"fmt"
	"io"
	"os"
	"sort"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	spellPhonemeTree *phonemeLeaf
)

type serverSpells struct {
	byID     map[spell.ID]*SpellDef
	allowAll bool // a cheat to allow all spells
	duration spellsDuration
	missiles spellMissiles
}

func (sp *serverSpells) Init(s *Server) {
	sp.duration.Init(s)
	sp.missiles.Init(s)
}

func (sp *serverSpells) Free() {
	sp.missiles.Free()
	sp.duration.Free()
}

var _ = [1]struct{}{}[40-unsafe.Sizeof(phonemeLeaf{})]

type phonemeLeaf struct {
	Ind int32
	Pho [spell.PhonMax]*phonemeLeaf
}

func (p *phonemeLeaf) Next(ph spell.Phoneme) *phonemeLeaf { // nox_xxx_updateSpellRelated_424830
	if p == nil || !ph.Valid() {
		return nil
	}
	return p.Pho[ph]
}

//export nox_xxx_spellGetDefArrayPtr_424820
func nox_xxx_spellGetDefArrayPtr_424820() unsafe.Pointer {
	return unsafe.Pointer(getPhonemeTree())
}

//export nox_xxx_getEnchantSpell_424920
func nox_xxx_getEnchantSpell_424920(enc C.int) C.int {
	return C.int(server.EnchantID(enc).Spell())
}

//export nox_xxx_getEnchantName_4248F0
func nox_xxx_getEnchantName_4248F0(enc C.int) *C.char {
	return internCStr(server.EnchantID(enc).String())
}

//export nox_xxx_enchantByName_424880
func nox_xxx_enchantByName_424880(cname *C.char) C.int {
	id, ok := server.ParseEnchant(GoString(cname))
	if !ok {
		return -1
	}
	return C.int(id)
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
	s := spell.ID(ind).String()
	if s == "" {
		return nil
	}
	return internCStr(s)
}

//export nox_xxx_spellNameToN_4243F0
func nox_xxx_spellNameToN_4243F0(cid *C.char) C.int {
	id := GoString(cid)
	ind := spell.ParseID(id)
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
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return 0
	}
	return C.int(sp.GetAudio(int(a2)))
}

//export nox_xxx_spellTitle_424930
func nox_xxx_spellTitle_424930(ind C.int) *wchar_t {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil || !sp.IsValid() {
		return nil
	}
	return internWStr(sp.Title)
}

//export nox_xxx_spellDescription_424A30
func nox_xxx_spellDescription_424A30(ind C.int) *wchar_t {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return nil
	}
	return internWStr(sp.Desc)
}

//export nox_xxx_spellByTitle_424960
func nox_xxx_spellByTitle_424960(ctitle *wchar_t) C.int {
	title := GoWString(ctitle)
	for i := 1; i < noxSpellsMax; i++ {
		if sp := noxServer.SpellDefByInd(spell.ID(i)); sp != nil && sp.Title == title {
			return C.int(i)
		}
	}
	return 0
}

//export nox_xxx_spellManaCost_4249A0
func nox_xxx_spellManaCost_4249A0(ind, a2 C.int) C.int {
	id := spell.ID(ind)
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
	sp := noxServer.SpellDefByInd(spell.ID(ind))
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
	return C.bool(noxServer.spellHasFlags(spell.ID(ind), things.SpellFlags(flags)))
}

//export nox_xxx_spellFlags_424A70
func nox_xxx_spellFlags_424A70(ind C.int) C.uint {
	return C.uint(noxServer.spellFlags(spell.ID(ind)))
}

//export nox_xxx_spellIcon_424A90
func nox_xxx_spellIcon_424A90(ind C.int) unsafe.Pointer {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return nil
	}
	return unsafe.Pointer(sp.Icon.C())
}

//export nox_xxx_spellIconHighlight_424AB0
func nox_xxx_spellIconHighlight_424AB0(ind C.int) unsafe.Pointer {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return nil
	}
	return unsafe.Pointer(sp.IconEnabled.C())
}

//export nox_xxx_spellFirstValid_424AD0
func nox_xxx_spellFirstValid_424AD0() C.int {
	for i := 1; i < noxSpellsMax; i++ {
		sp := noxServer.SpellDefByInd(spell.ID(i))
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
		sp := noxServer.SpellDefByInd(spell.ID(i))
		if sp.IsValid() {
			return C.int(i)
		}
	}
	return 0
}

//export nox_xxx_spellIsValid_424B50
func nox_xxx_spellIsValid_424B50(ind C.int) C.bool {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return false
	}
	return C.bool(sp.Valid)
}

//export nox_xxx_spellIsEnabled_424B70
func nox_xxx_spellIsEnabled_424B70(ind C.int) C.bool {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return false
	}
	return C.bool(sp.Enabled)
}

//export nox_xxx_spellEnable_424B90
func nox_xxx_spellEnable_424B90(ind C.int) C.bool {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return false
	}
	sp.Enabled = true
	return true
}

//export nox_xxx_spellDisable_424BB0
func nox_xxx_spellDisable_424BB0(ind C.int) C.bool {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return false
	}
	sp.Enabled = false
	return true
}

//export nox_xxx_spellCanUseInTrap_424BF0
func nox_xxx_spellCanUseInTrap_424BF0(ind C.int) C.bool {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
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
	sp := noxServer.SpellDefByInd(spell.ID(ind))
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

func nox_xxx_allocSpellRelatedArrays_4FC9B0() error {
	nox_alloc_spellDur_1569724 = alloc.NewClassT("spellDuration", noxDurSpell{}, 512)
	C.nox_alloc_magicEnt_1569668 = alloc.NewClass("magicEntityClass", 60, 64).UPtr()
	nox_xxx_imagCasterUnit_1569664 = noxServer.newObjectByTypeID("ImaginaryCaster").AsUnit()
	if nox_xxx_imagCasterUnit_1569664 == nil {
		return errors.New("cannot find ImaginaryCaster object type")
	}
	noxServer.createObjectAt(nox_xxx_imagCasterUnit_1569664, nil, types.Pointf{X: 2944.0, Y: 2944.0})
	noxPixieObjID = noxServer.ObjectTypeID("Pixie")
	*memmap.PtrUint32(0x5D4594, 1569676) = uint32(noxPixieObjID)
	*memmap.PtrUint32(0x5D4594, 1569680) = uint32(noxServer.ObjectTypeID("MagicMissile"))
	*memmap.PtrUint32(0x5D4594, 1569684) = uint32(noxServer.ObjectTypeID("SmallFist"))
	*memmap.PtrUint32(0x5D4594, 1569688) = uint32(noxServer.ObjectTypeID("MediumFist"))
	*memmap.PtrUint32(0x5D4594, 1569692) = uint32(noxServer.ObjectTypeID("LargeFist"))
	*memmap.PtrUint32(0x5D4594, 1569696) = uint32(noxServer.ObjectTypeID("DeathBall"))
	*memmap.PtrUint32(0x5D4594, 1569700) = uint32(noxServer.ObjectTypeID("Meteor"))
	return nil
}

func nox_xxx_freeSpellRelated_4FCA80() {
	nox_alloc_spellDur_1569724.Free()
	alloc.AsClass(C.nox_alloc_magicEnt_1569668).Free()
	C.dword_5d4594_1569672 = 0
	nox_xxx_imagCasterUnit_1569664.Delete()
	nox_xxx_imagCasterUnit_1569664 = nil
}

func (s *Server) nox_thing_read_SPEL_4156B0(f *MemFile, isClient bool) error {
	const yamlFile = "spells.yml"
	spells, err := things.ReadSpellsYAML(datapath.Data(yamlFile))
	if os.IsNotExist(err) {
		// no new file - read bag instead
		rd := things.NewReader(f)
		spells, err = rd.ReadSpellsSect()
		if n := rd.Buffered(); n != 0 {
			f.Seek(-int64(n), io.SeekCurrent)
		}
		if err != nil {
			return err
		}
	} else if err == nil {
		// ok, need to skip bag section
		rd := things.NewReader(f)
		err = rd.SkipSpellsSect()
		if n := rd.Buffered(); n != 0 {
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
	ind := spell.ParseID(def.ID)
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
		CastSound: sound.ByName(def.CastSound),
		OnSound:   sound.ByName(def.OnSound),
		OffSound:  sound.ByName(def.OffSound),
	}
	if def.Effect != "" {
		if eff := spell.ParseID(def.Effect); eff > 0 {
			sp.Effect = eff
		}
	}
	if s.spells.byID == nil {
		s.spells.byID = make(map[spell.ID]*SpellDef)
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
		sp.Def.Phonemes = append(sp.Def.Phonemes, spell.PhonEnd)
	}
	if isClient {
		sp.Icon = thingsImageRef(sp.Def.Icon)
		sp.IconEnabled = thingsImageRef(sp.Def.IconEnabled)
	}
	return nil
}

func (s *Server) spellHasFlags(ind spell.ID, flag things.SpellFlags) bool {
	return s.spellFlags(ind).Has(flag)
}

func (s *Server) spellFlags(ind spell.ID) things.SpellFlags {
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
			C.nox_xxx_spellGrantToPlayer_4FB550(u.CObj(), C.int(spell.SPELL_FIREBALL), 1, 1, 1)
		case player.Conjurer:
			C.nox_xxx_spellGrantToPlayer_4FB550(u.CObj(), C.int(spell.SPELL_CHARM), 1, 1, 1)
			C.nox_xxx_spellGrantToPlayer_4FB550(u.CObj(), C.int(spell.SPELL_LESSER_HEAL), 1, 1, 1)
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
	nox_xxx_spellCastByPlayer_4FEEF0()
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

func (s *Server) SpellDefByInd(i spell.ID) *SpellDef {
	if i <= 0 {
		return nil
	}
	return s.spells.byID[i]
}

func SpellIDs() []string {
	out := make([]string, 0, noxSpellsMax)
	for i := 1; i < noxSpellsMax; i++ {
		out = append(out, spell.ID(i).String())
	}
	return out
}

type SpellDef struct {
	Def         things.Spell
	ID          spell.ID // the ID of the spell itself, used to index it
	Effect      spell.ID // the ID of the spell effect function
	Enabled     bool
	Valid       bool
	Title       string
	Desc        string
	Icon        *Image
	IconEnabled *Image
	CastSound   sound.ID
	OnSound     sound.ID
	OffSound    sound.ID
}

func (s *SpellDef) IsValid() bool {
	return s != nil && s.Valid
}

func (s *SpellDef) GetAudio(snd int) sound.ID { // nox_xxx_spellGetAud44_424800
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
	Obj *nox_object_t
	Pos types.Pointf
}

//export nox_xxx_spellAccept_4FD400
func nox_xxx_spellAccept_4FD400(ispellID C.int, a2, a3p, a4p, a5p unsafe.Pointer, lvli C.int) C.int {
	if noxServer.nox_xxx_spellAccept4FD400(spell.ID(ispellID), asUnit(a2), asUnit(a3p), asUnit(a4p), (*spellAcceptArg)(a5p), int(lvli)) {
		return 1
	}
	return 0
}

func (s *Server) nox_xxx_spellAccept4FD400(spellID spell.ID, a2, obj3, obj4 *Unit, sa *spellAcceptArg, lvl int) bool {
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
	obj5 := asUnitC(sa.Obj)
	sp := s.SpellDefByInd(spellID)
	if sp == nil {
		gameLog.Printf("attempted to cast unsupported spell: %v", spellID)
		return false
	}
	if s.spellHasFlags(spellID, things.SpellFlagUnk8) && obj5 != nil && !obj5.Class().HasAny(object.MaskUnits) {
		return false
	}
	if !(obj5 == nil || C.nox_xxx_gameCaptureMagic_4FDC10(C.int(spellID), obj5.CObj()) != 0) {
		nox_xxx_aud_501960(sound.SoundPermanentFizzle, obj5, 0, 0)
		return false
	}
	var (
		fnc  func(spellID spell.ID, a2, a3, a4 *Unit, a5 *spellAcceptArg, lvl int) int
		cfnc unsafe.Pointer
	)
	effectID := sp.Effect
	switch effectID {
	case spell.SPELL_ANCHOR:
		fnc = castAnchor
	case spell.SPELL_ARACHNAPHOBIA:
		cfnc = C.nox_xxx_spellArachna_52DC80
	case spell.SPELL_BLIND:
		fnc = castBlind
	case spell.SPELL_BLINK:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_spellBlink2_530310, C.nox_xxx_spellBlink1_530380, nil, 0)
	case spell.SPELL_BURN:
		cfnc = C.nox_xxx_castBurn_52C3E0
	case spell.SPELL_CHANNEL_LIFE:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, nil, C.sub_52F460, nil, 0)
	case spell.SPELL_CHARM:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_charmCreature1_5011F0, C.nox_xxx_charmCreatureFinish_5013E0, C.nox_xxx_charmCreature2_501690, 0)
	case spell.SPELL_CLEANSING_FLAME, spell.SPELL_CLEANSING_MANA_FLAME:
		cfnc = C.nox_xxx_spellCastCleansingFlame_52D5C0
	case spell.SPELL_CONFUSE:
		cfnc = C.nox_xxx_castConfuse_52C1E0
	case spell.SPELL_COUNTERSPELL:
		cfnc = C.nox_xxx_castCounterSpell_52BBB0
	case spell.SPELL_CURE_POISON:
		cfnc = C.nox_xxx_castCurePoison_52CDB0
	case spell.SPELL_DEATH:
		fnc = castDeath
	case spell.SPELL_DEATH_RAY:
		fnc = castDeathRay
	case spell.SPELL_DETECT_MAGIC:
		fnc = castDetectMagic
	case spell.SPELL_DETONATE_GLYPHS:
		cfnc = C.sub_537E60
	case spell.SPELL_TURN_UNDEAD:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_spellTurnUndeadCreate_531310, C.nox_xxx_spellTurnUndeadUpdate_531410, C.nox_xxx_spellTurnUndeadDelete_531420, 70)
	case spell.SPELL_DRAIN_MANA:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, nil, C.nox_xxx_spellDrainMana_52E210, nil, 0)
	case spell.SPELL_EARTHQUAKE:
		cfnc = C.nox_xxx_castEquake_52DE40
	case spell.SPELL_LIGHTNING:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_spellEnergyBoltStop_52E820, C.nox_xxx_spellEnergyBoltTick_52E850, C.nullsub_29, 30)
	case spell.SPELL_FEAR:
		fnc = castFear
	case spell.SPELL_FIREBALL:
		cfnc = C.nox_xxx_castFireball_52C790
	case spell.SPELL_FIREWALK:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, nil, C.nox_xxx_firewalkTick_52ED40, nil, 3*s.TickRate())
	case spell.SPELL_FIST:
		cfnc = C.nox_xxx_castFist_52D3C0
	case spell.SPELL_FORCE_OF_NATURE:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.sub_52EF30, C.sub_52EFD0, C.sub_52F1D0, 2*s.TickRate()/3)
	case spell.SPELL_FREEZE:
		fnc = castFreeze
	case spell.SPELL_FUMBLE:
		cfnc = C.nox_xxx_castFumble_52C060
	case spell.SPELL_GLYPH:
		cfnc = C.nox_xxx_castGlyph_537FA0
	case spell.SPELL_GREATER_HEAL:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.sub_52F220, C.sub_52F2E0, nil, 0)
	case spell.SPELL_HASTE:
		fnc = castHaste
	case spell.SPELL_INFRAVISION:
		fnc = castInfravision
	case spell.SPELL_INVERSION:
		cfnc = C.sub_52BEB0
	case spell.SPELL_INVISIBILITY:
		fnc = castInvisibility
	case spell.SPELL_INVULNERABILITY:
		fnc = castInvulnerability
	case spell.SPELL_LESSER_HEAL:
		cfnc = C.sub_52DD50
	case spell.SPELL_LIGHT:
		fnc = castLight
	case spell.SPELL_CHAIN_LIGHTNING:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_onStartLightning_52F820, C.nox_xxx_onFrameLightning_52F8A0, C.sub_530100, 30)
	case spell.SPELL_LOCK:
		cfnc = C.nox_xxx_castLock_52CE90
	case spell.SPELL_MARK:
		cfnc = C.sub_52CA80
	case spell.SPELL_MARK_1, spell.SPELL_MARK_2, spell.SPELL_MARK_3, spell.SPELL_MARK_4:
		cfnc = C.sub_52CBD0
	case spell.SPELL_MAGIC_MISSILE:
		fnc = s.spells.missiles.Cast
	case spell.SPELL_SHIELD:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj5, obj4, sa, lvl, C.nox_xxx_castShield1_52F5A0, C.sub_52F650, C.sub_52F670, 0)
	case spell.SPELL_METEOR:
		cfnc = C.nox_xxx_castMeteor_52D9D0
	case spell.SPELL_METEOR_SHOWER:
		cfnc = C.nox_xxx_castMeteorShower_52D8A0
	case spell.SPELL_MOONGLOW:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj5, obj4, sa, lvl, C.nox_xxx_spellCreateMoonglow_531A00, nil, C.sub_531AF0, 0)
	case spell.SPELL_NULLIFY:
		fnc = castNullify
	case spell.SPELL_MANA_BOMB:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_manaBomb_530F90, C.nox_xxx_manaBombBoom_5310C0, C.sub_531290, 0)
	case spell.SPELL_PIXIE_SWARM:
		cfnc = C.nox_xxx_castPixies_540440
	case spell.SPELL_PLASMA:
		v8 := gamedataFloat("PlasmaSearchTime")
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_plasmaSmth_531580, C.nox_xxx_plasmaShot_531600, C.sub_5319E0, uint32(v8))
	case spell.SPELL_POISON:
		cfnc = C.nox_xxx_castPoison_52C720
	case spell.SPELL_PROTECTION_FROM_ELECTRICITY:
		fnc = castProtectElectricity
	case spell.SPELL_PROTECTION_FROM_FIRE:
		fnc = castProtectFire
	case spell.SPELL_PROTECTION_FROM_POISON:
		fnc = castProtectPoison
	case spell.SPELL_PULL:
		cfnc = C.nox_xxx_castPull_52BFA0
	case spell.SPELL_PUSH:
		cfnc = C.nox_xxx_castPush_52C000
	case spell.SPELL_OVAL_SHIELD:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj5, obj4, sa, lvl, C.sub_531490, C.sub_5314F0, C.sub_531560, 0)
	case spell.SPELL_RESTORE_HEALTH, spell.SPELL_WINK:
		cfnc = C.nox_xxx_castSpellWinkORrestoreHealth_52BF20
	case spell.SPELL_RESTORE_MANA:
		cfnc = C.sub_52BF50
	case spell.SPELL_RUN:
		fnc = castRun
	case spell.SPELL_SHOCK:
		cfnc = C.nox_xxx_useShock_52C5A0
	case spell.SPELL_SLOW:
		fnc = castSlow
	case spell.SPELL_STUN:
		cfnc = C.nox_xxx_castStun_52C2C0
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
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_summonStart_500DA0, C.nox_xxx_summonFinish_5010D0, C.nox_xxx_summonCancel_5011C0, 0)
	case spell.SPELL_SWAP:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.sub_530CA0, C.sub_530D30, nil, 0)
	case spell.SPELL_TAG:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_spellTagCreature_530160, C.sub_530250, C.sub_530270, 0)
	case spell.SPELL_TELEPORT_OTHER_TO_MARK_1, spell.SPELL_TELEPORT_OTHER_TO_MARK_2, spell.SPELL_TELEPORT_OTHER_TO_MARK_3, spell.SPELL_TELEPORT_OTHER_TO_MARK_4,
		spell.SPELL_TELEPORT_TO_MARK_1, spell.SPELL_TELEPORT_TO_MARK_2, spell.SPELL_TELEPORT_TO_MARK_3, spell.SPELL_TELEPORT_TO_MARK_4:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.sub_5305D0, C.sub_530650, nil, 0)
	case spell.SPELL_TELEPORT_POP:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_castTele_530820, C.sub_530880, nil, 0)
	case spell.SPELL_TELEPORT_TO_TARGET:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.sub_530A30_spell_execdur, C.nox_xxx_castTTT_530B70, nil, 0)
	case spell.SPELL_TELEKINESIS:
		cfnc = C.nox_xxx_castTelekinesis_52D330
	case spell.SPELL_TOXIC_CLOUD:
		cfnc = C.nox_xxx_castToxicCloud_52DB60
	case spell.SPELL_TRIGGER_GLYPH:
		cfnc = C.sub_52CCD0
	case spell.SPELL_VAMPIRISM:
		fnc = castVampirism
	case spell.SPELL_VILLAIN:
		fnc = castVillain
	case spell.SPELL_WALL:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, sa, lvl, C.nox_xxx_spellWallCreate_4FFA90, C.nox_xxx_spellWallUpdate_500070, C.nox_xxx_spellWallDestroy_500080, 0)
	default:
		return true
	}
	if cfnc != nil {
		fnc = func(spellID spell.ID, a2, a3, a4 *Unit, a5 *spellAcceptArg, lvl int) int {
			return int(C.nox_spells_call_intint6_go((*[0]byte)(cfnc), C.int(spellID), a2.CObj(), a3.CObj(), a4.CObj(), unsafe.Pointer(sa), C.int(lvl)))
		}
	}
	v9 := fnc(spellID, a2, obj3, obj4, sa, lvl)
	if v9 == 0 {
		nox_xxx_aud_501960(sound.SoundPermanentFizzle, obj4, 0, 0)
	}
	return v9 != 0
}

func nox_xxx_spellDurationBased_4FEBA0(spellID spell.ID, a2, a3, a4 *Unit, a5 *spellAcceptArg, a6 int, a7, a8, a9 unsafe.Pointer, a10 uint32) bool {
	return C.nox_xxx_spellDurationBased_4FEBA0(C.int(spellID), a2.CObj(), a3.CObj(), a4.CObj(), unsafe.Pointer(a5), C.int(a6), a7, a8, a9, C.int(a10)) != 0
}

func nox_xxx_spellFlySearchTarget(pos *types.Pointf, mslo noxObject, sflags things.SpellFlags, dist float32, a5 int, self *Unit) *Object {
	msl := mslo.AsObject()
	if self != nil && self.Class().Has(object.ClassPlayer) && sflags.Has(things.SpellOffensive) {
		if curTarg := asObjectS(self.UpdateDataPlayer().CursorObj); curTarg != nil {
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
		pos1 := msl.Pos()
		if MapTraceRay(pos1, *pos, MapTraceFlag1|MapTraceFlag3) {
			center = *pos
		} else {
			center = pos1
		}
	} else {
		center = *pos
	}
	dist2 := dist * dist
	owner := msl.FindOwnerChainPlayer()
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
		it.FindOwnerChainPlayer() // FIXME: result unused!
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
	if noxServer.nox_xxx_castSpellByUser4FDD20(spell.ID(a1), asUnitC(a2), (*spellAcceptArg)(a3)) {
		return 1
	}
	return 0
}

func (s *Server) castSpell(spellInd spell.ID, lvl int, u *Unit, a3 *spellAcceptArg) bool {
	if s.spellHasFlags(spellInd, things.SpellOffensive) {
		u.DisableEnchant(server.ENCHANT_INVISIBLE)
		u.DisableEnchant(server.ENCHANT_INVULNERABLE)
		s.spells.duration.CancelFor(spell.SPELL_OVAL_SHIELD, u)
	}
	if !s.spellHasFlags(spellInd, things.SpellTargeted) || u.CObj() == a3.Obj {
		return s.nox_xxx_spellAccept4FD400(spellInd, u, u, u, a3, lvl)
	}
	C.nox_xxx_createSpellFly_4FDDA0(u.CObj(), a3.Obj, C.int(spellInd))
	return true
}

func (s *Server) castSpellBy(spellInd spell.ID, caster *Unit, targ noxObject, targPos types.Pointf) bool {
	sa, freeArg := alloc.New(spellAcceptArg{})
	defer freeArg()
	sa.Obj = toCObj(targ)
	sa.Pos = targPos
	return s.nox_xxx_castSpellByUser4FDD20(spellInd, caster, sa)
}

func (s *Server) nox_xxx_castSpellByUser4FDD20(spellInd spell.ID, u *Unit, a3 *spellAcceptArg) bool {
	lvl := int(C.nox_xxx_spellGetPower_4FE7B0(C.int(spellInd), u.CObj()))
	return s.castSpell(spellInd, lvl, u, a3)
}
