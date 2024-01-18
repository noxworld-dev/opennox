package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func sub_4BC5D0(dr *client.Drawable, ani *client.AnimationVector) int32 {
	switch ani.Kind {
	case client.AnimOneShot:
		ind := int32((gameFrame() - dr.AnimStart) / uint32(int32(ani.Val42)+1))
		if ind >= int32(ani.Cnt40) {
			ind = int32(ani.Cnt40) - 1
		}
		return ind
	case client.AnimOneShotRemove:
		ind := int32((gameFrame() - dr.AnimStart) / uint32(int32(ani.Val42)+1))
		if ind >= int32(ani.Cnt40) {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
			return -1
		}
		return ind
	case client.AnimLoop:
		ind := int32((gameFrame() + dr.NetCode32) / uint32(int32(ani.Val42)+1))
		if ind >= int32(ani.Cnt40) {
			ind %= int32(ani.Cnt40)
		}
		return ind
	case client.AnimRandom:
		return nox_common_randomIntMinMax_415FF0(0, int32(ani.Cnt40)-1, internCStr("C:\\NoxPost\\src\\Client\\Draw\\vectdraw.c"), 19)
	case client.AnimSlave:
		return int32(dr.AnimFrameSlave)
	default:
		return 0
	}
}
func nox_thing_vector_animate_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return sub_4BC6B0(vp, dr, (*client.AnimationVector)(dr.DrawData))
}
func nox_things_vector_animate_draw_parse(obj *client.ObjectType, f *binfile.MemFile, attr_value *byte) bool {
	dd, _ := alloc.New(client.AnimationVector{})
	dd.Size = uint32(unsafe.Sizeof(client.AnimationVector{}))
	if !nox_xxx_spriteLoadVectoAnimatedImpl_44BFA0(dd, f) {
		return false
	}
	obj.DrawFunc.Set(nox_thing_vector_animate_draw)
	obj.DrawData = unsafe.Pointer(dd)
	return true
}
