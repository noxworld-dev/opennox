package strman

import (
	"errors"
	"fmt"
	"math/rand"
	"os"
	"path/filepath"
	"strings"

	"nox/v1/common/log"
)

type ID string

type Entry struct {
	ID   ID        `json:"id"`
	Vals []Variant `json:"vals"`
}

func (e Entry) Value() Variant {
	if len(e.Vals) == 1 {
		return e.Vals[0]
	}
	i := rand.Intn(len(e.Vals))
	return e.Vals[i]
}

type Variant struct {
	Str  string `json:"str"`
	Str2 string `json:"str2,omitempty"`
}

func New() *StringManager {
	return new(StringManager)
}

type StringManager struct {
	lang    int
	entries []Entry
	byID    map[ID]*Entry
}

func (sm *StringManager) Lang() int {
	return sm.lang
}

func (sm *StringManager) Get(id ID) (Entry, bool) {
	id = ID(strings.ToLower(string(id)))
	ent := sm.byID[id]
	if ent == nil {
		return Entry{}, false
	}
	return *ent, true
}

func fileID(file string, id ID) ID {
	if strings.IndexByte(string(id), ':') < 0 {
		if i := strings.LastIndexAny(file, `\/`); i >= 0 {
			file = file[i+1:]
		}
		id = ID(strings.Join([]string{file, string(id)}, ":"))
	}
	return id
}

func (sm *StringManager) GetInFile(id ID, file string) (Entry, bool) {
	return sm.Get(fileID(file, id))
}

func (sm *StringManager) GetVariant(id ID) (Variant, bool) {
	e, ok := sm.Get(id)
	if !ok || len(e.Vals) == 0 {
		return Variant{Str: fmt.Sprintf("MISSING:'%s'", id)}, false
	}
	return e.Value(), true
}

func (sm *StringManager) GetString(id ID) string {
	s, _ := sm.GetVariant(id)
	return s.Str
}

func (sm *StringManager) GetVariantInFile(id ID, file string) (Variant, bool) {
	return sm.GetVariant(fileID(file, id))
}

func (sm *StringManager) GetStringInFile(id ID, file string) string {
	s, _ := sm.GetVariant(fileID(file, id))
	return s.Str
}

func (sm *StringManager) indexEntries() error {
	sm.byID = make(map[ID]*Entry, len(sm.entries))
	for i, e := range sm.entries {
		id := ID(strings.ToLower(string(e.ID)))
		if e2, ok := sm.byID[id]; ok {
			log.Printf("duplicate strings entry %q:\n%q\nvs\n%q", e.ID, e.Vals, e2.Vals)
			continue
		}
		sm.byID[id] = &sm.entries[i]
	}
	return nil
}

func (sm *StringManager) ReadFile(path string) error {
	if len(path) == 0 {
		return errors.New("empty path")
	}
	ext := filepath.Ext(path)
	name := strings.TrimRight(path, ext)

	if err := sm.ReadJSON(name + ".csf.json"); err == nil {
		return nil
	} else if !os.IsNotExist(err) {
		return err
	}
	if err := sm.ReadCSF(name + ".csf"); err == nil {
		return nil
	} else if !os.IsNotExist(err) {
		return err
	}

	switch ext {
	case ".json":
		return sm.ReadJSON(path)
	case ".csf":
		return sm.ReadCSF(path)
	default:
		if err := sm.readSTRFile(path); err == nil {
			return nil
		} else if !os.IsNotExist(err) {
			return err
		}
		return sm.ReadCSF(name + ".csf")
	}
}

func (sm *StringManager) readSTRFile(path string) error {
	return os.ErrNotExist // FIXME
}
