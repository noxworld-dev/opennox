package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_WorkerHurt_44D810() int32 {
	var v1 int32
	if dword_5d4594_831076 != 0 {
		return 1
	}
	dword_5d4594_831092 = uint32(sub_43F130())
	dword_587000_122848 = uint32(bool2int32(dword_5d4594_831092 != 0))
	sub_4864A0((*uint32)(memmap.PtrOff(0x5D4594, 830876)))
	sub_486380((*uint32)(memmap.PtrOff(0x5D4594, 830876)), 0x1F4, 0, 0x4000)
	dword_5d4594_830864 = 0
	dword_5d4594_830972 = nil
	dword_5d4594_830872 = nil
	*memmap.PtrUint32(0x5D4594, 831080) = 0
	dword_5d4594_831084 = 0
	dword_5d4594_831076 = 1
	nox_strman_loadString_40F1D0(internCStr("Con03B.scr:WorkerHurt"), (**byte)(unsafe.Pointer(&v1)), internCStr("C:\\NoxPost\\src\\client\\Audio\\AudDiag.c"), 279)
	if v1 != 0 {
		nox_xxx_playDialogFile_44D900((*byte)(v1), 0)
	}
	return 1
}
