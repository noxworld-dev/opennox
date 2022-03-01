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
func nox_thing_read_IMAG_415700(fp *C.nox_memfile, cbuf *C.char) C.int {
	f := asMemfile(fp)
	pbuf := unsafe.Pointer(cbuf)
	buf := unsafe.Slice((*byte)(pbuf), 256*1024)

	cnt := int(f.ReadU32())
	nox_images_arr1_787156 = make([]*noxImageRef, 0, cnt)
	for i := 0; i < cnt; i++ {
		if err := nox_thing_read_IMAG_one_42F660(f, buf); err != nil {
			thingsLog.Printf("cannot read image %d: %v", i, err)
			return 0
		}
	}
	return 1
}

func nox_thing_read_IMAG_one_42F660(f *MemFile, buf []byte) error {
	refP, _ := alloc.Malloc(unsafe.Sizeof(C.nox_things_imageRef_t{}))
	ref := asImageRef((*C.nox_things_imageRef_t)(refP))
	nox_images_arr1_787156 = append(nox_images_arr1_787156, ref)

	readString8 := func() string {
		sz := f.ReadU8()
		_, _ = f.Read(buf[:sz])
		buf[sz] = 0
		return string(buf[:sz])
	}

	name := readString8()
	copy(unsafe.Slice((*byte)(unsafe.Pointer(&ref.name[0])), len(ref.name)), name)
	ref.name[len(name)] = 0

	kind := f.ReadI8()
	ref.ref_kind = C.char(kind)

	switch kind {
	case 1:
		ind := f.ReadI32()
		if ind == -1 {
			typ := f.ReadU8()
			name2 := readString8()
			if nox_xxx_loadImage_47A8C0(typ, name2) != nil {
				copy(unsafe.Slice((*byte)(unsafe.Pointer(&ref.name2[0])), len(ref.name2)), name2)
				ref.name2[len(name2)] = 0
				ref.field_25_0 = C.char(typ)
			} else {
				ref.field_25_0 = -1
			}
		}
		ref.field_24 = unsafe.Pointer(uintptr(ind))
		return nil
	case 2:
		sz := f.ReadU8()
		arr, _ := alloc.Pointers(int(sz))
		ptr, _ := alloc.Malloc(unsafe.Sizeof(noxImageRefAnim{}))
		anim := (*noxImageRefAnim)(ptr)
		anim.on_end = nil
		anim.images = (**C.nox_video_bag_image_t)(unsafe.Pointer(&arr[0]))
		anim.images_sz = C.uchar(sz)
		anim.field_2_1 = C.uchar(f.ReadU8())

		switch ityp := readString8(); ityp {
		case "Loop":
			anim.anim_type = 2
		case "OneShot":
			anim.anim_type = 0
		default:
			return fmt.Errorf("unexpected anim type: %q", ityp)
		}
		for i := 0; i < len(arr); i++ {
			if ind := int(f.ReadI32()); ind == -1 {
				typ := f.ReadI8()
				name2 := readString8()
				arr[i] = unsafe.Pointer(nox_xxx_loadImage_47A8C0(byte(typ), name2).C())
			} else {
				arr[i] = unsafe.Pointer(bagImageByIndex(ind).C())
			}
		}
		ref.field_24 = ptr
		return nil
	default:
		return fmt.Errorf("unsupported image kind: %d", int(kind))
	}
}
