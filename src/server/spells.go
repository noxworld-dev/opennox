package server

import (
	"fmt"
	"io"
	"os"
	"sort"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const (
	SpellsMax = 137
)

type SpellAcceptArg struct {
	Obj *Object
	Pos types.Pointf
}

func SpellIDs() []string {
	out := make([]string, 0, SpellsMax)
	for i := 1; i < SpellsMax; i++ {
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
	Icon        unsafe.Pointer // *noxrender.Image
	IconEnabled unsafe.Pointer // *noxrender.Image
	CastSound   sound.ID
	OnSound     sound.ID
	OffSound    sound.ID
}

func (s *SpellDef) IsValid() bool {
	return s != nil && s.Valid
}

func (s *SpellDef) IsEnabled() bool {
	return s != nil && s.Enabled
}

func (s *SpellDef) GetCastSound() sound.ID { // nox_xxx_spellGetAud44_424800(..., 0)
	if s == nil {
		return 0
	}
	return s.CastSound
}

func (s *SpellDef) GetOnSound() sound.ID { // nox_xxx_spellGetAud44_424800(..., 1)
	if s == nil {
		return 0
	}
	return s.OnSound
}

func (s *SpellDef) GetOffSound() sound.ID { // nox_xxx_spellGetAud44_424800(..., 2)
	if s == nil {
		return 0
	}
	return s.OffSound
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

type PhonemeLeaf struct {
	Ind int32
	Pho [spell.PhonMax]*PhonemeLeaf
}

func (p *PhonemeLeaf) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *PhonemeLeaf) Next(ph spell.Phoneme) *PhonemeLeaf { // nox_xxx_updateSpellRelated_424830
	if p == nil || !ph.Valid() {
		return nil
	}
	return p.Pho[ph]
}

type serverSpells struct {
	s        *Server
	byID     map[spell.ID]*SpellDef
	tree     *PhonemeLeaf
	AllowAll bool // a cheat to allow all spells
}

func (sp *serverSpells) init(s *Server) {
	sp.s = s
}

func (sp *serverSpells) Init() {
}

func (sp *serverSpells) Free() {
}

func (sp *serverSpells) DefByInd(i spell.ID) *SpellDef {
	if i <= 0 {
		return nil
	}
	return sp.byID[i]
}

func (sp *serverSpells) ByTitle(title string) spell.ID {
	for i := spell.ID(1); i < SpellsMax; i++ {
		if spl := sp.DefByInd(i); spl != nil && spl.Title == title {
			return i
		}
	}
	return 0
}

func (sp *serverSpells) Defs() []*SpellDef {
	out := make([]*SpellDef, 0, SpellsMax)
	for _, sp := range sp.byID {
		if sp != nil {
			out = append(out, sp)
		}
	}
	sort.Slice(out, func(i, j int) bool {
		return out[i].ID < out[j].ID
	})
	return out
}

func (sp *serverSpells) Flags(ind spell.ID) things.SpellFlags {
	spl := sp.DefByInd(ind)
	if spl == nil {
		return 0
	}
	flags := spl.Def.Flags
	if sp.AllowAll {
		flags |= things.SpellClassAny
	}
	return flags
}

func (sp *serverSpells) HasFlags(ind spell.ID, flag things.SpellFlags) bool {
	return sp.Flags(ind).Has(flag)
}

func (sp *serverSpells) Enable(ind spell.ID, enable bool) bool {
	spl := sp.DefByInd(ind)
	if spl == nil {
		return false
	}
	spl.Enabled = enable
	return true
}

func (sp *serverSpells) EnableAll() {
	for _, spl := range sp.byID {
		spl.Enabled = true
	}
}

func (sp *serverSpells) FirstValid() spell.ID {
	for i := spell.ID(1); i < SpellsMax; i++ {
		spl := sp.DefByInd(i)
		if spl.IsValid() {
			return i
		}
	}
	return 0
}

func (sp *serverSpells) NextValid(ind spell.ID) spell.ID {
	ind++
	if ind <= 0 || ind >= SpellsMax {
		return 0
	}
	for i := ind; i < SpellsMax; i++ {
		spl := sp.DefByInd(i)
		if spl.IsValid() {
			return i
		}
	}
	return 0
}

func (sp *serverSpells) PhonemeTree() *PhonemeLeaf {
	if sp.tree == nil {
		sp.tree, _ = alloc.New(PhonemeLeaf{})
	}
	return sp.tree
}

func (sp *serverSpells) ManaCost(id spell.ID, a2 int) int {
	if !id.Valid() {
		return 0
	}
	if a2 == 2 {
		switch id {
		case spell.SPELL_LIGHTNING:
			return int(sp.s.Balance.Float("EnergyBoltTrapCost"))
		case spell.SPELL_CHAIN_LIGHTNING:
			return int(sp.s.Balance.Float("LightningTrapCost"))
		case spell.SPELL_MANA_BOMB:
			return int(sp.s.Balance.Float("ManaBombTrapCost"))
		}
	}
	spl := sp.s.Spells.DefByInd(id)
	return spl.Def.ManaCost
}

func (sp *serverSpells) Phoneme(ind spell.ID, ind2 int) spell.Phoneme {
	spl := sp.DefByInd(ind)
	if spl == nil {
		return 0
	}
	list := spl.Def.Phonemes
	if ind2 < 0 || ind2 >= len(list) {
		return 0
	}
	return list[ind2]
}

func (sp *serverSpells) CanUseInTraps(ind spell.ID) bool {
	spl := sp.DefByInd(ind)
	if sp == nil {
		return false
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && ind == spell.SPELL_BLINK {
		return false
	}
	return !spl.Def.Flags.Has(things.SpellNoTrap)
}

func (sp *serverSpells) Price(ind spell.ID) int {
	spl := sp.DefByInd(ind)
	if spl == nil {
		return 0
	}
	price := float64(spl.Def.Price)
	if noxflags.HasGame(noxflags.GameModeQuest) {
		price *= sp.s.Balance.Float("QuestSpellWorthMultiplier")
	}
	return int(price)
}

type ImageLoaderFunc func(ref *things.ImageRef) unsafe.Pointer

func (sp *serverSpells) Read(f *binfile.MemFile, loadImage ImageLoaderFunc, dump bool) error {
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
	if dump {
		// generate default configs for OpenNox spell extensions
		for i := range spells {
			spl := &spells[i]
			switch spl.ID {
			case "SPELL_MAGIC_MISSILE":
				if spl.Missiles == nil {
					spl.Missiles = new(things.MissilesSpellConf)
					spl.Missiles.SetDefaults()
				}
			}
		}
		if err := things.WriteSpellsYAML(yamlFile, spells); err != nil {
			return err
		}
	}
	for _, spl := range spells {
		if err := sp.createSpellFrom(&spl, loadImage); err != nil {
			return err
		}
	}
	return nil
}

func (sp *serverSpells) createSpellFrom(def *things.Spell, loadImage ImageLoaderFunc) error {
	ind := spell.ParseID(def.ID)
	if ind <= 0 {
		return fmt.Errorf("unsupported spell: %q", def.ID)
	}
	const strFile = "speltree.c"
	spl := &SpellDef{
		Def:       *def,
		ID:        ind,
		Effect:    ind,
		Enabled:   true,
		Valid:     true,
		Title:     sp.s.Strings().GetStringInFile(def.Title, strFile),
		Desc:      sp.s.Strings().GetStringInFile(def.Desc, strFile),
		CastSound: sound.ByName(def.CastSound),
		OnSound:   sound.ByName(def.OnSound),
		OffSound:  sound.ByName(def.OffSound),
	}
	if def.Effect != "" {
		if eff := spell.ParseID(def.Effect); eff > 0 {
			spl.Effect = eff
		}
	}
	if sp.byID == nil {
		sp.byID = make(map[spell.ID]*SpellDef)
	}
	sp.byID[ind] = spl
	if len(spl.Def.Phonemes) != 0 {
		leaf := sp.PhonemeTree()
		for _, ph := range spl.Def.Phonemes {
			next := leaf.Pho[ph]
			if next == nil {
				next, _ = alloc.New(PhonemeLeaf{})
				leaf.Pho[ph] = next
			}
			leaf = next
		}
		leaf.Ind = int32(ind)
		spl.Def.Phonemes = append(spl.Def.Phonemes, spell.PhonEnd)
	}
	if loadImage != nil {
		spl.Icon = loadImage(spl.Def.Icon)
		spl.IconEnabled = loadImage(spl.Def.IconEnabled)
	}
	return nil
}
