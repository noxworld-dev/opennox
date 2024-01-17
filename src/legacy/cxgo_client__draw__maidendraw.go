package legacy

import (
	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
)

func nox_thing_maiden_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	if !noxflags.HasGame(0x200000) {
		npc := nox_npc_by_id(int32(dr.Field_32))
		if npc == nil {
			return 1
		}
		for i := 0; i < 6; i++ {
			nox_draw_setMaterial_4341D0(int32(i+1), int32(npc.color8[i]))
		}
		return nox_thing_monster_draw(vp, dr)
	}
	for it := nox_server_getFirstObject_4DA790(); it != nil; it = nox_server_getNextObject_4DA7A0(it) {
		if dr.Field_32 == it.Extent {
			ud := it.UpdateDataMonster()
			for i := 0; i < 6; i++ {
				cl := ud.Color[i]
				nox_draw_setMaterial_4340A0(int32(i+1), int32(cl.R), int32(cl.G), int32(cl.B))
			}
			break
		}
	}
	return nox_thing_monster_draw(vp, dr)
}
func nox_things_maiden_draw_parse(obj *client.ObjectType, f *binfile.MemFile, attr_value *byte) bool {
	res := nox_things_monster_draw_parse(obj, f, attr_value)
	obj.DrawFunc.Set(nox_thing_maiden_draw)
	return res
}
