package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"unsafe"
)

func nox_xxx_printCentered_445490(a1 *wchar2_t) {
	var (
		v1 int32
		v2 int32
		v3 *uint16
	)
	if a1 != nil {
		v1 = int32(func() uint32 {
			p := &dword_5d4594_825736
			*p++
			return *p
		}())
		if dword_5d4594_825736 == 3 {
			v1 = 0
			dword_5d4594_825736 = 0
		}
		nox_wcscpy((*wchar2_t)(unsafe.Pointer(mem_getU16Ptr(0x5D4594, uint32(v1*644)+823804))), a1)
		v2 = int32(dword_5d4594_825736 * 644)
		*memmap.PtrUint32(0x5D4594, uint32(v2)+824440) = gameFrame() + gameFPS()*4 + gameFPS()
		*memmap.PtrUint8(0x5D4594, uint32(v2)+824444) = 0
		v3 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("systemmsg"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimsg.c"), 69)))
		nox_gui_console_Printf_450C00(uint8(int8(NOX_CONSOLE_RED)), (*wchar2_t)(unsafe.Pointer(v3)), a1)
	}
}
