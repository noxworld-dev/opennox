package main

/*
#include "mutexes.h"
*/
import "C"
import (
	"sync"
	"sync/atomic"
	"unsafe"
)

var mutexes struct {
	last uint32
	byID sync.Map
}

func asMutex(p unsafe.Pointer) *sync.Mutex {
	m := (*C.nox_mutex_t)(p)
	id := uint32(m.p)
	v, ok := mutexes.byID.Load(id)
	if !ok {
		panic("no such mutex")
	}
	return v.(*sync.Mutex)
}

//export nox_mutex_init
func nox_mutex_init(m *C.nox_mutex_t) {
	mu := new(sync.Mutex)
	id := atomic.AddUint32(&mutexes.last, 1)
	mutexes.byID.Store(id, mu)
	m.p = C.uint(id)
}

//export nox_mutex_free
func nox_mutex_free(m *C.nox_mutex_t) {
	id := uint32(m.p)
	mutexes.byID.Delete(id)
}

//export nox_mutex_lock
func nox_mutex_lock(m *C.nox_mutex_t) {
	id := uint32(m.p)
	v, ok := mutexes.byID.Load(id)
	if !ok {
		panic("no such mutex")
	}
	v.(*sync.Mutex).Lock()
}

//export nox_mutex_unlock
func nox_mutex_unlock(m *C.nox_mutex_t) {
	id := uint32(m.p)
	v, ok := mutexes.byID.Load(id)
	if !ok {
		panic("no such mutex")
	}
	v.(*sync.Mutex).Unlock()
}
