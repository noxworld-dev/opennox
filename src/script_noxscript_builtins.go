package opennox

import (
	"errors"
	"fmt"
	"image"

	"github.com/noxworld-dev/noxscript/ns/asm"
	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/object"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
	"github.com/noxworld-dev/opennox/v1/server/noxscript"
)

func (s *noxScript) callBuiltin(i int, fi asm.Builtin) error {
	if fi < 0 || fi > asm.BuiltinGetScore {
		if s.panicCompilerCheck(fi) {
			return nil
		}
	}
	if s.builtinNeedsField36(fi) {
		s.nameSuff = s.scriptNameSuff(i)
	}
	if s.builtinNeedsFields4044(fi) {
		s.dpos.X = s.scriptField40(i)
		s.dpos.Y = s.scriptField44(i)
	}
	err := s.callBuiltinNative(fi)
	s.resetBuiltin()
	return err
}

func nox_script_shouldReadMoreXxx(fi int) bool {
	return fi == 9 || fi == 10 ||
		fi == 46 || fi == 47 ||
		fi == 190 || fi == 126
}

func nox_script_shouldReadEvenMoreXxx(fi int) bool {
	return fi == 126
}

var errStopScript = errors.New("noxscript: exit")

func (s *noxScript) callBuiltinNative(fi asm.Builtin) error {
	res, ok := noxscript.CallBuiltin(s, fi)
	if !ok {
		res, ok = s.panicScriptCall(fi)
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

func (s *noxScript) builtinNeedsFields4044(fi asm.Builtin) bool {
	// TODO: 7 items in the array, but the count is set to 5; why?
	var check = []asm.Builtin{
		0,
		67, 68,
		72,
		97, 98,
		100,
	}
	for _, ind := range check[:5] {
		if fi == ind {
			return true
		}
	}
	return false
}

func (s *noxScript) builtinNeedsField36(fi asm.Builtin) bool {
	switch fi {
	case 60, 110, 111, 112, 113:
		return true
	}
	return false
}

var noxScriptBuiltins = [asm.BuiltinGetScore + 1]noxscript.Builtin{
	asm.BuiltinSecondTimer:        nsSecondTimer,
	asm.BuiltinFrameTimer:         nsFrameTimer,
	asm.BuiltinSecondTimerWithArg: nsSecondTimerArg,
	asm.BuiltinFrameTimerWithArg:  nsFrameTimerArg,
	asm.BuiltinCancelTimer:        nsCancelTimer,
	asm.BuiltinGetTrigger:         nsGetTrigger,
	asm.BuiltinGetCaller:          nsGetCaller,
	asm.BuiltinSetCallback:        nsSetCallback,
}

func nsGetTrigger(vm noxscript.VM) int {
	vm.PushHandleNS(vm.NoxScript().GetTrigger())
	return 0
}

func nsGetCaller(vm noxscript.VM) int {
	vm.PushHandleNS(vm.NoxScript().GetCaller())
	return 0
}

func nsSecondTimer(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int(s.PopU32())
	dt := s.PopU32()
	s.PushU32(s.s.NewTimer(int(dt*s.s.TickRate()), fnc, 0))
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
	s.PushU32(s.s.NewTimer(int(dt*s.s.TickRate()), fnc, arg))
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

func eachObjectNS(s *Server, g *server.MapGroup, fnc func(obj ns.Obj) bool) {
	if g == nil {
		return
	}
	switch g.GroupType() {
	case server.MapGroupObjects:
		for it := g.First(); it != nil; it = it.Next() {
			if obj := s.GetObjectByInd(it.Data1()); obj != nil {
				if !fnc(nsObj{s, obj}) {
					return
				}
			}
		}
	}
}

func eachObjectRecursiveNS(s *Server, g *server.MapGroup, fnc func(obj ns.Obj) bool) bool {
	if g == nil {
		return true // just skip this group
	}
	switch g.GroupType() {
	case server.MapGroupObjects:
		for it := g.First(); it != nil; it = it.Next() {
			if obj := s.GetObjectByInd(it.Data1()); obj != nil {
				if !fnc(nsObj{s, obj}) {
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

func eachWaypointRecursive(s *Server, g *server.MapGroup, fnc func(wp ns.WaypointObj) bool) bool {
	if g == nil {
		return true
	}
	switch g.GroupType() {
	case server.MapGroupWaypoints:
		for it := g.First(); it != nil; it = it.Next() {
			if wp := s.getWaypointByInd(it.Data1()); wp != nil {
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

func eachWallRecursive(s *Server, g *server.MapGroup, fnc func(w ns.WallObj) bool) bool {
	if g == nil {
		return true
	}
	switch g.GroupType() {
	case server.MapGroupWalls:
		for it := g.First(); it != nil; it = it.Next() {
			if w := s.getWallAtGrid(image.Pt(it.Data1(), it.Data2())); w != nil {
				if !fnc(w) {
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

func nsSetCallback(vm noxscript.VM) int {
	s := vm.(*noxScript)
	fnc := int32(s.PopU32())
	ev := ns.ObjectEvent(s.PopU32())
	u := asObjectS(s.PopObject())
	if u == nil || !u.Class().Has(object.ClassMonster) {
		return 0
	}
	ud := u.UpdateDataMonster()
	switch ev {
	case ns.EventEnemySighted: // Enemy sighted
		ud.ScriptEnemySighted.Func = fnc
	case ns.EventLookingForEnemy: // Looking for enemy
		ud.ScriptLookingForEnemy.Func = fnc
	case ns.EventDeath: // Death
		ud.ScriptDeath.Func = fnc
	case ns.EventChangeFocus: // Change focus
		ud.ScriptChangeFocus.Func = fnc
	case ns.EventIsHit: // Is hit
		ud.ScriptIsHit.Func = fnc
	case ns.EventRetreat: // Retreat
		ud.ScriptRetreat.Func = fnc
	case ns.EventCollision: // Collision
		ud.ScriptCollision.Func = fnc
	case ns.EventEnemyHeard: // Enemy heard
		ud.ScriptHearEnemy.Func = fnc
	case ns.EventEndOfWaypoint: // End of waypoint
		ud.ScriptEndOfWaypoint.Func = fnc
	case ns.EventLostEnemy: // Lost sight of enemy
		ud.ScriptLostEnemy.Func = fnc
	}
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
