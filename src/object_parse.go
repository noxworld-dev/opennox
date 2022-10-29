package opennox

/*
#include "defs.h"
*/
import "C"
import (
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func firstWord(s string) string {
	if i := strings.IndexAny(s, " \t\n\r"); i > 0 {
		return s[:i]
	}
	return s
}

var _ = [1]struct{}{}[16-unsafe.Sizeof(server.MonsterAnim{})]

func playerAnimGetFrameRange(i int) (_, _ int) {
	return noxServer.PlayerAnimFrames(i)
}

//export nox_xxx_animPlayerGetFrameRange_4F9F90
func nox_xxx_animPlayerGetFrameRange_4F9F90(a1 int, a2, a3 *C.int) {
	v1, v2 := playerAnimGetFrameRange(a1)
	if a2 != nil {
		*a2 = C.int(v1)
	}
	if a3 != nil {
		*a3 = C.int(v2)
	}
}
