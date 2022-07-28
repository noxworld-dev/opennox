package memmap

import (
	"bytes"
	"fmt"
	"sort"
	"strconv"
	"sync/atomic"
	"unsafe"
)

const ptrSize = unsafe.Sizeof(unsafe.Pointer(nil))

type Variable struct {
	Addr uintptr
	Ptr  unsafe.Pointer // optional
	Size uintptr
	Name string
}

// Contains checks if a variable contains an address.
func (v *Variable) Contains(addr uintptr) bool {
	if addr < v.Addr {
		return false
	} else if addr == v.Addr {
		return true
	}
	off := addr - v.Addr
	return off < v.Size
}

// Blob returns a blob associated with this variable, if any.
func (v *Variable) Blob() *Blob {
	return BlobByAddr(v.Addr)
}

type Blob struct {
	Addr    uintptr
	Size    uintptr // if Data is not set
	Data    []byte
	Initial []byte
	Name    string
}

// Contains checks if a blob contains an address.
func (b *Blob) Contains(addr uintptr) bool {
	if addr < b.Addr {
		return false
	} else if addr == b.Addr {
		return true
	}
	off := addr - b.Addr
	return off < b.Size
}

// ContainsPtr checks if a blob contains a pointer.
func (b *Blob) ContainsPtr(ptr unsafe.Pointer) (uintptr, bool) {
	if len(b.Data) == 0 {
		return 0, false
	}
	blob := unsafe.Pointer(&b.Data[0])
	if uintptr(ptr) < uintptr(blob) {
		return 0, false
	}
	off := uintptr(ptr) - uintptr(blob)
	if off >= uintptr(len(b.Data)) {
		return 0, false
	}
	return off, true
}

var (
	blobs      []*Blob
	variables  []Variable
	varsSorted bool
)

func sortVars() {
	if varsSorted {
		return
	}
	sort.Slice(variables, func(i, j int) bool {
		return variables[i].Addr < variables[j].Addr
	})
	varsSorted = true
}

// RegisterBlob registers a blob with a given address in original Nox binary and specified name and size.
func RegisterBlob(addr uintptr, name string, size uintptr) {
	b := &Blob{
		Addr: addr,
		Name: name,
		Size: size,
	}
	for _, b2 := range blobs {
		if b.Addr == b2.Addr {
			return // duplicate
		}
	}
	blobs = append(blobs, b)
	sort.Slice(blobs, func(i, j int) bool {
		return blobs[i].Addr < blobs[j].Addr
	})
}

// RegisterBlobData registers a raw blob with a given address in original Nox binary and specified name and data.
func RegisterBlobData(addr uintptr, name string, data []byte) {
	b := &Blob{
		Addr:    addr,
		Name:    name,
		Size:    uintptr(len(data)),
		Data:    data,
		Initial: make([]byte, len(data)),
	}
	copy(b.Initial, data)
	for i, b2 := range blobs {
		if b.Addr == b2.Addr {
			blobs[i] = b
			return
		}
	}
	blobs = append(blobs, b)
	sort.Slice(blobs, func(i, j int) bool {
		return blobs[i].Addr < blobs[j].Addr
	})
}

// BlobByAddr find a blob containing an address. Returns nil if there's no such blob.
func BlobByAddr(addr uintptr) *Blob {
	for _, b := range blobs {
		if b.Contains(addr) {
			return b
		}
	}
	return nil
}

// BlobByPtr find a blob containing a pointer. Returns nil if there's no such blob.
func BlobByPtr(ptr unsafe.Pointer) (*Blob, uintptr) {
	for _, b := range blobs {
		if off, ok := b.ContainsPtr(ptr); ok {
			return b, off
		}
	}
	return nil, 0
}

// Blobs returns a sorted list of blobs.
func Blobs() []Blob {
	out := make([]Blob, 0, len(blobs))
	for _, b := range blobs {
		out = append(out, *b)
	}
	return out
}

// RegisterVariable registers an extracted variable with a given address in original Nox binary,
// specified size and name. Optionally, a pointer to the variable can be provided.
func RegisterVariable(addr, size uintptr, name string, ptr unsafe.Pointer) {
	variables = append(variables, Variable{
		Addr: addr,
		Ptr:  ptr,
		Size: size,
		Name: name,
	})
	varsSorted = false
}

// VariableByAddr find a variable containing an address. Returns nil if there's no such variables.
func VariableByAddr(addr uintptr) *Variable {
	sortVars()
	i := sort.Search(len(variables), func(i int) bool {
		v := &variables[i]
		return addr < v.Addr
	})
	i--
	if i < 0 {
		return nil
	}
	v := variables[i]
	if !v.Contains(addr) {
		return nil
	}
	return &v
}

// RegisterVariableOff is similar to RegisterVariable but specifies variable location in the binary relative to
// the blob address in the Nox binary.
func RegisterVariableOff(blob, off, size uintptr, name string, ptr unsafe.Pointer) {
	RegisterVariable(blob+off, size, name, ptr)
}

// Variables returns a sorted list of variables.
func Variables() []Variable {
	sortVars()
	return append([]Variable{}, variables...)
}

// Ptr returns an unsafe pointer to the blob at a given address.
func Ptr(addr uintptr) unsafe.Pointer {
	if len(blobs) == 0 {
		panic("no blobs defined")
	}
	if atomic.LoadUint32(&runtimeCheck) != 0 {
		checkAddr(addr)
	}
	if b := BlobByAddr(addr); b != nil {
		off := addr - b.Addr
		return unsafe.Pointer(&b.Data[off])
	}
	panic("no blobs matching the address: 0x" + strconv.FormatUint(uint64(addr), 16))
}

// RelativeAddr splits the address in the original binary into a blob address and an offset in it.
// It returns addr and 0 offset if the address is not inside of any of the blobs.
func RelativeAddr(addr uintptr) (blob, off uintptr) {
	if b := BlobByAddr(addr); b != nil {
		return b.Addr, addr - b.Addr
	}
	return addr, 0
}

// PtrOff returns an unsafe pointer to the specified blob at a given offset.
func PtrOff(blob, off uintptr) unsafe.Pointer {
	sl := Slice(blob, off)
	return unsafe.Pointer(&sl[0])
}

// Slice returns a slice to the specified blob at a given offset.
func Slice(blob, off uintptr) []byte {
	if len(blobs) == 0 {
		panic("no blobs defined")
	}
	if atomic.LoadUint32(&runtimeCheck) != 0 {
		checkAddr(blob + off)
	}
	if b := BlobByAddr(blob); b != nil {
		if off >= uintptr(len(b.Data)) {
			panic(fmt.Errorf("out of bounds error on blob: 0x%X, %d (%+d)", blob, off, off-uintptr(len(b.Data))))
		}
		return b.Data[off:]
	}
	panic("no blobs matching the address: 0x" + strconv.FormatUint(uint64(blob), 16))
}

// PtrSize is similar to Ptr, but also specifies the size of the access.
func PtrSize(addr, size uintptr) unsafe.Pointer {
	return Ptr(addr)
}

// PtrSizeOff is similar to PtrOff, but also specifies the size of the access.
func PtrSizeOff(addr, off, size uintptr) unsafe.Pointer {
	return PtrOff(addr, off)
}

func PtrPtr(base, off uintptr) *unsafe.Pointer {
	return (*unsafe.Pointer)(PtrSizeOff(base, off, ptrSize))
}

func PtrUint8(base, off uintptr) *byte {
	return (*byte)(PtrSizeOff(base, off, 1))
}

func PtrInt8(base, off uintptr) *int8 {
	return (*int8)(PtrSizeOff(base, off, 1))
}

func PtrUint16(base, off uintptr) *uint16 {
	return (*uint16)(PtrSizeOff(base, off, 2))
}

func PtrInt16(base, off uintptr) *int16 {
	return (*int16)(PtrSizeOff(base, off, 2))
}

func PtrUint32(base, off uintptr) *uint32 {
	return (*uint32)(PtrSizeOff(base, off, 4))
}

func PtrInt32(base, off uintptr) *int32 {
	return (*int32)(PtrSizeOff(base, off, 4))
}

func PtrUint64(base, off uintptr) *uint64 {
	return (*uint64)(PtrSizeOff(base, off, 8))
}

func PtrInt64(base, off uintptr) *int64 {
	return (*int64)(PtrSizeOff(base, off, 8))
}

func PtrFloat32(base, off uintptr) *float32 {
	return (*float32)(PtrSizeOff(base, off, 4))
}

func PtrFloat64(base, off uintptr) *float64 {
	return (*float64)(PtrSizeOff(base, off, 8))
}

func Uint8(base, off uintptr) byte {
	return *(*byte)(PtrSizeOff(base, off, 1))
}

func Int8(base, off uintptr) int8 {
	return *(*int8)(PtrSizeOff(base, off, 1))
}

func Uint16(base, off uintptr) uint16 {
	return *(*uint16)(PtrSizeOff(base, off, 2))
}

func Int16(base, off uintptr) int16 {
	return *(*int16)(PtrSizeOff(base, off, 2))
}

func Uint32(base, off uintptr) uint32 {
	return *(*uint32)(PtrSizeOff(base, off, 4))
}

func Int32(base, off uintptr) int32 {
	return *(*int32)(PtrSizeOff(base, off, 4))
}

func Uint64(base, off uintptr) uint64 {
	return *(*uint64)(PtrSizeOff(base, off, 8))
}

func Int64(base, off uintptr) int64 {
	return *(*int64)(PtrSizeOff(base, off, 8))
}

func Float32(base, off uintptr) float32 {
	return *(*float32)(PtrSizeOff(base, off, 4))
}

func Float64(base, off uintptr) float64 {
	return *(*float64)(PtrSizeOff(base, off, 8))
}

func String(base, off uintptr) string {
	sl := Slice(base, off)
	i := bytes.IndexByte(sl, 0)
	if i < 0 {
		panic("non zero-terminated string")
	}
	return string(sl[:i])
}
