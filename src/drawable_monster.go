package opennox

import (
	"fmt"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func init() {
	client.RegisterDraw("MonsterDraw", legacy.Get_nox_thing_monster_draw(), 7, parseMonsterDraw)
}

func parseMonsterDraw(obj *client.ObjectType, f *binfile.MemFile, _ string, _ []byte) error {
	dd, _ := alloc.New(client.MonsterDrawData{})
	dd.Size = uint32(unsafe.Sizeof(client.MonsterDrawData{}))
	for {
		tok := f.ReadU32()
		if tok == 0x454E4420 { // "END "
			break
		}
		ind := f.ReadU8()
		if int(ind) >= len(dd.Anim) {
			return fmt.Errorf("invalid animation index: %d", int(ind))
		}
		f.SkipString8()
		f.SkipString8()
		ani := &dd.Anim[ind]
		if err := nox_xxx_loadVectorAnimated_44B8B0(ani, f); err != nil {
			return err
		}
		if err := nox_xxx_loadVectorAnimated_44BC50(ani, f); err != nil {
			return err
		}
	}
	obj.DrawFunc = legacy.Get_nox_thing_monster_draw()
	obj.DrawData = unsafe.Pointer(dd)
	return nil
}
