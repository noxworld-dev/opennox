package noxscript

import (
	"io"
	"math"
	"strings"
)

type ObjID int

const (
	CallerID  = ObjID(-1)
	TriggerID = ObjID(-2)
)

type Object interface {
	NoxScriptID() ObjID
	GetNoxScriptVal(ind int) int32
	SetNoxScriptVal(ind int, val int32)
}

func NewRuntime() *Runtime {
	return new(Runtime)
}

func LoadScript(rd io.Reader) (*Runtime, error) {
	r := NewRuntime()
	if err := r.ReadScript(rd); err != nil {
		return nil, err
	}
	return r, nil
}

type Runtime struct {
	stack   []int32
	strings []string
	funcs   []*Func

	builtins builtinsData

	panicsCompiler bool

	// set during the call
	caller  Object
	trigger Object
}

func (r *Runtime) Reset() {
	r.stack = nil
	r.strings = nil
	r.builtins.byOp = nil
	r.resetBuiltinData()
	r.panicsCompiler = false
	r.funcs = nil
	r.caller = nil
	r.trigger = nil
}

func (r *Runtime) ReadScript(rd io.Reader) error {
	sc, err := ReadScript(rd)
	if err != nil {
		return err
	}
	return r.LoadScript(sc)
}

func (r *Runtime) LoadScript(sc *Script) error {
	r.Reset()
	r.strings = sc.Strings
	r.funcs = make([]*Func, 0, len(sc.Funcs))
	for i := range sc.Funcs {
		def := &sc.Funcs[i]
		f := r.newFunc(def)
		r.funcs = append(r.funcs, f)
	}
	return nil
}

func (r *Runtime) PushInt32(v int32) {
	r.stack = append(r.stack, v)
}

func (r *Runtime) PushInt(v int) {
	r.PushInt32(int32(v))
}

func (r *Runtime) PushUint32(v uint32) {
	r.stack = append(r.stack, int32(v))
}

func (r *Runtime) PushFloat32(v float32) {
	r.stack = append(r.stack, int32(math.Float32bits(v)))
}

func (r *Runtime) PushBool(v bool) {
	if v {
		r.PushInt32(1)
	} else {
		r.PushInt32(0)
	}
}

func (r *Runtime) PushObjectID(v ObjID) {
	r.PushInt32(int32(v))
}

func (r *Runtime) PushObject(v Object) {
	var id ObjID
	if v != nil {
		id = v.NoxScriptID()
	}
	r.PushInt32(int32(id))
}

func (r *Runtime) PopUint32() uint32 {
	return uint32(r.PopInt32())
}

func (r *Runtime) PopInt32() int32 {
	n := len(r.stack)
	if n == 0 {
		return 0
	}
	v := r.stack[n-1]
	r.stack = r.stack[:n-1]
	return v
}

func (r *Runtime) PopInt() int {
	return int(r.PopInt32())
}

func (r *Runtime) PopFloat32() float32 {
	return math.Float32frombits(r.PopUint32())
}

func (r *Runtime) PopBool() bool {
	return r.PopUint32() != 0
}

func (r *Runtime) PopObjectID() ObjID {
	return ObjID(r.PopUint32())
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
	i := r.PopUint32()
	return r.GetString(int(i))
}

func (r *Runtime) FuncByInd(i int) *Func {
	if i < 0 || i >= len(r.funcs) {
		return nil
	}
	return r.funcs[i]
}

func (r *Runtime) FuncByName(name string) *Func {
	for _, f := range r.funcs {
		if f.def.Name == name {
			return f
		}
	}
	return nil
}

func (r *Runtime) FuncByPref(pref string) []*Func {
	var out []*Func
	for _, f := range r.funcs {
		if strings.HasPrefix(f.def.Name, pref) {
			out = append(out, f)
		}
	}
	return out
}

func (r *Runtime) IndexByName(name string) int {
	for i, f := range r.funcs {
		if f.def.Name == name {
			return i
		}
	}
	return -1
}

func (r *Runtime) GetCaller() Object {
	return r.caller
}

func (r *Runtime) GetTrigger() Object {
	return r.trigger
}

func (r *Runtime) CallFirst(isSwitchToSolo bool) error {
	r.resetBuiltinData()
	sc := r.FuncByInd(1)
	if sc == nil {
		return nil
	}
	// TODO: check, var index might be wrong; also, is it okay to override it this way?
	copy(sc.vars[0][:4], []int32{
		int32(TriggerID), // self
		int32(CallerID),  // other
		1,                // true
		0,                // false
	})
	if isSwitchToSolo {
		return nil
	}
	return sc.Call(nil, nil)
}

func (r *Runtime) CallByName(name string, caller, trigger Object, args ...interface{}) error {
	if f := r.FuncByName(name); f != nil {
		return f.Call(caller, trigger, args...)
	}
	return &ErrNoFunc{Func: name}
}

func (r *Runtime) CallByPrefix(pref string, caller, trigger Object, args ...interface{}) error {
	list := r.FuncByPref(pref)
	if len(list) == 0 {
		return &ErrNoFunc{Func: pref}
	}
	for _, f := range list {
		if err := f.Call(caller, trigger, args...); err != nil {
			return err
		}
	}
	return nil
}
