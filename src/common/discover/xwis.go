package discover

import (
	"context"
	"fmt"
	"math/rand"
	"net"
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
			ip := net.ParseIP(r.Game.Addr).To4()
			if ip == nil {
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
