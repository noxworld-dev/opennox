package nox

/*
#include "defs.h"
*/
import "C"
import (
	noxflags "nox/v1/common/flags"
	"nox/v1/common/platform"
	"nox/v1/common/prand"
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

//export nox_common_toggleEngineFlag
func nox_common_toggleEngineFlag(flags C.nox_engine_flag) {
	noxflags.ToggleEngine(noxflags.EngineFlag(flags))
}

//export nox_common_getEngineFlag
func nox_common_getEngineFlag(flags C.nox_engine_flag) C.bool {
	return C.bool(noxflags.HasEngine(noxflags.EngineFlag(flags)))
}

//export nox_common_initRandom_415F70
func nox_common_initRandom_415F70() {
	noxCommonInitRandom()
}

func noxCommonInitRandom() {
	v := platform.TimeSeed()
	noxRndCounter1.Reset(int(v))
	noxRndCounter2.Reset(int(v))
}

//export nox_common_randomInt_415FA0
func nox_common_randomInt_415FA0(min, max C.int) C.int {
	return C.int(noxRndCounter1.IntClamp(int(min), int(max)))
}

//export nox_common_randomIntMinMax_415FF0
func nox_common_randomIntMinMax_415FF0(min, max C.int, file *C.char, line C.int) C.int {
	return C.int(randomIntMinMax(int(min), int(max)))
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
