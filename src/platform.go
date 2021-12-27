package nox

/*
#include <stdbool.h>
*/
import "C"
import (
	"time"

	"nox/v1/common/env"
	"nox/v1/common/platform"
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

//export nox_platform_time_seed
func nox_platform_time_seed() C.uint {
	return C.uint(platform.TimeSeed())
}

//export nox_platform_srand_time
func nox_platform_srand_time() {
	platform.RandSeedTime()
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

//export nox_platform_sleep
func nox_platform_sleep(ms C.uint) {
	if env.IsE2E() {
		platform.Sleep(time.Duration(ms))
		return
	}
	platform.Sleep(time.Duration(ms) * time.Millisecond)
}

//export nox_framerate_limit_416C70
func nox_framerate_limit_416C70(fps C.int) {
	if fps != 0 {
		nox_framerate_step_ticks = 1000 / uint64(fps)
	} else {
		nox_framerate_step_ticks = 0
	}
	ticks := platformTicks()
	nox_framerate_cur_ticks = ticks
	nox_framerate_next_ticks = ticks + nox_framerate_step_ticks
}

func nox_ticks_should_update_416CD0() C.bool {
	nox_framerate_cur_ticks = platformTicks()
	return nox_framerate_cur_ticks >= nox_framerate_next_ticks
}

func nox_ticks_until_next_416D00() int64 {
	ticks := platformTicks()
	if nox_framerate_next_ticks < ticks {
		return 0
	}
	diff := nox_framerate_next_ticks - ticks
	if diff > nox_framerate_next_ticks {
		return 0
	}
	return int64(diff)
}

var (
	nox_gameTicks_371764 uint64
	nox_gameFrame_371772 uint32
)

//export nox_ticks_reset_416D40
func nox_ticks_reset_416D40() {
	nox_gameTicks_371764 = platformTicks()
	nox_gameFrame_371772 = gameFrame()
	resetEngineFlag(NOX_ENGINE_FLAG_PAUSE)
}

func nox_ticks_check_416D70() bool {
	const mul = float32(0.033333335)

	df := int(gameFrame()) - int(nox_gameFrame_371772)
	dt := int64(platformTicks()) - int64(nox_gameTicks_371764)

	v2 := float64(df) * float64(mul)
	return float64(dt)*0.001 <= v2
}

func nox_ticks_maybe_sleep_416DD0() {
	const mul = float32(1000) / 30

	df := int(gameFrame()) - int(nox_gameFrame_371772)
	dt := int64(nox_gameTicks_371764) - int64(platformTicks())

	ms := int64(float64(df)*float64(mul)) + dt
	if ms > 0 {
		mainloopSleep(time.Duration(ms) * time.Millisecond)
	}
}
