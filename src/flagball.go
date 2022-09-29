package opennox

import "C"

import "github.com/noxworld-dev/opennox/v1/common/memmap"

//export sub_4E8290
func sub_4E8290(a1 C.char, a2 C.short) C.int {
	*memmap.PtrUint8(0x5D4594, 1567736) = byte(a1)
	*memmap.PtrUint16(0x5D4594, 1567738) = uint16(a2)
	return C.int(nox_xxx_netSendBallStatus_4D95F0(255, byte(a1), uint16(a2)))
}
