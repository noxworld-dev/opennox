package mapv0_test

import (
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/types"
	"nox/v1/server/script"
)

func (g *testGame) ObjectTypeByID(id string) script.ObjectType {
	return nil
}

func (g *testGame) ObjectByID(id string) script.Object {
	obj := g.objects[id]
	return obj
}

func (g *testGame) newObject(id string, x, y float32) *testObject {
	obj := &testObject{
		g:       g,
		id:      id,
		pos:     types.Pointf{X: x, Y: y},
		enabled: true,
	}
	if id != "" {
		if g.objects == nil {
			g.objects = make(map[string]script.Object)
		}
		g.objects[id] = obj
	}
	return obj
}

type testObject struct {
	script.BaseObject
	g       *testGame
	id      string
	pos     types.Pointf
	owner   script.Object
	enabled bool
	deleted bool
	dead    bool
}

func (v *testObject) ID() string {
	return v.id
}

func (v *testObject) String() string {
	return "Object(" + v.ID() + ")"
}

func (v *testObject) GetObject() script.Object {
	if v == nil {
		return nil
	}
	return v
}

func (v *testObject) IsEnabled() bool {
	return v.enabled
}

func (v *testObject) Enable(enable bool) {
	if v.deleted {
		return
	}
	v.enabled = enable
}

func (v *testObject) Owner() script.Object {
	return v.owner
}

func (v *testObject) SetOwner(owner script.ObjectWrapper) {
	if v.deleted {
		return
	}
	if owner == nil {
		v.owner = nil
	} else {
		v.owner = owner.GetObject()
	}
}

func (v *testObject) Pos() types.Pointf {
	return v.pos
}

func (v *testObject) SetPos(p types.Pointf) {
	if v.deleted {
		return
	}
	v.pos = p
}

func (v *testObject) Delete() {
	if v.deleted {
		return
	}
	v.deleted = true
	delete(v.g.objects, v.id)
}

func (v *testObject) Destroy() {
	if v.deleted {
		return
	}
	v.dead = true
}

func TestObjectID(t *testing.T) {
	g := newGame(t)
	g.newObject("Test", 1, 2)

	g.Exec(`
	local v = Nox.Object("Test")

	if v.id ~= "Test" then
		error("invalid ID field")
	end

	if v:__tostring() ~= "Object(Test)" then
		error("invalid string conversion")
	end
`)
}

func TestObjectPos(t *testing.T) {
	g := newGame(t)
	g.newObject("Test", 1, 2)

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

func TestObjectSetPos(t *testing.T) {
	g := newGame(t)
	obj1 := g.newObject("Test", 1, 2)
	obj2 := g.newObject("Test2", 3, 4)

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

func TestObjectDelete(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 1, 2)

	g.Exec(`
	local v = Nox.Object("Test")
	v:Delete()
`)
	require.True(t, v.deleted)
}

func TestObjectDestroy(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 1, 2)

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

func TestObjectEnabled(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 1, 2)

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

func TestObjectToggle(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 1, 2)

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

func TestObjectOwner(t *testing.T) {
	g := newGame(t)
	obj1 := g.newObject("Test", 1, 2)
	obj2 := g.newObject("Test2", 3, 4)

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

// TODO: test object types
// TODO: test object groups
