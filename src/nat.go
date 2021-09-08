package main

import (
	"context"
	"os"

	"nox/v1/common/env"
	"nox/v1/common/log"

	"github.com/noxworld-dev/nat"
)

var (
	gameNAT func()
	useNAT  = os.Getenv("NOX_NET_NAT") != "false"
)

func init() {
	nat.Log = log.New("nat")
	nat.LogUPNP = log.New("nat-upnp")
}

func gameStartNAT(port, hport int) error {
	if !useNAT || env.IsE2E() {
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
	gameNAT = cancel
	return nil
}

func gameStopNAT() {
	if gameNAT != nil {
		gameNAT()
		gameNAT = nil
	}
}
