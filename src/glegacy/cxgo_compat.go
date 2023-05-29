package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/csys"
	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/gotranspile/cxgo/runtime/stdio"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type _FIND_FILE struct {
	idx     uint32
	globbuf stdio.Glob
}

func fill_find_data(path *byte, lpFindFileData LPWIN32_FIND_DATAA) {
	var (
		st       csys.StatRes
		filename *byte = libc.StrRChr(path, '/')
	)
	if filename == nil {
		filename = path
	} else {
		filename = (*byte)(unsafe.Add(unsafe.Pointer(filename), 1))
	}
	csys.Stat(path, &st)
	*lpFindFileData = WIN32_FIND_DATAA{}
	if csys.IsDir(st.Mode) != 0 {
		lpFindFileData.dwFileAttributes = uint32(FILE_ATTRIBUTE_DIRECTORY)
	} else {
		lpFindFileData.dwFileAttributes = uint32(FILE_ATTRIBUTE_NORMAL)
	}
	lpFindFileData.nFileSizeHigh = uint32(st.Size >> 32)
	lpFindFileData.nFileSizeLow = uint32(st.Size)
	libc.StrCpy(&lpFindFileData.cFileName[0], filename)
}
func compatFindFirstFileA(lpFileName *byte, lpFindFileData LPWIN32_FIND_DATAA) HANDLE {
	var (
		converted *byte       = nox_fs_normalize(lpFileName)
		len_      int32       = int32(libc.StrLen(converted))
		ff        *_FIND_FILE = (*_FIND_FILE)(alloc.Calloc(int(unsafe.Sizeof(_FIND_FILE{})), 1))
	)
	if len_ >= 2 && *(*byte)(unsafe.Add(unsafe.Pointer(converted), len_-2)) == '.' && *(*byte)(unsafe.Add(unsafe.Pointer(converted), len_-1)) == '*' {
		*(*byte)(unsafe.Add(unsafe.Pointer(converted), len_-2)) = 0
	}
	if ff.globbuf.Glob(converted, int32(stdio.GlobNoEscape), nil) != 0 {
		alloc.Free(unsafe.Pointer(converted))
		alloc.Free(unsafe.Pointer(ff))
		return unsafe.Pointer(uintptr(math.MaxUint32))
	}
	alloc.Free(unsafe.Pointer(converted))
	fill_find_data(*(**byte)(unsafe.Add(unsafe.Pointer(ff.globbuf.Paths), unsafe.Sizeof((*byte)(nil))*uintptr(func() uint32 {
		p := &ff.idx
		x := *p
		*p++
		return x
	}()))), lpFindFileData)
	return HANDLE(ff)
}
func compatFindNextFileA(hFindFile HANDLE, lpFindFileData LPWIN32_FIND_DATAA) int32 {
	var ff *_FIND_FILE = (*_FIND_FILE)(hFindFile)
	if ff.idx >= uint32(ff.globbuf.Num) {
		return 0
	}
	fill_find_data(*(**byte)(unsafe.Add(unsafe.Pointer(ff.globbuf.Paths), unsafe.Sizeof((*byte)(nil))*uintptr(func() uint32 {
		p := &ff.idx
		x := *p
		*p++
		return x
	}()))), lpFindFileData)
	return 1
}
func compatFindClose(hFindFile HANDLE) int32 {
	var ff *_FIND_FILE = (*_FIND_FILE)(hFindFile)
	ff.globbuf.Free()
	alloc.Free(ff)
	return 1
}
