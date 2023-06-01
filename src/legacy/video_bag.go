package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var (
	Nox_xxx_gLoadImg  func(name string) *noxrender.Image
	Nox_xxx_gLoadAnim func(name string) *ImageRef
)

type nox_video_bag_image_t = [0]byte

func asImageH(p *nox_video_bag_image_t) noxrender.ImageHandle {
	return noxrender.ImageHandle(unsafe.Pointer(p))
}

func asImage(p *nox_video_bag_image_t) *noxrender.Image {
	return GetClient().R2().GetBag().AsImage(asImageH(p))
}

type ImageRefAnim struct {
	OnEnd     unsafe.Pointer         // 0, 0, func(noxrender.ImageHandle)
	ImagesPtr *noxrender.ImageHandle // 1, 4
	ImagesSz  uint8                  // 2, 8
	Field_2_1 uint8                  // 2, 9
	AnimType  uint8                  // 2, 10
	Field_2_3 uint8                  // 2, 11
	Field_3   uint32                 // 3, 12
}

func (r *ImageRefAnim) C() unsafe.Pointer {
	return unsafe.Pointer(r)
}

func (r *ImageRefAnim) Images() []noxrender.ImageHandle {
	return unsafe.Slice(r.ImagesPtr, r.ImagesSz)
}

func AsImageRefP(p unsafe.Pointer) *ImageRef {
	return (*ImageRef)(p)
}

type ImageRef struct {
	NameBuf    [32]byte       // 0, 0
	Name2Buf   [64]byte       // 8, 32
	Field_24   unsafe.Pointer // 24, 96; void* when field_25_1 == 2, int when field_25_1 == 1
	Field_25_0 int8           // 25, 100
	RefKind    int8           // 25, 101
	Field_25_2 int16          // 25, 102
}

func (r *ImageRef) C() unsafe.Pointer {
	return unsafe.Pointer(r)
}

func (r *ImageRef) Name() string {
	return alloc.GoString(&r.NameBuf[0])
}

func (r *ImageRef) SetName(s string) {
	alloc.StrCopyZero(r.NameBuf[:], s)
}

func (r *ImageRef) Name2() string {
	return alloc.GoString(&r.Name2Buf[0])
}

func (r *ImageRef) SetName2(s string) {
	alloc.StrCopyZero(r.Name2Buf[:], s)
}

func (r *ImageRef) Kind() int {
	return int(r.RefKind)
}

func (r *ImageRef) Field24int() int {
	if r.Kind() == 2 {
		panic("not an regular image")
	}
	return int(uintptr(r.Field_24))
}

func (r *ImageRef) Field24ptr() *ImageRefAnim {
	if r.Kind() != 2 {
		panic("not an animation")
	}
	return (*ImageRefAnim)(r.Field_24)
}

// nox_video_bag_image_type
func nox_video_bag_image_type(img *nox_video_bag_image_t) int32 {
	return int32(asImage(img).Type())
}

// nox_xxx_readImgMB_42FAA0
func nox_xxx_readImgMB_42FAA0(known_idx int32, typ int8, cname2 *byte) *nox_video_bag_image_t {
	return (*nox_video_bag_image_t)(GetClient().R2().GetBag().ImageRef(int(known_idx), byte(typ), GoString(cname2)).C())
}

// nox_xxx_gLoadImg_42F970
func nox_xxx_gLoadImg_42F970(name *byte) *nox_video_bag_image_t {
	return (*nox_video_bag_image_t)(Nox_xxx_gLoadImg(GoString(name)).C())
}

// nox_xxx_gLoadAnim_42FA20
func nox_xxx_gLoadAnim_42FA20(name *byte) *ImageRef {
	return (*ImageRef)(Nox_xxx_gLoadAnim(GoString(name)).C())
}
