//go:build safe

package legacy

import (
	"fmt"
	"os"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const cgoSafe = true

func init() {
	memmap.SetRuntimeChecks(true)
}

func checkPanicC(r any, ok *bool) {
	if r != nil {
		fmt.Fprintln(os.Stderr, r)
		*ok = false
	} else {
		*ok = true
	}
}

// mem_getPtr_go
func mem_getPtr_go(base, off uint, ok *bool) unsafe.Pointer {
	defer func() {
		checkPanicC(recover(), ok)
	}()
	return memmap.PtrOff(uintptr(base), uintptr(off))
}

// mem_getPtrSize_go
func mem_getPtrSize_go(base, off, size uint, ok *bool) unsafe.Pointer {
	defer func() {
		checkPanicC(recover(), ok)
	}()
	return memmap.PtrSizeOff(uintptr(base), uintptr(off), uintptr(size))
}

// nox_malloc
func nox_malloc(size uint) unsafe.Pointer {
	p, _ := alloc.Malloc(uintptr(size))
	return p
}

// nox_realloc
func nox_realloc(ptr unsafe.Pointer, size uint) unsafe.Pointer {
	return alloc.Realloc(ptr, uintptr(size))
}

// nox_calloc
func nox_calloc(num, size uint) unsafe.Pointer {
	p, _ := alloc.Calloc(int(num), uintptr(size))
	return p
}

// nox_free
func nox_free(ptr unsafe.Pointer) {
	alloc.Free(ptr)
}

// nox_memset
func nox_memset(ptr unsafe.Pointer, v int, size uint) unsafe.Pointer {
	return alloc.Memset(ptr, byte(v), uintptr(size))
}

// nox_memcpy_go
func nox_memcpy_go(dst, src unsafe.Pointer, size uint) unsafe.Pointer {
	return alloc.Memcpy(dst, src, uintptr(size))
}

// nox_memcmp_go
func nox_memcmp_go(ptr1, ptr2 unsafe.Pointer, size uint) int {
	return int(alloc.Memcmp(ptr1, ptr2, uintptr(size)))
}

// nox_strlen_go
func nox_strlen_go(ptr *char) uint {
	return uint(alloc.Strlen(unsafe.Pointer(ptr)))
}

// nox_strcpy_go
func nox_strcpy_go(dst, src *char) *char {
	return (*char)(alloc.Strcpy(unsafe.Pointer(dst), unsafe.Pointer(src)))
}

// nox_strcat_go
func nox_strcat_go(dst, src *char) *char {
	return (*char)(alloc.Strcat(unsafe.Pointer(dst), unsafe.Pointer(src)))
}

// nox_strcmp_go
func nox_strcmp_go(str1, str2 *char) int {
	return int(alloc.Strcmp(unsafe.Pointer(str1), unsafe.Pointer(str2)))
}
