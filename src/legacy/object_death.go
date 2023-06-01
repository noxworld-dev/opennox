package legacy

import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectDeath("PlayerDie", ccall.FuncAddr(nox_xxx_diePlayer_54D2B0), 0)
	server.RegisterObjectDeath("PotionDie", ccall.FuncAddr(nox_xxx_diePotion_54CBB0), 0)
	server.RegisterObjectDeath("ImpEggDie", ccall.FuncAddr(nox_xxx_dieImpEgg_54CAE0), 0)
	server.RegisterObjectDeath("GlyphDie", ccall.FuncAddr(nox_xxx_dieGlyph_54DF30), 0)
	server.RegisterObjectDeath("BarrelDie", ccall.FuncAddr(nox_xxx_dieBarrel_54DFA0), 0)
	server.RegisterObjectDeath("CreateObjectDie", ccall.FuncAddr(nox_xxx_dieCreateObject_54E010), 132)
	server.RegisterObjectDeath("SpawnObjectDie", ccall.FuncAddr(nox_xxx_dieSpawnObject_54E070), 132)
	server.RegisterObjectDeath("PolypDie", ccall.FuncAddr(nox_xxx_diePolyp_54CB10), 0)
	server.RegisterObjectDeath("MarkerDie", ccall.FuncAddr(nox_xxx_dieMarker_54E460), 0)
	server.RegisterObjectDeath("WeaponDie", ccall.FuncAddr(nox_xxx_dieWeapon_54E370_obj_die), 0)
	server.RegisterObjectDeath("ArmorDie", ccall.FuncAddr(nox_xxx_dieArmor_54E170_obj_die), 0)
	server.RegisterObjectDeath("BoulderDie", ccall.FuncAddr(nox_xxx_dieBoulder_54E4B0), 0)
	server.RegisterObjectDeath("GameBallDie", ccall.FuncAddr(nox_xxx_dieGameBall_54E620), 0)
	server.RegisterObjectDeath("MonsterGeneratorDie", ccall.FuncAddr(nox_xxx_dieMonsterGen_54E630), 0)

	server.RegisterObjectDeathParse("CreateObjectDie", wrapObjectDeathParseC(ccall.FuncAddr(sub_536B40)))
	server.RegisterObjectDeathParse("SpawnObjectDie", wrapObjectDeathParseC(ccall.FuncAddr(sub_536B40)))
}

func wrapObjectDeathParseC(ptr unsafe.Pointer) server.ObjectParseFunc {
	return func(objt *server.ObjectType, args []string) error {
		if Nox_call_objectType_parseDeath_go(ptr, strings.Join(args, " "), objt.DeathData) == 0 {
			return fmt.Errorf("cannot parse death data for %q", objt.ID())
		}
		return nil
	}
}

func Nox_call_objectType_parseDeath_go(a1 unsafe.Pointer, a2 string, a3 unsafe.Pointer) int {
	cstr := CString(a2)
	defer StrFree(cstr)
	return int(ccall.AsFunc[func(*byte, unsafe.Pointer) int32](a1)(cstr, a3))
}
