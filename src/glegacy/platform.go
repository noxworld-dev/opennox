package legacy

import "github.com/noxworld-dev/opennox-lib/platform"

var (
	PlatformTicks          func() uint64
	Nox_ticks_reset_416D40 func()
)

// nox_platform_rand
func nox_platform_rand() int32 { return int32(platform.RandInt()) }

// nox_platform_srand
func nox_platform_srand(seed uint32) { platform.RandSeed(int64(seed)) }

// nox_platform_get_ticks
func nox_platform_get_ticks() uint32 { return uint32(PlatformTicks()) }

// nox_ticks_reset_416D40
func nox_ticks_reset_416D40() { Nox_ticks_reset_416D40() }
