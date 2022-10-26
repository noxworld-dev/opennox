package opennox

/*
#include "defs.h"
*/
import "C"
import (
	"errors"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func firstWord(s string) string {
	if i := strings.IndexAny(s, " \t\n\r"); i > 0 {
		return s[:i]
	}
	return s
}

var _ = [1]struct{}{}[16-unsafe.Sizeof(monsterAnim{})]

type monsterAnim struct {
	sound   uint32  // 0, 0
	data4   [4]byte // 1, 4
	field8  byte    // 2, 8
	frames  byte    // 2, 9
	field10 byte    // 2, 10
	field11 byte    // 2, 11
	loop    uint32  // 3, 12
}

var playerAnimTypes = []things.PlayerAnimType{
	"IDLE",
	"DIE",
	"DEAD",
	"JUMP",
	"WALK",
	"WALK_AND_DRAG",
	"RUN",
	"RUNNING_JUMP",
	"PICKUP",
	"DODGE_LEFT",
	"DODGE_RIGHT",
	"ELECTROCUTED",
	"FALL",
	"TRIP",
	"GET_UP",
	"LAUGH",
	"POINT",
	"SIT",
	"SLEEP",
	"TALK",
	"TAUNT",
	"CAST_SPELL",
	"CONCENTRATE",
	"PUNCH_LEFT",
	"PUNCH_RIGHT",
	"PUNCH_RIGHT_HOOK",
	"MACE_STRIKE",
	"SWORD_STRIKE",
	"LONG_SWORD_STRIKE",
	"STAFF_STRIKE",
	"STAFF_BLOCK",
	"STAFF_SPELL_BLAST",
	"STAFF_THRUST",
	"SHOOT_BOW",
	"SHOOT_CROSSBOW",
	"AXE_STRIKE",
	"GREAT_SWORD_PARRY",
	"GREAT_SWORD_STRIKE",
	"GREAT_SWORD_IDLE",
	"HAMMER_STRIKE",
	"RAISE_SHIELD",
	"RECOIL_FORWARD",
	"RECOIL_BACKWARD",
	"RECOIL_SHIELD",
	"CHAKRAM_STRIKE",
	"BERSERKER_CHARGE",
	"WARCRY",
	"GREAT_SWORD_BLOCK_LEFT",
	"GREAT_SWORD_BLOCK_RIGHT",
	"GREAT_SWORD_BLOCK_DOWN",
	"ELECTRIC_ZAP",
	"DUST",
	"RECOIL",
	"SNEAK",
	"HARPOONTHROW",
}

func nox_xxx_parseDraw_535CD0(objt *ObjectType, d things.Draw) error {
	switch d := d.(type) {
	case things.MonsterDraw:
		ud := objt.updateDataMonster()
		if ud == nil {
			return errors.New("no monster update data")
		}
		anims, _ := alloc.Make([]monsterAnim{}, 16)
		ud.field_119 = unsafe.Pointer(&anims[0])
		for _, st := range d.Anims {
			if int(st.Type) >= len(anims) {
				return errors.New("unexpected animation index")
			}
			ani := monsterAnim{
				sound:   uint32(sound.ByName(st.Sound)),
				frames:  st.FramesPerDir,
				field10: st.Field10,
				loop:    uint32(bool2int(st.Kind == things.AnimationLoop || st.Kind == things.AnimationLoopAndFade)),
			}
			anims[st.Type] = ani
		}
	case things.PlayerDraw:
		for name, st := range d.Anims {
			ind := -1
			for i, s := range playerAnimTypes {
				if name == s {
					ind = i
					break
				}
			}
			if ind >= 0 {
				playerAnimSetFrameRange(ind, int(st.FramesPerDir), int(st.Field8))
			}
		}
	}
	return nil
}

func playerAnimSetFrameRange(i int, v1, v2 int) {
	*memmap.PtrUint32(0x5D4594, 1568412+8*uintptr(i)) = uint32(v1)
	*memmap.PtrUint32(0x5D4594, 1568416+8*uintptr(i)) = uint32(v2)
}

func playerAnimGetFrameRange(i int) (_, _ int) {
	return int(memmap.Uint32(0x5D4594, 1568412+8*uintptr(i))),
		int(memmap.Uint32(0x5D4594, 1568416+8*uintptr(i)))
}

//export nox_xxx_animPlayerGetFrameRange_4F9F90
func nox_xxx_animPlayerGetFrameRange_4F9F90(a1 int, a2, a3 *C.int) {
	v1, v2 := playerAnimGetFrameRange(a1)
	if a2 != nil {
		*a2 = C.int(v1)
	}
	if a3 != nil {
		*a3 = C.int(v2)
	}
}
