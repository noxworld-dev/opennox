// Package discover implements Nox server discovery.
package discover

import (
	"context"
	"net"
	"strconv"
	"sync"
	"time"

	"nox/v1/common/log"
)

const (
	discoverTimeout = 5 * time.Second
)

var (
	Log = log.New("discover")
)

type Server struct {
	Priority int    // lower values mean higher priority
	Addr     net.IP // only IPv4 for now
	Port     int
}

func (s Server) String() string {
	return s.Addr.String() + ":" + strconv.Itoa(s.Port)
}

type SearchFunc func(ctx context.Context, out chan<- Server) error

var (
	backends = make(map[string]SearchFunc)
)

// RegisterBackend register a new server discovery backend.
func RegisterBackend(name string, fnc SearchFunc) {
	if _, ok := backends[name]; ok {
		panic("already registered: " + name)
	}
	backends[name] = fnc
}

// Servers discover Nox servers and sends them to the channel.
func Servers(ctx context.Context, out chan<- Server) error {
	var (
		wg   sync.WaitGroup
		errc = make(chan error, 1)
	)
	for name, fnc := range backends {
		wg.Add(1)
		name, fnc := name, fnc
		go func() {
			defer wg.Done()
			if err := fnc(ctx, out); err != nil {
				Log.Printf("%s: %v", name, err)
				select {
				case errc <- err:
				default:
				}
			}
		}()
	}
	wg.Wait()
	select {
	case err := <-errc:
		return err
	default:
	}
	return nil
}

type ServerFunc func(s Server) error

// EachServer discovers Nox servers and calls fnc for each of them sequentially.
func EachServer(ctx context.Context, fnc ServerFunc) error {
	Log.Println("searching for servers...")
	if _, ok := ctx.Deadline(); !ok {
		var cancel func()
		ctx, cancel = context.WithTimeout(ctx, discoverTimeout)
		defer cancel()
	}

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
