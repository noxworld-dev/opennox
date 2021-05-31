package mapv0_test

import (
	"testing"
	"time"

	"github.com/stretchr/testify/require"
	glua "github.com/yuin/gopher-lua"

	"nox/v1/common/types"
	"nox/v1/server/script"
	"nox/v1/server/script/lua"
	"nox/v1/server/script/lua/mapv0"
)

func newGame(t testing.TB) *testGame {
	g := &testGame{t: t, frame: 1, time: time.Second}
	lvm := lua.NewVM(g, "", glua.Options{
		IncludeGoStackTrace: true,
	})
	lvm.InitAPI("Nox", mapv0.New)
	g.vm = lvm
	return g
}

type testGame struct {
	script.BaseGame
	vm        *lua.VM
	t         testing.TB
	frame     int
	time      time.Duration
	walls     map[types.Point]script.Wall
	waypoints map[string]script.Waypoint
	objects   map[string]script.Object
}

func (g *testGame) Tick() {
	g.frame++
	g.time += 33 * time.Millisecond
	g.vm.OnFrame()
}

func (g *testGame) Frame() int {
	return g.frame
}

func (g *testGame) Time() time.Duration {
	return g.time
}

func (g *testGame) Exec(s string) {
	err := g.vm.Exec(s)
	require.NoError(g.t, err)
}
