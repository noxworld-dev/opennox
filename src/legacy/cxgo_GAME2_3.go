package legacy

import (
	"image"
	"math"
	"sync/atomic"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/cmath"
	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_max_npcs int32 = 1024
var npc_array *nox_npc
var nox_draw_curDrawData_3799572 *noxrender.RenderData
var nox_gui_wol_servers_list nox_list_item_t = nox_list_item_t{}

func sub_48C580(a1 *pixel8888, num int32) {
	var pix *uint32 = (*uint32)(unsafe.Pointer(a1))
	for i := num - 1; i >= 0; i-- {
		var result uint32 = *pix
		for it := (*uint32)(unsafe.Add(unsafe.Pointer(pix), 4*uintptr(i))); uintptr(unsafe.Pointer(it)) > uintptr(unsafe.Pointer(pix)); it = (*uint32)(unsafe.Add(unsafe.Pointer(it), -int(4*1))) {
			if result > *it {
				result = uint32(atomic.SwapInt32((*int32)(unsafe.Pointer(it)), int32(result)))
			}
		}
		*pix = result
		pix = (*uint32)(unsafe.Add(unsafe.Pointer(pix), 4*1))
	}
}
func sub_48C690(a1 int32, a2 int32, a3 int32, a4 int32) uint32 {
	return sub_48C730(uint32((a3-a1)*(a3-a1) + (a4-a2)*(a4-a2)))
}
func sub_48C6B0(a1 int32, a2 int32) uint32 {
	return sub_48C730(uint32(a2*a2 + a1*a1))
}
func sub_48C730(a1 uint32) uint32 {
	var result int32
	if a1 < 0x10000 {
		if a1 < 0x100 {
			if a1 < 0x10 {
				if a1 < 4 {
					result = int32(*memmap.PtrUint8(0x587000, uintptr(a1)*64+155956)) >> 7
				} else {
					result = int32(*memmap.PtrUint8(0x587000, uintptr(a1)*16+155956)) >> 6
				}
			} else if a1 < 0x40 {
				result = int32(*memmap.PtrUint8(0x587000, uintptr(a1)*4+155956)) >> 5
			} else {
				result = int32(*memmap.PtrUint8(0x587000, uintptr(a1)+155956)) >> 4
			}
		} else if a1 < 0x1000 {
			if a1 < 0x400 {
				result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>2))+155956)) >> 3
			} else {
				result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>4))+155956)) >> 2
			}
		} else if a1 < 0x4000 {
			result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>6))+155956)) >> 1
		} else {
			result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>8))+155956))
		}
	} else if a1 < 0x1000000 {
		if a1 < 0x100000 {
			if a1 < 0x40000 {
				result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>10))+155956)) << 1
			} else {
				result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>12))+155956)) << 2
			}
		} else if a1 < 0x400000 {
			result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>14))+155956)) << 3
		} else {
			result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>16))+155956)) << 4
		}
	} else if a1 < 0x10000000 {
		if a1 < 0x4000000 {
			result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>18))+155956)) << 5
		} else {
			result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>20))+155956)) << 6
		}
	} else if a1 < 0x40000000 {
		result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>22))+155956)) << 7
	} else {
		result = int32(*memmap.PtrUint8(0x587000, uintptr((a1>>24))+155956)) << 8
	}
	return uint32(result)
}
func nox_xxx_showObserverWindow_48CA70(a1 int32) int32 {
	return nox_window_set_hidden(dword_5d4594_1193712, a1)
}
func sub_48CAD0() int32 {
	if wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_1197312) != 0 {
		return 0
	}
	nox_xxx_wnd_46C6E0(dword_5d4594_1197312)
	nox_window_set_hidden(dword_5d4594_1197312, 1)
	return 1
}
func sub_48D000() int32 {
	v0 := nox_new_window_from_file(internCStr("GuiKick.wnd"), nox_xxx_guiKick_48D0A0)
	dword_5d4594_1197312 = v0
	if v0 == nil {
		return 0
	}
	dword_5d4594_1197316 = nox_xxx_wndGetChildByID_46B0C0(v0, 4320)
	dword_5d4594_1197320 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1197312, 4321)
	nox_window_setPos_46A9B0(dword_5d4594_1197312, (nox_win_width-int32(dword_5d4594_1197312.SizeVal.X))/2, int32(dword_5d4594_1197312.Off.Y))
	nox_window_set_hidden(dword_5d4594_1197312, 1)
	dword_5d4594_1197324 = 0
	dword_5d4594_1197328 = 0
	dword_5d4594_1197332 = 0
	dword_5d4594_1197336 = 0
	return 1
}
func nox_xxx_guiKick_48D0A0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var v4 int32
	if a2 != 16391 {
		return 0
	}
	v4 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) - 4311
	if v4 != 0 {
		if v4 == 1 {
			sub_48CAD0()
			goto LABEL_15
		}
	} else {
		if dword_5d4594_1197308 != 4 {
			if dword_5d4594_1197308 == 2 {
				sub_48D340()
			} else {
				if dword_5d4594_1197308 != 0 && dword_5d4594_1197308 != 1 && dword_5d4594_1197308 != 3 {
					goto LABEL_15
				}
				sub_48D120()
			}
			sub_48CAD0()
			goto LABEL_15
		}
		sub_48D410()
	}
LABEL_15:
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100)
	return 1
}
func sub_48D120() int32 {
	var (
		v0     int32
		v1     *int32
		v2     *int32
		i      int32
		v4     *wchar2_t
		v5     *wchar2_t
		v6     int32
		v7     *wchar2_t
		result int32
		v9     int32
		v10    *wchar2_t
		v11    int32
		v12    *wchar2_t
	)
	v0 = 0
	dword_5d4594_1197328 = dword_5d4594_1197324
	alloc.Memcpy(memmap.PtrOff(0x5D4594, 1195512), memmap.PtrOff(0x5D4594, 1193720), 0x700)
	dword_5d4594_1197324 = 0
	v1 = (*int32)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1197316, 16404, 0, 0)))
	v2 = v1
	for i = *v1; i != -1; v2 = (*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) {
		v4 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1197316, 16406, uintptr(i), 0)))
		if v4 != nil {
			nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, uintptr(dword_5d4594_1197324)*56+1193720)), v4)
			dword_5d4594_1197324++
		}
		i = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1))
	}
	if dword_5d4594_1197328 > 0 {
		v5 = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1195512))
		for {
			v6 = 0
			if dword_5d4594_1197324 <= 0 {
				nox_xxx_voteSend_48D260(v5)
			} else {
				v7 = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1193720))
				for {
					if nox_wcscmp(v5, v7) == 0 {
						break
					}
					v6++
					v7 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(wchar2_t(0))*28))
					if v6 >= dword_5d4594_1197324 {
						nox_xxx_voteSend_48D260(v5)
						break
					}
				}
			}
			v0++
			v5 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(wchar2_t(0))*28))
			if v0 >= dword_5d4594_1197328 {
				break
			}
		}
	}
	result = dword_5d4594_1197324
	v9 = 0
	if dword_5d4594_1197324 <= 0 {
		return result
	}
	v10 = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1193720))
	for {
		v11 = 0
		if dword_5d4594_1197328 <= 0 {
			nox_xxx_netSendRenameMb_48D2D0(v10)
		} else {
			v12 = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1195512))
			for {
				if nox_wcscmp(v10, v12) == 0 {
					break
				}
				v11++
				v12 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v12), unsafe.Sizeof(wchar2_t(0))*28))
				if v11 >= dword_5d4594_1197328 {
					nox_xxx_netSendRenameMb_48D2D0(v10)
					break
				}
			}
		}
		result = dword_5d4594_1197324
		v9++
		v10 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(wchar2_t(0))*28))
		if v9 >= dword_5d4594_1197324 {
			break
		}
	}
	return result
}
func nox_xxx_voteSend_48D260(a1 *wchar2_t) {
	result := nox_common_playerInfoGetFirst_416EA0()
	v2 := result
	if result == nil {
		return
	}
	for nox_wcscmp((*wchar2_t)(unsafe.Add(v2.C(), 4704)), a1) != 0 {
		result = nox_common_playerInfoGetNext_416EE0(v2)
		v2 = result
		if result == nil {
			return
		}
	}
	var v3 [52]byte
	*(*uint16)(unsafe.Pointer(&v3[0])) = 750
	nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v3[2])), a1)
	nox_netlist_addToMsgListCli_40EBC0(31, 0, &v3[0], 52)
}
func nox_xxx_netSendRenameMb_48D2D0(a1 *wchar2_t) {
	result := nox_common_playerInfoGetFirst_416EA0()
	v2 := result
	if result == nil {
		return
	}
	for nox_wcscmp((*wchar2_t)(unsafe.Add(v2.C(), 4704)), a1) != 0 {
		result = nox_common_playerInfoGetNext_416EE0(v2)
		v2 = result
		if result == nil {
			return
		}
	}
	var v3 [52]byte
	*(*uint16)(unsafe.Pointer(&v3[0])) = 238
	nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v3[2])), a1)
	nox_netlist_addToMsgListCli_40EBC0(31, 0, &v3[0], 52)
}
func sub_48D340() {
	var result int32
	if nox_window_call_field_94_fnc(dword_5d4594_1197320, 16404, 0, 0) != 0 {
		result = 0
		dword_5d4594_1197332 = 0
		if dword_5d4594_1197336 == 1 {
			result = nox_xxx_clientVote_48D3E0()
			dword_5d4594_1197336 = dword_5d4594_1197332
			return
		}
	} else {
		result = 1
		dword_5d4594_1197332 = 1
		if dword_5d4594_1197336 == 0 {
			result = sub_48D3B0()
			dword_5d4594_1197336 = dword_5d4594_1197332
			return
		}
	}
	dword_5d4594_1197336 = uint32(result)
}
func sub_48D3B0() int32 {
	var v1 [2]byte
	v1[0] = 238
	v1[1] = 4
	return nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&v1[0]), 2, 1)
}
func nox_xxx_clientVote_48D3E0() int32 {
	var v1 [2]byte
	v1[0] = 238
	v1[1] = 5
	return nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&v1[0]), 2, 1)
}
func sub_48D410() {
	res := nox_window_call_field_94_fnc(dword_5d4594_1197320, 16404, 0, 0)
	if res == 0 {
		sub_48CB10(2)
	} else if res == 1 {
		sub_48CB10(3)
	}
}
func Sub_48D450() {
	nox_xxx_wnd_46C6E0(dword_5d4594_1197312)
	nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1197312)
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1197312)
	dword_5d4594_1197312 = nil
	dword_5d4594_1197316 = nil
	dword_5d4594_1197320 = nil
	dword_5d4594_1197324 = 0
	dword_5d4594_1197328 = 0
	dword_5d4594_1197332 = 0
	dword_5d4594_1197336 = 0
}
func sub_48D4A0() {
	dword_5d4594_1197332 = 0
	dword_5d4594_1197336 = 0
}
func sub_48D4B0(a1 int32) {
	*memmap.PtrUint32(0x5D4594, 1197304) = uint32(a1)
	if a1 == 1 {
		sub_4C3460(0)
	} else {
		sub_4C3460(1)
	}
}
func sub_48D4F0(a1 uint16, a2 uint16) int32 {
	var v2 uint16
	v2 = 10000
	if int32(a1)-10000 >= 0 {
		return bool2int32(int32(a2) < int32(a1) && int32(a2) >= int32(a1)-int32(v2))
	}
	if int32(a2) >= math.MaxUint16-int32(uint16(int16(10000-int32(a1)))) {
		return 1
	}
	v2 = a1
	return bool2int32(int32(a2) < int32(a1) && int32(a2) >= int32(a1)-int32(v2))
}
func sub_48D560(a1 uint16) int32 {
	var v1 *int32
	v1 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(memmap.PtrInt32(0x5D4594, 1197340))))))
	if v1 == nil {
		return 0
	}
	for *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*2)) != int32(a1) {
		v1 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v1)))))
		if v1 == nil {
			return 0
		}
	}
	return 1
}
func sub_48D5A0(a1 unsafe.Pointer) *uint32 {
	var (
		result *uint32
		v2     *uint32
	)
	result = (*uint32)(unsafe.Pointer(uintptr(sub_48D4F0(*memmap.PtrUint16(0x5D4594, 1197360), *(*uint16)(unsafe.Add(a1, 1))))))
	if result != nil {
		return result
	}
	result = (*uint32)(unsafe.Pointer(uintptr(sub_48D560(*(*uint16)(unsafe.Add(a1, 1))))))
	if result != nil {
		return result
	}
	result = (*uint32)(alloc.Calloc1(int(int32(*(*uint8)(unsafe.Add(a1, 3)))+32), 1))
	v2 = result
	if result == nil {
		return result
	}
	sub_425770(unsafe.Pointer(result))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = uint32(*(*uint16)(unsafe.Add(a1, 1)))
	*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*12)) = uint16(*(*uint8)(unsafe.Add(a1, 3)))
	*(*uint64)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint64(0))*2)) = uint64(nox_platform_get_ticks())
	alloc.Memcpy(unsafe.Add(unsafe.Pointer(v2), 4*8), unsafe.Add(a1, 4), uintptr(*(*uint8)(unsafe.Add(a1, 3))))
	if int32(*memmap.PtrUint16(0x5D4594, 1197360)) == int32(*(*uint16)(unsafe.Add(a1, 1))) {
		dword_5d4594_1197352 = unsafe.Pointer(v2)
	}
	return (*uint32)(unsafe.Pointer(uintptr(sub_425790(memmap.PtrInt32(0x5D4594, 1197340), v2))))
}
func Sub_48D660() {
	if dword_5d4594_1197352 == nil {
		if dword_5d4594_1197356 != nil {
			v0 := uint64(nox_platform_get_ticks()) - *(*uint64)(unsafe.Add(dword_5d4594_1197356, 16))
			if v0 > 0x7530 {
				*memmap.PtrUint16(0x5D4594, 1197360) = *(*uint16)(unsafe.Add(dword_5d4594_1197356, 8))
				dword_5d4594_1197352 = dword_5d4594_1197356
				dword_5d4594_1197356 = unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(dword_5d4594_1197356))))
			}
		}
	}
	v1 := dword_5d4594_1197352
	if dword_5d4594_1197352 != nil {
		for {
			v0 := uint32(*(*int32)(unsafe.Add(v1, 4*2)))
			if uint32(v0) != uint32(*memmap.PtrUint16(0x5D4594, 1197360)) {
				break
			}
			v2 := unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v1))))
			if v2 == nil {
				v2 = unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(memmap.PtrInt32(0x5D4594, 1197340)))))
				if v2 == v1 {
					v2 = nil
				}
			}
			nox_xxx_netOnPacketRecvCli_48EA70(31, (*uint8)(unsafe.Add(v1, 4*8)), int32(*(*uint16)(unsafe.Add(v1, unsafe.Sizeof(uint16(0))*12))))
			*memmap.PtrUint16(0x5D4594, 1197360)++
			nox_common_list_remove_425920(v1)
			alloc.FreePtr(v1)
			v1 = v2
			if v2 == nil {
				break
			}
		}
	}
	dword_5d4594_1197356 = v1
	dword_5d4594_1197352 = nil
}
func sub_48D740() {
	nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 1197340)))
	dword_5d4594_1197352 = nil
	dword_5d4594_1197356 = nil
	*memmap.PtrUint16(0x5D4594, 1197360) = 0
}
func sub_48D760() {
	var (
		v0 *int32
		v1 *int32
	)
	v0 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(memmap.PtrInt32(0x5D4594, 1197340))))))
	if v0 != nil {
		for {
			v1 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v0)))))
			nox_common_list_remove_425920(unsafe.Pointer(v0))
			alloc.Free(v0)
			v0 = v1
			if v1 == nil {
				break
			}
		}
	}
	nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 1197340)))
	*memmap.PtrUint16(0x5D4594, 1197360) = 0
}
func sub_48D7B0() {
	for it := unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(memmap.PtrInt32(0x5D4594, 1197340))))); it != nil; it = unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(it)))) {
	}
}
func sub_48D800() int32 {
	if nox_alloc_chat_1197364 != nil {
		nox_free_alloc_class((*nox_alloc_class)(nox_alloc_chat_1197364))
	}
	nox_alloc_chat_1197364 = nil
	*memmap.PtrUint32(0x5D4594, 1197368) = 0
	return 1
}
func sub_48D830(dr *client.Drawable) int32 {
	return bool2int32(nox_xxx_netCode2ChatBubble_48D850(int32(dr.Field_32)) != nil)
}
func nox_xxx_netCode2ChatBubble_48D850(a1 int32) unsafe.Pointer {
	result := *memmap.PtrPtr(0x5D4594, 1197368)
	if *memmap.PtrUint32(0x5D4594, 1197368) == 0 {
		return nil
	}
	for *(*uint32)(unsafe.Add(result, 656)) != uint32(a1) {
		result = *(*unsafe.Pointer)(unsafe.Add(result, 684))
		if result == nil {
			return nil
		}
	}
	return result
}
func nox_xxx_createTextBubble_48D880(a1 unsafe.Pointer, a2 *wchar2_t) {
	var (
		v2     *wchar2_t
		v3     int32
		result *wchar2_t
		v5     int32
		v6     int32
	)
	v2 = (*wchar2_t)(unsafe.Pointer(nox_xxx_netCode2ChatBubble_48D850(int32(*(*uint16)(unsafe.Add(a1, 1))))))
	if v2 != nil {
		v3 = 0
	} else {
		result = (*wchar2_t)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_chat_1197364)))
		v2 = result
		if result == nil {
			return
		}
		v3 = 1
	}
	nox_wcscpy(v2, a2)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*159)) = uint32(*(*uint8)(unsafe.Add(a1, 8)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*161)) = *(*uint32)(unsafe.Add(a1, 4))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*164)) = uint32(*(*uint16)(unsafe.Add(a1, 1)))
	if int32(*(*uint16)(unsafe.Add(a1, 9))) != 0 {
		v6 = int32(*(*uint16)(unsafe.Add(a1, 9)))
	} else {
		v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*159)) / 8)
		if v5 >= 8 {
			v5 = 8
		}
		v6 = int32(gameFPS() * uint32(v5+2))
	}
	result = (*wchar2_t)(unsafe.Pointer(uintptr(gameFrame() + uint32(v6))))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*160)) = uint32(uintptr(unsafe.Pointer(result)))
	if v3 == 0 {
		return
	}
	result = *(**wchar2_t)(memmap.PtrOff(0x5D4594, 1197368))
	if *memmap.PtrUint32(0x5D4594, 1197368) != 0 {
		*(*uint32)(unsafe.Add(dword_5d4594_1197372, 684)) = uint32(uintptr(unsafe.Pointer(v2)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*172)) = dword_5d4594_1197372
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*171)) = 0
		dword_5d4594_1197372 = unsafe.Pointer(v2)
	} else {
		*memmap.PtrPtr(0x5D4594, 1197368) = unsafe.Pointer(v2)
		dword_5d4594_1197372 = unsafe.Pointer(v2)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*172)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*171)) = 0
	}
}
func sub_48D990(a1p *noxrender.Viewport) {
	var (
		a1  = a1p
		v1  int32
		v2  *uint32
		v5  *byte
		v6  *byte
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v18 int32
		i   int32
		v20 *uint16
		v21 int32
		v22 int32
		v23 int32
		v24 int32
		v25 int32
		v26 int32
		v27 int32
		v28 int32
		v29 int32
	)
	v22 = nox_xxx_guiFontHeightMB_43F320(nil)
	v1 = v22 / 2
	sub_437260()
	sub_48DCF0(a1)
	v2 = *(**uint32)(memmap.PtrOff(0x5D4594, 1197368))
	v30 := *memmap.PtrPtr(0x5D4594, 1197368)
	if *memmap.PtrUint32(0x5D4594, 1197368) == 0 {
		sub_437290()
		return
	}
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*165)) != 0 {
			v3 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*167))
			v21 = int32(nox_color_white_2523948)
			v20 = nil
			if v3 != nil && int32(*(*uint8)(unsafe.Add(v3, 112)))&4 != 0 {
				v4 := nox_xxx_objGetTeamByNetCode_418C80(*(*uint32)(unsafe.Add(v3, 128)))
				v5 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*164))))))
				if v5 != nil {
					v20 = (*uint16)(unsafe.Add(unsafe.Pointer(v5), 4704))
				}
				if v4 != nil {
					v6 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(v4.ID))))
					if v6 != nil {
						v7 = int32(nox_xxx_materialGetTeamColor_418D50((*server.Team)(unsafe.Pointer(v6))))
						v21 = v7
					}
				}
			}
			v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*162)))
			v18 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*163)))
			for i = 0; i < 2; i++ {
				if i != 0 {
					v9 = int32(*memmap.PtrUint32(0x85B3FC, 956))
					v8--
					v18--
				} else {
					v9 = int32(*memmap.PtrUint32(0x852978, 4))
				}
				nox_client_drawSetColor_434460(v9)
				v23 = v8 - v1
				nox_client_drawAddPoint_49F500(v8, v18-v1)
				nox_client_drawAddPoint_49F500(v8-v1, v18)
				nox_client_drawLineFromPoints_49E4B0()
				v10 = int32(*(*uint32)(unsafe.Add(v30, 672)))
				v11 = v10 + v8
				v24 = v10 + v8
				nox_client_drawAddPoint_49F500(v8, v18-v1)
				nox_client_drawAddPoint_49F500(v11, v18-v1)
				nox_client_drawLineFromPoints_49E4B0()
				v12 = v1 + v11
				nox_client_drawAddPoint_49F500(v12, v18)
				nox_client_drawAddPoint_49F500(v24, v18-v1)
				nox_client_drawLineFromPoints_49E4B0()
				v25 = v12
				v27 = int32(uint32(v18) + *(*uint32)(unsafe.Add(v30, 676)))
				nox_client_drawAddPoint_49F500(v12, v18)
				nox_client_drawAddPoint_49F500(v12, v27)
				nox_client_drawLineFromPoints_49E4B0()
				v13 = v1 + v27
				v14 = v12 - v1
				nox_client_drawAddPoint_49F500(v14, v1+v27)
				nox_client_drawAddPoint_49F500(v25, v27)
				nox_client_drawLineFromPoints_49E4B0()
				if *(*uint32)(unsafe.Add(v30, 664)) != 0 {
					v28 = v1 + v27
					v26 = v1 + v8 + *(*int32)(unsafe.Add(v30, 672))/2
					nox_client_drawAddPoint_49F500(v14, v13)
					nox_client_drawAddPoint_49F500(v26, v13)
					nox_client_drawLineFromPoints_49E4B0()
					v15 = v22 + v13
					v29 = v8 + *(*int32)(unsafe.Add(v30, 672))/2
					nox_client_drawAddPoint_49F500(v29, v15)
					nox_client_drawAddPoint_49F500(v26, v28)
					nox_client_drawLineFromPoints_49E4B0()
					v16 = v8 + *(*int32)(unsafe.Add(v30, 672))/2 - v1
					nox_client_drawAddPoint_49F500(v29, v15)
					v13 = v28
					nox_client_drawAddPoint_49F500(v16, v28)
					nox_client_drawLineFromPoints_49E4B0()
					nox_client_drawAddPoint_49F500(v8, v28)
					nox_client_drawAddPoint_49F500(v16, v28)
				} else {
					nox_client_drawAddPoint_49F500(v8, v13)
					nox_client_drawAddPoint_49F500(v14, v13)
				}
				nox_client_drawLineFromPoints_49E4B0()
				nox_client_drawAddPoint_49F500(v8, v13)
				nox_client_drawAddPoint_49F500(v23, v13-v1)
				nox_client_drawLineFromPoints_49E4B0()
				nox_client_drawAddPoint_49F500(v23, int32(uint32(v13-v1)-*(*uint32)(unsafe.Add(v30, 676))))
				nox_client_drawAddPoint_49F500(v23, v13-v1)
				nox_client_drawLineFromPoints_49E4B0()
			}
			nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
			nox_xxx_drawSetColor_4343E0(*memmap.PtrInt32(0x852978, 4))
			nox_xxx_drawStringWrapHL_43FD00(nil, (*wchar2_t)(v30), v8, v18, 128, 0)
			if v20 != nil {
				nox_xxx_drawSetTextColor_434390(v21)
				nox_xxx_drawStringWrapHL_43FD00(nil, v20, v8, v18-v22-1, 128, 0)
			}
			v2 = (*uint32)(v30)
		}
		v30 = *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*171))
		if v30 == nil {
			break
		}
		v2 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*171)))
	}
	sub_437290()
}
func sub_48DCF0(a1 *noxrender.Viewport) {
	var (
		v1  int32
		v4  int32
		v5  uint32
		v7  int32
		v8  *uint32
		v9  int32
		v10 uint16
		v11 *int32
		v12 int32
		v13 *uint32
	)
	var v14 int32
	var v15 int32
	var v16 int32
	var v17 int32
	var v18 int32
	var v19 int32
	var v20 int32
	var v21 int32
	var v24 int32
	var a1a int4
	var v27 int32
	v1 = nox_xxx_guiFontHeightMB_43F320(nil)
	v2 := *memmap.PtrPtr(0x5D4594, 1197368)
	v3 := a1
	v24 = v1
	v4 = 0
	if *memmap.PtrUint32(0x5D4594, 1197368) != 0 {
		for {
			v5 = *(*uint32)(unsafe.Add(v2, 656))
			v6 := *(*unsafe.Pointer)(unsafe.Add(v2, 684))
			*(*uint32)(unsafe.Add(v2, 680)) = uint32(v4)
			v25 := v6
			v27 = v4 + 1
			*(*uint32)(unsafe.Add(v2, 668)) = 0
			if nox_xxx_netTestHighBit_578B70(v5) != 0 {
				v7 = nox_xxx_netClearHighBit_578B30(int16(uint16(*(*uint32)(unsafe.Add(v2, 656)))))
				v8 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(uint32(v7)).C())
			} else {
				v9 = nox_xxx_netClearHighBit_578B30(int16(uint16(*(*uint32)(unsafe.Add(v2, 656)))))
				v8 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v9)).C())
			}
			*(*uint32)(unsafe.Add(v2, 668)) = uint32(uintptr(unsafe.Pointer(v8)))
			if v8 != nil {
				*(*uint16)(unsafe.Add(v2, 644)) = *(*uint16)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(uint16(0))*6))
				*(*uint16)(unsafe.Add(v2, 646)) = *(*uint16)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(uint16(0))*8))
			}
			v10 = *(*uint16)(unsafe.Add(v2, 646))
			v11 = (*int32)(unsafe.Add(v2, 672))
			*(*uint32)(unsafe.Add(v2, 648)) = uint32(v3.Screen.Min.X + int(uint32(*(*uint16)(unsafe.Add(v2, 644)))) - v3.World.Min.X)
			*(*uint32)(unsafe.Add(v2, 652)) = uint32(v3.Screen.Min.Y + int(uint32(v10)) - v3.World.Min.Y)
			nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(v2), (*int32)(unsafe.Add(v2, 672)), (*int32)(unsafe.Add(v2, 676)), 128)
			if *(*uint32)(unsafe.Add(v2, 672)) > 128 {
				*v11 = 128
			}
			v12 = int32(*(*uint32)(unsafe.Add(v2, 676)))
			*(*uint32)(unsafe.Add(v2, 648)) += uint32(*v11 / (-2))
			v13 = (*uint32)(unsafe.Add(v2, 664))
			*(*uint32)(unsafe.Add(v2, 652)) += uint32(-64 - v12)
			*(*uint32)(unsafe.Add(v2, 660)) = 1
			*(*uint32)(unsafe.Add(v2, 664)) = 1
			if noxflags.HasGame(2048) {
				v14 = int32(*(*uint32)(unsafe.Add(v2, 648)))
				if int(v14) < v3.Screen.Min.X || int(v14) > v3.Screen.Max.X || (func() bool {
					v15 = int32(*(*uint32)(unsafe.Add(v2, 652)) - 64)
					return int(v15) < v3.Screen.Min.Y
				}()) || int(v15) > v3.Screen.Max.Y {
					*(*uint32)(unsafe.Add(v2, 660)) = 0
					*v13 = 0
				}
			}
			if *(*uint32)(unsafe.Add(v2, 660)) != 0 {
				v16 = int32(v3.Screen.Min.X + int(uint32(v24)))
				v17 = int32(*(*uint32)(unsafe.Add(v2, 648)))
				if v17 >= v16 {
					v18 = int32(v3.Screen.Max.X)
					if v24+v17+*v11 <= v18 {
						goto LABEL_22
					}
					v16 = v18 - *v11 - v24
				}
				*(*uint32)(unsafe.Add(v2, 648)) = uint32(v16)
				*v13 = 0
			LABEL_22:
				v19 = int32(v3.Screen.Min.Y + int(uint32(v24*2)) + 2)
				v20 = int32(*(*uint32)(unsafe.Add(v2, 652)))
				if v20 >= v19 {
					v21 = int32(v3.Screen.Max.Y)
					if uint32(v24)+*(*uint32)(unsafe.Add(v2, 676))+uint32(v20) <= uint32(v21) {
						goto LABEL_26
					}
					v19 = int32(uint32(v21) - *(*uint32)(unsafe.Add(v2, 676)) - uint32(v24))
				}
				*(*uint32)(unsafe.Add(v2, 652)) = uint32(v19)
				*v13 = 0
			LABEL_26:
				a1a.field_0 = int32(*(*uint32)(unsafe.Add(v2, 648)))
				a1a.field_4 = int32(*(*uint32)(unsafe.Add(v2, 652)))
				a1a.field_8 = int32(*(*uint32)(unsafe.Add(v2, 648)) + uint32(*v11))
				a1a.field_C = int32(*(*uint32)(unsafe.Add(v2, 676)) + *(*uint32)(unsafe.Add(v2, 652)))
				sub_48E000(&a1a, (*uint32)(unsafe.Add(v2, 664)))
				*(*uint32)(unsafe.Add(v2, 648)) = uint32(a1a.field_0)
				*(*uint32)(unsafe.Add(v2, 652)) = uint32(a1a.field_4)
			}
			if gameFrame() > uint32(*(*int32)(unsafe.Add(v2, 640))) {
				v22 := *(*unsafe.Pointer)(unsafe.Add(v2, 688))
				if v22 != nil {
					*(*uint32)(unsafe.Add(v22, 684)) = *(*uint32)(unsafe.Add(v2, 684))
				} else {
					*memmap.PtrUint32(0x5D4594, 1197368) = *(*uint32)(unsafe.Add(v2, 684))
				}
				v23 := *(*unsafe.Pointer)(unsafe.Add(v2, 684))
				if v23 != nil {
					*(*uint32)(unsafe.Add(v23, 688)) = *(*uint32)(unsafe.Add(v2, 688))
				} else {
					dword_5d4594_1197372 = *(*unsafe.Pointer)(unsafe.Add(v2, 688))
				}
				nox_alloc_class_free_obj_first((*nox_alloc_class)(nox_alloc_chat_1197364), v2)
			}
			v2 = v25
			if v25 == nil {
				v2 = *memmap.PtrPtr(0x5D4594, 1197368)
				goto LABEL_37
			}
			v4 = v27
		}
	}
LABEL_37:
	for v2 != nil {
		sub_48E240(v3, (*uint32)(v2))
		v2 = *(*unsafe.Pointer)(unsafe.Add(v2, 684))
	}
}
func sub_48E000(a1 *int4, a2 *uint32) bool {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v11 int4
	)
	if a1.field_0 < 0 || a1.field_4 < 0 || a1.field_8 > nox_win_width || a1.field_C > nox_win_height {
		*a2 = 0
	}
	v11.field_0 = 0
	v11.field_4 = 0
	v11.field_8 = 563
	if sub_467C80() != 0 {
		v2 = 279
		v11.field_C = 279
		v3 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(a1)), &v11)
		if v3 != 0 || (func() int32 {
			v3 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(&a1.field_8)), &v11)
			return v3
		}()) != 0 {
			a1.field_4 = v2
			*a2 = 0
			goto LABEL_13
		}
	} else {
		v2 = 55
		v11.field_C = 55
		v3 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(a1)), &v11)
		if v3 != 0 {
			a1.field_4 = v2
			*a2 = 0
			goto LABEL_13
		}
		v3 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(&a1.field_8)), &v11)
		if v3 != 0 {
			a1.field_4 = v2
			*a2 = 0
			goto LABEL_13
		}
	}
LABEL_13:
	if nox_client_getRenderGUI() != 0 {
		v11.field_0 = 0
		v11.field_C = nox_win_height
		v11.field_8 = 111
		v11.field_4 = nox_win_height - math.MaxInt8
		v4 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(a1)), &v11)
		if v4 != 0 || (func() int32 {
			v5 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(&a1.field_8)), &v11)
			return v5
		}()) != 0 {
			a1.field_4 += v11.field_4 - a1.field_C
			*a2 = 0
		}
		v11.field_4 = nox_win_height - 74
		v11.field_0 = nox_win_width/2 - 160
		v11.field_8 = v11.field_0 + 320
		v11.field_C = nox_win_height
		v6 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(a1)), &v11)
		if v6 != 0 || (func() int32 {
			v7 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(&a1.field_8)), &v11)
			return v7
		}()) != 0 {
			a1.field_4 += v11.field_4 - a1.field_C
			*a2 = 0
		}
		v11.field_8 = nox_win_width
		v11.field_0 = nox_win_width - 91
		v11.field_C = nox_win_height
		v11.field_4 = nox_win_height - 201
		v8 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(a1)), &v11)
		if v8 != 0 || (func() int32 {
			v9 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(&a1.field_8)), &v11)
			return v9
		}()) != 0 {
			a1.field_4 += v11.field_4 - a1.field_C
			*a2 = 0
		}
		v3 = sub_4C3260()
		if v3 != 0 {
			v11.field_0 = nox_win_width - 87
			v11.field_4 = 0
			v11.field_8 = nox_win_width
			v11.field_C = 145
			v3 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(a1)), &v11)
			if v3 != 0 || (func() int32 {
				v3 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(&a1.field_8)), &v11)
				return v3
			}()) != 0 {
				a1.field_4 = 145
				*a2 = 0
			}
		}
	}
	return v3 != 0
}
func sub_48E240(a1 *noxrender.Viewport, a2 *uint32) int8 {
	var (
		v2  int32
		v3  *uint32
		v4  int32
		v5  *uint32
		v6  int8
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int8
	)
	*(*uint8)(unsafe.Pointer(&v2)) = *memmap.PtrUint8(0x5D4594, 1197368)
	v3 = a2
	if a2 == *(**uint32)(memmap.PtrOff(0x5D4594, 1197368)) {
		return int8(v2)
	}
	v4 = 0
	v5 = *(**uint32)(memmap.PtrOff(0x5D4594, 1197368))
	if *memmap.PtrUint32(0x5D4594, 1197368) == 0 {
		return int8(v2)
	}
	for {
		v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*165)))
		if v2 != 0 {
			v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*170)))
			if uint32(v2) >= *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*170)) {
				goto LABEL_9
			}
			v2 = sub_48E480(a2, v5)
			if v2 != 0 {
				break
			}
		}
		v5 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v5), 4*171)))
		if v5 == nil {
			return int8(v2)
		}
	}
	v4 = 1
LABEL_9:
	if v5 != nil && v4 != 0 {
		v6 = 0
		v15 = 0
		switch sub_48E530(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*162))+*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*168))/2), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*163))+*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*169))/2)) {
		case 17:
			v6 = -96
			v15 = 8
		case 18:
			v6 = 48
			v15 = -118
		case 20:
			v6 = -112
			v15 = 2
		case 33:
			v6 = -64
			v15 = 44
		case 34:
			v6 = -16
			v15 = 15
		case 36:
			v6 = -64
			v15 = 19
		case 65:
			v6 = 96
			v15 = 4
		case 66:
			v6 = 48
			v15 = 69
		case 68:
			v6 = 80
			v15 = 1
		default:
		}
		v7 = 0
		for {
			*(*uint8)(unsafe.Pointer(&v2)) = uint8(int8(1 << v7))
			*(*uint8)(unsafe.Pointer(&v14)) = uint8(int8(1 << v7))
			if int32(uint8(int8(1<<v7)))&int32(uint8(v6)) != 0 {
				sub_48E6A0(int8(v14), v3, v5, &v12, &v13)
				v2 = sub_48E5C0(v3, v12, v13)
				if v2 != 0 {
					break
				}
			}
			if func() int32 {
				p := &v7
				*p++
				return *p
			}() >= 8 {
				goto LABEL_27
			}
		}
		v8 = v13
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*162)) = uint32(v12)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*163)) = uint32(v8)
	LABEL_27:
		if v7 == 8 {
			v9 = 0
			for {
				*(*uint8)(unsafe.Pointer(&v2)) = uint8(int8(1 << v9))
				*(*uint8)(unsafe.Pointer(&v14)) = uint8(int8(1 << v9))
				if int32(uint8(int8(1<<v9)))&int32(uint8(v15)) != 0 {
					sub_48E6A0(int8(v14), v3, v5, &v12, &v13)
					v2 = sub_48E5C0(v3, v12, v13)
					if v2 != 0 {
						break
					}
				}
				if func() int32 {
					p := &v9
					*p++
					return *p
				}() >= 8 {
					return int8(v2)
				}
			}
			v10 = v13
			*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*162)) = uint32(v12)
			*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*163)) = uint32(v10)
		}
	}
	return int8(v2)
}
func sub_48E480(a1 *uint32, a2 *uint32) int32 {
	v2 := nox_xxx_guiFontHeightMB_43F320(nil)
	v3 := int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*162)))
	v7 := int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*163)) - uint32(v2))
	v4 := int32(uint32(v2+v3) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*168)))
	v5 := int32(uint32(v2) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*163)) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*169)))
	v8 := int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*163)))
	return bool2int32(uint32(v3-v2) < uint32(v2)+*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*162))+*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*168)) && uint32(v4) > *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*162))-uint32(v2) && uint32(v7) < uint32(v2+v8)+*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*169)) && v5 > v8-v2)
}
func sub_48E530(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		v3 int32
	)
	if a1 >= nox_win_width/3 {
		v3 = bool2int32(a1 >= nox_win_width*2/3) - 1
		*(*uint8)(unsafe.Pointer(&v3)) = uint8(int8(v3 & 0xE0))
		v2 = v3 + 64
	} else {
		v2 = 16
	}
	if a2 < nox_win_height/3 {
		return v2 | 1
	}
	if a2 >= nox_win_height*2/3 {
		return v2 | 4
	}
	return v2 | 2
}
func sub_48E5C0(a1 *uint32, a2 int32, a3 int32) int32 {
	var (
		v3  int32
		v4  int32
		v6  *uint32
		v7  int32
		v8  int32
		v9  int32
		a2a int32
		a1a int4
	)
	a2a = 1
	nox_xxx_guiFontHeightMB_43F320(nil)
	a1a.field_0 = a2
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*168)))
	a1a.field_4 = a3
	v4 = int32(uint32(a3) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*169)))
	a1a.field_8 = a2 + v3
	a1a.field_C = v4
	sub_48E000(&a1a, (*uint32)(unsafe.Pointer(&a2a)))
	if a2a == 0 {
		return 0
	}
	v6 = *(**uint32)(memmap.PtrOff(0x5D4594, 1197368))
	if *memmap.PtrUint32(0x5D4594, 1197368) != 0 {
		for {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*165)) != 0 {
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*170)) >= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*170)) {
					return 1
				}
				v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*162)))
				v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*163)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*162)) = uint32(a2)
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*163)) = uint32(a3)
				v9 = sub_48E480(a1, v6)
				a2a = v9
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*162)) = uint32(v7)
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*163)) = uint32(v8)
				if v9 != 0 {
					break
				}
			}
			v6 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v6), 4*171)))
			if v6 == nil {
				return 1
			}
		}
		return 0
	}
	return 1
}
func sub_48E6A0(a1 int8, a2 *uint32, a3 *uint32, a4 *int32, a5 *int32) *int32 {
	var (
		result *int32
		v6     int32
		v7     *uint32
		v8     int32
		v9     *byte
		v10    int32
	)
	result = (*int32)(unsafe.Pointer(uintptr(nox_xxx_guiFontHeightMB_43F320(nil) * 2)))
	switch uint8(a1) {
	case 1:
		*a4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*162)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*168)) - uint32(uintptr(unsafe.Pointer(result))))
		*a5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*163)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*169)) - uint32(uintptr(unsafe.Pointer(result))))
		return result
	case 2:
		*a4 = int32(uint32(int32(uintptr(unsafe.Pointer(result)))) + *(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*162)) + *(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*168)))
		v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*163)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*169)) - uint32(uintptr(unsafe.Pointer(result))))
		result = a5
		*a5 = v6
		return result
	case 4:
		v7 = a3
		*a4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*162)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*168)) - uint32(uintptr(unsafe.Pointer(result))))
		v9 = (*byte)(unsafe.Add(unsafe.Add(unsafe.Pointer(result), *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*163))), *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*169))))
		result = a5
		*a5 = int32(uintptr(unsafe.Pointer(v9)))
	case 8:
		v7 = a3
		*a4 = int32(uint32(int32(uintptr(unsafe.Pointer(result)))) + *(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*162)) + *(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*168)))
		v9 = (*byte)(unsafe.Add(unsafe.Add(unsafe.Pointer(result), *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*163))), *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*169))))
		result = a5
		*a5 = int32(uintptr(unsafe.Pointer(v9)))
	case 0x10:
		*a4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*162)))
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*163)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*169)) - uint32(uintptr(unsafe.Pointer(result))))
		result = a5
		*a5 = v8
		return result
	case 0x20:
		*a4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*162)))
		v7 = a3
		v9 = (*byte)(unsafe.Add(unsafe.Add(unsafe.Pointer(result), *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*163))), *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*169))))
		result = a5
		*a5 = int32(uintptr(unsafe.Pointer(v9)))
	case 0x40:
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*162)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*168)) - uint32(uintptr(unsafe.Pointer(result))))
		result = a4
		*a4 = v10
		*a5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*163)))
	case 0x80:
		*a4 = int32(uint32(int32(uintptr(unsafe.Pointer(result)))) + *(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*162)) + *(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*168)))
		result = a5
		*a5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*163)))
	default:
		return result
	}
	return result
}
func sub_48E8E0(a1 int32) {
	v1 := nox_xxx_netCode2ChatBubble_48D850(a1)
	if v1 != nil {
		v2 := *(*unsafe.Pointer)(unsafe.Add(v1, 688))
		if v2 != nil {
			*(*uint32)(unsafe.Add(v2, 684)) = *(*uint32)(unsafe.Add(v1, 684))
		} else {
			*memmap.PtrUint32(0x5D4594, 1197368) = *(*uint32)(unsafe.Add(v1, 684))
		}
		v3 := *(*unsafe.Pointer)(unsafe.Add(v1, 684))
		if v3 != nil {
			*(*uint32)(unsafe.Add(v3, 688)) = *(*uint32)(unsafe.Add(v1, 688))
		}
		nox_alloc_class_free_obj_first((*nox_alloc_class)(nox_alloc_chat_1197364), v1)
	}
}
func sub_48E940() {
	nox_alloc_class_free_all((*nox_alloc_class)(nox_alloc_chat_1197364))
	*memmap.PtrUint32(0x5D4594, 1197368) = 0
}
func nox_xxx_spriteCreate_48E970(a1 int32, a2 uint32, a3 int32, a4 int32) *client.Drawable {
	v4 := nox_xxx_netClearHighBit_578B30(int16(uint16(a2)))
	v5 := v4
	v10 := v4
	var v6 *client.Drawable
	if nox_xxx_netTestHighBit_578B70(a2) != 0 {
		v6 = nox_xxx_netSpriteByCodeStatic_45A720(uint32(v10))
	} else {
		v6 = nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v10))
	}
	v7 := v6
	if v6 != nil {
		nox_xxx_updateSpritePosition_49AA90(v6, a3, a4)
	} else {
		if *memmap.PtrUint32(0x5D4594, 1200836) == 0 {
			*memmap.PtrUint32(0x5D4594, 1200836) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Crown")))
		}
		if *memmap.PtrUint32(0x5D4594, 1200840) == 0 {
			*memmap.PtrUint32(0x5D4594, 1200840) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GameBall")))
		}
		v8 := nox_xxx_spriteLoadAdd_45A360_drawable(a1, a3, a4)
		v7 = v8
		if v8 == nil {
			nox_xxx_spriteLoadError_4356E0()
			return nil
		}
		v8.Field_32 = uint32(v5)
		if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1200836) || uint32(a1) == *memmap.PtrUint32(0x5D4594, 1200840) || v8.Flags28Val&0x10000000 != 0 {
			sub_459DD0(v8, 1)
		}
	}
	nox_xxx_spriteSetActiveMB_45A990_drawable(unsafe.Pointer(v7))
	nox_xxx_sprite_49BA10(v7)
	v7.Field_80 = gameFrame()
	v7.Field_122 = 0
	return v7
}
func sub_4947E0(a1 *server.Player) {
	var (
		v1 int16
		v2 int32
	)
	if noxflags.HasGame(1) {
		v1 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
		v2 = int32(uint16(nox_xxx_servGamedataGet_40A020(v1)))
	} else {
		v2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(nox_xxx_cliGamedataGet_416590(0)), unsafe.Sizeof(uint16(0))*27)))
	}
	result := nox_common_playerInfoGetFirst_416EA0()
	for i := result; result != nil; i = result {
		if (int32(*(*uint8)(unsafe.Add(i.C(), 3680))) & 1) == 0 {
			if i == a1 {
				if noxflags.HasGame(1024) {
					if i.Field2140 >= uint32(v2) {
						i.Field2140 = uint32(v2 - 1)
					}
				} else {
					i.Lessons = v2
				}
			} else if noxflags.HasGame(1024) {
				if i.Field2140 < uint32(v2) {
					i.Field2140 = uint32(v2)
				}
			} else if i.Lessons >= int32(v2) {
				i.Lessons = v2 - 1
			}
		}
		result = nox_common_playerInfoGetNext_416EE0(i)
	}
}
func sub_4948B0(a1 *server.Team) {
	var (
		v1 int16
		v2 int32
	)
	if noxflags.HasGame(1) {
		v1 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
		v2 = int32(uint16(nox_xxx_servGamedataGet_40A020(v1)))
	} else {
		v2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(nox_xxx_cliGamedataGet_416590(0)), unsafe.Sizeof(uint16(0))*27)))
	}
	for i := nox_server_teamFirst_418B10(); i != nil; i = nox_server_teamNext_418B60(i) {
		if i == a1 {
			if !noxflags.HasGame(1024) {
				i.Lessons = int(uint32(v2))
			}
		} else if !noxflags.HasGame(1024) && i.Lessons >= int(uint32(v2)) {
			i.Lessons = int(uint32(v2 - 1))
		}
	}
	if noxflags.HasGame(1) {
		result := nox_xxx_getFirstPlayerUnit_4DA7C0()
		for j := result; result != nil; j = result {
			if nox_xxx_teamCompare2_419180(j.TeamPtr(), a1.IDVal) == 0 {
				v6 := nox_common_playerInfoGetByID_417040(int32(j.NetCode))
				v7 := v6
				if v6 != nil {
					if (*(*byte)(unsafe.Add(unsafe.Pointer(v6), 3680)) & 1) == 0 {
						if noxflags.HasGame(1024) {
							if v7.Field2140 < uint32(v2) {
								v7.Field2140 = uint32(v2)
							}
						} else if v7.Lessons >= int32(v2) {
							v7.Lessons = v2 - 1
						}
					}
				}
			}
			result = nox_xxx_getNextPlayerUnit_4DA7F0(j)
		}
	} else {
		result := nox_xxx_cliGetSpritePlayer_45A000()
		for k := result; result != nil; k = result {
			if nox_xxx_teamCompare2_419180(k.TeamPtr(), a1.IDVal) == 0 {
				v9 := nox_common_playerInfoGetByID_417040(int32(k.Field_32))
				v10 := v9
				if v9 != nil {
					if (*(*byte)(unsafe.Add(unsafe.Pointer(v9), 3680)) & 1) == 0 {
						if noxflags.HasGame(1024) {
							if v10.Field2140 < uint32(v2) {
								v10.Field2140 = uint32(v2)
							}
						} else if v10.Lessons >= int32(v2) {
							v10.Lessons = v2 - 1
						}
					}
				}
			}
			result = sub_45A010(k)
		}
	}
}
func nox_xxx_netCliProcUpdateStream_494A60(a1 []byte, a2 int32, a3 *uint32) int32 {
	var (
		v3  uint16
		v4  uint16
		v5  []byte
		v6  int32
		v8  uint16
		v9  uint16
		v11 uint8
		v14 uint8
		v17 uint8
		v18 int32
		v20 uint16
		v21 uint16
		v23 [10]byte
		v24 uint8
		v25 uint8
		v26 uint8
	)
	old := a1
	if a1[0] == math.MaxUint8 {
		v3 = *(*uint16)(unsafe.Add(unsafe.Pointer(a1), 1))
		v4 = *(*uint16)(unsafe.Add(unsafe.Pointer(a1), 3))
		v5 = a1[5:]
		v6 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), 3)))
		v24 = uint8(nox_xxx_cliGenerateAlias_57B9A0(int32(uintptr(memmap.PtrOff(0x5D4594, 1198020))), int32(v3), v6, gameFrame()))
		if int32(v24) != -1 {
			sub_57BA10(int32(uintptr(memmap.PtrOff(0x5D4594, uintptr(int32(v24)*8)+1198020))), int16(v3), int16(v6), -1)
			v23[0] = 165
			*(*uint16)(unsafe.Pointer(&v23[2])) = v3
			*(*uint16)(unsafe.Pointer(&v23[4])) = v4
			v23[1] = v24
			*(*uint32)(unsafe.Pointer(&v23[6])) = math.MaxUint32
			nox_netlist_addToMsgListCli_40EBC0(a2, 0, &v23[0], 10)
		}
	} else {
		v7 := int32(a1[0]) * 8
		v5 = a1[1:]
		v3 = *memmap.PtrUint16(0x5D4594, uintptr(v7)+1198020)
		v4 = *memmap.PtrUint16(0x5D4594, uintptr(v7)+1198022)
	}
	v8 = *(*uint16)(unsafe.Pointer(v5))
	v9 = *(*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*1))
	v20 = *(*uint16)(unsafe.Pointer(v5))
	v10 := v5[4:]
	v21 = v9
	v11 = v10[0]
	v12 := v10[1:]
	if (int32(v11) & 0x80) == 0 {
		v25 = 0
	} else {
		v25 = v12[0]
		v12 = v12[1:]
	}
	v14 = v12[0]
	v15 := v12[1:]
	v26 = v14
	if int32(v3) != 0 || int32(v4) != 0 {
		v16 := nox_xxx_spriteCreate_48E970(int32(v4), uint32(v3), int32(v8), int32(v9))
		if v16 != nil {
			v16.Field_72 = gameFrame()
			v17 = uint8(int8((int32(v11) >> 4) & 7))
			v16.Field_74_2 = v17
			if int32(v17) > 3 {
				v16.Field_74_2 = uint8(int8(int32(v17) + 1))
			}
			if v16.Field_69 != uint32(v26) {
				v18 = int32(gameFrame())
				v16.Field_69 = uint32(v26)
				v16.Field_79 = uint32(v18)
			}
			nox_xxx_spriteSetFrameMB_45AB80(unsafe.Pointer(v16), int32(v25))
		}
	}
	*a3 = uint32(v20)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) = uint32(v21)
	nox_xxx_cliUpdateCameraPos_435600(int32(v20), int32(v21))
	return int32(uint32(v15) - uint32(uintptr(unsafe.Pointer(old))))
}
func nox_xxx_netCliUpdateStream2_494C30(a1 *uint8, a2 int32, a3 *int32) int32 {
	var (
		v3  *uint8
		v4  uint8
		v6  uint16
		v7  *uint16
		v8  uint16
		v9  uint16
		v10 *int16
		v11 int32
		v12 int32
		v13 *int32
		v15 int32
		v16 int32
		v17 int32
		v20 int8
		v21 uint8
		v22 uint8
		v23 int32
		v24 uint8
		v25 int32
		v26 [10]byte
		v27 int8
		v28 uint8
	)
	v3 = a1
	v4 = *a1
	v25 = 0
	if int32(*a1) == 0 {
		v4 = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 1))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(a1), 1))
		if int32(v4) == 0 && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 2))) == 0 {
			return -3
		}
		v25 = 1
	}
	if int32(v4) == math.MaxUint8 {
		v6 = *(*uint16)(unsafe.Add(unsafe.Pointer(v3), 1))
		v7 = (*uint16)(unsafe.Add(unsafe.Pointer(v3), 3))
		v8 = *v7
		v9 = *v7
		v10 = (*int16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*1))
		v24 = uint8(nox_xxx_cliGenerateAlias_57B9A0(int32(uintptr(memmap.PtrOff(0x5D4594, 1198020))), int32(v6), int32(v9), gameFrame()))
		if int32(v24) != -1 {
			sub_57BA10(int32(uintptr(memmap.PtrOff(0x5D4594, uintptr(int32(v24)*8)+1198020))), int16(v6), int16(v9), int32(gameFrame()+60))
			v26[1] = v24
			v26[0] = 165
			*(*uint16)(unsafe.Pointer(&v26[2])) = v6
			*(*uint16)(unsafe.Pointer(&v26[4])) = v8
			*(*uint32)(unsafe.Pointer(&v26[6])) = gameFrame() + 60
			nox_netlist_addToMsgListCli_40EBC0(a2, 0, &v26[0], 10)
		}
	} else {
		v11 = int32(v4) * 8
		v10 = (*int16)(unsafe.Add(unsafe.Pointer(v3), 1))
		v6 = *memmap.PtrUint16(0x5D4594, uintptr(v11)+1198020)
		v8 = *memmap.PtrUint16(0x5D4594, uintptr(v11)+1198022)
	}
	var v14 unsafe.Pointer
	if v25 != 0 {
		v12 = int32(*(*int16)(v10))
		v13 = a3
		v14 = unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(int16(0))*2)
		*a3 = v12
		*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) = int32(*(*int16)(unsafe.Add(v14, -2)))
	} else {
		v13 = a3
		v15 = int32(*(*byte)(unsafe.Pointer(v10)))
		v14 = unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(int16(0))*1)
		*a3 += v15
		*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) += int32(*(*byte)(unsafe.Add(v14, -1)))
	}
	v16 = *v13
	if *v13 < 0 {
		return int32(int64(uintptr(unsafe.Pointer(a1))) - int64(uintptr(unsafe.Pointer(v14))))
	}
	if v16 > 6000 {
		return int32(int64(uintptr(unsafe.Pointer(a1))) - int64(uintptr(unsafe.Pointer(v14))))
	}
	v17 = *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1))
	if v17 < 0 {
		return int32(int64(uintptr(unsafe.Pointer(a1))) - int64(uintptr(unsafe.Pointer(v14))))
	}
	if v17 > 6000 {
		return int32(int64(uintptr(unsafe.Pointer(a1))) - int64(uintptr(unsafe.Pointer(v14))))
	}
	v18 := nox_xxx_spriteCreate_48E970(int32(v8), uint32(v6), v16, *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1)))
	v19 := v18
	if v18 == nil {
		return int32(int64(uintptr(unsafe.Pointer(a1))) - int64(uintptr(unsafe.Pointer(v14))))
	}
	if v18.Flags28Val&0x200000 != 0 {
		v18.Field_72 = gameFrame()
		v27 = int8(*(*uint8)(v14))
		v20 = int8(*(*uint8)(v14))
		v21 = uint8(int8((int32(*(*uint8)(v14)) >> 4) & 7))
		v19.Field_74_2 = v21
		if int32(v21) > 3 {
			v19.Field_74_2 = uint8(int8(int32(v21) + 1))
		}
		if int32(v20) < 0 {
			nox_xxx_spriteSetFrameMB_45AB80(unsafe.Pointer(v19), int32(*(*uint8)(unsafe.Pointer(uintptr(func() unsafe.Pointer {
				p := &v14
				*p = unsafe.Add(*p, 1)
				return *p
			}())))))
			v20 = v27
		}
		if int32(*(*uint8)(unsafe.Add(v19.C(), 112)))&4 != 0 {
			v22 = *(*uint8)(unsafe.Pointer(uintptr(func() unsafe.Pointer {
				p := &v14
				*p = unsafe.Add(*p, 1)
				return *p
			}())))
			v28 = v22
		} else {
			v28 = uint8(int8(int32(v20) & 0xF))
		}
		if v19.Field_69 != uint32(v28) {
			v23 = int32(gameFrame())
			v19.Field_69 = uint32(v28)
			v19.Field_79 = uint32(v23)
		}
		v14 = unsafe.Add(v14, 1)
	} else {
		v18.Field_72 = gameFrame()
		nox_xxx_sprite_49AA00_drawable(v18)
	}
	*v13 = int32(v19.PosVec.X)
	*(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1)) = int32(v19.PosVec.Y)
	return int32(int64(uintptr(unsafe.Pointer(v14))) - int64(uintptr(unsafe.Pointer(a1))))
}
func sub_494F00() int32 {
	var (
		v1 int32
	)
	*memmap.PtrUint32(0x5D4594, 1200772) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Spark")))
	if *memmap.PtrUint32(0x5D4594, 1200772) == 0 {
		return 0
	}
	result := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueSpark"))
	dword_5d4594_1200776 = uint32(result)
	if result == 0 {
		return 0
	}
	result = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("YellowSpark"))
	*memmap.PtrUint32(0x5D4594, 1200780) = uint32(result)
	if result == 0 {
		return 0
	}
	result = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CyanSpark"))
	*memmap.PtrUint32(0x5D4594, 1200784) = uint32(result)
	if result == 0 {
		return 0
	}
	result = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GreenSpark"))
	*memmap.PtrUint32(0x5D4594, 1200788) = uint32(result)
	if result == 0 {
		return 0
	}
	result = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Puff"))
	*memmap.PtrUint32(0x5D4594, 1200792) = uint32(result)
	if result == 0 {
		return 0
	}
	v1 = 0
	for {
		v2 := nox_xxx_getTTByNameSpriteMB_44CFC0(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1)+161216)))
		*memmap.PtrUint32(0x5D4594, uintptr(v1)+1200812) = uint32(v2)
		if v2 == 0 {
			break
		}
		v1 += 4
		if v1 >= 20 {
			dword_5d4594_1200796 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("VioletSpark")))
			return bool2int32(dword_5d4594_1200796 != 0)
		}
	}
	return 0
}
func sub_494FF0() *byte {
	var (
		v0 int32
		v1 *uint8
	)
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1200928))
	for *(*uint32)(unsafe.Pointer(v1)) != 0 {
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 16))
		v0++
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1201440))) {
			return nil
		}
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v0*16)+1200916))
}
func sub_495020(a1 int32) *byte {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1200916))
	for *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) == 0 || *(*uint32)(unsafe.Pointer(v2)) != uint32(a1) {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 16))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1201428))) {
			return nil
		}
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v1*16)+1200916))
}
func sub_495060(a1 int32, a2 int16, a3 int16) int32 {
	v3 := (*uint8)(memmap.PtrOff(0x5D4594, 1200916))
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)) == 1 && *(*uint32)(unsafe.Pointer(v3)) == uint32(a1) {
			return 1
		}
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 16))
		if int32(uintptr(unsafe.Pointer(v3))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1201428))) {
			break
		}
	}
	v4 := sub_494FF0()
	if v4 == nil {
		return 0
	}
	*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*3)) = uint16(a2)
	*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*4)) = uint16(a3)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) = 1
	*(*byte)(unsafe.Add(unsafe.Pointer(v4), 4)) = 0
	*(*uint32)(unsafe.Pointer(v4)) = uint32(a1)
	return 1
}
func sub_4950C0(a1 int32) int32 {
	v1 := sub_495020(a1)
	if v1 == nil {
		return 0
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3)) = 0
	return 1
}
func sub_4950F0(a1 int32, a2 int8) int32 {
	v2 := sub_495020(a1)
	if v2 == nil {
		return 0
	}
	*(*byte)(unsafe.Add(unsafe.Pointer(v2), 4)) = byte(a2)
	return 1
}
func sub_495120(a1 int32, a2 int16, a3 int16) int32 {
	v3 := sub_495020(a1)
	if v3 == nil {
		return 0
	}
	*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*3)) = uint16(a2)
	*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*4)) = uint16(a3)
	return 1
}
func sub_495150(a1 int32, a2 int16) int32 {
	v2 := sub_495020(a1)
	if v2 == nil {
		return 0
	}
	*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*3)) = uint16(a2)
	return 1
}
func sub_495180(a1 int32, a2 *uint16, a3 *uint16, a4 *uint8) int32 {
	v4 := sub_495020(a1)
	if v4 == nil {
		return 0
	}
	*a2 = *(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*3))
	*a3 = *(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*4))
	*a4 = *(*byte)(unsafe.Add(unsafe.Pointer(v4), 4))
	return 1
}
func Sub_4951C0() {
	result := (*byte)(memmap.PtrOff(0x5D4594, 1200922))
	for {
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), 6)) = 0
		*(*uint16)(unsafe.Pointer(result)) = 0
		*(*uint16)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(uint16(0))*1)) = 0
		*(*byte)(unsafe.Add(unsafe.Pointer(result), -2)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), -6)) = 0
		result = (*byte)(unsafe.Add(unsafe.Pointer(result), 16))
		if int32(uintptr(unsafe.Pointer(result))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1201434))) {
			break
		}
	}
}
func nox_xxx_unitSpriteCheckAlly_4951F0(a1 int32) int32 {
	return bool2int32(sub_495020(a1) != nil)
}
func sub_495210(a1 unsafe.Pointer) {
	var (
		v1 int32
		v2 int32
		v3 int32
	)
	v1 = int32(dword_5d4594_1203836)
	if (dword_5d4594_1203836+1)%100 == dword_5d4594_1203840 {
		dword_5d4594_1203840 = (dword_5d4594_1203840 + 1) % 100
	}
	if int32(*(*uint8)(unsafe.Add(a1, 10))) == 1 {
		v2 = int32(*(*uint16)(unsafe.Add(a1, 8)))
		if uint32(uint16(int16(v2))) == *memmap.PtrUint32(0x5D4594, 1203844) {
			*(*uint16)(unsafe.Add(a1, 8)) = *memmap.PtrUint16(0x5D4594, 1203856)
			v1 = int32(dword_5d4594_1203836)
			goto LABEL_9
		}
		if uint32(v2) == *memmap.PtrUint32(0x5D4594, 1203848) {
			*(*uint16)(unsafe.Add(a1, 8)) = *memmap.PtrUint16(0x5D4594, 1203852)
			v1 = int32(dword_5d4594_1203836)
			goto LABEL_9
		}
	}
LABEL_9:
	v3 = v1 * 24
	*memmap.PtrUint32(0x5D4594, uintptr(v3)+1201428) = uint32(*(*uint16)(unsafe.Add(a1, 2)))
	*memmap.PtrUint32(0x5D4594, uintptr(v3)+1201432) = uint32(*(*uint16)(unsafe.Add(a1, 4)))
	*memmap.PtrUint32(0x5D4594, uintptr(v3)+1201436) = uint32(*(*uint16)(unsafe.Add(a1, 6)))
	*memmap.PtrUint32(0x5D4594, uintptr(v3)+1201440) = uint32(*(*uint16)(unsafe.Add(a1, 8)))
	*memmap.PtrUint32(0x5D4594, uintptr(v3)+1201444) = uint32(*(*uint8)(unsafe.Add(a1, 10)))
	*memmap.PtrUint32(0x5D4594, uintptr(v3)+1201448) = gameFrame()
	dword_5d4594_1203836 = uint32((v1 + 1) % 100)
	sub_4952E0((*uint16)(a1))
}
func Sub_495430() int32 {
	var (
		v0     int32
		v1     int32
		result int32
		i      int32
		v4     int64
	)
	dword_5d4594_1203832 = 0
	nox_client_drawEnableAlpha_434560(0)
	sub_4345F0(0)
	nox_xxx_draw_434600(0)
	v0 = int32(dword_5d4594_1203840)
	v1 = int32(dword_5d4594_1203840)
	result = int32(dword_5d4594_1203836)
	for i = nox_win_height / 4 / 36; uint32(v1) != dword_5d4594_1203836; v1 = (v1 + 1) % 100 {
		if dword_5d4594_1203832 > uint32(i) {
			break
		}
		if (gameFrame() - *memmap.PtrUint32(0x5D4594, uintptr(v0)*24+1201448)) <= 0x5A {
			sub_495500(memmap.PtrInt32(0x5D4594, uintptr(v1)*24+1201428))
			v0 = int32(dword_5d4594_1203840)
			dword_5d4594_1203832++
		} else {
			v4 = int64(v0 + 1)
			v0 = (v0 + 1) % 100
			dword_5d4594_1203840 = uint32(int32(v4 % 100))
		}
		result = int32(dword_5d4594_1203836)
	}
	return result
}
func sub_495500(a1 *int32) {
	var (
		v2  int32
		v3  int32
		v4  bool
		v8  noxrender.ImageHandle
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v20 int32
		v21 int32
		v22 int32
		v23 int32
		v25 int32
		v26 int32
		v27 int32
		v28 [32]wchar2_t
		v29 [32]wchar2_t
		v30 [32]wchar2_t
		t9  *client.ObjectType
	)
	v1 := nox_xxx_guiFontPtrByName_43F360(internCStr("large"))
	v2 = *a1
	v3 = 0
	v4 = *a1 == 0
	v24 := v1
	v29[0] = 0
	v28[0] = 0
	v30[0] = 0
	v23 = 0
	v25 = 0
	v27 = 0
	v26 = 0
	if !v4 {
		v5 := nox_common_playerInfoGetByID_417040(v2)
		if v5 != nil {
			v3 = 1
			nox_swprintf(&v29[0], (*wchar2_t)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(wchar2_t(0))*2352)))
		}
	}
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) != 0 {
		v6 := nox_common_playerInfoGetByID_417040(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
		if v6 != nil {
			if v3 != 0 {
				nox_swprintf(&v28[0], internWStr("+%s"), (*byte)(unsafe.Add(unsafe.Pointer(v6), 4704)))
			} else {
				nox_swprintf(&v28[0], (*wchar2_t)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(wchar2_t(0))*2352)))
			}
		}
	}
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) != 0 {
		v7 := nox_common_playerInfoGetByID_417040(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
		if v7 != nil {
			nox_swprintf(&v30[0], (*wchar2_t)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(wchar2_t(0))*2352)))
		}
	}
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) != 1 {
		if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) == 2 {
			switch *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) {
			case 1, 12:
				v8 = nox_xxx_spellIcon_424A90(5)
				goto LABEL_26
			case 2:
				v8 = nox_xxx_spellGetAbilityIcon_425310(1, 0)
				goto LABEL_26
			case 4:
				v8 = nox_xxx_spellIcon_424A90(130)
				goto LABEL_26
			case 5:
				v8 = nox_xxx_spellIcon_424A90(60)
				goto LABEL_26
			case 9, 17:
				v8 = nox_xxx_spellIcon_424A90(43)
				goto LABEL_26
			case 15:
				v8 = nox_xxx_spellIcon_424A90(56)
				goto LABEL_26
			case 16:
				v8 = nox_xxx_spellIcon_424A90(16)
				goto LABEL_26
			default:
			}
		}
		v8 = noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, 1203828))
		goto LABEL_28
	}
	t9 = nox_get_thing(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
	if t9 == nil {
		v8 = noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, 1203828))
		goto LABEL_28
	}
	if t9.ObjClass&0x1001000 != 0 {
		sub_4B9650(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
	}
	v8 = t9.PrettyImage
LABEL_26:
	if v8 == nil {
		v8 = noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, 1203828))
	}
LABEL_28:
	nox_draw_imageMeta_47D5C0(v8, (*uint32)(unsafe.Pointer(&v27)), (*uint32)(unsafe.Pointer(&v26)), (*uint32)(unsafe.Pointer(&v23)), (*uint32)(unsafe.Pointer(&v25)))
	nox_xxx_drawGetStringSize_43F840(v1, &v29[0], &v21, &v22, 0)
	v11 = v21
	nox_xxx_drawGetStringSize_43F840(v1, &v28[0], &v21, &v22, 0)
	v12 = v21 + v11
	nox_xxx_drawGetStringSize_43F840(v1, &v30[0], &v21, &v22, 0)
	v13 = v12 + v23 + v21 + 20
	v14 = nox_win_width - (v12 + v23 + v21 + 10)
	v15 = v14 / 2
	v16 = int32(dword_5d4594_1203832 * 36)
	nox_client_drawRectFilledAlpha_49CF10(v14/2-5, int32(dword_5d4594_1203832*36), v13, 36)
	v17 = v16 + (36-v22)/2
	if *a1 != 0 {
		nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x5D4594, 2597996))
		if uint32(*a1) == nox_player_netCode_85319C {
			nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x8531A0, 2572))
		}
		v15 = nox_xxx_drawString_43F6E0(v24, &v29[0], v14/2, v17)
	}
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) != 0 {
		nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x5D4594, 2597996))
		if uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))) == nox_player_netCode_85319C {
			nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x8531A0, 2572))
		}
		v15 = nox_xxx_drawString_43F6E0(v24, &v28[0], v15, v17)
	}
	v18 = v15 + 5
	if v8 != nil {
		nox_client_drawImageAt_47D2C0(v8, v18-v27, v16+(36-v25)/2-v26)
	}
	v20 = v18 + v23 + 5
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) == 0 {
		return
	}
	nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x5D4594, 2597996))
	if uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2))) == nox_player_netCode_85319C {
		nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x8531A0, 2572))
	}
	nox_xxx_drawString_43F6E0(v24, &v30[0], v20, v17)
}
func Sub_4958F0() {
	dword_5d4594_1203840 = 0
	dword_5d4594_1203836 = 0
	if *memmap.PtrUint32(0x5D4594, 1203844) == 0 {
		*memmap.PtrUint32(0x5D4594, 1203844) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ArcherBolt")))
	}
	if *memmap.PtrUint32(0x5D4594, 1203848) == 0 {
		*memmap.PtrUint32(0x5D4594, 1203848) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ArcherArrow")))
	}
	if *memmap.PtrUint32(0x5D4594, 1203852) == 0 {
		*memmap.PtrUint32(0x5D4594, 1203852) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Bow")))
	}
	if *memmap.PtrUint32(0x5D4594, 1203856) == 0 {
		*memmap.PtrUint32(0x5D4594, 1203856) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CrossBow")))
	}
	*memmap.PtrUint32(0x5D4594, 1203828) = uint32(int32(uintptr(nox_xxx_spellIcon_424A90(15))))
}
func nox_xxx_allocClassListFriends_495980() int32 {
	nox_alloc_friendList_1203860 = unsafe.Pointer(nox_new_alloc_class(internCStr("FriendListClass"), 8, 128))
	return bool2int32(nox_alloc_friendList_1203860 != nil)
}
func sub_4959B0() {
	nox_alloc_class_free_all((*nox_alloc_class)(nox_alloc_friendList_1203860))
	dword_5d4594_1203864 = nil
}
func Sub_4959D0() {
	nox_free_alloc_class((*nox_alloc_class)(nox_alloc_friendList_1203860))
	nox_alloc_friendList_1203860 = nil
	dword_5d4594_1203864 = nil
}
func nox_xxx_cliAddObjFriend_4959F0(a1 int32) {
	result := (*uint32)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_friendList_1203860)))
	if result == nil {
		return
	}
	*result = uint32(a1)
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(result), 4*1)) = dword_5d4594_1203864
	dword_5d4594_1203864 = unsafe.Pointer(result)
}
func sub_495A20(a1 int32) {
	var (
		v2 unsafe.Pointer
	)
	v1 := dword_5d4594_1203864
	v2 = nil
	if dword_5d4594_1203864 != nil {
		for *(*uint32)(v1) != uint32(a1) {
			v2 = v1
			v1 = *(*unsafe.Pointer)(unsafe.Add(v1, 4))
			if v1 == nil {
				return
			}
		}
		if v2 != nil {
			*(*uint32)(unsafe.Add(v2, 4)) = *(*uint32)(unsafe.Add(v1, 4))
		} else {
			dword_5d4594_1203864 = *(*unsafe.Pointer)(unsafe.Add(v1, 4))
		}
		nox_alloc_class_free_obj_first((*nox_alloc_class)(nox_alloc_friendList_1203860), v1)
	}
}
func sub_495A80(a1 int32) int32 {
	v1 := dword_5d4594_1203864
	if dword_5d4594_1203864 == nil {
		return 0
	}
	for *(*uint32)(v1) != uint32(a1) {
		v1 = *(*unsafe.Pointer)(unsafe.Add(v1, 4*1))
		if v1 == nil {
			return 0
		}
	}
	return 1
}
func sub_495B50(a1 unsafe.Pointer) {
	if a1 != nil {
		v2 := *(*unsafe.Pointer)(unsafe.Add(a1, 4*18))
		if v2 != nil {
			*(*uint32)(unsafe.Add(v2, 76)) = *(*uint32)(unsafe.Add(a1, 4*19))
		}
		v3 := *(*unsafe.Pointer)(unsafe.Add(a1, 4*19))
		if v3 != nil {
			*(*uint32)(unsafe.Add(v3, 72)) = *(*uint32)(unsafe.Add(a1, 4*18))
		} else {
			*memmap.PtrUint32(0x5D4594, 1203872) = *(*uint32)(unsafe.Add(a1, 4*18))
		}
		v4 := *(*unsafe.Pointer)(unsafe.Add(a1, 4*16))
		v5 := *(*unsafe.Pointer)(unsafe.Add(a1, 4*15))
		if v4 != nil {
			*(*uint32)(unsafe.Add(v4, 68)) = *(*uint32)(unsafe.Add(a1, 4*17))
		}
		v6 := *(*unsafe.Pointer)(unsafe.Add(a1, 4*17))
		if v6 != nil {
			*(*uint32)(unsafe.Add(v6, 64)) = *(*uint32)(unsafe.Add(a1, 4*16))
		} else {
			result := (*uint32)(*(*unsafe.Pointer)(unsafe.Add(a1, 4*16)))
			*(*uint32)(unsafe.Add(v5, 456)) = uint32(uintptr(unsafe.Pointer(result)))
		}
	}
}
func Sub_495BB0(dr *client.Drawable, vp *noxrender.Viewport) {
	it := dr.Field_114
	if it == nil {
		return
	}
	for {
		next := it.Field64
		if it.Field0 == 1 {
			sub_495BF0(dr, it, vp)
		} else if it.Field0 == 2 {
			sub_495D00(dr, it, vp)
		}
		it = next
		if next == nil {
			break
		}
	}
}
func sub_495BF0(a1 *client.Drawable, a2 *client.DrawableFX, a3 *noxrender.Viewport) int32 {
	var (
		v3     int32
		result int32
		v5     *uint32
		v6     int32
		v7     int32
		v8     int32
		v9     *uint32
		v10    int32
		v11    *uint32
		v12    int8
		v13    uint8
		v14    int32
		v15    int32
	)
	v3 = 0
	result = int32(*(*uint8)(unsafe.Add(a2.C(), 56)))
	v13 = math.MaxUint8
	if result <= 0 {
		if a1.PosVec.X == int(a1.Field_8) && a1.PosVec.Y == int(a1.Field_9) {
			*(*uint8)(unsafe.Add(a2.C(), 56)) = 0
			return result
		}
	} else {
		v5 = &a2.Field8
		for {
			if *v5 != *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2)) && *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) != *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*3)) {
				break
			}
			v3++
			v5 = (*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2))
			if v3 >= result {
				if a1.PosVec.X == int(a1.Field_8) && a1.PosVec.Y == int(a1.Field_9) {
					*(*uint8)(unsafe.Add(a2.C(), 56)) = 0
					return result
				}
				break
			}
		}
	}
	v6 = int32(a1.PosVec.X)
	v7 = int32(a1.PosVec.Y)
	v8 = 0
	v14 = int32(a1.PosVec.X)
	v15 = int32(a1.PosVec.Y)
	if result > 0 {
		v9 = &a2.Field8
		for {
			v13 -= 42
			nox_client_drawEnableAlpha_434560(1)
			nox_client_drawSetAlpha_434580(v13)
			a1.PosVec.X = int(*v9)
			a1.PosVec.Y = int(*(*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*1)))
			a1.DrawFunc.Get()(a3, a1)
			v8++
			v9 = (*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*2))
			if v8 >= int32(*(*uint8)(unsafe.Add(a2.C(), 56))) {
				break
			}
		}
		v7 = v15
		v6 = v14
	}
	v10 = int32(*(*uint8)(unsafe.Add(a2.C(), 56)))
	if v10 > 0 {
		v11 = (*uint32)(unsafe.Add(a2.C(), v10*8))
		for {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*2)) = *v11
			*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*3)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
			v11 = (*uint32)(unsafe.Add(unsafe.Pointer(v11), -int(4*2)))
			v10--
			if v10 == 0 {
				break
			}
		}
	}
	a1.PosVec.X = int(uint32(v6))
	a1.PosVec.Y = int(uint32(v7))
	v12 = int8(*(*uint8)(unsafe.Add(a2.C(), 56)))
	a2.Field8 = uint32(v6)
	a2.Field12 = uint32(v7)
	if int32(v12) != 5 {
		*(*uint8)(unsafe.Add(a2.C(), 56)) = uint8(int8(int32(v12) + 1))
	}
	nox_client_drawEnableAlpha_434560(0)
	return 1
}
func sub_495D00(a1 *client.Drawable, a2 *client.DrawableFX, a3 *noxrender.Viewport) int32 {
	var (
		v3     int32
		v4     int32
		v5     *uint32
		v6     *client.Drawable
		result int32
		v9     int32
		v10    int32
		v11    int32
		v13    int32
		v14    int32
		v15    int32
		v16    int32
		v17    int32
		v18    bool
		v19    int32
		v20    *uint32
		v21    int8
		v22    float32
		v23    float32
		v24    float32
		v25    float32
		v26    uint8
		v27    int32
		v28    *float32
		v29    *float32
		v30    int32
		v31    int32
		v32    *uint32
	)
	v3 = 0
	v4 = int32(*(*uint8)(unsafe.Add(a2.C(), 56)))
	v26 = math.MaxUint8
	if v4 <= 0 {
		v6 = a1
		if a1.PosVec.X == int(a1.Field_8) {
			result = int32(a1.Field_9)
			if a1.PosVec.Y == int(uint32(result)) {
				*(*uint8)(unsafe.Add(a2.C(), 56)) = 0
				return result
			}
		}
	} else {
		v5 = &a2.Field8
		for {
			if *v5 != *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2)) && *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) != *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*3)) {
				v6 = a1
				break
			}
			v3++
			v5 = (*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2))
			if v3 >= v4 {
				v6 = a1
				if a1.PosVec.X == int(a1.Field_8) {
					result = int32(a1.Field_9)
					if a1.PosVec.Y == int(uint32(result)) {
						*(*uint8)(unsafe.Add(a2.C(), 56)) = 0
						return result
					}
				}
				break
			}
		}
	}
	v8 := a3
	v9 = int32(v6.PosVec.X + int(a3.Screen.Min.X) - a3.World.Min.X)
	v10 = int32(v6.Field_77 * 8)
	v30 = int32(v6.PosVec.Y - int(uint32(v6.ZVal)) - int(uint32(v6.Field_26_1)) - a3.World.Min.Y + a3.Screen.Min.Y - 10)
	v28 = memmap.PtrFloat32(0x587000, uintptr(v6.Field_77)*64+194136)
	v22 = float32(float64(*memmap.PtrFloat32(0x587000, uintptr(v6.Field_77)*64+194136)) * (-12.0))
	v11 = int32(v22) + v9
	v29 = memmap.PtrFloat32(0x587000, uintptr(v10)*8+194140)
	v23 = float32(float64(*memmap.PtrFloat32(0x587000, uintptr(v10)*8+194140)) * (-12.0))
	v27 = 0
	v31 = int32(v23) + v30
	v12 := a2
	if int32(*(*uint8)(unsafe.Add(a2.C(), 56))) != 0 {
		v32 = &a2.Field12
		for {
			v26 -= 63
			nox_client_drawEnableAlpha_434560(1)
			nox_client_drawSetAlpha_434580(v26)
			v13 = int32(v8.Screen.Min.X + int(*(*uint32)(unsafe.Add(unsafe.Pointer(v32), -4))) - v8.World.Min.X)
			v14 = *(*int32)(unsafe.Pointer(v32)) - int32(uint32(v6.ZVal)) - int32(uint32(v6.Field_26_1)) - int32(v8.World.Min.Y) + int32(v8.Screen.Min.Y) - 10
			v24 = float32(float64(*v28) * (-12.0))
			v15 = int32(v24) + v13
			v25 = float32(float64(*v29) * (-12.0))
			v16 = int32(v25) + v14
			v17 = int32(nox_color_rgb_4344A0(200, 200, 200))
			nox_client_drawSetColor_434460(v17)
			nox_client_drawAddPoint_49F500(v11, v31)
			nox_client_drawAddPoint_49F500(v15, v16)
			nox_client_drawLineFromPoints_49E4B0()
			v12 = a2
			v32 = (*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*2))
			v31 = v16
			v6 = a1
			v18 = v27+1 < int32(*(*uint8)(unsafe.Add(a2.C(), 56)))
			v11 = v15
			v27++
			if !v18 {
				break
			}
		}
	}
	v19 = int32(*(*uint8)(unsafe.Add(v12.C(), 56)))
	if v19 > 0 {
		v20 = (*uint32)(unsafe.Add(v12.C(), v19*8))
		for {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*2)) = *v20
			*(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*3)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*1))
			v20 = (*uint32)(unsafe.Add(unsafe.Pointer(v20), -int(4*2)))
			v19--
			if v19 == 0 {
				break
			}
		}
	}
	v12.Field8 = uint32(v6.PosVec.X)
	v12.Field12 = uint32(v6.PosVec.Y)
	v21 = int8(*(*uint8)(unsafe.Add(v12.C(), 56)))
	if int32(v21) != 5 {
		*(*uint8)(unsafe.Add(v12.C(), 56)) = uint8(int8(int32(v21) + 1))
	}
	nox_client_drawEnableAlpha_434560(0)
	return 1
}
func Sub_495FC0(a1 *client.DrawableFX, a2 *client.Drawable) {
	if a1 != nil && a2 != nil {
		a1.Field60 = a2
		a1.Field72 = *memmap.PtrUint32(0x5D4594, 1203872)
		a1.Field76 = 0
		if *memmap.PtrUint32(0x5D4594, 1203872) != 0 {
			*(*unsafe.Pointer)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1203872), 76)) = unsafe.Pointer(a1)
		}
		*memmap.PtrPtr(0x5D4594, 1203872) = unsafe.Pointer(a1)
		a1.Field64 = a2.Field_114
		a1.Field68 = 0
		v3 := a2.Field_114
		if v3 != nil {
			v3.Field68 = uint32(uintptr(unsafe.Pointer(a1)))
		}
		a2.Field_114 = a1
	}
}
func sub_4960B0() int32 {
	result := alloc.Calloc1(1, uintptr((nox_win_width*4/23*(nox_win_height/23)/2)*4))
	dword_5d4594_1217456 = result
	if result == nil {
		return 0
	}
	sub_4CA860()
	return 1
}
func sub_496120() int32 {
	if dword_5d4594_1217456 != nil {
		alloc.FreePtr(dword_5d4594_1217456)
		dword_5d4594_1217456 = nil
	}
	return 1
}
func nox_xxx_drawBlack_496150(a1 *noxrender.Viewport) {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v10 uint8
		v11 int32
		v12 uint8
		v13 uint8
		v14 int32
		v15 uint8
		v16 *uint8
		v17 bool
		v18 int32
		v20 int32
		v21 int32
		v24 int8
		v25 int32
		v26 int32
		v27 int32
		v28 int32
		v29 int32
		v30 int32
		v31 int32
		v32 int32
		v33 int32
		v35 float64
		v36 int32
		v37 int32
		v39 int32
		v40 int32
		v41 int32
		v42 int32
		v43 float64
		v44 float64
		v45 int32
		v46 int32
		v47 int32
		v48 int32
		v49 int32
		v50 int32
		v51 int32
		v52 int32
		v53 int32
		v54 int32
		v55 uint8
		v56 uint8
		v57 int32
		v58 int32
		v59 int32
		v60 int32
		v61 int32
		v62 int32
		v63 int32
		v64 int32
		v65 int32
		v66 int32
		v68 int32
		v69 int32
		v70 int32
		v71 int32
		v72 int32
		v73 uint32
		v74 int32
		v75 int32
		v76 int32
		a4  types.Pointf
		v78 types.Pointf
		v79 int32
		v80 int32
		a1a Point32
		a2  Point32
		v83 float4
		a3  float4
		v86 float4
	)
	sub_4CAE60()
	dword_5d4594_1217464 = 0
	dword_5d4594_1217460 = 0
	v1 = int32(a1.World.Min.X)
	v2 = int32(a1.World.Min.Y)
	v3 = int32(a1.Size.X)
	v79 = v1 / 23
	v80 = v2 / 23
	v74 = (v3+v1)/23 - v1/23
	v4 = int32((a1.Size.Y+int(v2))/23 - int(v2/23))
	*memmap.PtrUint32(0x5D4594, 1217444) = uint32(v1 + v3/2)
	dword_5d4594_1217448 = int32(uint32(a1.World.Min.Y + a1.Field12 + a1.Size.Y/2))
	sub_498030((*uint32)(unsafe.Pointer(a1)))
	sub_497260(a1)
	if v4 < 0 {
		goto LABEL_32
	}
	v5 = v80
	v6 = v74
	v71 = v80
	v70 = v80 * 23
	v75 = v4 + 1
	for {
		v7 = (int32(uint8(int8(v5))) + int32(uint8(int8(v79)))) & 1
		if v7 > v6 {
			goto LABEL_31
		}
		v8 = v7 + v79
		v69 = (v7 + v79) * 23
		v73 = uint32(v6-v7+2) >> 1
		for {
			v9 := nox_server_getWallAtGrid_410580(v8, v5)
			if v9 != nil {
				v10 = uint8(sub_57B500(v8, v5, 64))
				if int32(v10) != math.MaxUint8 {
					v11 = int32(v9.Tile1)
					v12 = uint8(v9.Flags4)
					if nox_xxx_wallFlags(v11)&1 != 0 {
						if int32(v12)&0x40 != 0 {
							if (*memmap.PtrInt32(0x5D4594, 1217444)-v69-11)*(*memmap.PtrInt32(0x5D4594, 1217444)-v69-11)+(dword_5d4594_1217448-v70-11)*(dword_5d4594_1217448-v70-11) < 3600 {
								v5 = v71
								v9.Flags4 = server.WallFlags(uint8(int8(int32(v12) | 1)))
								goto LABEL_29
							}
							v5 = v71
						}
						if int32(v10) != 0 {
							if int32(v10) == 1 {
								nox_xxx_drawBlackofWall_497C40(v8, v5, 6)
							} else {
								v16 = (*uint8)(memmap.PtrOff(0x587000, uintptr(v10)+161764))
								if int32(*memmap.PtrUint8(0x587000, uintptr(v10)+161764))&2 != 0 {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 2)
								}
								if int32(*v16)&1 != 0 {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 1)
								}
								if int32(*v16)&8 != 0 {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 8)
								}
								if int32(*v16)&4 != 0 {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 4)
								}
							}
						} else {
							nox_xxx_drawBlackofWall_497C40(v8, v5, 9)
						}
					} else {
						v13 = uint8(int8(int32(v12) | 1))
						v14 = int32(v9.Y6)
						v9.Flags4 = server.WallFlags(v13)
						if v14*23 <= dword_5d4594_1217448 {
							v15 = uint8(int8(int32(v13) & 0xFD))
						} else {
							v15 = uint8(int8(int32(v13) | 2))
						}
						v9.Flags4 = server.WallFlags(v15)
						if nox_xxx_wallFlags(v11)&4 != 0 {
							nox_xxx_drawList1096512_Append_4754C0(unsafe.Pointer(v9))
						}
					}
				}
			}
		LABEL_29:
			v8 += 2
			v17 = v73 == 1
			v69 += 46
			v73--
			if v17 {
				break
			}
		}
		v6 = v74
	LABEL_31:
		v5++
		v17 = v75 == 1
		v70 += 23
		v71 = v5
		v75--
		if v17 {
			break
		}
	}
LABEL_32:
	sub_498110()
	v72 = 0
	a3.field_0 = float32(float64(*memmap.PtrInt32(0x5D4594, 1217444)))
	a3.field_4 = float32(float64(dword_5d4594_1217448))
	if dword_5d4594_1217460 <= 0 {
		v51 = dword_5d4594_1217464
	} else {
		for {
			v18 = 0
			v19 := *(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1217456, uint32(v72)*4))
			switch *(*uint8)(unsafe.Add(v19, 56)) {
			case 0:
				v20 = int32(uint32(*(*int32)(unsafe.Add(v19, 40))*25736) / 75000)
				a3.field_8 = float32(float64(int32(*memmap.PtrUint32(0x5D4594, 1217444) + uint32(sub_414BD0(6434-v20)))))
				a3.field_C = float32(float64(int32(dword_5d4594_1217448 + int32(sub_414BD0(v20)))))
				sub_4CA960((*uint32)(unsafe.Add(v19, 24)), int8(*(*uint8)(unsafe.Add(v19, 36))), &a3, &a4)
				v21 = int32(uint32(*(*int32)(unsafe.Add(v19, 44))*25736) / 75000)
				a3.field_8 = float32(float64(int32(*memmap.PtrUint32(0x5D4594, 1217444) + uint32(sub_414BD0(6434-v21)))))
				a3.field_C = float32(float64(int32(dword_5d4594_1217448 + int32(sub_414BD0(v21)))))
				sub_4CA960((*uint32)(unsafe.Add(v19, 24)), int8(*(*uint8)(unsafe.Add(v19, 36))), &a3, &v78)
				v22p := nox_server_getWallAtGrid_410580(int32(*(*uint32)(unsafe.Add(v19, 24))), int32(*(*uint32)(unsafe.Add(v19, 28))))
				v23 := v22p
				var v22 uint32
				*(*uint8)(unsafe.Pointer(&v22)) = uint8(v22p.Flags4)
				v23.Field12 = 1
				v24 = int8(v22 | 1)
				v23.Flags4 = server.WallFlags(uint8(v24))
				if float64(v78.X) < float64(a4.X) {
					v23.Flags4 = server.WallFlags(uint8(int8(int32(v24) | 2)))
				}
				v23.Field3 |= *(*uint8)(unsafe.Add(v19, 36))
				v18 = int32(*(*uint32)(unsafe.Add(v19, 24)) + (*(*uint32)(unsafe.Add(v19, 28)) << 8))
			case 1:
				a4.X = float32(float64(*memmap.PtrInt32(0x5D4594, 1217444) + sub_414C50(int32(uint32(*(*int32)(unsafe.Add(v19, 40))*25736)/75000-19302))*int32(a1.Size.Y/2)/4096))
				a4.Y = float32(float64(a1.World.Min.Y))
				v18 = 0
				v78.X = float32(float64(*memmap.PtrInt32(0x5D4594, 1217444) + sub_414C50(int32(uint32(*(*int32)(unsafe.Add(v19, 44))*25736)/75000-19302))*int32(a1.Size.Y/2)/4096))
				v78.Y = float32(float64(a1.World.Min.Y))
			case 2:
				v25 = int32(a1.Size.Y)
				v26 = int32(*memmap.PtrUint32(0x5D4594, 1217444) - uint32(sub_414C50(int32(uint32(*(*int32)(unsafe.Add(v19, 40))*25736)/75000-6434))*(v25/2)/4096))
				v27 = int32(a1.World.Min.Y + int(v25) - 1)
				v28 = int32(a1.Size.Y)
				a4.X = float32(float64(v26))
				a4.Y = float32(float64(v27))
				v29 = sub_414C50(int32(uint32(*(*int32)(unsafe.Add(v19, 44))*25736)/75000 - 6434))
				v76 = int32(a1.World.Min.Y + int(v28) - 1)
				v78.X = float32(float64(*memmap.PtrInt32(0x5D4594, 1217444) - v29*(v28/2)/4096))
				v78.Y = float32(float64(v76))
				v18 = 0
			case 3:
				v32 = int32(*(*uint32)(unsafe.Add(v19, 40)) * 25736)
				a4.X = float32(float64(a1.World.Min.X))
				a4.Y = float32(float64(dword_5d4594_1217448 - sub_414C50(int32(uint32(v32)/75000-12868))*int32(a1.Size.X/2)/4096))
				v33 = int32(*(*uint32)(unsafe.Add(v19, 44)) * 25736)
				v78.X = float32(float64(a1.World.Min.X))
				v18 = 0
				v78.Y = float32(float64(dword_5d4594_1217448 - sub_414C50(int32(uint32(v33)/75000-12868))*int32(a1.Size.X/2)/4096))
			case 4:
				v30 = int32(a1.Size.X)
				v68 = int32(uint32(*(*int32)(unsafe.Add(v19, 40))*25736) / 75000)
				a4.X = float32(float64(a1.Size.X + a1.World.Min.X - 1))
				a4.Y = float32(float64(int32(dword_5d4594_1217448 + int32(sub_414C50(v68)*(v30/2)/4096))))
				v31 = int32(uint32(*(*int32)(unsafe.Add(v19, 44))*25736) / 75000)
				v78.X = float32(float64(a1.World.Min.X + int(v30) - 1))
				v78.Y = float32(float64(int32(dword_5d4594_1217448 + int32(sub_414C50(v31)*int32(a1.Size.X/2)/4096))))
				v18 = 0
			case 6:
				v34 := *(*unsafe.Pointer)(unsafe.Add(v19, 20))
				v35 = float64(*(*int32)(unsafe.Add(v34, 12)))
				*(*uint32)(unsafe.Add(v34, 132)) = 1
				v86.field_0 = float32(v35)
				v86.field_4 = float32(float64(*(*int32)(unsafe.Add(v34, 16))))
				v86.field_8 = float32(float64(*(*int32)(unsafe.Add(v34, 12)) + *memmap.PtrInt32(0x587000, uintptr(int32(*(*uint8)(unsafe.Add(v34, 299)))*8)+196184)))
				v86.field_C = float32(float64(*(*int32)(unsafe.Add(v34, 16)) + *memmap.PtrInt32(0x587000, uintptr(int32(*(*uint8)(unsafe.Add(v34, 299)))*8)+196188)))
				v36 = int32(uint32(*(*int32)(unsafe.Add(v19, 40))*25736) / 75000)
				a3.field_8 = float32(float64(*memmap.PtrInt32(0x5D4594, 1217444) + sub_414BD0(6434-v36)))
				a3.field_C = float32(float64(dword_5d4594_1217448 + sub_414BD0(v36)))
				if sub_497180((*float4)(unsafe.Pointer(&a3.field_0)), (*float4)(unsafe.Pointer(&v86.field_0)), (*types.Pointf)(unsafe.Pointer(&a4.X))) == 0 {
					a4 = *(*types.Pointf)(unsafe.Pointer(&v86.field_0))
				}
				v37 = int32(uint32(*(*int32)(unsafe.Add(v19, 44))*25736) / 75000)
				a3.field_8 = float32(float64(*memmap.PtrInt32(0x5D4594, 1217444) + sub_414BD0(6434-v37)))
				a3.field_C = float32(float64(dword_5d4594_1217448 + sub_414BD0(v37)))
				if sub_497180((*float4)(unsafe.Pointer(&a3.field_0)), (*float4)(unsafe.Pointer(&v86.field_0)), (*types.Pointf)(unsafe.Pointer(&v78.X))) == 0 {
					v78 = *(*types.Pointf)(unsafe.Pointer(&v86.field_8))
				}
				v18 = int32(*(*uint32)(unsafe.Add(v34, 128)))
			case 7:
				*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 132)) = 1
				v38 := *(*unsafe.Pointer)(unsafe.Add(v19, 20))
				v39 = int32(*memmap.PtrUint32(0x5D4594, 1217444) - *(*uint32)(unsafe.Add(v38, 12)))
				v40 = *(*int32)(unsafe.Add(v38, 16)) - dword_5d4594_1217448
				v83.field_0 = float32(float64(v40 + *(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))))
				v83.field_4 = float32(float64(v39 + *(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))))
				v83.field_8 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12)) - v40))
				v83.field_C = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16)) - v39))
				v41 = int32(uint32(*(*int32)(unsafe.Add(v19, 40))*25736) / 75000)
				a3.field_8 = float32(float64(*memmap.PtrInt32(0x5D4594, 1217444) + sub_414BD0(6434-v41)))
				a3.field_C = float32(float64(dword_5d4594_1217448 + sub_414BD0(v41)))
				if sub_497180((*float4)(unsafe.Pointer(&a3.field_0)), (*float4)(unsafe.Pointer(&v83.field_0)), (*types.Pointf)(unsafe.Pointer(&a4.X))) == 0 {
					a4 = types.Ptf(v83.field_0, v83.field_4)
				}
				v42 = int32(uint32(*(*int32)(unsafe.Add(v19, 44))*25736) / 75000)
				a3.field_8 = float32(float64(*memmap.PtrInt32(0x5D4594, 1217444) + sub_414BD0(6434-v42)))
				a3.field_C = float32(float64(dword_5d4594_1217448 + sub_414BD0(v42)))
				if sub_497180((*float4)(unsafe.Pointer(&a3.field_0)), (*float4)(unsafe.Pointer(&v83.field_0)), (*types.Pointf)(unsafe.Pointer(&v78.X))) != 0 {
					v18 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 128)))
					break
				}
				v78 = *(*types.Pointf)(unsafe.Pointer(&v83.field_8))
				v18 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 128)))
			case 8, 9, 0xA, 0xB, 0xD, 0xE:
				*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 132)) = 1
				switch *(*uint8)(unsafe.Add(v19, 56)) {
				case 8:
					v83.field_0 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 64))))
					v83.field_4 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 68))))
					v83.field_8 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 72))))
					v43 = float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 76)))
					v83.field_C = float32(v43)
				case 9:
					v83.field_0 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 64))))
					v44 = float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 68)))
					v83.field_4 = float32(v44)
					v83.field_8 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 80))))
					v43 = float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 84)))
					v83.field_C = float32(v43)
				case 0xA:
					v83.field_0 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 88))))
					v83.field_4 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 92))))
					v83.field_8 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 72))))
					v43 = float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 76)))
					v83.field_C = float32(v43)
				case 0xB:
					v83.field_0 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 88))))
					v44 = float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 92)))
					v83.field_4 = float32(v44)
					v83.field_8 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 80))))
					v43 = float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 84)))
					v83.field_C = float32(v43)
				case 0xD:
					v83.field_0 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 64))))
					v83.field_4 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 68))))
					v83.field_8 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 88))))
					v43 = float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 92)))
					v83.field_C = float32(v43)
				case 0xE:
					v83.field_0 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 72))))
					v44 = float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 76)))
					v83.field_4 = float32(v44)
					v83.field_8 = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 12))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 80))))
					v43 = float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 16))) + float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 84)))
					v83.field_C = float32(v43)
				default:
				}
				v45 = int32(uint32(*(*int32)(unsafe.Add(v19, 40))*25736) / 75000)
				a3.field_8 = float32(float64(*memmap.PtrInt32(0x5D4594, 1217444) + sub_414BD0(6434-v45)))
				a3.field_C = float32(float64(dword_5d4594_1217448 + sub_414BD0(v45)))
				if sub_497180((*float4)(unsafe.Pointer(&a3.field_0)), (*float4)(unsafe.Pointer(&v83.field_0)), (*types.Pointf)(unsafe.Pointer(&a4.X))) == 0 {
					a4 = *(*types.Pointf)(unsafe.Pointer(&v83.field_0))
				}
				v46 = int32(uint32(*(*int32)(unsafe.Add(v19, 44))*25736) / 75000)
				a3.field_8 = float32(float64(*memmap.PtrInt32(0x5D4594, 1217444) + sub_414BD0(6434-v46)))
				a3.field_C = float32(float64(dword_5d4594_1217448 + sub_414BD0(v46)))
				if sub_497180((*float4)(unsafe.Pointer(&a3.field_0)), (*float4)(unsafe.Pointer(&v83.field_0)), (*types.Pointf)(unsafe.Pointer(&v78.X))) == 0 {
					v78 = *(*types.Pointf)(unsafe.Pointer(&v83.field_8))
					v18 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 128)))
					break
				}
				v18 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 20)), 128)))
			default:
			}
			a1a.X = int32(a1.Screen.Min.X - a1.World.Min.X + int(int32(a4.X)))
			a1a.Y = int32(a1.Screen.Min.Y - a1.World.Min.Y + int(int32(a4.Y)))
			a2.X = int32(a1.Screen.Min.X - a1.World.Min.X + int(int32(v78.X)))
			a2.Y = int32(a1.Screen.Min.Y - a1.World.Min.Y + int(int32(v78.Y)))
			if sub_57BA30(&a1a, &a2, (*int4)(unsafe.Pointer(a1))) != 0 {
				v47 = dword_5d4594_1217464
				v48 = a1a.Y
				*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1217464)*8+1203876) = uint32(a1a.X)
				v49 = a2.X
				*memmap.PtrUint32(0x5D4594, uintptr(v47*8)+1203880) = uint32(v48)
				v50 = a2.Y
				*memmap.PtrUint32(0x5D4594, uintptr(v47*4)+1213348) = uint32(v18)
				*memmap.PtrUint8(0x5D4594, uintptr(func() int32 {
					p := &v47
					x := *p
					*p++
					return x
				}())+1212324) = *(*uint8)(unsafe.Add(v19, 56))
				dword_5d4594_1217464 = v47
				*memmap.PtrUint32(0x5D4594, uintptr(v47*8)+1203876) = uint32(v49)
				*memmap.PtrUint32(0x5D4594, uintptr(v47*8)+1203880) = uint32(v50)
				*memmap.PtrUint32(0x5D4594, uintptr(v47*4)+1213348) = uint32(v18)
				*memmap.PtrUint8(0x5D4594, uintptr(v47)+1212324) = *(*uint8)(unsafe.Add(v19, 56))
				v51 = v47 + 1
				dword_5d4594_1217464 = v51
			} else {
				v51 = dword_5d4594_1217464
			}
			v72++
			if v72 >= dword_5d4594_1217460 {
				break
			}
		}
	}
	v52 = v51 - 1
	v53 = 0
	dword_5d4594_1217464 = v52
	v54 = v52 - 1
	for v53 < v52 {
		v55 = *memmap.PtrUint8(0x5D4594, uintptr(v54)+1212324)
		if int32(v55) != 0 {
			v56 = *memmap.PtrUint8(0x5D4594, uintptr(v53)+1212324)
			if int32(v56) == 0 {
				if int32(v55) == 6 || int32(*memmap.PtrUint8(0x5D4594, uintptr(v53)+1212324)) == 6 {
					v63 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v54*8)+1203876))
					if *memmap.PtrInt32(0x5D4594, uintptr(v53*8)+1203876)-v63 >= 0 {
						v64 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203876) - uint32(v63))
					} else {
						v64 = int32(uint32(v63) - *memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203876))
					}
					v65 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v54*8)+1203880))
					if *memmap.PtrInt32(0x5D4594, uintptr(v53*8)+1203880)-v65 >= 0 {
						v66 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203880) - uint32(v65))
					} else {
						v66 = int32(uint32(v65) - *memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203880))
					}
					if v64 <= 4 && v66 <= 4 {
						v54 = func() int32 {
							p := &v53
							x := *p
							*p++
							return x
						}()
						continue
					}
				}
				*memmap.PtrUint8(0x5D4594, uintptr(v54)+1212324) = 12
				v54 = func() int32 {
					p := &v53
					x := *p
					*p++
					return x
				}()
				continue
			}
			if int32(v56) != int32(v55) {
				*memmap.PtrUint8(0x5D4594, uintptr(v54)+1212324) = 12
				v54 = func() int32 {
					p := &v53
					x := *p
					*p++
					return x
				}()
				continue
			}
			if *memmap.PtrUint32(0x5D4594, uintptr(v53*4)+1213348) == *memmap.PtrUint32(0x5D4594, uintptr(v54*4)+1213348) {
				v54 = func() int32 {
					p := &v53
					x := *p
					*p++
					return x
				}()
				continue
			}
			v57 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v54*8)+1203876))
			v58 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203876) - uint32(v57))
			if v58 < 0 {
				v59 = int32(uint32(v57) - *memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203876))
			} else {
				v59 = v58
			}
		} else {
			if int32(*memmap.PtrUint8(0x5D4594, uintptr(v53)+1212324)) != 0 {
				if int32(v55) == 6 || int32(*memmap.PtrUint8(0x5D4594, uintptr(v53)+1212324)) == 6 {
					v63 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v54*8)+1203876))
					if *memmap.PtrInt32(0x5D4594, uintptr(v53*8)+1203876)-v63 >= 0 {
						v64 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203876) - uint32(v63))
					} else {
						v64 = int32(uint32(v63) - *memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203876))
					}
					v65 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v54*8)+1203880))
					if *memmap.PtrInt32(0x5D4594, uintptr(v53*8)+1203880)-v65 >= 0 {
						v66 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203880) - uint32(v65))
					} else {
						v66 = int32(uint32(v65) - *memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203880))
					}
					if v64 <= 4 && v66 <= 4 {
						v54 = func() int32 {
							p := &v53
							x := *p
							*p++
							return x
						}()
						continue
					}
				}
				*memmap.PtrUint8(0x5D4594, uintptr(v54)+1212324) = 12
				v54 = func() int32 {
					p := &v53
					x := *p
					*p++
					return x
				}()
				continue
			}
			if *memmap.PtrUint32(0x5D4594, uintptr(v54*4)+1213348) == *memmap.PtrUint32(0x5D4594, uintptr(v53*4)+1213348) {
				v54 = func() int32 {
					p := &v53
					x := *p
					*p++
					return x
				}()
				continue
			}
			v60 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v54*8)+1203876))
			v58 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203876) - uint32(v60))
			if v58 < 0 {
				v59 = int32(uint32(v60) - *memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203876))
			} else {
				v59 = v58
			}
		}
		v61 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v54*8)+1203880))
		if *memmap.PtrInt32(0x5D4594, uintptr(v53*8)+1203880)-v61 >= 0 {
			v62 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203880) - uint32(v61))
		} else {
			v62 = int32(uint32(v61) - *memmap.PtrUint32(0x5D4594, uintptr(v53*8)+1203880))
		}
		if v59 <= 4 && v62 <= 4 {
			v54 = func() int32 {
				p := &v53
				x := *p
				*p++
				return x
			}()
		} else {
			*memmap.PtrUint8(0x5D4594, uintptr(v54)+1212324) = 12
			v54 = func() int32 {
				p := &v53
				x := *p
				*p++
				return x
			}()
		}
	}
}
func sub_497260(a1 *noxrender.Viewport) {
	var (
		v4  float64
		v5  float64
		v6  int32
		v7  float64
		v8  float64
		v9  float64
		v10 float64
		v11 float32
		v12 float32
		v13 float32
		v14 float32
		v15 float32
		v16 float32
		v17 float32
		v18 float32
		v19 float32
		v20 float32
		v21 float32
		v22 float32
	)
	result := nox_xxx_sprite_45A030()
	v2 := result
	if result == nil {
		return
	}
	v3 := a1
	for {
		v2.Field_33 = 0
		if !nox_client_drawable_testBuff_4356C0(v2, 0) {
			if *(*byte)(unsafe.Add(v2.C(), 112)) >= 0 {
				v6 = int32(v2.Shape.Kind)
				if v6 == 2 {
					v7 = float64(v2.PosVec.X)
					v8 = float64(v2.PosVec.Y)
					if v7-float64(v2.Shape.Circle.R) < float64(v3.World.Min.X+v3.Size.X) {
						v21 = float32(v7)
						v15 = v21 + v2.Shape.Circle.R
						if float64(v3.World.Min.X) < float64(v15) {
							v12 = float32(v8 - float64(v2.Shape.Circle.R))
							if float64(v3.World.Min.Y+v3.Size.Y) > float64(v12) {
								v18 = float32(v8 + float64(v2.Shape.Circle.R))
								if float64(v3.World.Min.Y) < float64(v18) {
									sub_497650(v2)
								}
							}
						}
					}
				} else if v6 == 3 {
					v9 = float64(v2.PosVec.X)
					v10 = float64(v2.PosVec.Y)
					if v9+float64(v2.Shape.Box.LeftBottom2) < float64(v3.World.Min.X+v3.Size.X) {
						v22 = float32(v9)
						v16 = v22 + v2.Shape.Box.RightTop
						if float64(v3.World.Min.X) < float64(v16) {
							v13 = float32(v10 + float64(v2.Shape.Box.LeftBottom))
							if float64(v3.World.Min.Y+v3.Size.Y) > float64(v13) {
								v19 = float32(v10 + float64(v2.Shape.Box.RightTop2))
								if float64(v3.World.Min.Y) < float64(v19) {
									sub_4977C0(v2)
								}
							}
						}
					}
				}
			} else {
				v4 = float64(v2.PosVec.X)
				v5 = float64(v2.PosVec.Y)
				if v4-32.0 < float64(v3.World.Min.X+v3.Size.X) {
					v20 = float32(v4)
					v14 = float32(float64(v20) + 32.0)
					if float64(v3.World.Min.X) < float64(v14) {
						v11 = float32(v5 - 32.0)
						if float64(v3.World.Min.Y+v3.Size.Y) > float64(v11) {
							v17 = float32(v5 + 32.0)
							if float64(v3.World.Min.Y) < float64(v17) {
								sub_4974B0(unsafe.Pointer(v2))
							}
						}
					}
				}
			}
		}
		result = sub_45A040(v2)
		v2 = result
		if result == nil {
			break
		}
	}
}
func sub_4974B0(a1 unsafe.Pointer) {
	var (
		v3  int32
		v4  float64
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v14 float32
		v15 int32
	)
	v1 := a1
	if (int32(*(*uint8)(unsafe.Add(a1, 116))) & 4) == 0 {
		v2 := sub_4CADD0()
		*(*uint8)(unsafe.Add(v2, 48)) = 1
		*(*uint8)(unsafe.Add(v2, 56)) = 6
		*(*unsafe.Pointer)(unsafe.Add(v2, 20)) = a1
		v3 = int32(*(*uint8)(unsafe.Add(a1, 299))) * 8
		v4 = float64(int32(*memmap.PtrUint32(0x5D4594, 1217444) - uint32(*memmap.PtrInt32(0x587000, uintptr(v3)+196184)/2) - *(*uint32)(unsafe.Add(a1, 12))))
		v15 = dword_5d4594_1217448 - int32(*memmap.PtrInt32(0x587000, uintptr(v3)+196188)/2) - *(*int32)(unsafe.Add(a1, 16))
		v14 = float32(float64(v15)*float64(v15) + v4*v4)
		*(*uint32)(unsafe.Add(v2, 32)) = uint32(int32(v14))
		v5 = sub_4CA8B0(*(*int32)(unsafe.Add(v1, 16))-dword_5d4594_1217448, int32(*(*uint32)(unsafe.Add(v1, 12))-*memmap.PtrUint32(0x5D4594, 1217444)))
		*(*uint32)(unsafe.Add(v2, 40)) = uint32(v5)
		if v5 < 0 {
			for {
				v6 = int32(*(*uint32)(unsafe.Add(v2, 40)))
				*(*uint32)(unsafe.Add(v2, 40)) = uint32(v6) + 75000
				if uint32(v6)+75000 >= 0 {
					break
				}
			}
		}
		if uint32(*(*int32)(unsafe.Add(v2, 40))) >= 75000 {
			for {
				v7 = int32(*(*uint32)(unsafe.Add(v2, 40)) - 75000)
				*(*uint32)(unsafe.Add(v2, 40)) = uint32(v7)
				if uint32(v7) < 75000 {
					break
				}
			}
		}
		v8 = sub_4CA8B0(*(*int32)(unsafe.Add(v1, 16))+int32(*memmap.PtrInt32(0x587000, uintptr(int32(*(*uint8)(unsafe.Add(v1, 299)))*8)+196188))-dword_5d4594_1217448, int32(*(*uint32)(unsafe.Add(v1, 12))+uint32(*memmap.PtrInt32(0x587000, uintptr(int32(*(*uint8)(unsafe.Add(v1, 299)))*8)+196184))-*memmap.PtrUint32(0x5D4594, 1217444)))
		*(*uint32)(unsafe.Add(v2, 44)) = uint32(v8)
		if v8 < 0 {
			for {
				v9 = int32(*(*uint32)(unsafe.Add(v2, 44)))
				*(*uint32)(unsafe.Add(v2, 44)) = uint32(v9) + 75000
				if uint32(v9)+75000 >= 0 {
					break
				}
			}
		}
		if uint32(*(*int32)(unsafe.Add(v2, 44))) >= 75000 {
			for {
				v10 = int32(*(*uint32)(unsafe.Add(v2, 44)) - 75000)
				*(*uint32)(unsafe.Add(v2, 44)) = uint32(v10)
				if uint32(v10) < 75000 {
					break
				}
			}
		}
		v11 = int32(*(*uint32)(unsafe.Add(v2, 44)))
		v12 = int32(*(*uint32)(unsafe.Add(v2, 40)))
		if v11 < v12 {
			*(*uint32)(unsafe.Add(v2, 40)) = uint32(v11)
			*(*uint32)(unsafe.Add(v2, 44)) = uint32(v12)
		}
		if float64(int32(*(*uint32)(unsafe.Add(v2, 44))-*(*uint32)(unsafe.Add(v2, 40)))) >= 37500.0 {
			v13 := sub_4CAED0(v2)
			*(*uint32)(unsafe.Add(v13, 40)) = 0
			*(*uint32)(unsafe.Add(v13, 44)) = *(*uint32)(unsafe.Add(v2, 40))
			*(*uint32)(unsafe.Add(v2, 40)) = *(*uint32)(unsafe.Add(v2, 44))
			*(*uint32)(unsafe.Add(v2, 44)) = 74999
			sub_4CAE90(v13)
		}
		sub_4CAE90(v2)
	}
}
func sub_497650(a1 *client.Drawable) {
	var (
		v4  int32
		v5  float64
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v21 float32
		v22 int32
		v23 float32
		v24 float32
	)
	v1 := sub_4CADD0()
	v2 := a1
	v3 := v1
	*(*uint8)(unsafe.Add(v1, 48)) = 1
	*(*uint8)(unsafe.Add(v1, 56)) = 7
	*(**client.Drawable)(unsafe.Add(v1, 20)) = a1
	v4 = int32(a1.PosVec.Y)
	v24 = float32(float64(int32(a1.PosVec.X - int(*memmap.PtrUint32(0x5D4594, 1217444)))))
	v5 = float64(int32(int32(v4) - dword_5d4594_1217448))
	v23 = float32(v5)
	v21 = float32(v5*float64(v23) + float64(v24*v24))
	v6 = int32(v21)
	*(*uint32)(unsafe.Add(v3, 4*8)) = uint32(v6)
	v7 = int32(int64(math.Sqrt(float64(v6))))
	v22 = int32(v24)
	v8 = int32(v23)
	v9 = sub_4CA8B0(v8, v22)
	v10 = int32(v2.Shape.Circle.R)
	v11 = sub_4CA8B0(v10, v7)
	*(*uint32)(unsafe.Add(v3, 4*10)) = uint32(v11 + v9)
	if v11+v9 < 0 {
		for {
			v12 = int32(*(*uint32)(unsafe.Add(v3, 4*10)))
			*(*uint32)(unsafe.Add(v3, 4*10)) = uint32(v12) + 75000
			if uint32(v12)+75000 >= 0 {
				break
			}
		}
	}
	if *(*uint32)(unsafe.Add(v3, 4*10)) >= 75000 {
		for {
			v13 = int32(*(*uint32)(unsafe.Add(v3, 4*10)) - 75000)
			*(*uint32)(unsafe.Add(v3, 4*10)) = uint32(v13)
			if uint32(v13) < 75000 {
				break
			}
		}
	}
	v14 = v9 - v11
	*(*uint32)(unsafe.Add(v3, 4*11)) = uint32(v14)
	if v14 < 0 {
		for {
			v15 = int32(*(*uint32)(unsafe.Add(v3, 4*11)))
			*(*uint32)(unsafe.Add(v3, 4*11)) = uint32(v15) + 75000
			if uint32(v15)+75000 >= 0 {
				break
			}
		}
	}
	if *(*uint32)(unsafe.Add(v3, 4*11)) >= 75000 {
		for {
			v16 = int32(*(*uint32)(unsafe.Add(v3, 4*11)) - 75000)
			*(*uint32)(unsafe.Add(v3, 4*11)) = uint32(v16)
			if uint32(v16) < 75000 {
				break
			}
		}
	}
	v17 = int32(*(*uint32)(unsafe.Add(v3, 4*11)))
	v18 = int32(*(*uint32)(unsafe.Add(v3, 4*10)))
	if v17 < v18 {
		*(*uint32)(unsafe.Add(v3, 4*10)) = uint32(v17)
		*(*uint32)(unsafe.Add(v3, 4*11)) = uint32(v18)
	}
	if float64(*(*uint32)(unsafe.Add(v3, 4*11))-*(*uint32)(unsafe.Add(v3, 4*10))) < 37500.0 {
		sub_4CAE90(v3)
		return
	}
	v19 := sub_4CAED0(v3)
	*(*uint32)(unsafe.Add(v19, 40)) = 0
	*(*uint32)(unsafe.Add(v19, 44)) = *(*uint32)(unsafe.Add(v3, 4*10))
	*(*uint32)(unsafe.Add(v3, 4*10)) = *(*uint32)(unsafe.Add(v3, 4*11))
	*(*uint32)(unsafe.Add(v3, 4*11)) = 74999
	sub_4CAE90(v19)
	sub_4CAE90(v3)
}
func sub_4977C0(a1 *client.Drawable) {
	var (
		v2     float64
		v3     float64
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		result int32
		v12    float64
		v13    int32
		v14    float64
		v15    int32
		v16    float64
		v17    int32
		v18    float64
		v19    int32
		v20    float64
		v21    int32
		v22    float64
		v23    int32
		v24    float32
		v25    float32
		v26    float32
		v27    float32
		v28    float32
		v29    float32
		v30    int32
		v31    int32
		v32    int32
		v33    int32
		v34    float32
		v35    float32
		v36    float32
		v37    float32
		v38    [8]float32
		v39    float32
		v40    int32
	)
	v1 := a1
	v2 = float64(a1.PosVec.X)
	v38[0] = float32(v2 + float64(a1.Shape.Box.LeftTop))
	v3 = float64(a1.PosVec.Y)
	v39 = float32(v3)
	v38[1] = float32(v3 + float64(v1.Shape.Box.LeftBottom))
	v38[2] = float32(v2 + float64(v1.Shape.Box.LeftBottom2))
	v38[3] = v39 + v1.Shape.Box.LeftTop2
	v38[4] = float32(v2 + float64(v1.Shape.Box.RightTop))
	v38[5] = v39 + v1.Shape.Box.RightBottom
	v38[6] = float32(v2 + float64(v1.Shape.Box.RightBottom2))
	v38[7] = v39 + v1.Shape.Box.RightTop2
	v30 = int32(uint32(int32(v38[0])) - *memmap.PtrUint32(0x5D4594, 1217444))
	v4 = int32(v38[1])
	v5 = sub_4CA8B0(int32(v4)-dword_5d4594_1217448, v30)
	v31 = int32(uint32(int32(v38[2])) - *memmap.PtrUint32(0x5D4594, 1217444))
	v6 = int32(v38[3])
	v7 = sub_4CA8B0(int32(v6)-dword_5d4594_1217448, v31)
	v32 = int32(uint32(int32(v38[4])) - *memmap.PtrUint32(0x5D4594, 1217444))
	v8 = int32(v38[5])
	v9 = sub_4CA8B0(int32(v8)-dword_5d4594_1217448, v32)
	v33 = int32(uint32(int32(v38[6])) - *memmap.PtrUint32(0x5D4594, 1217444))
	v10 = int32(v38[7])
	v40 = sub_4CA8B0(int32(v10)-dword_5d4594_1217448, v33)
	result = int32(uint8(sub_497B80(&v38[0], memmap.PtrInt32(0x5D4594, 1217444)))) - 1
	switch result {
	case 0:
		v35 = float32(float64(v38[5]+v38[1]) * 0.5)
		v14 = float64(v38[4]+v38[0])*0.5 - float64(*memmap.PtrInt32(0x5D4594, 1217444))
		v25 = float32((float64(v35)-float64(dword_5d4594_1217448))*(float64(v35)-float64(dword_5d4594_1217448)) + v14*v14)
		v15 = int32(v25)
		sub_497F60(v5, v9, 9, v15, v1)
	case 1:
		v37 = float32(float64(v38[7]+v38[3]) * 0.5)
		v18 = float64(v38[6]+v38[2])*0.5 - float64(*memmap.PtrInt32(0x5D4594, 1217444))
		v27 = float32((float64(v37)-float64(dword_5d4594_1217448))*(float64(v37)-float64(dword_5d4594_1217448)) + v18*v18)
		v19 = int32(v27)
		sub_497F60(v40, v7, 10, v19, v1)
	case 3:
		v34 = float32(float64(v38[3]+v38[1]) * 0.5)
		v12 = float64(v38[2]+v38[0])*0.5 - float64(*memmap.PtrInt32(0x5D4594, 1217444))
		v24 = float32((float64(v34)-float64(dword_5d4594_1217448))*(float64(v34)-float64(dword_5d4594_1217448)) + v12*v12)
		v13 = int32(v24)
		sub_497F60(v5, v7, 8, v13, v1)
	case 4, 9:
		v22 = float64(int32(v1.PosVec.X - int(*memmap.PtrUint32(0x5D4594, 1217444))))
		v29 = float32(float64(int32(v1.PosVec.Y-int(dword_5d4594_1217448)))*float64(int32(v1.PosVec.Y-int(dword_5d4594_1217448))) + v22*v22)
		v23 = int32(v29)
		sub_497F60(v7, v9, 14, v23, v1)
	case 5, 8:
		v20 = float64(int32(v1.PosVec.X - int(*memmap.PtrUint32(0x5D4594, 1217444))))
		v28 = float32(float64(int32(v1.PosVec.Y-int(dword_5d4594_1217448)))*float64(int32(v1.PosVec.Y-int(dword_5d4594_1217448))) + v20*v20)
		v21 = int32(v28)
		sub_497F60(v5, v40, 13, v21, v1)
	case 7:
		v36 = float32(float64(v38[7]+v38[5]) * 0.5)
		v16 = float64(v38[6]+v38[4])*0.5 - float64(*memmap.PtrInt32(0x5D4594, 1217444))
		v26 = float32((float64(v36)-float64(dword_5d4594_1217448))*(float64(v36)-float64(dword_5d4594_1217448)) + v16*v16)
		v17 = int32(v26)
		sub_497F60(v40, v9, 11, v17, v1)
	}
}
func sub_497B80(a1 *float32, a2 *int32) int8 {
	var (
		v2 *int32
		v3 *float32
		v4 int8
		v5 float64
		v7 float32
		v8 float32
		v9 float32
	)
	v2 = a2
	v3 = a1
	v4 = 0
	v9 = float32(float64(*a2))
	v7 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1))))
	v5 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*5))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*4))-v9-v7) * 0.70709997
	v8 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1))+*a1-v9-v7) * 0.70709997)
	if float64(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*1))-*v3+v9-v7)*0.70709997 <= 0.0 {
		if float64(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*3))-*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*2))+v9-v7)*0.70709997 < 0.0 {
			v4 = 2
		}
	} else {
		v4 = 1
	}
	if v5 < 0.0 {
		return int8(int32(v4) | 8)
	}
	if float64(v8) > 0.0 {
		v4 |= 4
	}
	return v4
}
func nox_xxx_drawBlackofWall_497C40(a1 int32, a2 int32, a3 int8) {
	var (
		v3  int32
		v4  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v21 int32
		v22 int32
		v23 int32
		v24 int32
	)
	v21 = a1 * 23
	v22 = a2 * 23
	v3 = a1*23 + 11
	v4 = a2*23 + 11
	v5 := sub_4CADD0()
	*(*uint32)(unsafe.Add(v5, 24)) = uint32(a1)
	*(*uint8)(unsafe.Add(v5, 36)) = uint8(a3)
	*(*uint32)(unsafe.Add(v5, 28)) = uint32(a2)
	*(*uint8)(unsafe.Add(v5, 48)) = 1
	*(*uint8)(unsafe.Add(v5, 56)) = 0
	switch a3 {
	case 1:
		v6 = int32(uint32(v3) - *memmap.PtrUint32(0x5D4594, 1217444) + 5)
		v7 = int32(v4) - dword_5d4594_1217448 - 5
		v8 = v3
		v9 = a2 * 23
		v23 = v21 + 23
	case 2:
		v6 = int32(uint32(v3) - *memmap.PtrUint32(0x5D4594, 1217444) - 5)
		v7 = int32(v4) - dword_5d4594_1217448 - 5
		v8 = v3
		v9 = a2 * 23
		v23 = a1 * 23
	case 4:
		v6 = int32(uint32(v3) - *memmap.PtrUint32(0x5D4594, 1217444) + 5)
		v10 = 5
		v8 = v3
		v7 = int32(v4) - dword_5d4594_1217448 + int32(v10)
		v23 = v21 + 23
		v9 = v22 + 23
	case 6:
		v8 = a1 * 23
		v7 = int32(v4) - dword_5d4594_1217448
		v4 = a2 * 23
		v6 = int32(uint32(v3) - *memmap.PtrUint32(0x5D4594, 1217444))
		v23 = v21 + 23
		v9 = v22 + 23
	case 8:
		v6 = int32(uint32(v3) - *memmap.PtrUint32(0x5D4594, 1217444) - 5)
		v23 = a1 * 23
		v7 = int32(v4) - dword_5d4594_1217448 + 5
		v8 = v3
		v9 = v22 + 23
	case 9:
		v6 = int32(uint32(v3) - *memmap.PtrUint32(0x5D4594, 1217444))
		v7 = int32(v4) - dword_5d4594_1217448
		v4 = a2 * 23
		v8 = v21 + 23
		v23 = a1 * 23
		v9 = v22 + 23
	default:
		v6 = a1
		v7 = a1
		v4 = v24
		v8 = v23
		v9 = v24
	}
	*(*uint32)(unsafe.Add(v5, 32)) = uint32(v6*v6 + v7*v7)
	v11 = sub_4CA8B0(int32(v4)-dword_5d4594_1217448, int32(uint32(v8)-*memmap.PtrUint32(0x5D4594, 1217444)))
	*(*uint32)(unsafe.Add(v5, 40)) = uint32(v11)
	if v11 < 0 {
		for {
			v12 = int32(*(*uint32)(unsafe.Add(v5, 40)))
			*(*uint32)(unsafe.Add(v5, 40)) = uint32(v12) + 75000
			if uint32(v12)+75000 >= 0 {
				break
			}
		}
	}
	if *(*uint32)(unsafe.Add(v5, 40)) >= 75000 {
		for {
			v13 = int32(*(*uint32)(unsafe.Add(v5, 40)) - 75000)
			*(*uint32)(unsafe.Add(v5, 40)) = uint32(v13)
			if uint32(v13) < 75000 {
				break
			}
		}
	}
	v14 := sub_4CA8B0(int32(v9)-dword_5d4594_1217448, int32(uint32(v23)-*memmap.PtrUint32(0x5D4594, 1217444)))
	*(*uint32)(unsafe.Add(v5, 44)) = uint32(v14)
	if v14 < 0 {
		for {
			v15 = int32(*(*uint32)(unsafe.Add(v5, 44)))
			*(*uint32)(unsafe.Add(v5, 44)) = uint32(v15) + 75000
			if uint32(v15)+75000 >= 0 {
				break
			}
		}
	}
	if *(*uint32)(unsafe.Add(v5, 44)) >= 75000 {
		for {
			v16 = int32(*(*uint32)(unsafe.Add(v5, 44)) - 75000)
			*(*uint32)(unsafe.Add(v5, 44)) = uint32(v16)
			if uint32(v16) < 75000 {
				break
			}
		}
	}
	v17 = int32(*(*uint32)(unsafe.Add(v5, 44)))
	v18 = int32(*(*uint32)(unsafe.Add(v5, 40)))
	if v17 < v18 {
		*(*uint32)(unsafe.Add(v5, 40)) = uint32(v17)
		*(*uint32)(unsafe.Add(v5, 44)) = uint32(v18)
	}
	if *(*uint32)(unsafe.Add(v5, 44))-*(*uint32)(unsafe.Add(v5, 40)) < 37500 {
		sub_4CAE90(v5)
		return
	}
	v19 := sub_4CAED0(v5)
	*(*uint32)(unsafe.Add(v19, 40)) = 0
	*(*uint32)(unsafe.Add(v19, 44)) = *(*uint32)(unsafe.Add(v5, 40))
	*(*uint32)(unsafe.Add(v5, 40)) = *(*uint32)(unsafe.Add(v5, 44))
	*(*uint32)(unsafe.Add(v5, 44)) = 74999
	sub_4CAE90(v19)
	sub_4CAE90(v5)
}
func sub_497F60(a1 int32, a2 int32, a3 int8, a4 int32, a5 *client.Drawable) {
	v5 := sub_4CADD0()
	*(*uint8)(unsafe.Add(v5, 56)) = uint8(a3)
	*(*uint32)(unsafe.Add(v5, 32)) = uint32(a4)
	*(*uint8)(unsafe.Add(v5, 48)) = 1
	*(**client.Drawable)(unsafe.Add(v5, 20)) = a5
	if a2 >= a1 {
		*(*uint32)(unsafe.Add(v5, 40)) = uint32(a1)
		*(*uint32)(unsafe.Add(v5, 44)) = uint32(a2)
	} else {
		*(*uint32)(unsafe.Add(v5, 40)) = uint32(a2)
		*(*uint32)(unsafe.Add(v5, 44)) = uint32(a1)
	}
	if *(*int32)(unsafe.Add(v5, 40)) < 0 {
		for {
			v6 := int32(*(*uint32)(unsafe.Add(v5, 40)))
			*(*uint32)(unsafe.Add(v5, 40)) = uint32(v6) + 75000
			if uint32(v6)+75000 >= 0 {
				break
			}
		}
	}
	if *(*uint32)(unsafe.Add(v5, 40)) >= 75000 {
		for {
			v7 := int32(*(*uint32)(unsafe.Add(v5, 40)) - 75000)
			*(*uint32)(unsafe.Add(v5, 40)) = uint32(v7)
			if uint32(v7) < 75000 {
				break
			}
		}
	}
	if *(*int32)(unsafe.Add(v5, 44)) < 0 {
		for {
			v8 := int32(*(*uint32)(unsafe.Add(v5, 44)))
			*(*uint32)(unsafe.Add(v5, 44)) = uint32(v8) + 75000
			if uint32(v8)+75000 >= 0 {
				break
			}
		}
	}
	if *(*uint32)(unsafe.Add(v5, 44)) >= 75000 {
		for {
			v9 := int32(*(*uint32)(unsafe.Add(v5, 44)) - 75000)
			*(*uint32)(unsafe.Add(v5, 44)) = uint32(v9)
			if uint32(v9) < 75000 {
				break
			}
		}
	}
	if *(*int32)(unsafe.Add(v5, 44))-*(*int32)(unsafe.Add(v5, 40)) < 37500 {
		sub_4CAE90(v5)
		return
	}
	v10 := sub_4CAED0(v5)
	*(*uint32)(unsafe.Add(v10, 40)) = 0
	*(*uint32)(unsafe.Add(v10, 44)) = *(*uint32)(unsafe.Add(v5, 40))
	*(*uint32)(unsafe.Add(v5, 40)) = *(*uint32)(unsafe.Add(v5, 44))
	*(*uint32)(unsafe.Add(v5, 44)) = 74999
	sub_4CAE90(v10)
	sub_4CAE90(v5)
}
func sub_498030(a1 *uint32) {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 int32
		v9 int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)) + uint32(v1))
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)) + uint32(v2))
	v9 = sub_4CA8B0(int32(v2)-dword_5d4594_1217448, int32(uint32(v1)-*memmap.PtrUint32(0x5D4594, 1217444)))
	v5 = sub_4CA8B0(int32(v2)-dword_5d4594_1217448, int32(uint32(v3)-*memmap.PtrUint32(0x5D4594, 1217444)))
	v6 = sub_4CA8B0(int32(v4)-dword_5d4594_1217448, int32(uint32(v3)-*memmap.PtrUint32(0x5D4594, 1217444)))
	v7 = sub_4CA8B0(int32(v4)-dword_5d4594_1217448, int32(uint32(v1)-*memmap.PtrUint32(0x5D4594, 1217444)))
	sub_497F60(v9, v5, 1, math.MaxInt32, nil)
	sub_497F60(v5, v6, 4, math.MaxInt32, nil)
	sub_497F60(v6, v7, 2, math.MaxInt32, nil)
	sub_497F60(v7, v9, 3, math.MaxInt32, nil)
}
func sub_498110() {
	for result := sub_4CAEB0(); result != nil; result = sub_4CAEB0() {
		sub_498130(result)
	}
}
func sub_498130(a1 unsafe.Pointer) {
	for i := sub_498290(a1); i < dword_5d4594_1217460; i++ {
		v2 := *(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1217456, uint32(i)*4))
		if *(*int32)(unsafe.Add(v2, 40)) > *(*int32)(unsafe.Add(a1, 44)) {
			break
		}
		sub_498380(a1, *(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1217456, uint32(i)*4)))
		if int32(*(*uint8)(unsafe.Add(a1, 48))) == 0 || *(*int32)(unsafe.Add(a1, 44))-*(*int32)(unsafe.Add(a1, 40)) < 0 {
			sub_4CAE40(a1)
			return
		}
		if int32(*(*uint8)(unsafe.Add(v2, 48))) == 0 || *(*int32)(unsafe.Add(v2, 44))-*(*int32)(unsafe.Add(v2, 40)) < 0 {
			if sub_4982E0(v2) <= i {
				i--
			}
			sub_4CAE40(v2)
		}
	}
	sub_4981D0(a1)
}
func sub_4981D0(a1 unsafe.Pointer) {
	var (
		v1 int32
		v2 int32
		v3 int32
	)
	v1 = dword_5d4594_1217460 - 1
	v2 = 0
	for v2 <= v1 {
		v3 = (v1 + v2) / 2
		if *(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1217456, uint32(v3)*4)), 40)) >= *(*int32)(unsafe.Add(a1, 40)) {
			v1 = v3 - 1
		} else {
			v2 = v3 + 1
		}
	}
	sub_498220(a1, v2)
}
func sub_498220(a1 unsafe.Pointer, a2 int32) {
	if a2 < dword_5d4594_1217460 {
		libc.MemMove(unsafe.Add(dword_5d4594_1217456, uint32(a2)*4+4), unsafe.Add(dword_5d4594_1217456, uint32(a2)*4), int((uint32(dword_5d4594_1217460)+uint32(a2)*0x3FFFFFFF)*4))
	}
	*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1217456, uint32(a2)*4)) = a1
	dword_5d4594_1217460++
}
func sub_498290(a1 unsafe.Pointer) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
	)
	v1 = 0
	v2 = dword_5d4594_1217460 - 1
	if dword_5d4594_1217460-1 < 0 {
		return 0
	}
	for {
		v3 = (v2 + v1) / 2
		if *(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1217456, uint32(v3)*4)), 44)) >= *(*int32)(unsafe.Add(a1, 40)) {
			v2 = v3 - 1
		} else {
			v1 = v3 + 1
		}
		if v1 > v2 {
			break
		}
	}
	if v2 >= 0 {
		return v2
	} else {
		return 0
	}
}
func sub_4982E0(a1 unsafe.Pointer) int32 {
	v1 := sub_498330(a1)
	libc.MemMove(unsafe.Add(dword_5d4594_1217456, uint32(v1)*4), unsafe.Add(dword_5d4594_1217456, uint32((v1+1)*4)), int((dword_5d4594_1217460+int32(v1+1)*0x3FFFFFFF)*4))
	dword_5d4594_1217460--
	return v1
}
func sub_498330(a1 unsafe.Pointer) int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		result int32
		v5     int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 40)))
	v2 = 0
	v3 = dword_5d4594_1217460 - 1
	for {
		result = (v3 + v2) / 2
		v5 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1217456, uint32(result*4))), 40)))
		if v5 == v1 {
			break
		}
		if v5 >= v1 {
			v3 = (v3 + v2) / 2
		} else {
			v2 = result + 1
		}
		if v2 > v3 {
			panic(-1)
		}
	}
	return result
}
func sub_498380(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	var (
		v6  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 bool
		v13 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
	)
	v2 := int32(*(*uint32)(unsafe.Add(a1, 40)))
	v3 := int32(*(*uint32)(unsafe.Add(a2, 44)))
	if v3 < v2 {
		return
	}
	v4 := int32(*(*uint32)(unsafe.Add(a2, 40)))
	v5 := int32(*(*uint32)(unsafe.Add(a1, 44)))
	if v4 > v5 {
		return
	}
	if v4 < v2 {
		if v3 <= v5 {
			if *(*int32)(unsafe.Add(a1, 32)) >= *(*int32)(unsafe.Add(a2, 32)) {
				v6 = int32(*(*uint32)(unsafe.Add(a1, 44)))
				*(*uint32)(unsafe.Add(a1, 40)) = uint32(v3 + 1)
				if v3+1 > v6 {
					*(*uint8)(unsafe.Add(a1, 48)) = 0
				}
			} else {
				*(*uint32)(unsafe.Add(a2, 44)) = uint32(v2 - 1)
			}
			return
		}
		if *(*int32)(unsafe.Add(a1, 32)) < *(*int32)(unsafe.Add(a2, 32)) {
			v7 := sub_4CAED0(a2)
			v8 = int32(*(*uint32)(unsafe.Add(v7, 44)))
			v9 = int32(*(*uint32)(unsafe.Add(a1, 44)) + 1)
			*(*uint32)(unsafe.Add(v7, 40)) = uint32(v9)
			if v9 > v8 {
				*(*uint8)(unsafe.Add(v7, 48)) = 0
			}
			v10 = int32(*(*uint32)(unsafe.Add(a1, 40)) - 1)
			v11 = int32(*(*uint32)(unsafe.Add(a2, 40)))
			*(*uint32)(unsafe.Add(a2, 44)) = uint32(v10)
			if v11 > v10 {
				*(*uint8)(unsafe.Add(a2, 48)) = 0
			}
			sub_4CAE90(v7)
			return
		}
		*(*uint8)(unsafe.Add(a1, 48)) = 0
		return
	}
	v12 = v3 <= v5
	v13 = int32(*(*uint32)(unsafe.Add(a1, 32)))
	if v12 {
		if v13 >= *(*int32)(unsafe.Add(a2, 32)) {
			v14 := sub_4CAED0(a1)
			v15 = int32(*(*uint32)(unsafe.Add(v14, 44)))
			v16 = int32(*(*uint32)(unsafe.Add(a2, 44)) + 1)
			*(*uint32)(unsafe.Add(v14, 40)) = uint32(v16)
			if v16 > v15 {
				*(*uint8)(unsafe.Add(v14, 48)) = 0
			}
			v17 = int32(*(*uint32)(unsafe.Add(a2, 40)) - 1)
			v18 = int32(*(*uint32)(unsafe.Add(a1, 40)))
			*(*uint32)(unsafe.Add(a1, 44)) = uint32(v17)
			if v18 > v17 {
				*(*uint8)(unsafe.Add(a1, 48)) = 0
			}
			sub_4CAE90(v14)
		} else {
			*(*uint8)(unsafe.Add(a2, 48)) = 0
		}
	} else {
		if v13 >= *(*int32)(unsafe.Add(a2, 32)) {
			v21 = v4 - 1
			v22 = int32(*(*uint32)(unsafe.Add(a1, 40)))
			*(*uint32)(unsafe.Add(a1, 44)) = uint32(v21)
			if v22 <= v21 {
				return
			}
			*(*uint8)(unsafe.Add(a1, 48)) = 0
			return
		}
		v19 = int32(*(*uint32)(unsafe.Add(a2, 44)))
		v20 = v5 + 1
		*(*uint32)(unsafe.Add(a2, 40)) = uint32(v20)
		if v20 > v19 {
			*(*uint8)(unsafe.Add(a2, 48)) = 0
		}
	}
}
func nox_xxx_client_4984B0_drawable(a1 *client.Drawable) int32 {
	var (
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 *int32
		v23 int32
		v24 int32
		v25 int32
		v26 int32
		v27 int32
		v28 *int32
		v29 int32
		v30 int32
		v31 int32
		v32 int32
		v34 int32
		v35 int32
		v36 int32
		v37 int32
		v38 int32
		v39 int32
		v40 int32
		v41 int32
		v42 int32
		v43 int32
		v44 int32
		v45 int32
		a1a int4
		a2  int4
		v48 int4
		i   *int32
		v50 int32
		v51 int32
	)
	v1 := a1
	if *(*uint32)(unsafe.Add(a1.C(), 300)) == 0 {
		return 0
	}
	if a1.C() == *memmap.PtrPtr(0x852978, 8) {
		return 1
	}
	if int32(int8(*(*uint8)(unsafe.Add(a1.C(), 112)))) >= 0 {
		v42 = int32(a1.PosVec.X)
		v43 = int32(a1.PosVec.Y)
		v6 = int32(a1.PosVec.X)
	} else {
		if (int32(*(*uint8)(unsafe.Add(a1.C(), 116))) & 4) == 0 {
			return int32(a1.Field_33)
		}
		v3 = int32(a1.PosVec.X)
		v4 = int32(a1.Field_74_4) * 8
		v5 = *memmap.PtrInt32(0x587000, uintptr(v4)+196184)
		v6 = v3 + v5/2
		v42 = v3 + v5/2
		v43 = int32(a1.PosVec.Y + int(uint32(*memmap.PtrInt32(0x587000, uintptr(v4)+196188)/2)))
	}
	if a1.Flags30Val&0x10000 != 0 {
		return int32(a1.Field_33)
	}
	v31 = 0
	v33 := nox_draw_getViewport_437250()
	v7 = int32(v33.World.Min.X - int(*(*uint32)(unsafe.Pointer(v33))))
	v44 = v7
	v8 = int32(v33.World.Min.Y - v33.Screen.Min.Y)
	v45 = v8
	a1a.field_0 = int32(*(*uint32)(unsafe.Pointer(v33)) + uint32(v33.Size.X/2))
	a1a.field_4 = int32(v33.Screen.Min.Y + v33.Field12 + v33.Size.Y/2)
	v37 = v6 - v7
	a1a.field_8 = v6 - v7
	a1a.field_C = v43 - v8
	v9 = int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1217464)*8+1203868))
	v10 = int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1217464)*8+1203872))
	if dword_5d4594_1217464 <= 0 {
		return 1
	}
	for i = memmap.PtrInt32(0x5D4594, 1203880); ; i = (*int32)(unsafe.Add(unsafe.Pointer(i), 4*2)) {
		a2.field_4 = v10
		a2.field_0 = v9
		v34 = *(*int32)(unsafe.Add(unsafe.Pointer(i), -int(4*1)))
		v11 = *i
		a2.field_8 = *(*int32)(unsafe.Add(unsafe.Pointer(i), -int(4*1)))
		v39 = v11
		a2.field_C = v11
		if sub_427C80(&a1a, &a2) != 0 {
			break
		}
		v9 = v34
		v10 = v39
		if func() int32 {
			p := &v31
			*p++
			return *p
		}() >= dword_5d4594_1217464 {
			return 1
		}
	}
	if v1.Shape.Kind == 2 {
		v12 = int32(v1.Shape.Circle.R)
		v50 = v12
		if int32(*(*uint16)(unsafe.Add(v1.C(), 2))) != 0 {
			v35 = int32(*(*uint16)(unsafe.Add(v1.C(), 6)))
			v13 = v6 - (int32(*(*uint16)(unsafe.Add(v1.C(), 4))) >> 1) - v7
			v14 = v43 + v12 + int32(v1.ZVal) - v35 - v8 - int32(v1.Field_24)
			v15 = v13 + int32(*(*uint16)(unsafe.Add(v1.C(), 4)))
			v16 = v14 + v35
		} else {
			v13 = v6 - v12 - v7
			v14 = v43 - v12 - v8 - int32(v1.Field_25)
			v15 = v42 + v50 - v44
			v16 = v43 + v50 + int32(v1.ZVal) - v45 - int32(v1.Field_24)
		}
	} else if int32(*(*uint16)(unsafe.Add(v1.C(), 2))) != 0 {
		v13 = v6 - (int32(*(*uint16)(unsafe.Add(v1.C(), 4))) >> 1) - v7
		v16 = int32(v1.Shape.Box.RightTop2) + v43 + int32(v1.ZVal) - v8
		v14 = v16 - int32(*(*uint16)(unsafe.Add(v1.C(), 6)))
		v15 = v13 + int32(*(*uint16)(unsafe.Add(v1.C(), 4)))
	} else {
		v13 = v37 + int32(v1.Shape.Box.LeftBottom2)
		v17 = v43 - v8 - int32(v1.Field_25)
		v14 = int32(v1.Shape.Box.LeftBottom) + v17
		v15 = v37 + int32(v1.Shape.Box.RightTop)
		v16 = int32(v1.Shape.Box.RightTop2) + v43 + int32(v1.ZVal) - v45
	}
	v32 = 0
	v51 = 0
	v41 = v13
	v38 = v14
	v40 = v15
	v36 = v16
	if v13 < *(*int32)(unsafe.Pointer(v33)) || int(v13) > v33.Screen.Max.X {
		v32 = 1
	} else {
		v51 = 1
	}
	if int(v14) < v33.Screen.Min.Y || int(v14) > v33.Screen.Max.Y {
		v32++
	} else {
		v51++
	}
	if v15 < *(*int32)(unsafe.Pointer(v33)) || int(v15) > v33.Screen.Max.X {
		v32++
	} else {
		v51++
	}
	if int(v16) < v33.Screen.Min.Y || int(v16) > v33.Screen.Max.Y {
		v32++
	} else {
		v51++
	}
	if int32(*(*uint16)(unsafe.Add(v1.C(), 2))) != 0 {
		if v15-v13 > 6 {
			v13 += 3
			v15 -= 3
		}
		if v16-v14 >= 22 {
			v14 += 11
			v16 -= 11
		}
	}
	if v51 == 0 || v32 == 0 {
		return 0
	}
	v48.field_0 = a1a.field_0
	v48.field_4 = a1a.field_4
	if v41 >= *(*int32)(unsafe.Pointer(v33)) {
		if int(v40) <= v33.Screen.Max.X {
			goto LABEL_50
		}
		v48.field_8 = v13
		a1a.field_8 = v13
	} else {
		v48.field_8 = v15
		a1a.field_8 = v15
	}
	a1a.field_C = v14
	v48.field_C = v16
LABEL_50:
	if int(v38) >= v33.Screen.Min.Y {
		if int(v36) <= v33.Screen.Max.Y {
			goto LABEL_55
		}
		a1a.field_8 = v13
		v48.field_C = v14
		a1a.field_C = v14
	} else {
		a1a.field_8 = v13
		v48.field_C = v16
		a1a.field_C = v16
	}
	v48.field_8 = v15
LABEL_55:
	v18 = dword_5d4594_1217464
	v19 = 0
	v20 = int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1217464)*8+1203868))
	v21 = int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1217464)*8+1203872))
	if dword_5d4594_1217464 > 0 {
		v22 = memmap.PtrInt32(0x5D4594, 1203880)
		for {
			v23 = *(*int32)(unsafe.Add(unsafe.Pointer(v22), -int(4*1)))
			v24 = *v22
			a2.field_4 = v21
			a2.field_0 = v20
			a2.field_8 = v23
			a2.field_C = v24
			if sub_427C80(&a1a, &a2) != 0 {
				return 0
			}
			v18 = dword_5d4594_1217464
			v19++
			v22 = (*int32)(unsafe.Add(unsafe.Pointer(v22), 4*2))
			v20 = v23
			v21 = v24
			if v19 >= dword_5d4594_1217464 {
				break
			}
		}
	}
	v25 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v18*8)+1203868))
	v26 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v18*8)+1203872))
	v27 = 0
	if v18 <= 0 {
		return 1
	}
	v28 = memmap.PtrInt32(0x5D4594, 1203880)
	for {
		v29 = *(*int32)(unsafe.Add(unsafe.Pointer(v28), -int(4*1)))
		v30 = *v28
		a2.field_0 = v25
		a2.field_4 = v26
		a2.field_8 = v29
		a2.field_C = v30
		if sub_427C80(&v48, &a2) != 0 {
			return 0
		}
		v27++
		v28 = (*int32)(unsafe.Add(unsafe.Pointer(v28), 4*2))
		v25 = v29
		v26 = v30
		if v27 >= dword_5d4594_1217464 {
			return 1
		}
	}
}
func sub_498AE0() {
	var (
		v0 int32
		v1 int32
		i  int32
	)
	nox_client_drawEnableAlpha_434560(1)
	nox_set_color_rgb_434430(0, 0, 0)
	v0 = dword_5d4594_1217464
	v1 = 0
	for i = dword_5d4594_1217464 - 1; v1 < v0; v1++ {
		if int32(*memmap.PtrUint8(0x5D4594, uintptr(i)+1212324)) == 12 {
			sub_498B50(int32(*memmap.PtrUint32(0x5D4594, uintptr(i*8)+1203876)), int32(*memmap.PtrUint32(0x5D4594, uintptr(i*8)+1203880)), int32(*memmap.PtrUint32(0x5D4594, uintptr(v1*8)+1203876)), int32(*memmap.PtrUint32(0x5D4594, uintptr(v1*8)+1203880)))
			v0 = dword_5d4594_1217464
		}
		i = v1
	}
	nox_client_drawEnableAlpha_434560(0)
}
func sub_498B50(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		result int32
		v15    uint8
		v16    int32
		v17    int32
		v18    int32
	)
	v4 = a3
	v5 = a1
	v6 = a2
	v7 = a2 - a4
	v8 = a1 - a3
	v9 = a1 - a3
	v10 = a4 - a2
	if a1-a3 < 0 {
		v8 = a3 - a1
	}
	if v7 < 0 {
		v7 = a4 - a2
	}
	if v8 <= v7 {
		v16 = 0
		if v10 < 0 {
			v17 = 1
		} else {
			v17 = -1
		}
	} else {
		v17 = 0
		v11 = bool2int32(v9 < 0) - 1
		*(*uint8)(unsafe.Pointer(&v11)) = uint8(int8(v11 & 0xFE))
		v16 = v11 + 1
	}
	v15 = 208
	v12 = a4 - v6
	v13 = v4 - v5
	v18 = 10
	for {
		nox_client_drawSetAlpha_434580(v15)
		v15 -= 20
		nox_client_drawAddPoint_49F500(v5, v6)
		nox_client_drawAddPoint_49F500(v5+v13, v12+v6)
		nox_client_drawLineFromPoints_49E4B0()
		v5 += v17
		v6 += v16
		result = func() int32 {
			p := &v18
			*p--
			return *p
		}()
		if v18 == 0 {
			break
		}
	}
	return result
}
func sub_498C20(a1 *Point32, a2 *Point32, a3 int32) int32 {
	var (
		v3  *Point32
		v4  *Point32
		v5  int8
		v6  int8
		v7  int32
		v8  int32
		v9  *int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 bool
		v21 float32
		v22 float32
		v23 float32
		v24 float32
		v25 float32
		v26 float32
		v27 float32
		v28 float32
		v29 float32 = 0
		v30 float32
		v31 int32 = 0
		v32 int32
		v33 *uint8
		a1a Point32
		a2a Point32
		a3a Point32
		v37 int8
		v38 int8
		v39 float32
	)
	v3 = a1
	if a1 == nil {
		return 0
	}
	v4 = a2
	if a2 == nil {
		return 0
	}
	if a3 == 0 {
		return 0
	}
	dword_5d4594_1217452 = 0
	v5 = sub_4990D0((*uint32)(unsafe.Pointer(a1)), (*uint32)(unsafe.Pointer(a2)))
	v6 = v5
	v37 = v5
	if int32(v5) == 0 {
		return 0
	}
	if int32(v5) != 4 && int32(v5) != 8 {
		v29 = float32(float64(a2.Y-v3.Y) / float64(a2.X-v3.X))
		v27 = float32(float64(v3.X) * float64(v29))
		v31 = v3.Y - int32(v27)
	}
	v7 = dword_5d4594_1217464
	v8 = 0
	v32 = 0
	if dword_5d4594_1217464 > 0 {
		v9 = memmap.PtrInt32(0x5D4594, 1203884)
		v33 = (*uint8)(memmap.PtrOff(0x5D4594, 1203884))
		for {
			a2a = *(*Point32)(unsafe.Add(unsafe.Pointer(v9), -int(unsafe.Sizeof(Point32{})*1)))
			if v8 == v7-1 {
				a3a = *(*Point32)(memmap.PtrOff(0x5D4594, 1203876))
			} else {
				v10 = *(*int32)(unsafe.Add(unsafe.Pointer(v9), 4*1))
				a3a.X = *v9
				a3a.Y = v10
			}
			v38 = sub_4990D0((*uint32)(unsafe.Pointer(&a2a)), (*uint32)(unsafe.Pointer(&a3a)))
			if int32(v38) != 0 && ((int32(v6)&1) == 0 || a2a.X <= v3.X || a2a.X <= v4.X || a3a.X <= v3.X || a3a.X <= v4.X) && ((int32(v37)&2) == 0 || a2a.X >= v3.X || a2a.X >= v4.X || a3a.X >= v3.X) {
				if (int32(v37)&4) == 0 || (func() bool {
					v11 = v3.Y
					return a2a.Y <= v11
				}()) || (func() bool {
					v12 = a2.Y
					return a2a.Y <= v12
				}()) || a3a.Y <= v11 || a3a.Y <= v12 {
					if (int32(v37)&8) == 0 || (func() bool {
						v13 = v3.Y
						return a2a.Y >= v13
					}()) || (func() bool {
						v14 = a2.Y
						return a2a.Y >= v14
					}()) || a3a.Y >= v13 || a3a.Y >= v14 {
						if a2a.X == a3a.X {
							if int32(v37) == 4 || int32(v37) == 8 {
								goto LABEL_65
							}
							if int32(v37) != 1 && int32(v37) != 2 {
								a1a.X = a2a.X
								v26 = float32(float64(a2a.X) * float64(v29))
								a1a.Y = v31 + int32(v26)
								if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
									sub_499130(&a1a.X)
								}
								goto LABEL_65
							}
							a1a.Y = v3.X
							a1a.X = a2a.X
							if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
								sub_499130(&a1a.X)
								goto LABEL_65
							}
						} else {
							v28 = float32(float64(a3a.Y-a2a.Y) / float64(a3a.X-a2a.X))
							v21 = float32(float64(a2a.X) * float64(v28))
							v15 = int32(v21)
							v16 = a2a.Y - v15
							if int32(v37) == 4 || int32(v37) == 8 {
								if int32(v38) == 1 || int32(v38) == 2 {
									a1a.X = v3.X
									a1a.Y = a2a.X
									if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
										sub_499130(&a1a.X)
									}
								} else {
									a1a.X = v3.X
									v22 = float32(float64(a1a.X) * float64(v28))
									a1a.Y = v16 + int32(v22)
									if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
										sub_499130(&a1a.X)
									}
								}
							}
							if int32(v37) == 1 || int32(v37) == 2 {
								if int32(v38) == 1 || int32(v38) == 2 {
									goto LABEL_65
								}
								v25 = float32(float64(v31-v16) / float64(v28))
								v17 = int32(v25)
								v18 = v3.Y
								a1a.X = v17
								a1a.Y = v18
								if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
									sub_499130(&a1a.X)
								}
								goto LABEL_65
							}
							if v29 != v28 {
								v39 = float32(float64(v31 - v16))
								v30 = v28 - v29
								v23 = v39 / v30
								a1a.X = int32(v23)
								v24 = v39 * v28 / v30
								a1a.Y = v16 + int32(v24)
								if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
									sub_499130(&a1a.X)
									goto LABEL_65
								}
							}
						}
					}
				}
			}
		LABEL_65:
			v7 = dword_5d4594_1217464
			v8 = v32 + 1
			v9 = (*int32)(unsafe.Add(unsafe.Pointer(v33), 8))
			v19 = func() int32 {
				p := &v32
				*p++
				return *p
			}() < dword_5d4594_1217464
			v33 = (*uint8)(unsafe.Add(unsafe.Pointer(v33), 8))
			if !v19 {
				break
			}
			v6 = v37
			v4 = a2
		}
	}
	sub_4991E0((*uint32)(unsafe.Pointer(v3)))
	return int32(dword_5d4594_1217452)
}
func sub_4990D0(a1 *uint32, a2 *uint32) int8 {
	var (
		v2     int32
		v3     int32
		result int8
		v5     int32
		v6     int32
		v7     int32
		v8     int32
	)
	if *a1 <= *a2 {
		if *a1 >= *a2 {
			v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
			v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))
			if v7 <= v8 {
				if v7 >= v8 {
					result = 0
				} else {
					result = 8
				}
			} else {
				result = 4
			}
		} else {
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
			v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))
			result = 2
			if v5 <= v6 {
				if v5 < v6 {
					result = 10
				}
			} else {
				result = 6
			}
		}
	} else {
		v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))
		result = 1
		if v2 <= v3 {
			if v2 < v3 {
				result = 9
			}
		} else {
			result = 5
		}
	}
	return result
}
func sub_499130(a1 *int32) int32 {
	var result int32
	result = int32(dword_5d4594_1217452)
	if dword_5d4594_1217452 >= 32 {
		return result
	}
	result = int32(dword_5d4594_1217452 + 1)
	*memmap.PtrUint32(0x5D4594, uintptr(result*8)+1212060) = uint32(*a1)
	*memmap.PtrUint32(0x5D4594, uintptr(result*8)+1212064) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	dword_5d4594_1217452 = uint32(result)
	return result
}
func sub_499160(a1 *Point32, a2 *Point32, a3 *Point32) int32 {
	var (
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		result int32
	)
	v3 = a3.X
	if a3.X > a2.X {
		v4 = a3.Y
		if v4 > a2.Y {
			v3 = a3.X
			v6 = a2.X
			v4 = a2.Y
			v5 = a3.Y
		} else {
			v6 = a2.X
			v5 = a2.Y
		}
	} else {
		v4 = a2.Y
		if a3.Y > v4 {
			v6 = a3.X
			v3 = a2.X
			v5 = a3.Y
		} else {
			v5 = a2.Y
			v6 = a3.X
			v4 = a3.Y
			v3 = a2.X
		}
	}
	result = 0
	if !(a1.X >= v6 && a1.X <= v3) {
		return result
	}
	v7 = a1.Y
	if v7 >= v4 && v7 <= v5 {
		result = 1
	}
	return result
}
func sub_4991E0(a1 *uint32) {
	var (
		v1  int32
		v2  *uint32
		v3  int32
		v4  *uint8
		v5  int32
		v6  int32
		v7  *uint32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
	)
	v1 = int32(dword_5d4594_1217452)
	if dword_5d4594_1217452 > 0 {
		v2 = a1
		v3 = 1
		v12 = 1
		v4 = (*uint8)(memmap.PtrOff(0x5D4594, 1212068))
		for {
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) - *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)))
			v6 = int32((*(*uint32)(unsafe.Pointer(v4))-*v2)*(*(*uint32)(unsafe.Pointer(v4))-*v2) + uint32(v5*v5))
			if v3 < v1 {
				v7 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 8))
				v13 = v1 - v3
				for {
					v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1)) - *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)))
					v9 = int32((*v7-*v2)*(*v7-*v2) + uint32(v8*v8))
					if v9 < v6 {
						v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))
						v6 = v9
						v11 = int32(*(*uint32)(unsafe.Pointer(v4)))
						*(*uint32)(unsafe.Pointer(v4)) = *v7
						*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
						*v7 = uint32(v11)
						*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1)) = uint32(v10)
					}
					v7 = (*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*2))
					v13--
					if v13 == 0 {
						break
					}
				}
				v1 = int32(dword_5d4594_1217452)
				v3 = v12
			}
			v3++
			v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 8))
			v12 = v3
			if v3-1 >= v1 {
				break
			}
		}
	}
}
func sub_499290(a1 int32) Point32 {
	var result Point32
	result.X = memmap.Int32(0x5D4594, uintptr(a1*8)+1212068)
	result.Y = memmap.Int32(0x5D4594, uintptr(a1*8)+1212072)
	return result
}
func sub_4992B0(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
	)
	result = 0
	v7 = 0
	v8 = 0
	if dword_5d4594_1217464 <= 0 {
		return result
	}
	v3 = dword_5d4594_1217464*8 - 8
	for {
		v4 = *memmap.PtrInt32(0x5D4594, uintptr(v3)+1203876)
		v5 = *memmap.PtrInt32(0x5D4594, uintptr(v3)+1203880)
		v6 = *memmap.PtrInt32(0x5D4594, uintptr(v8*8)+1203880)
		if v6 > a2 {
			if v5 > a2 {
				v3 = func() int32 {
					p := &v8
					x := *p
					*p++
					return x
				}() * 8
				continue
			}
		} else if a2 < v5 {
			goto LABEL_8
		}
		if a2 >= v6 {
			v3 = func() int32 {
				p := &v8
				x := *p
				*p++
				return x
			}() * 8
			continue
		}
	LABEL_8:
		if a1 >= *memmap.PtrInt32(0x5D4594, uintptr(v8*8)+1203876)+(a2-v6)*(v4-*memmap.PtrInt32(0x5D4594, uintptr(v8*8)+1203876))/(v5-v6) {
			result = v7
		} else {
			result = bool2int32(v7 == 0)
			v7 = bool2int32(v7 == 0)
		}
		v3 = func() int32 {
			p := &v8
			x := *p
			*p++
			return x
		}() * 8
		continue
		if v8 >= dword_5d4594_1217464 {
			break
		}
	}
	return result
}
func nox_xxx_loadReflSheild_499360() int32 {
	var (
		v0 int32
		v1 int32
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 int32
		v8 *uint8
	)
	v0 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ReflectiveShieldNW"))
	*memmap.PtrPtr(0x5D4594, 1217468) = unsafe.Pointer(nox_new_drawable_for_thing(v0))
	v1 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ReflectiveShieldN"))
	*memmap.PtrPtr(0x5D4594, 1217472) = unsafe.Pointer(nox_new_drawable_for_thing(v1))
	v2 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ReflectiveShieldNE"))
	*memmap.PtrPtr(0x5D4594, 1217476) = unsafe.Pointer(nox_new_drawable_for_thing(v2))
	v3 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ReflectiveShieldW"))
	*memmap.PtrPtr(0x5D4594, 1217480) = unsafe.Pointer(nox_new_drawable_for_thing(v3))
	*memmap.PtrUint32(0x5D4594, 1217484) = 0
	v4 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ReflectiveShieldE"))
	*memmap.PtrPtr(0x5D4594, 1217488) = unsafe.Pointer(nox_new_drawable_for_thing(v4))
	v5 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ReflectiveShieldSW"))
	*memmap.PtrPtr(0x5D4594, 1217492) = unsafe.Pointer(nox_new_drawable_for_thing(v5))
	v6 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ReflectiveShieldS"))
	*memmap.PtrPtr(0x5D4594, 1217496) = unsafe.Pointer(nox_new_drawable_for_thing(v6))
	v7 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ReflectiveShieldSE"))
	*memmap.PtrPtr(0x5D4594, 1217500) = unsafe.Pointer(nox_new_drawable_for_thing(v7))
	v8 = (*uint8)(memmap.PtrOff(0x5D4594, 1217468))
	for {
		if unsafe.Pointer(v8) != memmap.PtrOff(0x5D4594, 1217484) {
			if *(*uint32)(unsafe.Pointer(v8)) != 0 {
				*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v8)), 120)) |= 0x1000000
				goto LABEL_5
			}
			return 0
		}
	LABEL_5:
		v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 4))
		if int32(uintptr(unsafe.Pointer(v8))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1217504))) {
			*memmap.PtrUint32(0x5D4594, 1217504) = 0
			return 1
		}
	}
}
func sub_499450() {
	v0 := (*uint8)(memmap.PtrOff(0x5D4594, 1217468))
	for {
		if *(*uint32)(unsafe.Pointer(v0)) != 0 {
			nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(*(**uint64)(unsafe.Pointer(v0)))))
		}
		*(*uint32)(unsafe.Pointer(v0)) = 0
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 4))
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1217504))) {
			break
		}
	}
	*memmap.PtrUint32(0x5D4594, 1217504) = 0
}
func nox_xxx_drawShield_499810(vp *noxrender.Viewport, dr *client.Drawable) int32 {
	var (
		a1 = vp
		a2 = dr
	)
	*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, uintptr(int32(a2.Field_74_2)*4)+1217468), 12)) = uint32(a2.PosVec.X + int(*memmap.PtrUint32(0x587000, uintptr(int32(a2.Field_74_2)*8)+161776)))
	*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, uintptr(int32(a2.Field_74_2)*4)+1217468), 16)) = uint32(a2.PosVec.Y + int(uint32(a2.ZVal)) + int(*memmap.PtrUint32(0x587000, uintptr(int32(a2.Field_74_2)*8)+161780)))
	v3 := AsDrawableP(*memmap.PtrPtr(0x5D4594, uintptr(int32(a2.Field_74_2)*4)+1217468))
	v3.DrawFunc.Get()(a1, v3)
	return 0
}
func nox_xxx_fxDrawTurnUndead_499880(a1 *int16) {
	if *memmap.PtrUint32(0x5D4594, 1217508) == 0 {
		*memmap.PtrUint32(0x5D4594, 1217508) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("UndeadKiller")))
	}
	for i := 0; i < 256; i += 6 {
		v3 := nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1217508), int32(*a1), int32(*(*int16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(int16(0))*1))))
		if v3 != nil {
			v4 := int32(int16(i)) * 8
			*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*254)) = uint16(int16(i))
			v3.Field_117 = uint32(float32(float64(*memmap.PtrFloat32(0x587000, uintptr(v4)+194136)) * 4.0))
			v5 := float64(*memmap.PtrFloat32(0x587000, uintptr(v4)+194140)) * 4.0
			v3.Field_119 = 0
			v3.Field_118 = uint32(float32(v5))
			v3.Field_79 = gameFrame()
			v3.Field_81 = uint32(*a1)
			v3.Field_82 = uint32(*(*int16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(int16(0))*1)))
			v3.Field_115.Set(nox_xxx_sprite_4CA540)
			nox_xxx_spriteToList_49BC80_drawable(v3)
			nox_xxx_spriteToSightDestroyList_49BAB0_drawable(v3)
		}
	}
}
func nox_xxx_bookRewardCli_499CF0(a1 uint32, a2 int32, a3 int32) {
	var (
		result uint32
		v4     int32
		a3a    Point32
	)
	if !noxflags.HasGame(2048) || (func() bool {
		result = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq()) - *memmap.PtrUint32(0x5D4594, 1217504)
		return result >= 2
	}()) {
		*memmap.PtrUint32(0x5D4594, 1217504) = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())
		if a1 == 2 {
			v4 = 0
		} else {
			v4 = bool2int32(a1 == 3) + 2
		}
		a3a.X = 5
		a3a.Y = nox_win_height / 3
		nox_xxx_bookSetForward_45D200(a1, a2, &a3a)
		nox_xxx_draw_499E70(v4, a3a.X, a3a.Y, 271, 166, 1, 1)
		nox_xxx_draw_499E70(v4, a3a.X, a3a.Y, 135, 166, 2, 1)
		nox_xxx_draw_499E70(v4, a3a.X, a3a.Y+166, 135, 166, 2, 1)
		nox_xxx_draw_499E70(v4, a3a.X+271, a3a.Y, 271, 166, 1, 2)
		nox_xxx_draw_499E70(v4, a3a.X+135, a3a.Y, 135, 166, 2, 2)
		nox_xxx_draw_499E70(v4, a3a.X+135, a3a.Y+166, 135, 166, 2, 2)
		if a1 != 4 && a3 == 1 {
			nox_xxx_bookFillAll_45D570(a1, a2)
		}
	}
}
func sub_499F60(a1 int32, a2 int32, a3 int32, a4 int16, a5 int8, a6 int8, a7 int8, a8 int8, a9 int8, a10 int32) {
	var (
		result *uint32
		v11    int32
		v12    int32
		v13    *uint32
		v14    int32
	)
	if *memmap.PtrUint32(0x5D4594, 1217512) == 0 {
		*memmap.PtrUint32(0x5D4594, 1217512) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("RedBubbleParticle")))
		*memmap.PtrUint32(0x5D4594, 1217516) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("WhiteBubbleParticle")))
		*memmap.PtrUint32(0x5D4594, 1217520) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("LightBlueBubbleParticle")))
		*memmap.PtrUint32(0x5D4594, 1217524) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("OrangeBubbleParticle")))
		*memmap.PtrUint32(0x5D4594, 1217528) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GreenBubbleParticle")))
		*memmap.PtrUint32(0x5D4594, 1217532) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("VioletBubbleParticle")))
		*memmap.PtrUint32(0x5D4594, 1217536) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("LightVioletBubbleParticle")))
		*memmap.PtrUint32(0x5D4594, 1217540) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("YellowBubbleParticle")))
	}
	result = (*uint32)(nox_xxx_spriteLoadAdd_45A360_drawable(a1, a2, a3).C())
	v13 = result
	if result != nil {
		*(*uint8)(unsafe.Add(unsafe.Pointer(&v11), 1)) = *(*uint8)(unsafe.Add(unsafe.Pointer(&a4), unsafe.Sizeof(int16(0))-1))
		*(*uint8)(unsafe.Pointer(&result)) = *(*uint8)(unsafe.Add(unsafe.Pointer(result), 160))
		*(*uint8)(unsafe.Pointer(&v12)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v13), 156))
		*(*uint16)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(uint16(0))*52)) = uint16(a4)
		*(*uint8)(unsafe.Pointer(&v11)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v13), 152))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*108)) = nox_color_rgb_4344A0(v11, v12, int32(uintptr(unsafe.Pointer(result))))
		if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1217512) {
			v14 = int32(nox_color_rgb_4344A0(math.MaxUint8, 128, 128))
		} else if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1217516) {
			v14 = int32(nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, math.MaxUint8))
		} else if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1217524) {
			v14 = int32(nox_color_rgb_4344A0(math.MaxUint8, 100, 50))
		} else if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1217528) {
			v14 = int32(nox_color_rgb_4344A0(64, math.MaxUint8, 64))
		} else if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1217532) {
			v14 = int32(nox_color_rgb_4344A0(math.MaxUint8, 100, math.MaxUint8))
		} else if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1217536) {
			v14 = int32(nox_color_rgb_4344A0(math.MaxUint8, 200, math.MaxUint8))
		} else if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1217540) {
			v14 = int32(nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, 200))
		} else {
			v14 = int32(nox_color_rgb_4344A0(200, 200, math.MaxUint8))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*109)) = uint32(v14)
		*(*uint8)(unsafe.Add(unsafe.Pointer(v13), 440)) = uint8(a5)
		*(*uint8)(unsafe.Add(unsafe.Pointer(v13), 443)) = uint8(a6)
		*(*uint8)(unsafe.Add(unsafe.Pointer(v13), 442)) = uint8(a6)
		*(*uint8)(unsafe.Add(unsafe.Pointer(v13), 441)) = 1
		*(*uint8)(unsafe.Add(unsafe.Pointer(v13), 444)) = uint8(a8)
		*(*uint8)(unsafe.Add(unsafe.Pointer(v13), 445)) = uint8(a9)
		*(*uint8)(unsafe.Add(unsafe.Pointer(v13), 446)) = uint8(a7)
		nox_xxx_spriteToSightDestroyList_49BAB0_drawable((*client.Drawable)(unsafe.Pointer(v13)))
		nox_xxx_spriteTransparentDecay_49B950((*client.Drawable)(unsafe.Pointer(v13)), a10)
		nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(v13)))
	}
}
func nox_alloc_npcs() {
	arr, _ := alloc.Make([]nox_npc{}, int(nox_max_npcs))
	npc_array = &arr[0]
}
func nox_new_npc(id int32) *nox_npc {
	var (
		n   int32    = 0
		cur *nox_npc = npc_array
	)
	for cur.live != 0 {
		cur = (*nox_npc)(unsafe.Add(unsafe.Pointer(cur), unsafe.Sizeof(nox_npc{})*1))
		n++
		if n >= nox_max_npcs {
			return nil
		}
	}
	nox_init_npc(cur, id)
	return cur
}
func nox_npc_by_id(id int32) *nox_npc {
	var (
		n   int32    = 0
		cur *nox_npc = npc_array
	)
	for cur.id != id || cur.live == 0 {
		cur = (*nox_npc)(unsafe.Add(unsafe.Pointer(cur), unsafe.Sizeof(nox_npc{})*1))
		n++
		if n >= nox_max_npcs {
			return nil
		}
	}
	return cur
}
func nox_init_npc(ptr *nox_npc, id int32) int32 {
	*ptr = nox_npc{}
	ptr.live = 1
	ptr.id = id
	return id
}
func nox_npc_set_328(id int32, a2 int32) *nox_npc {
	var p *nox_npc = nox_npc_by_id(id)
	if p != nil {
		p.data8[326] = uint32(a2)
	}
	return p
}
func nox_xxx_clientEquip_49A3D0(a1 int8, a2 int32, a3 int32, a4 unsafe.Pointer) {
	var (
		k   *uint32
		v7  *byte
		i   *uint32
		v12 *byte
	)
	npc := nox_npc_by_id(a2)
	if npc == nil {
		return
	}
	if int32(a1) == 81 || int32(a1) == 80 {
		var v10 int32 = 0
		for i = (*uint32)(unsafe.Add(unsafe.Pointer(npc), 32)); *i != 0; i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*6)) {
			if func() int32 {
				p := &v10
				*p++
				return *p
			}() >= 27 {
				return
			}
		}
		v12 = (*byte)(unsafe.Add(unsafe.Pointer(npc), v10*24))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*8)) = uint32(a3)
		v13 := (*[4]*server.ModifierEff)(unsafe.Add(unsafe.Pointer(v12), 36))
		*(*uint32)(unsafe.Add(unsafe.Pointer(npc), 4*326)) |= uint32(a3)
		for j := 0; j < 4; j++ {
			mod := nox_xxx_modifGetDescById_413330(int32(*(*uint8)(unsafe.Add(a4, j))))
			v13[j] = mod
		}
	} else {
		var v5 int32 = 0
		for k = (*uint32)(unsafe.Add(unsafe.Pointer(npc), 680)); *k != 0; k = (*uint32)(unsafe.Add(unsafe.Pointer(k), 4*6)) {
			if func() int32 {
				p := &v5
				*p++
				return *p
			}() >= 26 {
				return
			}
		}
		v7 = (*byte)(unsafe.Add(unsafe.Pointer(npc), v5*24))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*170)) = uint32(a3)
		v8 := (*[4]*server.ModifierEff)(unsafe.Add(unsafe.Pointer(v7), 684))
		*(*uint32)(unsafe.Add(unsafe.Pointer(npc), 4*327)) |= uint32(a3)
		for l := 0; l < 4; l++ {
			mod := nox_xxx_modifGetDescById_413330(int32(*(*uint8)(unsafe.Add(a4, l))))
			v8[l] = mod
		}
	}
}

type healthChange struct {
	Field0  uint32        // 0, 0
	Field4  uint32        // 1, 4
	Field8  uint32        // 2, 8
	Field12 *healthChange // 3, 12
	Field16 *healthChange // 4, 16
}

func nox_xxx_allocArrayHealthChanges_49A5F0() int32 {
	nox_alloc_healthChange_1301772 = alloc.NewClassT("HealthChange", healthChange{}, 32)
	if nox_alloc_healthChange_1301772.Class == nil {
		return 0
	}
	dword_5d4594_1301780 = nox_xxx_guiFontPtrByName_43F360(internCStr("numbers"))
	return 1
}
func sub_49A630() {
	nox_alloc_healthChange_1301772.FreeAllObjects()
	dword_5d4594_1301776 = nil
}
func nox_xxx_cliAddHealthChange_49A650(a1 int32, a2 int16) {
	result := nox_alloc_healthChange_1301772.NewObject()
	v3 := result
	if result == nil {
		return
	}
	result.Field0 = uint32(a1)
	*(*uint16)(unsafe.Pointer(&result.Field4)) = uint16(a2)
	result.Field8 = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())
	v3.Field12 = dword_5d4594_1301776
	v3.Field16 = nil
	if dword_5d4594_1301776 != nil {
		dword_5d4594_1301776.Field16 = v3
	}
	dword_5d4594_1301776 = v3
}
func sub_49A6A0(vp *noxrender.Viewport, dr *client.Drawable) {
	var (
		a1  = vp
		a2  = dr
		v3  int32
		v5  int32
		v6  int32
		v7  int32
		v9  int32
		v12 int32
		v13 [80]wchar2_t
	)
	v10 := nox_xxx_bookGet_430B40_get_mouse_prev_seq()
	if a2.C() == *memmap.PtrPtr(0x852978, 8) {
		v9 = int32(*memmap.PtrUint32(0x85B3FC, 940))
	} else {
		v9 = int32(nox_color_yellow_2589772)
	}
	v2 := dword_5d4594_1301776
	v8 := dword_5d4594_1301776
	if dword_5d4594_1301776 != nil {
		for {
			v3 = int32(v2.Field8)
			v4 := v2.Field12
			v11 := v2.Field12
			if uint32(v10-v3) <= 0x1E {
				if v2.Field0 == a2.Field_32 {
					v5 = int32(a1.Screen.Min.X + a2.PosVec.X - a1.World.Min.X)
					v6 = int32(uint32(uint64(a2.PosVec.Y+a1.Screen.Min.Y+int(uint32((v3-v10)*2))-int(uint32(a2.ZVal))) - uint64(int64(a2.Field_25)) - uint64(a1.World.Min.Y)))
					nox_swprintf(&v13[0], internWStr("%d"), cmath.Abs(int64(*(*int16)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(int16(0))*2)))))
					nox_xxx_drawGetStringSize_43F840(dword_5d4594_1301780, &v13[0], &v12, nil, 0)
					v7 = v12/(-2) + v5
					nox_xxx_drawSetTextColor_434390(int32(nox_color_black_2650656))
					nox_xxx_drawString_43F6E0(dword_5d4594_1301780, &v13[0], v7-1, v6-1)
					nox_xxx_drawString_43F6E0(dword_5d4594_1301780, &v13[0], v7-1, v6+1)
					nox_xxx_drawString_43F6E0(dword_5d4594_1301780, &v13[0], v7+1, v6-1)
					nox_xxx_drawString_43F6E0(dword_5d4594_1301780, &v13[0], v7+1, v6+1)
					if int32(*(*int16)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(int16(0))*2))) <= 0 {
						nox_xxx_drawSetTextColor_434390(v9)
					} else {
						nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x8531A0, 2572))
					}
					nox_xxx_drawString_43F6E0(dword_5d4594_1301780, &v13[0], v7, v6)
					v4 = v11
				}
			} else {
				sub_49A880(v2)
			}
			v8 = v4
			if v4 == nil {
				break
			}
			v2 = v4
		}
	}
}
func sub_49A880(a1 *healthChange) {
	v1 := a1.Field16
	if v1 != nil {
		v1.Field12 = a1.Field12
	} else {
		dword_5d4594_1301776 = a1.Field12
	}
	v2 := a1.Field12
	if v2 != nil {
		v2.Field16 = a1.Field16
	}
	nox_alloc_healthChange_1301772.FreeObjectFirst(a1)
}
func Sub_49A8C0() {
	nox_alloc_healthChange_1301772.Free()
	dword_5d4594_1301776 = nil
	dword_5d4594_1301780 = nil
}
func nox_xxx_updateSpritePosition_49AA90(dr *client.Drawable, a2 int32, a3 int32) {
	var (
		a1 = dr
		v3 int32
		v4 int32
		v5 int32
		v6 int32
	)
	v3 = a2
	v4 = int32(a1.PosVec.Y)
	a1.Field_8 = uint32(a1.PosVec.X)
	a1.Field_9 = uint32(v4)
	if a2 < 0 || a2 >= 5888 || (func() bool {
		v5 = a3
		return a3 < 0
	}()) || a3 >= 5888 {
		v3 = 50
		v5 = 50
		if (a1.Flags30Val & 0x400000) == 0 {
			nox_xxx_sprite_45A110_drawable(dr)
		}
	}
	v6 = int32(a1.Field_5)
	a1.PosVec.X = int(uint32(v3))
	a1.Field_10 = uint32(v6)
	a1.PosVec.Y = int(uint32(v5))
	a1.Field_5 = gameFrame()
	nox_xxx_sprite_49AA00_drawable(dr)
}
func sub_49AEA0() int32 {
	if nox_alloc_pixelSpan_1301844 != nil {
		nox_free_alloc_class(nox_alloc_pixelSpan_1301844)
		nox_alloc_pixelSpan_1301844 = nil
	}
	if dword_5d4594_1301848 != nil {
		alloc.FreePtr(dword_5d4594_1301848)
		dword_5d4594_1301848 = nil
	}
	return 1
}
func sub_49B3E0() int32 {
	result := nox_new_window_from_file(internCStr("GGOver.wnd"), sub_49B420)
	dword_5d4594_1303452 = result
	if result == nil {
		return 0
	}
	nox_window_set_hidden(result, 1)
	nox_xxx_wnd_46ABB0(dword_5d4594_1303452, 0)
	return 1
}
func sub_49B420(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var v3 int32
	if a2 != 16391 {
		return 0
	}
	v3 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	if v3 == 10701 {
		nox_client_quit_4460C0()
		sub_49B6B0()
	} else if v3 == 10702 {
		*(*uint16)(unsafe.Add(unsafe.Pointer(&a2), unsafe.Sizeof(uint16(0))*0)) = 1008
		nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&a2), 2, 1)
		sub_49B6B0()
		return 0
	}
	return 0
}
func sub_49B490() {
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1303452)
	dword_5d4594_1303452 = nil
}
func sub_49B6B0() int32 {
	nox_window_set_hidden(dword_5d4594_1303452, 1)
	nox_xxx_wnd_46ABB0(dword_5d4594_1303452, 0)
	return nox_xxx_windowFocus_46B500(nil)
}
func nox_xxx_consoleEsc_49B7A0() {
	var v0 int32
	v0 = 0
	if nox_xxx_guiCursor_477600() == 0 && nox_video_inFadeTransition_44E0D0() == 0 {
		if sub_460660() != 0 {
			v0 = 1
		}
		if sub_46A6A0() == 0 && v0 != 1 {
			if sub_45D9B0() == 1 {
				sub_45D870()
			} else {
				if sub_4BFE40() != 0 {
					v0 = 1
				}
				if nox_xxx_quickBarClose_4606B0() != 0 {
					v0 = 1
				}
				if sub_462740() != 0 {
					v0 = 1
				}
				if sub_44A4E0() == 0 && v0 != 1 {
					if sub_479590() == 2 {
						sub_4795A0(1)
					} else if sub_479590() == 3 {
						sub_4795A0(1)
					} else if sub_479590() == 4 {
						sub_4795A0(1)
					} else if sub_478040() == 0 && sub_479950() == 0 {
						if sub_467C10() != 0 {
							v0 = 1
						}
						if nox_xxx_bookHideMB_45ACA0(0) != 0 {
							v0 = 1
						}
						if nox_gui_console_Hide_4512B0() != 0 {
							v0 = 1
						}
						if sub_446780() != 0 {
							v0 = 1
						}
						if nox_xxx_guiServerOptionsTryHide_4574D0() != 0 {
							v0 = 1
						}
						if sub_48CAD0() != 0 {
							v0 = 1
						}
						if sub_4AD9B0(1) != 0 {
							v0 = 1
						}
						if sub_4C35B0(1) != 0 {
							v0 = 1
						}
						if sub_46D6F0() == 0 && v0 != 1 {
							if nox_xxx_game_4DCCB0() != 0 {
								sub_445C40()
							} else {
								nox_xxx_clientPlaySoundSpecial_452D80(231, 100)
							}
						}
					}
				}
			}
		}
	}
}
func sub_49BB80(a1 int8) {
	*memmap.PtrUint8(0x5D4594, 1303504) = uint8(a1)
	*memmap.PtrUint8(0x5D4594, 1303512) = 0
	*memmap.PtrUint32(0x5D4594, 1303516) = gameFrame()
	result := nox_xxx_spellGetDefArrayPtr_424820()
	dword_5d4594_1303508 = result
}
func sub_49BBB0() {
	*memmap.PtrUint8(0x5D4594, 1303504) = 0
}
func sub_49BBC0() {
	var (
		v0 int32
		v1 uint8
	)
	if int32(*memmap.PtrUint8(0x5D4594, 1303504)) != 0 {
		v1 = uint8(nox_xxx_spellPhonemes_424A20(int32(*memmap.PtrUint8(0x5D4594, 1303504)), int32(*memmap.PtrUint8(0x5D4594, 1303512))))
		if gameFrame() >= uint32(*memmap.PtrInt32(0x5D4594, 1303516)) {
			v0 = nox_xxx_spellGetPhoneme_4FE1C0(int32(nox_player_netCode_85319C), int8(v1))
			nox_xxx_clientPlaySoundSpecial_452D80(v0, 100)
			nox_client_setPhonemeFrame_476E00(int32(*memmap.PtrUint32(0x587000, uintptr(int32(v1)*4)+163576)))
			*memmap.PtrUint32(0x5D4594, 1303516) = gameFrame() + 3
			dword_5d4594_1303508 = nox_xxx_updateSpellRelated_424830(dword_5d4594_1303508, int32(v1))
			*memmap.PtrUint8(0x5D4594, 1303512)++
		}
		if dword_5d4594_1303508.Ind == int32(*memmap.PtrUint8(0x5D4594, 1303504)) {
			sub_49BBB0()
		}
	}
}
func nox_xxx_getSprite178_49BD50(dr *client.Drawable) *client.Drawable {
	if dr == nil {
		return nil
	}
	return dr.Field_94
}
func sub_49BD70(vp *noxrender.Viewport) {
	if nox_xxx_checkGameFlagPause_413A50() == 1 {
		return
	}
	var next *client.Drawable
	for it := nox_xxx_getSomeSprite_49BD40(); it != nil; it = next {
		next = nox_xxx_getSprite178_49BD50(it)
		if fnc1 := it.ClientUpdateFunc.Get(); fnc1 == nil || fnc1(vp, it) != 0 {
			if fnc2 := it.Field_115.Get(); fnc2 != nil {
				fnc2(vp, it)
			}
		}
	}
}
func nox_xxx_clientAddRayEffect_49C160(a1 unsafe.Pointer) {
	var (
		result *uint32
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		v6     *uint32
		v7     *uint32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    *uint8
	)
	result = *(**uint32)(memmap.PtrOff(0x5D4594, 1304312))
	if *memmap.PtrInt32(0x5D4594, 1304312) >= 96 {
		return
	}
	if *memmap.PtrUint32(0x5D4594, 1304352) == 0 {
		*memmap.PtrUint32(0x5D4594, 1304352) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DynamicLightning")))
		*memmap.PtrUint32(0x5D4594, 1304356) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DynamicChainLightning")))
		*memmap.PtrUint32(0x5D4594, 1304360) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DynamicEnergyBolt")))
		*memmap.PtrUint32(0x5D4594, 1304364) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("OrbRay")))
		*memmap.PtrUint32(0x5D4594, 1304368) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("PlasmaRay")))
		*memmap.PtrUint32(0x5D4594, 1304372) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DrainManaRay")))
		*memmap.PtrUint32(0x5D4594, 1304376) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("HealRay")))
		*memmap.PtrUint32(0x5D4594, 1304380) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CharmRay")))
		*memmap.PtrUint32(0x5D4594, 1304384) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DrainManaOrb")))
		*memmap.PtrUint32(0x5D4594, 1304388) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("HealOrb")))
		*memmap.PtrUint32(0x5D4594, 1304392) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CharmOrb")))
		*memmap.PtrUint32(0x5D4594, 1304396) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("HarpoonRope")))
	}
	v2 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(a1, 3))))
	v3 = v2
	v4 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(a1, 5))))
	v5 = v4
	v6 = (*uint32)(func() *client.Drawable {
		if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(a1, 3)))) != 0 {
			return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v3))
		}
		return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v3))
	}().C())
	v7 = v6
	result = (*uint32)(func() *client.Drawable {
		if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(a1, 5)))) != 0 {
			return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v5))
		}
		return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v5))
	}().C())
	if !(v7 != nil && result != nil) {
		return
	}
	v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*3)))
	v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*4)))
	v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4)) - uint32(v9))
	v11 = v8 + (int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3)))-v8)/2
	result = (*uint32)(unsafe.Pointer(uintptr(v9 + v10/2)))
	switch *(*uint8)(unsafe.Add(a1, 1)) {
	case 1:
		v12 = int32(*memmap.PtrUint32(0x5D4594, 1304368))
	case 2:
		v12 = int32(*memmap.PtrUint32(0x5D4594, 1304380))
	case 3:
		v12 = int32(*memmap.PtrUint32(0x5D4594, 1304356))
	case 4:
		v12 = int32(*memmap.PtrUint32(0x5D4594, 1304360))
	case 5:
		v12 = int32(*memmap.PtrUint32(0x5D4594, 1304372))
	case 6:
		v12 = int32(*memmap.PtrUint32(0x5D4594, 1304376))
	case 7:
		v12 = int32(*memmap.PtrUint32(0x5D4594, 1304396))
	case 0x8C:
		v12 = int32(*memmap.PtrUint32(0x5D4594, 1304352))
	default:
		return
	}
	result = (*uint32)(nox_xxx_spriteLoadAdd_45A360_drawable(v12, v11, v9+v10/2).C())
	if result == nil {
		return
	}
	*(*uint8)(unsafe.Add(unsafe.Pointer(result), 432)) = 1
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 437)) = uint32(*(*uint16)(unsafe.Add(a1, 3)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 441)) = uint32(*(*uint16)(unsafe.Add(a1, 5)))
	v13 = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 433)) = uint32(*(*uint8)(unsafe.Add(a1, 2)))
	v14 = (*uint8)(memmap.PtrOff(0x5D4594, 1303924))
	for *(*uint32)(unsafe.Pointer(v14)) != 0 {
		v14 = (*uint8)(unsafe.Add(unsafe.Pointer(v14), 4))
		v13++
		if int32(uintptr(unsafe.Pointer(v14))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1304308))) {
			return
		}
	}
	*memmap.PtrPtr(0x5D4594, uintptr(v13*4)+1303924) = unsafe.Pointer(result)
}
func nox_xxx_clientRemoveRayEffect_49C450(a1 unsafe.Pointer) {
	var (
		v1 int32
	)
	v1 = 0
	v2 := memmap.PtrPtr(0x5D4594, 1303924)
	for {
		result := *(*unsafe.Pointer)(v2)
		if *v2 != nil {
			if uint32(*(*uint16)(unsafe.Add(a1, 3))) == *(*uint32)(unsafe.Add(result, 437)) && uint32(*(*uint16)(unsafe.Add(a1, 5))) == *(*uint32)(unsafe.Add(result, 441)) {
				break
			}
		}
		v2 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*1))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1304308))) {
			return
		}
	}
	nox_xxx_spriteDeleteStatic_45A4E0_drawable((*client.Drawable)(unsafe.Pointer(uintptr(*v2))))
	*memmap.PtrUint32(0x5D4594, uintptr(v1*4)+1303924) = 0
}
func nox_xxx_spriteDeleteSomeList_49C4B0() {
	var (
		v0 int32
		v1 *int32
	)
	v0 = 0
	if *memmap.PtrUint32(0x5D4594, 1304308) > 0 {
		v1 = memmap.PtrInt32(0x5D4594, 1303540)
		for {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable((*client.Drawable)(unsafe.Pointer(uintptr(*v1))))
			v0++
			v1 = (*int32)(unsafe.Add(unsafe.Pointer(v1), 4*1))
			if v0 >= *memmap.PtrInt32(0x5D4594, 1304308) {
				break
			}
		}
	}
	*memmap.PtrUint32(0x5D4594, 1304308) = 0
	sub_4C5050()
}
func nox_xxx_sprite_49C4F0() {
	var v0 *int32 = memmap.PtrInt32(0x5D4594, 1303924)
	for {
		if *v0 != 0 {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable((*client.Drawable)(unsafe.Pointer(uintptr(*v0))))
			*v0 = 0
		}
		v0 = (*int32)(unsafe.Add(unsafe.Pointer(v0), 4*1))
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1304308))) {
			break
		}
	}
}
func sub_49C520(a1p *client.Drawable) int32 {
	var (
		a1 = a1p
		v1 *uint8
		v2 int32
		i  *uint8
	)
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1303924))
	for a1.C() != *(*unsafe.Pointer)(unsafe.Pointer(v1)) {
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 4))
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1304308))) {
			v2 = 0
			if *memmap.PtrInt32(0x5D4594, 1304308) <= 0 {
				return 0
			}
			for i = (*uint8)(memmap.PtrOff(0x5D4594, 1303540)); a1.C() != *(*unsafe.Pointer)(unsafe.Pointer(i)); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 4)) {
				if func() int32 {
					p := &v2
					*p++
					return *p
				}() >= *memmap.PtrInt32(0x5D4594, 1304308) {
					return 0
				}
			}
			return 1
		}
	}
	return 1
}
func nox_xxx_wnd_49C760(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var v3 int32
	if a2 != 16391 {
		return 1
	}
	v3 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	if v3 == 4103 {
		sub_49C7A0()
	}
	return 1
}
func sub_49C7A0() {
	if dword_5d4594_1305680 != nil {
		nox_server_sanctuaryHelp_54276 = (^nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1305680, 4104).DrawData().Field0 >> 2) & 1
		nox_xxx_wnd_46C6E0(dword_5d4594_1305680)
		nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1305680)
		nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1305680)
		dword_5d4594_1305680 = nil
		nox_xxx_windowFocus_46B500(nil)
		if noxflags.HasGame(1) {
			sub_459D80(0)
		}
	}
}
func sub_49C810() int32 {
	return bool2int32(dword_5d4594_1305680 != nil)
}
func sub_49CA60(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v5 int32
		v6 int32
	)
	if a2 != 16391 {
		return 1
	}
	v3 := nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	if v3 != 10353 {
		return 1
	}
	nox_xxx_wnd_46C6E0(dword_5d4594_1305684)
	nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1305684)
	if noxflags.HasGame(128) && nox_server_sanctuaryHelp_54276 != 0 {
		nox_xxx_cliShowHelpGui_49C560()
	} else {
		sub_459D80(0)
	}
	v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1305684, 10352)
	v5 = int32(nox_window_call_field_94_fnc(v4, 16404, 0, 0))
	nox_server_connectionType_3596 = uint32(v5 + 1)
	v6 = sub_40A710(v5 + 1)
	nox_xxx_rateUpdate_40A6D0(v6)
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1305684)
	dword_5d4594_1305684 = nil
	nox_xxx_windowFocus_46B500(nil)
	return 1
}
func sub_49CB40() int32 {
	return bool2int32(dword_5d4594_1305684 != nil)
}
func sub_49CD30(xLeft int32, yTop int32, a3 int32, a4 int32, a5 int32, a6 int32) {
	var rc image.Rectangle
	if a3 != 0 {
		if a4 != 0 {
			if !nox_draw_curDrawData_3799572.Clip() || (func() *int4 {
				rc = image.Rect(int(xLeft), int(yTop), int(xLeft+a3), int(yTop+a4))
				return nox_xxx_utilRect_49F930((*int4)(unsafe.Pointer(&rc)), (*int4)(unsafe.Pointer(&rc)), (*int4)(unsafe.Pointer(nox_draw_curDrawData_3799572.ClipRectPtr())))
			}()) != nil {
				nox_draw_set54RGB32_434040(a5)
				sub_434080(a6)
				nox_client_drawAddPoint_49F500(xLeft, yTop)
				nox_client_drawAddPoint_49F500(xLeft+a3-1, yTop)
				sub_49E4F0(64)
				nox_client_drawAddPoint_49F500(xLeft+a3, yTop)
				nox_client_drawAddPoint_49F500(xLeft+a3, yTop+a4-1)
				sub_49E4F0(64)
				nox_client_drawAddPoint_49F500(xLeft+a3, yTop+a4)
				nox_client_drawAddPoint_49F500(xLeft, yTop+a4)
				sub_49E4F0(64)
				nox_client_drawAddPoint_49F500(xLeft, yTop+a4-1)
				nox_client_drawAddPoint_49F500(xLeft, yTop+1)
				sub_49E4F0(64)
			}
		}
	}
}
func sub_49D1C0(a1 unsafe.Pointer, a2 int32, a3 int32) int32 {
	sub_49E3C0((*uint32)(a1), a2, uint32(a3))
	return 0
}
func sub_49E3C0(a1 *uint32, a2 int32, a3 uint32) {
	var (
		v3 *uint32
		v4 int32
	)
	if int32(a3) > 0 {
		v3 = a1
		v4 = int32(a3 >> 2)
		if a3>>2 != 0 {
			for {
				*v3 = uint32(a2)
				v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
				if func() int32 {
					p := &v4
					x := *p
					*p--
					return x
				}() <= 1 {
					break
				}
			}
		}
		if int32(a3&3) >= 2 {
			*(*uint16)(unsafe.Pointer(v3)) = uint16(int16(a2))
		}
	}
}
func sub_49F6D0(a1 int32) int32 {
	var result int32
	result = bool2int32(nox_draw_curDrawData_3799572.Clip())
	nox_draw_curDrawData_3799572.SetClip(a1 != 0)
	return result
}
func nox_client_copyRect_49F6F0(xLeft int32, yTop int32, a3 int32, a4 int32) {
	var (
		result *int4
		rcSrc  image.Rectangle
	)
	rc := image.Rect(int(xLeft), int(yTop), int(xLeft+a3), int(yTop+a4))
	result = nox_xxx_utilRect_49F930((*int4)(unsafe.Pointer(&rcSrc)), (*int4)(unsafe.Pointer(&rc)), (*int4)(unsafe.Pointer(nox_draw_curDrawData_3799572.Rect3Ptr())))
	if result != nil {
		nox_draw_curDrawData_3799572.SetClipRect(rcSrc)
		rcSrc.Max.X--
		rcSrc.Max.Y--
		nox_draw_curDrawData_3799572.SetClipRect2(rcSrc)
	}
}
func sub_49F780(xLeft int32, a2 int32) {
	var (
		v2 int32
		v3 int32
	)
	v2 = xLeft
	if xLeft < int32(nox_draw_curDrawData_3799572.ClipRect().Min.X) {
		v2 = int32(nox_draw_curDrawData_3799572.ClipRect().Min.X)
	}
	v3 = a2
	if a2 > int32(nox_draw_curDrawData_3799572.ClipRect().Max.X) {
		v3 = int32(nox_draw_curDrawData_3799572.ClipRect().Max.X)
	}
	nox_client_copyRect_49F6F0(v2, int32(nox_draw_curDrawData_3799572.ClipRect().Min.Y), v3-v2, int32(nox_draw_curDrawData_3799572.ClipRect().Max.Y-nox_draw_curDrawData_3799572.ClipRect().Min.Y))
}
func nox_xxx_wndDraw_49F7F0() {
	if dword_5d4594_1305748 == 0 {
		*memmap.PtrUint32(0x5D4594, 1305772) = uint32(bool2int32(nox_draw_curDrawData_3799572.Clip()))
		*memmap.PtrUint32(0x5D4594, 1305756) = uint32(nox_draw_curDrawData_3799572.ClipRect().Min.X)
		*memmap.PtrUint32(0x5D4594, 1305760) = uint32(nox_draw_curDrawData_3799572.ClipRect().Min.Y)
		*memmap.PtrUint32(0x5D4594, 1305764) = uint32(nox_draw_curDrawData_3799572.ClipRect().Max.X)
		*memmap.PtrUint32(0x5D4594, 1305768) = uint32(nox_draw_curDrawData_3799572.ClipRect().Max.Y)
		*memmap.PtrUint32(0x5D4594, 1305732) = uint32(nox_draw_curDrawData_3799572.ClipRect2().Min.X)
		*memmap.PtrUint32(0x5D4594, 1305736) = uint32(nox_draw_curDrawData_3799572.ClipRect2().Min.Y)
		*memmap.PtrUint32(0x5D4594, 1305740) = uint32(nox_draw_curDrawData_3799572.ClipRect2().Max.X)
		*memmap.PtrUint32(0x5D4594, 1305744) = uint32(nox_draw_curDrawData_3799572.ClipRect2().Max.Y)
		dword_5d4594_1305748 = 1
	}
}
func sub_49F860() int32 {
	var result int32
	result = int32(dword_5d4594_1305748)
	if dword_5d4594_1305748 == 0 {
		return result
	}
	nox_draw_curDrawData_3799572.SetClip(memmap.Uint32(0x5D4594, 1305772) != 0)
	v1 := nox_draw_curDrawData_3799572.ClipRectPtr()
	v1.Min.X = int(*memmap.PtrUint32(0x5D4594, 1305756))
	v1.Min.Y = int(*memmap.PtrUint32(0x5D4594, 1305760))
	v1.Max.X = int(*memmap.PtrUint32(0x5D4594, 1305764))
	v1.Max.Y = int(*memmap.PtrUint32(0x5D4594, 1305768))
	v2 := nox_draw_curDrawData_3799572.ClipRect2Ptr()
	v2.Min.X = int(*memmap.PtrUint32(0x5D4594, 1305732))
	v2.Min.Y = int(*memmap.PtrUint32(0x5D4594, 1305736))
	result = int32(*memmap.PtrUint32(0x5D4594, 1305740))
	v2.Max.X = int(*memmap.PtrUint32(0x5D4594, 1305740))
	v2.Max.Y = int(*memmap.PtrUint32(0x5D4594, 1305744))
	dword_5d4594_1305748 = 0
	return result
}
func nox_xxx_utilRect_49F930(a1 *int4, a2 *int4, a3 *int4) *int4 {
	var (
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		result *int4
	)
	v3 = a3.field_0
	if a2.field_0 >= a3.field_0 {
		v3 = a2.field_0
	}
	v4 = a3.field_8
	if a2.field_8 <= v4 {
		v4 = a2.field_8
	}
	if v3 >= v4 {
		return nil
	}
	v5 = a3.field_4
	if a2.field_4 >= v5 {
		v5 = a2.field_4
	}
	v6 = a3.field_C
	if a2.field_C <= v6 {
		v6 = a2.field_C
	}
	if v5 >= v6 {
		return nil
	}
	result = a1
	a1.field_0 = v3
	a1.field_4 = v5
	a1.field_8 = v4
	a1.field_C = v6
	return result
}
func sub_49FDB0(a1 int32) {
	var (
		v1 *uint8
		j  int32
		v3 int32
		v4 *uint8
		i  int32
		v6 int32
		v7 int32
		v8 [140]byte
	)
	if dword_5d4594_1305788 == 0 {
		if false {
			v7 = 0
			if *memmap.PtrUint32(0x587000, uintptr(a1*4)+166016) > 0 {
				v4 = (*uint8)(memmap.PtrOff(0x587000, uintptr(a1*80)+166032))
				for {
					for i = 0; i < int32(int8(*v4)); i++ {
						v6 = (a1*12 + int32(int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), i+1))))) * 8
						sub_420DA0(*memmap.PtrFloat32(0x587000, uintptr(v6)+165360), *memmap.PtrFloat32(0x587000, uintptr(v6)+165364))
					}
					libc.StrCpy(&v8[4], *(**byte)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*byte)(nil))*3)))
					sub_4211D0(unsafe.Pointer(&v8[0]))
					sub_4214D0()
					v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 16))
					v7++
					if v7 >= *memmap.PtrInt32(0x587000, uintptr(a1*4)+166016) {
						break
					}
				}
			}
		} else {
			v1 = (*uint8)(memmap.PtrOff(0x587000, 165744))
			for {
				for j = 0; j < int32(int8(*v1)); j++ {
					v3 = int32(int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), j+1)))) * 8
					sub_420DA0(*memmap.PtrFloat32(0x587000, uintptr(v3)+165104), *memmap.PtrFloat32(0x587000, uintptr(v3)+165108))
				}
				libc.StrCpy(&v8[4], *(**byte)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*byte)(nil))*3)))
				sub_4211D0(unsafe.Pointer(&v8[0]))
				sub_4214D0()
				v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 16))
				if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x587000, 166016))) {
					break
				}
			}
		}
		dword_5d4594_1305788 = 1
	}
}
func sub_49FF20() {
	if dword_5d4594_1305788 != 0 {
		sub_421B10()
		dword_5d4594_1305788 = 0
	}
}
func nox_client_getChatMap_49FF40(a1 *int16) *byte {
	var (
		v1     int32
		v2     *nox_player_polygon_check_data
		result *byte
		v4     Point32
	)
	v1 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(int16(0))*1))) + 10
	v4.X = int32(*a1) + 10
	v4.Y = v1
	v2 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v4, 0)
	if v2 != nil || (func() *nox_player_polygon_check_data {
		v2 = (*nox_player_polygon_check_data)(unsafe.Pointer(sub_421990(&v4, 100.0, 0)))
		return v2
	}()) != nil {
		result = (*byte)(unsafe.Pointer(&v2.field_0[1]))
	} else {
		result = *(**byte)(memmap.PtrOff(0x587000, 165756))
	}
	return result
}
func sub_49FFA0(a1 int32) *int32 {
	var (
		result *int32
		v2     *int32
		v3     *int32
	)
	if *memmap.PtrUint32(0x5D4594, 1305808) == 0 {
		nox_common_list_clear_425760(&nox_gui_wol_servers_list)
	}
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list)))
	v2 = result
	if result != nil {
		for {
			v3 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v2)))))
			nox_common_list_remove_425920(unsafe.Pointer(v2))
			if a1 != 0 {
				nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*7))))
			}
			alloc.Free(v2)
			v2 = v3
			if v3 == nil {
				break
			}
		}
		*memmap.PtrUint32(0x5D4594, 1305808) = 1
	} else {
		*memmap.PtrUint32(0x5D4594, 1305808) = 1
	}
	return result
}
func sub_4A0020() *byte {
	return (*byte)(unsafe.Pointer(&nox_gui_wol_servers_list))
}
func nox_wol_servers_addResult_4A0030(srv *nox_gui_server_ent_t) int32 {
	var (
		v3 *int32
		v6 *wchar2_t
		v7 *wchar2_t
		v8 *wchar2_t
		v9 *wchar2_t
	)
	rec, _ := alloc.New(nox_gui_server_ent_t{})
	alloc.Memcpy(unsafe.Pointer(rec), unsafe.Pointer(srv), unsafe.Sizeof(nox_gui_server_ent_t{}))
	var v2 int32 = 0
	switch nox_wol_servers_sorting_166704 {
	case 0:
		if nox_gui_wol_servers_list.field_1 == &nox_gui_wol_servers_list {
			return sub_425790((*int32)(unsafe.Pointer(&nox_gui_wol_servers_list)), &rec.field_0)
		}
		v3 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list)))
		if v3 == nil {
			nox_common_list_append_4258E0(&nox_gui_wol_servers_list, (*nox_list_item_t)(unsafe.Pointer(rec)))
			return 0
		}
		for {
			if nox_strcmpi(&rec.server_name[0], (*byte)(unsafe.Add(unsafe.Pointer(v3), 120))) <= 0 {
				nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(v3)), (*nox_list_item_t)(unsafe.Pointer(rec)))
				return v2
			}
			v2++
			v3 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v3)))))
			if v3 == nil {
				break
			}
		}
		nox_common_list_append_4258E0(&nox_gui_wol_servers_list, (*nox_list_item_t)(unsafe.Pointer(rec)))
		return v2
	case 1:
		if nox_gui_wol_servers_list.field_1 == &nox_gui_wol_servers_list {
			return sub_425790((*int32)(unsafe.Pointer(&nox_gui_wol_servers_list)), &rec.field_0)
		}
		v3 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list)))
		if v3 == nil {
			nox_common_list_append_4258E0(&nox_gui_wol_servers_list, (*nox_list_item_t)(unsafe.Pointer(rec)))
			return 0
		}
		for nox_strcmpi(&rec.server_name[0], (*byte)(unsafe.Add(unsafe.Pointer(v3), 120))) < 0 {
			v2++
			v3 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v3)))))
			if v3 == nil {
				nox_common_list_append_4258E0(&nox_gui_wol_servers_list, (*nox_list_item_t)(unsafe.Pointer(rec)))
				return v2
			}
		}
		nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(v3)), (*nox_list_item_t)(unsafe.Pointer(rec)))
		return v2
	case 2:
		rec.sort_key = int32(rec.players)
		return sub_425790((*int32)(unsafe.Pointer(&nox_gui_wol_servers_list)), &rec.field_0)
	case 3:
		rec.sort_key = 32 - int32(rec.players)
		return sub_425790((*int32)(unsafe.Pointer(&nox_gui_wol_servers_list)), &rec.field_0)
	case 4:
		if nox_gui_wol_servers_list.field_1 == &nox_gui_wol_servers_list {
			return sub_425790((*int32)(unsafe.Pointer(&nox_gui_wol_servers_list)), &rec.field_0)
		}
		v6 = nox_gui_wol_gameModeString_43BCB0(int16(rec.flags))
		v3 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list)))
		if v3 == nil {
			nox_common_list_append_4258E0(&nox_gui_wol_servers_list, (*nox_list_item_t)(unsafe.Pointer(rec)))
			return 0
		}
		for {
			v7 = nox_gui_wol_gameModeString_43BCB0(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v3), 163))))
			if nox_wcscmp(v6, v7) <= 0 {
				nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(v3)), (*nox_list_item_t)(unsafe.Pointer(rec)))
				return v2
			}
			v2++
			v3 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v3)))))
			if v3 == nil {
				nox_common_list_append_4258E0(&nox_gui_wol_servers_list, (*nox_list_item_t)(unsafe.Pointer(rec)))
				return v2
			}
		}
		fallthrough
	case 5:
		if nox_gui_wol_servers_list.field_1 == &nox_gui_wol_servers_list {
			return sub_425790((*int32)(unsafe.Pointer(&nox_gui_wol_servers_list)), &rec.field_0)
		}
		v8 = nox_gui_wol_gameModeString_43BCB0(int16(rec.flags))
		v3 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list)))
		if v3 == nil {
			nox_common_list_append_4258E0(&nox_gui_wol_servers_list, (*nox_list_item_t)(unsafe.Pointer(rec)))
			return 0
		}
		for {
			v9 = nox_gui_wol_gameModeString_43BCB0(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v3), 163))))
			if nox_wcscmp(v8, v9) >= 0 {
				break
			}
			v2++
			v3 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v3)))))
			if v3 == nil {
				nox_common_list_append_4258E0(&nox_gui_wol_servers_list, (*nox_list_item_t)(unsafe.Pointer(rec)))
				return v2
			}
		}
		nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(v3)), (*nox_list_item_t)(unsafe.Pointer(rec)))
		return v2
	case 6:
		rec.sort_key = rec.ping
		return sub_425790((*int32)(unsafe.Pointer(&nox_gui_wol_servers_list)), &rec.field_0)
	case 7:
		rec.sort_key = 1000 - rec.ping
		return sub_425790((*int32)(unsafe.Pointer(&nox_gui_wol_servers_list)), &rec.field_0)
	case 8:
		rec.sort_key = int32(rec.status) & 0x30
		return sub_425790((*int32)(unsafe.Pointer(&nox_gui_wol_servers_list)), &rec.field_0)
	case 9:
		rec.sort_key = 48 - (int32(rec.status) & 0x30)
		return sub_425790((*int32)(unsafe.Pointer(&nox_gui_wol_servers_list)), &rec.field_0)
	default:
		return 0
	}
}
func nox_wol_servers_sortBtnHandler_4A0290(id int32) {
	switch id - 10047 {
	case 0:
		nox_wol_servers_sorting_166704 = uint32(bool2int32(nox_wol_servers_sorting_166704 == 0) + 0)
	case 1:
		nox_wol_servers_sorting_166704 = uint32(bool2int32(nox_wol_servers_sorting_166704 == 2) + 2)
	case 2:
		nox_wol_servers_sorting_166704 = uint32(bool2int32(nox_wol_servers_sorting_166704 == 4) + 4)
	case 3:
		nox_wol_servers_sorting_166704 = uint32(bool2int32(nox_wol_servers_sorting_166704 == 6) + 6)
	case 4:
		nox_wol_servers_sorting_166704 = uint32(bool2int32(nox_wol_servers_sorting_166704 == 8) + 8)
	}
}
func sub_4A0360() *int32 {
	var (
		result *int32
		i      *int32
	)
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list)))
	for i = result; result != nil; i = result {
		nox_gui_wol_newServerLine_43B7C0((*nox_gui_server_ent_t)(unsafe.Pointer(i)))
		result = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(i)))))
	}
	return result
}
func sub_4A0390() *int32 {
	var (
		v0 *uint32
		v1 *int32
		v2 *int32
		v5 *uint32
	)
	v4, free4 := alloc.Make([]int32{}, unsafe.Sizeof(nox_list_item_t{}))
	defer free4()
	nox_common_list_clear_425760((*nox_list_item_t)(unsafe.Pointer(&v4[0])))
	v0 = (*uint32)(unsafe.Pointer(nox_gui_wol_servers_list.field_1))
	v4[0] = int32(uintptr(unsafe.Pointer(nox_gui_wol_servers_list.field_0)))
	v5 = (*uint32)(unsafe.Pointer(nox_gui_wol_servers_list.field_1))
	if nox_gui_wol_servers_list.field_0 != nil {
		// FIXME: this is suspicious, why it's recording local variable to this list?
		nox_gui_wol_servers_list.field_0.field_1 = (*nox_list_item_t)(unsafe.Pointer(&v4[0]))
		v0 = v5
	}
	if v0 != nil {
		*(*unsafe.Pointer)(unsafe.Pointer(v0)) = unsafe.Pointer(&v4[0])
	}
	nox_common_list_clear_425760(&nox_gui_wol_servers_list)
	v1 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(&v4[0])))))
	if v1 == nil {
		return sub_4A0360()
	}
	for {
		v2 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v1)))))
		nox_wol_servers_addResult_4A0030((*nox_gui_server_ent_t)(unsafe.Pointer(v1)))
		v1 = v2
		if v2 == nil {
			break
		}
	}
	return sub_4A0360()
}
func sub_4A0410(a1 *byte, a2 int16) int32 {
	var v2 *int32
	v2 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list)))
	if v2 == nil {
		return 1
	}
	for libc.StrCmp(a1, (*byte)(unsafe.Add(unsafe.Pointer(v2), 12))) != 0 || int32(a2) != int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), 109))) {
		v2 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v2)))))
		if v2 == nil {
			return 1
		}
	}
	return 0
}
func sub_4A0490(a1 int32) *int32 {
	var result *int32
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list)))
	if result == nil {
		return nil
	}
	for *(*int32)(unsafe.Add(unsafe.Pointer(result), 4*9)) != a1 {
		result = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(result)))))
		if result == nil {
			return nil
		}
	}
	return result
}
func sub_4A04C0(a1 int32) *int32 {
	var (
		v1     int32
		result *int32
	)
	v1 = 0
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list)))
	if result == nil {
		return nil
	}
	for a1 != v1 {
		v1++
		result = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(result)))))
		if result == nil {
			return nil
		}
	}
	return result
}
