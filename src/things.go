package opennox

/*
#include "memfile.h"
#include "defs.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME4.h"
extern uint32_t dword_5d4594_251540;
extern uint32_t dword_5d4594_251568;
extern uint32_t dword_5d4594_251572;
extern uint32_t dword_5d4594_1563664;
extern nox_objectType_t* nox_xxx_objectTypes_head_1563660;
int sub_485CF0();
int sub_485F30();
int sub_46A360();
int sub_4F0640();
int nox_read_things_alternative_4E2B60_DONE(void);
int sub_42BF10();
char* nox_xxx_equipWeapon_4131A0();
void nox_xxx_equipArmor_415AB0();
void nox_xxx_equipWeapon_4157C0();
void sub_4E29D0();
*/
import "C"
import (
	"fmt"
	"io"
	"unsafe"

	"github.com/noxworld-dev/noxcrypt"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	thingsLog              = log.New("things")
	noxLoadedThings        *MemFile
	nox_images_arr1_787156 []*noxImageRef
)

func getThingName(i int) string {
	return GoString(C.nox_get_thing_name(C.int(i)))
}

func thingsImageRef(ref *things.ImageRef) *Image {
	if ref == nil {
		return nil
	}
	return nox_xxx_readImgMB42FAA0(ref.Ind, byte(ref.Ind2), ref.Name)
}

func openThings() (*MemFile, error) {
	thg := noxLoadedThings
	var err error
	if thg == nil {
		thg, err = loadMemfile("thing.bin", crypt.ThingBin)
		if err != nil {
			return nil, fmt.Errorf("failed to open things: %w", err)
		}
		noxLoadedThings = thg
	}
	_, err = thg.Seek(0, io.SeekStart)
	return thg, err
}

func closeThings() {
	if noxLoadedThings == nil {
		return
	}
	noxLoadedThings.Free()
	noxLoadedThings = nil
}

func nox_xxx_loadAllBinFiles_415470() error {
	if err := nox_xxx_parseSoundSetBin_424170("soundset.bin"); err != nil {
		return err
	}
	buf, freeBuf := alloc.Malloc(256 * 1024)
	defer freeBuf()
	if C.nox_xxx_parseModifierBin_412930(internCStr("modifier.bin"), (*C.char)(buf)) == 0 {
		return fmt.Errorf("failed to load modifiers")
	}

	thg, err := openThings()
	if err != nil {
		return err
	}
	if err := loadAllBinFileSections(thg, buf); err != nil {
		return err
	}
	return nil
}

func loadAllBinFileSections(thg *MemFile, buf unsafe.Pointer) error {
	s := noxServer
	C.dword_5d4594_251540 = 0
	C.dword_5d4594_251568 = 0
	C.dword_5d4594_251572 = 0
	isClient := noxflags.HasGame(noxflags.GameClient)
	for {
		sect := thg.ReadU32()
		if sect == 0 {
			break
		}
		switch sect {
		case 0x5350454C: // SPEL
			if err := s.nox_thing_read_SPEL_4156B0(thg, isClient); err != nil {
				return err
			}
		case 0x41554420: // AUD
			if noxflags.HasGame(noxflags.GameFlag22) {
				C.nox_thing_skip_AUD_414D40(thg.C())
			} else if C.nox_thing_read_audio_415660(thg.C(), (*C.char)(buf)) == 0 {
				return fmt.Errorf("failed to load audio")
			}
		case 0x41564E54: // AVNT
			if noxflags.HasGame(noxflags.GameFlag22) {
				C.nox_thing_skip_AVNT_452B00(thg.C())
			} else if C.nox_thing_read_AVNT_452890(thg.C(), buf) == 0 {
				return fmt.Errorf("failed to load AVNT")
			}
		case 0x57414C4C: // WALL
			if C.nox_thing_read_WALL_410900(thg.C(), (*C.char)(buf)) == 0 {
				return fmt.Errorf("failed to load walls")
			}
		case 0x464C4F52: // FLOR
			if C.nox_thing_read_FLOR_411540(thg.C(), (*C.uchar)(buf)) == 0 {
				return fmt.Errorf("failed to load floor")
			}
		case 0x45444745: // EDGE
			if C.nox_thing_read_EDGE_411850(thg.C(), (*C.uchar)(buf)) == 0 {
				return fmt.Errorf("failed to load edges")
			}
		case 0x4142494C: // ABIL
			if err := s.abilities.thingsReadAll(thg); err != nil {
				return err
			}
		case 0x494D4147: // IMAG
			if err := nox_thing_read_IMAG_415700(thg); err != nil {
				return err
			}
			return nil
		}
	}
	return nil
}

func nox_thing_read_IMAG_415700(f *MemFile) error {
	cnt := int(f.ReadU32())
	nox_images_arr1_787156 = make([]*noxImageRef, 0, cnt)
	for i := 0; i < cnt; i++ {
		if err := nox_thing_read_IMAG_one_42F660(f); err != nil {
			return fmt.Errorf("cannot read image %d: %w", i, err)
		}
	}
	return nil
}

func nox_thing_read_IMAG_one_42F660(f *MemFile) error {
	refP, _ := alloc.New(C.nox_things_imageRef_t{})
	ref := asImageRef((*C.nox_things_imageRef_t)(refP))
	nox_images_arr1_787156 = append(nox_images_arr1_787156, ref)

	name, _ := f.ReadString8()
	copy(unsafe.Slice((*byte)(unsafe.Pointer(&ref.name[0])), len(ref.name)), name)
	ref.name[len(name)] = 0

	kind := f.ReadI8()
	ref.ref_kind = C.char(kind)

	switch kind {
	case 1:
		ind := f.ReadI32()
		if ind == -1 {
			typ := f.ReadU8()
			name2, _ := f.ReadString8()
			if nox_xxx_loadImage_47A8C0(typ, name2) != nil {
				copy(unsafe.Slice((*byte)(unsafe.Pointer(&ref.name2[0])), len(ref.name2)), name2)
				ref.name2[len(name2)] = 0
				ref.field_25_0 = C.char(typ)
			} else {
				ref.field_25_0 = -1
			}
		}
		ref.field_24 = unsafe.Pointer(uintptr(ind))
		return nil
	case 2:
		sz := f.ReadU8()
		arr, _ := alloc.Make([]*nox_video_bag_image_t{}, sz)
		anim, _ := alloc.New(noxImageRefAnim{})
		anim.on_end = nil
		anim.images = &arr[0]
		anim.images_sz = C.uchar(sz)
		anim.field_2_1 = C.uchar(f.ReadU8())

		switch ityp, _ := f.ReadString8(); ityp {
		case "Loop":
			anim.anim_type = 2
		case "OneShot":
			anim.anim_type = 0
		default:
			return fmt.Errorf("unexpected anim type: %q", ityp)
		}
		for i := 0; i < len(arr); i++ {
			if ind := int(f.ReadI32()); ind == -1 {
				typ := f.ReadI8()
				name2, _ := f.ReadString8()
				arr[i] = nox_xxx_loadImage_47A8C0(byte(typ), name2).C()
			} else {
				arr[i] = bagImageByIndex(ind).C()
			}
		}
		ref.field_24 = unsafe.Pointer(anim.C())
		return nil
	default:
		return fmt.Errorf("unsupported image kind: %d", int(kind))
	}
}

func (s *Server) nox_read_things_alternative_4E2B60() error {
	s.objs.Clear()
	buf, bfree := alloc.Make([]byte{}, 256*1024)
	defer bfree()
	thg, err := openThings()
	if err != nil {
		return err
	}
	for {
		sect := thg.ReadU32()
		if sect == 0 {
			break
		}
		switch sect {
		case 0x5350454C: // SPEL
			C.nox_thing_skip_spells_415100(thg.C())
		case 0x4142494C: // ABIL
			C.nox_thing_read_ability_415320(thg.C())
		case 0x41554420: // AUD
			C.nox_thing_read_audio_502320(thg.C(), unsafe.Pointer(&buf[0]))
		case 0x41564E54: // AVNT
			C.nox_thing_read_AVNT_502120(thg.C(), unsafe.Pointer(&buf[0]))
		case 0x57414C4C: // WALL
			if C.nox_thing_read_WALL_414F60(thg.C(), unsafe.Pointer(&buf[0])) == 0 {
				return fmt.Errorf("nox_thing_read_WALL_414F60 failed")
			}
		case 0x464C4F52: // FLOR
			if C.nox_thing_read_FLOR_414DB0(thg.C()) == 0 {
				return fmt.Errorf("nox_thing_read_FLOR_414DB0 failed")
			}
		case 0x45444745: // EDGE
			if C.nox_thing_read_EDGE_414E70(thg.C(), unsafe.Pointer(&buf[0])) == 0 {
				return fmt.Errorf("nox_thing_read_EDGE_414E70 failed")
			}
		case 0x494D4147: // IMAG
			C.nox_thing_read_image_415240(thg.C())
		case 0x54484E47: // THNG
			if err := s.objs.readType(thg, buf); err != nil {
				return err
			}
		}
	}
	*memmap.PtrUint32(0x85B3FC, 960) = 1
	if err := s.objs.checkTypes(); err != nil {
		return err
	}
	if C.nox_read_things_alternative_4E2B60_DONE() == 0 {
		return fmt.Errorf("nox_read_things_alternative_4E2B60_DONE failed")
	}
	C.sub_4E29D0()
	C.nox_xxx_equipWeapon_4131A0()
	C.nox_xxx_equipArmor_415AB0()
	C.nox_xxx_equipWeapon_4157C0()
	C.sub_4F0640()
	if C.sub_42BF10() == 0 {
		return fmt.Errorf("sub_42BF10 failed")
	}
	return nil
}

func nox_xxx_parseThingBinClient_44C840_read_things() error {
	nox_things.nox_things_free_44C580()
	C.sub_485CF0()
	C.sub_485F30()
	C.sub_46A360()

	thg, err := openThings()
	if err != nil {
		return err
	}

	buf, bfree := alloc.Make([]byte{}, 256*1024)
	defer bfree()

	for {
		sect := thg.ReadU32()
		if sect == 0 {
			break
		}
		switch sect {
		case 0x5350454C: // "SPEL"
			C.nox_thing_skip_spells_415100(thg.C())
		case 0x4142494C: // "ABIL"
			C.nox_thing_read_ability_415320(thg.C())
		case 0x41554420: // "AUD "
			C.nox_thing_skip_AUD_414D40(thg.C())
		case 0x41564E54: // "AVNT"
			C.nox_thing_skip_AVNT_452B00(thg.C())
		case 0x57414C4C: // "WALL"
			if C.nox_thing_read_wall_46A010(thg.C(), (*C.char)(unsafe.Pointer(&buf[0]))) == 0 {
				return fmt.Errorf("nox_thing_read_wall_46A010 failed")
			}
		case 0x464C4F52: // "FLOR"
			if C.nox_thing_read_floor_485B30(thg.C(), (*C.char)(unsafe.Pointer(&buf[0]))) == 0 {
				return fmt.Errorf("nox_thing_read_floor_485B30 failed")
			}
		case 0x45444745: // "EDGE"
			if C.nox_thing_read_edge_485D40(thg.C(), (*C.char)(unsafe.Pointer(&buf[0]))) == 0 {
				return fmt.Errorf("nox_thing_read_edge_485D40 failed")
			}
		case 0x494D4147: // "IMAG"
			C.nox_thing_read_image_415240(thg.C())
		case 0x54484E47: // "THNG"
			if err := nox_things.readType(thg, buf); err != nil {
				return err
			}
		}
	}
	C.nox_xxx_equipWeapon_4131A0()
	C.nox_xxx_equipArmor_415AB0()
	C.nox_xxx_equipWeapon_4157C0()
	if C.sub_42BF10() == 0 {
		return fmt.Errorf("sub_42BF10 failed")
	}
	return nil
}
