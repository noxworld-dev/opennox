package nox

/*
#include "memfile.h"
*/
import "C"
import (
	"encoding/binary"
	"io"
	"unsafe"
)

func asMemfile(p *C.nox_memfile) *MemFile {
	return (*MemFile)(unsafe.Pointer(p))
}

type MemFile C.nox_memfile

func (f *MemFile) RawData() []byte {
	if f.data == nil {
		return nil
	}
	return unsafe.Slice((*byte)(unsafe.Pointer(f.data)), int(f.size))
}

func (f *MemFile) Data() []byte {
	if f.data == nil {
		return nil
	}
	sp, ep := uintptr(unsafe.Pointer(f.cur)), uintptr(unsafe.Pointer(f.end))
	if sp == 0 || ep == 0 || sp >= ep {
		return nil
	}
	return unsafe.Slice((*byte)(unsafe.Pointer(f.cur)), int(ep-sp))
}

func (f *MemFile) Skip(n int) {
	if f.data == nil {
		return
	}
	sp, ep := unsafe.Pointer(f.cur), unsafe.Pointer(f.end)
	if sp == nil || ep == nil {
		return
	}
	if uintptr(sp)+uintptr(n) >= uintptr(ep) {
		f.cur = f.end
	} else {
		f.cur = (*C.char)(unsafe.Add(sp, n))
	}
}

func (f *MemFile) Read(p []byte) (int, error) {
	data := f.Data()
	n := copy(p, data)
	if n == 0 {
		return 0, io.EOF
	}
	f.Skip(n)
	return n, nil
}

func (f *MemFile) ReadU8() byte {
	data := f.Data()
	if len(data) == 0 {
		return 0
	}
	v := data[0]
	f.Skip(1)
	return v
}

func (f *MemFile) ReadI8() int8 {
	return int8(f.ReadU8())
}

func (f *MemFile) ReadU16() uint16 {
	var buf [2]byte
	_, _ = f.Read(buf[:])
	return binary.LittleEndian.Uint16(buf[:])
}

func (f *MemFile) ReadI16() int16 {
	return int16(f.ReadU16())
}

func (f *MemFile) ReadU32() uint32 {
	var buf [4]byte
	_, _ = f.Read(buf[:])
	return binary.LittleEndian.Uint32(buf[:])
}

func (f *MemFile) ReadI32() int32 {
	return int32(f.ReadU32())
}
