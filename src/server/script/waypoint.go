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

// WaypointBase implements Waypoint, but panics on all the methods.
// Useful when you only want to define a part of the implementation.
type WaypointBase struct{}

func (WaypointBase) String() string {
	panic("implement me")
}

func (WaypointBase) ID() string {
	panic("implement me")
}

func (WaypointBase) IsEnabled() bool {
	panic("implement me")
}

func (WaypointBase) Enable(enable bool) {
	panic("implement me")
}

func (WaypointBase) Toggle() bool {
	panic("implement me")
}

func (WaypointBase) Pos() types.Pointf {
	panic("implement me")
}

func (WaypointBase) SetPos(p types.Pointf) {
	panic("implement me")
}
