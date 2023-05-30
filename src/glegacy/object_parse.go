package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

var _ = [1]struct{}{}[16-unsafe.Sizeof(server.MonsterAnim{})]

// nox_xxx_animPlayerGetFrameRange_4F9F90
func nox_xxx_animPlayerGetFrameRange_4F9F90(a1 int32, a2, a3 *int32) {
	v1, v2 := GetServer().S().PlayerAnimFrames(int(a1))
	if a2 != nil {
		*a2 = int32(v1)
	}
	if a3 != nil {
		*a3 = int32(v2)
	}
}
