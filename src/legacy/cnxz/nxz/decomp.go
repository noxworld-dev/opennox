package nxz

import "unsafe"

func sub57E8A0(this *uint32) {
	v1 := this
	sub57DD90(this)
	v2 := (*uint8)(calloc(548, 1))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*33)) = uint32(uintptr(unsafe.Pointer(v2)))
	memcpy(unsafe.Pointer(v2), unsafe.Pointer(&nxz_table_3[0]), int(548))
	memcpy(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*1))), unsafe.Pointer(&nxz_table_4[0]), int(unsafe.Sizeof([32]uint32{})))
}

func sub57E9A0(this *uint32) {
	v1 := this
	*this = uint32(uintptr(calloc(1, 0x10000)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*1)) = 0
	sub57E8A0((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*2)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*37)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*36)) = 0
}

func nxz_decompress_new() unsafe.Pointer {
	v0 := (*uint32)(calloc(1, 0x98))
	if v0 == nil {
		return nil
	}
	sub57E9A0(v0)
	return unsafe.Pointer(v0)
}

func sub57E910(this *unsafe.Pointer) {
	v1 := this
	free(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(this), unsafe.Sizeof(unsafe.Pointer(nil))*33)))
	sub57DDC0(v1)
}

func sub57EA00(this *unsafe.Pointer) {
	v1 := this
	v4 := this
	var v2 *unsafe.Pointer
	if v4 != nil {
		v2 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(unsafe.Pointer(nil))*2))
	}
	sub57E910(v2)
	free(*v1)
}

func nxz_decompress_free(lpMem unsafe.Pointer) {
	if lpMem != nil {
		sub57EA00((*unsafe.Pointer)(lpMem))
		free(lpMem)
	}
}
