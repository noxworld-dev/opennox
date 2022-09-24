package opennox

/*
#include "GAME4.h"
#include "GAME4_3.h"

static int nox_call_objectType_parse_go(int (*fnc)(nox_objectType_t*, nox_memfile*, char*), nox_objectType_t* arg1, nox_memfile* arg2, char* arg3) {
	return fnc(arg1, arg2, arg3);
}
*/
import "C"
import (
	"errors"
	"fmt"
	"io"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/things"
)

type objectFieldFunc func(objt *ObjectType, f *MemFile, str string, buf []byte) error

func nox_thing_read_xxx_4E3220(f *MemFile, buf []byte, typ *ObjectType) error {
	for {
		sz := f.ReadU8()
		if sz == 0 {
			return nil
		}
		if _, err := io.ReadFull(f, buf[:sz]); err != nil {
			return fmt.Errorf("cannot read object type: %w", err)
		}
		buf[sz] = 0
		str := string(buf[:sz])
		name := str
		if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
			name = str[:i]
			str = str[i+1:]
		}
		parseFnc := noxObjectFieldByName[name]
		if parseFnc == nil {
			continue
		}
		if i := strings.IndexByte(str, '='); i >= 0 {
			str = str[i+1:]
		}
		str = strings.TrimSpace(str)
		if err := parseFnc(typ, f, str, buf); err != nil {
			return fmt.Errorf("parse of %q failed: %w", name, err)
		}
	}
}

func wrapObjectFieldFuncC(p unsafe.Pointer) objectFieldFunc {
	return func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		n := copy(buf, str)
		buf[n] = 0
		ok := C.nox_call_objectType_parse_go((*[0]byte)(p), objt.C(), f.C(), (*C.char)(unsafe.Pointer(&buf[0])))
		if ok == 0 {
			return errors.New("parsing failed")
		}
		return nil
	}
}

func firstWord(s string) string {
	if i := strings.IndexAny(s, " \t\n\r"); i > 0 {
		return s[:i]
	}
	return s
}

var noxObjectFieldByName = map[string]objectFieldFunc{
	"CLASS": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseClassSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", objt.ID(), objt.Ind(), err)
		}
		objt.obj_class = uint32(v)
		return nil
	},
	"SUBCLASS": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseSubClassSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", objt.ID(), objt.Ind(), err)
		}
		objt.obj_subclass = uint32(v)
		return nil
	},
	"EXTENT": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := things.ParseExtent(str)
		if err != nil {
			return fmt.Errorf("cannot parse %q: %w", str, err)
		}
		s := &objt.shape
		*s = noxShape{}
		switch v := v.(type) {
		case nil:
			s.kind = shapeKindNone
		case things.Center:
			s.kind = shapeKindCenter
		case things.Circle:
			s.kind = shapeKindCircle
			s.circle.R = v.R
			s.circle.R2 = v.R * v.R
		case things.Box:
			s.kind = shapeKindBox
			s.box.W = v.W
			s.box.H = v.H
			s.box.Calc()
		default:
			return fmt.Errorf("unsupported shape type: %T", v)
		}
		return nil
	},
	"FLAGS": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseFlagSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", objt.ID(), objt.Ind(), err)
		}
		objt.obj_flags = uint32(v)
		return nil
	},
	"MATERIAL": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseMaterialSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", objt.ID(), objt.Ind(), err)
		}
		objt.material = uint16(v)
		return nil
	},
	"CARRYCAPACITY": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseUint(firstWord(str), 10, 16)
		if err != nil {
			return err
		}
		objt.carry_capacity = uint16(v)
		return nil
	},
	"LIGHTINTENSITY": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		return nil // server doesn't need that
	},
	"MASS": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseFloat(firstWord(str), 32)
		if err != nil {
			return err
		}
		objt.mass = float32(v)
		return nil
	},
	"SPEED": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.Atoi(firstWord(str))
		if err != nil {
			return err
		}
		fv := float32(float64(v) / 32)
		objt.float_33 = 0
		objt.speed = fv
		objt.speed_2 = fv
		return nil
	},
	"WEIGHT": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseUint(firstWord(str), 10, 8)
		if err != nil {
			return err
		}
		objt.weight = byte(v)
		return nil
	},
	"WORTH": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseUint(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		objt.worth = uint32(v)
		return nil
	},
	"EXPERIENCE": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseFloat(firstWord(str), 32)
		if err != nil {
			return err
		}
		objt.experience = float32(v)
		return nil
	},
	"ZSIZE": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		sub := strings.SplitN(str, " ", 2)
		if len(sub) != 2 {
			return errors.New("expected two values")
		}
		v1, err := strconv.Atoi(sub[0])
		if err != nil {
			return err
		}
		v2, err := strconv.Atoi(sub[1])
		if err != nil {
			return err
		}
		if v2 < v1 {
			v2 = v1
		}
		objt.zsize1 = float32(v1)
		objt.zsize2 = float32(v2)
		return nil
	},
	"HEALTH":      wrapObjectFieldFuncC(C.nox_xxx_parseHealth_535A60),
	"MENUICON":    wrapObjectFieldFuncC(C.nox_xxx_parseMenuIcon_535C30),
	"PRETTYIMAGE": wrapObjectFieldFuncC(C.nox_xxx_parsePrettyImage_0_535C80),
	"COLLIDE":     nox_xxx_parseCollide_536EC0,
	"DAMAGE":      nox_xxx_parseDamageFn_536C60,
	"DAMAGESOUND": nox_xxx_parseDamageSound_536CF0,
	"DIE":         nox_xxx_parseDieProc_536B80,
	"DROP":        nox_xxx_parseDrop_536A20,
	"INIT":        nox_xxx_parseInitProc_536930,
	"CREATE":      nox_xxx_parseCreateProc_536830,
	"PICKUP":      nox_xxx_parsePickup_536710,
	"UPDATE":      nox_xxx_parseUpdate_536620,
	"USE":         nox_xxx_parseUseFn_5363F0,
	"XFER":        nox_xxx_parseXFer_5360A0,
	"DRAW":        wrapObjectFieldFuncC(C.nox_xxx_parseDraw_535CD0),
}
