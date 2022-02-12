package nox

/*
short sub_42C2E0(int a1);
*/
import "C"
import "nox/v1/common/object"

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
	if a1p.callXfer(nil) == 0 {
		return 0
	}
	nox_xxx_crypt_426D40()
	for it := a1p.FirstItem(); it != nil; it = it.NextItem() {
		nox_xxx_xfer_saveObj51DF90(it)
	}
	return 1
}
