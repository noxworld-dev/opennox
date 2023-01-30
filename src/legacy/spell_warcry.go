package legacy

/*
#include "GAME4.h"
#include "GAME4_3.h"
*/
import "C"
import "github.com/noxworld-dev/opennox/v1/server"

func Nox_xxx_spell_4FE680(a1 *server.Object, a2 float32) {
	C.nox_xxx_spell_4FE680(asObjectC(a1), C.float(a2))
}
func Nox_xxx_mapCheck_537110(a1 *server.Object, a2 *server.Object) int {
	return int(C.nox_xxx_mapCheck_537110(asObjectC(a1), asObjectC(a2)))
}
