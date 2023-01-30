package legacy

/*
#include "defs.h"
char nox_xxx_unitHasCollideOrUpdateFn_537610(nox_object_t* a1);
*/
import "C"
import "github.com/noxworld-dev/opennox/v1/server"

var (
	Nox_xxx_updateSprings_5113A0 func()
)

//export nox_xxx_updateSprings_5113A0
func nox_xxx_updateSprings_5113A0() { Nox_xxx_updateSprings_5113A0() }
func Nox_xxx_unitHasCollideOrUpdateFn_537610(a1 *server.Object) {
	C.nox_xxx_unitHasCollideOrUpdateFn_537610(asObjectC(a1))
}
