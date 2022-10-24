package opennox

/*
#include "defs.h"
*/
import "C"
import (
	"errors"
	"fmt"
	"io"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

type objectFieldFunc func(objt *ObjectType, f *MemFile, str string, buf []byte) error

func nox_thing_read_xxx_4E3220(f *MemFile, buf []byte, typ *ObjectType) error {
	for {
		sz := f.ReadU8()
		if sz == 0 {
			return nil
		}
		if _, err := io.ReadFull(f, buf[:sz]); err != nil {
			return fmt.Errorf("cannot read object type: %w", err)
		}
		buf[sz] = 0
		str := string(buf[:sz])
		name := str
		if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
			name = str[:i]
			str = str[i+1:]
		}
		parseFnc := noxObjectFieldByName[name]
		if parseFnc == nil {
			continue
		}
		if i := strings.IndexByte(str, '='); i >= 0 {
			str = str[i+1:]
		}
		str = strings.TrimSpace(str)
		if err := parseFnc(typ, f, str, buf); err != nil {
			return fmt.Errorf("parse of %q failed: %w", name, err)
		}
	}
}

func firstWord(s string) string {
	if i := strings.IndexAny(s, " \t\n\r"); i > 0 {
		return s[:i]
	}
	return s
}

var noxObjectFieldByName = map[string]objectFieldFunc{
	"CLASS": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseClassSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", objt.ID(), objt.Ind(), err)
		}
		objt.obj_class = uint32(v)
		return nil
	},
	"SUBCLASS": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseSubClassSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", objt.ID(), objt.Ind(), err)
		}
		objt.obj_subclass = uint32(v)
		return nil
	},
	"EXTENT": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := things.ParseExtent(str)
		if err != nil {
			return fmt.Errorf("cannot parse %q: %w", str, err)
		}
		s := &objt.shape
		*s = noxShape{}
		switch v := v.(type) {
		case nil:
			s.kind = shapeKindNone
		case things.Center:
			s.kind = shapeKindCenter
		case things.Circle:
			s.kind = shapeKindCircle
			s.circle.R = v.R
			s.circle.R2 = v.R * v.R
		case things.Box:
			s.kind = shapeKindBox
			s.box.W = v.W
			s.box.H = v.H
			s.box.Calc()
		default:
			return fmt.Errorf("unsupported shape type: %T", v)
		}
		return nil
	},
	"FLAGS": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseFlagSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", objt.ID(), objt.Ind(), err)
		}
		objt.obj_flags = uint32(v)
		return nil
	},
	"MATERIAL": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseMaterialSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", objt.ID(), objt.Ind(), err)
		}
		objt.material = uint16(v)
		return nil
	},
	"CARRYCAPACITY": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseUint(firstWord(str), 10, 16)
		if err != nil {
			return err
		}
		objt.carry_capacity = uint16(v)
		return nil
	},
	"LIGHTINTENSITY": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		return nil // server doesn't need that
	},
	"MASS": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseFloat(firstWord(str), 32)
		if err != nil {
			return err
		}
		objt.mass = float32(v)
		return nil
	},
	"SPEED": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.Atoi(firstWord(str))
		if err != nil {
			return err
		}
		fv := float32(float64(v) / 32)
		objt.float_33 = 0
		objt.speed = fv
		objt.speed_2 = fv
		return nil
	},
	"WEIGHT": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseUint(firstWord(str), 10, 8)
		if err != nil {
			return err
		}
		objt.weight = byte(v)
		return nil
	},
	"WORTH": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseUint(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		objt.worth = uint32(v)
		return nil
	},
	"EXPERIENCE": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseFloat(firstWord(str), 32)
		if err != nil {
			return err
		}
		objt.experience = float32(v)
		return nil
	},
	"ZSIZE": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		sub := strings.SplitN(str, " ", 2)
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
		if v2 < v1 {
			v2 = v1
		}
		objt.zsize1 = float32(v1)
		objt.zsize2 = float32(v2)
		return nil
	},
	"HEALTH": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseInt(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		if objt.health_data != nil {
			alloc.Free(unsafe.Pointer(objt.health_data))
		}
		data, _ := alloc.New(objectHealthData{})
		objt.health_data = data
		data.cur = uint16(v)
		data.max = uint16(v)
		return nil
	},
	"MENUICON": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		objt.menu_icon = f.ReadI32()
		if objt.menu_icon == -1 {
			f.Skip(1)
			f.SkipString8()
		}
		return nil
	},
	"PRETTYIMAGE": func(objt *ObjectType, f *MemFile, str string, buf []byte) error {
		ind := f.ReadI32()
		if ind == -1 {
			f.Skip(1)
			f.SkipString8()
		}
		return nil
	},
	"COLLIDE":     nox_xxx_parseCollide_536EC0,
	"DAMAGE":      nox_xxx_parseDamageFn_536C60,
	"DAMAGESOUND": nox_xxx_parseDamageSound_536CF0,
	"DIE":         nox_xxx_parseDieProc_536B80,
	"DROP":        nox_xxx_parseDrop_536A20,
	"INIT":        nox_xxx_parseInitProc_536930,
	"CREATE":      nox_xxx_parseCreateProc_536830,
	"PICKUP":      nox_xxx_parsePickup_536710,
	"UPDATE":      nox_xxx_parseUpdate_536620,
	"USE":         nox_xxx_parseUseFn_5363F0,
	"XFER":        nox_xxx_parseXFer_5360A0,
	"DRAW":        nox_xxx_parseDraw_535CD0,
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

var playerAnimNames = []string{
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

func nox_xxx_parseDraw_535CD0(objt *ObjectType, f *MemFile, str string, buf []byte) error {
	name, _ := f.ReadString8()
	sectSz := int(f.ReadU64Align())
	switch name {
	default:
		f.Skip(sectSz)
		return nil
	case "MonsterDraw":
		ud := objt.updateDataMonster()
		if ud == nil {
			return errors.New("no monster update data")
		}
		anims, _ := alloc.Make([]monsterAnim{}, 16)
		ud.field_119 = unsafe.Pointer(&anims[0])
		var hdr [4]byte
		for {
			n, _ := f.Read(hdr[:])
			swap4(hdr[:])
			switch string(hdr[:n]) {
			default:
				return fmt.Errorf("invalid section name: %q", string(hdr[:n]))
			case "END ":
				return nil
			case "STAT":
				ind := int(f.ReadU8())
				if ind >= len(anims) {
					return errors.New("unexpected animation index")
				}
				ani := &anims[ind]

				snd, _ := f.ReadString8()
				ani.sound = uint32(sound.ByName(snd))

				v51, _ := f.ReadBytes8()
				ani.field8 = byte(copy(ani.data4[:len(v51)], v51))

				ani.frames = f.ReadU8()
				ani.field10 = f.ReadU8()

				kind, _ := f.ReadString8()
				ani.loop = uint32(bool2int(kind == "Loop" || kind == "LoopAndFade"))

				for i := 0; i < 8*int(ani.frames); i++ {
					if f.ReadI32() == -1 {
						f.Skip(1)
						f.SkipString8()
					}
				}
			}
		}
	case "PlayerDraw":
		var (
			hdr [4]byte
			ssz int
		)
		for {
			n, _ := f.Read(hdr[:])
			swap4(hdr[:])
			switch string(hdr[:n]) {
			default:
				return fmt.Errorf("invalid section name: %q", string(hdr[:n]))
			case "END ":
				return nil
			case "STAT":
				name, _ := f.ReadString8()
				ind := -1
				for i, s := range playerAnimNames {
					if name == s {
						ind = i
						break
					}
				}
				if ind < 0 {
					return fmt.Errorf("unsupported player animation: %q", name)
				}
				v36 := f.ReadU8()
				v37 := f.ReadU8()
				f.SkipString8()
				playerAnimSetFrameRange(ind, int(v36), int(v37))
				ssz = int(v36)
			case "SEQU":
				f.SkipString8()
				for i := 0; i < 8*ssz; i++ {
					if f.ReadI32() == -1 {
						f.Skip(1)
						f.SkipString8()
					}
				}
			}
		}
	}
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
