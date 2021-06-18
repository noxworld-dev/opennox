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

type SpellFlags uint32

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
