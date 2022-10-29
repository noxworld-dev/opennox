package opennox

/*
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_3.h"
*/
import "C"
import (
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectDamage("DefaultDamage", C.nox_xxx_damageDefaultProc_4E0B30)
	server.RegisterObjectDamage("SkeletonDamage", C.sub_4E23C0)
	server.RegisterObjectDamage("PlayerDamage", C.nox_server_handler_PlayerDamage_4E17B0)
	server.RegisterObjectDamage("StoneDamage", C.sub_4E24B0)
	server.RegisterObjectDamage("MechGolemDamage", C.sub_4E24E0)
	server.RegisterObjectDamage("FlammableDamage", C.nox_xxx_damageFlammable_4E2520)
	server.RegisterObjectDamage("BlackPowderDamage", C.nox_xxx_damageBlackPowder_4E2560)
	server.RegisterObjectDamage("ArmorDamage", C.nox_xxx_damageArmor_4E1500)
	server.RegisterObjectDamage("WeaponDamage", C.sub_4E14B0)
	server.RegisterObjectDamage("BallDamage", C.sub_4E14A0)
	server.RegisterObjectDamage("MonsterGeneratorDamage", C.nox_xxx_damageMonsterGen_4E27D0)

	server.RegisterObjectDamageSound("DefaultDamageSound", C.nox_xxx_soundDefaultDamageSound_532E20)
	server.RegisterObjectDamageSound("PlayerDamageSound", C.nox_xxx_soundPlayerDamageSound_5328B0)
}
