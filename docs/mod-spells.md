# Changing spells

Vanilla Nox stores spell configs in three different places:

- As a section in `thing.bin` file
- [Balance file](mod-balance.md)
- Built into the engine

The engine defines a list of all supported spell IDs (e.g. `SPELL_BLINK`) and the effect associated with it.

The `thing.bin` then lists spells that should be enabled in the game (by ID) and additionally configures them.
Unfortunately, this configuration is quite limited.

The [balance file](mod-balance.md) may additionally tune per-level spell parameters,
or special parameters that are unique to certain spells.

OpenNox extends this system and allows using `spells.yml` file to configure new spell parameters, as well as old ones in one place.

**Note:** this modding feature is still in development. Not all the config options for spells are available in `spells.yml`.
We will keep adding new ones in each version of OpenNox. 

## Generating base `spells.yml` file

Since this feature is in the development, it is strongly advised to generate a fresh `spells.yml` based on the latest
OpenNox version and your Nox game data.

This can be done by running OpenNox with `NOX_DUMP_SPELLS=true` environment variable.

On Linux:

```
NOX_DUMP_SPELLS=true opennox
```

On Windows (via `cmd.exe`):

```
set NOX_DUMP_SPELLS="true"
opennox.exe
```

This should create a `spells.yml` in Nox game data directory (not OpenNox directory!).

Alternatively, you could copy the [spells-sample.yml](spells-sample.yml) file to your Nox game directory.
Be aware that the sample file might be old and won't list all options available in the engine.

## Modifying `spells.yml`

Note that modifying `spells.yml` currently requires OpenNox restart.

Usually, the spell section will look like this:

```yaml
name: SPELL_BLINK
icon:
  ind: 131860
icon_enabled:
  ind: 131938
mana_cost: 10
price: 3000
flags:
- 1
- MOBS_CAN_CAST
- 128
- 1024
- CAN_COUNTER
- CANT_HOLD_CROWN
- 1048576
- CLASS_ANY
- 2147483648
phonemes: [cha, et, un]
title: thing.db:Blink
desc: thing.db:SPELL_BLINK_DESC
cast_sound: BlinkCast
---
```

Where:

- `name` - specifies spell ID to use; if `effect` is not set, this also determines the spell effect
- `effect` - specifies spell ID which will control the actual effect of the spell; see [adding spells](#adding-new-spells)
- `icon.ind` - the sprite index from `video.bag` that is used as a spell icon
- `icon_enabled.ind` - same as `icon.ind`, but for enabled spell icon
- `mana_cost` - mana cost of the spell
- `price` - base spell book price; Quest uses an additional multiplier for this price
- `flags` - different [flags](#spell-flags) that controls which category spell belongs to, what it can target, etc
- `phonemes` - a unique list of spell phonemes/gestures that invoke this spell; see [spell casting](game-manual-cast.md)
- `title` - a string ID for the spell title
- `desc` - a string ID for the spell description
- `cast_sound` - a sound for casing a spell
- `on_sound` - a sound for enabling a spell
- `off_sound` - a sound for disabling a spell

These are the only parameters that can be originally controlled via `thing.bin`, and was ported to `spells.yml`.

Apart from these, OpenNox provides more options for certain spells.
For example, `SPELL_MAGIC_MISSILE` has a new section:

```yaml
missiles:
  spread: 16
  projectile: MagicMissile
  vel_mult: 0.1
  offset: 4
  speed_rnd_min: 0.80000001
  speed_rnd_max: 1.2
  search_dist: 600
```

Here, a `count` parameter is omitted, because it is usually controlled via [balance file](mod-balance.md) (see `MagicMissileCount`).
Specifying it here will override balance data.

When a special section like `missiles` this is present, all parameters in there can be controlled individually for each spell level:

```yaml
missiles:
  # default parameters for all levels
  spread: 16
  projectile: MagicMissile
  vel_mult: 0.1
  offset: 4
  speed_rnd_min: 0.80000001
  speed_rnd_max: 1.2
  search_dist: 600
  # per-level configs
  levels:
    # levels 1-3: copied from balance file
    - count: 1
    - count: 2
    - count: 3
    # level 4: same number of missiles as lvl3, but longer homing distance
    - count: 3
      search_dist: 800
    # level 5: make it ultimate: more missiles, longer distance, faster missiles
    - count: 10
      speed_rnd_min: 1.0
      speed_rnd_max: 2.0
      search_dist: 800
```

### Spell flags

Not all flags are completely understood at this point. So we recommend to see what flags are set for existing spells
and experiment by setting/unsetting them in your mod.

Names of the spell flags provided below may change in a freshly-generated `spells.yml`,
but OpenNox will still support old names as well.

**Player class flags:**

- `CLASS_ANY` - spell can be used by any magic class (Conjurer and Wizard)
- `CLASS_WIZARD` - spell can only be used by Wizard
- `CLASS_CONJURER` - spell can only be used by Conjurer
- Setting none of these flags will effectively hide the spell.

**Targeting flags**

- `TARGETED` - spell is homing
- `AT_LOCATION` - spell can be cast at a point
- `CANT_TARGET_SELF` - spell cannot be targeted at the character

**Cast flags:**

- `NO_MANA` - spell doesn't require mana
- `NO_TRAP` - spell can't be used in traps
- `INSTANT` - spell is instant
- `DURATION` - spell is duration-based
- `OFFENSIVE` - spell is offensive
- `DEFENSIVE` - spell is defensive
- `CAN_COUNTER` - spell can be countered
- `MOBS_CAN_CAST` - mobs are allowed to use this spell
- `CANT_HOLD_CROWN` - spell can't be cast when holding a flag/crown/ball

**Special flags**

- `SUMMON_SPELL` - this is the base Summon Creature spell
- `SUMMON_CREATURE` - this is Summon for a specific creature
- `MARK_SPELL` - this is the base Mark Location spell
- `MARK_NUMBER` - this is Mark Location with a specific number
- `GOTO_MARK_SPELL` - this is the base Go To Mark spell
- `GOTO_MARK_NUMBER` - this is Go To Mark with a specific number

There are some flags that don't have names, which means we are not sure of its effect.

### Adding new spells

Currently, adding new spells in OpenNox is **not supported**.

Having said that it is possible to _replace_ unused spell slots that already exist in the game.

In spell section there's a `name` parameter that defines the **slot** that the spell uses
and `effect` for the engine to know which **effect** to run.

Usually these two IDs are the same (or `effect` is empty and derived from `name`), but these fields can be used to replace
unused spell IDs with custom ones.

For example, there's `SPELL_PHANTOM` which doesn't appear in the game and has no effect in the engine.
This gives us a free spell slot to use. Let's replace it with a custom magic missiles (`SPELL_MAGIC_MISSILE`) variant.
For this we need to set `name: SPELL_PHANTOM` (or find existing section with it) to specify which _slot_ we are using,
and set `effect: SPELL_MAGIC_MISSILE` for the engine to know which logic to use for it. The result should look like this:

```yaml
name: SPELL_PHANTOM # replacing Phantom spell slot
effect: SPELL_MAGIC_MISSILE # but effect is based on Magic Missiles
phonemes: [un, ro, do] # phonemes must be unique, so we keep ones from Phantom
# the rest is copied from Missiles and modified
icon:
  ind: 18248
icon_enabled:
  ind: 131967
mana_cost: 50
price: 5000
flags:
  - AT_LOCATION
  - MOBS_CAN_CAST
  - OFFENSIVE
  - CAN_COUNTER
  - CANT_TARGET_SELF
  - CLASS_WIZARD
  - 536870912
  - 1073741824
title: thing.db:MissilesOfMagic
desc: thing.db:SPELL_MAGIC_MISSILE_DESC
cast_sound: MagicMissileCast
missiles:
  count: 5
  spread: 30
  projectile: MagicMissile
  vel_mult: 0.1
  offset: 4
  speed_rnd_min: 0.1
  speed_rnd_max: 0.3
  search_dist: 800
---
```
