package nox

/*
#include "memfile.h"
#include "defs.h"
*/
import "C"
import (
	"fmt"
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/log"
)

var (
	thingsLog              = log.New("things")
	nox_images_arr1_787156 []*noxImageRef
)

//export nox_thing_read_IMAG_415700
func nox_thing_read_IMAG_415700(f *C.nox_memfile, buf *C.char) C.int {
	cnt := C.nox_memfile_read_u32(f)
	nox_images_arr1_787156 = make([]*noxImageRef, 0, cnt)
	for i := 0; i < int(cnt); i++ {
		if err := nox_thing_read_IMAG_one_42F660(f, buf); err != nil {
			thingsLog.Printf("cannot read image %d: %v", i, err)
			return 0
		}
	}
	return 1
}

func nox_thing_read_IMAG_one_42F660(f *C.nox_memfile, cbuf *C.char) error {
	pbuf := unsafe.Pointer(cbuf)
	buf := asByteSlice(pbuf, 256*1024)

	refP, _ := alloc.Malloc(unsafe.Sizeof(C.nox_things_imageRef_t{}))
	ref := (*C.nox_things_imageRef_t)(refP)
	nox_images_arr1_787156 = append(nox_images_arr1_787156, asImageRef(ref))

	readString8 := func() string {
		sz := C.nox_memfile_read_u8(f)
		C.nox_memfile_read(pbuf, 1, C.int(sz), f)
		buf[sz] = 0
		return string(buf[:sz])
	}

	name := readString8()
	copy(asByteSlice(unsafe.Pointer(&ref.name[0]), len(ref.name)), name)
	ref.name[len(name)] = 0

	kind := C.nox_memfile_read_i8(f)
	ref.field_25_1 = C.char(kind)

	switch kind {
	case 1:
		ind := C.nox_memfile_read_i32(f)
		if ind == -1 {
			typ := C.nox_memfile_read_u8(f)
			name2 := readString8()
			if nox_xxx_loadImage_47A8C0(byte(typ), name2) != nil {
				copy(asByteSlice(unsafe.Pointer(&ref.name2[0]), len(ref.name2)), name2)
				ref.name2[len(name2)] = 0
				ref.field_25_0 = C.char(typ)
			} else {
				ref.field_25_0 = -1
			}
		}
		ref.field_24 = ind
		return nil
	case 2:
		sz := C.nox_memfile_read_u8(f)
		arr, _ := alloc.Pointers(int(sz))
		pt, _ := alloc.Uints32(4)
		ptb := asByteSlice(unsafe.Pointer(&pt[0]), 16)
		pt[0] = 0
		pt[1] = uint32(uintptr(unsafe.Pointer(&arr[0])))
		ptb[8] = byte(sz)
		ptb[9] = byte(int8(C.nox_memfile_read_i8(f)))

		switch ityp := readString8(); ityp {
		case "Loop":
			ptb[10] = 2
		case "OneShot":
			ptb[10] = 0
		default:
			return fmt.Errorf("unexpected anim type: %q", ityp)
		}
		for i := 0; i < len(arr); i++ {
			if ind := int(C.nox_memfile_read_i32(f)); ind == -1 {
				typ := C.nox_memfile_read_i8(f)
				name2 := readString8()
				arr[i] = unsafe.Pointer(nox_xxx_loadImage_47A8C0(byte(typ), name2).C())
			} else {
				arr[i] = unsafe.Pointer(bagImageByIndex(ind).C())
			}
		}
		ref.field_24 = C.int(uintptr(unsafe.Pointer(&pt[0])))
		return nil
	default:
		return fmt.Errorf("unsupported image kind: %d", int(kind))
	}
}
