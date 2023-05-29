package legacy

import noxflags "github.com/noxworld-dev/opennox/v1/common/flags"

type nox_engine_flag = noxflags.EngineFlag

// nox_common_setEngineFlag
func nox_common_setEngineFlag(flags nox_engine_flag) {
	noxflags.SetEngine(noxflags.EngineFlag(flags))
}

// nox_common_resetEngineFlag
func nox_common_resetEngineFlag(flags nox_engine_flag) {
	noxflags.UnsetEngine(noxflags.EngineFlag(flags))
}

// nox_common_getEngineFlag
func nox_common_getEngineFlag(flags nox_engine_flag) bool {
	return bool(noxflags.HasEngine(noxflags.EngineFlag(flags)))
}

// nox_common_randomInt_415FA0
func nox_common_randomInt_415FA0(min, max int32) int32 {
	return int32(GetServer().S().Rand.Logic.IntClamp(int(min), int(max)))
}

// nox_common_randomIntMinMax_415FF0
func nox_common_randomIntMinMax_415FF0(min, max int32, _ *byte, _ int32) int32 {
	return int32(GetServer().S().Rand.Other.Int(int(min), int(max)))
}

// nox_common_randomFloat_416030
func nox_common_randomFloat_416030(min, max float32) float64 {
	return float64(GetServer().S().Rand.Logic.FloatClamp(float64(min), float64(max)))
}

// nox_common_randomFloatXxx_416090
func nox_common_randomFloatXxx_416090(min, max float32) float64 {
	return float64(GetServer().S().Rand.Other.Float(float64(min), float64(max)))
}
