# Nox Quest

This build provides more commands for Nox Quest game mode.

Originally, Nox Quest:

- Prevents players to skip levels if they haven't completed them already
- Skips only 5 levels at a time.
- Disables the portal after level 20.
- Even if portal cutoff is increased to more than 20, it won't teleport to next levels.

To solve all of this, you can run (in the game console; `F1`):

```
racoiaws
set quest warp.allow
set quest warp.inc 10
set quest warp.inf
```

For more detailed description of commands, read on.

## `warp.allow`

This option disables the requirement to complete a certain Quest level before accessing the portal.

**Example:**

```
# always allow to pass through the portal
set quest warp.allow
set quest warp.allow 1

# original Nox behavior
set quest warp.allow 0
```

## `warp.inc`

Changes the number of levels that the portal skips at a time.

**Example:**

```
# portal will only skip one level instead of 5
set quest warp.inc 1
# skip 20 levels
set quest warp.inc 20

# original Nox behavior
set quest warp.allow 5
```

## `warp.inf`

Allows the portal to work indefinitely instead of shutting down at level 20.

**Example:**

```
# portal will always be enabled
set quest warp.inf
set quest warp.inf 1

# original Nox behavior
set quest warp.inf 0
```

## `level.inc`

Changes the number of levels that will be skipped on the stage completion.
In other words, how quickly the levels will increase when you complete a Quest level.

This allows to ramp up difficulty much faster without affecting other Quest rules.

**Example:**

```
# completing level 5 will lead to level 7 (+2) instead of 6 (+1)
set quest level.inc 2

# original Nox behavior
set quest level.inc 1
```
