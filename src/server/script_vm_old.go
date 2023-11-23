package server

import (
	"errors"
	"fmt"
	"image"
	"io"
	"math"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/noxscript/ns/asm"
	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type ScriptFunc struct {
	asm.FuncDef
	Values []uint32
}

func (s *ScriptFunc) Name() string {
	return s.FuncDef.Name
}

func (s *ScriptFunc) Args() []uint32 {
	sz := s.FuncDef.Args
	if sz == 0 {
		return nil
	}
	return s.Values[:sz]
}

func (s *ScriptFunc) Locals() []uint32 {
	sz := s.FuncDef.Args
	if sz >= len(s.Values) {
		return nil
	}
	return s.Values[sz:]
}

func (s *ScriptFunc) AllLocals() []uint32 {
	return s.Values
}

type nsCallback struct {
	Name string
	Fnc  func() error
}

type noxScriptCallback struct {
	Block   *ScriptCallback
	Caller  *Object
	Trigger *Object
}

type NoxScriptVM struct {
	s  *Server
	vm struct {
		strings   []string
		funcs     []ScriptFunc
		stack     []uint32
		dpos      image.Point // pos delta added when calling builtins
		nameSuff  string      // name suffix added when calling builtins
		caller    *Object
		trigger   *Object
		callbacks []noxScriptCallback
	}
	timers  script.Timers
	virtual struct {
		last  int
		funcs map[int]nsCallback
	}
	panic noxScriptPanic

	CallBuiltinNative func(fi asm.Builtin) error
}

func (s *NoxScriptVM) Init(srv *Server) {
	s.s = srv
	s.resetVirtualFuncs()
}

func (s *NoxScriptVM) Reset() {
	for i := range s.vm.strings {
		s.vm.strings[i] = ""
	}
	s.vm.strings = s.vm.strings[:0]
	s.vm.funcs = nil
}

func (s *NoxScriptVM) resetVirtualFuncs() {
	s.virtual.last = math.MaxInt32
	s.virtual.funcs = make(map[int]nsCallback)
}

func (s *NoxScriptVM) FuncsCnt() int {
	return len(s.vm.funcs)
}

func (s *NoxScriptVM) Funcs() []ScriptFunc {
	return s.vm.funcs
}

func (s *NoxScriptVM) FuncByPref(name string) (*ScriptFunc, int) {
	scripts := s.Funcs()
	for i := range scripts {
		sc := &scripts[i]
		if strings.HasPrefix(sc.Name(), name) {
			return sc, i
		}
	}
	return nil, -1
}

func (s *NoxScriptVM) FuncByName(name string) (*ScriptFunc, int) {
	scripts := s.Funcs()
	for i := range scripts {
		sc := &scripts[i]
		if sc.Name() == name {
			return sc, i
		}
	}
	return nil, -1
}

func (s *NoxScriptVM) ResetBuiltin() {
	s.vm.dpos = image.Point{}
	s.vm.nameSuff = ""
}

func (s *NoxScriptVM) NameSuff() string {
	return s.vm.nameSuff
}

func (s *NoxScriptVM) DPos() image.Point {
	return s.vm.dpos
}

func (s *NoxScriptVM) DPosf() types.Pointf {
	return types.Point2f(s.vm.dpos)
}

func (s *NoxScriptVM) AsValue(val any) uint32 {
	switch val := val.(type) {
	case nil:
		return 0
	case bool:
		if val {
			return 1
		}
		return 0
	case int:
		return uint32(int32(val))
	case int32:
		return uint32(val)
	case uint32:
		return val
	case float32:
		return math.Float32bits(val)
	case ns4.Handle:
		return uint32(val.ScriptID())
	}
	panic(fmt.Errorf("unsupported type: %T", val))
}

func (s *NoxScriptVM) AsFuncIndex(defname string, fnc ns4.Func) int {
	switch fnc := fnc.(type) {
	case nil:
		return -1
	case int:
		if fnc < 0 || fnc >= s.FuncsCnt() {
			return -1
		}
		return fnc
	case string:
		return s.ScriptIndexByName(fnc)
	case func():
		return s.addVirtual(defname, func() (gerr error) {
			defer func() {
				if r := recover(); r != nil {
					if e, ok := r.(error); ok {
						gerr = e
					} else {
						gerr = fmt.Errorf("panic in %s: %v", defname, r)
					}
				}
			}()
			fnc()
			return nil
		})
	default:
		panic(fmt.Errorf("unsupported function type: %T", fnc))
	}
}

// addVirtual assigns a virtual function index for NoxScript.
func (s *NoxScriptVM) addVirtual(name string, fnc func() error) int {
	// Are we conflicting with the original NoxScript func indexes?
	if s.virtual.last-1 <= s.FuncsCnt() {
		panic("no more space for virtual script func handles")
	}
	id := s.virtual.last
	s.virtual.last--
	s.virtual.funcs[id] = nsCallback{Name: name, Fnc: fnc}
	return id
}

// ScriptIndexByName looks up NoxScript function ID (handle).
// It returns -1 if the function was not found.
//
// Originally only compiled NoxScript from the map was considered,
// in which case returned handle is just an index into the functions slice.
//
// Since new runtimes were introduced, this function will now return "virtual"
// function indexes, which are set really large to avoid collisions, for functions
// from the new runtimes. CallByIndex and ScriptCallback will recognize them later.
func (s *NoxScriptVM) ScriptIndexByName(name string) int {
	// Prefer map scripts from new script runtimes.
	for _, vm := range s.s.VMs.VMs {
		fnc, err := script.GetVMSymbol[func()](vm, name)
		if err != nil {
			// Pretend we found it, but return an error on all calls instead.
			return s.addVirtual(name, func() error {
				return err
			})
		}
		if fnc != nil {
			// Found, returning virtual handle.
			return s.addVirtual(name, func() error {
				fnc()
				return nil
			})
		}
	}
	for i, f := range s.vm.funcs {
		if f.Name() == name {
			return i
		}
	}
	return -1
}

func (s *NoxScriptVM) ScriptNameByIndex(h int) string {
	if cb, ok := s.virtual.funcs[h]; ok {
		return cb.Name
	}
	return s.Funcs()[h].Name()
}

func (s *NoxScriptVM) Caller() *Object {
	return s.vm.caller
}

func (s *NoxScriptVM) Trigger() *Object {
	return s.vm.trigger
}

func (s *NoxScriptVM) resetStack() {
	s.vm.stack = s.vm.stack[:0]
}

func (s *NoxScriptVM) saveStack() int {
	return len(s.vm.stack)
}

func (s *NoxScriptVM) adjustStack(prev, sz int) {
	if n := len(s.vm.stack); n != prev+sz {
		if sz != 0 {
			if n != 0 {
				v := s.PopU32()
				s.vm.stack = s.vm.stack[:prev]
				s.PushU32(v)
			} else {
				s.vm.stack = s.vm.stack[:prev]
				s.PushU32(0)
			}
		} else {
			s.vm.stack = s.vm.stack[:prev]
		}
	}
}

func (s *NoxScriptVM) stackAt(i int) uint32 {
	if i < 0 || i >= len(s.vm.stack) {
		return 0
	}
	return s.vm.stack[i]
}

func (s *NoxScriptVM) PushU32(v uint32) {
	s.vm.stack = append(s.vm.stack, v)
}

func (s *NoxScriptVM) PushI32(v int32) {
	s.vm.stack = append(s.vm.stack, uint32(v))
}

func (s *NoxScriptVM) PushF32(v float32) {
	s.vm.stack = append(s.vm.stack, math.Float32bits(v))
}

func (s *NoxScriptVM) PushBool(v bool) {
	if v {
		s.vm.stack = append(s.vm.stack, 1)
	} else {
		s.vm.stack = append(s.vm.stack, 0)
	}
}

func (s *NoxScriptVM) NewString(str string) uint32 {
	i := len(s.vm.strings)
	s.vm.strings = append(s.vm.strings, str)
	return uint32(i)
}

func (s *NoxScriptVM) PushString(str string) {
	s.vm.stack = append(s.vm.stack, s.NewString(str))
}

func (s *NoxScriptVM) PopI32() int32 {
	n := len(s.vm.stack)
	if n == 0 {
		return 0
	}
	v := s.vm.stack[n-1]
	s.vm.stack = s.vm.stack[:n-1]
	return int32(v)
}

func (s *NoxScriptVM) PopU32() uint32 {
	n := len(s.vm.stack)
	if n == 0 {
		return 0
	}
	v := s.vm.stack[n-1]
	s.vm.stack = s.vm.stack[:n-1]
	return v
}

func (s *NoxScriptVM) PopF32() float32 {
	return math.Float32frombits(s.PopU32())
}

func (s *NoxScriptVM) PopBool() bool {
	return s.PopU32() != 0
}

func (s *NoxScriptVM) LookupString(i uint32) (string, bool) {
	if i < 0 || i >= uint32(len(s.vm.strings)) {
		return "", false
	}
	return s.vm.strings[i], true
}

func (s *NoxScriptVM) GetString(i uint32) string {
	v, _ := s.LookupString(i)
	return v
}

func (s *NoxScriptVM) PopString() string {
	return s.GetString(s.PopU32())
}

func (s *NoxScriptVM) PopPoint() image.Point {
	y := s.PopI32()
	x := s.PopI32()
	return image.Point{X: int(x), Y: int(y)}
}

func (s *NoxScriptVM) PopPointf() types.Pointf {
	y := s.PopF32()
	x := s.PopF32()
	return types.Pointf{X: x, Y: y}
}

func (s *NoxScriptVM) PushHandleNS(obj ns4.Handle) {
	if obj == nil {
		s.PushI32(0)
	} else {
		s.PushI32(int32(obj.ScriptID()))
	}
}

func (s *NoxScriptVM) PopWaypointNS() ns4.WaypointObj {
	wp := s.s.WPs.ByInd(int(s.PopI32()))
	if wp == nil {
		return nil
	}
	return wp
}

func (s *NoxScriptVM) PopGroup() *MapGroup {
	return s.s.MapGroups.GroupByInd(int(s.PopI32()))
}

func (s *NoxScriptVM) PopWpGroupNS() ns4.WaypointGroupObj {
	g := s.PopGroup()
	if g == nil || s.s.MapGroups.MapGroupType(g) != MapGroupWaypoints {
		return nil
	}
	return nsWpGroup{s.s, g}
}

func (s *NoxScriptVM) scriptPushCallback(b *ScriptCallback, caller, trigger *Object) {
	s.vm.callbacks = append(s.vm.callbacks, noxScriptCallback{
		Block: b, Caller: caller, Trigger: trigger,
	})
}

func (s *NoxScriptVM) scriptPopCallback(b *ScriptCallback, caller, trigger *Object) {
	for i := 0; i < len(s.vm.callbacks); i++ {
		it := &s.vm.callbacks[i]
		if it.Block == b && it.Caller == caller && it.Trigger == trigger {
			s.vm.callbacks = append(s.vm.callbacks[:i], s.vm.callbacks[i+1:]...)
		}
	}
}

func (s *NoxScriptVM) OnEvent(event script.EventType) {
	scripts := s.Funcs()
	for i := range scripts {
		sc := &scripts[i]
		name := sc.Name()
		if strings.HasPrefix(name, string(event)) {
			if err := s.CallByIndex(i, nil, nil); err != nil {
				ScriptLog.Println(err)
			}
		}
	}
}

func (s *NoxScriptVM) RunFirst(isSwitchToSolo bool) {
	s.ResetBuiltin()
	if scripts := s.Funcs(); len(scripts) >= 2 {
		sc := scripts[1].Values
		tv := int32(-2)
		sc[0] = uint32(tv)
		tv = int32(-1)
		sc[1] = uint32(tv)
		sc[2] = 1
		sc[3] = 0
		if !isSwitchToSolo {
			if err := s.CallByIndex(1, nil, nil); err != nil {
				ScriptLog.Println(err)
			}
		}
	} else {
		ScriptLog.Printf("noxscript: no init function")
	}
}

func (s *NoxScriptVM) getFuncVarPtr(fi int, vari int) *uint32 {
	if fi < 0 || vari < 0 {
		return nil
	}
	scripts := s.Funcs()
	if fi >= len(scripts) {
		return nil
	}
	sc := &scripts[fi]
	return s.getFuncVarPtrFor(sc, vari)
}

func (s *NoxScriptVM) getFuncVarPtrFor(sc *ScriptFunc, vari int) *uint32 {
	if sc == nil {
		return nil
	}
	if vari < 0 || vari >= len(sc.Vars) {
		return nil
	}
	off := sc.Vars[vari].Offs
	if off < 0 || off >= len(sc.Values) {
		return nil
	}
	return &sc.Values[off]
}

func (s *NoxScriptVM) GetGlobal(gvar int) (uint32, bool) {
	return s.GetFuncVar(1, gvar)
}

func (s *NoxScriptVM) SetGlobal(gvar int, val uint32) bool {
	return s.SetFuncVar(1, gvar, val)
}

func (s *NoxScriptVM) GetFuncVar(fnc int, vari int) (uint32, bool) {
	ptr := s.getFuncVarPtr(fnc, vari)
	if ptr == nil {
		return 0, false
	}
	return *ptr, true
}

func (s *NoxScriptVM) SetFuncVar(fnc int, vari int, val uint32) bool {
	ptr := s.getFuncVarPtr(fnc, vari)
	if ptr == nil {
		return false
	}
	*ptr = val
	return true
}

func (s *NoxScriptVM) CallFunc(fnc string, args []uint32) (uint32, error) {
	sc, _ := s.FuncByName(fnc)
	if sc == nil {
		return 0, fmt.Errorf("function %q not found", fnc)
	}
	return s.callFuncPtr(sc, args)
}

func (s *NoxScriptVM) CallFuncInd(fnc int, args []uint32) (uint32, error) {
	if fnc < 0 {
		return 0, errors.New("function not found")
	}
	scripts := s.Funcs()
	if fnc >= len(scripts) {
		return 0, errors.New("function not found")
	}
	sc := &scripts[fnc]
	if sc == nil {
		return 0, fmt.Errorf("function %q not found", fnc)
	}
	return s.callFuncPtr(sc, args)
}

func (s *NoxScriptVM) callFuncPtr(sc *ScriptFunc, args []uint32) (uint32, error) {
	if sc == nil {
		return 0, errors.New("function not found")
	}
	argsN := len(sc.Args())
	if len(args) != argsN {
		return 0, fmt.Errorf("function %q expects %d arguments, but got %d", sc.Name(), argsN, len(args))
	}
	err := s.callByFunc(sc, nil, nil, args)
	return 0, err // TODO: read return value
}

func (s *NoxScriptVM) CallByIndex(index int, caller, trigger *Object) (gerr error) {
	defer func() {
		if r := recover(); r != nil {
			if e, ok := r.(error); ok {
				gerr = e
			} else {
				gerr = fmt.Errorf("panic: %v", r)
			}
			ScriptLog.Println("ERROR:", gerr)
		}
	}()
	if cb, ok := s.virtual.funcs[index]; ok && cb.Fnc != nil {
		s.vm.caller = caller
		s.vm.trigger = trigger
		return cb.Fnc()
	}
	if len(s.vm.funcs) == 0 {
		return errors.New("no map script functions")
	}
	scripts := s.Funcs()
	if index < 0 || index >= len(scripts) {
		return fmt.Errorf("invalid function index: %d (%x)", index, index)
	}
	sc := &scripts[index]

	s.vm.caller = caller
	s.vm.trigger = trigger

	args := make([]uint32, len(sc.Args()))
	for i := range args {
		args[i] = s.PopU32()
	}
	return s.callByFunc(sc, caller, trigger, args)
}

func (s *NoxScriptVM) callByFunc(sc *ScriptFunc, caller, trigger *Object, args []uint32) (gerr error) {
	defer func() {
		if r := recover(); r != nil {
			if e, ok := r.(error); ok {
				gerr = e
			} else {
				gerr = fmt.Errorf("panic: %v", r)
			}
			ScriptLog.Println("ERROR:", gerr)
		}
	}()

	s.vm.caller = caller
	s.vm.trigger = trigger

	scripts := s.Funcs()

	argsArr := sc.Args()
	for i := range argsArr {
		argsArr[i] = args[i]
	}
	bstack := s.saveStack()
	code := sc.Code
	readUint := func() uint32 {
		v := code[0]
		code = code[1:]
		return v
	}
	readInt := func() int32 {
		return int32(readUint())
	}
	readFloat := func() float32 {
		return math.Float32frombits(readUint())
	}
	// TODO: varOffPtr and varPtr are very similar; maybe they are the same, and it's a bug?
	varOffPtr := func(isGlobal bool, vari int32) *uint32 {
		if isGlobal {
			if len(scripts[1].Vars) != 0 && len(scripts[1].Values) != 0 {
				off := scripts[1].Vars[vari].Offs
				return &scripts[1].Values[off]
			}
		} else if vari < 0 {
			off := scripts[1].Vars[-vari].Offs
			return trigger.ScriptVarPtr(off)
		} else if len(sc.Vars) != 0 && len(sc.Values) != 0 {
			off := sc.Vars[vari].Offs
			return &sc.Values[off]
		}
		return nil
	}
	varPtr := func(isGlobal bool, vari int32) *uint32 {
		if isGlobal {
			if len(scripts[1].Values) != 0 {
				return &scripts[1].Values[vari]
			}
		} else if vari < 0 {
			return trigger.ScriptVarPtr(int(-vari))
		} else if len(sc.Values) != 0 {
			return &sc.Values[vari]
		}
		return nil
	}
	varIndPtr := func(isGlobal bool, vari int32, i int32) *uint32 {
		if isGlobal {
			if len(scripts[1].Values) != 0 {
				return &scripts[1].Values[vari+i]
			}
		} else if vari < 0 {
			return trigger.ScriptVarPtr(int(vari - i))
		} else if len(sc.Values) != 0 {
			return &sc.Values[vari+i]
		}
		return nil
	}
	for {
		op := asm.Op(readUint())
		switch op {
		case asm.OpLoadVarInt, asm.OpLoadVarString:
			isGlobal := readInt() != 0
			vari := readInt()
			ptr := varOffPtr(isGlobal, vari)
			if ptr != nil {
				s.PushI32(int32(*ptr))
			} else {
				s.PushI32(0)
			}
			continue
		case asm.OpLoadVarFloat:
			isGlobal := readInt() != 0
			vari := readInt()
			ptr := varOffPtr(isGlobal, vari)
			if ptr != nil {
				s.PushF32(math.Float32frombits(*ptr))
			} else {
				s.PushF32(0)
			}
			continue
		case asm.OpLoadVarPtr:
			isGlobal := readInt() != 0
			vari := readInt()
			var sz, off int32
			if isGlobal {
				def := &scripts[1].Vars[vari]
				sz = int32(def.Size)
				off = int32(def.Offs)
			} else if vari < 0 {
				def := &scripts[1].Vars[-vari]
				sz = int32(def.Size)
				off = int32(-def.Offs) // TODO: this doesn't look right
			} else if len(sc.Vars) != 0 {
				def := &sc.Vars[vari]
				sz = int32(def.Size)
				off = int32(def.Offs)
			} else {
				sz = 0
				off = 0
			}
			if sz > 1 {
				s.PushI32(sz)
			}
			s.PushBool(isGlobal)
			s.PushI32(off)
			continue
		case asm.OpPushInt, asm.OpPushString:
			v := readInt()
			s.PushI32(v)
			continue
		case asm.OpPushFloat:
			v := readFloat()
			s.PushF32(v)
			continue
		case asm.OpIntAdd:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs + rhs)
			continue
		case asm.OpFloatAdd:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushF32(lhs + rhs)
			continue
		case asm.OpIntSub:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs - rhs)
			continue
		case asm.OpFloatSub:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushF32(lhs - rhs)
			continue
		case asm.OpIntMul:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs * rhs)
			continue
		case asm.OpFloatMul:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushF32(lhs * rhs)
			continue
		case asm.OpIntDiv:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs / rhs)
			continue
		case asm.OpFloatDiv:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushF32(lhs / rhs)
			continue
		case asm.OpIntMod:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs % rhs)
			continue
		case asm.OpIntAnd:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs & rhs)
			continue
		case asm.OpIntOr:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs | rhs)
			continue
		case asm.OpIntXOr:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs ^ rhs)
			continue
		case asm.OpJump:
			jmpi := readInt()
			code = sc.Code[jmpi:]
			continue
		case asm.OpJumpIf:
			jmpi := readInt()
			if s.PopBool() {
				code = sc.Code[jmpi:]
			}
			continue
		case asm.OpJumpIfNot:
			jmpi := readInt()
			if !s.PopBool() {
				code = sc.Code[jmpi:]
			}
			continue
		case asm.OpStoreInt, asm.OpStoreString:
			rhs := s.PopI32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			ptr := varPtr(isGlobal, vari)
			if ptr != nil {
				*ptr = uint32(rhs)
			}
			s.PushI32(rhs)
			continue
		case asm.OpStoreFloat:
			val := s.PopF32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			ptr := varPtr(isGlobal, vari)
			if ptr != nil {
				*ptr = math.Float32bits(val)
			}
			s.PushF32(val)
			continue
		case asm.OpStoreIntMul, asm.OpStoreIntDiv, asm.OpStoreIntAdd, asm.OpStoreIntSub, asm.OpStoreIntMod,
			asm.OpStoreIntLSh, asm.OpStoreIntRSh, asm.OpStoreIntAnd, asm.OpStoreIntOr, asm.OpStoreIntXOr:
			rhs := s.PopI32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			ptr := varPtr(isGlobal, vari)
			if ptr != nil {
				lhs := int32(*ptr)
				switch op {
				case asm.OpStoreIntMul:
					lhs *= rhs
				case asm.OpStoreIntDiv:
					lhs /= rhs
				case asm.OpStoreIntAdd:
					lhs += rhs
				case asm.OpStoreIntSub:
					lhs -= rhs
				case asm.OpStoreIntMod:
					lhs %= rhs
				case asm.OpStoreIntLSh:
					lhs <<= rhs
				case asm.OpStoreIntRSh:
					lhs >>= rhs
				case asm.OpStoreIntAnd:
					lhs &= rhs
				case asm.OpStoreIntOr:
					lhs |= rhs
				case asm.OpStoreIntXOr:
					lhs ^= rhs
				}
				*ptr = uint32(lhs)
				s.PushI32(lhs)
			} else {
				s.PushI32(0)
			}
			continue
		case asm.OpStoreFloatMul, asm.OpStoreFloatDiv, asm.OpStoreFloatAdd, asm.OpStoreFloatSub:
			rhs := s.PopF32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			ptr := varPtr(isGlobal, vari)
			if ptr != nil {
				lhs := math.Float32frombits(*ptr)
				switch op {
				case asm.OpStoreFloatMul:
					lhs *= rhs
				case asm.OpStoreFloatDiv:
					lhs /= rhs
				case asm.OpStoreFloatAdd:
					lhs += rhs
				case asm.OpStoreFloatSub:
					lhs -= rhs
				}
				*ptr = math.Float32bits(lhs)
				s.PushF32(lhs)
			} else {
				s.PushF32(0)
			}
			continue
		case asm.OpStoreStringAdd:
			dval := s.PopString()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			ptr := varPtr(isGlobal, vari)
			if ptr != nil {
				val := s.GetString(*ptr)
				val += dval
				*ptr = s.NewString(val)
				s.PushU32(*ptr)
			} else {
				s.PushU32(0)
			}
			continue
		case asm.OpIntEq:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs == rhs)
			continue
		case asm.OpFloatEq:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs == rhs)
			continue
		case asm.OpStringEq:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs == rhs)
			continue
		case asm.OpIntLSh:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs << rhs)
			continue
		case asm.OpIntRSh:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs >> rhs)
			continue
		case asm.OpIntLt:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs < rhs)
			continue
		case asm.OpFloatLt:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs < rhs)
			continue
		case asm.OpStringLt:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs < rhs)
			continue
		case asm.OpIntGt:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs > rhs)
			continue
		case asm.OpFloatGt:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs > rhs)
			continue
		case asm.OpStringGt:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs > rhs)
			continue
		case asm.OpIntLte:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs <= rhs)
			continue
		case asm.OpFloatLte:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs <= rhs)
			continue
		case asm.OpStringLte:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs <= rhs)
			continue
		case asm.OpIntGte:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs >= rhs)
			continue
		case asm.OpFloatGte:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs >= rhs)
			continue
		case asm.OpStringGte:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs >= rhs)
			continue
		case asm.OpIntNeq:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs != rhs)
			continue
		case asm.OpFloatNeq:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs != rhs)
			continue
		case asm.OpStringNeq:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs != rhs)
			continue
		case asm.OpBoolAnd:
			rhs := s.PopBool()
			lhs := s.PopBool()
			s.PushBool(lhs && rhs)
			continue
		case asm.OpBoolOr:
			rhs := s.PopBool()
			lhs := s.PopBool()
			s.PushBool(lhs || rhs)
			continue
		case asm.OpBoolNot:
			x := s.PopBool()
			s.PushBool(!x)
			continue
		case asm.OpIntNot:
			x := s.PopI32()
			s.PushI32(^x)
			continue
		case asm.OpIntNeg:
			x := s.PopI32()
			s.PushI32(-x)
			continue
		case asm.OpFloatNeg:
			x := -s.PopF32()
			s.PushF32(x)
			continue
		case asm.OpIndexInt:
			i := s.PopI32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			sz := s.PopI32()
			failed := i < 0 || i >= sz
			ptr := varIndPtr(isGlobal, vari, i)
			var val int32
			if ptr != nil {
				val = int32(*ptr)
			}
			s.PushI32(val)
			if failed {
				return fmt.Errorf("noxscript: index out of bounds: [%d:%d]", i, sz)
			}
			continue
		case asm.OpIndexFloat:
			i := s.PopI32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			sz := s.PopI32()
			failed := i < 0 || i >= sz
			ptr := varIndPtr(isGlobal, vari, i)
			var val float32
			if ptr != nil {
				val = math.Float32frombits(*ptr)
			}
			s.PushF32(val)
			if failed {
				return fmt.Errorf("noxscript: index out of bounds: [%d:%d]", i, sz)
			}
			continue
		case asm.OpIndexPtr:
			i := s.PopI32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			sz := s.PopI32()
			failed := i < 0 || i > sz
			s.PushBool(isGlobal)
			if vari < 0 {
				s.PushI32(vari - i)
			} else {
				s.PushI32(vari + i)
			}
			if failed {
				return fmt.Errorf("noxscript: index out of bounds: [%d:%d]", i, sz)
			}
			continue
		case asm.OpCallBuiltin:
			fi := asm.Builtin(readInt())
			if err := s.callBuiltin(sc, fi); err != nil {
				return fmt.Errorf("in %q: %w", sc.Name(), err)
			}
		case asm.OpCallScript:
			ind := int(readInt())
			if err := s.CallByIndex(ind, caller, trigger); err != nil {
				return fmt.Errorf("in %q: %w", sc.Name(), err)
			}
		case asm.OpStringAdd:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushString(lhs + rhs)
		default:
			s.adjustStack(bstack, sc.Return)
			return nil
		}
	}
}

func (s *NoxScriptVM) ScriptCallbackRaw(b *ScriptCallback, caller, trigger *Object, out *uint32) *uint32 {
	*out = 0
	flags := b.Flags
	if flags&0x1 != 0 {
		return nil
	}
	sind := int(b.Func)
	if cb, ok := s.virtual.funcs[sind]; ok && cb.Fnc != nil {
		s.vm.caller = caller
		s.vm.trigger = trigger
		if err := cb.Fnc(); err != nil {
			ScriptLog.Printf("ScriptCallback: %s: %v", cb.Name, err)
		}
		*out = 0
		return out
	}
	if sind == -1 {
		return nil
	}
	if flags&0x2 != 0 {
		b.Flags |= 0x1
	}
	if s.saveStack() != 0 {
		s.scriptPushCallback(b, caller, trigger)
		return out
	}
	if err := s.CallByIndex(sind, caller, trigger); err != nil {
		ScriptLog.Println(err)
	}
	scripts := s.Funcs()
	if scripts[sind].Return != 0 {
		*out = s.PopU32()
	}
	s.resetStack()
	// TODO: Previously, the code was tracking how many temp strings were added,
	//       and removed them here. Instead, we can do interning + GC to achieve the same effect.
	s.scriptPopCallback(b, caller, trigger)
	if len(s.vm.callbacks) > 0 {
		s.ScriptCallbackRaw(s.vm.callbacks[0].Block, s.vm.callbacks[0].Caller, s.vm.callbacks[0].Trigger, out)
	}
	return out
}

func (s *NoxScriptVM) Nox_script_objCallbackName_508CB0(obj *Object, event int) (string, bool) {
	sd := obj.Field189
	if sd == nil {
		return "", false
	}
	funcs := s.Funcs()
	switch event {
	case 14:
		if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
			return alloc.GoString((*byte)(sd)), true
		}
		return funcs[obj.Field192].Name(), true
	}
	cl := obj.Class()
	switch {
	default:
		return "", false
	case cl.Has(object.ClassTrigger):
		ud := unsafe.Slice((*uint32)(obj.UpdateData), 9)
		switch event {
		case 0:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 512))), true
			}
			return funcs[ud[4]].Name(), true
		case 1:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 256))), true
			}
			return funcs[ud[6]].Name(), true
		case 2:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 384))), true
			}
			return funcs[ud[8]].Name(), true
		}
		return "", false
	case cl.Has(object.ClassMonster):
		ud := obj.UpdateDataMonster()
		switch ns4.ObjectEvent(event) {
		case ns4.EventEnemySighted:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 640))), true
			}
			return funcs[ud.ScriptEnemySighted.Func].Name(), true
		case ns4.EventLookingForEnemy:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 768))), true
			}
			return funcs[ud.ScriptLookingForEnemy.Func].Name(), true
		case ns4.EventDeath:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 896))), true
			}
			return funcs[ud.ScriptDeath.Func].Name(), true
		case ns4.EventChangeFocus:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1024))), true
			}
			return funcs[ud.ScriptChangeFocus.Func].Name(), true
		case ns4.EventIsHit:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1152))), true
			}
			return funcs[ud.ScriptIsHit.Func].Name(), true
		case ns4.EventRetreat:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1280))), true
			}
			return funcs[ud.ScriptRetreat.Func].Name(), true
		case ns4.EventCollision:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1408))), true
			}
			return funcs[ud.ScriptCollision.Func].Name(), true
		case ns4.EventEnemyHeard:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1536))), true
			}
			return funcs[ud.ScriptHearEnemy.Func].Name(), true
		case ns4.EventEndOfWaypoint:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1664))), true
			}
			return funcs[ud.ScriptEndOfWaypoint.Func].Name(), true
		case ns4.EventLostEnemy:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1792))), true
			}
			return funcs[ud.ScriptLostEnemy.Func].Name(), true
		}
		return "", false
	case cl.Has(object.ClassHole):
		switch event {
		case 12:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 128))), true
			}
			cd := obj.CollideData
			ind := *(*uint32)(unsafe.Add(cd, 4))
			return funcs[ind].Name(), true
		}
		return "", false
	case cl.Has(object.ClassMonsterGenerator):
		ud := unsafe.Slice((*uint32)(obj.UpdateData), 20)
		switch event {
		case 15:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1920))), true
			}
			return funcs[ud[13]].Name(), true
		case 16:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 2048))), true
			}
			return funcs[ud[15]].Name(), true
		case 17:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 2304))), true
			}
			return funcs[ud[17]].Name(), true
		case 18:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 2176))), true
			}
			return funcs[ud[19]].Name(), true
		}
		return "", false
	}
}

func (s *NoxScriptVM) ReadScript(r io.Reader) error {
	scr, err := asm.ReadScript(r)
	if err != nil {
		return err
	}
	s.vm.strings = scr.Strings
	s.vm.funcs = nil
	if len(scr.Funcs) != 0 {
		s.vm.funcs = make([]ScriptFunc, 0, len(scr.Funcs))
	}
	for _, fnc := range scr.Funcs {
		cur := ScriptFunc{FuncDef: fnc}
		if len(fnc.Name) >= 1024 {
			return fmt.Errorf("function name too long: %d", len(fnc.Name))
		}
		if fnc.VarsSz != 0 {
			cur.Values = make([]uint32, fnc.VarsSz)
		}
		s.vm.funcs = append(s.vm.funcs, cur)
	}
	return nil
}

func (s *NoxScriptVM) ActRun() {
	scripts := s.Funcs()
	s.s.Activators.EachTriggered(s.s.Frame(), func(it ActivatorArgs) {
		// TODO: support arguments for virtual funcs
		if it.Callback < len(scripts) && scripts[it.Callback].FuncDef.Args != 0 {
			s.PushU32(it.Arg)
		}
		if err := s.CallByIndex(it.Callback, it.Caller, it.Trigger); err != nil {
			ScriptLog.Println(err)
		}
	})
}

func (s *Server) Nox_server_mapRWScriptData_504F90(cf *cryptfile.CryptFile, _ unsafe.Pointer) error {
	if cf.ReadOnly() {
		return s.nox_server_mapRWScriptData_504F90_Read(cf)
	}
	return s.nox_server_mapRWScriptData_504F90_Write(cf)
}

func (s *Server) nox_server_mapRWScriptData_504F90_Read(cf *cryptfile.CryptFile) error {
	if vers, err := cf.ReadU16(); err != nil {
		return err
	} else if vers > 1 {
		return fmt.Errorf("unsupported script data vers: %v", vers)
	}
	if has, err := cf.ReadU8(); err != nil {
		return err
	} else if has == 0 {
		return nil
	}
	funcs := s.NoxScriptVM.Funcs()
	vars := funcs[1].AllLocals()
	for i := range vars {
		v, err := cf.ReadU32()
		if err != nil {
			return err
		}
		vars[i] = v
	}
	return s.LoadActivators(cf)
}

func (s *Server) nox_server_mapRWScriptData_504F90_Write(cf *cryptfile.CryptFile) error {
	funcs := s.NoxScriptVM.Funcs()
	cf.WriteU16(1)
	has := byte(0)
	if len(funcs) != 0 && noxflags.HasGame(noxflags.GameHost) && !noxflags.HasGame(noxflags.GameFlag23) {
		has = 1
	}
	cf.WriteU8(has)
	if has == 0 {
		return nil
	}
	vars := funcs[1].AllLocals()
	for _, v := range vars {
		cf.WriteU32(v)
	}
	return s.SaveActivators(cf)
}
