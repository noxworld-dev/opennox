package opennox

import (
	"image"

	"github.com/noxworld-dev/noxscript/ns/v4"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) NoWallSound(noWallSound bool) {
	legacy.Set_nox_xxx_wallSounds_2386840(bool2int(noWallSound))
}

func (s noxScriptNS) WallByHandle(h ns.WallHandle) ns.WallObj {
	if h == nil {
		return nil
	}
	id := h.WallScriptID()
	x := id >> 16
	y := id & 0xffff
	return s.Wall(x, y)
}

func (s noxScriptNS) Wall(x int, y int) ns.WallObj {
	w := s.s.getWallAtGrid(image.Pt(x, y))
	if w == nil {
		return nil
	}
	return w
}

func (s noxScriptNS) WallGroupByHandle(h ns.WallGroupHandle) ns.WallGroupObj {
	if h == nil {
		return nil
	}
	g := s.s.MapGroups.GroupByInd(h.WallGroupScriptID())
	if g == nil || mapGroupType(g) != server.MapGroupObjects {
		return nil
	}
	return nsWallGroup{s.s, g}
}

func (s noxScriptNS) WallGroup(name string) ns.WallGroupObj {
	g := s.s.GroupByID(name, server.MapGroupWalls)
	if g == nil {
		scriptLog.Printf("noxscript: cannot find wall group: %q", name)
		return nil
	}
	return nsWallGroup{s.s, g}
}

type nsWallGroup struct {
	s *Server
	g *server.MapGroup
}

func (g nsWallGroup) ScriptID() int {
	return int(g.g.Index())
}

func (g nsWallGroup) WallGroupScriptID() int {
	return int(g.g.Index())
}

func (g nsWallGroup) Enable(enable bool) {
	g.EachWall(true, func(w ns.WallObj) bool {
		w.Enable(enable)
		return true
	})
}

func (g nsWallGroup) Toggle() bool {
	one := false
	g.EachWall(true, func(w ns.WallObj) bool {
		if w.Toggle() {
			one = true
		}
		return true
	})
	return one
}

func (g nsWallGroup) Destroy() {
	g.EachWall(true, func(w ns.WallObj) bool {
		w.Destroy()
		return true
	})
}

func (g nsWallGroup) EachWall(recursive bool, fnc func(obj ns.WallObj) bool) {
	// TODO: recursive parameter is unused; remove from interface?
	eachWallRecursive(g.s, g.g, fnc)
}
