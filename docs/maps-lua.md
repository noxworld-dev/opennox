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
lua p = Nox.Players.host
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
local p = Nox.Players.host
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
- `p:SetPos(x,y)` - instantly moves player's [unit](#unit-object) to given coordinates.
- `p:SetPos(obj)` - instantly moves player's [unit](#unit-object) to a given object or waypoint.
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

Getting the host player:
```lua
local p = Nox.Players.host
print(p)
```

Getting player's name:
```lua
local p = Nox.Players.host
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

### `ObjectType`

Object type describes a "prototype" of an object that can be spawned in-game.

- `Nox.ObjectType(id)` - find an object type by ID.
- `t.id` - returns object type ID.
- `t:Create(x,y)` - creates a new [object instance](#object-instance) at given coordinates.
- `t:Create(obj)` - creates a new [object instance](#object-instance) at the position of another object or waypoint.

### `Object` instance

- `Nox.Object(id)` - find an object by ID.
- `v.id` - returns object's ID, if any.
- `v.owner` - returns or sets object's owner.
- `v.x` - gets or sets object's X coordinate.
- `v.y` - gets or sets object's Y coordinate.
- `v.z` - gets or sets object's Z coordinate.
- `v.enabled` - checks if object is enabled or sets the enabled state.
- `v:Pos()` - returns object's position as a pair of X,Y coordinates.
- `v:SetPos(x,y)` - instantly moves object to given coordinates.
- `v:SetPos(obj)` - instantly moves object to another object or waypoint.
- `v:SetOwner(obj)` - sets object owner; same as `v.owner`, but allow chaining.
- `v:Delete()` - permanently delete object from the map.
- `v:Toggle()` - toggles object's enabled state.

### `Unit` object

Unit extends the [generic object](#object-instance), so everything that can be done with object can be done with a unit.

- `v.health` - current health of the unit.
- `v.max_health` - max health of the unit.
- `v.mana` - current mana of the unit.
- `v.max_mana` - max mana of the unit.
- `v:Freeze()` - freezes the unit in place.
- `v:Wander()` - make the unit wander around.
- `v:Return()` - make the unit return to its starting position.
- `v:Idle()` - make the unit idle.
- `v:Guard()` - make the unit guard position.
- `v:Hunt()` - make the unit hunt for enemies.
- `v:LookAt(x,y)` - make the unit look at certain position.
- `v:LookAt(obj)` - make the unit look at another object or waypoint.
- `v:LookAtDir(dir)` - make the unit look in a given direction.
- `v:LookAngle(dir)` - make the unit look at a given angle.
- `v:MoveTo(x,y)` - make the unit move to certain position.
- `v:MoveTo(obj)` - make the unit move to another object or waypoint.
- `v:WalkTo(x,y)` - make the unit walk to certain position.
- `v:WalkTo(obj)` - make the unit walk to another object or waypoint.
- `v:Follow(obj)` - make the unit follow another object.
- `v:Attack(obj)` - make the unit attack another object.
- `v:HitMelee(x,y)` - make the unit hit melee a certain position.
- `v:HitMelee(obj)` - make the unit hit melee another object or waypoint.
- `v:HitRanged(x,y)` - make the unit hit ranged a certain position.
- `v:HitRanged(obj)` - make the unit hit ranged another object or waypoint.

### Examples

Teleport player 10 pixels right:
```lua
p = Nox.Players.host
x, y = p:Pos()
x = x + 10
p:SetPos(x,y)
```

Teleport player 1 to player 2:
```lua
p1 = Nox.Players[1]
p2 = Nox.Players[2]
p1:SetPos(p2)
```

Spawn 10 apples near the player:
```lua
apple = Nox.ObjectType("RedApple")
p = Nox.Players.host
for i = 1,10 do
    apple:Create(p)
end
```

Spawn Mimic near the player and make him friendly:
```lua
mimic = Nox.ObjectType("Mimic")
p = Nox.Players.host
mimic:Create(p):SetOwner(p)
```

Spawn 2 Beholders and make them follow the player:
```
beholder = Nox.ObjectType("Beholder")
p = Nox.Players.host
arr = {}
for i = 1,2 do
    arr[i] = beholder:Create(p)
end
squad = Nox.ObjectGroup(unpack(arr))
squad:SetOwner(p)
squad:Follow(p)
```

Make a train of 5 Bombers that follow each other and the player:
```
function trainFollow()
    p:Print("Bomber train!")
    prev = p
    for i, b in ipairs(bombers) do
        b:Follow(prev)
        prev = b
    end
end

function makeTrain()
    bomber = Nox.ObjectType("Bomber")
    p = Nox.Players.host
    bombers = {}
    for i = 1,5 do
        bombers[i] = bomber:Create(p)
    end
    train = Nox.ObjectGroup(unpack(bombers))
    train:SetOwner(p)
    -- give them a frame or two to appear
    Nox.FrameTimer(2, trainFollow)
end

makeTrain()
```
