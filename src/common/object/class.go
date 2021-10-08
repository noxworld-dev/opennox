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
	ClassMissile = Class(1 << iota)
	ClassMonster
	ClassPlayer
	ClassObstacle
	ClassFood
	ClassExit
	ClassKey
	ClassDoor
	ClassInfoBook
	ClassTrigger
	ClassTransporter
	ClassHole
	ClassWand
	ClassFire
	ClassElevator
	ClassElevatorShaft
	ClassDangerous
	ClassMonsterGenerator
	ClassReadable
	ClassLight
	ClassSimple
	ClassComplex
	ClassImmobile
	ClassVisibleEnable
	ClassWeapon
	ClassArmor
	ClassNotStackable
	ClassTreasure
	ClassFlag
	ClassClientPersist
	ClassClientPredict
	ClassPickup
)

const (
	MaskUnits = ClassPlayer | ClassMonster
)

func (c Class) Has(c2 Class) bool {
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
