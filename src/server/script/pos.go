package script

import "nox/v1/common/types"

// Positioner is an interface for objects that has position on the map.
type Positioner interface {
	// Pos returns current position of the object.
	Pos() types.Pointf
}

// GridPositioner is an interface for objects that has position on the map.
type GridPositioner interface {
	// GridPos returns current position of the object on the grid.
	GridPos() types.Point
}

// PositionSetter is an interface for objects that can be moved.
type PositionSetter interface {
	// SetPos instantly moves object to a given position.
	SetPos(p types.Pointf)
}

// Positionable is a combined interface for objects for which you can get and set the position.
type Positionable interface {
	Positioner
	PositionSetter
}

// SetPos is a helper to instantly move objects to another object's location.
func SetPos(obj PositionSetter, to Positioner) {
	obj.SetPos(to.Pos())
}

// Raisable is an interface for positionable objects that can also be raised or lowered by Z axis.
type Raisable interface {
	Positionable
	// Z returns current Z offset for the object.
	Z() float32
	// SetZ sets Z offset for the object.
	SetZ(z float32)
}

// Pushable is an interface for objects that can be pushed.
type Pushable interface {
	// Push applies a force to the object based on the vector and magnitude.
	Push(vec types.Pointf, force float32)
	// PushTo pushes an object to a specific location.
	PushTo(p types.Pointf)
}

// Physical is an interface for objects that are affected by physics.
type Physical interface {
	Raisable
	Pushable
}

// PushToPos is a helper to push objects to another object's location.
func PushToPos(obj Pushable, to Positioner) {
	obj.PushTo(to.Pos())
}
