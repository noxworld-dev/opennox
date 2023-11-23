package opennox

import (
	ns3vm "github.com/noxworld-dev/noxscript/ns/v3/vm"
	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/common"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	_ ns4.Game   = noxScriptImpl{}
	_ ns3vm.Game = noxScriptImpl{}
)

func (s *Server) NoxScript() ns4.Implementation {
	return noxScriptNS{s, s.Server.NoxScriptNS()}
}

func (s *Server) NoxScriptVM() ns3vm.Implementation {
	return s.NoxScriptNSVM()
}

func (s noxScriptImpl) NoxScript() ns4.Implementation {
	return s.s.NoxScript()
}

func (s noxScriptImpl) NoxScriptVM() ns3vm.Implementation {
	return s.s.NoxScriptVM()
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
