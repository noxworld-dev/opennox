package blobdata

import (
	_ "embed"

	"nox/v1/common/memmap"
)

//go:embed blob_581450.dat
var data581450 []byte

//go:embed blob_587000.dat
var data587000 []byte

func initData() {
	if n := copy(memmap.BlobByAddr(0x581450).Data, data581450); n != len(data581450) {
		panic("cannot init blob")
	}
	if n := copy(memmap.BlobByAddr(0x587000).Data, data587000); n != len(data587000) {
		panic("cannot init blob")
	}
}
