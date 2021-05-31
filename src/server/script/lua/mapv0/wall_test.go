package mapv0_test

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/types"
	"nox/v1/common/wall"
	"nox/v1/server/script"
)

type testWall struct {
	g       *testGame
	pos     types.Point
	enabled bool
	deleted bool
	dead    bool
}

func (g *testGame) WallAt(pos types.Pointf) script.Wall {
	return g.WallAtGrid(wall.PosToGrid(pos))
}

func (g *testGame) WallNear(pos types.Pointf) script.Wall {
	return g.WallAtGrid(wall.PosToGrid(pos))
}

func (g *testGame) WallAtGrid(pos types.Point) script.Wall {
	return g.walls[pos]
}

func (g *testGame) newWall(x, y int) *testWall {
	obj := &testWall{
		g:       g,
		pos:     types.Point{X: x, Y: y},
		enabled: true,
	}
	if g.walls == nil {
		g.walls = make(map[types.Point]script.Wall)
	}
	g.walls[obj.pos] = obj
	return obj
}

func (v *testWall) String() string {
	pos := v.GridPos()
	return fmt.Sprintf("Wall(%d, %d)", pos.X, pos.Y)
}

func (v *testWall) IsEnabled() bool {
	return v.enabled
}

func (v *testWall) Enable(enable bool) {
	if v.deleted {
		return
	}
	v.enabled = enable
}

func (v *testWall) Pos() types.Pointf {
	return wall.GridToPos(v.pos)
}

func (v *testWall) GridPos() types.Point {
	return v.pos
}

func (v *testWall) Delete() {
	if v.deleted {
		return
	}
	v.deleted = true
	delete(v.g.walls, v.pos)
}

func (v *testWall) Destroy() {
	v.dead = true
}

func TestWallString(t *testing.T) {
	g := newGame(t)
	g.newWall(1, 2)

	g.Exec(`
	local v = Nox.Wall(1, 2)

	if v:__tostring() ~= "Wall(1, 2)" then
		error("invalid string conversion:" .. v:__tostring())
	end
`)
}

func TestWallGridPos(t *testing.T) {
	g := newGame(t)
	g.newWall(1, 2)

	g.Exec(`
	local v = Nox.Wall(1, 2)

	local xi = v.xi
	local yi = v.yi
	if xi ~= 1 then
		error("invalid X in field: " .. xi)
	end
	if yi ~= 2 then
		error("invalid Y in field: " .. yi)
	end

	xi = xi + 1
	yi = yi + 1

	xi, yi = v:GridPos()
	if xi ~= 1 then
		error("invalid X in GridPos")
	end
	if yi ~= 2 then
		error("invalid Y in GridPos")
	end
`)
}

func TestWallPos(t *testing.T) {
	g := newGame(t)
	g.newWall(1, 2)

	g.Exec(`
	local v = Nox.Wall(1, 2)

	local x = v.x
	local y = v.y
	if x ~= 23 then
		error("invalid X in field:" .. x)
	end
	if y ~= 46 then
		error("invalid Y in field:" .. y)
	end

	x = x + 1
	y = y + 1

	x, y = v:Pos()
	if x ~= 23 then
		error("invalid X in Pos")
	end
	if y ~= 46 then
		error("invalid Y in Pos")
	end
`)
}

func TestWallDestroy(t *testing.T) {
	g := newGame(t)
	v := g.newWall(1, 2)

	g.Exec(`
	v = Nox.Wall(1, 2)
	v:Destroy()
`)
	require.True(t, v.dead)
	v.dead = false

	g.Exec(`
	v:Break()
`)
	require.True(t, v.dead)
	v.dead = false

	g.Exec(`
	v:Kill()
`)
	require.True(t, v.dead)
	v.dead = false
}

func TestWallEnabled(t *testing.T) {
	g := newGame(t)
	v := g.newWall(1, 2)

	g.Exec(`
	v = Nox.Wall(1, 2)

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

func TestWallToggle(t *testing.T) {
	g := newGame(t)
	v := g.newWall(1, 2)

	g.Exec(`
	v = Nox.Wall(1, 2)

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
