package nox

import (
	"time"

	"nox/v1/client/system/parsecmd"
	"nox/v1/common/log"
	"nox/v1/common/object"
	"nox/v1/common/types"
	"nox/v1/server/script"
)

var scriptLog = log.New("script")

func scriptTick() {
	luaScriptTick()
}

func scriptOnEvent(event script.EventType) {
	scriptLog.Printf("event: %q", event)

	// The global logic is the following:
	// - MapEntry: give the script a chance to init the map itself.
	// - OnPlayerJoin: called for each player so script can create associated object and variables.
	// - MapExit: called _before_ OnPlayerLeave to give the script a chance to see the map results with all players who made it till the end.
	// - OnPlayerLeave: called for each player in case the script handles results per-player rather than per-game.

	// TODO: handle OnPlayerAFK

	noxscriptOnEvent(event)
	luaOnEvent(event)

	switch event {
	case script.EventMapEntry:
		// TODO: we "rejoin" existing players here because the engine will actually keep all player objects
		//       after map change ideally we should find the place where it resets their
		for _, p := range getPlayers() {
			callOnPlayerJoin(p)
		}
	case script.EventMapExit:
		// TODO: same as above: we make players "leave" when the map changes, so scripts can run their player logic
		for _, p := range getPlayers() {
			callOnPlayerLeave(p)
		}
	}
	switch event {
	// TODO: change to EventMapShutdown and make sure it triggers
	//       actually, EventMapShutdown is called when saving game when the map _isn't_ shutting down
	//       so probably worth adding a new event that triggers at the right time
	case script.EventMapExit:
		luaShutdown()
	}
}

type noxScript struct{}

func (noxScript) Frame() int {
	return int(gameFrame())
}

func (noxScript) Time() time.Duration {
	sec := float64(gameFrame()) / float64(gameFPS())
	return time.Duration(sec) * time.Second
}

func (noxScript) BlindPlayers(blind bool) {
	BlindPlayers(blind)
}

func (noxScript) CinemaPlayers(v bool) {
	CinemaPlayers(v)
}

func (noxScript) Players() []script.Player {
	list := getPlayers()
	out := make([]script.Player, 0, len(list))
	for _, p := range list {
		out = append(out, p)
	}
	return out
}

func (noxScript) HostPlayer() script.Player {
	return HostPlayer()
}

func (noxScript) OnPlayerJoin(fnc func(p script.Player)) {
	OnPlayerJoin(fnc)
}

func (noxScript) OnPlayerLeave(fnc func(p script.Player)) {
	OnPlayerLeave(fnc)
}

func (noxScript) ObjectTypeByID(id string) script.ObjectType {
	tp := getObjectTypeByID(id)
	if tp == nil {
		return nil
	}
	return tp
}

func (noxScript) ObjectByID(id string) script.Object {
	obj := getObjectByID(id)
	if obj == nil {
		return nil
	}
	if obj.Class().Has(object.MaskUnits) {
		return obj.AsUnit()
	}
	return obj
}

func (noxScript) ObjectGroupByID(id string) *script.ObjectGroup {
	g := getObjectGroupByID(id)
	if g == nil {
		return nil
	}
	return g
}

func (noxScript) WaypointByID(id string) script.Waypoint {
	w := getWaypointByID(id)
	if w == nil {
		return nil
	}
	return w
}

func (noxScript) WaypointGroupByID(id string) *script.WaypointGroup {
	g := getWaypointGroupByID(id)
	if g == nil {
		return nil
	}
	return g
}

func (noxScript) WallAt(pos types.Pointf) script.Wall {
	w := getWallAt(pos)
	if w == nil {
		return nil
	}
	return w
}

func (noxScript) WallNear(pos types.Pointf) script.Wall {
	w := getWallNear(pos)
	if w == nil {
		return nil
	}
	return w
}

func (noxScript) WallAtGrid(pos types.Point) script.Wall {
	w := getWallAtGrid(pos)
	if w == nil {
		return nil
	}
	return w
}

func (noxScript) WallGroupByID(id string) *script.WallGroup {
	return getWallGroupByID(id)
}

type scriptConsole parsecmd.Color

func (c scriptConsole) Print(text string) {
	consolePrintf(parsecmd.Color(c), "%s", text)
}

func (noxScript) Console(error bool) script.Printer {
	if error {
		return scriptConsole(parsecmd.ColorLightRed)
	}
	return scriptConsole(parsecmd.ColorYellow)
}

type scriptGlobalPrint struct{}

func (scriptGlobalPrint) Print(text string) {
	PrintToPlayers(text)
}

func (noxScript) Global() script.Printer {
	return scriptGlobalPrint{}
}
