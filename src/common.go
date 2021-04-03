package main

/*
extern unsigned int nox_common_engineFlags;
*/
import "C"
import (
	"encoding/binary"

	"nox/common/platform"
	"nox/common/prand"
)

func bool2int(v bool) int {
	if v {
		return 1
	}
	return 0
}

var (
	noxRndCounter1 = prand.New(0)
	noxRndCounter2 = prand.New(0)
)

type EngineFlags uint

const (
	NOX_ENGINE_FLAG_1                          = EngineFlags(1 << 0)
	NOX_ENGINE_FLAG_ENABLE_SHOW_EXTENTS        = EngineFlags(1 << 1)
	NOX_ENGINE_FLAG_3                          = EngineFlags(1 << 2)
	NOX_ENGINE_FLAG_ENABLE_SHOW_AI             = EngineFlags(1 << 3)
	NOX_ENGINE_FLAG_5                          = EngineFlags(1 << 4)
	NOX_ENGINE_FLAG_6                          = EngineFlags(1 << 5)
	NOX_ENGINE_FLAG_7                          = EngineFlags(1 << 6)
	NOX_ENGINE_FLAG_8                          = EngineFlags(1 << 7)
	NOX_ENGINE_FLAG_9                          = EngineFlags(1 << 8)
	NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE       = EngineFlags(1 << 9)
	NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE    = EngineFlags(1 << 10)
	NOX_ENGINE_FLAG_12                         = EngineFlags(1 << 11)
	NOX_ENGINE_FLAG_13                         = EngineFlags(1 << 12)
	NOX_ENGINE_FLAG_14                         = EngineFlags(1 << 13)
	NOX_ENGINE_FLAG_15                         = EngineFlags(1 << 14)
	NOX_ENGINE_FLAG_ENABLE_NET_DEBUG           = EngineFlags(1 << 15)
	NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING     = EngineFlags(1 << 16)
	NOX_ENGINE_FLAG_18                         = EngineFlags(1 << 17)
	NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING = EngineFlags(1 << 18)
	NOX_ENGINE_FLAG_20                         = EngineFlags(1 << 19)
	NOX_ENGINE_FLAG_DISABLE_FLOOR_RENDERING    = EngineFlags(1 << 20)
	NOX_ENGINE_FLAG_REPLAY_WRITE               = EngineFlags(1 << 21)
	NOX_ENGINE_FLAG_REPLAY_READ                = EngineFlags(1 << 22)
	NOX_ENGINE_FLAG_24                         = EngineFlags(1 << 23)
	NOX_ENGINE_FLAG_25                         = EngineFlags(1 << 24)
	NOX_ENGINE_FLAG_26                         = EngineFlags(1 << 25)
	NOX_ENGINE_FLAG_27                         = EngineFlags(1 << 26)
	NOX_ENGINE_FLAG_28                         = EngineFlags(1 << 27)
	NOX_ENGINE_FLAG_29                         = EngineFlags(1 << 28)
	NOX_ENGINE_FLAG_LOG_BAND                   = EngineFlags(1 << 29)
	NOX_ENGINE_FLAG_31                         = EngineFlags(1 << 30)
	NOX_ENGINE_FLAG_32                         = EngineFlags(1 << 31)
)

func (f EngineFlags) Has(v EngineFlags) bool {
	return f&v != 0
}

func getEngineFlag(f EngineFlags) bool {
	return EngineFlags(C.nox_common_engineFlags).Has(f)
}

func setEngineFlag(f EngineFlags) {
	C.nox_common_engineFlags |= C.uint(f)
}

func resetEngineFlag(f EngineFlags) {
	C.nox_common_engineFlags &= C.uint(^f)
}

//export nox_xxx_replayWriteRndCounter_415F30
func nox_xxx_replayWriteRndCounter_415F30(fd C.int) C.int {
	i := noxRndCounter1.Index()
	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:], uint32(i))
	return C.int(fdWrite(int(fd), buf[:]))
}

//export nox_xxx_replayReadeRndCounter_415F50
func nox_xxx_replayReadeRndCounter_415F50(fd C.int) C.int {
	var buf [4]byte
	n := fdRead(int(fd), buf[:])
	i := int(binary.LittleEndian.Uint32(buf[:]))
	noxRndCounter1.Reset(i)
	return C.int(n)
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
