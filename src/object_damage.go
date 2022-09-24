package opennox

/*
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_3.h"
*/
import "C"
import (
	"strings"
	"unsafe"
)

func nox_xxx_parseDamageFn_536C60(objt *ObjectType, _ *MemFile, str string, _ []byte) error {
	name := str
	if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
		name = str[:i]
		str = str[i+1:]
	}
	fnc := noxObjectDamageTable[name]
	objt.func_damage = fnc
	return nil
}

func nox_xxx_parseDamageSound_536CF0(objt *ObjectType, _ *MemFile, str string, _ []byte) error {
	name := str
	if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
		name = str[:i]
		str = str[i+1:]
	}
	fnc := noxObjectDamageSoundTable[name]
	objt.func_damage_sound = fnc
	return nil
}

var noxObjectDamageTable = map[string]unsafe.Pointer{
	"DefaultDamage":          C.nox_xxx_damageDefaultProc_4E0B30,
	"SkeletonDamage":         C.sub_4E23C0,
	"PlayerDamage":           C.nox_server_handler_PlayerDamage_4E17B0,
	"StoneDamage":            C.sub_4E24B0,
	"MechGolemDamage":        C.sub_4E24E0,
	"FlammableDamage":        C.nox_xxx_damageFlammable_4E2520,
	"BlackPowderDamage":      C.nox_xxx_damageBlackPowder_4E2560,
	"ArmorDamage":            C.nox_xxx_damageArmor_4E1500,
	"WeaponDamage":           C.sub_4E14B0,
	"BallDamage":             C.sub_4E14A0,
	"MonsterGeneratorDamage": C.nox_xxx_damageMonsterGen_4E27D0,
}

var noxObjectDamageSoundTable = map[string]unsafe.Pointer{
	"DefaultDamageSound": C.nox_xxx_soundDefaultDamageSound_532E20,
	"PlayerDamageSound":  C.nox_xxx_soundPlayerDamageSound_5328B0,
}
