package script

import (
	"nox/v1/common/types"
)

type Game interface {
	TimeSource

	// BlindPlayers blinds or unblinds all players.
	BlindPlayers(blind bool)
	// CinemaPlayers enables a wide-screen "cinema" mode for all players.
	CinemaPlayers(v int)
	// Players returns a list of all players.
	Players() []Player
	// HostPlayer returns the host player.
	HostPlayer() Player

	// ObjectTypeByID finds an object type by ID.
	ObjectTypeByID(id string) ObjectType
	// ObjectByID finds an object by ID.
	ObjectByID(id string) Object
	// ObjectGroupByID finds an object group by ID.
	ObjectGroupByID(id string) *ObjectGroup

	// WaypointByID finds a waypoint by ID.
	WaypointByID(id string) Waypoint

	// WallAt finds a wall by its position.
	WallAt(pos types.Pointf) Wall
	// WallNear finds a wall near the position.
	WallNear(pos types.Pointf) Wall
	// WallAtGrid finds a wall by its grid position.
	WallAtGrid(pos types.Point) Wall
	// WallGroupByID finds a wall group by ID.
	WallGroupByID(id string) *WallGroup

	Global() Printer
	Console() Printer

	// TODO: audio
}
