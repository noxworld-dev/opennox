package noxscript

import (
	"errors"
	"fmt"
	"math"
)

func (r *Runtime) newFunc(def *FuncDef) *Func {
	f := &Func{r: r, def: def}
	f.allocVars()
	return f
}

type Func struct {
	r    *Runtime
	def  *FuncDef
	vars [][]int32
	data []int32
}

func (f *Func) Def() *FuncDef {
	return f.def
}

func (f *Func) allocVars() {
	f.vars = make([][]int32, len(f.def.Vars))
	f.data = make([]int32, f.def.VarsSz)
	for i, d := range f.def.Vars {
		if d.Size == 0 {
			continue
		}
		f.vars[i] = f.data[d.Offs : d.Offs+d.Size]
	}
}

func (f *Func) Name() string {
	return f.def.Name
}

func (f *Func) ptrToVar(ptr int) (i, j int) {
	_ = f.data[ptr] // bounds check
	for i, v := range f.def.Vars {
		if v.Offs <= ptr && ptr < v.Offs+v.Size {
			return i, ptr - v.Offs
		}
	}
	panic("unknown var offset")
}

func (f *Func) setPtrInt(ptr int, v int32) {
	i, j := f.ptrToVar(ptr)
	f.setArrInt(i, j, v)
}

func (f *Func) setArrInt(i, j int, v int32) {
	f.vars[i][j] = v
}

func (f *Func) setPtrFloat(ptr int, v float32) {
	i, j := f.ptrToVar(ptr)
	f.setArrFloat(i, j, v)
}

func (f *Func) setArrFloat(i, j int, v float32) {
	f.vars[i][j] = int32(math.Float32bits(v))
}

func (f *Func) setArrString(i, j int, s string) {
	si := f.r.AddString(s)
	f.setArrInt(i, j, int32(si))
}

func (f *Func) setArrBool(i, j int, v bool) {
	if v {
		f.vars[i][j] = 1
	} else {
		f.vars[i][j] = 0
	}
}

func (f *Func) getPtrInt(ptr int) int32 {
	i, j := f.ptrToVar(ptr)
	return f.getArrInt(i, j)
}

func (f *Func) getArrInt(i, j int) int32 {
	return f.vars[i][j]
}

func (f *Func) getPtrFloat(ptr int) float32 {
	i, j := f.ptrToVar(ptr)
	return f.getArrFloat(i, j)
}

func (f *Func) getArrFloat(i, j int) float32 {
	return math.Float32frombits(uint32(f.vars[i][j]))
}

func (f *Func) getPtrBool(ptr int) bool {
	i, j := f.ptrToVar(ptr)
	return f.getArrBool(i, j)
}

func (f *Func) getArrBool(i, j int) bool {
	return f.vars[i][j] != 0
}

func (f *Func) Call(caller, trigger Object, args ...interface{}) (gerr error) {
	if f == nil {
		return &Error{Err: errors.New("nil function")}
	}
	defer func() {
		switch r := recover().(type) {
		case *Error:
			gerr = r
		case error:
			gerr = &Error{Func: f.Name(), Err: r}
		default:
			gerr = &Error{Func: f.Name(), Err: fmt.Errorf("panic: %v", r)}
		case nil:
			switch err := gerr.(type) {
			case nil, *Error, *ErrNoFunc:
			default:
				gerr = &Error{Func: f.Name(), Err: err}
			}
		}
	}()
	r := f.r
	// TODO: pass these via closure
	r.caller = caller
	r.trigger = trigger

	if args != nil {
		if len(args) != f.def.Args {
			return fmt.Errorf("unexpected number of arguments: expected %d, got %d", f.def.Args, len(args))
		}
		for i := 0; i < f.def.Args; i++ {
			switch v := args[i].(type) {
			case nil:
				f.setArrInt(i, 0, 0)
			case int:
				f.setArrInt(i, 0, int32(v))
			case bool:
				f.setArrBool(i, 0, v)
			case float32:
				f.setArrFloat(i, 0, v)
			case string:
				f.setArrString(i, 0, v)
			case Object:
				f.setArrInt(i, 0, int32(v.NoxScriptID()))
			default:
				return fmt.Errorf("unsupported argument type: %T", args[i])
			}
		}
	} else {
		for i := 0; i < f.def.Args; i++ {
			v := r.PopInt32()
			f.vars[i][0] = v
		}
	}

	bstack := r.stackTop()
	code := f.def.Code
	nextInt := func() int32 {
		v := int32(code[0])
		code = code[1:]
		return v
	}
	nextFloat := func() float32 {
		v := math.Float32frombits(code[0])
		code = code[1:]
		return v
	}
	for {
		switch op := nextInt(); op {
		case 0x00, 0x03: // int var or string var
			isGlobal := nextInt() != 0
			vari := int(nextInt())
			var val int32
			if isGlobal {
				val = r.funcs[1].getArrInt(vari, 0)
			} else if vari < 0 {
				// TODO: remember those -2 and -1 (self and other)? are they related?
				off := r.funcs[0].def.Vars[-vari].Offs
				val = trigger.GetNoxScriptVal(off)
			} else {
				val = f.getArrInt(vari, 0)
			}
			r.PushInt32(val)
			continue
		case 0x01: // float var
			isGlobal := nextInt() != 0
			vari := int(nextInt())
			var val float32
			if isGlobal {
				val = r.funcs[1].getArrFloat(vari, 0)
			} else if vari < 0 {
				off := r.funcs[0].def.Vars[-vari].Offs
				val = math.Float32frombits(uint32(trigger.GetNoxScriptVal(off)))
			} else {
				val = f.getArrFloat(vari, 0)
			}
			r.PushFloat32(val)
			continue
		case 0x02: // var ptr
			isGlobal := nextInt()
			ind := int(nextInt())
			// TODO: this exposes variable layout and forces us to access it unsafely in a few other ops
			var sz, ptr int
			if isGlobal != 0 {
				sz = r.funcs[1].def.Vars[ind].Size
				ptr = r.funcs[1].def.Vars[ind].Offs
			} else if ind < 0 {
				ind = -ind
				sz = r.funcs[0].def.Vars[ind].Size
				ptr = -r.funcs[0].def.Vars[ind].Offs
			} else {
				sz = f.def.Vars[ind].Size
				ptr = f.def.Vars[ind].Offs
			}
			if sz > 1 {
				r.PushInt32(int32(sz))
			}
			r.PushInt32(isGlobal)
			r.PushInt32(int32(ptr))
			continue
		case 0x04, 0x06: // int literal or string literal
			val := nextInt()
			r.PushInt32(val)
			continue
		case 0x05: // float literal
			val := nextFloat()
			r.PushFloat32(val)
			continue
		case 0x07, 0x09, 0x0B, 0x0D, 0x0F, // +, -, *, /, % (int)
			0x10, 0x11, 0x12, 0x26, 0x27: // &, |, ^, <<, >> (int)
			rhs := r.PopInt32()
			lhs := r.PopInt32()
			var val int32
			switch op {
			case 0x07:
				val = lhs + rhs
			case 0x09:
				val = lhs - rhs
			case 0x0B:
				val = lhs * rhs
			case 0x0D:
				val = lhs / rhs
			case 0x0F:
				val = lhs % rhs
			case 0x10:
				val = lhs & rhs
			case 0x11:
				val = lhs | rhs
			case 0x12:
				val = lhs ^ rhs
			case 0x26:
				val = lhs << rhs
			case 0x27:
				val = lhs >> rhs
			}
			r.PushInt32(val)
			continue
		case 0x08, 0x0A, 0x0C, 0x0E: // +, -, *, / (float)
			rhs := r.PopFloat32()
			lhs := r.PopFloat32()
			var val float32
			switch op {
			case 0x08:
				val = lhs + rhs
			case 0x0A:
				val = lhs - rhs
			case 0x0C:
				val = lhs * rhs
			case 0x0E:
				val = lhs / rhs
			}
			r.PushFloat32(val)
			continue
		case 0x13: // jump
			off := nextInt()
			code = f.def.Code[off:]
			continue
		case 0x14: // jump if
			off := nextInt()
			if r.PopBool() { // TODO: double-check condition
				code = f.def.Code[off:]
			}
			continue
		case 0x15: // jump if not
			off := nextInt()
			if !r.PopBool() { // TODO: double-check condition
				code = f.def.Code[off:]
			}
			continue
		case 0x16, 0x18: // = (int or string)
			rhs := r.PopInt32()
			ptr := r.PopInt()
			isGlobal := r.PopBool()
			if isGlobal {
				r.funcs[1].setPtrInt(ptr, rhs)
			} else if ptr < 0 {
				trigger.SetNoxScriptVal(-ptr, rhs)
			} else {
				f.setPtrInt(ptr, rhs)
			}
			r.PushInt32(rhs)
			continue
		case 0x17: // = (float)
			rhs := r.PopFloat32()
			ptr := r.PopInt()
			isGlobal := r.PopBool()
			if isGlobal {
				r.funcs[1].setPtrFloat(ptr, rhs)
			} else if ptr < 0 {
				trigger.SetNoxScriptVal(-ptr, int32(math.Float32bits(rhs)))
			} else {
				f.setPtrFloat(ptr, rhs)
			}
			r.PushFloat32(rhs)
			continue
		case 0x19, 0x1B, 0x1D, 0x20, 0x22, // *=, /=, +=, -=, %=, (int)
			0x39, 0x3A, 0x3B, 0x3C, 0x3D: //  <<=, >>=, &=, |=, ^= (int)
			rhs := r.PopInt32()
			ptr := r.PopInt()
			isGlobal := r.PopBool()
			var v int32
			if isGlobal {
				v = r.funcs[1].getPtrInt(ptr)
			} else if ptr < 0 {
				v = trigger.GetNoxScriptVal(-ptr)
			} else {
				v = f.getPtrInt(ptr)
			}
			switch op {
			case 0x19:
				v *= rhs
			case 0x1B:
				v /= rhs
			case 0x1D:
				v += rhs
			case 0x20:
				v -= rhs
			case 0x22:
				v %= rhs
			case 0x39:
				v <<= rhs
			case 0x3A:
				v >>= rhs
			case 0x3B:
				v &= rhs
			case 0x3C:
				v |= rhs
			case 0x3D:
				v ^= rhs
			}
			if isGlobal {
				r.funcs[1].setPtrInt(ptr, v)
			} else if ptr < 0 {
				trigger.SetNoxScriptVal(-ptr, v)
			} else {
				f.setPtrInt(ptr, v)
			}
			r.PushInt32(v)
			continue
		case 0x1A, 0x1C, 0x1E, 0x21: // *=, /=, +=, -= (float)
			rhs := r.PopFloat32()
			ptr := r.PopInt()
			isGlobal := r.PopBool()
			var v float32
			if isGlobal {
				v = r.funcs[1].getPtrFloat(ptr)
			} else if ptr < 0 {
				v = math.Float32frombits(uint32(trigger.GetNoxScriptVal(-ptr)))
			} else {
				v = f.getPtrFloat(ptr)
			}
			switch op {
			case 0x1A:
				v *= rhs
			case 0x1C:
				v /= rhs
			case 0x1E:
				v += rhs
			case 0x21:
				v -= rhs
			}
			if isGlobal {
				r.funcs[1].setPtrFloat(ptr, v)
			} else if ptr < 0 {
				trigger.SetNoxScriptVal(-ptr, int32(math.Float32bits(v)))
			} else {
				f.setPtrFloat(ptr, v)
			}
			r.PushFloat32(v)
			continue
		case 0x1F: // += (string)
			rhs := r.PopInt()
			ptr := r.PopInt()
			isGlobal := r.PopBool()
			var sid int32
			if isGlobal {
				sid = r.funcs[1].getPtrInt(ptr)
			} else if ptr < 0 {
				sid = trigger.GetNoxScriptVal(-ptr)
			} else {
				sid = f.getPtrInt(ptr)
			}
			buf := r.GetString(int(sid)) + r.GetString(rhs)
			sid = int32(r.AddString(buf))
			if isGlobal {
				r.funcs[1].setPtrInt(ptr, sid)
			} else if ptr < 0 {
				trigger.SetNoxScriptVal(-ptr, sid)
			} else {
				f.setPtrInt(ptr, sid)
			}
			r.PushInt32(sid)
			continue
		case 0x23, 0x28, 0x2B, 0x2E, 0x31, 0x34: // ==, <, >, <=, >=, != (int)
			rhs := r.PopInt32()
			lhs := r.PopInt32()
			var val bool
			switch op {
			case 0x23:
				val = lhs == rhs
			case 0x28:
				val = lhs < rhs
			case 0x2B:
				val = lhs > rhs
			case 0x2E:
				val = lhs <= rhs
			case 0x31:
				val = lhs >= rhs
			case 0x34:
				val = lhs != rhs
			}
			r.PushBool(val)
			continue
		case 0x24, 0x29, 0x2C, 0x2F, 0x32, 0x35: // ==, <, >, <=, >=, != (float)
			rhs := r.PopFloat32()
			lhs := r.PopFloat32()
			var val bool
			switch op {
			case 0x24:
				val = lhs == rhs
			case 0x29:
				val = lhs < rhs
			case 0x2C:
				val = lhs > rhs
			case 0x2F:
				val = lhs <= rhs
			case 0x32:
				val = lhs >= rhs
			case 0x35:
				val = lhs != rhs
			}
			r.PushBool(val)
			continue
		case 0x25, 0x2A, 0x2D, 0x30, 0x33, 0x36: // ==, <, >, <=, >=, != (string)
			rhs := r.PopString()
			lhs := r.PopString()
			var val bool
			switch op {
			case 0x25:
				val = lhs == rhs
			case 0x2A:
				val = lhs < rhs
			case 0x2D:
				val = lhs > rhs
			case 0x30:
				val = lhs <= rhs
			case 0x33:
				val = lhs >= rhs
			case 0x36:
				val = lhs != rhs
			}
			r.PushBool(val)
			continue
		case 0x37: // && (int)
			rhs := r.PopBool()
			lhs := r.PopBool()
			r.PushBool(lhs && rhs)
			continue
		case 0x38: // || (int)
			rhs := r.PopBool()
			lhs := r.PopBool()
			r.PushBool(lhs || rhs)
			continue
		case 0x3E: // !v (int)
			v := r.PopBool()
			r.PushBool(!v)
			continue
		case 0x3F: // ^v (int)
			v := r.PopInt32()
			r.PushInt32(^v)
			continue
		case 0x40: // -v (int)
			v := r.PopInt32()
			r.PushInt32(-v)
			continue
		case 0x41: // -v (float)
			v := -r.PopFloat32()
			r.PushFloat32(v)
			continue
		case 0x42: // [i] (int)
			i := r.PopInt()
			vari := r.PopInt()
			isGlobal := r.PopBool()
			sz := r.PopInt()
			if i < 0 || i >= sz {
				return fmt.Errorf("array index out of bounds: [%d:%d]", i, sz)
			}
			var val int32
			if isGlobal {
				val = r.funcs[1].getArrInt(vari, i)
			} else if vari < 0 {
				val = trigger.GetNoxScriptVal(vari - i)
			} else {
				val = f.getArrInt(vari, i)
			}
			r.PushInt32(val)
			continue
		case 0x43: // [i] (float)
			i := r.PopInt()
			vari := r.PopInt()
			isGlobal := r.PopBool()
			sz := r.PopInt()
			if i < 0 || i >= sz {
				return fmt.Errorf("array index out of bounds: [%d:%d]", i, sz)
			}
			var val float32
			if isGlobal {
				val = r.funcs[1].getArrFloat(vari, i)
			} else if vari < 0 {
				val = math.Float32frombits(uint32(trigger.GetNoxScriptVal(vari - i)))
			} else {
				val = f.getArrFloat(vari, i)
			}
			r.PushFloat32(val)
			continue
		case 0x44: // &[i] (any)
			i := r.PopInt()
			vari := r.PopInt()
			isGlobal := r.PopBool()
			sz := r.PopInt()
			if i < 0 || i >= sz {
				return fmt.Errorf("array index out of bounds: [%d:%d]", i, sz)
			}
			r.PushBool(isGlobal)
			if vari < 0 {
				r.PushInt(vari - i)
			} else {
				r.PushInt(vari + i)
			}
			continue
		case 0x45: // call builtin
			ind := nextInt()
			v, err := f.CallBuiltin(int(ind))
			if err != nil {
				return err
			} else if v == 1 {
				break // TODO: return error?
			}
			continue
		case 0x46: // call script
			ind := int(nextInt())
			if err := r.FuncByInd(ind).Call(caller, trigger); err != nil {
				return err
			}
			continue
		case 0x49: // + (string)
			sa1 := r.PopString()
			sa2 := r.PopString()
			r.PushString(sa2 + sa1)
			continue
		case 0x47, 0x48:
		default:
		}
		if top := r.stackTop(); top != bstack+f.def.Return {
			if f.def.Return != 0 {
				if top != 0 {
					v := r.PopInt32()
					r.stackSet(bstack)
					r.PushInt32(v)
				} else {
					r.stackSet(bstack)
					r.PushInt32(0)
				}
			} else {
				r.stackSet(bstack)
			}
		}
		return nil
	}
}
