package player

import "fmt"

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
		return fmt.Sprintf("player.Class(%d)", int(c))
	}
}
