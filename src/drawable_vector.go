package opennox

import (
	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_xxx_spriteLoadVectoAnimatedImpl_44BFA0(ani *client.AnimationVector, f *binfile.MemFile) error {
	if err := nox_xxx_loadVectorAnimated_44B8B0(ani, f); err != nil {
		return err
	}
	return nox_xxx_loadVectorAnimated_44BC50(ani, f)
}

func nox_xxx_loadVectorAnimated_44B8B0(ani *client.AnimationVector, f *binfile.MemFile) error {
	ani.Cnt40 = uint16(f.ReadU8())
	ani.Val42 = uint16(f.ReadU8())
	kind, _ := f.ReadString8()
	ani.Kind = client.ParseAnimKind(kind)
	return nil
}

func nox_xxx_loadVectorAnimated_44BC50(ani *client.AnimationVector, f *binfile.MemFile) error {
	for i := 0; i < 8; i++ {
		k := i
		if i >= 4 {
			k = i + 1
		}
		arr, _ := alloc.Make([]noxrender.ImageHandle{}, int(ani.Cnt40))
		ani.Frames[k] = &arr[0]
		for j := 0; j < int(ani.Cnt40); j++ {
			id := f.ReadI32()
			var (
				typ   byte
				name2 string
			)
			if id == -1 {
				typ = f.ReadU8()
				name2, _ = f.ReadString8()
			}
			arr[j] = noxClient.r.Bag.ImageRef(int(id), typ, name2).C()
		}
	}
	return nil
}
