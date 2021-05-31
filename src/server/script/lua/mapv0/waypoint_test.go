package mapv0_test

import (
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/types"
	"nox/v1/server/script"
)

type testWaypoint struct {
	g       *testGame
	id      string
	pos     types.Pointf
	enabled bool
	dead    bool
}

func (g *testGame) WaypointByID(id string) script.Waypoint {
	return g.waypoints[id]
}

func (g *testGame) newWaypoint(id string, x, y float32) *testWaypoint {
	obj := &testWaypoint{
		g: g, id: id,
		pos:     types.Pointf{X: x, Y: y},
		enabled: true,
	}
	if g.waypoints == nil {
		g.waypoints = make(map[string]script.Waypoint)
	}
	g.waypoints[id] = obj
	return obj
}

func (v *testWaypoint) ID() string {
	return v.id
}

func (v *testWaypoint) String() string {
	return "Waypoint(" + v.ID() + ")"
}

func (v *testWaypoint) IsEnabled() bool {
	return v.enabled
}

func (v *testWaypoint) Enable(enable bool) {
	v.enabled = enable
}

func (v *testWaypoint) Pos() types.Pointf {
	return v.pos
}

func (v *testWaypoint) SetPos(pos types.Pointf) {
	v.pos = pos
}

func (v *testWaypoint) Destroy() {
	v.dead = true
}

func TestWaypointID(t *testing.T) {
	g := newGame(t)
	g.newWaypoint("Test", 1, 2)

	g.Exec(`
	local v = Nox.Waypoint("Test")

	if v.id ~= "Test" then
		error("invalid ID field")
	end

	if v:__tostring() ~= "Waypoint(Test)" then
		error("invalid string conversion")
	end
`)
}

func TestWaypointPos(t *testing.T) {
	g := newGame(t)
	g.newWaypoint("Test", 1, 2)

	g.Exec(`
	local v = Nox.Waypoint("Test")

	local x = v.x
	local y = v.y
	if x ~= 1 then
		error("invalid X in field")
	end
	if y ~= 2 then
		error("invalid Y in field")
	end

	x = x + 1
	y = y + 1

	x, y = v:Pos()
	if x ~= 1 then
		error("invalid X in Pos")
	end
	if y ~= 2 then
		error("invalid Y in Pos")
	end
`)
}

func TestWaypointSetPos(t *testing.T) {
	g := newGame(t)
	obj1 := g.newWaypoint("Test", 1, 2)
	obj2 := g.newWaypoint("Test2", 3, 4)

	g.Exec(`
	local v1 = Nox.Waypoint("Test")
	local v2 = Nox.Waypoint("Test2")
	v1:SetPos(v2)
	v2:SetPos(5, 6):SetPos(7, 8)
	v2.x = v2.x + 1
	v2.y = v2.y + 2
`)
	require.Equal(t, types.Pointf{X: 3, Y: 4}, obj1.pos)
	require.Equal(t, types.Pointf{X: 8, Y: 10}, obj2.pos)
}

func TestWaypointEnabled(t *testing.T) {
	g := newGame(t)
	v := g.newWaypoint("Test", 1, 2)

	g.Exec(`
	v = Nox.Waypoint("Test")

	if not v.enabled then
		error("not enabled")
	end

	v.enabled = false

	if v.enabled then
		error("not disabled")
	end
`)
	require.False(t, v.enabled)

	g.Exec(`
	v.enabled = not v.enabled
`)
	require.True(t, v.enabled)
}

func TestWaypointToggle(t *testing.T) {
	g := newGame(t)
	v := g.newWaypoint("Test", 1, 2)

	g.Exec(`
	v = Nox.Waypoint("Test")

	if not v.enabled then
		error("not enabled")
	end

	v:Toggle()

	if v.enabled then
		error("not disabled")
	end
`)
	require.False(t, v.enabled)

	g.Exec(`
	v:Toggle()
`)
	require.True(t, v.enabled)
}
