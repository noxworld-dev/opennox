package opennox

/*
extern unsigned int nox_xxx_wallSounds_2386840;
*/
import "C"
import (
	"image"

	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns"
)

func (s noxScriptNS) NoWallSound(noWallSound bool) {
	C.nox_xxx_wallSounds_2386840 = C.uint(bool2int(noWallSound))
}

func (s noxScriptNS) Wall(x int, y int) ns.WallObj {
	w := s.s.getWallAtGrid(image.Pt(x, y))
	if w == nil {
		return nil
	}
	return w
}

func (s noxScriptNS) WallGroup(name string) ns.WallGroupObj {
	g := s.s.mapGroups.GroupByID(name, mapGroupWalls)
	if g == nil {
		scriptLog.Printf("noxscript: cannot find wall group: %q", name)
		return nil
	}
	return nsWallGroup{s.s, g}
}

type nsWallGroup struct {
	s *Server
	g *mapGroup
}

func (g nsWallGroup) ScriptID() int {
	return int(g.g.Ind())
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
	g.g.eachWallRecursive(g.s, fnc)
}
