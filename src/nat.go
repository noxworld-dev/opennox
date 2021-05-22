package main

import (
	"context"
	"os"

	"nox/v1/common/nat"
)

var (
	gameNAT func()
	useNAT  = os.Getenv("NOX_NET_NAT") != "false"
)

func gameStartNAT() error {
	if !useNAT {
		return nil
	}
	ctx, cancel := context.WithCancel(context.Background())
	go func() {
		stop, _ := nat.Map(ctx, []nat.Port{
			{Port: 18590, Proto: "udp", Desc: "Nox game port"},
			{Port: gameHTTPPort, Proto: "tcp", Desc: "Nox HTTP port"},
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
