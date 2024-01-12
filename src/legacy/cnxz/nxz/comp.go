package nxz

import "unsafe"

func sub_57DF00(this *uint32) {
	v1 := this
	initCommon((*Common)(unsafe.Pointer(this)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*1)) = 4096
	v2 := (*uint8)(calloc(274, 4))
	v3 := v2
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*2)) = uint32(uintptr(unsafe.Pointer(v2)))
	memcpy(unsafe.Pointer(v3), unsafe.Pointer(&nxz_table_6[0]), int(unsafe.Sizeof([274]uint32{})))
}

func sub57DF70(this *unsafe.Pointer) {
	var v1 *unsafe.Pointer
	v1 = this
	free(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(this), unsafe.Sizeof(unsafe.Pointer(nil))*2)))
	freeCommon((*Common)(unsafe.Pointer(v1)))
}

func sub57D150(this *unsafe.Pointer) {
	v1 := this
	free(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(this), unsafe.Sizeof(unsafe.Pointer(nil))*5)))
	sub57DF70((*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(unsafe.Pointer(nil))*2)))
	free(*v1)
}

func nxz_compress_free(lpMem unsafe.Pointer) {
	if lpMem != nil {
		sub57D150((*unsafe.Pointer)(lpMem))
		free(lpMem)
	}
}
