package script

// ItemType is an interface that defines an item type.
type ItemType interface {
	Named
	// MaxStack returns maximal amount of this item an inventory slot can contain.
	MaxStack() int
}

// Item is an interface for generic items.
type Item interface {
	Named
	// ItemType returns a type of this item.
	ItemType() ItemType
	// Amount returns current amount of this item.
	Amount() int
	// SetAmount sets an amount of a given item.
	SetAmount(v int)
	// CanStack checks if two items can be stacked together.
	CanStack(v Item) bool
}

// Inventory is an interface for objects that can contain items.
type Inventory interface {
	// CountItem counts the number of given items in the inventory.
	CountItem(v Item) int
	// Items returns a list of all items. It ignores the stack size.
	Items() []Item
	// Gold returns amount of gold this inventory contains.
	Gold() int
	// SetGold sets the amount of gold this inventory contains.
	SetGold(v int)
}

// HasItem is a helper that checks if inventory contains a given item.
func HasItem(inv Inventory, v Item) bool {
	return inv.CountItem(v) != 0
}

// ChangeGold changes the amount of gold by a given amount.
// It returns false if it cannot be done.
func ChangeGold(inv Inventory, dv int) bool {
	val := inv.Gold() + dv
	if val < 0 {
		return false
	}
	inv.SetGold(val)
	return true
}
