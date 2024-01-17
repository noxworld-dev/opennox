package client

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

var _ = [1]struct{}{}[48-unsafe.Sizeof(AnimationVector{})]

type AnimationVector struct {
	Field0 uint32                    // 0, 0
	Field4 [9]*noxrender.ImageHandle // 1, 4; [9][]noxrender.ImageHandle
	Size40 uint16                    // 10, 40
	Val42  uint16                    // 10, 42
	Kind44 uint32                    // 11, 44
}

var _ = [1]struct{}{}[772-unsafe.Sizeof(MonsterDrawData{})]

type MonsterDrawData struct {
	Field0 uint32              // 0, 0
	Anim   [16]AnimationVector // 1, 4
}
