package script

import "nox/v1/common/types"

// Living is an interface for objects that are alive.
type Living interface {
	Breakable
	// Mana returns current and max mana of the unit.
	Mana() (cur, max int)
	// SetMana sets the amount of mana of the object. It will be limited by max mana.
	SetMana(v int)
	// SetMaxMana sets the maximal amount of mana of the object. It will be adjust mana accordingly.
	SetMaxMana(v int)
}

// Mobile is an interface for objects that can move around on their own.
type Mobile interface {
	Positioner
	// WalkTo forces the unit to walk to a location.
	WalkTo(p types.Pointf)
	// LookAt forces the unit to look at the location.
	LookAt(p types.Pointf)
	// LookAtDir forces the unit to look in a given direction.
	LookAtDir(dir int)
	// LookAngle forces unit to look at a given angle.
	LookAngle(ang int)
	// Freeze or unfreeze an object in place.
	Freeze(freeze bool)
	// Wander makes this unit wander around.
	Wander()
	// Return makes this unit to return to its starting position.
	Return()
	// Follow a given object.
	Follow(obj Positioner)
	// Flee from a given object for a certain duration.
	Flee(obj Positioner, dur Duration)
}

// WalkToPos is a helper to make an objects walk to another object's location.
func WalkToPos(obj Mobile, to Positioner) {
	obj.WalkTo(to.Pos())
}

// LookAtPos is a helper to make an objects look at another object's location.
func LookAtPos(obj Mobile, to Positioner) {
	obj.LookAt(to.Pos())
}

// Offensive is an interface for objects that can attack or defend.
type Offensive interface {
	// Aggression returns current aggression level.
	Aggression() float32
	// SetAggression sets aggression level.
	SetAggression(v float32)
	// RetreatLevel returns current retreat level.
	RetreatLevel() float32
	// SetRetreatLevel sets retreat level, causing the creature to flee on low health.
	SetRetreatLevel(v float32)
	// RegroupLevel returns current regroup level.
	RegroupLevel() float32
	// SetRegroupLevel sets regroup level, causing the creature to return to fight when health restores.
	SetRegroupLevel(v float32)
	// Attack another object.
	Attack(obj Positioner)
	// HitMelee forces the unit to melee attack the location.
	HitMelee(p types.Pointf)
	// HitRanged forces the unit to ranged attack the location.
	HitRanged(p types.Pointf)
}

// HitMeleePos is a helper to make an objects melee attack another object's location.
func HitMeleePos(obj Offensive, to Positioner) {
	obj.HitMelee(to.Pos())
}

// HitRangedPos is a helper to make an objects ranged attack another object's location.
func HitRangedPos(obj Offensive, to Positioner) {
	obj.HitRanged(to.Pos())
}

// Chatty is an interface for objects that can say stuff.
type Chatty interface {
	// Say displays the chat bubble on this object.
	// If the duration is set, the bubble will disappear after it passes.
	Say(text string, dur Duration)
	// Mute removes the current chat bubble, if any.
	Mute()
}

type Unit interface {
	Object
	// CanSee checks if this unit can see an object.
	CanSee(obj Object) bool
	Living
	Mobile
	Offensive
	Chatty // TODO: should be on object?
}

func NewUnitGroup(id string, list ...Unit) *UnitGroup {
	return &UnitGroup{id: id, list: list}
}

var ()

type UnitGroup struct {
	id   string
	list []Unit
}
