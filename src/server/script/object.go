package script

import (
	"nox/v1/common/object"
	"nox/v1/common/types"
)

type ObjectType interface {
	Identifiable
	CreateObject(p types.Pointf) Object
}

type Object interface {
	Identifiable
	Class() object.Class
	ObjectType() ObjectType
	Physical
	Enabler
	Deleter
}

type LockableObject interface {
	Object
	Lockable
}

func NewObjectGroup(id string, list ...Object) *ObjectGroup {
	return &ObjectGroup{id: id, list: list}
}

var (
	_ Identifiable = &ObjectGroup{}
	_ EnableSetter = &ObjectGroup{}
	_ Toggler      = &ObjectGroup{}
	_ Deleter      = &ObjectGroup{}
	_ Mover        = &ObjectGroup{}
	_ Pushable     = &ObjectGroup{}
)

type ObjectGroup struct {
	id   string
	list []Object
}

func (g *ObjectGroup) ID() string {
	if g == nil {
		return ""
	}
	return g.id
}

func (g *ObjectGroup) Objects() []Object {
	if g == nil {
		return nil
	}
	return g.list
}

func (g *ObjectGroup) Enable(enable bool) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Enable(enable)
	}
}

func (g *ObjectGroup) Delete() {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Delete()
	}
}

func (g *ObjectGroup) Toggle() bool {
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

func (g *ObjectGroup) MoveTo(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.MoveTo(pos)
	}
}

func (g *ObjectGroup) Push(vec types.Pointf, force float32) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Push(vec, force)
	}
}

func (g *ObjectGroup) PushTo(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.PushTo(pos)
	}
}
