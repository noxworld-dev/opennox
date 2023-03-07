package opennox

import (
	"context"
	"image"
	"net/http"
	"path/filepath"
	"reflect"
	"strings"
	"time"

	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/maps"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	// register script runtimes
	_ "github.com/noxworld-dev/opennox-lib/script/eval"
	_ "github.com/noxworld-dev/opennox-lib/script/lua"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

var scriptLog = log.New("script")

func init() {
	for _, rt := range script.VMRuntimes() {
		rt := rt
		noxConsole.Register(&console.Command{
			Token: rt.Name, HelpID: strman.ID(rt.Name + "help"),
			Help:  "execute " + rt.Title + " command",
			Flags: console.Server | console.Cheat,
			Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
				if len(tokens) == 0 {
					return false
				}
				vm := noxServer.vms.vmByName[rt.Name]
				if vm == nil {
					c.Print(console.ColorRed, rt.Title+" is not running")
					return true
				}
				code := strings.Join(tokens, " ")
				if rv, err := vm.Exec(code); err != nil {
					c.Printf(console.ColorRed, rt.Title+" error: %v", err)
				} else if rv.Kind() != reflect.Invalid {
					c.Printf(console.ColorLightBlue, "%v", rv.Interface())
				}
				return true
			},
		})
	}
}

func (s *Server) registerScriptAPIs(pref string) {
	for _, rt := range script.VMRuntimes() {
		rt := rt
		s.HTTP().HandleFunc(pref+"/"+rt.Name, func(w http.ResponseWriter, r *http.Request) {
			handlePostStr(w, r, 4096, func(code string) {
				code = strings.TrimSpace(code)
				if len(code) == 0 {
					return
				}
				apiLog.Printf("run %s: %q", rt.Name, code)
				s.QueueInLoop(context.Background(), func() {
					vm := s.vms.vmByName[rt.Name]
					if vm == nil {
						return
					}
					if _, err := vm.Exec(code); err != nil {
						rt.Log.Printf("error: %v", err)
					}
				})
			})
		})
	}
}

type scriptVMs struct {
	curmap   string
	vms      []script.VM
	vmByName map[string]script.VM
}

func (s *Server) scriptTick() {
	for _, vm := range s.vms.vms {
		vm.OnFrame()
	}
}

func (s *Server) vmsShutdown() {
	s.noxScript.resetVirtualFuncs()
	if len(s.vms.vms) != 0 {
		scriptLog.Printf("stopping script(s) for map %q", s.vms.curmap)
	}
	for _, vm := range s.vms.vms {
		_ = vm.Close()
	}
	s.vms.vms = nil
	s.vms.vmByName = nil
	s.vms.curmap = ""
}

func (s *Server) vmsMaybeInitMap() {
	mp := s.nox_server_currentMapGetFilename_409B30()
	scriptLog.Printf("check map init: %q vs %q", mp, s.vms.curmap)
	if mp == s.vms.curmap {
		return
	}
	s.vmsInitMap()
}

func (s *Server) vmsInitMap() {
	mp := s.nox_server_currentMapGetFilename_409B30()
	s.vmsShutdown()
	scriptLog.Printf("loading script(s) for map %q", mp)
	s.vms.curmap = mp
	mp = strings.TrimSuffix(mp, maps.Ext)
	mapsDir := datapath.Maps()
	s.vms.vmByName = make(map[string]script.VM)
	for _, rt := range script.VMRuntimes() {
		if rt.NewMap == nil {
			continue
		}
		vm, err := rt.NewMap(noxScriptImpl{s}, mapsDir, mp)
		if err != nil {
			rt.Log.Printf("error opening script %q: %v (%T)", filepath.Join(maps.Dir, mp), err, err)
			continue
		}
		if vm != nil {
			s.vms.vms = append(s.vms.vms, vm)
			s.vms.vmByName[rt.Name] = vm
		}
	}
	if len(s.vms.vms) != 0 {
		scriptLog.Printf("map script(s) loaded: %q", mp)
	} else {
		scriptLog.Printf("no map scripts for %q", mp)
	}
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
	switch event {
	case script.EventMapInitialize,
		script.EventMapEntry:
		s.vmsMaybeInitMap()
	}
	for _, vm := range s.vms.vms {
		vm.OnEvent(event)
	}

	switch event {
	case script.EventMapEntry:
		// TODO: we "rejoin" existing players here because the engine will actually keep all player objects
		//       after map change ideally we should find the place where it resets their
		for _, p := range s.GetPlayers() {
			s.callOnPlayerJoin(p)
		}
	case script.EventMapExit:
		// TODO: same as above: we make players "leave" when the map changes, so scripts can run their player logic
		for _, p := range s.GetPlayers() {
			s.callOnPlayerLeave(p)
		}
	}
	switch event {
	// TODO: change to EventMapShutdown and make sure it triggers
	//       actually, EventMapShutdown is called when saving game when the map _isn't_ shutting down
	//       so probably worth adding a new event that triggers at the right time
	case script.EventMapExit:
		s.vmsShutdown()
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
	obj := s.s.GetObjectByID(id)
	if obj == nil {
		return nil
	}
	if obj.Class().HasAny(object.MaskUnits) {
		return obj
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
	legacy.PrintToPlayers(text)
}

func (noxScriptImpl) Global() script.Printer {
	return scriptGlobalPrint{}
}
