package opennox

import (
	"fmt"
	"io"
	"os"
	"unsafe"

	"github.com/noxworld-dev/noxcrypt"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	thingsLog                 = log.New("things")
	noxLoadedThings           *binfile.MemFile
	nox_images_arr1_787156    []*legacy.ImageRef
	objectTypeCode16ByInd     []uint16
	objectTypeCode16ByInd_len int
	dumpSpells                = os.Getenv("NOX_DUMP_SPELLS") == "true"
)

func getThingName(i int) string {
	t := noxClient.Things.TypeByInd(i)
	if t == nil {
		return ""
	}
	return t.ID()
}

func openThings() (*binfile.MemFile, error) {
	thg := noxLoadedThings
	var err error
	if thg == nil {
		thg, err = binfile.LoadMemFile("thing.bin", crypt.ThingBin)
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
	buf, freeBuf := alloc.Make([]byte{}, 256*1024)
	defer freeBuf()
	if err := noxServer.Modif.Nox_xxx_parseModifierBin_412930("modifier.bin"); err != nil {
		return fmt.Errorf("failed to load modifiers: %w", err)
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

func loadAllBinFileSections(thg *binfile.MemFile, buf []byte) error {
	s := noxServer
	s.Walls.ResetDefs()
	legacy.LoadAllBinFileSectionsResetCounters()
	for {
		sect := thg.ReadU32()
		if sect == 0 {
			break
		}
		switch sect {
		case 0x5350454C: // SPEL
			if err := s.Spells.Read(thg, func(ref *things.ImageRef) unsafe.Pointer {
				if !noxflags.HasGame(noxflags.GameClient) {
					return nil
				}
				return unsafe.Pointer(noxClient.r.Bag.ThingsImageRef(ref))
			}, dumpSpells); err != nil {
				return err
			}
		case 0x41554420: // AUD
			if noxflags.HasGame(noxflags.GameFlag22) {
				legacy.Nox_thing_skip_AUD_414D40(thg)
			} else if legacy.Nox_thing_read_audio_415660(thg, buf) == 0 {
				return fmt.Errorf("failed to load audio")
			}
		case 0x41564E54: // AVNT
			if noxflags.HasGame(noxflags.GameFlag22) {
				legacy.Nox_thing_skip_AVNT_452B00(thg)
			} else if legacy.Nox_thing_read_AVNT_452890(thg, buf) == 0 {
				return fmt.Errorf("failed to load AVNT")
			}
		case 0x57414C4C: // WALL
			if err := s.Walls.ReadWall(thg); err != nil {
				return err
			}
		case 0x464C4F52: // FLOR
			if legacy.Nox_thing_read_FLOR_411540(thg, buf) == 0 {
				return fmt.Errorf("failed to load floor")
			}
		case 0x45444745: // EDGE
			if legacy.Nox_thing_read_EDGE_411850(thg, buf) == 0 {
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

func nox_thing_read_IMAG_415700(f *binfile.MemFile) error {
	cnt := int(f.ReadU32())
	nox_images_arr1_787156 = make([]*legacy.ImageRef, 0, cnt)
	for i := 0; i < cnt; i++ {
		if err := nox_thing_read_IMAG_one_42F660(f); err != nil {
			return fmt.Errorf("cannot read image %d: %w", i, err)
		}
	}
	return nil
}

func nox_thing_read_IMAG_one_42F660(f *binfile.MemFile) error {
	ref, _ := alloc.New(legacy.ImageRef{})
	nox_images_arr1_787156 = append(nox_images_arr1_787156, ref)

	name, _ := f.ReadString8()
	ref.SetName(name)

	kind := f.ReadI8()
	ref.RefKind = int8(kind)

	switch kind {
	case 1:
		ind := f.ReadI32()
		if ind == -1 {
			typ := f.ReadU8()
			name2, _ := f.ReadString8()
			if noxClient.r.Bag.LoadExternalImage(typ, name2) != nil {
				ref.SetName2(name2)
				ref.Field_25_0 = int8(typ)
			} else {
				ref.Field_25_0 = -1
			}
		}
		ref.Field_24 = unsafe.Pointer(uintptr(ind))
		return nil
	case 2:
		sz := f.ReadU8()
		arr, _ := alloc.Make([]noxrender.ImageHandle{}, sz)
		anim, _ := alloc.New(legacy.ImageRefAnim{})
		anim.OnEnd = nil
		anim.ImagesPtr = &arr[0]
		anim.ImagesSz = uint8(sz)
		anim.Field_2_1 = uint8(f.ReadU8())

		switch ityp, _ := f.ReadString8(); ityp {
		case "Loop":
			anim.AnimType = 2
		case "OneShot":
			anim.AnimType = 0
		default:
			return fmt.Errorf("unexpected anim type: %q", ityp)
		}
		for i := 0; i < len(arr); i++ {
			if ind := int(f.ReadI32()); ind == -1 {
				typ := f.ReadI8()
				name2, _ := f.ReadString8()
				arr[i] = noxClient.r.Bag.LoadExternalImage(byte(typ), name2).C()
			} else {
				arr[i] = noxClient.r.Bag.ImageByIndex(ind).C()
			}
		}
		ref.Field_24 = unsafe.Pointer(anim.C())
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
			legacy.Nox_thing_skip_spells_415100(thg)
		case 0x4142494C: // ABIL
			legacy.Nox_thing_read_ability_415320(thg)
		case 0x41554420: // AUD
			s.Audio.ReadAUD(thg)
		case 0x41564E54: // AVNT
			s.Audio.ReadAVNT(thg)
		case 0x57414C4C: // WALL
			if legacy.Nox_thing_read_WALL_414F60(thg, buf) == 0 {
				return fmt.Errorf("nox_thing_read_WALL_414F60 failed")
			}
		case 0x464C4F52: // FLOR
			if legacy.Nox_thing_read_FLOR_414DB0(thg) == 0 {
				return fmt.Errorf("nox_thing_read_FLOR_414DB0 failed")
			}
		case 0x45444745: // EDGE
			if legacy.Nox_thing_read_EDGE_414E70(thg, buf) == 0 {
				return fmt.Errorf("nox_thing_read_EDGE_414E70 failed")
			}
		case 0x494D4147: // IMAG
			legacy.Nox_thing_read_image_415240(thg)
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
	nox_xxx_equipWeapon_4131A0()
	legacy.Nox_xxx_equipArmor_415AB0()
	legacy.Nox_xxx_equipWeapon_4157C0()
	legacy.Sub_4F0640()
	sub_42BF10()
	return nil
}

func sub_42BF10() {
	c := noxClient
	if objectTypeCode16ByInd != nil {
		return
	}
	var sz int
	if noxflags.HasGame(noxflags.GameHost | noxflags.GameFlag22) {
		sz = c.srv.Types.Count()
	} else {
		if !noxflags.HasGame(noxflags.GameClient) {
			return
		}
		sz = c.Things.TypesCnt()
	}
	objectTypeCode16ByInd = make([]uint16, sz)
	objectTypeCode16ByInd_len = 0
}

func nox_xxx_parseThingBinClient_44C840_read_things() error {
	c := noxClient
	c.Nox_things_free_44C580()
	legacy.Sub_485CF0()
	legacy.Sub_485F30()
	c.srv.Walls.ResetSprites()

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
			legacy.Nox_thing_skip_spells_415100(thg)
		case 0x4142494C: // "ABIL"
			legacy.Nox_thing_read_ability_415320(thg)
		case 0x41554420: // "AUD "
			legacy.Nox_thing_skip_AUD_414D40(thg)
		case 0x41564E54: // "AVNT"
			legacy.Nox_thing_skip_AVNT_452B00(thg)
		case 0x57414C4C: // "WALL"
			if err := nox_thing_read_wall_46A010(thg, buf); err != nil {
				return err
			}
		case 0x464C4F52: // "FLOR"
			if legacy.Nox_thing_read_floor_485B30(thg, buf) == 0 {
				return fmt.Errorf("nox_thing_read_floor_485B30 failed")
			}
		case 0x45444745: // "EDGE"
			if legacy.Nox_thing_read_edge_485D40(thg, buf) == 0 {
				return fmt.Errorf("nox_thing_read_edge_485D40 failed")
			}
		case 0x494D4147: // "IMAG"
			legacy.Nox_thing_read_image_415240(thg)
		case 0x54484E47: // "THNG"
			if err := c.Things.ReadType(thg, buf); err != nil {
				return err
			}
		}
	}
	nox_xxx_equipWeapon_4131A0()
	legacy.Nox_xxx_equipArmor_415AB0()
	legacy.Nox_xxx_equipWeapon_4157C0()
	sub_42BF10()
	return nil
}

func sub_42BFB0() {
	objectTypeCode16ByInd = make([]uint16, len(objectTypeCode16ByInd))
	objectTypeCode16ByInd_len = 0
}

func nox_xxx_free_42BF80() {
	objectTypeCode16ByInd = nil
}

func nox_xxx_objectTOCgetTT(a1 uint16) int {
	for i, v := range objectTypeCode16ByInd {
		if v == a1 {
			return i
		}
	}
	return 0
}

func sub_42C310(a1 int, a2 uint16) {
	if objectTypeCode16ByInd == nil {
		return
	}
	objectTypeCode16ByInd[a1] = a2
}

func sub_42C2E0(a1 int) uint16 {
	if objectTypeCode16ByInd == nil {
		return 0
	}
	return objectTypeCode16ByInd[a1]
}

func sub_42C300() uint16 {
	return uint16(objectTypeCode16ByInd_len)
}

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
		for it := noxClient.Objs.FirstList1(); it != nil; it = it.Next() {
			ind := int(it.Field_27)
			if sub_4E3AD0(ind) == 0 && sub_4E3B80(ind) {
				checkInd(uint16(ind))
			}
		}
	}
}

func checkTypesMonsterGen(obj *Object, checkInd func(uint162 uint16)) {
	arr := unsafe.Slice((**server.Object)(obj.UpdateData), 12)
	for i := 0; i < 3; i++ {
		for j := 0; j < 4; j++ {
			obj4 := arr[4*i+j]
			if obj4 != nil {
				checkInd(obj4.TypeInd)
				for it2 := obj4.FirstItem(); it2 != nil; it2 = it2.NextItem() {
					checkInd(it2.TypeInd)
				}
			}
		}
	}
}

func sub_4E3AD0(ind int) int {
	if memmap.Uint32(0x5D4594, 1563904) == 0 {
		*memmap.PtrUint32(0x5D4594, 1563904) = uint32(noxServer.Types.PixieID())
	}
	typ := noxServer.Types.ByInd(ind)
	if cl := typ.Class(); !cl.Has(object.ClassMissile) && cl.Has(object.ClassImmobile) && !cl.Has(object.ClassVisibleEnable) {
		if f := typ.Flags(); f.Has(object.FlagNoCollide) && !f.Has(object.FlagShadow) {
			return 0
		}
	}
	return 1
}
