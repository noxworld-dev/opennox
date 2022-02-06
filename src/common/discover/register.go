package discover

import (
	"context"
	"sync"
	"time"

	"github.com/noxworld-dev/lobby"
	"github.com/noxworld-dev/xwis"
	"golang.org/x/sync/errgroup"

	"nox/v1/common/log"
)

const (
	lobbyInterval = lobby.DefaultTimeout / 3
)

var (
	lobbyLog = log.New("lobby")
	xwisLog  = log.New("xwis")
)

type GameInfo struct {
	lobby.Game
	XWIS xwis.GameInfo
}

// NewServer registers the server with initial game info.
// It will automatically retry the registration until the server is closed.
func NewServer(info GameInfo) *RegServer {
	ctx, stop := context.WithCancel(context.Background())
	s := &RegServer{
		stop:  stop,
		ticks: make(chan time.Time, 1),
		xwis:  make(chan struct{}, 1),
		cur:   info,
	}
	s.wg.Go(func() error {
		ticker := time.NewTicker(lobbyInterval)
		defer ticker.Stop()
		var t time.Time
		for {
			select {
			case <-ctx.Done():
				return nil
			case t = <-ticker.C:
			}
			select {
			case <-ctx.Done():
				return nil
			case s.ticks <- t:
			}
		}
	})
	s.wg.Go(func() error {
		return s.doLobby(ctx)
	})
	s.wg.Go(func() error {
		return s.doXWIS(ctx)
	})
	return s
}

type RegServer struct {
	wg    errgroup.Group
	stop  func()
	ticks chan time.Time
	xwis  chan struct{}

	mu  sync.RWMutex
	cur GameInfo
}

func (s *RegServer) Update(info GameInfo) {
	infoSetDefaults(&info.XWIS)
	s.mu.Lock()
	s.cur = info
	s.mu.Unlock()
	select {
	case s.ticks <- time.Now():
	default:
	}
	select {
	case s.xwis <- struct{}{}:
	default:
	}
}

func (s *RegServer) Close() error {
	if s.stop == nil {
		return nil
	}
	s.stop()
	s.stop = nil
	return s.wg.Wait()
}

func (s *RegServer) info() GameInfo {
	s.mu.RLock()
	info := s.cur
	s.mu.RUnlock()
	return info
}

type gameRegHost struct {
	s *RegServer
}

func (h gameRegHost) GameInfo(ctx context.Context) (*lobby.Game, error) {
	info := h.s.info()
	return &info.Game, nil
}

func (s *RegServer) doLobby(ctx context.Context) error {
	cli := newLobbyClient()
	for {
		if err := lobby.KeepRegistered(ctx, cli, s.ticks, gameRegHost{s: s}); err != nil {
			lobbyLog.Println(err)
		}
		select {
		case <-ctx.Done():
			return nil
		default:
		}
	}
}

func (s *RegServer) doXWIS(ctx context.Context) error {
	for {
		err := s.xwisReopenAndLoop(ctx)
		select {
		case <-ctx.Done():
			return nil
		default:
		}
		if err != nil {
			xwisLog.Println(err)
		}
		select {
		case <-ctx.Done():
			return nil
		case <-time.After(3 * time.Second):
		}
	}
}

func (s *RegServer) xwisReopenAndLoop(ctx context.Context) error {
	cli, err := xwis.NewClient(ctx, "", "")
	if err != nil {
		return err
	}
	defer cli.Close()

	for try := 0; ; try++ {
		game, err := cli.RegisterGame(ctx, s.info().XWIS)
		if err != nil {
			xwisLog.Println("registration failed:", err)
			select {
			case <-ctx.Done():
				return nil
			case <-time.After(3 * time.Second):
			}
			continue
		}
		if try >= 5 {
			return err
		}
		if err := s.xwisUpdateLoop(ctx, game); err != nil {
			xwisLog.Println("update failed:", err)
		}
	}

}

func (s *RegServer) xwisUpdateLoop(ctx context.Context, game *xwis.Game) error {
	for {
		select {
		case <-ctx.Done():
			return ctx.Err()
		case <-s.xwis:
		}
		if err := game.Update(ctx, s.info().XWIS); err != nil {
			return err
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
