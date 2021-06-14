package main

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
	noxscriptOnEvent(event)
	luaOnEvent(event)
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
