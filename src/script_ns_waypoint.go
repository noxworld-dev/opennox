package opennox

import (
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns"

	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) Waypoint(name string) ns.WaypointObj {
	wp := s.s.getWaypointByID(name)
	if wp == nil {
		scriptLog.Printf("noxscript: cannot find waypoint: %q", name)
		return nil
	}
	return wp
}

func (s noxScriptNS) WaypointGroup(name string) ns.WaypointGroupObj {
	g := s.s.GroupByID(name, server.MapGroupWaypoints)
	if g == nil {
		scriptLog.Printf("noxscript: cannot find waypoint group: %q", name)
		return nil
	}
	return nsWpGroup{s.s, g}
}

type nsWpGroup struct {
	s *Server
	g *server.MapGroup
}

func (g nsWpGroup) ScriptID() int {
	return int(g.g.Index())
}

func (g nsWpGroup) Enable(enable bool) {
	g.EachWaypoint(true, func(wp ns.WaypointObj) bool {
		wp.Enable(enable)
		return false
	})
}

func (g nsWpGroup) Toggle() bool {
	one := false
	g.EachWaypoint(true, func(wp ns.WaypointObj) bool {
		if wp.Toggle() {
			one = true
		}
		return true
	})
	return one
}

func (g nsWpGroup) EachWaypoint(recursive bool, fnc func(obj ns.WaypointObj) bool) {
	// TODO: recursive parameter is unused; remove from interface?
	eachWaypointRecursive(g.s, g.g, fnc)
}
