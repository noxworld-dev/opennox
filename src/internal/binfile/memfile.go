package binfile

import (
	"encoding/binary"
	"io"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func LoadMemFile(path string, key int) (*MemFile, error) {
	f, err := BinfileOpen(path, ReadOnly)
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
	return NewMemFile(unsafe.Pointer(&data[0]), int(sz)), nil
}

func NewMemFile(data unsafe.Pointer, sz int) *MemFile {
	nf, _ := alloc.New(MemFile{})
	nf.Size = int32(sz)
	nf.DataPtr = data
	nf.Cur = nf.DataPtr
	nf.End = unsafe.Add(data, sz)
	return nf
}

type MemFile struct {
	DataPtr unsafe.Pointer
	Size    int32
	Cur     unsafe.Pointer
	End     unsafe.Pointer
}

func (f *MemFile) C() unsafe.Pointer {
	return unsafe.Pointer(f)
}

func (f *MemFile) Free() {
	if f.DataPtr != nil {
		alloc.FreePtr(f.DataPtr)
	}
	f.DataPtr = nil
	f.Cur = nil
	f.End = nil
	f.Size = 0
	alloc.FreePtr(f.C())
}

func (f *MemFile) RawData() []byte {
	if f.DataPtr == nil {
		return nil
	}
	return unsafe.Slice((*byte)(f.DataPtr), int(f.Size))
}

func (f *MemFile) Data() []byte {
	if f.DataPtr == nil {
		return nil
	}
	sp, ep := uintptr(f.Cur), uintptr(f.End)
	if sp == 0 || ep == 0 || sp >= ep {
		return nil
	}
	return unsafe.Slice((*byte)(f.Cur), int(ep-sp))
}

func (f *MemFile) offset() int {
	sp, ep := uintptr(f.DataPtr), uintptr(f.Cur)
	return int(ep - sp)
}

func (f *MemFile) Seek(offset int64, whence int) (int64, error) {
	switch whence {
	case io.SeekStart:
		// nop
	case io.SeekCurrent:
		offset += int64(f.offset())
	case io.SeekEnd:
		offset = int64(f.Size) + offset
	default:
		panic(whence)
	}
	if offset < 0 {
		f.Cur = f.DataPtr
		return 0, nil
	} else if offset >= int64(f.Size) {
		f.Cur = f.End
		return int64(f.Size), nil
	}
	f.Cur = unsafe.Add(f.DataPtr, int(offset))
	return offset, nil
}

func (f *MemFile) Skip(n int) {
	if f.DataPtr == nil {
		return
	}
	sp, ep := f.Cur, f.End
	if sp == nil || ep == nil {
		return
	}
	if uintptr(sp)+uintptr(n) >= uintptr(ep) {
		f.Cur = f.End
	} else {
		f.Cur = unsafe.Add(sp, n)
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

func (f *MemFile) ReadU64() uint64 {
	var buf [8]byte
	_, _ = f.Read(buf[:])
	return binary.LittleEndian.Uint64(buf[:])
}

func (f *MemFile) ReadI64() int64 {
	return int64(f.ReadU64())
}

func (f *MemFile) SkipString8() {
	n := f.ReadU8()
	f.Skip(int(n))
}

func (f *MemFile) ReadBytes8() ([]byte, error) {
	n := f.ReadU8()
	buf := make([]byte, n)
	_, err := io.ReadFull(f, buf)
	if err != nil {
		return nil, err
	}
	return buf, nil
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

func (f *MemFile) ReadString16() (string, error) {
	n := f.ReadU16()
	buf := make([]byte, n)
	_, err := io.ReadFull(f, buf)
	if err != nil {
		return "", err
	}
	return string(buf), nil
}

func (f *MemFile) ReadU64Align() uint64 {
	off := f.offset()
	if over := off % 8; over != 0 {
		f.Skip(8 - over)
	}
	return f.ReadU64()
}
