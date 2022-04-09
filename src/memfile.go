package opennox

/*
#include "memfile.h"
*/
import "C"
import (
	"encoding/binary"
	"io"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

func loadMemfile(path string, key int) (*MemFile, error) {
	f, err := BinfileOpen(path, BinFileRO)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	if err = f.SetKey(key); err != nil {
		return nil, err
	}
	f.FileSeek(0, io.SeekEnd)
	sz := f.Written()
	f.FileSeek(0, io.SeekStart)
	data, _ := alloc.Make([]byte{}, sz)
	_, err = io.ReadFull(f, data)
	if err != nil {
		return nil, err
	}
	return newMemfile(unsafe.Pointer(&data[0]), int(sz)), nil
}

func newMemfile(data unsafe.Pointer, sz int) *MemFile {
	nf, _ := alloc.New(MemFile{})
	nf.size = C.int(sz)
	nf.data = (*C.char)(data)
	nf.cur = nf.data
	nf.end = (*C.char)(unsafe.Add(data, sz))
	return nf
}

func asMemfile(p *C.nox_memfile) *MemFile {
	return asMemfileP(unsafe.Pointer(p))
}

func asMemfileP(p unsafe.Pointer) *MemFile {
	return (*MemFile)(p)
}

type MemFile C.nox_memfile

func (f *MemFile) C() *C.nox_memfile {
	return (*C.nox_memfile)(unsafe.Pointer(f))
}

func (f *MemFile) Free() {
	if f.data != nil {
		alloc.Free(unsafe.Pointer(f.data))
	}
	f.data = nil
	f.cur = nil
	f.end = nil
	f.size = 0
	alloc.Free(unsafe.Pointer(f.C()))
}

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

func (f *MemFile) Seek(offset int64, whence int) (int64, error) {
	switch whence {
	case io.SeekStart:
		// nop
	case io.SeekCurrent:
		sp, ep := uintptr(unsafe.Pointer(f.data)), uintptr(unsafe.Pointer(f.cur))
		offset += int64(ep - sp)
	case io.SeekEnd:
		offset = int64(f.size) + offset
	default:
		panic(whence)
	}
	if offset < 0 {
		f.cur = f.data
		return 0, nil
	} else if offset >= int64(f.size) {
		f.cur = f.end
		return int64(f.size), nil
	}
	f.cur = (*C.char)(unsafe.Add(unsafe.Pointer(f.data), int(offset)))
	return offset, nil
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

func (f *MemFile) SkipString8() {
	n := f.ReadU8()
	f.Skip(int(n))
}

func (f *MemFile) ReadString8() (string, error) {
	n := f.ReadU8()
	buf := make([]byte, n)
	_, err := io.ReadFull(f, buf)
	if err != nil {
		return "", err
	}
	return string(buf), nil
}
