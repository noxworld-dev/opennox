package main

import "C"
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

func (noxScript) CinemaPlayers(v int) {
	panic("implement me")
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
	// TODO: better way
	for _, p := range getPlayers() {
		if p.IsHost() {
			return p
		}
	}
	return nil
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
	panic("implement me")
}

func (noxScript) WaypointByID(id string) script.Waypoint {
	panic("implement me")
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

type scriptConsole struct{}

func (scriptConsole) Print(text string) {
	consolePrintf(parsecmd.ColorYellow, "%s", text)
}

func (noxScript) Console() script.Printer {
	return scriptConsole{}
}

type scriptGlobalPrint struct{}

func (scriptGlobalPrint) Print(text string) {
	// TODO: better way
	for _, p := range getPlayers() {
		p.Print(text)
	}
}

func (noxScript) Global() script.Printer {
	return scriptGlobalPrint{}
}
