package lua

import (
	"bytes"
	"os"
	"path/filepath"
	"strings"

	"github.com/yuin/gopher-lua"

	"nox/v1/common/fs"
	"nox/v1/common/log"
	"nox/v1/server/script"
	"nox/v1/server/script/lua/mapv0"
)

var (
	Log = log.New("lua")
)

var _ script.VM = (*VM)(nil)

type VM struct {
	g      script.Game
	s      *lua.LState
	dir    string
	timers *script.Timers
	buf    bytes.Buffer
	pkg    map[string]*lua.LTable
}

func NewVM(g script.Game, dir string) *VM {
	vm := &VM{
		g: g, dir: dir,
		s: lua.NewState(lua.Options{
			SkipOpenLibs: true,
		}),
		timers: script.NewTimers(g),
		pkg:    make(map[string]*lua.LTable),
	}
	vm.initLibs()
	return vm
}

func (vm *VM) InitDefault() {
	if err := vm.Exec(`Nox = require("Nox.Map.Script.v0")`); err != nil {
		panic(err)
	}
}

func (vm *VM) Exec(s string) error {
	return vm.s.DoString(s)
}

func (vm *VM) ExecFile(path string) error {
	path = fs.Normalize(path)
	err := vm.s.DoFile(path)
	if e, ok := err.(*lua.ApiError); ok {
		if os.IsNotExist(e.Cause) {
			return e.Cause
		}
	}
	return err
}

func (vm *VM) OnEvent(typ script.EventType) {
	if fnc, ok := vm.s.GetGlobal("On" + string(typ)).(*lua.LFunction); ok {
		vm.s.Push(fnc)
		vm.s.Call(0, 0)
	}
}

func (vm *VM) OnFrame() {
	vm.timers.Tick()
	if fnc, ok := vm.s.GetGlobal("OnFrame").(*lua.LFunction); ok {
		vm.s.Push(fnc)
		vm.s.Call(0, 0)
	}
}

func (vm *VM) Close() error {
	vm.s.Close()
	return nil
}

func (vm *VM) initLibs() {
	ls := vm.s
	for _, lib := range []struct {
		name string
		init lua.LGFunction
	}{
		{lua.BaseLibName, lua.OpenBase},
		{lua.TabLibName, lua.OpenTable},
		{lua.StringLibName, lua.OpenString},
		{lua.MathLibName, lua.OpenMath},
	} {
		ls.Push(ls.NewFunction(lib.init))
		ls.Push(lua.LString(lib.name))
		ls.Call(1, 0)
	}
	for _, name := range []string{
		"dofile", "load", "loadfile", "loadstring",
		"module", "require",
	} {
		ls.SetGlobal(name, lua.LNil)
	}
	ls.SetGlobal("print", ls.NewFunction(vm.luaPrint))
	ls.SetGlobal("require", ls.NewFunction(vm.luaRequire))
}

func (vm *VM) luaPrint(L *lua.LState) int {
	p := vm.g.Console()
	vm.buf.Reset()
	top := L.GetTop()
	for i := 1; i <= top; i++ {
		vm.buf.WriteString(L.ToStringMeta(L.Get(i)).String())
		if i != top {
			vm.buf.WriteString("\t")
		}
	}
	vm.buf.WriteString("\n")
	text := vm.buf.String()
	Log.Print(strings.TrimSpace(text))
	p.Print(text)
	return 0
}

func (vm *VM) Error(L *lua.LState, err error) int {
	if L == nil {
		L = vm.s
	}
	L.Error(lua.LString(err.Error()), 0)
	return 0
}

func (vm *VM) luaRequire(L *lua.LState) int {
	name := L.CheckString(1)
	if t, ok := vm.pkg[name]; ok {
		if t == nil {
			L.Push(lua.LNil)
		} else {
			L.Push(t)
		}
		return 1
	}
	var (
		t  *lua.LTable
		ok bool
	)
	switch name {
	// builtin modules
	case "Nox.Map.Script.v0":
		t = mapv0.New(vm.s, vm.timers, vm.g)
	default:
		// check if there are modules with this name in local dir
		// make sure to clean paths, so the script cannot escape the sandbox
		if vm.dir != "" && !filepath.IsAbs(name) {
			path := filepath.Clean(name)
			path = strings.TrimLeft(path, "./\\~")
			path = filepath.Join(vm.dir, path+".lua")
			base := filepath.Base(path)
			Log.Printf("loading script %q", base)
			f, err := fs.Open(path)
			if err != nil {
				Log.Println(err)
				return vm.Error(L, err)
			}
			defer f.Close()
			fn, err := L.Load(f, base)
			if err != nil {
				Log.Println(err)
				return vm.Error(L, err)
			}
			L.Push(fn)
			err = L.PCall(0, 1, nil)
			if err != nil {
				Log.Println(err)
				return vm.Error(L, err)
			}
			ok = true
			t = L.OptTable(-1, nil)
		}
	}
	if t == nil && !ok {
		L.Push(lua.LNil)
		return 1
	}
	Log.Printf("loaded module %q", name)
	vm.pkg[name] = t
	L.Push(t)
	return 1
}
