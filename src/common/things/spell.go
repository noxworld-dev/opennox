package things

import (
	"encoding/json"
	"fmt"
	"io"
	"strings"
)

var (
	_ json.Marshaler   = Phoneme(0)
	_ json.Unmarshaler = (*Phoneme)(nil)
)

const (
	PhonKA  = Phoneme(0)
	PhonUN  = Phoneme(1)
	PhonIN  = Phoneme(2)
	PhonET  = Phoneme(3)
	PhonEnd = Phoneme(4)
	PhonCHA = Phoneme(5)
	PhonRO  = Phoneme(6)
	PhonZO  = Phoneme(7)
	PhonDO  = Phoneme(8)
	phonMax = 9
)

type Phoneme byte

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
	if p >= 0 && p < phonMax {
		return json.Marshal(p.String())
	}
	return json.Marshal(int(p))
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

var (
	_ json.Marshaler   = SpellFlags(0)
	_ json.Unmarshaler = (*SpellFlags)(nil)
)

const (
	SpellFlagUnk1       = SpellFlags(0x1)        // 1
	SpellFlagUnk2       = SpellFlags(0x2)        // 2
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
			out = append(out, int(v))
		}
	}
	if len(out) == 1 {
		return json.Marshal(out[0])
	}
	return json.Marshal(out)
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
	switch s {
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
		return true, fmt.Errorf("unknown spell flag: %q", s)
	}
	return true, nil
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

type Spell struct {
	ID          string     `json:"name"`
	Icon        *ImageRef  `json:"icon,omitempty"`
	IconEnabled *ImageRef  `json:"icon_enabled,omitempty"`
	ManaCost    int        `json:"mana_cost"`
	Price       int        `json:"price"`
	Flags       SpellFlags `json:"flags"`
	Phonemes    []Phoneme  `json:"phonemes,omitempty"`
	Title       string     `json:"title,omitempty"`
	Desc        string     `json:"description,omitempty"`
	CastSound   string     `json:"cast_sound,omitempty"`
	OnSound     string     `json:"on_sound,omitempty"`
	OffSound    string     `json:"off_sound,omitempty"`
}

func (f *File) ReadSpells() ([]Spell, error) {
	if err := f.seek(0, io.SeekStart); err != nil {
		return nil, err
	}
	ok, err := f.skipUntil("SPEL")
	if !ok {
		return nil, err
	}
	return f.readSPEL()
}

func (f *File) skipSPEL() error {
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

func (f *File) readSPEL() ([]Spell, error) {
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
			} else if v >= phonMax {
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
			Title:       title,
			Desc:        desc,
			Phonemes:    phon,
			CastSound:   cast,
			OnSound:     on,
			OffSound:    off,
		})
	}
	return out, nil // no END here
}
