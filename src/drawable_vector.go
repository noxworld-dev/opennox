package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func init() {
	client.RegisterDraw("VectorAnimateDraw", legacy.Get_nox_thing_vector_animate_draw(), 5, parseAnimVectorDraw)
	client.RegisterDraw("ReleasedSoulDraw", legacy.Get_nox_thing_released_soul_draw(), 5, parseAnimVectorDraw)
}

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

func parseAnimVectorDraw(obj *client.ObjectType, f *binfile.MemFile, _ string, _ []byte) error {
	dd, _ := alloc.New(client.AnimationVector{})
	dd.Size = uint32(unsafe.Sizeof(client.AnimationVector{}))
	if err := nox_xxx_spriteLoadVectoAnimatedImpl_44BFA0(dd, f); err != nil {
		return err
	}
	obj.DrawFunc = legacy.Get_nox_thing_vector_animate_draw()
	obj.DrawData = unsafe.Pointer(dd)
	return nil
}

func (c *Client) DrawAnimVector(vp *noxrender.Viewport, dr *client.Drawable) int {
	return c.drawAnimVector(vp, dr, (*client.AnimationVector)(dr.DrawData))
}

func (c *Client) drawAnimVector(vp *noxrender.Viewport, dr *client.Drawable, ani *client.AnimationVector) int {
	fi := c.getAnimFrameInd(dr, ani)
	if fi < 0 {
		return 0
	}
	frames := ani.FramesSlice(int(dr.AnimDir))
	legacy.Nox_xxx_drawObject_4C4770_draw(vp, dr, frames[fi])
	return 1
}

func (c *Client) DrawAnimState(vp *noxrender.Viewport, dr *client.Drawable) int {
	flags := dr.Flags70()
	dd := dr.DrawData // TODO: reconstruct type
	var ind int32
	if flags&2 != 0 {
		dr.AnimStart = c.Server.Frame()
		ind = 0
	} else if flags&4 != 0 {
		ind = 1
	} else {
		ind = int32((flags&0xff)>>2) & 2
	}
	ani := (*client.AnimationVector)(unsafe.Add(dd, 4+48*ind))
	if ani.Kind == client.AnimLoop {
		dr.AnimStart = c.Server.Frame()
	}
	if ani.Cnt40 == 0 {
		return 1
	}
	return c.drawAnimVector(vp, dr, ani)
}

func (c *Client) getAnimFrameInd(dr *client.Drawable, ani *client.AnimationVector) int {
	switch ani.Kind {
	case client.AnimOneShot:
		ind := int((c.Server.Frame() - dr.AnimStart) / (uint32(ani.Val42) + 1))
		if ind >= int(ani.Cnt40) {
			ind = int(ani.Cnt40) - 1
		}
		return ind
	case client.AnimOneShotRemove:
		ind := int((c.Server.Frame() - dr.AnimStart) / (uint32(ani.Val42) + 1))
		if ind >= int(ani.Cnt40) {
			c.Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
			return -1
		}
		return ind
	case client.AnimLoop:
		ind := int((c.Server.Frame() + dr.NetCode32) / (uint32(ani.Val42) + 1))
		if ind >= int(ani.Cnt40) {
			ind %= int(ani.Cnt40)
		}
		return ind
	case client.AnimRandom:
		return c.Server.Rand.Other.Int(0, int(ani.Cnt40)-1)
	case client.AnimSlave:
		return int(dr.AnimFrameSlave)
	default:
		return 0
	}
}
