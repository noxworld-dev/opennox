package legacy

/*
#include "defs.h"
void nox_xxx_cancelAllSpells_4FEE90(nox_object_t* a1);
*/
import "C"
import "github.com/noxworld-dev/opennox/v1/server"

func Nox_xxx_cancelAllSpells_4FEE90(a1 *server.Object) {
	C.nox_xxx_cancelAllSpells_4FEE90(asObjectC(a1))
}
