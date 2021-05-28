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

// Mover is an interface for objects that can be moved.
type Mover interface {
	// MoveTo instantly moves object to a given position.
	MoveTo(p types.Pointf)
}

// Movable is a combined interface for objects for which you can get and set the position.
type Movable interface {
	Positioner
	Mover
}

// MoveToPos is a helper to move objects to another object's location.
func MoveToPos(obj Mover, to Positioner) {
	obj.MoveTo(to.Pos())
}

// Raisable is an interface for movable objects that can also be raised or lowered by Z axis.
type Raisable interface {
	Movable
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
