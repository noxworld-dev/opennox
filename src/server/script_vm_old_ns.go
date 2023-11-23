package server

func (s *Server) NoxScriptNSVM() NoxScriptNSVM {
	return NoxScriptNSVM{s}
}

type NoxScriptNSVM struct {
	s *Server
}

func (s NoxScriptNSVM) NewString(val string) uint32 {
	return s.s.NoxScriptVM.NewString(val)
}

func (s NoxScriptNSVM) GetString(val uint32) string {
	return s.s.NoxScriptVM.GetString(val)
}

func (s NoxScriptNSVM) GetFuncVar(fnc int, vari int) uint32 {
	v, _ := s.s.NoxScriptVM.GetFuncVar(fnc, vari)
	return v
}

func (s NoxScriptNSVM) GetFuncInd(fnc string) int {
	_, fi := s.s.NoxScriptVM.FuncByName(fnc)
	return fi
}

func (s NoxScriptNSVM) SetFuncVar(fnc int, vari int, val uint32) {
	_ = s.s.NoxScriptVM.SetFuncVar(fnc, vari, val)
}

func (s NoxScriptNSVM) CallFunc(fnc int, args []uint32) uint32 {
	ret, _ := s.s.NoxScriptVM.CallFuncInd(fnc, args)
	return ret
}
