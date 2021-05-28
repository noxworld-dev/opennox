package object

import "strings"

var classNames = []string{
	"MISSILE", "MONSTER", "PLAYER", "OBSTACLE", "FOOD", "EXIT", "KEY",
	"DOOR", "INFO_BOOK", "TRIGGER", "TRANSPORTER", "HOLE", "WAND", "FIRE",
	"ELEVATOR", "ELEVATOR_SHAFT", "DANGEROUS", "MONSTERGENERATOR", "READABLE", "LIGHT", "SIMPLE",
	"COMPLEX", "IMMOBILE", "VISIBLE_ENABLE", "WEAPON", "ARMOR", "NOT_STACKABLE", "TREASURE",
	"FLAG", "CLIENT_PERSIST", "CLIENT_PREDICT", "PICKUP",
}

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
