package nox

import (
	"context"
	"os"
	"path/filepath"
	"strings"

	"nox/v1/common/console"
	"nox/v1/common/datapath"
	"nox/v1/common/maps"
	"nox/v1/server/script"
	"nox/v1/server/script/lua"
)

type scriptLUA struct {
	curmap string
	vm     *lua.VM
}

func init() {
	noxConsole.Register(&console.Command{
		Token: "lua", HelpID: "luahelp",
		Help:  "execute LUA command",
		Flags: console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if len(tokens) == 0 {
				return false
			}
			if noxServer.lua.vm == nil {
				c.Print(console.ColorRed, "LUA is not running")
				return true
			}
			code := strings.Join(tokens, " ")
			if err := noxServer.lua.vm.Exec(code); err != nil {
				c.Printf(console.ColorRed, "LUA error: %v", err)
			}
			return true
		},
	})
}

func (s *Server) runMapLUA(code string) {
	if s.lua.vm == nil {
		return
	}
	if len(code) == 0 {
		return
	}
	if err := s.lua.vm.Exec(code); err != nil {
		lua.Log.Printf("error: %v", err)
	}
}

func (s *Server) luaScriptTick() {
	if s.lua.vm == nil {
		return
	}
	s.lua.vm.OnFrame()
}

func (s *Server) luaMaybeInitMap() {
	mp := s.nox_server_currentMapGetFilename_409B30()
	if mp == s.lua.curmap {
		return
	}
	s.luaShutdown()
	lua.Log.Printf("loading script for map %q", mp)
	s.lua.curmap = mp
	mp = strings.TrimSuffix(mp, maps.Ext)
	mapDir := datapath.Data(maps.Dir, mp)
	s.lua.vm = lua.NewVM(noxScript{s}, mapDir)
	lname := mp + ".lua"
	err := s.lua.vm.ExecFile(filepath.Join(mapDir, lname))
	if os.IsNotExist(err) {
		lua.Log.Printf("no lua script for map: %q", lname)
		s.lua.vm.InitDefault()
		return
	} else if err != nil {
		lua.Log.Printf("error opening script %q: %v (%T)", filepath.Join(maps.Dir, mp, lname), err, err)
		return
	}
	lua.Log.Printf("map script loaded: %q", lname)
}

func (s *Server) luaShutdown() {
	if s.lua.vm != nil {
		lua.Log.Printf("stopping script for map %q", s.lua.curmap)
		_ = s.lua.vm.Close()
		s.lua.vm = nil
	}
	s.lua.curmap = ""
}

func (s *Server) luaOnEvent(event script.EventType) {
	switch event {
	case script.EventMapInitialize,
		script.EventMapEntry:
		s.luaMaybeInitMap()
	}
	if s.lua.vm != nil {
		s.lua.vm.OnEvent(event)
	}
}
