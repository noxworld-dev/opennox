package script

import (
	"fmt"

	"nox/v1/common/types"
)

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
	// MoveTo forces the unit to move to a location. More generic than WalkTo.
	MoveTo(p types.Pointf)
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
	// Idle makes an object idle.
	Idle()
	// Follow a given object.
	Follow(obj Positioner)
	// Flee from a given object for a certain duration.
	Flee(obj Positioner, dur Duration)
}

// MoveToPos is a helper to make an objects walk to another object's location. More generic than WalkToPos.
func MoveToPos(obj Mobile, to Positioner) {
	obj.MoveTo(to.Pos())
}

// WalkToPos is a helper to make an objects walk to another object's location.
func WalkToPos(obj Mobile, to Positioner) {
	obj.WalkTo(to.Pos())
}

// LookAtPos is a helper to make an objects look at another object's location.
func LookAtPos(obj Mobile, to Positioner) {
	obj.LookAt(to.Pos())
}

// OffensiveGroup is an interface for a group of objects that can attack or defend.
type OffensiveGroup interface {
	// SetAggression sets aggression level.
	SetAggression(v float32)
	// SetRetreatLevel sets retreat level, causing the creature to flee on low health.
	SetRetreatLevel(v float32)
	// SetRegroupLevel sets regroup level, causing the creature to return to fight when health restores.
	SetRegroupLevel(v float32)
	// Attack another object.
	Attack(obj Positioner)
	// HitMelee forces the unit to melee attack the location.
	HitMelee(p types.Pointf)
	// HitRanged forces the unit to ranged attack the location.
	HitRanged(p types.Pointf)
	// Guard makes an object guard location.
	Guard()
	// Hunt makes an object hunt for enemies.
	Hunt()
}

// Offensive is an interface for objects that can attack or defend.
type Offensive interface {
	OffensiveGroup
	// Aggression returns current aggression level.
	Aggression() float32
	// RetreatLevel returns current retreat level.
	RetreatLevel() float32
	// RegroupLevel returns current regroup level.
	RegroupLevel() float32
}

// HitMeleePos is a helper to make an objects melee attack another object's location.
func HitMeleePos(obj OffensiveGroup, to Positioner) {
	obj.HitMelee(to.Pos())
}

// HitRangedPos is a helper to make an objects ranged attack another object's location.
func HitRangedPos(obj OffensiveGroup, to Positioner) {
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

// IsAllUnits checks if all objects in the list are of type Unit.
func IsAllUnits(list []Object) bool {
	if len(list) == 0 {
		return false
	}
	for _, v := range list {
		if _, ok := v.(Unit); !ok {
			return false
		}
	}
	return true
}

func NewUnitGroup(id string, list ...Unit) *UnitGroup {
	return &UnitGroup{id: id, list: list}
}

var (
	_ objectGroup    = &UnitGroup{}
	_ Mobile         = &UnitGroup{}
	_ OffensiveGroup = &UnitGroup{}
)

type UnitGroup struct {
	id   string
	list []Unit
}

func (g *UnitGroup) ID() string {
	if g == nil {
		return ""
	}
	return g.id
}

func (g *UnitGroup) String() string {
	if id := g.ID(); id != "" {
		return fmt.Sprintf("UnitGroup(%s)", id)
	}
	return fmt.Sprintf("UnitGroup(%d)", len(g.list))
}

func (g *UnitGroup) Units() []Unit {
	if g == nil {
		return nil
	}
	return g.list
}

func (g *UnitGroup) Enable(enable bool) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Enable(enable)
	}
}

func (g *UnitGroup) SetOwner(owner ObjectWrapper) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.SetOwner(owner)
	}
}

func (g *UnitGroup) Delete() {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Delete()
	}
}

func (g *UnitGroup) Destroy() {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Destroy()
	}
}

func (g *UnitGroup) Toggle() bool {
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

func (g *UnitGroup) SetPos(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.SetPos(pos)
	}
}

func (g *UnitGroup) Push(vec types.Pointf, force float32) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Push(vec, force)
	}
}

func (g *UnitGroup) PushTo(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.PushTo(pos)
	}
}

func (g *UnitGroup) MoveTo(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.MoveTo(pos)
	}
}

func (g *UnitGroup) WalkTo(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.WalkTo(pos)
	}
}

func (g *UnitGroup) LookAt(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.LookAt(pos)
	}
}

func (g *UnitGroup) LookAtDir(dir int) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.LookAtDir(dir)
	}
}

func (g *UnitGroup) LookAngle(ang int) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.LookAngle(ang)
	}
}

func (g *UnitGroup) Freeze(freeze bool) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Freeze(freeze)
	}
}

func (g *UnitGroup) Wander() {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Wander()
	}
}

func (g *UnitGroup) Return() {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Return()
	}
}

func (g *UnitGroup) Idle() {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Idle()
	}
}

func (g *UnitGroup) Follow(obj Positioner) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Follow(obj)
	}
}

func (g *UnitGroup) Flee(obj Positioner, dur Duration) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Flee(obj, dur)
	}
}

func (g *UnitGroup) SetAggression(val float32) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.SetAggression(val)
	}
}

func (g *UnitGroup) SetRetreatLevel(val float32) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.SetRetreatLevel(val)
	}
}

func (g *UnitGroup) SetRegroupLevel(val float32) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.SetRegroupLevel(val)
	}
}

func (g *UnitGroup) Attack(obj Positioner) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Attack(obj)
	}
}

func (g *UnitGroup) HitMelee(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.HitMelee(pos)
	}
}

func (g *UnitGroup) HitRanged(pos types.Pointf) {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.HitRanged(pos)
	}
}

func (g *UnitGroup) Guard() {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Guard()
	}
}

func (g *UnitGroup) Hunt() {
	if g == nil {
		return
	}
	for _, v := range g.list {
		v.Hunt()
	}
}
