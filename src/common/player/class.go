package player

import "encoding/json"

var (
	_ json.Marshaler = Class(0)
)

const (
	Warrior  = Class(0)
	Wizard   = Class(1)
	Conjurer = Class(2)
)

type Class byte

func (c Class) String() string {
	switch c {
	case Warrior:
		return "warrior"
	case Wizard:
		return "wizard"
	case Conjurer:
		return "conjurer"
	default:
		return "unknown"
	}
}

func (c Class) MarshalJSON() ([]byte, error) {
	return json.Marshal(c.String())
}
