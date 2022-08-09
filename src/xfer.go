package opennox

/*
#include "defs.h"
short sub_42C2E0(int a1);
int nox_xxx_mapReadWriteObjData_4F4530(nox_object_t* a1p, int a2);
int nox_xxx_xfer_4F3E30(unsigned short a1, nox_object_t* a2, int a3);
*/
import "C"
import (
	"fmt"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
)

//export nox_xxx_xfer_saveObj_51DF90
func nox_xxx_xfer_saveObj_51DF90(a1 *nox_object_t) C.int {
	return C.int(nox_xxx_xfer_saveObj51DF90(asObjectC(a1)))
}

func nox_xxx_xfer_saveObj51DF90(a1p *Object) int {
	if a1p.Flags().Has(object.FlagDestroyed) {
		return 1
	}
	a1 := uint16(C.sub_42C2E0(C.int(a1p.objTypeInd())))
	if a1 == 0 {
		return 0
	}
	cryptFileWriteU16(a1)
	nox_xxx_crypt_426C90()
	if err := a1p.callXfer(nil); err != nil {
		mapLog.Println("nox_xxx_xfer_saveObj51DF90:", err)
		return 0
	}
	nox_xxx_crypt_426D40()
	for it := a1p.FirstItem(); it != nil; it = it.NextItem() {
		nox_xxx_xfer_saveObj51DF90(it)
	}
	return 1
}

//export nox_xxx_XFerDefault_4F49A0
func nox_xxx_XFerDefault_4F49A0(a1p *nox_object_t, a2 unsafe.Pointer) C.int {
	if err := nox_xxx_XFerDefault4F49A0(asObjectC(a1p), a2); err != nil {
		mapLog.Println("nox_xxx_XFerDefault_4F49A0:", err)
		return 0
	}
	return 1
}

func nox_xxx_XFerDefault4F49A0(v1 *Object, a2 unsafe.Pointer) error {
	a1, _ := cryptFileReadWriteU16(60)
	if int16(a1) > 60 {
		return fmt.Errorf("default xfer: unexpected value 1: %d", a1)
	}
	v2 := v1.field_34
	if C.nox_xxx_mapReadWriteObjData_4F4530(v1.CObj(), C.int(a1)) == 0 {
		return fmt.Errorf("default xfer: nox_xxx_mapReadWriteObjData_4F4530 failed")
	}
	if v1.field_34 == 0 || nox_xxx_cryptGetXxx() != 1 {
		v1.field_34 = v2
		return nil
	}
	if C.nox_xxx_xfer_4F3E30(C.ushort(a1), v1.CObj(), C.int(v1.field_34)) == 0 {
		return fmt.Errorf("default xfer: nox_xxx_xfer_4F3E30 failed")
	}
	v1.field_34 = v2
	return nil
}
