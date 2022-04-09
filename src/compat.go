package opennox

import "C"
import (
	"strconv"
	"unsafe"
)

//export nox_itoa
func nox_itoa(val C.int, s *C.char, radix C.int) *C.char {
	str := strconv.FormatInt(int64(val), int(radix))
	buf := unsafe.Slice((*byte)(unsafe.Pointer(s)), len(str)+1)
	i := copy(buf, str)
	buf[i] = 0
	return s
}

//export nox_utoa
func nox_utoa(val C.int, s *C.char, radix C.int) *C.char {
	str := strconv.FormatUint(uint64(val), int(radix))
	buf := unsafe.Slice((*byte)(unsafe.Pointer(s)), len(str)+1)
	i := copy(buf, str)
	buf[i] = 0
	return s
}
