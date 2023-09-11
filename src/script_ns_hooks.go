package opennox

import (
	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/script"

	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) OnFrame(fnc ns4.FrameFunc) {
	s.s.OnScriptFrame(fnc)
}
func (s noxScriptNS) OnMapEvent(ev ns4.MapEvent, fnc ns4.MapEventFunc) {
	switch ev {
	case ns4.MapInitialize:
		s.s.OnMapEvent(script.EventMapInitialize, fnc)
	case ns4.MapEntry:
		s.s.OnMapEvent(script.EventMapEntry, fnc)
	case ns4.MapExit:
		s.s.OnMapEvent(script.EventMapExit, fnc)
	case ns4.MapShutdown:
		s.s.OnMapEvent(script.EventMapShutdown, fnc)
	}
}
func (s noxScriptNS) OnChat(fnc ns4.ChatFunc) {
	s.s.OnChat(func(t *server.Team, p *server.Player, obj *server.Object, msg string) string {
		var (
			tm ns4.Team
			pl ns4.Player
			no ns4.Obj
		)
		if t != nil {
			tm = nsTeam{s.s, t}
		}
		if p != nil {
			pl = nsPlayer{s.s, asPlayerS(p)}
		}
		if obj != nil {
			no = nsObj{s.s, asObjectS(obj)}
		}
		return fnc(tm, pl, no, msg)
	})
}
