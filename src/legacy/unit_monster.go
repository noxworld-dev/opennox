package legacy

/*
#include "defs.h"
void* nox_xxx_monsterDefByTT_517560(int a1);
const char** nox_xxx_getDefaultSoundSet_424350(const char* a1);
short nox_xxx_monsterAutoSpells_54C0C0(nox_object_t* a1p);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_monsterCreateFn_54C480 func(u *server.Object)
)

//export nox_xxx_monsterCast_540A30
func nox_xxx_monsterCast_540A30(cu *nox_object_t, spellInd C.int, a3p *nox_object_t) {
	asObjectS(cu).MonsterCast(spell.ID(spellInd), asObjectS(a3p))
}

//export nox_xxx_monsterCreateFn_54C480
func nox_xxx_monsterCreateFn_54C480(u *nox_object_t) {
	Nox_xxx_monsterCreateFn_54C480(asObjectS(u))
}

func Nox_xxx_monsterDefByTT_517560(typ int) *server.MonsterDef {
	return (*server.MonsterDef)(C.nox_xxx_monsterDefByTT_517560(C.int(typ)))
}

func Nox_xxx_monsterAutoSpells_54C0C0(u *server.Object) {
	C.nox_xxx_monsterAutoSpells_54C0C0(asObjectC(u))
}

func Nox_xxx_getDefaultSoundSet_424350(name string) unsafe.Pointer {
	return unsafe.Pointer(C.nox_xxx_getDefaultSoundSet_424350(internCStr(name)))
}
