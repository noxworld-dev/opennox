package opennox

/*
#include "defs.h"
*/
import "C"
import (
	"github.com/noxworld-dev/opennox-lib/platform"
	"github.com/noxworld-dev/opennox-lib/prand"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

var (
	noxRndCounter1 = prand.New(0)
	noxRndCounter2 = prand.New(0)
)

//export nox_common_setEngineFlag
func nox_common_setEngineFlag(flags C.nox_engine_flag) {
	noxflags.SetEngine(noxflags.EngineFlag(flags))
}

//export nox_common_resetEngineFlag
func nox_common_resetEngineFlag(flags C.nox_engine_flag) {
	noxflags.UnsetEngine(noxflags.EngineFlag(flags))
}

//export nox_common_getEngineFlag
func nox_common_getEngineFlag(flags C.nox_engine_flag) C.bool {
	return C.bool(noxflags.HasEngine(noxflags.EngineFlag(flags)))
}

func noxCommonInitRandom() {
	v := platform.TimeSeed()
	noxRndCounter1.Reset(int(v))
	noxRndCounter2.Reset(int(v))
}

//export nox_common_randomInt_415FA0
func nox_common_randomInt_415FA0(min, max int) int {
	return noxRndCounter1.IntClamp(min, max)
}

//export nox_common_randomIntMinMax_415FF0
func nox_common_randomIntMinMax_415FF0(min, max int, file *C.char, line int) int {
	return randomIntMinMax(min, max)
}

func randomIntMinMax(min, max int) int {
	return noxRndCounter2.Int(min, max)
}

//export nox_common_randomFloat_416030
func nox_common_randomFloat_416030(min, max C.float) C.double {
	return C.double(noxRndCounter1.FloatClamp(float64(min), float64(max)))
}

//export nox_common_randomFloatXxx_416090
func nox_common_randomFloatXxx_416090(min, max C.float) C.double {
	return C.double(noxRndCounter2.Float(float64(min), float64(max)))
}
