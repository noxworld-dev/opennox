package opennox

import "C"
import (
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

//export sub_5002D0
func sub_5002D0(a1 *nox_object_t) {
	u := asUnitC(a1)
	sa, free := alloc.New(spellAcceptArg{})
	defer free()

	pl := u.ControllingPlayer()
	sa.Obj = u.CObj()
	sa.Pos = pl.CursorPos()
	noxServer.spells.duration.New(spell.SPELL_WALL, u, u, u, sa, 3, nil, nil, nil, 0)
}
