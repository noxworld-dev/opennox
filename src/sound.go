package opennox

import (
	"github.com/noxworld-dev/opennox-lib/object"

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func clientPlaySoundSpecial(snd sound.ID, a2 int) {
	legacy.Nox_xxx_clientPlaySoundSpecial_452D80(snd, a2)
}

func Nox_xxx_soundPlayerDamageSound_5328B0(obj1, obj2 *server.Object) int {
	s := obj1.Server()
	mat := uint16(1)
	if obj2 == nil {
		return 1
	}
	for it := obj1.InvFirstItem; it != nil; it = it.InvNextItem {
		if it.Class().Has(object.ClassArmor) && it.SubClass().AsArmor().Has(object.ArmorBreastplate) {
			if legacy.Sub_4133D0(it) != 0 {
				mat = 0x2000
			} else if int32(it.Material) > int32(mat) {
				mat = it.Material
			}
		}
	}
	s.Sub_532930(obj1, mat, obj2.Material)
	return 1
}
