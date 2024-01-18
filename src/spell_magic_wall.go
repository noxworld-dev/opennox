package opennox

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/wall"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

type spellWall struct {
	s         *Server
	alloc     alloc.ClassT[server.MagicWall]
	list      *server.MagicWall
	lvlLength []int
	saved     []server.MagicWallSave
}

func (sp *spellWall) newDurSpellForSave(u *server.Object) {
	pl := u.ControllingPlayer()
	sa := server.SpellAcceptArg{
		Obj: u,
		Pos: pl.CursorPos(),
	}
	sp.s.spells.duration.New(spell.SPELL_WALL, u, u, u, &sa, 3, nil, nil, nil, 0)
}

func (sp *spellWall) Init(srv *Server) {
	sp.s = srv
	sp.saved = nil
	sp.lvlLength = []int{
		7, // def?
		3, // lvl 1
		4, // lvl 2
		5, // lvl 3
		6, // lvl 4
		7, // lvl 5
	}
	sp.alloc = alloc.NewClassT("MagicWall", server.MagicWall{}, (sp.lvlLength[0]*2+1)*common.MaxPlayers)
}

func (sp *spellWall) Free() {
	sp.alloc.Free()
	sp.list = nil
	sp.saved = nil
}

func (sp *spellWall) Reset() {
	sp.alloc.FreeAllObjects()
	sp.list = nil
}

func (sp *spellWall) newWall(spl *server.DurSpell, wl *server.Wall, a3 uint32, prevTile byte, prevDir byte, prevFld byte) *server.MagicWall {
	p := sp.alloc.NewObject()
	if p == nil {
		return nil
	}
	p.Wall8 = wl
	p.Field0 = a3
	p.Dir4 = wl.Dir0
	p.PrevTile12 = prevTile
	p.PrevDir13 = prevDir
	p.PrevField14 = prevFld
	p.Spell20 = spl
	p.PlayerBits16 = 0
	p.Next24 = sp.list
	p.Prev28 = nil
	if sp.list != nil {
		sp.list.Prev28 = p
	}
	sp.list = p
	return p
}

func (sp *spellWall) destroyWall(mw *server.MagicWall) {
	sp.netChangeOrRemoveWall(mw)
	if noxflags.HasGame(noxflags.GameHost) {
		if wl := mw.Wall8; mw.Field0 != 0 {
			wl.Tile1 = mw.PrevTile12
			mw.Wall8.Dir0 = mw.PrevDir13
			mw.Wall8.Field2 = mw.PrevField14
		} else {
			sp.s.Walls.DeleteAtGrid(image.Pt(int(wl.X5), int(wl.Y6)))
		}
	}
	if prev := mw.Prev28; prev != nil {
		prev.Next24 = mw.Next24
	} else {
		sp.list = mw.Next24
	}
	if next := mw.Next24; next != nil {
		next.Prev28 = mw.Prev28
	}
	sp.alloc.FreeObjectFirst(mw)
}

func (sp *spellWall) netChangeOrRemoveWall(mw *server.MagicWall) {
	for i := 0; i < common.MaxPlayers; i++ {
		if mw.PlayerBits16&(1<<i) != 0 {
			if mw.Field0 != 0 {
				wl := mw.Wall8
				var buf [6]byte
				buf[0] = byte(noxnet.MSG_CHANGE_OR_ADD_WALL_MAGIC)
				buf[1] = mw.PrevTile12
				buf[2] = mw.PrevDir13
				buf[3] = mw.PrevField14
				buf[4] = wl.X5
				buf[5] = wl.Y6
				sp.s.NetSendPacketXxx0(i, buf[:6], 0, 1)
			} else {
				wl := mw.Wall8
				var buf [3]byte
				buf[0] = byte(noxnet.MSG_REMOVE_WALL_MAGIC)
				buf[1] = wl.X5
				buf[2] = wl.Y6
				sp.s.NetSendPacketXxx0(i, buf[:3], 0, 1)
			}
		}
	}
}

func (sp *spellWall) switchToPrevDir() {
	for it := sp.list; it != nil; it = it.Next24 {
		if it.Field0 == 1 {
			it.Wall8.Dir0 = it.PrevDir13
		}
	}
}

func (sp *spellWall) switchToNewDir() {
	for it := sp.list; it != nil; it = it.Next24 {
		if it.Field0 == 1 {
			it.Wall8.Dir0 = it.Dir4
		}
	}
}

func (sp *spellWall) disablePlayerBits(bits uint32) {
	for it := sp.list; it != nil; it = it.Next24 {
		it.PlayerBits16 &^= bits
	}
}

func (sp *spellWall) destroySysuse(a1 *server.Wall) {
	it := sp.list
	if it == nil {
		return
	}
	for {
		next := it.Next24
		if it.Wall8 == a1 {
			sp.destroyWall(it)
		}
		it = next
		if next == nil {
			break
		}
	}
}

func (sp *spellWall) changeOrAddRemoteWalls(pl *server.Player) {
	if pl.PlayerInd == common.MaxPlayers-1 {
		return
	}
	bit := uint32(1) << pl.PlayerInd
	for mw := sp.list; mw != nil; mw = mw.Next24 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(pl), 3680)))&0x10 != 0 {
			if mw.PlayerBits16&bit == 0 {
				wl := mw.Wall8
				var buf [6]byte
				buf[0] = byte(noxnet.MSG_CHANGE_OR_ADD_WALL_MAGIC)
				buf[1] = wl.Tile1
				buf[2] = wl.Dir0
				buf[3] = wl.Field2
				buf[4] = wl.X5
				buf[5] = wl.Y6
				sp.s.NetSendPacketXxx0(pl.Index(), buf[:6], 0, 1)
				mw.PlayerBits16 |= bit
			}
		}
	}
}

func (sp *spellWall) LoadOrSave(cf *cryptfile.CryptFile, u *server.Object) int {
	if cf.ReadOnly() {
		vers, _ := cf.ReadU16()
		if vers > 1 || int16(vers) <= 0 {
			return 0
		}
		cnt, _ := cf.ReadU8()
		if cnt == 0 {
			return 1
		}
		sp.newDurSpellForSave(u)
		sp.saved = nil
		for i := 0; i < int(cnt); i++ {
			fld0, _ := cf.ReadU32()
			x, _ := cf.ReadU8()
			y, _ := cf.ReadU8()
			fld12, _ := cf.ReadU8()
			fld13, _ := cf.ReadU8()
			fld14, _ := cf.ReadU8()
			tile, _ := cf.ReadU8()
			fld2, _ := cf.ReadU8()
			dir, _ := cf.ReadU8()
			hp, _ := cf.ReadU8()
			sp.saved = append(sp.saved, server.MagicWallSave{
				X: x, Y: y,
				Field0:  fld0,
				Field12: fld12,
				Field13: fld13,
				Field14: fld14,
				Tile1:   tile,
				Field2:  fld2,
				Dir:     dir,
				Health:  hp,
			})
		}
		return 1
	} else {
		cf.WriteU16(1)
		cnt := 0
		for it := sp.list; it != nil; it = it.Next24 {
			cnt++
		}
		if cnt > 0xff {
			return 0
		}
		cf.WriteU8(byte(cnt))
		for it := sp.list; it != nil; it = it.Next24 {
			cf.WriteU32(it.Field0)
			cf.WriteU8(it.Wall8.X5)
			cf.WriteU8(it.Wall8.Y6)
			cf.WriteU8(it.PrevTile12)
			cf.WriteU8(it.PrevDir13)
			cf.WriteU8(it.PrevField14)
			cf.WriteU8(it.Wall8.Tile1)
			cf.WriteU8(it.Wall8.Field2)
			cf.WriteU8(it.Wall8.Dir0)
			cf.WriteU8(it.Wall8.Health7)
		}
		return 1
	}
}

var _ = [1]struct{}{}[16-unsafe.Sizeof(server.MagicWallSave{})]

func (sp *spellWall) associateSavedWalls(obj *server.Object) int32 {
	if len(sp.saved) == 0 {
		return 1
	}
	var spl *server.DurSpell
	for it := sp.s.Spells.Dur.List; it != nil; it = it.Next {
		if spell.ID(it.Spell) == spell.SPELL_WALL && it.Caster16 == obj && it.Flags88&0x1 == 0 {
			spl = it
			break
		}
	}
	if spl == nil {
		return 0
	}
	spl.Create = legacy.Get_nox_xxx_spellWallCreate_4FFA90()
	spl.Update = legacy.Get_nox_xxx_spellWallUpdate_500070()
	spl.Destroy = legacy.Get_nox_xxx_spellWallDestroy_500080()
	spl.Target48 = nil

	for _, p := range sp.saved {
		wl := sp.s.Walls.GetWallAtGrid(image.Pt(int(p.X), int(p.Y)))
		if wl != nil {
			wl.Dir0 = p.Dir
		} else {
			wl = sp.s.Walls.CreateAtGrid(image.Pt(int(p.X), int(p.Y)))
			if wl == nil {
				return 0
			}
			wl.Flags4 |= wall.FlagBreakable
			wl.Tile1 = p.Tile1
			wl.Field2 = p.Field2
			wl.Dir0 = p.Dir
			wl.Health7 = p.Health
		}
		sp.newWall(spl, wl, p.Field0, p.Field12, p.Field13, p.Field14)
	}
	sp.saved = nil
	return 1
}

func (sp *spellWall) Create(spl *server.DurSpell) int {
	dur := sp.s.SecToFrames(60 * int(spl.Level+5))
	caster := spl.Caster16
	if caster == nil || caster.ObjFlags&0x8020 != 0 {
		return 1
	}
	if !sp.s.MapTraceRay9(spl.Pos, spl.Pos2) {
		if !caster.Class().Has(object.ClassPlayer) {
			return 1
		}
		ud := caster.UpdateDataPlayer()
		sp.s.NetInformTextMsg(ud.Player.PlayerIndex(), 0, 2)
		return 1
	}
	dpos := spl.Pos2.Sub(spl.Pos)
	v9 := legacy.Nox_xxx_math_509ED0(dpos)
	dir := legacy.Nox_xxx_math_509EA0(v9)
	x1 := int(spl.Pos2.X) / common.GridStep
	y1 := int(spl.Pos2.Y) / common.GridStep
	if ((x1 + y1) & 1) == 1 {
		x1++
	}
	xs := x1
	ys := y1
	v17 := magicWallDirSwap(dir)
	if sp.setWall(spl, x1, y1, v17) != 0 {
		for i := 0; i < sp.lvlLength[spl.Level]; i++ {
			x1 = magicWallCalcX(dir, xs, x1, false)
			y1 = magicWallCalcY(dir, ys, y1, false)
			ndir := magicWallCalcDir(dir, xs, ys, x1, y1)
			if sp.setWall(spl, x1, y1, ndir) == 0 {
				break
			}
		}
		x2 := xs
		y2 := ys
		for j := 0; j < sp.lvlLength[spl.Level]; j++ {
			x2 = magicWallCalcX(dir, xs, x2, true)
			y2 = magicWallCalcY(dir, ys, y2, true)
			ndir := magicWallCalcDir(dir, xs, ys, x2, y2)
			if sp.setWall(spl, x2, y2, ndir) == 0 {
				break
			}
		}
	}
	spl.Frame68 = sp.s.Frame() + dur
	return 0
}

func magicWallCalcDir(a1 int, a2, a3, a4, a5 int) byte {
	dir := magicWallDirSwap(a1)
	switch a1 {
	case 1:
		if a5 != a3 {
			dir = magicWallDirSwap(7)
		}
	case 7:
		if a5 != a3 {
			dir = magicWallDirSwap(1)
		}
	case 3:
		if a4 != a2 {
			dir = magicWallDirSwap(5)
		}
	default:
		if a1 == 5 && a4 != a2 {
			dir = magicWallDirSwap(3)
		}
	}
	return dir
}

func magicWallDirSwap(a1 int) byte {
	switch a1 {
	case 1:
		return 7
	case 2, 6:
		return 1
	case 3:
		return 8
	case 5:
		return 10
	case 7:
		return 9
	default:
		return 0
	}
}

func magicWallCalcX(dir int, sx, x int, mode bool) int {
	if !mode {
		switch dir {
		case 0, 1, 2:
			return x + 1
		case 6, 7, 8:
			return x - 1
		case 3:
			if x != sx {
				return x - 1
			}
			return x + 1
		case 5:
			if x == sx {
				return x - 1
			}
			return x + 1
		default:
			return x
		}
	}
	switch dir {
	case 0, 1, 2:
		return x - 1
	case 6, 7, 8:
		return x + 1
	case 3:
		if x != sx {
			return x - 1
		}
		return x + 1
	case 5:
		if x == sx {
			return x - 1
		}
		return x + 1
	default:
		return x
	}
}
func magicWallCalcY(dir int, sy, y int, mode bool) int {
	if !mode {
		switch dir {
		case 0, 3, 6:
			return y - 1
		case 2, 5, 8:
			return y + 1
		case 1:
			if y != sy {
				return y + 1
			}
			return y - 1
		case 7:
			if y != sy {
				return y - 1
			}
			return y + 1
		default:
			return y
		}
	}
	switch dir {
	case 0, 3, 6:
		return y + 1
	case 2, 5, 8:
		return y - 1
	case 1:
		if y != sy {
			return y + 1
		}
		return y - 1
	case 7:
		if y != sy {
			return y - 1
		}
		return y + 1
	default:
		return y
	}
}

func (sp *spellWall) setWall(spl *server.DurSpell, x, y int, dir uint8) int32 {
	wl := sp.s.Walls.GetWallAtGrid(image.Pt(x, y))
	if wl != nil {
		if sp.s.Walls.IsSysUse(wl) || sp.s.Walls.IsInvisible(wl) {
			return 0
		}
		if wl.Flags4.HasAny(wall.FlagDoor | wall.FlagSecret | wall.FlagBreakable) {
			return 0
		}
		wl.Dir0 = nox_xxx_wall_42A6C0(wl.Dir0, dir)
		wl.Field2 = 0
		sp.newWall(spl, wl, 1, wl.Tile1, wl.Dir0, wl.Field2)
		return 0
	} else {
		wl = sp.s.Walls.CreateAtGrid(image.Pt(x, y))
		if wl == nil {
			return 0
		}
		wl.Tile1 = byte(sp.s.Walls.MagicWallSystemUseOnlyInd())
		wl.Dir0 = dir
		if int32(dir) == 0 || int32(dir) == 1 {
			wl.Field2 = uint8(int8(int32(wl.X5) % int32(int16(sp.s.Walls.DefByInd(int(wl.Tile1)).Field749))))
		} else {
			wl.Field2 = 0
		}
		wl.Flags4 |= wall.FlagBreakable
		wl.Health7 = sp.s.Walls.DefByInd(int(wl.Tile1)).Health41
		sp.newWall(spl, wl, 0, 0, 0, 0)
		return 1
	}
}

func (sp *spellWall) Update(spl *server.DurSpell) int {
	return 0
}

func (sp *spellWall) Destroy(spl *server.DurSpell) {
	var next *server.MagicWall
	for it := sp.list; it != nil; it = next {
		next = it.Next24
		if it.Spell20 == spl {
			sp.destroyWall(it)
		}
	}
}
