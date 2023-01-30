package legacy

/*
#include "defs.h"
void nox_xxx_updateFallLogic_51B870(nox_object_t* a1);
char nox_xxx_unitHasCollideOrUpdateFn_537610(nox_object_t* a1p);
void nox_xxx_unitNeedSync_4E44F0(nox_object_t* a1);
void sub_51B810(nox_object_t* a1);
void sub_537770(nox_object_t* a1);
nox_object_t* nox_xxx_findObjectAtCursor_54AF40(nox_object_t* a1);
*/
import "C"
import "github.com/noxworld-dev/opennox/v1/server"

func Nox_xxx_findObjectAtCursor_54AF40(a1 *server.Object) *server.Object {
	return asObjectS(C.nox_xxx_findObjectAtCursor_54AF40(asObjectC(a1)))
}
func Nox_xxx_updateFallLogic_51B870(a1 *server.Object) {
	C.nox_xxx_updateFallLogic_51B870(asObjectC(a1))
}
func Sub_51B810(a1 *server.Object) {
	C.sub_51B810(asObjectC(a1))
}
func Sub_537770(a1 *server.Object) {
	C.sub_537770(asObjectC(a1))
}
