package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func nox_thing_maiden_draw(a1 *uint32, dr *nox_drawable) int32 {
	if !nox_common_gameFlags_check_40A5C0(0x200000) {
		var v9 *byte = (*byte)(unsafe.Pointer(nox_npc_by_id(int32(dr.Field_32))))
		if v9 == nil {
			return 1
		}
		var v10 int32 = 0
		var v11 *int32 = (*int32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v9), 8))))
		var v12 int32
		for {
			v12 = v10 + 1
			nox_draw_setMaterial_4341D0(v10+1, *v11)
			v10 = v12
			v11 = (*int32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
			if v12 >= 6 {
				break
			}
		}
		return nox_thing_monster_draw((*int32)(unsafe.Pointer(a1)), dr)
	}
	var v2 *nox_object_t = nox_server_getFirstObject_4DA790()
	if v2 == nil {
		return nox_thing_monster_draw((*int32)(unsafe.Pointer(a1)), dr)
	}
	var v3 int32
	for {
		v3 = int32(v2.Extent)
		if dr.Field_32 == uint32(v3) {
			break
		}
		v2 = nox_server_getNextObject_4DA7A0(v2)
		if v2 == nil {
			return nox_thing_monster_draw((*int32)(unsafe.Pointer(a1)), dr)
		}
	}
	var v5 int32 = int32(uintptr(v2.UpdateData))
	var v6 int32 = 0
	var v7 *uint8 = (*uint8)(unsafe.Pointer(uintptr(v5 + 2077)))
	var v8 int32
	for {
		*((*uint8)(unsafe.Pointer(&v3))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v7), 1))
		*((*uint8)(unsafe.Pointer(&v5))) = *((*uint8)(unsafe.Add(unsafe.Pointer(v7), -1)))
		v8 = v6 + 1
		*((*uint8)(unsafe.Pointer(&v6))) = *v7
		nox_draw_setMaterial_4340A0(v8, v5, v6, v3)
		v6 = v8
		v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 3))
		if v8 >= 6 {
			break
		}
	}
	return nox_thing_monster_draw((*int32)(unsafe.Pointer(a1)), dr)
}
func nox_things_maiden_draw_parse(obj *nox_thing, f *nox_memfile, attr_value *byte) bool {
	var result int32 = bool2int32(nox_things_monster_draw_parse(obj, f, attr_value))
	obj.DrawFunc = ccall.FuncAddr(nox_thing_maiden_draw)
	return result != 0
}
