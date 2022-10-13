package server

import (
	"sync/atomic"

	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox-lib/console"
)

const (
	defaultFirstObjectScriptID = ObjectScriptID(1000000000)
)

func New(pr console.Printer, sm *strman.StringManager) *Server {
	s := &Server{pr: pr, sm: sm}
	return s
}

type ObjectScriptID uint32

type Server struct {
	pr       console.Printer
	sm       *strman.StringManager
	frame    uint32
	tickRate uint32
	objects  struct {
		firstScriptID ObjectScriptID
		lastScriptID  ObjectScriptID
	}
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

func (s *Server) TickRate() uint32 {
	return atomic.LoadUint32(&s.tickRate)
}

func (s *Server) SetTickRate(v uint32) {
	atomic.StoreUint32(&s.tickRate, v)
}
