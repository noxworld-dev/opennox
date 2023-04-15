package server

import (
	"fmt"
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"
	"github.com/noxworld-dev/opennox-lib/wall"
)

type Wall struct {
	Dir0       byte           // 0, 0
	Tile1      byte           // 0, 1
	Field2     byte           // 0, 2
	Field3     byte           // 0, 3
	Field4     byte           // 1, 4
	X5         byte           // 1, 5
	Y6         byte           // 1, 6
	Health7    byte           // 1, 7
	Field8     uint32         // 2, 8
	Field12    uint32         // 3, 12
	Next16     *Wall          // 4, 16
	Prev20     *Wall          // 5, 20
	SortNext24 *Wall          // 6, 24
	Data28     unsafe.Pointer // 7, 28
	Field32    uint32         // 8, 32
}

func (w *Wall) C() unsafe.Pointer {
	return unsafe.Pointer(w)
}

func (w *Wall) String() string {
	if w == nil {
		return "Wall(nil)"
	}
	pos := w.GridPos()
	return fmt.Sprintf("Wall(%d, %d)", pos.X, pos.Y)
}

func (w *Wall) WallScriptID() int {
	p := w.GridPos()
	return (p.X << 16) | p.Y
}

func (w *Wall) GridPos() image.Point {
	x := int(w.X5)
	y := int(w.Y6)
	return image.Point{
		X: x,
		Y: y,
	}
}

func (w *Wall) ScriptID() int {
	p := w.GridPos()
	return (p.X << 16) | p.Y
}

func (w *Wall) Pos() types.Pointf {
	p := w.GridPos()
	return wall.GridToPos(p)
}

// IsEnabled checks if the wall is closed.
func (w *Wall) IsEnabled() bool {
	if w == nil {
		return false
	}
	v3 := *(*byte)(unsafe.Add(w.Data28, 21))
	return v3 == 1 || v3 == 2
}
