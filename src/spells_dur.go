package opennox

/*
#include <stdint.h>
extern void* dword_5d4594_1569728;
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	nox_alloc_spellDur_1569724 *alloc.Class
)

//export nox_xxx_newSpellDuration_4FE950
func nox_xxx_newSpellDuration_4FE950() unsafe.Pointer {
	p := nox_alloc_spellDur_1569724.NewObject()
	if p != nil {
		*memmap.PtrUint16(0x5D4594, 1569732)++
		*(*uint16)(p) = *memmap.PtrUint16(0x5D4594, 1569732)
	}
	return p
}

//export sub_4FE8A0
func sub_4FE8A0(a1 unsafe.Pointer) {
	if a1 == nil {
		nox_alloc_spellDur_1569724.FreeAllObjects()
		C.dword_5d4594_1569728 = nil
		return
	}
	var v3 unsafe.Pointer
	for v1 := C.dword_5d4594_1569728; v1 != nil; v1 = v3 {
		v2 := *(*unsafe.Pointer)(unsafe.Add(v1, 48))
		v3 = *(*unsafe.Pointer)(unsafe.Add(v1, 116))
		if v2 == nil || *(*uint8)(unsafe.Add(v2, 8))&0x4 == 0 {
			sub_4FE900(v1)
			sub_4FE980(v1)
		}
	}
}

//export sub_4FE980
func sub_4FE980(p unsafe.Pointer) {
	var v2 unsafe.Pointer
	for v1 := *(*unsafe.Pointer)(unsafe.Add(p, 108)); v1 != nil; v1 = v2 {
		v2 = *(*unsafe.Pointer)(unsafe.Add(v1, 116))
		sub_4FE980(v1)
	}
	var v4 unsafe.Pointer
	for v3 := *(*unsafe.Pointer)(unsafe.Add(p, 104)); v3 != nil; v3 = v4 {
		v4 = *(*unsafe.Pointer)(unsafe.Add(v3, 116))
		sub_4FE980(v3)
	}
	nox_alloc_spellDur_1569724.FreeObjectFirst(p)
}

//export sub_4FE900
func sub_4FE900(p unsafe.Pointer) {
	if v2 := *(*unsafe.Pointer)(unsafe.Add(p, 112)); v2 != nil {
		*(*unsafe.Pointer)(unsafe.Add(v2, 116)) = *(*unsafe.Pointer)(unsafe.Add(p, 116))
	} else {
		C.dword_5d4594_1569728 = *(*unsafe.Pointer)(unsafe.Add(p, 116))
	}
	if v3 := *(*unsafe.Pointer)(unsafe.Add(p, 116)); v3 != nil {
		*(*unsafe.Pointer)(unsafe.Add(v3, 112)) = *(*unsafe.Pointer)(unsafe.Add(p, 112))
	}
}
