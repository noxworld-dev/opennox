package script

import "log"

// TODO: should also accept a reference to Nox engine

type BuiltinFunc func(r *Runtime) int

type builtinsData struct {
	byOp map[int]Builtin
	F36  string
	F40  int
	F44  int
}

type Builtin struct {
	Fnc          BuiltinFunc
	NeedsF36     bool
	NeedsF4044   bool
	ReadMore     bool
	ReadEvenMore bool
}

func (r *Runtime) RegisterBuiltin(code int, b *Builtin) {
	if r.builtins.byOp == nil {
		r.builtins.byOp = make(map[int]Builtin)
	}
	if b == nil {
		delete(r.builtins.byOp, code)
	} else {
		if b.Fnc == nil {
			panic("function must be set")
		}
		r.builtins.byOp[code] = *b
	}
}

func (r *Runtime) resetBuiltinData() {
	r.builtins.F36 = ""
	r.builtins.F40 = 0
	r.builtins.F44 = 0
}

func (r *Runtime) BuiltinF36() string {
	return r.builtins.F36
}

func (r *Runtime) BuiltinF40() int {
	return r.builtins.F40
}

func (r *Runtime) BuiltinF44() int {
	return r.builtins.F44
}

func (sc *Script) CallBuiltin(code int) (int, bool) {
	r := sc.r
	b, ok := r.builtins.byOp[code]
	if !ok {
		if r.checkPanicMemhack(code) {
			return 0, true
		}
		log.Printf("noxscript: invalid builtin index: %d (%x)", code, code)
		return 0, false
	}
	if sc.f36 == "" {
		return b.Fnc(r), true
	}
	if b.NeedsF36 {
		r.builtins.F36 = sc.f36
	}
	if b.NeedsF4044 {
		r.builtins.F40 = sc.f40
		r.builtins.F44 = sc.f44
	}
	res := b.Fnc(r)
	r.resetBuiltinData()
	return res, true
}
