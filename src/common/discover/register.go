package discover

import (
	"context"
	"time"

	"github.com/noxworld-dev/xwis"

	"nox/v1/common/log"
)

var xwisLog = log.New("xwis")

// NewServer registers the server with initial game info.
// It will automatically retry the registration until the server is closed.
func NewServer(info xwis.GameInfo) *RegServer {
	upd := make(chan xwis.GameInfo, 1)
	upd <- info
	s := &RegServer{
		upd:  upd,
		done: make(chan struct{}),
	}
	go s.do()
	return s
}

type RegServer struct {
	upd  chan xwis.GameInfo
	done chan struct{}
}

func (s *RegServer) Update(info xwis.GameInfo) {
	if s.done == nil {
		return
	}
	// remove old value, if any
	select {
	case _, ok := <-s.upd:
		if !ok {
			return
		}
	default:
	}
	// put the new one
	select {
	case s.upd <- info:
	default:
	}
}

func (s *RegServer) Close() error {
	if s.done == nil {
		return nil
	}
	close(s.upd)
	<-s.done
	s.done = nil
	return nil
}

func (s *RegServer) do() {
	defer close(s.done)
	var (
		gcancel func()
		gdone   chan struct{}
	)
	stop := func() {
		if gcancel != nil {
			gcancel()
			gcancel = nil
			<-gdone
		}
	}
	defer stop()
	for info := range s.upd {
		stop()
		info := info
		ctx, cancel := context.WithCancel(context.Background())
		done := make(chan struct{})
		go func() {
			defer close(done)
			infoSetDefaults(&info)
			s.register(ctx, info)
		}()
		gcancel, gdone = cancel, done
	}
}

func (s *RegServer) register(ctx context.Context, info xwis.GameInfo) {
	// TODO: supports game info updates in XWIS library
	for {
		xwisLog.Println("updating game info...")
		var (
			cli *xwis.Client
			err error
		)
		for {
			cli, err = xwis.NewClient(ctx, "", "")
			if err == nil {
				break
			}
			xwisLog.Println("cannot initialize:", err)
			select {
			case <-ctx.Done():
				return
			case <-time.After(3 * time.Second):
			}
		}
		if err := cli.HostGame(ctx, info); err != nil {
			xwisLog.Println(err)
		}
		cli.Close()
		select {
		case <-ctx.Done():
			return
		case <-time.After(3 * time.Second):
		}
	}
}

func infoSetDefaults(info *xwis.GameInfo) {
	if info.Name == "" {
		info.Name = "OpenNox Server"
	}
	if info.Map == "" {
		info.Map = "estate"
	}
	if info.MapType == 0 && info.Flags == 0 {
		info.MapType = xwis.MapTypeChat
	}
	if info.Resolution == 0 {
		info.Resolution = xwis.Res1024x768
	}
	if info.MaxPlayers == 0 {
		info.MaxPlayers = 32
	}
}
