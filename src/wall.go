package opennox

import (
	"errors"
	"fmt"
	"image"
	"math"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
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
	g := s.MapGroups.GroupByID(id, server.MapGroupWalls)
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
	w.Server().nox_xxx_wallPreDestroy_534DA0(w.GridPos())
}

func (s *Server) Nox_xxx_mapDamageToWalls_534FC0(rect image.Rectangle, pos types.Pointf, rad float32, dmg int, dtyp object.DamageType, who *server.Object) bool {
	var (
		cos, sin float32
		pts      [32]image.Point
	)
	dir := 0
	dirSet := false
	if who != nil {
		if who.Class().HasAny(object.MaskUnits) {
			dir = int(who.Direction1)
			dirSet = true
		} else {
			if !who.Class().HasAny(0x1001000) {
				goto LABEL_10
			}
			v11 := who.InvHolder
			if v11 == nil {
				goto LABEL_10
			}
			dir = int(v11.Direction1)
			dirSet = true
		}
		cos, sin = server.SinCosDir(byte(dir))
	}
LABEL_10:
	yi := rect.Min.Y
	v33 := int32(yi)
	v37 := rad * rad
	v7 := 0
	v25 := 0
	for yi <= rect.Max.Y {
		xi := rect.Min.X
		v32 := int32(xi)
		if rect.Min.X <= rect.Max.X {
			v15p := pts[v7:]
			for xi <= rect.Max.X {
				if s.Walls.GetWallAtGrid(image.Pt(xi, yi)) != nil {
					v16 := func() types.Pointf {
						if dirSet {
							return who.PosVec
						}
						return pos
					}()
					v17 := float64(v32)
					v35 := float32(v17)
					v26 := float32(v17*23.0 + 11.5 - float64(v16.X))
					v18 := float64(v33)
					v31 := float32(v18)
					v19 := v18*23.0 + 11.5 - float64(v16.Y)
					v28 := float32(v19)
					v20 := v19*float64(v28) + float64(v26*v26)
					v30 := float32(v20)
					if v20 < float64(v37) {
						if !dirSet || float64(v30) <= 0.0 || (func() bool {
							v21 := math.Sqrt(float64(v30)) + 0.5
							v27 := float32(float64(v26) / v21)
							return float64(v28)/v21*float64(sin)+float64(v27*cos) > 0.5
						}()) {
							var v38b types.Pointf
							v38b.X = float32(float64(v35)*23.0 + 11.5)
							v38b.Y = float32(float64(v31)*23.0 + 11.5)
							var v36 image.Point
							if (s.MapTraceRayAt(pos, v38b, nil, &v36, 1) || v36.X == int(xi) && v36.Y == int(yi)) && v25 < 32 {
								v15p[0].X = xi
								v15p[0].Y = yi
								v25++
								v15p = v15p[1:]
							}
						}
					}
				}
				xi++
				v32 = int32(xi)
			}
			v7 = v25
			who = who
			rect = rect
		}
		yi++
		v33 = int32(yi)
	}
	if v7 <= 0 {
		return v7 > 0
	}
	it := pts[:]
	for {
		s.Nox_xxx_damageToMap_534BC0(it[0].X, it[0].Y, dmg, dtyp, who)
		it = it[1:]
		v7--
		if v7 == 0 {
			break
		}
		who = who
	}
	v7 = v25
	return v7 > 0
}
func (s *Server) Nox_xxx_damageToMap_534BC0(gx, gy int, dmg int, dtyp object.DamageType, who *server.Object) int {
	wl := s.Walls.GetWallAtGrid(image.Pt(gx, gy))
	if *memmap.PtrUint32(0x5D4594, 2488556) == 0 {
		*memmap.PtrUint32(0x5D4594, 2488556) = uint32(s.Walls.DefIndByName("MagicWallSystemUseOnly"))
	}
	if wl == nil {
		return 0
	}
	if wl.Flags4&0x20 != 0 {
		return 0
	}
	if wl.Flags4&8 == 0 {
		s.Sub_532FE0(s.Walls.DefByInd(int(wl.Tile1)).Field36, who)
		return 0
	}
	var (
		v7 *server.Object
		v8 int
	)
	if !noxflags.HasGame(4096) || who == nil || uint32(wl.Tile1) != *memmap.PtrUint32(0x5D4594, 2488556) || (func() *server.Object {
		v7 = who.FindOwnerChainPlayer()
		return v7
	}()) == nil || (func() bool {
		v8 = 99999999
		return (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 8))) & 4) == 0
	}()) {
		v8 = dmg
	}
	if int(wl.Health7)-v8 <= 0 {
		return s.nox_xxx_wallPreDestroy_534DA0(image.Pt(gx, gy))
	}
	v10 := uint8(int8(int(wl.Health7) - v8))
	v11 := int(wl.Tile1)
	wl.Health7 = v10
	var v17 types.Pointf
	v17.X = float32(float64(gx)*23.0 + 11.5)
	v17.Y = float32(float64(gy)*23.0 + 11.5)
	if btyp := int(s.Walls.DefByInd(v11).BrickType42); btyp != 0 {
		bi := s.Rand.Logic.IntClamp(0, btyp-1)
		bo := s.Walls.DefByInd(int(wl.Tile1)).BrickObject(bi)
		brick := s.NewObjectByTypeID(bo)
		if brick != nil {
			s.CreateObjectAt(brick, nil, v17)
			v16 := float64(s.Rand.Logic.FloatClamp(10.0, 20.0))
			asObjectS(brick).applyForce(v17, v16)
		}
	}
	s.Sub_533010(s.Walls.DefByInd(int(wl.Tile1)).Field36, who)
	return 0
}
func (s *Server) Nox_xxx_wall_4DF1E0(a1 int) {
	for it := s.Walls.FirstBreakable(); it != nil; it = it.Next() {
		wl := it.Wall
		if wl.Flags4&0x20 != 0 {
			s.Nox_xxx_wallSendDestroyed_4DF0A0(wl, a1)
		}
	}
	sub_4DF2A0(int8(a1))
	if legacy.Sub_5071C0() {
		s.Sub_507190(a1, 1)
	}
	if !noxflags.HasGame(noxflags.GameModeQuest) {
		return
	}
	for it := s.Objs.First(); it != nil; it = it.Next() {
		if it.Class().Has(object.ClassDoor) && *(*byte)(unsafe.Add(it.UpdateData, 48)) != 0 {
			s.Sub_4D6A20(a1, it)
		}
	}
	if s.Doors.Sub_4D72C0() {
		v5 := s.Doors.Sub_4D72C0()
		s.Sub_4D7280(a1, v5)
	}
}
func sub_4DF2A0(a1 int8) {
	v1 := int32(1) << a1
	for it := nox_xxx_wallSecretGetFirstWall_410780(); it != nil; it = nox_xxx_wallSecretNext_410790(it) {
		if *(*int32)(unsafe.Add(it, 4*5))&8 != 0 {
			*(*int32)(unsafe.Add(it, 4*7)) |= v1
		} else {
			*(*int32)(unsafe.Add(it, 4*7)) &^= v1
		}
	}
}
func (s *Server) nox_xxx_wallPreDestroy_534DA0(pt image.Point) int {
	wl := s.Walls.GetWallAtGrid(pt)
	if *memmap.PtrUint32(0x5D4594, 2488560) == 0 {
		*memmap.PtrUint32(0x5D4594, 2488560) = uint32(s.Walls.DefIndByName("MagicWallSystemUseOnly"))
	}
	if wl == nil {
		return 0
	}
	if (wl.Flags4&0x8) == 0 || (wl.Flags4&0x20) != 0 {
		return 0
	}
	wl.Health7 = 0
	var pos types.Pointf
	pos.X = float32(float64(pt.X)*23.0 + 11.5)
	pos.Y = float32(float64(pt.Y)*23.0 + 11.5)
	v4 := s.Walls.DefByInd(int(wl.Tile1)).BreakSound()
	v5 := sound.ByName(v4)
	s.Audio.EventPos(v5, pos, 0, 0)
	nox_xxx_netSendPointFx_522FF0(noxnet.MSG_FX_SMOKE_BLAST, pos)
	if !noxflags.HasGame(noxflags.GameModeQuest) {
		if bricks := s.Walls.DefByInd(int(wl.Tile1)).BrickType42; bricks != 0 {
			brick := byte(s.Rand.Logic.IntClamp(0, int(bricks)-1))
			cnt := s.Rand.Logic.IntClamp(3, 6)
			for i := 0; i < cnt; i++ {
				typID := s.Walls.DefByInd(int(wl.Tile1)).BrickObject(int(brick))
				if b := s.NewObjectByTypeID(typID); b != nil {
					y := float32(s.Rand.Logic.FloatClamp(-2.0, 2.0) + float64(pos.Y))
					x := float32(s.Rand.Logic.FloatClamp(-2.0, 2.0) + float64(pos.X))
					s.CreateObjectAt(b, nil, types.Pointf{X: x, Y: y})
					force := float64(s.Rand.Logic.FloatClamp(4.0, 10.0))
					asObjectS(b).applyForce(pos, force)
				}
				brick++
				if brick >= bricks {
					brick = 0
				}
			}
		}
	}
	if uint32(wl.Tile1) == *memmap.PtrUint32(0x5D4594, 2488560) {
		s.spells.walls.destroySysuse(wl)
	} else {
		s.Walls.BreakByID(wl.Field10)
		s.Nox_xxx_wallSendDestroyed_4DF0A0(wl, 32)
	}
	return 1
}
