package server

import "github.com/noxworld-dev/noxscript/ns/v4"

func (s NoxScriptNS) ClearMessages(pl ns.Obj) {
	if pl == nil {
		return
	}
	u := nsToObj(pl)
	s.s.Nox_xxx_netScriptMessageKill_4D9760(u)
}
