package script

type Player interface {
	ObjectWrapper // proxies to Unit
	Positionable  // proxies to Unit
	Named
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
