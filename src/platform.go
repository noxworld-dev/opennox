package main

import "C"
import (
	"math/rand"
	"time"
)

var (
	start  = time.Now()
	random = seedRandomTime()
)

func timeSeed() int64 {
	return time.Now().UnixNano()
}

func seedRandomTime() *rand.Rand {
	return rand.New(rand.NewSource(timeSeed()))
}

//export nox_platform_rand
func nox_platform_rand() C.int {
	return C.int(random.Int())
}

//export nox_platform_srand
func nox_platform_srand(seed C.uint) {
	random = rand.New(rand.NewSource(int64(seed)))
}

//export nox_platform_time_seed
func nox_platform_time_seed() C.uint {
	return C.uint(timeSeed())
}

//export nox_platform_srand_time
func nox_platform_srand_time() {
	random = seedRandomTime()
}

//export nox_platform_get_ticks
func nox_platform_get_ticks() C.uint {
	return C.uint(time.Since(start) / time.Millisecond)
}

//export nox_platform_sleep
func nox_platform_sleep(ms C.uint) {
	time.Sleep(time.Duration(ms) * time.Millisecond)
}
