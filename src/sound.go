package opennox

import (
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

func clientPlaySoundSpecial(snd sound.ID, a2 int) {
	legacy.Nox_xxx_clientPlaySoundSpecial_452D80(snd, a2)
}
