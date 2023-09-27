package opennox

import (
	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) Waypoints() []ns.WaypointObj {
	list := s.s.WPs.All()
	out := make([]ns.WaypointObj, 0, len(list))
	for _, wp := range list {
		out = append(out, wp)
	}
	return out
}

func (s noxScriptNS) WaypointByHandle(h ns.WaypointHandle) ns.WaypointObj {
	if h == nil {
		return nil
	}
	wp := s.s.WPs.ByInd(h.WaypointScriptID())
	if wp == nil {
		return nil
	}
	return wp
}

func (s noxScriptNS) Waypoint(name string) ns.WaypointObj {
	wp := s.s.WPs.ByID(name)
	if wp == nil {
		scriptLog.Printf("noxscript: cannot find waypoint: %q", name)
		return nil
	}
	return wp
}

func (s noxScriptNS) NewWaypoint(name string, pos types.Pointf) ns.WaypointObj {
	wp := s.s.NewWaypoint(pos)
	wp.SetName(name)
	return wp
}

func (s noxScriptNS) WaypointGroupByHandle(h ns.WaypointGroupHandle) ns.WaypointGroupObj {
	if h == nil {
		return nil
	}
	g := s.s.MapGroups.GroupByInd(h.WaypointGroupScriptID())
	if g == nil || mapGroupType(g) != server.MapGroupWaypoints {
		return nil
	}
	return nsWpGroup{s.s, g}
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

func (g nsWpGroup) WaypointGroupScriptID() int {
	return int(g.g.Index())
}

func (g nsWpGroup) Name() string {
	return g.g.ID()
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
