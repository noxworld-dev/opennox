package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"unsafe"
)

type nox_memfile struct {
	data *byte
	size int32
	cur  *byte
	end  *byte
}

func nox_memfile_read_i8(f *nox_memfile) int8 {
	if f.data == nil {
		return 0
	}
	var v int8 = *(*int8)(unsafe.Pointer(f.cur))
	f.cur = (*byte)(unsafe.Add(unsafe.Pointer(f.cur), 1))
	return v
}
func nox_memfile_read_u8(f *nox_memfile) uint8 {
	if f.data == nil {
		return 0
	}
	var v uint8 = *(*uint8)(unsafe.Pointer(f.cur))
	f.cur = (*byte)(unsafe.Add(unsafe.Pointer(f.cur), 1))
	return v
}
func nox_memfile_read_i16(f *nox_memfile) int16 {
	if f.data == nil {
		return 0
	}
	var v int16 = *(*int16)(unsafe.Pointer(f.cur))
	f.cur = (*byte)(unsafe.Add(unsafe.Pointer(f.cur), 2))
	return v
}
func nox_memfile_read_u16(f *nox_memfile) uint16 {
	if f.data == nil {
		return 0
	}
	var v uint16 = *(*uint16)(unsafe.Pointer(f.cur))
	f.cur = (*byte)(unsafe.Add(unsafe.Pointer(f.cur), 2))
	return v
}
func nox_memfile_read_i32(f *nox_memfile) int32 {
	if f.data == nil {
		return 0
	}
	var v int32 = *(*int32)(unsafe.Pointer(f.cur))
	f.cur = (*byte)(unsafe.Add(unsafe.Pointer(f.cur), 4))
	return v
}
func nox_memfile_read_u32(f *nox_memfile) uint32 {
	if f.data == nil {
		return 0
	}
	var v uint32 = *(*uint32)(unsafe.Pointer(f.cur))
	f.cur = (*byte)(unsafe.Add(unsafe.Pointer(f.cur), 4))
	return v
}
func nox_memfile_skip(f *nox_memfile, n int32) {
	if f.data == nil {
		return
	}
	f.cur = (*byte)(unsafe.Add(unsafe.Pointer(f.cur), n))
}
func nox_memfile_read(dst unsafe.Pointer, sz uint32, cnt int32, f *nox_memfile) uint32 {
	var n uint32 = uint32(cnt) * sz
	if uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(f.cur), n)))) > uintptr(unsafe.Pointer(f.end)) {
		n = uint32(int32(uintptr(unsafe.Pointer(f.end)) - uintptr(unsafe.Pointer(f.cur))))
	}
	alloc.Memcpy(dst, unsafe.Pointer(f.cur), int(n))
	f.cur = (*byte)(unsafe.Add(unsafe.Pointer(f.cur), n))
	return n / sz
}
func nox_memfile_read64align_40AD60(dest *byte, sz int32, cnt int32, f *nox_memfile) uint32 {
	var (
		cur_offset uint32 = uint32(int32(uintptr(unsafe.Pointer(f.cur)) - uintptr(unsafe.Pointer(f.data))))
		over       uint8  = uint8(cur_offset % 8)
		buf        [8]byte
	)
	if int32(over) != 0 {
		nox_memfile_read(unsafe.Pointer(&buf[0]), uint32(8-int32(over)), 1, f)
	}
	var result uint32 = nox_memfile_read(unsafe.Pointer(&buf[0]), 8, 1, f)
	if result != 1 {
		return result
	}
	alloc.Memcpy(unsafe.Pointer(dest), unsafe.Pointer(&buf[0]), int(cnt*sz))
	return 1
}
