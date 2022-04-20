# OpenNox console commands

## Enabling all commands

By default, Nox and OpenNox start with most commands disabled. This is done to prevent cheating in campaign.
Most commands will not work in multiplayer, unless you are a server admin/host.

To enable all commands, open the console (`F1` by default) and type:

```
racoiaws
```

## List of commands

To get a list of all available commands, use `help`.

Here's the list of the most interesting ones.

- [`image`](#image) - take a screenshot
- [`show`](#show) - show debug information
- [`list`](#list) - list spells, objects, monsters
- [`load`](#load) - switch game map
- [`set god`](#set-god) - invulnerability, infinite mana, all spells
- [`set quest`](#set-quest) - Nox Quest commands
- [`set maps`](#set-maps) - map-related settings
- [`cheat god`](#cheat-god) - invulnerability and infinite mana (no spells)
- [`cheat sage`](#cheat-sage) - all spells, abilities, scrolls
- [`cheat spells`](#cheat-spells) - all spells (optionally with hidden ones)
- [`cheat scrolls`](#cheat-scrolls) - all beast scrolls
- [`cheat goto`](#cheat-goto) - teleport to coordinates or waypoint
- [`cheat spawn`](#cheat-spawn) - spawn item or monster
- [`cheat gold`](#cheat-gold) - add gold
- [`cheat health`](#cheat-health) - set or restore health
- [`cheat mana`](#cheat-mana) - set or restore mana
- [`cheat equip.all`](#cheat-equipall) - allow to equip any armor and weapons
- [`cheat charm.all`](#cheat-charmall) - allow charming any hostile creature or NPC
- [`cheat summon.nolimit`](#cheat-summonnolimit) - no limit for spawned creatures
- [`lua`](#lua) - run LUA command

### image

Take a screenshot and save it as a PNG image.

```
image
```

### show

This command contains various helpers for debugging.

Available sub-commands:
- `show bindings` - show console bindings (macros).
- `show extents` - show names and sizes for all object on the screen.
- `show ai` - show AI paths and print all AI decisions to console.
- `show gui` - shows or hides graphical user interface.

### list

This command list various in-game spells, items, monsters, maps and players.

These commands print item IDs that can be the used with [spawn](#cheat-spawn) command.

Available sub-commands:
- `list staffs` - list all staffs and wands.
- `list armor` - list all armor.
- `list weapons` - list all weapons.
- `list food` - list all consumables.
- `list monsters` - list all monsters and NPCs.
- `list spells` - list all spells.
- `list maps` - list all maps.
- `list users` - list all players.

### load

This command switches current game map to the one specified:

```
load wiz01a
```

In vanilla Nox, not all maps can usually be loaded. For example, it's impossible to load campaign maps in multiplayer.
OpenNox allows removing those restrictions via [`set maps allow.all`](#set-maps).

### set god

A vanilla cheat for invulnerability, all spells and infinite mana.

```
set god
```

To disable:

```
unset god
```

Note that using this cheat will cause the character to learn all spells up to the maximal level.
This cannot be reversed, even if the cheat is disabled.
See [cheat god](#cheat-god) if you only need invulnerability and infinite mana.

### set quest

These commands allow more controls for Nox Quest game mode. See [this page](game-quest.md) for details.

### set maps

These commands allow more controls for game map loading.

- `set maps allow.all` - disable game mode checks when loading the map; allows loading campaign in multiplayer, etc

### cheat god

A cheat for invulnerability and infinite mana.

```
cheat god
```

To disable:

```
cheat god 0
```

For additionally getting all spells see [cheat sage](#cheat-sage), or [set god](#set-god).

### cheat sage

A cheat for getting all class spells, scrolls and/or abilities.

```
cheat sage
```

To disable:

```
cheat sage 0
```

### cheat spells

A cheat for getting all spells.

For getting class spells:

```
cheat spells
```

For getting class spells with a specific spell level:

```
cheat spells 3
```

To get all spells, even hidden ones:

```
cheat spells all
```

### cheat scrolls

A cheat for getting all beat scrolls.

```
cheat scrolls
```

To disable:

```
cheat scrolls 0
```

### cheat goto

Teleport to given coordinates or a waypoint.

For teleporting to coordinates (X, Y):

```
cheat goto 1000 2000
```

For teleporting to a waypoint:

```
cheat goto MyWaypoint
```

### cheat spawn

Spawn a given item or monster at the player's position.

Command accepts IDs returned by the [list](#list) command.

```
cheat spawn OblivionOrb
cheat spawn Mimic
```

It is also possible to specify a number of items to spawn:

```
cheat spawn RedApple 5
```

### cheat gold

Adds specified amount of gold to all players.

```
cheat gold 10000
```

### cheat health

Sets or restores health for the character.

Without arguments, command will restore health to maximum:

```
cheat health
```

You can also specify desired health value:

```
cheat health 999
```

### cheat mana

Sets or restores mana for the character.

Without arguments, command will restore mana to maximum:

```
cheat mana
```

You can also specify desired mana value:

```
cheat mana 999
```

### cheat equip.all

Removes equipment requirements from all items. In other words, any class can equip and use any armor/weapons.

```
cheat equip.all
```

To disable it:

```
cheat equip.all 0
```

### cheat charm.all

Allows charming any hostile creatures and NPCs (including scripted ones, humanoids, etc).

```
cheat charm.all
```

To disable it:

```
cheat charm.all 0
```

### cheat summon.nolimit

Remove the limit for the number of summoned creatures.

WARNING: The game may become unstable and crash.

```
cheat summon.nolimit
```

To disable it:

```
cheat summon.nolimit 0
```

### lua

This commands runs given LUA code.

For example, to replicate `cheat spawn RedApple` with LUA:

```
lua apple = Nox.ObjectType("RedApple")
lua p = Nox.Players.host
lua apple:Create(p)
```

Notice that variables defined in one `lua` command can be used in other ones.

It's also possible to write a multi-line command in a single line:

```
lua apple = Nox.ObjectType("RedApple"); p = Nox.Players.host; apple:Create(p)
```

or

```
lua Nox.ObjectType("RedApple"):Create(Nox.Players.host)
```

For more information about LUA scripting, see [this page](maps-lua.md).
