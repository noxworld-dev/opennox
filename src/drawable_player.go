package opennox

import (
	"fmt"
	"slices"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	client.RegisterDraw("PlayerDraw", legacy.Get_nox_thing_player_draw(), 6, parsePlayerDraw)
}

func parsePlayerDraw(obj *client.ObjectType, f *binfile.MemFile, str string, buf []byte) error {
	dd, _ := alloc.New(client.PlayerDrawData{})
	dd.Size = uint32(unsafe.Sizeof(client.PlayerDrawData{}))
	tok := f.ReadU32()
	if tok == 0x454E4420 { // "END "
		return fmt.Errorf("unexpected end of player anim")
	}
loop:
	for {
		attr, _ := f.ReadString8()
		aind := slices.Index(server.PlayerAnimNames[:], attr)
		if aind < 0 {
			return fmt.Errorf("unsupported player animation: %q", attr)
		}
		panim := &dd.Anim[aind]
		if err := nox_xxx_loadVectorAnimated_44B8B0(&panim.Base, f); err != nil {
			return err
		}
		for {
			tok = f.ReadU32()
			if tok == 0x454E4420 { // "END "
				obj.DrawFunc = legacy.Get_nox_thing_player_draw()
				obj.DrawData = unsafe.Pointer(dd)
				return nil
			}
			if tok == 0x53544154 {
				continue loop
			}
			attr, _ = f.ReadString8()
			if attr == "NAKED" {
				p, _ := alloc.New(client.PlayerEquipAnimation{})
				panim.Naked = p
				if err := parsePlayerEquipAnim(p, int(panim.Base.Cnt40), f); err != nil {
					return err
				}
			} else if ind := slices.Index(server.PlayerArmorNames[:], attr); ind >= 0 {
				p, _ := alloc.New(client.PlayerEquipAnimation{})
				panim.Armor[ind] = p
				if err := parsePlayerEquipAnim(p, int(panim.Base.Cnt40), f); err != nil {
					return err
				}
			} else if ind = slices.Index(server.PlayerWeaponNames[:], attr); ind >= 0 {
				p, _ := alloc.New(client.PlayerEquipAnimation{})
				panim.Weapon[ind] = p
				if err := parsePlayerEquipAnim(p, int(panim.Base.Cnt40), f); err != nil {
					return err
				}
			} else {
				return fmt.Errorf("unsupported player animation: %q", attr)
			}
		}
	}
}

func parsePlayerEquipAnim(ani *client.PlayerEquipAnimation, cnt int, f *binfile.MemFile) error {
	ani.Size = uint32(unsafe.Sizeof(client.PlayerEquipAnimation{}))
	for i := 0; i < 8; i++ {
		k := i
		if i >= 4 {
			k = i + 1
		}
		arr, _ := alloc.Make([]noxrender.ImageHandle{}, cnt)
		ani.Frames[k] = &arr[0]
		for j := 0; j < cnt; j++ {
			ind := int(f.ReadI32())
			var (
				typ   byte
				name2 string
			)
			if ind == -1 {
				typ = f.ReadU8()
				name2, _ = f.ReadString8()
			}
			arr[j] = noxClient.r.Bag.ImageRef(ind, typ, name2).C()
		}
	}
	return nil
}
