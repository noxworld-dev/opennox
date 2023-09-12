package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Sub_5002D0 func(a1 *server.Object)
)

var (
	magicWallAlloc     alloc.ClassT[server.MagicWall] // nox_alloc_magicWall_1569748
	magicWallFirst     *server.MagicWall              // dword_5d4594_1569752
	magicWallLvlLength = []int{                       // 217844
		7, // 0
		3, // 1
		4, // 2
		5, // 3
		6, // 4
		7, // 5
	}
	magicWallsSavedCnt int                      // dword_5d4594_1569756
	magicWallsSavedArr [16]server.MagicWallSave // 1569764
)

func nox_xxx_allocMagicWallArray_4FF730() int32 {
	magicWallsSavedCnt = 0
	magicWallAlloc = alloc.NewClassT("MagicWall", server.MagicWall{}, int(int32((magicWallLvlLength[0]<<6)+32)))
	return bool2int32(magicWallAlloc.Class != nil)
}

func sub_4FF770() int32 {
	magicWallAlloc.Free()
	magicWallFirst = nil
	magicWallsSavedCnt = 0
	return 0
}

func nox_xxx_mapWall_4FF790() {
	magicWallAlloc.FreeAllObjects()
	magicWallFirst = nil
}

func nox_xxx_netWallCreate_4FFE80(a1 *server.DurSpell, a2 *server.Wall, a3 uint32, a4 byte, a5 byte, a6 byte) *server.MagicWall {
	p := magicWallAlloc.NewObject()
	if p == nil {
		return nil
	}
	p.Field8 = a2
	p.Field0 = a3
	p.Field4 = a2.Dir0
	p.Field12 = a4
	p.Field13 = a5
	p.Field14 = a6
	p.Field20 = a1
	p.Field16 = 0
	p.Field28 = nil
	p.Field24 = magicWallFirst
	if magicWallFirst != nil {
		magicWallFirst.Field28 = p
	}
	magicWallFirst = p
	return p
}

func nox_xxx_wallDestroy_4FF870(mw *server.MagicWall) {
	sub_4FF900(mw)
	if noxflags.HasGame(1) {
		if wl := mw.Field8; mw.Field0 != 0 {
			wl.Tile1 = mw.Field12
			mw.Field8.Dir0 = mw.Field13
			mw.Field8.Field2 = mw.Field14
		} else {
			nox_xxx_mapDelWallAtPt_410430(int32(wl.X5), int32(wl.Y6))
		}
	}
	if v2 := mw.Field28; v2 != nil {
		v2.Field24 = mw.Field24
	} else {
		magicWallFirst = mw.Field24
	}
	if v3 := mw.Field24; v3 != nil {
		v3.Field28 = mw.Field28
	}
	magicWallAlloc.FreeObjectFirst(mw)
}

func sub_4FF900(mw *server.MagicWall) {
	for i := 0; i < 32; i++ {
		if mw.Field16&(1<<i) != 0 {
			if mw.Field0 != 0 {
				wl := mw.Field8
				var buf [6]byte
				buf[0] = byte(noxnet.MSG_CHANGE_OR_ADD_WALL_MAGIC)
				buf[1] = mw.Field12
				buf[2] = mw.Field13
				buf[3] = mw.Field14
				buf[4] = wl.X5
				buf[5] = wl.Y6
				nox_xxx_netSendPacket0_4E5420(int32(i), unsafe.Pointer(&buf[0]), 6, nil, 1)
			} else {
				wl := mw.Field8
				var buf [3]byte
				buf[0] = byte(noxnet.MSG_REMOVE_WALL_MAGIC)
				buf[1] = wl.X5
				buf[2] = wl.Y6
				nox_xxx_netSendPacket0_4E5420(int32(i), unsafe.Pointer(&buf), 3, nil, 1)
			}
		}
	}
}

func nox_xxx_mapSetWallInGlobalDir0pr1_5004D0() {
	for it := magicWallFirst; it != nil; it = it.Field24 {
		if it.Field0 == 1 {
			it.Field8.Dir0 = it.Field13
		}
	}
}

func nox_xxx_map_5004F0() {
	for it := magicWallFirst; it != nil; it = it.Field24 {
		if it.Field0 == 1 {
			it.Field8.Dir0 = it.Field4
		}
	}
}

func sub_4FF990(a1 int32) {
	for it := magicWallFirst; it != nil; it = it.Field24 {
		it.Field16 &= uint32(^a1)
	}
}

func nox_xxx_wallDestroyMagicwallSysuse_4FF840(a1 *server.Wall) {
	it := magicWallFirst
	if it == nil {
		return
	}
	for {
		next := it.Field24
		if it.Field8 == a1 {
			nox_xxx_wallDestroy_4FF870(it)
		}
		it = next
		if next == nil {
			break
		}
	}
}

func sub_4FF7B0(pl *server.Player) {
	if pl.PlayerInd == common.MaxPlayers-1 {
		return
	}
	bit := uint32(1) << pl.PlayerInd
	for mw := magicWallFirst; mw != nil; mw = mw.Field24 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(pl), 3680)))&0x10 != 0 {
			if mw.Field16&bit == 0 {
				wl := mw.Field8
				var buf [6]byte
				buf[0] = byte(noxnet.MSG_CHANGE_OR_ADD_WALL_MAGIC)
				buf[1] = wl.Tile1
				buf[2] = wl.Dir0
				buf[3] = wl.Field2
				buf[4] = wl.X5
				buf[5] = wl.Y6
				nox_xxx_netSendPacket0_4E5420(int32(pl.PlayerInd), unsafe.Pointer(&buf[0]), 6, nil, 1)
				mw.Field16 |= bit
			}
		}
	}
}

func sub_5000B0(a1p *server.Object) int32 {
	vers := int16(1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&vers)), 2)
	if vers > 1 || vers <= 0 {
		return 0
	}
	cnt := byte(0)
	for it := magicWallFirst; it != nil; it = it.Field24 {
		cnt++
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&cnt, 1)
	if nox_crypt_IsReadOnly() != 0 {
		if cnt == 0 {
			return 1
		}
		Sub_5002D0(a1p)
		magicWallsSavedCnt = 0
		if cnt == 0 {
			return 1
		}
		for i := 0; i < int(cnt); i++ {
			var (
				dir, fld2, tile, fld14 byte
				fld13, fld12, x, y, hp byte
				fld0                   uint32
			)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&fld0)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&x, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&y, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&fld12, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&fld13, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&fld14, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&tile, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&fld2, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&dir, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&hp, 1)
			sub_500330(x, y, fld0, fld12, fld13, fld14, tile, fld2, dir, hp)
		}
		return 1
	} else {
		for it := magicWallFirst; it != nil; it = it.Field24 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&it.Field0)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&it.Field8.X5, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&it.Field8.Y6, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&it.Field12, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&it.Field13, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&it.Field14, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&it.Field8.Tile1, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&it.Field8.Field2, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&it.Field8.Dir0, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&it.Field8.Health7, 1)
		}
		return 1
	}
}

var _ = [1]struct{}{}[16-unsafe.Sizeof(server.MagicWallSave{})]

func sub_500330(x byte, y byte, fld0 uint32, fld12 byte, fld13 byte, fld14 byte, tile byte, fld2 byte, dir byte, hp byte) {
	if magicWallsSavedCnt < len(magicWallsSavedArr)-1 {
		ind := magicWallsSavedCnt
		p := &magicWallsSavedArr[ind]
		p.X, p.Y = x, y
		p.Field0 = fld0
		p.Field12 = fld12
		p.Field13 = fld13
		p.Field14 = fld14
		p.Tile1 = tile
		p.Field2 = fld2
		p.Dir = dir
		p.Health = hp
		magicWallsSavedCnt++
	}
}

func nox_xxx_playerSomeWallsUpdate_5003B0(obj *server.Object) int32 {
	if magicWallsSavedCnt <= 0 {
		magicWallsSavedCnt = 0
		return 1
	}
	var sp *server.DurSpell
	for it := nox_xxx_spellCastedFirst_4FE930(); it != nil; it = nox_xxx_spellCastedNext_4FE940(it) {
		if spell.ID(it.Spell) == spell.SPELL_WALL && it.Caster16 == obj && it.Flags88&0x1 == 0 {
			sp = it
			break
		}
	}
	if sp == nil {
		return 0
	}
	sp.Create.Set(Nox_xxx_spellWallCreate_4FFA90)
	sp.Update.Set(Nox_xxx_spellWallUpdate_500070)
	sp.Destroy.Set(Nox_xxx_spellWallDestroy_500080)
	sp.Target48 = nil

	for i := 0; i < magicWallsSavedCnt; i++ {
		p := &magicWallsSavedArr[i]
		wl := nox_server_getWallAtGrid_410580(int32(p.X), int32(p.Y))
		if wl != nil {
			wl.Dir0 = p.Dir
		} else {
			wl = nox_xxx_wallCreateAt_410250(int32(p.X), int32(p.Y))
			if wl == nil {
				return 0
			}
			wl.Flags4 |= 8
			wl.Tile1 = p.Tile1
			wl.Field2 = p.Field2
			wl.Dir0 = p.Dir
			wl.Health7 = p.Health
		}
		nox_xxx_netWallCreate_4FFE80(sp, wl, p.Field0, p.Field12, p.Field13, p.Field14)
	}
	magicWallsSavedCnt = 0
	return 1
}

func Nox_xxx_spellWallCreate_4FFA90(sp *server.DurSpell) int32 {
	v22 := int32(gameFPS() * 60 * (sp.Level + 5))
	v2 := sp.Caster16
	if v2 == nil || v2.ObjFlags&0x8020 != 0 {
		return 1
	}
	var a1a float4
	a1a.field_0 = sp.Pos.X
	a1a.field_4 = sp.Pos.Y
	a1a.field_8 = sp.Pos2.X
	a1a.field_C = sp.Pos2.Y
	if int32(uint8(int8(nox_xxx_traceRay_5374B0(&a1a)))) == 0 {
		v6 := sp.Caster16
		if !v6.Class().Has(object.ClassPlayer) {
			return 1
		}
		v7 := v6.UpdateDataPlayer()
		a1b := int32(2)
		nox_xxx_netInformTextMsg_4DA0F0(int32(v7.Player.PlayerInd), 0, &a1b)
		return 1
	}
	var v23 types.Pointf
	v23.X = a1a.field_8 - a1a.field_0
	v23.Y = a1a.field_C - a1a.field_4
	v9 := nox_xxx_math_509ED0(&v23)
	v10 := nox_xxx_math_509EA0(v9)
	x1 := int32(int64(sp.Pos2.X) / 23)
	y1 := int32(int64(sp.Pos2.Y) / 23)
	if ((int32(uint8(int8(x1))) + int32(uint8(int8(y1)))) & 1) == 1 {
		x1++
	}
	xs := x1
	ys := y1
	v17 := uint8(sub_4FFA40(v10))
	if sub_4FFD00(sp, x1, y1, v17) != 0 {
		for i := 0; i < magicWallLvlLength[sp.Level]; i++ {
			x1 = int32(uint8(nox_xxx_spellWallCreateCalcXMB_4FFEF0(v10, xs, x1, 0)))
			y1 = int32(uint8(nox_xxx_spellWallCreateCalcYMB_4FFFB0(v10, ys, y1, 0)))
			v18 := uint8(nox_xxx_spellWallCreateCalcDirMB_4FF9B0(v10, xs, ys, x1, y1))
			if sub_4FFD00(sp, x1, y1, v18) == 0 {
				break
			}
		}
		x2 := xs
		y2 := ys
		for j := 0; j < magicWallLvlLength[sp.Level]; j++ {
			x2 = int32(uint8(nox_xxx_spellWallCreateCalcXMB_4FFEF0(v10, xs, x2, 1)))
			y2 = int32(uint8(nox_xxx_spellWallCreateCalcYMB_4FFFB0(v10, ys, y2, 1)))
			v19 := uint8(nox_xxx_spellWallCreateCalcDirMB_4FF9B0(v10, xs, ys, x2, y2))
			if sub_4FFD00(sp, x2, y2, v19) == 0 {
				break
			}
		}
	}
	sp.Frame68 = uint32(v22) + gameFrame()
	return 0
}

func nox_xxx_spellWallCreateCalcDirMB_4FF9B0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int8 {
	dir := sub_4FFA40(a1)
	switch a1 {
	case 1:
		if a5 != a3 {
			dir = sub_4FFA40(7)
		}
	case 7:
		if a5 != a3 {
			dir = sub_4FFA40(1)
		}
	case 3:
		if a4 != a2 {
			dir = sub_4FFA40(5)
		}
	default:
		if a1 == 5 && a4 != a2 {
			dir = sub_4FFA40(3)
		}
	}
	return dir
}

func sub_4FFA40(a1 int32) int8 {
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

func nox_xxx_spellWallCreateCalcXMB_4FFEF0(a1 int32, a2 int32, a3 int32, a4 int8) int8 {
	var v5 int8
	if int32(a4) == 0 {
		switch a1 {
		case 0:
			return int8(a3 + 1)
		case 1:
			return int8(a3 + 1)
		case 2:
			return int8(a3 + 1)
		case 3:
			v5 = int8(a3)
			if a3 != a2 {
				return int8(int32(v5) - 1)
			}
			return int8(int32(v5) + 1)
		case 5:
			v5 = int8(a3)
			if a3 == a2 {
				return int8(int32(v5) - 1)
			}
			return int8(int32(v5) + 1)
		case 6:
			return int8(a3 - 1)
		case 7:
			return int8(a3 - 1)
		case 8:
			return int8(a3 - 1)
		default:
			return int8(a3)
		}
	}
	switch a1 {
	case 0:
		return int8(a3 - 1)
	case 1:
		return int8(a3 - 1)
	case 2:
		return int8(a3 - 1)
	case 3:
		v5 = int8(a3)
		if a3 != a2 {
			return int8(int32(v5) - 1)
		}
		return int8(int32(v5) + 1)
	case 5:
		v5 = int8(a3)
		if a3 == a2 {
			return int8(int32(v5) - 1)
		}
		return int8(int32(v5) + 1)
	case 6:
		return int8(a3 + 1)
	case 7:
		return int8(a3 + 1)
	case 8:
		return int8(a3 + 1)
	default:
		return int8(a3)
	}
}
func nox_xxx_spellWallCreateCalcYMB_4FFFB0(a1 int32, a2 int32, a3 int32, a4 int8) int8 {
	var v4 int8
	if int32(a4) == 0 {
		switch a1 {
		case 0:
			v4 = int8(a3)
			return int8(int32(v4) - 1)
		case 1:
			v4 = int8(a3)
			if a3 != a2 {
				return int8(int32(v4) + 1)
			}
			return int8(a3 - 1)
		case 2:
			return int8(a3 + 1)
		case 3:
			return int8(a3 - 1)
		case 5:
			return int8(a3 + 1)
		case 6:
			return int8(a3 - 1)
		case 7:
			v4 = int8(a3)
			if a3 != a2 {
				return int8(int32(v4) - 1)
			}
			return int8(int32(v4) + 1)
		case 8:
			return int8(a3 + 1)
		default:
			return int8(a3)
		}
	}
	switch a1 {
	case 0:
		return int8(a3 + 1)
	case 1:
		v4 = int8(a3)
		if a3 != a2 {
			return int8(int32(v4) + 1)
		}
		return int8(a3 - 1)
	case 2:
		return int8(a3 - 1)
	case 3:
		return int8(a3 + 1)
	case 5:
		return int8(a3 - 1)
	case 6:
		return int8(a3 + 1)
	case 7:
		v4 = int8(a3)
		if a3 != a2 {
			return int8(int32(v4) - 1)
		}
		return int8(int32(v4) + 1)
	case 8:
		v4 = int8(a3)
		return int8(int32(v4) - 1)
	default:
		return int8(a3)
	}
}

func sub_4FFD00(sp *server.DurSpell, x int32, y int32, dir uint8) int32 {
	if int32(*memmap.PtrUint8(0x5D4594, 1570004)) == 0 {
		*memmap.PtrUint8(0x5D4594, 1570004) = uint8(int8(nox_xxx_wallTileByName_410D60(internCStr("MagicWallSystemUseOnly"))))
		*memmap.PtrUint8(0x5D4594, 1570005) = uint8(int8(nox_xxx_wallTileByName_410D60(internCStr("InvisibleWallSet"))))
		*memmap.PtrUint8(0x5D4594, 1570006) = uint8(int8(nox_xxx_wallTileByName_410D60(internCStr("InvisibleBlockingWallSet"))))
	}
	wl := nox_server_getWallAtGrid_410580(x, y)
	if wl != nil {
		if int32(wl.Tile1) == int32(*memmap.PtrUint8(0x5D4594, 1570004)) {
			return 0
		}
		if int32(wl.Tile1) == int32(*memmap.PtrUint8(0x5D4594, 1570005)) || int32(wl.Tile1) == int32(*memmap.PtrUint8(0x5D4594, 1570006)) {
			return 0
		}
		if int32(wl.Flags4)&0x1C != 0 {
			return 0
		}
		wl.Dir0 = nox_xxx_wall_42A6C0(wl.Dir0, dir)
		wl.Field2 = 0
		nox_xxx_netWallCreate_4FFE80(sp, wl, 1, wl.Tile1, wl.Dir0, wl.Field2)
		return 0
	} else {
		wl = nox_xxx_wallCreateAt_410250(x, y)
		if wl == nil {
			return 0
		}
		wl.Tile1 = *memmap.PtrUint8(0x5D4594, 1570004)
		wl.Dir0 = dir
		if int32(dir) == 0 || int32(dir) == 1 {
			wl.Field2 = uint8(int8(int32(wl.X5) % int32(int16(nox_xxx_map_410E00(int32(wl.Tile1))))))
		} else {
			wl.Field2 = 0
		}
		wl.Flags4 |= 8
		wl.Health7 = nox_xxx_mapWallGetHpByTile_410E20(int32(wl.Tile1))
		nox_xxx_netWallCreate_4FFE80(sp, wl, 0, 0, 0, 0)
		return 1
	}
}

func Nox_xxx_spellWallUpdate_500070(sp *server.DurSpell) int32 {
	return 0
}

func Nox_xxx_spellWallDestroy_500080(sp *server.DurSpell) {
	var next *server.MagicWall
	for it := magicWallFirst; it != nil; it = next {
		next = it.Field24
		if it.Field20 == sp {
			nox_xxx_wallDestroy_4FF870(it)
		}
	}
}
