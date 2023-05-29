package legacy

/*
#include <stdint.h>
void nox_xxx_clientPlaySoundSpecial_452D80(int a1, int a2);
*/

import "github.com/noxworld-dev/opennox/v1/common/sound"

func Nox_xxx_clientPlaySoundSpecial_452D80(a1 sound.ID, a2 int) {
	nox_xxx_clientPlaySoundSpecial_452D80(int(a1), int(a2))
}
