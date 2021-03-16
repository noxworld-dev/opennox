package main

/*
#include <stdbool.h>
extern unsigned int nox_frame_xxx_2598000;
*/
import "C"
import (
	"time"

	"nox/common/memmap"
	"nox/common/platform"
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
	return uint64(platform.Ticks() / time.Millisecond)
}

//export nox_platform_sleep
func nox_platform_sleep(ms C.uint) {
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

//export nox_ticks_should_update_416CD0
func nox_ticks_should_update_416CD0() C.bool {
	nox_framerate_cur_ticks = platformTicks()
	return nox_framerate_cur_ticks >= nox_framerate_next_ticks
}

//export nox_ticks_until_next_416D00
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

//export nox_ticks_xxx_416D40
func nox_ticks_xxx_416D40() {
	*memmap.PtrUint64(0x5D4594, 371764) = platformTicks()
	*memmap.PtrUint32(0x5D4594, 371772) = uint32(C.nox_frame_xxx_2598000)
	resetEngineFlag(NOX_ENGINE_FLAG_32)
}

//export sub_416D70
func sub_416D70() C.bool {
	v2 := float64(int(C.nox_frame_xxx_2598000)-int(memmap.Uint32(0x5D4594, 371772))) * float64(memmap.Float32(0x587000, 54424))
	return float64(int64(platformTicks())-int64(memmap.Uint32(0x5D4594, 371764)))*0.001 <= v2
}

//export nox_ticks_maybe_sleep_416DD0
func nox_ticks_maybe_sleep_416DD0() {
	v1 := float64(int(C.nox_frame_xxx_2598000)-int(memmap.Uint32(0x5D4594, 371772))) * float64(memmap.Float32(0x587000, 54428))
	ms := int64(v1) + int64(memmap.Uint32(0x5D4594, 371764)) - int64(platformTicks())
	if ms > 0 {
		platform.Sleep(time.Duration(ms) * time.Millisecond)
	}
}
