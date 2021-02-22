package main

/*
#include <stdio.h>

char* dos_to_unix(const char* path);
int fscanf_go0(FILE* f, const char* fmt);
int fscanf_go1(FILE* f, const char* fmt, void* a1);
*/
import "C"
import (
	"fmt"
	"io"
	"nox/common/alloc"
	"unsafe"
)

func newCFile(f *C.FILE) io.ByteReader {
	return cfileReader{f: f}
}

type cfileReader struct {
	f *C.FILE
}

func (f cfileReader) ReadByte() (byte, error) {
	c := C.fgetc(f.f)
	if c < 0 {
		// it's not always true, but that's what original code does
		return 0, io.EOF
	}
	return byte(c), nil
}

func fopen(path, mode string) *C.FILE {
	cpath := C.CString(path)
	cmode := C.CString(mode)
	defer func() {
		StrFree(cpath)
		StrFree(cmode)
	}()
	apath := cpath
	if p := C.dos_to_unix(cpath); p != cpath {
		defer StrFree(p)
		apath = p
	}
	return C.fopen(apath, cmode)
}

func fscanf(f *C.FILE, format string, args ...interface{}) int {
	cfmt := C.CString(format)
	defer StrFree(cfmt)
	var cargs []unsafe.Pointer
	for _, v := range args {
		switch v := v.(type) {
		case unsafe.Pointer:
			cargs = append(cargs, v)
		case *string:
			cstr := (*C.char)(alloc.Calloc(1024, 1))
			defer func() {
				*v = C.GoString(cstr)
				alloc.Free(unsafe.Pointer(cstr))
			}()
			cargs = append(cargs, unsafe.Pointer(cstr))
		default:
			panic(fmt.Errorf("unsupported type: %T", v))
		}
	}
	switch len(cargs) {
	case 0:
		return int(C.fscanf_go0(f, cfmt))
	case 1:
		return int(C.fscanf_go1(f, cfmt, cargs[0]))
	default:
		panic(fmt.Errorf("unsupported args count: %d", len(cargs)))
	}
}
