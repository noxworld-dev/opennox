package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func sub_42EBB0(a1 uint32, fnc unsafe.Pointer, field_4 int32, name *byte) {
	if a1 == 1 {
		arr := alloc.ReallocT(ptr_5D4594_754088, ptr_5D4594_754088_cnt+1)
		ptr_5D4594_754088 = arr
		if arr == nil {
			panic("abort")
		}
		p := &ptr_5D4594_754088[ptr_5D4594_754088_cnt]
		p.Fnc = fnc
		p.Field_4 = field_4
		libc.StrCpy(&p.Name[0], name)
		ptr_5D4594_754088_cnt++
	} else if a1 == 2 {
		arr := alloc.ReallocT(ptr_5D4594_754092, ptr_5D4594_754092_cnt+1)
		ptr_5D4594_754092 = arr
		if arr == nil {
			panic("abort")
		}
		p := &ptr_5D4594_754092[ptr_5D4594_754092_cnt]
		p.Fnc = fnc
		p.Field_4 = field_4
		var sz int32 = int32(libc.StrLen(name) + 1)
		alloc.Memcpy(unsafe.Pointer(&p.Name[0]), unsafe.Pointer(name), uintptr(sz))
		ptr_5D4594_754092_cnt++
	}
}
