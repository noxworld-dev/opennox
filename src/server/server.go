package server

import (
	"context"
	"sync/atomic"
	"time"

	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/platform"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox-lib/console"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/gsync"
)

var Log = log.New("server")

var (
	serverLast uintptr // atomic
	servers    gsync.Map[uintptr, *Server]
)

func getServer(h uintptr) *Server {
	s, _ := servers.Load(h)
	return s
}

func New(pr console.Printer, sm *strman.StringManager) *Server {
	s := &Server{
		pr: pr, sm: sm,
		loopHooks: make(chan func()),
		port:      common.GamePort,
	}
	s.handle = atomic.AddUintptr(&serverLast, 1)
	servers.Store(s.handle, s)
	s.Rand.init(nil)
	s.Types.init()
	s.Objs.init(s.handle)
	s.Modif.init(sm)
	s.Players.init()
	s.Teams.init(sm, pr)
	s.Abils.init(s)
	s.http.init()
	return s
}

type ObjectScriptID uint32

type Server struct {
	handle     uintptr
	pr         console.Printer
	sm         *strman.StringManager
	frame      uint32
	tickRate   uint32
	rateNext   time.Duration
	updateFunc func() bool
	tickHooks  tickHooks
	loopHooks  chan func()

	Rand       serverRandom
	Walls      serverWalls
	wps        serverWaypoints
	Types      serverObjTypes
	Objs       serverObjects
	Modif      serverModifiers
	Map        serverMap
	Doors      serverDoors
	MapGroups  ServerMapGroups
	Audio      serverAudio
	Activators serverActivators
	Players    serverPlayers
	Teams      serverTeams
	Abils      serverAbilities

	ShouldCallMapInit  bool
	ShouldCallMapEntry bool

	port int
	http httpService
	nat  natService

	updateFunc2 func() bool
}

func (s *Server) Close() {
	servers.Delete(s.handle)
}

func (s *Server) Printer() console.Printer {
	return s.pr
}

func (s *Server) Printf(cl console.Color, format string, args ...interface{}) {
	s.pr.Printf(cl, format, args...)
}

func (s *Server) Strings() *strman.StringManager {
	return s.sm
}

func (s *Server) Frame() uint32 {
	return atomic.LoadUint32(&s.frame)
}

func (s *Server) SetFrame(v uint32) {
	atomic.StoreUint32(&s.frame, v)
}

func (s *Server) IncFrame() {
	atomic.AddUint32(&s.frame, 1)
}

func (s *Server) SetInitialFrame() {
	if noxflags.HasGame(noxflags.GameHost) {
		s.SetFrame(1)
	} else {
		s.SetFrame(0)
	}
}

func (s *Server) TickRate() uint32 {
	return atomic.LoadUint32(&s.tickRate)
}

func (s *Server) SetTickRate(v uint32) {
	atomic.StoreUint32(&s.tickRate, v)
}

func (s *Server) AsFrames(dt ns4.Duration) int {
	if dt.IsInfinite() {
		return 0 // TODO: check
	}
	frames, ok := dt.Frames()
	if ok {
		return frames
	}
	dur, _ := dt.Time()
	return int(float64(s.TickRate()) * dur.Seconds())
}

func (s *Server) SetUpdateFunc(fnc func() bool) {
	s.updateFunc = fnc
}

func (s *Server) SetUpdateFunc2(fnc func() bool) {
	s.updateFunc2 = fnc
}

func (s *Server) Update() bool {
	if s.updateFunc == nil {
		return true
	}
	if !s.updateFunc() {
		return false
	}
	return true
}

func (s *Server) Update2() bool {
	if s.updateFunc2 == nil {
		return true
	}
	if !s.updateFunc2() {
		return false
	}
	return true
}

func (s *Server) QueueInLoop(ctx context.Context, fnc func()) {
	select {
	case <-ctx.Done():
	case s.loopHooks <- fnc:
	}
}

func (s *Server) RunLoopHooks() {
	s.LoopSleep(time.Millisecond)
}

func (s *Server) LoopSleep(dt time.Duration) {
	if dt <= 0 {
		return
	}
	tm := time.NewTimer(dt)
	defer tm.Stop()
	for {
		select {
		case <-tm.C:
			return
		case fnc := <-s.loopHooks:
			fnc()
		}
	}
}

func (s *Server) SetRateLimit(fps int) {
	step := time.Duration(0)
	if fps != 0 {
		step = time.Second / time.Duration(fps)
	}
	s.rateNext = platform.Ticks() + step
}

func (s *Server) RateWait() {
	ticks := platform.Ticks()
	dt := s.rateNext - ticks
	if dt > 0 {
		s.LoopSleep(dt)
	}
}

func (s *Server) SetServerPort(port int) {
	if port <= 0 {
		port = common.GamePort
	}
	s.port = port
}

func (s *Server) ServerPort() int {
	if s.port <= 0 {
		return common.GamePort
	}
	return s.port
}

func (s *Server) HTTPPort() int {
	return InferHTTPPort(s.ServerPort())
}

func InferHTTPPort(port int) int {
	return common.GameHTTPPort + (port - common.GamePort)
}
