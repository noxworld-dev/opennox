package opennox

/*
#include "defs.h"
*/
import "C"

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

type nox_video_bag_image_t = C.nox_video_bag_image_t

func asImage(p *nox_video_bag_image_t) *noxrender.Image {
	return noxClient.r.Bag.AsImage(noxrender.ImageHandle(unsafe.Pointer(p)))
}

//export nox_video_bag_image_type
func nox_video_bag_image_type(img *nox_video_bag_image_t) C.int {
	return C.int(asImage(img).Type())
}

//export nox_xxx_readImgMB_42FAA0
func nox_xxx_readImgMB_42FAA0(known_idx C.int, typ C.char, cname2 *C.char) *nox_video_bag_image_t {
	return (*nox_video_bag_image_t)(noxClient.r.Bag.ImageRef(int(known_idx), byte(typ), GoString(cname2)).C())
}

//export nox_xxx_gLoadImg_42F970
func nox_xxx_gLoadImg_42F970(name *C.char) *nox_video_bag_image_t {
	return (*nox_video_bag_image_t)(nox_xxx_gLoadImg(GoString(name)).C())
}

//export nox_xxx_gLoadAnim_42FA20
func nox_xxx_gLoadAnim_42FA20(name *C.char) *C.nox_things_imageRef_t {
	return nox_xxx_gLoadAnim(GoString(name)).C()
}

func nox_xxx_gLoadImg(name string) *noxrender.Image {
	if name == "" {
		return nil
	}
	for _, p := range nox_images_arr1_787156 {
		if name == p.Name() {
			ind := p.field24int()
			if ind == -1 {
				if p.field_25_0 == -1 {
					return nil
				}
				name2 := p.Name2()
				return noxClient.r.Bag.LoadExternalImage(byte(p.field_25_0), name2)
			}
			return noxClient.r.Bag.ImageByIndex(ind)
		}
	}
	return nil
}

func asImageRefP(p unsafe.Pointer) *noxImageRef {
	return (*noxImageRef)(p)
}

func asImageRef(p *C.nox_things_imageRef_t) *noxImageRef {
	return asImageRefP(unsafe.Pointer(p))
}

type noxImageRef C.nox_things_imageRef_t

func (r *noxImageRef) C() *C.nox_things_imageRef_t {
	return (*C.nox_things_imageRef_t)(unsafe.Pointer(r))
}

func (r *noxImageRef) Name() string {
	return GoString(&r.name[0])
}

func (r *noxImageRef) Name2() string {
	return GoString(&r.name2[0])
}

func (r *noxImageRef) kind() int {
	return int(r.ref_kind)
}

func (r *noxImageRef) field24int() int {
	if r.kind() == 2 {
		panic("not an regular image")
	}
	return int(uintptr(r.field_24))
}

func (r *noxImageRef) field24ptr() *noxImageRefAnim {
	if r.kind() != 2 {
		panic("not an animation")
	}
	return (*noxImageRefAnim)(r.field_24)
}

type noxImageRefAnim C.nox_things_imageRef2_t

func (r *noxImageRefAnim) C() *C.nox_things_imageRef2_t {
	return (*C.nox_things_imageRef2_t)(unsafe.Pointer(r))
}

func (r *noxImageRefAnim) Images() []*nox_video_bag_image_t {
	return unsafe.Slice(r.images, r.images_sz)
}

func nox_xxx_gLoadAnim(name string) *noxImageRef {
	if name == "" {
		return nil
	}
	for _, p := range nox_images_arr1_787156 {
		if name == p.Name() {
			return p
		}
	}
	return nil
}

func nox_video_bagFree_42F4D0() {
	for _, p := range nox_images_arr1_787156 {
		if p.kind() == 2 {
			anim := p.field24ptr()
			alloc.Free(unsafe.Pointer(anim.images))
			alloc.Free(unsafe.Pointer(anim.C()))
		}
		alloc.Free(unsafe.Pointer(p.C()))
	}
	nox_images_arr1_787156 = nil
	sub_47D150()
	noxClient.r.Bag.Free()
}

func sub_47D150() {
	if p := memmap.PtrPtr(0x5D4594, 1189588); *p != nil {
		alloc.Free(*p)
		*p = nil
	}
}
