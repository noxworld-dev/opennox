package script

import (
	"encoding/binary"
	"math"
	"strings"
	"unsafe"
)

type Script struct {
	r         *Runtime
	name      string
	stackSize int
	size28    int
	field12   int
	field16   int
	field20   []int32
	field24   []int32
	field28   []int32
	code      []byte
	f36       string
	f40       int
	f44       int
}

func (sc *Script) Name() string {
	return sc.name
}

func (sc *Script) setField28Int(i int32, v int32) {
	sc.field28[i] = v
}

func (sc *Script) setField28Float(i int32, v float32) {
	sc.field28[i] = int32(math.Float32bits(v))
}

func (sc *Script) getField28Int(i int32) int32 {
	return sc.field28[i]
}

func (sc *Script) getField28Float(i int32) float32 {
	return math.Float32frombits(uint32(sc.field28[i]))
}

func (sc *Script) Call(a2, a3 unsafe.Pointer) {
	if sc == nil {
		return
	}
	r := sc.r
	r.caller = a2
	r.trigger = a3

	for i := 0; i < sc.size28; i++ {
		v := r.PopInt()
		sc.field28[i] = v
	}
	bstack := r.stackTop()
	code := sc.code
	nextInt := func() int32 {
		v := int32(binary.LittleEndian.Uint32(code))
		code = code[4:]
		return v
	}
	nextFloat := func() float32 {
		v := math.Float32frombits(binary.LittleEndian.Uint32(code))
		code = code[4:]
		return v
	}
	// TODO: remove this once type of a3 is clear
	getA3Field := func(field int, i int32) unsafe.Pointer {
		p := *(*unsafe.Pointer)(unsafe.Pointer(uintptr(a3) + uintptr(field)))
		return unsafe.Pointer(uintptr(p) + uintptr(4*i))
	}
	for {
		switch nextInt() {
		case 0, 3: // get xxx int
			sa1 := nextInt()
			sa2 := nextInt()
			if sa1 != 0 {
				sa2 = r.scripts[1].field24[sa2]
				sa2 = r.scripts[1].getField28Int(sa2)
				r.PushInt(sa2)
			} else if sa2 < 0 {
				sa2 = -sa2
				sa2 = r.scripts[0].field24[sa2]
				sa2 = *(*int32)(getA3Field(760, sa2))
				r.PushInt(sa2)
			} else {
				sa2 = sc.field24[sa2]
				sa2 = sc.getField28Int(sa2)
				r.PushInt(sa2)
			}
			continue
		case 1: // get xxx float
			sa1 := nextInt()
			sa2 := nextInt()
			var sf1 float32
			if sa1 != 0 {
				sa2 = r.scripts[1].field24[sa2]
				sf1 = r.scripts[1].getField28Float(sa2)
			} else if sa2 < 0 {
				sa2 = -sa2
				sa2 = r.scripts[0].field24[sa2]
				sf1 = *(*float32)(getA3Field(760, sa2))
			} else {
				sa2 = sc.field24[sa2]
				sf1 = sc.getField28Float(sa2)
			}
			r.PushFloat(sf1)
			continue
		case 2:
			sa1 := nextInt()
			sa2 := nextInt()
			var sa3, sa4 int32
			if sa1 != 0 {
				sa3 = r.scripts[1].field20[sa2]
				sa4 = r.scripts[1].field24[sa2]
			} else if sa2 < 0 {
				sa2 = -sa2
				sa3 = r.scripts[0].field20[sa2]
				sa4 = -r.scripts[0].field24[sa2]
			} else {
				sa3 = sc.field20[sa2]
				sa4 = sc.field24[sa2]
			}
			if sa3 > 1 {
				r.PushInt(sa3)
			}
			r.PushInt(sa1)
			r.PushInt(sa4)
			continue
		case 4, 6: // static int
			sa1 := nextInt()
			r.PushInt(sa1)
			continue
		case 5: // static float
			sf1 := nextFloat()
			r.PushFloat(sf1)
			continue
		case 7: // add int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushInt(sa2 + sa1)
			continue
		case 8: // add float
			sf1 := r.PopFloat()
			sf2 := r.PopFloat()
			r.PushFloat(sf1 + sf2)
			continue
		case 9: // sub int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushInt(sa2 - sa1)
			continue
		case 10: // sub float
			sf1 := r.PopFloat()
			sf2 := r.PopFloat()
			r.PushFloat(sf2 - sf1)
			continue
		case 11: // mult int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushInt(sa1 * sa2)
			continue
		case 12: // mult float
			sf1 := r.PopFloat()
			sf2 := r.PopFloat()
			r.PushFloat(sf1 * sf2)
			continue
		case 13: // div int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushInt(sa2 / sa1)
			continue
		case 14: // div float
			sf1 := r.PopFloat()
			sf2 := r.PopFloat()
			r.PushFloat(sf2 / sf1)
			continue
		case 15: // mod int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushInt(sa2 % sa1)
			continue
		case 16: // bit mult int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushInt(sa2 & sa1)
			continue
		case 17: // bit or int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushInt(sa2 | sa1)
			continue
		case 18: // bit xor int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushInt(sa2 ^ sa1)
			continue
		case 19: // jump
			sa1 := nextInt()
			code = sc.code[4*sa1:]
			continue
		case 20: // jump if
			sa1 := nextInt()
			if r.PopBool() {
				code = sc.code[4*sa1:]
			}
			continue
		case 21: // jump if not
			sa1 := nextInt()
			if !r.PopBool() {
				code = sc.code[4*sa1:]
			}
			continue
		case 22, 24: // set xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				r.scripts[1].setField28Int(sa2, sa1)
			} else if sa2 < 0 {
				*(*int32)(getA3Field(760, -sa2)) = sa1
			} else {
				sc.setField28Int(sa2, sa1)
			}
			r.PushInt(sa1)
			continue
		case 23: // set xxx float
			sf1 := r.PopFloat()
			sa2 := r.PopInt()
			if r.PopBool() {
				r.scripts[1].setField28Float(sa2, sf1)
			} else if sa2 < 0 {
				*(*float32)(getA3Field(760, -sa2)) = sf1
			} else {
				sc.setField28Float(sa2, sf1)
			}
			r.PushFloat(sf1)
			continue
		case 25: // mult xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Int(sa2)
				v *= sa1
				r.scripts[1].setField28Int(sa2, v)
				r.PushInt(v)
			} else if sa2 < 0 {
				*(*int32)(getA3Field(760, -sa2)) *= sa1
				r.PushInt(*(*int32)(getA3Field(760, -sa2)))
			} else {
				v := sc.getField28Int(sa2)
				v *= sa1
				sc.setField28Int(sa2, v)
				r.PushInt(v)
			}
			continue
		case 26: // mult xxx float
			sf1 := r.PopFloat()
			sa1 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Float(sa1)
				v *= sf1
				r.scripts[1].setField28Float(sa1, v)
				r.PushFloat(v)
			} else if sa1 < 0 {
				*(*float32)(getA3Field(760, -sa1)) *= sf1
				r.PushFloat(*(*float32)(getA3Field(760, -sa1)))
			} else {
				v := sc.getField28Float(sa1)
				v *= sf1
				sc.setField28Float(sa1, v)
				r.PushFloat(v)
			}
			continue
		case 27: // div xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Int(sa2)
				v /= sa1
				r.scripts[1].setField28Int(sa2, v)
				r.PushInt(v)
			} else if sa2 < 0 {
				*(*int32)(getA3Field(760, -sa2)) /= sa1
				r.PushInt(*(*int32)(getA3Field(760, -sa2)))
			} else {
				v := sc.getField28Int(sa2)
				v /= sa1
				sc.setField28Int(sa2, v)
				r.PushInt(v)
			}
			continue
		case 28: // div xxx float
			sf1 := r.PopFloat()
			sa1 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Float(sa1)
				v /= sf1
				r.scripts[1].setField28Float(sa1, v)
				r.PushFloat(v)
			} else if sa1 < 0 {
				*(*float32)(getA3Field(760, -sa1)) /= sf1
				r.PushFloat(*(*float32)(getA3Field(760, -sa1)))
			} else {
				v := sc.getField28Float(sa1)
				v /= sf1
				sc.setField28Float(sa1, v)
				r.PushFloat(v)
			}
			continue
		case 29: // add xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Int(sa2)
				v += sa1
				r.scripts[1].setField28Int(sa2, v)
				r.PushInt(v)
			} else if sa2 < 0 {
				*(*int32)(getA3Field(760, -sa2)) += sa1
				r.PushInt(*(*int32)(getA3Field(760, -sa2)))
			} else {
				v := sc.getField28Int(sa2)
				v += sa1
				sc.setField28Int(sa2, v)
				r.PushInt(v)
			}
			continue
		case 30: // add xxx float
			sf1 := r.PopFloat()
			sa1 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Float(sa1)
				v += sf1
				r.scripts[1].setField28Float(sa1, v)
				r.PushFloat(v)
			} else if sa1 < 0 {
				*(*float32)(getA3Field(760, -sa1)) += sf1
				r.PushFloat(*(*float32)(getA3Field(760, -sa1)))
			} else {
				v := sc.getField28Float(sa1)
				v += sf1
				sc.setField28Float(sa1, v)
				r.PushFloat(v)
			}
			continue
		case 31: // cat xxx string
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			sa3 := r.PopBool()
			var sa4 int32
			if sa3 {
				sa4 = r.scripts[1].getField28Int(sa2)
			} else if sa2 < 0 {
				sa4 = *(*int32)(getA3Field(760, -sa2))
			} else {
				sa4 = sc.getField28Int(sa2)
			}
			buf := r.GetString(int(sa4)) + r.GetString(int(sa1))
			si := int32(r.AddString(buf))
			if sa3 {
				r.scripts[1].setField28Int(sa2, si)
			} else if sa2 < 0 {
				*(*int32)(getA3Field(760, -sa2)) = si
			} else {
				sc.setField28Int(sa2, si)
			}
			r.PushInt(si)
			continue
		case 32: // sub xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Int(sa2)
				v -= sa1
				r.scripts[1].setField28Int(sa2, v)
				r.PushInt(v)
			} else if sa2 < 0 {
				*(*int32)(getA3Field(760, -sa2)) -= sa1
				r.PushInt(*(*int32)(getA3Field(760, -sa2)))
			} else {
				v := sc.getField28Int(sa2)
				v -= sa1
				sc.setField28Int(sa2, v)
				r.PushInt(v)
			}
			continue
		case 33: // sub xxx float
			sf1 := r.PopFloat()
			sa1 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Float(sa1)
				v -= sf1
				r.scripts[1].setField28Float(sa1, v)
				r.PushFloat(v)
			} else if sa1 < 0 {
				*(*float32)(getA3Field(760, -sa1)) -= sf1
				r.PushInt(*(*int32)(getA3Field(760, -sa1)))
			} else {
				v := sc.getField28Float(sa1)
				v -= sf1
				sc.setField28Float(sa1, v)
				r.PushFloat(v)
			}
			continue
		case 34: // mod xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Int(sa2)
				v %= sa1
				r.scripts[1].setField28Int(sa2, v)
				r.PushInt(v)
			} else if sa2 < 0 {
				*(*int32)(getA3Field(760, -sa2)) %= sa1
				r.PushInt(*(*int32)(getA3Field(760, -sa2)))
			} else {
				v := sc.getField28Int(sa2)
				v %= sa1
				sc.setField28Int(sa2, v)
				r.PushInt(v)
			}
			continue
		case 35: // equal int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushBool(sa2 == sa1)
			continue
		case 36: // equal float
			sf1 := r.PopFloat()
			sf2 := r.PopFloat()
			r.PushBool(sf2 == sf1)
			continue
		case 37: // equal string
			sa1 := r.PopString()
			sa2 := r.PopString()
			r.PushBool(sa2 == sa1)
			continue
		case 38: // left shift
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushInt(sa2 << sa1)
			continue
		case 39: // right shift
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushInt(sa2 >> sa1)
			continue
		case 40: // < int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushBool(sa2 < sa1)
			continue
		case 41: // < float
			sf1 := r.PopFloat()
			sf2 := r.PopFloat()
			r.PushBool(sf2 < sf1)
			continue
		case 42: // < string
			sa1 := r.PopString()
			sa2 := r.PopString()
			r.PushBool(strings.Compare(sa2, sa1) < 0)
			continue
		case 43: // > int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushBool(sa2 > sa1)
			continue
		case 44: // > float
			sf1 := r.PopFloat()
			sf2 := r.PopFloat()
			r.PushBool(sf2 > sf1)
			continue
		case 45: // > string
			sa1 := r.PopString()
			sa2 := r.PopString()
			r.PushBool(strings.Compare(sa2, sa1) > 0)
			continue
		case 46: // <= int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushBool(sa2 <= sa1)
			continue
		case 47: // <= float
			sf1 := r.PopFloat()
			sf2 := r.PopFloat()
			r.PushBool(sf2 <= sf1)
			continue
		case 48: // <= string
			sa1 := r.PopString()
			sa2 := r.PopString()
			r.PushBool(strings.Compare(sa2, sa1) <= 0)
			continue
		case 49: // >= int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushBool(sa2 >= sa1)
			continue
		case 50: // >= float
			sf1 := r.PopFloat()
			sf2 := r.PopFloat()
			r.PushBool(sf2 >= sf1)
			continue
		case 51: // >= string
			sa1 := r.PopString()
			sa2 := r.PopString()
			r.PushBool(strings.Compare(sa2, sa1) >= 0)
			continue
		case 52: // not equal int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			r.PushBool(sa2 != sa1)
			continue
		case 53: // not equal float
			sf1 := r.PopFloat()
			sf2 := r.PopFloat()
			r.PushBool(sf2 != sf1)
			continue
		case 54: // not equal string
			sa1 := r.PopString()
			sa2 := r.PopString()
			r.PushBool(sa2 != sa1)
			continue
		case 55: // logical and
			sa1 := r.PopBool()
			sa2 := r.PopBool()
			r.PushBool(sa2 && sa1)
			continue
		case 56: // logical or
			sa1 := r.PopBool()
			sa2 := r.PopBool()
			r.PushBool(sa2 || sa1)
			continue
		case 57: // left shift xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Int(sa2)
				v <<= sa1
				r.scripts[1].setField28Int(sa2, v)
				r.PushInt(v)
			} else if sa2 < 0 {
				*(*uint32)(getA3Field(760, -sa2)) <<= sa1
				r.PushInt(*(*int32)(getA3Field(760, -sa2)))
			} else {
				v := sc.getField28Int(sa2)
				v <<= sa1
				sc.setField28Int(sa2, v)
				r.PushInt(v)
			}
			continue
		case 58: // right shift xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Int(sa2)
				v >>= sa1
				r.scripts[1].setField28Int(sa2, v)
				r.PushInt(v)
			} else if sa2 < 0 {
				*(*uint32)(getA3Field(760, -sa2)) >>= sa1
				r.PushInt(*(*int32)(getA3Field(760, -sa2)))
			} else {
				v := sc.getField28Int(sa2)
				v >>= sa1
				sc.setField28Int(sa2, v)
				r.PushInt(v)
			}
			continue
		case 59: // bit mult xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Int(sa2)
				v &= sa1
				r.scripts[1].setField28Int(sa2, v)
				r.PushInt(v)
			} else if sa2 < 0 {
				*(*int32)(getA3Field(760, -sa2)) &= sa1
				r.PushInt(*(*int32)(getA3Field(760, -sa2)))
			} else {
				v := sc.getField28Int(sa2)
				v &= sa1
				sc.setField28Int(sa2, v)
				r.PushInt(v)
			}
			continue
		case 60: // bit or xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Int(sa2)
				v |= sa1
				r.scripts[1].setField28Int(sa2, v)
				r.PushInt(v)
			} else if sa2 < 0 {
				*(*int32)(getA3Field(760, -sa2)) |= sa1
				r.PushInt(*(*int32)(getA3Field(760, -sa2)))
			} else {
				v := sc.getField28Int(sa2)
				v |= sa1
				sc.setField28Int(sa2, v)
				r.PushInt(v)
			}
			continue
		case 61: // bit xor xxx int
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			if r.PopBool() {
				v := r.scripts[1].getField28Int(sa2)
				v ^= sa1
				r.scripts[1].setField28Int(sa2, v)
				r.PushInt(v)
			} else if sa2 < 0 {
				*(*int32)(getA3Field(760, -sa2)) ^= sa1
				r.PushInt(*(*int32)(getA3Field(760, -sa2)))
			} else {
				v := sc.getField28Int(sa2)
				v ^= sa1
				sc.setField28Int(sa2, v)
				r.PushInt(v)
			}
			continue
		case 62: // not int
			sa1 := r.PopInt()
			r.PushBool(sa1 == 0)
			continue
		case 63: // invert int
			sa1 := r.PopInt()
			r.PushInt(^sa1)
			continue
		case 64: // negate int
			sa1 := r.PopInt()
			r.PushInt(-sa1)
			continue
		case 65: // negate float
			sf1 := -r.PopFloat()
			r.PushFloat(sf1)
			continue
		case 66:
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			sa3 := r.PopBool()
			sa4 := r.PopInt()
			sa5 := false
			if sa1 < 0 || sa1 >= sa4 {
				sa5 = true
			}
			if sa3 {
				sa4 = r.scripts[1].getField28Int(sa1 + sa2)
			} else if sa2 < 0 {
				sa4 = *(*int32)(getA3Field(760, sa2-sa1))
			} else {
				sa4 = sc.getField28Int(sa1 + sa2)
			}
			r.PushInt(sa4)
			if sa5 {
				break
			}
			continue
		case 67:
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			sa3 := r.PopBool()
			sa4 := r.PopInt()
			sa5 := false
			if sa1 < 0 || sa1 > sa4 {
				sa5 = true
			}
			var sf1 float32
			if sa3 {
				sf1 = r.scripts[1].getField28Float(sa1 + sa2)
			} else if sa2 < 0 {
				sf1 = *(*float32)(getA3Field(760, sa2-sa1))
			} else {
				sf1 = sc.getField28Float(sa1 + sa2)
			}
			r.PushFloat(sf1)
			if sa5 {
				break
			}
			continue
		case 68:
			sa1 := r.PopInt()
			sa2 := r.PopInt()
			sa3 := r.PopInt()
			sa4 := r.PopInt()
			sa5 := false
			if sa1 < 0 || sa1 > sa4 {
				sa5 = true
			}
			r.PushInt(sa3)
			if sa2 < 0 {
				r.PushInt(sa2 - sa1)
			} else {
				r.PushInt(sa2 + sa1)
			}
			if sa5 {
				break
			}
			continue
		case 69: // call builtin
			sa1 := nextInt()
			v, ok := sc.CallBuiltin(int(sa1))
			if !ok {
				continue // TODO: break instead?
			} else if v == 1 {
				break
			}
			continue
		case 70: // call script
			sa1 := nextInt()
			r.Script(int(sa1)).Call(a2, a3)
			continue
		case 73: // string cat
			sa1 := r.PopString()
			sa2 := r.PopString()
			r.PushString(sa2 + sa1)
			continue
		default:
			break
		}
		if top := r.stackTop(); top != bstack+sc.stackSize {
			if sc.stackSize != 0 {
				if top != 0 {
					v := r.PopInt()
					r.stackSet(bstack)
					r.PushInt(v)
				} else {
					r.stackSet(bstack)
					r.PushInt(0)
				}
			} else {
				r.stackSet(bstack)
			}
		}
		return
	}
}
