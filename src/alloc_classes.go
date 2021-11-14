package nox

/*
#include "common/alloc/classes/alloc_class.h"
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/alloc/classes"
)

const DeadWord = 0xacacacac

//export nox_new_alloc_class
func nox_new_alloc_class(name *C.char, size, cnt C.int) *C.nox_alloc_class {
	return (*C.nox_alloc_class)(classes.New(C.GoString(name), uintptr(size), int(cnt)).UPtr())
}

//export nox_new_alloc_class_dynamic
func nox_new_alloc_class_dynamic(name *C.char, size, cnt C.int) *C.nox_alloc_class {
	return (*C.nox_alloc_class)(classes.NewDynamic(C.GoString(name), uintptr(size), int(cnt)).UPtr())
}

//export nox_free_alloc_class
func nox_free_alloc_class(p *C.nox_alloc_class) {
	classes.AsClass(unsafe.Pointer(p)).Free()
}

//export nox_alloc_class_new_obj
func nox_alloc_class_new_obj(p *C.nox_alloc_class) unsafe.Pointer {
	return classes.AsClass(unsafe.Pointer(p)).NewObject()
}

//export nox_alloc_class_new_obj_zero
func nox_alloc_class_new_obj_zero(p *C.nox_alloc_class) unsafe.Pointer {
	return classes.AsClass(unsafe.Pointer(p)).NewObjectZero()
}

//export nox_alloc_class_free_obj_first
func nox_alloc_class_free_obj_first(p *C.nox_alloc_class, obj unsafe.Pointer) {
	classes.AsClass(unsafe.Pointer(p)).FreeObject(obj)
}

//export nox_alloc_class_free_all
func nox_alloc_class_free_all(p *C.nox_alloc_class) {
	classes.AsClass(unsafe.Pointer(p)).YYY4144D0()
}

//export nox_alloc_class_free_obj_last
func nox_alloc_class_free_obj_last(p *C.nox_alloc_class, obj unsafe.Pointer) {
	classes.AsClass(unsafe.Pointer(p)).XXX414400(obj)
}
