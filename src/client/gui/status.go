package gui

const (
	StatusActive     = StatusFlags(1 << iota) // 0x1
	StatusToggle                              // 0x2
	StatusDraggable                           // 0x4
	StatusEnabled                             // 0x8
	StatusHidden                              // 0x10
	StatusAbove                               // 0x20
	StatusBelow                               // 0x40
	StatusImage                               // 0x80
	StatusTabStop                             // 0x100
	StatusNoInput                             // 0x200
	StatusNoFocus                             // 0x400
	StatusDestroyed                           // 0x800
	StatusBorder                              // 0x1000
	StatusSmoothText                          // 0x2000
	StatusOneLine                             // 0x4000
	StatusNoFlush                             // 0x8000
)

type StatusFlags uint32

func (s StatusFlags) Has(s2 StatusFlags) bool {
	return s&s2 != 0
}

func (s StatusFlags) HasNone(s2 StatusFlags) bool {
	return s&s2 == 0
}

func (s *StatusFlags) Set(s2 StatusFlags) {
	*s |= s2
}

func (s StatusFlags) IsEnabled() bool {
	return s.Has(StatusEnabled)
}

func (s StatusFlags) IsHidden() bool {
	return s.Has(StatusHidden)
}
