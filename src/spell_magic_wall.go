package opennox

import (
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_5002D0(a1 *server.Object) {
	u := asObjectS(a1)
	sa, free := alloc.New(server.SpellAcceptArg{})
	defer free()

	pl := u.ControllingPlayer()
	sa.Obj = u.SObj()
	sa.Pos = pl.CursorPos()
	noxServer.spells.duration.New(spell.SPELL_WALL, u.SObj(), u.SObj(), u.SObj(), sa, 3, nil, nil, nil, 0)
}
