package script

type Waypoint interface {
	Identifiable
	Enabler
	Movable
}

type Player interface {
	Movable // proxies to Unit
	// Name of the player.
	Name() string
	// IsHost checks if this player hosts the game.
	IsHost() bool
	Printer
	// Blind or unblind the player.
	Blind(v bool)
	// Cinema enables wide-screen "cinema" mode.
	Cinema(v int)
	// Unit that the player controls.
	Unit() Unit
}
