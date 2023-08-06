package opennox

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

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
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

func getPhonemeTree() *phonemeLeaf {
	if spellPhonemeTree == nil {
		spellPhonemeTree, _ = alloc.New(phonemeLeaf{})
	}
	return spellPhonemeTree
}

const noxSpellsMax = 137

func nox_xxx_spellAwardAll1_4EFD80(p *server.Player) {
	serverSetAllBeastScrolls(asPlayerS(p), noxflags.HasEngine(noxflags.EngineAdmin))
}

func nox_xxx_spellAwardAll2_4EFC80(p *server.Player) {
	serverSetAllSpells(asPlayerS(p), noxflags.HasEngine(noxflags.EngineAdmin), 0)
}

func nox_xxx_spellAwardAll3_4EFE10(p *server.Player) {
	serverSetAllWarriorAbilities(asPlayerS(p), noxflags.HasEngine(noxflags.EngineAdmin), 0)
}

func nox_xxx_spellGetAud44_424800(ind, a2 int) int {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return 0
	}
	return int(sp.GetAudio(a2))
}

func nox_xxx_spellTitle_424930(ind int) (string, bool) {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil || !sp.IsValid() {
		return "", false
	}
	return sp.Title, true
}

func nox_xxx_spellDescription_424A30(ind int) (string, bool) {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return "", false
	}
	return sp.Desc, true
}

func nox_xxx_spellByTitle_424960(title string) int {
	for i := 1; i < noxSpellsMax; i++ {
		if sp := noxServer.SpellDefByInd(spell.ID(i)); sp != nil && sp.Title == title {
			return i
		}
	}
	return 0
}

func nox_xxx_spellManaCost_4249A0(ind, a2 int) int {
	id := spell.ID(ind)
	if !id.Valid() {
		return 0
	}
	if a2 == 2 {
		switch ind {
		case 24:
			return int(gamedataFloat("EnergyBoltTrapCost"))
		case 43:
			return int(gamedataFloat("LightningTrapCost"))
		case 56:
			return int(gamedataFloat("ManaBombTrapCost"))
		}
	}
	sp := noxServer.SpellDefByInd(id)
	return sp.Def.ManaCost
}

func nox_xxx_spellPhonemes_424A20(ind, ind2 int) spell.Phoneme {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return 0
	}
	list := sp.Def.Phonemes
	if ind2 < 0 || ind2 >= len(list) {
		return 0
	}
	return list[ind2]
}

func nox_xxx_spellIcon_424A90(ind int) unsafe.Pointer {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return nil
	}
	return unsafe.Pointer(sp.Icon.C())
}

func nox_xxx_spellIconHighlight_424AB0(ind int) unsafe.Pointer {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return nil
	}
	return unsafe.Pointer(sp.IconEnabled.C())
}

func nox_xxx_spellFirstValid_424AD0() int {
	for i := 1; i < noxSpellsMax; i++ {
		sp := noxServer.SpellDefByInd(spell.ID(i))
		if sp.IsValid() {
			return i
		}
	}
	return 0
}

func nox_xxx_spellNextValid_424AF0(ind int) int {
	ind++
	if ind <= 0 || ind >= noxSpellsMax {
		return 0
	}
	for i := ind; i < noxSpellsMax; i++ {
		sp := noxServer.SpellDefByInd(spell.ID(i))
		if sp.IsValid() {
			return i
		}
	}
	return 0
}

func nox_xxx_spellIsValid_424B50(ind int) bool {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return false
	}
	return sp.Valid
}

func nox_xxx_spellIsEnabled_424B70(ind int) bool {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return false
	}
	return sp.Enabled
}

func nox_xxx_spellEnable_424B90(ind int) bool {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return false
	}
	sp.Enabled = true
	return true
}

func nox_xxx_spellDisable_424BB0(ind int) bool {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return false
	}
	sp.Enabled = false
	return true
}

func nox_xxx_spellCanUseInTrap_424BF0(ind int) bool {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return false
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && ind == 4 {
		return false
	}
	return !sp.Def.Flags.Has(things.SpellNoTrap)
}

func nox_xxx_spellPrice_424C40(ind int) int {
	sp := noxServer.SpellDefByInd(spell.ID(ind))
	if sp == nil {
		return 0
	}
	price := float64(sp.Def.Price)
	if noxflags.HasGame(noxflags.GameModeQuest) {
		price *= gamedataFloat("QuestSpellWorthMultiplier")
	}
	return int(price)
}

func nox_xxx_spellEnableAll_424BD0() {
	noxServer.spellEnableAll()
}

func (s *Server) spellEnableAll() {
	for _, sp := range s.spells.byID {
		sp.Enabled = true
	}
}

func nox_xxx_allocSpellRelatedArrays_4FC9B0() error {
	s := noxServer
	nox_alloc_spellDur_1569724 = alloc.NewClassT("spellDuration", noxDurSpell{}, 512)
	legacy.Set_nox_alloc_magicEnt_1569668(alloc.NewClass("magicEntityClass", 60, 64).UPtr())
	nox_xxx_imagCasterUnit_1569664 = asObjectS(s.NewObjectByTypeID("ImaginaryCaster"))
	if nox_xxx_imagCasterUnit_1569664 == nil {
		return errors.New("cannot find ImaginaryCaster object type")
	}
	s.CreateObjectAt(nox_xxx_imagCasterUnit_1569664, nil, types.Pointf{X: 2944.0, Y: 2944.0})
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
	nox_alloc_spellDur_1569724.Free()
	alloc.AsClass(legacy.Get_nox_alloc_magicEnt_1569668()).Free()
	legacy.Set_dword_5d4594_1569672(0)
	nox_xxx_imagCasterUnit_1569664.Delete()
	nox_xxx_imagCasterUnit_1569664 = nil
}

func (s *Server) nox_thing_read_SPEL_4156B0(f *binfile.MemFile, isClient bool) error {
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
		c := noxClient
		sp.Icon = c.r.Bag.ThingsImageRef(sp.Def.Icon)
		sp.IconEnabled = c.r.Bag.ThingsImageRef(sp.Def.IconEnabled)
	}
	return nil
}

func (s *Server) SpellHasFlags(ind spell.ID, flag things.SpellFlags) bool {
	return s.SpellFlags(ind).Has(flag)
}

func (s *Server) SpellFlags(ind spell.ID) things.SpellFlags {
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
	legacy.Nox_xxx_playerResetProtectionCRC_56F7D0(*(*uintptr)(p.field(4640)), 0)
	for i := 1; i < len(p.BeastScrollLvl); i++ {
		p.BeastScrollLvl[i] = uint32(lvl)
		legacy.Nox_xxx_playerAwardSpellProtectionCRC_56FCE0(*(*uintptr)(p.field(4640)), i, lvl)
	}
	legacy.Nox_xxx_playerApplyProtectionCRC_56FD50(*(*uintptr)(p.field(4640)), unsafe.Pointer(&p.BeastScrollLvl[0]), len(p.BeastScrollLvl))
}

func serverSetAllSpells(p *Player, enable bool, max int) {
	lvl := 0
	if enable {
		lvl = max
		if max <= 0 {
			lvl = 3
		}
	}
	legacy.Nox_xxx_playerResetProtectionCRC_56F7D0(*(*uintptr)(p.field(4636)), 0)
	// set max level for all possible spells
	// the engine will automatically allow only ones that have WIS_USE, CON_USE or COMMON_USE set
	for i := 1; i < len(p.SpellLvl); i++ {
		p.SpellLvl[i] = uint32(lvl)
		legacy.Nox_xxx_playerAwardSpellProtectionCRC_56FCE0(*(*uintptr)(p.field(4636)), i, lvl)
	}
	if !enable && noxflags.HasGame(noxflags.GameModeQuest) {
		u := p.UnitC()
		// grant default spells for Quest when disabling the cheat
		switch p.PlayerClass() {
		case player.Wizard:
			legacy.Nox_xxx_spellGrantToPlayer_4FB550(u.SObj(), spell.SPELL_FIREBALL, 1, 1, 1)
		case player.Conjurer:
			legacy.Nox_xxx_spellGrantToPlayer_4FB550(u.SObj(), spell.SPELL_CHARM, 1, 1, 1)
			legacy.Nox_xxx_spellGrantToPlayer_4FB550(u.SObj(), spell.SPELL_LESSER_HEAL, 1, 1, 1)
		}
	}
	legacy.Nox_xxx_playerApplyProtectionCRC_56FD50(*(*uintptr)(p.field(4636)), unsafe.Pointer(&p.SpellLvl[0]), len(p.SpellLvl))
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
		legacy.Nox_xxx_playerAwardSpellProtectionCRC_56FCE0(*(*uintptr)(p.field(4636)), i, lvl)
	}
}

func nox_xxx_spellBookReact_4FCB70() {
	legacy.Nox_xxx_spellCastByBook_4FCB80()
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
	Icon        *noxrender.Image
	IconEnabled *noxrender.Image
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
	sp := s.SpellDefByInd(spellID)
	if sp == nil {
		gameLog.Printf("attempted to cast unsupported spell: %v", spellID)
		return false
	}
	if s.SpellHasFlags(spellID, things.SpellFlagUnk8) && obj5 != nil && !obj5.Class().HasAny(object.MaskUnits) {
		return false
	}
	if !(obj5 == nil || legacy.Nox_xxx_gameCaptureMagic_4FDC10(spellID, obj5.SObj()) != 0) {
		s.AudioEventObj(sound.SoundPermanentFizzle, obj5, 0, 0)
		return false
	}
	var fnc func(spellID spell.ID, a2, a3, a4 *server.Object, a5 *server.SpellAcceptArg, lvl int) int
	effectID := sp.Effect
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
		fnc = legacy.Nox_xxx_castCounterSpell_52BBB0
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
		return s.spells.duration.New(spellID, a2, obj3, obj4, sa, lvl, nil, legacy.Get_nox_xxx_firewalkTick_52ED40(), nil, 3*s.TickRate())
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
		v8 := gamedataFloat("PlasmaSearchTime")
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
	v9 := fnc(spellID, a2.SObj(), obj3.SObj(), obj4.SObj(), sa, lvl)
	if v9 == 0 {
		s.AudioEventObj(sound.SoundPermanentFizzle, obj4, 0, 0)
	}
	return v9 != 0
}

func (s *Server) Nox_xxx_spellFlySearchTarget(pos *types.Pointf, mslo server.Obj, sflags things.SpellFlags, dist float32, a5 int, sself *server.Object) *server.Object {
	self := asObjectS(sself)
	msl := toObject(mslo)
	if self != nil && self.Class().Has(object.ClassPlayer) && sflags.Has(things.SpellOffensive) {
		if curTarg := asObjectS(self.UpdateDataPlayer().CursorObj); curTarg != nil {
			if s.IsEnemyTo(sself, curTarg.SObj()) && ((a5 == 1) || (a5 == 0) && msl != curTarg) {
				return curTarg.SObj()
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
		if s.MapTraceRay(pos1, *pos, server.MapTraceFlag1|server.MapTraceFlag3) {
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
		Min: center.Sub(types.Ptf(dist, dist)),
		Max: center.Add(types.Ptf(dist, dist)),
	}
	var (
		minDist float32 = 1e+08
		found   *server.Object
	)
	s.Map.EachObjInRect(rect, func(it *server.Object) bool {
		if !(a5 != 0 || msl.SObj() != it) {
			return true
		}
		if !it.Class().HasAny(object.MaskTargets) {
			return true
		}
		if it.Class().Has(object.ClassMonster) && (it.SubClass()&0x8000 != 0) {
			return true
		}
		if it.Class().Has(object.ClassPlayer) && asObjectS(it).ControllingPlayer().Field3680&0x1 != 0 {
			return true
		}
		if it.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			return true
		}
		if it.Class().Has(object.ClassMonster) && (it.SubClass()&0x4000 != 0) {
			return true
		}
		it.FindOwnerChainPlayer() // FIXME: result unused!
		if sflags.Has(things.SpellOffensive) && !s.IsEnemyTo(msl.SObj(), it) {
			return true
		}
		opos := it.Pos()
		dx := center.X - opos.X
		dy := center.Y - opos.Y
		odist := dy*dy + dx*dx
		if odist > dist2 {
			return true
		}
		if msl != nil && !s.CanInteract(msl.SObj(), it, 0) {
			return true
		}
		if owner != nil && !s.CanInteract(owner.SObj(), it, 0) {
			return true
		}
		if odist < minDist {
			found = it
			minDist = odist
		}
		return true
	})
	return found.SObj()
}

func nox_xxx_castSpellByUser_4FDD20(a1 int, a2 *server.Object, a3 unsafe.Pointer) int {
	if noxServer.nox_xxx_castSpellByUser4FDD20(spell.ID(a1), -1, a2, (*server.SpellAcceptArg)(a3)) {
		return 1
	}
	return 0
}

func (s *Server) castSpell(spellInd spell.ID, lvl int, u *server.Object, a3 *server.SpellAcceptArg) bool {
	if s.SpellHasFlags(spellInd, things.SpellOffensive) {
		asObjectS(u).DisableEnchant(server.ENCHANT_INVISIBLE)
		asObjectS(u).DisableEnchant(server.ENCHANT_INVULNERABLE)
		s.spells.duration.CancelFor(spell.SPELL_OVAL_SHIELD, u)
	}
	if !s.SpellHasFlags(spellInd, things.SpellTargeted) || u.SObj() == a3.Obj {
		return s.Nox_xxx_spellAccept4FD400(spellInd, u, u, u, a3, lvl)
	}
	legacy.Nox_xxx_createSpellFly_4FDDA0(u.SObj(), a3.Obj, spellInd)
	return true
}

func (s *Server) castSpellBy(spellInd spell.ID, lvl int, caster *server.Object, targ server.Obj, targPos types.Pointf) bool {
	sa, freeArg := alloc.New(server.SpellAcceptArg{})
	defer freeArg()
	sa.Obj = toObjectS(targ)
	sa.Pos = targPos
	return s.nox_xxx_castSpellByUser4FDD20(spellInd, lvl, caster, sa)
}

func (s *Server) nox_xxx_castSpellByUser4FDD20(spellInd spell.ID, lvl int, u *server.Object, sa *server.SpellAcceptArg) bool {
	if lvl < 0 {
		lvl = legacy.Nox_xxx_spellGetPower_4FE7B0(spellInd, u)
	}
	return s.castSpell(spellInd, lvl, u, sa)
}
