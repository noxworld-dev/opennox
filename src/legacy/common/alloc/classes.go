package alloc

import (
	"fmt"
	"os"
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/platform"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc/handles"
)

var (
	debugClasses = os.Getenv("NOX_DEBUG_ALLOC_CLASSES") == "true"
)

func AsClassT[T comparable](p unsafe.Pointer) ClassT[T] {
	return ClassT[T]{Class: AsClass(p)}
}

func NewClassT[T comparable](name string, typ T, cnt int) ClassT[T] {
	return ClassT[T]{Class: NewClass(name, unsafe.Sizeof(typ), cnt)}
}

func NewDynamicClassT[T comparable](name string, typ T, cnt int) ClassT[T] {
	return ClassT[T]{Class: NewDynamicClass(name, unsafe.Sizeof(typ), cnt)}
}

type ClassT[T comparable] struct {
	*Class
}

func (c ClassT[T]) NewObject() *T {
	return (*T)(c.Class.NewObject())
}

func (c ClassT[T]) FreeObjectFirst(p *T) {
	c.Class.FreeObjectFirst(unsafe.Pointer(p))
}

func (c ClassT[T]) FreeObjectLast(p *T) {
	c.Class.FreeObjectLast(unsafe.Pointer(p))
}

func (c ClassT[T]) Free() {
	c.Class.Free()
	c.Class = nil
}

const (
	DeadChar = 0xAC
	DeadWord = 0xACACACAC
)

func IsDead(p unsafe.Pointer) bool {
	return uintptr(p) == DeadWord
}

var allocClasses = make(map[unsafe.Pointer]*Class)

func AsClass(p unsafe.Pointer) *Class {
	if p == nil {
		return nil
	}
	return allocClasses[p]
}

func (al *Class) UPtr() unsafe.Pointer {
	if al == nil {
		return nil
	}
	if al.h == nil {
		al.h = handles.NewPtr()
		allocClasses[al.h] = al
	}
	return al.h
}

type object struct {
	al      *Class
	expires time.Duration
	next    *object
	prev    *object
	ptr     unsafe.Pointer
	free    func()
}

func (obj *object) Free() {
	if obj == nil || obj.ptr == nil {
		return
	}
	delete(obj.al.byPtr, obj.ptr)
	if obj.free != nil {
		obj.free()
		obj.free = nil
	}
	obj.ptr = nil
}

func (obj *object) memset(b byte) {
	var vals [][4]byte
	data := unsafe.Slice((*byte)(obj.ptr), obj.al.size)
	for _, off := range obj.al.keep {
		var v [4]byte
		copy(v[:], data[off:])
		vals = append(vals, v)
	}
	Memset(obj.ptr, b, obj.al.size)
	for i, off := range obj.al.keep {
		v := vals[i]
		copy(data[off:], v[:])
	}
}

func (obj *object) Zero() {
	obj.memset(0)
}

func (obj *object) Dead() {
	obj.memset(DeadChar)
}

type Class struct {
	h      unsafe.Pointer
	name   string
	size   uintptr
	cnt    int
	byPtr  map[unsafe.Pointer]*object
	lastGC time.Duration
	keep   []uintptr

	allocs int
	static struct {
		ptr  unsafe.Pointer
		free func()
		list
	}
	dynamic struct {
		enabled bool
		list
	}
	active struct {
		list
		max int
	}
}

func (al *Class) String() string {
	return fmt.Sprintf("%s (Allocation Class)", al.name)
}

func NewClass(name string, size uintptr, cnt int) *Class {
	if name == "" {
		panic("empty name")
	}
	if size <= 0 {
		panic("size not specified")
	}
	if cnt <= 0 {
		panic("count not specified")
	}
	al := &Class{
		name:   name,
		size:   size,
		cnt:    cnt,
		allocs: cnt,
		byPtr:  make(map[unsafe.Pointer]*object),
	}
	if debugClasses {
		log.Printf("alloc(%s): New(%d * [%d])", al.name, cnt, size)
	}

	// pre-allocate a fixed amount
	const hdr = 16
	al.static.ptr, al.static.free = Calloc(cnt, size+hdr)
	for i := 0; i < cnt; i++ {
		obj := &object{
			al:  al,
			ptr: unsafe.Add(al.static.ptr, (size+hdr)*uintptr(i)),
		}
		Memset(obj.ptr, DeadChar, hdr)
		obj.ptr = unsafe.Add(obj.ptr, hdr)
		al.byPtr[obj.ptr] = obj
		al.static.AddLast(obj)
	}
	return al
}

func NewDynamicClass(name string, size uintptr, cnt int) *Class {
	p := NewClass(name, size, cnt)
	if p == nil {
		return nil
	}
	p.dynamic.enabled = true
	return p
}

func (al *Class) Keep(off uintptr) {
	if off < 0 || off+4 > al.size {
		panic("invalid offset")
	}
	al.keep = append(al.keep, off)
}

func (al *Class) ResetStats() {
	al.active.max = al.active.n
}

func (al *Class) Free() {
	if al == nil {
		return
	}
	if debugClasses {
		log.Printf("alloc(%s): Free (%d active)", al.name, al.active.Count())
	}
	if al.dynamic.enabled {
		al.freeAllDynamic()
	}
	al.freeAllStatic()
	if al.h != nil {
		delete(allocClasses, al.h)
		al.h = nil
	}
	al.static.Clear()
	al.dynamic.Clear()
	al.active.Clear()
}

func (al *Class) freeAllStatic() {
	if al.static.ptr == nil {
		return
	}
	al.static.free()
	al.static.free = nil
	al.static.ptr = nil
	al.static.Clear()
}

func (al *Class) freeAllDynamic() {
	if al == nil {
		return
	}
	al.dynamic.Each(func(it *object) {
		it.Free()
	})
	al.active.Each(func(it *object) {
		if it.expires == 0 {
			return // skip static
		}
		al.active.remove(it)
		it.Free()
	})
	al.dynamic.Clear()
}

func (al *Class) gcDynamic() {
	now := platform.Ticks().Truncate(time.Millisecond)
	if now == al.lastGC {
		return
	}
	al.lastGC = now
	al.dynamic.Each(func(it *object) {
		if now <= it.expires {
			return
		}
		al.dynamic.remove(it)
		it.Free()
		if debugClasses {
			log.Printf("alloc(%s): GC(%p)", al.name, it.ptr)
		}
	})
}

func (al *Class) NewObject() unsafe.Pointer {
	if al == nil {
		return nil
	}
	obj := al.static.PopFirst()
	if obj == nil {
		obj = al.dynamic.PopFirst()
		if obj == nil {
			if !al.dynamic.enabled {
				return nil
			}
			// allocate dynamically
			obj = &object{
				al:      al,
				expires: time.Nanosecond,
			}
			obj.ptr, obj.free = Malloc(al.size)
			al.byPtr[obj.ptr] = obj
			al.allocs++
			if debugClasses {
				log.Printf("alloc(%s): NewObject(%p): dynamic alloc", al.name, obj.ptr)
			}
		} else {
			if debugClasses {
				log.Printf("alloc(%s): NewObject(%p): dynamic reuse", al.name, obj.ptr)
			}
		}
	} else {
		if debugClasses {
			log.Printf("alloc(%s): NewObject(%p): static reuse", al.name, obj.ptr)
		}
	}
	al.active.AddFirst(obj)
	al.gcDynamic()
	if al.active.n > al.active.max {
		al.active.max = al.active.n
	}
	obj.Zero()
	return obj.ptr
}

func (al *Class) FreeObjectFirst(p unsafe.Pointer) {
	if p == nil {
		return
	}
	obj := al.byPtr[p]
	if debugClasses {
		log.Printf("alloc(%s): FreeObjectFirst(%p) (dynamic: %v)", al.name, p, obj.expires != 0)
	}
	al.active.Remove(obj)
	if obj.expires != 0 {
		obj.expires = (platform.Ticks() + 10*time.Second).Truncate(time.Millisecond)
		al.dynamic.AddFirst(obj)
	} else {
		al.static.AddFirst(obj)
	}
	obj.Dead()
}

func (al *Class) FreeObjectLast(p unsafe.Pointer) {
	if p == nil {
		return
	}
	obj := al.byPtr[p]
	if debugClasses {
		log.Printf("alloc(%s): FreeObjectLast(%p) (dynamic: %v)", al.name, p, obj.expires != 0)
	}
	al.active.Remove(obj)
	if obj.expires != 0 {
		obj.expires = (platform.Ticks() + 10*time.Second).Truncate(time.Millisecond)
		al.dynamic.AddLast(obj)
	} else {
		al.static.AddLast(obj)
	}
	obj.Dead()
}

func (al *Class) FreeAllObjects() {
	if al == nil {
		return
	}
	if debugClasses {
		log.Printf("alloc(%s): FreeAllObjects (%d active)", al.name, al.active.Count())
	}
	if al.dynamic.enabled {
		al.freeAllDynamic()
	}
	al.active.Each(func(it *object) {
		al.active.remove(it)
		it.Dead()
		al.static.AddFirst(it)
	})
	al.dynamic.Clear()
	al.active.Clear()
}
