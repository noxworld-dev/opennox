package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"unsafe"
)

func sub_42EBB0(a1 uint32, fnc func(int32), field_4 int32, name *byte) {
	var v6 *wchar2_t
	_ = v6
	var v8 *wchar2_t
	_ = v8
	if a1 == 1 {
		var arr *obj_5D4594_754088_t = (*obj_5D4594_754088_t)(libc.Realloc(unsafe.Pointer(ptr_5D4594_754088), int((ptr_5D4594_754088_cnt+1)*int32(unsafe.Sizeof(obj_5D4594_754088_t{})))))
		ptr_5D4594_754088 = arr
		if arr == nil {
			panic("abort")
		}
		(*(*obj_5D4594_754088_t)(unsafe.Add(unsafe.Pointer(arr), unsafe.Sizeof(obj_5D4594_754088_t{})*uintptr(ptr_5D4594_754088_cnt)))).fnc = fnc
		(*(*obj_5D4594_754088_t)(unsafe.Add(unsafe.Pointer(arr), unsafe.Sizeof(obj_5D4594_754088_t{})*uintptr(ptr_5D4594_754088_cnt)))).field_4 = field_4
		libc.StrCpy(&(*(*obj_5D4594_754088_t)(unsafe.Add(unsafe.Pointer(arr), unsafe.Sizeof(obj_5D4594_754088_t{})*uintptr(ptr_5D4594_754088_cnt)))).name[0], name)
		ptr_5D4594_754088_cnt++
	} else if a1 == 2 {
		var arr *obj_5D4594_754088_t = (*obj_5D4594_754088_t)(libc.Realloc(unsafe.Pointer(ptr_5D4594_754092), int((ptr_5D4594_754092_cnt+1)*int32(unsafe.Sizeof(obj_5D4594_754088_t{})))))
		ptr_5D4594_754092 = arr
		if arr == nil {
			panic("abort")
		}
		(*(*obj_5D4594_754088_t)(unsafe.Add(unsafe.Pointer(arr), unsafe.Sizeof(obj_5D4594_754088_t{})*uintptr(ptr_5D4594_754092_cnt)))).fnc = fnc
		(*(*obj_5D4594_754088_t)(unsafe.Add(unsafe.Pointer(arr), unsafe.Sizeof(obj_5D4594_754088_t{})*uintptr(ptr_5D4594_754092_cnt)))).field_4 = field_4
		var sz int32 = int32(libc.StrLen(name) + 1)
		alloc.Memcpy(unsafe.Pointer(&(*(*obj_5D4594_754088_t)(unsafe.Add(unsafe.Pointer(arr), unsafe.Sizeof(obj_5D4594_754088_t{})*uintptr(ptr_5D4594_754092_cnt)))).name[0]), unsafe.Pointer(name), int(sz))
		ptr_5D4594_754092_cnt++
	}
}
