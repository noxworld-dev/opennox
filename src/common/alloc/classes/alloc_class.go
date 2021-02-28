package classes

// TODO: move to the parent package once we get rid of C here

/*
// TODO: refactor and remove those flags
#cgo CFLAGS: -DNOX_CGO -DNOX_CGO_ALLOC -Wno-int-conversion -Wno-incompatible-pointer-types
#include <stdlib.h>
#include "alloc_class.h"
void  nox_free_alloc_class_f30(nox_alloc_class* p);
*/
import "C"

import (
	"fmt"
	"reflect"
	"time"
	"unsafe"

	"nox/common/alloc"
	"nox/common/platform"
)

//export alloc_nox_platform_get_ticks
func alloc_nox_platform_get_ticks() C.uint {
	return C.uint(platform.Ticks() / time.Millisecond)
}

func asByteSlice(p unsafe.Pointer, sz int) (out []byte) {
	*(*reflect.SliceHeader)(unsafe.Pointer(&out)) = reflect.SliceHeader{
		Data: uintptr(p),
		Len:  sz, Cap: sz,
	}
	return
}

var allocClasses = make(map[*C.nox_alloc_class]*allocClass)

func AsClass(p unsafe.Pointer) *AllocClass {
	return (*AllocClass)(p)
}

func asClass(p *C.nox_alloc_class) *AllocClass {
	return (*AllocClass)(p)
}

type AllocClass C.nox_alloc_class

func (c *AllocClass) C() *C.nox_alloc_class {
	return (*C.nox_alloc_class)(c)
}

func (c *AllocClass) UPtr() unsafe.Pointer {
	return unsafe.Pointer(c)
}

type allocClass struct {
	name string
	size int
	cnt  int
	c    *AllocClass
}

func (al *allocClass) String() string {
	return fmt.Sprintf("%s (Allocation Class)", al.name)
}

func New(name string, size, cnt int) *AllocClass {
	if name == "" {
		panic("empty name")
	}
	if size <= 0 {
		panic("size not specified")
	}
	if cnt <= 0 {
		panic("count not specified")
	}
	p := (*C.nox_alloc_class)(C.calloc(1, C.uint(unsafe.Sizeof(C.nox_alloc_class{}))))
	i := copy(asByteSlice(unsafe.Pointer(&p.name[0]), int(C.ALLOC_CLASS_NAME_MAX)), name)
	p.name[i] = 0

	isize := uintptr(size) + unsafe.Sizeof(C.nox_alloc_hdr{})
	arrp := C.calloc(C.uint(cnt), C.uint(isize))
	p.items = arrp

	for i := 0; i < cnt; i++ {
		h := (*C.nox_alloc_hdr)(unsafe.Pointer(uintptr(arrp) + isize*uintptr(i)))
		h.field_0 = 0
		h.field_1 = 0
		h.field_2 = p.field_24
		p.field_24 = h
		if i > 0 {
			p.field_25 = h
		}
	}
	p.size = C.int(size)
	p.cnt1 = C.int(cnt)
	p.cnt2 = C.int(cnt)
	p.ticks = 0
	p.field_26 = 0
	p.field_27 = 0
	p.field_31 = 0

	al := &allocClass{
		name: name,
		size: size,
		cnt:  cnt,
		c:    asClass(p),
	}
	allocClasses[p] = al
	return asClass(p)
}

func NewF30(name string, size, cnt int) *AllocClass {
	p := New(name, size, cnt)
	if p == nil {
		return nil
	}
	p.field_30 = 1
	return p
}

func (c *AllocClass) Free() {
	if c == nil {
		return
	}
	if c.field_30 != 0 {
		C.nox_free_alloc_class_f30(c.C())
	}
	if _, ok := allocClasses[c.C()]; ok {
		delete(allocClasses, c.C())
		C.free(unsafe.Pointer(c.items))
		C.free(unsafe.Pointer(c))
	}
}

func (c *AllocClass) NewObject() unsafe.Pointer {
	return C.nox_alloc_class_new_obj_go(c.C())
}

func (c *AllocClass) NewObjectZero() unsafe.Pointer {
	obj := c.NewObject()
	if obj == nil {
		return nil
	}
	alloc.Memset(obj, 0, uintptr(c.size))
	return obj
}

func (c *AllocClass) FreeObject(obj unsafe.Pointer) {
	C.nox_alloc_class_free_obj_go(c.C(), obj)
}

func (c *AllocClass) YYY4144D0() {
	C.nox_alloc_class_yyy_4144D0_go(c.C())
}

func (c *AllocClass) XXX414400(obj unsafe.Pointer) {
	C.nox_alloc_class_xxx_414400_go(c.C(), obj)
}
