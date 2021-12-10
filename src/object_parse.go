package nox

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
	"io"
	"strings"
	"unsafe"
)

type objectFieldFunc func(objt *ObjectType, f *MemFile, str string, buf []byte) error

//export nox_thing_read_xxx_4E3220
func nox_thing_read_xxx_4E3220(a1 *C.nox_memfile, pbuf *C.char, ctyp *C.nox_objectType_t) C.int {
	f := asMemfile(a1)
	buf := unsafe.Slice((*byte)(unsafe.Pointer(pbuf)), 256*1024)
	typ := asObjectType(ctyp)
	for {
		sz := f.ReadU8()
		if sz == 0 {
			return 1
		}
		if _, err := io.ReadFull(f, buf[:sz]); err != nil {
			thingsLog.Printf("cannot read object type: %v", err)
			return 0
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
			thingsLog.Println(err)
			return 0
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

var noxObjectFieldByName = map[string]objectFieldFunc{
	"CARRYCAPACITY":  wrapObjectFieldFuncC(C.nox_xxx_parseCapacity_535B80),
	"CLASS":          wrapObjectFieldFuncC(C.nox_xxx_parseClass_535B00),
	"SUBCLASS":       wrapObjectFieldFuncC(C.nox_xxx_parseSubclass_535B30),
	"EXTENT":         wrapObjectFieldFuncC(C.nox_xxx_parseExtent_535990),
	"FLAGS":          wrapObjectFieldFuncC(C.nox_xxx_parseFlags_535AD0),
	"HEALTH":         wrapObjectFieldFuncC(C.nox_xxx_parseHealth_535A60),
	"LIGHTINTENSITY": wrapObjectFieldFuncC(C.nox_xxx_parseLightIntensity_535C20),
	"MASS":           wrapObjectFieldFuncC(C.nox_xxx_parseMass_535B60),
	"MENUICON":       wrapObjectFieldFuncC(C.nox_xxx_parseMenuIcon_535C30),
	"PRETTYIMAGE":    wrapObjectFieldFuncC(C.nox_xxx_parsePrettyImage_0_535C80),
	"SPEED":          wrapObjectFieldFuncC(C.nox_xxx_parseSpeed_535A20),
	"WEIGHT":         wrapObjectFieldFuncC(C.nox_xxx_parseWeight_535BB0),
	"MATERIAL":       wrapObjectFieldFuncC(C.nox_xxx_parseMaterial_535BE0),
	"EXPERIENCE":     wrapObjectFieldFuncC(C.nox_xxx_parseXP_535970),
	"COLLIDE":        wrapObjectFieldFuncC(C.nox_xxx_parseCollide_536EC0),
	"DAMAGE":         wrapObjectFieldFuncC(C.nox_xxx_parseDamageFn_536C60),
	"DAMAGESOUND":    wrapObjectFieldFuncC(C.nox_xxx_parseDamageSound_536CF0),
	"DIE":            wrapObjectFieldFuncC(C.nox_xxx_parseDieProc_536B80),
	"DROP":           wrapObjectFieldFuncC(C.nox_xxx_parseDrop_536A20),
	"INIT":           wrapObjectFieldFuncC(C.nox_xxx_parseInitProc_536930),
	"CREATE":         wrapObjectFieldFuncC(C.nox_xxx_parseCreateProc_536830),
	"PICKUP":         wrapObjectFieldFuncC(C.nox_xxx_parsePickup_536710),
	"UPDATE":         nox_xxx_parseUpdate_536620,
	"USE":            wrapObjectFieldFuncC(C.nox_xxx_parseUseFn_5363F0),
	"XFER":           wrapObjectFieldFuncC(C.nox_xxx_parseXFer_5360A0),
	"DRAW":           wrapObjectFieldFuncC(C.nox_xxx_parseDraw_535CD0),
	"ZSIZE":          wrapObjectFieldFuncC(C.nox_xxx_parseZSize_5359B0),
	"WORTH":          wrapObjectFieldFuncC(C.nox_xxx_parseWorth_535A00),
}
