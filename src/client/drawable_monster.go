package client

import (
	"unsafe"
)

var _ = [1]struct{}{}[772-unsafe.Sizeof(MonsterDrawData{})]

type MonsterDrawData struct {
	Size uint32              // 0, 0
	Anim [16]AnimationVector // 1, 4
}
