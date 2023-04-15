package opennox

import (
	"fmt"
	"image"
	"sort"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"
	"github.com/noxworld-dev/opennox-lib/wall"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	dword_5D4594_251544 []unsafe.Pointer
	dword_5d4594_251556 []unsafe.Pointer
)

func asWall(p unsafe.Pointer) *Wall {
	return (*Wall)(p)
}

func nox_server_getWallAtGrid_410580(x, y int) unsafe.Pointer {
	return noxServer.getWallAtGrid(image.Pt(x, y)).C()
}

func nox_xxx_wall_4105E0(x, y int) unsafe.Pointer {
	return noxServer.getWallAtGrid2(image.Pt(x, y)).C()
}

func allocWalls() int {
	dword_5D4594_251544, _ = alloc.Make([]unsafe.Pointer{}, 32*256)
	if dword_5D4594_251544 == nil {
		return 0
	}
	legacy.Set_dword_5D4594_251544(unsafe.Pointer(&dword_5D4594_251544[0]))

	dword_5d4594_251556, _ = alloc.Make([]unsafe.Pointer{}, 256)
	if dword_5d4594_251556 == nil {
		return 0
	}
	legacy.Set_dword_5d4594_251556(unsafe.Pointer(&dword_5d4594_251556[0]))
	legacy.Set_dword_5d4594_251552(0)
	for i := 0; i < 32*256; i++ {
		ptr, _ := alloc.Malloc(36)
		if ptr == nil {
			return 0
		}
		*(*unsafe.Pointer)(unsafe.Add(ptr, 20)) = legacy.Get_dword_5d4594_251548()
		legacy.Set_dword_5d4594_251548(ptr)
	}
	nox_xxx_wall_410160()
	return 1
}

func nox_xxx_wall_410160() {
	for i := 0; i < 32*256; i++ {
		ptr := dword_5D4594_251544[i]
		if ptr == nil {
			dword_5D4594_251544[i] = nil
			continue
		}

		var next unsafe.Pointer
		prev := legacy.Get_dword_5d4594_251548()
		for it := ptr; it != nil; it = next {
			next = *(*unsafe.Pointer)(unsafe.Add(it, 16))
			*(*unsafe.Pointer)(unsafe.Add(it, 20)) = prev
			legacy.Set_dword_5d4594_251548(it)
			prev = it
		}
		dword_5D4594_251544[i] = nil
	}
	legacy.Set_dword_5d4594_251552(0)
	for i := 0; i < 256; i++ {
		dword_5d4594_251556[i] = nil
	}
}

func freeWalls() {
	for i := 0; i < 32*256; i++ {
		var next unsafe.Pointer
		for ptr := dword_5D4594_251544[i]; ptr != nil; ptr = next {
			next = *(*unsafe.Pointer)(unsafe.Add(ptr, 16))
			alloc.FreePtr(ptr)
		}
	}
	var next unsafe.Pointer
	for ptr := legacy.Get_dword_5d4594_251548(); ptr != nil; ptr = next {
		next = *(*unsafe.Pointer)(unsafe.Add(ptr, 20))
		alloc.FreePtr(ptr)
	}
	legacy.Set_dword_5d4594_251548(nil)

	alloc.FreeSlice(dword_5D4594_251544)
	dword_5D4594_251544 = nil
	legacy.Set_dword_5D4594_251544(nil)

	alloc.FreeSlice(dword_5d4594_251556)
	dword_5d4594_251556 = nil
	legacy.Set_dword_5d4594_251556(nil)
}

func (s *Server) nox_xxx_wallTileByName_410D60(name string) byte {
	return legacy.Nox_xxx_wallTileByName_410D60(name)
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
	g := s.GroupByID(id, server.MapGroupWalls)
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
	return legacy.Get_dword_5d4594_251560()
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

func (w *Wall) WallScriptID() int {
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
		legacy.Nox_xxx_wallClose_512070(w.C())
	} else {
		legacy.Nox_xxx_wallOpen_511F80(w.C())
	}
}

func (w *Wall) Toggle() bool {
	legacy.Nox_xxx_wallToggle_512160(w.C())
	return w.IsEnabled()
}

// Destroy (break) the wall.
func (w *Wall) Destroy() {
	legacy.Nox_xxx_wallPreDestroyByPtr_5122C0(w.C())
}
