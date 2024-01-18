package client

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

var _ = [1]struct{}{}[48-unsafe.Sizeof(AnimationVector{})]

type AnimationVector struct {
	Field0 uint32                    // 0, 0
	Frames [9]*noxrender.ImageHandle // 1, 4; [9][]noxrender.ImageHandle
	Cnt40  uint16                    // 10, 40
	Val42  uint16                    // 10, 42
	Kind   uint32                    // 11, 44
}
