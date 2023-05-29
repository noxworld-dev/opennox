package legacy

import "unsafe"

func mem_getPtr(base uint32, off uint32) unsafe.Pointer {
	var (
		ok bool           = true
		p  unsafe.Pointer = mem_getPtr_go(base, off, &ok)
	)
	if !ok {
		panic("abort")
	}
	return p
}
func mem_getPtrSize(base uint32, off uint32, size uint32) unsafe.Pointer {
	var (
		ok bool           = true
		p  unsafe.Pointer = mem_getPtrSize_go(base, off, size, &ok)
	)
	if !ok {
		panic("abort")
	}
	return p
}
func nox_memcpy(dst unsafe.Pointer, src unsafe.Pointer, size uint32) unsafe.Pointer {
	return nox_memcpy_go(dst, src, size)
}
func nox_memcmp(ptr1 unsafe.Pointer, ptr2 unsafe.Pointer, size uint32) int32 {
	return nox_memcmp_go(ptr1, ptr2, size)
}
func nox_strlen(ptr *byte) uint32 {
	return nox_strlen_go(ptr)
}
func nox_strcpy(dst *byte, src *byte) *byte {
	return nox_strcpy_go(dst, src)
}
func nox_strcat(dst *byte, src *byte) *byte {
	return nox_strcat_go(dst, src)
}
func nox_strcmp(str1 *byte, str2 *byte) int32 {
	return nox_strcmp_go(str1, str2)
}
