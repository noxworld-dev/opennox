package opennox

import (
	"fmt"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

type XferFunc func(obj *Object, a2 unsafe.Pointer) error

func nox_xxx_xfer_saveObj51DF90(cf *cryptfile.CryptFile, a1p *server.Object) int {
	if a1p.Flags().Has(object.FlagDestroyed) {
		return 1
	}
	a1 := uint16(sub_42C2E0(int(a1p.TypeInd)))
	if a1 == 0 {
		return 0
	}
	cf.WriteU16(a1)
	cf.SectionStart()
	if err := a1p.CallXfer(nil); err != nil {
		mapLog.Println("nox_xxx_xfer_saveObj51DF90:", err)
		return 0
	}
	cf.SectionEnd()
	for it := a1p.FirstItem(); it != nil; it = it.NextItem() {
		nox_xxx_xfer_saveObj51DF90(cf, it)
	}
	return 1
}

func nox_xxx_XFerDefault4F49A0(cf *cryptfile.CryptFile, v1 *server.Object, a2 unsafe.Pointer) error {
	a1, _ := cf.ReadWriteU16(60)
	if int16(a1) > 60 {
		return fmt.Errorf("default xfer: unexpected value 1: %d", a1)
	}
	v2 := v1.Field34
	if legacy.Nox_xxx_mapReadWriteObjData_4F4530(v1, int(a1)) == 0 {
		return fmt.Errorf("default xfer: nox_xxx_mapReadWriteObjData_4F4530 failed")
	}
	if v1.Field34 == 0 || !cf.ReadOnly() {
		v1.Field34 = v2
		return nil
	}
	if legacy.Nox_xxx_xfer_4F3E30(int(a1), v1, v1.Field34) == 0 {
		return fmt.Errorf("default xfer: nox_xxx_xfer_4F3E30 failed")
	}
	v1.Field34 = v2
	return nil
}

func nox_xxx_XFer_ReadShopItem_52A840(a1 unsafe.Pointer, a2 int) {
	s := noxServer
	cf := cryptfile.Global()
	if a2 < 50 {
		// TODO: why it's unused?
		_, _ = cf.ReadU32()
	}
	b1, _ := cf.ReadU8()
	*(*uint8)(unsafe.Add(a1, 4)) = b1

	tname, _ := cf.ReadString8()
	var typ *server.ObjectType
	if tname != "" {
		typ = s.Types.ByID(tname)
		*(*int32)(unsafe.Add(a1, 0)) = int32(typ.Ind())
	}
	if a2 >= 47 {
		name, _ := cf.ReadString8()
		if name != "" {
			var v4 int
			switch typ.Xfer {
			case legacy.Get_nox_xxx_XFerFieldGuide_4F6390():
				v4 = s.Types.IndByID(name)
			case legacy.Get_nox_xxx_XFerAbilityReward_4F6240():
				v4 = int(s.abilities.nox_xxx_abilityNameToN_424D80(name))
			default:
				v4 = int(spell.ParseID(name))
			}
			*(*uint32)(unsafe.Add(a1, 8)) = uint32(v4)
		}
	}
	var mods [4]*server.ModifierEff
	for i := range mods {
		mname, _ := cf.ReadString8()
		if mname == "" {
			continue
		}
		mod := s.Modif.Nox_xxx_modifGetIdByName413290(mname)
		if mod >= 0 && mod != 255 {
			mods[i] = s.Modif.Nox_xxx_modifGetDescById413330(mod)
		}
	}

	*(*unsafe.Pointer)(unsafe.Add(a1, 12)) = mods[0].C()
	*(*unsafe.Pointer)(unsafe.Add(a1, 16)) = mods[1].C()
	*(*unsafe.Pointer)(unsafe.Add(a1, 20)) = mods[2].C()
	*(*unsafe.Pointer)(unsafe.Add(a1, 24)) = mods[3].C()
}

func nox_xxx_XFer_WriteShopItem_52A5F0(a1 unsafe.Pointer) {
	cf := cryptfile.Global()
	cf.WriteU8(*(*uint8)(unsafe.Add(a1, 4)))
	typ := noxServer.Types.ByInd(int(*(*int32)(unsafe.Add(a1, 0))))
	cf.WriteString8(typ.ID())
	pind := int(*(*int32)(unsafe.Add(a1, 8)))
	var pname string
	switch typ.Xfer {
	case legacy.Get_nox_xxx_XFerFieldGuide_4F6390():
		pname = noxServer.Types.ByInd(pind).ID()
	case legacy.Get_nox_xxx_XFerAbilityReward_4F6240():
		pname = server.Ability(pind).String()
	default:
		pname = spell.ID(pind).String()
	}
	cf.WriteString8(pname)
	mods := [4]*server.ModifierEff{
		*(**server.ModifierEff)(unsafe.Add(a1, 12)),
		*(**server.ModifierEff)(unsafe.Add(a1, 16)),
		*(**server.ModifierEff)(unsafe.Add(a1, 20)),
		*(**server.ModifierEff)(unsafe.Add(a1, 24)),
	}
	for _, m := range mods {
		if m != nil {
			cf.WriteString8(m.Name())
		} else {
			cf.WriteString8("")
		}
	}
}
