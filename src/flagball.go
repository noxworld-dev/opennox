package opennox

import "github.com/noxworld-dev/opennox/v1/common/memmap"

func sub_4E8290(a1 byte, a2 uint16) int {
	*memmap.PtrUint8(0x5D4594, 1567736) = a1
	*memmap.PtrUint16(0x5D4594, 1567738) = a2
	return nox_xxx_netSendBallStatus_4D95F0(255, a1, a2)
}
