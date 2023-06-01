package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
)

var _ = [1]struct{}{}[16-unsafe.Sizeof(binfile.MemFile{})]

type nox_memfile = binfile.MemFile

func asMemfile(p *nox_memfile) *binfile.MemFile {
	return asMemfileP(unsafe.Pointer(p))
}

func asMemfileP(p unsafe.Pointer) *binfile.MemFile {
	return (*binfile.MemFile)(p)
}
