package main

/*
#include <stdlib.h>
#include "proto.h"
*/
import "C"
import (
	"fmt"
	"unsafe"
)

var allocClasses = make(map[*C.nox_alloc_class]*allocClass)

type allocClass struct {
	name string
	size int
	cnt  int
	c    *C.nox_alloc_class
}

func (al *allocClass) String() string {
	return fmt.Sprintf("%s (Allocation Class)", al.name)
}

//export nox_new_alloc_class
func nox_new_alloc_class(name *C.char, size, cnt C.int) *C.nox_alloc_class {
	if name == nil {
		panic("empty name")
	}
	if size <= 0 {
		panic("size not specified")
	}
	if cnt <= 0 {
		panic("count not specified")
	}
	p := (*C.nox_alloc_class)(C.calloc(1, C.uint(unsafe.Sizeof(C.nox_alloc_class{}))))
	sname := C.GoString(name)
	i := copy(asByteSlice(unsafe.Pointer(&p.name[0]), 88), sname)
	p.name[i] = 0

	isize := uintptr(size) + unsafe.Sizeof(C.nox_alloc_hdr{})
	arrp := C.calloc(C.uint(cnt), C.uint(isize))
	p.items = arrp

	for i := 0; i < int(cnt); i++ {
		h := (*C.nox_alloc_hdr)(unsafe.Pointer(uintptr(arrp) + isize*uintptr(i)))
		h.field_0 = 0
		h.field_1 = 0
		h.field_2 = p.field_24
		p.field_24 = h
		if i > 0 {
			p.field_25 = h
		}
	}
	p.size = size
	p.cnt1 = cnt
	p.cnt2 = cnt
	p.ticks = 0
	p.field_26 = 0
	p.field_27 = 0
	p.field_31 = 0

	al := &allocClass{
		name: sname,
		size: int(size),
		cnt:  int(cnt),
		c:    p,
	}
	allocClasses[p] = al
	return p
}

//export nox_new_alloc_class_f30
func nox_new_alloc_class_f30(name *C.char, size, cnt C.int) *C.nox_alloc_class {
	p := nox_new_alloc_class(name, size, cnt)
	if p == nil {
		return nil
	}
	p.field_30 = 1
	return p
}

//export nox_free_alloc_class
func nox_free_alloc_class(p *C.nox_alloc_class) {
	if p == nil {
		return
	}
	if p.field_30 != 0 {
		C.nox_free_alloc_class_f30(p)
	}
	if _, ok := allocClasses[p]; ok {
		delete(allocClasses, p)
		C.free(unsafe.Pointer(p.items))
		C.free(unsafe.Pointer(p))
	}
}

//export nox_alloc_class_new_obj_zero
func nox_alloc_class_new_obj_zero(al *C.nox_alloc_class) unsafe.Pointer {
	obj := C.nox_alloc_class_new_obj(al)
	if obj == nil {
		return nil
	}
	C.memset(obj, 0, C.uint(al.size))
	return obj
}
