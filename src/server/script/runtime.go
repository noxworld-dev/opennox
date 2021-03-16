package script

import (
	"math"
	"strings"
	"unsafe"
)

func NewRuntime() *Runtime {
	return &Runtime{}
}

type Runtime struct {
	stack   []int32
	strings []string
	scripts []Script

	builtins builtinsData

	panicsMemhack bool

	// set during the call
	caller  unsafe.Pointer
	trigger unsafe.Pointer
}

func (r *Runtime) Reset() {
	r.stack = nil
	r.strings = nil
	r.builtins.byOp = nil
	r.resetBuiltinData()
	r.panicsMemhack = false
	r.scripts = nil
	r.caller = nil
	r.trigger = nil
}

func (r *Runtime) PushInt(v int32) {
	r.stack = append(r.stack, v)
}

func (r *Runtime) PushUint(v uint32) {
	r.stack = append(r.stack, int32(v))
}

func (r *Runtime) PushFloat(v float32) {
	r.stack = append(r.stack, int32(math.Float32bits(v)))
}

func (r *Runtime) PushBool(v bool) {
	if v {
		r.PushInt(1)
	} else {
		r.PushInt(0)
	}
}

func (r *Runtime) PopUint() uint32 {
	return uint32(r.PopInt())
}

func (r *Runtime) PopInt() int32 {
	n := len(r.stack)
	if n == 0 {
		return 0
	}
	v := r.stack[n-1]
	r.stack = r.stack[:n-1]
	return v
}

func (r *Runtime) PopFloat() float32 {
	return math.Float32frombits(r.PopUint())
}

func (r *Runtime) PopBool() bool {
	return r.PopUint() != 0
}

func (r *Runtime) stackTop() int {
	return len(r.stack) - 1
}

func (r *Runtime) stackSet(i int) {
	r.stack = r.stack[:i+1]
}

func (r *Runtime) StackAt(i int) uint32 {
	if i < 0 || i >= cap(r.stack) {
		return 0
	}
	stack := r.stack
	stack = stack[:cap(stack)]
	return uint32(stack[i])
}

func (r *Runtime) AddString(s string) int {
	i := len(r.strings)
	r.strings = append(r.strings, s)
	return i
}

func (r *Runtime) GetString(i int) string {
	if i < 0 || i >= len(r.strings) {
		return ""
	}
	return r.strings[i]
}

func (r *Runtime) PushString(s string) {
	i := r.AddString(s)
	r.stack = append(r.stack, int32(i))
}

func (r *Runtime) PopString() string {
	i := r.PopUint()
	return r.GetString(int(i))
}

func (r *Runtime) Script(i int) *Script {
	if i < 0 || i >= len(r.scripts) {
		return nil
	}
	return &r.scripts[i]
}

func (r *Runtime) IndexByName(name string) int {
	for i, s := range r.scripts {
		if s.name == name {
			return i
		}
	}
	return -1
}

func (r *Runtime) GetCaller() unsafe.Pointer {
	return r.caller
}

func (r *Runtime) GetTrigger() unsafe.Pointer {
	return r.trigger
}

func (r *Runtime) CallFirst(isSwitchToSolo bool) {
	r.resetBuiltinData()
	sc := r.Script(1)
	if sc == nil {
		return
	}
	f28 := sc.field28
	f28[0] = -2
	f28[1] = -1
	f28[2] = 1
	f28[3] = 0
	if !isSwitchToSolo {
		sc.Call(nil, nil)
	}
}

func (r *Runtime) CallByName(name string, a2, a3 unsafe.Pointer) {
	for _, s := range r.scripts {
		if strings.HasPrefix(s.name, name) {
			s.Call(a2, a3)
		}
	}
}
