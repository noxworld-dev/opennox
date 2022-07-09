package opennox

/*
#include "memfile.h"
#include "defs.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME2.h"
extern uint32_t dword_5d4594_251540;
extern uint32_t dword_5d4594_251568;
extern uint32_t dword_5d4594_251572;
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
)

var (
	thingsLog              = log.New("things")
	noxLoadedThings        *MemFile
	nox_images_arr1_787156 []*noxImageRef
)

func nox_get_thing_name(i int) string {
	return GoString(C.nox_get_thing_name(C.int(i)))
}

func thingsImageRef(ref *things.ImageRef) *Image {
	if ref == nil {
		return nil
	}
	return nox_xxx_readImgMB42FAA0(ref.Ind, byte(ref.Ind2), ref.Name)
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

	thg := noxLoadedThings
	if thg == nil {
		var err error
		thg, err = loadMemfile("thing.bin", crypt.ThingBin)
		if err != nil {
			return fmt.Errorf("failed to open things: %w", err)
		}
	}
	thg.Seek(0, io.SeekStart)
	if err := loadAllBinFileSections(thg, buf); err != nil {
		thg.Free()
		noxLoadedThings = nil
		return err
	}
	noxLoadedThings = thg
	return nil
}

func loadAllBinFileSections(thg *MemFile, buf unsafe.Pointer) error {
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
			if err := noxServer.nox_thing_read_SPEL_4156B0(thg, isClient); err != nil {
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
			if C.nox_thing_read_ABIL_415750(thg.C(), buf) == 0 {
				return fmt.Errorf("failed to load abilities")
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
