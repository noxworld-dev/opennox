package server

import (
	"context"
	"sync/atomic"
	"time"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/platform"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox-lib/console"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

const (
	defaultFirstObjectScriptID = ObjectScriptID(1000000000)
)

var Log = log.New("server")

func New(pr console.Printer, sm *strman.StringManager) *Server {
	s := &Server{
		pr: pr, sm: sm,
		loopHooks: make(chan func()),
		port:      common.GamePort,
	}
	s.types.Init()
	s.http.init()
	return s
}

type ObjectScriptID uint32

type Server struct {
	pr         console.Printer
	sm         *strman.StringManager
	frame      uint32
	tickRate   uint32
	rateNext   time.Duration
	updateFunc func() bool
	tickHooks  tickHooks
	loopHooks  chan func()

	types   serverObjTypes
	Objs    serverObjects
	Map     serverMap
	Audio   serverAudio
	objects struct {
		firstScriptID ObjectScriptID
		lastScriptID  ObjectScriptID
	}

	port int
	http httpService
	nat  natService
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

func (s *Server) LastObjectScriptID() ObjectScriptID {
	return s.objects.lastScriptID
}

func (s *Server) NextObjectScriptID() ObjectScriptID {
	id := s.objects.lastScriptID
	s.objects.lastScriptID++
	return id
}

func (s *Server) SetLastObjectScriptID(id ObjectScriptID) {
	s.objects.lastScriptID = id
}

func (s *Server) SetFirstObjectScriptID(id ObjectScriptID) {
	s.objects.firstScriptID = id
}

func (s *Server) ResetObjectScriptIDs() {
	s.SetLastObjectScriptID(defaultFirstObjectScriptID)
	if s.objects.firstScriptID != 0 {
		s.SetLastObjectScriptID(s.objects.firstScriptID)
	}
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

func (s *Server) SetUpdateFunc(fnc func() bool) {
	s.updateFunc = fnc
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
