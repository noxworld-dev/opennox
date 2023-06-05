package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_monstersAllBelongToHost_4DB6A0() {
	var (
		v0 *byte
		v1 *byte
		v2 int32
		v3 int32
		v4 int32
		v5 int32
	)
	v0 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(31)))
	v1 = v0
	if v0 != nil && *((*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*514))) != 0 {
		if *memmap.PtrUint32(0x5D4594, 1563124) == 0 {
			*memmap.PtrUint32(0x5D4594, 1563124) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SaveGameLocation")))
		}
		v2 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
		if v2 != 0 {
			for uint32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 4)))) != *memmap.PtrUint32(0x5D4594, 1563124) {
				v2 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(unsafe.Pointer(uintptr(v2)))))))
				if v2 == 0 {
					return
				}
			}
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 516))))
			if v3 != 0 {
				for {
					v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 512))))
					nox_xxx_unitSetOwner_4EC290((*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*514)))))), (*server.Object)(unsafe.Pointer(uintptr(v3))))
					if int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 8))))&2 != 0 {
						if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 748))) + 1440))))&0x80 != 0 {
							v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 12))))
							*((*uint8)(unsafe.Pointer(&v5))) = uint8(int8(v5 | 0x80))
							*(*uint32)(unsafe.Pointer(uintptr(v3 + 12))) = uint32(v5)
							nox_xxx_netReportAcquireCreature_4D91A0(int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v1), 2064)))), (*server.Object)(unsafe.Pointer(uintptr(v3))))
							nox_xxx_netMarkMinimapObject_417190(int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v1), 2064)))), (*server.Object)(unsafe.Pointer(uintptr(v3))), 1)
						}
					}
					v3 = v4
					if v4 == 0 {
						break
					}
				}
			}
			*(*uint32)(unsafe.Pointer(uintptr(v2 + 44))) = 0
			nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(unsafe.Pointer(uintptr(v2))))
		}
	}
}
