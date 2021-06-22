package keybind

import (
	"strings"

	"nox/v1/common/strman"
)

type Key uint32

type KeyBind struct {
	Name    string
	Key     Key
	TitleID strman.ID
	Title   string
}

type BindEvent struct {
	Name  string
	Key   Key
	Title string
}

type Binding struct {
	sm   *strman.StringManager
	keys struct {
		list    []KeyBind
		byKey   map[Key]*KeyBind
		byName  map[string]*KeyBind
		byTitle map[string]*KeyBind
	}
	events struct {
		list    []BindEvent
		byKey   map[Key]*BindEvent
		byName  map[string]*BindEvent
		byTitle map[string]*BindEvent
	}
}

func New(sm *strman.StringManager) *Binding {
	kb := &Binding{sm: sm}
	kb.keys.list = make([]KeyBind, len(defKeyBinds))
	kb.events.list = make([]BindEvent, len(defBindEvents))
	copy(kb.keys.list, defKeyBinds)
	copy(kb.events.list, defBindEvents)
	kb.loadStrings()
	kb.index()
	return kb
}

func (kb *Binding) loadStrings() {
	for i := range kb.keys.list {
		b := &kb.keys.list[i]
		b.Title = kb.sm.GetString(b.TitleID)
	}
	for i := range kb.events.list {
		b := &kb.events.list[i]
		if i == 0 {
			b.Title = kb.sm.GetString("bindevent:NullEvent")
		} else {
			b.Title = kb.sm.GetString(strman.ID("bindevent:" + b.Name))
		}
	}
}

func (kb *Binding) index() {
	kb.keys.byKey = make(map[Key]*KeyBind)
	kb.keys.byName = make(map[string]*KeyBind)
	kb.keys.byTitle = make(map[string]*KeyBind)
	for i := range kb.keys.list {
		b := &kb.keys.list[i]
		kb.keys.byKey[b.Key] = b
		kb.keys.byName[b.Name] = b
		kb.keys.byTitle[strings.ToLower(b.Title)] = b
	}
	kb.events.byKey = make(map[Key]*BindEvent)
	kb.events.byName = make(map[string]*BindEvent)
	kb.events.byTitle = make(map[string]*BindEvent)
	for i := range kb.events.list {
		b := &kb.events.list[i]
		if b.Key != 0 {
			kb.events.byKey[b.Key] = b
		}
		if b.Name != "" {
			kb.events.byName[b.Name] = b
		}
		kb.events.byTitle[strings.ToLower(b.Title)] = b
	}
}

func (kb *Binding) Keys() []KeyBind {
	return kb.keys.list
}

func (kb *Binding) KeyByCode(key Key) *KeyBind {
	return kb.keys.byKey[key]
}

func (kb *Binding) KeyByName(name string) *KeyBind {
	return kb.keys.byName[name]
}

func (kb *Binding) KeyByTitle(title string) *KeyBind {
	return kb.keys.byTitle[strings.ToLower(title)]
}

func (kb *Binding) Events() []BindEvent {
	return kb.events.list[1:]
}

func (kb *Binding) EventByCode(key Key) *BindEvent {
	return kb.events.byKey[key]
}

func (kb *Binding) EventByName(name string) *BindEvent {
	return kb.events.byName[name]
}

func (kb *Binding) EventByTitle(title string) *BindEvent {
	return kb.events.byTitle[strings.ToLower(title)]
}
