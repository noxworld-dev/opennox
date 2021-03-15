package strman

import (
	"encoding/json"

	"nox/common/fs"
)

type jsonFile struct {
	Lang    int     `json:"lang,omitempty"`
	Entries []Entry `json:"entries"`
}

func (sm *StringManager) ReadJSON(path string) error {
	sm.lang = 0
	sm.entries = nil
	var file jsonFile
	f, err := fs.Open(path)
	if err != nil {
		return err
	}
	defer f.Close()
	if err = json.NewDecoder(f).Decode(&file); err != nil {
		return err
	}
	sm.lang = file.Lang
	// TODO: pack values in memory?
	sm.entries = file.Entries
	return sm.indexEntries()
}

func (sm *StringManager) WriteJSON(path string) error {
	f, err := fs.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()
	if err = json.NewEncoder(f).Encode(jsonFile{
		Lang:    sm.lang,
		Entries: sm.entries,
	}); err != nil {
		return err
	}
	return f.Close()
}
