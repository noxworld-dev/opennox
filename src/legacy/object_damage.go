package legacy

import (
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectDamage("DefaultDamage", ccall.FuncAddr(nox_xxx_damageDefaultProc_4E0B30))
	server.RegisterObjectDamage("SkeletonDamage", ccall.FuncAddr(sub_4E23C0))
	server.RegisterObjectDamage("PlayerDamage", ccall.FuncAddr(nox_server_handler_PlayerDamage_4E17B0))
	server.RegisterObjectDamage("StoneDamage", ccall.FuncAddr(sub_4E24B0))
	server.RegisterObjectDamage("MechGolemDamage", ccall.FuncAddr(sub_4E24E0))
	server.RegisterObjectDamage("FlammableDamage", ccall.FuncAddr(nox_xxx_damageFlammable_4E2520))
	server.RegisterObjectDamage("BlackPowderDamage", ccall.FuncAddr(nox_xxx_damageBlackPowder_4E2560))
	server.RegisterObjectDamage("ArmorDamage", ccall.FuncAddr(nox_xxx_damageArmor_4E1500))
	server.RegisterObjectDamage("WeaponDamage", ccall.FuncAddr(sub_4E14B0))
	server.RegisterObjectDamage("BallDamage", ccall.FuncAddr(sub_4E14A0))
	server.RegisterObjectDamage("MonsterGeneratorDamage", ccall.FuncAddr(nox_xxx_damageMonsterGen_4E27D0))

	server.RegisterObjectDamageSound("DefaultDamageSound", ccall.FuncAddr(nox_xxx_soundDefaultDamageSound_532E20))
	server.RegisterObjectDamageSound("PlayerDamageSound", ccall.FuncAddr(nox_xxx_soundPlayerDamageSound_5328B0))
}
