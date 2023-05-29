package legacy

import "github.com/noxworld-dev/opennox/v1/server"

func init() {
	server.RegisterObjectDamage("DefaultDamage", nox_xxx_damageDefaultProc_4E0B30)
	server.RegisterObjectDamage("SkeletonDamage", sub_4E23C0)
	server.RegisterObjectDamage("PlayerDamage", nox_server_handler_PlayerDamage_4E17B0)
	server.RegisterObjectDamage("StoneDamage", sub_4E24B0)
	server.RegisterObjectDamage("MechGolemDamage", sub_4E24E0)
	server.RegisterObjectDamage("FlammableDamage", nox_xxx_damageFlammable_4E2520)
	server.RegisterObjectDamage("BlackPowderDamage", nox_xxx_damageBlackPowder_4E2560)
	server.RegisterObjectDamage("ArmorDamage", nox_xxx_damageArmor_4E1500)
	server.RegisterObjectDamage("WeaponDamage", sub_4E14B0)
	server.RegisterObjectDamage("BallDamage", sub_4E14A0)
	server.RegisterObjectDamage("MonsterGeneratorDamage", nox_xxx_damageMonsterGen_4E27D0)

	server.RegisterObjectDamageSound("DefaultDamageSound", nox_xxx_soundDefaultDamageSound_532E20)
	server.RegisterObjectDamageSound("PlayerDamageSound", nox_xxx_soundPlayerDamageSound_5328B0)
}
