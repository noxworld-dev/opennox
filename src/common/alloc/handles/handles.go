package handles

import (
	"fmt"
	"sync/atomic"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc/memguard"
)

var (
	data []byte
	base uintptr
	end  uintptr
	cur  uint32
	free func()
)

// Init the handles memory region.
func Init() {
	const size = 16 * 1024 * 1024
	data, free = memguard.New(size)
	base = uintptr(unsafe.Pointer(&data[0]))
	end = base + size
}

// New creates a new unique opaque handle for application to use.
func New() uintptr {
	if base == 0 {
		panic("call Init first")
	}
	h := base + uintptr(atomic.AddUint32(&cur, 1))
	if h >= end {
		panic("no more handles") // TODO
	}
	return h
}

// NewPtr creates a new unique opaque handle for application to use. It casts the value to a pointer.
func NewPtr() unsafe.Pointer {
	if base == 0 {
		panic("call Init first")
	}
	off := uintptr(atomic.AddUint32(&cur, 1))
	h := base + off
	if h >= end {
		panic("no more handles") // TODO
	}
	return unsafe.Pointer(&data[off])
}

// IsValid checks if a handle is valid.
func IsValid(h uintptr) bool {
	return h >= base && h < end
}

// AssertValid checks if a handle is valid and panic otherwise.
func AssertValid(h uintptr) {
	if h == 0 {
		panic("zero handle")
	}
	if h < base || h >= end {
		panic(fmt.Errorf("invalid handle: %v", h))
	}
}

// AssertValidPtr checks if a handle is valid and panic otherwise.
func AssertValidPtr(p unsafe.Pointer) {
	AssertValid(uintptr(p))
}

// Release all the handles and associated protected memory pages.
func Release() {
	if free != nil {
		free()
		free = nil
		data = nil
		base = 0
		end = 0
	}
}
