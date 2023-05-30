package legacy

import "unsafe"

func sub_980523(unit *nox_object_t) {
	if unit == nil {
		return
	}
	for it := (*nox_object_t)(unit.inv_first_item); it != nil; it = it.inv_next_item {
		if (it.ObjClass&0x2000000) != 0 && (it.ObjFlags&0x100) != 0 {
			if uint32(nox_xxx_unitArmorInventoryEquipFlags_415C70(it))&0x3000000 != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr((uint32(uintptr(unit.data_update))) + 276))) + 2500))) = uint32(uintptr(unsafe.Pointer(it)))
			}
		}
	}
}
func sub_9805EB(unit *nox_object_t) *nox_object_t {
	if unit == nil {
		return nil
	}
	for it := (*nox_object_t)(unit.inv_first_item); it != nil; it = it.inv_next_item {
		if (it.ObjClass&0x2000000) != 0 && it.ObjFlags == 16 {
			return it
		}
	}
	return nil
}
