package noxscript

import asm "github.com/noxworld-dev/opennox-lib/script/noxscript/noxasm"

var builtins = make(map[asm.Builtin]Builtin)

type Builtin func(s VM) int

func Register(op asm.Builtin, fnc Builtin) {
	if _, ok := builtins[op]; ok {
		panic("already registered")
	}
	builtins[op] = fnc
}

func CallBuiltin(vm VM, op asm.Builtin) (int, bool) {
	fnc, ok := builtins[op]
	if !ok {
		return 0, false
	}
	return fnc(vm), true
}
