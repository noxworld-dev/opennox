package opennox

/*
#ifdef _WIN32
#include <windows.h>
#else
#include "windows_compat.h"
#endif
*/
import "C"
import (
	"strconv"
	"time"
	"unsafe"
)

//export nox_itoa
func nox_itoa(val C.int, s *C.char, radix C.int) *C.char {
	str := strconv.FormatInt(int64(val), int(radix))
	buf := unsafe.Slice((*byte)(unsafe.Pointer(s)), len(str)+1)
	i := copy(buf, str)
	buf[i] = 0
	return s
}

func asTime(ts *C.SYSTEMTIME) time.Time {
	if ts == nil {
		return time.Time{}
	}
	return time.Date(
		int(ts.wYear), time.Month(ts.wMonth), int(ts.wDay),
		int(ts.wHour), int(ts.wMinute), int(ts.wSecond),
		int(ts.wMilliseconds)*int(time.Millisecond),
		time.Local,
	)
}
