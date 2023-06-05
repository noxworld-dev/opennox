package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_980523(unit *server.Object) {
	if unit == nil {
		return
	}
	for it := unit.InvFirstItem; it != nil; it = it.InvNextItem {
		if (it.ObjClass&0x2000000) != 0 && (it.ObjFlags&0x100) != 0 {
			if uint32(nox_xxx_unitArmorInventoryEquipFlags_415C70(it))&0x3000000 != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(unit.UpdateData)), 276)))), 2500)) = uint32(uintptr(unsafe.Pointer(it)))
			}
		}
	}
}
func sub_9805EB(unit *server.Object) *server.Object {
	if unit == nil {
		return nil
	}
	for it := unit.InvFirstItem; it != nil; it = it.InvNextItem {
		if (it.ObjClass&0x2000000) != 0 && it.ObjFlags == 16 {
			return it
		}
	}
	return nil
}
