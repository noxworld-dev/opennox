package legacy

import "C"

var (
	Sub_4E8290 func(a1 byte, a2 uint16) int
)

//export sub_4E8290
func sub_4E8290(a1 C.char, a2 C.short) int {
	return Sub_4E8290(byte(a1), uint16(a2))
}
