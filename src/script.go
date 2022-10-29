package opennox

import (
	"image"
	"time"

	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox-lib/console"

	"github.com/noxworld-dev/opennox/v1/server"
)

var scriptLog = log.New("script")

func (s *Server) scriptTick() {
	s.luaScriptTick()
}

func (s *Server) scriptOnEvent(event script.EventType) {
	scriptLog.Printf("event: %q", event)

	// The global logic is the following:
	// - MapEntry: give the script a chance to init the map itself.
	// - OnPlayerJoin: called for each player so script can create associated object and variables.
	// - MapExit: called _before_ OnPlayerLeave to give the script a chance to see the map results with all players who made it till the end.
	// - OnPlayerLeave: called for each player in case the script handles results per-player rather than per-game.

	// TODO: handle OnPlayerAFK

	s.noxScript.OnEvent(event)
	s.luaOnEvent(event)

	switch event {
	case script.EventMapEntry:
		// TODO: we "rejoin" existing players here because the engine will actually keep all player objects
		//       after map change ideally we should find the place where it resets their
		for _, p := range s.getPlayers() {
			s.callOnPlayerJoin(p)
		}
	case script.EventMapExit:
		// TODO: same as above: we make players "leave" when the map changes, so scripts can run their player logic
		for _, p := range s.getPlayers() {
			s.callOnPlayerLeave(p)
		}
	}
	switch event {
	// TODO: change to EventMapShutdown and make sure it triggers
	//       actually, EventMapShutdown is called when saving game when the map _isn't_ shutting down
	//       so probably worth adding a new event that triggers at the right time
	case script.EventMapExit:
		s.luaShutdown()
	}
}

type noxScriptImpl struct {
	s *Server
}

func (s noxScriptImpl) Frame() int {
	return int(s.s.Frame())
}

func (s noxScriptImpl) Time() time.Duration {
	sec := float64(s.s.Frame()) / float64(s.s.TickRate())
	return time.Duration(sec) * time.Second
}

func (noxScriptImpl) BlindPlayers(blind bool) {
	BlindPlayers(blind)
}

func (noxScriptImpl) CinemaPlayers(v bool) {
	noxServer.CinemaPlayers(v)
}

func (s noxScriptImpl) Players() []script.Player {
	list := s.s.getPlayers()
	out := make([]script.Player, 0, len(list))
	for _, p := range list {
		out = append(out, p)
	}
	return out
}

func (noxScriptImpl) HostPlayer() script.Player {
	return HostPlayer()
}

func (s noxScriptImpl) OnPlayerJoin(fnc func(p script.Player)) {
	s.s.OnPlayerJoin(fnc)
}

func (s noxScriptImpl) OnPlayerLeave(fnc func(p script.Player)) {
	s.s.OnPlayerLeave(fnc)
}

type noxScriptObjType struct {
	*server.ObjectType
}

func (t noxScriptObjType) CreateObject(p types.Pointf) script.Object {
	return noxServer.createObject(t.ObjectType, p)
}

func (s noxScriptImpl) ObjectTypeByID(id string) script.ObjectType {
	tp := s.s.ObjectTypeByID(id)
	if tp == nil {
		return nil
	}
	return noxScriptObjType{tp}
}

func (s noxScriptImpl) ObjectByID(id string) script.Object {
	obj := s.s.getObjectByID(id)
	if obj == nil {
		return nil
	}
	if obj.Class().HasAny(object.MaskUnits) {
		return obj.AsUnit()
	}
	return obj
}

func (s noxScriptImpl) ObjectGroupByID(id string) *script.ObjectGroup {
	g := s.s.getObjectGroupByID(id)
	if g == nil {
		return nil
	}
	return g
}

func (s noxScriptImpl) WaypointByID(id string) script.Waypoint {
	w := s.s.getWaypointByID(id)
	if w == nil {
		return nil
	}
	return w
}

func (s noxScriptImpl) WaypointGroupByID(id string) *script.WaypointGroup {
	g := s.s.getWaypointGroupByID(id)
	if g == nil {
		return nil
	}
	return g
}

func (s noxScriptImpl) WallAt(pos types.Pointf) script.Wall {
	w := s.s.getWallAt(pos)
	if w == nil {
		return nil
	}
	return w
}

func (s noxScriptImpl) WallNear(pos types.Pointf) script.Wall {
	w := s.s.getWallNear(pos)
	if w == nil {
		return nil
	}
	return w
}

func (s noxScriptImpl) WallAtGrid(pos image.Point) script.Wall {
	w := s.s.getWallAtGrid(pos)
	if w == nil {
		return nil
	}
	return w
}

func (s noxScriptImpl) WallGroupByID(id string) *script.WallGroup {
	return s.s.getWallGroupByID(id)
}

type scriptConsole console.Color

func (c scriptConsole) Print(text string) {
	noxConsole.Print(console.Color(c), text)
}

func (noxScriptImpl) Console(error bool) script.Printer {
	if error {
		return scriptConsole(console.ColorLightRed)
	}
	return scriptConsole(console.ColorYellow)
}

func (noxScriptImpl) AudioEffect(name string, pos script.Positioner) {
	// FIXME: trigger audio event
}

type scriptGlobalPrint struct{}

func (scriptGlobalPrint) Print(text string) {
	PrintToPlayers(text)
}

func (noxScriptImpl) Global() script.Printer {
	return scriptGlobalPrint{}
}
