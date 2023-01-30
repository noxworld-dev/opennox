package legacy

/*
#include "server__object__die__die.h"
#include "GAME4_3.h"
#include "GAME5.h"

static int nox_call_objectType_parseDeath_go(int (*fnc)(char*, void*), char* arg1, void* arg2) { return fnc(arg1, arg2); }
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectDeath("PlayerDie", C.nox_xxx_diePlayer_54D2B0, 0)
	server.RegisterObjectDeath("PotionDie", C.nox_xxx_diePotion_54CBB0, 0)
	server.RegisterObjectDeath("ImpEggDie", C.nox_xxx_dieImpEgg_54CAE0, 0)
	server.RegisterObjectDeath("GlyphDie", C.nox_xxx_dieGlyph_54DF30, 0)
	server.RegisterObjectDeath("BarrelDie", C.nox_xxx_dieBarrel_54DFA0, 0)
	server.RegisterObjectDeath("CreateObjectDie", C.nox_xxx_dieCreateObject_54E010, 132)
	server.RegisterObjectDeath("SpawnObjectDie", C.nox_xxx_dieSpawnObject_54E070, 132)
	server.RegisterObjectDeath("PolypDie", C.nox_xxx_diePolyp_54CB10, 0)
	server.RegisterObjectDeath("MarkerDie", C.nox_xxx_dieMarker_54E460, 0)
	server.RegisterObjectDeath("WeaponDie", C.nox_xxx_dieWeapon_54E370_obj_die, 0)
	server.RegisterObjectDeath("ArmorDie", C.nox_xxx_dieArmor_54E170_obj_die, 0)
	server.RegisterObjectDeath("BoulderDie", C.nox_xxx_dieBoulder_54E4B0, 0)
	server.RegisterObjectDeath("GameBallDie", C.nox_xxx_dieGameBall_54E620, 0)
	server.RegisterObjectDeath("MonsterGeneratorDie", C.nox_xxx_dieMonsterGen_54E630, 0)

	server.RegisterObjectDeathParse("CreateObjectDie", wrapObjectDeathParseC(C.sub_536B40))
	server.RegisterObjectDeathParse("SpawnObjectDie", wrapObjectDeathParseC(C.sub_536B40))
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
	return int(C.nox_call_objectType_parseDeath_go((*[0]byte)(a1), cstr, a3))
}
