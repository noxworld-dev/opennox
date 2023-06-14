package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_memfile_read_i8(f *binfile.MemFile) int8 {
	return f.ReadI8()
}
func nox_memfile_read_u8(f *binfile.MemFile) uint8 {
	return f.ReadU8()
}
func nox_memfile_read_i16(f *binfile.MemFile) int16 {
	return f.ReadI16()
}
func nox_memfile_read_u16(f *binfile.MemFile) uint16 {
	return f.ReadU16()
}
func nox_memfile_read_i32(f *binfile.MemFile) int32 {
	return f.ReadI32()
}
func nox_memfile_read_u32(f *binfile.MemFile) uint32 {
	return f.ReadU32()
}
func nox_memfile_skip(f *binfile.MemFile, n int32) {
	f.Skip(int(n))
}
func nox_memfile_read(dst unsafe.Pointer, sz uint32, cnt int32, f *binfile.MemFile) uint32 {
	n, _ := f.Read(unsafe.Slice((*byte)(dst), sz*uint32(cnt)))
	return uint32(n) / sz
}
func nox_memfile_read64align_40AD60(dest *byte, sz int32, cnt int32, f *binfile.MemFile) uint32 {
	var (
		cur_offset uint32 = uint32(int32(uintptr(f.Cur) - uintptr(f.DataPtr)))
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
	alloc.Memcpy(unsafe.Pointer(dest), unsafe.Pointer(&buf[0]), uintptr(cnt*sz))
	return 1
}
