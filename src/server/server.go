package server

import (
	"nox/v1/common/console"
	"nox/v1/common/strman"
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
	pr      console.Printer
	sm      *strman.StringManager
	objects struct {
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
