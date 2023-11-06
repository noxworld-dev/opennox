package opennox

import (
	"image"
	"time"

	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

// TODO: This is only for old LUA compatibility.

type scrObject struct {
	*Object
}

func (obj scrObject) GetObject() script.Object {
	if obj.Object == nil {
		return nil
	}
	return obj
}

func (obj scrObject) SetOwner(owner script.ObjectWrapper) {
	if owner == nil {
		obj.Object.SetOwner(nil)
		return
	}
	own := owner.GetObject().(server.Obj).SObj()
	obj.SObj().SetOwner(own)
}

func (obj scrObject) Owner() script.Object {
	if obj.Object == nil {
		return nil
	}
	p := obj.Object.Owner()
	if p == nil {
		return nil
	}
	return scrObject{p}
}

func (obj scrObject) CanSee(obj2 script.Object) bool {
	if obj.Object == nil || obj2 == nil {
		return false
	}
	return obj.Object.CanSee(toObject(obj2.(server.Obj)))
}

func (p *Player) Unit() script.Unit {
	if p == nil {
		return nil
	}
	return scrObject{p.UnitC()}
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
	list := s.s.GetPlayers()
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
	return scrObject{asObjectS(noxServer.createObject(t.ObjectType, p))}
}

func (s noxScriptImpl) ObjectTypeByID(id string) script.ObjectType {
	tp := s.s.Types.ByID(id)
	if tp == nil {
		return nil
	}
	return noxScriptObjType{tp}
}

func (s noxScriptImpl) ObjectByID(id string) script.Object {
	obj := s.s.Objs.GetObjectByID(id)
	if obj == nil {
		return nil
	}
	if obj.Class().HasAny(object.MaskUnits) {
		return scrObject{asObjectS(obj)}
	}
	return scrObject{asObjectS(obj)}
}

func (s noxScriptImpl) ObjectGroupByID(id string) *script.ObjectGroup {
	g := s.s.getObjectGroupByID(id)
	if g == nil {
		return nil
	}
	return g
}

func (s noxScriptImpl) WaypointByID(id string) script.Waypoint {
	w := s.s.WPs.ByID(id)
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
	w := s.s.Walls.GetWallAt(pos)
	if w == nil {
		return nil
	}
	return asWallS(w)
}

func (s noxScriptImpl) WallNear(pos types.Pointf) script.Wall {
	w := s.s.Walls.GetWallNear(pos)
	if w == nil {
		return nil
	}
	return asWallS(w)
}

func (s noxScriptImpl) WallAtGrid(pos image.Point) script.Wall {
	w := s.s.Walls.GetWallAtGrid(pos)
	if w == nil {
		return nil
	}
	return asWallS(w)
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
	legacy.PrintToPlayers(text)
}

func (noxScriptImpl) Global() script.Printer {
	return scriptGlobalPrint{}
}
