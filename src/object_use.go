package opennox

/*
#include "GAME4_3.h"

static int nox_call_objectType_parseUse_go(int (*fnc)(char*, void*), char* arg1, void* arg2) { return fnc(arg1, arg2); }
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

func nox_xxx_parseUseFn_5363F0(objt *ObjectType, d *things.ProcFunc) error {
	t, ok := noxObjectUseTable[d.Name]
	if !ok {
		// TODO: add "unknown" use as a nop types
		return nil
	}
	objt.use = t.Func
	objt.useData = nil
	objt.useDataSize = t.DataSize
	if t.DataSize == 0 {
		return nil
	}
	data, _ := alloc.Malloc(uintptr(t.DataSize))
	objt.useData = data
	if t.ParseFunc != nil {
		cstr := CString(strings.Join(d.Args, " "))
		defer StrFree(cstr)
		if C.nox_call_objectType_parseUse_go((*[0]byte)(t.ParseFunc), cstr, data) == 0 {
			return fmt.Errorf("cannot parse collide data for %q", d.Name)
		}
	}
	return nil
}

var noxObjectUseTable = map[string]struct {
	Func      unsafe.Pointer
	DataSize  int
	ParseFunc unsafe.Pointer
}{
	"ConsumeUse":        {Func: C.nox_xxx_useConsume_53EE10, DataSize: 4, ParseFunc: C.sub_536390},
	"ConsumeConfuseUse": {Func: C.nox_xxx_useCiderConfuse_53EF00, DataSize: 4, ParseFunc: C.sub_536390},
	"FireWandUse":       {Func: C.nox_xxx_useFireWand_53F670},
	"CastUse":           {Func: C.nox_xxx_useCast_53ED90, DataSize: 4, ParseFunc: C.sub_536180},
	"EnchantUse":        {Func: C.nox_xxx_useEnchant_53ED60, DataSize: 8, ParseFunc: C.sub_536130},
	"MushroomUse":       {Func: C.nox_xxx_useMushroom_53ECE0},
	"ReadUse":           {Func: C.nox_xxx_useRead_53F7C0, DataSize: 260},
	"WarpReadUse":       {Func: C.sub_53F830, DataSize: 260},
	"WandUse":           {Func: C.nox_xxx_useLesserFireballStaff_53F290, DataSize: 116, ParseFunc: C.sub_536260},
	"WandCastUse":       {Func: C.nox_xxx_useWandCastSpell_53F4F0, DataSize: 116, ParseFunc: C.sub_5361B0},
	"SpellRewardUse":    {Func: C.nox_xxx_useSpellReward_53F9E0, DataSize: 1},
	"AbilityRewardUse":  {Func: C.nox_xxx_useAbilityReward_53FAE0, DataSize: 1},
	"FieldGuideUse":     {Func: C.sub_53F930, DataSize: 64},
	"PotionUse":         {Func: C.nox_xxx_usePotion_53EF70, DataSize: 4, ParseFunc: C.sub_5363C0},
	"AmmoUse":           {DataSize: 3},
	"BowUse":            {DataSize: 1},
}
