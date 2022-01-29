package object

import (
	"encoding/json"
	"fmt"
	"strings"
)

var flagsNames = []string{
	"BELOW", "NO_UPDATE", "ACTIVE", "ALLOW_OVERLAP",
	"SHORT", "DESTROYED", "NO_COLLIDE", "MISSILE_HIT",
	"EQUIPPED", "PARTITIONED", "NO_COLLIDE_OWNER", "OWNER_VISIBLE",
	"EDIT_VISIBLE", "NO_PUSH_CHARACTERS", "AIRBORNE", "DEAD",
	"SHADOW", "FALLING", "IN_HOLE", "RESPAWN",
	"ON_OBJECT", "SIGHT_DESTROY", "TRANSIENT", "BOUNCY",
	"ENABLED", "PENDING", "TRANSLUCENT", "STILL",
	"NO_AUTO_DROP", "FLICKER", "SELECTED", "MARKED",
}

var (
	_ json.Marshaler = Flags(0)
)

func ParseFlag(s string) (Flags, error) {
	s = strings.ToUpper(s)
	for i, v := range flagsNames {
		if s == v {
			return Flags(1 << i), nil
		}
	}
	return 0, fmt.Errorf("invalid flag name: %q", s)
}

type Flags uint32

const (
	FlagBelow            = Flags(1 << iota) // 0x1
	FlagNoUpdate                            // 0x2
	FlagActive                              // 0x4
	FlagAllowOverlap                        // 0x8
	FlagShort                               // 0x10
	FlagDestroyed                           // 0x20
	FlagNoCollide                           // 0x40
	FlagMissileHit                          // 0x80
	FlagEquipped                            // 0x100
	FlagPartitioned                         // 0x200
	FlagNoCollideOwner                      // 0x400
	FlagOwnerVisible                        // 0x800
	FlagEditVisible                         // 0x1000
	FlagNoPushCharacters                    // 0x2000
	FlagAirborne                            // 0x4000
	FlagDead                                // 0x8000
	FlagShadow                              // 0x10000
	FlagFalling                             // 0x20000
	FlagInHole                              // 0x40000
	FlagRespawn                             // 0x80000
	FlagOnObject                            // 0x100000
	FlagSightDestroy                        // 0x200000
	FlagTransient                           // 0x400000
	FlagBouncy                              // 0x800000
	FlagEnabled                             // 0x1000000
	FlagPending                             // 0x2000000
	FlagTranslucent                         // 0x4000000
	FlagStill                               // 0x8000000
	FlagNoAutoDrop                          // 0x10000000
	FlagFlicker                             // 0x20000000
	FlagSelected                            // 0x40000000
	FlagMarked                              // 0x80000000
)

const (
	FlagNotMovableMask = FlagDead | FlagNoCollide | FlagDestroyed | FlagAllowOverlap
	FlagNoUpdateMask   = FlagNoUpdate | FlagDestroyed
)

func (c Flags) Has(c2 Flags) bool {
	return c&c2 != 0
}

func (c Flags) HasAny(c2 Flags) bool {
	return c&c2 != 0
}

func (c Flags) Split() []Flags {
	var out []Flags
	for i := 0; i < 32; i++ {
		c2 := Flags(1 << i)
		if c.Has(c2) {
			out = append(out, c2)
		}
	}
	return out
}

func (c Flags) String() string {
	var out []string
	for i := 0; i < 32; i++ {
		c2 := Flags(1 << i)
		if c.Has(c2) {
			out = append(out, flagsNames[i])
		}
	}
	return strings.Join(out, " | ")
}

func (c Flags) MarshalJSON() ([]byte, error) {
	var arr []string
	for _, s := range c.Split() {
		arr = append(arr, s.String())
	}
	return json.Marshal(arr)
}
