# Nox enums and flags

## Unit flags

Name | Value | Comment
---- | ----- | -------
`BELOW` | `0x1` |  object does not collide with airborne units
`NO_UPDATE` | `0x2` |  O is ignored while executing update queue
`ACTIVE` | `0x4` |  UNKNOWN
`ALLOW_OVERLAP` | `0x8` |  O will not be pushed upon collision with obstacles (effects, decorations)
`SHORT` | `0x10` |  Jumping PC and airborne objects will not collide with O
`DESTROYED` | `0x20` |  O is going to be removed next frame
`NO_COLLIDE` | `0x40` |  O ignores collisions with anything (static decorations)
`MISSILE_HIT` | `0x80` |  O triggers missile collisions
`EQUIPPED` | `0x100` |  O is being worn by NPC or PC, any armor/weapons for example
`PARTITIONED` | `0x200` |  UNKNOWN
`NO_COLLIDE_OWNER` | `0x400` |  O does not collide with its parent
`OWNER_VISIBLE` | `0x800` |  O is only visible to its parent (`TeleportGlyphX`)
`EDIT_VISIBLE` | `0x1000` |  O is only visible in NoxEdit; O with `OWNER_VISIBLE` / `EDIT_VISIBLE` will not render at all, even with show extents mode enabled
`NO_PUSH_CHARACTERS` | `0x2000` |  O does not collide with PC
`AIRBORNE` | `0x4000` |  O ignores collision with some objects
`DEAD` | `0x8000` |  O is a monster/PC and is dead; used for various tests
`SHADOW` | `0x10000` |  O blocks PC's line of sight; examples `ColumnX`, `StoneBlock`, `Boulder`
`FALLING` | `0x20000` |  UNKNOWN, probably related to Pits
`IN_HOLE` | `0x40000` |  UNKNOWN, probably related to Pits
`RESPAWN` | `0x80000` |  O is added in respawn list upon creation (only in MP)
`ON_OBJECT` | `0x100000` |  fall logic related - prevents smth
`SIGHT_DESTROY` | `0x200000` |  UNKNOWN
`TRANSIENT` | `0x400000` |  decaying object
`BOUNCY` | `0x800000` |  obj has special fall logic
`ENABLED` | `0x1000000` |  O is in "active" state (valid only for interactive objects - elevators, buttons...)
`PENDING` | `0x2000000` |  set on recently created O's, probably forces `MSG_SIMPLE_OBJECT`
`TRANSLUCENT` | `0x4000000` |  UNKNOWN, probably something related to lighting system
`STILL` | `0x8000000` |  UNKNOWN
`NO_AUTO_DROP` | `0x10000000` |  O does not drop upon death of its current holder; example `OblivionOrb`
`FLICKER` | `0x20000000` |  UNKNOWN, something related to projectiles
`SELECTED` | `0x40000000` | 
`MARKED` | `0x80000000` |

## Class flags

Name | Value | Comment
---- | ----- | -------
`MISSILE` | `0x1` | O is treated as projectile (some special update handling)
`MONSTER` | `0x2` | O is treated as monster, used mostly in validating
`PLAYER` | `0x4` | O represents player in game world. (`NewPlayer`, `PhantomPlayer`, `Player`, `PlayerFemale`)
`OBSTACLE` | `0x8` | O blocks movement, used mostly in monster AI code for static decorations
`FOOD` | `0x10` | O is a useful healing item, used in monster AI (`ACTION_RETREAT`)
`EXIT` | `0x20` | O is level finish (exit) point, examples: `ExitX`, `TeleporterExit`, `PitExit`
`KEY` | `0x40` | O is a key used for opening locked doors
`DOOR` | `0x80` | Object is a door
`INFO_BOOK` | `0x100` | O is a spell book or field guide
`TRIGGER` | `0x200` | O executes some event upon interaction (Buttons, levers, pressure plates, wells)
`TRANSPORTER` | `0x400` | O is used for instant travelling (`TeleportPentagram`, `TeleportExitStoneX`)
`HOLE` | `0x800` | `PitCrumblingFloor` / `ForestPit`
`WAND` | `0x1000` | O is a weapon for magic users (`InfinitePainWand`, `LesserFireballWand`, `ForceWand`...)
`FIRE` | `0x2000` | O is an instance of fire (`Flame`, `FlameCleanse`, `BlueFlame`...)
`ELEVATOR` | `0x4000` | `XElevator`, never (?) used in code
`ELEVATOR_SHAFT` | `0x8000` | `XElevatorPit`
`DANGEROUS` | `0x10000` | Marks O as dangerous for AI, used for pathfinding
`MONSTERGENERATOR` | `0x20000` | `XGenerator`
`READABLE` | `0x40000` | Various signs, never used in code
`LIGHT` | `0x80000` | Object is a light source
`SIMPLE` | `0x100000` | Most objects have this in declaration. `MSG_SIMPLE_OBJ` contains netID and obj position
`COMPLEX` | `0x200000` | Like `SIMPLE`, but used only (?) for monsters; `MSG_COMPLEX_OBJ` also contains animation frame
`IMMOBILE` | `0x400000` | Used for static decorations. Objects with this class are only synchronized with clients by special packets (`MSG_DOOR_ANGLE`)
`VISIBLE_ENABLE` | `0x800000` | Object is only rendered if `ENABLED` flag set
`WEAPON` | `0x1000000` | 
`ARMOR` | `0x2000000` | 
`NOT_STACKABLE` | `0x4000000` | Multiple objects do not stack in inventory, any `WEAPON`/`ARMOR` has this
`TREASURE` | `0x8000000` | Object is used in Scavenger Hunt game mode
`FLAG` | `0x10000000` | Object is a flag used in CTF game mode
`CLIENT_PERSIST` | `0x20000000` | 
`CLIENT_PREDICT` | `0x40000000` | 
`PICKUP` | `0x80000000` | 

## Weapon flags

Name | Value | Comment
---- | ----- | -------
`Flag` | `0x1` | 
`Quiver` | `0x2` | 
`Bow` | `0x4` | 
`CrossBow` | `0x8` | 
`RoundChakram` | `0x40` | 
`FanChakram` | `0x80` | 
`Sword` | `0x100` | 
`Longsword` | `0x200` | 
`GreatSword` | `0x400` | 
`MorningStar` | `0x800` | 
`BattleAxe` | `0x1000` | 
`OgreAxe` | `0x2000` | 
`WarHammer` | `0x4000` | 
`StaffWooden` | `0x8000` | 
`SulphorousFlareWand` | `0x10000` | 
`SulphorousShowerWand` | `0x20000` | 
`ForceWand` | `0x40000` | 
`LesserFireballWand` | `0x80000` | 
`DemonsBreathWand` | `0x80000` |  Those two have equal masks...
`InfinitePainWand` | `0x200000` | 
`DeathRayWand` | `0x400000` | 
`OblivionHalberd` | `0x800000` | 
`OblivionHeart` | `0x1000000` | 
`OblivionWierdling` | `0x2000000` | 
`OblivionOrb` | `0x4000000` | 

## Damage type

Name | Value | Comment
---- | ----- | -------
`BLADE` | `0` | Weapons
`FLAME` | `1` | `FlameX`, `Fireball`
`CRUSH` | `2` | `Bear`, `Golem`
`IMPALE` | `3` | `Halberd`, `Wasp`
`DRAIN` | `4` | `Ghost`, `Shade`
`POISON` | `5` | Poison, Toxic cloud
`DISPEL_UNDEAD` | `6` | Dispel undead
`EXPLOSION` | `7` | `BlackPowderBarrel` explosions
`BITE` | `8` | Spiders, Wolves
`ELECTRIC` | `9` | Lightning?
`CLAW` | `10` | `EmberDemon`
`IMPACT` | `11` | `Ogres`, `Troll`, `Hammer`?
`LAVA` | `12` | Lava tiles
`DEATH_MAGIC` | `13` | Death spell
`PLASMA` | `14` | Plasma spell (Staff of Oblivion)
`MANA_BOMB` | `15` | Mana Bomb spell
`ZAP_RAY` | `16` | Death Ray spell
`AIRBORNE_ELECTRIC` | `17` | unknown

## Monster status

Name | Value | Comment
---- | ----- | -------
`DESTROY_WHEN_DEAD` | `0x1` | 
`CHECK` | `0x2` | 
`CAN_BLOCK` | `0x4` | 
`CAN_DODGE` | `0x8` | 
`unused` | `0x10` | 
`CAN_CAST_SPELLS` | `0x20` | 
`HOLD_YOUR_GROUND` | `0x40` | 
`SUMMONED` | `0x80` | 
`ALERT` | `0x100` | 
`INJURED` | `0x200` | 
`CAN_SEE_FRIENDS` | `0x400` | 
`CAN_HEAL_SELF` | `0x800` | 
`CAN_HEAL_OTHERS` | `0x1000` | 
`CAN_RUN` | `0x2000` | 
`RUNNING` | `0x4000` | 
`ALWAYS_RUN` | `0x8000` | 
`NEVER_RUN` | `0x10000` | 
`BOT` | `0x20000` | 
`MORPHED` | `0x40000` | 
`STAY_DEAD` | `0x80000` | 
`ON_FIRE` | `0x100000` | 
`FRUSTRATED` | `0x200000` | 
