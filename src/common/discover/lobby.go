package discover

import (
	"context"
	"net"

	"github.com/noxworld-dev/lobby"

	"nox/v1/internal/version"
)

const (
	lobbyServer = "http://nox.nwca.xyz:8088"
)

func newLobbyClient() *lobby.Client {
	cli := lobby.NewClient(lobbyServer)
	cli.SetUserAgent("OpenNox/" + version.Version())
	return cli
}

func init() {
	RegisterBackend("lobby", func(ctx context.Context, out chan<- Server) error {
		cli := newLobbyClient()
		rooms, err := cli.ListGames(ctx)
		if err != nil {
			return err
		}
		for _, g := range rooms {
			ip := net.ParseIP(g.Address).To4()
			if ip == nil {
				continue
			}
			Log.Printf("lobby: %s (%s)", ip, g.Name)
			select {
			case <-ctx.Done():
				return ctx.Err()
			case out <- Server{Priority: 0, Addr: ip, Port: g.Port}:
			}
		}
		return nil
	})
}
