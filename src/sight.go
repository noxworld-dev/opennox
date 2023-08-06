package opennox

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

func sub_4989A0() {
	sz := legacy.Get_dword_5d4594_1217464()
	if sz < 3 {
		return
	}
	const capacity = 1024 // TODO: size is a guess
	arr := unsafe.Slice((*image.Point)(memmap.PtrOff(0x5D4594, 1203876)), capacity)
	arr = arr[:sz] // TODO: check if the loop below can get out of bounds

	barr := unsafe.Slice((*byte)(memmap.PtrOff(0x5D4594, 1212324)), capacity)
	iarr := unsafe.Slice((*uint32)(memmap.PtrOff(0x5D4594, 1213348)), capacity)

	p0 := arr[0] // 1203876, 1203880
	p1 := arr[1] // 1203884, 1203888

	// arr[2] // 1203892, 1203896

	j := 1
	for i := 2; i < sz; i++ {
		p := arr[i]
		bv := barr[i]
		if ((p0.X-p1.X)*(p.Y-p1.Y) != (p0.Y-p1.Y)*(p.X-p1.X)) || bv != barr[j] {
			j++
			p0 = p1
		}
		arr[j] = p
		barr[j] = bv
		iarr[j] = iarr[i]
		p1 = p
	}
	legacy.Set_dword_5d4594_1217464(j + 1)
}
