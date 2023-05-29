package legacy

import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectDeath("PlayerDie", nox_xxx_diePlayer_54D2B0, 0)
	server.RegisterObjectDeath("PotionDie", nox_xxx_diePotion_54CBB0, 0)
	server.RegisterObjectDeath("ImpEggDie", nox_xxx_dieImpEgg_54CAE0, 0)
	server.RegisterObjectDeath("GlyphDie", nox_xxx_dieGlyph_54DF30, 0)
	server.RegisterObjectDeath("BarrelDie", nox_xxx_dieBarrel_54DFA0, 0)
	server.RegisterObjectDeath("CreateObjectDie", nox_xxx_dieCreateObject_54E010, 132)
	server.RegisterObjectDeath("SpawnObjectDie", nox_xxx_dieSpawnObject_54E070, 132)
	server.RegisterObjectDeath("PolypDie", nox_xxx_diePolyp_54CB10, 0)
	server.RegisterObjectDeath("MarkerDie", nox_xxx_dieMarker_54E460, 0)
	server.RegisterObjectDeath("WeaponDie", nox_xxx_dieWeapon_54E370_obj_die, 0)
	server.RegisterObjectDeath("ArmorDie", nox_xxx_dieArmor_54E170_obj_die, 0)
	server.RegisterObjectDeath("BoulderDie", nox_xxx_dieBoulder_54E4B0, 0)
	server.RegisterObjectDeath("GameBallDie", nox_xxx_dieGameBall_54E620, 0)
	server.RegisterObjectDeath("MonsterGeneratorDie", nox_xxx_dieMonsterGen_54E630, 0)

	server.RegisterObjectDeathParse("CreateObjectDie", wrapObjectDeathParseC(sub_536B40))
	server.RegisterObjectDeathParse("SpawnObjectDie", wrapObjectDeathParseC(sub_536B40))
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
	return int(asFuncT[func(*byte, unsafe.Pointer) int32](uintptr(a1))(cstr, a3))
}
