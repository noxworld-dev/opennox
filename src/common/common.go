package common

// #cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
// #cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
// #cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
// #cgo CFLAGS: -DNOX_CGO
import "C"
import (
	"encoding/binary"
	"syscall"

	_ "nox/common/ability"
	_ "nox/common/gamemech"
	_ "nox/common/magic"
	_ "nox/common/object"
	_ "nox/common/system"
	_ "nox/common/telnet"
	_ "nox/common/wolapi"
	_ "nox/common/xfer"

	"nox/common/platform"
	"nox/common/prand"
)

var (
	noxRndCounter1 = prand.New(0)
	noxRndCounter2 = prand.New(0)
)

//export nox_xxx_replayWriteRndCounter_415F30
func nox_xxx_replayWriteRndCounter_415F30(fd C.int) C.int {
	i := noxRndCounter1.Index()
	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:], uint32(i))
	n, _ := syscall.Write(int(fd), buf[:])
	return C.int(n)
}

//export nox_xxx_replayReadeRndCounter_415F50
func nox_xxx_replayReadeRndCounter_415F50(fd C.int) C.int {
	var buf [4]byte
	n, _ := syscall.Read(int(fd), buf[:])
	i := int(binary.LittleEndian.Uint32(buf[:]))
	noxRndCounter1.Reset(i)
	return C.int(n)
}

//export nox_common_initRandom_415F70
func nox_common_initRandom_415F70() {
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
	return C.int(noxRndCounter2.Int(int(min), int(max)))
}

//export nox_common_randomFloat_416030
func nox_common_randomFloat_416030(min, max C.float) C.double {
	return C.double(noxRndCounter1.FloatClamp(float64(min), float64(max)))
}

//export nox_common_randomFloatXxx_416090
func nox_common_randomFloatXxx_416090(min, max C.float) C.double {
	return C.double(noxRndCounter2.Float(float64(min), float64(max)))
}
