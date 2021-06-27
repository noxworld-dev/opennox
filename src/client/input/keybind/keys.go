package keybind

import (
	"strconv"

	"nox/v1/common/strman"
)

const (
	// StrmanPref is a default prefix for string localisation IDs.
	StrmanPref = "keybind:"
	// StrmanNA is a default localisation ID for unknown keys.
	StrmanNA = "keybind:NA"
)

type keyDesc struct {
	Name    string
	Code    Key
	TitleID strman.ID
	Title   string
}

var keys struct {
	list   []*keyDesc
	byCode map[Key]*keyDesc
	byName map[string]Key
}

func init() {
	keys.byCode = make(map[Key]*keyDesc)
	keys.byName = make(map[string]Key)
	for _, d := range defKeys {
		RegisterKey(d.Code, d.Name, d.TitleID, d.Title)
	}
}

// KeyByName finds the key by its name. It returns 0 if there's no such key.
func KeyByName(name string) Key {
	return keys.byName[name]
}

// Key represent a key code registered with this package.
// The code is arbitrary and may not represent key code of the underlying input source.
type Key uint32

// IsValid checks if the key is registered.
func (k Key) IsValid() bool {
	if k == 0 {
		return false
	}
	return keys.byCode[k] != nil
}

// String returns the name of the key.
func (k Key) String() string {
	if k == 0 {
		return ""
	}
	b := keys.byCode[k]
	if b == nil || b.Name == "" {
		return strconv.Itoa(int(k))
	}
	return b.Name
}

// TitleID returns key title ID for localisation.
func (k Key) TitleID() strman.ID {
	if k == 0 {
		return ""
	}
	b := keys.byCode[k]
	if b == nil {
		return StrmanNA
	} else if b.TitleID == "" {
		return StrmanPref + strman.ID(b.Name)
	}
	return b.TitleID
}

// Title returns key localised key title.
func (k Key) Title(sm *strman.StringManager) string {
	if k == 0 {
		return ""
	}
	b := keys.byCode[k]
	if b == nil {
		return sm.GetString(StrmanNA)
	}
	sid := b.TitleID
	if sid == "" {
		if b.Title != "" {
			return b.Title
		}
		sid = StrmanNA
	}
	return sm.GetString(sid)
}

// ListKeys lists all keys registered with this package.
func ListKeys() []Key {
	out := make([]Key, 0, len(keys.list))
	for _, d := range keys.list {
		out = append(out, d.Code)
	}
	return out
}

// RegisterKey registers a new key with specified code, name and title.
func RegisterKey(code Key, name string, titleID strman.ID, titleDef string) {
	if code == 0 {
		panic("empty key code")
	}
	if name == "" {
		panic("empty name")
	}
	if _, ok := keys.byCode[code]; ok {
		panic("key code already registered")
	}
	if _, ok := keys.byName[name]; ok {
		panic("key name already registered")
	}
	d := &keyDesc{Name: name, Code: code, TitleID: titleID, Title: titleDef}
	keys.list = append(keys.list, d)
	keys.byCode[d.Code] = d
	keys.byName[d.Name] = d.Code
}
