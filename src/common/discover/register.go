package discover

import (
	"context"
	"log"
	"os"

	"github.com/noxworld-dev/xwis"
)

var xwisLog = log.New(os.Stderr, "[xwis]: ", log.LstdFlags|log.Lmsgprefix)

// RegisterGame will keep the game registered until context is cancelled.
func RegisterGame(ctx context.Context, info xwis.GameInfo) error {
	if info.Name == "" {
		info.Name = "Noxg Server"
	}
	if info.Map == "" {
		info.Map = "estate"
	}
	if info.MapType == 0 {
		info.MapType = xwis.MapTypeChat
	}
	if info.Resolution == 0 {
		info.Resolution = xwis.Res1024x768
	}
	if info.MaxPlayers == 0 {
		info.MaxPlayers = 32
	}
	cli, err := xwis.NewClient(ctx, "", "")
	if err != nil {
		xwisLog.Printf("failed to init: %v", err)
		return err
	}
	defer cli.Close()

	// TODO: actually update those values according to what server is doing
	xwisLog.Println("registering server")
	err = cli.HostGame(ctx, info)
	if err != nil {
		xwisLog.Printf("failed to host: %v", err)
		return err
	}
	return nil
}
