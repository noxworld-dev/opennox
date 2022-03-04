package gui

import "fmt"

var (
	stateByID = make(map[StateID]*state)
)

type state struct {
	Name string
	Func StateFunc
}

type StateFunc func() bool

func RegisterState(id StateID, name string, fnc StateFunc) {
	if id <= 0 {
		panic("invalid id")
	}
	if fnc == nil {
		panic("no function")
	}
	if _, ok := stateByID[id]; ok {
		panic("already registered")
	}
	stateByID[id] = &state{Name: name, Func: fnc}
}

const (
	StateNone = StateID(-1)
)

type StateID int

func (st StateID) String() string {
	if st == StateNone {
		return "<none>"
	}
	if s := stateByID[st]; s != nil && s.Name != "" {
		return s.Name
	}
	return fmt.Sprintf("gui.StateID(%d)", int(st))
}

type State struct {
	states []StateID
}

func (s *State) Current() StateID {
	if len(s.states) == 0 {
		return StateNone
	}
	return s.states[len(s.states)-1]
}

func (s *State) Pop() {
	if len(s.states) > 0 {
		s.states = s.states[:len(s.states)-1]
	}
}

func (s *State) PopUntil(code StateID) {
	for s.Current() != code {
		s.Pop()
	}
}

func (s *State) Push(code StateID) bool {
	if s.Current() == code {
		return false
	}
	s.states = append(s.states, code)
	return true
}

func (s *State) Switch() bool {
	st := stateByID[s.Current()]
	if st == nil || st.Func == nil {
		return true
	}
	return st.Func()
}
