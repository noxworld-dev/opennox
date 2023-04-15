package opennox

import (
	"errors"
	"fmt"
	"image"
	"math"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	nox_wall_def_cnt  int
	nox_wall_defs_arr *[80]server.WallDef
)

func nox_thing_read_WALL_410900(f *binfile.MemFile) error {
	if nox_wall_defs_arr == nil {
		nox_wall_defs_arr, _ = alloc.New([80]server.WallDef{})
	}
	if nox_wall_def_cnt >= cap(nox_wall_defs_arr) {
		return errors.New("too many wall definitions")
	}
	p := &nox_wall_defs_arr[nox_wall_def_cnt]
	f.Skip(4)
	name, _ := f.ReadString8()
	alloc.StrCopyZero(p.Field0[:], name)
	p.Field32 = f.ReadU32()
	p.Field36 = uint16(int16(f.ReadI32()))
	p.Field38 = uint16(int16(f.ReadI32()))
	p.Field40 = f.ReadU8()
	p.Field41 = f.ReadU8()
	v39 := f.ReadU64Align()
	p.Field42 = uint8(int8(v39))
	p.Brick43 = [8][64]byte{}
	for i := 0; i < int(p.Field42); i++ {
		if i >= len(p.Brick43) {
			return errors.New("too many wall sub defs")
		}
		v4, _ := f.ReadString8()
		alloc.StrCopyZero(p.Brick43[i][:], v4)
	}
	v45, _ := f.ReadString8()
	alloc.StrCopyZero(p.SoundOpen555[:], v45)
	v46, _ := f.ReadString8()
	alloc.StrCopyZero(p.SoundClose619[:], v46)
	v47, _ := f.ReadString8()
	alloc.StrCopyZero(p.Sound683[:], v47)
	p.Field749 = f.ReadU8()
	p.Sprite8432 = [4][15][16]unsafe.Pointer{}

	for dir := server.WallDirUp; dir <= server.WallDirLeftHalfArrowUp; dir++ {
		sz := f.ReadU64Align()
		for jj := 0; jj < int(sz); jj++ {
			for kk := 0; kk < 4; kk++ {
				p.Field12272[kk][dir] = uint8(int8(sz))
				v1 := f.ReadU32()
				v2 := f.ReadU32()
				p.Field752[kk][dir][jj] = [2]uint32{v1, v2}
				if f.ReadI32() == -1 {
					f.Skip(1)
					f.SkipString8()
				}
			}
		}
	}
	if f.ReadU32() != 0x454E4420 { // "END "
		return errors.New("expected section end")
	}
	nox_wall_def_cnt++
	return nil
}

func nox_thing_read_wall_46A010(f *binfile.MemFile, _ []byte) error {
	if nox_wall_def_cnt <= 0 {
		return errors.New("no server wall definitions")
	}
	f.Skip(4)
	name, _ := f.ReadString8()
	ind := -1
	for i := 0; i < nox_wall_def_cnt; i++ {
		p := &nox_wall_defs_arr[i]
		if p.Name() == name {
			ind = i
			break
		}
	}
	if ind == -1 {
		return fmt.Errorf("wall definition not found: %q", name)
	}
	p := &nox_wall_defs_arr[ind]
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
				v1 := f.ReadU32()
				v2 := f.ReadU32()
				p.Field752[kk][dir][jj] = [2]uint32{v1, v2}
				v21 := int(f.ReadI32())
				var (
					v41   byte
					bname string
				)
				if v21 == -1 {
					v41 = f.ReadU8()
					bname, _ = f.ReadString8()
				}
				img := noxClient.r.Bag.ImageRef(v21, v41, bname)
				p.Sprite8432[kk][dir][jj] = unsafe.Pointer(img.C())
			}
		}
	}
	if f.ReadU32() != 0x454E4420 { // "END "
		return errors.New("expected section end")
	}
	return nil
}

func sub_526CA0(a1 string) int {
	a1 = strings.ToUpper(a1)
	v1 := false
	for i := 0; i < nox_wall_def_cnt; i++ {
		v3 := strings.ToUpper(sub_410D40(i))
		if v3 == a1 {
			*memmap.PtrUint32(0x973F18, 35948) = uint32(i)
			v1 = true
		}
	}
	if a1 == "NONE" {
		*memmap.PtrUint32(0x973F18, 35948) = math.MaxUint8
		return 1
	}
	if v1 {
		return 1
	}
	*memmap.PtrUint32(0x973F18, 35948) = 0
	return 0
}

func nox_xxx_getWallSprite_46A3B0(ind int, a2 int, a3 int, a4 int) noxrender.ImageHandle {
	p := &nox_wall_defs_arr[ind]
	return noxrender.ImageHandle(p.Sprite8432[a4][a2][a3])
}
func nox_xxx_getWallDrawOffset_46A3F0(ind int, a2 int, a3 int, a4 int) *[2]uint32 {
	p := &nox_wall_defs_arr[ind]
	return &p.Field752[a4][a2][a3]
}

func sub_410D40(ind int) string {
	return nox_wall_defs_arr[ind].Name()
}

func nox_xxx_wallTileByName_410D60(name string) int {
	if nox_wall_def_cnt <= 0 {
		return -1
	}
	for i := 0; i < nox_wall_def_cnt; i++ {
		p := &nox_wall_defs_arr[i]
		if p.Name() == name {
			return i
		}
	}
	return -1
}
func nox_xxx_mapWallMaxVariation_410DD0(ind int, a2 int, a3 int) byte {
	p := &nox_wall_defs_arr[ind]
	return p.Field12272[a3][a2]
}
func nox_xxx_map_410E00(ind int) byte {
	return nox_wall_defs_arr[ind].Field749
}
func nox_xxx_mapWallGetHpByTile_410E20(ind int) byte {
	return nox_wall_defs_arr[ind].Field41
}
func nox_xxx_wallGetBrickTypeMB_410E40(ind int) byte {
	return nox_wall_defs_arr[ind].Field42
}
func nox_xxx_wallFlags(ind int) uint32 {
	return nox_wall_defs_arr[ind].Field32
}
func nox_xxx_wallField36(ind int) uint16 {
	return nox_wall_defs_arr[ind].Field36
}
func nox_xxx_wallGetBrickObj_410E60(ind int, ind2 int) string {
	name := "Brick0"
	p := &nox_wall_defs_arr[ind]
	if s := alloc.GoStringS(p.Brick43[ind2][:]); s != "" {
		name = s
	}
	return name
}
func nox_xxx_wallSoundByTile_410EA0(ind int) string {
	name := "WallDestroyed"
	p := &nox_wall_defs_arr[ind]
	if s := alloc.GoStringS(p.Sound683[:]); s != "" {
		name = s
	}
	return name
}
func nox_xxx_wallFindOpenSound_410EE0(ind int) string {
	name := "SecretWallOpen"
	p := &nox_wall_defs_arr[ind]
	if s := alloc.GoStringS(p.SoundOpen555[:]); s != "" {
		name = s
	}
	return name
}
func nox_xxx_wallFindCloseSound_410F20(ind int) string {
	name := "SecretWallClose"
	p := &nox_wall_defs_arr[ind]
	if s := alloc.GoStringS(p.SoundClose619[:]); s != "" {
		name = s
	}
	return name
}
func sub_46A360() {
	for i := range nox_wall_defs_arr {
		p := &nox_wall_defs_arr[i]
		p.Sprite8432 = [4][15][16]unsafe.Pointer{}
	}
}

func asWallS(p *server.Wall) *Wall {
	return (*Wall)(unsafe.Pointer(p))
}

func (s *Server) nox_xxx_wallTileByName_410D60(name string) byte {
	return byte(nox_xxx_wallTileByName_410D60(name))
}

func (s *Server) getWallGroupByID(id string) *script.WallGroup {
	g := s.GroupByID(id, server.MapGroupWalls)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Wall
	for it := g.First(); it != nil; it = it.Next() {
		if wl := s.Walls.GetWallAtGrid(image.Point{
			X: it.Data1(),
			Y: it.Data2(),
		}); wl != nil {
			list = append(list, asWallS(wl))
		}
	}
	return script.NewWallGroup(id, list...)
}

func nox_xxx_wallSecretGetFirstWall_410780() unsafe.Pointer {
	return legacy.Get_dword_5d4594_251560()
}

func nox_xxx_wallSecretNext_410790(p unsafe.Pointer) unsafe.Pointer {
	if p == nil {
		return nil
	}
	return *(*unsafe.Pointer)(p)
}

var _ = [1]struct{}{}[36-unsafe.Sizeof(Wall{})]

type Wall server.Wall

func (w *Wall) C() unsafe.Pointer {
	return unsafe.Pointer(w)
}

func (w *Wall) S() *server.Wall {
	if w == nil {
		return nil
	}
	return (*server.Wall)(unsafe.Pointer(w))
}

func (w *Wall) String() string {
	return w.S().String()
}

func (w *Wall) WallScriptID() int {
	return w.S().WallScriptID()
}

func (w *Wall) ScriptID() int {
	return w.S().ScriptID()
}

func (w *Wall) GridPos() image.Point {
	return w.S().GridPos()
}

func (w *Wall) Pos() types.Pointf {
	return w.S().Pos()
}

// IsEnabled checks if the wall is closed.
func (w *Wall) IsEnabled() bool {
	return w.S().IsEnabled()
}

// Enable or disable (close or open) the wall.
func (w *Wall) Enable(close bool) {
	if close {
		legacy.Nox_xxx_wallClose_512070(w.C())
	} else {
		legacy.Nox_xxx_wallOpen_511F80(w.C())
	}
}

func (w *Wall) Toggle() bool {
	legacy.Nox_xxx_wallToggle_512160(w.C())
	return w.IsEnabled()
}

// Destroy (break) the wall.
func (w *Wall) Destroy() {
	legacy.Nox_xxx_wallPreDestroyByPtr_5122C0(w.C())
}
