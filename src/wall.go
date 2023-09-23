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

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_thing_read_wall_46A010(f *binfile.MemFile, _ []byte) error {
	wdefs := noxServer.Walls.Defs()
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
	s := noxServer
	a1 = strings.ToUpper(a1)
	v1 := false
	wdefs := s.Walls.Defs()
	for i := range wdefs {
		v3 := strings.ToUpper(wdefs[i].Name())
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

func nox_xxx_wall_42A6C0(a1 uint8, a2 uint8) uint8 {
	return memmap.Uint8(0x587000, uintptr(a1)*13+71276+uintptr(a2))
}

func asWallS(p *server.Wall) *Wall {
	return (*Wall)(unsafe.Pointer(p))
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

func (w *Wall) Server() *Server {
	return noxServer // TODO
}

func (w *Wall) Def() *server.WallDef {
	if w == nil {
		return nil
	}
	return w.Server().Walls.DefByInd(int(w.Tile1))
}

// Enable or disable (close or open) the wall.
func (w *Wall) Enable(close bool) {
	if close {
		w.close()
	} else {
		w.open()
	}
}

func (w *Wall) Toggle() bool {
	w.toggle()
	return w.IsEnabled()
}

func (w *Wall) open() {
	if w.Flags4&4 == 0 {
		return
	}
	p := w.Data28
	st := *(*uint8)(unsafe.Add(p, 21))
	if st != 3 && st != 4 {
		*(*uint8)(unsafe.Add(p, 21)) = 4
		s := w.Server()
		if s.Walls.NoWallSounds {
			return
		}
		pos := types.Pointf{
			X: float32(int32(*(*uint32)(unsafe.Add(p, 4)))*23) + 11.5,
			Y: float32(int32(*(*uint32)(unsafe.Add(p, 8)))*23) + 11.5,
		}
		sndName := w.Def().OpenSound()
		s.Audio.EventPos(sound.ByName(sndName), pos, 0, 0)
	}
}

func (w *Wall) close() {
	if w.Flags4&4 == 0 {
		return
	}
	p := w.Data28
	st := *(*uint8)(unsafe.Add(p, 21))
	if st != 1 && st != 2 {
		*(*uint8)(unsafe.Add(p, 21)) = 2
		s := w.Server()
		if s.Walls.NoWallSounds {
			return
		}
		pos := types.Pointf{
			X: float32(int32(*(*uint32)(unsafe.Add(p, 4)))*23) + 11.5,
			Y: float32(int32(*(*uint32)(unsafe.Add(p, 8)))*23) + 11.5,
		}
		sndName := w.Def().CloseSound()
		s.Audio.EventPos(sound.ByName(sndName), pos, 0, 0)
	}
}

func (w *Wall) toggle() {
	if w.Flags4&4 == 0 {
		return
	}
	if w.IsEnabled() {
		w.open()
	} else {
		w.close()
	}
}

// Destroy (break) the wall.
func (w *Wall) Destroy() {
	legacy.Nox_xxx_wallPreDestroyByPtr_5122C0(w.C())
}
