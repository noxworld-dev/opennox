package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_win_unk5 *gui.Window
var dword_5d4594_1062452 *gui.Window
var nox_windows_arr_1093036 [7]nox_window_yyy
var ptr_5D4594_2650668 **obj_5D4594_2650668_t
var ptr_5D4594_2650668_cap int32 = 128
var nox_client_inventory_grid_1050020 [84]nox_inventory_cell_t

func sub_460D40() int32 {
	return bool2int32(dword_5d4594_1049508 != nil)
}
func sub_460D50() int32 {
	var (
		v0     *uint8
		v1     **uint32
		v2     int32
		v3     *uint8
		result int32
	)
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1049500)
	dword_5d4594_1049500 = nil
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1049504)
	dword_5d4594_1049504 = nil
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1049520)
	dword_5d4594_1049520 = nil
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1049508)
	dword_5d4594_1049508 = nil
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1049512)
	dword_5d4594_1049512 = nil
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1049516)
	dword_5d4594_1049516 = nil
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 1048404))
	for {
		nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(v0)))))
		*(*uint32)(unsafe.Pointer(v0)) = 0
		v1 = (**uint32)(unsafe.Add(unsafe.Pointer(v0), 24))
		v2 = 5
		for {
			nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), -int(unsafe.Sizeof((*uint32)(nil))*5))))))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v1), -int(unsafe.Sizeof((*uint32)(nil))*5))) = nil
			nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(*v1)))
			*v1 = nil
			v1 = (**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*1))
			v2--
			if v2 == 0 {
				break
			}
		}
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 256))
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1049684))) {
			break
		}
	}
	nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, 1048148)))))
	*memmap.PtrUint32(0x5D4594, 1048148) = 0
	v3 = (*uint8)(memmap.PtrOff(0x5D4594, 1048152))
	for {
		result = nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(v3)))))
		*(*uint32)(unsafe.Pointer(v3)) = 0
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
		if int32(uintptr(unsafe.Pointer(v3))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1048164))) {
			break
		}
	}
	dword_5d4594_1049532 = nil
	*memmap.PtrUint32(0x5D4594, 1047928) = 0
	dword_5d4594_1047932 = 0
	return result
}
func nox_xxx_cliPrepareGameplay1_460E60() int32 {
	var result int32
	if sub_460D40() != 0 {
		sub_460D50()
	}
	result = nox_xxx_quickBarCreate_45E190()
	if result != 0 {
		sub_460EA0(nox_client_getRenderGUI())
		result = 1
	}
	return result
}
func sub_460EA0(a1 int32) {
	sub_460B90(a1)
}
func sub_460EB0(a1 int32, a2 int8) {
	if a1 < 0 || a1 >= 140 {
		return
	}
	*memmap.PtrUint8(0x5D4594, uintptr(a1)+1049544) = uint8(a2)
}
func sub_461010() {
	if dword_5d4594_1049484 == 0 {
		return
	}
	nox_window_set_hidden((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1048148)), 1)
	nox_window_set_hidden(dword_5d4594_1049512, 0)
	sub_46AE10(dword_5d4594_1049500.C(), 0)
	nox_xxx_clientPlaySoundSpecial_452D80(797, 100)
	dword_5d4594_1049484 = 0
}
func sub_461060() {
	if dword_5d4594_1049484 == 1 {
		sub_461010()
		return
	}
	if *memmap.PtrUint32(0x5D4594, 1049476) == 1 {
		nox_xxx_quickBarClose_4606B0()
	}
	nox_window_set_hidden((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1048148)), 0)
	nox_window_set_hidden(dword_5d4594_1049512, 1)
	sub_46AE10(dword_5d4594_1049500.C(), 1)
	nox_xxx_clientPlaySoundSpecial_452D80(796, 100)
	dword_5d4594_1049484 = 1
}
func sub_461090(a1 int32, a2 int32) *byte {
	var (
		v2     int32
		result *byte
	)
	v2 = int32(gameFrame())
	result = (*byte)(memmap.PtrOff(0x5D4594, 1047764+24*1+20))
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(result), -int(4*5))) == uint32(a1) {
			if a2 == 0 {
				*(*uint32)(unsafe.Pointer(result)) = uint32(v2)
			} else {
				*(*uint32)(unsafe.Pointer(result)) = 0
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(result), -int(4*3))) = uint32(a2)
		}
		result = (*byte)(unsafe.Add(unsafe.Pointer(result), 24))
		if int32(uintptr(unsafe.Pointer(result))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1047928))) {
			break
		}
	}
	return result
}
func sub_4610D0(a1 uint8) *byte {
	var (
		v1     *int32
		result *byte
	)
	if int32(a1) != 6 {
		return sub_461090(int32(*memmap.PtrUint32(0x5D4594, uintptr(int32(a1)*24)+1047764)), 1)
	}
	v1 = mem_getI32Ptr(0x5D4594, 1047764+24*1)
	for {
		result = sub_461090(*v1, 1)
		v1 = (*int32)(unsafe.Add(unsafe.Pointer(v1), 4*6))
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1047908))) {
			break
		}
	}
	return result
}
func sub_461120(a1 int32, a2 int32) *byte {
	var (
		v2     int32
		result *byte
	)
	v2 = 1 << a1
	result = (*byte)(memmap.PtrOff(0x5D4594, 1047764+24*1+12))
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(result), -int(4*3))) == uint32(a1) {
			if a2 != 0 {
				*(*uint32)(unsafe.Pointer(result)) |= uint32(v2)
			} else {
				*(*uint32)(unsafe.Pointer(result)) &= uint32(^v2)
			}
		}
		result = (*byte)(unsafe.Add(unsafe.Pointer(result), 24))
		if int32(uintptr(unsafe.Pointer(result))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1047920))) {
			break
		}
	}
	return result
}
func sub_461160(a1 int32) int32 {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = 1
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1047764+24*1))
	for *(*uint32)(unsafe.Pointer(v2)) != uint32(a1) {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 24))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1047908))) {
			return 0
		}
	}
	return bool2int32((uint32(1<<a1) & *memmap.PtrUint32(0x5D4594, uintptr(v1*24)+1047764+12)) != 0)
}
func sub_4611A0() int32 {
	return int32(dword_5d4594_1047932)
}
func sub_4611B0() {
	if dword_5d4594_1047936 != 0 {
		nox_xxx_clientSendAbil_45DAF0(dword_5d4594_1047936)
		dword_5d4594_1047936 = 0
		dword_5d4594_1047932 = 0
	}
}
func nox_xxx_netAbilityRewardCli_4611E0(a1 int32, a2 int32, a3 *byte) {
	var v3 *uint8
	if a1 >= 1 && a1 < 6 {
		v3 = (*uint8)(memmap.PtrOff(0x5D4594, 1047764+24*1+16))
		for {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v3), -int(4*4))) == uint32(a1) && *(*uint32)(unsafe.Pointer(v3)) != uint32(a2) {
				if noxflags.HasGame(2) && *memmap.PtrUint32(0x8531A0, 2576) != 0 {
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576)+uint32(a1*4))), 3696)) = uint32(a2)
				}
				*(*uint32)(unsafe.Pointer(v3)) = uint32(a2)
				if a2 != 0 {
					nox_xxx_abilityReward_45D290(a1, a3, int32(uintptr(unsafe.Pointer(a3))))
				}
			}
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 24))
			if int32(uintptr(unsafe.Pointer(v3))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1047924))) {
				break
			}
		}
	}
}
func nox_xxx_buttonFindFirstEmptySlot_461250() int32 {
	var (
		v0 int32
		v1 int32
		v2 *uint32
	)
	v0 = int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))
	for {
		v1 = 0
		v2 = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) + uint32(v0*40))))
		for {
			if *v2 == 0 {
				nox_xxx_clientUpdateButtonRow_45E110(v0)
				return v1
			}
			v1++
			v2 = (*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2))
			if v1 >= 5 {
				break
			}
		}
		if func() int32 {
			p := &v0
			*p++
			return *p
		}() >= 5 {
			v0 = 0
		}
		if v0 == int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200))) {
			break
		}
	}
	return -1
}
func sub_4612A0() int32 {
	var (
		result int32
		i      *uint32
	)
	result = 0
	for i = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) + uint32(int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))*40)))); *i != 0; i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*2)) {
		if func() int32 {
			p := &result
			*p++
			return *p
		}() >= 5 {
			return -1
		}
	}
	return result
}
func nox_xxx_buttonHaveSpellInBarMB_4612D0(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		v3 *uint32
	)
	v1 = int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))
	for {
		v2 = 0
		v3 = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) + uint32(v1*40))))
		for {
			if *v3 == uint32(a1) {
				return 1
			}
			v2++
			v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2))
			if v2 >= 5 {
				break
			}
		}
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= 5 {
			v1 = 0
		}
		if v1 == int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200))) {
			break
		}
	}
	return 0
}
func nox_xxx_buttonSetImgMB_461320(a1 int32, a2 *int2) {
	if a2 != nil {
		if a1 >= 0 && a1 < 5 {
			nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480))+uint32(a1*4))), 212)))), &a2.field_0, &a2.field_4)
		}
	}
}
func sub_461360(a1 int32) int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		v4     int32
		result int32
	)
	v1 = int32(uintptr(nox_xxx_aClosewoodengat_587000_133480))
	v2 = int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))
	v3 = int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))
	for {
		v4 = 5
		result = v2 * 40
		for {
			if *(*uint32)(unsafe.Pointer(uintptr(result + v1))) == uint32(a1) {
				*(*uint32)(unsafe.Pointer(uintptr(result + v1))) = 0
				v1 = int32(uintptr(nox_xxx_aClosewoodengat_587000_133480))
			}
			result += 8
			v4--
			if v4 == 0 {
				break
			}
		}
		if func() int32 {
			p := &v2
			*p++
			return *p
		}() >= 5 {
			v2 = 0
		}
		if v2 == v3 {
			break
		}
	}
	return result
}
func sub_461400() int32 {
	var (
		i      int32
		result int32
		v2     int32
	)
	for i = 0; i < 40; i += 8 {
		result = i
		v2 = 5
		for {
			*(*uint32)(unsafe.Pointer(uintptr(uint32(result) + uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480))))) = *memmap.PtrUint32(0x5D4594, uintptr(result)+1047564)
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(result)+uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)))), 4)) = *memmap.PtrUint8(0x5D4594, uintptr(result)+1047568)
			result += 40
			v2--
			if v2 == 0 {
				break
			}
		}
	}
	return result
}
func sub_461440(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1049688) = uint32(a1)
	return result
}
func sub_461450() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1049688))
}
func nox_xxx_playerInitColors_461460(pl *server.Player) {
	var (
		a1  = unsafe.Pointer(pl)
		v1  int32
		v2  int8
		v3  int8
		v4  int32
		v5  int8
		v6  int8
		v7  int32
		v8  int8
		v9  int8
		v10 int32
		v11 int8
		v12 int8
	)
	v1 = int32(nox_color_rgb_4344A0(int32(*(*uint8)(unsafe.Add(a1, 2253))), int32(*(*uint8)(unsafe.Add(a1, 2254))), int32(*(*uint8)(unsafe.Add(a1, 2255)))))
	v2 = int8(*(*uint8)(unsafe.Add(a1, 2257)))
	v3 = int8(*(*uint8)(unsafe.Add(a1, 2256)))
	*(*uint32)(unsafe.Add(a1, 2296)) = uint32(v1)
	v4 = int32(nox_color_rgb_4344A0(int32(v3), int32(v2), int32(*(*uint8)(unsafe.Add(a1, 2258)))))
	v5 = int8(*(*uint8)(unsafe.Add(a1, 2260)))
	v6 = int8(*(*uint8)(unsafe.Add(a1, 2259)))
	*(*uint32)(unsafe.Add(a1, 2292)) = uint32(v4)
	v7 = int32(nox_color_rgb_4344A0(int32(v6), int32(v5), int32(*(*uint8)(unsafe.Add(a1, 2261)))))
	v8 = int8(*(*uint8)(unsafe.Add(a1, 2263)))
	v9 = int8(*(*uint8)(unsafe.Add(a1, 2262)))
	*(*uint32)(unsafe.Add(a1, 2300)) = uint32(v7)
	v10 = int32(nox_color_rgb_4344A0(int32(v9), int32(v8), int32(*(*uint8)(unsafe.Add(a1, 2264)))))
	v11 = int8(*(*uint8)(unsafe.Add(a1, 2266)))
	v12 = int8(*(*uint8)(unsafe.Add(a1, 2265)))
	*(*uint32)(unsafe.Add(a1, 2304)) = uint32(v10)
	*(*uint32)(unsafe.Add(a1, 2308)) = nox_color_rgb_4344A0(int32(v12), int32(v11), int32(*(*uint8)(unsafe.Add(a1, 2267))))
	*(*uint32)(unsafe.Add(a1, 2312)) = nox_color_white_2523948
}
func sub_461520() {
	result := unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())
	for i := result; result != nil; i = result {
		nox_xxx_playerInitColors_461460((*server.Player)(i))
		result = unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(i)))
	}
}
func nox_xxx_clientSetAltWeapon_461550(a1 *nox_inventory_cell_t) {
	if dword_5d4594_1062480 != nil {
		dword_5d4594_1062484 = dword_5d4594_1062480.field_4
	} else {
		dword_5d4594_1062484 = 0
	}
	dword_5d4594_1062480 = a1
	sub_4619F0()
	if dword_5d4594_1062480 == nil {
		nox_xxx_clientReportSecondaryWeapon_4BF010(nil)
		return
	}
	dword_5d4594_1062480.field_0.Field_32 = a1.field_4
	dword_5d4594_1062480.field_136 = 1
	nox_xxx_clientReportSecondaryWeapon_4BF010(dword_5d4594_1062480.field_0)
}
func sub_4615C0() *client.Drawable {
	v0 := int32(*memmap.PtrUint32(0x5D4594, 1063640))
	if v0 == 0 {
		v0 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Bow"))
		*memmap.PtrUint32(0x5D4594, 1063640) = uint32(v0)
	}
	if array_5D4594_1049872[8] == nil {
		return array_5D4594_1049872[7]
	}
	v1 := array_5D4594_1049872[8]
	for v1.Field_27 != uint32(v0) {
		v1 = v1.Next()
		if v1 == nil {
			return array_5D4594_1049872[7]
		}
	}
	return array_5D4594_1049872[8]
}
func sub_461600(a1 int32) *client.Drawable {
	for i := range array_5D4594_1049872 {
		v1 := &array_5D4594_1049872[i]
		result := *v1
		if *v1 != nil {
			for result.Field_27 != uint32(a1) {
				result = result.Next()
				if result == nil {
					goto LABEL_5
				}
			}
			return result
		}
	LABEL_5:
	}
	return nil
}
func nox_xxx_send2ServInvenFail_461630(a1 int16) int32 {
	var v3 [3]byte
	v3[0] = 241
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(a1)
	return nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&v3[0]), 3, 0)
}
func sub_461930() int32 {
	for i := range array_5D4594_1049872 {
		v0 := &array_5D4594_1049872[i]
		v1 := *v0
		if v1 != nil {
			for (v1.Flags28Val & 0x1001000) == 0 {
				v1 = v1.Next()
				if v1 == nil {
					goto LABEL_5
				}
			}
			return 1
		}
	LABEL_5:
	}
	return 0
}
func sub_461970(a1 int32, a2 int32) *int32 {
	var (
		v2 *int32
		v3 int32
	)
	if (nox_get_thing(a2).ObjClass & 0x4000000) != 0 {
		return nil
	}
	v2 = (*int32)(unsafe.Pointer(&nox_client_inventory_grid_1050020[0]))
	for {
		{
			v3 = 0
			var ptr *int32 = v2
			for {
				if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(ptr), 140))) != 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*ptr)), 108)) == uint32(a2) && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(ptr), 140))) < 0x20 {
					*(*int32)(unsafe.Add(unsafe.Pointer(ptr), 4*uintptr(int32(func() uint8 {
						p := ((*uint8)(unsafe.Add(unsafe.Pointer(ptr), 140)))
						x := *p
						*p++
						return x
					}())+1))) = a1
					return ptr
				}
				v3++
				ptr = (*int32)(unsafe.Add(unsafe.Pointer(ptr), 4*(NOX_INVENTORY_ROW_COUNT*(unsafe.Sizeof(nox_inventory_cell_t{})/4))))
				if v3 >= 4 {
					break
				}
			}
			v2 = (*int32)(unsafe.Add(unsafe.Pointer(v2), 4*(unsafe.Sizeof(nox_inventory_cell_t{})/4)))
		}
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(unsafe.Pointer(&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1]))) {
			break
		}
	}
	return nil
}
func sub_4619F0() *byte {
	var (
		v0     *byte
		result *byte
		v2     int32
		v3     int32
	)
	v0 = &nox_client_inventory_grid_1050020[0].field_140
	for {
		result = v0
		v2 = 4
		for {
			v3 = 0
			if int32(*result) > 0 {
				for {
					*(*uint32)(unsafe.Add(unsafe.Pointer(result), -int(4*1))) = 0
					v3++
					if v3 >= int32(*result) {
						break
					}
				}
			}
			result = (*byte)(unsafe.Add(unsafe.Pointer(result), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
			v2--
			if v2 == 0 {
				break
			}
		}
		v0 = (*byte)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(nox_inventory_cell_t{})))
		if int32(uintptr(unsafe.Pointer(v0))) > int32(uintptr(unsafe.Pointer(&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1].field_140))) {
			break
		}
	}
	return result
}
func sub_461B50() *uint8 {
	var (
		v0     int32
		result *uint8
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		v7     unsafe.Pointer
		v8     *nox_inventory_cell_t
		v9     *uint8
		v10    int32
		v11    int32
		v12    int32
		i      int32
		v14    int32
		v15    bool
		j      int32
		v17    int32
		v18    int32
		v19    *int32
		v20    *uint8
		v21    *nox_inventory_cell_t
		v22    int32
		v23    int32
		v24    int32
		v25    int32
		v26    *int32
		v27    int32
		v28    *uint8
		v29    *uint8
		v30    int32
	)
	v0 = 0
	result = (*uint8)(unsafe.Pointer(&nox_client_inventory_grid_1050020[0].field_136))
	v25 = 0
	v26 = (*int32)(unsafe.Pointer(&nox_client_inventory_grid_1050020[0].field_136))
LABEL_2:
	v2 = 0
	v24 = 0
	v21 = (*nox_inventory_cell_t)(unsafe.Add(unsafe.Pointer(result), -136))
	v20 = result
	v19 = (*int32)(unsafe.Add(unsafe.Pointer(result), 4))
	for {
		if int32(*(*uint8)(unsafe.Pointer(v19))) == 0 {
			v3 = v0
			v27 = v0
			if int32(uintptr(unsafe.Pointer(result))) < int32(uintptr(unsafe.Pointer(&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1].field_136))) {
			LABEL_5:
				if v3 == v0 {
					v4 = v2
					v22 = v2
				} else {
					v4 = 0
					v22 = 0
				}
				result = &nox_client_inventory_grid_1050020[v3+NOX_INVENTORY_ROW_COUNT*v4].field_140
				for int32(*result) == 0 {
					v4++
					result = (*uint8)(unsafe.Add(unsafe.Pointer(result), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
					v22 = v4
					if v4 >= 4 {
						v27 = func() int32 {
							p := &v3
							*p++
							return *p
						}()
						if v3 >= 20 {
							goto LABEL_38
						}
						goto LABEL_5
					}
				}
				v5 = v3 + NOX_INVENTORY_ROW_COUNT*v4
				var v6 int32 = v5
				v7 = unsafe.Pointer(nox_client_inventory_grid_1050020[v5].field_0)
				v8 = &nox_client_inventory_grid_1050020[v5]
				v29 = (*uint8)(unsafe.Pointer(&nox_client_inventory_grid_1050020[v5]))
				v30 = int32(*(*uint32)(unsafe.Add(v7, 108)))
				if (*(*uint32)(unsafe.Add(v7, 112)) & 0x4000000) == 0 {
					v9 = &nox_client_inventory_grid_1050020[0].field_140
					v23 = 0
					v28 = &nox_client_inventory_grid_1050020[0].field_140
					for {
						v10 = 0
						for int32(*v9) == 0 || int32(*v9) == 32 || *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v9), -int(4*35))))), 108)) != uint32(v30) || v10 == v4 && v23 == v27 {
							v10++
							v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
							if v10 >= 4 {
								goto LABEL_28
							}
						}
						v11 = v23 + NOX_INVENTORY_ROW_COUNT*v10
						v12 = int32(nox_client_inventory_grid_1050020[v11].field_140)
						for i = int32(nox_client_inventory_grid_1050020[v6].field_140); i > 0; v6 = v5 {
							if v12 == 32 {
								break
							}
							i--
							v14 = func() int32 {
								p := &v12
								x := *p
								*p++
								return x
							}() + v11
							*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(&nox_client_inventory_grid_1050020[0]), 4), (v14+v11*36)*4)) = *(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(&nox_client_inventory_grid_1050020[0]), 4), (i+v5+v5*36)*4))
							v4 = v22
						}
						nox_client_inventory_grid_1050020[v11].field_140 = uint8(int8(v12))
						if i <= 0 {
							nox_client_inventory_grid_1050020[v6].field_140 = 0
							nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(*(**uint64)(unsafe.Pointer(v29)))))
							v0 = v25
							*(*uint32)(unsafe.Pointer(v29)) = 0
							v2 = v24 - 1
							v21 = (*nox_inventory_cell_t)(unsafe.Add(unsafe.Pointer(v21), -int(4*(NOX_INVENTORY_ROW_COUNT*(unsafe.Sizeof(nox_inventory_cell_t{})/4)))))
							result = (*uint8)(unsafe.Pointer(v26))
							v19 = (*int32)(unsafe.Add(unsafe.Pointer(v19), -int(4*(NOX_INVENTORY_ROW_COUNT*(unsafe.Sizeof(nox_inventory_cell_t{})/4)))))
							v20 = (*uint8)(unsafe.Add(unsafe.Pointer(v20), -int(NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{}))))
							goto LABEL_35
						}
						nox_client_inventory_grid_1050020[v6].field_140 = uint8(int8(i))
					LABEL_28:
						v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v28), unsafe.Sizeof(nox_inventory_cell_t{})))
						v15 = int32(uintptr(unsafe.Add(unsafe.Pointer(v28), unsafe.Sizeof(nox_inventory_cell_t{})))) < int32(uintptr(unsafe.Pointer(&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1].field_140)))
						v23++
						v28 = (*uint8)(unsafe.Add(unsafe.Pointer(v28), unsafe.Sizeof(nox_inventory_cell_t{})))
						if v15 {
							continue
						}
						break
					}
					v2 = v24
					v8 = &nox_client_inventory_grid_1050020[v5]
				}
				v21.field_0 = v8.field_0
				if *(*uint32)(unsafe.Pointer(v20)) != 0 {
					dword_5d4594_1062480 = v21
				}
				result = (*uint8)(unsafe.Pointer(v26))
				nox_client_inventory_grid_1050020[v6].field_140 = 0
				*(*uint32)(unsafe.Pointer(v8)) = 0
				nox_client_inventory_grid_1050020[v6].field_132 = 0
				v0 = v25
				goto LABEL_35
			}
		LABEL_38:
			for j = v0; j < NOX_INVENTORY_ROW_COUNT-1; j++ {
				if j == v0 {
					v17 = v2
				} else {
					v17 = 0
				}
				v18 = 4 - v17
				result = (*uint8)(unsafe.Pointer(&nox_client_inventory_grid_1050020[j+NOX_INVENTORY_ROW_COUNT*v17].field_136))
				for {
					*(*uint32)(unsafe.Add(unsafe.Pointer(result), -int(4*1))) = 0
					*(*uint32)(unsafe.Pointer(result)) = 0
					result = (*uint8)(unsafe.Add(unsafe.Pointer(result), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
					v18--
					if v18 == 0 {
						break
					}
				}
			}
			return result
		}
	LABEL_35:
		v24 = func() int32 {
			p := &v2
			*p++
			return *p
		}()
		v19 = (*int32)(unsafe.Add(unsafe.Pointer(v19), 4*(NOX_INVENTORY_ROW_COUNT*(unsafe.Sizeof(nox_inventory_cell_t{})/4))))
		v20 = (*uint8)(unsafe.Add(unsafe.Pointer(v20), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
		v21 = (*nox_inventory_cell_t)(unsafe.Add(unsafe.Pointer(v21), 4*(NOX_INVENTORY_ROW_COUNT*(unsafe.Sizeof(nox_inventory_cell_t{})/4))))
		if v2 >= 4 {
			result = (*uint8)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(nox_inventory_cell_t{})))
			v25 = func() int32 {
				p := &v0
				*p++
				return *p
			}()
			v26 = (*int32)(unsafe.Pointer(result))
			if int32(uintptr(unsafe.Pointer(result))) >= int32(uintptr(unsafe.Pointer(&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1].field_136))) {
				return result
			}
			goto LABEL_2
		}
	}
}
func sub_461E60(a1 ***uint64) **uint64 {
	var (
		v1     **uint64
		v2     int32
		v3     int32
		result **uint64
	)
	v1 = *a1
	v2 = int32(uintptr(unsafe.Pointer(*(***uint64)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((**uint64)(nil))*1)))))
	if v2 < int32(*(*uint8)(unsafe.Add(unsafe.Pointer(*a1), 140)))-1 {
		v3 = v2*4 + 4
		for {
			v2++
			*(**uint64)(unsafe.Add(unsafe.Pointer(v1), v3)) = *(**uint64)(unsafe.Add(unsafe.Add(unsafe.Pointer(v1), v3), 4))
			v1 = *a1
			v3 += 4
			if v2 >= int32(*(*uint8)(unsafe.Add(unsafe.Pointer(*a1), 140)))-1 {
				break
			}
		}
	}
	if int32(func() uint8 {
		p := ((*uint8)(unsafe.Add(unsafe.Pointer(*a1), 140)))
		*p--
		return *p
	}()) == 0 {
		nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(**a1)))
		**a1 = nil
	}
	result = (**uint64)(unsafe.Pointer(*(**uint64)(unsafe.Add(unsafe.Pointer(*a1), unsafe.Sizeof((*uint64)(nil))*34))))
	if result == nil {
		return result
	}
	nox_xxx_clientSetAltWeapon_461550(nil)
	result = *a1
	*(**uint64)(unsafe.Add(unsafe.Pointer(*a1), unsafe.Sizeof((*uint64)(nil))*34)) = nil
	return result
}
func sub_461EF0(a1 int32) **nox_inventory_cell_t {
	for row := 0; row < NOX_INVENTORY_ROW_COUNT; row++ {
		for col := 0; col < NOX_INVENTORY_COL_COUNT; col++ {
			cell := &nox_client_inventory_grid_1050020[row+NOX_INVENTORY_ROW_COUNT*col]
			field140_val := int(int32(cell.field_140))
			if field140_val <= 0 {
				continue
			}
			p_maybe_stack_items := &cell.field_4
			for maybe_stack_idx := 0; maybe_stack_idx < field140_val; maybe_stack_idx++ {
				if *(*uint32)(unsafe.Add(unsafe.Pointer(p_maybe_stack_items), 4*uintptr(maybe_stack_idx))) == uint32(a1) {
					*memmap.PtrUint32(0x5D4594, 1049792) = uint32(maybe_stack_idx)
					*memmap.PtrPtr(0x5D4594, 1049788) = unsafe.Pointer(cell)
					return (**nox_inventory_cell_t)(memmap.PtrOff(0x5D4594, 1049788))
				}
			}
		}
	}
	return nil
}
func sub_461F90(a1 int32) *client.Drawable {
	for i := range array_5D4594_1049872 {
		v2 := &array_5D4594_1049872[i]
		v3 := *v2
		if *(*uint32)(unsafe.Pointer(v2)) != 0 {
			for v3.Field_32 != uint32(a1) {
				v3 = v3.Next()
				if v3 == nil {
					goto LABEL_5
				}
			}
			v5 := v3.Field_93
			if v5 != nil {
				v5.NextPtr = v3.NextPtr
			} else {
				array_5D4594_1049872[i] = v3.NextPtr
			}
			v6 := v3.NextPtr
			if v6 != nil {
				v6.Field_93 = v3.Field_93
			}
			v7 := v3.Flags28()
			if v7&0x1000 != 0 || nox_xxx_ammoCheck_415880(uint16(v3.Field_27)) == 2 || nox_xxx_ammoCheck_415880(uint16(v3.Field_27)) == 128 {
				sub_470D70()
			}
			return v3
		}
	LABEL_5:
	}
	return nil
}
func sub_4622E0(a1 unsafe.Pointer) int32 {
	var (
		v1     int32
		result int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 112)))
	if *(*uint32)(unsafe.Add(a1, 112))&0x1000000 != 0 && int32(*(*uint8)(unsafe.Add(a1, 116)))&2 != 0 {
		return 0
	}
	if !((uint32(v1)&0x2000000) == 0 || (func() bool {
		result = 1
		return (int32(*(*uint8)(unsafe.Add(a1, 116))) & 1) == 0
	}())) {
		return result
	}
	if uint32(v1)&0x2000000 != 0 {
		if *(*uint32)(unsafe.Add(a1, 116))&0x144 != 0 {
			return 2
		}
		if int32(*(*uint8)(unsafe.Add(a1, 116)))&0x90 != 0 {
			return 3
		}
		if int32(*(*uint8)(unsafe.Add(a1, 116)))&0x20 != 0 {
			return 4
		}
		if int32(*(*uint8)(unsafe.Add(a1, 116)))&2 != 0 {
			return 8
		}
		if int32(*(*uint8)(unsafe.Add(a1, 116)))&8 != 0 {
			return 5
		}
	}
	if *(*uint32)(unsafe.Add(a1, 112))&0x1000000 != 0 {
		if int32(*(*uint8)(unsafe.Add(a1, 116)))&4 != 0 {
			return 8
		}
		return 7
	}
	if v1&0x1000 != 0 {
		return 7
	}
	result = 9
	return result
}
func nox_xxx_clientEquip_4623B0(a1 *client.Drawable) int32 {
	var v3 [3]byte
	v3[0] = 117
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeCli_578B00(a1))
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, &v3[0], 3)
}
func sub_4623E0(a1 *client.Drawable, a2 int32) {
	var (
		v2     int32
		result *client.Drawable
		v4     int32
		v5     *client.Drawable
	)
	if (a1.Flags28Val & 0x2000000) == 0 {
		goto LABEL_19
	}
	v2 = int32(a1.Flags29Val)
	if v2&0x140 != 0 {
		result = array_5D4594_1049872[a2]
		if result == nil {
			goto LABEL_19
		}
		for result.NextPtr != nil {
			result = result.NextPtr
		}
		if result == nil {
			goto LABEL_19
		}
		if v2&0x40 != 0 {
			if result.Flags28Val&0x2000000 != 0 {
				v4 = int32(result.Flags29Val)
				if v4&0x100 != 0 {
					result = result.Field_93
				}
			}
		}
	} else {
		if (v2 & 0x10) == 0 {
			goto LABEL_19
		}
		result = array_5D4594_1049872[a2]
		if result == nil {
			goto LABEL_19
		}
		for result.NextPtr != nil {
			result = result.NextPtr
		}
	}
	if result != nil {
		v5 = result.NextPtr
		if v5 != nil {
			v5.Field_93 = a1
		}
		a1.NextPtr = result.NextPtr
		result.NextPtr = a1
		a1.Field_93 = result
		return
	}
LABEL_19:
	a1.Field_93 = nil
	a1.NextPtr = array_5D4594_1049872[a2]
	result = array_5D4594_1049872[a2]
	if result != nil {
		result.Field_93 = a1
	}
	array_5D4594_1049872[a2] = a1
}
func sub_4624D0(a1 int32) {
	v2 := sub_461F90(a1)
	if v2 == nil {
		return
	}
	defer nox_xxx_spriteDelete_45A4B0(v2)

	v3 := sub_461EF0(a1)
	v4 := v3
	if v3 == nil {
		return
	}
	(*v3).field_132 = 0
	if dword_5d4594_1062492 != v2 {
		if nox_xxx_ammoCheck_415880(uint16(v2.Field_27))&0xC != 0 && dword_5d4594_1062480 != nil && nox_xxx_ammoCheck_415880(uint16(dword_5d4594_1062480.field_0.Field_27)) == 2 {
			dword_5d4594_1062480.field_136 = 0
			nox_xxx_clientSetAltWeapon_461550(nil)
		}
		return
	}
	dword_5d4594_1062492 = nil
	if dword_5d4594_1062480 != nil {
		dword_5d4594_1062496 = v2.Field_32
		dword_5d4594_1062480.field_0.Field_32 = dword_5d4594_1062480.field_4
		nox_xxx_clientEquip_4623B0(dword_5d4594_1062480.field_0)
	} else {
		nox_xxx_clientSetAltWeapon_461550(*v3)
		(*v4).field_136 = 1
	}
}
func sub_4625D0(win *gui.Window, draw *gui.WindowData) int {
	var (
		v3 int32
		v4 int32
		v5 int32
		v6 int32
	)
	if dword_5d4594_1049864 == 5 {
		return 1
	}
	nox_client_wndGetPosition_46AA60(win, &v3, &v4)
	nox_window_get_size(win, &v5, &v6)
	if v4+v6 <= 0 {
		return 1
	}
	nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
	if dword_5d4594_1062480 != nil && dword_5d4594_1062480.field_0 != nil {
		dr := dword_5d4594_1062480.field_0
		dr.PosVec.X = int(uint32(v3 + v5/2))
		dr.PosVec.Y = int(uint32(v4 + v6/2))
		dr.DrawFunc.Get()((*noxrender.Viewport)(memmap.PtrOff(0x5D4594, 1049732)), dr)
	}
	v2 := sub_42E8E0(35, 1)
	if v2 != nil {
		nox_xxx_drawString_43F6E0(dword_5d4594_1063636, v2, v3+22, v4+41)
	}
	return 1
}
func sub_4626C0(a1 unsafe.Pointer) float64 {
	var (
		v1 int32
		i  unsafe.Pointer
		v3 unsafe.Pointer
	)
	if a1 == nil || (*(*uint32)(unsafe.Add(a1, 112))&0x13001000) == 0 {
		return 0.0
	}
	v1 = 2
	for i = unsafe.Add(a1, 440); ; i = unsafe.Add(i, 4*1) {
		v3 = *(*unsafe.Pointer)(i)
		if v3 != nil {
			if *(*unsafe.Pointer)(unsafe.Add(v3, 52)) == ccall.FuncAddr(nox_xxx_lightngEffect_4E06F0) {
				break
			}
		}
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= 4 {
			return 0.0
		}
	}
	return float64(*(*float32)(unsafe.Add(v3, 56)))
}
func sub_462700(a1 unsafe.Pointer) float64 {
	var (
		v1 int32
		i  unsafe.Pointer
		v3 unsafe.Pointer
	)
	if a1 == nil || (*(*uint32)(unsafe.Add(a1, 112))&0x13001000) == 0 {
		return 0.0
	}
	v1 = 2
	for i = unsafe.Add(a1, 440); ; i = unsafe.Add(i, 4*1) {
		v3 = *(*unsafe.Pointer)(i)
		if v3 != nil {
			if *(*unsafe.Pointer)(unsafe.Add(v3, 52)) == ccall.FuncAddr(nox_xxx_fireEffect_4E0550) {
				break
			}
		}
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= 4 {
			return 0.0
		}
	}
	return float64(*(*float32)(unsafe.Add(v3, 56)))
}
func sub_463370(a1p *gui.Window, pos *nox_point, a3 *uint32) {
	var a1, v7 int32
	nox_client_wndGetPosition_46AA60(a1p, &a1, &v7)
	v5 := a3
	*a3 = uint32(pos.x) - uint32(a1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) = uint32(pos.y - v7)
}
func sub_4633B0(a1 unsafe.Pointer, a2 *float32, a3 *float32) {
	*a2 = float32(*(*uint16)(unsafe.Add(a1, 292)))
	*a3 = float32(*(*uint16)(unsafe.Add(a1, 294)))
	if *(*uint32)(unsafe.Add(a1, 112))&0x13001000 != 0 {
		v4 := *(*unsafe.Pointer)(unsafe.Add(a1, 436))
		if v4 != nil {
			if *(*unsafe.Pointer)(unsafe.Add(v4, 76)) == ccall.FuncAddr(sub_4E0380) {
				v5 := float32(float64(*a2) * float64(*(*float32)(unsafe.Add(v4, 80))))
				*a2 = v5
				v6 := float32(float64(*a3) * float64(*(*float32)(unsafe.Add(v4, 80))))
				result := int32(v6)
				*a3 = float32(result)
			}
		}
	}
}
func sub_463420(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1050012) = uint32(a1)
	return result
}
func nox_xxx_inventoryDrawAllMB_463430(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1  = win.C()
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v7  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v16 int2
		v17 [16]wchar2_t
	)
	v1 = int32(dword_587000_136184)
	nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, 396)))), 0, v1)
	nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &v16.field_0, &v16.field_4)
	nox_xxx_guiFontHeightMB_43F320(nil)
	v2 = 0
	v3 = v16.field_0 + 10
	v4 = v16.field_4 + 234
	for {
		if uint32(1<<v2)&*memmap.PtrUint32(0x5D4594, 1062540) != 0 && v2 != 31 && v2 != 30 {
			v5 := nox_xxx_getEnchantSpell_424920(v2)
			v6 := nox_xxx_spellIcon_424A90(v5)
			nox_client_drawImageAt_47D2C0(v6, v3, v4)
			v3 += 35
		}
		v2++
		if v2 >= 32 {
			break
		}
	}
	v7 = 0
	for {
		if int32(*memmap.PtrUint8(0x5D4594, 1062536))&int32(uint8(int8(1<<v7))) != 0 {
			v8 := sub_413420(1 << v7)
			nox_client_drawImageAt_47D2C0(v8, v3, v4)
			v3 += 35
		}
		v7++
		if v7 >= 6 {
			break
		}
	}
	if noxflags.HasGame(4096) && dword_5d4594_1050008 != nil {
		v4 += 5
		v3 += 6
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(dword_5d4594_1050008.Field_24, 4)) + (gameFrame()%uint32(*(*uint8)(unsafe.Add(dword_5d4594_1050008.Field_24, 8))))*4)))), v3-58, v4-53)
		nox_swprintf(&v17[0], internWStr("X %d"), *memmap.PtrUint32(0x5D4594, 1050012))
		nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x852978, 0))
		nox_xxx_drawString_43F6E0(dword_5d4594_1063636, &v17[0], v3+20, v4+9)
		*memmap.PtrUint32(0x5D4594, 1049812) = uint32(v3 - 30)
		*memmap.PtrUint32(0x5D4594, 1049816) = uint32(v4 - 20)
		*memmap.PtrUint32(0x5D4594, 1049820) = uint32(v3 + 30)
		*memmap.PtrUint32(0x5D4594, 1049824) = uint32(v4 + 20)
	}
	if noxflags.HasGame(4096) && sub_4BFD30() != 0 {
		v9 = v4 + 5
		v10 = v3 + 66
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1050004)), v10-64, v9-58)
		*memmap.PtrUint32(0x5D4594, 1049828) = uint32(v10 - 30)
		*memmap.PtrUint32(0x5D4594, 1049832) = uint32(v9 - 20)
		*memmap.PtrUint32(0x5D4594, 1049836) = uint32(v10 + 30)
		*memmap.PtrUint32(0x5D4594, 1049840) = uint32(v9 + 20)
	}
	if int32(*memmap.PtrUint8(0x5D4594, 1049868)) != 0 {
		v11 = v16.field_4 + 13
		v12 = v16.field_0 + 254
		if v16.field_4+163 > 0 {
			nox_xxx_wndDraw_49F7F0()
			nox_client_copyRect_49F6F0(v12, v11, 260, 150)
			if int32(*memmap.PtrUint8(0x5D4594, 1049869)) != 0 {
				if int32(*memmap.PtrUint8(0x5D4594, 1049869)) == 1 {
					nox_xxx_guiDrawJournal_469D40(v12, v11, dword_5d4594_1062512)
				}
			} else {
				nox_xxx_guiDrawInventoryTray_4643B0(v12, v11)
			}
			sub_49F860()
		}
		if dword_5d4594_1049864 == 5 {
			sub_4627F0((*uint32)(unsafe.Pointer(&v16)))
			nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1049912)), v16.field_0, v16.field_4)
		} else {
			if int32(*memmap.PtrUint8(0x5D4594, 1049870)) != 0 {
				if int32(*memmap.PtrUint8(0x5D4594, 1049870)) == 1 {
					nox_client_makePlayerStatsDlg_463880(&v16.field_0)
					nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1049912)), v16.field_0, v16.field_4)
				}
			} else {
				sub_4BF7E0((*uint32)(unsafe.Pointer(&v16)))
				nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1049908)), v16.field_0, v16.field_4)
			}
			nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
			nox_xxx_drawStringWrap_43FAF0(nil, (*wchar2_t)(memmap.PtrOff(0x5D4594, 1062588)), v16.field_0+13, v16.field_4+17, 196, 0)
		}
	}
	if int32(*memmap.PtrUint8(0x5D4594, 1049868)) == 1 {
		v14 = int32(dword_587000_136184)
		dword_587000_136184 = uint32(v14 + 64)
		if v14+64 > 0 {
			dword_587000_136184 = 0
			*memmap.PtrUint8(0x5D4594, 1049868) = 2
		}
	} else if int32(*memmap.PtrUint8(0x5D4594, 1049868)) == 3 {
		v13 = int32(dword_587000_136184)
		dword_587000_136184 = uint32(v13 - 32)
		if v13-32 <= -225 {
			dword_587000_136184 = 4294967071
			*memmap.PtrUint8(0x5D4594, 1049868) = 0
			if int32(*memmap.PtrUint8(0x5D4594, 1049869)) != 0 {
				if int32(*memmap.PtrUint8(0x5D4594, 1049869)) == 1 {
					dword_5d4594_1062520 = dword_5d4594_1062512
				}
			} else {
				dword_5d4594_1062516 = dword_5d4594_1062512
			}
			*memmap.PtrUint8(0x5D4594, 1049869) = 0
			dword_5d4594_1062512 = dword_5d4594_1062516
			nox_window_call_field_94_fnc(dword_5d4594_1062508, 16395, 0, 850)
			nox_window_call_field_94_fnc(dword_5d4594_1062508, 16394, uintptr(*(*int32)(unsafe.Add(dword_5d4594_1062508.WidgetData, 4))-dword_5d4594_1062512), 0)
			nox_xxx_wndSetIcon_46AE60(dword_5d4594_1062528, nil)
			sub_46AEC0(dword_5d4594_1062528, dword_5d4594_1049976)
			nox_xxx_wndSetID_46B080(dword_5d4594_1062528, 9105)
			*memmap.PtrUint8(0x5D4594, 1049870) = 0
			nox_xxx_wndSetIcon_46AE60(dword_5d4594_1062524, dword_5d4594_1049992)
			sub_46AEC0(dword_5d4594_1062524, dword_5d4594_1049996)
			nox_xxx_wndSetID_46B080(dword_5d4594_1062524, 9107)
			nox_window_set_hidden(dword_5d4594_1062468, 0)
		}
	}
	if sub_467C80() != 0 && nox_xxx_playerAnimCheck_4372B0() != 0 {
		sub_467C10()
	}
	return 1
}
func nox_xxx_guiDrawInventoryTray_4643B0(a1 int32, a2 int32) int32 {
	var (
		v2          int32
		v3          int32
		v4          *uint8
		v5          int32
		v6          int32
		v7          unsafe.Pointer
		v8          float64
		v9          float64
		v10         int32
		v11         noxrender.ImageHandle
		v12         unsafe.Pointer
		v13         int16
		v14         int16
		v15         int16
		v16         bool
		result      int32
		v18         int32
		v19         int32
		v20         int32
		v21         int32
		v22         int32
		v23         *uint8
		v24         int32
		v25         int32
		v26         int32
		v27         int32
		WideCharStr [16]wchar2_t
		v29         *uint8
	)
	v2 = a2
	nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1049928)), a1, a2)
	nox_itow(dword_5d4594_1062552, &WideCharStr[0], 10)
	nox_xxx_drawSetTextColor_434390(int32(nox_color_yellow_2589772))
	nox_xxx_drawGetStringSize_43F840(dword_5d4594_1063636, &WideCharStr[0], &v24, nil, 0)
	nox_xxx_drawString_43F6E0(dword_5d4594_1063636, &WideCharStr[0], a1-v24+43, a2+36)
	if dword_5d4594_1049864 == 5 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1049932)), a1, a2+50)
	}
	if sub_473670() != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1049936)), a1, a2+100)
	}
	v3 = a1 + 60
	v4 = &nox_client_inventory_grid_1050020[0].field_140
	v27 = a1 + 60
	v5 = a2 - dword_5d4594_1062512
	v20 = 0
	v23 = &nox_client_inventory_grid_1050020[0].field_140
	for {
		if v5 > v2-50 {
			v6 = v3
			nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, uintptr((v20%3)*4)+1049916)), v3, v5)
			v29 = v4
			v22 = 4
			for {
				if int32(*v4) != 0 {
					v7 = *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), -int(4*35)))
					if v7 != nil {
						v21 = 0
						nox_client_drawEnableAlpha_434560(1)
						nox_client_drawSetAlpha_434580(0x40)
						v8 = float64(*(*uint16)(unsafe.Add(v7, 292)))
						v25 = int32(*(*uint16)(unsafe.Add(v7, 294)))
						v9 = float64(v25)
						if v8 >= v9**mem_getDoublePtr(0x581450, 9608) {
							if v8 >= v9*qword_581450_9544 {
								goto LABEL_16
							}
							v10 = int32(nox_color_yellow_2589772)
						} else {
							v10 = int32(*memmap.PtrUint32(0x85B3FC, 940))
						}
						if uint32(v10) != 0x80000000 {
							nox_client_drawSetColor_434460(v10)
							nox_client_drawRectFilledOpaque_49CE30(v6, v5, 50, 50)
						}
					LABEL_16:
						nox_client_drawSetAlpha_434580(0x80)
						if *(*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*2))) != 0 {
							v11 = noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, 1049964))
							v19 = v5
							v18 = v6
						} else {
							if *(*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*1))) != 0 {
								nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1049968)), v6, v5)
								goto LABEL_27
							}
							if *(*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*34))) != dword_5d4594_1062488 {
								goto LABEL_27
							}
							if dword_5d4594_1062480 == nil {
								goto LABEL_27
							}
							v12 = dword_5d4594_1062480.field_0.C()
							if v12 == nil || (*(*uint32)(unsafe.Add(v12, 112))&0x1000000) == 0 || (int32(*(*uint8)(unsafe.Add(v12, 116)))&0xC) == 0 {
								goto LABEL_27
							}
							v11 = noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, 1049968))
							v19 = v5
							v18 = v6
						}
						nox_client_drawImageAt_47D2C0(v11, v18, v19)
					LABEL_27:
						nox_client_drawEnableAlpha_434560(0)
						*(*uint32)(unsafe.Add(v7, 16)) = uint32(v5 + 25)
						*(*uint32)(unsafe.Add(v7, 12)) = uint32(v6 + 25)
						ccall.AsFunc[client.ObjectDrawFunc](*(*unsafe.Pointer)(unsafe.Add(v7, 300)))((*noxrender.Viewport)(memmap.PtrOff(0x5D4594, 1049732)), AsDrawableP(v7))
						if dword_5d4594_1049864 == 6 {
							if *(*uint32)(unsafe.Add(v7, 112))&0x13001000 != 0 {
								if (*(*uint32)(unsafe.Add(v7, 112)) & 0x1000) == 4096 {
									v13 = int16(*(*uint16)(unsafe.Add(v7, 450)))
									if int32(*(*uint16)(unsafe.Add(v7, 448))) < int32(v13) {
										if int32(v13) != 0 {
											v21 = 1
										}
									}
								}
							}
							v14 = int16(*(*uint16)(unsafe.Add(v7, 294)))
							if (int32(*(*uint16)(unsafe.Add(v7, 292))) == int32(v14) || int32(v14) == 0) && v21 == 0 {
								nox_client_drawRectFilledAlpha_49CF10(v6, v5, 50, 50)
							}
						}
						if int32(*v29) > 1 {
							nox_swprintf(&WideCharStr[0], internWStr("%d"), *v29)
							nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
							nox_xxx_drawString_43F6E0(dword_5d4594_1063636, &WideCharStr[0], v6+6, v5+6)
						}
						if *(*uint32)(unsafe.Add(v7, 112))&0x13001000 != 0 {
							v15 = int16(*(*uint16)(unsafe.Add(v7, 448)))
							if int32(v15) >= 0 {
								nox_swprintf(&WideCharStr[0], internWStr("%d"), v15)
								nox_xxx_drawSetTextColor_434390(int32(nox_color_blue_2650684))
								nox_xxx_drawGetStringSize_43F840(dword_5d4594_1063636, &WideCharStr[0], &v26, nil, 0)
								nox_xxx_drawString_43F6E0(dword_5d4594_1063636, &WideCharStr[0], v6-v26+44, v5+6)
							}
						}
						v4 = v29
						goto LABEL_43
					}
				}
			LABEL_43:
				v6 += 50
				v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
				v16 = v22 == 1
				v29 = v4
				v22--
				if v16 {
					v2 = a2
					v4 = v23
					v3 = v27
					goto LABEL_45
				}
			}
		}
	LABEL_45:
		v5 += 50
		result = v2 + 150
		if v5 > v2+150 {
			break
		}
		v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(nox_inventory_cell_t{})))
		v20++
		v23 = v4
		if int32(uintptr(unsafe.Pointer(v4))) >= int32(uintptr(unsafe.Pointer(&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1].field_140))) {
			break
		}
	}
	return result
}
func sub_464770(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	var (
		v3 int32
		v4 *client.Drawable
		v5 int32
		v6 *client.Drawable
	)
	if dword_5d4594_1049864 == 6 {
		return 1
	}
	switch a2 {
	case 5, 8:
		return 1
	case 6:
		if *memmap.PtrUint32(0x5D4594, 1049848) == 0 {
			goto LABEL_25
		}
		if !nox_xxx_wndPointInWnd_46AAB0(dword_5d4594_1062456, int32(uint16(a3)), int32(a3>>16)) {
			goto LABEL_22
		}
		if dword_5d4594_1049856 != 0 {
			if *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 112))&0x1001000 != 0 {
				if dword_5d4594_1062480 != nil {
					nox_client_invAlterWeapon_4672C0()
				} else {
					dword_5d4594_1062492 = AsDrawableP(*memmap.PtrPtr(0x5D4594, 1049848))
					nox_xxx_clientDequip_464B70(dword_5d4594_1062492)
				}
			}
		} else if (*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 112))&0x1001000) == 0 || nox_client_inventory_grid_1050020[dword_5d4594_1049800_inventory_click_row_index+NOX_INVENTORY_ROW_COUNT*dword_5d4594_1049796_inventory_click_column_index].field_132 != 0 {
			sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), dword_5d4594_1049796_inventory_click_column_index, dword_5d4594_1049800_inventory_click_row_index)
		} else {
			if nox_xxx_ammoCheck_415880(uint16(uintptr(unsafe.Pointer(*(**byte)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 108)))))) == 2 {
				v3 = sub_415840(4)
				v4 = sub_461600(v3)
				v5 = sub_415840(8)
				v6 = sub_461600(v5)
				if v4 == nil && v6 == nil {
					sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), dword_5d4594_1049796_inventory_click_column_index, dword_5d4594_1049800_inventory_click_row_index)
					nox_xxx_cursorResetDraggedItem_4776A0()
					if dword_5d4594_1049856 == 0 {
						nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(*(**uint64)(memmap.PtrOff(0x5D4594, 1049848)))))
					}
					*memmap.PtrUint32(0x5D4594, 1049848) = 0
					dword_5d4594_1049856 = 0
					return 1
				}
			}
			if dword_5d4594_1062480 != nil {
				dword_5d4594_1062480.field_136 = 0
			}
			sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), dword_5d4594_1049796_inventory_click_column_index, dword_5d4594_1049800_inventory_click_row_index)
			nox_xxx_clientSetAltWeapon_461550(&nox_client_inventory_grid_1050020[dword_5d4594_1049800_inventory_click_row_index+NOX_INVENTORY_ROW_COUNT*dword_5d4594_1049796_inventory_click_column_index])
			dword_5d4594_1062480.field_136 = 1
		}
	LABEL_22:
		nox_xxx_cursorResetDraggedItem_4776A0()
		if dword_5d4594_1049856 == 0 {
			nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(*(**uint64)(memmap.PtrOff(0x5D4594, 1049848)))))
		}
		*memmap.PtrUint32(0x5D4594, 1049848) = 0
		dword_5d4594_1049856 = 0
	LABEL_25:
		nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1062456)
		return 1
	case 7:
		if dword_5d4594_1062480 != nil {
			nox_client_invAlterWeapon_4672C0()
		}
		return 1
	default:
		return 0
	}
}
func sub_464B40(a1 int32, a2 int32) int32 {
	return bool2int32(a1 >= 0 && a1 < 4 && a2 >= 0 && a2 < 21)
}
func nox_xxx_clientDequip_464B70(a1 *client.Drawable) int32 {
	var v3 [3]byte
	v3[0] = 118
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeCli_578B00(a1))
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, &v3[0], 3)
}
func nox_xxx_XorEaxEaxSub_464BA0(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	return 0
}
func nox_xxx_inventoryWndProc_464BB0(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	return uintptr(bool2int(a2 != 8 && a2 != 12 && a2 != 16))
}
func nox_xxx_trade_4657B0(a1 int16) int32 {
	var v2 [4]byte
	v2[0] = 201
	v2[1] = 30
	*(*uint16)(unsafe.Pointer(&v2[2])) = uint16(a1)
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, &v2[0], 4)
}
func nox_xxx_clientTradeMB_4657E0(a1 *int2) {
	if nox_xxx_pointInRect_4281F0(a1, (*int4)(memmap.PtrOff(0x587000, 136352))) != 0 {
		var (
			i = (a1.field_4+dword_5d4594_1062512-13)/50 + NOX_INVENTORY_ROW_COUNT*((a1.field_0-314)/50)
			n = nox_client_inventory_grid_1050020[i].field_140
		)
		if n != 0 {
			nox_xxx_clientTrade_465870(int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(&nox_client_inventory_grid_1050020[i]), int32(n)*4)))))
		}
	}
}
func nox_xxx_clientTrade_465870(a1 int16) int32 {
	var v2 [4]byte
	v2[0] = 201
	v2[1] = 28
	*(*uint16)(unsafe.Pointer(&v2[2])) = uint16(a1)
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, &v2[0], 4)
}
func sub_4658A0(a1 int32, a2 *int2) {
	if int32(*memmap.PtrUint8(0x5D4594, 1049868)) == 2 {
		if nox_xxx_pointInRect_4281F0(a2, (*int4)(memmap.PtrOff(0x587000, 136336))) != 0 {
			*memmap.PtrPtr(0x5D4594, 1049848) = array_5D4594_1049872[sub_465990((*uint32)(unsafe.Pointer(a2)))].C()
			dword_5d4594_1049856 = 1
		} else {
			dword_5d4594_1049856 = 0
			if nox_xxx_pointInRect_4281F0(a2, (*int4)(memmap.PtrOff(0x587000, 136368))) != 0 {
				if (a2.field_4-13)/50 == 2 {
					nox_client_toggleMap_473610()
				}
			} else if nox_xxx_pointInRect_4281F0(a2, (*int4)(memmap.PtrOff(0x587000, 136352))) != 0 {
				dword_5d4594_1049796_inventory_click_column_index = (a2.field_0 - 314) / 50
				dword_5d4594_1049800_inventory_click_row_index = (a2.field_4 + dword_5d4594_1062512 - 13) / 50
				if sub_464B40(dword_5d4594_1049796_inventory_click_column_index, dword_5d4594_1049800_inventory_click_row_index) != 0 {
					nox_xxx_cliInventorySpriteUpd_465A30()
				}
			}
		}
	}
}
func sub_465990(a1 *uint32) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
		v5 *client.Drawable
		v6 int2
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - 15)
	v6.field_0 = int32(*a1 - 11)
	v6.field_4 = v1
	v2 = 0
	for {
		v3 = nox_xxx_pointInRect_4281F0(&v6, (*int4)(memmap.PtrOff(0x587000, uintptr(v2*16)+136192)))
		if v3 == 0 {
			goto LABEL_6
		}
		if v2 == 6 {
			break
		}
		if v2 != 0 {
			return v2
		}
		if array_5D4594_1049872[0] != nil {
			return 0
		}
	LABEL_6:
		if func() int32 {
			p := &v2
			*p++
			return *p
		}() >= 9 {
			return -1
		}
	}
	v5 = array_5D4594_1049872[8]
	if array_5D4594_1049872[8] == nil {
		return 5
	}
	for (v5.Flags28Val&0x2000000) == 0 || (int32(v5.Flags29Val)&2) == 0 {
		v5 = v5.Next()
		if v5 == nil {
			return 5
		}
	}
	return 8
}
func nox_xxx_clientDrop_465BE0(a1 *int2) int32 {
	var (
		result int32
		v2     int16
		v3     [7]byte
	)
	result = int32(*memmap.PtrUint32(0x5D4594, 1049848))
	if *memmap.PtrUint32(0x5D4594, 1049848) == 0 {
		return result
	}
	v3[0] = 114
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeCli_578B00(AsDrawableP(*memmap.PtrPtr(0x5D4594, 1049848))))
	v2 = int16(a1.field_4)
	*(*uint16)(unsafe.Pointer(&v3[3])) = uint16(int16(a1.field_0))
	*(*uint16)(unsafe.Pointer(&v3[5])) = uint16(v2)
	result = nox_netlist_addToMsgListCli_40EBC0(31, 0, &v3[0], 7)
	return result
}
func nox_xxx_clientKeyEquip_465C30(a1 int32, a2 int32) int32 {
	dword_5d4594_1049796_inventory_click_column_index = a1
	dword_5d4594_1049800_inventory_click_row_index = a2
	nox_xxx_cliInventorySpriteUpd_465A30()
	nox_xxx_clientEquip_4623B0(AsDrawableP(*memmap.PtrPtr(0x5D4594, 1049848)))
	return sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), a1, a2)
}
func nox_xxx_clientUse_465C70(a1p *client.Drawable) {
	if a1p != nil {
		var a1 [3]byte
		a1[0] = 116
		*(*uint16)(unsafe.Add(unsafe.Pointer(&a1), 1)) = uint16(nox_xxx_netGetUnitCodeCli_578B00(a1p))
		nox_netlist_addToMsgListCli_40EBC0(31, 0, &a1[0], 3)
	}
}
func sub_465CA0() int32 {
	nox_window_set_hidden(dword_5d4594_1062476, 0)
	dword_5d4594_1049864 = 5
	nox_client_setCursorType_477610(6)
	return nox_xxx_wndSetCaptureMain_46ADC0(dword_5d4594_1062456)
}
func sub_465CD0(a1 unsafe.Pointer, a2 int32, a3 uint32, a4 int32, a5 uint32) {
	var (
		v5 **nox_inventory_cell_t
		v6 int32
		v7 int2
	)
	v4 := a4
	if a4 != 0 {
		sub_473970((*int2)(a1), &v7)
		v5 = sub_461EF0(a2)
		if v5 != nil {
			v6 = 4
			for {
				*memmap.PtrUint32(0x5D4594, 1049848) = **(**uint32)(unsafe.Pointer(v5))
				*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 128)) = *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v5)) + uint32(v6))))
				if sub_4C12C0() == 0 {
					nox_xxx_clientDrop_465BE0(&v7)
				}
				v6 += 4
				v4--
				*memmap.PtrUint32(0x5D4594, 1049848) = 0
				if v4 == 0 {
					break
				}
			}
		}
	}
}
func sub_465D50_draw(a1p unsafe.Pointer) int32 {
	var a1, v4 int32
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(a1p, 396)))), &v4, &a1)
	v2 := sub_4615C0()
	if v2 != nil {
		v2.PosVec.X = int(uint32(v4 + 51))
		v2.PosVec.Y = int(uint32(a1 + 81))
		v2.DrawFunc.Get()((*noxrender.Viewport)(memmap.PtrOff(0x5D4594, 1049732)), v2)
	} else {
		if dword_5d4594_1062496 == 0 && dword_5d4594_1062492 == nil {
			nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1050000)), v4+21, a1+50)
		}
	}
	return 1
}
func sub_465DE0(a1 int32) int32 {
	dword_5d4594_1049844 = uint32(a1)
	return nox_xxx_j_inventoryNameSignInit_467460()
}
func nox_xxx_wndCreateInventoryMB_465E00() *gui.Window {
	nox_xxx_inventoryLoadImages_467050()
	nox_xxx_inventoryNameSignInit_4671E0()
	dword_5d4594_1063636 = nox_xxx_guiFontPtrByName_43F360(internCStr("small"))
	*memmap.PtrUint32(0x5D4594, 1049732) = 0
	*memmap.PtrUint32(0x5D4594, 1049736) = 0
	*memmap.PtrUint32(0x5D4594, 1049740) = uint32(nox_win_width)
	*memmap.PtrUint32(0x5D4594, 1049744) = uint32(nox_win_height)
	*memmap.PtrUint32(0x5D4594, 1049764) = uint32(nox_win_width)
	*memmap.PtrUint32(0x5D4594, 1049768) = uint32(nox_win_height)
	*memmap.PtrUint32(0x5D4594, 1049748) = 0
	*memmap.PtrUint32(0x5D4594, 1049752) = 0
	dword_5d4594_1062452 = nox_window_new(nil, 552, 0, 0, 563, 264, nil)
	nox_window_set_all_funcs(dword_5d4594_1062452, nil, nox_xxx_movEax1Sub_4661C0, nil)
	v0 := (*uint32)(unsafe.Pointer(nox_window_new(dword_5d4594_1062452, 8, 0, 224, int(nox_win_width), 40, nil)))
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(v0)), nox_xxx_XorEaxEaxSub_464BA0, nox_xxx_movEax1Sub_4661C0, nox_xxx_inventroryOnHovewerSub_4667E0)
	dword_5d4594_1062456 = nox_window_new(dword_5d4594_1062452, 40, 0, 0, 563, 224, sub_466220)
	nox_window_set_all_funcs(dword_5d4594_1062456, sub_464BD0, nox_xxx_inventoryDrawAllMB_463430, sub_466620)
	dword_5d4594_1062456.DrawData().Style |= 0x100
	*memmap.PtrPtr(0x5D4594, 1062472) = unsafe.Pointer(nox_window_new(dword_5d4594_1062452, 40, 0, 0, 1, 1, nil))
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, 1062472)))), sub_464BD0, nox_xxx_movEax1Sub_4661C0, nil)
	dword_5d4594_1062468 = nox_window_new(dword_5d4594_1062456, 40, 173, 174, 50, 50, nil)
	nox_window_set_all_funcs(dword_5d4594_1062468, sub_464770, sub_4625D0, sub_4661D0)
	dword_5d4594_1062468.DrawData().Style |= 0x100
	result := sub_466950(dword_5d4594_1062456)
	if result == 0 {
		return nil
	}
	result = sub_466C40(dword_5d4594_1062456)
	if result == 0 {
		return nil
	}
	result = sub_466ED0(dword_5d4594_1062456)
	if result == 0 {
		return nil
	}
	nox_win_unk5 = nox_window_new(nil, NOX_WIN_LAYER_BACK|0x408, -1, int(nox_win_height-math.MaxInt8), 111, math.MaxInt8, nil)
	if nox_win_unk5 == nil {
		return nil
	}
	nox_window_set_all_funcs(nox_win_unk5, nox_xxx_inventoryWndProc_464BB0, nox_xxx_inventoryDrawProc_466580, nil)
	v3 := nox_xxx_gLoadImg_42F970(internCStr("CurrentWeapon"))
	nox_xxx_wndSetIcon_46AE60(nox_win_unk5, v3)
	v4 := nox_xxx_gLoadImg_42F970(internCStr("CurrentWeaponLit"))
	nox_xxx_wndSetIconLit_46AEA0(nox_win_unk5, v4)
	nox_xxx_wndSetOffsetMB_46AE40(nox_win_unk5, -1, 0)
	nox_win_init_cur_weapon(nox_win_unk5, 24, 51, 53, 53)
	sub_471160(nox_win_unk5, 79, 40, 20, math.MaxInt8)
	sub_470D70()
	v5 := nox_window_new(nox_win_unk5, 8, 5, 11, 28, 29, nil)
	nox_window_set_all_funcs(v5, sub_466550, nox_xxx_movEax1Sub_4661C0, sub_466160)
	libc.MemSet(unsafe.Pointer(&nox_client_inventory_grid_1050020[0]), 0, int(uintptr(NOX_INVENTORY_ROW_COUNT*NOX_INVENTORY_COL_COUNT)*unsafe.Sizeof(nox_inventory_cell_t{})))
	if dword_5d4594_1062560 == 0 {
		dword_5d4594_1062560 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Gold"))
		*memmap.PtrUint32(0x5D4594, 1049728) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("QuestGoldPile")))
		*memmap.PtrUint32(0x5D4594, 1049724) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("QuestGoldChest")))
	}
	nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT*1-1].field_0 = nox_new_drawable_for_thing(dword_5d4594_1062560)
	if nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1].field_0 != nil {
		nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1].field_140 = 1
	}
	v6 := dword_5d4594_1062564
	if dword_5d4594_1062564 == 0 {
		v6 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Identify"))
		dword_5d4594_1062564 = v6
	}
	nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT*2-1].field_0 = nox_new_drawable_for_thing(v6)
	if nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT*2-1].field_0 != nil {
		nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT*2-1].field_140 = 1
	}
	v7 := dword_5d4594_1062556
	if dword_5d4594_1062556 == 0 {
		v7 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("AutoMap"))
		dword_5d4594_1062556 = v7
	}
	nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT*3-1].field_0 = nox_new_drawable_for_thing(v7)
	if nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT*3-1].field_0 != nil {
		nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT*3-1].field_140 = 1
	}
	return dword_5d4594_1062456
}
func nox_xxx_movEax1Sub_4661C0(win *gui.Window, draw *gui.WindowData) int {
	return 1
}
func sub_466220(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v5 int32
		v6 int32
		v7 int32
		v8 int32
	)
	if a2 == 16391 {
		switch nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) {
		case 9102:
			if dword_5d4594_1062512-25 >= 0 {
				v5 = dword_5d4594_1062512 - 25 - (dword_5d4594_1062512-25)%50
			} else {
				v5 = 0
			}
			dword_5d4594_1062512 = v5
			nox_window_call_field_94_fnc(dword_5d4594_1062508, 16394, uintptr(*(*uint32)(unsafe.Add(dword_5d4594_1062508.WidgetData, 4))-uint32(v5)), 0)
			nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
			return 0
		case 9103:
			v6 = dword_5d4594_1062512 + 50
			dword_5d4594_1062512 = v6
			if v6 <= *(*int32)(unsafe.Add(dword_5d4594_1062508.WidgetData, 4)) {
				v7 = v6 - v6%50
			} else {
				v7 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1062508.WidgetData, 4)))
			}
			dword_5d4594_1062512 = v7
			nox_window_call_field_94_fnc(dword_5d4594_1062508, 16394, uintptr(*(*uint32)(unsafe.Add(dword_5d4594_1062508.WidgetData, 4))-uint32(v7)), 0)
			nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
			return 0
		case 9105:
			v8 = sub_469FA0() - 150
			if dword_5d4594_1049864 == 5 {
				return 0
			}
			if v8 < 0 {
				v8 = 0
			}
			*memmap.PtrUint8(0x5D4594, 1049869) = 1
			dword_5d4594_1062516 = dword_5d4594_1062512
			dword_5d4594_1062512 = dword_5d4594_1062520
			nox_window_call_field_94_fnc(dword_5d4594_1062508, 16395, 0, uintptr(v8))
			nox_window_call_field_94_fnc(dword_5d4594_1062508, 16394, uintptr(*(*int32)(unsafe.Add(dword_5d4594_1062508.WidgetData, 4))-dword_5d4594_1062512), 0)
			nox_xxx_wndSetIcon_46AE60(dword_5d4594_1062528, noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, 1049980)))
			sub_46AEC0(dword_5d4594_1062528, noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, 1049984)))
			nox_xxx_wndSetID_46B080(dword_5d4594_1062528, 9106)
			return 0
		case 9106:
			*memmap.PtrUint8(0x5D4594, 1049869) = 0
			dword_5d4594_1062520 = dword_5d4594_1062512
			dword_5d4594_1062512 = dword_5d4594_1062516
			nox_window_call_field_94_fnc(dword_5d4594_1062508, 16395, 0, 850)
			nox_window_call_field_94_fnc(dword_5d4594_1062508, 16394, uintptr(*(*int32)(unsafe.Add(dword_5d4594_1062508.WidgetData, 4))-dword_5d4594_1062512), 0)
			nox_xxx_wndSetIcon_46AE60(dword_5d4594_1062528, nil)
			sub_46AEC0(dword_5d4594_1062528, dword_5d4594_1049976)
			nox_xxx_wndSetID_46B080(dword_5d4594_1062528, 9105)
			return 0
		case 9107:
			if dword_5d4594_1049864 == 5 {
				return 0
			}
			*memmap.PtrUint8(0x5D4594, 1049870) = 1
			nox_xxx_wndSetIcon_46AE60(dword_5d4594_1062524, nil)
			sub_46AEC0(dword_5d4594_1062524, noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, 1049988)))
			nox_xxx_wndSetID_46B080(dword_5d4594_1062524, 9108)
			nox_window_set_hidden(dword_5d4594_1062468, 1)
			return 0
		case 9108:
			if dword_5d4594_1049864 != 5 {
				*memmap.PtrUint8(0x5D4594, 1049870) = 0
				nox_xxx_wndSetIcon_46AE60(dword_5d4594_1062524, dword_5d4594_1049992)
				sub_46AEC0(dword_5d4594_1062524, dword_5d4594_1049996)
				nox_xxx_wndSetID_46B080(dword_5d4594_1062524, 9107)
				nox_window_set_hidden(dword_5d4594_1062468, 0)
			}
			return 0
		case 9111:
			sub_467C10()
			return 0
		default:
			return 0
		}
	} else if a2 == 16393 {
		dword_5d4594_1062512 = *(*int32)(unsafe.Add(dword_5d4594_1062508.WidgetData, 4)) - int32(a4)
		return 0
	} else {
		return 0
	}
}
func sub_466550(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	if a2 < 5 {
		return 0
	}
	if a2 <= 6 {
		return 1
	}
	if a2 == 7 {
		nox_client_toggleInventory_467C60()
		return 1
	}
	return 0
}
func nox_xxx_inventoryDrawProc_466580(win *gui.Window, draw *gui.WindowData) int {
	var (
		v1 *uint32
		v3 *int16
		v6 int32
		v7 int32
	)
	v1 = (*uint32)(win.C())
	var a1b, v5 int32
	nox_client_wndGetPosition_46AA60(win, &v5, &a1b)
	nox_window_get_size((*gui.Window)(unsafe.Pointer(v1)), &v7, &v6)
	var v2 noxrender.ImageHandle
	if int32(*memmap.PtrUint8(0x5D4594, 1049868)) != 0 {
		v2 = *(*noxrender.ImageHandle)(unsafe.Add(unsafe.Pointer(v1), 4*19))
	} else {
		v2 = *(*noxrender.ImageHandle)(unsafe.Add(unsafe.Pointer(v1), 4*15))
	}
	nox_client_drawImageAt_47D2C0(v2, v5, a1b)
	nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
	v3 = (*int16)(unsafe.Pointer(sub_42E8E0(35, 1)))
	if v3 != nil {
		nox_xxx_drawString_43F6E0(dword_5d4594_1063636, (*wchar2_t)(unsafe.Pointer(v3)), v5+19, a1b+102)
	}
	return 1
}
func sub_466620(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	a1 := (int32)(uintptr(win.C()))
	var (
		v3  *wchar2_t
		a2a int2
	)
	a2a.field_4 = int32(a3 >> 16)
	a2a.field_0 = int32(uint16(a3))
	v3 = sub_466660(a1, &a2a)
	nox_xxx_cursorSetTooltip_4776B0(v3)
	return 1
}
func sub_466950(a1 *gui.Window) int32 {
	var (
		v5 [4]int32
		v6 [332]byte
	)
	v5[1] = 0
	v5[2] = 0
	v5[3] = 0
	v5[0] = 0
	*(*uint32)(unsafe.Pointer(&v6[24])) = 0
	*(*uint32)(unsafe.Pointer(&v6[48])) = 0
	*(*uint32)(unsafe.Pointer(&v6[32])) = *memmap.PtrUint32(0x5D4594, 1049940)
	*(*uint32)(unsafe.Pointer(&v6[40])) = *memmap.PtrUint32(0x5D4594, 1049944)
	*(*uint32)(unsafe.Pointer(&v6[56])) = *memmap.PtrUint32(0x5D4594, 1049944)
	*(*uint32)(unsafe.Pointer(&v6[68])) = 0x80000000
	*(*uint32)(unsafe.Pointer(&v6[8])) = 1
	*(*uint16)(unsafe.Pointer(&v6[72])) = 0
	*(**gui.Window)(unsafe.Pointer(&v6[16])) = a1
	v1 := nox_gui_newButtonOrCheckbox_4A91A0(a1, 1161, 522, 2, 20, 25, (*gui.WindowData)(unsafe.Pointer(&v6[0])))
	*memmap.PtrPtr(0x5D4594, 1062500) = unsafe.Pointer(v1)
	if v1 == nil {
		return 0
	}
	nox_xxx_wndSetID_46B080(v1, 9102)
	*(*[332]byte)(unsafe.Pointer(&v6[0])) = [332]byte{}
	*(*uint32)(unsafe.Pointer(&v6[32])) = *memmap.PtrUint32(0x5D4594, 1049948)
	*(*uint32)(unsafe.Pointer(&v6[24])) = 0
	*(*uint32)(unsafe.Pointer(&v6[48])) = 0
	*(*uint32)(unsafe.Pointer(&v6[40])) = *memmap.PtrUint32(0x5D4594, 1049952)
	*(*uint32)(unsafe.Pointer(&v6[56])) = *memmap.PtrUint32(0x5D4594, 1049952)
	*(*uint32)(unsafe.Pointer(&v6[68])) = 0x80000000
	*(*uint32)(unsafe.Pointer(&v6[8])) = 1
	*(*uint16)(unsafe.Pointer(&v6[72])) = 0
	*(**gui.Window)(unsafe.Pointer(&v6[16])) = a1
	v3 := nox_gui_newButtonOrCheckbox_4A91A0(a1, 1161, 522, 148, 20, 25, (*gui.WindowData)(unsafe.Pointer(&v6[0])))
	*memmap.PtrPtr(0x5D4594, 1062504) = unsafe.Pointer(v3)
	if v3 == nil {
		return 0
	}
	nox_xxx_wndSetID_46B080(v3, 9103)
	*(*[332]byte)(unsafe.Pointer(&v6[0])) = [332]byte{}
	v5[2] = 0
	*(*uint32)(unsafe.Pointer(&v6[20])) = 0x80000000
	*(*uint32)(unsafe.Pointer(&v6[44])) = 0x80000000
	*(*uint32)(unsafe.Pointer(&v6[28])) = 0x80000000
	*(*uint32)(unsafe.Pointer(&v6[36])) = 0x80000000
	*(*uint32)(unsafe.Pointer(&v6[52])) = 0x80000000
	*(*uint32)(unsafe.Pointer(&v6[8])) = 8
	*(**gui.Window)(unsafe.Pointer(&v6[16])) = a1
	v5[3] = 0
	v5[0] = 0
	v5[1] = 850
	v4 := nox_gui_newSlider_4B4EE0(a1, 1033, 524, 42, 16, 91, (*uint32)(unsafe.Pointer(&v6[0])), (*float32)(unsafe.Pointer(&v5[0])))
	dword_5d4594_1062508 = v4
	if v4 == nil {
		return 0
	}
	nox_xxx_wndSetWindowProc_46B300(v4, sub_466BF0)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1062508.Field100(), sub_466BA0)
	dword_5d4594_1062508.Field100().SizeVal.X = 16
	dword_5d4594_1062508.Field100().SizeVal.Y = 16
	nox_xxx_wndSetOffsetMB_46AE40(dword_5d4594_1062508.Field100(), 0, -15)
	sub_4B5700(dword_5d4594_1062508, 0, 0, *memmap.PtrPtr(0x5D4594, 1049956), *memmap.PtrPtr(0x5D4594, 1049960), *memmap.PtrPtr(0x5D4594, 1049960))
	return 1
}
func sub_466BA0(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	if *memmap.PtrUint32(0x5D4594, 1049848) != 0 {
		return sub_464BD0(win, p2, p3, p4)
	} else {
		return nox_xxx_wndButtonProc_4A7F50(win, p2, p3, p4)
	}
}
func sub_466BF0(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	if *memmap.PtrUint32(0x5D4594, 1049848) != 0 {
		return sub_464BD0(win, p2, p3, p4)
	} else {
		return nox_xxx_wndScrollBoxDraw_4B4BA0(win, p2, p3, p4)
	}
}
func sub_466C40(a1 *gui.Window) int32 {
	var v5 [332]byte
	*(*uint32)(unsafe.Pointer(&v5[24])) = 0
	*(*uint32)(unsafe.Pointer(&v5[48])) = 0
	*(*uint32)(unsafe.Pointer(&v5[32])) = 0
	*(*uint32)(unsafe.Pointer(&v5[40])) = 0
	*(*noxrender.ImageHandle)(unsafe.Pointer(&v5[56])) = dword_5d4594_1049976
	*(*uint32)(unsafe.Pointer(&v5[60])) = 4294967053
	*(*uint32)(unsafe.Pointer(&v5[64])) = 4294967126
	*(**gui.Window)(unsafe.Pointer(&v5[16])) = a1
	*(*uint32)(unsafe.Pointer(&v5[8])) = 1
	v1 := nox_gui_newButtonOrCheckbox_4A91A0(a1, 1161, 243, 170, 34, 34, (*gui.WindowData)(unsafe.Pointer(&v5[0])))
	dword_5d4594_1062528 = v1
	if v1 == nil {
		return 0
	}
	nox_xxx_wndSetID_46B080(v1, 9105)
	nox_gui_winSetFunc96_46B070(dword_5d4594_1062528, sub_466E20)
	v5 = [332]byte{}
	*(*noxrender.ImageHandle)(unsafe.Pointer(&v5[24])) = dword_5d4594_1049992
	*(*uint32)(unsafe.Pointer(&v5[48])) = 0
	*(*uint32)(unsafe.Pointer(&v5[32])) = 0
	*(*uint32)(unsafe.Pointer(&v5[40])) = 0
	*(*noxrender.ImageHandle)(unsafe.Pointer(&v5[56])) = dword_5d4594_1049996
	*(*uint32)(unsafe.Pointer(&v5[60])) = 4294967291
	*(*uint32)(unsafe.Pointer(&v5[64])) = 4294967110
	*(**gui.Window)(unsafe.Pointer(&v5[16])) = a1
	*(*uint32)(unsafe.Pointer(&v5[8])) = 1
	v3 := nox_gui_newButtonOrCheckbox_4A91A0(a1, 1161, 5, 186, 34, 34, (*gui.WindowData)(unsafe.Pointer(&v5[0])))
	dword_5d4594_1062524 = v3
	if v3 == nil {
		return 0
	}
	nox_xxx_wndSetID_46B080(v3, 9107)
	nox_gui_winSetFunc96_46B070(dword_5d4594_1062524, sub_466E20)
	v5 = [332]byte{}
	*(*uint32)(unsafe.Pointer(&v5[24])) = 0
	*(*uint32)(unsafe.Pointer(&v5[48])) = 0
	*(*uint32)(unsafe.Pointer(&v5[32])) = 0
	*(*uint32)(unsafe.Pointer(&v5[40])) = 0
	*(*uint32)(unsafe.Pointer(&v5[56])) = *memmap.PtrUint32(0x5D4594, 1049972)
	*(*uint32)(unsafe.Pointer(&v5[60])) = 4294966749
	*(*uint32)(unsafe.Pointer(&v5[64])) = 4294967294
	*(**gui.Window)(unsafe.Pointer(&v5[16])) = a1
	*(*uint32)(unsafe.Pointer(&v5[8])) = 1
	v4 := nox_gui_newButtonOrCheckbox_4A91A0(a1, 1161, 547, 2, 16, 16, (*gui.WindowData)(unsafe.Pointer(&v5[0])))
	*memmap.PtrPtr(0x5D4594, 1062532) = unsafe.Pointer(v4)
	if v4 == nil {
		return 0
	}
	nox_xxx_wndSetID_46B080(v4, 9111)
	nox_gui_winSetFunc96_46B070((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1062532)), sub_466E20)
	return 1
}
func sub_466ED0(a1 *gui.Window) int32 {
	result := nox_new_window_from_file(internCStr("identify.wnd"), nil)
	dword_5d4594_1062476 = result
	if result == nil {
		return 0
	}
	sub_46AB20(result, 200, 200)
	sub_46B120(dword_5d4594_1062476, a1)
	nox_window_setPos_46A9B0(dword_5d4594_1062476, 51, 15)
	v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1062476, 9155)
	nox_xxx_wndSetDrawFn_46B340(v2, sub_466F50)
	return 1
}
func sub_466F50(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1  = (*uint32)(win.C())
		a2  = (*int32)(draw.C())
		v3  int32
		v6  *uint32
		v8  int32
		v10 *uint8
		v11 *int32
		v12 **uint8
		v13 int32
	)
	if dword_5d4594_1063116 == nil {
		return 1
	}
	v3 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1063116, 112)))
	if uint32(v3)&0x13001000 != 0 {
		v4 := (*uint32)(func() unsafe.Pointer {
			if uint32(v3)&0x11001000 != 0 {
				return nox_xxx_getProjectileClassById_413250(int32(*(*uint32)(unsafe.Add(dword_5d4594_1063116, 108))))
			}
			return nox_xxx_equipClothFindDefByTT_413270(int32(*(*uint32)(unsafe.Add(dword_5d4594_1063116, 108))))
		}())
		v6 = v4
		if v4 != nil {
			v8 = 1
			v9 := unsafe.Add(dword_5d4594_1063116, 432)
			v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 4*4))
			for {
				cb := *(*uint8)(unsafe.Add(unsafe.Pointer(v10), 1))
				cg := *v10
				cr := *(*uint8)(unsafe.Add(unsafe.Pointer(v10), -1))
				nox_draw_setMaterial_4340A0(func() int32 {
					p := &v8
					x := *p
					*p++
					return x
				}(), int32(cr), int32(cg), int32(cb))
				v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 3))
				if v8 >= 7 {
					break
				}
			}
			v11 = (*int32)(unsafe.Add(unsafe.Pointer(v6), 4*9))
			v12 = (**uint8)(v9)
			v13 = 4
			for {
				v14 := *v12
				if *v12 != nil {
					cb := *(*uint8)(unsafe.Add(unsafe.Pointer(v14), 26))
					cg := *(*uint8)(unsafe.Add(unsafe.Pointer(v14), 25))
					cr := *(*uint8)(unsafe.Add(unsafe.Pointer(v14), 24))
					nox_draw_setMaterial_4340A0(*v11, int32(cr), int32(cg), int32(cb))
				}
				v12 = (**uint8)(unsafe.Add(unsafe.Pointer(v12), unsafe.Sizeof((*uint8)(nil))*1))
				v11 = (*int32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
				v13--
				if v13 == 0 {
					break
				}
			}
		}
	}
	var v15, v16 int32
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(a1)), &v15, &v16)
	nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*6))), *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*15))+v15, *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*16))+v16)
	return 1
}
func nox_xxx_inventoryLoadImages_467050() {
	*memmap.PtrPtr(0x5D4594, 1049908) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryBase")))
	*memmap.PtrPtr(0x5D4594, 1049912) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryIdentifyBase")))
	*memmap.PtrPtr(0x5D4594, 1049916) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryTray1")))
	*memmap.PtrPtr(0x5D4594, 1049920) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryTray2")))
	*memmap.PtrPtr(0x5D4594, 1049924) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryTray3")))
	*memmap.PtrPtr(0x5D4594, 1049928) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryTraySpecial")))
	*memmap.PtrPtr(0x5D4594, 1049932) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryTrayIdentifyLit")))
	*memmap.PtrPtr(0x5D4594, 1049936) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryTrayMapLit")))
	*memmap.PtrPtr(0x5D4594, 1049940) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryUpButton")))
	*memmap.PtrPtr(0x5D4594, 1049944) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryUpButtonLit")))
	*memmap.PtrPtr(0x5D4594, 1049948) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryDownButton")))
	*memmap.PtrPtr(0x5D4594, 1049952) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryDownButtonLit")))
	*memmap.PtrPtr(0x5D4594, 1049956) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventorySliderButton")))
	*memmap.PtrPtr(0x5D4594, 1049960) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventorySliderButtonLit")))
	*memmap.PtrPtr(0x5D4594, 1049964) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryEquipRing")))
	*memmap.PtrPtr(0x5D4594, 1049968) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryQuickItemRing")))
	*memmap.PtrPtr(0x5D4594, 1049972) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryCloseButtonLit")))
	dword_5d4594_1049976 = nox_xxx_gLoadImg_42F970(internCStr("InventoryJournalButtonLit"))
	*memmap.PtrPtr(0x5D4594, 1049980) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryInventoryButton")))
	*memmap.PtrPtr(0x5D4594, 1049984) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryInventoryButtonLit")))
	*memmap.PtrPtr(0x5D4594, 1049988) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("InventoryDollButtonLit")))
	dword_5d4594_1049992 = nox_xxx_gLoadImg_42F970(internCStr("InventoryStatsButton"))
	dword_5d4594_1049996 = nox_xxx_gLoadImg_42F970(internCStr("InventoryStatsButtonLit"))
	*memmap.PtrPtr(0x5D4594, 1050000) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("GUIFist")))
	*memmap.PtrPtr(0x5D4594, 1050004) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("SharedKeyMode")))
	dword_5d4594_1050008 = nox_xxx_gLoadAnim_42FA20(internCStr("ExtraLives"))
}
func nox_client_invAlterWeapon_4672C0() {
	if *memmap.PtrUint32(0x852978, 8) == 0 {
		return
	}
	if nox_xxx_guiCursor_477600() != 0 {
		return
	}
	if sub_461160(1) != 0 {
		return
	}
	v1 := *memmap.PtrPtr(0x8531A0, 2576)
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
		return
	}
	if *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 276)) == 34 {
		return
	}
	v2 := nox_xxx_pointInRect_4281F0((*int2)(memmap.PtrOff(0x5D4594, 1062572)), (*int4)(memmap.PtrOff(0x587000, 136336)))
	if v2 == 1 {
		nox_xxx_cursorSetDraggedItem_477690(nil)
	}
	v3 := dword_5d4594_1062480
	if dword_5d4594_1062480 != nil {
		if nox_xxx_ammoCheck_415880(uint16(dword_5d4594_1062480.field_0.Field_27)) == 2 {
			v4 := sub_415840(2)
			r4 := sub_461600(v4)
			if r4 == nil {
				return
			}
			dword_5d4594_1062492 = r4
			nox_xxx_clientDequip_464B70(r4)
			nox_xxx_clientPlaySoundSpecial_452D80(895, 100)
			return
		}
		v3 = dword_5d4594_1062480
	}
	for i := 1; i < 27; i++ {
		r5 := 1 << i
		if 1<<i != 2 && uint32(r5)&*(*uint32)(unsafe.Add(v1, 4)) != 0 {
			v6 := sub_415840(1 << i)
			r6 := sub_461600(v6)
			if r6 != nil {
				dword_5d4594_1062492 = r6
				nox_xxx_clientDequip_464B70(r6)
				nox_xxx_clientPlaySoundSpecial_452D80(895, 100)
				return
			}
			v3 = dword_5d4594_1062480
		}
	}
	if v3 != nil {
		v3.field_0.Field_32 = v3.field_4
		nox_xxx_clientEquip_4623B0(dword_5d4594_1062480.field_0)
		nox_xxx_clientPlaySoundSpecial_452D80(895, 100)
	}
}
func sub_4673F0(a1 int32, a2 int32) {
	*memmap.PtrUint32(0x5D4594, 1062580) = uint32(a1)
	*memmap.PtrUint32(0x5D4594, 1062584) = uint32(a2)
}
func sub_467410(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1062540) = uint32(a1)
	return result
}
func sub_467420(a1 int8) int8 {
	var result int8
	result = a1
	*memmap.PtrUint8(0x5D4594, 1062536) = uint8(a1)
	return result
}
func sub_467430() uint8 {
	return *memmap.PtrUint8(0x5D4594, 1062536)
}
func sub_467440(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1062544) = uint32(a1)
	return result
}
func sub_467450(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1062548) = uint32(a1)
	return result
}
func sub_467470(a1 int32, a2 float32) int32 {
	var result int32
	result = int32(uint8(int8(a1)))
	*mem_getFloatPtr(0x5D4594, uint32(int32(uint8(int8(a1)))*4)+1063100) = a2
	return result
}
func sub_467490(a1 int32) {
	dword_5d4594_1062552 = a1
}
func sub_4674A0() int32 {
	return dword_5d4594_1062552
}
func nox_window_set_visible_unk5(visible int32) {
	if visible != 0 {
		nox_window_set_hidden(nox_win_unk5, 0)
	} else {
		nox_window_set_hidden(nox_win_unk5, 1)
	}
}
func nox_xxx_cliUseCurePoison_4674E0(a1 int32) {
	if nox_xxx_guiCursor_477600() != 1 {
		if nox_xxx_checkGameFlagPause_413A50() == 0 {
			cell := nox_xxx_cliInventoryFirstItemByTT_467520(a1)
			if cell != nil {
				cell.field_0.Field_32 = cell.field_4
				nox_xxx_clientUse_465C70(cell.field_0)
			}
		}
	}
}
func nox_xxx_cliInventoryFirstItemByTT_467520(a1 int32) *nox_inventory_cell_t {
	var (
		v1 int32
		v3 int32
	)
	v1 = 0
	v2 := &nox_client_inventory_grid_1050020[0]
	for {
		v3 = 0
		v4 := v2
		for {
			if int32(v4.field_140) != 0 && *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v4)), 108)) == uint32(a1) {
				return &nox_client_inventory_grid_1050020[v1+NOX_INVENTORY_ROW_COUNT*v3]
			}
			v3++
			v4 = (*nox_inventory_cell_t)(unsafe.Add(unsafe.Pointer(v4), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
			if v3 >= 4 {
				break
			}
		}
		v2 = (*nox_inventory_cell_t)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(nox_inventory_cell_t{})))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) <= int32(uintptr(unsafe.Pointer(&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1]))) {
			continue
		}
		break
	}
	return nil
}
func sub_467590() int32 {
	var result int32
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		result = int32(*(*byte)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 3684)))
	} else {
		result = 1
	}
	return result
}
func sub_4675B0() int32 {
	return int32(dword_5d4594_1049864)
}
func sub_4675E0(a1 int32, a2 int16, a3 int16) {
	v3 := sub_461EF0(a1)
	if v3 != nil {
		*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(**(**uint32)(unsafe.Pointer(v3)))), 292)) = uint16(a2)
		v4 := **(**unsafe.Pointer)(unsafe.Pointer(v3))
		*(*uint16)(unsafe.Add(v4, 294)) = uint16(a3)
	} else {
		if *memmap.PtrUint32(0x5D4594, 1049848) != 0 && *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 128)) == uint32(a1) {
			*(*uint16)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 292)) = uint16(a2)
			*(*uint16)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 294)) = uint16(a3)
		}
	}
}
func sub_467650() {
	sub_462740()
	dword_5d4594_1049864 = 6
	nox_client_setCursorType_477610(8)
	if sub_467C80() == 0 {
		sub_467BB0()
	}
}
func sub_467680() {
	if dword_5d4594_1049864 == 6 {
		dword_5d4594_1049864 = 0
	}
}
func nox_xxx_wndGetHandle_4676A0() *gui.Window {
	return dword_5d4594_1062452
}
func sub_4676D0(a1 int32) int32 {
	v1 := sub_461EF0(a1)
	if v1 != nil {
		return int32(**(**uint32)(unsafe.Pointer(v1)))
	}
	result := int32(*memmap.PtrUint32(0x5D4594, 1049848))
	if *memmap.PtrUint32(0x5D4594, 1049848) == 0 || *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 128)) != uint32(a1) {
		result = 0
	}
	return result
}
func sub_467700(a1 int32) int32 {
	v1 := sub_461EF0(a1)
	if v1 != nil {
		return int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v1)), 140)))
	}
	if *memmap.PtrUint32(0x5D4594, 1049848) != 0 && *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 128)) == uint32(a1) {
		return 1
	}
	return 0
}
func sub_467740(a1 int32) int32 {
	dword_5d4594_1062488 = uint32(a1)
	return a1
}
func sub_467810(a1 int32, a2 int32) int32 {
	if a1 < 0 || a2 < 0 || a1 >= 4 || a2 >= 20 {
		return 0
	}
	return int32(nox_client_inventory_grid_1050020[a2+NOX_INVENTORY_ROW_COUNT*a1].field_140)
}
func sub_467850(a1 int32) int32 {
	v1 := nox_xxx_cliInventoryFirstItemByTT_467520(a1)
	if v1 != nil {
		return int32(v1.field_140)
	}
	return 0
}
func sub_467870(a1 int32, a2 int32) *byte {
	if a1 < 0 || a2 < 0 || a1 >= 4 || a2 >= 20 {
		return nil
	}
	return (*byte)(unsafe.Pointer(&nox_client_inventory_grid_1050020[a2+NOX_INVENTORY_ROW_COUNT*a1].field_4))
}
func sub_4678B0() int32 {
	if dword_5d4594_1062480 != nil {
		return int32(dword_5d4594_1062480.field_4)
	}
	return 0
}
func sub_4678C0() int32 {
	return int32(dword_5d4594_1062488)
}
func sub_4678D0() unsafe.Pointer {
	var (
		v1 int32
		v2 int32
		v3 *client.Drawable
	)
	v0 := *memmap.PtrPtr(0x8531A0, 2576)
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
		return nil
	}
	v1 = 1
	for {
		if 1<<v1 != 2 {
			if uint32(1<<v1)&*(*uint32)(unsafe.Add(v0, 4)) != 0 {
				v2 = sub_415840(1 << v1)
				v3 = sub_461600(v2)
				if v3 != nil {
					break
				}
			}
		}
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= 27 {
			return nil
		}
	}
	v5 := sub_461EF0(int32(v3.Field_32))
	if v5 != nil {
		return **(**unsafe.Pointer)(unsafe.Pointer(v5))
	} else {
		return nil
	}
}
func sub_467930(a1 int32, a2 int32, a3 int32) {
	if a1 == 0 {
		return
	}
	r1 := sub_461EF0(a1)
	if r1 == nil {
		return
	}
	v4 := **(**unsafe.Pointer)(unsafe.Pointer(r1))
	*(*uint16)(unsafe.Add(v4, 448)) = uint16(int16(a2))
	*(*uint16)(unsafe.Add(v4, 450)) = uint16(int16(a3))
	r2 := *(**byte)(unsafe.Pointer(r1))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(r2), 4*33)) == 1 {
		sub_470D90(a2, a3)
	}
}
func sub_467980() int32 {
	var (
		v0 *uint8
		v1 *uint8
		v2 int32
	)
	v0 = (*uint8)(unsafe.Pointer(&nox_client_inventory_grid_1050020[0]))
	for {
		v1 = v0
		v2 = 4
		for {
			if *(*uint32)(unsafe.Pointer(v1)) != 0 {
				nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(*(**uint64)(unsafe.Pointer(v1)))))
				*(*uint32)(unsafe.Pointer(v1)) = 0
			}
			*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 140)) = 0
			*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*33)) = 0
			*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) = 0
			v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
			v2--
			if v2 == 0 {
				break
			}
		}
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(nox_inventory_cell_t{})))
		if int32(uintptr(unsafe.Pointer(v0))) > int32(uintptr(unsafe.Pointer(&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1]))) {
			break
		}
	}
	sub_462740()
	dword_5d4594_1049864 = 0
	nox_xxx_clientSetAltWeapon_461550(nil)
	dword_5d4594_1062488 = 0
	libc.MemSet(unsafe.Pointer(&array_5D4594_1049872[0]), 0, 0x24)
	dword_5d4594_1062492 = nil
	dword_5d4594_1062496 = 0
	*memmap.PtrUint8(0x5D4594, 1062536) = 0
	*memmap.PtrUint32(0x5D4594, 1062540) = 0
	*memmap.PtrUint32(0x5D4594, 1062544) = 0
	*memmap.PtrUint32(0x5D4594, 1062548) = 0
	dword_5d4594_1062552 = 0
	sub_472310()
	dword_587000_136184 = 4294967071
	*memmap.PtrUint8(0x5D4594, 1049868) = 0
	*memmap.PtrUint8(0x5D4594, 1049869) = 0
	dword_5d4594_1062516 = 0
	dword_5d4594_1062520 = 0
	dword_5d4594_1062512 = 0
	nox_window_call_field_94_fnc(dword_5d4594_1062508, 16395, 0, 850)
	nox_window_call_field_94_fnc(dword_5d4594_1062508, 16394, uintptr(*(*int32)(unsafe.Add(dword_5d4594_1062508.WidgetData, 4))-dword_5d4594_1062512), 0)
	nox_xxx_wndSetIcon_46AE60(dword_5d4594_1062528, nil)
	sub_46AEC0(dword_5d4594_1062528, dword_5d4594_1049976)
	nox_xxx_wndSetID_46B080(dword_5d4594_1062528, 9105)
	*memmap.PtrUint8(0x5D4594, 1049870) = 0
	nox_xxx_wndSetIcon_46AE60(dword_5d4594_1062524, dword_5d4594_1049992)
	sub_46AEC0(dword_5d4594_1062524, dword_5d4594_1049996)
	nox_xxx_wndSetID_46B080(dword_5d4594_1062524, 9107)
	return nox_window_set_hidden(dword_5d4594_1062468, 0)
}
func sub_467B00(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		v3 *uint8
		i  int32
		v5 int32
		v6 int32
		v8 int32
		v9 *uint8
	)
	v2 = 0
	v8 = 0
	v9 = (*uint8)(unsafe.Pointer(&nox_client_inventory_grid_1050020[0]))
	for {
		v3 = v9
		for i = 0; i < 4; i++ {
			v5 = sub_467810(i, v2)
			if v5 == 0 {
				v8++
				v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
				continue
			}
			if *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v3)), 108)) == uint32(a1) {
				v6 = 31
				if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v3)), 112)))&0x10 != 0 {
					if noxflags.HasGame(6144) {
						v6 = 9
					} else {
						v6 = 3
					}
				}
				if (*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v3)), 112))&0x4000000) == 0 && a2+v5 <= v6 {
					v8++
				}
			}
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
		}
		v2++
		v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(nox_inventory_cell_t{})))
		if int32(uintptr(unsafe.Pointer(v9))) >= int32(uintptr(unsafe.Pointer(&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1]))) {
			break
		}
	}
	return v8
}
func sub_467BB0() {
	if nox_gui_xxx_check_446360() == 0 {
		if sub_4AE3D0() == 0 {
			if nox_xxx_guiCursor_477600() == 0 {
				if nox_xxx_playerAnimCheck_4372B0() == 0 {
					if nox_xxx_get_57AF20() == 0 {
						if int32(*memmap.PtrUint8(0x5D4594, 1049868)) == 3 || int32(*memmap.PtrUint8(0x5D4594, 1049868)) == 0 {
							*memmap.PtrUint8(0x5D4594, 1049868) = 1
							nox_xxx_clientPlaySoundSpecial_452D80(789, 100)
						}
						dword_5d4594_1062512 = dword_5d4594_1062516
					}
				}
			}
		}
	}
}
func sub_467C10() int32 {
	if dword_5d4594_1049864 == 6 {
		return 1
	}
	if sub_467C80() == 0 {
		return 0
	}
	*memmap.PtrUint8(0x5D4594, 1049868) = 3
	nox_xxx_clientPlaySoundSpecial_452D80(790, 100)
	if dword_5d4594_1049864 == 5 {
		sub_462740()
	}
	sub_467CD0()
	return 1
}
func nox_client_toggleInventory_467C60() {
	if sub_467C80() != 0 {
		sub_467C10()
	} else {
		sub_467BB0()
	}
}
func sub_467C80() int32 {
	return bool2int32(int32(*memmap.PtrUint8(0x5D4594, 1049868)) == 1 || int32(*memmap.PtrUint8(0x5D4594, 1049868)) == 2)
}
func sub_467CA0() {
	if sub_467C80() == 0 {
		dword_5d4594_1062516 = 0
		if dword_5d4594_1062508 != nil {
			nox_window_call_field_94_fnc(dword_5d4594_1062508, 16394, uintptr(*(*uint32)(unsafe.Add(dword_5d4594_1062508.WidgetData, 4))), 0)
		}
	}
}
func sub_467CD0() int32 {
	var (
		v0 int32
		v3 *uint8
	)
	v0 = 0
	if *memmap.PtrUint32(0x5D4594, 1049848) != 0 {
		if dword_5d4594_1049856 == 0 && sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), dword_5d4594_1049796_inventory_click_column_index, dword_5d4594_1049800_inventory_click_row_index) == 0 {
			nox_xxx_spritePickup_461660(int32(*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 128))), int32(*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 108))), unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 432))
			v1 := sub_461EF0(int32(*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 128))))
			v2 := v1
			if v1 != nil {
				*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v1)), 132)) = 0
				for i := range array_5D4594_1049872 {
					v3 = (*uint8)(unsafe.Pointer(&array_5D4594_1049872[i]))
					v4 := *(*unsafe.Pointer)(unsafe.Pointer(v3))
					if *(*uint32)(unsafe.Pointer(v3)) != 0 {
						for *(*uint32)(unsafe.Add(v4, 128)) != *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 128)) {
							v4 = *(*unsafe.Pointer)(unsafe.Add(v4, 368))
							if v4 == nil {
								goto LABEL_12
							}
						}
						*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v2)), 132)) = 1
						if *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v2)), 136)) != 0 {
							nox_xxx_clientSetAltWeapon_461550(nil)
							*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v2)), 136)) = 0
						}
					}
				LABEL_12:
				}
			}
		}
		*memmap.PtrUint32(0x5D4594, 1049848) = 0
		dword_5d4594_1049856 = 0
		nox_xxx_cursorResetDraggedItem_4776A0()
		v0 = 1
	}
	v5 := nox_xxx_wndGetCaptureMain_46AE00()
	if nox_window_is_child(nox_xxx_wndGetHandle_4676A0(), v5) == 1 {
		v6 := nox_xxx_wndGetCaptureMain_46AE00()
		nox_xxx_wndClearCaptureMain_46ADE0(v6)
	}
	return v0
}
func nox_xxx_gameClearAll_467DF0(a1 int32) {
	var (
		result int32
		v4     [3]int32
	)
	v4[0] = 25
	v4[1] = 25
	v4[2] = 25
	sub_4460A0(0)
	if sub_47A260() == 1 {
		sub_47A1F0()
	}
	if sub_478030() == 1 {
		sub_479280()
	}
	sub_45D810()
	nox_xxx_gameDeleteSpiningCrownSkull_4B8220()
	nox_alloc_npcs_2()
	sub_4573B0()
	if !noxflags.HasGame(1) {
		sub_469B90(&v4[0])
		sub_4349C0((*uint32)(unsafe.Pointer(&v4[0])))
		sub_421B10()
	}
	nox_xxx_spriteDeleteSomeList_49C4B0()
	nox_xxx_sprite_49C4F0()
	sub_49A630()
	sub_49BBB0()
	nox_client_resetScreenParticles_431510()
	nox_xxx_spriteDeleteAll_45A5E0(a1)
	result = bool2int32(noxflags.HasGame(1))
	if result == 0 {
		nox_xxx_wall_410160()
		for i := int32(0); i < ptr_5D4594_2650668_cap*44; i += 44 {
			for j := int32(0); j < ptr_5D4594_2650668_cap; j++ {
				*(*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(j)))))) + uint32(i)))) = 0
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(j))))))+uint32(i))), 4)) = math.MaxUint8
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(j))))))+uint32(i))), 24)) = math.MaxUint8
				nox_xxx_tileFreeTile_422200(unsafe.Add(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(j)))), i+4))
				nox_xxx_tileFreeTile_422200(unsafe.Add(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(j)))), i+24))
			}
		}
	}
}
func sub_469B90(a1 *int32) int32 {
	var result int32
	*memmap.PtrUint32(0x587000, 142296) = uint32(*a1)
	*memmap.PtrUint32(0x587000, 142300) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	result = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2))
	*memmap.PtrUint32(0x587000, 142304) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
	return result
}
func nox_xxx_getAmbientColor_469BB0() *byte {
	return (*byte)(memmap.PtrOff(0x587000, 142296))
}
func sub_469FA0() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1064848))
}
func nox_client_chatStart_46A430(a1 int32) {
	if !noxflags.HasGame(2048) {
		if dword_5d4594_1064868 == 0 {
			*(*uint32)(dword_5d4594_1064864) = 0
			*(*uint16)(unsafe.Add(dword_5d4594_1064864, 1052)) = 0
			nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1064856)
			sub_46C690(dword_5d4594_1064856)
			nox_xxx_windowFocus_46B500(dword_5d4594_1064860)
			dword_5d4594_1064868 = 1
			*memmap.PtrUint32(0x5D4594, 1064872) = uint32(a1)
		}
	}
}
func sub_46A4A0() int32 {
	return int32(dword_5d4594_1064868)
}
func nox_xxx_cmdSayDo_46A4B0(a1 *wchar2_t, a2 int32) uint32 {
	var (
		v2     *uint32
		v3     uint32
		result uint32
		v5     *wchar2_t
		v6     int8
		v7     int32
		v8     [520]byte
	)
	v2 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(nox_player_netCode_85319C).C())
	v3 = nox_wcsspn(a1, internWStr(" "))
	result = nox_wcslen(a1)
	if v3 == result {
		return result
	}
	v5 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(wchar2_t(0))*uintptr(v3)))
	v8[0] = 168
	*(*uint16)(unsafe.Pointer(&v8[9])) = 0
	*(*uint16)(unsafe.Pointer(&v8[1])) = uint16(nox_player_netCode_85319C)
	v8[3] = 0
	if nox_xxx_cliCanTalkMB_4100F0((*int16)(unsafe.Pointer(a1))) != 0 {
		v6 = int8(v8[3] | 2)
	} else {
		v6 = int8(v8[3] | 4)
	}
	v8[3] = byte(v6)
	if a2 != 0 {
		v8[3] |= 1
	}
	v8[8] = byte(nox_wcslen(v5) + 1)
	if v8[3]&4 != 0 {
		nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v8[11])), v5)
		v7 = 2
	} else {
		nox_sprintf(&v8[11], internCStr("%S"), v5)
		v7 = 1
	}
	if v2 != nil {
		*(*uint16)(unsafe.Pointer(&v8[4])) = *(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*6))
		*(*uint16)(unsafe.Pointer(&v8[6])) = *(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*8))
	} else {
		*(*uint16)(unsafe.Pointer(&v8[6])) = math.MaxUint16
		*(*uint16)(unsafe.Pointer(&v8[4])) = math.MaxUint16
	}
	result = uint32(nox_netlist_addToMsgListCli_40EBC0(31, 0, &v8[0], v7*int32(v8[8])+11))
	return result
}
func sub_46A5D0(win *gui.Window, draw *gui.WindowData) int {
	var (
		v2 int32
		v3 bool
	)
	_ = v3
	var v5 int32
	var v6 int32
	v5 = 0
	v6 = 0
	nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1064856)
	nox_xxx_windowFocus_46B500(dword_5d4594_1064860)
	nox_xxx_drawGetStringSize_43F840(nil, (*uint16)(dword_5d4594_1064864), &v5, nil, 0)
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Add(dword_5d4594_1064864, 512)), &v6, nil, 0)
	v3 = v5+v6-90 < 0
	v5 += v6 + 10
	v2 = v5
	if v5 < 100 {
		v2 = 100
		v5 = v2
	} else if v5 > 320 {
		v2 = 320
		v5 = v2
	}
	nox_window_setPos_46A9B0(dword_5d4594_1064856, (nox_win_width-v2)/2, int32(dword_5d4594_1064856.Off.Y))
	sub_46AB20(win, v5, 20)
	return nox_xxx_wndEditDrawNoImage_488160(win, draw)
}
func sub_46A6A0() int32 {
	if wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_1064856) != 0 {
		return 0
	}
	if nox_xxx_wndGetFocus_46B4F0() == dword_5d4594_1064860 {
		nox_xxx_windowFocus_46B500(nil)
	}
	nox_xxx_wnd_46C6E0(dword_5d4594_1064856)
	nox_window_set_hidden(dword_5d4594_1064856, 1)
	dword_5d4594_1064856.Flags &= 0xFFFFFFF7
	dword_5d4594_1064860.Flags &= 0xFFFFFFF7
	set_dword_5d4594_3799468(1)
	dword_5d4594_1064868 = 0
	return 1
}
func sub_46A730() *gui.Window {
	*memmap.PtrUint32(0x5D4594, 1064876) = uint32(nox_win_width / 2)
	*memmap.PtrUint32(0x5D4594, 1064880) = uint32(nox_win_height * 2 / 3)
	r1 := nox_new_window_from_file(internCStr("GuiChat.wnd"), sub_46A820)
	dword_5d4594_1064856 = r1
	if r1 == nil {
		return r1
	}
	nox_window_setPos_46A9B0(r1, *memmap.PtrInt32(0x5D4594, 1064876), *memmap.PtrInt32(0x5D4594, 1064880))
	r2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064856, 9201)
	dword_5d4594_1064860 = r2
	if r2 == nil {
		return r2
	}
	nox_xxx_wndSetDrawFn_46B340(r2, sub_46A5D0)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1064860, sub_46A7E0)
	dword_5d4594_1064864 = dword_5d4594_1064860.WidgetData
	return dword_5d4594_1064856
}
func sub_46A7E0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	if a2 != 21 || a3 != 1 {
		return nox_xxx_wndEditProc_487D70(win, a2, a3, a4)
	}
	if a4 == 2 {
		nox_xxx_consoleEsc_49B7A0()
	}
	return 1
}
func sub_46A820(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	if a2 != 16415 {
		return 0
	}
	if int32(*(*uint16)(unsafe.Add(dword_5d4594_1064864, 1052))) != 0 {
		nox_xxx_cmdSayDo_46A4B0((*uint16)(dword_5d4594_1064864), *memmap.PtrInt32(0x5D4594, 1064872))
	}
	sub_46A6A0()
	return 0
}
func sub_46A860() {
	if dword_5d4594_1064856 != nil {
		nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1064856)
		dword_5d4594_1064856 = nil
	}
	dword_5d4594_1064860 = nil
	dword_5d4594_1064864 = nil
	dword_5d4594_1064868 = 0
	*memmap.PtrUint32(0x5D4594, 1064872) = 0
}
func nox_xxx_wndRetNULL_46A8A0() int32 {
	return 0
}
func nox_xxx_wndRetNULL_0_46A8B0() int32 {
	return 0
}
func sub_46AE10(a1 unsafe.Pointer, a2 int32) {
	if a1 != nil {
		v3 := int32(*(*uint32)(unsafe.Add(a1, 36)))
		if a2 != 0 {
			*(*uint32)(unsafe.Add(a1, 36)) = uint32(v3 | 2)
		} else {
			*(*uint32)(unsafe.Add(a1, 36)) = uint32(v3) & 0xFFFFFFFD
		}
	}
}
func nox_xxx_wndSetOffsetMB_46AE40(a1 *gui.Window, a2 int32, a3 int32) {
	if a1 != nil {
		a1.DrawData().ImgPtVal.X = int(a2)
		a1.DrawData().ImgPtVal.Y = int(a3)
	}
}
func nox_xxx_wndSetIcon_46AE60(a1 *gui.Window, a2 noxrender.ImageHandle) int32 {
	if a1 == nil {
		return -2
	}
	a1.DrawData().BgImageHnd = a2
	return 0
}
func nox_xxx_wndSetIconLit_46AEA0(a1 *gui.Window, a2 noxrender.ImageHandle) int32 {
	if a1 == nil {
		return -2
	}
	a1.DrawData().HlImageHnd = a2
	return 0
}
func sub_46AEC0(a1 *gui.Window, a2 noxrender.ImageHandle) int32 {
	if a1 == nil {
		return -2
	}
	a1.DrawData().SelImageHnd = a2
	return 0
}
func sub_46AEE0(a1 *gui.Window, a2 int32) int32 {
	nox_window_call_field_94_fnc(a1, 16385, uintptr(a2), 0)
	return 0
}
func sub_46AF00(a1 *gui.Window) *wchar2_t {
	if a1 == nil {
		return nil
	}
	v1 := int32(a1.DrawData().Style)
	if v1&0x800 != 0 {
		return (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(a1, 16386, 0, 0)))
	}
	if (v1 & 0x80) != 0 {
		return (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(a1, 16413, 0, 0)))
	} else {
		return nil
	}
}
func sub_46AF40(a1 unsafe.Pointer) unsafe.Pointer {
	if a1 == nil {
		return nil
	}
	return *(*unsafe.Pointer)(unsafe.Add(a1, 236))
}
func nox_gui_windowCopyDrawData_46AF80(win *gui.Window, p unsafe.Pointer) int32 {
	if win == nil {
		return -2
	}
	if p == nil {
		return -3
	}
	alloc.Memcpy(unsafe.Pointer(win.DrawData()), p, unsafe.Sizeof(gui.WindowData{}))
	return 0
}
func sub_46B630(a1p *gui.Window, a2 int32, a3 int32) *gui.Window {
	var (
		v6 int32
		j  int32
	)
	result := a1p
	if a1p == nil {
		return (*gui.Window)(result)
	}
LABEL_2:
	for i := result.Field100Ptr; i != nil; i = i.PrevPtr {
		v6 = int32(i.Off.X)
		j = int32(i.Off.Y)
		for v5 := i.ParentPtr; v5 != nil; v5 = v5.ParentPtr {
			v6 += int32(v5.Off.X)
			j += int32(v5.Off.Y)
		}
		if a2 >= v6 && int(a2) <= int(v6)+i.SizeVal.X && a3 >= j && int(a3) <= int(j)+i.SizeVal.Y && (int32(i.Flags)&0x10) == 0 {
			result = i
			goto LABEL_2
		}
	}
	return (*gui.Window)(result)
}
func nox_xxx_wnd_46C2A0(a1 *gui.Window) int32 {
	if a1 == nil {
		return 1
	}
	if int32(a1.Flags)&0x10 != 0 {
		return 1
	}
	v2 := a1.ParentPtr
	if v2 != nil {
		for (int32(v2.Flags) & 0x10) == 0 {
			v2 = v2.ParentPtr
			if v2 == nil {
				return 0
			}
		}
		return 1
	}
	return 0
}
func sub_46DB80() {
	for i := 0; i < 8; i += 4 {
		nox_window_call_field_94_fnc((*gui.Window)(*memmap.PtrPtr(0x5D4594, uintptr(i)+1090060)), 16399, 1, 0)
		nox_window_call_field_94_fnc((*gui.Window)(*memmap.PtrPtr(0x5D4594, uintptr(i)+1090068)), 16399, 1, 0)
		nox_window_call_field_94_fnc((*gui.Window)(*memmap.PtrPtr(0x5D4594, uintptr(i)+1090076)), 16399, 1, 0)
		nox_window_call_field_94_fnc((*gui.Window)(*memmap.PtrPtr(0x5D4594, uintptr(i)+1090084)), 16399, 1, 0)
		nox_window_call_field_94_fnc((*gui.Window)(*memmap.PtrPtr(0x5D4594, uintptr(i)+1090092)), 16399, 1, 0)
	}
}
func sub_46DC00(a1 *gui.Window, a2 uint8, a3 int32) int32 {
	nox_window_call_field_94_fnc(a1, 16397, uintptr(a3), uintptr(a2))
	return 1
}
func sub_46DC30(a1 *gui.Window, a2 uint8, a3 *wchar2_t, _rest ...interface{}) int32 {
	var va libc.ArgList
	va.Start(a3, _rest)
	nox_vswprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1089000)), a3, va)
	return sub_46DC00(a1, a2, int32(uintptr(memmap.PtrOff(0x5D4594, 1089000))))
}
func sub_46DCC0() {
	var (
		v1  int32
		v4  int32
		v6  int32
		v8  int32
		v9  int32
		m   int32
		v13 uint8
		v14 int32
		v15 int32
		v16 int32
		v20 int32
		v21 uint8
		v22 int32
		v25 int32
		v26 uint32
		j   uint32
		v30 uint8
		v31 int32
		v32 int32
		v33 int32
		v34 int32
		v37 *byte
		v38 int32
		v39 uint8
		v40 int32
	)
	if dword_5d4594_1090120 == 5 {
		v23 := uint32(nox_common_playerInfoCount_416F40())
		v43 := v23
		*memmap.PtrUint8(0x5D4594, 1090117) = 0
		*memmap.PtrUint8(0x5D4594, 1090118) = 0
		if noxflags.HasGame(1) && nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
			v43 = func() uint32 {
				p := &v23
				*p--
				return *p
			}()
		}
		for i := nox_common_playerInfoGetFirst_416EA0(); i != nil; i = nox_common_playerInfoGetNext_416EE0(i) {
			v25 = int32(i.Field3680)
			if (v25&1) == 0 || v25&0x20 != 0 {
				if i.Field2108 == 0 {
					i.Field2108 = 0x8000000
				}
			} else {
				i.Field2108 |= 0x80000000
			}
		}
		v26 = 0
		if uint32(*memmap.PtrUint8(0x5D4594, 1090117)) < v23 {
			var v27 *server.Player
			for {
				j = math.MaxUint32
				for v28 := nox_common_playerInfoGetFirst_416EA0(); v28 != nil; v28 = nox_common_playerInfoGetNext_416EE0(v28) {
					if (v28.PlayerInd != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) && uint32(v28.Field2108) >= v26 && sub_46E1E0(int32(v28.NetCodeVal)) == 0 && uint32(v28.Field2108) < j {
						j = v28.Field2108
						v27 = v28
					}
				}
				v30 = *memmap.PtrUint8(0x5D4594, 1090117)
				v31 = int32(*memmap.PtrUint8(0x5D4594, 1090117)) * 80
				*memmap.PtrUint32(0x5D4594, uintptr(v31)+1084192) = v27.NetCodeVal
				v32 = int32(v27.Field3680)
				if (v32&1) == 0 || v32&0x20 != 0 {
					v33 = int32(v27.Field2108)
					if uint32(v33) == 0x8000000 {
						*memmap.PtrUint32(0x5D4594, uintptr(v31)+1084196) = 0
					} else {
						*memmap.PtrUint32(0x5D4594, uintptr(v31)+1084196) = uint32(v33)
						*memmap.PtrUint8(0x5D4594, 1090118)++
					}
				} else {
					*memmap.PtrUint32(0x5D4594, uintptr(v31)+1084196) = v27.Field2108 + 0x80000000
				}
				*memmap.PtrUint32(0x5D4594, uintptr(v31)+1084200) = uint32(*(*uint16)(unsafe.Add(v27.C(), 2148)))
				*memmap.PtrUint32(0x5D4594, uintptr(v31)+1084208) = v27.Field3680
				v34 = int32(v30) * 80
				*memmap.PtrUint32(0x5D4594, uintptr(v34)+1084204) = uint32(sub_46E080(v27))
				nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(v34)+1084132)), (*wchar2_t)(unsafe.Add(v27.C(), 4704)))
				sub_46E170((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084132)))
				*memmap.PtrUint8(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084188) = *(*uint8)(unsafe.Add(v27.C(), 2251))
				v35 := nox_xxx_objGetTeamByNetCode_418C80(v27.NetCodeVal)
				v36 := v35
				if v35 != nil && nox_xxx_servObjectHasTeam_419130(v35) != 0 {
					v37 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(v36.ID))))
					if v37 != nil {
						v38 = int32(*(*byte)(unsafe.Add(unsafe.Pointer(v37), 57)))
						v39 = *memmap.PtrUint8(0x5D4594, 1090117)
						*memmap.PtrUint32(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084184) = uint32(v38)
					} else {
						v39 = *memmap.PtrUint8(0x5D4594, 1090117)
						*memmap.PtrUint32(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084184) = math.MaxUint32
					}
				} else {
					v39 = *memmap.PtrUint8(0x5D4594, 1090117)
					*memmap.PtrUint32(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084184) = math.MaxUint32
				}
				*memmap.PtrUint8(0x5D4594, 1090117) = uint8(int8(int32(v39) + 1))
				v26 = j
				if uint32(uint8(int8(int32(v39)+1))) >= v43 {
					break
				}
			}
		}
		for result := nox_common_playerInfoGetFirst_416EA0(); result != nil; result = nox_common_playerInfoGetNext_416EE0(result) {
			v40 = int32(result.Field3680)
			if (v40&1) == 0 || v40&0x20 != 0 {
				if result.Field2108 == 0x8000000 {
					result.Field2108 = 0
				}
			} else {
				result.Field2108 &= math.MaxInt32
			}
		}
	} else if noxflags.HasGame(1024) {
		v1 = math.MinInt32
		v41 := uint32(nox_common_playerInfoCount_416F40())
		v2 := uint32(nox_xxx_getTeamCounter_417DD0())
		*memmap.PtrUint8(0x5D4594, 1090116) = 0
		v42 := v2
		*memmap.PtrUint8(0x5D4594, 1090117) = 0
		*memmap.PtrUint8(0x5D4594, 1090118) = 0
		if noxflags.HasGame(1) && nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
			v41--
		}
		if uint32(*memmap.PtrUint8(0x5D4594, 1090116)) < v2 {
			var v3 *server.Team
			for {
				v4 = math.MaxInt32
				for k := nox_server_teamFirst_418B10(); k != nil; k = nox_server_teamNext_418B60(k) {
					if k.Lessons >= int(v1) && sub_46E130(int32(k.IDVal)) == 0 && k.Lessons < int(v4) {
						v4 = int32(k.Lessons)
						v3 = k
					}
				}
				v6 = int32(*memmap.PtrUint8(0x5D4594, 1090116)) * 56
				*memmap.PtrUint32(0x5D4594, uintptr(v6)+1087252) = uint32(v3.Lessons)
				*memmap.PtrUint32(0x5D4594, uintptr(v6)+1087248) = uint32(v3.IDVal)
				*memmap.PtrUint8(0x5D4594, uintptr(v6)+1087256) = byte(v3.ColorInd)
				nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(v6)+1087204)), &v3.NameBuf[0])
				sub_46E170((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090116))*56)+1087204)))
				*memmap.PtrUint8(0x5D4594, 1090116)++
				v1 = v4
				if uint32(*memmap.PtrUint8(0x5D4594, 1090116)) >= uint32(v42) {
					break
				}
			}
		}
		for l := nox_common_playerInfoGetFirst_416EA0(); l != nil; l = nox_common_playerInfoGetNext_416EE0(l) {
			v8 = int32(l.Field3680)
			if v8&1 != 0 && (v8&0x20) == 0 {
				l.Field2140 += math.MaxUint16
			}
		}
		v9 = -1
		if uint32(*memmap.PtrUint8(0x5D4594, 1090117)) < v41 {
			var v10 *server.Player
			for {
				m = math.MaxInt32
				for v11 := nox_common_playerInfoGetFirst_416EA0(); v11 != nil; v11 = nox_common_playerInfoGetNext_416EE0(v11) {
					if (v11.PlayerInd != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) && int32(v11.Field2140) >= v9 && sub_46E1E0(int32(v11.NetCodeVal)) == 0 && int32(v11.Field2140) < m {
						m = int32(v11.Field2140)
						v10 = v11
					}
				}
				v13 = *memmap.PtrUint8(0x5D4594, 1090117)
				v14 = int32(*memmap.PtrUint8(0x5D4594, 1090117)) * 80
				*memmap.PtrUint32(0x5D4594, uintptr(v14)+1084192) = v10.NetCodeVal
				v15 = int32(v10.Field3680)
				if (v15&1) == 0 || v15&0x20 != 0 {
					*memmap.PtrUint32(0x5D4594, uintptr(v14)+1084196) = v10.Field2140
					*memmap.PtrUint8(0x5D4594, 1090118)++
				} else {
					*memmap.PtrUint32(0x5D4594, uintptr(v14)+1084196) = v10.Field2140 - math.MaxUint16
				}
				*memmap.PtrUint32(0x5D4594, uintptr(v14)+1084200) = uint32(*(*uint16)(unsafe.Add(v10.C(), 2148)))
				*memmap.PtrUint32(0x5D4594, uintptr(v14)+1084208) = v10.Field3680
				v16 = int32(v13) * 80
				*memmap.PtrUint32(0x5D4594, uintptr(v16)+1084204) = uint32(sub_46E080(v10))
				nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(v16)+1084132)), (*wchar2_t)(unsafe.Add(v10.C(), 4704)))
				sub_46E170((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084132)))
				*memmap.PtrUint8(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084188) = *(*uint8)(unsafe.Add(v10.C(), 2251))
				v17 := nox_xxx_objGetTeamByNetCode_418C80(v10.NetCodeVal)
				v18 := v17
				if v17 != nil && nox_xxx_servObjectHasTeam_419130(v17) != 0 {
					v19 := nox_xxx_getTeamByID_418AB0(int32(v18.ID))
					if v19 != nil {
						v20 = int32(v19.IDVal)
						v21 = *memmap.PtrUint8(0x5D4594, 1090117)
						*memmap.PtrUint32(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084184) = uint32(v20)
					} else {
						v21 = *memmap.PtrUint8(0x5D4594, 1090117)
						*memmap.PtrUint32(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084184) = math.MaxUint32
					}
				} else {
					v21 = *memmap.PtrUint8(0x5D4594, 1090117)
					*memmap.PtrUint32(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084184) = math.MaxUint32
				}
				*memmap.PtrUint8(0x5D4594, 1090117) = uint8(int8(int32(v21) + 1))
				v9 = m
				if uint32(uint8(int8(int32(v21)+1))) >= v41 {
					break
				}
			}
		}
		for result := nox_common_playerInfoGetFirst_416EA0(); result != nil; result = nox_common_playerInfoGetNext_416EE0(result) {
			v22 = int32(result.Field3680)
			if v22&1 != 0 {
				if (v22 & 0x20) == 0 {
					result.Field2140 -= math.MaxUint16
				}
			}
		}
	} else {
		sub_46E4E0()
	}
}
func sub_46E080(a1 *server.Player) int32 {
	var (
		v1 int32
		v3 *uint32
	)
	if noxflags.HasGame(32) {
		v1 = int32(a1.NetCodeVal)
		if v1 == int32(*memmap.PtrUint16(0x5D4594, 1090128)) {
			return 2
		}
		if v1 == int32(*memmap.PtrUint16(0x5D4594, 1090130)) {
			return 3
		}
	} else if noxflags.HasGame(64) {
		if a1.NetCodeVal == uint32(*memmap.PtrUint16(0x5D4594, 1090132)) {
			return 4
		}
	} else if noxflags.HasGame(16) {
		v3 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(a1.NetCodeVal).C())
		if v3 != nil {
			if nox_client_drawable_testBuff_4356C0((*client.Drawable)(unsafe.Pointer(v3)), 30) {
				return 1
			}
		}
	}
	return 0
}
func sub_46E130(a1 int32) int32 {
	var (
		v1 int32
		i  *uint8
	)
	v1 = 0
	if int32(*memmap.PtrUint8(0x5D4594, 1090116)) == 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 1087248)); *(*uint32)(unsafe.Pointer(i)) != uint32(a1); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 56)) {
		if uint32(func() int32 {
			p := &v1
			*p++
			return *p
		}()) >= uint32(*memmap.PtrUint8(0x5D4594, 1090116)) {
			return 0
		}
	}
	return 1
}
func sub_46E170(a1 *wchar2_t) *uint16 {
	if a1 == nil || *memmap.PtrInt32(0x5D4594, 1084036) == 0 {
		return nil
	}
	var v1 *uint16
	var v2 uint32
	v1 = a1
	v2 = nox_wcslen(a1)
	var a1a int32 = 0
	nox_xxx_drawGetStringSize_43F840(nil, v1, &a1a, nil, 0)
	if a1a == 0 {
		return nil
	}
	if (a1a + 5) <= *memmap.PtrInt32(0x5D4594, 1084036) {
		return v1
	}
	var v3 *uint16 = (*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*uintptr(v2)))
	for {
		*v3 = 0
		v3 = (*uint16)(unsafe.Add(unsafe.Pointer(v3), -int(unsafe.Sizeof(uint16(0))*1)))
		nox_xxx_drawGetStringSize_43F840(nil, v1, &a1a, nil, 0)
		if (a1a + 5) <= *memmap.PtrInt32(0x5D4594, 1084036) {
			break
		}
	}
	return v1
}
func sub_46E1E0(a1 int32) int32 {
	var (
		v1 int32
		i  *uint8
	)
	v1 = 0
	if int32(*memmap.PtrUint8(0x5D4594, 1090117)) == 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 1084192)); *(*uint32)(unsafe.Pointer(i)) != uint32(a1); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 80)) {
		if uint32(func() int32 {
			p := &v1
			*p++
			return *p
		}()) >= uint32(*memmap.PtrUint8(0x5D4594, 1090117)) {
			return 0
		}
	}
	return 1
}
func sub_46E4E0() {
	var (
		v0  int32
		v1  uint32
		v3  int32
		v5  int32
		v7  int32
		v8  int32
		k   int32
		v12 uint8
		v13 int32
		v14 int32
		v15 int32
		v16 *uint32
		v17 *uint32
		v18 *byte
		v19 int32
		v20 uint8
		v22 int32
		v23 uint32
	)
	v0 = math.MaxInt32
	v1 = uint32(nox_xxx_getTeamCounter_417DD0())
	v24 := v1
	v23 = uint32(nox_common_playerInfoCount_416F40())
	*memmap.PtrUint8(0x5D4594, 1090116) = 0
	*memmap.PtrUint8(0x5D4594, 1090117) = 0
	*memmap.PtrUint8(0x5D4594, 1090118) = 0
	if noxflags.HasGame(1) && nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
		v23--
	}
	if uint32(*memmap.PtrUint8(0x5D4594, 1090116)) < v1 {
		var v2 *server.Team
		for {
			v3 = math.MinInt32
			for i := nox_server_teamFirst_418B10(); i != nil; i = nox_server_teamNext_418B60(i) {
				if i.Lessons <= int(v0) && sub_46E130(int32(i.IDVal)) == 0 && i.Lessons > int(v3) {
					v3 = int32(i.Lessons)
					v2 = i
				}
			}
			v5 = int32(*memmap.PtrUint8(0x5D4594, 1090116)) * 56
			*memmap.PtrUint32(0x5D4594, uintptr(v5)+1087252) = uint32(v2.Lessons)
			*memmap.PtrUint32(0x5D4594, uintptr(v5)+1087248) = uint32(v2.IDVal)
			*memmap.PtrUint8(0x5D4594, uintptr(v5)+1087256) = byte(v2.ColorInd)
			nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(v5)+1087204)), &v2.NameBuf[0])
			sub_46E170((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090116))*56)+1087204)))
			*memmap.PtrUint8(0x5D4594, 1090116)++
			v0 = v3
			if uint32(*memmap.PtrUint8(0x5D4594, 1090116)) >= uint32(v24) {
				break
			}
		}
	}
	for j := nox_common_playerInfoGetFirst_416EA0(); j != nil; j = nox_common_playerInfoGetNext_416EE0(j) {
		v7 = int32(j.Field3680)
		if v7&1 != 0 && (v7&0x20) == 0 {
			j.Lessons -= math.MaxUint16
		}
	}
	v8 = math.MaxInt32
	if uint32(*memmap.PtrUint8(0x5D4594, 1090117)) < v23 {
		var v9 *server.Player
		for {
			k = math.MinInt32
			for v10 := nox_common_playerInfoGetFirst_416EA0(); v10 != nil; v10 = nox_common_playerInfoGetNext_416EE0(v10) {
				if (v10.PlayerInd != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) && v10.Lessons <= v8 && sub_46E1E0(int32(v10.NetCodeVal)) == 0 && v10.Lessons > k {
					k = v10.Lessons
					v9 = v10
				}
			}
			v12 = *memmap.PtrUint8(0x5D4594, 1090117)
			v13 = int32(*memmap.PtrUint8(0x5D4594, 1090117)) * 80
			*memmap.PtrUint32(0x5D4594, uintptr(v13)+1084192) = v9.NetCodeVal
			v14 = int32(v9.Field3680)
			if (v14&1) == 0 || v14&0x20 != 0 {
				*memmap.PtrUint32(0x5D4594, uintptr(v13)+1084196) = uint32(v9.Lessons)
				*memmap.PtrUint8(0x5D4594, 1090118)++
			} else {
				*memmap.PtrUint32(0x5D4594, uintptr(v13)+1084196) = uint32(v9.Lessons + math.MaxUint16)
			}
			*memmap.PtrUint32(0x5D4594, uintptr(v13)+1084200) = uint32(*(*uint16)(unsafe.Add(v9.C(), 2148)))
			v15 = int32(v12) * 80
			*memmap.PtrUint32(0x5D4594, uintptr(v15)+1084204) = uint32(sub_46E080(v9))
			*memmap.PtrUint32(0x5D4594, uintptr(v15)+1084208) = v9.Field3680
			nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(v15)+1084132)), (*wchar2_t)(unsafe.Add(v9.C(), 4704)))
			sub_46E170((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084132)))
			*memmap.PtrUint8(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084188) = *(*uint8)(unsafe.Add(v9.C(), 2251))
			v16 = nox_xxx_objGetTeamByNetCode_418C80(v9.NetCodeVal)
			v17 = v16
			if v16 != nil && nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Pointer(v16))) != 0 {
				v18 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v17), 4))))))
				if v18 != nil {
					v19 = int32(*(*byte)(unsafe.Add(unsafe.Pointer(v18), 57)))
					v20 = *memmap.PtrUint8(0x5D4594, 1090117)
					*memmap.PtrUint32(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084184) = uint32(v19)
				} else {
					v20 = *memmap.PtrUint8(0x5D4594, 1090117)
					*memmap.PtrUint32(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084184) = math.MaxUint32
				}
			} else {
				v20 = *memmap.PtrUint8(0x5D4594, 1090117)
				*memmap.PtrUint32(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1090117))*80)+1084184) = math.MaxUint32
			}
			*memmap.PtrUint8(0x5D4594, 1090117) = uint8(int8(int32(v20) + 1))
			v8 = k
			if uint32(uint8(int8(int32(v20)+1))) >= v23 {
				break
			}
		}
	}
	for result := nox_common_playerInfoGetFirst_416EA0(); result != nil; result = nox_common_playerInfoGetNext_416EE0(result) {
		v22 = int32(result.Field3680)
		if v22&1 != 0 {
			if (v22 & 0x20) == 0 {
				result.Lessons += math.MaxUint16
			}
		}
	}
}
func sub_46F060(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	return 0
}
func nox_xxx_Proc_46F070(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	return 0
}
func sub_46FAE0() {
	var (
		yTop int32
		v1   int32
	)
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 1088996))*4+1090060)))), &v1, &yTop)
	yTop += int32(dword_587000_145672*uint32(*(*int16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*memmap.PtrPtr(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 1088996))*4+1090060), 32)), 2))) + uint32(int32(*(*int16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*memmap.PtrPtr(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 1088996))*4+1090060), 32)), 2)))/2))
	nox_client_drawSetColor_434460(int32(nox_color_yellow_2589772))
	nox_xxx_drawPointMB_499B70(v1+1, yTop, 3)
}
func sub_46FE60(a1 int32) uint8 {
	var (
		result uint8
		v2     uint8
	)
	result = 0
	v2 = 0
	if int32(*memmap.PtrUint8(0x5D4594, 1090116)) == 0 {
		return 0
	}
	for *memmap.PtrUint32(0x5D4594, uintptr(int32(v2)*56)+1087248) != uint32(a1) {
		v2 = func() uint8 {
			p := &result
			*p++
			return *p
		}()
		if int32(result) >= int32(*memmap.PtrUint8(0x5D4594, 1090116)) {
			return 0
		}
	}
	return result
}
func sub_46FEB0(a1 uint8) uint8 {
	return *memmap.PtrUint8(0x587000, uintptr((int32(*memmap.PtrUint8(0x5D4594, uintptr(int32(a1)*56)+1087256))%10)*8)+145584)
}
func sub_46FEE0() int8 {
	var (
		v0 int32
		v1 int8
		i  *uint8
		v4 int32
		v5 int32
		v6 *uint8
		v7 int32
		v8 *uint8
	)
	v0 = 0
	v1 = 1
	if int32(*memmap.PtrUint8(0x5D4594, 1090117)) == 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 1084192)); *(*uint32)(unsafe.Pointer(i)) != nox_player_netCode_85319C; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 80)) {
		if uint32(func() int32 {
			p := &v0
			*p++
			return *p
		}()) >= uint32(*memmap.PtrUint8(0x5D4594, 1090117)) {
			return 0
		}
	}
	v4 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v0*80)+1084196))
	if !noxflags.HasGame(1024) {
		v7 = int32(*memmap.PtrUint8(0x5D4594, 1090117))
		if int32(*memmap.PtrUint8(0x5D4594, 1090117)) == 0 {
			return v1
		}
		v8 = (*uint8)(memmap.PtrOff(0x5D4594, 1084196))
		for {
			if *(*uint32)(unsafe.Pointer(v8)) > uint32(v4) {
				v1++
			}
			v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 80))
			v7--
			if v7 == 0 {
				break
			}
		}
		return v1
	}
	v5 = int32(*memmap.PtrUint8(0x5D4594, 1090117))
	if int32(*memmap.PtrUint8(0x5D4594, 1090117)) == 0 {
		return v1
	}
	v6 = (*uint8)(memmap.PtrOff(0x5D4594, 1084196))
	for {
		if *(*uint32)(unsafe.Pointer(v6)) < uint32(v4) {
			v1++
		}
		v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 80))
		v5--
		if v5 == 0 {
			break
		}
	}
	return v1
}
func sub_46FF70(a1 int32) int8 {
	var (
		v1 int8
		v2 int32
		v3 *uint8
		v5 int32
		v6 *uint8
	)
	v1 = 1
	if !noxflags.HasGame(1024) {
		v5 = int32(*memmap.PtrUint8(0x5D4594, 1090116))
		if int32(*memmap.PtrUint8(0x5D4594, 1090116)) == 0 {
			return v1
		}
		v6 = (*uint8)(memmap.PtrOff(0x5D4594, 1087252))
		for {
			if *(*uint32)(unsafe.Pointer(v6)) > uint32(a1) {
				v1++
			}
			v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 56))
			v5--
			if v5 == 0 {
				break
			}
		}
		return v1
	}
	v2 = int32(*memmap.PtrUint8(0x5D4594, 1090116))
	if int32(*memmap.PtrUint8(0x5D4594, 1090116)) == 0 {
		return v1
	}
	v3 = (*uint8)(memmap.PtrOff(0x5D4594, 1087252))
	for {
		if *(*uint32)(unsafe.Pointer(v3)) < uint32(a1) {
			v1++
		}
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 56))
		v2--
		if v2 == 0 {
			break
		}
	}
	return v1
}
func sub_46FFD0() uint8 {
	var (
		result uint8
		v1     int32
		v2     *uint8
		v3     *byte
		v4     *uint8
		v5     uint8
		v6     uint8
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    *wchar2_t
		v13    int32
		v15    uint8
		v16    float32
		v17    int32
		v18    int32
		v19    int32
		v20    int32
		v21    int32
		v22    int32
		v23    int32
		v24    int32
	)
	_ = v24
	var v25 float32
	var v26 int32
	var v27 int32
	var v28 int32
	var v29 int32
	var v30 int32
	sub_46DB80()
	sub_46F8F0(0, 0)
	result = *memmap.PtrUint8(0x5D4594, 1090117)
	v23 = 0
	if int32(*memmap.PtrUint8(0x5D4594, 1090117)) != 0 {
		v1 = 1
		v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1084184))
		for {
			v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2))))))
			v4 = v3
			if v3 != nil && *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1198)) != 0 {
				if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 24)))&1 != 0 {
					*(*uint8)(unsafe.Pointer(&v21)) = 9
				} else if *(*int32)(unsafe.Pointer(v2)) == -1 {
					*(*uint8)(unsafe.Pointer(&v21)) = 4
				} else {
					v5 = sub_46FE60(int32(*(*uint32)(unsafe.Pointer(v2))))
					*(*uint8)(unsafe.Pointer(&v21)) = sub_46FEB0(v5)
				}
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) == nox_player_netCode_85319C {
					dword_587000_145672 = uint32(*(*int16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1090060), 32)), 46)))
					*memmap.PtrUint32(0x5D4594, 1088996) = 0
				}
				v6 = uint8(int8(v21))
				sub_46DC30((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1090060)), uint8(int8(v21)), (*wchar2_t)(memmap.PtrOff(0x587000, 147828)), (*uint8)(unsafe.Add(unsafe.Pointer(v2), -52)))
				sub_46DC30((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1090076)), v6, (*wchar2_t)(memmap.PtrOff(0x587000, 147836)), *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 4816)))
				v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
				v8 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 2282)))
				*(*uint8)(unsafe.Pointer(&v22)) = 4
				if uint32(v7) == nox_player_netCode_85319C {
					v9 = sub_470CD0()
					v24 = v9
					v25 = float32(float64(v9))
					v10 = sub_470CC0()
					v24 = v10
					v16 = float32(float64(v10) / float64(v25) * 100.0)
					v8 = int32(v16)
				}
				if v8 > 25 {
					if v8 <= 50 {
						*(*uint8)(unsafe.Pointer(&v22)) = 15
					}
				} else {
					*(*uint8)(unsafe.Pointer(&v22)) = 6
				}
				sub_46DC30((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1090084)), uint8(int8(v22)), (*wchar2_t)(memmap.PtrOff(0x587000, 147844)), v8)
				sub_46DC30((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1090092)), v6, (*wchar2_t)(memmap.PtrOff(0x587000, 147856)), *memmap.PtrUint32(0x5D4594, uintptr(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 4)))*4)+1084056))
				v11 = sub_46FB50(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*5))), (*uint8)(unsafe.Pointer(&v26)))
				sub_46DC60(*memmap.PtrInt32(0x5D4594, 1090068), uint8(int8(v26)), int32(uintptr(unsafe.Pointer(v11))))
				if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 4824))) != 0 {
					nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, 1090068)))), &v19, &v18)
					nox_window_get_size((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1090068)), &v28, &v27)
					v12 := *(*unsafe.Pointer)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1090068), 32))
					v19 += 5
					v18 = v18 + int32(*(*int16)(unsafe.Add(v12, 2)))/2 + int32(*(*int16)(unsafe.Add(v12, 2)))*v1 - 1
					nox_client_drawSetColor_434460(int32(nox_color_white_2523948))
					nox_video_drawCircleColored_4C3270(v19, v18, 2, int32(nox_color_white_2523948))
					nox_client_drawAddPoint_49F500(v19+2, v18)
					nox_client_drawAddPoint_49F500(v19+9, v18)
					nox_client_drawLineFromPoints_49E4B0()
					nox_client_drawAddPoint_49F500(v19+9, v18)
					nox_client_drawAddPoint_49F500(v19+9, v18+3)
					nox_client_drawLineFromPoints_49E4B0()
					nox_client_drawAddPoint_49F500(v19+7, v18)
					nox_client_drawAddPoint_49F500(v19+7, v18+2)
					nox_client_drawLineFromPoints_49E4B0()
				}
				if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 4825))) != 0 {
					nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, 1090068)))), &v17, &v20)
					nox_window_get_size((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1090068)), &v30, &v29)
					v13 = v17 + 5
					v14 := *(*unsafe.Pointer)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1090068), 32))
					v15 = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 4824))
					v17 += 5
					if int32(v15) == 1 {
						v17 = v13 + 15
					}
					v20 = v20 + int32(*(*int16)(unsafe.Add(v14, 2)))/2 + int32(*(*int16)(unsafe.Add(v14, 2)))*v1 - 1
					nox_client_drawSetColor_434460(int32(nox_color_yellow_2589772))
					nox_video_drawCircleColored_4C3270(v17, v20, 2, int32(nox_color_yellow_2589772))
					nox_client_drawAddPoint_49F500(v17+2, v20)
					nox_client_drawAddPoint_49F500(v17+9, v20)
					nox_client_drawLineFromPoints_49E4B0()
					nox_client_drawAddPoint_49F500(v17+9, v20)
					nox_client_drawAddPoint_49F500(v17+9, v20+3)
					nox_client_drawLineFromPoints_49E4B0()
					nox_client_drawAddPoint_49F500(v17+7, v20)
					nox_client_drawAddPoint_49F500(v17+7, v20+2)
					nox_client_drawLineFromPoints_49E4B0()
				}
				v1++
			}
			result = uint8(int8(v23 + 1))
			v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 80))
			v23++
			if v23 >= int32(*memmap.PtrUint8(0x5D4594, 1090117)) {
				break
			}
		}
		dword_587000_145664 = 1
	} else {
		dword_587000_145664 = 1
	}
	return result
}
func sub_470580() int32 {
	return bool2int32(dword_5d4594_1090120 != 0 && wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_1090048) != 1)
}
func sub_4705B0() {
	if dword_5d4594_1090048 != nil {
		if wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_1090048) != 0 {
			nox_window_set_hidden(dword_5d4594_1090048, 0)
		}
		dword_5d4594_1090120 = 0
		sub_4703F0()
	}
}
func sub_4705F0(a1 int8, a2 int8, a3 int16) int8 {
	var result int8
	result = a2
	if int32(a2) == 1 {
		result = a1
		if int32(a1) != 2 && int32(a1) != 0 {
			if int32(a1) == 1 {
				result = int8(a3)
				*memmap.PtrUint16(0x5D4594, 1090128) = uint16(a3)
			}
		} else {
			*memmap.PtrUint16(0x5D4594, 1090128) = 0
		}
	} else if int32(a2) == 2 {
		result = a1
		if int32(a1) != 2 && int32(a1) != 0 {
			if int32(a1) == 1 {
				*memmap.PtrUint16(0x5D4594, 1090130) = uint16(a3)
			}
		} else {
			*memmap.PtrUint16(0x5D4594, 1090130) = 0
		}
	}
	return result
}
func sub_470650(a1 int8, a2 int16) int8 {
	var result int8
	result = a1
	if int32(a1) != 0 && int32(a1) != 1 {
		if int32(a1) == 4 || int32(a1) == 2 {
			result = int8(a2)
			*memmap.PtrUint16(0x5D4594, 1090132) = uint16(a2)
		}
	} else {
		*memmap.PtrUint16(0x5D4594, 1090132) = 0
	}
	return result
}
func sub_470680() int32 {
	var result int32
	result = 0
	*memmap.PtrUint16(0x5D4594, 1090128) = 0
	*memmap.PtrUint16(0x5D4594, 1090130) = 0
	*memmap.PtrUint16(0x5D4594, 1090132) = 0
	return result
}
func sub_4706A0() int32 {
	return bool2int32(dword_5d4594_1090048 != nil && dword_5d4594_1090120 != 0)
}
func nox_xxx_playerGet_470A90() int32 {
	return int32(dword_5d4594_1096252)
}
func nox_xxx_cliShowHideTubes_470AA0(a1 int32) {
	dword_5d4594_1096252 = uint32(a1)
	if *memmap.PtrUint32(0x5D4594, 1093176) != 0 {
		if a1 != 0 {
			nox_window_set_hidden(nox_windows_arr_1093036[2].Win, 0)
			nox_window_set_hidden(nox_windows_arr_1093036[3].Win, 0)
		} else {
			nox_window_set_hidden(nox_windows_arr_1093036[2].Win, 1)
			nox_window_set_hidden(nox_windows_arr_1093036[3].Win, 1)
		}
	}
}
func nox_xxx_guiHealthManaColorInit_470B00() *uint8 {
	var result *uint8
	dword_5d4594_1090284 = nox_color_rgb_4344A0(math.MaxUint8, 0, 0)
	dword_5d4594_1090280 = nox_color_rgb_4344A0(100, 0, 0)
	*memmap.PtrUint32(0x5D4594, 1091964) = nox_color_rgb_4344A0(0, math.MaxUint8, 0)
	*memmap.PtrUint32(0x5D4594, 1092992) = nox_color_rgb_4344A0(0, 100, 0)
	nox_windows_arr_1093036[0].Color1 = dword_5d4594_1090284
	nox_windows_arr_1093036[0].Color2 = dword_5d4594_1090280
	nox_windows_arr_1093036[1].Color1 = nox_color_rgb_4344A0(0, 0, math.MaxUint8)
	nox_windows_arr_1093036[1].Color2 = nox_color_rgb_4344A0(0, 0, 100)
	nox_windows_arr_1093036[4].Color1 = nox_color_rgb_4344A0(240, 0, 240)
	nox_windows_arr_1093036[4].Color2 = nox_color_rgb_4344A0(50, 0, 50)
	nox_windows_arr_1093036[5].Color1 = nox_color_rgb_4344A0(math.MaxUint8, 0, math.MaxUint8)
	nox_windows_arr_1093036[5].Color2 = nox_color_rgb_4344A0(50, 0, 50)
	nox_windows_arr_1093036[6].Color1 = nox_color_rgb_4344A0(math.MaxUint8, 0, math.MaxUint8)
	nox_windows_arr_1093036[6].Color2 = nox_color_rgb_4344A0(50, 0, 50)
	result = (*uint8)(memmap.PtrOff(0x5D4594, 1094732))
	for {
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), -int(4*384))) = 0
		*(*uint32)(unsafe.Pointer(result)) = 0
		result = (*uint8)(unsafe.Add(unsafe.Pointer(result), 24))
		if int32(uintptr(unsafe.Pointer(result))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1096268))) {
			break
		}
	}
	return result
}
func sub_470C40(a1 int32) int32 {
	var result int32
	dword_5d4594_1096264 = uint32(a1)
	if a1 != 0 {
		result = int32(*memmap.PtrUint32(0x5D4594, 1091964))
		nox_windows_arr_1093036[0].Color1 = *memmap.PtrUint32(0x5D4594, 1091964)
		nox_windows_arr_1093036[0].Color2 = *memmap.PtrUint32(0x5D4594, 1092992)
	} else {
		result = int32(dword_5d4594_1090280)
		nox_windows_arr_1093036[0].Color1 = dword_5d4594_1090284
		nox_windows_arr_1093036[0].Color2 = dword_5d4594_1090280
	}
	return result
}
func nox_xxx_cliSetTotalHealth_470C80(a1 int32, a2 int32) int32 {
	var result int32
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2247)) = uint32(a2)
	}
	result = a1
	nox_windows_arr_1093036[0].Field8 = uint32(a2)
	nox_windows_arr_1093036[0].Field4 = uint32(a1)
	dword_5d4594_1096260 = 32
	return result
}
func sub_470CB0(a1 int32) int32 {
	var result int32
	result = a1
	nox_windows_arr_1093036[0].Field4 = uint32(a1)
	return result
}
func sub_470CC0() int32 {
	return int32(nox_windows_arr_1093036[0].Field4)
}
func sub_470CD0() int32 {
	return int32(nox_windows_arr_1093036[0].Field8)
}
func nox_xxx_cliSetManaAndMax_470CE0(a1 int32, a2 int32) int32 {
	var result int32
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2243)) = uint32(a2)
	}
	result = a1
	nox_windows_arr_1093036[1].Field8 = uint32(a2)
	nox_windows_arr_1093036[1].Field4 = uint32(a1)
	dword_5d4594_1096260 = 32
	return result
}
func nox_xxx_cliSetMana_470D10(a1 int32) int32 {
	var result int32
	result = a1
	nox_windows_arr_1093036[1].Field4 = uint32(a1)
	return result
}
func sub_470D20(a1 int32, a2 int32) int32 {
	var result int32
	result = a1
	nox_windows_arr_1093036[4].Field4 = uint32(a1)
	nox_windows_arr_1093036[4].Field8 = uint32(a2)
	if a1 != a2 {
		result = nox_xxx_setKeybTimeout_4160D0(17)
	}
	return result
}
func sub_470D70() {
	nox_window_set_hidden(nox_windows_arr_1093036[5].Win, 1)
	nox_window_set_hidden(nox_windows_arr_1093036[6].Win, 1)
}
func sub_470D90(a1 int32, a2 int32) int32 {
	var result int32
	nox_window_set_hidden(nox_windows_arr_1093036[5].Win, 0)
	nox_window_set_hidden(nox_windows_arr_1093036[6].Win, 0)
	result = a1
	nox_windows_arr_1093036[5].Field4 = uint32(a1)
	nox_windows_arr_1093036[5].Field8 = uint32(a2)
	nox_windows_arr_1093036[6].Field4 = uint32(a1)
	nox_windows_arr_1093036[6].Field8 = uint32(a2)
	return result
}
func nox_xxx_cliGetMana_470DD0() int32 {
	return int32(nox_windows_arr_1093036[1].Field4)
}
func sub_470DE0() int32 {
	var (
		result int32
		v1     int32
		v2     int32
		v3     int32
	)
	result = int32(nox_player_netCode_85319C)
	if nox_player_netCode_85319C == 0 {
		return result
	}
	v1 = int32(nox_windows_arr_1093036[0].Field4)
	if nox_windows_arr_1093036[0].Field4 < 1 {
		return result
	}
	result = int32(nox_windows_arr_1093036[0].Field8 * 3435973838)
	v2 = int32(nox_windows_arr_1093036[0].Field8 * 2 / 5)
	v3 = v2
	if nox_windows_arr_1093036[0].Field4 >= uint32(v2) {
		return result
	}
	*memmap.PtrUint32(0x5D4594, 1091960) = gameFPS()/3 + nox_windows_arr_1093036[0].Field4*((gameFPS()*3)>>2)/uint32(v2)
	result = bool2int32(nox_xxx_checkKeybTimeout_4160F0(4, *memmap.PtrUint32(0x5D4594, 1091960)-1))
	if result != 0 {
		nox_xxx_clientPlaySoundSpecial_452D80(896, (v3-v1)*66/v3+33)
		result = nox_xxx_setKeybTimeout_4160D0(4)
	}
	return result
}
func sub_470E90(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	switch a2 {
	case 5:
		nox_client_invAlterWeapon_4672C0()
		return 1
	case 8, 12, 16:
		return 0
	default:
		return 1
	}
}
func nox_win_init_cur_weapon(a1 *gui.Window, a2, a3, w, h int) {
	nox_windows_arr_1093036[4].Win = nox_window_new(a1, 0x408, a2, a3, w, h, nil)
	nox_window_set_all_funcs(nox_windows_arr_1093036[4].Win, sub_470E90, sub_470F40_draw, sub_4710B0)
	nox_windows_arr_1093036[4].Win.WidgetData = unsafe.Pointer(uintptr(4))
}
func sub_470F40_draw(win *gui.Window, draw *gui.WindowData) int {
	var (
		v4  int32
		v5  int32
		v6  int32
		v8  float64
		v9  float64
		v12 int32
		v14 int32
		v16 int32
		v17 int32
		v18 int32
	)
	v18 = 1
	v3 := &nox_windows_arr_1093036[int32(uintptr(win.WidgetData))]
	nox_client_wndGetPosition_46AA60(win, &v14, &v16)
	var w int32
	var h int32
	nox_window_get_size(win, &w, &h)
	v4 = w / 2
	v17 = w/2 + v14
	v5 = h/2 + v16
	v6 = int32(v3.Field8)
	if v6 != 0 {
		v12 = int32(v3.Field4<<8) / v6
	} else {
		v18 = 0
	}
	v3.Color2 = v3.Color1
	if v18 == 0 {
		sub_465D50_draw(unsafe.Pointer(win))
		return 1
	}
	if v12 >= 256 {
		v7 := sub_4678D0()
		if v7 != nil {
			v8 = float64(*(*uint16)(unsafe.Add(v7, 292)))
			v9 = float64(*(*uint16)(unsafe.Add(v7, 294)))
			if v8 < v9**mem_getDoublePtr(0x581450, 9608) {
				v3.Color2 = *memmap.PtrUint32(0x85B3FC, 940)
				v12 = 1
			} else if v8 < v9*qword_581450_9544 {
				v3.Color2 = nox_color_yellow_2589772
				v12 = 1
			} else {
				v18 = 0
				v12 = 1
			}
		} else {
			v18 = 0
			v12 = 1
		}
	}
	if v18 != 0 {
		nox_client_drawEnableAlpha_434560(1)
		nox_client_drawSetAlpha_434580(0x40)
		sub_4AE6F0(v17, v5, v4, v12, int32(v3.Color2))
		nox_client_drawEnableAlpha_434560(0)
	}
	sub_465D50_draw(unsafe.Pointer(win))
	return 1
}
func sub_471250(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1  = (*uint32)(win.C())
		v1  *uint8
		v2  int32
		v3  *uint8
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 float64
		v13 int32
		v14 *uint8
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 *uint8
		v21 float32
		v22 float32
	)
	v20 = (*uint8)(unsafe.Pointer(&nox_windows_arr_1093036[*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8))]))
	v1 = v20
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(a1)), &v18, &v17)
	v2 = 1
	if *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*2)) >= 1 {
		v15 = 1
		v5 = nox_xxx_bookGet_430B40_get_mouse_prev_seq()
		v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*2)))
		v19 = v5
		if v6 > 30 {
			v15 = 0
			v2 = 0
		}
		v7 = (v2+61)/v6 - v2
		v8 = 61 - v7
		v22 = 0.001
		v16 = 0
		v21 = float32(float64(v2-v6*((v2+61)/v6)+61) / float64(v6))
		if v6 <= 0 {
			return 1
		}
		for {
			if uint32(v16) >= *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*1)) {
				v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*4)))
			} else {
				v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3)))
			}
			v10 = v8
			v8 -= v7 + v2
			v11 = v7
			if v7 <= 0 {
				v11 = 1
			}
			v12 = float64(v22 + v21)
			v22 = float32(v12)
			if v12 >= qword_581450_9512 {
				v8--
				v10--
				v11++
				v22 = float32(float64(v22) - qword_581450_9512)
			}
			nox_client_drawSetColor_434460(v9)
			nox_client_drawEnableAlpha_434560(1)
			if v10 < 0 {
				v13 = -v10
				v10 = 0
				v11 -= v13
			}
			if v11 > 0 {
				v14 = (*uint8)(memmap.PtrOff(0x587000, uintptr(v10*8)+147905))
				for {
					if int32(uintptr(unsafe.Pointer(v14))) >= int32(uintptr(memmap.PtrOff(0x587000, 148393))) {
						break
					}
					if *(*uint32)(unsafe.Add(unsafe.Pointer(v14), 3)) != uint32(v19) {
						nox_client_drawRectFilledOpaque_49CE30(v18+int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v14), -1))), v17+int32(*v14), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v14), 1))), 1)
						*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 3)) = uint32(v19)
					}
					v14 = (*uint8)(unsafe.Add(unsafe.Pointer(v14), 8))
					v11--
					if v11 <= 0 {
						break
					}
				}
			}
			nox_client_drawEnableAlpha_434560(0)
			if uint32(func() int32 {
				p := &v16
				*p++
				return *p
			}()) >= *(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*2)) {
				break
			}
			v2 = v15
			v1 = v20
		}
		return 1
	} else {
		nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3))))
		nox_client_drawEnableAlpha_434560(1)
		v3 = (*uint8)(memmap.PtrOff(0x587000, 147905))
		for {
			nox_client_drawRectFilledOpaque_49CE30(v18+int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), -1))), v17+int32(*v3), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 1))), 1)
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 8))
			if int32(uintptr(unsafe.Pointer(v3))) >= int32(uintptr(memmap.PtrOff(0x587000, 148393))) {
				break
			}
		}
		nox_client_drawEnableAlpha_434560(0)
		return 1
	}
}
func sub_471450(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1p         = win
		v3          int32
		WideCharStr [4]wchar2_t
	)
	v1 := a1p
	nox_itow(int32(nox_windows_arr_1093036[*(*uint32)(unsafe.Add(unsafe.Pointer(a1p), 4*8))].Field4), &WideCharStr[0], 10)
	nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
	nox_xxx_drawGetStringSize_43F840(dword_5d4594_1096288, &WideCharStr[0], &v3, nil, 0)
	var v4, a1 int32
	nox_client_wndGetPosition_46AA60(v1, &v4, &a1)
	nox_xxx_drawString_43F6E0(dword_5d4594_1096288, &WideCharStr[0], v4-v3/2+8, int32(a1)+1)
	return 1
}
func nox_xxx_guiBottleSlotDrawFn_471A80(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1p = win
		v2  int32
		v4  int32
		v5  *int16
		v6  int32
		v9  [8]wchar2_t
	)
	v1 := int32(uintptr(a1p.WidgetData))
	var v8, a1 int32
	nox_client_wndGetPosition_46AA60(a1p, &v8, &a1)
	v2 = v1 * 536
	if int32(*memmap.PtrUint16(0x5D4594, uintptr(v2)+1090312)) != 0 {
		v3 := *memmap.PtrPtr(0x5D4594, uintptr(v2)+1090296)
		if v3 != nil {
			*(*uint32)(unsafe.Add(v3, 12)) = uint32(v8 + 14)
			*(*int32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, uintptr(v2)+1090296), 16)) = a1 + 15
			ccall.AsFunc[client.ObjectDrawFunc](*(*unsafe.Pointer)(unsafe.Add(*memmap.PtrPtr(0x5D4594, uintptr(v2)+1090296), 300)))((*noxrender.Viewport)(memmap.PtrOff(0x5D4594, 1091908)), AsDrawableP(*memmap.PtrPtr(0x5D4594, uintptr(v2)+1090296)))
		}
		nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
		nox_swprintf(&v9[0], internWStr("%d"), *memmap.PtrUint16(0x5D4594, uintptr(v2)+1090312))
		v4 = nox_xxx_guiFontHeightMB_43F320(dword_5d4594_1096288)
		nox_xxx_drawString_43F6E0(dword_5d4594_1096288, &v9[0], v8-2, a1-v4+10)
	}
	v5 = mem_getI16Ptr(0x5D4594, uint32(v2)+1090300)
	if v5 != nil {
		v6 = nox_xxx_guiFontHeightMB_43F320(dword_5d4594_1096288)
		nox_xxx_drawString_43F6E0(dword_5d4594_1096288, (*wchar2_t)(unsafe.Pointer(v5)), v8-2, a1-v6+33)
	}
	return 1
}
func nox_xxx_guiBottleSlotProc_471B90(a1 *gui.Window, a2, p3, p4 uintptr) uintptr {
	switch a2 {
	case 5:
		if *memmap.PtrUint32(0x5D4594, uintptr(a1.WidgetData)*536+1090308) != 0 {
			nox_xxx_cliUseCurePoison_4674E0(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1.WidgetData)*536+1090308)))
		}
		return 1
	case 8, 12, 16:
		return 0
	default:
		return 1
	}
}
func nox_xxx_drawHealthManaBar_471C00(a1 *gui.Window, draw *gui.WindowData) int {
	var (
		v3 int32
		v4 int32
		v5 int32
		v7 int32
	)
	v1 := int32(uintptr(a1.WidgetData))
	v7 = v1
	v2 := &nox_windows_arr_1093036[v1]
	if nox_xxx_clientIsObserver_4372E0() != 0 || nox_gameDisableMapDraw_5d4594_2650672 != 0 || noxflags.HasGame(9437184) {
		return 1
	}
	if v1 != 0 {
		v3 = nox_win_width/2 + 21
	} else {
		v3 = nox_win_width/2 + 15
	}
	v4 = nox_win_height/2 - 48
	v5 = int32(v2.Field4 * 48 / v2.Field8)
	nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
	nox_client_drawRectFilledOpaque_49CE30(v3, v4, 2, 48)
	nox_client_drawSetColor_434460(int32(v2.Color1))
	nox_client_drawRectFilledOpaque_49CE30(v3, v4-v5+48, 2, v5)
	if v7 != 0 {
		nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 944))
	} else if dword_5d4594_1096264 != 0 {
		nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 984))
	} else {
		nox_client_drawSetColor_434460(int32(nox_color_violet_2598268))
	}
	nox_client_drawBorderLines_49CC70(v3-1, v4-1, 4, 50)
	return 1
}
func sub_472080() int32 {
	var result int32
	result = int32(nox_windows_arr_1093036[4].Field4)
	if nox_windows_arr_1093036[4].Field4 == nox_windows_arr_1093036[4].Field8 {
		return result
	}
	result = bool2int32(sub_416120(0x11))
	if result != 0 {
		result = 0x64 / int32(gameFPS())
		nox_windows_arr_1093036[4].Field4 += uint32(0x64 / int32(gameFPS()))
	}
	return result
}
func sub_4720C0(xLeft int32, a2 int32) int32 {
	nox_client_drawPixel_49EFA0(xLeft+1, a2)
	nox_client_drawRectFilledOpaque_49CE30(xLeft, a2+1, 3, 1)
	nox_client_drawPixel_49EFA0(xLeft+1, a2+2)
	return 0
}
func nox_xxx_guiHealthManaTubeProc_472100(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	var v3 int32
	switch a2 {
	case 7:
		v3 = bool2int32(dword_5d4594_1096252 == 1)
		dword_5d4594_1096252 = 1 - dword_5d4594_1096252
		nox_window_set_hidden(nox_windows_arr_1093036[2].Win, v3)
		if int32(*memmap.PtrUint8(0x85B3FC, 12254)) != 0 {
			nox_window_set_hidden(nox_windows_arr_1093036[3].Win, bool2int32(dword_5d4594_1096252 == 0))
		}
		nox_xxx_clientPlaySoundSpecial_452D80(901, 100)
		return 1
	case 8, 12, 16:
		return 0
	default:
		return 1
	}
}
func sub_4721A0(a1 int32) int32 {
	if a1 != 0 {
		return nox_window_set_hidden(dword_5d4594_1090276, 0)
	} else {
		return nox_window_set_hidden(dword_5d4594_1090276, 1)
	}
}
func nox_xxx_cliPrepareGameplay2_4721D0() int32 {
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1090276)
	nox_xxx_windowDestroyMB_46C4E0(nox_windows_arr_1093036[2].Win)
	if nox_windows_arr_1093036[3].Win != nil {
		nox_xxx_windowDestroyMB_46C4E0(nox_windows_arr_1093036[3].Win)
	}
	nox_xxx_guiHealthManaInit_4714E0()
	sub_472310()
	return sub_4721A0(nox_client_getRenderGUI())
}
func nox_client_quickHealthPotion_472220() {
	if nox_xxx_guiCursor_477600() == 0 {
		if *memmap.PtrUint32(0x5D4594, 1090308) != 0 {
			nox_xxx_cliUseCurePoison_4674E0(*memmap.PtrInt32(0x5D4594, 1090308))
		}
	}
}
func nox_client_quickManaPotion_472240() {
	if nox_xxx_guiCursor_477600() == 0 {
		if *memmap.PtrUint32(0x5D4594, 1090844) != 0 {
			nox_xxx_cliUseCurePoison_4674E0(*memmap.PtrInt32(0x5D4594, 1090844))
		}
	}
}
func nox_client_quickCurePoisonPotion_472260() {
	if nox_xxx_guiCursor_477600() == 0 {
		if *memmap.PtrUint32(0x5D4594, 1091380) != 0 {
			nox_xxx_cliUseCurePoison_4674E0(*memmap.PtrInt32(0x5D4594, 1091380))
		}
	}
}
func sub_472280() {
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
		return
	}
	v1 := sub_42E8E0(38, 1)
	nox_wcsncpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1091372)), v1, 3)
	*memmap.PtrUint16(0x5D4594, 1091378) = 0
	v2 := sub_42E8E0(36, 1)
	nox_wcsncpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1090300)), v2, 3)
	*memmap.PtrUint16(0x5D4594, 1090306) = 0
	if int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))) == 0 {
		return
	}
	v3 := sub_42E8E0(37, 1)
	nox_wcsncpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1090836)), v3, 3)
	*memmap.PtrUint16(0x5D4594, 1090842) = 0
}
func sub_472310() {
	*memmap.PtrUint16(0x5D4594, 1091384) = uint16(int16(sub_467850(int32(dword_5d4594_1096276))))
	*memmap.PtrUint16(0x5D4594, 1090848) = uint16(int16(sub_467850(int32(dword_5d4594_1096272))))
	*memmap.PtrUint16(0x5D4594, 1091384) = uint16(int16(sub_467850(int32(dword_5d4594_1096276))))
	*memmap.PtrUint16(0x5D4594, 1090312) = uint16(int16(sub_467850(*memmap.PtrInt32(0x5D4594, 1096268))))
	if int32(*memmap.PtrUint16(0x5D4594, 1090312)) != 0 {
		r1 := nox_get_thing(*memmap.PtrInt32(0x5D4594, 1096268))
		if r1 != nil {
			nox_drawable_link_thing((*client.Drawable)(memmap.PtrOff(0x5D4594, 1090316)), r1.Field_1c)
			*memmap.PtrUint32(0x5D4594, 1090296) = uint32(uintptr(memmap.PtrOff(0x5D4594, 1090316)))
			if true {
				*memmap.PtrUint32(0x5D4594, 1090308) = *memmap.PtrUint32(0x5D4594, 1096268)
				*memmap.PtrUint32(0x5D4594, 1090436) |= 0x40000000
				return
			}
		} else {
			*memmap.PtrUint32(0x5D4594, 1090296) = 0
		}
		*memmap.PtrUint32(0x5D4594, 1090308) = *memmap.PtrUint32(0x5D4594, 1096268)
	} else {
		*memmap.PtrUint16(0x5D4594, 1090312) = uint16(int16(sub_467850(int32(dword_5d4594_1096284))))
		if int32(*memmap.PtrUint16(0x5D4594, 1090312)) != 0 {
			var t1 *client.ObjectType = nox_get_thing(int32(dword_5d4594_1096284))
			if t1 != nil {
				nox_drawable_link_thing((*client.Drawable)(memmap.PtrOff(0x5D4594, 1090316)), t1.Field_1c)
				*memmap.PtrUint32(0x5D4594, 1090296) = uint32(uintptr(memmap.PtrOff(0x5D4594, 1090316)))
				if true {
					*memmap.PtrUint32(0x5D4594, 1090436) |= 0x40000000
					*memmap.PtrUint32(0x5D4594, 1090308) = dword_5d4594_1096284
					return
				}
			} else {
				*memmap.PtrUint32(0x5D4594, 1090296) = 0
			}
			*memmap.PtrUint32(0x5D4594, 1090308) = dword_5d4594_1096284
		} else {
			r6 := sub_467850(int32(dword_5d4594_1096280))
			*memmap.PtrUint16(0x5D4594, 1090312) = uint16(uintptr(r6))
			if r6 != 0 {
				r7 := nox_get_thing(int32(dword_5d4594_1096280))
				if r7 != nil {
					nox_drawable_link_thing((*client.Drawable)(memmap.PtrOff(0x5D4594, 1090316)), r7.Field_1c)
					*memmap.PtrUint32(0x5D4594, 1090296) = uint32(uintptr(memmap.PtrOff(0x5D4594, 1090316)))
					if true {
						*memmap.PtrUint32(0x5D4594, 1090308) = dword_5d4594_1096280
						*memmap.PtrUint32(0x5D4594, 1090436) |= 0x40000000
						return
					}
				} else {
					*memmap.PtrUint32(0x5D4594, 1090296) = 0
				}
				*memmap.PtrUint32(0x5D4594, 1090308) = dword_5d4594_1096280
			} else {
				*memmap.PtrUint32(0x5D4594, 1090296) = 0
				*memmap.PtrUint32(0x5D4594, 1090308) = 0
			}
		}
	}
}
func nox_client_mapZoomIn_4724E0() {
	nox_xxx_minimap_587000_149232 -= 10
	if nox_xxx_minimap_587000_149232 < 500 {
		nox_xxx_minimap_587000_149232 = 500
	}
}
func nox_client_mapZoomOut_472500() {
	nox_xxx_minimap_587000_149232 += 10
	if nox_xxx_minimap_587000_149232 > 4000 {
		nox_xxx_minimap_587000_149232 = 4000
	}
}
func nox_xxx_cliSetMinimapZoom_472520(a1 int32) int32 {
	var result int32
	result = a1
	nox_xxx_minimap_587000_149232 = uint32(a1)
	return result
}
func sub_472540(a1 unsafe.Pointer) int32 {
	var (
		v1     int32
		v2     int32
		result int32
		a1a    int2
	)
	if a1 == *memmap.PtrPtr(0x852978, 8) {
		nox_xxx_getSomeCoods_435670(&a1a)
	} else {
		v1 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		a1a.field_0 = int32(*(*uint32)(unsafe.Add(a1, 12)))
		a1a.field_4 = v1
	}
	v2 = nox_xxx_polygonGetIdxA_421790(&a1a, *memmap.PtrInt32(0x5D4594, 1096312))
	if v2 != 0 {
		*memmap.PtrUint32(0x5D4594, 1096312) = uint32(v2)
	} else {
		v2 = int32(*memmap.PtrUint32(0x5D4594, 1096312))
	}
	if v2 != 0 {
		result = int32(*(*byte)(unsafe.Add(unsafe.Pointer(nox_xxx_polygonGetByIdx_4214A0(v2)), 130)))
	} else {
		result = 1
	}
	return result
}
func nox_xxx_drawMinimap4Sprite_4725C0(a1 unsafe.Pointer) {
	result := bool2int32(nox_client_drawable_testBuff_4356C0((*client.Drawable)(*memmap.PtrPtr(0x852978, 8)), 2))
	if result == 0 {
		sub_437260()
		*memmap.PtrUint32(0x5D4594, 1096316) = uint32(sub_472540(a1))
		nox_xxx_cliDrawMinimap_472600(a1, *memmap.PtrInt32(0x5D4594, 1096316))
		sub_437290()
	}
}
func nox_xxx_cliDrawMinimap_472600(a1 unsafe.Pointer, a2 int32) int32 {
	var (
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		v8    int32
		v9    int32
		v10   int32
		v12   int8
		v13   int32
		v14   int32
		v16   *uint8
		v19   unsafe.Pointer
		v20   int32
		v21   int32
		v22   int32
		v23   int32
		v24   int32
		v25   int32
		v26   int32
		v27   int8
		v28   int8
		v29   int32
		v30   *byte
		v31   *float32
		v32   int32
		v33   float64
		v34   int32
		v35   float64
		j     *float32
		v37   int32
		v38   float64
		v41   *nox_player_polygon_check_data
		v42   int32
		v43   int32
		v44   int32
		v45   *client.Drawable
		v51   *byte
		v52   int32
		v53   int32
		v54   int32
		v56   *byte
		v58   int32
		v60   int32
		v61   int32
		v63   *nox_player_polygon_check_data
		v64   int32
		v66   int32
		v68   int32
		v69   int32
		i     int32
		v72   int32
		v73   int32
		v74   int32
		v75   *byte
		v76   int2
		v77   int32
		v78   int32
		v79   int32
		v80   int32
		xLeft int2
		yTop  int32
		v84   int2
		v85   int32
	)
	v2 := nox_draw_getViewport_437250()
	if int32(*memmap.PtrUint8(0x5D4594, 1096300)) == 0 {
		*memmap.PtrUint8(0x5D4594, 1096300) = uint8(int8(nox_xxx_wallTileByName_410D60(internCStr("InvisibleWallSet"))))
		*memmap.PtrUint8(0x5D4594, 1096301) = uint8(int8(nox_xxx_wallTileByName_410D60(internCStr("InvisibleBlockingWallSet"))))
	}
	nox_client_drawEnableAlpha_434560(0)
	nox_xxx_wndDraw_49F7F0()
	v3 = nox_win_width / 6
	v4 = nox_win_height - nox_win_width/6
	yTop = v4 / 2
	nox_client_copyRect_49F6F0(0, 0, nox_win_width, nox_win_height)
	v5 = int32(*(*uint32)(unsafe.Pointer(v2)))
	if *(*uint32)(unsafe.Pointer(v2)) <= 0 {
		nox_client_drawRectFilledAlpha_49CF10(0, v4/2, v3, v3)
	} else {
		nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
		if v5 >= v3 {
			nox_client_drawRectFilledOpaque_49CE30(0, v4/2, v3, v3)
		} else {
			nox_client_drawRectFilledOpaque_49CE30(0, v4/2, v5, v3)
			nox_client_drawRectFilledAlpha_49CF10(v5, v4/2, v3-v5, v3)
		}
	}
	nox_client_drawEnableAlpha_434560(1)
	nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
	nox_client_drawSetAlpha_434580(0x5A)
	nox_client_drawRectLines_473510(-1, yTop-1, v3+2, v3+2)
	nox_client_drawSetAlpha_434580(0x3C)
	nox_client_drawRectLines_473510(-2, yTop-2, v3+4, v3+4)
	nox_client_drawSetAlpha_434580(0x28)
	nox_client_drawRectLines_473510(-3, yTop-3, v3+6, v3+6)
	nox_client_drawEnableAlpha_434560(0)
	nox_client_copyRect_49F6F0(0, yTop, v3, v3)
	v6 = int32(nox_xxx_minimap_587000_149232)
	v7 = v3 * v6 / 100
	nox_xxx_getSomeCoods_435670(&v84)
	v8 = v84.field_0 - v7/2
	v9 = v84.field_4 - v7/2
	xLeft.field_0 = v84.field_0 - v7/2
	xLeft.field_4 = v9
	v81 := v8 / 23
	v77 = (v8 + v7) / 23
	v78 = (v9 + v7) / 23
	v74 = (v8 / 23) * 23
	v80 = (v9 / 23) * 23
	v10 = v9 / 23
	for i = v9 / 23; i <= v78; i++ {
		v11 := sub_4106A0(v10)
		for v11 != nil {
			v12 = int8(*(*uint8)(unsafe.Add(v11, 1)))
			if int32(v12) == int32(*memmap.PtrUint8(0x5D4594, 1096300)) {
				goto LABEL_37
			}
			if int32(v12) == int32(*memmap.PtrUint8(0x5D4594, 1096301)) {
				goto LABEL_37
			}
			if int32(*(*uint8)(unsafe.Add(v11, 8))) != 0 && int32(*(*uint8)(unsafe.Add(v11, 8))) != a2 {
				goto LABEL_37
			}
			v13 = int32(*(*uint8)(unsafe.Add(v11, 5)))
			if v13 < v81 {
				goto LABEL_37
			}
			if v13 > v77 {
				break
			}
			v14 = v74 + (v13-v81)*23
			if int32(*(*uint8)(unsafe.Add(v11, 4)))&0x10 != 0 {
				v15 := *(*unsafe.Pointer)(unsafe.Add(v11, 32))
				if v15 == nil {
					goto LABEL_37
				}
				v69 = 0
				v16 = (*uint8)(memmap.PtrOff(0x587000, 149244))
				for {
					v17 := nox_server_getWallAtGrid_410580(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v16), -int(4*1)))+uint32(*(*uint8)(unsafe.Add(v11, 5)))), int32(*(*uint32)(unsafe.Pointer(v16))+uint32(*(*uint8)(unsafe.Add(v11, 6)))))
					if v17 != nil {
						if *(*uint32)(unsafe.Add(v17, 12)) != 0 {
							if v69 < 4 {
								v20 = int32(nox_xxx_minimap_587000_149232)
								v21 = int32(*(*uint8)(unsafe.Add(v15, 299))) * 8
								v22 = (*(*int32)(unsafe.Add(v15, 12)) - xLeft.field_0) * 100 / v20
								v85 = (*(*int32)(unsafe.Add(v15, 16)) - xLeft.field_4) * 100 / v20
								v23 = *memmap.PtrInt32(0x587000, uintptr(v21)+196184) * 100 / v20
								v24 = *memmap.PtrInt32(0x587000, uintptr(v21)+196188) * 100 / v20
								nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 940))
								nox_client_drawAddPoint_49F500(v22, yTop+v85)
								nox_xxx_rasterPointRel_49F570(v23, v24)
								nox_client_drawLineFromPoints_49E4B0()
								v8 = xLeft.field_0
							}
							goto LABEL_37
						}
					} else {
						v18 := nox_server_getWallAtGrid_410580(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v16), -int(4*1)))+uint32(*(*uint8)(unsafe.Add(v11, 5)))), int32(*(*uint8)(unsafe.Add(v11, 6))))
						if v18 != nil && *(*uint32)(unsafe.Add(v18, 12)) != 0 || (func() unsafe.Pointer {
							v19 = nox_server_getWallAtGrid_410580(int32(*(*uint8)(unsafe.Add(v11, 5))), int32(*(*uint32)(unsafe.Pointer(v16))+uint32(*(*uint8)(unsafe.Add(v11, 6)))))
							return v19
						}()) != nil && *(*uint32)(unsafe.Add(v19, 12)) != 0 {
							if v69 < 4 {
								v20 = int32(nox_xxx_minimap_587000_149232)
								v21 = int32(*(*uint8)(unsafe.Add(v15, 299))) * 8
								v22 = (*(*int32)(unsafe.Add(v15, 12)) - xLeft.field_0) * 100 / v20
								v85 = (*(*int32)(unsafe.Add(v15, 16)) - xLeft.field_4) * 100 / v20
								v23 = *memmap.PtrInt32(0x587000, uintptr(v21)+196184) * 100 / v20
								v24 = *memmap.PtrInt32(0x587000, uintptr(v21)+196188) * 100 / v20
								nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 940))
								nox_client_drawAddPoint_49F500(v22, yTop+v85)
								nox_xxx_rasterPointRel_49F570(v23, v24)
								nox_client_drawLineFromPoints_49E4B0()
								v8 = xLeft.field_0
							}
							goto LABEL_37
						}
					}
					v16 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), 8))
					v69++
					if int32(uintptr(unsafe.Pointer(v16))) >= int32(uintptr(memmap.PtrOff(0x587000, 149276))) {
						goto LABEL_37
					}
				}
			}
			if noxflags.HasGame(0x10000) || *(*uint32)(unsafe.Add(v11, 12)) != 0 {
				v26 = int32(nox_xxx_minimap_587000_149232)
				v25 = v26
				v76.field_0 = (v14 - v8) * 100 / v26
				v76.field_4 = yTop + (v80-v9)*100/v26
				v27 = int8(*(*uint8)(unsafe.Add(v11, 4)))
				if (int32(v27)&4) == 0 || (func() bool {
					v28 = int8(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v11, 28)), 21)))
					return int32(v28) != 3
				}()) && int32(v28) != 2 {
					if (int32(v27) & 0x20) == 0 {
						sub_4730D0(&v76, *(*uint8)(v11), 2300/v25)
					}
				}
			}
		LABEL_37:
			v11 = *(*unsafe.Pointer)(unsafe.Add(v11, 24))
			v9 = xLeft.field_4
		}
		v10 = i + 1
		v80 += 23
	}
	if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_AI) {
		v29 = sub_50CB00()
		v30 = (*byte)(sub_50CB10())
		if v29 >= 2 {
			nox_client_drawSetColor_434460(*memmap.PtrInt32(0x8531A0, 2572))
			if v29-1 > 0 {
				v31 = (*float32)(unsafe.Add(unsafe.Pointer(v30), 8))
				v72 = v29 - 1
				for {
					v32 = int32(nox_xxx_minimap_587000_149232)
					v33 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v31), -int(unsafe.Sizeof(float32(0))*1))))
					xLeft.field_0 = int32(uint32((uint64(int64(*(*float32)(unsafe.Add(unsafe.Pointer(v31), -int(unsafe.Sizeof(float32(0))*2)))))-uint64(v8))*100)) / v32
					nox_client_drawAddPoint_49F500(xLeft.field_0, yTop+int32(uint32((uint64(int64(v33))-uint64(v9))*100))/v32)
					v34 = int32(nox_xxx_minimap_587000_149232)
					v35 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v31), unsafe.Sizeof(float32(0))*1)))
					xLeft.field_0 = int32(uint32((uint64(int64(*v31))-uint64(v8))*100)) / v34
					nox_client_drawAddPoint_49F500(xLeft.field_0, yTop+int32(uint32((uint64(int64(v35))-uint64(v9))*100))/v34)
					nox_client_drawLineFromPoints_49E4B0()
					v31 = (*float32)(unsafe.Add(unsafe.Pointer(v31), unsafe.Sizeof(float32(0))*2))
					v72--
					if v72 == 0 {
						break
					}
				}
			}
		}
		for j = (*float32)(unsafe.Pointer(uintptr(nox_xxx_minimapFirstMonster_50AAE0()))); j != nil; j = (*float32)(unsafe.Pointer(uintptr(nox_xxx_minimapNextMonster_50AB10()))) {
			nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 940))
			v37 = int32(nox_xxx_minimap_587000_149232)
			v38 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(j), unsafe.Sizeof(float32(0))*1)))
			xLeft.field_0 = int32(uint32((uint64(int64(*j))-uint64(v8))*100)) / v37
			nox_xxx_minimapDrawPoint_473570(xLeft.field_0, yTop+int32(uint32((uint64(int64(v38))-uint64(v9))*100))/v37)
		}
	}
	v73 = 0
	if *memmap.PtrUint32(0x5D4594, 1096304) == 0 {
		*memmap.PtrUint32(0x5D4594, 1096304) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Crown")))
		*memmap.PtrUint32(0x5D4594, 1096308) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GameBall")))
	}
	v39 := nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
	v70 := v39
	if v39 != nil && nox_xxx_servObjectHasTeam_419130(v39) != 0 {
		v73 = 1
	}
	for k := nox_xxx_cliFirstMinimapObj_459EB0(); k != nil; k = nox_xxx_cliNextMinimapObj_459EC0(k) {
		v41 = nox_xxx_polygonIsPlayerInPolygon_4217B0((*int2)(unsafe.Add(k.C(), 12)), 0)
		if v41 != nil {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(&v41.field_0[32]), 2))) != a2 {
				continue
			}
		} else if a2 != 1 {
			continue
		}
		v42 = int32(nox_xxx_minimap_587000_149232)
		xLeft.field_0 = int32((k.PosVec.X - int(v8)) * 100 / int(v42))
		xLeft.field_4 = int32(int(yTop) + (k.PosVec.Y-int(v9))*100/int(v42))
		if (k.Flags28Val&0x400000) == 0 || (func() bool {
			v43 = int32(nox_color_blue_2650684)
			return (int32(k.Flags29Val) & 8) == 0
		}()) {
			v43 = int32(*memmap.PtrUint32(0x85B3FC, 940))
		}
		nox_client_drawSetColor_434460(v43)
		v44 = int32(k.Field_27)
		if v44 == *memmap.PtrInt32(0x5D4594, 1096304) {
			if nox_server_teamFirst_418B10() != nil || (func() *client.Drawable {
				v45 = nox_xxx_cliGetSpritePlayer_45A000()
				return v45
			}()) == nil {
			} else {
				for !nox_client_drawable_testBuff_4356C0(v45, 30) {
					v45 = sub_45A010(v45)
					if v45 == nil {
						goto LABEL_64
					}
				}
				continue
			}
		LABEL_64:
			nox_client_drawSetColor_434460(*memmap.PtrInt32(0x8531A0, 2572))
			v46 := nox_xxx_objGetTeamByNetCode_418C80(k.Field_32)
			if v46 != nil {
				v47 := nox_xxx_getTeamByID_418AB0(int32(v46.ID))
				if v47 != nil {
					v48 := nox_xxx_materialGetTeamColor_418D50(v47)
					nox_client_drawSetColor_434460(int32(v48))
				}
			}
			sub_473420((*uint32)(unsafe.Pointer(&xLeft)))
			continue
		}
		if v44 == *memmap.PtrInt32(0x5D4594, 1096308) {
			v49 := nox_xxx_objGetTeamByNetCode_418C80(k.Field_32)
			v50 := v49
			if v49 != nil && nox_xxx_servObjectHasTeam_419130(v49) != 0 {
				v51 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(v50.ID))))
				if v51 != nil {
					v52 = int32(nox_xxx_materialGetTeamColor_418D50((*server.Team)(unsafe.Pointer(v51))))
					nox_client_drawSetColor_434460(v52)
				}
			} else {
				nox_client_drawSetColor_434460(int32(nox_color_white_2523948))
			}
			nox_video_drawCircleRad3_4734F0(&xLeft.field_0)
			continue
		}
		v53 = int32(k.Flags28Val)
		if uint32(v53)&0x10000000 != 0 {
			if k.Flags30Val&0x1000000 != 0 {
				nox_client_drawSetColor_434460(int32(nox_color_white_2523948))
				v54 = sub_4B9470(k.Field_109)
				v55 := nox_xxx_getTeamByID_418AB0(v54)
				if v55 != nil {
					v58 = int32(nox_xxx_materialGetTeamColor_418D50(v55))
					nox_client_drawSetColor_434460(v58)
					sub_4733B0((*uint32)(unsafe.Pointer(&xLeft)))
					continue
				}
				sub_4733B0((*uint32)(unsafe.Pointer(&xLeft)))
				continue
			}
		} else {
			if (v53 & 4) == 0 {
				nox_xxx_minimapDrawPoint_473570(xLeft.field_0, xLeft.field_4)
				continue
			}
			if !noxflags.HasGame(32) {
				if k.C() == *memmap.PtrPtr(0x852978, 8) {
					sub_4735C0(xLeft.field_0, xLeft.field_4)
				} else {
					nox_xxx_minimapDrawPoint_473570(xLeft.field_0, xLeft.field_4)
				}
				continue
			}
			v56 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(k.Field_32))))
			if v56 != nil {
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v56), 4*1))&1 != 0 {
					nox_client_drawSetColor_434460(int32(nox_color_white_2523948))
					v57 := nox_xxx_objGetTeamByNetCode_418C80(k.Field_32)
					if v57 != nil {
						v55 := func() *server.Team {
							if int32(v57.ID) == 1 {
								return nox_xxx_getTeamByID_418AB0(2)
							}
							return nox_xxx_getTeamByID_418AB0(1)
						}()
						if v55 != nil {
							v58 = int32(nox_xxx_materialGetTeamColor_418D50(v55))
							nox_client_drawSetColor_434460(v58)
							sub_4733B0((*uint32)(unsafe.Pointer(&xLeft)))
							continue
						}
					}
					sub_4733B0((*uint32)(unsafe.Pointer(&xLeft)))
					continue
				}
			}
		}
	}
	v79 = int32(*memmap.PtrUint32(0x8531A0, 2572))
	for l := nox_xxx_cliGetSpritePlayer_45A000(); l != nil; l = sub_45A010(l) {
		v60 = bool2int32(nox_client_drawable_testBuff_4356C0(l, 30))
		v61 = int32(l.Field_32)
		v77 = v60
		v62 := nox_xxx_objGetTeamByNetCode_418C80(uint32(v61))
		v68 = int32(l.Field_32)
		v81b := v62
		v75 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(v68)))
		if v70 != nil && v62 != nil && v73 != 0 {
			v76.field_0 = nox_xxx_servCompareTeams_419150(v70, v62)
			if v76.field_0 != 0 {
				goto LABEL_103
			}
		} else {
			v76.field_0 = 0
		}
		if v77 == 0 && l.C() != *memmap.PtrPtr(0x852978, 8) && int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 3680)))&1 == 0 {
			continue
		}
	LABEL_103:
		v63 = nox_xxx_polygonIsPlayerInPolygon_4217B0((*int2)(unsafe.Add(l.C(), 12)), 0)
		if (v63 == nil || int32(*(*uint8)(unsafe.Add(unsafe.Pointer(&v63.field_0[32]), 2))) == a2) && v75 != nil && (*(*byte)(unsafe.Add(unsafe.Pointer(v75), 3680))&1) != 1 {
			v64 = int32(nox_xxx_minimap_587000_149232)
			xLeft.field_0 = int32((l.PosVec.X - int(v8)) * 100 / int(v64))
			xLeft.field_4 = int32(int(yTop) + (l.PosVec.Y-int(v9))*100/int(v64))
			if l.C() == *memmap.PtrPtr(0x852978, 8) || v76.field_0 != 0 {
				nox_client_drawSetColor_434460(v79)
			} else {
				nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 940))
			}
			if v77 != 0 {
				if v81b != nil {
					v65 := nox_xxx_getTeamByID_418AB0(int32(v81b.ID))
					if v65 != nil {
						v66 = int32(nox_xxx_materialGetTeamColor_418D50(v65))
						nox_client_drawSetColor_434460(v66)
					}
				}
				sub_473420((*uint32)(unsafe.Pointer(&xLeft)))
			} else {
				nox_xxx_minimapDrawPoint_473570(xLeft.field_0, xLeft.field_4)
			}
		}
	}
	return sub_49F860()
}
func sub_4730D0(a1 *int2, a2 uint8, a3 int32) int32 {
	var (
		result int32 = 0
		v4     int32
		v5     int32
		v6     *int2
	)
	if nox_xxx_minimap_587000_149232 <= 2000 {
		v4 = int32(*memmap.PtrUint32(0x85B3FC, 956))
		result = int32(a2)
		v5 = a3 / 2
		switch a2 {
		case 0:
			result = sub_473380(a1.field_0, a3+a1.field_4, a1.field_0+a3, a1.field_4, *memmap.PtrInt32(0x85B3FC, 956))
		case 1:
			result = sub_473380(a1.field_0, a1.field_4, a1.field_0+a3, a1.field_4+a3, *memmap.PtrInt32(0x85B3FC, 956))
		case 2:
			sub_473380(a1.field_0, a3+a1.field_4, a1.field_0+a3, a1.field_4, *memmap.PtrInt32(0x85B3FC, 956))
			result = sub_473380(a1.field_0, a1.field_4, a1.field_0+a3, a1.field_4+a3, v4)
		case 3:
			sub_473380(a1.field_0, a1.field_4, a1.field_0+v5, a1.field_4+v5, *memmap.PtrInt32(0x85B3FC, 956))
			result = sub_473380(a1.field_0, a3+a1.field_4, a3+a1.field_0, a1.field_4, v4)
		case 4:
			sub_473380(a1.field_0, a1.field_4, a1.field_0+a3, a1.field_4+a3, *memmap.PtrInt32(0x85B3FC, 956))
			result = sub_473380(v5+a1.field_0, v5+a1.field_4, a3+a1.field_0, a1.field_4, v4)
		case 5:
			sub_473380(a1.field_0, a3+a1.field_4, a1.field_0+a3, a1.field_4, *memmap.PtrInt32(0x85B3FC, 956))
			result = sub_473380(v5+a1.field_0, v5+a1.field_4, a3+a1.field_0, a1.field_4+a3, v4)
		case 6:
			v6 = a1
			sub_473380(a1.field_0, a1.field_4, a1.field_0+a3, a1.field_4+a3, *memmap.PtrInt32(0x85B3FC, 956))
			result = sub_473380(v6.field_0, a3+v6.field_4, v5+v6.field_0, v6.field_4+v5, v4)
		case 7:
			sub_473380(a1.field_0, a1.field_4, a1.field_0+v5, a1.field_4+v5, *memmap.PtrInt32(0x85B3FC, 956))
			result = sub_473380(v5+a1.field_0, v5+a1.field_4, a3+a1.field_0, a1.field_4, v4)
		case 8:
			sub_473380(v5+a1.field_0, v5+a1.field_4, a1.field_0+a3, a1.field_4+a3, *memmap.PtrInt32(0x85B3FC, 956))
			result = sub_473380(v5+a1.field_0, v5+a1.field_4, a3+a1.field_0, a1.field_4, v4)
		case 9:
			sub_473380(v5+a1.field_0, v5+a1.field_4, a1.field_0+a3, a1.field_4+a3, *memmap.PtrInt32(0x85B3FC, 956))
			result = sub_473380(v5+a1.field_0, v5+a1.field_4, a1.field_0, a1.field_4+a3, v4)
		case 0xA:
			v6 = a1
			sub_473380(a1.field_0, a1.field_4, a1.field_0+v5, a1.field_4+v5, *memmap.PtrInt32(0x85B3FC, 956))
			result = sub_473380(v6.field_0, a3+v6.field_4, v5+v6.field_0, v6.field_4+v5, v4)
		default:
			return result
		}
	} else {
		nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 956))
		nox_client_drawPixel_49EFA0(a1.field_0, a1.field_4)
	}
	return result
}
func sub_473380(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	nox_client_drawSetColor_434460(a5)
	nox_client_drawAddPoint_49F500(a1, a2)
	nox_client_drawAddPoint_49F500(a3, a4)
	return nox_client_drawLineFromPoints_49E4B0()
}
func sub_4733B0(a1 *uint32) int32 {
	var (
		v1 int32
		v2 int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) + 4)
	v2 = int32(*a1 - 2)
	nox_client_drawAddPoint_49F500(v2, v1)
	v1 -= 8
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v2, v1)
	v2 += 4
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v2, v1)
	v1 += 4
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawAddPoint_49F500(v2-4, v1)
	return nox_client_drawLineFromPoints_49E4B0()
}
func sub_473420(a1 *uint32) int32 {
	var (
		v1 int32
		v2 int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) + 6)
	v2 = int32(*a1 - 4)
	nox_client_drawAddPoint_49F500(v2, v1)
	v1 -= 12
	v2 -= 2
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v2, v1)
	v1 += 6
	v2 += 4
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v2, v1)
	v1 -= 6
	v2 += 2
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v2, v1)
	v1 += 6
	v2 += 2
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v2, v1)
	v1 -= 6
	v2 += 4
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v2, v1)
	v1 += 12
	v2 -= 2
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v2, v1)
	nox_client_drawAddPoint_49F500(v2-8, v1)
	return nox_client_drawLineFromPoints_49E4B0()
}
func nox_video_drawCircleRad3_4734F0(a1 *int32) {
	nox_video_drawCircle_4B0B90(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*0)), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)), 3)
}
func nox_client_drawRectLines_473510(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4 int32
		v5 int32
	)
	nox_client_drawAddPoint_49F500(a1, a2)
	v4 = a1 + a3 - 1
	nox_client_drawAddPoint_49F500(v4, a2)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v4, a2)
	v5 = a4 - 1 + a2
	nox_client_drawAddPoint_49F500(v4, v5)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v4, v5)
	nox_client_drawAddPoint_49F500(a1, v5)
	return nox_client_drawLineFromPoints_49E4B0()
}
func nox_xxx_minimapDrawPoint_473570(xLeft int32, yTop int32) {
	if nox_xxx_minimap_587000_149232 > 1200 {
		nox_xxx_drawPointMB_499B70(xLeft, yTop, bool2int32(nox_xxx_minimap_587000_149232 < 1750)+2)
	} else {
		nox_xxx_drawPointMB_499B70(xLeft, yTop, 4)
	}
}
func sub_4735C0(xLeft int32, yTop int32) {
	if nox_xxx_minimap_587000_149232 > 1200 {
		nox_xxx_drawPointMB_499B70(xLeft, yTop, bool2int32(nox_xxx_minimap_587000_149232 < 1750)+4)
	} else {
		nox_xxx_drawPointMB_499B70(xLeft, yTop, 6)
	}
}
func nox_xxx_drawMinimapAndLines_4738E0() int32 {
	var (
		result int32
		v1     *uint32
	)
	result = 1
	if nox_client_gui_flag_1556112 == 1 {
		return result
	}
	if int32(*memmap.PtrUint8(0x5D4594, 1096424))&1 != 0 {
		v1 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(nox_player_netCode_85319C).C())
		nox_xxx_drawMinimap4Sprite_4725C0(unsafe.Pointer(v1))
	}
	result = nox_xxx_drawMessageLines_445530()
	return result
}
func nox_xxx____setargv_11_473920() {
	*memmap.PtrUint32(0x5D4594, 1096520) = 1
}
func sub_473930() *byte {
	var result *byte
	*memmap.PtrPtr(0x5D4594, 1096456) = unsafe.Pointer(nox_xxx_gLoadAnim_42FA20(internCStr("ConfusedBirdies")))
	result = (*byte)(unsafe.Pointer(nox_xxx_gLoadAnim_42FA20(internCStr("SphericalShieldAnim"))))
	*memmap.PtrPtr(0x5D4594, 1096460) = unsafe.Pointer(result)
	return result
}
func sub_473960() int32 {
	var result int32
	result = 0
	*memmap.PtrUint32(0x5D4594, 1096456) = 0
	*memmap.PtrUint32(0x5D4594, 1096460) = 0
	return result
}
func sub_4739E0(a1 *uint32, a2 *int2, a3 *int2) int32 {
	var result int32
	a3.field_0 = int32(uint32(a2.field_0) + *a1 - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	result = a2.field_4
	a3.field_4 = int32(uint32(result) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	return result
}
func sub_473A10(a1 *uint32, a2 *int2, a3 *uint32) int32 {
	var result int32
	*a3 = uint32(a2.field_0) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) - *a1
	result = a2.field_4
	*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) = uint32(result) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	return result
}
func nox_xxx_drawWalls_473C10(vp *noxrender.Viewport, data unsafe.Pointer) {
	var (
		a1   *uint32 = (*uint32)(unsafe.Pointer(vp))
		a2   *uint8  = (*uint8)(data)
		v3   *uint8
		v4   uint8
		v5   int32
		v6   int32
		v7   int32
		v8   int32
		v9   int32
		v10  int32
		v11  int32
		v12  int32
		v13  int32
		v14  int32
		v15  int32
		v16  int32
		v17  int32
		v18  int32
		v19  int32
		v20  bool
		v21  int32
		v22  int32
		v23  int32
		v24  int32
		v25  int32
		v26  uint8
		v27  uint8
		v28  int8
		v29  int32
		v30  int32
		v31  int32
		v32  *int32
		v33  int32
		v34  int32
		v35  int32
		v36  int32
		v37  int32
		v38  int32
		v39  int32
		v40  int32
		v41  int32
		v42  int32
		v43  int32
		v44  int32
		v45x int32
		v45y int32
		v46  int32
		v47  int32
		v48  int32
		v49  int32
		v50  int32
		v51  noxrender.ImageHandle
		v52  int32
		v53  int32
		v54  *uint8
		v55x int32
		v55y int32
		v56  int32
		v57  int32
		v58  int32
		v59  int32
		v60  int32
		v63  int32
		v64  int32
		v65  int32
		v66  int32
		v67  int32
		v68  int32
		v69  int32
		a3   int32
		a4   int32
		v72  int32
		v73  int32
		v74  int32
		v75  int32
		v76  int32
		v77  int2
		a2a  int2
		a1a  int2
		v80  int2
		v81  int2
		v82  int32
		v83  [3]int32
		v84  int32
	)
	v3 = a2
	a4 = nox_win_width
	v72 = 0
	a3 = 0
	if a2 == nil {
		return
	}
	v4 = *(*uint8)(unsafe.Add(unsafe.Pointer(a2), 4))
	if (int32(v4) & 1) == 0 {
		return
	}
	v5 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 6)))
	v6 = int32(*a1 + uint32(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 5)))*23) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	v82 = int32(*a1 + uint32(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 5)))*23) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) + uint32(v5*23) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	v74 = int32(*memmap.PtrUint32(0x587000, uintptr(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 3)))*4)+149364))
	v8 = v74
	if v74 == -1 {
		v8 = int32(*a2)
		v74 = int32(*a2)
	}
	v84 = v8
	if v8 != 0 {
		if v8 == 1 && int32(v4)&0x40 != 0 {
			v84 = 12
		}
	} else if int32(v4)&0x40 != 0 {
		v84 = 11
	}
	if *memmap.PtrUint32(0x587000, 80808) != 0 {
		v9 = v74 * 16
		v10 = int32(*memmap.PtrUint32(0x587000, uintptr(v74*16)+85440))
		v11 = int32(*memmap.PtrUint32(0x587000, uintptr(v74*16)+85448))
		a1a.field_4 = int32(uint32(v7) + *memmap.PtrUint32(0x587000, uintptr(v74*16)+85444))
		v12 = v6 + v10
		a2a.field_4 = int32(uint32(v7) + *memmap.PtrUint32(0x587000, uintptr(v74*16)+85452))
		v13 = v6 + v11
		a1a.field_0 = v12
		a2a.field_0 = v13
		if v74 == 7 || v74 == 9 {
			if sub_4C42A0(&a1a, &a2a, &a3, &a4) != 0 {
				v22 = 1
			} else {
				v22 = 0
				a3 = a2a.field_0
			}
			v23 = int32(*memmap.PtrUint32(0x587000, uintptr(v9)+85508))
			a1a.field_0 = int32(uint32(v82) + *memmap.PtrUint32(0x587000, uintptr(v9)+85504))
			v24 = int32(uint32(v82) + *memmap.PtrUint32(0x587000, uintptr(v9)+85512))
			v25 = int32(*memmap.PtrUint32(0x587000, uintptr(v9)+85516))
			a1a.field_4 = v7 + v23
			a2a.field_0 = v24
			a2a.field_4 = v7 + v25
			if sub_4C42A0(&a1a, &a2a, &a3, &a4) != 0 {
				v19 = a3
			} else {
				if v22 == 0 {
					return
				}
				if a4 > a1a.field_0 {
					a4 = a1a.field_0
				}
				v19 = a3
			}
		} else {
			if v74 != 8 && v74 != 10 {
				if sub_4C42A0(&a1a, &a2a, &a3, &a4) == 0 {
					return
				}
				v19 = a3
			} else {
				v76 = v13
				v75 = v12
				if sub_4C42A0(&a1a, &a2a, &v75, &v76) != 0 {
					v73 = bool2int32(v76-v75 >= 3)
				} else {
					v73 = 0
				}
				v14 = int32(*memmap.PtrUint32(0x587000, uintptr(v74*16)+85504))
				v15 = int32(*memmap.PtrUint32(0x587000, uintptr(v74*16)+85516))
				v80.field_4 = int32(uint32(v7) + *memmap.PtrUint32(0x587000, uintptr(v74*16)+85508))
				v16 = v6 + v14
				v17 = int32(uint32(v6) + *memmap.PtrUint32(0x587000, uintptr(v74*16)+85512))
				v80.field_0 = v16
				a3 = v16
				v81.field_0 = v17
				a4 = v17
				v81.field_4 = v7 + v15
				v18 = sub_4C42A0(&v80, &v81, &a3, &a4)
				v19 = a3
				v20 = v18 == 0
				if v20 {
					v21 = 0
				} else {
					v21 = bool2int32(a4-a3 >= 3)
				}
				if v73 != 0 {
					if v21 != 0 {
						if a3 > v75 {
							v19 = v75
							a3 = v75
						}
						if v19 <= v80.field_0 {
							v19 = 0
							a3 = 0
						}
						if a4 < v76 {
							a4 = v76
						}
						if a4 >= v81.field_0 {
							a4 = nox_win_width
						}
					} else {
						v19 = v75
						a3 = v75
						a4 = v76
						if v74 != 8 {
							v84 = 1
							if v19 == v80.field_0 {
								v19 = 0
								a3 = 0
							}
						} else {
							v84 = 0
							if v76 == v81.field_0 {
								a4 = nox_win_width
							}
						}
					}
				} else {
					if v21 == 0 {
						return
					}
					v84 = bool2int32(v74 != 8) + 13
					if a4 == v81.field_0 {
						a4 = nox_win_width
					}
					if v19 == v80.field_0 {
						v19 = 0
						a3 = 0
					}
				}
			}
		}
		if v19 >= a4 {
			v26 = *(*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
			*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 3)) = 0
			*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 4)) = uint8(int8(int32(v26) & 0xFC))
			return
		}
	}
	v27 = *(*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
	v28 = int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))) & 2)
	if int32(v28) == 0 {
		v29 = (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))) >> 2) & 2
		goto LABEL_64
	}
	if *memmap.PtrUint32(0x5D4594, 805848) != 0 && nox_client_translucentFrontWalls_805844 != 0 {
		if nox_client_highResFrontWalls_80820 == 0 && nox_client_highResFloors_154952 != 0 {
			v72 |= 4
			goto LABEL_61
		}
		v72 = 8
	}
	if nox_client_highResFrontWalls_80820 == 0 {
		v72 |= 4
	}
LABEL_61:
	v29 = (int32(v27)&8 | 4) >> 2
LABEL_64:
	v73 = v29
	if int32(v28) != 0 && nox_client_translucentFrontWalls_805844 != 0 && (nox_xxx_wallFlags(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 1))))&4) == 0 {
		v30 = v72
		*(*uint8)(unsafe.Pointer(&v30)) = uint8(int8(v72 | 2))
		v72 = v30
	} else {
		v72 |= 1
	}
	if *memmap.PtrUint32(0x587000, 80816) != 0 {
		switch v74 {
		case 0, 3:
			v31 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 6)))
			v77.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 5))) * 23
			v77.field_4 = (v31 + 1) * 23
			v32 = (*int32)(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77)))))
			if uintptr(unsafe.Pointer(v32)) != uintptr(31) {
				v83[0] = *v32
				v83[1] = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*1))
				v33 = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*2))
				v32 = &v83[0]
				v83[2] = v33
			}
			v77.field_0 += 23
			v77.field_4 -= 23
			v34 = int32(uintptr(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77))))))
		case 1, 4:
			v35 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 6)))
			v77.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 5))) * 23
			v77.field_4 = v35 * 23
			v32 = (*int32)(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77)))))
			if uintptr(unsafe.Pointer(v32)) != uintptr(31) {
				v83[0] = *v32
				v83[1] = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*1))
				v36 = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*2))
				v32 = &v83[0]
				v83[2] = v36
			}
			v77.field_0 += 23
			v77.field_4 += 23
			v34 = int32(uintptr(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77))))))
		case 7:
			v37 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 6)))
			v77.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 5))) * 23
			v77.field_4 = v37 * 23
			v32 = (*int32)(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77)))))
			if uintptr(unsafe.Pointer(v32)) != uintptr(31) {
				v83[0] = *v32
				v83[1] = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*1))
				v38 = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*2))
				v32 = &v83[0]
				v83[2] = v38
			}
			v77.field_0 += 23
			v34 = int32(uintptr(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77))))))
		case 8:
			v39 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 6)))
			v77.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 5)))*23 + 11
			v77.field_4 = v39*23 + 11
			v32 = (*int32)(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77)))))
			if uintptr(unsafe.Pointer(v32)) != uintptr(31) {
				v83[0] = *v32
				v83[1] = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*1))
				v40 = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*2))
				v32 = &v83[0]
				v83[2] = v40
			}
			v77.field_0 -= 34
			v77.field_4 -= 34
			v34 = int32(uintptr(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77))))))
		case 10:
			v41 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 6)))
			v77.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 5))) * 23
			v77.field_4 = (v41 + 1) * 23
			v32 = (*int32)(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77)))))
			if uintptr(unsafe.Pointer(v32)) != uintptr(31) {
				v83[0] = *v32
				v83[1] = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*1))
				v42 = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*2))
				v32 = &v83[0]
				v83[2] = v42
			}
			v77.field_0 += 11
			v77.field_4 -= 11
			v34 = int32(uintptr(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77))))))
		default:
			v43 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 6)))
			v77.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 5))) * 23
			v77.field_4 = (v43 + 1) * 23
			v32 = (*int32)(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77)))))
			if uintptr(unsafe.Pointer(v32)) != uintptr(31) {
				v83[0] = *v32
				v83[1] = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*1))
				v44 = *(*int32)(unsafe.Add(unsafe.Pointer(v32), 4*2))
				v32 = &v83[0]
				v83[2] = v44
			}
			v77.field_0 += 23
			v34 = int32(uintptr(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer(&v77))))))
		}
		v74 = v34
		nox_xxx_getWallDrawOffset_46A3F0(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 1))), v84, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 2))), v73, &v45x, &v45y)
		v46 = v82 + v45x - 51
		v47 = -73 - v45y + v7
		sub_4345F0(1)
		v48 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 8)))
		*(*uint8)(unsafe.Pointer(&v49)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v32), 4))
		*(*uint8)(unsafe.Pointer(&v50)) = *(*uint8)(unsafe.Pointer(v32))
		nox_draw_setColorMultAndIntensityRGB_433CD0(uint8(int8(v50)), uint8(int8(v49)), uint8(int8(v48)))
		if (v72 & 2) == 0 {
			v69 = v72
			v66 = a4
			v65 = a3
			v64 = nox_win_height
			v63 = v74
			v52 = int32(uintptr(nox_xxx_getWallSprite_46A3B0(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 1))), v84, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 2))), v73)))
			nox_xxx_edgeDraw_480EF0(v52, v46, v47, v32, (*int32)(v63), v64, v65, v66, 0, v69)
			goto LABEL_106
		}
		if sub_47D380(a3, a4) == 0 {
			goto LABEL_106
		}
		nox_client_drawEnableAlpha_434560(1)
		nox_client_drawSetAlpha_434580(0x80)
		sub_47D400(bool2int32(nox_client_highResFrontWalls_80820 == 0), int8(uint8(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))))
		v68 = v47
		v67 = v46
		v51 = nox_xxx_getWallSprite_46A3B0(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 1))), v84, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 2))), v73)
	} else {
		v53 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 6)))
		v77.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 5)))*23 + 11
		v77.field_4 = v53*23 + 11
		v54 = sub_469920((*nox_point)(unsafe.Pointer(&v77)))
		nox_xxx_getWallDrawOffset_46A3F0(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 1))), v84, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 2))), v73, &v55x, &v55y)
		v56 = v82 + v55x - 50
		v57 = -72 - v55y + v7
		sub_4345F0(1)
		*(*uint8)(unsafe.Pointer(&v59)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v54), 8))
		v58 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v54), 4)))
		*(*uint8)(unsafe.Pointer(&v60)) = *v54
		nox_draw_setColorMultAndIntensityRGB_433CD0(uint8(int8(v60)), uint8(int8(v58)), uint8(int8(v59)))
		if (v72 & 2) == 0 {
			if sub_47D380(a3, a4) != 0 {
				sub_47D400(bool2int32(nox_client_highResFrontWalls_80820 == 0), int8(uint8(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))))
				v61 := nox_xxx_getWallSprite_46A3B0(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 1))), v84, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 2))), v73)
				nox_client_drawImageAt_47D2C0(v61, v56, v57)
				sub_47D400(0, 0)
			}
			goto LABEL_106
		}
		if sub_47D380(a3, a4) == 0 {
			goto LABEL_106
		}
		nox_client_drawEnableAlpha_434560(1)
		nox_client_drawSetAlpha_434580(0x80)
		sub_47D400(bool2int32(nox_client_highResFrontWalls_80820 == 0), int8(uint8(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))))
		v68 = v57
		v67 = v56
		v51 = nox_xxx_getWallSprite_46A3B0(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 1))), v84, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 2))), v73)
	}
	nox_client_drawImageAt_47D2C0(v51, v67, v68)
	sub_47D400(0, 0)
	nox_client_drawEnableAlpha_434560(0)
LABEL_106:
	sub_4345F0(0)
	*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 3)) = 0
	*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 4)) &= 0xFC
	*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)) = 1
	return
}
func sub_474B40(dr *client.Drawable) int32 {
	var (
		a1 = dr
	)
	v1 := nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
	if v1 != nil {
		v2 := nox_xxx_objGetTeamByNetCode_418C80(a1.Field_32)
		if v2 != nil {
			if nox_player_netCode_85319C == a1.Field_32 || nox_xxx_servCompareTeams_419150(v1, v2) != 0 {
				return 1
			}
		}
	}
	v3 := AsDrawableP(*memmap.PtrPtr(0x852978, 8))
	if a1 == v3 {
		return 1
	}
	if *memmap.PtrUint32(0x852978, 8) != 0 {
		if !nox_client_drawable_testBuff_4356C0((*client.Drawable)(*memmap.PtrPtr(0x852978, 8)), 21) {
			v3 = AsDrawableP(*memmap.PtrPtr(0x852978, 8))
			goto LABEL_9
		}
		return 1
	}
LABEL_9:
	if int32(a1.Flags28Val)&4 != 0 {
		if a1 != v3 {
			nox_common_playerInfoGetByID_417040(int32(a1.Field_32))
		}
	}
	return 0
}
func nox_xxx_sprite_4756E0_drawable(dr *client.Drawable) int32 {
	var (
		a1 *uint32 = (*uint32)(dr.C())
		v3 int32
		v4 int32
	)
	if ptr := dr.DrawFunc.Ptr(); ptr != nil {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*30)))
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*28)))
		if (v3&0x1000) == 0 && v3&1 != 0 && (dr.DrawFunc.Equals(nox_thing_static_draw) || dr.DrawFunc.Equals(Nox_thing_static_random_draw)) && (uint32(v4)&0x80800000) == 0 && (v3&0x48 != 0 || uint32(v4)&0x400000 != 0) && (v3&0x800) == 0 {
			return 1
		}
	}
	return 0
}
func nox_xxx_sprite_475740_drawable(dr *client.Drawable) int32 {
	var (
		a1     *uint32 = (*uint32)(dr.C())
		result int32
		v3     int32
		v4     int32
	)
	result = 0

	if ptr := dr.DrawFunc.Ptr(); ptr != nil {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*30)))
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*28)))
		if (v3 & 0x1000) == 0 {
			if v3&1 != 0 {
				result = 1
				if (dr.DrawFunc.Equals(nox_thing_static_draw) || dr.DrawFunc.Equals(Nox_thing_static_random_draw)) && (uint32(v4)&0x80800000) == 0 && (v3&0x800) == 0 && (v3&0x48 != 0 || uint32(v4)&0x400000 != 0) {
					result = 0
				}
			}
		}
	}
	return result
}
func nox_xxx_sprite_4757A0_drawable(a1 *client.Drawable) int32 {
	var (
		result int32
		v2     int32
	)
	result = 0
	if *(*uint32)(unsafe.Add(a1, 300)) == 0 {
		return result
	}
	v2 = int32(a1.Flags30Val)
	if (v2 & 0x1000) != 0 {
		return result
	}
	if v2&0x4000 == 0 {
		return result
	}
	if v2&0x40 != 0 {
		result = 1
	}
	return result
}
func sub_4757D0_drawable(dr *client.Drawable) int32 {
	var (
		a1     *uint32 = (*uint32)(dr.C())
		result int32
		v2     int32
	)
	result = 0
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*75)) == 0 {
		return result
	}
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*30)))
	if (v2&1) == 0 && ((*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*28))&0x2000) == 0 || uint32(v2)&0x1000000 != 0) && (v2&0x1000) == 0 {
		result = 1
	}
	return result
}
func nox_xxx_drawAllMB_475810_draw_B(vp *noxrender.Viewport) int32 {
	var (
		v10 int32 = 1
		v11 int32
		v38 types.Pointf
	)
	if nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_FLOOR_RENDERING) || (func() bool {
		v38.X = float32(float64(vp.World.Max.X))
		v38.Y = float32(float64(vp.World.Max.Y))
		v11 = nox_xxx_tileNFromPoint_411160(&v38)
		return v11 == math.MaxUint8
	}()) || v11 == -1 {
		v10 = 0
	}
	return v10
}
