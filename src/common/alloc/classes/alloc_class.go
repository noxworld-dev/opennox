package classes

// TODO: move to the parent package once we get rid of C here

/*
// TODO: refactor and remove those flags
#cgo CFLAGS: -DNOX_CGO -DNOX_CGO_ALLOC -Wno-int-conversion -Wno-incompatible-pointer-types
#include <stdlib.h>
#include "alloc_class.h"
void  nox_free_alloc_class_dynamic(nox_alloc_class* p);
*/
import "C"

import (
	"fmt"
	"time"
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/platform"
)

//export alloc_nox_platform_get_ticks
func alloc_nox_platform_get_ticks() C.uint {
	return C.uint(platform.Ticks() / time.Millisecond)
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
	name      string
	size      uintptr
	cnt       int
	c         *AllocClass
	free      func()
	itemsFree func()
}

func (al *allocClass) String() string {
	return fmt.Sprintf("%s (Allocation Class)", al.name)
}

func New(name string, size uintptr, cnt int) *AllocClass {
	if name == "" {
		panic("empty name")
	}
	if size <= 0 {
		panic("size not specified")
	}
	if cnt <= 0 {
		panic("count not specified")
	}
	ptr, free := alloc.Malloc(unsafe.Sizeof(C.nox_alloc_class{}))
	p := (*C.nox_alloc_class)(ptr)
	i := copy(unsafe.Slice((*byte)(unsafe.Pointer(&p.name[0])), int(C.ALLOC_CLASS_NAME_MAX)), name)
	p.name[i] = 0

	isize := size + unsafe.Sizeof(C.nox_alloc_hdr{})
	arrp, arrFree := alloc.Calloc(cnt, isize)
	p.items = arrp

	for i := 0; i < cnt; i++ {
		h := (*C.nox_alloc_hdr)(unsafe.Pointer(uintptr(arrp) + isize*uintptr(i)))
		h.expires = 0
		h.next = p.first_free
		p.first_free = h
		if i > 0 {
			p.last_free = h
		}
	}
	p.size = C.int(size)
	p.cnt1 = C.int(cnt)
	p.cnt2 = C.int(cnt)
	p.ticks = 0
	p.first_free_add = nil
	p.last_free_add = nil
	p.field_31 = 0

	al := &allocClass{
		name:      name,
		size:      size,
		cnt:       cnt,
		c:         asClass(p),
		free:      free,
		itemsFree: arrFree,
	}
	allocClasses[p] = al
	return asClass(p)
}

func NewDynamic(name string, size uintptr, cnt int) *AllocClass {
	p := New(name, size, cnt)
	if p == nil {
		return nil
	}
	p.can_grow = 1
	return p
}

func (c *AllocClass) Free() {
	if c == nil {
		return
	}
	if c.can_grow != 0 {
		C.nox_free_alloc_class_dynamic(c.C())
	}
	if al, ok := allocClasses[c.C()]; ok {
		delete(allocClasses, c.C())
		al.itemsFree()
		al.free()
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
