package legacy

/*
#include <stdbool.h>
*/
import "C"
import "github.com/noxworld-dev/opennox-lib/platform"

var (
	PlatformTicks          func() uint64
	Nox_ticks_reset_416D40 func()
)

//export nox_platform_rand
func nox_platform_rand() int { return platform.RandInt() }

//export nox_platform_srand
func nox_platform_srand(seed C.uint) { platform.RandSeed(int64(seed)) }

//export nox_platform_get_ticks
func nox_platform_get_ticks() C.uint { return C.uint(PlatformTicks()) }

//export nox_ticks_reset_416D40
func nox_ticks_reset_416D40() { Nox_ticks_reset_416D40() }
