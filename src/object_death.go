package opennox

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

	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

func nox_xxx_parseDieProc_536B80(objt *ObjectType, d *things.ProcFunc) error {
	t, ok := noxObjectDeathTable[d.Name]
	if !ok {
		// TODO: add "unknown" death as a nop types
		return nil
	}
	objt.die = t.Func
	objt.dieData = nil
	if t.DataSize == 0 {
		return nil
	}
	data, _ := alloc.Malloc(uintptr(t.DataSize))
	objt.dieData = data
	if t.ParseFunc != nil {
		cstr := CString(strings.Join(d.Args, " "))
		defer StrFree(cstr)
		if C.nox_call_objectType_parseDeath_go((*[0]byte)(t.ParseFunc), cstr, data) == 0 {
			return fmt.Errorf("cannot parse death data for %q", d.Name)
		}
	}
	return nil
}

var noxObjectDeathTable = map[string]struct {
	Func      unsafe.Pointer
	DataSize  int
	ParseFunc unsafe.Pointer
}{
	"PlayerDie":           {Func: C.nox_xxx_diePlayer_54D2B0},
	"PotionDie":           {Func: C.nox_xxx_diePotion_54CBB0},
	"ImpEggDie":           {Func: C.nox_xxx_dieImpEgg_54CAE0},
	"GlyphDie":            {Func: C.nox_xxx_dieGlyph_54DF30},
	"BarrelDie":           {Func: C.nox_xxx_dieBarrel_54DFA0},
	"CreateObjectDie":     {Func: C.nox_xxx_dieCreateObject_54E010, DataSize: 132, ParseFunc: C.sub_536B40},
	"SpawnObjectDie":      {Func: C.nox_xxx_dieSpawnObject_54E070, DataSize: 132, ParseFunc: C.sub_536B40},
	"PolypDie":            {Func: C.nox_xxx_diePolyp_54CB10},
	"MarkerDie":           {Func: C.nox_xxx_dieMarker_54E460},
	"WeaponDie":           {Func: C.nox_xxx_dieWeapon_54E370_obj_die},
	"ArmorDie":            {Func: C.nox_xxx_dieArmor_54E170_obj_die},
	"BoulderDie":          {Func: C.nox_xxx_dieBoulder_54E4B0},
	"GameBallDie":         {Func: C.nox_xxx_dieGameBall_54E620},
	"MonsterGeneratorDie": {Func: C.nox_xxx_dieMonsterGen_54E630},
}
