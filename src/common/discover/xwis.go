package discover

import (
	"context"
	"net"

	"github.com/noxworld-dev/xwis"
)

func init() {
	RegisterBackend("xwis", func(ctx context.Context, out chan<- Server) error {
		cli, err := xwis.NewClient(ctx, "", "")
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
			Log.Printf("xwis: %s (%s)", ip, r.Game.Name)
			select {
			case <-ctx.Done():
				return ctx.Err()
			case out <- Server{Addr: ip}:
			}
		}
		return nil
	})
}
