//go:build safe
// +build safe

package nox

/*
#cgo CFLAGS: -g -O0 -DNOX_CGO_MEMMAP
#cgo CFLAGS: -Dmalloc=nox_malloc
#cgo CFLAGS: -Drealloc=nox_realloc
#cgo CFLAGS: -Dcalloc=nox_calloc
#cgo CFLAGS: -Dfree=nox_free
#cgo CFLAGS: -Dmemset=nox_memset
#cgo CFLAGS: -Dmemcpy=nox_memcpy
#cgo CFLAGS: -Dmemcmp=nox_memcmp
#cgo CFLAGS: -Dstrlen=nox_strlen
#cgo CFLAGS: -Dstrcpy=nox_strcpy
#cgo CFLAGS: -Dstrcat=nox_strcat
#cgo CFLAGS: -Dstrcmp=nox_strcmp
typedef unsigned int uintptr_t;
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/memmap"
)

func init() {
	memmap.SetRuntimeChecks(true)
}

//export mem_getPtr
func mem_getPtr(base, off C.uintptr_t) unsafe.Pointer {
	return memmap.PtrOff(uintptr(base), uintptr(off))
}

//export mem_getPtrSize
func mem_getPtrSize(base, off, size C.uintptr_t) unsafe.Pointer {
	return memmap.PtrSizeOff(uintptr(base), uintptr(off), uintptr(size))
}

//export nox_malloc
func nox_malloc(size C.uint) unsafe.Pointer {
	return alloc.Malloc(uintptr(size))
}

//export nox_realloc
func nox_realloc(ptr unsafe.Pointer, size C.uint) unsafe.Pointer {
	return alloc.Realloc(ptr, uintptr(size))
}

//export nox_calloc
func nox_calloc(num, size C.uint) unsafe.Pointer {
	return alloc.Calloc(uintptr(num), uintptr(size))
}

//export nox_free
func nox_free(ptr unsafe.Pointer) {
	alloc.Free(ptr)
}

//export nox_memset
func nox_memset(ptr unsafe.Pointer, v C.int, size C.uint) unsafe.Pointer {
	return alloc.Memset(ptr, byte(v), uintptr(size))
}

//export nox_memcpy_go
func nox_memcpy_go(dst, src unsafe.Pointer, size C.uint) unsafe.Pointer {
	return alloc.Memcpy(dst, src, uintptr(size))
}

//export nox_memcmp_go
func nox_memcmp_go(ptr1, ptr2 unsafe.Pointer, size C.uint) C.int {
	return C.int(alloc.Memcmp(ptr1, ptr2, uintptr(size)))
}

//export nox_strlen_go
func nox_strlen_go(ptr *C.char) C.uint {
	return C.uint(alloc.Strlen(unsafe.Pointer(ptr)))
}

//export nox_strcpy_go
func nox_strcpy_go(dst, src *C.char) *C.char {
	return (*C.char)(alloc.Strcpy(unsafe.Pointer(dst), unsafe.Pointer(src)))
}

//export nox_strcat_go
func nox_strcat_go(dst, src *C.char) *C.char {
	return (*C.char)(alloc.Strcat(unsafe.Pointer(dst), unsafe.Pointer(src)))
}

//export nox_strcmp_go
func nox_strcmp_go(str1, str2 *C.char) C.int {
	return C.int(alloc.Strcmp(unsafe.Pointer(str1), unsafe.Pointer(str2)))
}
