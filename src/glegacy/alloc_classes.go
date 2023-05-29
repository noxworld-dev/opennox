package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const DeadWord = 0xacacacac

type nox_alloc_class = [0]byte

// nox_new_alloc_class
func nox_new_alloc_class(name *char, size, cnt int) *nox_alloc_class {
	return (*nox_alloc_class)(alloc.NewClass(GoString(name), uintptr(size), cnt).UPtr())
}

// nox_new_alloc_class_dynamic
func nox_new_alloc_class_dynamic(name *char, size, cnt int) *nox_alloc_class {
	return (*nox_alloc_class)(alloc.NewDynamicClass(GoString(name), uintptr(size), cnt).UPtr())
}

// nox_free_alloc_class
func nox_free_alloc_class(p *nox_alloc_class) {
	alloc.AsClass(unsafe.Pointer(p)).Free()
}

// nox_alloc_class_new_obj_zero
func nox_alloc_class_new_obj_zero(p *nox_alloc_class) unsafe.Pointer {
	return alloc.AsClass(unsafe.Pointer(p)).NewObject()
}

// nox_alloc_class_free_obj_first
func nox_alloc_class_free_obj_first(p *nox_alloc_class, obj unsafe.Pointer) {
	alloc.AsClass(unsafe.Pointer(p)).FreeObjectFirst(obj)
}

// nox_alloc_class_free_all
func nox_alloc_class_free_all(p *nox_alloc_class) {
	alloc.AsClass(unsafe.Pointer(p)).FreeAllObjects()
}
