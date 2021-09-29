package server

const (
	defaultFirstObjectScriptID = ObjectScriptID(1000000000)
)

func New() *Server {
	s := &Server{}
	return s
}

type ObjectScriptID uint32

type Server struct {
	objects struct {
		firstScriptID ObjectScriptID
		lastScriptID  ObjectScriptID
	}
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
