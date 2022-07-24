package opennox

/*
#include "GAME5.h"
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"
)

func nox_xxx_parseCreateProc_536830(objt *ObjectType, _ *MemFile, str string, _ []byte) error {
	name := str
	if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
		name = str[:i]
	}
	fnc, ok := noxObjectCreateTable[name]
	if !ok {
		return fmt.Errorf("unsupported create func: %q", name)
	}
	objt.func_new = fnc
	return nil
}

var noxObjectCreateTable = map[string]unsafe.Pointer{
	"NoCreate":               nil,
	"MonsterCreate":          C.nox_xxx_monsterCreateFn_54C480,
	"ArmorCreate":            C.sub_54C950,
	"WeaponCreate":           C.nox_xxx_createWeapon_54C710,
	"PlayerCreate":           nil,
	"ObeliskCreate":          C.nox_xxx_createFnObelisk_54CA10,
	"AnimCreate":             C.nox_xxx_createFnAnim_54CA50,
	"TriggerCreate":          C.nox_xxx_createTrigger_54CA60,
	"MonsterGeneratorCreate": C.nox_xxx_createMonsterGen_54CA90,
	"RewardMarkerCreate":     C.nox_xxx_createRewardMarker_54CAC0,
}
