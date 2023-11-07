package opennox

import (
	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/common"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

var _ ns4.Game = noxScriptImpl{}

func (s *Server) NoxScript() ns4.Implementation {
	return noxScriptNS{s, s.Server.NoxScriptNS()}
}

func (s noxScriptImpl) NoxScript() ns4.Implementation {
	return s.s.NoxScript()
}

type noxScriptNS struct {
	s *Server
	server.NoxScriptNS
}

func (s noxScriptNS) AutoSave() {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		SaveCoop(common.SaveAuto)
	}
}
