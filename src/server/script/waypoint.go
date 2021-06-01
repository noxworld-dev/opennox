package script

import (
	"fmt"

	"nox/v1/common/types"
)

type Waypoint interface {
	Identifiable
	Enabler
	Positionable
}

func NewWaypointGroup(id string, list ...Waypoint) *WaypointGroup {
	return &WaypointGroup{id: id, list: list}
}

type waypointGroup interface {
	Identifiable
	EnableSetter
	Toggler
	PositionSetter
}

var (
	_ waypointGroup = &WaypointGroup{}
)

type WaypointGroup struct {
	id   string
	list []Waypoint
}

func (g *WaypointGroup) ID() string {
	if g == nil {
		return ""
	}
	return g.id
}

func (g *WaypointGroup) String() string {
	if id := g.ID(); id != "" {
		return fmt.Sprintf("WaypointGroup(%s)", id)
	}
	return fmt.Sprintf("WaypointGroup(%d)", len(g.list))
}

func (g *WaypointGroup) Waypoints() []Waypoint {
	if g == nil {
		return nil
	}
	return g.list
}

func (g *WaypointGroup) Enable(enable bool) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Enable(enable)
	}
}

func (g *WaypointGroup) Toggle() bool {
	if g == nil {
		return false
	}
	var st bool
	for i, v := range g.list {
		ns := Toggle(v)
		if i == 0 {
			st = ns
		}
	}
	return st
}

func (g *WaypointGroup) SetPos(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.SetPos(pos)
	}
}

var _ Waypoint = BaseWaypoint{}

// BaseWaypoint implements Waypoint, but panics on all the methods.
// Useful when you only want to define a part of the implementation.
type BaseWaypoint struct{}

func (BaseWaypoint) String() string {
	panic("implement me")
}

func (BaseWaypoint) ID() string {
	panic("implement me")
}

func (BaseWaypoint) IsEnabled() bool {
	panic("implement me")
}

func (BaseWaypoint) Enable(enable bool) {
	panic("implement me")
}

func (BaseWaypoint) Toggle() bool {
	panic("implement me")
}

func (BaseWaypoint) Pos() types.Pointf {
	panic("implement me")
}

func (BaseWaypoint) SetPos(p types.Pointf) {
	panic("implement me")
}
