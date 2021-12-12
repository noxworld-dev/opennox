package keybind

import (
	"strings"

	"nox/v1/common/strman"
)

type Event uint32

type BindEvent struct {
	Name  string
	Event Event
	Title string
}

type Binding struct {
	sm     *strman.StringManager
	events struct {
		list    []BindEvent
		byKey   map[Event]*BindEvent
		byName  map[string]*BindEvent
		byTitle map[string]*BindEvent
	}
}

func New(sm *strman.StringManager) *Binding {
	kb := &Binding{sm: sm}
	kb.events.list = make([]BindEvent, len(defBindEvents))
	copy(kb.events.list, defBindEvents)
	kb.loadStrings()
	kb.index()
	return kb
}

func (kb *Binding) loadStrings() {
	for i := range kb.events.list {
		b := &kb.events.list[i]
		if i == 0 {
			b.Title = kb.sm.GetString("bindevent:NullEvent")
		} else if b.Title == "" {
			b.Title = kb.sm.GetString(strman.ID("bindevent:" + b.Name))
		}
	}
}

func (kb *Binding) index() {
	kb.events.byKey = make(map[Event]*BindEvent)
	kb.events.byName = make(map[string]*BindEvent)
	kb.events.byTitle = make(map[string]*BindEvent)
	for i := range kb.events.list {
		b := &kb.events.list[i]
		if b.Event != 0 {
			kb.events.byKey[b.Event] = b
		}
		if b.Name != "" {
			kb.events.byName[b.Name] = b
		}
		kb.events.byTitle[strings.ToLower(b.Title)] = b
	}
}

func (kb *Binding) Events() []BindEvent {
	return kb.events.list[1:]
}

func (kb *Binding) EventByCode(key Event) *BindEvent {
	return kb.events.byKey[key]
}

func (kb *Binding) EventByName(name string) *BindEvent {
	return kb.events.byName[name]
}

func (kb *Binding) EventByTitle(title string) *BindEvent {
	return kb.events.byTitle[strings.ToLower(title)]
}
