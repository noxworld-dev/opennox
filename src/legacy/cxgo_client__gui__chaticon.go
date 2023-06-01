package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func nox_xxx_guiChatIconLoad_445650() int32 {
	var v0 *uint16
	*memmap.PtrUint32(0x5D4594, 825748) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("ChatIcon")))))
	dword_5d4594_825744 = uint32(uintptr(unsafe.Pointer(nox_window_new(nil, 136, int(nox_win_width)-50, int(nox_win_height)/2-50, 50, 50, nil))))
	nox_xxx_wndSetIcon_46AE60(*(*int32)(unsafe.Pointer(&dword_5d4594_825744)), *memmap.PtrInt32(0x5D4594, 825748))
	nox_window_set_all_funcs((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_825744)))), nil, ccall.FuncAddr(nox_xxx_guiChatMode_4456E0), nil)
	v0 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("chatmode"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\chaticon.c"), 73)))
	nox_xxx_wndWddSetTooltip_46B000((*nox_window_data)(unsafe.Pointer(uintptr(dword_5d4594_825744+36))), (*wchar2_t)(unsafe.Pointer(v0)))
	return 1
}
