package strman

import (
	"errors"
	"fmt"
	"log"
	"math/rand"
	"os"
	"path/filepath"
	"strings"
)

type Entry struct {
	ID   string    `json:"id"`
	Vals []Variant `json:"vals"`
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
	byID    map[string]*Entry
}

func (sm *StringManager) Lang() int {
	return sm.lang
}

func (sm *StringManager) Get(id string) (Entry, bool) {
	id = strings.ToLower(id)
	ent := sm.byID[id]
	if ent == nil {
		return Entry{}, false
	}
	return *ent, true
}

func fileID(file, id string) string {
	if strings.IndexByte(id, ':') < 0 {
		if i := strings.LastIndexAny(file, `\/`); i >= 0 {
			file = file[i+1:]
		}
		id = strings.Join([]string{file, id}, ":")
	}
	return id
}

func (sm *StringManager) GetInFile(id, file string) (Entry, bool) {
	return sm.Get(fileID(file, id))
}

func (sm *StringManager) GetString2(id string) (string, string) {
	e, ok := sm.Get(id)
	if !ok || len(e.Vals) == 0 {
		return fmt.Sprintf("MISSING:'%s'", id), ""
	}
	if len(e.Vals) == 1 {
		return e.Vals[0].Str, e.Vals[0].Str2
	}
	i := rand.Intn(len(e.Vals))
	return e.Vals[i].Str, e.Vals[i].Str2
}

func (sm *StringManager) GetString(id string) string {
	s, _ := sm.GetString2(id)
	return s
}

func (sm *StringManager) GetString2InFile(id, file string) (string, string) {
	return sm.GetString2(fileID(file, id))
}

func (sm *StringManager) GetStringInFile(id, file string) string {
	s, _ := sm.GetString2(fileID(file, id))
	return s
}

func (sm *StringManager) indexEntries() error {
	sm.byID = make(map[string]*Entry, len(sm.entries))
	for i, e := range sm.entries {
		id := strings.ToLower(e.ID)
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
