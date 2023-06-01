package ccall

import (
	"fmt"
	"runtime"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
)

type funcReg struct {
	Func  any
	Where string
}

var funcs = make(map[unsafe.Pointer]funcReg)

func FuncAddr(fnc any) unsafe.Pointer {
	if fnc == nil {
		return nil
	}
	addr := libc.FuncAddrUnsafe(fnc)
	if _, ok := funcs[addr]; ok {
		return addr
	}
	funcs[addr] = funcReg{Func: fnc, Where: caller(1)}
	return addr
}

func AsFunc[T any](h unsafe.Pointer) T {
	if h == nil {
		var zero T
		return zero
	}
	r, ok := funcs[h]
	if !ok {
		panic("not found")
	}
	fnc, ok := r.Func.(T)
	if !ok {
		panic(fmt.Errorf("unexpected func type: got %T, exp %T\nRegistered at:\n\t%s\n", r.Func, fnc, r.Where))
	}
	return fnc
}

func caller(skip int) string {
	pc, file, line, ok := runtime.Caller(skip + 1)
	if !ok {
		return "<unknown>"
	}
	fnc := "<unknown>"
	if f := runtime.FuncForPC(pc); f != nil {
		fnc = f.Name()
	}
	return fmt.Sprintf("%s, %s:%d", fnc, file, line)
}
