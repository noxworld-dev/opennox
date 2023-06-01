package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_monsterCast_540A30     func(cu *server.Object, spellInd int, a3p *server.Object)
	Nox_xxx_monsterCreateFn_54C480 func(u *server.Object)
)

// nox_xxx_monsterCast_540A30
func nox_xxx_monsterCast_540A30(cu *nox_object_t, spellInd int32, a3p *nox_object_t) {
	Nox_xxx_monsterCast_540A30(asObjectS(cu), int(spellInd), asObjectS(a3p))
}

// nox_xxx_monsterCreateFn_54C480
func nox_xxx_monsterCreateFn_54C480(u *nox_object_t) {
	Nox_xxx_monsterCreateFn_54C480(asObjectS(u))
}

func Nox_xxx_monsterDefByTT_517560(typ int) *server.MonsterDef {
	return (*server.MonsterDef)(nox_xxx_monsterDefByTT_517560(int32(typ)))
}

func Nox_xxx_monsterAutoSpells_54C0C0(u *server.Object) {
	nox_xxx_monsterAutoSpells_54C0C0(asObjectC(u))
}

func Nox_xxx_getDefaultSoundSet_424350(name string) unsafe.Pointer {
	return unsafe.Pointer(nox_xxx_getDefaultSoundSet_424350(internCStr(name)))
}
