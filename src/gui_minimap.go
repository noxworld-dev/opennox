package opennox

import (
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func sub_473670() int {
	return int(memmap.Uint8(0x5D4594, 1096424) & 1)
}

func nox_client_toggleMap_473610() int {
	if nox_xxx_guiCursor_477600() != 1 {
		if memmap.Uint8(0x5D4594, 1096424)&1 != 0 {
			clientPlaySoundSpecial(sound.SoundMapClose, 100)
			*memmap.PtrUint32(0x5D4594, 1096424) &= 0xFFFFFFFE
		} else {
			clientPlaySoundSpecial(sound.SoundMapOpen, 100)
			*memmap.PtrUint32(0x5D4594, 1096424) |= 0x1
		}
		noxClient.GUI.ValYYY = 1
		return int(*memmap.PtrUint32(0x5D4594, 1096424))
	}
	return 0
}
