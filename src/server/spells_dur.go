package server

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

type DurSpellCreateFunc func(sp *DurSpell) int32
type DurSpellUpdateFunc func(sp *DurSpell) int32
type DurSpellDestroyFunc func(sp *DurSpell) int32

type DurSpell struct {
	ID      uint16                          // 0, 0
	_       uint16                          // 0, 2
	Spell   uint32                          // 1, 4
	Level   uint32                          // 2, 8
	Obj12   *Object                         // 3, 12
	Obj16   *Object                         // 4, 16
	Flag20  uint32                          // 5, 20
	Obj24   *Object                         // 6, 24
	Pos     types.Pointf                    // 7, 28
	Field36 uint32                          // 9, 36
	Field40 uint32                          // 10, 40
	Field44 uint32                          // 11, 44
	Obj48   *Object                         // 12, 48
	Pos2    types.Pointf                    // 13, 52
	Frame60 uint32                          // 15, 60
	Frame64 uint32                          // 16, 64
	Frame68 uint32                          // 17, 68
	Field72 int32                           // 18, 72
	Field76 uint32                          // 19, 76
	Field80 uint32                          // 20, 80
	Field84 uint32                          // 21, 84
	Flags88 uint32                          // 22, 88
	Create  ccall.Func[DurSpellCreateFunc]  // 23, 92
	Update  ccall.Func[DurSpellUpdateFunc]  // 24, 96
	Destroy ccall.Func[DurSpellDestroyFunc] // 25, 100
	Sub104  *DurSpell                       // 26, 104
	Sub108  *DurSpell                       // 27, 108
	Prev    *DurSpell                       // 28, 112
	Next    *DurSpell                       // 29, 116
}

func (sp *DurSpell) C() unsafe.Pointer {
	return unsafe.Pointer(sp)
}
