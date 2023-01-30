package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_xxx_gLoadImg(name string) *noxrender.Image {
	if name == "" {
		return nil
	}
	for _, p := range nox_images_arr1_787156 {
		if name == p.Name() {
			ind := p.Field24int()
			if ind == -1 {
				if p.Field_25_0 == -1 {
					return nil
				}
				name2 := p.Name2()
				return noxClient.r.Bag.LoadExternalImage(byte(p.Field_25_0), name2)
			}
			return noxClient.r.Bag.ImageByIndex(ind)
		}
	}
	return nil
}

func nox_xxx_gLoadAnim(name string) *legacy.ImageRef {
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
		if p.Kind() == 2 {
			anim := p.Field24ptr()
			alloc.Free(unsafe.Pointer(anim.ImagesPtr))
			alloc.Free(anim.C())
		}
		alloc.Free(p.C())
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
