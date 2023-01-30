package legacy

/*
#include "defs.h"
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

var _ = [1]struct{}{}[16-unsafe.Sizeof(server.MonsterAnim{})]

//export nox_xxx_animPlayerGetFrameRange_4F9F90
func nox_xxx_animPlayerGetFrameRange_4F9F90(a1 int, a2, a3 *C.int) {
	v1, v2 := GetServer().S().PlayerAnimFrames(a1)
	if a2 != nil {
		*a2 = C.int(v1)
	}
	if a3 != nil {
		*a3 = C.int(v2)
	}
}
