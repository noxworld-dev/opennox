package main

import "C"
import (
	"time"

	"nox/common/platform"
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
	return C.uint(platform.Ticks() / time.Millisecond)
}

//export nox_platform_sleep
func nox_platform_sleep(ms C.uint) {
	platform.Sleep(time.Duration(ms) * time.Millisecond)
}
