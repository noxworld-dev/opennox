package opennox

import (
	"errors"
	"fmt"

	"github.com/noxworld-dev/noxscript/ns/asm"

	"github.com/noxworld-dev/opennox/v1/legacy"
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

func nsCancelTimer(vm noxscript.VM) int {
	s := vm.(*noxScript)
	act := s.PopU32()
	ok := s.s.Activators.Cancel(act)
	s.PushBool(ok)
	return 0
}
