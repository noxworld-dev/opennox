package client

import (
	"errors"
	"fmt"
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (c *Client) ReadWalls(f *binfile.MemFile) error {
	wdefs := c.Server.Walls.Defs()
	if len(wdefs) == 0 {
		return errors.New("no server wall definitions")
	}
	f.Skip(4)
	name, _ := f.ReadString8()
	ind := -1
	for i := range wdefs {
		p := &wdefs[i]
		if p.Name() == name {
			ind = i
			break
		}
	}
	if ind == -1 {
		return fmt.Errorf("wall definition not found: %q", name)
	}
	p := &wdefs[ind]
	p.Sprite8432 = [4][15][16]unsafe.Pointer{}
	f.Skip(14)
	v31 := f.ReadU64Align()
	for i := 0; i < int(v31); i++ {
		if i >= len(p.Brick43) {
			return errors.New("too many wall sub defs")
		}
		f.SkipString8()
	}
	f.SkipString8()
	f.SkipString8()
	f.SkipString8()
	f.Skip(1)

	for dir := server.WallDirUp; dir <= server.WallDirLeftHalfArrowUp; dir++ {
		v35 := f.ReadU64Align()
		if v35 >= 16 {
			return errors.New("too many wall sprite defs")
		}
		for jj := 0; jj < int(v35); jj++ {
			for kk := 0; kk < 4; kk++ {
				v1 := int(f.ReadI32())
				v2 := int(f.ReadI32())
				p.DrawOffs752[kk][dir][jj] = image.Pt(v1, v2)
				v21 := int(f.ReadI32())
				var (
					v41   byte
					bname string
				)
				if v21 == -1 {
					v41 = f.ReadU8()
					bname, _ = f.ReadString8()
				}
				img := c.Render().Bag.ImageRef(v21, v41, bname)
				p.Sprite8432[kk][dir][jj] = unsafe.Pointer(img.C())
			}
		}
	}
	if f.ReadU32() != 0x454E4420 { // "END "
		return errors.New("expected section end")
	}
	return nil
}
