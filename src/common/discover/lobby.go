package discover

import (
	"context"
	"net/netip"

	"github.com/noxworld-dev/lobby"

	"github.com/noxworld-dev/opennox/v1/internal/version"
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
			ip, err := netip.ParseAddr(g.Address)
			if err != nil {
				Log.Printf("lobby: %q (%s): %v", g.Address, g.Name, err)
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
