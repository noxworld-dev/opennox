package nox

/*
#include "GAME1.h"
#include "GAME4_1.h"
*/
import "C"
import (
	"fmt"
	"sort"
	"unsafe"

	"nox/v1/common/types"
	"nox/v1/common/wall"
	"nox/v1/server/script"
)

func asWall(p unsafe.Pointer) *Wall {
	return (*Wall)(p)
}

func getWallAtGrid(pos types.Point) *Wall {
	p := C.nox_server_getWallAtGrid_410580(C.int(pos.X), C.int(pos.Y))
	return asWall(p)
}

func getWallAt(pos types.Pointf) *Wall {
	return getWallAtGrid(wall.PosToGrid(pos))
}

func getWallNear(pos types.Pointf) *Wall {
	if w := getWallAt(pos); w != nil {
		return w
	}
	// TODO: a better way
	pi := wall.PosToGrid(pos)
	try := []types.Point{
		{X: pi.X + 1, Y: pi.Y},
		{X: pi.X - 1, Y: pi.Y},
		{X: pi.X, Y: pi.Y + 1},
		{X: pi.X, Y: pi.Y - 1},
		{X: pi.X + 1, Y: pi.Y + 1},
		{X: pi.X + 1, Y: pi.Y - 1},
		{X: pi.X - 1, Y: pi.Y + 1},
		{X: pi.X - 1, Y: pi.Y - 1},
	}
	sort.Slice(try, func(i, j int) bool {
		p1, p2 := wall.GridToPos(try[i]), wall.GridToPos(try[j])
		d1 := p1.Sub(pos).Len()
		d2 := p2.Sub(pos).Len()
		return d1 < d2
	})
	for _, p := range try {
		if w := getWallAtGrid(p); w != nil {
			return w
		}
	}
	return nil
}

func getWallGroupByID(id string) *script.WallGroup {
	g := getMapGroupByID(id, 2)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Wall
	for wp := g.FirstItem(); wp != nil; wp = wp.Next() {
		p := wp.Payload()
		if wl := getWallAtGrid(types.Point{
			X: int(*(*C.int)(unsafe.Pointer(uintptr(p) + 0))),
			Y: int(*(*C.int)(unsafe.Pointer(uintptr(p) + 4))),
		}); wl != nil {
			list = append(list, wl)
		}
	}
	return script.NewWallGroup(id, list...)
}

type Wall [0]byte

func (w *Wall) C() unsafe.Pointer {
	return unsafe.Pointer(w)
}

func (w *Wall) field(dp uintptr) unsafe.Pointer {
	return unsafe.Pointer(uintptr(w.C()) + dp)
}

func (w *Wall) String() string {
	pos := w.GridPos()
	return fmt.Sprintf("Wall(%d, %d)", pos.X, pos.Y)
}

func (w *Wall) field1() byte {
	return *(*byte)(w.field(1))
}

func (w *Wall) field4() byte {
	return *(*byte)(w.field(4))
}

func (w *Wall) GridPos() types.Point {
	x := int(*(*byte)(w.field(5)))
	y := int(*(*byte)(w.field(6)))
	return types.Point{
		X: x,
		Y: y,
	}
}

func (w *Wall) Pos() types.Pointf {
	p := w.GridPos()
	return wall.GridToPos(p)
}

// IsEnabled checks if the wall is closed.
func (w *Wall) IsEnabled() bool {
	v2 := *(*unsafe.Pointer)(w.field(28))
	v3 := *(*byte)(unsafe.Pointer(uintptr(v2) + 21))
	return v3 == 1 || v3 == 2
}

// Enable or disable (close or open) the wall.
func (w *Wall) Enable(close bool) {
	if close {
		C.nox_xxx_wallClose_512070(C.int(uintptr(w.C())))
	} else {
		C.nox_xxx_wallOpen_511F80(C.int(uintptr(w.C())))
	}
}

// Destroy (break) the wall.
func (w *Wall) Destroy() {
	C.nox_xxx_wallPreDestroyByPtr_5122C0(C.int(uintptr(w.C())))
}
