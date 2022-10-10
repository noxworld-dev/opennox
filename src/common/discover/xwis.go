package discover

import (
	"context"
	"fmt"
	"math/rand"
	"net/netip"
	"time"

	"github.com/noxworld-dev/lobby"
	"github.com/noxworld-dev/xwis"
)

func init() {
	xwisRand := rand.New(rand.NewSource(time.Now().UnixNano()))
	xwisName := fmt.Sprintf("jack%06x", xwisRand.Intn(0x1000000))
	const backend = "xwis"
	RegisterFallback("xwis", func(ctx context.Context, out chan<- Server) error {
		Log.Printf(backend+": using name: %s", xwisName)
		cli, err := xwis.NewClient(ctx, xwisName, xwisName)
		if err != nil {
			return err
		}
		defer cli.Close()

		rooms, err := cli.ListRooms(ctx)
		if err != nil {
			return err
		}

		for _, r := range rooms {
			if r.Game == nil {
				continue
			}
			ip, err := netip.ParseAddr(r.Game.Addr)
			if err != nil {
				Log.Printf(backend+": %q (%s): %v", r.Game.Addr, r.Game.Name, err)
				continue
			}
			Log.Printf(backend+": %s (%s)", ip, r.Game.Name)
			select {
			case <-ctx.Done():
				return ctx.Err()
			case out <- Server{
				IP:       ip,
				Source:   backend,
				Priority: priorityXWIS,
				NoPing:   true,
				Game:     *lobby.GameFromXWIS(r.Game),
			}:
			}
		}
		return nil
	})
}
