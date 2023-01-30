package opennox

import (
	"time"

	"github.com/noxworld-dev/opennox-lib/env"
	"github.com/noxworld-dev/opennox-lib/platform"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

func platformTicks() uint64 {
	if env.IsE2E() {
		return uint64(platform.Ticks())
	}
	return uint64(platform.Ticks() / time.Millisecond)
}

var (
	nox_gameTicks_371764 uint64
	nox_gameFrame_371772 uint32
)

func nox_ticks_reset_416D40() {
	nox_gameTicks_371764 = platformTicks()
	nox_gameFrame_371772 = noxServer.Frame()
	noxflags.UnsetEngine(noxflags.EnginePause)
}

func nox_ticks_getNext() time.Duration {
	const mul = 1000.0 / 30.0

	df := int(noxServer.Frame()) - int(nox_gameFrame_371772)
	dt := int64(platformTicks()) - int64(nox_gameTicks_371764)

	ms := int64(float64(df)*mul) - dt
	return time.Duration(ms) * time.Millisecond
}
