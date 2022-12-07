package opennox

/*
#include <stdint.h>
void nox_xxx_clientPlaySoundSpecial_452D80(int a1, int a2);
*/
import "C"
import (
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func clientPlaySoundSpecial(snd sound.ID, a2 int) {
	C.nox_xxx_clientPlaySoundSpecial_452D80(C.int(snd), C.int(a2))
}
