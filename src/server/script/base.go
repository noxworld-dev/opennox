package script

import "fmt"

// Identifiable is an interface for objects with unique string ID.
type Identifiable interface {
	fmt.Stringer
	// ID of the object.
	ID() string
}

// Named is an interface for objects with a human-readable name.
type Named interface {
	fmt.Stringer
	// Name returns a name of the item.
	Name() string
}

// Deleter is an interface for objects that can be deleted.
type Deleter interface {
	// Delete the object permanently.
	Delete()
}

// Printer is an interface for printing messages.
type Printer interface {
	// Print a text message.
	Print(text string)
}

// EnableSetter is an interface for objects that can be enabled and disabled.
type EnableSetter interface {
	// Enable or disable the object.
	Enable(enable bool)
}

// Toggler is an interface for objects that can be toggled.
type Toggler interface {
	// Toggle the object's enabled state.
	// It returns the new state after toggling the object.
	Toggle() bool
}

// Enabler is an interface for objects that can be enabled or disabled.
type Enabler interface {
	// IsEnabled checks if object is currently enabled.
	IsEnabled() bool
	EnableSetter
}

// Toggle is a helper to toggle the object's enabled state.
// It returns the new state after toggling the object.
func Toggle(obj Enabler) bool {
	if t, ok := obj.(Toggler); ok {
		return t.Toggle()
	}
	obj.Enable(!obj.IsEnabled())
	return obj.IsEnabled()
}

// Lockable is an interface for objects that can be locked.
type Lockable interface {
	// IsLocked checks if object is currently locked.
	IsLocked() bool
	// Lock or unlock the object.
	Lock(lock bool)
}

// ToggleLock is a helper to toggle the object's lock state.
// It returns the new state after toggling the object.
func ToggleLock(obj Lockable) bool {
	obj.Lock(!obj.IsLocked())
	return obj.IsLocked()
}

// Destroyable is an interface for objects can be broken, destroyed or killed.
type Destroyable interface {
	// Destroy this object. Implies reducing health to zero and playing break/death effects.
	Destroy()
}

// Breakable is an interface for objects that has health and can be broken.
type Breakable interface {
	Destroyable
	// Health returns current and max health of the object.
	Health() (cur, max int)
	// SetHealth sets the amount of health of the object. It will be limited by max health.
	SetHealth(v int)
	// SetMaxHealth sets the maximal amount of health of the object. It will be adjust health accordingly.
	SetMaxHealth(v int)
}

// Owned is an interface for objects with an owner.
type Owned interface {
	Owner() Object
}

// OwnerSetter is an interface for objects that can be assigned an owner.
type OwnerSetter interface {
	SetOwner(owner ObjectWrapper)
}

// Ownable is an interface for objects that has and can be assigned an owner.
type Ownable interface {
	Owned
	OwnerSetter
}

type Trigger interface {
	OnTriggerActivate(fnc func(obj Object))
	OnTriggerDeactivate(fnc func())
}
