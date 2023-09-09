package opennox

import (
	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/common"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

var _ ns4.Game = noxScriptImpl{}

func (s *Server) NoxScript() ns4.Implementation {
	return noxScriptNS{s}
}

func (s noxScriptImpl) NoxScript() ns4.Implementation {
	return s.s.NoxScript()
}

type noxScriptNS struct {
	s *Server
}

func (s noxScriptNS) TimerByHandle(h ns4.TimerHandle) ns4.Timer {
	if h == nil {
		return nil
	}
	id := h.TimerScriptID()
	if id <= 0 {
		return nil
	}
	return nsTimer{s: s.s, id: uint32(id)}
}

func (s noxScriptNS) NewTimer(dt ns4.Duration, fnc ns4.Func, args ...any) ns4.Timer {
	if dt.IsInfinite() {
		panic("trying to create an infinite timer")
	}
	var arg uint32
	switch len(args) {
	default:
		panic("more than one timer arguments are not supported yet")
	case 0:
		arg = 0
	case 1:
		arg = s.s.noxScript.AsValue(args[0])
	}
	id := s.s.NewTimer(s.s.AsFrames(dt), s.s.noxScript.AsFuncIndex("Timer", fnc), arg)
	return nsTimer{s: s.s, id: id}
}

func (s noxScriptNS) RandomFloat(min float32, max float32) float32 {
	return float32(s.s.Rand.Logic.FloatClamp(float64(min), float64(max)))
}

func (s noxScriptNS) Random(min int, max int) int {
	return s.s.Rand.Logic.IntClamp(min, max)
}

func (s noxScriptNS) StopScript(val any) {
	panic(val)
}

func (s noxScriptNS) AutoSave() {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		SaveCoop(common.SaveAuto)
	}
}

type nsTimer struct {
	s  *Server
	id uint32
}

func (t nsTimer) ScriptID() int {
	return int(t.id)
}

func (t nsTimer) TimerScriptID() int {
	return int(t.id)
}

func (t nsTimer) Cancel() bool {
	return t.s.Activators.Cancel(t.id)
}
