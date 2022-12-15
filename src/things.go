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
void nox_xxx_equipWeapon_4131A0();
void nox_xxx_equipArmor_415AB0();
void nox_xxx_equipWeapon_4157C0();
int sub_485CF0();
int sub_485F30();
int sub_46A360();
int sub_4F0640();
*/
import "C"
import (
	"fmt"
	"io"
	"unsafe"

	"github.com/noxworld-dev/noxcrypt"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	thingsLog                 = log.New("things")
	noxLoadedThings           *MemFile
	nox_images_arr1_787156    []*noxImageRef
	objectTypeCode16ByInd     []uint16
	objectTypeCode16ByInd_len int
)

func getThingName(i int) string {
	return GoString(nox_get_thing_name(C.int(i)))
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
			if noxClient.Bag.LoadExternalImage(typ, name2) != nil {
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
				arr[i] = (*nox_video_bag_image_t)(noxClient.Bag.LoadExternalImage(byte(typ), name2).C())
			} else {
				arr[i] = (*nox_video_bag_image_t)(noxClient.Bag.ImageByIndex(ind).C())
			}
		}
		ref.field_24 = unsafe.Pointer(anim.C())
		return nil
	default:
		return fmt.Errorf("unsupported image kind: %d", int(kind))
	}
}

func (s *Server) nox_read_things_alternative_4E2B60() error {
	s.Server.FreeObjectTypes()
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
			s.Audio.ReadAUD(thg)
		case 0x41564E54: // AVNT
			s.Audio.ReadAVNT(thg)
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
			rd := things.NewReader(thg)
			th, err := rd.ReadThingSect()
			if n := rd.Buffered(); n != 0 {
				thg.Seek(-int64(n), io.SeekCurrent)
			}
			if err != nil {
				return err
			}
			if err = s.ReadObjectType(th); err != nil {
				return err
			}
		}
	}
	if err := s.CheckTypes(); err != nil {
		return err
	}
	C.nox_xxx_equipWeapon_4131A0()
	C.nox_xxx_equipArmor_415AB0()
	C.nox_xxx_equipWeapon_4157C0()
	C.sub_4F0640()
	sub_42BF10()
	return nil
}

func sub_42BF10() {
	if objectTypeCode16ByInd != nil {
		return
	}
	var sz int
	if noxflags.HasGame(noxflags.GameHost | noxflags.GameFlag22) {
		sz = int(nox_xxx_unitDefGetCount_4E3AC0())
	} else {
		if !noxflags.HasGame(noxflags.GameClient) {
			return
		}
		sz = len(nox_things.byInd)
	}
	objectTypeCode16ByInd = make([]uint16, sz)
	objectTypeCode16ByInd_len = 0
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
	sub_42BF10()
	return nil
}

//export sub_42BFB0
func sub_42BFB0() {
	objectTypeCode16ByInd = make([]uint16, len(objectTypeCode16ByInd))
	objectTypeCode16ByInd_len = 0
}

func nox_xxx_free_42BF80() {
	objectTypeCode16ByInd = nil
}

//export nox_xxx_objectTOCgetTT_42C2B0
func nox_xxx_objectTOCgetTT_42C2B0(a1 C.ushort) C.int {
	return C.int(nox_xxx_objectTOCgetTT(uint16(a1)))
}

func nox_xxx_objectTOCgetTT(a1 uint16) int {
	for i, v := range objectTypeCode16ByInd {
		if v == a1 {
			return i
		}
	}
	return 0
}

//export sub_42C310
func sub_42C310(a1 C.int, a2 C.ushort) {
	if objectTypeCode16ByInd == nil {
		return
	}
	objectTypeCode16ByInd[int(a1)] = uint16(a2)
}

//export sub_42C2E0
func sub_42C2E0(a1 C.int) C.ushort {
	if objectTypeCode16ByInd == nil {
		return 0
	}
	return C.ushort(objectTypeCode16ByInd[int(a1)])
}

//export sub_42C300
func sub_42C300() C.ushort {
	return C.ushort(objectTypeCode16ByInd_len)
}

//export sub_42BFE0
func sub_42BFE0() {
	s := noxServer
	if !noxflags.HasGame(noxflags.GameHost | noxflags.GameFlag22) {
		return
	}
	sub_42BFB0()
	last := uint16(1)
	checkInd := func(ind uint16) {
		if val := objectTypeCode16ByInd[ind]; val == 0 {
			objectTypeCode16ByInd[ind] = last
			objectTypeCode16ByInd_len++
			last++
		}
	}
	for it := asObjectS(s.Objs.List); it != nil; it = it.Next() {
		checkInd(it.TypeInd)
		for it2 := it.FirstItem(); it2 != nil; it2 = it2.NextItem() {
			checkInd(it2.TypeInd)
		}
		if it.Class().Has(object.ClassMonsterGenerator) {
			checkTypesMonsterGen(it, checkInd)
		}
	}
	for it := asObjectS(s.Objs.Pending); it != nil; it = it.Next() {
		checkInd(it.TypeInd)
		if it.Class().Has(object.ClassMonsterGenerator) {
			checkTypesMonsterGen(it, checkInd)
		}
	}
	for it := asObjectS(s.Objs.UpdatableList2); it != nil; it = it.Next() {
		checkInd(it.TypeInd)
	}
	if !noxflags.HasGame(noxflags.GameFlag22) && noxflags.HasGame(noxflags.GameHost) &&
		noxflags.HasGame(noxflags.GameClient) && !noxflags.HasGame(noxflags.GameFlag23) {
		for it := asDrawable(C.sub_45A060()); it != nil; it = asDrawable(C.sub_45A070(it.C())) {
			ind := int(it.field_27)
			if sub_4E3AD0(C.int(ind)) == 0 && sub_4E3B80(C.int(ind)) != 0 {
				checkInd(uint16(ind))
			}
		}
	}
}

func checkTypesMonsterGen(obj *Object, checkInd func(uint162 uint16)) {
	arr := unsafe.Slice((**nox_object_t)(obj.UpdateData), 12)
	for i := 0; i < 3; i++ {
		for j := 0; j < 4; j++ {
			obj4 := asObjectC(arr[4*i+j])
			if obj4 != nil {
				checkInd(obj4.TypeInd)
				for it2 := obj4.FirstItem(); it2 != nil; it2 = it2.NextItem() {
					checkInd(it2.TypeInd)
				}
			}
		}
	}
}

//export sub_4E3AD0
func sub_4E3AD0(ind C.int) C.int {
	if memmap.Uint32(0x5D4594, 1563904) == 0 {
		*memmap.PtrUint32(0x5D4594, 1563904) = uint32(noxServer.ObjectTypeID("Pixie"))
	}
	typ := noxServer.ObjectTypeByInd(int(ind))
	if cl := typ.Class(); !cl.Has(object.ClassMissile) && cl.Has(object.ClassImmobile) && !cl.Has(object.ClassVisibleEnable) {
		if f := typ.Flags(); f.Has(object.FlagNoCollide) && !f.Has(object.FlagShadow) {
			return 0
		}
	}
	return 1
}
