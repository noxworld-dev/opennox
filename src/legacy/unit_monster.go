package legacy

/*
#include "defs.h"
*/
import "C"
import "github.com/noxworld-dev/opennox/v1/server"

var (
	Nox_xxx_monsterCast_540A30 func(cu *server.Object, spellInd int, a3p *server.Object)
)

//export nox_xxx_monsterCast_540A30
func nox_xxx_monsterCast_540A30(cu *nox_object_t, spellInd C.int, a3p *nox_object_t) {
	Nox_xxx_monsterCast_540A30(asObjectS(cu), int(spellInd), asObjectS(a3p))
}
