package server

import (
	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/script"
)

func (s NoxScriptNS) OnFrame(fnc ns4.FrameFunc) {
	s.s.OnScriptFrame(fnc)
}
func (s NoxScriptNS) OnMapEvent(ev ns4.MapEvent, fnc ns4.MapEventFunc) {
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
