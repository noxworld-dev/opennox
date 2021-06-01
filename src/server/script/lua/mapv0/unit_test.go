package mapv0_test

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/types"
	"nox/v1/server/script"
)

func (g *testGame) newUnit(id string, x, y float32) *testUnit {
	obj := g.newObjectRaw(id, x, y)
	unit := &testUnit{testObject: obj}
	if id != "" {
		if g.objects == nil {
			g.objects = make(map[string]script.Object)
		}
		g.objects[id] = unit
	}
	return unit
}

var _ script.Unit = &testUnit{}

type unitState int

const (
	UnitIdle = unitState(iota)
	UnitMove
	UnitWalk
	UnitWander
	UnitReturn
	UnitFollow
	UnitFlee
	UnitAttack
	UnitHitMelee
	UnitHitRanged
	UnitGuard
	UnitHunt
)

type testUnit struct {
	*testObject
	look struct {
		pt  types.Pointf
		dir int
		ang int
	}
	frozen bool
	st     unitState
	targ   types.Pointf
	health struct {
		cur, max int
	}
	mana struct {
		cur, max int
	}
	aggr    float32
	retreat float32
	regroup float32
}

func (u *testUnit) String() string {
	return "Unit(" + u.ID() + ")"
}

func (u *testUnit) GetObject() script.Object {
	if u == nil {
		return nil
	}
	return u
}

func (u *testUnit) CanSee(obj script.Object) bool {
	panic("implement me")
}

func (u *testUnit) Health() (cur, max int) {
	return u.health.cur, u.health.max
}

func (u *testUnit) SetHealth(v int) {
	u.health.cur = v
}

func (u *testUnit) SetMaxHealth(v int) {
	u.health.cur = v
	u.health.max = v
}

func (u *testUnit) Mana() (cur, max int) {
	return u.mana.cur, u.mana.max
}

func (u *testUnit) SetMana(v int) {
	u.mana.cur = v
}

func (u *testUnit) SetMaxMana(v int) {
	u.mana.cur = v
	u.mana.max = v
}

func (u *testUnit) MoveTo(p types.Pointf) {
	u.st = UnitMove
	u.targ = p
}

func (u *testUnit) WalkTo(p types.Pointf) {
	u.st = UnitWalk
	u.targ = p
}

func (u *testUnit) LookAt(p types.Pointf) {
	u.look.pt = p
}

func (u *testUnit) LookAtDir(dir int) {
	u.look.dir = dir
}

func (u *testUnit) LookAngle(ang int) {
	u.look.ang = ang
}

func (u *testUnit) Freeze(freeze bool) {
	u.frozen = freeze
}

func (u *testUnit) Wander() {
	u.st = UnitWander
	u.targ = types.Pointf{}
}

func (u *testUnit) Return() {
	u.st = UnitReturn
	u.targ = types.Pointf{}
}

func (u *testUnit) Idle() {
	u.st = UnitIdle
	u.targ = types.Pointf{}
}

func (u *testUnit) Follow(obj script.Positioner) {
	u.st = UnitFollow
	u.targ = obj.Pos()
}

func (u *testUnit) Flee(obj script.Positioner, dur script.Duration) {
	u.st = UnitFlee
	u.targ = obj.Pos()
}

func (u *testUnit) SetAggression(v float32) {
	u.aggr = v
}

func (u *testUnit) SetRetreatLevel(v float32) {
	u.retreat = v
}

func (u *testUnit) SetRegroupLevel(v float32) {
	u.regroup = v
}

func (u *testUnit) Attack(obj script.Positioner) {
	u.st = UnitAttack
	u.targ = obj.Pos()
}

func (u *testUnit) HitMelee(p types.Pointf) {
	u.st = UnitHitMelee
	u.targ = p
}

func (u *testUnit) HitRanged(p types.Pointf) {
	u.st = UnitHitRanged
	u.targ = p
}

func (u *testUnit) Guard() {
	u.st = UnitGuard
	u.targ = types.Pointf{}
}

func (u *testUnit) Hunt() {
	u.st = UnitHunt
	u.targ = types.Pointf{}
}

func (u *testUnit) Aggression() float32 {
	return u.aggr
}

func (u *testUnit) RetreatLevel() float32 {
	return u.retreat
}

func (u *testUnit) RegroupLevel() float32 {
	return u.regroup
}

func (u *testUnit) Say(text string, dur script.Duration) {
	panic("implement me")
}

func (u *testUnit) Mute() {
	panic("implement me")
}

func TestUnitID(t *testing.T) {
	g := newGame(t)
	g.newUnit("Test", 1, 2)

	g.Exec(`
	local v = Nox.Object("Test")

	if v.id ~= "Test" then
		error("invalid ID field")
	end

	if v:__tostring() ~= "Unit(Test)" then
		error("invalid string conversion")
	end
`)
}

func TestUnitPos(t *testing.T) {
	g := newGame(t)
	g.newUnit("Test", 1, 2)

	g.Exec(`
	local v = Nox.Object("Test")

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

func TestUnitSetPos(t *testing.T) {
	g := newGame(t)
	obj1 := g.newUnit("Test", 1, 2)
	obj2 := g.newUnit("Test2", 3, 4)

	g.Exec(`
	local v1 = Nox.Object("Test")
	local v2 = Nox.Object("Test2")
	v1:SetPos(v2)
	v2:SetPos(5, 6):SetPos(7, 8)
	v2.x = v2.x + 1
	v2.y = v2.y + 2
`)
	require.Equal(t, types.Pointf{X: 3, Y: 4}, obj1.pos)
	require.Equal(t, types.Pointf{X: 8, Y: 10}, obj2.pos)
}

func TestUnitDelete(t *testing.T) {
	g := newGame(t)
	v := g.newUnit("Test", 1, 2)

	g.Exec(`
	local v = Nox.Object("Test")
	v:Delete()
`)
	require.True(t, v.deleted)
}

func TestUnitDestroy(t *testing.T) {
	g := newGame(t)
	v := g.newUnit("Test", 1, 2)

	g.Exec(`
	v = Nox.Object("Test")
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

func TestUnitEnabled(t *testing.T) {
	g := newGame(t)
	v := g.newUnit("Test", 1, 2)

	g.Exec(`
	v = Nox.Object("Test")

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

func TestUnitToggle(t *testing.T) {
	g := newGame(t)
	v := g.newUnit("Test", 1, 2)

	g.Exec(`
	v = Nox.Object("Test")

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

func TestUnitOwner(t *testing.T) {
	g := newGame(t)
	obj1 := g.newUnit("Test", 1, 2)
	obj2 := g.newUnit("Test2", 3, 4)

	g.Exec(`
	v1 = Nox.Object("Test")
	v2 = Nox.Object("Test2"):SetOwner(v1)
`)
	require.Equal(t, obj1, obj2.owner)

	g.Exec(`
	v2:SetOwner(nil)
`)
	require.Nil(t, obj2.owner)

	g.Exec(`
	v2.owner = v1
`)
	require.Equal(t, obj1, obj2.owner)

	g.Exec(`
	v2.owner = nil
`)
	require.Nil(t, obj2.owner)

	g.Exec(`
	v2.owner = v1
	v1.owner = v2.owner
`)
	require.Equal(t, obj1, obj2.owner)
	require.Equal(t, obj1, obj1.owner)
}

func TestUnitFreeze(t *testing.T) {
	g := newGame(t)
	v := g.newUnit("Test", 1, 2)

	g.Exec(`
	v = Nox.Object("Test")
	v:Freeze()
`)
	require.True(t, v.frozen)

	g.Exec(`
	v:Freeze(false)
`)
	require.False(t, v.frozen)

	g.Exec(`
	v:Freeze(true)
`)
	require.True(t, v.frozen)
}

func TestUnitHealth(t *testing.T) {
	g := newGame(t)
	v := g.newUnit("Test", 1, 2)
	v.health.cur = 3
	v.health.max = 5

	g.Exec(`
	v = Nox.Object("Test")

	if v.health ~= 3 then
		error("incorrect health")
	end
	if v.max_health ~= 5 then
		error("incorrect max health")
	end

	v.health = 1
`)
	require.Equal(t, 1, v.health.cur)

	g.Exec(`
	v.max_health = 10
`)
	require.Equal(t, 10, v.health.cur)
	require.Equal(t, 10, v.health.max)
}

func TestUnitMana(t *testing.T) {
	g := newGame(t)
	v := g.newUnit("Test", 1, 2)
	v.mana.cur = 3
	v.mana.max = 5

	g.Exec(`
	v = Nox.Object("Test")

	if v.mana ~= 3 then
		error("incorrect mana")
	end
	if v.max_mana ~= 5 then
		error("incorrect max mana")
	end

	v.mana = 1
`)
	require.Equal(t, 1, v.mana.cur)

	g.Exec(`
	v.max_mana = 10
`)
	require.Equal(t, 10, v.mana.cur)
	require.Equal(t, 10, v.mana.max)
}

func TestUnitActions(t *testing.T) {
	g := newGame(t)
	obj1 := g.newUnit("Test", 1, 2)
	obj2 := g.newUnit("Test2", 3, 4)

	g.Exec(`
	v1 = Nox.Object("Test")
	v2 = Nox.Object("Test2")
`)
	require.Equal(t, UnitIdle, obj1.st)

	for _, c := range []struct {
		name string
		st   unitState
	}{
		{"Wander", UnitWander},
		{"Hunt", UnitHunt},
		{"Return", UnitReturn},
		{"Guard", UnitGuard},
		{"Idle", UnitIdle},
	} {
		t.Run(c.name, func(t *testing.T) {
			g.t = t
			g.Exec(fmt.Sprintf(`
	v1:%s()
`,
				c.name,
			))
			require.Equal(t, c.st, obj1.st)
		})
	}

	for _, c := range []struct {
		name   string
		st     unitState
		coords bool
	}{
		{"MoveTo", UnitMove, true},
		{"WalkTo", UnitWalk, true},
		{"Follow", UnitFollow, false},
		{"Attack", UnitAttack, false},
		{"HitMelee", UnitHitMelee, true},
		{"HitRanged", UnitHitRanged, true},
	} {
		t.Run(c.name, func(t *testing.T) {
			g.t = t
			if c.coords {
				g.Exec(fmt.Sprintf(`
	v1:%s(1, 2)
`,
					c.name,
				))
				require.Equal(t, c.st, obj1.st)
				require.Equal(t, types.Pointf{1, 2}, obj1.targ)
			}

			g.Exec(fmt.Sprintf(`
	v1:Idle()
	v1:%s(v2)
`,
				c.name,
			))
			require.Equal(t, c.st, obj1.st)
			require.Equal(t, obj2.pos, obj1.targ)
		})
	}
}

// TODO: test unit group
