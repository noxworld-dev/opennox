package script

import (
	"fmt"

	"nox/v1/common/object"
	"nox/v1/common/types"
)

type ObjectType interface {
	Identifiable
	CreateObject(p types.Pointf) Object
}

// ObjectWrapper is an interface for types that wrap Object.
type ObjectWrapper interface {
	// GetObject returns an underlying object.
	GetObject() Object
}

type Object interface {
	Identifiable
	ObjectWrapper
	Class() object.Class
	ObjectType() ObjectType
	Ownable
	Physical
	Enabler
	Deleter
	Destroyable
}

type LockableObject interface {
	Object
	Lockable
}

func NewObjectGroup(id string, list ...Object) *ObjectGroup {
	return &ObjectGroup{id: id, list: list}
}

type objectGroup interface {
	Identifiable
	OwnerSetter
	EnableSetter
	Toggler
	Deleter
	PositionSetter
	Pushable
	Destroyable
}

var (
	_ objectGroup = &ObjectGroup{}
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

func (g *ObjectGroup) String() string {
	if id := g.ID(); id != "" {
		return fmt.Sprintf("ObjectGroup(%s)", id)
	}
	return fmt.Sprintf("ObjectGroup(%d)", len(g.list))
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

func (g *ObjectGroup) SetOwner(owner ObjectWrapper) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.SetOwner(owner)
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

func (g *ObjectGroup) Destroy() {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Destroy()
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

func (g *ObjectGroup) SetPos(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.SetPos(pos)
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

var _ Object = BaseObject{}

// BaseObject implements Object, but panics on all the methods.
// Useful when you only want to define a part of the implementation.
type BaseObject struct{}

func (BaseObject) ID() string {
	panic("implement me")
}

func (BaseObject) String() string {
	panic("implement me")
}

func (BaseObject) GetObject() Object {
	panic("implement me")
}

func (BaseObject) Class() object.Class {
	panic("implement me")
}

func (BaseObject) ObjectType() ObjectType {
	panic("implement me")
}

func (BaseObject) Owner() Object {
	panic("implement me")
}

func (BaseObject) SetOwner(owner ObjectWrapper) {
	panic("implement me")
}

func (BaseObject) Pos() types.Pointf {
	panic("implement me")
}

func (BaseObject) SetPos(p types.Pointf) {
	panic("implement me")
}

func (BaseObject) Z() float32 {
	panic("implement me")
}

func (BaseObject) SetZ(z float32) {
	panic("implement me")
}

func (BaseObject) Push(vec types.Pointf, force float32) {
	panic("implement me")
}

func (BaseObject) PushTo(p types.Pointf) {
	panic("implement me")
}

func (BaseObject) IsEnabled() bool {
	panic("implement me")
}

func (BaseObject) Enable(enable bool) {
	panic("implement me")
}

func (BaseObject) Delete() {
	panic("implement me")
}

func (BaseObject) Destroy() {
	panic("implement me")
}
