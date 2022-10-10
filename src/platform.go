package opennox

/*
#include <stdbool.h>
*/
import "C"
import (
	"time"

	"github.com/noxworld-dev/opennox-lib/env"
	"github.com/noxworld-dev/opennox-lib/platform"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

var (
	nox_framerate_cur_ticks  uint64
	nox_framerate_next_ticks uint64
	nox_framerate_step_ticks uint64
)

//export nox_platform_rand
func nox_platform_rand() C.int {
	return C.int(platform.RandInt())
}

//export nox_platform_srand
func nox_platform_srand(seed C.uint) {
	platform.RandSeed(int64(seed))
}

//export nox_platform_get_ticks
func nox_platform_get_ticks() C.uint {
	return C.uint(platformTicks())
}

func platformTicks() uint64 {
	if env.IsE2E() {
		return uint64(platform.Ticks())
	}
	return uint64(platform.Ticks() / time.Millisecond)
}

func nox_framerate_limit_416C70(fps int) {
	if fps != 0 {
		nox_framerate_step_ticks = 1000 / uint64(fps)
	} else {
		nox_framerate_step_ticks = 0
	}
	ticks := platformTicks()
	nox_framerate_cur_ticks = ticks
	nox_framerate_next_ticks = ticks + nox_framerate_step_ticks
}

func nox_ticks_until_next_416D00() time.Duration {
	ticks := platformTicks()
	if nox_framerate_next_ticks < ticks {
		return 0
	}
	diff := nox_framerate_next_ticks - ticks
	if diff > nox_framerate_next_ticks {
		return 0
	}
	return time.Duration(diff) * time.Millisecond
}

var (
	nox_gameTicks_371764 uint64
	nox_gameFrame_371772 uint32
)

//export nox_ticks_reset_416D40
func nox_ticks_reset_416D40() {
	nox_gameTicks_371764 = platformTicks()
	nox_gameFrame_371772 = gameFrame()
	noxflags.UnsetEngine(noxflags.EnginePause)
}

func nox_ticks_getNext() time.Duration {
	const mul = 1000.0 / 30.0

	df := int(gameFrame()) - int(nox_gameFrame_371772)
	dt := int64(platformTicks()) - int64(nox_gameTicks_371764)

	ms := int64(float64(df)*mul) - dt
	return time.Duration(ms) * time.Millisecond
}
