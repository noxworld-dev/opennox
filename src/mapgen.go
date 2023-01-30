package opennox

import (
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_xxx_mapGenMakeInfo_4D5DB0(p unsafe.Pointer) {
	alloc.StrCopy(unsafe.Slice((*byte)(unsafe.Add(p, 0)), 64), "Generated Map")
	alloc.StrCopy(unsafe.Slice((*byte)(unsafe.Add(p, 64)), 64), "Generated Map") // TODO: size is a guess
	*(*uint16)(unsafe.Add(p, 576)) = memmap.Uint16(0x587000, 198380)
	*(*uint32)(unsafe.Add(p, 592)) = memmap.Uint32(0x587000, 198384)
	alloc.StrCopy(unsafe.Slice((*byte)(unsafe.Add(p, 656)), 64), "http://www.westwood.com")
	alloc.StrCopy(unsafe.Slice((*byte)(unsafe.Add(p, 720)), 128), "http://www.westwood.com")
	alloc.StrCopy(unsafe.Slice((*byte)(unsafe.Add(p, 848)), 128), "http://www.westwood.com")
	alloc.StrCopy(unsafe.Slice((*byte)(unsafe.Add(p, 976)), 256), "Generated Map")
	alloc.StrCopy(unsafe.Slice((*byte)(unsafe.Add(p, 1232)), 128), "Westwood Studios")
	date := time.Now().Format("Mon, Jan 2 2006")
	alloc.StrCopy(unsafe.Slice((*byte)(unsafe.Add(p, 1360)), 32), date)
	*(*uint32)(unsafe.Add(p, 1392)) = 3
}
