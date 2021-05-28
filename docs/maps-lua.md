# Map script LUA API

To create a LUA map script, put `<mapname>.lua` file in the map's directory.

For example:
```
maps/
  estate/
    estate.map
    estate.nxz
    estate.lua
```

You also need to request a specific version of the scripting API that you want to use:

```lua
Nox = require("Nox.Map.Script.v0")
```

Now you are ready to write some magic Nox scripts!

It is also possible to add more LUA files, for example:
```
maps/
  estate/
    estate.map
    estate.lua
    other_file.lua
```

And use `require` to load it:

```lua
other_file = require("other_file")
```

## Debugging with the in-game console

You can access script variables for debugging using Nox console.

First, you should enable cheats (`racoiaws`), and the prefix all you commands with `lua `.

For example:

```lua
lua p = Nox.Players[1]
lua print(p)
```

## Timers

Timers allow to trigger some LUA function at a later time.

### Frame timer

This timer will call a given function after N game frames (server ticks).

```lua
function MyFunc()
    print("trigger!")
end
Nox.FrameTimer(60, MyFunc)
```

### Seconds timer

This timer will call a given function after N in-game seconds pass.

```lua
function MyFunc()
    print("trigger!")
end
Nox.SecondTimer(10, MyFunc)
```

## Walls

Walls in Nox are positioned on a regular grid. Thus, walls can be addressed by those grid positions.
If walls are marked as scriptable in the editor, it will be possible to enable (close) and disable (open) them.

- `Wall(xi,yi)` - get a [wall](#wall-object) by its grid coordinates.
- `WallAt(x,y)` - get a [wall](#wall-object) at exact real coordinates (not grid ones).
- `WallNear(x,y)` - get a [wall](#wall-object) near specific real coordinates (not grid ones).
- `WallNear(obj)` - get a [wall](#wall-object) near a specific object or waypoint.
- `WallGroup(id)` - finds a [wall group](#wallgroup) by the ID.

### `Wall` object

This object represents a single wall on the map.

- `w.xi` - returns X grid coordinate of the wall.
- `w.yi` - returns Y grid coordinate of the wall.
- `w.x` - returns real X coordinate of the wall.
- `w.y` - returns real Y coordinate of the wall.
- `w.enabled` - checks if the wall is enabled (closed) or sets the enabled state.
- `w:Pos()` - returns wall's real position as a pair of X,Y coordinates.
- `w:Toggle()` - toggles the wall's state (opened/closed).
- `w:Break()` - break this wall (must be set as breakable).

### `WallGroup`

This object represents a group of one or more walls on the map.

- `w.id` - returns ID of this wall group.
- `w:Toggle()` - toggles walls state (opened/closed).
- `w:Break()` - break these walls (must be set as breakable).

### Examples

Open secret wall near the player (must be really close):
```lua
local p = Nox.Players[1]
Nox.WallNear(p).enabled = false
```

Break a wall group with ID `MyGroup` on the map:
```lua
local g = Nox.WallGroup("MyGroup")
g:Break()
```

## Players

This section describes player-related objects and functions.

### `Players` meta-class

Players list can be accessed via `Nox.Players` meta-class.

- `Players()` - returns current list of [players](#player-object) as LUA array.
- `Players[i]` - returns a [player](#player-object) by index `i`.
- `Players:Print(text)` - prints a text message to all players.
- `Players:Blind()` - blinds all players (fades the screen to black).
- `Players:Blind(false)` - unblinds all players (fade back to normal).

### `Player` object

Player object includes information about human-controlled player, as well as a unit he controls.

- `p.name` - returns player's name.
- `p.host` - checks if player is a host.
- `p.unit` - returns player's [unit](#unit-object), if any.
- `p.x` - gets or sets player's [unit](#unit-object) X coordinate.
- `p.y` - gets or sets player's [unit](#unit-object) Y coordinate.
- `p:Pos()` - returns player's [unit](#unit-object) position as a pair of X,Y coordinates.
- `p:MoveTo(x,y)` - instantly moves player's [unit](#unit-object) to given coordinates.
- `p:MoveTo(obj)` - instantly moves player's [unit](#unit-object) to a given object or waypoint.
- `p:Print(text)` - prints a text message to the player.
- `p:Blind()` - blinds player (fades the screen to black).
- `p:Blind(false)` - unblinds player (fade back to normal).

### Examples

Iterating over all players:
```lua
local players = Nox.Players()
for i,p in ipairs(players) do
    print(p)
end
```

Getting the first player:
```lua
local p = Nox.Players[1]
print(p)
```

Getting player's name:
```lua
local p = Nox.Players[1]
print(p.name)
```

Checking if player is a host:
```lua
local p = Nox.Players[1]
if p.host then
    print("it's the host!")
end
```

Blind everyone:
```lua
Nox.Players:Blind()
```

Blind everyone except the host:
```lua
local players = Nox.Players()
for i,p in ipairs(players) do
    if not p.host then
        p:Blind()
    end
end
```

## Objects

This section describes different object present in game.

### `Object` and `ObjectType`

For simplicity, the script API allows to get both [`Object`](#object-instance) (objects seen in-game)
and [`ObjectType`](#objecttype) (prototypes of objects) via a single `Objects(id)` call.

In other words, if you want to get objects with a certain ID that exists on the map already:
```lua
local v = Nox.Object("MyObjectOnTheMap")
print(v:Pos())
```
In this case, the returned value is an [object instance](#object-instance), or a more specific one like [unit](#unit-object).

And if you want to create a new one based on some object type:
```lua
local t = Nox.Object("RedApple")
local v1 = t:Create(x1, y1)
local v2 = t:Create(x2, y2)
```
In this case the returned value describes the type of the object.
The actual object instance be created to be seen in game (can be done multiple times).

### `ObjectType`

Object type describes a "prototype" of an object that can be spawned in-game.

- `t.id` - returns object type ID.
- `t:Create(x,y)` - creates a new [object instance](#object-instance) at given coordinates.
- `t:Create(obj)` - creates a new [object instance](#object-instance) at the position of another object or waypoint.

### `Object` instance

- `v.id` - returns object's ID, if any.
- `v.x` - gets or sets object's X coordinate.
- `v.y` - gets or sets object's Y coordinate.
- `v.z` - gets or sets object's Z coordinate.
- `v.enabled` - checks if object is enabled or sets the enabled state.
- `v:Pos()` - returns object's position as a pair of X,Y coordinates.
- `v:MoveTo(x,y)` - instantly moves object to given coordinates.
- `v:MoveTo(obj)` - instantly moves object to another object or waypoint.
- `v:Delete()` - permanently delete object from the map.
- `v:Toggle()` - toggles object's enabled state.

### `Unit` object

Unit extends the [generic object](#object-instance), so everything that can be done with object can be done with a unit.

- `v:Freeze()` - freezes the unit in place.
- `v:Wander()` - make the unit wander around.
- `v:Return()` - make the unit return to its starting position.
- `v:LookAt(x,y)` - make the unit look at certain position.
- `v:LookAt(obj)` - make the unit look at another object or waypoint.
- `v:LookAtDir(dir)` - make the unit look in a given direction.
- `v:LookAngle(dir)` - make the unit look at a given angle.
- `v:WalkTo(x,y)` - make the unit walk to certain position.
- `v:WalkTo(obj)` - make the unit walk to another object or waypoint.
- `v:Follow(obj)` - make the unit follow another object.
- `v:Attack(obj)` - make the unit attack another object.
- `v:HitMelee(x,y)` - make the unit hit melee a certain position.
- `v:HitMelee(obj)` - make the unit hit melee another object or waypoint.
- `v:HitRanged(x,y)` - make the unit hit ranged a certain position.
- `v:HitRanged(obj)` - make the unit hit ranged another object or waypoint.

### Examples

Teleport player 10 units right:
```lua
local p = Nox.Players[1]
x, y = p:Pos()
x = x + 10
p:MoveTo(x,y)
```

Teleport player 1 to player 2:
```lua
local p1 = Nox.Players[1]
local p2 = Nox.Players[2]
p1:MoveTo(p2)
```

Spawn 10 apples near the player:
```lua
local apple = Nox.Object("RedApple")
local p = Nox.Players[1]
for i = 1,10 do
    apple:Create(p)
end
```
