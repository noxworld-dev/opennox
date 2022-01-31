package object

import (
	"encoding/json"
	"strconv"
	"strings"
)

var classNames = []string{
	"MISSILE", "MONSTER", "PLAYER", "OBSTACLE", "FOOD", "EXIT", "KEY",
	"DOOR", "INFO_BOOK", "TRIGGER", "TRANSPORTER", "HOLE", "WAND", "FIRE",
	"ELEVATOR", "ELEVATOR_SHAFT", "DANGEROUS", "MONSTERGENERATOR", "READABLE", "LIGHT", "SIMPLE",
	"COMPLEX", "IMMOBILE", "VISIBLE_ENABLE", "WEAPON", "ARMOR", "NOT_STACKABLE", "TREASURE",
	"FLAG", "CLIENT_PERSIST", "CLIENT_PREDICT", "PICKUP",
}

var (
	_ json.Marshaler = Class(0)
)

type Class uint32

const (
	ClassMissile          = Class(1 << iota) // 0x1
	ClassMonster                             // 0x2
	ClassPlayer                              // 0x4
	ClassObstacle                            // 0x8
	ClassFood                                // 0x10
	ClassExit                                // 0x20
	ClassKey                                 // 0x40
	ClassDoor                                // 0x80
	ClassInfoBook                            // 0x100
	ClassTrigger                             // 0x200
	ClassTransporter                         // 0x400
	ClassHole                                // 0x800
	ClassWand                                // 0x1000
	ClassFire                                // 0x2000
	ClassElevator                            // 0x4000
	ClassElevatorShaft                       // 0x8000
	ClassDangerous                           // 0x10000
	ClassMonsterGenerator                    // 0x20000
	ClassReadable                            // 0x40000
	ClassLight                               // 0x80000
	ClassSimple                              // 0x100000
	ClassComplex                             // 0x200000
	ClassImmobile                            // 0x400000
	ClassVisibleEnable                       // 0x800000
	ClassWeapon                              // 0x1000000
	ClassArmor                               // 0x2000000
	ClassNotStackable                        // 0x4000000
	ClassTreasure                            // 0x8000000
	ClassFlag                                // 0x10000000
	ClassClientPersist                       // 0x20000000
	ClassClientPredict                       // 0x40000000
	ClassPickup                              // 0x80000000
)

const (
	MaskUnits   = ClassPlayer | ClassMonster
	MaskTargets = ClassMonsterGenerator | MaskUnits
)

func (c Class) Has(c2 Class) bool {
	return c&c2 != 0
}

func (c Class) HasAny(c2 Class) bool {
	return c&c2 != 0
}

func (c Class) Split() []Class {
	var out []Class
	for i := 0; i < 32; i++ {
		c2 := Class(1 << i)
		if c.Has(c2) {
			out = append(out, c2)
		}
	}
	return out
}

func (c Class) String() string {
	var out []string
	for i := 0; i < 32; i++ {
		c2 := Class(1 << i)
		if c.Has(c2) {
			out = append(out, classNames[i])
		}
	}
	return strings.Join(out, " | ")
}

func (c Class) MarshalJSON() ([]byte, error) {
	var arr []string
	for _, s := range c.Split() {
		arr = append(arr, s.String())
	}
	return json.Marshal(arr)
}

var (
	_ json.Marshaler = ArmorClass(0)
)

var ArmorClassNames = []string{
	"HELMET", "SHIELD", "BREASTPLATE", "ARM_ARMOR", "PANTS", "BOOTS", "SHIRT", "LEG_ARMOR", "BACK",
}

type ArmorClass uint32

const (
	ArmorHelmet = ArmorClass(1 << iota)
	ArmorShield
	ArmorBreastplate
	ArmorArmArmor
	ArmorPants
	ArmorBoots
	ArmorShirt
	ArmorLegArmor
	ArmorBack
)

func (c ArmorClass) Has(c2 ArmorClass) bool {
	return c&c2 != 0
}

func (c ArmorClass) Split() []ArmorClass {
	var out []ArmorClass
	for i := 0; i < 32; i++ {
		c2 := ArmorClass(1 << i)
		if c.Has(c2) {
			out = append(out, c2)
		}
	}
	return out
}

func (c ArmorClass) String() string {
	var out []string
	for i := 0; i < 32; i++ {
		c2 := ArmorClass(1 << i)
		if c.Has(c2) {
			if i < len(ArmorClassNames) {
				out = append(out, ArmorClassNames[i])
			} else {
				out = append(out, "0x"+strconv.FormatUint(uint64(c2), 16))
			}
		}
	}
	return strings.Join(out, " | ")
}

func (c ArmorClass) MarshalJSON() ([]byte, error) {
	var arr []string
	for _, s := range c.Split() {
		arr = append(arr, s.String())
	}
	return json.Marshal(arr)
}
