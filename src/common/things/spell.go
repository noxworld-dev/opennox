package things

import (
	"encoding/json"
	"fmt"
	"io"
	"strings"

	"gopkg.in/yaml.v2"

	"nox/v1/common/strman"
)

func init() {
	for i, id := range spellIDs {
		spellIndByID[id] = i
	}
}

var (
	_ json.Marshaler   = Phoneme(0)
	_ json.Unmarshaler = (*Phoneme)(nil)
	_ yaml.Marshaler   = Phoneme(0)
	_ yaml.Unmarshaler = (*Phoneme)(nil)
)

const (
	PhonKA  = Phoneme(0) // upper-left
	PhonUN  = Phoneme(1) // up
	PhonIN  = Phoneme(2) // upper-right
	PhonET  = Phoneme(3) // left
	PhonEnd = Phoneme(4)
	PhonCHA = Phoneme(5) // right
	PhonRO  = Phoneme(6) // lower-left
	PhonZO  = Phoneme(7) // down
	PhonDO  = Phoneme(8) // lower-right
	PhonMax = 9
)

type Phoneme byte

func (p Phoneme) Valid() bool {
	return p >= 0 && p < PhonMax
}

func (p Phoneme) String() string {
	switch p {
	case PhonKA:
		return "ka"
	case PhonUN:
		return "un"
	case PhonIN:
		return "in"
	case PhonET:
		return "et"
	case PhonEnd:
		return "!"
	case PhonCHA:
		return "cha"
	case PhonRO:
		return "ro"
	case PhonZO:
		return "zo"
	case PhonDO:
		return "do"
	default:
		return fmt.Sprintf("Phoneme(%d)", int(p))
	}
}

func (p Phoneme) MarshalJSON() ([]byte, error) {
	if p.Valid() {
		return json.Marshal(p.String())
	}
	return json.Marshal(int(p))
}

func (p Phoneme) MarshalYAML() (interface{}, error) {
	if p.Valid() {
		return p.String(), nil
	}
	return int(p), nil
}

func (p *Phoneme) parseText(s string) error {
	switch strings.ToLower(s) {
	case "ka":
		*p = PhonKA
	case "un":
		*p = PhonUN
	case "in":
		*p = PhonIN
	case "et":
		*p = PhonET
	case "!", "":
		*p = PhonEnd
	case "cha":
		*p = PhonCHA
	case "ro":
		*p = PhonRO
	case "zo":
		*p = PhonZO
	case "do":
		*p = PhonDO
	default:
		return fmt.Errorf("unknown spell phoneme: %q", s)
	}
	return nil
}

func (p *Phoneme) UnmarshalJSON(data []byte) error {
	var s string
	if err := json.Unmarshal(data, &s); err != nil {
		var v int
		if err2 := json.Unmarshal(data, &v); err2 != nil {
			return err
		}
		*p = Phoneme(v)
		return nil
	}
	return p.parseText(s)
}

func (p *Phoneme) UnmarshalYAML(unmarshal func(interface{}) error) error {
	var v uint8
	if err := unmarshal(&v); err == nil {
		*p = Phoneme(v)
		return nil
	}
	var s string
	if err := unmarshal(&s); err != nil {
		return err
	}
	return p.parseText(s)
}

var (
	_ json.Marshaler   = SpellFlags(0)
	_ json.Unmarshaler = (*SpellFlags)(nil)
	_ yaml.Marshaler   = SpellFlags(0)
	_ yaml.Unmarshaler = (*SpellFlags)(nil)
)

const (
	SpellFlagUnk1       = SpellFlags(0x1)        // 1
	SpellDuration       = SpellFlags(0x2)        // 2
	SpellTargetFoe      = SpellFlags(0x4)        // 4
	SpellFlagUnk4       = SpellFlags(0x8)        // 8
	SpellFlagUnk5       = SpellFlags(0x10)       // 16
	SpellCancelsProtect = SpellFlags(0x20)       // 32
	SpellFlagUnk7       = SpellFlags(0x40)       // 64
	SpellFlagUnk8       = SpellFlags(0x80)       // 128
	SpellFlagUnk9       = SpellFlags(0x100)      // 256
	SpellAutoTrack      = SpellFlags(0x200)      // 512
	SpellFlagUnk11      = SpellFlags(0x400)      // 1024
	SpellFlagUnk12      = SpellFlags(0x800)      // 2048
	SpellFlagUnk13      = SpellFlags(0x1000)     // 4096
	SpellSummon         = SpellFlags(0x2000)     // 8192
	SpellFlagUnk15      = SpellFlags(0x4000)     // 16384
	SpellFlagUnk16      = SpellFlags(0x8000)     // 32768
	SpellFlagUnk17      = SpellFlags(0x10000)    // 65536
	SpellFlagUnk18      = SpellFlags(0x20000)    // 131072
	SpellFlagUnk19      = SpellFlags(0x40000)    // 262144
	SpellFlagUnk20      = SpellFlags(0x80000)    // 524288
	SpellFlagUnk21      = SpellFlags(0x100000)   // 1048576
	SpellCantTargetSelf = SpellFlags(0x200000)   // 2097152
	SpellNoTrap         = SpellFlags(0x400000)   // 4194304
	SpellNoMana         = SpellFlags(0x800000)   // 8388608
	SpellCommonUse      = SpellFlags(0x1000000)  // 16777216
	SpellWizUse         = SpellFlags(0x2000000)  // 33554432
	SpellConUse         = SpellFlags(0x4000000)  // 67108864
	SpellFlagUnk28      = SpellFlags(0x8000000)  // 134217728
	SpellFlagUnk29      = SpellFlags(0x10000000) // 268435456
	SpellFlagUnk30      = SpellFlags(0x20000000) // 536870912
	SpellFlagUnk31      = SpellFlags(0x40000000) // 1073741824
	SpellFlagUnk32      = SpellFlags(0x80000000) // 2147483648
)

type SpellFlags uint32

func (f SpellFlags) string() string {
	switch f {
	case SpellDuration:
		return "DURATION"
	case SpellTargetFoe:
		return "TARGET_FOE"
	case SpellCancelsProtect:
		return "CANCELS_PROTECT"
	case SpellAutoTrack:
		return "AUTO_TRACK"
	case SpellSummon:
		return "SUMMON"
	case SpellCantTargetSelf:
		return "CANT_TARGET_SELF"
	case SpellNoTrap:
		return "NO_TRAP"
	case SpellNoMana:
		return "NO_MANA"
	case SpellCommonUse:
		return "COMMON_USE"
	case SpellWizUse:
		return "WIS_USE"
	case SpellConUse:
		return "CON_USE"
	}
	return ""
}

func (f SpellFlags) String() string {
	if f == 0 {
		return ""
	}
	arr := f.Split()
	if len(arr) > 1 {
		str := make([]string, 0, len(arr))
		for _, v := range arr {
			str = append(str, v.String())
		}
		return strings.Join(str, " | ")
	}
	if s := f.string(); s != "" {
		return s
	}
	return fmt.Sprintf("SpellFlags(%d)", int(f))
}

func (f SpellFlags) Has(f2 SpellFlags) bool {
	return f&f2 != 0
}

func (f SpellFlags) Split() []SpellFlags {
	var out []SpellFlags
	for i := 0; i < 32; i++ {
		v := SpellFlags(1 << i)
		if f&v != 0 {
			out = append(out, v)
		}
	}
	return out
}

func (f SpellFlags) MarshalJSON() ([]byte, error) {
	if f == 0 {
		return []byte("0"), nil
	}
	arr := f.Split()
	out := make([]interface{}, 0, len(arr))
	for _, v := range f.Split() {
		if s := v.string(); s != "" {
			out = append(out, s)
		} else {
			out = append(out, uint(v))
		}
	}
	if len(out) == 1 {
		return json.Marshal(out[0])
	}
	return json.Marshal(out)
}

func (f SpellFlags) MarshalYAML() (interface{}, error) {
	if f == 0 {
		return 0, nil
	}
	arr := f.Split()
	out := make([]interface{}, 0, len(arr))
	for _, v := range f.Split() {
		if s := v.string(); s != "" {
			out = append(out, s)
		} else {
			out = append(out, uint(v))
		}
	}
	if len(out) == 1 {
		return out[0], nil
	}
	return out, nil
}

func (f *SpellFlags) parseText(s string) error {
	switch s {
	case "DURATION":
		*f = SpellDuration
	case "TARGET_FOE":
		*f = SpellTargetFoe
	case "CANCELS_PROTECT":
		*f = SpellCancelsProtect
	case "AUTO_TRACK":
		*f = SpellAutoTrack
	case "SUMMON":
		*f = SpellSummon
	case "CANT_TARGET_SELF":
		*f = SpellCantTargetSelf
	case "NO_TRAP":
		*f = SpellNoTrap
	case "NO_MANA":
		*f = SpellNoMana
	case "COMMON_USE":
		*f = SpellCommonUse
	case "WIS_USE":
		*f = SpellWizUse
	case "CON_USE":
		*f = SpellConUse
	default:
		return fmt.Errorf("unknown spell flag: %q", s)
	}
	return nil
}

func (f *SpellFlags) unmarshalJSON(data []byte) (bool, error) {
	var v uint32
	if err := json.Unmarshal(data, &v); err == nil {
		*f = SpellFlags(v)
		return true, nil
	}
	var s string
	err := json.Unmarshal(data, &s)
	if err != nil {
		return false, err
	}
	err = f.parseText(s)
	return true, err
}

func (f *SpellFlags) UnmarshalJSON(data []byte) error {
	if ok, err := f.unmarshalJSON(data); ok {
		return err
	}
	var arr []json.RawMessage
	if err := json.Unmarshal(data, &arr); err != nil {
		return err
	}
	v := SpellFlags(0)
	for _, a := range arr {
		var f2 SpellFlags
		if _, err := f2.unmarshalJSON(a); err != nil {
			return err
		}
		v |= f2
	}
	*f = v
	return nil
}

func (f *SpellFlags) unmarshalYAML(unmarshal func(interface{}) error) (bool, error) {
	var v uint32
	if err := unmarshal(&v); err == nil {
		*f = SpellFlags(v)
		return true, nil
	}
	var s string
	err := unmarshal(&s)
	if err != nil {
		return false, err
	}
	err = f.parseText(s)
	return true, err
}

func (f *SpellFlags) UnmarshalYAML(unmarshal func(interface{}) error) error {
	if ok, err := f.unmarshalYAML(unmarshal); ok {
		return err
	}
	var arr []SpellFlags
	if err := unmarshal(&arr); err != nil {
		return err
	}
	v := SpellFlags(0)
	for _, a := range arr {
		v |= a
	}
	*f = v
	return nil
}

type Spell struct {
	ID          string             `json:"name" yaml:"name"`
	Icon        *ImageRef          `json:"icon,omitempty" yaml:"icon,omitempty"`
	IconEnabled *ImageRef          `json:"icon_enabled,omitempty" yaml:"icon_enabled,omitempty"`
	ManaCost    int                `json:"mana_cost" yaml:"mana_cost"`
	Price       int                `json:"price" yaml:"price"`
	Flags       SpellFlags         `json:"flags" yaml:"flags"`
	Phonemes    []Phoneme          `json:"phonemes,omitempty" yaml:"phonemes,omitempty"`
	Title       strman.ID          `json:"title,omitempty" yaml:"title,omitempty"`
	Desc        strman.ID          `json:"desc,omitempty" yaml:"desc,omitempty"`
	CastSound   string             `json:"cast_sound,omitempty" yaml:"cast_sound,omitempty"`
	OnSound     string             `json:"on_sound,omitempty" yaml:"on_sound,omitempty"`
	OffSound    string             `json:"off_sound,omitempty" yaml:"off_sound,omitempty"`
	Missiles    *MissilesSpellConf `json:"missiles,omitempty" yaml:"missiles,omitempty"`
}

func SkipSpellsSection(r io.Reader) error {
	f := newDirectReader(r)
	return f.skipSPEL()
}

func ReadSpellsSection(r io.Reader) ([]Spell, error) {
	f := newDirectReader(r)
	return f.readSPEL()
}

func (f *Reader) ReadSpells() ([]Spell, error) {
	if err := f.seek(0, io.SeekStart); err != nil {
		return nil, err
	}
	ok, err := f.skipUntil("SPEL")
	if !ok {
		return nil, err
	}
	return f.readSPEL()
}

func (f *Reader) skipSPEL() error {
	n, err := f.readU32()
	if err != nil {
		return err
	} else if n <= 0 {
		return nil
	}
	for i := 0; i < int(n); i++ {
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err = f.skip(1 + 2); err != nil {
			return err
		}
		sz, err := f.readU8()
		if err != nil {
			return err
		}
		for j := 0; j < int(sz); j++ {
			v, err := f.readU8()
			if err != nil {
				return err
			} else if v >= 9 {
				return fmt.Errorf("invalid spell code: %d", v)
			}
		}
		for k := 0; k < 2; k++ {
			if err := f.skipImageRef(); err != nil {
				return err
			}
		}
		if err = f.skip(4); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err := f.skipBytes16(); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
	}
	return nil // no END here
}

func (f *Reader) readSPEL() ([]Spell, error) {
	n, err := f.readU32()
	if err != nil {
		return nil, err
	} else if n <= 0 {
		return nil, nil
	}
	out := make([]Spell, 0, n)
	for i := 0; i < int(n); i++ {
		id, err := f.readString8()
		if err != nil {
			return out, err
		}
		mana, err := f.readU8()
		if err != nil {
			return out, err
		}
		price, err := f.readU16()
		if err != nil {
			return out, err
		}
		sz, err := f.readU8()
		if err != nil {
			return out, err
		}
		phon := make([]Phoneme, 0, sz)
		for j := 0; j < int(sz); j++ {
			v, err := f.readU8()
			if err != nil {
				return out, err
			} else if v >= PhonMax {
				return out, fmt.Errorf("invalid phoneme: %d", v)
			}
			phon = append(phon, Phoneme(v))
		}
		im1, err := f.readImageRef()
		if err != nil {
			return out, err
		}
		im2, err := f.readImageRef()
		if err != nil {
			return out, err
		}
		fl, err := f.readU32()
		if err != nil {
			return out, err
		}
		title, err := f.readString8()
		if err != nil {
			return out, err
		}
		desc, err := f.readString16()
		if err != nil {
			return out, err
		}
		cast, err := f.readString8()
		if err != nil {
			return out, err
		}
		if cast == "NULL" {
			cast = ""
		}
		on, err := f.readString8()
		if err != nil {
			return out, err
		}
		if on == "NULL" {
			on = ""
		}
		off, err := f.readString8()
		if err != nil {
			return out, err
		}
		if off == "NULL" {
			off = ""
		}
		out = append(out, Spell{
			ID:          id,
			Icon:        im1,
			IconEnabled: im2,
			ManaCost:    int(mana),
			Price:       int(price),
			Flags:       SpellFlags(fl),
			Title:       strman.ID(title),
			Desc:        strman.ID(desc),
			Phonemes:    phon,
			CastSound:   cast,
			OnSound:     on,
			OffSound:    off,
		})
	}
	return out, nil // no END here
}

var (
	spellIndByID = make(map[string]int)
	spellIDs     = []string{
		"SPELL_INVALID",                     // 0
		"SPELL_ANCHOR",                      // 1
		"SPELL_ARACHNAPHOBIA",               // 2
		"SPELL_BLIND",                       // 3
		"SPELL_BLINK",                       // 4
		"SPELL_BURN",                        // 5
		"SPELL_CANCEL",                      // 6
		"SPELL_CHAIN_LIGHTNING_BOLT",        // 7
		"SPELL_CHANNEL_LIFE",                // 8
		"SPELL_CHARM",                       // 9
		"SPELL_CLEANSING_FLAME",             // 10
		"SPELL_CLEANSING_MANA_FLAME",        // 11
		"SPELL_CONFUSE",                     // 12
		"SPELL_COUNTERSPELL",                // 13
		"SPELL_CURE_POISON",                 // 14
		"SPELL_DEATH",                       // 15
		"SPELL_DEATH_RAY",                   // 16
		"SPELL_DETECT_MAGIC",                // 17
		"SPELL_DETONATE",                    // 18
		"SPELL_DETONATE_GLYPHS",             // 19
		"SPELL_DISENCHANT_ALL",              // 20
		"SPELL_TURN_UNDEAD",                 // 21
		"SPELL_DRAIN_MANA",                  // 22
		"SPELL_EARTHQUAKE",                  // 23
		"SPELL_LIGHTNING",                   // 24
		"SPELL_EXPLOSION",                   // 25
		"SPELL_FEAR",                        // 26
		"SPELL_FIREBALL",                    // 27
		"SPELL_FIREWALK",                    // 28
		"SPELL_FIST",                        // 29
		"SPELL_FORCE_FIELD",                 // 30
		"SPELL_FORCE_OF_NATURE",             // 31
		"SPELL_FREEZE",                      // 32
		"SPELL_FUMBLE",                      // 33
		"SPELL_GLYPH",                       // 34
		"SPELL_GREATER_HEAL",                // 35
		"SPELL_HASTE",                       // 36
		"SPELL_INFRAVISION",                 // 37
		"SPELL_INVERSION",                   // 38
		"SPELL_INVISIBILITY",                // 39
		"SPELL_INVULNERABILITY",             // 40
		"SPELL_LESSER_HEAL",                 // 41
		"SPELL_LIGHT",                       // 42
		"SPELL_CHAIN_LIGHTNING",             // 43
		"SPELL_LOCK",                        // 44
		"SPELL_MARK",                        // 45
		"SPELL_MARK_1",                      // 46
		"SPELL_MARK_2",                      // 47
		"SPELL_MARK_3",                      // 48
		"SPELL_MARK_4",                      // 49
		"SPELL_MAGIC_MISSILE",               // 50
		"SPELL_SHIELD",                      // 51
		"SPELL_METEOR",                      // 52
		"SPELL_METEOR_SHOWER",               // 53
		"SPELL_MOONGLOW",                    // 54
		"SPELL_NULLIFY",                     // 55
		"SPELL_MANA_BOMB",                   // 56
		"SPELL_PHANTOM",                     // 57
		"SPELL_PIXIE_SWARM",                 // 58
		"SPELL_PLASMA",                      // 59
		"SPELL_POISON",                      // 60
		"SPELL_PROTECTION_FROM_ELECTRICITY", // 61
		"SPELL_PROTECTION_FROM_FIRE",        // 62
		"SPELL_PROTECTION_FROM_MAGIC",       // 63
		"SPELL_PROTECTION_FROM_POISON",      // 64
		"SPELL_PULL",                        // 65
		"SPELL_PUSH",                        // 67
		"SPELL_OVAL_SHIELD",                 // 68
		"SPELL_RESTORE_HEALTH",              // 69
		"SPELL_RESTORE_MANA",                // 70
		"SPELL_RUN",                         // 71
		"SPELL_SHOCK",                       // 72
		"SPELL_SLOW",                        // 73
		"SPELL_SMALL_ZAP",                   // 74
		"SPELL_STUN",                        // 75
		"SPELL_SUMMON_BAT",                  // 76
		"SPELL_SUMMON_BLACK_BEAR",           // 77
		"SPELL_SUMMON_BEAR",                 // 78
		"SPELL_SUMMON_BEHOLDER",             // 79
		"SPELL_SUMMON_BOMBER",               // 80
		"SPELL_SUMMON_CARNIVOROUS_PLANT",    // 81
		"SPELL_SUMMON_ALBINO_SPIDER",        // 82
		"SPELL_SUMMON_SMALL_ALBINO_SPIDER",  // 83
		"SPELL_SUMMON_EVIL_CHERUB",          // 84
		"SPELL_SUMMON_EMBER_DEMON",          // 85
		"SPELL_SUMMON_GHOST",                // 86
		"SPELL_SUMMON_GIANT_LEECH",          // 87
		"SPELL_SUMMON_IMP",                  // 88
		"SPELL_SUMMON_MECHANICAL_FLYER",     // 89
		"SPELL_SUMMON_MECHANICAL_GOLEM",     // 90
		"SPELL_SUMMON_MIMIC",                // 91
		"SPELL_SUMMON_OGRE",                 // 92
		"SPELL_SUMMON_OGRE_BRUTE",           // 93
		"SPELL_SUMMON_OGRE_WARLORD",         // 94
		"SPELL_SUMMON_SCORPION",             // 95
		"SPELL_SUMMON_SHADE",                // 96
		"SPELL_SUMMON_SKELETON",             // 97
		"SPELL_SUMMON_SKELETON_LORD",        // 98
		"SPELL_SUMMON_SPIDER",               // 99
		"SPELL_SUMMON_SMALL_SPIDER",         // 100
		"SPELL_SUMMON_SPITTING_SPIDER",      // 101
		"SPELL_SUMMON_STONE_GOLEM",          // 102
		"SPELL_SUMMON_TROLL",                // 103
		"SPELL_SUMMON_URCHIN",               // 104
		"SPELL_SUMMON_WASP",                 // 105
		"SPELL_SUMMON_WILLOWISP",            // 106
		"SPELL_SUMMON_WOLF",                 // 107
		"SPELL_SUMMON_BLACK_WOLF",           // 108
		"SPELL_SUMMON_WHITE_WOLF",           // 109
		"SPELL_SUMMON_ZOMBIE",               // 110
		"SPELL_SUMMON_VILE_ZOMBIE",          // 111
		"SPELL_SUMMON_DEMON",                // 112
		"SPELL_SUMMON_LICH",                 // 113
		"SPELL_SUMMON_DRYAD",                // 114
		"SPELL_SUMMON_URCHIN_SHAMAN",        // 115
		"SPELL_SWAP",                        // 116
		"SPELL_TAG",                         // 117
		"SPELL_TELEPORT_OTHER_TO_MARK_1",    // 118
		"SPELL_TELEPORT_OTHER_TO_MARK_2",    // 119
		"SPELL_TELEPORT_OTHER_TO_MARK_3",    // 120
		"SPELL_TELEPORT_OTHER_TO_MARK_4",    // 121
		"SPELL_TELEPORT_POP",                // 122
		"SPELL_TELEPORT_TO_MARK_1",          // 123
		"SPELL_TELEPORT_TO_MARK_2",          // 124
		"SPELL_TELEPORT_TO_MARK_3",          // 125
		"SPELL_TELEPORT_TO_MARK_4",          // 126
		"SPELL_TELEPORT_TO_TARGET",          // 127
		"SPELL_TELEKINESIS",                 // 128
		"SPELL_TOXIC_CLOUD",                 // 129
		"SPELL_TRIGGER_GLYPH",               // 130
		"SPELL_VAMPIRISM",                   // 131
		"SPELL_VILLAIN",                     // 132
		"SPELL_WALL",                        // 133
		"SPELL_WINK",                        // 134
		"SPELL_SUMMON_CREATURE",             // 135
		"SPELL_MARK_LOCATION",               // 136
		"SPELL_TELEPORT_TO_MARKER",          // 137
	}
)

func SpellIndex(id string) int {
	return spellIndByID[id]
}

func SpellIDByIndex(ind int) string {
	if ind <= 0 || ind >= len(spellIDs) {
		return ""
	}
	return spellIDs[ind]
}
