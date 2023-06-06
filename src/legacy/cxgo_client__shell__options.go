package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_4AA650() {
	var (
		v2 *byte
		v3 unsafe.Pointer
	)
	if sub_44D930() == 0 {
		v2 = *(**byte)(memmap.PtrOff(0x587000, uintptr(func() uint32 {
			p := mem_getU32Ptr(0x5D4594, 1309744)
			x := *p
			*p++
			return x
		}())*4+172892))
		nox_strman_loadString_40F1D0(v2, (**byte)(unsafe.Pointer(&v3)), internCStr("C:\\NoxPost\\src\\client\\shell\\Options.c"), 131)
		*memmap.PtrUint32(0x5D4594, 1309744) %= 3
		if v3 != nil {
			nox_xxx_playDialogFile_44D900((*byte)(v3), 100)
		}
	}
}
