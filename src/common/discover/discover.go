// Package discover implements Nox server discovery.
package discover

import (
	"context"
	"log"
	"net"
	"os"
	"time"
)

const (
	discoverTimeout = 5 * time.Second
)

var (
	Log = log.New(os.Stderr, "[discover]: ", log.LstdFlags|log.Lmsgprefix)
)

type Server struct {
	Addr net.IP // only IPv4 for now
}

// Servers discover Nox servers and sends them to the channel.
func Servers(ctx context.Context, out chan<- Server) error {
	list, err := staticIPs(StaticFile)
	if len(list) == 0 {
		return err
	}
	for _, s := range list {
		select {
		case <-ctx.Done():
			return ctx.Err()
		case out <- s:
		}
	}
	return nil
}

type ServerFunc func(s Server) error

// EachServer discovers Nox servers and calls fnc for each of them sequentially.
func EachServer(ctx context.Context, fnc ServerFunc) error {
	Log.Println("searching for servers...")
	ctx, cancel := context.WithTimeout(ctx, discoverTimeout)
	defer cancel()

	out := make(chan Server, 10)
	errc := make(chan error, 1)

	go func() {
		defer close(out)
		if err := Servers(ctx, out); err != nil {
			errc <- err
		}
	}()

	n := 0
	defer func() {
		Log.Printf("found %d server(s)", n)
	}()
	for s := range out {
		n++
		if err := fnc(s); err != nil {
			return err
		}
	}
	select {
	case err := <-errc:
		return err
	default:
	}
	return nil
}
