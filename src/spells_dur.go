package opennox

/*
#include <stdint.h>
extern void* dword_5d4594_1569728;
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	nox_alloc_spellDur_1569724 alloc.ClassT[noxDurSpell]
)

type noxDurSpell struct {
	id      uint16         // 0, 0
	_       uint16         // 0, 2
	spell   uint32         // 1, 4
	level   uint32         // 2, 8
	obj12   *nox_object_t  // 3, 12
	obj16   *nox_object_t  // 4, 16
	flag20  uint32         // 5, 20
	obj24   *nox_object_t  // 6, 24
	pos     types.Pointf   // 7, 28
	field36 uint32         // 9, 36
	field40 uint32         // 10, 40
	field44 uint32         // 11, 44
	obj48   *nox_object_t  // 12, 48
	pos2    types.Pointf   // 13, 52
	frame60 uint32         // 15, 60
	frame64 uint32         // 16, 64
	frame68 uint32         // 17, 68
	field72 int32          // 18, 72
	field76 uint32         // 19, 76
	field80 uint32         // 20, 80
	field84 uint32         // 21, 84
	flags88 uint32         // 22, 88
	create  unsafe.Pointer // 23, 92
	update  unsafe.Pointer // 24, 96
	destroy unsafe.Pointer // 25, 100
	sub104  *noxDurSpell   // 26, 104
	sub108  *noxDurSpell   // 27, 108
	prev    *noxDurSpell   // 28, 112
	next    *noxDurSpell   // 29, 116
}

func (sp *noxDurSpell) C() unsafe.Pointer {
	return unsafe.Pointer(sp)
}

//export nox_xxx_newSpellDuration_4FE950
func nox_xxx_newSpellDuration_4FE950() unsafe.Pointer {
	p := nox_alloc_spellDur_1569724.NewObject()
	if p != nil {
		*memmap.PtrUint16(0x5D4594, 1569732)++
		p.id = *memmap.PtrUint16(0x5D4594, 1569732)
	}
	return p.C()
}

//export sub_4FE8A0
func sub_4FE8A0(a1 int) {
	if a1 == 0 {
		nox_alloc_spellDur_1569724.FreeAllObjects()
		C.dword_5d4594_1569728 = nil
		return
	}
	var next *noxDurSpell
	for it := (*noxDurSpell)(C.dword_5d4594_1569728); it != nil; it = next {
		u := asUnitC(it.obj48)
		next = it.next
		if u == nil || !u.Class().Has(object.ClassPlayer) {
			sub_4FE900(it.C())
			sub_4FE980(it.C())
		}
	}
}

//export sub_4FE980
func sub_4FE980(a1 unsafe.Pointer) {
	sp := (*noxDurSpell)(a1)
	var next1 *noxDurSpell
	for it := sp.sub108; it != nil; it = next1 {
		next1 = it.next
		sub_4FE980(it.C())
	}
	var next2 *noxDurSpell
	for it := sp.sub104; it != nil; it = next2 {
		next2 = it.next
		sub_4FE980(it.C())
	}
	nox_alloc_spellDur_1569724.FreeObjectFirst(sp)
}

//export sub_4FE900
func sub_4FE900(a1 unsafe.Pointer) {
	sp := (*noxDurSpell)(a1)
	if prev := sp.prev; prev != nil {
		prev.next = sp.next
	} else {
		C.dword_5d4594_1569728 = sp.next.C()
	}
	if next := sp.next; next != nil {
		next.prev = sp.prev
	}
}
