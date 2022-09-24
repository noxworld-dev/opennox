package opennox

/*
#include "GAME3_3.h"
*/
import "C"
import (
	"errors"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

func nox_xxx_parseInitProc_536930(objt *ObjectType, _ *MemFile, str string, _ []byte) error {
	name := str
	if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
		name = str[:i]
		str = str[i+1:]
	}
	t, ok := noxObjectInitTable[name]
	if !ok {
		// TODO: add "unknown" init as a nop init types (similar to NoInit)
		return nil
	}
	objt.func_init = t.Func
	objt.init_data = nil
	objt.init_data_size = int32(t.DataSize)
	if t.DataSize == 0 {
		return nil
	}
	data, _ := alloc.Malloc(uintptr(t.DataSize))
	objt.init_data = data
	if t.ParseFunc != nil {
		if err := t.ParseFunc(objt, str); err != nil {
			return err
		}
	}
	return nil
}

func objectDirectionInitParse(objt *ObjectType, val string) error {
	p := unsafe.Slice((*int32)(objt.init_data), 2)
	sub := strings.SplitN(val, " ", 2)
	if len(sub) != 2 {
		return errors.New("expected two values")
	}
	v1, err := strconv.Atoi(sub[0])
	if err != nil {
		return err
	}
	v2, err := strconv.Atoi(sub[1])
	if err != nil {
		return err
	}
	p[0] = int32(v1)
	p[1] = int32(v2)
	return nil
}

var noxObjectInitTable = map[string]struct {
	Func      unsafe.Pointer
	DataSize  int
	ParseFunc func(objt *ObjectType, val string) error
}{
	"NoInit":         {},
	"MonsterInit":    {Func: C.nox_xxx_unitMonsterInit_4F0040},
	"ShopkeeperInit": {Func: C.nox_xxx_unitMonsterInit_4F0040, DataSize: 1724},
	"PlayerInit":     {Func: C.nox_xxx_unitInitPlayer_4EFE80},
	"ProjectileInit": {},
	"SparkInit":      {Func: C.nox_xxx_unitSparkInit_4F0390},
	"FrogInit":       {Func: C.nox_xxx_initFrog_4F03B0},
	"ChestInit":      {Func: C.nox_xxx_initChest_4F0400},
	"BoulderInit":    {Func: C.nox_xxx_unitBoulderInit_4F0420},
	"GruntInit":      {},
	"SkeletonInit":   {},
	"TowerInit":      {},
	"SkullInit":      {Func: C.sub_4F0450, DataSize: 8, ParseFunc: objectDirectionInitParse},
	"DirectionInit":  {Func: C.sub_4F0490, DataSize: 8, ParseFunc: objectDirectionInitParse},
	"GlyphInit":      {DataSize: 36},
	"ModifierInit":   {DataSize: 20},
	"GoldInit":       {Func: C.nox_xxx_unitInitGold_4F04B0, DataSize: 4},
	"BreakInit": {Func: C.nox_xxx_breakInit_4F0570, ParseFunc: func(objt *ObjectType, val string) error {
		objt.field_9 = 2
		return nil
	}},
	"MonsterGeneratorInit": {Func: C.nox_xxx_unitInitGenerator_4F0590},
	"RewardMarkerInit":     {DataSize: 220},
	"AnkhInit":             {DataSize: 5124},
}
