package opennox

import (
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

const wallGridSize = 256

var (
	dword_5D4594_251544 []*server.Wall
	dword_5d4594_251556 []unsafe.Pointer
)

func asWallS(p *server.Wall) *Wall {
	return (*Wall)(unsafe.Pointer(p))
}

func nox_server_getWallAtGrid_410580(x, y int) *server.Wall {
	return noxServer.getWallAtGrid(image.Pt(x, y))
}

func nox_xxx_wall_4105E0(x, y int) *server.Wall {
	return noxServer.getWallAtGrid2(image.Pt(x, y))
}

func allocWalls() int {
	dword_5D4594_251544, _ = alloc.Make([]*server.Wall{}, 32*wallGridSize)
	if dword_5D4594_251544 == nil {
		return 0
	}
	legacy.Set_dword_5D4594_251544(unsafe.Pointer(&dword_5D4594_251544[0]))

	dword_5d4594_251556, _ = alloc.Make([]unsafe.Pointer{}, wallGridSize)
	if dword_5d4594_251556 == nil {
		return 0
	}
	legacy.Set_dword_5d4594_251556(unsafe.Pointer(&dword_5d4594_251556[0]))
	legacy.Set_dword_5d4594_251552(0)
	for i := 0; i < 32*wallGridSize; i++ {
		ptr, _ := alloc.New(Wall{})
		if ptr == nil {
			return 0
		}
		ptr.Prev20 = legacy.Get_dword_5d4594_251548()
		legacy.Set_dword_5d4594_251548(ptr.C())
	}
	nox_xxx_wall_410160()
	return 1
}

func nox_xxx_wall_410160() {
	for i := 0; i < 32*wallGridSize; i++ {
		ptr := dword_5D4594_251544[i]
		if ptr == nil {
			dword_5D4594_251544[i] = nil
			continue
		}

		var next *server.Wall
		prev := legacy.Get_dword_5d4594_251548()
		for it := ptr; it != nil; it = next {
			next = it.Next16
			it.Prev20 = prev
			legacy.Set_dword_5d4594_251548(it.C())
			prev = it
		}
		dword_5D4594_251544[i] = nil
	}
	legacy.Set_dword_5d4594_251552(0)
	for i := 0; i < wallGridSize; i++ {
		dword_5d4594_251556[i] = nil
	}
}

func freeWalls() {
	for i := 0; i < 32*wallGridSize; i++ {
		var next *server.Wall
		for ptr := dword_5D4594_251544[i]; ptr != nil; ptr = next {
			next = ptr.Next16
			alloc.Free(ptr)
		}
	}
	var next *server.Wall
	for ptr := legacy.Get_dword_5d4594_251548(); ptr != nil; ptr = next {
		next = ptr.Prev20
		alloc.Free(ptr)
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

func (s *Server) getWallAtGrid(pos image.Point) *server.Wall { // nox_server_getWallAtGrid_410580
	if (byte(pos.X)+byte(pos.Y))&0x1 != 0 {
		return nil
	}
	ind := (uint16(pos.Y) + (uint16(pos.X) << 8)) & 0x1FFF
	for it := dword_5D4594_251544[ind]; it != nil; it = it.Next16 {
		if pos == it.GridPos() && it.Field4&0x30 == 0 {
			return it
		}
	}
	return nil
}

func (s *Server) getWallAtGrid2(pos image.Point) *server.Wall { // nox_xxx_wall_4105E0
	v2 := (uint16(pos.Y) + (uint16(pos.X) << 8)) & 0x1FFF
	for it := dword_5D4594_251544[v2]; it != nil; it = it.Next16 {
		if pos == it.GridPos() && it.Field4&0x20 == 0 {
			return it
		}
	}
	return nil
}

func (s *Server) getWallAt(pos types.Pointf) *server.Wall {
	return s.getWallAtGrid(wall.PosToGrid(pos))
}

func (s *Server) getWallNear(pos types.Pointf) *server.Wall {
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
			list = append(list, asWallS(wl))
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

var _ = [1]struct{}{}[36-unsafe.Sizeof(Wall{})]

type Wall server.Wall

func (w *Wall) C() unsafe.Pointer {
	return unsafe.Pointer(w)
}

func (w *Wall) S() *server.Wall {
	if w == nil {
		return nil
	}
	return (*server.Wall)(unsafe.Pointer(w))
}

func (w *Wall) String() string {
	return w.S().String()
}

func (w *Wall) WallScriptID() int {
	return w.S().WallScriptID()
}

func (w *Wall) ScriptID() int {
	return w.S().ScriptID()
}

func (w *Wall) GridPos() image.Point {
	return w.S().GridPos()
}

func (w *Wall) Pos() types.Pointf {
	return w.S().Pos()
}

// IsEnabled checks if the wall is closed.
func (w *Wall) IsEnabled() bool {
	return w.S().IsEnabled()
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
