package opennox

import (
	"github.com/noxworld-dev/opennox-lib/script"

	"github.com/noxworld-dev/opennox/v1/server"
)

func (s *Server) getWaypointGroupByID(id string) *script.WaypointGroup {
	g := s.MapGroups.GroupByID(id, server.MapGroupWaypoints)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Waypoint
	for it := g.First(); it != nil; it = it.Next() {
		if wl := s.WPs.ByInd(it.Data1()); wl != nil {
			list = append(list, wl)
		}
	}
	return script.NewWaypointGroup(id, list...)
}
