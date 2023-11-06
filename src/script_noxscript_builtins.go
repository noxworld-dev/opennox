package opennox

import (
	"errors"
	"fmt"
	"image"

	"github.com/noxworld-dev/noxscript/ns/asm"
	ns4 "github.com/noxworld-dev/noxscript/ns/v4"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
	"github.com/noxworld-dev/opennox/v1/server/noxscript"
)

func nox_script_shouldReadMoreXxx(fi asm.Builtin) bool {
	return fi == 9 || fi == 10 ||
		fi == 46 || fi == 47 ||
		fi == 190 || fi == 126
}

func nox_script_shouldReadEvenMoreXxx(fi asm.Builtin) bool {
	return fi == asm.BuiltinSetDialog
}

var errStopScript = errors.New("noxscript: exit")

func (s *noxScript) callBuiltinNative(fi asm.Builtin) error {
	res, ok := noxscript.CallBuiltin(s, fi)
	if !ok {
		res, ok = s.PanicScriptCall(fi)
	}
	if !ok {
		res, ok = legacy.CallScriptBuiltin(fi)
	}
	if !ok {
		if fi < 0 || int(fi) >= len(noxScriptBuiltins) {
			return fmt.Errorf("noxscript: invalid builtin index: %d (%x)", fi, fi)
		}
		res = noxScriptBuiltins[fi](s)
	}
	if res != 0 {
		if fi == asm.BuiltinStopScript {
			return errStopScript
		}
		return fmt.Errorf("noxscript: builtin %v failed", fi)
	}
	return nil
}

var noxScriptBuiltins = [asm.BuiltinGetScore + 1]noxscript.Builtin{
	asm.BuiltinSecondTimer:        nsSecondTimer,
	asm.BuiltinFrameTimer:         nsFrameTimer,
	asm.BuiltinSecondTimerWithArg: nsSecondTimerArg,
	asm.BuiltinFrameTimerWithArg:  nsFrameTimerArg,
	asm.BuiltinCancelTimer:        nsCancelTimer,
}

func nsSecondTimer(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int(s.PopU32())
	dt := s.PopU32()
	s.PushU32(s.s.NewTimer(int(s.s.SecToFrames(int(dt))), fnc, 0))
	return 0
}

func nsFrameTimer(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int(s.PopU32())
	df := int(s.PopU32())
	s.PushU32(s.s.NewTimer(df, fnc, 0))
	return 0
}

func nsSecondTimerArg(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int(s.PopU32())
	arg := s.PopU32()
	dt := s.PopU32()
	s.PushU32(s.s.NewTimer(int(s.s.SecToFrames(int(dt))), fnc, arg))
	return 0
}

func nsFrameTimerArg(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int(s.PopU32())
	arg := s.PopU32()
	df := int(s.PopU32())
	s.PushU32(s.s.NewTimer(df, fnc, arg))
	return 0
}

// TODO: migrate all usage of `nox_server_scriptExecuteFnForEachGroupObj_502670` to use these funcs below.

func eachObjectNS(s *Server, g *server.MapGroup, fnc func(obj ns4.Obj) bool) {
	if g == nil {
		return
	}
	switch g.GroupType() {
	case server.MapGroupObjects:
		for it := g.First(); it != nil; it = it.Next() {
			if obj := s.Objs.GetObjectByInd(it.Data1()); obj != nil {
				if !fnc(nsObj{s, asObjectS(obj)}) {
					return
				}
			}
		}
	}
}

func eachObjectRecursiveNS(s *Server, g *server.MapGroup, fnc func(obj ns4.Obj) bool) bool { // nox_server_scriptExecuteFnForEachGroupObj_502670
	if g == nil {
		return true // just skip this group
	}
	switch g.GroupType() {
	case server.MapGroupObjects:
		for it := g.First(); it != nil; it = it.Next() {
			if obj := s.Objs.GetObjectByInd(it.Data1()); obj != nil {
				if !fnc(nsObj{s, asObjectS(obj)}) {
					return false
				}
			}
		}
	case server.MapGroupGroups:
		for it := g.First(); it != nil; it = it.Next() {
			if !eachObjectRecursiveNS(s, s.MapGroups.GroupByInd(it.Data1()), fnc) {
				return false
			}
		}
	}
	return true
}

func eachWaypointRecursive(s *Server, g *server.MapGroup, fnc func(wp ns4.WaypointObj) bool) bool {
	if g == nil {
		return true
	}
	switch g.GroupType() {
	case server.MapGroupWaypoints:
		for it := g.First(); it != nil; it = it.Next() {
			if wp := s.WPs.ByInd(it.Data1()); wp != nil {
				if !fnc(wp) {
					return false
				}
			}
		}
	case server.MapGroupGroups:
		for it := g.First(); it != nil; it = it.Next() {
			if !eachWaypointRecursive(s, s.MapGroups.GroupByInd(it.Data1()), fnc) {
				return false
			}
		}
	}
	return true
}

func eachWallRecursive(s *Server, g *server.MapGroup, fnc func(w ns4.WallObj) bool) bool {
	if g == nil {
		return true
	}
	switch g.GroupType() {
	case server.MapGroupWalls:
		for it := g.First(); it != nil; it = it.Next() {
			if w := s.Walls.GetWallAtGrid(image.Pt(it.Data1(), it.Data2())); w != nil {
				if !fnc(asWallS(w)) {
					return false
				}
			}
		}
	case server.MapGroupGroups:
		for it := g.First(); it != nil; it = it.Next() {
			if !eachWallRecursive(s, s.MapGroups.GroupByInd(it.Data1()), fnc) {
				return false
			}
		}
	}
	return true
}

func nsCancelTimer(vm noxscript.VM) int {
	s := vm.(*noxScript)
	act := s.PopU32()
	ok := s.s.Activators.Cancel(act)
	s.PushBool(ok)
	return 0
}

func sliceEqual(a, b []uint32) bool {
	if len(a) != len(b) {
		return false
	}
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}
