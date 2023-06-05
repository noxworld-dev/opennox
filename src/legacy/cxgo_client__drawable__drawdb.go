package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/stdio"

	"github.com/noxworld-dev/opennox/v1/client"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func init() {
	client.RegisterObjectUpdate("ColorLightUpdateDraw", nox_xxx_updDrawColorlight_4CE390)
	client.RegisterObjectUpdate("CloudUpdateDraw", nox_xxx_updDrawCloud_4CE1D0)
	client.RegisterObjectUpdate("SmallCloudUpdateDraw", sub_4CE360)
	client.RegisterObjectUpdate("DeathBallUpdateDraw", nox_xxx_updDrawDBall_4CDF80)
	client.RegisterObjectUpdate("DeathBallFragmentUpdateDraw", sub_4CE0A0)
	client.RegisterObjectUpdate("DeathBallChargeUpdateDraw", nox_xxx_updDrawDBallCharge_4CE0C0)
	client.RegisterObjectUpdate("MagicUpdateDraw", nox_xxx_updDrawMagic_4CDD80)
	client.RegisterObjectUpdate("SparkleTrailUpdateDraw", nox_xxx_updDrawSparkleTrail_4CDBF0)
	client.RegisterObjectUpdate("MagicMissileUpdateDraw", nox_xxx_updDrawMagicMissile_4CD9E0)
	client.RegisterObjectUpdate("TeleportWakeUpdateDraw", nox_xxx_updDrawTeleportWake_4CD8D0)
	client.RegisterObjectUpdate("DrainManaUpdateDraw", sub_4CD690)
	client.RegisterObjectUpdate("HealUpdateDraw", sub_4CD450)
	client.RegisterObjectUpdate("CharmUpdateDraw", sub_4CD400)
	client.RegisterObjectUpdate("TitanFireballUpdateDraw", sub_4CCE70)
	client.RegisterObjectUpdate("StrongFireballUpdateDraw", sub_4CD090)
	client.RegisterObjectUpdate("FireballUpdateDraw", sub_4CD0C0)
	client.RegisterObjectUpdate("WeakFireballUpdateDraw", sub_4CD0F0)
	client.RegisterObjectUpdate("PitifulFireballUpdateDraw", sub_4CD120)
	client.RegisterObjectUpdate("FistUpdateDraw", nox_xxx_updDrawFist_4CCDB0)
	client.RegisterObjectUpdate("MeteorUpdateDraw", sub_4CCD00)
	client.RegisterObjectUpdate("UndeadKillerClientUpdate", nox_xxx_updDrawUndeadKiller_4CCCF0)
	client.RegisterObjectUpdate("ManaBombChargeClientUpdate", nox_xxx_updDrawManabombCharge_4CCAC0)
	client.RegisterObjectUpdate("VortexSourceClientUpdate", nox_xxx_updDrawVortexSource_4CC950)
	client.RegisterObjectUpdate("LinearOrbUpdateDraw", sub_4CA650)
	client.RegisterObjectUpdate("MonsterGeneratorUpdateDraw", nox_xxx_updDrawMonsterGen_4BC920)
}

func nox_parse_thing_draw(obj *nox_thing, f *nox_memfile, data unsafe.Pointer) bool {
	var (
		attr_value       = (*byte)(data)
		read_len   uint8 = nox_memfile_read_u8(f)
		read_str   [256]byte
	)
	nox_memfile_read(unsafe.Pointer(&read_str[0]), 1, int32(read_len), f)
	read_str[read_len] = 0
	var tmp uint32
	nox_memfile_read64align_40AD60((*byte)(unsafe.Pointer(&tmp)), int32(4), 1, f)
	if *(*uint32)(unsafe.Pointer(&nox_parse_thing_draw_funcs[0])) == 0 {
		return true
	}
	var item *nox_parse_thing_draw_funcs_t
	for i := range nox_parse_thing_draw_funcs {
		cur := &nox_parse_thing_draw_funcs[i]
		if cur.name == GoString(&read_str[0]) {
			item = cur
			break
		}
	}
	if item == nil {
		return true
	}
	if item.parse_fnc != nil {
		item.parse_fnc(obj, f, attr_value)
	}
	obj.DrawFunc = ccall.FuncPtr(item.draw)
	return true
}
func nox_parse_thing_light_dir(obj *nox_thing, f *nox_memfile, data unsafe.Pointer) bool {
	attr_value := (*byte)(data)
	var deg int32 = 0
	if stdio.Sscanf(attr_value, "%d", &deg) != 1 {
		return false
	}
	if deg < 0 || deg >= 360 {
		return false
	}
	obj.LightDir = uint16(int16(int64(float64(deg)**mem_getDoublePtr(0x581450, 9560)**(*float64)(unsafe.Pointer(&qword_581450_9552)) + *(*float64)(unsafe.Pointer(&qword_581450_9544)))))
	obj.Field_10 = 0
	return true
}
func nox_parse_thing_light_penumbra(obj *nox_thing, f *nox_memfile, data unsafe.Pointer) bool {
	attr_value := (*byte)(data)
	var deg int32 = 0
	if stdio.Sscanf(attr_value, "%d", &deg) != 1 {
		return false
	}
	if deg < 0 || deg >= 180 {
		return false
	}
	obj.LightPenumbra = uint16(int16(int64(float64(deg)**mem_getDoublePtr(0x581450, 9560)**(*float64)(unsafe.Pointer(&qword_581450_9552)) + *(*float64)(unsafe.Pointer(&qword_581450_9544)))))
	return true
}

func nox_parse_thing_pretty_image(obj *nox_thing, f *nox_memfile, data unsafe.Pointer) bool {
	var (
		v10       [128]byte
		known_idx uint32 = nox_memfile_read_u32(f)
	)
	if known_idx != math.MaxUint32 {
		obj.PrettyImage = uint32(uintptr(unsafe.Pointer(nox_xxx_readImgMB_42FAA0(int32(known_idx), 0, &v10[0]))))
		return true
	}
	var v8 int32 = int32(nox_memfile_read_u8(f))
	var n int32 = int32(nox_memfile_read_u8(f))
	nox_memfile_read(unsafe.Pointer(&v10[0]), 1, n, f)
	obj.PrettyImage = uint32(uintptr(unsafe.Pointer(nox_xxx_readImgMB_42FAA0(int32(known_idx), int8(v8), &v10[0]))))
	return true
}
func nox_free_tile_defs() int32 {
	for i := int32(0); uint32(i) < nox_tile_def_cnt; i++ {
		var it *nox_tileDef_t = &nox_tile_defs_arr[i]
		if it.data_32 != nil {
			alloc.Free(it.data_32)
			it.data_32 = nil
		}
	}
	return 1
}
func sub_485F30() int32 {
	var (
		v0 int32
		v1 *unsafe.Pointer
	)
	v0 = 0
	if *(*int32)(unsafe.Pointer(&dword_5d4594_251572)) <= 0 {
		return 1
	}
	v1 = (*unsafe.Pointer)(memmap.PtrOff(0x85B3FC, 28676))
	for {
		if *v1 != nil {
			alloc.FreePtr(*v1)
			*v1 = nil
		}
		v0++
		v1 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(unsafe.Pointer(nil))*15))
		if v0 >= *(*int32)(unsafe.Pointer(&dword_5d4594_251572)) {
			break
		}
	}
	return 1
}
func nox_xxx_equipArmor_415AB0() {
	var (
		v0 *uint8
		v1 int32
		v2 int32
	)
	if *memmap.PtrUint32(0x5D4594, 371252) != 1 {
		if *memmap.PtrUint32(0x587000, 34848) != 0 {
			v0 = (*uint8)(memmap.PtrOff(0x587000, 34864))
			for {
				if noxflags.HasGame(2097153) {
					*((*uint32)(unsafe.Add(unsafe.Pointer(v0), -int(4*2)))) = uint32(nox_xxx_getNameId_4E3AA0(*((**byte)(unsafe.Add(unsafe.Pointer(v0), -int(unsafe.Sizeof((*byte)(nil))*4))))))
					v1 = nox_xxx_getNameId_4E3AA0(*(**byte)(unsafe.Pointer(v0)))
				} else {
					*((*uint32)(unsafe.Add(unsafe.Pointer(v0), -int(4*2)))) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(*((**byte)(unsafe.Add(unsafe.Pointer(v0), -int(unsafe.Sizeof((*byte)(nil))*4))))))
					v1 = nox_xxx_getTTByNameSpriteMB_44CFC0(*(**byte)(unsafe.Pointer(v0)))
				}
				*((*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*1))) = uint32(v1)
				v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*2))))
				v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 24))
				if v2 == 0 {
					break
				}
			}
		}
		*memmap.PtrUint32(0x5D4594, 371252) = 1
	}
}
func nox_xxx_equipWeapon_4157C0() {
	var (
		v0 *uint8
		v1 int32
		v2 int32
	)
	if *memmap.PtrUint32(0x5D4594, 371244) != 1 {
		if *memmap.PtrUint32(0x587000, 33064) != 0 {
			v0 = (*uint8)(memmap.PtrOff(0x587000, 33064))
			for {
				if noxflags.HasGame(2097153) {
					v1 = nox_xxx_getNameId_4E3AA0(*(**byte)(unsafe.Pointer(v0)))
				} else {
					v1 = nox_xxx_getTTByNameSpriteMB_44CFC0(*(**byte)(unsafe.Pointer(v0)))
				}
				*((*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*1))) = uint32(v1)
				v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*3))))
				v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 12))
				if v2 == 0 {
					break
				}
			}
		}
		*memmap.PtrUint32(0x5D4594, 371244) = 1
	}
}
func sub_4F0640() int32 {
	var (
		v0     *byte
		v1     *uint8
		v2     int8
		v3     *byte
		v4     *byte
		v5     *uint8
		v6     int32
		v7     *byte
		v8     *uint8
		v9     int32
		v10    *byte
		v11    *uint8
		v12    int32
		result *byte
		v14    *uint8
		v15    int32
	)
	v0 = *(**byte)(memmap.PtrOff(0x587000, 208180))
	if *memmap.PtrUint32(0x587000, 208180) != 0 {
		v1 = (*uint8)(memmap.PtrOff(0x587000, 208180))
		for {
			v2 = int8(*v0)
			v3 = *(**byte)(unsafe.Pointer(v1))
			if int32(v2) == 35 {
				v3 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1))
			}
			*((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*1))) = uint32(nox_xxx_getNameId_4E3AA0(v3))
			v0 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*5))))))
			v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 20))
			if v0 == nil {
				break
			}
		}
	}
	v4 = *(**byte)(memmap.PtrOff(0x587000, 210712))
	if *memmap.PtrUint32(0x587000, 210712) != 0 {
		v5 = (*uint8)(memmap.PtrOff(0x587000, 210712))
		for {
			v6 = nox_xxx_modifGetIdByName_413290(v4)
			*((*uint32)(unsafe.Add(unsafe.Pointer(v5), -int(4*1)))) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v6)))
			v4 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*6))))))
			v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 24))
			if v4 == nil {
				break
			}
		}
	}
	v7 = *(**byte)(memmap.PtrOff(0x587000, 210856))
	if *memmap.PtrUint32(0x587000, 210856) != 0 {
		v8 = (*uint8)(memmap.PtrOff(0x587000, 210856))
		for {
			v9 = nox_xxx_modifGetIdByName_413290(v7)
			*((*uint32)(unsafe.Add(unsafe.Pointer(v8), -int(4*1)))) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v9)))
			v7 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*6))))))
			v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 24))
			if v7 == nil {
				break
			}
		}
	}
	v10 = *(**byte)(memmap.PtrOff(0x587000, 211000))
	if *memmap.PtrUint32(0x587000, 211000) != 0 {
		v11 = (*uint8)(memmap.PtrOff(0x587000, 211000))
		for {
			v12 = nox_xxx_modifGetIdByName_413290(v10)
			*((*uint32)(unsafe.Add(unsafe.Pointer(v11), -int(4*1)))) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v12)))
			v10 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*6))))))
			v11 = (*uint8)(unsafe.Add(unsafe.Pointer(v11), 24))
			if v10 == nil {
				break
			}
		}
	}
	result = *(**byte)(memmap.PtrOff(0x587000, 209344))
	if *memmap.PtrUint32(0x587000, 209344) != 0 {
		v14 = (*uint8)(memmap.PtrOff(0x587000, 209344))
		for {
			v15 = nox_xxx_modifGetIdByName_413290(result)
			*((*uint32)(unsafe.Add(unsafe.Pointer(v14), -int(4*1)))) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v15)))
			result = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*6))))))
			v14 = (*uint8)(unsafe.Add(unsafe.Pointer(v14), 24))
			if result == nil {
				break
			}
		}
	}
	return int32(uintptr(unsafe.Pointer(result)))
}
func nox_xxx_draw_44C780(a1 int32) unsafe.Pointer {
	var (
		i      int32
		v2     int32
		result unsafe.Pointer
	)
	for i = 0; i < 32; i += 4 {
		v2 = i
		if i >= 16 {
			v2 = i + 4
		}
		result = *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v2 + a1)))
		if result != nil {
			alloc.FreePtr(result)
		}
	}
	return result
}
func sub_44C7B0(a1 int32) unsafe.Pointer {
	var (
		v1     *unsafe.Pointer
		v2     int32
		v3     *unsafe.Pointer
		v4     int32
		v5     *unsafe.Pointer
		v6     int32
		result unsafe.Pointer
	)
	v1 = (*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 52)))
	v2 = 55
	for {
		if *v1 != nil {
			nox_xxx_draw_44C780(int32(uintptr(*v1)) + 4)
			alloc.FreePtr(*v1)
		}
		v3 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(unsafe.Pointer(nil))*1))
		v4 = 26
		for {
			if *v3 != nil {
				nox_xxx_draw_44C780(int32(uintptr(*v3)) + 4)
				alloc.FreePtr(*v3)
			}
			v3 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(unsafe.Pointer(nil))*1))
			v4--
			if v4 == 0 {
				break
			}
		}
		v5 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(unsafe.Pointer(nil))*27))
		v6 = 27
		for {
			result = *v5
			if *v5 != nil {
				nox_xxx_draw_44C780(int32(uintptr(result)) + 4)
				alloc.FreePtr(*v5)
			}
			v5 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(unsafe.Pointer(nil))*1))
			v6--
			if v6 == 0 {
				break
			}
		}
		v1 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(unsafe.Pointer(nil))*66))
		v2--
		if v2 == 0 {
			break
		}
	}
	return result
}
func Nox_xxx_draw_44C650_free(lpMem unsafe.Pointer, draw client.ObjectDrawFunc) {
	var kind int32 = 0
	if nox_parse_thing_draw_funcs[0].name != "" {
		var item *nox_parse_thing_draw_funcs_t
		for i := range nox_parse_thing_draw_funcs {
			cur := &nox_parse_thing_draw_funcs[i]
			if cur.name == "" {
				break
			}
			if ccall.FuncAddr(cur.draw) == ccall.FuncAddr(draw) {
				item = cur
				break
			}
		}
		if item != nil {
			kind = int32(item.kind)
		}
	}
	var v7 *unsafe.Pointer = nil
	var v8 int32 = 0
	var v9 *byte = nil
	var v10 int32 = 0
	var v11 *byte = nil
	var v12 int32 = 0
	switch kind {
	case 2, 3:
		if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(lpMem)), 4*1))) != 0 {
			alloc.FreePtr(*((*unsafe.Pointer)(unsafe.Add(unsafe.Pointer((*unsafe.Pointer)(lpMem)), unsafe.Sizeof(unsafe.Pointer(nil))*1))))
		}
		alloc.FreePtr(lpMem)
	case 4:
		v7 = (*unsafe.Pointer)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(lpMem)), 4))))
		v8 = 5
		for {
			if *v7 != nil {
				alloc.FreePtr(*v7)
			}
			v7 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(unsafe.Pointer(nil))*1))
			v8--
			if v8 == 0 {
				break
			}
		}
		alloc.FreePtr(lpMem)
	case 5:
		nox_xxx_draw_44C780(int32(uintptr(lpMem)) + 4)
		alloc.FreePtr(lpMem)
	case 6:
		sub_44C7B0(int32(uintptr(lpMem)))
		alloc.FreePtr(lpMem)
	case 7:
		v9 = (*byte)(unsafe.Add(unsafe.Pointer((*byte)(lpMem)), 8))
		v10 = 16
		for {
			nox_xxx_draw_44C780(int32(uintptr(unsafe.Pointer(v9))))
			v9 = (*byte)(unsafe.Add(unsafe.Pointer(v9), 48))
			v10--
			if v10 == 0 {
				break
			}
		}
		alloc.FreePtr(lpMem)
	case 8:
		v11 = (*byte)(unsafe.Add(unsafe.Pointer((*byte)(lpMem)), 8))
		v12 = 3
		for {
			nox_xxx_draw_44C780(int32(uintptr(unsafe.Pointer(v11))))
			v11 = (*byte)(unsafe.Add(unsafe.Pointer(v11), 48))
			v12--
			if v12 == 0 {
				break
			}
		}
		alloc.FreePtr(lpMem)
	default:
		alloc.FreePtr(lpMem)
	}
}
