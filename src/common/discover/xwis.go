package discover

import (
	"context"
	"fmt"
	"math/rand"
	"net"
	"sync"
	"time"

	"github.com/noxworld-dev/xwis"
)

var (
	xwisRand = rand.New(rand.NewSource(time.Now().UnixNano()))
	xwisName = fmt.Sprintf("jack%06x", xwisRand.Intn(0x1000000))

	xwisMu    sync.Mutex
	xwisRooms []xwis.Room
)

func XWISRooms() []xwis.Room {
	// TODO: this is a workaround; XWIS doesn't allow to reconnect twice for some reason (IP discovery + WOL scan)
	xwisMu.Lock()
	rooms := xwisRooms
	xwisMu.Unlock()
	return rooms
}

func init() {
	RegisterBackend("xwis", func(ctx context.Context, out chan<- Server) error {
		Log.Printf("using name: %s", xwisName)
		cli, err := xwis.NewClient(ctx, xwisName, xwisName)
		if err != nil {
			return err
		}
		defer cli.Close()

		rooms, err := cli.ListRooms(ctx)
		if err != nil {
			return err
		}
		xwisMu.Lock()
		xwisRooms = rooms
		xwisMu.Unlock()

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
