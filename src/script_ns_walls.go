package opennox

import (
	"image"

	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) NoWallSound(noSound bool) {
	s.s.Walls.NoWallSounds = noSound
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
	w := s.s.Walls.GetWallAtGrid(image.Pt(x, y))
	if w == nil {
		return nil
	}
	return asWallS(w)
}

func (s noxScriptNS) WallGroupByHandle(h ns.WallGroupHandle) ns.WallGroupObj {
	if h == nil {
		return nil
	}
	g := s.s.MapGroups.GroupByInd(h.WallGroupScriptID())
	if g == nil || s.s.MapGroups.MapGroupType(g) != server.MapGroupObjects {
		return nil
	}
	return nsWallGroup{s.s, g}
}

func (s noxScriptNS) WallGroup(name string) ns.WallGroupObj {
	g := s.s.MapGroups.GroupByID(name, server.MapGroupWalls)
	if g == nil {
		ScriptLog.Printf("noxscript: cannot find wall group: %q", name)
		return nil
	}
	return nsWallGroup{s.s, g}
}

func (s noxScriptNS) FindWalls(iter func(it ns.WallObj) bool, conditions ...ns.WallCond) int {
	// This generic iteration function will act as a fallback that scans everything.
	search := s.s.Walls.EachWallRaw
	// Attempt to find a more specific iterator ad optimize it.
	for i, c := range conditions {
		found := false
		switch c := c.(type) {
		case ns.InRectf:
			search = func(fnc func(obj *server.Wall) bool) {
				s.s.Walls.EachInRect(types.RectFromPointsf(c.Min, c.Max), fnc)
			}
			found = true
		case ns.InCirclef:
			search = func(fnc func(obj *server.Wall) bool) {
				s.s.Walls.EachInCircle(c.Center.Pos(), float32(c.R), fnc)
			}
			found = true
		}
		// We only need one optimized iterator. Once found - remove it from conditions.
		if found {
			conditions = append(conditions[:i], conditions[i+1:]...)
			break
		}
	}
	// Finally start the actual iteration.
	filter := wallAND(conditions)
	cnt := 0
	search(func(it *server.Wall) bool {
		wl := asWallS(it)
		if !filter.Matches(wl) {
			return true // find next match
		}
		// Found, pass to user-defined handler func.
		cnt++
		if iter != nil && !iter(wl) {
			return false
		}
		return true
	})
	return cnt
}

type wallAND []ns.WallCond

func (arr wallAND) Matches(obj ns.WallObj) bool {
	for _, c := range arr {
		if !c.WallMatches(obj) {
			return false
		}
	}
	return true
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

func (g nsWallGroup) Name() string {
	return g.g.ID()
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
	server.EachWallRecursive(g.s.Server, g.g, func(wl *server.Wall) bool {
		return fnc(asWallS(wl))
	})
}
