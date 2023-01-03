package opennox

/*
#include "GAME1.h"
#include "GAME4_1.h"
extern void* dword_5d4594_251560;
*/
import "C"
import (
	"fmt"
	"image"
	"sort"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"
	"github.com/noxworld-dev/opennox-lib/wall"
)

func asWall(p unsafe.Pointer) *Wall {
	return (*Wall)(p)
}

//export nox_server_getWallAtGrid_410580
func nox_server_getWallAtGrid_410580(x, y C.int) unsafe.Pointer {
	return noxServer.getWallAtGrid(image.Pt(int(x), int(y))).C()
}

//export nox_xxx_wall_4105E0
func nox_xxx_wall_4105E0(x, y C.int) unsafe.Pointer {
	return noxServer.getWallAtGrid2(image.Pt(int(x), int(y))).C()
}

func (s *Server) nox_xxx_wallTileByName_410D60(name string) byte {
	str := CString(name)
	defer StrFree(str)
	return byte(C.nox_xxx_wallTileByName_410D60(str))
}

func (s *Server) getWallAtGrid(pos image.Point) *Wall { // nox_server_getWallAtGrid_410580
	if (byte(pos.X)+byte(pos.Y))&0x1 != 0 {
		return nil
	}
	ind := (uint16(pos.Y) + (uint16(pos.X) << 8)) & 0x1FFF
	for it := asWall(dword_5D4594_251544[ind]); it != nil; it = it.next() {
		if pos == it.GridPos() && it.field4()&0x30 == 0 {
			return it
		}
	}
	return nil
}

func (s *Server) getWallAtGrid2(pos image.Point) *Wall { // nox_xxx_wall_4105E0
	v2 := (uint16(pos.Y) + (uint16(pos.X) << 8)) & 0x1FFF
	for it := asWall(dword_5D4594_251544[v2]); it != nil; it = it.next() {
		if pos == it.GridPos() && it.field4()&0x20 == 0 {
			return it
		}
	}
	return nil
}

func (s *Server) getWallAt(pos types.Pointf) *Wall {
	return s.getWallAtGrid(wall.PosToGrid(pos))
}

func (s *Server) getWallNear(pos types.Pointf) *Wall {
	if w := s.getWallAt(pos); w != nil {
		return w
	}
	// TODO: a better way
	pi := wall.PosToGrid(pos)
	try := []image.Point{
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
		if w := s.getWallAtGrid(p); w != nil {
			return w
		}
	}
	return nil
}

func (s *Server) getWallGroupByID(id string) *script.WallGroup {
	g := s.mapGroups.GroupByID(id, mapGroupWalls)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Wall
	for it := g.First(); it != nil; it = it.Next() {
		if wl := s.getWallAtGrid(image.Point{
			X: it.Data1(),
			Y: it.Data2(),
		}); wl != nil {
			list = append(list, wl)
		}
	}
	return script.NewWallGroup(id, list...)
}

func nox_xxx_wallSecretGetFirstWall_410780() unsafe.Pointer {
	return C.dword_5d4594_251560
}

func nox_xxx_wallSecretNext_410790(p unsafe.Pointer) unsafe.Pointer {
	if p == nil {
		return nil
	}
	return *(*unsafe.Pointer)(p)
}

type Wall [0]byte

func (w *Wall) C() unsafe.Pointer {
	return unsafe.Pointer(w)
}

func (w *Wall) field(dp uintptr) unsafe.Pointer {
	return unsafe.Add(w.C(), dp)
}

func (w *Wall) String() string {
	pos := w.GridPos()
	return fmt.Sprintf("Wall(%d, %d)", pos.X, pos.Y)
}

func (w *Wall) ScriptID() int {
	p := w.GridPos()
	return (p.X << 16) | p.Y
}

func (w *Wall) dir() byte {
	return *(*byte)(w.field(0))
}

func (w *Wall) setDir(v byte) {
	*(*byte)(w.field(0)) = v
}

func (w *Wall) tile() byte {
	return *(*byte)(w.field(1))
}

func (w *Wall) setTile(v byte) {
	*(*byte)(w.field(1)) = v
}

func (w *Wall) field2() byte {
	return *(*byte)(w.field(2))
}

func (w *Wall) setField2(v byte) {
	*(*byte)(w.field(2)) = v
}

func (w *Wall) field4() byte {
	return *(*byte)(w.field(4))
}

func (w *Wall) setField4(v byte) {
	*(*byte)(w.field(4)) = v
}

func (w *Wall) health() byte {
	return *(*byte)(w.field(7))
}

func (w *Wall) setHealth(v byte) {
	*(*byte)(w.field(7)) = v
}

func (w *Wall) GridPos() image.Point {
	x := int(*(*byte)(w.field(5)))
	y := int(*(*byte)(w.field(6)))
	return image.Point{
		X: x,
		Y: y,
	}
}

func (w *Wall) Pos() types.Pointf {
	p := w.GridPos()
	return wall.GridToPos(p)
}

func (w *Wall) next() *Wall {
	return asWall(*(*unsafe.Pointer)(w.field(16)))
}

func (w *Wall) field28() unsafe.Pointer {
	return *(*unsafe.Pointer)(w.field(28))
}

// IsEnabled checks if the wall is closed.
func (w *Wall) IsEnabled() bool {
	v2 := w.field28()
	v3 := *(*byte)(unsafe.Add(v2, 21))
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

func (w *Wall) Toggle() bool {
	C.nox_xxx_wallToggle_512160(C.int(uintptr(w.C())))
	return w.IsEnabled()
}

// Destroy (break) the wall.
func (w *Wall) Destroy() {
	C.nox_xxx_wallPreDestroyByPtr_5122C0(C.int(uintptr(w.C())))
}
