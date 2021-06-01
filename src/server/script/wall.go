package script

import (
	"fmt"

	"nox/v1/common/types"
)

type Wall interface {
	fmt.Stringer
	Positioner
	GridPositioner
	Enabler // opens and closes the wall
	Destroyable
}

var (
	_ Identifiable = &WallGroup{}
	_ EnableSetter = &WallGroup{}
	_ Toggler      = &WallGroup{}
	_ Destroyable  = &WallGroup{}
)

func NewWallGroup(id string, list ...Wall) *WallGroup {
	return &WallGroup{id: id, list: list}
}

type WallGroup struct {
	id   string
	list []Wall
}

func (g *WallGroup) ID() string {
	if g == nil {
		return ""
	}
	return g.id
}

func (g *WallGroup) String() string {
	if id := g.ID(); id != "" {
		return fmt.Sprintf("WallGroup(%s)", id)
	}
	return fmt.Sprintf("WallGroup(%d)", len(g.list))
}

func (g *WallGroup) Walls() []Wall {
	if g == nil {
		return nil
	}
	return g.list
}

func (g *WallGroup) Enable(enable bool) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Enable(enable)
	}
}

func (g *WallGroup) Toggle() bool {
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

func (g *WallGroup) Destroy() {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Destroy()
	}
}

var _ Wall = BaseWall{}

// BaseWall implements Wall, but panics on all the methods.
// Useful when you only want to define a part of the implementation.
type BaseWall struct{}

func (BaseWall) String() string {
	panic("implement me")
}

func (BaseWall) Pos() types.Pointf {
	panic("implement me")
}

func (BaseWall) GridPos() types.Point {
	panic("implement me")
}

func (BaseWall) IsEnabled() bool {
	panic("implement me")
}

func (BaseWall) Enable(enable bool) {
	panic("implement me")
}

func (BaseWall) Destroy() {
	panic("implement me")
}
