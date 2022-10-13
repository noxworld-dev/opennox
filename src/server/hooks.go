package server

import "sync"

type tickHooks struct {
	mu        sync.Mutex
	callbacks []func() // one time
	hooks     []func() // persistent
}

func (s *Server) TickCallback(fnc func()) {
	s.tickHooks.mu.Lock()
	s.tickHooks.callbacks = append(s.tickHooks.callbacks, fnc)
	s.tickHooks.mu.Unlock()
}

func (s *Server) TickHook(fnc func()) {
	s.tickHooks.mu.Lock()
	s.tickHooks.hooks = append(s.tickHooks.hooks, fnc)
	s.tickHooks.mu.Unlock()
}

func (s *Server) RunTickHooks() {
	s.tickHooks.mu.Lock()
	defer s.tickHooks.mu.Unlock()
	for _, fnc := range s.tickHooks.hooks {
		fnc()
	}
	for i, fnc := range s.tickHooks.callbacks {
		fnc()
		s.tickHooks.callbacks[i] = nil
	}
	s.tickHooks.callbacks = s.tickHooks.callbacks[:0]
}
