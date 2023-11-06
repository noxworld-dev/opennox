package server

import "github.com/noxworld-dev/opennox-lib/script"

type ScriptVMs struct {
	Curmap   string
	VMs      []script.VM
	VMByName map[string]script.VM
}

func (s *Server) ScriptTick() {
	for _, vm := range s.VMs.VMs {
		func() {
			defer func() {
				if r := recover(); r != nil {
					ScriptLog.Printf("panic in OnFrame: %v", r)
				}
			}()
			vm.OnFrame()
		}()
	}
	s.callOnScriptFrame()
}

func (s *Server) VMsShutdown() {
	s.NoxScriptVM.resetVirtualFuncs()
	if len(s.VMs.VMs) != 0 {
		ScriptLog.Printf("stopping script(s) for map %q", s.VMs.Curmap)
	}
	for _, vm := range s.VMs.VMs {
		_ = vm.Close()
	}
	s.VMs.VMs = nil
	s.VMs.VMByName = nil
	s.VMs.Curmap = ""
}
