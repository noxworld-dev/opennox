package client

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/server"
)

var _ = [1]struct{}{}[40-unsafe.Sizeof(PlayerEquipAnimation{})]

type PlayerEquipAnimation struct {
	Size   uint32                    // 0, 0
	Frames [9]*noxrender.ImageHandle // 1, 4; [1][]noxrender.ImageHandle
}

var _ = [1]struct{}{}[264-unsafe.Sizeof(PlayerAnimation{})]

type PlayerAnimation struct {
	Base   AnimationVector                               // 0, 0
	Naked  *PlayerEquipAnimation                         // 12, 48
	Armor  [server.PlayerArmorCnt]*PlayerEquipAnimation  // 13, 52
	Weapon [server.PlayerWeaponCnt]*PlayerEquipAnimation // 39, 156
}

func (a *PlayerAnimation) FramesSlice(ptr *noxrender.ImageHandle) []noxrender.ImageHandle {
	return unsafe.Slice(ptr, a.Base.Cnt40)
}

var _ = [1]struct{}{}[14524-unsafe.Sizeof(PlayerDrawData{})]

type PlayerDrawData struct {
	Size uint32                                // 0, 0
	Anim [server.PlayerAnimCnt]PlayerAnimation // 1, 4
}
