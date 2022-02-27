package discover

import (
	"context"
	"net"

	"github.com/noxworld-dev/lobby"

	"nox/v1/internal/version"
)

var (
	// LobbyServer is an address of the Nox lobby server used for discovery.
	LobbyServer = "http://nox.nwca.xyz:8088"
)

func newLobbyClient() *lobby.Client {
	cli := lobby.NewClient(LobbyServer)
	cli.SetUserAgent("OpenNox/" + version.Version())
	return cli
}

func init() {
	const backend = "lobby"
	RegisterBackend(backend, func(ctx context.Context, out chan<- Server) error {
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
			g := g.Game
			Log.Printf("lobby: %s (%s)", ip, g.Name)
			select {
			case <-ctx.Done():
				return ctx.Err()
			case out <- Server{
				IP:       ip,
				Source:   backend,
				Priority: priorityLobby,
				Game:     g,
			}:
			}
		}
		return nil
	})
}
