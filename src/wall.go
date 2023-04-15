package opennox

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func asWallS(p *server.Wall) *Wall {
	return (*Wall)(unsafe.Pointer(p))
}

func (s *Server) nox_xxx_wallTileByName_410D60(name string) byte {
	return legacy.Nox_xxx_wallTileByName_410D60(name)
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
		if wl := s.Walls.GetWallAtGrid(image.Point{
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
