package legacy

/*
#include "common/alloc/classes/alloc_class.h"
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const DeadWord = 0xacacacac

//export nox_new_alloc_class
func nox_new_alloc_class(name *C.char, size, cnt int) *C.nox_alloc_class {
	return (*C.nox_alloc_class)(alloc.NewClass(GoString(name), uintptr(size), cnt).UPtr())
}

//export nox_new_alloc_class_dynamic
func nox_new_alloc_class_dynamic(name *C.char, size, cnt int) *C.nox_alloc_class {
	return (*C.nox_alloc_class)(alloc.NewDynamicClass(GoString(name), uintptr(size), cnt).UPtr())
}

//export nox_free_alloc_class
func nox_free_alloc_class(p *C.nox_alloc_class) {
	alloc.AsClass(unsafe.Pointer(p)).Free()
}

//export nox_alloc_class_new_obj_zero
func nox_alloc_class_new_obj_zero(p *C.nox_alloc_class) unsafe.Pointer {
	return alloc.AsClass(unsafe.Pointer(p)).NewObject()
}

//export nox_alloc_class_free_obj_first
func nox_alloc_class_free_obj_first(p *C.nox_alloc_class, obj unsafe.Pointer) {
	alloc.AsClass(unsafe.Pointer(p)).FreeObjectFirst(obj)
}

//export nox_alloc_class_free_all
func nox_alloc_class_free_all(p *C.nox_alloc_class) {
	alloc.AsClass(unsafe.Pointer(p)).FreeAllObjects()
}

//export nox_alloc_class_free_obj_last
func nox_alloc_class_free_obj_last(p *C.nox_alloc_class, obj unsafe.Pointer) {
	alloc.AsClass(unsafe.Pointer(p)).FreeObjectLast(obj)
}

//export nox_alloc_class_reset_stats
func nox_alloc_class_reset_stats(p *C.nox_alloc_class) {
	alloc.AsClass(unsafe.Pointer(p)).ResetStats()
}

//export nox_alloc_class_obj_keep
func nox_alloc_class_obj_keep(p *C.nox_alloc_class, off int) {
	alloc.AsClass(unsafe.Pointer(p)).Keep(uintptr(off))
}
