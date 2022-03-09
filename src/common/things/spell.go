package things

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io"
	"os"
	"strings"

	"gopkg.in/yaml.v2"

	"nox/v1/common/strman"
)

func init() {
	for i, id := range spellIDs {
		spellIndByID[id] = SpellID(i)
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
	SpellTargeted       = SpellFlags(0x4)        // 4
	SpellAtLocation     = SpellFlags(0x8)        // 8
	SpellMobsCanCast    = SpellFlags(0x10)       // 16
	SpellOffensive      = SpellFlags(0x20)       // 32
	SpellFlagUnk7       = SpellFlags(0x40)       // 64
	SpellFlagUnk8       = SpellFlags(0x80)       // 128
	SpellInstant        = SpellFlags(0x100)      // 256
	SpellDefensive      = SpellFlags(0x200)      // 512
	SpellFlagUnk11      = SpellFlags(0x400)      // 1024
	SpellFlagUnk12      = SpellFlags(0x800)      // 2048
	SpellSummonMain     = SpellFlags(0x1000)     // 4096
	SpellSummonCreature = SpellFlags(0x2000)     // 8192
	SpellMarkMain       = SpellFlags(0x4000)     // 16384
	SpellMarkNumber     = SpellFlags(0x8000)     // 32768
	SpellGotoMarkMain   = SpellFlags(0x10000)    // 65536
	SpellGotoMarkNumber = SpellFlags(0x20000)    // 131072
	SpellCanCounter     = SpellFlags(0x40000)    // 262144
	SpellCantHoldCrown  = SpellFlags(0x80000)    // 524288
	SpellFlagUnk21      = SpellFlags(0x100000)   // 1048576
	SpellCantTargetSelf = SpellFlags(0x200000)   // 2097152
	SpellNoTrap         = SpellFlags(0x400000)   // 4194304
	SpellNoMana         = SpellFlags(0x800000)   // 8388608
	SpellClassAny       = SpellFlags(0x1000000)  // 16777216
	SpellClassWizard    = SpellFlags(0x2000000)  // 33554432
	SpellClassConjurer  = SpellFlags(0x4000000)  // 67108864
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
	case SpellTargeted:
		return "TARGETED"
	case SpellAtLocation:
		return "AT_LOCATION"
	case SpellMobsCanCast:
		return "MOBS_CAN_CAST"
	case SpellOffensive:
		return "OFFENSIVE"
	case SpellInstant:
		return "INSTANT"
	case SpellDefensive:
		return "DEFENSIVE"
	case SpellSummonMain:
		return "SUMMON_SPELL"
	case SpellSummonCreature:
		return "SUMMON_CREATURE"
	case SpellMarkMain:
		return "MARK_SPELL"
	case SpellMarkNumber:
		return "MARK_NUMBER"
	case SpellGotoMarkMain:
		return "GOTO_MARK_SPELL"
	case SpellGotoMarkNumber:
		return "GOTO_MARK_NUMBER"
	case SpellCanCounter:
		return "CAN_COUNTER"
	case SpellCantHoldCrown:
		return "CANT_HOLD_CROWN"
	case SpellCantTargetSelf:
		return "CANT_TARGET_SELF"
	case SpellNoTrap:
		return "NO_TRAP"
	case SpellNoMana:
		return "NO_MANA"
	case SpellClassAny:
		return "CLASS_ANY"
	case SpellClassWizard:
		return "CLASS_WIZARD"
	case SpellClassConjurer:
		return "CLASS_CONJURER"
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
	case "TARGET_FOE", "TARGETED":
		*f = SpellTargeted
	case "TARGET_POINT", "AT_LOCATION":
		*f = SpellAtLocation
	case "MOBS_CAN_CAST":
		*f = SpellMobsCanCast
	case "CANCELS_PROTECT", "OFFENSIVE":
		*f = SpellOffensive
	case "INSTANT":
		*f = SpellInstant
	case "AUTO_TRACK", "DEFENSIVE":
		*f = SpellDefensive
	case "SUMMON_SPELL":
		*f = SpellSummonMain
	case "SUMMON", "SUMMON_CREATURE":
		*f = SpellSummonCreature
	case "MARK_SPELL":
		*f = SpellMarkMain
	case "MARK_NUMBER":
		*f = SpellMarkNumber
	case "GOTO_MARK_SPELL":
		*f = SpellGotoMarkMain
	case "GOTO_MARK_NUMBER":
		*f = SpellGotoMarkNumber
	case "CAN_COUNTER":
		*f = SpellCanCounter
	case "CANT_HOLD_CROWN":
		*f = SpellCantHoldCrown
	case "CANT_TARGET_SELF":
		*f = SpellCantTargetSelf
	case "NO_TRAP":
		*f = SpellNoTrap
	case "NO_MANA":
		*f = SpellNoMana
	case "COMMON_USE", "CLASS_ANY":
		*f = SpellClassAny
	case "WIS_USE", "CLASS_WIZARD":
		*f = SpellClassWizard
	case "CON_USE", "CLASS_CONJURER":
		*f = SpellClassConjurer
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
	Effect      string             `json:"effect,omitempty" yaml:"effect,omitempty"`
	Icon        *ImageRef          `json:"icon,omitempty" yaml:"icon,omitempty"`
	IconEnabled *ImageRef          `json:"icon_enabled,omitempty" yaml:"icon_enabled,omitempty"`
	ManaCost    int                `json:"mana_cost" yaml:"mana_cost"`
	Price       int                `json:"price" yaml:"price"`
	Flags       SpellFlags         `json:"flags" yaml:"flags"`
	Phonemes    []Phoneme          `json:"phonemes,omitempty" yaml:"phonemes,flow,omitempty"`
	Title       strman.ID          `json:"title,omitempty" yaml:"title,omitempty"`
	Desc        strman.ID          `json:"desc,omitempty" yaml:"desc,omitempty"`
	CastSound   string             `json:"cast_sound,omitempty" yaml:"cast_sound,omitempty"`
	OnSound     string             `json:"on_sound,omitempty" yaml:"on_sound,omitempty"`
	OffSound    string             `json:"off_sound,omitempty" yaml:"off_sound,omitempty"`
	Missiles    *MissilesSpellConf `json:"missiles,omitempty" yaml:"missiles,omitempty"`
}

func ReadSpellsYAML(path string) ([]Spell, error) {
	data, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	// compatibility
	var out []Spell
	if err := yaml.Unmarshal(data, &out); err == nil {
		return out, nil
	}
	// new format - individual objects split as YAML documents
	out = nil
	dec := yaml.NewDecoder(bytes.NewReader(data))
	for {
		var sp Spell
		err := dec.Decode(&sp)
		if err == io.EOF {
			return out, nil
		} else if err != nil {
			return out, err
		}
		out = append(out, sp)
	}
}

func WriteSpellsYAML(path string, list []Spell) error {
	f, err := os.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()
	enc := yaml.NewEncoder(f)
	for _, sp := range list {
		if err := enc.Encode(sp); err != nil {
			return err
		}
	}
	if err := enc.Close(); err != nil {
		return err
	}
	return f.Close()
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

func ParseSpellID(id string) SpellID {
	return spellIndByID[id]
}

type SpellID int

func (id SpellID) Valid() bool {
	return id > 0 && int(id) < len(spellIDs)
}

func (id SpellID) String() string {
	if !id.Valid() {
		return ""
	}
	return spellIDs[id]
}

const (
	SPELL_INVALID                     = SpellID(0)
	SPELL_ANCHOR                      = SpellID(1)
	SPELL_ARACHNAPHOBIA               = SpellID(2)
	SPELL_BLIND                       = SpellID(3)
	SPELL_BLINK                       = SpellID(4)
	SPELL_BURN                        = SpellID(5)
	SPELL_CANCEL                      = SpellID(6)
	SPELL_CHAIN_LIGHTNING_BOLT        = SpellID(7)
	SPELL_CHANNEL_LIFE                = SpellID(8)
	SPELL_CHARM                       = SpellID(9)
	SPELL_CLEANSING_FLAME             = SpellID(10)
	SPELL_CLEANSING_MANA_FLAME        = SpellID(11)
	SPELL_CONFUSE                     = SpellID(12)
	SPELL_COUNTERSPELL                = SpellID(13)
	SPELL_CURE_POISON                 = SpellID(14)
	SPELL_DEATH                       = SpellID(15)
	SPELL_DEATH_RAY                   = SpellID(16)
	SPELL_DETECT_MAGIC                = SpellID(17)
	SPELL_DETONATE                    = SpellID(18)
	SPELL_DETONATE_GLYPHS             = SpellID(19)
	SPELL_DISENCHANT_ALL              = SpellID(20)
	SPELL_TURN_UNDEAD                 = SpellID(21)
	SPELL_DRAIN_MANA                  = SpellID(22)
	SPELL_EARTHQUAKE                  = SpellID(23)
	SPELL_LIGHTNING                   = SpellID(24)
	SPELL_EXPLOSION                   = SpellID(25)
	SPELL_FEAR                        = SpellID(26)
	SPELL_FIREBALL                    = SpellID(27)
	SPELL_FIREWALK                    = SpellID(28)
	SPELL_FIST                        = SpellID(29)
	SPELL_FORCE_FIELD                 = SpellID(30)
	SPELL_FORCE_OF_NATURE             = SpellID(31)
	SPELL_FREEZE                      = SpellID(32)
	SPELL_FUMBLE                      = SpellID(33)
	SPELL_GLYPH                       = SpellID(34)
	SPELL_GREATER_HEAL                = SpellID(35)
	SPELL_HASTE                       = SpellID(36)
	SPELL_INFRAVISION                 = SpellID(37)
	SPELL_INVERSION                   = SpellID(38)
	SPELL_INVISIBILITY                = SpellID(39)
	SPELL_INVULNERABILITY             = SpellID(40)
	SPELL_LESSER_HEAL                 = SpellID(41)
	SPELL_LIGHT                       = SpellID(42)
	SPELL_CHAIN_LIGHTNING             = SpellID(43)
	SPELL_LOCK                        = SpellID(44)
	SPELL_MARK                        = SpellID(45)
	SPELL_MARK_1                      = SpellID(46)
	SPELL_MARK_2                      = SpellID(47)
	SPELL_MARK_3                      = SpellID(48)
	SPELL_MARK_4                      = SpellID(49)
	SPELL_MAGIC_MISSILE               = SpellID(50)
	SPELL_SHIELD                      = SpellID(51)
	SPELL_METEOR                      = SpellID(52)
	SPELL_METEOR_SHOWER               = SpellID(53)
	SPELL_MOONGLOW                    = SpellID(54)
	SPELL_NULLIFY                     = SpellID(55)
	SPELL_MANA_BOMB                   = SpellID(56)
	SPELL_PHANTOM                     = SpellID(57)
	SPELL_PIXIE_SWARM                 = SpellID(58)
	SPELL_PLASMA                      = SpellID(59)
	SPELL_POISON                      = SpellID(60)
	SPELL_PROTECTION_FROM_ELECTRICITY = SpellID(61)
	SPELL_PROTECTION_FROM_FIRE        = SpellID(62)
	SPELL_PROTECTION_FROM_MAGIC       = SpellID(63)
	SPELL_PROTECTION_FROM_POISON      = SpellID(64)
	SPELL_PULL                        = SpellID(65)
	SPELL_PUSH                        = SpellID(66)
	SPELL_OVAL_SHIELD                 = SpellID(67)
	SPELL_RESTORE_HEALTH              = SpellID(68)
	SPELL_RESTORE_MANA                = SpellID(69)
	SPELL_RUN                         = SpellID(70)
	SPELL_SHOCK                       = SpellID(71)
	SPELL_SLOW                        = SpellID(72)
	SPELL_SMALL_ZAP                   = SpellID(73)
	SPELL_STUN                        = SpellID(74)
	SPELL_SUMMON_BAT                  = SpellID(75)
	SPELL_SUMMON_BLACK_BEAR           = SpellID(76)
	SPELL_SUMMON_BEAR                 = SpellID(77)
	SPELL_SUMMON_BEHOLDER             = SpellID(78)
	SPELL_SUMMON_BOMBER               = SpellID(79)
	SPELL_SUMMON_CARNIVOROUS_PLANT    = SpellID(80)
	SPELL_SUMMON_ALBINO_SPIDER        = SpellID(81)
	SPELL_SUMMON_SMALL_ALBINO_SPIDER  = SpellID(82)
	SPELL_SUMMON_EVIL_CHERUB          = SpellID(83)
	SPELL_SUMMON_EMBER_DEMON          = SpellID(84)
	SPELL_SUMMON_GHOST                = SpellID(85)
	SPELL_SUMMON_GIANT_LEECH          = SpellID(86)
	SPELL_SUMMON_IMP                  = SpellID(87)
	SPELL_SUMMON_MECHANICAL_FLYER     = SpellID(88)
	SPELL_SUMMON_MECHANICAL_GOLEM     = SpellID(89)
	SPELL_SUMMON_MIMIC                = SpellID(90)
	SPELL_SUMMON_OGRE                 = SpellID(91)
	SPELL_SUMMON_OGRE_BRUTE           = SpellID(92)
	SPELL_SUMMON_OGRE_WARLORD         = SpellID(93)
	SPELL_SUMMON_SCORPION             = SpellID(94)
	SPELL_SUMMON_SHADE                = SpellID(95)
	SPELL_SUMMON_SKELETON             = SpellID(96)
	SPELL_SUMMON_SKELETON_LORD        = SpellID(97)
	SPELL_SUMMON_SPIDER               = SpellID(98)
	SPELL_SUMMON_SMALL_SPIDER         = SpellID(99)
	SPELL_SUMMON_SPITTING_SPIDER      = SpellID(100)
	SPELL_SUMMON_STONE_GOLEM          = SpellID(101)
	SPELL_SUMMON_TROLL                = SpellID(102)
	SPELL_SUMMON_URCHIN               = SpellID(103)
	SPELL_SUMMON_WASP                 = SpellID(104)
	SPELL_SUMMON_WILLOWISP            = SpellID(105)
	SPELL_SUMMON_WOLF                 = SpellID(106)
	SPELL_SUMMON_BLACK_WOLF           = SpellID(107)
	SPELL_SUMMON_WHITE_WOLF           = SpellID(108)
	SPELL_SUMMON_ZOMBIE               = SpellID(109)
	SPELL_SUMMON_VILE_ZOMBIE          = SpellID(110)
	SPELL_SUMMON_DEMON                = SpellID(111)
	SPELL_SUMMON_LICH                 = SpellID(112)
	SPELL_SUMMON_DRYAD                = SpellID(113)
	SPELL_SUMMON_URCHIN_SHAMAN        = SpellID(114)
	SPELL_SWAP                        = SpellID(115)
	SPELL_TAG                         = SpellID(116)
	SPELL_TELEPORT_OTHER_TO_MARK_1    = SpellID(117)
	SPELL_TELEPORT_OTHER_TO_MARK_2    = SpellID(118)
	SPELL_TELEPORT_OTHER_TO_MARK_3    = SpellID(119)
	SPELL_TELEPORT_OTHER_TO_MARK_4    = SpellID(120)
	SPELL_TELEPORT_POP                = SpellID(121)
	SPELL_TELEPORT_TO_MARK_1          = SpellID(122)
	SPELL_TELEPORT_TO_MARK_2          = SpellID(123)
	SPELL_TELEPORT_TO_MARK_3          = SpellID(124)
	SPELL_TELEPORT_TO_MARK_4          = SpellID(125)
	SPELL_TELEPORT_TO_TARGET          = SpellID(126)
	SPELL_TELEKINESIS                 = SpellID(127)
	SPELL_TOXIC_CLOUD                 = SpellID(128)
	SPELL_TRIGGER_GLYPH               = SpellID(129)
	SPELL_VAMPIRISM                   = SpellID(130)
	SPELL_VILLAIN                     = SpellID(131)
	SPELL_WALL                        = SpellID(132)
	SPELL_WINK                        = SpellID(133)
	SPELL_SUMMON_CREATURE             = SpellID(134)
	SPELL_MARK_LOCATION               = SpellID(135)
	SPELL_TELEPORT_TO_MARKER          = SpellID(136)
)

var (
	spellIndByID = make(map[string]SpellID)
	spellIDs     = []string{
		"SPELL_INVALID",
		"SPELL_ANCHOR",
		"SPELL_ARACHNAPHOBIA",
		"SPELL_BLIND",
		"SPELL_BLINK",
		"SPELL_BURN",
		"SPELL_CANCEL",
		"SPELL_CHAIN_LIGHTNING_BOLT",
		"SPELL_CHANNEL_LIFE",
		"SPELL_CHARM",
		"SPELL_CLEANSING_FLAME",
		"SPELL_CLEANSING_MANA_FLAME",
		"SPELL_CONFUSE",
		"SPELL_COUNTERSPELL",
		"SPELL_CURE_POISON",
		"SPELL_DEATH",
		"SPELL_DEATH_RAY",
		"SPELL_DETECT_MAGIC",
		"SPELL_DETONATE",
		"SPELL_DETONATE_GLYPHS",
		"SPELL_DISENCHANT_ALL",
		"SPELL_TURN_UNDEAD",
		"SPELL_DRAIN_MANA",
		"SPELL_EARTHQUAKE",
		"SPELL_LIGHTNING",
		"SPELL_EXPLOSION",
		"SPELL_FEAR",
		"SPELL_FIREBALL",
		"SPELL_FIREWALK",
		"SPELL_FIST",
		"SPELL_FORCE_FIELD",
		"SPELL_FORCE_OF_NATURE",
		"SPELL_FREEZE",
		"SPELL_FUMBLE",
		"SPELL_GLYPH",
		"SPELL_GREATER_HEAL",
		"SPELL_HASTE",
		"SPELL_INFRAVISION",
		"SPELL_INVERSION",
		"SPELL_INVISIBILITY",
		"SPELL_INVULNERABILITY",
		"SPELL_LESSER_HEAL",
		"SPELL_LIGHT",
		"SPELL_CHAIN_LIGHTNING",
		"SPELL_LOCK",
		"SPELL_MARK",
		"SPELL_MARK_1",
		"SPELL_MARK_2",
		"SPELL_MARK_3",
		"SPELL_MARK_4",
		"SPELL_MAGIC_MISSILE",
		"SPELL_SHIELD",
		"SPELL_METEOR",
		"SPELL_METEOR_SHOWER",
		"SPELL_MOONGLOW",
		"SPELL_NULLIFY",
		"SPELL_MANA_BOMB",
		"SPELL_PHANTOM",
		"SPELL_PIXIE_SWARM",
		"SPELL_PLASMA",
		"SPELL_POISON",
		"SPELL_PROTECTION_FROM_ELECTRICITY",
		"SPELL_PROTECTION_FROM_FIRE",
		"SPELL_PROTECTION_FROM_MAGIC",
		"SPELL_PROTECTION_FROM_POISON",
		"SPELL_PULL",
		"SPELL_PUSH",
		"SPELL_OVAL_SHIELD",
		"SPELL_RESTORE_HEALTH",
		"SPELL_RESTORE_MANA",
		"SPELL_RUN",
		"SPELL_SHOCK",
		"SPELL_SLOW",
		"SPELL_SMALL_ZAP",
		"SPELL_STUN",
		"SPELL_SUMMON_BAT",
		"SPELL_SUMMON_BLACK_BEAR",
		"SPELL_SUMMON_BEAR",
		"SPELL_SUMMON_BEHOLDER",
		"SPELL_SUMMON_BOMBER",
		"SPELL_SUMMON_CARNIVOROUS_PLANT",
		"SPELL_SUMMON_ALBINO_SPIDER",
		"SPELL_SUMMON_SMALL_ALBINO_SPIDER",
		"SPELL_SUMMON_EVIL_CHERUB",
		"SPELL_SUMMON_EMBER_DEMON",
		"SPELL_SUMMON_GHOST",
		"SPELL_SUMMON_GIANT_LEECH",
		"SPELL_SUMMON_IMP",
		"SPELL_SUMMON_MECHANICAL_FLYER",
		"SPELL_SUMMON_MECHANICAL_GOLEM",
		"SPELL_SUMMON_MIMIC",
		"SPELL_SUMMON_OGRE",
		"SPELL_SUMMON_OGRE_BRUTE",
		"SPELL_SUMMON_OGRE_WARLORD",
		"SPELL_SUMMON_SCORPION",
		"SPELL_SUMMON_SHADE",
		"SPELL_SUMMON_SKELETON",
		"SPELL_SUMMON_SKELETON_LORD",
		"SPELL_SUMMON_SPIDER",
		"SPELL_SUMMON_SMALL_SPIDER",
		"SPELL_SUMMON_SPITTING_SPIDER",
		"SPELL_SUMMON_STONE_GOLEM",
		"SPELL_SUMMON_TROLL",
		"SPELL_SUMMON_URCHIN",
		"SPELL_SUMMON_WASP",
		"SPELL_SUMMON_WILLOWISP",
		"SPELL_SUMMON_WOLF",
		"SPELL_SUMMON_BLACK_WOLF",
		"SPELL_SUMMON_WHITE_WOLF",
		"SPELL_SUMMON_ZOMBIE",
		"SPELL_SUMMON_VILE_ZOMBIE",
		"SPELL_SUMMON_DEMON",
		"SPELL_SUMMON_LICH",
		"SPELL_SUMMON_DRYAD",
		"SPELL_SUMMON_URCHIN_SHAMAN",
		"SPELL_SWAP",
		"SPELL_TAG",
		"SPELL_TELEPORT_OTHER_TO_MARK_1",
		"SPELL_TELEPORT_OTHER_TO_MARK_2",
		"SPELL_TELEPORT_OTHER_TO_MARK_3",
		"SPELL_TELEPORT_OTHER_TO_MARK_4",
		"SPELL_TELEPORT_POP",
		"SPELL_TELEPORT_TO_MARK_1",
		"SPELL_TELEPORT_TO_MARK_2",
		"SPELL_TELEPORT_TO_MARK_3",
		"SPELL_TELEPORT_TO_MARK_4",
		"SPELL_TELEPORT_TO_TARGET",
		"SPELL_TELEKINESIS",
		"SPELL_TOXIC_CLOUD",
		"SPELL_TRIGGER_GLYPH",
		"SPELL_VAMPIRISM",
		"SPELL_VILLAIN",
		"SPELL_WALL",
		"SPELL_WINK",
		"SPELL_SUMMON_CREATURE",
		"SPELL_MARK_LOCATION",
		"SPELL_TELEPORT_TO_MARKER",
	}
)
