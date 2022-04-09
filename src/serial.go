package opennox

import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/serial"
)

//export nox_xxx_regGetSerial_420120
func nox_xxx_regGetSerial_420120(dst *C.uchar) C.int {
	s, ok := serial.Serial()
	if !ok {
		return 0
	}
	out := unsafe.Slice((*byte)(unsafe.Pointer(dst)), len(s)+1)
	n := copy(out, s)
	out[n] = 0
	return 1
}
