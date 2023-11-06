package opennox

import (
	"context"
	"fmt"
	"net/http"
	"path/filepath"
	"reflect"
	"strings"

	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/maps"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/strman"
	// register script runtimes
	_ "github.com/noxworld-dev/opennox-lib/script/eval"
	_ "github.com/noxworld-dev/opennox-lib/script/lua"
)

var scriptLog = log.New("script")

func init() {
	for _, rt := range script.VMRuntimes() {
		rt := rt
		noxConsole.Register(&console.Command{
			Token: rt.Name, HelpID: strman.ID(rt.Name + "help"),
			Help:  "execute " + rt.Title + " command",
			Flags: console.Server | console.Cheat,
			Raw:   true,
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
		func() {
			defer func() {
				if r := recover(); r != nil {
					scriptLog.Printf("panic in OnFrame: %v", r)
				}
			}()
			vm.OnFrame()
		}()
	}
	s.callOnScriptFrame()
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
			rt.Log.Println("error opening script %q: %v", filepath.Join(maps.Dir, mp), err)
			noxConsole.Print(console.ColorRed, fmt.Sprintf("ERROR: %q: %v", filepath.Join(maps.Dir, mp), err))
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
		func() {
			defer func() {
				if r := recover(); r != nil {
					scriptLog.Printf("panic in event: %q: %v", event, r)
				}
			}()
			vm.OnEvent(event)
		}()
	}
	s.callOnMapEvent(event)

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
}
