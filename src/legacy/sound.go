package legacy

/*
#include <stdint.h>
#include "defs.h"
int sub_4133D0(nox_object_t* a1);
void nox_xxx_clientPlaySoundSpecial_452D80(int a1, int a2);
*/
import "C"
import (
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_soundPlayerDamageSound_5328B0  func(obj, obj2 *server.Object) int
	Nox_xxx_soundDefaultDamageSound_532E20 func(obj, obj2 *server.Object) int
)

func Nox_xxx_clientPlaySoundSpecial_452D80(a1 sound.ID, a2 int) {
	C.nox_xxx_clientPlaySoundSpecial_452D80(C.int(a1), C.int(a2))
}

func Sub_4133D0(a1 *server.Object) int {
	return int(C.sub_4133D0(asObjectC(a1)))
}

//export nox_xxx_soundPlayerDamageSound_5328B0
func nox_xxx_soundPlayerDamageSound_5328B0(a1, a2 *nox_object_t) int {
	return Nox_xxx_soundPlayerDamageSound_5328B0(asObjectS(a1), asObjectS(a2))
}

//export nox_xxx_soundDefaultDamageSound_532E20
func nox_xxx_soundDefaultDamageSound_532E20(a1, a2 *nox_object_t) int {
	return Nox_xxx_soundDefaultDamageSound_532E20(asObjectS(a1), asObjectS(a2))
}
