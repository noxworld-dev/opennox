package nox

import (
	"context"

	"nox/v1/common/env"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/log"

	"github.com/noxworld-dev/nat"
)

var (
	useNAT = true
)

type natService struct {
	stop func()
}

func init() {
	nat.Log = log.New("nat")
	nat.LogUPNP = log.New("nat-upnp")
	configBoolPtr("network.port_forward", "NOX_NET_NAT", true, &useNAT)
}

func (s *Server) gameStartNAT(port, hport int) error {
	if !useNAT || !noxflags.HasGame(noxflags.GameOnline) || env.IsE2E() {
		return nil
	}
	ctx, cancel := context.WithCancel(context.Background())
	go func() {
		stop, _ := nat.Map(ctx, []nat.Port{
			{Port: port, Proto: "udp", Desc: "Nox game port"},
			{Port: hport, Proto: "tcp", Desc: "Nox HTTP port"},
		})
		if stop != nil {
			<-ctx.Done()
			stop()
		}
	}()
	s.nat.stop = cancel
	return nil
}

func (s *Server) gameStopNAT() {
	if s.nat.stop != nil {
		s.nat.stop()
		s.nat.stop = nil
	}
}
